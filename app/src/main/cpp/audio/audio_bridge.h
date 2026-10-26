#pragma once

// Bridge ID -> WAV (Fase 14): conecta las peticiones de sonido
// del juego con el backend Audio ya definido (AAudio en Android,
// nulo contable en host), sin tocar el loop del juego.
//
// Como se cablea: el chassis avisa en la entrada de las
// funciones de audio (hook opcional, ver chassis.h) y el
// bridge traduce el ID a WAV con la tabla generada
// (audio_id_map.h, desde Streams.bin/Sfx.bin + inventario).
// El codigo huesped sigue corriendo integro: el bridge es
// sonido sombra (el estado del juego no se toca), igual que
// el backend AAudio no cambia la logica del juego.
//
// Que reproduce (verificado en esta fase):
//   - AudioStream_Play (r3 = id de stream, verificado en el
//     codigo huesped): WAV ADP extraido, 32.000 Hz estereo.
//   - AudioStream_StopCurrent: detiene la reproduccion en
//     curso (la del bridge, no la del juego).
// Que SOLO cuenta (sin reproducir): sndFXStartEx,
// sndSeqPlayEx, AudioStream_StartPrepared y cualquier otra
// entrada, porque su layout de argumentos NO esta verificado
// en esta fase; inventar un trigger seria sonar mal con
// cara de correcto. Sus IDs quedan en CountedEntries() para
// la traza, no en PlayedEntries().
// Que NO hace: mezcla (una sola cola: los sonidos se sirven
// en orden de llegada; un stream largo y un SFX a la vez
// sonaran en serie, no mezclados), bucles (los WAV se
// decodifican una sola pasada, como en la extraccion) ni
// DSP/MusyX real (secuencias .pro/.poo y midi.wad: fuera,
// ver PORT-STATUS Fase 14).
//
// Sin WAV (APK sin payload de audio): las busquedas fallan
// en la tabla o en LoadWavFile y quedan como no resueltas,
// sin crashear y sin tocar el juego. En Android el wav_root
// es <base>/sfa-data/audio (ver native-lib); en host, la
// carpeta assets/extraidos/audio del repo.

#include <cstdint>
#include <string>
#include <vector>

#include "audio/audio.h"

namespace sfa {

class AudioBridge {
 public:
  // Audio debe estar Init() + Start() antes de usar el bridge
  // (en el runtime lo hace GameCubeRuntime::Init; en el test
  // host lo hace el propio test). El bridge no posee Audio.
  void SetAudio(Audio* audio) { audio_ = audio; }
  void SetWavRoot(const char* root) {
    wav_root_ = root != nullptr ? root : "";
  }

  // Entradas del hook del chassis (pc + r3/r4/r5 del juego).
  // Devuelve true si la entrada produjo reproduccion.
  bool OnAudioEntry(uint32_t pc, uint32_t r3, uint32_t r4,
                    uint32_t r5);

  // API directa (misma que usa el hook; el test host la usa
  // para verificar la cadena sin depender del juego).
  bool OnStreamPlay(uint32_t stream_id);
  void OnStreamStop();
  // Trigger SFX por id de Sfx.bin: encola los WAV de sus
  // campos de muestra no nulos, en orden. Devuelve el numero
  // de muestras encoladas (0 = trigger sin muestra directa
  // o id desconocido; ver UnresolvedEntries()).
  int OnSfxTrigger(uint32_t trigger_id);

  // Avance de reproduccion: alimenta hasta kFeedFrames por
  // llamada desde la cola al backend. En host el test llama
  // a Tick() + Audio::Pump() en bucle hasta vaciar; en la
  // APK lo llama GameCubeRuntime::Frame() (el callback
  // AAudio drena en paralelo).
  void Tick();

  struct Played {
    uint32_t id = 0;
    const char* kind = nullptr;  // "stream" o "sfx_muestra"
    std::string wav;
    int src_rate = 0;
    int src_channels = 0;
    uint64_t frames_48k = 0;
  };
  struct Counted {
    uint32_t pc = 0;
    uint32_t r3 = 0;
  };
  struct Unresolved {
    uint32_t id = 0;
    const char* kind = nullptr;  // "stream" o "sfx_trigger"
  };

  const std::vector<Played>& PlayedEntries() const { return played_; }
  const std::vector<Counted>& CountedEntries() const {
    return counted_;
  }
  const std::vector<Unresolved>& UnresolvedEntries() const {
    return unresolved_;
  }
  // Frames pendientes en la cola (0 = todo entregado al
  // backend, sin contar lo que el backend aun no dreno).
  uint64_t QueuedFrames() const { return queued_frames_; }
  bool QueueEmpty() const { return queue_.empty(); }

 private:
  static constexpr int kFeedFrames = 4096;

  struct Queued {
    std::vector<int16_t> pcm;  // Estereo s16 a 48.000 Hz.
    size_t pos = 0;            // Frames ya entregados.
  };

  const char* LookupStreamWav(uint32_t id) const;
  const char* LookupSampleWav(uint32_t id) const;
  // Carga un WAV relativo a wav_root_, lo resamplea a
  // estereo 48.000 Hz y lo encola. Registra Played o
  // Unresolved segun el caso. Devuelve false si no se pudo.
  bool EnqueueWav(const char* rel, uint32_t id, const char* kind);

  Audio* audio_ = nullptr;
  std::string wav_root_;
  std::vector<Queued> queue_;
  uint64_t queued_frames_ = 0;
  std::vector<Played> played_;
  std::vector<Counted> counted_;
  std::vector<Unresolved> unresolved_;
};

}  // namespace sfa
