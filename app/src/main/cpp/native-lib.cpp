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
