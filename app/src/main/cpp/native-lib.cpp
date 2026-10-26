// Punto de entrada nativo de la base del port (NativeActivity).
//
// Ciclo de vida mínimo y honesto:
//   - APP_CMD_INIT_WINDOW: inicializa renderer + runtime, fija el
//     tamano de ventana para el layout tactil, y carga datos si
//     existen (o pide el picker SAF si no existen, Fase 13).
//   - APP_CMD_TERM_WINDOW / APP_CMD_DESTROY: apaga en orden.
//   - APP_CMD_GAINED_FOCUS / LOST_FOCUS: pausa/reanuda el frame.
//   - Sin ventana o sin foco: no se dibuja, se espera eventos.
//   - Input: se entrega al módulo Input (que escribe el
//     PadState que PADRead vuelca al juego).
//
// Via de datos (ver PORT-STATUS):
//   <base>/sfa-data/sys/main.dol + <base>/sfa-data/files/...
//   base = internalDataPath o externalDataPath (interna
//   preferida, la misma que usa SetCardPath para memcard-a.raw).
//   Sin datos: clear + quad de prueba, sin fallo. Con picker
//   SAF (Fase 13): si no hay datos en el primer arranque, se
//   pide la carpeta al usuario por JNI; cuando Java termina la
//   copia y escribe .saf-copy-done, el bucle principal carga
//   el juego sin reiniciar la app. Si el usuario cancela, no
//   se vuelve a pedir en esta ejecucion (evita un bucle de
//   pickers); la app sigue en clear + quad.

#include <android_native_app_glue.h>
#include <jni.h>

#include <cstdio>
#include <string>

#include <android/native_window.h>

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
  bool data_found = false;   // existe sfa-data/sys/main.dol
  bool load_tried = false;   // LoadGame ya intentado con datos
  bool saf_requested = false;
  bool saf_done_seen = false;
  bool saf_error_seen = false;
  int poll_counter = 0;
};

bool FileExists(const std::string& path) {
  std::FILE* f = std::fopen(path.c_str(), "rb");
  if (f == nullptr) return false;
  std::fclose(f);
  return true;
}

// Busca datos en las bases (interna, luego externa) y, si los
// hay, carga el juego. Devuelve true si encontro main.dol
// (aunque LoadGame falle: entonces no se reintenta en bucle).
bool TryLoadData(struct android_app* app, AppState* state) {
  const char* bases[2] = {nullptr, nullptr};
  std::string internal = sfa::InternalDataPath();
  if (!internal.empty()) bases[0] = internal.c_str();
  if (app->activity != nullptr &&
      app->activity->externalDataPath != nullptr) {
    bases[1] = app->activity->externalDataPath;
  }
  for (const char* base : bases) {
    if (base == nullptr) continue;
    std::string dol = std::string(base) + "/sfa-data/sys/main.dol";
    if (!FileExists(dol)) continue;
    state->data_found = true;
    state->load_tried = true;
    std::string files = std::string(base) + "/sfa-data/files";
    state->runtime.SetDiscRoot(files.c_str());
    // Fase 12 — tarjeta virtual Slot A: persiste en el
    // almacenamiento privado de la app, junto a los datos
    // (misma base que el DOL: interna preferida). Sin esta
    // llamada, la tarjeta viviria solo en RAM y la partida
    // se perderia al cerrar la app.
    state->runtime.HleState()->SetCardPath(
        (std::string(base) + "/memcard-a.raw").c_str());
    if (state->runtime.LoadGame(dol.c_str())) {
      SFA_LOGI("native: juego cargado desde %s", dol.c_str());
    } else {
      SFA_LOGE("native: LoadGame fallo en %s", dol.c_str());
    }
    return true;
  }
  return false;
}

// Pide el picker SAF a MainActivity por JNI. El hilo de
// android_main puede no estar asociado a la JVM: se asocia si
// hace falta y se desasocia despues. Java hace el resto en el
// hilo UI (ver MainActivity.requestDataFolder).
void RequestSafPicker(struct android_app* app) {
  if (app->activity == nullptr || app->activity->vm == nullptr ||
      app->activity->clazz == nullptr) {
    SFA_LOGE("native: SAF no disponible (sin activity/JVM)");
    return;
  }
  JavaVM* vm = app->activity->vm;
  JNIEnv* env = nullptr;
  bool attached = false;
  if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) !=
      JNI_OK) {
    if (vm->AttachCurrentThread(&env, nullptr) != JNI_OK || env == nullptr) {
      SFA_LOGE("native: SAF: no se pudo asociar el hilo a la JVM");
      return;
    }
    attached = true;
  }
  jclass cls = env->GetObjectClass(app->activity->clazz);
  if (cls == nullptr) {
    SFA_LOGE("native: SAF: sin clase de actividad");
    if (attached) vm->DetachCurrentThread();
    return;
  }
  jmethodID mid = env->GetMethodID(cls, "requestDataFolder", "()V");
  if (mid == nullptr) {
    SFA_LOGE("native: SAF: metodo requestDataFolder no encontrado");
    if (attached) vm->DetachCurrentThread();
    return;
  }
  env->CallVoidMethod(app->activity->clazz, mid);
  if (env->ExceptionCheck()) {
    env->ExceptionClear();
    SFA_LOGE("native: SAF: excepcion al pedir el picker");
  } else {
    SFA_LOGI("native: SAF: picker solicitado (sin datos en primer "
             "arranque; si se cancela, modo clear + quad)");
  }
  if (attached) vm->DetachCurrentThread();
}

// Si Java ya termino la copia SAF, carga el juego (una sola vez).
// Se llama desde el bucle principal, no en cada iteracion:
// cada 128 vueltas sin juego en marcha, un fopen barato.
void PollSafResult(struct android_app* app, AppState* state) {
  if (state->load_tried) return;
  std::string internal = sfa::InternalDataPath();
  const char* bases[2] = {nullptr, nullptr};
  if (!internal.empty()) bases[0] = internal.c_str();
  if (app->activity != nullptr &&
      app->activity->externalDataPath != nullptr) {
    bases[1] = app->activity->externalDataPath;
  }
  for (const char* base : bases) {
    if (base == nullptr) continue;
    std::string done = std::string(base) + "/sfa-data/.saf-copy-done";
    std::string err = std::string(base) + "/sfa-data/.saf-copy-error";
    if (!state->saf_done_seen && FileExists(done)) {
      state->saf_done_seen = true;
      SFA_LOGI("native: SAF: copia verificada (.saf-copy-done), "
               "cargando el juego");
      TryLoadData(app, state);
      return;
    }
    if (!state->saf_error_seen && FileExists(err)) {
      state->saf_error_seen = true;
      SFA_LOGE("native: SAF: copia fallo (.saf-copy-error, ver "
               "boot.log); sin datos, modo clear + quad");
      return;
    }
  }
}

void HandleCmd(struct android_app* app, int32_t cmd) {
  auto* state = static_cast<AppState*>(app->userData);
  switch (cmd) {
    case APP_CMD_INIT_WINDOW:
      if (app->window != nullptr) {
        state->window_ready = state->renderer.Init(app->window);
        if (state->window_ready) {
          // Tamano para el layout tactil Fase 13.
          state->runtime.InputState()->SetViewportSize(
              ANativeWindow_getWidth(app->window),
              ANativeWindow_getHeight(app->window));
          state->runtime.Init();
          if (!TryLoadData(app, state)) {
            SFA_LOGI("native: sin datos sfa-data (modo clear + quad "
                     "de prueba; ver PORT-STATUS, via de datos)");
            // Fase 13: primer arranque sin datos -> picker SAF.
            // Solo una vez por ejecucion; cancelar no reintenta.
            if (!state->saf_requested) {
              state->saf_requested = true;
              RequestSafPicker(app);
            }
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
  // Fase 6b/13: los eventos llegan al Input del runtime (que
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
    // Sin juego cargado: vigilar el resultado de la copia SAF.
    // OJO: IsRunning() es true desde Init() aunque no haya juego
    // (el stub de la base tambien "corre"); el guarda correcto
    // es IsGameLoaded(), no IsRunning().
    if (state.window_ready && state.has_focus &&
        !state.runtime.IsGameLoaded() &&
        (++state.poll_counter % 128) == 0) {
      PollSafResult(app, &state);
    }
    if (state.window_ready && state.has_focus &&
        state.runtime.IsRunning()) {
      state.runtime.Frame(&state.renderer);
    }
  }
}
