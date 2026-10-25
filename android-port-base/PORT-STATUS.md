# Estado del port Android — rama `android-port-base`

**Fecha de este estado: 2026-10-25. Uso personal, repo privado, NO distribución.**

## Resumen honesto

**La app NO es jugable todavía.** Lo que hay es una base compilable
más el runtime base verificado en host (cargador DOL, memoria guest,
dispatch y SMC) y, desde este tramo, los 176 chunks DolRecomp
enlazados en `libstarfox.so` con su shim C. No hay APK jugable en
el repo. Cuando la haya, se anunciará aquí con su commit, tamaño y
SHA, y solo entonces merece la pena descargarla para probar el juego.

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

## Qué NO funciona todavía (bloqueadores, sin maquillar)

1. **Dispatch real y HLE pendientes (bloqueador actual nº 1):**
   los chunks ya enlazan (Fase 1), pero el runtime todavía no llama
   a `dolrecomp_run_blocks()` desde `0x80003140` ni existe el HLE
   (OS/GX/VI/DVD/SI/DSP/PAD) que el arranque exige. Hasta entonces
   la CPU es un stub y no se ejecuta código del juego. Este es el
   trabajo de la Fase 2, no un detalle menor.
2. **HLE completo pendiente:** GX, VI, DVD, SI/EXI, DSP, PAD, OS y
   demás llamadas del sistema. El juego llamará a esas familias
   desde el primer arranque; sin HLE, el primer bloque real fallará
   de forma explícita en `boot.log`, no silenciosamente.
3. **GX real pendiente:** solo clear. Falta FIFO, display lists y
   texturas (CMPR/RGB5A3/RGBA8 ya extraídas) para un frame real.
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
  toca (su fichero no aparece modificado en `git status`); el
  runtime que arranca la app sigue siendo el stub, así que su
  comportamiento de arranque no cambia. La APK con chunks
  llegará cuando haya dispatch real + HLE (Fase 2), no antes.

**Fidelidad honesta de los `ppc_*` (límites de esta fase):**
la aritmética FP es doble plana con redondeo a f32 en las
instrucciones single (verificado: los `fpr` guardan dobles
planos iguales al f32, salvo payload NaN); `fres`/`frsqrte`
usan el recíproco exacto en vez de la estimación Gekko (el
código guest que refina con Newton converge igual; la
bit-exactitud de la estimación queda para la Fase 2). Nada de
esto está validado ejecutando el juego: solo enlaza y pasa
tests de unidad.

**Qué bloquea la Fase 2 (dispatch real desde 0x80003140):**
falta (1) conectar el runtime (`GameCubeRuntime::Frame`) a
`dolrecomp_run_blocks()`/`dolrecomp_call()` con un `CPUState`
cuya `ram` apunte a la `GCMemory` cargada con el DOL, y (2) el
HLE mínimo de arranque en el orden de `init` (OS → DVD → VI →
PAD → LC/DC → GXInit → audio → carga de ficheros), porque el
primer bloque real llamará a esas familias y hoy devolvería
`exception` o se quedaría sin respuesta. Sin eso, llamar a
`__start` es correr a ciegas: enlazado sí, ejecutable todavía no.

## Orden que queda

1. Dispatch real desde `0x80003140` + HLE mínimo de arranque
   (OS/GX/VI/DVD/SI) para que __start avance.
2. GX real (primer frame) y luego DSP/MusyX e input.
3. Paquete de datos + build APK + validación + test en Tab S8.
