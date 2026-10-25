# FASE 2 — DolRecomp de Star Fox Adventures (GameCube) — rebuild desde cero

**Fecha de ejecución:** 2026-10-25. **Subagente autónomo; informe para el coordinador.**
**NO se tocó el original.** Todo el trabajo está en `./work-recomp/`.
NO se subió nada a Drive ni a GitHub. NO se construyó APK (fase posterior).
NO se editó `./ESTADO.md` (es del coordinador).

## 0. Original verificado (solo lectura)

- Original: `./disc/` — 789.617.752 bytes, 3.879 ficheros
  (recuento `find -type f`; coincide con Fase 1).
- Copia de trabajo: `work-recomp/main.dol`, copiada con `cp`, SHA-1 idéntico al original:
  `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`, 3.405.600 bytes.
- Tras todo el trabajo, el original sigue con el mismo SHA-1 (verificado al final).
- Cabecera DOL (big-endian, leída por script Python, no de memoria):
  - text[0] (.init): off 0x100, addr 0x80003100, 9.504 bytes = 2.376 palabras.
  - text[1] (.text): off 0x2620, addr 0x800066E0, 2.865.952 bytes = 716.488 palabras.
  - Total texto: 718.864 palabras. Entry: 0x80003140. BSS: 0x803371A0, tamaño 0xB2CB8.
- Único `.rel`: `disc/files/modules/testmod.rel`, **569 bytes** (valor medido; la nota
  vieja decía 68 bytes — se registra el medido). Ver §7: no es código del juego retail
  (cadenas "Main called", "epilogue called") y DolRecomp actual lo rechaza.

## 1. DolRecomp — repo oficial, clon y build

- **No había copia local** en `./tools/` ni en `./` (comprobado antes de clonar).
- **Repo oficial:** https://github.com/ExpansionPak/DolRecomp
  (identificado vía búsqueda web: anuncio en GBAtemp "DolRecomp, a Wii/GameCube static
  recompiler, was recently made public" + README del repo, que lo describe como
  recompiler estático GameCube/Wii, CPU-only, sin runtime).
- **Clon:** 2026-10-25 en `work-recomp/DolRecomp/` (clon completo, árbol limpio:
  `git status --short` vacío).
- **Commit HEAD:** `02e27aca1c408cfcb2a4079a3a5b5ab3ae39d340`
  — 2026-10-10 14:10:56 -0700, "Merge pull request #38 from dougchansan/fix/modern-memory-test-portability".
- **Submódulo:** `extern/tomlc17` en `8d3766ddafa6515417f4885ae6878ef69fac401e`
  (inicializado con `git submodule update --init --recursive`; requerido por CMake).
- **Verificación de que es el proyecto real:** README ("DolRecomp is a static recompiler
  for GameCube and Wii PowerPC code"), `src/` con `analysis/`, `app/`, `backend/`,
  `cpu/`, `frontend/`, `ir/`, `platform/`, CLI `dolrecomp` con opciones
  `--gamecube`, `--cpu gekko|broadway|espresso`, `--backend c|llvm`, `--map`.
- **Build (cadena exacta, -j1 por la VM de 2 CPU / ~8 GB RAM):**
  ```
  cd work-recomp/DolRecomp
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Release     # exit 0, gcc 13.3.0, cmake 3.28.3
  cmake --build build -j1                             # exit 0
  ```
  Binario: `DolRecomp/build/dolrecomp` (203.424 bytes).
  Suite propia: `ctest --test-dir build -C Release -j1` → **20/20 tests PASSED**
  (1,96 s). Log: `work-recomp/build.log`, `work-recomp/build-config.log`.

## 2. Símbolos — fuente, conversión y recuento

- **Fuente pública (metadata, no contenido del juego):** SFA-Decomp,
  https://github.com/zcanann/SFA-Decomp
  (identificado vía Recompendium/DecompBuddy: "zcanann/SFA-Decomp, Decompilation of
  Star Fox Adventures for GameCube").
- **Clon:** `work-recomp/SFA-Decomp/`. Primer intento: clon completo — extremadamente
  lento por historial (llegó a ~179 MB sin terminar en ~20 min); se detuvo y se
  sustituyó por clon superficial `--depth 1`, que terminó completo y verificado
  (3.316 ficheros, 57 MB). El clon parcial dentro de `DolRecomp/` se eliminó.
- **Commit HEAD (shallow):** `9b4063e5c363fca5173a8ef565532287dc1396d0`
  — 2026-10-07 00:00:05 +0000, "Integrate staging".
- **Fichero exacto:** `SFA-Decomp/config/GSAP01_rev1/symbols.txt` (24.957 líneas).
  Identidad de versión confirmada por dos vías independientes:
  - `config/GSAP01_rev1/build.sha1` = `c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`
    (igual que nuestro DOL).
  - `config/GSAP01_rev1/config.yml`: `game_name: Star Fox Adventures (PAL, Rev 1)`,
    `hash: c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66`.
- **Formato de entrada (decomp-toolkit):**
  `nombre = seccion:0xDIRECCION; // type:TIPO size:0xTAMAÑO scope:...`
  Ej.: `__start = .init:0x80003140; // type:function size:0x138 scope:weak`.
- **Conversión:** script propio `work-recomp/make_symbols_map.py` (streaming, sin cargar
  el DOL en RAM). Regla: una línea por símbolo, formato que acepta el parser de
  DolRecomp (`src/analysis/symbol_map.c:parse_line`, 3 tokens): `0xADDR 0xSIZE nombre`.
  Salida: `work-recomp/symbols.map` (851.511 bytes, 24.957 líneas, 0 duplicados
  addr+nombre, 0 nombres que empiecen por `.` o `*`).
- **Recuento final (contado, no estimado):**

  | Concepto | Cifra |
  |---|---|
  | Líneas en `symbols.txt` GSAP01_rev1 | 24.957 |
  | type:function | **9.505** (9.493 en .text + 12 en .init) |
  | type:object | 15.363 |
  | type:label | 89 |
  | Símbolos con dirección no múltiplo de 4 | 318 (DolRecomp los descarta en carga, `symbol_map.c`: `(address & 3) != 0` → skip) |
  | Símbolos que DolRecomp cargaría (24.957 − 318) | 24.639 |
  | Símbolos ejecutables emitidos en `generated_symbols.h` | **9.591** (= 9.575 en .text + 16 en .init; ver §3) |

- **Comparación con la referencia del 2026-10-11 (24.445 = 9.505 func + 14.940 obj):**
  - Funciones: **idénticas, 9.505 = 9.505**. Sin desviación.
  - Objetos: ahora 15.363 frente a 14.940 (+423). Total ahora 24.957 frente a 24.445
    (+512), de los que 89 son `type:label` (categoría que la referencia no desglosaba)
    y el resto es crecimiento de objetos en el repo SFA-Decomp entre el run de
    referencia y el commit 2026-10-07 usado aquí. Indicio adicional: 15.363 − 422
    símbolos `hidden` = 14.941, a 1 del 14.940 de referencia — coherente con que el
    run anterior contase objetos visibles o con un commit anterior; no se puede
    afirmar más sin el commit exacto del run anterior, que no está documentado.
  - **No se inventó ningún símbolo:** todos vienen del fichero citado.

## 3. Recompilación con DolRecomp (modo Gekko)

Comandos exactos (desde `work-recomp/`, `-j1`):

```
./DolRecomp/build/dolrecomp -j1 --gamecube --cpu gekko main.dol out-nomap
./DolRecomp/build/dolrecomp -j1 --gamecube --cpu gekko --map symbols.map main.dol out-map
```

(`--gamecube` = modo GameCube sin title ID; `--cpu gekko` = perfil Gekko explícito.
El log de DolRecomp confirma `cpu: Gekko (GameCube)`, entry `0x80003140`,
BSS `0x803371A0 (0xB2CB8 bytes)`.)

### 3.1 Cifras reales (idénticas en ambas pasadas)

| Concepto | text[0] .init | text[1] .text | Total |
|---|---|---|---|
| Instrucciones decodificadas | 2.376 | 716.488 | **718.864** |
| Conocidas (traducidas a C) | 734 | 716.484 | 717.218 |
| Datos embebidos en sección de código | 1.642 | 4 | 1.646 |
| **Desconocidas** | **0** | **0** | **0** |
| Chunks generados | 1 | 175 | **176** |

- La cifra de referencia "716.488 instrucciones PPC→C, 0 desconocidas" corresponde a
  text[1] solo y **se reproduce exactamente** (716.488 decodificadas, 0 desconocidas).
- La cifra "~176 chunks" también se reproduce exactamente: **176 chunks**
  (ventanas de 0x4000 bytes: `chunk_0000_text0_80003100.c` …
  `chunk_0175_text1_802BE6E0.c`).
- Líneas de código C en chunks: **6.787.650** (más `generated.c` 182 líneas y
  `generated.h` 549 líneas).
- Tamaños: `out-nomap/` 183.840.846 bytes; `out-map/` 185.000.573 bytes
  (la diferencia es casi entera `generated_symbols.h`, 19.188 líneas).
- Ficheros generados (por pasada): `generated/generated.c` (índice de chunks),
  `generated/generated.h` (CPUState, helpers, declaraciones `func_<chunk>`),
  `generated/chunks/*.c` (176), `generated/generated_smc.txt` (solo SMC),
  y solo en la pasada con mapa: `generated/generated_symbols.h`.
- Logs completos: `dolrecomp-nomap.log`, `dolrecomp-map.log`.

### 3.2 Efecto real del mapa de símbolos en ESTA versión de DolRecomp (desviación importante)

- La pasada con `--map` imprime `loaded 9591 executable symbols` y emite
  `generated_symbols.h` con `DOLRECOMP_SYMBOL_COUNT 9591` y macros
  `DOLRECOMP_SYMBOL_<nombre>` / `DOLRECOMP_SYMBOL_SIZE_<nombre>`
  (ej. `DOLRECOMP_SYMBOL__start 0x80003140u`, tamaño `0x138`).
- **Pero el C generado es byte a byte idéntico con y sin mapa:**
  `diff -rq out-nomap/generated/chunks out-map/generated/chunks` → 0 diferencias;
  `generated.h` y `generated.c` también idénticos.
- Consecuencia: en el DolRecomp actual (ExpansionPak, commit 2026-10-10) el mapa
  **no** divide el código por funciones ni renombra funciones en el C: las
  funciones generadas siguen siendo `func_<inicio-de-chunk>` con etiquetas
  internas `label_<addr>` / `loop_<addr>` (ej. entry → `label_80003140` dentro de
  `func_80003100`, con `case 0x80003140u: goto label_80003140` en el dispatcher).
  El mapa solo sirve al runtime posterior (dispatch por nombre, replacements
  con `DOLRECOMP_ENABLE_REPLACEMENTS`, según README).
- Esto difiere del flujo antiguo GekkoRecomp/GameCubeRecomp (TOML + `symbols.txt`
  como fronteras de función) que presumiblemente usó el run del 2026-10-11.
  **No es un fallo de este run:** es el comportamiento documentado del upstream
  actual. Si la Fase 4 necesita funciones con nombre real en el C, habrá que
  post-procesar los chunks a partir de `symbols.map` + `generated_symbols.h`
  (trabajo nuevo, no hecho aquí) o usar otro fork; no se finge que ya exista.

### 3.3 SMC (código automodificable) — aviso real de DolRecomp

- Ambas pasadas terminan con:
  `warning: this DOL may patch executable memory at runtime. generated code many need additional patches`
  (sic, "many" en el mensaje original).
- Lista completa: `out-map/generated/generated_smc.txt` (idéntica en ambas pasadas,
  verificado con `diff`):
  - 108 líneas = 1 cabecera + **107 rangos** de instrucciones sospechosas de parchear
    memoria ejecutable.
  - Primeros: `0x80003390`, `0x80003740` (en .init), `0x801F3700`, `0x801F3708`,
    `0x801F770C`, `0x801F7714`, `0x8024136C`, `0x802414B8`, …
  - Último: `0x8028B974`. Rangos multi-palabra incluidos, ej. `0x8024B66C-0x8024B67C`,
    `0x802516FC-0x80251710`.
- El README de DolRecomp lo declara explícito: SMC **no** se gestiona automáticamente
  ("intentionally leaves that decision to the port"). Ver bloqueadores en §6.

### 3.4 Datos embebidos en secciones de código

- 1.646 palabras dentro de text[0]/text[1] no son instrucciones y DolRecomp las emite
  como `// .long 0x........` + `// embedded data` con una etiqueta que solo asigna
  `ctx->pc` (ej. `0x80003538: .long 0x4D657472` = "Metr", la tabla TRK).
- Consecuencia para el runtime: la imagen de memoria invitada debe contener los bytes
  originales de las secciones de código **como datos legibles**, no solo las
  secciones de datos; si el runtime solo carga secciones data, esas lecturas fallarán.

## 4. Verificación de precisión (independiente de DolRecomp)

Método exacto (scripts Python ad hoc, no el propio comentario de DolRecomp):
1. Leer la cabecera DOL big-endian y mapear dirección invitada → offset de fichero
   por sección (ver §0).
2. Desensamblar con **Capstone 5.0.7** (`CS_ARCH_PPC`, `CS_MODE_BIG_ENDIAN`),
   desensamblador independiente de DolRecomp.
3. Comparar mnemónico/operandos de Capstone con el comentario `// ADDR: ...` y el
   C emitido por DolRecomp para esa dirección.

Resultados (5 direcciones, todas coinciden salvo formato numérico: `-16` vs `-0x10`,
`110` vs `0x6e` — mismo valor):

| Dirección | Palabra PPC (BE) | Capstone (independiente) | C generado por DolRecomp |
|---|---|---|---|
| 0x80003140 (entry) | 0x48000139 | `bl 0x80003278` | `// 80003140: bl 0x80003278` ✓ |
| 0x80003144 | 0x48000211 | `bl 0x80003354` | `// 80003144: bl 0x80003354` ✓ |
| 0x800066E0 (inicio .text) | 0x9421FFF0 | `stwu r1, -0x10(r1)` | `// 800066E0: stwu r1, -16(r1)` ✓ |
| 0x800066E4 | 0x7C0802A6 | `mflr r0` | `// 800066E4: mflr r0` ✓ |
| 0x8000A6E0 | 0x2C000005 | `cmpwi r0, 5` | `// 8000A6E0: cmpwi r0, 5` ✓ |
| 0x801F3700 (zona SMC) | 0xB005006E | `sth r0, 0x6e(r5)` | `// 801F3700: sth r0, 110(r5)` ✓ |

- Comprobación aritmética adicional de la entry: 0x48000139 → opcode 18 (b), LK=1
  (bl), LI=0x4E, destino = 0x80003140 + (0x4E << 2) = **0x80003278**, que es
  `__init_registers` según SFA-Decomp (`size:0x1C`). Coherente: la entry salta a
  init_registers, y la segunda llamada va a `__init_hardware` (0x80003354).
- Además: el C de la entry emite `ctx->pc = 0x80003140u` y el dispatcher
  `case 0x80003140u: goto label_80003140` — la entry es alcanzable por dispatch.
- Alcance honesto: verificación puntual (6 direcciones, 2 secciones), no una
  comparación exhaustiva instrucción por instrucción de las 718.864 (eso sería
  otro trabajo; el conteo 0 desconocidas de DolRecomp es el dato de cobertura).

## 5. Verificación de compilación con gcc

- Cabecera de CPU usada: la propia de DolRecomp, `DolRecomp/src/cpu/cpu.h`
  (struct `CPUState`, `mem_read32`/`mem_write32`, `cpu_init`), vía `-I DolRecomp/src`.
  Los chunks incluyen `../generated.h`, que incluye `cpu/cpu.h` por defecto.
  Esto valida **sintaxis y tipos del C generado**, no un runtime jugable
  (el `cpu.c` de DolRecomp es un harness de test, no un runtime GameCube).
- Muestra previa: `chunk_0000` y `chunk_0001` con `-fsyntax-only` y objeto
  (`-c`): exit 0, **0 warnings**, `compile-test/chunk0000.o` 358.624 bytes.
- Compilación completa (script `compile-all/run.sh`, un chunk cada vez, `-j1`
  equivalente, `gcc -std=c11 -O0 -I DolRecomp/src -c`, sin optimización para
  no disparar RAM/tiempo):
  - **176/176 chunks compilan limpio, 0 fallos.** `compile-all/results.tsv`
    (176 líneas OK), `compile-all/summary.txt` = `OK=176 FAIL=0`,
    `compile-all/failures.log` vacío (0 bytes), 176 `.o` en `compile-all/`
    (146 MB en total).
  - Como los chunks con mapa son byte-idénticos a los sin mapa (§3.2), este
    resultado cubre ambas pasadas. Adicionalmente, `generated_symbols.h` se
    verificó por separado: un TU que lo incluye y referencia
    `DOLRECOMP_SYMBOL__start` pasa `-fsyntax-only` (`compile-test/symtest.c`).
- No hay errores reales que reportar: no se oculta ningún fallo parcial.

## 6. Bloqueadores honestos para el runtime posterior (Fase 4)

Ninguno de estos está resuelto por DolRecomp; el README lo dice: "It handles the
CPU side of recompilation. Graphics, audio, input, platform integration, and the
rest of the runtime are up to whatever is hosting the generated code."

1. **Runtime CPUState/HLE completo (el mayor):** el C generado solo conoce
   `CPUState` + `mem_read*/mem_write*` + un dispatcher con límite de profundidad
   de llamada (`DOLRECOMP_C_MAX_CALL_DEPTH 24`). Falta todo el resto: mapa de
   memoria GameCube (RAM, ARAM, registros HW), MMU/segmentos, excepciones,
   hilos, temporización, DVD, SI/EXI, MI, PI, VI, PE. El `cpu.c` de DolRecomp
   es un harness de pruebas, no ese runtime. Punto de partida sugerido por el
   propio README: ModernGekko-Template (no evaluado aquí).
2. **GX → Vulkan/GLES:** el DOL trae el SDK GX de Nintendo enlazado estáticamente;
   sus llamadas son código invitado que escribe en la FIFO y registros GX.
   El runtime debe emular esa interfaz HW y traducirla a Vulkan/GLES; DolRecomp
   no emite ninguna llamada gráfica. Sin esto no hay imagen, aunque la CPU
   funcione.
3. **DSP/audio y MusyX:** el audio pasa por DSP + middleware MusyX (el juego lo
   usa; la Fase 4 debe verificar qué funciones DSP/MusyX del DOL son alcanzables
   y si se reimplementan, se hace HLE o se reescriben). No verificado aquí más
   allá de constatar que el DOL contiene ese código; no se afirma cobertura.
4. **SMC (107 rangos, §3.3):** el runtime debe decidir por rango: parchear el C
   generado, invalidar/retraducir, o emular escritura en memoria ejecutable.
   DolRecomp lo deja explícitamente en manos del port. Los rangos en .init
   (0x80003390, 0x80003740) y en torno a 0x801F37xx / 0x8024xxxx / 0x8026xxxx
   son los primeros a auditar.
5. **Datos embebidos en código (§3.4) y secciones data/BSS:** la imagen de memoria
   debe reproducir: 8 secciones data (529.888 bytes), BSS 732.344 bytes en
   0x803371A0, y los bytes de código como datos legibles (1.646 palabras).
   Además, las secciones data 0x80005620/0x80005CC0 (extab) y los datos en
   0x802C2200+ deben mapearse en sus direcciones exactas.
6. **Sistema de objetos/DLLs, animaciones y mapas (datos del juego, Fase 3):**
   la recompilación traduce CPU, pero la lógica del juego vive en tablas de
   objetos/DLLs, animaciones, mapas y scripts cargados del disco. Sin la
   extracción de assets (Fase 3) y sin entender el cargador de DLLs del juego,
   el runtime no puede alimentar al motor. Esto no lo resuelve DolRecomp.
7. **testmod.rel no recompilable con DolRecomp actual:** ver §7; si la Fase 4
   necesita el sistema REL del juego, hay que resolverlo aparte (no bloquea
   main.dol).
8. **Funciones sin nombre real en el C (§3.2):** si la Fase 4 quiere depurar o
   parchear por nombre de función (no por dirección), hace falta el
   post-procesado de chunks con `symbols.map` o el uso de `generated_symbols.h`
   en el dispatcher del runtime. Las direcciones y tamaños están todos en
   `symbols.map`; no falta información, falta el paso de integración.

## 7. testmod.rel (único .rel del disco) — resultado negativo, documentado

- Copia: `work-recomp/testmod.rel` (569 bytes, igual que el original).
- Contenido: cadenas `"_prolog() called.  Zero=%d  One=%d"`, `"epilogue called"`,
  `"Main called"` — módulo de prueba, no código retail del juego.
- Intento: `./DolRecomp/build/dolrecomp -j1 --gamecube testmod.rel out-testmod`
  → **exit 1, `error: REL section table is outside the file`**
  (log: `dolrecomp-testmod.log`). Cabecera medida (BE): id=1, words siguientes
  `0, 0, 0x101, 0, 0x44, 1, 0x1a1, 0x229, ...` — no parsea como REL estándar
  (nº de secciones 0x101 imposible para 569 bytes).
- Conclusión: no bloquea main.dol; se deja fuera de la recompilación y se anota
  para Fase 3/4 si alguien necesita entender el cargador REL del juego.

## 8. Desviaciones frente a la referencia del 2026-10-11 (resumen)

| Magnitud | Referencia 2026-10-11 | Este run (2026-10-25) | Veredicto |
|---|---|---|---|
| Instrucciones .text | 716.488, 0 desconocidas | 716.488, 0 desconocidas | **Idéntico** |
| Chunks | ~176 | 176 | **Idéntico** |
| Compilación gcc | compilaban | 176/176 limpios | **Idéntico / mejor documentado** |
| Símbolos funciones | 9.505 | 9.505 | **Idéntico** |
| Símbolos objetos | 14.940 | 15.363 (+423) | Crecimiento del repo SFA-Decomp; ver §2 |
| Símbolos total | 24.445 | 24.957 (+512, incl. 89 labels) | Misma causa |
| testmod.rel | "stub de 68 bytes" | 569 bytes medidos | **Corrección: el fichero real mide 569** |
| Herramienta | (no documentado el fork exacto) | DolRecomp ExpansionPak commit 02e27ac (2026-10-10), CLI `--gamecube --cpu gekko --map` | Flujo distinto al GekkoRecomp/TOML antiguo: el mapa no renombra funciones en el C (§3.2) |

## 9. Ficheros generados (inventario, tamaños medidos)

En `./work-recomp/` (total del directorio: 572 MB,
incluidos .o de verificación):

| Fichero / directorio | Tamaño | Contenido |
|---|---|---|
| `main.dol` | 3.405.600 | Copia de trabajo del DOL (SHA-1 = original) |
| `DolRecomp/` (+ `build/dolrecomp`) | build 4.485.269 | Repo + binario construido (commit §1) |
| `SFA-Decomp/` | 57 MB | Repo símbolos (commit §2; solo lectura para este run) |
| `symbols.map` | 851.511 | 24.957 símbolos convertidos (§2) |
| `make_symbols_map.py` | 1.890 | Conversor SFA → DolRecomp |
| `out-nomap/generated/generated.c` | (182 líneas) | Índice de los 176 chunks |
| `out-nomap/generated/generated.h` | (549 líneas) | Cabecera común del C generado |
| `out-nomap/generated/chunks/` (176 .c) | — | C completo sin mapa |
| `out-nomap/generated/generated_smc.txt` | (108 líneas) | 107 rangos SMC |
| `out-nomap/` total | 183.840.846 | |
| `out-map/generated/` (+ `generated_symbols.h`, 19.188 líneas) | — | C completo con mapa (chunks idénticos a nomap) |
| `out-map/` total | 185.000.573 | |
| `compile-all/` (176 .o + results.tsv + summary.txt) | 146 MB | Prueba gcc 176/176 OK |
| `compile-test/` | — | Muestra + test de `generated_symbols.h` |
| `dolrecomp-nomap.log`, `dolrecomp-map.log`, `dolrecomp-testmod.log` | — | Logs de DolRecomp |
| `build.log`, `build-config.log` | — | Logs de build de DolRecomp |
| `FASE2.md` (este fichero) | — | Informe |

**Cifras de cabecera para el coordinador:** DolRecomp ExpansionPak `02e27ac`
(2026-10-10); SFA-Decomp `9b4063e` (2026-10-07); símbolos 24.957 (9.505 func +
15.363 obj + 89 labels); instrucciones 718.864 totales (716.488 en .text),
**0 desconocidas**; **176 chunks**; gcc **176/176 limpios**; precisión verificada
con Capstone en entry + 5 direcciones; SMC: 107 rangos; bloqueadores en §6.
Sin promesas de plazos: la Fase 4 (runtime) es el trabajo que queda y es mayor
que esta fase.
