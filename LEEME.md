# Star Fox Adventures (GameCube) — Recompilación y paquete de traspaso

**Juego:** Star Fox Adventures, GameCube, europeo GSAP01 Rev 1 PAL (En, Fr, De, Es, It).
**Copia original:** árbol del disco extraído por el usuario (789.617.752 bytes, 3.879 ficheros).
`ejecutable/main.dol`: 3.405.600 bytes, SHA-1 `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`
(coincide con la referencia SFA-Decomp GSAP01_rev1). Entry `0x80003140`, BSS `0x803371A0`
(tamaño `0xB2CB8`).

## Qué hay en este paquete

- `codigo/` — C generado con DolRecomp (176 chunks), `generated.h` / `generated.c` /
  `generated_symbols.h`, `generated_smc.txt` (107 rangos de código automodificable),
  `symbols.map` (24.957 símbolos), el conversor `make_symbols_map.py`, el informe
  `FASE2.md` y la prueba de compilación gcc (`results.tsv`, `summary.txt`: 176/176 OK).
- `herramientas/` — extractores de assets en Python (texturas, audio, vídeo, textos,
  modelos), con argumentos; en Windows se ejecutan con `python`.
- `analisis/` — inventarios CSV con SHA-1 del disco y de cada categoría de assets.
- `ejecutable/` — `main.dol` y ficheros del sistema del disco (`boot.bin`, `bi2.bin`,
  `apploader.img`, `fst.bin`, `testmod.rel` de prueba, 569 bytes, no es código retail).
- `docs/extraccion/` — resúmenes por categoría de la extracción (con las rutas
  adaptadas a rutas relativas; el contenido técnico no se ha alterado).
- `LEEME.md` (este fichero), `PLAN.md`, `ESTADO.md`, `DATOS.md`, `EXTRACCION.md`.

## Material compañero (en la misma carpeta de Drive, no dentro de este ZIP)

Por la regla «no dejes nada», el material completo viaja como archivos compañeros
en la carpeta de Drive «Star Fox Adventures (GameCube)», indexados en `DATOS.md`:
el árbol íntegro del disco y todos los assets extraídos, en ZIP planos troceados
por bytes en partes de 380 MiB como máximo. Para rejuntar una serie en Windows:

```powershell
copy /b sfa-disco.zip.aa + sfa-disco.zip.ab + sfa-disco.zip.ac sfa-disco.zip
```

y después comprobar con 7-Zip (`7z t sfa-disco.zip`) y comparar el SHA-1 con el
anotado en `DATOS.md`. Nunca se usó `zip -s` para trocear: ese método dio
archivos corruptos en un proyecto anterior.

## Estado en una frase

Fases 1 (verificación), 2 (DolRecomp a C) y 3 (extracción completa de assets)
terminadas y verificadas. Falta la Fase 4, el port APK para Android, que queda
documentada como trabajo posterior en `PLAN.md` (no se construyó en este tramo).
El repositorio privado de GitHub `DavidSnow12/star-fox-adventures-port` (uso
personal, no para distribuir) recibe todo el proyecto excepto únicamente la
imagen ISO/disco; su subida queda pendiente de la autorización de `gh`
(ver `DATOS.md`).
