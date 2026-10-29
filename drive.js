'use strict';
// drive.js — Fase 11: importar starfox-disco.zip desde el
// Google Drive DEL USUARIO, con SU sesion de Google.
//
// MODELO (decision del usuario 2026-10-28, reafirmada en la
// Fase 11): la pagina NO contiene ni aloja los datos del
// juego. Este modulo le pide a Google, con el permiso que el
// usuario concede en su propio navegador, el fichero
// «starfox-disco.zip» que YA vive en SU Drive privado; el
// ZIP viaja de su Drive a su navegador y se importa con el
// pipeline ZIP de la Fase 10 (SFAFS.importZip), quedando
// guardado en OPFS como cualquier importacion. Nada pasa por
// ningun servidor nuestro: no hay servidor.
//
// ============================================================
//   CONFIGURACION — LA LLAVE DE GOOGLE (un solo sitio)
//
//   Pega entre las comillas el ID de cliente de OAuth que el
//   usuario crea en SU cuenta de Google siguiendo
//   GUIA-LLAVE-GOOGLE.md (work-web/). Su formato es:
//
//     123456789012-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//       .apps.googleusercontent.com
//
//   Sin ese ID, el boton «Entrar con mi Drive y jugar» solo
//   muestra el aviso de que falta configurar la llave; el
//   resto de la pagina funciona igual que siempre. El ID de
//   cliente NO es una contrasena: es publico por diseno en
//   las aplicaciones web de Google; lo que protege el Drive
//   es la cuenta del usuario y el permiso que concede (o
//   revoca) en cada inicio de sesion.
// ============================================================
const SFA_DRIVE_CLIENT_ID = '';

window.SFADrive = (function () {
  const ZIP_NAME = 'starfox-disco.zip';
  const SCOPE = 'https://www.googleapis.com/auth/drive.readonly';
  const API = 'https://www.googleapis.com/drive/v3/files';

  function driveConfigured() {
    return /^[0-9]+-[A-Za-z0-9_-]+\.apps\.googleusercontent\.com$/
      .test(SFA_DRIVE_CLIENT_ID);
  }

  // --- Banner de estado -------------------------------------
  // Durante la fase de Drive (login, busqueda, descarga) el
  // banner se pinta directamente en el DOM: el estado de
  // SFAFS NO se toca (en particular no se pone 'cargando',
  // porque importZip/copyFileList interpretan 'cargando' como
  // copia en curso y rechazarian la importacion). Cuando la
  // importacion arranca, SFAFS/SFAUI toman el banner.
  function banner(title, detail) {
    const s = document.getElementById('status');
    const d = document.getElementById('status-detail');
    if (s) s.textContent = title;
    if (d) d.textContent = detail || '';
  }
  function fail(msg) {
    // Un solo canal de errores, el mismo que usa la Fase 5/10:
    // SFAFS en 'error' y SFAUI pinta «ERROR — ...».
    if (window.SFAFS) window.SFAFS.setStatus('error', msg);
    else banner('ERROR — ' + msg, '');
    return false;
  }

  // --- Capa de red (Drive REST) ------------------------------
  // Extraida a un objeto para poder inyectar una API falsa en
  // los tests (verify12/): mismo contrato, sin Google real.
  //   listZip(token)           -> { files: [{id, name,
  //                                modifiedTime, size}] }
  //   download(token, id, cb)  -> Blob, con cb(recibidos,
  //                                total) para el progreso.
  const net = {
    async listZip(token) {
      const q = new URLSearchParams({
        q: "name = '" + ZIP_NAME + "' and trashed = false",
        fields: 'files(id,name,modifiedTime,size)',
        orderBy: 'modifiedTime desc',
        spaces: 'drive',
      });
      const resp = await fetch(API + '?' + q.toString(), {
        headers: { Authorization: 'Bearer ' + token },
      });
      if (resp.status === 401 || resp.status === 403) {
        throw new Error('SESION');
      }
      if (!resp.ok) {
        throw new Error('Drive respondio ' + resp.status +
          ' buscando el ZIP');
      }
      return await resp.json();
    },
    async download(token, id, onProgress) {
      const resp = await fetch(API + '/' +
        encodeURIComponent(id) + '?alt=media', {
        headers: { Authorization: 'Bearer ' + token },
      });
      if (resp.status === 401 || resp.status === 403) {
        throw new Error('SESION');
      }
      if (!resp.ok) {
        throw new Error('Drive respondio ' + resp.status +
          ' descargando el ZIP');
      }
      const total = parseInt(
        resp.headers.get('Content-Length') || '0', 10);
      if (resp.body && typeof resp.body.getReader === 'function') {
        const reader = resp.body.getReader();
        const chunks = [];
        let received = 0;
        for (;;) {
          const r = await reader.read();
          if (r.done) break;
          chunks.push(r.value);
          received += r.value.length;
          if (onProgress) onProgress(received, total);
        }
        return new Blob(chunks, { type: 'application/zip' });
      }
      const blob = await resp.blob();
      if (onProgress) onProgress(blob.size, blob.size);
      return blob;
    },
  };

  // --- Flujo principal, con token ya concedido ---------------
  // Devuelve true si el juego quedo cargado. TODOS los fallos
  // dejan mensaje accionable en el estado y devuelven false;
  // la importacion solo se intenta con el ZIP COMPLETO ya
  // descargado, asi que un corte a mitad de descarga nunca
  // deja una copia parcial por buena.
  async function importWithToken(token, netImpl) {
    const nx = netImpl || net;
    banner('BUSCANDO EN TU DRIVE — ' + ZIP_NAME,
      'Consultando tu Google Drive con tu sesion…');
    let listing;
    try {
      listing = await nx.listZip(token);
    } catch (e) {
      if (e && e.message === 'SESION') {
        return fail('Google no dio acceso a tu Drive (sesion ' +
          'caducada o permiso denegado). Pulsa de nuevo «Entrar ' +
          'con mi Drive y jugar» y acepta el acceso de solo ' +
          'lectura.');
      }
      return fail('No se pudo consultar tu Drive: ' +
        (e && e.message ? e.message : String(e)) +
        '. Revisa tu conexion y vuelve a intentarlo.');
    }
    const files = (listing && listing.files) || [];
    if (!files.length) {
      return fail('No se encontro «' + ZIP_NAME + '» en tu ' +
        'Drive. Sube ese fichero a tu Google Drive (es el ZIP ' +
        'unico de tu disco; esta en tu carpeta «Star Fox ' +
        'Adventures (GameCube)») y vuelve a intentarlo.');
    }
    // files.list ya viene ordenado por modifiedTime desc, pero
    // se reelige el mas reciente por si la API falsa/real no
    // ordena: el contrato es «el mas reciente».
    let chosen = files[0];
    for (const f of files) {
      if ((f.modifiedTime || '') > (chosen.modifiedTime || '')) {
        chosen = f;
      }
    }
    let lastShown = 0;
    let blob;
    try {
      blob = await nx.download(token, chosen.id, (got, total) => {
        if (got - lastShown < 8388608 && got !== total) return;
        lastShown = got;
        banner('DESCARGANDO DE TU DRIVE — ' + ZIP_NAME,
          (got / 1048576).toFixed(0) + ' / ' +
          (total ? (total / 1048576).toFixed(0) : '¿?') +
          ' MB · el ZIP baja de tu Drive a este navegador; ' +
          'no cierres la pagina.');
      });
    } catch (e) {
      if (e && e.message === 'SESION') {
        return fail('Tu sesion de Google caduco durante la ' +
          'descarga. Pulsa de nuevo «Entrar con mi Drive y ' +
          'jugar» para renovarla y reintentar.');
      }
      return fail('La descarga desde tu Drive se corto: ' +
        (e && e.message ? e.message : String(e)) +
        '. No se importo nada; vuelve a intentarlo.');
    }
    if (!blob || !blob.size) {
      return fail('Tu Drive devolvio un fichero vacio para «' +
        ZIP_NAME + '». Revisa que el ZIP de tu Drive este ' +
        'completo y vuelve a intentarlo.');
    }
    banner('DESCARGA COMPLETA — importando el ZIP',
      (blob.size / 1048576).toFixed(0) + ' MB recibidos; la ' +
      'pagina lo descomprime y lo guarda en este navegador…');
    // El pipeline de la Fase 10 trabaja sobre File/Blob con
    // entradas perezosas por rangos: el Blob se envuelve como
    // File con nombre, sin copiar sus datos.
    const file = typeof File === 'function'
      ? new File([blob], ZIP_NAME, { type: 'application/zip' })
      : blob;
    // importZip valida ANTES de copiar y llama a SFAUI: desde
    // aqui el banner lo lleva el estado de SFAFS, como con el
    // selector de fichero.
    const ok = await window.SFAFS.importZip(file);
    if (!ok) return false; // el error concreto ya esta en el estado
    // Mismo camino que el selector ZIP de main.js tras importar.
    if (typeof window.SFAAfterDataReady === 'function') {
      window.SFAAfterDataReady();
    } else if (typeof window.SFAStart === 'function') {
      window.SFAStart();
    }
    return true;
  }

  // --- Entrada: boton «Entrar con mi Drive y jugar» ----------
  let tokenClient = null;
  let busy = false;
  function start() {
    if (busy) return false;
    if (!driveConfigured()) {
      banner('FALTA CONFIGURAR LA LLAVE DE GOOGLE',
        'Este boton necesita el ID de cliente de OAuth creado ' +
        'en TU cuenta de Google (una sola vez, unos minutos, ' +
        'gratis). Sigue la GUIA-LLAVE-GOOGLE.md del proyecto y ' +
        'esa llave quedara conectada a la pagina. Mientras ' +
        'tanto, «Elegir ZIP del disco» y «Elegir carpeta de ' +
        'datos» funcionan como siempre.');
      return false;
    }
    if (!window.SFAFS || !window.SFAModule) {
      banner('EL MOTOR AUN ESTA CARGANDO',
        'Espera a que la pagina termine de cargar el wasm y ' +
        'vuelve a pulsar el boton de Drive.');
      return false;
    }
    if (window.SFAFS.state.status === 'cargando') {
      banner('YA HAY UNA COPIA EN CURSO',
        'Espera a que termine la importacion actual.');
      return false;
    }
    if (typeof google === 'undefined' || !google.accounts ||
        !google.accounts.oauth2) {
      return fail('No se pudo cargar el inicio de sesion de ' +
        'Google (¿sin conexion o bloqueado por el navegador?). ' +
        'Revisa tu conexion y recarga la pagina.');
    }
    busy = true;
    try {
      if (!tokenClient) {
        tokenClient = google.accounts.oauth2.initTokenClient({
          client_id: SFA_DRIVE_CLIENT_ID,
          scope: SCOPE,
          callback: (resp) => {
            if (resp && resp.error) {
              busy = false;
              fail('Google no concedio el acceso (' +
                resp.error + '). Pulsa de nuevo el boton y ' +
                'acepta el permiso de solo lectura a tu Drive.');
              return;
            }
            importWithToken(resp.access_token)
              .catch((e) => fail('Fallo inesperado trayendo el ' +
                'juego de tu Drive: ' +
                (e && e.message ? e.message : String(e))))
              .finally(() => { busy = false; });
          },
          error_callback: (err) => {
            busy = false;
            const t = err && err.type ? err.type : 'desconocido';
            fail(t === 'popup_closed'
              ? 'Cerraste la ventana de Google antes de ' +
                'terminar. Pulsa de nuevo «Entrar con mi Drive ' +
                'y jugar» y completa el inicio de sesion.'
              : 'El inicio de sesion de Google fallo (' + t +
                '). Vuelve a intentarlo; si persiste, deja que ' +
                'el navegador muestre ventanas emergentes de ' +
                'accounts.google.com.');
          },
        });
      }
      banner('INICIANDO SESION CON GOOGLE',
        'Se abrira la ventana de Google: elige TU cuenta y ' +
        'acepta el acceso de solo lectura a tu Drive. Si sale ' +
        'el aviso de «aplicacion no verificada», es tu propia ' +
        'aplicacion en modo de prueba: «Configuracion ' +
        'avanzada» → «Ir al proyecto».');
      tokenClient.requestAccessToken();
    } catch (e) {
      busy = false;
      return fail('No se pudo iniciar el inicio de sesion de ' +
        'Google: ' + (e && e.message ? e.message : String(e)));
    }
    return true;
  }

  // Cableado del boton (si la pagina lo tiene).
  if (typeof document !== 'undefined' && document.getElementById) {
    const btn = document.getElementById('drive-btn');
    if (btn) btn.addEventListener('click', () => { start(); });
  }

  return {
    start, importWithToken, net, driveConfigured,
    ZIP_NAME, SCOPE,
    clientId: () => SFA_DRIVE_CLIENT_ID,
  };
})();
