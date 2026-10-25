#pragma once

// Acceso a memoria guest para el código DolRecomp (big-endian).
//
// Traducción guest -> host: una dirección guest 0x80000000+offset
// se traduce a ram_host[offset]. Nunca se accede a la dirección
// guest como puntero host. Rangos fuera de RAM (p. ej. registros
// 0xCC00xxxx) NO se leen/escriben como RAM: se registran y
// devuelven 0 / se ignoran, hasta que exista el HLE de ese
// registro. Un acceso fuera de rango marca exception en el estado.

#include <cstdint>

#include "gamecube_runtime/cpu_state.h"

namespace sfa {

// Rangos de registros de hardware (lectura devuelve 0 en la base).
// 0xCC000000-0xCC020000: cubre CC00 (171 lis en chunks) y CC01
// (202 lis); el rango anterior solo llegaba a 0xCC010000 y dejaba
// la página CC01 fuera, cayendo en exception (corrección del
// análisis GX/HLE).
bool IsHardwareRegister(uint32_t guest_address);

// Lecturas big-endian. Devuelven 0 fuera de rango (con exception).
uint8_t MemRead8(CpuState* ctx, uint32_t guest_address);
uint16_t MemRead16(CpuState* ctx, uint32_t guest_address);
uint32_t MemRead32(CpuState* ctx, uint32_t guest_address);
uint64_t MemRead64(CpuState* ctx, uint32_t guest_address);

// Escrituras big-endian. Ignoran fuera de rango (con exception).
void MemWrite8(CpuState* ctx, uint32_t guest_address, uint8_t value);
void MemWrite16(CpuState* ctx, uint32_t guest_address, uint16_t value);
void MemWrite32(CpuState* ctx, uint32_t guest_address, uint32_t value);
void MemWrite64(CpuState* ctx, uint32_t guest_address, uint64_t value);

}  // namespace sfa
