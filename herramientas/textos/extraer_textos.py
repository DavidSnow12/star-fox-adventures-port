#!/usr/bin/env python3
"""Extractor de textos de Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL).

Lee UNICAMENTE los ficheros gametext/*.bin del arbol del disco y emite un
JSON por idioma con los textos (IDs + frases en Unicode). No modifica el
disco: solo lectura.

Formato en disco (verificado contra los 1020 ficheros, no solo contra la
wiki de SFA-Decomp, que describe el struct C con puntero):

    u32be  num_glifos
    characterStruct[num_glifos]      ; 16 bytes cada uno:
                                     ;   u32be codepoint, u16be x, u16be y,
                                     ;   s8 left/right/top/bottom,
                                     ;   u8 width, height, font, texture
    u16be  num_textos
    u16be  long_datos_cadenas        ; bytes del bloque de cadenas, sin tabla
    gametextRec[num_textos]          ; 12 bytes cada uno, NO el struct C:
                                     ;   u16be id, u16be num_frases,
                                     ;   u8 window, u8 align_h, u8 align_v,
                                     ;   u8 idioma, u32be indice_primera_frase
    u32be  num_cadenas                ; == suma de num_frases (verificado)
    u32be  offsets[num_cadenas]       ; relativos al bloque de cadenas
    bytes  cadenas[long_datos_cadenas]
    u32be  long_bloque_desconocido     ; en todos los ficheros, bytes 0xEE
    bytes  bloque_desconocido
    fontTextures[]                   ; termina con cabecera 0,0,0,0 + 4 bytes 0

Cadenas: UTF-8. Los codigos de control son un caracter del area de uso
privado (PUA) en UTF-8 seguido de N parametros u16be. Los parametros pueden
contener bytes 0x00, asi que el final de cada cadena NO se busca por NUL:
se recorta por la tabla de offsets (el siguiente offset, o el fin del
bloque para la ultima). Al decodificar, la cadena termina en el primer
NUL a nivel de texto (los NUL de parametros de control no cuentan);
el resto de la rebanada es relleno y se ignora.
Los codigos de control se conservan en el JSON como tokens legibles, p. ej.
<E020:0> o <F8FF:255,102,102,255>, para no perder informacion ni romper
la lectura. Tabla de parametros segun la wiki y la tabla lbl_802C86F0 del
decomp (src/main/gametext.c): E000:1, E018:3, E020:1, F8F2:2, F8F3:0,
F8F4:1, F8F5:1, F8F6:1, F8F7:1, F8F8:0, F8F9:0, F8FA:0, F8FB:0, F8FC:0,
F8FD:0, F8FE:0, F8FF:4.

Ficheros que NO son gametext y NO se parsean (se copian en bruto):
    GAMETEXT.bin / GAMETEXT.tab  (disc root; versiones viejas sin uso, la
                                  wiki indica formato desconocido y dialogo
                                  antiguo ausente del juego final)
    TEXTABLE.bin                 (disc root; NO es texto: es la tabla u16
                                  de remapeo de IDs de textura, segun
                                  docs/wiki/Textures.md y texture.c)

Uso:
    python3 extraer_textos.py <dir_files_del_disco_o_gametext> <dir_salida> [inventario.csv]

    <dir_files_del_disco_o_gametext> puede ser el directorio "files" del
    disco (contiene gametext/) o el propio directorio gametext/.
    <dir_salida> recibe textos_<idioma>.json, resumen.json y brutos/.
    Si se pasa un tercer argumento, ahi se escribe el inventario CSV.

    No hay rutas absolutas hardcodeadas: todo llega por argv.
"""

import csv
import hashlib
import json
import os
import re
import shutil
import struct
import sys
from collections import Counter

# Orden fijado por sLanguageNameTable[] (src/main/gametext.c:1284).
IDIOMAS = ["English", "French", "German", "Italian", "Japanese", "Spanish"]
CODIGO_IDIOMA = {nombre: i for i, nombre in enumerate(IDIOMAS)}

# Codigo de control PUA -> numero de parametros u16be.
CONTROLES = {
    0xE000: 1,  # Seq Id
    0xE018: 3,  # Seq Time
    0xE020: 1,  # Hint ID
    0xF8F2: 2, 0xF8F3: 0, 0xF8F4: 1, 0xF8F5: 1, 0xF8F6: 1,
    0xF8F7: 1,  # Set Font (TEXT_CTRL_LANGUAGE en el decomp)
    0xF8F8: 0, 0xF8F9: 0, 0xF8FA: 0, 0xF8FB: 0,
    0xF8FC: 0, 0xF8FD: 0, 0xF8FE: 0,
    0xF8FF: 4,  # Set Color
}

GLIFO = struct.Struct(">IHHbbbbBBBB")   # 16 bytes
REGISTRO = struct.Struct(">HHBBBBI")    # 12 bytes
CABECERA_TEX = struct.Struct(">HHHH")  # 8 bytes


def sha1(path):
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for bloque in iter(lambda: f.read(1 << 20), b""):
            h.update(bloque)
    return h.hexdigest()


def sha1_bytes(data):
    return hashlib.sha1(data).hexdigest()


def idioma_de_fichero(nombre):
    """'Spanish.bin' -> 'Spanish'; '4_Spanish.bin' -> 'Spanish'."""
    base = nombre[:-4] if nombre.lower().endswith(".bin") else nombre
    if "_" in base:
        base = base.split("_", 1)[1]
    return base


def decodificar_cadena(cruda):
    """Decodifica una rebanada de cadena.

    Devuelve (texto, num_controles, tiene_no_ascii, error_o_None).
    El texto conserva los controles como tokens <XXXX:p1,p2,...>.

    Semantica del juego: la cadena termina en el primer NUL a nivel de
    texto. Los NUL que son bytes de parametros de control se consumen
    como parametros, nunca como terminador (por eso NO se hace rstrip:
    una frase que termina en un control con parametros 0x00 perderia
    esos parametros). Todo lo que sigue al terminador dentro de la
    rebanada es relleno hasta el siguiente offset y se ignora; si ese
    resto contuviera bytes distintos de NUL, se senala con el error
    'bytes tras terminador' en vez de inventar texto.
    """
    salida = []
    controles = 0
    i = 0
    cuerpo = cruda
    while i < len(cuerpo):
        b = cuerpo[i]
        if b == 0x00:
            resto = cuerpo[i + 1:]
            if any(c != 0x00 for c in resto):
                return None, controles, False, "bytes tras terminador"
            break
        if b < 0x80:
            salida.append(chr(b))
            i += 1
            continue
        if 0xC0 <= b < 0xE0:
            largo = 2
        elif 0xE0 <= b < 0xF0:
            largo = 3
        elif 0xF0 <= b < 0xF8:
            largo = 4
        else:
            return None, controles, False, "byte inicial UTF-8 invalido 0x%02x en %d" % (b, i)
        try:
            caracter = cuerpo[i:i + largo].decode("utf-8")
        except UnicodeDecodeError as exc:
            return None, controles, False, "UTF-8 invalido en %d: %s" % (i, exc)
        punto = ord(caracter)
        if punto in CONTROLES:
            nparam = CONTROLES[punto]
            params = []
            for k in range(nparam):
                pos = i + largo + 2 * k
                if pos + 2 > len(cuerpo):
                    return None, controles, False, "parametro de control truncado"
                params.append(struct.unpack(">H", cuerpo[pos:pos + 2])[0])
            controles += 1
            if params:
                salida.append("<%04X:%s>" % (punto, ",".join(str(p) for p in params)))
            else:
                salida.append("<%04X>" % punto)
            i += largo + 2 * nparam
        elif 0xE000 <= punto <= 0xF8FF:
            return None, controles, False, "PUA desconocido U+%04X" % punto
        else:
            salida.append(caracter)
            i += largo
    texto = "".join(salida)
    return texto, controles, any(ord(c) > 127 for c in texto), None


def validar_texturas(datos, inicio):
    """Recorre el bloque de texturas de fuente segun la formula de la wiki.

    Devuelve (ok, num_texturas, bytes_finales_sobrantes). La distancia de
    una textura a la siguiente es (((w*h*pixFmt)>>4)*2)+4.
    """
    off = inicio
    ntex = 0
    while True:
        if off + 8 > len(datos):
            return False, ntex, len(datos) - off
        tex_fmt, pix_fmt, w, h = CABECERA_TEX.unpack_from(datos, off)
        if w == 0 and h == 0:
            return True, ntex, len(datos) - (off + 8)
        off += (((w * h * pix_fmt) >> 4) * 2) + 4
        ntex += 1
        if ntex > 64:
            return False, ntex, len(datos) - off


def parsear_gametext(path, rel):
    """Parsea un gametext .bin. Devuelve (resultado, error_o_None)."""
    with open(path, "rb") as f:
        datos = f.read()
    if len(datos) < 4:
        return None, "fichero demasiado corto"
    (num_glifos,) = struct.unpack(">I", datos[:4])
    off = 4 + num_glifos * GLIFO.size
    if off + 4 > len(datos):
        return None, "cabecera de glifos fuera de rango"
    glifos = []
    for i in range(num_glifos):
        punto = GLIFO.unpack_from(datos, 4 + i * GLIFO.size)[0]
        glifos.append(punto)
    num_textos, long_cadenas = struct.unpack(">HH", datos[off:off + 4])
    gt = off + 4
    if gt + num_textos * REGISTRO.size > len(datos):
        return None, "tabla de textos fuera de rango"
    registros = [REGISTRO.unpack_from(datos, gt + i * REGISTRO.size)
                 for i in range(num_textos)]
    ns_off = gt + num_textos * REGISTRO.size
    (num_cadenas,) = struct.unpack(">I", datos[ns_off:ns_off + 4])
    if ns_off + 4 + num_cadenas * 4 > len(datos):
        return None, "tabla de offsets fuera de rango"
    offsets = [struct.unpack(">I", datos[ns_off + 4 + j * 4:ns_off + 8 + j * 4])[0]
               for j in range(num_cadenas)]
    s_off = ns_off + 4 + num_cadenas * 4
    if s_off + long_cadenas > len(datos):
        return None, "bloque de cadenas fuera de rango"
    bloque = datos[s_off:s_off + long_cadenas]
    # Validaciones estructurales (fallan -> fichero a brutos, no silencio).
    if num_cadenas != sum(r[1] for r in registros):
        return None, "num_cadenas %d != suma num_frases %d" % (
            num_cadenas, sum(r[1] for r in registros))
    if any(offsets[i] >= offsets[i + 1] for i in range(len(offsets) - 1)):
        return None, "offsets de cadena no estrictamente crecientes"
    if offsets and offsets[-1] >= long_cadenas:
        return None, "ultimo offset fuera del bloque de cadenas"
    if offsets and offsets[0] != 0:
        return None, "primer offset != 0"
    unk_off = s_off + long_cadenas
    if unk_off + 4 > len(datos):
        return None, "sin bloque desconocido"
    (unk_len,) = struct.unpack(">I", datos[unk_off:unk_off + 4])
    desconocido = datos[unk_off + 4:unk_off + 4 + unk_len]
    if len(desconocido) != unk_len or any(b != 0xEE for b in desconocido):
        return None, "bloque desconocido no es todo 0xEE"
    tex_ok, num_tex, sobrante = validar_texturas(datos, unk_off + 4 + unk_len)
    if not tex_ok:
        return None, "recorrido de texturas de fuente no termina"
    frases = []
    fallos = []
    for j, o in enumerate(offsets):
        fin = offsets[j + 1] if j + 1 < len(offsets) else long_cadenas
        cruda = bloque[o:fin]
        texto, nctrl, no_ascii, err = decodificar_cadena(cruda)
        if err is not None:
            fallos.append((j, err))
            frases.append(None)
        else:
            frases.append(texto)
    textos = []
    for (ident, nfr, window, ah, av, lang, primera) in registros:
        if primera + nfr > num_cadenas:
            return None, "registro id %d apunta fuera de las cadenas" % ident
        textos.append({
            "id": ident,
            "num_frases": nfr,
            "window": window,
            "align_h": ah,
            "align_v": av,
            "idioma_codigo": lang,
            "indice_primera_frase": primera,
            "frases": frases[primera:primera + nfr],
        })
    return {
        "fuente": rel,
        "num_glifos": num_glifos,
        "glifos_no_ascii": sorted({c for c in glifos if c > 127}),
        "num_textos": num_textos,
        "num_cadenas": num_cadenas,
        "num_texturas_fuente": num_tex,
        "bytes_sobrantes_tras_texturas": sobrante,
        "textos": textos,
        "fallos_frase": fallos,
    }, None


def main(argv):
    if len(argv) < 3:
        print("Uso: extraer_textos.py <dir_files_o_gametext> <dir_salida> [inventario.csv]",
              file=sys.stderr)
        return 2
    entrada, salida = argv[1], argv[2]
    inventario_csv = argv[3] if len(argv) > 3 else None

    if os.path.isdir(os.path.join(entrada, "gametext")):
        dir_gametext = os.path.join(entrada, "gametext")
        raiz = entrada
    elif os.path.basename(os.path.normpath(entrada)) == "gametext":
        dir_gametext = entrada
        raiz = os.path.dirname(os.path.normpath(entrada))
    else:
        print("No se encontro gametext/ en %s" % entrada, file=sys.stderr)
        return 2

    os.makedirs(salida, exist_ok=True)
    dir_brutos = os.path.join(salida, "brutos")
    os.makedirs(dir_brutos, exist_ok=True)

    ficheros = []
    for dirpath, _dirnames, nombres in os.walk(dir_gametext):
        for nombre in sorted(nombres):
            if nombre.lower().endswith(".bin"):
                ficheros.append(os.path.join(dirpath, nombre))
    ficheros.sort()

    por_idioma = {}
    filas_inventario = []
    fallos_archivo = []
    legados = []

    # Ficheros legacy de la raiz del disco: no se parsean, se copian en bruto.
    for nombre, motivo in [
        ("GAMETEXT.bin", "version antigua sin uso; formato desconocido (wiki Gametext)"),
        ("GAMETEXT.tab", "tabla de la version antigua sin uso"),
        ("TEXTABLE.bin", "NO es texto: tabla u16 de remapeo de IDs de textura"),
    ]:
        origen = os.path.join(raiz, nombre)
        if os.path.isfile(origen):
            destino = os.path.join(dir_brutos, nombre)
            shutil.copyfile(origen, destino)
            legados.append({"fichero": nombre, "motivo": motivo,
                            "tamano": os.path.getsize(origen),
                            "sha1": sha1(origen)})
            filas_inventario.append({
                "fuente": os.path.relpath(origen, raiz),
                "tamano_fuente": os.path.getsize(origen),
                "sha1_fuente": sha1(origen),
                "salida": os.path.join("brutos", nombre),
                "tamano_salida": os.path.getsize(destino),
                "sha1_salida": sha1(destino),
                "idioma": "",
                "num_cadenas": 0,
                "nota": "sin parsear: " + motivo,
            })

    for path in ficheros:
        rel = os.path.relpath(path, raiz)
        idioma = idioma_de_fichero(os.path.basename(path))
        if idioma not in IDIOMAS:
            fallos_archivo.append({"fichero": rel, "error": "idioma desconocido en nombre"})
            continue
        resultado, error = parsear_gametext(path, rel)
        if error is not None:
            destino = os.path.join(dir_brutos, rel.replace(os.sep, "__"))
            shutil.copyfile(path, destino)
            fallos_archivo.append({"fichero": rel, "error": error,
                                   "bruto": os.path.basename(destino)})
            continue
        # Idioma del registro vs idioma del fichero.
        mal_idioma = [t for t in resultado["textos"]
                      if t["idioma_codigo"] != CODIGO_IDIOMA[idioma]]
        if mal_idioma:
            fallos_archivo.append({"fichero": rel,
                                   "error": "%d registros con idioma_codigo distinto de %s"
                                   % (len(mal_idioma), idioma)})
        entrada_idioma = por_idioma.setdefault(idioma, {
            "archivos": [], "textos": [],
            "total_frases_con_control": 0, "total_frases_no_ascii": 0,
            "fallos_frase": [], "glifos_no_ascii": set(),
        })
        entrada_idioma["glifos_no_ascii"].update(resultado["glifos_no_ascii"])
        entrada_idioma["archivos"].append({
            "fuente": rel,
            "directorio": os.path.basename(os.path.dirname(path)),
            "archivo": os.path.basename(path),
            "tamano": os.path.getsize(path),
            "sha1": sha1(path),
            "num_glifos": resultado["num_glifos"],
            "num_textos": resultado["num_textos"],
            "num_cadenas": resultado["num_cadenas"],
            "num_texturas_fuente": resultado["num_texturas_fuente"],
        })
        for texto in resultado["textos"]:
            item = dict(texto)
            item["fuente"] = rel
            item["directorio"] = os.path.basename(os.path.dirname(path))
            entrada_idioma["textos"].append(item)
            for frase in texto["frases"]:
                if frase is None:
                    continue
                if "<" in frase and re.search(r"<[0-9A-F]{4}(:[^>]*)?>", frase):
                    entrada_idioma["total_frases_con_control"] += 1
                if any(ord(c) > 127 for c in frase):
                    entrada_idioma["total_frases_no_ascii"] += 1
        for j, err in resultado["fallos_frase"]:
            entrada_idioma["fallos_frase"].append({"fichero": rel, "frase": j, "error": err})
        # La fila de inventario se completa cuando el JSON del idioma exista.
        filas_inventario.append({
            "fuente": rel,
            "tamano_fuente": os.path.getsize(path),
            "sha1_fuente": sha1(path),
            "salida": None,  # se rellena abajo
            "tamano_salida": None,
            "sha1_salida": None,
            "idioma": idioma,
            "num_cadenas": resultado["num_cadenas"],
            "nota": "",
        })

    salidas_json = {}
    for idioma in IDIOMAS:
        if idioma not in por_idioma:
            continue
        datos_idioma = por_idioma[idioma]
        ids = [t["id"] for t in datos_idioma["textos"]]
        doc = {
            "juego": "Star Fox Adventures",
            "version": "GSAP01 Rev 1 PAL (En/Fr/De/Es/It)",
            "idioma": idioma,
            "idioma_codigo": CODIGO_IDIOMA[idioma],
            "total_archivos": len(datos_idioma["archivos"]),
            "total_textos": len(datos_idioma["textos"]),
            "total_frases": sum(t["num_frases"] for t in datos_idioma["textos"]),
            "ids_unicos": len(set(ids)),
            "frases_con_control": datos_idioma["total_frases_con_control"],
            "frases_no_ascii": datos_idioma["total_frases_no_ascii"],
            "glifos_no_ascii_union": [
                {"codepoint": c, "char": chr(c)}
                for c in sorted(datos_idioma["glifos_no_ascii"])],
            "archivos": datos_idioma["archivos"],
            "textos": datos_idioma["textos"],
            "nota_controles": "Los codigos de control PUA se conservan como "
                              "tokens <XXXX:param,...> dentro de cada frase.",
        }
        nombre_json = "textos_%s.json" % idioma
        ruta_json = os.path.join(salida, nombre_json)
        with open(ruta_json, "w", encoding="utf-8") as f:
            json.dump(doc, f, ensure_ascii=False, indent=1)
            f.write("\n")
        salidas_json[idioma] = (nombre_json, os.path.getsize(ruta_json), sha1(ruta_json))

    for fila in filas_inventario:
        if fila["salida"] is None and fila["idioma"] in salidas_json:
            nombre_json, tam, h = salidas_json[fila["idioma"]]
            fila["salida"] = nombre_json
            fila["tamano_salida"] = tam
            fila["sha1_salida"] = h

    # Resumen global (maquina) + glifos no ASCII por idioma.
    resumen = {
        "juego": "Star Fox Adventures",
        "version": "GSAP01 Rev 1 PAL",
        "total_archivos_gametext": len(ficheros),
        "por_idioma": {},
        "total_textos": 0,
        "total_frases": 0,
        "fallos_archivo": fallos_archivo,
        "legado_sin_parsear": legados,
        "codigos_control_observados": {},
    }
    # Recuento de controles observados y glifos, releyendo los JSON escritos.
    for idioma, datos_idioma in por_idioma.items():
        ctrl = Counter()
        for texto in datos_idioma["textos"]:
            for frase in texto["frases"]:
                if frase:
                    for m in re.finditer(r"<([0-9A-F]{4})(?::[^>]*)?>", frase):
                        ctrl[m.group(1)] += 1
        resumen["por_idioma"][idioma] = {
            "archivos": len(datos_idioma["archivos"]),
            "textos": len(datos_idioma["textos"]),
            "frases": sum(t["num_frases"] for t in datos_idioma["textos"]),
            "ids_unicos": len({t["id"] for t in datos_idioma["textos"]}),
            "frases_con_control": datos_idioma["total_frases_con_control"],
            "frases_no_ascii": datos_idioma["total_frases_no_ascii"],
            "fallos_frase": len(datos_idioma["fallos_frase"]),
            "json": salidas_json[idioma][0],
            "json_tamano": salidas_json[idioma][1],
            "json_sha1": salidas_json[idioma][2],
        }
        resumen["total_textos"] += resumen["por_idioma"][idioma]["textos"]
        resumen["total_frases"] += resumen["por_idioma"][idioma]["frases"]
        for codigo, n in ctrl.items():
            resumen["codigos_control_observados"][codigo] = \
                resumen["codigos_control_observados"].get(codigo, 0) + n
    with open(os.path.join(salida, "resumen.json"), "w", encoding="utf-8") as f:
        json.dump(resumen, f, ensure_ascii=False, indent=1)
        f.write("\n")

    if inventario_csv:
        os.makedirs(os.path.dirname(os.path.abspath(inventario_csv)), exist_ok=True)
        with open(inventario_csv, "w", encoding="utf-8", newline="") as f:
            w = csv.writer(f)
            w.writerow(["fuente", "tamano_fuente", "sha1_fuente", "salida",
                        "tamano_salida", "sha1_salida", "idioma", "num_cadenas", "nota"])
            for fila in filas_inventario:
                w.writerow([fila["fuente"], fila["tamano_fuente"], fila["sha1_fuente"],
                            fila["salida"], fila["tamano_salida"], fila["sha1_salida"],
                            fila["idioma"], fila["num_cadenas"], fila["nota"]])

    print("archivos gametext: %d" % len(ficheros))
    print("textos totales: %d" % resumen["total_textos"])
    print("frases totales: %d" % resumen["total_frases"])
    for idioma in IDIOMAS:
        if idioma in resumen["por_idioma"]:
            d = resumen["por_idioma"][idioma]
            print("  %-8s archivos=%d textos=%d frases=%d ids_unicos=%d" % (
                idioma, d["archivos"], d["textos"], d["frases"], d["ids_unicos"]))
    print("fallos de archivo: %d" % len(fallos_archivo))
    print("legado sin parsear (en brutos/): %d" % len(legados))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
