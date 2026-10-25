"""Common helpers for Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL) extraction.

No absolute paths are hard-coded here: callers pass every input/output path
via argv. All multi-byte integers on disc are big-endian.

Formats implemented (see SFA-Decomp docs/wiki/Formats.md, Models.md, Maps.md):
  * ZLB: 16-byte header "ZLB\\0", u32 version, u32 decompressed size,
    u32 compressed size, then a standard zlib stream. Verified on disc:
    ``zlib.decompress(data[16:16+compressed])`` reproduces exactly
    ``decompressed`` bytes (the retail hand-rolled DEFLATE decoder skips the
    2-byte zlib header and inflates raw DEFLATE, which is equivalent).
  * DIR: same 16-byte header with tag "DIR" (+ any 4th byte); payload is
    stored raw, length = compressed size field.
  * FACEFEED: 16-byte header 0xFACEFEED, u32 decompressed, u32 aux, u32
    compressed; a nested ZLB (or raw E0) block follows after a header whose
    total size is (aux-3)*4 bytes in the records observed on this disc
    (aux == 12 -> 36 bytes). Fallback header sizes are tried and only a
    candidate that lands on a known magic AND decompresses to the declared
    size is accepted.
  * E0E0E0E0 (standalone): u32 decompressed size, u32 data offset; payload
    starts at data_offset + 0x18.
  * TAB files: arrays of u32 (or u16, per family) terminated by 0xFFFFFFFF,
    often with a trailing sentinel equal to the .bin size. ``read_tab_slots``
    returns the slot list with terminator/sentinel removed; slot 0 values
    are kept (offset 0 can be a real record, e.g. MODELS slot 0).
"""
import hashlib
import struct
import zlib

ZLB_MAGIC = b"ZLB\x00"
FACEFEED_MAGIC = bytes.fromhex("facefeed")
E0_MAGIC = b"\xe0\xe0\xe0\xe0"
F0_MAGIC = b"\xf0\xf0\xf0\xf0"


def sha1_bytes(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def sha1_file(path) -> str:
    h = hashlib.sha1()
    with open(path, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def be16(data, off):
    return struct.unpack_from(">H", data, off)[0]


def be16s(data, off):
    return struct.unpack_from(">h", data, off)[0]


def be32(data, off):
    return struct.unpack_from(">I", data, off)[0]


def be32s(data, off):
    return struct.unpack_from(">i", data, off)[0]


def be_float(data, off):
    return struct.unpack_from(">f", data, off)[0]


def parse_zlb(data: bytes, off: int):
    """Parse one ZLB/DIR block at ``off``. Returns (payload, consumed, info)."""
    if off + 16 > len(data):
        raise ValueError(f"ZLB block at {off:#x} truncated (header)")
    tag = data[off:off + 4]
    version, dec_size, comp_size = struct.unpack_from(">III", data, off + 4)
    if tag == ZLB_MAGIC:
        raw = data[off + 16:off + 16 + comp_size]
        if len(raw) != comp_size:
            raise ValueError(f"ZLB block at {off:#x} truncated (payload)")
        payload = zlib.decompress(raw)
        if len(payload) != dec_size:
            raise ValueError(
                f"ZLB block at {off:#x}: decompressed {len(payload)} != declared {dec_size}")
        return payload, 16 + comp_size, {
            "kind": "ZLB", "version": version,
            "decompressed_size": dec_size, "compressed_size": comp_size}
    if tag[:3] == b"DIR":
        payload = data[off + 16:off + 16 + comp_size]
        if len(payload) != comp_size:
            raise ValueError(f"DIR block at {off:#x} truncated")
        return payload, 16 + comp_size, {
            "kind": "DIR", "version": version,
            "decompressed_size": dec_size, "compressed_size": comp_size}
    raise ValueError(f"not a ZLB/DIR block at {off:#x} (tag {tag!r})")


def parse_wrapper(data: bytes, off: int):
    """Parse one record wrapper at ``off`` (FACEFEED / ZLB / E0 / raw).

    Returns (payload, kind, info). A bare model/block payload that starts
    with neither magic is returned as kind 'RAW' only when the caller
    explicitly allows it (parse_wrapper never invents one: unknown magics
    raise).
    """
    if off + 4 > len(data):
        raise ValueError(f"record at {off:#x} truncated")
    magic = data[off:off + 4]
    if magic == FACEFEED_MAGIC:
        dec, aux, comp = struct.unpack_from(">III", data, off + 4)
        candidates = []
        for hs in ((aux - 3) * 4, aux + 0x18, aux + 0x28, 0x24, 0x10 + aux):
            if hs > 0 and hs not in candidates:
                candidates.append(hs)
        last_err = None
        for hs in candidates:
            nested = off + hs
            if nested + 4 > len(data):
                continue
            try:
                if data[nested:nested + 4] == ZLB_MAGIC or data[nested:nested + 3] == b"DIR":
                    payload, _c, info = parse_zlb(data, nested)
                    if len(payload) == dec:
                        info = dict(info, facefeed_aux=aux,
                                    facefeed_compressed=comp, header_size=hs)
                        return payload, "FACEFEED+ZLB", info
                elif data[nested:nested + 4] == E0_MAGIC:
                    edec, eoff = struct.unpack_from(">II", data, nested + 4)
                    payload = data[nested + eoff + 0x18:nested + eoff + 0x18 + edec]
                    if len(payload) == edec == dec:
                        return payload, "FACEFEED+E0", {
                            "facefeed_aux": aux, "facefeed_compressed": comp,
                            "header_size": hs}
            except Exception as exc:  # try next candidate
                last_err = exc
        raise ValueError(
            f"FACEFEED at {off:#x} (dec={dec} aux={aux} comp={comp}): "
            f"no nested block validated ({last_err})")
    if magic == ZLB_MAGIC or magic[:3] == b"DIR":
        payload, _c, info = parse_zlb(data, off)
        return payload, info["kind"], info
    if magic == E0_MAGIC:
        dec, doff = struct.unpack_from(">II", data, off + 4)
        payload = data[off + doff + 0x18:off + doff + 0x18 + dec]
        if len(payload) != dec:
            raise ValueError(f"E0 block at {off:#x}: got {len(payload)} != {dec}")
        return payload, "E0", {"decompressed_size": dec, "data_offset": doff}
    if magic == F0_MAGIC:
        raise ValueError(f"F0/LZO block at {off:#x} is not supported (no LZO decoder, "
                         "and no such block was found on this disc)")
    raise ValueError(f"unknown record magic at {off:#x}: {magic.hex()}")


def read_tab_u32(tab: bytes):
    """All u32 values in a .tab file, in order (no terminator handling)."""
    return [struct.unpack_from(">I", tab, i)[0]
            for i in range(0, len(tab) - 3, 4)]


def tab_slots(tab: bytes, bin_len: int):
    """Slot list for a .tab file: stop at 0xFFFFFFFF, drop a trailing
    sentinel equal to the .bin size. Zeros are kept as 'absent' slots."""
    vals = read_tab_u32(tab)
    slots = []
    for v in vals:
        if v == 0xFFFFFFFF:
            break
        slots.append(v)
    if slots and slots[-1] == bin_len:
        slots.pop()
    return slots


def flagged_offset_candidates(raw: int):
    """Offset candidates for a flagged .tab entry (high byte = flags).

    Order: low 24 bits (wiki: 'high byte = unknown flags' for mod .tab),
    then low 28 bits (the mask used by the retail loader for MODELS),
    then the raw value itself.
    """
    out = []
    for cand in (raw & 0x00FFFFFF, raw & 0x0FFFFFFF, raw):
        if cand not in out:
            out.append(cand)
    return out


def resolve_flagged_record(bin_data: bytes, raw: int):
    """Decompress the record a flagged .tab entry points at.

    Returns (payload, kind, offset_used, info) or raises. A raw value of 0
    means 'absent' (caller must check before calling).
    """
    last_err = None
    for off in flagged_offset_candidates(raw):
        if off + 4 > len(bin_data):
            continue
        try:
            payload, kind, info = parse_wrapper(bin_data, off)
            return payload, kind, off, info
        except Exception as exc:
            last_err = exc
    raise ValueError(f"flagged tab entry {raw:#010x}: no offset validated ({last_err})")
