# Guía de prueba en Tab S8 — Botón «añadir audio», Tier 1 y caché PCM (Tramo 6)

**LEE ESTO PRIMERO — qué es prueba real y qué no.**
Esta guía la ejecuta **el usuario en su Tab S8**; nada de lo que sigue
se ha probado en hardware en este tramo (sin enlace ADB en la tarea
y sin APK construida aquí: este tramo entrega código + tests host,
no una APK). La APK que salga de aplicar este parche será, como
GX19, una **APK de prueba NO jugable** hasta que el port lo sea:
la parte A (botón + importación) sí se puede verificar entera con
esa build; la parte B (sonido Tier 1 en juego + caché) solo se
verificará cuando el juego llegue a ThornTail Hollow (TTH) o a un
stream TTH. **No des por buena la parte B si solo pasó la parte A.**
Si algo falla, reporta exactamente lo de la sección «Qué reportar».

## 0. Qué necesitas antes de empezar

- La APK con este tramo aplicado (rama `android-port-base`, parche
  `diffs/tramo6.patch` aplicado sobre `033610d`, build Gradle).
  Comprueba que es la build nueva: al arrancar debe verse la
  **píldora en el centro inferior** (ver §1). Si no se ve, NO
  sigas: es la APK vieja.
- Los datos base ya importados por SAF (Pack B: `sys/main.dol` +
  `files/`, ≥2.916 ficheros, marcador `.saf-copy-done`). Sin datos
  base, el audio solo no suena y el botón lo avisará en boot.log
  («audio importado pero sin sys/main.dol»).
- El paquete de audio Tier 1 preparado en el PC o en la tablet,
  en una carpeta que contenga **una carpeta `audio/`** con esta
  estructura exacta (el picker acepta elegir `audio/` en sí o su
  padre si contiene `audio/`; nunca elijas la carpeta de datos
  base: el flujo de audio NO toca `sys/` ni `files/`):
  ```
  audio/
    musyx/…          (816 WAV MusyX de Tier 0)
    streams/TTH/…    (231 ADP de TTH)
  ```
  Cifras del paquete de audio (solo overlay, sin base):
  **1.047 ficheros, 139.673.324 B ≈ 133,20 MiB**
  (816 WAV = 26.590.956 B + 231 ADP TTH = 113.082.368 B).
  Ojo con la cifra 365,24 MiB que verás en otros documentos:
  esa es la **huella total en dispositivo con la base incluida**
  (base 232,04 MiB + overlay 133,20 MiB), NO lo que transfieres
  con «añadir audio». Si transfieres 365 MiB por el picker de
  audio, has elegido la carpeta equivocada.
- Cómo leer `boot.log` (APK debuggable): con el puente ADB/PC o
  `run-as com.starfox.port cat files/boot.log` desde la tablet
  con adb. **Importante:** cada arranque de la app TRUNCA
  boot.log (se abre en escritura al inicio): extrae el log de
  una sesión ANTES de volver a abrir la app, o perderás la
  evidencia de esa sesión. Las líneas que importan empiezan por
  `audio-btn:`, `saf:` y `bridge:`.

## 1. Dónde está el botón y cómo se reconoce (sin etiqueta de texto)

Limitación honesta del Tramo 6: la píldora **no lleva texto**
(GL sin fuente; la etiqueta real queda para el futuro overlay de
ajustes). Se reconoce por **posición + color**:

- **Posición:** centro inferior de la pantalla, pegada al borde
  inferior. En la Tab S8 (2560×1600) mide **307×96 px**,
  centrada horizontalmente, a 32 px del borde inferior
  (fracciones x 0,44–0,56, y 0,92–0,98). Queda **debajo** del
  damero de prueba y **no solapa** ningún control: stick
  (izquierda abajo), rombo A/B/X/Y (derecha abajo), C-stick
  reservado (centro-derecha), L/R y Start (arriba).
- **Color = estado** (mira la píldora, no el juego):
  - **Ámbar fijo = sin audio.** Estado inicial si nunca se
    importó audio.
  - **Ámbar parpadeante = verificando.** Acabas de pulsar y la
    copia/verificación está en curso. No pulses de nuevo: los
    toques durante este estado se ignoran a propósito.
  - **Verde = audio listo.** Importación verificada
    (`.saf-audio-done`).
  - **Rojo = error.** La copia falló (`.saf-audio-error`) o el
    picker no se pudo abrir. Mira boot.log para la causa.

## 2. Prueba A — Botón + importación Tier 1 (verificable YA)

### A1. Estado inicial
1. Abre la app con los datos base ya importados pero SIN audio.
2. **Esperado:** píldora **ámbar fija** visible en el centro
   inferior, y en boot.log una línea
   `native: audio-btn: estado sin audio`.
3. Toca el stick virtual y pulsa A: **el juego debe responder
   igual que antes** (el botón no roba juego). Toca fuera de la
   píldora (por ejemplo, el centro de la pantalla): **no debe
   abrirse ningún picker**.

### A2. Importar Tier 1 con el botón
1. Pulsa la píldora (toque corto, soltar DENTRO de la píldora).
   **Esperado inmediato:** la píldora pasa a **ámbar
   parpadeante** y en boot.log aparece
   `native: audio-btn: estado verificando` seguido de
   `saf: picker de audio abierto (elige la carpeta audio/ con
   streams/ y musyx/)`.
   - Si pulsas y la píldora sigue ámbar fija sin picker: el
     toque no cayó dentro (¿pulsaste fuera del rectángulo?),
     o es la APK vieja. Repite apuntando al centro inferior.
   - Si la píldora se queda parpadeando y NO se abre el
     picker: mira boot.log (`saf: picker de audio fallo: …`).
2. En el picker SAF, elige la carpeta **`audio/`** (o su padre
   si contiene `audio/`). **NO elijas** la carpeta de datos
   base ni `streams/` sola.
3. Espera a que termine la copia (1.047 ficheros; el progreso
   sale en boot.log cada 250 ficheros: `saf: progreso: …`).
   **Durante la copia, NO pulses la píldora de nuevo**: debe
   seguir parpadeando y no abrir un segundo picker.
   Tampoco cierres la app a mitad de copia: si lo haces, al
   reabrir el estado vuelve a derivarse (sin audio o listo
   según lo que quedara), nunca se queda parpadeando atascado.
4. **Esperado al terminar:** píldora **verde**, y en boot.log:
   ```
   saf: copia de audio terminada: 1047 ficheros, … B
   saf: verificacion de audio (anadir audio)
   saf: audio/ wav=816 adp=231 adp_invalidos=0
   saf: audio listo (marcador .saf-audio-done; …)
   native: audio-btn: estado audio listo
   ```
   - `adp_invalidos` debe ser **0** con el pack Tier 1 correcto.
     Si es >0, anota qué ficheros lista (máx. 10 en el log):
     esos ADP los saltará el bridge por fichero (silencio para
     esos streams, juego intacto).
   - Si la píldora queda **roja**: copia fallida. En boot.log
     estará `saf: copia de audio FALLO: …` y el marcador
     `.saf-audio-error`. Reporta esa línea (ver §4).

### A3. Volver a pulsar con audio listo (re-añadir/sustituir)
1. Con la píldora en verde, púlsala de nuevo.
2. **Esperado:** vuelve a **parpadeante** y se reabre el picker.
   Esto es deliberado: así se puede añadir más audio (por
   ejemplo, pasar de Tier 1 a Completo-ADP) o sustituir un pack
   corrupto sin reimportar los datos base.
3. Cancela el picker (atrás). **Esperado:** en el siguiente
   sondeo (cada 128 vueltas del bucle, ~1–2 s) la píldora
   vuelve a **verde** — Java escribe un marcador
   `.saf-audio-cancelled` al cancelar y el sondeo nativo lo
   consume y rederiva el estado (`audio/` con medios ⇒
   listo). Sin ese marcador, cancelar dejaría la píldora
   parpadeando hasta reiniciar; si eso ocurriera (píldora
   parpadeando más de 5 s tras cancelar), **repórtalo** con el
   boot.log: es una regresión del camino de cancelación.
   Si cancelas un primer intento sin audio previo, lo esperado
   es volver a **ámbar fijo** (sin audio), por el mismo
   mecanismo.

### A4. Comprobación de que no se tocó la base
Después de A2, el juego debe seguir cargando igual que antes
(mismo arranque, misma tarjeta `memcard-a.raw`). El flujo de
audio **nunca escribe** en `sys/` ni en `files/` ni borra
`.saf-copy-done`. Si tras importar audio el juego dejara de
cargar, es una regresión grave: repórtala con el boot.log
completo (ver §4).

## 3. Prueba B — Qué debe oírse con Tier 1 (solo cuando el juego llegue ahí)

**No intentes esta parte con una build que no juegue.** Con la
build de este tramo (prueba, no jugable), el criterio de éxito
es la parte A. La parte B es la especificación de lo que debe
ocurrir cuando el port juegue, para no tener que reescribirla:

1. **SFX Tier 0 (816 WAV):** efectos por trigger — pasos,
   golpes, menús, voces cortas MusyX — deben sonar en cuanto el
   juego los dispare. En boot.log, cada SFX deja
   `bridge: trigger SFX id … -> FX … -> muestra …` y
   `bridge: sfx_muestra id … -> '…wav' …`.
2. **Voz/ambiente TTH (231 ADP, 121 IDs resueltos):** al llegar
   a ThornTail Hollow, los diálogos `ttalk*` (p. ej. `ttalk1`,
   `ttalk2`), `mttalk*` y ambiente `tth*` deben sonar por ADP
   decodificado en dispositivo. En boot.log, la primera vez
   que suena un stream verás
   `bridge: stream por adp 'streams/TTH/….adp' (32000 Hz x2, …)`
   (o `por cache` si ya estaba cacheado, ver §4). Los 110 ADP
   TTH sin ID resuelto quedan listos pero en silencio hasta
   que la tabla de streams los resuelva: eso NO es un fallo
   del botón ni de la caché.
3. **Lo que NO debe oírse con ningún tier (no lo reportes como
   fallo de esta prueba):** música secuenciada MusyX (bancos
   `.pro`/`.poo` + `midi.wad`, `sndSeqPlayEx` sin cablear),
   streams fuera de TTH (en silencio con log `unresolved`),
   ni el stream 1367 (no existe en `Streams.bin`: es un
   problema aparte, documentado desde la Fase 14).

## 4. Prueba C — Caché PCM (qué comprobar, dónde, y qué significa)

La caché vive en `<base>/sfa-data/audio-cache/v1/` con esta
correspondencia (Tramo 5, sin cambios aquí):

```
ADP   sfa-data/audio/streams/TTH/ttalk1.adp
  ->  sfa-data/audio-cache/v1/streams/TTH/ttalk1.pcm   (s16le 32 kHz estéreo)
  ->  sfa-data/audio-cache/v1/streams/TTH/ttalk1.meta  (JSON: decoder dtk-v1,
        adp_bytes, adp_sha1, pcm_frames, pcm_bytes, last_used)
```

Reglas que debes verificar (cuando un stream TTH suene de
principio a fin):

1. **Tras sonar COMPLETO un stream TTH**, debe aparecer su
   `.pcm` + `.meta` en la caché, y en boot.log
   `bridge: cache ADP promovida 'streams/TTH/….adp'`.
   Tamaño esperado del `.pcm`: `adp_bytes / 32 * 28 * 4`
   (ratio 3,50×). Ejemplo: un ADP de 32.768 B ⇒ `.pcm` de
   114.688 B. Un `.pcm` de otro tamaño o un `.meta` con
   `pcm_bytes` distinto del tamaño real del `.pcm` es un fallo
   de caché: repórtalo con ambos tamaños.
2. **Segunda reproducción del mismo stream:** debe salir por
   caché, no por ADP: en boot.log
   `bridge: stream por cache 'streams/TTH/….adp' …` (la primera
   vez fue `por adp`). El sonido debe ser idéntico.
3. **Stream cortado a medias NO crea caché** (regla Tramo 5:
   la parcial no se promueve): si interrumpes un diálogo TTH
   (cambiar de zona, cortar el juego) y luego miras la caché,
   NO debe haber `.pcm` de ese stream (ni `.tmp` visible como
   válido: un `.pcm.tmp` huérfano nunca se reproduce y se
   borra al iniciar la caché). Si aparece un `.pcm` de un
   stream que sabes que no terminó, repórtalo.
4. **La caché nunca suena sin su ADP:** si borras un ADP de
   `audio/` dejando su `.pcm`, ese stream debe quedar en
   silencio con log (no sonar desde la caché huérfana).
   No borres ADP a mano salvo para esta comprobación concreta,
   y restáuralos después con el botón (re-añadir).
5. **Techo LRU 2.048 MiB:** la caché completa de TTH (231
   streams) son como máximo 377,45 MiB si sonaran todos, y el
   techo es 2.048 MiB, así que con Tier 1 **no debes ver
   desalojos** en uso normal. Si la caché total supera
   2.048 MiB o desaparecen `.pcm` de streams recientes, es un
   fallo del LRU: repórtalo con el listado de la caché.
6. **Cómo listar la caché sin PC (si no tienes adb a mano):**
   la vía fiable es boot.log (líneas `por adp` / `por cache` /
   `promovida` / `no promovida`). El listado de ficheros
   requiere adb + `run-as` (APK debuggable):
   ```
   adb shell "run-as com.starfox.port ls -l files/sfa-data/audio-cache/v1/streams/TTH/ | head -n 40"
   adb shell "run-as com.starfox.port cat files/sfa-data/audio-cache/v1/streams/TTH/ttalk1.meta"
   adb shell "run-as com.starfox.port cat files/boot.log" > boot-sesion.log
   ```
   Recuerda: extrae `boot.log` ANTES de relanzar la app.

## 5. Qué reportar si falla (copia y pega, sin resumir)

Para cada fallo, reporta estos 5 puntos (si falta uno, dilo):

1. **Paso exacto** (p. ej. «A2 paso 4» o «C punto 2») y qué
   esperabas ver.
2. **Color de la píldora** en el momento del fallo (ámbar /
   parpadeante / verde / rojo) y si responde a toques.
3. **Líneas de boot.log** relevantes, copiadas literales
   (`audio-btn:`, `saf:`, `bridge:`), y si el log se extrajo
   antes de relanzar la app.
4. **Listado de la caché** (si el fallo es de caché): salida
   del `ls` de `audio-cache/v1/streams/TTH/` y el `.meta` del
   stream afectado, si existe.
5. **Contenido de `sfa-data/audio/`** tras el fallo (conteo
   `wav=` / `adp=` / `adp_invalidos=` del informe SAF en
   boot.log), y si los datos base siguen cargando (sí/no).

Casos que NO son fallos de este tramo (no los reportes como
tales): música secuenciada muda (§3.3), streams fuera de TTH
en silencio, stream 1367 sin resolver, y la ausencia de texto
en la píldora (limitación documentada, pendiente P1).
