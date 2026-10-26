#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

// Captura FIFO de mundo, Tramo 9 frente B. Parte PURA (sin
// runtime, sin GL): el escritor y el validador operan sobre
// buffers que el llamador (runtime.cpp, parche Tramo 9) les
// entrega. La procedencia es por CONSTRUCCION, no por patron
// de bytes: el runtime escribe el segmento FIFO tal cual lo
// acumulo el buffer de captura en vivo (sfa_fifo_capture_data)
// y la RAM tal cual esta en memory_.RamData() EN EL MISMO
// punto temporal (antes del reset de captura y antes del
// siguiente slice). Ningun byte de estos ficheros se genera
// aqui: este modulo solo los vuelca, los describe en un
// manifiesto y los verifica despues.
//
// Formato de una captura (directorio frame_<N>/):
//   frame_<N>_fifo.bin : segmento FIFO del frame (bytes vivos).
//   frame_<N>_ram.bin  : RAM huesped completa (24 MiB) en el
//                        mismo punto temporal que el fin del
//                        segmento FIFO.
//   frame_<N>.json     : manifiesto (ver WriteFrameManifest):
//                        indice, escena (puesta por el
//                        jugador, nunca inferida), tamanos,
//                        overflow de captura, huellas FNV-1a
//                        de ambos ficheros, contador de
//                        texloads y base FIFO global.
//   frame_<N>_texloads.csv : cargas de textura del frame con
//                        su fifo_offset GLOBAL (el runtime
//                        ya las convierte en FeedGxFrame()).
// Criterios de rechazo del validador (todos estructurales;
// los criterios TEV —draw que muestree textura, ordenes
// 0x28+/0xC0+/0xF6+ antes del draw, DL resolubles— los aplica
// el censo sobre la captura aceptada, ver CAPTURA_MUNDO_T9.md):
//   R1 manifiesto ausente o incompleto / escena vacia.
//   R2 tamano fifo o ram distinto del manifiesto.
//   R3 huella FNV distinta (fichero modificado tras capturar).
//   R4 overflow de captura > 0 (bytes perdidos).
//   R5 ram_size != 24 MiB (0x1800000).
//   R6 fifo vacio.
// Un frame simulado NO pasa R1-R6 por si solo (cualquiera
// puede escribir un manifiesto coherente): lo que distingue
// una captura viva de una simulada es el procedimiento
// (runtime + gancho en FeedGxFrame, ver DIFF.md) mas la
// verificacion TEV posterior (censo: draws reales con
// texmap/coord 0-7 y DL resueltos con SU ram.bin). El
// validador de aqui es el primer filtro, no la prueba final.

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

namespace sfa {

inline constexpr uint32_t kFrameCaptureRamSize = 24u * 1024u * 1024u;

// FNV-1a 64: huella de integridad (NO criptografica; basta
// para detectar un fichero modificado o truncado tras la
// captura, que es lo que R2/R3 necesitan).
inline uint64_t FrameCaptureFnv(const uint8_t* data, size_t len) {
  uint64_t h = 14695981039346656037ull;
  for (size_t i = 0; i < len; ++i) {
    h ^= data[i];
    h *= 1099511628211ull;
  }
  return h;
}

struct FrameTexLoad {
  uint64_t fifo_offset = 0;  // Global (base + relativo).
  uint32_t tex_obj = 0;
  int map = 0;
};

struct FrameCaptureMeta {
  int index = 0;
  std::string scene;  // Etiqueta del jugador; vacia = invalida.
  uint64_t fifo_len = 0;
  uint64_t fifo_hash = 0;
  uint64_t ram_len = 0;
  uint64_t ram_hash = 0;
  uint64_t fifo_base = 0;  // Offset global del segmento.
  unsigned long long overflow = 0;  // >0 = captura invalida.
  size_t texload_count = 0;
};

namespace frame_capture_detail {

inline bool WriteAll(const std::string& path, const uint8_t* data,
                     size_t len) {
  FILE* f = std::fopen(path.c_str(), "wb");
  if (f == nullptr) return false;
  bool ok = true;
  if (len > 0 && std::fwrite(data, 1, len, f) != len) ok = false;
  if (std::fclose(f) != 0) ok = false;
  return ok;
}

inline bool ReadAll(const std::string& path, std::vector<uint8_t>* out) {
  FILE* f = std::fopen(path.c_str(), "rb");
  if (f == nullptr) return false;
  std::fseek(f, 0, SEEK_END);
  long n = std::ftell(f);
  std::fseek(f, 0, SEEK_SET);
  if (n < 0) {
    std::fclose(f);
    return false;
  }
  out->assign(static_cast<size_t>(n), 0);
  bool ok = true;
  if (n > 0 && std::fread(out->data(), 1, n, f) != static_cast<size_t>(n))
    ok = false;
  std::fclose(f);
  return ok;
}

// Extrae un campo "clave":valor hasta coma o } (json minimo,
// sin parser general: el manifiesto lo escribe este mismo
// modulo con formato fijo).
inline bool JsonField(const std::string& json, const char* key,
                      std::string* val) {
  std::string pat = std::string("\"") + key + "\":";
  size_t p = json.find(pat);
  if (p == std::string::npos) return false;
  p += pat.size();
  if (p >= json.size()) return false;
  if (json[p] == '"') {
    size_t e = json.find('"', p + 1);
    if (e == std::string::npos) return false;
    *val = json.substr(p + 1, e - p - 1);
    return true;
  }
  size_t e = json.find_first_of(",}", p);
  if (e == std::string::npos) return false;
  *val = json.substr(p, e - p);
  return true;
}

}  // namespace frame_capture_detail

// Escribe los 4 ficheros de una captura en `dir` (debe existir).
// `scene` vacia -> false sin escribir nada (R1 se aplica antes
// de tocar el disco). Devuelve false si alguna escritura falla.
inline bool WriteFrameCapture(
    const std::string& dir, const FrameCaptureMeta& meta_in,
    const uint8_t* fifo, size_t fifo_len, const uint8_t* ram,
    size_t ram_len, const std::vector<FrameTexLoad>& texloads) {
  if (meta_in.scene.empty()) return false;
  if (fifo == nullptr || ram == nullptr) return false;
  std::string base = dir + "/frame_" + std::to_string(meta_in.index);
  FrameCaptureMeta m = meta_in;
  m.fifo_len = fifo_len;
  m.ram_len = ram_len;
  m.fifo_hash = FrameCaptureFnv(fifo, fifo_len);
  m.ram_hash = FrameCaptureFnv(ram, ram_len);
  m.texload_count = texloads.size();
  if (!frame_capture_detail::WriteAll(base + "_fifo.bin", fifo, fifo_len))
    return false;
  if (!frame_capture_detail::WriteAll(base + "_ram.bin", ram, ram_len))
    return false;
  std::string csv = "fifo_offset,tex_obj,map\n";
  for (const FrameTexLoad& t : texloads) {
    csv += std::to_string(t.fifo_offset) + "," +
           std::to_string(t.tex_obj) + "," + std::to_string(t.map) +
           "\n";
  }
  if (!frame_capture_detail::WriteAll(
          base + "_texloads.csv",
          reinterpret_cast<const uint8_t*>(csv.data()), csv.size()))
    return false;
  char buf[1024];
  std::snprintf(buf, sizeof buf,
                "{\"index\":%d,\"scene\":\"%s\",\"fifo_len\":%llu,"
                "\"fifo_hash\":\"%016llX\",\"ram_len\":%llu,"
                "\"ram_hash\":\"%016llX\",\"fifo_base\":%llu,"
                "\"overflow\":%llu,\"texload_count\":%zu}\n",
                m.index, m.scene.c_str(),
                static_cast<unsigned long long>(m.fifo_len),
                static_cast<unsigned long long>(m.fifo_hash),
                static_cast<unsigned long long>(m.ram_len),
                static_cast<unsigned long long>(m.ram_hash),
                static_cast<unsigned long long>(m.fifo_base),
                m.overflow, m.texload_count);
  return frame_capture_detail::WriteAll(
      base + ".json", reinterpret_cast<const uint8_t*>(buf),
      std::strlen(buf));
}

// Valida una captura escrita por WriteFrameCapture. `reason`
// recibe el codigo R1..R6 (o "ok"). No parsea el FIFO: el
// parseo y los criterios TEV son trabajo del censo (ver
// encabezado). Devuelve true solo si R1-R6 pasan todos.
inline bool ValidateFrameCapture(const std::string& dir, int index,
                                 std::string* reason) {
  std::string base = dir + "/frame_" + std::to_string(index);
  auto fail = [&](const char* r) {
    if (reason != nullptr) *reason = r;
    return false;
  };
  std::vector<uint8_t> json_bytes;
  if (!frame_capture_detail::ReadAll(base + ".json", &json_bytes))
    return fail("R1-manifiesto-ausente");
  std::string json(json_bytes.begin(), json_bytes.end());
  std::string v;
  FrameCaptureMeta m;
  m.index = index;
  if (!frame_capture_detail::JsonField(json, "scene", &v) || v.empty())
    return fail("R1-escena-vacia");
  m.scene = v;
  if (!frame_capture_detail::JsonField(json, "fifo_len", &v))
    return fail("R1-manifiesto-incompleto");
  m.fifo_len = std::stoull(v);
  if (!frame_capture_detail::JsonField(json, "ram_len", &v))
    return fail("R1-manifiesto-incompleto");
  m.ram_len = std::stoull(v);
  if (!frame_capture_detail::JsonField(json, "overflow", &v))
    return fail("R1-manifiesto-incompleto");
  m.overflow = std::stoull(v);
  std::string hstr;
  if (!frame_capture_detail::JsonField(json, "fifo_hash", &hstr))
    return fail("R1-manifiesto-incompleto");
  if (!frame_capture_detail::JsonField(json, "ram_hash", &v))
    return fail("R1-manifiesto-incompleto");
  m.fifo_hash = std::stoull(hstr, nullptr, 16);
  m.ram_hash = std::stoull(v, nullptr, 16);
  if (m.overflow > 0) return fail("R4-overflow");
  if (m.ram_len != kFrameCaptureRamSize) return fail("R5-ram-no-24MiB");
  if (m.fifo_len == 0) return fail("R6-fifo-vacio");
  std::vector<uint8_t> fifo, ram;
  if (!frame_capture_detail::ReadAll(base + "_fifo.bin", &fifo))
    return fail("R2-fifo-ausente");
  if (!frame_capture_detail::ReadAll(base + "_ram.bin", &ram))
    return fail("R2-ram-ausente");
  if (fifo.size() != m.fifo_len) return fail("R2-fifo-tamano");
  if (ram.size() != m.ram_len) return fail("R2-ram-tamano");
  if (FrameCaptureFnv(fifo.data(), fifo.size()) != m.fifo_hash)
    return fail("R3-fifo-modificado");
  if (FrameCaptureFnv(ram.data(), ram.size()) != m.ram_hash)
    return fail("R3-ram-modificada");
  if (reason != nullptr) *reason = "ok";
  return true;
}

}  // namespace sfa
