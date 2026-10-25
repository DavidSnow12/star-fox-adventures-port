"""Decompress SFA ZLB / FACEFEED containers.

Usage:
  python3 zlb_extract.py <input> <output> [--tab TAB] [--flagged]

* Single file (e.g. ``foo.romlist.zlb``): decompresses the one ZLB block
  and writes it to <output>.
* With --tab: splits a .bin container (MODELS.bin, modXX.zlb.bin,
  VOXMAP.bin) by its .tab file. Each valid slot is written as
  <output>/<stem>_<slot:04d>.bin ; a JSON manifest with offsets, kinds,
  sizes and SHA-1s is written to <output>.manifest.json. With --flagged
  the .tab entries carry a flags byte (MODELS / mod / VOXMAP); without it
  entries are plain offsets (e.g. a plain ZLB-per-record container).
* A slot whose raw tab value is 0 is 'absent' and is skipped (except
  flagged slot value 0x10000000, i.e. offset 0, which is a real record).

Exit code is 0 even if individual slots fail; failures are listed in the
manifest and on stderr, so a bulk run is not lost to one bad record.
"""
import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sfa_common import (parse_wrapper, parse_zlb, resolve_flagged_record,
                        sha1_bytes, tab_slots)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("input")
    ap.add_argument("output")
    ap.add_argument("--tab", default=None, help=".tab file for a container")
    ap.add_argument("--flagged", action="store_true",
                    help=".tab entries carry a flags high byte")
    args = ap.parse_args(argv)

    inp = Path(args.input)
    data = inp.read_bytes()
    if args.tab is None:
        payload, _kind, info = parse_zlb(data, 0)
        out = Path(args.output)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(payload)
        print(f"{inp.name}: ZLB {info['compressed_size']} -> {len(payload)} bytes "
              f"sha1={sha1_bytes(payload)}")
        return 0

    tab = Path(args.tab).read_bytes()
    slots = tab_slots(tab, len(data))
    outdir = Path(args.output)
    outdir.mkdir(parents=True, exist_ok=True)
    manifest = {"source": str(inp), "tab": str(args.tab), "slots": len(slots),
                "records": [], "failures": []}
    ok = 0
    for slot, raw in enumerate(slots):
        if raw == 0:
            manifest["records"].append(
                {"slot": slot, "raw": raw, "status": "absent"})
            continue
        try:
            if args.flagged:
                payload, kind, off, _info = resolve_flagged_record(data, raw)
            else:
                payload, kind, _info = parse_wrapper(data, raw)
                off = raw
            name = f"{inp.stem}_{slot:04d}.bin"
            (outdir / name).write_bytes(payload)
            manifest["records"].append({
                "slot": slot, "raw": raw, "offset": off, "kind": kind,
                "size": len(payload), "sha1": sha1_bytes(payload),
                "file": name, "status": "ok"})
            ok += 1
        except Exception as exc:
            manifest["records"].append(
                {"slot": slot, "raw": raw, "status": "failed", "error": str(exc)})
            manifest["failures"].append({"slot": slot, "raw": raw, "error": str(exc)})
            print(f"slot {slot} raw={raw:#x}: FAILED {exc}", file=sys.stderr)
    (outdir / f"{inp.stem}.manifest.json").write_text(
        json.dumps(manifest, indent=2))
    print(f"{inp.name}: {ok} records ok, {len(manifest['failures'])} failed, "
          f"{sum(1 for r in manifest['records'] if r['status'] == 'absent')} absent, "
          f"of {len(slots)} slots")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
