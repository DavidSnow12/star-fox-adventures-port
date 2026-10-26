#include "audio/audio_bridge.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <memory>

#include "audio/audio_id_map.h"
#include "audio/fx_table.h"
#include "log.h"

namespace sfa {

namespace {

// Direcciones guest verificadas en codigo/symbols.map.
constexpr uint32_t kAudioStreamPlay = 0x8000D220u;
constexpr uint32_t kAudioStreamStopCurrent = 0x8000D03Cu;
constexpr uint32_t kSndFxStartEx = 0x80273218u;

int16_t ClampS16(int32_t v) {
  if (v > 32767) return 32767;
  if (v < -32768) return -32768;
  return static_cast<int16_t>(v);
}

bool FileExists(const char* path) {
  std::FILE* f = std::fopen(path, "rb");
  if (f == nullptr) return false;
  std::fclose(f);
  return true;
}

// Lector nativo ADP con escritura de cache en streaming:
// decodifica por bloques para reproducir y escribe ese
// mismo PCM en <rel>.pcm.tmp; al llegar a EOF promueve
// la cache (meta + rename + poda LRU). Si se cierra
// antes de EOF (stop o nuevo Play), el .tmp se aborta:
// la cache parcial NO se promueve (limitacion v1).
class AdpCachedReader : public NativeReader {
 public:
  bool Open(const char* adp_path, const std::string& cache_root,
            const std::string& adp_rel, uint64_t cap_bytes) {
    if (!decoder_.Open(adp_path)) return false;
    cache_root_ = cache_root;
    adp_rel_ = adp_rel;
    adp_path_ = adp_path;
    cap_bytes_ = cap_bytes;
    uint64_t total = decoder_.TotalNativeFrames();
    uint64_t adp_bytes = total / 28 * 32;
    // Best effort: si la cache no se puede abrir, el
    // sonido sigue sin cache (no es error de reproduccion).
    if (writer_.Open(cache_root, adp_rel, adp_bytes, total)) {
      writer_open_ = true;
    }
    return true;
  }

  size_t ReadNative(int16_t* out, size_t max_frames) override {
    size_t got = decoder_.ReadNative(out, max_frames);
    if (got > 0 && writer_open_) {
      if (!writer_.Write(out, got)) writer_open_ = false;
    }
    if (decoder_.AtEof() && !finalized_) {
      finalized_ = true;
      if (writer_open_) {
        if (writer_.Finalize(adp_path_, cap_bytes_)) {
          SFA_LOGI("bridge: cache ADP promovida '%s'",
                   adp_rel_.c_str());
        } else {
          SFA_LOGI("bridge: cache ADP no promovida '%s' "
                   "(seguir sonando sin cache)",
                   adp_rel_.c_str());
        }
        writer_open_ = false;
      }
    }
    return got;
  }

  uint64_t TotalNativeFrames() const override {
    return decoder_.TotalNativeFrames();
  }
  bool NativeEof() const override { return decoder_.AtEof(); }
  void CloseNative() override {
    if (!finalized_ && writer_open_) writer_.Abort();
    writer_open_ = false;
    decoder_.Close();
  }

 private:
  AdpStreamDecoder decoder_;
  CacheWriter writer_;
  bool writer_open_ = false;
  bool finalized_ = false;
  std::string cache_root_;
  std::string adp_rel_;
  std::string adp_path_;
  uint64_t cap_bytes_ = kAdpCacheCapBytes;
};

}  // namespace

const char* AudioBridge::LookupStreamWav(uint32_t id) const {
  for (const StreamIdEntry& e : kStreamIdMap) {
    if (e.id == id) return e.wav;
  }
  return nullptr;
}

const MusyxSampleEntry* AudioBridge::LookupSampleEntry(
    uint32_t id) const {
  for (const MusyxSampleEntry& e : kMusyxSampleMap) {
    if (e.id == id) return &e;
  }
  return nullptr;
}

bool AudioBridge::EnqueueWav(const char* rel, uint32_t id,
                             const char* kind, float gain,
                             size_t loop_start_48k,
                             size_t loop_len_48k, bool is_stream) {
  if (audio_ == nullptr || rel == nullptr) return false;
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += rel;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV no legible '%s' (id %u, %s)",
             path.c_str(), id, kind);
    return false;
  }
  return EnqueueDecoded(wav, rel, id, kind, gain, loop_start_48k,
                        loop_len_48k, is_stream);
}

std::string AudioBridge::AdpRelForWav(const char* wav_rel) {
  if (wav_rel == nullptr) return "";
  if (indexed_root_ != wav_root_) {
    adp_index_.Build(wav_root_);
    indexed_root_ = wav_root_;
  }
  std::string found = adp_index_.Lookup(wav_rel);
  if (!found.empty()) return found;
  // Audio anadido a mitad de sesion (picker "anadir
  // audio"): el indice puede estar obsoleto; reconstruir
  // una vez y reintentar antes de rendirse al WAV.
  adp_index_.Build(wav_root_);
  found = adp_index_.Lookup(wav_rel);
  if (!found.empty()) return found;
  // Red de seguridad: sustitucion directa .wav -> .adp,
  // solo si ese fichero existe realmente (el indice es
  // la via principal; esto cubre packs sin streams/ en
  // el arbol esperado por el indice).
  std::string direct = wav_rel;
  size_t dot = direct.rfind(".wav");
  if (dot != std::string::npos) {
    direct.replace(dot, 4, ".adp");
    std::string path = wav_root_;
    if (!path.empty() && path.back() != '/') path += '/';
    path += direct;
    if (FileExists(path.c_str())) return direct;
  }
  return "";
}

bool AudioBridge::StartStreamSource(std::unique_ptr<StreamSource> src,
                                    const char* rel, const char* via,
                                    uint32_t id) {
  if (audio_ == nullptr || src == nullptr || rel == nullptr) {
    return false;
  }
  uint64_t total48 = src->TotalFrames48();
  if (total48 == 0) return false;
  CloseStreamSource();
  stream_voice_.active = false;
  stream_voice_.pcm.clear();
  stream_voice_.pos = 0;
  Played p;
  p.id = id;
  p.kind = "stream";
  p.wav = rel;
  p.src_rate = 32000;
  p.src_channels = 2;
  p.frames_48k = total48;
  played_.push_back(p);
  last_stream_via_ = via != nullptr ? via : "";
  stream_source_ = std::move(src);
  SFA_LOGI("bridge: stream por %s '%s' (32000 Hz x2, %llu "
           "frames a 48 kHz)",
           via != nullptr ? via : "?",
           rel, static_cast<unsigned long long>(total48));
  return true;
}

void AudioBridge::CloseStreamSource() {
  if (stream_source_ != nullptr) {
    stream_source_->Close();
    stream_source_.reset();
  }
}

bool AudioBridge::EnqueueDecoded(const Audio::WavData& wav,
                                 const char* rel, uint32_t id,
                                 const char* kind, float gain,
                                 size_t loop_start_48k,
                                 size_t loop_len_48k,
                                 bool is_stream) {
  if (audio_ == nullptr || rel == nullptr) return false;
  if (is_stream) CloseStreamSource();  // WAV sustituye al streaming.
  Voice* slot = nullptr;
  if (is_stream) {
    slot = &stream_voice_;  // La voz de stream es única.
  } else {
    for (Voice& v : sfx_voices_) {
      if (!v.active) {
        slot = &v;
        break;
      }
    }
    if (slot == nullptr) {
      ++dropped_sfx_;
      SFA_LOGI("bridge: SFX id %u descartado (8 voces "
               "ocupadas)", id);
      return false;
    }
  }
  std::vector<int16_t> pcm =
      Audio::ResampleToStereo(wav, Audio::kOutputRate);
  if (pcm.empty()) return false;
  Played p;
  p.id = id;
  p.kind = kind;
  p.wav = rel;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->gain = gain;
  slot->loop_start = loop_start_48k;
  slot->loop_len = loop_len_48k;
  slot->active = true;
  SFA_LOGI("bridge: %s id %u -> '%s' (%d Hz x%d, %llu frames "
           "a 48 kHz, bucle [%llu, %llu))",
           kind, id, rel, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k),
           static_cast<unsigned long long>(loop_start_48k),
           static_cast<unsigned long long>(loop_start_48k +
                                            loop_len_48k));
  return true;
}

bool AudioBridge::OnStreamPlay(uint32_t stream_id) {
  const char* wav = LookupStreamWav(stream_id);
  if (wav == nullptr) {
    Unresolved u;
    u.id = stream_id;
    u.kind = "stream";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: stream id %u sin resolver en la tabla "
             "(no se inventa sonido)",
             stream_id);
    return false;
  }
  // Tramo 5, orden: cache PCM -> ADP por bloques -> WAV
  // en memoria -> silencio + unresolved. El ADP es la
  // fuente de verdad (su PCM es bit a bit el WAV host);
  // preferir un WAV viejo sobre un ADP presente
  // introduciria divergencias si el pack mezcla
  // generaciones. El WAV queda como red de seguridad.
  if (!cache_cleaned_) {
    cache_cleaned_ = true;
    // Huerfanos de una sesion anterior (cierre a mitad,
    // falta de espacio): nunca se reproducen, se borran.
    CleanupCacheOrphans(cache_root_);
  }
  std::string adp_rel = AdpRelForWav(wav);
  if (!adp_rel.empty()) {
    std::string adp_path = wav_root_;
    if (!adp_path.empty() && adp_path.back() != '/') adp_path += '/';
    adp_path += adp_rel;
    // 1) Cache valida: lector por bloques sobre el .pcm.
    AdpCacheMeta meta;
    if (IsCacheValid(cache_root_, adp_rel, adp_path, &meta)) {
      auto reader = std::make_unique<PcmNativeReader>();
      if (reader->Open(CachePcmPath(cache_root_, adp_rel).c_str())) {
        TouchCache(cache_root_, adp_rel);
        auto src =
            std::make_unique<ResamplingSource>(std::move(reader));
        if (StartStreamSource(std::move(src), adp_rel.c_str(),
                              "cache", stream_id)) {
          return true;
        }
      }
      SFA_LOGI("bridge: cache valida pero ilegible '%s', "
               "se redecodifica del ADP",
               adp_rel.c_str());
    }
    // 2) ADP por bloques (+ escritura de cache en vivo).
    auto cached = std::make_unique<AdpCachedReader>();
    if (cached->Open(adp_path.c_str(), cache_root_, adp_rel,
                     cache_cap_) &&
        cached->TotalNativeFrames() > 0) {
      auto src =
          std::make_unique<ResamplingSource>(std::move(cached));
      if (StartStreamSource(std::move(src), adp_rel.c_str(), "adp",
                            stream_id)) {
        return true;
      }
    }
    SFA_LOGI("bridge: stream %u sin ADP utilizable ('%s'), "
             "se intenta el WAV",
             stream_id, adp_rel.c_str());
  }
  // 3) WAV por el camino viejo en memoria (red de seguridad;
  // para streams largos, con su limite conocido del anillo).
  if (EnqueueWav(wav, stream_id, "stream", 1.0f, 0, 0, true)) {
    return true;
  }
  // 4) Nada reproducible: silencio + unresolved, sin crash.
  Unresolved u;
  u.id = stream_id;
  u.kind = "stream";
  unresolved_.push_back(u);
  return false;
}

void AudioBridge::OnStreamStop() {
  // Detener SOLO la voz de stream. El backend sigue con lo
  // ya entregado (el anillo se drena solo); no se puede
  // "des-entregar" lo enviado, y no se pretende. Los SFX
  // en curso NO se tocan (Fase 17: antes se vaciaba toda
  // la cola serial, incluidos SFX que sonaban en paralelo).
  // Cerrar la fuente en streaming aborta su escritura de
  // cache parcial (no se promueve: limitacion v1).
  CloseStreamSource();
  stream_voice_.active = false;
  stream_voice_.pcm.clear();
  stream_voice_.pos = 0;
  SFA_LOGI("bridge: stop de stream (solo voz de stream)");
}

void AudioBridge::OnSfxStop() {
  for (Voice& v : sfx_voices_) {
    v.active = false;
    v.pcm.clear();
    v.pos = 0;
  }
  SFA_LOGI("bridge: stop de SFX (voces SFX vaciadas)");
}

int AudioBridge::OnSfxTrigger(uint32_t trigger_id) {
  const SfxTriggerEntry* found = nullptr;
  for (const SfxTriggerEntry& e : kSfxTriggerMap) {
    if (e.id == trigger_id) {
      found = &e;
      break;
    }
  }
  if (found == nullptr) {
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u desconocido", trigger_id);
    return 0;
  }
  // Fase 16, corrección verificada en código huésped: los 4 campos
  // de Sfx.bin son VARIANTES alternativas (una por disparo,
  // elegida por pesos en Sfx_ReadTriggerParams), NO 4 sonidos
  // simultáneos. Hasta que los pesos estén en el mapa, se
  // reproduce la primera variante no nula documentada como
  // aproximación; para triggers de variante única (un solo
  // campo no nulo) esa primera variante ES la única, sin
  // ambigüedad.
  // TODO(Fase 16, siguiente paso): pesos + volRand/pitchRand
  // en audio_id_map.h y selección ponderada real.
  // TRAMO 5 (corrección Fase 18): cada variante NO es una
  // muestra, es un ID FX (sfxIds[] de Sfx.bin). Se resuelve
  // FX -> muestra por fx_table.h (kFxSample, tabla
  // verificada, NO identidad) y se encola por EnqueueSample,
  // el mismo camino que OnFxStart (bucle por metadato de la
  // muestra real y ganancia vol_base/127). El código anterior
  // usaba la variante como muestra directa y sonaba con el
  // WAV equivocado en 1331/1331 variantes (p. ej. trigger 13:
  // sonaba 175 y debe sonar 841, vía FX 175 -> macro 1040).
  // OnFxStart NO se toca: el camino real del juego
  // (sndFXStartEx) ya resolvía por esta tabla.
  // Nota Tramo 5: para FX 96/162/820 la tabla lleva la muestra
  // lineal de su macro, CONFIRMADA por recorrido MCMD completo
  // (play-macro = voz hija paralela con la misma muestra:
  // 96->1173, 162->1172, 820->1147; el doblaje a 2 voces queda
  // pendiente, la muestra no); aquí se usa esa misma muestra
  // lineal, igual que OnFxStart.
  uint16_t fx_id = 0;
  for (int i = 0; i < 4; ++i) {
    if (found->samples[i] != 0) {
      fx_id = found->samples[i];
      break;
    }
  }
  if (fx_id == 0) {
    // Trigger conocido pero sin variante (secuencia o grupo
    // MusyX): queda como no resuelto, no como silencio
    // inventado.
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u sin variante "
             "(secuencia/grupo, fuera de esta fase)",
             trigger_id);
    return 0;
  }
  if (fx_id >= kFxTableCount) {
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u con FX %u fuera de "
             "tabla (0-832)",
             trigger_id, fx_id);
    return 0;
  }
  uint32_t sample_id = kFxSample[fx_id];
  SFA_LOGI("bridge: trigger SFX id %u -> FX %u -> muestra %u "
           "(tabla FX, no identidad)",
           trigger_id, fx_id, sample_id);
  uint64_t dropped_before = dropped_sfx_;
  if (EnqueueSample(sample_id,
                    static_cast<float>(found->vol_base) / 127.0f)) {
    return 1;
  }
  if (dropped_sfx_ > dropped_before) {
    // Voces llenas: ya contado en dropped_sfx_ por
    // EnqueueSample; no se añade un Unresolved espurio.
    return 0;
  }
  Unresolved u;
  u.id = trigger_id;
  u.kind = "sfx_trigger";
  unresolved_.push_back(u);
  return 0;
}

bool AudioBridge::EnqueueSample(uint32_t sample_id, float gain) {
  const MusyxSampleEntry* entry = LookupSampleEntry(sample_id);
  if (entry == nullptr) return false;
  Voice* slot = nullptr;
  for (Voice& v : sfx_voices_) {
    if (!v.active) {
      slot = &v;
      break;
    }
  }
  if (slot == nullptr) {
    ++dropped_sfx_;
    SFA_LOGI("bridge: SFX muestra %u descartada (8 voces ocupadas)",
             sample_id);
    return false;
  }
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += entry->wav;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV no legible '%s' (muestra %u)", path.c_str(),
             sample_id);
    return false;
  }
  std::vector<int16_t> pcm =
      Audio::ResampleToStereo(wav, Audio::kOutputRate);
  if (pcm.empty()) return false;
  size_t loop_start_48k = 0;
  size_t loop_len_48k = 0;
  if (entry->loop_len > 0 && wav.rate > 0) {
    loop_start_48k = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_start) *
         static_cast<uint64_t>(Audio::kOutputRate)) /
        static_cast<uint64_t>(wav.rate));
    loop_len_48k = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_len) *
         static_cast<uint64_t>(Audio::kOutputRate)) /
        static_cast<uint64_t>(wav.rate));
    size_t total = pcm.size() / 2;
    if (loop_start_48k + loop_len_48k > total) {
      loop_len_48k =
          total > loop_start_48k ? total - loop_start_48k : 0;
    }
  }
  Played p;
  p.id = sample_id;
  p.kind = "sfx_muestra";
  p.wav = entry->wav;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->gain = gain;
  slot->loop_start = loop_start_48k;
  slot->loop_len = loop_len_48k;
  slot->active = true;
  SFA_LOGI("bridge: sfx_muestra id %u -> '%s' (%d Hz x%d, %llu "
           "frames a 48 kHz, bucle [%llu, %llu), ganancia %.3f)",
           sample_id, entry->wav, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k),
           static_cast<unsigned long long>(loop_start_48k),
           static_cast<unsigned long long>(loop_start_48k +
                                            loop_len_48k),
           static_cast<double>(gain));
  return true;
}

int AudioBridge::OnFxStart(uint32_t fx_id, uint32_t volume,
                           uint32_t pan, uint32_t studio) {
  // Fase 18: fxId ya viene enmascarado por el llamador del
  // hook (r3&0xFFFF); aquí se vuelve a enmascarar por
  // seguridad para llamadas directas del test host.
  fx_id &= 0xFFFFu;
  volume &= 0xFFu;
  pan &= 0xFFu;
  studio &= 0xFFu;
  if (fx_id >= kFxTableCount) {
    Unresolved u;
    u.id = fx_id;
    u.kind = "sfx_fx";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: FX %u desconocido (fuera de tabla 0-832)",
             fx_id);
    return 0;
  }
  // 0xFF = valor del descriptor (volume 127, panning 64 en
  // los 833). El panning hoy solo se registra: no se aplica
  // ley de paneo inventada sobre un WAV ya estéreo/mono
  // resampleado.
  uint32_t vol = (volume == 0xFFu) ? 127u : volume;
  uint32_t pan_eff = (pan == 0xFFu) ? 64u : pan;
  float gain = static_cast<float>(vol) / 127.0f;
  uint32_t sample_id = kFxSample[fx_id];
  SFA_LOGI("bridge: sndFXStartEx fx=%u studio=%u pan=%u -> "
           "muestra %u (tabla FX, no identidad)",
           fx_id, studio, pan_eff, sample_id);
  if (!EnqueueSample(sample_id, gain)) {
    Unresolved u;
    u.id = fx_id;
    u.kind = "sfx_fx";
    unresolved_.push_back(u);
    return 0;
  }
  return 1;
}

bool AudioBridge::OnAudioEntry(uint32_t pc, uint32_t r3,
                               uint32_t r4, uint32_t r5,
                               uint32_t r6, uint32_t /*r7*/) {
  Counted c;
  c.pc = pc;
  c.r3 = r3;
  counted_.push_back(c);
  if (pc == kAudioStreamPlay) return OnStreamPlay(r3);
  if (pc == kAudioStreamStopCurrent) {
    OnStreamStop();
    return true;
  }
  if (pc == kSndFxStartEx) {
    // sndFXStartEx (Fase 18, layout verificado en código
    // huésped): r3=fxId, r4=volume, r5=pan, r6=studio.
    // r7 se ignora (basura del llamador).
    return OnFxStart(r3 & 0xFFFFu, r4 & 0xFFu, r5 & 0xFFu,
                     r6 & 0xFFu) == 1;
  }
  // Demas entradas de audio: solo conteo (layout de
  // argumentos sin verificar; ver cabecera).
  return false;
}

uint64_t AudioBridge::QueuedFrames() const {
  uint64_t total = 0;
  auto add = [&total](const Voice& v) {
    if (!v.active) return;
    if (v.HasLoop()) {
      // Hasta el fin de la iteración actual del bucle.
      total += v.LoopEnd() > v.pos ? v.LoopEnd() - v.pos : 0;
    } else {
      total += v.Total() > v.pos ? v.Total() - v.pos : 0;
    }
  };
  for (const Voice& v : sfx_voices_) add(v);
  add(stream_voice_);
  if (StreamSourceActive()) {
    uint64_t total48 = stream_source_->TotalFrames48();
    uint64_t pos48 = stream_source_->Position48();
    total += total48 > pos48 ? total48 - pos48 : 0;
  }
  return total;
}

size_t AudioBridge::ActiveVoiceCount() const {
  size_t n = 0;
  for (const Voice& v : sfx_voices_) {
    if (v.active) ++n;
  }
  if (stream_voice_.active) ++n;
  if (StreamSourceActive()) ++n;
  return n;
}

std::vector<uint64_t> AudioBridge::ActiveVoicePositions() const {
  std::vector<uint64_t> out;
  for (const Voice& v : sfx_voices_) {
    if (v.active) out.push_back(static_cast<uint64_t>(v.pos));
  }
  if (stream_voice_.active) {
    out.push_back(static_cast<uint64_t>(stream_voice_.pos));
  }
  if (StreamSourceActive()) {
    out.push_back(stream_source_->Position48());
  }
  return out;
}

void AudioBridge::Tick() {
  if (audio_ == nullptr) return;
  // Una fuente en streaming que llego a EOF en el Tick
  // anterior se cierra aqui (no en mitad de la mezcla).
  if (stream_source_ != nullptr && stream_source_->AtEof()) {
    CloseStreamSource();
  }
  // Voces activas en orden: SFX (slots) + stream.
  Voice* voices[9];
  size_t nvoices = 0;
  for (Voice& v : sfx_voices_) {
    if (v.active) voices[nvoices++] = &v;
  }
  if (stream_voice_.active) voices[nvoices++] = &stream_voice_;
  bool stream_on = StreamSourceActive();
  if (nvoices == 0 && !stream_on) return;

  // Tamaño del bloque: el mayor restante entre voces no
  // en bucle (una voz en bucle puede llenar el bloque
  // entero), recortado a kFeedFrames. Así, con voces en
  // paralelo, el total entregado es el máximo de las
  // longitudes, no la suma (la serie anterior sumaba).
  // La fuente en streaming aporta kFeedFrames mientras
  // no llegue a EOF (su restante exacto lo conoce ella,
  // pero el bloque se recorta igual a kFeedFrames).
  size_t block = 0;
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    size_t avail = v->HasLoop()
                       ? static_cast<size_t>(kFeedFrames)
                       : (v->Total() > v->pos ? v->Total() - v->pos
                                              : 0);
    if (avail > block) block = avail;
  }
  if (stream_on && block < static_cast<size_t>(kFeedFrames)) {
    block = static_cast<size_t>(kFeedFrames);
  }
  if (block > static_cast<size_t>(kFeedFrames)) {
    block = static_cast<size_t>(kFeedFrames);
  }
  if (block == 0) return;

  // Bloque del stream en streaming (si lo hay): se lee
  // una sola vez por Tick, antes de mezclar.
  size_t stream_frames = 0;
  if (stream_on) {
    if (stream_scratch_.size() < block * 2) {
      stream_scratch_.resize(block * 2);
    }
    stream_frames =
        stream_source_->Read48k(stream_scratch_.data(), block);
  }

  // Suma en int32 y clamp duro UNA vez al final (no clamp
  // progresivo por voz: 20000+20000-20000 debe dar 20000,
  // no 12767).
  std::vector<int32_t> acc(block * 2, 0);
  // Voz en streaming: suma su bloque leido (puede ser
  // parcial en EOF; el resto del bloque es silencio para
  // ella, no para las demas voces).
  if (stream_on) {
    for (size_t f = 0; f < stream_frames; ++f) {
      acc[f * 2] += stream_scratch_[f * 2];
      acc[f * 2 + 1] += stream_scratch_[f * 2 + 1];
    }
  }
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    for (size_t f = 0; f < block; ++f) {
      size_t idx;
      if (v->HasLoop()) {
        size_t raw = v->pos + f;
        if (raw < v->LoopEnd()) {
          idx = raw;
        } else {
          idx = v->loop_start +
                (raw - v->LoopEnd()) % v->loop_len;
        }
      } else {
        if (v->pos + f >= v->Total()) continue;
        idx = v->pos + f;
      }
      acc[f * 2] += static_cast<int32_t>(std::lround(
          static_cast<float>(v->pcm[idx * 2]) * v->gain));
      acc[f * 2 + 1] += static_cast<int32_t>(std::lround(
          static_cast<float>(v->pcm[idx * 2 + 1]) * v->gain));
    }
  }
  std::vector<int16_t> mixed(block * 2);
  for (size_t i = 0; i < block * 2; ++i) {
    mixed[i] = ClampS16(acc[i]);
  }
  audio_->SubmitBuffer(mixed.data(), static_cast<int>(block));

  // Avance de la fuente en streaming: si llego a EOF con
  // este bloque, se cierra (la cache, si la habia, ya se
  // promovio al decodificar el ultimo frame nativo).
  if (stream_on && stream_source_->AtEof()) {
    CloseStreamSource();
  }

  // Avance: no en bucle termina en EOF; en bucle, al
  // llegar a loop_end se repite la región (la cola tras
  // loop_end nunca se alcanza).
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    if (v->HasLoop()) {
      size_t np = v->pos + block;
      if (np >= v->LoopEnd()) {
        v->pos = v->loop_start +
                 (np - v->LoopEnd()) % v->loop_len;
      } else {
        v->pos = np;
      }
    } else {
      v->pos += block;
      if (v->pos >= v->Total()) {
        v->active = false;
        v->pcm.clear();
        v->pos = 0;
      }
    }
  }
}

}  // namespace sfa
