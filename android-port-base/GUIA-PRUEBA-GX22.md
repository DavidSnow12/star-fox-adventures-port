# Guía de prueba en Tab S8 — GX22 (Tramo 8)

**Novedad Tramo 8 respecto a GX21 (host, NO probada en dispositivo todavía):** HLE ARQ de lectura (canales 22/95 pasan solos de status 4 a status 1 y producen sndSeqPlayEx reales en host), bucles 99/74, primer pase 22/95, normalize≠0 en TEV y captura de filtro de copia EFB. En dispositivo, además de los checks de esta guía, observa: ¿suena música en el título (22/95) con datos Tier 1? ¿sigue la etiqueta en la píldora? Si no suena música, NO es necesariamente regresión de GX22: en host la música por vía del juego existe, pero en dispositivo depende de datos, SAF y del HLE ARQ; reporta boot.log y logcat.


**Estado de este documento: En la rama `android-port-base` (commit de la APK GX22).** No se ha probado
nada en hardware en el Tramo 8 (sin enlace ADB en la tarea);
todo lo que sigue es lo que el usuario debe comprobar en su
Tab S8 con la APK GX22 commiteada en la rama `android-port-base`. Nada de lo que sigue se da
por pasado hasta que el usuario lo reporte.

**APK bajo prueba (verificada en la rama, no reconstruida
aquí):** `android-port-base/app-debug-gx22-test.apk`,
**12.722.854 B, SHA-256
`74c8ea0c01423d4b288c263c54f6a135fd87c62715b9913bbe89b65554a4d84e`,
v13 / `0.13.0-gx22-test`, PRUEBA, NO jugable.** Si tu APK no
coincide en tamaño y SHA, no es GX22: no sigas esta guía con
ella (GX20 es v11 / `0.12.0-gx21-test`, 12.710.566 B, SHA-256
`be0da86c85be0359f3116ba5121980cbb6d29fe661a5c9b130239a50f6deb0e9`).

**Qué trae GX22 respecto a GX22 (y qué NO trae).**
- TRAE (Tramo 7): etiqueta de texto dentro de la píldora
  «añadir audio» (bitmap GL, sin overlay Java, sin zona
  táctil nueva); resto de TEV/EFB (indirecto con escala
  `2^exp` corregida, fog EXP/EXP2 con near/far de XF,
  texgen NRM/TEX/post, `DecodeEfbCopy` puro); Tick ya en el
  runtime de la APK (el bug de Tick era del harness host, no
  de la APK); `sndSeqPlayEx` cableado en el port (probado
  solo por vía sintética, sin llamada real en juego todavía).
- NO TRAE: juego jugable verificado, ni menú alcanzado en
  ninguna traza host (ver §6), ni música por vía del juego,
  ni rumble positivo verificado, ni Pack C instalable. La
  parte A de esta guía (píldora + importación) SÍ es
  verificable ya; las partes B/C/D solo se verificarán
  cuando el juego llegue ahí de verdad.

## 0. Antes de empezar

- **Datos primero.** Sin `sfa-data/` la APK es inerte (clear
  + píldora, sin juego): eso NO es un fallo de GX22, es
  falta de datos. Importa primero el pack de test vigente
  por SAF (ver §2): **base SAF 243.309.656 B + overlay Tier 1
  = 382.982.980 B (365,24 MiB) / 3.968 ficheros**
  (2.921 de base: 5 `sys/` + 2.916 `files/` Pack B, más
  1.047 de overlay: 816 WAV + 231 ADP TTH). **Libre
  recomendado ≥1,5 GB** (ZIP 301 MB + pack 383 MB + caché
  peor caso 377,45 MiB + margen).
- **Pack C NO se instala.** El Pack C-título medido
  (117 ficheros, 71.705.100 B) NO es instalable: el
  verificador exige `files/` ≥2.916 ficheros y `sys/main.dol`
  exacto (3.405.600 B, SHA-1 `c1a6ccdc…66`); con 117
  escribiría `.saf-copy-error` y el juego no cargaría. No
  intentes instalar un recorte: usa el pack Tier 1 completo.
- **boot.log se sobrescribe en cada arranque.** La APK
  abre `boot.log` en escritura al arrancar: **copia el log
  de una sesión ANTES de volver a abrir la app**, o pierdes
  la evidencia de esa sesión. Vía adb (APK debuggable):
  ```
  adb shell "run-as com.starfox.port cat files/boot.log" > boot-sesion.log
  ```
  Haz una copia por sesión y nómbrala (`boot-titulo.log`,
  `boot-menu-intento1.log`, …). Las líneas que importan
  empiezan por `audio-btn:`, `saf:`, `bridge:` y `rumble:`
  (estas últimas, solo si hay fallo JNI; su ausencia es
  normal, ver §5).
- **Controles táctiles (fracciones de pantalla, layout del
  port):** Start arriba-centro (0,50 / 0,10); A derecha
  (0,905 / 0,70), B (0,845 / 0,82), X (0,845 / 0,58),
  Y (0,785 / 0,70); D-pad izquierda: arriba (0,255 / 0,58),
  abajo (0,255 / 0,82), izquierda (0,195 / 0,70), derecha
  (0,315 / 0,70); stick izquierdo abajo-izquierda;
  L (0,055 / 0,12), R (0,945 / 0,12). La píldora «añadir
  audio» está en el centro inferior (Tab S8: 307×96 px,
  x 0,44–0,56, y 0,92–0,98), debajo del damero.

## 1. Prueba A — Píldora con etiqueta + importación Tier 1 (verificable YA)

### A0. Etiqueta en cada estado (hazlo primero)
1. Abre la app con los datos base ya importados pero SIN
   audio. **Esperado:** píldora **ámbar fija** con el texto
   **`AÑADIR AUDIO`** legible dentro de ella, sin salirse
   por ningún lado. (La Ñ lleva tilde: a distancia puede
   parecer una N; acércate antes de reportar «sin tilde».)
2. Pulsa la píldora sin elegir carpeta todavía.
   **Esperado:** **ámbar parpadeante** con **`VERIFICANDO`**.
3. Completa la importación (§2) y comprueba: píldora
   **verde** con **`AUDIO LISTO`**.
4. Si se da un error real (p. ej. carpeta sin `audio/`
   válido), **esperado:** píldora **roja** con
   **`ERROR AUDIO`** en blanco. No fuerces un error
   borrando datos: si no se da, déjalo como «no observado».
5. En todos los estados: texto **centrado**, sin invadir el
   damero ni ningún control. Toca el stick y pulsa A: el
   juego debe responder igual que antes (la etiqueta no
   añade zona táctil: tocar las letras es tocar la píldora).

### A1–A4. Importación (resumen; detalle completo en la guía
### Tier 1/caché Tramo 7 de la rama)
1. Con audio sin importar, boot.log debe traer
   `native: audio-btn: estado sin audio`.
2. Pulsa la píldora (toque corto, soltar DENTRO): debe
   parpadear con `VERIFICANDO` y abrir el picker SAF
   (`saf: picker de audio abierto (elige la carpeta audio/
   con streams/ y musyx/)`).
3. En el picker elige la carpeta **`audio/`** (o su padre
   si contiene `audio/`). **NO elijas** la carpeta de
   datos base ni `streams/` sola. Si transfieres 365 MiB
   por el picker de audio, has elegido la carpeta
   equivocada: el overlay solo son **1.047 ficheros,
   139.673.324 B ≈ 133,20 MiB** (816 WAV = 26.590.956 B +
   231 ADP TTH = 113.082.368 B).
4. Espera a que termine (progreso cada 250 ficheros en
   boot.log). **Durante la copia, NO pulses la píldora de
   nuevo** ni cierres la app a mitad de copia.
   **Esperado al terminar:** píldora **verde** con
   **`AUDIO LISTO`**, y en boot.log:
   ```
   saf: copia de audio terminada: 1047 ficheros, … B
   saf: verificacion de audio (anadir audio)
   saf: audio/ wav=816 adp=231 adp_invalidos=0
   saf: audio listo (marcador .saf-audio-done; …)
   native: audio-btn: estado audio listo
   ```
   `adp_invalidos` debe ser **0**. Si es >0, anota qué
   ficheros lista (máx. 10 en el log).
5. Con audio listo, pulsa la píldora de nuevo: debe volver
   a parpadear con `VERIFICANDO` y reabrir el picker
   (re-añadir/sustituir, deliberado). Cancela el picker
   (atrás): en ~1–2 s debe volver a **verde** con
   `AUDIO LISTO`. Si se queda parpadeando más de 5 s tras
   cancelar, repórtalo con el boot.log.
6. El flujo de audio **nunca escribe** en `sys/` ni en
   `files/` ni borra `.saf-copy-done`. Si tras importar
   audio el juego dejara de cargar, es una regresión grave.

### A5. Táctil con la etiqueta (regresión, rápida)
1. Toque que empieza FUERA de la píldora y se desliza
   HASTA ella: **NO debe abrir el picker**.
2. Toque dentro que se desliza FUERA y se suelta fuera:
   **NO debe abrir el picker**.
3. Dos dedos a la vez (uno en la píldora, otro en el
   stick): **ambos deben funcionar**.
Si alguno falla, es una regresión grave: indica el caso
(1/2/3) y si ya pasaba en GX21.

## 2. Prueba B — Título, aviso de tarjeta y primer intento de menú (EXPLORATORIA, no pass/fail)

**Contexto honesto:** ninguna traza host ha pasado del
título (Tramo 8: 7 variantes, todas en DLL UI 4, ver §6).
En dispositivo el juego SÍ tiene mando táctil real, así que
esta parte es el primer intento real de navegar — pero
**ningún resultado aquí es todavía un «fallo» del port por
sí solo**: reporta exactamente qué pantalla viste y qué
pulsaste, con foto si puedes, y copia el boot.log ANTES de
relanzar.

1. Con el pack Tier 1 importado y audio listo (o sin
   audio: el juego carga igual), abre la app y espera al
   título. **Anota:** ¿se ve el título? ¿vídeo? ¿texto
   «Press Start» o equivalente? ¿la píldora sigue visible
   sobre el juego?
2. Pulsa **Start** (arriba-centro). **Anota:** ¿cambia la
   pantalla? ¿aparece pantalla de carga («loading, do not
   touch the Memory Card…») y/o aviso de tarjeta («There
   is no Memory Card in Slot A», opciones «Retry» /
   «Play (but cannot save your progress)»)? Si hay tarjeta
   virtual (`memcard-a.raw` en almacenamiento privado, la
   APK la crea), el aviso puede no aparecer: anota si
   apareció o no.
3. Si aparece el aviso de tarjeta, prueba EN ESTE ORDEN,
   copiando el boot.log entre intentos (cada intento, una
   sesión; si relanzas, el log anterior se pierde):
   a. Pulsa **A** (¿selecciona la opción marcada? ¿cuál?).
   b. Si A no avanza, pulsa **abajo** en el D-pad y luego
      **A** (¿cambia la opción marcada? ¿avanza?).
   c. Si sigue sin avanzar, pulsa **Start** de nuevo.
   **Anota en cada paso:** qué opción parecía marcada
   (si se distingue: el color de selección TEV aún puede
   no distinguirse en hardware), qué pulsaste y qué
   pantalla salió después (¿título de nuevo? ¿menú con
   «New Game / Load / Options» o similar? ¿negro?).
4. Si llegas a un menú: **NO pulses «New Game» sin anotar
   primero la pantalla** (foto + boot.log). Luego, si
   quieres, prueba «New Game» y anota si carga mundo,
   si se queda en negro, o si vuelve al título — y copia
   el boot.log antes de relanzar.
5. Si el juego se queda en negro, se cierra o se congela
   en algún paso: anota el paso exacto, el tiempo
   esperado, y copia el boot.log (y logcat si lo tienes)
   ANTES de relanzar. Un cuelgue en el título con GX22
   NO significa que GX20 «jugara»: GX20 tampoco jugaba.

## 3. Prueba C — Sonido Tier 1 y caché (solo si el juego llega ahí)

**No intentes esta parte si el juego no ha pasado del
título.** Con GX22 sin juego real, el criterio de éxito es
la parte A. Esto es la especificación para cuando llegue:

1. **SFX Tier 0 (816 WAV):** efectos por trigger deben
   sonar cuando el juego los dispare. En boot.log:
   `bridge: trigger SFX id … -> FX … -> muestra …`.
   En host Tramo 7, en juego real: 11/11, 24/24 SFX, 0
   descartados (ese dato es host, no dispositivo).
2. **Voz/ambiente TTH (231 ADP, 121 IDs resueltos):** al
   llegar a ThornTail Hollow, diálogos `ttalk*`, `mttalk*`
   y ambiente `tth*` deben sonar por ADP. Primera vez:
   `bridge: stream por adp 'streams/TTH/….adp' …`; si ya
   estaba cacheado: `por cache`. Los 110 ADP TTH sin ID
   resuelto quedan en silencio: eso NO es fallo del botón
   ni de la caché.
3. **Caché PCM** (`sfa-data/audio-cache/v1/`): tras sonar
   COMPLETO un stream TTH debe aparecer su `.pcm` +
   `.meta` (`bridge: cache ADP promovida …`); tamaño
   `.pcm` = `adp_bytes / 32 * 28 * 4` (ratio 3,50×).
   Segunda reproducción: `por cache`, mismo sonido.
   Stream cortado a medias NO crea caché. La caché nunca
   suena sin su ADP. Techo LRU 2.048 MiB: con Tier 1 no
   debes ver desalojos (caché TTH completa ≤377,45 MiB).

## 4. Prueba D — Rumble (negativa YA, positiva solo con evento real)

1. **Arranque sin vibración.** Al abrir la app, en el
   picker SAF y al importar audio, el motor **NO debe
   vibrar**. Si vibra sin haber jugado, es un fallo:
   repórtalo con el momento exacto.
2. **Juego sin evento = silencio.** En menús o caminando
   sin recibir golpes, silencio del motor. Vibración en
   menús sin evento sería sospechosa, pero solo
   concluyente si se descarta un evento real del juego.
3. **Pausa detiene el motor.** Si alguna vez vibra y
   cambias de app, bloqueas la tablet o la app pierde el
   foco: **debe detenerse en el acto**. Al volver, solo
   puede volver a vibrar si el juego emite un RUMBLE
   nuevo (el tracker se resetea al pausar: deliberado).
4. **Salir detiene el motor.** Con la app cerrada, el
   motor debe estar parado. Un motor que siga vibrando
   con la app cerrada es un fallo grave: repórtalo con el
   tiempo que tardó en parar.
5. **Positiva (solo con evento real):** combate, daño o
   caída que en GameCube vibraría → vibración continua
   mientras dure el evento, que **para sola** al terminar
   (STOP del juego). Un único golpe seco de ~1 s aunque
   la acción continúe, o una vibración que no para nunca,
   son fallos distintos: anota cuál ocurrió. El mismo
   evento, repetido, debe vibrar cada vez.

## 5. Qué NO debes esperar con GX22 (no lo reportes como fallo)

- **Juego jugable.** GX22 es PRUEBA, NO jugable: sin juego
  real verificado, no esperes partida completa, ni mundo,
  ni guardado verificado en dispositivo.
- **Menú garantizado.** Ninguna traza host llegó al menú;
  si en dispositivo tampoco llegas, es el estado conocido,
  no una regresión de GX22 (repórtalo como «sin avance»,
  con los pasos de §2, no como «GX22 roto»).
- **Música por vía del juego.** En host, por vía del juego
  hubo 0 llamadas `sndSeqPlayEx` y los canales 22/95
  quedaron esperando un callback ARQ que el HLE no
  entrega; los bucles medidos (99/74, 5 no buclea) no están
  implementados. Si en dispositivo no suena música, es el
  estado conocido. Si SUENA música, repórtalo como nuevo
  (con qué momento del juego).
- **Rumble positivo garantizado.** Ningún run host llamó
  a `PADControlMotor`: no hay momento garantizado que
  deba vibrar. «No vibra» sin evento claro es
  «sin evento observado», no un fallo.
- **Pack C instalable.** Ver §0: con 117 ficheros el
  verificador rechaza el pack. Usa Tier 1 completo.
- **Stream 1367.** No existe en `Streams.bin`: si el log
  lo marca no resuelto, es el problema conocido desde la
  Fase 14, no un fallo de GX22 ni del pack.
- **Texto de selección perfecto.** El color de selección
  TEV puede no distinguirse todavía en hardware: si no
  sabes qué opción está marcada en el aviso/menú, dilo
  así («opción marcada no distinguible») en vez de
  adivinar.

## 6. Qué reportar (copia y pega, sin resumir)

1. **Build:** GX22 (tamaño + SHA de arriba, o «no
   coincide») y si los datos son Tier 1 completo (sí/no,
   conteo `wav=`/`adp=` del informe SAF en boot.log).
2. **Paso exacto** (p. ej. «A0 paso 2», «B paso 3b», «D
   punto 3») y qué esperabas ver.
3. **Píldora en ese momento:** color + texto
   (`AÑADIR AUDIO` / `VERIFICANDO` / `AUDIO LISTO` /
   `ERROR AUDIO` / «sin texto» / «recortado»), y si
   responde a toques. Foto si puedes.
4. **Pantalla del juego en ese momento:** título / carga
   / aviso de tarjeta (¿qué opción marcada?) / menú (¿qué
   opciones?) / mundo / negro / cierre, con foto si
   puedes.
5. **Líneas de boot.log** relevantes, copiadas literales
   (`audio-btn:`, `saf:`, `bridge:`, `rumble:`), y si el
   log se extrajo ANTES de relanzar la app (sí/no).
6. **Caché** (si el fallo es de caché): listado de
   `audio-cache/v1/streams/TTH/` y el `.meta` afectado.
7. **¿Es fallo nuevo de GX22 o ya pasaba en GX21?** Si la
   etiqueta es lo único distinto, dilo; si el táctil o la
   importación fallan igual que en GX20, dilo también.
8. **Rumble:** qué sentiste (nada / continua / golpe seco
   / no para), si pausar/salir la detuvo, y líneas
   `rumble:` o «ninguna».

Casos que NO son fallos de GX22 (ver §5): no jugar, no
llegar al menú, música muda por vía del juego, rumble sin
evento, stream 1367 sin resolver, y no haber observado el
estado rojo `ERROR AUDIO` si no se dio ningún error real.
