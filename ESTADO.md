# ESTADO — Star Fox Adventures (GameCube) — rebuild desde cero

**Hilo conductor. Si no está aquí con cifra verificada, no está hecho.**

## Fase 1 — Verificación del original — COMPLETA

- Disco: 789.617.752 bytes, 3.879 ficheros. `main.dol`: 3.405.600 bytes,
  SHA-1 `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`, GSAP01 Rev 1 PAL.
- Secciones: `.init` 2.376 palabras, `.text` 716.488 palabras, total 718.864.
  Entry `0x80003140`, BSS `0x803371A0` (732.344 bytes). Sin overlays retail.
  Único `.rel`: `testmod.rel`, 569 bytes (la nota vieja decía 68; el valor
  medido es 569), módulo de prueba, fuera de la recompilación.

## Fase 2 — DolRecomp a C — COMPLETA

- DolRecomp ExpansionPak `02e27ac`, SFA-Decomp `9b4063e`,
  `symbols.map` 24.957 símbolos. 718.864 instrucciones, **0 desconocidas**,
  176 chunks, gcc **176/176 limpios**, precisión Capstone en entry + 5
  direcciones. Informe completo en `codigo/FASE2.md`.
- Desviaciones: el mapa NO renombra funciones en el C actual (chunks con/sin
  mapa byte-idénticos; el mapa solo sirve vía `generated_symbols.h`).
  SMC: 107 rangos en `codigo/generated/generated_smc.txt`.

## Fase 3 — Extracción de assets — COMPLETA

- **Textos:** 26.338 textos / 62.566 frases, exactos. JSON por idioma, español
  verificado (SHA-1 `aa6266bc2e2d9216b85a3ffd6e9e1e79c8678026`).
  Sin parsear: GAMETEXT.bin/.tab (versión antigua sin uso), TEXTABLE.bin
  (remapeo de IDs de textura, no texto).
- **Vídeo:** starfox.thp → 1.797 JPEG 512×384 + 1 WAV estéreo 32 kHz, exactos.
- **Texturas:** 19.264 fotogramas → 19.264 PNG, 0 errores; total 20.210 PNG.
  Desviación explicada: TEXPRE[0] doblemente empaquetado aporta 1 fotograma
  más que la referencia 19.263. En bruto: FONTS.bin, SPRITES, SPRTABLE,
  CACHEFONTSTEX (0 B).
- **Audio:** 958 ADP → WAV, 0 fallos (exactos); 1.472 MusyX → WAV, 0 fallos;
  20 brutos (`.pro`/`.poo`, `midi.wad`, tablas, `.sam`/`.sdi` completos).
- **Modelos:** 829 modelos únicos + 1.215 bloques = 2.044 OBJ; 124/124 romlists;
  0 fallos. Desviación honesta: la referencia 2.285 no coincide con ningún
  conteo reproducible (ni slots 3.325, ni únicos 829, ni 2.044); queda
  documentada sin inventar equivalencia. OBJ en pose bind sin skinning,
  sin MTL/texturas enlazadas.

## Fase 4 — Port APK Android — PENDIENTE (posterior, ver PLAN.md)

## Fase 5 — GitHub privado — PREPARACIÓN (sin push todavía)

- Repo: `DavidSnow12/star-fox-adventures-port`, privado, rama `main`,
  todo el proyecto excepto únicamente la imagen ISO/disco. Uso personal,
  no para distribuir. Ningún fichero supera 100 MB: no hace falta Git LFS.
- Pendiente: autorizar `gh` y verificar el push (repo privado, rama,
  ficheros). Ver `DATOS.md`.
