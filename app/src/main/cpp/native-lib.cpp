// Punto de entrada nativo de la base del port (NativeActivity).
//
// Ciclo de vida mínimo y honesto:
//   - APP_CMD_INIT_WINDOW: inicializa renderer + runtime.
//   - APP_CMD_TERM_WINDOW / APP_CMD_DESTROY: apaga en orden.
//   - APP_CMD_GAINED_FOCUS / LOST_FOCUS: pausa/reanuda el frame.
//   - Sin ventana o sin foco: no se dibuja, se espera eventos.
//   - Input: se entrega al módulo Input (stub en esta base).
//
// No hay código del juego ejecutándose todavía: el runtime es la
// base (memoria + CPU stub + audio stub) y el renderer solo limpia
// la pantalla. Si la app se cierra al abrir, boot.log y logcat
// dicen hasta qué comando llegó.

#include <android_native_app_glue.h>

#include <cstdio>
#include <string>

#include "gamecube_runtime/runtime.h"
#include "log.h"
#include "platform/platform.h"
#include "renderer/renderer.h"

namespace {

struct AppState {
  sfa::GameCubeRuntime runtime;
  sfa::Renderer renderer;
  bool has_focus = false;
  bool window_ready = false;
};

void HandleCmd(struct android_app* app, int32_t cmd) {
  auto* state = static_cast<AppState*>(app->userData);
  switch (cmd) {
    case APP_CMD_INIT_WINDOW:
      if (app->window != nullptr) {
        state->window_ready = state->renderer.Init(app->window);
        if (state->window_ready) {
          state->runtime.Init();
          // Fase 10 — carga de datos (dormida sin datos):
          // si existe un arbol Pack B copiado en la carpeta
          // privada de la app (interna o externa), se carga.
          // Layout exacto (ver PORT-STATUS, via de datos):
          //   <base>/sfa-data/sys/main.dol
          //   <base>/sfa-data/files/...
          // Sin SAF todavia: la copia la hace el usuario por
          // adb (build de prueba) o, cuando exista, el picker
          // SAF que copiara a esta misma carpeta. Sin datos,
          // la APK queda en clear + quad de prueba, y eso se
          // registra en boot.log (no es un fallo).
          const char* bases[2] = {nullptr, nullptr};
          std::string internal = sfa::InternalDataPath();
          if (!internal.empty()) bases[0] = internal.c_str();
          if (app->activity != nullptr &&
              app->activity->externalDataPath != nullptr) {
            bases[1] = app->activity->externalDataPath;
          }
          bool tried = false;
          for (const char* base : bases) {
            if (base == nullptr) continue;
            std::string dol = std::string(base) + "/sfa-data/sys/main.dol";
            std::FILE* probe = std::fopen(dol.c_str(), "rb");
            if (probe == nullptr) continue;
            std::fclose(probe);
            tried = true;
            std::string files = std::string(base) + "/sfa-data/files";
            state->runtime.SetDiscRoot(files.c_str());
            // Fase 12 — tarjeta virtual Slot A: persiste en el
            // almacenamiento privado de la app, junto a los
            // datos (misma base que el DOL: interna preferida).
            // Sin esta llamada, la tarjeta viviria solo en RAM
            // y la partida se perderia al cerrar la app.
            state->runtime.HleState()->SetCardPath(
                (std::string(base) + "/memcard-a.raw").c_str());
            if (state->runtime.LoadGame(dol.c_str())) {
              SFA_LOGI("native: juego cargado desde %s", dol.c_str());
            } else {
              SFA_LOGE("native: LoadGame fallo en %s", dol.c_str());
            }
            break;
          }
          if (!tried) {
            SFA_LOGI("native: sin datos sfa-data (modo clear + quad "
                     "de prueba; ver PORT-STATUS, via de datos)");
          }
        } else {
          SFA_LOGE("native: renderer no listo, runtime sin arrancar");
        }
      }
      break;
    case APP_CMD_TERM_WINDOW:
      state->runtime.Shutdown();
      state->renderer.Shutdown();
      state->window_ready = false;
      break;
    case APP_CMD_GAINED_FOCUS:
      state->has_focus = true;
      break;
    case APP_CMD_LOST_FOCUS:
      state->has_focus = false;
      break;
    case APP_CMD_DESTROY:
      state->runtime.Shutdown();
      state->renderer.Shutdown();
      break;
    default:
      break;
  }
}

int32_t HandleInput(struct android_app* app, AInputEvent* event) {
  // Fase 6b: los eventos llegan al Input del runtime (que
  // escribe el PadState que PADRead vuelca al juego). Se
  // devuelve 1 solo si Input lo consumio (cambio el estado).
  auto* state = static_cast<AppState*>(app->userData);
  if (state == nullptr) return 0;
  return state->runtime.InputState()->HandleEvent(event) ? 1 : 0;
}

}  // namespace

void android_main(struct android_app* app) {
  sfa::PlatformInit(app);
  SFA_LOGI("native: android_main, base del port Android (sin juego todavia)");

  AppState state;
  app->userData = &state;
  app->onAppCmd = HandleCmd;
  app->onInputEvent = HandleInput;

  // Loop principal: procesar eventos y, solo con ventana y foco,
  // ejecutar un frame del runtime.
  while (true) {
    int events = 0;
    struct android_poll_source* source = nullptr;
    // Sin ventana/foco: bloqueo; con ventana: no bloqueo (frames).
    const int timeout = (state.window_ready && state.has_focus) ? 0 : -1;
    const int result =
        ALooper_pollOnce(timeout, nullptr, &events,
                         reinterpret_cast<void**>(&source));
    if (result >= 0 && source != nullptr) {
      source->process(app, source);
    }
    if (app->destroyRequested != 0) {
      state.runtime.Shutdown();
      state.renderer.Shutdown();
      SFA_LOGI("native: destroyRequested, salida limpia");
      return;
    }
    if (state.window_ready && state.has_focus &&
        state.runtime.IsRunning()) {
      state.runtime.Frame(&state.renderer);
    }
  }
}
