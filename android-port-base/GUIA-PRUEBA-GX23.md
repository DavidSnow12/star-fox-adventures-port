# Guía de prueba en Tab S8 — GX23 (Tramo 9)

**Novedad Tramo 9 respecto a GX22 (host, NO probada en dispositivo todavía):** bucles de música 22/95 por secciones, varias canciones a la vez en el bridge (antes una cortaba a la otra), observabilidad DVDLow (`GetCurrentId` en el hook), copia EFB decodificada y mecanismo de captura FIFO de mundo (código integrado, SIN cableado en `Frame()` ni botón de captura todavía: ver §5), y la secuencia título→DLL 5 medida en host. En dispositivo, además de los checks de esta guía, observa: ¿suena música en el título (22/95, con bucle)? ¿sigue la etiqueta en la píldora? Si no suena música, NO es necesariamente regresión de GX23: en host la música por vía del juego existe, pero en dispositivo depende de datos, SAF y del HLE ARQ; reporta boot.log y logcat.

**Estado de este documento: en la rama `android-port-base` (commit de la APK GX23).** No se ha probado nada en hardware en el Tramo 9 (sin enlace ADB en la tarea); todo lo que sigue es lo que el usuario debe comprobar en su Tab S8 con la APK GX23 commiteada en la rama `android-port-base`. Nada de lo que sigue se da por pasado hasta que el usuario lo reporte.

**APK bajo prueba (verificada en la rama, no reconstruida aquí):** `android-port-base/app-debug-gx23-test.apk`, **12.747.430 B, SHA-256 `e0a51117ab11dfa821017894d354a8d4cf76c12f820a7218712a7d23c6315663`, SHA-1 `6978f60a5d7a577d43e6fb1fcc8f1ad9d9cf5afe`, v14 / `0.14.0-gx23-test`, PRUEBA, NO jugable.** Si tu APK no coincide en tamaño y SHA, no es GX23: no sigas esta guía con ella (GX22 es v13 / `0.13.0-gx22-test`, 12.722.854 B, SHA-256 `74c8ea0c01423d4b288c263c54f6a135fd87c62715b9913bbe89b65554a4d84e`).

**Qué trae GX23 respecto a GX22 (y qué NO trae).**
- TRAE: bucles 22 (12 secciones) y 95 (5 secciones) por secciones; bridge multi-canción (hasta 4 slots, fades y stops por handle); llamador de la música del título identificado en host (animación de cámara del título, triggers 190/193); EFB decodificado (filtro 0x53/0x54, formato low52, bit 14 = clase display/textura, no gate) + FBO EFB y captura FIFO en código; secuencia de exploración título→DLL 5 medida en host (§2).
- NO TRAE: juego jugable verificado, ni menú alcanzado en ninguna traza host, ni copias EFB reales en pantalla (el cableado en `Frame()` y el botón de captura están pendientes: sin ellos las copias cuentan como rechazadas `sin-target-EFB` y no hay capturas de frame), ni rumble positivo verificado, ni Pack C instalable. La parte A (píldora + importación) SÍ es verificable ya; las partes B/C solo se verificarán cuando el juego llegue ahí de verdad.

## 0. Antes de empezar

- **Datos primero.** Sin `sfa-data/` la APK es inerte (clear + píldora, sin juego): eso NO es un fallo de GX23, es falta de datos. Importa primero el pack de test vigente por SAF: **base SAF 243.309.656 B + overlay Tier 1 = 382.982.980 B (365,24 MiB) / 3.968 ficheros. Libre recomendado ≥1,5 GB.**
- **Pack C NO se instala.** El Pack C-título medido (117 ficheros, 71.705.100 B) NO es instalable: el verificador exige `files/` ≥2.916 ficheros y `sys/main.dol` exacto (3.405.600 B, SHA-1 `c1a6ccdc…66`); con 117 escribiría `.saf-copy-error` y el juego no cargaría. No intentes instalar un recorte: usa el pack Tier 1 completo.
- **boot.log se sobrescribe en cada arranque.** Copia el log de una sesión ANTES de volver a abrir la app: `adb shell "run-as com.starfox.port cat files/boot.log" > boot-sesion.log`. Haz una copia por sesión y nómbrala (`boot-titulo.log`, `boot-menu-intento1.log`, …). Las líneas que importan empiezan por `audio-btn:`, `saf:`, `bridge:` y `rumble:` (estas últimas, solo si hay fallo JNI; su ausencia es normal).
- **Controles táctiles:** Start arriba-centro (0,50 / 0,10); A derecha (0,905 / 0,70), B (0,845 / 0,82), X (0,845 / 0,58), Y (0,785 / 0,70); D-pad izquierda: arriba (0,255 / 0,58), abajo (0,255 / 0,82), izquierda (0,195 / 0,70), derecha (0,315 / 0,70); stick izquierdo abajo-izquierda; L (0,055 / 0,12), R (0,945 / 0,12). La píldora «añadir audio» está en el centro inferior (Tab S8: 307×96 px, x 0,44–0,56, y 0,92–0,98). **No toques la píldora durante la prueba de menú**: un toque abre el picker SAF y contamina el intento.

## 1. Prueba A — Píldora con etiqueta + importación Tier 1 (verificable YA)

Igual que en GX22: abre la app con datos base ya importados pero SIN audio (píldora ámbar fija con texto `AÑADIR AUDIO`), pulsa la píldora, importa el pack Tier 1 por SAF y comprueba que pasa a `VERIFICANDO` (parpadeante) y luego a `AUDIO LISTO` (verde). Si queda en rojo (`ERROR AUDIO`), copia el boot.log antes de relanzar y reporta las líneas `saf:` y `audio-btn:`. Cancelar el picker debe dejar la píldora en ámbar, no parpadeando.

## 2. Prueba B — Exploración título → aviso → DLL 5 (camino más corto en host)

**Estado honesto (Tramo 9, host):** ninguna variante host ha llegado al menú. La variante que más se acerca es tarjeta + stick-abajo+A repetido (40M despachos): sale de DLL 4 a DLL 5, con partida creada, 27 efectos y 0 excepciones, pero el frame final es casi negro, sin ficheros de menú ni de área: DLL 5 NO es el menú confirmado. B/Z no cambian nada medible en host; el stick abajo domina sobre Start mantenido.

Secuencia, un intento = una sesión con su boot.log copiado ANTES de relanzar:
1. **Título.** Abre la app y espera. Anota: ¿se ve el título? ¿vídeo attract en marcha? ¿texto «Press Start» o equivalente? ¿la píldora sigue visible sobre el juego? Espera a que el vídeo attract termine por sí solo si puedes (30–60 s).
2. **Salir del attract: mantén Start, no lo pulses y sueltes.** En host, lo que saca de la película NO es un toque corto: es Start mantenido 5–10 s. Anota: ¿cambia la pantalla? ¿aparece pantalla de carga, aviso de tarjeta, o una pantalla casi negra con una línea de texto pequeña? Esa pantalla casi negra con texto pequeño ES el estado post-attract medido en host: si la ves, has llegado tan lejos como el host. No es el menú.
3. **Si aparece el aviso de tarjeta**, prueba EN ESTE ORDEN, copiando el boot.log entre intentos: a) pulsa A; b) si A no avanza, stick izquierdo hacia abajo + A (en host el D-pad abajo+A NO es lo mismo); c) D-pad abajo + A; d) B; e) Z; f) Start mantenido. Tras la pantalla post-attract, A y stick-abajo+A **repetidos** varios segundos (en host hicieron falta ~870 lecturas para DLL 5).
4. **Reporta como «posible DLL 5» (no como menú)** cualquier pantalla nueva tras esa secuencia, con screenshot y boot.log. Un menú real se reconoce por opciones legibles y ficheros de menú/área en el log, no por una pantalla casi negra.

## 3. Prueba C — Sonido en el título

Con Tier 1 importado y en el título: ¿suena música (22/95)? ¿sigue sonando al cabo de un rato (bucle por secciones, novedad Tramo 9) o se corta tras el primer pase? ¿suenan efectos al navegar (selección del menú)? ¿suena algún stream? Reporta qué se oye y qué no, con boot.log (líneas `bridge:`) y logcat (`StarFoxPort`). El stream 1367 sigue sin resolver en host: si algún sonido del título falta, puede ser ese; no lo inventes, repórtalo como ausente.

## 4. Prueba D — Rumble y caché

Rumble: sigue sin evento `PADControlMotor` real en ninguna traza host, así que la ausencia de vibración en el título es lo esperado hoy, no un fallo. Si vibrara en algún momento, repórtalo como novedad con el boot.log. Caché: tras sonar streams, la carpeta `sfa-data/audio-cache/v1/` debe ir creciendo con `.pcm` y `.meta`; reporta si crece o si algún stream suena siempre desde cero.

## 5. Qué NO esperar de GX23 (para no reportar falsos fallos)

- Capturas de frame ni líneas `efb-copy:` en boot.log: el mecanismo de captura existe en código, pero el botón/disparador y el cableado en `Frame()` están pendientes (decisión del integrador: cablearlo exigiría exponer los eventos GxCopy al frame y dibujar dos veces o un blit que no existe, y la dirección del ratio de escala Y — 0x4E = 232 en todas las copias reales — sigue sin resolverse: el modelo actual rechazaría todas las copias XFB reales). No pidas capturas hasta la APK que lo anuncie.
- Menú, mundo, Pack C-menú/mundo, rumble positivo, ni APK jugable: todo eso sigue pendiente y solo se dará por hecho con juego real verificado en Tab S8.
