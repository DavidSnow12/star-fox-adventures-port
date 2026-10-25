# Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL) — Modelos / Objetos / Mapas / Animaciones / ZLB

Extracción desde cero a partir del árbol del disco en
`~/workspace/starfoxadventures/disc/files/` (solo lectura; no se ha modificado
nada del disco, no se ha subido nada a Drive/GitHub y no se ha construido ningún
APK). Herramientas en
`~/workspace/starfoxadventures/assets/herramientas/modelos/` (Python, argv, sin
rutas absolutas hardcodeadas). Fecha de la extracción: 2026-10-25.

## Formatos probados (verificación empírica, no solo wiki)

| Formato | Resultado |
|---|---|
| `.zlb` (romlists y bloques de mapa) | **zlib estándar.** Cabecera `ZLB\0`, u32 versión=1, u32 tamaño descomprimido, u32 tamaño comprimido, y a continuación un stream zlib. `zlib.decompress` reproduce exactamente el tamaño declarado en los 124 romlists y en los 1.215 bloques. El decodificador DEFLATE manual del juego (que salta los 2 bytes de cabecera zlib) es equivalente. |
| `MODELS.bin` (modelos de personaje/objeto) | **FACEFEED + ZLB anidado.** Los 3.325 registros son `FACEFEED` con un ZLB interior (desplazamiento deducido de `aux`: se prueban `(aux-3)*4`, `aux+0x18`, `aux+0x28`, `0x24`, `0x10+aux` y solo se acepta el candidato que cae sobre una magia conocida y descomprime al tamaño declarado). 0 fallos. |
| Bloques de mapa (`modXX.zlb.bin`) | **ZLB directo.** Los 1.215 bloques son ZLB sin envoltura FACEFEED. 0 fallos. |
| Envolturas DIR / E0 | Soportadas por el código (`sfa_common.parse_wrapper`), pero **no apareció ningún registro DIR ni E0** en los contenedores procesados (MODELS + mod). |
| F0 / LZO | **No encontrado y no soportado.** La wiki indica que no hay ficheros LZO en el disco retail; el extractor lo rechaza explícitamente. Como `fallos.csv` está vacío, ningún registro procesado era F0. |
| Tablas `.tab` con byte alto de flags | Verificado: el valor 0 no es "ausente" cuando lleva flags (p. ej. `0x10000000` = offset 0 real). Regla: raw 0 = ausente, `0xFFFFFFFF` = terminador, valor igual al tamaño del `.bin` = centinela final (se descarta). Los candidatos de offset se prueban en orden: 24 bits bajos, 28 bits bajos, valor crudo. |
| Modelos GX → OBJ | Verificado en los 829 modelos únicos (ver abajo). Tristrips/triángulos/trifans/quads indexados, atributos en orden GX (POS, NRM/NBT, CLR0, TEX por capa), índices de 1 o 2 bytes big-endian según el bit VAT del stream, escalas VAT de la tabla `GXSetVtxAttrFmt` del juego (VAT5 POS/8 TEX/256, VAT6 POS/256 TEX/1024, etc., por primitiva, no por tipo de modelo). Normales s8/64 (registros NBT de 9 bytes: primer triplete). `v` de textura invertida (GX crece hacia abajo). |

## Conteos reales (esta extracción)

### Romlists (`.romlist.zlb`)

- **124 ficheros, 124 descomprimidos, 0 fallos.** Total descomprimido: 934.344 B.
- **20.568 entradas** de romlist parseadas (`romlists.csv`), con tipo, tamaño en
  palabras de 4 bytes, flags, posición y id único (`romlists_resumen.csv`).
- Salida: `romlists/*.bin` (uno por fichero, mismo nombre sin `.zlb`).

### Modelos (`MODELS.bin` + `MODELS.tab`, raíz + 52 directorios de nivel)

- Slots reales procesados: **3.325** (raíz 150 + por mapa 3.175). Ojo: un conteo
  ingenuo de la `.tab` da 3.378 porque cuenta como válidos los 53 centinelas
  "valor == tamaño del .bin" (uno por contenedor); esos no son modelos.
- Payloads únicos por SHA-1 del descomprimido: **829**. Slots duplicados
  (mismo modelo servido en varios mapas): **2.496**.
- OBJ generados: **829/829 (100 % de los únicos), 0 fallos.**
- Caras OBJ totales (modelos + bloques): **1.319.431**; vértices OBJ totales:
  **769.118**.
- Salida: `modelos_descomprimidos/modelo_<sha1>.bin` +
  `modelos_obj/modelo_<sha1>.obj` + sidecar `.json` (huesos, hitspheres,
  shaders, estadísticas por dlist, conteo direct usado).
- Correspondencia slot → payload único: `modelos_fuentes.csv` (4.540 filas:
  3.325 modelos + 1.215 bloques).

### Bloques de mapa (`modXX.zlb.bin` + `modXX.tab`, 52 ficheros)

- Slots procesados: **1.215**, todos payloads únicos (cada bloque de mapa es
  geometría distinta), OBJ generados: **1.215/1.215, 0 fallos.**
- Salida: `bloques_descomprimidos/bloque_<sha1>.bin` +
  `bloques_obj/bloque_<sha1>.obj` + sidecar `.json` + colisión
  `bloques_colision/bloque_<sha1>.csv` (triángulos GCpolygon en crudo s16 y
  en escala /8, más grupos de polígonos).
- Los 52 `modXX.zlb.bin` son uno por directorio de nivel. Hay `.tab` huérfanos
  en algunos directorios (p. ej. `crfort/mod12.tab`, `dragrock/mod10.tab`,
  `mod29.tab`, `volcano/mod8.tab`, `warlock/mod16.tab`, `worldmap/mod3.tab`,
  `shipbattle/mod30.tab`, `mmshrine/mod32.tab`, `dragrockbot/mod29.tab`) sin
  `.zlb.bin` correspondiente en ese directorio: se ignoran como bloques, no se
  tratan como geometría.

### Objetos / índices / DLLs / mapas / animaciones / VOXMAP

Inventarios en `~/workspace/starfoxadventures/assets/inventarios/`:

| Fichero | Contenido |
|---|---|
| `objetos.csv` | **1.477** definiciones de `OBJECTS.bin` (nombre, dll_id, clase, nº de modelos/secuencias/puntos de anclaje/texturas, escala, ids de modelo y de secuencia). `dll_id` u16 con columna gemela s16 (`-1` = sin DLL). |
| `objindex.csv` | **2.192** filas de `OBJINDEX.bin` (traducción id de romlist → id de objeto). |
| `dlls.csv` | **471** filas de la tabla wiki de DLLs (468 con nombre, 3 sin nombre), cruzadas con uso real: **449** DLLs usadas por ≥1 objeto. Ver `dlls_nota.json`: `DLLS.bin` **no existe** en esta extracción del disco (solo `DLLS.tab` de 32 B), así que el código DLL no se inventaría desde el disco; solo nombres wiki + uso. |
| `mapas.csv` | **117** mapas (IDs 0x00–0x74), con nombre MAPINFO, tipo, romlist y directorio de la wiki `MapList.md` (unión 117/117), rejilla de bloques y distribución de `mod`. |
| `animaciones.csv` | **2.597** registros del `ANIM.BIN` raíz parseados por registro (flag "holds real" = bit `0x10000000` de la tab, tamaño, stub o no, frameControl, offsets de stream/curva, nº de joints, nº de frames, stride). |
| `animaciones_resumen.csv` | **54** contenedores (raíz ANIM + raíz PREANIM + 52 ANIM por mapa). Raíz ANIM: 610 flagged, de los cuales **1 es stub** (id 2462, la anomalía que la wiki documenta) → **609 reales no-stub**, coincidiendo con la wiki. Raíz PREANIM: 396 flagged, 0 stub-flagged. Total flagged en los 54 contenedores: **12.431**. |
| `modanim.csv` | **1.264** slots (offsets u16 a `MODANIM.BIN`, valores s16 separados por centinelas -1 en runtime; no se re-deriva gramática más allá). |
| `amap.csv` | **1.264** slots (offsets u32 a `AMAP.BIN`, primeros bytes; la gramática de registro **no** se re-deriva: queda como inventario, no como decodificación). |
| `modelind.csv` | **1.888** entradas s16 de `MODELIND.bin` (1 negativa, 629 ceros — los ceros se reportan como mapeo al slot 0, no como modelos distintos —, máx. 1.258). Las copias de raíz y de `swaphol` son SHA-1 idénticas. |
| `voxmap_root.csv` + `voxmap_resumen.csv` | VOXMAP raíz (1.600 entradas: 44 ok, 620 ausentes, 935 centinelas de fin, 1 terminador, 0 fallos) + 52 por mapa. **Total ok: 2.944** (raíz 44 + por mapa 2.900), 0 fallos en ningún contenedor. La cifra 2.944 de la wiki coincide con el total incluyendo la raíz, no con el subtotal por mapa (2.900). Los `min_y`/`max_y` candidatos son s16 en +0x04/+0x0C del payload descomprimido, con la cautela de la wiki (la rejilla de rutas VOXMAP no se re-decodifica aquí). |
| `objects_bin2_nota.json` | `OBJECTS.bin2` (301.952 B, 256 B más que `OBJECTS.bin`) difiere en ~47 % del rango común: **no** es una variante menor; queda solo como nota cruda, sin afirmación de linaje. |
| `modelos.csv` | **5.440** filas: 124 romlists + 829 modelos descomprimidos + 829 modelos OBJ + 1.215 bloques descomprimidos + 1.215 bloques OBJ + 1.215 CSV de colisión + 13 inventarios. Columnas: `fuente, tamano_fuente, sha1_fuente, salida, tamano_salida, sha1_salida, tipo`. Las rutas de salida son relativas a `~/workspace/starfoxadventures/assets/`. Verificación: 0 salidas ausentes; muestra aleatoria de 30/30 con tamaño y SHA-1 recomputados correctos. |

No inventariados como geometría (fuera del alcance o sin formato verificable):
`OBJHITS.bin` (27.584 B, sin tab), `OBJEVENT.bin` (9.568 B), `OBJSEQ2C.tab`,
`ANIMCURV.bin/.tab` (curvas: formato no pedido en la wiki de referencia, no
decodificado), `VOXOBJ.bin` (0 B, tab de 32 B: vacío), texturas `TEX0/TEX1`
(los OBJ no llevan MTL ni texturas enlazadas: la extracción de texturas es
otra familia de trabajo).

## Desviación frente a la referencia 2026-10-11 (2.285 modelos → OBJ)

La referencia no coincide con ningún conteo reproducible de esta extracción:

- Slots de modelo reales: **3.325**.
- Modelos únicos (SHA-1 del descomprimido): **829**.
- OBJ de modelo generados: **829**.
- Modelos + bloques únicos juntos: **2.044** (829 + 1.215), todavía 241 por
  debajo de 2.285.

Explicación parcial verificada: gran parte de la diferencia es duplicación
entre mapas (2.496 de los 3.325 slots son copias exactas de un modelo ya
presente en otro contenedor) y el conteo ingenuo de `.tab` (3.378) incluye 53
centinelas que no son modelos. El resto de la discrepancia con 2.285 **queda
sin explicar con los datos disponibles**: la referencia de 2026-10-11 no
conserva su criterio de conteo (por slot sin deduplicar, por mapa, u otro
alcance), así que no se inventa una equivalencia. Los conteos de esta
extracción son reproducibles con `run_all.py` y `modelos_fuentes.csv`.

## Advertencias honestas sobre los OBJ

1. **Pose bind, sin skinning.** Las matrices de hueso no se aplican; los
   índices de matriz direct se ignoran. Los huesos (0x1C) y hitspheres van en
   el sidecar JSON, no deforman el OBJ.
2. **Conteo direct (atributos GX directos) y su resolución.** El nº de bytes
   directos por vértice no está en la display list: lo fija el descriptor GX
   en runtime. El parser prueba 0..6 y solo acepta conteos que parsean la
   lista completa con todos los índices en rango. En 56 display lists de
   modelo, varios conteos pasaban, y se comprobó que **dan caras distintas**:
   elegir a ciegas habría sido arbitrario. Se resolvieron con dos reglas
   verificadas, en este orden: (a) fórmula retail de
   `modelRenderFn_setVtxDescr` (jointCount ≤ 1 → 0; si no,
   {1+texMtx, 1+texMtx+1, 1+texMtx+3}); (b) el direct más común entre las
   display lists no ambiguas del mismo modelo. Resultado: 53 resueltas por
   (a), 3 por (b), **0 sin resolver**, y — validación posterior — la
   resolución coincide con el "menor conteo que pasa" en las 56, así que
   ningún OBJ cambió al aplicar el tiebreak, pero ahora la elección está
   justificada y registrada (`direct_tiebreak` en cada sidecar). En bloques,
   244 tienen ambigüedad, pero el descriptor retail de bloques solo fija
   POS/CLR/TEX indexados (ningún atributo direct), y 0 pasa siempre en los
   11.072 dlists de bloque: la ambigüedad de bloques es inocua.
3. **Bloques: yOffset no aplicado.** La cabecera de bloque trae yMin/yMax/
   yOffset (p. ej. mod13.0: -751 en los tres) mientras la bbox de la display
   list y la del grupo de polígonos coinciden con los vértices crudos sin
   desplazar. Hipótesis registrada: yOffset es un desplazamiento de
   colocación en el mundo aplicado por el cargador del mapa, no geometría
   local del bloque. Los OBJ de bloque son coordenadas locales y el sidecar
   reporta yMin/yMax/yOffset crudos. No se ha verificado en un bloque
   no degenerado con yOffset distinto de yMin/yMax.
4. **Colisión: tipo de superficie inferido.** El grupo de polígonos no trae
   tamaño explícito; se ordenan los grupos por `firstPolygon` y el tipo de
   superficie se toma del byte en +0x11 del registro. Es una inferencia,
   marcada como tal en el código y en los CSV de colisión.
5. **Winding y ejes.** Tristrips con alternancia par/impar estándar, sin flip
   de winding ni intercambio de ejes; solo `v` de textura invertida. No se ha
   comparado contra renderizado de referencia (no hay renderer en este
   entorno).
6. **Sin texturas ni materiales.** Los OBJ referencian índices de textura
   (`vt`) pero no hay MTL ni PNG/DDS: `TEX0/TEX1` quedan fuera de esta
   extracción.

## Fallos

`fallos.csv` está vacío (solo cabecera): **0 fallos** en romlists (124/124),
modelos (829/829 únicos), bloques (1.215/1.215) y tablas (VOXMAP 0 fallos en
53 contenedores, animaciones sin offsets fuera de rango en la raíz). Los
directorios no de nivel (`BOSSAndross`, `Boot`, `Communicator`, `GameMaze`,
`Sequences`, `audio`, `card`, `gametext`, `modules`, `musyxbin`, `savegame`,
`streams`, etc.) no contienen MODELS/VOXMAP/ANIM/mod y no se procesan como
niveles; sus contenidos (textos, audio, iconos de tarjeta) pertenecen a otras
familias de extracción.

## Tamaños de salida

Total en `extraidos/modelos/`: ~142 MB. Desglose: `romlists/` 0,9 MB,
`modelos_descomprimidos/` 7,7 MB, `modelos_obj/` 25 MB (OBJ + sidecars JSON),
`bloques_descomprimidos/` 24 MB, `bloques_obj/` 48 MB (OBJ + sidecars),
`bloques_colision/` 25 MB, resto (CSV/JSON de la corrida) < 1 MB.

## Cómo reproducir

```bash
python3 ~/workspace/starfoxadventures/assets/herramientas/modelos/run_all.py \
  ~/workspace/starfoxadventures/disc/files \
  ~/workspace/starfoxadventures/assets/extraidos/modelos \
  ~/workspace/starfoxadventures/assets/inventarios \
  --wiki-dir ~/workspace/starfoxadventures/work-recomp/SFA-Decomp/docs/wiki
```

Extractores individuales: `zlb_extract.py <entrada> <salida> [--tab TAB]
[--flagged]`, `parse_models.py <modelo.bin> <modelo.obj> [--json sidecar]`,
`parse_blocks.py <bloque.bin> <bloque.obj> [--json sidecar] [--collision csv]
[--block-name NOMBRE]`, `parse_tables.py <dir_disc> <dir_inventarios>
[--wiki-dir DIR]`. Todos leen el disco solo en lectura.
