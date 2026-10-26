#pragma once

// Layout tactil en pantalla — Fase 13. Fuente unica de verdad para
// las zonas tactiles, compartida entre la APK (input.cpp, que
// convierte pixeles a fracciones con el tamano de ventana) y las
// pruebas host (que alimentan fracciones directamente).
//
// Sin dependencias Android: solo fracciones de pantalla (0..1,
// origen arriba-izquierda, x a la derecha, y hacia abajo) y
// PadState. La conversion a pixeles vive en input.cpp; este
// modulo nunca ve un pixel.
//
// Coordenadas en "unidades de alto": para que un circulo tactil
// sea un circulo en pixeles en pantallas 16:9, la distancia se
// mide como u = (x - cx) * aspect, v = (cy - y), con aspect =
// ancho/alto de la ventana (16:9 => 1,777...). Un radio de 0,09
// son ~65 px en una pantalla de 720 px de alto, y 0,18 son
// ~130 px de recorrido del stick.
//
// LAYOUT DEFINIDO (paisaje; fracciones, no pixeles absolutos):
//
//   L (0.055,0.12)      Start (0.50,0.10)      R (0.945,0.12)
//   Stick (0.13,0.72)   C-stick RESERVADO      D-pad (0.255,0.70)
//   radio aceptacion    (0.62,0.70) SIN MAPEO   + A/B/X/Y (0.845,0.70)
//
// Diagrama (ver PORT-STATUS para la version con zonas y tamanos):
//
//   +----------------------------------------------------------+
//   | [L]              [Start]                         [R]     |
//   |                                                          |
//   |   (o) stick                      ( ) C-stick    [X]      |
//   |  zona 0.01-0.25 x 0.42-0.98    reservado    [Y]  [A]      |
//   |   D-pad [+] junto al stick                 [B]          |
//   +----------------------------------------------------------+
//
// Zonas (centro, radio en unidades de alto; botones 0,09):
//   - Stick virtual: centro (0.13, 0.72), aceptacion 0,20,
//     recorrido 0,18. Arrastrar desde el apoyo: abajo en
//     pantalla => stick_y negativo (GC: abajo = -127), como
//     el stick fisico. Es EL control que mueve los menus:
//     el aviso y el menu de titulo se mueven con stick Y
//     (padGetStickY), NO con D-pad (medido Fase 12).
//   - A (0.905,0.70), B (0.845,0.82), X (0.845,0.58),
//     Y (0.785,0.70): rombo alrededor de (0.845,0.70).
//   - Z (0.72,0.55). L (0.055,0.12), R (0.945,0.12),
//     Start (0.50,0.10).
//   - D-pad: Up (0.255,0.58), Down (0.255,0.82),
//     Left (0.195,0.70), Right (0.315,0.70). Existe para el
//     juego, pero NO mueve el aviso ni (por lo medido) el
//     menu de titulo: esos usan stick Y.
//   - C-stick: zona reservada en (0.62,0.70), radio 0,20,
//     SIN MAPEO en esta fase (substick queda a 0, como en
//     todas las fases previas). Los toques ahi se ignoran
//     a proposito: mapearlo a medias (p. ej. sin flanco
//     ni zona muerta medida) seria peor que reservarlo.
//     Queda documentado, no olvidado.
// Prioridad en Down: botones, luego stick, luego C-stick
// reservado (ignorado), luego fuera de zona (ignorado).
// Antes de esta fase cualquier primer dedo era stick en
// toda la pantalla; ese comportamiento queda sustituido
// por este layout: un toque fuera de zona ya no mueve
// el stick por accidente.
//
// Flanco JustPressed: TouchLayout solo escribe Held en
// PadState (botones y stick). El flanco Just = Held &
// ~Prev lo calcula padUpdate en el juego (0x80014F6C),
// exactamente igual que para mando/teclado: no hay poke
// directo de Just desde aqui. Soltar un boton limpia su
// bit; soltar el stick vuelve stick_x/stick_y a 0, lo que
// rearma el flanco de stick Y para el siguiente toque
// (el aviso exige soltar entre movimientos).

#include <cstdint>
#include <map>

#include "input/pad_state.h"

namespace sfa {

class TouchLayout {
 public:
  enum class EventType { kDown, kMove, kUp };

  struct TouchEvent {
    EventType type;
    int32_t id;   // identificador de dedo (pointer id Android)
    float x;      // fraccion de ancho, 0..1
    float y;      // fraccion de alto, 0..1
  };

  explicit TouchLayout(float aspect = 16.0f / 9.0f) : aspect_(aspect) {}
  void SetAspect(float aspect) { aspect_ = aspect; }
  float Aspect() const { return aspect_; }

  void Reset() {
    pointers_.clear();
    stick_pointer_ = -1;
    anchor_x_ = 0.0f;
    anchor_y_ = 0.0f;
  }

  // Aplica un evento tactil a `state`. Devuelve true si cambio
  // el estado (consumido). No toca sub-stick: queda a 0.
  bool Handle(const TouchEvent& ev, PadState& state) {
    switch (ev.type) {
      case EventType::kDown: return OnDown(ev, state);
      case EventType::kMove: return OnMove(ev, state);
      case EventType::kUp: return OnUp(ev, state);
    }
    return false;
  }

  // Clasificacion de una posicion (para pruebas y documentacion).
  // Devuelve el bit del boton de esa zona, 0 si es zona de stick,
  // y -1 si no es ninguna zona activa (incluida la C-stick
  // reservada y el exterior).
  int ZoneButtonAt(float x, float y) const {
    uint16_t bit = ButtonAt(x, y);
    if (bit != 0) return static_cast<int>(bit);
    if (InStickZone(x, y)) return 0;
    return -1;
  }

  bool InStickZone(float x, float y) const {
    return Dist2(x, y, kStickX, kStickY) <= kStickAccept * kStickAccept;
  }

 private:
  static constexpr float kStickX = 0.13f;
  static constexpr float kStickY = 0.72f;
  static constexpr float kStickAccept = 0.20f;
  static constexpr float kStickTravel = 0.18f;
  static constexpr float kButtonRadius = 0.09f;
  static constexpr float kCStickX = 0.62f;
  static constexpr float kCStickY = 0.70f;

  struct ButtonZone {
    float x;
    float y;
    uint16_t bit;
  };
  // Rombo A/B/X/Y + resto, en el orden de prioridad de acierto
  // (las zonas no se solapan: centros separados >= 0,085 en
  // unidades de alto frente a radio 0,09... salvo A/B y A/X,
  // que distan ~0,107; el primer acierto en este orden gana,
  // documentado para que un toque entre dos botones no sea
  // ambiguo en codigo).
  // Definido dentro de la clase (C++17): ButtonAt lo recorre en
  // linea y necesita el tipo completo aqui, no solo declarado.
  static constexpr ButtonZone kZones[] = {
      {0.905f, 0.70f, PadState::kButtonA},
      {0.845f, 0.82f, PadState::kButtonB},
      {0.845f, 0.58f, PadState::kButtonX},
      {0.785f, 0.70f, PadState::kButtonY},
      {0.720f, 0.55f, PadState::kButtonZ},
      {0.055f, 0.12f, PadState::kButtonL},
      {0.945f, 0.12f, PadState::kButtonR},
      {0.500f, 0.10f, PadState::kButtonStart},
      {0.255f, 0.58f, PadState::kButtonUp},
      {0.255f, 0.82f, PadState::kButtonDown},
      {0.195f, 0.70f, PadState::kButtonLeft},
      {0.315f, 0.70f, PadState::kButtonRight},
  };

  // Distancia al cuadrado en unidades de alto (sin raiz: los
  // llamadores comparan con radio al cuadrado).
  float Dist2(float x, float y, float cx, float cy) const {
    float u = (x - cx) * aspect_;
    float v = cy - y;
    return u * u + v * v;
  }

  uint16_t ButtonAt(float x, float y) const {
    for (const ButtonZone& z : kZones) {
      if (Dist2(x, y, z.x, z.y) <= kButtonRadius * kButtonRadius) {
        return z.bit;
      }
    }
    return 0;
  }

  static int8_t AxisToStick(float v) {
    if (v < -1.0f) v = -1.0f;
    if (v > 1.0f) v = 1.0f;
    int t = static_cast<int>(v * 127.0f);
    if (t > 127) t = 127;
    if (t < -127) t = -127;
    return static_cast<int8_t>(t);
  }

  void SetButton(PadState& state, uint16_t bit, bool pressed) {
    if (pressed) {
      state.buttons = static_cast<uint16_t>(state.buttons | bit);
    } else {
      state.buttons = static_cast<uint16_t>(state.buttons & ~bit);
    }
    state.SyncAnalogFromButtons();
  }

  bool OnDown(const TouchEvent& ev, PadState& state) {
    if (pointers_.count(ev.id) != 0) return false;
    uint16_t bit = ButtonAt(ev.x, ev.y);
    if (bit != 0) {
      pointers_[ev.id] = bit;
      SetButton(state, bit, true);
      return true;
    }
    if (InStickZone(ev.x, ev.y)) {
      if (stick_pointer_ != -1) return false;  // un solo stick
      stick_pointer_ = ev.id;
      anchor_x_ = ev.x;
      anchor_y_ = ev.y;
      state.stick_x = 0;
      state.stick_y = 0;
      return true;
    }
    // C-stick reservado y exterior: ignorados a proposito.
    return false;
  }

  bool OnMove(const TouchEvent& ev, PadState& state) {
    if (stick_pointer_ != -1 && ev.id == stick_pointer_) {
      float u = (ev.x - anchor_x_) * aspect_;
      float v = anchor_y_ - ev.y;
      state.stick_x = AxisToStick(u / kStickTravel);
      state.stick_y = AxisToStick(v / kStickTravel);
      return true;
    }
    return false;  // botones: mantener no necesita Move
  }

  bool OnUp(const TouchEvent& ev, PadState& state) {
    auto it = pointers_.find(ev.id);
    if (it != pointers_.end()) {
      SetButton(state, it->second, false);
      pointers_.erase(it);
      return true;
    }
    if (stick_pointer_ != -1 && ev.id == stick_pointer_) {
      stick_pointer_ = -1;
      state.stick_x = 0;
      state.stick_y = 0;
      return true;
    }
    return false;
  }

  float aspect_;
  std::map<int32_t, uint16_t> pointers_;  // dedo -> bit de boton
  int32_t stick_pointer_ = -1;
  float anchor_x_ = 0.0f;
  float anchor_y_ = 0.0f;
};

}  // namespace sfa
