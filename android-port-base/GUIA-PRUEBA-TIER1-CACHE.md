# Guía de prueba en Tab S8 — Botón «añadir audio» CON ETIQUETA, Tier 1 y caché PCM (Tramo 7)

**LEE ESTO PRIMERO — qué es prueba real y qué no.**
Esta guía la ejecuta **el usuario en su Tab S8**; nada de lo que sigue
se ha probado en hardware en este tramo (sin enlace ADB en la tarea
y sin APK construida aquí: este tramo entrega código + tests host,
no una APK). Es la actualización Tramo 7 de la guía del Tramo 6:
**lo único que cambia en pantalla es que la píldora ya lleva texto**
(antes solo color). Todo lo demás — botón, importación, Tier 1,
caché, rumble — es idéntico al Tramo 6, y las partes B/C siguen
exigiendo juego jugable. La APK que salga de aplicar este parche
será, como GX20, una **APK de prueba NO jugable** hasta que el port
lo sea: la parte A (botón + etiqueta + importación) sí se puede
verificar entera con esa build; la parte B (sonido Tier 1 en juego
+ caché) solo se verificará cuando el juego llegue a ThornTail
Hollow (TTH) o a un stream TTH. **No des por buena la parte B si
solo pasó la parte A.** Si algo falla, reporta exactamente lo de
la sección «Qué reportar».

**Qué cambió en el Tramo 7 (y qué NO cambió).**
- CAMBIA: la píldora dibuja una etiqueta bitmap dentro de ella
  (fuente 5x7 en GL, sin overlay Java, sin cambios de foco ni de
  ciclo de vida). Textos por estado (ver §1).
- NO CAMBIA: posición, tamaño, color por estado, táctil
  (interceptación antes del juego, solo dedo que baja dentro,
  soltar fuera cancela, multitáctil independiente), sondeo cada
  128 vueltas, marcadores `.saf-audio-done/.saf-audio-error/
  .saf-audio-cancelled`, líneas de boot.log (sin prefijo nuevo),
  flujo SAF, bridge ni caché. Si algo de eso se comporta distinto
  que en el Tramo 6, es una regresión: repórtala aunque la
  etiqueta se vea bien.

## 0. Qué necesitas antes de empezar

- La APK con este tramo aplicado (rama `android-port-base`, parche
  `diffs/tramo7.patch` aplicado SOBRE el Tramo 6 (`c274c96`),
  build Gradle). Comprueba que es la build nueva: al arrancar
  debe verse la **píldora en el centro inferior CON TEXTO**
  (ver §1). Si se ve la píldora sin texto, es la build del
  Tramo 6 (GX20), NO la de este tramo: no sigas.
- Los datos base ya importados por SAF. Pack de test vigente
  (no cambiar estas cifras sin medirlas de nuevo):
  **base SAF 243.309.656 B + overlay Tier 1 = 382.982.980 B
  (365,24 MiB) / 3.968 ficheros, libre ≥1,5 GB.**
  La cifra 365,24 MiB es la huella TOTAL con la base incluida
  (base 232,04 MiB + overlay 133,20 MiB), NO lo que se transfiere
  con «añadir audio».
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
  Si transfieres 365 MiB por el picker de audio, has elegido la
  carpeta equivocada.
- Cómo leer `boot.log` (APK debuggable): con el puente ADB/PC o
  `run-as com.starfox.port cat files/boot.log` desde la tablet
  con adb. **Importante:** cada arranque de la app TRUNCA
  boot.log (se abre en escritura al inicio): extrae el log de
  una sesión ANTES de volver a abrir la app, o perderás la
  evidencia de esa sesión. Las líneas que importan empiezan por
  `audio-btn:`, `saf:` y `bridge:`. **El Tramo 7 no añade líneas
  nuevas**: la etiqueta no deja rastro en el log; su verificación
  es visual (esta guía) + táctil.

## 1. Dónde está el botón y cómo se reconoce (AHORA CON TEXTO)

- **Posición (sin cambios):** centro inferior de la pantalla,
  pegada al borde inferior. En la Tab S8 (2560×1600) mide
  **307×96 px**, centrada horizontalmente, a 32 px del borde
  inferior (fracciones x 0,44–0,56, y 0,92–0,98). Queda
  **debajo** del damero de prueba y **no solapa** ningún control:
  stick (izquierda abajo), rombo A/B/X/Y (derecha abajo), C-stick
  reservado (centro-derecha), L/R y Start (arriba).
- **Etiqueta + color = estado** (mira la píldora, no el juego;
  el texto mide 28 px de alto en la Tab S8 y ocupa 284 px de
  ancho en su etiqueta más larga, centrado en la píldora con
  11,5 px de margen lateral y 34 px vertical):

  | Estado | Color de la píldora | Texto dentro | Color del texto |
  |---|---|---|---|
  | sin audio | ámbar fijo | `AÑADIR AUDIO` | oscuro |
  | verificando | ámbar parpadeante (30 frames on/off) | `VERIFICANDO` | oscuro con ámbar encendido; ámbar con ámbar apagado (fondo oscuro) |
  | audio listo | verde | `AUDIO LISTO` | oscuro |
  | error | rojo | `ERROR AUDIO` | blanco |

  Notas de lectura: la Ñ de `AÑADIR` lleva tilde (en fuente 5x7
  se ve como dos puntos sobre la N; si parece una N normal a
  distancia, acércate: la tilde existe). El texto NUNCA debe
  salirse de la píldora, ni tocar el damero, ni tapar ningún
  botón de juego. Si el texto se ve recortado, desplazado,
  borroso hasta ser ilegible, o fuera de la píldora, es un fallo
  del Tramo 7: repórtalo con foto si puedes (ver §5) y con el
  estado/color en ese momento.

## 2. Prueba A — Botón + etiqueta + importación Tier 1 (verificable YA)

### A0. Etiqueta en cada estado (nuevo del Tramo 7, hazlo primero)
1. Abre la app con los datos base ya importados pero SIN audio.
   **Esperado:** píldora **ámbar fija** con el texto
   **`AÑADIR AUDIO`** legible dentro de ella, sin salirse por
   ningún lado.
2. Pulsa la píldora y, sin elegir carpeta todavía (o justo al
   abrirse el picker), fíjate en la píldora: **esperado:**
   **ámbar parpadeante** con el texto **`VERIFICANDO`**.
   (El parpadeo alterna fondo ámbar / fondo oscuro; el texto
   sigue siendo `VERIFICANDO` en ambas fases.)
3. Completa la importación (A2) y comprueba: píldora **verde**
   con el texto **`AUDIO LISTO`**.
4. Si puedes provocar un error sin romper nada (por ejemplo,
   elegir una carpeta sin `audio/` válido, o cancelar de forma
   que falle la copia), **esperado:** píldora **roja** con el
   texto **`ERROR AUDIO`** en blanco. No fuerces un error
   borrando datos: si no se da de forma natural, deja este punto
   como «no observado» y dilo así en el reporte (no es un fallo
   no haber visto el rojo).
5. En todos los estados: el texto debe estar **centrado** en la
   píldora y **no debe invadir** el damero ni ningún control.
   Toca el stick virtual y pulsa A: **el juego debe responder
   igual que antes** (la etiqueta no añade zona táctil: tocar
   las letras es tocar la píldora, y tocar fuera de la píldora
   sigue siendo juego).

### A1. Estado inicial
1. Abre la app con los datos base ya importados pero SIN audio.
2. **Esperado:** píldora **ámbar fija** con `AÑADIR AUDIO`
   visible en el centro inferior, y en boot.log una línea
   `native: audio-btn: estado sin audio`.
3. Toca el stick virtual y pulsa A: **el juego debe responder
   igual que antes** (el botón no roba juego). Toca fuera de la
   píldora (por ejemplo, el centro de la pantalla): **no debe
   abrirse ningún picker**.

### A2. Importar Tier 1 con el botón
1. Pulsa la píldora (toque corto, soltar DENTRO de la píldora).
   **Esperado inmediato:** la píldora pasa a **ámbar
   parpadeante** con `VERIFICANDO` y en boot.log aparece
   `native: audio-btn: estado verificando` seguido de
   `saf: picker de audio abierto (elige la carpeta audio/ con
   streams/ y musyx/)`.
   - Si pulsas y la píldora sigue ámbar fija sin picker: el
     toque no cayó dentro (¿pulsaste fuera del rectángulo?),
     o es la APK vieja. Repite apuntando al centro inferior,
     sobre las letras.
   - Si la píldora se queda parpadeando y NO se abre el
     picker: mira boot.log (`saf: picker de audio fallo: …`).
   - Si el picker se abre pero la etiqueta NO dice
     `VERIFICANDO` (sigue `AÑADIR AUDIO` o no hay texto):
     es un fallo del Tramo 7: repórtalo con el color y el
     texto que veas.
2. En el picker SAF, elige la carpeta **`audio/`** (o su padre
   si contiene `audio/`). **NO elijas** la carpeta de datos
   base ni `streams/` sola.
3. Espera a que termine la copia (1.047 ficheros; el progreso
   sale en boot.log cada 250 ficheros: `saf: progreso: …`).
   **Durante la copia, NO pulses la píldora de nuevo**: debe
   seguir parpadeando con `VERIFICANDO` y no abrir un segundo
   picker. Tampoco cierres la app a mitad de copia: si lo haces,
   al reabrir el estado vuelve a derivarse (sin audio o listo
   según lo que quedara), nunca se queda parpadeando atascado.
4. **Esperado al terminar:** píldora **verde** con
   **`AUDIO LISTO`**, y en boot.log:
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
   - Si la píldora queda **roja** con `ERROR AUDIO`: copia
     fallida. En boot.log estará
     `saf: copia de audio FALLO: …` y el marcador
     `.saf-audio-error`. Reporta esa línea (ver §5).

### A3. Volver a pulsar con audio listo (re-añadir/sustituir)
1. Con la píldora en verde (`AUDIO LISTO`), púlsala de nuevo.
2. **Esperado:** vuelve a **parpadeante** con `VERIFICANDO` y
   se reabre el picker. Esto es deliberado: así se puede añadir
   más audio (por ejemplo, pasar de Tier 1 a Completo-ADP) o
   sustituir un pack corrupto sin reimportar los datos base.
3. Cancela el picker (atrás). **Esperado:** en el siguiente
   sondeo (cada 128 vueltas del bucle, ~1–2 s) la píldora
   vuelve a **verde** con `AUDIO LISTO` — Java escribe un
   marcador `.saf-audio-cancelled` al cancelar y el sondeo
   nativo lo consume y rederiva el estado. Si la píldora se
   queda parpadeando más de 5 s tras cancelar, **repórtalo**
   con el boot.log: es una regresión del camino de cancelación.
   Si cancelas un primer intento sin audio previo, lo esperado
   es volver a **ámbar fijo** con `AÑADIR AUDIO`, por el mismo
   mecanismo.

### A4. Comprobación de que no se tocó la base
Después de A2, el juego debe seguir cargando igual que antes
(mismo arranque, misma tarjeta `memcard-a.raw`). El flujo de
audio **nunca escribe** en `sys/` ni en `files/` ni borra
`.saf-copy-done`. Si tras importar audio el juego dejara de
cargar, es una regresión grave: repórtala con el boot.log
completo (ver §5).

### A5. Táctil con la etiqueta (regresión Tramo 6, rápida)
La etiqueta no debe cambiar el táctil. Comprueba estos 3 casos
(los mismos del Tramo 6, ahora tocando sobre las letras):
1. Toque que empieza FUERA de la píldora y se desliza HASTA
   ella: **NO debe abrir el picker** (solo arma un dedo que
   baja dentro).
2. Toque dentro que se desliza FUERA y se suelta fuera:
   **NO debe abrir el picker** (soltar fuera cancela).
3. Dos dedos a la vez (uno en la píldora, otro en el stick):
   **ambos deben funcionar** (el stick se mueve y la píldora
   dispara al soltar dentro).
Si alguno falla, es una regresión grave del táctil: repórtala
indicando el caso (1/2/3) y si el fallo existía ya en GX20.

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

Para cada fallo, reporta estos 6 puntos (si falta uno, dilo):

1. **Paso exacto** (p. ej. «A0 paso 2», «A2 paso 4» o «C punto 2»)
   y qué esperabas ver.
2. **Color Y TEXTO de la píldora** en el momento del fallo
   (ámbar / parpadeante / verde / rojo + qué texto se leía, o
   «sin texto», o «texto recortado/fuera») y si responde a
   toques. Si puedes, adjunta foto de la píldora.
3. **Líneas de boot.log** relevantes, copiadas literales
   (`audio-btn:`, `saf:`, `bridge:`), y si el log se extrajo
   antes de relanzar la app.
4. **Listado de la caché** (si el fallo es de caché): salida
   del `ls` de `audio-cache/v1/streams/TTH/` y el `.meta` del
   stream afectado, si existe.
5. **Contenido de `sfa-data/audio/`** tras el fallo (conteo
   `wav=` / `adp=` / `adp_invalidos=` del informe SAF en
   boot.log), y si los datos base siguen cargando (sí/no).
6. **¿Es fallo nuevo del Tramo 7 o ya pasaba en GX20?** Si la
   etiqueta es lo único distinto, dilo; si el táctil o la
   importación fallan igual que en GX20, dilo también (eso
   distingue una regresión de la etiqueta de un fallo viejo).

Casos que NO son fallos de este tramo (no los reportes como
tales): música secuenciada muda (§3.3), streams fuera de TTH
en silencio, stream 1367 sin resolver, y no haber observado el
estado rojo `ERROR AUDIO` si no se dio ningún error real.
