"""Parse a decompressed SFA character model (ModelFileHeader) to Wavefront OBJ.

Usage:
  python3 parse_models.py <model.bin> <model.obj> [--json sidecar.json]

Geometry rules (verified against the disc, see RESUMEN.md for the evidence):
  * Header fields are file-relative offsets (the game converts them to
    pointers on load). Counts at 0xE4..0xFB, pointers at 0x20..0xD4.
  * Render instructions are a bit stream read LSB-first within each byte
    (the retail reader does ``(w >> (pos & 7)) & 1``). Opcodes: 1 = bind
    shader (6-bit index), 2 = draw display list (8-bit index),
    3 = vertex-descriptor sizes (pos bit; normal bit iff shader attr & 1;
    colour bit iff shader attr & 2; tex bit), 4/0 = matrix list
    (4-bit count + 8-bit indices), 5 = end.
  * A display list is a sequence of GX primitives. Primitive byte =
    base | VAT, where base is 0x80 quads, 0x90 triangles, 0x98 tristrips,
    0xA0 trifans (lines/points are counted and skipped), followed by a
    big-endian u16 vertex count. A trailing run of zero bytes is the
    32-byte alignment padding of the list size field, not geometry.
  * Per vertex, in GX attribute order: direct bytes (matrix indices,
    count auto-detected, see below), then POS index, NRM/NBT index
    (if the shader uses normals), CLR0 index (if the shader uses colour),
    then one TEX index per shader layer (OBJ uses TEX0 only).
    Index width is 1 byte (size bit 0) or 2 bytes big-endian (size bit 1).
  * VAT scales (from the retail GXSetVtxAttrFmt table in pi_videoinit):
    VAT5: POS s16/8, TEX s16/256.  VAT6: POS s16/256, TEX s16/1024.
    VAT0: POS s16/1, TEX s16/128.   VAT3: POS s16/256, TEX s16/1024.
    VAT7: POS s16/1, TEX s16/1024.  Other VATs are not produced by this
    game's tables; a strip with an unknown VAT fails that model.
  * Normals are s8 triplets with magnitude ~64 (axis models are exactly
    64): vn = component / 64. If header flags24 & 0x08, the normal array
    holds 9-byte NBT records and vn is the first triplet.
  * Output is the bind pose: bone matrices are NOT applied (the direct
    matrix indices in the display list are ignored). No winding flip and
    no axis swap are applied; coordinates are the GX values as scaled.
  * Direct-byte count: the retail vertex descriptor enables PNMTXIDX
    (if jointCount > 1) plus texture-matrix direct attributes plus
    texMtxCount direct attributes, which cannot be derived from the
    model alone without the runtime texture-reference state. The parser
    therefore tries direct counts 0..6 for each display list and accepts
    a count only if the whole list parses with every index in range and
    ends in zero padding. Ambiguity (more than one count passing) is
    reported in the sidecar and the smallest passing count is used.
"""
import argparse
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sfa_common import be16, be16s, be32, be_float

# vat -> (pos_divisor, tex_divisor); NRM is always s8/64 in these files.
VAT_SCALES = {0: (1, 128), 3: (256, 1024), 5: (8, 256), 6: (256, 1024), 7: (1, 1024)}
PRIM_BASE = {0x80: "quads", 0x90: "triangles", 0x98: "tristrip", 0xA0: "trifan",
             0xA8: "lines", 0xB0: "linestrip", 0xB8: "points"}


class BitReader:
    def __init__(self, data):
        self.data = data
        self.pos = 0

    def read(self, n):
        v = 0
        for i in range(n):
            if self.pos >> 3 >= len(self.data):
                raise ValueError("render-instruction stream exhausted")
            v |= ((self.data[self.pos >> 3] >> (self.pos & 7)) & 1) << i
            self.pos += 1
        return v


def parse_header(data: bytes):
    if len(data) < 0x100:
        raise ValueError(f"model too small: {len(data)} bytes")
    h = {
        "file_size_field": be32(data, 0x0C),
        "textures_ptr": be32(data, 0x20),
        "vertices_ptr": be32(data, 0x28),
        "normals_ptr": be32(data, 0x2C),
        "colors_ptr": be32(data, 0x30),
        "texcoords_ptr": be32(data, 0x34),
        "shaders_ptr": be32(data, 0x38),
        "bones_ptr": be32(data, 0x3C),
        "vtxgroups_ptr": be32(data, 0x54),
        "hitspheres_ptr": be32(data, 0x58),
        "dlists_ptr": be32(data, 0xD0),
        "instrs_ptr": be32(data, 0xD4),
        "instrs_bytes": be16(data, 0xD8),
        "flags24": data[0x24],
        "flags2": be16(data, 0x02),
        "n_vtx": be16(data, 0xE4),
        "n_nrm": be16(data, 0xE6),
        "n_col": be16(data, 0xE8),
        "n_tex": be16(data, 0xEA),
        "n_tex_entries": data[0xF2],
        "n_bones": data[0xF3],
        "n_vtxgroups": data[0xF4],
        "n_dlists": data[0xF5],
        "n_dlists_shadow": data[0xF6],
        "n_hitspheres": data[0xF7],
        "n_shaders": data[0xF8],
        "n_morph": data[0xF9],
        "n_texmtx": data[0xFA],
    }
    shaders = []
    for i in range(h["n_shaders"]):
        base = h["shaders_ptr"] + i * 0x44
        if base + 0x44 > len(data):
            raise ValueError(f"shader {i} out of file")
        shaders.append({"attr": data[base + 0x40], "layers": data[base + 0x41],
                        "raw_hex": data[base:base + 0x44].hex()})
    h["shaders"] = shaders
    return h


def parse_render_instrs(data: bytes, h):
    """Returns a list of draw records in order:
    {dlist, shader, pos16, nrm16, clr16, tex16, layers, attr}."""
    start = h["instrs_ptr"]
    stream = data[start:start + h["instrs_bytes"]]
    br = BitReader(stream)
    draws = []
    cur_shader = 0
    vat = {"pos16": False, "nrm16": False, "clr16": False, "tex16": False}
    ops = []
    while br.pos < len(stream) * 8:
        op = br.read(4)
        if op == 1:
            cur_shader = br.read(6)
            ops.append(("bind", cur_shader))
        elif op == 2:
            dl = br.read(8)
            sh = h["shaders"][cur_shader] if cur_shader < len(h["shaders"]) else None
            if sh is None:
                raise ValueError(f"bind to missing shader {cur_shader}")
            draws.append({"dlist": dl, "shader": cur_shader,
                          "pos16": vat["pos16"], "nrm16": vat["nrm16"],
                          "clr16": vat["clr16"], "tex16": vat["tex16"],
                          "layers": sh["layers"], "attr": sh["attr"]})
            ops.append(("draw", dl))
        elif op == 3:
            sh = h["shaders"][cur_shader] if cur_shader < len(h["shaders"]) else None
            if sh is None:
                raise ValueError(f"vat op with missing shader {cur_shader}")
            vat = {"pos16": bool(br.read(1))}
            if sh["attr"] & 1:
                vat["nrm16"] = bool(br.read(1))
            else:
                vat["nrm16"] = False
            if sh["attr"] & 2:
                vat["clr16"] = bool(br.read(1))
            else:
                vat["clr16"] = False
            vat["tex16"] = bool(br.read(1))
            ops.append(("vat", dict(vat)))
        elif op in (0, 4):
            cnt = br.read(4)
            idxs = [br.read(8) for _ in range(cnt)]
            ops.append(("mtx", cnt, idxs))
        elif op == 5:
            ops.append(("end",))
            break
        else:
            raise ValueError(f"unknown render opcode {op} at bit {br.pos - 4}")
    return draws, ops


def _read_index(buf, pos, wide):
    if wide:
        return be16(buf, pos), pos + 2
    return buf[pos], pos + 1


def parse_display_list(data: bytes, h, draw, direct):
    """Parse one display list. Returns (faces, stats).

    faces: list of (prim_kind, [vertex, ...]) where vertex is a dict with
    pos/nrm/tex indices (or None) and the strip VAT.
    """
    base = h["dlists_ptr"] + draw["dlist"] * 0x1C
    if base + 0x1C > len(data):
        raise ValueError(f"dlist {draw['dlist']} entry out of file")
    off, size = struct.unpack_from(">IH", data, base)
    if off + size > len(data):
        raise ValueError(f"dlist {draw['dlist']} bytes out of file")
    blob = data[off:off + size]
    indexed = ((2 if draw["pos16"] else 1)
               + ((2 if draw["nrm16"] else 1) if draw["attr"] & 1 else 0)
               + ((2 if draw["clr16"] else 1) if draw["attr"] & 2 else 0)
               + draw["layers"] * (2 if draw["tex16"] else 1))
    vsize = direct + indexed
    faces = []
    stats = {"strips": 0, "prims": {}, "vertices": 0, "skipped_prims": 0}
    pos = 0
    while pos < len(blob):
        if blob[pos] == 0:
            if any(blob[pos:]):
                raise ValueError(f"zero opcode with trailing non-zero data at {pos}")
            break  # 32-byte alignment padding
        opcode = blob[pos]
        prim = PRIM_BASE.get(opcode & 0xF8)
        if prim is None:
            raise ValueError(f"unknown GX primitive byte {opcode:#x} at {pos}")
        vat = opcode & 0x07
        if vat not in VAT_SCALES:
            raise ValueError(f"unsupported VAT {vat} at {pos}")
        if pos + 3 > len(blob):
            raise ValueError("primitive header truncated")
        cnt = be16(blob, pos + 1)
        if cnt == 0 or pos + 3 + cnt * vsize > len(blob):
            raise ValueError(f"primitive at {pos} count {cnt} overruns list")
        verts = []
        for vi in range(cnt):
            p = pos + 3 + vi * vsize + direct
            v = {"vat": vat}
            v["pos"], p = _read_index(blob, p, draw["pos16"])
            if draw["attr"] & 1:
                v["nrm"], p = _read_index(blob, p, draw["nrm16"])
            else:
                v["nrm"] = None
            if draw["attr"] & 2:
                v["clr"], p = _read_index(blob, p, draw["clr16"])
            else:
                v["clr"] = None
            texs = []
            for _ in range(draw["layers"]):
                t, p = _read_index(blob, p, draw["tex16"])
                texs.append(t)
            v["tex"] = texs[0] if texs else None
            v["tex_all"] = texs
            if v["pos"] >= h["n_vtx"]:
                raise ValueError(f"pos index {v['pos']} >= n_vtx {h['n_vtx']}")
            if v["nrm"] is not None and v["nrm"] >= h["n_nrm"]:
                raise ValueError(f"nrm index {v['nrm']} >= n_nrm {h['n_nrm']}")
            if v["clr"] is not None and h["n_col"] and v["clr"] >= h["n_col"]:
                raise ValueError(f"clr index {v['clr']} >= n_col {h['n_col']}")
            if v["tex"] is not None and v["tex"] >= h["n_tex"]:
                raise ValueError(f"tex index {v['tex']} >= n_tex {h['n_tex']}")
            verts.append(v)
        stats["strips"] += 1
        stats["prims"][prim] = stats["prims"].get(prim, 0) + 1
        stats["vertices"] += cnt
        if prim == "tristrip":
            for i in range(2, cnt):
                if i % 2 == 0:
                    faces.append((prim, [verts[i - 2], verts[i - 1], verts[i]]))
                else:
                    faces.append((prim, [verts[i - 1], verts[i - 2], verts[i]]))
        elif prim == "triangles":
            if cnt % 3:
                raise ValueError("triangle primitive with count not multiple of 3")
            for i in range(0, cnt, 3):
                faces.append((prim, verts[i:i + 3]))
        elif prim == "trifan":
            for i in range(2, cnt):
                faces.append((prim, [verts[0], verts[i - 1], verts[i]]))
        elif prim == "quads":
            if cnt % 4:
                raise ValueError("quad primitive with count not multiple of 4")
            for i in range(0, cnt, 4):
                faces.append((prim, [verts[i], verts[i + 1], verts[i + 2]]))
                faces.append((prim, [verts[i], verts[i + 2], verts[i + 3]]))
        else:  # lines / points: counted, no faces
            stats["skipped_prims"] += 1
        pos += 3 + cnt * vsize
    return faces, stats


def parse_model(data: bytes):
    """Full parse. Returns (obj_text, sidecar_dict). Raises on failure."""
    h = parse_header(data)
    draws, _ops = parse_render_instrs(data, h)
    if len(draws) != h["n_dlists"] + h["n_dlists_shadow"]:
        # Shadow dlists are a second group indexed after the primary group;
        # the instruction stream draws them with the same indices, so a
        # mismatch here is informational, not fatal, unless draws exceed
        # the total table size.
        pass
    # Vertex pools
    vptr, nptr, tptr, cptr = (h["vertices_ptr"], h["normals_ptr"],
                              h["texcoords_ptr"], h["colors_ptr"])
    nbt = bool(h["flags24"] & 0x08)
    nrm_stride = 9 if nbt else 3

    def pos_xyz(idx, vat):
        div, _t = VAT_SCALES[vat]
        x, y, z = struct.unpack_from(">hhh", data, vptr + idx * 6)
        return (x / div, y / div, z / div)

    def tex_uv(idx, vat):
        _p, div = VAT_SCALES[vat]
        u, v = struct.unpack_from(">hh", data, tptr + idx * 4)
        return (u / div, 1.0 - v / div)  # OBJ v=0 is bottom; GX v grows down

    def nrm_xyz(idx):
        x, y, z = struct.unpack_from(">bbb", data, nptr + idx * nrm_stride)
        return (x / 64.0, y / 64.0, z / 64.0)

    # Per-display-list parse with direct-count auto-detection.
    # Direct-count tiebreak (verified on the full unique-model set):
    # different passing counts give DIFFERENT faces, so "smallest passing"
    # alone is arbitrary for ambiguous dlists. Retail
    # modelRenderFn_setVtxDescr (objprint_dolphin.c) sets, when
    # jointCount > 1: PNMTXIDX (1) + texMtxCount direct attrs + a texture
    # part of 0 (no textureRefs), 1 (textureRefs, no aux texture) or 3
    # (textureRefs + aux texture); when jointCount <= 1 it sets no direct
    # attribute at all (direct = 0). So:
    #   1. retail candidate set: {0} if jointCount <= 1, else
    #      {1+texMtx, 1+texMtx+1, 1+texMtx+3}; if exactly one candidate
    #      passes, use it;
    #   2. else the model's most common unambiguous direct, if it passes;
    #   3. else smallest passing, flagged in direct_unresolved.
    # On the 2026-10-25 full run this resolves all 56 ambiguous model
    # dlists (35 by model-constant, 21 by the retail rule, all of the
    # latter being jointCount <= 1 -> 0); step 3 never fires there, but
    # it is kept so a future model still produces an OBJ instead of
    # failing, with the ambiguity recorded.
    all_faces = []  # (dlist_index, prim, [verts])
    dl_stats = {}
    direct_used = {}
    ambiguous = []
    tiebreak = {}
    unresolved = []
    parsed = {}  # dl -> {direct: (faces, stats)}
    for draw in draws:
        dl = draw["dlist"]
        if dl in parsed:
            continue
        successes = {}
        last_err = None
        for direct in range(0, 7):
            try:
                successes[direct] = parse_display_list(data, h, draw, direct)
            except Exception as exc:
                last_err = exc
        if not successes:
            raise ValueError(f"dlist {dl}: no direct count parses ({last_err})")
        parsed[dl] = successes
        if len(successes) > 1:
            ambiguous.append({"dlist": dl,
                              "passing_direct_counts": sorted(successes)})
    if h["n_bones"] <= 1:
        retail_cands = {0}
    else:
        base = 1 + h["n_texmtx"]
        retail_cands = {base, base + 1, base + 3}
    unamb_directs = [next(iter(v)) for dl, v in parsed.items()
                     if len(v) == 1]
    model_mode = None
    if unamb_directs:
        from collections import Counter as _Counter
        model_mode = _Counter(unamb_directs).most_common(1)[0][0]
    for dl, successes in parsed.items():
        if len(successes) == 1:
            direct, (faces, stats) = next(iter(successes.items()))
            tiebreak[dl] = "unique"
        else:
            inter = retail_cands & set(successes)
            if len(inter) == 1:
                direct = next(iter(inter))
                tiebreak[dl] = "retail_formula"
            elif model_mode is not None and model_mode in successes:
                direct = model_mode
                tiebreak[dl] = "model_constant"
            else:
                direct = min(successes)
                tiebreak[dl] = "smallest_fallback"
                unresolved.append(dl)
            faces, stats = successes[direct]
        direct_used[dl] = direct
        dl_stats[dl] = stats
        for prim, verts in faces:
            all_faces.append((dl, prim, verts))

    # OBJ emission with (index, vat) deduplication for positions/texcoords
    v_map, vt_map, vn_map = {}, {}, {}
    v_lines, vt_lines, vn_lines = [], [], []
    face_lines = []
    cur_dl = None
    for dl, _prim, verts in all_faces:
        if dl != cur_dl:
            face_lines.append(f"g dlist_{dl}")
            cur_dl = dl
        elems = []
        for v in verts:
            pk = (v["pos"], v["vat"])
            if pk not in v_map:
                x, y, z = pos_xyz(v["pos"], v["vat"])
                v_lines.append(f"v {x:.6g} {y:.6g} {z:.6g}")
                v_map[pk] = len(v_lines)
            vi = v_map[pk]
            if v["tex"] is not None:
                tk = (v["tex"], v["vat"])
                if tk not in vt_map:
                    u, vv = tex_uv(v["tex"], v["vat"])
                    vt_lines.append(f"vt {u:.6g} {vv:.6g}")
                    vt_map[tk] = len(vt_lines)
                ti = vt_map[tk]
            else:
                ti = None
            if v["nrm"] is not None:
                if v["nrm"] not in vn_map:
                    nx, ny, nz = nrm_xyz(v["nrm"])
                    vn_lines.append(f"vn {nx:.6g} {ny:.6g} {nz:.6g}")
                    vn_map[v["nrm"]] = len(vn_lines)
                ni = vn_map[v["nrm"]]
            else:
                ni = None
            if ti is not None and ni is not None:
                elems.append(f"{vi}/{ti}/{ni}")
            elif ti is not None:
                elems.append(f"{vi}/{ti}")
            elif ni is not None:
                elems.append(f"{vi}//{ni}")
            else:
                elems.append(f"{vi}")
        face_lines.append("f " + " ".join(elems))

    header_lines = [
        "# Star Fox Adventures (GameCube, GSAP01) character model, bind pose.",
        "# Positions: GX s16 scaled per primitive VAT (VAT5 /8, VAT6 /256).",
        "# Texcoords: GX s16 scaled per VAT (VAT5 /256, VAT6 /1024), v flipped.",
        "# Normals: s8 triplets /64 (9-byte NBT records: first triplet).",
        "# Bone matrices NOT applied; direct matrix indices ignored.",
    ]
    obj = "\n".join(header_lines + v_lines + vt_lines + vn_lines + face_lines) + "\n"

    # Bones / hitspheres / vtxgroups for the sidecar (raw-field parse, wiki layout)
    bones = []
    for i in range(h["n_bones"]):
        base = h["bones_ptr"] + i * 0x1C
        if base + 0x1C > len(data):
            break
        parent = struct.unpack_from(">b", data, base)[0]
        idx = list(data[base + 1:base + 4])
        head = struct.unpack_from(">fff", data, base + 4)
        tail = struct.unpack_from(">fff", data, base + 0x10)
        bones.append({"parent": parent, "idx_bytes": idx, "head": head, "tail": tail})
    hitspheres = []
    for i in range(h["n_hitspheres"]):
        base = h["hitspheres_ptr"] + i * 0x18
        if base + 0x18 > len(data):
            break
        hitspheres.append({
            "raw_hex": data[base:base + 0x18].hex(),
            "bone_wiki": be16s(data, base),
            "radius_wiki": be_float(data, base + 4),
            "pos_wiki": struct.unpack_from(">fff", data, base + 8),
            "linked_wiki": be16(data, base + 0x14),
            "sphere_index_wiki": struct.unpack_from(">b", data, base + 0x16)[0],
        })
    sidecar = {
        "n_vtx": h["n_vtx"], "n_nrm": h["n_nrm"], "n_col": h["n_col"],
        "n_tex": h["n_tex"], "n_bones": h["n_bones"],
        "n_vtxgroups": h["n_vtxgroups"], "n_dlists": h["n_dlists"],
        "n_dlists_shadow": h["n_dlists_shadow"], "n_hitspheres": h["n_hitspheres"],
        "n_shaders": h["n_shaders"], "n_morph": h["n_morph"],
        "n_texmtx": h["n_texmtx"], "n_tex_entries": h["n_tex_entries"],
        "flags24": h["flags24"], "flags2": h["flags2"], "nbt_normals": nbt,
        "file_size_field": h["file_size_field"],
        "shaders": [{"attr": s["attr"], "layers": s["layers"]} for s in h["shaders"]],
        "draws": len(draws),
        "obj_vertices": len(v_lines), "obj_texcoords": len(vt_lines),
        "obj_normals": len(vn_lines), "obj_faces": len(face_lines) - len(dl_stats),
        "direct_per_dlist": direct_used,
        "direct_ambiguous": ambiguous,
        "direct_tiebreak": {str(k): v for k, v in tiebreak.items()},
        "direct_unresolved": unresolved,
        "dl_stats": {str(k): v for k, v in dl_stats.items()},
        "bones": bones, "hitspheres": hitspheres,
    }
    return obj, sidecar


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("model")
    ap.add_argument("obj")
    ap.add_argument("--json", default=None)
    args = ap.parse_args(argv)
    data = Path(args.model).read_bytes()
    obj, sidecar = parse_model(data)
    out = Path(args.obj)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(obj)
    if args.json:
        Path(args.json).write_text(json.dumps(sidecar, indent=2))
    print(f"{args.model}: {sidecar['obj_faces']} faces, "
          f"{sidecar['obj_vertices']} verts, {sidecar['draws']} draws, "
          f"{sidecar['n_bones']} bones, {sidecar['n_hitspheres']} hitspheres")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
