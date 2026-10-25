#pragma once

// Estado de CPU Gekko para el código DolRecomp.
//
// Campos verificados por grep en los 176 chunks (no inventados):
//   gpr[32] (u32), fpr[32] (f64), ps1[32] (f64, paired-single),
//   cr, xer, lr, ctr, pc (u32), gqr[8] (u32), msr, fpscr,
//   srr0, srr1, sr[16], hid2, ear, downcount (s64), exception.
// Funciones de memoria que los chunks llaman: mem_read/write
// 8/16/32/64 (big-endian, ver mem.h).
//
// NOTA DE INTEGRACIÓN: los chunks DolRecomp usan un CPUState
// global en C (cabecera "cpu/cpu.h" de generated.h). Este struct
// está en namespace sfa para la base y el cargador, sin incluir
// generated.h todavía. Cuando los chunks se enlacen en la librería,
// el shim global cpu/cpu.h deberá tener EXACTAMENTE este layout
// (mismo orden y tipos) y las mem_* deberán operar sobre él;
// hasta entonces, este struct es el contrato documentado, no una
// segunda implementación divergente.

#include <cstdint>

namespace sfa {

struct CpuState {
  uint32_t gpr[32] = {};
  double fpr[32] = {};
  double ps1[32] = {};
  uint32_t cr = 0;
  uint32_t xer = 0;
  uint32_t lr = 0;
  uint32_t ctr = 0;
  uint32_t pc = 0;
  uint32_t gqr[8] = {};
  uint32_t msr = 0;
  uint32_t fpscr = 0;
  uint32_t srr0 = 0;
  uint32_t srr1 = 0;
  uint32_t sr[16] = {};
  uint32_t hid2 = 0;
  uint32_t ear = 0;
  int64_t downcount = 0;
  int exception = 0;
  // Puntero al buffer host de la RAM guest (ver GCMemory).
  // DolRecomp lo llama ram/ram_size en generated.h; aquí se guarda
  // como referencia externa, no como copia.
  uint8_t* ram = nullptr;
  uint32_t ram_size = 0;
  void* userdata = nullptr;
};

}  // namespace sfa
