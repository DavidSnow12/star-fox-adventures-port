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

bool GxDrawToGlQuads(const GxDraw& draw, int canvas_w, int canvas_h,
                     GlQuad* out) {
  if (out == nullptr) return false;
  if (draw.prim != 0x80 || draw.verts.size() != 4) return false;
  if (!draw.has_viewport || !draw.has_projection) return false;
  const float kEfbX0 = 342.0f;
  const float kEfbY0 = 342.0f;
  for (int i = 0; i < 4; ++i) {
    const GxVertex& v = draw.verts[i];
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
    out->x[i] = 2.0f * xs / static_cast<float>(canvas_w) - 1.0f;
    out->y[i] = 1.0f - 2.0f * ys / static_cast<float>(canvas_h);
    out->s[i] = v.s;
    out->t[i] = v.t;
  }
  out->tex_obj = draw.tex_obj;
  out->tex_map = draw.tex_map;
  return true;
}

}  // namespace sfa
