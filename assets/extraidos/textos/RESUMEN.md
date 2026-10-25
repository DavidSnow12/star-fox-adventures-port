# Textos de Star Fox Adventures — RESUMEN

Juego: Star Fox Adventures, GameCube, **GSAP01 Rev 1 PAL** (En/Fr/De/Es/It).
Fuente: árbol del disco en `disc/files/` (solo lectura; no se modificó nada:
los ficheros del disco conservan su fecha 2026-10-11 y su SHA-1).
Extractor: `assets/herramientas/textos/extraer_textos.py`
(por argv, sin rutas absolutas hardcodeadas). Regeneración:

```
python3 assets/herramientas/textos/extraer_textos.py disc/files \
    assets/extraidos/textos assets/inventarios/textos.csv
```

## Formato probado (verificado en los 1020 ficheros, no solo en la wiki)

La wiki de SFA-Decomp (`Gametext.md`) describe el struct C con un puntero
`phrases`; **en disco el registro es distinto** y así lo implementa el
extractor (la diferencia se confirmó además contra los `.c.new` de `Boot`,
que listan los mismos IDs, `numPhrases` y `window`):

```
u32be  num_glifos
characterStruct[num_glifos]   ; 16 bytes: u32 codepoint, u16 x, u16 y,
                              ;   s8 left/right/top/bottom,
                              ;   u8 width, height, font, texture
u16be  num_textos
u16be  long_bloque_cadenas
registro[num_textos]          ; 12 bytes: u16 id, u16 num_frases,
                              ;   u8 window, u8 align_h, u8 align_v,
                              ;   u8 idioma, u32 indice_primera_frase
u32be  num_cadenas            ; == suma de num_frases (verificado)
u32be  offsets[num_cadenas]   ; relativos al bloque de cadenas
bytes  cadenas[long_bloque_cadenas]
u32be  long_bloque_desconocido ; bloque entero de bytes 0xEE
bytes  bloque_desconocido
fontTextures[]                ; termina en cabecera 0,0,0,0 + 4 bytes 0
```

Cadenas:

- **UTF-8 directo** (no hay codificación propia que transcodificar: `á`,
  `ñ`, `¡`, `¿` ya son UTF-8 en disco; la tabla de glifos usa codepoints
  UCS4 y contiene esos mismos caracteres).
- El final de cada cadena **no** se busca por NUL: se recorta por la tabla
  de offsets (siguiente offset, o fin del bloque). La cadena termina en
  el primer NUL a nivel de texto, como hace el juego; el resto de la
  rebanada es relleno y se ignora.
- **Códigos de control**: un carácter PUA en UTF-8 seguido de N parámetros
  `u16be` (los parámetros pueden contener bytes 0x00, por eso un `rstrip`
  de NULes rompería frases que terminan en un control — se detectó y se
  corrigió durante la verificación: 32 frases francesas de `Sequences`
  que terminan en `E018` con parámetros 0 se perdían con ese método).
  En el JSON se conservan como tokens legibles sin pérdida, p. ej.
  `<E020:0>`, `<E018:0,3,0>`, `<F8FF:171,253,253,255>`,
  `<F8F7:2>A<F8F7:4>` (icono de botón A: fuente 2, luego vuelta a fuente 4).
  Tabla de parámetros: E000:1, E018:3, E020:1, F8F2:2, F8F3:0, F8F4:1,
  F8F5:1, F8F6:1, F8F7:1, F8F8:0, F8F9:0, F8FA:0, F8FB:0, F8FC:0, F8FD:0,
  F8FE:0, F8FF:4 (wiki + tabla `lbl_802C86F0` del decomp).
- Las **frases vacías (`""`) se conservan**: son 7.105 en total y son
  datos reales (separadores / huecos, p. ej. `Boot` id 825 frase 2),
  no errores de extracción.
- Las texturas de fuente **no se decodifican a imagen** en esta entrega
  (eso es trabajo de texturas, no de textos); sí se recorren y validan
  con la fórmula de la wiki (`(((w*h*pixFmt)>>4)*2)+4`) en los 1020
  ficheros: todas terminan en el terminador esperado.

## Conteos reales por idioma

«Textos» = entradas (un mismo ID aparece en muchos directorios: 73
directorios por idioma — 72 de mapa/menú + `Sequences` con 132 ficheros
`N_<idioma>.bin`); «IDs únicos» = IDs distintos. La diferencia entre
textos (5.265+) e IDs únicos (~1.125) es, por tanto, esperada.

| Idioma | Archivos | Textos | Frases | IDs únicos | Frases con control | Frases no ASCII | JSON (bytes) | SHA-1 del JSON |
|---|---|---|---|---|---|---|---|---|
| English | 204 | 5.268 | 12.084 | 1.125 | 1.826 | 144 | 1.829.466 | `2e48918e153c853e19e9cc003be8e50abe342641` |
| French | 204 | 5.270 | 13.038 | 1.127 | 1.896 | 5.621 | 1.940.072 | `00e3b3762bb7d02dee547e23bfd72ae0b91b3c79` |
| German | 204 | 5.267 | 12.018 | 1.125 | 1.838 | 3.564 | 1.878.881 | `9d31e1d18e3ecc4a3b91c338e44b59998c5fd500` |
| Italian | 204 | 5.268 | 13.329 | 1.125 | 1.864 | 2.416 | 1.904.852 | `be0c74345a183fc0a3cf91dff0415d1d9462ddfd` |
| Spanish | 204 | 5.265 | 12.097 | 1.123 | 1.866 | 4.749 | 1.892.060 | `aa6266bc2e2d9216b85a3ffd6e9e1e79c8678026` |
| **Total** | **1.020** | **26.338** | **62.566** | — | **9.290** | — | — | — |

## Comparación con la referencia 2026-10-11

La referencia (26.338 textos / 62.566 frases) **coincide exactamente**
con esta extracción, sin desviación que investigar. Las diferencias
entre idiomas son reales y explicables, no errores:

- El número de **frases por idioma difiere** (alemán 12.018 frente a
  italiano 13.329) porque una misma entrada `(directorio, id)` se divide
  en distinto número de frases según la traducción: 1.416 entradas
  difieren entre español e italiano y 359 entre español y alemán
  (p. ej. `Animtest` id 512: 9 frases en español, 8 en italiano).
- El número de **textos difiere ligeramente** (5.265–5.270) porque algún
  directorio trae una entrada más o menos según el idioma.
- Los códigos de control observados en todo el corpus (15.283 en total,
  recuento independiente desde el disco crudo = recuento en los JSON):
  F8F4: 510, F8F7: 4.030, F8FF: 4.669, E018: 4.149, F8FA: 5, E020: 1.250,
  F8F8: 30, F8F9: 30, E000: 610. No aparece ningún código PUA fuera de
  la tabla conocida.

## Verificación del español (específica)

- Glifos no ASCII de la tabla de fuentes española (unión de los 204
  ficheros): ¡ © ¿ Á É Í Ñ Ó Ú ß á ä ç è é í ñ ó ö ú ü.
- Frases españolas con algún carácter no ASCII: 4.749; con ñ/Ñ: 393;
  con ¡: 372; con ¿: 473. Todo decodificado como Unicode real, no como
  escapes ni como bytes sueltos (verificable abriendo
  `textos_Spanish.json` en UTF-8).
- Ejemplos reales extraídos del JSON definitivo (no del disco crudo):
  - `[Animtest/Arwing id 809]` «La Memory Card (tarjeta de memoria) de
    la Ranura A está dañada y no se puede utilizar.»
  - `[Animtest id 1175]` «La partida de Star Fox Adventures guardada en
    la Memory Card (tarjeta de memoria) de la Ranura A está dañada.
    Tienes que borrarla para poder continuar.»
  - `[Animtest id 818]` «El archivo guardado estaba dañado y ha sido
    borrado.»
  - `[FrontEnd id 262]` «¡Eh, Fox! ¡No dejes que se escapen! Intenta
    embestirles para detenerles... Aunque lo único que tienes que hacer
    es alcanzar a Tricky antes que ellos. Presta atención al trazado del
    camino y ten cuidado con las minas que suelten. ¡Buena suerte!»
  - `[FrontEnd id 267]` «¡Venga, Fox! ¡No he visto tipo más despistado
    en toda mi vida! Es muy fácil: sólo tienes que abrir la reja con
    el Bastón.»
  - `[Animtest id 512]` «¿Quieres guardar la partida?»
  - `[Link]` «Bastón», «Señuelo», «¡Quieto!», «Disparar Cañón»,
    «Liberar Espíritu».
  - `[Boot id 825]` «Se ha producido un error.» / «» / «Apaga la
    consola y consulta el manual de instrucciones de NINTENDO GAMECUBE
    para obtener más información.»
  - `[Boot id 830]` «Éste no es el disco de» / «Star Fox Adventures.» /
    «» / «Coloca el disco de» / «Star Fox Adventures.»
  - `[Sequences id 4]` «`<E000:209>`», «`<E018:0,0,0> `»,
    «`<E018:0,3,0><F8FF:171,253,253,255>¡Ésa es mi mami!`»,
    «`<E018:0,5,0> `» (secuencia con tiempos y color, intactos).
  - `[Animtest id 1171]` «Pulsa `<F8F7:2>A<F8F7:4>`» (icono botón A).
- El `idioma_codigo` de todos los registros coincide con el idioma del
  fichero (español = 5, orden de `sLanguageNameTable[]`); 0 discrepancias.

## Qué quedó sin parsear y por qué

- **`GAMETEXT.bin` / `GAMETEXT.tab`** (raíz del disco, 69.376 y 20.672 B):
  versiones antiguas sin uso; la wiki indica formato desconocido y
  diálogo antiguo ausente del juego final. No se intentó adivinar el
  formato: copias byte a byte en `brutos/` (SHA-1 idéntico al original).
- **`TEXTABLE.bin`** (raíz, 6.496 B): **no es texto** pese al nombre.
  Es la tabla `u16` de remapeo de IDs de textura
  (`docs/wiki/Textures.md`, `texture.c`: `TEXTABLE[id]`). Copia en
  `brutos/`; el extractor de texturas, no este, debe usarla.
- **`gametext/Boot/*.c.new`** (5 ficheros): artefactos de generación en
  C (structs + cadenas como literales), no datos del juego. No se
  emiten como salida; solo se usaron como comprobación cruzada de
  `Boot` (IDs, `numPhrases`, `window` coinciden con el binario).
- **Texturas de fuente** de los `.bin`: recorridas y validadas, no
  convertidas a imagen (fuera del alcance «textos»).
- **Nada más**: los 1.020 `gametext/*.bin` parsean completos. No hay
  ficheros gametext en `brutos/` por fallo; `brutos/` contiene solo
  los 3 ficheros legacy anteriores.

## Fallos: ninguno

- Fallos de archivo: **0 / 1.020** (estructura, offsets, bloque `0xEE`,
  recorrido de texturas y decodificación validados en todos).
- Fallos de frase: **0 / 62.566** (0 frases `null` en los JSON;
  relectura independiente de los JSON reproduce los conteos de cabecera).
- Códigos PUA desconocidos: **0**. Bytes no NUL tras un terminador
  dentro de una rebanada: **0** (todo el resto es relleno NUL).
- Inventario: `assets/inventarios/textos.csv`, 1.023 filas + cabecera
  (1.020 gametext + 3 legacy), columnas: fuente, tamaño, SHA-1 fuente,
  salida, tamaño, SHA-1 salida, idioma, nº cadenas, nota. Los SHA-1 se
  recomputaron de forma independiente para muestras de cada tipo y
  coinciden (p. ej. `gametext/Boot/Spanish.bin`:
  `506e091e7719c10eb199564bc5f63a9df52c5540`).
- `resumen.json` (en esta misma carpeta) es el resumen máquina con los
  mismos conteos, los SHA-1 de los JSON y la lista de legacy.

## Estructura de cada JSON por idioma

```json
{
  "juego": "Star Fox Adventures",
  "version": "GSAP01 Rev 1 PAL (En/Fr/De/Es/It)",
  "idioma": "Spanish", "idioma_codigo": 5,
  "total_archivos": 204, "total_textos": 5265, "total_frases": 12097,
  "ids_unicos": 1123, "frases_con_control": 1866, "frases_no_ascii": 4749,
  "glifos_no_ascii_union": [{"codepoint": 241, "char": "ñ"}],
  "archivos": [{"fuente": "gametext/Boot/Spanish.bin", "tamano": 6944,
                "sha1": "506e...", "num_textos": 7, "num_cadenas": 19}],
  "textos": [{"id": 825, "fuente": "gametext/Boot/Spanish.bin",
              "directorio": "Boot", "num_frases": 3, "window": 129,
              "align_h": 0, "align_v": 0, "idioma_codigo": 5,
              "indice_primera_frase": 0,
              "frases": ["Se ha producido un error.", "", "..."]}]
}
```
