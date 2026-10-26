# Estado del port Android — rama `android-port-base`

**Fecha de este estado: 2026-10-25. Uso personal, repo privado, NO distribución.**

## Resumen honesto

**La app NO es jugable todavía.** Lo que hay es una base compilable
más el runtime verificado en host: el juego ya NO se queda en el
arranque — en host ejecuta su arranque completo, carga los 89
ficheros base por DVD, pasa audio/DSP/ARAM y entra en su bucle de
frames estable (ver «Fase 5» abajo: 5.000.000 despachos sin
exception, 1.789.482 escrituras FIFO GX, encuesta PAD por frame).
No hay APK jugable en el repo: el renderer GX ya existe y está
verificado en host (Fase 5b: replay de 602 draws a imagen con
texturas reales), pero todavía no está en la APK. Cuando haya
APK jugable, se anunciará aquí con su commit, tamaño y SHA, y
solo entonces merece la pena descargarla para probar el juego.

**Fases 6–7 (2026-10-25, este tramo):** el juego ya NO se queda
en el logo Dolby retenido: con el `DVDFileInfo` real, el
callback async de DVD y los drenajes ARQ (ver «Fases 6–7»
abajo), en host avanza por toda la init de audio (12 ficheros,
16,8 MB), el desbloqueo ARAM por callback y la carga del
frontal (98 ficheros, 20,1 MB, 2 `GXLoadTexObj`, textos del
frontal en inglés), hasta un **nuevo bloqueador honesto**: una
excepción por escritura fuera de rango en
`updateHeavyFogTexture` (0x8006A0E0) porque el puntero de la
caché de texturas es NULL tras
`n_attractmode_releaseMovieBuffers` (ver «Fases 6–7», punto 5).
Sigue sin ser jugable, y la APK Fase 0 sigue siendo solo
arranque.

**Fase 8 (2026-10-26, este tramo): bloqueador nº 1 RESUELTO
(no era un NULL).** La excepción de run26 no era una escritura
en 0: `getCache` devuelve `0xE0000000` (base de la caché
bloqueada de GameCube) cuando el estado es 0 o 4, y el HLE de
`LCEnable` no hacía nada, así que `mem_*` no tenía mapeada esa
dirección. Con la caché bloqueada mapeada (16 KiB) + DMA LC por
HLE + `mfwpar` + inicialización real de colas de mensajes, el
juego supera `updateHeavyFogTexture`, registra los callbacks VI,
llega a `prepareAttractMode` y carga `starfox.thp` (48,9 MB) y el
frontal completo (121 ficheros, 22,6 MB async, 56.389 B FIFO).
**Nueva frontera, sin maquillar:** se detiene en
`OSReceiveMessage` dentro de `prepareAttractMode` esperando
mensajes de los hilos de decodificación THP, que el chassis
monohilo registra pero no ejecuta (`OSCreateThread` solo
registra). Ese es el siguiente bloqueador concreto, no un
retroceso: los titulares de run30/31/32/33 son idénticos salvo
los contadores VI. Ver «Fase 8» abajo.

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
- Renderer EGL/GLES3: clear + `DrawQuad` stub.
- **Fase 6a — DVDFileInfo real + callback async (NUEVO,
  verificado):** `DVDOpen` escribe +12/+48/+52/+56 con el tamaño
  real del fichero y el offset FST; `DVDReadAsyncPrio` lee en
  síncrono y despacha el callback del juego como código huésped
  (r3 = bytes, r4 = fileInfo); VI retrace por modelo de frontera
  de frame (`OSSleepThread`/`VIWaitForRetrace`); drenajes ARQ de
  subida, de sync y de callback por petición (ver «Fases 6–7»).
- **Fase 6b — Input HLE completo (NUEVO, verificado):**
  `PADStatus` real (12 B/mando), `PADRead` escribe los 4 mandos
  y pone el flag de muestra fresca (0x803DE65D) que `padUpdate`
  exige, `HandleEvent` mapeado a `PadState` (stick, A/B/X/Y/Z,
  L/R todo o nada, D-pad, Start, C-stick 0, rumble no-op) y
  conectado al runtime. Test host `start`: Held0 = 0x1000.
- **Fase 7 — Audio por WAV (NUEVO, verificado en host):**
  backend AAudio en Android (48 kHz estéreo, `-laaudio`),
  backend nulo contable en host; WAV PCM16 mono/estéreo con
  resampleo lineal a 48 kHz y anillo de 262.144 frames;
  `PlayWavFile` probado con dos IDs reales del inventario
  (ver «Fases 6–7»). En dispositivo, sonido todavía sin probar.
- **Fase 5 — Bucle de juego en host (NUEVO, verificado):**
  desbloqueos AR/AI/DSP/ARAM/hilos (ver sección «Fase 5»),
  carga DVD completa (89 ficheros) y bucle de frames estable
  sin exception (run14). GX por HLE empezado (`GXLoadTexObj`
  registrado); texturas y renderer, pendientes (sin maquillar).

## Qué NO funciona todavía (bloqueadores, sin maquillar)

1. **~~Bloqueador nº 1 (Fases 6–7): excepción por caché de
   texturas NULL en la transición attract-mode.~~ RESUELTO en
   Fase 8 (no era un NULL, ver abajo):** la causa raíz estaba
   en el HLE, no en el juego: `getCache` (0x80022BB0)
   devuelve `0xE0000000` (caché bloqueada) con estado 0 o 4, y
   `LCEnable` HLE no hacía nada, así que `mem_*` no mapeaba
   `0xE0000000` → exception 1 en el primer `stbx` de
   `updateHeavyFogTexture`. El watchpoint demostró que en
   run27 las únicas escrituras a la estructura de caché fueron
   el borrado BSS de arranque: ni `releaseMovieBuffers` ni
   `prepareMovie` llegaron a correr en ese run, así que la
   historia «release liberó la caché, estado 4» queda
   superada para este run (el estado era 0 por BSS, no 4 por
   free). Solución: búfer LC de 16 KiB en `CPUState` +
   `LCLoadBlocks`/`LCStoreBlocks`/`LCQueueWait` por HLE +
   `mfwpar` + colas de mensajes reales. Ver «Fase 8».
2. **Bloqueador actual nº 1 (NUEVO, tras Fase 8): el juego se
   detiene en `OSReceiveMessage` (0x80244A68) dentro de
   `prepareAttractMode` (0x80118E70),** esperando (con
   `flags = 1`, bloqueante) un mensaje de los hilos de
   decodificación THP (`CreateVideoDecodeThread` 0x8011A034,
   `CreateAudioDecodeThread` 0x80117A80, `CreateReadThread`
   0x80119BF4) que el chassis monohilo registra con
   `OSCreateThread` pero no ejecuta. Sin hilos reales (o un
   planificador que los haga avanzar) no hay pantalla de
   título ni input de título que probar. Siguiente paso
   concreto: ejecutar hilos registrados (planificador
   cooperativo o entrega de mensajes simulada con la
   semántica exacta de la cola), sin inventar contenido de
   los mensajes. Ver «Fase 8», punto 4.
2. **~~Dispatch real y HLE pendientes:~~ HECHO en Fases 2–6:**
   el juego ejecuta su arranque completo, toda la init de
   audio y la carga del frontal en host (ver «Fases 6–7»).
   **~~Renderer GX + texturas:~~ HECHO en host en Fase 5b**
   (máquina GX, conversiones verificadas y renderer host con
   frame real); falta el mismo camino en la APK (ver «Fase 5b»).
3. **HLE completo pendiente:** GX (máquina de estado y
   display lists) en APK, ~~callbacks VI pre/post retrace,~~
   **HECHO en Fase 8** (setters por HLE + entrega encadenada
   por trampolín sintético en cada retrace simulado;
   `videoSwapFrameBuffers` pre y `gpuErrorHandler` post,
   155.286 cadenas equilibradas en run31 sin regresión);
   audio DSP real, planificador de hilos real, CARD. El HLE
   actual cubre arranque + eventos DSP/ARQ + callback DVD +
   PAD + sueño instantáneo + callbacks VI + DMA LC + colas
   de mensajes.
4. **GX real en APK pendiente:** la máquina de estado GX,
   display lists y texturas convertidas ya existen y están
   verificadas en host (Fase 5b); falta el mismo camino en
   la APK (GLES3) para un frame real en dispositivo.
5. **Audio MusyX/DSP pendiente:** backend AAudio implementado
   (sin probar en dispositivo) y WAV probados en host; falta
   el mapeo ID de sonido del juego → WAV (tablas
   `Streams.bin`/`Sfx.bin`/`.sdi` sin parsear), las secuencias
   MusyX (`.pro`/`.poo`/`midi.wad`) y la emulación DSP.
6. **Input pendiente (parcial):** mando/teclado/táctil-stick
   mapeados; faltan botones táctiles en pantalla (sin layout
   definido, no inventado) y rumble (`PADControlMotor` sin
   HLE). **Flanco JustPressed: MEDIDO en Fase 8 a nivel
   `padUpdate`** (la fórmula es `Just = Held & ~Prev`,
   leída en 0x800151E4–0x80015210): con Start programado
   desde el PADRead nº 3 (0 en los dos primeros), el run
   termina con Held0 = Just0 = Prev0 = 0x1000, frente a
   Held0 = Prev0 = 0x1000, Just0 = 0 con Start desde el
   arranque. Falta la misma prueba a nivel de pantalla de
   título, bloqueada por el pipeline de hilos THP (punto 2
   arriba).
7. **Datos sin empaquetar:** no hay paquete de datos para el test.
   La APK no meterá 2 GB; la vía (APK pequeña + datos aparte) está
   por decidir con tamaños reales y pasos de instalación.
8. **Sin Android SDK aquí:** no hay `aapt2/d8/apksigner/zipalign` ni
   Gradle en este entorno. La APK de este tramo no se ha construido;
   su build y validación (`apksigner verify`, `zipalign`, manifiesto
   con `apktool`) quedan pendientes de instalar cmdline-tools o de
   la vía manual de la skill local.
9. **Sin ejecución en dispositivo:** no hay runtime Android aquí.
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

### GX por HLE (paso 1): HECHO en host en Fase 5b

- Hecho en Fase 5: `GXInit`/FIFO como stubs con log
  (heredados), `GXLoadTexObj` HLE con registro (texObj,
  mapa). El resto de GX corría como código huésped y
  emitía comandos FIFO reales (trazados en `0xCC008000`,
  no interpretados).
- **Hecho en Fase 5b (ver sección «Fase 5b»):** máquina
  de estado GX en host (`gamecube_runtime/gx.{h,cpp}`:
  CP/XF/BP, viewport, matrices, draws VAT1, DLs leídas de
  RAM), validada con 602 draws QUADS VAT1 a EOF sin
  desconocidos. TEV multi-etapa, `Rcp_*` y EFB siguen
  siendo no-op documentados, no promesas.

### Texturas (paso 2): VERIFICADO en Fase 5b

Evidencia de partida (Fase 5): `GXLoadTexObj` registra
texObj `0x816C0020`, mapa 0 (desde
`selectTextureWithSecondary`, textura UI).
**Hecho en Fase 5b (ver sección «Fase 5b»):** layout
`GXTexObj` cerrado y verificado (3 texObjs vivos: barra
IA8, Rare RGB5A3, Dolby CMPR, todos con tamaño base
exacto), conversiones C++ verificadas byte a byte contra
la referencia del extractor (**10 PASS, 0 FAIL**, incluido
CMPR con tile de 32 B corregido). Origen verificado:
activos embebidos en `.rodata` del DOL (data5), no bancos
TEX. Si una dirección no resuelve, la regla sigue siendo
log + placeholder magenta/negra documentada, no inventar
texturas.

### Verificación por subpaso (paso 3): HECHO en host en Fase 5b

- Clear (Fase 0 APK): intacto, sin reconstruir (ver abajo).
- Quad con textura convertida: **VERIFICADO en host**
  (Fase 5b: replay 602/602 draws con barra/Rare/Dolby
  texturizados, logo Rare vertical y legible).
- Display list mínima: NO aplica en este tramo (0 DLs en
  el stream; el parser las soporta, leídas de RAM guest,
  profundidad ≤ 4, sin ejercitar aquí).
- HUD/UI: el juego ejecuta `gameTextRun` por frame, pero
  en este tramo no genera draws; el frame renderizado es
  el de logos (barra/Rare/Dolby), no HUD.
- El bucle de juego estable de run14 es la base; el frame
  visible del bucle es el último dibujado (Dolby),
  retenido en el EFB (ver «Fase 5b»).

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

1. ~~Máquina de estado GX en host + decodificación
   `GXTexObj` y conversiones de textura (pasos 1–2).~~
   HECHO en Fase 5b (ver abajo).
2. ~~Renderer (verificación host) para los subpasos de
   imagen (paso 3).~~ HECHO en host en Fase 5b; falta el
   mismo camino en la APK (GLES3).
3. Callback async de DVD + struct `DVDFileInfo` (los
   reads ya son síncronos; falta avisar al juego).
4. Input: PADStatus real + mapeo táctil/mando (el juego
   ya encuesta PAD cada frame; la inyección Start de
   diagnóstico no produce efecto observable, ver Fase 5b).
5. Audio DSP real (tareas DSP, no solo el evento de
   init) + backend de audio.
6. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).


## Fase 5b (este tramo): máquina GX en host, texturas verificadas, renderer host y diagnóstico Start

Trabajo en `android-port-base` (commit del tramo al final).
Ficheros: `cpu/cpu.{h,c}` (captura FIFO, ventana de 32 B),
`gamecube_runtime/hle.{h,cpp}` (OSReport, TexLoads, PAD de
diagnóstico), `gamecube_runtime/gx_texture.{h,cpp}` (nuevo),
`gamecube_runtime/gx.{h,cpp}` (nuevo). Tests host en
`work-port/fase2-tests/` (fuera del repo): `test_gx.cpp` /
`build_gx.sh` (runs 15–19), `test_gx_tex.cpp`,
`test_gx_parse.cpp`, `test_gx_render.cpp` (runs 19).

### Captura FIFO (corrección real, no cosmética)

La captura inicial solo enganchaba `0xCC008000` exacto, pero
el helper de matriz del SDK usa `psq_st` y su segundo float
va a `0xCC008004`. El pipe write-gather acepta la ventana
`0xCC008000–0xCC00801F` (32 B, con recorte en el borde) y
acumula en orden de store. Efecto medido: el FIFO pasó de
5.575.591 B (run15) a **5.575.663 B (run19, referencia
vigente)**, +72 B = 18 floats × 4 B, y las 3 matrices de
posición pasaron a identidad limpia. Búfer lineal de 32 MB,
al llenarse deja de añadir pero sigue contando (overflow
marcado, nunca sobrescritura silenciosa). Desactivada por
defecto; global monohilo como la traza HW.

### OSReport HLE (solo observación)

`OSReport` 0x8007D8C0 es un stub retail de 0x50 B (vuelca
r3–r10 y f1–f8 a la pila y retorna, sin imprimir nada). El
HLE formatea (enteros r4–r10, flotantes f1–f8, resto en pila
del llamador: arg entero nº k ≥ 7 en `sp + 8 + 4*(k-7)`,
verificado con la línea `mem` de 16 args; flotantes en pila
se marcan `[pila-f]`, no se inventan), guarda hasta 200.000
líneas y loguea las 500 primeras. run19: 24.973 llamadas,
24.923 de ellas la línea por frame
`thread: state=0 attr=0 suspend=0` (sin valor discriminante)
y 50 de init (líneas `mem`/`slot` completas, p. ej.
`mem 0k/11488992k 0k/1835008k 0k/655264k 316448k/4587424k`).
Ninguna línea menciona press/start/title/button/pad/input.

### Diagnóstico Start: resultado negativo, con evidencia

Inyección Start (0x1000) por dos vías en test host, ambas
sin ningún cambio observable en FIFO, DVD, HLE ni OSReport:
(a) vía `PADRead` (run16: contadores idénticos a run15,
FIFO byte-idéntico SHA-256
`b8210738e87adf5bf1e978d973069ae3631d8f2dc3d0882212054357dc8eb579`,
globales PAD a 0 al final); (b) poke directo en
`OSSleepThread` (run17: Held/JustPressed quedan en 0x1000
en RAM al final, pero el FIFO sigue byte-idéntico). La vía
(b) queda invalidada como prueba: `padUpdate` recomputa los
globales desde el buffer `PADRead` antes de la lógica del
frame siguiente, así que el poke se borra antes de leerse.
La vía (a) es la prueba válida y tampoco muestra efecto.
Conclusión honesta: con Start mantenido ~24.921 frames no
hay cambio observable. **No se puede distinguir pantalla de
título vs pantalla de carga animada con esta evidencia.**
Hipótesis abiertas, sin decidir: `padUpdate` toma la rama
err y borra el buffer/globales, o el juego lee input por
otra vía (interrupciones SI); o la pantalla no espera input
en esta fase (logos temporizados/atascados, ver «bucle
estable» abajo). `padUpdate` 0x80014F6C verificado desde el
código: globales Previous 0x8033B210, Held 0x8033B220,
Released 0x8033B230, JustPressed 0x8033B240; `PADClamp`
0x8024E458 no toca botones (si err != 0 retorna; si err
== 0 solo ajusta sticks/triggers). La inyección es solo
test host: la APK nunca llama a `SetPadInject`.

### GXTexObj: layout cerrado y verificado

`GXTexObj` = 32 bytes en `struct_juego + 32`: +0 mode0, +4
mode1, +8 empaquetado (ancho `(v&0x3FF)+1`, alto
`((v>>10)&0x3FF)+1`, formato `(v>>20)&0xF`), +12 dirección
de imagen (`0x80000000 | ((w<<5) & 0x01FFFFFF)`), +16 user
data (struct del juego), +20 formato en plano, +28 u16
(tiles), +30/+31 (LOD/tile). Struct del juego: +10/+12
ancho/alto u16, +22 formato, +23/+24 wraps, +32 GXTexObj,
+64 flag, +68 tamaño base (palabra en texObj+36), +96 datos
embaldosados (texObj+64). Los 3 texObjs vivos de run19
verifican todo (tamaño de campo = tamaño base calculado):

- `0x816C0020`: 376×104, IA8 (3), imagen `0x816C0060`,
  78.208 B — barra blanca redondeada (UI).
- `0x816D3200`: 128×160, RGB5A3 (5), imagen `0x816D3240`,
  40.960 B — logo Rareware (R dorada sobre azul oscuro).
- `0x816DD260`: 180×92, CMPR (14), imagen `0x816DD2A0`,
  8.832 B — logo Dolby Pro Logic II (tile CMPR de 32 B:
  23×12×32 = 8.832 exacto; con 64 B daría el doble).

**Origen verificado, no el esperado:** ninguno de los 3
coincide con ningún fotograma de `texturas.csv` por
(ancho, alto, formato) ni por datos base byte-idénticos en
los bancos raíz. Agujas del medio (1.024 B) sí aparecen en
`main.dol`, sección `data5` (fileoff 2.885.344, guest
`0x802C36E0`): son activos embebidos en `.rodata` del DOL,
copiados al heap por el juego, no texturas de bancos TEX.
El decodificador trabaja sobre los bytes RAM, sea cual sea
su origen, así que esto no bloquea el renderer. Queda
pendiente una búsqueda con aguja larga en bancos de mapa y
contenedores no-TEX solo si se quiere cerrar ese cabo.

### Conversiones de textura verificadas (C++ contra referencia)

Porte de `decode_pure` del extractor a
`gamecube_runtime/gx_texture.*` (mismos tiles, ensanchados,
CMPR con subbloques fila-mayor e índices MSB-primero,
RGBA8 con planos AR + GB, IA8/IA4/I4/I8). Test host
`test_gx_tex.cpp` contra las muestras de `run15/texverify/`
(decodificadas con el extractor Python verificado):
**10 PASS, 0 FAIL** — IA8 8×8, CMPR 64×48, RGB5A3 32×32,
RGBA8 32×32, I8 32×32, IA4 32×32, I4 128×128 (todas byte a
byte contra el `.rgba` de referencia), RGB565 sintético
4×4 (0 casos reales en este disco, documentado como
sintético), errores (paleta → false, tamaño incorrecto →
false) y placeholder magenta 2×2. Bug encontrado y
corregido en el porte: el tile CMPR era 64 B y debe ser
**32 B** (4 subbloques DXT1 de 8 B por tile 8×8). Formatos
de paleta (8/9/10) devuelven false: necesitan TLUT que no
va en el blob; 0 casos reales en este disco. Dirección sin
resolver → log + placeholder magenta documentada, nunca
texturas inventadas.

### Máquina GX en host (`gamecube_runtime/gx.{h,cpp}`)

Parser C++ sin dependencias Android (stdlib solo): NOP,
CP (1+1+4), XF (1+4+4n), BP (1+4, registro en byte alto),
DL (1+4+4, leída de RAM guest, profundidad ≤ 4), INV y
draws (1+2+vertices). Los códigos 0x20/0x28/0x30/0x38 no
aparecen y se reportan como desconocidos sin adivinar
payload. VAT según YAGCD + VCD global (CP 0x50/0x60);
layout VAT1 validado por patrón y valores:
`[texmtxidx u8][pos XYZ s16][tex ST f32] = 15 bytes`
(byte 0 = 0x3C = 60 = GX_IDENTITY en todos los vértices;
texcoords (0,0),(1,0),(1,1),(0,1) exactas). Atributos
indexados NO se decodifican (se reportan; todo el stream
actual es directo). Textura vigente por draw desde la
lista externa `TexLoads` (el HLE la registra con offset
FIFO), no desde BP: el stream de esta fase NO trae BP de
textura porque `GXLoadTexObj` está HLEado.
**Validación (`test_gx_parse.cpp`, run19, 10 PASS):**
parseo completo a EOF sin desconocidos, **602 draws QUADS
VAT1**, 0 DLs, 0 indexados, viewport [320, −240, 16777215,
662, 582, 16777215], proyección orto en el primer draw
(tipo 1, [0.003125, −1.0, −0.003809, 0.9123, −0.0101,
−1.0101]), primer draw full-screen (0,0)–(640,480) z −0.5
decodificado, último draw Dolby en offset 321.757.
Escala de posiciones: **empírica /16 para VAT1** (el quad
(0,0)–(10240,7680) solo cuadra con 640×480 así; el campo
POSSHFT vale 2, así que la fórmula usada es
`2^(shift+2)`); pendiente de confirmar contra otro VAT o
contra el código SDK — no bloquear el render diagnóstico.
Semántica de BP reg `0x00` con valores tipo color queda
observada pero sin cerrar (reg-en-byte-alto confirmado,
no es error de parseo).

### Renderer host: frame real, con evidencia

`test_gx_render.cpp` (fuera del repo): replay de los draws
con la transformada GX estándar (pos_matrix del draw →
proyección orto → viewport → región EFB (342,342)–(982,822)
= canvas 640×480), rasterización por triángulos con
interpolación baricéntrica de (s,t), texturas decodificadas
desde `ram.bin` (layout GXTexObj arriba). **602/602 draws
renderizados, 0 saltados** (`run19/frame602.ppm` + `.txt`).
Desglose: tex 0 (sin textura) 1 draw, barra 241, Rare 240,
Dolby 120. El full-screen con texel (0,0) de la barra es
negro real (la esquina de la textura es negra), así que el
fondo sale negro; el draw 1 sin textura usa gris-azul
diagnóstico (32,32,64), documentado como NO color real
(TEV pendiente), pero queda tapado por el draw 3. La
altura 439 del full-screen y el desplazamiento vertical
son el resultado de la proyección orto del juego, no un
error del renderer. Fases por separado (cada una sobre
negro, asumiendo el clear estándar entre pantallas de
logo): `frame_barra.ppm` (242 draws, 1.689 px no negros),
`frame_rare.ppm` (240 draws, 809 px), `frame_dolby.ppm`
(120 draws, 398 px). **Verificación visual:** el logo Rare
sale vertical con la R dorada legible (sin flip vertical);
la geometría y la orientación de textura son correctas.
Caveat honesto: el compuesto de 602 draws muestra barra +
Rare + Dolby solapados arriba a la izquierda (las
coordenadas del juego los ponen ahí: barra (33,60)–
(127,84), Rare (64,58)–(99,98), Dolby (57,65)–(107,88) en
canvas), porque entre fases el FIFO no trae ningún clear
por draw; si el juego limpia el EFB entre fases, lo hace
por un mecanismo fuera del FIFO (copia PE con clear, no
visible en la traza de eventos truncada) y entonces las
pantallas individuales son las de `frame_*`. El mecanismo
de clear queda como verificación pendiente, no como
afirmación. **Después del offset ~321.757 no hay más
draws en todo el stream** (5,25 MB restantes): el bucle
estable emite solo estado (frame estable ~216 B: INV +
BP + XF viewport, 0 draws, sin reescribir proyección ni
VAT/VCD), así que el frame visible del bucle es el último
dibujado (Dolby), retenido en el EFB. Esto invalida la
idea inicial de «un frame del bucle con draws». El bucle
estable (24.921 frames sin dibujar) no encaja con un
temporizador simple de logos: candidatos, el callback
async de DVD nunca invocado o el contador de retraces VI
por interrupción (que nunca se entrega;
`VIWaitForRetrace` solo ×2 en todo el run).

### No-regresión host (run20, tras todos los cambios)

`build_gx.sh run20 5000000 300 baseline` (58,875 s):
motivo `dispatch_cap`, 5.000.000 despachos, PC final
`0x802440BC`, exception 0, unknown 0, main = 1, init = 1,
HLE totales 175.450, retrace 2, FIFO 5.575.663 B sin
overflow. Desglose HLE **idéntico** a run19 (diff vacío):
`PADRead` ×24.923, `DVDOpen` ×89, `DVDReadAsyncPrio` ×82,
`GXLoadTexObj` ×600, `OSReport` ×24.973, `OSSleepThread`
×24.921. FIFO **byte-idéntico** a run19 (SHA-256
`fb2ba7f822a654623841fad6f400fbfb6a78b8ffc244011750d88d80dcb2014e`).
Sin regresión frente a run19 ni a run14.

### Build NDK (verificación Fase 5b)

Build `ndk-fase5b`, JOBS=4 (directorio nuevo, 178 C +
16 C++ desde cero; el primer intento con JOBS=2 se
reinició a JOBS=4 sin pérdida porque el script escribe
`.o.tmp` y solo renombra al terminar): PASS, **0 errores**
(0 líneas `error:`; los «error» del log son símbolos del
runtime C++, `logic_error`/`length_error`).
`libstarfox.so` **27.300.944 B**, ELF64 `DYN` AArch64,
SHA-256
`ea78bc86240727d77709f777cf8e6e3ac931b45fcdf2cfb045bb40e9bfe80084`
(Fase 5: 27.260.624 B,
`c24a7eab1e9eaf578320ceedaea3908dca353abf2f237adb3c0c8766f9efb6ed`),
comprobación del script «OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver», 124 undefined
totales (solo libs del sistema; 120 en Fase 5).
`android_main` en `T`, `dolrecomp_call_depth` en `B`,
`GxParser`/`GxDecodeTexture` en `T` (30 símbolos `sfa.*Gx`),
`gx.cpp`/`gx_texture.cpp`/`cpu.c`/`hle.cpp` compilados
limpios por separado con clang NDK r28c antes del enlace
completo.

### Qué queda (tras Fase 5b, en orden)

1. Renderer en APK (GLES3): el camino host funciona; falta
   el mismo camino en la APK (quads texturados desde el
   parser + texturas decodificadas) cuando haya SDK.
2. ~~Callback async de DVD + struct `DVDFileInfo`:~~ HECHO
   en Fases 6–7 (ver sección «Fases 6–7»); queda el contador
   de retraces VI por interrupción (callbacks pre/post).
3. ~~Input: PADStatus real + mapeo táctil/mando:~~ HECHO en
   Fase 6b salvo botones táctiles en pantalla, rumble y el
   flanco JustPressed con pulsación real (ver «Fases 6–7»).
4. Mecanismo de clear EFB entre fases (copia PE) y fórmula
   exacta de escala de posiciones / semántica de BP 0x00
   (pendientes, no bloquean el render diagnóstico).
5. ~~Audio DSP real + backend de audio:~~ backend AAudio
   HECHO en Fase 7 (sin probar en dispositivo); quedan DSP
   real, secuencias MusyX y el mapeo ID → WAV.
6. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).

## Fases 6–7 (2026-10-25, este tramo): desbloqueo post-Dolby, input y audio

### 1. Fase 6a — DVDFileInfo real y callback async de DVD

Layout verificado contra el propio código SDK del DOL (no un
manual externo): `DVDOpen` (0x80249548) escribe +48 = offset
de disco de la entrada FST, +52 = longitud de la entrada FST,
+56 = 0, +12 = 0; `DVDReadAsyncPrio` (0x80249858) lee +52,
guarda el callback en +56 y llama a `DVDReadAbsAsyncPrio`;
`cbForReadAsync` (0x80249918) invoca +56 con r3 = resultado,
r4 = fileInfo. El código del juego confirma +52:
`loadFileByPathAsync` (0x80015A38, `lwz r29,52(r30)`) y el
cargador de romlists (0x800485E4) reservan por esa longitud.

**Bug previo encontrado:** el HLE anterior no escribía +52,
así que ambos reservaban 0 y las 82 lecturas async de run20
eran de 0 B (la init de audio «rápida» era falsa: no cargaba
nada). `DvdOpen` ahora escribe +12 = 0, +48 = offset FST
(o 0 sin FST), +52 = tamaño real del fichero host, +56 = 0;
si la escritura guest falla, el open devuelve 0 (un struct a
medias es peor que un fallo visible). FST: candidatos
`SetFstPath`, `<disc_root>/../sys/fst.bin`,
`<disc_root>/sys/fst.bin`; formato: nº de entradas en +8,
entradas de 12 B, tabla de nombres tras `12*count`;
directorios abren rangos `[i+1, length)`; nombres con una
`/` inicial quitada; fallback por basename solo si es único
en el FST (3.874 ficheros parseados en el test).

`DVDReadAsyncPrio` ahora lee en síncrono y **despacha el
callback del juego como código huésped**: lr intacto (retorno
del llamador), r3 = bytes leídos, r4 = fileInfo, pc =
callback; el `blr` del callback vuelve al llamador original.
r3 debe ser bytes, no 0 de «éxito»: el wrapper `DVDRead`
(0x80015888) guarda r3 en `[r13-26664]` y solo sale del bucle
si no es 0/-1/-3. Callbacks del juego verificados:
`DvdRead_Callback` (0x8001598C), `initLoadFileReadCb`
(0x80041EC4), `romListReadCb` (0x8004276C),
`animCurvReadCb` (0x800423D4) y los de audio (0x8000975C,
0x800096AC, 0x80009594, 0x800094E4, 0x80009434, 0x80009384,
0x800092D4, 0x80009224, y más tarde 0x80009174, 0x800090C4,
0x80009014). Aviso documentado: una lectura async de 0 B se
registra como advertencia, porque el wrapper la trata como
«pendiente» (hay ficheros vacíos en disco, p. ej. varios
`VOXMAP.bin`, sin evidencia aún de que el juego los lea por
async).

**VI retrace (modelo de frontera de frame):** `OSSleepThread`
(desde `waitNextFrame` 0x8004ABE0) incrementa el contador:
cada sueño completado esperando el siguiente retrace ES un
retrace entregado (uno por frame dormido, la cadencia que el
juego espera). `VIWaitForRetrace` avanza al siguiente retrace
(+1, retorno inmediato, nunca bloquea); solo se llama en
`tvInit` (×2 en run20), sin doble conteo en el bucle. NO se
deriva del timebase del chassis (+200/despacho, ~40k/frame):
un contador a 50 Hz sobre él solo marcaría cada ~243 frames
del bucle, una escala falsa. Pendiente: los callbacks VI
pre/post retrace que registra el juego
(`VISetPreRetraceCallback` 0x8024CB14,
`VISetPostRetraceCallback` 0x8024CB58, desde 0x80049F48/54 y
el reproductor THP) todavía NO se entregan; sus punteros
viven en el estado VI del SDK (código huésped, sin HLE) y
localizar ese estado es el siguiente paso.

**Drenajes ARQ (tres, todos por evidencia de ejecución):**

1. `aramUploadData` (0x802849EC): el contador de su cola
   ([r31+641]) se drena con los pendientes SDK (patrón
   aramInit). Desbloqueó run21 (contador en 16).
2. `aramSyncTransferQueue` (0x80284B84): la última subida de
   una serie no tiene un wait-head posterior que la drene;
   el sync completa una DMA por cesión (contador −1; si
   quedan pendientes SDK, también −1). Desbloqueó run23
   (50M despachos en el mismo estado que run22: contador
   0x803D5B41 = 1, índice 3, slots con +28 =
   `aramQueueCallback` 0x80284910 y +32 = 0).
3. `AudioAramWriteSync` (0x80008FDC, este tramo): el juego
   postea con `ARQPostRequest` (0x802516D4, código huésped:
   struct en 0x803372A0+slot*48, +28 = callback, +0 =
   siguiente de la lista de la cola 1, head/tail en
   [r13-20816]/[r13-20812]) y gira hasta que
   `AudioAramWriteCompleteCallback` (0x80009008: stw 1 en
   [r13-27076]; blr) ponga el flag. run25b (50M despachos)
   quedó ahí con el flag a 0 y un elemento en la cola 1
   (slot 0: +28 = 0x80009008, src 0x8054C700, dst ARAM
   0x00EC93E0, len 1272864). El HLE entrega ahora ese
   callback como código huésped (lr = el propio spin head,
   para volver al giro y salir por el epílogo normal, con
   registros restaurados; r3 = la petición) y desenlaza la
   petición antes de despachar. Limitación heredada: los
   callbacks +32/+36 de los slots del array ARQ
   (`aramQueueCallback`) siguen sin invocarse en los
   drenajes por contador; si el juego espera uno, el
   siguiente atasco lo dirá con su PC y su flag.

**Diagnóstico mm no fatal (registrado, no un fallo):** tras
los callbacks de audio, el juego imprime `5: *** mm Error
*** ---> Can't free ram at this location: 81205e00`
(`mmFree` sobre el fileInfo 0x81205E00) y CONTINÚA cargando
el siguiente fichero (run22/run24/run25: mismo patrón). Solo
aparece cuando las lecturas tienen éxito (el camino correcto);
las escrituras HLE replican exactamente las del SDK, así que
no es corrupción nuestra. No bloquea.

### 2. Fase 6b — PADStatus real e input

`PADStatus` (12 B/mando, libogc, verificado en `padUpdate`
0x80014F6C): +0 botón u16 BE, +2 stickX s8, +3 stickY s8,
+4 substickX s8, +5 substickY s8 (se comprueba contra ±40),
+6 triggerL u8, +7 triggerR u8, +8 analogA u8, +9 analogB u8,
+10 err s8, +11 reservado 0. `PADClamp` (0x8024E458) no toca
botones (solo sticks/gatillos, y retorna pronto si err != 0).

**El misterio Start, resuelto desde el código del juego:**
`padUpdate` usa dos slots de 48 B (0x8033B250/0x8033B280) y
globales de 4 palabras (Previous 0x8033B210+4i, Held
0x8033B220+4i, Released 0x8033B230+4i, JustPressed
0x8033B240+4i). Tras `PADRead` y `PADClamp`, lee un flag de
«muestra fresca» en [r13-25827] = 0x803DE65D: si es 0,
descarta el `PADRead` y copia el slot anterior (ceros en el
primer frame); si no es cero, usa el dato fresco y lo limpia
al final. El único escritor observado además del clear de
`padUpdate` es `gpuErrorHandler` (0x80049810); en hardware
real el evento de muestreo SI lo pondría entre frames. Esto
explica run16 exactamente: la inyección escribía Start en el
búfer, pero el flag era 0 y `padUpdate` copiaba el slot
anterior (cero). **Corrección HLE:** `PADRead` escribe
siempre los 48 B (mando 0 desde el `PadState` actual, mandos
1–3 con err = −1 = 0xFF, sin mando, como el SDK) y pone el
flag 0x803DE65D = 1 antes de que `padUpdate` lo lea (el mismo
punto lógico que la muestra SI en hardware). El retorno
sigue siendo 0, que el chequeo de `padUpdate` en 0x80014FC0
acepta. El poke directo en `OSSleepThread` sobre Held/
JustPressed se ELIMINÓ: `padUpdate` recomputa esos globales
desde el búfer, así que el poke se borraba antes de leerse.

`PadState` (`input/pad_state.h`, sin dependencias Android):
bits libogc (D-pad LEFT 0x0001, RIGHT 0x0002, DOWN 0x0004, UP
0x0008, Z 0x0010, R 0x0020, L 0x0040, A 0x0100, B 0x0200,
X 0x0400, Y 0x0800, START 0x1000); `SyncAnalogFromButtons()`
(L/R todo o nada: bit → gatillo 255; A/B igual para
analogA/B). `Input::HandleEvent` mapea y devuelve true solo
si cambió el estado (consumido): gamepad (A/B/X/Y, L1/R1/
L2/R2 → L/R, START, DPAD, Z), teclado (flechas = D-pad,
Enter = Start, Z = botón Z), joystick (AXIS_X/Y → stick
izquierdo, Y invertida; LTRIGGER/RTRIGGER > 0,5 → L/R bit +
255; AXIS_Z/RZ deliberadamente ignorados: C-stick = 0 en
esta fase), táctil (primer dedo, arrastre desde el anclaje →
stick, 100 px = deflexión total, ±127). Botones táctiles en
pantalla NO mapeados todavía: no hay layout definido y un
layout inventado por cuadrantes sería peor que la ausencia.
Rumble no-op en esta fase (`PADControlMotor` sin HLE; el
juego no lo ha llamado en los runs). Cableado:
`GameCubeRuntime::Init` llama `hle_.SetPadState(input_.StatePtr())`;
`native-lib.cpp` `HandleInput` reenvía al Input del runtime
y devuelve 1 solo si se consumió (antes devolvía 0 y nunca
reviaba).

### 3. Fase 7 — Audio por WAV extraídos

API sin cambios (Init/Shutdown/Pump/Start/Stop/SubmitBuffer/
SetMasterVolume); `SubmitBuffer` toma frames estéreo s16 a
la frecuencia de salida. **Decisión de backend, documentada:**
AAudio en Android. OpenSL ES deliberadamente NO
implementado: minSdk es 26 y AAudio existe desde API 26, así
que el caso «AAudio no disponible» no puede darse en esta
app, y un segundo backend sería improbable aquí. Si AAudio
falla al abrir en un dispositivo concreto, `BackendOk()` =
false, `SubmitBuffer` sigue encolando sin crashear y el log
lo reporta. Implementación (guardada por `__ANDROID__`):
builder, 48.000 Hz, estéreo, PCM16, modo baja latencia,
callback de datos que drena el anillo; `EXCLUSIVE` primero,
`SHARED` si falla. Enlace con `-laaudio` (CMakeLists y
`build-libstarfox-ndk.sh`; NDK r28c provee `libaaudio.so` y
`aaudio/AAudio.h` para API 26). En host, backend nulo
contable: `Pump()` drena el anillo y cuenta frames
entregados (en Android `Pump()` es no-op: drena el callback
AAudio). Anillo productor/consumidor único de 262.144
frames estéreo (~5,5 s a 48 kHz), índices atómicos; si se
llena, se descartan los frames más antiguos y
`DroppedFrames()` los cuenta (el audio del juego nunca debe
bloquear un frame). Volumen maestro 0–1 aplicado al enviar.

Cargador WAV (`LoadWavFile`): RIFF/WAVE, PCM formato 1,
PCM16, 1–2 canales, cualquier frecuencia; resto de chunks
saltados con padding par. Todos los WAV del inventario son
PCM16, suficiente para esta fase. Resampleo
(`ResampleToStereo`): interpolación lineal a estéreo 48.000
Hz; mono duplicado a ambos canales; frames de salida =
`floor(in_frames * 48000 / in_rate)` (mínimo 1). HLE de alto
nivel por fichero (`PlayWavFile`): carga un WAV real
extraído, resamplea a 48 kHz estéreo y lo envía; devuelve
frames enviados o −1 si no se puede leer. Límite
documentado: para ficheros largos, el llamador debe drenar
entre trozos (el test host lo hace); `PlayWavFile` solo sobre
un fichero mayor que el anillo descarta los más antiguos y
los cuenta. Es directo para muestras MusyX cortas (< 1 s).
**NO hecho en Fase 7:** mapeo ID de sonido del juego → ruta
WAV (tablas `Streams.bin`/`Sfx.bin`/`.sdi` sin parsear),
secuencias MusyX (`.pro`/`.poo`/`midi.wad`), emulación DSP.
La fase prueba que un ID real (una ruta real del inventario)
produce salida; el cableado a los `snd*` del juego es el
siguiente paso.

### 4. Verificación host (runs, sin regresión enmascarada)

Test `work-port/fase2-tests/test_phase6.cpp` (fuera del
repo, no se commitea): modos `unit` (chequeos HLE/audio
directos), `baseline` (bucle sin inyección) y `start` (Start
0x1000 vía `PADRead`).

- **Unit (run21-unit): todo PASS.** `DvdOpen MAPS.bin` = 1,
  +52 = 111.648, +48 = 0x7C79600, +12 = 0, +56 = 0 tras open,
  FST cargado, 0 fallos de escritura fileInfo. Con `/` inicial:
  `DvdOpen /audio/data/Music.bin` = 1, +52 = 2.544. Callback
  async sin ejecutar el chunk: `DVDReadAsyncPrio` con
  fileInfo MAPS.bin, 1.024 B, callback 0x8001598C, lr
  0x80015AA4 → pc = 0x8001598C, r3 = 1.024, r4 = fileInfo,
  lr intacto, 1 callback, 1.024 B async, +56 = callback.
  PAD: `PADRead` con Start y stick (40, −30) → mando 0
  botones 0x1000, stickX 40, stickY −30, err mando 0 = 0,
  err mando 1 = 0xFF, flag 0x803DE65D = 1. Audio: stream
  `assets/extraidos/audio/streams/AN/an1301.wav` (32.000 Hz
  estéreo) → 1.892.352 frames a 48 kHz (exacto:
  frames*48000/32000), no silencioso, entrega chunked
  (8.192 frames con Pump entre medias) exacta con 0
  descartados. MusyX
  `assets/extraidos/audio/musyx/starfoxm/0000_SFXdn_boar1_c.wav`
  (22.050 Hz mono, 3.477 frames) → `PlayWavFile` 7.568
  frames a 48 kHz, entregados > 0.
- **run21 (5M): REGRESIÓN diagnosticada.** Solo 198 HLE,
  DVDOpen ×7, async ×7, 5.500.544 B async, 7 callbacks (solo
  audio), FIFO 828 B (SHA-256
  `60451a6e775565276c630eb1ecda553120e371cbc8a6112c227b4bb00cf6c07f`,
  distinto de run20), PC final 0x802849EC, PADRead ×1,
  retrace 2, exception 0. Causa: los callbacks DVD síncronos
  dispararon subidas ARAM de audio, pero las completaciones
  ARQ solo se drenaban en el spin de aramInit, así que
  `aramUploadData` giraba con su contador en 16. Fix: drenaje
  del wait-head de subida (punto 1 arriba).
- **run22 (5M, 24,560 s) y run23 (50M, 477,137 s): segundo
  atasco, real (no lentitud).** Estado idéntico: PC
  0x80284B84 (`aramSyncTransferQueue`), HLE 775, drenajes de
  subida 593, PADRead ×1, FIFO 828 B mismo SHA. Fix: drenaje
  del sync-wait (punto 2 arriba).
- **run24 (5M, 62,542 s): AVANCE.** HLE 1.669, DVDOpen ×12,
  async ×12, close ×12, 16.855.828 B async, 12 callbacks en 8
  callbacks distintos (los 7 anteriores + 0x80009224),
  drenajes de subida 1.425, de sync 47, PC final 0x80008FDC
  (código del juego, ya no un spin del SDK), exception 0,
  PADRead ×1 (bucle aún no alcanzado: sigue en init/carga,
  ahora cargando más datos), FIFO aún 828 B (el stream
  pre-logo, no el frame run20). Cada megabyte por esta
  emulación cuesta muchos despachos, así que 5M ya no llegan
  al bucle (en run20 la init era «rápida» justo porque no
  cargaba nada).
- **run25b (50M, 276,531 s): tercer atasco, real.** Estado
  idéntico a run24 (PC 0x80008FDC, HLE 1.669, 12 opens) con
  45M despachos más: la prueba de que no era lentitud. Fix:
  entrega del callback ARQ por petición (punto 3 arriba).
  (run25, el intento anterior a 50M, murió sin resumen por
  limpieza del lanzamiento detached del proceso; se
  relanzó como run25b en primer plano y completó.)
- **run26 baseline (5M, 24,078 s): AVANCE HASTA EL FRONTAL,
  luego excepción (ver punto 5).** 1.849.789 despachos,
  motivo `exception`, HLE 1.982, DVDOpen ×98, async ×98,
  close ×96, 20.083.124 B async, 98 callbacks, drenajes de
  subida 1.425, de sync 47, callbacks ARQ 1, GXLoadTexObj ×2
  (¡nuevos draws!), FIFO 2.100 B, PADRead ×2, OSReport ×4,
  exception 0x00000001 en PC final 0x8006A0E0. El juego
  cargó `PREANIM.tab`, `ENVFXACT.bin`, `animtest/TEX0.bin`,
  `gametext/Link/English.bin` y
  `gametext/FrontEnd/English.bin`, creó un hilo
  (`OSCreateThread`, registrado, sin ejecución real) y
  llegó a procesar frames (`newshadows_beginFrame`).
- **run26-start (5M, 23,310 s): INPUT VERIFICADO.** Idéntico
  a run26 salvo el input: PADRead #1 y #2 con botones
  0x1000 (Start vía `PADRead`, relectura 0x10000000),
  Held0 = 0x00001000, Prev0 = 0x00001000, Just0 = 0x00000000
  (correcto: Start mantenido desde el arranque no tiene
  flanco; una pulsación real posterior daría JustPressed).
  Mismos despachos (1.849.789), mismos HLE, misma excepción:
  el flujo no cambia porque la excepción del punto 5 precede
  a cualquier lógica de título que lea Held. La vía PADRead
  queda probada; el efecto en el flujo queda pendiente de
  superar el punto 5. El test de `start` en run20 (sin el
  flag de muestra fresca) daba FIFO byte-idéntico: ese
  diagnóstico queda invalidado por el flag, no por el poke.

### 5. Bloqueador siguiente: excepción por caché NULL (sin maquillar)

**CORRECCIÓN (Fase 8, con evidencia de watchpoint): el texto
de abajo invierte `getCache` y su historia de release queda
superada.** Lo verificado en run27: `getCache` devuelve
`0xE0000000` cuando el estado [r13-23424] es 4 o 0, y el
puntero [r13-23404] en otro caso (no al revés); y en ese run
las únicas escrituras a la estructura de caché (0x803DEFC0–
0x803DF060) fueron el borrado BSS de arranque
(0x80003434–0x80003454): ni `releaseMovieBuffers` ni
`prepareMovie` corrieron, así que el estado era 0 por BSS y
el puntero 0 por BSS, y la exception 1 no fue una escritura
en 0 sino en `0xE0000000` sin mapear en `mem_*` (el HLE de
`LCEnable` no hacía nada y el `_LCEnable` huésped, que
programa DBAT3 y borra 16 KiB con `dcbz`, nunca corría).
Se conserva el texto original debajo como registro del
diagnóstico previo; la causa raíz real y la solución están
en «Fase 8», punto 1.

`updateHeavyFogTexture` (0x8006A09C) llama a `getCache`
(0x80022BB0), que devuelve [r13-23404] cuando el estado
[r13-23424] es 0 o 4, y 0xE0000000 en otro caso. En run26,
el estado final es 0 y el puntero es 0x00000000: el bucle
escribe con `stbx r0, r4, r3` en r4 = 0 → fuera de rango →
exception 1 (la semántica documentada de `mem.*`: fuera de
rango = lectura 0 / escritura ignorada + exception = 1).
El PC reportado (0x8006A0E0) es el inicio del bloque del
bucle, no la instrucción `stbx` exacta. Llamadores de
`updateHeavyFogTexture`: `newshadows_beginFrame`
(0x8006CB00, desde 0x8006CC84) y `allocLotsOfTextures`
(0x8006D7CC, desde 0x8006E794). La función que deja el
puntero a 0 es `n_attractmode_releaseMovieBuffers`
(0x80116548): si el estado != 2, libera todos los búferes
de la caché con `mm_free` (0x80023968) — incluido
[r13-23404] — y pone el estado a 4. Es decir: tras liberar
los búferes de la película del attract-mode, el juego
empieza frames (sombras/niebla) sin haber re-inicializado
la caché. Hipótesis abiertas, sin evidencia aún para
decidir: (a) el re-init vive en un hilo que el chassis
monohilo no ejecuta (`OSCreateThread` solo registra; en
run26 se creó un hilo en 0x801383AC sin ejecución real);
(b) el re-init cuelga del callback de fin de película THP
(jugador THP pendiente, como CARD). Siguiente paso:
localizar quién escribe [r13-23404] fuera del free
(0x80116620/0x8011678C/0x801168A4 son escrituras dentro
del propio free) y su condición de disparo; NO parchear
con un búfer falso.

### 6. Build NDK (verificación Fase 6–7)

Build `ndk-fase6b`, JOBS=4 (directorio nuevo, 178 C + C++
desde cero; el intento anterior `ndk-fase6` con JOBS=2 se
perdió al limpiarse su sesión, sin riesgo porque el script
escribe `.o.tmp` y solo renombra al terminar): PASS, **0
errores**, exit 0. `libstarfox.so` **27.326.912 B**, ELF64
`DYN` AArch64, SHA-256
`9d00fe0a94487f61655d34bfe6ea2f63f557b6516eccf9ffc6a1e904074a7410`
(Fase 5b: 27.300.944 B,
`ea78bc86240727d77709f777cf8e6e3ac931b45fcdf2cfb045bb40e9bfe80084`),
comprobación del script «OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver», 151 undefined
totales (solo libs del sistema; 124 en Fase 5b: el delta
incluye las nuevas referencias `AAudio*` del backend de
audio y símbolos de runtime C++ del código nuevo).
`android_main` en `T`, `AAudioStreamBuilder_*` en `U`
(sistema, esperado). APK Fase 0 intacta: SHA-256
`b07a6af555246d442808208563efa8b0d423c7bd916aa9fc8938b1484bbf07d1`
(57.916 B, sin reconstruir en este tramo).

### 7. Qué queda (tras Fases 6–7, en orden)

1. Bloqueador nº 1: re-init de la caché de texturas tras el
   attract-mode (punto 5 arriba).
2. Callbacks VI pre/post retrace (el estado VI del SDK).
3. Mapeo ID de sonido del juego → WAV; secuencias MusyX;
   DSP real.
4. Botones táctiles en pantalla (layout por definir),
   rumble, flanco JustPressed con pulsación real.
5. Renderer GX en APK (GLES3) con el camino ya verificado
   en host; THP; CARD; hilos reales.
6. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).

## Fase 8 (2026-10-26, este tramo): bloqueador nº 1 resuelto, callbacks VI, flanco JustPressed

### 1. Bloqueador nº 1: causa raíz real y solución (sin parche falso)

Instrumentación añadida para el diagnóstico (con variables de
entorno, apagada por defecto, segura para NDK/APK):
`SFA_WATCH_CACHE` en `cpu/cpu.c` registra cada escritura en la
región de la estructura de caché del attract-mode
(0x803DEFC0–0x803DF060) con PC y LR huésped exactos, y
`SFA_PCTRACE` en `chassis.cpp` registra la entrada a un conjunto
de funciones trazadas (solo despachos cross-chunk; las llamadas
intra-chunk son gotos y no se ven).

Hallazgos decisivos (sustituyen el diagnóstico de «Fases 6–7»,
punto 5):

- `getCache` (0x80022BB0) NO devuelve 0 cuando la caché está
  inactiva: lee el estado [r13-23424]; si es 4 o 0 devuelve
  `0xE0000000` (`lis r3, -8192`); en otro caso devuelve el
  puntero [r13-23404]. Con r13 = 0x803E4B40, estado en
  0x803DEFC0 y puntero en 0x803DEFD4. `0xE0000000` es la base
  de la caché bloqueada de GameCube: una dirección legítima
  en hardware, no un puntero nulo.
- run27 (reproducción de run26 con traza: mismos 1.849.789
  despachos, misma exception): el watchpoint demostró que las
  ÚNICAS escrituras a la estructura de caché en todo el run
  fueron el borrado BSS de arranque (0x80003434–0x80003454,
  LR 0x800033C0). `n_attractmode_releaseMovieBuffers`
  (0x80116548) NUNCA corrió en ese run, y tampoco
  `prepareMovie`. La caché nunca se inicializó (estado 0 y
  puntero 0, ambos por BSS).
- La cadena que llega al fallo es código en línea
  incondicional: `allocLotsOfTextures` (0x8006D7CC, despacho
  1.515.077, LR 0x80062F34, desde `initTextures` 0x80062E18)
  llama a `updateHeavyFogTexture` (0x8006A09C, despacho
  1.849.786, LR 0x8006E798, `bl` en 0x8006E794), y
  `initTextures` la llama incondicionalmente el `init` del
  juego (0x800211D0). En hardware real la caché TIENE que
  ser válida en ese punto.
- La re-inicialización real existe y es posterior (pantalla
  de título), no algo que faltara antes de `initTextures`:
  `n_attractmode_prepareMovie` (0x80116650) reserva 7
  búferes con `mmAlloc` (0x80023E30), guarda un búfer de
  16.384 B en [r13-23404] (0x8011678C) y, tras
  `AttractMovie_AssignBuffers` (0x80119198),
  `prepareAttractMode` (0x80118E70) y `THPPlayerPlay`
  (0x80118E10), pone estado = 2 (0x80116990). Sus únicos
  llamadores son `TitleMenu_run` (0x80116C74, con flag
  [r13-23415]) y `TitleMenu_initialise` (0x80117770, con byte
  [r13-23408] != 0 Y estado 0 o 4).
- Causa raíz, en la capa SDK/HLE, no en el juego: el `init`
  del juego llama a `LCEnable` (0x80242548) incondicionalmente
  (0x80020FC4), antes de `initTextures`. El `_LCEnable`
  huésped (0x8024247C) programa DBAT3 sobre `0xE0000000` y
  borra 512 × 32 B = 16 KiB con `dcbz`. Pero el HLE de
  `LCEnable` devolvía inmediatamente sin hacer nada, así que
  el `_LCEnable` huésped nunca corría y `mem_*` no tenía
  mapeo para `0xE0000000` → fuera de rango → exception 1 en
  el primer `stbx` de `updateHeavyFogTexture` (bucle: r9
  0..63, CTR 16 → 1.024 `stbx`; desplazamiento máximo
  ≈ 3.903, dentro de los 16 KiB que `_LCEnable` borra; su
  cola llama a `memcpyToCache` sobre una textura 64×64 de
  4.096 B creada en `allocLotsOfTextures`). `memcpyToCache`
  (0x80022AB0) y `copyToCache` (0x80022B60) confirman el
  modelo: con estado 0/4 van por la vía DMA de caché
  bloqueada (`LCStoreBlocks`/`LCLoadBlocks`), no por `memcpy`
  (0x80003494). El único hilo creado en run26 fue
  `errorThreadFunc` (0x801383C0), lo que refuta la hipótesis
  «el re-init vive en el hilo no ejecutado» para ese run.

Solución implementada (solo runtime/HLE; código del juego
intacto, ningún búfer falso):

- `cpu/cpu.h`: `GC_LC_BASE 0xE0000000`, `GC_LC_SIZE 16384` y
  `u8 locked_cache[GC_LC_SIZE]` añadido AL FINAL de
  `CPUState` (deliberado: insertarlo en medio desplazaría
  offsets como `downcount` o `ram` que los 176 chunks
  precompilados ya usan). El búfer es cero en arranque
  (`InitCpuForBoot` pone a cero la estructura).
- `cpu/cpu.c` `resolve_addr()`: mapea 0xE0000000–0xE0004000
  a `cpu->locked_cache + offset`.
- `hle.h`/`hle.cpp`: `LCLoadBlocks` (0x802425A8),
  `LCStoreBlocks` (0x802425CC), `LCQueueWait` (0x8024269C) y
  `LcDmaCopy()`. Semántica leída del código SDK huésped, no
  adivinada: Load copia RAM (r4) → LC (r3); Store copia LC
  (r4) → RAM (r3); r5 = bloques de 32 B, con 0 = 128 bloques
  (4.096 B, igual que el bucle de `LCStoreData` 0x802425F0,
  que avanza ambas direcciones 4.096 B por tramo de 128
  bloques); DMAU guarda la dirección de RAM y DMAL la de LC
  más control 0x12 (load) / 0x02 (store). Direcciones LC
  fuera de ventana registran `SFA_LOGE` y omiten la copia
  sin recortar en silencio. `LCQueueWait` devuelve r3+1 (el
  código huésped hace `addi r3, r3, 1` a la entrada) porque
  el DMA aquí es síncrono y la cola siempre está vacía.
  `LCEnable` HLE ahora también pone a cero el búfer LC
  (como el bucle `dcbz` de `_LCEnable`). `LCStoreData` NO se
  HLEó: es código huésped ordinario que itera sobre los
  `LCStoreBlocks` ya HLEados. Nota de diseño: DBAT3, como
  está decodificado, mapea un bloque de 4 MiB en
  `0xE0000000`, pero solo 16 KiB son líneas bloqueadas que
  `_LCEnable` borra; el búfer se dimensiona a esos 16 KiB
  reales, con registro ruidoso ante desbordamiento.
- Corrección WPAR necesaria para pasar la siguiente
  instrucción tras el arreglo LC: `PPCMfwpar` (0x80240CD4)
  lee el SPR 921. `HandleFallback` modela WPAR como HID0
  (1008) y L2CR (1017): nuevo miembro `wpar_` en `Hle`,
  inicial 0 = tubo de recogida vacío, así que
  `GXResetWriteGatherPipe` (0x80258C6C, que gira mientras
  el bit 0 de `mfwpar` sea 1 y luego hace `mtwpar`) sale en
  la primera iteración.

run28 (tras el arreglo LC): supera `updateHeavyFogTexture`
(despacho 1.849.786). `LCStoreBlocks` HLE se dispara en el
despacho 1.850.045 con exactamente los argumentos predichos
(r3 = 0x8165E400 textura RAM, r4 = 0xE0000000, r5 = 0 →
128 bloques), lo que confirma la dirección Store. Segundo
`LCEnable` en el despacho 1.856.864 (desde 0x80029980). Nueva
exception en el despacho 1.884.514, PC 0x80240CD8 (SPR 921
sin modelar) → corregida como arriba.

### 2. Segunda corrección de la misma clase: colas de mensajes

run29 (tras el arreglo WPAR): sin exception, `dispatch_cap`,
5.000.000 despachos, 26,190 s, PC final 0x802449F8.
Titulares frente a run26: DVDOpen ×121 (antes 98), async
×119, 22.649.460 B async (antes 20.083.124), FIFO 56.389 B
(antes 2.100), PADRead ×3, VIWaitForRetrace ×4, OSReport 22
líneas / 17 cambios, OSSleepThread ×997.009.
`TitleMenu_initialise` corrió en el despacho 2.049.170 (LR
0x80013F48, `Resource_Acquire`) y `prepareMovie` en el
2.049.221 (LR 0x80117774): el camino natural de re-init se
alcanzó. Ficheros nuevos frente a run26: `gamefront/ANIM.BIN`,
`MODELS.bin`, `TEX0.bin`, `TEX1.bin`, `gamefront.romlist.zlb`
y `starfox.thp` (48.931.320 B, fileInfo 0x803A76C0); algunas
búsquedas fallaron (`gamefront/animcurv.bin`, `animcurv.tab`,
`voxmap.bin`, `warlock/voxmap.bin`, «no encontrado»).
OSReport muestra `LOADED OBJECT SKYSun/SKYMoon/CommandMenu/
communicato/WORLDcomm/commCube/commCubeFro/commQuitObj/
commMemoryC/projball/LockIcon` y `finished init`. El run se
detuvo en `OSSendMessage` (0x802449A0) durmiendo sin fin:
su cola en 0x803A8C30 era todo ceros (capacidad [q+20] = 0,
usados [q+28] = 0) porque `OSInitMessageQueue` estaba HLEado
como no-op puro.

El código huésped de `OSInitMessageQueue` (0x80244940)
escribe [q+16] = msgArray, [q+20] = msgCount, [q+24] = 0
(firstIndex), [q+28] = 0 (usedCount), con dos colas de hilos
en +0 y +8 a cero (`OSInitThreadQueue` 0x80246724 huésped:
[q+0] = [q+4] = 0). El caso HLE devolvía 0 sin escribir
nada, así que el `OSSendMessage` huésped (no HLEado) veía
capacidad 0 y dormía para siempre. Corrección en `hle.cpp`:
`kOsInitMessageQueue` sale del grupo no-op y escribe esas
8 palabras con `mem_write32`; también se implementa
`kOsInitThreadQueue` independiente (2 escrituras a cero).
`OSInitContext` y los casos del planificador siguen siendo
no-ops (no hay contextos de hilo ni planificador en el
chassis monohilo; `OSSleepThread` siempre retorna al
instante).

run30 (tras el arreglo de colas): mismos titulares que
run29 (DVDOpen ×121, async ×119, FIFO 56.389 B,
OSSleepThread ×997.005, `dispatch_cap` 5M, 25,464 s, PC
final 0x80244AC0). La detención avanzó un paso, como se
esperaba, al lado receptor (ver punto 4). Evidencia de que
el arreglo funciona: `OSInitMessageQueue` ×8 (despacho
2.049.225 desde `AttractMovieAudio_Init` 0x8011988C;
también desde `CreateVideoDecodeThread` 0x8011A0FC,
`CreateAudioDecodeThread` 0x80117B48 y `CreateReadThread`
0x80119BF4); `OSSendMessage` ×16 (LRs 0x801199EC
`PushFreeReadBuffer`, 0x80119C98 `PushFreeTextureSet`,
0x80117880).

### 3. Callbacks VI pre/post retrace (implementados)

Evidencia de que el juego los espera: `VISetPreRetraceCallback`
(0x8024CB14) se llama desde 0x80049F48 y `VISetPostRetraceCallback`
(0x8024CB58) desde 0x80049F54, 0x80118D6C, 0x80119068 (dentro
de `prepareAttractMode`, después de la recepción que hoy se
detiene, así que ese registro no llega a ocurrir en run30) y
0x80138418. Los cuerpos de los setters (código DolRecomp):
Pre guarda r3 en [r13-21016], Post en [r13-21012], cada uno
devuelve el valor anterior, envueltos en 0x802440BC/0x802440E4
(deshabilitar/habilitar interrupciones). Nada los entregaba:
`VIWaitForRetrace` (0x8024D29C) y `OSSleepThread`
(0x8024740C) solo hacían `++retrace_count_` y retornaban.

Implementación: los dos setters están HLEados (devuelven el
anterior, y escriben TAMBIÉN los globales RAM, así que
cualquier lector directo de [r13-21016]/[r13-21012] ve lo
mismo que el HLE); la entrega se hace en cada retrace
simulado (tanto `VIWaitForRetrace` como `OSSleepThread`,
porque ambos están definidos en este código como «un
retrace ocurrió» — el bucle del juego espera por sueño, y
`VIWaitForRetrace` solo ocurrió ×4 en run30, todas en init
tipo tvInit). La cadena es pre y luego post, encadenadas
por un PC sintético `kViCallbackTrampoline` = 0x80003000
(nunca código real: el DOL empieza en 0x80003100;
`dolrecomp_call` consulta `host_call` antes que los chunks,
así que el HLE lo intercepta siempre; sin HLE instalado, el
chassis se detendría con `unknown_pc`, fallo ruidoso, no
corrupción). El trampolín era necesario porque poner post
como lr de pre entraría en bucle (post se devolvería a sí
mismo). Los callbacks reciben el contador de retrace en r3
(convención `VIRetraceCallback`). Guarda de reentrancia de
un solo hueco: un retrace anidado dentro de un callback
omite la entrega en vez de corromper la cadena (limitación
documentada). `VIInit` pone a cero ambos globales, como el
estado VI en hardware. Contadores de verificación:
cadenas, pre entregados, post entregados.

run31 (baseline 5M con entrega VI): setters ×1 cada uno
(pre = `videoSwapFrameBuffers` 0x80049AAC, registrado desde
`videoInit` 0x80049F48; post = `gpuErrorHandler` 0x80049768,
desde 0x80049F54). Cadenas 155.286, pre 155.286, post
155.286: equilibradas, ninguna cadena atascada, ninguna
exception. Titulares idénticos a run30 (DVDOpen ×121, async
×119, FIFO 56.389 B, OSReport 22, `dispatch_cap` 5M,
26,293 s), salvo dos efectos explicados, no regresiones:
(a) `OSSleepThread` ×155.282 (antes ×997.005) porque cada
sueño ahora despacha 2 callbacks y el presupuesto de 5M se
consume distinto; la detención final sigue siendo la misma
(OSReceiveMessage, punto 4); (b) el byte `flag_pad`
(0x803DE65D) termina en 1 (antes 0): `gpuErrorHandler`, el
callback post, hace `li r0, 1; stb r0, -25827(r13)`
(0x8004980C–0x80049810), así que ese byte — que `padUpdate`
usa como flag de muestra nueva (lo lee en 0x80015134 y lo
pone a cero en su epílogo 0x800154B4) — queda a 1 tras cada
retrace en cuanto los callbacks corren, como en hardware;
no cambia el comportamiento PAD (los globales PAD de
run31 son idénticos a run30). Decisión mantenida: entrega
en ambos puntos; si un run futuro regresa (nueva exception
o detención anterior), el repliegue documentado es entrega
solo en `VIWaitForRetrace`.

### 4. Nueva frontera (sin maquillar): pipeline de hilos THP

run30 se detiene en `OSReceiveMessage` (0x80244A68), una
sola entrada en el despacho 2.049.566, LR 0x8011902C dentro
de `prepareAttractMode` (0x80118E70). En 0x8011901C hace
`OSReceiveMessage(cola = r31+1324, salida = sp+8, flags = 1
bloqueante)` y gira en `OSSleepThread` mientras
`usedCount ([q+28]) == 0`. Espera un mensaje de los hilos
de decodificación/lectura THP creados justo antes
(`CreateVideoDecodeThread` 0x8011A034,
`CreateAudioDecodeThread`/`AudioDecodeThreadStart`
0x80117A80, camino `CreateReadThread`), que nunca corren
porque `OSCreateThread` solo registra hilos (`runnable =
false`, sin ejecución) en el chassis monohilo. Es el
bloqueador «hilos reales» ya listado, ahora localizado con
precisión. NO se ha improvisado una solución: el siguiente
paso concreto es ejecutar los hilos registrados
(planificador cooperativo o entrega de mensajes con la
semántica exacta de la cola), sin inventar el contenido de
los mensajes. Esto es lo que hoy impide llegar a una
pantalla de título que lea input.

### 5. Flanco JustPressed (medido a nivel `padUpdate`)

Fórmula leída en el código huésped de `padUpdate`
(0x80014F6C), no supuesta: en 0x800151E4–0x80015210,
`Just = Held & ~Prev` (xor + and), `Released = Prev &
~Held` (0x800151F8–0x80015208), y Prev se actualiza a Held
(0x8001520C). La puerta de muestra nueva: 0x80015134 lee
el flag 0x803DE65D (puesto a 1 por el `PADRead` HLE y por
el callback post VI, ver punto 3; puesto a 0 por el epílogo
de `padUpdate` 0x800154B4); con flag 0, `padUpdate` copia
la muestra anterior en vez de usar la fresca.

Medición con pulsación posterior real (no Start mantenido):
el HLE ganó `SetPadPressFromRead(n)` — solo con inyección
de test activa; la ruta de la APK (`SetPadState`, con
`pad_inject_` desactivado) no puede verse afectada — y el
test ganó el modo `press` (variable
`SFA_PAD_PRESS_FROM_READ`, defecto 3): las lecturas
1..n-1 salen con botones 0 y desde la n con los botones
inyectados.

- run32 (`press` desde la lectura 3, 5M): PADRead #1
  botones 0x0000, #2 0x0000, #3 0x1000 (Start, relectura
  0x10000000). Globales finales: Held0 = Just0 = Prev0 =
  0x1000. Flanco real: `padUpdate` #3 calculó Held =
  0x1000 con Prev = 0 (de #1/#2 sin botones) → Just =
  0x1000. Sin exception, titulares iguales a run31.
- run33 (`start`, regresión sobre el build nuevo, 5M):
  Held0 = Prev0 = 0x1000, Just0 = 0, idéntico a run26-start
  (Start mantenido desde el arranque: sin flanco, Just 0
  correcto). PADRead #1/#2/#3 con 0x1000. Sin regresión.
- Advertencia honesta: esto mide el flanco en `padUpdate`,
  las únicas llamadas `padUpdate` del run; la prueba a
  nivel de pantalla de título sigue bloqueada por el punto
  4 (el juego no llega a `TitleMenu_run`). El mecanismo
  verificado es exactamente el que usará la pantalla de
  título.

### 6. Verificación host (runs 27–34, sin regresión enmascarada)

- run27: reproducción de run26 con traza (watchpoint +
  PCTRACE): mismos 1.849.789 despachos, misma exception en
  0x8006A0E0; evidencia del punto 1.
- run28: supera `updateHeavyFogTexture`; nueva exception
  WPAR (0x80240CD8) diagnosticada por PC y corregida.
- run29: sin exception, `dispatch_cap` 5M; detención en
  `OSSendMessage` por colas sin inicializar (punto 2).
- run30: `dispatch_cap` 5M; detención en `OSReceiveMessage`
  (punto 4). Titulares: DVDOpen ×121, async ×119,
  22.649.460 B async, FIFO 56.389 B, GXLoadTexObj ×2,
  PADRead ×3, VIWaitForRetrace ×4, OSReport 22/17,
  OSSleepThread ×997.005.
- run31: como run30 + callbacks VI (punto 3); sin exception
  ni cambio de titulares salvo los contadores VI y los dos
  efectos explicados.
- run32: flanco JustPressed (punto 5); sin exception.
- run33: regresión `start` sin cambios (punto 5).
- run34 (`unit`): TODO OK, 0 fallos (layout DVDFileInfo,
  callback async, PADStatus + flag de muestra nueva, WAV
  resampleo/entrega).

### 7. Build NDK (verificación Fase 8)

Build `ndk-build` (directorio nuevo bajo `work-port/`, fuera
del repo; JOBS=2, 179 C + runtime C++ desde cero): PASS, **0
errores**, exit 0 (las 5 menciones de «error» en el log son
nombres de símbolos del sistema, `logic_error`/`length_error`/
`strerror`, no errores de compilación).
`libstarfox.so` **27.329.920 B**, ELF64 `DYN` AArch64, SHA-256
`6105885b664b41ec8e19dc385f5e943a36a475074eb04f6b67177e360b19bf7e`
(Fase 6–7: 27.326.912 B,
`9d00fe0a94487f61655d34bfe6ea2f63f557b6516eccf9ffc6a1e904074a7410`),
comprobación del script «OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver», 153 undefined
totales (151 en Fase 6–7: delta +2, solo libs del sistema).
`android_main` en `T`, `AAudioStreamBuilder_*` en `U`
(sistema, esperado). Antes del build completo, compilación
dirigida de los ficheros tocados (cpu.c, chassis.cpp,
hle.cpp) con el toolchain NDK y los mismos flags: 0 errores.
APK Fase 0 intacta: SHA-256
`b07a6af555246d442808208563efa8b0d423c7bd916aa9fc8938b1484bbf07d1`
(57.916 B, sin reconstruir en este tramo; sigue siendo solo
arranque, NO jugable).

### 8. Qué queda (tras Fase 8, en orden)

1. Hilos reales / pipeline THP (punto 4): el bloqueador
   actual nº 1. Sin esto no hay pantalla de título.
2. Renderer GX en APK (GLES3) con el camino ya verificado
   en host; THP; CARD.
3. Mapeo ID de sonido del juego → WAV; secuencias MusyX;
   DSP real.
4. Botones táctiles en pantalla (layout por definir),
   rumble.
5. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).

## Fase 9 (2026-10-26, este tramo): hilos THP reales, prepare desbloqueado, bucle principal en marcha

El bloqueador nº 1 de la Fase 8 (el juego detenido en
`OSReceiveMessage` esperando un mensaje de los hilos THP)
queda **resuelto sin inventar contenido**: el mensaje lo
produce la decodificación huésped real del primer frame de
`starfox.thp`, ejecutada por los hilos registrados.

### 1. Planificador cooperativo en el HLE (semántica implementada)

Un solo flujo de despachos (el chassis) cambia el
`CPUState` entre hilos: guarda los registros del hilo
actual en su `ThreadEntry` (o en `main_ctx_` para el
principal, que no tiene `ThreadEntry` porque su `OSThread`
lo crea el SO antes de `main`) y carga los del siguiente,
con el PC en su punto de reanudación (LR del
sleep/suspend, o la entrada en el primer arranque).
Compartido y NO guardado/restaurado por hilo: RAM,
`host_call`, `timebase`, búfer LC y sus etiquetas (memoria
compartida como la RAM), `hid2`, `downcount` (el chassis
lo repone antes de cada despacho); la reserva
`lwarx`/`stwcx` se limpia al cambiar (semántica PPC por
procesador). Sin rodajas de tiempo: un hilo que nunca
duerme ni se suspende nunca cede (si eso ocurre alguna
vez, se verá como un run con PC fijo en el tope de
despachos y se diagnosticará entonces).

Disparadores de cambio:

- Sleep en cola del principal (LR 0x80244AC0 Receive o
  0x802449F8 Send): registra la cola bloqueada y su tipo,
  y cambia. El principal es elegido PRIMERO si
  `MainReady()` (cola Receive con `used > 0`, o cola Send
  con `used < capacidad`); si no, round-robin sobre
  trabajadores reanudados, no suspendidos y no terminados,
  empezando tras el hilo actual.
- Sleep de cualquier trabajador: intento de cambio siempre
  (los trabajadores no tienen sleeps de frame).
- Sleep de frame del principal (`waitNextFrame`, LR en
  código de juego): NO cambia — mantiene la entrega VI +
  retorno inmediato anterior. La planificación de
  trabajadores en el bucle de frame es un paso siguiente
  explícito, no hecho aquí.
- `OSSuspendThread` sobre el hilo actual: guarda con valor
  de retorno = contador viejo de suspensión y cambia al
  principal si está listo, si no round-robin; sin relevo,
  retorno inmediato (giro, como antes) y un contador de
  fallback del planificador.
- Retorno de una función de hilo: el LR inicial de todo
  hilo creado es el trampolín sintético de salida
  0x80003004; al llegar, el hilo se marca terminado y el
  planificador cambia sin guardar su contexto; sin relevo,
  cambio forzado al principal si está guardado, si no
  excepción (fallo ruidoso, no silencioso).
- `OSResumeThread`: solo marca listo (sin preempción
  inmediata). Un hilo reanudado corre cuando el hilo
  actual cede la próxima vez. Esto mantiene atómica la
  secuencia prepare del principal (Create → Start vídeo →
  Start audio → Start read → Receive) antes de que corra
  ningún trabajador.

Callbacks VI: el contador de retrace solo avanza en sleeps
del principal (en los runs 30–33 todos los sleeps eran del
principal, así que los conteos siguen siendo comparables).
Al volver al principal, se intenta `DeliverViCallbacks()`
con retorno = PC de reanudación del principal (mecanismo
del trampolín de la Fase 8), así que las cadenas VI siguen
ocurriendo en los despertares del principal, pero caen
bruscamente durante la fase prepare bloqueada porque el
principal ya no gira: cambio documentado, no regresión,
siempre que el juego avance (y avanza: ver punto 4).

Entrega al principal registrada: al cambiar de vuelta al
principal mientras esperaba en una cola Receive que ya
tiene mensaje, la entrega se registra ANTES de que el
principal la consuma (dirección de cola, valor del mensaje,
dirección huésped y entrada del hilo remitente; tope de
10.000 entradas, las 20 primeras en log).

Campos huésped `OSThread` escritos por el nuevo
`OSCreateThread` HLE (espejo best-effort de la semántica
SDK leída en el código huésped: estado `[712] = 1`,
suspensión `[716] = 1`, prioridad `[720] = [724]`,
`[728] = -1`, `[744..760] = 0`, pila `[772] = tope`,
fondo `[776] = tope - tamaño` con canario `0xDEADBABE`,
contexto vía `OSInitContext`: PC `[408] = entrada`, SP
`[4] = (pila alineada a 8) - 8`, MSR `[412] = 0x9032`,
gpr3 `[12] = val`, gpr2 `[8]` y gpr13 `[52]` del creador,
resto a cero; lista global de hilos en `0x800000DC`/
`0x800000E0`). Desviación documentada: los campos LR/CTR
del contexto `[132]`/`[136]` se escriben a 0 (el huésped
los deja obsoletos); el contexto host usa el trampolín de
salida, así que ningún cambio host se ve afectado y ningún
código huésped de cambio de contexto corre en este modelo.
Diagnóstico de canario: al guardar un contexto de
trabajador se comprueba la palabra del fondo de pila
contra `0xDEADBABE` y cualquier cambio se registra una
vez por hilo (en los runs 39/41 no saltó).

### 2. Cuatro correcciones encadenadas, cada una con evidencia

El desbloqueo necesitó cuatro correcciones; ninguna es un
parche falso y cada una se diagnosticó por su síntoma:

1. **Cola bloqueada: registro vivo, no marco** (run36).
   El principal nunca despertaba pese a que la cola
   prepare tenía mensaje: el código guardaba la cola
   leyendo `[sp+36]` en el marco de Receive, pero el
   prólogo de Receive guarda el r31 del LLAMADOR en +36
   ANTES de poner r31 = cola (y Send guarda el r28 del
   llamador en +24 antes de poner r28 = cola). Leer el
   marco daba la base P (0x803A7120) en vez de la cola
   prepare (0x803A764C). Corrección: Receive → cola =
   gpr[31] vivo; Send → cola = gpr[28] vivo.
2. **LCEnable HLE: falta el bit LCE de HID2** (run36→37).
   Con la cola ya correcta, el hilo de vídeo se suspendía
   tras decodificar con resultado 28 en `Q+164`. El 28 de
   `THPVideoDecode` (0x80264E1C) es su rama HID2: salta
   cuando el bit LCE (0x10000000) está LIMPIO (la
   decodificación usa la caché bloqueada). El
   `_LCEnable` huésped (0x802424A4) hace
   `mfhid2; oris 0x100F; mthid2`; el HLE de la Fase 8 solo
   ponía el búfer a cero. Corrección: el HLE LCEnable
   ahora espeja `hid2 |= 0x100F0000` además de poner el
   búfer a cero.
3. **Hilos: falta el bit FP del MSR** (run37→38). Con LCE,
   el hilo de vídeo abortaba con excepción
   `FP_UNAVAILABLE` (0x20) en el vector 0x800. El MSR
   inicial de `OSInitContext` es 0x9032, sin FP (bit
   0x2000). En hardware real el primer FP del hilo salta
   al manejador del SO (vector 0x800, fuera del DOL: el
   chassis no puede ejecutarlo) y su efecto neto es dejar
   FP activo con el contexto FP propio del hilo (a cero,
   como `OSInitContext`). Corrección: el MSR inicial de
   los hilos es 0xB032 (0x9032 + FP); el guardado/
   restaurado FP por hilo ya existía en `ThreadContext`
   (fpr/ps1), así que la semántica es la misma.
4. **`LCStoreData` HLE: bypass intra-chunk a `mtdmau`**
   (run38→39). Con FP, el hilo de vídeo abortaba con
   excepción de programa en 0x802425D8 (`mtdmau`, dentro
   de `LCStoreBlocks` 0x802425CC). `LCStoreBlocks` SÍ está
   en la tabla HLE, pero `LCStoreData` (0x802425F0, mismo
   chunk) lo llama con `goto` intra-chunk sin pasar por
   `host_call`, y `mtdmau` no está implementado en cpu.c.
   Corrección: `LCStoreData` entra en la tabla HLE con
   copia síncrona real vía `LcDmaCopy` (RAM → LC, en
   bloques de 32 B, como el bucle huésped que llama a
   `LCStoreBlocks` por trozos de 4096 B; r5 = 0 ≡ 128
   bloques) y retorno `ceil(bloques/128)`, espejo exacto
   del cálculo huésped (`bloques = (bytes+31)>>5`,
   retorno `(bloques+127)>>7`; bytes = 0 no copia y
   devuelve 0). El DMA real es asíncrono y `LCQueueWait`
   HLE ya devuelve de inmediato, así que el modelo es
   consistente. La tabla HLE pasa de 58 a 59 entradas
   (dentro de `log_count_[64]`).

### 3. Mensajes entregados: contenido real, no inventado

El mensaje esperado por `prepareAttractMode` es
`PrepareReady(1)`, enviado por `AttractMovieVideo_Decode`
(0x80119CA8) al final del bucle de componentes si el flag
`[r13-23284]` sigue puesto (el envío 0 solo ocurre en
error de lectura o de decodificación). En run39/run41 el
principal despierta **3 veces** con el mensaje exacto:

- Cola 0x803A764C (prepare, capacidad 1), mensaje
  `0x00000001`, remitente hilo huésped 0x803A9CA8, entrada
  0x80119F2C (`AttractMovieVideo_Decoder`, streaming,
  prioridad 15). Las 3 entregas son idénticas en run39 y
  run41 (determinista).

El 1 no se inyecta: lo produce la decodificación huésped
real del frame 0 de `starfox.thp` (48.931.320 B): el hilo
de lectura lee el frame real por `DVDReadPrio` (el búfer
0x807A7280 coincide byte a byte con el frame del disco,
JPEG SOI en el offset 16), el hilo de audio procesa los
componentes de audio, y el hilo de vídeo decodifica el
componente JPEG con `THPVideoDecode` + `__THPDecompressYUV`
(20 llamadas `LCStoreData` HLE en el run: planos Y
8192 B a LC 0xE0000000 y U/V 2048 B a 0xE0002800/
0xE0003200, desde las texturas 0x80818C00/0x80F747E0/
0x80F507E0 y siguientes). Tras cada éxito, el vídeo
envía una textura lista a la cola `video_ready_tex` y
`PrepareReady(1)` a la cola prepare.

### 4. Punto alcanzado tras el desbloqueo (run41, código final)

- `dispatch_cap` 5M, **0 exceptions**, PC final
  0x80051580 dentro de `addSphereMapTexStage`
  (0x8005152C, 0x1E0): el principal está en mitad de un
  dibujo (montaje de una etapa de textura sphere-map),
  no atascado.
- Planificador: 24 cambios, 3 a principal, 0 fallbacks,
  hilo actual = principal. Hilos: vídeo 3 entradas / 3
  cesiones / 0 suspensiones; audio 2 / 2; lectura 2 / 2;
  hilo de error (0x803ACA78) nunca reanudado, como antes.
- Colas al final: prepare vacía (consumida); `read_free`
  3/10; `read_filled` 6/10 (primer índice 4);
  `read_q3` vacía (primer índice 3, consumida por vídeo);
  `video_free_tex` 3/3 libres de nuevo; `video_ready_tex`
  2/3 (texturas 0x803A7814, 0x803A7824 esperando
  display); `audio_free` 3/3; `audio_ready` 3/3 llena.
- Estado prepare: P+1592 = 1, P+1596 = 2, P+1597 = 2
  (1 = preparado tras el primer éxito; 2 = reproducción
  en marcha), P+1599 = 1, Q+108 = 2 componentes, Q+208 =
  2, Q+176 = 0x58, Q+180 = 0x1680.
- Bucle principal en marcha: retrace 38, cadenas VI 38
  (pre/post equilibradas), callback pre sigue siendo
  `videoSwapFrameBuffers` (0x80049AAC) y el callback post
  ya NO es `gpuErrorHandler` sino `PlayControl`
  (0x8011897C, 0x3B0): la función de control de juego
  que cada retrace consume texturas decodificadas vía
  `PopDecodedTextureSet` (0x80119C34) y avanza la
  reproducción. Es decir: **la película de atracción
  (attract movie) está reproduciéndose** — prepare con
  éxito, frames decodificándose y texturas listas para
  display. NO se afirma pantalla de título: el título
  como tal (menú con input) sigue pendiente de probar a
  nivel de pantalla (ver punto 7).
- Dibujo real: FIFO 15.021.078 B (frente a 56.389 B en
  run35), `GXLoadTexObj` ×10.870 (frente a ×2), OSReport
  95 líneas / 45 cambios (frente a 22/17), PADRead ×27,
  DVDOpen ×132, async ×131, `DVDReadPrio` ×30,
  `LCLoadBlocks` ×270, `LCStoreBlocks` ×105,
  `LCQueueWait` ×384.

### 5. Verificación host (runs 36–41, sin regresión enmascarada)

- run36 (planificador, cola mal leída): hilos corriendo
  (lectura/audio 731.058 cambios cada uno) pero principal
  sin despertar nunca; cola prepare con mensaje 0
  (fracaso por error 28 de decodificación) sin consumir.
  Diagnóstico: punto 2.1.
- run37 (cola corregida, sin LCE): excepción 0x20 en el
  hilo de vídeo (FP). Diagnóstico: punto 2.3.
- run38 (LCE + FP, sin LCStoreData): excepción de
  programa en `mtdmau` (0x802425D8). Diagnóstico: 2.4.
- run39 (todo corregido): desbloqueo completo, cifras
  del punto 4.
- run41 (código final, sin trazas de depuración):
  **idéntico a run39** en todos los contadores y en FIFO
  (15.021.078 B exactos, determinista), mismo PC final,
  mismas 3 entregas.
- run40unit (`test_phase6`, modo unit, con el HLE nuevo):
  TODO OK, 0 fallos.
- run40press (`test_phase6`, modo press, Start desde
  PADRead nº 3): idéntico a run39/run41 en todos los
  contadores (DVDOpen ×132, GXLoadTexObj ×10.870, FIFO
  15.021.078 B exactos, 3 despertares con mensaje 1).
  Held0 = Prev0 = 0x1000, Just0 = 0 al final: el flanco
  quedó consumido por la lógica del juego tras avanzar
  (en run32 el juego estaba atascado en prepare y el
  flanco seguía sin consumir: Just0 = 0x1000). No es una
  regresión de PAD — el código PAD no se tocó — sino la
  consecuencia del propio desbloqueo. La prueba de input
  a nivel de pantalla de título sigue pendiente (punto 7).
- Comparación run35 → run41 (cambios documentados, resto
  comparable): OSSleepThread ×996.986 → ×52 y cadenas VI
  155.286 → 38 (el principal ya no gira en prepare: es el
  cambio de diseño del punto 1, no una regresión);
  DVDOpen ×121 → ×132, async ×119 → ×131, `DVDReadPrio`
  ×10 → ×30 (el pipeline THP fluye y el juego carga más
  tras el desbloqueo); FIFO, GXLoadTexObj y OSReport
  suben porque el juego dibuja y avanza (punto 4).
  Held/Just/Prev en modo baseline: 0/0/0 en ambos (sin
  pulsación en ese modo).

### 6. Build NDK (verificación Fase 9)

Build `ndk-build` (directorio nuevo bajo `work-port/`,
fuera del repo; JOBS=2, 179 C + runtime C++ desde cero):
PASS, **0 errores**, exit 0.
`libstarfox.so` **27.340.304 B**, ELF64 `DYN` AArch64,
SHA-256
`c2ba48298589299a53b6e735811ef063e8b4af1a2ff999d1fa7c7c1a1915efa2`
(Fase 8: 27.329.920 B,
`6105885b664b41ec8e19dc385f5e943a36a475074eb04f6b67177e360b19bf7e`;
delta +10.384 B por el planificador y el `LCStoreData`
HLE), comprobación del script «OK: ningún símbolo
mem_/ppc_/func_/dolrecomp_ sin resolver», 153 undefined
totales (**igual que en Fase 8: delta 0**, solo libs del
sistema). `android_main` en `T`.
APK Fase 0 intacta: SHA-256
`b07a6af555246d442808208563efa8b0d423c7bd916aa9fc8938b1484bbf07d1`
(57.916 B, sin reconstruir en este tramo; sigue siendo
solo arranque, NO jugable).

### 7. Qué queda (tras Fase 9, en orden)

1. Pantalla de título a nivel de juego: runs más largos y
   input (Start) en el bucle `PlayControl`/título para
   confirmar el paso de la película de atracción al menú
   y la lectura de JustPressed allí; la prueba de la Fase
   8 medía el flanco solo a nivel `padUpdate`.
2. Renderer GX en APK (GLES3) con el camino ya verificado
   en host; display de las texturas THP listas; THP de
   audio (los búferes `audio_ready` ya se llenan).
3. CARD (guardado) y resto de HLE que el bucle principal
   vaya pidiendo al avanzar más allá del título.
4. Mapeo ID de sonido del juego → WAV; secuencias MusyX;
   DSP real.
5. Botones táctiles en pantalla (layout por definir),
   rumble.
6. Paquete de datos Pack B, APK jugable y test en Tab S8.
   La APK Fase 0 sigue siendo solo arranque (ver abajo).
   Limitación conocida del planificador (punto 1): sin
   rodajas de tiempo y sin planificación de trabajadores
   en sleeps de frame del principal; si un hilo futuro no
   cede nunca, se diagnosticará por PC fijo en el tope.
