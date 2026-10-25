#include "input/input.h"

#include "log.h"

namespace sfa {

void Input::Reset() { logged_touch_ = false; }

bool Input::HandleEvent(AInputEvent* event) {
  if (event == nullptr) return false;
  if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION &&
      !logged_touch_) {
    logged_touch_ = true;
    SFA_LOGI("input: primer evento tactil recibido (mapeo a mando pendiente)");
  }
  return false;
}

}  // namespace sfa
