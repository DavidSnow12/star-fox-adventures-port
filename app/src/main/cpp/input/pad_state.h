#pragma once

// Estado de un mando de GameCube, compartido entre Input (que lo
// escribe desde eventos Android) y el HLE (que lo vuelca en el
// PADStatus que lee padUpdate). Sin dependencias Android: este
// fichero lo incluyen tanto input.cpp (NDK) como hle.cpp (host).
//
// Bits de botones (libogc, verificados contra padUpdate
// 0x80014F6C: lee botones como u16 BE en +0 del PADStatus):
//   D-pad: LEFT 0x0001, RIGHT 0x0002, DOWN 0x0004, UP 0x0008.
//   Z 0x0010, R 0x0020, L 0x0040.
//   A 0x0100, B 0x0200, X 0x0400, Y 0x0800, START 0x1000.
// Gatillos: en PADStatus son analogicos u8 (0-255) en +6/+7; en
// esta fase son todo o nada: bit L/R puesto => 255, si no 0.
// analogA/analogB (+8/+9): presion de A/B, mismo criterio.
// C-stick (+4/+5, sub-stick): siempre 0 en esta fase.

#include <cstdint>

namespace sfa {

struct PadState {
  uint16_t buttons = 0;
  int8_t stick_x = 0;
  int8_t stick_y = 0;
  int8_t substick_x = 0;
  int8_t substick_y = 0;
  uint8_t trigger_l = 0;
  uint8_t trigger_r = 0;
  uint8_t analog_a = 0;
  uint8_t analog_b = 0;

  static constexpr uint16_t kButtonLeft = 0x0001u;
  static constexpr uint16_t kButtonRight = 0x0002u;
  static constexpr uint16_t kButtonDown = 0x0004u;
  static constexpr uint16_t kButtonUp = 0x0008u;
  static constexpr uint16_t kButtonZ = 0x0010u;
  static constexpr uint16_t kButtonR = 0x0020u;
  static constexpr uint16_t kButtonL = 0x0040u;
  static constexpr uint16_t kButtonA = 0x0100u;
  static constexpr uint16_t kButtonB = 0x0200u;
  static constexpr uint16_t kButtonX = 0x0400u;
  static constexpr uint16_t kButtonY = 0x0800u;
  static constexpr uint16_t kButtonStart = 0x1000u;

  // Aplica el criterio todo o nada a los valores analogicos que
  // derivan de botones digitales (gatillos y presion A/B).
  void SyncAnalogFromButtons() {
    trigger_l = (buttons & kButtonL) != 0 ? 255u : 0u;
    trigger_r = (buttons & kButtonR) != 0 ? 255u : 0u;
    analog_a = (buttons & kButtonA) != 0 ? 255u : 0u;
    analog_b = (buttons & kButtonB) != 0 ? 255u : 0u;
    substick_x = 0;
    substick_y = 0;
  }
};

}  // namespace sfa
