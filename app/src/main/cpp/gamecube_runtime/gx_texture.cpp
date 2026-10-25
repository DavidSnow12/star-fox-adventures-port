// Ver gx_texture.h. Porte de decode_pure del extractor del repo.

#include "gamecube_runtime/gx_texture.h"

#include <cstring>

namespace sfa {

namespace {

uint8_t Expand5(uint32_t v) {
  return static_cast<uint8_t>((v << 3) | (v >> 2));
}
uint8_t Expand6(uint32_t v) {
  return static_cast<uint8_t>((v << 2) | (v >> 4));
}
uint8_t Expand4(uint32_t v) {
  return static_cast<uint8_t>((v << 4) | v);
}
uint8_t Expand3(uint32_t v) {
  return static_cast<uint8_t>((v << 5) | (v << 2) | (v >> 1));
}
uint16_t U16Be(const uint8_t* p) {
  return static_cast<uint16_t>((static_cast<uint16_t>(p[0]) << 8) |
                               static_cast<uint16_t>(p[1]));
}

// Tile (ancho, alto, bytes) por formato, del extractor.
bool TileInfo(int format, uint32_t* tw, uint32_t* th, uint32_t* tb) {
  switch (format) {
    case 0: *tw = 8; *th = 8; *tb = 32; return true;   // I4
    case 1: *tw = 8; *th = 4; *tb = 32; return true;   // I8
    case 2: *tw = 8; *th = 4; *tb = 32; return true;   // IA4
    case 3: *tw = 4; *th = 4; *tb = 32; return true;   // IA8
    case 4: *tw = 4; *th = 4; *tb = 32; return true;   // RGB565
    case 5: *tw = 4; *th = 4; *tb = 32; return true;   // RGB5A3
    case 6: *tw = 4; *th = 4; *tb = 64; return true;   // RGBA8
    case 14: *tw = 8; *th = 8; *tb = 32; return true;  // CMPR
    // (4 subbloques DXT1 de 8 B = 32 B por tile 8x8; el valor 64
    // fue un error de este porte, detectado al contrastar con
    // TILE del extractor y con el tamano base del juego.)
    default: return false;
  }
}

void Put(std::vector<uint8_t>& out, uint32_t width, uint32_t height,
         uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b,
         uint8_t a) {
  if (x >= width || y >= height) return;
  size_t off = (static_cast<size_t>(y) * width + x) * 4;
  out[off] = r;
  out[off + 1] = g;
  out[off + 2] = b;
  out[off + 3] = a;
}

void Rgb565(uint16_t v, uint8_t* r, uint8_t* g, uint8_t* b) {
  *r = Expand5((v >> 11) & 31);
  *g = Expand6((v >> 5) & 63);
  *b = Expand5(v & 31);
}

void Rgb5a3(uint16_t v, uint8_t* r, uint8_t* g, uint8_t* b, uint8_t* a) {
  if (v & 0x8000) {
    *r = Expand5((v >> 10) & 31);
    *g = Expand5((v >> 5) & 31);
    *b = Expand5(v & 31);
    *a = 255;
  } else {
    *a = Expand3((v >> 12) & 7);
    *r = Expand4((v >> 8) & 15);
    *g = Expand4((v >> 4) & 15);
    *b = Expand4(v & 15);
  }
}

}  // namespace

const char* GxFormatName(int format) {
  switch (format) {
    case 0: return "I4";
    case 1: return "I8";
    case 2: return "IA4";
    case 3: return "IA8";
    case 4: return "RGB565";
    case 5: return "RGB5A3";
    case 6: return "RGBA8";
    case 8: return "C4(paleta)";
    case 9: return "C8(paleta)";
    case 10: return "C14X2(paleta)";
    case 14: return "CMPR";
    default: return "?";
  }
}

bool GxTextureBaseSize(uint32_t width, uint32_t height, int format,
                       uint32_t* out_bytes) {
  uint32_t tw = 0, th = 0, tb = 0;
  if (!TileInfo(format, &tw, &th, &tb)) return false;
  uint32_t tiles_x = (width + tw - 1) / tw;
  uint32_t tiles_y = (height + th - 1) / th;
  if (out_bytes != nullptr) *out_bytes = tiles_x * tiles_y * tb;
  return true;
}

bool GxDecodeTexture(const uint8_t* data, uint32_t data_len,
                     uint32_t width, uint32_t height, int format,
                     std::vector<uint8_t>* rgba_out) {
  if (data == nullptr || rgba_out == nullptr) return false;
  uint32_t tw = 0, th = 0, tb = 0;
  if (!TileInfo(format, &tw, &th, &tb)) return false;
  uint32_t expected = 0;
  GxTextureBaseSize(width, height, format, &expected);
  if (data_len != expected) return false;
  rgba_out->assign(static_cast<size_t>(width) * height * 4, 0);
  std::vector<uint8_t>& out = *rgba_out;
  uint32_t tiles_x = (width + tw - 1) / tw;
  uint32_t tiles_y = (height + th - 1) / th;
  uint32_t tile_index = 0;
  for (uint32_t ty = 0; ty < tiles_y; ++ty) {
    for (uint32_t tx = 0; tx < tiles_x; ++tx) {
      const uint8_t* tile = data + static_cast<size_t>(tile_index++) * tb;
      if (format == 0) {  // I4: 8x8, 2 px/byte, nibble alto primero
        for (uint32_t row = 0; row < th; ++row) {
          for (uint32_t col = 0; col < tw / 2; ++col) {
            uint8_t byte = tile[row * (tw / 2) + col];
            uint8_t v = Expand4(byte >> 4);
            Put(out, width, height, tx * tw + col * 2, ty * th + row, v, v,
                v, 255);
            v = Expand4(byte & 15);
            Put(out, width, height, tx * tw + col * 2 + 1, ty * th + row, v,
                v, v, 255);
          }
        }
      } else if (format == 1) {  // I8: 8x4, 1 byte/px
        for (uint32_t row = 0; row < th; ++row) {
          for (uint32_t col = 0; col < tw; ++col) {
            uint8_t v = tile[row * tw + col];
            Put(out, width, height, tx * tw + col, ty * th + row, v, v, v,
                255);
          }
        }
      } else if (format == 2) {  // IA4: 8x4, (I alto, A bajo)
        for (uint32_t row = 0; row < th; ++row) {
          for (uint32_t col = 0; col < tw; ++col) {
            uint8_t byte = tile[row * tw + col];
            uint8_t v = Expand4(byte >> 4);
            uint8_t a = Expand4(byte & 15);
            Put(out, width, height, tx * tw + col, ty * th + row, v, v, v,
                a);
          }
        }
      } else if (format == 3 || format == 4 || format == 5) {
        // IA8 / RGB565 / RGB5A3: 4x4, u16 BE por pixel
        for (uint32_t row = 0; row < th; ++row) {
          for (uint32_t col = 0; col < tw; ++col) {
            uint32_t k = (row * tw + col) * 2;
            if (format == 3) {
              uint8_t i = tile[k];
              uint8_t a = tile[k + 1];
              Put(out, width, height, tx * tw + col, ty * th + row, i, i, i,
                  a);
            } else if (format == 4) {
              uint8_t r = 0, g = 0, b = 0;
              Rgb565(U16Be(tile + k), &r, &g, &b);
              Put(out, width, height, tx * tw + col, ty * th + row, r, g, b,
                  255);
            } else {
              uint8_t r = 0, g = 0, b = 0, a = 0;
              Rgb5a3(U16Be(tile + k), &r, &g, &b, &a);
              Put(out, width, height, tx * tw + col, ty * th + row, r, g, b,
                  a);
            }
          }
        }
      } else if (format == 6) {  // RGBA8: 4x4, plano AR + plano GB
        for (uint32_t row = 0; row < th; ++row) {
          for (uint32_t col = 0; col < tw; ++col) {
            uint32_t k = row * tw + col;
            uint8_t a = tile[k * 2];
            uint8_t r = tile[k * 2 + 1];
            uint8_t g = tile[32 + k * 2];
            uint8_t b = tile[32 + k * 2 + 1];
            Put(out, width, height, tx * tw + col, ty * th + row, r, g, b,
                a);
          }
        }
      } else if (format == 14) {  // CMPR: 8x8 = 4 subbloques DXT1
        for (uint32_t sy = 0; sy < 2; ++sy) {
          for (uint32_t sx = 0; sx < 2; ++sx) {
            const uint8_t* blk = tile + (sy * 2 + sx) * 8;
            uint16_t c0 = U16Be(blk);
            uint16_t c1 = U16Be(blk + 2);
            uint8_t col0[3], col1[3];
            Rgb565(c0, &col0[0], &col0[1], &col0[2]);
            Rgb565(c1, &col1[0], &col1[1], &col1[2]);
            uint8_t cols[4][3];
            uint8_t alphas[4];
            for (int ch = 0; ch < 3; ++ch) {
              cols[0][ch] = col0[ch];
              cols[1][ch] = col1[ch];
            }
            if (c0 > c1) {
              for (int ch = 0; ch < 3; ++ch) {
                cols[2][ch] = static_cast<uint8_t>(
                    (2 * col0[ch] + col1[ch]) / 3);
                cols[3][ch] = static_cast<uint8_t>(
                    (col0[ch] + 2 * col1[ch]) / 3);
              }
              alphas[0] = alphas[1] = alphas[2] = alphas[3] = 255;
            } else {
              for (int ch = 0; ch < 3; ++ch) {
                cols[2][ch] = static_cast<uint8_t>(
                    (col0[ch] + col1[ch]) / 2);
                cols[3][ch] = 0;
              }
              alphas[0] = alphas[1] = alphas[2] = 255;
              alphas[3] = 0;
            }
            for (uint32_t py = 0; py < 4; ++py) {
              uint8_t byte = blk[4 + py];
              for (uint32_t px = 0; px < 4; ++px) {
                // Primer pixel de la fila en los 2 bits altos
                // (no LSB-primero): decision verificada en el
                // extractor contra el corpus del disco.
                uint32_t idx = (byte >> ((3 - px) * 2)) & 3;
                Put(out, width, height, tx * tw + sx * 4 + px,
                    ty * th + sy * 4 + py, cols[idx][0], cols[idx][1],
                    cols[idx][2], alphas[idx]);
              }
            }
          }
        }
      }
    }
  }
  return true;
}

void GxPlaceholderTexture(uint32_t width, uint32_t height,
                          std::vector<uint8_t>* rgba_out) {
  if (rgba_out == nullptr) return;
  rgba_out->assign(static_cast<size_t>(width) * height * 4, 0);
  for (size_t i = 0; i + 3 < rgba_out->size(); i += 4) {
    (*rgba_out)[i] = 255;      // R
    (*rgba_out)[i + 1] = 0;    // G
    (*rgba_out)[i + 2] = 255;  // B
    (*rgba_out)[i + 3] = 255;  // A
  }
}

}  // namespace sfa
