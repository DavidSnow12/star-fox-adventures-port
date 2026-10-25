#include "gamecube_runtime/chassis.h"

#include <chrono>
#include <cstring>

// generated.h es C puro (sin guardas extern "C" propias): desde
// C++ debe incluirse en un bloque extern "C" para que las
// func_* queden sin mangling, igual que en los chunks C. Sin
// esto el enlace falla con func_* sin resolver (error real de
// este tramo en el test host; el build NDK no lo veia porque
// ningun .cpp incluia generated.h antes de chassis.cpp).
extern "C" {
#include "generated.h"
}
#include "log.h"

namespace sfa {

void InitCpuForBoot(CpuState* cpu, uint8_t* ram, uint32_t ram_size,
                    uint32_t entry) {
  if (cpu == nullptr) return;
  std::memset(cpu, 0, sizeof(*cpu));
  cpu->ram = ram;
  cpu->ram_size = ram_size;
  cpu->pc = entry;
  cpu->msr = 0;
  cpu->timebase = 0;
  cpu->downcount = 0;
}

ChassisResult RunChassis(CpuState* cpu, Hle* hle,
                         uint64_t max_dispatches, double max_seconds,
                         uint32_t stop_pc) {
  ChassisResult result;
  if (cpu == nullptr) {
    result.reason = ChassisResult::kUnknownPc;
    result.reason_text = "cpu_nulo";
    return result;
  }
  (void)hle;  // El HLE actua via cpu->host_call, no aqui.
  auto start = std::chrono::steady_clock::now();
  while (true) {
    if (cpu->exception != 0) {
      result.reason = ChassisResult::kException;
      result.reason_text = "exception";
      result.exception_value = cpu->exception;
      result.exception_pc = cpu->pc;
      result.exception_dar = cpu->dar;
      break;
    }
    uint32_t pc = cpu->pc;
    result.last_pc = pc;
    if (pc == kBootMainAddress && !result.reached_main) {
      result.reached_main = true;
      SFA_LOGI("chassis: hito main 0x%08X (despachos %llu)", pc,
               static_cast<unsigned long long>(result.dispatches));
    }
    // init NO se detecta solo por pc == 0x80020F8C: main llama a
    // init con bl dentro del MISMO chunk (chunk_0007), y eso se
    // emite como goto, no como despacho al chassis. Lo observable
    // desde el chassis son las direcciones de retorno dentro de
    // init (p. ej. 0x80020FB8 tras OSInit, 0x80020FBC tras
    // DVDInit): cualquier despacho con pc en [init, main) es
    // codigo de init en ejecucion. El log de HLE lo confirma
    // independientemente (retornos 0x80020FB8/BC/C0/C4/C8).
    if (pc >= kBootInitAddress && pc < kBootMainAddress &&
        !result.reached_init) {
      result.reached_init = true;
      SFA_LOGI("chassis: hito init (pc 0x%08X dentro de init, "
               "despachos %llu)",
               pc, static_cast<unsigned long long>(result.dispatches));
    }
    if (stop_pc != 0 && pc == stop_pc) {
      result.reason = ChassisResult::kReachedStopPc;
      result.reason_text = "reached_stop_pc";
      result.reached_stop_pc = true;
      SFA_LOGI("chassis: hito parada 0x%08X (despachos %llu)", pc,
               static_cast<unsigned long long>(result.dispatches));
      break;
    }
    if (pc == kBootExitAddress) {
      result.reason = ChassisResult::kReachedExit;
      result.reason_text = "reached_exit";
      SFA_LOGI("chassis: main retorno a exit 0x%08X (despachos %llu)",
               pc, static_cast<unsigned long long>(result.dispatches));
      break;
    }
    if (result.dispatches >= max_dispatches) {
      result.reason = ChassisResult::kDispatchCap;
      result.reason_text = "dispatch_cap";
      break;
    }
    if ((result.dispatches & 1023u) == 0 && max_seconds > 0.0) {
      double elapsed =
          std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                        start)
              .count();
      if (elapsed > max_seconds) {
        result.reason = ChassisResult::kTimeCap;
        result.reason_text = "time_cap";
        result.elapsed_seconds = elapsed;
        break;
      }
    }
    if (cpu->downcount < 0) cpu->downcount = 0;
    cpu->timebase += 10000;
    int ok = dolrecomp_call(cpu, pc);
    ++result.dispatches;
    if (!ok) {
      result.reason = ChassisResult::kUnknownPc;
      result.reason_text = "unknown_pc";
      result.unknown_pc = pc;
      SFA_LOGE("chassis: PC sin funcion 0x%08X (despachos %llu)", pc,
               static_cast<unsigned long long>(result.dispatches));
      break;
    }
    if (cpu->exception != 0) {
      result.reason = ChassisResult::kException;
      result.reason_text = "exception";
      result.exception_value = cpu->exception;
      result.exception_pc = cpu->pc;
      result.exception_dar = cpu->dar;
      SFA_LOGE("chassis: exception 0x%08X en PC 0x%08X (despachos "
               "%llu)",
               result.exception_value, result.exception_pc,
               static_cast<unsigned long long>(result.dispatches));
      break;
    }
  }
  result.elapsed_seconds =
      std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                    start)
          .count();
  return result;
}

}  // namespace sfa
