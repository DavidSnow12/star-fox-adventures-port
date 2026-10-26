// Rumble fase A + B (ver RUMBLE_FASE_B.md, work-port/tramo5-rumble/):
// HLE de PADControlMotor 0x8024F580 con estado por canal y
// solo-en-transicion, salida por interfaz RumbleSink.
//
// Fase A (hecha): el HLE despacha y el sink por defecto es nulo
// (no-op + log). Fase B (este fichero + rumble_jni.* +
// MainActivity): el sink real es JniVibratorSink, que llama por
// JNI a MainActivity.setRumble()/cancelRumble() (mismo patron
// nativo->Java que el picker SAF de native-lib.cpp, sin cambiar
// a Java Activity: NativeActivity ya expone vm + clazz y el
// hilo del juego se asocia a la JVM si hace falta).
//
// Firma libogc: void PADControlMotor(u32 chan, u32 command),
// r3 = chan (0-3), r4 = command (0=STOP, 1=RUMBLE,
// 2=STOP_HARD, identico a STOP a efectos del stub). Sin
// temporizacion en el HLE: la duracion la decide el juego
// (sus wrappers + padUpdate paran cuando toca); si el juego
// pide RUMBLE y nunca pide STOP, vibrar hasta STOP es el
// comportamiento fiel. Por eso Java usa una onda repetida
// indefinidamente (createWaveform({0, 1000}, repeat=0)) que
// solo Vibrator.cancel() detiene, no un one-shot con
// duracion inventada. Sin lectura de SI/EXI: el HLE
// sustituye entero al PADControlMotor del SDK, como ya hace
// PADRead. Solo el canal 0 llega al vibrador fisico (hay un
// solo motor); los demas canales se registran en el tracker
// pero el sink JNI los ignora sin llamar a Java (ver
// RumbleChanDrivesMotor). La cancelacion en pausa/cierre
// vive en dos capas independientes (ver Hle::StopAllRumble
// y MainActivity.onPause/onDestroy): cualquiera de las dos
// basta para que el motor no quede vibrando al salir.

#pragma once

#include <cstdint>

namespace sfa {

// Salida del rumble. El HLE solo conoce la interfaz.
class RumbleSink {
 public:
  virtual ~RumbleSink() = default;
  virtual void SetRumble(int chan, bool on) = 0;
  // Detiene todo rumble, sin depender del estado que el sink
  // crea haber enviado: es el camino de cancelacion de
  // ciclo de vida (pausa/cierre), no una transicion del
  // juego. Implementacion por defecto: OFF en los 4 canales
  // (los sinks que solo cuentan transiciones, como el de
  // registro, solo contaran los canales que estaban ON).
  // JniVibratorSink la sobreescribe con un solo
  // Vibrator.cancel() en Java, sin pasar por los canales.
  virtual void CancelAll() {
    for (int chan = 0; chan < 4; ++chan) SetRumble(chan, false);
  }
};

// Sink nulo (fase A, host y APK sin sink JNI inyectado).
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

// Regla de cableado fisico, compartida por el sink JNI y los
// tests host (sin deps Android): un solo motor en el
// dispositivo, asi que solo el canal 0 (mando del jugador)
// lo mueve. Los canales 1-3 existen en el tracker y en el
// log, pero nunca llegan a Java.
inline bool RumbleChanDrivesMotor(int chan) { return chan == 0; }

// Estado por canal con solo-en-transicion: padUpdate llama
// cada frame, asi que un RUMBLE sostenido no debe re-disparar
// el sink (ni el log) en cada frame. Apply devuelve true
// solo cuando el estado del canal cambia de verdad.
// cmd fuera de {0,1,2} o chan fuera de [0,4): false, sin
// cambio de estado (el llamador registra el aviso).
// Reset() vacia el estado (camino de pausa/cierre): tras
// el, el siguiente RUMBLE del juego vuelve a ser una
// transicion y re-vibra, en vez de quedarse mudo porque el
// tracker creia seguir ON tras una cancelacion hardware.
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
  void Reset() {
    for (int i = 0; i < 4; ++i) on_[i] = false;
  }

 private:
  bool on_[4] = {false, false, false, false};
};

}  // namespace sfa
