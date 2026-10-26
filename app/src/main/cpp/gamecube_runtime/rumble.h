#pragma once

// Rumble fase A (ver RUMBLE.md, work-port/fase18-tev/): HLE de
// PADControlMotor 0x8024F580 con estado por canal y
// solo-en-transicion, salida por interfaz RumbleSink.
// Fase A = NO-OP + log: el sink por defecto no vibra nada.
// La fase B (Vibrator por JNI) queda fuera, documentada como
// pendiente: la APK inyectara una implementacion real con
// Hle::SetRumbleSink sin tocar el HLE.
//
// Firma libogc: void PADControlMotor(u32 chan, u32 command),
// r3 = chan (0-3), r4 = command (0=STOP, 1=RUMBLE,
// 2=STOP_HARD, identico a STOP a efectos del stub). Sin
// temporizacion en el HLE: la duracion la decide el juego
// (sus wrappers + padUpdate paran cuando toca); si el juego
// pide RUMBLE y nunca pide STOP, vibrar hasta STOP es el
// comportamiento fiel. Sin lectura de SI/EXI: el HLE
// sustituye entero al PADControlMotor del SDK, como ya hace
// PADRead. Solo canal 0 llegaria al vibrador fisico en fase
// B (hay un solo motor); los demas canales se registran
// pero no vibran.

#include <cstdint>

namespace sfa {

// Salida del rumble. El HLE solo conoce la interfaz.
class RumbleSink {
 public:
  virtual ~RumbleSink() = default;
  virtual void SetRumble(int chan, bool on) = 0;
};

// Sink nulo (fase A, host y APK hasta la fase B).
class NullRumbleSink : public RumbleSink {
 public:
  void SetRumble(int /*chan*/, bool /*on*/) override {}
};

// Sink de registro (tests host): guarda la ultima transicion
// por canal y el numero de llamadas al sink.
class RecordingRumbleSink : public RumbleSink {
 public:
  void SetRumble(int chan, bool on) override {
    if (chan < 0 || chan >= 4) return;
    if (state_[chan] != on) {
      state_[chan] = on;
      ++calls_;
    }
    last_chan_ = chan;
    last_on_ = on;
  }
  bool State(int chan) const {
    return chan >= 0 && chan < 4 ? state_[chan] : false;
  }
  int Calls() const { return calls_; }
  int LastChan() const { return last_chan_; }
  bool LastOn() const { return last_on_; }

 private:
  bool state_[4] = {false, false, false, false};
  int calls_ = 0;
  int last_chan_ = -1;
  bool last_on_ = false;
};

// Estado por canal con solo-en-transicion: padUpdate llama
// cada frame, asi que un RUMBLE sostenido no debe re-disparar
// el sink (ni el log) en cada frame. Apply devuelve true
// solo cuando el estado del canal cambia de verdad.
// cmd fuera de {0,1,2} o chan fuera de [0,4): false, sin
// cambio de estado (el llamador registra el aviso).
class RumbleTracker {
 public:
  bool Apply(int chan, int cmd, bool* want_on_out) {
    if (chan < 0 || chan >= 4) return false;
    if (cmd != 0 && cmd != 1 && cmd != 2) return false;
    bool want_on = (cmd == 1);  // RUMBLE; 0 y 2 = STOP
    if (want_on_out != nullptr) *want_on_out = want_on;
    if (on_[chan] == want_on) return false;
    on_[chan] = want_on;
    return true;
  }
  bool IsOn(int chan) const {
    return chan >= 0 && chan < 4 ? on_[chan] : false;
  }

 private:
  bool on_[4] = {false, false, false, false};
};

}  // namespace sfa
