#pragma once

// Runtime de consola: une memoria, CPU, renderer, audio e input en
// un ciclo de frame. En esta base, Frame() solo avanza la CPU stub,
// bombea el audio stub y deja el dibujo al renderer.

#include "audio/audio.h"
#include "gamecube_runtime/cpu.h"
#include "gamecube_runtime/memory.h"
#include "gamecube_runtime/smc_ranges.h"
#include "gamecube_runtime/symbol_dispatch.h"
#include "input/input.h"
#include "renderer/renderer.h"

namespace sfa {

class GameCubeRuntime {
 public:
  bool Init();
  // Carga un DOL real en la RAM guest (Fase 1). Devuelve false si
  // el fichero no existe o no valida; en ese caso el runtime sigue
  // en modo base (sin juego) y el motivo queda en boot.log. La ruta
  // la dará el paquete de datos, no está hardcodeada aquí.
  bool LoadGame(const char* dol_path);
  void Shutdown();

  // Un frame completo (llamado desde android_main cuando hay ventana).
  void Frame(Renderer* renderer);

  GCMemory* Memory() { return &memory_; }
  SymbolDispatch* Dispatch() { return &dispatch_; }
  SmcTable* Smc() { return &smc_; }
  bool IsRunning() const { return running_; }

 private:
  GCMemory memory_;
  GekkoCpu cpu_{&memory_};
  SymbolDispatch dispatch_;
  SmcTable smc_;
  Audio audio_;
  Input input_;
  bool running_ = false;
};

}  // namespace sfa
