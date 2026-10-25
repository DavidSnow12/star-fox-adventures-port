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

uint8_t GCMemory::Read8(uint32_t address) const {
  if (!IsValid(address)) return 0;
  return ram_[address - kRamBase];
}

uint16_t GCMemory::Read16(uint32_t address) const {
  if (!IsValid(address) || address + 2 > kRamBase + kRamSize) return 0;
  const uint32_t o = address - kRamBase;
  return (static_cast<uint16_t>(ram_[o]) << 8) | ram_[o + 1];
}

uint64_t GCMemory::Read64(uint32_t address) const {
  if (!IsValid(address) || address + 8 > kRamBase + kRamSize) return 0;
  const uint32_t o = address - kRamBase;
  uint64_t v = 0;
  for (int i = 0; i < 8; ++i) v = (v << 8) | ram_[o + i];
  return v;
}

void GCMemory::Write8(uint32_t address, uint8_t value) {
  if (!IsValid(address)) return;
  ram_[address - kRamBase] = value;
}

void GCMemory::Write16(uint32_t address, uint16_t value) {
  if (!IsValid(address) || address + 2 > kRamBase + kRamSize) return;
  const uint32_t o = address - kRamBase;
  ram_[o] = static_cast<uint8_t>(value >> 8);
  ram_[o + 1] = static_cast<uint8_t>(value);
}

void GCMemory::Write64(uint32_t address, uint64_t value) {
  if (!IsValid(address) || address + 8 > kRamBase + kRamSize) return;
  const uint32_t o = address - kRamBase;
  for (int i = 0; i < 8; ++i) {
    ram_[o + i] = static_cast<uint8_t>(value >> (56 - 8 * i));
  }
}

bool GCMemory::WriteBytes(uint32_t address, const uint8_t* data,
                          uint32_t size) {
  if (data == nullptr) return false;
  if (!IsValid(address) || address + size > kRamBase + kRamSize) {
    return false;
  }
  const uint32_t o = address - kRamBase;
  for (uint32_t i = 0; i < size; ++i) ram_[o + i] = data[i];
  return true;
}

bool GCMemory::ZeroBss() {
  if (!IsValid(kBssBase) || kBssBase + kBssSize > kRamBase + kRamSize) {
    return false;
  }
  const uint32_t o = kBssBase - kRamBase;
  for (uint32_t i = 0; i < kBssSize; ++i) ram_[o + i] = 0;
  return true;
}

void GCMemory::MarkCodeModified(uint32_t address, uint32_t size) {
  // SMC: 107 rangos documentados en generated_smc.txt (FASE2.md).
  // Aquí solo se registra el evento; invalidar y re-traducir el
  // código afectado corresponde al runtime completo.
  SFA_LOGI("memory: SMC en 0x%08X, %u bytes (registrado, sin retraducir)",
           address, size);
}

}  // namespace sfa
