#!/usr/bin/env python3
"""Convierte SFA-Decomp config/GSAP01_rev1/symbols.txt (formato decomp-toolkit)
al formato de mapa de DolRecomp (symbol_map.c:parse_line, 3 tokens: ADDR SIZE NAME).
- Entrada:  name = section:0xADDR; // type:TYPE size:0xSIZE scope:... [hidden]
- Salida:   0xADDR 0xSIZE name   (una linea por simbolo; hex sin prefijo tambien vale,
  pero se conserva 0x porque parse_hex lo acepta)
- Se conservan TODOS los simbolos tipados; DolRecomp descarta en carga los de
  direccion no multiplo de 4 (se cuentan aqui como 'skipped_by_dolrecomp').
- Los nombres que empiezan por '.' o '*' tambien los descarta DolRecomp (valid_name).
"""
import re, sys, collections
src, dst = sys.argv[1], sys.argv[2]
pat = re.compile(r'^(\S+)\s*=\s*([^:]+):(0x[0-9A-Fa-f]+);\s*//\s*type:(\w+)(?:\s+size:(0x[0-9A-Fa-f]+))?')
counts = collections.Counter(); skipped_align = 0; skipped_name = 0; seen = set(); dups = 0
out = open(dst, 'w')
with open(src) as f:
    for line in f:
        line = line.rstrip('\n')
        m = pat.match(line)
        if not m:
            counts['unparsed'] += 1; continue
        name, section, addr_s, typ, size_s = m.groups()
        addr = int(addr_s, 16); size = int(size_s, 16) if size_s else 0
        counts[f'type:{typ}'] += 1; counts[f'section:{section}'] += 1
        if addr % 4 != 0:
            skipped_align += 1; counts['skipped_align'] += 1
        if name.startswith(('.', '*')):
            skipped_name += 1; counts['skipped_name'] += 1
        key = (addr, name)
        if key in seen: dups += 1; counts['dup_addr_name'] += 1
        seen.add(key)
        out.write(f"{addr_s} {size_s if size_s else '0x0'} {name}\n")
out.close()
print(f"total_lines_written={sum(1 for _ in open(dst))}")
print(f"duplicates_addr_name={dups} skipped_align={skipped_align} skipped_name_dot_star={skipped_name}")
for k in sorted(counts): print(f"{k}={counts[k]}")
