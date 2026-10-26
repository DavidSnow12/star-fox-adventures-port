#pragma once

// Cache PCM de streams ADP (Tramo 5). Ubicacion, formato y
// politica decididos en la Fase 18 (ADP-CACHE-DESIGN.md):
//
//   <base>/sfa-data/audio-cache/v1/<rel>.pcm
//   <base>/sfa-data/audio-cache/v1/<rel>.meta
//
// donde <rel> replica la ruta de audio sin la parte
// "audio/" y con extension .pcm:
//   ADP  sfa-data/audio/streams/TTH/ttalk1.adp
//   ->   sfa-data/audio-cache/v1/streams/TTH/ttalk1.pcm
//
// Formato .pcm: s16le intercalado, 32.000 Hz estereo, sin
// cabecera WAV (exactamente el chunk data del WAV host):
//   frames = adp_bytes / 32 * 28; pcm_bytes = frames * 4
//   (ratio constante 3,50x). Se guarda a 32 kHz, NO a 48 kHz:
//   el resampleo se hace al reproducir, por bloques.
// .meta JSON: decoder "dtk-v1", adp_rel, adp_bytes,
// adp_sha1 (diagnostico, calculado al decodificar; NO es
// criterio de validez), pcm_frames, rate 32000, channels 2,
// pcm_bytes, last_used (milisegundos Unix, para LRU).
// last_used es ESTRICTAMENTE creciente por proceso (si dos
// escrituras caen en el mismo milisegundo, la segunda suma
// 1): sin esto, dos caches escritas en el mismo segundo
// empatarian y el desempate alfabetico podria desalojar
// la mas reciente en vez de la mas vieja.
//
// Validez (sin leer el PCM entero): meta con decoder
// "dtk-v1", adp_bytes == tamano actual del ADP, pcm_bytes
// == tamano real del .pcm y == adp_bytes/32*28*4. La
// verificacion completa por SHA-1 NO se hace en cada Play
// (leer 12 MB para hashear anularia el ahorro); el SHA-1
// se guarda al decodificar y se usa bajo demanda.
// Escritura atomica: PCM a <rel>.pcm.tmp, .meta solo tras
// cerrar el .pcm con exito, rename .tmp -> .pcm. Un .tmp
// huerfano nunca se reproduce y se borra en la siguiente
// inicializacion de la cache.
// Capacidad: techo LRU 2.048 MiB por defecto (cubre la
// cache completa, 1.823,50 MiB, con margen). El desalojo
// es LRU por last_used y NUNCA desaloja lo que suena
// (keep-set explicito en PruneCache). Fallar la cache
// nunca falla el sonido: si el disco esta lleno, se
// abandona la escritura y el sonido sigue desde memoria.
// La cache es derivada; el ADP del pack es la fuente.
//
// Sin dependencias nuevas: POSIX (mkdir/opendir) + SHA-1
// propio (sin libreria externa). Solo C++17 estandar.

#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace sfa {

// Techo LRU por defecto: 2.048 MiB.
constexpr uint64_t kAdpCacheCapBytes = 2147483648ULL;
// Version del directorio de cache y del decodificador.
constexpr const char* kAdpCacheVersion = "v1";
constexpr const char* kAdpCacheDecoder = "dtk-v1";

// SHA-1 hexadecimal en minusculas (40 caracteres) de un
// buffer. Implementacion propia estandar (FIPS 180-1).
std::string Sha1Hex(const uint8_t* data, size_t len);
// SHA-1 de un fichero, o "" si no se puede leer.
std::string Sha1FileHex(const char* path);

// --- Rutas (sin tocar el disco) ---

// "streams/TTH/ttalk1.adp" (o "audio/streams/...") ->
// "streams/TTH/ttalk1.pcm". Si no termina en .adp, se
// devuelve la entrada tal cual (el llamador decide).
std::string AdpRelToCacheRel(const std::string& adp_rel);
std::string CachePcmPath(const std::string& cache_root,
                         const std::string& adp_rel);
std::string CacheMetaPath(const std::string& cache_root,
                          const std::string& adp_rel);
std::string CacheTmpPath(const std::string& cache_root,
                         const std::string& adp_rel);
// Raiz de cache derivada de wav_root: si wav_root termina
// en "/audio", <base>/sfa-data/audio-cache/v1; si no (pack
// simulado host), wav_root + "/audio-cache/v1".
std::string DeriveCacheRoot(const std::string& wav_root);

// --- .meta ---

struct AdpCacheMeta {
  std::string decoder;
  std::string adp_rel;
  uint64_t adp_bytes = 0;
  std::string adp_sha1;
  uint64_t pcm_frames = 0;
  int rate = 0;
  int channels = 0;
  uint64_t pcm_bytes = 0;
  int64_t last_used = 0;
};

bool WriteCacheMeta(const std::string& meta_path,
                    const AdpCacheMeta& meta);
bool ReadCacheMeta(const std::string& meta_path, AdpCacheMeta* out);

// --- Validez y mantenimiento ---

// Cache valida segun las 3 reglas (decoder, tamano ADP,
// coherencia PCM). No requiere que el ADP siga existiendo:
// si falta, devuelve false (sin ADP no hay fuente que
// validar; la cache nunca suena sin su ADP).
bool IsCacheValid(const std::string& cache_root,
                  const std::string& adp_rel,
                  const std::string& adp_path,
                  AdpCacheMeta* meta_out = nullptr);
// Actualiza last_used del .meta al abrir el .pcm (best
// effort: si falla, la reproduccion sigue igual).
void TouchCache(const std::string& cache_root,
                const std::string& adp_rel);
// Borra .pcm+.meta de una entrada (best effort).
void DeleteCacheEntry(const std::string& cache_root,
                      const std::string& adp_rel);
// Borra recursivamente *.tmp y *.meta.tmp huerfanos.
void CleanupCacheOrphans(const std::string& cache_root);
// Tamano total de los .pcm bajo cache_root (0 si no existe).
uint64_t CacheTotalBytes(const std::string& cache_root);
// Desalojo LRU hasta quedar <= cap_bytes. Evicta por
// last_used ascendente (luego ruta, determinista) y NUNCA
// las entradas de keep_cache_rels (lo que suena).
// Devuelve el numero de entradas desalojadas.
size_t PruneCache(const std::string& cache_root, uint64_t cap_bytes,
                  const std::set<std::string>& keep_cache_rels);

// Escritor de cache en streaming: se alimenta con el PCM
// nativo (32 kHz estereo) que se va decodificando para
// reproducir, y al llegar a EOF promueve el .tmp a .pcm
// con su .meta. Si la reproduccion se detiene antes de
// EOF, el llamador debe llamar a Abort(): el .tmp parcial
// NO se promueve (limitacion v1 conocida: el siguiente
// Play vuelve a decodificar desde el inicio).
class CacheWriter {
 public:
  CacheWriter() = default;
  ~CacheWriter();
  CacheWriter(const CacheWriter&) = delete;
  CacheWriter& operator=(const CacheWriter&) = delete;

  // Abre <rel>.pcm.tmp para escritura (crea directorios).
  // false si no se puede crear: el llamador sigue sonando
  // sin cache (no es error de reproduccion).
  bool Open(const std::string& cache_root,
            const std::string& adp_rel, uint64_t adp_bytes,
            uint64_t pcm_frames);
  bool IsOpen() const { return file_ != nullptr; }
  // Escribe PCM nativo; false si el disco falla (a partir
  // de ahi se ignora el resto: Abort en el cierre).
  bool Write(const int16_t* samples, size_t frames);
  // Cierra, calcula el SHA-1 del ADP, escribe el .meta,
  // renombra .tmp -> .pcm y poda por LRU. true si la
  // cache quedo valida. Si algo falla, borra el .tmp.
  bool Finalize(const std::string& adp_path, uint64_t cap_bytes);
  void Abort();

 private:
  std::FILE* file_ = nullptr;
  std::string cache_root_;
  std::string adp_rel_;
  std::string tmp_path_;
  uint64_t adp_bytes_ = 0;
  uint64_t pcm_frames_ = 0;
  uint64_t pcm_written_ = 0;  // Bytes PCM escritos.
  bool failed_ = false;
};

// Indice ADP insensible a caso sobre audio/streams/:
// clave "<dir en minusculas>/<stem en minusculas>" ->
// ruta real "streams/<DIR>/<f>.adp". NO se deriva por
// simple sustitucion de extension y caso: el disco trae
// variantes (GB/bird vs GB/Bird.adp, KP/EWDie vs EWdie.adp,
// TTH/QueenOk vs QueenOK.adp) y la sustitucion ingenua
// reintroduciria ese error. El indice se construye sobre
// el contenido real del pack, una vez por wav_root.
class AdpIndex {
 public:
  // Escanea <wav_root>/streams/ recursivamente. true si
  // el directorio existe (aunque este vacio); false si no
  // se puede leer (el llamador usa sustitucion directa
  // como red de seguridad).
  bool Build(const std::string& wav_root);
  // wav_rel "streams/TTH/ttalk1.wav" -> "streams/TTH/ttalk1.adp"
  // real, o "" si no hay coincidencia.
  std::string Lookup(const std::string& wav_rel) const;
  size_t Size() const { return map_.size(); }
  void Clear() { map_.clear(); }

 private:
  std::map<std::string, std::string> map_;
};

}  // namespace sfa
