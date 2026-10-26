# Guía de prueba en Tab S8 — Rumble en hardware, fase B (Tramo 7)

**LEE ESTO PRIMERO — qué se puede probar y qué no, todavía.**
El rumble fase B (JNI → `Vibrator`, solo canal 0) ya existe en
código desde el Tramo 5 y está probado en host (18 checks), pero
**el juego NO ha llamado a `PADControlMotor` en ningún run host
todavía**. Eso significa: hoy NO hay ningún momento del juego
garantizado en el que deba vibrar, y NO existe un botón de
prueba de rumble (añadir uno sería otra zona táctil y otro
alcance; no se hace en este tramo). Esta guía, por tanto, tiene
dos partes: (A) las comprobaciones negativas que SÍ se pueden
hacer ya con cualquier build (que el motor NO vibre cuando no
debe, y que se detenga al pausar/salir), y (B) la prueba
positiva, que solo será concluyente cuando el juego alcance un
evento que llame a `PADControlMotor` (golpe, daño o acción que
en GameCube haría vibrar el mando — el momento exacto lo dirá
el juego cuando llegue ahí, no se inventa aquí).
**No reportes «no vibra» como fallo si el juego no ha llegado
a ningún evento de rumble**: sin llamada del juego, el silencio
del motor es el comportamiento correcto.

**Qué cambió en el Tramo 7 (y qué NO cambió para el rumble).**
- CAMBIA: la píldora «añadir audio» ya lleva etiqueta de texto
  (`AÑADIR AUDIO` / `VERIFICANDO` / `AUDIO LISTO` /
  `ERROR AUDIO`, fuente bitmap en GL). La etiqueta es solo
  pintura dentro de la píldora: no añade zona táctil, no toca
  el camino de rumble, no añade líneas a boot.log.
- NO CAMBIA: camino de rumble, onda, permisos, logs ni
  criterios de esta guía. Si al probar rumble notas algo raro
  en la píldora (texto que no corresponde al estado de audio),
  repórtalo como fallo de etiqueta, no de rumble, indicando
  color + texto (ver guía Tier 1/caché Tramo 7, §1 y §5).
- Pack de test vigente (sin cambios): base SAF 243.309.656 B +
  overlay Tier 1 = 382.982.980 B (365,24 MiB) / 3.968 ficheros,
  libre ≥1,5 GB. El rumble no depende del audio: las pruebas
  negativas de la parte A valen con o sin audio importado.

## 0. Base técnica (para interpretar lo que veas)

- Camino: juego → HLE `PADControlMotor(chan, cmd)` → tracker
  (solo-en-transición: solo actúa cuando el estado cambia) →
  sink JNI (solo canal 0; canales 1–3 solo se registran, nunca
  vibran: hay un único motor físico) → `MainActivity.setRumble`
  / `cancelRumble` → `Vibrator`.
- Onda: `createWaveform({0, 1000}, repeat=0)` — en efecto
  continua (0 ms de pausa entre repeticiones). La duración NO
  la fija un temporizador: la decide el juego con su STOP
  (`PADControlMotor(0, 0)` o `(0, 2)` STOP_HARD → `cancel()`).
  Un RUMBLE sin STOP posterior debe vibrar hasta que el juego
  lo pare o hasta pausar/salir (ver §A).
- Permiso: `VIBRATE` es normal (sin diálogo en tiempo de
  ejecución). Si el dispositivo no tuviera vibrador
  (`hasVibrator()` false), el sink es no-op silencioso: la
  Tab S8 SÍ tiene motor, así que en ella «no vibra» nunca
  puede explicarse por falta de hardware.
- Logs: el camino de éxito NO deja línea propia en boot.log
  (el sink JNI solo loguea fallos: `rumble: … JNI fallo`,
  `metodo Java … no encontrado`, `no se pudo asociar el hilo
  a la JVM`). Ausencia de líneas `rumble:` = camino JNI sano
  hasta donde se puede observar por log; presencia de una =
  fallo real, repórtalo literal. La confirmación positiva es
  **sentir** la vibración, no una línea de log.
- boot.log: extrae el log ANTES de relanzar la app (cada
  arranque lo trunca). El Tramo 7 no añade líneas de rumble.

## A. Prueba negativa — verificable YA con cualquier build

Haz estas 4 comprobaciones con la APK con este tramo (o con
GX20: el rumble fase B ya estaba en GX20; el Tramo 7 no lo
toca, solo añade la etiqueta a la píldora):

1. **Arranque sin vibración.** Abre la app (con o sin datos).
   **Esperado:** el motor NO vibra en ningún momento del
   arranque, ni en el picker SAF, ni al importar audio con el
   botón. Si vibra al arrancar sin haber jugado, es un fallo
   (un RUMBLE espurio o un sink sin inicializar vibrando):
   repórtalo con el momento exacto. De paso, comprueba la
   etiqueta: con audio sin importar, la píldora debe decir
   `AÑADIR AUDIO` en ámbar; tras importar, `AUDIO LISTO` en
   verde (si la etiqueta no corresponde, es fallo de etiqueta,
   no de rumble).
2. **Juego sin evento = silencio.** Juega (cuando se pueda)
   por zonas sin acción: menús, caminar sin recibir golpes.
   **Esperado:** silencio del motor. Vibración en menús sin
   evento sería sospechosa, pero solo concluyente si el log
   o el contexto descartan un evento real del juego.
3. **Pausa detiene el motor.** Si en algún momento el motor
   está vibrando (prueba B) y cambias de app, bloqueas la
   tablet o la app pierde el foco: **el motor debe detenerse
   en el acto** (doble garantía: `APP_CMD_PAUSE`/`LOST_FOCUS`
   → `StopAllRumble` nativo + `onPause()` Java → `cancel()`).
   Al volver, el juego puede volver a vibrar solo si emite
   un RUMBLE nuevo (el tracker se resetea al pausar: un
   RUMBLE idéntico tras reanudar SÍ es transición y vuelve
   a vibrar — eso es deliberado, no un fallo).
4. **Salir detiene el motor.** Cierra la app mientras vibra
   (si se da el caso) o justo después: **el motor debe estar
   parado** tras el cierre (`onDestroy()` Java + `Shutdown()`
   nativo cancelan). Un motor que siga vibrando con la app
   cerrada es un fallo grave («motor olvidado»): repórtalo
   de inmediato con el tiempo que tardó en parar (o si hubo
   que forzar la detención).

## B. Prueba positiva — cuando el juego llegue a un evento

Cuando el port juegue y alcances acción real (combate, daño,
caída, o cualquier evento que en GameCube vibraría):

1. **Qué debes sentir:** vibración continua mientras dure el
   evento, que **para sola** cuando el evento termina
   (STOP del juego). No es un toque corto ni un patrón: es
   continua hasta STOP. Si sientes un único golpe seco de
   ~1 s y luego silencio aunque la acción continúe, o una
   vibración que no para nunca tras terminar la acción,
   anota cuál de los dos ocurrió (son fallos distintos:
   STOP prematuro frente a STOP perdido).
2. **Qué NO debes sentir:** vibración en el canal equivocado
   no existe como síntoma observable (un solo motor); lo
   observable es vibrar / no vibrar / no parar.
3. **Repetición:** el mismo evento, repetido, debe vibrar
   cada vez (solo-en-transición: RUMBLE → STOP → RUMBLE
   vibra de nuevo; RUMBLE → RUMBLE sin STOP intermedio NO
   re-dispara, pero como la onda ya es continua, no notarás
   diferencia: no lo reportes como fallo).
4. **Qué anotar en el reporte:** momento del juego (zona y
   acción), duración aproximada sentida (¿para sola al
   terminar la acción? ¿sigue?), si pausar/salir la detuvo
   (§A.3–4), y cualquier línea `rumble:` en boot.log/logcat
   (su ausencia es normal; su presencia es fallo). Añade
   también color + texto de la píldora en ese momento (p. ej.
   verde `AUDIO LISTO` si el audio estaba importado): sirve
   para descartar que la vibración viniera de tocar la píldora
   por accidente.

## C. Qué reportar (copia y pega, sin resumir)

1. **Build** (GX20 / build con Tramo 7) y si el juego ya
   juega o solo arranca.
2. **Momento exacto** (arranque / picker / menú / acción
   concreta) y **qué sentiste** (nada / continua / golpe
   seco / no para).
3. **Pausa y cierre:** ¿paró el motor al pausar? ¿al salir?
   (sí/no, y cuánto tardó si no paró sola).
4. **Líneas `rumble:`** de boot.log/logcat, literales, o
   «ninguna» (extrae boot.log ANTES de relanzar la app: cada
   arranque lo trunca).
5. **¿El evento del juego era real?** Si reportas «no vibra»,
   indica qué acción del juego esperabas que vibrara y por
   qué (si no hay evento claro, es «sin evento observado»,
   no un fallo).
6. **Píldora en ese momento** (Tramo 7): color + texto
   (`AÑADIR AUDIO` / `VERIFICANDO` / `AUDIO LISTO` /
   `ERROR AUDIO`), para descartar toques accidentales en ella.
