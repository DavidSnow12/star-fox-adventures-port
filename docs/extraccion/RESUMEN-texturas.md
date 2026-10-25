# Resumen — Texturas de Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL)

Fecha del run: 2026-10-25. Disco de trabajo (solo lectura):
`./disc/files/` (no se modificó nada
allí). Extractor:
`./assets/herramientas/texturas/extract_textures.py`
(con su `README.md`). Inventario:
`./assets/inventarios/texturas.csv`.

## Método (verificado contra el disco, no solo contra la wiki)

- Bancos: `TEXPRE` compartido en la raíz + `TEX0`/`TEX1` en la
  raíz y en 52 directorios de mapa = 107 pares `.tab`/`.bin`.
- Cada `.tab` es una lista de u32 big-endian hasta `0xFFFFFFFF`.
  Entrada presente = bit `0x80000000`; campo de 6 bits en 24..29
  = número de fotogramas; 24 bits bajos = desplazamiento / 2.
  Entrada ausente típica: `0x01000000`. La palabra anterior al
  terminador es `tamaño_del_.bin / 2` (centinela de fin, no una
  textura) y se ignora por no tener el bit de presente.
- `count == 1`: registro directo. `count > 1`: tabla de `count+1`
  desplazamientos relativos, los `count` primeros son fotogramas
  y el último es el tamaño total. Se comprobó que los fotogramas
  de un mismo id tienen las mismas dimensiones y formato (son
  fotogramas de animación, no mipmaps entre sí).
- Registro `ZLB`: cabecera de 16 bytes + zlib estándar.
  Registro `DIR` (`DIRn`, solo en TEX1/TEXPRE): cabecera de 16
  bytes + 16 bytes de prefijo + blob de textura; el campo de
  tamaño de la cabecera DIR es la longitud del blob (el cargador
  salta 32 bytes desde el inicio del registro, y este extractor
  hace lo mismo).
- Un blob puede empezar a su vez por `ZLB`/`DIR`: es el caso de
  `TEXPRE[0]`, doblemente empaquetado (DIR que contiene un ZLB).
  Sin esa recursión, ese fotograma quedaría sin decodificar.
- Blob de textura: cabecera de `0x60` bytes (ancho u16 BE en
  `0x0A`, alto en `0x0C`, formato GX en `0x16`, desplazamiento
  de la imagen secundaria en `0x50`) + datos de imagen.
- Ajuste de tamaño (comprobado en los 19.264 fotogramas, 0 sin
  ajustar): los datos son el nivel base, más su cadena de
  mipmaps si la hay, más una imagen secundaria I4 si el campo
  `0x50` es distinto de 0. Los mipmaps se identifican por suma
  de niveles (mitades enteras, acolchado a tile); la secundaria
  por `tamaño_total = tamaño_principal + tamaño_I4`, con
  `tamaño_principal == campo 0x50`.
  Solo se emite el nivel base como PNG principal; la secundaria
  se emite aparte con sufijo `_secondary`. Los mipmaps no se
  emiten como PNG separados.
- Ojo, corrección importante frente a un primer ajuste solo por
  tamaño: hay 214 fotogramas cuyo tamaño total ajusta tanto a
  "nivel base + I4" como a "cadena de mipmaps sin secundaria".
  El primer run los clasificó por tamaño y dio 1.039
  secundarias; la clasificación correcta es por el campo
  `0x50` (0 = sin secundaria; distinto de 0 = desplazamiento
  de la secundaria, que coincide con el tamaño principal en
  los 944 casos en que no es 0). Con ese criterio, las
  secundarias son 944 y las texturas con mipmaps 5.306. El run
  final usa el criterio del campo `0x50`.
- Los datos están embaldosados (tiled) según el formato GX y se
  recortan a las dimensiones de la cabecera. Los PNG se emiten
  tal como están almacenados, sin voltear (la wiki avisa de que
  muchas texturas están "al revés" y las voltea la geometría).

## Conteos reales

- Entradas presentes en las `.tab`: 9.700 (raíz: TEXPRE 191,
  TEX0 150, TEX1 210; mapas: 9.149).
- Fotogramas (un PNG principal por fotograma, sin deduplicar
  entre mapas: la misma textura copiada en varios mapas produce
  un PNG por mapa, como en el disco): **19.264**.
- PNG principales: 19.264.
- PNG de imágenes secundarias I4: 944.
- PNG de SCREENS: 2.
- **Total de PNG: 20.210.**
- Ficheros en bruto copiados: 5 (ver abajo).
- Filas del inventario CSV: 20.215 (+ cabecera).
- Fotogramas con cadena de mipmaps (solo se emite el nivel
  base): 5.306. Fotogramas con secundaria I4: 944.
- Fotogramas sin decodificar por error: 0. Errores de registro:
  0. Formatos de paleta en el corpus: 0.

## Formatos probados

| Formato GX | Código | PNG principales | Estado |
|---|---:|---:|---|
| I4 | 0 | 48 | Decodificado (tile 8x8, 2 px/byte, nibble alto primero) |
| I8 | 1 | 81 | Decodificado (tile 8x4) |
| IA4 | 2 | 28 | Decodificado (tile 8x4; intensidad nibble alto, alfa nibble bajo) |
| IA8 | 3 | 1.861 | Decodificado (tile 4x4; par (intensidad, alfa) en ese orden) |
| RGB565 | 4 | 0 | Implementado y probado con datos sintéticos (numpy ≡ Python puro); 0 casos reales en este disco |
| RGB5A3 | 5 | 11.036 | Decodificado (tile 4x4; bit alto 1 = RGB555 opaco, 0 = RGB4A3) |
| RGBA8 | 6 | 1.134 | Decodificado (tile 4x4; plano AR + plano GB) |
| C4 | 8 | 0 | No decodificable sin TLUT (la paleta no va en el blob); 0 casos reales |
| C8 | 9 | 0 | Igual que C4; 0 casos reales |
| C14X2 | 10 | 0 | Igual que C4; 0 casos reales |
| CMPR | 14 | 5.076 | Decodificado (tile 8x8 = 4 subbloques DXT1 en orden fila-mayor; índices con el primer pixel de cada fila en los 2 bits altos) |
| **Total** | | **19.264** | |

Decisiones de canal verificadas, no supuestas:

- IA8 = (intensidad, alfa): en el corpus, el segundo byte es
  255 en el 70% de las texturas (alfa opaco) y el primero casi
  nunca lo es; al revés daría un 70% de texturas blancas puras.
- IA4 = (intensidad alta, alfa baja): el nibble bajo es 15 en
  26 de 28 texturas (alfa opaco); al revés, casi ninguna textura
  sería opaca.
- CMPR con índices MSB-primero y subbloques fila-mayor: el
  gradiente medio de imagen es claramente menor que con
  índices LSB-primero o subbloques en orden columna-mayor
  (p. ej. 33,0 frente a 41,9 en una textura 512x512).
- Los decodificadores numpy y Python puro del extractor dan
  resultados byte a byte idénticos en los 7 formatos reales y
  en RGB565 sintético.

Validación visual (muestras del run de prueba de la raíz):
TEX1[5] (CMPR 512x512) es un atlas coherente de piezas del
Arwing; TEX1[449] (RGBA8 128x128) es una textura de roca lisa y
sin desorden de tiles; SCREENS_0 muestra el texto legible
"SABRE'S ADVENTURE..." (ver SCREENS abajo).

## SCREENS.bin (fuera de los bancos TEX, incluido aparte)

- `SCREENS.tab`: 2 entradas (`0`, `0x25810`) + terminador.
- Cada registro: cabecera de 16 bytes (ancho u16 BE = 320, alto
  = 240) + 153.600 bytes de píxeles (320x240x2).
- Formato exacto no documentado en la wiki. Se emite como
  **RGB5A3 embaldosado 4x4 (supuesto, marcado así en el
  inventario)**: el embaldosado es mucho más suave que el
  lineal (gradiente medio 3,6 frente a 8,8); todos los píxeles
  tienen el bit alto a 1 y las zonas negras son exactamente
  `0x8000` (bajo RGB565 serían rojo oscuro, bajo RGB5A3 son
  negro opaco); el contenido resultante es una tira compacta y
  coherente (~200x20 px centrada sobre negro), no ruido. La
  imagen 0 dice "SABRE'S ADVENTURE..." en naranja sobre negro;
  la imagen 1 es la misma tira con ligeras diferencias de
  píxeles. Son las "dos imágenes no usadas" de la wiki.

## Qué quedó en bruto y por qué

En `extraidos/texturas/raw/` (copias exactas, con su fila en el
inventario):

- `FONTS.bin` (22.432 B): 10 fuentes con nombre incrustado
  (KanjiFont, FunFont, DinoSubtitleFont1, DinoSubtitleFont2,
  SubtitleFont, DinoMediumFontIn, DinoMediumFontOut,
  CommunicatorFont, TeenyFont, LargeFont), en bloques de 2.240 B
  con el nombre en el desplazamiento +4. No es un formato GX ni
  lleva cabecera de textura; la wiki solo dice "presumiblemente
  gráficos de fuente" y el código decompilado no lo lee en esta
  revisión. No se ha inventado una decodificación de glifos.
- `SPRITES.bin` (176 B) y `SPRITES.tab` (64 B): definiciones de
  sprites, no píxeles. La `.tab` da 11 desplazamientos
  (0, 16, 32, ..., 144, 176 = fin) para registros de 16 bytes
  que describen posición/tamaño/referencias, no datos de imagen.
  No hay nada que convertir a PNG.
- `SPRTABLE.bin` (174 B): tabla casi toda a ceros (11 bytes
  distintos de cero, al final), sin cabecera GX ni píxeles.
- `CACHEFONTSTEX.bin` (0 B): fichero vacío. (Su compañero
  `CACHEFONTSTAB.bin` también está vacío, 0 B; no se copió
  porque no estaba en la lista del encargo.)
- Ningún blob TEX quedó en bruto: 0 fotogramas sin decodificar.

## Texturas embebidas en directorios de nivel

Se revisaron los directorios de mapa: cada uno contiene
`TEX0.bin/.tab` y `TEX1.bin/.tab` (ya extraídos), más
`MODELS.bin` (cabecera `FACEFEED`, geometría/modelos: sus
entradas de textura son índices a los bancos TEX, no píxeles
embebidos), `modXX.zlb.bin` (geometría de mapa comprimida con
ZLB) y los demás `.bin/.tab` de animación, objetos y mapas.
No se encontró ningún otro blob con cabecera de textura GX
embebido en esos ficheros, así que no hay PNG adicionales por
esta vía. Fuera del encargo (no extraídos, solo constatados):
`card/memcardicon*.img` (4 x 1.024 B) + `memcardicon0.pal`
(512 B), iconos de tarjeta de memoria con paleta, y
`opening*.bnr` (banners de GameCube). No se han tocado.

## Comparación con la referencia del run 2026-10-11

Referencia: 19.263 texturas → PNG. Este run: 19.264 PNG
principales. Diferencia: **+1, explicada, no maquillada**.
El fotograma extra es `TEXPRE[0]`, el placeholder doblemente
empaquetado (DIR que contiene un ZLB). Un extractor sin la
recursión DIR→ZLB lo dejaría sin decodificar y contaría
19.263. Aquí se desempaqueta y da exactamente el mismo blob
(SHA-1 `559d89c71f96b7001947dfe985f6177e0d3500c1`, 224 B, IA8
8x8) que el placeholder de `TEX0[0]`, `TEX1[0]` y `TEXPRE[1]`:
una textura blanca con 4 cuadrantes de alfa (91, 162, 85, 93).
El resto del conteo coincide fotograma a fotograma con el
sondeo independiente previo al run (9.700 entradas presentes,
19.264 fotogramas).

## Notas para la reconstrucción / port

- Los PNG conservan el canal alfa tal como está en el formato
  (RGB5A3 con alfa 3 bits, CMPR con alfa 1 bit en bloques no
  opacos, IA8/IA4 con alfa completa). No se ha premultiplicado
  nada.
- Las dimensiones son las de la cabecera, no las acolchadas a
  tile; el acolchado se recorta al emitir el PNG.
- La imagen secundaria I4 (944 casos) es una máscara/intensidad
  del mismo tamaño que la principal, emitida aparte porque su
  uso en runtime (segundo objeto GX) no está documentado con
  certeza en la wiki; no se ha fusionado con el alfa de la
  principal.
- El inventario permite regenerar o verificar cada PNG desde
  su blob de origen por SHA-1 sin releer todo el disco.
