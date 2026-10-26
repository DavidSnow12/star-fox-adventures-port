#pragma once

// Input — Fase 6b (mando/teclado) + Fase 13 (tactil por layout).
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
//   - Tactil: layout definido en input/touch_layout.h
//     (fracciones de pantalla, no pixeles): stick virtual
//     izquierdo, rombo A/B/X/Y, Z, L/R, Start, D-pad y zona
//     C-stick reservada SIN MAPEO (substick a 0). El tamano
//     de ventana lo fija native-lib con SetViewportSize en
//     INIT_WINDOW; sin tamano, los toques se ignoran (no se
//     puede clasificar una zona en fracciones sin el).
//     Multitactil: cada dedo es un boton o el stick, con
//     seguimiento por pointer id; soltar rearma el flanco.
//   - Rumble: PADControlMotor tiene HLE desde la fase TEV
//     (kPadControlMotor 0x8024F580 con estado por canal y
//     solo-en-transicion, ver rumble.h); desde la fase B el
//     sink es JniVibratorSink (chan 0 al Vibrator fisico,
//     ver rumble_jni.h y MainActivity), y el juego no lo
//     ha llamado en los runs host todavia.
// HandleEvent devuelve true solo si el evento cambio el
// estado (consumido); si no, false para no ocultar eventos
// al sistema. El flanco JustPressed lo calcula padUpdate
// en el juego (Held & ~Prev); aqui solo se escribe Held.

#include <android/input.h>
#include <cstdint>

#include "input/pad_state.h"
#include "input/touch_layout.h"

namespace sfa {

class Input {
 public:
  void Reset();
  // Tamano de ventana en pixeles (ANativeWindow). Debe llamarse
  // antes de que lleguen toques; si no, el tactil se ignora.
  void SetViewportSize(int width, int height);
  // Devuelve true si el evento se consumio (cambio el estado).
  bool HandleEvent(AInputEvent* event);
  const PadState& State() const { return state_; }
  PadState* StatePtr() { return &state_; }

 private:
  bool HandleKey(AInputEvent* event);
  bool HandleMotion(AInputEvent* event);
  bool HandleTouch(AInputEvent* event);
  void SetButton(uint16_t bit, bool pressed);

  PadState state_;
  TouchLayout touch_;
  int viewport_w_ = 0;
  int viewport_h_ = 0;
  bool logged_touch_ = false;
  bool logged_no_viewport_ = false;
};

}  // namespace sfa
