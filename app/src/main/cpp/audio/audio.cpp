#include "audio/audio.h"

#include "log.h"

namespace sfa {

bool Audio::Init() {
  SFA_LOGI("audio: stub inicializado (sin sonido todavia, MusyX pendiente)");
  return true;
}

void Audio::Shutdown() {}

void Audio::Start() {
  SFA_LOGI("audio: Start (stub, sin backend AAudio/OpenSL todavia)");
}

void Audio::Stop() {}

void Audio::SubmitBuffer(const short* /*frames*/, int /*frame_count*/) {
  // STUB: se descarta. El backend real (AAudio/OpenSL, 2 canales,
  // ring buffer) sustituirá este método sin tocar el loop.
}

void Audio::SetMasterVolume(float /*volume*/) {}

void Audio::Pump() {
  // STUB: sin mezcla todavía. No se registra cada frame para no
  // inundar el log; el primer arranque ya quedó en Init().
}

}  // namespace sfa
