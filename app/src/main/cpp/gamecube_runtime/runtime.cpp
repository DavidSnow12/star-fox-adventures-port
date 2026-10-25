#include "gamecube_runtime/runtime.h"

#include "gamecube_runtime/dol_loader.h"
#include "log.h"

namespace sfa {

bool GameCubeRuntime::Init() {
  if (!memory_.Init()) return false;
  cpu_.Reset();
  audio_.Init();
  audio_.Start();
  input_.Reset();
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
  SFA_LOGI("runtime: DOL cargado, entry 0x%08X, dispatch guest con "
           "%zu simbolos (boot + init)",
           result.entry, dispatch_.GuestCount());
  return true;
}

void GameCubeRuntime::Shutdown() {
  running_ = false;
  audio_.Shutdown();
  SFA_LOGI("runtime: apagado");
}

void GameCubeRuntime::Frame(Renderer* renderer) {
  if (!running_ || renderer == nullptr) return;
  // Ritmo nominal de la base: un paso de CPU stub por frame.
  // El runtime real ejecutará aquí los chunks DolRecomp hasta el
  // siguiente sincronismo (VI/DVD/audio), no un paso por frame.
  cpu_.Step();
  audio_.Pump();
  renderer->DrawQuad();
  renderer->RenderFrame();
}

}  // namespace sfa
