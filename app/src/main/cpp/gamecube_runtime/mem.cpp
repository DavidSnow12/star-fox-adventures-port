#include "gamecube_runtime/mem.h"

#include "log.h"

namespace sfa {

namespace {
uint8_t* HostPtr(CpuState* ctx, uint32_t guest_address, uint32_t size,
                 bool* is_hardware) {
  *is_hardware = false;
  if (ctx == nullptr || ctx->ram == nullptr) return nullptr;
  if (IsHardwareRegister(guest_address)) {
    *is_hardware = true;
    return nullptr;
  }
  // RAM guest: 0x80000000 - 0x81800000 (24 MiB). También se acepta
  // la forma física (offset < ram_size) que generated.h aliasa a
  // GC_RAM_BASE, para compatibilidad con dolrecomp_physical_pc_alias.
  uint32_t offset = 0;
  if (guest_address >= 0x80000000u &&
      guest_address < 0x80000000u + ctx->ram_size) {
    offset = guest_address - 0x80000000u;
  } else if (guest_address < ctx->ram_size) {
    offset = guest_address;
  } else {
    return nullptr;
  }
  if (offset + size > ctx->ram_size) return nullptr;
  return ctx->ram + offset;
}
}  // namespace

bool IsHardwareRegister(uint32_t guest_address) {
  return guest_address >= 0xCC000000u && guest_address < 0xCC020000u;
}

uint8_t MemRead8(CpuState* ctx, uint32_t guest_address) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 1, &hw);
  if (hw) return 0;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return 0;
  }
  return p[0];
}

uint16_t MemRead16(CpuState* ctx, uint32_t guest_address) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 2, &hw);
  if (hw) return 0;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return 0;
  }
  return (static_cast<uint16_t>(p[0]) << 8) | p[1];
}

uint32_t MemRead32(CpuState* ctx, uint32_t guest_address) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 4, &hw);
  if (hw) return 0;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return 0;
  }
  return (static_cast<uint32_t>(p[0]) << 24) |
         (static_cast<uint32_t>(p[1]) << 16) |
         (static_cast<uint32_t>(p[2]) << 8) | p[3];
}

uint64_t MemRead64(CpuState* ctx, uint32_t guest_address) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 8, &hw);
  if (hw) return 0;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return 0;
  }
  uint64_t v = 0;
  for (int i = 0; i < 8; ++i) v = (v << 8) | p[i];
  return v;
}

void MemWrite8(CpuState* ctx, uint32_t guest_address, uint8_t value) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 1, &hw);
  if (hw) return;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return;
  }
  p[0] = value;
}

void MemWrite16(CpuState* ctx, uint32_t guest_address, uint16_t value) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 2, &hw);
  if (hw) return;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return;
  }
  p[0] = static_cast<uint8_t>(value >> 8);
  p[1] = static_cast<uint8_t>(value);
}

void MemWrite32(CpuState* ctx, uint32_t guest_address, uint32_t value) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 4, &hw);
  if (hw) return;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return;
  }
  p[0] = static_cast<uint8_t>(value >> 24);
  p[1] = static_cast<uint8_t>(value >> 16);
  p[2] = static_cast<uint8_t>(value >> 8);
  p[3] = static_cast<uint8_t>(value);
}

void MemWrite64(CpuState* ctx, uint32_t guest_address, uint64_t value) {
  bool hw = false;
  uint8_t* p = HostPtr(ctx, guest_address, 8, &hw);
  if (hw) return;
  if (p == nullptr) {
    if (ctx != nullptr) ctx->exception = 1;
    return;
  }
  for (int i = 0; i < 8; ++i) {
    p[i] = static_cast<uint8_t>(value >> (56 - 8 * i));
  }
}

}  // namespace sfa
