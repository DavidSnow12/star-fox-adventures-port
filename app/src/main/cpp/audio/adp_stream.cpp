#include "audio/adp_stream.h"

#include <algorithm>
#include <cmath>

namespace sfa {

namespace {

const int32_t kC1[4] = {0, 1920, 3680, 3136};
const int32_t kC2[4] = {0, 0, -1664, -1760};
const int32_t kXMax = 32767 * 2048;
const int32_t kXMin = -32768 * 2048;

int32_t ClampX(int32_t v) {
  if (v > kXMax) return kXMax;
  if (v < kXMin) return kXMin;
  return v;
}

// floor(X/2048) exacto con desplazamientos (2048 = 2^11).
int32_t FloorDiv2048(int32_t x) {
  if (x >= 0) return x >> 11;
  return -(((-x) + 2047) >> 11);
}

// trunc(N/2048) exacto para N con signo (int64). En C la
// division entera ya trunca hacia cero; con desplazamiento
// se hace explicito y se evita depender del compilador.
int32_t TruncDiv2048(int64_t n) {
  if (n >= 0) return static_cast<int32_t>(n >> 11);
  return static_cast<int32_t>(-((-n) >> 11));
}

int16_t ClampS16(double v) {
  if (v > 32767.0) return 32767;
  if (v < -32768.0) return -32768;
  return static_cast<int16_t>(std::lrint(v));
}

}  // namespace

bool DecodeDtkBlock(const uint8_t* block, DtkState* state,
                    int16_t* out_28_frames) {
  if (block == nullptr || state == nullptr || out_28_frames == nullptr) {
    return false;
  }
  uint8_t hdr_l = block[0], hdr_r = block[1];
  // Bytes 2-3 son copias redundantes de 0-1 (siempre iguales
  // en todo el disco); se ignoran, como en adp_decode.cpp.
  int idx_l = hdr_l >> 4, idx_r = hdr_r >> 4;
  int32_t c1l = idx_l < 4 ? kC1[idx_l] : 0;
  int32_t c2l = idx_l < 4 ? kC2[idx_l] : 0;
  int32_t c1r = idx_r < 4 ? kC1[idx_r] : 0;
  int32_t c2r = idx_r < 4 ? kC2[idx_r] : 0;
  // Exponente 13-15 -> escala 0 (4096 >> exp), igual que
  // host/FFmpeg: cabecera fuera de rango no es error.
  int32_t scale_l = 4096 >> (hdr_l & 0x0F);
  int32_t scale_r = 4096 >> (hdr_r & 0x0F);
  for (int j = 0; j < 28; ++j) {
    uint8_t byte = block[4 + j];
    int lo = byte & 0x0F;
    if (lo >= 8) lo -= 16;
    int hi = byte >> 4;
    if (hi >= 8) hi -= 16;
    // Acumulador int64 OBLIGATORIO: c*X llega a ~2,5e11.
    int32_t q = ClampX(TruncDiv2048(static_cast<int64_t>(c1l) * state->x1l +
                                    static_cast<int64_t>(c2l) * state->x2l));
    int32_t x = ClampX(lo * scale_l * 2048 + q);
    out_28_frames[j * 2] = static_cast<int16_t>(FloorDiv2048(x));
    state->x2l = state->x1l;
    state->x1l = x;
    q = ClampX(TruncDiv2048(static_cast<int64_t>(c1r) * state->x1r +
                            static_cast<int64_t>(c2r) * state->x2r));
    x = ClampX(hi * scale_r * 2048 + q);
    out_28_frames[j * 2 + 1] = static_cast<int16_t>(FloorDiv2048(x));
    state->x2r = state->x1r;
    state->x1r = x;
  }
  return true;
}

AdpStreamDecoder::~AdpStreamDecoder() { Close(); }

bool AdpStreamDecoder::Open(const char* adp_path) {
  Close();
  if (adp_path == nullptr) return false;
  std::FILE* in = std::fopen(adp_path, "rb");
  if (in == nullptr) return false;
  if (std::fseek(in, 0, SEEK_END) != 0) {
    std::fclose(in);
    return false;
  }
  long size = std::ftell(in);
  if (size < 0 || size % 32 != 0) {
    std::fclose(in);
    return false;
  }
  if (std::fseek(in, 0, SEEK_SET) != 0) {
    std::fclose(in);
    return false;
  }
  file_ = in;
  total_frames_ = static_cast<uint64_t>(size / 32) * 28u;
  position_ = 0;
  state_ = DtkState();
  block_len_ = 0;
  block_pos_ = 0;
  return true;
}

void AdpStreamDecoder::Close() {
  if (file_ != nullptr) {
    std::fclose(file_);
    file_ = nullptr;
  }
  total_frames_ = 0;
  position_ = 0;
  block_len_ = 0;
  block_pos_ = 0;
}

size_t AdpStreamDecoder::ReadNative(int16_t* out, size_t max_frames) {
  if (out == nullptr || file_ == nullptr || max_frames == 0) return 0;
  size_t delivered = 0;
  while (delivered < max_frames && position_ < total_frames_) {
    if (block_pos_ >= block_len_) {
      // Decodificar el siguiente bloque de 32 B.
      uint8_t block[32];
      if (std::fread(block, 1, 32, file_) != 32) {
        break;  // Truncado inesperado: EOF prematuro, sin crash.
      }
      if (!DecodeDtkBlock(block, &state_, block_pcm_)) break;
      block_len_ = 28;
      block_pos_ = 0;
    }
    size_t avail = block_len_ - block_pos_;
    size_t want = std::min(avail, max_frames - delivered);
    for (size_t i = 0; i < want; ++i) {
      out[(delivered + i) * 2] = block_pcm_[(block_pos_ + i) * 2];
      out[(delivered + i) * 2 + 1] =
          block_pcm_[(block_pos_ + i) * 2 + 1];
    }
    block_pos_ += want;
    delivered += want;
    position_ += want;
  }
  return delivered;
}

PcmNativeReader::~PcmNativeReader() { Close(); }

bool PcmNativeReader::Open(const char* pcm_path) {
  Close();
  if (pcm_path == nullptr) return false;
  std::FILE* in = std::fopen(pcm_path, "rb");
  if (in == nullptr) return false;
  if (std::fseek(in, 0, SEEK_END) != 0) {
    std::fclose(in);
    return false;
  }
  long size = std::ftell(in);
  if (size < 0 || size % 4 != 0) {
    std::fclose(in);
    return false;
  }
  if (std::fseek(in, 0, SEEK_SET) != 0) {
    std::fclose(in);
    return false;
  }
  file_ = in;
  total_frames_ = static_cast<uint64_t>(size) / 4u;
  position_ = 0;
  return true;
}

void PcmNativeReader::Close() {
  if (file_ != nullptr) {
    std::fclose(file_);
    file_ = nullptr;
  }
  total_frames_ = 0;
  position_ = 0;
}

size_t PcmNativeReader::ReadNative(int16_t* out, size_t max_frames) {
  if (out == nullptr || file_ == nullptr || max_frames == 0) return 0;
  size_t remaining = total_frames_ > position_
                         ? static_cast<size_t>(total_frames_ - position_)
                         : 0;
  size_t want = std::min(remaining, max_frames);
  if (want == 0) return 0;
  size_t got = std::fread(out, 4, want, file_);
  position_ += got;
  return got;
}

uint64_t ResamplingSource::TotalFrames48() const {
  if (reader_ == nullptr) return 0;
  // Misma formula truncante que ResampleToStereo.
  return reader_->TotalNativeFrames() * 48000u / 32000u;
}

bool ResamplingSource::GetFrame(uint64_t idx, int16_t* frame_out) {
  if (reader_ == nullptr) return false;
  if (idx >= reader_->TotalNativeFrames()) return false;
  if (!chunk_.empty() && idx >= chunk_base_ &&
      idx < chunk_base_ + chunk_len_) {
    size_t off = static_cast<size_t>(idx - chunk_base_);
    frame_out[0] = chunk_[off * 2];
    frame_out[1] = chunk_[off * 2 + 1];
    return true;
  }
  // Fuera del chunk: solo se puede avanzar al siguiente
  // chunk (idx debe ser exactamente el primer frame no
  // leido todavia; i0 es monotono y avanza de uno en uno,
  // asi que en uso real siempre coincide). Retroceder o
  // saltar es error: no se rebobina ni se inventan frames.
  if (idx != next_native_) return false;
  chunk_.assign(kChunkFrames * 2, 0);
  size_t got = reader_->ReadNative(chunk_.data(), kChunkFrames);
  if (got == 0) return false;
  chunk_base_ = next_native_;
  next_native_ += got;
  chunk_len_ = got;
  size_t off = static_cast<size_t>(idx - chunk_base_);
  if (off >= chunk_len_) return false;
  frame_out[0] = chunk_[off * 2];
  frame_out[1] = chunk_[off * 2 + 1];
  return true;
}

size_t ResamplingSource::Read48k(int16_t* out, size_t max_frames) {
  if (out == nullptr || reader_ == nullptr || max_frames == 0) return 0;
  uint64_t total48 = TotalFrames48();
  uint64_t total_native = reader_->TotalNativeFrames();
  size_t delivered = 0;
  while (delivered < max_frames && out_index_ < total48) {
    // Identico a ResampleToStereo: pos en doble, i0 por
    // truncacion, i1 clamp al ultimo frame.
    double pos =
        static_cast<double>(out_index_) * 32000.0 / 48000.0;
    uint64_t i0 = static_cast<uint64_t>(pos);
    if (i0 >= total_native) {
      eof_ = true;
      break;
    }
    uint64_t i1 = i0 + 1 < total_native ? i0 + 1 : i0;
    double frac = pos - static_cast<double>(i0);
    int16_t f0[2], f1[2];
    if (!GetFrame(i0, f0) || !GetFrame(i1, f1)) {
      eof_ = true;
      break;  // EOF prematuro: cortar sin crash ni silencio inventado.
    }
    for (int ch = 0; ch < 2; ++ch) {
      double s0 = f0[ch];
      double s1 = f1[ch];
      out[delivered * 2 + ch] =
          ClampS16(static_cast<float>(s0 * (1.0 - frac) + s1 * frac));
    }
    ++out_index_;
    ++delivered;
  }
  if (out_index_ >= total48) eof_ = true;
  return delivered;
}

}  // namespace sfa
