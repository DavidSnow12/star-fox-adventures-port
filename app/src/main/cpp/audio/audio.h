#pragma once

// Audio — Fase 7: backend real detras de la API limpia.
//
// La API que usa el runtime no cambia (Init/Start/Stop/
// SubmitBuffer/SetMasterVolume/Pump): el juego hablara con el
// audio solo por aqui, para que MusyX/DSP real pueda sustituir
// este backend sin tocar el loop.
//
// Backend (decision documentada): AAudio en Android. OpenSL ES
// NO se implementa: minSdk es 26 y AAudio existe desde API 26,
// asi que el caso "AAudio no disponible" no puede ocurrir en
// esta app; un segundo backend seria codigo sin forma de
// probarse aqui (ni en host ni en un dispositivo API 26+).
// Si AAudio falla al abrir en un dispositivo concreto, el
// backend queda en error (BackendOk() = false) y SubmitBuffer
// sigue encolando sin romper el juego; el log lo dira.
// En host (sin Android) el backend es nulo pero contable:
// Pump() drena el anillo y cuenta los frames entregados, asi
// que el test host verifica la cadena completa (WAV ->
// resampleo -> SubmitBuffer -> entrega) sin tarjeta de sonido.
//
// Datos: SubmitBuffer recibe frames estereo s16 a la tasa de
// salida (48.000 Hz). PlayWavFile() es el HLE de alto nivel
// por ID de este paso: carga un WAV PCM16 extraido (streams
// ADP a 32.000 Hz estereo, MusyX mono a su frecuencia de
// inventario), lo resamplea a 48.000 Hz estereo y lo entrega
// por SubmitBuffer. El mapeo ID del juego -> ruta WAV (tablas
// Streams.bin/Sfx.bin y .sdi) NO esta hecho todavia: este paso
// prueba que un ID real (una ruta real del inventario)
// produce salida; el trigger del juego (snd*) es el siguiente.
// Secuencias MusyX (.pro/.poo/midi.wad) y DSP quedan fuera,
// como ordena la tarea.

#include <atomic>
#include <cstdint>
#include <string>
#include <vector>

#if defined(__ANDROID__)
#include <aaudio/AAudio.h>
#endif

namespace sfa {

class Audio {
 public:
  static constexpr int kOutputRate = 48000;

  bool Init();
  void Shutdown();
  void Pump();  // Llamado una vez por frame. En Android no-op
                // (el callback AAudio drena); en host drena el
                // anillo y cuenta la entrega.
  void Start();
  void Stop();
  // frames: numero de frames estereo (no de muestras), a
  // 48.000 Hz. El buffer puede ser nullptr solo si
  // frame_count es 0. Se aplica el volumen maestro.
  void SubmitBuffer(const short* frames, int frame_count);
  void SetMasterVolume(float volume);

  // HLE de alto nivel por fichero WAV real (ver cabecera).
  // Devuelve los frames entregados a 48.000 Hz, o -1 si el
  // fichero no es un WAV PCM16 legible.
  int PlayWavFile(const char* path);

  // Observacion para tests host (y logcat en Android).
  uint64_t SubmittedFrames() const { return submitted_frames_; }
  uint64_t DeliveredFrames() const { return delivered_frames_; }
  uint64_t DroppedFrames() const { return dropped_frames_; }
  bool BackendOk() const { return backend_ok_; }
  const char* BackendName() const { return backend_name_; }
  float MasterVolume() const { return volume_; }

  // WAV PCM16 (cualquier tasa/canales 1-2) en memoria.
  struct WavData {
    int rate = 0;
    int channels = 0;
    // Muestras entrelazadas s16, frames = size / channels.
    std::vector<int16_t> samples;
    uint64_t Frames() const {
      return channels > 0
                 ? static_cast<uint64_t>(samples.size()) /
                       static_cast<uint64_t>(channels)
                 : 0;
    }
  };
  static bool LoadWavFile(const char* path, WavData* out);
  // Resampleo lineal a estereo 48.000 Hz (mono se duplica).
  static std::vector<int16_t> ResampleToStereo(const WavData& in,
                                               int out_rate);

 private:
  // Anillo SPSC (productor: SubmitBuffer; consumidor: callback
  // AAudio o Pump en host). Capacidad en frames estereo.
  static constexpr size_t kRingFrames = 262144;
  std::vector<int16_t> ring_;
  std::atomic<size_t> ring_read_{0};
  std::atomic<size_t> ring_write_{0};
  size_t RingAvailable() const;
  size_t RingFree() const;
  // Drena hasta max_frames del anillo a out (estereo s16).
  // Devuelve los frames realmente drenados.
  size_t Drain(int16_t* out, size_t max_frames);

  float volume_ = 1.0f;
  bool started_ = false;
  bool backend_ok_ = false;
  const char* backend_name_ = "none";
  uint64_t submitted_frames_ = 0;
  uint64_t delivered_frames_ = 0;
  uint64_t dropped_frames_ = 0;
#if defined(__ANDROID__)
  AAudioStream* stream_ = nullptr;
  static aaudio_data_callback_result_t DataCallback(
      AAudioStream* stream, void* user_data, void* audio_data,
      int32_t num_frames);
  bool OpenStream(aaudio_sharing_mode_t sharing);
#endif
};

}  // namespace sfa
