#pragma once

// Input — Fase 6b: eventos Android -> PadState de GameCube.
//
// El estado vive en PadState (input/pad_state.h, sin deps
// Android) y el HLE lo lee en PADRead (Hle::SetPadState); este
// modulo solo traduce eventos a ese estado, no toca el juego.
// Mapeo (ver pad_state.h para los bits):
//   - Mando (teclas AKEYCODE_BUTTON_* y ejes joystick): A/B/X/
//     Y/Z, L/R (gatillos analogicos > 0,5 => bit + 255, si no
//     0: todo o nada), D-pad, Start, stick izquierdo con
//     AXIS_X/AXIS_Y (Y invertida: arriba Android es -1 y en
//     GC arriba es +127). C-stick: siempre 0 en esta fase
//     (los ejes AXIS_Z/RZ se ignoran a proposito).
//   - Teclado: flechas = D-pad, Enter = Start, Z = boton Z.
//   - Tactil (primer dedo): arrastre desde el punto de
//     apoyo => stick (100 px = deflexion completa, con
//     clamp a +-127). Los botones tactiles NO se mapean
//     todavia: no hay un layout de botones en
//     pantalla definido y un mapeo inventado (zonas
//     cuadrantes) seria peor que la ausencia; queda como
//     siguiente paso con un layout explicito.
//   - Rumble: no-op en esta fase (PADControlMotor no tiene
//     HLE todavia; el juego no lo ha llamado en los runs).
// HandleEvent devuelve true solo si el evento cambio el
// estado (consumido); si no, false para no ocultar eventos
// al sistema.

#include <android/input.h>
#include <cstdint>

#include "input/pad_state.h"

namespace sfa {

class Input {
 public:
  void Reset();
  // Devuelve true si el evento se consumio (cambio el estado).
  bool HandleEvent(AInputEvent* event);
  const PadState& State() const { return state_; }
  PadState* StatePtr() { return &state_; }

 private:
  bool HandleKey(AInputEvent* event);
  bool HandleMotion(AInputEvent* event);
  void SetButton(uint16_t bit, bool pressed);

  PadState state_;
  bool logged_touch_ = false;
  bool touch_active_ = false;
  int32_t touch_id_ = -1;
  float touch_anchor_x_ = 0.0f;
  float touch_anchor_y_ = 0.0f;
};

}  // namespace sfa
