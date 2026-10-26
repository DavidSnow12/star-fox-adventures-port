#include "audio/adp_cache.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <ctime>

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

namespace sfa {

namespace {

// ---------- Utilidades POSIX ----------

bool IsDir(const std::string& path) {
  struct stat st;
  return ::stat(path.c_str(), &st) == 0 && S_ISDIR(st.st_mode);
}

bool FileSize(const std::string& path, uint64_t* out) {
  struct stat st;
  if (::stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode)) {
    return false;
  }
  *out = static_cast<uint64_t>(st.st_size);
  return true;
}

int64_t FileMtime(const std::string& path) {
  struct stat st;
  if (::stat(path.c_str(), &st) != 0) return 0;
  return static_cast<int64_t>(st.st_mtime);
}

// mkdir -p (best effort; ignora "ya existe").
bool MkdirP(const std::string& path) {
  if (path.empty()) return false;
  std::string cur;
  size_t i = 0;
  if (path[0] == '/') {
    cur = "/";
    i = 1;
  }
  while (i <= path.size()) {
    size_t slash = path.find('/', i);
    std::string part = path.substr(i, slash == std::string::npos
                                           ? std::string::npos
                                           : slash - i);
    if (!part.empty() && part != ".") {
      if (!cur.empty() && cur.back() != '/') cur += '/';
      cur += part;
      if (::mkdir(cur.c_str(), 0777) != 0 && !IsDir(cur)) return false;
    }
    if (slash == std::string::npos) break;
    i = slash + 1;
  }
  return IsDir(path);
}

std::string DirOf(const std::string& path) {
  size_t slash = path.rfind('/');
  if (slash == std::string::npos) return "";
  if (slash == 0) return "/";
  return path.substr(0, slash);
}

bool EndsWith(const std::string& s, const std::string& suffix) {
  return s.size() >= suffix.size() &&
         s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string ToLowerAscii(std::string s) {
  for (char& c : s) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return s;
}

// Escritura atomica de un fichero pequeno: <path>.tmp +
// rename. Si falla, queda el fichero viejo (o ninguno),
// nunca uno a medias como destino final.
bool WriteFileAtomic(const std::string& path, const std::string& data) {
  std::string tmp = path + ".tmp";
  std::FILE* f = std::fopen(tmp.c_str(), "wb");
  if (f == nullptr) return false;
  bool ok = data.empty() ||
            std::fwrite(data.data(), 1, data.size(), f) == data.size();
  if (std::fclose(f) != 0) ok = false;
  if (!ok) {
    std::remove(tmp.c_str());
    return false;
  }
  if (std::rename(tmp.c_str(), path.c_str()) != 0) {
    std::remove(tmp.c_str());
    return false;
  }
  return true;
}

// ---------- SHA-1 (FIPS 180-1, implementacion propia) ----------

uint32_t Rotl32(uint32_t v, int n) { return (v << n) | (v >> (32 - n)); }

struct Sha1Ctx {
  uint32_t h[5] = {0x67452301u, 0xEFCDAB89u, 0x98BADCFEu,
                   0x10325476u, 0xC3D2E1F0u};
  uint64_t total = 0;  // Bytes procesados.
  uint8_t buf[64];
  size_t buf_len = 0;

  void Block(const uint8_t* p) {
    uint32_t w[80];
    for (int i = 0; i < 16; ++i) {
      w[i] = (static_cast<uint32_t>(p[i * 4]) << 24) |
             (static_cast<uint32_t>(p[i * 4 + 1]) << 16) |
             (static_cast<uint32_t>(p[i * 4 + 2]) << 8) |
             static_cast<uint32_t>(p[i * 4 + 3]);
    }
    for (int i = 16; i < 80; ++i) {
      w[i] = Rotl32(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    }
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
    for (int i = 0; i < 80; ++i) {
      uint32_t f, k;
      if (i < 20) {
        f = (b & c) | ((~b) & d);
        k = 0x5A827999u;
      } else if (i < 40) {
        f = b ^ c ^ d;
        k = 0x6ED9EBA1u;
      } else if (i < 60) {
        f = (b & c) | (b & d) | (c & d);
        k = 0x8F1BBCDCu;
      } else {
        f = b ^ c ^ d;
        k = 0xCA62C1D6u;
      }
      uint32_t tmp = Rotl32(a, 5) + f + e + k + w[i];
      e = d;
      d = c;
      c = Rotl32(b, 30);
      b = a;
      a = tmp;
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
  }

  void Update(const uint8_t* data, size_t len) {
    total += len;
    while (len > 0) {
      size_t take = std::min(len, sizeof(buf) - buf_len);
      std::memcpy(buf + buf_len, data, take);
      buf_len += take;
      data += take;
      len -= take;
      if (buf_len == 64) {
        Block(buf);
        buf_len = 0;
      }
    }
  }

  std::string FinalHex() {
    uint64_t bits = total * 8u;
    uint8_t pad = 0x80;
    Update(&pad, 1);
    uint8_t zero = 0;
    while (buf_len != 56) Update(&zero, 1);
    uint8_t lenbuf[8];
    for (int i = 0; i < 8; ++i) {
      lenbuf[i] = static_cast<uint8_t>(bits >> (56 - 8 * i));
    }
    // Alimentar directamente sin tocar total (ya no importa).
    for (int i = 0; i < 8; ++i) {
      buf[buf_len++] = lenbuf[i];
      if (buf_len == 64) {
        Block(buf);
        buf_len = 0;
      }
    }
    char hex[41];
    for (int i = 0; i < 5; ++i) {
      std::snprintf(hex + i * 8, 9, "%08x", h[i]);
    }
    return std::string(hex, 40);
  }
};

// ---------- Parseo minimo de .meta (sin libreria JSON) ----------

// Extrae el valor de "clave": <numero> (entero sin signo).
bool MetaNumber(const std::string& json, const std::string& key,
                uint64_t* out) {
  std::string pat = "\"" + key + "\"";
  size_t p = json.find(pat);
  if (p == std::string::npos) return false;
  p = json.find(':', p + pat.size());
  if (p == std::string::npos) return false;
  ++p;
  while (p < json.size() &&
         (json[p] == ' ' || json[p] == '\t' || json[p] == '\n')) {
    ++p;
  }
  // Permitir signo negativo (last_used nunca lo es, pero el
  // parseo no debe fallar por un '-' inesperado).
  bool neg = false;
  if (p < json.size() && json[p] == '-') {
    neg = true;
    ++p;
  }
  if (p >= json.size() || json[p] < '0' || json[p] > '9') return false;
  uint64_t v = 0;
  while (p < json.size() && json[p] >= '0' && json[p] <= '9') {
    v = v * 10 + static_cast<uint64_t>(json[p] - '0');
    ++p;
  }
  *out = neg ? static_cast<uint64_t>(-static_cast<int64_t>(v)) : v;
  return true;
}

// Extrae el valor de "clave": "texto" (sin escapes: nuestros
// valores nunca llevan comillas ni barras).
bool MetaString(const std::string& json, const std::string& key,
                std::string* out) {
  std::string pat = "\"" + key + "\"";
  size_t p = json.find(pat);
  if (p == std::string::npos) return false;
  p = json.find(':', p + pat.size());
  if (p == std::string::npos) return false;
  p = json.find('"', p);
  if (p == std::string::npos) return false;
  size_t q = json.find('"', p + 1);
  if (q == std::string::npos) return false;
  *out = json.substr(p + 1, q - p - 1);
  return true;
}

std::string MetaJson(const AdpCacheMeta& m) {
  char buf[1024];
  std::snprintf(
      buf, sizeof(buf),
      "{\n  \"decoder\": \"%s\",\n  \"adp_rel\": \"%s\",\n"
      "  \"adp_bytes\": %llu,\n  \"adp_sha1\": \"%s\",\n"
      "  \"pcm_frames\": %llu,\n  \"rate\": %d,\n  \"channels\": %d,\n"
      "  \"pcm_bytes\": %llu,\n  \"last_used\": %lld\n}\n",
      m.decoder.c_str(), m.adp_rel.c_str(),
      static_cast<unsigned long long>(m.adp_bytes),
      m.adp_sha1.c_str(),
      static_cast<unsigned long long>(m.pcm_frames), m.rate,
      m.channels, static_cast<unsigned long long>(m.pcm_bytes),
      static_cast<long long>(m.last_used));
  return std::string(buf);
}

// Milisegundos Unix, estrictamente crecientes por proceso
// (ver cabecera: sin esto, el LRU empataria en el mismo
// segundo/milisegundo y desalojaria por orden alfabetico).
int64_t NowMsMonotonic() {
  static int64_t last = 0;
  struct timespec ts;
  int64_t now = 0;
  if (::clock_gettime(CLOCK_REALTIME, &ts) == 0) {
    now = static_cast<int64_t>(ts.tv_sec) * 1000 +
          static_cast<int64_t>(ts.tv_nsec) / 1000000;
  } else {
    now = static_cast<int64_t>(std::time(nullptr)) * 1000;
  }
  if (now <= last) now = last + 1;
  last = now;
  return now;
}

bool ReadWholeFile(const std::string& path, std::string* out) {
  std::FILE* f = std::fopen(path.c_str(), "rb");
  if (f == nullptr) return false;
  std::fseek(f, 0, SEEK_END);
  long size = std::ftell(f);
  if (size < 0) {
    std::fclose(f);
    return false;
  }
  std::fseek(f, 0, SEEK_SET);
  out->assign(static_cast<size_t>(size), '\0');
  bool ok = size == 0 ||
            std::fread(&(*out)[0], 1, static_cast<size_t>(size), f) ==
                static_cast<size_t>(size);
  std::fclose(f);
  return ok;
}

// Entrada de cache encontrada en disco (para LRU).
struct CacheEntryOnDisk {
  std::string cache_rel;  // p. ej. "streams/TTH/ttalk1.pcm"
  std::string pcm_path;
  std::string meta_path;
  uint64_t pcm_bytes = 0;
  int64_t last_used = 0;
};

void ScanCacheDir(const std::string& dir, const std::string& rel_prefix,
                  std::vector<CacheEntryOnDisk>* out) {
  DIR* d = ::opendir(dir.c_str());
  if (d == nullptr) return;
  while (dirent* e = ::readdir(d)) {
    std::string name = e->d_name;
    if (name == "." || name == "..") continue;
    std::string path = dir + "/" + name;
    std::string rel = rel_prefix.empty() ? name : rel_prefix + "/" + name;
    if (IsDir(path)) {
      ScanCacheDir(path, rel, out);
    } else if (EndsWith(name, ".pcm")) {
      uint64_t size = 0;
      if (!FileSize(path, &size)) continue;
      CacheEntryOnDisk entry;
      entry.cache_rel = rel;
      entry.pcm_path = path;
      entry.meta_path = path.substr(0, path.size() - 4) + ".meta";
      entry.pcm_bytes = size;
      AdpCacheMeta meta;
      if (ReadCacheMeta(entry.meta_path, &meta) && meta.last_used > 0) {
        entry.last_used = meta.last_used;
      } else {
        entry.last_used = FileMtime(path);
      }
      out->push_back(entry);
    }
  }
  ::closedir(d);
}

void ScanOrphansDir(const std::string& dir) {
  DIR* d = ::opendir(dir.c_str());
  if (d == nullptr) return;
  while (dirent* e = ::readdir(d)) {
    std::string name = e->d_name;
    if (name == "." || name == "..") continue;
    std::string path = dir + "/" + name;
    if (IsDir(path)) {
      ScanOrphansDir(path);
    } else if (EndsWith(name, ".tmp") || EndsWith(name, ".meta.tmp")) {
      std::remove(path.c_str());
    }
  }
  ::closedir(d);
}

void ScanAdpDir(const std::string& dir, const std::string& rel_prefix,
                std::map<std::string, std::string>* out) {
  DIR* d = ::opendir(dir.c_str());
  if (d == nullptr) return;
  while (dirent* e = ::readdir(d)) {
    std::string name = e->d_name;
    if (name == "." || name == "..") continue;
    std::string path = dir + "/" + name;
    std::string rel = rel_prefix.empty() ? name : rel_prefix + "/" + name;
    if (IsDir(path)) {
      ScanAdpDir(path, rel, out);
    } else if (EndsWith(name, ".adp")) {
      // Clave: dir relativo bajo streams/ + stem, en minusculas.
      std::string stem = name.substr(0, name.size() - 4);
      std::string dir_rel = DirOf(rel);
      std::string key =
          ToLowerAscii(dir_rel.empty() ? stem : dir_rel + "/" + stem);
      (*out)[key] = "streams/" + rel;
    }
  }
  ::closedir(d);
}

}  // namespace

std::string Sha1Hex(const uint8_t* data, size_t len) {
  Sha1Ctx ctx;
  if (len > 0) ctx.Update(data, len);
  return ctx.FinalHex();
}

std::string Sha1FileHex(const char* path) {
  if (path == nullptr) return "";
  std::FILE* f = std::fopen(path, "rb");
  if (f == nullptr) return "";
  Sha1Ctx ctx;
  uint8_t buf[65536];
  size_t n;
  while ((n = std::fread(buf, 1, sizeof(buf), f)) > 0) {
    ctx.Update(buf, n);
  }
  std::fclose(f);
  return ctx.FinalHex();
}

std::string AdpRelToCacheRel(const std::string& adp_rel) {
  std::string rel = adp_rel;
  const std::string kAudioPrefix = "audio/";
  if (rel.compare(0, kAudioPrefix.size(), kAudioPrefix) == 0) {
    rel = rel.substr(kAudioPrefix.size());
  }
  if (EndsWith(rel, ".adp")) {
    rel = rel.substr(0, rel.size() - 4) + ".pcm";
  }
  return rel;
}

std::string CachePcmPath(const std::string& cache_root,
                         const std::string& adp_rel) {
  std::string root = cache_root;
  while (!root.empty() && root.back() == '/') root.pop_back();
  return root + "/" + AdpRelToCacheRel(adp_rel);
}

std::string CacheMetaPath(const std::string& cache_root,
                          const std::string& adp_rel) {
  std::string pcm = CachePcmPath(cache_root, adp_rel);
  return pcm.substr(0, pcm.size() - 4) + ".meta";
}

std::string CacheTmpPath(const std::string& cache_root,
                         const std::string& adp_rel) {
  return CachePcmPath(cache_root, adp_rel) + ".tmp";
}

std::string DeriveCacheRoot(const std::string& wav_root) {
  std::string root = wav_root;
  while (!root.empty() && root.back() == '/') root.pop_back();
  if (root.empty()) return "";  // Sin wav_root no hay cache.
  const std::string kAudioSuffix = "/audio";
  if (EndsWith(root, kAudioSuffix)) {
    return root.substr(0, root.size() - kAudioSuffix.size()) +
           "/audio-cache/" + kAdpCacheVersion;
  }
  return root + "/audio-cache/" + kAdpCacheVersion;
}

bool WriteCacheMeta(const std::string& meta_path,
                    const AdpCacheMeta& meta) {
  return WriteFileAtomic(meta_path, MetaJson(meta));
}

bool ReadCacheMeta(const std::string& meta_path, AdpCacheMeta* out) {
  if (out == nullptr) return false;
  std::string json;
  if (!ReadWholeFile(meta_path, &json)) return false;
  AdpCacheMeta m;
  if (!MetaString(json, "decoder", &m.decoder)) return false;
  MetaString(json, "adp_rel", &m.adp_rel);
  MetaString(json, "adp_sha1", &m.adp_sha1);
  if (!MetaNumber(json, "adp_bytes", &m.adp_bytes)) return false;
  if (!MetaNumber(json, "pcm_frames", &m.pcm_frames)) return false;
  uint64_t rate = 0, channels = 0, pcm_bytes = 0, last_used = 0;
  if (!MetaNumber(json, "rate", &rate)) return false;
  if (!MetaNumber(json, "channels", &channels)) return false;
  if (!MetaNumber(json, "pcm_bytes", &pcm_bytes)) return false;
  MetaNumber(json, "last_used", &last_used);
  m.rate = static_cast<int>(rate);
  m.channels = static_cast<int>(channels);
  m.pcm_bytes = pcm_bytes;
  m.last_used = static_cast<int64_t>(last_used);
  *out = m;
  return true;
}

bool IsCacheValid(const std::string& cache_root,
                  const std::string& adp_rel,
                  const std::string& adp_path,
                  AdpCacheMeta* meta_out) {
  uint64_t adp_bytes = 0;
  if (!FileSize(adp_path, &adp_bytes)) return false;
  AdpCacheMeta meta;
  if (!ReadCacheMeta(CacheMetaPath(cache_root, adp_rel), &meta)) {
    return false;
  }
  if (meta.decoder != kAdpCacheDecoder) return false;
  if (meta.adp_bytes != adp_bytes) return false;
  // Coherencia interna: detecta truncados sin leer el PCM.
  if (adp_bytes % 32 != 0) return false;
  uint64_t expect_pcm = adp_bytes / 32 * 28 * 4;
  if (meta.pcm_bytes != expect_pcm) return false;
  if (meta.pcm_frames != adp_bytes / 32 * 28) return false;
  if (meta.rate != 32000 || meta.channels != 2) return false;
  uint64_t pcm_bytes = 0;
  if (!FileSize(CachePcmPath(cache_root, adp_rel), &pcm_bytes)) {
    return false;
  }
  if (pcm_bytes != expect_pcm) return false;
  if (meta_out != nullptr) *meta_out = meta;
  return true;
}

void TouchCache(const std::string& cache_root,
                const std::string& adp_rel) {
  std::string meta_path = CacheMetaPath(cache_root, adp_rel);
  AdpCacheMeta meta;
  if (!ReadCacheMeta(meta_path, &meta)) return;
  meta.last_used = NowMsMonotonic();
  WriteCacheMeta(meta_path, meta);  // Best effort.
}

void DeleteCacheEntry(const std::string& cache_root,
                      const std::string& adp_rel) {
  std::remove(CachePcmPath(cache_root, adp_rel).c_str());
  std::remove(CacheMetaPath(cache_root, adp_rel).c_str());
  std::remove(CacheTmpPath(cache_root, adp_rel).c_str());
}

void CleanupCacheOrphans(const std::string& cache_root) {
  ScanOrphansDir(cache_root);
}

uint64_t CacheTotalBytes(const std::string& cache_root) {
  std::vector<CacheEntryOnDisk> entries;
  ScanCacheDir(cache_root, "", &entries);
  uint64_t total = 0;
  for (const CacheEntryOnDisk& e : entries) total += e.pcm_bytes;
  return total;
}

size_t PruneCache(const std::string& cache_root, uint64_t cap_bytes,
                  const std::set<std::string>& keep_cache_rels) {
  std::vector<CacheEntryOnDisk> entries;
  ScanCacheDir(cache_root, "", &entries);
  uint64_t total = 0;
  for (const CacheEntryOnDisk& e : entries) total += e.pcm_bytes;
  if (total <= cap_bytes) return 0;
  std::sort(entries.begin(), entries.end(),
            [](const CacheEntryOnDisk& a, const CacheEntryOnDisk& b) {
              if (a.last_used != b.last_used) {
                return a.last_used < b.last_used;
              }
              return a.cache_rel < b.cache_rel;
            });
  size_t evicted = 0;
  for (const CacheEntryOnDisk& e : entries) {
    if (total <= cap_bytes) break;
    if (keep_cache_rels.count(e.cache_rel) != 0) continue;
    std::remove(e.pcm_path.c_str());
    std::remove(e.meta_path.c_str());
    total -= e.pcm_bytes;
    ++evicted;
  }
  return evicted;
}

CacheWriter::~CacheWriter() { Abort(); }

bool CacheWriter::Open(const std::string& cache_root,
                       const std::string& adp_rel, uint64_t adp_bytes,
                       uint64_t pcm_frames) {
  Abort();
  cache_root_ = cache_root;
  adp_rel_ = adp_rel;
  tmp_path_ = CacheTmpPath(cache_root, adp_rel);
  std::string dir = DirOf(tmp_path_);
  if (!MkdirP(dir)) return false;
  file_ = std::fopen(tmp_path_.c_str(), "wb");
  if (file_ == nullptr) return false;
  adp_bytes_ = adp_bytes;
  pcm_frames_ = pcm_frames;
  pcm_written_ = 0;
  failed_ = false;
  return true;
}

bool CacheWriter::Write(const int16_t* samples, size_t frames) {
  if (file_ == nullptr || failed_) return false;
  if (frames == 0) return true;
  size_t wrote = std::fwrite(samples, 4, frames, file_);
  if (wrote != frames) {
    failed_ = true;
    return false;
  }
  pcm_written_ += frames * 4;
  return true;
}

bool CacheWriter::Finalize(const std::string& adp_path,
                           uint64_t cap_bytes) {
  if (file_ == nullptr) return false;
  bool ok = !failed_;
  if (std::fclose(file_) != 0) ok = false;
  file_ = nullptr;
  std::string pcm_path = CachePcmPath(cache_root_, adp_rel_);
  std::string meta_path = CacheMetaPath(cache_root_, adp_rel_);
  if (!ok || pcm_written_ != pcm_frames_ * 4) {
    std::remove(tmp_path_.c_str());
    return false;
  }
  AdpCacheMeta meta;
  meta.decoder = kAdpCacheDecoder;
  meta.adp_rel = adp_rel_;
  meta.adp_bytes = adp_bytes_;
  meta.adp_sha1 = Sha1FileHex(adp_path.c_str());  // Best effort.
  meta.pcm_frames = pcm_frames_;
  meta.rate = 32000;
  meta.channels = 2;
  meta.pcm_bytes = pcm_written_;
  meta.last_used = NowMsMonotonic();
  if (!WriteCacheMeta(meta_path, meta)) {
    std::remove(tmp_path_.c_str());
    return false;
  }
  if (std::rename(tmp_path_.c_str(), pcm_path.c_str()) != 0) {
    std::remove(tmp_path_.c_str());
    std::remove(meta_path.c_str());
    return false;
  }
  // Podar por LRU tras escribir: la entrada recien escrita
  // es la mas reciente, asi que solo se desaloja si ni
  // siquiera ella cabe (entonces se va la mas vieja, no
  // esta, salvo que sea la unica).
  PruneCache(cache_root_, cap_bytes, std::set<std::string>());
  return IsCacheValid(cache_root_, adp_rel_,
                      adp_path.c_str());
}

void CacheWriter::Abort() {
  if (file_ != nullptr) {
    std::fclose(file_);
    file_ = nullptr;
  }
  if (!tmp_path_.empty()) {
    std::remove(tmp_path_.c_str());
    tmp_path_.clear();
  }
  failed_ = false;
}

bool AdpIndex::Build(const std::string& wav_root) {
  map_.clear();
  std::string streams = wav_root;
  while (!streams.empty() && streams.back() == '/') streams.pop_back();
  streams += "/streams";
  if (!IsDir(streams)) return false;
  ScanAdpDir(streams, "", &map_);
  return true;
}

std::string AdpIndex::Lookup(const std::string& wav_rel) const {
  // "streams/TTH/ttalk1.wav" -> dir "TTH", stem "ttalk1".
  const std::string kPrefix = "streams/";
  if (wav_rel.compare(0, kPrefix.size(), kPrefix) != 0) return "";
  std::string rest = wav_rel.substr(kPrefix.size());
  size_t slash = rest.rfind('/');
  std::string dir = slash == std::string::npos ? "" : rest.substr(0, slash);
  std::string file = slash == std::string::npos ? rest : rest.substr(slash + 1);
  if (!EndsWith(file, ".wav")) return "";
  std::string stem = file.substr(0, file.size() - 4);
  std::string key =
      ToLowerAscii(dir.empty() ? stem : dir + "/" + stem);
  auto it = map_.find(key);
  return it == map_.end() ? "" : it->second;
}

}  // namespace sfa
