#include "gamecube_runtime/mem.h"

// Envoltorios C++ sobre las mem_* C del shim (cpu/cpu.c). Antes
// esta era una segunda implementacion con su propia traduccion
// guest->host; ahora delega, para que el C++ y los chunks vean
// exactamente la misma memoria y la misma semantica:
//   - RAM 0x80000000-0x81800000, alias sin cache 0xC0000000 (nuevo
//     respecto a la version anterior, que no lo aceptaba) y forma
//     fisica (offset < ram_size, la que generated.h aliasa).
//   - Hardware 0xCC000000-0xCC020000: lectura 0, escritura
//     ignorada, SIN exception.
//   - Fuera de rango: lectura 0 / escritura ignorada, CON
//     exception = 1.
// Los envoltorios solo anaden la guarda de ctx nulo (las mem_* C
// ya la tienen, pero el contrato C++ anterior la garantizaba y se
// conserva para no cambiar el comportamiento de los llamadores).

#include "cpu/cpu.h"

namespace sfa {

bool IsHardwareRegister(uint32_t guest_address) {
  return guest_address >= 0xCC000000u && guest_address < 0xCC020000u;
}

uint8_t MemRead8(CpuState* ctx, uint32_t guest_address) {
  if (ctx == nullptr) return 0;
  return ::mem_read8(ctx, guest_address);
}

uint16_t MemRead16(CpuState* ctx, uint32_t guest_address) {
  if (ctx == nullptr) return 0;
  return ::mem_read16(ctx, guest_address);
}

uint32_t MemRead32(CpuState* ctx, uint32_t guest_address) {
  if (ctx == nullptr) return 0;
  return ::mem_read32(ctx, guest_address);
}

uint64_t MemRead64(CpuState* ctx, uint32_t guest_address) {
  if (ctx == nullptr) return 0;
  return ::mem_read64(ctx, guest_address);
}

void MemWrite8(CpuState* ctx, uint32_t guest_address, uint8_t value) {
  if (ctx == nullptr) return;
  ::mem_write8(ctx, guest_address, value);
}

void MemWrite16(CpuState* ctx, uint32_t guest_address, uint16_t value) {
  if (ctx == nullptr) return;
  ::mem_write16(ctx, guest_address, value);
}

void MemWrite32(CpuState* ctx, uint32_t guest_address, uint32_t value) {
  if (ctx == nullptr) return;
  ::mem_write32(ctx, guest_address, value);
}

void MemWrite64(CpuState* ctx, uint32_t guest_address, uint64_t value) {
  if (ctx == nullptr) return;
  ::mem_write64(ctx, guest_address, value);
}

}  // namespace sfa
