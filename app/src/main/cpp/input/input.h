#pragma once

// Input — STUB de la base: táctil -> mando de GameCube.
//
// La correspondencia real (stick analógico, botones A/B/X/Y/Z,
// gatillos, C-stick, D-pad) se definirá con la primera pantalla
// jugable; aquí solo se registra el primer toque para validar que
// los eventos llegan desde android_main.

#include <android/input.h>
#include <cstdint>

namespace sfa {

class Input {
 public:
  void Reset();
  // Devuelve true si el evento se consumió. De momento solo
  // registra el primer evento de cada tipo.
  bool HandleEvent(AInputEvent* event);

 private:
  bool logged_touch_ = false;
};

}  // namespace sfa
