#include "input/input.h"

#include <cmath>

#include "log.h"

namespace sfa {

namespace {

float ClampAxis(float v) {
  if (v < -1.0f) return -1.0f;
  if (v > 1.0f) return 1.0f;
  return v;
}

int8_t AxisToStick(float v) {
  float c = ClampAxis(v);
  int v127 = static_cast<int>(c * 127.0f);
  if (v127 > 127) v127 = 127;
  if (v127 < -127) v127 = -127;
  return static_cast<int8_t>(v127);
}

}  // namespace

void Input::Reset() {
  state_ = PadState();
  touch_.Reset();
  // AudioButton::Reset() solo limpia armado/disparo, no el
  // estado (lo reescribe native-lib tras Init, ver
  // audio_button.h): aqui no se pierde un Ready previo.
  audio_button_.Reset();
  surround_button_.Reset();
  logged_touch_ = false;
  logged_no_viewport_ = false;
}

void Input::SetViewportSize(int width, int height) {
  if (width <= 0 || height <= 0) return;
  viewport_w_ = width;
  viewport_h_ = height;
  touch_.SetAspect(static_cast<float>(width) /
                   static_cast<float>(height));
}

void Input::SetButton(uint16_t bit, bool pressed) {
  if (pressed) {
    state_.buttons = static_cast<uint16_t>(state_.buttons | bit);
  } else {
    state_.buttons = static_cast<uint16_t>(state_.buttons & ~bit);
  }
  state_.SyncAnalogFromButtons();
}

bool Input::HandleEvent(AInputEvent* event) {
  if (event == nullptr) return false;
  int32_t type = AInputEvent_getType(event);
  if (type == AINPUT_EVENT_TYPE_KEY) return HandleKey(event);
  if (type == AINPUT_EVENT_TYPE_MOTION) return HandleMotion(event);
  return false;
}

bool Input::HandleKey(AInputEvent* event) {
  int32_t action = AKeyEvent_getAction(event);
  if (action != AKEY_EVENT_ACTION_DOWN &&
      action != AKEY_EVENT_ACTION_UP) {
    return false;
  }
  bool pressed = action == AKEY_EVENT_ACTION_DOWN;
  uint16_t bit = 0;
  switch (AKeyEvent_getKeyCode(event)) {
    case AKEYCODE_BUTTON_A: bit = PadState::kButtonA; break;
    case AKEYCODE_BUTTON_B: bit = PadState::kButtonB; break;
    case AKEYCODE_BUTTON_X: bit = PadState::kButtonX; break;
    case AKEYCODE_BUTTON_Y: bit = PadState::kButtonY; break;
    case AKEYCODE_BUTTON_L1: bit = PadState::kButtonL; break;
    case AKEYCODE_BUTTON_R1: bit = PadState::kButtonR; break;
    case AKEYCODE_BUTTON_L2: bit = PadState::kButtonL; break;
    case AKEYCODE_BUTTON_R2: bit = PadState::kButtonR; break;
    case AKEYCODE_BUTTON_START: bit = PadState::kButtonStart; break;
    case AKEYCODE_DPAD_UP: bit = PadState::kButtonUp; break;
    case AKEYCODE_DPAD_DOWN: bit = PadState::kButtonDown; break;
    case AKEYCODE_DPAD_LEFT: bit = PadState::kButtonLeft; break;
    case AKEYCODE_DPAD_RIGHT: bit = PadState::kButtonRight; break;
    case AKEYCODE_BUTTON_Z: bit = PadState::kButtonZ; break;
    case AKEYCODE_ENTER: bit = PadState::kButtonStart; break;
    case AKEYCODE_Z: bit = PadState::kButtonZ; break;
    default: break;
  }
  if (bit == 0) return false;
  SetButton(bit, pressed);
  return true;
}

bool Input::HandleMotion(AInputEvent* event) {
  int32_t source = AInputEvent_getSource(event);
  if ((source & AINPUT_SOURCE_JOYSTICK) != 0) {
    float x = AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_X, 0);
    float y = AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_Y, 0);
    float lt =
        AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_LTRIGGER, 0);
    float rt =
        AMotionEvent_getAxisValue(event, AMOTION_EVENT_AXIS_RTRIGGER, 0);
    state_.stick_x = AxisToStick(x);
    state_.stick_y = AxisToStick(-y);
    SetButton(PadState::kButtonL, lt > 0.5f);
    SetButton(PadState::kButtonR, rt > 0.5f);
    // C-stick (AXIS_Z/RZ) a 0 a proposito en esta fase.
    state_.substick_x = 0;
    state_.substick_y = 0;
    return true;
  }
  if ((source & AINPUT_SOURCE_TOUCHSCREEN) != 0) {
    return HandleTouch(event);
  }
  return false;
}

// Tactil Fase 13: cada evento Android se traduce a eventos del
// layout en fracciones (pixeles / tamano de ventana) y el layout
// decide zona y escribe Held en state_. MOVE recorre TODOS los
// dedos (un MOVE Android trae todas las posiciones, no solo la
// del dedo que se movio); DOWN/UP/CANCEL solo el dedo indice.
// Un dedo que baja fuera de zona no se registra: su MOVE/UP
// posterior tampoco cambia nada (TouchLayout lo ignora).
bool Input::HandleTouch(AInputEvent* event) {
  if (viewport_w_ <= 0 || viewport_h_ <= 0) {
    if (!logged_no_viewport_) {
      logged_no_viewport_ = true;
      SFA_LOGE("input: tactil ignorado, sin tamano de ventana "
               "(SetViewportSize pendiente)");
    }
    return false;
  }
  if (!logged_touch_) {
    logged_touch_ = true;
    SFA_LOGI("input: tactil por layout Fase 13 (stick + botones "
             "en pantalla, C-stick reservado sin mapeo)");
  }
  int32_t action = AMotionEvent_getAction(event);
  int32_t action_code = action & AMOTION_EVENT_ACTION_MASK;
  size_t count = AMotionEvent_getPointerCount(event);
  bool changed = false;
  auto to_frac = [&](size_t i, TouchLayout::TouchEvent& out) {
    out.x = AMotionEvent_getX(event, i) /
            static_cast<float>(viewport_w_);
    out.y = AMotionEvent_getY(event, i) /
            static_cast<float>(viewport_h_);
    out.id = AMotionEvent_getPointerId(event, i);
  };
  // Tramo 6 — BOTON AUDIO ANTES QUE EL JUEGO: un dedo armado
  // por la pildora se consume aqui y nunca llega a TouchLayout
  // (ni como boton ni como stick); un dedo de juego que se
  // deslice hasta la pildora NO la arma (HandleDown exige
  // bajar dentro). Sin esto, la pildora seria solo dibujo.
  if (action_code == AMOTION_EVENT_ACTION_MOVE) {
    for (size_t i = 0; i < count; ++i) {
      TouchLayout::TouchEvent ev{TouchLayout::EventType::kMove, 0, 0, 0};
      to_frac(i, ev);
      if (audio_button_.HandleMove(ev.id, ev.x, ev.y)) {
        changed = true;
        continue;
      }
      // Tramo 20 — pildora surround DESPUES de la de audio
      // (rectangulos disjuntos: el orden entre pildoras no
      // importa) y ANTES que TouchLayout, igual que audio.
      if (surround_button_.HandleMove(ev.id, ev.x, ev.y)) {
        changed = true;
        continue;
      }
      if (touch_.Handle(ev, state_)) changed = true;
    }
    return changed;
  }
  size_t pointer_index =
      static_cast<size_t>((action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK) >>
                          AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT);
  if (pointer_index >= count) return false;
  TouchLayout::TouchEvent ev{TouchLayout::EventType::kUp, 0, 0, 0};
  to_frac(pointer_index, ev);
  if (action_code == AMOTION_EVENT_ACTION_DOWN ||
      action_code == AMOTION_EVENT_ACTION_POINTER_DOWN) {
    ev.type = TouchLayout::EventType::kDown;
    // Pildoras primero: si una la consume, el juego no ve el
    // toque. Audio antes que surround (disjuntas: el orden
    // entre ellas no importa).
    if (audio_button_.HandleDown(ev.id, ev.x, ev.y)) return true;
    if (surround_button_.HandleDown(ev.id, ev.x, ev.y)) return true;
  } else if (action_code == AMOTION_EVENT_ACTION_UP ||
             action_code == AMOTION_EVENT_ACTION_POINTER_UP ||
             action_code == AMOTION_EVENT_ACTION_CANCEL) {
    ev.type = TouchLayout::EventType::kUp;
    if (audio_button_.HandleUp(ev.id, ev.x, ev.y)) return true;
    if (surround_button_.HandleUp(ev.id, ev.x, ev.y)) return true;
  } else {
    return false;
  }
  return touch_.Handle(ev, state_);
}

}  // namespace sfa
