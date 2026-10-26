#pragma once

// Bridge ID -> WAV (Fases 14, 16, 17): conecta las peticiones
// de sonido del juego con el backend Audio ya definido
// (AAudio en Android, nulo contable en host), sin tocar el
// loop del juego.
//
// Como se cablea: el chassis avisa en la entrada de las
// funciones de audio (hook opcional, ver chassis.h) y el
// bridge traduce el ID a WAV con la tabla generada
// (audio_id_map.h, desde Streams.bin/Sfx.bin + inventario).
// El codigo huesped sigue corriendo integro: el bridge es
// sonido sombra (el estado del juego no se toca), igual que
// el backend AAudio no cambia la logica del juego.
//
// Que reproduce (verificado):
//   - AudioStream_Play (r3 = id de stream, verificado en el
//     codigo huesped): WAV ADP extraido, 32.000 Hz estereo.
//   - AudioStream_StopCurrent: detiene SOLO la voz de
//     stream (los SFX siguen; Fase 17 corrige el vaciado
//     total de la cola serial anterior).
//   - Triggers SFX por id de Sfx.bin: UNA variante por
//     disparo (Fase 16: los 4 campos son variantes
//     alternativas por pesos, no 4 sonidos), ganancia
//     vol_base/127 (el volumen maestro lo aplica
//     Audio::SubmitBuffer, no el bridge, para no
//     aplicarlo dos veces).
// Que SOLO cuenta (sin reproducir): sndSeqPlayEx,
// AudioStream_StartPrepared y cualquier otra entrada, porque
// no es un fichero de audio (sndSeqPlayEx: secuenciador
// .pro/.poo + midi.wad) o su layout no está verificado.
// Sus IDs quedan en CountedEntries() para la traza, no en
// PlayedEntries(). sndFXStartEx YA reproduce desde la
// Fase 18 (OnFxStart, tabla FX verificada), no solo cuenta.
// Mezcla (Fase 17): 8 voces SFX + 1 voz de stream, en
// PARALELO (no en serie): Tick() mezcla un bloque de
// hasta kFeedFrames sumando en int32 por frame y con
// clamp duro a int16 (sin wrap, sin normalización por
// nº de voces, sin compresor). Si las 8 voces SFX están
// ocupadas, el nuevo SFX se DESCARTA y se cuenta en
// DroppedSfx() (el robo por antigüedad/volumen es el
// paso siguiente, una vez medido qué voces conviven en
// trazas reales). La voz de stream es única: un nuevo
// Play la sustituye (el juego tiene un solo stream
// actual), no se encola detrás.
// Bucles (Fase 17): por metadato del inventario
// (audio_id_map.h, loop_start/loop_len en frames de la
// fuente, reescalados a 48 kHz al encolar; 321/1472
// muestras MusyX, 0/958 streams). Al llegar a
// loop_start + loop_len, la posición vuelve a
// loop_start (se repite la región, NO se reinicia
// desde 0); la cola tras el fin del bucle nunca se
// alcanza en bucle. La voz en bucle solo para por
// stop/robo, nunca por EOF. Sin bucle, termina en EOF.
// NO se infieren flags FX (bits 0xC000 de
// synthStartSound, probablemente tipo de muestra/bucle,
// sin verificar).
//
// Sin WAV (APK sin payload de audio): las busquedas fallan
// en la tabla o en LoadWavFile y quedan como no resueltas,
// sin crashear y sin tocar el juego. En Android el wav_root
// es <base>/sfa-data/audio (ver native-lib); en host, la
// carpeta assets/extraidos/audio del repo.

#include <array>
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

  // Entradas del hook del chassis (pc + r3/r4/r5/r6/r7 del
  // juego). Devuelve true si la entrada produjo
  // reproduccion. Fase 16: r6/r7 llegan desde el chassis
  // (sndFXStartEx usa r6 como indice de tabla;
  // sndSeqPlayEx reenvia r7). Hoy se registran en
  // CountedEntries con r3; su uso para resolver FX queda
  // pendiente de la tabla FX (ver PORT-STATUS).
  bool OnAudioEntry(uint32_t pc, uint32_t r3, uint32_t r4,
                    uint32_t r5, uint32_t r6 = 0, uint32_t r7 = 0);

  // API directa (misma que usa el hook; el test host la usa
  // para verificar la cadena sin depender del juego).
  bool OnStreamPlay(uint32_t stream_id);
  void OnStreamStop();  // Solo la voz de stream (Fase 17).
  void OnSfxStop();     // Solo las voces SFX (futuros hooks).
  // Trigger SFX por id de Sfx.bin: encola UNA variante
  // (la primera no nula; ver comentario Fase 16 en el .cpp).
  // Devuelve 1 si se encoló, 0 si no (sin muestra directa,
  // id desconocido, WAV ilegible o voces llenas).
  // NOTA Fase 18: este helper de test trata el campo de
  // Sfx.bin como ID de muestra directo, y la Fase 18
  // demostró que ese campo es un ID FX (ver OnFxStart).
  // El camino REAL del juego no pasa por aquí: pasa por
  // sndFXStartEx -> OnFxStart. Corregir este helper para
  // que pase por la tabla FX y actualizar los tests
  // Fase 16/17 (que fijan muestra 175 / 79068 frames para
  // trigger 13) queda como trabajo pendiente documentado,
  // no se hace aquí para no romper la suite validada.
  int OnSfxTrigger(uint32_t trigger_id);

  // SFX real por ID FX (Fase 18, hook sndFXStartEx
  // 0x80273218): fxId = r3&0xFFFF, volume = r4&0xFF
  // (0xFF -> volumen del descriptor, 127), pan = r5&0xFF
  // (0xFF -> panning del descriptor, 64; hoy solo se
  // registra, no se aplica ley de paneo), studio = r6&0xFF
  // (r7 se IGNORA: basura del llamador, no es el ITD).
  // Resuelve fxId -> muestra por fx_table.h (NO identidad:
  // macro == fxId en 0/833) y encola la muestra con
  // ganancia volume/127. Devuelve 1 si se encoló, 0 si no
  // (FX desconocido -> unresolved, WAV ilegible, voces
  // llenas con dropped_sfx_ incrementado).
  int OnFxStart(uint32_t fx_id, uint32_t volume, uint32_t pan,
                uint32_t studio);

  // Avance de reproduccion: mezcla un bloque de hasta
  // kFeedFrames de todas las voces activas y lo entrega al
  // backend. En host el test llama a Tick() + Audio::Pump()
  // en bucle hasta vaciar; en la APK lo llama
  // GameCubeRuntime::Frame() (el callback AAudio drena en
  // paralelo).
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
  // Frames pendientes: suma de lo que queda por entregar
  // en voces no en bucle + (para voces en bucle) lo que
  // queda hasta el fin de la iteración actual del bucle
  // (la voz en bucle es infinita en realidad; este número
  // solo sirve para tests, no como "queda X para terminar").
  uint64_t QueuedFrames() const;
  bool QueueEmpty() const { return ActiveVoiceCount() == 0; }
  // Voces activas (SFX en orden de slot + stream al final
  // si está activa) y sus posiciones en frames a 48 kHz.
  // Solo para tests host (verificar mezcla y bucles).
  size_t ActiveVoiceCount() const;
  std::vector<uint64_t> ActiveVoicePositions() const;
  uint64_t DroppedSfx() const { return dropped_sfx_; }

 private:
  static constexpr int kFeedFrames = 4096;
  static constexpr size_t kMaxSfxVoices = 8;

  struct Voice {
    std::vector<int16_t> pcm;  // Estereo s16 a 48.000 Hz.
    size_t pos = 0;            // Frames ya entregados.
    float gain = 1.0f;         // vol/127 (SFX) o 1.0 (stream).
    size_t loop_start = 0;     // Frames a 48 kHz (0,0 = no bucle).
    size_t loop_len = 0;
    bool active = false;
    bool HasLoop() const { return loop_len > 0; }
    size_t Total() const { return pcm.size() / 2; }
    size_t LoopEnd() const { return loop_start + loop_len; }
  };

  const char* LookupStreamWav(uint32_t id) const;
  const struct MusyxSampleEntry* LookupSampleEntry(
      uint32_t id) const;
  // Encola UNA muestra MusyX como voz SFX (carga WAV,
  // resamplea a 48 kHz estéreo, aplica bucle por metadato
  // y ganancia). Usado por OnFxStart; OnSfxTrigger conserva
  // su propio camino para no romper la suite Fase 16/17.
  bool EnqueueSample(uint32_t sample_id, float gain);
  // Carga un WAV relativo a wav_root_, lo resamplea a
  // estereo 48.000 Hz y lo encola como voz (stream o SFX).
  // Registra Played o Unresolved segun el caso. Devuelve
  // false si no se pudo (incluidas voces SFX llenas, que
  // además incrementan dropped_sfx_).
  bool EnqueueWav(const char* rel, uint32_t id, const char* kind,
                  float gain, size_t loop_start_48k,
                  size_t loop_len_48k, bool is_stream);
  // Encola un WavData ya cargado/decodificado (WAV o ADP
  // decodificado a 32.000 Hz estéreo) con la misma
  // semántica de voz que EnqueueWav. Usado por el fallback
  // ADP de streams (Fase 18) para no duplicar la lógica
  // de voces; EnqueueWav lo reutiliza tras cargar el WAV.
  bool EnqueueDecoded(const Audio::WavData& wav, const char* rel,
                      uint32_t id, const char* kind, float gain,
                      size_t loop_start_48k, size_t loop_len_48k,
                      bool is_stream);

  Audio* audio_ = nullptr;
  std::string wav_root_;
  std::array<Voice, kMaxSfxVoices> sfx_voices_;
  Voice stream_voice_;
  uint64_t dropped_sfx_ = 0;
  std::vector<Played> played_;
  std::vector<Counted> counted_;
  std::vector<Unresolved> unresolved_;
};

}  // namespace sfa
