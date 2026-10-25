"""Parse a decompressed SFA map-block model (MapBlockData, 0xB8 header) to OBJ.

Usage:
  python3 parse_blocks.py <block.bin> <block.obj> [--json sidecar.json]
        [--collision collision.csv] [--block-name NAME]

Differences from character models (parse_models.py):
  * Header is the MapBlockData layout (wiki Maps.md "Block Model Data"):
    vertices @0x58 (vec3s, stride 6), colours @0x5C (u16 RGBA4444),
    texcoords @0x60 (vec2s, stride 4), shaders @0x64 (0x44 stride,
    attr @+0x40, layers @+0x41), display lists @0x68 (0x1C stride,
    offset @+0, size @+4), three render streams @0x78/0x7C/0x80 with
    byte sizes @0x84/0x86/0x88, counts @0x90..0xA2, name @0xA4 (11 bytes).
  * Block render streams use the block variant of opcode 3: POS bit,
    then COLOUR bit iff shader attr & 2, then TEX bit. The normal bit
    that character streams carry is skipped (blocks carry no normals).
    Opcode 1/2/4/5 semantics are the same as for character models, and
    the bit order is likewise LSB-first within each byte.
  * Block display lists use VAT5 (primitive bytes 0x95 triangles,
    0x9D tristrips, ...): POS s16/8, TEX s16/256. A block's local
    coordinates are exported as-is; the header yMin/yMax/yOffset
    (@0x8A/0x8C/0x8E, s16) are reported in the sidecar but NOT added:
    the display-list bounding boxes and the collision-group boxes in
    the sampled blocks match the raw (unshifted) vertices, so yOffset
    looks like a world-placement shift applied by the map loader, not
    part of the block-local geometry. This is flagged as an open
    interpretation in RESUMEN.md, not silently baked in.
  * Collision triangles (GCpolygons @0x4C, stride 8: v0,v1,v2,cellMask;
    count @0x98) use the same vertex pool. They are NOT merged into the
    visible OBJ: with --collision they are written as CSV rows with the
    polygon-group surface type inferred from polygonGroups (@0x50,
    stride 0x14: firstPolygon @+0, surfaceType @+0x11) by ordering
    groups on firstPolygon. Collision coordinates are reported in the
    CSV in raw s16 units and in /8 units (the wiki's collision scale);
    visible OBJ coordinates use the VAT5 /8 scale, so the two agree
    numerically for the sampled block (5120 raw -> 640 in both).
  * Blocks have no joints, so direct-byte count is expected to be 0;
    it is still auto-detected per display list (0..3) exactly as for
    character models, and ambiguity is reported.
"""
import argparse
import csv
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sfa_common import be16, be16s, be32
from parse_models import VAT_SCALES, PRIM_BASE, BitReader, _read_index


def parse_block_header(data: bytes):
    if len(data) < 0xB8:
        raise ValueError(f"block too small: {len(data)} bytes")
    h = {
        "flags4": be16(data, 0x04),
        "file_size_field": be32(data, 0x08),
        "gcpolygons_ptr": be32(data, 0x4C),
        "polygroups_ptr": be32(data, 0x50),
        "textures_ptr": be32(data, 0x54),
        "vertices_ptr": be32(data, 0x58),
        "colors_ptr": be32(data, 0x5C),
        "texcoords_ptr": be32(data, 0x60),
        "shaders_ptr": be32(data, 0x64),
        "dlists_ptr": be32(data, 0x68),
        "streams_ptr": [be32(data, 0x78), be32(data, 0x7C), be32(data, 0x80)],
        "streams_bytes": [be16(data, 0x84), be16(data, 0x86), be16(data, 0x88)],
        "y_min": be16s(data, 0x8A), "y_max": be16s(data, 0x8C),
        "y_offset": be16s(data, 0x8E),
        "n_vtx": be16(data, 0x90), "n_unk": be16(data, 0x92),
        "n_col": be16(data, 0x94), "n_tex": be16(data, 0x96),
        "n_polygons": be16(data, 0x98), "n_polygroups": be16(data, 0x9A),
        "n_hits": be16(data, 0x9C),
        "n_textures": data[0xA0], "n_dlists": data[0xA1], "n_shaders": data[0xA2],
        "name": data[0xA4:0xAF].split(b"\x00", 1)[0].decode("ascii", "replace"),
    }
    shaders = []
    for i in range(h["n_shaders"]):
        base = h["shaders_ptr"] + i * 0x44
        if base + 0x44 > len(data):
            raise ValueError(f"block shader {i} out of file")
        shaders.append({"attr": data[base + 0x40], "layers": data[base + 0x41]})
    h["shaders"] = shaders
    return h


def parse_block_streams(data: bytes, h):
    """Parse the three render streams. Returns draws per stream name."""
    names = ["main", "transp", "water"]
    out = {}
    for name, ptr, nbytes in zip(names, h["streams_ptr"], h["streams_bytes"]):
        draws = []
        if ptr == 0 or nbytes == 0:
            out[name] = draws
            continue
        br = BitReader(data[ptr:ptr + nbytes])
        cur_shader = 0
        vat = {"pos16": False, "clr16": False, "tex16": False}
        while br.pos < nbytes * 8:
            op = br.read(4)
            if op == 1:
                cur_shader = br.read(6)
            elif op == 2:
                dl = br.read(8)
                sh = h["shaders"][cur_shader] if cur_shader < len(h["shaders"]) else None
                if sh is None:
                    raise ValueError(f"block stream {name}: missing shader {cur_shader}")
                draws.append({"dlist": dl, "shader": cur_shader, "stream": name,
                              "pos16": vat["pos16"], "clr16": vat["clr16"],
                              "tex16": vat["tex16"], "layers": sh["layers"],
                              "attr": sh["attr"], "nrm16": False})
            elif op == 3:
                sh = h["shaders"][cur_shader] if cur_shader < len(h["shaders"]) else None
                if sh is None:
                    raise ValueError(f"block stream {name}: vat op, missing shader")
                vat = {"pos16": bool(br.read(1))}
                if sh["attr"] & 2:
                    vat["clr16"] = bool(br.read(1))
                else:
                    vat["clr16"] = False
                vat["tex16"] = bool(br.read(1))
            elif op in (0, 4):
                cnt = br.read(4)
                for _ in range(cnt):
                    br.read(8)
            elif op == 5:
                break
            else:
                raise ValueError(f"block stream {name}: unknown opcode {op}")
        out[name] = draws
    return out


def parse_block_dlist(data: bytes, h, draw, direct):
    base = h["dlists_ptr"] + draw["dlist"] * 0x1C
    if base + 0x1C > len(data):
        raise ValueError(f"block dlist {draw['dlist']} entry out of file")
    off, size = struct.unpack_from(">IH", data, base)
    if off + size > len(data):
        raise ValueError(f"block dlist {draw['dlist']} bytes out of file")
    blob = data[off:off + size]
    indexed = ((2 if draw["pos16"] else 1)
               + ((2 if draw["clr16"] else 1) if draw["attr"] & 2 else 0)
               + draw["layers"] * (2 if draw["tex16"] else 1))
    vsize = direct + indexed
    faces, stats = [], {"strips": 0, "prims": {}, "vertices": 0}
    pos = 0
    while pos < len(blob):
        if blob[pos] == 0:
            if any(blob[pos:]):
                raise ValueError(f"block dlist: zero opcode with trailing data at {pos}")
            break
        opcode = blob[pos]
        prim = PRIM_BASE.get(opcode & 0xF8)
        if prim is None:
            raise ValueError(f"block dlist: unknown primitive {opcode:#x} at {pos}")
        vat = opcode & 0x07
        if vat not in VAT_SCALES:
            raise ValueError(f"block dlist: unsupported VAT {vat}")
        cnt = be16(blob, pos + 1)
        if cnt == 0 or pos + 3 + cnt * vsize > len(blob):
            raise ValueError(f"block dlist: primitive at {pos} count {cnt} overruns")
        verts = []
        for vi in range(cnt):
            p = pos + 3 + vi * vsize + direct
            v = {"vat": vat}
            v["pos"], p = _read_index(blob, p, draw["pos16"])
            if draw["attr"] & 2:
                v["clr"], p = _read_index(blob, p, draw["clr16"])
            else:
                v["clr"] = None
            texs = []
            for _ in range(draw["layers"]):
                t, p = _read_index(blob, p, draw["tex16"])
                texs.append(t)
            v["tex"] = texs[0] if texs else None
            v["nrm"] = None
            if v["pos"] >= h["n_vtx"]:
                raise ValueError(f"block pos {v['pos']} >= n_vtx {h['n_vtx']}")
            if v["tex"] is not None and v["tex"] >= h["n_tex"]:
                raise ValueError(f"block tex {v['tex']} >= n_tex {h['n_tex']}")
            verts.append(v)
        stats["strips"] += 1
        stats["prims"][prim] = stats["prims"].get(prim, 0) + 1
        stats["vertices"] += cnt
        if prim == "tristrip":
            for i in range(2, cnt):
                if i % 2 == 0:
                    faces.append([verts[i - 2], verts[i - 1], verts[i]])
                else:
                    faces.append([verts[i - 1], verts[i - 2], verts[i]])
        elif prim == "triangles":
            for i in range(0, cnt - cnt % 3, 3):
                faces.append(verts[i:i + 3])
        elif prim == "trifan":
            for i in range(2, cnt):
                faces.append([verts[0], verts[i - 1], verts[i]])
        elif prim == "quads":
            for i in range(0, cnt - cnt % 4, 4):
                faces.append([verts[i], verts[i + 1], verts[i + 2]])
                faces.append([verts[i], verts[i + 2], verts[i + 3]])
        pos += 3 + cnt * vsize
    return faces, stats


def parse_block(data: bytes, block_name=""):
    h = parse_block_header(data)
    streams = parse_block_streams(data, h)
    vptr, tptr = h["vertices_ptr"], h["texcoords_ptr"]

    def pos_xyz(idx, vat):
        div, _t = VAT_SCALES[vat]
        x, y, z = struct.unpack_from(">hhh", data, vptr + idx * 6)
        return (x / div, y / div, z / div)

    def tex_uv(idx, vat):
        _p, div = VAT_SCALES[vat]
        u, v = struct.unpack_from(">hh", data, tptr + idx * 4)
        return (u / div, 1.0 - v / div)

    all_faces = []  # (stream, dlist, [verts])
    dl_stats, direct_used, ambiguous = {}, {}, []
    seen = set()
    for stream_name, draws in streams.items():
        for draw in draws:
            key = (stream_name, draw["dlist"])
            if key in seen:
                continue
            seen.add(key)
            successes, last_err = [], None
            for direct in range(0, 4):
                try:
                    faces, stats = parse_block_dlist(data, h, draw, direct)
                    successes.append((direct, faces, stats))
                except Exception as exc:
                    last_err = exc
            if not successes:
                raise ValueError(
                    f"block {stream_name} dlist {draw['dlist']}: no direct count "
                    f"parses ({last_err})")
            if len(successes) > 1:
                ambiguous.append({"stream": stream_name, "dlist": draw["dlist"],
                                  "passing_direct_counts": [s[0] for s in successes]})
            # Retail block descriptor (shader.c mapBlockRender path) sets
            # ONLY indexed POS/CLR/TEX after GXClearVtxDesc: no direct
            # attribute exists for blocks, so direct = 0 is always correct
            # when it passes. On the full run it does (all 11,072 block
            # dlists choose 0, and 0 is in every ambiguous passing set),
            # so smallest-passing == retail-correct here. A dlist where 0
            # fails but a larger count passes would mean the stream-bit
            # sizes were misread, not a real direct attribute.
            direct, faces, stats = successes[0]
            direct_used[f"{stream_name}:{draw['dlist']}"] = direct
            dl_stats[f"{stream_name}:{draw['dlist']}"] = stats
            for tri in faces:
                all_faces.append((stream_name, draw["dlist"], tri))

    v_map, vt_map = {}, {}
    v_lines, vt_lines, face_lines = [], [], []
    cur = None
    for stream_name, dl, tri in all_faces:
        if (stream_name, dl) != cur:
            face_lines.append(f"g {stream_name}_dlist_{dl}")
            cur = (stream_name, dl)
        elems = []
        for v in tri:
            pk = (v["pos"], v["vat"])
            if pk not in v_map:
                x, y, z = pos_xyz(v["pos"], v["vat"])
                v_lines.append(f"v {x:.6g} {y:.6g} {z:.6g}")
                v_map[pk] = len(v_lines)
            if v["tex"] is not None:
                tk = (v["tex"], v["vat"])
                if tk not in vt_map:
                    u, vv = tex_uv(v["tex"], v["vat"])
                    vt_lines.append(f"vt {u:.6g} {vv:.6g}")
                    vt_map[tk] = len(vt_lines)
                elems.append(f"{v_map[pk]}/{vt_map[tk]}")
            else:
                elems.append(f"{v_map[pk]}")
        face_lines.append("f " + " ".join(elems))
    header = [
        "# Star Fox Adventures map block model, block-local coordinates.",
        "# Blocks use VAT5: POS s16/8, TEX s16/256, v flipped. No normals.",
        "# Header yOffset NOT applied (see sidecar / RESUMEN.md).",
    ]
    obj = "\n".join(header + v_lines + vt_lines + face_lines) + "\n"

    # Collision triangles + polygon groups
    groups = []
    for i in range(h["n_polygroups"]):
        base = h["polygroups_ptr"] + i * 0x14
        if base + 0x14 > len(data):
            break
        first = be16(data, base)
        bbox = struct.unpack_from(">6h", data, base + 2)
        groups.append({"index": i, "first_polygon": first, "bbox_raw": bbox,
                       "surface_type": data[base + 0x11],
                       "flags": be16(data, base + 0x12)})
    groups_sorted = sorted(groups, key=lambda g: g["first_polygon"])
    collisions = []
    for i in range(h["n_polygons"]):
        base = h["gcpolygons_ptr"] + i * 8
        if base + 8 > len(data):
            break
        v0, v1, v2, mask = struct.unpack_from(">HHHH", data, base)
        surf = None
        for gi, g in enumerate(groups_sorted):
            nxt = groups_sorted[gi + 1]["first_polygon"] if gi + 1 < len(groups_sorted) else 10 ** 9
            if g["first_polygon"] <= i < nxt:
                surf = g["surface_type"]
                break
        verts = []
        for vi in (v0, v1, v2):
            if vi < h["n_vtx"]:
                x, y, z = struct.unpack_from(">hhh", data, vptr + vi * 6)
                verts.append((x, y, z, x / 8.0, y / 8.0, z / 8.0))
            else:
                verts.append(None)
        collisions.append({"triangle": i, "v0": v0, "v1": v1, "v2": v2,
                           "cell_mask": mask, "surface_type": surf,
                           "vertices": verts})
    sidecar = {
        "name": h["name"] or block_name, "n_vtx": h["n_vtx"], "n_col": h["n_col"],
        "n_tex": h["n_tex"], "n_polygons": h["n_polygons"],
        "n_polygroups": h["n_polygroups"], "n_dlists": h["n_dlists"],
        "n_shaders": h["n_shaders"], "n_textures": h["n_textures"],
        "y_min": h["y_min"], "y_max": h["y_max"], "y_offset": h["y_offset"],
        "file_size_field": h["file_size_field"],
        "shaders": h["shaders"],
        "streams": {k: len(v) for k, v in streams.items()},
        "obj_vertices": len(v_lines), "obj_texcoords": len(vt_lines),
        "obj_faces": len(face_lines) - len(dl_stats),
        "direct_per_dlist": direct_used, "direct_ambiguous": ambiguous,
        "dl_stats": dl_stats,
        "collision_triangles": len(collisions),
        "polygroups": groups,
    }
    return obj, sidecar, collisions


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("block")
    ap.add_argument("obj")
    ap.add_argument("--json", default=None)
    ap.add_argument("--collision", default=None)
    ap.add_argument("--block-name", default="")
    args = ap.parse_args(argv)
    data = Path(args.block).read_bytes()
    obj, sidecar, collisions = parse_block(data, args.block_name)
    out = Path(args.obj)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(obj)
    if args.json:
        Path(args.json).write_text(json.dumps(sidecar, indent=2))
    if args.collision:
        with open(args.collision, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["triangle", "v0", "v1", "v2", "cell_mask",
                        "surface_type", "v0_raw", "v1_raw", "v2_raw",
                        "v0_div8", "v1_div8", "v2_div8"])
            for c in collisions:
                w.writerow([c["triangle"], c["v0"], c["v1"], c["v2"],
                            c["cell_mask"], c["surface_type"],
                            c["vertices"][0][:3] if c["vertices"][0] else None,
                            c["vertices"][1][:3] if c["vertices"][1] else None,
                            c["vertices"][2][:3] if c["vertices"][2] else None,
                            c["vertices"][0][3:] if c["vertices"][0] else None,
                            c["vertices"][1][3:] if c["vertices"][1] else None,
                            c["vertices"][2][3:] if c["vertices"][2] else None])
    print(f"{args.block}: {sidecar['obj_faces']} faces, "
          f"{sidecar['obj_vertices']} verts, "
          f"{sidecar['collision_triangles']} collision tris, "
          f"name={sidecar['name']!r}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
