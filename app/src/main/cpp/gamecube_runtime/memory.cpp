#include "gamecube_runtime/memory.h"

#include "log.h"

namespace sfa {

GCMemory::GCMemory() = default;

bool GCMemory::Init() {
  ram_.assign(kRamSize, 0);
  SFA_LOGI("memory: RAM reservada, %u bytes en 0x%08X", kRamSize, kRamBase);
  SFA_LOGI("memory: BSS en 0x%08X, %u bytes (dentro de RAM, a cero)",
           kBssBase, kBssSize);
  return true;
}

bool GCMemory::LoadDol(const char* /*path*/) {
  // STUB deliberado: no hay cargador todavía. No inventar una carga
  // parcial: el cargador debe colocar cada sección text/data del DOL
  // en su dirección, poner el BSS a cero y dejar el PC en la entry.
  SFA_LOGE("memory: LoadDol no implementado todavia (siguiente bloque)");
  return false;
}

uint32_t GCMemory::Read32(uint32_t address) const {
  if (!IsValid(address) || address + 4 > kRamBase + kRamSize) return 0;
  const uint32_t offset = address - kRamBase;
  // GameCube es big-endian; la RAM se guarda en orden big-endian.
  return (static_cast<uint32_t>(ram_[offset]) << 24) |
         (static_cast<uint32_t>(ram_[offset + 1]) << 16) |
         (static_cast<uint32_t>(ram_[offset + 2]) << 8) |
         static_cast<uint32_t>(ram_[offset + 3]);
}

void GCMemory::Write32(uint32_t address, uint32_t value) {
  if (!IsValid(address) || address + 4 > kRamBase + kRamSize) return;
  const uint32_t offset = address - kRamBase;
  ram_[offset] = static_cast<uint8_t>(value >> 24);
  ram_[offset + 1] = static_cast<uint8_t>(value >> 16);
  ram_[offset + 2] = static_cast<uint8_t>(value >> 8);
  ram_[offset + 3] = static_cast<uint8_t>(value);
}

void GCMemory::MarkCodeModified(uint32_t address, uint32_t size) {
  // SMC: 107 rangos documentados en generated_smc.txt (FASE2.md).
  // Aquí solo se registra el evento; invalidar y re-traducir el
  // código afectado corresponde al runtime completo.
  SFA_LOGI("memory: SMC en 0x%08X, %u bytes (registrado, sin retraducir)",
           address, size);
}

}  // namespace sfa
