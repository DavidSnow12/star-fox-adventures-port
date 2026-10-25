#!/usr/bin/env python3
"""Extractor de audio de Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL).

Convierte los streams .adp del disco (ADPCM DTK de GameCube, bloques de
32 bytes) a WAV PCM 16-bit estereo a 32000 Hz, y las muestras MusyX
(.sam/.sdi) a WAV PCM 16-bit mono a la frecuencia indicada en cada entrada
del directorio de muestras. Los bancos MusyX (.pro/.poo), el wad MIDI
(midi.wad), las tablas de triggers (Music.bin/Sfx.bin/Streams.bin) y los
buffers Empty*.bin no se pueden decodificar a audio con la informacion
disponible y se conservan en bruto, documentados, sin inventar contenido.

Uso:
    python3 extract_audio.py --disc <raiz-del-disco> --out <carpeta-salida>
        [--only all|streams|musyx] [--jobs N] [--rate 32000]

<raiz-del-disco> es la carpeta que contiene ``files/`` (o directamente la
carpeta ``files/``). No hay rutas absolutas hardcodeadas: todas las rutas
se derivan de --disc y --out. Solo lectura sobre el disco.

Formato DTK (.adp), verificado empiricamente contra el decodificador
adpcm_dtk de FFmpeg y contra la estructura de bloques del disco:
  * Cada bloque tiene 32 bytes: [hdrL, hdrR, hdrL, hdrR, 28 bytes de datos].
    Los bytes 2 y 3 son copias redundantes de 0 y 1 (verificado en los
    17.072.128 bloques de los 958 ficheros: siempre iguales).
  * Cada byte de datos aporta un nibble por canal: nibble bajo = canal L,
    nibble alto = canal R. 28 bytes -> 28 muestras estereo por bloque.
  * Cabecera por canal: nibble alto = indice de coeficientes (0-3 en este
    disco; >=4 se comporta como predictor nulo, igual que FFmpeg),
    nibble bajo = exponente de escala: escala = 4096 >> exp (exp 0-12 en
    este disco; 13-15 dan escala 0).
  * Predictor (coeficientes en /2048, estado en punto fijo x2048):
        P = trunc((c1*X1 + c2*X2) / 2048); P = clamp(P, -32768*2048, 32767*2048)
        X = nibble*escala*2048 + P
        X = clamp(X, -32768*2048, 32767*2048)
        muestra = floor(X / 2048)
    con (c1, c2) = {0: (0,0), 1: (1920,0), 2: (3680,-1664), 3: (3136,-1760)}.
    Validacion contra FFmpeg: la saturacion es en DOS etapas (predictor y
    estado); sin saturar el predictor, los ataques fuertes a fondo de
    escala divergen hasta 16.520 LSB. Con ella: datos aleatorios 97,7 %
    bit-exactos, max. 1 LSB; ficheros reales th03u_sa 96,71 % y an1301
    95,61 %, max. 4 LSB. El residuo esta en el redondeo interno de FFmpeg,
    no en los coeficientes (variar un coeficiente en 1/2048 rompe la
    decodificacion por la resonancia).
  * Frecuencia: 32000 Hz, la frecuencia fija del streaming DTK de GameCube
    (el codigo del juego no fija otra frecuencia para streams; Streams.bin
    no contiene duraciones: su campo lengthRaw es un punto de fundido de
    musica, no la duracion del fichero).

Formato DSP-ADPCM MusyX (.sam + .sdi), verificado contra el contexto de
bucle de Table B (ver RESUMEN.md):
  * .sdi, Table A: entradas de 32 bytes terminadas en 0xFFFFFFFF:
    [id u16 BE][pad u16][offset u32 BE][desconocido u32][pitch u8][pad u8]
    [frecuencia u16 BE][n_muestras u32 BE][bucle_inicio u32 BE]
    [bucle_longitud u32 BE][offset_TableB u32 BE].
    Cada muestra ocupa ceil(n_muestras/14)*8 bytes en .sam, redondeado
    a multiplo de 32 para la siguiente.
  * .sdi, Table B: entradas de 40 bytes:
    [desconocido u16 = 8][ps_inicial u8][ps_bucle u8][hist_bucle2 s16]
    [hist_bucle1 s16][16 coeficientes s16 = 8 pares (c0, c1)].
    El ps_inicial coincide con el primer byte de la muestra en .sam en
    las 1472/1472 muestras (verificacion exhaustiva).
  * Decodificacion DSP estandar, predictor en /2048:
        muestra = clamp((nibble << escala) + ((h1*c0 + h2*c1 + 1024) >> 11))
    con pred = cabecera >> 4 (0-7 en este disco) y escala = cabecera & 0xF.
    El bucle NO se repite en el WAV: se decodifica una sola pasada y los
    parametros de bucle quedan en el inventario.
  * Los bucles se validan asi: decodificar hasta bucle_inicio debe dejar
    el estado (hist1, hist2) igual al contexto de bucle de Table B. El
    redondeo del desplazamiento es "half up" (+1024 antes de >> 11):
    321/321 muestras con bucle coinciden EXACTAMENTE (320 no triviales +
    1 con bucle_inicio = 0). Otras variantes quedan muy atras: floor
    29/321, trunc 21/321, ceil 27/321, half_away 298/321, half_even
    303/321. Ver RESUMEN.md para los numeros.

Inventario (CSV):
  * ``fuente`` es siempre relativa a la raiz del disco pasada en --disc
    (p. ej. ``files/streams/AN/an1301.adp`` o ``files/audio/starfoxm.sam``).
  * Para filas ADP y brutos, ``tamano``/``sha1_fuente`` son del fichero
    completo. Para filas MusyX, son del RECORTE de la muestra dentro de
    .sam (``offset_en_fuente`` = offset del recorte, ``tamano`` =
    ceil(n_muestras/14)*8 bytes); el .sam completo queda en brutos/ con
    su propio SHA-1.

Solo biblioteca estandar de Python 3. Compatible con Windows (el worker
de multiprocessing es una funcion de nivel superior y todo el codigo
corre bajo ``if __name__ == "__main__"``).
"""

import argparse
import csv
import hashlib
import multiprocessing as mp
import os
import shutil
import struct
import sys
from array import array

# ---------------------------------------------------------------------------
# Utilidades
# ---------------------------------------------------------------------------

def sha1_file(path):
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def sha1_bytes(data):
    return hashlib.sha1(data).hexdigest()


def be16(buf, off):
    return struct.unpack_from(">H", buf, off)[0]


def be32(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def bes16(buf, off):
    return struct.unpack_from(">h", buf, off)[0]


def write_wav(path, samples, channels, rate):
    """Escribe PCM 16-bit little-endian. ``samples`` es array('h')."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if sys.byteorder == "big":
        samples = array("h", samples)
        samples.byteswap()
    data = samples.tobytes()
    header = struct.pack(
        "<4sI4s4sIHHIIHH4sI",
        b"RIFF", 36 + len(data), b"WAVE", b"fmt ", 16, 1,
        channels, rate, rate * channels * 2, channels * 2, 16,
        b"data", len(data),
    )
    with open(path, "wb") as f:
        f.write(header)
        f.write(data)
    return len(header) + len(data)


# ---------------------------------------------------------------------------
# DTK (.adp)
# ---------------------------------------------------------------------------

# Coeficientes del predictor DTK en /2048, por indice (nibble alto).
DTK_COEF = {
    0: (0, 0),
    1: (1920, 0),
    2: (3680, -1664),
    3: (3136, -1760),
}

# Tabla de nibbles con signo por byte: indice -> (nibble_bajo, nibble_alto).
_SIGNED_PAIRS = []
for _b in range(256):
    _lo = _b & 0x0F
    _hi = _b >> 4
    _SIGNED_PAIRS.append((_lo - 16 if _lo >= 8 else _lo,
                          _hi - 16 if _hi >= 8 else _hi))

_X_MAX = 32767 * 2048
_X_MIN = -32768 * 2048


def decode_dtk(data):
    """Decodifica un .adp completo.

    Devuelve (muestras_intercaladas array('h'), es_dual_mono).
    Lanza ValueError si el tamano no es multiplo de 32.
    """
    if len(data) % 32 != 0:
        raise ValueError("tamano .adp no multiplo de 32: %d" % len(data))
    nblocks = len(data) // 32
    # 2 canales x 2 bytes por muestra x 28 muestras por bloque.
    out = array("h", bytes(4 * nblocks * 28))
    table = _SIGNED_PAIRS
    dual_mono = True
    x1l = x2l = x1r = x2r = 0
    idx = 0
    for b in range(nblocks):
        base = b * 32
        hdr_l = data[base]
        hdr_r = data[base + 1]
        c1l, c2l = DTK_COEF.get(hdr_l >> 4, (0, 0))
        c1r, c2r = DTK_COEF.get(hdr_r >> 4, (0, 0))
        scale_l = 4096 >> (hdr_l & 0x0F)
        scale_r = 4096 >> (hdr_r & 0x0F)
        for j in range(28):
            lo, hi = table[data[base + 4 + j]]
            # Canal L (nibble bajo).
            v = c1l * x1l + c2l * x2l
            q = v // 2048 if v >= 0 else -((-v) // 2048)
            # Etapa 1: saturación del término predictor (ver docstring).
            if q > _X_MAX:
                q = _X_MAX
            elif q < _X_MIN:
                q = _X_MIN
            x = lo * scale_l * 2048 + q
            if x > _X_MAX:
                x = _X_MAX
            elif x < _X_MIN:
                x = _X_MIN
            sl = x // 2048
            x2l = x1l
            x1l = x
            # Canal R (nibble alto).
            v = c1r * x1r + c2r * x2r
            q = v // 2048 if v >= 0 else -((-v) // 2048)
            if q > _X_MAX:
                q = _X_MAX
            elif q < _X_MIN:
                q = _X_MIN
            x = hi * scale_r * 2048 + q
            if x > _X_MAX:
                x = _X_MAX
            elif x < _X_MIN:
                x = _X_MIN
            sr = x // 2048
            x2r = x1r
            x1r = x
            if sl != sr:
                dual_mono = False
            out[idx] = sl
            out[idx + 1] = sr
            idx += 2
    return out, dual_mono


def _adp_worker(args):
    """Worker de multiprocessing: decodifica un .adp y escribe su WAV."""
    src_path, rel, out_path, rate = args
    with open(src_path, "rb") as f:
        data = f.read()
    samples, dual_mono = decode_dtk(data)
    nframes = len(samples) // 2
    wav_size = write_wav(out_path, samples, 2, rate)
    return {
        # fuente siempre relativa a la raiz del disco pasada en --disc
        # (los .adp viven en files/streams/ dentro del disco).
        "fuente": "files/" + rel,
        "tamano": len(data),
        "sha1_fuente": sha1_bytes(data),
        "tamano_salida": wav_size,
        "sha1_salida": sha1_file(out_path),
        "formato": "WAV PCM16 DTK-ADPCM",
        "frecuencia": rate,
        "canales": 2,
        "muestras": nframes,
        "duracion_s": round(nframes / rate, 3),
        "muestra_id": "",
        "offset_en_fuente": "",
        "loop_inicio": "",
        "loop_longitud": "",
        "nombre_h_bak": "",
        "notas": "dual-mono (L==R en todas las muestras)" if dual_mono else "",
        "_out_path": out_path,
    }


# ---------------------------------------------------------------------------
# MusyX (.sam/.sdi)
# ---------------------------------------------------------------------------

def parse_sdir(sdi):
    """Devuelve (entradas Table A, entradas Table B por indice).

    Cada entrada Table A es un dict con id, offset, pitch, frecuencia,
    n_muestras, bucle_inicio, bucle_longitud, offset_tableb. Cada entrada
    Table B es un dict con ps_inicial, ps_bucle, hist_bucle1, hist_bucle2
    y coefs (lista de 8 pares).
    """
    entries = []
    off = 0
    while off + 4 <= len(sdi) and be32(sdi, off) != 0xFFFFFFFF:
        entries.append({
            "id": be16(sdi, off),
            "offset": be32(sdi, off + 4),
            "pitch": sdi[off + 12],
            "frecuencia": be16(sdi, off + 14),
            "n_muestras": be32(sdi, off + 16),
            "bucle_inicio": be32(sdi, off + 20),
            "bucle_longitud": be32(sdi, off + 24),
            "offset_tableb": be32(sdi, off + 28),
        })
        off += 32
    if off + 4 > len(sdi):
        raise ValueError(".sdi sin terminador 0xFFFFFFFF en Table A")
    tableb = []
    tb_start = off + 4
    for e in entries:
        tb = sdi[e["offset_tableb"]:e["offset_tableb"] + 40]
        if len(tb) < 40:
            raise ValueError("Table B truncada para la muestra %d" % e["id"])
        vals = struct.unpack(">16h", tb[8:40])
        tableb.append({
            "ps_inicial": tb[2],
            "ps_bucle": tb[3],
            "hist_bucle2": bes16(tb, 4),
            "hist_bucle1": bes16(tb, 6),
            "coefs": [(vals[i], vals[i + 1]) for i in range(0, 16, 2)],
        })
    return entries, tableb


def decode_dsp(data, coefs, nsamp):
    """Decodifica DSP-ADPCM estandar (predictor /2048, redondeo half-up)."""
    out = array("h", bytes(2 * nsamp))
    hist1 = hist2 = 0
    i = 0
    n = 0
    while n < nsamp and i + 8 <= len(data):
        hdr = data[i]
        pred = hdr >> 4
        scale = hdr & 0x0F
        if pred >= len(coefs):
            raise ValueError("indice de predictor DSP fuera de rango: %d" % pred)
        c0, c1 = coefs[pred]
        for k in range(14):
            if n >= nsamp:
                break
            byte = data[i + 1 + k // 2]
            nib = (byte >> 4) if k % 2 == 0 else (byte & 0x0F)
            if nib >= 8:
                nib -= 16
            s = (nib << scale) + ((hist1 * c0 + hist2 * c1 + 1024) >> 11)
            if s > 32767:
                s = 32767
            elif s < -32768:
                s = -32768
            out[n] = s
            hist2 = hist1
            hist1 = s
            n += 1
        i += 8
    if n != nsamp:
        raise ValueError("muestra DSP truncada: %d/%d muestras" % (n, nsamp))
    return out


def parse_h_bak(path):
    """Devuelve {sound_id: nombre} a partir de starfox.h.bak."""
    import re
    mapping = {}
    with open(path, "r", encoding="latin1", errors="replace") as f:
        for line in f:
            m = re.match(r"#define\s+(SFX\w+)\s+(\d+)", line)
            if m:
                mapping[int(m.group(2))] = m.group(1)
    return mapping


def sanitize_name(name):
    return "".join(ch if (ch.isalnum() or ch in "_.-") else "_" for ch in name)


# ---------------------------------------------------------------------------
# Analisis estructural (.pro/.poo, triggers) - sin decodificacion semantica
# ---------------------------------------------------------------------------

def parse_pool(poo):
    """Analisis estructural de un .poo MusyX.

    Devuelve un dict con los offsets de cabecera, el numero de SoundMacros
    recorridas por sus campos de tamano y si el recorrido aterriza
    exactamente en el offset de tablas (con el terminador 0xFFFFFFFF).
    """
    if len(poo) < 16:
        return {"error": "fichero demasiado corto"}
    macro_off = be32(poo, 0)
    tables_off = be32(poo, 4)
    keymaps_off = be32(poo, 8)
    layers_off = be32(poo, 12)
    # El recorrido de macros termina en keymaps_off cuando tables_off es 0
    # (grupo sin seccion de tablas) y en tables_off en caso contrario.
    end = tables_off if tables_off else keymaps_off
    off = macro_off
    count = 0
    while off + 8 <= end:
        size = be32(poo, off)
        if size < 8 or off + size > end:
            break
        off += size
        count += 1
    gap = poo[off:end] if off <= end else b""
    return {
        "macro_off": macro_off,
        "tables_off": tables_off,
        "keymaps_off": keymaps_off,
        "layers_off": layers_off,
        "macros": count,
        "macro_walk_end": off,
        "macro_walk_ok": off + 4 == end and gap == b"\xff\xff\xff\xff",
        "gap_len": end - off,
    }


def parse_project(pro):
    """Analisis estructural minimo de un .pro MusyX: palabras de cabecera."""
    words = [be32(pro, i) for i in range(0, min(40, len(pro)), 4)]
    return {"header_words": words}


def parse_streams_bin(data):
    """Registros StreamEntry de 22 bytes (decomp: audio_stream.c)."""
    recs = []
    off = 0
    while off + 22 <= len(data):
        name = data[off + 6:off + 21].split(b"\x00")[0].decode("latin1")
        recs.append({
            "id": be16(data, off),
            "fade": data[off + 2],
            "vol": data[off + 3],
            "length_raw": be16(data, off + 4),
            "name": name,
            "flag": data[off + 21],
        })
        off += 22
    return recs, len(data) - off


# ---------------------------------------------------------------------------
# Programa principal
# ---------------------------------------------------------------------------

def resolve_files_dir(disc):
    if os.path.isdir(os.path.join(disc, "files")):
        return os.path.join(disc, "files")
    if os.path.isdir(os.path.join(disc, "streams")):
        return disc
    raise SystemExit("no se encontro files/ ni streams/ bajo --disc: %s" % disc)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--disc", required=True, help="raiz del disco (contiene files/)")
    ap.add_argument("--out", required=True, help="carpeta de salida")
    ap.add_argument("--only", choices=["all", "streams", "musyx"], default="all")
    ap.add_argument("--jobs", type=int, default=0,
                    help="procesos paralelos para .adp (0 = todos los nucleos)")
    ap.add_argument("--rate", type=int, default=32000,
                    help="frecuencia de muestreo de los streams DTK (def. 32000)")
    ap.add_argument("--inventory", default="",
                    help="ruta del CSV de inventario (def.: <assets>/inventarios/audio.csv "
                         "cuando --out es <assets>/extraidos/audio; si no, <out>/audio.csv)")
    args = ap.parse_args(argv)

    files_dir = resolve_files_dir(args.disc)
    out_root = args.out
    streams_out = os.path.join(out_root, "streams")
    musyx_out = os.path.join(out_root, "musyx")
    brutos_out = os.path.join(out_root, "brutos")
    for d in (streams_out, musyx_out, brutos_out):
        os.makedirs(d, exist_ok=True)

    rows = []
    stats = {"adp_ok": 0, "adp_fail": [], "musyx_ok": 0, "musyx_fail": [],
             "dual_mono": 0, "brutos": 0}

    # --- 1. Streams .adp -> WAV -------------------------------------------
    if args.only in ("all", "streams"):
        adp_files = []
        for root, _dirs, names in os.walk(os.path.join(files_dir, "streams")):
            for name in sorted(names):
                if name.lower().endswith(".adp"):
                    src = os.path.join(root, name)
                    rel = os.path.relpath(src, files_dir).replace(os.sep, "/")
                    dst = os.path.join(streams_out,
                                       os.path.relpath(src, os.path.join(files_dir, "streams")))
                    dst = os.path.splitext(dst)[0] + ".wav"
                    adp_files.append((src, rel, dst, args.rate))
        print("ADP: %d ficheros" % len(adp_files), flush=True)
        njobs = args.jobs if args.jobs > 0 else (mp.cpu_count() or 1)
        if njobs > 1 and len(adp_files) > 1:
            ctx = mp.get_context()
            with ctx.Pool(njobs) as pool:
                for i, row in enumerate(pool.imap_unordered(_adp_worker, adp_files, chunksize=4)):
                    row["salida"] = os.path.relpath(row["_out_path"], out_root).replace(os.sep, "/")
                    del row["_out_path"]
                    rows.append(row)
                    stats["adp_ok"] += 1
                    if "dual-mono" in row["notas"]:
                        stats["dual_mono"] += 1
                    if (i + 1) % 100 == 0:
                        print("  ADP %d/%d" % (i + 1, len(adp_files)), flush=True)
        else:
            for src, rel, dst, rate in adp_files:
                try:
                    row = _adp_worker((src, rel, dst, rate))
                except Exception as exc:  # noqa: BLE001 - se registra y se sigue
                    stats["adp_fail"].append((rel, str(exc)))
                    continue
                row["salida"] = os.path.relpath(dst, out_root).replace(os.sep, "/")
                del row["_out_path"]
                rows.append(row)
                stats["adp_ok"] += 1
                if "dual-mono" in row["notas"]:
                    stats["dual_mono"] += 1
        print("ADP OK: %d, fallos: %d, dual-mono: %d"
              % (stats["adp_ok"], len(stats["adp_fail"]), stats["dual_mono"]), flush=True)
        for rel, err in stats["adp_fail"]:
            print("  FALLO ADP %s: %s" % (rel, err), flush=True)

    # --- 2. MusyX .sam/.sdi -> WAV por muestra ----------------------------
    if args.only in ("all", "musyx"):
        audio_dir = os.path.join(files_dir, "audio")
        h_bak = parse_h_bak(os.path.join(audio_dir, "starfox.h.bak"))
        for grp in ("starfoxm", "starfoxs"):
            sdi_path = os.path.join(audio_dir, grp + ".sdi")
            sam_path = os.path.join(audio_dir, grp + ".sam")
            with open(sdi_path, "rb") as f:
                sdi = f.read()
            with open(sam_path, "rb") as f:
                sam = f.read()
            entries, tableb = parse_sdir(sdi)
            print("%s: %d muestras en Table A" % (grp, len(entries)), flush=True)
            for e, tb in zip(entries, tableb):
                sid = e["id"]
                name = h_bak.get(sid)
                stem = ("%04d_%s" % (sid, sanitize_name(name))) if name else ("sample_%04d" % sid)
                dst = os.path.join(musyx_out, grp, stem + ".wav")
                frames = (e["n_muestras"] + 13) // 14
                data = sam[e["offset"]:e["offset"] + frames * 8]
                try:
                    if sam[e["offset"]] != tb["ps_inicial"]:
                        raise ValueError("ps_inicial no coincide con .sam")
                    samples = decode_dsp(data, tb["coefs"], e["n_muestras"])
                    wav_size = write_wav(dst, samples, 1, e["frecuencia"])
                except Exception as exc:  # noqa: BLE001
                    stats["musyx_fail"].append(("%s:%d" % (grp, sid), str(exc)))
                    continue
                rows.append({
                    "fuente": "files/audio/%s.sam" % grp,
                    "tamano": len(data),
                    "sha1_fuente": sha1_bytes(data),
                    "salida": os.path.relpath(dst, out_root).replace(os.sep, "/"),
                    "tamano_salida": wav_size,
                    "sha1_salida": sha1_file(dst),
                    "formato": "WAV PCM16 DSP-ADPCM (MusyX)",
                    "frecuencia": e["frecuencia"],
                    "canales": 1,
                    "muestras": e["n_muestras"],
                    "duracion_s": round(e["n_muestras"] / e["frecuencia"], 3) if e["frecuencia"] else "",
                    "muestra_id": sid,
                    "offset_en_fuente": e["offset"],
                    "loop_inicio": e["bucle_inicio"] if e["bucle_longitud"] else "",
                    "loop_longitud": e["bucle_longitud"] if e["bucle_longitud"] else "",
                    "nombre_h_bak": name or "",
                    "notas": ("pitch=%d" % e["pitch"])
                             + ("; bucle (no repetido en el WAV)" if e["bucle_longitud"] else ""),
                })
                stats["musyx_ok"] += 1
            print("%s OK: %d, fallos: %d"
                  % (grp, stats["musyx_ok"], len(stats["musyx_fail"])), flush=True)

    # --- 3. Brutos (sin decodificar) ---------------------------------------
    brutos = []
    audio_dir = os.path.join(files_dir, "audio")
    for rel, nota in [
        ("audio/starfoxm.sam", "banco de muestras MusyX (contenedor de los WAV musyx/)"),
        ("audio/starfoxm.sdi", "directorio de muestras MusyX (Table A/B)"),
        ("audio/starfoxm.pro", "proyecto MusyX (solo analisis estructural; resto en bruto)"),
        ("audio/starfoxm.poo", "pool MusyX/SoundMacros (solo analisis estructural; resto en bruto)"),
        ("audio/starfoxs.sam", "banco de muestras MusyX (contenedor de los WAV musyx/)"),
        ("audio/starfoxs.sdi", "directorio de muestras MusyX (Table A/B)"),
        ("audio/starfoxs.pro", "proyecto MusyX (solo analisis estructural; resto en bruto)"),
        ("audio/starfoxs.poo", "pool MusyX/SoundMacros (solo analisis estructural; resto en bruto)"),
        ("audio/midi.wad", "wad MIDI MusyX (sin MThd; formato de eventos propietario, no decodificado)"),
        ("audio/data/Music.bin", "tabla de triggers de musica"),
        ("audio/data/Sfx.bin", "tabla de triggers SFX (entradas de 32 bytes)"),
        ("audio/data/Streams.bin", "tabla de streams (entradas de 22 bytes; indice parcial, ver RESUMEN)"),
    ]:
        src = os.path.join(files_dir, rel)
        if os.path.exists(src):
            dst = os.path.join(brutos_out, os.path.basename(rel))
            shutil.copyfile(src, dst)
            brutos.append((rel, src, dst, nota))
    for i in range(8):
        rel = "audio/data/Empty%d.bin" % i
        src = os.path.join(files_dir, rel)
        if os.path.exists(src):
            dst = os.path.join(brutos_out, "Empty%d.bin" % i)
            shutil.copyfile(src, dst)
            brutos.append((rel, src, dst,
                           "buffer identico en los 8 ficheros (256 KiB de ASCII imprimible aleatorio)"))
    musyxbin_dir = os.path.join(files_dir, "musyxbin")
    if os.path.isdir(musyxbin_dir):
        n_musyxbin = sum(len(names) for _r, _d, names in os.walk(musyxbin_dir))
        print("musyxbin/: %d ficheros (vacio en este disco)" % n_musyxbin, flush=True)
    for rel, src, dst, nota in brutos:
        rows.append({
            "fuente": "files/" + rel,
            "tamano": os.path.getsize(src),
            "sha1_fuente": sha1_file(src),
            "salida": os.path.relpath(dst, out_root).replace(os.sep, "/"),
            "tamano_salida": os.path.getsize(dst),
            "sha1_salida": sha1_file(dst),
            "formato": "raw (sin decodificar)",
            "frecuencia": "",
            "canales": "",
            "muestras": "",
            "duracion_s": "",
            "muestra_id": "",
            "offset_en_fuente": "",
            "loop_inicio": "",
            "loop_longitud": "",
            "nombre_h_bak": "",
            "notas": nota,
        })
        stats["brutos"] += 1

    # --- 4. Inventario ------------------------------------------------------
    if args.inventory:
        inv_path = args.inventory
    else:
        out_norm = out_root.rstrip(os.sep)
        if (os.path.basename(out_norm) == "audio"
                and os.path.basename(os.path.dirname(out_norm)) == "extraidos"):
            inv_path = os.path.join(os.path.dirname(os.path.dirname(out_norm)),
                                    "inventarios", "audio.csv")
        else:
            inv_path = os.path.join(out_root, "audio.csv")
    os.makedirs(os.path.dirname(inv_path), exist_ok=True)
    fields = ["fuente", "tamano", "sha1_fuente", "salida", "tamano_salida",
              "sha1_salida", "formato", "frecuencia", "canales", "muestras",
              "duracion_s", "muestra_id", "offset_en_fuente", "loop_inicio",
              "loop_longitud", "nombre_h_bak", "notas"]
    rows.sort(key=lambda r: (r["salida"]))
    with open(inv_path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fields, extrasaction="ignore")
        w.writeheader()
        w.writerows(rows)
    print("Inventario: %s (%d filas)" % (inv_path, len(rows)), flush=True)
    print("RESUMEN: ADP ok=%d fallos=%d dual-mono=%d | MusyX ok=%d fallos=%d | brutos=%d"
          % (stats["adp_ok"], len(stats["adp_fail"]), stats["dual_mono"],
             stats["musyx_ok"], len(stats["musyx_fail"]), stats["brutos"]), flush=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
