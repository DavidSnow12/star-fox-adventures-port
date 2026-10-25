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
//   0x40 DL (1+4+4), 0x48 invalidar cache (1 B), 0x61 BP (1+4),
//   0x80-0xBF draw (1+2+vertices). Los codigos 0x20/0x28/0x30/0x38
//   no aparecen en este stream: si aparecen, el parser se detiene
//   y los reporta como desconocidos en vez de adivinar su payload.
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
// - VCD: CP 0x50 (LO): POS@0-1, NRM@2-3, CLR0@4-5, CLR1@6-7,
//   PNMTXIDX@8 (1 bit), TEXnMTXIDX@9+n (1 bit). CP 0x60 (HI):
//   TEXn@2n (0=nada,1=directo,2=indice8,3=indice16).
//   Orden de componentes en el vertice: PNMTXIDX, TEXnMTXIDX,
//   POS, NRM, CLR0, CLR1, TEX0-7. Los atributos indexados NO se
//   decodifican (se reportan como no soportados): todo el stream
//   actual es directo.
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
  uint64_t n_bp = 0;
  uint64_t n_dl = 0;
  uint64_t n_inv = 0;
  uint64_t n_draw = 0;
  uint64_t dl_bytes = 0;
  uint64_t indexed_attrs = 0;  // vertices con atributo indexado
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
  // opcode desconocido, un atributo indexado, un DL ilegible o
  // un vertice truncado (ver FirstUnknown() y Stats()).
  bool Parse(const uint8_t* fifo, size_t fifo_len);

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

  bool ParseStream(const uint8_t* data, size_t len, bool in_dl,
                   int depth, uint64_t base_offset);
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
};

}  // namespace sfa
