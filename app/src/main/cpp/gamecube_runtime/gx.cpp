// Maquina de estado GX en host (ver gx.h para los layouts).
#include "gamecube_runtime/gx.h"

#include "renderer/gx_tev.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

namespace sfa {
namespace {

uint32_t ReadBe32(const uint8_t* p) {
  return (static_cast<uint32_t>(p[0]) << 24) |
         (static_cast<uint32_t>(p[1]) << 16) |
         (static_cast<uint32_t>(p[2]) << 8) | static_cast<uint32_t>(p[3]);
}

uint16_t ReadBe16(const uint8_t* p) {
  return static_cast<uint16_t>((static_cast<uint16_t>(p[0]) << 8) |
                               static_cast<uint16_t>(p[1]));
}

float BitsToFloat(uint32_t bits) {
  float f = 0.0f;
  std::memcpy(&f, &bits, sizeof(f));
  return f;
}

std::string HexContext(const uint8_t* p, size_t n) {
  std::string out;
  char buf[4];
  for (size_t i = 0; i < n; ++i) {
    std::snprintf(buf, sizeof(buf), "%02X", p[i]);
    out += buf;
  }
  return out;
}

// Tamano en bytes de un componente directo (sin indices).
// type: 0=U8, 1=S8, 2=U16, 3=S16, 4=F32. -1 si desconocido.
int CompSize(int type) {
  switch (type) {
    case 0:
    case 1:
      return 1;
    case 2:
    case 3:
      return 2;
    case 4:
      return 4;
    default:
      return -1;
  }
}

int ColorSize(int type) {
  switch (type) {
    case 0:
    case 3:
      return 2;
    case 1:
      return 3;
    case 2:
    case 4:
    case 5:
      return 4;
    default:
      return -1;
  }
}

}  // namespace

GxParser::GxParser() = default;

void GxParser::SetTexLoads(const std::vector<GxTexLoad>& loads) {
  tex_loads_ = loads;
  std::sort(tex_loads_.begin(), tex_loads_.end(),
            [](const GxTexLoad& a, const GxTexLoad& b) {
              return a.fifo_offset < b.fifo_offset;
            });
}

bool GxParser::Parse(const uint8_t* fifo, size_t fifo_len) {
  draws_.clear();
  copies_.clear();
  fed_draws_.clear();
  pending_.clear();
  stats_ = GxStats();
  cp_.clear();
  bp_.clear();
  xf_.clear();
  first_unknown_.clear();
  failed_ = false;
  trunc_ = false;
  stream_base_ = 0;
  feed_base_ = 0;
  stats_.total_bytes = fifo_len;
  size_t consumed = 0;
  StreamResult r = ParseStream(fifo, fifo_len, false, 0, 0, &consumed);
  if (r == StreamResult::kTrunc) {
    first_unknown_ = "stream truncado en offset " +
                     std::to_string(consumed);
    failed_ = true;
    return false;
  }
  return r == StreamResult::kDone && !failed_;
}

void GxParser::ResetFeed() {
  draws_.clear();
  copies_.clear();
  fed_draws_.clear();
  pending_.clear();
  stats_ = GxStats();
  cp_.clear();
  bp_.clear();
  xf_.clear();
  first_unknown_.clear();
  failed_ = false;
  trunc_ = false;
  stream_base_ = 0;
  feed_base_ = 0;
}

bool GxParser::Feed(const uint8_t* data, size_t len, uint64_t base_offset) {
  if (failed_) return false;
  if (data == nullptr && len != 0) return false;
  fed_draws_.clear();
  trunc_ = false;
  if (pending_.empty()) {
    feed_base_ = base_offset;
  } else if (base_offset != feed_base_ + pending_.size()) {
    // El llamador debe alimentar bytes contiguos: un salto
    // invalida los offsets FIFO de draws y texloads.
    first_unknown_ = "Feed no contiguo en offset " +
                     std::to_string(base_offset);
    failed_ = true;
    return false;
  }
  if (len > 0) {
    pending_.insert(pending_.end(), data, data + len);
    stats_.total_bytes += len;
  }
  stream_base_ = feed_base_;
  size_t consumed = 0;
  StreamResult r = ParseStream(pending_.data(), pending_.size(), false, 0,
                               0, &consumed);
  if (r == StreamResult::kFailed) return false;
  if (r == StreamResult::kTrunc) {
    // Conservar solo el comando incompleto (y su base).
    pending_.erase(pending_.begin(),
                   pending_.begin() + static_cast<long>(consumed));
    feed_base_ += consumed;
    return true;
  }
  pending_.clear();
  feed_base_ += consumed;
  return true;
}

std::vector<GxDraw> GxParser::TakeFedDraws() {
  std::vector<GxDraw> out;
  out.swap(fed_draws_);
  return out;
}

void GxParser::AppendTexLoads(const std::vector<GxTexLoad>& loads) {
  tex_loads_.insert(tex_loads_.end(), loads.begin(), loads.end());
}

GxParser::StreamResult GxParser::ParseStream(const uint8_t* data, size_t len,
                                             bool in_dl, int depth,
                                             uint64_t base_offset,
                                             size_t* consumed_io) {
  size_t pos = 0;
  // En un DL, la truncacion es un error (el DL viene completo
  // de RAM); en el stream principal, es kTrunc (Feed retiene
  // el resto). El helper traduce el caso.
  auto trunc_or_fail = [&](size_t at) -> StreamResult {
    if (in_dl) {
      first_unknown_ = "DL truncado en offset " + std::to_string(at);
      failed_ = true;
      return StreamResult::kFailed;
    }
    if (consumed_io != nullptr) *consumed_io = at;
    return StreamResult::kTrunc;
  };
  while (pos < len) {
    uint8_t op = data[pos];
    uint64_t fifo_offset =
        in_dl ? base_offset : (stream_base_ + pos);
    if (op == 0x00) {
      ++stats_.n_nop;
      ++pos;
      continue;
    }
    if (op == 0x08) {
      if (pos + 6 > len) return trunc_or_fail(pos);
      uint32_t addr = data[pos + 1];
      uint32_t value = ReadBe32(data + pos + 2);
      cp_[addr] = value;
      ++stats_.n_cp;
      pos += 6;
      continue;
    }
    if (op == 0x10) {
      if (pos + 5 > len) return trunc_or_fail(pos);
      uint32_t header = ReadBe32(data + pos + 1);
      uint32_t count = (header >> 16) + 1;
      uint32_t addr = header & 0xFFFF;
      if (pos + 5 + 4 * static_cast<size_t>(count) > len) {
        return trunc_or_fail(pos);
      }
      std::vector<uint32_t> words;
      for (uint32_t i = 0; i < count; ++i) {
        words.push_back(ReadBe32(data + pos + 5 + 4 * i));
      }
      for (uint32_t i = 0; i < count; ++i) {
        xf_[addr + i] = std::vector<uint32_t>(1, words[i]);
      }
      ++stats_.n_xf;
      pos += 5 + 4 * static_cast<size_t>(count);
      continue;
    }
    if (op == 0x20 || op == 0x28 || op == 0x30 || op == 0x38) {
      // XF indexado (YAGCD 5.11.5.9): opcode + indice (2 B) +
      // (longitud-1:4 bits, direccion:12 bits) + 4 B por dato.
      // Se parsea y cuenta; NO muta xf_ (ver gx.h).
      if (pos + 5 > len) return trunc_or_fail(pos);
      uint32_t w = ReadBe16(data + pos + 3);
      uint32_t count = ((w >> 12) & 0xF) + 1;
      if (pos + 5 + 4 * static_cast<size_t>(count) > len) {
        return trunc_or_fail(pos);
      }
      ++stats_.n_indx;
      pos += 5 + 4 * static_cast<size_t>(count);
      continue;
    }
    if (op == 0x61) {
      if (pos + 5 > len) return trunc_or_fail(pos);
      uint32_t v = ReadBe32(data + pos + 1);
      bp_[v >> 24] = v & 0xFFFFFF;
      ++stats_.n_bp;
      // Tramo 6: disparo de copia EFB = escritura BP 0x52 en
      // el propio FIFO (GXCopyDisp/GXCopyTex; correccion a la
      // nota Tramo 5 que lo situaba en MMIO PE). Se registra
      // el evento con los regs de copia vigentes; la copia en
      // si sigue pendiente (sin buffer EFB en el renderer).
      if ((v >> 24) == 0x52) {
        GxCopy c;
        c.fifo_offset = fifo_offset;
        c.reg52 = v & 0xFFFFFF;
        auto take = [&](uint32_t reg, uint32_t* out, bool* has) {
          auto it = bp_.find(reg);
          if (it != bp_.end()) {
            *out = it->second;
            *has = true;
          }
        };
        take(0x49, &c.reg49, &c.has49);
        take(0x4A, &c.reg4a, &c.has4a);
        take(0x4B, &c.reg4b, &c.has4b);
        take(0x4D, &c.reg4d, &c.has4d);
        copies_.push_back(c);
      }
      pos += 5;
      continue;
    }
    if (op == 0x40) {
      if (pos + 9 > len) return trunc_or_fail(pos);
      uint32_t addr = ReadBe32(data + pos + 1);
      uint32_t size = ReadBe32(data + pos + 5);
      ++stats_.n_dl;
      stats_.dl_bytes += size;
      if (depth >= 4) {
        first_unknown_ = "DL anidado demasiado profundo en offset " +
                         std::to_string(fifo_offset);
        failed_ = true;
        return StreamResult::kFailed;
      }
      // Fase 11: un DL sin lector valido NO detiene el stream.
      // Sin lector (test host sin RAM) o con lector que devuelve
      // nullptr (direccion/tamano fuera de rango: el caso del
      // DL 0x80379320 size 0x7FC86CE0, repetido 96x en run42),
      // se consumen sus 9 B y se cuenta como saltado. El
      // contenido del DL no se dibuja en ese caso. Con lector
      // valido (APK: RAM viva) el contenido SI se parsea. Un
      // DL que fallase a mitad si detendria el parse (fallo
      // real, no ausencia de lector).
      const uint8_t* dl = nullptr;
      if (ram_reader_ != nullptr) dl = ram_reader_(addr, size);
      if (dl == nullptr) {
        ++stats_.n_dl_skipped;
        pos += 9;
        continue;
      }
      size_t dl_consumed = 0;
      StreamResult dr =
          ParseStream(dl, size, true, depth + 1, fifo_offset, &dl_consumed);
      if (dr != StreamResult::kDone) {
        if (dr == StreamResult::kFailed) {
          return StreamResult::kFailed;
        }
        first_unknown_ = "DL truncado en offset " +
                         std::to_string(fifo_offset);
        failed_ = true;
        return StreamResult::kFailed;
      }
      pos += 9;
      continue;
    }
    if (op == 0x48) {
      ++stats_.n_inv;
      ++pos;
      continue;
    }
    if (op >= 0x80 && op <= 0xBF) {
      size_t draw_start = pos;
      trunc_ = false;
      if (!ParseDraw(data, len, &pos, op & 0xF8, op & 0x07,
                     fifo_offset)) {
        if (trunc_ && !in_dl) return trunc_or_fail(draw_start);
        return StreamResult::kFailed;
      }
      continue;
    }
    // Opcode desconocido: detener sin adivinar su payload.
    {
      size_t ctx_len = len - pos < 16 ? len - pos : 16;
      char buf[256];
      std::snprintf(buf, sizeof(buf),
                    "opcode desconocido 0x%02X en offset %llu contexto "
                    "%s",
                    op, static_cast<unsigned long long>(fifo_offset),
                    HexContext(data + pos, ctx_len).c_str());
      first_unknown_ = buf;
      failed_ = true;
      return StreamResult::kFailed;
    }
  }
  if (consumed_io != nullptr) *consumed_io = pos;
  return StreamResult::kDone;
}

bool GxParser::ParseDraw(const uint8_t* data, size_t len, size_t* pos_io,
                         int prim, int vat, uint64_t fifo_offset) {
  size_t pos = *pos_io;
  if (pos + 3 > len) {
    trunc_ = true;
    return false;
  }
  uint32_t count = ReadBe16(data + pos + 1);
  uint32_t vsize = VertexSize(vat);
  if (vsize == 0) {
    first_unknown_ = "draw con VAT no decodificable (vat=" +
                     std::to_string(vat) + ") en offset " +
                     std::to_string(fifo_offset);
    failed_ = true;
    return false;
  }
  if (pos + 3 + static_cast<size_t>(vsize) * count > len) {
    trunc_ = true;
    return false;
  }
  GxDraw draw;
  draw.fifo_offset = static_cast<uint32_t>(fifo_offset);
  draw.prim = prim;
  draw.vat = vat;
  draw.tex_obj = TexLoadFor(fifo_offset);
  draw.tex_map = TexMapFor(fifo_offset);
  TexLoadsFor(fifo_offset, draw.tex_objs);
  // Instantánea TEV (anclaje previo obligatorio): se copia
  // AQUI, antes de las tres salidas (normal, opaca, POINTS),
  // porque bp_ muta con el stream y el generador no puede
  // leerlo al final del frame. Sin snapshot no hay TEV.
  draw.tev = SnapshotTevFromBp(bp_);
  draw.has_tev = true;
  // Estado fijo (Tramo 5): mismo punto que TEV, misma razon.
  draw.fixed = SnapshotFixedFromBp(bp_);
  // Texgen XF por coord (palabras 0x1040+i / 0x1050+i).
  for (int i = 0; i < 8; ++i) {
    auto it1 = xf_.find(0x1040u + static_cast<uint32_t>(i));
    auto it2 = xf_.find(0x1050u + static_cast<uint32_t>(i));
    if (it1 != xf_.end() && !it1->second.empty()) {
      draw.texgen_w1[i] = it1->second[0];
      draw.has_texgen[i] = true;
    }
    if (it2 != xf_.end() && !it2->second.empty()) {
      draw.texgen_w2[i] = it2->second[0];
      draw.has_texgen[i] = true;
    }
  }
  draw.has_viewport = Viewport(draw.viewport);
  draw.has_projection = Projection(draw.projection, &draw.projection_type);
  // Matriz de posicion vigente (CP 0x30, PNMTXIDX en bits 0-5).
  int pnmtx = 0;
  auto cp_it = cp_.find(0x30);
  if (cp_it != cp_.end()) pnmtx = static_cast<int>(cp_it->second & 0x3F);
  PosMatrix(pnmtx, draw.pos_matrix);
  // Desviacion medida A (run42, offsets 2157-4122): TRIANGLESTRIP
  // VAT2 con stride aritmetico 21 aparece en el stream con
  // stride 8: 15 draws consecutivos a exactamente 131 B
  // (3 + 16x8), seguidos de 32 NOP + recarga VCD/XF limpia en
  // 4154. Con 21 B el parser aterriza en 2497 en un byte 0x03
  // que NO es un opcode: es el 4o byte del vertice 9 del
  // segundo strip (bytes 03 00 03 00 33...). El contenido de
  // 8 B no se decodifica (sin base de arrays CP 0xA0-0xBF en
  // el stream y sin escritura CP por MMIO en la traza HW):
  // se guarda crudo y el renderer lo salta, contado.
  if (prim == 0x98 && vat == 2 && vsize == 21) {
    if (pos + 3 + 8u * count > len) {
      trunc_ = true;
      return false;
    }
    draw.has_raw_vertices = true;
    draw.raw_vertex_data.assign(data + pos + 3,
                                data + pos + 3 + 8u * count);
    draws_.push_back(draw);
    fed_draws_.push_back(draw);
    ++stats_.n_draw;
    ++stats_.n_opaque_draws;
    ++stats_.draws_by_prim[prim];
    ++stats_.draws_by_vat[vat];
    *pos_io = pos + 3 + 8u * count;
    return true;
  }
  // Desviacion medida B (run42, offsets 4207-56339): POINTS
  // VAT0 con stride aritmetico 11 aparece con stride 10
  // (POS S16 XYZ + TEX S16 ST, sin byte de indice de matriz):
  // 92 draws a exactamente 567 B (3 + 50x10 + 64 NOP), y el
  // ultimo cierra con 32 NOP exactos antes de la recarga XF
  // de viewport en 56339. Con 11 B el parser se pasa 18 B y
  // aterriza dentro del valor XF 0x44258000 (byte 0x25).
  // Las posiciones usan la misma formula de shift que VAT1
  // (divisor 2^(shift+2)); para VAT0 es extrapolacion, no
  // validacion (el renderer salta los POINTS igualmente).
  if (prim == 0xB8 && vat == 0 && vsize == 11) {
    if (pos + 3 + 10u * count > len) {
      trunc_ = true;
      return false;
    }
    VatFmt f = VatFormat(vat);
    size_t vpos = pos + 3;
    for (uint32_t i = 0; i < count; ++i) {
      GxVertex v;
      size_t off = 0;
      float x = 0, y = 0, z = 0, s = 0, t = 0;
      const uint8_t* p = data + vpos;
      if (!ReadComp(p, 10, &off, f.pos_type, f.pos_shift, &x) ||
          !ReadComp(p, 10, &off, f.pos_type, f.pos_shift, &y) ||
          !ReadComp(p, 10, &off, f.pos_type, f.pos_shift, &z) ||
          !ReadComp(p, 10, &off, f.tex_type[0], f.tex_shift[0], &s) ||
          !ReadComp(p, 10, &off, f.tex_type[0], f.tex_shift[0], &t)) {
        first_unknown_ = "vertice POINTS no decodificable en offset " +
                         std::to_string(fifo_offset);
        failed_ = true;
        return false;
      }
      v.x = x;
      v.y = y;
      v.z = z;
      v.s = s;
      v.t = t;
      v.has_tex = true;
      draw.verts.push_back(v);
      vpos += 10;
    }
    draws_.push_back(draw);
    fed_draws_.push_back(draw);
    ++stats_.n_draw;
    ++stats_.draws_by_prim[prim];
    ++stats_.draws_by_vat[vat];
    *pos_io = pos + 3 + 10u * count;
    return true;
  }
  // Si algun campo VCD es indexado, todos los vertices del
  // draw lo son (el indice va por vertice, no por draw).
  bool vcd_indexed = false;
  {
    auto lo_it = cp_.find(0x50);
    auto hi_it = cp_.find(0x60);
    if (lo_it != cp_.end() && hi_it != cp_.end()) {
      uint32_t lo = lo_it->second;
      uint32_t hi = hi_it->second;
      for (int i = 0; i < 4; ++i) {
        // POS@9, NRM@11, COL0@13, COL1@15 (2 bits cada uno).
        uint32_t f = (lo >> (9 + 2 * i)) & 0x3;
        if (f == 2 || f == 3) vcd_indexed = true;
      }
      for (int i = 0; i < 8; ++i) {
        uint32_t tf = (hi >> (2 * i)) & 0x3;  // TEX0-7
        if (tf == 2 || tf == 3) vcd_indexed = true;
      }
    }
  }
  size_t vpos = pos + 3;
  for (uint32_t i = 0; i < count; ++i) {
    GxVertex v;
    uint32_t consumed = 0;
    if (!DecodeVertex(data + vpos, vsize, vat, &consumed, &v)) {
      first_unknown_ = "vertice no decodificable en offset " +
                       std::to_string(fifo_offset);
      failed_ = true;
      return false;
    }
    if (vcd_indexed) {
      draw.indexed = true;
      ++stats_.indexed_attrs;
    }
    draw.verts.push_back(v);
    vpos += consumed;
  }
  // Matrices de textura (Tramo 5): indices TnMIDX distintos
  // usados por los vertices (solo camino normal; opacos y
  // POINTS no las llevan porque el renderer los salta).
  // Indice 60 = identidad (no se guarda). Base XF: id*4 si
  // id < 64, 1280 + (id-64)*4 si id >= 64 (GXLoadTexMtxImm).
  {
    bool seen[256] = {false};
    for (const GxVertex& v : draw.verts) {
      for (int m = 0; m < 8; ++m) {
        if (!v.has_uv[m]) continue;
        int idx = v.tex_mtx_idx_arr[m];
        if (idx == 60 || seen[idx]) continue;
        seen[idx] = true;
        uint32_t base = idx < 64
                            ? static_cast<uint32_t>(idx) * 4u
                            : 1280u + (static_cast<uint32_t>(idx) - 64u) * 4u;
        std::vector<float> mat(12, 0.0f);
        bool any = false;
        for (int k = 0; k < 12; ++k) {
          auto it = xf_.find(base + static_cast<uint32_t>(k));
          if (it != xf_.end() && !it->second.empty()) {
            mat[static_cast<size_t>(k)] = BitsToFloat(it->second[0]);
            any = true;
          }
        }
        if (any) draw.tex_matrices[idx] = mat;
      }
    }
  }
  // Si el vertice trae PNMTXIDX propio, la matriz del draw es la
  // del primer vertice (GX permite una por vertice; el renderer
  // actual usa una por draw y este caso no aparece en el stream).
  if (!draw.verts.empty() && draw.verts[0].has_pos_mtx_idx) {
    PosMatrix(draw.verts[0].pos_mtx_idx, draw.pos_matrix);
  }
  draws_.push_back(draw);
  fed_draws_.push_back(draw);
  ++stats_.n_draw;
  if (draw.indexed) ++stats_.n_indexed_draws;
  ++stats_.draws_by_prim[prim];
  ++stats_.draws_by_vat[vat];
  *pos_io = pos + 3 + static_cast<size_t>(vsize) * count;
  return true;
}

GxParser::VatFmt GxParser::VatFormat(int vat) const {
  VatFmt f;
  auto get = [&](uint32_t addr) -> uint32_t {
    auto it = cp_.find(addr);
    return it == cp_.end() ? 0 : it->second;
  };
  uint32_t a = get(0x70 + vat);
  uint32_t b = get(0x80 + vat);
  uint32_t c = get(0x90 + vat);
  f.pos_count = static_cast<int>(a & 0x1);
  f.pos_type = static_cast<int>((a >> 1) & 0x7);
  f.pos_shift = static_cast<int>((a >> 4) & 0x1F);
  f.nrm_count = static_cast<int>((a >> 9) & 0x1);
  f.nrm_type = static_cast<int>((a >> 10) & 0x7);
  f.col0_count = static_cast<int>((a >> 13) & 0x1);
  f.col0_type = static_cast<int>((a >> 14) & 0x7);
  f.col1_count = static_cast<int>((a >> 17) & 0x1);
  f.col1_type = static_cast<int>((a >> 18) & 0x7);
  f.tex_count[0] = static_cast<int>((a >> 21) & 0x1);
  f.tex_type[0] = static_cast<int>((a >> 22) & 0x7);
  f.tex_shift[0] = static_cast<int>((a >> 25) & 0x1F);
  f.tex_count[1] = static_cast<int>(b & 0x1);
  f.tex_type[1] = static_cast<int>((b >> 1) & 0x7);
  f.tex_shift[1] = static_cast<int>((b >> 4) & 0x1F);
  f.tex_count[2] = static_cast<int>((b >> 9) & 0x1);
  f.tex_type[2] = static_cast<int>((b >> 10) & 0x7);
  f.tex_shift[2] = static_cast<int>((b >> 13) & 0x1F);
  f.tex_count[3] = static_cast<int>((b >> 18) & 0x1);
  f.tex_type[3] = static_cast<int>((b >> 19) & 0x7);
  f.tex_shift[3] = static_cast<int>((b >> 22) & 0x1F);
  f.tex_count[4] = static_cast<int>((b >> 27) & 0x1);
  f.tex_type[4] = static_cast<int>((b >> 28) & 0x7);
  f.tex_shift[4] = 0;  // TEX4SHFT no esta en VAT_B (ver YAGCD)
  f.tex_count[5] = static_cast<int>(c & 0x1);
  f.tex_type[5] = static_cast<int>((c >> 1) & 0x7);
  f.tex_shift[5] = static_cast<int>((c >> 4) & 0x1F);
  f.tex_count[6] = static_cast<int>((c >> 9) & 0x1);
  f.tex_type[6] = static_cast<int>((c >> 10) & 0x7);
  f.tex_shift[6] = static_cast<int>((c >> 13) & 0x1F);
  f.tex_count[7] = static_cast<int>((c >> 18) & 0x1);
  f.tex_type[7] = static_cast<int>((c >> 19) & 0x7);
  f.tex_shift[7] = static_cast<int>((c >> 22) & 0x1F);
  return f;
}

uint32_t GxParser::VertexSize(int vat) const {
  auto vcd_lo_it = cp_.find(0x50);
  auto vcd_hi_it = cp_.find(0x60);
  if (vcd_lo_it == cp_.end() || vcd_hi_it == cp_.end()) return 0;
  uint32_t lo = vcd_lo_it->second;
  uint32_t hi = vcd_hi_it->second;
  VatFmt f = VatFormat(vat);
  uint32_t size = 0;
  // Tamano de un campo indexado en el FIFO: 1 B (indice8) o
  // 2 B (indice16). El atributo al que apunta NO se decodifica
  // aqui (ver DecodeVertex): solo se reserva su hueco para
  // que el parse no se desincronice.
  auto field_size = [](uint32_t field, uint32_t direct_size,
                       uint32_t* out) -> bool {
    if (field == 0) return true;  // ausente: 0 B
    if (field == 1) {
      *out += direct_size;
      return true;
    }
    if (field == 2) {
      *out += 1;
      return true;
    }
    if (field == 3) {
      *out += 2;
      return true;
    }
    return false;
  };
  // Indices de matriz (1 byte cada uno si presentes; layout
  // YAGCD: PMIDX@0, TnMIDX@1+n).
  if (lo & 0x1) size += 1;  // PMIDX
  for (int i = 0; i < 8; ++i) {
    if (lo & (0x2u << i)) size += 1;  // TEXnMTXIDX
  }
  // POS
  uint32_t pos_field = (lo >> 9) & 0x3;
  if (pos_field == 0) {
    // Sin posicion: un draw sin posicion no es valido aqui.
    return 0;
  }
  int cs = CompSize(f.pos_type);
  if (cs < 0) return 0;
  if (!field_size(pos_field,
                  static_cast<uint32_t>(cs) * (f.pos_count ? 3u : 2u),
                  &size)) {
    return 0;
  }
  // NRM
  uint32_t nrm_field = (lo >> 11) & 0x3;
  if (nrm_field != 0) {
    if (f.nrm_count) return 0;  // NBT (9 comps) no soportado
    cs = CompSize(f.nrm_type);
    if (cs < 0) return 0;
    if (!field_size(nrm_field, static_cast<uint32_t>(cs) * 3u, &size)) {
      return 0;
    }
  }
  // CLR0 / CLR1
  uint32_t c0_field = (lo >> 13) & 0x3;
  if (c0_field != 0) {
    cs = ColorSize(f.col0_type);
    if (cs < 0) return 0;
    if (!field_size(c0_field, static_cast<uint32_t>(cs), &size)) {
      return 0;
    }
  }
  uint32_t c1_field = (lo >> 15) & 0x3;
  if (c1_field != 0) {
    cs = ColorSize(f.col1_type);
    if (cs < 0) return 0;
    if (!field_size(c1_field, static_cast<uint32_t>(cs), &size)) {
      return 0;
    }
  }
  // TEX0-7
  for (int i = 0; i < 8; ++i) {
    uint32_t t_field = (hi >> (2 * i)) & 0x3;
    if (t_field == 0) continue;
    cs = CompSize(f.tex_type[i]);
    if (cs < 0) return 0;
    if (!field_size(t_field,
                    static_cast<uint32_t>(cs) *
                        (f.tex_count[i] ? 2u : 1u),
                    &size)) {
      return 0;
    }
  }
  return size;
}

bool GxParser::ReadComp(const uint8_t* data, size_t avail, size_t* off,
                        int type, int shift, float* out) const {
  int cs = CompSize(type);
  if (cs < 0 || *off + static_cast<size_t>(cs) > avail) return false;
  const uint8_t* p = data + *off;
  double v = 0.0;
  switch (type) {
    case 0:
      v = p[0];
      break;
    case 1:
      v = static_cast<int8_t>(p[0]);
      break;
    case 2:
      v = ReadBe16(p);
      break;
    case 3:
      v = static_cast<int16_t>(ReadBe16(p));
      break;
    case 4:
      *out = BitsToFloat(ReadBe32(p));
      *off += 4;
      return true;
    default:
      return false;
  }
  // Divisor validado para VAT1 (shift 2 -> /16). Ver gx.h.
  double divisor = 1.0;
  for (int i = 0; i < shift + 2; ++i) divisor *= 2.0;
  *out = static_cast<float>(v / divisor);
  *off += static_cast<size_t>(cs);
  return true;
}

bool GxParser::ReadColor(const uint8_t* data, size_t avail, size_t* off,
                         int type, int count, GxVertex* out) const {
  (void)count;  // el tamano lo da el formato, no el contador
  int cs = ColorSize(type);
  if (cs < 0 || *off + static_cast<size_t>(cs) > avail) return false;
  const uint8_t* p = data + *off;
  auto expand5 = [](uint32_t v) -> uint8_t {
    return static_cast<uint8_t>((v << 3) | (v >> 2));
  };
  auto expand6 = [](uint32_t v) -> uint8_t {
    return static_cast<uint8_t>((v << 2) | (v >> 4));
  };
  auto expand4 = [](uint32_t v) -> uint8_t {
    return static_cast<uint8_t>((v << 4) | v);
  };
  switch (type) {
    case 0: {
      uint16_t v = ReadBe16(p);
      out->r = expand5((v >> 11) & 31);
      out->g = expand6((v >> 5) & 63);
      out->b = expand5(v & 31);
      out->a = 255;
      break;
    }
    case 1:
      out->r = p[0];
      out->g = p[1];
      out->b = p[2];
      out->a = 255;
      break;
    case 2:
      out->r = p[0];
      out->g = p[1];
      out->b = p[2];
      out->a = 255;
      break;
    case 3: {
      uint16_t v = ReadBe16(p);
      out->r = expand4((v >> 12) & 15);
      out->g = expand4((v >> 8) & 15);
      out->b = expand4((v >> 4) & 15);
      out->a = expand4(v & 15);
      break;
    }
    case 4: {
      // RGBA6 empaquetado en 4 bytes (6 bits por canal).
      uint32_t r6 = p[0] >> 2;
      uint32_t g6 = ((p[0] & 3) << 4) | (p[1] >> 4);
      uint32_t b6 = ((p[1] & 15) << 2) | (p[2] >> 6);
      uint32_t a6 = p[2] & 63;
      auto expand6b = [](uint32_t v) -> uint8_t {
        return static_cast<uint8_t>((v * 255 + 31) / 63);
      };
      out->r = expand6b(r6);
      out->g = expand6b(g6);
      out->b = expand6b(b6);
      out->a = expand6b(a6);
      break;
    }
    case 5:
      out->r = p[0];
      out->g = p[1];
      out->b = p[2];
      out->a = p[3];
      break;
    default:
      return false;
  }
  out->has_color = true;
  *off += static_cast<size_t>(cs);
  return true;
}

bool GxParser::DecodeVertex(const uint8_t* data, size_t avail, int vat,
                            uint32_t* consumed, GxVertex* out) const {
  auto vcd_lo_it = cp_.find(0x50);
  auto vcd_hi_it = cp_.find(0x60);
  if (vcd_lo_it == cp_.end() || vcd_hi_it == cp_.end()) return false;
  uint32_t lo = vcd_lo_it->second;
  uint32_t hi = vcd_hi_it->second;
  VatFmt f = VatFormat(vat);
  size_t off = 0;
  // Lee un indice (1 B si field == 2, 2 B si field == 3).
  auto read_index = [&](uint32_t field, uint32_t* value) -> bool {
    if (field == 2) {
      if (off + 1 > avail) return false;
      *value = data[off];
      off += 1;
      return true;
    }
    if (field == 3) {
      if (off + 2 > avail) return false;
      *value = ReadBe16(data + off);
      off += 2;
      return true;
    }
    return false;
  };
  if (lo & 0x1) {
    if (off + 1 > avail) return false;
    out->pos_mtx_idx = data[off];
    out->has_pos_mtx_idx = true;
    off += 1;
  }
  for (int i = 0; i < 8; ++i) {
    if (lo & (0x2u << i)) {
      if (off + 1 > avail) return false;
      out->tex_mtx_idx_arr[i] = data[off];
      if (i == 0) out->tex_mtx_idx = data[off];
      off += 1;
    }
  }
  uint32_t pos_field = (lo >> 9) & 0x3;
  float x = 0, y = 0, z = 0;
  if (pos_field == 2 || pos_field == 3) {
    uint32_t idx = 0;
    if (!read_index(pos_field, &idx)) return false;
    out->has_pos_index = true;
    out->pos_index = idx;
  } else if (pos_field == 1) {
    if (!ReadComp(data, avail, &off, f.pos_type, f.pos_shift, &x)) {
      return false;
    }
    if (!ReadComp(data, avail, &off, f.pos_type, f.pos_shift, &y)) {
      return false;
    }
    if (f.pos_count) {
      if (!ReadComp(data, avail, &off, f.pos_type, f.pos_shift, &z)) {
        return false;
      }
    }
  } else {
    return false;
  }
  out->x = x;
  out->y = y;
  out->z = z;
  uint32_t nrm_field = (lo >> 11) & 0x3;
  if (nrm_field != 0) {
    if (nrm_field == 2 || nrm_field == 3) {
      uint32_t idx = 0;
      if (!read_index(nrm_field, &idx)) return false;
    } else if (nrm_field != 1 || f.nrm_count) {
      return false;
    } else {
      float nx = 0, ny = 0, nz = 0;
    // Normales: normalizacion directa (sin shift de VAT; la
    // iluminacion no la usa el renderer actual).
    auto read_nrm = [&](float* v) -> bool {
      int cs = CompSize(f.nrm_type);
      if (cs < 0 || off + static_cast<size_t>(cs) > avail) return false;
      const uint8_t* p = data + off;
      switch (f.nrm_type) {
        case 0:
          *v = p[0] / 255.0f;
          break;
        case 1:
          *v = static_cast<int8_t>(p[0]) / 127.0f;
          break;
        case 2:
          *v = ReadBe16(p) / 65535.0f;
          break;
        case 3:
          *v = static_cast<int16_t>(ReadBe16(p)) / 32767.0f;
          break;
        case 4:
          *v = BitsToFloat(ReadBe32(p));
          break;
        default:
          return false;
      }
      off += static_cast<size_t>(cs);
      return true;
    };
    if (!read_nrm(&nx) || !read_nrm(&ny) || !read_nrm(&nz)) return false;
    out->nx = nx;
    out->ny = ny;
    out->nz = nz;
    out->has_normal = true;
    }
  }
  uint32_t c0_field = (lo >> 13) & 0x3;
  if (c0_field != 0) {
    if (c0_field == 2 || c0_field == 3) {
      uint32_t idx = 0;
      if (!read_index(c0_field, &idx)) return false;
    } else if (c0_field != 1) {
      return false;
    } else if (!ReadColor(data, avail, &off, f.col0_type, f.col0_count,
                          out)) {
      return false;
    }
  }
  uint32_t c1_field = (lo >> 15) & 0x3;
  if (c1_field != 0) {
    if (c1_field == 2 || c1_field == 3) {
      uint32_t idx = 0;
      if (!read_index(c1_field, &idx)) return false;
    } else if (c1_field != 1) {
      return false;
    } else {
      // CLR1 (Tramo 5): ya no se tira; el renderer TEV la
      // entrega como vColor1 cuando el canal es el set 1.
      GxVertex tmp;
      if (!ReadColor(data, avail, &off, f.col1_type, f.col1_count,
                     &tmp)) {
        return false;
      }
      out->r1 = tmp.r;
      out->g1 = tmp.g;
      out->b1 = tmp.b;
      out->a1 = tmp.a;
      out->has_color1 = true;
    }
  }
  for (int i = 0; i < 8; ++i) {
    uint32_t t_field = (hi >> (2 * i)) & 0x3;
    if (t_field == 0) continue;
    if (t_field == 2 || t_field == 3) {
      uint32_t idx = 0;
      if (!read_index(t_field, &idx)) return false;
      if (i == 0) {
        out->has_tex_index = true;
        out->tex_index = idx;
      }
      continue;
    }
    if (t_field != 1) return false;
    float s = 0, t = 0;
    if (!ReadComp(data, avail, &off, f.tex_type[i], f.tex_shift[i],
                  &s)) {
      return false;
    }
    if (f.tex_count[i]) {
      if (!ReadComp(data, avail, &off, f.tex_type[i], f.tex_shift[i],
                    &t)) {
        return false;
      }
    }
    // Tramo 5: se guardan las 8 coords (antes solo TEX0).
    out->uv_s[i] = s;
    out->uv_t[i] = t;
    out->has_uv[i] = true;
    if (i == 0) {
      out->s = s;
      out->t = t;
      out->has_tex = true;
    }
  }
  *consumed = static_cast<uint32_t>(off);
  return true;
}

uint32_t GxParser::TexLoadFor(uint64_t fifo_offset) const {
  uint32_t tex = 0;
  for (size_t i = 0; i < tex_loads_.size(); ++i) {
    if (tex_loads_[i].fifo_offset <= fifo_offset) {
      tex = tex_loads_[i].tex_obj;
    } else {
      break;
    }
  }
  return tex;
}

void GxParser::TexLoadsFor(uint64_t fifo_offset, uint32_t out[8]) const {
  for (int m = 0; m < 8; ++m) out[m] = 0;
  for (size_t i = 0; i < tex_loads_.size(); ++i) {
    if (tex_loads_[i].fifo_offset > fifo_offset) break;
    int map = tex_loads_[i].map;
    if (map >= 0 && map < 8) out[map] = tex_loads_[i].tex_obj;
  }
}

int GxParser::TexMapFor(uint64_t fifo_offset) const {
  int map = 0;
  for (size_t i = 0; i < tex_loads_.size(); ++i) {
    if (tex_loads_[i].fifo_offset <= fifo_offset) {
      map = tex_loads_[i].map;
    } else {
      break;
    }
  }
  return map;
}

bool GxParser::Viewport(float out[6]) const {
  for (int i = 0; i < 6; ++i) {
    auto it = xf_.find(0x101A + i);
    if (it == xf_.end() || it->second.empty()) return false;
    out[i] = BitsToFloat(it->second[0]);
  }
  return true;
}

bool GxParser::Projection(float out[6], int* type) const {
  for (int i = 0; i < 6; ++i) {
    auto it = xf_.find(0x1020 + i);
    if (it == xf_.end() || it->second.empty()) return false;
    out[i] = BitsToFloat(it->second[0]);
  }
  auto it = xf_.find(0x1026);
  if (it != xf_.end() && !it->second.empty() && type != nullptr) {
    *type = static_cast<int>(it->second[0]);
  } else if (type != nullptr) {
    *type = 0;
  }
  return true;
}

void GxParser::PosMatrix(int index, float out[12]) const {
  static const float kIdentity[12] = {1, 0, 0, 0, 0, 1,
                                      0, 0, 0, 0, 1, 0};
  for (int i = 0; i < 12; ++i) out[i] = kIdentity[i];
  uint32_t base = static_cast<uint32_t>(index) * 4u;
  for (int i = 0; i < 12; ++i) {
    auto it = xf_.find(base + i);
    if (it == xf_.end() || it->second.empty()) return;
    out[i] = BitsToFloat(it->second[0]);
  }
}

}  // namespace sfa
