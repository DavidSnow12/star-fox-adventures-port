#pragma once

// Boton "surround" — Tramo 20 (via NATIVA, mismo patron que la
// pildora "anadir audio" del Tramo 6, ver input/audio_button.h).
//
// Por que nativo y no overlay Java: MainActivity es
// NativeActivity sin UI Java (toda la pantalla es la ventana
// nativa); un Button Java necesitaria z-order por encima de
// la superficie EGL y gestion de foco que pausaria el juego
// al perderlo. La via nativa reutiliza tres patrones ya
// probados: fracciones de pantalla (TouchLayout, Fase 13),
// interceptacion en Input antes del layout del juego, y
// preferencia persistida en Java (SharedPreferences) leida
// por JNI (via B del Tramo 16, no el setter JNI directo:
// la JNI no alcanza app->userData y el puntero de proceso
// necesitaria ciclo de vida propio).
//
// QUE ES (y que NO es):
// - Una zona tactil RESERVADA, no un boton de juego: Input la
//   consulta ANTES que TouchLayout (despues de la pildora de
//   audio; los rectangulos son disjuntos, asi que el orden
//   entre pildoras no importa), y un toque que empieza en
//   ella nunca llega a PadState (ni como boton ni como stick).
// - La pildora DIBUJADA usa EXACTAMENTE este rectangulo: el
//   renderer convierte estas mismas constantes (fracciones)
//   a NDC, asi que tactil y dibujo no pueden desalinearse
//   por constantes duplicadas. Sin fuente de texto en GL, la
//   pildora no lleva etiqueta (igual que la de audio antes
//   del Tramo 7): el estado se comunica por COLOR + boot.log
//   (ver GUIA-PRUEBA-GX29.md). La etiqueta textual real queda
//   pendiente del futuro overlay de ajustes; no se finge
//   texto con un dibujo ambiguo.
// - El estado es SOLO presentacion + guarda de disparo: lo
//   escribe native-lib (preferencia Java) y lo lee el
//   renderer. No decide la mezcla: eso lo decide el gate
//   C++ (AudioBridge::SetSurroundEnabled, Tramo 16, OFF por
//   defecto). Con el modo OFF, el PCM es bit-identico al de
//   GX28 (espejo = 1); con ON, el bridge aplica el espejo
//   interp(2-span) en ganancias L/R en note-on y descarta S
//   (Tramo 15: en estereo lastSPan=0 siempre, asi que el
//   modo estereo actual ya es fiel; el modo surround fiel
//   NO necesita matriz DPL porque S se descarta).
//
// RECTANGULO (fracciones, origen arriba-izquierda, igual que
// TouchLayout y que la pildora de audio): x 0.31-0.43,
// y 0.92-0.98, centro inferior, a la IZQUIERDA de la pildora
// de audio (0.44-0.56) con 0.01 de hueco. El candidato
// x 0.30-0.42 fallaba el liston del Tramo 6 (margen >= 0.035
// en aspect 1.6, Tab S8) frente a D-pad abajo (0.255,0.82)
// por 0.0018 (0.0332); desplazado a 0.31-0.43 el margen
// minimo es 0.043 (ver test host del Tramo 20). La banda
// y 0.92-0.98 queda por debajo de todas las zonas de juego
// (maximo: stick 0.72+0.20=0.92 en bruto, D-pad abajo
// 0.82+0.09=0.91, C-stick reservado 0.70+0.20=0.90).
//
// ESTADOS: OFF (gris pizarra) y ON (cian). Sin parpadeo: el
// toggle es inmediato y persistido; no hay estado transitorio
// que comunicar (a diferencia de Verifying en audio).

#include <cstdint>

namespace sfa {

// Rectangulo de la pildora (fracciones de pantalla).
constexpr float kSurroundBtnX0 = 0.31f;
constexpr float kSurroundBtnX1 = 0.43f;
constexpr float kSurroundBtnY0 = 0.92f;
constexpr float kSurroundBtnY1 = 0.98f;

struct SurroundButtonColor {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// Color de la pildora segun estado. Funcion pura (testeable
// en host sin GL): el renderer solo la aplica. Cian y gris
// pizarra no colisionan con ningun color de la pildora de
// audio (ambar / ambar parpadeante / verde / rojo).
inline SurroundButtonColor SurroundButtonColorFor(bool enabled) {
  if (enabled) return SurroundButtonColor{0, 180, 220};  // cian
  return SurroundButtonColor{96, 96, 112};              // gris pizarra
}

class SurroundButton {
 public:
  void Reset() {
    // Solo armado/disparo, igual que AudioButton::Reset():
    // el ESTADO (enabled) lo posee native-lib (preferencia
    // Java) y sobrevive a Reset() del Input (que ocurre en
    // Runtime::Init, antes de que native-lib reaplique la
    // preferencia en INIT_WINDOW). Borrarlo aqui lo dejaria
    // en OFF aunque la preferencia guardada fuese ON.
    armed_pointer_ = -1;
    trigger_pending_ = false;
  }

  bool Enabled() const { return enabled_; }
  void SetEnabled(bool enabled) { enabled_ = enabled; }

  static bool Contains(float x, float y) {
    return x >= kSurroundBtnX0 && x <= kSurroundBtnX1 &&
           y >= kSurroundBtnY0 && y <= kSurroundBtnY1;
  }

  // Devuelve true si el evento queda consumido por la
  // pildora (el llamador NO debe pasarlo a TouchLayout).
  // Down fuera no se registra: su Move/Up posterior tampoco
  // hace nada (igual que TouchLayout con zonas de juego).
  bool HandleDown(int32_t id, float x, float y) {
    if (!Contains(x, y)) return false;
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

  // El bucle nativo lo consume (una sola vez) e invierte la
  // preferencia Java + el gate C++. No se auto-dispara nada
  // desde aqui.
  bool TakeTrigger() {
    if (!trigger_pending_) return false;
    trigger_pending_ = false;
    return true;
  }

  bool TriggerPending() const { return trigger_pending_; }

 private:
  bool enabled_ = false;
  int32_t armed_pointer_ = -1;
  bool trigger_pending_ = false;
};

}  // namespace sfa
