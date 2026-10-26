#pragma once

// Sink Vibrator real, fase B (solo Android; no se compila en
// los tests host, que usan RecordingRumbleSink).
//
// Decision: nativo -> Java por JNI, NO Java Activity con
// callback inverso ni cambio de Activity. Motivo: el patron
// ya existe y esta probado en esta base (RequestSafPicker en
// native-lib.cpp: vm + clazz de NativeActivity, asociacion
// del hilo si hace falta, GetMethodID + CallVoidMethod). Un
// cambio a Java Activity + SurfaceView es la decision
// pendiente de la siguiente iteracion (ver README de la
// base) y no hace falta para vibrar: Vibrator.vibrate()
// y cancel() son llamadas binder seguras fuera del hilo UI,
// asi que Java NO necesita runOnUiThread aqui (al reves
// que el picker SAF, que si lo necesita para
// startActivityForResult).
//
// Cableado: Hle -> RumbleTracker (solo-en-transicion) ->
// JniVibratorSink::SetRumble(chan, on) -> MainActivity.
// Solo chan 0 llega a Java (RumbleChanDrivesMotor); los
// demas canales no hacen ni una llamada JNI. Anti-spam en
// dos capas: el tracker ya solo llama en transicion, y el
// sink ademas ignora un SetRumble repetido con el mismo
// estado (sent_/last_on_): un juego que repita RUMBLE sin
// pasar por el tracker (no ocurre hoy) tampoco re-dispara
// la llamada binder. CancelAll() ignora ese filtro a
// proposito: siempre intenta cancelar en Java, para que el
// camino de pausa/cierre no dependa de lo que el sink cree
// haber enviado, y resetea sent_ para que el siguiente ON
// tras reanudar vuelva a vibrar.
//
// Propiedad: el sink guarda JavaVM* y ANativeActivity* (los
// dos viven toda la vida del proceso: la JVM y la actividad
// del glue). NO guarda un global ref propio ni lo borra:
// copiar el patron SAF evita un ref que habria que liberar
// desde un hilo que puede no estar asociado al salir.
// Init() solo guarda punteros, no llama a Java: en el
// arranque no vibra nada.

#include <android/native_activity.h>
#include <jni.h>

#include "gamecube_runtime/rumble.h"

namespace sfa {

class JniVibratorSink : public RumbleSink {
 public:
  void Init(JavaVM* vm, ANativeActivity* activity) {
    vm_ = vm;
    activity_ = activity;
  }
  bool Ready() const { return vm_ != nullptr && activity_ != nullptr; }

  void SetRumble(int chan, bool on) override;
  void CancelAll() override;

 private:
  // Llama a un metodo de MainActivity. has_arg=false ->
  // firma "()V"; true -> "(Z)V" con arg. Devuelve false si
  // no hay JVM/actividad, si falta el metodo o si Java
  // lanzo excepcion (limpiada, sin crash nativo). Asocia el
  // hilo a la JVM si hace falta y lo desasocia despues,
  // como RequestSafPicker.
  bool CallJava(const char* method, const char* sig, bool arg,
                bool has_arg);

  JavaVM* vm_ = nullptr;
  ANativeActivity* activity_ = nullptr;
  // Ultimo estado enviado a Java (solo chan 0). sent_=false
  // significa "sin estado enviado / cancelado": el proximo
  // ON debe llamar a Java aunque last_on_ diga lo mismo.
  bool sent_ = false;
  bool last_on_ = false;
};

}  // namespace sfa
