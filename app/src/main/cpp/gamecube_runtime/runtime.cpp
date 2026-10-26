#include "gamecube_runtime/runtime.h"

#include "cpu/cpu.h"
#include "gamecube_runtime/dol_loader.h"
#include "log.h"
#include "renderer/frame_capture.h"

namespace sfa {

namespace {

// Trampolin del hook de audio del chassis (Fase 14) al
// bridge del runtime. Sin WAV en el root, el bridge es
// inerte (ver audio_bridge.h).
void AudioHookTrampoline(uint32_t pc, uint32_t r3, uint32_t r4,
                         uint32_t r5, uint32_t r6, uint32_t r7,
                         void* user) {
  auto* bridge = static_cast<AudioBridge*>(user);
  if (bridge != nullptr) bridge->OnAudioEntry(pc, r3, r4, r5, r6, r7);
}

}  // namespace

bool GameCubeRuntime::Init() {
  if (!memory_.Init()) return false;
  cpu_.Reset();
  audio_.Init();
  audio_.Start();
  audio_bridge_.SetAudio(&audio_);
  // Tramo 8: RAM huésped para leer SynthPlayParams en OnSeqPlay
  // (speed/mutes/volumen de sndSeqPlayEx). Sin esta línea,
  // params = defaults v1 (sin rotura).
  audio_bridge_.SetGuestRam(memory_.RamData(), memory_.RamSize());
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
  // Fase 11: captura FIFO activa desde el primer slice. El
  // tope es 32 MiB, asi que FeedGxFrame() la drena tras cada
  // slice (un frame tipico es de decenas de KiB; el arranque
  // completo en host fue de ~15 MB en 5M despachos, repartido
  // en muchas rebanadas).
  sfa_fifo_capture_reset();
  sfa_fifo_capture_set_enabled(1);
  gx_parser_.ResetFeed();
  // Fase 11: lector DL sobre la RAM viva del runtime (con
  // chequeo de rango: un DL fuera de rango devuelve nullptr y
  // el parser lo salta contado, sin tumbar el frame).
  gx_parser_.SetRamReader([this](uint32_t guest, uint32_t size) {
    if (guest < 0x80000000u) return static_cast<const uint8_t*>(nullptr);
    uint64_t off = static_cast<uint64_t>(guest) - 0x80000000u;
    if (off + size > memory_.RamSize()) {
      return static_cast<const uint8_t*>(nullptr);
    }
    return static_cast<const uint8_t*>(memory_.RamData() + off);
  });
  gx_fifo_base_ = 0;
  gx_texloads_converted_ = 0;
  gx_capture_on_ = true;
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
  // Rumble fase B primero: ningun camino de apagado
  // (TERM_WINDOW, DESTROY, destroyRequested) puede dejar el
  // motor vibrando; el tracker reseteado rearma el proximo
  // RUMBLE si la app vuelve a arrancar el runtime.
  hle_.StopAllRumble();
  running_ = false;
  audio_.Shutdown();
  sfa_hw_trace_set_enabled(0);
  sfa_fifo_capture_set_enabled(0);
  gx_capture_on_ = false;
  SFA_LOGI("runtime: apagado");
}

void GameCubeRuntime::RequestFrameCapture(const char* dir,
                                          const char* scene) {
  if (dir == nullptr || scene == nullptr || scene[0] == '\0') return;
  capture_dir_ = dir;
  capture_scene_ = scene;
  capture_pending_ = true;
  SFA_LOGI("runtime: captura de frame pedida (dir %s, escena %s, "
           "indice %d)",
           dir, scene, capture_index_);
}

void GameCubeRuntime::FeedGxFrame() {
  if (!gx_capture_on_) return;
  // Texloads HLE nuevas: su fifo_offset es relativo al buffer
  // de captura vigente (se resetea tras cada drenaje), asi que
  // se convierten a offset global sumando gx_fifo_base_.
  const std::vector<Hle::TexLoad>& loads = hle_.TexLoads();
  std::vector<GxTexLoad> conv;
  if (loads.size() > gx_texloads_converted_) {
    for (size_t i = gx_texloads_converted_; i < loads.size(); ++i) {
      GxTexLoad gl;
      gl.fifo_offset = gx_fifo_base_ + loads[i].fifo_offset;
      gl.tex_obj = loads[i].tex_obj;
      gl.map = static_cast<int>(loads[i].map);
      conv.push_back(gl);
    }
    gx_parser_.AppendTexLoads(conv);
    gx_texloads_converted_ = loads.size();
  }
  unsigned long long len = sfa_fifo_capture_count();
  if (sfa_fifo_capture_overflow() > 0) {
    SFA_LOGI("runtime: captura FIFO desbordada (base %llu, "
             "len %llu): se pierden bytes; el parser se "
             "reinicia en el proximo frame",
             static_cast<unsigned long long>(gx_fifo_base_), len);
  }
  const uint8_t* data = sfa_fifo_capture_data();
  // Tramo 9: gancho de captura de frame. Punto temporal
  // critico: ANTES del parseo y ANTES del reset de captura,
  // con la RAM viva tal cual esta tras la rebanada. El
  // segmento FIFO y la RAM salen de aqui juntos: si se
  // escribieran despues del siguiente slice, la ventana
  // temporal estaria rota y la captura se descartaria
  // (ver CAPTURA_MUNDO_T9.md). Tras escribir, el frame
  // sigue su drenaje normal (el juego no se interrumpe).
  if (capture_pending_) {
    capture_pending_ = false;
    FrameCaptureMeta meta;
    meta.index = capture_index_;
    meta.scene = capture_scene_;
    meta.fifo_base = gx_fifo_base_;
    meta.overflow = sfa_fifo_capture_overflow();
    std::vector<FrameTexLoad> ft;
    for (const GxTexLoad& t : conv) {
      FrameTexLoad f;
      f.fifo_offset = t.fifo_offset;
      f.tex_obj = t.tex_obj;
      f.map = t.map;
      ft.push_back(f);
    }
    bool ok = false;
    if (len > 0 && data != nullptr) {
      ok = WriteFrameCapture(capture_dir_, meta, data,
                             static_cast<size_t>(len),
                             memory_.RamData(), memory_.RamSize(), ft);
    }
    SFA_LOGI("runtime: captura de frame %d (%s): fifo %llu B, "
             "ram %u B, overflow %llu, escena %s",
             capture_index_, ok ? "ok" : "FALLO",
             len, memory_.RamSize(), meta.overflow,
             capture_scene_.c_str());
    ++capture_index_;
  }
  if (len > 0 && data != nullptr) {
    if (!gx_parser_.Feed(data, static_cast<size_t>(len),
                         gx_fifo_base_)) {
      SFA_LOGI("runtime: parser GX fallo en frame (base %llu): "
               "%s; se reinicia el feed",
               static_cast<unsigned long long>(gx_fifo_base_),
               gx_parser_.FirstUnknown().c_str());
      gx_parser_.ResetFeed();
    } else {
      std::vector<GxDraw> fed = gx_parser_.TakeFedDraws();
      if (!fed.empty()) SetGxDraws(fed);
    }
  }
  sfa_fifo_capture_reset();
  gx_fifo_base_ += len;
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
    // Fase 11: tras videoInit, el juego sigue en rebanadas por
    // frame (100.000 despachos o 0,25 s) y FeedGxFrame() drena
    // la captura FIFO tras cada rebanada para dibujar los
    // draws del frame real (el tope de 32 MiB se evita con el
    // drenaje por frame).
    ChassisResult slice =
        RunChassis(&cpu_state_, &hle_, 100000, 0.25, 0,
                   &AudioHookTrampoline, &audio_bridge_);
    FeedGxFrame();
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
                   kBootVideoInitAddress, &AudioHookTrampoline,
                   &audio_bridge_);
    FeedGxFrame();
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
  // Fase 14: el bridge alimenta al backend antes de que
  // Pump() drene (en host) o el callback AAudio drene (en
  // Android, donde Pump() es no-op).
  audio_bridge_.Tick();
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
  // Tramo 6: pildora "anadir audio" SIEMPRE por encima (UI,
  // no arte): tambien sin juego, que es cuando mas falta
  // (importar audio antes de jugar). Estado desde Input,
  // que native-lib mantiene por sondeo de marcadores.
  renderer->DrawAudioButton(input_.AudioButtonState());
  renderer->RenderFrame();
}

}  // namespace sfa
