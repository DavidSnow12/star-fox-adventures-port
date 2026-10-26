// Tarjeta virtual Memory Card, formato RAW real (ver card.h).
// Sin dependencias guest/Android: solo stdio para persistir.

#include "gamecube_runtime/card.h"

#include <cstdio>
#include <cstring>
#include <ctime>

namespace sfa {

namespace {

uint16_t Be16(const uint8_t* p) {
  return static_cast<uint16_t>((static_cast<uint16_t>(p[0]) << 8) |
                               static_cast<uint16_t>(p[1]));
}

uint32_t Be32(const uint8_t* p) {
  return (static_cast<uint32_t>(p[0]) << 24) |
         (static_cast<uint32_t>(p[1]) << 16) |
         (static_cast<uint32_t>(p[2]) << 8) | static_cast<uint32_t>(p[3]);
}

void PutBe16(uint8_t* p, uint16_t v) {
  p[0] = static_cast<uint8_t>(v >> 8);
  p[1] = static_cast<uint8_t>(v);
}

void PutBe32(uint8_t* p, uint32_t v) {
  p[0] = static_cast<uint8_t>(v >> 24);
  p[1] = static_cast<uint8_t>(v >> 16);
  p[2] = static_cast<uint8_t>(v >> 8);
  p[3] = static_cast<uint8_t>(v);
}

// Checksum SDK (__CARDCheckSum): suma de palabras u16 BE y suma
// de sus complementos, ambas con 0xFFFF normalizado a 0.
void CardCheckSum(const uint8_t* data, uint32_t length, uint16_t* sum,
                  uint16_t* inv_sum) {
  uint32_t s = 0;
  uint32_t inv = 0;
  for (uint32_t i = 0; i + 1 < length; i += 2) {
    uint16_t w = Be16(data + i);
    s += w;
    inv += static_cast<uint16_t>(~w);
  }
  uint16_t s16 = static_cast<uint16_t>(s);
  uint16_t inv16 = static_cast<uint16_t>(inv);
  if (s16 == 0xFFFFu) s16 = 0;
  if (inv16 == 0xFFFFu) inv16 = 0;
  *sum = s16;
  *inv_sum = inv16;
}

// Segundos desde 2000-01-01 (epoca GameCube) a partir del reloj
// host. Solo se usa para hora de formato y modtime: el juego no
// los compara con nada critico.
uint32_t GcEpochSeconds() {
  std::time_t now = std::time(nullptr);
  if (now < 946684800) return 0;
  return static_cast<uint32_t>(now - 946684800);
}

int BlocksForSize(uint32_t size) {
  if (size == 0) return 0;
  return static_cast<int>((size + VirtualCard::kBlockSize - 1) /
                          VirtualCard::kBlockSize);
}

}  // namespace

bool VirtualCard::EnsureLoaded() {
  if (loaded_) return !image_parse_failed_;
  loaded_ = true;
  image_parse_failed_ = false;
  if (path_.empty()) {
    FormatNew();
    return true;
  }
  std::FILE* f = std::fopen(path_.c_str(), "rb");
  if (f == nullptr) {
    FormatNew();
    return true;
  }
  std::vector<uint8_t> image(kImageSize);
  size_t got = std::fread(image.data(), 1, image.size(), f);
  std::fclose(f);
  if (got != image.size() || !ParseImage(image)) {
    image_parse_failed_ = true;
    FormatNew();
    return false;
  }
  return true;
}

void VirtualCard::FormatNew() {
  files_.clear();
  bam_.assign(kTotalBlocks, 0);
  for (int i = 0; i < kFirstDataBlock; ++i) bam_[i] = -1;  // sistema
  mounted_ = false;
  format_time_ = GcEpochSeconds();
  // Serie: 12 bytes en cabecera; GetSerialNo devuelve los 8
  // primeros como u64 BE. Se deriva de la hora de formato para
  // que cada tarjeta formateada tenga una serie distinta, y
  // queda persistida en la imagen (estable entre arranques).
  uint64_t t = static_cast<uint64_t>(format_time_);
  serial_no_ = 0x5346414300000000ULL | (t & 0xFFFFFFFFULL);
  dir_update_ = 1;
  bam_update_ = 1;
}

bool VirtualCard::ParseImage(const std::vector<uint8_t>& image) {
  // Cabecera: tamano en Mbits debe ser 4 (tarjeta de 59).
  if (Be16(image.data() + 0x22) != 4) return false;
  serial_no_ = 0;
  for (int i = 0; i < 8; ++i) {
    serial_no_ = (serial_no_ << 8) | image[i];
  }
  // La hora de formato es u64 BE @0x0C (OSTime); para modtime
  // solo se usan los 32 bits bajos (@0x10).
  format_time_ = Be32(image.data() + 0x10);
  const uint8_t* dir = image.data() + 0x2000;
  const uint8_t* bam_block = image.data() + 0x6000;
  dir_update_ = Be16(dir + 8186);
  bam_update_ = Be16(bam_block + 4);
  // BAM: mapa desde +10, 4091 entradas; solo importan las 64
  // primeras (una tarjeta de 59 tiene 64 bloques).
  bam_.assign(kTotalBlocks, 0);
  for (int i = 0; i < kTotalBlocks; ++i) {
    uint16_t v = Be16(bam_block + 10 + i * 2);
    bam_[i] = (v == 0xFFFFu) ? -1 : static_cast<int>(v);
  }
  files_.clear();
  for (int i = 0; i < 127; ++i) {
    const uint8_t* e = dir + i * 64;
    if (Be32(e) == 0xFFFFFFFFu) {
      // Hueco vacio: se conserva como placeholder para que los
      // indices de directorio (fileNo) no se desplacen.
      File dead;
      dead.alive = false;
      files_.push_back(dead);
      continue;
    }
    File file;
    file.stat.game_name[0] = static_cast<char>(e[0]);
    file.stat.game_name[1] = static_cast<char>(e[1]);
    file.stat.game_name[2] = static_cast<char>(e[2]);
    file.stat.game_name[3] = static_cast<char>(e[3]);
    file.stat.company[0] = static_cast<char>(e[4]);
    file.stat.company[1] = static_cast<char>(e[5]);
    char name_buf[33];
    std::memcpy(name_buf, e + 8, 32);
    name_buf[32] = 0;
    file.name = name_buf;
    file.time = Be32(e + 40);
    file.stat.time = file.time;
    file.stat.banner_format = e[7];
    file.stat.icon_addr = Be32(e + 44);
    file.stat.icon_format = Be16(e + 48);
    file.stat.icon_speed = Be16(e + 50);
    file.first_block = Be16(e + 54);
    file.block_count = Be16(e + 56);
    file.stat.comment_word = Be32(e + 60);
    // La longitud logica no vive en la entrada de directorio:
    // se reconstruye como bloques * 8192. El juego siempre
    // crea con tamano multiplo de bloque (SFA: 24576 =
    // 3 bloques), asi que no hay perdida en la recarga. Los
    // datos se leen siguiendo la cadena BAM.
    file.length =
        static_cast<uint32_t>(file.block_count) * kBlockSize;
    file.stat.length = file.length;
    file.data.assign(file.length, 0);
    int block = file.first_block;
    uint32_t written = 0;
    while (block >= kFirstDataBlock && block < kTotalBlocks &&
           written < file.length) {
      uint32_t chunk = kBlockSize;
      if (written + chunk > file.length) chunk = file.length - written;
      std::memcpy(file.data.data() + written,
                  image.data() + static_cast<size_t>(block) * kBlockSize,
                  chunk);
      written += chunk;
      int next = (block < static_cast<int>(bam_.size())) ? bam_[block] : -1;
      if (next < 0) break;
      block = next;
    }
    files_.push_back(file);
  }
  return true;
}

std::vector<uint8_t> VirtualCard::Serialize() const {
  std::vector<uint8_t> image(kImageSize, 0xFF);
  // Cabecera.
  uint8_t* header = image.data();
  for (int i = 0; i < 8; ++i) {
    header[i] = static_cast<uint8_t>(serial_no_ >> (56 - 8 * i));
  }
  // Serie completa de 12 B: 8 de GetSerialNo + 4 derivados.
  header[8] = static_cast<uint8_t>(serial_no_ >> 56);
  header[9] = static_cast<uint8_t>(serial_no_ >> 48);
  header[10] = static_cast<uint8_t>(serial_no_ >> 40);
  header[11] = static_cast<uint8_t>(serial_no_ >> 32);
  PutBe32(header + 0x0C, 0);  // OSTime alto (no usado por el HLE)
  PutBe32(header + 0x10, format_time_);
  PutBe16(header + 0x22, 4);  // 4 Mbit = tarjeta de 59 bloques
  PutBe16(header + 0x24, 0);  // codificacion ASCII
  PutBe16(header + 0x1FA, 1);
  uint16_t sum = 0;
  uint16_t inv = 0;
  CardCheckSum(header, 0x1FC, &sum, &inv);
  PutBe16(header + 0x1FC, sum);
  PutBe16(header + 0x1FE, inv);
  // Directorio (+ copia). Los huecos (borrados) quedan en 0xFF:
    // la imagen arranca llena de 0xFF y solo se escriben las
    // entradas vivas, en su mismo indice.
  for (int copy = 0; copy < 2; ++copy) {
    uint8_t* dir = image.data() + 0x2000 + copy * 0x2000;
    for (size_t i = 0; i < files_.size() && i < 127; ++i) {
      const File& file = files_[i];
      if (!file.alive) continue;
      uint8_t* e = dir + i * 64;
      std::memset(e, 0xFF, 64);
      e[0] = static_cast<uint8_t>(file.stat.game_name[0]);
      e[1] = static_cast<uint8_t>(file.stat.game_name[1]);
      e[2] = static_cast<uint8_t>(file.stat.game_name[2]);
      e[3] = static_cast<uint8_t>(file.stat.game_name[3]);
      e[4] = static_cast<uint8_t>(file.stat.company[0]);
      e[5] = static_cast<uint8_t>(file.stat.company[1]);
      e[6] = 0;  // reservado
      e[7] = file.stat.banner_format;  // formato de banner (byte 7 YAGCD)
      std::memset(e + 8, 0, 32);
      std::memcpy(e + 8, file.name.c_str(),
                  file.name.size() < 32 ? file.name.size() : 32);
      PutBe32(e + 40, file.time);
      PutBe32(e + 44, file.stat.icon_addr);
      PutBe16(e + 48, file.stat.icon_format);
      PutBe16(e + 50, file.stat.icon_speed);
      e[52] = 0;  // permisos (0: solo el HLE lee esta imagen)
      e[53] = 0;  // contador de copias
      PutBe16(e + 54, static_cast<uint16_t>(file.first_block));
      PutBe16(e + 56, static_cast<uint16_t>(file.block_count));
      PutBe16(e + 58, 0xFFFF);  // reservado
      PutBe32(e + 60, file.stat.comment_word);
    }
    PutBe16(dir + 8186, dir_update_);
    CardCheckSum(dir, 8188, &sum, &inv);
    PutBe16(dir + 8188, sum);
    PutBe16(dir + 8190, inv);
  }
  // BAM (+ copia): checksum @0, inverso @2, contador @4, libres
  // @6, ultimo asignado @8, mapa @10 (0 libre, siguiente, o
  // 0xFFFF ultimo). Checksum SDK sobre 8188 B desde +4.
  for (int copy = 0; copy < 2; ++copy) {
    uint8_t* bam_block = image.data() + 0x6000 + copy * 0x2000;
    std::memset(bam_block, 0, kBlockSize);
    PutBe16(bam_block + 4, bam_update_);
    PutBe16(bam_block + 6, static_cast<uint16_t>(FreeBlocks()));
    int last = -1;
    for (int i = kTotalBlocks - 1; i >= 0; --i) {
      if (bam_[i] != 0) {
        last = i;
        break;
      }
    }
    PutBe16(bam_block + 8,
             static_cast<uint16_t>(last < 0 ? 0xFFFF : last));
    for (int i = 0; i < kTotalBlocks; ++i) {
      uint16_t v = (bam_[i] < 0)
                       ? 0xFFFFu
                       : static_cast<uint16_t>(bam_[i]);
      PutBe16(bam_block + 10 + i * 2, v);
    }
    CardCheckSum(bam_block + 4, 8188, &sum, &inv);
    PutBe16(bam_block + 0, sum);
    PutBe16(bam_block + 2, inv);
  }
  // Datos: bloque N en el offset N*8192.
  for (const File& file : files_) {
    if (!file.alive) continue;
    int block = file.first_block;
    uint32_t written = 0;
    while (block >= kFirstDataBlock && block < kTotalBlocks &&
           written < file.length) {
      uint32_t chunk = kBlockSize;
      if (written + chunk > file.length) chunk = file.length - written;
      std::memcpy(image.data() + static_cast<size_t>(block) * kBlockSize,
                  file.data.data() + written, chunk);
      written += chunk;
      int next = bam_[block];
      if (next < 0) break;
      block = next;
    }
  }
  return image;
}

bool VirtualCard::Persist() {
  if (path_.empty()) return true;
  std::vector<uint8_t> image = Serialize();
  std::FILE* f = std::fopen(path_.c_str(), "wb");
  if (f == nullptr) return false;
  size_t written = std::fwrite(image.data(), 1, image.size(), f);
  std::fclose(f);
  return written == image.size();
}

int VirtualCard::FindFile(const std::string& name) const {
  for (size_t i = 0; i < files_.size(); ++i) {
    if (files_[i].alive && files_[i].name == name) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

int VirtualCard::FreeBlocks() const {
  int free = 0;
  for (int i = kFirstDataBlock; i < kTotalBlocks; ++i) {
    if (bam_[i] == 0) ++free;
  }
  return free;
}

bool VirtualCard::AllocBlocks(int count, int* first_block) {
  if (count <= 0 || FreeBlocks() < count) return false;
  int first = -1;
  int prev = -1;
  for (int i = kFirstDataBlock; i < kTotalBlocks && count > 0; ++i) {
    if (bam_[i] != 0) continue;
    if (first < 0) first = i;
    if (prev >= 0) bam_[prev] = i;
    prev = i;
    --count;
  }
  if (prev >= 0) bam_[prev] = -1;
  *first_block = first;
  return true;
}

int VirtualCard::Probe(int chan, uint32_t* mem_size,
                       uint32_t* sector_size) const {
  if (chan != 0) return kNoCard;
  if (mem_size != nullptr) *mem_size = kProbeMemSize;
  if (sector_size != nullptr) *sector_size = kProbeSectorSize;
  return kReady;
}

int VirtualCard::Init() { return kReady; }

int VirtualCard::Mount(int chan) {
  if (chan != 0) return kNoCard;
  EnsureLoaded();
  mounted_ = true;
  return kReady;
}

int VirtualCard::Unmount(int chan) {
  if (chan != 0) return kNoCard;
  mounted_ = false;
  return kReady;
}

int VirtualCard::Check(int chan) const {
  if (chan != 0) return kNoCard;
  if (!mounted_) return kNoCard;
  return kReady;
}

int VirtualCard::Format(int chan) {
  if (chan != 0) return kNoCard;
  FormatNew();
  mounted_ = true;
  Persist();
  return kReady;
}

int VirtualCard::Open(int chan, const std::string& name, int* file_no) {
  if (chan != 0) return kNoCard;
  if (!mounted_) return kNoCard;
  int idx = FindFile(name);
  if (idx < 0) return kNoFile;
  if (file_no != nullptr) *file_no = idx;
  return kReady;
}

int VirtualCard::Create(int chan, const std::string& name, uint32_t size,
                        int* file_no) {
  if (chan != 0) return kNoCard;
  if (!mounted_) return kNoCard;
  if (name.size() > kMaxFileName) return kNameTooLong;
  if (FindFile(name) >= 0) return kExist;
  int blocks = BlocksForSize(size);
  int first = -1;
  if (!AllocBlocks(blocks, &first)) return kInsSpace;
  // Reutilizar un hueco de borrado si lo hay (fileNo estable);
  // si no, anadir al final (maximo 127 entradas).
  int slot = -1;
  for (size_t i = 0; i < files_.size(); ++i) {
    if (!files_[i].alive) {
      slot = static_cast<int>(i);
      break;
    }
  }
  if (slot < 0) {
    if (files_.size() >= 127) {
      // Devolver los bloques antes de fallar.
      int block = first;
      while (block >= kFirstDataBlock && block < kTotalBlocks) {
        int next = bam_[block];
        bam_[block] = 0;
        if (next < 0) break;
        block = next;
      }
      return kLimit;
    }
    slot = static_cast<int>(files_.size());
    files_.push_back(File());
  }
  File& file = files_[slot];
  file.alive = true;
  file.name = name;
  file.length = size;  // longitud logica; capacidad = bloques
  file.data.assign(static_cast<size_t>(blocks) * kBlockSize, 0);
  file.time = GcEpochSeconds();
  file.stat = CardStatData();
  file.stat.file_name = name;
  file.stat.length = file.length;
  file.stat.time = file.time;
  file.first_block = first;
  file.block_count = blocks;
  ++dir_update_;
  ++bam_update_;
  Persist();
  if (file_no != nullptr) *file_no = slot;
  return kReady;
}

int VirtualCard::Close(int file_no) {
  if (file_no < 0 || file_no >= static_cast<int>(files_.size()) ||
      !files_[file_no].alive) {
    return kNoEnt;
  }
  return kReady;
}

int VirtualCard::Read(int file_no, uint32_t offset, uint32_t length,
                      uint8_t* out) const {
  if (file_no < 0 || file_no >= static_cast<int>(files_.size()) ||
      !files_[file_no].alive) {
    return kNoEnt;
  }
  const File& file = files_[file_no];
  if (offset > file.length || length > file.length - offset) {
    return kIoError;
  }
  if (out != nullptr && length > 0) {
    std::memcpy(out, file.data.data() + offset, length);
  }
  return kReady;
}

int VirtualCard::Write(int file_no, uint32_t offset, const uint8_t* data,
                       uint32_t length) {
  if (file_no < 0 || file_no >= static_cast<int>(files_.size()) ||
      !files_[file_no].alive) {
    return kNoEnt;
  }
  File& file = files_[file_no];
  if (offset > file.length || length > file.length - offset) {
    return kIoError;
  }
  if (data != nullptr && length > 0) {
    std::memcpy(file.data.data() + offset, data, length);
  }
  file.time = GcEpochSeconds();
  file.stat.time = file.time;
  Persist();
  return kReady;
}

int VirtualCard::Delete(int chan, const std::string& name) {
  if (chan != 0) return kNoCard;
  if (!mounted_) return kNoCard;
  int idx = FindFile(name);
  if (idx < 0) return kNoFile;
  File& file = files_[idx];
  int block = file.first_block;
  while (block >= kFirstDataBlock && block < kTotalBlocks) {
    int next = bam_[block];
    bam_[block] = 0;
    if (next < 0) break;
    block = next;
  }
  // No se compacta: la entrada queda como hueco (0xFF en la
  // imagen) y su fileNo puede reutilizarse en el proximo Create.
  file.alive = false;
  file.name.clear();
  file.data.clear();
  file.first_block = -1;
  file.block_count = 0;
  ++dir_update_;
  ++bam_update_;
  Persist();
  return kReady;
}

int VirtualCard::GetStatus(int chan, int file_no,
                           CardStatData* stat) const {
  if (chan != 0) return kNoCard;
  if (file_no < 0 || file_no >= static_cast<int>(files_.size()) ||
      !files_[file_no].alive) {
    return kNoEnt;
  }
  if (stat != nullptr) *stat = files_[file_no].stat;
  return kReady;
}

int VirtualCard::SetStatus(int chan, int file_no,
                           const CardStatData& stat) {
  if (chan != 0) return kNoCard;
  if (file_no < 0 || file_no >= static_cast<int>(files_.size()) ||
      !files_[file_no].alive) {
    return kNoEnt;
  }
  File& file = files_[file_no];
  file.stat.banner_format = stat.banner_format;
  file.stat.icon_addr = stat.icon_addr;
  file.stat.icon_format = stat.icon_format;
  file.stat.icon_speed = stat.icon_speed;
  file.stat.comment_word = stat.comment_word;
  file.stat.offset_banner = stat.offset_banner;
  file.stat.offset_banner_tlut = stat.offset_banner_tlut;
  for (int i = 0; i < 8; ++i) {
    file.stat.offset_icon[i] = stat.offset_icon[i];
  }
  file.stat.offset_icon_tlut = stat.offset_icon_tlut;
  file.stat.offset_data = stat.offset_data;
  ++dir_update_;
  Persist();
  return kReady;
}

int VirtualCard::GetSerialNo(int chan, uint64_t* serial) const {
  if (chan != 0) return kNoCard;
  if (serial != nullptr) *serial = serial_no_;
  return kReady;
}

size_t VirtualCard::FileCount() const {
  size_t n = 0;
  for (const File& f : files_) {
    if (f.alive) ++n;
  }
  return n;
}

bool VirtualCard::FileInfo(size_t index, std::string* name,
                           uint32_t* length) const {
  size_t n = 0;
  for (const File& f : files_) {
    if (!f.alive) continue;
    if (n == index) {
      if (name != nullptr) *name = f.name;
      if (length != nullptr) *length = f.length;
      return true;
    }
    ++n;
  }
  return false;
}

}  // namespace sfa
