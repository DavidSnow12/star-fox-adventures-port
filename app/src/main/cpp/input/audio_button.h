#pragma once

// Boton "anadir audio" — Tramo 6 (via NATIVA, ver TRAMO6-INFORME.md).
//
// Por que nativo y no overlay Java ni Activity Java completa:
// NativeActivity no tiene UI Java y su ventana la posee el glue
// nativo. Un Button Java anadido por WindowManager/addContentView
// necesitaria z-order por encima de la superficie EGL, banderas
// de foco exactas (NOT_FOCUSABLE + NOT_TOUCH_MODAL) y gestion
// en TERM_WINDOW; si el foco se pierde, el bucle nativo deja de
// ejecutar frames (has_focus=false) y el juego se pausaria al
// tocar el boton: un modo de regresion que NINGUN test host
// puede detectar (necesita dispositivo). Una Activity Java
// completa (Activity + GLSurfaceView en vez de NativeActivity)
// obligaria a reescribir el glue (android_main, ciclo de vida,
// EGL del renderer): fuera de alcance de este tramo y con
// riesgo de romper la base que hoy arranca. La via nativa
// reutiliza tres patrones ya probados: fracciones de pantalla
// (TouchLayout, Fase 13), interceptacion en Input antes del
// layout del juego, y polling por marcadores cada 128 vueltas
// (PollSafResult, Fase 13). Su geometria SI es verificable en
// host, que es lo que cubre el test de este tramo.
//
// QUE ES (y que NO es):
// - Una zona tactil RESERVADA, no un boton de juego: Input la
//   consulta ANTES que TouchLayout, y un toque que empieza en
//   ella nunca llega a PadState (ni como boton ni como stick).
// - La pildora DIBUJADA usa EXACTAMENTE este rectangulo: el
//   renderer convierte estas mismas constantes (fracciones)
//   a NDC, asi que tactil y dibujo no pueden desalinearse por
//   constantes duplicadas. Sin fuente de texto en GL, la
//   pildora no lleva etiqueta: el estado se comunica por
//   COLOR (ver AudioButtonColor) + boot.log. La etiqueta
//   textual real queda pendiente del futuro overlay de
//   ajustes (ver informe, pendiente P1); no se finge texto
//   con un dibujo ambiguo.
// - El estado es SOLO presentacion + guarda anti-doble-pulso:
//   lo escribe native-lib (sondeo de marcadores) y lo lee el
//   renderer. No decide si hay audio: eso lo deciden los
//   marcadores Java (.saf-audio-done/.saf-audio-error) y el
//   escaneo inicial de audio/ (ver native-lib.cpp).
//
// RECTANGULO (fracciones, origen arriba-izquierda, igual que
// TouchLayout): x 0.44-0.56, y 0.92-0.98, centro inferior.
// Por que ahi y no en la franja superior (geometricamente
// mas libre, margen 0,30 en y=0,04): la app usa
// Theme.NoTitleBar.Fullscreen SIN banderas immersive-sticky
// (ni el manifiesto ni native-lib las fijan), asi que un
// boton en y<0,08 compite con el gesto de sistema de la
// barra superior y su toque puede ser robado por el sistema.
// El centro inferior, en cambio, esta fuera de toda zona de
// juego con margen >=0,035 unidades de alto en aspect 1,6
// (Tab S8, 2560x1600) y 1,778 (16:9) — verificado en el test
// host contra TODAS las zonas Fase 13 (botones r=0,09,
// stick r=0,20, C-stick reservado r=0,20); el factor
// limitante es la C-stick reservada (margen ~0,040). En la
// Tab S8 la pildora mide 307x96 px (0,12*2560 x 0,06*1600),
// y NO solapa el quad damero (-0,8..0,8 NDC: la pildora
// queda en -0,84..-0,96 NDC, debajo de el).
// La zona NO roba juego porque: (1) es disjunta de las zonas
// de juego (margen >0, nunca un toque de juego cae dentro);
// (2) la interceptacion es solo para dedos que BAJAN dentro
// (un dedo de juego que se desliza hasta la pildora NO la
// dispara: el armado exige Down dentro); (3) soltar fuera
// cancela sin disparar.
//
// ESTADOS (los que pide la tarea, ni uno mas):
//   kNoAudio   — sin audio/ o sin .saf-audio-done (color ambar)
//   kVerifying — picker pedido, copia/verificacion en curso:
//                los toques en la pildora se tragan sin
//                re-disparar (anti-doble-pulso). Color ambar
//                parpadeante (el renderer alterna cada 30
//                frames; la funcion pura recibe blink_on).
//   kReady     — .saf-audio-done visto (color verde). Pulsar
//                de nuevo REABRE el picker (anadir/sustituir
//                audio): es deliberado, no un error.
//   kError     — .saf-audio-error visto, o picker no
//                disponible al pulsar (color rojo).
// Verifying es volatil por ejecucion (nunca persistido): si
// la app se cierra a mitad de copia, al arrancar el estado
// se rederiva (done -> Ready; audio/ con medios -> Ready;
// si no, NoAudio). Nunca hay un Verifying atascado.
//
// Sin dependencias Android ni GL: solo fracciones y un enum.
// El dibujo GL vive en Renderer/GxGlRenderer; la logica de
// sondeo y el JNI, en native-lib.cpp; la copia, en Java.

#include <cstdint>

namespace sfa {

// Rectangulo de la pildora (fracciones de pantalla).
constexpr float kAudioBtnX0 = 0.44f;
constexpr float kAudioBtnX1 = 0.56f;
constexpr float kAudioBtnY0 = 0.92f;
constexpr float kAudioBtnY1 = 0.98f;

enum class AudioState {
  kNoAudio = 0,
  kVerifying = 1,
  kReady = 2,
  kError = 3,
};

struct AudioButtonColor {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// Color de la pildora segun estado. Funcion pura (testeable
// en host sin GL): el renderer solo la aplica. Verifying
// parpadea: blink_on=true -> ambar, false -> fondo oscuro.
inline AudioButtonColor AudioButtonColorFor(AudioState state, bool blink_on) {
  switch (state) {
    case AudioState::kNoAudio:
      return AudioButtonColor{255, 176, 0};  // ambar
    case AudioState::kVerifying:
      return blink_on ? AudioButtonColor{255, 176, 0}
                      : AudioButtonColor{32, 32, 48};
    case AudioState::kReady:
      return AudioButtonColor{0, 200, 80};  // verde
    case AudioState::kError:
      return AudioButtonColor{220, 40, 40};  // rojo
  }
  return AudioButtonColor{255, 176, 0};
}

inline const char* AudioStateName(AudioState state) {
  switch (state) {
    case AudioState::kNoAudio: return "sin audio";
    case AudioState::kVerifying: return "verificando";
    case AudioState::kReady: return "audio listo";
    case AudioState::kError: return "error";
  }
  return "sin audio";
}

class AudioButton {
 public:
  void Reset() {
    // Solo armado/disparo: el ESTADO lo posee native-lib
    // (sondeo) y sobrevive a Reset() del Input (que ocurre
    // en Runtime::Init, antes de que native-lib rederive el
    // estado en INIT_WINDOW). Borrar el estado aqui lo
    // dejaria en NoAudio aunque hubiera audio.
    armed_pointer_ = -1;
    trigger_pending_ = false;
  }

  AudioState State() const { return state_; }
  void SetState(AudioState state) { state_ = state; }

  static bool Contains(float x, float y) {
    return x >= kAudioBtnX0 && x <= kAudioBtnX1 && y >= kAudioBtnY0 &&
           y <= kAudioBtnY1;
  }

  // Devuelve true si el evento queda consumido por la
  // pildora (el llamador NO debe pasarlo a TouchLayout).
  // Down fuera no se registra: su Move/Up posterior tampoco
  // hace nada (igual que TouchLayout con zonas de juego).
  bool HandleDown(int32_t id, float x, float y) {
    if (!Contains(x, y)) return false;
    if (state_ == AudioState::kVerifying) {
      // Tragado sin armar: anti-doble-pulso durante la copia.
      // No se dispara otro picker encima del que ya corre
      // (Java tambien guarda audioRunning, doble guarda).
      return true;
    }
    if (armed_pointer_ != -1) return true;  // un solo dedo arma
    armed_pointer_ = id;
    return true;
  }

  bool HandleMove(int32_t id, float x, float y) {
    if (armed_pointer_ == -1 || id != armed_pointer_) return false;
    if (!Contains(x, y)) {
      // Deslizar fuera cancela: soltar fuera NO dispara.
      armed_pointer_ = -1;
    }
    return true;
  }

  bool HandleUp(int32_t id, float x, float y) {
    if (armed_pointer_ == -1 || id != armed_pointer_) return false;
    armed_pointer_ = -1;
    if (Contains(x, y)) trigger_pending_ = true;
    return true;
  }

  // El bucle nativo lo consume (una sola vez) y lanza el
  // picker SAF. No se auto-dispara nada desde aqui.
  bool TakeTrigger() {
    if (!trigger_pending_) return false;
    trigger_pending_ = false;
    return true;
  }

  bool TriggerPending() const { return trigger_pending_; }

 private:
  AudioState state_ = AudioState::kNoAudio;
  int32_t armed_pointer_ = -1;
  bool trigger_pending_ = false;
};

}  // namespace sfa
