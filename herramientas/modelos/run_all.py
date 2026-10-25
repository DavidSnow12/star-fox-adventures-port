"""End-to-end SFA models/objects/maps/animations/ZLB extraction.

Usage:
  python3 run_all.py <disc_files_dir> <extraidos_modelos_dir> <inventarios_dir>
                     [--wiki-dir DIR]

* <disc_files_dir> is read-only: nothing under it is ever written.
* <extraidos_modelos_dir> receives:
    romlists/            decompressed *.romlist.zlb payloads (one per file)
    modelos_descomprimidos/  unique decompressed character-model payloads,
                             named modelo_<sha1>.bin
    modelos_obj/         OBJ (+ JSON sidecar) per unique parseable model
    bloques_descomprimidos/ unique decompressed map-block payloads,
                             named bloque_<sha1>.bin
    bloques_obj/         OBJ (+ JSON sidecar) per unique parseable block
    bloques_colision/    collision CSV per unique block (only when the
                         block has collision triangles)
    modelos_fuentes.csv  every MODELS/mod slot -> unique payload mapping
    fallos.csv           every record that failed to decompress or parse,
                         with the reason
* <inventarios_dir> receives the table inventories written by
  parse_tables.py, plus modelos.csv (the artifact inventory with the
  columns: fuente, tamano_fuente, sha1_fuente, salida, tamano_salida,
  sha1_salida, tipo).
* RESUMEN.md is written into <extraidos_modelos_dir> by hand after this
  run (it summarises counts that this script prints); this script does
  not fabricate it.

Deduplication is by SHA-1 of the decompressed payload: the same model
is shipped in many map directories, so per-source rows live in
modelos_fuentes.csv while the (large) payload/OBJ is stored once.
"""
import argparse
import csv
import hashlib
import json
import sys
import traceback
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sfa_common import (parse_zlb, resolve_flagged_record, sha1_bytes,
                        sha1_file, tab_slots)
from parse_models import parse_model
from parse_blocks import parse_block
from parse_tables import main as parse_tables_main


def sha1_of(path: Path) -> str:
    return sha1_file(path)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("disc_files")
    ap.add_argument("extraidos_modelos")
    ap.add_argument("inventarios")
    ap.add_argument("--wiki-dir", default=None)
    args = ap.parse_args(argv)
    disc = Path(args.disc_files)
    out = Path(args.extraidos_modelos)
    inv = Path(args.inventarios)
    for d in ("romlists", "modelos_descomprimidos", "modelos_obj",
              "bloques_descomprimidos", "bloques_obj", "bloques_colision"):
        (out / d).mkdir(parents=True, exist_ok=True)
    inv.mkdir(parents=True, exist_ok=True)

    artifacts = []  # modelos.csv rows
    failures = []
    fuentes = []    # modelos_fuentes.csv rows

    def add_artifact(fuente_rel, fuente_size, fuente_sha, salida_rel,
                     salida_path, tipo):
        artifacts.append({
            "fuente": fuente_rel, "tamano_fuente": fuente_size,
            "sha1_fuente": fuente_sha, "salida": salida_rel,
            "tamano_salida": salida_path.stat().st_size if salida_path.exists() else "",
            "sha1_salida": sha1_of(salida_path) if salida_path.exists() else "",
            "tipo": tipo})

    def rel_disc(p: Path) -> str:
        try:
            return str(p.relative_to(disc))
        except ValueError:
            return str(p)

    # ---------------------------------------------------------- romlists
    romlist_files = sorted(disc.glob("*.romlist.zlb"))
    for p in romlist_files:
        dst = out / "romlists" / (p.stem + ".bin")
        try:
            payload = parse_zlb(p.read_bytes(), 0)[0]
            dst.write_bytes(payload)
            add_artifact(rel_disc(p), p.stat().st_size, sha1_of(p),
                         f"extraidos/modelos/romlists/{dst.name}", dst,
                         "romlist_descomprimido")
        except Exception as exc:
            failures.append({"fuente": rel_disc(p), "etapa": "zlb_romlist",
                             "error": str(exc)})

    # ---------------------------------------------------------- models + blocks
    # Sources: (label, bin_path, tab_path) -- root first, then per-map dirs.
    model_sources = []
    if (disc / "MODELS.bin").exists():
        model_sources.append(("root", disc / "MODELS.bin", disc / "MODELS.tab"))
    for d in sorted(p for p in disc.iterdir() if p.is_dir()):
        if (d / "MODELS.bin").exists():
            model_sources.append((d.name, d / "MODELS.bin", d / "MODELS.tab"))
    block_sources = []
    for d in sorted(p for p in disc.iterdir() if p.is_dir()):
        for mod in sorted(d.glob("mod*.zlb.bin")):
            tab = d / (mod.name.replace(".zlb.bin", ".tab"))
            if tab.exists():
                block_sources.append((f"{d.name}/{mod.name}", mod, tab))

    seen_models, seen_blocks = {}, {}
    model_stats = Counter()
    for label, bin_path, tab_path in model_sources:
        bin_data = bin_path.read_bytes()
        try:
            slots = tab_slots(tab_path.read_bytes(), len(bin_data))
        except Exception as exc:
            failures.append({"fuente": rel_disc(bin_path), "etapa": "tab_MODELS",
                             "error": str(exc)})
            continue
        for slot, raw in enumerate(slots):
            if raw == 0:
                continue
            try:
                payload, _kind, _off, _info = resolve_flagged_record(bin_data, raw)
            except Exception as exc:
                failures.append({"fuente": f"{rel_disc(bin_path)} slot {slot}",
                                 "etapa": "descomprimir_modelo", "error": str(exc)})
                model_stats["modelo_descompresion_fallo"] += 1
                continue
            sha = sha1_bytes(payload)
            fuentes.append({"origen": label, "archivo": rel_disc(bin_path),
                            "slot": slot, "tab_raw": f"{raw:#x}",
                            "tamano_descomprimido": len(payload),
                            "sha1_descomprimido": sha, "clase": "modelo"})
            if sha in seen_models:
                model_stats["modelo_duplicado"] += 1
                continue
            seen_models[sha] = True
            dst = out / "modelos_descomprimidos" / f"modelo_{sha}.bin"
            dst.write_bytes(payload)
            add_artifact(rel_disc(bin_path), bin_path.stat().st_size,
                         sha1_of(bin_path),
                         f"extraidos/modelos/modelos_descomprimidos/{dst.name}",
                         dst, "modelo_descomprimido")
            try:
                obj, sidecar = parse_model(payload)
                obj_path = out / "modelos_obj" / f"modelo_{sha}.obj"
                obj_path.write_text(obj)
                (out / "modelos_obj" / f"modelo_{sha}.json").write_text(
                    json.dumps(sidecar, indent=2))
                add_artifact(rel_disc(bin_path), bin_path.stat().st_size,
                             sha1_of(bin_path),
                             f"extraidos/modelos/modelos_obj/{obj_path.name}",
                             obj_path, "modelo_obj")
                model_stats["modelo_obj_ok"] += 1
            except Exception as exc:
                failures.append({"fuente": f"modelo_{sha}",
                                 "etapa": "parse_modelo_obj", "error": str(exc)})
                model_stats["modelo_obj_fallo"] += 1

    block_stats = Counter()
    for label, bin_path, tab_path in block_sources:
        bin_data = bin_path.read_bytes()
        try:
            slots = tab_slots(tab_path.read_bytes(), len(bin_data))
        except Exception as exc:
            failures.append({"fuente": rel_disc(bin_path), "etapa": "tab_mod",
                             "error": str(exc)})
            continue
        for slot, raw in enumerate(slots):
            if raw == 0:
                continue
            try:
                payload, _kind, _off, _info = resolve_flagged_record(bin_data, raw)
            except Exception as exc:
                failures.append({"fuente": f"{rel_disc(bin_path)} slot {slot}",
                                 "etapa": "descomprimir_bloque", "error": str(exc)})
                block_stats["bloque_descompresion_fallo"] += 1
                continue
            sha = sha1_bytes(payload)
            fuentes.append({"origen": label, "archivo": rel_disc(bin_path),
                            "slot": slot, "tab_raw": f"{raw:#x}",
                            "tamano_descomprimido": len(payload),
                            "sha1_descomprimido": sha, "clase": "bloque"})
            if sha in seen_blocks:
                block_stats["bloque_duplicado"] += 1
                continue
            seen_blocks[sha] = True
            dst = out / "bloques_descomprimidos" / f"bloque_{sha}.bin"
            dst.write_bytes(payload)
            add_artifact(rel_disc(bin_path), bin_path.stat().st_size,
                         sha1_of(bin_path),
                         f"extraidos/modelos/bloques_descomprimidos/{dst.name}",
                         dst, "bloque_descomprimido")
            try:
                obj, sidecar, collisions = parse_block(payload)
                obj_path = out / "bloques_obj" / f"bloque_{sha}.obj"
                obj_path.write_text(obj)
                (out / "bloques_obj" / f"bloque_{sha}.json").write_text(
                    json.dumps(sidecar, indent=2))
                add_artifact(rel_disc(bin_path), bin_path.stat().st_size,
                             sha1_of(bin_path),
                             f"extraidos/modelos/bloques_obj/{obj_path.name}",
                             obj_path, "bloque_obj")
                block_stats["bloque_obj_ok"] += 1
                if collisions:
                    csv_path = out / "bloques_colision" / f"bloque_{sha}.csv"
                    with open(csv_path, "w", newline="") as fh:
                        w = csv.writer(fh)
                        w.writerow(["triangle", "v0", "v1", "v2", "cell_mask",
                                    "surface_type"])
                        for c in collisions:
                            w.writerow([c["triangle"], c["v0"], c["v1"], c["v2"],
                                        c["cell_mask"], c["surface_type"]])
                    add_artifact(rel_disc(bin_path), bin_path.stat().st_size,
                                 sha1_of(bin_path),
                                 f"extraidos/modelos/bloques_colision/{csv_path.name}",
                                 csv_path, "bloque_colision_csv")
            except Exception as exc:
                failures.append({"fuente": f"bloque_{sha}",
                                 "etapa": "parse_bloque_obj", "error": str(exc)})
                block_stats["bloque_obj_fallo"] += 1

    # ---------------------------------------------------------- tables
    wiki_argv = ["--wiki-dir", args.wiki_dir] if args.wiki_dir else []
    try:
        parse_tables_main([str(disc), str(inv)] + wiki_argv)
    except Exception:
        failures.append({"fuente": "tablas", "etapa": "parse_tables",
                         "error": traceback.format_exc(limit=3)})

    # Inventory CSVs produced by this run itself
    with open(out / "modelos_fuentes.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["origen", "archivo", "slot", "tab_raw",
                                           "tamano_descomprimido",
                                           "sha1_descomprimido", "clase"])
        w.writeheader()
        w.writerows(fuentes)
    with open(out / "fallos.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["fuente", "etapa", "error"])
        w.writeheader()
        w.writerows(failures)

    # Aggregate inventories as modelos.csv rows (primary source convention:
    # fuente = the disc file the inventory was mainly derived from).
    inv_primary = {
        "objetos.csv": "OBJECTS.bin", "objindex.csv": "OBJINDEX.bin",
        "romlists.csv": "*.romlist.zlb (124 ficheros)",
        "romlists_resumen.csv": "*.romlist.zlb (124 ficheros)",
        "mapas.csv": "MAPS.bin", "dlls.csv": "OBJECTS.bin",
        "animaciones.csv": "ANIM.BIN", "animaciones_resumen.csv": "ANIM.BIN",
        "modanim.csv": "MODANIM.BIN", "amap.csv": "AMAP.BIN",
        "modelind.csv": "MODELIND.bin", "voxmap_root.csv": "VOXMAP.bin",
        "voxmap_resumen.csv": "VOXMAP.bin",
    }
    for name, primary in inv_primary.items():
        p = inv / name
        if not p.exists():
            continue
        src = disc / primary if not primary.startswith("*") else None
        add_artifact(primary,
                     src.stat().st_size if src else "",
                     sha1_of(src) if src else "",
                     f"inventarios/{name}", p, "inventario")
    with open(inv / "modelos.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["fuente", "tamano_fuente",
                                           "sha1_fuente", "salida",
                                           "tamano_salida", "sha1_salida", "tipo"])
        w.writeheader()
        w.writerows(artifacts)

    summary = {
        "romlists": len(romlist_files),
        "model_sources": len(model_sources),
        "block_sources": len(block_sources),
        "unique_models": len(seen_models),
        "unique_blocks": len(seen_blocks),
        "model_stats": dict(model_stats),
        "block_stats": dict(block_stats),
        "fuentes_rows": len(fuentes),
        "failures": len(failures),
        "artifacts": len(artifacts),
    }
    (out / "run_summary.json").write_text(json.dumps(summary, indent=2))
    print(json.dumps(summary, indent=2))
    if failures:
        print(f"WARNING: {len(failures)} failures, see fallos.csv", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
