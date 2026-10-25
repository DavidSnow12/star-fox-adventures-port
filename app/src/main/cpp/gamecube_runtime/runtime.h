#pragma once

// Runtime de consola: une memoria, CPU, renderer, audio e input en
// un ciclo de frame.
//
// Fase 2-3: cuando hay un juego cargado (LoadGame), Frame() ya no
// usa el stub de CPU: ejecuta el chassis DolRecomp (chassis.h)
// en rebanadas por frame (100.000 despachos o 0,25 s por frame,
// lo que llegue antes) desde la entry del DOL, con el HLE
// instalado (hle.h) y la traza de hardware activa. Sin juego
// cargado, Frame() conserva exactamente el comportamiento de la
// Fase 0 (paso stub + quad): la APK boot-test no cambia.

#include "audio/audio.h"
#include "gamecube_runtime/chassis.h"
#include "gamecube_runtime/cpu.h"
#include "gamecube_runtime/hle.h"
#include "gamecube_runtime/memory.h"
#include "gamecube_runtime/smc_ranges.h"
#include "gamecube_runtime/symbol_dispatch.h"
#include "input/input.h"
#include "renderer/renderer.h"

namespace sfa {

class GameCubeRuntime {
 public:
  bool Init();
  // Carga un DOL real en la RAM guest (Fase 1) y prepara el
  // chassis: CPUState apuntando a esa RAM, HLE instalado y
  // traza de hardware activa. Devuelve false si el fichero no
  // existe o no valida; en ese caso el runtime sigue en modo
  // base (sin juego) y el motivo queda en boot.log. La ruta la
  // dara el paquete de datos, no esta hardcodeada aqui.
  bool LoadGame(const char* dol_path);
  // Raiz del arbol del disco ya extraido para el HLE DVD
  // (p. ej. la carpeta files/ del paquete de datos). Debe
  // llamarse antes de que el juego abra ficheros DVD.
  void SetDiscRoot(const char* root) { hle_.SetDiscRoot(root); }
  void Shutdown();

  // Un frame completo (llamado desde android_main cuando hay
  // ventana). Con juego: una rebanada del chassis; sin juego:
  // el paso stub de la base.
  void Frame(Renderer* renderer);

  GCMemory* Memory() { return &memory_; }
  SymbolDispatch* Dispatch() { return &dispatch_; }
  SmcTable* Smc() { return &smc_; }
  Hle* HleState() { return &hle_; }
  CpuState* Cpu() { return &cpu_state_; }
  bool IsRunning() const { return running_; }
  bool IsGameLoaded() const { return game_loaded_; }
  bool IsBootFinished() const { return boot_finished_; }
  bool BootReachedMain() const { return boot_reached_main_; }
  bool BootReachedInit() const { return boot_reached_init_; }
  bool BootReachedVideoInit() const { return boot_reached_video_init_; }
  // Vuelca la traza de hardware a CSV (Fase 4). Devuelve false
  // si no se pudo escribir alguno de los dos ficheros.
  bool DumpHwTrace(const char* csv_path, const char* events_path);

 private:
  GCMemory memory_;
  GekkoCpu cpu_{&memory_};
  SymbolDispatch dispatch_;
  SmcTable smc_;
  Hle hle_;
  CpuState cpu_state_{};
  Audio audio_;
  Input input_;
  bool running_ = false;
  bool game_loaded_ = false;
  bool boot_finished_ = false;
  bool boot_reached_main_ = false;
  bool boot_reached_init_ = false;
  bool boot_reached_video_init_ = false;
};

}  // namespace sfa
