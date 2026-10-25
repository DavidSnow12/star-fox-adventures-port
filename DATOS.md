# DATOS — Star Fox Adventures: material en Drive y en GitHub

## Carpeta de Drive

Carpeta propia: «Star Fox Adventures (GameCube)» — ID de carpeta:
`1x_dKvfIlwAluN2KpQ3pEDybGiFCD-9Fe`. Todos los tamaños siguientes se
re-verificaron en Drive tras la subida.

## Paquete de traspaso (este ZIP)

| Fichero | Tamaño (bytes) | SHA-1 |
|---|---|---|
| `starfox-recomp.zip` (este ZIP, en Drive con el ID siguiente) | ver tamaño y SHA-1 definitivos en el informe de entrega y en ESTADO.md (un fichero no puede contener su propio SHA-1 exacto) | ver informe de entrega y ESTADO.md |

Contenido: LEEME/PLAN/ESTADO/DATOS/EXTRACCION.md, `codigo/` (C DolRecomp,
`symbols.map`, `FASE2.md`, prueba gcc), `herramientas/` (extractores),
`analisis/` (inventarios CSV), `ejecutable/` (`main.dol` y ficheros del
sistema), `docs/extraccion/` (resúmenes por categoría).

## Series compañeras (ZIP planos troceados por bytes, nunca `zip -s`)

Rejuntar en Windows con `copy /b` y comprobar con 7-Zip y SHA-1:

| Serie | ZIP completo (bytes) | SHA-1 rejuntado | Partes en Drive (tamaño exacto verificado) |
|---|---|---|---|
| `sfa-disco` (árbol íntegro del disco) | 547.969.309 | `aac0d1f46b18d8748c71e174b2437bbc8973b458` | `sfa-disco.zip.aa` 398.458.880 B (ID `1-RSQcUtMtwp7hTmnwHyisPSmj6XYq_mY`), `sfa-disco.zip.ab` 149.510.429 B (ID `1hqUgi-Txl1tQSVeK6Xs3oSi4LoMUTqkm`) |
| `sfa-assets` (assets extraídos completos) | 1.848.796.458 | `0bc3905898517fd761a66fe754f3625dd64492e3` | `sfa-assets.zip.aa` 398.458.880 B (ID `1sgPHYCufDenN-jTDed3v0xq76xEFMFw8`), `sfa-assets.zip.ab` 398.458.880 B (ID `1Yn-LUAtmJxyKgeOKM9Vd_q0bfFl-rAAG`), `sfa-assets.zip.ac` 398.458.880 B (ID `108ybH7xT-kB8uqWu5fKrnWt7ncYHszHu`), `sfa-assets.zip.ad` 398.458.880 B (ID `1KAdpzw__VPh18CbiRfzYgJlZ7tahrgQG`), `sfa-assets.zip.ae` 254.960.938 B (ID `1bGxU8MwomcmJB_y4VxzVj6_4Zm2y2RAu`) |

Fichero del paquete en Drive: `starfox-recomp.zip`, ID
`1_7u_jLBTc0AhnZHnxQm8JI17YXbKQrGb` (se actualiza en este mismo ID con
la versión que incluye este DATOS.md definitivo).

Cada parte mide 398.458.880 bytes como máximo (380 MiB), salvo la última
de cada serie. Los tamaños de la tabla se re-verifican en Drive tras la
subida; si una subida se corta, se verifica el listado y se re-sube solo
lo que falte.

## GitHub (privado, uso personal, no para distribuir)

- Repo: `DavidSnow12/star-fox-adventures-port`, rama `main`, privado.
- Contenido: todo el proyecto excepto únicamente la imagen ISO/disco
  (C recompilado, herramientas, inventarios, assets extraídos, docs y
  paquete). Ningún fichero supera 100 MB: no hace falta Git LFS.
- Estado: repo local preparado; push pendiente de autorizar `gh` en la
  máquina que lo haga (la sesión de navegador no equivale a sesión CLI).
  Tras el push, verificar en la web del repo: privado, rama y ficheros.
