# Vídeo de Star Fox Adventures — RESUMEN de extracción

**Fuente (solo lectura, no modificada):** `disc/files/starfox.thp`
(GSAP01 Rev 1 PAL, la película de la pantalla de título según la wiki de
SFA-Decomp, `docs/wiki/Files.md`).

| Concepto | Valor verificado |
|---|---|
| Tamaño del THP | 48.931.320 bytes (coincide con el tamaño que da la wiki) |
| SHA-1 del THP | `90cd0a1670128c3f731f3a0386916b2553756096` |
| Formato / versión | THP v1.0 (`0x00010000`), magic `THP\0` |
| Vídeo | 512×384, 29,97 fps, **1.797 frames** |
| Audio | 2 canales, 32.000 Hz, ADPCM propio de THP |
| Muestras de audio | 1.920.426 por canal = 60,013 s |
| Duración de vídeo | 1.797 / 29,97 = 59,96 s (el audio trae ~53 ms más; es así en la fuente: el último frame de audio declara 1.068 muestras frente a las 1.064–1.078 habituales) |
| Frames extraídos | **1.797 JPEG** (`frame_0000.jpg` … `frame_1796.jpg`) |
| Audio extraído | **1 WAV** (`audio.wav`, PCM s16le estéreo 32 kHz) |
| Salida total | 54.377.964 bytes (1.798 ficheros: 1.797 JPEG + WAV) |
| Inventario | `assets/inventarios/video.csv` (1.798 filas + cabecera) |
| Extractor | `assets/herramientas/video/thp_extract.py` (sin rutas absolutas; ver regeneración abajo) |

## Estructura THP verificada (no asumida)

La wiki de SFA-Decomp (`Formats.md`, `Files.md`) no documenta el formato
THP en sí; solo identifica `starfox.thp` como la película de título. La
estructura siguiente se tomó de YAGCD §15.34 y se verificó byte a byte
contra este archivo con scripts (nunca a ojo):

**Cabecera THP (48 bytes, big-endian):** magic `THP\0`, versión
`0x00010000`, maxBufferSize 46.528, maxAudioSamples 1.078, fps 29,97,
numFrames 1.797, firstFrameSize 5.760, dataSize 48.931.232
(= tamaño del archivo − 88), componentDataOffset 48,
offsetsDataOffset 0 (sin tabla de offsets), firstFrameOffset 88,
lastFrameOffset 48.926.296.

**Componentes (offset 48):** numComponents 2, tipos `[video, audio, 0xFF…]`;
VideoInfo 512×384; AudioInfo 2 canales, 32.000 Hz, 1.920.426 muestras
totales. En v1.0 el AudioInfo no lleva el campo `numData` de v1.1: hay
exactamente un frame de audio por frame de vídeo.

**Frame (cabecera de 16 bytes):** `nextTotalSize`, `prevTotalSize`,
`imageSize`, `audioSize`; después van `imageSize` bytes de vídeo y
`audioSize` bytes de audio. El tamaño almacenado de cada frame es el
total redondeado hacia arriba a múltiplo de 32 bytes (relleno con ceros).
Verificación completa de la cadena, sin excepciones:

- Los 1.797 frames se recorren exactamente hasta el final del archivo
  (offset final 48.931.320 = tamaño del archivo, 0 bytes sobrantes).
- Todos los enlaces `prevTotalSize`/`nextTotalSize` internos coinciden
  con los tamaños almacenados vecinos (0 errores).
- La cadena es incluso circular: `prev` del frame 0 = tamaño del último
  frame (5.024) y `next` del último = tamaño del primero (5.760).
- Los 24.644 bytes de relleno a 32 bytes son todos cero.
- El último frame empieza exactamente en `lastFrameOffset`.

**Vídeo ("quasi-JPEG"):** cada frame es un JPEG al que le falta el
relleno estándar: en los datos de scan, los bytes `0xFF` literales van
sin el `0x00` que exige JPEG. El extractor convierte cada `0xFF` del
scan en `0xFF 0x00` (buscando el SOS `0xFFDA` y el EOI `0xFFD9` hacia
atrás, como indica YAGCD) y recorta la cola tras el EOI. Totales:
159.557 bytes `0xFF` rellenados y 2.633 bytes tras EOI recortados
(`imageSize` incluye a veces 0–3 bytes de ceros tras el EOI).
Importante: las secuencias `FF D0–D7` dentro del scan son bytes `0xFF`
literales, NO marcadores de reinicio: rellenarlas también es lo correcto
(comprobado: con relleno total los PNG coinciden con la decodificación
nativa de ffmpeg; preservando supuestos RST, no).

**Audio (ADPCM THP, distinto del ADPCM de los `.dsp`):** cada frame de
audio tiene una cabecera de 80 bytes — `channelSize` (bytes ADPCM por
canal), `numSamples` (muestras por canal), tabla de coeficientes de
16 s16 en punto fijo 5.11 por canal (siempre las dos, también en mono),
y `prev1/prev2` por canal — seguida de `channelSize` bytes del canal 1
y otros tantos del canal 2. Se cumple en los 1.797 frames:
`audioSize == 80 + 2 × channelSize`. Los datos son paquetes de 8 bytes
= 14 muestras: byte 0 = `index = (b >> 4) & 0x7`, `exponent = b & 0xF`;
factores = `tabla[2×index] / 2^11` y `tabla[2×index+1] / 2^11`; 7 bytes =
14 nibbles de 4 bits con signo; `muestra = clamp_s16(((prev1×f1 +
prev2×f2) >> 11) + (nibble << exponent))`. La suma de `numSamples` de
todos los frames es exactamente 1.920.426 = el total de la cabecera de
audio. El último frame declara 1.068 muestras aunque sus 616 bytes por
canal dan capacidad para 1.078: se emiten exactamente las 1.068
declaradas y se descarta la cola del último paquete.

## Validación cruzada con ffmpeg

- **JPEG:** los 1.797 JPEG decodifican con ffmpeg en una sola pasada
  (`frame_%04d.jpg` → null), salida 0, sin errores. Además, 7 frames
  muestreados a lo largo del archivo (0, 1, 2, 100, 500, 1000, 1796)
  producen PNG **byte a byte idénticos** a la decodificación nativa
  del THP por ffmpeg.
- **Audio (modo por defecto, `header`):** cada frame se decodifica con
  el estado previo de su propia cabecera (lo que el formato especifica
  y lo que permite decodificar frames sueltos). Frente al WAV de ffmpeg
  (`adpcm_thp`, 32 kHz estéreo, 1.920.426 muestras/canal): 95,06 %
  de muestras exactas; excluyendo el último frame, 95,08 % y
  diferencia máxima 432 (solo en las primeras muestras tras cada
  frontera de frame, por el reinicio de historia; decae a cero).
- **Audio (modo `carried`, `--audio-history carried`):** el estado se
  arrastra entre frames, como hace el decodificador de ffmpeg.
  Excluyendo el último frame es **100,0000 % exacto** frente a ffmpeg
  (diferencia máxima 0). El extractor soporta ambos modos; el WAV
  entregado es el del modo `header` por defecto.
- **Último frame (divergencia documentada, no un fallo del extractor):**
  tanto en modo `header` como en `carried`, el último frame coincide
  con ffmpeg solo en ~59 % de sus muestras, con una diferencia máxima
  de 32.821: ffmpeg emite ahí un pico recortado a 32.767 que no está
  en la decodificación fiel al formato. El propio ffmpeg avisa al
  decodificar este archivo: `invalid number of samples in packet`
  (el último paquete declara 1.068 muestras frente a 1.078 de
  capacidad). Conclusión: la cola del WAV de ffmpeg es la que no es
  fiable; el WAV entregado sigue los conteos declarados por el
  formato y suma exactamente el total de la cabecera.

## Comparación con la referencia 2026-10-11

La referencia decía «THP → 1.797 JPEG + WAV». **Coincidencia exacta:
1.797 JPEG + 1 WAV, sin desviación que investigar.** (El mismo conteo
era esperable: el número de frames está en la cabecera THP, 1.797.)

## Fallos

Ninguno. 0 frames con error de cadena, 0 JPEG con error de
decodificación, 0 frames de audio que incumplan `audioSize ==
80 + 2 × channelSize`, 0 bytes de relleno distintos de cero. La única
anomalía observada es el aviso de ffmpeg sobre el último paquete de
audio (ver arriba), que afecta a la referencia, no a esta extracción.

## Regeneración

```bash
python assets/herramientas/video/thp_extract.py \
  disc/files/starfox.thp \
  --out assets/extraidos/video \
  --inventory assets/inventarios/video.csv
# Variante con historia de audio arrastrada (bit-exacta con ffmpeg
# salvo el último frame):
python assets/herramientas/video/thp_extract.py \
  disc/files/starfox.thp \
  --out /tmp/thp_carried --audio-history carried
```

El inventario CSV lleva, por frame: índice, archivo, tamaño, SHA-1,
resolución (512×384) y detalle (`stored`/`stuffed`/`trimmed`/`padding32`);
y una fila de audio con tamaño, SHA-1, frecuencia/canales/muestras y
modo de historia usado.
