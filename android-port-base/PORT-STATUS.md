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

**Fase 10 (2026-10-26, este tramo):** Start programado
DESPUÉS de la película en marcha SÍ saca al juego del
bucle attract/title (`TitleMenu_run` deja de despacharse;
dosis-respuesta monótona con press12/press20 frente al
baseline run42, idéntico a run41), a un bucle sano
post-attract con 2 texturas estables y sin ficheros DVD
nuevos — pero la pantalla nueva NO queda identificada
como menú principal (ver «Fase 10», punto 1, matiz). El
renderer GX ya está en la APK (GLES3, QUADS + texturas
decodificadas, validado en host 602/602 sobre run19),
pero el parser host se detiene en el FIFO de la película
en el offset 2497 (opcode 0x03): frames de película
todavía NO renderizables por este camino. Nueva APK de
prueba `app-debug-gx-test.apk` (clear + damero, NO
jugable, sin datos; ver «Fase 10», punto 4). La APK Fase 0
sigue intacta.

**Fase 12 (2026-10-26, este tramo):** el bloqueador
visible de la Fase 11 (aviso «There is no Memory Card
in Slot A») queda RESUELTO en host por dos vías: tarjeta
virtual Slot A con formato GameCube real (59 bloques,
checksums SDK verificados, serie estable, persiste en
`<base>/memcard-a.raw` junto a los datos) — primer
arranque crea la partida (Create 24576 B + Write ×2 +
SetStatus), segundo arranque la abre y la lee (Open 0 +
Read ×2) — y, sin tarjeta, el menú del aviso recorrido
con stick Y + A hasta «Play (but cannot save your
progress)». En ambas vías el juego llega al bucle de
título (`TitleMenu_run`/`TitleMenu_render` por frame,
película attract parada). APK de prueba GX12 en la rama
(`app-debug-gx12-test.apk`, 12.538.534 B, SHA-256
`7587eb34…`, con la tarjeta virtual cableada). Sigue
sin ser jugable y sin probar en dispositivo: quedan
picker SAF, botones táctiles, sonido y la prueba real
con datos (ver «Fase 12»).

**Fase 13 (2026-10-26, este tramo):** picker SAF +
botones táctiles, los dos frentes que faltaban para
que la APK se pueda usar sin adb y sin mando. En
primer arranque sin `sfa-data`, la app abre el picker
de carpetas (Drive → Descargas → carpeta con
`sys/main.dol` + `files/`), copia Pack B a la carpeta
privada (misma base que el DOL y que `memcard-a.raw`)
con progreso en `boot.log`, verifica `main.dol`
(tamaño + SHA-1) y el conteo de `files/`, y carga el
juego al terminar sin reiniciar (marcador
`.saf-copy-done`; si falla, `.saf-copy-error` y la app
sigue en clear + quad, nunca se rompe). Layout
táctil DEFINIDO y documentado (fracciones, no
píxeles): stick virtual izquierdo — el que mueve el
aviso y los menús, no el D-pad —, rombo A/B/X/Y, Z,
L/R, Start, D-pad y C-stick reservado sin mapeo.
Verificado en host: la secuencia táctil del aviso
produce exactamente el guion PAD de run49b (stick Y
−80, soltar, A) y el run50 con ese guion reproduce
run49b en todas las métricas (estado 13, byte 0, FIFO
idéntico). APK de prueba GX13 en la rama. Sigue sin
ser jugable, sin sonido de juego y sin probar en
Tab S8 real: eso es lo que queda (ver «Fase 13»).

**Fase 14 (2026-10-26, este tramo):** traza de audio
del juego + mapeo ID → WAV + bridge conectado al
backend AAudio. En la ventana attract / Start /
aviso CARD / bucle de título, el juego solo pide
UN sonido por stream: `AudioStream_Play(1367)` ×2
(desde `ObjSeq_start`), y 1367 NO resuelve: no
existe en `Streams.bin` y, además, en host el
directorio de streams queda vacío (ver «Fase 14»:
el callback síncrono del HLE devuelve 0 y
`loadFileByPathAsync` toma el camino de fallo).
No hay `sndFXStartEx` ni `sndSeqPlayEx` en esa
ventana; sí hay init de audio completa,
`sndPushGroup` ×56 (grupos 0–55), `audioUpdate`
por frame y volúmenes de título. La tabla
generada resuelve 820/830 IDs de stream a WAV
real (10 sin WAV) y los 1.205 triggers SFX a sus
muestras (todas en inventario); el bridge
reproduce por el hook del chassis y entrega en
host 1.892.352 frames del stream 1301 y 104.997
de las 4 muestras del trigger 1, 0 descartados.
APK de prueba GX14 en la rama (bridge cableado
pero inerte sin payload de audio en Pack B).
MusyX/DSP sigue pendiente, ahora con la causa
exacta documentada (ver «Fase 14»).

**Fase 15 (2026-10-26, este tramo): trampolín HLE de
callbacks DVD + primer stream válido por el camino
del juego.** El trampolín propuesto en Fase 14 está
implementado (`kDvdCallbackTrampoline` 0x80003008):
el blr de un callback DVD ya no entrega el retorno
del callback como si fuera el de `DVDReadAsyncPrio`,
sino que restaura r3 = bytes leídos y salta al
retorno original. Consecuencia directa: el
directorio de streams queda cargado
(`dir_ptr` 0x810182E0, `count` 905, antes 0/0) y
desaparece el error `mm` de doble-free que dejaba
la carga fallida. El juego en la ventana sigue
pidiendo SOLO 1367 (×2), que sigue sin resolver
por la única causa restante: 1367 NO existe en
`Streams.bin` (escaneo de la tabla en RAM: NO).
Con el directorio cargado, el código huésped de
`AudioStream_Play` SÍ entrega un stream válido:
`Play(1301)` re-despachado desde el juego devuelve
1, abre `streams/AN/an1301.adp` y el bridge entrega
1.892.352 frames a 48 kHz con 0 descartados. Lo
que NO avanza todavía: el estado del juego
(`currentId`/`playing` en 0, `preparing` 340 =
índice 339+1) porque el arranque real espera la
completitud async DVDLow (`PrepareCallback`), que
el host aún no entrega, y 10 `audioUpdate` no lo
mueven. APK de prueba GX15 en la rama. Ver
«Fase 15».

**Fase 16 (2026-10-26, este tramo): completitud
async DVDLow CERRADA en test host + corrección
SFX (variantes, no 4 sonidos) + hook de audio
ampliado a r6/r7.** El parche HLE de
`DVDPrepareStreamAsync` (0x80249A84) entrega
`PrepareCallback` por el trampolín existente y
`StartPrepared` deja el estado exacto del
arranque: `currentId` = 340 (= índice 339+1 de
1301, NO 1301), `playing` = 1, `preparing` /
`prepared` / diferido / `IsPreparing` en 0, sin
exception, con guarda anti-doble-entrega
(segunda entrega no re-despacha y no borra el
estado). Test host `test_fase16` TODO OK (ver
«Fase 16»). Dos trampas del test aislado,
documentadas porque son del harness, no del
runtime: sin `AIInit` previo, las constantes
SRC quedan a 0 y `__AI_SRC_INIT` cicla sin fin;
sin bit FP en MSR, el `lfs` de `StartPrepared`
da exception FP-unavailable (0x20, vector
0x800) — en el arranque real AIInit corre en el
boot y el juego habilita FP en su `__start`.
Además: `OnSfxTrigger` ya no encola 4 muestras
en serie; reproduce solo la primera variante no
nula (los 4 campos de `Sfx.bin` son variantes
alternativas por pesos, no sonidos simultáneos;
trigger 13 → muestra 175 única, verificada) y
el hook pasa r6/r7 al bridge (hoy registrados,
pendiente resolver la tabla FX antes de cablear
`sndFXStartEx` por ID FX). Mezcla de voces y
bucles por metadato quedan para la Fase 17;
payload de audio, TEV multi-etapa, rumble y APK
jugable siguen pendientes. Ver «Fase 16».

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
- **Fase 14 — Traza de audio + mapeo ID → WAV + bridge
  (NUEVO, verificado en host):** `PCTRACE` ampliada con
  entradas de audio y r3–r7; tabla generada
  (`audio/audio_id_map.h`, desde `Streams.bin`/`Sfx.bin` +
  inventario: 820/830 streams, 1.205 triggers SFX,
  1.472 muestras MusyX); bridge `audio/audio_bridge.*`
  conectado por hook opcional del chassis al backend
  AAudio (sin cambiar el loop: el código huésped corre
  íntegro) y al runtime (`Tick()` por frame, root
  `<base>/sfa-data/audio`, inerte sin payload). Host
  run52: hook con 3 entradas (StopCurrent ×1,
  Play(1367) ×2, no resuelto), entrega 1.892.352 +
  104.997 frames con 0 descartados, métricas de juego
  idénticas a run51. En dispositivo, sonido todavía
  sin probar; el único stream pedido en la ventana
  no resuelve (ver «Fase 14»).
- **Fase 15 — Trampolín DVD + stream válido por el
  camino del juego (NUEVO, verificado en host):**
  `kDvdCallbackTrampoline` 0x80003008 en
  `gamecube_runtime/hle.{h,cpp}`: todo callback
  `DVDReadAsyncPrio` vuelve por el trampolín, que
  restaura r3 = bytes leídos (0 si lectura vacía o
  fallida) y salta al retorno original con
  lr = retorno original; en run54, 135/135
  callbacks con 135 trampolines y pila 0 al final.
  Directorio de streams cargado (0x810182E0, 905)
  y error `mm` de doble-free desaparecido. El
  juego pide solo 1367 (sin resolver: ausente de
  `Streams.bin`), pero su propio `AudioStream_Play`
  con 1301 devuelve 1 y el bridge entrega
  1.892.352 frames con 0 descartados (ver
  «Fase 15»). En dispositivo, sonido todavía sin
  probar.
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
   audio DSP real, planificador de hilos real, ~~CARD~~
   **HECHO en Fase 12** (tarjeta virtual Slot A, ver
   «Fase 12»). El HLE actual cubre arranque + eventos
   DSP/ARQ + callback DVD + PAD + sueño instantáneo +
   callbacks VI + DMA LC + colas de mensajes + CARD.
4. **GX en APK (Fase 11, ya no parcial en parser/alimentacion):**
   el renderer GLES3 ya dibuja frames del bucle real por
   triangulos (QUADS/TRIANGLES/STRIP/FAN + texturas) y el
   parser host cubre el FIFO de pelicula COMPLETO hasta EOF
   sin desconocidos (5148 draws en run42; ver «Fase 11»).
   La APK de prueba GX11 alimenta `SetGxDraws()` por frame
   desde la captura FIFO con parser incremental y lector DL
   sobre RAM viva. Queda: contenido DL en host (solo fiable
   con RAM viva, no con snapshot de fin de run), TEV
   multi-etapa/lighting/EFB (no-op), y la prueba en
   dispositivo con `sfa-data` (sin ejecutar aqui). Ver
   «Fase 11».
5. **Audio MusyX/DSP pendiente (Fase 14: mapeo HECHO;
   Fase 15: trampolín HECHO, arranque de stream
   BLOQUEADO con causa nueva):**
   backend AAudio implementado (sin probar en
   dispositivo), tabla ID → WAV generada y bridge
   verificado en host (ver «Fase 14» y «Fase 15»).
   ~~(a) El trampolín de callbacks DVD~~ **HECHO en
   Fase 15** (directorio de streams cargado,
   0x810182E0/905; el juego sigue pidiendo solo
   1367, ausente de `Streams.bin`). Falta: (a) la
   completitud async DVDLow del stream preparado
   (`AudioStream_PrepareCallback` →
   `AudioStream_StartPrepared` → `currentId`/
   `playing`): tras `Play(1301)` = 1, el juego
   queda en `preparing` 340 con `dvdState` 1 y 10
   `audioUpdate` no lo mueven (ver «Fase 15»);
   (b) las secuencias MusyX (`.pro`/`.poo`/
   `midi.wad`: cargados, sin ninguna petición de
   reproducción trazada en la ventana) y la
   emulación DSP (solo el evento de init, no
   tareas reales); (c) mezcla de voces y payload
   de audio WAV en Pack B para la APK.
6. **Input pendiente (parcial):** mando/teclado/táctil-stick
   mapeados; faltan botones táctiles en pantalla (sin layout
   definido, no inventado) y rumble (`PADControlMotor` sin
   HLE). **Flanco JustPressed: MEDIDO en Fase 8 a nivel
   `padUpdate`** (la fórmula es `Just = Held & ~Prev`,
   leída en 0x800151E4–0x80015210): con Start programado
   desde el PADRead nº 3 (0 en los dos primeros), el run
   termina con Held0 = Just0 = Prev0 = 0x1000, frente a
   Held0 = Prev0 = 0x1000, Just0 = 0 con Start desde el
   arranque. En Fase 10, la prueba a nivel de bucle de
   título SÍ se hizo (Start tras la película en marcha
   rompe el bucle attract/title; ver «Fase 10», punto 1),
   pero la pantalla nueva no queda identificada como menú
   (identificada en Fase 11: pantalla de carga + aviso de
   falta de Memory Card, ver «Fase 11»). **Menú del aviso:
   MEDIDO en Fase 12** (ver «Fase 12», punto 1): NO se
   mueve con D-pad; se mueve con stick Y / C-stick Y
   (`padGetStickY`/`padGetCY`, con flanco) y se confirma
   con A (bit `0x100` de `getButtonsJustPressed`).
7. **Datos (Fase 10, vía definida, SAF pendiente):** Pack B
   (240 MB, sin `streams/`) aparte, nunca en APK ni en Git;
   la APK ya acepta `<base>/sfa-data/sys/main.dol` +
   `<base>/sfa-data/files/` (copia interina por adb, ver
   «Fase 10», punto 3). Falta el picker SAF + copia en la
   app; sin lista mínima verificada todavía.
8. **SDK (Fase 10, resuelto por vía manual):** SDK en
   `~/tools/android-sdk` (build-tools 34.0.0, platforms
   android-34); Gradle 8.6 sigue fallando por el daemon,
   así que la APK se construye por vía manual documentada
   (`build-apk-manual.sh`, javac/d8/aapt2/zipalign/
   apksigner) y validada (ver «Fase 10», punto 4).
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

## Fase 10 (2026-10-26, este tramo): Start saca del bucle attract, renderer GX en APK, APK de prueba GX

### 1. Transicion pelicula -> titulo con Start: SI, con matiz honesto

`TitleMenu_run` YA se despachaba en la Fase 9: la pregunta de
esta fase no era llegar a el, sino salir de su bucle de
attract con Start. Respuesta: **si, Start rompe el bucle**,
pero la pantalla nueva **no queda identificada como "menu
principal con opciones"** (ver matiz al final del punto).

Test host nuevo (fuera del repo, como siempre):
`work-port/fase2-tests/test_phase10.cpp` (+
`build_phase10.sh`): como `test_phase9` + pulsacion Start
mantenida desde un PADRead programado
(`SetPadInject(true, 0x1000)` + `SetPadPressFromRead(n)`,
la via valida de las Fases 6-8: flag de muestra fresca
0x803DE65D, Held/Just/Prev por `padUpdate`) + `texloads.csv`
de salida. `SFA_PCTRACE=1` registra los despachos de
`TitleMenu_run`/`TitleMenu_render`/`prepareMovie`/
`releaseMovieBuffers`/`THPPlayerStop`.

- run42 baseline (press = 0, 5M despachos): reproduccion
  EXACTA de run41: FIFO 15.021.078 B, SHA-256 identico a
  run41, OSReport identico, PC final 0x80051580
  (`addSphereMapTexStage`), PADRead x27, VI cadenas 38,
  GXLoadTexObj x10.870, DVDOpen x132, async x131,
  `video_ready_tex` 2/3, 0 exceptions, `TitleMenu_run` x24
  (primero en el despacho 2.352.692, luego uno por frame,
  ~107k despachos/frame) y `TitleMenu_render` x23. Sin
  regresion frente a la Fase 9.
- run43 press12 (Start desde PADRead #12, 5M): ultimo
  `TitleMenu_run` en el despacho 3.211.355 (baseline: ultimo
  en 4.979.572); despues, `TitleMenu_run` x9 en total y
  `TitleMenu_render` x8: el bucle attract/title se detiene
  y el juego sigue en otro bucle. PADRead x191, VI cadenas
  198 (equilibradas pre/post), FIFO 10.095.648 B,
  GXLoadTexObj x5.028, DVDOpen x130, OSCreateThread x4
  (baseline x10: los hilos THP ya no se recrean),
  LCLoadBlocks x0 (x270), LCStoreBlocks x1 (x105),
  `video_ready_tex` 0/3, Held0 = Prev0 = 0x1000, Just0 = 0
  (flanco consumido, Start mantenido), 0 exceptions, PC
  final 0x80015CF0 (`utf8GetNextChar`, en mitad de dibujo
  de texto). Post callback sigue siendo `PlayControl`
  (0x8011897C).
- run44 press20 (Start desde PADRead #20, 5M): ultimo
  `TitleMenu_run` en 4.149.573; PADRead x90, VI 99, FIFO
  12.867.490 B, GXLoadTexObj x8.014, OSCreateThread x7,
  LCStoreBlocks x53, `video_ready_tex` 0/3, Held0 = 0x1000,
  0 exceptions, PC final 0x800799FC (`gxTevCommitStages`,
  en mitad de dibujo). Valores intermedios exactos entre
  press12 y baseline en todos los contadores.
- Dosis-respuesta monotona: cuanto mas tarde el Start,
  mas tarde la salida del bucle y mas FIFO/GXLoadTexObj
  acumulados. Es causalidad, no casualidad de un run.
- Firma post-transicion (identica en press12 y press20,
  distinta del baseline): texObjs dominantes 0x80E24E40
  (mapa 0) + 0x816148C0, frente al conjunto rotante de la
  pelicula (0x816E2540/0x816DF420/0x80EC6BE0/0x810ABB60...).
  Sin ficheros DVD nuevos (DVDOpen 130/131 frente a 132) y
  sin lineas OSReport nuevas (45 cambios en los tres runs):
  la pantalla nueva reutiliza assets del frontal ya
  cargados (`gamefront`), no carga un nivel ni un menu
  nuevo desde disco.
- MATIZ (no maquillado): la identidad de la pantalla nueva
  NO esta probada como menu principal con opciones: no hay
  traza de `TitleMenuItem_*`, ni texto de menu leido, ni
  DLL UI vigente identificado. Lo probado es la salida del
  bucle attract/title a un bucle sano post-attract (PADRead
  y VI por frame, cadenas VI equilibradas, 0 exceptions,
  dibujo continuo con 2 texturas estables). Siguiente paso
  para nombrarla: trazar el DLL UI vigente / estado de
  menu, o renderizar el tramo post-transicion con el parser
  ampliado (punto 2, limite). NO se afirma "pantalla de
  titulo con menu" todavia.

### 2. Renderer GX en APK (GLES3): camino host portado, con limite medido

Ficheros nuevos en la rama (este commit):

- `app/src/main/cpp/renderer/gx_translate.{h,cpp}` — sin
  dependencias GL, testeable en host: `GxDrawToGlQuads()`
  (la misma transformada que el renderer host de Fase 5b:
  pos_matrix 3x4, proyeccion orto o perspectiva — camino
  perspectiva NO validado en run19 —, viewport y region
  EFB (342,342); salida NDC con y hacia arriba en vez de
  pixeles de canvas) y `DecodeGxTexObj()` (mismo layout
  GXTexObj verificado: +8 dims/formato, +12 direccion,
  +36 tamano base; false si el tamano no coincide o el
  formato es de paleta/desconocido).
- `app/src/main/cpp/renderer/gx_gl.{h,cpp}` — GLES3:
  programa de textura simple, solo QUADS (prim 0x80, 4
  vertices, atributos directos, con viewport/proyeccion);
  cualquier otro draw se cuenta en `quads_skipped_` y no
  se dibuja. Texturas: re-upload en cada frame por
  textura distinta (deliberadamente lento para una
  prueba: el contenido de una textura THP cambia en cada
  frame aunque su texObj sea el mismo, asi que cachear
  por texObj mostraria el primer frame siempre). Sin
  textura (tex_obj 0): color diagnostico (32,32,64), como
  el host. Sin resolver: magenta 1x1, como el host.
  `DrawCheckerQuad()`: damero 64x64 procedural (codigo,
  NO arte del juego) para el paso "quad con textura".
- `app/src/main/cpp/renderer/renderer.{h,cpp}` — orden de
  frame: `BeginFrame()` (clear) -> `DrawTestQuad()` o
  `DrawGxFrame(draws, ram, ram_size)` -> `RenderFrame()`
  (swap). `GxGl` se inicializa tras el contexto EGL; si
  falla, el renderer sigue haciendo clear (fallo en log).
- `app/src/main/cpp/gamecube_runtime/runtime.{h,cpp}` —
  tras `videoInit`, `Frame()` ya NO se detiene: el juego
  sigue en rebanadas por frame (100.000 despachos o 0,25 s,
  sin stop-PC), con `game_ended_` solo en exception /
  unknown_pc / exit (nunca silencioso). Sin captura FIFO
  en APK (tope 32 MiB: no es la via del renderer).
  `SetGxDraws()` es el punto de alimentacion GX futuro,
  hoy vacio. Con juego cargado, NO se dibuja el damero
  (clear hasta que llegue GX real). Sin juego, clear +
  damero.
- `app/src/main/cpp/CMakeLists.txt` — anadidos `gx.cpp`,
  `gx_texture.cpp`, `gx_gl.cpp`, `gx_translate.cpp` (la
  via Gradle, cuando funcione, no debe perderlos).

Validacion host (test nuevo, fuera del repo):
`work-port/fase2-tests/test_gx_gl.cpp` (+ `build_gx_gl.sh`):
sobre run19, parse_ok = 1, **602/602 draws traducidos, 0
saltados, 3/3 texturas decodificadas** (IA8 376x104,
RGB5A3 128x160, CMPR 180x92), primer quad fullscreen NDC
x [-1,1], y [0.912,-0.916] (= canvas 640x439 del host).

LIMITE MEDIDO (no maquillado): el parser host se detiene
en el FIFO de la pelicula (run42, run43 y run44) en el
**offset 2497, opcode desconocido 0x03** (contexto
`03000300330606000200020022060600`): solo 5 draws
parseados, 4 traducidos. Es decir: el camino GX portado
cubre los frames tipo run19 (logos/barra/Dolby), NO los
frames de pelicula/3D todavia. Ampliar el parser (opcode
0x03, VATs y prims mas alla de QUADS VAT1) es el
siguiente paso del renderer, antes de afirmar un frame de
pelicula en APK.

No-op documentados (no fallos silenciosos): TEV
multi-etapa, `Rcp_*`, EFB, lighting, y display lists
complejas mas alla de QUADS directos (el parser host las
soporta hasta profundidad 4, el renderer GL solo dibuja
QUADS directos).

THP via `PopDecodedTextureSet` / `video_ready_tex`: en
host, las texturas listas llegan al dibujo como
`GXLoadTexObj` ordinarios (el juego las carga como
texObjs); no hay un camino THP separado en el renderer.
Cuando el parser cubra esos draws, las texturas THP
fluiran por el mismo `DrawDraws` (con re-upload por
frame por reutilizacion del texObj). Hoy: `video_ready_tex`
2/3 en baseline, 0/3 tras Start (la pelicula ya no se
muestra).

### 3. Via de datos para la APK de prueba (definida; SAF pendiente)

Layout que ya acepta `native-lib.cpp` (dormido sin
datos, este commit): si existe

    <base>/sfa-data/sys/main.dol
    <base>/sfa-data/files/...

donde `<base>` es `internalDataPath` o `externalDataPath`
de la app, el runtime hace `SetDiscRoot(.../files)` +
`LoadGame(.../main.dol)` y lo registra en boot.log. Sin
`sfa-data`, boot.log registra "sin datos (modo clear +
quad de prueba)" y la APK NO falla: queda en clear +
damero.

- Pack B = `disc/files/` sin `streams/` = 240 MB
  (239.678.460 B). Nunca en APK ni en Git (limite
  100 MB/fichero). El runtime debe leer el arbol nativo
  del disco, no PNG/WAV/OBJ convertidos.
- No existe lista minima verificada para arrancar: se
  medira cuando el runtime registre que abre (el HLE DVD
  ya loguea cada open; en run42 son 132 opens).
- Ruta prevista para el usuario (NO implementada aun en
  esta APK): Drive -> Descargas -> picker SAF en primer
  arranque -> copia a la carpeta privada de la app
  (`sfa-data/` de arriba). Ruta interina para esta build
  de prueba (debuggable, solo para probar): con la APK
  instalada y la app ya abierta una vez (para que exista
  su carpeta externa),

      adb push <carpeta-Pack-B>/sys/main.dol \
        /sdcard/Android/data/com.starfox.port/files/sfa-data/sys/main.dol
      adb push <carpeta-Pack-B>/files \
        /sdcard/Android/data/com.starfox.port/files/sfa-data/files

  (MTP a `Android/data/` puede no mostrarse en Android
  11+, por eso el interino es adb, no MTP.) Tras copiar,
  cerrar y reabrir la app: boot.log debe decir "juego
  cargado desde ..." en vez de "sin datos".
- Estado honesto: **la APK de prueba de esta fase AUN NO
  puede cargar Pack B por si sola** (falta el picker SAF
  + copia). Entrega: camino host + APK de arranque con
  renderer, nunca etiquetada como jugable.

### 4. APK de prueba GX (NO JUGABLE, solo arranque + renderer)

**Fichero en esta rama:**
`android-port-base/app-debug-gx-test.apk`
**Tamano:** 12.522.150 bytes
**SHA-256:**
`70fedbd289440118e9c21da2ca10498ca2a83601d29247301f406ac124aab8ce`
**Paquete:** `com.starfox.port`, versionCode 2 /
`0.2.0-gx-test`, minSdk 26, targetSdk 34, actividad
`MainActivity` (landscape, `android.app.lib_name`
`starfox`), `application-debuggable` (SOLO por ser build
de prueba, etiquetada como tal aqui y en su nombre;
quitar para release).
**Contenido:** `lib/arm64-v8a/libstarfox.so`
(27.360.560 B, el .so de este tramo) +
`lib/arm64-v8a/libc++_shared.so` (9.236.352 B, NEEDED
por el .so) + `classes.dex` + `assets/README.md`.
Sin datos del juego, sin DOL, sin disco.
**Validacion:** `apksigner verify` OK (v2 y v3, 1
firmante; v1 desactivada por apksigner al ser minSdk
26, esperado), `zipalign -c` OK, `aapt2 dump badging`
correcto (sdkVersion 26, targetSdkVersion 34, sin
permisos implicitos tras anadir `<uses-sdk>` al
manifiesto — la primera build de este tramo los tenia
por asumir minSdk 1, corregido y reconstruido),
`apktool d` OK (manifiesto: paquete, debuggable de
prueba, MainActivity; libs arm64-v8a presentes).
Construida por via manual
(`android-port-base/build-apk-manual.sh`: javac/d8 con
`--lib android.jar`/aapt2/zipalign/apksigner) porque
Gradle 8.6 sigue fallando en este entorno con "Could
not receive a message from the daemon". El script queda
en el repo para reproducirla. Firma: keystore de prueba
autofirmado en `work-port/test-debug.keystore` (fuera
del repo, no se commitea); al instalar pedira "Instalar
apps desconocidas" una sola vez para la app instaladora.

**Que hace al abrirla (por codigo, NO probado en
dispositivo en este tramo):** arranca NativeActivity,
inicializa EGL/GLES3 + programa GX, y dibuja clear +
damero procedural centrado, y escribe `boot.log`
(`StarFoxPort` en logcat). Si no hay `sfa-data`,
boot.log dice "sin datos (modo clear + quad de
prueba)". Si hay `sfa-data` copiado por adb (punto 3),
intenta cargar el DOL y avanzar tras `videoInit` en
rebanadas por frame (sin GX todavia: clear hasta que
llegue la alimentacion GX). **No probado en Tab S8 en
este tramo: no hay ejecucion en dispositivo aqui; el
boot.log real de dispositivo queda pendiente.**

**Que NO hace / NO es:** no es jugable, no carga el
juego sin `sfa-data`, no dibuja ningun frame del juego
(todavia), no tiene sonido de juego, no tiene botones
tactiles, no tiene picker SAF. Si se abre y se ve clear
+ damero, ESO ES LO ESPERADO en esta fase, no un fallo
del juego. La APK Fase 0 (`app-debug-boot-test.apk`,
57.916 B) queda intacta en la rama, sin reconstruir.

### 5. Build NDK (verificacion Fase 10)

Build `ndk-phase10` (directorio nuevo bajo `work-port/`,
fuera del repo; JOBS=4, 179 C + runtime C++ desde cero;
2 CPUs en esta VM: el build tardo ~30 min, la mayoria
en chunks): PASS, **0 errores**.
`libstarfox.so` **27.360.560 B**, ELF64 `DYN` AArch64,
SHA-256
`08eedac321021516333aac1bd7d59a2b841df0ce7d5f95cf4a34bb7391dca5c0`
(Fase 9: 27.340.304 B,
`c2ba48298589299a53b6e735811ef063e8b4af1a2ff999d1fa7c7c1a1915efa2`;
delta +20.256 B por el renderer GX y el gancho de datos),
comprobacion del script "OK: ningun simbolo
mem_/ppc_/func_/dolrecomp_ sin resolver", 186 undefined
totales (Fase 9: 153; **delta +33, todos explicados**:
31 funciones GLES nuevas del renderer GX + 2 vtables
RTTI de C++, solo libs del sistema). `android_main`
en `T`. Compilacion dirigida previa de los 5 ficheros
tocados con el toolchain NDK: 0 errores.
Regresion host: run42 identico a run41 (punto 1) y
`test_phase6` modo unit: TODO OK, 0 fallos.

### 6. Que queda (tras Fase 10, en orden)

1. Nombrar la pantalla post-Start: trazar el DLL UI
   vigente / estado de menu (o renderizar el tramo
   post-transicion cuando el parser lo cubra). Sin eso,
   no afirmar "menu principal".
2. Renderer GX: ampliar el parser (opcode 0x03 en offset
   2497 del FIFO de pelicula, VATs y prims mas alla de
   QUADS VAT1) y alimentar `SetGxDraws()` por frame con
   estado de parser incremental (hoy el FIFO se acumula
   y el parser es de stream completo: no sirve por
   frame tal cual).
3. Picker SAF + copia de Pack B a `sfa-data/` (punto 3),
   y prueba real en Tab S8 de la APK GX (boot.log,
   damero, y luego carga con datos).
4. CARD (guardado) y resto de HLE que el bucle principal
   vaya pidiendo al avanzar mas alla del titulo.
5. Mapeo ID de sonido del juego -> WAV; secuencias MusyX;
   DSP real.
6. Botones tactiles en pantalla (layout por definir),
   rumble.
7. APK 100% jugable: solo cuando renderer + datos +
   input tactil + audio esten probados en dispositivo.
   La APK de este tramo sigue siendo solo arranque con
   renderer (ver punto 4).

## Fase 11 (2026-10-26, este tramo): renderer completo (parser GX ampliado + pantalla post-Start identificada + APK GX11)

### 1. Correccion del layout VCD (el error real bajo el "opcode 0x03")

El parser de la Fase 10 tenia los campos VCD desplazados:
usaba POS@0-1, NRM@2-3, CLR0@4-5, CLR1@6-7,
PNMTXIDX@8, TEXnMTXIDX@9+n. El layout real YAGCD
(5.11.2, verificado contra el documento y contra el
stream) es: **PMIDX@0, TnMIDX@1+n, POS@9-10, NRM@11-12,
COL0@13-14, COL1@15-16** (HI: TEXn@2n, ese si estaba
bien). run19 parseaba igual por compensacion de dos
errores: el bit 9 (POS directo real) se leia como
"TEX0MTXIDX presente" y el bit 0 (PMIDX real) como "POS
directo": mismo numero de bytes, mismas posiciones, solo
cambiaba la etiqueta del primer byte (que antes se
guardaba como `tex_mtx_idx` y ahora como `pos_mtx_idx`,
y por eso el primer quad de run19 sale IDENTICO tras la
correccion: NDC x [-1,1], y [0.912,-0.916]).

Con el layout corregido, el "opcode desconocido 0x03" en
offset 2497 queda explicado sin tocarlo: el parser viejo
sobre-consumia el strip VAT2 como 21 B y aterrizaba en
medio de un vertice. Y el draw que detenia la Fase 10
(0x9C, strip VAT4 en 59080, VCD 0xA00) se decodifica
solo: POS directo + NRM directo, VAT4 F32+F32 = **24 B
exactos**, validados por 16 draws consecutivos a 819 B
exactos (3 + 34x24) que teselan una rejilla en x
(-1, -0.8666, -0.7333, -0.6, ...).

### 2. Parser ampliado: dos desviaciones MEDIDAS que siguen en pie

Bajo el layout corregido, dos casos siguen sin reproducir
los limites del stream y usan stride medido (nunca reglas
GX generales; fuera de estos dos triples exactos rige la
aritmetica VCD/VAT):

- **TRIANGLESTRIP VAT2, stride aritmetico 21 -> 8 B
  opacos** (run42, offsets 2157-4122): 15 draws a 131 B
  exactos (3 + 16x8), seguidos de 32 NOP + recarga VCD/XF
  limpia en 4154. Contenido de 8 B sin decodificar (sin
  bases de arrays CP 0xA0-0xBF en el stream y sin
  escrituras CP por MMIO en la traza HW): se guarda crudo
  (`has_raw_vertices`), se cuenta (`n_opaque_draws`) y el
  renderer lo salta.
- **POINTS VAT0, stride aritmetico 11 -> 10 B** (run42,
  offsets 4207-56339): 92 draws a 567 B exactos
  (3 + 50x10 + 64 NOP); el ultimo cierra con 32 NOP
  exactos antes de la recarga XF de viewport en 56339.
  Decodificacion manual POS S16 XYZ + TEX S16 ST, sin
  byte PMIDX (la formula de shift 2^(shift+2) es
  extrapolacion de VAT1, no validacion para VAT0; el
  renderer salta los POINTS igualmente).

Ademas: **atributos indexados** (VCD 2 = indice8,
3 = indice16) ya no detienen el parse: se leen los
indices (POS/TEX0 guardados en `GxVertex`, resto
consumidos), el draw queda marcado `indexed` y el
renderer lo salta, contado (`n_indexed_draws`,
`indexed_attrs`). En los runs actuales no aparece ningun
draw indexado (0 en todos), pero el camino existe.
**Display lists (0x40):** con lector RAM valido se
parsea el contenido (recursion, profundidad maxima 4);
sin lector valido (test host sin RAM, o direccion/tamano
fuera de rango) se consumen sus 9 B y se cuenta
(`n_dl_skipped`), SIN detener el stream. Esto es lo que
permite el parseo completo del FIFO en host.

### 3. Parseo completo del FIFO de pelicula (verificacion host)

Test host nuevo (fuera del repo, como siempre):
`work-port/fase2-tests/test_gx11.cpp` +
`build_gx11.sh` (parseo completo + triangulacion +
equivalencia Feed incremental + segmento post-transicion
+ fase DL-RAM diagnostica). Resultados:

- **run19 (regresion):** parse_ok=1, 602 draws (QUADS
  VAT1), 1204 tris, 0 saltados, 3 texturas, primer quad
  identico a Fase 10. Feed incremental equivalente al
  parseo completo en trozos de 1/7/64/1000/65536/131/567
  bytes y de una pieza.
- **run42 / run45ph11base (baseline, FIFO 15.021.078 B):
  parse_ok=1, 5148 draws, 0 desconocidos, 19586 tris,
  107 saltados (92 POINTS + 15 strips opacos), 21
  texturas distintas, 6674 DLs (todas saltadas sin
  lector).** Desglose: QUADS 2769 (1852 VAT1 + 917
  VAT4), TRIANGLESTRIP 2287 (15 VAT2 + 16 VAT4 + 2256
  VAT0), POINTS 92 VAT0. run45 = run42 en todo.
- **run43press12 / run46ph11press12 (FIFO 10.095.648 B):
  parse_ok=1, 30188 draws, 63650 tris, 2272 DLs.**
  run44press20 (12.867.490 B): 18137 draws, 42556 tris,
  4544 DLs. run46 = run43 en todo (sin regresion).
- **DLs:** 6674 llamadas en run42; las sanas forman una
  libreria reutilizada (164 pares (direccion, tamano)
  distintos, el mas repetido x368; tamano mediano 2400 B,
  rango 96-64992 B). 120 llamadas anomalas: 96x DL
  0x80379320 con size 0x7FC86CE0 (2,1 GB, imposible) y
  24x DL 0x816A0000 con size 0. Con lector con chequeo de
  rango devuelven nullptr y se saltan contadas; el
  tratamiento de 9 B queda validado por el walk completo
  a EOF sin desconocidos. El word de size anomalo queda
  SIN explicar (no se inventa mascara ni semantica).
- **Fase DL-RAM (diagnostica, NO exito/fracaso):** con
  lector sobre `ram.bin` de fin de run, el parseo falla
  en el offset 76003 dentro del DL 0x816E75E0 (35.360 B,
  solapado con el siguiente DL 0x816E7800): la libreria DL
  se reescribe durante el run y el snapshot final NO
  contiene los DLs tal como estaban en cada llamada (los
  DLs tardios si sobreviven: strips VAT6 visibles en
  0x80EE5C60). Conclusion: **el contenido DL solo es
  fiable con RAM viva (APK), nunca con snapshot host.**
  Por eso la fase DL-RAM no marca el test como fallido.

### 4. Pantalla post-Start IDENTIFICADA (no es el menu principal)

Umbral PCTRACE de run46 (ultimo `TitleMenu_render`):
FIFO offset > 5.232.323. Segmento POST en run46:
**28487 draws, todos QUADS, 56974 tris, 0 saltados**;
texturas: 0x80E24E40 (fuente) x28308, 0x816148C0
(negro) x179; rango de indices [1701, 30187].
Render host del tramo (renderer 640x480 + variante 4x
para leer; el render 1x deja los glifos a ~1,7 px):

1. **Pantalla de carga** (primeros draws POST): texto
   leido literal del render 4x:
   "Star Fox Adventures is loading. / Do not touch the
   Memory Card or the POWER Button. / Star Fox Adventures
   only supports Memory Card Slot A."
   (3 lineas, atlas de fuente 512x64 I4 0x80E24E40).
2. **Aviso de falta de Memory Card** (desde ~draw 16000
   hasta el final del run): "There is no Memory Card in
   Slot A." + opciones "Retry" / "Play (but cannot save
   your progress)". Ventana 13000: solo texto de carga
   (y 61-69); ventana 16000: mezcla (transicion);
   ventana 18000 en adelante: solo aviso (y 36-40).
   **Cual opcion esta seleccionada NO se puede afirmar:**
   el renderer host no modela color TEV (todo sale
   blanco) y no hay traza de seleccion.
3. **NO es el menu principal:** no hay traza de
   `TitleMenuItem_*` (0 despachos inter-chunk en PCTRACE;
   las llamadas intra-chunk son invisibles para PCTRACE,
   ver matiz Fase 10), ni cambio de DLL UI (`curUiDll`
   = 4, `pendingUiDll` = 0 en los tres runs; `loadUiDll`
   solo 2 veces en init, nunca tras Start), ni texto de
   menu. La pantalla tras Start es carga y, sin tarjeta
   (CARD sin implementar en el entorno host), el aviso
   de falta de tarjeta. El run termina en esa zona
   (PC final 0x80015CF0 `utf8GetNextChar`, dibujo de
   texto). La cola del run sale negra en render
   acumulado porque el run termina a mitad de frame tras
   los quads negros de limpieza, no porque la pantalla
   sea negra: ventanas anteriores (29000, 29500) si
   muestran el texto del aviso.

### 5. Renderer APK: triangulos + alimentacion por frame

- `renderer/gx_translate.{h,cpp}`: `GlTri` +
  `GxDrawToGlTris()` (misma transformada por vertice que
  `GxDrawToGlQuads`, sin cambiarla): QUADS -> 2 tris
  (0,1,2)(0,2,3) (pixel-identicos al camino anterior);
  TRIANGLES -> grupos de 3; TRIANGLESTRIP -> orden
  YAGCD (v0,v1,v2),(v1,v3,v2),(v2,v3,v4),...;
  TRIANGLEFAN -> (v0,v1,v2),(v0,v2,v3),.... LINES/
  LINESTRIP/POINTS, draws indexados y opacos devuelven
  false y se cuentan como saltados.
- `renderer/gx_gl.{h,cpp}`: `DrawDraws()` dibuja por
  `GL_TRIANGLES` (`DrawTriangleVertices`, mismo shader
  y programa de textura); cache de texturas por frame,
  sin textura -> (32,32,64), sin resolver -> magenta,
  todo sin cambios. Contador de draws mantenida
  (`quads_drawn_` = draws dibujados) + contador nuevo
  de triangulos (`tris_drawn_`).
- `gamecube_runtime/runtime.{h,cpp}`: `FeedGxFrame()`:
  tras CADA rebanada (boot y post-boot) drena la captura
  FIFO (tope 32 MiB, evitado por el drenaje), convierte
  las texloads HLE nuevas a offset global
  (`gx_fifo_base_ + offset relativo`), alimenta el
  parser incremental y deja los draws en
  `SetGxDraws()`; en fallo del parser, log de
  `FirstUnknown()` una vez y `ResetFeed()` (el juego
  reescribe VCD/VAT/XF cada frame). `LoadGame()` activa
  la captura + lector DL sobre RAM viva con chequeo de
  rango; `Shutdown()` la desactiva. Sin datos, el
  comportamiento Fase 0 no cambia (clear + quad).
- **Caveat renderer (honesto):** TEV multi-etapa,
  lighting, EFB y color de seleccion siguen siendo
  no-op; las texturas I4 (fuente) se suben con alfa 255
  (el decode compartido no da alfa de intensidad), asi
  que en la APK los glifos se dibujan con su fondo negro
  opaco (legibles como bloques de texto blanco sobre
  negro; el solape entre glifos adyacentes no existe en
  el stream: ancho <= avance). El manejo alfa/TEV para
  texto queda pendiente, documentado aqui, no maquillado
  como resuelto.

### 6. APK de prueba GX11 (NO JUGABLE, solo renderer real)

**Fichero en esta rama:**
`android-port-base/app-debug-gx11-test.apk`
**Tamano:** 12.518.054 bytes
**SHA-256:**
`0f60154e91908d288acd3ccd1acefa919405f0afd40707479e860cba544abd4c`
**Paquete:** `com.starfox.port`, versionCode 3 /
versionName `0.3.0-gx11-test`, debuggable SOLO por ser
build de prueba, solo arm64-v8a.
**Validacion:** apksigner verify OK (esquemas v2+v3),
zipalign -c 4 OK, aapt2 badging OK (v3 /
0.3.0-gx11-test / debuggable / arm64-v8a), apktool d OK,
`libstarfox.so` interior 27.360.560 B = el .so NDK
verificado abajo. `build-apk-manual.sh` acepta ahora
version-code/version-name opcionales (defecto 3 /
0.3.0-gx11-test). La APK Fase 10
(`app-debug-gx-test.apk`, SHA-256
`70fedbd289440118e9c21da2ca10498ca2a83601d29247301f406ac124aab8ce`)
y la Fase 0 (`app-debug-boot-test.apk`) quedan intactas,
sin reconstruir.
**Que hace (por codigo, NO probado en dispositivo):**
arranca, EGL/GLES3 + programa GX, clear + damero si no
hay datos; **con `sfa-data` por adb, carga el DOL,
avanza tras `videoInit` y dibuja los frames del bucle
real por triangulos con texturas desde RAM viva**
(pelicula/title/carga/aviso, segun hasta donde llegue
el bucle), con `boot.log`.
**Que NO hace / NO es:** no es jugable, no tiene
sonido de juego, no tiene botones tactiles, no tiene
picker SAF, no incluye datos/disco (nunca en APK ni en
Git), no esta probada en una Tab S8 real en este tramo
(sin Android/emulador aqui; la validacion es estructura:
compilacion, firma, manifiesto, librerias, simbolos).
Si se abre sin datos y se ve clear + damero, ESO ES LO
ESPERADO, no un fallo.

### 7. Build NDK (verificacion Fase 11)

Build `ndk-gx11` (copia de `ndk-phase10` bajo
`work-port/`, fuera del repo; incremental por fecha:
solo se recompilaron los ficheros tocados + chassis):
PASS, **0 errores**. `libstarfox.so` **27.360.560 B**
(mismo tamano que Fase 10 por coincidencia de alineacion
del enlace; el SHA-256 si cambia), ELF64 AArch64, SHA-256
`f9e3de8f5342ebfe808d36be7c02cd418b6cfa23428b81b6423ab331c04cd0be`,
`android_main` en `T`, comprobacion del script "OK:
ningun simbolo mem_/ppc_/func_/dolrecomp_ sin
resolver", **186 undefined totales, lista IDENTICA a
Fase 10** (delta 0: el camino de triangulos usa las
mismas funciones GLES que el de quads).
Regresion host: run19 identico (punto 3), run45 = run42
y run46 = run43 en contadores (verificacion previa de
esta fase, sin cambios en el chassis: el parser solo
lee el FIFO capturado, no afecta a la ejecucion).

### 8. Que queda (tras Fase 11, en orden)

1. **~~CARD (guardado): AHORA ES EL BLOQUEADOR VISIBLE:~~
   RESUELTO en Fase 12 (ver «Fase 12»):** sin tarjeta, el
   juego se quedaba en el aviso "There is no Memory Card
   in Slot A" (Retry / Play sin guardar). Resuelto por
   dos vías: tarjeta virtual en Slot A con formato válido
   y input (stick Y + A) que elige "Play (but cannot
   save your progress)".
2. Picker SAF + copia de Pack B a `sfa-data/` y prueba
   real en Tab S8 de la APK GX11 (boot.log + frames
   reales con datos; sin eso, la APK GX11 sigue sin
   probar en dispositivo).
3. Contenido DL en APK con RAM viva (el camino ya esta
   cableado; falta probarlo con datos: los DLs aportan
   la mayor parte de la geometria de la pelicula).
4. TEV multi-etapa / color de seleccion / alfa de
   texturas I4 en el renderer (texto y seleccion
   correctos, no solo bloques blancos).
5. Mapeo ID de sonido del juego -> WAV; secuencias
   MusyX; DSP real.
6. Botones tactiles en pantalla (layout por definir),
   rumble.
7. APK 100% jugable: solo cuando renderer + datos +
   CARD/input + audio esten probados en dispositivo. La
   APK de este tramo sigue siendo solo renderer real
   (ver punto 6).

## Fase 12 (2026-10-26, este tramo): CARD Slot A — tarjeta virtual + ruta «Play sin guardar», aviso superado

El bloqueador visible nº 1 de la Fase 11 queda RESUELTO en
host por DOS vías independientes, ambas verificadas con
evidencia (no con la predicción del código). El juego ya no
se queda en el aviso «There is no Memory Card in Slot A»:
con tarjeta virtual crea y lee su partida, y sin tarjeta
el menú del aviso se puede recorrer y confirmar hasta
«Play (but cannot save your progress)», llegando en ambos
casos al bucle de título (`TitleMenu_run`/`TitleMenu_render`
por frame, película attract parada, FIFO creciendo).

### 1. API CARD que llama el juego (desde código huésped, no supuesta)

Funciones SDK en el DOL (`codigo/generated/generated_symbols.h`,
`codigo/symbols.map`); el juego solo llama las variantes
síncronas (verificado por `bl` en `codigo/generated/chunks/*.c`;
las Async solo las llaman los wrappers síncronos del propio
SDK, así que quedan como código huésped sin ejecutar):

- `CARDInit 0x8025F664`, `CARDProbeEx 0x802624B8`,
  `CARDMount 0x80262D1C`, `CARDCheck 0x80262398`,
  `CARDOpen 0x8026391C`, `CARDClose 0x80263A94`,
  `CARDCreate 0x80263E40`, `CARDRead 0x802642B8`,
  `CARDWrite 0x80264634`, `CARDDelete 0x80264830`,
  `CARDGetStatus 0x80264A70`, `CARDSetStatus 0x80264D10`,
  `CARDGetSerialNo 0x80264D58`, `CARDUnmount 0x80262E00`,
  `CARDFormat 0x80263648` (además `CARDMountAsync`,
  `CARDCheckExAsync`, `CARDCreateAsync`, `CARDReadAsync`,
  `CARDWriteAsync`, `CARDDeleteAsync`, `CARDSetStatusAsync`).
- Wrappers del juego: `cardProbe 0x8007E08C`,
  `showMemCardError 0x8007E42C`, `cardGetMessage 0x8007E190`,
  `saveGame 0x8007FBA8`, `loadSaveGame 0x8007DEDC`,
  `maybeTryLoadSave 0x8007DE40`, `cardCreateSaveFile 0x8007DF84`,
  `cardFormatMemoryCard 0x8007D910`,
  `cardWriteOptions 0x8007DD08`, `cardShowLoadingMsg 0x8007E8A4`,
  `saveGame_prepareAndWrite 0x8007EEE4`,
  `cardDeleteSaveFile 0x8007DB80`,
  `_initCardAndDsp 0x8007E170` (llama a `CARDInit`),
  `loadMemCardImages 0x8007F698`,
  `cardSetStatusNoCard2 0x80080164` (callback de montaje:
  guarda 3 en el global de estado de tarjeta).
- Códigos CARD (valores SDK, confirmados en el código del
  juego): READY 0, BUSY -1, WRONGDEVICE -2, NOCARD -3,
  NOFILE -4, IOERROR -5, BROKEN -6, EXIST -7, NOENT -8,
  INSSPACE -9, NOPERM -10, LIMIT -11, NAMETOOLONG -12,
  ENCODING -13, CANCELED -14, FATAL -128. -85 es interno
  del juego (serie distinta), no un código CARD.
- `cardProbe(chan)`: `CARDProbeEx` en bucle mientras -1;
  0 + sector 8192 → estado 13, devuelve 1 (tarjeta útil);
  0 + sector != 8192 → estado 7; -3 → estado 2;
  -2 → estado 1; otro → estado 0. Solo si chan != 0 llama
  a `showMemCardError(0)`; si el byte de reintento está a 1
  y chan != 0, vuelve a probar.
- `saveGame` tras `cardProbe(0) == 1`: `CARDMount` (montaje
  -6 o -13 → `CARDCheck`; 0 → `CARDCheck`; otro → sale con
  ese resultado), `CARDGetSerialNo` (distinto de la serie
  guardada con el chequeo de identidad activo → estado 11,
  -85), `CARDOpen` (fichero «Star Fox Adventures»):
  -4 con arg 0 → camino de creación; 0 → `CARDGetStatus`
  y su chequeo exacto (pasa si `iconAddr + 0x10000 ==
  0xFFFF mod 2^32`, es decir iconAddr == `0xFFFFFFFF`,
  y lo mismo para la palabra de comentario en stat+56;
  si ambos fallan: arg 0 → -4, arg != 0 → reescritura).
  Creación: `CARDCreate(0, nombre, 24576, fileInfo)`;
  escritura: `CARDWrite(fileInfo, buf, 16384, 0)` +
  `CARDWrite(fileInfo, buf+8192, 8192, 16384)`; error -5
  en escritura → `CARDDelete`; luego `CARDGetStatus`,
  retoques de stat y `CARDSetStatus`.
- `maybeTryLoadSave` (llamado desde `loadGameOptions`):
  byte de reintento = 0; `cardShowLoadingMsg(0)` (pantalla
  de carga, bucle de 60 frames); `saveGame_prepareAndWrite`
  → `saveGame` → `cardProbe(0)`; `showMemCardError(1)`
  incondicional (retorna al instante si estado == 3, el
  que pone el callback de montaje); si el byte sigue a 1,
  repite carga + error; si 0, retorna.
- Menú del aviso (`showMemCardError`, decodificado, no
  por color TEV): estado 2 (NOCARD) y 3 → 2 opciones,
  acciones [1, 2], textos [1306, 1309, 1307]. Tabla de
  acciones (`0x8031031C` en RAM): 1 → estado 13 +
  byte de reintento = 1 («Retry»: el llamador vuelve a
  probar); 2 → limpia el byte r13-32100, estado 13,
  reintento 0 («Play (but cannot save your progress)»:
  el llamador sigue sin guardar). Selección inicial 0.
  **Corrección a la hipótesis de la tarea: el menú NO se
  mueve con D-pad.** Por frame llama a `padGetStickY(0)`
  y `padGetCY(0)` (stick Y y C-stick Y): < 0 → selección
  +1 (abajo), > 0 → -1 (arriba), con flanco (mantener
  mueve una sola vez; soltar rearma). Confirmación con A:
  `getButtonsJustPressed(0)` bit `0x100`. El bucle sale
  cuando estado == 13. El byte r13-32100 lo lee
  `TitleMenu_run`: es el propio flag «guardado activo»
  del juego.

### 2. Tarjeta virtual (HLE en la frontera SDK, sin EXI)

Ficheros nuevos `app/src/main/cpp/gamecube_runtime/card.h`
+ `card.cpp`, cableados en `hle.h`/`hle.cpp` (tabla HLE +
`SetCardPath()` + `SetCardEnabled(bool)`, este último
SOLO para pruebas host; la APK nunca lo usa) y en
`CMakeLists.txt`. Solo Slot A (canal 0); el canal 1
devuelve NOCARD como ranura vacía. El código CARD
huésped nunca corre una vez HLEadas las entradas
públicas. El callback de montaje se despacha como
código huésped (r3 = chan, r4 = resultado), seguro aquí
porque los 3 sitios de llamada pasan
`cardSetStatusNoCard2`, que solo guarda estado 3.
- Formato: Memory Card GameCube real, 59 bloques
  (4 Mbit; imagen `0x80000` B = 64 bloques × 8192 B,
  5 de sistema + 59 útiles), verificado contra YAGCD
  §12 y contra el propio código SDK del juego:
  cabecera @0x0000, directorio @0x2000, respaldo
  @0x4000, BAM @0x6000, respaldo @0x8000, datos desde
  @0xA000. Cabecera: serie 12 B @0, hora de formato 8 B
  @0xC, tamaño en Mbits u16 BE @0x22 (= 4), encoding
  u16 BE @0x24 (= 0 ASCII), resto 0xFF, contador @0x1FA,
  checksums @0x1FC/0x1FE. Directorio: 127 entradas ×
  64 B, contador @8186, checksums @8188/8190. Entrada:
  gamecode 4, maker 2, reservado 1, formato de banner 1,
  nombre 32, modtime 4, offset de imagen 4, formato de
  icono 2, velocidad 2, permisos 1, contador de copias 1,
  primer bloque 2, nº de bloques 2, reservado 2,
  palabra de comentario 4. BAM: checksum 2, inverso 2,
  contador 2, libres 2, último asignado 2, mapa (0 libre,
  cadena de siguiente bloque, 0xFFFF último).
- Checksums con el algoritmo exacto del SDK
  (`__CARDCheckSum 0x80261484`: suma de palabras u16 BE
  + suma de sus complementos, con 0xFFFF normalizado a
  0): directorio sobre 8188 B con checksum @8188,
  inverso @8190, contador @8186 (incrementado antes);
  BAM sobre 8188 B desde +4 con checksum @0, inverso
  @2, contador @4. Cobertura de cabecera ([0, 0x1FC))
  por analogía con dir/BAM: el juego nunca la verifica
  por el camino HLE; es pulido de validez externa, no
  un dato del flujo. Verificación independiente: la
  imagen creada por run48 pasa los 3 checksums
  (cabecera/dir/BAM calculados == guardados).
- Serie: generada en el formateo desde la hora de
  formato, guardada en los 12 B de cabecera;
  `CARDGetSerialNo` devuelve los 8 primeros como u64
  BE, estable entre arranques porque persiste en la
  imagen (serie idéntica en run48 y run49).
- Persistencia: si hay ruta, cada mutación
  (Create/Write/Delete/SetStatus/Format) reescribe la
  imagen completa en esa ruta. Sin ruta, la tarjeta
  vive solo en RAM. Si el fichero existe con tamaño
  incorrecto o no parsea, el HLE arranca con una
  tarjeta recién formateada en RAM, reporta el fallo
  al llamador y NO toca el fichero existente hasta la
  primera mutación válida.
- Slots estables: una entrada borrada queda como hueco
  0xFF (no se compacta), así que el fileNo (índice de
  directorio) de los demás no cambia; Create reutiliza
  un hueco antes que un slot nuevo. La longitud lógica
  es el tamaño de Create; la capacidad, bloques × 8192;
  al recargar, la longitud se reconstruye como
  bloques × 8192 (sin pérdida para este juego: 24576 =
  exactamente 3 bloques).
- Structs visibles al huésped: CARDFileInfo +0 chan,
  +4 fileNo, +8 offset (0), +12 length; CARDStat 108 B
  (nombre @0, longitud @32, hora @36, gameName @40,
  company @44, bannerFormat @46, iconAddr @48,
  iconFormat @52, iconSpeed @54, palabra de comentario
  @56, offsets @60/@64/@68/@100/@104). Los ficheros
  nuevos reportan iconAddr = `0xFFFFFFFF` y comentario
  `0xFFFFFFFF`, que es justo lo que hace pasar el
  chequeo de `CARDGetStatus` del juego. Tras recargar,
  bannerFormat/iconAddr/iconFormat/iconSpeed/comentario
  se restauran desde la entrada (bannerFormat en el
  byte 7 YAGCD); los offsets de banner/icono NO
  persisten en la entrada y vuelven como `0xFFFFFFFF`
  (limitación documentada: el juego solo lee/escribe
  +46/+48/+52/+54/+56 por este camino, así que no
  afecta a su flujo).
- Cableado APK (`native-lib.cpp`): cuando se encuentra
  `sfa-data`, se llama a
  `runtime.HleState()->SetCardPath((base +
  "/memcard-a.raw").c_str())` con la MISMA base que el
  DOL (interna preferida, almacenamiento privado que
  persiste entre arranques). Sin datos no se fija ruta
  (el juego no corre en modo demo).

### 3. Verificación host: las DOS vías superan el aviso

Test `work-port/fase2-tests/test_phase12.cpp` (+
`build_phase12.sh`): nuevos args argv[7] ruta de tarjeta
(«-» = solo RAM), argv[8] script PAD
`desde:botones:stickx:sticky` separado por comas
(botones decimales, A = 256, Start = 4096), argv[9]
tarjeta activa 1/0. El informe final vuelca contadores
CARD, `pad_reads`, estado/reintento/byte de guardado y
la lista de ficheros de la tarjeta. `SetPadScript()`
es solo host; la APK usa `SetPadState` desde Input.
Regresión: run49a (sin tarjeta, con el código nuevo)
es IDÉNTICO a run47 en todos los contadores HLE
(PADRead ×191, DVDOpen ×130, GXLoadTexObj ×5028,
OSReport ×259, …), draws 30.188 y mismo PC final
(`0x80015CF0`): cero regresión del código CARD.

- **run48 — tarjeta presente, primer arranque**
  (5.000.000 despachos, Start desde PADRead 12):
  `CARDProbeEx → 0 (mem 524288, sector 8192,
  pad_reads=72)` → `CARDMount → 0` + callback →
  `CARDCheck → 0` → `CARDGetSerialNo → 0` →
  `CARDOpen → -4` (NOFILE, primer arranque) →
  segundo intento completo: ProbeEx/Mount/Check/Serial/
  Open -4 → `CARDCreate «Star Fox Adventures» 24576
  → 0 (fileNo 0)` → `CARDWrite ×2 (16384 @0, 8192
  @16384) → 0` → `CARDGetStatus → 0` →
  `CARDSetStatus → 0` → `CARDUnmount`. Estado final
  13, reintento 0. El run terminó a mitad de la segunda
  pantalla de carga (`cardShowLoadingMsg` es un bucle
  de 60 frames; desp 4.804.848 → tope 5.000.000), NO
  atascado: PC final en `__save_fpr` (prólogo de
  render), sin excepción ni PC desconocido. Imagen
  `memcard-a.raw` exactamente 524.288 B: serie estable,
  entrada GSAP/01 «Star Fox Adventures», primer bloque
  5, 3 bloques, iconFormat 0x55, iconSpeed 0xFF
  (los OR acumulados del juego), cadena BAM 5→6→7→
  0xFFFF, 56 bloques libres.
- **run49 — segundo arranque, misma imagen**
  (8.000.000 despachos, Start 12): ProbeEx → 0, Mount
  → 0, Check → 0, Serial → 0, `CARDOpen → 0
  (fileNo 0)`, GetStatus → 0, `CARDRead ×2 (8192 @8192,
  8192 @0)`, Close, Unmount. Byte r13-32100: 255 → 1
  (el juego marca «partida presente»). Después:
  `TitleMenu_run ×44` / `TitleMenu_render ×43` por
  frame, `n_attractmode_prepareMovie` /
  `n_attractmode_releaseMovieBuffers` / `THPPlayerStop`
  (película attract parada), FIFO 30.344.120 B, draws
  23.175 con TRIANGLESTRIP 4.167 (frente a 783 del
  run47 atascado): el juego está en el bucle de título,
  no en el aviso. PC final `GXLoadTexMtxImm` (mitad de
  un render de título, normal).
- **run49a — sin tarjeta, sin script** (5.000.000,
  Start 12, tarjeta deshabilitada): ProbeEx → -3
  (NOCARD, `pad_reads=72`), estado 2, reintento 0,
  byte 255, PC final `0x80015CF0` (render de texto, el
  mismo que run47): el aviso persiste, como debe.
  No se crea ningún fichero con la tarjeta
  deshabilitada.
- **run49b — sin tarjeta + «Play sin guardar»**
  (8.000.000, Start 12, script
  `122:0:0:-80,150:0:0:0,170:256:0:0,190:0:0:0`):
  stick abajo (122) → selección 0→1; soltar (150)
  rearma el flanco; A (170) confirma la acción 2;
  soltar (190). Resultado: estado 13, reintento 0,
  **byte r13-32100 = 0** (el efecto exacto de la
  acción 2), `TitleMenu_run ×36` / render por frame
  hasta el tope, FIFO 27.395.620 B, draws 33.826 con
  TRIANGLESTRIP 3.415, PC final `GXSetVtxDesc`
  (mitad de render). La vía «Play sin guardar»
  también supera el aviso, sin tarjeta.
- Lo que NO se afirma: el menú principal con sus
  opciones visibles (el renderer host no modela color
  TEV ni resuelve todas las texturas del título desde
  el snapshot final), ni jugabilidad. Lo verificado es
  el bucle de título en marcha tras la puerta CARD, en
  ambas vías. El siguiente paso de input es navegar
  ese menú (New Game y demás) con botones táctiles /
  stick en la APK; el mecanismo de selección ya está
  medido (stick Y + A, no D-pad).

### 4. Build NDK (verificación Fase 12)

Build `ndk-out-12` (directorio nuevo, compilación
completa, no incremental): **0 errores** tras corregir
un defecto latente de la Fase 11 que los builds
incrementales habían enmascarado — en
`runtime.cpp:59` la lambda de `SetRamReader` mezclaba
retornos `const uint8_t*` y `uint8_t*`, y clang la
rechaza por tipo de retorno deducido inconsistente
(2 errores). Fix mínimo sin cambio de comportamiento:
cast a `const uint8_t*` en el último retorno. El
build incremental de la Fase 11 había reutilizado un
`runtime.o` anterior al lambda, así que el defecto no
se vio entonces; el build completo de esta fase lo
expuso y quedó corregido. `libstarfox.so`
**27.417.392 B**, ELF64 AArch64, SHA-256
`553f3cc330ceecec86a118563292c1a2accfb86dd9d9d61bf70eb9c230abce80`,
`android_main` en `T`, comprobación del script «OK:
ningún símbolo mem_/ppc_/func_/dolrecomp_ sin
resolver», **189 undefined totales** (frente a 186 en
Fase 11; delta +3 coherente con el nuevo uso de stdio
de `card.cpp` — fopen/fread/fwrite/fseek/ftell —, todos
de librerías del sistema: AAudio, AConfiguration,
AInput, libc, libm, sin ningún símbolo de shim/chunk).

### 5. APK de prueba GX12 (verificación Fase 12)

`android-port-base/app-debug-gx12-test.apk`:
**12.538.534 B**, SHA-256
`7587eb34aded00bc749b063a8e7acee48ec047b09b1257d1df244ef698406795`,
`com.starfox.port` v4 / `0.4.0-gx12-test`,
debuggable solo por ser build de prueba, solo
arm64-v8a. Validación: apksigner v2+v3 OK (1 firmante),
zipalign OK, badging (sdk 26, target 34, MainActivity
lanzable), `libstarfox.so` interior con SHA idéntico
al del build NDK (`553f3cc3…`), sin datos ni disco
dentro (solo dex, `libc++_shared.so`, `libstarfox.so`,
manifiesto y `assets/README.md`). Hace (por código,
NO probado en dispositivo): todo lo de GX11 (arranca,
EGL/GLES3 + programa GX, clear + damero sin datos;
con `sfa-data` por adb, carga el DOL, avanza tras
videoInit y dibuja frames del bucle real) MÁS la
tarjeta virtual CARD: con datos, `memcard-a.raw` se
crea en la misma base que el DOL y la partida persiste
entre arranques (crear/leer verificados en host, no
en dispositivo). NO hace: no es jugable, sin sonido
de juego, sin botones táctiles, sin picker SAF, sin
probar en Tab S8 real.

### 6. Qué queda (tras Fase 12, en orden)

1. ~~Picker SAF + copia de Pack B a `sfa-data/`~~ HECHO
   en Fase 13 (código + verificación host; falta la
   prueba real en Tab S8 con datos: boot.log + frames
   reales. La tarjeta virtual ya tiene ruta privada
   fijada, así que en cuanto la APK corra con datos, la
   partida persistirá entre arranques).
2. ~~Botones táctiles en pantalla (layout por definir)~~
   HECHO en Fase 13 (layout definido y documentado,
   verificado en host contra run49b; falta probarlo
   tocando la pantalla real en Tab S8). El menú del
   aviso necesita stick Y + A (no D-pad), y el de
   título, por medir.
3. Contenido DL en APK con RAM viva (cableado; falta
   probarlo con datos).
4. TEV multi-etapa / color de selección / alfa I4 en el
   renderer (texto y selección correctos).
5. Mapeo ID de sonido del juego -> WAV; secuencias
   MusyX; DSP real.
6. Rumble (`PADControlMotor` sin HLE).
7. APK 100% jugable: solo cuando renderer + datos +
   CARD/input + audio estén probados en dispositivo.
   La APK de este tramo sigue siendo solo prueba de
   renderer + CARD (ver punto 5).

## Fase 13 (este tramo): picker SAF + botones táctiles

Dos frentes que bloqueaban usar la APK sin adb y sin
mando. Ninguno toca el juego, el HLE CARD ni los chunks:
el picker es Java + un cable JNI mínimo, y el táctil es
una reescritura del camino de toque de `Input` sobre un
layout explícito. `main` intacto (18ac28e); todo en
`android-port-base`.

### 1. Picker SAF + copia de Pack B

Problema: NativeActivity no tiene UI Java (toda la
pantalla es la ventana nativa), así que no hay un botón
donde colgar un picker. Vía elegida, documentada porque
es la decisión que condiciona el resto: el código
nativo detecta la falta de datos en `INIT_WINDOW` y
llama por JNI a `MainActivity.requestDataFolder()`;
Java lanza el Intent en el hilo UI (`runOnUiThread`,
porque `startActivityForResult` desde el hilo nativo
no es seguro) y `onActivityResult` copia en un hilo de
fondo (una copia de ~240 MB no puede bloquear la UI).
Ficheros: `app/src/main/java/com/starfox/port/
MainActivity.java` (picker + copia + verificación +
`boot.log`), `native-lib.cpp` (detección, JNI,
sondeo del marcador).

Flujo exacto:
1. Primer arranque sin `sfa-data`: la app abre el
   picker de carpetas (`ACTION_OPEN_DOCUMENT_TREE`
   con permiso de lectura persistente). El usuario
   elige la carpeta de datos (Drive → Descargas →
   carpeta con `sys/main.dol` + `files/`): se copian
   los HIJOS de la carpeta elegida a `sfa-data/`
   (elegir la carpeta padre copiaría una carpeta de
   más y la verificación fallaría con «FALTA
   sys/main.dol», registrado en `boot.log`).
2. Destino: `<base>/sfa-data/`, interna preferida, la
   MISMA base que usa `native-lib` para el DOL y para
   `SetCardPath(.../memcard-a.raw)`; externa solo si
   no hay interna. Sin esta coincidencia, la tarjeta
   y los datos vivirían en bases distintas.
3. Progreso en `boot.log` (mismo fichero que el log
   nativo, carpeta interna, abierto en append desde
   Java) cada 250 ficheros, más logcat.
4. Verificación final, sin ambigüedad:
   - `sys/main.dol` presente, tamaño 3.405.600 B,
     SHA-1 `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`
     (calculado en streaming, no cargado en RAM).
   - `files/` con al menos 2.916 ficheros (Pack B =
     `disc/files/` sin `streams/`: 2.916 ficheros,
     239.678.460 B, contados en el árbol local).
     Si el conteo es mayor (el usuario eligió
     `files/` completo, con `streams/`: 3.874), se
     registra como aviso, no como error: los
     ficheros extra no estorban al juego. Si es
     menor o el DOL no coincide, verificación
     FALLIDA: no se escribe el marcador de éxito.
5. Éxito → `<base>/sfa-data/.saf-copy-done` con el
   resumen; el bucle nativo lo sondea cada 128
   vueltas sin juego cargado y llama a `TryLoadData`
   (la carga que antes solo ocurría en `INIT_WINDOW`
   ahora es una función reutilizable). Fallo →
   `.saf-copy-error` con la causa. Cancelación del
   picker → registrado en `boot.log`, sin reintento
   en esta ejecución (evita un bucle de pickers).
   En los tres casos sin datos, la app sigue en
   clear + quad de prueba: nunca falla por falta de
   datos.
6. NUNCA se meten datos ni disco en Git ni en la
   APK: la copia sale siempre de la carpeta del
   usuario. La APK GX13 solo lleva dex, libs,
   manifiesto y `assets/README.md` (ver punto 5).

Corrección real encontrada en esta fase (no
cosmética): el sondeo SAF NO puede usar
`IsRunning()` como guarda — `Init()` lo pone a true
aunque no haya juego (el stub de la base también
«corre») —, así que usa `IsGameLoaded()`. Con
`IsRunning()` el marcador `.saf-copy-done` nunca se
habría detectado y el juego no habría cargado tras
la copia. Queda documentado aquí para que nadie lo
«simplifique» de vuelta.

Errores que registra `boot.log` (qué falta, exacto):
«FALTA sys/main.dol», «main.dol NO coincide»
(tamaño/SHA-1 esperados incluidos), «files/
INCOMPLETO: faltan al menos N ficheros», «copia
FALLO: <causa>», «picker cancelado». Una copia
parcial de un intento cancelado se sobrescribe en
el siguiente intento (mismos nombres de fichero);
no hay limpieza de ficheros huérfanos de un Pack
distinto — limitación honesta, sin efecto para el
flujo normal (misma carpeta de origen).

### 2. Botones táctiles: layout DEFINIDO

Fichero nuevo `app/src/main/cpp/input/touch_layout.h`
(sin dependencias Android: solo fracciones + PadState,
compartido entre la APK y las pruebas host) y
reescritura del camino táctil de `input/input.cpp` /
`input.h` sobre él. El tamaño de ventana lo fija
`native-lib` en `INIT_WINDOW` con
`ANativeWindow_getWidth/Height` (`SetViewportSize`);
sin tamaño, los toques se ignoran y se registra en
`boot.log` (sin tamaño no se puede clasificar una
zona en fracciones; inventar un tamaño por defecto
habría puesto los botones en sitios falsos).

Fracciones de pantalla (origen arriba-izquierda, x
a la derecha, y hacia abajo; paisaje). Distancias en
«unidades de alto» (dx × aspecto) para que un
círculo táctil sea un círculo en píxeles en 16:9:
radio de botón 0,09 (~65 px a 720p), stick con
aceptación 0,20 y recorrido 0,18 (~130 px).

Diagrama (zonas, centros y qué botón es cada zona;
el dibujo NO está a escala, las fracciones sí son
las reales):

```
+----------------------------------------------------------+
| [L] (0.055,0.12)    [Start] (0.50,0.10)   [R] (0.945,0.12)|
|                                                          |
|  (o) STICK                                                |
|  centro (0.13,0.72)        ( ) C-STICK     [X] (0.845,   |
|  aceptacion 0.20            RESERVADO        0.58)      |
|  recorrido 0.18             (0.62,0.70)  [Y] (0.785,0.70) |
|  zona x 0.01-0.25, y 0.42-0.98  SIN MAPEO  [A] (0.905,   |
|                                                          |
|  D-pad: Up (0.255,0.58)                     0.70)        |
|  Left (0.195,0.70) Right (0.315,0.70)  [B] (0.845,0.82)   |
|  Down (0.255,0.82)     [Z] (0.72,0.55)                    |
+----------------------------------------------------------+
```

Mapeo (bits PAD, ver `pad_state.h`):
- Stick virtual: arrastre desde el apoyo; abajo en
  pantalla → stick_y negativo (GC: abajo = −127).
  ES el control de menús: el aviso y (por lo medido
  en Fase 12) el menú de título se mueven con stick
  Y (`padGetStickY`), NO con D-pad.
- A (0.905,0.70) = 0x0100, B (0.845,0.82) = 0x0200,
  X (0.845,0.58) = 0x0400, Y (0.785,0.70) = 0x0800:
  rombo alrededor de (0.845,0.70).
- Z (0.72,0.55) = 0x0010, L (0.055,0.12) = 0x0040 +
  gatillo 255, R (0.945,0.12) = 0x0020 + gatillo 255,
  Start (0.50,0.10) = 0x1000.
- D-pad: Up (0.255,0.58) = 0x0008, Down (0.255,0.82)
  = 0x0004, Left (0.195,0.70) = 0x0001, Right
  (0.315,0.70) = 0x0002. Existe para el juego, pero
  NO mueve el aviso (medido Fase 12).
- C-stick: zona reservada en (0.62,0.70), radio 0,20,
  SIN MAPEO en esta fase (sub-stick queda a 0, como
  en todas las fases previas). Los toques ahí se
  ignoran a propósito: mapearlo a medias (sin zona
  muerta ni escala medidas) sería peor que
  reservarlo. Queda documentado, no olvidado.
- Prioridad en Down: botones, luego stick, luego
  C-stick reservado (ignorado), luego exterior
  (ignorado). Cambio deliberado frente a antes: un
  toque fuera de zona YA NO mueve el stick (antes
  cualquier primer dedo era stick en toda la
  pantalla, y un toque accidental en el centro
  habría movido el menú).
- Multitáctil por pointer id: cada dedo es un botón
  o el stick (un solo stick); MOVE recorre todos los
  dedos (un MOVE Android trae todas las posiciones).
- Flanco JustPressed: TouchLayout solo escribe Held
  en PadState. Just = Held & ~Prev lo calcula
  `padUpdate` en el juego (0x80014F6C), igual que
  para mando/teclado: NO hay poke directo de Just.
  Soltar el stick vuelve stick a 0, lo que rearma
  el flanco de stick Y para el siguiente toque (el
  aviso exige soltar entre movimientos: mantener
  mueve una sola vez).

### 3. Verificación host: la secuencia táctil supera el aviso

Test `work-port/fase2-tests/test_touch13.cpp` (fuera
del repo, como los demás tests host; alimenta
fracciones directamente a `TouchLayout`, sin
Android): TODO OK, 28 comprobaciones. La secuencia
del aviso — apoyo en (0.13,0.72), arrastre a
(0.13,0.834), soltar, A en (0.905,0.70), soltar —
produce EXACTAMENTE los valores PAD del guion
run49b: stick (0,−80), soltar → (0,0), Held A =
0x100 con analogA 255, soltar → 0. También probado:
stick en juego en diagonal (+80,+79), multitáctil
A+B con suelta independiente, D-pad/Z/L/R/Start,
C-stick reservado ignorado con sub-stick a 0, y
toque fuera de zona ignorado (antes era stick).

Run de juego equivalente, `run50-ph13touch`
(8.000.000 despachos, Start desde PADRead 12, sin
tarjeta, guion `122:0:0:-80,150:0:0:0,170:256:0:0,
190:0:0:0` — los valores que emite la prueba
táctil, con los instantes de run49b, que los pone
el usuario al tocar, no el layout): REPRODUCE
run49b en TODAS las métricas de `stdout.log`:
motivo `dispatch_cap`, PC final `0x80257320`
(idéntico), FIFO 27.395.620 B (idéntico, overflow
0), PADRead ×197, `CARDProbeEx → −3` (NOCARD),
`cardStatus = 13`, `saveByte = 0` (el efecto exacto
de la acción 2, «Play sin guardar»), sin exception
ni PC desconocido. El código HLE/CARD no cambió en
esta fase, así que la identidad con run49b es lo
esperado y lo que se quería demostrar: cero
regresión, y el camino táctil llega al mismo
efecto que el guion de teclado/mando. (El conteo
`TitleMenu_run ×36` de run49b no se reproduce desde
`stdout.log` — ese conteo vino de un análisis
posterior del coordinador, no de una línea del
informe del test —; la equivalencia aquí se
establece con estado/byte/FIFO/PC, que sí están en
el informe.)

### 4. Build NDK (verificación Fase 13)

Build `ndk-fase13` (directorio nuevo, compilación
completa): **0 errores**. `libstarfox.so`
**27.426.080 B**, ELF64 AArch64, SHA-256
`f41d5c3953de6f0c7446cce498961821735a7e21e597af5a2a361398edbe0db4`,
`android_main` en `T`, comprobación del script «OK:
ningún símbolo mem_/ppc_/func_/dolrecomp_ sin
resolver», **191 undefined totales** (frente a 189
en Fase 12; delta +2 exactamente
`ANativeWindow_getWidth`/`ANativeWindow_getHeight`
de `native-lib.cpp`, ambos en libandroid, que ya
está enlazada con `-landroid`). Compilación
aislada previa de `input.cpp` y `native-lib.cpp`
con el NDK también limpia (para no esperar al
final de los chunks ante un error de sintaxis).

### 5. APK de prueba GX13 (verificación Fase 13)

`android-port-base/app-debug-gx13-test.apk`:
**12.554.918 B**, SHA-256
`aeb9f3b253a1b43fe88c4d107961a9356b64837628f94b9bd022b73a3b77d633`,
`com.starfox.port` v5 / `0.5.0-gx13-test`,
debuggable solo por ser build de prueba, solo
arm64-v8a. Validación: apksigner v2+v3 OK (1
firmante), zipalign OK, badging (sdk 26, target 34,
MainActivity lanzable), `libstarfox.so` interior con
SHA idéntico al del build NDK (`f41d5c39…`), sin
datos ni disco dentro (solo dex, `libc++_shared.so`,
`libstarfox.so`, manifiesto y `assets/README.md`).
El dex contiene `requestDataFolder` /
`onActivityResult` / `.saf-copy-done` (verificado
por strings). Hace (por código, NO probado en
dispositivo): todo lo de GX12 (arranca, EGL/GLES3 +
programa GX, clear + damero sin datos; con
`sfa-data`, carga el DOL, tarjeta virtual
persistente) MÁS picker SAF con copia y
verificación de Pack B, y botones táctiles con el
layout de arriba. NO hace: no es jugable, sin
sonido de juego, sin probar en Tab S8 real (ni el
picker ni el táctil han tocado una pantalla real).

Corrección del script de APK en esta fase:
`build-apk-manual.sh` pasaba solo
`MainActivity.class` a d8; con la clase anidada
`CopyStats` de la copia SAF, d8 rompe («requires
its nest mates»). Ahora pasa todas las clases de
`classes/` (ver el script). Sin este fix no hay
APK GX13; no cambia el resultado para APKs
anteriores (MainActivity no tenía anidadas).

### 6. Qué queda (tras Fase 13, en orden)

1. Prueba real en Tab S8 (bloqueador de
   verificación, no de código): instalar GX13,
   primer arranque sin datos → picker → elegir la
   carpeta Pack B → comprobar en `boot.log` la
   copia (2.916 ficheros), la verificación
   (main.dol + SHA-1) y la carga; después, recorrer
   el aviso con el stick táctil + A y comprobar que
   llega al bucle de título. Hasta que eso no pase
   en dispositivo, picker y táctil son «código
   verificado en host», no «probado».
2. Sonido: mapeo ID de sonido del juego → WAV;
   secuencias MusyX; DSP real. (El backend AAudio /
   WAV existe desde Fase 7; falta el contenido.)
3. TEV multi-etapa / color de selección / alfa I4
   en el renderer (texto y selección correctos en
   el menú de título).
4. Contenido DL en APK con RAM viva (cableado;
   falta probarlo con datos).
5. Rumble (`PADControlMotor` sin HLE).
6. APK 100% jugable: solo cuando renderer + datos +
   CARD/input + audio estén probados en
   dispositivo. La APK de este tramo sigue siendo
   solo prueba de renderer + CARD + SAF + táctil
   (ver punto 5).

## Fase 14 (este tramo): traza de audio + mapeo ID → WAV + bridge

Trabajo en `android-port-base` solo; `main` intacto en
`18ac28e`. Tests host fuera del repo
(`work-port/fase2-tests/test_phase14*.cpp`,
`build_phase14*.sh`): la réplica exacta de run50
(8.000.000 despachos, Start desde PADRead 12, sin
tarjeta, guion `122:0:0:-80,150:0:0:0,170:256:0:0,
190:0:0:0`) es run51; el run con bridge es run52.

### 1. Traza de audio del juego (run51, sin regresión)

`chassis.cpp`: `PCTRACE` (solo con `SFA_PCTRACE`, solo
host en la práctica) ampliada con 19 entradas de audio
(direcciones verificadas en `codigo/symbols.map`) y con
r3–r7 al final de la línea (el `pc=0x...` queda intacto
para el parseo anterior). Limitación documentada: solo
se ven entradas ENTRE chunks; una llamada dentro del
mismo chunk es un goto y no aparece (por eso
`audioLoadTriggerData`, en el mismo chunk que
`audioInit`, no sale en PCTRACE aunque corre: lo
prueba el `bl` de `audioInit` en 0x80009DA4 y los 3
`DVDOpen` con retorno en `loadFileByPathAsync`).

run51 reproduce run50 en TODAS las métricas:
`dispatch_cap`, 8.000.000 despachos, PC final
`0x80257320`, exception 0, HLE 28.249, PADRead ×197,
DVDOpen ×133, FIFO 27.395.620 B (overflow 0),
`cardStatus = 13`, `saveByte = 0`, `TitleMenu_run`
×36. La traza nueva no cambia el juego.

Llamadas de audio trazadas en la ventana attract /
transición Start / carga-aviso CARD / bucle de título
(entre paréntesis, despacho y llamador):

- `audioInit` 0x80009BF8 ×1 (desp 6.774, desde
  `init`).
- `sndVolume` 0x802732E0 ×1 (r3=127, r4=0, r5=255,
  desde `audioInit`).
- `sndMasterVolume` 0x80273340 ×1 en init (r3=127,
  r4=100, r5=1, r6=1, r7=-1) y ×31 más en título
  (desde `CameraModeTitle_update` 0x80111D2C, r3 =
  0,1,2,3,5,6,7… creciente, r4=10, r5=1): 32 en total.
- `AudioStream_Init` 0x8000D5B4 ×1 (r3=-1, r4=-1).
- `sndPushGroup` 0x8027C09C ×56 (desde `audioInit`:
  r4 = 0 una vez y 1–55 en bucle; grupos MusyX 0–55
  cargados en init).
- `audioSetVolumes` 0x80009A28 ×32 (las mismas 32
  llamadas de título que `sndMasterVolume`).
- `AudioStream_StopCurrent` 0x8000D03C ×1 (desp
  2.049.289, desde `audioStopByMask` 0x80009B00,
  antes de la película attract).
- `AttractMovieAudio_Init` 0x80119848 ×4 (audio THP
  de la película, no MusyX; r3=2).
- `audioUpdate` 0x80009BD0 ×36 (una por frame de
  título, desde `gameLoop`).
- `AudioStream_Play` 0x8000D220 ×2 (desp 2.354.011 y
  2.354.497, r3=1367, r4=`ObjSeq_AudioStreamCallback`
  0x800806F0, lr en `ObjSeq_start` 0x80081B70):
  EL ÚNICO sonido por stream pedido en la ventana.
- NINGUNA en la ventana: `sndFXStartEx`,
  `sndSeqPlayEx`, `AudioStream_StartPrepared`,
  `AudioStream_GetCurrentId`, `ObjSeq_AudioStreamCallback`
  como entrada. El clic A del aviso CARD y la
  navegación del título no disparan SFX por estas
  entradas en esta ventana.
- Ficheros DVD de audio: los 12 de init
  (`Music.bin`, `Sfx.bin`, `Streams.bin`,
  `starfoxm/s.poo/pro/sdi/sam`, `starfoxs/...`,
  `midi.wad`; los 12 callbacks `*LoadedCallback`
  despachados por el HLE, flags de carga
  `0xFFF`). NINGÚN `streams/*.adp` abierto en la
  ventana.
- Globales finales de audio: `ready=1`,
  `musicGrp=1`, `sfxGrp=1`, `streamPlaying=0`,
  `streamCurrentId=0`, `streamPreparingId=0`,
  `streamPreparedId=0`, volL=volR=127, `sndActive=1`.

### 2. El stream 1367 no resuelve (dos causas independientes)

(a) 1367 NO existe en `Streams.bin`: búsqueda
exhaustiva (905 registros; IDs vecinos 1361 y 1368;
el BE16 1367 no aparece en todo el fichero). Con el
directorio funcionando, `AudioStream_Play` lo
buscaría por comparación directa del u16 inicial
(verificado en el código huésped) y devolvería 0
igual. (b) En host, además, el directorio está
vacío: `dir_ptr` 0x803DE210 = 0 y `count`
0x803DE214 = 0 al final de run50, run51 y run52.
Verificado con un run de parada en el retorno de
la primera llamada (`pc=0x80081B70`): retorno de
`AudioStream_Play` = 0, `streamCurrentId` = 0.

Causa raíz del directorio vacío (cadena completa,
verificada en código huésped + HLE, no supuesta):

1. `audioLoadTriggerData` 0x8000980C carga
   `Music.bin`/`Sfx.bin`/`Streams.bin` con
   `loadFileByPathAsync` 0x8001599C y guarda
   `dir_ptr` = retorno y `count` = tamaño/22
   (magia de división `0xBA2E8BA3`; 19.920/22 =
   905). `Sfx.bin` SÍ queda bien (ptr
   0x8101D0C0, 1.205 registros): su callback
   devuelve un flags no nulo.
2. `streamsLoadedCallback` 0x80009594, en cambio,
   devuelve el contador ANTES de guardar (0 en
   host, porque el callback corre durante la
   carga, no después): su camino de éxito termina
   con r3 = `[count]` = 0.
3. El HLE entrega el callback DVD como despacho
   nuevo con lr intacto, así que su `blr` vuelve
   a `loadFileByPathAsync` (0x80015AA4) con r3 =
   retorno del callback (0), no con el estado de
   `DVDReadAsyncPrio`. `loadFileByPathAsync`
   toma el camino de fallo (libera búfer y
   fileInfo, devuelve 0) y `audioLoadTriggerData`
   guarda `dir_ptr` = 0, `count` = 0.
4. En hardware real el callback es asíncrono:
   `loadFileByPathAsync` devuelve búfer + tamaño
   al instante, `audioLoadTriggerData` guarda
   dir/count, y el callback posterior ya los ve
   poblados. El fallo es de fidelidad del HLE
   host, no del juego ni de la tabla.

Siguiente paso concreto (NO hecho aquí, para no
tocar la maquinaria de callbacks que usan los
wrappers de romlists): un trampolín HLE que, al
volver un callback de carga, restaure r3 = bytes
leídos antes de saltar al retorno original, de
modo que `loadFileByPathAsync` vea éxito aunque
el callback devuelva 0. Hasta entonces, ningún
stream pedido por el juego sonará en host aunque
la tabla sea correcta.

Detalle abierto (no portador): las palabras de
`Music.bin` terminan en (0x32, 2) aunque su único
escritor estático es `audioLoadTriggerData`; se
deja constancia sin atribuirlo (podría ser reuso
por bytes de otra inicialización de música, no
verificado).

### 3. Formato de las tablas (leído, no supuesto)

`Streams.bin` (19.920 B): 905 registros × 22 B =
`[id u16 BE][campo u16 BE][lengthRaw u16 BE]
[nombre 16 B]` + 10 B de cola a cero. 830 con
nombre (784 únicos; 29 nombres repetidos con
distinto id, p. ej. `KP/getspirit` ×5: mismo WAV,
distinto punto de fundido `lengthRaw/100`).
`lengthRaw` = 0 en 880 registros, distinto de
cero en 25 (p. ej. `GB/Intro` 7.200, `AN/an1301`
2.400): punto de fundido, NO duración (coherente
con el RESUMEN de extracción). Ids especiales en
`AudioStream_Play`: 1228 = retorno 0 inmediato,
1318 = dos llamadas de alloc antes de seguir.

`Sfx.bin` (38.560 B): 1.205 registros × 32 B =
`[id u16 BE][volBase u8][0][pitchBase u8][0]
[? u16][? u16][muestra0..3 u16]...`. Los 4
campos de muestra están en 0..832 (817 distintos;
solo 3 triggers superan 827: 828–832, las
primeras muestras sin nombre de `starfoxs`).
Interpretación documentada: 0 = sin muestra (247
triggers con los 4 campos a 0; si 0 fuese una
muestra real, 247 triggers sonarían igual).
`volBase` típico 100, `pitchBase` 127 en 1.199.

`Music.bin` (2.544 B): triggers de música (sin
semántica decodificada en este tramo); sin petición
de reproducción trazada en la ventana.

Generador: `herramientas/audio/gen_audio_id_map.py`
(lee disco + `analisis/audio.csv`, escribe
`app/src/main/cpp/audio/audio_id_map.h` y
`herramientas/audio/audio_id_map.csv`). Empareja
insensible a mayúsculas (`GB/bird` frente a
`GB/Bird.adp`) y por prefijo único si el nombre
está truncado a 15 caracteres.

Tabla resultante:

| Concepto | Resueltos | Sin resolver |
|---|---|---|
| Streams (id → WAV ADP 32 kHz estéreo) | 820/830 | 10: `WC/wc970` (970), `IM/arrive` (20511), `WC/wc09b–wc09h` (20946–20951, 20958) y `unknown` (20959): sin `.adp` en el disco |
| Triggers SFX (id → muestras) | 1.205/1.205 (todas sus muestras en inventario) | 0 (247 sin muestra directa: secuencia/grupo) |
| Muestras MusyX (id → WAV mono) | 1.472/1.472 (0–1471) | 0 |
| ADP con WAV pero sin id de tabla | — | 185 ficheros (TTH 121, COMM 48, resto 16): no referenciables por `AudioStream_Play` |

El stream pedido en la ventana, 1367, queda en
«sin resolver» por la causa doble del punto 2.
Ningún ID pedido se mapea a un sonido inventado.

### 4. Bridge conectado al backend (sin cambiar el loop)

Ficheros nuevos en el repo: `app/src/main/cpp/audio/
audio_bridge.{h,cpp}` (+ `audio_id_map.h`
generado) y el hook opcional en
`gamecube_runtime/chassis.{h,cpp}` (5 PCs:
`AudioStream_Play`, `AudioStream_StopCurrent`,
`AudioStream_StartPrepared`, `sndFXStartEx`,
`sndSeqPlayEx`; con hook nulo, coste cero).
El hook se dispara ANTES del despacho y el código
huésped corre íntegro después: sonido sombra,
estado del juego intacto. `GameCubeRuntime`
posee el bridge (`SetAudioWavRoot`,
`Tick()` antes de `Audio::Pump()` por frame) y
`native-lib` le pasa `<base>/sfa-data/audio`.
Sin esa carpeta (Pack B actual, sin WAV), el
bridge es inerte: búsquedas fallidas → no
resuelto, sin ficheros, sin cambios en el juego.

Reglas del bridge, deliberadas: solo reproduce
`AudioStream_Play` (r3 = id, verificado) y
detiene en `AudioStream_StopCurrent`; las demás
entradas solo se cuentan (su layout de
argumentos no está verificado; `sndFXStartEx` /
`sndSeqPlayEx` no se inventan). Una sola cola
en orden de llegada (sin mezcla: un stream y un
SFX a la vez sonarían en serie), WAV de una sola
pasada (sin bucles, como en la extracción),
alimentación de 4.096 frames por `Tick()`.
`OnSfxTrigger(id)` es API directa (misma que
usará el hook cuando el layout de `sndFXStartEx`
se verifique).

### 5. Verificación host (run52, sin regresión)

Run52 = run51 + hook + bridge (root = repo
`assets/extraidos/audio`): motivo `dispatch_cap`,
PC final `0x80257320`, HLE 28.249, PADRead ×197,
FIFO 27.395.620 B, `cardStatus = 13`, audio
final idéntico a run51. (Tiempo 39,9 s frente a
27,9 s de run51: varianza de host, no regresión
de estado — el hook son 5 comparaciones por
despacho y 3 llamadas en todo el run.)

Hook durante el juego: 3 entradas exactas —
`StopCurrent` ×1 (r3 = 0x80330000) y
`Play(1367)` ×2, ambas no resueltas, 0
reproducidas por el juego. Verificación directa
de la cadena (mismo código, IDs reales de tabla):

- Stream 1301 (`streams/AN/an1301.wav`, 32.000 Hz
  estéreo) → 1.892.352 frames a 48 kHz
  (exactamente el número de Fase 7),
  submitted = delivered = 1.892.352, dropped = 0.
- Trigger SFX 1 → 4 muestras (420
  `SFXmenu_fend_name`, 421 `SFXmenu_pause_hliteup`,
  422 `SFXmenu_pause_hlitedown`, 423
  `SFXfoot_dirt_walk_1`, 22.050 Hz mono) →
  11.450 + 15.351 + 52.697 + 25.499 = 104.997
  frames, submitted = delivered, dropped = 0.
- Trigger 45 → 0 muestras (sin muestra directa),
  no resuelto. Stream 970 → no resuelto.
- Totales del test: submitted = delivered =
  1.997.349, dropped = 0.

Test host `run21-unit` de Fase 7 (WAV previos)
sigue cubierto por la misma ruta (`LoadWavFile`
+ `ResampleToStereo` sin tocar; el 1301 del
bridge reproduce su número exacto).

### 6. Build NDK y APK de prueba GX14

Build `ndk-fase14` (incremental desde
`ndk-fase13`): **0 errores**. `libstarfox.so`
**27.616.232 B**, ELF64 AArch64, SHA-256
`886f41fa2642e4309ef8e4eb569f7bdd4f01c56ae3151b1d3d51f69692bdafe2`,
`android_main` en `T`, símbolos `AudioBridge::*`
en `T`, **cero** `mem_/ppc_/func_/dolrecomp_` sin
resolver (191 undefined totales, solo libs del
sistema). APK de prueba `app-debug-gx14-test.apk`
(**12.599.974 B**, SHA-256
`9f4af993be0e0f3f4a0d7b42ef78f0aab11a1d175607877fe0f029b75e8f95d9`,
`com.starfox.port` v6 / `0.6.0-gx14-test`):
apksigner Verifies (v2+v3, 1 firmante), zipalign
OK, manifiesto minSdk 26 / arm64-v8a /
debuggable, `libstarfox.so` interior con el
mismo SHA-256 que el build NDK, sin datos del
juego dentro. Etiqueta: PRUEBA, nunca jugable
sin juego completo; el bridge está cableado
pero inerte sin `sfa-data/audio`. Nota de
entorno: el JDK había desaparecido por el wipe
de VM; se extrajo OpenJDK 21.0.12.1 a
`~/tools/jdk21` (persiste, a diferencia de
`/usr`) y la APK se construyó con él.

### 7. MusyX/DSP: qué pide el juego y qué falta

En la ventana trazada, el juego NO pide ninguna
secuencia: ni `sndSeqPlayEx` ni `sndFXStartEx`.
Lo que sí hace: cargar los bancos completos
(`.pro`/`.poo`/`.sdi`/`.sam` ×2, `midi.wad`;
flags `0xFFF`) y 56 `sndPushGroup` (grupos
0–55). El audio de la película attract NO es
MusyX: es la pista THP (`AttractMovieAudio_*`,
decodificación y mezcla propias, ya en el
juego). Falta para música/SFX MusyX, en orden:

1. Trampolín HLE del punto 2 (prerrequisito
   para cualquier stream del juego en host).
2. Layout de argumentos de `sndFXStartEx` y
   `sndSeqPlayEx` (qué registro lleva el id de
   trigger/secuencia) para cablear el hook a
   `OnSfxTrigger` y al reproductor de secuencias.
3. Semántica de secuencias: `.pro` (proyecto),
   `.poo` (SoundMacros) y `midi.wad`
   (1.273.280 B, sin `MThd`, sin parse de eventos
   establecido): qué macro/secuencia corresponde
   a cada trigger y cómo avanza en el tiempo.
4. DSP real: hoy solo el evento de init
   (`dspInitCallback`); faltan la ejecución de
   tareas DSP (`salBuildCommandList` y
   siguientes), la mezcla de voces y el modelo
   ARAM (las muestras viven en ARAM tras
   `AudioAramWriteSync`, sin modelo en host).
   Sin esto, cualquier «música» sería un stub
   que suena mal presentado como música: no se
   hace. El WAV por muestra ya existe (1.472) y
   es el material sobre el que se construirá.

### 8. Qué queda (tras Fase 14, en orden)

1. ~~Trampolín HLE de callbacks de carga (punto 2)
   + re-verificar `AudioStream_Play` con un id
   válido (p. ej. 1301) desde el juego, no solo
   desde el test directo.~~ **HECHO en Fase 15**
   (ver abajo).
2. Layout de `sndFXStartEx`/`sndSeqPlayEx` y
   primer SFX real del juego por el bridge.
3. Secuencias MusyX + DSP (punto 7), mezcla de
   voces, bucles de muestra.
4. Payload de audio WAV en Pack B
   (`sfa-data/audio` con `streams/` y `musyx/`)
   o decodificación ADP/DSP-ADPCM en el
   dispositivo; sin eso la APK GX14 no suena
   aunque el código esté cableado.
5. Prueba real en Tab S8 (GX14: picker SAF +
   táctil + CARD + bridge inerte) y, cuando haya
   payload, primera escucha real.
6. TEV multi-etapa, rumble y APK 100% jugable
   (sin cambios en esta fase; ver «Fase 13»,
   punto 6).

## Fase 15 (este tramo): trampolín HLE de callbacks DVD + primer stream válido por el camino del juego

Trabajo en `android-port-base` solo; `main` intacto en
`18ac28e`. Tests host fuera del repo
(`work-port/fase2-tests/test_phase15.cpp`,
`build_phase15.sh`): réplica exacta de run51
(8.000.000 despachos, Start desde PADRead 12, sin
tarjeta, guion `122:0:0:-80,150:0:0:0,170:256:0:0,
190:0:0:0`) es run53 (base pre-trampolín), run54
(trampolín) y run57 (trampolín + bridge); run54-stop
y run55/run56 paran en el retorno del primer
`AudioStream_Play` (0x80081B70) y re-despachan el
código huésped de `Play` con 1301 (ver punto 3).

### 1. El trampolín (semántica, alcance, riesgos)

Ficheros: `app/src/main/cpp/gamecube_runtime/hle.{h,cpp}`
solo; código huésped intacto, sin cambios en
`audio/*`, `chassis.*` ni en los wrappers del juego.
PC sintético nuevo `kDvdCallbackTrampoline` =
0x80003008 (vecino del trampolín VI 0x80003000 y
de la salida de hilo 0x80003004; el DOL empieza en
0x80003100, así que nunca es código real, y
`dolrecomp_call` consulta `host_call` antes que los
chunks, así que el HLE lo intercepta siempre).

Semántica exacta, en dos tiempos:

1. `DVDReadAsyncPrio` con callback != 0: lee en
   síncrono como antes, registra el evento, pone
   r3 = bytes y r4 = fileInfo para el callback...
   pero pone lr = 0x80003008 (antes, lr = retorno
   del llamador) y apila un marco
   `{retorno_original, r3_a_restaurar, fileInfo,
   callback}`. El callback corre íntegro como
   código huésped (cierra el fichero, baja
   contadores, escribe su global) sin saber que su
   lr es sintético: su prólogo/epílogo guardan y
   restauran lr por pila, como cualquier función.
2. Al hacer blr, el callback aterriza en el
   trampolín: el HLE desapila (LIFO), pone
   r3 = bytes leídos, pc = retorno original y
   lr = retorno original, y devuelve el control.
   Invariante: al reanudar el llamador, TODO está
   como si el callback hubiese vuelto directo,
   SALVO r3. r4 y el resto de registros quedan
   como los dejó el callback, igual que antes.

Valor restaurado: bytes si `got > 0`; 0 si
`got == 0` (fichero vacío: misma semántica de
fallo/pendiente que antes) o `got < 0` (error
HLE: sin entrada o destino no escribible). Esto
último es una desviación deliberada del «bytes»
literal: restaurar -1 (0xFFFFFFFF) haría que
`loadFileByPathAsync` lo tomase por éxito
(solo comprueba r3 != 0) con un búfer no
escrito; restaurar 0 preserva el camino de
fallo seguro. En los runs, `got < 0` no ocurre
(todas las lecturas con callback son `got > 0`).

Alcance, verificado en código huésped (no
supuesto): SOLO `DVDReadAsyncPrio` con callback
!= 0. El camino sincrono (callback nulo, retorno
1/0) no cambia; `DVDReadPrio`, los callbacks VI
(su propio trampolín, Fase 8) y los drenajes ARQ
no lo usan. Los 20 puntos `bl` a
`DVDReadAsyncPrio` en el código recompilado son:
el wrapper `DVDRead` 0x80015888 (tras el retorno
ignora r3: lee su global [r13-26664], que el
callback ya escribió con los bytes),
`loadFileByPathAsync` 0x80015AA4 (solo r3 != 0)
y 18 llamadores en chunk_0016/0017 que
sobrescriben r3 (o saltan incondicionalmente) al
volver; NINGUNO compara r3 con 1 ni usa el
retorno del callback como dato. Por eso bytes
(y 1, en el caso de `loadFileByPathAsync`)
son equivalentes para todos los llamadores
verificados. Riesgo residual, declarado: si un
camino futuro llamase a `DVDReadAsyncPrio` por
puntero de función (no hay ninguno en el código
recompilado: las 20 llamadas son `bl` directos)
y usase el retorno del callback, vería bytes en
vez de ese retorno; el escaneo estático no lo
cubre, la traza dinámica sí (cada entrega queda
registrada como `DVDTrampoline` con el r3 del
callback a la entrada).

Pila, no slot único: un callback que lanzase
otra lectura async antes de volver apilaría un
segundo marco y se desapilaría en orden LIFO.
En los runs no se observa anidamiento
(profundidad máxima 1, pila 0 al final). Un
trampolín sin marco es error interno del HLE y
se marca como exception 1 (fallo ruidoso, nunca
salto a 0 en silencio); no ha ocurrido en ningún
run (0 casos en 135 + 121 + 135 entregas).

Efecto colateral positivo y verificado: en la
base, la carga fallida de `Streams.bin` dejaba
un intento de doble-free del fileInfo (el
callback ya lo libera con `DVDClose` + `mm_free`
con retardo; el camino de fallo de
`loadFileByPathAsync` lo liberaba otra vez) que
el juego reportaba como `*** mm Error *** --->
Can't free ram at this location: 81205e00`
(1 línea en `osreport.log` de run53). Con el
trampolín, la carga toma el camino de éxito, no
hay segundo free y el error desaparece
(0 líneas en run54/run57).

### 2. Nueva traza de audio: el juego sigue pidiendo solo 1367, ahora por una sola causa

Run53 (base, pre-trampolín) reproduce run51:
`dispatch_cap`, 8.000.000 despachos, PC final
0x80257320, exception 0, `DVDOpen` ×133,
`DVDReadAsyncPrio` ×135, FIFO 27.395.620 B,
`PADRead` ×197, `cardStatus` = 13, `Play(1367)`
×2 (desp 2.354.011 y 2.354.497). Parada run53 en
el retorno del primer Play: `dir_ptr` = 0,
`count` = 0, retorno de Play = 0.

Run54 (trampolín, misma réplica): `dispatch_cap`,
8.000.000 despachos, exception 0, `DVDOpen` ×133,
`DVDReadPrio` ×40, `DVDReadAsyncPrio` ×135,
`DVDTrampoline` ×135 (1:1, pila 0),
`DVDClose` ×120, `PADRead` ×197,
`cardStatus` = 13, `saveByte` = 0, cadenas VI
210/210/210, cambios de planificador 32 (4 a
principal, 0 fallbacks), `TitleMenu_run` ×36,
`audioUpdate` ×36, `AttractMovieAudio_Init` ×4,
`Play(1367)` ×2 (desp 2.354.145 y 2.354.652, el
desplazamiento es el coste de los trampolines),
audio final idéntico a run53, `OSReport` 264
frente a 265 (la línea menos es el error `mm`
del punto 1). PC final 0x8025C3B0 frente a
0x80257320 y FIFO 27.395.255 B frente a
27.395.620 B (-365 B) y `texloads` 17.554 frente
a 17.557: el run termina en el límite de
despachos, así que el punto de corte cae en otro
punto del bucle de título; la secuencia de
funciones trazadas (pc/lr) hasta la parada es
idéntica entre base y trampolín (228 entradas,
verificada por comparación), y solo deriva el
conteo de despachos (+151 hasta la parada:
121 trampolines + 30 de deriva por direcciones
de heap distintas al conservarse el búfer de
streams). La comparación byte a byte de `ram.bin`
difiere (el búfer de streams ya no se libera y
las asignaciones posteriores caen en otras
direcciones); los globales de estado del juego
(UI, CARD, audio) coinciden.

Parada run54 en el retorno del primer Play:
`dir_ptr` = 0x810182E0, `count` = 905 (19.920/22),
retorno de Play = 0, y el escaneo de la tabla
en RAM dice: **id 1367: NO** (primeras entradas
1 `TTH/ttalk1`, 2 `TTH/ttalk2`, 3 `TTH/ttalk3`,
4 `TTH/ttalk11`, 7 `MC/MCaveOut`, como en
`Streams.bin`). El directorio queda cargado
también al final del run completo (0x810182E0,
905), no se libera después.

Conclusión del punto 2, sin maquillar: de las
dos causas de Fase 14, la del HLE está
RESUELTA y la de la tabla SIGUE: 1367 no existe
en `Streams.bin` (905 registros; vecinos 1361 y
1368; el BE16 1367 no aparece en todo el
fichero, verificado en Fase 14 y de nuevo en la
tabla cargada en RAM). Ningún stream pedido por
el juego en esta ventana resuelve todavía, pero
ya no es por el directorio: es porque el único
id pedido no está en la tabla. Qué es 1367
(¿id de otra tabla? ¿id de voz descartado en la
versión PAL?) sigue abierto y NO se inventa:
`AudioStream_Play` busca por comparación directa
del u16 en este directorio (verificado en
0x8000D2AC–0x8000D2E4), así que con este
directorio no puede resolverlo.

### 3. `AudioStream_Play` con un id válido, por el código del juego (run55/run56)

El juego en esta ventana no pide ningún id
válido por sí mismo, así que la verificación se
hace re-despachando su propio código (test
`test_phase15.cpp`, fuera del repo): tras la
parada del punto 2 (directorio cargado, estado
de audio del juego intacto), el harness pone
pc = `AudioStream_Play` 0x8000D220, r3 = 1301,
r4 = `ObjSeq_AudioStreamCallback` 0x800806F0 (el
mismo callback que usa el juego) y lr = retorno
de `ObjSeq_start` 0x80081B70. Solo r3/r4
importan en la entrada: el cuerpo sobrescribe
r5/r6/r7 antes de leerlos (verificado en
chunk_0002, 0x8000D314–0x8000D324), así que
r5/r6/r7 = 0 no son datos inventados que el
juego lea. Esto NO se presenta como «el juego
pidió 1301»: es la prueba de que el camino del
juego (lookup en el directorio cargado +
`DVDOpen` + preparación + bridge) entrega un
stream válido.

Resultado (reproducido idéntico en run55 y
run56):

- `Play(1301)` vuelve en 68 despachos, sin
  exception, retorno = 1 (éxito = preparación
  iniciada, ver abajo), `DVDOpen` +1 (el fichero
  es `streams/AN/an1301.adp`, que existe en el
  disco), trampolines nuevos = 0 (la preparación
  usa comandos DVDLow, no `DVDReadAsyncPrio`).
- Estado del juego tras Play: `streamCurrentId`
  = 0, `streamPlaying` = 0, `streamPreparingId`
  = 340, `streamPreparedId` = 0,
  `streamEndPos` = 0x41C00000. El 340 NO es un
  id: es índice+1 en el directorio (1301 está en
  el índice 339 de `Streams.bin`, verificado en
  el fichero y en la tabla en RAM), que es lo
  que `Play` guarda en ese global
  (0x8000D524–0x8000D528).
- Bridge (hook en la entrada de Play, sin
  sustituir el código huésped): `Play(1301)`
  resuelve a `streams/AN/an1301.wav` (32.000 Hz
  estéreo) y el drenaje entrega submitted =
  delivered = 1.892.352 frames a 48 kHz
  (exactamente el número de Fase 7/14), dropped
  = 0, guard 462, cola vacía. `Play(1367)` sigue
  no resuelto, como debe ser.
- Fase C (experimento, run56): 10 llamadas a
  `audioUpdate` 0x80009BD0 (la misma que
  `gameLoop` hace por frame, 31 despachos cada
  una, sin exception) NO mueven el stream:
  `currentId` = 0, `playing` = 0, `preparing` =
  340, `prepared` = 0, `dvdState` = 1, `pos` = 0
  en las 10. La completitud de la preparación NO
  se sondea por `audioUpdate`: espera el
  callback async DVDLow
  (`AudioStream_PrepareCallback` 0x8000D5FC →
  `AudioStream_StartPrepared`), que el host aún
  no entrega (no hay modelo de interrupción DVD
  para comandos DVDLow de streaming). Ese es el
  siguiente bloqueador exacto para que el
  stream suene POR EL JUEGO (no solo por el
  bridge sombra), y no se maquilla: en host, hoy,
  el sonido de stream del juego es entrega por
  bridge, no reproducción DSP/ARAM del juego.

Run57 (trampolín + bridge, réplica completa):
mismas métricas de juego que run54 (PC final
0x8025C3B0, FIFO 27.395.255 B, `DVDTrampoline`
135/135, pila 0), hook con 3 entradas exactas
(`StopCurrent` ×1, `Play(1367)` ×2, ambas no
resueltas) y verificación directa sin cambios:
stream 1301 → 1.892.352 frames, trigger SFX 1 →
104.997 frames (4 muestras), total submitted =
delivered = 1.997.349, dropped = 0; trigger 45
→ 0 muestras, stream 970 → no resuelto. Los
tests WAV y unit previos siguen PASS por esta
misma ruta (el código de `audio/*` no se tocó
en esta fase; la entrega 1301/trigger 1
reproduce sus números exactos de Fase 7/14).

### 4. Build NDK y APK de prueba GX15

Build `ndk-fase15`: **0 errores**. `libstarfox.so`
**27.616.960 B** (Fase 14: 27.616.232 B; +728 B
del trampolín), ELF64 AArch64, SHA-256
`b627ed36333ab011b1642e92ad5f6a4445e0e60530943697c8d382e253fdd485`,
`android_main` en `T`, **cero**
`mem_/ppc_/func_/dolrecomp_` sin resolver (191
undefined totales, solo libs del sistema, igual
que en Fase 14). Nota de build: el script es
incremental por fecha y no sigue cabeceras; como
`hle.h` cambió el layout de la clase `Hle`, se
reutilizaron los objetos de `ndk-fase14` SALVO
los 4 `.cpp` que dependen (transitivamente) de
`hle.h` (`hle`, `chassis`, `runtime`,
`native-lib`), recompilados de cero y verificados
por fecha y por la cadena del trampolín dentro
del `.so`; los chunks y el resto de C++ no
incluyen `hle.h` (cierre de dependencias
calculado, 4/20 `.cpp`).

APK de prueba `app-debug-gx15-test.apk`
(**12.599.974 B**, SHA-256
`4b59eb5f36bb5577480c75ca6ceff7803c231c2017c5838864098c5c4ef74e36`,
`com.starfox.port` v7 / `0.7.0-gx15-test`):
apksigner Verifies (v2+v3, 1 firmante), zipalign
OK, manifiesto minSdk 26 / arm64-v8a /
debuggable, `libstarfox.so` interior con el
mismo SHA-256 que el build NDK, sin datos del
juego dentro. Curiosidad verificada, no error:
el tamaño total coincide al byte con GX14
(12.599.974 B) aunque la lib creció 728 B, porque
la lib comprime 343 B mejor; los SHA de ambas
APK y de la lib interior son distintos y la lib
interior es la nueva. Etiqueta: PRUEBA — clear
+ quad + SAF + táctil + CARD + bridge inerte sin
`sfa-data/audio`; nunca jugable sin juego
completo. Nota de entorno: el JDK del sistema
ya es OpenJDK 21.0.12.1 (la nota de Fase 14
sobre `~/tools/jdk21` queda superada: esta APK
se construyó con el JDK del sistema).

### 5. Qué queda (tras Fase 15, en orden)

1. Completitud async DVDLow de streams
   (`PrepareCallback` → `StartPrepared` →
   `currentId`/`playing`): el modelo que falta
   para que un stream suene por el juego y no
   solo por el bridge. Es de la misma familia
   que el trampolín (entrega async sin
   interrupciones), pero en comandos DVDLow de
   streaming, no en `DVDReadAsyncPrio`.
2. Layout de `sndFXStartEx`/`sndSeqPlayEx` y
   primer SFX real del juego por el bridge.
3. Secuencias MusyX + DSP (punto 7 de Fase 14),
   mezcla de voces, bucles de muestra.
4. Payload de audio WAV en Pack B
   (`sfa-data/audio` con `streams/` y `musyx/`)
   o decodificación ADP/DSP-ADPCM en el
   dispositivo; sin eso la APK GX15 no suena
   aunque el código esté cableado.
5. Prueba real en Tab S8 (GX15: picker SAF +
   táctil + CARD + bridge inerte) y, cuando haya
   payload, primera escucha real.
6. TEV multi-etapa, rumble y APK 100% jugable
   (sin cambios en esta fase; ver «Fase 13»,
   punto 6).

## Fase 16 (este tramo): completitud async DVDLow + SFX variante única + hook r6/r7

Trabajo en `android-port-base` solo; `main` intacto en
`18ac28e`. Test host fuera del repo
(`work-port/fase2-tests/test_fase16.cpp`, compilado con el
patrón de `build_phase15.sh`: C host con
`compile-host-c.sh` + runtime C++ + bridge, enlazado con
`obj-host/*.o`; se ejecuta desde la raíz del repo para que
`assets/extraidos/audio` resuelva el WAV de la muestra 175).

### 1. Parche DVDLow: `DVDPrepareStreamAsync` por el trampolín

Ficheros: `app/src/main/cpp/gamecube_runtime/hle.{h,cpp}`
(nueva constante `kDvdPrepareStreamAsync` = 0x80249A84,
entrada en `kHleTable`, contador `dvd_prepare_callbacks_`
+ accessor `DvdPrepareCallbacks()`; nuevo caso en
`HandleHostCall` antes de `kDvdCallbackTrampoline`).
Lógica, verificada contra el código huésped de
`DVDPrepareStreamAsync` en
`codigo/generated/chunks/chunk_0145_text1_802466E0.c`
(r6 guardado en r30, r3 = fileInfo en r27):

- Callback == 0 → retorno 1 sin despacho (camino síncrono
  sin cambios).
- `IsPreparing (0x803DE209) == 0` y `preparing
  (0x803DE230) == 0` → retorno 1 SIN re-entrega (guarda
  anti-doble-entrega: una segunda entrega borraría B,
  B = A = 0, y `StartPrepared` posterior ya no arrancaría
  nunca).
- En otro caso: escribe `fileInfo+56 = callback`, apila un
  marco LIFO en la pila del trampolín existente
  (`return_pc = lr`, `restore_r3 = 0`, fileInfo, callback),
  incrementa el contador, pone r3 = 0, r4 = fileInfo,
  pc = callback, lr = `kDvdCallbackTrampoline`.

El parche NO escribe `gameState`, ni D, ni F en RAM: la
precondición `gameState == 1` queda documentada en el
comentario del caso, no forzada (si no lo es, es un
segundo bloqueador aguas arriba, no un fallo de la
entrega). Entrega síncrona inmediata, no interrupción
diferida: la variante diferida fiel exigiría un trampolín
sintético nuevo, diseño nuevo, no parche mínimo. El
`restore_r3` = 0 es inocuo en entrega inmediata porque
`Play` sobrescribe r3 en 0x8000D54C; en una entrega
diferida futura deberá ser el r3 que el código
interrumpido esperaba.

### 2. Test host Fase 16: TODO OK (cifras)

Estado presetado como lo dejaría `Play(1301)` real
(r13 = 0x803E4B40, r1 = 0x80400000 en arena libre,
r2 = 0x803E4B40, gameState = 1, A = 340, E = 1,
B = C = D = F = 0, G = 0), más dos precondiciones de
arranque que el test aislado debe poner explícito
(ver punto 3):

- `AIInit (0x80250458)` llega al centinela en 109
  despachos, sin exception, `bound_32KHz` bajo != 0.
- HLE intercepta `DVDPrepareStreamAsync`: pc = callback
  0x8000D5FC, lr = trampolín DVD, `fileInfo+56` =
  callback, contador Prepare = 1, pila trampolín = 1.
- `PrepareCallback` llega al centinela en 4 despachos,
  sin exception: A = 0, B = 340, E = 0, D = 0, F = 0,
  pila trampolín vacía. Exactamente el estado
  «preparado, no sonando» del informe DVDLow.
- `StartPrepared (0x8000D158)` llega al centinela en 11
  despachos, sin exception: D = 340, F = 1 (playing),
  A = B = C = E = 0.
- Observadores: `GetCurrentId (0x8000CFB8)` = 340 (NO
  1301: 340 es índice 339+1, como predijo el informe),
  `IsPreparing (0x8000CFC0)` = 0.
- Guarda anti-doble-entrega: segunda intercepción
  manejada, pc = centinela sin re-despachar, contador
  sigue en 1, D = 340, F = 1 intactos.
- SFX (bridge, sin juego): `OnSfxTrigger(13)` encola
  exactamente 1 entrada,
  `wav = "musyx/starfoxm/0175_SFXsc_gemrun1022.wav"`,
  22050 Hz mono, 79068 frames a 48 kHz;
  `OnSfxTrigger(45)` encola 0 y queda no resuelto.

### 3. Dos trampas del test aislado (harness, no runtime)

1. Sin `AIInit` previo, `bound_32KHz` / `bound_48KHz` /
   `min_wait` / `max_wait` quedan a 0 y `__AI_SRC_INIT`
   (0x8025072C, al que llama `AISetStreamPlayState`
   desde `StartPrepared`) rechaza siempre la medición
   del contador de muestras 0xCC006C08 y cicla sin fin
   (primer intento del test: 100.000 despachos con
   cap, PC final 0x802507A0, r3 = contador = 0x3DB6,
   timebase 20.000.800). El comentario de
   `InitCpuForBoot` ya lo advertía: AIInit lee el bus
   162 MHz de 0x800000F8 y deriva las constantes SRC
   antes de llamar a `__AI_SRC_INIT`. En el arranque
   real AIInit corre en el boot, mucho antes del
   audio; el test lo despacha explícito. NO es un
   fallo del parche DVDLow.
2. Sin bit FP en MSR, el `lfs` de `StartPrepared`
   (0x8000D1C0, tras `AISetStreamPlayState`) da
   exception FP-unavailable (0x20, vector 0x800, lr =
   0x8000D1B8, F ya en 1, D aún en 0). `InitCpuForBoot`
   deja msr = 0; en el arranque real el juego
   habilita FP en su `__start`. El test pone
   `cpu.msr = 0x2000u` (PPC_BIT(18)) explícito, con
   comentario. Tampoco es un fallo del parche.

### 4. Corrección SFX y hook ampliado

- `app/src/main/cpp/audio/audio_bridge.cpp`:
  `OnSfxTrigger` reproduce SOLO la primera variante no
  nula y hace `break`, con comentario Fase 16
  explicando que los 4 campos son variantes, no 4
  sonidos, y TODO pendiente: pesos + volRand/pitchRand
  en `audio_id_map.h` y selección ponderada real. Para
  triggers de variante única (un solo campo no nulo)
  la primera variante ES la única, sin ambigüedad.
- Hook ampliado a r6/r7 (sin cableado de sonido nuevo
  todavía): `gamecube_runtime/chassis.h` (typedef
  `AudioEntryHook` ahora con r3–r7), `chassis.cpp`
  (pasa `gpr[6]`, `gpr[7]`), `runtime.cpp`
  (`AudioHookTrampoline` con r6/r7),
  `audio/audio_bridge.h/.cpp` (`OnAudioEntry` con
  r6/r7 por defecto 0, hoy ignorados salvo registro
  en `CountedEntries`). Necesario porque
  `sndFXStartEx` usa r6 como índice de tabla y
  `sndSeqPlayEx` reenvía r7.
- BLOQUEADOR antes de cablear el hook de
  `sndFXStartEx` por ID FX: el bridge traduce hoy
  trigger → campo → WAV buscando el campo como ID
  de muestra, pero el código huésped muestra que
  ese campo entra a `dataGetFX` y la muestra real
  es el descriptor FX[2]; si la tabla FX no es la
  identidad, el bridge sonará con el WAV equivocado
  aunque el trigger sea correcto. Falta: volcado de
  la tabla FX en RAM guest tras `sndInit` + traza
  PCTRACE del primer SFX real (base aproximada
  0x803CB7D8 según el cálculo de `dataGetFX`).
  `sndSeqPlayEx` NO se cablea a WAV: es secuenciador
  (`.pro`/`.poo` + `midi.wad`), no fichero de audio.

### 5. Análisis GX/TEV y payload de audio (de este tramo, sin código todavía)

- Addendum GX/TEV (trabajo de análisis, fuera del
  repo): conteos estáticos en los 176 chunks
  (`GXSetNumTevStages` 59, `GXSetTevOrder` 222,
  `GXCopyDisp` 1, `GXCopyTex` 9,
  `GXLoadTexObjPreLoaded` 36, `PADControlMotor` 5,
  `GXSetBlendMode` 92, `GXSetAlphaCompare` 76,
  `GXSetZMode` 60, `GXSetFog` 21, `GXSetTevIndirect`
  47). Matiz que cambia el orden: la TEV multi-etapa
  no es solo post-filtro; las etapas de mundo
  (`addCastShadowTevStages` 0x80050300,
  `addProjectedLightTevStage` 0x8005073C,
  `addShadowFalloffTevStages` 0x8004D414,
  `setupCausticBaseTevStages` 0x8004CFF0,
  `setupHeatShimmerTevStages` 0x8004DC38, etc.)
  son sombreado del mundo y deben ir antes que el
  TEV indirecto de agua/distorsión, tras la cadena
  PREV básica. «1-2 etapas bastan para la primera
  jugable» se mantiene. Implementación futura: el
  generador de shader debe leer los registros BP
  ColorIn/AlphaIn/ColorOp/AlphaOp por etapa
  (`GXSetTevColorIn` 241, `GXSetTevAlphaIn` 219,
  `GXSetTevColorOp` 209, `GXSetTevAlphaOp` 206),
  no apoyarse en `GXSetTevOp` (solo 3 sitios).
- Payload de audio por tiers (propuesto, NO
  construido ni subido): Pack B base 235 MiB + Tier
  0 SFX solo (816 WAV MusyX, 25,4 MiB) ≈ 260 MiB;
  Tier 1 primer tramo (Tier 0 + ADP de
  `streams/TTH/`, 108 MiB) ≈ 368 MiB; Tier 1-WAV
  ≈ 508 MiB; completo (ADP 521 MiB + `.sam` 14,6
  MiB + `.sdi` 108 KiB) ≈ 771 MiB. Recomendación:
  ADP en dispositivo con caché PCM (ahorro ~1,3
  GiB frente a WAV), portando a C++ los dos
  decodificadores hoy solo en Python
  (`herramientas/audio/extract_audio.py`: ADP DTK
  y DSP-ADPCM). Sin payload, la APK no suena
  aunque el código esté cableado.

### 6. Qué queda (tras Fase 16, en orden)

1. Mezcla de voces 8 SFX + 1 stream en paralelo
   (clamp int16, contador `dropped_`, descarte sin
   robo en paso 1) y bucles por metadato del
   inventario (321/1472 muestras MusyX; 0/958
   streams), sin inferir flags FX `0xC000`.
2. Resolver la tabla FX (volcado + traza PCTRACE)
   y cablear el hook de `sndFXStartEx` por ID FX;
   primer SFX real del juego por el bridge.
3. Secuencias MusyX + DSP (música: NO sonará en
   el paso SFX/streams; solo SFX + streams de
   voz/ambiente).
4. Payload de audio en Pack B (o decodificación
   ADP en dispositivo) — punto 5.
5. TEV multi-etapa (etapas de mundo primero),
   rumble y resto de GX/HLE para un frame jugable
   completo.
6. La cuestión 1367 sigue abierta (id no en
   tabla; no inventar qué es) y la APK jugable
   candidata exige, además de lo anterior, input
   efectivo y juego real con audio en Tab S8.

## Fase 17 (este tramo): mezcla de voces 8 SFX + 1 stream + bucles por metadato

Trabajo en `android-port-base` solo; `main` intacto en
`18ac28e`. Test host fuera del repo
(`work-port/fase2-tests/test_fase17.cpp`, mismo patrón de
compilación que `test_fase16`; se ejecuta desde la raíz
del repo para que `assets/extraidos/audio` resuelva los
WAV). La Fase 16 ya está cerrada y en verde; esta fase
cambia el bridge, no el parche DVDLow.

### 1. Modelo de voces (sustituye la cola serial)

Ficheros: `app/src/main/cpp/audio/audio_bridge.{h,cpp}`,
`app/src/main/cpp/audio/audio_id_map.h` (regenerado, ver
punto 2), `herramientas/audio/gen_audio_id_map.py`.

- 8 voces SFX + 1 voz de stream, en PARALELO: `Tick()`
  mezcla un bloque de hasta 4096 frames sumando en
  int32 por frame (ganancia por voz) y con clamp duro
  a int16 UNA vez al final (no clamp progresivo por
  voz: 20000+20000−20000 debe dar 20000, no 12767).
  Sin normalización por nº de voces, sin compresor
  en este paso. El volumen maestro lo aplica
  `Audio::SubmitBuffer` (ya lo hacía); el bridge solo
  aplica vol/127 en SFX para no aplicarlo dos veces.
- Voz de stream única: un nuevo `Play` la SUSTITUYE,
  no se encola detrás (el juego tiene un solo stream
  actual). `OnStreamStop()` detiene SOLO la voz de
  stream: corrección frente a la cola serial anterior,
  que vaciaba también los SFX en curso.
- Voces SFX llenas (8 ocupadas): el nuevo SFX se
  DESCARTA y se cuenta en `DroppedSfx()` (paso 1, sin
  robo). El robo por antigüedad/volumen es el paso
  siguiente, una vez medido qué voces conviven en
  trazas reales.
- Ganancia SFX: `vol_base/127` del trigger
  (`SfxTriggerEntry.vol_base`; pitch se ignora en
  este paso, como en Fase 16).

### 2. Bucles por metadato (no por flags FX)

El generador ahora emite en `MusyxSampleEntry` dos
campos nuevos, `loop_start` y `loop_len`, en frames
de la fuente, desde `analisis/audio.csv`
(`loop_inicio`/`loop_longitud`; 0,0 = sin bucle).
Regeneración verificada: 1472 muestras, 820 streams,
1205 triggers, 0 muestras referenciadas sin WAV; el
diff del header es solo la estructura + las 1472
líneas de muestras (321 con bucle, como el
inventario). El bridge reescala el bucle a 48 kHz al
encolar (`loop_48k = loop_fuente × 48000 / rate`,
recortado al total resampleado por redondeo).
Semántica: al llegar a `loop_start + loop_len`, la
posición vuelve a `loop_start` (se repite la región,
NO se reinicia desde 0); la cola tras el fin del
bucle nunca se alcanza en bucle (ej. muestra 175:
bucle fuente [18273, 35556) en 36322 frames; a
48 kHz [39777, 77399) en 79068 frames; cola de
1669 frames no jugada en bucle). La voz en bucle
solo para por stop/robo, nunca por EOF. Sin bucle,
termina en EOF. NO se infieren flags FX (bits
0xC000 de `synthStartSound`, probablemente tipo de
muestra/bucle, sin verificar): el bucle es opt-in
por metadato.

### 3. Test host Fase 17: TODO OK (cifras)

- Paralelo SFX: trigger 25 (44094 frames) + trigger
  35 (14506 frames) a la vez → entregados = 44094
  = max, NO 58600 = suma; entregados = drenados,
  0 descartados en backend.
- Stream + SFX: stream 1 (258048 frames) + trigger
  25 → tras superar la longitud del SFX queda
  exactamente 1 voz activa (el stream);
  `OnStreamStop()` deja 0 voces; se entregó más que
  el SFX solo.
- Voces llenas: 8 triggers no en bucle
  (25, 35, 1, 14, 19, 2, 3, 5) ocupan las 8 voces; el
  9º (trigger 8) no encola, `DroppedSfx()` = 1, sin
  entrada `Played` nueva por el descartado.
- Bucle: trigger 13 → muestra 175, 79068 frames a
  48 kHz; tras entregar 86016 frames (> longitud
  total) la voz SIGUE activa y su posición es
  48394, dentro de [39777, 77399); `OnSfxStop()`
  la vacía. Regresión: `test_fase16` recompilado
  contra el nuevo bridge (su layout cambió) sigue
  TODO OK.
- NO verificado por contenido: la ganancia
  vol/127 y la forma de onda mezclada (el backend
  host solo cuenta frames, no expone PCM); solo
  está verificado por código + conteos de frames.
  La escucha real exige payload + Tab S8.

### 4. Qué queda (tras Fase 17, en orden)

1. Resolver la tabla FX (volcado + traza PCTRACE)
   y cablear el hook de `sndFXStartEx` por ID FX;
   primer SFX real del juego por el bridge.
2. Secuencias MusyX + DSP (música: NO sonará en
   el paso SFX/streams; solo SFX + streams de
   voz/ambiente).
3. Payload de audio en Pack B (o decodificación
   ADP en dispositivo) — sin eso la APK no suena
   aunque el código esté cableado.
4. TEV multi-etapa (etapas de mundo primero),
   rumble y resto de GX/HLE para un frame jugable
   completo.
5. La cuestión 1367 sigue abierta (id no en
   tabla; no inventar qué es) y la APK jugable
   candidata exige, además de lo anterior, input
   efectivo y juego real con audio en Tab S8.

### 5. APK de prueba GX16 (Fase 16+17, PRUEBA — NO jugable)

`android-port-base/app-debug-gx16-test.apk`
(**12.595.878 B**, SHA-256
`7c5ade4a5ed263e25c4e02af16bd8c2d9089b69bb322ff4e19b835e3498e5673`,
`com.starfox.port` v8 / `0.8.0-gx16-test`):
apksigner Verifies (v2+v3, 1 firmante), zipalign OK,
manifiesto minSdk 26 / arm64-v8a / debuggable (build
de prueba expresa, como GX15), `lib/arm64-v8a/
libstarfox.so` interior 27.616.864 B, SHA-256
`34cec2a7e518970fb766ab766afe157f6f153d4cd14182f7becd8df3ed8a73c5`
(idéntico al build NDK Fase 16+17: AArch64,
`android_main` en T, 0 símbolos
`mem_`/`ppc_`/`func_`/`dolrecomp_` sin resolver, 191
undefined solo de libs del sistema), más
`libc++_shared.so` 9.236.352 B. Sin datos del juego
dentro. Etiqueta: PRUEBA — clear + quad + SAF +
táctil + CARD + bridge con mezcla de voces y bucles
en host, pero inerte sin `sfa-data/audio`; nunca
jugable sin juego completo. Nota de entorno: el JDK
del sistema desapareció con el reemplazo de VM (apt
del sistema con el bloqueo tomado); la APK se
construyó con Temurin 21.0.13 descargado por curl a
`~/tools/jdk-21.0.13+9` (persiste en `~/tools/`, a
diferencia de /usr); el JDK parcial de
`~/tools/jdk21` NO sirve (le falta `java.security`
y `javac` falla en `SecurityProperties`).

## Fase 18 (2026-10-26, este tramo): hook sndFXStartEx por ID FX — primer SFX real por el bridge

**Veredicto que cambia el sonido:** la tabla FX NO es la identidad.
El campo de Sfx.bin que el bridge usaba como «ID de muestra» es un
ID FX: entra a dataGetFX, sale un descriptor cuyo único campo
variable es macro (offset 2), y la muestra real es el operando
flags>>8 del único START-SAMPLE del macro. macro == fxId en 0/833
casos y sample == fxId en 0/833. Las 1331/1331 variantes de trigger
con muestra sonaban con un WAV distinto del verificado.

**Verificación por tres vías (trabajo en work-port/fase18-fx/):**
1) Offline: starfoxs.pro (56 grupos; 29 tipo 1 con 833 FX, IDs 0–832
contiguos) + starfoxs.poo (925 macros; 833/833 macros FX con
exactamente un START-SAMPLE, muestras 595–1471, todas con WAV).
2) RAM real tras sndInit: 833 descriptores idénticos a .pro salvo
vGroup=31 impuesto por dataInsertFX (833/833).
3) dataGetFX real en host: descriptores esperados para
13/25/35/45/175/648/335/420–423/0/832/1, NULL para 999/65535.
Formato FX_TAB (10 B BE): id@0, macro@2, maxVoices@4, priority@5,
volume@6, panning@7, key@8, vGroup@9; en los 833: maxVoices 255,
priority 10, volume 127, panning 64, key 60 constantes.
Direcciones: sndFXStartEx 0x80273218 (r3=fxId, r4=volume, r5=pan,
r6=studio; r7 basura del llamador, se ignora), synthFXStart
0x80272120, dataGetFX 0x80275B28, dataFXGroupTable 0x803CB7D8.
Tabla verificada: FX 13 -> muestra 926, FX 25 -> 1285, FX 35 -> 693,
FX 45 -> 839. Trigger 13 -> FX 175 -> macro 1040 -> muestra 841
(no starfoxm/0175); trigger 45 no tiene FX (sus 6 sfxIds son 0,
así que no llama a sndFXStartEx; su «no resuelto» era correcto
por ese motivo, no por secuencia/grupo).

**Implementado en este commit:** audio/fx_table.h (833 muestras,
generada desde fx_verified.csv, no a mano) + AudioBridge::OnFxStart
(fxId&0xFFFF, volume 0xFF->127, pan 0xFF->64 solo registrado sin
ley de paneo inventada, studio, ganancia volume/127, bucle por
metadato) + OnAudioEntry(pc 0x80273218) que lo despacha con
r3-r6 del chassis (el hook ya disparaba en ese pc; antes solo
contaba). Test host test_fase18_fx.cpp: TODO OK (FX 13/25/35/45 a
sus muestras correctas, hook por pc con r7=0x12345678 ignorado,
FX 999/65535 no resueltos sin crash, entregados == drenados,
0 descartados). Regresión test_fase17: TODO OK.

**Pendiente documentado, no oculto:** el helper OnSfxTrigger
sigue tratando el campo Sfx.bin como muestra directa (camino
solo de test host; el camino real del juego es sndFXStartEx ->
OnFxStart). Corregirlo para que pase por la tabla FX y actualizar
los tests Fase 16/17 (que fijan muestra 175 / 79068 frames para
trigger 13) queda para el siguiente paso, no se hizo aquí para
no romper la suite validada. Primer SFX real por PCTRACE:
pendiente de partida más larga más allá de 0x80081B70 (en la
ventana medida hubo 56 sndPushGroup y 0 sndFXStartEx; el hook
quedó probado en prueba aislada, no en partida). FX 96, 162, 820:
su macro tiene play-macro antes del START-SAMPLE, muestra lineal
tabulada con branch_before_sample=1 pendiente de confirmar por
ejecución MCMD completa. sndFXStartEx aislado devuelve -1 por
falta de estado synth en el test aislado, no por error de tabla.
La cuestión 1367 sigue abierta. MusyX/DSP (secuencias) y TEV
multi-etapa siguen pendientes en este tramo.

## Fase TEV (2026-10-26, este tramo, SIN commit ni push): TEV multi-etapa + rumble fase A

**Estado del arbol: cambios sin commitear en `android-port-base` para
revision del coordinador (no se hizo commit, no se hizo push, `main`
intacto).** Diseno seguido sin reinventar: `work-port/fase18-tev/
TEV-DESIGN.md`, `RUMBLE.md`, `GX-RESTO.md`.

**1) Anclaje previo obligatorio (hecho).** `GxDraw` gana `TevState tev`
+ `has_tev`, rellenados en `GxParser::ParseDraw()` ANTES de las tres
salidas (normal, opaca, POINTS): el snapshot copia el `bp_` vigente
en ese offset FIFO, porque `bp_` muta con el stream y leerlo al final
del frame daria a todos los draws la configuracion del ultimo.
Decodificado con confianza alta: GENMODE (BP 0x00) bits [13:10] + 1 =
nº de etapas; palabra color BP 0xC0+2*etapa y palabra alfa
0xC1+2*etapa (YAGCD + codigo SDK recompilado: d[3:0], c[7:4], b[11:8],
a[15:12], bias[17:16], op-bit[18], clamp[19], scale[21:20], out[23:22];
bits[17:16]==3 => COMP, si no ADD/SUB). La palabra alfa usa la misma
estructura con campos de 3 bits en simetria asumida (d[2:0], c[5:3],
b[8:6], a[11:9]): PENDIENTE del anclaje §3.3 del diseno, y el test
host fija el comportamiento actual para que el anclaje solo tenga
que corregir `DecodeAlphaWord`.

**2) Generador TEV (`renderer/gx_tev.h`, sin GL, GLSL ES 1.00).**
Formula ADD `mix(a,b,c)+d` con bias/scale/clamp, SUB con b negado,
COMP por canal (R8 solo R, GR16 R+G, BGR24/RGB8 los tres; el caso
sombra COMP_R8_GT esta cubierto por test), estado PREV/REG0-2,
KONST por selector (literales 1..1/8 y K0-K3 por canal), swap
identidad, samplers un uniform por texmap usado (max 8), cache por
hash FNV-1a con tope 128 (LRU). Politica §6 del diseno: indirecto =
no-op contado (la etapa combina igual con la texcoord sin perturbar);
input/op fuera de enum = passthrough de la etapa + contador, nunca
crash ni magenta; >16 etapas truncadas con marca; etapa identidad
sin codigo pero contada como procesada. Integracion GL en
`GxGlRenderer`: el programa TEV compilado solo se USA cuando es
resoluble con el formato de vertice actual (sin RASC/RASA y como
mucho 1 sampler cuyo mapa es el tex_map del draw); cualquier otro
draw TEV cae al programa fijo anterior con contador `tev_fallback_`.
Sin snapshot (`has_tev=false`) no se tocan los contadores TEV.
Contadores nuevos: `tev_draws_`, `tev_stages_total_`,
`tev_indirect_noop_`, `tev_unsupported_`, `tev_programs_compiled_`,
`tev_fallback_`.

**3) Rumble fase A (`gamecube_runtime/rumble.h` + HLE).**
`Hle::kPadControlMotor = 0x8024F580` en la tabla HLE
("PADControlMotor") con estado por canal y solo-en-transicion
(`RumbleTracker`): r3 = chan (0-3), r4 = cmd (0=STOP, 1=RUMBLE,
2=STOP_HARD=STOP); chan/cmd fuera de rango = aviso sin estado y sin
crash; retorno 0 (void en libogc). Salida por interfaz `RumbleSink`:
por defecto nula (no-op + log, fase A). **Fase B pendiente y
documentada, no hecha:** Vibrator por JNI detras de la misma
interfaz (`Hle::SetRumbleSink`), permiso VIBRATE en el manifiesto y
cancelacion en `onPause`; sin prueba en la Tab S8 no se declara
terminada. Sitios `bl` conocidos (sin cambiar): stopRumble2
0x80014A54, stopRumble 0x80014A90, doRumble 0x80014ACC, padUpdate
0x80014F6C, initControllers 0x800154D8. Comentario de `input.h`
actualizado (antes decia que no habia HLE).

**4) Tests host (en `work-port/fase2-tests/`, no en el repo).**
`test_tev.cpp` + `build_tev.sh`, `test_rumble.cpp` +
`build_rumble.sh`: TODO OK. `test_tev`: decodificacion color
caustica etapa 0 (a=15,b=8,c=10,d=15, ADD, clamp 1) y sombra etapa 1
(COMP_R8_GT, op 8, no ADD); caustica 3 etapas (muestreo, `vColor`,
konstante 0.5, `gl_FragColor`, indirecto contado 1); sombra 4 etapas
(comparacion `>` + `uRegC0/C1/C2`); UI 2 etapas (samplers `uTex0` y
`uTex1`, `uKonst0` K0_R); indirecto sin referencia indirecta y etapa
fuera de enum en passthrough contada, sin fallar; >16 etapas
truncadas a 16; cache (mismo estado mismo hash, 1 compilado; un
campo distinto hash distinto, 2 compilados); snapshot (GENMODE 2
etapas, BP distinto hash distinto, `bp_raw` conservado, order/ksel
marcados no anclados); regresion run19: parseo completo, 602 draws,
602/602 con snapshot TEV, 602 tris traducidos (sin cambio), GLSL
generado para 602/602. Ojo: run19 tiene UN solo hash TEV distinto
(pantalla de titulo con una sola configuracion TEV): la varianza
por draw queda probada sinteticamente (snapshot), no con run19.
`test_rumble`: tracker (repetido no re-dispara, STOP_HARD = STOP,
chan 4 y cmd 9 sin efecto, canales independientes) y despacho HLE
real con sink de registro: (0,1),(0,1),(0,0),(0,2),(4,1),(1,1) dan
exactamente ON, OFF, ON(1) (3 llamadas al sink), 6 llamadas
registradas como "PADControlMotor", direccion fuera de tabla false,
y sin sink no-op sin crash con estado cambiado.

**5) Compilacion NDK arm64: OK.** `android-port-base/
build-libstarfox-ndk.sh` (NDK r28c, clang aarch64 API 26, sin
instalar nada en /usr) enlaza `libstarfox.so` (27.683.056 B, ELF
64-bit shared object ARM aarch64) con el script sin cambios:
"OK: ningun simbolo mem_/ppc_/func_/dolrecomp_ sin resolver"
(194 undefined, solo libs del sistema bionic). Simbolos TEV
presentes en el .so (`GenerateTevFragment`, `SnapshotTevFromBp`,
`TevHash`, `GxGlRenderer::GetOrCompileTevProgram`). Salida en
`work-port/ndk-tev-build/libstarfox.so` (fuera del repo, no se
sube). Los 4 TU tocados (`gx.cpp`, `hle.cpp`, `gx_gl.cpp`,
`input.cpp`) tambien se verificaron por separado con el mismo
toolchain (objetos ELF AArch64, sin errores ni warnings).

**Quedo sin implementar y por que (honesto, no oculto).**
- Order/KSEL/indirecto/konst/regcolor del snapshot: NO anclados
(TEV-DESIGN.md §3.3). El snapshot guarda `bp_raw` completo para el
anclaje futuro sin tocar el parser, pero sus campos order usan la
heuristica texcoord=texmap=etapa (coincide con el caso UI 2 etapas,
NO garantizada para mundo: la etapa 2 de caustica usa mapa 3, no 2)
y ksel/regcolor/konst quedan en neutro (sel 0 = constante 1, valores
0) con `order_anchored=false` / `ksel_anchored=false`. Sin una
captura FIFO de mundo con el caso UI (`gameUiSetupTexturedQuadTev`)
no se puede anclar: el anclaje es trabajo de una ejecucion host,
no de este tramo.
- Color de vertice y UV por mapa en el renderer GL (GX-RESTO.md
P0.2/P0.3): el generador emite `vColor`/`vColor1` y `vUv0..7`, pero
el formato de vertice actual solo lleva una UV y ningun color, asi
que esos programas caen al camino fijo con contador. Multi-textura
por draw (lista `tex_obj_por_mapa`) y matrices de textura (P0.5)
siguen pendientes: sin ellos, la sombra/luz proyectada y los
materiales multi-mapa no se ven aunque el generador sea correcto.
- Estado fijo GL (blend/alpha-compare/z/cull/fog, P0.4), TEV
indirecto real (P2.1), EFB/copia y filtros (P3): fuera de la fase A
por diseno; el indirecto queda en no-op contado.
- Fase B de rumble (Vibrator JNI): pendiente, ver punto 3.
- Ficheros de audio de la Fase 18 (`audio_bridge.*`, `fx_table.h`):
NO tocados. `main` no tocado. Sin commit, sin push.

## Fase 18 ADP (2026-10-26, coordinador): streams solo-ADP suenan por el bridge

**Implementado y verificado en host:** decodificador DTK en el repo
(audio/adp_decode.*), puerto del verificador Fase 18 (bit a bit
idéntico al WAV host en 7 ficheros, con la corrección int64
crítica). OnStreamPlay: si no hay WAV, decodifica el .adp
homónimo (misma ruta relativa, extensión .adp) a 32.000 Hz
estéreo y lo encola como stream vía EnqueueDecoded (la
refactorización EnqueueWav -> EnqueueDecoded no rompe la
suite: test_fase18_fx y test_fase17 siguen TODO OK).
Test test_fase18_adp.cpp con pack simulado solo-ADP (sin WAV):
stream 1301 encola por ADP, 1.892.352 frames a 48 kHz
(exactamente la referencia WAV 1.261.568 x 1,5 y la entrega
Fase 15), entregados == drenados, 0 descartados; stream
999999 no resuelto sin crash. TODO OK.
**Limitación v1 documentada:** decodificación de fichero
entero (~3,2 s para el mayor ADP); el streaming por bloques +
caché PCM en sfa-data/audio-cache/v1/ (diseño Fase 18
payload) queda como siguiente paso. Payload medido:
Tier 0 257,40 MiB, Tier 1 365,24 MiB, completo-ADP 778,40
MiB; ningún tier cubre música secuenciada ni los 85
streams sin resolver. MusyX secuencias: PARCIALMENTE
RESUELTO (formato y flujo de eventos verificados contra
el huésped, 98,85 % de 105.141 notas resueltas offline;
audio audible NO resuelto, sin DSP necesario para el
modelo bridge; sndSeqPlayEx NO cableado a WAV).
La cuestión 1367 sigue abierta.

## APK de prueba GX18 (Fase 18, PRUEBA — NO jugable)

`android-port-base/app-debug-gx18-test.apk`, 12.608.032 B,
SHA-256 `4ba9be852667bb2f71b74dba8542190f9da51c8ec517de58b9f1386bf696a70e`
(commit `c06b795`, push verificado con `git ls-remote`):
`com.starfox.port` v9 / `0.9.0-gx18-test`, apksigner Verifies
(v2+v3, 1 firmante, alias test), zipalign OK, manifiesto
minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de
prueba expresa, como GX16), `lib/arm64-v8a/libstarfox.so`
interior 27.687.048 B, SHA-256
`df5ce0250a1161fd81eee278e5e1b19404348166f56064a1e1b96b1dc6fa0ef4`,
idéntico al build NDK de este tramo (TEV + ADP +
rumble fase A + hook FX). Sin datos del juego dentro.
Etiqueta: PRUEBA — clear + quad + TEV multi-etapa por
generador (con las limitaciones documentadas: order/ksel
no anclados, color/UV por mapa pendientes), SAF + táctil +
CARD + bridge con FX real por tabla, streams por WAV o
ADP, mezcla de voces y bucles en host. NO es la APK
jugable al 100 %: sin secuenciador MusyX audible, sin
streaming ADP con caché, sin juego real con input y
audio verificado en Tab S8. La cuestión 1367 sigue abierta.

## Tramo 5 (2026-10-26, coordinador): TEV de mundo anclado + FX por trigger + ADP por bloques + rumble JNI + MusyX primer pase offline

Trabajo en cinco vías paralelas, cada una en su copia, integradas
por el coordinador con fusiones sin conflictos (0 marcadores de
conflicto) en android-port-base. La vía MusyX entregó diseño +
renders offline, NO código en el port (su parche chassis es solo
harness, marcado TRAMO5-COPY-ONLY, y NO se integró en el repo).

**GX — TEV de mundo anclado:** SnapshotTevFromBp decodifica de BP
real order 0x28+p, ksel 0xF6+p, indirecto 0x10+e, ind order 0x27,
konst/regcolor 0xE0-0xE7; order_anchored/ksel_anchored=true (antes
heurística texcoord=texmap=etapa). Correcciones contra el SDK
recompilado: palabra alfa d[6:4] c[9:7] b[12:10] a[15:13];
AlphaCompare 0xF3 limpio; registros TevColor/C0/C1/C2 unificados;
bug UV (uTex<texmap> con vUv<texcoord>). Casos dorados literales:
cáustica 0x8004CFF0, sombra 0x80050300, UI 0x8011E35C. Color/UV/
texturas por mapa (hasta 8 samplers, unidad=mapa, magenta si
falta), matrices de textura (s,t,1) + proyectiva, estado fijo GL
desde BP (blend, Z, cull, scissor con corrección -342 + flip,
alpha-compare como discard; fog solo snapshot+contador; blend
lógico off+contador). Test nuevo test_tramo5: 80 checks, 0
fallos; run19 602/602 draws con GLSL; test_tev viejo actualizado
(AlphaWord nuevo layout, flags anclados) y TODO OK integrado.
Pendientes con causa: indirecto real P2.1 (falta decodificar
GXSetIndTexMtx 0x8025BBF4 y GXSetIndTexCoordScale 0x8025BD54);
texgen-POS (cáustica coords 1/3 desde POS, sombra POS mtx 60);
Fog start/end sin invertir; EFB/copia P3 (disparo por MMIO PE,
no FIFO); supuestos explícitos en el informe GX (matriz 2x4,
glFrontFace CW, igualdad float alpha-compare, bit 19
indirecto, bit 2 blend, ScissorBoxOffset). Sin captura FIFO de
mundo: la demostración es decodificador + literales, no frame.

**FX — OnSfxTrigger por tabla:** trigger -> primera variante no
nula = ID FX -> kFxSample -> EnqueueSample (mismo camino que
OnFxStart, que no se toca). Trigger 13 -> FX 175 -> muestra 841,
sample_0841.wav, 51012 frames sin bucle (antes 175 / 79068).
Fase 16 TODO OK (39), Fase 17 TODO OK (36, §4 rehecha con
trigger 155 -> FX 156 -> muestra 887, 14315 f, bucle [26,14280)),
Fase 18-FX TODO OK (22); sonda OnFxStart(175) = misma 841 con
51012 f. FX 96/162/820 CONFIRMADOS por recorrido MCMD: play-macro
= voz hija paralela con la misma muestra (1173/1172/1147);
pendiente solo el doblaje a 2 voces. Primer SFX real por PCTRACE
NO apareció: 2 intentos de 20M despachos, sndFXStartEx=0; los
pulsos de pad no alteran la trayectoria (juego no sale de
título/atractiva); siguiente paso: entrada de pad en menú o
arrancar desde guardado.

**ADP — streaming por bloques + caché PCM:** nuevos
adp_stream.{h,cpp} (DTK por bloques 32 B -> 28 frames, int64,
resampleo incremental sin chasquidos) y adp_cache.{h,cpp}
(sfa-data/audio-cache/v1/<rel>.pcm s16le 32 kHz, .meta JSON,
atómico .tmp+rename, LRU 2.048 MiB, keep-set nunca desaloja lo
que suena, parcial no se promueve). Bridge: caché -> ADP por
bloques (escribiendo caché en vivo) -> WAV -> silencio +
unresolved, nunca crash; índice ADP insensible a caso,
reconstruido al primer fallo. SAF: verifyAndMark() informa de
audio/ sin bloquear; «añadir audio» por detrás completo
(requestAudioFolder/copyAudioTree solo en sfa-data/audio/),
pero el botón visible NO está cableado (sin UI Java ni overlay;
robar zona táctil sería regresión). Test integrado TODO OK
(74 checks, tras actualizar el fixture packE a la corrección FX:
trigger 25 -> FX 648 -> muestra 996, 23989 f); 1301 por bloques
bit a bit idéntico a fichero entero; gnr1423 mayor en 221 ms.
Sustituye al fallback ADP fichero entero de la Fase 18.

**Rumble fase B — Vibrator por JNI:** viable sin cambiar a Java
Activity (patrón SAF existente). Chan 0 + RUMBLE -> waveform
repetida, STOP/STOP_HARD -> cancel(); canales 1-3 solo
registrados. Cancelación idempotente en dos capas: nativa
(StopAllRumble desde Shutdown, PAUSE y LOST_FOCUS con reset)
y Java (onPause/onDestroy -> cancelRumble). Manifiesto VIBRATE
+ vibrator required=false; VibratorManager API 31+ con fallback
API 26-30, javac contra android.jar API 34 con 0 warnings.
Test host fase B TODO OK (18 checks), fase A intacta. Pendiente
hardware: prueba en Tab S8 (que vibre, que STOP pare, que
pausar/salir detenga el motor, y si la tablet tiene vibrador).

**MusyX — primer pase audible offline, SIN cableado en el port:**
verificación huésped nota->muestra track 5 completa EXACTA
(281/281 capturas, tablas M 595 macros/98 layers); secuenciador
generalizado exacto (track 0 bucle 73.223 pasos 16/16, track 30
16/16); renders offline track 99 (6 notas, 23,99 s, pico 0,670)
y track 74 (15 notas, 41,99 s, pico 0,969) con pitch verificado
(ratio 1,2616 vs 1,2599, error 0,13 %); calibración medida
ticks/s = BPM×6,4 = (BPM/60)×384 (corrige BPM×51,2 de la Fase
18). Diseño de cableado sndSeqPlayEx 0x8027C34C hecho, NO
implementado: sin él, la música NO suena dentro del juego.
Trabajo en work-port/tramo5-musyx/ (TRAMO5.md, seq_host.py,
render_musyx.py, WAV 99/74); NO se copió el parche chassis
harness al repo.

**Datos:** sin cambios en este tramo (Tier 0 257,40 MiB, Tier 1
365,24 MiB, Completo-ADP 778,40 MiB; Pack B 240 MB). La cuestión
1367 sigue abierta.

## APK de prueba GX19 (Tramo 5, PRUEBA — NO jugable)

`android-port-base/app-debug-gx19-test.apk`, 12.673.702 B,
SHA-256 `7e9b8a6702f0080f0802616733f015047934f3fa794a15324d295e252a662539`
(commit de este tramo, push verificado con `git ls-remote`):
`com.starfox.port` v10 / `0.10.0-gx19-test`, apksigner Verifies
(v2+v3, 1 firmante, alias test), zipalign OK, manifiesto
minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de
prueba expresa), permiso VIBRATE, vibrador no obligatorio,
`lib/arm64-v8a/libstarfox.so` interior 27.792.464 B, SHA-256
`01714e0439da6f52695fb32e826c289471ff92ee4a367b1ce748807a7f71379d`
(idéntico al build NDK de este tramo: 0 errores, 0 símbolos
mem_/ppc_/func_/dolrecomp_ sin resolver, 213 undefined solo de
sistema, `android_main` y `func_80003100` en T).
Build manual (Gradle daemon con fallo conocido): javac
--release 17, d8, aapt2 link --min-sdk-version 26
--target-sdk-version 34 --version-code 10 --version-name
0.10.0-gx19-test, libstarfox.so + libc++_shared.so, zipalign -f
4, firma keystore de prueba alias test. Sin datos del juego
dentro.
Etiqueta: PRUEBA — arranca, clear + quad + TEV multi-etapa por
generador con TEV de mundo anclado (con las limitaciones
documentadas: indirecto real no implementado, texgen-POS
pendiente, Fog solo contador, EFB sin implementar), SAF + táctil
+ CARD + bridge con FX real por tabla (OnSfxTrigger corregido),
streams por WAV o ADP por bloques con caché PCM, mezcla de
voces y bucles en host, rumble JNI (pendiente de prueba en
hardware). NO es la APK jugable al 100 %: sin secuenciador
MusyX audible en el juego (renders offline 99/74 sí suenan,
cableado sndSeqPlayEx pendiente), sin juego real con input y
audio verificado en Tab S8, sin datos dentro (inerte sin
sfa-data/). La cuestión 1367 sigue abierta.

## Tramo 6 (2026-10-26, coordinador): indirecto TEV real + primer SFX real + sndSeqPlayEx cableado + botón «añadir audio» + datos medidos

Trabajo en 5 vías paralelas, integradas por el coordinador con
verificación NDK (no se copió ninguna copia entera sobre otra en
`audio_bridge`, tocado por FX/ADP de Tramo 5 y por MusyX/SFX de
este tramo; fusión cambio a cambio).

**TEV indirecto real + texgen-POS + Fog + EFB (vía 1, test nuevo
71 checks 0 fallos; regresión Tramo 5 80 checks 0 fallos, run19
602/602):** decodificado con evidencia `GXSetIndTexMtx`
0x8025BBF4 (slots 1→0/2→1/3→2 + alias, BP 0x06+3k..0x08+3k,
palabra [escala:23-22][fila1:21-11][fila0:10-0], S11 =
int11/1024, campo escala = (scale_exp+17)&3; cáustica
0x8004D964: id 2, scale_exp −3 → campo 2),
`GXSetIndTexCoordScale` 0x8025BD54 (BP 0x25 etapas 0/1, 0x26
etapas 2/3; cáustica 0x8004D1CC: (0,0,0) → ITS_1/ITS_1),
`GXSetTevIndirect` 0x8025BB58 (orden de args corregido desde
el cuerpo SDK; cáustica 0x8004D1FC → palabra 0x270),
`GXSetTexCoordGen2` 0x80258880 (tabla de saltos guest
0x8032FF60, XF palabra 1 [src:10-7][hasMatrix 2][forma 1:0],
palabra 2 postmtx = (w&0xFF)+64, 125 = identidad; el id de
matriz va en la sombra GX, no en XF; cáustica 0x8004CFF0
coords 1/2/3 POS mtx 30/33/36, sombra 0x80050300 POS mtx 60
post global, UI 0x8011E35C TEX0 passthrough) y `GXSetFog`
0x8025CC44 (A = far/(far−near), B, C, normalización A a
[0.5,1.0]; BP 0xEE/0xEF/0xF0/0xF1/0xF2; start/end solo con
near/far conocidos). Implementado: indirecto real bajo gate
de 12 condiciones (ITF_8, alfa OFF, wraps OFF, add 0, matriz
presente, escalas ITS_1, mapas/coords válidos, etapa con
textura; fuera del gate: no-op contado), texgen-POS solo
GlTri (src POS, 2x4/3x4, postmtx 125, normalize 0; UV desde
posición post-PNMTX, matriz TnMIDX del vértice o identidad),
Fog decode + start/end con guarda + snippet GLSL lineal
(vacío para EXP/EXP2/NONE). **Corrección al Tramo 5:** la nota
«disparo EFB por MMIO PE, no FIFO» es FALSA — `GXCopyDisp`
0x80259CA8 y `GXCopyTex` 0x80259E18 escriben solo en FIFO
0xCC008000; el disparo es escritura BP 0x52 con bit 0x4000
forzado en la sombra GX (+492), destino BP 0x4B = dest>>5;
el parser sí observa el disparo como eventos `GxCopy`
(regs 0x49/0x4A/0x4B/0x4D + offset FIFO). Copia de píxeles
EFB completa sigue pendiente (sin buffer EFB en el
renderer). Pendiente con causa: multiplicador del campo de
escala ind (2 bits, sin determinar en este DOL, se guarda
crudo), `vFogZ` en `gx_gl.cpp` (cambiaría el formato de
vértice sin prueba en dispositivo), fog EXP/EXP2, texgen
no-POS / postmtx ≠ identidad / normalize ≠ 0, indirecto
fuera del gate, captura FIFO de mundo (sigue sin existir).
Caveat: texgen-POS cáustica exacto solo si el vértice lleva
TnMIDX, si no cae a identidad (documentado); sombra mtx 60
= identidad, exacta.

**Primer SFX real + doblaje (vía 2, test nuevo 41 ok 0 FAIL;
regresiones Fase 16/17/18-FX 39/36/22, 0 fallos):** causa raíz
del fallo de Tramo 5: la confirmación del menú exige fade en
255 y una pulsación A/Start *nueva* después de ese máximo
(un pulso que empieza con la película se consume en pararla
y, mantenido, no genera flanco `JustPressed`); la navegación
no usa D-pad, usa stick analógico, y el título está rotado
(stick X mueve la selección vertical). Intento C (tarjeta
fresca, 40M despachos, stick X/A/Start hasta lectura 700):
**11 llamadas a `sndFXStartEx` 0x80273218, 8 reproducidas,
y el juego SALIÓ del título (DLL 4 → 7, selección 1 →
opciones)** — primer SFX: despacho 6.515.026, frame ~17, FX
411 → muestra 866 (14.943 f), trigger 891
`menu_fox_select`; luego 782 → 1360 (`pep_snorein`), 379 →
853 (`crf_babyflute`, confirmación), 778 → 1362
(`pep_wakeup`), 176 → 865 (`sc_lockedon22`), en DLL 7 791
→ 1363 (`pep_yawn`) y 176 → 865; 3 descartados en DLL 7 no
por sonidos ausentes: el harness nunca llama a
`bridge.Tick()`, así que las 8 voces nunca se liberan
(pendiente: harness que llame a `Tick()` por frame).
Intento D (tarjeta Tramo 5 reutilizada, 20M): `CARDCreate =
0`, 6/6 reproducidos, mismos frames 17 y 114, más `snoreout`
(783 → 1361) y `slip_fingersnap` (792 → 1402, ×2).
Doblaje 96/162/820: `fx_double.h` (675→676 muestra 1173,
669→670 muestra 1172, 595→596 muestra 1147), padre por
`OnFxStart` exacto + hija por `EnqueueSamplePitched`
(53.878 Hz para −2 st, 64.072 Hz para −5 st); test anti-eco:
2 voces, totales distintos (padre 171.723 f, hija 192.751
f), no un eco. **Decisión de integración: el hook
`sndFXStartEx` pasa a `OnFxStartDoubled`** (≥1 voz = éxito);
`OnFxStart` intacto, `OnSfxTrigger` sigue 1 voz a propósito,
pan de la hija registrado sin aplicar (sin ley de paneo
validada). `sndSeqPlayEx` seguía en 0 en estos runs y el
stream 1367 sigue sin resolver.

**sndSeqPlayEx cableado en el port (vía 3, test bridge 50
checks 0 fallos; NDK 6 TUs de audio limpias):** nuevo
`audio/musyx_seq.h/.cpp` (ticks/s = BPM×6,4, agenda CC →
NoteOff → NoteOn ante el mismo tick) y `musyx_notes.h`
generado desde Tramo 5: 99 (gid 54, BPM 60, 6 notas S797),
74 (gid 18, BPM 120, 15 notas S1173), 5 (gid 0, BPM 70, 281
notas, 7 silenciosas huésped excluidas), polifonía máxima
14 < 16 voces. Bridge: `OnSeqPlay` (hook 0x8027C34C,
r3=sgid, r4=sid, r6=params registrado pero no leído — sin
acceso a RAM huésped, speed=256, sin mutes en v1),
`OnSeqStop` (hook 0x80272F80), 16 voces de música propias
fuera de 8 SFX + 1 stream; pitch por resampleo, bucle por
metadato, pan CC10 en note-on, ganancia por bloque de
mezcla (85 ms) porque las primeras notas de 99/74 arrancan
con CC7=0 y suben en rampa (fijar ganancia en note-on las
dejaría mudas). Sintético por la misma vía del chassis:
99 6/6, 1.153.548 f (23,99 s); 74 15/15, 2.016.326 f
(41,99 s); 5 281/281, 0 robos, 1.318.912 f (27,43 s);
canción 42 sin tabla → `unresolved musyx_cancion`.
**En juego NO se afirma música:** runs 3M y 20M con cero
`sndSeqPlayEx` reales (causa: el camino
`Music.bin` → `Music_ChannelLoadedCallback` →
`sndSeqPlayEx` solo se alcanza al salir de título/atractiva,
y los runs host no salen de ahí). El cableado queda probado
por vía sintética esperando esa llamada real. Pendiente:
bucles de canción, resto de canciones, params reales,
equivalencia sgid↔gid, pitch-bend/modulación/ADSR/robo/
release/pan DSP/curvas/solape/portamento/reverb/DSP real.

**Botón «añadir audio» visible (vía 4, test host 52 checks
0 fallos; NDK 5/5 ficheros 0 warnings; javac API 34 OK):**
vía nativa, no overlay Java ni Activity completa (un botón
Java sobre NativeActivity exigiría z-order/foco exactos y
perder el foco pausaría el juego al tocarlo; la Activity
completa obligaría a reescribir el glue). Píldora
centro-inferior x 0,44–0,56 / y 0,92–0,98 (307×96 px en Tab
S8, 32 px del borde inferior), táctil y dibujo con las
mismas constantes, dibujada tras los draws GX también sin
juego. No roba táctil: se consulta antes que el damero,
solo arma un dedo que baja dentro, soltar fuera cancela,
multitáctil independiente; margen mínimo medido 0,0400 en
aspect 1,6 (64 px) y 0,0445 en 16:9; franja superior
rechazada (gesto de sistema robaría toques en y<0,08 sin
immersive-sticky). Estados por color + boot.log: ámbar
fijo = sin audio, ámbar parpadeante = verificando
(anti-doble-pulso), verde = listo, rojo = error; derivados
de marcadores, con nuevos `.saf-audio-error` y
`.saf-audio-cancelled` (sin este último, cancelar dejaba
la píldora parpadeando hasta reiniciar); pulsar en verde
reabre el picker; sondeo cada 128 vueltas, nada bloquea el
loop; `RequestSafAudioPicker` por fin tiene llamador.
Pendiente honesto: etiqueta de texto en la píldora (GL sin
fuente; exige overlay Java o fuente bitmap — mitigado con
color + log + guías), prueba real en Tab S8 (la hará el
usuario con las guías), rumble positivo (pendiente de un
`PADControlMotor` real del juego; hoy ningún run lo ha
llamado, así que el silencio es correcto, no un fallo).

**Datos + pipeline (vía 5, medido hoy, no copiado):** Pack A
785.986.556 B / 3.874 ficheros (corrección: 3.879 era
`sys/` + `files/`); Pack B sin `streams/` 239.678.460 B /
2.916 ficheros; `streams/` 546.308.096 B / 958 ADP; base
SAF 243.309.656 B / 2.921 ficheros. Pack de test =
base SAF + overlay Tier 1 (816 WAV MusyX + 231 ADP TTH):
382.982.980 B (365,24 MiB) / 3.968 ficheros, confirmado por
tres vías; ZIP Tier 1 medido por streaming 301.444.555 B
— un solo fichero, sin split; libre recomendado en Tab S8
≥1,5 GB. Aperturas reales hasta título: 117 ficheros
distintos (71.705.100 B), todos en Pack B, cero en
`streams/` — NO es lista mínima (los runs solo llegan a
título), así que el pack de test sigue siendo Pack B +
Tier 1. Hallazgo: 5 aperturas fallan por mayúsculas en
subdirectorio (`gamefront/animcurv.*`, `voxmap.*`,
`warlock/voxmap.bin`); el juego lo tolera, pendiente del
runtime, no se arregla renombrando el pack. Pipeline APK
en `work-port/tramo6-data/build-tramo6-apk.sh` (preflight,
NDK, validación de símbolos, APK manual, re-validación;
rechaza etiquetas jugable/playable/release/final; no
commitea ni pushea). Corrección a la vía 5: el JDK NO
estaba ausente en la integración (OpenJDK 21 presente en
esta máquina en el momento del build; la ausencia era del
entorno de la vía, tras un reemplazo de VM).

**Build Tramo 6 (coordinador, NDK):** 0 errores, 0 símbolos
mem_/ppc_/func_/dolrecomp_ sin resolver (214 undefined
solo de sistema), `libstarfox.so` 27.865.408 B, SHA-256
`02e3bcadd98edb8b444307207e282810134d6e49f4703d24c8d50f6b52ef4f39`,
ELF64 AArch64, `android_main` y `func_80003100` en T,
`OnFxStartDoubled` y `OnSeqPlay` en T (la lib del primer
build del coordinador, 27.865.152 B / SHA
`04137fe3…`, quedó sustituida por la rebuild del pipeline
APK; la lib interior de la APK es idéntica a la lib NDK
final, mismo SHA).

## APK de prueba GX20 (Tramo 6, PRUEBA — NO jugable)

`android-port-base/app-debug-gx20-test.apk`, 12.702.374 B,
SHA-256
`2ce7f95d90d7bb292e5e4d27208c3133be65f45a3faa4ec61221a1ff15a64c71`,
SHA-1 `db2055525fadc5ed6286792b342ae5e098994067`
(commit de este tramo, push verificado con `git ls-remote`):
`com.starfox.port` v11 / `0.11.0-gx20-test`, apksigner
Verifies (v2+v3, 1 firmante, alias test), zipalign OK,
manifiesto minSdk 26 / targetSdk 34 / arm64-v8a /
debuggable (build de prueba expresa), solo permiso
VIBRATE, `lib/arm64-v8a/libstarfox.so` interior 27.865.408
B, SHA-256 `02e3bcad…` (idéntico al build NDK final),
sin datos del juego dentro. Build manual (Gradle daemon
con fallo conocido): javac --release 17, d8, aapt2 link,
zipalign -f 4, firma keystore de prueba alias test.
Etiqueta: PRUEBA — arranca, clear + quad + TEV de mundo
anclado con indirecto real bajo gate + texgen-POS + Fog
lineal (con las limitaciones documentadas en Tramo 6),
SAF + táctil + CARD + botón «añadir audio» visible
(píldora nativa, sin robar táctil) + bridge con primer
SFX real en host, doblaje 96/162/820, streams por WAV o
ADP por bloques con caché PCM, secuenciador MusyX
cableado (99/74/5 por vía sintética, sin llamada real en
juego todavía), mezcla de voces y bucles en host, rumble
JNI (pendiente de prueba en hardware). NO es la APK
jugable al 100 %: sin juego real con input y audio
verificado en Tab S8, sin datos dentro (inerte sin
sfa-data/), sin música en juego todavía, sin rumble
positivo verificado. La cuestión 1367 sigue abierta.
Pasos de prueba en Tab S8: ver
`android-port-base/GUIA-PRUEBA-TIER1-CACHE.md` y
`android-port-base/GUIA-PRUEBA-RUMBLE.md` en esta misma
rama (pack de test = base SAF + overlay Tier 1, 365,24
MiB totales; overlay transferido 133,20 MiB; libre
recomendado ≥1,5 GB; extraer `boot.log` antes de
relanzar, porque cada arranque lo trunca).
## Tramo 7 (2026-10-26, este tramo): Tick en harness, música forzada real, TEV/EFB resto, etiqueta en la píldora, Pack C y pipeline

**La app sigue sin ser jugable.** Este tramo integra trabajo verificado
en host, no juego en dispositivo. `main` intacto en `18ac28e`.

### 7A — Harness Tick + música en juego
- Hallazgo: el runtime de la APK **ya** hace `Tick()+Pump()` por frame
  tras cada rebanada de 100k despachos; el bug era solo de los harness
  host. No se cambió `audio_bridge.*` ni `runtime.cpp` por esto.
- Test bridge puro: 30 checks, 0 fallos. Sin Tick: 11 SFX → 8
  reproducidos, 3 descartados (Tramo 6). Con Tick: **11/11, 0
  descartados**. En juego: G1 11/11, G2 24/24, G4 4/4, 0 descartados.
  Regresiones intactas: trigger 13→841 (51.012 f), stream 1301 por
  ADP (1.892.352 f), canción 99 sintética (6 notas).
- Música por vía del juego: 0 `sndSeqPlayEx` reales en G1/G2/título/G4.
  El juego SÍ dispara música: canales track 22 (trigger 190
  `cldrnr_tune1_be`) y track 95 (trigger 193 `windydocks`) en
  `status=4` (espera ARQ); el HLE no entrega el callback ARQ de
  lectura, así que `Music_ChannelLoadedCallback` nunca corre. Ventana:
  ningún canal a 8M, ambos ya a 17M.
- Experimento forzado G3 (etiquetado, código huésped real):
  `Music_Trigger(235,1)` + entrega manual de
  `AudioAramReadCompleteCallback` → `sndSeqPlayEx` real con params
  reales de RAM: sgid=54, track=99, flags=6, speed=256. `sgid=54`
  confirma sgid↔gid para la 99. Bridge entrega la 99 completa:
  6 notas, 1.153.548 frames, idéntica a la sintética de Tramo 6.
- Bucles medidos (no implementados): 99 buclea (notas 2..5),
  74 buclea (notas 3..14), 5 no buclea (281 notas). Prioridad:
  primer pase de 22 (gid 0) y 95 (gid 49).
- Pendiente crítico siguiente: HLE ARQ de lectura (diseño en
  trabajo local, sin aplicar), bucles 99/74, `sndSeqVolume`/fades.
  No se afirma música por vía del juego ni sgid↔gid en general.

### 7B — Resto TEV/EFB
- Escala ind resuelta con corrección a Tramo 6: los 3 campos [23:22]
  son trozos de un valor de 6 bits (scale_exp+17); Tramo 6 rechazaba
  toda matriz real. Multiplicador **2^scale_exp** plegado en GLSL
  (caústica: diagonal 0.5, exp −3 → 0.0625). S11=int11/1024.
- vFogZ + fog EXP/EXP2 implementados; near/far recuperados de la
  proyección XF del draw (run19 602/602, run39 orto/persp, 0 fallos;
  draw EXP de run39: error relativo 3.8e-08). FSEL: solo 2=LIN;
  4/5 EXP/EXP2; degenerado = far==near o end==start.
- Texgen: casos reales run39 (NRM, TEX0+post64+norm1, TEX1+post70);
  matrices post SÍ llegan por FIFO y el parser las captura
  (`draw.post_matrices`: run39 4925 draws con post, 4096 post64
  exacto). Traductor: NRM, TEX y post 2D (q=1); POS+post≠125 ya no
  desactiva el texgen.
- Indirecto fuera del gate: frecuencia NO medible con fundamento
  (el censo Tramo 6 de "0 indirectas" era artefacto del parser;
  con decoder corregido run39 4925/5148 draws con matriz ind, todos
  scale_exp=−1; run19 0/602). Gate sin ampliar.
- EFB: `DecodeEfbCopy` puro (bit exec 14, destino
  `0x80000000+(reg4b<<5)`, tamaños probados 640×480/32×32/80×60,
  stride reg4d×32; reg49 provisional, bit 16 hipótesis). Copia de
  píxeles NO implementada (sin buffer EFB); captura FIFO de mundo
  NO existe (diseño, sin frame simulado).
- Tests: nuevo 53 checks, 0 fallos; Tramo 6 corregido 76 checks,
  0 fallos; Tramo 6 original contra código Tramo 7: 66 ok, 5 fallos
  = correcciones deliberadas; Tramo 5: 80 checks ok; run19: 602
  draws, 602 GLSL, 0 fallos.
- Pendiente: ancla absoluta 2^exp (no DOL-probada), curva EXP/EXP2
  (reconstrucción; discriminar en dispositivo), normalize≠0, 3x4+post,
  copia EFB de píxeles, captura de mundo, prueba gx_gl en dispositivo.

### 7C — Etiqueta en la píldora (bitmap GL)
- Vía elegida: bitmap en GL (fuente 5×7, textura opaca, mismo camino
  `DrawTexturedQuad`). Vía Java/TextView rechazada con motivos
  medidos (z-order, foco que pausaría el bucle nativo, geometría
  fuera de `TouchLayout`, tamaño en sp que podría desbordar 307 px).
- Test host: 44 checks, 0 fallos. Etiquetas `AÑADIR AUDIO` /
  `VERIFICANDO` / `AUDIO LISTO` / `ERROR AUDIO`; Tab S8 284×28
  (escala 4), 1080p 213×21; contraste WCAG ≥4,5:1; táctil no robado;
  NDK 0 warnings. Guías Tier 1/caché y rumble actualizadas en la rama
  (puntos A0/A5 nuevos).
- No afirma píxeles reales en pantalla ni prueba en Tab S8; rumble
  positivo sigue sin evento `PADControlMotor` en ningún run.

### 7D — Pack C y pipeline APK
- Pack C-título medido (único hito medido): **117 ficheros,
  71.705.100 B, 0 en `streams/`** (con `sys/`: 122 ficheros,
  75.336.296 B; ZIP 67.324.078 B). **NO instalable**
  (`verifyAndMark` exige ≥2.916 ficheros) y **NO es lista mínima**;
  sin Pack C-menú ni Pack C-primer-mundo. Pack instalable
  recomendado sigue siendo base SAF + Tier 1: **382.982.980 B /
  3.968 ficheros**.
- Pipeline Tramo 7 (`android-port-base/build-tramo7-apk.sh`):
  JDK bloqueador superado (OpenJDK 21.0.12.1 / Temurin 21.0.13),
  guarda de símbolos corregida, guardas de versión rechazadas
  (`jugable`/`PLAYABLE`/sin `-test` → exit 1). Build de validación
  (NO GX21, NO al repo): 12.702.374 B, SHA-256
  `4deeb7b4b7dabe5f0030a8d10d87975cdd513245d980c4032ace339429fb1971`,
  apksigner v2+v3, zipalign OK, solo `VIBRATE`.
- Enlace no byte-reproducible (lib −336 B por orden variable de
  `xargs -P2`; no es diferencia de código: exigir conjuntos de
  símbolos, no igualdad de SHA entre builds).
- Instalación Tab S8: SAF + carpeta privada, sin
  `MANAGE_EXTERNAL_STORAGE` ni `READ_MEDIA_*`; «añadir audio» SÍ
  tiene disparador en c274c96 (corrección al Tramo 6); libre ≥1,5 GB
  para Tier 1; `boot.log` se sobrescribe en cada arranque.

### Integración Tramo 7 en esta rama
- Parches 7B (7 ficheros: `gx.h`, `gx.cpp`, `gx_tev.h`,
  `gx_translate.h/.cpp`, `gx_gl.h/.cpp`) y 7C (nuevo
  `input/audio_label.h`; `gx_gl.h/.cpp`, `renderer.cpp`) aplicados
  sin conflicto (7C pasa `git apply --check` sobre 7B).
- 7A y 7D aportan diseño/medición, no código de juego aplicado:
  HLE ARQ, bucles y params RAM quedan como siguiente paso, no
  como código sin probar en la rama.
- NDK integrado Tramo 7: libstarfox.so 27.875.720 B, SHA-256 8135a18425ed688f3b3dfa983dd0ac1ea6f8704c2cef6c7180aa19db8a47a5d9, ELF64 AArch64, android_main en T, 0 mem_/ppc_/func_/dolrecomp_ sin resolver, 214 undefined solo sistema. APK GX21 (segundo commit de este tramo): android-port-base/app-debug-gx21-test.apk, 12.710.566 B, SHA-256 be0da86c85be0359f3116ba5121980cbb6d29fe661a5c9b130239a50f6deb0e9, SHA-1 04ddfe516261b610b063a432aaf36060d616fdb1, com.starfox.port v12 / 0.12.0-gx21-test, apksigner Verifies v2+v3 (1 firmante), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior 27.876.432 B, SHA-256 d4b7c13c4c159845b555c1f4de982e8e2a1de8a3cdfcf46b4791a424017e7072, android_main en T, 0 símbolos de juego sin resolver. Nota honesta: la lib interior difiere en +712 B de la lib de integración (27.875.720 B, SHA 8135a184…), por el enlace no byte-reproducible ya documentado en Tramo 7D; no es diferencia de código. Etiqueta: PRUEBA — con etiqueta en la píldora, TEV/EFB resto y Tick en runtime, pero sin juego real verificado en Tab S8; nunca jugable al 100%.

## Tramo 8 (2026-10-26, este tramo): HLE ARQ + música por vía del juego + TEV/EFB resto + traza más allá del título

### 8A — HLE ARQ de lectura y música por vía del juego (sin forzado)
- Trampolín `0x8000300C` con restore completo de registros (mismo conjunto que `ThreadContext`); en la entrada a `ARQPostRequest` se encola solo si `r6 == 1` (lectura) y `r10 == 0x80008EDC`; el siguiente host_call redirige a `AudioAramReadCompleteCallback` con `r3 = petición`; su `blr` restaura todo y reanuda el punto interceptado. Diseño Tramo 7 (snapshot/restore + `RunChassis` anidado) NO aplicado: `dolrecomp_call` consulta `host_call` en cada despacho.
- En juego (40M despachos, Tick por rebanada, force = 0): canales 22 → status 1, handle 1, vol 60; 95 → status 1, handle 2, vol 100; **2 `sndSeqPlayEx` reales** (sgid 0/track 22 y sgid 49/track 95, flags=6, speed=256, mutes 0xFFFFFFFF, vol target 0), fades reales `sndSeqVolume` 60/500 ms y 100/500 ms, `SeqVolume` final 0,787, 0 excepciones. G1: PADRead 507, MusyxNotas 19, Delivered 1.327.104 f. G2: PADRead 496, MusyxNotas 12. G3: `curUiDll=5`, PADRead 660, **sndFXStartEx 13/13, 0 descartados**, MusyxNotas 17. Sin resolver: solo stream 1367 (preexistente).
- Bridge: **64 checks, 0 fallos** (trigger 13→841, stream 1301 ADP 1.892.352 f, SFX 11/11 con Tick, bucle 99: 6+2×4=14 notas sigue activa, bucle 74: 15+12=27 notas sigue activa, track 5 sin bucle: 281 notas termina, primer pase 22: 1.886 notas BPM 120, 95: 49 notas BPM 60, params RAM, fade 64/500 ms → 0,5039 tras 6 ticks). Bucles: 99 notas 2..5 periodo 7.672; 74 notas 3..14 periodo 29.179. Voces de música 16→32 (polifonía máxima 22 = 17).
- NO quedó: bucle de 22/95 por secciones (loopCount por sección, sin segmento único; quedan en primer pase y terminan); una sola canción a la vez (al arrancar 95, la 22 se corta, límite v1 del bridge); trayectoria G1/DLL 7 11/11 del Tramo 7 no replayada (guiones no guardados; regresión SFX en juego es G3 DLL 5 13/13); llamador de 190/193 sin identificar; stream 1367 sin resolver.

### 8B — TEV/EFB resto
- Ancla 2^exp REFORZADA, no probada por el DOL: `GXSetIndTexMtx` (0x8025BBF4) suma 17 antes de repartir; un ancla 2^(exp+k), k≠0, exigiría sumar 17−k. Lo que el DOL no descarta: factor constante C≠1 ajeno al exponente. Censo real: solo 2 matrices ind, exp −1, diagonal 0.4375, en 91.445 draws; discriminador de dispositivo en el informe del frente.
- normalize≠0 IMPLEMENTADO (semántica libogc: primera pasada → normalize → post → división por q' en 3x4). Único caso real: TEX0, 2x4, post64, norm1, 87.289 coords / 389.764 vértices; 20,7% UV (0,0), guarda de vector nulo crítica. Caso especial libogc (vértice solo POS+1 TEX en 2x4) NO aplicado (draws mezclan vértices con normal/color, condición por vértice no verificada).
- 3x4+post: 0 coords en 92.939 draws (5 trazas); implementado como camino general, solo prueba sintética, sin afirmar comportamiento del juego.
- Copia EFB de píxeles NO implementada; sí: captura de 0x53/0x54 en `GxCopy`/`DecodeEfbCopy` (crudo, sin decodificar), `PlanEfbCopy` (XFB 640×480 stride 1280 bpp 2 → offset 0x400000, total 614.400; 5 rechazos) y `CopyEfbRows`. Bloqueador exacto: `gx_gl.cpp` sin FBO ni `glReadPixels` ni target EFB; bits de formato low52 sin decodificar a YUY2/RGB565/etc. y filtro sin decodificar; falta plomería de escritura en RAM viva. `GXSetCopyFilter` (0x80259A64) escribe BP 0x53/0x54 (defecto 0x595000/0x000015 si vfilter nulo); filtro constante en trazas: 0x30C1C7/0x0071CC. Bit 16 sigue siendo correlación perfecta, no flag probado (bit16=1 → textura 782, XFB 0; bit16=0 → XFB 25.451, textura 0, en 26.233 copias).
- Captura FIFO de mundo: diseño completo, sin frame simulado (fifo.bin + ram.bin del mismo frame, arranque en boot o snapshot inicial, etiqueta de escena, criterios de rechazo). Sin ella, la frecuencia de indirecto fuera del gate sigue no medible.
- Tests host: nuevo 33/33, Tramo 7 corregido 53/53, Tramo 6 76/76, Tramo 5 80/80, todos 0 fallos; Tramo 7 original contra este código: 3 fallos = cambios deliberados (NRM norm1, TEX norm1, norm1+post64 → (0, 0.5)). NDK `-fsyntax-only` limpio sobre los ficheros cambiados.

### 8C — Traza más allá del título y Pack C
- **NO se llega al menú en ninguna de 7 variantes host** (8M–20M despachos, 0 excepciones, todas `curUiDll=4`, `pendingUiDll=0`, `titleNextDllId=0`, sin ficheros de menú ni de área). Por tanto NO hay Pack C-menú ni Pack C-primer-mundo medidos.
- Corrección a Tramo 7: su traza estaba truncada por el harness (`stop_pc=0x80081B70`, retorno real tras `AudioStream_Play`); la carrera paró ahí con solo 4 PADReads y Start nunca aplicado. El harness Tramo 8 usa `stop_pc=0` en la carrera principal.
- Causa medida: el input SÍ llega (Held Start 0x1000, Start+A 0x1100, ritmo cambia sin input: 53 lecturas sin input frente a 539 con Start en 8M). Falta otra cosa, en orden de probabilidad: condición no-input (fin de THP, DVD/async, callback VI/ARQ no entregado), input distinto en el momento exacto (stick abajo+A — V2 usó D-pad —, B/Z, A tardío con tarjeta), o menú en la misma DLL 4 invisible a la detección por DLL+ficheros. Discriminador: render FIFO por variante + carrera larga con tarjeta y stick-abajo+A; en dispositivo, la parte exploratoria de la guía GX22 es hoy el camino más corto.
- Pack C-título reconfirmado exacto: **117 ficheros, 71.705.100 B, 0 en `streams/`** (con `sys/`: 122 / 75.336.296 B), **NO instalable** (faltan 2.799 para los 2.916 de `verifyAndMark`). Sin tarjeta: 111 / 71.692.396 B. Pack instalable vigente sin cambios: **base SAF + Tier 1 = 3.968 ficheros / 382.982.980 B**. Con tarjeta el juego sí avanza (CARDCreate/Write, partida de 24.576 B, `saveByte=1`) sin salir de DLL 4.

### Integración Tramo 8 en esta rama
- Código (commit `674cd1a`, 13 ficheros, 3.884 inserciones, 88 borrados): 8A (bridge, musyx_seq, notas 22/95, hle, chassis solo hook `sndSeqVolume`, `SetGuestRam` en `runtime.cpp` Init) + 8B (4 parches: `gx.h/.cpp`, `gx_tev.h`, `gx_translate.cpp`, aplicados sin conflicto, idénticos a los ficheros del frente).
- NDK integrado Tramo 8: libstarfox.so 27.954.176 B, SHA-256 7b75108bea8456d5b60b1bce49f81b3962bc32bac0f931eea67044833f39604d, ELF64 AArch64, `android_main` en T, 0 mem_/ppc_/func_/dolrecomp_ sin resolver, 214 undefined solo sistema. APK GX22 (segundo commit de este tramo): android-port-base/app-debug-gx22-test.apk, 12.722.854 B, SHA-256 74c8ea0c01423d4b288c263c54f6a135fd87c62715b9913bbe89b65554a4d84e, SHA-1 7ea6fc2a887a329dea985587cbb8b7abef74ba0d, com.starfox.port v13 / 0.13.0-gx22-test, apksigner Verifies v2+v3 (1 firmante), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior idéntica a la NDK (27.954.176 B, mismo SHA-256; esta vez sin la diferencia de enlace de Tramo 7). Etiqueta: PRUEBA — con música por vía del juego en host, normalize TEV y resto EFB, pero sin juego real verificado en Tab S8; nunca jugable al 100%.
- Guía de prueba en la rama: android-port-base/GUIA-PRUEBA-GX22.md (adaptada del borrador Tramo 8C, con novedad Tramo 8 y checks de dispositivo pendientes; nada de ella se da por pasado sin reporte del usuario).

## Tramo 9 (2026-10-26, este tramo): DVDLow + bucles 22/95 por secciones + multi-canción + EFB decodificado + traza a DLL 5

### 9A — Audio: completitud DVDLow, stream 1367 acotado, bucles por secciones, varias canciones
- Completitud async DVDLow medida en juego real (G3, 40M despachos): `AudioStream_Play` ×2 (las dos 1367), `StartPrepared` ×0, `GetCurrentId` ×0, `DVDPrepareStreamAsync` ×0, `StopCurrent` ×1. No hay streams a medias, dobles ni perdidos en el título: el único Play del título falla antes de Prepare. La cadena Prepare→StartPrepared ya estaba cerrada en test aislado (Fase 16); se cierran dos huecos de observabilidad: `GetCurrentId` entra en la lista de hook del chassis (patch-A, 1 línea) y `StartPrepared` se observa además de contarse. El bridge sigue sonando desde Play (retrasarlo a StartPrepared rompería el camino 1301 verificado y en el título ningún Play va seguido de StartPrepared).
- Stream 1367 ACOTADO, sin resolver, sin inventar. Llamador exacto: `ObjSeq_start`, `bl AudioStream_Play` en `0x80081B6C`, id = (int16 de la acción − 1) & 0x3FFF = 1367, callback `ObjSeq_AudioStreamCallback`, dos buffers de estado distintos (dos slots ObjSeq). El juego tolera el fallo (Play=0 → la acción continúa en `0x80081B94`, sin reintento ni atasco). Descartados: 1367 no existe en `Streams.bin` (905 registros; vecinos 1353/1361/1368/1376), ningún `*1367*` en todo el disco (AN solo tiene an1301/an1353/an1361), y `sample_1367.wav` es una muestra MusyX SFX, otro namespace — mapearlo sería inventar sonido. Siguiente experimento: volcar el struct de acción ObjSeq en la entrada de Play.
- Bucles 22/95 POR SECCIONES implementados (nuevo `audio/musyx_sections.h`, generado desde `seq_host.py` + primer pase, emparejamiento exacto 1886/1886 y 49/49). 22: 12 secciones con notas, todas buclean; 95: 5 secciones, todas buclean; loopCounts crecen sin cota en 100k pasos, así que la terminación es `sndSeqStop`/cambio de canción. Limitaciones honestas: CC congelados en fin de primer pase (no se repiten por sección/vuelta) y reloj de sección huésped no replicado tick a tick (el hueco entre vueltas es puente, tras drenaje de NoteOffs).
- Varias canciones: bridge de 1 a 4 slots (secuenciador, CC, mutes y fade propios; pool de voces compartido de 32). Handles en orden de arranque = seqHandle del juego en G3 (22→1, 95→2). Fades por handle exactos: 60/500 ms → 0,4724 en 22 sin tocar 95; 100/500 ms → 0,7874 en 95 sin tocar 22. Stops por handle con fallbacks documentados (la convención de r3 de `sndSeqStop` no está verificada en juego: G3 tiene 0 llamadas; `SeqStopUnmatched()` lo delataría). 5º arranque sin slot no roba.
- Extra cerrado: llamador de 190/193. Traza directa de `Music_Trigger`: `CameraModeTitle_moveCam` con inmediatos (`li r3, 190` / `li r3, 193`, `bl Music_Trigger`). La música del título la dispara la animación de cámara del título, no el input — por eso 22 y 95 arrancan juntas sin tocar nada.
- Tests frente A: **137 checks, 0 fallos** (secuenciador 22 con 12 secciones ≥2 vueltas, 95 con 5 secciones ≥2 vueltas; bridge 22: primer pase 1886 → 3701 notas tras +600 ticks, 0 robos; bridge 95: 49 → 69 tras +300 ticks; 22+95 simultáneas 0 robos; SFX 11/11 con Tick; en juego 13/13 SFX, 0 descartados, 2 sndSeqPlayEx, 0 excepciones, idéntico a G3 Tramo 8).

### 9B — EFB: decodificado, FBO y captura en código; cableado en Frame() PENDIENTE (decisión del integrador)
- Filtro 0x53/0x54 decodificado EXACTO (simulación instrucción por instrucción de `GXSetCopyFilter` 0x80259A64): traza `0x30C1C7/0x0071CC` → taps `[7,7,12,12,12,7,7]`, suma 64; defecto `0x595000/0x000015` → `[0,0,21,22,21,0,0]`, suma 64.
- Bit 14 CORREGIDO (refuta Tramo 7/8): `GXCopyDisp` 0x80259CA8 fuerza bit 14 (`ori 0x4000`); `GXCopyTex` 0x80259E18 NO. Bit 14 = clase de destino (1 = display/XFB, 0 = textura), no gate de ejecución. TODA escritura 0x52 ejecuta una copia; las 782 "sin exec" eran copias reales a textura. `DecodeEfbCopy` expone `is_disp` y `execute = has52`; censo run39: `exec=195` (antes 29), run19: 24.922 copias, 1 reg52, idéntico.
- low52 decodificado: bits 0-1 clamp, 12-13 Frame2Field, bit 10 flag de escala Y (BP 0x4E de 9 bits), bit 11 clear, bits 7-8 gamma (crudo, siempre 0), formato textura desde `GXSetTexCopyDst` 0x80259710, bit 9 mipmap, bit 16 marcador textura (perfecto en trazas: 1 en 782 texturas, 0 en 25.451 XFB; setter NO localizado, el port lee palabras FIFO, no las construye). `0x0210` NO es fmt 1 (I8): es fmt 0x11, único compatible, bloques 8x4 probados por la tabla del helper 0x8025abb8.
- Src != dst descubierto y RECHAZADO (no inventado): callers del DOL 0x8006ca44 y 0x8006ca7c, src 640x480 → dst 320x240 (RGB565 y fmt 0x11, mipmap); la regla de remuestreo del HW no está probada, así que `PlanTexCopy` los RECHAZA en vez de escribir un 1:1 falso. Mismo patrón en run43 (248), run48 (417), run49b (451): sistemático.
- GL: FBO EFB RGBA8 + depth24, `glReadPixels` + flip vertical, despacho lineal / escala-modelo / tiled, contadores y motivos de rechazo. Conversiones RGB565 exacto salvo cuantización propia y YUY2 BT.601 limitado (blanco Y=235, negro Y=16). Captura FIFO de mundo: hook en `FeedGxFrame()` que escribe `frame_<N>_fifo.bin` + `frame_<N>_ram.bin` (24 MiB) + manifiesto JSON + texloads, con validador R1-R6; solo se activa si alguien llama a `RequestFrameCapture` (hoy nadie).
- **Cableado en Frame() NO aplicado, deliberadamente:** cablearlo exigiría exponer los eventos GxCopy al frame y dibujar dos veces o un blit que no existe, y la dirección del ratio de escala Y sigue sin resolverse (todas las copias de las 5 trazas llevan 0x4E = 232; el modelo 256/232 exigiría 533 filas de readback para un dst de 480 y rechazaría todas las copias XFB reales; el inverso 232/256 exigiría 438 y ejecutaría). Sin cableado, las copias rechazan con `sin-target-EFB` (contador, no crash) y DrawDraws sigue dibujando a pantalla como siempre: cero riesgo de regresión de pantalla. Tampoco hay disparador de captura (patrón marcador recomendado, pendiente). El discriminador de dispositivo (ancla: ratio 3,5 entre exp −1 y exp −3; fog LIN 0,5 / EXP 0,6065 / EXP2 0,7788 en t = 0,5) queda pendiente de la APK que cablee Frame() y el botón de captura.
- Tests frente B: nuevo **62/62**; regresiones Tramo 5 80/80, Tramo 6 76/76, Tramo 8 33/33, Tramo 7 variante migrada 53/53 (el Tramo 7 original da 51/53 por construcción manual sin `has52`, corrección deliberada documentada); NDK completo del frente: BUILD_EXIT=0, lib 164.338.848 B con los símbolos Tramo 9.

### 9C — Traza más allá del título: se llega a DLL 5, NO al menú
- Carrera larga con tarjeta y stick-abajo+A repetido (L1/L2, 40M despachos): **curUiDll=5, titleNextDllId=5, PC 0x8025DAD0** (mismo PC final de G3 Tramo 8-ARQ), 873 PADReads, 904 retraces, 27 SFX, partida creada de 24.576 B, 0 excepciones. Pero **NO es el menú probado**: 0 ficheros nuevos de menú/área, 0 objetos OSReport nuevos (salvo `mmUniqueIdent`), frame final casi negro (359 px no negros, dos pequeños grupos texto/icono no legibles), sin opciones visibles. **Pack C-menú y Pack C-primer-mundo: NO MEDIDOS** (no inventados).
- Discriminador FIFO por variante (12M, 10 variantes + 2 largas, 0 excepciones): firma película (texturas rotantes `0x816E2540`/`0x816DF420`/`0x80EC1E00`, mapas 0–6) frente a firma post-attract persistente (`0x80E20060` ~86% + `0x816148C0`, solo mapa 0). B/Z no cambian nada medible; stick abajo domina sobre Start mantenido (W10 clona a W1); sin input el juego nunca alcanza el trigger de música (88 lecturas). Regresiones: Pack C-título 117 / 71.705.100 B con tarjeta y 111 / 71.692.396 B sin ella, idénticos al Tramo 8; música 22/95 en 11/12 carreras; SFX L1/L2 27/27, 0 descartados; stream 1367 ×2 en todas (preexistente). Pack instalable vigente: base SAF + Tier 1 = 3.968 / 382.982.980 B. Pendiente: identidad exacta de DLL 5 (render con TEV/color real, traza de qué código escribe `curUiDll`, o navegación real en Tab S8); carrera ≥60M con tarjeta para aplicar la cola mantenida desde la lectura 1002.

### Integración Tramo 9 en esta rama
- Parches aplicados sin conflicto (audio: 6 diffs + nuevo `audio/musyx_sections.h`; EFB: 8 parches, 6 modificados + 2 nuevos `renderer/efb_copy.h` y `renderer/frame_capture.h`); Frame() y disparador de captura NO cableados por la decisión documentada en 9B.
- NDK integrado Tramo 9: libstarfox.so 28.008.048 B, SHA-256 07fefc887a06130e23ed7cef3e325702ca18334864b94035f3c79c7d546f904c, ELF64 AArch64, `android_main` y `func_80003100` en T, `BeginEfbTarget`/`CopyEfbToGuestRam`/`RequestFrameCapture`/`OnSeqPlay` en T, 0 mem_/ppc_/func_/dolrecomp_ sin resolver, 226 undefined solo sistema. APK GX23 (segundo commit de este tramo): android-port-base/app-debug-gx23-test.apk, 12.747.430 B, SHA-256 e0a51117ab11dfa821017894d354a8d4cf76c12f820a7218712a7d23c6315663, SHA-1 6978f60a5d7a577d43e6fb1fcc8f1ad9d9cf5afe, com.starfox.port v14 / 0.14.0-gx23-test, apksigner Verifies v2+v3 (1 firmante), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior idéntica a la NDK (28.008.048 B, mismo SHA-256). Etiqueta: PRUEBA — con bucles 22/95 por secciones, multi-canción, EFB decodificado y DLL 5 en host, pero sin juego real verificado en Tab S8, sin menú, sin copias EFB en pantalla; nunca jugable al 100%.
- Guía de prueba en la rama: android-port-base/GUIA-PRUEBA-GX23.md (parte B actualizada con la secuencia Tramo 9 y §5 con lo que NO esperar de GX23; nada de ella se da por pasado sin reporte del usuario).

## Tramo 10 (2026-10-27, este tramo): EFB cableado en Frame() + CC por sección/vuelta + identidad de DLL 5

### 10A — EFB: ratio Y resuelto (Tramo 9 invertido) + Frame() cableado
- Dirección del ratio Y RESUELTA con evidencia del DOL: `GXSetDispCopyYScale` (0x80259928) hace `f1 = 256.0 / arg` y `r6 = int & 0x1FF` para BP 0x4E; los tres llamadores pasan `YSCALEIN = xfbHeight / efbHeight`. El paso es `yscale/256` (upscale), no `256/yscale`. Confirmación independiente desde la cola: devuelve `((H-1)*256)/yscale + 1` más ajuste por parte impar, con (480,232)→530, (480,256)→480, (522,232)→575, (528,234)→578. Una copia XFB 640x480@232 produce 530 filas desde 480 de readback; el modelo invertido de Tramo 9 rechazaba todas las copias XFB reales, el corregido las ejecuta.
- Remuestreo, geometría RESUELTA, kernel = MODELO: el DOL en 0x8006CA14 hace `TexCopySrc(0,0,640,480)` → `TexCopyDst(320,240,fmt 4, mipmap 1)` → `GXCopyTex`; variante en 0x8006CA7C con fmt 0x11. El destino SÍ es 320x240 (el stride 0x4D lo confirma independientemente). Censo: run39 = 195 copias, run43 = 248 copias, mismas 8 formas que Tramo 9; solo dos formas son src≠dst (fmt 0x11 ×23 y RGB565 640→320 ×23). El kernel HW 2:1 no está probado por ninguna fuente: downsample como MODELO explícito (media de bloque, ratios enteros uniformes, RGB565/RGBA8). Ratios no enteros, no uniformes y fmt 0x11 siguen rechazando con contador, sin escribir bytes inventados. `dst_w` se deriva del stride, equivalente al lógico solo si es múltiplo de tile (4); se cumple en todas las copias observadas (320/32/80) y en el llamador del DOL.
- Cableado Frame() entregado: sin doble dibujado ni blit inventado — un solo dibujado al FBO EFB → copias → presentación con el quad texturizado existente (LINEAR; `glBlitFramebuffer` NEAREST queda como optimización futura fuera del parche). `Frame()`: `BeginEfbFrame(640,480)` → `DrawGxFrame` → `CopyEfbCopies` → `PresentEfb`; si el FBO falla, camino antiguo y copias del frame descartadas. Plomería: `GxParser` gana `fed_copies_` + `TakeFedCopies()` (`Copies()` histórico intacto). Readback cacheado (un `glReadPixels` 1,2 MB por frame, invalidado en `DrawDraws`/`BeginEfbTarget`, rechazado tras `ShutdownGl`). Log `runtime: efb-copy: frame ok=%d rechazadas=%d ultimo=%s` solo en frames con rechazos. Caveat: las copias a textura quedan diferidas un frame (los draws del mismo frame muestrean la textura anterior); la ejecución entrelazada por `fifo_offset` es seguimiento definido, no implementado.
- Disparador de captura entregado: marcador `<internalDataPath>/captura-frame-pedida`, sondeo cada 128 vueltas con ventana+foco+juego cargado, escena saneada a `[A-Za-z0-9_-]`, borrado antes de pedir (un solo uso), salida a `<internalDataPath>/capturas`. Sin botón Java (alcance mínimo); activación vía adb: `adb shell "echo -n titulo > /data/data/com.starfox.port/files/captura-frame-pedida"`. Sin captura automática por frame.
- Residual: 530 (SDK) vs 528 líneas XFB (±2): los buffers XFB alternan con separación 676.864 B = 528×1280 + 1024 de guarda; 530 líneas desbordarían 1536 B. Reconciliación plausible: destino 528 con registro 232 = trunc(256/(528/480)). No bloquea (destino+530×1280 cabe en 24 MiB y está acotado; el XFB no se presenta a pantalla). Discriminador: copia con filas de geometría conocida + volcado de RAM invitada en filas 528–531. Kernel HW 2:1: media de bloque es modelo, no medición. fmt 0x11 (8x4, 23 copias en run39): geometría probada, semántica de píxel sin confirmar; sigue rechazado. Sin prueba en dispositivo: nada aquí afirma píxeles reales en pantalla.
- Tests frente EFB: nueva suite Tramo 10: 45 checks, 0 fallos (YScaleLines incl. 530≠435; dirección con taps delta Y=[16,82,144,41,41]; identidad con filtro de traza; rechazos sin escribir; plan/ejecución downsample RGBA8 8x8→4x4 y RGB565 8x4→4x2 con decodificación exacta; `TakeFedCopies`; eventos reales de traza con framebuffer constante — geometría real, píxeles NO reales — XFB ejecuta con 530 filas, textura 640→320 ejecuta con 153.600 B, fmt 0x11 rechazado). Regresiones contra código nuevo: Tramo 9 62/62, Tramo 8 original 33/33, Tramo 7 migrada 53/53, Tramo 6 (variante T7) 76/76, Tramo 5 original 80 ok. Nota honesta: el original `tramo6-tev/test_tramo6.cpp` (71 checks) da 5 fallos contra el código actual, pero son diferencias de semántica introducidas ya en Tramo 7 (escala de matriz, POS-postmtx, fog), no una regresión de Tramo 10; la comparación válida es la variante T7, que pasa 76/76. NDK del frente (r28c, arm64-v8a, API 34): lib compilada y enlazada, 0 warnings, 0 errores, 153.961.320 B (build del frente con sus ficheros, no la lib integrada).

### 10B — Menú: identidad exacta de DLL 5 (corrección a Tramo 9) + carreras 60M
- `curUiDll` NO es un `dll_id` de la wiki: es un índice en `gModelEngineUiDllResourceIds` (0x802C7788, 18 entradas, idéntica en el DOL del disco y en RAM). `loadUiDll(idx)` hace `Resource_Acquire(tabla[idx], 1)`. El `dll_id` 5 de la wiki («Sky») no tiene nada que ver con `curUiDll=5`. Tabla: índice 2 → 50 TitleScreenInit (pantalla inicial); 4 → 52 TitleMenu (menú principal, initialise 0x80117480, run 0x80116AF4); 5 → 53 SaveSelectScreen (selección de partida, initialise 0x8011B900, run 0x8011B364, render 0x8011AF60); 6 → 54 EnterSaveNameScreen (run 0x8011BDB4); 7 → 55 OptionsScreen (frameStart 0x8011D59C).
- Cadena de prueba del estado final (idéntica en ambas carreras): `curUiDll=5`, `prevUiDll=6`, `curRes=0x8033A24C` = slot de la tabla C de recursos para el DLL 53 (base 0x8033A178 + 53×4), cuyo contenido `0x8031C0A4` = descriptor `SaveSelectScreen_funcs` + 24, con vtable `[+4]=SaveSelectScreen_run`, `[+8]=frameEnd_nop`, `[+12]=SaveSelectScreen_render`. El estado final NO es TitleMenu (su slot es `0x8031BB7C`, run `0x80116AF4`).
- Quién escribe qué (estático + traza PCTRACE, chassis sin parchear): `TitleMenu_run` escribe `gTitleMenuNextDllId` según selección: sel. 0 → 5, sel. 1/2/3 → 7 (Options), y al agotarse `gTitleMenuLoadDelay` llama `loadUiDll(titleNext)` en `0x8011702C`. `loadUiDll` pone `pending=arg+1`; la función de frame lo consume (`cur=pending`, `prev`=viejo). Por eso los muestreos muestran `pend=5` ~3M despachos antes del cambio. `setCurUiDll` (único llamador estático `0x8011C39C` en EnterSaveName) nunca se ejecutó en ninguna carrera (0 PCTRACE). `TitleMenu_setSelection`: 0 llamadas — la selección nunca se movió de 0. Los 5 `loadUiDll` de cada carrera, por `lr`: `2` (init) → `4` (`TitleScreenInit_frameStart`, `lr 0x801162D4`) → `5` (`TitleMenu_run`, `lr 0x80117030`) → `6` (`saveFileSelect_init`, `lr 0x8011A824`) → `5` (`EnterSaveNameScreen_run`, `lr 0x8011C334`).
- Diferencia 4/5/menú real: 4 = menú principal (ya superado); 5 = pantalla de slots (un menú posterior, no el principal, no el juego); desde SaveSelect falta abrir una partida existente o crear una en slot vacío. La ausencia de ficheros de disco nuevos NO argumenta contra SaveSelect: lee la tarjeta, no el disco. La etiqueta literal de la opción 0 no se decodificó (no afirmar «New Game»).
- Carreras 60M (0 excepciones, FIFO sin desborde con tope 512 MiB solo-harness; harness = Tramo 9 + solo observación, `force_trigger=0`, tarjeta fresca, `SFA_PCTRACE=1`). Secuencia idéntica en R1 y R2 (muestreo, `padread` entre paréntesis): 3M `0→4` (10) → 20M `pend 0→5, titleNext 0→5` (339) → 23M `4→5` SaveSelect (509) → 25M `5→6` EnterSaveName (527) → 35M `pend 0→5` (736/737) → 37M `6→5` SaveSelect (846) → 37M→60M sin más transiciones de índice. R1 (repite Tramo 9 L1/L2 a 60M; la cola mantenida desde la lectura 1002 esta vez SÍ se aplicó): 1.216 PADRead / 1.247 retraces, 47 SFX / 2 sndSeq, 148 DVDOpen, 201.023 texloads, FIFO 306.270.912 B, PC final `0x8025C4B4` (`GXSetTevColorOp`, fin de rebanada en render). R2 (nueva, Start mantenido + fases A / stick-abajo+A / D-pad-abajo+A / B / Z / mantenido desde 1002): 1.056 / 1.087, 41 SFX / 2 sndSeq, 148 DVDOpen, 210.013 texloads, FIFO 312.586.116 B, PC final `0x8003E55C` (`renderOpMatrix`). La variante secuenciada NO cambió el camino: mismas 6 transiciones y mismos `padread`. Dentro de SaveSelect tras 37M sí hay actividad (R1: panel 1→0, slot 0→1→2; R2: panel 1, slot 0→1), pero nunca `loadUiDll(4)`, ni otro `loadUiDll(6)`, ni capítulo, ni lanzamiento (`quit=0, launch=0, chapter=0`). SFX: misma familia que Tramo 9 (379, 407, 415, 417, 775, 776, 777), solo más repeticiones, ninguna familia nueva, `DroppedSfx=0`. Música 22+95 intacta. OSReport: 39 líneas distintas, sin líneas nuevas (solo 2 contadores `mem`/`slot`). Tarjeta: mismo fichero `'Star Fox Adventures'` 24.576 B, `saveByte=1` (R1: más ciclos CARD, Read ×24 frente a ×18).
- Causa del estancamiento NO probada (hipótesis, no hecho): la confirmación probablemente exige flanco (Just) y el botón mantenido desde 1002 no genera flancos nuevos. Hueco experimental probado: ninguna carrera pulsó (soltar + volver a pulsar) DENTRO de SaveSelect — los pulsos terminan en la lectura 1000. Próximo host: pulsos después de `cur==5` (por despacho/estado, no por lecturas previas). Frame final (render host, SIN TEV/color real; magenta = placeholder): R1 9.266 px no negros (todos en cuadrante 320×240: panel grande + filas de texto pequeñas + iconos, texto NO legible como opciones); R2 403 px (como los 359 de L2). Parse GX OK en ambas. No demuestra menú legible.
- ¿Se llegó al menú? Al principal (TitleMenu): sí, y se superó. A una pantalla de menú posterior (SaveSelect, dos veces, más EnterSaveName): sí — más que Tramo 9. A un menú legible con opciones visibles: NO demostrado en host. Al juego: NO. Corrección a Tramo 9: su «NO es el menú» era impreciso — SaveSelect SÍ es una pantalla de menú, y sus «0 ficheros nuevos» no argumentaban en contra.
- Pack C: NO hay Pack C-menú ni Pack C-primer-mundo (no inventados). `pack.csv` de R1 y R2 idéntico en lista al de Tramo 9 L2 (`diff` limpio): Pack C-título reconfirmado: 117 ficheros / 71.705.100 B (con tarjeta). Pack instalable vigente sin re-medir: base SAF + Tier 1 = 3.968 / 382.982.980 B. Razón estructural: SaveSelect/EnterSaveName no abren ficheros de disco nuevos.
- Guía exploratoria Tramo 10 en la rama: `android-port-base/GUIA-EXPLORATORIA-GX23-TRAMO10.md` (título → attract → Start mantenido → slots, con sesiones separadas por botón, toques con soltar, nunca mantenido, cada una con su `boot.log` copiado ANTES de relanzar + logcat + foto; parar y reportar en slots, en nombre, en retorno al título o en capítulo/mundo, sin avanzar al juego sin reportar). La guía GX24 incorpora esa secuencia en su §2.

### 10C — Audio: CC por sección/vuelta, reloj huésped, r3 de sndSeqStop
- Regla probada en el huésped: vuelta 1 == vuelta 2 exactamente, y vuelta 1 == primer pase filtrado a `time >= loopPoint`. 22: 1694 notas de vuelta (192 de intro no se repiten) y 536 CC (sec1/sec3 80 CC7 cada una; sec8 236 CC7 + 29 CC10; sec11 rampa CC7 1→111; resto 0). 95: 47 notas y 202 CC, con periodos y fases propios por sección (6144/6144/30624/29088/27552). El modelo Tramo 9 (congelado) erraba 117 notas/vuelta en volumen y 28 en pan en 22 (sec8 casi muda: congelado 1 frente a trayectoria hasta 59), y 21 en pan en 95.
- Reloj huésped, divergencia medida y corregida: Tramo 9 anclaba a primera nota y esperaba drenaje de NoteOffs (desalineación de ~36 s entre sec0/sec10 de 22; periodos erróneos en 95). Ahora: entrada alineada en fase (`loop_end` o `loop_end + k·periodo`), NoteOffs que cruzan fronteras, catch-up CC por (midi, cc) y salto de notas más viejas que el bloque. Error residual < 1 bloque Tick (85,33 ms), no acumulativo. Coste único en 95: hasta 4 notas por sección perdidas antes de la transición (~79,5 s); después, fase exacta para siempre.
- Bug real hallado por los tests y corregido: en la llamada que cruza una frontera, los eventos de la vuelta vieja vencidos en ese bloque se perdían (el CC 111 final de la rampa de sec11, fire 104424, frontera 104448 — el slot quedaba en 110 para siempre en la vuelta 2). La fase ahora emite vuelta vieja → cruce → vuelta nueva. T4 lo prueba (CC7(11) = 111 tras la frontera).
- r3 de `sndSeqStop` VERIFICADA en código huésped, no hipótesis: `r3 = seqHandle` (ID en nodo+12, valor devuelto por `sndSeqPlayEx` y guardado en `chan+4`): `seqStop` hace `r3 & 0x7FFFFFFF` y busca en dos listas; sin coincidencia no hace nada; con bit 31 solo limpia un flag (no detiene). Los 3 llamadores directos pasan `chan+4`; `sndSeqVolume` usa la misma búsqueda con su r5. Implementado: flag/bit-31/`-1` → no detiene nada, cuenta en `SeqStopFlagged()`, no dispara el fallback. Sigue sin verificar dinámicamente en juego (0 llamadas en G3; pata dinámica = tests sintéticos/host T6). El fallback de handle 0 sigue siendo heurística; el significado del flag con bit 31 se desconoce.
- 99/74 NO convertidos (decisión deliberada: cambiaría R3/R4 verificados solo con el análisis nuevo). Medido para el tramo que los convierta: periodos huésped 6144 (99) y 26112 (74) frente a 7672/29179 del bucle de segmento (+24,9%/+11,7% lentos), fases perdidas y fuga de CC de ventana en 74.
- Tests frente Audio: suite nueva `tests/test_tramo10.cpp`: 124 checks, 0 fallos (T0 tablas, T1a/T1b sintéticos, T2 22 real, T3 95 real con catch-up 0:112 1:104 2:127 3:0 4:127, T4 bridge con valores CC exactos por tick, T5 fades 0,4724/0,7874, T6 stops, T7 99/74/5). Regresión Tramo 9 contra código parcheado: 137 checks, 2 fallos, ambos esperados: S3 sintético (su sección A no tiene tablas de vuelta; con el modelo nuevo, sin tablas no hay bucle — lo sustituyen T1a/T1b). Pasan R0 (SFX 11/11), R1 (13→841), R2 (1301), R3/R4, R5, S1 (ahora t=200 s), S2 (t=240 s), L1/L2, M1–M5, A1–A3. Línea base sin parche reproducida: 137 checks, 0 fallos. Re-verificado contra el árbol integrado: 124/0 (parches idénticos a `src-patched/` por `diff`).
- Limitaciones exactas: CC19 en 95 sec2/3/4 se repite por vuelta (11/7/8 eventos) y NO está modelado (significado DSP desconocido). Bucles 99/74 no son exactos tal cual (periodo y CC de ventana del modelo Tramo 8). Ningún `sndSeqStop` real observado en juego; fallback de handle 0 es heurística, no comportamiento del juego. 95 pierde sus vueltas previas a la transición (~79,5 s); sin prueba en hardware (ADB caído) ni APK en el frente; todo es host. S3 de Tramo 9 cambió por diseño (sin tablas de vuelta no hay bucle).

### Integración Tramo 10 en esta rama
- Parches aplicados sin conflicto: EFB 10 parches (uno por fichero: `gx.h`, `gx.cpp`, `runtime.h`, `runtime.cpp`, `gx_gl.h`, `gx_gl.cpp`, `efb_copy.h`, `renderer.h`, `renderer.cpp`, `native-lib.cpp`; verificados byte a byte sobre copias prístinas por el frente) + Audio 4 diffs + `audio/musyx_sections.h` v2 completo (sin el fichero v2, las secciones se saltan y la música terminaría tras el primer pase — T0 lo detecta). Menú aporta harness/trazas/guía, no código de juego. Total: 15 ficheros modificados + guía exploratoria nueva.
- NDK integrado Tramo 10: libstarfox.so 28.049.096 B, SHA-256 39f6704a9e6fb5b9c26a7309450c6758137952e6e7f7dbead01b08b947a0c453, ELF64 AArch64, `android_main` y `func_80003100` en T, símbolos nuevos presentes (mangleados: `TakeFedCopies`, `CopyYScaleLines`, `BeginEfbFrame`, `CopyEfbCopies`, `PresentEfb`, `RequestFrameCapture`, `OnSeqPlay`, `OnSeqStopHandle`), 0 `mem_/ppc_/func_/dolrecomp_` sin resolver, 226 undefined solo sistema. APK GX24 (segundo commit de este tramo): android-port-base/app-debug-gx24-test.apk, 12.755.622 B, SHA-256 55c34a8ca35d90ba96f5703186525a31d2c6d92fe86b6e3cfee319bc5728e497, SHA-1 c3e2c7cabaac3263811b25b0686c24751f7ccf6e, com.starfox.port v15 / 0.15.0-gx24-test, apksigner Verifies v2+v3 (1 firmante), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior idéntica a la NDK (28.049.096 B, mismo SHA-256; esta vez sin diferencia de enlace). OJO: GX24 lleva otro certificado de firma de prueba que GX23 (SHA-256 del certificado ef9b793a… frente a 6c88665f…): NO actualizará sobre GX23 instalada; desinstalar GX23 antes de instalar GX24. Etiqueta: PRUEBA — con EFB cableado en Frame(), CC por sección/vuelta y DLL 5 identificada, pero sin juego real verificado en Tab S8, sin menú legible, sin rumble positivo verificado; nunca jugable al 100%.
- Guías en la rama: android-port-base/GUIA-PRUEBA-GX24.md (nueva, con §2 actualizado a SaveSelect y §5 actualizado a Frame() cableado) y android-port-base/GUIA-EXPLORATORIA-GX23-TRAMO10.md (borrador Tramo 10). Cuestión 1367 sigue abierta (acotada, no resuelta).

## Tramo 11 (2026-10-27, este tramo): flanco en SaveSelect lanza el mapa + 99/74 por secciones + CC19 + EFB 529/Z8/mismo-frame

### 11A — Menú: el flanco en SaveSelect SÍ lanza el mapa; nuevo bloqueo: excepción en la canción 94
- Método nuevo: disparo por ESTADO, no por lecturas ni despacho fijo. El harness comprueba curUiDll/prevUiDll en cada rebanada de 100k y, en la primera que ve cur==5 && prev==6 (segunda entrada en SaveSelect, tras EnterSaveName), sustituye el guion PAD: soltar 20 lecturas, un pulso de 6 lecturas, soltar para siempre. En las 6 carreras el disparo cayó en disp 36.400.000 / padread 840 (pulso en lecturas 860–865). `launch` pasa de 0 (muestra 38M) a 1 (muestra 39M).
- Discriminador cerrado: confirmar en SaveSelect (panel 1) exige flanco de A o Start con el stick analógico centrado (los bits de D-pad no estorban). Stick abajo + A = navegación (slot 0→1, 60M atascado). B = cancelar (panel 1→0, SFX 416 ×1 nuevo, 60M atascado). v1 (A), v2 (Start) y v4 (D-pad↓+A) son la misma trayectoria byte a byte (misma FIFO 196.799.288 B, mismo pack, mismas familias SFX, mismos CARD, 74 cambios OSReport): el juego no distingue A de Start ni de D-pad+A tras el flanco. Confusión declarada: la duración del pulso (6 lecturas) no se aisló de la de Tramo 10 (2 lecturas).
- Cadena del lanzamiento (DOL+capstone, verificada a mano): SaveSelectScreen_run panel 1 → saveSelectOpenFile → … → loadMapForCurrentSaveGame (0x800EA020) → loadUiDll(1) → objeto UIController (frameStart 0x800DA1E8, frameEnd 0x800DA1B8, render 0x800DA138). Sus únicos llamadores directos son SaveGame_gplayGotoRestartPoint y SaveGame_gplayGotoSavegame; PCTRACE no los lista, así que no se distingue cuál corrió (GotoSavegame es el candidato por coherencia, no un hecho). loadUiDll(4) nunca aparece tras el disparo (4 solo en el arranque): ningún retorno al título. `chapter` = 0 en los 6 finales; no se alcanzó selección de capítulo.
- Pack C-mapa CANDIDATO (parcial, NO mínimo, NO «pack del primer mundo»): 139 ficheros / 78.252.684 B; los 22 nuevos (+6.547.584 B) son frontend.romlist.zlb, warlock.romlist.zlb y warlock/* + shipbattle/* (ANIM.BIN/.TAB, MODELS.bin/.tab, TEX0/1.bin/.tab, mod14/mod16.tab y .zlb.bin). No se afirma qué capítulo/área representan. Pack C-título reconfirmado (117 / 71.705.100 B, v3/v5). Pack instalable vigente sin cambios: base SAF + Tier 1 = 3.968 / 382.982.980 B.
- Nuevo bloqueo (excepción): tras sndSeqPlayEx grupo 45 / canción 94 (bankData=0x810A9800), InitTrackEvents → GenerateNextTrackEvent lee fuera de rango: exception=1 (DSI simulada del shim), PC de parada 0x8026F200 (posterior a la llamada, no la instrucción que falla), DAR 0x479E7A63 reproducido exacto en v1-a-dar. El valor aparece como dato en el objeto de música en RAM final (base 0x803B5380, structs +0x124), coherente con perseguir datos de secuencia como punteros; pista e instrucción exactas NO identificadas (la RAM final es posterior a la excepción). El bridge anota la 94 «sin tabla verificada» (hueco de audio host, distinto del fallo huésped). Fallos nuevos de apertura (12 distintos vs 5 en Tramo 10: animcurv/voxmap de warlock/shipbattle) no se presentan como causa de la excepción. Corrección: las muestras de mundo (pasos, rex) al final de v1 también están en Tramo 10 R1; son notas de las secuencias del título, no evidencia de juego en el mundo. Frame host sigue sin TEV/color real: no se afirma menú legible ni juego visible.
- Guía exploratoria Tramo 11 en la rama: android-port-base/GUIA-EXPLORATORIA-GX24-TRAMO11.md (título→aviso→SaveSelect, confirmar con A/Start a toque con el stick suelto, una sesión por botón, parar ante cualquier cambio tras confirmar).

### 11B — Audio: 99/74 buclean por secciones; CC19 = pan surround (estado, sin mezcla)
- 99 y 74 SÍ buclean por secciones (verificado, no forzado; el generador aborta si falla cualquier comprobación): vuelta 1 == vuelta 0 filtrada a time >= loopPoint (tuplas exactas), vuelta 2 == vuelta 1, mismo para CC, y loop_end único en todas las transiciones medidas. 99 (gid 54, BPM 60): sec0 loopPoint 3072 / periodo 6144 / 2 notas / 1 CC {3074,0,7,100}; sec1 loopPoint 1536 / periodo 6144 / 2 notas / 1 CC {1538,1,7,100}. Total 4 notas, 2 CC; caen 2 intros (time 10). El bucle de segmento viejo (7672, +24,9 % lento) queda retirado. 74 (gid 18, BPM 120): 3 secciones, periodo común 26112, fases escalonadas (loopPoints 3072/4608/6144), 4 notas cada una, CC 231/231/216. Total 12 notas, 678 CC; caen 3 intros (time 8). El segmento viejo (29179, +11,7 % lento, con fuga de CC de ventana) queda retirado.
- CC19 en 95 DETERMINADO: pan surround, no volumen/pan/pitch/eco. Evidencia: seq.c:1253 solo lo guarda en el banco MIDI (sin constante con nombre en mcmd.h); el único lector en el barrido del pool 49 es el opcode 0x47 = SelectSource (mcmd_exec.c:1149-1150, ctrl 19, fuente inpSurroundPanning): 82 registros, todos 0x47, 0 ADSR-desde-ctrl; synth.c:838 lo pasa como surroundPan separado del pan estéreo. En 95 vuelta 1: sec2 11 / sec3 7 / sec4 8 eventos, todos valor 64, cada delta CC19→CC10 siguiente exactamente 96 ticks. Macros 966 (803, sec0/1), 1298 (1017, sec2) y 1300 (1019, sec4) leen ctrl 19; 1299 (1018, sec3) no lo lee: sus CC19 son inertes. Lo mismo para 99 (macro 949, ambas secciones) y 74 (macro 674, las 3 secciones): sin CC19 de vuelta, así que en bucle el huésped congela la intro (99: 16/16; 74: 0/0/127). Caveat: la ganancia 100× frente a 1× depende de la fórmula de SFA-Decomp (recuperación, no fuente retail) y es de segundo orden; la conclusión cualitativa no depende de ella. Modelo entregado: solo estado (cc19[16] + SeqCc19Of), sin cambio de mezcla — el bridge es estéreo y no tiene bus surround; mapearlo sobre el pan corrompería CC10. Contadores CC19 de 95 corregidos a 9/4/6 (la primera v3 llevaba 8/3/5 y cortaba el último CC10 de 95 sec2/3/4).
- Suite host: 186 checks, 0 fallos. Regresiones 22/95 íntegras (ticks exactos 844–1684, fades 0,4724/0,7874, stops por handle, track 5 = 281). Cambios esperados, no regresiones: CC de vuelta de 95: 202 → 205; catch-up de 95: 5 → 8 eventos; viejo T7 (99 = 14, 74 = 27 notas) obsoleto por diseño y sustituido por U7. Limitaciones: todo es host/sintético (sin APK nueva en el frente, sin ejecución en Tab S8, nada es música verificada en juego); CC19 de primer pase NO está en las tablas planas (95: 28 eventos; 99: 2; 74: 3): el bridge informa 0 donde el huésped tiene 16/16 (95 sec0/1, 99) y 0/0/127 (74; sec2 difiere: huésped 127 frente a bridge 0); 95 sigue perdiendo sus vueltas previas a la transición (~79,5 s); ningún sndSeqStop real se ha observado en juego.

### 11C — EFB: 529 resuelto, Z8 resuelto, mismo frame implementado; kernel 2:1 acotado
- Discriminador 530/528 RESUELTO a 529 (sin dispositivo). Tres cierres independientes: la cola de GXSetDispCopyYScale (DOL 0x80259998–0x802599E0) con la polaridad corregida (== 0, no != 0 como en Tramo 10); el modo PAL real (0x802CBC68: efb 480, xfb 528 → yscale 232 → ((479*256)/232)+1 = 529, sin +1 porque 480 % 29 = 16); y el pitch XFB real (0x804A5500 − 0x80400000 = 0xA5500 = 529×1280 exactos — el «528×1280 + 1024 de guarda» era aritmética incorrecta). Consecuencia: GX24 escribía 530 filas (una línea de más, invisible en pantalla pero RAM XFB incorrecta). Parche 01 + tests con sentinela. Un comentario obsoleto en efb_copy.h que aún decía 530 se corrigió en la integración.
- Kernel 2:1 NO resuelto, acotado con discriminador exacto. dump_filter sobre run39: el mismo filtro (taps [7,7,12,12,12,7,7]) está vivo en las 8 formas de copia. El manual GX §8.9 dice que el filtro de copia aplica también a copias a textura (y un box opcional para LOD); correlación nueva: el bit 9 de 0x52 vale 1 solo en las dos copias con downsample. Como el 7-tap es vertical (1-D), el discriminador separa ejes: tablas exactas para impulso par/impar en vertical (punto 255 / box 127 / 7-tap [27,47,27] par y [27,47,47,27] impar) y horizontal (punto/box), tolerancia ±6 por cuantificación RGB565. Falta una salida de referencia (Dolphin o volcado RAM) para decidir; el modelo box se mantiene etiquetado MODEL.
- Formato 0x11 RESUELTO como copia Z8, decodificador entregado. Cadena completa: captureReflectionTextures (0x8006CA14) → GXSetTexCopyDst(fmt 17) → GXCopyTex fuerza PE formato 3 = Z24 (YAGCD PE_CONTROL 0x43) → destino = ReflectionDepthTexture, muestreada como I8 real (fmt 1 en textureAlloc). Geometría FIFO idéntica a I8; el discriminador es la escritura PE_CONTROL (BP 0x00 con bits 0-2 == 3) adyacente a la copia (sin draws ni DL entre medias; el flag se consume por disparo). Validado con el parser real en run39: 23/23 Z adyacentes, 0 falsos positivos. Decodificador: lectura de profundidad del FBO (renderbuffer DEPTH_COMPONENT24 ya existente) + downsample modelo + tiles I8 (inverso exacto de GxDecodeTexture, probado por round-trip). Byte de profundidad = alto (trunc(avg*255)), con argumento y falsador documentados (rampa monótona vs diente de sierra).
- Copias en el mismo frame IMPLEMENTADO. GxMergeSegments (nuevo, puro) + Frame() entrelazado por fifo_offset (draws antes que copias en empates; ties de DL documentados). Sin regresión por construcción (sin copias = orden antiguo; copias tras draws = orden antiguo exacto) y fallback intacto byte a byte.
- Suite nueva: 74/74. Parches: aplican limpios con patch -p1 y reproducen los ficheros byte a byte (verificación del frente). Regresiones: Tramo 10 36/45 (los 9 fallos son exactamente los valores corregidos 530→529 etc., esperados); Tramo 9 62/62, Tramo 8 33/33, Tramo 7 53/53, Tramo 6 76/76; Tramo 5 74/75 con el único fallo preexistente (el binario original de Tramo 10 falla igual: falta el dir run19). La suite Tramo 10 debe actualizarse a los valores 529 en el próximo tramo (no se modificó aquí para dejar constancia). NDK del frente (arm64-v8a, API 34, r28c): éxito (lib enlazada 154.346.368 B en el build del frente, 0 errores); el primer intento detectó un d0 duplicado en el parche 08 (el test host no compila gx_gl.cpp por el GL); corregido, parches regenerados y re-verificados. Es verificación de compilación/enlace, no de ejecución ni de APK. Caveats: el kernel HW 2:1 y el byte de profundidad siguen siendo MODELO/argumento, no medida; ningún APK Tramo 11 se había construido en los frentes (la APK GX25 se construye en la integración, abajo).

### Integración Tramo 11 en esta rama
- Parches aplicados sin conflicto: audio (musyx_sections.h v3 completo + 4 diffs; verificados byte a byte contra src-patched/audio del frente; suite del frente re-ejecutada: 186/0) + EFB (8 parches; suite del frente: 74/74) + 1 corrección de comentario obsoleto en efb_copy.h (530→529). Menú aporta harness/trazas/guía, no código de juego. Total: 13 ficheros (12 modificados + gx_merge.h nuevo) + guía exploratoria nueva. NDK integrado (abajo) y APK GX25 (abajo). Cuestión 1367 sigue abierta (acotada, no resuelta).

### APK GX25 (Tramo 11, PRUEBA — NO jugable)
android-port-base/app-debug-gx25-test.apk, 12.772.006 B, SHA-256 737b7b1e35386e123c7ebcda10629fcdae0e983e297290c00f8b94cb79e7fb44, SHA-1 d4fbdb9d9ede071e2ffc9108ac18a83ff33845bc, com.starfox.port v16 / 0.16.0-gx25-test, apksigner Verifies v2+v3 (1 firmante, alias test), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior 28.087.912 B, SHA-256 6f039d1c216f8eedab5fe2d230c131d7b64dac50a5db39bcd414af94246e2458 (idéntica al build NDK de este tramo: ELF64 AArch64, android_main y func_80003100 en T, símbolos nuevos TakeFedCopies/CopyYScaleLines/GxMergeSegments/ReadEfbDepth/SeqCc19Of presentes, 0 mem_/ppc_/func_/dolrecomp_ sin resolver, 228 undefined solo sistema). Build manual (Gradle daemon con fallo conocido): javac --release 17, d8, aapt2 link --min-sdk-version 26 --target-sdk-version 34 --version-code 16 --version-name 0.16.0-gx25-test, libstarfox.so + libc++_shared.so, zipalign -f 4, firma keystore de prueba alias test (fuera del repo, NO commiteado). OJO: GX25 lleva otro certificado de firma de prueba que GX24 (SHA-256 del certificado 5c6ac1b3…a2): NO actualizará sobre GX24 instalada; desinstalar GX24 antes de instalar GX25. Etiqueta: PRUEBA — con flanco SaveSelect→mapa en host (cortado por la excepción de la canción 94), 99/74 por secciones, CC19 como estado surround, EFB 529 + Z8 + mismo frame, pero sin juego real verificado en Tab S8, sin menú legible, sin mundo, sin rumble positivo verificado; nunca jugable al 100 %. Guías: android-port-base/GUIA-PRUEBA-GX25.md (nueva) y android-port-base/GUIA-EXPLORATORIA-GX24-TRAMO11.md (Tramo 11). Cuestión 1367 sigue abierta (acotada, no resuelta).

## Tramo 12 (2026-10-27, este tramo): excepción canción 94 resuelta (modelo ARAM) + CC19 de primer pase + suite Tramo 10 a 529 — APK GX26 (PRUEBA, NO jugable)

### 12A — Canción 94: causa exacta, parche ARAM, nuevo bloqueo unknown_pc
- Causa exacta (reproducida, no inferida): pista 19, instrucción 0x8026E818 (`lhz r0, 8(r3)`) en `GenerateNextTrackEvent`; primer fallo en 0x479E7A6B (puntero basura 0x479E7A63 de la entrada de pista 19). El DAR de Tramo 11 (0x479E7A63) era el segundo fallo, no el primero: el shim no aborta el chunk tras `exception=1`, así que la RAM final engañaba. Corrección a Tramo 11: pista e instrucción exactas ya están identificadas.
- Causa raíz: el HLE de Tramo 8 entregaba la lectura ARQ sin copiar ningún byte, así que `bankData` de la 94 (0x810A9800) contenía basura vieja del búfer; `seqStartPlay` interpretó esos bytes como tabla de pistas ([bank+0]=0 → tabla leída desde el propio búfer) y construyó punteros basura. No era corrupción de fichero: el banco real es el arreglo `midi.wad` de la canción (offset 0x130600, 6.504 B, ARAM 0x00FF9840).
- Parche mínimo integrado (solo adición, 128 líneas en `gamecube_runtime/hle.cpp`, 0 borrados): modelo ARAM host de 16 MiB (tamaño real de ARAM en GameCube). Captura subidas MRAM→ARAM en el gancho `kArqPostRequest` (args leídos de registros, no de la estructura, porque el gancho corre antes que el chunk huésped) y copia ARAM→MRAM en la entrega de lecturas antes del callback. Solo copia bytes que el propio juego subió antes; un rango ARAM nunca escrito copia ceros (comportamiento previo, sin regresión). Error propio documentado en el camino: la primera versión invertía origen/destino en subidas y solo "cero-izaba" el banco (también eliminaba la excepción, pero por el motivo equivocado); corregido tras verificar que las subidas cubren la región midi completa (0xEC93E0..0x1000000, exactamente 1.272.864 B).
- Prueba definitiva (carrera v1-a-aram2, mismo guion v1-a, tarjeta fresca): 0 MEMFAIL, 49.571.763 despachos (+8.767.007 vs Tramo 11), las tres lecturas con `fuente_escrita=1` y `primer_u32=0x58` (22: ARAM 0x00F130E0 → MRAM 0x80FA5EE0, 17.120 B; 95: 0x00FFB1C0 → 0x810DE460, 3.520 B; 94: 0x00FF9840 → 0x810A9800, 6.528 B), y en RAM final el bankData 94 es byte a byte idéntico a `midi.wad` (0/6.504 diferencias), canal 2 con track 94, seqHandle 3, status 1: la canción huésped está activa al final. Trayectoria hasta el disparo idéntica (disp 36.400.000, padread 840, pulso 860–865, `loadUiDll(1)` desde 0x800EA0B4, launch=1, chapter=0). SFX sube a 39 (nuevos como 661 `SFXbaddie_zyck_lash`), sndSeq 3, arq_entreg=3, FIFO 241.539.382 B sin overflow. El bridge sigue sin tabla verificada para la 94 (hueco de audio host separado; no inventa sonido).
- Pack C-mapa re-medido: 142 ficheros / 82.413.172 B (+3 ficheros, +4.160.488 B vs el candidato: `gametext/ShipBattle/English.bin` 28.980 B, `streams/GB/Intro.adp` 4.128.768 B — stream id 105 —, `gametext/Sequences/20105_English.bin` 2.740 B; mismos 12 fallos de apertura). Sigue siendo CANDIDATO PARCIAL — prohibido presentarlo como pack del mundo: la traza muere en el nuevo bloqueo, sin mundo estable, sin capítulo.
- Nuevo bloqueo (NO resuelto): `unknown_pc 0x80000100` (RAM ahí todo ceros; aparece también con el parche de ceros, así que no depende del contenido del banco), con `chapter=0`, `curUiDll=1`, `pendingUiDll=0`. Pista principal para el siguiente tramo: `osreport.log` dominado por `mm Error: No more slots available, region 1/2 used 849 avail 850` junto a `LOADED OBJECT staffAnim/Override` — posible asignación fallida antes del salto. Experimento propuesto: instrumentar el salto indirecto final + correlacionar con el primer error `mm`. Pack instalable vigente sin cambios: base SAF + Tier 1 = 3.968 / 382.982.980 B.

### 12B — Audio: CC19 de primer pase en las tablas planas; mezclador surround NO integrado
- Parche integrado (33 inserciones, 0 borrados, solo `audio/musyx_notes.h`; verificado byte-idéntico al resultado del frente): 95 (gid 49) 431 → 459 eventos planos (+28: sec0 6×16, sec1 4×16, sec2 11×64, sec3 7×64, sec4 8×64); 99 (gid 54) 44 → 46 (+2: (6,0,16), (4,1,16)); 74 (gid 18) 803 → 806 (+3: (5,0,0), (5,1,0), (5,2,127)). Notas, CC7/CC10, tablas de bucle, `musyx_seq.cpp` y bridge sin cambios (el estado `SeqCc19Of` ya existía; faltaban los eventos). Verificación huésped: el generador prueba que la subsecuencia CC7/CC10 plana de cada midi ES la vuelta 0 salvo exclusiones conocidas y listadas (eventos de frontera/dedup que ya viven en las tablas de bucle, nunca CC19); el primer CC19 de cada midi precede a su primera nota; las entradas a bucle no cambian (9212 / 32256 / 30528).
- Caso 74 sec2, explicado y corregido: no era otro valor ni un preset enmascarado — el bridge daba 0 porque su slot arranca con `cc19.fill(0)` y ninguna tabla contenía CC19 para 74, mientras el huésped emite (5,2,127) y lo congela (macro 674 lee ctrl 19; vueltas sin reemisión). Ahora el bridge da 127 desde el primer pase y lo mantiene en bucle. Los 0 de sec0/sec1 también eran hueco sin modelar; ahora son eventos evidenciados (5,0,0)/(5,1,0). Lo mismo cierra 95 sec0/1 (16/16, antes 0/0).
- Mezclador surround: diseñado y prototipado en host, NO integrado (decisión con evidencia). Prototipo standalone (buses L/R/S separados, S nunca sumado a L/R, ley de pan exactamente la del bridge): en modo STEREO, CC19 no toca L/R y S=0; en modo SURROUND, CC10 no cambia y CC19 solo alimenta S; captura por voz en el note-on. Por qué no se integra: (1) sin salida para S — el bridge/audio es estéreo y el huésped tiene 3 salidas (volL/volR/volS); plegar S sobre L/R cambiaría la mezcla actual y contradice al huésped (en estéreo, `lastSPan = 0`); (2) escala sin resolver — y corrección a Tramo 11: leyendo el fuente SFA-Decomp (recuperación, no retail), el resumen "≥2 satura" es la variante ingenua, no el código literal: el literal trunca a u16 y NO es monótono (cc19 5 → trasero, 6 → 1.381); literal vs 1× discrepan en los valores reales (16 = centro literal o 0.238 frontal 1×; 64 = trasero literal o centro 1×; 127 = trasero en ambas); elegir hoy sería inventar; (3) flag por macro pendiente: 95 sec3 lleva cc19=64 en el canal pero su macro 1299 no lee ctrl 19, así que su S huésped es 0 — un mezclador por canal lo sobre-renderizaría sin ese flag. No se ha mapeado nada sobre el pan como "surround".
- Suites: bridge 234 checks, 0 fallos (186 de Tramo 11 + 48 nuevos: V0 tablas 20, V1 flujo primer pase 15, V2 bridge en primer pase 8, V3 caso 74 sec2 5); prototipo surround 51/51. Únicos cambios esperados: U7 99 0/0→16/16, U7 74 0/0/0→0/0/127, U8 95 CC19(0/1) 0/0→16/16. Regresiones intactas: 22 primer pase 1886 notas en 843 ticks, ticks 844/846/851/1505/1550/1594/1600/1610/1684, fades 0,4724/0,7874, stops por handle, track 5 = 281 notas. Persisten: 95 pierde sus vueltas previas a la transición (~79,5 s); ningún `sndSeqStop` real observado en juego; SFA-Decomp ≠ retail. Todo host/sintético: ninguna música verificada en Tab S8.

### 12C — EFB: suite Tramo 10 a 529 (45/45); kernel 2:1 sigue MODEL
- Suite Tramo 10 actualizada a 529: 45 checks, 0 fallos (los 9 fallos de Tramo 11 quedan cerrados, sin décimo fallo escondido). Valores corregidos: 480@232 = 529, 522@232 = 576, 528@234 = 577, 480@234 = 525, 576@232 = 635, 240@232 = 264; B dst_h 5→4, mapa delta [16,82,144,41,41]→[16,82,144,41], C 5→4 filas. Endurecimientos: B pasa a `ram[4*32]` y F a `ram[off+529*1280]` — el check antiguo de F no habría detectado que GX24 (530) tocaba la fila 529. La suite actualizada vive en `work-port/tramo12-efb/test_tramo10_t12.cpp` (no está en el repo; la suite Tramo 10 original vive solo en work-port). Regresiones contra el código actual: T11 74/74, T9 62/62, T8 33/33, T7 53/53, T6 76/76. Corrección a la nota de Tramo 11: T5 es 80/80 invocada con su argumento (`./test_tramo5 ../fase2-tests/run19`, 602 draws, igual que el log original de Tramo 10); el "74/75 preexistente" era un fallo de invocación (sin argumento busca `run19` relativo al cwd y la sección aborta; reproducido), no un fichero perdido — `fase2-tests/run19/fifo.bin` existe. Esta vía no cambia código del port: el delta de código de GX26 viene de las vías A/B.
- Kernel 2:1: NO resuelto, sigue MODEL (box), con decisor validado. Sin referencia real disponible, documentado con evidencia: Dolphin ausente (ningún binario, ningún candidato en apt; instalarlo no bastaría sin escena de impulso); `run39/ram.bin` no sirve (los destinos de reflexión están a cero: la traza guarda comandos FIFO, no salidas del PE); un volcado de reflexión del juego tampoco serviría (entrada desconocida) ni una "construcción desde el filtro documentado" (el filtro documentado ES uno de los candidatos). Nuevo `kernel_ref.cpp`: 33/33 — re-deriva desde cero las tablas Tramo 11 (coinciden exactamente), verifica la cuantificación RGB565 y la tolerancia ±6, y autotest del decisor (cada candidato recuperado de forma única, desajuste 0; kernel fuera del conjunto → "ningún candidato"; box + ruido ±3 → box; vía de fichero probada extremo a extremo). Experimento que lo decidiría: homebrew GC mínimo con escena de impulso (filas/columnas 100 y 101, filtro de traza, `GXSetTexCopyDst` 320×240 mipmap 1) ejecutado en Dolphin o HW, decidido con el decisor. Caveat: Dolphin ≠ HW con certeza absoluta; la impresión visual en dispositivo no prueba el kernel. El byte de profundidad sigue siendo MODELO/argumento, no medida.

### Integración Tramo 12 en esta rama
- Parches aplicados sin conflicto: ARAM (copia completa de `hle.cpp` del frente, verificada como adición pura: 128 líneas añadidas, 0 borradas, más el include `<vector>`) + CC19 (parche aplicado limpio con `patch -p1`; conteos verificados en el árbol integrado: kMusyxCc95 459 con 28 CC19, kMusyxCc99 46 con 2, kMusyxCc74 806 con 3). Surround NO integrado (decisión documentada arriba). Suite Tramo 10 a 529 re-ejecutada por la vía C (45/45) y por mí contra el árbol integrado (45/45); suite CC19 re-ejecutada por mí (234/0 + surround 51/0). Trabajo de las vías en `work-port/tramo12-{song94,cc19,efb}/`. NDK integrado (abajo) y APK GX26 (abajo). Cuestión 1367 sigue abierta (acotada, no resuelta).

### APK GX26 (Tramo 12, PRUEBA — NO jugable)
android-port-base/app-debug-gx26-test.apk, 12.776.102 B, SHA-256 f5e9469dc3839b1f7d8853c98d550b93168a9aa0ed6906da5f9b0e5a79ade30c, SHA-1 a453921b6ad2499ec2f413bd85f71bb47f4e4268, com.starfox.port v17 / 0.17.0-gx26-test, apksigner Verifies v2+v3 (1 firmante, alias test), zipalign OK, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable (build de prueba expresa), solo permiso VIBRATE, sin datos dentro. Lib interior 28.091.408 B, SHA-256 b71d87aa8b422bd634c2729dfc8f0819dd3b8d5019f252ddffa3830b3055f154 (idéntica al build NDK de este tramo: ELF64 AArch64, android_main y func_80003100 en T, OnSeqPlay y SeqCc19Of en T, 0 mem_/ppc_/func_/dolrecomp_ sin resolver, 228 undefined solo sistema). Build manual (Gradle daemon con fallo conocido): javac --release 17, d8, aapt2 link --min-sdk-version 26 --target-sdk-version 34 --version-code 17 --version-name 0.17.0-gx26-test, libstarfox.so + libc++_shared.so, zipalign -f 4, firma keystore de prueba alias test (fuera del repo, NO commiteado; el fichero `.idsig` generado por apksigner se excluyó del commit, como en GX24/GX25). OJO: GX26 lleva otro certificado de firma de prueba que GX25 (SHA-256 del certificado 0085ccc30b552b18d170040d01bcf5b01c0892bff439ffca52855882e3cb1851): NO actualizará sobre GX25 instalada; desinstalar GX25 antes de instalar GX26. Etiqueta: PRUEBA — con la excepción de la canción 94 resuelta en host (modelo ARAM) y el CC19 de primer pase en las tablas, pero sin juego real verificado en Tab S8, sin menú legible, sin mundo estable (el host muere en `unknown_pc 0x80000100` tras lanzar el mapa), sin rumble positivo verificado; nunca jugable al 100 %. Guías: android-port-base/GUIA-PRUEBA-GX26.md (nueva) y android-port-base/GUIA-EXPLORATORIA-GX24-TRAMO11.md (Tramo 11). Cuestión 1367 sigue abierta (acotada, no resuelta).

## Tramo 13 (2026-10-27, este tramo): unknown_pc explicado byte a byte (sin parche honesto) + surround resuelto pero sin integrar + kernel sin referencia — SIN APK nueva (GX26 sigue vigente)

### 13A — unknown_pc 0x80000100: mecanismo probado, bloqueo NO superado, ningún parche aplicado
- Causa exacta (probada, no hipotética): no es un salto a un vector de reset ni un vtable nulo. Es un **desbordamiento del búfer de objetos visibles en la pila de `sceneDraw`**: `getVisibleObjects` escribe 1 byte por objeto en un búfer de la pila de `sceneDraw` sin comprobar límite, y con ≥640 objetos visibles los bytes 636–639 caen exactamente sobre el LR guardado, convirtiendo `0x8005C9A4` en `0x00000100`; el epílogo hace `blr` a `0x100` y el chassis muere en `unknown_pc`.
- Evidencia (4 carreras idénticas, 49.571.763 despachos, igual que Tramo 12): anillo de despachos instrumentado (solo observación) `sceneDraw+0x558 → shadowVolumesSetDirty (lr=0x8005C914) → sceneDraw+0x5BC → pc=0x00000100`; epílogo desensamblado `lwz r0,0x294(r1); mtlr r0; addi r1,r1,0x290; blr`; pila equilibrada (sp epílogo `0x803F9B80`, sp muerte `0x803F9E10` = +`0x290`): solo el valor del LR estaba corrupto. Slot LR: `0x803F9E14`. Watchpoint por byte (prueba definitiva, carrera v1-d): tras el último prólogo de `sceneDraw` (LR `80 05 C9 A4`), exactamente 4 escrituras desde `getVisibleObjects+0xAC` (`stb r0,0(r25)`, chunk `0x8005B8E4`, sp `0x803F9B30`): `0x803F9E14←00, 0x803F9E15←00, 0x803F9E16←01, 0x803F9E17←00` → LR `0x00000100` exacto. El `0x100` son los flags de visibilidad (0/1) de los objetos nº 636–639, no una máscara ni un vector.
- Aritmética: búfer en `sp_sceneDraw+0x18` (`0x803F9B98`, pasado por `sceneDraw+0x78`); `0x803F9E14−0x803F9B98 = 636`; `r25` avanza 1 por objeto (`0x8005BC54`) sin límite. Capacidad hasta registros guardados: 616 bytes; hasta tope del marco: 632. Con ≥640 objetos el choque es inevitable incluso en hardware real: el búfer no es el bug, el conteo sí.
- Primer error mm (correlacionado, no causa directa): entre 45M y 46M (0 en 45M, 176 en 46M; 1.455 totales). `lr=0x80023A28` en `mmAllocFromRegion+0x70`, región 2, `used=849 avail=850`; el desensamblado muestra que `used+1==capacidad` → error y retorno 0: la región está llena de verdad (máximo útil 849). Cadena dominante: `gameUpdate → Obj_UpdateAllObjects → Obj_UpdateObject → FEseqobject_update → ObjSeq_start → Obj_AllocObjectSetup → mmAlloc`. Una vez llena, toda creación falla, pero la cola del anillo es render puro: el mm no causa directamente el salto.
- Causa aguas arriba cuantificada (SAMPLEOBJ por 1M): fuga desde 41–42M (al activarse `cur=1`), luego lineal exacta por 1M: +50 Override, +10 staffAnim, +10 AnimCamera, +30 SB_FireBall, +30 liberados (los FireBall se equilibran; Override 422 cargados/2 liberados, staffAnim 84/0, AnimCamera 84/0). 10 ciclos por 1M ≈ 1 ciclo cada ~2 retraces; mismo ciclo en audio: 84 `AudioStream_Play(105)` desde `ObjSeq_start+0xA18` (el bridge no buclea, el huésped re-dispara). 84×10 + base ≈ 849 = región llena. Condición del bucle verificada en estático: `FEseqobject_update` (0x801E00D4) rearranca la secuencia solo si `mainGetBit(117)==0`, y el bit 117 permanece a 0 en host; **quién debería ponerlo a 1 no está identificado** (1.382 llamadas a `mainSetBits`, valor casi siempre por registro).
- Por qué no hay parche: agrandar el búfer sería modificar código del juego recompilado, no un parche del port, y solo retrasaría el choque (el conteo sigue creciendo y la región ya está llena). Forzar el bit 117 o un "fin de stream" sería inventar sin saber qué entrega falta. Decisión del coordinador: **ningún parche aplicado**; el informe documenta el mecanismo cerrado y el siguiente experimento exacto (1. trazar `mainGetBit(117)` y qué comando de secuencia debería ponerlo; 2. trazar `ObjSeq_AudioStreamCallback` y si el huésped cree que el stream termina al instante por la entrega síncrona de Fase 16; 3. comprobar la cola de `mmFreeDeferred` y si `Obj_Free` corre para esos tipos).
- Pack C-mapa re-medido: **142 ficheros / 82.413.172 B, idéntico a Tramo 12. Sigue siendo CANDIDATO PARCIAL — prohibido presentarlo como pack del mundo** (muerte con `chapter=0`, `curUiDll=1`, sin mundo estable). Mismos 12 fallos de apertura. Pack instalable vigente sin cambios: base SAF + Tier 1 = 3.968 / 382.982.980 B.
- Regresiones re-verificadas en las 4 carreras: disparo idéntico (disp 36.400.000, padread 840, pulso 860–865), `launch=1`, SFX 39, sndSeq 3 (22/95/94), entregas ARQ reales con `fuente_escrita=1` (22/95/94, primer_u32 `0x58`), **0 MEMFAIL**, 0 excepciones antes del punto. No se re-ejecutaron suites de audio/EFB de tramos anteriores en esta vía (no hay binario de suite reutilizable en este tramo; se declara así, no se afirma). Trabajo en `work-port/tramo13-unknownpc/` (INFORME.md, 4 diffs de instrumentación solo observación, carreras v1-a/v1-b/v1-c/v1-d con stdout/stderr/osreport/ram/pack).

### 13B — Audio: surround resuelto, pero NO integrado (decisión con evidencia)
- Escala RESUELTA (no era una elección): los bytes de macro del pool S (`starfoxs.poo`) muestran que las 5 macros lectoras (966, 1298, 1300, 949, 674) llevan `0x27101347` con valor `0x0` → escala exactamente `0x640000` (100×). Las 2 macros 1× (`0x00641347`) son otras: **1502 y 1425**, no las de 95/99/74. Corrección al Tramo 12 (números correctos, mecanismo mal descrito): ctrl 19 va por la rama *unsigned* de `_GetInputValue` (no está en la lista signed); el producto s32 **envuelve módulo 2³²** (hardware PPC), luego clamp solo superior a `0x3FFF`, retorno u16, `synth` `lastSPan = valor×0x200` (clamp `0x7F0000`), `spanPos = (lastSPan−0x10000)×2.4220301e-07`. Verificado C (`-fwrapv`) vs Python en los 128 valores: **0 divergencias**. Valores reales: 0→0 frontal, **16→1.0 centro**, 64→2.0 trasero, 127→2.0 trasero (6→1.381, no monótono). Caveat: wrapped vs saturado difieren en 30/128 valores, pero entre los reales solo 16 cambia (centro vs trasero si el retail saturase). Solo importaría en modo surround, que el port no renderiza. Experimento que lo decide: objdiff de la unidad `snd_midictrl` o desensamblado retail de `_GetInputValue`.
- Salida RESUELTA (estéreo = inaudible; surround = DPL sin matriz derivable): el juego es **estéreo por defecto** (`audioInit` → `sndOutputMode(1)`); surround solo vía menú de opciones (`soundMode=1`, guardado en partida, restauración condicionada al modo OS). En estéreo el huésped pone `lastSPan = 0` siempre → **el modelo solo-estado actual ya es fiel** para lo que el port renderiza. Plegar S sobre L/R está prohibido en ambos modos (en estéreo S=0 con L/R íntegros; en surround el huésped atenúa L/R con el espejo, no suma S). En surround, la salida seguiría siendo estéreo AI: `volS` va al DSP como parámetro de mezcla y la matriz Dolby Pro Logic vive en el **microcódigo DSP binario** (nada en el C del decomp). No hay LFE ni trasero discreto; la rama DPL2 de estudio no la usa el juego (ninguna llamada a `synthActivateStudio` en main/dlls). **Sin matriz no hay salida implementable** — ese es el bloqueador de integración.
- Flag por macro IMPLEMENTADO Y TESTEADO (retenido, NO aplicado): tabla (gid, midi): 49 → 0/1/2/4 sí, **3 (1299) NO**; 54 → 0/1 sí; 18 → 0/1/2 sí; resto NO por defecto (22/5 sin auditar). 1299 sin `0x47` ni `0x15` → `lastSPan`=0 aunque el canal lleve CC19=64. Implementado en copia de trabajo: `MusicVoice.reads_surround/surround_span` capturados en `StartMusicNote`, `ReadsSurround`/`SurroundSpan`/`MusicVoiceSurround` — sin tocar `Tick()` ni el PCM. Matiz: el huésped reevalúa voces vivas ante cambios de CC; el bridge hornea en note-on (como CC10) — exacto aquí porque CC19 es constante por sección y precede a su primera nota.
- Tests host: **Tramo 13: 58 checks, 0 fallos** — escala 128/128, ley sal (S/espejo: 0→0/1; 1→0.5011/0.7079; 2→0.7079/0), flag, primer pase (95: 49/49 voces, 99: 6/6, 74: 15/15, todas con el (reads, span) esperado, sec3 inerte) y bucle (95 hasta 96 notas, 99 hasta 10, 74 hasta 27; sec3 sigue inerte con `CC19(3)=64`; sec0/1 conservan 16 persistido). Nota honesta: en bucle de 95 el registrador por diferencia de conjuntos capturó 43/47 apariciones (4 coincidencias de reutilización de slot), con cobertura completa por midi y todos los registros correctos. **Regresiones: suite Tramo 12 234/0** contra el bridge parcheado (bucles 22/95/99/74, CC19 primer pase 459/46/806, fades 0,4724/0,7874, stops por handle, track 5 = 281 notas). **Mezcla estéreo bit a bit**: pristino 063ccbb vs parcheado, mismo escenario 95/99/74/22 → **10.991.744 frames, FNV-1a `0xc4f98f7aea63da2e` idéntico**.
- Parche retenido (NO aplicar): `work-port/tramo13-surround/patches/patch-tramo13-surround-HELD-NO-APLICAR.diff` — solo `audio_bridge.h/.cpp`, espejo verificado. Qué falta, en orden: (1) matriz DPL del ucode DSP (o medida GC real + decodificador Pro Logic) — bloqueador de cualquier modo surround audible; (2) fidelidad del wrap para cc19=16 (objdiff/disasm retail); (3) decisión de producto sobre opción de modo de sonido (debe ser opt-in, como en el juego); (4) auditoría de macros de 22/5; (5) prueba en Tab S8 cuando vuelva el enlace ADB. Todo host/sintético, sin APK, sin ejecución en dispositivo.

### 13C — EFB: kernel 2:1 sigue MODEL (sin referencia), suites todas en verde
- Referencia NO conseguida, con evidencia nueva: Dolphin ausente (`which dolphin*` vacío; nada en `/usr/bin`, `/usr/local/bin` ni `~/tools/`). **Cierre de la vía apt**: un `apt-get update` del sistema retiene el lock de listas todo el tramo, así que se descargó directo del mirror el índice `noble/universe` (64.755 paquetes) y se buscó: **no existe ningún paquete `dolphin-emu` en Ubuntu 24.04** (solo el gestor KDE `dolphin`); tampoco en `noble-updates`. La vía apt no está bloqueada temporalmente: está cerrada para esta distro. Flatpak/docker/podman ausentes (instalar flatpak exigiría apt, bloqueado); Dolphin oficial en Linux es solo Flatpak, sin tarball ni AppImage oficial; AppImages de terceros no intentados deliberadamente (binario sin verificar); compilar Dolphin desde fuente descartado en este tramo (2 CPU, sin GPU, deps por apt bloqueado). Dato a favor del intento futuro: sí hay Mesa software (`swrast`, Xvfb) pero ningún ICD Vulkan, así que un Dolphin futuro iría por OpenGL software con `LIBGL_ALWAYS_SOFTWARE=1`.
- **Homebrew entregado, sin compilar ni ejecutar**: fuente del programa mínimo de impulso (4 pasadas: vertical par 100 / impar 101, horizontal par 100 / impar 101, copia 640×480→320×240 RGB565 con mipmap 1, filtro de la traza run39) en `work-port/tramo13-kernel/homebrew-impulse/main.c` y receta completa en `work-port/tramo13-kernel/homebrew-impulse/BUILD.sh`. No se compiló porque no hay devkitPPC/libogc (el instalador oficial de devkitPro, inspeccionado, necesita apt bloqueado y es cambio de sistema fuera del directorio del tramo; y sin Dolphin compilar no produciría referencia alguna). La receta incluye los dos controles previos obligatorios: filtro emitido = traza (BP 0x53/0x54) y paridad Y no espejada (un espejo invalidaría la decisión vertical).
- Decisión del kernel: sigue MODEL, sin parche. El ejecutor separable (7-tap vertical + box horizontal) **no** se implementa — sería inventar el kernel. El decisor queda re-verificado y listo: en cuanto exista un volcado real 320×240, la decisión es mecánica (`kernel_ref --ref …`). No hay diff de código contra 063ccbb.
- Byte Z8: sigue MODELO por argumento (byte alto), no medida. Reproducción Tramo 13: en `run39/ram.bin`, los 64 B de ambos destinos de reflexión siguen a cero (`0x8163C740` fmt 0x11 y `0x81614900` RGB565) — la traza guarda comandos FIFO, no salidas del PE. La etiqueta "RESUELTO" de Tramo 11 cubre la identificación del formato y el decodificador, no el byte. Falsador vigente: rampa de profundidad en dispositivo → monótona (byte alto) vs diente de sierra (byte bajo); si dijera bajo, el cambio es de una línea en `ExecuteEfbCopyZ8`.
- Suites EFB re-verificadas contra 063ccbb: todo en verde, cero fallos. Árbol `cpp/` extraído con `git show 063ccbb:` y verificado **byte a byte idéntico** al de Tramo 12 en los 16 ficheros EFB (el diff 4b399ad→063ccbb solo toca guías, APK GX26 y audio). Compilación limpia `-Wall -Wextra` (0 avisos). Tramo 10 a 529 **45/45**; Tramo 11 **74/74**; Tramo 9 **62/62**; Tramo 8 **33/33**; Tramo 7 **53/53**; Tramo 6 **76/76**; Tramo 5 (con `../fase2-tests/run19`) **80/80**, 602 draws como en Tramo 10; decisor `kernel_ref` **33/33** + `SIN REFERENCIA REAL`. No hay ningún fallo con causa que informar. Qué falta, en orden: (1) resolver Dolphin (flatpak cuando se libere apt, o compilación en máquina con más recursos) — bloqueo raíz; (2) instalar devkitPPC+libogc y compilar las 4 pasadas del homebrew; (3) verificar filtro de traza y paridad Y antes de aceptar cualquier salida; (4) ejecutar en Dolphin (nogui + Xvfb + OpenGL software, Dump Textures o frame dump) y decidir por eje con `kernel_ref`; entonces sí, parche + tests; (5) el mismo experimento con rampa de profundidad decide el byte Z8.

### Integración Tramo 13 en esta rama
- **Ningún parche de código aplicado, deliberadamente**: la vía A no tiene parche honesto (el mecanismo está probado pero agrandar el búfer sería tocar código del juego y forzar el bit 117 sería inventar); la vía B retiene su parche (falta la matriz DPL); la vía C no tiene parche (falta la referencia). Aplicar cualquiera de los tres habría sido maquillar el tramo.
- **Sin APK nueva**: con cero cambios en el código del port, una GX27 sería GX26 con otro número de versión — ruido, no avance. La APK de prueba vigente sigue siendo **GX26** (12.776.102 B, SHA-256 `f5e9469dc3839b1f7d8853c98d550b93168a9aa0ed6906da5f9b0e5a79ade30c`, v17 / `0.17.0-gx26-test`; desinstalar GX25 antes de instalarla; guía GUIA-PRUEBA-GX26.md). Este commit es solo documentación del Tramo 13. Trabajo de las vías en `work-port/tramo13-{unknownpc,surround,kernel}/`. Cuestión 1367 sigue abierta (acotada, no resuelta).
- Etiqueta: PRUEBA — sin juego real verificado en Tab S8, sin menú legible, sin mundo estable (el host muere en `unknown_pc` tras lanzar el mapa), sin rumble positivo verificado, inerte sin `sfa-data/`; nunca jugable al 100 %.

## Tramo 14 (2026-10-27, este tramo): bit 117 acotado (sin parche) + wrap surround confirmado + Dolphin corriendo sin volcado — SIN APK nueva (GX26 sigue vigente)

### 14A — Bit 117 / fin de secuencia: bloqueo NO superado, causa acotada a una proposición falsable, ningún parche
- Reproducción exacta (carrera v1, idéntica a Tramo 13 v1-d): **49.571.763 despachos**, ticks 496, PADRead 1017, retrace 1051, `pc_final=0x80000100`, disparo disp 36.400.000 / padread 840, `curUiDll=1, chapter=0, launch=1`, SFX 39, sndSeq 3 (22/95/94), 0 MEMFAIL, primer error mm región 2 `used=849 avail=850` (1.455 errores en total). Corrupción LR re-confirmada (`00 00 01 00` desde `getVisibleObjects+0xAC`). Pack C-mapa sin cambios: **142 / 82.413.172 B, sigue CANDIDATO PARCIAL**.
- **El bit 117, verificado en RAM viva** (muestreo nuevo `T14: SAMPLEBIT` cada 1M): descriptor estable desde 3M — tabla `0x813B0C40`, inicio 467, byte2 `0x40`, array sel 1, **longitud 1 bit** (byte `0x803A51A6`, bit 3). Vale **0 en las 47 muestras de 3M a 49M y 0 en el `ram.bin` final**.
- **El setter existe y nunca corre**: estático, `FEseqobject_SeqFn` (`0x801DFCEC`) recorre la cola `[estado+0x8B]`/`[estado+0x81+i]`; código **1 → `mainSetBits(0x75=117, 1)`** (`0x801DFD90`). Es el único setter con valor constante 1 del sistema ObjSeq. Quién llama a SeqFn (barrido completo del DOL buscando `lwz *,0xBC(*)` + `bctrl`): **único llamador, `objCallSeqFn`** (`0x8008512C`, puntero en `[obj+0xBC]` puesto por `FEseqobject_init`), que tras llamar **borra la cola**. `objCallSeqFn` tiene solo 3 llamadores `bl`: `ObjSeq_SetupInitialPlaybackState+0x160`, `ObjSeq_update+0x2A8` y `ObjSeq_update+0xB84` (este último solo si el flag `[r13-0x60B0]==0`, o sea, como mucho una vez por estado y pase). Dinámico (traza PCTRACE ampliada, `mainGetBit`/`mainSetBits` filtrados a bit 117): **`mainSetBits(117) = 0` en toda la carrera** — robusto frente a invisibilidad intra-chunk, porque SeqFn está en otro chunk que `mainSetBits`. Esto descarta también los 18 sitios de `objInterpretSeq` y cualquier setter por datos. En cambio, `mainGetBit(117) = 169`, alternando estrictamente `SB_Galleon_update` (85) y `FEseqobject_update` (84). Cada uno de los 84 updates va seguido de `ObjSeq_start(0, obj=0x8120C740, -1)` — siempre el mismo objeto reiniciando la secuencia 0. Destino del `bctrl` confirmado en RAM viva: `ObjSeq_funcs+0x18`, `[+0x48]=ObjSeq_start`. `SB_Galleon_update` también toma siempre su rama "bit==0" (la rama !=0, con `updateFlight`/`updateShield`, nunca corre).
- **Audio: pista falsa para el bit 117.** `Play(105)` 84× (todos desde `ObjSeq_start`), `PrepareCallback` 84× (entrega HLE síncrona dentro de Play, `lr=0x80003008`), `ObjSeq_AudioStreamCallback` 84× — pero su desensamblado muestra que **solo toca subtítulos** (IsPreparing/Nop/`gameTextLoadTaskText`/`subtitleStop`/`subtitleStart`), nunca el bit ni el fin de secuencia. Dos huecos HLE reales pero distintos: `AudioStream_StartPrepared` = **0 llamadas** (el huésped nunca cree que el stream suene: `play_b=0, cur=0, prep=0` en todos los muestreos post-lanzamiento) y `PlayAddrCallback` (fin de stream) = **0** (sin entrega `DVDStopStreamAtEndAsync`). Caveat honesto: `ObjSeq_StartPreparedStream` no estaba en la lista PCTRACE de esta vía, así que no se distingue "nunca llamado" de "llamado pero abortó" — punto 1 de v2.
- **Fuga NO diferida.** `mmFreeTick` corre 1.020×; la cola diferida sube a 33 en 42M y se queda clavada en 33 hasta 49M **pero con la cabeza cambiando entre muestras** (equilibrio entrada/salida, no atasco). La fuga es no-liberación: Override 422 cargados / 2 liberados, staffAnim 84/0, AnimCamera 84/0 (FireBall 252/225, neto +27). `Obj_FreeObject` corre 226× (casi todo desde `dll501_update`), nunca para esos tipos. Causalidad: bit 117 → reinicio → fuga, no al revés.
- Parche propuesto: **ninguno**. Forzar el bit 117 o inventar un fin de stream seguiría siendo inventar sin saber qué entrega falta. Tampoco se reabre el búfer de `sceneDraw` (descartado en Tramo 13). Siguiente paso exacto (v2, solo observación): (1) añadir a PCTRACE `ObjSeq_StartPreparedStream` (`0x800805A8`) y `ObjSeq_ExecuteActionCommand` (`0x800856C4`); muestrear `[r13-0x60F4]`, `[r13-0x6118]`, `[r13-0x60AE]` por 1M. (2) Añadir a PCTRACE `objCallSeqFn` (`0x8008512C`) y muestrear la cola del slot del mapa (`[slot+0x80..0x8B]`; resolver antes la base de la tabla de slots del código de asignación de `ObjSeq_start`). Discriminador: si `objCallSeqFn` corre con contador 0 siempre → falta el **encolado** del código 1 (trazar entonces las acciones de la secuencia 0); si nunca corre para ese slot → la entrega que falta es la **llamada** (guardas destino==propietario / slot fuera del bucle de update). (3) Solo con eso resuelto, diseñar el parche HLE y verificar: `mainSetBits(117,1)` ≥1 con `lr=0x801DFD9C`, `bit117=1` después, 0 `Play(105)` nuevos por 1M, `LOADED Override` estable, visible <616, y la carrera pasando de `sceneDraw`. Trabajo en `work-port/tramo14-bit117/` (INFORME.md, diffs de observación contra Tramo 13 no aplicados al repo, carrera v1 completa, análisis estático y harness reutilizables). Regresiones de comportamiento: ninguna (todo observación).

### 14B — Surround: wrap confirmado, matriz sigue bloqueada, parche retenido v2 (NO integrado)
- **Matriz DPL: NO resuelta, con barrido evidenciado (no opinión).** En el C del decomp no hay matriz: barrido de `src/musyx/runtime/` e `include/musyx/` para surround/Dolby/Pro Logic — solo el cálculo de `volS` (`sal_volume.c`, tabla `{0, 0.7079, 1, 1}`), buses AUX con sección `surround` (para reverb, no salida principal), el comentario `SND_OUTPUTMODE_SURROUND 2`, y la rama DPL2 de estudio que el juego no usa. La salida AI es estéreo puro (4 búferes de `0x280` B), así que cualquier surround debe codificarse en Lt/Rt dentro del microcódigo DSP. **El microcódigo es retail byte a byte**: `dspSlave` (`sal_dsp.c`, 3312 palabras) extraído del decomp y comparado con el DOL local en `0x803321A0` (offset `0x32F1A0`): **idéntico al 100 %**; además `sal_dsp.c` está en `matching_units.txt` de `GSAP01_rev1`. Del lado CPU no se sube ninguna tabla de coeficientes (solo `dspSlave` a IRAM + DRAM scratch). Escaneo de constantes en las 3312 palabras: `0x5A82` (0.7071 Q15) = 0 ocurrencias, `0x5A80` = 0, `0x4000` = 0, `0x2D41` = 0, `0x7FFF` = 1 (inmediato aislado, no coeficiente de mezcla). No hay constante DPL legible que extraer; leer la regla real (ganancia, signo, retardo, fase) exige desensamblar el ISA DSP y localizar el bucle que consume `vS`/`mixerCtrl`. Vía de medida cerrada en este entorno: sin desensamblador DSP offline (`~/tools/`, `pip`, `SFA-Decomp/tools/` sin DSP; `apt-cache` sin `dolphin-emu`), sin GameCube real, sin Dolphin LLE para correr `dspSlave` con `vS` controlado, sin decodificador Pro Logic. No se descarga nada por orden del tramo. **Vía futura nombrada**: desensamblador DSP de Dolphin (o equivalente) sobre `dspSlave`, o Dolphin LLE con PB controlado para ajustar la matriz empíricamente. Inventar `Lt = L + 0.707·S, Rt = R − 0.707·S` está prohibido por el tramo y sería falso con alta probabilidad (fase/retardo desconocidos).
- **Wrap cc19=16: DISCRIMINADO — el retail envuelve (caveat de Tramo 13 cerrado).** Desensamblado del DOL retail (no del decomp): `_GetInputValue` en `0x802829E0`, tamaño `0x488`, 290 instrucciones (Capstone PPC). Lista signed en `0x80282a48–0x80282a78` (ctrl `0x80`, `1`, `0x0A`, `0xA0`, `0xA1`, `0x83`); ctrl 19 (`0x13`) falla todas → **rama unsigned** (`0x80282c38`). Rama unsigned: `bl inpGetMidiCtrl` (`0x80282494`; patrón `lbz`+`slwi 7` = `(MSB<<7)|LSB`, luego cc19·128), `scale>>1` (`srawi 1`, `0x80282cf0`), **`mullw` plano en `0x80282cf4`**, `>>15`, **clamp solo superior** (`cmpwi 0x3FFF`, `0x80282cfc–0x80282d04`, sin clamp inferior), SET = `value = tmp`, retorno u16 (`clrlwi`, `0x80282e50`). **Saturación imposible**: 6 `mullw` y **0 `mullwo`, 0 `mulhw`, 0 `bov`, 0 `mcrxr`** en toda la función. La variante saturada es código que el retail no tiene. **Conclusión: cc19=16 = centro (span 1.0) definitivamente.** Ningún número cambia (la tabla de Tramo 13 ya era la de wrap); cambia el estatus, de dudoso a confirmado. Impacto de la variante descartada: solo 16 (95 sec0/1, 99 sec0/1) habría pasado de centro a trasero, solo en modo surround; en estéreo, cero en cualquier variante.
- **Modo de sonido opt-in: diseñado, NO aplicado.** Estado actual: el port no tiene opción de modo, ni `SharedPreferences` de audio, ni setter JNI, ni lectura de partida (solo trazas CARD en `chassis.cpp`). En el huésped el modo vive en la partida: `SaveData.soundMode` u8 (`savedata_struct.h:36`); carga → `audioSetSoundMode(soundMode, 0)` en `21.c:1488` (con `force=0` no aplica si la consola no es estéreo); opciones → `gOptionsSaveData->soundMode` en `55.c:403/794` (`force=1`). Modos: 0→STEREO, 1→SURROUND, 2→MONO, 3→STEREO; defecto `audioInit` → STEREO. Diseño (dos fases): **Fase A** (implementable hoy, pero NO enviada hasta tener matriz): interruptor en `MainActivity` → `SharedPreferences` (defecto OFF) → JNI `nativeSetSurroundEnabled` → campo `surround_enabled_` en el bridge; con ON y matriz resuelta, `Tick()` aplicaría espejo `interp(2−span)` a L/R y acumularía `S = 0.7079·level·interp(span)` codificado con la matriz evidenciada. Sin matriz, ON no debe hacer nada audible (atenuar sin codificar pierde energía y no es ni estéreo ni surround huésped). **Fase B** (futura): cuando el port ejecute la carga de partida del juego, leer `SaveData.soundMode` y alimentar el mismo setter (regla huésped `force=0` en carga, `force=1` en opciones). **Sin partida/sin ajuste: estéreo**, como el juego por defecto. El ajuste del port no debe afirmar que sigue a la partida hasta que la Fase B exista. SFX/stream fuera de alcance en esta fase.
- **Auditoría 22/5: tabla completa (no resumen).** Método: `SeqHost` primer pase + vueltas (22: 400000 pasos; 5: 60000) + `macro_records` sobre `starfoxm.poo` (pool M) + censo completo de ambos pools. Las tablas planas del bridge reproducen al huésped nota a nota (22: 1886; 5: 281). Censo: pool M 594 macros, 122 con exactamente un `0x47` (todos ctrl 19; 120×100×, 2×1×: 515, 516); pool S 925 macros, 82 con `0x47` (todos ctrl 19; 80×100×, 2×1×: 1425, 1502); **0 macros con opcode `0x15` en ambos pools** (ampliación a Tramo 13: `panning[1]=0` es general, no particular de 1299). **Canción 22 (track 22, gid 0, pool M; CC19 = 0 en TODAS las vueltas** — huésped 6 vueltas/sección, planas `kMusyxCc22` 727 CCs/0 CC19, bucle 544 CCs/0 CC19; secciones 2/6/7/9 sin notas): sec 0/1/3/4/5/8/10/11/12/13/14/15 con notas 24/10/10/12/8/56/540/198/72/288/384/284; solo sec 4 (macro 226, 100×) y sec 15 (macro 72, 100×) leen ctrl 19, con CC19=0 → span 0.0 frontal, S=0, espejo=1: idéntico a estéreo; resto S=0 sin leer. **Canción 5 (track 5, gid 0, pool M, 1 sección; único CC19: `time 4, midi 6, 127`, antes de la primera nota de midi 6 en `time 10`)**: midis 0/1/2/3 leen (398/397, 100×) con CC19=0 frontal; midi 6 (67 notas) NO lee pese a CC19=127 → **0.0 inerte** (como 95 sec3): S=0 inerte; midis 9/10 leen (216/219/222, 223/224, 100×) con CC19=0 frontal; resto S=0. **Hallazgo de clave: (gid, midi) está prohibido para gid 0.** Ambas canciones son gid 0 (como las pistas 0–73): `(0,4)` → 22 lee (226) pero 5 NO lee; `(0,0)` → 5 lee (398) pero 22 NO lee. El parche v2 usa clave por `track_id` (`MusyxSong.track_id`, que el bridge conoce) para 22/5 y mantiene la tabla por gid de Tramo 13 para 95/99/74. **Hueco del bridge documentado e inaudible:** `kMusyxCc5` (463 CCs) tiene 0 CC19 — el evento (4,6,127) falta en la tabla plana (`SeqCc19Of(6)=0` vs 127 huésped), sin consecuencia audible porque midi 6 es inerte; un arreglo estilo Tramo 12 para la 5 lo añadiría sin cambiar ningún PCM. **Veredicto audible: en modo SURROUND huésped, 22 y 5 dan S=0 en el 100 % de sus voces** (inertes o frontales); su render estéreo actual ya es fiel incluso en ese modo hipotético.
- **Parche: RETENIDO v2 (no integrable este tramo).** 206 líneas, solo `audio_bridge.h/.cpp`, base `4289f36`; `patch -p1 --dry-run` OK sobre copia prístina y aplicado byte-idéntico a `src/audio/` v2. Contenido: `ReadsSurround` sin cambios (95/99/74); nuevo `ReadsSurroundTrack` (22→4,15; 5→0,1,2,3,9,10); `SurroundSpan` sin cambios funcionales (comentario actualizado: wrap confirmado retail); `MusicVoice` += `reads_surround`/`surround_span` + accesor `MusicVoiceSurround`; captura en `StartMusicNote` por track para 22/5, por gid para el resto. No toca `Tick()` ni el PCM. **Motivo de retención: falta la matriz (condición 1 de 3).** Flag auditado ✓, opt-in diseñado ✓, pero aplicar hoy añadiría estado muerto sin consumidor, como en Tramo 13.
- Tests con cifras: **test Tramo 14: 45 checks, 0 fallos** (span 128/128 == tabla literal; tabla por track completa incl. colisiones; regresión gid; primer pase bridge 5 = **281/281 notas en 282 ticks**, 22 = **1886/1886 en 843 ticks** con todos los registros voz con el (reads, span) esperado, incl. 5 midi 6 con reads=false pese al CC19=127 huésped; bucle 22 = **1991 notas**, 105 registros nuevos correctos). **Regresión Tramo 13 contra v2: 58/0**; **regresión Tramo 12 contra v2: 234/0**. **PCM bit-idéntico** (prístino `4289f36` vs v2): escenario principal **10.991.744 frames, FNV-1a `0xc4f98f7aea63da2e`**; canción 5 sola **281 notas, 1.318.912 frames, FNV-1a `0xae7d3c452c43d75e`**. Nota de método honesta: la primera pasada puso la 5 en el mismo Env que las otras cuatro y **no arrancó** ("sin slot libre", límite de 4 canciones en curso); se detectó por el log y se corrigió con un Env aparte que sí la cubre. Caveats: el `Recorder` escanea 32 slots (`kMaxMusicVoices=32`) y subcuenta en pasajes densos (22 midi 8: 44/56; 5 midi 8: 23/29); los totales `MusyxNotesStarted()` son exactos y todos los registros observados son correctos. Captura en note-on difiere del huésped ante un cambio de CC19 a mitad de sección; no existe tal evento en 22/5. Todo host, sin Tab S8 ni APK. El diff retenido NO debe presentarse como mejora audible. Trabajo en `work-port/tramo14-surround/` (INFORME.md, tabla_22_5.md, parche retenido v2, audit.py, censos, desensamblados retail, tests). **Siguiente paso real (fuera de este tramo):** desensamblar `dspSlave` (o medirlo bajo Dolphin LLE) hasta identificar cómo `vS` se pliega en Lt/Rt; en ese momento, el parche v2 + el diseño opt-in son la base directa de la integración, sin re-auditoría de 22/5.

### 14C — EFB: Dolphin instalado y corriendo, toolchain y homebrews compilados, pero SIN volcado — kernel y byte Z8 siguen MODEL
- **Vía Flatpak oficial, sin apt y sin binarios sin verificar.** Flatpak 1.14.6 extraído de 14 .deb oficiales de `archive.ubuntu.com` (SHA-256 verificados contra el índice noble) a `tramo14-kernel/flatpak-prefix/`. Repo oficial `https://flatpak.dolphin-emu.org/dev.flatpakrepo` + Flathub añadidos; instalación completada (~2,7 GB): **Dolphin Emulator 2609-127 beta** (commit `d19ce17d…`, 2026-10-25) + runtime KDE 6.11 + Mesa 26.2.5. **Ejecución resuelta:** `flatpak run` exigía bus de sesión D-Bus, bus de sistema (`/run/dbus/system_bus_socket`) y Xvfb; con los tres, el sandbox funciona. Esta build Flatpak **no incluye `dolphin-emu-nogui`**: se usó el binario Qt con `-b --exec -v`. Los procesos Dolphin ignoran SIGTERM (hubo que usar SIGKILL por PID).
- **Sin volcado tras 7 ejecuciones** (OGL y Software, variantes con/sin WaitVSync, `DumpTextures` + `DumpEFBTarget` + `DumpXFBTarget`, GFX.ini en ambas ubicaciones, logging activado): `Dump/Textures/` vacío y `dolphin.log` vacío en todos los casos. Hallazgo útil verificado contra la fuente de Dolphin: `DumpTextures` **no vuelca copias EFB** (solo texturas RAM); los mecanismos correctos son `DumpEFBTarget`/`DumpXFBTarget`, y tampoco produjeron ficheros. Hipótesis ordenadas y prueba siguiente (homebrew mínimo solo-CopyDisp, y GUI bajo Xvfb) en el INFORME §8 de la vía. Las cachés de shaders son ficheros de 0 bytes: no son prueba de draws, corrección explícita de una inferencia inicial de la vía.
- **devkitPPC + libogc: conseguidos por vía directa oficial.** `.deb` oficial `devkitpro-pacman` 6.0.1-2 desde `apt.devkitpro.org`, **SHA-256 verificado exactamente** contra su índice (`88f4ec80…a97a`), extraído con `dpkg-deb` sin instalar en el sistema. Pacman relocalizado (transporte nativo fallaba tras el proxy → `XferCommand=curl`) instaló `gamecube-dev`: **devkitPPC GCC 16.2.0 + libogc + elf2dol** en `tramo14-kernel/devkitpro-root/`. Salvedad honesta: la instalación usó `SigLevel=Never` (el keyring GPG está ligado a `/opt/devkitpro/pacman` y no se puede poblar en un prefijo relocalizado); paquetes por HTTPS desde `pkg.devkitpro.org` con sumas verificadas por pacman. Si se exige firma, repetir en `/opt/devkitpro` real.
- **Homebrews: compilados (con un bug real de Tramo 13 corregido).** **Filtro verificado estáticamente** contra la fuente de libogc (`GX_SetCopyFilter`): taps `{7,7,12,12,12,7,7}` emiten exactamente BP `0x53=0x30C1C7` / `0x54=0x0071CC` de la traza run39; `GX_SetTexCopyDst(...,GX_TRUE)` pone el bit 9 de `0x52`. Falta la confirmación en log FIFO. **Bug Tramo 13 encontrado y corregido:** el frame 2 dejaba `GX_VA_CLR0` en DIRECT pero el quad solo enviaba POS+TEX0 (flujo desalineado, draw sin completar). Corregido (`CLR0` a `NONE`, `NumChans(0)`, color `GX_COLORNULL`) en impulso y rampa; la corrección **no** produjo volcados, así que no era el único bloqueo. Hashes vigentes (0 avisos, cabeceras DOL validadas, entry `0x80003100`): impulse-0 `89a5b722…f2a5`, impulse-1 `98bf8e06…07d`, impulse-2 `b5561f97…322`, impulse-3 `e330fc1a…bcd`, depth-ramp `51595ed1…742`, spin-0 (variante sin WaitVSync, descarta VSync como bloqueo) `8399146b…bcd`. Flag crítico: `-mogc` (sin él, libogc aborta con "Invalid platform selected").
- **Byte Z8: sigue MODEL, experimento listo y compilado.** Matiz documental nuevo: la cabecera libogc define `GX_TF_Z8` (fmt 0x11) como "upper 8 bits of Z" — refuerza el byte alto, pero **no es una medida**. Experimento `homebrew-depth/` compilado (no ejecutado): 640 franjas de profundidad constante, copia `GX_TF_Z8` a plena resolución (sin downsample, para aislar el byte), muestreada como I8; predicciones H0 monótona vs H1 diente de sierra (~0x66/columna), controles planos en los extremos, decisor `analyse.py`. Cambio de una línea localizado en `ExecuteEfbCopyZ8` (`int v = (int)(avg*16777215.0f) & 0xFF` si ganara H1), **no aplicado**.
- **Kernel: sigue MODEL, decisor re-verificado, sin parche.** Sin referencia ejecutada no hay decisión por eje; el ejecutor separable (7-tap vertical + box horizontal) sigue sin implementarse. Decisor `kernel_ref` 33/33. **Experimento alternativo desde el port en host: no sirve, por circularidad** (el downsample del port ES el modelo bajo examen; devolvería box por construcción). Documentado en el INFORME §6 de la vía; no se ejecutó porque no añadiría evidencia.
- Suites re-verificadas contra 4289f36 (árbol cpp byte a byte idéntico en los 16 ficheros, 0 avisos `-Wall -Wextra`): Tramo 10 a 529 **45/45**, Tramo 11 **74/74**, Tramo 9 **62/62**, Tramo 8 **33/33**, Tramo 7 **53/53**, Tramo 6 **76/76**, Tramo 5 **80/80** (602 draws), decisor **33/33** + `SIN REFERENCIA REAL`. Cero fallos, cero regresiones. **Declaración honesta sobre el código del port: este frente NO cambia código del port.** Sin referencia ejecutada, cambiar el modelo box sería inventar el kernel, y sin medida, cambiar el byte Z8 sería inventar el byte. Trabajo en `work-port/tramo14-kernel/` (INFORME.md, DIFF.md con base exacta y ausencia de parche justificada, homebrew-impulse/depth/spin compilados, toolchain relocalizada, Flatpak extraído, suites y logs; ningún proceso Dolphin queda corriendo). El próximo tramo solo necesita resolver el bloqueo de volcado (§8.4 del informe): todo lo demás (Dolphin, toolchain, homebrews corregidos, decisores) está listo.

### Integración Tramo 14 en esta rama
- **Ningún parche de código aplicado, deliberadamente**: la vía A no tiene parche honesto (el setter del bit 117 existe pero nunca corre; forzar el bit sería inventar); la vía B retiene su parche v2 (falta la matriz DPL); la vía C no tiene parche (falta el volcado de referencia). Aplicar cualquiera de los tres habría sido maquillar el tramo.
- **Sin APK nueva**: con cero cambios en el código del port, una GX27 sería GX26 con otro número de versión — ruido, no avance. La APK de prueba vigente sigue siendo **GX26** (12.776.102 B, SHA-256 `f5e9469dc3839b1f7d8853c98d550b93168a9aa0ed6906da5f9b0e5a79ade30c`, v17 / `0.17.0-gx26-test`; desinstalar GX25 antes de instalarla; guía GUIA-PRUEBA-GX26.md). Este commit es solo documentación del Tramo 14. Trabajo de las vías en `work-port/tramo14-{bit117,surround,kernel}/`. Cuestión 1367 sigue abierta (acotada, no resuelta).
- Etiqueta: PRUEBA — sin juego real verificado en Tab S8, sin menú legible, sin mundo estable (el host muere en `unknown_pc` tras lanzar el mapa), sin rumble positivo verificado, inerte sin `sfa-data/`; nunca jugable al 100 %.

## Tramo 15 (2026-10-27, este tramo): bit 117 v2 (encolado, sin parche) + matriz DPL falsada + kernel 2:1 y Z8 decididos con referencia Dolphin — SIN APK nueva (GX26 sigue vigente)

### 15A — Bit 117 v2: discriminador RESUELTO (rama ENCOLADO), bloqueo NO superado, ningún parche
- Reproducción (dos carreras, idénticas a Tramos 12–14): **49.571.763 despachos**, ticks 496, PADRead 1017, retrace 1051, `pc_final=0x80000100`, disparo disp 36.400.000 / padread 840, `curUiDll=1, chapter=0, launch=1`, SFX 39, sndSeq 3 (22/95/94), primer error mm región 2 `used=849 avail=850`, **1.455 errores `No more slots`**, LOADED Override 422 / staffAnim 84 / AnimCamera 84 / FireBall 252. Corrupción LR re-confirmada (bytes `00 00 01 00` a `0x803F9E14..17` desde `getVisibleObjects+0xAC`). `ram.bin` v1/v1b difiere en solo 2 bytes (`0x803DEA06–07`); `osreport.log` y `texloads.csv` idénticos.
- PCTRACE v1 (contadores totales): `ObjSeq_StartPreparedStream` (0x800805A8) **0**, `ObjSeq_ExecuteActionCommand` (0x800856C4) **0**, `objCallSeqFn` (0x8008512C, sitios de update) **0**, `seqDoSubCmd0B` (0x80083A7C, único escritor de la cola SeqFn) **0**, `FEseqobject_SeqFn` (0x801DFCEC) **0**, `mainSetBits(117)` **0** (reads 169: 85 SB_Galleon / 84 FEseqobject_update), frente a `FEseqobject_update` 84 / `ObjSeq_start` 86 / `ObjSeq_update` **11.386** (6.049 animatedobj + 3.204 runBgCmds + 2.133 dll501). Es decir: no falta solo el código 1 en una cola que funciona — **ninguna acción de secuencia se ejecuta nunca en host, para ningún estado, así que ninguna cola se encola nunca**. La rama LLAMADA queda descartada: no hay drenajes que "no lleguen al slot del mapa".
- **Caveat de Tramo 14 cerrado (audio): `StartPreparedStream` = nunca llamado, no "llamado pero abortó".** Prueba triple: contador total 0 por ambas vías visibles; `pend6118 = 0` en las 49 muestras (una llamada abortada lo habría dejado a 1); `veto60F4 = 0` en las 49 muestras; las 86 llamadas a `IsPreparing` vienen de `AudioStreamCallback` (84) y `pauseMenuUpdate` (2), ninguna de `StartPreparedStream`. El hueco de audio es consecuencia, no causa.
- **Controles v1b** (los pases sí avanzan, pero nunca a acción/drenaje): `RebuildCurveStateToFrame` 0, `EvaluateCondition` 0, `RefreshActionCursor` 0, `FindConditional` 0, frente a `SetupInitialPlaybackState` 3.204 (solo `lr=0x80087A9C`, rama `[SeqState+0x7E]==2` → salida del pase; verificado: sus 116 objetos son exactamente los 116 de los pases runBgCmds, conteo por objeto idéntico) y `UpdateCurvePosition`/`DoBgCmds0D` 7.432 cada uno (cola del pase). Restan 750 pases con salida temprana. Hipótesis principal para v3 (no probada): en host `[SeqState+0]` es 0 (destino cae al propietario y salta el drenaje) y/o `[slot+0x3C4C]` es 0 (salta el rebuild).
- **Corrección a Tramo 14 §6:** la rejilla real de chunks (`codigo/generated/chunks/`, inicios `...26E0 + k·0x4000`) hace que los ceros de `StartPreparedStream`, `ExecuteActionCommand`, `seqDoSubCmd0B` y `FEseqobject_SeqFn` sean totales, no "no concluyentes". Solo `objCallSeqFn` tiene un sitio invisible (el de `SetupInitialPlaybackState`, intra-chunk 0032), cubierto por `FEseqobject_SeqFn = 0`, visible por cualquier vía.
- **Muestreo de cola: declarado NO resuelto por muestreo, sin maquillar.** El único candidato estricto (`0x803F916C`, `slot57=0`, `cnt=0`) es un falso positivo (slot ≠ 25/26 de FE, sin propietario `[anim+0xB8]`, contenido con constantes flotantes/punteros a código); un escaneo post-hoc por `slot57 ∈ {25,26}` resultó inutilizable (el byte aparece en texto/datos del juego). No se afirma "cola vacía en muestras": con `seqDoSubCmd0B = 0` global, la conclusión no depende del muestreo. Sí medido en las 49 muestras: `veto=0, pend6118=0, f60AE=0, f60B0=0, pendSub=0` siempre; FE bien cableado en RAM (`fe_bc=0x801DFCEC`, `fe_b8=0x8120C850`, `fe_b4`: −1 en 41M, 25 en 42–45M, 26 en 46–49M); bit 117 = 0 siempre.
- **Visible máximo:** no hay contador directo en estos logs; no se inventa número. Cota probada: **≥640 objetos** (bytes 636–639 sobrescriben el LR, igual que Tramo 13).
- Parche: **NO hay** (condición del encargo no cumplida). Ningún hueco HLE concreto y evidenciado: modelar `StartPrepared`/`playing` no haría correr ninguna acción ni pondría el bit 117, y forzarlo sería inventar. Los criterios de verificación del encargo quedan como definición de "superado" (`mainSetBits(117,1) ≥ 1` con `lr=0x801DFD9C`, `bit117=1`, 0 `Play(105)` nuevos/1M, Override estable, visible < 616, pasar de `sceneDraw`) — ninguno se cumple hoy.
- Siguiente experimento exacto (v3, observación): (1) muestrear por 1M las tablas globales por slot (base `0x80398278`) para el slot FE (25/26) y testigos: byte `[base+slot+0x3C4C]` (guarda de rebuild/drenaje), `[+0x338C]`, `[+0x3538]`, `[+0x3CF4]`, medio `[+slot·2+0x3A98]`; discriminador: `0x3C4C` del slot FE 0 frente a otros slots ≠ 0 (específico) o 0 en todos (global en host); (2) barrido estático (con `skipdata`) buscando el escritor de `[SeqState+0]` (destino) en `ObjSeq_start`, `SetupInitialPlaybackState` y callees de `objSetupObject`; si solo se escribe desde una acción, el bucle se cierra (destino 0 ⇒ drenaje saltado ⇒ secuencia atascada ⇒ fuga ⇒ desbordamiento); (3) solo con 1–2 resueltos, diseñar parche HLE contra los criterios arriba; si no, censo por pase de qué guarda saca a cada pase de `ObjSeq_update`, no parche.
- Pack C-mapa re-confirmado: **142 ficheros / 82.413.172 B, CSV idéntico a Tramo 14. Sigue CANDIDATO PARCIAL, prohibido presentarlo como pack del mundo.**

### 15B — Surround: matriz DPL FALSADA (no "sin resolver"), ningún diff, parche v2 sigue retenido
- Desensamblado completo de `dspSlave` (3312 palabras, `gcdsptool` 1.0.6) y emulación del camino de salida real cmd17 → cmd9 → cmd14 con un intérprete DSP mínimo construido aquí (validado en cmd17: 1310 pasos, buf0 == −S2 exacto). Orden CPU verificado en `salBuildCommandList`: cmds 0–6 por estudio, luego 17 (`dspSurround`), 9 (main del master), 14 (AI), 15.
- **cmd14 solo lee las secciones L/R** (DRAM `0x0000`/`0x0140`) para la salida AI. La sección S de cmd9 (`0x0280`) es sobrescrita por el DMA1 de cmd14 y jamás se lee. El bus S de las voces nunca llega a AI.
- **`dspSurround` es siempre cero en frames reales**: grep completo del decomp — solo se aloca (160 s32), se pone a cero en init y se libera; ningún código CPU ni del juego lo escribe. La "adición de surround" de cmd9 suma 0.
- **Sin coeficientes ni retardo/fase**: escaneo re-verificado (`0x5A82`/`0x5A80`/`0x4000`/`0x2D41` = 0 ocurrencias). La fórmula genérica `Lt = L + 0.707·S, Rt = R − 0.707·S` queda explícitamente descartada: S no aparece en ninguna lectura del camino de salida.
- **El espejo es real pero a nivel de voz**: `sndOutputMode(SURROUND)` pone `synthFlags & 2`, entonces `lastSPan` se calcula desde el span (`synth.c`) y en STEREO se fuerza a 0; `salCalcVolume` aplica el espejo `interp(2−span)` a volL/volR por voz. Los buffers main L/R del huésped YA contienen estéreo con espejo. En estudios STD el resto va al bus S (descartado); en DPL2 va a AUX B → efectos (dependiente del efecto, no una matriz fija). El tipo de estudio se fija en init, no con el modo de salida.
- **Medición del modelo de frame real (S2 = 0)**: AI == `hi16(main L/R)` en 306/320 muestras, **0 discrepancias** fuera de artefactos. Las 14 restantes son un quirk del código del huésped (header de cmd9, 2 muestras por chunk de 48: j=0 a −32766, j=1 a +2176…+2752) — no codifica S, no depende de span, y no debe reproducirse ni "arreglarse" en el port.
- Falsadores y anomalías documentadas (no ocultas): DMA-setup de cmd9: el código literal lee el descriptor del siguiente chunk desde la posición post-mezcla (`0x0EA4`, datos surround), imposible como comportamiento comercial; el código de actualización de tabla mantiene el descriptor pretendido en `0x0E44`, que es el modelo usado para medir la mezcla (la mezcla en sí es código literal e inequívoco). Orden de par LDX adoptado L-primero: único orden que hace de la extracción de cmd14 la conversión estándar "mitad alta" para muestras main s32 a plena escala (el mezclador acumula en 40 bits y guarda (M,L) completos); el orden contrario haría toda la salida AI ruido de mitades bajas, falsado por el audio normal del juego. Orden de canales AI (cmd14 emite sección `0x0140` antes que `0x0000`): nota abierta, irrelevante para S, que está ausente en ambos casos.
- Integración: **NINGUNA** (según la regla del encargo: integrar solo si la matriz quedaba evidenciada; no lo está, está falsada). No hay diff contra `4088fc6`, no se toca `Tick()` ni el PCM, el parche v2 sigue retenido, y el diseño opt-in de matriz NO debe construirse (plegar S sería infiel al huésped, que descarta S). El evento CC19 (4,6,127) de la canción 5 tampoco se añadió (opcional, inaudible por midi 6 inerte, sin prisa).
- **Comprobación del coordinador (espejo en el bridge):** verificado en `app/src/main/cpp/audio/audio_bridge.cpp`: el bridge NO aplica espejo — el PCM de nota MusyX hornea gl/gr solo desde el pan CC10 (balance lineal) y CC19 se guarda solo como estado. Esto NO es un hueco que integrar sin más: en el huésped, en STEREO (modo por defecto del juego y modo de render del port) `lastSPan = 0` siempre, así que espejo = 1 y el comportamiento actual ya es fiel. Aplicar un espejo derivado de CC19 sin puerta de modo atenuaría voces que el huésped en estéreo NO atenúa — sería infiel, no una corrección. Consecuencia: un futuro modo surround fiel en el port NO necesita matriz (S se descarta): sería espejo en ganancias L/R por voz + S descartado, con puerta de modo (el diseño opt-in de Tramo 14, revisado: sin acumulación de S codificada). No se integra este tramo porque exige la plomería de modo (interruptor → SharedPreferences → JNI → flag del bridge) para no añadir estado muerto, y no es bloqueador de jugable. Siguiente experimento exacto: implementar ese modo con puerta (OFF por defecto, PCM estéreo bit-idéntico con espejo = 1) y tests de ganancias atenuadas por span solo con el modo ON.

### 15C — Kernel 2:1 y byte Z8: bloqueo Dolphin RESUELTO, ambos decididos con referencia real, diff vacío justificado
- **Bloqueo de volcado resuelto (tres causas encadenadas):** (1) el .dol del host no existe dentro del sandbox Flatpak: el manifiesto de Dolphin no concede acceso a home (verificado con `flatpak run --command=ls`: sin override, "No such file or directory"; con `--filesystem=host`, el fichero aparece); los lanzadores del tramo usan `--filesystem=host` siempre (los `TimePlayed` del Tramo 14 no prueban ejecución: Dolphin registra el intento aunque el fichero sea inaccesible); (2) diálogos modales: la primera GUI con fs-host mostró en captura Xvfb el consentimiento de Analytics y un pánico `GatherPipeBursted` (CommandProcessor.cpp:390); solución por configuración, con claves confirmadas en el binario (`PermissionAsked`, `UsePanicHandlers`): `Dolphin.ini` con `[Analytics] PermissionAsked=True, Enabled=False` y `[Interface] UsePanicHandlers=False`; (3) la causa decisiva: `GX_Init(NULL, 0)` cuelga: con sondas `SYS_Report` (visibles en `dolphin.log` solo tras parada limpia desde la UI; los SIGKILL impedían el vaciado) se acotó: todo hasta `VIDEO_Flush` imprime, `GX_Init` nunca retorna; el depurador mostró PC `0x8000d8cc` = `KThreadIdleMain` (hilo principal dormido); con FIFO explícito (`gp_fifo[256*1024]`, `GX_Init(gp_fifo, sizeof)`) retorna en ~7 ms. A partir de ahí: presentación real (quad rojo `(255,0,0)` en ventana y volcado XFB) y volcados reales. El verde `(0,135,0)` de todas las ejecuciones anteriores era la conversión BT.601 de YUV todo-cero: el XFB inicial sin escribir. **Lección: con esta toolchain, siempre FIFO explícito; `GX_Init(NULL,0)` cuelga bajo Dolphin 2609-127.** Herramientas nuevas reutilizables: `run-dolphin.sh`/`run2.sh`/`run3.sh`/`run4.sh` (D-Bus + Xvfb + fs-host + `-u dolphin-user/` + capturas ffmpeg), `xtool.py` (ventanas X + clics XTest vía python-xlib, permitió pausar, Show PC y parada limpia). Ningún proceso Dolphin queda corriendo.
- **Kernel 2:1: BOX en ambos ejes, ambas paridades (referencia Dolphin).** Homebrews impulso Tramo 14 reconstruidos con FIFO explícito, filtro run39 `{7,7,12,12,12,7,7}`, copia 320×240 RGB565. Cada ejecución produjo el volcado de textura `xfb1_n000000_320x240.png`, convertido a RGBA8 y pasado por `kernel_ref_t15` (autotest 33/33): vertical / fila par 100 → fila 50, valor 128, **box, peor diff 5** (point 127/128, tap7 87); vertical / fila impar 101 → fila 50, valor 127, **box, peor diff 4** (tap7 86); horizontal / col par 100 → col 50, valor 127, **box, peor diff 4**; horizontal / col impar 101 → col 50, valor 128, **box, peor diff 5**. Un solo texel no-cero en los 4 casos, resto exactamente 0; sin espejo Y (espejo caería en 189/190); tap7 ([27,47,27] par, [27,47,47,27] impar) excluido por 86+ de diferencia. La ruta RGB565 re-cuantificada da un falso negativo en la pasada 0 (diff 9 por doble cuantificación); la ruta RGBA8 es la autoritativa. **El port ya implementa box: sin diff. El ejecutor separable 7-tap NO se implementa porque la referencia lo descarta.** Matiz honesto: Dolphin da box aunque el homebrew fija los taps run39; no se confirmó en log FIFO que Dolphin los recibiera. Lectura exacta: en la configuración ejecutada, la copia EFB→textura de Dolphin 2609-127 produce box. Si el HW real aplicara tap7, el port diferiría; la certeza HW queda pendiente (consola + captura o log FIFO). La confirmación del filtro emitido en log FIFO sigue pendiente, no bloqueante para la decisión de forma.
- **Byte Z8: byte ALTO (H0), con acuerdo cuantitativo.** La rampa Tramo 14 tenía tres bugs, encontrados y corregidos en este tramo: (a) quad de fondo con Z=0 + LEQUAL bloqueaba las franjas; (b) profundidad inicial del EFB a 0 (no al clear lejano); (c) causa raíz: con `guOrtho(..., near=0, far=1)`, `ndc_z = -2z−1`, así que solo z=0 sobrevivía al clipping — por eso solo dibujaba la banda x<16. Con Z negada (z'∈[−1,0]) + test GX_ALWAYS, la rampa completa dibuja. Resultado (`dump-depth4-640x480.png`, `analyse.py`): controles planos distintos: x<16 → 0,0; x≥624 → 255,0 (la primera rampa, toda a cero, se descarta explícitamente como experimento inválido, no como H0); perfil monótono 0→255, 0 saltos |d|>16 en 639 transiciones; acuerdo punto a punto con H0: x=100 → 35 (predicho 35,2), x=320 → 128 (predicho 127–128), x=500 → 204 (predicho 203,3). H1 (diente de sierra ~0x66/columna) descartado. **El port ya implementa `trunc(avg·255)` en `ExecuteEfbCopyZ8`: el cambio H1 de una línea NO se aplica.** Alcance: el experimento aísla la selección del byte (plena resolución); el downsample box de la copia Z8 hereda la evidencia del kernel de color pero no se midió por separado para Z. Nota: los volcados XFB sufren distorsión gamma en Dolphin (medido: observado ≈ g²/255); las decisiones usaron volcados de textura (lineales), no XFB.
- **Suites y diff:** suites EFB contra 4088fc6 NO re-verificadas, como indica la tarea: no se tocó código del port, así que no procede. Quedan como en Tramo 14 (contra 4289f36: T10a529 45/45, T11 74/74, T9 62/62, T8 33/33, T7 53/53, T6 76/76, T5 80/80; decisor 33/33 re-validado aquí como `kernel_ref_t15`). **DIFF vacío, justificado**: ambas decisiones confirman el código actual; cualquier diff habría sido cambiar código correcto por código contradicho por la evidencia. Solo cambiaría la conclusión una referencia HW de tap7 o del byte bajo. Desde esta vía, lo pendiente ya no es kernel ni Z8 (cerrados contra Dolphin): certeza HW del filtro tap7, confirmación del filtro en log FIFO, y el resto del port (bit 117/unknown_pc, Pack C hasta mundo, matriz DPL, prueba GX26) que pertenece a otras vías.

### Integración Tramo 15 en esta rama
- **Ningún parche de código aplicado, deliberadamente**: la vía A no tiene parche honesto (ninguna acción ObjSeq corre en host; forzar el bit seguiría siendo inventar); la vía B no integra nada (matriz falsada; el opt-in de matriz no debe construirse); la vía C tiene diff vacío justificado (box y byte alto ya implementados). Aplicar cualquiera habría sido maquillar el tramo.
- **Sin APK nueva**: con cero cambios en el código del port, una GX27 sería GX26 con otro número de versión — ruido, no avance. La APK de prueba vigente sigue siendo **GX26** (12.776.102 B, SHA-256 `f5e9469dc3839b1f7d8853c98d550b93168a9aa0ed6906da5f9b0e5a79ade30c`, v17 / `0.17.0-gx26-test`; desinstalar GX25 antes de instalarla; guía GUIA-PRUEBA-GX26.md). Este commit es solo documentación del Tramo 15. Trabajo de las vías en `work-port/tramo15-{bit117,surround,kernel}/`. Cuestión 1367 sigue abierta (acotada, no resuelta).
- Etiqueta: PRUEBA — sin juego real verificado en Tab S8, sin menú legible, sin mundo estable (el host muere en `unknown_pc` tras lanzar el mapa), sin rumble positivo verificado, inerte sin `sfa-data/`; nunca jugable al 100 %.

## Tramo 16 (2026-10-27, este tramo): bit 117 v3 (guardas 0 globales, cerrojo circular, sin parche) + modo surround con puerta (integrado) + confirmación FIFO — APK GX27 de prueba (NO jugable)

### 16A — Bit 117 v3: ambas guardas son 0 GLOBALES; el bloqueo es un cerrojo circular, sin parche
- Reproducción exacta (carrera v1, idéntica a Tramos 12–15): **49.571.763 despachos**, ticks 496, PADRead 1017, retrace 1051, `pc_final=0x80000100`, disparo disp 36.400.000 / padread 840, `curUiDll=1, chapter=0, launch=1`, SFX 39, sndSeq 3 (22/95/94), primer error mm región 2 `used=849 avail=850`, **1.455 errores `No more slots`**, LOADED Override 422 / staffAnim 84 / AnimCamera 84 / FireBall 252. Corrupción LR re-confirmada (`00 00 01 00` desde `getVisibleObjects+0xAC`). PCTRACE idéntica a Tramo 15: `StartPreparedStream` 0, `ExecuteActionCommand` 0, `objCallSeqFn` 0, `seqDoSubCmd0B` 0, `mainSetBits(117)` 0, `mainGetBit(117)` 169, `FEseqobject_update` 84, `ObjSeq_start` 86, `ObjSeq_update` 11.386.
- **Muestreo por 1M de las tablas por slot (base `0x80398278`), 49 muestras `T16: SAMPLESLOT`, valores por muestra (no solo el final):** el slot FE solo es válido en 42M–49M (25 en 42M–45M, 26 en 46M–49M): `3C4C=0, 338C=0, 3538=40, 3CF4=0, 39E8=0, 3A98=106` (= seq 105+1) en las 8 muestras. Las filas 1M–41M NO son FE (`feSlot` 0/−1 antes de que exista el objeto; su columna FE es el slot 0) — se declara así, no se presentan como medidas del FE.
- **Global, no específico del FE:** `nz3C4C=0, nz338C=0, nz3CF4=0, nz39E8=0` en las **49 muestras**. Testigos del título (slots 25/26, 3M–40M, 38 muestras × 2, idénticos): `3C4C=0, 338C=0, 3538=48, 3CF4=0, 39E8=0, 3A98=1368` (= seq 1367+1). El único byte no-nulo jamás es `3538` (flags de secuencia copiados en `ObjSeq_start`, no una guarda) y `3A98`.
- **`[SeqState+0]`:** `feDest = [0x8120C850+0] = 0x00000000` en las 49 muestras. Caveat declarado: ese struct no parsea como SeqState vivo (`+0x57=0`, `+0x62=8202`, `+0x94=0x40800000` = float 4.0), y ningún pase `ObjSeq_update` corre jamás para el propietario FE (0/11.386, llamadores 6.049/3.204/2.133, todos en chunks distintos, conteo total). La afirmación precisa es: **ningún destino enlazado a FE existe en host** (`objCallSeqFn=0`, `FEseqobject_SeqFn=0`).
- **Barrido estático (skipdata): escritor único y cerrojo.** Único escritor no-nulo de `[SeqState+0]`: `ObjSeq_resolveTargetObject` (`0x80081CD8`), con ramas por `[tipo+0x1C]` (0 y 17 → 0; 1/2 → objeto de `0x8002BB60/20`; 3 → 0 salvo callback; resto → `0x8002BB60`, `0x8002E248` o búsqueda del objeto más cercano). Su único llamador en todo el DOL es `ToggleCommand3Target+0x4C`. Los demás escritores solo ponen 0: `Rebuild+0x178` y `Toggle`-off (`0x80086398`). `Toggle` solo lo llaman `Rebuild+0x1EC` y `ExecuteActionCommand+0x2A4` (= 0 en host). En `Rebuild`, el comando de curva **3** es el que llama a `Toggle` (tabla de salto en `0x80310A68`, 12 entradas, todas dentro de `Rebuild`). `[3C4C]` no tiene escritor directo: es un latch que `runBgCmds` copia de `[3BF4]` cada frame; `[3BF4]` solo lo escribe `objCallSeqFn` (retorno de SeqFn o 1). De ahí el cerrojo: drenaje exige destino≠propietario → exige `[SeqState+0]≠0` → exige `resolve` → exige `Toggle` → exige `Rebuild` (cmd 3) o `ExecuteAction` (0) → `Rebuild`-desde-`update` exige `[3C4C]≠0` y `[39E8]≠0` (ambos 0).
- **Corrección a Tramo 15:** `Rebuild` sí corre ≈3.204 veces vía `SetupInitialPlaybackState` (llamada sin guarda en `0x80085F2C`, intra-chunk 0032, invisible para PCTRACE) y aun así no produce ningún enlace. La pregunta se desplaza a: ¿las listas de curva de esos estados no contienen comando 3, `Toggle` va a off, o `resolve` devuelve 0? Sin decidir entre (a)/(b)/(c), no hay hueco HLE concreto y **no se diseña parche** (tampoco se crea `patches/`). Criterios de verificación incumplidos todos: `mainSetBits(117,1)=0`, `bit117=0`, `Play(105)` sigue, Override 422/2, visible ≥640, muerte en `sceneDraw`.
- **Nota honesta:** una primera carrera se lanzó por error con `v1 256 -80` (pulso A con stick abajo) en vez de `v1 256 0` (A solo, como Tramo 15); divergió (tope 60M, `launch=0`) y se descartó por completo (carpeta borrada, ningún dato usado). La carrera válida usa los argumentos exactos de Tramo 15 y reproduce al despacho.
- **V4 propuesto (en el informe, §7):** (1) censo por 1M de las listas enlazadas por slot (`base+slot*0x80`, 16 entradas `(objeto, propietario)` que `Toggle`-on escribe): ¿aparece jamás el FE como objeto? (2) Instrumentar una copia de observación del chunk 0032 (misma técnica que `patched/chassis.cpp`, sin tocar el repo) que cuente `Rebuild` vía `Setup`, comandos 3, `Toggle` on/off y rama de `resolve`. Solo con eso resuelto, diseñar parche contra los criterios de §6.
- Pack C-mapa re-confirmado: **142 ficheros / 82.413.172 B, CSV byte a byte idéntico a Tramo 14/15** (SHA-1 del CSV `33d032e8e6c3969dbacaf0bbca46bf98838128b0`). Sigue **CANDIDATO PARCIAL, prohibido presentarlo como pack del mundo.**

### 16B — Surround con puerta: integrado (sin matriz, sin S, sin estado muerto)
- **Fórmula exacta**, verificada contra `SFA-Decomp/sal_volume.c` (tabla pan `{0, 0.7079, 1, 1}` l.32; espejo `2 − spanPos` l.165–172; `CalcBus` l.69–86, que espeja el nivel *antes* del reparto por pan): `mirror(span) = interp(2 − span)` → span 0→1, 1→0.7079, 1.381→0.4382, 2→0. Es un factor **común a L y R** (no cambia el balance CC10).
- **Punto de aplicación**: el render del note-on (`StartMusicNote`), donde se hornean `gl/gr`. `Tick()` no se toca. El parche subsume el estado v2 retenido (Tramo 13/14) y lo convierte en estado consumido: ya no hay estado muerto.
- **S descartado**: nada se suma a L/R (Tramo 15: cmd14 jamás lee S). SFX y stream no se tocan.
- **Puerta**: `AudioBridge::SetSurroundEnabled(bool)`, OFF por defecto. Solo afecta a notas que empiezan después de activarla (las voces ya horneadas no cambian, como en el huésped).
- **Tests host (todo host, sin Tab S8):** (a) puerta OFF, PCM bit-idéntico al prístino: escenario Tramo 14 — 10.991.744 frames, FNV-1a `0xc4f98f7aea63da2e`; canción 5 aparte: 281 notas, 1.318.912 frames, `0xae7d3c452c43d75e`. Ambos hashes coinciden con los publicados en Tramo 14. (b) Puerta ON, gemelo OFF/ON por `note_index`: 95 → 4 voces span 1 con energía ON/OFF **0.5011** (= 0.7079²) y 33 voces span 2 con PCM ON **todo ceros** (OFF no silencioso en las 33, no vacuo); 95 sec3 inerte (12 voces midi 3) y 5 midi 6 inerte (67 voces) con PCM **byte-idéntico**; 67 voces de la 5 con reads=true y span 0 idénticas (frontal sin cambio). Captura (reads, span) idéntica OFF/ON. **Test propio: 675 checks, 0 fallos.** (c) Regresiones re-ejecutadas contra el bridge Tramo 16: Tramo 14 **45/0**, Tramo 13 **58/0**, Tramo 12 **234/0**. Ninguna cifra se afirma sin re-ejecutar. Caveat honesto del muestreo: en la 5 se observan 275/281 voces; las 6 perdidas son midi 8 inertes de 16–27 ticks (diagnóstico en `build/diag_missing5.cpp`), ninguna voz atenuable queda sin cubrir.
- **Decisiones:** evento CC19 (4,6,127) de la canción 5: **NO añadido.** Es inaudible por construcción (las 9 macros de midi 6 no leen ctrl 19, `reads=false` con cualquier CC19); añadirlo solo cambiaría estado observable sin efecto audible, tocando tablas hoy fieles al primer pase medido. Queda documentado como en Tramo 14/15.
- **Qué NO es este modo**: no es Dolby Pro Logic, no codifica S, no cambia nada en estéreo por defecto, no sigue a `SaveData.soundMode` del juego. Es opt-in, no bloqueador de jugable.
- **Plomería Java→JNI: diseño exacto pero SIN verificar** (no hay build NDK de la parte Java, ni APK que la ejercite, ni dispositivo): SharedPreferences `sfa_settings`, clave `audio_surround_enabled`, defecto `false`; setter JNI `Java_com_starfox_port_MainActivity_nativeSetSurroundEnabled` en `native-lib.cpp`, con el obstáculo real documentado (la JNI no alcanza `app->userData`, necesita un puntero de proceso fijado al crear el runtime y limpiado en `Shutdown()`); vía recomendada B: getter Java `getSurroundEnabled()` + `ApplySurroundPreference(app)` tras `TryLoadData()`, con el patrón ya probado de `RequestSafPicker`. **No existe UI del interruptor** (`MainActivity` es `NativeActivity` sin UI Java): el parche no debe presentarse como "surround activable en la app" hasta que esa UI y la plomería se construyan y verifiquen en hardware. **En GX27 la puerta existe en código pero no tiene llamador: permanece OFF.** El modo no es activable desde la app en esta build.

### 16C — Kernel: confirmación FIFO conseguida; certeza HW sigue pendiente
- **Resultado principal: Dolphin SÍ recibió los taps run39, y aun así la copia da box.** El matiz pendiente del Tramo 15 queda cerrado en su primera mitad; lo único que sigue pendiente es la certeza HW.
- Dolphin no expone ningún log de texto de escrituras BP (verificado: `--help` sin flag de grabación, `Logger.ini` sin tipo FIFO/BP, grabación solo vía GUI Tools → FIFO Player). Así que se grabó el `.dff` real desde el diálogo GUI (navegación por teclado + clics localizados por grounding; el campo `File name:` solo aceptó texto con `Alt+N`, documentado en el informe): diálogo **2124 FIFO bytes, 0 memory bytes, 3 frames** (Frames to Record: 3). Fichero `impulse-fifo0.dff` (1.069.804 B, SHA-256 `291b8a92b31744de1a331b8005dc57297f2601b303bcccda85cd2a5c29be0f7d`).
- Análisis (`parse_dff.py`, salida CONFIRMADO): `BP 0x53 = 0x30C1C7` (`61 53 30 C1 C7`): **3 hits** en offsets 1068037, 1068745, 1069453. `BP 0x54 = 0x0071CC` (`61 54 00 71 CC`): **3 hits**, cada uno 5 bytes después de su `0x53` → **3/3 pares**. Separación 708 = 2124/3, y el par aparece dentro de la secuencia de copia (tras BP 0x01–0x04, antes de los registros de copia 0x49/0x4A/0x4D/0x4B/0x52). Secundario: las mismas palabras aparecen como imagen BPMem LE en offsets 652/656.
- Para que la grabación contuviera los BP hubo que construir una variante del homebrew (`impulse-fifo-log.c/.dol`, SHA-256 `f4fc920b…`, compilación 0 avisos): el original emite `GX_SetCopyFilter` una sola vez y luego queda en bucle vacío; la variante re-emite el mismo filtro cada frame. Prueba de cordura: su volcado 320×240 tiene el mismo SHA que el Tramo 15 (`1a48a87e…`), box diff 5.
- Reproducción Tramo 15 con `impulse-fifo-0.dol` original: volcado SHA **idéntico** al del Tramo 15, fila 50 valor 128, decisor box diff 5 / tap7 diff 87.
- Port re-verificado en solo lectura (`efb_copy.h`, HEAD `162ce3c`): box en `ExecuteEfbCopyTiledDownsampled` (línea 795, `sr / n` en 827) y byte alto en `ExecuteEfbCopyZ8` (línea 910, `trunc(avg·255)` en 936). **Diff vacío, justificado.** Única discrepancia: un comentario viejo en `ExecuteEfbCopyZ8` decía que el byte bajo se descartó "por argumento, no por medida" — desactualizado tras el Tramo 15; **corregido en este tramo (solo comentario)** a la medida de rampa Dolphin.
- **Certeza HW: evaluación honesta.** Queda como **"decidido con referencia Dolphin, certeza HW pendiente"** — no se afirma certeza HW. Lo que la cerraría, con discriminador exacto: el mismo experimento de impulso en consola GC real + lectura de la textura copiada desde RAM; un solo texel ~127/128 en 50 → box (port correcto); perfil [27,47,27]/[27,47,47,27] → tap7 (procedería el ejecutor separable). Ninguna vía HW es viable en este entorno (sin consola ni captura), y Dolphin no puede probar HW.
- Entrega y limpieza: INFORME.md completo en `work-port/tramo16-kernel/` (evidencia FIFO, evaluación HW, confirmación del port, límites explícitos: no se parseó el formato `.dff` oficial completo, solo búsqueda de bytes + aritmética 2124/3). Lanzadores/scripts reutilizables en esa carpeta: `run-fifo.sh`, `xtool16.py`, `type_text.py`, `parse_dff.py`; `xtool.py`/`kernel_ref_t15` por enlace al Tramo 15. Repo intacto en esa vía, ningún proceso Dolphin corriendo (`pgrep -x dolphin-emu` vacío), volcados por frame duplicados eliminados tras verificar SHA, conservado solo el par representativo de la sesión FIFO.

### Integración Tramo 16 en esta rama
- **Código integrado:** parche surround con puerta (`app/src/main/cpp/audio/audio_bridge.h/.cpp`, 243 inserciones, 7 borrados) + corrección de comentario obsoleto en `app/src/main/cpp/renderer/efb_copy.h` (byte bajo: de "por argumento, no por medida" a medida de rampa Dolphin, Tramo 15). Vías bit117 y kernel: solo documentación, sin código.
- **NDK integrado:** libstarfox.so 28.092.384 B, SHA-256 `aa9ff103d4b922467a23a26a22389c85851935374af8cfe78d5f6d73ed6f3e59`, ELF64 AArch64, `android_main` y `func_80003100` en T, `SurroundMirror`/`ReadsSurroundTrack` en T (`SetSurroundEnabled` es inline en la cabecera, sin símbolo propio), 0 `mem_/ppc_/func_/dolrecomp_` sin resolver, 228 undefined solo sistema.
- **APK GX27 de prueba:** código `0a84ae2`; APK `android-port-base/app-debug-gx27-test.apk` (12.776.102 B, SHA-256 `5aebb3f0f7431a57cf8b6d4df83fcb729035c81d814f8989e4632ef388e893ba`, v18 / `0.18.0-gx27-test`, apksigner v2+v3, zipalign OK, solo permiso VIBRATE, lib interior SHA-256 `aa9ff103d4b922467a23a26a22389c85851935374af8cfe78d5f6d73ed6f3e59` idéntica al build NDK; certificado SHA-256 `7900c20080c1a6f588392597191be93a2acf35cd922def9b774babec3673bbef`, distinto del de GX26 → desinstalar GX26 antes de instalar GX27; keystore de prueba NO commiteado). Guía: `GUIA-PRUEBA-GX27.md`.
- Etiqueta: PRUEBA — sin juego real verificado en Tab S8, sin menú legible, sin mundo estable (el host muere en `unknown_pc` tras lanzar el mapa), sin rumble positivo verificado, inerte sin `sfa-data/`; nunca jugable al 100 %. Cuestión 1367 sigue abierta (acotada, no resuelta).

## Tramo 17 (2026-10-27, este tramo): bit 117 v4 (bucle de Rebuild que no arranca + cargador de animación que aborta en la magia) — SIN APK nueva (GX27 sigue vigente)

- Reproducción exacta (carreras v1/v1b/v1c/v1d/v1f, idénticas a Tramos 12–16): **49.571.763 despachos**, ticks 496, PADRead 1017, retrace 1051, `pc_final=0x80000100`, disparo disp 36.400.000 / padread 840, `curUiDll=1, chapter=0, launch=1`, SFX 39, sndSeq 3 (22/95/94), 1.455 errores mm, LOADED Override 422 / staffAnim 84 / AnimCamera 84 / FireBall 252. PCTRACE heredada idéntica (`StartPreparedStream` 0, `ExecuteActionCommand` 0, `objCallSeqFn` 0, `seqDoSubCmd0B` 0, `mainSetBits(117)` 0, `mainGetBit(117)` 169, `Setup` 3.204, `Rebuild` inter-chunk 0).
- **Las tres sub-hipótesis de Tramo 16 quedan falsadas a la vez, por un hecho anterior:** censo de enlaces por slot (49 muestras por 1M, `base+slot*0x80`, 16 entradas): `nz = 0` siempre, FE jamás como objeto ni propietario → `Toggle`-on no corre nunca. Copia de observación del chunk 0032: `rebuild = 3204, setup = 3204, update = 0`, sobre **116 estados distintos** (top `0x81210A90` ×42), pero `list_null = 3204, list_nonnull = 0, cmd_sum = 0, cmd_iter = 0, cmd3 = 0, toggle = 0, on = 0, off = 0, res_* = 0` (PCTRACE `resolve` = 0 como cross-check). `Rebuild` toma la rama de lista nula antes del bucle: no hay lista, luego no hay comando 3 que discutir, ni `Toggle`-off, ni `resolve`-0. Los estados son vírgenes (`[+0x94] = [+0x62] = [+0x57] = 0`; `state = owner + 0x110` en las 20 muestras; `s7E = 2`, la rama de `update` que llama a `Setup`).
- **Barrido estático:** en todas las funciones `ObjSeq_*` el único escritor a `[SeqState+0x94]` es `seqState_free` (pone 0). El único escritor no-nulo de todo el DOL con pinta de SeqState es `objLoadAnimdata` (`0x800825B8`, `stw r3, 0x94(r29)` en `0x80082704`; también `+0x62`, `+0x98`, `+0x57`, `+0x7E`, y `seqState_init` al final). No tiene llamadores `bl`: se despacha por la tabla `ObjSeq_funcs` (`0x80310638`).
- **El cargador corre pero no completa (v4b/v4c):** PCTRACE `objLoadAnimdata` = 851 despachos (850 entradas contadas en etiqueta; diferencia de 1 sin explicar, sin efecto en las conclusiones), llamadores `lr = 0x8016CADC` (599, zona `animatedobj_update`) y `0x801E60E8` (252, zona `dll501_update`); `seqState_init` = **0** (ninguna ejecución llega al final); `seqState_free` = 226. Embudo (850 contados): `id` nunca −1, `getTableFileEntry` no-0 siempre (850/850), y las dos comparaciones de magia fallan siempre: `strncmp(buf, "SEQA", 4) != 0` (850/850) y `strncmp(buf, "SEQB", 4) != 0` (850/850) → rama de error `"<objLoadAnimdata> Warning ACRomTab is NULL"` + epílogo antes del conteo, del alloc y de `init` (por eso `cnt_* = 0/0` y `alloc_* = 0/0`: esas etiquetas no se alcanzan). Corrección: los dos `0x80291f84` del cargador son `strncmp`, no lecturas DVD. Las etiquetas SÍ están bien en host (`ram.bin` final: `0x803DD0E4 = "SEQA"`, `0x803DD0EC = "SEQB"`): lo que falla es la cabecera de 8 bytes que produce `loadAndDecompressDataFile`, no las etiquetas. El aviso no aparece en los logs de host (la función de impresión no vuelca ahí); la evidencia es el embudo.
- **Dato relacionado, NO cadena probada:** 12 ficheros existen en disco en mayúsculas pero el juego los pide en minúsculas en subdirectorios y el resolutor solo hace fallback case-insensitive en raíz: `gamefront/`/`shipbattle/`/`warlock/` × `animcurv.bin`, `animcurv.tab`, `voxmap.bin`, `voxmap.tab` (en disco `ANIMCURV.bin`, `ANIMCURV.tab`, `VOXMAP.bin`, `VOXMAP.tab`) → 20 líneas `DVDOpen ... no encontrado` por carrera. Es un hueco HLE real y medible, pero no se afirma que cause la magia fallida (el cargador no abre por nombre visible y la entrada de tabla sí se resuelve). Es la primera hipótesis de v5, no una conclusión.
- **Sin parche** (criterios incumplidos todos: `mainSetBits(117,1) = 0`, `bit117 = 0`, `Play(105)` sigue, Override 422/2, visible ≥640, muerte en `sceneDraw`). No se crea `patches/`. **v5 definido:** (1) instrumentar `loadAndDecompressDataFile` (`0x800466e0`, chunk_0017) solo para llamadas del cargador (`lr = 0x8008268C`) y loguear los 8 bytes producidos; (2) probar en harness (copia, sin tocar el repo) el fallback case-insensitive en subdirectorios y ver si el cargador completa (`init > 0`, listas no nulas, `Toggle` > 0); (3) solo entonces diseñar parche HLE contra los criterios.
- **Notas honestas:** una v1e se lanzó dos veces sobre el mismo directorio y la segunda reutilizó el `memcard-a.raw` de la primera (divergió a `dispatch_cap` 60M, sin muerte); se descartó por completo y la carrera válida con el mismo binario es v1f (directorio nuevo). Un intento de instrumentación v4c puso un ancla en el chunk equivocado (`label_80082708` no existe en chunk_0031: `objLoadAnimdata` cruza la frontera en `0x800826E0`); la versión correcta divide el embudo entre chunk_0031 (hasta el conteo) y chunk_0032 (alloc). Pack C-mapa re-confirmado: 142 / 82.413.172 B, CSV SHA-1 `33d032e8e6c3969dbacaf0bbca46bf98838128b0`, sigue CANDIDATO PARCIAL.
- Trabajo en `work-port/tramo17-bit117/` (INFORME.md, `patched/chunk_0031.c`, `patched/chunk_0032.c`, `patched/chassis.cpp`, `test_tramo17.cpp`, `parse_t17.py`, `static-scan.txt`, carreras v1/v1b/v1c/v1d/v1f; v1e descartada).

### Integración Tramo 17 en esta rama
- **Sin APK nueva**: con cero cambios en el código del port, una GX28 sería GX27 con otro número de versión — ruido, no avance. La APK de prueba vigente sigue siendo **GX27** (12.776.102 B, SHA-256 `5aebb3f0f7431a57cf8b6d4df83fcb729035c81d814f8989e4632ef388e893ba`, v18 / `0.18.0-gx27-test`; desinstalar GX26 antes de instalarla; guía GUIA-PRUEBA-GX27.md). Este commit es solo documentación del Tramo 17. Cuestión 1367 sigue abierta (acotada, no resuelta).
## Tramo 18 (2026-10-27, este tramo): bit 117 v5/vía B — fallback case-insensitive por componentes INTEGRADO — APK GX28 de prueba (NO jugable)

- **Vía A (host, observación, sin parche):** en las 850/850 llamadas del cargador, `loadAndDecompressDataFile(13, dest, entrada, 8, 0, 0, 0)` deja en `sp+0xC` siempre los mismos 8 bytes `00 00 00 00 FF 00 FF C4` (`w0=0`, `w1=0xFF00FFC4`; no es buffer a cero; `ret_seqa=0`, `ret_seqb=0`, `changed=850`, `r3=0` en 850/850 que el cargador ignora). Decisión: **(i) la fuente no se resolvió/cargó en host**, falsada (ii): `getTableFileEntry(14, idx, &sp+8)` devuelve éxito 1 en 850/850 pero escribe 0 en `sp+8` en 850/850 (medido por dos puntos independientes); índices plausibles y estructurados (13 distintos: 1×6, 0x1687/0x1688×2, rango contiguo 0x1DA–0x1E3×84 cada uno; 13 índices → 1 única salida). Corrección a Tramo 17: su `load_hdr_nonzero=850` contaba el código de retorno, no la entrada. Queda sin decidir un nivel más abajo: por qué la tabla 14 da 0 (base no cargada vs índices fuera del rango cargado) y qué lectura interna produce el patrón `FF00FFC4` con entrada 0; medida que falta: instrumentar `getTableFileEntry` por dentro (chunk_0016: base de tabla para el argumento 14, índice y palabra leída, si la base apunta a RAM cargada o a ceros). Vía A NO probó el fallback ni afirma que sea la causa: la entrada 0 no se explica por un nombre visible en ese punto.
- **Vía B (host, harness, fallback verificado, bit 117 sigue a 0):** fallback implementado solo en la copia del harness (`patched/hle.cpp`, `Hle::DvdOpen`): si la apertura exacta de una ruta con `/` falla, resuelve CADA COMPONENTE por separado con `strcasecmp`. Detalle clave: en disco los ficheros son `ANIMCURV.bin/.tab`, `VOXMAP.bin/.tab` (tronco en mayúsculas, extensión en minúsculas), así que un simple "pasar a mayúsculas" daría `ANIMCURV.BIN`, que tampoco existe.

| Medida | Base (sin fallback) | Fallback |
|---|---|---|
| `DVDOpen ... no encontrado` | 20 líneas / 12 caminos | **0 líneas** (13 resoluciones por componentes, los 12 caminos) |
| Punto final | `unknown_pc 0x80000100`, 49.571.763 desp. | `dispatch_cap`, 60.000.000 desp., `pc_final=0x802481D8` (pasa el punto de muerte) |
| `ticks` / `PADRead` / `retrace` | 496 / 1017 / 1051 | 600 / 1168 / 1202 |
| Embudo cargador: `load_total` / `load_r1_zero` (SEQA) / `seqState_init` | 850 / 0 / 0 | 20 / **14** / **14** (el cargador completa 14/20) |
| `load_r1_nonzero` / `load_r2_nonzero` | 850 / 850 | 6 / 6 (6/20 cargas siguen fallando ambas magias, sin investigar) |
| `Rebuild` total / `list_null` / `list_nonnull` | 3204 / 3204 / 0 | 18 / **0** / **18** |
| `cmd3` / `Toggle` / `on` | 0 / 0 / 0 | **18** / **18** / **18** |
| Censo LINK `nz > 0` | 0/49, máx 0 | **58/60, máx 6** |
| `FEseqobject_SeqFn` | 0 | **235** (pero con `lr=0x80085190`, no el `lr=0x801DFD9C` del criterio) |
| `mainSetBits(117,1)` / `bit117` final | 0 / 0 | **0 / 0 (a 60M)** — criterio NO cumplido |
| SFX / `Play(105)` / LOADED Override | 39 / 84 / 422 | 174 / 1 / 7 |
| `chapter` / `launch` | 0 / 1 | 0 / 1 (progresa, SIN mundo observado) |

  Cadena probada hasta `Toggle`-on: apertura fallida de `animcurv`/`voxmap` → cabecera sin magia → `objLoadAnimdata` aborta → `[SeqState+0x94]` nulo → `Rebuild` sin bucle → sin cmd 3 → sin `Toggle`-on → sin enlace → sin drenaje → 84 reinicios → fuga → muerte en `sceneDraw`. Con el fallback, cada eslabón hasta `Toggle`-on/`SeqFn` se mueve y la muerte desaparece en la ventana observada. `visible < 616` no se midió directamente (solo evidencia indirecta: supera el despacho de muerte y llega viva a 60M). Reconciliación honesta: A prueba el fallo aguas arriba (entrada de tabla 0 → cabecera constante sin magia); B prueba empíricamente que resolver los 12 ficheros desbloquea el cargador en 14/20 casos y toda la cadena hasta `Toggle`-on — **el fallback es NECESARIO pero, en 60M despachos, todavía NO suficiente para el criterio completo. No es "el parche del bit 117".**
- **Integración en esta rama (un solo cambio de comportamiento, conservador):** el port ya tenía el mismo hueco: `Hle::DvdOpen` en `app/src/main/cpp/gamecube_runtime/hle.cpp` solo hacía fallback sin distinción de mayúsculas para nombres planos (sin `/`), escaneando el directorio raíz (Fase 5: `PREANIM.BIN/PREANIM.TAB`). El fallback por componentes de vía B se inserta tras ese bloque, antes del error "no encontrado", adaptado a nombres/variables/estilo del port y con su log (`SFA_LOGI`, "resuelto sin distinguir mayusculas por componentes como"). Solo se aplica cuando la apertura exacta ya falló: no cambia ninguna ruta que antes resolvía. Diff aplicado en `work-port/tramo18-bit117/integracion/hle-fallback-port.diff`. Build NDK manual (sin Gradle: el daemon da el fallo conocido; y CMake aborta porque calcula `SFA_GENERATED_DIR` como `cpp/../../../codigo` = `app/codigo`, inexistente — la compilación manual con el clang del NDK r28c reproduce la lista de fuentes del CMakeLists con la ruta real `codigo/generated`; documentado en `work-port/tramo18-bit117/integracion/build-ndk-manual.sh`).
- **APK GX28 de prueba:** código `f99b1e4`; APK `android-port-base/app-debug-gx28-test.apk` (12.776.102 B, SHA-256 `cb6d1e0f6ea9c90ae37c9b6728ad619f73a41878c994cdcda4b7f1a1071fd28b`, SHA-1 `b82eb2595cf7d12cdd5f929356d6209b6d16a4e6`, v19 / `0.19.0-gx28-test`, apksigner v2+v3, zipalign OK, solo permiso VIBRATE, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable, sin datos dentro, lib interior SHA-256 `256c8fc24b42823fa5803a9d8c7444053853c01936764c6d2c68fec0c3b85241`; certificado SHA-256 `9a4cb89b264158baea1258d5d5c53c5ecffbbbfbeb347f55c2aae8d5c975c680`, distinto del de GX27 → desinstalar GX27 antes de instalar GX28). Guía: `GUIA-PRUEBA-GX28.md`. **GX28 es de PRUEBA, NO jugable:** sin juego real en Tab S8, sin menú legible, sin mundo estable, sin rumble positivo, sin surround activable; inerte sin `sfa-data/`. La evidencia de comportamiento es la de vía B en harness, no una prueba del port nuevo más allá de compilación y validación estructural. El bloqueo bit 117 sigue: si tras confirmar en slots se cierra o se queda parada, reportarlo con `boot.log`.
- **Pack C-mapa sigue 142 / 82.413.172 B CANDIDATO PARCIAL (no revalidado como mundo):** el pack de la carrera con fallback no es comparable byte a byte con Pack C-mapa (trayectoria distinta: 165 intentos frente a 1127, sin 84 reinicios); Pack C-mapa sigue siendo el candidato parcial de la trayectoria base. Cuestión 1367 sigue abierta (acotada, no resuelta).
- **Siguiente tramo (v6):** (1) instrumentar `getTableFileEntry` por dentro (chunk_0016: base de tabla para el argumento 14, índice y palabra leída, si la base apunta a RAM cargada o a ceros); (2) investigar las 6/20 cargas restantes que fallan ambas magias; (3) el eslabón aguas abajo entre `SeqFn` (`lr=0x80085190` observado) y `mainSetBits(117,1)` con `lr=0x801DFD9C` (ventana más larga y/o siguiente eslabón); solo después, revalidar Pack C-mundo. Trabajo en `work-port/tramo18-bit117/viaA/`, `work-port/tramo18-bit117/viaB/` e `work-port/tramo18-bit117/integracion/`.
## Tramo 19 (2026-10-27, este tramo): bit 117 v6 — tabla 14 por dentro, las 6/20 y el eslabón SeqFn→bit 117: CRITERIO CUMPLIDO EN VENTANA LARGA, SIN mundo todavía — SIN APK nueva (GX28 sigue vigente)

- **Paso 1, DECIDIDO: la tabla 14 no está cargada en host (no es índice fuera de rango ni base nula).** Instrumentación en copia de observación del chunk_0016 (`getTableFileEntry` por dentro: base, cuenta, índice, palabra leída, muestreo de la tabla). Carrera sin fallback (reproducción exacta: 49.571.763 despachos, `unknown_pc 0x80000100`): `tab14_loader=850, lwzx=850, word_zero=850, word_nonzero=0, fail_early=0, fail_base0=0, base_changes=0`; muestras: `base=0x80347A30` siempre, `cnt=8144` siempre, `word=0` siempre, `nz256=0`. La tabla está bien direccionada pero toda a cero. Con fallback (60M): misma base y cuenta, `nz256=254`, `wlast=0xFFFFFFFF`, palabras reales (idx 1 → 0; 0x1687 → `0x800071A0`; 0x1DA–0x1E3 → `0x20000138…0x20002780`).
- **Origen exacto del patrón `00 00 00 00 FF 00 FF C4` (cerrado por estática + vivo):** la tabla 14 en RAM ES `ANIMCURV.tab` (16 primeras palabras idénticas a disco; centinela final `0xFFFFFFFF`). Sin fallback, el `ANIMCURV.tab` del área no se abre por caso → tabla a cero → `getTableFileEntry` devuelve éxito 1 pero escribe 0 → `loadAndDecompressDataFile` tipo 13 con entrada 0 ve la base del blob del subtipo 13 a NULL (global `0x80360D7C` = 0 en base, `0x80F73940` en fb) → vía fallback en `0x80048308` (corrección: NO `0x80048260`, que es solo para subtipos 32/75) → tabla de ficheros en `0x802CCB04`, índice `r4=52` (`r26=13`) → **`ANIMCURV.bin`**, offset 0 → su registro 0, que en disco ES `00000000 FF00FFC4` repetido. En vivo: `T13B fb2=850`, muestras `entry=0, tabbase=0x802CCB04, r4=52, fileptr→'ANIMCURV.bin'`, `bufhdr=00000000 FF00FFC4`. El patrón no es corrupción ni buffer a cero: es el registro 0 real de `ANIMCURV.bin`.
- **Paso 2, las 6/20: EXPLICADAS, no son un segundo hueco.** En fb, las 6 cargas que fallan ambas magias son exactamente las 6 de `tabidx=1` (`id=0` en las 6, `entry=0`, `hdr=00000000 FF00FFC4`); las otras 14 no llegan a la línea de log porque con `SEQA==0` el cargador salta sin pasar por el `strncmp` SEQB. Y `ANIMCURV.tab[1] = 0` en disco: la entrada 0 es legítima, no otro fallo de resolución (`DVDOpen no encontrado = 0` con fallback). No requieren parche.
- **Paso 3, SeqFn→bit 117: RESUELTO por ventana larga.** Anatomía: `FEseqobject_SeqFn` (`0x801DFCEC`) itera `byte [r29+139]` (cuenta) y `byte [r29+129+r30]` (código); código 1 → `mainSetBits(117,1)` con retorno `0x801DFD9C`. En 60M la lista está VACÍA en las 235 llamadas (`iter=0, cntpos=0, SEQCNT 0:235`): no es que corra otro código, es que el bucle no corre. En 150M (`dispatch_cap`, viva, `pc_final=0x8003EB34`): `SEQ total=730, iter=1, code1=1, cntpos=1`; **`SEQCODE iter=1 call=682 ix=0 code=1`** y **`MSB117 n=1 bit=117 val=1 lr=0x801DFD9C`** (una sola vez en toda la carrera); `SAMPLEBIT bit117=1` desde 92M hasta 150M (acotado entre 91M y 92M). Criterio completo cumplido: `mainSetBits(117,1) ≥ 1` con el `lr` exacto + `bit117=1`. Colateral: SFX 174→2266, `sndSeq` 3→4, `LOADED` 95→207, `Override` estable en 7 (60M y 150M), `toggle` 18→19 (`off=1` nuevo). Caveat: la captura FIFO saturó en 150M (tope 512 MiB, `fifo_over=173288259`); contadores y logs no dependen de ella. No hay parche que diseñar para el bit 117: con el fallback de Tramo 18 el mecanismo ya funciona; forzar el bit habría sido maquillaje.
- **Pero SIN mundo todavía, y A no es la llave.** A 150M: `chapter=0, launch=1, curUiDll=1`. Experimento con 59 pulsos A extra tras el lanzamiento (lecturas 1100–4000, 220 tramos frente a 102): trayectoria idéntica (solo 3 líneas distintas en `stdout.log`, rutas; `stderr.log` byte a byte idéntico; mismos contadores y mismo pack). El juego NO espera un A en esa pantalla. Pack long19/input19: 140 / 82.298.464 B (frente a Pack C-mapa 142 / 82.413.172 B): sigue CANDIDATO PARCIAL, prohibido presentarlo como pack del mundo.
- **Sin APK nueva:** con cero cambios en el código del port, una GX29 sería GX28 con otro número — ruido, no avance. La APK de prueba vigente sigue siendo **GX28** (12.776.102 B, SHA-256 `cb6d1e0f6ea9c90ae37c9b6728ad619f73a41878c994cdcda4b7f1a1071fd28b`, v19 / `0.19.0-gx28-test`; guía GUIA-PRUEBA-GX28.md). Este commit es solo documentación del Tramo 19. Cuestión 1367 sigue abierta (acotada, no resuelta).
- **Siguiente tramo (v7):** (1) por qué no hay mundo con bit117=1 (ventana aún más larga; input distinto de A, p. ej. stick/D-pad para elegir destino; segundo gate aguas abajo; qué renderiza realmente a 150M); (2) solo con mundo estable, re-medir Pack C; (3) plomería/UI surround (getter Java + `ApplySurroundPreference` tras `TryLoadData()` + interruptor; el gate C++ ya existe, OFF por defecto) + prueba en Tab S8; (4) certeza HW tap7. APK jugable solo con juego real verificado. Trabajo en `work-port/tramo19-bit117-v6/` (INFORME-T19.md, `patch_t19.py`, `patch_t19b.py`, `patched/`, carreras base19/base19b/base19c, fb19, long19, input19).
## Tramo 20 (2026-10-27, este tramo): v7 — el A del Tramo 19 nunca se entregó; navegación SÍ mueve el mundo; no hay segundo gate; plomería surround con interruptor — APK GX29 de prueba (NO jugable)
- **CORRECCIÓN al Tramo 19 (leer primero): la conclusión "el juego NO espera un A" es INVÁLIDA y queda retirada.** Mecanismo: `Hle::SetPadScript` (`hle.h:511`) hace `clear()` — sustituye el guion entero. El disparo por estado (`cur==5 && prev==6`) disparó en `padread=840` y sustituyó el guion por soltar/A 860–866/soltar para siempre; los 59 pulsos A extra de input19 iban en lecturas 1100–4000, todas posteriores, y **nunca existieron en el guion efectivo**. Que input19 ≡ long19 no prueba nada sobre el A: prueba que el guion fue sustituido. Todo experimento post-disparo debe instalar su programa en el propio disparo (así lo hace el binario Tramo 20, con auditoría `T20: PADIN` por lectura).
- **Control ctrl20 (150M, solo lanzamiento): reproducción exacta de long19 con el binario nuevo.** Mismos contadores (`dispatch_cap`, ticks 1500, `pc_final=0x8003EB34`, PADRead 2234, retrace 2960, `curUiDll=1`, `dvdopen=165`, `texloads=504359`, `fifo_over=173288259`, `sndFX=2266`, `sndSeq=4`), mismo FINAL (`cur=1 prev=5 chapter=0 launch=1 loadDelay=254`), mismo pack 140 / 82.298.464 B; stdout 0 líneas de diferencia (sin líneas `T20:`), stderr byte a byte idéntico, `ram.bin` 2 bytes distintos (`0x803DEA06–07`, el contador ya visto en v1/v1b). El binario queda validado antes de atribuir cambios.
- **(a) Ventana larga long20 (300M, solo lanzamiento): el tiempo solo NO es la llave.** `dispatch_cap`, ticks 3000, `pc_final=0x8025C574`, retrace 6395, `curUiDll=1`, `dvdopen=165`, `texloads=1.032.797`, `sndFX=7155`, `sndSeq=4`, FINAL idéntico (`cur=1 chapter=0 launch=1 loadDelay=254`), `SEQ 730/1/1` idéntico, `bit117=1`, pack 140 / 82.298.464 B. 150M más de juego vivo no mueven ningún campo UI.
- **(d) Qué renderiza: una escena 3D viva.** Clasificación de `T10: SAMPLE` contra `generated_symbols.h`: 41M–150M dominan render (`renderOpMatrix`, `modelDoRenderInstrs`, `addShaderLayerStages` incl. `pc_final`, `Camera_GetViewMatrix/RebuildProjectionMatrix`, `skyGetSunColor`, `renderGlows`, `objRenderChild/Shadow`, `lightningDrawBolt/Strand`, `modgfx_renderEffects`, `textRenderChar/Setup` HUD); 150M–300M añaden `ObjHits_CheckHitVolumes` (colisiones) y `modgfx_updateActiveEffects`. `UIController_render` (`0x800DA138`): `gameTimerIsRunning` → `gameTimerRun` + `hudNumberRender` + render por vtable+12; `frameStart` (`0x800DA1E8`) es un trampolín. `loadMapForCurrentSaveGame` (`0x800EA020`, desensamblado completo): `unlockLevel(0,0,1)`, `memset`, `cutsceneExit`, `audioStopByMask(7)`, `stopRumble2`, `resetYbutton`, lee la entrada de partida (`[0x803A4C08+0x20]<<4`, posición +0x684/688/68c), `mapLoadByCoords`, `getCurUiDll()==4 → loadUiDll(1)`, `screenTransition_holdThenFadeIn(30,1)`. **La cadena de carga del mapa ya corrió.** `loadDelay=254` está en todas las fases desde el título (centinela inerte, no cuenta atrás). `osreport` long19: 0 errores `mm`. Punto de aparición slot 0: `(570.648, -82.000, 15790.820)`; el nombre del área no se derivó (hueco honesto, no se afirma ninguno).
- **(b) Navegación nav20 (150M, programa post-disparo de 29 pasos): el input SÍ mueve el mundo.** Programa anclado a `trig_pad=840`: A de lanzamiento 860–866 (idéntico al control) y desde +300: stick arriba 200 lecturas, D-pad abajo, A, D-pad abajo, A, stick abajo 200, A, D-pad arriba, A, Start, B, stick derecha 200, A (fin +1646, dentro de las ~2926 lecturas). Entrega probada: `T20: PADIN` **760 lecturas no nulas** (control: 100) con cada valor en lecturas concretas, y el propio Held del juego muestra D-pad abajo (`0x00000004`, 79M) y A (`0x00000100`, 87M/104M). Efecto: `ram.bin` **271.077 bytes distintos** (control: 2), **2 aperturas DVD nuevas** (`gametext/Communicator/English.bin` 34.912 B y `gametext/ShipBattle/English.bin` 28.980 B, textos de juego, no de menú), `sndSeq` 4→**5**, `arq` 4→5, `sndFX` 2266→2128, `texloads` 504489, `playerGetMaxMagic` y `objUpdateHitSpheres` en el bucle 100M–150M. FINAL UI sin cambio (`cur=1 chapter=0 launch=1`): la navegación no cambia la máquina UI, pero ese ya no es el criterio (ver siguiente punto). `SEQ 730/1/1`, `msb117_1=1`, `bit117=1` al final. Pack nav20: **141 / 82.333.376 B**.
- **(c) Segundo gate: NO HAY (reframing).** `chapter=0` es el campo de capítulo de la partida nueva (slot 0, aparición constante); `loadMapForCurrentSaveGame` no lee ningún capítulo para entrar al mundo, lee posición; ningún código condiciona la entrada a `chapter>0`. **Queda retirado `chapter>0` como discriminador de mundo** hasta que una sesión verificada lo redefina. Lo que falta para el 100% jugable ya no es una puerta en host: (1) frame visible + audio + input en Tab S8 (GX29 es el vehículo); (2) en su caso, volcado de frame en host (EFB→PNG) para nombrar la escena — no hecho aquí. Pack C-mapa (142 / 82.413.172 B) sigue CANDIDATO PARCIAL y el pack nav20 (141 / 82.333.376 B) **tampoco** se presenta como pack del mundo: la medición definitiva exige una trayectoria de juego verificada (las tres mediciones dependen de la trayectoria: base 142, control 140, nav 141).
- **Plomería surround vía B + interruptor (Tramo 16, por fin con llamador).** Nuevo `input/surround_button.h` (rectángulo x 0.31–0.43, y 0.92–0.98, izquierda de la píldora de audio con hueco 0.01; el candidato 0.30–0.42 fallaba el listón Tramo 6 por 0.0018 frente a D-pad abajo; en 0.31–0.43 el margen mínimo es 0.0432 en 1.6 y 0.0499 en 16:9; colores OFF gris pizarra / ON cian, sin colisión con audio; sin etiqueta bitmap todavía, pendiente del overlay de ajustes). `input.h/.cpp` (interceptación tras audio y antes de TouchLayout), `renderer.h/.cpp` (`DrawSurroundButton`, misma NDC que audio), `runtime.cpp` (dibujo cada frame, también sin juego), `native-lib.cpp` (`GetSurroundPreference` JNI `getSurroundEnabled()Z` con false ante fallo, `SetSurroundPreference` JNI `setSurroundEnabled(Z)V`, `ApplySurroundPreference` tras `TryLoadData()` en INIT_WINDOW y en el camino SAF-done, drenaje del disparo cada vuelta: sin ventana/foco se descarta; si no, persiste primero y solo entonces aplica; si la escritura Java falla, se conserva el estado viejo), `MainActivity.java` (`get/setSurroundEnabled` sobre `SharedPreferences sfa_settings` / `audio_surround_enabled`, defecto false). **No sigue a `SaveData.soundMode`** (Fase B del Tramo 14, opcional, NO hecha): es un ajuste del port. Con OFF (defecto), el PCM es bit-idéntico al de GX28; con ON, espejo `interp(2−span)` en note-on y S descartado (Tramo 15/16).
- **Verificación surround:** test host `work-port/tramo20-surround/tests-host/test_tramo20_surround.cpp` **45/45, 0 fallos** (rectángulo, disjunción táctil y NDC con audio, márgenes, doble guarda TouchLayout-solo, disparo/cancel/multitáctil, Reset, colores, regresión A/stick/C-stick). Build NDK (r28c, API 26): `libstarfox.so` 28.096.632 B, SHA-256 `983c3826ed5f1560fcd802dbffffd0c381407a3773bcffce6fde6cd57592d740`, ELF64 AArch64, `android_main` y `func_80003100` en T, `Renderer::DrawSurroundButton` en T, `ApplySurroundPreference` presente, cadenas de log surround presentes, 0 símbolos `mem_/ppc_/func_/dolrecomp_` sin resolver, 228 indefinidos solo de sistema (`GekkoCpu::Step/Reset` eran indefinidos en GX28 y en GX29 están definidos en T). Nota de entorno: el JDK de /usr desapareció en un reemplazo de VM; el build de APK usó el Temurin persistente `~/tools/jdk-21.0.13+9` (javac 21.0.13).
- **APK GX29 de prueba:** código de este tramo; APK `android-port-base/app-debug-gx29-test.apk` (12.776.102 B, SHA-256 `d2ecc2f2aebce6c48ff8914e39a1ed34365e2e9cb91f4190dcc3485a6f666f80`, SHA-1 `da4368fb3da6399d5c35ae9842a4a9fe9d15677a`, v20 / `0.20.0-gx29-test`, apksigner v2+v3, zipalign OK, solo permiso VIBRATE, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable, sin datos dentro, lib interior SHA-256 `983c3826…` idéntica al build NDK; certificado SHA-256 `6c88665f5e36b032d42921182027ae412df66587812d64624f34b0fb9bd55216`, distinto del de GX28 → desinstalar GX28 antes de instalar GX29; guía GUIA-PRUEBA-GX29.md). Etiqueta: PRUEBA — con interruptor surround activable en código y verificado en host/NDK, pero sin juego real verificado en Tab S8, sin píldora pulsada en dispositivo, sin persistencia ni sonido ON verificados en dispositivo; nunca jugable al 100%.
- **No hecho en este tramo (declarado, no simulado):** certeza HW tap7 (solo GC real la cerraría); prueba GX28/GX29 en Tab S8 (sin enlace ADB operativo ni navegador en vivo en este subagente; peticiones expresas en GUIA-PRUEBA-GX29.md: líneas `native: surround:`, líneas del fallback, líneas `DVDOpen` de Communicator/ShipBattle, navegación post-lanzamiento); Fase B `soundMode`; etiqueta de texto en la píldora surround; APK jugable (exige juego real verificado en Tab S8: input + audio + frame). Trabajo en `work-port/tramo20-v7/` (INFORME-T20.md, carreras ctrl20/long20/nav20, `clasificar_pc.py`, `des_dol.py`, `ramdiff.py`) y `work-port/tramo20-surround/` (test host 45/45), build NDK en `work-port/tramo20-ndk-build/`, APK en `work-port/tramo20-apk/`. Cuestión 1367 sigue abierta (acotada, no resuelta).
## Tramo 21 (2026-10-27, este tramo): la escena tiene nombre ("Ship Battle") + etiqueta en la píldora surround — APK GX30 de prueba (NO jugable)
- **La escena que renderiza el host ya tiene nombre: MAPINFO[0] = "Ship Battle".** Cadena completa y reproducible (`work-port/tramo21-mapa/mapa_shipbattle.py`, sin carrera nueva, sobre las `ram.bin` del Tramo 20): partida slot 0 en (570.648, −82.000, 15790.820); `mapSetup` divide x,z por **640.0** (constante del DOL en r2−0x7944 con r2 = 0x803E7EC0, que pone el propio stub de entry del juego 0x80003280–88 — el preset del harness 0x803E4B40 habría dado 0.3 y una rejilla absurda, pero el entry lo sobrescribe antes de cualquier código de mapa); rejilla (0,24) en el rectángulo 1 de la entrada 0 (−6..5, 18..24) con el bit 78 puesto → `mapCoordsToId = 0`; `mapSetup` copia el registro MAPINFO 0 en el búfer de mapa actual (0x815BE960), que en ctrl20/long20/nav20 es byte a byte MAPINFO[0] = "Ship Battle" (byte28 = 0, short30 = 0), con `mapId_out` = 0 y `maptype` = 0 en las tres carreras. Corroboraciones: ctrl20 ya abre `gametext/ShipBattle/English.bin` antes de navegar; `shipbattle/*` 18 aperturas idénticas en las tres carreras; `warlock/*` 21 en las tres (carga del mismo mundo, no cambio de mapa); nav20 termina con el mismo id 0 tras 150M con input. **No se afirma** que la pantalla muestre el rótulo "Ship Battle" (es el nombre en datos) ni la apariencia de la escena (eso lo dirá la sesión GX30). **Límite honesto:** en host NO hay GPU ni EFB y el `fifo.bin` saturó (512 MiB, 173M de overflow), así que no hay PNG del frame en host: la identificación es por el registro del propio juego, más fuerte que una imagen para decidir si el host está en mundo jugable (sí, y con nombre). Cámara y HUD vigentes del Tramo 20 (`Camera_GetViewMatrix/RebuildProjectionMatrix`, `gameTimer` + `hudNumberRender` + `textRenderChar/Setup`); la matriz de cámara del frame final no se volcó (hueco declarado).
- **Etiqueta de texto en la píldora surround (pendiente del Tramo 20, hecha).** Nuevo `input/surround_label.h` (patrón Tramo 7, sin duplicar la fuente: reutiliza la 5x7, el layout y el quad de `audio_label.h`): OFF → "SURROUND OFF" (12 glifos, blanco sobre gris pizarra), ON → "SURROUND ON" (11 glifos, oscuro sobre cian); textura opaca; si ni escala 1 cabe, píldora sin etiqueta (nunca recortada). `renderer.cpp` (`DrawSurroundButton`): mismo bloque de etiqueta que `DrawAudioButton`, solo pintura — el táctil NO cambia (mismo rectángulo, mismos márgenes 0,0432/0,0499). Test host `work-port/tramo21-surround/tests-host/test_tramo21_surround_label.cpp` **47/47, 0 fallos** (Tab S8 307×96 px: escala 4, tex 284×28 OFF / 260×28 ON, contrastes WCAG 6,17:1 / 7,45:1; 16:9 escala 3; quad dentro y sin distorsión; opacidad; fondo = color de la píldora; píldora 20×10 y 0×0 sin etiqueta; regresión audio y rectángulo intactos; el test tuvo dos errores propios corregidos antes del verde: 12 glifos, no 13, y `AudioLabelPillPx` toma extensión NDC, no fracción). Regresión Tramo 20: **45/45**. **Fase B `soundMode`: NO hecha** (opcional; cambiaría la semántica del ajuste del port y exige decisión en dispositivo).
- **Verificación:** build NDK incremental desde los objetos del Tramo 20 (el build desde cero se abandonó a los 47 objetos por lento; solo `renderer.cpp` cambió): `libstarfox.so` 28.098.544 B (GX29: 28.096.632), SHA-256 `e2e6e346377ce59b0dbb283d2ac27dcc6fca05fc3d42cb346f4fcacfa9f2f361`, ELF64 AArch64, `android_main` y `func_80003100` en T, `DrawSurroundButton` en T, `RasterizeSurroundLabel` presente, 0 símbolos `mem_/ppc_/func_/dolrecomp_` sin resolver, 228 indefinidos solo de sistema (igual que GX29).
- **APK GX30 de prueba:** código de este tramo; APK `android-port-base/app-debug-gx30-test.apk` (12.780.198 B, SHA-256 `90591b0c3da0238630f227b2197c8d71eddae4d508b2870c3a897c62c36e0303`, SHA-1 `5865b307f5356758ca5b7e1b73c947476c28dbdc`, v21 / `0.21.0-gx30-test`, apksigner v2+v3, zipalign OK, solo permiso VIBRATE, minSdk 26 / targetSdk 34 / arm64-v8a / debuggable, sin datos dentro, lib interior idéntica al build NDK; certificado SHA-256 `6c88665f5e36b032d42921182027ae412df66587812d64624f34b0fb9bd55216`, **idéntico al de GX29 → GX30 actualiza sobre GX29 sin desinstalar** (versionCode 21 > 20; desde GX28 o anterior, desinstalar primero); guía GUIA-PRUEBA-GX30.md). Etiqueta: PRUEBA — con etiqueta verificada en host/NDK, pero sin juego real verificado en Tab S8, sin etiqueta leída en dispositivo, sin persistencia con texto, sin sonido ON, sin navegación ni frame Ship Battle verificados en dispositivo; nunca jugable al 100%.
- **No hecho en este tramo (declarado, no simulado):** sesión GX29/GX30 en Tab S8 (sin reporte del usuario en este tramo: queda pendiente con guía actualizada a GX30); Pack C-mundo (exige trayectoria verificada: Pack C-mapa 142 / 82.413.172 B sigue CANDIDATO PARCIAL y el pack nav20 141 / 82.333.376 B TAMPOCO es pack del mundo); certeza HW tap7; Fase B `soundMode`; APK jugable (exige juego real verificado en Tab S8: input + audio + frame). Trabajo en `work-port/tramo21-mapa/` (INFORME-T21.md, `mapa_shipbattle.py`) y `work-port/tramo21-surround/` (test host 47/47), build NDK en `work-port/tramo21-ndk-build/`, APK en `work-port/tramo21-apk/`. Cuestión 1367 sigue abierta (acotada, no resuelta).

## Tramo 22 (2026-10-27, este tramo): Pack C-mundo medido en la trayectoria host verificada (criterio mapa actual) — SIN APK nueva, GX30 sigue vigente
- **Pack C-mundo = trayectoria nav20 del Tramo 20, re-medida con el resolvedor correcto: 153 ficheros / 82.729.888 B.** El criterio que faltaba lo puso el Tramo 21 (el mapa actual del juego, no `chapter>0`): nav20 termina con el búfer de mapa actual = MAPINFO[0] = "Ship Battle" (re-verificado aquí con `mapa_shipbattle.py` del Tramo 21: veredicto idéntico en ctrl20/long20/nav20), viva al final (150.000.000 despachos, `pc_final = 0x80286A48`, `curUiDll = 1`, `launch = 1`, `bit117 = 1`, `chapter = 0`, 0 excepciones, `sndSeq = 5`, 167 intentos DVDOpen, 0 aperturas fallidas). **Bug del medidor viejo, corregido:** `medir_pack.py` (Tramo 7D/20) solo toleraba caso en nombres planos de raíz y excluía 12 ficheros en subdirectorios — los `animcurv`/`voxmap` de `gamefront/`, `shipbattle/` y `warlock/`, exactamente los 12 que fallaban en la carrera mapa vieja; el medidor nuevo (`work-port/tramo22-pack/medir_pack22.py`) resuelve por componentes con `strcasecmp` como el port desde GX28 (0 casos `logsize` en las 5 carreras). Resultados: nav20 153 / 82.729.888 (antes 141 / 82.333.376); ctrl20 = long20 = long19 como conjuntos, 152 / 82.694.976; nav20 = base 152 + `gametext/Communicator/English.bin` (34.912 B, lo único que añade la navegación). El viejo Pack C-mapa 142 / 82.413.172 B queda como medición histórica pre-fallback (re-medición idéntica, 12 fallidos); el viejo nav20 141 queda sustituido por el corregido 153. Unión nav20 ∪ mapa142 como referencia: 155 / 82.844.596 B; los 2 propios del mapa viejo (`ANIMCURV.bin` de raíz, 111.968 B; `gametext/Sequences/20105_English.bin`, 2.740 B) quedan como candidatos documentados, no sumados: la definición es una sola trayectoria reproducible.
- **Alcance honesto:** Pack C-mundo NO es lista mínima ni pack instalable solo (`verifyAndMark` exige ≥2.916 ficheros; el pack instalable vigente sigue siendo base SAF + Tier 1, 3.968 / 382.982.980 B) y NO está verificado en dispositivo: si la sesión GX30 muestra otro mundo o abre ficheros fuera de los 153, se revisa. Por eso no hay APK jugable en este tramo.
- **No hecho en este tramo (declarado, no simulado):** sesión GX30 en Tab S8 (sin reporte del usuario en este tramo: queda pendiente con la guía GX30 vigente; GX30 re-verificada intacta en la rama, SHA-256 `90591b0c3da0238630f227b2197c8d71eddae4d508b2870c3a897c62c36e0303`, 12.780.198 B, v21 / `0.21.0-gx30-test`); certeza HW tap7 (solo consola GC real la cerraría; la confirmación del filtro en log FIFO Dolphin también sigue pendiente como paso intermedio no-HW, no intentado aquí); Fase B `soundMode` (opcional; exige decisión en dispositivo, no impuesta); APK jugable (exige juego real verificado en Tab S8: input + audio + frame). **Sin cambios de código en este tramo: no se entrega APK nueva con otro número** (como en los Tramos 13, 14, 15, 17 y 19); la APK vigente sigue siendo GX30. Trabajo en `work-port/tramo22-pack/` (INFORME-T22.md, `medir_pack22.py`, CSVs). Cuestión 1367 sigue abierta (acotada, no resuelta).
