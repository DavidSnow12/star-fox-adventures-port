#pragma once

// Estado de CPU Gekko para el codigo DolRecomp.
//
// DEFINICION UNICA: el tipo real vive en cpu/cpu.h (C, layout
// canonico DolRecomp). Este fichero es solo un alias en el
// namespace sfa, para que el C++ (mem.*, cargador, runtime) y los
// chunks C operen sobre el MISMO struct, sin una segunda definicion
// que pueda divergir en orden o tipos.
//
// Campos que usan los chunks (verificado por grep en los 176):
//   gpr[32] (u32), fpr[32] (f64), ps1[32] (f64, paired-single),
//   pc, lr, ctr, cr, xer, fpscr, msr, srr0, srr1, dar, dsisr, ear,
//   hid2, timebase, sr[16], gqr[8], exception, program_exception,
//   downcount (s64), host_call (puntero PPCHostCall, no bool: asi
//   lo consulta generated.h en dolrecomp_call()), ram, ram_size.
// La version anterior de este fichero tenia otro orden, exception
// como int y host_call como bool, ademas de un campo userdata que
// nadie usaba; eso ya no existe. Cualquier codigo que dependiera
// de ese orden o de esos tipos debe actualizarse, no convivir
// con el shim.
//
// La RAM guest NO vive aqui: el runtime la reserva (GCMemory) y
// apunta ram/ram_size a ella antes de llamar a los chunks. El
// cargador DOL y los tests host no cambian de comportamiento por
// este alias: solo cambia donde esta definido el tipo.

#include "cpu/cpu.h"

namespace sfa {

using CpuState = ::CPUState;
using PpcHostCall = ::PPCHostCall;

}  // namespace sfa
