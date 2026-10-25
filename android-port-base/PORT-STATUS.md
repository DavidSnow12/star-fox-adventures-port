# Estado del port Android — rama `android-port-base`

**Fecha de este estado: 2026-10-25. Uso personal, repo privado, NO distribución.**

## Resumen honesto

**La app NO es jugable todavía.** Lo que hay es una base compilable
más el runtime verificado en host: el juego ya NO se queda en el
arranque — en host ejecuta su arranque completo, carga los 89
ficheros base por DVD, pasa audio/DSP/ARAM y entra en su bucle de
frames estable (ver «Fase 5» abajo: 5.000.000 despachos sin
exception, 1.789.482 escrituras FIFO GX, encuesta PAD por frame).
No hay APK jugable en el repo ni renderer: sin GPU, el bucle
emite comandos GX que nadie dibuja todavía. Cuando haya APK
jugable, se anunciará aquí con su commit, tamaño y SHA, y solo
entonces merece la pena descargarla para probar el juego.

## Qué funciona (verificado)

- Base Android: NativeActivity, `android_main`, loop, ciclo de vida
  (ventana/foco/destrucción), log con `boot.log`.
- C++ nativo para arm64-v8a con NDK r28c: enlaza como `libstarfox.so`
  (AArch64, `android_main` exportado). Revalidado en este tramo con
  los ficheros nuevos (12 C++ + glue).
- **Fase 1 — Shim global y enlace de chunks (NUEVO, verificado):**
  ver la sección «Fase 1 — Shim `cpu/cpu.h` y enlace de chunks»
  más abajo. En resumen: `generated.c` + 176 chunks compilan para
  arm64 con NDK r28c (0 errores) y enlazan en `libstarfox.so` con
  **cero símbolos de shim/chunks sin resolver** (176 `func_*` en
  `T`, `mem_*`/`ppc_*` en `T`, `dolrecomp_call_depth` en `B`).
  El runtime sigue siendo stub: el juego todavía NO se ejecuta
  (falta el dispatch real desde `0x80003140` y el HLE).
- **Fase 1 — Cargador DOL (NUEVO, verificado en host):**
  `gamecube_runtime/dol_loader.*` parsea la cabecera DOL (offsets,
  direcciones y tamaños big-endian), copia 2 secciones text y 8 data
  en sus direcciones guest exactas, pone el BSS a cero y devuelve la
  entry. Test host con el `main.dol` real (solo lectura):
  entry `0x80003140`, text 2 secciones / 2.875.456 B, data 8 secciones
  / 529.888 B, palabra en entry `0x48000139`, BSS primero y último a
  cero. RESULTADO: PASS.
- **Memoria guest (NUEVO):** `cpu_state.h` con todos los campos que
  usan los chunks (gpr, fpr, ps1, cr, xer, lr, ctr, pc, gqr, msr,
  fpscr, srr, sr, hid2, ear, downcount, exception), `mem.*` con
  lecturas/escrituras 8/16/32/64 big-endian, traducción guest->host
  (nunca puntero guest directo), registros hardware 0xCC00xxxx que
  devuelven 0 sin exception, y fuera de rango que marca exception.
  Test host: roundtrip 8/16/32/64 exacto. PASS.
- **Dispatch (NUEVO):** `symbol_dispatch` ahora con tabla guest:
  `RegisterGuestBoot()` registra 7 símbolos de arranque con
  direcciones verificadas en `generated_symbols.h` (__start,
  __init_registers, __init_data, __init_hardware, __flush_cache,
  memset, memcpy). Lookup desconocido devuelve 0, no inventa.
- **SMC (NUEVO):** `SmcTable::LoadFromText()` parsea
  `generated_smc.txt`: 107 rangos exactos cargados (la mayoría una
  sola dirección, rangos inclusivos), con `IsInSmcRange` verificado
  en 0x80003390 y en 0x8024B670. Apply sigue siendo solo registro,
  sin modificar código ejecutado ni flush de caché todavía.
- Renderer EGL/GLES3: clear + `DrawQuad` stub. Audio: API limpia
  (Start/Stop/SubmitBuffer/SetMasterVolume) sin sonido. Input: primer
  evento táctil registrado, sin mapeo a mando todavía.
- **Fase 5 — Bucle de juego en host (NUEVO, verificado):**
  desbloqueos AR/AI/DSP/ARAM/hilos (ver sección «Fase 5»),
  carga DVD completa (89 ficheros) y bucle de frames estable
  sin exception (run14). GX por HLE empezado (`GXLoadTexObj`
  registrado); texturas y renderer, pendientes (sin maquillar).

## Qué NO funciona todavía (bloqueadores, sin maquillar)

1. **~~Dispatch real y HLE pendientes (bloqueador actual nº 1):~~
   HECHO en Fases 2–5:** el juego ejecuta su arranque completo
   y su bucle de frames en host (ver «Fase 5»). El bloqueador
   actual nº 1 es el renderer GX + texturas (sin ellos, el
   bucle emite comandos que nadie dibuja).
2. **HLE completo pendiente:** GX (máquina de estado y
   display lists), callback async de DVD, struct PADStatus,
   audio DSP real, planificador de hilos real. El HLE actual
   cubre arranque + eventos DSP/ARQ + sueño instantáneo.
3. **GX real pendiente:** solo clear. Falta la máquina de
   estado GX, display lists interpretadas y texturas
   convertidas (CMPR/RGB5A3/RGBA8 ya extraídas) para un
   frame real.
4. **Audio MusyX/DSP pendiente:** backend AAudio/OpenSL sin
   implementar, sin mezcla ni streams.
5. **Input pendiente:** sin mapeo táctil a stick/botones/gatillos ni
   gamepad.
6. **Datos sin empaquetar:** no hay paquete de datos para el test.
   La APK no meterá 2 GB; la vía (APK pequeña + datos aparte) está
   por decidir con tamaños reales y pasos de instalación.
7. **Sin Android SDK aquí:** no hay `aapt2/d8/apksigner/zipalign` ni
   Gradle en este entorno. La APK de este tramo no se ha construido;
   su build y validación (`apksigner verify`, `zipalign`, manifiesto
   con `apktool`) quedan pendientes de instalar cmdline-tools o de
   la vía manual de la skill local.
8. **Sin ejecución en dispositivo:** no hay runtime Android aquí.
   Todo lo anterior es validación en host/NDK, no una prueba de
   juego en la Tab S8.

## APK de prueba de arranque (Fase 0) — NO JUGABLE, solo arranque

**Fichero en esta rama:** `android-port-base/app-debug-boot-test.apk`
**Tamaño:** 57.916 bytes
**SHA-256:** `b07a6af555246d442808208563efa8b0d423c7bd916aa9fc8938b1484bbf07d1`
**SHA-1:** `a2983836700f14a06f78d53e69e54aa186135f6a`
**Paquete:** `com.starfox.port`, versión 1 / `0.1.0-base`,
minSdk 26, targetSdk 34, actividad `MainActivity`,
`lib/arm64-v8a/libstarfox.so` (AArch64, 147.784 B).
**Validación:** `aapt2 dump badging` correcto,
`apksigner verify` OK (v2 y v3, 1 firmante),
`zipalign -c` OK. Construida por vía manual (javac/d8/aapt2/
apksigner/zipalign) porque Gradle falla en este entorno con
"Could not receive a message from the daemon" (daemon arranca y
queda en espera, el cliente no lee su mensaje; causa de entorno,
no del código). El build Gradle queda pendiente de resolver ese
fallo de daemon o de usar la vía manual documentada.
**Firma:** keystore de depuración generado para esta prueba
(autofirmada, no es una firma de release; al instalar pedirá
"Instalar apps desconocidas" una sola vez para la app instaladora).

**Qué hace al abrirla:** arranca NativeActivity, inicializa EGL/GLES3
y dibuja una pantalla de color fijo, escribe `boot.log` y registra
en logcat con la etiqueta `StarFoxPort`. **No hay juego:** no carga
DOL, no hay GX real, no hay sonido, no hay datos. Si se abre y se
queda en color fijo, ESO ES LO ESPERADO en esta fase, no un fallo
del juego.

**Instalación y prueba (Tab S8, Android 16):**
1. Descargar `app-debug-boot-test.apk` de esta rama (no de `main`).
2. Instalarla (permitir "Instalar apps desconocidas" solo para la
   app que instala, una vez).
3. Abrirla una vez, esperar unos segundos en la pantalla de color.
4. Leer el arranque:
   `adb shell run-as com.starfox.port cat files/boot.log`
   (funciona porque esta APK es debuggable) o
   `adb logcat -s StarFoxPort`.
5. Reportar: si abrió y qué color/pantalla se vio, las últimas
   líneas de `boot.log` / logcat, y si se cerró sola (con el log,
   no sin él).

**Qué NO es esta APK:** no es la APK jugable que el usuario
probará cuando el port esté al 100%. Esa APK todavía no existe y
se anunciará aquí, con su propio commit y SHA, cuando el runtime
integrado (chunks + HLE + GX + audio + datos) esté listo. No
confundir ambas: esta es solo la prueba de que la base arranca en
un dispositivo real.

## Permisos en Android 16 (para cuando llegue el test)

- Conceder manualmente el acceso a archivos si la carga de datos lo
  pide, antes del primer arranque (ajustes de la app, no se puede
  conceder desde dentro en Android 16 para todos los archivos).
- Sin permisos de red ni de cuentas: el port no los necesita.

## Dónde queda boot.log y qué reportar si falla

- `boot.log` queda en la carpeta interna de la app
  (`<internalDataPath>/boot.log`, accesible desde la app o con
  `adb` cuando haya puente). También queda `logcat` con la etiqueta
  `StarFoxPort`.
- Si la app se cierra al abrir, reporta: las últimas 20 líneas de
  `boot.log`, el modelo (Tab S8 SM-X700, Android 16), y si el
  paquete de datos estaba copiado o no. No adivines la causa: con
  ese log se ve hasta qué fase llegó (ventana, renderer, DOL,
  dispatch, primer bloque).

## Referencia Foxhollow / Aurora (licencia, verificada con reserva)

- Foxhollow oficial: `JackPriceBurns/foxhollow`, port nativo sobre
  SFA-Decomp + Aurora. Licencia en metadato GitHub: **CC0-1.0**,
  pero el texto íntegro de su `LICENSE` NO se leyó: **no copiar
  código suyo hasta leerlo**. SFA-Decomp también CC0 en metadato
  (misma reserva). Aurora es **MIT** (conservar su aviso si se copia
  algo de ella); SDL3/Dawn/nod/ImGui/RmlUi tienen licencias propias
  sin revisar.
- **No decir "Foxhollow soporta Android":** Aurora como framework
  sí declara Android (y tiene `platforms/android/`), pero Foxhollow
  como producto dice explícitamente que no hay planes de release
  para iOS/Android y solo está probado en Mac/Windows/Linux.
- Recomendación adoptada: Foxhollow/Aurora como **referencia de
  diseño**, no copia masiva. Este proyecto es DolRecomp, no
  decompilación SFA: el código no es intercambiable por copiar-pegar.
  Detalle en `work-port/apk-data/FOXHOLLOW-LICENCIA.md` (fuera del
  repo, trabajo local).

## Paquete de datos (vía decidida, tamaños reales)

- **APK pequeña (solo código) + paquete aparte, nunca 2 GB en el
  APK ni en Git.** El runtime debe leer el árbol nativo del disco,
  no los convertidos: `disc/files/` mide 785.986.556 B (786 MB,
  3.879 ficheros); sin `streams/` (546.308.096 B) queda **Pack B =
  239.678.460 B (240 MB)**. Los convertidos inflan ~3x
  (`assets/extraidos/` 2.327.541.630 B): audio WAV 1.984.462.826 B,
  texturas 148.137.941 B, modelos 131.000.028 B, vídeo 54.385.833 B,
  textos 9.555.002 B. No existe todavía una lista mínima verificada
  de ficheros para arrancar: se medirá cuando el runtime registre
  qué abre (Pack A -> Pack B -> recorte medido).
- Instalación en Tab S8 cuando el runtime exista: descarga del
  paquete desde su Drive a Descargas, selector SAF en primer arranque
  y copia a la carpeta privada de la app (`getExternalFilesDir()`).
  `adb push` directo a `Android/data/` puede no funcionar en
  Android 11+. Permisos: ninguno para carpeta privada ni SAF;
  "Instalar apps desconocidas" solo una vez para la app instaladora;
  NO `MANAGE_EXTERNAL_STORAGE`, NO `READ_MEDIA_*`.
- `boot.log` en debug se lee con
  `adb shell run-as com.starfox.port cat files/boot.log`; en release
  `run-as` falla, por eso las pruebas serán con build debug.

## Build APK (procedimiento, sin SDK todavía en este tramo)

- Sin SDK aquí: sin `aapt2/d8/apksigner/zipalign/gradle`, Java
  OpenJDK 21, NDK r28c ya presente (no reinstalar).
- Procedimiento documentado (ver `work-port/apk-data/APK-BUILD.md`):
  cmdline-tools en `~/tools/android-sdk/cmdline-tools/latest`,
  `sdkmanager "platform-tools" "platforms;android-34"
  "build-tools;34.0.0" "cmake;3.22.1"`, NDK r28c fijado
  (`ndkVersion "28.2.13676358"`), `./gradlew assembleDebug` ->
  `app/build/outputs/apk/debug/app-debug.apk`, firma debug
  automática. Riesgo sin probar: JDK 21 frente a AGP 8.3.2
  (documentado para JDK 17); si el primer build falla por JDK,
  opciones: JDK 17 con `org.gradle.java.home`, o subir AGP.

## Alcance HLE/GX/DSP/input (análisis verificado, trabajo local)

Análisis en `work-port/gx-scope/` (fuera del repo, solo lectura del
repo, sin modificarlo): conteos por grep en los 176 chunks y en
`symbols.map` (24.957 líneas, 24.945 direcciones distintas).

- **Contrato CPU:** gpr 940.106 usos, pc 714.808, downcount 144.810,
  cr 135.181, fpr 130.579, lr 64.198, ps1 50.652, xer 47.066, ctr
  11.413, exception 5.456; `mem_*` en total 274.147 usos
  (read32 107.456, write32 81.083, resto 8/16/64). Toda la interacción
  con el mundo pasa por esas 8 `mem_*`: si no distinguen RAM de
  hardware, nada más funciona.
- **Correcciones aplicadas de este análisis:** `CpuState` ahora
  incluye `host_call` (flag que `generated.h` consulta junto a
  `ppc_host_call`); `IsHardwareRegister` ampliado a 0xCC020000
  (CC00: 171 `lis`, CC01: 202 `lis`; antes CC01 caía en exception).
  Hardware no se escribe como literal en el C: se construye con
  `lis` decimal con signo, así que la intercepción correcta es en
  `mem_*`, no buscando literales.
- **Familias HLE:** GX 164, OS+__OS 130, DVD 39, EXI 26, CARD 23,
  SI 21, AI 17, DB 17, PAD 13, VI 11, DSP 10, THP 9, DC 7, LC 6,
  AR 5 + ARQ 2. Trampas evitadas: `ARW*` (44, Arwing del juego) no es
  ARAM; `AX*` = 0 (el juego no usa AX, su audio es MusyX propio:
  `synth*` 50, `snd*` 38, `Audio*` 117, `dsp*` 23 en minúscula).
- **Cadena de arranque verificada:** __start -> __init_registers ->
  __init_hardware -> __init_data -> DBInit -> OSInit -> __init_user
  -> main (0x800214A4) -> init (0x80020F8C) -> checkReset ->
  gameLoop (0x80020E2C). `init` llama en orden: OSInit, DVDInit,
  VIInit, PADInit, LCEnable, videoInit (GXInit 0x802556DC),
  audioInit, initLoadFiles, _initCardAndDsp. Por eso el primer HLE
  no es GX, es OS+DVD+VI+PAD+LC/DC en ese orden. Tabla guest de
  arranque+init ya registrada (7 + 12 símbolos).
- **GX mínimo:** por HLE sustituyendo funciones GX (no emulando el
  FIFO a nivel `mem_*` como primer paso): GXInit/FIFO, matrices/
  viewport, estado fijo, texturas (RGB5A3 11.036, CMPR 5.076 con
  reorden DXT1 o descompresión, RGBA8 1.134 con reentrelazado,
  IA8/I8/I4/IA4 a RGBA; sin paletas TLUT, 0 casos), TEV mínimo
  (1 etapa directa), GXBegin y luego display lists. Bloqueador:
  falta el mapa dirección-guest -> textura del disco (PNG indexados
  por banco/id, no por dirección de carga).
- **Audio:** streams ADP 958 WAV (32 kHz, 14.938 s), MusyX 1.472 WAV
  (1.548 s, frecuencias en inventario); secuencias MusyX NO
  reproducibles (`.pro`/`.poo`/`midi.wad` sin semántica). Primer paso:
  backend AAudio/OpenSL detrás de la API actual + WAV por ID, no DSP
  emulado.
- **Input:** `padUpdate` 0x80014F6C + globales
  `gPadButtonsHeld` 0x8033B220, `JustPressed` 0x8033B240, etc.
  Mapeo mínimo: stick izquierdo, A/B/X/Y/Z, L/R todo o nada,
  D-pad, Start, C-stick a 0, rumble no-op.
- **Bloqueador nº 1 anterior, RESUELTO en este tramo:** ya existe
  `cpu/cpu.h` global con el layout exacto de `CpuState` +
  `host_call`/`ram`/`ram_size` y las `mem_*` C enlazables; los 176
  chunks compilan y enlazan (ver la sección Fase 1 más abajo).
  El bloqueador que queda es el dispatch real + HLE (Fase 2).

## Fase 1 — Shim `cpu/cpu.h` y enlace de chunks (2026-10-25)

**Ficheros (rama `android-port-base`, este commit):**

- `app/src/main/cpp/cpu/cpu.h` — Cabecera C que exige
  `codigo/generated/generated.h` como `cpu/cpu.h`. Tipos
  `u8/u16/u32/u64/s8/s16/s32/s64/f32/f64`, constantes
  `GC_RAM_BASE` (0x80000000), `GC_RAM_UNCACHED`, `PPC_PROGRAM_TRAP`
  y resto de la ABI, y el `struct CPUState` en el **orden
  canónico de DolRecomp** (gpr, fpr, ps1, pc, lr, ctr, cr, xer,
  fpscr, msr, srr0, srr1, dar, dsisr, ear, hid2, timebase, sr,
  gqr, exception, program_exception, … , `host_call` como
  puntero `PPCHostCall` — no bool —, `ram`, `ram_size`,
  `downcount`, `cycle_budget`, hooks y MEM2). Todos los campos
  que los chunks usan por nombre están ahí, verificados por grep.
- `app/src/main/cpp/cpu/cpu.c` — Implementación C (sin mangling):
  las 8 `mem_read/write 8/16/32/64` big-endian, `dolrecomp_call_depth`
  (la única definición; `generated.h` la declara `extern`), y
  todos los `ppc_*` que emiten los chunks: FP escalar
  (`fadd(s)/fsub(s)/fmul(s)/fdiv(s)`, `fma`, `fctiw`, `fcmp`,
  `fres`, `frsqrte`, `frsp`), paired-single (`ps_add/sub/mul/div/
  madd/madds0/madds1/sum0/sum1/muls0/muls1/res/rsqrte`),
  `psq_load/store` (GQR tipos 0/4/5/6/7), excepciones
  (`program/system_call/dsi/alignment`, `rfi`, `trap_condition`,
  `fallback_instruction`, `host_call`, `mftb`, `dcbz_l`,
  `memory_fence`, `fpscr_updated`, …). Implementación propia
  para este port a partir de la semántica PPC/Gekko y de las
  firmas de DolRecomp (mismas firmas, no código copiado).
- `app/src/main/cpp/gamecube_runtime/cpu_state.h` — Ya NO es un
  segundo struct: es un alias (`sfa::CpuState = ::CPUState`).
  La versión anterior tenía otro orden, `exception` como `int`,
  `host_call` como `bool` y un `userdata` que nadie usaba; todo
  eso desapareció. Un solo tipo, sin divergencia posible.
- `app/src/main/cpp/gamecube_runtime/mem.cpp` — Los envoltorios
  C++ `MemRead*/MemWrite*` ahora delegan en las `mem_*` C, en
  vez de ser una segunda implementación. Semántica conservada
  (hardware 0xCC000000–0xCC020000 a 0 sin exception, fuera de
  rango con exception) más el alias sin cache 0xC0000000, que
  la versión anterior no aceptaba.
- `app/src/main/cpp/CMakeLists.txt` — `libstarfox.so` ya incluye
  `cpu/cpu.c`, `codigo/generated/generated.c` y los 176 chunks
  (GLOB con comprobación en configure: si no son 176, error
  fatal), con `-I` a `app/src/main/cpp` (para `cpu/cpu.h`) y a
  `codigo/generated` (para `generated.h` de `generated.c`).
  Los chunks NO se copiaron a `app/`: siguen en `codigo/`.
- `android-port-base/build-libstarfox-ndk.sh` — Build directo
  con el NDK sin Gradle, reutilizable: compila todo lo anterior
  y comprueba los undefined. Ojo, dos lecciones guardadas en el
  propio script: (1) `cpu/cpu.c` y `gamecube_runtime/cpu.cpp`
  NO pueden compartir `cpu.o` (el segundo sobrescribía al
  primero y el .so quedaba sin `mem_*`/`ppc_*`; el shim se
  llama `cpu_shim.o`); (2) la compilación C va en paralelo
  (`JOBS`, por defecto 2) porque en serie tarda ~30 min.

**Semántica de memoria (la del port, no la del ejemplo DolRecomp):**
RAM 0x80000000–0x81800000, alias sin cache 0xC0000000–0xC1800000
y forma física (offset < `ram_size`, la que `generated.h` aliasa
a `GC_RAM_BASE`); hardware 0xCC000000–0xCC020000 lee 0 / ignora
escrituras sin exception; fuera de rango lee 0 / ignora
escrituras con `exception = 1`.

**Cómo se compila (comando exacto usado en la verificación):**

```
./android-port-base/build-libstarfox-ndk.sh \
  ~/workspace/starfoxadventures/work-port/fase1-ndk-build
# = clang aarch64-linux-android26 (NDK r28c, API 26) -O2 -std=c11
#   (C) / -std=c++17 (C++), -I app/src/main/cpp -I codigo/generated,
#   enlace compartido con -landroid -llog -lEGL -lGLESv3 -lm
```

El `OUT` de la verificación vive en `work-port/fase1-ndk-build/`
(fuera del repo, no se commitea; el repo solo guarda el script).
Nota operativa: a mitad de este tramo `/tmp` se reinició y borró
el primer build y sus logs; la verificación se repitió entera
con `OUT` persistente y dio resultados idénticos.

**Resultado del enlace (verificado, no estimado):**

- `libstarfox.so`: 27.225.688 B, ELF64, `DYN`, `AArch64`,
  SHA-256 `210bfc7570ba53bfe60e2eb8d4df208e74bc73a957090db99ec9c027e7d4eaf6`.
- `android_main` en `T`, `dolrecomp_call_depth` en `B`,
  `func_80003100` y `func_802BE6E0` en `T`, `mem_read32` y
  `ppc_fadds` en `T`; **176 símbolos `func_*` en `T`**
  (uno por chunk).
- `nm -u` filtrado: **cero símbolos** que empiecen por
  `mem_`/`ppc_`/`func_`/`dolrecomp_` sin resolver. Los 109
  undefined restantes son solo de librerías del sistema:
  `android`/`log` (AAssetManager, ALooper, `__android_log_print`),
  EGL/GLESv3, libc/libm/pthread de bionic y runtime C++
  (`__cxa_*`, `operator new/delete`, `std::string`), que en el
  APK real aporta `libc++_shared`.
- Errores de compilación NDK `-O2`: **0**. Warnings (pasada
  aparte `-Wall -O0` sobre shim + generated + chunks + C++ de
  la app, 0 errores): solo **3**, todos `-Wunused-label` en
  código generado, inofensivos (labels `return_dispatch_*`
  definidas pero no usadas en los chunks 800A66E0, 800AA6E0 y
  800CE6E0); **0 warnings en `cpu/cpu.c` y 0 en el C++ de la app**.

**Tests host previos, repetidos en este tramo (TODO OK):**

- Test C (`work-port/fase1-tests/test_shim.c`, fuera del repo):
  42 checks — roundtrip BE 8/16/32/64, alias sin cache y físico,
  hardware a 0 sin exception, fuera de rango con exception,
  `dolrecomp_find_original` en entry/primer/último chunk y NULL
  en desconocida, `call_depth` inicial 0, `ppc_host_call` con y
  sin hook, FP (`fadds/fsubs/fmuls/fdivs/fadd`, `fres(4)=0.25`,
  `frsqrte(16)=0.25`, `fctiwz(3.75)=3`, `fcmp` LT/EQ, trap,
  `mftb` TBL/TBU), paired-single y PSQ f32 (carga par, `w=1`,
  almacén par, PSQ deshabilitado → programa ilegal) y
  excepciones (`sc` → pc 0xC00, trap → pc 0x700). Sin llamar a
  ninguna `func_*`: el juego NO se ejecutó.
- Test C++ (`work-port/fase1-tests/test_host.cpp`): alias
  `sfa::CpuState` idéntico a `::CPUState` (`static_assert` +
  `sizeof`), C++ y C leyendo/escribiendo el mismo estado, y el
  **cargador DOL previo sin cambios**: `main.dol` del repo
  (solo lectura), entry 0x80003140, text 2 / 2.875.456 B, data
  8 / 529.888 B, palabra en entry 0x48000139, BSS primero y
  último a cero. RESULTADO: TODO OK.
- **APK Fase 0 intacta:** este tramo no la reconstruye ni la
  toca (su fichero no aparece modificado en `git status`, 57.916 B
  sin cambios). El runtime ya tiene chassis + HLE en código, pero
  `Frame()` solo los usa cuando hay un juego cargado, y la APK
  Fase 0 nunca carga ninguno: su comportamiento de arranque no
  cambia. La APK con chunks llegará con el GX real, no antes.

**Fidelidad honesta de los `ppc_*` (límites de esta fase):**
la aritmética FP es doble plana con redondeo a f32 en las
instrucciones single (verificado: los `fpr` guardan dobles
planos iguales al f32, salvo payload NaN); `fres`/`frsqrte`
usan el recíproco exacto en vez de la estimación Gekko (el
código guest que refina con Newton converge igual; la
bit-exactitud de la estimación queda para la Fase 2). Nada de
esto está validado ejecutando el juego: solo enlaza y pasa
tests de unidad.

**Fase 2 resuelta en este tramo (ver sección "Fases 2–4" al
final):** el runtime ya conecta `Frame()` con el chassis de
dispatch real y el HLE mínimo de arranque; la ruta
`0x80003140 → main → init → videoInit` está verificada en
test host sin exception. Lo que queda es el GX real y la
frontera ARAM (ver abajo), no el dispatch.

## Orden que queda

1. ~~Dispatch real desde `0x80003140` + HLE mínimo de arranque
   (OS/GX/VI/DVD/SI) para que __start avance.~~ HECHO en este
   tramo (Fases 2–4, ver abajo): ruta a videoInit verificada y
   exploración hasta la frontera ARAM.
2. ~~GX real (primer frame) + ARAM/DSP (la frontera actual es
   `__ARChecksize` esperando el estado ARAM en `0xCC005016`) y
   luego input y carga de ficheros (DVD) hasta gameLoop.~~
   HECHO en Fase 5 (ver abajo): ARAM/DSP desbloqueados, DVD
   completo (89 ficheros) y bucle de juego alcanzado. Falta el
   frame real: máquina de estado GX + texturas + renderer.
3. Paquete de datos + build APK + validación + test en Tab S8.

## Fases 2–4 (este tramo): dispatch real, HLE mínimo y traza HW

Código nuevo: `gamecube_runtime/chassis.{h,cpp}` (bucle de
dispatch), `gamecube_runtime/hle.{h,cpp}` (43 entradas HLE),
`runtime.{h,cpp}` (conexión `Frame()`), `cpu/cpu.{h,c}`
(traza HW + DAR en accesos fuera de rango),
`build-libstarfox-ndk.sh` (añade `-fPIC`, ver abajo).
Tests host en `work-port/fase2-tests/` (fuera del repo):
`test_boot.cpp` (puerta de paso) y `test_trace2.cpp`
(exploración sin stop-PC, NO es puerta de paso).

### Ruta ejecutada (Fase 2, verificada)

Chassis: cada iteración despacha `dolrecomp_call(cpu, pc)`,
repone `downcount` a 0 antes de cada despacho (los chunks
ceden al chassis con `downcount <= -256`) y avanza el
`timebase` simulado 10.000 por despacho (no es exacto por
ciclo; `mftb` ya ve pasar el tiempo). Paradas limpias, nunca
silenciosas: stop-PC, exit `0x8028DE18`, exception, PC
desconocido o topes. La interceptación HLE solo puede ocurrir
en el despacho (los chunks nunca llaman a `dolrecomp_call`
internamente: `bl` intra-chunk es `goto`, `bl` entre chunks
pone `lr` y devuelve al chassis; `blr` usa el switch de
retorno). Un handler HLE pone `pc = lr` y devuelve true: vale
tanto para `bl` como para tail-call `b`.

Cadena real observada: `__start` (0x80003140) →
`__init_registers` → `__init_hardware` (llama a `__OSPSInit`
0x80241628 y `__OSCacheInit` 0x802428AC) → `__init_data`
(memcpy / `__flush_cache`) → `DBInit` 0x80247714 → `OSInit` →
`__check_pad3` (0x80003100) → `__init_user` 0x80247680 →
`main` 0x800214A4 → `init` 0x80020F8C (detectado por rango
[0x80020F8C, 0x800214A4): `main → init` es `bl` intra-chunk
chunk_0007, nunca se despacha exacto) → `videoInit`
0x80049D84 (chunk distinto: sí se despacha exacto).

Primeras 10 llamadas HLE en orden (retorno entre paréntesis):
`__OSPSInit` ← 0x80003368, `__OSCacheInit` ← 0x8000336C,
`DBInit` ← 0x8000323C, `OSInit` ← 0x80003240,
`__init_user` ← 0x80003268, `OSInit` ← 0x80020FB8 (segunda
vez, desde init), `DVDInit` ← 0x80020FBC, `VIInit` ←
0x80020FC0, `PADInit` ← 0x80020FC4, `LCEnable` ← 0x80020FC8.
`videoInit` llama después, en orden: OSGetArenaLo/Hi,
DCStoreRange, DCInvalidateRange, GXInit, OSInitAlloc,
VIConfigure, GXInitFifoBase, GXSetCPUFifo, GXSetGPFifo,
GXInitFifoLimits, GXSetCPUFifo, GXSetGPFifo, OSInitThreadQueue,
VIFlush, VIWaitForRetrace ×2.

### HLE implementado y su comportamiento (Fase 3)

- OS: OSInit marca init y registra la arena provisional;
  OSInitAlloc acepta lo/hi coherentes del llamador y reinicia
  el bump allocator del heap en lo (alineado a 32);
  OSGetArenaLo/Hi devuelven la arena provisional
  `0x80400000–0x81700000` (por encima de la pila
  `0x803F9E58` y del fin del BSS `0x803E4458`, dentro de RAM
  `0x81800000`; videoInit luego la fija a
  `0x80400A00–0x81700000` con su OSInitAlloc real). Alarmas
  (OSInitAlarm/OSSetAlarm/OSCancelAlarm) = no-op con log,
  nunca se disparan en esta fase. Hilos: OSCreateThread
  registra y devuelve 1, OSResumeThread marca runnable y
  devuelve 1; no hay ejecución real de hilos (el chassis
  monohilo ES el scheduler).
- Heap: OSAllocFromHeap 0x80241DCC = bump allocator HLE
  (bloques alineados a 32 dentro de la arena, 0 si no cabe;
  el handle de r3 se ignora: un solo heap global);
  OSFreeToHeap 0x80241EC8 = no-op con log (fuga acotada a
  init; pendiente para sesiones largas). Motivo documentado:
  el OSAllocFromHeap real trabaja sobre la cabecera que
  OSInitAlloc debería escribir en RAM; sin ella sigue
  punteros basura (ver Exceptions).
- DVD (del árbol extraído, nunca DVD físico): DVDInit marca
  flag; DVDOpen lee el nombre guest (máx. 1.024 chars),
  prueba `raíz + "/" + nombre` y `raíz + nombre`, abre con
  `fopen("rb")`, guarda tamaño y una entrada por dirección
  guest fileInfo, devuelve 1/0. DVDOpen NO escribe todavía
  los campos del struct DVDFileInfo (layout pendiente de
  verificar contra `initLoadFiles`). DVDReadPrio lee con
  `fseek`/`fread` y copia a RAM guest (puntero directo si
  está en RAM incl. alias no cacheado `0xC0000000`, si no
  byte a byte), devuelve bytes o -1. DVDReadAsyncPrio es
  síncrono en esta fase (lee ya, devuelve 1) y NO invoca el
  callback (r7) todavía. DVDClose cierra y borra; leer después
  devuelve -1. OJO: el `DVDRead` 0x80015888 es una función
  DEL JUEGO (wrapper propio), NO el read del SDK: no se HLEa;
  los reads SDK son DVDReadPrio 0x80249948 y
  DVDReadAsyncPrio 0x80249858. OSGetTick 0x80247614 NO se HLEa
  a propósito: su código real usa `mftb` del timebase del
  chassis, ya correcto; HLEarlo arriesgaría el ABI r3:r4.
- VI: VIInit resetea el contador de retrace; VIWaitForRetrace
  incrementa y devuelve AL INSTANTE (nunca bloquea: un wait
  real colgaría el chassis); VIConfigure/VIFlush = stubs con
  log (el modo de vídeo / framebuffer real es trabajo GX).
- PAD: PADInit = estado a cero; PADRead = stub con log que
  devuelve 0 y NO escribe todavía el struct PADStatus (layout
  pendiente); la RAM del buffer ya es cero tras el BSS, así
  que `padUpdate` lee el estado neutro, que es el
  comportamiento pedido para esta fase. PADReset/PADRecalibrate
  aparecen en la exploración posterior (ver abajo) como stubs
  con log (añadidos al recorrer la ruta: PADReset 0x8024EDC0,
  PADRecalibrate 0x8024EEC0).
- LC/DC: LCEnable, DCStoreRange, DCFlushRange,
  DCInvalidateRange = no-op con log (sin caches separadas en
  recompilación); DCZeroRange SÍ pone a cero la RAM guest
  (puntero directo si está en RAM, si no byte a byte).
- GX en esta fase: GXInit = stub con log (el GX real es la
  fase siguiente); GXInitFifoBase/Ptrs/Limits, GXSetCPUFifo,
  GXSetGPFifo = stubs con log, sin tocar hardware ni FIFO.
- SPR por fallback: el emisor C de DolRecomp solo traduce
  unos pocos SPR; mfhid0/mthid0 (SPR 1008) y mfl2cr/mtl2cr
  (1017) llegan como fallback y el HLE los modela con estado
  propio (hid0_/l2cr_, inicio 0 provisional: el código
  observado solo hace OR de bits sobre lo leído). OJO: el
  número SPR va partido en el raw (bits 11-15 mitad alta,
  16-20 mitad baja); `(raw>>11)&0x3FF` da 501 para HID0 en vez
  de 1008 (error real, corregido y cubierto con test usando el
  raw del propio juego `0x7C10FAA6`).
- Cache por fallback: dcbst/dcbf/dcbi/icbi (opcode 31, XO 54/
  86/470/982) = no-op + `pc = cia + 4` (el emisor termina el
  bloque tras el fallback; no avanzar sería un bucle
  infinito). Cualquier otro fallback = exception registrada
  sin avanzar (el chassis se detiene, no se enmascara).
- `__OSPSInit` NO es no-op puro (ver Exceptions): replica su
  efecto verificado en el chunk (`hid2 |= 0xA0000000`
  LSQE+PSE, `gqr[0] = 0`). `__OSCacheInit` sí es no-op: su
  chunk solo toca HID0/L2CR/error handler/prints, sin efecto
  observable aquí.

### Verificación: test host boot (puerta de paso, run1)

`test_boot.cpp`, DOL real solo en lectura, árbol
`disc/files/` como raíz DVD. RESULTADO: TODO OK.
- Arranque: motivo `reached_stop_pc`, 847 despachos, 0,007 s,
  PC final `0x80049D84` (videoInit, detenido ANTES de
  despacharlo), main = 1, init = 1, videoInit = 1, exception 0,
  PC desconocido 0, HLE totales 10, retrace 0, fallback_cache
  0, fallback_unknown 0, GXInit 0 (correcto: el stop es la
  entrada a videoInit). DOL re-verificado: entry, text/data,
  palabra en entry, BSS primero/último a cero.
- Unidades: retrace ×1000 en 0,001 s; DCZeroRange pone a cero
  64 B reales; DCStoreRange no toca la RAM; arenas
  `0x80400000`/`0x81700000`; `__OSPSInit` HLE deja HID2 con
  LSQE+PSE y `gqr[0] = 0`; heap HLE: primer bloque en
  arena_lo, segundo tras 128 B alineados (100 → 128);
  fallback dcbst avanza sin exception; fallback desconocido
  (raw 0) marca exception sin avanzar; traza HW: escribir +
  2 lecturas en `0xCC001234` → total 3, distinct 1.
- DVD contra el árbol real: DVDOpen `AMAP.BIN` = 1,
  DVDReadPrio 256 B @0 y 128 B @1024 byte-idénticos al
  fichero host, DVDOpen `/AMAP.BIN` = 1 (candidato con barra
  inicial), DVDOpen `NOEXISTE.BIN` = 0, DVDClose = 1, leer
  tras cerrar = -1 (`0xFFFFFFFF`).
- Traza HW del arranque a videoInit: total 0, distinct 0 (la
  traza funciona por test de unidad: el juego NO toca ningún
  `0xCC00xxxx` directo en esa ruta; todo el hardware de esa
  fase vive dentro de las funciones SDK que el HLE sustituye).

### Exploración más allá de videoInit (run2, diagnóstica)

`test_trace2.cpp`, sin stop-PC, topes 300.000 despachos /
60 s. NO es puerta de paso: su valor es la frontera y la
traza. Resultado actual: motivo `dispatch_cap`, 300.000
despachos, 1,365 s, sin exception, PC final `0x80250BA0`,
main = 1, init = 1, HLE totales 93, retrace 2, fallback_cache
0, fallback_unknown 0. La ejecución pasa videoInit,
setDisplayCopyFilter (vía SPR HID0), initLoadingScreenTextures
(OSGetArenaHi ← 0x80116198), mmInit (5 OSAllocFromHeap HLE:
tamaños `0xC3EEE0`, `0x6EC`, `0x1C0000`, `0x9FFA0`,
`0x45FFA0`), ~49 DCInvalidateRange, 5 DCFlushRange, PADInit
(segunda vez, desde 0x80015500), PADRecalibrate, PADReset ×2,
PADRead ×1 (desde `padUpdate` 0x80014FC0), y queda girando en
`__ARChecksize` 0x80250B88 (ver Exceptions / frontera).
NO se alcanzó todavía: ningún DVDOpen/DVDRead, ningún
`initLoadFiles`, ningún gameLoop.

### Traza de hardware (Fase 4, run2 post-correcciones)

CSV en `work-port/fase2-tests/run2/` (fuera del repo). Total
25.220.080 eventos, 11 direcciones distintas, 0 descartadas.
El 99,99 % es un solo bucle de espera (ver frontera). Top:

| Dirección | Lect. | Escr. | Total | Primer PC | Nota |
|---|---|---|---|---|---|
| 0xCC005016 | 25.219.146 | 0 | 25.219.146 | 0x80250BA0 | Espera ARAM/DSP (`__ARChecksize`) |
| 0xCC008000 | 0 | 285 | 285 | 0x80259950 | FIFO GX (stream de comandos) |
| 0xCC006800 | 97 | 97 | 194 | 0x802442F4 | EXI (lectura/escritura) |
| 0xCC00680C | 96 | 96 | 192 | 0x80253E18 | EXI |
| 0xCC006024 | 96 | 0 | 96 | 0x80241668 | DI/DVD (solo lectura) |
| 0xCC006804 | 0 | 48 | 48 | 0x80253FA0 | EXI |
| 0xCC006808 | 0 | 48 | 48 | 0x80253FAC | EXI |
| 0xCC006810 | 0 | 48 | 48 | 0x80253DD4 | EXI |
| 0xCC008004 | 0 | 18 | 18 | 0x8025D9A4 | Registro junto al FIFO GX |
| 0xCC00501A | 2 | 1 | 3 | 0x80250AB8 | ARAM/DSP |
| 0xCC006828 | 1 | 1 | 2 | 0x8024439C | EXI |

Interpretación para la fase GX (las regiones EXI/DI/DSP son
plausibles por mapa GC, a confirmar contra el código que
accede): el FIFO GX `0xCC008000` ya recibe comandos reales
desde funciones GX no HLEadas (285 escrituras, primer byte
`0x61`); el resto del tráfico pre-GX es ARAM/DSP + EXI/DI de
init. La traza vive en el shim C (`cpu.c`, no en `mem.cpp`:
los chunks llaman a `mem_*` C directamente), solo el rango
`0xCC000000–0xCC020000`, primeros 20 eventos por dirección en
detalle, contadores sin truncar, máx. 2.048 direcciones
distintas. `CPUState` no cambió de layout (orden canónico
DolRecomp); el estado de traza es estático en `cpu.c`
(chassis monohilo, sin locks). Desactivada por defecto;
`LoadGame` la resetea y activa; `DumpHwTrace` existe para
uso futuro desde código nativo (aún sin cablear a
`native-lib.cpp`).

### Exceptions encontradas (ninguna enmascarada)

1. PSMTXIdentity 0x80247800 → program exception, vector
   `0x700` (run2 pre-corrección). Causa: el HLE inicial de
   `__OSPSInit` era no-op puro y perdía su efecto real.
   Verificado en el chunk 0x80241628: lee HID2, hace OR con
   `0xA0000000` (LSQE+PSE), escribe HID2, invalida icache y
   pone `gqr[0] = 0`. Corrección: el HLE replica esos dos
   efectos (no se tocó el juego ni el shim de PSQ). Tras la
   corrección, PSMTXIdentity se ejecuta sin exception.
   `__OSCacheInit` se verificó que NO escribe HID2 (sus
   llamadas son mfhid0/ICEnable/DCEnable/L2CR/MSR/error
   handler/prints), así que su no-op es correcto.
2. mfhid0 0x8004A5B4 → fallback desconocido (run2
   pre-corrección). Causa: SPR sin modelar en CPUState.
   Corrección: HLE de SPR HID0/L2CR por fallback (ver arriba).
   Tras la corrección, setDisplayCopyFilter continúa.
3. mmInit 0x80024148 → exception genérica tras
   OSAllocFromHeap 0x80241DCC real (run2 pre-corrección).
   Causa: OSInitAlloc HLE no escribía la cabecera del heap y
   el allocador real seguía punteros basura. Corrección: heap
   HLE por bump allocator (ver arriba). Tras la corrección,
   mmInit completa sus 5 reservas sin exception.
4. Frontera actual (NO es un fallo del juego): el run2 actual
   agota el tope de despachos girando en `__ARChecksize`
   0x80250B88, que lee `0xCC005016` (16 bits) esperando un bit
   de estado ARAM/DSP que nunca se pone porque las lecturas
   HW devuelven 0. Siguiente trabajo GX/ARAM: emular el
   estado ARAM/DMA (o HLEar ARInit/`__ARChecksize`) para que
   init continúe hacia la carga de ficheros.

### Build NDK (verificación)

Script existente con dos cambios documentados:
`build-libstarfox-ndk.sh` añade `-fPIC` a `compile_c` y
`compile_cxx` (bug latente de Fase 1: los objetos de Fase 1
no referenciaban globales de datos, así que enlazaban sin
PIC; el enlace Fase 2 falló con
`R_AARCH64_ADR_PREL_PG_HI21 ... recompile with -fPIC` hasta
el cambio). Además, `generated.h` es C puro sin guardas
`extern "C"`: incluirlo desde C++ mangla `func_*`; la
corrección es envolver el include en `extern "C" {}` en
`chassis.cpp` (verificado: `U func_80003100` sin manglar).
Resultado (tras las correcciones HLE de este tramo, build
`fase2-ndk-build`, JOBS=2): PASS, 0 errores.
`libstarfox.so` 27.257.168 B, SHA-256
`b64416715b57e6fd02c6ee55db2da994b4fb454cd202d536094bc0f3f1e8e64e`,
comprobación del script "OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver", 115 undefined
totales (solo libs del sistema: libc/pthread/bionic). Los
objetos hle/chassis/runtime/cpu se borraron antes de
reconstruir para que los cambios de este tramo entraran
(el script es incremental por timestamp, no por flags ni
por cabeceras); las cadenas nuevas ("heap bump",
"OSAllocFromHeap", "fallback SPR") y los símbolos
`sfa_hle_host_call` / `sfa_hle_instruction_fallback` están
en el `.so` final. El directorio de build de Fase 1
(`fase1-ndk-build`) no se tocó.

### Qué queda para GX

- GX real: FIFO `0xCC008000` (285 escrituras ya observadas),
  registros CP/PE, display lists, texturas, framebuffer y
  modo de vídeo (VIConfigure real). La traza HW de arriba ES
  la especificación de partida.
- ARAM/DSP: estado `0xCC005016` / `0xCC00501A` o HLE AR
  (`__ARChecksize`, ARInit, DMA ARAM) para salir del bucle.
- Después: DVDFileInfo struct + callback async de DVD,
  struct PADStatus, heap con free real (no solo bump),
  arena definitiva (no provisional), input con mapeo a
  táctil/mando, paquete de datos Pack B, APK jugable y test
  en Tab S8. Sin ejecución en dispositivo todavía.

## Fase 5 (este tramo): desbloqueo AR/DSP/ARAM, carga DVD y bucle de juego

Trabajo en `android-port-base` (commit del tramo al final).
Ficheros tocados: `cpu/cpu.{h,c}` (estado AR/AI/
DSP), `gamecube_runtime/chassis.{h,cpp}` (timebase +200,
valores IPL), `gamecube_runtime/dol_loader.cpp` (orden
BSS/datos), `gamecube_runtime/hle.{h,cpp}` (eventos DSP/ARQ,
GXLoadTexObj, OSSleepThread, DVDOpen sin mayúsculas).
Tests host en `work-port/fase2-tests/` (fuera del repo):
`test_boot.cpp` (run1, puerta de paso), `test_trace2.cpp`
(runs 7–14) y `test_pchist.cpp` (diagnóstico: histograma,
pre-racha, volcado de pila/globales).

### 0. Desbloqueo previo (obligatorio, COMPLETADO y superado)

La frontera de Fases 2–4 era `__ARChecksize` 0x80250B88
girando en `0xCC005016` (run2: 25.219.146 lecturas). La
cadena completa de desbloqueos, cada uno verificado por
separado antes de seguir (si uno no se verificaba, no se
seguía), fue:

- **AR_MODE (cpu.c):** `__ARChecksize` lee `0xCC005016`
  (`lhz` 16-bit) y solo sale cuando el bit 0 vale 1. Los
  registros AR `0xCC005000–0xCC00503F` se guardan (RMW
  coherente) y AR_MODE se lee siempre con bit 0 a 1 (en
  este HLE nunca hay DMA ARAM pendiente). run3: traza HW
  1.056 eventos frente a 25.220.080 en run2; el giro terminó.
- **PPCSync (hle):** tras AR, exception `0x8` en
  `0x80240CBC` (un único `sc` + `blr`); HLE no-op con
  retorno a `lr`. run4: superado.
- **Contador AI (cpu.c):** `__AI_SRC_INIT` 0x8025072C
  espera que el contador `0xCC006C08` CAMBIE; modelo
  `timebase / 1266` (40,5 MHz / 32 kHz). run5: primer bucle
  superado, segundo bucle alcanzado.
- **Calibración SRC (chassis.cpp):** la medición de
  `__AI_SRC_INIT` solo acepta Δticks < 1144 o
  1384 ≤ Δ < 1566; con timebase +10000 o +100 los deltas
  caían siempre fuera (1200/1300, en el hueco); con
  **+200 por despacho** el Δ alcanzable es 1200 o 1400
  según la fase, y 1400 está en la ventana, así que la
  calibración termina en pocos intentos. Además
  `InitCpuForBoot` escribe los valores IPL en RAM guest
  (`0x800000F8` = 162.000.000 bus, `0x800000FC` =
  486.000.000 CPU). run1 sigue TODO OK tras el cambio.
  `__AI_SRC_INIT` NO se HLEa a propósito: sus 3 llamadores
  están en su mismo chunk (goto, no despacho) y una entrada
  HLE sería código muerto.
- **BSS que borraba datos (dol_loader.cpp, causa raíz del
  salto a 0):** el cargador copiaba text/data y LUEGO ponía
  el BSS a cero, pero el BSS de cabecera (`0x803371A0`,
  732.344 B → hasta `0x803E3E58`) SOLAPA las secciones
  data #6 (`0x803DCB40`) y #7 (`0x803DFEC0`): destruía
  ~46 KB de datos inicializados, entre ellos los punteros
  malloc/free de `.sdata2` en `0x803DFF08/0x803DFF0C` (en
  el fichero: `0x8000A1D8` / `0x8000A1B8`). Resultado:
  `audioInit` → `sndSetHooks` copiaba ceros a los globales
  `[r13-19980]/[r13-19976]` y `salMalloc` 0x802854DC
  saltaba por el puntero 0 (PC 0 a los 6.905 despachos).
  La tabla de `__init_data` del propio juego lo confirma:
  su BSS verdadero EXCLUYE esas secciones
  (`[0x803371A0,+678304)`, `[0x803DE160,+7492)`,
  `[0x803E9E20,+56)`) y sus copias son src==dst.
  Corrección: poner el BSS a cero ANTES de copiar
  text/data (los datos ganan en el solape). Tras ella:
  hooks `0x8000A1D8`/`0x8000A1B8` correctos en RAM.
- **Buzones DSP (cpu.c):** `__DSP_boot_task` 0x80252050
  espera correo DEL DSP (`DSPCheckMailFromDSP` 0x80251840:
  `lhz [0xCC005004]`, `rotl32(v,17)&1` = **bit 15**,
  0x8000 — el primer intento con bit 14 / 0x4000 falló y
  la traza lo delató: primer valor 0x4000 sin salir del
  giro). Modelo: correo FROM siempre presente (bit 15 a
  1, valor resto 0; `__DSP_boot_task` guarda el correo en
  12(r1) y NO lo vuelve a leer, así que el valor es
  irrelevante ahí); buzón TO siempre libre (bit 15 a 0 en
  lectura, consumo instantáneo; se conserva el valor
  enviado para la traza); escrituras al buzón FROM se
  ignoran. run10: el giro de 73.672.215 lecturas de
  `0xCC005004` desapareció de la traza.
- **Callback de init DSP (hle.cpp, evento, no sustitución):**
  `salInitDsp` 0x80285248 añade la tarea (campo [40] =
  `dspInitCallback` 0x80285084), pone a 0 el flag
  `[r13-19912]` y gira en 0x802852DC hasta que el callback
  lo ponga a 1. Sin DSP no hay interrupción que lo
  dispare (run10: giro sin fin, 0 excepciones). Como
  `DSPAddTask` 0x802519CC (código huésped: lista +
  handshake, NO HLEado) y el bucle son puntos de
  despacho, el HLE recuerda la tarea en la entrada a
  `DSPAddTask` y entrega el callback al aterrizar en el
  bucle: si el init_cb es `dspInitCallback`, aplica SUS
  efectos exactos (`[r13-19928]=[r13-19912]=1`); otro
  init_cb queda solo registrado, sin efecto. run11: log
  `DSP task init callback entregado (tarea 0x803D61E0)`.
- **Drenaje ARQ (hle.cpp, evento):** `aramInit`
  0x80284B94 gira en 0x80284D58 mientras el contador de
  la cola ARAM `[r31+641]` != 0; solo lo baja
  `aramQueueCallback` 0x80284910, que corre al completarse
  el DMA ARAM (interrupción ARQ: inexistente aquí).
  Modelo: DMA ARAM instantáneo en diferido — cada entrada
  a `ARQPostRequest` 0x802516D4 (código huésped) cuenta
  una petición pendiente y al aterrizar en el bucle se
  aplica como decrementos del contador que el bucle lee
  (puntero en r30 del huésped). Las entradas de
  `aramInit` tienen callback nulo (r8=0), así que drenar
  equivale exactamente a bajar el contador. run12: log
  `ARQ drenado en aramInit (contador 0x803D5B41: 1 -> 0)`.
- **DVD sin mayúsculas (hle.cpp):** el árbol extraído trae
  `PREANIM.BIN`/`PREANIM.TAB` y el juego pide
  `PREANIM.bin`/`PREANIM.tab`; el FS del host distingue
  mayúsculas y el `fopen` exacto fallaba. `DVDOpen` ahora
  prueba, solo para nombres planos, un escaneo del
  directorio raíz con comparación sin mayúsculas. run13:
  `PREANIM.bin` resuelto como `PREANIM.BIN` (946.880 B).
- **GXLoadTexObj (hle.cpp, GX por HLE):** el huésped llama
  a un puntero del estado GX en `[estado+1040]` que el
  `GXInit` stub nunca inicializó (en el fallo:
  `gx_state_ptr [r13-27608] = 0x803AFE20`,
  `slot1040 = 0x00000000`) y saltaba a 0 (run12: PC 0 a
  1.381.102 despachos, tras 89 `DVDOpen`). En vez de
  adivinar ese puntero, `GXLoadTexObj` 0x8025B260 se HLEa
  entero: sin GPU, "cargar" es registrar (texObj, mapa)
  en `Calls()` (r3/r4 de cada llamada). run13: dos
  llamadas desde `selectTextureWithSecondary` 0x8004C448
  (texObj `0x816C0020`, mapa 0).
- **OSSleepThread (hle.cpp, bucle de juego):** tras la
  carga, `waitNextFrame` 0x8004AA4C duerme el hilo
  principal (`Queue_GetCount` > 1 → `OSSleepThread`
  0x8024740C con el hilo en `r13-25796`) esperando el
  siguiente retrace; sin interrupciones nadie lo despierta
  y `SelectThread` 0x80246A24 gira con la máscara de
  listos `[r13-21248]` a 0 (run13: 1.618.366 despachos en
  0x80246B5C). HLE: el sueño termina al instante (igual
  que `VIWaitForRetrace`, que ya era retrace simulado).
  run14: el juego entra en su bucle de frames (ver abajo).

### Bucle de juego alcanzado (run14, 5.000.000 despachos)

Sin exception, sin PC desconocido, corte por tope de
despachos en `0x802440BC` (mitad de frame, no un giro).
Llamadas HLE totales 150.477 (frente a 357 en run13):
`PADRead` ×24.923, `PADReset` ×24.924 (una encuesta de
input por iteración), `DVDOpen` ×89, `DVDReadAsyncPrio`
×82 (toda la carga base ya hecha: `MAPS`, `MAPINFO`,
`TEXTABLE`, `HITS`, `MODELIND`, `MODANIM`, `AMAP`,
`BITTABLE`, `WEAPONDA`, `VOXOBJ`, `MODLINES`, `SAVEGAME`,
`OBJSEQ`, `OBJECTS`, `OBJINDEX`, `OBJEVENT`, `OBJHITS`,
`TEXPRE`, `PREANIM`, `ENVFXACT`, ...), `GXLoadTexObj` ×2,
`OSSleepThread` repetido desde `waitNextFrame` (retorno
0x8004ABE0, el sitio exacto del sueño). Escrituras FIFO
GX `0xCC008000`: **1.789.482** (frente a 285 en run2).
Perfil por iteración (~24.900 iteraciones, ~200
despachos cada una): `GXSetViewport` ×24.924,
`gxSetZMode_` ×24.924, `GXFlush` ×49.845,
`gameTextRun` 74.769 despachos, `padUpdate` 99.692,
`evalNoisePlacements` 1.174.093 (23%),
`mmFreeTick` 274.142, `OSReport` ×24.973,
`OSDisable/RestoreInterrupts` ×100.186 cada uno. Es un
bucle de frames estable con trabajo GX por frame
(viewport, Z, flush, texto UI), no un giro: la
interpretación prudente es pantalla de título o de carga
animada en espera de input (PAD siempre a 0: sin botones,
no avanza de pantalla). Distinguir título de carga exige
capturar el texto de `OSReport` o inyectar Start; queda
como siguiente paso, no como afirmación de este tramo.

### GX por HLE (paso 1): estado

- Hecho: `GXInit`/FIFO como stubs con log (heredados),
  `GXLoadTexObj` HLE con registro (texObj, mapa).
  El resto de GX (`GXSetViewport`, `GXFlush`,
  `GXSetTexCoordGen2`, `__GXSetMatrixIndex`, `GXBegin`,
  ...) corre como código huésped y emite comandos FIFO
  reales (trazados en `0xCC008000`, no interpretados).
- NO hecho (sin maquillar): máquina de estado GX en el
  host (matrices, viewport, estado fijo, TEV) ni
  interpretación de display lists; TEV multi-etapa,
  `Rcp_*` y EFB siguen siendo no-op documentados, no
  promesas. El siguiente subpaso es esa máquina de estado
  (o, antes, decidir si el render va por GLES en la APK o
  por un rasterizador host para verificación).

### Texturas (paso 2): NO verificado todavía

Evidencia de partida, no conversión: `GXLoadTexObj`
registra texObj `0x816C0020`, mapa 0 (desde
`selectTextureWithSecondary`, probablemente textura UI).
Falta: decodificar el `GXTexObj` huésped (dirección de
imagen, formato, tamaño), resolverlo contra
`assets/inventarios/texturas.csv` y convertir (RGB5A3,
CMPR con reorden DXT1 o descompresión, RGBA8
reentrelazado, IA8/I8/I4/IA4 a RGBA, sin TLUT). Ninguna
conversión está verificada en este tramo; si una
dirección no resuelve, la regla sigue siendo log +
placeholder magenta/negra documentada, no inventar
texturas.

### Verificación por subpaso (paso 3): estado honesto

- Clear (Fase 0 APK): intacto, sin reconstruir (ver abajo).
- Quad con textura convertida: NO verificado (falta
  conversión + renderer).
- Display list mínima: NO verificado (DLs huésped solo
  trazadas como bytes FIFO).
- HUD/UI: NO verificado como frame (el juego ejecuta
  `gameTextRun` por frame, pero sin renderer no hay
  imagen que mostrar).
- El bucle de juego estable de run14 es la base sobre la
  que esos subpasos se verificarán; no se presenta como
  uno de ellos.

### No-op y limitaciones documentadas (Fase 5)

- Buzones DSP: correo FROM siempre presente, TO siempre
  libre; la finalización de tareas DSP reales (audio) NO
  está modelada: cualquier código que espere un correo
  DSP concreto pasará al instante con el valor fijo
  `0x80000000`.
- ARQ: DMA instantáneo en diferido; entradas con callback
  no nulo no se invocan todavía (las de `aramInit` son
  nulas); peticiones ARQ intra-chunk (sin despacho) no
  pasan por el gancho.
- `OSSleepThread`: sin suspensión real ni planificador;
  un bucle que espere un mensaje que nunca llega seguirá
  girando como bucle de despachos (entonces pedirá el
  siguiente HLE, p. ej. el callback async de DVD, que
  sigue pendiente: `DVDReadAsyncPrio` lee en síncrono
  pero NO invoca el callback).
- `GXLoadTexObj`: no escribe los registros BP ni el
  estado GX que el huésped escribiría; si una lectura
  posterior del estado GX lo exigiera, se rellenará en el
  HLE.
- PAD: sigue a 0 (sin botones); el juego no puede salir
  de la pantalla en espera de input hasta el mapeo.

### Build NDK (verificación Fase 5)

Build `fase5-ndk-build`, JOBS=4 (directorio nuevo: el de
Fase 2 ya no persistía; 178 chunks recompilados desde cero):
PASS, 0 errores. `libstarfox.so` 27.260.624 B, SHA-256
`c24a7eab1e9eaf578320ceedaea3908dca353abf2f237adb3c0c8766f9efb6ed`,
comprobación del script "OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver", 120 undefined
totales (solo libs del sistema, verificado por el script;
115 en Fase 2 — entre los nuevos están `readdir` y
`strcasecmp` del fallback `DVDOpen` sin mayúsculas).
Los 4 ficheros cambiados ya compilaban limpios por separado
antes del enlace completo (`cpu.c`, `hle.cpp`, `chassis.cpp`,
`dol_loader.cpp` con clang NDK r28c, API 26, `-fPIC`).

### Qué queda (tras Fase 5, en orden)

1. Máquina de estado GX en host + decodificación
   `GXTexObj` y conversiones de textura (pasos 1–2).
2. Renderer (GLES en APK o verificación host) para los
   subpasos de imagen (paso 3).
3. Callback async de DVD + struct `DVDFileInfo` (los
   reads ya son síncronos; falta avisar al juego).
4. Input: PADStatus real + mapeo táctil/mando (el juego
   ya encuesta PAD cada frame; con Start debería avanzar
   de pantalla).
5. Audio DSP real (tareas DSP, no solo el evento de
   init) + backend de audio.
6. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).

