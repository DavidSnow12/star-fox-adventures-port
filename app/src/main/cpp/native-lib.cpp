// Punto de entrada nativo de la base del port (NativeActivity).
//
// Ciclo de vida mínimo y honesto:
//   - APP_CMD_INIT_WINDOW: inicializa renderer + runtime, fija el
//     tamano de ventana para el layout tactil, y carga datos si
//     existen (o pide el picker SAF si no existen, Fase 13).
//   - APP_CMD_TERM_WINDOW / APP_CMD_DESTROY: apaga en orden.
//   - APP_CMD_GAINED_FOCUS / LOST_FOCUS: pausa/reanuda el frame.
//   - Rumble fase B: APP_CMD_PAUSE y LOST_FOCUS detienen el
//     rumble sin apagar el runtime (StopAllRumble: cancela
//     el Vibrator y resetea el tracker, asi que reanudar
//     vuelve a vibrar); TERM_WINDOW / DESTROY /
//     destroyRequested apagan el runtime y su Shutdown()
//     vuelve a cancelar. La capa Java (onPause/onDestroy)
//     cancela ademas por su lado: doble garantia.
//   - Sin ventana o sin foco: no se dibuja, se espera eventos.
//   - Input: se entrega al módulo Input (que escribe el
//     PadState que PADRead vuelca al juego).
//
// Via de datos (ver PORT-STATUS):
//   <base>/sfa-data/sys/main.dol + <base>/sfa-data/files/...
//   base = internalDataPath o externalDataPath (interna
//   preferida, la misma que usa SetCardPath para memcard-a.raw).
//   Sin datos: clear + quad de prueba, sin fallo. Con picker
//   Boton "anadir audio" (Tramo 6, via nativa): la pildora
//   inferior-centro (input/audio_button.h) la intercepta
//   Input ANTES que el layout del juego; su disparo lo drena
//   el bucle principal y llama a RequestSafAudioPicker (el
//   mismo JNI/SAF ya probado del Tramo 5). El estado visible
//   (sin audio / verificando / audio listo / error) NO se
//   adivina: se deriva de marcadores — .saf-audio-done y el
//   nuevo .saf-audio-error que Java escribe al fallar — mas
//   un escaneo inicial de audio/ (un Pack B que ya trajera
//   audio no tiene marcador y debe verse como listo). El
//   sondeo corre TAMBIEN con el juego cargado (a diferencia
//   de PollSafResult, que solo vigila sin juego): anadir
//   audio a mitad de sesion es el caso de uso. Nada bloquea
//   el loop: el picker es async (runOnUiThread + hilo de
//   fondo Java) y el sondeo son dos fopen cada 128 vueltas.
//   SAF (Fase 13): si no hay datos en el primer arranque, se
//   pide la carpeta al usuario por JNI; cuando Java termina la
//   copia y escribe .saf-copy-done, el bucle principal carga
//   el juego sin reiniciar la app. Si el usuario cancela, no
//   se vuelve a pedir en esta ejecucion (evita un bucle de
//   pickers); la app sigue en clear + quad.

#include <android_native_app_glue.h>
#include <jni.h>

#include <cstdio>
#include <cstring>
#include <string>

#include <dirent.h>
#include <sys/stat.h>

#include <android/native_window.h>

#include "gamecube_runtime/rumble_jni.h"
#include "input/audio_button.h"
#include "input/audio_state_fs.h"
#include "gamecube_runtime/runtime.h"
#include "log.h"
#include "platform/platform.h"
#include "renderer/renderer.h"

namespace {

struct AppState {
  sfa::GameCubeRuntime runtime;
  sfa::Renderer renderer;
  // Rumble fase B: vive en AppState (no en el runtime) porque
  // necesita vm + actividad del glue, que el runtime no
  // conoce. Se inyecta en el HLE en INIT_WINDOW y sobrevive
  // a Shutdown(): el runtime solo guarda el puntero, como
  // con el PadState de Input. Sin actividad/JVM, Ready() es
  // false y el sink es inerte (no-op, sin crash).
  sfa::JniVibratorSink rumble_sink;
  bool has_focus = false;
  bool window_ready = false;
  bool data_found = false;   // existe sfa-data/sys/main.dol
  bool load_tried = false;   // LoadGame ya intentado con datos
  bool saf_requested = false;
  bool saf_done_seen = false;
  bool saf_error_seen = false;
  int poll_counter = 0;
  // Tramo 6 — estado del boton de audio (ver audio_button.h).
  // Verifying es volatil por ejecucion: nunca se persiste y
  // se rederiva en INIT_WINDOW (InitAudioState). Los *_seen
  // evitan re-loguear el mismo marcador en cada sondeo.
  sfa::AudioState audio_state = sfa::AudioState::kNoAudio;
  bool audio_done_seen = false;
  bool audio_error_seen = false;
  int audio_poll_counter = 0;
  // Tramo 10: sondeo del disparador de captura de frame
  // (marcador, ver PollFrameCaptureRequest).
  int capture_poll_counter = 0;
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
    // Fase 14 — bridge de audio: <base>/sfa-data/audio con
    // streams/... y musyx/... (payload futuro del Pack B).
    // Sin esa carpeta, el bridge es inerte (peticiones no
    // resueltas, juego intacto).
    state->runtime.SetAudioWavRoot(
        (std::string(base) + "/sfa-data/audio").c_str());
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

// Pide el picker SAF de audio a MainActivity por JNI
// ("anadir audio", Tramo 5): mismo patron que
// RequestSafPicker, pero metodo requestAudioFolder().
// Tramo 6: YA TIENE llamador (la pildora nativa: el bucle
// drena TakeAudioButtonTrigger() y llama aqui). Devuelve
// true solo si el picker quedo solicitado; false pone al
// boton en Error (sin activity/JVM, sin metodo, excepcion
// JNI). No se auto-dispara nunca: solo responde al toque
// del usuario en la pildora. La via Java (picker -> copia
// solo-audio -> verificacion -> .saf-audio-done, y ahora
// .saf-audio-error al fallar) esta completa y el juego ya
// cargado lee el audio nuevo en vivo (el bridge reconstruye
// su indice ADP al primer fallo de busqueda).
bool RequestSafAudioPicker(struct android_app* app) {
  if (app->activity == nullptr || app->activity->vm == nullptr ||
      app->activity->clazz == nullptr) {
    SFA_LOGE("native: SAF audio no disponible (sin activity/JVM)");
    return false;
  }
  JavaVM* vm = app->activity->vm;
  JNIEnv* env = nullptr;
  bool attached = false;
  if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) !=
      JNI_OK) {
    if (vm->AttachCurrentThread(&env, nullptr) != JNI_OK || env == nullptr) {
      SFA_LOGE("native: SAF audio: no se pudo asociar el hilo a la JVM");
      return false;
    }
    attached = true;
  }
  jclass cls = env->GetObjectClass(app->activity->clazz);
  if (cls == nullptr) {
    SFA_LOGE("native: SAF audio: sin clase de actividad");
    if (attached) vm->DetachCurrentThread();
    return false;
  }
  jmethodID mid = env->GetMethodID(cls, "requestAudioFolder", "()V");
  if (mid == nullptr) {
    SFA_LOGE("native: SAF audio: metodo requestAudioFolder no encontrado");
    if (attached) vm->DetachCurrentThread();
    return false;
  }
  env->CallVoidMethod(app->activity->clazz, mid);
  bool ok = true;
  if (env->ExceptionCheck()) {
    env->ExceptionClear();
    SFA_LOGE("native: SAF audio: excepcion al pedir el picker");
    ok = false;
  } else {
    SFA_LOGI("native: SAF audio: picker solicitado (anadir audio, "
             "sin reimportar sys/ ni files/)");
  }
  if (attached) vm->DetachCurrentThread();
  return ok;
}

// --- Estado del boton de audio, Tramo 6 (sin bloquear) ---
// IsAudioMediaFile / AudioDirHasMedia viven en
// input/audio_state_fs.h (POSIX, sin Android): el mismo
// codigo lo compila NDK y lo ejercita el test host.

void SetAudioState(AppState* state, sfa::AudioState next) {
  state->audio_state = next;
  state->runtime.InputState()->SetAudioButtonState(next);
  SFA_LOGI("native: audio-btn: estado %s", sfa::AudioStateName(next));
}

// Derivacion inicial (INIT_WINDOW, una sola vez): done ->
// listo; si no, audio/ con medios (Pack B con audio, o una
// copia anterior sin marcador) -> listo; si no, sin audio.
// Nunca Verifying al arrancar: una copia interrumpida por
// cierre no deja un estado atascado (ver audio_button.h).
void InitAudioState(struct android_app* app, AppState* state) {
  std::string internal = sfa::InternalDataPath();
  const char* bases[2] = {nullptr, nullptr};
  if (!internal.empty()) bases[0] = internal.c_str();
  if (app->activity != nullptr &&
      app->activity->externalDataPath != nullptr) {
    bases[1] = app->activity->externalDataPath;
  }
  for (const char* base : bases) {
    if (base == nullptr) continue;
    std::string root = std::string(base) + "/sfa-data";
    if (FileExists(root + "/.saf-audio-done")) {
      state->audio_done_seen = true;
      SetAudioState(state, sfa::AudioState::kReady);
      return;
    }
    if (sfa::AudioDirHasMedia(root + "/audio")) {
      SetAudioState(state, sfa::AudioState::kReady);
      return;
    }
  }
  SetAudioState(state, sfa::AudioState::kNoAudio);
}

// Sondeo de marcadores de audio (cada 128 vueltas del bucle,
// CON juego cargado o sin el). done -> listo; error -> error.
// Un marcador ya visto no re-loguea. No lee el contenido:
// Java solo escribe .saf-audio-done tras verificar, y
// .saf-audio-error solo al fallar (ver MainActivity).
void PollAudioResult(struct android_app* app, AppState* state) {
  std::string internal = sfa::InternalDataPath();
  const char* bases[2] = {nullptr, nullptr};
  if (!internal.empty()) bases[0] = internal.c_str();
  if (app->activity != nullptr &&
      app->activity->externalDataPath != nullptr) {
    bases[1] = app->activity->externalDataPath;
  }
  for (const char* base : bases) {
    if (base == nullptr) continue;
    std::string root = std::string(base) + "/sfa-data";
    // Tramo 6 — cancelacion: Java escribe .saf-audio-cancelled
    // cuando el usuario cancela el picker (ver MainActivity).
    // Se consume (borra) y se rederiva: sin el, cancelar
    // dejaria la pildora en Verificando hasta reiniciar,
    // porque "sin marcador" tambien significa "copia en
    // curso" y el sondeo no puede distinguirlos. El orden
    // importa: cancelado se comprueba ANTES que done, pero
    // done solo lo escribe Java tras verificar, nunca tras
    // cancelar, asi que no hay carrera entre ambos.
    if (FileExists(root + "/.saf-audio-cancelled")) {
      std::remove((root + "/.saf-audio-cancelled").c_str());
      if (FileExists(root + "/.saf-audio-done")) {
        state->audio_done_seen = true;
        SetAudioState(state, sfa::AudioState::kReady);
      } else if (sfa::AudioDirHasMedia(root + "/audio")) {
        SetAudioState(state, sfa::AudioState::kReady);
      } else {
        SetAudioState(state, sfa::AudioState::kNoAudio);
      }
      return;
    }
    if (!state->audio_done_seen && FileExists(root + "/.saf-audio-done")) {
      state->audio_done_seen = true;
      SetAudioState(state, sfa::AudioState::kReady);
      return;
    }
    if (!state->audio_error_seen &&
        FileExists(root + "/.saf-audio-error")) {
      state->audio_error_seen = true;
      SetAudioState(state, sfa::AudioState::kError);
      return;
    }
  }
}

// Tramo 10: disparador EXPLICITO de captura de frame
// (RequestFrameCapture, Tramo 9). NUNCA automatico por
// frame: solo cuando existe el marcador
//   <internalDataPath>/captura-frame-pedida
// cuyo contenido (una linea) es la etiqueta de escena.
// Activacion hoy (sin boton Java todavia; el coordinador
// puede anadir un boton de depuracion que escriba el
// marcador, con el mismo efecto):
//   adb shell "echo -n titulo > /data/data/com.starfox.port/files/captura-frame-pedida"
// (ruta interna segun InternalDataPath; en el dispositivo
// real es files/ de la app). El sondeo borra el marcador
// ANTES de pedir la captura, asi que un solo marcador da
// una sola captura (sin re-disparos en sondeos posteriores
// ni capturas en bucle). Seguridad: solo con ventana+foco
// y juego cargado (el llamador lo garantiza); escena
// vacia, ilegible o con caracteres fuera de [A-Za-z0-9_-]
// se descarta (marcador borrado, log, sin captura); la
// salida va a <internalDataPath>/capturas (el runtime crea
// frame_<N>/ dentro; dir y escena nulos/vacios ya se
// ignoran en RequestFrameCapture). Sin juego, el marcador
// NO se consume: queda para cuando el juego este cargado
// (evita perder la peticion por sondear demasiado pronto).
void PollFrameCaptureRequest(struct android_app* app, AppState* state) {
  (void)app;  // El marcador vive en internalDataPath, no en app.
  if (!state->runtime.IsGameLoaded()) return;
  std::string internal = sfa::InternalDataPath();
  if (internal.empty()) return;
  std::string marker = internal + "/captura-frame-pedida";
  std::FILE* f = std::fopen(marker.c_str(), "rb");
  if (f == nullptr) return;
  char buf[128];
  size_t n = std::fread(buf, 1, sizeof(buf) - 1, f);
  std::fclose(f);
  buf[n] = '\0';
  // Borrar ANTES de validar: un marcador = una captura como
  // maximo, aunque la escena sea invalida.
  std::remove(marker.c_str());
  std::string scene;
  for (size_t i = 0; i < n; ++i) {
    char c = buf[i];
    if (c == '\n' || c == '\r') break;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9') || c == '_' || c == '-') {
      scene.push_back(c);
    } else if (c == ' ' || c == '\t') {
      // Espacios: se ignoran (no se convierten en guion:
      // la etiqueta debe ser exactamente la escrita, sin
      // caracteres extranos).
      continue;
    } else {
      scene.clear();
      break;
    }
    if (scene.size() >= 64) break;
  }
  if (scene.empty()) {
    SFA_LOGI("native: captura-frame: marcador descartado "
             "(escena vacia o invalida)");
    return;
  }
  std::string dir = internal + "/capturas";
  state->runtime.RequestFrameCapture(dir.c_str(), scene.c_str());
  SFA_LOGI("native: captura-frame: pedida (escena %s, dir %s)",
           scene.c_str(), dir.c_str());
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
          // Rumble fase B: inyectar el sink JNI en el HLE
          // (idempotente en re-INIT_WINDOW: mismo puntero).
          // Init() solo guarda vm/actividad, no vibra.
          if (app->activity != nullptr) {
            state->rumble_sink.Init(app->activity->vm,
                                    app->activity);
            state->runtime.HleState()->SetRumbleSink(
                &state->rumble_sink);
          }
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
          // Tramo 6: estado inicial de la pildora de audio
          // (tras runtime.Init, que resetea Input sin borrar
          // el estado — ver audio_button.h — y tras la carga
          // de datos, por si el Pack B ya trae audio/).
          InitAudioState(app, state);
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
    case APP_CMD_PAUSE:
      // Rumble fase B: pausar detiene el motor sin apagar el
      // runtime (el juego puede reanudar y re-vibrar: el
      // tracker queda reseteado). La capa Java onPause
      // cancela ademas por su lado.
      state->runtime.StopAllRumble();
      break;
    case APP_CMD_GAINED_FOCUS:
      state->has_focus = true;
      break;
    case APP_CMD_LOST_FOCUS:
      state->has_focus = false;
      // Sin foco el bucle ya no ejecuta frames: el motor no
      // debe seguir vibrando por un RUMBLE anterior.
      state->runtime.StopAllRumble();
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
    // Tramo 6 — pildora "anadir audio": drenar el disparo en
    // CADA vuelta (respuesta inmediata, sin esperar al %128)
    // y sondear marcadores cada 128, CON juego cargado o sin
    // el. Sin ventana/foco el disparo se descarta (el picker
    // no debe abrirse con la app en pausa; el usuario puede
    // volver a pulsar). Al pulsar: se borran los marcadores
    // viejos ANTES de poner Verifying — si no, el sondeo
    // podria ver el .saf-audio-done anterior antes de que el
    // hilo Java lo borre y marcar Listo durante la copia
    // nueva (Java tambien los borra al empezar a copiar:
    // doble guarda). Mientras Verifying, Input ya traga los
    // toques en la pildora sin re-disparar (ver
    // audio_button.h); aqui el guarda es por si acaso.
    if (state.runtime.InputState()->TakeAudioButtonTrigger()) {
      if (!state.window_ready || !state.has_focus) {
        SFA_LOGI("native: audio-btn: disparo descartado (sin "
                 "ventana/foco; volver a pulsar con la app "
                 "en primer plano)");
      } else if (state.audio_state == sfa::AudioState::kVerifying) {
        SFA_LOGI("native: audio-btn: disparo ignorado (copia "
                 "de audio ya en marcha)");
      } else {
        std::string internal = sfa::InternalDataPath();
        const char* bases[2] = {nullptr, nullptr};
        if (!internal.empty()) bases[0] = internal.c_str();
        if (app->activity != nullptr &&
            app->activity->externalDataPath != nullptr) {
          bases[1] = app->activity->externalDataPath;
        }
        for (const char* base : bases) {
          if (base == nullptr) continue;
          std::string root = std::string(base) + "/sfa-data";
          std::remove((root + "/.saf-audio-done").c_str());
          std::remove((root + "/.saf-audio-error").c_str());
          std::remove((root + "/.saf-audio-cancelled").c_str());
        }
        state.audio_done_seen = false;
        state.audio_error_seen = false;
        SetAudioState(&state, sfa::AudioState::kVerifying);
        if (!RequestSafAudioPicker(app)) {
          SetAudioState(&state, sfa::AudioState::kError);
        }
      }
    }
    if (state.window_ready && state.has_focus &&
        (++state.audio_poll_counter % 128) == 0) {
      PollAudioResult(app, &state);
    }
    // Tramo 10: sondeo del marcador de captura (cada 128,
    // con ventana+foco; PollFrameCaptureRequest exige
    // ademas juego cargado y no consume sin el).
    if (state.window_ready && state.has_focus &&
        (++state.capture_poll_counter % 128) == 0) {
      PollFrameCaptureRequest(app, &state);
    }
    if (state.window_ready && state.has_focus &&
        state.runtime.IsRunning()) {
      state.runtime.Frame(&state.renderer);
    }
  }
}
