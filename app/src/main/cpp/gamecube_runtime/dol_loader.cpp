#include "gamecube_runtime/dol_loader.h"

#include <cstdio>

#include "log.h"

namespace sfa {

namespace {
uint32_t ReadBe32(const uint8_t* p) {
  return (static_cast<uint32_t>(p[0]) << 24) |
         (static_cast<uint32_t>(p[1]) << 16) |
         (static_cast<uint32_t>(p[2]) << 8) | p[3];
}
}  // namespace

DolLoadResult LoadDolFromBuffer(const uint8_t* dol, uint32_t dol_size,
                                GCMemory* memory) {
  DolLoadResult result;
  if (dol == nullptr || memory == nullptr) {
    result.error = "dol o memoria nulos";
    return result;
  }
  if (dol_size < 0x100) {
    result.error = "fichero DOL menor que la cabecera (0x100)";
    return result;
  }
  uint32_t text_off[7];
  uint32_t data_off[11];
  uint32_t text_addr[7];
  uint32_t data_addr[11];
  uint32_t text_size[7];
  uint32_t data_size[11];
  for (int i = 0; i < 7; ++i) text_off[i] = ReadBe32(dol + 0x00 + 4 * i);
  for (int i = 0; i < 11; ++i) data_off[i] = ReadBe32(dol + 0x1C + 4 * i);
  for (int i = 0; i < 7; ++i) text_addr[i] = ReadBe32(dol + 0x48 + 4 * i);
  for (int i = 0; i < 11; ++i) data_addr[i] = ReadBe32(dol + 0x64 + 4 * i);
  for (int i = 0; i < 7; ++i) text_size[i] = ReadBe32(dol + 0x90 + 4 * i);
  for (int i = 0; i < 11; ++i) data_size[i] = ReadBe32(dol + 0xAC + 4 * i);
  const uint32_t bss_addr = ReadBe32(dol + 0xD8);
  const uint32_t bss_size = ReadBe32(dol + 0xDC);
  const uint32_t entry = ReadBe32(dol + 0xE0);

  // Validación completa antes de escribir nada en RAM.
  for (int i = 0; i < 7; ++i) {
    if (text_size[i] == 0) continue;
    if (text_off[i] + text_size[i] > dol_size) {
      result.error = "seccion text fuera del fichero";
      return result;
    }
    if (!memory->IsValid(text_addr[i]) ||
        text_addr[i] + text_size[i] > GCMemory::kRamBase + GCMemory::kRamSize) {
      result.error = "seccion text fuera de RAM guest";
      return result;
    }
  }
  for (int i = 0; i < 11; ++i) {
    if (data_size[i] == 0) continue;
    if (data_off[i] + data_size[i] > dol_size) {
      result.error = "seccion data fuera del fichero";
      return result;
    }
    if (!memory->IsValid(data_addr[i]) ||
        data_addr[i] + data_size[i] > GCMemory::kRamBase + GCMemory::kRamSize) {
      result.error = "seccion data fuera de RAM guest";
      return result;
    }
  }
  if (bss_addr != 0) {
    if (!memory->IsValid(bss_addr) ||
        bss_addr + bss_size > GCMemory::kRamBase + GCMemory::kRamSize) {
      result.error = "BSS fuera de RAM guest";
      return result;
    }
  }

  // ORDEN (Fase 5, desbloqueo salMalloc): primero se pone a cero
  // el BSS y DESPUES se copian text/data. El BSS de la cabecera
  // (0x803371A0, 732344 B -> hasta 0x803E3E58) SOLAPA las
  // secciones data #6 (0x803DCB40) y #7 (0x803DFEC0): si se
  // pone a cero despues de copiar, se destruyen ~46 KB de datos
  // inicializados, entre ellos los punteros malloc/free de
  // .sdata2 en 0x803DFF08/0x803DFF0C (en el fichero: 0x8000A1D8
  // / 0x8000A1B8). El resultado era: audioInit -> sndSetHooks
  // copiaba ceros a los globales, salMalloc saltaba por el
  // puntero 0 y la ejecucion caia a PC 0. El BSS verdadero
  // segun la tabla de __init_data del propio juego excluye
  // esas secciones ([0x803371A0,+678304), [0x803DE160,+7492),
  // [0x803E9E20,+56)); con este orden, el estado final coincide
  // con el que deja __init_data (copias src==dst + ceros solo
  // en el BSS verdadero). Para DOLs sin solape el orden es
  // indiferente.
  if (!memory->ZeroBss()) {
    // BSS de este DOL coincide con la constante de GCMemory; si no
    // coincidiera, el cargador debería usar bss_addr/bss_size del
    // fichero. Se registra y se falla de forma explícita.
    SFA_LOGE("dol: BSS del fichero (0x%08X, %u) no coincide con "
             "GCMemory::kBss (0x%08X, %u)",
             bss_addr, bss_size, GCMemory::kBssBase, GCMemory::kBssSize);
    result.error = "BSS del fichero distinto de GCMemory::kBss";
    return result;
  }

  for (int i = 0; i < 7; ++i) {
    if (text_size[i] == 0) continue;
    if (!memory->WriteBytes(text_addr[i], dol + text_off[i],
                            text_size[i])) {
      result.error = "fallo al copiar seccion text";
      return result;
    }
    result.text_sections++;
    result.text_bytes += text_size[i];
  }
  for (int i = 0; i < 11; ++i) {
    if (data_size[i] == 0) continue;
    if (!memory->WriteBytes(data_addr[i], dol + data_off[i],
                            data_size[i])) {
      result.error = "fallo al copiar seccion data";
      return result;
    }
    result.data_sections++;
    result.data_bytes += data_size[i];
  }

  result.ok = true;
  result.entry = entry;
  SFA_LOGI("dol: cargado, entry 0x%08X, text %u secciones %u B, "
           "data %u secciones %u B, BSS 0x%08X %u B",
           entry, result.text_sections, result.text_bytes,
           result.data_sections, result.data_bytes, bss_addr, bss_size);
  return result;
}

DolLoadResult LoadDolFromFile(const char* path, GCMemory* memory) {
  DolLoadResult result;
  if (path == nullptr) {
    result.error = "ruta nula";
    return result;
  }
  FILE* f = fopen(path, "rb");
  if (f == nullptr) {
    result.error = "no se pudo abrir el fichero DOL";
    return result;
  }
  fseek(f, 0, SEEK_END);
  const long size = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (size <= 0 || size > 64L * 1024L * 1024L) {
    fclose(f);
    result.error = "tamano DOL invalido";
    return result;
  }
  uint8_t* buffer = new uint8_t[static_cast<size_t>(size)];
  const size_t read = fread(buffer, 1, static_cast<size_t>(size), f);
  fclose(f);
  if (read != static_cast<size_t>(size)) {
    delete[] buffer;
    result.error = "lectura incompleta del DOL";
    return result;
  }
  result = LoadDolFromBuffer(buffer, static_cast<uint32_t>(size), memory);
  delete[] buffer;
  return result;
}

}  // namespace sfa
