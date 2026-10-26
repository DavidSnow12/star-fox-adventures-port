#include "renderer/gx_translate.h"

#include <cmath>

#include "gamecube_runtime/gx_texture.h"
#include "renderer/gx_tev.h"

namespace sfa {

namespace {

uint32_t ReadBe32(const uint8_t* ram, size_t ram_size, uint32_t guest) {
  uint32_t off = guest - 0x80000000u;
  if (off + 4 > ram_size) return 0;
  return (static_cast<uint32_t>(ram[off]) << 24) |
         (static_cast<uint32_t>(ram[off + 1]) << 16) |
         (static_cast<uint32_t>(ram[off + 2]) << 8) |
         static_cast<uint32_t>(ram[off + 3]);
}

}  // namespace

bool DecodeGxTexObj(const uint8_t* ram, size_t ram_size, uint32_t tex_obj,
                    GxDecodedTex* out) {
  if (ram == nullptr || out == nullptr) return false;
  out->ok = false;
  uint32_t w8 = ReadBe32(ram, ram_size, tex_obj + 8);
  uint32_t w12 = ReadBe32(ram, ram_size, tex_obj + 12);
  uint32_t w36 = ReadBe32(ram, ram_size, tex_obj + 36);
  int w = static_cast<int>(w8 & 0x3FF) + 1;
  int h = static_cast<int>((w8 >> 10) & 0x3FF) + 1;
  int fmt = static_cast<int>((w8 >> 20) & 0xF);
  uint32_t img_guest = 0x80000000u | ((w12 << 5) & 0x01FFFFFFu);
  uint32_t img_off = img_guest - 0x80000000u;
  uint32_t base = 0;
  if (!GxTextureBaseSize(static_cast<uint32_t>(w), static_cast<uint32_t>(h),
                         fmt, &base)) {
    return false;
  }
  if (base != w36) return false;  // El juego debe coincidir.
  if (img_off + base > ram_size) return false;
  if (!GxDecodeTexture(ram + img_off, base, static_cast<uint32_t>(w),
                       static_cast<uint32_t>(h), fmt, &out->rgba)) {
    return false;
  }
  out->width = w;
  out->height = h;
  out->format = fmt;
  out->ok = true;
  return true;
}

namespace {

// Transformada por vertice (la misma de siempre): pos_matrix
// 3x4, proyeccion orto o perspectiva, viewport y region EFB
// (342,342); salida NDC (y arriba). Si mx_out/my_out/mz_out
// no son null, devuelven la posicion tras la matriz de
// posicion (antes de proyeccion): es la entrada POS del
// texgen (Tramo 6, pipeline GX: el texgen consume la
// posicion post-PNMTX, no el atributo crudo).
bool TransformVertex(const GxDraw& draw, const GxVertex& v, int canvas_w,
                     int canvas_h, float* ndc_x, float* ndc_y,
                     float* mx_out = nullptr, float* my_out = nullptr,
                     float* mz_out = nullptr) {
  const float kEfbX0 = 342.0f;
  const float kEfbY0 = 342.0f;
  float mx = draw.pos_matrix[0] * v.x + draw.pos_matrix[1] * v.y +
             draw.pos_matrix[2] * v.z + draw.pos_matrix[3];
  float my = draw.pos_matrix[4] * v.x + draw.pos_matrix[5] * v.y +
             draw.pos_matrix[6] * v.z + draw.pos_matrix[7];
  float mz = draw.pos_matrix[8] * v.x + draw.pos_matrix[9] * v.y +
             draw.pos_matrix[10] * v.z + draw.pos_matrix[11];
  if (mx_out != nullptr) *mx_out = mx;
  if (my_out != nullptr) *my_out = my;
  if (mz_out != nullptr) *mz_out = mz;
  float xc = 0.0f;
  float yc = 0.0f;
  if (draw.projection_type == 1) {
    xc = mx * draw.projection[0] + draw.projection[1];
    yc = my * draw.projection[2] + draw.projection[3];
  } else {
    float w = -mz;  // Perspectiva GX: camino NO validado en run19.
    if (w == 0.0f) w = 1.0f;
    xc = (mx * draw.projection[0] + mz * draw.projection[1]) / w;
    yc = (my * draw.projection[2] + mz * draw.projection[3]) / w;
  }
  float xs = xc * draw.viewport[0] + draw.viewport[3] - kEfbX0;
  float ys = yc * draw.viewport[1] + draw.viewport[4] - kEfbY0;
  *ndc_x = 2.0f * xs / static_cast<float>(canvas_w) - 1.0f;
  *ndc_y = 1.0f - 2.0f * ys / static_cast<float>(canvas_h);
  return true;
}

}  // namespace

bool ApplyTexMatrix(const float m[12], float s, float t, float* s_out,
                    float* t_out) {
  if (m == nullptr || s_out == nullptr || t_out == nullptr) return false;
  float sp = m[0] * s + m[1] * t + m[2];
  float tp = m[4] * s + m[5] * t + m[6];
  float wp = m[8] * s + m[9] * t + m[10];
  if ((m[8] != 0.0f || m[9] != 0.0f || m[10] != 0.0f) && wp != 0.0f) {
    sp /= wp;
    tp /= wp;
  }
  *s_out = sp;
  *t_out = tp;
  return true;
}

bool ApplyTexMatrixPos(const float m[12], float x, float y, float z,
                       float* s_out, float* t_out) {
  if (m == nullptr || s_out == nullptr || t_out == nullptr) return false;
  float sp = m[0] * x + m[1] * y + m[2] * z + m[3];
  float tp = m[4] * x + m[5] * y + m[6] * z + m[7];
  float wp = m[8] * x + m[9] * y + m[10] * z + m[11];
  if ((m[8] != 0.0f || m[9] != 0.0f || m[10] != 0.0f || m[11] != 0.0f) &&
      wp != 0.0f) {
    sp /= wp;
    tp /= wp;
  }
  *s_out = sp;
  *t_out = tp;
  return true;
}

namespace {

// UV final de un vertice para un mapa: UV directa con la
// matriz TnMIDX del vertice si el draw la trae (distinta de
// identidad); sin matriz o sin UV en el vertice: UV cruda
// (0,0 si el vertice no trae esa coord).
// Tramo 6 (texgen-POS): si el draw trae texgen XF para esta
// coord y es aplicable (fuente POS, forma 2x4/3x4, sin
// normalizar), la UV NO sale del atributo TEX del
// vertice sino de la posicion post-PNMTX (mx,my,mz)
// transformada por la matriz TnMIDX del vertice (60 o
// matriz ausente = identidad).
// Tramo 7B: se anaden NRM (fuente 1: normal transformada
// por la 3x3 de PNMTX, nnx/nny/nnz; exacta si PNMTX es
// rigida, ver gx_tev.h) y TEX0-7 (fuente 5-12: atributo
// UV de la coord fuente, o (0,0) si el vertice no la
// trae; matriz TnMIDX de ESTA coord). Tras la matriz
// principal, si el texgen tiene postmtx != 125 y la
// matriz post esta capturada en draw.post_matrices, se
// aplica en 2D con q=1 (s',t') = (P0*s+P1*t+P2+P3,
// P4*s+P5*t+P6+P7): exacto para forma 2x4 (todos los
// casos de trazas); para forma 3x4 la division por q'
// tras el post no se modela (sin caso en trazas).
// normalize != 0,
// BINRM/TANGENT/COLOR y post sin matriz capturada
// conservan el camino anterior (UV directa).
// El id de matriz del texgen no esta en XF (shadow GX), asi
// que la TnMIDX es la unica matriz visible en el stream;
// si el vertice no trae TnMIDX, la identidad es exacta
// para la sombra (mtx 60) y una aproximacion documentada
// para la caustica (mtx 30/33/36) cuando el vertice no la
// trae (ver informe Tramo 6).
void FinalUv(const GxDraw& draw, const GxVertex& v, int map, float mx,
             float my, float mz, float nnx, float nny, float nnz,
             float* s_out, float* t_out) {
  if (map >= 0 && map < 8 && draw.has_texgen[map]) {
    TexGen tg = DecodeTexGenWord1(draw.texgen_w1[map]);
    DecodeTexGenWord2(draw.texgen_w2[map], &tg);
    bool form_ok = (tg.type_form == 0 || tg.type_form == 2);
    bool pos_like = tg.present && tg.src == 0 && form_ok &&
                    tg.normalize == 0;
    bool nrm_like = tg.present && tg.src == 1 && form_ok &&
                    tg.normalize == 0;
    bool tex_like = TexGenTexApplicable(tg);
    if (pos_like || nrm_like || tex_like) {
      // Identidad segun forma: 2x4 no divide (fila 3 a
      // cero); 3x4 identidad divide por z (regla general).
      float ident[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
      if (tg.type_form == 2) ident[10] = 1;
      const float* m = ident;
      int idx = v.tex_mtx_idx_arr[map];
      if (idx != 60) {
        auto it = draw.tex_matrices.find(idx);
        if (it != draw.tex_matrices.end() && it->second.size() == 12)
          m = it->second.data();
      }
      float s = 0.0f, t = 0.0f;
      if (pos_like) {
        ApplyTexMatrixPos(m, mx, my, mz, &s, &t);
      } else if (nrm_like) {
        ApplyTexMatrixPos(m, nnx, nny, nnz, &s, &t);
      } else {
        int src_coord = tg.src - 5;
        float u = v.has_uv[src_coord] ? v.uv_s[src_coord] : 0.0f;
        float vv = v.has_uv[src_coord] ? v.uv_t[src_coord] : 0.0f;
        ApplyTexMatrix(m, u, vv, &s, &t);
      }
      // Matriz post (dual texture) si esta capturada:
      // entrada (s, t, q=1) para forma 2x4 (q implicito
      // homogeneo); para forma 3x4 la division por q'
      // tras el post no se modela (sin caso en trazas).
      if (TexGenPostApplicable(tg)) {
        auto pit = draw.post_matrices.find(tg.postmtx);
        if (pit != draw.post_matrices.end() &&
            pit->second.size() == 12) {
          const float* p = pit->second.data();
          float sp = p[0] * s + p[1] * t + p[2] + p[3];
          float tp = p[4] * s + p[5] * t + p[6] + p[7];
          s = sp;
          t = tp;
        }
      }
      *s_out = s;
      *t_out = t;
      return;
    }
  }
  float s = v.has_uv[map] ? v.uv_s[map] : 0.0f;
  float t = v.has_uv[map] ? v.uv_t[map] : 0.0f;
  if (v.has_uv[map]) {
    int idx = v.tex_mtx_idx_arr[map];
    if (idx != 60) {
      auto it = draw.tex_matrices.find(idx);
      if (it != draw.tex_matrices.end() && it->second.size() == 12) {
        ApplyTexMatrix(it->second.data(), s, t, &s, &t);
      }
    }
  }
  *s_out = s;
  *t_out = t;
}

}  // namespace

bool GxDrawToGlQuads(const GxDraw& draw, int canvas_w, int canvas_h,
                     GlQuad* out) {
  if (out == nullptr) return false;
  if (draw.prim != 0x80 || draw.verts.size() != 4) return false;
  if (!draw.has_viewport || !draw.has_projection) return false;
  for (int i = 0; i < 4; ++i) {
    const GxVertex& v = draw.verts[i];
    TransformVertex(draw, v, canvas_w, canvas_h, &out->x[i], &out->y[i]);
    out->s[i] = v.s;
    out->t[i] = v.t;
  }
  out->tex_obj = draw.tex_obj;
  out->tex_map = draw.tex_map;
  return true;
}

bool GxDrawToGlTris(const GxDraw& draw, int canvas_w, int canvas_h,
                    std::vector<GlTri>* out) {
  if (out == nullptr) return false;
  if (draw.has_raw_vertices || draw.indexed) return false;
  if (!draw.has_viewport || !draw.has_projection) return false;
  if (draw.verts.empty()) return false;
  // NDC por vertice, una sola vez.
  std::vector<float> nx(draw.verts.size());
  std::vector<float> ny(draw.verts.size());
  std::vector<float> pmx(draw.verts.size());
  std::vector<float> pmy(draw.verts.size());
  std::vector<float> pmz(draw.verts.size());
  // Tramo 7B: normal post-PNMTX (3x3, sin traslacion) y Z
  // de fog por vertice (perspectiva: sqrt(mx^2+mz^2);
  // orto: max(-mz, 0); ver gx_translate.h).
  std::vector<float> nmx(draw.verts.size(), 0.0f);
  std::vector<float> nmy(draw.verts.size(), 0.0f);
  std::vector<float> nmz(draw.verts.size(), 0.0f);
  std::vector<float> fogz(draw.verts.size(), 0.0f);
  for (size_t i = 0; i < draw.verts.size(); ++i) {
    TransformVertex(draw, draw.verts[i], canvas_w, canvas_h, &nx[i],
                    &ny[i], &pmx[i], &pmy[i], &pmz[i]);
    const GxVertex& v = draw.verts[i];
    if (v.has_normal) {
      nmx[i] = draw.pos_matrix[0] * v.nx + draw.pos_matrix[1] * v.ny +
               draw.pos_matrix[2] * v.nz;
      nmy[i] = draw.pos_matrix[4] * v.nx + draw.pos_matrix[5] * v.ny +
               draw.pos_matrix[6] * v.nz;
      nmz[i] = draw.pos_matrix[8] * v.nx + draw.pos_matrix[9] * v.ny +
               draw.pos_matrix[10] * v.nz;
    }
    if (draw.projection_type == 1) {
      fogz[i] = pmz[i] < 0.0f ? -pmz[i] : 0.0f;
    } else {
      fogz[i] = std::sqrt(pmx[i] * pmx[i] + pmz[i] * pmz[i]);
    }
  }
  auto push_tri = [&](size_t a, size_t b, size_t c) {
    GlTri tri;
    const size_t idx[3] = {a, b, c};
    for (int k = 0; k < 3; ++k) {
      const GxVertex& v = draw.verts[idx[k]];
      tri.x[k] = nx[idx[k]];
      tri.y[k] = ny[idx[k]];
      tri.fog_z[k] = fogz[idx[k]];
      tri.s[k] = v.s;
      tri.t[k] = v.t;
      // Color vertice (sin color: blanco opaco, como el parser).
      tri.cr0[k] = v.r / 255.0f;
      tri.cg0[k] = v.g / 255.0f;
      tri.cb0[k] = v.b / 255.0f;
      tri.ca0[k] = v.has_color ? v.a / 255.0f : 1.0f;
      tri.cr1[k] = v.r1 / 255.0f;
      tri.cg1[k] = v.g1 / 255.0f;
      tri.cb1[k] = v.b1 / 255.0f;
      tri.ca1[k] = v.has_color1 ? v.a1 / 255.0f : 1.0f;
      for (int m = 0; m < 8; ++m) {
        FinalUv(draw, v, m, pmx[idx[k]], pmy[idx[k]], pmz[idx[k]],
                nmx[idx[k]], nmy[idx[k]], nmz[idx[k]],
                &tri.uv_s[k][m], &tri.uv_t[k][m]);
      }
    }
    tri.tex_obj = draw.tex_obj;
    tri.tex_map = draw.tex_map;
    for (int m = 0; m < 8; ++m) tri.tex_objs[m] = draw.tex_objs[m];
    out->push_back(tri);
  };
  const size_t n = draw.verts.size();
  switch (draw.prim) {
    case 0x80:  // QUADS: grupos de 4 -> (0,1,2)(0,2,3).
      if (n % 4 != 0) return false;
      for (size_t i = 0; i + 3 < n; i += 4) {
        push_tri(i, i + 1, i + 2);
        push_tri(i, i + 2, i + 3);
      }
      break;
    case 0x90:  // TRIANGLES: grupos de 3.
      if (n % 3 != 0) return false;
      for (size_t i = 0; i + 2 < n; i += 3) push_tri(i, i + 1, i + 2);
      break;
    case 0x98:  // TRIANGLESTRIP (YAGCD 5.11.5.2.3).
      if (n < 3) return false;
      for (size_t i = 0; i + 2 < n; ++i) {
        if (i % 2 == 0) {
          push_tri(i, i + 1, i + 2);
        } else {
          push_tri(i, i + 2, i + 1);
        }
      }
      break;
    case 0xA0:  // TRIANGLEFAN.
      if (n < 3) return false;
      for (size_t i = 1; i + 1 < n; ++i) push_tri(0, i, i + 1);
      break;
    default:
      return false;  // LINES/LINESTRIP/POINTS: sin dibujo.
  }
  return !out->empty();
}

}  // namespace sfa
