#include "audio/audio.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

#include "log.h"

namespace sfa {

namespace {

uint16_t ReadU16(const uint8_t* p) {
  return static_cast<uint16_t>(p[0] | (p[1] << 8));
}

uint32_t ReadU32(const uint8_t* p) {
  return static_cast<uint32_t>(p[0]) |
         (static_cast<uint32_t>(p[1]) << 8) |
         (static_cast<uint32_t>(p[2]) << 16) |
         (static_cast<uint32_t>(p[3]) << 24);
}

int16_t ClampS16(float v) {
  if (v > 32767.0f) return 32767;
  if (v < -32768.0f) return -32768;
  return static_cast<int16_t>(std::lrintf(v));
}

}  // namespace

bool Audio::Init() {
  ring_.assign(kRingFrames * 2, 0);
  ring_read_.store(0);
  ring_write_.store(0);
  submitted_frames_ = 0;
  delivered_frames_ = 0;
  dropped_frames_ = 0;
  backend_ok_ = false;
#if defined(__ANDROID__)
  backend_name_ = "AAudio";
#else
  backend_name_ = "host-null";
#endif
  SFA_LOGI("audio: inicializado (backend %s, salida %d Hz estereo)",
           backend_name_, kOutputRate);
  return true;
}

void Audio::Shutdown() {
  Stop();
  ring_.clear();
}

size_t Audio::RingAvailable() const {
  size_t r = ring_read_.load(std::memory_order_acquire);
  size_t w = ring_write_.load(std::memory_order_acquire);
  return (w >= r) ? (w - r) : (kRingFrames - (r - w));
}

size_t Audio::RingFree() const {
  size_t avail = RingAvailable();
  return avail >= kRingFrames ? 0 : (kRingFrames - avail);
}

size_t Audio::Drain(int16_t* out, size_t max_frames) {
  size_t avail = RingAvailable();
  size_t n = std::min(avail, max_frames);
  size_t r = ring_read_.load(std::memory_order_relaxed);
  for (size_t i = 0; i < n; ++i) {
    size_t idx = (r + i) % kRingFrames;
    out[i * 2] = ring_[idx * 2];
    out[i * 2 + 1] = ring_[idx * 2 + 1];
  }
  ring_read_.store((r + n) % kRingFrames, std::memory_order_release);
  return n;
}

void Audio::SubmitBuffer(const short* frames, int frame_count) {
  if (frame_count <= 0 || frames == nullptr) return;
  if (ring_.empty()) ring_.assign(kRingFrames * 2, 0);
  size_t w = ring_write_.load(std::memory_order_relaxed);
  size_t r = ring_read_.load(std::memory_order_acquire);
  size_t free = (w >= r) ? (kRingFrames - (w - r)) : (r - w);
  // Anillo lleno: se descartan los mas antiguos (el audio del
  // juego no puede bloquear el frame; la latencia baja manda).
  // Se deja siempre un frame libre para distinguir
  // lleno/vacio en el contador SPSC.
  size_t capacity = free > 0 ? free - 1 : 0;
  size_t n = static_cast<size_t>(frame_count);
  if (n > capacity) {
    size_t drop = n - capacity;
    dropped_frames_ += drop;
    // Avanzar el lector descarta lo mas antiguo.
    ring_read_.store((r + drop) % kRingFrames,
                     std::memory_order_release);
    r = ring_read_.load(std::memory_order_acquire);
    (void)r;
  }
  for (size_t i = 0; i < n; ++i) {
    size_t idx = (w + i) % kRingFrames;
    ring_[idx * 2] = ClampS16(frames[i * 2] * volume_);
    ring_[idx * 2 + 1] = ClampS16(frames[i * 2 + 1] * volume_);
  }
  ring_write_.store((w + n) % kRingFrames, std::memory_order_release);
  submitted_frames_ += n;
}

void Audio::SetMasterVolume(float volume) {
  if (volume < 0.0f) volume = 0.0f;
  if (volume > 1.0f) volume = 1.0f;
  volume_ = volume;
}

#if defined(__ANDROID__)

aaudio_data_callback_result_t Audio::DataCallback(
    AAudioStream* /*stream*/, void* user_data, void* audio_data,
    int32_t num_frames) {
  auto* self = static_cast<Audio*>(user_data);
  if (self == nullptr || audio_data == nullptr || num_frames <= 0) {
    return AAUDIO_CALLBACK_RESULT_CONTINUE;
  }
  auto* out = static_cast<int16_t*>(audio_data);
  size_t got = self->Drain(out, static_cast<size_t>(num_frames));
  if (got < static_cast<size_t>(num_frames)) {
    std::memset(out + got * 2, 0,
                (static_cast<size_t>(num_frames) - got) * 2 *
                    sizeof(int16_t));
  }
  self->delivered_frames_ += static_cast<uint64_t>(num_frames);
  return AAUDIO_CALLBACK_RESULT_CONTINUE;
}

bool Audio::OpenStream(aaudio_sharing_mode_t sharing) {
  AAudioStreamBuilder* builder = nullptr;
  if (AAudio_createStreamBuilder(&builder) != AAUDIO_OK ||
      builder == nullptr) {
    return false;
  }
  AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_OUTPUT);
  AAudioStreamBuilder_setSharingMode(builder, sharing);
  AAudioStreamBuilder_setPerformanceMode(
      builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);
  AAudioStreamBuilder_setSampleRate(builder, kOutputRate);
  AAudioStreamBuilder_setChannelCount(builder, 2);
  AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
  AAudioStreamBuilder_setDataCallback(builder, &Audio::DataCallback,
                                      this);
  aaudio_result_t result =
      AAudioStreamBuilder_openStream(builder, &stream_);
  AAudioStreamBuilder_delete(builder);
  if (result != AAUDIO_OK || stream_ == nullptr) {
    stream_ = nullptr;
    return false;
  }
  return AAudioStream_requestStart(stream_) == AAUDIO_OK;
}

#endif  // __ANDROID__

void Audio::Start() {
  if (started_) return;
  started_ = true;
#if defined(__ANDROID__)
  // Exclusivo primero (baja latencia); si el dispositivo lo
  // rechaza, compartido (siempre funciona en API 26+).
  backend_ok_ = OpenStream(AAUDIO_SHARING_MODE_EXCLUSIVE);
  if (!backend_ok_) {
    backend_ok_ = OpenStream(AAUDIO_SHARING_MODE_SHARED);
  }
  if (backend_ok_) {
    SFA_LOGI("audio: AAudio arrancado (%d Hz estereo)",
             kOutputRate);
  } else {
    SFA_LOGE("audio: AAudio no pudo abrirse (se sigue encolando "
             "sin sonido; ver logcat de audio)");
  }
#else
  backend_ok_ = true;
  SFA_LOGI("audio: backend host-null arrancado (sin sonido, "
           "entrega contada en Pump)");
#endif
}

void Audio::Stop() {
  if (!started_) return;
  started_ = false;
#if defined(__ANDROID__)
  if (stream_ != nullptr) {
    AAudioStream_requestStop(stream_);
    AAudioStream_close(stream_);
    stream_ = nullptr;
  }
#endif
  backend_ok_ = false;
}

void Audio::Pump() {
#if defined(__ANDROID__)
  // El callback AAudio drena; Pump no hace nada para no
  // robar frames al callback.
  (void)0;
#else
  // Host: drenar todo lo pendiente y contarlo como entrega.
  // (El bufer de drenaje es estatico para no reservar por
  // frame; el test host es monohilo.)
  static std::vector<int16_t> drain;
  if (drain.size() < kRingFrames * 2) drain.resize(kRingFrames * 2);
  size_t got = Drain(drain.data(), kRingFrames);
  delivered_frames_ += got;
#endif
}

bool Audio::LoadWavFile(const char* path, WavData* out) {
  if (path == nullptr || out == nullptr) return false;
  std::FILE* file = std::fopen(path, "rb");
  if (file == nullptr) return false;
  std::fseek(file, 0, SEEK_END);
  long size = std::ftell(file);
  std::fseek(file, 0, SEEK_SET);
  if (size < 44) {
    std::fclose(file);
    return false;
  }
  std::vector<uint8_t> data(static_cast<size_t>(size));
  if (std::fread(data.data(), 1, data.size(), file) != data.size()) {
    std::fclose(file);
    return false;
  }
  std::fclose(file);
  if (std::memcmp(data.data(), "RIFF", 4) != 0 ||
      std::memcmp(data.data() + 8, "WAVE", 4) != 0) {
    return false;
  }
  int format = -1;
  int channels = 0;
  int rate = 0;
  int bits = 0;
  size_t data_off = 0;
  size_t data_len = 0;
  size_t pos = 12;
  while (pos + 8 <= data.size()) {
    const char* id = reinterpret_cast<const char*>(data.data() + pos);
    uint32_t len = ReadU32(data.data() + pos + 4);
    size_t chunk_start = pos + 8;
    if (chunk_start + len > data.size()) return false;
    if (std::memcmp(id, "fmt ", 4) == 0 && len >= 16) {
      format = ReadU16(data.data() + chunk_start);
      channels = ReadU16(data.data() + chunk_start + 2);
      rate = static_cast<int>(ReadU32(data.data() + chunk_start + 4));
      bits = ReadU16(data.data() + chunk_start + 14);
    } else if (std::memcmp(id, "data", 4) == 0) {
      data_off = chunk_start;
      data_len = len;
    }
    pos = chunk_start + len + (len & 1u);
  }
  // Solo PCM16, que es lo que produce el extractor (ver
  // inventario: WAV PCM16 DTK-ADPCM / DSP-ADPCM decodificados).
  if (format != 1 || bits != 16 || (channels != 1 && channels != 2) ||
      rate <= 0 || data_len == 0) {
    return false;
  }
  size_t frames = data_len / (static_cast<size_t>(channels) * 2u);
  out->rate = rate;
  out->channels = channels;
  out->samples.resize(frames * static_cast<size_t>(channels));
  for (size_t i = 0; i < frames * static_cast<size_t>(channels); ++i) {
    out->samples[i] = static_cast<int16_t>(
        ReadU16(data.data() + data_off + i * 2));
  }
  return true;
}

std::vector<int16_t> Audio::ResampleToStereo(const WavData& in,
                                             int out_rate) {
  std::vector<int16_t> out;
  if (in.rate <= 0 || out_rate <= 0 || in.channels < 1 ||
      in.channels > 2 || in.samples.empty()) {
    return out;
  }
  uint64_t in_frames = in.Frames();
  uint64_t out_frames =
      in_frames * static_cast<uint64_t>(out_rate) /
      static_cast<uint64_t>(in.rate);
  if (out_frames == 0) out_frames = 1;
  out.resize(static_cast<size_t>(out_frames) * 2);
  for (uint64_t j = 0; j < out_frames; ++j) {
    double pos = static_cast<double>(j) * in.rate / out_rate;
    uint64_t i0 = static_cast<uint64_t>(pos);
    if (i0 >= in_frames) i0 = in_frames - 1;
    uint64_t i1 = i0 + 1 < in_frames ? i0 + 1 : i0;
    double frac = pos - static_cast<double>(i0);
    for (int ch = 0; ch < 2; ++ch) {
      int src_ch = in.channels == 1 ? 0 : ch;
      double s0 = in.samples[i0 * static_cast<uint64_t>(in.channels) +
                             static_cast<uint64_t>(src_ch)];
      double s1 = in.samples[i1 * static_cast<uint64_t>(in.channels) +
                             static_cast<uint64_t>(src_ch)];
      out[j * 2 + static_cast<uint64_t>(ch)] =
          ClampS16(static_cast<float>(s0 * (1.0 - frac) + s1 * frac));
    }
  }
  return out;
}

int Audio::PlayWavFile(const char* path) {
  WavData wav;
  if (!LoadWavFile(path, &wav)) {
    SFA_LOGE("audio: PlayWavFile: '%s' no es WAV PCM16 legible",
             path != nullptr ? path : "(null)");
    return -1;
  }
  std::vector<int16_t> pcm = ResampleToStereo(wav, kOutputRate);
  if (pcm.empty()) return -1;
  int frames = static_cast<int>(pcm.size() / 2);
  // Se encola entero: si el llamador no drena (Pump en host,
  // callback AAudio en Android) y el fichero supera el anillo
  // (262.144 frames, ~5,5 s), el anillo descarta lo mas
  // antiguo y DroppedFrames() lo cuenta. Para streams largos
  // el llamador debe entregar por trozos con drenaje entre
  // ellos (asi lo hace el test host); este metodo es directo
  // para muestras cortas (MusyX, < 1 s).
  SubmitBuffer(pcm.data(), frames);
  SFA_LOGI("audio: PlayWavFile '%s': %d Hz x%d -> %d Hz estereo, "
           "%d frames",
           path, wav.rate, wav.channels, kOutputRate, frames);
  return frames;
}

}  // namespace sfa
