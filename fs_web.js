// fs_web.js — Carga de datos del usuario a MEMFS + OPFS.
//
// MODELO (decision del usuario 2026-10-28): el usuario carga
// SUS propios ficheros desde SU equipo. Nada se sube a ningun
// servidor: todo ocurre en el navegador (File API / OPFS /
// MEMFS del wasm). Este fichero NO contiene datos del juego.
//
// Flujo:
//   1. Usuario importa SUS datos por una de dos vias:
//      a. Carpeta de datos (input webkitdirectory; NO se usa
//         showDirectoryPicker en este build).
//      b. Fase 10: UN fichero ZIP con el disco completo
//         (starfox-disco.zip: sys/ y files/ en la raiz del ZIP,
//         o bajo una unica carpeta envoltorio). Es la via sin
//         friccion en movil, donde elegir carpetas es torpe.
//         Fase 12: la raiz de datos se detecta a CUALQUIER
//         profundidad (ver findDataRoot): tambien vale el ZIP
//         del paquete PC, que lleva el disco en
//         StarFox-PC/data/sys/main.dol, o cualquier carpeta
//         que contenga el disco dentro de otras carpetas.
//         El ZIP se descomprime DENTRO del navegador (parser
//         propio del directorio central + DecompressionStream
//         nativo; sin librerias externas) y sus entradas entran
//         en copyFileList como File perezosos: mismo destino,
//         misma validacion, mismo progreso.
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
    // Fase 10: progreso tambien en bytes (una copia del disco
    // son ~790 MB; el contador de ficheros solo no basta para
    // saber si avanza cuando copia ficheros grandes).
    bytesCopied: 0, totalBytes: 0,
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
  //
  // Fase 12: deteccion PROFUNDA de la raiz. La version de la
  // Fase 5 solo reubicaba el PRIMER candidato y en la practica
  // cubria un envoltorio; pero hay contenedores legitimos con
  // el disco a mas niveles (el ZIP del paquete PC lo lleva en
  // 'StarFox-PC/data/sys/main.dol', dos niveles) y el usuario
  // no tiene por que conocer ni corregir la estructura de lo
  // que elige. Regla: cualquier ruta cuyos DOS ULTIMOS
  // componentes sean exactamente 'sys' y 'main.dol'
  // (componentes completos; sin distinguir mayusculas) marca
  // una raiz candidata, con prefijo = lo anterior a 'sys/'.
  // Si hay varias candidatas, gana: (1) la que tenga
  // directorio hermano 'files/', (2) la que tenga mas
  // ficheros DEL DISCO bajo su raiz (los que cuelgan
  // directamente de su 'sys/' o su 'files/', que son los que
  // se copiarian si ganara; contar todo el subarbol haria
  // ganar siempre a la candidata mas superficial, porque las
  // anidadas tambien cuelgan de ella), (3) en empate, la mas
  // superficial.
  // Al reubicar desde un contenedor (prefijo no vacio) se
  // copia SOLO lo que cuelga de 'sys/' y 'files/' de esa
  // raiz: el resto del contenedor (el lanzador del paquete
  // PC, su manifest.json, ficheros ajenos) se ignora. Con la
  // raiz en '' (el disco ya en la raiz de lo elegido) la
  // lista pasa intacta, como siempre.
  function findDataRoot(files) {
    const prefixes = new Set();
    for (const f of files) {
      const parts = f.rel.split('/');
      const n = parts.length;
      if (n >= 2 &&
          parts[n - 2].toLowerCase() === 'sys' &&
          parts[n - 1].toLowerCase() === 'main.dol') {
        prefixes.add(n === 2 ? '' : parts.slice(0, n - 2).join('/') + '/');
      }
    }
    if (!prefixes.size) return null;
    let best = null;
    for (const prefix of prefixes) {
      let count = 0;
      let hasFiles = false;
      for (const f of files) {
        if (prefix && !f.rel.startsWith(prefix)) continue;
        const rel = prefix ? f.rel.slice(prefix.length) : f.rel;
        const top = rel.split('/')[0].toLowerCase();
        if (top !== 'sys' && top !== 'files') continue;
        count++;
        if (top === 'files') hasFiles = true;
      }
      const depth = prefix ? prefix.split('/').filter(Boolean).length : 0;
      if (!best ||
          (hasFiles !== best.hasFiles ? hasFiles :
            count !== best.count ? count > best.count :
            depth < best.depth)) {
        best = { prefix, hasFiles, count, depth };
      }
    }
    return best.prefix;
  }
  function rebaseToDataRoot(files) {
    const prefix = findDataRoot(files);
    if (prefix === null || prefix === '') return files;
    return files
      .filter((f) => f.rel.startsWith(prefix))
      .map((f) => Object.assign({}, f,
        { rel: f.rel.slice(prefix.length) }))
      .filter((f) => {
        const top = f.rel.split('/')[0].toLowerCase();
        return top === 'sys' || top === 'files';
      });
  }
  // Fase 12: resumen de lo que SI se vio en lo elegido, para
  // que el error de «sin sys/main.dol» sea accionable de
  // verdad: nombra las primeras carpetas/ficheros de primer
  // nivel presentes (las carpetas con '/' final).
  function seenSummary(files) {
    const seen = [];
    let more = false;
    for (const f of files) {
      const parts = f.rel.split('/');
      const label = parts.length > 1 ? parts[0] + '/' : parts[0];
      if (!label || seen.indexOf(label) >= 0) continue;
      if (seen.length >= 6) { more = true; break; }
      seen.push(label);
    }
    if (!seen.length) return 'dentro no hay ningun fichero';
    return 'dentro hay: ' + seen.join(', ') + (more ? ', …' : '');
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
        // Fase 12: el error nombra lo que SI se vio dentro,
        // para que el usuario distinga «elegi otra cosa» de
        // «la pagina no encuentra mi disco».
        setStatus('error',
          'Lo elegido no contiene sys/main.dol en ningun nivel: ' +
          seenSummary(files) + '. Elige el ZIP completo del disco ' +
          '(starfox-disco.zip) o una carpeta que contenga el disco ' +
          '(sys/ y files/), aunque este dentro de otras carpetas.');
        return false;
      }
      // El runtime abre el DOL por ruta exacta: normaliza su rel.
      dol.rel = 'sys/main.dol';
      if (!files.some((f) => f.rel.startsWith('files/'))) {
        setStatus('error',
          'Lo elegido no contiene la carpeta files/. Importa la ' +
          'copia completa: la carpeta con sys/main.dol y files/, ' +
          'o el ZIP completo del disco.');
        return false;
      }
    }
    state.total = files.length;
    state.filesCopied = 0;
    state.bytesCopied = 0;
    state.totalBytes = files.reduce((a, f) =>
      a + ((f.file && typeof f.file.size === 'number') ? f.file.size
        : (typeof f.size === 'number' ? f.size : 0)), 0);
    setStatus('cargando');
    let currentRel = '';
    let lastUiBytes = 0;
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
        state.bytesCopied += bytes.length;
        state.progress = state.filesCopied / Math.max(1, state.total);
        if (onProgress) onProgress(state.filesCopied, state.total);
        else if ((state.filesCopied % 50 === 0 ||
                  state.bytesCopied - lastUiBytes >= 33554432) &&
                 typeof window.SFAUI === 'function') {
          // Contador visible durante la copia: cada 50 ficheros
          // o cada ~32 MB (los ficheros grandes del ZIP tambien
          // hacen avanzar el contador).
          lastUiBytes = state.bytesCopied;
          window.SFAUI(state);
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
  // --- ZIP del disco (Fase 10) --------------------------------
  // Parser propio del directorio central (sin librerias
  // externas alojadas fuera): EOCD clasico y ZIP64 (localizador
  // + registro, y extra 0x0001 por entrada). Cada entrada se lee
  // de forma perezosa: el Blob original se trocea por rangos
  // (slice) y el metodo 8 se infla con la API nativa
  // DecompressionStream('deflate-raw'); el metodo 0 (stored) se
  // copia tal cual. Nunca se descomprime el ZIP entero en
  // memoria: como mucho una entrada inflada a la vez.
  function zu16(b, o) { return b[o] | (b[o + 1] << 8); }
  function zu32(b, o) {
    return (b[o] | (b[o + 1] << 8) | (b[o + 2] << 16) |
      (b[o + 3] << 24)) >>> 0;
  }
  function zu64(b, o) { return zu32(b, o) + zu32(b, o + 4) * 4294967296; }
  async function readRange(blob, off, len) {
    return new Uint8Array(await blob.slice(off, off + len).arrayBuffer());
  }
  async function zipEntries(blob) {
    if (!blob || typeof blob.slice !== 'function' || !blob.size) {
      throw new Error('no es un fichero legible');
    }
    const size = blob.size;
    // EOCD: 22 B fijos + comentario de hasta 65535 B al final.
    const tailLen = Math.min(size, 22 + 65535);
    const tail = await readRange(blob, size - tailLen, tailLen);
    let eocd = -1;
    for (let i = tail.length - 22; i >= 0; i--) {
      if (zu32(tail, i) === 0x06054b50 &&
          zu16(tail, i + 20) === tail.length - (i + 22)) { eocd = i; break; }
    }
    if (eocd < 0) throw new Error('no parece un fichero ZIP (sin directorio central)');
    const eocdAbs = size - tailLen + eocd;
    if (zu16(tail, eocd + 4) !== 0) throw new Error('ZIP multiparte no soportado');
    let count = zu16(tail, eocd + 10);
    let cdSize = zu32(tail, eocd + 12);
    let cdOff = zu32(tail, eocd + 16);
    if (count === 0xffff || cdSize === 0xffffffff || cdOff === 0xffffffff) {
      // ZIP64: localizador de 20 B justo antes del EOCD.
      if (eocdAbs < 20) throw new Error('ZIP64 sin localizador');
      const loc = await readRange(blob, eocdAbs - 20, 20);
      if (zu32(loc, 0) !== 0x07064b50) throw new Error('ZIP64 sin localizador');
      const z64off = zu64(loc, 8);
      const z64 = await readRange(blob, z64off, 56);
      if (zu32(z64, 0) !== 0x06064b50) throw new Error('registro ZIP64 invalido');
      // Layout ZIP64 EOCD: tras firma(4)+tamano(8)+versiones(4)
      // y discos(8) van entradas-en-disco(8)@24, entradas(8)@32,
      // tamano CD(8)@40 y offset CD(8)@48.
      count = zu64(z64, 32); cdSize = zu64(z64, 40); cdOff = zu64(z64, 48);
    }
    if (count > 200000) throw new Error('demasiadas entradas en el ZIP (' + count + ')');
    const cd = await readRange(blob, cdOff, cdSize);
    const dec = new TextDecoder('utf-8');
    const out = [];
    let p = 0;
    for (let n = 0; n < count; n++) {
      if (p + 46 > cd.length || zu32(cd, p) !== 0x02014b50) {
        throw new Error('directorio central corrupto (entrada ' + n + ')');
      }
      const method = zu16(cd, p + 10);
      let comp = zu32(cd, p + 20);
      let uncomp = zu32(cd, p + 24);
      const nameLen = zu16(cd, p + 28);
      const extraLen = zu16(cd, p + 30);
      const commentLen = zu16(cd, p + 32);
      const diskStart = zu16(cd, p + 34);
      let localOff = zu32(cd, p + 42);
      if (diskStart !== 0) throw new Error('ZIP multiparte no soportado');
      const name = dec.decode(cd.subarray(p + 46, p + 46 + nameLen))
        .replace(/\\/g, '/');
      if (comp === 0xffffffff || uncomp === 0xffffffff ||
          localOff === 0xffffffff) {
        // Extra ZIP64 (0x0001): valores en orden fijo (sin
        // comprimir, comprimido, offset local, disco) y SOLO
        // para los campos marcados 0xFFFFFFFF en el central.
        let q = p + 46 + nameLen;
        const qEnd = q + extraLen;
        while (q + 4 <= qEnd) {
          const id = zu16(cd, q); const sz = zu16(cd, q + 2);
          if (id === 0x0001) {
            let r = q + 4;
            if (uncomp === 0xffffffff) { uncomp = zu64(cd, r); r += 8; }
            if (comp === 0xffffffff) { comp = zu64(cd, r); r += 8; }
            if (localOff === 0xffffffff) { localOff = zu64(cd, r); r += 8; }
            break;
          }
          q += 4 + sz;
        }
      }
      p += 46 + nameLen + extraLen + commentLen;
      if (name.endsWith('/')) continue; // directorio
      if (!name || name.startsWith('/') ||
          name.split('/').indexOf('..') >= 0) continue; // ruta insegura
      out.push({
        rel: name, method: method, compSize: comp,
        uncompSize: uncomp, localOff: localOff,
      });
    }
    return out;
  }
  async function inflateEntry(blob, e) {
    const lh = await readRange(blob, e.localOff, 30);
    if (lh.length < 30 || zu32(lh, 0) !== 0x04034b50) {
      throw new Error('cabecera local corrupta en «' + e.rel + '»');
    }
    const dataOff = e.localOff + 30 + zu16(lh, 26) + zu16(lh, 28);
    const raw = await readRange(blob, dataOff, e.compSize);
    if (e.method === 0) return raw;
    if (e.method === 8) {
      if (typeof DecompressionStream !== 'function') {
        throw new Error('este navegador no sabe descomprimir ZIP ' +
          '(sin DecompressionStream); importa por carpeta en su lugar');
      }
      const stream = new Blob([raw]).stream()
        .pipeThrough(new DecompressionStream('deflate-raw'));
      const out = new Uint8Array(
        await new Response(stream).arrayBuffer());
      if (e.uncompSize && out.length !== e.uncompSize) {
        throw new Error('«' + e.rel + '» descomprime a un tamano ' +
          'inesperado (' + out.length + ' != ' + e.uncompSize + ')');
      }
      return out;
    }
    throw new Error('«' + e.rel + '» usa un metodo de compresion ' +
      'no soportado (' + e.method + ')');
  }
  async function importZip(blob, onProgress) {
    // Devuelve lo que devuelva copyFileList (true = datos en
    // MEMFS listos para sfa_web_load_game). La validacion de
    // raiz (sys/main.dol presente, a cualquier profundidad:
    // Fase 12) la hace copyFileList ANTES de copiar, usando
    // solo los nombres: si el ZIP no vale, no se descomprime ni
    // se copia nada.
    if (state.status === 'cargando') return false; // copia en curso
    let entries;
    try {
      entries = await zipEntries(blob);
    } catch (e) {
      setStatus('error',
        'No se pudo leer el ZIP: ' +
        (e && e.message ? e.message : String(e)) +
        '. Elige el fichero starfox-disco.zip completo, el que ' +
        'contiene el disco (sys/ y files/).');
      return false;
    }
    if (!entries.length) {
      setStatus('error',
        'El ZIP no contiene ficheros. Elige el ZIP completo del ' +
        'disco (el que contiene sys/ y files/, a cualquier ' +
        'profundidad).');
      return false;
    }
    const files = entries.map((e) => ({
      rel: e.rel,
      size: e.uncompSize,
      file: {
        size: e.uncompSize,
        // File perezoso: copyFileList solo llama a arrayBuffer()
        // cuando copia ESTA entrada; solo entonces se lee e
        // infla. El ArrayBuffer devuelto es una copia exacta de
        // los bytes descomprimidos.
        arrayBuffer: () => inflateEntry(blob, e).then((u8) =>
          u8.buffer.slice(u8.byteOffset,
            u8.byteOffset + u8.byteLength)),
      },
    }));
    return await copyFileList(files, onProgress);
  }
  async function hasSavedCopy() {
    // Deteccion barata de copia persistida (para el boton
    // «▸ Jugar» de main.js): basta con que OPFS contenga
    // sfa-data/sys/main.dol; no rehidrata nada.
    if (!state.opfsAvailable) return false;
    try {
      const root = await opfsRoot();
      const dataDir = await root.getDirectoryHandle('sfa-data');
      const sysDir = await dataDir.getDirectoryHandle('sys');
      await sysDir.getFileHandle('main.dol');
      return true;
    } catch (e) { return false; }
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
    // Fase 10: importacion por ZIP y deteccion de copia guardada.
    importZip, hasSavedCopy, zipList: zipEntries,
  };
})();
