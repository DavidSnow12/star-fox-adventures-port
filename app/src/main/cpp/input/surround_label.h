#pragma once

// Etiqueta de texto de la pildora "surround" — Tramo 21 (via BITMAP
// EN GL, mismo patron que la pildora de audio del Tramo 7, ver
// input/audio_label.h: sin overlay Java — NativeActivity no tiene
// UI Java y un TextView sobre EGL exigiria z-order/foco que el
// bucle nativo no tolera —, sin fichero de fuente y sin asset en
// la APK: la fuente 5x7, el layout y el quad se REUTILIZAN de
// audio_label.h (no se duplica la tabla de glifos); aqui solo se
// eligen texto y colores de ESTE boton. El tactil NO cambia en
// absoluto: la etiqueta es solo pintura dentro del rectangulo
// que ya intercepta Input (surround_button.h), dibujada en la
// misma llamada que ya dibuja la pildora (Renderer::
// DrawSurroundButton, mismo estado, mismas constantes
// kSurroundBtn*), con el mismo shader y el mismo camino de
// textura que DrawTexturedQuadRect.
//
// Textos (de ESTADO, no de accion: el color ya comunica el
// estado y el boot.log lo confirma; "SURROUND OFF" no es una
// invitacion a apagar algo apagado):
//   OFF -> "SURROUND OFF"  (12 glifos)
//   ON  -> "SURROUND ON"   (11 glifos)
// Ambos caben en la pildora 0.31-0.43 (mismo ancho que la de
// audio, 0.44-0.56, que ya lleva 12 glifos): la escala la
// calcula AudioLabelLayoutFor desde los pixeles reales, asi
// que el texto NUNCA puede desbordar por construccion; si ni
// escala 1 cabe, el llamador dibuja la pildora SIN etiqueta
// (como la de audio).
//
// Color del texto (contraste WCAG, formula de luminancia
// relativa; medido en el test host del Tramo 21):
//   OFF gris pizarra (96,96,112) + blanco (255,255,255): el
//     oscuro (20,20,30) solo daria ~2,8:1, por eso OFF usa
//     blanco (el unico estado con texto claro, igual que
//     Error en audio).
//   ON cian (0,180,220) + oscuro (20,20,30).
// Textura OPACA (fondo = color de la pildora, texto = color de
// texto, alfa 255 en todos los pixeles): el shader no activa
// blending, asi que una textura con alfa mostraria el fondo
// del frame anterior en los huecos.
//
// Sin dependencias Android ni GL: solo fracciones, pixeles y
// un buffer RGBA. El MISMO codigo lo compila el NDK y lo
// ejercita el test host.

#include <cstdint>
#include <vector>

#include "input/audio_label.h"
#include "input/surround_button.h"

namespace sfa {

inline const char* SurroundLabelText(bool enabled) {
  return enabled ? "SURROUND ON" : "SURROUND OFF";
}

// Color RGB del texto segun estado (ver cabecera: OFF blanco
// por contraste sobre gris pizarra, ON oscuro sobre cian).
struct SurroundLabelColor {
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
};

inline SurroundLabelColor SurroundLabelTextColor(bool enabled) {
  if (enabled) return SurroundLabelColor{20, 20, 30};  // oscuro sobre cian
  return SurroundLabelColor{255, 255, 255};           // blanco sobre gris
}

// Rasteriza la etiqueta a RGBA opaco (fondo = color de la
// pildora, texto = color de texto). Vector vacio si no cabe
// (el llamador dibuja la pildora sin etiqueta, nunca recortada).
inline std::vector<uint8_t> RasterizeSurroundLabel(
    bool enabled, int pill_w_px, int pill_h_px,
    AudioLabelLayout* out_layout) {
  const char* text = SurroundLabelText(enabled);
  AudioLabelLayout layout = AudioLabelLayoutFor(text, pill_w_px, pill_h_px);
  if (out_layout != nullptr) *out_layout = layout;
  if (!layout.ok) return std::vector<uint8_t>();
  const SurroundButtonColor bg = SurroundButtonColorFor(enabled);
  const SurroundLabelColor fg = SurroundLabelTextColor(enabled);
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

}  // namespace sfa
