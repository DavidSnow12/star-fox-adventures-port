#!/usr/bin/env python3
"""Genera la tabla ID -> WAV para el bridge de audio (Fase 14).

Entradas (solo lectura):
  - <disc>/files/audio/data/Streams.bin : 905 registros x 22 B
      [id u16 BE][campo u16 BE][lengthRaw u16 BE][nombre 16 B].
      El id es el que AudioStream_Play (0x8000D220) busca por
      comparacion directa con el u16 inicial de cada registro
      (verificado en el codigo huesped recompilado).
  - <disc>/files/audio/data/Sfx.bin : 1205 registros x 32 B
      [id u16 BE][volBase u8][0][pitchBase u8][0][? u16]
      [? u16][muestra0 u16][muestra1 u16][muestra2 u16]
      [muestra3 u16]... Los 4 campos de muestra estan en el
      rango de IDs de muestra MusyX (0..832 observados); el
      valor 0 se interpreta como "sin muestra" (247 triggers
      tienen los 4 campos a 0: si 0 fuese una muestra real,
      247 triggers distintos sonarian igual, lo cual no es
      creible; queda documentado como interpretacion, no
      como hecho verificado contra el runtime MusyX).
  - <repo>/analisis/audio.csv : inventario de WAV extraidos.
      Streams: fuente files/streams/DIR/f.adp -> salida
      streams/DIR/f.wav (32.000 Hz estereo). MusyX: muestra_id
      global (starfoxm 0..593, starfoxs 594..1471) -> salida
      musyx/...wav (mono, frecuencia de inventario).

Salidas:
  - app/src/main/cpp/audio/audio_id_map.h : tablas C++ para
    el bridge (sin dependencias, solo la tabla).
  - herramientas/audio/audio_id_map.csv : misma tabla en
    CSV legible (tipo,id,wav[,muestras]).

Emparejamiento stream: nombre Streams.bin "DIR/nombre" contra
"DIR/base" del inventario, insensible a mayusculas (el disco
tiene variantes como GB/bird frente a GB/Bird.adp). Si el
nombre exacto no existe, se prueba prefijo unico (nombres
truncados a 15 caracteres en el campo de 16 B). Lo que no
empareja queda en la lista de sin resolver: nunca se inventa
un WAV.

Uso:
  python3 gen_audio_id_map.py --disc <raiz-disco> --repo <repo>
    [--inventory <csv>] [--out-h <header>] [--out-csv <csv>]
"""

import argparse
import csv
import os
import struct
import sys


def parse_streams(path):
    d = open(path, "rb").read()
    recs = []
    for i in range(len(d) // 22):
        r = d[i * 22:(i + 1) * 22]
        sid, _f2, length_raw = struct.unpack_from(">HHH", r, 0)
        name = r[6:22].split(b"\x00")[0].decode("ascii", "replace")
        recs.append((sid, length_raw, name))
    return recs


def parse_sfx(path):
    d = open(path, "rb").read()
    recs = []
    for i in range(len(d) // 32):
        r = d[i * 32:(i + 1) * 32]
        tid = struct.unpack_from(">H", r, 0)[0]
        vol = r[2]
        pitch = r[4]
        samples = [struct.unpack_from(">H", r, off)[0]
                   for off in (10, 12, 14, 16)]
        recs.append((tid, vol, pitch, samples))
    return recs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--disc", required=True)
    ap.add_argument("--repo", required=True)
    ap.add_argument("--inventory", default=None)
    ap.add_argument("--out-h", default=None)
    ap.add_argument("--out-csv", default=None)
    args = ap.parse_args()

    inv_path = args.inventory or os.path.join(args.repo, "analisis",
                                              "audio.csv")
    out_h = args.out_h or os.path.join(
        args.repo, "app", "src", "main", "cpp", "audio",
        "audio_id_map.h")
    out_csv = args.out_csv or os.path.join(
        args.repo, "herramientas", "audio", "audio_id_map.csv")

    streams = parse_streams(os.path.join(args.disc, "files", "audio",
                                         "data", "Streams.bin"))
    sfx = parse_sfx(os.path.join(args.disc, "files", "audio", "data",
                                 "Sfx.bin"))
    rows = list(csv.DictReader(open(inv_path, newline="",
                                    encoding="utf-8")))

    # Inventario streams: clave "DIR/base" en minusculas.
    wav_by_key = {}
    for row in rows:
        if not row["salida"].startswith("streams/"):
            continue
        fuente = row["fuente"]  # files/streams/DIR/f.adp
        parts = fuente.split("/")
        if len(parts) < 4:
            continue
        key = (parts[2] + "/" + parts[3].rsplit(".", 1)[0]).lower()
        wav_by_key.setdefault(key, row["salida"])

    # Inventario MusyX: muestra_id -> salida.
    sample_wav = {}
    for row in rows:
        if not row["salida"].startswith("musyx/"):
            continue
        try:
            mid = int(row["muestra_id"])
        except (ValueError, TypeError):
            continue
        sample_wav[mid] = row["salida"]

    stream_map = []      # (id, wav)
    stream_unmatched = []  # (id, nombre, motivo)
    for sid, _lr, name in streams:
        if not name:
            continue
        key = name.lower()
        if key in wav_by_key:
            stream_map.append((sid, wav_by_key[key]))
            continue
        # Prefijo unico (nombre truncado en el campo de 16 B):
        # solo vale si es prefijo estricto de una unica clave
        # y la parte del directorio coincide.
        pref = [k for k in wav_by_key
                if k.startswith(key) and
                k.split("/")[0] == key.split("/")[0]]
        if len(pref) == 1:
            stream_map.append((sid, wav_by_key[pref[0]]))
        else:
            stream_unmatched.append(
                (sid, name, "sin WAV en inventario (%d candidatos "
                 "por prefijo)" % len(pref)))
    stream_map.sort()

    sfx_map = sorted(sfx)
    sample_map = sorted(sample_wav.items())

    # WAV de muestra que faltan para triggers (deberia ser 0:
    # los campos observados son 0..832 y el inventario cubre
    # 0..1471).
    sfx_missing_samples = sorted(
        {s for (_t, _v, _p, ss) in sfx_map for s in ss
         if s != 0 and s not in sample_wav})

    with open(out_h, "w", encoding="utf-8") as f:
        f.write("// Generado por herramientas/audio/gen_audio_id_map.py "
                "(Fase 14).\n")
        f.write("// NO EDITAR A MANO: regenerar desde Streams.bin, "
                "Sfx.bin y analisis/audio.csv.\n")
        f.write("// Streams: id de AudioStream_Play -> WAV ADP "
                "extraido (32.000 Hz estereo).\n")
        f.write("// SFX: id de trigger -> vol/pitch + 4 IDs de "
                "muestra MusyX (0 = sin muestra).\n")
        f.write("// Muestras: ID global MusyX -> WAV (mono, "
                "frecuencia de inventario).\n")
        f.write("#pragma once\n\n#include <cstdint>\n\n"
                "namespace sfa {\n\n")
        f.write("struct StreamIdEntry {\n  uint16_t id;\n  const char* wav;\n};\n\n")
        f.write("static const StreamIdEntry kStreamIdMap[] = {\n")
        for sid, wav in stream_map:
            f.write('    {%d, "%s"},\n' % (sid, wav))
        f.write("};\n\n")
        f.write("struct SfxTriggerEntry {\n  uint16_t id;\n  uint8_t vol_base;\n  uint8_t pitch_base;\n  uint16_t samples[4];\n};\n\n")
        f.write("static const SfxTriggerEntry kSfxTriggerMap[] = {\n")
        for tid, vol, pitch, ss in sfx_map:
            f.write("    {%d, %d, %d, {%d, %d, %d, %d}},\n"
                    % (tid, vol, pitch, ss[0], ss[1], ss[2], ss[3]))
        f.write("};\n\n")
        f.write("struct MusyxSampleEntry {\n  uint16_t id;\n  const char* wav;\n};\n\n")
        f.write("static const MusyxSampleEntry kMusyxSampleMap[] = {\n")
        for mid, wav in sample_map:
            f.write('    {%d, "%s"},\n' % (mid, wav))
        f.write("};\n\n}  // namespace sfa\n")

    with open(out_csv, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["tipo", "id", "wav", "extra"])
        for sid, wav in stream_map:
            w.writerow(["stream", sid, wav, ""])
        for tid, vol, pitch, ss in sfx_map:
            w.writerow(["sfx_trigger", tid, "",
                        "vol=%d pitch=%d muestras=%s"
                        % (vol, pitch, ";".join(str(s) for s in ss))])
        for mid, wav in sample_map:
            w.writerow(["musyx_muestra", mid, wav, ""])

    print("streams: %d registros con nombre, %d resueltos, "
          "%d sin resolver" % (
              sum(1 for _s, _l, n in streams if n),
              len(stream_map), len(stream_unmatched)))
    for sid, name, why in stream_unmatched:
        print("  sin resolver: stream id=%d nombre='%s' (%s)"
              % (sid, name, why))
    print("sfx: %d triggers, muestras referenciadas sin WAV: %s"
          % (len(sfx_map), sfx_missing_samples))
    print("musyx: %d muestras en inventario" % len(sample_map))
    print("header: %s" % out_h)
    print("csv: %s" % out_csv)
    return 0


if __name__ == "__main__":
    sys.exit(main())
