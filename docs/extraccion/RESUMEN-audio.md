# RESUMEN — Audio de Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL)

Extracción realizada el 2026-10-25 desde el árbol del disco en
`./disc/` (solo lectura; ningún fichero del
disco fue modificado). Herramienta:
`./assets/herramientas/audio/extract_audio.py`
(Python 3, solo biblioteca estándar, sin rutas absolutas hardcodeadas;
se invoca con `--disc` y `--out`).

Reproducir:

```
python extract_audio.py --disc ./disc \
    --out ./assets/extraidos/audio --jobs 2
```

## Resultado global

| Concepto | Cantidad |
|---|---|
| Streams ADP → WAV | 958 ficheros, 0 fallos |
| Muestras MusyX → WAV | 1.472 muestras, 0 fallos |
| Ficheros en bruto (sin decodificar) | 20 |
| Filas en el inventario | 2.450 |
| Bytes totales de salida (WAV + brutos) | 1.984.451.098 (~1,85 GiB) |

Inventario: `./assets/inventarios/audio.csv`
(2.450 filas + cabecera, sin campos vacíos en `salida`/`sha1_salida`).
`fuente` es siempre relativa a la raíz del disco (p. ej.
`files/streams/AN/an1301.adp`, `files/audio/starfoxm.sam`). Para filas ADP
y brutos, `tamano`/`sha1_fuente` son del fichero completo; para filas
MusyX son del **recorte** de la muestra dentro de `.sam`
(`offset_en_fuente` = offset del recorte, `tamano` =
ceil(n_muestras/14)*8 bytes). Los `.sam` completos están en `brutos/`
con su propio SHA-1, así que toda muestra es trazable por dos vías.

## 1. Streams ADP (ADPCM DTK de GameCube) → WAV estéreo 32000 Hz

**Formato, verificado bloque a bloque en todo el disco.** Cada bloque
tiene 32 bytes: `[hdrL, hdrR, hdrL, hdrR, 28 bytes de datos]`. Los bytes
2 y 3 son copias redundantes de 0 y 1 (verificado en los 17.072.128
bloques de los 958 ficheros: siempre iguales). Cada byte de datos
aporta un nibble por canal (bajo = L, alto = R): 28 muestras estéreo
por bloque. Cabecera por canal: nibble alto = índice de coeficientes,
nibble bajo = exponente de escala (`escala = 4096 >> exp`). En este
disco solo aparecen índices 0–3 y exponentes 0–12 (≥4 se comportaría
como predictor nulo y 13–15 darían escala 0, igual que FFmpeg, pero no
ocurren en datos reales).

Coeficientes del predictor (en /2048), estado en punto fijo x2048:

```
P = trunc((c1*X1 + c2*X2) / 2048);  P = clamp(P, -32768*2048, 32767*2048)
X = nibble*escala*2048 + P;         X = clamp(X, -32768*2048, 32767*2048)
muestra = floor(X / 2048)
(c1, c2) = {0: (0,0), 1: (1920,0), 2: (3680,-1664), 3: (3136,-1760)}
```

La saturación es en **dos etapas** (predictor y estado). Sin saturar el
predictor, los ataques fuertes a fondo de escala divergen de FFmpeg
hasta 16.520 LSB; con ella, la divergencia máxima medida es de 4 LSB.
El historial se arrastra entre bloques y durante todo el fichero, y
empieza en 0 en cada fichero. Los coeficientes se confirmaron por
ajuste contra FFmpeg: valores vecinos (±1/2048) disparan el error a
36–607 por la resonancia del filtro.

**Validación contra FFmpeg** (`adpcm_dtk`, 32000 Hz, estéreo), sobre los
WAV entregados:

| Fichero | Exactas bit a bit | Desviación máx. |
|---|---|---|
| Datos sintéticos aleatorios (20 bloques) | 97,7 % | 1 LSB |
| `streams/TTH/th03u_sa.adp` (dual-mono) | 96,71 % | 4 LSB |
| `streams/AN/an1301.adp` (estéreo) | 95,61 % | 4 LSB |
| `streams/GNR/gnr1423.adp` (mayor estéreo) | 95,41 % | 4 LSB |
| `streams/VFP/vf01e_pe.adp` (mayor dual-mono) | 96,40 % | 4 LSB |

El residuo de ≤4 LSB (0,012 % del fondo de escala) se atribuye al
redondeo interno en coma flotante de FFmpeg, no a los coeficientes; es
inaudible y no se ha intentado "corregir" inventando un redondeo
distinto.

**Frecuencia 32000 Hz**: es la frecuencia fija del streaming DTK de
GameCube. En el código del juego no se encontró ninguna llamada que
fije otra frecuencia para streams (solo la definición del SDK), así
que los WAV usan 32000 Hz y su duración es `frames / 32000`.

**Totales reales**: 958 ficheros `.adp` (todos en `files/streams/`, no
hay `.adp` en ningún otro sitio del disco), 546.308.096 bytes
(521,0 MiB), 17.072.128 bloques, 478.019.584 frames, 14.938,1 s de
audio, WAV resultantes 1.912.120.488 bytes. 734 de los 958 son
dual-mono (L==R en todas las muestras; marcado en la columna `notas`
del inventario); 224 son estéreo real. Por directorio (TOP):
TTH 231, COMM 97, CRF 83, DIM 77, WC 77, DR 53, SW 41, KP 38, MAP 26,
MMP 26, LV 24, ARW 22, SSH 22, OFP 21, SSS 20, CC 19, SK 18, GB 16,
VFP 11, CR 6, IM 6, KS 5, GNR 4, AN 3, TREX 3, DB 2, DFS 2, GF 2, MC 2,
TOSKL 1 (suma 958).

**Comparación con la referencia 2026-10-11 (958 ADP→WAV)**: coincide
exactamente. No hay desviación de conteo: 958 ficheros encontrados y
958 convertidos, 0 fallos.

**`Streams.bin` NO es el índice de los ADP ni una tabla de
duraciones** (905 registros × 22 bytes; 785 nombres únicos; 880
registros con `lengthRaw` = 0 y solo 25 distintos de cero). Comprobado:
188 ficheros ADP no tienen ningún registro en `Streams.bin` (entre
ellos todo `COMM/`), y 15 nombres de `Streams.bin` no tienen fichero
ADP (nombre vacío, variantes de mayúsculas como `GB/bird` frente a
`GB/Bird.adp`, `KP/EWDie` frente a `EWdie.adp`, `TTH/QueenOk` frente a
`QueenOK.adp`, `WC/wc09b`, `unknown`, etc.). Además `lengthRaw/100`
no es la duración: p. ej. `GB/Intro` dura 112,90 s frente a un
`lengthRaw` de 72,00 s, y el audio sigue siendo audible hasta el
final; `GNR/gnrdeath` dura 8,96 s frente a 3,00 s y es silencio exacto
desde ~el 60 %. Según el código del juego, `lengthRaw/100.0` solo se
usa como punto de fundido de música, no como duración ni punto de
parada. Por eso el conjunto autoritativo de ficheros es el de los ADP
(958) y las duraciones del inventario salen de los propios ficheros.
`Streams.bin` queda en `brutos/` (ver §3).

## 2. Bancos MusyX (`.sam` / `.sdi`) → WAV mono

**Estructura verificada exhaustivamente.** `starfoxm` = 594 muestras
(Sound IDs 0–593), `starfoxs` = 878 muestras (IDs 594–1471); total
**1.472**. Table A: entradas de 32 bytes terminadas en `0xFFFFFFFF`;
Table B empieza justo después y mide exactamente entradas × 40 bytes
en ambos grupos. Validación de `.sam`: 0 recortes fuera de límites;
cada offset siguiente = `align32(offset anterior +
ceil(n_muestras/14)*8)`; el final acolchado de la última entrada
coincide exactamente con la longitud del `.sam` en ambos grupos; el
byte `ps_inicial` de Table B coincide con el primer byte de la muestra
en `.sam` en las 1.472/1.472 muestras. Barrido completo de índices de
predictor DSP en todos los datos: ninguno supera 7 (el decodificador
nunca puede fallar por ese motivo).

**Decodificación DSP-ADPCM estándar**, predictor en /2048:

```
muestra = clamp((nibble << escala) + ((h1*c0 + h2*c1 + 1024) >> 11))
```

con `pred = cabecera >> 4`, `escala = cabecera & 0xF`, y los 8 pares
de coeficientes de Table B. El redondeo del desplazamiento es
**"half up"** (+1024 antes de `>> 11`): se eligió por validación
contra el contexto de bucle de Table B (decodificar hasta
`bucle_inicio` debe dejar el estado igual al historial de bucle
almacenado). Resultados sobre las 321 muestras con bucle:

| Redondeo | Historiales exactos |
|---|---|
| half up (+1024, `>> 11`) | **321/321** (320 no triviales + 1 con `bucle_inicio` = 0) |
| half away | 298/321 |
| half even | 303/321 |
| floor (`>> 11` sin más) | 29/321 |
| trunc | 21/321 |
| ceil | 27/321 |

(Variantes Q14, pares intercambiados y coeficientes cruzados, probadas
antes, daban errores de miles.) Los WAV son mono a la frecuencia de
Table A por muestra, recortados a exactamente `n_muestras`. **Los
bucles NO se repiten en el WAV**: se decodifica una sola pasada y
`loop_inicio`/`loop_longitud` quedan en el inventario.

**Totales reales**: 1.472 WAV, 26.656.431 muestras, 1.547,8 s,
53.377.630 bytes. Nombres: 828 muestras con nombre de `starfox.h.bak`
(`<id 4 dígitos>_<nombre>`, sanitizado) y 644 sin nombre
(`sample_<id 4 dígitos>`); `starfox.h.bak` tiene 998 `#define`, 828
valores SFX únicos (0–827) y 57 grupos GRP. Con bucle: 321 muestras
(`starfoxm` 240, `starfoxs` 81). Frecuencias: 22050 Hz ×811,
16000 ×426, 11025 ×221, 32000 ×10, 8000 ×2, 20000 ×1, 44100 ×1.

**Observación abierta (no es un fallo probado)**: la muestra
`starfoxs` ID 594 (`SFXfox_roll4` según `.h.bak`) decodifica con
autocorrelación lag-1 de −0,768 y oscilación fuerte (primeras
muestras 7168, −8893, 6416, …). No produce ningún error (los
predictores se mantienen ≤7) y la fórmula está validada por los
321/321 historiales de bucle, así que probablemente sea un sonido
áspero/ruidoso genuino; se deja constancia aquí en lugar de
"suavizarlo" o descartarlo.

## 3. Qué quedó en bruto y por qué (20 ficheros, 18.952.980 bytes)

Todo en `brutos/`, byte a byte idéntico al disco, sin contenido
inventado. Los `.adp` originales **no** se duplican en `brutos/` (el
disco sigue siendo el archivo; su salida son los WAV).

| Fichero(s) | Motivo |
|---|---|
| `starfoxm.sam`, `starfoxs.sam` (+ `.sdi`) | Contenedores MusyX completos; sus muestras están decodificadas en `musyx/`, pero el original íntegro queda aquí. |
| `starfoxm.pro`, `starfoxs.pro` | Solo parse estructural: ambas comparten los mismos primeros words de cabecera (`0x1b48, 0, 0x28, 0x2e, …`) y muestran patrones repetitivos en `0x29e` (6 bytes) y `0x300`, pero no se estableció ninguna semántica; no se inventa un parse. |
| `starfoxm.poo`, `starfoxs.poo` | Solo parse estructural por campos de tamaño: `starfoxm` = 594 SoundMacros que terminan 4 bytes antes del offset de tablas (`0xc994`, hueco `0xFFFFFFFF`); `starfoxs` = 924 SoundMacros hasta `0xef44` (sin sección de tablas). La semántica de los comandos de SoundMacro no se decodificó. |
| `midi.wad` (1.273.280 B) | Sin eventos MIDI estándar: 0 ocurrencias de `MThd`; el recorrido por chunks con prefijo de tamaño falla (el primer u32 = 19744 cubre un solo chunk hasta 19748 de 1.273.280). Empieza con 108 pares u32-BE (0, X) y luego se rompe en `80 00 00 76 00 00 18 00 …`. No se estableció ningún parse de eventos de canción MusyX. |
| `Music.bin` (2.544 B), `Sfx.bin` (38.560 B = 1205 × 32 bytes), `Streams.bin` (19.920 B) | Tablas de triggers. Solo se verificó estructura: el primer registro de `Sfx.bin` es coherente con el layout `SfxTriggerFull` del decomp (id 1, volBase 0x28, pitchBase 0x7f, …). La decodificación semántica completa de triggers queda fuera de alcance; `Streams.bin` se documenta en §1. |
| `Empty0.bin`–`Empty7.bin` (262.144 B cada uno) | Los 8 son byte a byte idénticos; todos sus bytes son ASCII imprimible (0x20–0x7E, 95 valores distintos) sin periodicidad en ningún periodo probado (256–65536, fracción de coincidencia ≈0,072–0,074 = azar). Se interpretan como buffers placeholder/dummy, no como audio; se conservan los 8. |
| `files/musyxbin/` | Vacío en este disco (0 ficheros en `global/` y `starfox/`): no había nada que extraer. |

## 4. Fallos y caveats

- **Fallos: 0** en ADP (958/958) y 0 en MusyX (1.472/1.472). No hubo
  ficheros descartados ni muestras omitidas.
- Desviación residual ADP frente a FFmpeg: ≤4 LSB (ver §1). No afecta
  a la escucha y no se ha maquillado.
- Redondeo DSP: half up, 321/321 historiales de bucle exactos (§2).
- `lengthRaw` de `Streams.bin` es un punto de fundido, no una
  duración; `Streams.bin` no cubre todos los ADP (§1).
- Muestra 594 de `starfoxs`: sonido áspero genuino probable (§2).
- Trabajo futuro (fuera del alcance de esta tarea): decodificación de
  eventos de canción en `midi.wad` y semántica completa de `.pro`/`.poo`
  (referencia posible: amuse y la documentación de formato AGSC de
  Metroid Prime).
