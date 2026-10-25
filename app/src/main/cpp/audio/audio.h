#pragma once

// Audio — STUB de la base.
//
// El audio real del juego es MusyX/DSP (muestras ya extraídas a WAV
// en el repo), y su emulación (DSP, mezcla, streams ADP/DTK) es un
// bloque entero por sí solo. Este stub solo define la interfaz que
// usará el runtime (Init/Pump/Shutdown) para que la integración no
// tenga que tocar el loop principal después.

namespace sfa {

class Audio {
 public:
  bool Init();
  void Shutdown();
  void Pump();  // Llamado una vez por frame.

  // API limpia del backend (aportación de la IA de GitHub, integrada
  // como stub): el juego hablará con el audio solo por aquí, para
  // que MusyX/DSP real pueda sustituir este backend sin tocar el
  // loop. En esta base son no-op con log; no hay sonido todavía.
  void Start();
  void Stop();
  // frames: número de frames estéreo (no de muestras). El buffer
  // puede ser nullptr en el stub.
  void SubmitBuffer(const short* frames, int frame_count);
  void SetMasterVolume(float volume);
};

}  // namespace sfa
