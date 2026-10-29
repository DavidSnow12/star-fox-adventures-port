#include "gamecube_runtime/hle.h"

#include <cstring>
#include <utility>
#include <vector>

#include <dirent.h>
#include <strings.h>

#include "cpu/cpu.h"
#include "log.h"

namespace sfa {

namespace {
// Nombres de la tabla HLE, en el mismo orden que el switch de
// HandleHostCall. Solo la ruta real (ver hle.h).
struct HleEntry {
  uint32_t address;
  const char* name;
};
constexpr HleEntry kHleTable[] = {
    {Hle::kOsInit, "OSInit"},
    {Hle::kOsPsInit, "__OSPSInit"},
    {Hle::kOsCacheInit, "__OSCacheInit"},
    {Hle::kInitUser, "__init_user"},
    {Hle::kDbInit, "DBInit"},
    {Hle::kDvdInit, "DVDInit"},
    {Hle::kDvdOpen, "DVDOpen"},
    {Hle::kDvdClose, "DVDClose"},
    {Hle::kDvdReadAsyncPrio, "DVDReadAsyncPrio"},
    {Hle::kDvdReadPrio, "DVDReadPrio"},
    {Hle::kDvdPrepareStreamAsync, "DVDPrepareStreamAsync"},
    {Hle::kDvdCallbackTrampoline, "DVDTrampoline"},
    {Hle::kViInit, "VIInit"},
    {Hle::kViWaitForRetrace, "VIWaitForRetrace"},
    {Hle::kViConfigure, "VIConfigure"},
    {Hle::kViFlush, "VIFlush"},
    {Hle::kViSetPreRetraceCallback, "VISetPreRetraceCallback"},
    {Hle::kViSetPostRetraceCallback, "VISetPostRetraceCallback"},
    {Hle::kViCallbackTrampoline, "VITrampoline"},
    {Hle::kPadInit, "PADInit"},
    {Hle::kPadRead, "PADRead"},
    {Hle::kPadReset, "PADReset"},
    {Hle::kPadRecalibrate, "PADRecalibrate"},
    {Hle::kPadControlMotor, "PADControlMotor"},
    {Hle::kGxInit, "GXInit"},
    {Hle::kLcEnable, "LCEnable"},
    {Hle::kLcLoadBlocks, "LCLoadBlocks"},
    {Hle::kLcStoreBlocks, "LCStoreBlocks"},
    {Hle::kLcStoreData, "LCStoreData"},
    {Hle::kLcQueueWait, "LCQueueWait"},
    {Hle::kDcInvalidateRange, "DCInvalidateRange"},
    {Hle::kDcFlushRange, "DCFlushRange"},
    {Hle::kDcStoreRange, "DCStoreRange"},
    {Hle::kDcFlushRangeNoSync, "DCFlushRangeNoSync"},
    {Hle::kDcStoreRangeNoSync, "DCStoreRangeNoSync"},
    {Hle::kDcZeroRange, "DCZeroRange"},
    {Hle::kOsGetArenaHi, "OSGetArenaHi"},
    {Hle::kOsGetArenaLo, "OSGetArenaLo"},
    {Hle::kOsInitAlloc, "OSInitAlloc"},
    {Hle::kOsAllocFromHeap, "OSAllocFromHeap"},
    {Hle::kOsFreeToHeap, "OSFreeToHeap"},
    {Hle::kOsInitAlarm, "OSInitAlarm"},
    {Hle::kOsSetAlarm, "OSSetAlarm"},
    {Hle::kOsCancelAlarm, "OSCancelAlarm"},
    {Hle::kOsInitThreadQueue, "OSInitThreadQueue"},
    {Hle::kOsDisableScheduler, "OSDisableScheduler"},
    {Hle::kOsEnableScheduler, "OSEnableScheduler"},
    {Hle::kOsCreateThread, "OSCreateThread"},
    {Hle::kOsResumeThread, "OSResumeThread"},
    {Hle::kOsSuspendThread, "OSSuspendThread"},
    {Hle::kThreadExitTrampoline, "ThreadExit"},
    {Hle::kOsInitContext, "OSInitContext"},
    {Hle::kOsInitMessageQueue, "OSInitMessageQueue"},
    {Hle::kGxInitFifoBase, "GXInitFifoBase"},
    {Hle::kGxInitFifoPtrs, "GXInitFifoPtrs"},
    {Hle::kGxInitFifoLimits, "GXInitFifoLimits"},
    {Hle::kGxSetCpuFifo, "GXSetCPUFifo"},
    {Hle::kGxSetGpFifo, "GXSetGPFifo"},
    {Hle::kGxLoadTexObj, "GXLoadTexObj"},
    {Hle::kOsSleepThread, "OSSleepThread"},
    {Hle::kPpcSync, "PPCSync"},
    {Hle::kOsReport, "OSReport"},
    {Hle::kCardInit, "CARDInit"},
    {Hle::kCardProbeEx, "CARDProbeEx"},
    {Hle::kCardMount, "CARDMount"},
    {Hle::kCardUnmount, "CARDUnmount"},
    {Hle::kCardCheck, "CARDCheck"},
    {Hle::kCardFormat, "CARDFormat"},
    {Hle::kCardOpen, "CARDOpen"},
    {Hle::kCardClose, "CARDClose"},
    {Hle::kCardCreate, "CARDCreate"},
    {Hle::kCardRead, "CARDRead"},
    {Hle::kCardWrite, "CARDWrite"},
    {Hle::kCardDelete, "CARDDelete"},
    {Hle::kCardGetStatus, "CARDGetStatus"},
    {Hle::kCardSetStatus, "CARDSetStatus"},
    {Hle::kCardGetSerialNo, "CARDGetSerialNo"},
    // Tramo 8: al final para no mover los indices de
    // log_count_ de las entradas anteriores.
    {Hle::kArqReadDeliveryTrampoline, "ARQReadTrampoline"},
    // Fase 7 (port web, nucleo compartido): tambien al final,
    // por el mismo motivo.
    {Hle::kAiCallbackTrampoline, "AITrampoline"},
    // Fase 8 (port web, nucleo compartido): trampolin de
    // entrega del callback de breakpoint GX.
    {Hle::kBpCallbackTrampoline, "BPTrampoline"},
};

const char* FindHleName(uint32_t address) {
  for (const HleEntry& e : kHleTable) {
    if (e.address == address) return e.name;
  }
  return nullptr;
}

// Escribe guest->host cuando el destino esta en RAM (incluido el
// alias sin cache 0xC0000000); fuera de RAM, byte a byte con
// mem_write* (que marca exception si no cabe). Devuelve false
// si el rango no cabe en RAM y tampoco es escribible por mem_*.
bool GuestRangeHostPtr(CpuState* cpu, uint32_t guest, uint32_t size,
                       uint8_t** out) {
  if (cpu == nullptr || cpu->ram == nullptr || out == nullptr) return false;
  uint32_t offset = 0;
  if (guest >= 0x80000000u && guest < 0x80000000u + cpu->ram_size &&
      size <= cpu->ram_size - (guest - 0x80000000u)) {
    offset = guest - 0x80000000u;
  } else if (guest >= 0xC0000000u &&
             guest < 0xC0000000u + cpu->ram_size &&
             size <= cpu->ram_size - (guest - 0xC0000000u)) {
    offset = guest - 0xC0000000u;
  } else {
    return false;
  }
  *out = cpu->ram + offset;
  return true;
}

// Copia DMA de la caché bloqueada, sincrona (ver hle.h): un lado
// es RAM (mem_addr) y el otro la ventana LC (lc_addr, en
// [0xE0000000, 0xE0004000)). to_lc = RAM -> LC (Load); false =
// LC -> RAM (Store). El lado RAM usa el puntero host directo
// cuando cabe en RAM/alias; si no, el bucle mem_* (que cubre
// cualquier region mapeada). Devuelve false si el lado LC esta
// fuera de la ventana: el llamador lo registra, no se copia
// parcial ni se recorta en silencio.
bool LcDmaCopy(CpuState* cpu, uint32_t mem_addr, uint32_t lc_addr,
               uint32_t bytes, bool to_lc) {
  if (cpu == nullptr) return false;
  if (lc_addr < GC_LC_BASE || bytes > GC_LC_SIZE ||
      lc_addr - GC_LC_BASE > GC_LC_SIZE - bytes) {
    return false;
  }
  uint8_t* lc = cpu->locked_cache + (lc_addr - GC_LC_BASE);
  uint8_t* host = nullptr;
  if (GuestRangeHostPtr(cpu, mem_addr, bytes, &host)) {
    if (to_lc) {
      std::memcpy(lc, host, bytes);
    } else {
      std::memcpy(host, lc, bytes);
    }
    return true;
  }
  for (uint32_t i = 0; i < bytes; ++i) {
    if (to_lc) {
      lc[i] = ::mem_read8(cpu, mem_addr + i);
    } else {
      ::mem_write8(cpu, mem_addr + i, lc[i]);
    }
    if (cpu->exception != 0) return false;
  }
  return true;
}

// Lectura guest de un u32 BE con control de excepcion (false si
// la direccion no es legible). Solo para structs CARD pequenos.
bool ReadGuestU32(CpuState* cpu, uint32_t guest, uint32_t* out) {
  if (cpu == nullptr || out == nullptr) return false;
  cpu->exception = 0;
  uint32_t v = ::mem_read32(cpu, guest);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  *out = v;
  return true;
}

void WriteGuestU32(CpuState* cpu, uint32_t guest, uint32_t value) {
  if (cpu == nullptr) return;
  cpu->exception = 0;
  ::mem_write32(cpu, guest, value);
  if (cpu->exception != 0) cpu->exception = 0;
}

void WriteGuestU16(CpuState* cpu, uint32_t guest, uint16_t value) {
  if (cpu == nullptr) return;
  cpu->exception = 0;
  ::mem_write16(cpu, guest, value);
  if (cpu->exception != 0) cpu->exception = 0;
}

void WriteGuestU8(CpuState* cpu, uint32_t guest, uint8_t value) {
  if (cpu == nullptr) return;
  cpu->exception = 0;
  ::mem_write8(cpu, guest, value);
  if (cpu->exception != 0) cpu->exception = 0;
}

// CARDFileInfo guest (SDK, verificado contra el uso del juego:
// solo +4 = fileNo se lee de vuelta, en CARDGetStatus/SetStatus;
// +0 chan, +8 offset, +12 length se escriben por plausibilidad).
void WriteCardFileInfo(CpuState* cpu, uint32_t fileinfo, int chan,
                       int file_no, uint32_t length) {
  WriteGuestU32(cpu, fileinfo + 0u, static_cast<uint32_t>(chan));
  WriteGuestU32(cpu, fileinfo + 4u, static_cast<uint32_t>(file_no));
  WriteGuestU32(cpu, fileinfo + 8u, 0u);
  WriteGuestU32(cpu, fileinfo + 12u, length);
}

// CARDStat guest, 108 B (layout SDK; el juego lee +46
// bannerFormat, +48 iconAddr, +52 iconFormat, +54 iconSpeed y
// +56 como palabra de comentario, y los reescribe en SetStatus).
void WriteCardStat(CpuState* cpu, uint32_t stat,
                   const CardStatData& data) {
  uint8_t name[32];
  std::memset(name, 0, sizeof(name));
  std::memcpy(name, data.file_name.c_str(),
              data.file_name.size() < 32 ? data.file_name.size() : 32);
  for (int i = 0; i < 32; ++i) WriteGuestU8(cpu, stat + i, name[i]);
  WriteGuestU32(cpu, stat + 32u, data.length);
  WriteGuestU32(cpu, stat + 36u, data.time);
  for (int i = 0; i < 4; ++i) {
    WriteGuestU8(cpu, stat + 40u + i,
                 static_cast<uint8_t>(data.game_name[i]));
  }
  WriteGuestU8(cpu, stat + 44u, static_cast<uint8_t>(data.company[0]));
  WriteGuestU8(cpu, stat + 45u, static_cast<uint8_t>(data.company[1]));
  WriteGuestU8(cpu, stat + 46u, data.banner_format);
  WriteGuestU8(cpu, stat + 47u, 0u);
  WriteGuestU32(cpu, stat + 48u, data.icon_addr);
  WriteGuestU16(cpu, stat + 52u, data.icon_format);
  WriteGuestU16(cpu, stat + 54u, data.icon_speed);
  WriteGuestU32(cpu, stat + 56u, data.comment_word);
  WriteGuestU32(cpu, stat + 60u, data.offset_banner);
  WriteGuestU32(cpu, stat + 64u, data.offset_banner_tlut);
  for (int i = 0; i < 8; ++i) {
    WriteGuestU32(cpu, stat + 68u + 4u * static_cast<uint32_t>(i),
                  data.offset_icon[i]);
  }
  WriteGuestU32(cpu, stat + 100u, data.offset_icon_tlut);
  WriteGuestU32(cpu, stat + 104u, data.offset_data);
}

bool ReadCardStat(CpuState* cpu, uint32_t stat, CardStatData* data) {
  if (cpu == nullptr || data == nullptr) return false;
  uint32_t v = 0;
  if (!ReadGuestU32(cpu, stat + 32u, &v)) return false;
  data->length = v;
  if (!ReadGuestU32(cpu, stat + 36u, &v)) return false;
  data->time = v;
  uint8_t b = 0;
  cpu->exception = 0;
  b = ::mem_read8(cpu, stat + 46u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  data->banner_format = b;
  if (!ReadGuestU32(cpu, stat + 48u, &v)) return false;
  data->icon_addr = v;
  cpu->exception = 0;
  uint32_t fmt = ::mem_read16(cpu, stat + 52u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  data->icon_format = static_cast<uint16_t>(fmt);
  cpu->exception = 0;
  uint32_t spd = ::mem_read16(cpu, stat + 54u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  data->icon_speed = static_cast<uint16_t>(spd);
  if (!ReadGuestU32(cpu, stat + 56u, &v)) return false;
  data->comment_word = v;
  if (!ReadGuestU32(cpu, stat + 60u, &v)) return false;
  data->offset_banner = v;
  if (!ReadGuestU32(cpu, stat + 64u, &v)) return false;
  data->offset_banner_tlut = v;
  for (int i = 0; i < 8; ++i) {
    if (!ReadGuestU32(cpu, stat + 68u + 4u * static_cast<uint32_t>(i),
                      &v)) {
      return false;
    }
    data->offset_icon[i] = v;
  }
  if (!ReadGuestU32(cpu, stat + 100u, &v)) return false;
  data->offset_icon_tlut = v;
  if (!ReadGuestU32(cpu, stat + 104u, &v)) return false;
  data->offset_data = v;
  return true;
}

}  // namespace

Hle::Hle() = default;

Hle::~Hle() {
  for (DvdEntry& e : dvd_) {
    if (e.file != nullptr) std::fclose(e.file);
  }
}

void Hle::SetDiscRoot(const char* root) {
  disc_root_ = root != nullptr ? root : "";
}

void Hle::SetFstPath(const char* path) {
  fst_path_ = path != nullptr ? path : "";
  fst_loaded_ = false;
  fst_load_attempted_ = false;
  fst_entries_.clear();
}

void Hle::SetCardPath(const char* path) {
  card_.SetPath(path != nullptr ? path : "");
}

void Hle::SetPadInject(bool enabled, uint16_t buttons, int8_t stick_x,
                       int8_t stick_y) {
  pad_inject_ = enabled;
  pad_inject_buttons_ = buttons;
  pad_inject_stick_x_ = stick_x;
  pad_inject_stick_y_ = stick_y;
  pad_state_.buttons = buttons;
  pad_state_.stick_x = stick_x;
  pad_state_.stick_y = stick_y;
  pad_state_.SyncAnalogFromButtons();
}

std::string Hle::NormalizeDvdName(const std::string& name) {
  // El juego pide '/audio/data/Music.bin' (con barra) y
  // 'GAMETEXT.bin' (plano); el FST guarda rutas relativas sin
  // barra inicial ('audio/data/Music.bin'). Normalizar es solo
  // quitar la barra inicial; no se inventan rutas.
  if (!name.empty() && name[0] == '/') return name.substr(1);
  return name;
}

void Hle::TryLoadFst() {
  if (fst_load_attempted_) return;
  fst_load_attempted_ = true;
  std::string candidates[3];
  int n = 0;
  if (!fst_path_.empty()) candidates[n++] = fst_path_;
  if (!disc_root_.empty()) {
    candidates[n++] = disc_root_ + "/../sys/fst.bin";
    candidates[n++] = disc_root_ + "/sys/fst.bin";
  }
  std::FILE* file = nullptr;
  std::string used;
  for (int i = 0; i < n && file == nullptr; ++i) {
    file = std::fopen(candidates[i].c_str(), "rb");
    if (file != nullptr) used = candidates[i];
  }
  if (file == nullptr) {
    SFA_LOGI("hle: FST no encontrado (sin +48 real; +52 seguira "
             "siendo el tamano host)");
    return;
  }
  std::fseek(file, 0, SEEK_END);
  long size = std::ftell(file);
  std::fseek(file, 0, SEEK_SET);
  if (size < 12) {
    std::fclose(file);
    return;
  }
  std::vector<uint8_t> data(static_cast<size_t>(size));
  if (std::fread(data.data(), 1, data.size(), file) != data.size()) {
    std::fclose(file);
    return;
  }
  std::fclose(file);
  auto be32 = [&data](size_t off) -> uint32_t {
    return (static_cast<uint32_t>(data[off]) << 24) |
           (static_cast<uint32_t>(data[off + 1]) << 16) |
           (static_cast<uint32_t>(data[off + 2]) << 8) |
           static_cast<uint32_t>(data[off + 3]);
  };
  uint32_t count = be32(8);
  if (count == 0 || 12u * count > data.size()) {
    SFA_LOGE("hle: FST '%s' con cabecera incoherente (entradas %u)",
             used.c_str(), count);
    return;
  }
  size_t strtab = 12u * count;
  auto entry_name = [&data, strtab](uint32_t name_off) -> std::string {
    std::string out;
    for (size_t i = strtab + name_off; i < data.size(); ++i) {
      if (data[i] == 0) break;
      out.push_back(static_cast<char>(data[i]));
    }
    return out;
  };
  // Recorrido FST: la entrada raiz (0) es directorio con
  // longitud = n. de entradas; cada directorio abre un rango
  // [i+1, longitud) con su prefijo. Los ficheros no guardan
  // padre: el prefijo vigente lo da el rango que los contiene.
  std::vector<std::pair<uint32_t, std::string>> stack;
  // (fin_de_rango, prefijo). Se procesa en orden de entrada.
  fst_entries_.clear();
  std::string prefix;
  uint32_t range_end = count;
  // Pila explicita para no depender de recursion: se recorren
  // las entradas y se mantiene el prefijo segun el rango.
  // Implementacion iterativa con pila de (fin, prefijo).
  struct Frame {
    uint32_t end;
    std::string prefix;
  };
  std::vector<Frame> frames;
  frames.push_back(Frame{count, ""});
  for (uint32_t i = 1; i < count; ++i) {
    while (!frames.empty() && i >= frames.back().end) {
      frames.pop_back();
    }
    if (frames.empty()) break;
    uint32_t raw = be32(12u * i);
    uint32_t type = raw >> 24;
    uint32_t name_off = raw & 0xFFFFFFu;
    uint32_t off = be32(12u * i + 4);
    uint32_t len = be32(12u * i + 8);
    std::string name = entry_name(name_off);
    if (type == 1) {
      frames.push_back(Frame{len, frames.back().prefix + name + "/"});
    } else if (type == 0) {
      fst_entries_.push_back(
          {frames.back().prefix + name, {off, len}});
    }
  }
  (void)prefix;
  (void)range_end;
  (void)stack;
  fst_loaded_ = true;
  SFA_LOGI("hle: FST cargado '%s': %zu ficheros", used.c_str(),
           fst_entries_.size());
}

bool Hle::LookupFst(const std::string& name, uint32_t* disc_offset,
                    uint32_t* length) const {
  if (!fst_loaded_ || disc_offset == nullptr || length == nullptr) {
    return false;
  }
  std::string norm = NormalizeDvdName(name);
  const std::pair<std::string, std::pair<uint32_t, uint32_t>>* base =
      nullptr;
  for (const auto& e : fst_entries_) {
    if (e.first == norm) {
      *disc_offset = e.second.first;
      *length = e.second.second;
      return true;
    }
    // Respaldo solo si el nombre base es unico en el FST (el
    // juego a veces pide un nombre plano que en disco vive en
    // un subdirectorio; si hay varios, no se adivina).
    size_t slash = e.first.rfind('/');
    std::string leaf =
        slash == std::string::npos ? e.first : e.first.substr(slash + 1);
    if (leaf == norm) {
      if (base != nullptr) return false;
      base = &e;
    }
  }
  if (base != nullptr) {
    *disc_offset = base->second.first;
    *length = base->second.second;
    return true;
  }
  return false;
}

bool Hle::WriteDvdFileInfo(CpuState* cpu, uint32_t fileinfo,
                           uint32_t disc_offset, uint32_t length) {
  if (cpu == nullptr) return false;
  cpu->exception = 0;
  ::mem_write32(cpu, fileinfo + 12u, 0u);
  ::mem_write32(cpu, fileinfo + 48u, disc_offset);
  ::mem_write32(cpu, fileinfo + 52u, length);
  ::mem_write32(cpu, fileinfo + 56u, 0u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    ++dvd_fileinfo_failures_;
    return false;
  }
  return true;
}

bool Hle::FormatOsReport(CpuState* cpu, std::string* out) {
  if (cpu == nullptr || out == nullptr) return false;
  std::string fmt;
  if (!ReadGuestString(cpu, cpu->gpr[3], &fmt)) return false;
  // Args varargs PPC: enteros en r4-r10, flotantes en f1-f8.
  // Mas alla de los registros, los enteros se leen del area de
  // parametros del llamador (sp+8 + 4*k), layout verificado en
  // run16 con la linea "mem" de 16 args (7 en registros, 9 en
  // pila: los 9 valores a sp+8..sp+40 son plausibles y el
  // siguiente, sp+44, ya es un puntero de frame ajeno). Los
  // flotantes en pila no se expanden (ninguna linea observada
  // los usa): se marcan, no se inventan.
  auto stack_int_arg = [&](int vararg_index, uint32_t* v) -> bool {
    if (vararg_index < 7) return false;
    uint32_t a = cpu->gpr[1] + 8u +
                 4u * static_cast<uint32_t>(vararg_index - 7);
    uint8_t* host = nullptr;
    if (!GuestRangeHostPtr(cpu, a, 4, &host)) return false;
    *v = (static_cast<uint32_t>(host[0]) << 24) |
         (static_cast<uint32_t>(host[1]) << 16) |
         (static_cast<uint32_t>(host[2]) << 8) |
         static_cast<uint32_t>(host[3]);
    return true;
  };
  size_t gpr = 4;
  size_t fpr = 1;
  int int_arg = 0;  // n. de args enteros consumidos (r4 = 0)
  bool stack_float = false;
  out->clear();
  char num[64];
  // Lee el siguiente arg entero (registro o pila).
  auto next_int = [&](uint32_t* v) -> bool {
    if (gpr <= 10) {
      *v = cpu->gpr[gpr++];
      ++int_arg;
      return true;
    }
    if (stack_int_arg(int_arg, v)) {
      ++int_arg;
      return true;
    }
    return false;
  };
  for (size_t i = 0; i < fmt.size(); ++i) {
    char c = fmt[i];
    if (c != '%') {
      out->push_back(c);
      continue;
    }
    if (i + 1 >= fmt.size()) {
      out->push_back('%');
      break;
    }
    size_t j = i + 1;
    if (fmt[j] == '%') {
      out->push_back('%');
      i = j;
      continue;
    }
    // Flags / ancho / precision (se ignoran en la salida, pero
    // '*' consume un entero, como en printf).
    while (j < fmt.size() &&
           (fmt[j] == '-' || fmt[j] == '+' || fmt[j] == ' ' ||
            fmt[j] == '#' || fmt[j] == '0')) {
      ++j;
    }
    while (j < fmt.size() && fmt[j] == '*') {
      uint32_t dummy = 0;
      (void)next_int(&dummy);
      ++j;
    }
    while (j < fmt.size() && fmt[j] >= '0' && fmt[j] <= '9') ++j;
    if (j < fmt.size() && fmt[j] == '.') {
      ++j;
      if (j < fmt.size() && fmt[j] == '*') {
        uint32_t dummy = 0;
        (void)next_int(&dummy);
        ++j;
      }
      while (j < fmt.size() && fmt[j] >= '0' && fmt[j] <= '9') ++j;
    }
    while (j < fmt.size() &&
           (fmt[j] == 'h' || fmt[j] == 'l' || fmt[j] == 'L' ||
            fmt[j] == 'j' || fmt[j] == 'z' || fmt[j] == 't')) {
      ++j;
    }
    if (j >= fmt.size()) {
      out->append("[fmt truncado]");
      break;
    }
    char conv = fmt[j];
    i = j;
    uint32_t v = 0;
    switch (conv) {
      case 'd':
      case 'i':
        if (next_int(&v)) {
          std::snprintf(num, sizeof(num), "%d",
                        static_cast<int32_t>(v));
          out->append(num);
        } else {
          out->append("[pila?]");
        }
        break;
      case 'u':
        if (next_int(&v)) {
          std::snprintf(num, sizeof(num), "%u", v);
          out->append(num);
        } else {
          out->append("[pila?]");
        }
        break;
      case 'x':
      case 'X':
        if (next_int(&v)) {
          std::snprintf(num, sizeof(num),
                        conv == 'x' ? "%x" : "%X", v);
          out->append(num);
        } else {
          out->append("[pila?]");
        }
        break;
      case 'o':
        if (next_int(&v)) {
          std::snprintf(num, sizeof(num), "%o", v);
          out->append(num);
        } else {
          out->append("[pila?]");
        }
        break;
      case 'c':
        if (next_int(&v)) {
          out->push_back(static_cast<char>(v & 0xFF));
        } else {
          out->append("[pila?]");
        }
        break;
      case 's': {
        if (next_int(&v)) {
          std::string s;
          if (ReadGuestString(cpu, v, &s)) {
            out->append(s);
          } else {
            std::snprintf(num, sizeof(num), "(str? 0x%08X)", v);
            out->append(num);
          }
        } else {
          out->append("[pila?]");
        }
        break;
      }
      case 'p':
        if (next_int(&v)) {
          std::snprintf(num, sizeof(num), "0x%08X", v);
          out->append(num);
        } else {
          out->append("[pila?]");
        }
        break;
      case 'f':
      case 'F':
      case 'e':
      case 'E':
      case 'g':
      case 'G':
        if (fpr > 8) {
          stack_float = true;
          out->append("[pila-f]");
        } else {
          std::snprintf(num, sizeof(num), "%g", cpu->fpr[fpr++]);
          out->append(num);
        }
        break;
      case 'n': {
        // %n escribe: aqui no se escribe nada (no hay efecto
        // observable en retail) y se consume el puntero.
        uint32_t dummy = 0;
        (void)next_int(&dummy);
        break;
      }
      default:
        out->push_back('%');
        out->push_back(conv);
        out->append("[?]");
        {
          uint32_t dummy = 0;
          (void)next_int(&dummy);
        }
        break;
    }
  }
  if (stack_float) out->append(" [float en pila sin expandir]");
  return true;
}

void Hle::Install(CpuState* cpu) {
  if (cpu == nullptr) return;
  cpu->host_call = &sfa_hle_host_call;
  cpu->instruction_fallback = &sfa_hle_instruction_fallback;
  // Puente C->C++ sin global: los callbacks recuperan la
  // instancia desde cpu->external_user_data (el chassis es
  // monohilo, pero asi cada CPUState lleva su propio HLE y no
  // hay un singleton que pueda quedar colgando entre tests).
  cpu->external_user_data = this;
}

void Hle::LogCall(CpuState* cpu, const char* name, uint32_t address) {
  HleCall call;
  call.name = name;
  call.address = address;
  call.return_address = cpu != nullptr ? cpu->lr : 0;
  call.r3 = cpu != nullptr ? cpu->gpr[3] : 0;
  call.r4 = cpu != nullptr ? cpu->gpr[4] : 0;
  call.r5 = cpu != nullptr ? cpu->gpr[5] : 0;
  call.r6 = cpu != nullptr ? cpu->gpr[6] : 0;
  call.r7 = cpu != nullptr ? cpu->gpr[7] : 0;
  if (calls_.size() < 1000000) calls_.push_back(call);
  // Log en texto solo las 20 primeras por nombre. El indice es
  // la posicion en kHleTable (mismo puntero de literal); 127 es
  // el cubo de nombres fuera de tabla (log_count_ tiene 128).
  unsigned idx = 127;
  for (unsigned i = 0; i < sizeof(kHleTable) / sizeof(kHleTable[0]); ++i) {
    if (kHleTable[i].name == name) {
      idx = i;
      break;
    }
  }
  uint64_t n = ++log_count_[idx];
  if (n <= 20) {
    SFA_LOGI("hle: %s @0x%08X <- ret 0x%08X (r3=0x%08X r4=0x%08X "
             "r5=0x%08X r6=0x%08X)",
             name, address, call.return_address, call.r3, call.r4,
             call.r5, call.r6);
  }
}

bool Hle::Return(CpuState* cpu, uint32_t value) {
  cpu->gpr[3] = value;
  cpu->pc = cpu->lr;
  return true;
}

uint64_t Hle::CallCountFor(const char* name) const {
  uint64_t n = 0;
  for (const HleCall& c : calls_) {
    if (c.name != nullptr && name != nullptr &&
        std::strcmp(c.name, name) == 0) {
      ++n;
    }
  }
  return n;
}

bool Hle::ReadGuestString(CpuState* cpu, uint32_t guest,
                          std::string* out) {
  if (cpu == nullptr || out == nullptr) return false;
  out->clear();
  for (int i = 0; i < 1024; ++i) {
    uint8_t ch = ::mem_read8(cpu, guest + static_cast<uint32_t>(i));
    if (cpu->exception != 0) return false;
    if (ch == 0) return true;
    out->push_back(static_cast<char>(ch));
  }
  return false;
}

bool Hle::WriteGuestBytes(CpuState* cpu, uint32_t dest,
                          const uint8_t* data, uint32_t size) {
  if (cpu == nullptr || data == nullptr) return false;
  uint8_t* host = nullptr;
  if (GuestRangeHostPtr(cpu, dest, size, &host)) {
    std::memcpy(host, data, size);
    return true;
  }
  for (uint32_t i = 0; i < size; ++i) {
    ::mem_write8(cpu, dest + i, data[i]);
    if (cpu->exception != 0) return false;
  }
  return true;
}

Hle::DvdEntry* Hle::FindDvd(uint32_t fileinfo_guest) {
  for (DvdEntry& e : dvd_) {
    if (e.fileinfo == fileinfo_guest) return &e;
  }
  return nullptr;
}

int Hle::DvdOpen(CpuState* cpu, uint32_t filename_guest,
                 uint32_t fileinfo_guest) {
  std::string name;
  if (!ReadGuestString(cpu, filename_guest, &name)) {
    SFA_LOGE("hle: DVDOpen: nombre guest 0x%08X ilegible", filename_guest);
    return 0;
  }
  if (disc_root_.empty()) {
    SFA_LOGE("hle: DVDOpen '%s': sin raiz de disco (SetDiscRoot)",
             name.c_str());
    return 0;
  }
  // Candidatos: raiz/nombre, y raiz+nombre si nombre ya lleva '/'.
  std::string candidates[2];
  candidates[0] = disc_root_ + "/" + name;
  candidates[1] = disc_root_ + name;
  std::FILE* file = nullptr;
  std::string used;
  for (int i = 0; i < 2 && file == nullptr; ++i) {
    // Evitar doble '//' solo cosmetico: fopen lo acepta igual.
    file = std::fopen(candidates[i].c_str(), "rb");
    if (file != nullptr) used = candidates[i];
  }
  if (file == nullptr &&
      name.find('/') == std::string::npos) {
    // Fallback sin distincion de mayusculas (Fase 5): el arbol
    // extraido del disco trae PREANIM.BIN/PREANIM.TAB en
    // mayusculas y el juego pide 'PREANIM.bin'/'PREANIM.tab';
    // en el host el FS distingue mayusculas y el fopen exacto
    // falla, aunque el fichero ESTA en el arbol del disco del
    // usuario. Se escanea el directorio raiz y se compara sin
    // distinguir mayusculas; solo para nombres planos (sin '/').
    DIR* dir = ::opendir(disc_root_.c_str());
    if (dir != nullptr) {
      while (file == nullptr) {
        struct dirent* ent = ::readdir(dir);
        if (ent == nullptr) break;
        if (::strcasecmp(ent->d_name, name.c_str()) == 0) {
          std::string path = disc_root_ + "/" + ent->d_name;
          file = std::fopen(path.c_str(), "rb");
          if (file != nullptr) {
            used = path;
            SFA_LOGI("hle: DVDOpen '%s': resuelto sin distinguir "
                     "mayusculas como '%s'",
                     name.c_str(), ent->d_name);
          }
        }
      }
      ::closedir(dir);
    }
  }
  if (file == nullptr &&
      name.find('/') != std::string::npos) {
    // Fallback sin distincion de mayusculas POR COMPONENTES
    // (Tramo 18, verificado en harness): el fallback de Fase 5
    // solo cubre nombres planos (sin '/'); el juego pide en
    // minusculas 'gamefront/shipbattle/warlock' x
    // 'animcurv.bin/.tab, voxmap.bin/.tab' y en disco existen
    // como 'ANIMCURV.bin/.tab, VOXMAP.bin/.tab' (tronco en
    // mayusculas, extension en minusculas: un simple "pasar
    // el nombre a mayusculas" daria ANIMCURV.BIN, que TAMPOCO
    // existe). Se resuelve cada componente por separado con
    // strcasecmp, de modo que cubre variantes de caso tanto
    // del directorio como del fichero, en cualquier
    // subdirectorio, no solo en los tres citados. Solo se
    // aplica cuando la apertura exacta ya fallo; no cambia
    // ninguna ruta que antes resolvia.
    std::string cur = disc_root_;
    bool ok = true;
    size_t pos = 0;
    while (ok) {
      size_t slash = name.find('/', pos);
      std::string comp = (slash == std::string::npos)
                             ? name.substr(pos)
                             : name.substr(pos, slash - pos);
      DIR* dir = ::opendir(cur.c_str());
      if (dir == nullptr) { ok = false; break; }
      bool found = false;
      while (!found) {
        struct dirent* ent = ::readdir(dir);
        if (ent == nullptr) break;
        if (::strcasecmp(ent->d_name, comp.c_str()) == 0) {
          cur = cur + "/" + ent->d_name;
          found = true;
        }
      }
      ::closedir(dir);
      if (!found) { ok = false; break; }
      if (slash == std::string::npos) break;
      pos = slash + 1;
    }
    if (ok) {
      file = std::fopen(cur.c_str(), "rb");
      if (file != nullptr) {
        used = cur;
        SFA_LOGI("hle: DVDOpen '%s': resuelto sin distinguir "
                 "mayusculas por componentes como '%s'",
                 name.c_str(), cur.c_str());
      }
    }
  }
  if (file == nullptr) {
    SFA_LOGE("hle: DVDOpen '%s': no encontrado bajo '%s'", name.c_str(),
             disc_root_.c_str());
    return 0;
  }
  std::fseek(file, 0, SEEK_END);
  long size = std::ftell(file);
  std::fseek(file, 0, SEEK_SET);
  DvdEntry* old = FindDvd(fileinfo_guest);
  if (old != nullptr) {
    if (old->file != nullptr) std::fclose(old->file);
    old->file = file;
    old->size = size;
    old->host_path = used;
  } else {
    DvdEntry e;
    e.fileinfo = fileinfo_guest;
    e.file = file;
    e.size = size;
    e.host_path = used;
    dvd_.push_back(e);
  }
  // Fase 6a: DVDFileInfo real (ver hle.h). +52 es el tamano
  // host (== longitud FST cuando hay FST); +48 el offset de
  // disco FST o 0 sin FST. Si la escritura guest falla, la
  // apertura se da por fallida: el juego lee +52 para
  // reservar, y un struct a medias es peor que un 0 (el
  // llamador reintentara o registrara el fallo, no leera 0 B
  // en silencio como en run20).
  TryLoadFst();
  uint32_t disc_offset = 0;
  uint32_t fst_length = 0;
  bool fst_hit = LookupFst(name, &disc_offset, &fst_length);
  if (fst_hit && fst_length != static_cast<uint32_t>(size)) {
    SFA_LOGE("hle: DVDOpen '%s': FST dice %u B pero el fichero "
             "host mide %ld B (se usa el host)",
             name.c_str(), fst_length, size);
  }
  if (!WriteDvdFileInfo(cpu, fileinfo_guest, disc_offset,
                        static_cast<uint32_t>(size))) {
    SFA_LOGE("hle: DVDOpen '%s': fileInfo guest 0x%08X no "
             "escribible (apertura fallida)",
             name.c_str(), fileinfo_guest);
    DvdClose(cpu, fileinfo_guest);
    return 0;
  }
  SFA_LOGI("hle: DVDOpen '%s' -> '%s' (%ld B, fileInfo guest 0x%08X, "
           "FST %s, disc_off 0x%08X)",
           name.c_str(), used.c_str(), size, fileinfo_guest,
           fst_hit ? "si" : "no", disc_offset);
  return 1;
}

int Hle::DvdRead(CpuState* cpu, uint32_t fileinfo_guest,
                 uint32_t dest_guest, uint32_t length, uint32_t offset) {
  DvdEntry* e = FindDvd(fileinfo_guest);
  if (e == nullptr || e->file == nullptr) {
    SFA_LOGE("hle: DVDRead: fileInfo guest 0x%08X sin entrada abierta",
             fileinfo_guest);
    return -1;
  }
  if (static_cast<long>(offset) >= e->size) return 0;
  uint32_t want = length;
  if (static_cast<long>(offset) + static_cast<long>(want) > e->size) {
    want = static_cast<uint32_t>(e->size - static_cast<long>(offset));
  }
  std::fseek(e->file, static_cast<long>(offset), SEEK_SET);
  std::vector<uint8_t> buf(want);
  size_t got = want > 0 ? std::fread(buf.data(), 1, want, e->file) : 0;
  if (got > 0 && !WriteGuestBytes(cpu, dest_guest, buf.data(),
                                  static_cast<uint32_t>(got))) {
    SFA_LOGE("hle: DVDRead: destino guest 0x%08X no escribible",
             dest_guest);
    return -1;
  }
  return static_cast<int>(got);
}

bool Hle::DvdClose(CpuState* cpu, uint32_t fileinfo_guest) {
  (void)cpu;
  for (auto it = dvd_.begin(); it != dvd_.end(); ++it) {
    if (it->fileinfo == fileinfo_guest) {
      if (it->file != nullptr) std::fclose(it->file);
      dvd_.erase(it);
      return true;
    }
  }
  return false;
}

void Hle::DrainArqCompletions(CpuState* cpu, uint32_t count_addr,
                              const char* where) {
  if (cpu == nullptr) return;
  uint32_t count = ::mem_read8(cpu, count_addr);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return;
  }
  uint32_t applied =
      pending_arq_completions_ < count ? pending_arq_completions_ : count;
  ::mem_write8(cpu, count_addr, static_cast<uint8_t>(count - applied));
  pending_arq_completions_ -= applied;
  SFA_LOGI("hle: ARQ drenado en %s (contador 0x%08X: %u -> %u, "
           "pendientes restantes %u)",
           where, count_addr, count, count - applied,
           pending_arq_completions_);
}

bool Hle::DeliverViCallbacks(CpuState* cpu) {
  if (cpu == nullptr || vi_chain_active_) return false;
  uint32_t r13 = cpu->gpr[13];
  uint32_t pre = ::mem_read32(cpu, r13 - 21016u);
  uint32_t post = ::mem_read32(cpu, r13 - 21012u);
  if (cpu->exception != 0) return false;
  if (pre == 0 && post == 0) return false;
  ++vi_chains_;
  if (pre != 0) {
    ++vi_pre_delivered_;
    vi_chain_active_ = true;
    vi_chain_post_ = post;
    vi_chain_ret_ = cpu->lr;
    cpu->gpr[3] = static_cast<uint32_t>(retrace_count_);
    cpu->pc = pre;
    cpu->lr = kViCallbackTrampoline;
  } else {
    ++vi_post_delivered_;
    cpu->gpr[3] = static_cast<uint32_t>(retrace_count_);
    cpu->pc = post;
  }
  return true;
}

// ------------------------------------------------------------------
// IRQ AI (Fase 7 del port web, nucleo compartido; diseno y
// evidencia en INFORME-WEB-FASE6.md §6 y §9).
//
// El audio de la pelicula (AttractMovie) usa la via AI DMA
// cruda del SDK: AttractMovieAudio_Init registra
// AttractMovieAudio_DmaCallback (0x80118528) en [r13-20908]
// con AIRegisterDMACallback, y SOLO ese callback ejecuta la
// mezcla (0x80118184) que devuelve los buferes decodificados
// a la cola audfree. Sin modelo de interrupcion AI el
// callback nunca corria: el hilo de audio se bloquea en el
// 4.o bufer, el de video se queda sin readed2 tras
// exactamente 3 frames y el watchdog de TitleMenu_run
// (contador [r13-23280] > 10) libera y reintenta — el bucle
// abre/lee 160 B/cierra sobre starfox.thp.
//
// Entrega (identica a la validada en el experimento c8 de la
// Fase 6): como la de VI, con pc = callback y lr = trampolin
// propio 0x80003010, rafagas de hasta 6 entregas por punto
// (el DMA real consume 640 B = 160 muestras por disparo), y
// SOLO en los puntos seguros de VI y siempre DESPUES de la
// cadena VI completa (HandleHostCall: VIWaitForRetrace,
// segunda fase del trampolin VI y OSSleepThread del
// principal). Invariante de la Fase 6 (c4-c6): AI nunca se
// antepone a VI, o PlayControl muere de hambre.
//
// Puertas (las medidas en vivo en la Fase 6): el registrado
// ha de ser exactamente el callback de la pelicula (el del
// motor principal NO se entrega: la musica va por el puente
// MusyX y no se toca) y, si el estado de AttractMovieAudio
// [r13-23324] no es 0 (el callback encadena primero al
// registrante previo), ese previo [r13-23328] ha de ser no
// nulo (en carrera: estado 2, previo 0x80284FE0).
//
// Replanificacion diferida (capa 2 de la causa raiz): la
// mezcla despierta al hilo de audio con OSSendMessage, pero
// en el planificador cooperativo ese despertar no le da el
// turno dentro del ciclo (las cadenas terminan en MainReady
// y el hilo de audio, creado el ultimo, pierde la carrera).
// Al abrir la rafaga se fotografian los trabajadores
// bloqueados en una cola vacia/llena (su contexto guardado
// apunta al retorno de sueno de Receive/Send y la cola vive
// en r31/r28, como en el principal); al cerrarla, si la
// mezcla dejo alguna de esas colas con su espera satisfecha,
// ese hilo queda anotado como despertado por IRQ y
// SwitchOnSleep le da el paso primero en el siguiente punto
// de cambio natural. Nunca se cambia de hilo desde el
// trampolin (c11: el principal perdia el mensaje "ready" a
// mitad de recepcion) y ninguna entrega nace de SwitchToMain
// (c13: reignicion en cadena sin progreso del principal).

bool Hle::DeliverAiCallbacks(CpuState* cpu) {
  return DeliverAiCallbacksRet(cpu, cpu != nullptr ? cpu->lr : 0);
}

bool Hle::DeliverAiCallbacksRet(CpuState* cpu, uint32_t ret) {
  if (cpu == nullptr || ai_chain_active_) return false;
  uint32_t r13 = cpu->gpr[13];
  uint32_t cb = ::mem_read32(cpu, r13 - 20908u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  if (cb != kAttractMovieDmaCallback) return false;
  uint32_t state = ::mem_read32(cpu, r13 - 23324u);
  uint32_t prev = ::mem_read32(cpu, r13 - 23328u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  // Estado 0: rama autocontenida del callback. Otro estado:
  // encadena al registrante previo; solo es seguro si ese
  // puntero es una funcion real (medido: 0x80284FE0).
  if (state != 0 && prev == 0) return false;
  SnapshotAiWaiters(cpu);
  ai_chain_active_ = true;
  ai_chain_ret_ = ret;
  ai_chain_count_ = 0;
  ++ai_bursts_;
  ++ai_delivered_;
  if (ai_delivered_ <= 12 || ai_delivered_ % 500 == 0) {
    SFA_LOGI("hle: AI DMA callback entregado (#%llu, retorno "
             "0x%08X, estado %u, previo 0x%08X)",
             static_cast<unsigned long long>(ai_delivered_), ret,
             state, prev);
  }
  cpu->pc = cb;
  cpu->lr = kAiCallbackTrampoline;
  return true;
}

bool Hle::HandleAiTrampoline(CpuState* cpu) {
  if (cpu == nullptr) return false;
  if (!ai_chain_active_) {
    // No deberia ocurrir (el PC sintetico solo lo pone este
    // HLE como lr de la entrega); si el huesped aterriza aqui
    // sin cadena, se vuelve por lr sin tocar nada mas.
    SFA_LOGE("hle: trampolin AI sin cadena activa (pc "
             "0x%08X, lr 0x%08X): retorno sin efecto",
             cpu->pc, cpu->lr);
    return Return(cpu, 0);
  }
  uint32_t r13 = cpu->gpr[13];
  uint32_t cb = ::mem_read32(cpu, r13 - 20908u);
  uint32_t state = ::mem_read32(cpu, r13 - 23324u);
  uint32_t prev = ::mem_read32(cpu, r13 - 23328u);
  if (cpu->exception != 0) cpu->exception = 0;
  bool gate = (state == 0) || (prev != 0);
  // Rafaga: mientras el callback siga registrado, las
  // puertas aguanten y no se llegue a 6 entregas por punto,
  // se vuelve a entregar (el blr del callback aterriza otra
  // vez en este trampolin).
  if (cb == kAttractMovieDmaCallback && gate &&
      ai_chain_count_ + 1 < 6) {
    ++ai_chain_count_;
    ++ai_delivered_;
    cpu->pc = cb;
    cpu->lr = kAiCallbackTrampoline;
    return true;
  }
  uint32_t ret = ai_chain_ret_;
  ai_chain_active_ = false;
  ai_chain_ret_ = 0;
  ai_chain_count_ = 0;
  // Cierre de rafaga: la mezcla ya corrio entera; toca
  // resolver si desperto a algun trabajador (paso diferido).
  ResolveAiWake(cpu);
  // Fase 8: al cerrar la rafaga AI, el breakpoint GX tiene
  // su oportunidad en el mismo punto (si la entrega AI
  // ocupo el cierre de la cadena VI, el BP no se queda sin
  // su entrega de este retrace).
  if (DeliverBreakPtCallbackRet(cpu, ret)) return true;
  cpu->pc = ret;
  return true;
}

// ------------------------------------------------------------------
// Breakpoint GX (Fase 8, port web; mecanismo y modelo en
// hle.h, junto a kBpCallbackTrampoline).
//
// La entrega sigue el patron de la IRQ AI de la Fase 7: se
// intenta solo en puntos seguros del HLE (tras la cadena VI,
// en VIWaitForRetrace y en el sueno de frame del principal,
// siempre despues de la entrega AI) y el callback corre como
// codigo huesped ordinario sobre el hilo actual, asi que sus
// llamadas OS (el OSSendMessage de THPPlayerPostDrawDone a
// freetex) despiertan trabajadores por las vias normales del
// planificador, sin necesidad de paso diferido. Nunca se
// entrega con una cadena AI o BP en curso, ni dos veces en
// el mismo retrace (la cadencia hardware del mecanismo:
// GXFlush arma una vez por frame sometido y el disparo
// llega cuando el GP lo ha consumido, esto es, dentro del
// mismo frame).

bool Hle::DeliverBreakPtCallback(CpuState* cpu) {
  return DeliverBreakPtCallbackRet(cpu,
                                    cpu != nullptr ? cpu->lr : 0);
}

bool Hle::DeliverBreakPtCallbackRet(CpuState* cpu, uint32_t ret) {
  if (cpu == nullptr || bp_chain_active_ || ai_chain_active_) {
    return false;
  }
  if (bp_last_retrace_ == retrace_count_) return false;
  uint32_t r13 = cpu->gpr[13];
  uint32_t armed = ::mem_read32(cpu, r13 - 20660u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  if (armed == 0) return false;  // GXDisableBreakPt lo limpia.
  uint32_t cb = ::mem_read32(cpu, r13 - 20668u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  // El callback ha de ser codigo huesped en RAM principal;
  // cualquier otra cosa (0, un trampolin HLE, un puntero de
  // datos) no es un registro valido de GXSetBreakPtCallback.
  if (cb < 0x80000000u || cb >= 0x81800000u) return false;
  bp_chain_active_ = true;
  bp_chain_ret_ = ret;
  bp_last_retrace_ = retrace_count_;
  ++bp_delivered_;
  if (bp_delivered_ <= 12 || bp_delivered_ % 500 == 0) {
    SFA_LOGI("hle: breakpoint GX entregado (#%llu, callback "
             "0x%08X, armado 0x%08X, retorno 0x%08X)",
             static_cast<unsigned long long>(bp_delivered_), cb,
             armed, bp_chain_ret_);
  }
  cpu->pc = cb;
  cpu->lr = kBpCallbackTrampoline;
  return true;
}

bool Hle::HandleBpTrampoline(CpuState* cpu) {
  if (cpu == nullptr) return false;
  if (!bp_chain_active_) {
    // No deberia ocurrir (el PC sintetico solo lo pone este
    // HLE como lr de la entrega); si el huesped aterriza
    // aqui sin cadena, se vuelve por lr sin tocar nada mas.
    SFA_LOGE("hle: trampolin BP sin cadena activa (pc "
             "0x%08X, lr 0x%08X): retorno sin efecto",
             cpu->pc, cpu->lr);
    return Return(cpu, 0);
  }
  uint32_t ret = bp_chain_ret_;
  bp_chain_active_ = false;
  bp_chain_ret_ = 0;
  cpu->pc = ret;
  return true;
}

void Hle::SnapshotAiWaiters(CpuState* cpu) {
  ai_burst_waiters_.clear();
  if (cpu == nullptr) return;
  for (size_t i = 0; i < threads_.size(); ++i) {
    const ThreadEntry& t = threads_[i];
    if (!t.has_ctx || t.finished) continue;
    int kind = 0;
    uint32_t queue = 0;
    if (t.ctx.lr == kOsReceiveSleepRet) {
      kind = 1;
      queue = t.ctx.gpr[31];
    } else if (t.ctx.lr == kOsSendSleepRet) {
      kind = 2;
      queue = t.ctx.gpr[28];
    } else {
      continue;
    }
    if (queue == 0) continue;
    uint32_t used = ::mem_read32(cpu, queue + 28u);
    if (cpu->exception != 0) {
      cpu->exception = 0;
      continue;
    }
    if (kind == 1 && used != 0) continue;  // ya tenia mensaje
    if (kind == 2) {
      uint32_t cap = ::mem_read32(cpu, queue + 20u);
      if (cpu->exception != 0) {
        cpu->exception = 0;
        continue;
      }
      if (cap == 0 || used < cap) continue;  // no bloqueaba
    }
    AiWaiter w;
    w.idx = static_cast<int>(i);
    w.queue = queue;
    w.kind = kind;
    ai_burst_waiters_.push_back(w);
  }
}

void Hle::ResolveAiWake(CpuState* cpu) {
  if (cpu == nullptr || ai_burst_waiters_.empty()) return;
  int best = -1;
  uint32_t best_prio = 0xFFFFFFFFu;
  uint32_t best_queue = 0;
  int best_kind = 0;
  for (const AiWaiter& w : ai_burst_waiters_) {
    if (w.idx < 0 ||
        static_cast<size_t>(w.idx) >= threads_.size()) {
      continue;
    }
    const ThreadEntry& t = threads_[static_cast<size_t>(w.idx)];
    if (t.finished || !t.has_ctx) continue;
    // El candidato ha de seguir bloqueado en la misma cola:
    // si la cadena del callback cambio de hilo a mitad (la
    // mezcla no duerme, pero el previo encadenado podria),
    // la foto ya no describe su espera y no se anota nada.
    uint32_t want_lr =
        w.kind == 1 ? kOsReceiveSleepRet : kOsSendSleepRet;
    uint32_t have_queue =
        w.kind == 1 ? t.ctx.gpr[31] : t.ctx.gpr[28];
    if (t.ctx.lr != want_lr || have_queue != w.queue) continue;
    uint32_t used = ::mem_read32(cpu, w.queue + 28u);
    if (cpu->exception != 0) {
      cpu->exception = 0;
      continue;
    }
    bool woken = false;
    if (w.kind == 1) {
      woken = used > 0;
    } else {
      uint32_t cap = ::mem_read32(cpu, w.queue + 20u);
      if (cpu->exception != 0) {
        cpu->exception = 0;
        continue;
      }
      woken = cap > 0 && used < cap;
    }
    if (!woken) continue;
    if (best < 0 || t.priority < best_prio) {
      best = w.idx;
      best_prio = t.priority;
      best_queue = w.queue;
      best_kind = w.kind;
    }
  }
  ai_burst_waiters_.clear();
  if (best >= 0) {
    irq_woken_idx_ = best;
    irq_woken_queue_ = best_queue;
    irq_woken_kind_ = best_kind;
    ++ai_irq_wakes_;
    if (ai_irq_wakes_ <= 20) {
      const ThreadEntry& t = threads_[static_cast<size_t>(best)];
      SFA_LOGI("sched: despertar IRQ AI anotado (hilo "
               "0x%08X, entry 0x%08X, prioridad %u): paso "
               "diferido al siguiente cambio natural",
               t.thread_guest, t.entry, t.priority);
    }
  }
}

// ------------------------------------------------------------------
// Planificador cooperativo (Fase 9).
//
// Modelo (leido del codigo SDK huesped, no de un manual):
//   OSCreateThread (0x80246C54): r3 hilo, r4 entry, r5 val,
//     r6 stack (TOP, no base), r7 tamano, r8 prioridad 0..31,
//     r9 attr. Escribe en el struct: estado [712]=1,
//     suspend [716]=1, prioridad [720]=[724], [728]=-1,
//     [744..760]=0, stack [772]=r6, fondo [776]=r6-r7 con
//     canario 0xDEADBABE en el fondo, y contexto via
//     OSInitContext (0x80242DD8): PC [408]=entry, SP [4]=
//     (stack alineado a 8)-8, MSR [412]=0x9032, gpr3 [12]=val,
//     gpr2 [8] y gpr13 [52] del creador, resto a cero.
//     Los hilos THP lo confirman: video (stack = propio
//     struct, 4096 B justo debajo, V+88..V+4184), audio
//     igual, read (stack en R+0..R+4096, struct en R+4096).
//   OSReceiveMessage (0x80244A68) / OSSendMessage (0x802449A0):
//     colas con [16]=array, [20]=capacidad, [24]=firstIndex,
//     [28]=usedCount; si la cola esta vacia (Receive) o llena
//     (Send) y flags&1, duermen con OSSleepThread y reintentan.
//   OSSuspendThread (0x8024729C): [716]++ y, si el contador
//     era 0, suspende (estado 1, flag de replanificacion);
//     si ya estaba suspendido, solo incrementa.
//   OSResumeThread (0x80247014): [716]-- (con clamp a 0);
//     solo cuando llega a 0 el hilo vuelve a listo (mascara
//     de listos [r13-21248], bit 31-prioridad).
//
// El chassis es un unico flujo de despachos: el cambio de
// contexto es, por tanto, guardar el CPUState del hilo actual
// en su ThreadEntry (o en main_ctx_ para el principal) y
// cargar el del siguiente, poniendo pc en su punto de
// reanudacion (lr del sueno/suspension, o entry en el primer
// arranque). El SelectThread huesped nunca corre; la mascara
// de listos y el flag [r13-21244] se mantienen como espejo.
// LIMITACIONES (documentadas, no ocultas): cooperativo, sin
// rodaja de tiempo (un hilo que nunca duerme/suspende no
// cede la CPU); Resume no adelanta (el hilo reanudado corre
// cuando el actual ceda, no en el acto); el sueno de frame
// (waitNextFrame) no cambia de hilo (queda para la fase de
// bucle de frames); el estado [712] del struct es espejo
// (1 listo/suspendido, 2 en ejecucion), el autoritativo es
// ThreadEntry. Un hilo que suspende sin relevo listo cae en
// el camino de retorno instantaneo anterior (gira, como
// antes) y queda registrado en scheduler_fallbacks_.

Hle::ThreadEntry* Hle::FindThread(uint32_t guest) {
  for (ThreadEntry& t : threads_) {
    if (t.thread_guest == guest) return &t;
  }
  return nullptr;
}

void Hle::SaveCurrent(CpuState* cpu, uint32_t resume_pc) {
  ThreadContext* dst = nullptr;
  if (current_thread_ < 0) {
    dst = &main_ctx_;
    main_saved_ = true;
  } else {
    ThreadEntry& t = threads_[static_cast<size_t>(current_thread_)];
    dst = &t.ctx;
    t.has_ctx = true;
    // Canario de pila del hilo (Fase 9, diagnostico): si el
    // hilo desbordo su pila de 4096 B, el fondo ya no es
    // 0xDEADBABE. Solo se avisa una vez por hilo.
    if (!t.canary_warned && t.stack_size > 0) {
      uint32_t bottom = t.stack - t.stack_size;
      uint32_t v = ::mem_read32(cpu, bottom);
      if (cpu->exception == 0 && v != 0xDEADBABEu) {
        t.canary_warned = true;
        SFA_LOGI("sched: CANARIO de pila alterado en hilo "
                 "0x%08X (fondo 0x%08X = 0x%08X, no 0xDEADBABE)",
                 t.thread_guest, bottom, v);
      } else if (cpu->exception != 0) {
        cpu->exception = 0;
      }
    }
  }
  for (int i = 0; i < 32; ++i) {
    dst->gpr[i] = cpu->gpr[i];
    dst->fpr[i] = cpu->fpr[i];
    dst->ps1[i] = cpu->ps1[i];
  }
  dst->pc = resume_pc;
  dst->lr = cpu->lr;
  dst->ctr = cpu->ctr;
  dst->cr = cpu->cr;
  dst->xer = cpu->xer;
  dst->fpscr = cpu->fpscr;
  dst->msr = cpu->msr;
  dst->srr0 = cpu->srr0;
  dst->srr1 = cpu->srr1;
  dst->dar = cpu->dar;
  dst->dsisr = cpu->dsisr;
  dst->ear = cpu->ear;
  for (int i = 0; i < 16; ++i) dst->sr[i] = cpu->sr[i];
  for (int i = 0; i < 8; ++i) dst->gqr[i] = cpu->gqr[i];
  dst->program_exception = cpu->program_exception;
}

void Hle::LoadContext(CpuState* cpu, const ThreadContext& ctx) {
  for (int i = 0; i < 32; ++i) {
    cpu->gpr[i] = ctx.gpr[i];
    cpu->fpr[i] = ctx.fpr[i];
    cpu->ps1[i] = ctx.ps1[i];
  }
  cpu->pc = ctx.pc;
  cpu->lr = ctx.lr;
  cpu->ctr = ctx.ctr;
  cpu->cr = ctx.cr;
  cpu->xer = ctx.xer;
  cpu->fpscr = ctx.fpscr;
  cpu->msr = ctx.msr;
  cpu->srr0 = ctx.srr0;
  cpu->srr1 = ctx.srr1;
  cpu->dar = ctx.dar;
  cpu->dsisr = ctx.dsisr;
  cpu->ear = ctx.ear;
  for (int i = 0; i < 16; ++i) cpu->sr[i] = ctx.sr[i];
  for (int i = 0; i < 8; ++i) cpu->gqr[i] = ctx.gqr[i];
  cpu->program_exception = ctx.program_exception;
  cpu->reserve_valid = false;
  cpu->exception = 0;
}

void Hle::LoadMain(CpuState* cpu) {
  LoadContext(cpu, main_ctx_);
  current_thread_ = -1;
}

bool Hle::MainReady(CpuState* cpu) {
  if (!main_saved_) return false;
  if (blocked_kind_ == 0 || blocked_queue_ == 0) return true;
  if (blocked_kind_ == 1) {
    uint32_t used = ::mem_read32(cpu, blocked_queue_ + 28u);
    if (cpu->exception != 0) {
      cpu->exception = 0;
      return false;
    }
    return used > 0;
  }
  uint32_t capacity = ::mem_read32(cpu, blocked_queue_ + 20u);
  uint32_t used = ::mem_read32(cpu, blocked_queue_ + 28u);
  if (cpu->exception != 0) {
    cpu->exception = 0;
    return false;
  }
  return used < capacity;
}

void Hle::UpdateReadyMask(CpuState* cpu) {
  uint32_t mask = 0;
  for (const ThreadEntry& t : threads_) {
    if (t.runnable && !t.suspended && !t.finished) {
      mask |= (1u << (31u - (t.priority & 31u)));
    }
  }
  ::mem_write32(cpu, cpu->gpr[13] - 21248u, mask);
  if (cpu->exception != 0) cpu->exception = 0;
}

bool Hle::SwitchToMain(CpuState* cpu, bool save_current) {
  if (!main_saved_) return false;
  if (blocked_kind_ == 1 && blocked_queue_ != 0) {
    uint32_t used = ::mem_read32(cpu, blocked_queue_ + 28u);
    uint32_t array = ::mem_read32(cpu, blocked_queue_ + 16u);
    uint32_t first = ::mem_read32(cpu, blocked_queue_ + 24u);
    uint32_t capacity = ::mem_read32(cpu, blocked_queue_ + 20u);
    if (cpu->exception == 0 && used > 0 && capacity > 0) {
      uint32_t msg = ::mem_read32(cpu, array + (first % capacity) * 4u);
      if (cpu->exception == 0) {
        MainWakeDelivery d;
        d.queue = blocked_queue_;
        d.message = msg;
        if (current_thread_ >= 0) {
          const ThreadEntry& s =
              threads_[static_cast<size_t>(current_thread_)];
          d.sender_guest = s.thread_guest;
          d.sender_entry = s.entry;
        }
        if (main_wake_deliveries_.size() < 10000) {
          main_wake_deliveries_.push_back(d);
        }
        if (main_wake_deliveries_.size() <= 20) {
          SFA_LOGI("sched: principal despierta: cola 0x%08X "
                   "mensaje 0x%08X (remitente hilo 0x%08X, "
                   "entry 0x%08X)",
                   d.queue, d.message, d.sender_guest, d.sender_entry);
        }
      } else {
        cpu->exception = 0;
      }
    } else if (cpu->exception != 0) {
      cpu->exception = 0;
    }
  }
  if (save_current) SaveCurrent(cpu, cpu->lr);
  int prev = current_thread_;
  LoadMain(cpu);
  ++switches_total_;
  ++switches_to_main_;
  if (prev >= 0) {
    ThreadEntry& p = threads_[static_cast<size_t>(prev)];
    ::mem_write16(cpu, p.thread_guest + 712u, 1u);
    if (cpu->exception != 0) cpu->exception = 0;
  }
  ::mem_write32(cpu, cpu->gpr[13] - 21244u, 0u);
  if (cpu->exception != 0) cpu->exception = 0;
  UpdateReadyMask(cpu);
  if (DeliverViCallbacks(cpu)) return true;
  return true;
}

bool Hle::SwitchToWorker(CpuState* cpu, size_t idx, bool save_current) {
  if (idx >= threads_.size()) return false;
  ThreadEntry& next = threads_[idx];
  if (!next.runnable || next.suspended || next.finished || !next.has_ctx) {
    return false;
  }
  if (save_current) SaveCurrent(cpu, cpu->lr);
  int prev = current_thread_;
  if (prev >= 0) {
    ThreadEntry& p = threads_[static_cast<size_t>(prev)];
    ::mem_write16(cpu, p.thread_guest + 712u, 1u);
    if (cpu->exception != 0) cpu->exception = 0;
  }
  current_thread_ = static_cast<int>(idx);
  next.started = true;
  ++next.switches_in;
  ++switches_total_;
  LoadContext(cpu, next.ctx);
  ::mem_write16(cpu, next.thread_guest + 712u, 2u);
  if (cpu->exception != 0) cpu->exception = 0;
  ::mem_write32(cpu, cpu->gpr[13] - 21244u, 0u);
  if (cpu->exception != 0) cpu->exception = 0;
  UpdateReadyMask(cpu);
  return true;
}

bool Hle::SwitchOnSleep(CpuState* cpu) {
  // Portador de la cadena de despertares (Fase 7): de un
  // solo uso, se consume a la entrada; si el hilo que
  // duerme ES el portador, tras el bloque de la IRQ se
  // busca el siguiente eslabon (ver chain_from_idx_ en
  // hle.h).
  int chain_carrier = chain_from_idx_;
  chain_from_idx_ = -1;
  // Fase 7 (diseno Fase 6 §9): paso DIFERIDO al hilo
  // despertado por la IRQ AI, evaluado a la ENTRADA de
  // cualquier sueno. La anotacion la dejo el cierre de una
  // rafaga (ResolveAiWake). Evaluarlo aqui, y no tras
  // registrar el sueno del principal, es una correccion
  // medida en la primera verificacion de la Fase 7: el
  // registro de abajo sale antes de tiempo cuando el
  // principal duerme en un punto que no es de cola (espera
  // VI / sueno de frame), y durante el atasco del attract
  // esos son los UNICOS puntos de cambio que ocurren (los
  // trabajadores estan todos bloqueados), asi que la marca
  // nunca se consumia y el hilo despertado seguia sin turno
  // (medido: marca anotada en f=230 y consumida en f=281,
  // ya en el ciclo siguiente y sobre un hilo re-creado).
  // Las invariantes se mantienen: el cambio ocurre en un
  // sueno voluntario del hilo actual (nunca desde el
  // trampolin de la IRQ a mitad de recepcion: eso era c11),
  // de este cambio no nace ninguna entrega (sin reignicion:
  // eso era c13) y la entrega AI sigue yendo tras la VI en
  // sus sitios. La marca se consume se aplique o no.
  if (irq_woken_idx_ >= 0) {
    int idx = irq_woken_idx_;
    uint32_t wqueue = irq_woken_queue_;
    int wkind = irq_woken_kind_;
    irq_woken_idx_ = -1;
    irq_woken_queue_ = 0;
    irq_woken_kind_ = 0;
    if (idx != current_thread_ &&
        idx < static_cast<int>(threads_.size())) {
      ThreadEntry& t = threads_[static_cast<size_t>(idx)];
      // Revalidacion estricta: el paso solo se da si el
      // hilo sigue dormido en la MISMA espera que la IRQ
      // completo (mismo retorno de sueno en su contexto y
      // misma cola en el registro de la llamada). Si ya
      // corrio por round-robin o fue re-creado, la marca
      // era vieja y se descarta en silencio.
      uint32_t want_lr =
          wkind == 1 ? kOsReceiveSleepRet : kOsSendSleepRet;
      uint32_t have_queue =
          wkind == 1 ? t.ctx.gpr[31] : t.ctx.gpr[28];
      if (t.runnable && !t.suspended && !t.finished &&
          t.has_ctx && t.ctx.lr == want_lr &&
          have_queue == wqueue) {
        if (current_thread_ < 0) {
          // Registrar el sueno del principal como hace el
          // bloque normal de abajo: si duerme por cola, su
          // cola; si no (espera VI / sueno de frame), sin
          // cola, para que MainReady lo reanude en el
          // siguiente cambio y su mensaje (si lo hay) siga
          // esperandolo en su cola, como hoy. Solo cede UN
          // turno al trabajador que la IRQ desperto, que es
          // lo que __OSReschedule haria en hardware tras la
          // interrupcion.
          if (cpu->lr == kOsReceiveSleepRet) {
            blocked_queue_ = cpu->gpr[31];
            blocked_kind_ = 1;
          } else if (cpu->lr == kOsSendSleepRet) {
            blocked_queue_ = cpu->gpr[28];
            blocked_kind_ = 2;
          } else {
            blocked_queue_ = 0;
            blocked_kind_ = 0;
          }
        }
        if (SwitchToWorker(cpu, static_cast<size_t>(idx),
                           true)) {
          ++ai_irq_boosts_;
          chain_from_idx_ = idx;
          return true;
        }
      }
    }
  }
  // Fase 7: salto en cadena del paso diferido. El hilo que
  // duerme es el portador (recibio el turno por la IRQ o
  // por otro salto) y durante su turno envio mensajes: si
  // algun trabajador sigue dormido en una espera de cola
  // que AHORA esta completada (Receive con mensaje, Send
  // con hueco), ese trabajador es el siguiente eslabon y
  // recibe el paso antes de que MainReady devuelva la CPU
  // al principal. Mismo criterio de revalidacion que el
  // paso IRQ (contexto dormido en esa espera, hilo
  // ejecutable) y desempate por prioridad del SO (menor
  // valor primero). Si no hay eslabon, el flujo normal
  // sigue intacto.
  if (chain_carrier >= 0 && current_thread_ == chain_carrier) {
    int best = -1;
    uint32_t best_prio = 0xFFFFFFFFu;
    for (size_t i = 0; i < threads_.size(); ++i) {
      if (static_cast<int>(i) == current_thread_) continue;
      const ThreadEntry& t = threads_[i];
      if (!t.runnable || t.suspended || t.finished ||
          !t.has_ctx) {
        continue;
      }
      int kind = 0;
      uint32_t queue = 0;
      if (t.ctx.lr == kOsReceiveSleepRet) {
        kind = 1;
        queue = t.ctx.gpr[31];
      } else if (t.ctx.lr == kOsSendSleepRet) {
        kind = 2;
        queue = t.ctx.gpr[28];
      } else {
        continue;
      }
      if (queue == 0) continue;
      uint32_t used = ::mem_read32(cpu, queue + 28u);
      if (cpu->exception != 0) {
        cpu->exception = 0;
        continue;
      }
      bool satisfied = false;
      if (kind == 1) {
        satisfied = used > 0;
      } else {
        uint32_t cap = ::mem_read32(cpu, queue + 20u);
        if (cpu->exception != 0) {
          cpu->exception = 0;
          continue;
        }
        satisfied = cap > 0 && used < cap;
      }
      if (!satisfied) continue;
      if (best < 0 || t.priority < best_prio) {
        best = static_cast<int>(i);
        best_prio = t.priority;
      }
    }
    if (best >= 0 &&
        SwitchToWorker(cpu, static_cast<size_t>(best), true)) {
      ++ai_chain_hops_;
      chain_from_idx_ = best;
      if (ai_chain_hops_ <= 20) {
        const ThreadEntry& t = threads_[static_cast<size_t>(best)];
        SFA_LOGI("sched: salto en cadena IRQ AI (hilo "
                 "0x%08X, entry 0x%08X, prioridad %u)",
                 t.thread_guest, t.entry, t.priority);
      }
      return true;
    }
  }
  if (current_thread_ < 0) {
    if (cpu->lr != kOsReceiveSleepRet && cpu->lr != kOsSendSleepRet) {
      return false;
    }
    // Cola viva, NO la guardada en el marco: el prologo de
    // Receive guarda el r31 del LLAMADOR en +36 antes de
    // poner r31 = cola (y Send guarda el r28 del llamador
    // en +24 antes de poner r28 = cola). Leer el marco daba
    // la base P (0x803A7120) en vez de la cola prepare
    // (0x803A764C): ese fue el fallo del run36 (el
    // principal nunca veia su cola con mensaje).
    if (cpu->lr == kOsReceiveSleepRet) {
      blocked_queue_ = cpu->gpr[31];
      blocked_kind_ = 1;
    } else {
      blocked_queue_ = cpu->gpr[28];
      blocked_kind_ = 2;
    }
  }
  if (MainReady(cpu)) {
    if (SwitchToMain(cpu, true)) return true;
  }
  size_t n = threads_.size();
  size_t start = 0;
  if (n > 0) {
    start = current_thread_ < 0
                ? 0
                : (static_cast<size_t>(current_thread_) + 1) % n;
    for (size_t k = 0; k < n; ++k) {
      size_t idx = (start + k) % n;
      if (static_cast<int>(idx) == current_thread_) continue;
      ThreadEntry& t = threads_[idx];
      if (t.runnable && !t.suspended && !t.finished) {
        if (SwitchToWorker(cpu, idx, true)) return true;
      }
    }
  }
  return false;
}

void Hle::WriteThreadGuestFields(CpuState* cpu, ThreadEntry* t) {
  if (cpu == nullptr || t == nullptr) return;
  uint32_t thread = t->thread_guest;
  uint32_t sp = (t->stack & ~7u) - 8u;
  ::mem_write16(cpu, thread + 712u, 1u);
  ::mem_write16(cpu, thread + 714u, 1u);
  ::mem_write32(cpu, thread + 716u, t->suspend_count);
  ::mem_write32(cpu, thread + 720u, t->priority);
  ::mem_write32(cpu, thread + 724u, t->priority);
  ::mem_write32(cpu, thread + 728u, 0xFFFFFFFFu);
  for (uint32_t off = 744u; off <= 760u; off += 4u) {
    ::mem_write32(cpu, thread + off, 0u);
  }
  ::mem_write32(cpu, thread + 772u, t->stack);
  ::mem_write32(cpu, thread + 776u, t->stack - t->stack_size);
  ::mem_write32(cpu, t->stack - t->stack_size, 0xDEADBABEu);
  for (int i = 0; i < 32; ++i) {
    uint32_t v = 0;
    if (i == 1) v = sp;
    if (i == 2) v = cpu->gpr[2];
    if (i == 3) v = t->val;
    if (i == 13) v = cpu->gpr[13];
    ::mem_write32(cpu, thread + static_cast<uint32_t>(i * 4), v);
  }
  ::mem_write32(cpu, thread + 128u, 0u);
  ::mem_write32(cpu, thread + 132u, 0u);
  ::mem_write32(cpu, thread + 136u, 0u);
  ::mem_write32(cpu, thread + 140u, 0u);
  ::mem_write32(cpu, thread + 408u, t->entry);
  ::mem_write32(cpu, thread + 412u, 0x9032u);
  for (uint32_t off = 420u; off <= 432u; off += 4u) {
    ::mem_write32(cpu, thread + off, 0u);
  }
  uint32_t next = ::mem_read32(cpu, 0x800000E0u);
  if (cpu->exception == 0) {
    if (next != 0) {
      ::mem_write32(cpu, next + 764u, thread);
    } else {
      ::mem_write32(cpu, 0x800000DCu, thread);
    }
    ::mem_write32(cpu, thread + 768u, next);
    ::mem_write32(cpu, thread + 764u, 0u);
    ::mem_write32(cpu, 0x800000E0u, thread);
  }
  if (cpu->exception != 0) cpu->exception = 0;
}


// ---- Tramo 12 (PARCHE PROPUESTO, copia host; NO aplicado al repo) ----
// Hueco: la entrega ARQ de lectura del Tramo 8 despacha el callback
// (AudioAramReadCompleteCallback) pero NUNCA copia datos ARAM->MRAM:
// no hay ARAM modelada. Consecuencia medida: bankData de la cancion 94
// (dest 0x810A9800) conserva datos viejos del bufer ([bank+0]=0), asi
// que seqStartPlay construye punteros de pista basura y
// GenerateNextTrackEvent falla en la pista 19 (ver INFORME.md).
// Parche minimo: modelo ARAM host de 16 MiB (tamano real de ARAM en
// GameCube). En cada ARQPostRequest de subida (tipo 0) se copia
// MRAM->ARAM; en la entrega de cada lectura se copia ARAM->MRAM
// ANTES de redirigir al callback. Layout peticion SDK (ARQPostRequest
// 0x802516D4, verificado en codigo huesped y en los posts del
// propio juego): [req+8]=tipo (1=lectura de audio, 0=subida),
// [req+16]=ORIGEN, [req+20]=DESTINO, [req+24]=len; el origen/destino
// son ARAM/MRAM segun la direccion (lectura: origen ARAM, destino
// MRAM; subida: origen MRAM, destino ARAM). NO son campos fijos
// ARAM/MRAM: la primera version de este parche los tenia
// intercambiados para subidas y no capturo nada (ver INFORME).
// No se inventa ningun dato: solo se copian bytes que el propio juego
// subio antes a ARAM. Si un rango ARAM nunca se escribio, la lectura
// copia ceros (comportamiento previo, sin regresion).
namespace {
constexpr uint32_t kT12AramSize = 0x1000000u;  // 16 MiB
std::vector<uint8_t> g_t12_aram;
std::vector<uint8_t> g_t12_aram_written;  // 1 byte por bloque de 256 B
uint64_t g_t12_aram_write_bytes = 0;
uint64_t g_t12_aram_read_bytes = 0;
uint32_t T12ReadBe32(const uint8_t* p) {
  return (static_cast<uint32_t>(p[0]) << 24) |
         (static_cast<uint32_t>(p[1]) << 16) |
         (static_cast<uint32_t>(p[2]) << 8) | static_cast<uint32_t>(p[3]);
}
// Puntero host a RAM huesped (cached 0x80000000, uncached 0xC0000000,
// forma fisica < ram_size); nullptr si fuera de rango.
uint8_t* T12GuestPtr(CpuState* cpu, uint32_t guest, uint32_t len) {
  if (cpu == nullptr || cpu->ram == nullptr || len == 0) return nullptr;
  uint32_t off = 0;
  if (guest >= 0x80000000u && guest < 0x80000000u + cpu->ram_size) {
    off = guest - 0x80000000u;
  } else if (guest >= 0xC0000000u &&
             guest < 0xC0000000u + cpu->ram_size) {
    off = guest - 0xC0000000u;
  } else if (guest < cpu->ram_size) {
    off = guest;
  } else {
    return nullptr;
  }
  if (off + len > cpu->ram_size) return nullptr;
  return cpu->ram + off;
}
bool T12ArqFields(CpuState* cpu, uint32_t req, uint32_t* type,
                  uint32_t* aram, uint32_t* mram, uint32_t* len) {
  uint8_t* p = T12GuestPtr(cpu, req, 28);
  if (p == nullptr) return false;
  *type = T12ReadBe32(p + 8);
  *aram = T12ReadBe32(p + 16);
  *mram = T12ReadBe32(p + 20);
  *len = T12ReadBe32(p + 24);
  return true;
}
void T12AramEnsure() {
  if (g_t12_aram.empty()) {
    g_t12_aram.assign(kT12AramSize, 0);
    g_t12_aram_written.assign(kT12AramSize / 256, 0);
  }
}
}  // namespace

bool Hle::HandleHostCall(CpuState* cpu, uint32_t address) {
  // Entrega ARQ de lectura (Tramo 8, desbloqueo de Music).
  // Problema medido (Tramo 7, G1/G2/G4): el juego alloca
  // canales de musica (tracks 22 y 95) en status=4
  // esperando el DMA ARAM, pero el HLE no entrega el
  // callback ARQ de lectura, asi que
  // Music_ChannelLoadedCallback nunca corre y sndSeqPlayEx
  // del juego es 0. Cadena verificada en codigo huesped:
  //   Music_LoadChannelForTrigger (0x8000B0F0) ->
  //   AudioAramReadAllocAsync (0x80008DF4) -> ARQPostRequest
  //   (0x802516D4, codigo huesped) con r3 = entrada del
  //   juego (pool 0x803372A0, 16 x 0x30), r6 = dir (1 =
  //   ARAM->MRAM, lectura; el propio ARQPostRequest hace
  //   cmpwi r6,1 para elegir cola), r10 = callback del
  //   servicio ARQ (0x80008EDC, AudioAramReadComplete-
  //   Callback, que busca la entrada por puntero y llama
  //   a su callback +32 con +36/+40/+44 como args).
  // Mecanica (sin RunChassis anidado y sin perder el hook
  // de audio del chassis, a diferencia del diseno
  // HLE-ARQ-READ-DELIVERY del Tramo 7, que proponia
  // snapshot/restore alrededor de un redespacho):
  //   1. En la entrada a ARQPostRequest se encola la
  //      peticion si dir==1 y callback==0x80008EDC (solo
  //      lecturas de audio; las escrituras y otras
  //      lecturas quedan como antes).
  //   2. En el SIGUIENTE host_call (dolrecomp_call
  //      consulta host_call en CADA despacho, asi que
  //      esto ocurre en el despacho siguiente al post,
  //      dentro o justo despues de ARQPostRequest), se
  //      redirige: se guardan todos los registros en un
  //      marco, pc = 0x80008EDC, r3 = peticion,
  //      lr = trampolin 0x8000300C, y se devuelve true.
  //      El chassis despacha entonces el callback como
  //      codigo huesped normal (el hook de audio ve el
  //      sndSeqPlayEx real que sigue, sin intervencion).
  //   3. El blr del callback aterriza en el trampolin:
  //      se restaura TODO el registro guardado, pc =
  //      direccion interceptada, lr = lr original, y se
  //      devuelve true: el punto interceptado se despacha
  //      entonces con normalidad (HLE o chunk original).
  // Por que es seguro interrumpir en cualquier punto:
  // el callback solo toca estado de musica en RAM
  // (status/seqHandle del canal), el bridge por el hook
  // y scratch de pila (restaurado via r1 en el marco);
  // NO toca la cola ARQ ni los registros que
  // ARQPostRequest aun no ha terminado de usar, porque
  // todos se restauran en el trampolin. La RAM no se
  // restaura a proposito: los efectos del callback SON
  // la entrega. Si el callback a su vez postea otra
  // lectura, la pila LIFO la anida correctamente (el
  // trampolin desapila en orden inverso); en la practica
  // la cola nunca acumula mas de una peticion, porque
  // cada post va seguido de un despacho que la entrega.
  // Sin marco en el trampolin: error interno ruidoso
  // (exception), igual que el trampolin DVD.
  if (address == kArqReadDeliveryTrampoline) {
    if (arq_read_frames_.empty()) {
      SFA_LOGE("hle: ARQReadTrampoline sin marco: error "
               "interno, exception");
      cpu->exception = 1;
      return true;
    }
    ArqReadFrame frame = arq_read_frames_.back();
    arq_read_frames_.pop_back();
    ++arq_read_trampolines_;
    for (int i = 0; i < 32; ++i) {
      cpu->gpr[i] = frame.gpr[i];
      cpu->fpr[i] = frame.fpr[i];
      cpu->ps1[i] = frame.ps1[i];
    }
    cpu->ctr = frame.ctr;
    cpu->cr = frame.cr;
    cpu->xer = frame.xer;
    cpu->fpscr = frame.fpscr;
    cpu->msr = frame.msr;
    cpu->srr0 = frame.srr0;
    cpu->srr1 = frame.srr1;
    cpu->dar = frame.dar;
    cpu->dsisr = frame.dsisr;
    cpu->ear = frame.ear;
    for (int i = 0; i < 16; ++i) cpu->sr[i] = frame.sr[i];
    for (int i = 0; i < 8; ++i) cpu->gqr[i] = frame.gqr[i];
    cpu->pc = frame.resume_pc;
    cpu->lr = frame.resume_lr;
    SFA_LOGI("hle: ARQ lectura retornada (peticion 0x%08X, "
             "reanudada 0x%08X, marcos %zu)",
             frame.req, frame.resume_pc, arq_read_frames_.size());
    return true;
  }
  if (!arq_read_pending_.empty()) {
    uint32_t req = arq_read_pending_.front();
    arq_read_pending_.erase(arq_read_pending_.begin());
    {
      // Tramo 12: copia ARAM->MRAM de la lectura antes de entregar
      // el callback (en hardware real el DMA ya completo).
      uint32_t type = 0, aram = 0, mram = 0, len = 0;
      if (T12ArqFields(cpu, req, &type, &aram, &mram, &len)) {
        T12AramEnsure();
        uint8_t* dst = T12GuestPtr(cpu, mram, len);
        if (len > 0 && aram + len <= kT12AramSize && dst != nullptr) {
          bool written = false;
          for (uint32_t b = aram / 256; b < (aram + len + 255) / 256; ++b)
            if (g_t12_aram_written[b] != 0) written = true;
          std::memcpy(dst, g_t12_aram.data() + aram, len);
          g_t12_aram_read_bytes += len;
          SFA_LOGI(
              "hle: T12 ARAM lectura copiada (peticion 0x%08X, tipo %u, "
              "ARAM 0x%08X -> MRAM 0x%08X, %u B, fuente_escrita=%d, "
              "primer_u32=0x%08X)",
              req, type, aram, mram, len, written ? 1 : 0,
              len >= 4 ? T12ReadBe32(dst) : 0u);
        } else {
          SFA_LOGI(
              "hle: T12 ARAM lectura SIN copiar (peticion 0x%08X, tipo "
              "%u, ARAM 0x%08X, MRAM 0x%08X, %u B: fuera de rango)",
              req, type, aram, mram, len);
        }
      }
    }
    ArqReadFrame frame;
    for (int i = 0; i < 32; ++i) {
      frame.gpr[i] = cpu->gpr[i];
      frame.fpr[i] = cpu->fpr[i];
      frame.ps1[i] = cpu->ps1[i];
    }
    frame.ctr = cpu->ctr;
    frame.cr = cpu->cr;
    frame.xer = cpu->xer;
    frame.fpscr = cpu->fpscr;
    frame.msr = cpu->msr;
    frame.srr0 = cpu->srr0;
    frame.srr1 = cpu->srr1;
    frame.dar = cpu->dar;
    frame.dsisr = cpu->dsisr;
    frame.ear = cpu->ear;
    for (int i = 0; i < 16; ++i) frame.sr[i] = cpu->sr[i];
    for (int i = 0; i < 8; ++i) frame.gqr[i] = cpu->gqr[i];
    frame.resume_pc = address;
    frame.resume_lr = cpu->lr;
    frame.req = req;
    arq_read_frames_.push_back(frame);
    ++arq_read_delivered_;
    cpu->gpr[3] = req;
    cpu->lr = kArqReadDeliveryTrampoline;
    cpu->pc = kArqReadCompleteCb;
    SFA_LOGI("hle: ARQ lectura entregada (peticion 0x%08X, "
             "interceptada 0x%08X, pendientes %zu)",
             req, address, arq_read_pending_.size());
    return true;
  }
  // Evento DSP (Fase 5, desbloqueo salInitDsp): NO es una
  // sustitucion de funcion, sino la entrega del evento que el
  // DSP real produciria. Cadena verificada en el chunk_0160:
  // salInitDsp (0x80285248) construye la tarea DSP (campo
  // [40] = dspInitCallback 0x80285084, [44] =
  // dspResumeCallback), llama a DSPAddTask (0x802519CC, codigo
  // huesped: lista de tareas + __DSP_boot_task con el
  // handshake de buzones ya modelado), luego pone a 0 el
  // flag [r13-19912] (0x802852D4) y gira en 0x802852DC
  // (lwz r0,-19912(r13); cmplwi r0,0; bc si ==0) hasta que
  // el callback de init del DSP lo ponga a 1. Sin DSP no hay
  // interrupcion que dispare ese callback (run10: giro sin
  // fin en 0x802852DC, 0 excepciones). Como DSPAddTask y el
  // bucle son puntos de despacho (llamada cross-chunk y
  // retorno por el dispatcher), el HLE recuerda la tarea en
  // la entrada a DSPAddTask y entrega el callback al
  // aterrizar en el bucle: si el init_cb de la tarea es
  // dspInitCallback, se aplican SUS efectos exactos
  // ([r13-19928]=1 y [r13-19912]=1, leidos en 0x80285084);
  // cualquier otro init_cb queda solo registrado (sin
  // efecto), no inventado. El codigo huesped (lista,
  // handshake, flag a 0, sndEnd/sndBegin) corre intacto;
  // solo se suple el evento DSP, igual que el buzon
  // "siempre listo" de cpu.c. LIMITACION: las tareas DSP
  // no se ejecutan de verdad (audio DSP pendiente).
  if (address == kDspAddTask) {
    pending_dsp_task_ = cpu->gpr[3];
  } else if (address == kSalInitDspSpinHead && pending_dsp_task_ != 0) {
    uint32_t task = pending_dsp_task_;
    pending_dsp_task_ = 0;
    uint32_t init_cb = ::mem_read32(cpu, task + 40u);
    if (cpu->exception == 0 && init_cb == kDspInitCallback) {
      uint32_t r13 = cpu->gpr[13];
      ::mem_write32(cpu, r13 - 19912u, 1u);
      ::mem_write32(cpu, r13 - 19928u, 1u);
      SFA_LOGI("hle: DSP task init callback entregado "
               "(tarea 0x%08X, [r13-19912]=[r13-19928]=1)",
               task);
    } else {
      SFA_LOGI("hle: DSP task init callback 0x%08X sin modelar "
               "(tarea 0x%08X): sin efecto",
               init_cb, task);
    }
  }
  // Evento ARQ (Fase 5, desbloqueo aramInit): mismo patron que
  // el DSP. Cadena verificada en chunk_0160: aramUploadData
  // (0x802849A8) encola una subida de 40 B y llama a
  // ARQPostRequest (0x802516D4, SDK, codigo huesped), y luego
  // hace contador++ ([r31+641], 0x80284B30); aramInit
  // (0x80284B94) gira en 0x80284D58
  // (lbz r0,0(r30); cmplwi r0,0; bc si !=0) hasta que el
  // contador vuelve a 0. El contador solo lo baja
  // aramQueueCallback (0x80284910), que el servicio ARQ
  // ejecuta al completarse el DMA ARAM (interrupcion ARQ):
  // sin interrupciones, la cola nunca drena (run11: giro
  // sin fin en 0x80284D58, 0 excepciones). En este HLE el
  // DMA ARAM es instantaneo (no hay ARAM modelada ni datos
  // que leer de vuelta en esta fase), asi que cada peticion
  // ARQ se da por completada en diferido: se cuenta en la
  // entrada a ARQPostRequest y se aplica como decrementos
  // del contador que el bucle lee (puntero en r30 del huesped)
  // al aterrizar en el bucle. Los callbacks de las entradas
  // de aramInit son nulos (r8=0 en la llamada), asi que
  // drenar equivale exactamente a bajar el contador; si una
  // subida futura trae callback no nulo, habra que invocarlo
  // aqui (limitacion documentada). Las peticiones ARQ
  // intra-chunk (sin despacho) no pasan por este gancho.
  if (address == kArqPostRequest) {
    ++pending_arq_completions_;
    // Tramo 8: encolar lecturas de audio para la entrega
    // por trampolin (ver bloque al inicio de esta
    // funcion). r6 = dir (1 = ARAM->MRAM), r10 = callback
    // del servicio ARQ, r3 = peticion del juego. El
    // contador de la Fase 5 se mantiene igual que antes
    // (tambien cuenta las lecturas): no se cambia su
    // drenaje para no alterar aramInit/upload/sync.
    if (cpu->gpr[6] == 1 && cpu->gpr[10] == kArqReadCompleteCb) {
      uint32_t req = cpu->gpr[3];
      bool dup = false;
      for (uint32_t p : arq_read_pending_) {
        if (p == req) dup = true;
      }
      if (!dup && arq_read_pending_.size() < 64) {
        arq_read_pending_.push_back(req);
        ++arq_read_queued_;
        SFA_LOGI("hle: ARQ lectura encolada (peticion 0x%08X, "
                 "pendientes %zu)",
                 req, arq_read_pending_.size());
      } else {
        SFA_LOGI("hle: ARQ lectura NO encolada (peticion "
                 "0x%08X, duplicada o cola llena)",
                 req);
      }
    }
    {
      // Tramo 12: captura de subidas MRAM->ARAM (tipo 0). OJO orden:
      // este gancho corre ANTES que el chunk huesped de
      // ARQPostRequest (el switch final devuelve false y el chunk
      // escribe despues los mismos valores en la estructura), asi
      // que los argumentos se leen de los REGISTROS, no de la
      // estructura (que aun contiene la peticion anterior del
      // mismo slot). Args SDK: r3=req, r5=tipo, r7=ARAM, r8=MRAM,
      // r9=len, r10=callback. En la entrega de lectura (bloque
      // superior) la estructura YA esta escrita y si se lee de
      // ella, como antes.
      uint32_t req = cpu->gpr[3];
      uint32_t type = cpu->gpr[5];
      uint32_t src = cpu->gpr[7];
      uint32_t dst = cpu->gpr[8];
      uint32_t len = cpu->gpr[9];
      SFA_LOGI(
          "hle: T12 ARQ post (peticion 0x%08X, tipo %u, r6=%u, cb="
          "0x%08X, origen 0x%08X, destino 0x%08X, %u B)",
          req, type, cpu->gpr[6], cpu->gpr[10], src, dst, len);
      // Subida (tipo 0): origen MRAM (src), destino ARAM (dst).
      if (type == 0 && len > 0 && dst + len <= kT12AramSize) {
        uint8_t* src_ptr = T12GuestPtr(cpu, src, len);
        if (src_ptr != nullptr) {
          T12AramEnsure();
          std::memcpy(g_t12_aram.data() + dst, src_ptr, len);
          for (uint32_t b = dst / 256; b < (dst + len + 255) / 256; ++b)
            g_t12_aram_written[b] = 1;
          g_t12_aram_write_bytes += len;
        }
      }
    }
  } else if (address == kAramInitSpinHead && pending_arq_completions_ != 0) {
    DrainArqCompletions(cpu, cpu->gpr[30], "aramInit");
  } else if (address == kAramUploadWaitHead &&
             pending_arq_completions_ != 0) {
    // Contador de la cola de aramUploadData: base en r31,
    // contador en +641 (ver hle.h). El drenaje es el mismo
    // que en aramInit; solo cambia el puntero del contador.
    DrainArqCompletions(cpu, cpu->gpr[31] + 641u, "aramUploadData");
    ++arq_drained_upload_;
  } else if (address == kAudioAramWriteSyncWaitHead) {
    // Tercer drenaje ARQ (ver hle.h): entrega del callback
    // por peticion de la cola 1. Solo si el flag sigue a 0
    // y hay peticion en la cola; en otro caso, no tocar
    // nada (el giro sale solo). lr = el spin head: el blr
    // del callback vuelve al giro, que relee el flag a 1.
    uint32_t r13 = cpu->gpr[13];
    uint32_t flag = ::mem_read32(cpu, r13 - 27076u);
    uint32_t head_addr = r13 - 20816u;
    uint32_t tail_addr = r13 - 20812u;
    uint32_t req = ::mem_read32(cpu, head_addr);
    if (cpu->exception == 0 && flag == 0 && req != 0) {
      uint32_t cb = ::mem_read32(cpu, req + 28u);
      uint32_t next = ::mem_read32(cpu, req + 0u);
      if (cpu->exception == 0 && cb != 0) {
        ::mem_write32(cpu, head_addr, next);
        if (next == 0) ::mem_write32(cpu, tail_addr, 0);
        ++arq_callbacks_;
        SFA_LOGI("hle: ARQ callback entregado en "
                 "AudioAramWriteSync (peticion 0x%08X, "
                 "callback 0x%08X, siguiente 0x%08X)",
                 req, cb, next);
        cpu->exception = 0;
        cpu->gpr[3] = req;
        cpu->lr = kAudioAramWriteSyncWaitHead;
        cpu->pc = cb;
        return true;
      }
    } else if (cpu->exception != 0) {
      cpu->exception = 0;
    }
  } else if (address == kAramSyncWaitHead) {
    // Drenaje del sync-wait (ver hle.h): una DMA completada
    // por cesion. No depende de pendientes SDK: el contador
    // del juego y el contador SDK se desincronizan justo en
    // la ultima subida (el post ya se conto y se dreno en
    // un wait-head anterior, pero el juego incremento el
    // contador despues). Si quedan pendientes SDK, tambien
    // baja uno (esa DMA es una de ellas).
    uint32_t count_addr = cpu->gpr[3] + 641u;
    uint32_t count = ::mem_read8(cpu, count_addr);
    if (cpu->exception == 0 && count > 0) {
      ::mem_write8(cpu, count_addr, static_cast<uint8_t>(count - 1));
      if (pending_arq_completions_ > 0) --pending_arq_completions_;
      ++arq_drained_sync_;
      if (arq_drained_sync_ <= 20) {
        SFA_LOGI("hle: ARQ sync drenado (contador 0x%08X: %u -> "
                 "%u, pendientes SDK %u)",
                 count_addr, count, count - 1, pending_arq_completions_);
      }
    } else if (cpu->exception != 0) {
      cpu->exception = 0;
    }
  }
  const char* name = FindHleName(address);
  if (name == nullptr) return false;
  LogCall(cpu, name, address);
  switch (address) {
    case kOsPsInit:
      // __OSPSInit real (chunk 0x80241628, verificado): lee HID2,
      // le pone los bits 0xA0000000 (LSQE 0x80000000 + PSE
      // 0x20000000) y lo escribe, invalida la icache (sin efecto
      // en recompilacion) y pone gqr[0] = 0. Sin esos bits, el
      // primer psq_st (p. ej. PSMTXIdentity 0x80247800) da
      // program exception en el shim: esa exception del tramo
      // anterior era un HLE incompleto, no un fallo del juego.
      cpu->hid2 |= 0xA0000000u;
      cpu->gqr[0] = 0;
      SFA_LOGI("hle: __OSPSInit: hid2 |= 0xA0000000 (LSQE+PSE), "
               "gqr[0] = 0");
      return Return(cpu, 0);
    case kOsCacheInit:
    case kDbInit:
    case kInitUser:
      // __OSCacheInit: solo toca HID0/L2CR/error handler y
      // prints de depuracion (verificado en su chunk): sin
      // efecto observable en este runtime (no hay HID0/L2CR en
      // CPUState ni caches separadas). DBInit: depuracion.
      // __init_user (0x20 B): habilita el scheduler en hardware;
      // aqui el chassis monohilo ES el scheduler, asi que no-op.
      return Return(cpu, 0);
    case kOsInit:
      os_init_done_ = true;
      SFA_LOGI("hle: OSInit: arena 0x%08X-0x%08X (HLE provisional)",
               arena_lo_, arena_hi_);
      return Return(cpu, 0);
    case kOsInitAlloc:
      // OSInitAlloc(lo, hi) en el SDK real fija la arena y la
      // cabecera del heap; aqui se aceptan los valores del
      // llamador si son coherentes y se reinicia el bump
      // allocator del heap HLE en lo (alineado a 32).
      if (cpu->gpr[3] != 0 && cpu->gpr[4] != 0 &&
          cpu->gpr[3] < cpu->gpr[4]) {
        arena_lo_ = cpu->gpr[3];
        arena_hi_ = cpu->gpr[4];
        heap_next_ = (arena_lo_ + 31u) & ~31u;
        SFA_LOGI("hle: OSInitAlloc: arena 0x%08X-0x%08X, "
                 "heap bump en 0x%08X",
                 arena_lo_, arena_hi_, heap_next_);
      }
      return Return(cpu, 0);
    case kOsAllocFromHeap: {
      // Bump allocator HLE (un solo heap global; el handle de
      // r3 se ignora). Motivo: el OSAllocFromHeap real trabaja
      // sobre la cabecera que OSInitAlloc deberia haber
      // escrito en RAM; sin esa cabecera sigue punteros
      // basura y el acceso mem_* da exception (stop real en
      // mmInit 0x80024148, tramo anterior). El bump devuelve
      // direcciones RAM validas y alineadas a 32.
      uint32_t size = (cpu->gpr[4] + 31u) & ~31u;
      uint32_t addr = heap_next_;
      if (size == 0) {
        return Return(cpu, addr);
      }
      if (addr < arena_lo_ || addr + size > arena_hi_) {
        SFA_LOGE("hle: OSAllocFromHeap SIN MEMORIA: size=%u "
                 "next=0x%08X arena=0x%08X-0x%08X",
                 size, addr, arena_lo_, arena_hi_);
        return Return(cpu, 0);
      }
      heap_next_ = addr + size;
      return Return(cpu, addr);
    }
    case kOsFreeToHeap:
      // No-op con log: el bump allocator no reutiliza bloques
      // (fuga acotada a la fase de init; la arena es de
      // ~19 MB y las reservas de arranque son pequenas).
      // Pendiente documentado para sesiones largas.
      return Return(cpu, 0);
    case kOsGetArenaLo:
      return Return(cpu, arena_lo_);
    case kOsGetArenaHi:
      return Return(cpu, arena_hi_);
    case kOsInitAlarm:
    case kOsSetAlarm:
    case kOsCancelAlarm:
      // Alarmas: no-op con log. Ninguna alarma se dispara en
      // esta fase; si el juego depende de una, el log de HLE
      // dira cual fue la primera (pendiente documentado).
      return Return(cpu, 0);
    case kOsDisableScheduler:
    case kOsEnableScheduler:
    case kOsInitContext:
      return Return(cpu, 0);
    case kOsInitThreadQueue:
      // Codigo huesped: [q+0]=[q+4]=0 (primero/ultimo hilo).
      ::mem_write32(cpu, cpu->gpr[3] + 0u, 0u);
      ::mem_write32(cpu, cpu->gpr[3] + 4u, 0u);
      return Return(cpu, 0);
    case kOsInitMessageQueue: {
      // Implementacion real (antes era no-op, y ese era el
      // atasco siguiente al bloqueador nº 1): el codigo
      // huesped de OSInitMessageQueue escribe [q+16]=msgArray,
      // [q+20]=msgCount, [q+24]=0 (firstIndex), [q+28]=0
      // (usedCount), con las dos colas de hilos en +0 y +8 a
      // cero (OSInitThreadQueue huesped: [q+0]=[q+4]=0). Sin
      // esto, OSSendMessage (huesped, no HLEado) veia
      // capacidad 0 y dormia para siempre en run29, porque
      // used (0) >= capacidad (0).
      uint32_t q = cpu->gpr[3];
      ::mem_write32(cpu, q + 0u, 0u);
      ::mem_write32(cpu, q + 4u, 0u);
      ::mem_write32(cpu, q + 8u, 0u);
      ::mem_write32(cpu, q + 12u, 0u);
      ::mem_write32(cpu, q + 16u, cpu->gpr[4]);
      ::mem_write32(cpu, q + 20u, cpu->gpr[5]);
      ::mem_write32(cpu, q + 24u, 0u);
      ::mem_write32(cpu, q + 28u, 0u);
      return Return(cpu, 0);
    }
    case kOsCreateThread: {
      // Fase 9: captura completa (entry/val/stack/prioridad)
      // y contexto inicial como OSInitContext, mas espejo
      // guest en el struct (ver WriteThreadGuestFields).
      // Prioridad fuera de 0..31: el huesped devuelve 0.
      int32_t prio = static_cast<int32_t>(cpu->gpr[8]);
      if (prio < 0 || prio > 31) {
        SFA_LOGI("hle: OSCreateThread rechazado (prioridad %d)",
                 prio);
        return Return(cpu, 0);
      }
      ThreadEntry* existing = FindThread(cpu->gpr[3]);
      bool recreated = existing != nullptr;
      if (recreated && irq_woken_idx_ >= 0 &&
          irq_woken_idx_ ==
              static_cast<int>(existing - threads_.data())) {
        // Fase 7: el hilo anotado para el paso diferido
        // acaba de ser re-creado: su contexto viejo (y la
        // espera que la IRQ completo) ya no existe; la
        // marca no debe disparar sobre la nueva encarnacion.
        irq_woken_idx_ = -1;
        irq_woken_queue_ = 0;
        irq_woken_kind_ = 0;
      }
      ThreadEntry* t = nullptr;
      if (existing != nullptr) {
        t = existing;
      } else {
        threads_.push_back(ThreadEntry());
        t = &threads_.back();
      }
      t->thread_guest = cpu->gpr[3];
      t->entry = cpu->gpr[4];
      t->val = cpu->gpr[5];
      t->stack = cpu->gpr[6];
      t->stack_size = cpu->gpr[7];
      t->priority = cpu->gpr[8];
      t->suspend_count = 1;
      t->runnable = false;
      t->started = false;
      t->suspended = true;
      t->finished = false;
      t->switches_in = 0;
      t->yields = 0;
      t->suspends = 0;
      t->canary_warned = false;
      // Contexto inicial (OSInitContext): pc=entry, lr=
      // trampolin de salida, sp=(stack&~7)-8, gpr3=val,
      // gpr2/gpr13 del creador, msr/srr1=0x9032, resto 0.
      t->ctx = ThreadContext();
      t->ctx.pc = t->entry;
      t->ctx.lr = kThreadExitTrampoline;
      t->ctx.gpr[1] = (t->stack & ~7u) - 8u;
      t->ctx.gpr[2] = cpu->gpr[2];
      t->ctx.gpr[3] = t->val;
      t->ctx.gpr[13] = cpu->gpr[13];
      // 0x9032 de OSInitContext + bit FP (0x2000, PPC_MSR_FP):
      // en hardware real el primer FP del hilo salta al
      // manejador del SO (vector 0x800, fuera del DOL: el
      // chassis no puede ejecutarlo) y su efecto neto es
      // dejar FP activo con el contexto FP propio del hilo
      // (a cero, como OSInitContext). Activarlo en la
      // creacion es ese mismo efecto; sin el, el primer
      // FP del hilo de video (YUV) aborta con 0x20.
      t->ctx.msr = 0xB032u;
      t->ctx.srr0 = t->entry;
      t->ctx.srr1 = 0x9032u;
      t->has_ctx = true;
      WriteThreadGuestFields(cpu, t);
      SFA_LOGI("hle: OSCreateThread %s (guest 0x%08X, entry "
               "0x%08X, val 0x%08X, stack 0x%08X+%u, prio %u)",
               recreated ? "re-creado" : "registrado", t->thread_guest,
               t->entry, t->val, t->stack, t->stack_size, t->priority);
      return Return(cpu, 1);
    }
    case kOsResumeThread: {
      // Fase 9: [716]-- con clamp; solo a 0 vuelve a listo.
      // Sin adelanto: el hilo corre cuando el actual ceda.
      ThreadEntry* t = FindThread(cpu->gpr[3]);
      if (t == nullptr) {
        SFA_LOGI("hle: OSResumeThread sobre hilo desconocido "
                 "0x%08X (sin efecto, retorno 1 como antes)",
                 cpu->gpr[3]);
        return Return(cpu, 1);
      }
      if (t->suspend_count > 0) --t->suspend_count;
      t->suspended = t->suspend_count > 0;
      if (t->suspend_count == 0) {
        bool was_ready = t->runnable && !t->finished;
        t->runnable = true;
        ::mem_write32(cpu, t->thread_guest + 716u, 0u);
        ::mem_write16(cpu, t->thread_guest + 712u, 1u);
        ::mem_write32(cpu, cpu->gpr[13] - 21244u, 1u);
        if (cpu->exception != 0) cpu->exception = 0;
        UpdateReadyMask(cpu);
        if (!was_ready) {
          SFA_LOGI("hle: OSResumeThread: hilo 0x%08X listo "
                   "(entry 0x%08X, prio %u)",
                   t->thread_guest, t->entry, t->priority);
        }
      } else {
        ::mem_write32(cpu, t->thread_guest + 716u, t->suspend_count);
        if (cpu->exception != 0) cpu->exception = 0;
      }
      return Return(cpu, 1);
    }
    case kOsSuspendThread: {
      // Fase 9: [716]++ y retorno del contador anterior
      // (como el huesped). Auto-suspension: cede la CPU al
      // siguiente listo; sin relevo, retorno instantaneo
      // (desviacion solo en deadlock, registrada).
      ThreadEntry* t = FindThread(cpu->gpr[3]);
      if (t == nullptr) {
        SFA_LOGI("hle: OSSuspendThread sobre hilo desconocido "
                 "0x%08X (sin efecto, retorno 0)",
                 cpu->gpr[3]);
        return Return(cpu, 0);
      }
      uint32_t old = t->suspend_count;
      ++t->suspend_count;
      t->suspended = true;
      ++t->suspends;
      ::mem_write32(cpu, t->thread_guest + 716u, t->suspend_count);
      ::mem_write16(cpu, t->thread_guest + 712u, 1u);
      if (cpu->exception != 0) cpu->exception = 0;
      UpdateReadyMask(cpu);
      if (current_thread_ >= 0 &&
          t == &threads_[static_cast<size_t>(current_thread_)]) {
        // Auto-suspension del hilo en curso: guardar con
        // gpr3 = contador anterior (valor de retorno) y ceder.
        cpu->gpr[3] = old;
        ++t->yields;
        if (MainReady(cpu)) {
          if (SwitchToMain(cpu, true)) return true;
        }
        size_t n = threads_.size();
        size_t start =
            (static_cast<size_t>(current_thread_) + 1) % n;
        for (size_t k = 0; k < n; ++k) {
          size_t idx = (start + k) % n;
          if (static_cast<int>(idx) == current_thread_) continue;
          ThreadEntry& cand = threads_[idx];
          if (cand.runnable && !cand.suspended && !cand.finished) {
            if (SwitchToWorker(cpu, idx, true)) return true;
          }
        }
        ++scheduler_fallbacks_;
        SFA_LOGI("sched: OSSuspendThread sin relevo para hilo "
                 "0x%08X (continua: desviacion solo en deadlock)",
                 t->thread_guest);
        return Return(cpu, old);
      }
      return Return(cpu, old);
    }
    case kThreadExitTrampoline: {
      // Una funcion de hilo retorno: marcar terminada y
      // cambiar; sin relevo, volver al principal aunque su
      // cola no este lista (gira diagnosticable), y si ni
      // eso es posible, exception ruidosa.
      if (current_thread_ < 0) {
        SFA_LOGE("sched: trampolin de salida alcanzado desde "
                 "el principal (pc=0x%08X, lr=0x%08X)",
                 cpu->pc, cpu->lr);
        cpu->exception = 1;
        return true;
      }
      ThreadEntry& t = threads_[static_cast<size_t>(current_thread_)];
      t.finished = true;
      t.suspended = true;
      SFA_LOGI("sched: hilo 0x%08X terminado (entry 0x%08X, "
               "switches_in=%llu)",
               t.thread_guest, t.entry,
               static_cast<unsigned long long>(t.switches_in));
      UpdateReadyMask(cpu);
      if (MainReady(cpu)) {
        if (SwitchToMain(cpu, false)) return true;
      }
      size_t n = threads_.size();
      for (size_t k = 0; k < n; ++k) {
        ThreadEntry& cand = threads_[k];
        if (cand.runnable && !cand.suspended && !cand.finished) {
          if (SwitchToWorker(cpu, k, false)) return true;
        }
      }
      if (main_saved_ && SwitchToMain(cpu, false)) return true;
      SFA_LOGE("sched: hilo terminado sin relevo (deadlock)");
      cpu->exception = 1;
      return true;
    }
    case kDvdInit:
      dvd_init_done_ = true;
      return Return(cpu, 0);
    case kDvdOpen: {
      int ok = DvdOpen(cpu, cpu->gpr[3], cpu->gpr[4]);
      return Return(cpu, ok ? 1u : 0u);
    }
    case kDvdClose: {
      bool ok = DvdClose(cpu, cpu->gpr[3]);
      return Return(cpu, ok ? 1u : 0u);
    }
    case kDvdReadPrio: {
      int got = DvdRead(cpu, cpu->gpr[3], cpu->gpr[4], cpu->gpr[5],
                        cpu->gpr[6]);
      return Return(cpu, static_cast<uint32_t>(got));
    }
    case kDvdReadAsyncPrio: {
      // Fase 6a: lectura sincrona + callback despachado como
      // codigo huesped, en el punto que el juego espera.
      // Mecanica: el handler HLE corre dentro de
      // dolrecomp_call(cpu, async_addr) con lr = retorno del
      // llamador. Si hay callback, se ponen r3 = bytes
      // leidos y r4 = fileInfo (convencion de cbForReadAsync
      // 0x80249918: r3 resultado, r4 fileInfo) y pc =
      // callback, y se devuelve true: el chassis despacha
      // el callback a continuacion. Si el callback es 0,
      // comportamiento anterior (retorno 1/0).
      // Fase 15 (trampolin): el lr del callback YA NO es el
      // retorno del llamador, sino kDvdCallbackTrampoline
      // (0x80003008). Antes de la Fase 15 el blr del
      // callback volvia directo al llamador y entregaba el
      // retorno DEL CALLBACK como si fuera el de
      // DVDReadAsyncPrio; en hardware real ese retorno se
      // descarta (el callback corre en interrupcion, despues
      // de que DVDReadAsyncPrio ya devolviera 1) y el
      // llamador nunca lo ve. Eso rompia loadFileByPathAsync
      // (0x80015AA4: exito solo si r3 != 0) para
      // streamsLoadedCallback (0x80009594), que devuelve
      // [count] = 0 porque el directorio aun no se ha
      // guardado en el modelo sincrono: la carga de
      // Streams.bin se daba por fallida y el directorio
      // quedaba a 0 (Fase 14). Ahora el blr aterriza en el
      // trampolin, que restaura r3 = bytes leidos y salta
      // al retorno original con lr = retorno original: el
      // llamador reanuda EXACTAMENTE como antes salvo r3.
      // Casos borde: got == 0 (fichero vacio) restaura 0,
      // igual que antes (el wrapper lo trata como
      // pendiente); got < 0 (error HLE: sin entrada o
      // destino no escribible) restaura 0, no un -1 que
      // loadFileByPathAsync tomaria por exito.
      // El wrapper del juego (DVDRead 0x80015888) guarda r3
      // de ENTRADA al callback en su global [r13-26664] y
      // solo sale del bucle si el valor no es 0/-1/-3: por
      // eso el callback debe llevar los bytes leidos, no
      // un 0 de "exito". Los callbacks de carga
      // (initLoadFileReadCb 0x80041EC4, romListReadCb
      // 0x8004276C) cierran el fichero (DVDClose HLE) y bajan
      // su contador/flag de pendiente: sin esta entrega, la
      // carga de romlists nunca se daba por terminada.
      // Alcance verificado en codigo huesped (Fase 15): los
      // 20 puntos bl a DVDReadAsyncPrio son el wrapper
      // DVDRead (r3 ignorado tras el retorno: lee el
      // global), loadFileByPathAsync (solo r3 != 0) y 18
      // llamadores en chunk_0016/0017 que sobrescriben r3
      // (o saltan incondicionalmente) al volver; ninguno
      // compara r3 con 1 ni usa el retorno del callback.
      uint32_t fileinfo = cpu->gpr[3];
      uint32_t callback = cpu->gpr[7];
      int got = DvdRead(cpu, cpu->gpr[3], cpu->gpr[4], cpu->gpr[5],
                        cpu->gpr[6]);
      if (got == 0) {
        SFA_LOGI("hle: DVDReadAsyncPrio: 0 B (fichero vacio o "
                 "offset al final; el wrapper del juego "
                 "tratara 0 como pendiente)");
      }
      if (callback != 0) {
        cpu->exception = 0;
        ::mem_write32(cpu, fileinfo + 56u, callback);
        if (cpu->exception != 0) cpu->exception = 0;
        DvdAsyncEvent ev;
        ev.fileinfo = fileinfo;
        ev.callback = callback;
        ev.bytes = got;
        dvd_async_events_.push_back(ev);
        ++dvd_callbacks_;
        if (got > 0) dvd_async_bytes_ += static_cast<uint64_t>(got);
        // Fase 15: el callback vuelve por el trampolin, no
        // directo al llamador. Se apila el retorno original
        // y el r3 a restaurar (bytes; 0 si got <= 0, ver el
        // comentario del caso). El callback recibe r3 =
        // bytes y r4 = fileInfo exactamente como antes; su
        // propio retorno queda registrado por LogCall del
        // trampolin (r3 de entrada), no se pierde.
        DvdCallbackFrame frame;
        frame.return_pc = cpu->lr;
        frame.restore_r3 = got > 0 ? static_cast<uint32_t>(got) : 0u;
        frame.fileinfo = fileinfo;
        frame.callback = callback;
        dvd_callback_stack_.push_back(frame);
        SFA_LOGI("hle: DVDReadAsyncPrio: %d B, callback "
                 "0x%08X despachado via trampolin (fileInfo "
                 "0x%08X, retorno 0x%08X, r3 a restaurar %u)",
                 got, callback, fileinfo, frame.return_pc,
                 frame.restore_r3);
        cpu->gpr[3] = static_cast<uint32_t>(got);
        cpu->gpr[4] = fileinfo;
        cpu->pc = callback;
        cpu->lr = kDvdCallbackTrampoline;
        return true;
      }
      SFA_LOGI("hle: DVDReadAsyncPrio sincrono: %d B, callback "
               "nulo (sin despacho)",
               got);
      return Return(cpu, got >= 0 ? 1u : 0u);
    }
    case kDvdPrepareStreamAsync: {
      // Fase 16: entrega de AudioStream_PrepareCallback.
      // AudioStream_Play (0x8000D220) llama aqui con r3 = fileInfo
      // y r6 = callback (0x8000D5FC, verificado en el codigo huesped:
      // DVDPrepareStreamAsync guarda r6 en r30 y lo pasa a la cola
      // SDK, que lo escribiria en fileInfo+56). El host no modela
      // la cola SDK ni la interrupcion DI, asi que sin esta
      // intercepcion el callback nunca corre y preparing queda
      // atascado (A=340, E=1). Se entrega por el mismo trampolin
      // DVD de la Fase 15: el callback vuelve aqui, se restaura
      // r3 = 0 (exito; PrepareCallback ignora r3/r4) y se salta
      // al retorno original de Play, que es la continuacion
      // DVDStopStreamAtEndAsync. Esa continuacion sobrescribe r3
      // antes de usarlo, asi que restore_r3 es inocuo aqui.
      // Guarda contra doble entrega: si IsPreparing (byte
      // 0x803DE209) ya es 0 y preparing (0x803DE230) ya es 0, no
      // hay nada que mover; re-entregar borraria prepared
      // (B = A = 0) y StartPrepared posterior ya no arrancaria.
      // En ese caso se retorna 1 sin despachar, como el SDK.
      // Precondicion NO escrita por el parche: gameState
      // (0x803DE3FD) debe ser 1 para que PrepareCallback mueva
      // A->B; si no lo es, PrepareCallback limpiara E dejando
      // A=340, y eso es un bloqueador aguas arriba, no un fallo
      // de esta entrega (ver PORT-STATUS Fase 16).
      uint32_t fileinfo = cpu->gpr[3];
      uint32_t callback = cpu->gpr[6];
      if (callback == 0) {
        SFA_LOGI("hle: DVDPrepareStreamAsync sin callback "
                 "(fileInfo 0x%08X): retorno 1",
                 fileinfo);
        return Return(cpu, 1u);
      }
      uint32_t preparing = ::mem_read32(cpu, 0x803DE230u);
      uint32_t is_preparing = ::mem_read8(cpu, 0x803DE209u);
      if (cpu->exception != 0) cpu->exception = 0;
      if (is_preparing == 0 && preparing == 0) {
        SFA_LOGI("hle: DVDPrepareStreamAsync ya entregado "
                 "(preparing=0, IsPreparing=0): sin re-entrega "
                 "(fileInfo 0x%08X, callback 0x%08X)",
                 fileinfo, callback);
        return Return(cpu, 1u);
      }
      cpu->exception = 0;
      ::mem_write32(cpu, fileinfo + 56u, callback);
      if (cpu->exception != 0) cpu->exception = 0;
      DvdCallbackFrame frame;
      frame.return_pc = cpu->lr;
      frame.restore_r3 = 0u;
      frame.fileinfo = fileinfo;
      frame.callback = callback;
      dvd_callback_stack_.push_back(frame);
      ++dvd_prepare_callbacks_;
      SFA_LOGI("hle: DVDPrepareStreamAsync: callback 0x%08X "
               "despachado via trampolin (fileInfo 0x%08X, "
               "retorno 0x%08X)",
               callback, fileinfo, frame.return_pc);
      cpu->gpr[3] = 0u;
      cpu->gpr[4] = fileinfo;
      cpu->pc = callback;
      cpu->lr = kDvdCallbackTrampoline;
      return true;
    }
    case kDvdCallbackTrampoline: {
      // Fase 15, segundo tiempo de la entrega DVD: el blr
      // del callback aterrizo aqui (su lr era este PC
      // sintetico). Se desapila el marco LIFO (un callback
      // puede lanzar otra lectura async antes de volver),
      // se restaura r3 = bytes leidos y se salta al retorno
      // original con lr = retorno original, de modo que el
      // llamador reanuda exactamente como si el callback
      // hubiese vuelto directo, salvo r3. r4 y el resto de
      // registros quedan como los dejo el callback, igual
      // que antes. Sin marco, error interno del HLE: fallo
      // ruidoso (exception), nunca salto a 0 en silencio.
      if (dvd_callback_stack_.empty()) {
        SFA_LOGE("hle: DVDTrampoline sin marco (r3=0x%08X): "
                 "error interno, exception",
                 cpu->gpr[3]);
        cpu->exception = 1;
        return true;
      }
      DvdCallbackFrame frame = dvd_callback_stack_.back();
      dvd_callback_stack_.pop_back();
      ++dvd_trampolines_;
      cpu->gpr[3] = frame.restore_r3;
      cpu->pc = frame.return_pc;
      cpu->lr = frame.return_pc;
      return true;
    }
    case kViInit:
      vi_init_done_ = true;
      retrace_count_ = 0;
      // VIInit pone a cero el estado VI, incluidos los
      // callbacks (el huesped los guarda en estos globales).
      ::mem_write32(cpu, cpu->gpr[13] - 21016u, 0u);
      ::mem_write32(cpu, cpu->gpr[13] - 21012u, 0u);
      return Return(cpu, 0);
    case kViConfigure:
      // VIConfigure(mode*): se registra; el modo real (NTSC/
      // PAL, framebuffer) es trabajo de la fase GX, no de init.
      return Return(cpu, 0);
    case kViFlush:
      return Return(cpu, 0);
    case kViWaitForRetrace: {
      // Retrace simulado, Fase 6a: esperar al siguiente
      // retrace = avanzar el contador en 1 y volver al
      // instante (nunca bloquea: un wait real colgaria el
      // chassis). El contador tambien avanza en cada
      // OSSleepThread (un retrace por frame dormido); esta
      // llamada solo ocurre en tvInit (x2 en run20), asi que
      // ambos caminos no se duplican en el bucle.
      ++retrace_count_;
      if (DeliverViCallbacks(cpu)) return true;
      // Fase 7: tras la cadena VI (o sin ella), la IRQ AI
      // encadenada; nunca antes que VI (Fase 6, c4-c6).
      if (DeliverAiCallbacks(cpu)) return true;
      // Fase 8: el breakpoint GX, tras la IRQ AI (en
      // hardware la IRQ CP llega cuando el GP consume el
      // frame, sin orden fijo frente a la de AI).
      if (DeliverBreakPtCallback(cpu)) return true;
      return Return(cpu, 0);
    }
    case kViSetPreRetraceCallback: {
      // Codigo huesped: old = [r13-21016]; [r13-21016] = cb;
      // devuelve old. Se escribe tambien el global para que
      // cualquier lector directo vea lo mismo que el HLE.
      uint32_t global = cpu->gpr[13] - 21016u;
      uint32_t old = ::mem_read32(cpu, global);
      ::mem_write32(cpu, global, cpu->gpr[3]);
      return Return(cpu, old);
    }
    case kViSetPostRetraceCallback: {
      uint32_t global = cpu->gpr[13] - 21012u;
      uint32_t old = ::mem_read32(cpu, global);
      ::mem_write32(cpu, global, cpu->gpr[3]);
      return Return(cpu, old);
    }
    case kViCallbackTrampoline: {
      // Fase 7, segunda fase pendiente: el post-callback
      // acaba de volver al trampolin (se le despacho con lr
      // = trampolin precisamente para este encadenado); antes
      // de regresar al retorno real se entrega la IRQ AI, ya
      // con la cadena VI completa detras (diseno Fase 6 §9).
      if (vi_post_ai_pending_) {
        uint32_t ret2 = vi_post_ai_ret_;
        vi_post_ai_pending_ = false;
        vi_post_ai_ret_ = 0;
        if (DeliverAiCallbacksRet(cpu, ret2)) return true;
        // Fase 8: el breakpoint GX, tras la IRQ AI y con la
        // cadena VI completa detras (mismo punto vivo que la
        // entrega AI durante la pelicula).
        if (DeliverBreakPtCallbackRet(cpu, ret2)) return true;
        cpu->pc = ret2;
        return true;
      }
      // Segundo tiempo de la cadena VI: pre ya volvio aqui
      // (su blr aterrizo en este PC sintetico). Si hay post,
      // se despacha; si no, se vuelve al retorno original.
      uint32_t post = vi_chain_post_;
      uint32_t ret = vi_chain_ret_;
      vi_chain_post_ = 0;
      vi_chain_ret_ = 0;
      vi_chain_active_ = false;
      if (post != 0) {
        ++vi_post_delivered_;
        cpu->gpr[3] = static_cast<uint32_t>(retrace_count_);
        cpu->pc = post;
        // Fase 7: el post vuelve al trampolin (no a ret)
        // para encadenar la entrega AI tras el (ver la
        // segunda fase de arriba).
        vi_post_ai_pending_ = true;
        vi_post_ai_ret_ = ret;
        cpu->lr = kViCallbackTrampoline;
      } else {
        // Sin post: la cadena VI ya termino; la IRQ AI se
        // intenta con el mismo retorno como continuacion.
        if (DeliverAiCallbacksRet(cpu, ret)) return true;
        // Fase 8: el breakpoint GX, tras la IRQ AI.
        if (DeliverBreakPtCallbackRet(cpu, ret)) return true;
        cpu->pc = ret;
      }
      return true;
    }
    case kAiCallbackTrampoline:
      // Retorno de una entrega del callback DMA de AI de la
      // pelicula (o continuacion de su rafaga): ver
      // HandleAiTrampoline junto a DeliverAiCallbacks.
      return HandleAiTrampoline(cpu);
    case kBpCallbackTrampoline:
      // Retorno de una entrega del callback de breakpoint
      // GX (Fase 8): ver HandleBpTrampoline junto a
      // DeliverBreakPtCallback.
      return HandleBpTrampoline(cpu);
    case kPadInit:
      pad_init_done_ = true;
      return Return(cpu, 0);
    case kPadRead: {
      // Fase 6b: PADStatus real (12 B/pad, 4 pads = 48 B en
      // r3) desde el PadState vigente: externo (Input) si lo
      // hay, si no el interno (inyeccion de test o cero).
      // Pad 0 conectado (err = 0); pads 1-3 sin mando
      // (err = -1, como el SDK: padUpdate pone a cero sus
      // globales y no los usa). Retorno 0: el chequeo de
      // padUpdate (0x80014FC0) lo acepta y sigue a PADClamp.
      // Ademas se pone a 1 el flag de muestra nueva
      // (0x803DE65D, ver hle.h): padUpdate lo lee DESPUES de
      // PADRead y solo entonces usa el fresco; sin el, la
      // inyeccion de run16 se perdia (copia del slot
      // anterior, siempre a cero). Esto modela el muestreo
      // SI que en hardware pondria ese flag entre frames.
      const PadState* state =
          pad_state_ext_ != nullptr ? pad_state_ext_ : &pad_state_;
      PadState effective = *state;
      effective.SyncAnalogFromButtons();
      ++pad_reads_;
      // Pulsacion programada (Fase 8, solo con inyeccion de
      // test): antes del PADRead n, botones 0.
      if (pad_inject_ && pad_press_from_read_ != 0 &&
          pad_reads_ < pad_press_from_read_) {
        effective.buttons = 0;
      }
      // Secuencia de test (Fase 12): si hay guion, el tramo
      // vigente sustituye botones y stick (no se combina con
      // la inyeccion constante: el guion es la fuente).
      if (!pad_script_.empty()) {
        const PadScriptStep* step = nullptr;
        for (const PadScriptStep& s : pad_script_) {
          if (s.from_read <= pad_reads_) step = &s;
        }
        if (step != nullptr) {
          effective.buttons = step->buttons;
          effective.stick_x = step->stick_x;
          effective.stick_y = step->stick_y;
        }
      }
      uint8_t status[48];
      std::memset(status, 0, sizeof(status));
      status[0] = static_cast<uint8_t>(effective.buttons >> 8);
      status[1] = static_cast<uint8_t>(effective.buttons);
      status[2] = static_cast<uint8_t>(effective.stick_x);
      status[3] = static_cast<uint8_t>(effective.stick_y);
      status[4] = static_cast<uint8_t>(effective.substick_x);
      status[5] = static_cast<uint8_t>(effective.substick_y);
      status[6] = effective.trigger_l;
      status[7] = effective.trigger_r;
      status[8] = effective.analog_a;
      status[9] = effective.analog_b;
      status[10] = 0;
      for (int pad = 1; pad < 4; ++pad) {
        status[pad * 12 + 10] = 0xFF;  // err = -1: sin mando
      }
      bool ok = WriteGuestBytes(cpu, cpu->gpr[3], status, sizeof(status));
      cpu->exception = 0;
      ::mem_write8(cpu, kPadFreshFlag, 1u);
      if (cpu->exception != 0) cpu->exception = 0;
      // Diagnostico: primeras 5 escrituras con relectura.
      static int pad_logs = 0;
      if (pad_logs < 5) {
        ++pad_logs;
        uint8_t* host = nullptr;
        uint32_t back = 0;
        if (GuestRangeHostPtr(cpu, cpu->gpr[3], 4, &host)) {
          back = (static_cast<uint32_t>(host[0]) << 24) |
                 (static_cast<uint32_t>(host[1]) << 16) |
                 (static_cast<uint32_t>(host[2]) << 8) |
                 static_cast<uint32_t>(host[3]);
        }
        SFA_LOGI("hle: PADRead #%d buf=0x%08X ok=%d relectura="
                 "0x%08X botones=0x%04X stick=(%d,%d)",
                 pad_logs, cpu->gpr[3], ok ? 1 : 0, back,
                 effective.buttons, effective.stick_x,
                 effective.stick_y);
      }
      return Return(cpu, 0);
    }
    case kPadReset:
    case kPadRecalibrate:
      return Return(cpu, 0);
    case kPadControlMotor: {
      // Rumble fase A + B (ver rumble.h y rumble_jni.h): r3 = chan, r4 = command
      // (0=STOP, 1=RUMBLE, 2=STOP_HARD=STOP). Solo-en-transicion
      // via RumbleTracker: padUpdate llama cada frame y un
      // RUMBLE sostenido no debe re-disparar sink ni log por
      // frame. En fase B el sink es JniVibratorSink (chan 0
      // al Vibrator fisico; resto, solo registro). Chan/cmd
      // fuera de rango: aviso, sin estado y sin crash.
      // Retorno void en libogc: se devuelve 0 y
      // los wrappers no usan r3 tras la llamada.
      uint32_t chan = cpu->gpr[3];
      uint32_t cmd = cpu->gpr[4];
      bool want_on = false;
      if (rumble_tracker_.Apply(static_cast<int>(chan),
                                static_cast<int>(cmd), &want_on)) {
        SFA_LOGI("hle: PADControlMotor chan=%u cmd=%u (%s)",
                 chan, cmd, want_on ? "RUMBLE" : "STOP");
        if (rumble_sink_ != nullptr)
          rumble_sink_->SetRumble(static_cast<int>(chan), want_on);
      } else if (chan >= 4 || cmd > 2) {
        SFA_LOGI("hle: PADControlMotor chan=%u cmd=%u fuera de "
                 "rango: sin efecto",
                 chan, cmd);
      }
      return Return(cpu, 0);
    }
    case kGxInit:
      gx_init_done_ = true;
      SFA_LOGI("hle: GXInit HLE (Fase 5, GX por HLE): registra y "
               "devuelve; el estado GX se construye funcion a "
               "funcion, sin GPU todavia");
      return Return(cpu, 0);
    case kGxLoadTexObj: {
      // Sin GPU: registrar (texObj=r3, mapa=r4) en Calls() y
      // en TexLoads() con el offset FIFO vigente, y devolver.
      // Ver kGxLoadTexObj en hle.h.
      TexLoad load;
      load.fifo_offset = sfa_fifo_capture_count();
      load.tex_obj = cpu->gpr[3];
      load.map = cpu->gpr[4];
      tex_loads_.push_back(load);
      SFA_LOGI("hle: GXLoadTexObj HLE: texObj 0x%08X mapa %u "
               "(registrado, sin GPU)",
               cpu->gpr[3], cpu->gpr[4]);
      return Return(cpu, 0);
    }
    case kCardInit: {
      // CARDInit del SDK: en huesped solo prepara el estado
      // EXI, que el HLE CARD no usa (todas las operaciones
      // publicas estan HLEadas). No-op con retorno 0.
      card_.EnsureLoaded();
      return Return(cpu, 0);
    }
    case kCardProbeEx: {
      // (chan, &memSize, &sectorSize). Solo Slot A presente;
      // el canal 1 devuelve NOCARD como una ranura vacia.
      if (!card_enabled_) {
        SFA_LOGI("hle: CARDProbeEx chan=%d -> -3 (NOCARD, card deshabilitada, "
                 "pad_reads=%llu)",
                 static_cast<int>(cpu->gpr[3]),
                 static_cast<unsigned long long>(pad_reads_));
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      card_.EnsureLoaded();
      uint32_t mem_size = 0;
      uint32_t sector_size = 0;
      int result = card_.Probe(static_cast<int>(cpu->gpr[3]), &mem_size,
                               &sector_size);
      if (result == VirtualCard::kReady) {
        WriteGuestU32(cpu, cpu->gpr[4], mem_size);
        WriteGuestU32(cpu, cpu->gpr[5], sector_size);
      }
      SFA_LOGI("hle: CARDProbeEx chan=%d -> %d (mem=%u sector=%u, "
               "pad_reads=%llu)",
               static_cast<int>(cpu->gpr[3]), result, mem_size,
               sector_size,
               static_cast<unsigned long long>(pad_reads_));
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardMount: {
      // (chan, workArea, callback). El callback del juego
      // (cardSetStatusNoCard2 en los 3 sitios de llamada)
      // preserva r3, asi que se puede despachar en linea con
      // r3=chan y r4=resultado, como DVDReadAsyncPrio hace con
      // su callback: el callback corre como codigo huesped y
      // su blr vuelve al retorno del llamador, con r3 intacto
      // (= chan 0 = READY 0 en Slot A). Sin callback, retorno
      // directo del resultado.
      int chan = static_cast<int>(cpu->gpr[3]);
      uint32_t callback = cpu->gpr[5];
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      card_.EnsureLoaded();
      int result = card_.Mount(chan);
      SFA_LOGI("hle: CARDMount chan=%d -> %d (callback 0x%08X)",
               chan, result, callback);
      if (callback != 0) {
        cpu->gpr[3] = static_cast<uint32_t>(chan);
        cpu->gpr[4] = static_cast<uint32_t>(result);
        cpu->pc = callback;
        return true;
      }
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardUnmount: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      int result =
          card_.Unmount(static_cast<int>(cpu->gpr[3]));
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardCheck: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      int result = card_.Check(static_cast<int>(cpu->gpr[3]));
      SFA_LOGI("hle: CARDCheck chan=%d -> %d",
               static_cast<int>(cpu->gpr[3]), result);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardFormat: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      int result = card_.Format(static_cast<int>(cpu->gpr[3]));
      SFA_LOGI("hle: CARDFormat chan=%d -> %d",
               static_cast<int>(cpu->gpr[3]), result);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardOpen: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, filename, fileInfo). El fileNo (indice de
      // directorio) queda en +4 del struct y en el registro
      // de abiertos de esta instancia.
      std::string name;
      if (!ReadGuestString(cpu, cpu->gpr[4], &name)) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kIoError));
      }
      int file_no = -1;
      int result = card_.Open(static_cast<int>(cpu->gpr[3]), name,
                              &file_no);
      if (result == VirtualCard::kReady) {
        CardStatData stat;
        card_.GetStatus(static_cast<int>(cpu->gpr[3]), file_no, &stat);
        WriteCardFileInfo(cpu, cpu->gpr[5],
                          static_cast<int>(cpu->gpr[3]), file_no,
                          stat.length);
        bool found = false;
        for (auto& e : card_open_) {
          if (e.first == cpu->gpr[5]) {
            e.second = file_no;
            found = true;
          }
        }
        if (!found) card_open_.push_back({cpu->gpr[5], file_no});
      }
      SFA_LOGI("hle: CARDOpen '%s' -> %d (fileNo %d)", name.c_str(),
               result, file_no);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardClose: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (fileInfo). Se resuelve el fileNo por el registro y,
      // si no hay registro, por +4 del propio struct.
      int file_no = -1;
      for (auto& e : card_open_) {
        if (e.first == cpu->gpr[3]) file_no = e.second;
      }
      if (file_no < 0) {
        uint32_t v = 0;
        if (ReadGuestU32(cpu, cpu->gpr[3] + 4u, &v)) {
          file_no = static_cast<int>(v);
        }
      }
      for (auto it = card_open_.begin(); it != card_open_.end();) {
        if (it->first == cpu->gpr[3]) {
          it = card_open_.erase(it);
        } else {
          ++it;
        }
      }
      int result = card_.Close(file_no);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardCreate: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, filename, size, fileInfo).
      std::string name;
      if (!ReadGuestString(cpu, cpu->gpr[4], &name)) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kIoError));
      }
      int file_no = -1;
      int result = card_.Create(static_cast<int>(cpu->gpr[3]), name,
                                cpu->gpr[5], &file_no);
      if (result == VirtualCard::kReady) {
        WriteCardFileInfo(cpu, cpu->gpr[6],
                          static_cast<int>(cpu->gpr[3]), file_no,
                          cpu->gpr[5]);
        bool found = false;
        for (auto& e : card_open_) {
          if (e.first == cpu->gpr[6]) {
            e.second = file_no;
            found = true;
          }
        }
        if (!found) card_open_.push_back({cpu->gpr[6], file_no});
      }
      SFA_LOGI("hle: CARDCreate '%s' size %u -> %d (fileNo %d)",
               name.c_str(), cpu->gpr[5], result, file_no);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardRead: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (fileInfo, buf, length, offset).
      int file_no = -1;
      for (auto& e : card_open_) {
        if (e.first == cpu->gpr[3]) file_no = e.second;
      }
      if (file_no < 0) {
        uint32_t v = 0;
        if (ReadGuestU32(cpu, cpu->gpr[3] + 4u, &v)) {
          file_no = static_cast<int>(v);
        }
      }
      uint32_t length = cpu->gpr[5];
      std::vector<uint8_t> buf(length);
      int result = card_.Read(file_no, cpu->gpr[6], length,
                              length > 0 ? buf.data() : nullptr);
      if (result == VirtualCard::kReady && length > 0) {
        WriteGuestBytes(cpu, cpu->gpr[4], buf.data(), length);
      }
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardWrite: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (fileInfo, buf, length, offset). Los datos se leen
      // del guest por el puntero host cuando cabe en RAM.
      int file_no = -1;
      for (auto& e : card_open_) {
        if (e.first == cpu->gpr[3]) file_no = e.second;
      }
      if (file_no < 0) {
        uint32_t v = 0;
        if (ReadGuestU32(cpu, cpu->gpr[3] + 4u, &v)) {
          file_no = static_cast<int>(v);
        }
      }
      uint32_t length = cpu->gpr[5];
      std::vector<uint8_t> buf(length);
      uint8_t* host = nullptr;
      if (length > 0 && GuestRangeHostPtr(cpu, cpu->gpr[4], length,
                                          &host)) {
        std::memcpy(buf.data(), host, length);
      } else {
        for (uint32_t i = 0; i < length; ++i) {
          cpu->exception = 0;
          buf[i] = ::mem_read8(cpu, cpu->gpr[4] + i);
          if (cpu->exception != 0) {
            cpu->exception = 0;
            break;
          }
        }
      }
      int result = card_.Write(file_no, cpu->gpr[6],
                               length > 0 ? buf.data() : nullptr,
                               length);
      SFA_LOGI("hle: CARDWrite fileNo %d off %u len %u -> %d",
               file_no, cpu->gpr[6], length, result);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardDelete: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, filename).
      std::string name;
      if (!ReadGuestString(cpu, cpu->gpr[4], &name)) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kIoError));
      }
      int result =
          card_.Delete(static_cast<int>(cpu->gpr[3]), name);
      SFA_LOGI("hle: CARDDelete '%s' -> %d", name.c_str(), result);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardGetStatus: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, fileNo, stat).
      CardStatData stat;
      int result = card_.GetStatus(static_cast<int>(cpu->gpr[3]),
                                   static_cast<int>(cpu->gpr[4]),
                                   &stat);
      if (result == VirtualCard::kReady) {
        WriteCardStat(cpu, cpu->gpr[5], stat);
      }
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardSetStatus: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, fileNo, stat): el juego reescribe el stat que
      // GetStatus le dio, con iconAddr/comentario/banner
      // retocados (saveGame). Solo esos campos se persisten.
      CardStatData stat;
      if (!ReadCardStat(cpu, cpu->gpr[5], &stat)) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kIoError));
      }
      int result = card_.SetStatus(static_cast<int>(cpu->gpr[3]),
                                   static_cast<int>(cpu->gpr[4]),
                                   stat);
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kCardGetSerialNo: {
      if (!card_enabled_) {
        return Return(cpu,
                      static_cast<uint32_t>(VirtualCard::kNoCard));
      }
      // (chan, &serial u64 BE).
      uint64_t serial = 0;
      int result = card_.GetSerialNo(static_cast<int>(cpu->gpr[3]),
                                     &serial);
      if (result == VirtualCard::kReady) {
        uint8_t bytes[8];
        for (int i = 0; i < 8; ++i) {
          bytes[i] = static_cast<uint8_t>(serial >> (56 - 8 * i));
        }
        WriteGuestBytes(cpu, cpu->gpr[4], bytes, 8);
      }
      return Return(cpu, static_cast<uint32_t>(result));
    }
    case kOsReport: {
      // Observacion, no sustitucion de logica: el stub huesped
      // solo vuelca registros y retorna, asi que capturar el
      // texto y retornar sin tocar r3 (el stub tampoco lo
      // tocaba) conserva el comportamiento. Las lineas quedan
      // en OsReportLines() para el test; en log solo las 500
      // primeras para no inundar logcat en el bucle.
      std::string line;
      if (FormatOsReport(cpu, &line)) {
        if (osreport_lines_.size() < 500) {
          SFA_LOGI("osreport: %s", line.c_str());
        }
        if (osreport_lines_.size() < 200000) {
          osreport_lines_.push_back(line);
        }
      } else {
        SFA_LOGI("osreport: (formato 0x%08X ilegible)", cpu->gpr[3]);
      }
      cpu->pc = cpu->lr;
      return true;
    }
    case kOsSleepThread: {
      // Fase 9: el retrace solo lo avanza el hilo principal
      // (antes todos los suenos eran del principal, asi que
      // el conteo es comparable; los suenos de trabajadores
      // no son retraces). Un sueno por cola cede la CPU al
      // planificador; un sueno de frame mantiene el camino
      // anterior (entrega VI + retorno instantaneo).
      if (current_thread_ < 0) ++retrace_count_;
      if (current_thread_ >= 0) {
        ThreadEntry& cur = threads_[static_cast<size_t>(current_thread_)];
        ++cur.yields;
      }
      bool attempted =
          current_thread_ >= 0 || cpu->lr == kOsReceiveSleepRet ||
          cpu->lr == kOsSendSleepRet;
      if (SwitchOnSleep(cpu)) return true;
      // Un sueno de frame del principal no es un fallo del
      // planificador (por diseno no cambia de hilo): solo
      // cuentan los suenos por cola sin relevo.
      if (attempted && !threads_.empty()) ++scheduler_fallbacks_;
      if (current_thread_ < 0) {
        if (DeliverViCallbacks(cpu)) return true;
        // Fase 7: IRQ AI encadenada tras VI, como en
        // VIWaitForRetrace (nunca antes que VI).
        if (DeliverAiCallbacks(cpu)) return true;
        // Fase 8: el breakpoint GX, tras la IRQ AI.
        if (DeliverBreakPtCallback(cpu)) return true;
      }
      return Return(cpu, 0);
    }
    case kGxInitFifoBase:
    case kGxInitFifoPtrs:
    case kGxInitFifoLimits:
    case kGxSetCpuFifo:
    case kGxSetGpFifo:
      // Stubs GX previos al GX real: se guarda solo el log, no
      // se toca hardware ni FIFO.
      return Return(cpu, 0);
    case kPpcSync:
      // Barrera SDK (ver hle.h): no-op, retorno a lr. Sin esto,
      // el `sc` de PPCSync cae en la excepcion de llamada al
      // sistema (0xC00) y el chassis se detiene; el vector
      // 0xC00 no esta en el DOL cargado (vive bajo 0x80003100),
      // asi que no hay codigo huesped que ejecutar ahi.
      return Return(cpu, 0);
    case kLcEnable:
      // _LCEnable huesped no corre (HLE): su bucle dcbz ponia
      // la ventana LC a cero. El búfer ya esta a cero en el
      // arranque; se vuelve a poner a cero aqui para que una
      // segunda llamada tenga la misma semantica.
      // Fase 9: ademas espeja el mfhid2/oris 0x100F/mthid2
      // del huesped (0x802424A4): sin el bit LCE (0x10000000)
      // THPVideoDecode devuelve el error 28 y el hilo de
      // video se suspende sin enviar PrepareReady(1).
      std::memset(cpu->locked_cache, 0, GC_LC_SIZE);
      cpu->hid2 |= 0x100F0000u;
      return Return(cpu, 0);
    case kLcLoadBlocks: {
      // Load: RAM (r4) -> LC (r3). r5 = bloques de 32 B, 0 = 128
      // (4096 B, como el bucle de LCStoreData). El huesped
      // devuelve r3 intacto.
      uint32_t lc = cpu->gpr[3];
      uint32_t mem = cpu->gpr[4];
      uint32_t blocks = cpu->gpr[5] == 0 ? 128u : cpu->gpr[5];
      if (!LcDmaCopy(cpu, mem, lc, blocks * 32u, true)) {
        SFA_LOGE("hle: LCLoadBlocks fuera de ventana LC r3=0x%08X "
                 "r4=0x%08X bloques=%u (sin copia)",
                 lc, mem, blocks);
      }
      return Return(cpu, lc);
    }
    case kLcStoreBlocks: {
      // Store: LC (r4) -> RAM (r3). El huesped devuelve r3
      // enmascarado a 28 bits (rlwinm 0, 4, 31 en la entrada).
      uint32_t mem = cpu->gpr[3];
      uint32_t lc = cpu->gpr[4];
      uint32_t blocks = cpu->gpr[5] == 0 ? 128u : cpu->gpr[5];
      if (!LcDmaCopy(cpu, mem, lc, blocks * 32u, false)) {
        SFA_LOGE("hle: LCStoreBlocks fuera de ventana LC r3=0x%08X "
                 "r4=0x%08X bloques=%u (sin copia)",
                 mem, lc, blocks);
      }
      return Return(cpu, mem & 0x0FFFFFFFu);
    }
    case kLcStoreData: {
      // LCStoreData huesped (0x802425F0): copia bytes de RAM
      // a LC en bloques de 32 B (bucle que llama a
      // LCStoreBlocks por trozos de 4096 B) y devuelve
      // ceil(bloques/128). Sin esta entrada HLE, el bucle
      // huesped llama intra-chunk a LCStoreBlocks y choca
      // con mtdmau (sin implementar en cpu.c) -> excepcion
      // de programa en el hilo de video durante el primer
      // frame THP. Copia sincrona (el DMA real es asincrono
      // y LCQueueWait HLE ya devuelve de inmediato, asi que
      // el modelo es consistente); bytes=0 no copia y
      // devuelve 0, como el huesped.
      uint32_t mem = cpu->gpr[3];
      uint32_t lc = cpu->gpr[4];
      uint32_t bytes = cpu->gpr[5];
      uint32_t blocks = (bytes + 31u) >> 5;
      if (blocks != 0) {
        if (!LcDmaCopy(cpu, mem, lc, blocks * 32u, false)) {
          SFA_LOGE("hle: LCStoreData fuera de ventana LC r3=0x%08X "
                   "r4=0x%08X bytes=%u (sin copia)",
                   mem, lc, bytes);
        }
      }
      return Return(cpu, (blocks + 127u) >> 7);
    }
    case kLcQueueWait:
      // DMA sincrono: la cola esta vacia siempre; el huesped
      // devuelve r3+1 (addi en la entrada).
      return Return(cpu, cpu->gpr[3] + 1u);
    case kDcInvalidateRange:
    case kDcFlushRange:
    case kDcStoreRange:
    case kDcFlushRangeNoSync:
    case kDcStoreRangeNoSync:
      // No-op correctos en recompilacion: no hay cache separada
      // que vaciar; la RAM host ya contiene los datos.
      return Return(cpu, 0);
    case kDcZeroRange: {
      uint32_t addr = cpu->gpr[3];
      uint32_t size = cpu->gpr[4];
      uint8_t* host = nullptr;
      if (GuestRangeHostPtr(cpu, addr, size, &host)) {
        std::memset(host, 0, size);
      } else {
        for (uint32_t i = 0; i < size; ++i) {
          ::mem_write8(cpu, addr + i, 0);
          if (cpu->exception != 0) break;
        }
      }
      return Return(cpu, 0);
    }
    default:
      return false;
  }
}

void Hle::HandleFallback(CpuState* cpu, uint32_t raw, uint32_t cia) {
  // Cache: opcode primario 31 (0x7C000000) y XO de cache:
  //   dcbst 54, dcbf 86, dcbi 470, icbi 982.
  // En recompilacion son no-op (sin icache/dcache separadas) y
  // el bloque termina aqui por diseno del emisor C: avanzar a
  // cia+4 es la continuacion correcta, no enmascarar nada.
  uint32_t primary = raw & 0xFC000000u;
  uint32_t xo = (raw >> 1) & 0x3FFu;
  bool is_cache = primary == 0x7C000000u &&
                  (xo == 54u || xo == 86u || xo == 470u || xo == 982u);
  if (is_cache) {
    ++fallback_cache_;
    if (fallback_cache_ <= 20) {
      SFA_LOGI("hle: fallback cache no-op raw=0x%08X cia=0x%08X "
               "-> pc=0x%08X",
               raw, cia, cia + 4u);
    }
    cpu->pc = cia + 4u;
    return;
  }
  // SPR: el emisor C solo traduce directamente unos pocos SPR
  // (xer, lr, ctr, srr, tbr, gqr, ear, hid2); el resto
  // (mfhid0/mthid0, mfl2cr/mtl2cr, ...) llega aqui como
  // mfspr (XO 339) / mtspr (XO 467). OJO: el numero de SPR va
  // partido en el raw (bits 11-15 = mitad alta, bits 16-20 =
  // mitad baja): spr = ((raw>>16)&0x1F) | (((raw>>11)&0x1F)<<5).
  // Un desplazamiento ingenuo (raw>>11)&0x3FF da 501 para HID0
  // en vez de 1008 (error real corregido en este tramo).
  // CPUState no tiene hid0 ni l2cr, asi que el HLE los guarda.
  // Solo se modelan HID0 (1008), L2CR (1017) y WPAR (921):
  // cualquier otro SPR es exception registrada, no un avance
  // silencioso.
  if (primary == 0x7C000000u && (xo == 339u || xo == 467u)) {
    uint32_t spr =
        ((raw >> 16) & 0x1Fu) | (((raw >> 11) & 0x1Fu) << 5);
    uint32_t reg = (raw >> 21) & 0x1Fu;
    if (spr == 1008u || spr == 1017u || spr == 921u) {
      if (xo == 339u) {
        cpu->gpr[reg] =
            spr == 1008u ? hid0_ : (spr == 1017u ? l2cr_ : wpar_);
      } else {
        if (spr == 1008u) {
          hid0_ = cpu->gpr[reg];
        } else if (spr == 1017u) {
          l2cr_ = cpu->gpr[reg];
        } else {
          wpar_ = cpu->gpr[reg];
        }
      }
      // Los SPR son raros en la ruta: se registran siempre.
      SFA_LOGI("hle: fallback SPR %s %u r%u -> pc=0x%08X",
               xo == 339u ? "mf" : "mt", spr, reg, cia + 4u);
      cpu->pc = cia + 4u;
      return;
    }
    ++fallback_unknown_;
    SFA_LOGE("hle: fallback SPR sin modelar spr=%u xo=%u "
             "raw=0x%08X cia=0x%08X (exception, sin avanzar)",
             spr, xo, raw, cia);
    cpu->exception = 1;
    return;
  }
  // Cualquier otra instruccion sin traducir: exception real,
  // sin avanzar el PC. El chassis se detiene y la registra.
  ++fallback_unknown_;
  SFA_LOGE("hle: fallback DESCONOCIDO raw=0x%08X cia=0x%08X "
           "(exception, sin avanzar)",
           raw, cia);
  cpu->exception = 1;
}

}  // namespace sfa

extern "C" bool sfa_hle_host_call(CPUState* cpu, uint32_t address) {
  if (cpu == nullptr) return false;
  auto* hle = static_cast<sfa::Hle*>(cpu->external_user_data);
  if (hle == nullptr) return false;
  return hle->HandleHostCall(cpu, address);
}

extern "C" void sfa_hle_instruction_fallback(CPUState* cpu, uint32_t raw,
                                            uint32_t cia) {
  if (cpu == nullptr) {
    return;
  }
  auto* hle = static_cast<sfa::Hle*>(cpu->external_user_data);
  if (hle == nullptr) {
    // Sin HLE instalado, el comportamiento heredado del shim es
    // program exception; aqui se replica sin Hle para no ocultar
    // el caso: exception y PC sin avanzar.
    cpu->exception = 1;
    return;
  }
  hle->HandleFallback(cpu, raw, cia);
}
