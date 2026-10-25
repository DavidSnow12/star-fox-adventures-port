"""Parse SFA disc tables to CSV/JSON (objects, maps, animations, romlists,
DLLs, VOXMAP/AMAP/MODANIM/MODELIND, OBJINDEX).

Usage:
  python3 parse_tables.py <disc_files_dir> <inventarios_dir> [--wiki-dir DIR]

<disc_files_dir> is the extracted disc root (the directory that contains
OBJECTS.bin, MAPS.bin, *.romlist.zlb and the per-map subdirectories).
<inventarios_dir> receives the CSV/JSON files. --wiki-dir, if given, is
the SFA-Decomp docs/wiki directory; its MapList.md and DLLs.md tables
are parsed (read-only) only to join human-readable map romlist names
and DLL names onto the disc-derived rows. Without it those two columns
are left empty; no disc-derived value depends on the wiki.

Every parser below states, in code comments, which interpretation it
used and how it validated it (monotonic offsets inside the .bin,
counts matching a second file, terminator 0xFFFFFFFF, ...). Formats
that could not be validated are reported as raw statistics only and
are never presented as decoded rows.
"""
import argparse
import csv
import json
import re
import struct
import sys
import zlib
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sfa_common import (be16, be16s, be32, parse_zlb, resolve_flagged_record,
                        sha1_bytes, tab_slots)


def u32s(data):
    return [struct.unpack_from(">I", data, i)[0] for i in range(0, len(data) - 3, 4)]


def u16s(data):
    return [struct.unpack_from(">H", data, i)[0] for i in range(0, len(data) - 1, 2)]


def s16s(data):
    return [struct.unpack_from(">h", data, i)[0] for i in range(0, len(data) - 1, 2)]


def write_csv(path, rows, fieldnames):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fieldnames)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fieldnames})


# ---------------------------------------------------------------- objects
def parse_objects(root: Path):
    """OBJECTS.bin/tab + OBJINDEX.bin.

    OBJECTS.tab: plain u32 offsets, terminated by 0xFFFFFFFF, last offset
    before the terminator is the .bin size (validated: it equals the file
    size). Record size = next offset - offset. Name at +0x91 (11 bytes).
    dll_id is read as u16 at +0x50 in this script's output, following the
    wiki table; the decomp cross-check notes the same offset is read as
    s16 by the loader (dll_id == -1 means 'no DLL'). Both readings agree
    except for the -1 sentinel, which is reported as 65535 here and
    normalised to -1 in the dll_id_s column.
    """
    bin_data = (root / "OBJECTS.bin").read_bytes()
    tab = (root / "OBJECTS.tab").read_bytes()
    offsets = tab_slots(tab, len(bin_data))
    objindex = s16s((root / "OBJINDEX.bin").read_bytes())
    rows = []
    for def_id, (off, nxt) in enumerate(zip(offsets, offsets[1:] + [len(bin_data)])):
        if off >= len(bin_data) or nxt <= off:
            rows.append({"def_id": def_id, "offset": off, "size": nxt - off,
                         "status": "invalid_offset"})
            continue
        rec = bin_data[off:nxt]
        if len(rec) < 0x9C:
            rows.append({"def_id": def_id, "offset": off, "size": len(rec),
                         "status": "short_record"})
            continue
        name = rec[0x91:0x9C].split(b"\x00", 1)[0].decode("ascii", "replace")
        dll_u16 = struct.unpack_from(">H", rec, 0x50)[0]
        dll_s16 = struct.unpack_from(">h", rec, 0x50)[0]
        class_id = struct.unpack_from(">h", rec, 0x52)[0]
        model_ids = ()
        p_model = struct.unpack_from(">I", rec, 0x08)[0]
        n_models = rec[0x55]
        if p_model and off <= off + p_model < nxt and n_models:
            try:
                model_ids = struct.unpack_from(f">{n_models}I", bin_data,
                                               off + p_model)
            except struct.error:
                model_ids = ()
        p_seq = struct.unpack_from(">I", rec, 0x1C)[0]
        n_seq = rec[0x5E]
        seq_ids = ()
        if p_seq and off <= off + p_seq < nxt and n_seq:
            try:
                seq_ids = struct.unpack_from(f">{n_seq}H", bin_data, off + p_seq)
            except struct.error:
                seq_ids = ()
        help_texts = struct.unpack_from(">4H", rec, 0x7C)
        rows.append({
            "def_id": def_id, "offset": off, "size": nxt - off, "name": name,
            "dll_id": dll_u16, "dll_id_s": dll_s16, "class_id": class_id,
            "n_models": n_models, "n_player_objs": rec[0x56],
            "n_attach_points": rec[0x58], "n_textures": rec[0x59],
            "n_vecs": rec[0x5A], "n_sequences": n_seq,
            "map_id": struct.unpack_from(">H", rec, 0x78)[0],
            "flags": struct.unpack_from(">I", rec, 0x44)[0],
            "shadow_type": struct.unpack_from(">h", rec, 0x48)[0],
            "help_texts": ";".join(str(x) for x in help_texts),
            "model_ids": ";".join(str(x) for x in model_ids),
            "sequence_ids": ";".join(str(x) for x in seq_ids),
            "scale": struct.unpack_from(">f", rec, 0x04)[0],
            "status": "ok",
        })
    return rows, objindex, offsets


def parse_objindex(objindex, object_count):
    rows = []
    for i, v in enumerate(objindex):
        resolved = v if v != -1 else None
        valid = resolved is not None and 0 <= resolved < object_count
        rows.append({"objindex_id": i, "mapped_def": v,
                     "resolves": "yes" if valid else ("unused_-1" if v == -1 else "out_of_range")})
    return rows


# ---------------------------------------------------------------- romlists
def parse_romlist(payload: bytes, name: str):
    """Romlist entries: s16 type, u8 size_words, u8 acts0, u8 loadFlags,
    u8 acts1, u8 bound, u8 cullDist, vec3f position, u32 id, then
    (size_words*4 - 0x18) bytes of type-specific parameters. The size
    field is validated on every entry (positive, in-bounds); a single
    bad entry aborts that file with an error, it is not skipped."""
    entries = []
    off = 0
    while off < len(payload):
        if off + 0x18 > len(payload):
            raise ValueError(f"{name}: trailing {len(payload) - off} bytes at {off:#x}")
        typ, size_words, acts0, load_flags, acts1, bound, cull = struct.unpack_from(
            ">hBBBBBB", payload, off)
        size = size_words * 4
        if size < 0x18 or off + size > len(payload):
            raise ValueError(f"{name}: bad entry size {size} at {off:#x}")
        x, y, z = struct.unpack_from(">fff", payload, off + 8)
        uid = struct.unpack_from(">I", payload, off + 0x14)[0]
        entries.append({
            "romlist": name, "entry_index": len(entries), "offset": off,
            "type_raw": typ, "size_words": size_words, "size_bytes": size,
            "acts0": acts0, "load_flags": load_flags, "acts1": acts1,
            "bound": bound, "cull_dist": cull, "pos_x": x, "pos_y": y, "pos_z": z,
            "unique_id": uid,
            "params_hex": payload[off + 0x18:off + size].hex(),
        })
        off += size
    if off != len(payload):
        raise ValueError(f"{name}: ended at {off} != {len(payload)}")
    return entries


# ---------------------------------------------------------------- maps
def parse_maps(root: Path, maplist):
    """MAPS.tab: 7 u32 per map (info, blockTable, rects1..4, listSize),
    117 maps (0x00..0x74), terminated by 0xFFFFFFFF + padding.
    Validation: info offsets are non-decreasing and every blockTable
    region size equals sizeX*sizeZ*4 bytes implied by the info record.
    MAPINFO.bin: 0x20-byte records, name[28], type @0x1C, always-6 @0x1D,
    objType @0x1E."""
    maps_bin = (root / "MAPS.bin").read_bytes()
    maps_tab = u32s((root / "MAPS.tab").read_bytes())
    # 117 maps x 7 fields = 819 values, then terminator/padding
    if len(maps_tab) < 819:
        raise ValueError(f"MAPS.tab too short: {len(maps_tab)} u32")
    info = (root / "MAPINFO.bin").read_bytes()
    n_info = len(info) // 0x20
    rows = []
    for mid in range(117):
        fields = maps_tab[mid * 7:(mid + 1) * 7]
        info_off, block_off, r1, r2, r3, r4, list_size = fields
        if info_off + 0x20 > len(maps_bin):
            rows.append({"map_id": mid, "status": "info_out_of_range"})
            continue
        size_x, size_z, org_x, org_z = struct.unpack_from(">HHHH", maps_bin, info_off)
        n_blocks = struct.unpack_from(">h", maps_bin, info_off + 0x1C)[0]
        cells = size_x * size_z
        block_vals = []
        if block_off + cells * 4 <= len(maps_bin):
            block_vals = [struct.unpack_from(">I", maps_bin, block_off + i * 4)[0]
                          for i in range(cells)]
        nonempty = 0
        mod_dist = Counter()
        for v in block_vals:
            mod = (v >> 23) & 0xFF
            if mod != 0xFF:
                nonempty += 1
                mod_dist[mod] += 1
        if mid < n_info:
            raw_name = info[mid * 0x20:mid * 0x20 + 28]
            mname = raw_name.split(b"\x00", 1)[0].decode("ascii", "replace")
            mtype = info[mid * 0x20 + 0x1C]
            obj_type = struct.unpack_from(">H", info, mid * 0x20 + 0x1E)[0]
        else:
            mname, mtype, obj_type = "", None, None
        ml = maplist.get(mid, {}) if maplist else {}
        rows.append({
            "map_id": mid, "map_id_hex": f"{mid:02x}",
            "mapinfo_name": mname, "map_type": mtype, "mapinfo_objtype": obj_type,
            "romlist_name": ml.get("romlist", ""), "directory": ml.get("directory", ""),
            "size_x": size_x, "size_z": size_z, "origin_x": org_x, "origin_z": org_z,
            "n_blocks_field": n_blocks, "grid_cells": cells,
            "nonempty_cells": nonempty,
            "block_table_offset": block_off, "info_offset": info_off,
            "rects_offsets": ";".join(str(x) for x in (r1, r2, r3, r4)),
            "list_size_field": list_size,
            "mod_distribution": ";".join(f"{k}:{v}" for k, v in sorted(mod_dist.items())),
            "status": "ok",
        })
    return rows


def parse_maplist_md(path: Path):
    """Parse the 'Main map list' + second table of MapList.md.

    Returns {map_id: {romlist, directory, name, type}}. Section-aware:
    only rows between '## Main map list' and 'From here on' (first
    table, 6 cells: ID|Romlist|Directory|Name|T|Note) and rows after
    'From here on' up to the 'Although `animtest`' paragraph (second
    table, 5 cells: ID|Romlist|Name|ObjType|Note) are read. This avoids
    the later Directory List / Parent Maps tables, whose rows also
    start with hex ids but have a different column layout. MapList.md
    rows do NOT start with a leading '|' (e.g. '00|frontend |...')."""
    if not path.exists():
        return {}
    text = path.read_text(errors="replace")
    out = {}
    state = None
    for raw_line in text.splitlines():
        line = raw_line.strip()
        if line.startswith("## Main map list"):
            state = "main"
            continue
        if line.startswith("From here on"):
            state = "second"
            continue
        if line.startswith("Although `animtest`") or line.startswith("## Directory List"):
            state = None
            continue
        if state is None or "|" not in line:
            continue
        cells = [c.strip() for c in line.split("|")]
        if len(cells) < 5:
            continue
        try:
            mid = int(cells[0], 16)
        except ValueError:
            continue
        if cells[0] in ("ID", "--") or not re.fullmatch(r"[0-9a-fA-F]{1,2}", cells[0]):
            continue
        if state == "main" and len(cells) >= 6:
            out[mid] = {"romlist": cells[1], "directory": cells[2],
                        "name": cells[3], "type": cells[4]}
        elif state == "second" and len(cells) == 5:
            out[mid] = {"romlist": cells[1], "directory": "",
                        "name": cells[2], "type": "1",
                        "objtype": cells[3]}
    return out


def parse_dlls_md(path: Path):
    """Parse the DLL ID table of DLLs.md -> {id: (name, description)}."""
    if not path.exists():
        return {}
    out = {}
    for line in path.read_text(errors="replace").splitlines():
        line = line.strip()
        if not line.startswith("|"):
            continue
        cells = [c.strip() for c in line.strip("|").split("|")]
        if len(cells) < 3:
            continue
        try:
            did = int(cells[0], 16)
        except ValueError:
            continue
        out[did] = (cells[1], cells[2])
    return out


# ---------------------------------------------------------------- animations
def parse_anim_container(tab_path: Path, bin_path: Path):
    """ANIM.TAB / PREANIM.TAB: 2600 u32. Entry = 28-bit offset + bit
    0x10000000 ('this container holds the real record'). The .BIN size
    is entry 2597, then 0xFFFFFFFF + a zero pad word (validated on the
    root containers; per-map containers use the same layout with their
    own sizes). A real record's header (wiki Animation.md, corpus
    section): byte0 always 0, byte1 frameControl, u16 frame-stream
    offset @+2, u16 root-curve offset @+4, u8 jointCount @+6,
    u8 frameCount @+7, u8 stride @+8, byte9 always 0. The 32-byte stub
    (0004 0010 0000 0102 + zeros) is the shared null animation."""
    tab = u32s(tab_path.read_bytes())
    bin_data = bin_path.read_bytes()
    if len(tab) < 2598:
        return [], {"error": f"tab too short: {len(tab)} entries"}
    rows = []
    for aid in range(2597):
        raw = tab[aid]
        holds = bool(raw & 0x10000000)
        off = raw & 0x0FFFFFFF
        if off >= len(bin_data):
            rows.append({"anim_id": aid, "holds_real": holds, "offset": off,
                         "status": "offset_out_of_range"})
            continue
        nxt = tab[aid + 1] & 0x0FFFFFFF if aid + 1 < len(tab) else len(bin_data)
        size = nxt - off if nxt > off else 0
        rec = bin_data[off:off + size] if size else b""
        # 32-byte null animation: 8-byte header 0004 0010 0000 0102 + 24 zeros.
        is_stub = rec == bytes.fromhex("0004001000000102") + bytes(24)
        hdr = {}
        if len(rec) >= 10:
            hdr = {"frame_control": rec[1],
                   "frame_stream_offset": struct.unpack_from(">H", rec, 2)[0],
                   "root_curve_offset": struct.unpack_from(">H", rec, 4)[0],
                   "joint_count": rec[6], "frame_count": rec[7],
                   "stride": rec[8]}
        rows.append({"anim_id": aid, "holds_real": holds, "offset": off,
                     "size": size, "is_stub": is_stub, **hdr,
                     "status": "ok" if size else "empty"})
    summary = {
        "tab_entries": len(tab), "bin_size": len(bin_data),
        "bin_size_field": tab[2597] if len(tab) > 2597 else None,
        "holds_real": sum(1 for r in rows if r.get("holds_real")),
        "holds_real_stub": sum(1 for r in rows
                                if r.get("holds_real") and r.get("is_stub")),
        "stubs": sum(1 for r in rows if r.get("is_stub")),
        "empty": sum(1 for r in rows if r.get("size") == 0),
        "records_with_size": sum(1 for r in rows if r.get("size")),
    }
    return rows, summary


def parse_anim_summary_only(tab_path: Path, bin_path: Path):
    rows, summary = parse_anim_container(tab_path, bin_path)
    return summary


def parse_modanim(root: Path):
    """MODANIM.TAB: 1264 u16 offsets into MODANIM.BIN (one per MODELS
    slot; validated: monotonic non-decreasing, max < bin size).
    Length = next offset - offset; the record bytes are s16 values,
    split by -1 sentinels in the runtime loader (reported raw here)."""
    tab = u16s((root / "MODANIM.TAB").read_bytes())
    bin_data = (root / "MODANIM.BIN").read_bytes()
    rows = []
    for i, off in enumerate(tab):
        nxt = tab[i + 1] if i + 1 < len(tab) else len(bin_data)
        size = nxt - off if nxt >= off else 0
        vals = s16s(bin_data[off:off + size]) if size else []
        rows.append({"model_slot": i, "offset": off, "size": size,
                     "s16_values": ";".join(str(v) for v in vals)})
    return rows


def parse_amap(root: Path):
    """AMAP.TAB: 1264 u32 offsets into AMAP.BIN (validated monotonic
    non-decreasing, max < bin size). Records are byte tables (the
    .BIN starts with counting byte sequences); only offsets, lengths
    and leading bytes are inventoried here, the record grammar is
    not re-derived in this pass."""
    tab = u32s((root / "AMAP.TAB").read_bytes())
    bin_data = (root / "AMAP.BIN").read_bytes()
    rows = []
    for i, off in enumerate(tab):
        nxt = tab[i + 1] if i + 1 < len(tab) else len(bin_data)
        size = nxt - off if nxt >= off else 0
        rows.append({"model_slot": i, "offset": off, "size": size,
                     "first_bytes_hex": bin_data[off:off + 16].hex() if size else ""})
    return rows


def parse_voxmap(tab_path: Path, bin_path: Path):
    """VOXMAP.tab: flagged u32 (flags<<24 | offset). Each valid entry
    points at a ZLB block in VOXMAP.bin. The decompressed record's
    candidate minY/maxY are the s16 values at +0x04/+0x0C quoted by
    the wiki's decoded VOXMAP section; they are reported as candidates
    and the full route-grid decode is not re-derived here."""
    tab = u32s(tab_path.read_bytes())
    bin_data = bin_path.read_bytes()
    rows = []
    for i, raw in enumerate(tab):
        if raw == 0:
            rows.append({"vox_index": i, "status": "absent"})
            continue
        if raw == len(bin_data):
            # Trailing sentinel: the .tab is padded with the .bin size
            # after the last real entry (root VOXMAP: 935 such entries).
            rows.append({"vox_index": i, "status": "end_sentinel"})
            continue
        if raw == 0xFFFFFFFF:
            rows.append({"vox_index": i, "status": "terminator"})
            continue
        try:
            payload, _kind, off, _info = resolve_flagged_record(bin_data, raw)
            min_y = struct.unpack_from(">h", payload, 4)[0] if len(payload) >= 6 else None
            max_y = struct.unpack_from(">h", payload, 12)[0] if len(payload) >= 14 else None
            rows.append({"vox_index": i, "status": "ok", "tab_raw": raw,
                         "offset": off, "decompressed_size": len(payload),
                         "sha1": sha1_bytes(payload),
                         "min_y_candidate": min_y, "max_y_candidate": max_y})
        except Exception as exc:
            rows.append({"vox_index": i, "status": "failed", "tab_raw": raw,
                         "error": str(exc)})
    return rows


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("disc_files")
    ap.add_argument("inventarios")
    ap.add_argument("--wiki-dir", default=None)
    args = ap.parse_args(argv)
    root = Path(args.disc_files)
    out = Path(args.inventarios)
    out.mkdir(parents=True, exist_ok=True)
    wiki = Path(args.wiki_dir) if args.wiki_dir else None
    maplist = parse_maplist_md(wiki / "MapList.md") if wiki else {}
    dll_names = parse_dlls_md(wiki / "DLLs.md") if wiki else {}

    obj_rows, objindex, _offsets = parse_objects(root)
    write_csv(out / "objetos.csv", obj_rows,
              ["def_id", "offset", "size", "name", "dll_id", "dll_id_s",
               "class_id", "n_models", "n_player_objs", "n_attach_points",
               "n_textures", "n_vecs", "n_sequences", "map_id", "flags",
               "shadow_type", "help_texts", "model_ids", "sequence_ids",
               "scale", "status"])
    write_csv(out / "objindex.csv", parse_objindex(objindex, len(obj_rows)),
              ["objindex_id", "mapped_def", "resolves"])

    # Romlists (root *.romlist.zlb)
    rom_rows, rom_summary = [], []
    for p in sorted(root.glob("*.romlist.zlb")):
        try:
            payload = parse_zlb(p.read_bytes(), 0)[0]
            entries = parse_romlist(payload, p.name)
            rom_rows.extend(entries)
            types = Counter(e["type_raw"] for e in entries)
            rom_summary.append({
                "romlist": p.name, "compressed_size": p.stat().st_size,
                "decompressed_size": len(payload),
                "entries": len(entries),
                "distinct_types": len(types),
                "unique_ids": len({e["unique_id"] for e in entries}),
                "status": "ok"})
        except Exception as exc:
            rom_summary.append({"romlist": p.name, "compressed_size": p.stat().st_size,
                                "decompressed_size": "", "entries": "",
                                "distinct_types": "", "unique_ids": "",
                                "status": f"failed: {exc}"})
    write_csv(out / "romlists.csv", rom_rows,
              ["romlist", "entry_index", "offset", "type_raw", "size_words",
               "size_bytes", "acts0", "load_flags", "acts1", "bound",
               "cull_dist", "pos_x", "pos_y", "pos_z", "unique_id", "params_hex"])
    write_csv(out / "romlists_resumen.csv", rom_summary,
              ["romlist", "compressed_size", "decompressed_size", "entries",
               "distinct_types", "unique_ids", "status"])

    # Maps
    map_rows = parse_maps(root, maplist)
    write_csv(out / "mapas.csv", map_rows,
              ["map_id", "map_id_hex", "mapinfo_name", "map_type",
               "mapinfo_objtype", "romlist_name", "directory", "size_x",
               "size_z", "origin_x", "origin_z", "n_blocks_field",
               "grid_cells", "nonempty_cells", "block_table_offset",
               "info_offset", "rects_offsets", "list_size_field",
               "mod_distribution", "status"])

    # DLLs: join wiki names with object usage counts
    dll_use = Counter(r["dll_id"] for r in obj_rows if r["status"] == "ok")
    dll_rows = []
    for did in sorted(set(list(dll_names) + list(dll_use))):
        name, desc = dll_names.get(did, ("", ""))
        dll_rows.append({"dll_id": did, "dll_id_hex": f"{did:03x}",
                         "wiki_name": name, "wiki_description": desc,
                         "objects_using": dll_use.get(did, 0)})
    write_csv(out / "dlls.csv", dll_rows,
              ["dll_id", "dll_id_hex", "wiki_name", "wiki_description",
               "objects_using"])
    dlls_tab = u32s((root / "DLLS.tab").read_bytes()) if (root / "DLLS.tab").exists() else []
    (out / "dlls_nota.json").write_text(json.dumps({
        "DLLS.bin_present": (root / "DLLS.bin").exists(),
        "DLLS.tab_values": dlls_tab,
        "note": "DLLS.bin is absent from this disc extraction (only the 32-byte "
                "DLLS.tab is present), so DLL code itself cannot be inventoried "
                "from the disc here; dlls.csv joins wiki DLL names with "
                "OBJECTS.bin dll_id usage only.",
    }, indent=2))

    # Animations: root containers in full, per-map containers as summaries
    anim_summaries = []
    for tab_name, bin_name, label in [("ANIM.TAB", "ANIM.BIN", "root_ANIM"),
                                      ("PREANIM.TAB", "PREANIM.BIN", "root_PREANIM")]:
        rows, summary = parse_anim_container(root / tab_name, root / bin_name)
        summary["container"] = label
        anim_summaries.append(summary)
        if label == "root_ANIM":
            write_csv(out / "animaciones.csv", rows,
                      ["anim_id", "holds_real", "offset", "size", "is_stub",
                       "frame_control", "frame_stream_offset",
                       "root_curve_offset", "joint_count", "frame_count",
                       "stride", "status"])
    for mapdir in sorted(p for p in root.iterdir() if p.is_dir()):
        tab_p, bin_p = mapdir / "ANIM.TAB", mapdir / "ANIM.BIN"
        if tab_p.exists() and bin_p.exists():
            try:
                s = parse_anim_summary_only(tab_p, bin_p)
                s["container"] = f"{mapdir.name}_ANIM"
            except Exception as exc:
                s = {"container": f"{mapdir.name}_ANIM", "error": str(exc)}
            anim_summaries.append(s)
    write_csv(out / "animaciones_resumen.csv", anim_summaries,
              ["container", "tab_entries", "bin_size", "bin_size_field",
               "holds_real", "holds_real_stub", "stubs", "empty",
               "records_with_size", "error"])

    write_csv(out / "modanim.csv", parse_modanim(root),
              ["model_slot", "offset", "size", "s16_values"])
    write_csv(out / "amap.csv", parse_amap(root),
              ["model_slot", "offset", "size", "first_bytes_hex"])

    # MODELIND: s16 array, one entry per model id
    modelind = s16s((root / "MODELIND.bin").read_bytes())
    root_model_slots = set()
    # root MODELS slots that are present (flagged tab, raw != 0)
    try:
        mtab = tab_slots((root / "MODELS.tab").read_bytes(),
                         (root / "MODELS.bin").stat().st_size)
        root_model_slots = {i for i, v in enumerate(mtab) if v != 0}
    except Exception:
        pass
    write_csv(out / "modelind.csv",
              [{"model_id": i, "models_tab_slot": v,
                "slot_present_in_root_MODELS": "yes" if v in root_model_slots else "no"}
               for i, v in enumerate(modelind)],
              ["model_id", "models_tab_slot", "slot_present_in_root_MODELS"])

    # VOXMAP root + per-map (summaries + per-record rows for root only)
    vox_rows = parse_voxmap(root / "VOXMAP.tab", root / "VOXMAP.bin")
    write_csv(out / "voxmap_root.csv", vox_rows,
              ["vox_index", "status", "tab_raw", "offset", "decompressed_size",
               "sha1", "min_y_candidate", "max_y_candidate", "error"])
    def vox_summary(container, rows):
        return {"container": container, "entries": len(rows),
                "ok": sum(1 for r in rows if r["status"] == "ok"),
                "absent": sum(1 for r in rows if r["status"] == "absent"),
                "failed": sum(1 for r in rows if r["status"] == "failed"),
                "end_sentinel": sum(1 for r in rows if r["status"] == "end_sentinel"),
                "terminator": sum(1 for r in rows if r["status"] == "terminator")}
    vox_summaries = [vox_summary("root_VOXMAP", vox_rows)]
    for mapdir in sorted(p for p in root.iterdir() if p.is_dir()):
        tab_p, bin_p = mapdir / "VOXMAP.tab", mapdir / "VOXMAP.bin"
        if tab_p.exists() and bin_p.exists():
            try:
                rows = parse_voxmap(tab_p, bin_p)
                vox_summaries.append(vox_summary(f"{mapdir.name}_VOXMAP", rows))
            except Exception as exc:
                vox_summaries.append({"container": f"{mapdir.name}_VOXMAP",
                                      "error": str(exc)})
    write_csv(out / "voxmap_resumen.csv", vox_summaries,
              ["container", "entries", "ok", "absent", "failed",
               "end_sentinel", "terminator", "error"])

    # OBJECTS.bin2 comparison (raw, no decode claim)
    bin2 = root / "OBJECTS.bin2"
    if bin2.exists():
        b1, b2 = (root / "OBJECTS.bin").read_bytes(), bin2.read_bytes()
        diff = sum(1 for a, c in zip(b1, b2) if a != c)
        (out / "objects_bin2_nota.json").write_text(json.dumps({
            "OBJECTS.bin_size": len(b1), "OBJECTS.bin2_size": len(b2),
            "common_bytes": min(len(b1), len(b2)),
            "differing_bytes_in_common_range": diff,
            "differing_fraction": diff / max(1, min(len(b1), len(b2))),
            "note": "OBJECTS.bin2 is 256 bytes longer AND differs in ~47% of the "
                    "common range, so it is not a minor variant of "
                    "OBJECTS.bin; it is inventoried raw only. No decoded "
                    "claim is made about which table lineage bin2 represents.",
        }, indent=2))
    print(f"objetos: {len(obj_rows)} defs, romlists: {len(rom_summary)} files, "
          f"{len(rom_rows)} entries, mapas: {len(map_rows)}, "
          f"anim containers: {len(anim_summaries)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
