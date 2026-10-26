#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

// Copia EFB de pixeles, Tramo 9 frente B (Star Fox Adventures, port
// Android, rama android-port-base). Parte PURA (sin GL, sin RAM del
// runtime): testeable en host. El llamador GL (gx_gl.cpp, parche
// Tramo 9) aporta el readback RGBA8 del target EFB y el puntero a
// la RAM huesped; este fichero decide formato, convierte y escribe.
//
// Estado de decodificacion (ver INFORME Tramo 9, seccion 1):
//  - Filtro 0x53/0x54: DECODIFICADO EXACTO. GXSetCopyFilter
//    0x80259A64 empaqueta vfilter[7] como: BP53 = v0 | v1<<6 |
//    v2<<12 | v3<<18 (cada uno 6 bits: los bits 6-7 de v0-v5 se
//    pierden en las mascaras); BP54 = v4 | v5<<6 | v6<<12 (v6
//    con 8 bits: sus bits 6-7 SI sobreviven al OR final).
//    Traza: [7,7,12,12,12,7,7], suma 64. Defecto (vfilter nulo):
//    BP53=0x595000, BP54=0x000015 -> [0,0,21,22,21,0,0], suma 64.
//    La suma 64 en AMBOS casos confirma el empaquetado (un
//    desplazamiento de campo distinto no daria 64 en los dos).
//  - Bit 14 de 0x52: CORRECCION Tramo 9 (ver DIFF.md). NO es un
//    "execute gate": GXCopyDisp 0x80259CA8 fuerza bit 14
//    (ori 0x4000) y GXCopyTex 0x80259E18 NO lo pone (su palabra
//    final es la sombra 0x1fc sin bit 14). YAGCD: bit 14
//    "execute ? (1: to XFB 0: to texture ?!)". Conclusion:
//    TODA escritura 0x52 ejecuta una copia; bit 14 = clase de
//    destino (1 = display/XFB, 0 = textura). La lectura Tramo
//    7/8 ("sin exec = control, no copia") queda REFUTADA por
//    el desensamblado de GXCopyTex: las 782 copias "sin exec"
//    del censo son copias reales a textura.
//  - Bit 11: clear (argumento clear de GXCopyDisp/GXCopyTex:
//    (clear<<11) en ambas funciones). Bit 10 (display): flag
//    de escala Y (GXSetDispCopyYScale 0x80259928: bit 10 =
//    (256 - yscale_int) > 0). Bits 12-13: Frame2Field
//    (GXSetDispCopyFrame2Field 0x80259880). Bits 0-1: clamp
//    (GXSetCopyClamp 0x802598AC). Bits 7-8: gamma segun YAGCD,
//    sin escritor localizado en el DOL y siempre 0 en trazas:
//    se reportan crudos, no se interpretan.
//  - Formato de copia a textura (bits 3-6 de low52, ver
//    GXSetTexCopyDst 0x80259710): bit3 = fmt bit 3; bit4 =
//    fmt bit 0 (O con el bit 4 viejo de la sombra: la sombra
//    0x1fc persiste entre llamadas y el bit 4 nunca se limpia
//    a 0 por GXSetTexCopyDst, solo se pone a 1; en trazas el
//    bit 4 viejo es 0 siempre que se ha podido comprobar);
//    bit5 = fmt bit 1; bit6 = fmt bit 2. Es decir, fmt_low =
//    bit3<<3 | bit6<<2 | bit5<<1 | bit4. Bit 9 = mipmap.
//    Bit 16: marcador de textura (1 en las 782 copias a
//    textura, 0 en las 25.451 a XFB), con origen SIN
//    LOCALIZAR: descartados GXSetTexCopyDst path A (su
//    escritura de bits 15-16 queda anulada por la reescritura
//    de la sombra en 0x802597D8, que conserva todos los bits
//    salvo el 3), GXCopyTex arg2 (los callers del DOL pasan
//    solo 0/1 = clear) y GXSetCopyClamp (solo bits 0-1);
//    el escaneo de escrituras a 0x1fc en todo el DOL solo
//    encuentra texdst/copyclamp/copytex. El puerto NO
//    necesita el origen: lee palabras FIFO, no las construye.
//    Ademas: path A de texdst (fmt en {0,1,2,3,38}) pone
//    bits 15-16 a 1; las palabras de traza tienen bit15=0 y
//    bit16=1, luego NINGUNA copia de traza paso por path A
//    (nada limpia bit15): todos los fmt de traza son path B
//    (>= 4). Por eso el 0x0210 NO es fmt 1 (I8): es fmt 0x11,
//    UNICO compatible (0x21/0x31 tienen bloques (0,0) en la
//    tabla del helper 0x8025abb8 y darian stride 10240, no
//    1280; 0x01 es path A). fmt 0x11 tiene bloques 8x4
//    (tabla: shifts (3,2)) y su caller (0x8006ca7c) pasa
//    dst 320x240 mipmap 1 con src 640x480: caso src != dst,
//    rechazado por PlanTexCopy. Su semantica de pixel sigue
//    sin confirmar y no se convierte.
//  - XFB: low52 = 0x0C00 siempre (bits 10,11: escala Y activa
//    + clear). 2 BPP seguro (stride 1280 = 640 x 2). Bit 4
//    (YAGCD: formato del target XFB) siempre 0 en trazas. La
//    conversion YUY2-vs-RGB565 NO se puede decidir desde BP:
//    el puerto asume YUY2 para display (formato VI estandar
//    de GameCube; el conversor RGB565 existe y es el cambio
//    de una constante si una captura futura lo desmiente).
//    Bit4 = 1 no se ha observado nunca: se rechaza, no se
//    adivina.
//  - Copias a textura: destino EN TILES GX (no lineal). El
//    stride de traza para textura es bytes por fila de tiles
//    DEL DESTINO (no del origen): dst_w =
//    (stride_bytes / tile_bytes) * tile_w. PROBADO con los
//    callers del DOL y el censo run39 (dump_copies): 32x32
//    RGBA8 stride 512 (8 tiles x 64 B), 80x60 RGB565 stride
//    640 (20 x 32 B). Y DESCUBRIMIENTO Tramo 9: el juego
//    copia a veces con src != dst (caller 0x8006ca44:
//    src 640x480 -> dst 320x240 RGB565 mipmap; caller
//    0x8006ca7c: src 640x480 -> dst 320x240 fmt 0x11
//    mipmap): esos casos (0x010240, 0x010210 en run39) se
//    RECHAZAN por mismatch src/dst (regla de remuestreo
//    del HW no probada), no se escriben como 1:1. Solo
//    RGB565 (4) y RGBA8 (6) con dst_w == src_w se codifican
//    (inversos exactos de GxDecodeTexture); el resto
//    (incluido fmt 0x11, geometria 8x4 probada por la tabla
//    de bloques del helper 0x8025abb8, pero semantica de
//    pixel sin confirmar) se rechaza.
//  - Filtro vertical + escala Y: MODELO, no HW probado (ver
//    ApplyVerticalCopyFilter). El camino 1:1 NO aplica filtro:
//    con filas constantes el filtro es identidad (suma 64),
//    pero con filas variables un filtro aplicado sin escala
//    emborronaria sin evidencia de que el HW lo haga; no
//    aplicar es la opcion exacta-conservadora. El camino con
//    escala usa el modelo y se marca como tal en su nombre.

#include <cstdint>
#include <cstring>
#include <vector>

#include "gamecube_runtime/gx.h"
#include "gamecube_runtime/gx_texture.h"

namespace sfa {

// --- Filtro de copia (BP 0x53/0x54) ---

// Decodifica los 7 coeficientes del filtro vertical de copia.
// taps[0..3] = campos de 6 bits de filter53; taps[4..5] = campos
// de 6 bits de filter54; taps[6] = (filter54 >> 12) & 0xFF (8 bits
// segun el empaquetado del SDK; en traza y defecto vale <= 22,
// asi que la ambiguedad 6-vs-8 bits no afecta a ningun caso
// observado). Devuelve false solo con puntero nulo.
inline bool DecodeCopyFilter(uint32_t filter53, uint32_t filter54,
                             int taps[7]) {
  if (taps == nullptr) return false;
  taps[0] = static_cast<int>(filter53 & 0x3Fu);
  taps[1] = static_cast<int>((filter53 >> 6) & 0x3Fu);
  taps[2] = static_cast<int>((filter53 >> 12) & 0x3Fu);
  taps[3] = static_cast<int>((filter53 >> 18) & 0x3Fu);
  taps[4] = static_cast<int>(filter54 & 0x3Fu);
  taps[5] = static_cast<int>((filter54 >> 6) & 0x3Fu);
  taps[6] = static_cast<int>((filter54 >> 12) & 0xFFu);
  return true;
}

inline int CopyFilterSum(const int taps[7]) {
  int s = 0;
  for (int i = 0; i < 7; ++i) s += taps[i];
  return s;
}

// --- Formato de copia (low52 + bit 14/16) ---

enum class EfbPixelKind {
  kUnknown = 0,
  kXfbLinear2Bpp,  // Display: lineal, stride, 2 BPP (YUY2 asumido).
  kTexRgb565Tiled,  // Textura RGB565 (fmt_low 4): tiles 4x4, 32 B.
  kTexRgba8Tiled,  // Textura RGBA8 (fmt_low 6): tiles 4x4, 64 B.
};

struct EfbCopyFormat {
  bool is_disp = false;  // Bit 14: 1 = display/XFB, 0 = textura.
  bool clear = false;  // Bit 11.
  bool yscale_flag = false;  // Bit 10 (display): escala Y activa.
  int field_mode = 0;  // Bits 12-13 (Frame2Field).
  int gamma_raw = 0;  // Bits 7-8 (YAGCD; sin interpretar).
  bool clamp_top = false;  // Bit 0.
  bool clamp_bottom = false;  // Bit 1.
  bool bit16_marker = false;  // Bit 16: 1 en textura, 0 en XFB.
  int tex_fmt_low = -1;  // Textura: nibble permutado (bits 3-6).
  bool tex_mipmap = false;  // Textura: bit 9.
  bool xfb_fmt_bit4 = false;  // Display: bit 4 (YAGCD: formato XFB).
  EfbPixelKind kind = EfbPixelKind::kUnknown;
  int bytes_per_pixel = 0;  // Solo para kXfbLinear2Bpp (2).
  int tile_bytes = 0;  // Solo para kinds tiled (32 / 64).
  int tile_w = 0, tile_h = 0;  // Solo para kinds tiled (4x4).
};

// Decodifica el formato de una copia ya decodificada por
// DecodeEfbCopy. No toca RAM ni GL. El tipo devuelto dice si el
// puerto sabe convertir los pixeles (kind != kUnknown) o si debe
// rechazar la copia sin escribir bytes inventados.
inline EfbCopyFormat DecodeCopyFormat(const EfbCopyDecoded& d) {
  EfbCopyFormat f;
  f.is_disp = d.is_disp;
  f.clear = (d.low52 & 0x0800u) != 0;
  f.yscale_flag = (d.low52 & 0x0400u) != 0;
  f.field_mode = static_cast<int>((d.low52 >> 12) & 0x3u);
  f.gamma_raw = static_cast<int>((d.low52 >> 7) & 0x3u);
  f.clamp_top = (d.low52 & 0x1u) != 0;
  f.clamp_bottom = (d.low52 & 0x2u) != 0;
  f.bit16_marker = d.bit16_marker;
  if (d.is_disp) {
    f.xfb_fmt_bit4 = (d.low52 & 0x10u) != 0;
    // Display observado: bit4 siempre 0. Solo ese caso se
    // convierte (YUY2 asumido, 2 BPP lineal).
    if (!f.xfb_fmt_bit4) {
      f.kind = EfbPixelKind::kXfbLinear2Bpp;
      f.bytes_per_pixel = 2;
    }
  } else {
    int b3 = static_cast<int>((d.low52 >> 3) & 0x1u);
    int b4 = static_cast<int>((d.low52 >> 4) & 0x1u);
    int b5 = static_cast<int>((d.low52 >> 5) & 0x1u);
    int b6 = static_cast<int>((d.low52 >> 6) & 0x1u);
    f.tex_fmt_low = (b3 << 3) | (b6 << 2) | (b5 << 1) | b4;
    f.tex_mipmap = (d.low52 & 0x0200u) != 0;
    if (f.tex_fmt_low == 4) {
      f.kind = EfbPixelKind::kTexRgb565Tiled;
      f.tile_bytes = 32;
      f.tile_w = 4;
      f.tile_h = 4;
    } else if (f.tex_fmt_low == 6) {
      f.kind = EfbPixelKind::kTexRgba8Tiled;
      f.tile_bytes = 64;
      f.tile_w = 4;
      f.tile_h = 4;
    }
  }
  return f;
}

// --- Conversion de pixeles (desde readback RGBA8 de GL) ---

inline uint8_t ClampU8(int v) {
  if (v < 0) return 0;
  if (v > 255) return 255;
  return static_cast<uint8_t>(v);
}

// Una fila RGBA8 -> RGB565 big-endian (byte alto primero, como
// el u16 BE del decodificador GX). Exacta salvo el cuantizado
// 5/6 bits, que es la perdida propia del formato.
inline void Rgba8RowToRgb565Be(const uint8_t* rgba, int width,
                               uint8_t* out) {
  for (int x = 0; x < width; ++x) {
    uint8_t r = rgba[x * 4], g = rgba[x * 4 + 1], b = rgba[x * 4 + 2];
    uint16_t v = static_cast<uint16_t>(((r >> 3) << 11) |
                                       ((g >> 2) << 5) | (b >> 3));
    out[x * 2] = static_cast<uint8_t>(v >> 8);
    out[x * 2 + 1] = static_cast<uint8_t>(v & 0xFFu);
  }
}

// Una fila RGBA8 -> YUY2 (macropixel Y0 U Y1 V, BT.601 rango
// limitado, aritmetica entera). Requiere ancho par; con ancho
// impar devuelve false sin escribir nada. Los coeficientes son
// los estandar BT.601; el redondeo exacto del HW no esta
// verificado y se documenta como tal (ver INFORME).
inline bool Rgba8RowToYuy2(const uint8_t* rgba, int width,
                           uint8_t* out) {
  if (rgba == nullptr || out == nullptr || width <= 0 ||
      (width & 1) != 0)
    return false;
  for (int x = 0; x < width; x += 2) {
    uint8_t r0 = rgba[x * 4], g0 = rgba[x * 4 + 1], b0 = rgba[x * 4 + 2];
    uint8_t r1 = rgba[(x + 1) * 4], g1 = rgba[(x + 1) * 4 + 1],
            b1 = rgba[(x + 1) * 4 + 2];
    // BT.601 limited-range (Y: 16..235, U/V: 16..240): los
    // coeficientes de rango completo (77/150/29) daban
    // blanco Y=271 (clamp 255), no 235; corregido Tramo 9
    // (blanco -> Y=235, negro -> Y=16, verificados).
    int y0 = ((66 * r0 + 129 * g0 + 25 * b0 + 128) >> 8) + 16;
    int y1 = ((66 * r1 + 129 * g1 + 25 * b1 + 128) >> 8) + 16;
    // U/V del par: media de los dos pixeles (el HW YUY2
    // comparte un croma por par; la media es la opcion
    // neutra documentada, no una medida del HW).
    int rm = (r0 + r1) / 2, gm = (g0 + g1) / 2, bm = (b0 + b1) / 2;
    int u = ((-38 * rm - 74 * gm + 112 * bm + 128) >> 8) + 128;
    int v = ((112 * rm - 94 * gm - 18 * bm + 128) >> 8) + 128;
    out[x * 2] = ClampU8(y0);
    out[x * 2 + 1] = ClampU8(u);
    out[x * 2 + 2] = ClampU8(y1);
    out[x * 2 + 3] = ClampU8(v);
  }
  return true;
}

// RGBA8 lineal -> destino GX en tiles (inverso exacto de
// GxDecodeTexture para RGB565 y RGBA8). `rgba` es w*h*4 en
// orden de filas; `out` debe tener tiles_x*tiles_y*tile_bytes
// bytes (ver PlanTexCopy). Pixeles fuera de w/h en el borde
// del ultimo tile se rellenan con (0,0,0,0): el decodificador
// los ignora via Put(), asi que el round-trip es exacto dentro
// de w/h. Devuelve false con formato no soportado o punteros
// nulos (sin escribir nada en ese caso).
inline bool Rgba8ToGxTiled(const uint8_t* rgba, int width, int height,
                           int gx_format, uint8_t* out) {
  if (rgba == nullptr || out == nullptr || width <= 0 || height <= 0)
    return false;
  int tw = 0, th = 0, tb = 0;
  if (gx_format == 4) {
    tw = 4;
    th = 4;
    tb = 32;
  } else if (gx_format == 6) {
    tw = 4;
    th = 4;
    tb = 64;
  } else {
    return false;
  }
  int tiles_x = (width + tw - 1) / tw;
  int tiles_y = (height + th - 1) / th;
  std::memset(out, 0,
              static_cast<size_t>(tiles_x) * tiles_y * tb);
  int tile_index = 0;
  for (int ty = 0; ty < tiles_y; ++ty) {
    for (int tx = 0; tx < tiles_x; ++tx) {
      uint8_t* tile = out + static_cast<size_t>(tile_index++) * tb;
      for (int row = 0; row < th; ++row) {
        for (int col = 0; col < tw; ++col) {
          int x = tx * tw + col, y = ty * th + row;
          uint8_t r = 0, g = 0, b = 0, a = 0;
          if (x < width && y < height) {
            const uint8_t* p = rgba + (static_cast<size_t>(y) * width + x) * 4;
            r = p[0];
            g = p[1];
            b = p[2];
            a = p[3];
          }
          if (gx_format == 4) {
            uint16_t v = static_cast<uint16_t>(
                ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
            int k = (row * tw + col) * 2;
            tile[k] = static_cast<uint8_t>(v >> 8);
            tile[k + 1] = static_cast<uint8_t>(v & 0xFFu);
          } else {
            int k = row * tw + col;
            tile[k * 2] = a;
            tile[k * 2 + 1] = r;
            tile[32 + k * 2] = g;
            tile[32 + k * 2 + 1] = b;
          }
        }
      }
    }
  }
  return true;
}

// --- Planes de copia ---

// Plan lineal (display/XFB): reutiliza PlanEfbCopy Tramo 8 con
// el bpp del formato decodificado. Sin cambios de semantica:
// sin destino/tamano/stride, fuera de MEM1, stride < fila o
// copia que excede la RAM -> false.
inline bool PlanEfbCopyLinear(const EfbCopyDecoded& d,
                              const EfbCopyFormat& f, uint32_t ram_size,
                              EfbCopyPlan* plan) {
  if (f.kind != EfbPixelKind::kXfbLinear2Bpp) return false;
  return PlanEfbCopy(d, ram_size, f.bytes_per_pixel, plan);
}

// Plan en tiles (textura RGB565/RGBA8): el stride de traza
// es bytes por fila de tiles DEL DESTINO. De el se deriva
// dst_w = (stride_bytes / tile_bytes) * tile_w, que DEBE
// coincidir con el ancho del evento (src): si no coincide,
// es un caso src != dst (640x480 -> 320x240, probado en
// callers) cuya regla de remuestreo no esta probada, y el
// plan se rechaza (no se escribe un 1:1 falso). La altura
// del destino no viene en el evento: se toma la del evento
// (en todos los casos con ancho coincidente de los callers,
// dst_h == src_h; un caso con ancho coincidente y altura
// distinta no se ha observado). Sin stride, el plan se
// rechaza (sin stride no hay dst_w que validar).
inline bool PlanTexCopy(const EfbCopyDecoded& d,
                        const EfbCopyFormat& f, uint32_t ram_size,
                        EfbCopyPlan* plan) {
  if (plan == nullptr) return false;
  if (f.kind != EfbPixelKind::kTexRgb565Tiled &&
      f.kind != EfbPixelKind::kTexRgba8Tiled)
    return false;
  if (!d.has_dest || !d.has_size || !d.has_stride) return false;
  if (d.dest_guest < 0x80000000u || d.dest_guest >= 0x81800000u)
    return false;
  if (d.width <= 0 || d.height <= 0) return false;
  if (d.stride_bytes <= 0 ||
      (d.stride_bytes % f.tile_bytes) != 0)
    return false;
  int dst_tiles_x = d.stride_bytes / f.tile_bytes;
  int dst_w = dst_tiles_x * f.tile_w;
  if (dst_w != d.width) return false;  // Caso src != dst.
  int tiles_y = (d.height + f.tile_h - 1) / f.tile_h;
  uint32_t off = d.dest_guest - 0x80000000u;
  uint64_t total = static_cast<uint64_t>(d.stride_bytes) *
                   static_cast<uint64_t>(tiles_y);
  if (off + total > ram_size) return false;
  plan->dest_offset = off;
  plan->row_bytes = d.stride_bytes;
  plan->total_bytes = static_cast<int>(total);
  return true;
}

// --- Ejecucion (escribe en RAM huesped; no toca GL) ---
//
// `readback` es el rectangulo EFB leido por glReadPixels en
// RGBA8 (readback_w x readback_h, 4 BPP, filas sin padding).
// `ram` es la RAM huesped completa (ram_size bytes, base
// 0x80000000). El rectangulo de copia (src_x, src_y, width,
// height) debe caber en el readback; en trazas src = (0,0)
// siempre, pero el desplazamiento se soporta (no se asume).
// Devuelve false sin escribir NADA si cualquier validacion
// falla (incluido formato desconocido o copia con escala: ver
// ExecuteEfbCopyScaledModel). El orden de escritura es por
// filas de destino con pitch = stride (lineal) o por tiles
// (textura): en ambos casos el padding del destino queda
// intacto (CopyEfbRows / escritura por tiles no lo toca).

inline bool ExecuteEfbCopyLinear(const EfbCopyDecoded& d,
                                 const EfbCopyFormat& f,
                                 const uint8_t* readback, int readback_w,
                                 int readback_h, uint8_t* ram,
                                 uint32_t ram_size) {
  if (readback == nullptr || ram == nullptr) return false;
  if (f.kind != EfbPixelKind::kXfbLinear2Bpp) return false;
  // Escala Y: el camino 1:1 solo acepta sin escala (bit10 = 0)
  // o yscale_int = 256 con 0x4E capturado. Cualquier otro caso
  // es camino con escala (modelo aparte), no un 1:1.
  if (f.yscale_flag) {
    if (!d.has_yscale || d.yscale_int != 256) return false;
  }
  EfbCopyPlan plan;
  if (!PlanEfbCopyLinear(d, f, ram_size, &plan)) return false;
  if (!d.has_src) return false;
  if (d.src_x < 0 || d.src_y < 0 ||
      d.src_x + d.width > readback_w ||
      d.src_y + d.height > readback_h)
    return false;
  if ((d.width & 1) != 0) return false;  // YUY2 necesita pares.
  std::vector<uint8_t> conv(
      static_cast<size_t>(plan.row_bytes) * d.height);
  for (int y = 0; y < d.height; ++y) {
    const uint8_t* row =
        readback + (static_cast<size_t>(d.src_y + y) * readback_w +
                    d.src_x) *
                       4;
    uint8_t* dst = conv.data() + static_cast<size_t>(y) * plan.row_bytes;
    if (!Rgba8RowToYuy2(row, d.width, dst)) return false;
  }
  return CopyEfbRows(conv.data(), plan.row_bytes,
                     ram + plan.dest_offset, d.stride_bytes,
                     plan.row_bytes, d.height);
}

inline bool ExecuteEfbCopyTiled(const EfbCopyDecoded& d,
                                const EfbCopyFormat& f,
                                const uint8_t* readback, int readback_w,
                                int readback_h, uint8_t* ram,
                                uint32_t ram_size) {
  if (readback == nullptr || ram == nullptr) return false;
  if (f.kind != EfbPixelKind::kTexRgb565Tiled &&
      f.kind != EfbPixelKind::kTexRgba8Tiled)
    return false;
  EfbCopyPlan plan;
  if (!PlanTexCopy(d, f, ram_size, &plan)) return false;
  if (!d.has_src) return false;
  if (d.src_x < 0 || d.src_y < 0 ||
      d.src_x + d.width > readback_w ||
      d.src_y + d.height > readback_h)
    return false;
  // Extrae el rectangulo a un buffer lineal RGBA8 y lo codifica
  // en tiles; la escritura final es un unico bloque contiguo
  // (las texturas GX son contiguas en tiles, sin pitch).
  std::vector<uint8_t> rect(
      static_cast<size_t>(d.width) * d.height * 4);
  for (int y = 0; y < d.height; ++y) {
    const uint8_t* row =
        readback + (static_cast<size_t>(d.src_y + y) * readback_w +
                    d.src_x) *
                       4;
    std::memcpy(rect.data() + static_cast<size_t>(y) * d.width * 4,
                row, static_cast<size_t>(d.width) * 4);
  }
  std::vector<uint8_t> tiled(plan.total_bytes);
  int gx_fmt = (f.kind == EfbPixelKind::kTexRgb565Tiled) ? 4 : 6;
  if (!Rgba8ToGxTiled(rect.data(), d.width, d.height, gx_fmt,
                      tiled.data()))
    return false;
  std::memcpy(ram + plan.dest_offset, tiled.data(), tiled.size());
  return true;
}

// --- Filtro vertical + escala Y (MODELO, no HW probado) ---
//
// El HW aplica el filtro de copia (7 taps, suma 64) al
// remuestrear verticalmente con yscale. La alineacion exacta
// (centro de la ventana, redondeo, bordes) NO esta en el DOL:
// este modelo usa centro (y+0.5)*ratio - 0.5 con ratio =
// 256/yscale_int, ventana de 7 taps centrada (k-3) y clamp de
// bordes, con redondeo (+32)>>6. Es autoconsistente (filas
// constantes -> identidad exacta) y host-testeable, pero se
// marca MODELO en su nombre y en el informe: no se presenta
// como comportamiento medido del HW. Solo para display.
inline bool ApplyVerticalCopyFilterModel(const uint8_t* src_rows,
                                         int src_h, int src_pitch,
                                         const int taps[7],
                                         int yscale_int, int dst_h,
                                         uint8_t* dst_rows,
                                         int dst_pitch) {
  if (src_rows == nullptr || dst_rows == nullptr || taps == nullptr)
    return false;
  if (src_h <= 0 || dst_h <= 0 || yscale_int <= 0 ||
      src_pitch <= 0 || dst_pitch <= 0)
    return false;
  double ratio = 256.0 / static_cast<double>(yscale_int);
  for (int y = 0; y < dst_h; ++y) {
    double center = (static_cast<double>(y) + 0.5) * ratio - 0.5;
    int base = static_cast<int>(center + 0.5);  // redondeo al entero
    for (int x = 0; x < src_pitch; ++x) {
      int acc = 0;
      for (int k = 0; k < 7; ++k) {
        int sy = base + (k - 3);
        if (sy < 0) sy = 0;
        if (sy >= src_h) sy = src_h - 1;
        acc += taps[k] * src_rows[static_cast<size_t>(sy) * src_pitch + x];
      }
      dst_rows[static_cast<size_t>(y) * dst_pitch + x] =
          static_cast<uint8_t>((acc + 32) >> 6);
    }
  }
  return true;
}

// Copia display con escala Y + filtro (MODELO). `readback`
// debe contener las filas EFB de entrada (src_h = filas
// disponibles; el numero de filas de salida es height del
// evento). Requisitos: formato display 2 BPP, yscale_flag con
// yscale_int capturado (0x4E) y distinto de 256, destino
// lineal valido. La conversion a YUY2 se aplica DESPUES del
// filtrado (el filtro opera en RGBA8, como modelo).
inline bool ExecuteEfbCopyScaledModel(const EfbCopyDecoded& d,
                                      const EfbCopyFormat& f,
                                      const uint8_t* readback,
                                      int readback_w, int readback_h,
                                      const int taps[7], uint8_t* ram,
                                      uint32_t ram_size) {
  if (readback == nullptr || ram == nullptr || taps == nullptr)
    return false;
  if (f.kind != EfbPixelKind::kXfbLinear2Bpp) return false;
  if (!f.yscale_flag || !d.has_yscale || d.yscale_int == 256)
    return false;
  EfbCopyPlan plan;
  if (!PlanEfbCopyLinear(d, f, ram_size, &plan)) return false;
  if (!d.has_src) return false;
  // Filas de entrada necesarias: la ventana del modelo llega
  // hasta round((height-0.5)*ratio - 0.5) + 3. Si el readback
  // no las cubre, se rechaza (no se inventan filas).
  double ratio = 256.0 / static_cast<double>(d.yscale_int);
  int need = static_cast<int>((d.height - 0.5) * ratio - 0.5 + 0.5) + 3 + 1;
  if (d.src_y + need > readback_h) return false;
  if (d.src_x + d.width > readback_w) return false;
  if ((d.width & 1) != 0) return false;
  std::vector<uint8_t> filtered(
      static_cast<size_t>(d.height) * readback_w * 4);
  // Filtra por columnas de bytes RGBA (src_pitch = ancho*4);
  // el rectangulo src_x se recorta despues, por filas.
  std::vector<uint8_t> src_block(
      static_cast<size_t>(need) * readback_w * 4);
  for (int y = 0; y < need; ++y) {
    std::memcpy(src_block.data() + static_cast<size_t>(y) * readback_w * 4,
                readback + static_cast<size_t>(d.src_y + y) * readback_w * 4,
                static_cast<size_t>(readback_w) * 4);
  }
  if (!ApplyVerticalCopyFilterModel(src_block.data(), need,
                                    readback_w * 4, taps, d.yscale_int,
                                    d.height, filtered.data(),
                                    readback_w * 4))
    return false;
  std::vector<uint8_t> conv(
      static_cast<size_t>(plan.row_bytes) * d.height);
  for (int y = 0; y < d.height; ++y) {
    const uint8_t* row =
        filtered.data() + static_cast<size_t>(y) * readback_w * 4 +
        static_cast<size_t>(d.src_x) * 4;
    uint8_t* dst = conv.data() + static_cast<size_t>(y) * plan.row_bytes;
    if (!Rgba8RowToYuy2(row, d.width, dst)) return false;
  }
  return CopyEfbRows(conv.data(), plan.row_bytes,
                     ram + plan.dest_offset, d.stride_bytes,
                     plan.row_bytes, d.height);
}

}  // namespace sfa
