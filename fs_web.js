// fs_web.js — Carga de datos del usuario a MEMFS + OPFS.
//
// MODELO (decision del usuario 2026-10-28): el usuario carga
// SUS propios ficheros desde SU equipo. Nada se sube a ningun
// servidor: todo ocurre en el navegador (File API / OPFS /
// MEMFS del wasm). Este fichero NO contiene datos del juego.
//
// Flujo:
//   1. Usuario elige carpeta de datos (input webkitdirectory;
//      NO se usa showDirectoryPicker en este build).
//   2. Cada fichero se copia a OPFS (persistente, Chromium)
//      y a MEMFS (Module.FS.writeFile) ANTES del primer frame.
//   3. El juego corre contra MEMFS (/sfa-data/...).
//   4. Memory card: MEMFS -> OPFS en "Guardar partida" y en
//      visibilitychange/beforeunload (volcado EXPLICITO;
//      sin el, la partida se pierde al cerrar la pestana).
//   5. Sin OPFS (fallback): solo MEMFS; "Guardar partida"
//      descarga memcard-a.raw al equipo del usuario.
//
// Rutas MEMFS (ver fs_web.h): /sfa-data/sys/main.dol,
// /sfa-data/files/..., /sfa-data/audio/..., /memcard-a.raw.
// La carpeta elegida debe contener sys/main.dol y files/;
// audio/ es opcional (sin el, el bridge queda inerte como
// en Android sin Pack B con audio).
//
// Estado: window.SFAFS expone {status, progress, error,
// opfsAvailable} y main.js lo refleja en el indicador.
// status: 'sin-datos' | 'cargando' | 'listo' | 'error'.
// 'listo' significa: datos en MEMFS y main.dol presente.
// NO significa juego corriendo: en el build standalone el
// runtime no esta enlazado (main_web devuelve juego=false)
// y main.js lo muestra como "capa lista, runtime pendiente".

'use strict';

window.SFAFS = (function () {
  const DOL = '/sfa-data/sys/main.dol';
  const CARD = '/memcard-a.raw';
  const state = {
    status: 'sin-datos', progress: 0, total: 0, error: '',
    opfsAvailable: typeof navigator !== 'undefined' &&
      !!navigator.storage && typeof navigator.storage.getDirectory === 'function',
    filesCopied: 0,
  };
  function setStatus(s, err) {
    state.status = s;
    if (err !== undefined) state.error = err;
    if (typeof window.SFAUI === 'function') window.SFAUI(state);
  }
  function memfsWrite(path, bytes) {
    // Module.FS: API estable de Emscripten para MEMFS.
    const Module = window.SFAModule;
    if (!Module || !Module.FS) throw new Error('wasm FS no listo');
    const parts = path.split('/').filter(Boolean);
    let dir = '/';
    for (let i = 0; i < parts.length - 1; i++) {
      dir += (dir === '/' ? '' : '/') + parts[i];
      try { Module.FS.mkdir(dir); } catch (e) { /* ya existe */ }
    }
    Module.FS.writeFile(path, bytes);
  }
  function memfsExists(path) {
    try {
      const Module = window.SFAModule;
      return !!Module && !!Module.FS && Module.FS.analyzePath(path).exists;
    } catch (e) { return false; }
  }
  async function opfsRoot() {
    return await navigator.storage.getDirectory();
  }
  async function opfsWrite(relPath, bytes) {
    // relPath como 'sfa-data/files/...' dentro del OPFS root.
    const root = await opfsRoot();
    const parts = relPath.split('/').filter(Boolean);
    let dir = root;
    for (let i = 0; i < parts.length - 1; i++) {
      dir = await dir.getDirectoryHandle(parts[i], { create: true });
    }
    const fh = await dir.getFileHandle(parts[parts.length - 1], { create: true });
    const w = await fh.createWritable();
    await w.write(bytes);
    await w.close();
  }
  // Fase 5: si el usuario eligio una carpeta SUPERIOR a la de
  // datos (p. ej. la que contiene a su carpeta de datos), las
  // rutas llegan como 'algo/sys/main.dol'. Reubica la lista a
  // la carpeta que contiene directamente sys/main.dol para que
  // la eleccion siga siendo valida en vez de fallar en silencio.
  function rebaseToDataRoot(files) {
    if (files.some((f) => f.rel.toLowerCase() === 'sys/main.dol')) {
      return files;
    }
    const cand = files.find((f) => /\/sys\/main\.dol$/i.test(f.rel));
    if (!cand) return files;
    const prefix =
      cand.rel.slice(0, cand.rel.length - 'sys/main.dol'.length);
    return files
      .filter((f) => f.rel.startsWith(prefix))
      .map((f) => ({ rel: f.rel.slice(prefix.length), file: f.file }));
  }
  async function copyFileList(files, onProgress, opts) {
    // files: [{rel: 'sys/main.dol', file: File|Blob}] con rel
    // relativo a la raiz de la carpeta elegida.
    // opts.partial: copia parcial (overlay de audio): sin
    // validacion de raiz de datos ni reubicacion.
    const partial = !!(opts && opts.partial);
    if (state.status === 'cargando') return false; // copia en curso
    if (!partial) {
      // Validacion ANTES de copiar (Fase 5): sin raiz de datos
      // no se copia nada y el error dice que carpeta elegir.
      files = rebaseToDataRoot(files);
      const dol = files.find(
        (f) => f.rel.toLowerCase() === 'sys/main.dol');
      if (!dol) {
        setStatus('error',
          'La carpeta elegida no contiene sys/main.dol. Elige la ' +
          'carpeta de datos que contiene directamente sys/ y files/ ' +
          '(la raiz de tu copia del disco), no una carpeta superior ' +
          'ni la carpeta files/ sola.');
        return false;
      }
      // El runtime abre el DOL por ruta exacta: normaliza su rel.
      dol.rel = 'sys/main.dol';
      if (!files.some((f) => f.rel.startsWith('files/'))) {
        setStatus('error',
          'La carpeta elegida no contiene la carpeta files/. Elige ' +
          'la carpeta de datos completa: debe contener sys/main.dol ' +
          'y files/.');
        return false;
      }
    }
    state.total = files.length;
    state.filesCopied = 0;
    setStatus('cargando');
    let currentRel = '';
    try {
      for (const f of files) {
        currentRel = f.rel;
        const bytes = new Uint8Array(await f.file.arrayBuffer());
        const memPath = '/sfa-data/' + f.rel;
        memfsWrite(memPath, bytes);
        if (state.opfsAvailable) {
          try { await opfsWrite('sfa-data/' + f.rel, bytes); }
          catch (e) { /* OPFS opcional: MEMFS ya tiene el dato */ }
        }
        state.filesCopied++;
        state.progress = state.filesCopied / Math.max(1, state.total);
        if (onProgress) onProgress(state.filesCopied, state.total);
        else if (state.filesCopied % 50 === 0 &&
                 typeof window.SFAUI === 'function') {
          window.SFAUI(state); // contador visible durante la copia
        }
      }
    } catch (e) {
      // Fase 5: antes la excepcion quedaba sin capturar y la
      // pagina se quedaba en CARGANDO para siempre, sin mensaje.
      setStatus('error',
        'Fallo copiando «' + currentRel + '»: ' +
        (e && e.message ? e.message : String(e)) +
        '. Revisa que la carpeta sea legible y que haya memoria ' +
        'libre, y vuelve a elegirla.');
      return false;
    }
    if (partial) {
      setStatus(memfsExists(DOL) ? 'listo' : 'sin-datos');
      return true;
    }
    if (!memfsExists(DOL)) {
      setStatus('error', 'Falta sys/main.dol en la carpeta elegida.');
      return false;
    }
    setStatus('listo');
    return true;
  }
  async function loadFromOpfs() {
    // Rehidrata MEMFS desde la copia OPFS persistida (sin
    // volver a pedir la carpeta). Devuelve false si no hay
    // copia o si OPFS no esta disponible.
    if (!state.opfsAvailable) return false;
    try {
      const root = await opfsRoot();
      const dataDir = await root.getDirectoryHandle('sfa-data');
      const files = [];
      async function walk(dir, prefix) {
        for await (const [name, handle] of dir.entries()) {
          if (handle.kind === 'file') {
            files.push({ rel: prefix + name, file: await handle.getFile() });
          } else if (handle.kind === 'directory') {
            await walk(handle, prefix + name + '/');
          }
        }
      }
      await walk(dataDir, '');
      if (files.length === 0) return false;
      return await copyFileList(files);
    } catch (e) {
      return false; // sin copia OPFS: el usuario elegira carpeta
    }
  }
  async function dumpCard() {
    // Volcado EXPLICITO de la memory card MEMFS -> OPFS (o
    // descarga si no hay OPFS). Devuelve 'opfs' | 'descarga' | 'sin-card'.
    const Module = window.SFAModule;
    if (!Module || !Module.FS || !memfsExists(CARD)) return 'sin-card';
    const bytes = Module.FS.readFile(CARD);
    if (state.opfsAvailable) {
      try {
        const root = await opfsRoot();
        const fh = await root.getFileHandle('memcard-a.raw', { create: true });
        const w = await fh.createWritable();
        await w.write(bytes);
        await w.close();
        return 'opfs';
      } catch (e) { /* cae a descarga */ }
    }
    const blob = new Blob([bytes], { type: 'application/octet-stream' });
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob);
    a.download = 'memcard-a.raw';
    a.click();
    setTimeout(() => URL.revokeObjectURL(a.href), 5000);
    return 'descarga';
  }
  function surroundGet() {
    try {
      return window.localStorage.getItem('sfa_settings/audio_surround_enabled') === '1';
    } catch (e) { return false; }
  }
  function surroundSet(enabled) {
    try {
      window.localStorage.setItem(
        'sfa_settings/audio_surround_enabled', enabled ? '1' : '0');
      return true;
    } catch (e) { return false; }
  }
  return {
    state, setStatus, memfsExists, copyFileList, loadFromOpfs,
    dumpCard, surroundGet, surroundSet, DOL, CARD,
  };
})();
