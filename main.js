// main.js — Cascara web WEBFULL (Fase 3): copia adaptada de
// work-web/web/main.js (ver webfull-LEEME.md §2 para el diff).
// NO contiene datos del juego. El wasm del build COMPLETO
// (sfa-web.js, MODULARIZE SFAModule) se instancia en index.html
// y se asigna a window.SFAModule; sfa_web_load_game() devuelve
// 1 con datos validos en MEMFS y la pagina arranca el bucle rAF.
// Sin datos, la pagina muestra SIN DATOS y nunca "JUEGO CARGADO".
//
// Bucle: requestAnimationFrame -> sfa_web_frame() (UN frame,
// retorna siempre). Equivalente web de emscripten_set_main_loop.
// Pausa: visibilitychange (oculta -> sfa_web_set_paused(1),
// que cancela rumble) + beforeunload (volcado de card).
//
// Audio: AudioContext 48 kHz tras gesto del usuario.
// sfa_web_audio_push_js(samples, count): cola de
// AudioBufferSourceNode (ver audio_web.h). Si la cola
// programada supera 0,5 s, se descarta el bloque (contador
// en window.SFAAudioDropped).
//
// Input por frame (orden: mando, teclado ya aplicado por
// eventos, tactil por eventos): getGamepads()[0] si existe
// y es standard -> sfa_web_input_gamepad. El teclado y el
// tactil llegan por eventos y escriben el mismo PadState.
// Las pildoras DOM (abajo) usan los MISMOS rectangulos en
// fracciones que audio_button.h (0.44-0.56 / 0.92-0.98) y
// surround_button.h (0.31-0.43 / 0.92-0.98); al ser DOM, su
// click no llega al canvas (stopPropagation) y no roba
// input de juego. La interceptacion tactil en C++
// (input_web) queda como respaldo si el overlay DOM se
// oculta (p. ej. pantalla completa sin DOM).
//
// Rumble: sfa_web_rumble_js(on): mando 0 con actuador ->
// playEffect; sin actuador -> no-op (ver rumble_web.h).
//
// Sonda de profundidad EFB (renderer_web): al arrancar,
// prueba readPixels FLOAT y luego UNSIGNED_INT sobre un
// FBO de prueba y escribe el modo con sfa_web_depth_mode().
// El resultado se muestra en el panel de estado; la sonda
// NO prueba el EFB real del juego (eso exige el runtime
// completo y queda PENDIENTE DE VERIFICACION EN NAVEGADOR).

'use strict';

(function () {
  const $ = (id) => document.getElementById(id);
  const canvas = $('game-canvas');
  const statusEl = $('status');
  const detailEl = $('status-detail');
  const audioPill = $('pill-audio');
  const surroundPill = $('pill-surround');
  let audioCtx = null;
  let audioUntil = 0;
  let audioDropped = 0;
  let rafId = 0;
  let running = false;

  function setStatus(text, detail) {
    if (statusEl) statusEl.textContent = text;
    if (detailEl) detailEl.textContent = detail || '';
  }
  window.SFAUI = function (fsState) {
    const map = {
      'sin-datos': 'SIN DATOS — elige tu carpeta de datos',
      'cargando': 'CARGANDO — copiando a la memoria del navegador',
      'listo': 'DATOS LISTOS en memoria',
      'error': 'ERROR — ' + (fsState.error || 'ver consola'),
    };
    setStatus(map[fsState.status] || fsState.status,
      fsState.status === 'cargando'
        ? (fsState.filesCopied + ' / ' + fsState.total + ' ficheros')
        : (fsState.opfsAvailable
          ? 'Almacenamiento persistente (OPFS) disponible'
          : 'Sin OPFS: sesion sin persistencia (Guardar descarga la card)'));
    refreshPills();
  };

  // --- Audio ---
  function ensureAudio() {
    if (audioCtx) {
      if (audioCtx.state === 'suspended') audioCtx.resume();
      return;
    }
    try {
      const AC = window.AudioContext || window.webkitAudioContext;
      audioCtx = new AC({ sampleRate: 48000 });
      audioUntil = audioCtx.currentTime;
    } catch (e) { audioCtx = null; }
  }
  window.sfa_web_audio_push_js = function (samples, count) {
    if (!audioCtx) return;
    const now = audioCtx.currentTime;
    if (audioUntil < now) audioUntil = now;
    if (audioUntil - now > 0.5) { audioDropped++; return; }
    const buf = audioCtx.createBuffer(2, count, 48000);
    const l = buf.getChannelData(0), r = buf.getChannelData(1);
    for (let i = 0; i < count; i++) {
      l[i] = samples[i * 2] / 32768;
      r[i] = samples[i * 2 + 1] / 32768;
    }
    const src = audioCtx.createBufferSource();
    src.buffer = buf;
    src.connect(audioCtx.destination);
    src.start(audioUntil);
    audioUntil += count / 48000;
  };

  // --- Rumble ---
  window.sfa_web_rumble_js = function (on) {
    try {
      const pads = navigator.getGamepads ? navigator.getGamepads() : [];
      const pad = pads && pads[0];
      const act = pad && pad.vibrationActuator;
      if (!act) return;
      if (on) {
        act.playEffect({ duration: 100000, strongMagnitude: 1.0, weakMagnitude: 1.0 });
      } else if (typeof act.reset === 'function') {
        act.reset();
      } else {
        act.playEffect({ duration: 0, strongMagnitude: 0, weakMagnitude: 0 });
      }
    } catch (e) { /* sin actuador: no-op */ }
  };

  // --- Sonda de profundidad (renderer_web) ---
  function probeDepth() {
    try {
      const gl = canvas.getContext('webgl2');
      if (!gl) { setStatus('ERROR — sin WebGL2', 'Este navegador no expone WebGL2.'); return; }
      // FBO de prueba RGBA8 + DEPTH_COMPONENT24, como el EFB.
      const fbo = gl.createFramebuffer();
      const tex = gl.createTexture();
      gl.bindTexture(gl.TEXTURE_2D, tex);
      gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, 16, 16, 0, gl.RGBA, gl.UNSIGNED_BYTE, null);
      const rbo = gl.createRenderbuffer();
      gl.bindRenderbuffer(gl.RENDERBUFFER, rbo);
      gl.renderbufferStorage(gl.RENDERBUFFER, gl.DEPTH_COMPONENT24, 16, 16);
      gl.bindFramebuffer(gl.FRAMEBUFFER, fbo);
      gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.TEXTURE_2D, tex, 0);
      gl.framebufferRenderbuffer(gl.FRAMEBUFFER, gl.DEPTH_ATTACHMENT, gl.RENDERBUFFER, rbo);
      if (gl.checkFramebufferStatus(gl.FRAMEBUFFER) !== gl.FRAMEBUFFER_COMPLETE) {
        probeDone(3, 'FBO de prueba incompleto');
        return;
      }
      gl.clearColor(0, 0, 0, 1);
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
      let mode = 3;
      try {
        gl.readPixels(0, 0, 1, 1, gl.DEPTH_COMPONENT, gl.FLOAT, new Float32Array(1));
        mode = gl.getError() === gl.NO_ERROR ? 1 : 2;
      } catch (e) { mode = 2; }
      if (mode === 2) {
        try {
          gl.readPixels(0, 0, 1, 1, gl.DEPTH_COMPONENT, gl.UNSIGNED_INT, new Uint32Array(1));
          mode = gl.getError() === gl.NO_ERROR ? 2 : 3;
        } catch (e) { mode = 3; }
      }
      gl.bindFramebuffer(gl.FRAMEBUFFER, null);
      probeDone(mode, mode === 1 ? 'FLOAT' : mode === 2 ? 'UNSIGNED_INT (fallback)' : 'no disponible (copias Z8 rechazadas)');
    } catch (e) { probeDone(3, 'sonda fallo: ' + e.message); }
  }
  function probeDone(mode, label) {
    try {
      const M = window.SFAModule;
      if (M && M._sfa_web_depth_mode) M._sfa_web_depth_mode(mode);
    } catch (e) { /* wasm aun no listo: la sonda se repite tras onRuntimeInitialized */ }
    const el = $('depth-mode');
    if (el) el.textContent = 'Readback profundidad EFB: ' + label;
  }

  // --- Input: teclado ---
  document.addEventListener('keydown', (ev) => {
    if (ev.repeat) return;
    ensureAudio();
    const M = window.SFAModule;
    if (M && M.ccall) {
      try { M.ccall('sfa_web_input_key', 'number', ['string', 'number'], [ev.code, 1]); } catch (e) {}
    }
    if (['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'Space'].includes(ev.code)) ev.preventDefault();
  });
  document.addEventListener('keyup', (ev) => {
    const M = window.SFAModule;
    if (M && M.ccall) {
      try { M.ccall('sfa_web_input_key', 'number', ['string', 'number'], [ev.code, 0]); } catch (e) {}
    }
  });

  // --- Input: tactil (Pointer Events, fracciones) ---
  function pointerFrac(ev) {
    const rect = canvas.getBoundingClientRect();
    return {
      x: (ev.clientX - rect.left) / Math.max(1, rect.width),
      y: (ev.clientY - rect.top) / Math.max(1, rect.height),
    };
  }
  canvas.addEventListener('pointerdown', (ev) => {
    ensureAudio();
    canvas.setPointerCapture(ev.pointerId);
    const f = pointerFrac(ev);
    const M = window.SFAModule;
    if (M && M.ccall) {
      try { M.ccall('sfa_web_input_pointer_down', 'number', ['number', 'number', 'number'], [ev.pointerId, f.x, f.y]); } catch (e) {}
    }
  });
  canvas.addEventListener('pointermove', (ev) => {
    const f = pointerFrac(ev);
    const M = window.SFAModule;
    if (M && M.ccall) {
      try { M.ccall('sfa_web_input_pointer_move', 'number', ['number', 'number', 'number'], [ev.pointerId, f.x, f.y]); } catch (e) {}
    }
  });
  function pointerUp(ev) {
    const f = pointerFrac(ev);
    const M = window.SFAModule;
    if (M && M.ccall) {
      try { M.ccall('sfa_web_input_pointer_up', 'number', ['number', 'number', 'number'], [ev.pointerId, f.x, f.y]); } catch (e) {}
    }
  }
  canvas.addEventListener('pointerup', pointerUp);
  canvas.addEventListener('pointercancel', pointerUp);

  // --- Pildoras DOM (equivalentes sin Java) ---
  function refreshPills() {
    if (!surroundPill) return;
    const on = window.SFAFS ? window.SFAFS.surroundGet() : false;
    surroundPill.textContent = on ? 'SURROUND ON' : 'SURROUND OFF';
    surroundPill.dataset.state = on ? 'on' : 'off';
    if (audioPill) {
      const st = window.SFAFS ? window.SFAFS.state.status : 'sin-datos';
      audioPill.textContent = st === 'listo' ? 'AUDIO LISTO'
        : st === 'cargando' ? 'AUDIO…' : st === 'error' ? 'AUDIO ERROR' : 'AÑADIR AUDIO';
      audioPill.dataset.state = st;
    }
  }
  if (audioPill) audioPill.addEventListener('click', (ev) => {
    ev.stopPropagation();
    ensureAudio();
    $('audio-folder').click();
  });
  if (surroundPill) surroundPill.addEventListener('click', (ev) => {
    ev.stopPropagation();
    const cur = window.SFAFS.surroundGet();
    const next = !cur;
    // Persistir ANTES de aplicar (mismo orden que native-lib).
    if (window.SFAFS.surroundSet(next)) {
      const M = window.SFAModule;
      if (M && M._sfa_web_set_surround) M._sfa_web_set_surround(next ? 1 : 0);
    }
    refreshPills();
  });

  // --- Selectores de carpeta ---
  function filesFromInput(inputEl) {
    const out = [];
    for (const file of inputEl.files) {
      // webkitRelativePath: 'carpeta/sys/main.dol' -> rel 'sys/main.dol'.
      const parts = file.webkitRelativePath.split('/');
      parts.shift();
      out.push({ rel: parts.join('/'), file });
    }
    return out;
  }
  const dataInput = $('data-folder');
  if (dataInput) dataInput.addEventListener('change', async () => {
    ensureAudio();
    const files = filesFromInput(dataInput);
    if (!files.length) {
      // Fase 5: elegir una carpeta vacia ya no es silencioso.
      setStatus('SIN DATOS — la carpeta elegida esta vacia',
        'Elige la carpeta de datos que contiene sys/ y files/.');
      return;
    }
    // Fase 5: si la copia fallo, copyFileList ya dejo el error
    // concreto en el estado; no pisarlo con LoadGame.
    const okLoad = await window.SFAFS.copyFileList(files);
    if (okLoad) afterDataReady();
  });
  const audioInput = $('audio-folder');
  if (audioInput) audioInput.addEventListener('change', async () => {
    // Overlay de audio: solo ficheros bajo audio/ (no reimporta sys/files).
    const files = filesFromInput(audioInput)
      .filter((f) => f.rel.startsWith('audio/'))
      .map((f) => ({ rel: f.rel, file: f.file }));
    if (!files.length) { setStatus('ERROR — carpeta de audio sin audio/', ''); return; }
    await window.SFAFS.copyFileList(files, null, { partial: true });
    refreshPills();
  });
  const saveBtn = $('save-btn');
  if (saveBtn) saveBtn.addEventListener('click', async () => {
    const where = await window.SFAFS.dumpCard();
    setStatus('Partida guardada (' + where + ')', '');
  });

  function afterDataReady() {
    const M = window.SFAModule;
    if (M && M._sfa_web_load_game) {
      const ok = M._sfa_web_load_game();
      if (ok) { setStatus('JUEGO CARGADO', ''); startLoop(); }
      else setStatus('ERROR — LoadGame fallo', 'Ver consola: /sfa-data/sys/main.dol ausente o DOL invalido.');
    } else {
      setStatus('ERROR — wasm sin sfa_web_load_game', 'El modulo cargado no es el build completo.');
    }
    refreshPills();
  }

  // --- Bucle principal ---
  function frame() {
    if (!running) return;
    const M = window.SFAModule;
    if (M) {
      // Gamepad por frame (via principal).
      try {
        const pads = navigator.getGamepads ? navigator.getGamepads() : [];
        const pad = pads && pads[0];
        if (pad && M._sfa_web_input_gamepad && M._malloc && M.HEAPF32 && M.HEAP32) {
          const btnPtr = M._malloc(16 * 4);
          const prsPtr = M._malloc(16 * 4);
          const axPtr = M._malloc(4 * 4);
          for (let i = 0; i < 16; i++) {
            const b = pad.buttons[i];
            M.HEAPF32[(btnPtr >> 2) + i] = b ? b.value : 0;
            M.HEAP32[(prsPtr >> 2) + i] = b && b.pressed ? 1 : 0;
          }
          for (let i = 0; i < 4; i++) M.HEAPF32[(axPtr >> 2) + i] = pad.axes[i] || 0;
          M._sfa_web_input_gamepad(btnPtr, prsPtr, 16, axPtr, 4);
          M._free(btnPtr); M._free(prsPtr); M._free(axPtr);
        }
      } catch (e) { /* mando no estandar: se ignora este frame */ }
      if (M._sfa_web_frame) M._sfa_web_frame();
      // Drenaje de pildoras tactiles (respaldo C++): si un toque
      // en canvas disparo una pildora, actuar aqui.
      try {
        if (M._sfa_web_input_take_audio_trigger && M._sfa_web_input_take_audio_trigger()) {
          $('audio-folder').click();
        }
        if (M._sfa_web_input_take_surround_trigger && M._sfa_web_input_take_surround_trigger()) {
          surroundPill.click();
        }
      } catch (e) {}
    }
    rafId = requestAnimationFrame(frame);
  }
  function startLoop() {
    if (running) return;
    running = true;
    const M = window.SFAModule;
    if (M && M._sfa_web_set_paused) M._sfa_web_set_paused(0);
    rafId = requestAnimationFrame(frame);
  }

  // --- Ciclo de vida: visibilitychange = APP_CMD_PAUSE ---
  document.addEventListener('visibilitychange', async () => {
    const M = window.SFAModule;
    if (document.hidden) {
      if (M && M._sfa_web_set_paused) M._sfa_web_set_paused(1);
      window.sfa_web_rumble_js(false);
      await window.SFAFS.dumpCard(); // volcado explicito al ocultar
    } else {
      if (M && M._sfa_web_set_paused) M._sfa_web_set_paused(0);
    }
  });
  window.addEventListener('beforeunload', () => {
    // Sincrono no garantizado: el volcado fiable es el de
    // visibilitychange + el boton Guardar. No se promete mas.
    const M = window.SFAModule;
    if (M && M._sfa_web_set_paused) M._sfa_web_set_paused(1);
  });
  window.addEventListener('resize', () => {
    const M = window.SFAModule;
    if (M && M._sfa_web_resize) {
      M._sfa_web_resize(canvas.clientWidth, canvas.clientHeight);
    } else if (M && M._sfa_web_input_set_viewport) {
      M._sfa_web_input_set_viewport(canvas.clientWidth, canvas.clientHeight);
    }
  });

  // Arranque WEBFULL (diferencia contra la Fase 2): la sonda de
  // profundidad NO corre al cargar el script, sino DESPUES de
  // sfa_web_init() (ver index.html): el contexto WebGL2 lo crea
  // Emscripten en Init() y la sonda debe reutilizar ese mismo
  // contexto (getContext('webgl2') devuelve el mismo objeto),
  // no crear uno propio antes. SFAInitWeb() la invoca el
  // script de arranque de index.html tras instanciar el modulo.
  // Ademas, la Fase 2 nunca llamaba a sfa_web_init() desde el
  // navegador: aqui SI se llama (tamano del canvas + surround
  // desde localStorage, persistido antes de aplicar).
  window.SFAInitWeb = function () {
    const M = window.SFAModule;
    if (M && M._sfa_web_init) {
      M._sfa_web_init(canvas.width, canvas.height);
      if (M._sfa_web_set_surround && window.SFAFS) {
        M._sfa_web_set_surround(window.SFAFS.surroundGet() ? 1 : 0);
      }
    }
    probeDepth();
    refreshPills();
  };
  window.SFAProbeDepth = probeDepth;
  refreshPills();
  window.SFAStart = async function () {
    const restored = await window.SFAFS.loadFromOpfs();
    if (restored) afterDataReady();
    else if (window.SFAFS.state.status !== 'error') {
      // Fase 5: restaurar sin copia guardada ya no es un no-op
      // silencioso (era indistinguible de "la pagina no va").
      setStatus('SIN COPIA GUARDADA — elige tu carpeta de datos',
        'Todavia no hay datos guardados en este navegador. Pulsa ' +
        '«Elegir carpeta de datos» y elige la carpeta que contiene ' +
        'sys/ y files/ (tu copia del disco). Los datos no estan en ' +
        'el servidor: se cargan desde tu equipo y quedan solo en ' +
        'este navegador.');
    }
  };
})();
