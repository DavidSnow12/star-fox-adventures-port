#include "gamecube_runtime/hle.h"

#include <cstring>

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
    {Hle::kViInit, "VIInit"},
    {Hle::kViWaitForRetrace, "VIWaitForRetrace"},
    {Hle::kViConfigure, "VIConfigure"},
    {Hle::kViFlush, "VIFlush"},
    {Hle::kPadInit, "PADInit"},
    {Hle::kPadRead, "PADRead"},
    {Hle::kPadReset, "PADReset"},
    {Hle::kPadRecalibrate, "PADRecalibrate"},
    {Hle::kGxInit, "GXInit"},
    {Hle::kLcEnable, "LCEnable"},
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

void Hle::SetPadInject(bool enabled, uint16_t buttons, int8_t stick_x,
                       int8_t stick_y) {
  pad_inject_ = enabled;
  pad_inject_buttons_ = buttons;
  pad_inject_stick_x_ = stick_x;
  pad_inject_stick_y_ = stick_y;
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
  if (calls_.size() < 1000000) calls_.push_back(call);
  // Log en texto solo las 20 primeras por nombre. El indice es
  // la posicion en kHleTable (mismo puntero de literal).
  unsigned idx = 63;
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
  SFA_LOGI("hle: DVDOpen '%s' -> '%s' (%ld B, fileInfo guest 0x%08X)",
           name.c_str(), used.c_str(), size, fileinfo_guest);
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

bool Hle::HandleHostCall(CpuState* cpu, uint32_t address) {
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
  } else if (address == kAramInitSpinHead && pending_arq_completions_ != 0) {
    uint32_t count_addr = cpu->gpr[30];
    uint32_t count = ::mem_read8(cpu, count_addr);
    if (cpu->exception == 0) {
      uint32_t applied =
          pending_arq_completions_ < count ? pending_arq_completions_ : count;
      ::mem_write8(cpu, count_addr, (uint8_t)(count - applied));
      pending_arq_completions_ -= applied;
      SFA_LOGI("hle: ARQ drenado en aramInit (contador "
               "0x%08X: %u -> %u, pendientes restantes %u)",
               count_addr, count, count - applied,
               pending_arq_completions_);
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
    case kOsInitThreadQueue:
    case kOsDisableScheduler:
    case kOsEnableScheduler:
    case kOsInitContext:
    case kOsInitMessageQueue:
      return Return(cpu, 0);
    case kOsCreateThread: {
      ThreadEntry t;
      t.thread_guest = cpu->gpr[3];
      t.runnable = false;
      threads_.push_back(t);
      SFA_LOGI("hle: OSCreateThread registrado (guest 0x%08X, "
               "sin ejecucion real: chassis monohilo)",
               t.thread_guest);
      return Return(cpu, 1);
    }
    case kOsResumeThread: {
      for (ThreadEntry& t : threads_) {
        if (t.thread_guest == cpu->gpr[3]) t.runnable = true;
      }
      return Return(cpu, 1);
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
      // Sincrono en esta fase: se lee ahora y se devuelve 1.
      // El callback (r7) NO se invoca todavia: pendiente para
      // cuando una ruta async real lo exija (ver PORT-STATUS).
      int got = DvdRead(cpu, cpu->gpr[3], cpu->gpr[4], cpu->gpr[5],
                        cpu->gpr[6]);
      SFA_LOGI("hle: DVDReadAsyncPrio sincrono: %d B, callback "
               "0x%08X no invocado (pendiente)",
               got, cpu->gpr[7]);
      return Return(cpu, got >= 0 ? 1u : 0u);
    }
    case kViInit:
      vi_init_done_ = true;
      retrace_count_ = 0;
      return Return(cpu, 0);
    case kViConfigure:
      // VIConfigure(mode*): se registra; el modo real (NTSC/
      // PAL, framebuffer) es trabajo de la fase GX, no de init.
      return Return(cpu, 0);
    case kViFlush:
      return Return(cpu, 0);
    case kViWaitForRetrace: {
      // Retrace simulado: un tick por llamada, vuelta inmediata.
      // NUNCA espera: un bucle de espera real aqui colgaria el
      // chassis, y el juego en bucle espera retrace leyendo el
      // contador, no bloqueando el hilo.
      ++retrace_count_;
      return Return(cpu, 0);
    }
    case kPadInit:
      pad_init_done_ = true;
      return Return(cpu, 0);
    case kPadRead: {
      // Sin inyeccion: comportamiento anterior (retorno 0 sin
      // escribir; la RAM del buffer ya es cero tras el BSS, asi
      // que padUpdate lee el estado neutro).
      // Con inyeccion (solo test host Fase 5b): se escribe el
      // PADStatus SDK (12 B/pad, 4 pads = 48 B en r3) del pad 0
      // — button u16 BE en +0, stickX/stickY s8 en +2/+3,
      // sub-stick/gatillos/analogicos a 0, err en +10 a 0 — y
      // los pads 1-3 a cero. padUpdate (huesped) lee ese buffer
      // y calcula Held/JustPressed desde ahi; el layout se
      // verifica en el test comparando los globales
      // 0x8033B210-0x8033B240 tras la inyeccion.
      if (pad_inject_) {
        uint8_t status[48];
        std::memset(status, 0, sizeof(status));
        status[0] = static_cast<uint8_t>(pad_inject_buttons_ >> 8);
        status[1] = static_cast<uint8_t>(pad_inject_buttons_);
        status[2] = static_cast<uint8_t>(pad_inject_stick_x_);
        status[3] = static_cast<uint8_t>(pad_inject_stick_y_);
        status[10] = 0;
        bool ok = WriteGuestBytes(cpu, cpu->gpr[3], status, sizeof(status));
        // Diagnostico Fase 5b: confirmar que la escritura llega
        // (primeras 5 inyecciones) y relectura inmediata.
        static int inject_logs = 0;
        if (inject_logs < 5) {
          ++inject_logs;
          uint8_t* host = nullptr;
          uint32_t back = 0;
          if (GuestRangeHostPtr(cpu, cpu->gpr[3], 4, &host)) {
            back = (static_cast<uint32_t>(host[0]) << 24) |
                   (static_cast<uint32_t>(host[1]) << 16) |
                   (static_cast<uint32_t>(host[2]) << 8) |
                   static_cast<uint32_t>(host[3]);
          }
          SFA_LOGI("hle: PADRead inject #%d buf=0x%08X ok=%d "
                   "relectura=0x%08X",
                   inject_logs, cpu->gpr[3], ok ? 1 : 0, back);
        }
      }
      return Return(cpu, 0);
    }
    case kPadReset:
    case kPadRecalibrate:
      return Return(cpu, 0);
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
    case kOsSleepThread:
      // Sueno instantaneo (ver kOsSleepThread en hle.h).
      // Diagnostico Fase 5b (solo con inyeccion PAD activa):
      // ademas de la inyeccion por PADRead, se pokear los
      // globales Held (0x8033B220) y JustPressed (0x8033B240)
      // del pad 0 con Start, una vez por frame. Si ni asi el
      // juego avanza, la pantalla no esta leyendo estos
      // globales (o no esta esperando input): es el
      // discriminador, no un mapeo de input.
      if (pad_inject_) {
        ::mem_write32(cpu, 0x8033B220u,
                      static_cast<uint32_t>(pad_inject_buttons_));
        ::mem_write32(cpu, 0x8033B240u,
                      static_cast<uint32_t>(pad_inject_buttons_));
      }
      return Return(cpu, 0);
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
      return Return(cpu, 0);
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
  // Solo se modelan HID0 (1008) y L2CR (1017): cualquier otro
  // SPR es exception registrada, no un avance silencioso.
  if (primary == 0x7C000000u && (xo == 339u || xo == 467u)) {
    uint32_t spr =
        ((raw >> 16) & 0x1Fu) | (((raw >> 11) & 0x1Fu) << 5);
    uint32_t reg = (raw >> 21) & 0x1Fu;
    if (spr == 1008u || spr == 1017u) {
      if (xo == 339u) {
        cpu->gpr[reg] = spr == 1008u ? hid0_ : l2cr_;
      } else {
        if (spr == 1008u) {
          hid0_ = cpu->gpr[reg];
        } else {
          l2cr_ = cpu->gpr[reg];
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
