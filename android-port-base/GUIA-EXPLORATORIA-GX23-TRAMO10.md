# Guía exploratoria GX23 — Tramo 10 (BORRADOR, no integrar sin revisión del coordinador)

APK: GX23 de prueba, v14 / `0.14.0-gx23-test`,
12.747.430 B, SHA-256
`e0a51117ab11dfa821017894d354a8d4cf76c12f820a7218712a7d23c6315663`.
**PRUEBA, NO jugable.** No se afirma ninguna prueba en
hardware: esto es lo que el usuario debe probar en su
Tab S8 y reportar. Sustituye/actualiza la parte
exploratoria de `GUIA-PRUEBA-GX23.md` de la rama (que
venía de Tramo 9/GX22); no cambia la APK ni el pack
instalable (base SAF + Tier 1).

## Regla de oro (sin cambios)

**Copia `boot.log` ANTES de relanzar la app**: cada
arranque lo sobrescribe. Un `boot.log` perdido es una
sesión perdida. Lo mismo para el logcat de StarFoxPort:
guárdalo al final de cada sesión, antes de cerrar.

## Qué sabemos ahora (host, Tramo 10) y por qué cambia la secuencia

- Tras el título y el attract, el menú principal
  (TitleMenu) se supera confirmando su primera opción
  (selección inicial 0): el juego pasa a la pantalla
  de **selección de partida (slots)**, luego a la de
  **poner nombre** si se confirma un slot, y vuelve a
  la de slots. En host eso llevó decenas de pulsos
  repetidos, no un solo toque.
- **No mantengas el botón pulsado**: en host, un botón
  mantenido mueve la selección pero no confirma la
  salida de la pantalla de slots. Cada acción debe ser
  **pulsar y soltar** (un toque corto por acción),
  con pausas para ver qué cambia.
- Una pantalla casi negra con texto pequeño NO es por
  sí sola un cuelgue: en host, varias pantallas de
  título/slots se ven así en el render sin TEV. Lo
  que decide es el sonido (sonidos de interfaz al
  moverse/confirmar) y el cambio de pantalla.
- Si la pantalla es la de slots, NO es el menú
  principal: es la siguiente. Repórtala como
  «pantalla de slots», no como «menú» a secas.

## Secuencia a probar (una sesión por intento, con su boot.log)

1. Arranca GX23. Espera al título y al attract
   (película) sin tocar nada unos segundos.
2. **Start MANTENIDO 5–10 s** (no toque corto). Si
   aparece aviso de tarjeta, acéptalo con A (toque).
3. Si aparece el menú principal (opciones del título),
   confirma la primera opción con **A (toque corto)**.
   Si no pasa nada, repite A a toques (varios
   segundos, un toque por segundo, soltando entre
   toques). No mantengas A.
4. Cuando aparezca la **pantalla de slots** (lista de
   partidas): PARA. Haz foto, anota cuántos slots se
   ven y si alguno tiene nombre/progreso, y guarda
   `boot.log` + logcat. Esa foto ya es un hito:
   repórtala antes de seguir.
5. A partir de aquí, **una sesión por intento**
   (cada intento: arrancar de nuevo hasta slots, hacer
   solo ese intento, guardar logs):
   - **Sesión A — mover + confirmar**: mueve el slot
     con D-pad abajo a toques (uno por toque, soltando)
     y confirma con A a toque. Anota si cambia el
     slot resaltado y si abre algo (nombre, capítulo,
     aviso).
   - **Sesión B — stick**: lo mismo con el stick
     abajo a toques (no mantenido).
   - **Sesión C — slot vacío / nombre**: si hay un
     slot vacío, confírmalo con A a toque. Si aparece
     la pantalla de poner nombre, PARA y reporta
     (foto + logs) ANTES de confirmar ningún nombre.
   - **Sesión D — volver atrás**: pulsa B a toque.
     Anota si vuelve al menú principal del título.
   - **Sesión E — Z y Start**: pulsa Z a toque; en
     otra sesión, Start a toque. Anota cualquier
     cambio (en host, B/Z no cambiaron nada medible
     en la pantalla post-attract; aquí se comprueba
     en slots).
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
  slots, nombre, retorno al título, capítulo/mundo).
- Qué se ve (¿lista de slots? ¿cuántos? ¿alguno con
  nombre?) y qué se oye (¿sonidos de interfaz al
  mover/confirmar? ¿música del título? ¿silencio?).
- Qué botón se pulsó, cómo (toque / mantenido) y qué
  cambió exactamente tras pulsarlo.
- Si algo parece un cuelgue (pantalla negra sin
  sonido ni respuesta durante >30 s): anota el último
  botón que funcionó y guarda los logs igualmente.

## Qué NO hacer en estas sesiones

- No mantener botones pulsados como método principal
  (en host no confirma la salida de slots).
- No pulsar «New Game» ni confirmar un nombre ni
  entrar al mundo sin haber reportado antes la
  pantalla de slots/nombre (se perdería el punto
  exacto del hito).
- No borrar la tarjeta ni el pack de datos entre
  sesiones salvo que se pida explícitamente: los
  slots que veas dependen de la tarjeta.
