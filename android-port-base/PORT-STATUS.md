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
solo de sistema), `libstarfox.so` 27.865.152 B, SHA-256
`04137fe3168dcc7ed6df7eb6cba904f6a202c7c182ff7f80ec90d47c4070683c`,
ELF64 AArch64, `android_main` y `func_80003100` en T,
`OnFxStartDoubled` y `OnSeqPlay` en T. APK GX20: ver
sección siguiente (se añade tras el build en este mismo
tramo).
