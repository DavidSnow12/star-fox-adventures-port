# Base del port Android — rama `android-port-base`

Rama de trabajo para la base del port Android de Star Fox Adventures
(GameCube, GSAP01 Rev 1), en el repositorio privado
`DavidSnow12/star-fox-adventures-port`. Uso personal, no distribución.

Esta rama **no** es un juego jugable. Es la base compilable sobre la que
se integrará después el runtime: Activity nativa, loop principal, log de
arranque, y módulos stub para runtime de GameCube, renderer, audio,
input y plataforma.

## Qué hay ya en el repo (rama `main`)

- Recompilación DolRecomp de `main.dol`: 718.864 instrucciones,
  176 chunks C, gcc 176/176, `symbols.map` con 24.957 símbolos,
  `generated_symbols.h` con 9.591 símbolos ejecutables.
- 107 rangos de código automodificable (SMC) en `generated_smc.txt`.
- Entry `0x80003140`, BSS `0x803371A0` (tamaño `0xB2CB8`).
- Assets extraídos completos (textos, texturas, audio, vídeo, modelos).
- Documentación completa en `PLAN.md`, `ESTADO.md`, `EXTRACCION.md`.

## Estructura de la base

```
app/
  build.gradle                 Módulo Android (arm64-v8a, minSdk 26)
  src/main/AndroidManifest.xml Actividad nativa, orientación horizontal
  src/main/java/com/starfox/port/MainActivity.java
                               NativeActivity; el trabajo real está en C++
  src/main/cpp/CMakeLists.txt  libstarfox.so + native_app_glue
  src/main/cpp/native-lib.cpp  android_main: eventos, loop, frame
  src/main/cpp/log.h           Macros de log (logcat + boot.log)
  src/main/cpp/gamecube_runtime/
    runtime.h/.cpp             Estado del runtime, init/frame/shutdown
    cpu.h/.cpp                 CPU Gekko: STUB (sin dispatch aún)
    memory.h/.cpp              Mapa de memoria GC, RAM 24 MiB, SMC stub
  src/main/cpp/renderer/
    renderer.h/.cpp            EGL + GLES3: init/resize/frame (clear)
  src/main/cpp/audio/
    audio.h/.cpp               Audio: STUB (MusyX/DSP pendientes)
  src/main/cpp/input/
    input.h/.cpp               Táctil -> mando: STUB
  src/main/cpp/platform/
    platform.h/.cpp            Assets (AAssetManager) y boot.log
  src/main/assets/README.md    Los datos del juego se preparan después;
                               NO se copian aquí los assets extraídos.
  src/main/res/values/strings.xml
build.gradle / settings.gradle / gradle.properties
gradle/wrapper/gradle-wrapper.properties
```

## Qué NO hace todavía (honesto)

- No ejecuta el código recompilado de DolRecomp: `cpu.cpp` es un stub
  que registra el PC inicial y no despacha funciones. La integración
  real (dispatch por nombre con `generated_symbols.h`, o
  post-procesado de chunks) es el siguiente bloque de trabajo.
- No hay GX real: el renderer solo limpia la pantalla con GLES3.
- No hay DSP/MusyX: el audio es un stub que no suena.
- No carga `main.dol` ni los datos del juego: `memory.cpp` reserva la
  RAM y rechaza la carga con un log claro hasta que el cargador exista.
- No hay sistema de objetos/DLLs/mapas/animaciones.
- Los assets extraídos (cerca de 2 GB) no van dentro del APK en esta
  base; su empaquetado y carga se decidirán en la fase de integración
  (ver `PLAN.md` de la rama `main`).

## Compilar (Windows, Android Studio)

1. Abrir este repositorio en Android Studio (la carpeta raíz del repo
   no es el proyecto: el módulo está en `app/`; usar
   `File > Open` sobre la carpeta que contiene `settings.gradle` de
   esta rama, o importar el módulo).
2. Instalar con el SDK Manager: Android SDK Platform 34, NDK r28c,
   CMake 3.22+.
3. `Build > Make Project` o desde la terminal:
   `gradlew assembleDebug`
4. El APK de depuración queda en
   `app/build/outputs/apk/debug/app-debug.apk`.

Requisito en el dispositivo (Android 16, p. ej. Tab S8): conceder
manualmente el acceso a archivos si la futura carga de datos lo pide,
antes del primer arranque.

## Validación hecha en esta base

- C++ nativo compilado para arm64-v8a con el NDK r28c (clang, API 26)
  y enlazado como `libstarfox.so`: objetos `EM_AARCH64`, sin errores.
- `AndroidManifest.xml` bien formado (XML válido).
- `MainActivity.java` compila con `javac` contra un stub de
  `NativeActivity` (aquí no hay Android SDK, así que la compilación
  completa con Gradle/Android Studio queda pendiente en Windows).
- No hay runtime Android en este entorno: no se ha ejecutado la app
  ni se ha probado en dispositivo. El primer arranque en dispositivo
  debe revisarse con el `boot.log` que la app escribe en su carpeta
  interna y con `logcat`.

## Aportación de la IA de GitHub, integrada en esta base

El 2026-10-25 se pidió análisis a la IA de GitHub (chat del repo) y
se integró lo útil antes del push. No creó archivos ni modificó el
repo; el trabajo es conjunto: su análisis, mi implementación y
validación.

Integrado:
- **Dispatch por nombre**: `gamecube_runtime/symbol_dispatch.*`
  (lookup por nombre, sin tocar el C de DolRecomp, solo tabla mínima
  de arranque; no se resuelven los 9.591 símbolos de golpe).
- **Separación guest/host**: `GCMemory::GuestToHost()`; el juego
  nunca se ejecuta en direcciones guest 0x8000... reales del proceso
  ARM64, la RAM guest vive en un buffer host.
- **Tabla SMC**: `gamecube_runtime/smc_ranges.*` (catálogo de los
  107 rangos; Apply solo registra en esta base, sin modificar código
  ejecutado y sin flush de caché todavía).
- **API limpia de audio**: `Start/Stop/SubmitBuffer/SetMasterVolume`
  como stub, para que MusyX/DSP sustituya el backend sin tocar el loop.
- **Renderer**: `DrawQuad()` como primer paso útil (clear + quad)
  antes de cualquier GX real; GLES3 en esta base (arm64, API 26+).
- **Orden de integración y riesgos**: memoria guest -> dispatch ->
  chunks y SMC -> renderer -> audio -> input -> assets solo cuando
  el runtime base esté estable; riesgos: guest sin traducir, resolver
  todos los símbolos de golpe, patches SMC sin flush, mezclar
  lifecycle Android con el loop del juego, MusyX antes del runtime
  mínimo, GX completo antes del modelo de memoria.

No adoptado todavía, con motivo (no ignorado):
- **Java Activity + SurfaceView + JNI en lugar de NativeActivity**:
  la IA de GitHub lo recomienda como base más robusta a largo plazo
  (pause/resume, pérdida de surface, menús, permisos). Esta base
  sigue con NativeActivity porque ya está validada para arm64 y su
  ciclo de vida se gestiona explícitamente en `native-lib.cpp`
  (INIT/TERM_WINDOW, GAINED/LOST_FOCUS, DESTROY). Cambiar a Java +
  SurfaceView es una decisión de la siguiente iteración, no un
  cambio silencioso en esta base: si se hace, MainActivity dejará de
  heredar de NativeActivity y expondrá callbacks JNI de surface,
  y el loop nativo pasará a ser llamado desde Java.

## Siguiente bloque (después de esta base)

1. Cargador de `main.dol` + RAM/BSS en direcciones exactas.
2. Dispatch de funciones DolRecomp por nombre (`generated_symbols.h`).
3. Tratamiento SMC (107 rangos) y datos embebidos en código.
4. GX -> GLES real (al menos clear + triángulos de prueba con datos
   del juego) y DSP/MusyX.
5. Carga de datos y primer frame real, con `boot.log` como diagnóstico.
