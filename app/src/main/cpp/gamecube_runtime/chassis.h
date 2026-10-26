#pragma once

// Chassis de ejecucion (Fase 2): el bucle que conecta el runtime
// con el codigo DolRecomp. NO es dolrecomp_run_blocks() tal cual:
// ese bucle no distingue hitos ni motivos de parada, y esta fase
// necesita exactamente eso (llegar a main, a init y a videoInit,
// y detenerse con causa si hay exception o PC desconocido).
//
// Mecanica (verificada contra codigo/generated/generated.h):
//   - Cada iteracion despacha dolrecomp_call(cpu, cpu->pc). Ese
//     call consulta primero host_call (HLE) y luego el chunk
//     original; un bl entre chunks deja pc=destino y vuelve al
//     chassis, asi que el siguiente despacho es la funcion
//     llamada (o el HLE, si la direccion esta en la tabla).
//   - downcount se repone a 0 antes de cada despacho: los bucles
//     de los chunks ceden al chassis al agotar el presupuesto
//     (256 ciclos) con pc=principio del bucle, y el chassis los
//     re-despacha con presupuesto nuevo. Sin reposicion,
//     downcount decreceria sin limite y un bucle de espera
//     generaria despachos eternos sin control.
//   - timebase avanza de forma simulada (+200 por despacho, sin
//     pretension de precision de ciclo): los mftb del juego ven
//     pasar el tiempo en vez de un contador congelado. El valor
//     importa: +10000 y +100 hacian inalcanzable la ventana de
//     __AI_SRC_INIT (ver chassis.cpp); +200 la hace alcanzable.
//   - Paradas limpias, nunca silenciosas: exception (con su PC y
//     valor), PC sin funcion (dolrecomp_call devuelve 0),
//     tope de despachos, tope de tiempo, llegada al PC de parada
//     (videoInit, ANTES de despacharlo) o llegada a exit
//     (0x8028DE18, main ha retornado).
//
// El chassis no enmascara nada: si una exception aparece, se
// detiene y se registra; el llamador decide que hacer con ella.

#include <cstdint>

#include "gamecube_runtime/cpu_state.h"
#include "gamecube_runtime/hle.h"

namespace sfa {

struct ChassisResult {
  enum Reason {
    kReachedStopPc,
    kReachedExit,
    kException,
    kUnknownPc,
    kDispatchCap,
    kTimeCap,
  };
  Reason reason = kDispatchCap;
  const char* reason_text = "dispatch_cap";
  bool reached_main = false;
  bool reached_init = false;
  bool reached_stop_pc = false;
  uint64_t dispatches = 0;
  uint32_t exception_value = 0;
  uint32_t exception_pc = 0;
  // DAR en el momento de la exception (direccion efectiva del
  // acceso mem_* fuera de rango, o DAR de la DSI real). 0 si
  // la exception no vino de un acceso a memoria.
  uint32_t exception_dar = 0;
  uint32_t unknown_pc = 0;
  uint32_t last_pc = 0;
  double elapsed_seconds = 0.0;
};

// Hitos de la ruta de arranque (direcciones guest verificadas).
// init se detecta por rango [init, main): main lo llama con bl
// dentro del mismo chunk (goto, no despacho), asi que la entrada
// exacta a init nunca llega al chassis; lo que si llega son sus
// direcciones de retorno (0x80020FB8 tras OSInit, etc.).
constexpr uint32_t kBootMainAddress = 0x800214A4u;      // main
constexpr uint32_t kBootInitAddress = 0x80020F8Cu;      // init
constexpr uint32_t kBootVideoInitAddress = 0x80049D84u; // videoInit
constexpr uint32_t kBootExitAddress = 0x8028DE18u;      // exit

// Estado inicial de arranque: todo a cero salvo ram/ram_size/pc.
// msr=0: __init_hardware pone el bit FP con mtmsr; r1/r2/r13 los
// pone __init_registers. El HLE se instala DESPUES (Hle::Install).
void InitCpuForBoot(CpuState* cpu, uint8_t* ram, uint32_t ram_size,
                    uint32_t entry);

// Hook de entrada a funciones de audio (Fase 14): si no es
// nulo, se llama ANTES de despachar cada entrada de funcion
// de audio conocida (AudioStream_Play, AudioStream_
// StopCurrent, AudioStream_StartPrepared, sndFXStartEx,
// sndSeqPlayEx, sndSeqStop desde Tramo 6), con pc y r3/r4/r5
// del juego. El hook NO
// sustituye al codigo huesped: el despacho sigue despues,
// intacto. Con hook nulo el coste es cero (una comparacion
// de puntero por despacho). El runtime lo usa para el bridge
// ID -> WAV (audio_bridge.h); el test host, para el mismo
// bridge. Sin hook, el juego corre exactamente igual que
// antes (las fases 2-13 no lo pasaban).
// Fase 16: el hook lleva r3-r7 (antes solo r3-r5). sndFXStartEx
// necesita r6 (indice de tabla, ver audio_id_map / informe Fase 16)
// y sndSeqPlayEx reenvia r7/r8; sin r6/r7 el hook nacia cojo.
// Los llamadores antiguos que pasaban solo r3-r5 se actualizan
// en chassis.cpp y runtime.cpp; el bridge ignora r6/r7 hasta que
// la tabla FX este resuelta, pero ya no se pierden.
using AudioEntryHook = void (*)(uint32_t pc, uint32_t r3,
                                uint32_t r4, uint32_t r5,
                                uint32_t r6, uint32_t r7,
                                void* user);

// Bucle principal. stop_pc=0 desactiva la parada por hito (el
// bucle solo para por exception, PC desconocido o topes).
// max_seconds=0 desactiva el tope de tiempo (no recomendado).
ChassisResult RunChassis(CpuState* cpu, Hle* hle,
                         uint64_t max_dispatches, double max_seconds,
                         uint32_t stop_pc,
                         AudioEntryHook audio_hook = nullptr,
                         void* audio_hook_user = nullptr);

}  // namespace sfa
