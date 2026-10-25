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
  logged_touch_ = false;
  touch_active_ = false;
  touch_id_ = -1;
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
    if (!logged_touch_) {
      logged_touch_ = true;
      SFA_LOGI("input: primer evento tactil (mitad izquierda = "
               "stick, botones tactiles pendientes de layout)");
    }
    int32_t action = AMotionEvent_getAction(event);
    int32_t action_code = action & AMOTION_EVENT_ACTION_MASK;
    size_t pointer_index =
        static_cast<size_t>((action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK) >>
                            AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT);
    size_t count = AMotionEvent_getPointerCount(event);
    if (pointer_index >= count) return false;
    int32_t id = AMotionEvent_getPointerId(event, pointer_index);
    // Primer dedo = stick (arrastre desde el apoyo). No hay
    // division por mitades todavia: sin ancho de ventana en
    // este modulo, un criterio "mitad izquierda" seria
    // arbitrario; los botones tactiles quedan pendientes de
    // un layout en pantalla explicito.
    if (action_code == AMOTION_EVENT_ACTION_DOWN ||
        action_code == AMOTION_EVENT_ACTION_POINTER_DOWN) {
      touch_active_ = true;
      touch_id_ = id;
      touch_anchor_x_ = AMotionEvent_getX(event, pointer_index);
      touch_anchor_y_ = AMotionEvent_getY(event, pointer_index);
      return true;
    }
    if (touch_active_ && id == touch_id_) {
      if (action_code == AMOTION_EVENT_ACTION_MOVE) {
        float dx =
            (AMotionEvent_getX(event, pointer_index) - touch_anchor_x_) /
            100.0f;
        float dy =
            (AMotionEvent_getY(event, pointer_index) - touch_anchor_y_) /
            100.0f;
        state_.stick_x = AxisToStick(dx);
        state_.stick_y = AxisToStick(-dy);
        return true;
      }
      if (action_code == AMOTION_EVENT_ACTION_UP ||
          action_code == AMOTION_EVENT_ACTION_POINTER_UP ||
          action_code == AMOTION_EVENT_ACTION_CANCEL) {
        touch_active_ = false;
        touch_id_ = -1;
        state_.stick_x = 0;
        state_.stick_y = 0;
        return true;
      }
    }
    return false;
  }
  return false;
}

}  // namespace sfa
