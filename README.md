# Star Fox Adventures (GameCube) — Recompilación, assets y port (en curso)

**Repositorio privado, uso personal. No es para distribuir.**

Proyecto completo de Star Fox Adventures (GameCube, europeo GSAP01 Rev 1 PAL)
a partir de la copia original del usuario, excepto únicamente la imagen
ISO/disco, que no está en este repo (el árbol del disco y el material
completo están además en la carpeta privada de Drive del usuario, ver
`DATOS.md`).

## Contenido

- `codigo/` — C generado con DolRecomp (176 chunks, 0 instrucciones
  desconocidas, gcc 176/176 limpios), `symbols.map` (24.957 símbolos),
  informe `FASE2.md` y prueba de compilación. Herramienta: DolRecomp
  ExpansionPak commit `02e27ac`; símbolos: SFA-Decomp commit `9b4063e`
  (`config/GSAP01_rev1/symbols.txt`). Los repos de esas herramientas no
  están vendorizados aquí: se referencian por commit y se clonan aparte
  para regenerar.
- `assets/extraidos/` — assets completos extraídos del disco: textos
  (26.338/62.566 frases), vídeo (1.797 JPEG + WAV), texturas
  (19.264 fotogramas → 20.210 PNG), audio (958 ADP + 1.472 MusyX → WAV),
  modelos (829 únicos + 1.215 bloques = 2.044 OBJ). Ver `EXTRACCION.md`.
- `herramientas/` — extractores en Python (con argumentos, multiplataforma).
- `analisis/` — inventarios CSV con SHA-1 del disco y de cada categoría.
- `ejecutable/` — `main.dol` (3.405.600 bytes, SHA-1
  `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`) y ficheros del sistema.
- `docs/extraccion/` — resúmenes por categoría de la extracción.
- `LEEME.md`, `PLAN.md`, `ESTADO.md`, `DATOS.md`, `EXTRACCION.md` — paquete
  de traspaso completo, orientado a Windows (PowerShell/CMD, `copy /b`,
  7-Zip).

## Estado

Fases 1 (verificación), 2 (DolRecomp a C) y 3 (extracción de assets)
terminadas y verificadas. **Pendiente: Fase 4, el port APK para Android**
(documentado en `PLAN.md`: runtime CPUState/HLE, GX → GLES/Vulkan,
DSP/MusyX, 107 rangos SMC, datos embebidos, dispatch por nombre).
Referencia a evaluar entonces: Foxhollow + Aurora (declara soporte
Android, sin APK construida antes en este proyecto).

## Regeneración

Ver `PLAN.md` (recompilación con DolRecomp y extractores con `python`).
Los inventarios en `analisis/` permiten verificar cualquier regeneración
por SHA-1.
