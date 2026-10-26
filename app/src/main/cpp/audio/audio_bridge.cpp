#include "audio/audio_bridge.h"

#include <algorithm>
#include <cmath>

#include "audio/audio_id_map.h"
#include "log.h"

namespace sfa {

namespace {

// Direcciones guest verificadas en codigo/symbols.map.
constexpr uint32_t kAudioStreamPlay = 0x8000D220u;
constexpr uint32_t kAudioStreamStopCurrent = 0x8000D03Cu;

int16_t ClampS16(int32_t v) {
  if (v > 32767) return 32767;
  if (v < -32768) return -32768;
  return static_cast<int16_t>(v);
}

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
  Voice* slot = nullptr;
  if (is_stream) {
    slot = &stream_voice_;  // La voz de stream es única:
    // un nuevo Play sustituye al anterior (no se encola
    // detrás: el juego tiene un solo stream actual).
  } else {
    for (Voice& v : sfx_voices_) {
      if (!v.active) {
        slot = &v;
        break;
      }
    }
    if (slot == nullptr) {
      // Paso 1: descartar y contar, no robar voces (el robo
      // por antigüedad/volumen es el paso siguiente, una
      // vez medido qué voces conviven en trazas reales).
      ++dropped_sfx_;
      SFA_LOGI("bridge: SFX id %u descartado (8 voces "
               "ocupadas)", id);
      return false;
    }
  }
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += rel;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV no legible '%s' (id %u, %s)",
             path.c_str(), id, kind);
    return false;
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
  if (!EnqueueWav(wav, stream_id, "stream", 1.0f, 0, 0, true)) {
    Unresolved u;
    u.id = stream_id;
    u.kind = "stream";
    unresolved_.push_back(u);
    return false;
  }
  return true;
}

void AudioBridge::OnStreamStop() {
  // Detener SOLO la voz de stream. El backend sigue con lo
  // ya entregado (el anillo se drena solo); no se puede
  // "des-entregar" lo enviado, y no se pretende. Los SFX
  // en curso NO se tocan (Fase 17: antes se vaciaba toda
  // la cola serial, incluidos SFX que sonaban en paralelo).
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
  // simultáneos. El bridge anterior encolaba los 4 en serie, lo
  // que sonaba mal con cara de correcto (p. ej. trigger 1:
  // 420-423 son menú, pausa y pasos, sin relación entre sí).
  // Hasta que los pesos estén en el mapa, se reproduce la
  // primera variante no nula documentada como aproximación;
  // para triggers de variante única (un solo campo no nulo)
  // esa primera variante ES la única, sin ambigüedad.
  // TODO(Fase 16, siguiente paso): pesos + volRand/pitchRand
  // en audio_id_map.h y selección ponderada real.
  // BLOQUEADOR del primer SFX real por hook (no por trigger):
  // el campo de muestra entra a dataGetFX y la muestra real
  // es el descriptor FX[2]; si la tabla FX no es la
  // identidad, este camino por trigger sonaría con el WAV
  // equivocado aunque el trigger sea correcto. Ver
  // PORT-STATUS Fase 16, punto 4.
  // SFX no usa EnqueueWav: necesita el bucle reescalado a
  // 48 kHz, que solo se conoce tras cargar el WAV (su
  // wav.rate). Se carga una sola vez aquí.
  int enqueued = 0;
  for (int i = 0; i < 4; ++i) {
    uint16_t sample = found->samples[i];
    if (sample == 0) continue;
    const MusyxSampleEntry* entry = LookupSampleEntry(sample);
    if (entry == nullptr) continue;
    // Buscar slot libre (sin contar dropped dos veces:
    // si no hay slot, EnqueueWavSfx no se llama).
    Voice* slot = nullptr;
    for (Voice& v : sfx_voices_) {
      if (!v.active) {
        slot = &v;
        break;
      }
    }
    if (slot == nullptr) {
      ++dropped_sfx_;
      SFA_LOGI("bridge: SFX trigger %u descartado (8 voces "
               "ocupadas)", trigger_id);
      return 0;
    }
    std::string path = wav_root_;
    if (!path.empty() && path.back() != '/') path += '/';
    path += entry->wav;
    Audio::WavData wav;
    if (!Audio::LoadWavFile(path.c_str(), &wav)) {
      Unresolved u;
      u.id = trigger_id;
      u.kind = "sfx_trigger";
      unresolved_.push_back(u);
      return 0;
    }
    std::vector<int16_t> pcm =
        Audio::ResampleToStereo(wav, Audio::kOutputRate);
    if (pcm.empty()) {
      Unresolved u;
      u.id = trigger_id;
      u.kind = "sfx_trigger";
      unresolved_.push_back(u);
      return 0;
    }
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
      // El bucle reescalado nunca debe pasar del total
      // resampleado (redondeo): se recorta al total.
      size_t total = pcm.size() / 2;
      if (loop_start_48k + loop_len_48k > total) {
        loop_len_48k = total > loop_start_48k
                           ? total - loop_start_48k
                           : 0;
      }
    }
    Played p;
    p.id = sample;
    p.kind = "sfx_muestra";
    p.wav = entry->wav;
    p.src_rate = wav.rate;
    p.src_channels = wav.channels;
    p.frames_48k = pcm.size() / 2;
    played_.push_back(p);
    slot->pcm = std::move(pcm);
    slot->pos = 0;
    slot->gain = static_cast<float>(found->vol_base) / 127.0f;
    slot->loop_start = loop_start_48k;
    slot->loop_len = loop_len_48k;
    slot->active = true;
    SFA_LOGI("bridge: sfx_muestra id %u -> '%s' (%d Hz x%d, "
             "%llu frames a 48 kHz, bucle [%llu, %llu), "
             "ganancia %.3f)",
             sample, entry->wav, wav.rate, wav.channels,
             static_cast<unsigned long long>(p.frames_48k),
             static_cast<unsigned long long>(loop_start_48k),
             static_cast<unsigned long long>(loop_start_48k +
                                              loop_len_48k),
             static_cast<double>(slot->gain));
    enqueued = 1;
    break;  // Solo una variante por disparo (ver arriba).
  }
  if (enqueued == 0) {
    // Trigger conocido pero sin muestra directa (secuencia o
    // grupo MusyX): queda como no resuelto, no como silencio
    // inventado. (Si el motivo fue voces llenas, ya se
    // contó en dropped_sfx_ y se retornó arriba; este
    // camino es solo para "sin muestra".)
    // Nota: si el bucle anterior retornó por voces llenas,
    // no se llega aquí. Si se llega aquí, no hubo muestra.
    bool any_sample = false;
    for (int i = 0; i < 4; ++i) {
      if (found->samples[i] != 0 &&
          LookupSampleEntry(found->samples[i]) != nullptr) {
        any_sample = true;
      }
    }
    if (!any_sample) {
      Unresolved u;
      u.id = trigger_id;
      u.kind = "sfx_trigger";
      unresolved_.push_back(u);
      SFA_LOGI("bridge: trigger SFX id %u sin muestra directa "
               "(secuencia/grupo, fuera de esta fase)",
               trigger_id);
    }
  }
  return enqueued;
}

bool AudioBridge::OnAudioEntry(uint32_t pc, uint32_t r3,
                               uint32_t /*r4*/, uint32_t /*r5*/,
                               uint32_t /*r6*/, uint32_t /*r7*/) {
  Counted c;
  c.pc = pc;
  c.r3 = r3;
  counted_.push_back(c);
  if (pc == kAudioStreamPlay) return OnStreamPlay(r3);
  if (pc == kAudioStreamStopCurrent) {
    OnStreamStop();
    return true;
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
  return total;
}

size_t AudioBridge::ActiveVoiceCount() const {
  size_t n = 0;
  for (const Voice& v : sfx_voices_) {
    if (v.active) ++n;
  }
  if (stream_voice_.active) ++n;
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
  return out;
}

void AudioBridge::Tick() {
  if (audio_ == nullptr) return;
  // Voces activas en orden: SFX (slots) + stream.
  Voice* voices[9];
  size_t nvoices = 0;
  for (Voice& v : sfx_voices_) {
    if (v.active) voices[nvoices++] = &v;
  }
  if (stream_voice_.active) voices[nvoices++] = &stream_voice_;
  if (nvoices == 0) return;

  // Tamaño del bloque: el mayor restante entre voces no
  // en bucle (una voz en bucle puede llenar el bloque
  // entero), recortado a kFeedFrames. Así, con voces en
  // paralelo, el total entregado es el máximo de las
  // longitudes, no la suma (la serie anterior sumaba).
  size_t block = 0;
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    size_t avail = v->HasLoop()
                       ? static_cast<size_t>(kFeedFrames)
                       : (v->Total() > v->pos ? v->Total() - v->pos
                                              : 0);
    if (avail > block) block = avail;
  }
  if (block > static_cast<size_t>(kFeedFrames)) {
    block = static_cast<size_t>(kFeedFrames);
  }
  if (block == 0) return;

  // Suma en int32 y clamp duro UNA vez al final (no clamp
  // progresivo por voz: 20000+20000-20000 debe dar 20000,
  // no 12767).
  std::vector<int32_t> acc(block * 2, 0);
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
