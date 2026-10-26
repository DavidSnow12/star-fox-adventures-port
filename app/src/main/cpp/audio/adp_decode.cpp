#include "audio/adp_decode.h"

#include <cstdint>
#include <cstdio>
#include <vector>

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

// trunc(N/2048) exacto para N con signo (int64).
int32_t TruncDiv2048(int64_t n) {
  if (n >= 0) return static_cast<int32_t>(n >> 11);
  return static_cast<int32_t>(-((-n) >> 11));
}

}  // namespace

bool DecodeAdpFile(const char* path, Audio::WavData* out) {
  if (path == nullptr || out == nullptr) return false;
  FILE* in = std::fopen(path, "rb");
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
  std::vector<uint8_t> data(static_cast<size_t>(size > 0 ? size : 1));
  if (size > 0 &&
      std::fread(data.data(), 1, static_cast<size_t>(size), in) !=
          static_cast<size_t>(size)) {
    std::fclose(in);
    return false;
  }
  std::fclose(in);

  std::vector<int16_t> pcm;
  pcm.reserve(static_cast<size_t>(size / 32) * 28 * 2);
  int32_t x1l = 0, x2l = 0, x1r = 0, x2r = 0;
  long nblocks = size / 32;
  for (long b = 0; b < nblocks; ++b) {
    const uint8_t* blk = data.data() + b * 32;
    uint8_t hdr_l = blk[0], hdr_r = blk[1];
    int idx_l = hdr_l >> 4, idx_r = hdr_r >> 4;
    int32_t c1l = idx_l < 4 ? kC1[idx_l] : 0;
    int32_t c2l = idx_l < 4 ? kC2[idx_l] : 0;
    int32_t c1r = idx_r < 4 ? kC1[idx_r] : 0;
    int32_t c2r = idx_r < 4 ? kC2[idx_r] : 0;
    int32_t scale_l = 4096 >> (hdr_l & 0x0F);
    int32_t scale_r = 4096 >> (hdr_r & 0x0F);
    for (int j = 0; j < 28; ++j) {
      uint8_t byte = blk[4 + j];
      int lo = byte & 0x0F;
      if (lo >= 8) lo -= 16;
      int hi = byte >> 4;
      if (hi >= 8) hi -= 16;
      int32_t q = ClampX(TruncDiv2048(static_cast<int64_t>(c1l) * x1l +
                                      static_cast<int64_t>(c2l) * x2l));
      int32_t x = ClampX(lo * scale_l * 2048 + q);
      int16_t sl = static_cast<int16_t>(FloorDiv2048(x));
      x2l = x1l;
      x1l = x;
      q = ClampX(TruncDiv2048(static_cast<int64_t>(c1r) * x1r +
                              static_cast<int64_t>(c2r) * x2r));
      x = ClampX(hi * scale_r * 2048 + q);
      int16_t sr = static_cast<int16_t>(FloorDiv2048(x));
      x2r = x1r;
      x1r = x;
      pcm.push_back(sl);
      pcm.push_back(sr);
    }
  }
  out->rate = 32000;
  out->channels = 2;
  out->samples = std::move(pcm);
  return true;
}

}  // namespace sfa
