#include "gamecube_runtime/chassis.h"

#include "cpu/cpu.h"

#include <chrono>
#include <cstdio>
#include <cstdlib>
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
  // Informacion de arranque que en hardware escribe el IPL antes
  // de saltar al juego (Fase 5, desbloqueo AI): AIInit
  // (0x80250458) lee [0x800000F8] como reloj de bus y de ahi
  // deriva las constantes SRC que __AI_SRC_INIT valida; con la
  // RAM a cero, todas salian 0 y la validacion no pasaba nunca
  // (el bucle de medicion se repetia sin fin). GameCube real:
  // bus 162 MHz, CPU 486 MHz (3x). Se escriben big-endian en
  // RAM guest (offset = direccion - 0x80000000); el DOL empieza
  // en 0x80003100, asi que nada lo sobrescribe.
  if (ram != nullptr && ram_size > 0x100u) {
    auto put_be32 = [&ram](uint32_t off, uint32_t v) {
      ram[off] = static_cast<uint8_t>(v >> 24);
      ram[off + 1] = static_cast<uint8_t>(v >> 16);
      ram[off + 2] = static_cast<uint8_t>(v >> 8);
      ram[off + 3] = static_cast<uint8_t>(v);
    };
    put_be32(0xF8u, 162000000u);  // 0x800000F8: reloj de bus
    put_be32(0xFCu, 486000000u);  // 0x800000FC: reloj de CPU
  }
}

ChassisResult RunChassis(CpuState* cpu, Hle* hle,
                         uint64_t max_dispatches, double max_seconds,
                         uint32_t stop_pc, AudioEntryHook audio_hook,
                         void* audio_hook_user) {
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
    // Traza de entradas a funciones clave (solo host, solo con
    // SFA_PCTRACE en el entorno; apagada por defecto). Solo ve
    // despachos entre chunks: una llamada dentro del mismo chunk
    // es un goto y no aparece; las llamadas entre chunks si.
    {
      static int pctrace = -1;
      if (pctrace < 0) pctrace = std::getenv("SFA_PCTRACE") != nullptr;
      if (pctrace) {
        static const uint32_t kTracePcs[] = {
            0x80116AF4u,  // TitleMenu_run
            0x80116650u,  // n_attractmode_prepareMovie
            0x80116548u,  // n_attractmode_releaseMovieBuffers
            0x8006CB00u,  // newshadows_beginFrame
            0x8006A09Cu,  // updateHeavyFogTexture
            0x8006D7CCu,  // allocLotsOfTextures
            0x80118E10u,  // THPPlayerPlay
            0x80118D2Cu,  // THPPlayerStop
            0x8011634Cu,  // n_rareware_render
            0x801169E8u,  // TitleMenu_render
            0x80117480u,  // TitleMenu_initialise
            0x80116298u,  // TitleScreenInit_render
            0x80242548u,  // LCEnable (HLE)
            0x802425A8u,  // LCLoadBlocks (HLE)
            0x802425CCu,  // LCStoreBlocks (HLE)
            0x8024269Cu,  // LCQueueWait (HLE)
            0x80244940u,  // OSInitMessageQueue
            0x802449A0u,  // OSSendMessage
            0x80244A68u,  // OSReceiveMessage
            0x801190C8u,  // InitAllMessageQueue
            0x801383C0u,  // hilo creado en run26 (OSCreateThread)
            // Fase 11: traza de menu/UI post-Start (simbolos
            // GSAP01_rev1 PAL): TitleMenuItem_render,
            // setCurUiDll, loadUiDll, TitleMenu_setSelection.
            0x80131BF8u,  // TitleMenuItem_render
            0x80014954u,  // setCurUiDll
            0x80014974u,  // loadUiDll
            0x80117440u,  // TitleMenu_setSelection
            // Fase 12: traza CARD (juego + libreria SDK).
            0x8007E08Cu,  // cardProbe
            0x8007E42Cu,  // showMemCardError
            0x8007E190u,  // cardGetMessage
            0x8007FBA8u,  // saveGame
            0x8007DEDCu,  // loadSaveGame
            0x8007DE40u,  // maybeTryLoadSave
            0x8007DF84u,  // cardCreateSaveFile
            0x8007D910u,  // cardFormatMemoryCard
            0x8007DD08u,  // cardWriteOptions
            0x8007E8A4u,  // cardShowLoadingMsg
            0x8025F664u,  // CARDInit
            0x802624B8u,  // CARDProbeEx
            0x80262D1Cu,  // CARDMount
            0x80262B7Cu,  // CARDMountAsync
            0x80262398u,  // CARDCheck
            0x80261E08u,  // CARDCheckExAsync
            0x8026391Cu,  // CARDOpen
            0x80263A94u,  // CARDClose
            0x80263E40u,  // CARDCreate
            0x802642B8u,  // CARDRead
            0x80264634u,  // CARDWrite
            0x80264A70u,  // CARDGetStatus
            0x80264830u,  // CARDDelete
            0x80263648u,  // CARDFormat
            0x80262E00u,  // CARDUnmount
            0x80264D58u,  // CARDGetSerialNo
            // Fase 14: traza de audio (simbolos GSAP01_rev1 PAL,
            // verificados en codigo/symbols.map). Solo entradas
            // entre chunks: una llamada dentro del mismo chunk
            // es un goto y no aparece aqui (limitacion
            // documentada en PORT-STATUS, Fase 14).
            0x80009BF8u,  // audioInit
            0x80009BD0u,  // audioUpdate
            0x8000980Cu,  // audioLoadTriggerData
            0x80009A28u,  // audioSetVolumes
            0x80009B4Cu,  // audioStopAll
            0x8000D220u,  // AudioStream_Play (r3 = id de stream)
            0x8000D158u,  // AudioStream_StartPrepared
            0x8000D03Cu,  // AudioStream_StopCurrent
            0x8000CFC8u,  // AudioStream_SetVolume
            0x8000CFB8u,  // AudioStream_GetCurrentId
            0x8000D5B4u,  // AudioStream_Init
            0x80273218u,  // sndFXStartEx
            0x8027C34Cu,  // sndSeqPlayEx
            0x8027C09Cu,  // sndPushGroup
            0x80272F80u,  // sndSeqStop
            0x802732E0u,  // sndVolume
            0x80273340u,  // sndMasterVolume
            0x80119848u,  // AttractMovieAudio_Init (audio THP)
            0x800806F0u,  // ObjSeq_AudioStreamCallback
        };
        for (uint32_t t : kTracePcs) {
          if (pc == t) {
            // r3-r7: argumentos de la llamada (Fase 14: el id
            // de sonido/stream viaja en r3 en AudioStream_Play
            // y en los snd*; sin ellos la traza no sirve para
            // mapear). Los campos van al final para no romper
            // el parseo existente por "pc=0x...".
            std::fprintf(stderr,
                         "PCTRACE desp=%llu pc=0x%08X lr=0x%08X "
                         "fifo=%llu r3=0x%08X r4=0x%08X "
                         "r5=0x%08X r6=0x%08X r7=0x%08X\n",
                         static_cast<unsigned long long>(result.dispatches),
                         pc, cpu->lr,
                         static_cast<unsigned long long>(
                             sfa_fifo_capture_count()),
                         cpu->gpr[3], cpu->gpr[4], cpu->gpr[5],
                         cpu->gpr[6], cpu->gpr[7]);
            break;
          }
        }
      }
    }
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
    // Hook de audio (Fase 14): solo en entradas de funcion
    // conocidas, antes del despacho, sin sustituirlo. La
    // lista es la de funciones con hook en audio_bridge.h;
    // aqui solo se filtra por PC (las demas entradas no
    // llegan al hook, ni siquiera a contar).
    if (audio_hook != nullptr &&
        (pc == 0x8000D220u ||  // AudioStream_Play
         pc == 0x8000D03Cu ||  // AudioStream_StopCurrent
         pc == 0x8000D158u ||  // AudioStream_StartPrepared
         pc == 0x80273218u ||  // sndFXStartEx
         pc == 0x8027C34Cu)) {  // sndSeqPlayEx
      audio_hook(pc, cpu->gpr[3], cpu->gpr[4], cpu->gpr[5],
                 cpu->gpr[6], cpu->gpr[7], audio_hook_user);
    }
    if (cpu->downcount < 0) cpu->downcount = 0;
    // Timebase simulado (Fase 5, desbloqueo AI): +200 por
    // despacho, NO +10000 ni +100. __AI_SRC_INIT mide los ticks
    // entre dos cambios del contador AI (periodo 1266 ticks a
    // 32 kHz) y solo acepta delta < 1144 o 1384 <= delta < 1566
    // (constantes SRC de AIInit: 1264/120/1686). Cada espera se
    // sincroniza al siguiente cambio de contador, asi que el
    // delta medido queda clavado cerca del periodo, cuantizado
    // a la rejilla del incremento: con +10000 era multiplo de
    // 10000 (siempre fuera); con +100 era siempre 1200/1300
    // (medido en pchist: 1160x1200 + 2253x1300, 0 fuera de ahi,
    // siempre en el hueco (1144, 1384)); con +200 el delta
    // alcanzable es 1200 o 1400 segun la fase, y 1400 SI esta
    // en la ventana, asi que la calibracion termina en pocos
    // intentos (la fase deriva entre intentos). El valor sigue
    // siendo simulado, sin pretension de precision de ciclo.
    cpu->timebase += 200;
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
