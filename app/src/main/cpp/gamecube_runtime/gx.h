#pragma once

// Maquina de estado GX en host (Fase 5b, sin dependencias Android).
//
// Interpreta el stream FIFO GX (capturado de 0xCC008000, ver cpu.h)
// y el estado CP/XF/BP que lleva, mas las display lists leidas de
// RAM huesped. Solo lectura: no toca el estado del juego.
//
// Layouts verificados contra el propio stream (run19) y contra
// YAGCD (registros CP/XF/BP):
// - Comandos: 0x00 NOP (1 B), 0x08 CP (1+1+4), 0x10 XF (1+4+4n),
//   0x20/0x28/0x30/0x38 INDX (XF indexado, YAGCD 5.11.5.9:
//   1+2 indice +2 (longitud-1:4 bits, direccion:12 bits) +4n
//   datos; se parsea y cuenta, pero NO muta el mapa XF: su
//   direccionamiento indexado exacto no esta modelado y ningun
//   draw observado hasta ahora depende de el),
//   0x40 DL (1+4+4), 0x48 invalidar cache (1 B), 0x61 BP (1+4),
//   0x80-0xBF draw (1+2+vertices).
// - Desviaciones MEDIDAS del stream de la pelicula/titulo
//   (run42/46), NO reglas GX generales: el calculo aritmetico
//   VCD/VAT da un stride que NO reproduce los limites de
//   comando del stream para dos casos, y el parser usa el
//   stride medido (validado por periodicidad + limite limpio),
//   documentado en gx.cpp. Fuera de esos dos casos exactos
//   (prim+vat+stride aritmetico), rige la aritmetica VCD/VAT.
//   El "opcode desconocido 0x03" de la Fase 10 NO era un
//   opcode: era el 4o byte de un vertice de strip de 8 B,
//   alcanzado por sobre-consumir el draw como 21 B.
// - VAT: CP 0x70+vat (A), 0x80+vat (B), 0x90+vat (C). VAT_A:
//   POSCNT@0 (0=XY,1=XYZ), POSFMT@1-3 (0=U8,1=S8,2=U16,3=S16,
//   4=F32), POSSHFT@4-8, NRMCNT@9, NRMFMT@10-12, COL0CNT@13,
//   COL0FMT@14-16, COL1CNT@17, COL1FMT@18-20, TEX0CNT@21,
//   TEX0FMT@22-24, TEX0SHFT@25-29, BYTEDEQUANT@30,
//   NORMALINDEX3@31. VAT_B: TEX1CNT@0, TEX1FMT@1-3,
//   TEX1SHFT@4-8, TEX2CNT@9, TEX2FMT@10-12, TEX2SHFT@13-17,
//   TEX3CNT@18, TEX3FMT@19-21, TEX3SHFT@22-26, TEX4CNT@27,
//   TEX4FMT@28-30, VCACHE_ENHANCE@31. VAT_C: TEX5-7 analogos.
//   Formatos de color: 0=RGB565,1=RGB8,2=RGBX8,3=RGBA4,4=RGBA6,
//   5=RGBA8.
// - VCD (layout YAGCD 5.11.2, CORREGIDO en Fase 11: la version
//   anterior tenia los campos desplazados y run19 solo parseaba
//   por compensacion de dos errores): CP 0x50 (LO): PMIDX@0,
//   TnMIDX@1+n (1 bit cada uno), POS@9-10, NRM@11-12,
//   COL0@13-14, COL1@15-16. CP 0x60 (HI):
//   TEXn@2n (0=nada,1=directo,2=indice8,3=indice16).
//   Orden de componentes en el vertice: PMIDX, TnMIDX,
//   POS, NRM, CLR0, CLR1, TEX0-7. Los atributos indexados se
//   decodifican como indices (sin resolver contra arrays CP, que
//   el stream no trae): el draw queda marcado indexed y el
//   renderer lo salta, contado.
// - Posiciones enteras: el campo shift de VAT1 es 2 (bits 4-8) y
//   el quad de pantalla completa (0,0)-(10240,7680) solo cuadra
//   con la proyeccion orto + viewport del stream si el divisor
//   es 16, es decir 2^(shift+2). Se usa esa formula para S16/U16
//   (y analogamente para S8/U8 y texcoords enteras) y queda
//   marcada como validada solo para VAT1: si otro VAT dibuja,
//   hay que revalidarla (ver PORT-STATUS).
// - Texturas: el stream de esta fase NO trae registros BP de
//   textura (GXLoadTexObj esta HLEado y no los escribe). La
//   textura vigente de cada draw se resuelve con la lista
//   externa de cargas (offset FIFO -> texObj/mapa, la misma que
//   registra el HLE), no con BP. Direccion sin resolver ->
//   tex_obj = 0 (el renderer usa el placeholder magenta).
// - Display lists: se leen de RAM huesped via el lector que da
//   el llamador; profundidad maxima 4; un DL puede contener
//   draws y cambios de estado que afectan al estado posterior.

#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace sfa {

// Un vertice decodificado (solo lo que el renderer usa ahora;
// normal y color se guardan para TEV/lighting futuros).
struct GxVertex {
  uint8_t pos_mtx_idx = 0;
  bool has_pos_mtx_idx = false;
  uint8_t tex_mtx_idx = 60;  // GX_IDENTITY si no viene en el vertice
  // Atributos indexados (VCD 2 = indice8, 3 = indice16): el
  // parser guarda los indices, pero NO resuelve el atributo
  // (necesitaria base/stride CP 0xA0-0xBF + lector de RAM del
  // array); el draw queda marcado indexed y el renderer lo
  // salta (contado, no silencioso).
  bool has_pos_index = false;
  uint32_t pos_index = 0;
  bool has_tex_index = false;
  uint32_t tex_index = 0;
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
  float nx = 0.0f;
  float ny = 0.0f;
  float nz = 0.0f;
  bool has_normal = false;
  uint8_t r = 255;
  uint8_t g = 255;
  uint8_t b = 255;
  uint8_t a = 255;
  bool has_color = false;
  float s = 0.0f;
  float t = 0.0f;
  bool has_tex = false;
};

// Un draw completo con el estado vigente en su offset.
struct GxDraw {
  uint32_t fifo_offset = 0;
  int prim = 0;  // opcode & 0xF8 (0x80 QUADS, 0x90 TRIANGLES, ...)
  int vat = 0;
  std::vector<GxVertex> verts;
  // Draws con vertices opacos (stride medido, contenido sin
  // decodificar: strips VAT2, ver gx.cpp): los bytes crudos
  // van aqui y verts queda vacio; el renderer los salta.
  bool has_raw_vertices = false;
  std::vector<uint8_t> raw_vertex_data;
  // True si algun vertice trae atributos indexados.
  bool indexed = false;
  uint32_t tex_obj = 0;  // 0 = sin resolver (placeholder)
  int tex_map = 0;
  // Estado vigente (copia en el momento del draw).
  float viewport[6] = {0, 0, 0, 0, 0, 0};
  bool has_viewport = false;
  float projection[6] = {0, 0, 0, 0, 0, 0};
  int projection_type = 0;  // 0 = perspectiva, 1 = orto
  bool has_projection = false;
  float pos_matrix[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
};

// Carga de textura externa (la que registra el HLE GXLoadTexObj).
struct GxTexLoad {
  uint64_t fifo_offset = 0;
  uint32_t tex_obj = 0;
  int map = 0;
};

struct GxStats {
  uint64_t total_bytes = 0;
  uint64_t n_nop = 0;
  uint64_t n_cp = 0;
  uint64_t n_xf = 0;
  uint64_t n_indx = 0;  // comandos XF indexados 0x20-0x38
  uint64_t n_bp = 0;
  uint64_t n_dl = 0;
  uint64_t n_dl_skipped = 0;  // DL sin lector valido: 9 B, sin
                              // contenido (ver ParseStream)
  uint64_t n_inv = 0;
  uint64_t n_draw = 0;
  uint64_t dl_bytes = 0;
  uint64_t indexed_attrs = 0;  // vertices con atributo indexado
  uint64_t n_opaque_draws = 0;  // draws con stride medido
  uint64_t n_indexed_draws = 0;  // draws con algun indice
  std::map<int, uint64_t> draws_by_prim;
  std::map<int, uint64_t> draws_by_vat;
};

class GxParser {
 public:
  // Lector de RAM huesped: devuelve puntero a size bytes en guest,
  // o nullptr si fuera de rango. Solo se usa para display lists.
  using RamReader =
      std::function<const uint8_t*(uint32_t guest, uint32_t size)>;

  GxParser();

  void SetRamReader(RamReader reader) { ram_reader_ = reader; }
  // Copia y ordena por offset FIFO (el HLE las registra en orden,
  // pero se ordena aqui para que la busqueda sea valida siempre).
  void SetTexLoads(const std::vector<GxTexLoad>& loads);

  // Parsea todo el stream. Devuelve false si se detiene en un
  // opcode desconocido o un vertice truncado (ver FirstUnknown()
  // y Stats()). Un DL sin lector valido NO detiene el parse:
  // se salta (n_dl_skipped). Los atributos indexados
  // ya NO detienen el parse: se guardan los indices y el draw
  // queda marcado indexed.
  bool Parse(const uint8_t* fifo, size_t fifo_len);

  // Alimentacion incremental (Fase 11, APK): el estado CP/XF/BP
  // persiste entre llamadas; solo se emiten los draws de
  // comandos completos y el resto incompleto queda pendiente
  // para el siguiente Feed. base_offset es el offset FIFO
  // global del primer byte de data (para que los draws y las
  // texloads sigan siendo comparables tras drenar la captura).
  // Devuelve false si el stream se desincroniza (opcode
  // desconocido / DL ilegible): en ese caso el llamador debe
  // descartar el estado con ResetFeed() (el juego reescribe
  // VCD/VAT/XF cada frame, asi que el estado se restablece).
  // ResetFeed() deja el parser listo para un stream nuevo.
  void ResetFeed();
  bool Feed(const uint8_t* data, size_t len, uint64_t base_offset);
  // Draws emitidos por el ultimo Feed (se vacia en cada Feed).
  std::vector<GxDraw> TakeFedDraws();
  // Anade cargas de textura sin reordenar (el llamador las
  // entrega en orden creciente de offset, como las registra
  // el HLE). Para stream completo, usar SetTexLoads().
  void AppendTexLoads(const std::vector<GxTexLoad>& loads);

  const std::vector<GxDraw>& Draws() const { return draws_; }
  const GxStats& Stats() const { return stats_; }
  const std::map<uint32_t, uint32_t>& CpRegs() const { return cp_; }
  const std::map<uint32_t, uint32_t>& BpRegs() const { return bp_; }
  // Viewport (XF 0x101A) y proyeccion (XF 0x1020) finales.
  bool Viewport(float out[6]) const;
  bool Projection(float out[6], int* type) const;
  // Matriz de posicion XF (indice 0-63) final, o identidad si no
  // se cargo.
  void PosMatrix(int index, float out[12]) const;
  // Primer problema: offset, opcode y contexto en hex.
  std::string FirstUnknown() const { return first_unknown_; }

  // Tamano de vertice directo para un VAT con el VCD vigente.
  // Devuelve 0 si el VAT usa atributos indexados o desconocidos.
  uint32_t VertexSize(int vat) const;

 private:
  // Resultado de ParseStream: kDone (stream completo), kTrunc
  // (el ultimo comando esta incompleto: consumed marca su
  // inicio y el resto queda pendiente), kFailed (ver
  // first_unknown_).
  enum class StreamResult { kDone, kTrunc, kFailed };

  struct VatFmt {
    int pos_count = 0;  // 0 = XY, 1 = XYZ
    int pos_type = 0;
    int pos_shift = 0;
    int nrm_count = 0;  // 0 = normal(3), 1 = NBT(9)
    int nrm_type = 0;
    int col0_count = 0;  // 0 = RGB, 1 = RGBA
    int col0_type = 0;
    int col1_count = 0;
    int col1_type = 0;
    int tex_count[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // 0 = S, 1 = ST
    int tex_type[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int tex_shift[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  };

  StreamResult ParseStream(const uint8_t* data, size_t len, bool in_dl,
                           int depth, uint64_t base_offset,
                           size_t* consumed_io);
  bool ParseDraw(const uint8_t* data, size_t len, size_t* pos_io,
                 int prim, int vat, uint64_t fifo_offset);
  bool DecodeVertex(const uint8_t* data, size_t avail, int vat,
                    uint32_t* consumed, GxVertex* out) const;
  VatFmt VatFormat(int vat) const;
  // Decodifica un componente entero/flotante. Devuelve false si
  // no hay bytes suficientes.
  bool ReadComp(const uint8_t* data, size_t avail, size_t* off, int type,
                int shift, float* out) const;
  bool ReadColor(const uint8_t* data, size_t avail, size_t* off,
                 int type, int count, GxVertex* out) const;
  uint32_t TexLoadFor(uint64_t fifo_offset) const;
  int TexMapFor(uint64_t fifo_offset) const;

  RamReader ram_reader_;
  std::vector<GxTexLoad> tex_loads_;
  std::vector<GxDraw> draws_;
  GxStats stats_;
  std::map<uint32_t, uint32_t> cp_;
  std::map<uint32_t, uint32_t> bp_;
  std::map<uint32_t, std::vector<uint32_t>> xf_;  // addr -> palabras
  std::string first_unknown_;
  bool failed_ = false;
  // True si el ultimo fallo de ParseDraw fue solo falta de
  // bytes (comando incompleto al final del buffer), no un
  // error real: ParseStream lo traduce a kTrunc.
  bool trunc_ = false;
  // Estado incremental (Feed): bytes pendientes del comando
  // incompleto, base FIFO global del stream actual y draws del
  // ultimo Feed. stream_base_ es la base del ParseStream en
  // curso (0 en Parse() completo; base_offset en Feed()).
  std::vector<uint8_t> pending_;
  uint64_t feed_base_ = 0;
  uint64_t stream_base_ = 0;
  std::vector<GxDraw> fed_draws_;
};

}  // namespace sfa
