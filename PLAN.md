# PLAN — Star Fox Adventures: de este paquete al port APK Android

## Hecho (verificado, no hace falta rehacerlo)

1. **Verificación del original:** disco 789.617.752 bytes / 3.879 ficheros;
   `main.dol` 3.405.600 bytes, SHA-1 `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`,
   GSAP01 Rev 1, entry `0x80003140`, BSS `0x803371A0` (732.344 bytes).
2. **DolRecomp a C:** DolRecomp ExpansionPak commit `02e27ac` (2026-10-10),
   SFA-Decomp commit `9b4063e`, `symbols.map` 24.957 símbolos
   (9.505 funciones, 15.363 objetos, 89 labels). 718.864 instrucciones totales
   (716.488 en `.text`), **0 desconocidas**, 176 chunks, gcc **176/176 limpios**.
   Precisión verificada con Capstone independiente en la entry y 5 direcciones.
3. **Assets completos:** textos 26.338/62.566 frases (exactos), vídeo
   1.797 JPEG + WAV (exactos), texturas 19.264 fotogramas (+1 explicado por
   TEXPRE[0] doblemente empaquetado), audio 958 ADP + 1.472 MusyX (0 fallos),
   modelos 829 únicos + 1.215 bloques (2.044 OBJ). Detalle y limitaciones
   honestas en `EXTRACCION.md` y en `docs/extraccion/`.

## Pendiente — Fase 4: port APK Android (trabajo posterior, NO hecho aquí)

El C de `codigo/generated/chunks/` es solo la CPU. El runtime debe aportar:

1. **CPUState/HLE completo:** mapa de memoria GameCube (RAM, ARAM, registros HW),
   MMU/segmentos, excepciones, hilos, temporización, DVD, SI/EXI, MI, PI, VI, PE.
   El `cpu.c` de DolRecomp es solo un harness de pruebas, no este runtime.
   El dispatcher generado tiene límite de profundidad de llamada
   (`DOLRECOMP_C_MAX_CALL_DEPTH 24`). Punto de partida sugerido por el README
   de DolRecomp: ModernGekko-Template (no evaluado aquí).
2. **GX → GLES/Vulkan:** el DOL trae el SDK GX enlazado estáticamente; sus
   llamadas escriben en la FIFO y registros GX. Hay que emular esa interfaz
   y traducirla a GLES/Vulkan. Sin esto no hay imagen aunque la CPU funcione.
3. **DSP/audio y MusyX:** verificar qué funciones DSP/MusyX del DOL son
   alcanzables y si se reimplementan, se hace HLE o se reescriben.
4. **SMC (107 rangos, `codigo/generated/generated_smc.txt`):** decidir por
   rango: parchear el C generado, invalidar/retraducir, o emular escritura
   en memoria ejecutable. DolRecomp lo deja explícitamente en manos del port.
   Primeros rangos a auditar: `0x80003390`, `0x80003740` (en `.init`),
   `0x801F37xx`, `0x8024xxxx`, `0x8026xxxx`.
5. **Datos embebidos y memoria:** la imagen de memoria invitada debe contener
   las 8 secciones data (529.888 bytes), el BSS (732.344 bytes en
   `0x803371A0`) y los bytes de código como datos legibles (1.646 palabras
   embebidas en secciones de código, p. ej. la tabla TRK).
6. **Funciones sin nombre real en el C:** en el DolRecomp actual el mapa NO
   renombra funciones en el C (las pasadas con y sin mapa son byte-idénticas;
   el mapa solo sirve vía `generated_symbols.h`, 9.591 símbolos ejecutables).
   Para depurar/parchear por nombre hay que post-procesar los chunks con
   `symbols.map` + `generated_symbols.h`, o usar otro fork. Las direcciones
   y tamaños están todos en `symbols.map`; no falta información, falta el
   paso de integración.
7. **Sistema de objetos/DLLs, animaciones y mapas:** la lógica del juego vive
   en tablas de objetos/DLLs, animaciones, mapas y scripts del disco. Los
   assets extraídos (Fase 3) y el cargador de DLLs del juego hay que
   entenderlos antes de alimentar al motor. `testmod.rel` (569 bytes, módulo
   de prueba, no parsea como REL estándar) queda fuera; si se necesita el
   sistema REL del juego, hay que resolverlo aparte (no bloquea `main.dol`).
8. **App Android (NDK, arm64):** empaquetar el C + runtime en una app con
   entrada táctil, probar la estructura en local (compilación, firma,
   manifiesto, librerías, símbolos) y probar la ejecución en un dispositivo
   real (en este entorno no hay emulador Android). Guardar un registro de
   arranque legible en el dispositivo para diagnosticar cierres inmediatos.
9. **Referencia a evaluar entonces, no ahora:** Foxhollow, port nativo jugable
   basado en SFA-Decomp + Aurora, cuyo framework Aurora declara soporte
   Android. No se construyó ninguna APK con él en este proyecto y no se
   puede copiar su código sin verificar su licencia/autoría.

## Regeneración (Windows)

- **Recompilación:** instalar CMake 3.16+ y un compilador C11 (MSVC o MinGW;
  las builds de Windows están probadas con MSVC y MinGW según el README de
  DolRecomp). Clonar DolRecomp, construir con CMake en Release, convertir
  `symbols.txt` de SFA-Decomp (`config/GSAP01_rev1`) con
  `codigo/make_symbols_map.py` y ejecutar `dolrecomp.exe --gamecube --cpu gekko
  --map symbols.map main.dol out-map`.
- **Assets:** cada extractor en `herramientas/<categoria>/` se ejecuta con
  `python` y argumentos (`--disc`, `--out`, `--inventory` según el script);
  los inventarios en `analisis/` permiten verificar la regeneración por SHA-1.
- **GitHub (privado, uso personal, no para distribuir):** repo
  `DavidSnow12/star-fox-adventures-port`, rama `main`. Contenido: todo el
  proyecto excepto únicamente la imagen ISO/disco. Ningún fichero del
  proyecto supera los 100 MB, así que no hace falta Git LFS. La subida queda
  pendiente de autorizar `gh` en la máquina que la haga (ver `DATOS.md`).

## Checklist para quien retome

- [ ] Runtime CPUState/HLE + mapa de memoria (punto 1)
- [ ] GX → GLES/Vulkan (punto 2)
- [ ] DSP/MusyX (punto 3)
- [ ] SMC, 107 rangos (punto 4)
- [ ] Imagen de memoria con data/BSS/datos embebidos (punto 5)
- [ ] Dispatch por nombre con `generated_symbols.h` o post-procesado (punto 6)
- [ ] Cargador de objetos/DLLs/mapas con los assets de la Fase 3 (punto 7)
- [ ] APK arm64 + prueba en dispositivo real (punto 8)
- [ ] Push verificado al repo privado (ver `DATOS.md`)
