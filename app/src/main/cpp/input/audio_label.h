#pragma once

// Etiqueta de texto de la pildora "anadir audio" — Tramo 7
// (via BITMAP EN GL, elegida; ver TRAMO7-INFORME.md §1).
//
// Por que bitmap y no overlay Java: NativeActivity no tiene UI
// Java y su ventana la posee el glue nativo. Un TextView sobre
// la superficie (WindowManager.addView / addContentView) exige
// z-order por encima de EGL, banderas de foco exactas
// (NOT_FOCUSABLE + NOT_TOUCH_MODAL) y retirada en TERM_WINDOW;
// si el foco se pierde, el bucle nativo deja de ejecutar frames
// (has_focus=false) y el juego se pausaria al tocar el boton, un
// modo de regresion que NINGUN test host puede detectar (exige
// dispositivo), y su geometria bypassa TouchLayout, asi que
// tampoco seria testeable en host. La via bitmap, en cambio, no
// toca ciclo de vida, foco, JNI ni Java: la etiqueta se dibuja
// en la misma llamada que ya dibuja la pildora
// (Renderer::DrawAudioButton, mismo estado, mismas constantes
// kAudioBtn*), con el mismo shader y el mismo camino de textura
// que DrawTexturedQuad (GxGlRenderer::DrawTexturedQuadRect, nuevo
// en este tramo). El táctil NO cambia en absoluto: la etiqueta
// es solo pintura dentro del rectangulo que ya intercepta Input.
//
// FUENTE: bitmap 5x7 embebido en este header (sin fichero de
// fuente, sin asset en la APK, sin dependencia de la densidad ni
// del tamano de fuente del usuario: la escala se calcula desde
// los pixeles reales de la pildora, asi que el texto NUNCA puede
// desbordar la pildora por construccion — ver LayoutFor).
// Letras: A-Z + Ñ (U+00D1, tilde en la fila 0) + espacio; minus-
// culas se pliegan a mayusculas; cualquier otro caracter se
// dibuja como '?' (visible, nunca un hueco silencioso).
//
// Etiquetas (una por estado, texto de ACCION en el estado que
// pide pulsar; el estado se sigue comunicando tambien por color
// + boot.log, como en el Tramo 6):
//   kNoAudio   -> "AÑADIR AUDIO"  (12 glifos)
//   kVerifying -> "VERIFICANDO"   (11 glifos)
//   kReady     -> "AUDIO LISTO"   (11 glifos)
//   kError     -> "ERROR AUDIO"   (11 glifos)
//
// Color del texto (contraste WCAG medido con la formula de
// luminancia relativa, ver TRAMO7-INFORME.md §1.3):
//   ambar (255,176,0)  + oscuro (20,20,30)   = 9,98:1
//   verde (0,200,80)   + oscuro              = 8,16:1
//   rojo  (220,40,40)  + blanco (255,255,255)= 4,80:1
//     (oscuro sobre rojo solo daria 3,81:1, por eso Error usa
//     blanco; es el unico estado con texto claro)
//   fondo parpadeo-off (32,32,48) + ambar    = 8,75:1
//   (Verifying con blink_off usa ambar, no blanco, para no
//   perder la identidad de color del estado "verificando").
//
// Textura OPACA (fondo = color de la pildora, texto = color de
// texto, alfa 255 en todos los pixeles): el shader de
// GxGlRenderer no activa blending, asi que una textura con alfa
// mostraria el fondo del frame anterior en los huecos. Al ser
// opaca y del mismo color que el interior de la pildora, el quad
// de la etiqueta es indistinguible del interior salvo por las
// letras, y el filtrado LINEAR en los bordes no deja halo.
//
// Coste por frame: la etiqueta se rasteriza y se sube como
// textura en cada frame (igual que DrawTexturedQuad ya hace con
// su textura): 284x28x4 = 31.808 B en Tab S8 (~1,9 MB/s a 60 fps,
// despreciable frente a los draws GX). Cachear la textura entre
// frames queda como optimizacion futura, no como necesidad: el
// parpadeo cambia el color cada 30 frames de todos modos.
//
// Sin dependencias Android ni GL: solo fracciones, pixeles y un
// buffer RGBA. El MISMO codigo lo compila el NDK y lo ejercita
// el test host (precedente: audio_state_fs.h en el Tramo 6).

#include <cmath>
#include <cstdint>
#include <vector>

#include "input/audio_button.h"

namespace sfa {

// ---- Fuente 5x7: cada fila son 5 bits, bit 4 = columna izquierda.
struct AudioGlyph {
  int codepoint;  // ASCII, o 0xD1 para Ñ (U+00D1).
  uint8_t rows[7];
};

inline const AudioGlyph* AudioGlyphTable(int* out_count) {
  static const AudioGlyph kGlyphs[] = {
      {'A', {0b01110, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001}},
      {'B', {0b11110, 0b10001, 0b10001, 0b11110, 0b10001, 0b10001, 0b11110}},
      {'C', {0b01110, 0b10001, 0b10000, 0b10000, 0b10000, 0b10001, 0b01110}},
      {'D', {0b11100, 0b10010, 0b10001, 0b10001, 0b10001, 0b10010, 0b11100}},
      {'E', {0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b11111}},
      {'F', {0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b10000}},
      {'G', {0b01110, 0b10001, 0b10000, 0b10111, 0b10001, 0b10001, 0b01110}},
      {'H', {0b10001, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001}},
      {'I', {0b01110, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b01110}},
      {'J', {0b00111, 0b00010, 0b00010, 0b00010, 0b00010, 0b10010, 0b01100}},
      {'K', {0b10001, 0b10010, 0b10100, 0b11000, 0b10100, 0b10010, 0b10001}},
      {'L', {0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b11111}},
      {'M', {0b10001, 0b11011, 0b10101, 0b10101, 0b10001, 0b10001, 0b10001}},
      {'N', {0b10001, 0b11001, 0b10101, 0b10011, 0b10001, 0b10001, 0b10001}},
      // Ñ: tilde en la fila 0 + cuerpo de N en las filas 1-6.
      {0xD1, {0b01010, 0b10001, 0b11001, 0b10101, 0b10011, 0b10001, 0b10001}},
      {'O', {0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110}},
      {'P', {0b11110, 0b10001, 0b10001, 0b11110, 0b10000, 0b10000, 0b10000}},
      {'Q', {0b01110, 0b10001, 0b10001, 0b10001, 0b10101, 0b10010, 0b01101}},
      {'R', {0b11110, 0b10001, 0b10001, 0b11110, 0b10100, 0b10010, 0b10001}},
      {'S', {0b01111, 0b10000, 0b10000, 0b01110, 0b00001, 0b00001, 0b11110}},
      {'T', {0b11111, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100}},
      {'U', {0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110}},
      {'V', {0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01010, 0b00100}},
      {'W', {0b10001, 0b10001, 0b10001, 0b10101, 0b10101, 0b10101, 0b01010}},
      {'X', {0b10001, 0b10001, 0b01010, 0b00100, 0b01010, 0b10001, 0b10001}},
      {'Y', {0b10001, 0b10001, 0b01010, 0b00100, 0b00100, 0b00100, 0b00100}},
      {'Z', {0b11111, 0b00001, 0b00010, 0b00100, 0b01000, 0b10000, 0b11111}},
      {'?', {0b01110, 0b10001, 0b00001, 0b00110, 0b00100, 0b00000, 0b00100}},
      {' ', {0, 0, 0, 0, 0, 0, 0}},
  };
  if (out_count != nullptr) *out_count = 29;
  return kGlyphs;
}

// Busca un glifo; minusculas -> mayusculas; desconocido -> '?'.
inline const AudioGlyph* AudioGlyphFor(int codepoint) {
  if (codepoint >= 'a' && codepoint <= 'z') codepoint -= 32;
  int count = 0;
  const AudioGlyph* table = AudioGlyphTable(&count);
  for (int i = 0; i < count; ++i) {
    if (table[i].codepoint == codepoint) return &table[i];
  }
  for (int i = 0; i < count; ++i) {
    if (table[i].codepoint == '?') return &table[i];
  }
  return nullptr;
}

// Decodifica el siguiente glifo de una cadena UTF-8 (solo se
// necesita Ñ: secuencia C3 91 / C3 B1; resto multibyte -> '?').
// Devuelve el codepoint y avanza *p (al menos 1 byte, nunca 0).
inline int AudioLabelNextGlyph(const char** p) {
  const unsigned char* s = reinterpret_cast<const unsigned char*>(*p);
  if (s[0] == 0) return 0;
  if (s[0] < 0x80) {
    *p += 1;
    return s[0];
  }
  if (s[0] == 0xC3 && (s[1] == 0x91 || s[1] == 0xB1)) {
    *p += 2;
    return 0xD1;
  }
  *p += 1;  // Byte UTF-8 no soportado: '?' visible, sin atascarse.
  return '?';
}

inline int AudioLabelGlyphCount(const char* text) {
  if (text == nullptr) return 0;
  int n = 0;
  const char* p = text;
  while (*p != 0) {
    if (AudioLabelNextGlyph(&p) != 0) ++n;
  }
  return n;
}

inline const char* AudioLabelText(AudioState state) {
  switch (state) {
    case AudioState::kNoAudio:
      return "A\xC3\x91" "ADIR AUDIO";  // "AÑADIR AUDIO"
    case AudioState::kVerifying:
      return "VERIFICANDO";
    case AudioState::kReady:
      return "AUDIO LISTO";
    case AudioState::kError:
      return "ERROR AUDIO";
  }
  return "A\xC3\x91" "ADIR AUDIO";
}

inline AudioButtonColor AudioLabelTextColor(AudioState state, bool blink_on) {
  if (state == AudioState::kVerifying && !blink_on) {
    return AudioButtonColor{255, 176, 0};  // ambar sobre fondo oscuro
  }
  if (state == AudioState::kError) {
    return AudioButtonColor{255, 255, 255};  // blanco sobre rojo
  }
  return AudioButtonColor{20, 20, 30};  // oscuro sobre ambar/verde
}

// Tamano de la pildora en pixeles desde su extension NDC:
// NDC va de -1 a 1, asi que px = span_ndc / 2 * pantalla.
inline int AudioLabelPillPx(float ndc_span, int screen_px) {
  if (screen_px <= 0) return 0;
  return static_cast<int>(std::lround(ndc_span * 0.5f * screen_px));
}

struct AudioLabelLayout {
  bool ok = false;
  int scale = 0;
  int tex_w = 0;
  int tex_h = 0;
  int glyph_count = 0;
};

// Escala maxima que cabe con un margen minimo de 8 px por lado.
// Geometria del texto: cada glifo ocupa 6 columnas (5 + 1 de
// separacion) salvo el ultimo, que no lleva separacion final:
//   tex_w = (6*n - 1) * scale,  tex_h = 7 * scale.
// Si ni scale=1 cabe, ok=false: el llamador dibuja la pildora
// SIN etiqueta (nunca una etiqueta recortada ni desbordada).
inline AudioLabelLayout AudioLabelLayoutFor(const char* text, int pill_w_px,
                                             int pill_h_px) {
  AudioLabelLayout out;
  out.glyph_count = AudioLabelGlyphCount(text);
  if (out.glyph_count <= 0 || pill_w_px <= 0 || pill_h_px <= 0) return out;
  const int avail_w = pill_w_px - 16;
  const int avail_h = pill_h_px - 16;
  if (avail_w <= 0 || avail_h <= 0) return out;
  const int by_w = avail_w / (6 * out.glyph_count - 1);
  const int by_h = avail_h / 7;
  const int scale = by_w < by_h ? by_w : by_h;
  if (scale < 1) return out;
  out.scale = scale;
  out.tex_w = (6 * out.glyph_count - 1) * scale;
  out.tex_h = 7 * scale;
  out.ok = true;
  return out;
}

// Rasteriza la etiqueta a RGBA opaco (fondo = color de la
// pildora, texto = color de texto). Vector vacio si no cabe.
inline std::vector<uint8_t> RasterizeAudioLabel(AudioState state, bool blink_on,
                                                int pill_w_px, int pill_h_px,
                                                AudioLabelLayout* out_layout) {
  const char* text = AudioLabelText(state);
  AudioLabelLayout layout = AudioLabelLayoutFor(text, pill_w_px, pill_h_px);
  if (out_layout != nullptr) *out_layout = layout;
  if (!layout.ok) return std::vector<uint8_t>();
  const AudioButtonColor bg = AudioButtonColorFor(state, blink_on);
  const AudioButtonColor fg = AudioLabelTextColor(state, blink_on);
  std::vector<uint8_t> rgba(static_cast<size_t>(layout.tex_w) * layout.tex_h *
                            4);
  for (size_t i = 0; i < rgba.size(); i += 4) {
    rgba[i + 0] = bg.r;
    rgba[i + 1] = bg.g;
    rgba[i + 2] = bg.b;
    rgba[i + 3] = 255;
  }
  const int s = layout.scale;
  const char* p = text;
  int gi = 0;
  while (*p != 0) {
    const int cp = AudioLabelNextGlyph(&p);
    const AudioGlyph* g = AudioGlyphFor(cp);
    if (g != nullptr) {
      for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 5; ++col) {
          if ((g->rows[row] & (1 << (4 - col))) == 0) continue;
          for (int dy = 0; dy < s; ++dy) {
            for (int dx = 0; dx < s; ++dx) {
              const int x = (gi * 6 + col) * s + dx;
              const int y = row * s + dy;
              const size_t off =
                  (static_cast<size_t>(y) * layout.tex_w + x) * 4;
              rgba[off + 0] = fg.r;
              rgba[off + 1] = fg.g;
              rgba[off + 2] = fg.b;
              rgba[off + 3] = 255;
            }
          }
        }
      }
    }
    ++gi;
  }
  return rgba;
}

struct AudioLabelQuad {
  bool ok = false;
  float x0 = 0;
  float y_top = 0;
  float x1 = 0;
  float y_bot = 0;
};

// Quad NDC de la etiqueta, centrado en la pildora y SIN distorsion:
// el ancho/alto NDC se derivan de los pixeles reales de la textura
// y de la pantalla (no del rectangulo de la pildora: estirar la
// textura a toda la pildora deformaria las letras, aspect 2,0 de
// la pildora frente a ~10,1 de "AÑADIR AUDIO" a escala 4).
// ok=false si no hay pantalla valida: el llamador omite la etiqueta.
inline AudioLabelQuad AudioLabelQuadFor(int screen_w, int screen_h,
                                         float pill_x0, float pill_x1,
                                         float pill_y_top, float pill_y_bot,
                                         int tex_w, int tex_h) {
  AudioLabelQuad out;
  if (screen_w <= 0 || screen_h <= 0 || tex_w <= 0 || tex_h <= 0) return out;
  const float qw = 2.0f * tex_w / screen_w;
  const float qh = 2.0f * tex_h / screen_h;
  const float cx = (pill_x0 + pill_x1) * 0.5f;
  const float cy = (pill_y_top + pill_y_bot) * 0.5f;
  out.x0 = cx - qw * 0.5f;
  out.x1 = cx + qw * 0.5f;
  out.y_top = cy + qh * 0.5f;
  out.y_bot = cy - qh * 0.5f;
  out.ok = true;
  return out;
}

}  // namespace sfa
