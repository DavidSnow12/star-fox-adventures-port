#pragma once

// HLE minimo del port Android (Fases 2-3): sustituye funciones del
// SDK de GameCube por implementaciones host, interceptadas en el
// punto que DolRecomp ya preve: CPUState::host_call, consultado
// por dolrecomp_call() ANTES de ejecutar el chunk original. Una
// funcion HLE, al terminar, pone ctx->pc = ctx->lr (la direccion
// de retorno que el bl del llamador dejo en lr; tambien correcta
// para una llamada por cola con b, porque lr sigue siendo el
// retorno del llamador logico) y devuelve true: el chassis sigue
// despachando desde esa direccion de retorno. Una direccion que
// no esta en la tabla devuelve false y el chunk original se
// ejecuta de verdad: eso es deliberado, no un fallo silencioso.
//
// Tabla = solo la ruta real observada (boot + init) mas las
// funciones que la Fase 3 nombra. NO se registran los 9.591
// simbolos de generated_symbols.h de golpe.
//
//   Boot: __OSPSInit, __OSCacheInit, DBInit, OSInit, __init_user.
//   Init (orden de init 0x80020F8C): OSInit, DVDInit, VIInit,
//     PADInit, LCEnable; luego videoInit -> GXInit (stub).
//   Soporte en esa ruta: VIConfigure, VIFlush, VIWaitForRetrace
//     (retrace simulado: incrementa un contador y vuelve; NUNCA
//     espera), PADRecalibrate, PADReset, PADRead (estado a 0),
//     DC* (no-op salvo DCZeroRange, que pone a cero de verdad),
//     OSGetArenaLo/Hi, OSInitAlloc, hilos/alarmas como no-op
//     con log, GXInitFifo* / GXSet*Fifo como stubs con log.
//   DVD (datos del arbol ya extraido, nunca de un DVD fisico):
//     DVDInit, DVDOpen, DVDReadPrio, DVDReadAsyncPrio (sincrono
//     en esta fase; el callback async queda pendiente),
//     DVDClose. DVDOpen NO escribe aun los campos del struct
//     DVDFileInfo (su layout exacto esta pendiente de verificar
//     contra el uso del juego en initLoadFiles): guarda la
//     entrada en una tabla HLE indexada por la direccion guest
//     del fileInfo, y DVDRead la resuelve por esa direccion.
//
// Log: cada llamada HLE queda en Calls() (nombre, direccion
// guest, retorno, r3-r6 de entrada). En logcat/boot.log solo
// se imprimen las 20 primeras por nombre, para no inundar el
// log en el bucle del juego; el contador total no se corta.

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

#include "gamecube_runtime/cpu_state.h"

namespace sfa {

struct HleCall {
  const char* name = nullptr;
  uint32_t address = 0;
  uint32_t return_address = 0;
  uint32_t r3 = 0;
  uint32_t r4 = 0;
  uint32_t r5 = 0;
  uint32_t r6 = 0;
};

class Hle {
 public:
  // Direcciones guest verificadas en generated_symbols.h /
  // symbols.map (no punteros host).
  static constexpr uint32_t kOsInit = 0x80240EA4u;
  static constexpr uint32_t kOsPsInit = 0x80241628u;
  static constexpr uint32_t kOsCacheInit = 0x802428ACu;
  static constexpr uint32_t kInitUser = 0x80247680u;
  static constexpr uint32_t kDbInit = 0x80247714u;
  static constexpr uint32_t kDvdInit = 0x80249BA0u;
  static constexpr uint32_t kDvdOpen = 0x80249548u;
  static constexpr uint32_t kDvdClose = 0x80249610u;
  static constexpr uint32_t kDvdReadAsyncPrio = 0x80249858u;
  static constexpr uint32_t kDvdReadPrio = 0x80249948u;
  static constexpr uint32_t kViInit = 0x8024CE24u;
  static constexpr uint32_t kViWaitForRetrace = 0x8024D29Cu;
  static constexpr uint32_t kViConfigure = 0x8024D764u;
  static constexpr uint32_t kViFlush = 0x8024DF00u;
  static constexpr uint32_t kPadInit = 0x8024EFC4u;
  static constexpr uint32_t kPadRead = 0x8024F1D4u;
  static constexpr uint32_t kPadReset = 0x8024EDC0u;
  static constexpr uint32_t kPadRecalibrate = 0x8024EEC0u;
  static constexpr uint32_t kGxInit = 0x802556DCu;
  static constexpr uint32_t kLcEnable = 0x80242548u;
  static constexpr uint32_t kDcInvalidateRange = 0x802422F8u;
  static constexpr uint32_t kDcFlushRange = 0x80242328u;
  static constexpr uint32_t kDcStoreRange = 0x8024235Cu;
  static constexpr uint32_t kDcFlushRangeNoSync = 0x80242390u;
  static constexpr uint32_t kDcStoreRangeNoSync = 0x802423C0u;
  static constexpr uint32_t kDcZeroRange = 0x802423F0u;
  static constexpr uint32_t kOsGetArenaHi = 0x80242030u;
  static constexpr uint32_t kOsGetArenaLo = 0x80242038u;
  static constexpr uint32_t kOsInitAlloc = 0x80241F54u;
  static constexpr uint32_t kOsAllocFromHeap = 0x80241DCCu;
  static constexpr uint32_t kOsFreeToHeap = 0x80241EC8u;
  static constexpr uint32_t kOsInitAlarm = 0x80241674u;
  static constexpr uint32_t kOsSetAlarm = 0x8024191Cu;
  static constexpr uint32_t kOsCancelAlarm = 0x80241984u;
  static constexpr uint32_t kOsInitThreadQueue = 0x80246724u;
  static constexpr uint32_t kOsDisableScheduler = 0x80246740u;
  static constexpr uint32_t kOsEnableScheduler = 0x80246780u;
  static constexpr uint32_t kOsCreateThread = 0x80246C54u;
  static constexpr uint32_t kOsResumeThread = 0x80247014u;
  static constexpr uint32_t kOsInitContext = 0x80242DD8u;
  static constexpr uint32_t kOsInitMessageQueue = 0x80244940u;
  static constexpr uint32_t kGxInitFifoBase = 0x80256868u;
  static constexpr uint32_t kGxInitFifoPtrs = 0x802568D4u;
  static constexpr uint32_t kGxInitFifoLimits = 0x80256944u;
  static constexpr uint32_t kGxSetCpuFifo = 0x80256950u;
  static constexpr uint32_t kGxSetGpFifo = 0x80256A60u;

  Hle();
  ~Hle();

  // Raiz del arbol del disco ya extraido (p. ej. disc/files/).
  // Sin raiz, DVDOpen falla de forma explicita (log + retorno 0).
  void SetDiscRoot(const char* root);
  const std::string& DiscRoot() const { return disc_root_; }

  // Instala host_call + instruction_fallback en cpu, con esta
  // instancia en cpu->external_user_data para los callbacks C.
  void Install(CpuState* cpu);

  // Entrada del host_call de DolRecomp. true = HLE ejecutado.
  bool HandleHostCall(CpuState* cpu, uint32_t address);
  // Fallback de instrucciones no traducidas. El emisor C de
  // DolRecomp termina el bloque tras un fallback y espera que
  // el runtime avance el PC: por eso los casos modelados
  // (cache y SPR HID0/L2CR, ver hle.cpp) ponen pc = cia+4.
  // Cualquier otro caso marca exception sin avanzar: el
  // chassis se detiene y la registra, no se enmascara.
  void HandleFallback(CpuState* cpu, uint32_t raw, uint32_t cia);

  // DVD, usables tambien directamente desde tests host.
  // DvdOpen: 1 = abierto, 0 = fallo. DvdRead: bytes leidos, -1
  // si el fileInfo no tiene entrada HLE abierta.
  int DvdOpen(CpuState* cpu, uint32_t filename_guest,
              uint32_t fileinfo_guest);
  int DvdRead(CpuState* cpu, uint32_t fileinfo_guest,
              uint32_t dest_guest, uint32_t length, uint32_t offset);
  bool DvdClose(CpuState* cpu, uint32_t fileinfo_guest);

  const std::vector<HleCall>& Calls() const { return calls_; }
  uint64_t CallCountFor(const char* name) const;
  uint64_t RetraceCount() const { return retrace_count_; }
  uint64_t FallbackCacheCount() const { return fallback_cache_; }
  uint64_t FallbackUnknownCount() const { return fallback_unknown_; }
  bool OsInitDone() const { return os_init_done_; }
  bool DvdInitDone() const { return dvd_init_done_; }
  bool ViInitDone() const { return vi_init_done_; }
  bool PadInitDone() const { return pad_init_done_; }
  bool GxInitDone() const { return gx_init_done_; }
  uint32_t ArenaLo() const { return arena_lo_; }
  uint32_t ArenaHi() const { return arena_hi_; }

 private:
  struct DvdEntry {
    uint32_t fileinfo = 0;
    std::FILE* file = nullptr;
    long size = 0;
    std::string host_path;
  };
  struct ThreadEntry {
    uint32_t thread_guest = 0;
    bool runnable = false;
  };

  void LogCall(CpuState* cpu, const char* name, uint32_t address);
  bool Return(CpuState* cpu, uint32_t value);
  DvdEntry* FindDvd(uint32_t fileinfo_guest);
  static bool ReadGuestString(CpuState* cpu, uint32_t guest,
                              std::string* out);
  static bool WriteGuestBytes(CpuState* cpu, uint32_t dest,
                              const uint8_t* data, uint32_t size);

  std::string disc_root_;
  std::vector<HleCall> calls_;
  // Contador por nombre para el tope de log (20 por nombre), sin
  // recorrer calls_ en cada llamada (seria O(n^2) en bucles).
  // Indice = posicion en kHleTable de hle.cpp (maximo 64).
  uint64_t log_count_[64] = {};
  std::vector<DvdEntry> dvd_;
  std::vector<ThreadEntry> threads_;
  uint64_t retrace_count_ = 0;
  uint64_t fallback_cache_ = 0;
  uint64_t fallback_unknown_ = 0;
  bool os_init_done_ = false;
  bool dvd_init_done_ = false;
  bool vi_init_done_ = false;
  bool pad_init_done_ = false;
  bool gx_init_done_ = false;
  // Arena HLE provisional (ver PORT-STATUS): por encima de la
  // pila (0x803F9E58) y del BSS (fin 0x803E4458), dentro de RAM
  // (fin 0x81800000). videoInit la consultara via OSGetArena*.
  uint32_t arena_lo_ = 0x80400000u;
  uint32_t arena_hi_ = 0x81700000u;
  // Bump allocator del heap HLE (ver hle.cpp): un solo heap
  // global dentro de la arena. heap_next_ arranca en
  // arena_lo_ y OSInitAlloc lo reinicia.
  uint32_t heap_next_ = 0x80400000u;
  // SPR que CPUState no modela y el emisor C deja en fallback:
  // HID0 (1008) y L2CR (1017). El HLE los guarda aqui; su valor
  // inicial es 0 (provisional: el codigo observado solo hace
  // OR de bits sobre lo leido, no comprueba bits previos).
  uint32_t hid0_ = 0;
  uint32_t l2cr_ = 0;
};

}  // namespace sfa

// Callbacks C para CPUState::host_call / instruction_fallback.
// Recuperan la instancia desde cpu->external_user_data (puesta
// por Hle::Install); sin instancia devuelven false (sin HLE, el
// chunk original corre) o marcan exception en el fallback.
extern "C" bool sfa_hle_host_call(CPUState* cpu, uint32_t address);
extern "C" void sfa_hle_instruction_fallback(CPUState* cpu, uint32_t raw,
                                            uint32_t cia);
