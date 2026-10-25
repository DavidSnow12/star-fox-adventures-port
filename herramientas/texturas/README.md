# Extractor de texturas de Star Fox Adventures

`extract_textures.py` extrae los bancos de texturas del disco
(TEX0/TEX1 por mapa y TEXPRE compartido) y los decodifica a PNG.
Solo lee el disco; nunca lo modifica. No sube nada a Drive/GitHub
ni construye APK.

## Uso

```bash
python extract_textures.py [--disc DIR] [--out DIR] [--inventory CSV] \
    [--maps all|mapa1,mapa2] [--no-screens] [--no-raw] [--no-numpy] \
    [--max-frames N]
```

Sin argumentos, las rutas se resuelven respecto al script:

- disco: `<proyecto>/disc/files`
- salida: `<proyecto>/assets/extraidos/texturas`
- inventario: `<proyecto>/assets/inventarios/texturas.csv`

Requisitos: Python 3.8+, Pillow. numpy opcional (muy recomendable;
sin numpy usa el decodificador Python puro, con los mismos
resultados pero mucho más lento).

## Salida

- `<origen>/<BANCO>_<id:04d>_f<fotograma>.png`: nivel base de
  cada fotograma. `<origen>` es `root` o el nombre del mapa.
  Los PNG se emiten tal como están almacenados (sin voltear).
- `<origen>/<BANCO>_<id:04d>_f<fotograma>_secondary.png`:
  imagen secundaria I4, cuando el blob la trae (campo 0x50 != 0).
- `screens/screens_<n>.png`: las dos imágenes de SCREENS.bin
  (formato supuesto: RGB5A3 embaldosado 4x4; ver RESUMEN.md).
- `raw/<fichero>`: copias en bruto de los ficheros inspeccionados
  que no son texturas GX decodificables (FONTS.bin, SPRITES.*,
  SPRTABLE.bin, CACHEFONTSTEX.bin) y de cualquier blob TEX que no
  se pueda decodificar (en este disco: ninguno).
- Inventario CSV con columnas: `fuente, tamano_fuente, sha1_fuente,
  salida, tamano_salida, sha1_salida, formato, dimensiones`.
  Para texturas TEX, `fuente` es `<origen>/<BANCO>.bin#id=<id>
  frame=<f>` y tamaño/SHA-1 son los del blob de textura
  descomprimido (cabecera 0x60 + datos, con mipmaps y secundaria
  incluidos); para una secundaria, son los de su rebanada I4.
  Para SCREENS, son los del registro completo (cabecera 16 +
  píxeles). Para ficheros en bruto, son los del fichero entero.

## Formatos

Decodificados: I4, I8, IA4, IA8, RGB565, RGB5A3, RGBA8, CMPR
(DXT1 con índices MSB-primero y subbloques en orden fila-mayor).
No decodificados: C4/C8/C14X2 (paleta; no hay TLUT en el blob, y
además no aparecen en este disco: 0 casos en 19.264 fotogramas).

Los mipmaps no se emiten como PNG separados: solo se emite el
nivel base. Las texturas se cuentan por fotograma y por origen
(sin deduplicar entre mapas: la misma textura copiada en varios
mapas produce un PNG por mapa, como en el disco).

Los detalles, conteos y decisiones dudosas están en
`../../extraidos/texturas/RESUMEN.md`.
