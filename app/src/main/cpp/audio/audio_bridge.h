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
//     alternativas por pesos, no 4 sonidos), resuelta
//     trigger -> FX -> muestra por fx_table.h (Tramo 5;
//     antes se usaba la variante como muestra directa,
//     WAV equivocado), ganancia vol_base/127 (el volumen
//     maestro lo aplica Audio::SubmitBuffer, no el bridge,
//     para no aplicarlo dos veces).
// Que SOLO cuenta (sin reproducir): AudioStream_StartPrepared
// y cualquier otra entrada, porque su layout no está
// verificado. Sus IDs quedan en CountedEntries() para la
// traza, no en PlayedEntries(). sndFXStartEx YA reproduce
// desde la Fase 18 (OnFxStart, tabla FX verificada).
// TRAMO 6: sndSeqPlayEx YA reproduce (OnSeqPlay): arranca el
// secuenciador host MusyX con el primer pase verificado de
// la cancion pedida (musyx_notes.h, generado desde Tramo 5)
// y entrega sus notas por voces de musica propias (16, fuera
// de las 8 SFX y de la voz de stream), con reloj BPMx6,4,
// pitch por mac_key, pan CC10 en el note-on y CC7
// automatizado por bloque de mezcla. Solo suenan las
// canciones con tabla verificada (99, 74, 5); cualquier otra
// queda como no resuelta ("musyx_cancion"), sin inventar
// sonido. sndSeqStop detiene la cancion host en curso.
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
//
// Streams (Tramo 5, streaming ADP + cache PCM): OnStreamPlay
// ya NO carga el WAV entero ni decodifica el ADP entero.
// Orden: cache PCM valida -> ADP por bloques (mientras
// suena, escribe la cache; al llegar a EOF la promueve) ->
// WAV por el camino viejo en memoria -> silencio +
// unresolved + log, nunca crash. El ADP se resuelve por
// indice insensible a caso sobre audio/streams/ (ver
// adp_cache.h), no por sustitucion ingenua de extension.
// La voz de stream en streaming entrega por bloques de
// hasta kFeedFrames resampleados a 48 kHz (el resampleo
// incremental comparte la matematica de ResampleToStereo,
// sin chasquidos en fronteras de bloque). Los SFX siguen
// por el camino en memoria (cortos, < 1 s tipico).
// La cache vive en <base>/sfa-data/audio-cache/v1/ (ver
// adp_cache.h); el bridge la deriva de wav_root. Si el
// usuario anade audio a mitad de sesion (picker SAF
// "anadir audio"), el indice se reconstruye al primer
// fallo de busqueda, asi que el audio nuevo suena sin
// reiniciar ni reimportar.

#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "audio/adp_cache.h"
#include "audio/adp_stream.h"
#include "audio/audio.h"
#include "audio/fx_double.h"
#include "audio/musyx_seq.h"

namespace sfa {

class AudioBridge {
 public:
  AudioBridge();  // CC7=127, CC10=64 iniciales (preset huesped).
  // Audio debe estar Init() + Start() antes de usar el bridge
  // (en el runtime lo hace GameCubeRuntime::Init; en el test
  // host lo hace el propio test). El bridge no posee Audio.
  void SetAudio(Audio* audio) { audio_ = audio; }
  void SetWavRoot(const char* root) {
    wav_root_ = root != nullptr ? root : "";
    cache_root_ = DeriveCacheRoot(wav_root_);
    indexed_root_.clear();
    adp_index_.Clear();
    cache_cleaned_ = false;
  }
  // Tramo 8 — RAM huesped para leer SynthPlayParams en
  // OnSeqPlay (ver .cpp). Puntero NO poseido: lo fija el
  // runtime (memory_.RamData(), estable tras Init) o el
  // test host; sin fijar, OnSeqPlay usa los defaults v1
  // (speed 256, sin mutes, volumen 1,0). El runtime debe
  // llamarlo tras cargar el DOL (parche aparte, ver
  // runtime-setguestram.patch): sin esa linea, los params
  // se ignoran pero nada se rompe.
  void SetGuestRam(const uint8_t* ram, uint32_t size) {
    guest_ram_ = ram;
    guest_ram_size_ = size;
  }
  // Techo LRU de la cache PCM (por defecto 2.048 MiB).
  // Solo para tests host; en la APK no se toca.
  void SetCacheCapBytes(uint64_t cap) { cache_cap_ = cap; }
  uint64_t CacheCapBytes() const { return cache_cap_; }
  const std::string& CacheRoot() const { return cache_root_; }
  // Via del ultimo stream en streaming: "cache", "adp" o
  // "" (WAV en memoria o ningun stream en streaming).
  const std::string& LastStreamVia() const { return last_stream_via_; }

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
  // Devuelve 1 si se encoló, 0 si no (sin variante, FX
  // fuera de tabla, WAV ilegible o voces llenas).
  // TRAMO 5 (corrección Fase 18): los campos de
  // SfxTriggerEntry::samples[] NO son muestras, son IDs FX
  // (sfxIds[] de Sfx.bin). La resolución es trigger -> FX
  // -> muestra por audio/fx_table.h (kFxSample, 833
  // entradas verificadas; macro == fxId en 0/833), y luego
  // EnqueueSample, el mismo camino que OnFxStart. Ejemplo:
  // trigger 13 -> FX 175 -> muestra 841 (NO 175; la
  // muestra 175 era el WAV equivocado de antes). El camino
  // REAL del juego sigue sin pasar por aquí: pasa por
  // sndFXStartEx -> OnFxStart, que NO se toca en este
  // tramo. Reserva: FX 96/162/820 usan la muestra lineal
  // de su macro (branch_before_sample=1, pendiente de
  // confirmación por ejecución MCMD completa).
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

  // Tramo 6 — SFX real CON doblaje (opt-in; OnFxStart NO cambia,
  // sigue siendo 1 voz). Para FX sin voz hija (todos salvo
  // 96/162/820) delega exactamente en OnFxStart. Para
  // 96/162/820 encola padre por OnFxStart y luego la hija por
  // EnqueueSamplePitched (misma muestra, pitch por tecla, misma
  // ganancia; ver fx_double.h). Devuelve nº de voces encoladas:
  // 2 (padre + hija), 1 (solo padre) o 0 (el padre falló).
  // Decisión de integración Tramo 6: el hook sndFXStartEx pasa
  // a esta variante (antes llamaba a OnFxStart).
  int OnFxStartDoubled(uint32_t fx_id, uint32_t volume, uint32_t pan,
                       uint32_t studio);

  // Musica MusyX (Tramo 6, hook sndSeqPlayEx 0x8027C34C;
  // Tramo 8: params reales + bucles + fades):
  // group_id = r3 (sgid), seq_id = r4 (sid = trigger->track),
  // params_ptr = r6 (puntero huesped a SynthPlayParams: se
  // LEE si el bridge tiene RAM huesped fijada con
  // SetGuestRam — speed si flags bit 1, mutes si bit 0,
  // volumen inicial si bit 2; sin RAM, defaults v1).
  // La busqueda es por seq_id; si el group_id no coincide
  // con el gid de la tabla, arranca igualmente y lo deja
  // en el log (equivalencia sgid<->gid sin verificar salvo
  // 99, confirmada en el Tramo 7). Canciones con tabla:
  // 99, 74, 5, 22, 95 (Tramo 8); 99/74 con bucle, resto en
  // primer pase.
  // Devuelve 1 si arranco, 0 si la cancion no tiene tabla
  // verificada (unresolved "musyx_cancion") o no hay audio.
  // Sustituye cualquier cancion host en curso (una sola
  // cancion a la vez en v1, como la voz de stream unica).
  int OnSeqPlay(uint32_t group_id, uint32_t seq_id,
                uint32_t params_ptr);
  // Hook sndSeqStop 0x80272F80: detiene la cancion host.
  void OnSeqStop();
  // Tramo 8 — hook sndSeqVolume 0x80273090 (layout
  // verificado en codigo huesped, Music_ChannelLoaded-
  // Callback 0x8000B4A0: r3=volumen 0..127, r4=tiempo,
  // r5=seqHandle, r6=0): programa un fade lineal del
  // volumen maestro de musica hacia volume/127 en
  // time_ms (0 = inmediato). Sin cancion activa se
  // ignora (log) y devuelve false. El tiempo se modela
  // en ms (fade de entrada 500 del callback: con ticks
  // a 60 Hz serian 8,3 s, implausible como fade-in).
  // Solo afecta a la mezcla (no al PCM almacenado ni a
  // los conteos de notas/frames).
  bool OnSeqVolume(uint32_t volume, uint32_t time_ms,
                   uint32_t seq_handle);
  // Volumen maestro de musica vigente (0..1) y objetivo,
  // para tests host.
  float SeqVolume() const { return seq_vol_current_; }
  float SeqVolumeTarget() const { return seq_vol_to_; }

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
  // Observacion MusyX para tests host (Tramo 6).
  struct SeqStarted {
    uint32_t group_id = 0;
    uint32_t seq_id = 0;
    uint32_t bpm = 0;
    size_t notes = 0;
    uint32_t params_ptr = 0;
    // Tramo 8: params aplicados (defaults v1 si no hay RAM
    // huesped o params fuera de rango: speed 256, flags 0).
    uint32_t speed = 256;
    uint32_t params_flags = 0;
  };
  const std::vector<SeqStarted>& SeqStartedEntries() const {
    return seq_started_;
  }
  int CurrentSeqTrack() const {
    return seq_.Active() && seq_.Song() != nullptr
               ? static_cast<int>(seq_.Song()->track_id)
               : -1;
  }
  bool SeqActive() const { return seq_.Active(); }
  size_t MusyxActiveNotes() const;
  uint64_t MusyxNotesStarted() const { return musyx_started_; }
  uint64_t MusyxNotesEnded() const { return musyx_ended_; }
  uint64_t MusyxStolen() const { return musyx_stolen_; }
  // CC7 vigente por canal MIDI (tras los eventos del
  // secuenciador; 127 antes del primer evento del canal).
  uint32_t MusyxCc7(uint32_t midi) const {
    return midi < 16 ? cc7_[midi] : 127;
  }
  // Solo tests host: copia del PCM (48 kHz, sin ganancia
  // CC7) de la voz de musica de note_index, si esta activa.
  bool MusyxVoicePcmCopy(size_t note_index,
                         std::vector<int16_t>* out) const;
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
  // Voces de musica (Tramo 6: 16; Tramo 8: 32): el primer
  // pase de track 22 mide polifonia maxima 17, por encima
  // de 16 (con 16 habria robos en 22). 5: 14, 99: 2, 74: 3,
  // 95: 5. Solo cuesta memoria de las voces activas; sin
  // cancion no cuesta nada. Fuera de las 8 SFX y de la voz
  // de stream.
  static constexpr size_t kMaxMusicVoices = 32;

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
  // Musica (Tramo 6): arranca una nota como voz de musica
  // (resampleo con pitch por mac_key, bucle de muestra por
  // metadato, pan CC10 del note-on; la ganancia CC7 se
  // aplica en Tick por bloque, no aqui). Roba la voz mas
  // antigua si las 16 estan ocupadas (cuenta musyx_stolen_).
  bool StartMusicNote(const MusyxNote& note, size_t note_index);
  void StopMusicNote(size_t note_index);
  void StopAllMusic();
  // Avanza el secuenciador dt segundos y procesa sus
  // eventos (CC7/CC10, note-on/off). Llamado por Tick().
  void PumpSequencer(double dt_seconds);
  // Resuelve el .adp de un WAV de stream por indice
  // insensible a caso (con reconstruccion del indice al
  // primer fallo, para audio anadido a mitad de sesion);
  // si el indice no lo encuentra, intenta la sustitucion
  // directa .wav -> .adp si ese fichero existe. "" si no
  // hay ADP (entonces el llamador cae al WAV).
  std::string AdpRelForWav(const char* wav_rel);
  // Arranca una voz de stream en streaming (cache o ADP).
  // Sustituye cualquier voz de stream anterior (vector o
  // streaming). Devuelve false si la fuente esta vacia.
  bool StartStreamSource(std::unique_ptr<StreamSource> src,
                         const char* rel, const char* via,
                         uint32_t id);
  void CloseStreamSource();
  bool StreamSourceActive() const {
    return stream_source_ != nullptr && !stream_source_->AtEof();
  }
  // Encola UNA muestra MusyX como voz SFX (carga WAV,
  // resamplea a 48 kHz estéreo, aplica bucle por metadato
  // y ganancia). Usado por OnFxStart y, desde el Tramo 5,
  // también por OnSfxTrigger (tras resolver FX -> muestra).
  bool EnqueueSample(uint32_t sample_id, float gain);
  // Tramo 6 — voz hija con pitch: COPIA deliberada de
  // EnqueueSample con tasa efectiva 48000/ratio, no una
  // refactorización, para que el camino verificado quede
  // intacto. Misma política de voces llenas, mismo bucle por
  // metadato reescalado y misma ganancia. ratio <= 0 -> false.
  bool EnqueueSamplePitched(uint32_t sample_id, float gain,
                            double pitch_ratio);
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
  // Tramo 8: RAM huesped (no poseida) para params, y
  // estado de params/fade de la cancion en curso.
  const uint8_t* guest_ram_ = nullptr;
  uint32_t guest_ram_size_ = 0;
  // Mutes de SynthPlayParams (flags bit 0): bit por pista
  // MusyX (nota.midi); bit a 1 = pista activa (seq.c:1261,
  // Tramo 7). Solo se aplica si flags & 1; en otro caso
  // todo activo (el caso medido real, flags=6, ignora los
  // mutes). El mapeo bit->midi es el supuesto documentado
  // del Tramo 8 (verificado solo sinteticamente).
  uint32_t params_mute_[2] = {0xFFFFFFFFu, 0xFFFFFFFFu};
  bool params_mute_active_ = false;
  // Volumen maestro de musica (fade sndSeqVolume): se
  // aplica en Tick al mezclar, no al PCM almacenado.
  float seq_vol_current_ = 1.0f;
  float seq_vol_from_ = 1.0f;
  float seq_vol_to_ = 1.0f;
  double seq_vol_t_ = 0.0;
  double seq_vol_dur_ = 0.0;
  void AdvanceSeqVolume(double dt_seconds);
  std::string wav_root_;
  std::string cache_root_;
  std::string indexed_root_;
  AdpIndex adp_index_;
  bool cache_cleaned_ = false;
  uint64_t cache_cap_ = kAdpCacheCapBytes;
  std::string last_stream_via_;
  std::array<Voice, kMaxSfxVoices> sfx_voices_;
  // Voz de musica (Tramo 6): PCM ya resampleado a 48 kHz
  // con pitch y pan del note-on, SIN ganancia aplicada
  // (Tick multiplica por base_gain x CC7 vigente / 127
  // por bloque). Sin bucle en el campo: el bucle de
  // muestra ya se expandio al renderizar la nota hasta
  // su key-off (o hasta agotar la muestra sin bucle).
  struct MusicVoice {
    std::vector<int16_t> pcm;
    size_t pos = 0;
    float base_gain = 1.0f;  // mac_vol/127.
    uint32_t midi = 0;
    size_t note_index = 0;
    bool active = false;
    size_t Total() const { return pcm.size() / 2; }
  };
  std::array<MusicVoice, kMaxMusicVoices> music_voices_;
  MusyxSequencer seq_;
  std::array<uint32_t, 16> cc7_{};
  std::array<uint32_t, 16> cc10_{};
  std::vector<SeqStarted> seq_started_;
  uint64_t musyx_started_ = 0;
  uint64_t musyx_ended_ = 0;
  uint64_t musyx_stolen_ = 0;
  Voice stream_voice_;  // Solo para el fallback WAV en memoria.
  // Voz de stream en streaming (cache o ADP). Excluyente
  // con stream_voice_: solo una de las dos esta activa.
  std::unique_ptr<StreamSource> stream_source_;
  // Bufer reutilizado por Tick() para el bloque del stream
  // (evita reservar por Tick en el hilo del juego).
  std::vector<int16_t> stream_scratch_;
  uint64_t dropped_sfx_ = 0;
  std::vector<Played> played_;
  std::vector<Counted> counted_;
  std::vector<Unresolved> unresolved_;
};

}  // namespace sfa
