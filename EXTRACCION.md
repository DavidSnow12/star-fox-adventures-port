# EXTRACCION — Star Fox Adventures: qué se extrajo, cómo y qué quedó en bruto

Los resúmenes detallados por categoría están en `docs/extraccion/`
(RESUMEN-textos, RESUMEN-texturas, RESUMEN-video, RESUMEN-audio,
RESUMEN-modelos). Aquí va el consolidado con las cifras verificadas.

## Inventarios

Todos los inventarios están en `analisis/` (CSV con SHA-1 de fuente y salida):
`disco.csv` (3.879 ficheros del disco), `textos.csv`, `texturas.csv`,
`video.csv`, `audio.csv`, `modelos.csv` y los inventarios por familia de
modelos (`objetos.csv`, `objindex.csv`, `dlls.csv`, `mapas.csv`,
`animaciones.csv`, `modanim.csv`, `amap.csv`, `modelind.csv`,
`voxmap_root.csv`, `voxmap_resumen.csv`, `romlists.csv`,
`romlists_resumen.csv`, `animaciones_resumen.csv`).

## Textos — completo

- Formato real en disco: registro de 12 bytes
  (`u16 id, u16 num_frases, u8 window, u8 align_h, u8 align_v, u8 idioma,
  u32 indice_primera_frase`), no el struct con puntero de la wiki.
- 1.020/1.020 ficheros, 26.338 textos, 62.566 frases, 0 fallos. Cadenas en
  UTF-8 directo; controles propios conservados como tokens, sin pérdida.
- Por idioma (ficheros/textos/frases): English 204/5.268/12.084,
  French 204/5.270/13.038, German 204/5.267/12.018, Italian 204/5.268/13.329,
  Spanish 204/5.265/12.097. Español verificado con acentos, ñ, ¡ y ¿.
- Sin parsear: GAMETEXT.bin/.tab (versión antigua sin uso, formato
  desconocido según la wiki, no se adivinó), TEXTABLE.bin (tabla `u16` de
  remapeo de IDs de textura, corresponde a texturas), `*.c.new` de Boot
  (artefactos de generación, solo comprobación cruzada).

## Vídeo — completo

- `starfox.thp` (48.931.320 bytes, SHA-1
  `90cd0a1670128c3f731f3a0386916b2553756096`) → 1.797 JPEG 512×384 +
  1 WAV estéreo 32 kHz, 60,013 s, 0 fallos. Formato THP v1.0 verificado
  byte a byte (la wiki SFA no lo documenta; estructura según YAGCD §15.34),
  con validación cruzada ffmpeg (JPEG byte-idénticos en muestra; audio
  100 % en modo carried salvo el último frame, donde el propio ffmpeg
  avisa de muestras inválidas).

## Texturas — completo

- 107 pares `.tab/.bin` (TEXPRE + TEX0/TEX1 en raíz y 52 mapas), 9.700
  entradas → 19.264 fotogramas → 19.264 PNG, 0 errores, 0 sin decodificar.
  Total 20.210 PNG (19.264 + 944 secundarias I4 + 2 SCREENS).
- Formatos: RGB5A3 11.036, CMPR 5.076, IA8 1.861, RGBA8 1.134, I8 81,
  I4 48, IA4 28. Solo se emite el nivel base (con mipmaps: 5.306).
- Hallazgos: cabecera DIR de 16 B + prefijo 16 B (el blob empieza en +32);
  TEXPRE[0] doblemente empaquetado (DIR→ZLB→placeholder IA8 8×8) explica
  el +1 frente a la referencia 19.263; el desambiguador correcto entre
  secundaria I4 y cadena de mipmaps es el campo `0x50`.
- En bruto: FONTS.bin (10 fuentes, sin formato de glifos documentado),
  SPRITES.bin/.tab (definiciones, no píxeles), SPRTABLE.bin (casi todo
  ceros), CACHEFONTSTEX.bin (0 B). Ningún blob TEX quedó en bruto.
- Los PNG se emiten tal como están almacenados (sin voltear, como avisa
  la wiki) y sin deduplicar entre mapas, como en el disco.

## Audio — completo

- ADP → WAV: 958/958, 0 fallos, estéreo 32.000 Hz, 14.938,1 s.
  734 dual-mono, 224 estéreo real. Decodificador DTK con saturación en
  dos etapas (desviación vs ffmpeg ≤4 LSB, inaudible).
- MusyX → WAV: 1.472/1.472, 0 fallos (starfoxm 594 + starfoxs 878), mono,
  1.547,8 s, redondeo half-up validado 321/321 en bucles. 828 con nombre,
  644 sin nombre, 321 con bucle (no repetido en el WAV).
- En bruto (20 ficheros, byte-idénticos): `.pro`/`.poo` (estructura sin
  semántica), `midi.wad` (sin `MThd`, eventos MusyX no parseados),
  `Music.bin`/`Sfx.bin`/`Streams.bin` (tablas de triggers),
  `Empty0–7.bin` (placeholder ASCII), `.sam`/`.sdi` completos (sus
  muestras ya están decodificadas). `musyxbin/` está vacío en este disco.
- Aviso: `Streams.bin` NO es índice de los ADP (188 ADP sin registro,
  15 nombres sin ADP); las duraciones del inventario salen de los ficheros.

## Modelos / objetos / mapas / animaciones / ZLB — completo

- ZLB = zlib estándar (124 romlists + 1.215 bloques, tamaño exacto).
  MODELS = FACEFEED + ZLB anidado, 3.325 slots → 829 únicos por SHA-1
  (2.496 duplicados exactos entre mapas) → 829/829 OBJ. Bloques:
  1.215/1.215 OBJ + 1.215 CSV de colisión. Total OBJ: 1.319.431 caras,
  769.118 vértices.
- Objetos: 1.477 definiciones; OBJINDEX 2.192 filas; DLLs 471 filas
  (468 con nombre wiki, 449 usadas); mapas 117; animaciones 54
  contenedores (ANIM: 610 flagged, 609 reales + 1 stub anómalo id 2462,
  como la wiki; PREANIM 396); MODANIM/AMAP 1.264 slots cada uno;
  MODELIND 1.888; VOXMAP 2.944 OK, 0 fallos.
- Desviación honesta: la referencia 2.285 modelos→OBJ no coincide con
  ningún conteo reproducible; queda documentada sin inventar equivalencia.
- Limitaciones: OBJ en pose bind sin skinning; sin MTL/texturas enlazadas
  (TEX0/TEX1 fuera de esta extracción); yOffset de bloque no aplicado
  (hipótesis documentada: desplazamiento de colocación); tipo de
  superficie de colisión inferido por orden de `firstPolygon`;
  `DLLS.bin` ausente en esta extracción (solo nombres wiki + uso);
  `OBJECTS.bin2` difiere ~47 % de `OBJECTS.bin` (nota cruda, sin linaje
  afirmado); ANIMCURV, OBJHITS/OBJEVENT/OBJSEQ2C y gramática AMAP quedan
  en bruto/inventario, no decodificados.
