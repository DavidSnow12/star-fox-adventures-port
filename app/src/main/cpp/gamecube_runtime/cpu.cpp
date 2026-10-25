#include "gamecube_runtime/cpu.h"

#include "log.h"

namespace sfa {

void GekkoCpu::Reset() {
  pc_ = GCMemory::kEntry;
  steps_ = 0;
  SFA_LOGI("cpu: reset, PC inicial 0x%08X (entry del DOL)", pc_);
}

void GekkoCpu::Step() {
  // STUB: sin dispatch DolRecomp todavía. Se avanza el PC nominal
  // para que el loop principal tenga un ritmo, y se registra solo
  // al principio para no inundar el log.
  if (steps_ < 5) {
    SFA_LOGI("cpu: paso %llu, PC 0x%08X (STUB, sin ejecutar juego)",
             static_cast<unsigned long long>(steps_), pc_);
  }
  pc_ += 4;
  ++steps_;
  (void)memory_;
}

}  // namespace sfa
