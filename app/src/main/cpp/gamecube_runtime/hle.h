#pragma once

// HLE minimo del port Android (Fases 2-3): sustituye funciones del
// SDK de GameCube por implementaciones host, interceptadas en el
// punto que DolRecomp ya preve: CPUState::host_call, consultado
// por dolrecomp_call() ANTES de ejecutar el chunk original. Una
// funcion HLE, al terminar, pone ctx->pc = ctx->lr (la direccion
// de retorno que el bl del llamador dejo en lr; tambien correcta
// para una llamada por cola con b, porque lr sigue siendo el
// retorno del llamador logico) y devuelve true: el chassis sigue
// despachando desde esa direccion de retorno. Una direccion que
// no esta en la tabla devuelve false y el chunk original se
// ejecuta de verdad: eso es deliberado, no un fallo silencioso.
//
// Tabla = solo la ruta real observada (boot + init) mas las
// funciones que la Fase 3 nombra. NO se registran los 9.591
// simbolos de generated_symbols.h de golpe.
//
//   Boot: __OSPSInit, __OSCacheInit, DBInit, OSInit, __init_user.
//   Init (orden de init 0x80020F8C): OSInit, DVDInit, VIInit,
//     PADInit, LCEnable; luego videoInit -> GXInit (stub).
//   Soporte en esa ruta: VIConfigure, VIFlush, VIWaitForRetrace
//     (retrace simulado: incrementa un contador y vuelve; NUNCA
//     espera), PADRecalibrate, PADReset, PADRead (PADStatus
//     real desde PadState, Fase 6b), DC* (no-op salvo
//     DCZeroRange, que pone a cero de verdad),
//     OSGetArenaLo/Hi, OSInitAlloc, hilos/alarmas como no-op
//     con log, GXInitFifo* / GXSet*Fifo como stubs con log.
//   Fase 5b: OSReport (captura de texto, el stub huesped no
//     imprime en retail) y PADRead con inyeccion opcional solo
//     para diagnostico host (SetPadInject).
//   DVD (datos del arbol ya extraido, nunca de un DVD fisico):
//     DVDInit, DVDOpen, DVDReadPrio, DVDReadAsyncPrio,
//     DVDClose. Fase 6a: DVDOpen escribe el DVDFileInfo real
//     (+12=0, +48 offset FST, +52 longitud, +56=0) y
//     DVDReadAsyncPrio lee en sincrono y DESPACHA el callback
//     del juego (r3 = bytes, r4 = fileInfo) antes de volver
//     al llamador, como haria la interrupcion DI en hardware.
//     DVDRead se resuelve por la direccion guest del fileInfo
//     en la tabla HLE, como antes.
//   DSP (Fase 5): DSPAddTask corre como codigo huesped; el HLE
//     solo entrega el evento de init de la tarea (el callback
//     que el DSP real dispararia por interrupcion) al llegar
//     al bucle de espera de salInitDsp. Ver HandleHostCall.
//
// Log: cada llamada HLE queda en Calls() (nombre, direccion
// guest, retorno, r3-r6 de entrada). En logcat/boot.log solo
// se imprimen las 20 primeras por nombre, para no inundar el
// log en el bucle del juego; el contador total no se corta.

#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include "gamecube_runtime/card.h"
#include "gamecube_runtime/cpu_state.h"
#include "gamecube_runtime/rumble.h"
#include "input/pad_state.h"

namespace sfa {

// Layout DVDFileInfo del SDK de este DOL, verificado contra el
// propio codigo SDK (no contra un manual externo):
//   DVDOpen 0x80249548 escribe: +48 = entrada FST +4 (offset en
//     disco), +52 = entrada FST +8 (longitud), +56 = 0,
//     +12 = 0.
//   DVDReadAsyncPrio 0x80249858 lee +52 (longitud, para validar
//     offset+longitud), guarda el callback (r7) en +56 y llama
//     a DVDReadAbsAsyncPrio con la direccion de disco
//     +48+offset.
//   cbForReadAsync 0x80249918 invoca el puntero en +56
//     (si != 0) con r3 = resultado y r4 = fileInfo.
// El juego tambien lee +52 directamente: loadFileByPathAsync
// 0x80015A38 (lwz r29,52(r30)) reserva segun esa longitud, y
// el cargador de romlists 0x800485E4 hace lo mismo. Sin +52,
// ambos reservaban 0 y los 82 reads async de run20 eran de 0 B.
// El offset +48 sale de fst.bin (sys/) cuando esta disponible;
// sin FST se escribe 0 (el HLE no lo usa: lee por offset de
// fichero host, no por direccion de disco) y +52 es siempre el
// tamano real del fichero host, que coincide con la longitud
// FST cuando hay FST (verificado en los 4 ficheros de prueba).
//
// Layout PADStatus (12 B/pad, libogc, verificado contra
// padUpdate 0x80014F6C: botones lhz en +0, sub-stick Y lbz en
// +5, err lbz en +10; PADClamp 0x8024E458 solo ajusta sticks):
//   +0 button u16 BE, +2 stickX s8, +3 stickY s8,
//   +4 substickX s8, +5 substickY s8, +6 triggerL u8,
//   +7 triggerR u8, +8 analogA u8, +9 analogB u8, +10 err s8,
//   +11 (reservado, 0).
// padUpdate ademas lee un flag de "muestra nueva" en
// [r13-25827] (absoluto 0x803DE65D, r13 = 0x803E4B40 fijado por
// __init_registers): si es 0, descarta el PADRead fresco y
// copia el slot anterior (por eso la inyeccion Start de run16
// no dejaba Held = 0x1000); si es != 0, usa el fresco y lo
// pone a 0 al final. El unico escritor observado en el DOL,
// ademas del propio padUpdate (que lo limpia), es
// gpuErrorHandler 0x80049810 (lo pone a 1). En hardware real
// ese flag lo pondria el muestreo SI entre frames; aqui lo
// pone PADRead (HLE) justo antes de que padUpdate lo lea,
// que es el mismo punto logico: muestra nueva disponible.

struct HleCall {
  const char* name = nullptr;
  uint32_t address = 0;
  uint32_t return_address = 0;
  uint32_t r3 = 0;
  uint32_t r4 = 0;
  uint32_t r5 = 0;
  uint32_t r6 = 0;
  uint32_t r7 = 0;
};

class Hle {
 public:
  // Direcciones guest verificadas en generated_symbols.h /
  // symbols.map (no punteros host).
  static constexpr uint32_t kOsInit = 0x80240EA4u;
  static constexpr uint32_t kOsPsInit = 0x80241628u;
  static constexpr uint32_t kOsCacheInit = 0x802428ACu;
  static constexpr uint32_t kInitUser = 0x80247680u;
  static constexpr uint32_t kDbInit = 0x80247714u;
  static constexpr uint32_t kDvdInit = 0x80249BA0u;
  static constexpr uint32_t kDvdOpen = 0x80249548u;
  static constexpr uint32_t kDvdClose = 0x80249610u;
  static constexpr uint32_t kDvdReadAsyncPrio = 0x80249858u;
  static constexpr uint32_t kDvdReadPrio = 0x80249948u;
  // Fase 16: DVDPrepareStreamAsync (SDK de streams). AudioStream_Play
  // NO usa DVDReadAsyncPrio: llama a DVDPrepareStreamAsync con
  // r3 = fileInfo y r6 = AudioStream_PrepareCallback (0x8000D5FC),
  // que el SDK guarda en fileInfo+56 y entregaria por interrupcion
  // DI tras DVDLowAudioStream. Como el host no modela DI, esa
  // entrega nunca llegaba y preparing quedaba en 340 para siempre.
  // El HLE intercepta esta funcion y entrega el callback por el
  // trampolin DVD existente (ver hle.cpp). Entrega sincrona
  // inmediata, no interrupcion diferida: documentada como tal.
  static constexpr uint32_t kDvdPrepareStreamAsync = 0x80249A84u;
  // Trampolin de callbacks DVD (Fase 15): PC sintetico, mismo
  // patron que el trampolin VI (0x80003000) y la salida de
  // hilo (0x80003004). NUNCA es codigo real (el DOL empieza
  // en 0x80003100); dolrecomp_call consulta host_call antes
  // que los chunks, asi que el HLE lo intercepta siempre.
  // Problema que resuelve (ver hle.cpp, kDvdReadAsyncPrio):
  // en hardware real DVDReadAsyncPrio devuelve 1 (cola OK)
  // al instante y el callback corre despues, en interrupcion
  // (su retorno se descarta); en el HLE sincrono el callback
  // corre ANTES de volver al llamador y su blr entrega el
  // retorno del callback como si fuera el de
  // DVDReadAsyncPrio. loadFileByPathAsync (0x80015AA4)
  // comprueba r3 != 0 para exito, asi que un callback que
  // devuelve 0 (streamsLoadedCallback: [count] = 0 porque
  // el directorio aun no se ha guardado) hacia fallar la
  // carga aunque la lectura fuese correcta. El trampolin
  // es el lr del callback: cuando el callback hace blr,
  // aterriza aqui, el HLE restaura r3 = bytes leidos y
  // salta al retorno original con lr = retorno original.
  // Invariante: al reanudar el llamador, TODO esta como si
  // el callback hubiese vuelto directamente, SALVO r3.
  // Alcance: solo DVDReadAsyncPrio con callback != 0; el
  // camino sincrono (callback nulo), DVDReadPrio, los
  // callbacks VI y los drenajes ARQ no lo usan. La pila
  // (no un solo slot) cubre un callback que a su vez lance
  // otra lectura async antes de volver.
  static constexpr uint32_t kDvdCallbackTrampoline = 0x80003008u;
  static constexpr uint32_t kViInit = 0x8024CE24u;
  static constexpr uint32_t kViWaitForRetrace = 0x8024D29Cu;
  static constexpr uint32_t kViConfigure = 0x8024D764u;
  static constexpr uint32_t kViFlush = 0x8024DF00u;
  // Callbacks VI (Fase 8): el juego los registra (tvInit y
  // prepareAttractMode) y el SDK los guarda en [r13-21016]
  // (pre) y [r13-21012] (post), con retorno del anterior.
  // Como el chassis no tiene interrupciones, la entrega se
  // hace en cada retrace simulado (VIWaitForRetrace y
  // OSSleepThread, los mismos puntos que ya incrementan
  // retrace_count_): pre y luego post, encadenados por un
  // PC sintetico (abajo) porque el blr de pre debe aterrizar
  // en post y el de post en el retorno original, y poner
  // post como lr de pre entraria en bucle (post se
  // devolveria a si mismo). Los callbacks reciben el
  // contador de retrace en r3 (convencion VIRetraceCallback).
  static constexpr uint32_t kViSetPreRetraceCallback = 0x8024CB14u;
  static constexpr uint32_t kViSetPostRetraceCallback = 0x8024CB58u;
  // PC sintetico del trampolin VI: NUNCA es codigo real (el
  // DOL empieza en 0x80003100). dolrecomp_call consulta
  // host_call antes que los chunks, asi que el HLE lo
  // intercepta siempre; si el HLE no estuviera instalado, el
  // chassis se detendria con unknown_pc (fallo ruidoso, no
  // corrupcion silenciosa).
  static constexpr uint32_t kViCallbackTrampoline = 0x80003000u;
  static constexpr uint32_t kPadInit = 0x8024EFC4u;
  static constexpr uint32_t kPadRead = 0x8024F1D4u;
  static constexpr uint32_t kPadReset = 0x8024EDC0u;
  static constexpr uint32_t kPadRecalibrate = 0x8024EEC0u;
  // Rumble fase A (ver gamecube_runtime/rumble.h): PADControlMotor
  // 0x8024F580, llamado desde stopRumble2 0x80014A54, stopRumble
  // 0x80014A90, doRumble 0x80014ACC, padUpdate 0x80014F6C e
  // initControllers 0x800154D8. Sin esta entrada, el juego
  // ejecutaria el PADControlMotor recompilado del SDK contra
  // registros SI no modelados (comportamiento no definido, no
  // un no-op limpio). El HLE es no-op + log con estado por
  // canal y solo-en-transicion; la vibracion real (fase B,
  // Vibrator por JNI) queda pendiente y se inyecta por
  // SetRumbleSink sin tocar el HLE.
  static constexpr uint32_t kPadControlMotor = 0x8024F580u;
  static constexpr uint32_t kGxInit = 0x802556DCu;
  static constexpr uint32_t kLcEnable = 0x80242548u;
  // DMA de la caché bloqueada (Fase 8, bloqueador nº 1): el
  // juego solo llama a estas dos funciones del SDK desde
  // copyToCache (Load) y memcpyToCache / LCStoreData (Store).
  // Su codigo huesped programa la DMA con mtdmau/mtdmal, que
  // el HLE no modela (fallback = exception); como el DMA LC
  // es sincrono en este modelo (igual que los drenajes ARQ),
  // se HLEa la copia directa. Convencion verificada en el
  // codigo huesped (ver HandleHostCall): Load copia de RAM
  // (r4) a LC (r3); Store, de LC (r4) a RAM (r3); r5 = bloques
  // de 32 B, con 0 = 128 bloques (4096 B, como el bucle de
  // LCStoreData). LCQueueWait se HLEa como retorno inmediato
  // (DMA sincrono => cola vacia), devolviendo r3+1 como el
  // codigo huesped (addi r3, r3, 1 en la entrada).
  static constexpr uint32_t kLcLoadBlocks = 0x802425A8u;
  static constexpr uint32_t kLcStoreBlocks = 0x802425CCu;
  static constexpr uint32_t kLcStoreData = 0x802425F0u;
  static constexpr uint32_t kLcQueueWait = 0x8024269Cu;
  // DSP (Fase 5, evento de tarea): DSPAddTask NO esta en la
  // tabla HLE (su codigo huesped corre de verdad: lista de
  // tareas + handshake de arranque por buzones, ya modelado en
  // cpu.c); solo se usa su entrada para recordar la tarea
  // pendiente. La entrega del callback de init se hace en el
  // bucle de espera de salInitDsp (ver HandleHostCall).
  static constexpr uint32_t kDspAddTask = 0x802519CCu;
  static constexpr uint32_t kDspInitCallback = 0x80285084u;
  static constexpr uint32_t kSalInitDspSpinHead = 0x802852DCu;
  // ARQ (Fase 5, drenaje ARAM): ARQPostRequest tampoco esta en
  // la tabla (su codigo huesped corre: programa el DMA ARAM);
  // solo se cuenta la peticion pendiente. La entrega se hace
  // en el bucle de espera de aramInit (ver HandleHostCall).
  static constexpr uint32_t kArqPostRequest = 0x802516D4u;
  static constexpr uint32_t kAramInitSpinHead = 0x80284D58u;
  // ARQ (Fase 6a): segundo punto de espera. aramUploadData
  // 0x802849A8 espera a que el contador de su cola
  // [r31+641] baje de 16 (0x802849EC: lbz contador; si >= 16,
  // 0x80284B5C duerme y vuelve a 0x802849E8). El drenaje de
  // aramInit no cubre este punto: tras los callbacks DVD de
  // audio (Fase 6a), las subidas de muestras se atascaban
  // aqui con el contador en 16 y sin drenaje (run21). El
  // contador se drena igual que en aramInit (pendientes SDK
  // aplicados, con clamp al contador). LIMITACION heredada:
  // los callbacks por peticion de la cola del juego
  // (aramQueueCallback 0x80284910: +32 callback, +36 arg)
  // no se invocan en el drenaje; si el juego espera uno,
  // el siguiente atasco lo dira con su PC y su flag, y se
  // implementara la entrega con la cola (base r31, indice
  // en [r31+640]) en vez de solo el contador.
  static constexpr uint32_t kAramUploadWaitHead = 0x802849ECu;
  // ARQ (Fase 6a, segundo drenaje): aramSyncTransferQueue
  // 0x80284B7C gira (lbz contador en 0x80284B84, base fija
  // 0x803D58C0 en r3) hasta que el contador [r3+641] sea 0.
  // La ultima subida de una serie no tiene un wait-head
  // posterior que la drene: el llamador postea y espera en
  // sync, y el contador queda en 1 con 0 pendientes SDK
  // (run23: 50M despachos, mismo estado que run22, contador
  // 0x803D5B41 = 1, indice 3, slots con callback +32 = 0).
  // En este punto se completa una DMA por cesion del chunk
  // (contador -1; si hay pendientes SDK, tambien -1): con
  // cola maxima 16, el sync termina en pocas cesiones. Los
  // slots observados tienen +32 = 0, asi que no se pierde
  // ningun callback del juego en este drenaje.
  static constexpr uint32_t kAramSyncWaitHead = 0x80284B84u;
  // ARQ (Fase 6a, tercer drenaje: callbacks por peticion).
  // AudioAramWriteSync 0x80008F38 postea una escritura ARAM
  // con ARQPostRequest (0x802516D4, codigo huesped: la
  // peticion es un struct del juego en 0x803372A0+slot*48,
  // +28 = callback, +0 = siguiente de la lista enlazada
  // de la cola 1, head/tail en [r13-20816]/[r13-20812]) y
  // luego gira en 0x80008FDC (lwz flag [r13-27076]; cmpwi
  // 0; bc si ==0) hasta que el callback de escritura
  // (AudioAramWriteCompleteCallback 0x80009008: stw 1 en el
  // flag; blr) lo ponga a 1. Sin interrupcion ARQ, ese
  // callback nunca corre (run25b: 50M despachos, PC final
  // 0x80008FDC, flag 0, cola 1 con un elemento: slot 0 con
  // +28 = 0x80009008, src 0x8054C700, dst ARAM 0x00EC93E0,
  // len 1272864). En este punto se entrega el callback de
  // la cabeza de la cola 1 como codigo huesped (lr = el
  // propio spin head, para que el blr del callback vuelva
  // al giro, relea el flag ya a 1 y salga por el epilogo
  // normal de la funcion, con sus registros restaurados)
  // y se desenlaza la peticion antes de despachar, para
  // no re-entregarla en la siguiente escritura. r3 = la
  // peticion, por convencion de callback ARQ. Si el flag
  // ya es 1 o la cola esta vacia, no se hace nada (el
  // giro sale solo o el siguiente atasco dira por que).
  static constexpr uint32_t kAudioAramWriteSyncWaitHead = 0x80008FDCu;
  static constexpr uint32_t kAudioAramWriteCompleteCb = 0x80009008u;
  static constexpr uint32_t kDcInvalidateRange = 0x802422F8u;
  static constexpr uint32_t kDcFlushRange = 0x80242328u;
  static constexpr uint32_t kDcStoreRange = 0x8024235Cu;
  static constexpr uint32_t kDcFlushRangeNoSync = 0x80242390u;
  static constexpr uint32_t kDcStoreRangeNoSync = 0x802423C0u;
  static constexpr uint32_t kDcZeroRange = 0x802423F0u;
  static constexpr uint32_t kOsGetArenaHi = 0x80242030u;
  static constexpr uint32_t kOsGetArenaLo = 0x80242038u;
  static constexpr uint32_t kOsInitAlloc = 0x80241F54u;
  static constexpr uint32_t kOsAllocFromHeap = 0x80241DCCu;
  static constexpr uint32_t kOsFreeToHeap = 0x80241EC8u;
  static constexpr uint32_t kOsInitAlarm = 0x80241674u;
  static constexpr uint32_t kOsSetAlarm = 0x8024191Cu;
  static constexpr uint32_t kOsCancelAlarm = 0x80241984u;
  static constexpr uint32_t kOsInitThreadQueue = 0x80246724u;
  static constexpr uint32_t kOsDisableScheduler = 0x80246740u;
  static constexpr uint32_t kOsEnableScheduler = 0x80246780u;
  static constexpr uint32_t kOsCreateThread = 0x80246C54u;
  static constexpr uint32_t kOsResumeThread = 0x80247014u;
  static constexpr uint32_t kOsSuspendThread = 0x8024729Cu;
  static constexpr uint32_t kOsInitContext = 0x80242DD8u;
  static constexpr uint32_t kOsInitMessageQueue = 0x80244940u;
  static constexpr uint32_t kOsSendMessage = 0x802449A0u;
  static constexpr uint32_t kOsReceiveMessage = 0x80244A68u;
  // Retornos de OSSleepThread dentro del SDK (ver codigo
  // huesped): Receive duerme en 0x80244ABC (lr 0x80244AC0,
  // cabeza del bucle) y Send en 0x802449F4 (lr 0x802449F8).
  // El planificador (Fase 9) los usa para distinguir un
  // sueno por cola (ceder la CPU) de un sueno de frame.
  static constexpr uint32_t kOsReceiveSleepRet = 0x80244AC0u;
  static constexpr uint32_t kOsSendSleepRet = 0x802449F8u;
  // PC sintetico de salida de hilo (Fase 9): lr inicial de
  // todo hilo creado, vecino del trampolin VI (0x80003000).
  // Nunca es codigo real (el DOL empieza en 0x80003100); si
  // una funcion de hilo retorna, aterriza aqui, el HLE la
  // marca terminada y cambia al siguiente hilo listo.
  static constexpr uint32_t kThreadExitTrampoline = 0x80003004u;
  // OSSleepThread (Fase 5, bucle de juego): el chassis es
  // monohilo y no entrega interrupciones (VI retrace, DVD,
  // ARQ...), asi que un hilo dormido no lo despertaria nadie:
  // waitNextFrame (0x8004AA4C) duerme el hilo principal
  // esperando el siguiente retrace y SelectThread gira sin
  // fin con la mascara de listos a 0 (run13). HLE: el sueno
  // termina al instante (igual que VIWaitForRetrace, que ya
  // era "retrace simulado, nunca espera").
  // FASE 9 — planificador cooperativo (ver ThreadEntry y
  // SwitchOnSleep en hle.cpp): un sueno por cola (lr en
  // Receive/Send) ya NO retorna al instante: guarda el
  // contexto del hilo actual y despacha el siguiente hilo
  // listo (main primero si su cola ya tiene mensaje, si no
  // round-robin entre hilos reanudados). Un sueno de frame
  // (waitNextFrame, lr en codigo del juego) mantiene el
  // comportamiento anterior (entrega VI + retorno): el
  // planificado por frame queda como siguiente paso
  // documentado, no como hecho. El SelectThread huesped
  // nunca corre: todo cambio de contexto es host, y los
  // campos del struct OSThread que el HLE escribe son un
  // espejo best-effort (ver OSCreateThread en hle.cpp),
  // no el estado autoritativo (ese vive en ThreadEntry).
  static constexpr uint32_t kOsSleepThread = 0x8024740Cu;
  static constexpr uint32_t kGxInitFifoBase = 0x80256868u;
  static constexpr uint32_t kGxInitFifoPtrs = 0x802568D4u;
  static constexpr uint32_t kGxInitFifoLimits = 0x80256944u;
  static constexpr uint32_t kGxSetCpuFifo = 0x80256950u;
  static constexpr uint32_t kGxSetGpFifo = 0x80256A60u;
  // GXLoadTexObj (Fase 5, GX por HLE): el huesped llama a un
  // puntero del estado GX en [estado+1040] que el GXInit HLE
  // (stub) nunca inicializo, y saltaba a 0 (run12). En vez de
  // adivinar ese puntero, GXLoadTexObj se HLEa entero: en
  // esta fase sin GPU, "cargar" una textura es registrar
  // (texObj, mapa) en el log de llamadas HLE (Calls() guarda
  // r3/r4 de cada llamada) para el paso de texturas; los
  // registros BP que el huesped escribiria al FIFO no se
  // leen de vuelta en la ruta observada. Si una lectura
  // posterior del estado GX lo exigiera, se rellenaria aqui.
  static constexpr uint32_t kGxLoadTexObj = 0x8025B260u;
  // OSReport (Fase 5b, diagnostico): en este binario es un stub
  // de 0x50 B (0x8007D8C0-0x8007D910: vuelca r3-r10 y f1-f8 a
  // la pila y retorna, sin imprimir nada en retail). HLEarlo
  // para capturar formato+args es, por tanto, un cambio de
  // observacion, no de logica: el bucle debe dar los mismos
  // conteos HLE/DVD/PAD que sin el (verificado en run15).
  // El formato llega en r3 y los args en r4-r10 (enteros) y
  // f1-f8 (flotantes), convencion varargs PPC; el formateador
  // es propio y conservador (ver hle.cpp): %d/%u/%x/%s/%c/%p
  // desde GPR, %f/%g desde FPR, resto literal con marca. Los
  // enteros mas alla de r10 se leen del area de parametros del
  // llamador (sp+8 + 4*k, verificado en run16 con la linea
  // "mem" de 16 args); los flotantes en pila se marcan.
  static constexpr uint32_t kOsReport = 0x8007D8C0u;
  // Barrera PPCSync (Fase 5, desbloqueo AR): su cuerpo en este
  // binario es un unico `sc` (ver chunk_0143, 0x80240CBC) seguido
  // de blr; el SDK lo usa como barrera de pipeline y el manejador
  // de la excepcion retorna al llamador. En recompilacion no hay
  // pipeline ni caches separadas que serializar: no-op con
  // retorno a lr. Los otros dos `sc` del binario (colas de
  // DCFlushRange 0x80242354 y DCStoreRange 0x80242388) ya son
  // inalcanzables porque esas funciones estan HLEadas enteras.
  static constexpr uint32_t kPpcSync = 0x80240CBCu;
  // CARD (Fase 12, HLE entero en Slot A, ver card.h): el juego
  // solo usa Slot A y solo llama a las variantes sincronas
  // (verificado por barrido de bl en el codigo generado); las
  // variantes Async del SDK quedan como codigo huesped (sin
  // EXI, inalcanzables desde el juego). Direcciones verificadas
  // en codigo/generated/generated_symbols.h / symbols.map.
  static constexpr uint32_t kCardInit = 0x8025F664u;
  static constexpr uint32_t kCardProbeEx = 0x802624B8u;
  static constexpr uint32_t kCardMount = 0x80262D1Cu;
  static constexpr uint32_t kCardUnmount = 0x80262E00u;
  static constexpr uint32_t kCardCheck = 0x80262398u;
  static constexpr uint32_t kCardFormat = 0x80263648u;
  static constexpr uint32_t kCardOpen = 0x8026391Cu;
  static constexpr uint32_t kCardClose = 0x80263A94u;
  static constexpr uint32_t kCardCreate = 0x80263E40u;
  static constexpr uint32_t kCardRead = 0x802642B8u;
  static constexpr uint32_t kCardWrite = 0x80264634u;
  static constexpr uint32_t kCardDelete = 0x80264830u;
  static constexpr uint32_t kCardGetStatus = 0x80264A70u;
  static constexpr uint32_t kCardSetStatus = 0x80264D10u;
  static constexpr uint32_t kCardGetSerialNo = 0x80264D58u;
  // __AI_SRC_INIT (0x8025072Cu) NO se HLEa aqui a proposito:
  // sus 3 llamadores (0x802501A4, 0x80250298, 0x80250388)
  // estan en el MISMO chunk que la funcion (chunk_0147), asi
  // que DolRecomp los emite como goto, no como despacho: el
  // host_call nunca ve 0x8025072C y una entrada en la tabla
  // seria codigo muerto que fingiria cobertura. El desbloqueo
  // real es el timebase del chassis (ver chassis.cpp).

  Hle();
  ~Hle();

  // Raiz del arbol del disco ya extraido (p. ej. disc/files/).
  // Sin raiz, DVDOpen falla de forma explicita (log + retorno 0).
  void SetDiscRoot(const char* root);
  const std::string& DiscRoot() const { return disc_root_; }

  // Instala host_call + instruction_fallback en cpu, con esta
  // instancia en cpu->external_user_data para los callbacks C.
  void Install(CpuState* cpu);

  // Entrada del host_call de DolRecomp. true = HLE ejecutado.
  bool HandleHostCall(CpuState* cpu, uint32_t address);
  // Fallback de instrucciones no traducidas. El emisor C de
  // DolRecomp termina el bloque tras un fallback y espera que
  // el runtime avance el PC: por eso los casos modelados
  // (cache y SPR HID0/L2CR, ver hle.cpp) ponen pc = cia+4.
  // Cualquier otro caso marca exception sin avanzar: el
  // chassis se detiene y la registra, no se enmascara.
  void HandleFallback(CpuState* cpu, uint32_t raw, uint32_t cia);

  // DVD, usables tambien directamente desde tests host.
  // DvdOpen: 1 = abierto, 0 = fallo. DvdRead: bytes leidos, -1
  // si el fileInfo no tiene entrada HLE abierta.
  int DvdOpen(CpuState* cpu, uint32_t filename_guest,
              uint32_t fileinfo_guest);
  int DvdRead(CpuState* cpu, uint32_t fileinfo_guest,
              uint32_t dest_guest, uint32_t length, uint32_t offset);
  bool DvdClose(CpuState* cpu, uint32_t fileinfo_guest);

  // Inyeccion PAD solo para diagnostico host (Fase 5b, ahora
  // sobre PadState, Fase 6b): el test la activa y PADRead
  // escribe ese estado en el PADStatus del pad 0; padUpdate
  // (codigo huesped) calcula Held/JustPressed desde ahi,
  // igual que con un mando real. Por defecto desactivada:
  // PADRead escribe el PadState vigente (cero si nadie lo
  // puso). NO es el mapeo tactil (ese vive en Input y llega
  // por SetPadState) y nunca se activa en la APK desde aqui.
  void SetPadInject(bool enabled, uint16_t buttons, int8_t stick_x,
                    int8_t stick_y);
  bool PadInjectEnabled() const { return pad_inject_; }
  // Tarjeta virtual Slot A (Fase 12, ver card.h): la ruta se
  // fija antes de arrancar el juego; sin ruta, la tarjeta vive
  // en RAM. En la APK la fija native-lib a
  // <internalDataPath>/memcard-a.raw (almacenamiento privado,
  // persiste entre arranques); en host la fija el test.
  void SetCardPath(const char* path);
  const VirtualCard& Card() const { return card_; }
  // Solo host (Fase 12): con false, Slot A se comporta como
  // vacio (Probe/Mount/... devuelven NOCARD). Sirve para
  // verificar en host la via "Play (but cannot save your
  // progress)" sin tarjeta. La APK no lo usa (siempre true).
  void SetCardEnabled(bool enabled) { card_enabled_ = enabled; }
  bool CardEnabled() const { return card_enabled_; }
  // Programacion de pulsacion de test (Fase 8, solo host):
  // si n > 0, la inyeccion de test solo entrega botones a
  // partir del PADRead numero n (las lecturas 1..n-1 salen
  // con botones 0), para medir el flanco JustPressed con
  // una pulsacion posterior real y no mantenida desde el
  // arranque. Por defecto 0 = sin programacion (comportamiento
  // anterior). La APK nunca llama a esto: su ruta es
  // SetPadState, con pad_inject_ desactivado, asi que el
  // programador no puede afectar al juego real.
  void SetPadPressFromRead(uint64_t n) { pad_press_from_read_ = n; }
  // Secuencia PAD de test (Fase 12, solo host): tramos
  // (desde PADRead n, botones, stick) aplicados en orden; el
  // tramo vigente es el ultimo cuyo from_read <= lecturas.
  // Sirve para guiones de varios pasos (p. ej. stick abajo y
  // luego A en el aviso de Memory Card) que la inyeccion
  // constante de SetPadInject no puede expresar. La APK nunca
  // la usa: su ruta es SetPadState desde Input.
  struct PadScriptStep {
    uint64_t from_read = 0;
    uint16_t buttons = 0;
    int8_t stick_x = 0;
    int8_t stick_y = 0;
  };
  void SetPadScript(const PadScriptStep* steps, size_t count) {
    pad_script_.clear();
    if (steps != nullptr) {
      for (size_t i = 0; i < count; ++i) pad_script_.push_back(steps[i]);
    }
  }
  uint64_t PadReads() const { return pad_reads_; }
  // Estado PAD vigente (Fase 6b): si se fija un estado externo
  // (Input, no propio), PADRead lo lee de ahi; si no, usa el
  // estado interno (inyeccion de test o cero). El puntero no
  // se posee: debe vivir mas que el Hle (en el runtime, Input
  // vive en el mismo objeto que Hle).
  void SetPadState(const PadState* state) { pad_state_ext_ = state; }
  const PadState* PadStatePtr() const { return pad_state_ext_; }
  // Rumble fase A: sink inyectable (por defecto nulo, fase B
  // pendiente). El puntero no se posee: debe vivir mas que
  // el Hle. Sin sink, el HLE solo registra y loguea.
  void SetRumbleSink(RumbleSink* sink) { rumble_sink_ = sink; }
  bool RumbleOn(int chan) const { return rumble_tracker_.IsOn(chan); }
  // Flag de muestra PAD nueva (0x803DE65D, ver cabecera).
  static constexpr uint32_t kPadFreshFlag = 0x803DE65Du;
  // FST del disco (Fase 6a): ruta explicita opcional; si no se
  // fija, SetDiscRoot prueba disc_root/../sys/fst.bin y
  // disc_root/sys/fst.bin. Sin FST, +48 se escribe 0.
  void SetFstPath(const char* path);
  bool FstLoaded() const { return fst_loaded_; }
  uint64_t DvdCallbacksInvoked() const { return dvd_callbacks_; }
  uint64_t ArqDrainedUpload() const { return arq_drained_upload_; }
  uint64_t ArqDrainedSync() const { return arq_drained_sync_; }
  uint64_t ArqCallbacksDelivered() const { return arq_callbacks_; }
  uint64_t DvdAsyncBytes() const { return dvd_async_bytes_; }
  uint64_t DvdFileInfoWriteFailures() const {
    return dvd_fileinfo_failures_;
  }
  // Eventos async completados (fileInfo, callback, bytes) para
  // tests host; el callback se registra aqui ANTES de
  // despacharlo como codigo huesped, asi que el test puede
  // contar entregas aunque el callback cierre el fichero.
  struct DvdAsyncEvent {
    uint32_t fileinfo = 0;
    uint32_t callback = 0;
    int32_t bytes = 0;
  };
  const std::vector<DvdAsyncEvent>& DvdAsyncEvents() const {
    return dvd_async_events_;
  }
  // Trampolines DVD completados (Fase 15): uno por callback
  // async entregado; en un run sin error debe igualar el
  // numero de callbacks DVD despachados (dvd_callbacks_) y
  // la pila debe quedar vacia al final (DvdTrampolineDepth
  // == 0). Un trampolin sin marco es un error interno del
  // HLE y se marca como exception en el handler, no se
  // ignora en silencio.
  uint64_t DvdCallbackTrampolines() const { return dvd_trampolines_; }
  // Entregas de PrepareCallback por DVDPrepareStreamAsync (Fase 16).
  uint64_t DvdPrepareCallbacks() const { return dvd_prepare_callbacks_; }
  size_t DvdCallbackTrampolineDepth() const {
    return dvd_callback_stack_.size();
  }
  struct DvdCallbackFrame {
    uint32_t return_pc = 0;  // retorno original del llamador
    uint32_t restore_r3 = 0;  // bytes leidos (0 si lectura fallida/vacia)
    uint32_t fileinfo = 0;
    uint32_t callback = 0;
  };

  // Lineas OSReport capturadas (formato ya expandido) y cargas
  // GXLoadTexObj con su offset en el stream FIFO capturado, para
  // asociar cada draw con la textura vigente en ese punto.
  struct TexLoad {
    uint64_t fifo_offset = 0;
    uint32_t tex_obj = 0;
    uint32_t map = 0;
  };
  const std::vector<std::string>& OsReportLines() const {
    return osreport_lines_;
  }
  const std::vector<TexLoad>& TexLoads() const { return tex_loads_; }

  const std::vector<HleCall>& Calls() const { return calls_; }
  uint64_t CallCountFor(const char* name) const;
  uint64_t RetraceCount() const { return retrace_count_; }
  uint64_t ViChains() const { return vi_chains_; }
  uint64_t ViPreDelivered() const { return vi_pre_delivered_; }
  uint64_t ViPostDelivered() const { return vi_post_delivered_; }
  uint64_t FallbackCacheCount() const { return fallback_cache_; }
  uint64_t FallbackUnknownCount() const { return fallback_unknown_; }
  bool OsInitDone() const { return os_init_done_; }
  bool DvdInitDone() const { return dvd_init_done_; }
  bool ViInitDone() const { return vi_init_done_; }
  bool PadInitDone() const { return pad_init_done_; }
  bool GxInitDone() const { return gx_init_done_; }
  uint32_t ArenaLo() const { return arena_lo_; }
  uint32_t ArenaHi() const { return arena_hi_; }

 private:
  struct DvdEntry {
    uint32_t fileinfo = 0;
    std::FILE* file = nullptr;
    long size = 0;
    std::string host_path;
  };
  // Contexto por hilo (Fase 9): solo lo que es propio de un
  // hilo. Compartido y NO guardado/restaurado: ram/ram_size,
  // host_call, external_user_data, timebase (avanza con el
  // chassis, no por hilo), locked_cache y sus tags (memoria
  // compartida, como la RAM), hid2 (SPR global de CPU) y
  // downcount (el chassis lo repone antes de cada despacho).
  // La reserva lwarx/stwcx se limpia al cambiar de hilo
  // (semantica PPC: una reserva es por procesador, y el
  // cambio de contexto la invalida).
  struct ThreadContext {
    uint32_t gpr[32] = {};
    double fpr[32] = {};
    double ps1[32] = {};
    uint32_t pc = 0;
    uint32_t lr = 0;
    uint32_t ctr = 0;
    uint32_t cr = 0;
    uint32_t xer = 0;
    uint32_t fpscr = 0;
    uint32_t msr = 0;
    uint32_t srr0 = 0;
    uint32_t srr1 = 0;
    uint32_t dar = 0;
    uint32_t dsisr = 0;
    uint32_t ear = 0;
    uint32_t sr[16] = {};
    uint32_t gqr[8] = {};
    uint32_t program_exception = 0;
  };
  struct ThreadEntry {
    uint32_t thread_guest = 0;
    // runnable = reanudado al menos una vez (legado: antes
    // solo significaba "registrado y marcado runnable").
    bool runnable = false;
    uint32_t entry = 0;
    uint32_t val = 0;
    uint32_t stack = 0;
    uint32_t stack_size = 0;
    uint32_t priority = 0;
    uint32_t suspend_count = 1;
    bool started = false;
    bool suspended = true;
    bool finished = false;
    ThreadContext ctx;
    bool has_ctx = false;
    bool canary_warned = false;
    uint64_t switches_in = 0;
    uint64_t yields = 0;
    uint64_t suspends = 0;
  };

 public:
  // Estadistica del planificador (Fase 9), para tests host.
  const std::vector<ThreadEntry>& ThreadsForTest() const {
    return threads_;
  }
  int CurrentThreadIndexForTest() const { return current_thread_; }
  uint64_t SchedulerSwitches() const { return switches_total_; }
  uint64_t SchedulerSwitchesToMain() const { return switches_to_main_; }
  uint64_t SchedulerFallbacks() const { return scheduler_fallbacks_; }
  struct MainWakeDelivery {
    uint32_t queue = 0;
    uint32_t message = 0;
    uint32_t sender_guest = 0;
    uint32_t sender_entry = 0;
  };
  const std::vector<MainWakeDelivery>& MainWakeDeliveries() const {
    return main_wake_deliveries_;
  }

 private:

  void LogCall(CpuState* cpu, const char* name, uint32_t address);
  bool Return(CpuState* cpu, uint32_t value);
  // Entrega de callbacks VI en un retrace simulado (ver
  // kViSetPreRetraceCallback): si hay pre y/o post
  // registrados, redirige pc a pre (con lr = trampolin) o a
  // post (con lr intacto) y devuelve true; si no hay ninguno
  // o ya hay una cadena en curso (retrace anidado dentro de
  // un callback), devuelve false y el llamador retorna normal.
  bool DeliverViCallbacks(CpuState* cpu);
  DvdEntry* FindDvd(uint32_t fileinfo_guest);
  static bool ReadGuestString(CpuState* cpu, uint32_t guest,
                              std::string* out);
  static bool WriteGuestBytes(CpuState* cpu, uint32_t dest,
                              const uint8_t* data, uint32_t size);

  std::string disc_root_;
  std::vector<HleCall> calls_;
  // Fase 5b (ver SetPadInject / OsReportLines / TexLoads).
  bool pad_inject_ = false;
  uint16_t pad_inject_buttons_ = 0;
  int8_t pad_inject_stick_x_ = 0;
  int8_t pad_inject_stick_y_ = 0;
  uint64_t pad_press_from_read_ = 0;
  uint64_t pad_reads_ = 0;
  std::vector<PadScriptStep> pad_script_;
  // Tarjeta virtual Slot A (Fase 12) y ficheros CARD abiertos:
  // la clave es la direccion guest del CARDFileInfo, el valor
  // el fileNo (indice de directorio). Si un Read/Write llega
  // sin registro (struct copiado por el huesped), se recurre
  // a leer +4 del propio struct guest.
  VirtualCard card_;
  bool card_enabled_ = true;
  std::vector<std::pair<uint32_t, int>> card_open_;
  std::vector<std::string> osreport_lines_;
  std::vector<TexLoad> tex_loads_;
  // Formatea un OSReport huesped (formato en r3, args en
  // r4-r10/f1-f8). Devuelve false si el formato es ilegible.
  bool FormatOsReport(CpuState* cpu, std::string* out);
  // Contador por nombre para el tope de log (20 por nombre), sin
  // recorrer calls_ en cada llamada (seria O(n^2) en bucles).
  // Indice = posicion en kHleTable de hle.cpp (Fase 12: 128
  // huecos, porque la tabla CARD la lleva por encima de 64).
  uint64_t log_count_[128] = {};
  std::vector<DvdEntry> dvd_;
  std::vector<ThreadEntry> threads_;
  uint64_t retrace_count_ = 0;
  // Cadena de callbacks VI en curso (ver DeliverViCallbacks).
  bool vi_chain_active_ = false;
  uint32_t vi_chain_post_ = 0;
  uint32_t vi_chain_ret_ = 0;
  uint64_t vi_chains_ = 0;
  uint64_t vi_pre_delivered_ = 0;
  uint64_t vi_post_delivered_ = 0;
  // Fase 6a: retrace por interrupcion de frame. El chassis no
  // tiene interrupciones reales; el punto logico donde el
  // juego espera un retrace es OSSleepThread desde
  // waitNextFrame (0x8004ABE0): cada sueno completado ES un
  // retrace entregado. VIWaitForRetrace tambien avanza al
  // siguiente retrace (solo se llama en tvInit, x2 en run20,
  // asi que no hay doble conteo en el bucle). NO se deriva
  // del timebase del chassis: ese timebase es simulado
  // (+200/despacho, ~40k/frame) y un contador a 50 Hz sobre
  // el daria un retrace cada ~243 frames, escala falsa.
  // Los callbacks pre/post retrace que el juego registra
  // (VISetPreRetraceCallback 0x8024CB14, Post 0x8024CB58,
  // desde 0x80049F48/54 y el reproductor THP) NO se entregan
  // todavia: sus punteros viven en el estado VI del SDK
  // (codigo huesped, sin HLE) y leerlos exige localizar ese
  // estado; queda documentado como siguiente paso, no como
  // hecho.
  // Fase 6a/b: estado PAD y FST (ver hle.cpp).
  PadState pad_state_;
  const PadState* pad_state_ext_ = nullptr;
  // Rumble fase A (ver rumble.h): tracker por canal + sink
  // inyectable (nulo por defecto: no-op + log).
  RumbleTracker rumble_tracker_;
  RumbleSink* rumble_sink_ = nullptr;
  std::string fst_path_;
  bool fst_loaded_ = false;
  bool fst_load_attempted_ = false;
  // nombre normalizado (sin '/' inicial) -> (offset disco, len)
  std::vector<std::pair<std::string, std::pair<uint32_t, uint32_t>>>
      fst_entries_;
  uint64_t dvd_callbacks_ = 0;
  uint64_t dvd_async_bytes_ = 0;
  uint64_t dvd_fileinfo_failures_ = 0;
  uint64_t arq_drained_upload_ = 0;
  uint64_t arq_drained_sync_ = 0;
  uint64_t arq_callbacks_ = 0;
  std::vector<DvdAsyncEvent> dvd_async_events_;
  // Pila de trampolines DVD pendientes (Fase 15) + contador.
  std::vector<DvdCallbackFrame> dvd_callback_stack_;
  uint64_t dvd_trampolines_ = 0;
  uint64_t dvd_prepare_callbacks_ = 0;
  void TryLoadFst();
  bool LookupFst(const std::string& name, uint32_t* disc_offset,
                 uint32_t* length) const;
  static std::string NormalizeDvdName(const std::string& name);
  bool WriteDvdFileInfo(CpuState* cpu, uint32_t fileinfo,
                        uint32_t disc_offset, uint32_t length);
  // Aplica las peticiones ARQ pendientes como decrementos del
  // contador de cola del juego en count_addr (Fase 5/6a).
  void DrainArqCompletions(CpuState* cpu, uint32_t count_addr,
                           const char* where);
  uint64_t fallback_cache_ = 0;
  uint64_t fallback_unknown_ = 0;
  bool os_init_done_ = false;
  bool dvd_init_done_ = false;
  bool vi_init_done_ = false;
  bool pad_init_done_ = false;
  bool gx_init_done_ = false;
  // Arena HLE provisional (ver PORT-STATUS): por encima de la
  // pila (0x803F9E58) y del BSS (fin 0x803E4458), dentro de RAM
  // (fin 0x81800000). videoInit la consultara via OSGetArena*.
  uint32_t arena_lo_ = 0x80400000u;
  uint32_t arena_hi_ = 0x81700000u;
  // Bump allocator del heap HLE (ver hle.cpp): un solo heap
  // global dentro de la arena. heap_next_ arranca en
  // arena_lo_ y OSInitAlloc lo reinicia.
  uint32_t heap_next_ = 0x80400000u;
  // SPR que CPUState no modela y el emisor C deja en fallback:
  // HID0 (1008) y L2CR (1017). El HLE los guarda aqui; su valor
  // inicial es 0 (provisional: el codigo observado solo hace
  // OR de bits sobre lo leido, no comprueba bits previos).
  uint32_t hid0_ = 0;
  uint32_t l2cr_ = 0;
  uint32_t wpar_ = 0;
  // WPAR (921, tubo write-gather de GX): se guarda como HID0/
  // L2CR. Valor inicial 0 = tubo vacio: GXResetWriteGatherPipe
  // gira mientras el bit 0 de mfwpar sea 1, asi que con 0 sale
  // en el primer intento (sin tubo que drenar en este modelo).
  // Tarea DSP pendiente de callback de init (Fase 5): se fija
  // en la entrada a DSPAddTask (codigo huesped, no HLEado) y
  // se consume al aterrizar en el bucle de espera de
  // salInitDsp. 0 = ninguna pendiente (una tarea real nunca
  // tiene direccion 0).
  uint32_t pending_dsp_task_ = 0;
  // Peticiones ARQ pendientes de completar (Fase 5): se
  // incrementa en cada entrada a ARQPostRequest (codigo
  // huesped, no HLEado) y se aplica como decrementos del
  // contador de la cola del juego al aterrizar en el bucle
  // de espera de aramInit.
  uint32_t pending_arq_completions_ = 0;
  // Planificador cooperativo (Fase 9, ver hle.cpp).
  // current_thread_ = indice en threads_, o -1 = hilo
  // principal (que no tiene ThreadEntry: su struct OSThread
  // lo crea el OS antes de main y nunca pasa por
  // OSCreateThread HLEado). main_ctx_ es su contexto
  // guardado en el ultimo sueno por cola; blocked_* es la
  // cola en la que quedo esperando (0 = ninguna).
  int current_thread_ = -1;
  ThreadContext main_ctx_;
  bool main_saved_ = false;
  uint32_t blocked_queue_ = 0;
  int blocked_kind_ = 0;  // 0 ninguna, 1 Receive, 2 Send
  uint64_t switches_total_ = 0;
  uint64_t switches_to_main_ = 0;
  uint64_t scheduler_fallbacks_ = 0;
  std::vector<MainWakeDelivery> main_wake_deliveries_;
  ThreadEntry* FindThread(uint32_t guest);
  void SaveCurrent(CpuState* cpu, uint32_t resume_pc);
  void LoadContext(CpuState* cpu, const ThreadContext& ctx);
  void LoadMain(CpuState* cpu);
  bool MainReady(CpuState* cpu);
  bool SwitchToMain(CpuState* cpu, bool save_current);
  bool SwitchToWorker(CpuState* cpu, size_t idx, bool save_current);
  bool SwitchOnSleep(CpuState* cpu);
  void UpdateReadyMask(CpuState* cpu);
  void WriteThreadGuestFields(CpuState* cpu, ThreadEntry* t);
};

}  // namespace sfa

// Callbacks C para CPUState::host_call / instruction_fallback.
// Recuperan la instancia desde cpu->external_user_data (puesta
// por Hle::Install); sin instancia devuelven false (sin HLE, el
// chunk original corre) o marcan exception en el fallback.
extern "C" bool sfa_hle_host_call(CPUState* cpu, uint32_t address);
extern "C" void sfa_hle_instruction_fallback(CPUState* cpu, uint32_t raw,
                                            uint32_t cia);
