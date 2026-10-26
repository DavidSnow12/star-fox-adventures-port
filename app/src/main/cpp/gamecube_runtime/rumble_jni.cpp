// Sink Vibrator real, fase B. Ver rumble_jni.h para la
// decision (nativo -> Java por JNI, mismo patron que SAF)
// y el doble anti-spam (tracker + filtro del sink).

#include "gamecube_runtime/rumble_jni.h"

#include "log.h"

namespace sfa {

void JniVibratorSink::SetRumble(int chan, bool on) {
  // Solo el canal 0 mueve el motor fisico; los demas no
  // llegan a Java en absoluto (ni siquiera una llamada).
  if (!RumbleChanDrivesMotor(chan)) return;
  // Segunda capa anti-spam: mismo estado ya enviado -> sin
  // llamada binder. El tracker ya filtra lo normal; esto
  // cubre llamadas directas al sink fuera del HLE.
  if (sent_ && last_on_ == on) return;
  if (!Ready()) return;
  if (CallJava("setRumble", "(Z)V", on, true)) {
    sent_ = true;
    last_on_ = on;
  }
  // Si la llamada fallo (sin JVM, metodo ausente,
  // excepcion Java), no se marca como enviada: el proximo
  // cambio de estado lo reintentara, y la cancelacion de
  // ciclo de vida no depende de este flag.
}

void JniVibratorSink::CancelAll() {
  // Siempre intentar cancelar en Java, aunque sent_ diga
  // que no hay nada enviado: la garantia de pausa/cierre
  // no puede depender del estado recordado. Despues, el
  // proximo ON debe volver a llamar a Java.
  if (Ready()) {
    if (!CallJava("cancelRumble", "()V", false, false)) {
      SFA_LOGE("rumble: cancelRumble JNI fallo (ver logcat)");
    }
  }
  sent_ = false;
  last_on_ = false;
}

bool JniVibratorSink::CallJava(const char* method, const char* sig,
                               bool arg, bool has_arg) {
  if (vm_ == nullptr || activity_ == nullptr ||
      activity_->clazz == nullptr) {
    return false;
  }
  JNIEnv* env = nullptr;
  bool attached = false;
  if (vm_->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) !=
      JNI_OK) {
    if (vm_->AttachCurrentThread(&env, nullptr) != JNI_OK ||
        env == nullptr) {
      SFA_LOGE("rumble: no se pudo asociar el hilo a la JVM");
      return false;
    }
    attached = true;
  }
  bool ok = false;
  jclass cls = env->GetObjectClass(activity_->clazz);
  if (cls != nullptr) {
    jmethodID mid = env->GetMethodID(cls, method, sig);
    if (mid != nullptr) {
      if (has_arg) {
        env->CallVoidMethod(activity_->clazz, mid,
                            static_cast<jboolean>(arg ? JNI_TRUE
                                                      : JNI_FALSE));
      } else {
        env->CallVoidMethod(activity_->clazz, mid);
      }
      if (env->ExceptionCheck()) {
        env->ExceptionClear();
        SFA_LOGE("rumble: excepcion Java en %s", method);
      } else {
        ok = true;
      }
    } else {
      SFA_LOGE("rumble: metodo Java %s no encontrado", method);
    }
    env->DeleteLocalRef(cls);
  }
  if (attached) vm_->DetachCurrentThread();
  return ok;
}

}  // namespace sfa
