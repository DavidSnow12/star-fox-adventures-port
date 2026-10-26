#include "audio/audio_bridge.h"

#include "audio/audio_id_map.h"
#include "log.h"

namespace sfa {

namespace {

// Direcciones guest verificadas en codigo/symbols.map.
constexpr uint32_t kAudioStreamPlay = 0x8000D220u;
constexpr uint32_t kAudioStreamStopCurrent = 0x8000D03Cu;

}  // namespace

const char* AudioBridge::LookupStreamWav(uint32_t id) const {
  for (const StreamIdEntry& e : kStreamIdMap) {
    if (e.id == id) return e.wav;
  }
  return nullptr;
}

const char* AudioBridge::LookupSampleWav(uint32_t id) const {
  for (const MusyxSampleEntry& e : kMusyxSampleMap) {
    if (e.id == id) return e.wav;
  }
  return nullptr;
}

bool AudioBridge::EnqueueWav(const char* rel, uint32_t id,
                             const char* kind) {
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
  Queued q;
  q.pcm = std::move(pcm);
  queued_frames_ += q.pcm.size() / 2;
  queue_.push_back(std::move(q));
  SFA_LOGI("bridge: %s id %u -> '%s' (%d Hz x%d, %llu frames "
           "a 48 kHz)",
           kind, id, rel, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k));
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
  if (!EnqueueWav(wav, stream_id, "stream")) {
    Unresolved u;
    u.id = stream_id;
    u.kind = "stream";
    unresolved_.push_back(u);
    return false;
  }
  return true;
}

void AudioBridge::OnStreamStop() {
  // Detener = vaciar la cola del bridge. El backend sigue
  // con lo ya entregado (el anillo se drena solo); no se
  // puede "des-entregar" lo enviado, y no se pretende.
  queued_frames_ = 0;
  queue_.clear();
  SFA_LOGI("bridge: stop de stream (cola vaciada)");
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
  int enqueued = 0;
  for (int i = 0; i < 4; ++i) {
    uint16_t sample = found->samples[i];
    if (sample == 0) continue;  // Sin muestra (ver generador).
    const char* wav = LookupSampleWav(sample);
    if (wav == nullptr) continue;
    if (EnqueueWav(wav, sample, "sfx_muestra")) ++enqueued;
  }
  if (enqueued == 0) {
    // Trigger conocido pero sin muestra directa (secuencia o
    // grupo MusyX): queda como no resuelto, no como silencio
    // inventado.
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u sin muestra directa "
             "(secuencia/grupo, fuera de esta fase)",
             trigger_id);
  }
  return enqueued;
}

bool AudioBridge::OnAudioEntry(uint32_t pc, uint32_t r3,
                               uint32_t /*r4*/, uint32_t /*r5*/) {
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

void AudioBridge::Tick() {
  if (audio_ == nullptr) return;
  int budget = kFeedFrames;
  while (budget > 0 && !queue_.empty()) {
    Queued& q = queue_.front();
    size_t total = q.pcm.size() / 2;
    size_t remaining = total - q.pos;
    if (remaining == 0) {
      queue_.erase(queue_.begin());
      continue;
    }
    size_t n = remaining < static_cast<size_t>(budget)
                   ? remaining
                   : static_cast<size_t>(budget);
    audio_->SubmitBuffer(q.pcm.data() + q.pos * 2,
                         static_cast<int>(n));
    q.pos += n;
    queued_frames_ -= n;
    budget -= static_cast<int>(n);
    if (q.pos >= total) queue_.erase(queue_.begin());
  }
}

}  // namespace sfa
