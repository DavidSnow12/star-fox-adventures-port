#include "gamecube_runtime/runtime.h"

#include "cpu/cpu.h"
#include "gamecube_runtime/dol_loader.h"
#include "log.h"

namespace sfa {

bool GameCubeRuntime::Init() {
  if (!memory_.Init()) return false;
  cpu_.Reset();
  audio_.Init();
  audio_.Start();
  input_.Reset();
  // Fase 6b: el estado PAD que escribe Input (eventos Android)
  // es el que lee PADRead en el HLE. Sin este cable, Input y
  // HLE vivirian desconectados (el fallo de la base).
  hle_.SetPadState(input_.StatePtr());
  game_loaded_ = false;
  boot_finished_ = false;
  boot_reached_main_ = false;
  boot_reached_init_ = false;
  boot_reached_video_init_ = false;
  running_ = true;
  SFA_LOGI("runtime: inicializado (base, sin codigo de juego todavia)");
  SFA_LOGI("runtime: dispatch con %zu imports minimos pendientes, SMC "
           "con %zu rangos registrados",
           SymbolDispatch::kMinimalImportCount, smc_.Count());
  return true;
}

bool GameCubeRuntime::LoadGame(const char* dol_path) {
  DolLoadResult result = LoadDolFromFile(dol_path, &memory_);
  if (!result.ok) {
    SFA_LOGE("runtime: no se pudo cargar el DOL (%s)",
             result.error != nullptr ? result.error : "desconocido");
    return false;
  }
  dispatch_.RegisterGuestBoot();
  dispatch_.RegisterGuestInit();
  // Chassis Fase 2: el CPUState apunta a la RAM guest ya cargada
  // con el DOL real, con el HLE instalado y la traza activa.
  InitCpuForBoot(&cpu_state_, memory_.RamData(), memory_.RamSize(),
                 result.entry);
  hle_.Install(&cpu_state_);
  sfa_hw_trace_reset();
  sfa_hw_trace_set_enabled(1);
  game_loaded_ = true;
  boot_finished_ = false;
  boot_reached_main_ = false;
  boot_reached_init_ = false;
  boot_reached_video_init_ = false;
  SFA_LOGI("runtime: DOL cargado, entry 0x%08X, dispatch guest con "
           "%zu simbolos (boot + init), chassis+HLE listos",
           result.entry, dispatch_.GuestCount());
  return true;
}

void GameCubeRuntime::Shutdown() {
  running_ = false;
  audio_.Shutdown();
  sfa_hw_trace_set_enabled(0);
  SFA_LOGI("runtime: apagado");
}

bool GameCubeRuntime::DumpHwTrace(const char* csv_path,
                                  const char* events_path) {
  int a = sfa_hw_trace_write_csv(csv_path);
  int b = sfa_hw_trace_write_events_csv(events_path);
  return a == 0 && b == 0;
}

void GameCubeRuntime::Frame(Renderer* renderer) {
  if (!running_ || renderer == nullptr) return;
  renderer->BeginFrame();
  if (game_loaded_ && boot_finished_ && !game_ended_) {
    // Fase 10: tras videoInit, el juego NO se detiene: sigue
    // en rebanadas por frame (100.000 despachos o 0,25 s).
    // Sin captura FIFO (32 MiB de tope: no es la via del
    // renderer; la alimentacion GX incremental con parser con
    // estado queda pendiente, ver PORT-STATUS).
    ChassisResult slice =
        RunChassis(&cpu_state_, &hle_, 100000, 0.25, 0);
    ++post_boot_slices_;
    if (slice.reason == ChassisResult::kException ||
        slice.reason == ChassisResult::kUnknownPc ||
        slice.reason == ChassisResult::kReachedExit) {
      game_ended_ = true;
      SFA_LOGI("runtime: juego terminado tras arranque: %s, "
               "rebanadas post-boot %llu, pc 0x%08X",
               slice.reason_text,
               static_cast<unsigned long long>(post_boot_slices_),
               cpu_state_.pc);
    }
  } else if (game_loaded_ && !boot_finished_) {
    // Rebanada del chassis por frame: el arranque completo puede
    // necesitar varias rebanadas; el estado (pc, registros, RAM)
    // vive en cpu_state_ y persiste entre frames.
    ChassisResult slice =
        RunChassis(&cpu_state_, &hle_, 100000, 0.25,
                   kBootVideoInitAddress);
    if (slice.reached_main) boot_reached_main_ = true;
    if (slice.reached_init) boot_reached_init_ = true;
    if (slice.reached_stop_pc) boot_reached_video_init_ = true;
    if (slice.reached_stop_pc ||
        slice.reason == ChassisResult::kException ||
        slice.reason == ChassisResult::kUnknownPc ||
        slice.reason == ChassisResult::kReachedExit) {
      boot_finished_ = true;
      SFA_LOGI("runtime: arranque terminado: %s, despachos en "
               "rebanada %llu, main=%d init=%d videoInit=%d",
               slice.reason_text,
               static_cast<unsigned long long>(slice.dispatches),
               boot_reached_main_ ? 1 : 0, boot_reached_init_ ? 1 : 0,
               boot_reached_video_init_ ? 1 : 0);
    }
  } else if (!game_loaded_) {
    // Fase 0 intacta: sin juego, el paso stub de siempre.
    cpu_.Step();
  }
  audio_.Pump();
  renderer->DrawQuad();
  if (!pending_gx_draws_.empty()) {
    // Via GX futura: draws parseados del frame, con texturas
    // desde la RAM huesped del runtime.
    renderer->DrawGxFrame(pending_gx_draws_, memory_.RamData(),
                          memory_.RamSize());
    pending_gx_draws_.clear();
  } else if (!game_loaded_) {
    // Sin juego: clear + quad de prueba con textura (damero
    // procedural, no arte del juego). Con juego cargado, NO
    // se dibuja el damero: el frame queda en clear hasta que
    // la alimentacion GX exista.
    renderer->DrawTestQuad();
  }
  renderer->RenderFrame();
}

}  // namespace sfa
