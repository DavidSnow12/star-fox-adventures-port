# Estado del port Android — rama `android-port-base`

**Fecha de este estado: 2026-10-25. Uso personal, repo privado, NO distribución.**

## Resumen honesto

**La app NO es jugable todavía.** Lo que hay es una base compilable
más el runtime base verificado en host (cargador DOL, memoria guest,
dispatch y SMC). No hay APK jugable en el repo. Cuando la haya, se
anunciará aquí con su commit, tamaño y SHA, y solo entonces merece
la pena descargarla para probar el juego.

## Qué funciona (verificado)

- Base Android: NativeActivity, `android_main`, loop, ciclo de vida
  (ventana/foco/destrucción), log con `boot.log`.
- C++ nativo para arm64-v8a con NDK r28c: enlaza como `libstarfox.so`
  (AArch64, `android_main` exportado). Revalidado en este tramo con
  los ficheros nuevos (12 C++ + glue).
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

1. **Chunks DolRecomp no enlazados:** los 176 chunks usan un
   `CPUState` global en C (`cpu/cpu.h` de `generated.h`) y funciones
   `mem_*`/`ppc_host_call` globales. El shim global con el layout
   exacto de `cpu_state.h` y el enlace de los chunks en CMake es el
   siguiente paso; hasta entonces la CPU es un stub y no se ejecuta
   código del juego.
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

## Descarga e instalación (CUANDO haya APK jugable)

Todavía no aplica. No descargues la base como si fuera el juego:
abrirá una pantalla de color fijo y se quedará ahí, porque no hay
código del juego ejecutándose.

Cuando se publique una APK de prueba, aquí aparecerá:
- Rama y commit exactos, nombre del fichero, tamaño y SHA-256.
- Dónde descargarla (repo, rama `android-port-base`, o release).
- Pasos: instalar APK, conceder permisos, copiar el paquete de
  datos a la carpeta indicada, abrir la app.

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

## Orden que queda

1. Shim global `cpu/cpu.h` + enlace de chunks + `ppc_host_call`.
2. HLE mínimo de arranque (OS/GX/VI/DVD/SI) para que __start avance.
3. GX real (primer frame) y luego DSP/MusyX e input.
4. Paquete de datos + build APK + validación + test en Tab S8.
