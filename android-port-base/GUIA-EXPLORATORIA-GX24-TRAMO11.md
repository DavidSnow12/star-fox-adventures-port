# Guía exploratoria GX24 — Tramo 11 (BORRADOR, no integrar sin revisión del coordinador)

APK: GX24 de prueba, v15 / `0.15.0-gx24-test`,
12.755.622 B, SHA-256
`55c34a8ca35d90ba96f5703186525a31d2c6d92fe86b6e3cfee319bc5728e497`.
**PRUEBA, NO jugable.** No se afirma ninguna prueba en
hardware: esto es lo que el usuario debe probar en su
Tab S8 y reportar. Actualiza la parte exploratoria de
`GUIA-PRUEBA-GX24.md` de la rama (que venía de
Tramo 10/GX23); no cambia la APK ni el pack
instalable (base SAF + Tier 1).
**OJO certificado**: GX24 firma con certificado
distinto al de GX23: desinstalar GX23 antes de
instalar GX24 (dato de Tramo 10, se mantiene).

## Regla de oro (sin cambios)

**Copia `boot.log` ANTES de relanzar la app**: cada
arranque lo sobrescribe. Un `boot.log` perdido es una
sesión perdida. Lo mismo para el logcat de StarFoxPort:
guárdalo al final de cada sesión, antes de cerrar.

## Qué sabemos ahora (host, Tramo 11) y qué cambia

- La pantalla de **slots (SaveSelect)** ya NO es el
  atasco: en host, un toque de confirmación con el
  **stick suelto/centrado** lanza la carga del mapa
  de la partida (`loadMapForCurrentSaveGame`). El
  atasco de Tramo 10 era pulsar con el botón
  mantenido o con el stick abajo.
- **Lo que confirma**: A, o Start. **Lo que NO
  confirma**: A con el stick abajo (eso mueve el
  slot: un toque = un slot), ni B (eso vuelve atrás,
  a la pantalla anterior de slots).
- El D-pad abajo + A SÍ confirma en host (el D-pad
  no mueve la selección en esta pantalla); aun así,
  la forma recomendada es **A solo, con el stick
  suelto**, que es la probada más simple.
- Tras confirmar una partida CON guardado, el juego
  en host empieza a cargar el mapa (ficheros
  `warlock/*`, `shipbattle/*`) y luego se detiene en
  un fallo de música (canción 94): en el dispositivo
  puede verse un cambio de pantalla, un fundido, o
  quedarse en negro. **Cualquier cambio tras
  confirmar es un hito: PARA y reporta** (foto +
  logs) antes de seguir tocando.
- Una pantalla casi negra con texto pequeño NO es por
  sí sola un cuelgue: en host, varias pantallas de
  título/slots se ven así en el render sin TEV. Lo
  que decide es el sonido (sonidos de interfaz al
  moverse/confirmar) y el cambio de pantalla.
- Si la pantalla es la de slots, NO es el menú
  principal: es la siguiente. Repórtala como
  «pantalla de slots», no como «menú» a secas. Y
  la pantalla de carga del mapa NO es el juego
  jugable: es solo el intento de entrar al mundo.

## Secuencia a probar (una sesión por intento, con su boot.log)

1. Arranca GX24. Espera al título y al attract
   (película) sin tocar nada unos segundos.
2. **Start MANTENIDO 5–10 s** (no toque corto). Si
   aparece aviso de tarjeta, acéptalo con A (toque,
   stick suelto).
3. Si aparece el menú principal (opciones del título),
   confirma la primera opción con **A (toque corto,
   stick suelto)**. Si no pasa nada, repite A a
   toques (un toque por segundo, soltando entre
   toques y sin tocar el stick). No mantengas A.
4. Cuando aparezca la **pantalla de slots** (lista de
   partidas): PARA. Haz foto, anota cuántos slots se
   ven y si alguno tiene nombre/progreso, y guarda
   `boot.log` + logcat. Esa foto ya es un hito:
   repórtala antes de seguir.
5. A partir de aquí, **una sesión por intento**
   (cada intento: arrancar de nuevo hasta slots, hacer
   solo ese intento, guardar logs):
   - **Sesión A — confirmar con A (la principal)**:
     con el stick SUELTO (sin tocarlo), pulsa A a
     toque. Anota si abre algo (pantalla de nombre,
     pantalla de carga, capítulo, mundo, negro con
     música nueva) o si no pasa nada. Si abre algo:
     PARA y reporta (foto + logs) ANTES de seguir.
   - **Sesión B — confirmar con Start**: lo mismo
     con Start a toque, stick suelto.
   - **Sesión C — mover slot**: mueve el slot con el
     stick abajo a TOQUES cortos (un toque = un slot,
     soltando el stick entre toques). Anota si cambia
     el slot resaltado. NO confirmes en esta sesión.
   - **Sesión D — volver atrás con B**: pulsa B a
     toque, stick suelto. Anota si vuelve al menú
     principal del título o a otra pantalla de slots.
   - **Sesión E — slot vacío / nombre**: si hay un
     slot vacío, confírmalo con A a toque (stick
     suelto). Si aparece la pantalla de poner nombre,
     PARA y reporta (foto + logs) ANTES de confirmar
     ningún nombre.
6. Si alguna sesión llega a selección de capítulo o
   al mundo del juego: PARA, foto + `boot.log` +
   logcat, y repórtalo como hito antes de jugar.
   No avances jugando sin reportar: los logs de ese
   primer arranque son los que permiten medir el
   pack del primer mundo.

## Qué reportar por sesión (imprescindible)

- `boot.log` copiado ANTES de relanzar + logcat
  StarFoxPort de esa sesión.
- Foto de la pantalla en cada hito (menú principal,
  slots, nombre, carga del mapa, capítulo/mundo).
- Qué se ve (¿lista de slots? ¿cuántos? ¿alguno con
  nombre?) y qué se oye (¿sonidos de interfaz al
  mover/confirmar? ¿música del título? ¿música nueva
  tras confirmar? ¿silencio?).
- Qué botón se pulsó, cómo (toque / mantenido) y
  **dónde estaba el stick** (suelto / abajo /
  mantenido) y qué cambió exactamente tras pulsarlo.
- Si algo parece un cuelgue (pantalla negra sin
  sonido ni respuesta durante >30 s): anota el último
  botón que funcionó y guarda los logs igualmente.

## Qué NO hacer en estas sesiones

- No mantener botones pulsados como método principal
  (en host no confirma la salida de slots).
- **No pulsar A con el stick abajo esperando
  confirmar**: en host eso mueve el slot, no confirma.
  Para confirmar, suelta el stick y luego toca A.
- No pulsar «New Game» ni confirmar un nombre ni
  entrar al mundo sin haber reportado antes la
  pantalla de slots/nombre (se perdería el punto
  exacto del hito).
- No borrar la tarjeta ni el pack de datos entre
  sesiones salvo que se pida explícitamente: los
  slots que veas dependen de la tarjeta.
