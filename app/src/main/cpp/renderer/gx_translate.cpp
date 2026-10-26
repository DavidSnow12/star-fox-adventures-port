#include "renderer/gx_translate.h"

#include "gamecube_runtime/gx_texture.h"

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
// (342,342); salida NDC (y arriba).
bool TransformVertex(const GxDraw& draw, const GxVertex& v, int canvas_w,
                     int canvas_h, float* ndc_x, float* ndc_y) {
  const float kEfbX0 = 342.0f;
  const float kEfbY0 = 342.0f;
  float mx = draw.pos_matrix[0] * v.x + draw.pos_matrix[1] * v.y +
             draw.pos_matrix[2] * v.z + draw.pos_matrix[3];
  float my = draw.pos_matrix[4] * v.x + draw.pos_matrix[5] * v.y +
             draw.pos_matrix[6] * v.z + draw.pos_matrix[7];
  float mz = draw.pos_matrix[8] * v.x + draw.pos_matrix[9] * v.y +
             draw.pos_matrix[10] * v.z + draw.pos_matrix[11];
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
  for (size_t i = 0; i < draw.verts.size(); ++i) {
    TransformVertex(draw, draw.verts[i], canvas_w, canvas_h, &nx[i],
                    &ny[i]);
  }
  auto push_tri = [&](size_t a, size_t b, size_t c) {
    GlTri tri;
    const size_t idx[3] = {a, b, c};
    for (int k = 0; k < 3; ++k) {
      tri.x[k] = nx[idx[k]];
      tri.y[k] = ny[idx[k]];
      tri.s[k] = draw.verts[idx[k]].s;
      tri.t[k] = draw.verts[idx[k]].t;
    }
    tri.tex_obj = draw.tex_obj;
    tri.tex_map = draw.tex_map;
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
