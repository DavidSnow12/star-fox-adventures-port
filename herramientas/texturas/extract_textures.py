#!/usr/bin/env python3
"""Extractor de texturas de Star Fox Adventures (GameCube, GSAP01 Rev 1 PAL).

Lee los bancos de texturas del disco (TEX0/TEX1 por mapa y TEXPRE
compartido) y los decodifica a PNG. No modifica el disco original: solo
lectura.

Formato de los bancos (segun docs/wiki/Textures.md y Formats.md de
SFA-Decomp, verificado contra el disco en 2026-10-25):
  * Cada banco es un par .tab/.bin. La .tab es una lista de u32
    big-endian hasta un terminador 0xFFFFFFFF. Una entrada presente
    tiene el bit 0x80000000; su campo de 6 bits en 24..29 es el numero
    de fotogramas (count) y sus 24 bits bajos son el desplazamiento
    dividido por 2 (desplazamiento en bytes = valor * 2).
  * count == 1: en ese desplazamiento hay directamente un registro
    ZLB o DIR.
  * count > 1: en ese desplazamiento hay count+1 u32 (relativos a la
    base) con los desplazamientos de los count fotogramas y un
    centinela final con el tamano total.
  * Registro ZLB: cabecera de 16 bytes ("ZLB\\0", version, tamano
    descomprimido, tamano comprimido) + flujo zlib estandar.
  * Registro DIR ("DIRn"): cabecera de 16 bytes + 16 bytes de
    prefijo + el blob de textura. El campo de tamano de la cabecera
    DIR es la longitud del blob de textura (no del registro entero);
    el cargador del juego salta 32 bytes desde el inicio del
    registro. Este extractor hace lo mismo: textura =
    registro[32:32+tamano_cabecera].
  * Un blob de textura puede a su vez empezar por ZLB/DIR (caso
    TEXPRE[0], doblemente empaquetado): se desempaqueta en
    recursion hasta 3 niveles.
  * El blob de textura es: cabecera de 0x60 bytes + datos de imagen.
    Cabecera: ancho u16 BE en 0x0A, alto u16 BE en 0x0C, formato
    GXTexFmt u8 en 0x16, campo en 0x50 (desplazamiento de la imagen
    secundaria I4 dentro de los datos, 0 si no hay).
  * Los datos de imagen son: nivel base (+ cadena de mipmaps si la
    hay) y, opcionalmente, una imagen secundaria I4 del mismo
    tamano. El extractor emite solo el nivel base como PNG
    principal; la secundaria, si existe, como PNG aparte con
    sufijo "_secondary". Los mipmaps no se emiten como PNG
    separados (son reducciones del nivel base).
  * Los datos estan embaldosados (tiled) segun el formato GX:
    I4 8x8, I8/IA4 8x4, IA8/RGB565/RGB5A3/RGBA8 4x4, CMPR 8x8
    (4 subbloques 4x4). Las dimensiones de la cabecera se recortan
    desde el tamano acolchado a multiplo de tile. Las texturas se
    emiten tal como estan almacenadas (el juego dice que muchas
    estan "al reves" y las voltea la geometria); NO se voltea nada
    aqui.

Formatos GX decodificados (valores de GXTexFmt):
  0 I4, 1 I8, 2 IA4, 3 IA8, 4 RGB565, 5 RGB5A3, 6 RGBA8, 14 CMPR.
  IA8 es (intensidad, alfa) en ese orden por pixel; IA4 es
  (intensidad en el nibble alto, alfa en el bajo). Esto se verifico
  estadisticamente sobre el corpus: en IA8 el segundo byte es 255
  en el 70% de las texturas (alfa opaco) mientras que el primero
  casi nunca lo es; en IA4 el nibble bajo es 15 en 26/28 texturas.
  CMPR: subbloques en orden fila-mayor (sup-izq, sup-der, inf-izq,
  inf-der); indices DXT1 con el primer pixel de cada fila en los
  2 bits altos del byte de la fila (verificado por suavidad de
  gradiente frente a la variante LSB-primero).
  Los formatos de paleta 8 C4, 9 C8, 10 C14X2 no aparecen en este
  disco (0 casos en 19.264 fotogramas) y, de aparecer, no se
  podrian decodificar sin la TLUT, que no va en el blob: el
  extractor los deja en bruto y lo registra.

Ademas, si se pide (por defecto si), decodifica SCREENS.bin:
  dos registros segun SCREENS.tab (desplazamientos en bytes, no
  x2), cada uno con cabecera de 16 bytes (ancho u16 BE, alto
  u16 BE) + datos 16 bpp embaldosados 4x4. El formato exacto no
  esta documentado en la wiki; se emite como RGB5A3 embaldosado
  porque (a) el embaldosado es mucho mas suave que el lineal
  (gradiente medio 3,6 frente a 8,8), (b) todos los pixeles
  tienen el bit alto a 1 y las zonas negras son exactamente
  0x8000, lo que bajo RGB565 serian rojo oscuro y bajo RGB5A3
  son negro opaco, y (c) el contenido resultante es una tira
  compacta y coherente (~200x20 px centrada sobre negro), no
  ruido. Queda marcado como supuesto en el inventario y en el
  RESUMEN.

Uso:
  python3 extract_textures.py [--disc DIR] [--out DIR]
                              [--inventory CSV] [--maps a,b | all]
                              [--no-screens] [--no-raw] [--no-numpy]
                              [--max-frames N]
  Sin argumentos, las rutas se resuelven respecto a este script:
    disc      = <raiz-del-proyecto>/disc/files
    out       = <raiz-del-proyecto>/assets/extraidos/texturas
    inventory = <raiz-del-proyecto>/assets/inventarios/texturas.csv
  donde <raiz-del-proyecto> es el directorio "starfoxadventures"
  que contiene a "assets/". No hay rutas absolutas de ninguna
  maquina hardcodeadas; --disc/--out/--inventory las sustituyen.

Requisitos: Python 3.8+, Pillow. numpy es opcional pero muy
recomendable (104 Mpx en total); sin numpy se usa un decodificador
Python puro mas lento con los mismos resultados.
"""

import argparse
import csv
import hashlib
import os
import struct
import sys
import zlib

# ---------------------------------------------------------------------------
# Constantes de formato
# ---------------------------------------------------------------------------

FMT_NAMES = {
    0: "I4",
    1: "I8",
    2: "IA4",
    3: "IA8",
    4: "RGB565",
    5: "RGB5A3",
    6: "RGBA8",
    8: "C4",
    9: "C8",
    10: "C14X2",
    14: "CMPR",
}

PALETTE_FORMATS = {8, 9, 10}

# formato -> (ancho de tile, alto de tile, bytes por tile)
TILE = {
    0: (8, 8, 32),
    1: (8, 4, 32),
    2: (8, 4, 32),
    3: (4, 4, 32),
    4: (4, 4, 32),
    5: (4, 4, 32),
    6: (4, 4, 64),
    8: (8, 8, 32),
    9: (8, 4, 32),
    10: (4, 4, 32),
    14: (8, 8, 32),
}

HEADER_SIZE = 0x60


class UnsupportedFormat(Exception):
    pass


class BadRecord(Exception):
    pass


def sha1(data):
    return hashlib.sha1(data).hexdigest()


def u32be(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def u16be(buf, off):
    return struct.unpack_from(">H", buf, off)[0]


def tile_size(width, height, fmt):
    tw, th, tb = TILE[fmt]
    return ((width + tw - 1) // tw) * ((height + th - 1) // th) * tb


def mip_sum_to(width, height, fmt, nlevels):
    """Tamano de los nlevels primeros niveles de mipmap (mitades
    enteras, con un minimo de 1 px por dimension, acolchado a tile)."""
    total = 0
    w, h = width, height
    for _ in range(nlevels):
        total += tile_size(w, h, fmt)
        w = max(1, w // 2)
        h = max(1, h // 2)
    return total


def split_main_secondary(blob, width, height, fmt):
    """Devuelve (datos_principales, datos_secundarios_o_None, n_mips).

    datos_principales incluye todos los niveles de mipmap; el
    llamador solo decodifica el nivel base (los primeros
    tile_size() bytes).

    La presencia de secundaria se decide por el campo 0x50 de
    la cabecera (desplazamiento de la imagen secundaria), no
    solo por el tamano: hay texturas cuyo tamano total ajusta
    tanto a "nivel base + I4" como a "cadena de mipmaps sin
    secundaria" (214 casos en este disco). En esos casos
    ambiguos, el campo 0x50 es el que desambigua: si es 0 no
    hay secundaria; si no es 0, es exactamente el tamano de
    los datos principales. Comprobado en los 19.264 fotogramas:
    los 944 campos 0x50 distintos de 0 coinciden con un tamano
    principal valido y el resto son 0.
    """
    payload = blob[HEADER_SIZE:]
    field50 = u32be(blob, 0x50)
    i4_size = tile_size(width, height, 0)
    if field50 != 0:
        for nlevels in range(1, 13):
            main = mip_sum_to(width, height, fmt, nlevels)
            if main == field50 and len(payload) == main + i4_size:
                return payload[:main], payload[main:], nlevels
        raise BadRecord(
            "campo 0x50=%d no ajusta a base/mipmaps+I4 (datos %d) "
            "para %dx%d fmt=%d"
            % (field50, len(payload), width, height, fmt))
    for nlevels in range(1, 13):
        main = mip_sum_to(width, height, fmt, nlevels)
        if len(payload) == main:
            return payload, None, nlevels
    raise BadRecord(
        "tamano de datos %d no ajusta a base/mipmaps para "
        "%dx%d fmt=%d" % (len(payload), width, height, fmt)
    )


# ---------------------------------------------------------------------------
# Desempaquetado ZLB / DIR
# ---------------------------------------------------------------------------

def unpack_record(data, off):
    """Desempaqueta un registro ZLB o DIR en data[off:]. Devuelve
    el blob descomprimido / sin comprimir (sin la cabecera del
    registro)."""
    if off + 16 > len(data):
        raise BadRecord("registro truncado en %d" % off)
    tag = data[off:off + 3]
    if tag == b"ZLB":
        dec = u32be(data, off + 8)
        comp = u32be(data, off + 12)
        raw = zlib.decompress(data[off + 16:off + 16 + comp])
        if len(raw) != dec:
            raise BadRecord(
                "ZLB: descomprimido %d != declarado %d" % (len(raw), dec))
        return raw
    if tag == b"DIR":
        dec = u32be(data, off + 8)
        # 16 bytes de cabecera + 16 bytes de prefijo; el campo dec
        # es la longitud del blob de textura que sigue.
        blob = data[off + 32:off + 32 + dec]
        if len(blob) != dec:
            raise BadRecord("DIR truncado: %d != %d" % (len(blob), dec))
        return blob
    raise BadRecord("magic desconocida %r en %d" % (data[off:off + 4], off))


def unpack_texture(data, off):
    """Desempaqueta un registro de textura, siguiendo el doble
    empaquetado (TEXPRE[0]: DIR que contiene un ZLB)."""
    blob = unpack_record(data, off)
    for _ in range(3):
        if len(blob) >= 4 and blob[:3] in (b"ZLB", b"DIR"):
            blob = unpack_record(blob, 0)
        else:
            break
    return blob


def parse_tab(tab_bytes):
    """Lista de entradas u32 BE hasta (sin incluir) 0xFFFFFFFF."""
    entries = []
    for off in range(0, len(tab_bytes) - 3, 4):
        value = u32be(tab_bytes, off)
        if value == 0xFFFFFFFF:
            break
        entries.append(value)
    return entries


def texture_frames(bin_bytes, tab_bytes):
    """Genera (id, frame, desplazamiento_en_bin) para cada
    fotograma presente en un banco."""
    for tex_id, entry in enumerate(parse_tab(tab_bytes)):
        if not (entry & 0x80000000):
            continue  # ausente (p. ej. 0x01000000) o palabra final
        base = (entry & 0x00FFFFFF) * 2
        count = (entry >> 24) & 0x3F
        if count == 1:
            yield tex_id, 0, base
        elif count > 1:
            offsets = [u32be(bin_bytes, base + i * 4)
                       for i in range(count + 1)]
            for frame, rel in enumerate(offsets[:-1]):
                yield tex_id, frame, base + rel
        else:
            # count == 0 con bit de presente: no observado en el
            # disco; se registra como error en el llamador.
            yield tex_id, -1, base


# ---------------------------------------------------------------------------
# Decodificadores GX (salida: bytes RGBA, fila-mayor, sin acolchado)
# ---------------------------------------------------------------------------

def _expand5(v):
    return (v << 3) | (v >> 2)


def _expand6(v):
    return (v << 2) | (v >> 4)


def _expand4(v):
    return (v << 4) | v


def _expand3(v):
    return (v << 5) | (v << 2) | (v >> 1)


def _rgb565(v):
    return (_expand5((v >> 11) & 31), _expand6((v >> 5) & 63),
            _expand5(v & 31))


def _rgb5a3(v):
    if v & 0x8000:
        return (_expand5((v >> 10) & 31), _expand5((v >> 5) & 31),
                _expand5(v & 31), 255)
    a = _expand3((v >> 12) & 7)
    return (_expand4((v >> 8) & 15), _expand4((v >> 4) & 15),
            _expand4(v & 15), a)


def _cmpr_colors(c0, c1):
    col0 = _rgb565(c0)
    col1 = _rgb565(c1)
    if c0 > c1:
        cols = [col0, col1,
                tuple((2 * col0[i] + col1[i]) // 3 for i in range(3)),
                tuple((col0[i] + 2 * col1[i]) // 3 for i in range(3))]
        alphas = (255, 255, 255, 255)
    else:
        cols = [col0, col1,
                tuple((col0[i] + col1[i]) // 2 for i in range(3)),
                (0, 0, 0)]
        alphas = (255, 255, 255, 0)
    return cols, alphas


def decode_pure(data, width, height, fmt):
    """Decodificador Python puro (fallback sin numpy). data es
    exactamente el nivel base (sin mipmaps ni secundaria)."""
    if fmt in PALETTE_FORMATS:
        raise UnsupportedFormat("formato de paleta %s sin TLUT"
                                % FMT_NAMES.get(fmt, fmt))
    if fmt not in TILE:
        raise UnsupportedFormat("formato GX desconocido %d" % fmt)
    tw, th, tb = TILE[fmt]
    tiles_x = (width + tw - 1) // tw
    tiles_y = (height + th - 1) // th
    if len(data) != tiles_x * tiles_y * tb:
        raise BadRecord("datos base %d != %d tiles esperados"
                        % (len(data), tiles_x * tiles_y * tb))
    out = bytearray(width * height * 4)

    def put(x, y, rgba):
        if x < width and y < height:
            off = (y * width + x) * 4
            out[off:off + 4] = bytes(rgba)

    tile_index = 0
    for ty in range(tiles_y):
        for tx in range(tiles_x):
            tile = data[tile_index * tb:(tile_index + 1) * tb]
            tile_index += 1
            if fmt == 0:  # I4: 8x8, 2 px/byte, nibble alto primero
                for row in range(th):
                    for col in range(tw // 2):
                        byte = tile[row * (tw // 2) + col]
                        v = _expand4(byte >> 4)
                        put(tx * tw + col * 2, ty * th + row, (v, v, v, 255))
                        v = _expand4(byte & 15)
                        put(tx * tw + col * 2 + 1, ty * th + row,
                            (v, v, v, 255))
            elif fmt == 1:  # I8: 8x4, 1 byte/px
                for row in range(th):
                    for col in range(tw):
                        v = tile[row * tw + col]
                        put(tx * tw + col, ty * th + row, (v, v, v, 255))
            elif fmt == 2:  # IA4: 8x4, (I alto, A bajo)
                for row in range(th):
                    for col in range(tw):
                        byte = tile[row * tw + col]
                        v = _expand4(byte >> 4)
                        a = _expand4(byte & 15)
                        put(tx * tw + col, ty * th + row, (v, v, v, a))
            elif fmt in (3, 4, 5):  # IA8 / RGB565 / RGB5A3: 4x4, u16 BE
                for row in range(th):
                    for col in range(tw):
                        v = u16be(tile, (row * tw + col) * 2)
                        if fmt == 3:
                            i = tile[(row * tw + col) * 2]
                            a = tile[(row * tw + col) * 2 + 1]
                            put(tx * tw + col, ty * th + row, (i, i, i, a))
                        elif fmt == 4:
                            r, g, b = _rgb565(v)
                            put(tx * tw + col, ty * th + row, (r, g, b, 255))
                        else:
                            put(tx * tw + col, ty * th + row, _rgb5a3(v))
            elif fmt == 6:  # RGBA8: 4x4, plano AR (32 B) + plano GB (32 B)
                for row in range(th):
                    for col in range(tw):
                        k = row * tw + col
                        a = tile[k * 2]
                        r = tile[k * 2 + 1]
                        g = tile[32 + k * 2]
                        b = tile[32 + k * 2 + 1]
                        put(tx * tw + col, ty * th + row, (r, g, b, a))
            elif fmt == 14:  # CMPR: 8x8 = 4 subbloques 4x4 DXT1
                for sy in range(2):
                    for sx in range(2):
                        blk = tile[(sy * 2 + sx) * 8:(sy * 2 + sx) * 8 + 8]
                        c0 = u16be(blk, 0)
                        c1 = u16be(blk, 2)
                        cols, alphas = _cmpr_colors(c0, c1)
                        for py in range(4):
                            byte = blk[4 + py]
                            for px in range(4):
                                # Primer pixel de la fila en los
                                # 2 bits altos (no LSB-primero).
                                idx = (byte >> ((3 - px) * 2)) & 3
                                r, g, b = cols[idx]
                                put(tx * tw + sx * 4 + px,
                                    ty * th + sy * 4 + py,
                                    (r, g, b, alphas[idx]))
    return bytes(out)


def decode_numpy(data, width, height, fmt):
    """Decodificador numpy (mismos resultados que decode_pure)."""
    import numpy as np
    if fmt in PALETTE_FORMATS:
        raise UnsupportedFormat("formato de paleta %s sin TLUT"
                                % FMT_NAMES.get(fmt, fmt))
    if fmt not in TILE:
        raise UnsupportedFormat("formato GX desconocido %d" % fmt)
    tw, th, tb = TILE[fmt]
    tiles_x = (width + tw - 1) // tw
    tiles_y = (height + th - 1) // th
    if len(data) != tiles_x * tiles_y * tb:
        raise BadRecord("datos base %d != %d tiles esperados"
                        % (len(data), tiles_x * tiles_y * tb))
    padded_h = tiles_y * th
    padded_w = tiles_x * tw

    def untile(arr):
        # arr: (tiles_y, tiles_x, th, tw, ...) -> (padded_h, padded_w, ...)
        axes = [0, 2, 1, 3] + list(range(4, arr.ndim))
        return arr.transpose(axes).reshape(
            (padded_h, padded_w) + arr.shape[4:])

    if fmt == 0:  # I4
        raw = np.frombuffer(data, dtype=np.uint8).reshape(
            tiles_y, tiles_x, th, tw // 2)
        hi = (raw >> 4).astype(np.uint8)
        lo = (raw & 15).astype(np.uint8)
        px = np.empty((tiles_y, tiles_x, th, tw), dtype=np.uint8)
        px[:, :, :, 0::2] = hi
        px[:, :, :, 1::2] = lo
        v = untile(px)
        v = ((v.astype(np.uint16) << 4) | v).astype(np.uint8)
        rgba = np.stack([v, v, v, np.full_like(v, 255)], axis=-1)
    elif fmt == 1:  # I8
        px = np.frombuffer(data, dtype=np.uint8).reshape(
            tiles_y, tiles_x, th, tw)
        v = untile(px)
        rgba = np.stack([v, v, v, np.full_like(v, 255)], axis=-1)
    elif fmt == 2:  # IA4
        raw = np.frombuffer(data, dtype=np.uint8).reshape(
            tiles_y, tiles_x, th, tw)
        inten = ((raw >> 4).astype(np.uint16) * 17).astype(np.uint8)
        alpha = ((raw & 15).astype(np.uint16) * 17).astype(np.uint8)
        rgba = np.stack([untile(inten), untile(inten),
                         untile(inten), untile(alpha)], axis=-1)
    elif fmt in (3, 4, 5):  # u16 BE por pixel, tile 4x4
        raw = np.frombuffer(data, dtype=">u2").reshape(
            tiles_y, tiles_x, th, tw)
        vals = untile(raw).astype(np.uint32)
        if fmt == 3:
            # Par BE (intensidad, alfa): intensidad = byte alto.
            inten = (vals >> 8) & 0xFF
            alpha = vals & 0xFF
            rgba = np.stack([inten, inten, inten, alpha], axis=-1)
        elif fmt == 4:
            r = ((vals >> 11) & 31)
            g = ((vals >> 5) & 63)
            b = vals & 31
            r = ((r << 3) | (r >> 2)).astype(np.uint8)
            g = ((g << 2) | (g >> 4)).astype(np.uint8)
            b = ((b << 3) | (b >> 2)).astype(np.uint8)
            rgba = np.stack([r, g, b, np.full_like(r, 255)], axis=-1)
        else:
            opaque = (vals & 0x8000) != 0
            r5 = (vals >> 10) & 31
            g5 = (vals >> 5) & 31
            b5 = vals & 31
            r = np.where(opaque, (r5 << 3) | (r5 >> 2),
                         ((vals >> 8) & 15) * 17)
            g = np.where(opaque, (g5 << 3) | (g5 >> 2),
                         ((vals >> 4) & 15) * 17)
            b = np.where(opaque, (b5 << 3) | (b5 >> 2),
                         (vals & 15) * 17)
            a3 = (vals >> 12) & 7
            a = np.where(opaque, 255, (a3 << 5) | (a3 << 2) | (a3 >> 1))
            rgba = np.stack([r.astype(np.uint8), g.astype(np.uint8),
                             b.astype(np.uint8), a.astype(np.uint8)],
                            axis=-1)
        rgba = rgba.astype(np.uint8)
    elif fmt == 6:  # RGBA8
        raw = np.frombuffer(data, dtype=np.uint8).reshape(
            tiles_y, tiles_x, 2, th, tw, 2)
        # plano 0: (A, R); plano 1: (G, B)
        a = untile(raw[:, :, 0, :, :, 0])
        r = untile(raw[:, :, 0, :, :, 1])
        g = untile(raw[:, :, 1, :, :, 0])
        b = untile(raw[:, :, 1, :, :, 1])
        rgba = np.stack([r, g, b, a], axis=-1)
    elif fmt == 14:  # CMPR
        raw = np.frombuffer(data, dtype=np.uint8).reshape(
            tiles_y, tiles_x, 2, 2, 8)
        c0 = (raw[:, :, :, :, 0].astype(np.uint32) << 8) | \
            raw[:, :, :, :, 1].astype(np.uint32)
        c1 = (raw[:, :, :, :, 2].astype(np.uint32) << 8) | \
            raw[:, :, :, :, 3].astype(np.uint32)
        idx_bytes = raw[:, :, :, :, 4:8]  # (..., 4 filas)
        shifts = np.array([6, 4, 2, 0], dtype=np.uint32)
        idx = ((idx_bytes[:, :, :, :, :, None] >> shifts) & 3)
        # idx: (ty, tx, sy, sx, fila, col)
        idx = idx.reshape(tiles_y, tiles_x, 2, 2, 4, 4)
        col0 = np.stack([_expand5_np((c0 >> 11) & 31),
                         _expand6_np((c0 >> 5) & 63),
                         _expand5_np(c0 & 31)], axis=-1)
        col1 = np.stack([_expand5_np((c1 >> 11) & 31),
                         _expand6_np((c1 >> 5) & 63),
                         _expand5_np(c1 & 31)], axis=-1)
        opaque = c0 > c1
        col2 = np.where(opaque[..., None],
                        (2 * col0.astype(np.uint16) +
                         col1.astype(np.uint16)) // 3,
                        (col0.astype(np.uint16) +
                         col1.astype(np.uint16)) // 2).astype(np.uint8)
        col3 = np.where(opaque[..., None],
                        (col0.astype(np.uint16) +
                         2 * col1.astype(np.uint16)) // 3,
                        0).astype(np.uint8)
        cols = np.stack([col0, col1, col2, col3], axis=-2)
        # cols: (ty, tx, sy, sx, 4, 3); reunir por indice.
        # Aplanar fila/columna del subbloque (16 px) para usar
        # take_along_axis sobre el eje de color.
        idx_flat = idx.reshape(tiles_y, tiles_x, 2, 2, 16)
        idx_exp = np.broadcast_to(idx_flat[..., None],
                                  idx_flat.shape + (3,))
        gathered_flat = np.take_along_axis(cols, idx_exp, axis=-2)
        gathered = gathered_flat.reshape(
            tiles_y, tiles_x, 2, 2, 4, 4, 3)
        # alfa: 0 solo si indice 3 y bloque no opaco
        alpha = np.where((idx == 3) & (~opaque[..., None, None]),
                         0, 255).astype(np.uint8)
        tile_rgba = np.concatenate(
            [gathered, alpha[..., None]], axis=-1)
        # tile_rgba: (ty, tx, sy, sx, 4, 4, 4) -> (ty, sy, 4, tx, sx, 4)
        tile_rgba = tile_rgba.transpose(0, 2, 4, 1, 3, 5, 6)
        rgba = tile_rgba.reshape(padded_h, padded_w, 4)
    else:  # pragma: no cover - formatos ya filtrados arriba
        raise UnsupportedFormat("formato GX %d" % fmt)
    return rgba[:height, :width, :].tobytes()


def _expand5_np(v):
    import numpy as np
    return ((v << 3) | (v >> 2)).astype(np.uint8)


def _expand6_np(v):
    import numpy as np
    return ((v << 2) | (v >> 4)).astype(np.uint8)


def decode(data, width, height, fmt, use_numpy):
    if use_numpy:
        try:
            import numpy  # noqa: F401
        except ImportError:
            use_numpy = False
    if use_numpy:
        return decode_numpy(data, width, height, fmt)
    return decode_pure(data, width, height, fmt)


# ---------------------------------------------------------------------------
# Escritura PNG e inventario
# ---------------------------------------------------------------------------

def save_png(path, width, height, rgba_bytes):
    from PIL import Image
    img = Image.frombytes("RGBA", (width, height), rgba_bytes)
    img.save(path, format="PNG")


def process_bank(bin_path, tab_path, source, bank, out_png_dir,
                 rows, stats, use_numpy, max_frames):
    """Procesa un banco TEX0/TEX1/TEXPRE. rows: lista de filas CSV."""
    with open(bin_path, "rb") as fh:
        bin_bytes = fh.read()
    with open(tab_path, "rb") as fh:
        tab_bytes = fh.read()
    for tex_id, frame, off in texture_frames(bin_bytes, tab_bytes):
        if max_frames is not None and stats["frames"] >= max_frames:
            return
        if frame < 0:
            stats["errors"] += 1
            stats["error_list"].append(
                "%s/%s id=%d: count=0 con bit de presente" %
                (source, bank, tex_id))
            continue
        stats["frames"] += 1
        base_name = "%s_%04d_f%d" % (bank, tex_id, frame)
        try:
            blob = unpack_texture(bin_bytes, off)
        except Exception as exc:  # noqa: BLE001 - se registra y sigue
            stats["errors"] += 1
            stats["error_list"].append(
                "%s/%s id=%d f=%d: %s" % (source, bank, tex_id, frame, exc))
            rows.append([_raw_row(source, bank, tex_id, frame, bin_bytes,
                                  off, out_png_dir, stats)])
            continue
        if len(blob) < HEADER_SIZE:
            stats["errors"] += 1
            stats["error_list"].append(
                "%s/%s id=%d f=%d: blob corto %d" %
                (source, bank, tex_id, frame, len(blob)))
            continue
        width = u16be(blob, 0x0A)
        height = u16be(blob, 0x0C)
        fmt = blob[0x16]
        fmt_name = FMT_NAMES.get(fmt, "GX%d" % fmt)
        fuente = "%s/%s.bin#id=%d frame=%d" % (source, bank, tex_id, frame)
        if width == 0 or height == 0 or fmt not in TILE:
            stats["undecoded"] += 1
            stats["undecoded_list"].append(
                (fuente, fmt_name, width, height,
                 "dimensiones/formato no valido"))
            _write_raw_blob(rows, fuente, blob, out_png_dir, source,
                            base_name, fmt_name, stats)
            continue
        try:
            main, secondary, nmips = split_main_secondary(
                blob, width, height, fmt)
        except Exception as exc:  # noqa: BLE001
            stats["undecoded"] += 1
            stats["undecoded_list"].append(
                (fuente, fmt_name, width, height, str(exc)))
            _write_raw_blob(rows, fuente, blob, out_png_dir, source,
                            base_name, fmt_name, stats)
            continue
        stats["by_format"][fmt_name] = stats["by_format"].get(fmt_name, 0) + 1
        if nmips > 1:
            stats["with_mipmaps"] += 1
        base_size = tile_size(width, height, fmt)
        try:
            rgba = decode(main[:base_size], width, height, fmt, use_numpy)
        except UnsupportedFormat as exc:
            stats["undecoded"] += 1
            stats["undecoded_list"].append(
                (fuente, fmt_name, width, height, str(exc)))
            _write_raw_blob(rows, fuente, blob, out_png_dir, source,
                            base_name, fmt_name, stats)
            continue
        except Exception as exc:  # noqa: BLE001
            stats["errors"] += 1
            stats["error_list"].append(
                "%s: decodificacion %s" % (fuente, exc))
            _write_raw_blob(rows, fuente, blob, out_png_dir, source,
                            base_name, fmt_name, stats)
            continue
        out_rel = "%s/%s.png" % (source, base_name)
        out_path = os.path.join(out_png_dir, out_rel)
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        save_png(out_path, width, height, rgba)
        with open(out_path, "rb") as fh:
            png_bytes = fh.read()
        rows.append([fuente, len(blob), sha1(blob), out_rel,
                     len(png_bytes), sha1(png_bytes), fmt_name,
                     "%dx%d" % (width, height)])
        stats["png_main"] += 1
        if secondary is not None:
            stats["with_secondary"] += 1
            try:
                rgba2 = decode(secondary, width, height, 0, use_numpy)
            except Exception as exc:  # noqa: BLE001
                stats["errors"] += 1
                stats["error_list"].append(
                    "%s secundaria: %s" % (fuente, exc))
                continue
            out_rel2 = "%s/%s_secondary.png" % (source, base_name)
            out_path2 = os.path.join(out_png_dir, out_rel2)
            save_png(out_path2, width, height, rgba2)
            with open(out_path2, "rb") as fh:
                png2_bytes = fh.read()
            rows.append(["%s secondary=I4" % fuente, len(secondary),
                         sha1(secondary), out_rel2, len(png2_bytes),
                         sha1(png2_bytes), "I4-secundaria",
                         "%dx%d" % (width, height)])
            stats["png_secondary"] += 1


def _write_raw_blob(rows, fuente, blob, out_png_dir, source, base_name,
                    fmt_name, stats):
    raw_rel = "raw/%s_%s.bin" % (source, base_name)
    raw_path = os.path.join(out_png_dir, raw_rel)
    os.makedirs(os.path.dirname(raw_path), exist_ok=True)
    with open(raw_path, "wb") as fh:
        fh.write(blob)
    rows.append([fuente, len(blob), sha1(blob), raw_rel, len(blob),
                 sha1(blob), fmt_name, ""])
    stats["raw_files"] += 1


def _raw_row(source, bank, tex_id, frame, bin_bytes, off, out_png_dir,
             stats):
    # Fallback para registros que ni siquiera desempaquetan: se
    # guarda el resto del bin desde el desplazamiento como bruto.
    # No deberia ocurrir en este disco (0 casos en el sondeo).
    raw_rel = "raw/%s_%s_%04d_f%d.bin" % (source, bank, tex_id, frame)
    raw_path = os.path.join(out_png_dir, raw_rel)
    os.makedirs(os.path.dirname(raw_path), exist_ok=True)
    chunk = bin_bytes[off:off + 1024]
    with open(raw_path, "wb") as fh:
        fh.write(chunk)
    stats["raw_files"] += 1
    return ["%s/%s.bin#id=%d frame=%d" % (source, bank, tex_id, frame),
            len(chunk), sha1(chunk), raw_rel, len(chunk), sha1(chunk),
            "registro-ilegible", ""]


def process_screens(disc_dir, out_png_dir, rows, stats, use_numpy):
    bin_path = os.path.join(disc_dir, "SCREENS.bin")
    tab_path = os.path.join(disc_dir, "SCREENS.tab")
    if not (os.path.exists(bin_path) and os.path.exists(tab_path)):
        return
    with open(bin_path, "rb") as fh:
        bin_bytes = fh.read()
    with open(tab_path, "rb") as fh:
        tab_bytes = fh.read()
    for img_idx, off in enumerate(parse_tab(tab_bytes)):
        record = bin_bytes[off:off + 16 + 320 * 240 * 2]
        # La cabecera real da las dimensiones; no se asumen.
        if len(record) < 16:
            continue
        width = u16be(record, 0)
        height = u16be(record, 2)
        pix = record[16:16 + width * height * 2]
        if len(pix) != width * height * 2:
            stats["errors"] += 1
            stats["error_list"].append(
                "SCREENS imagen %d: pixeles truncados" % img_idx)
            continue
        rgba = decode(pix, width, height, 5, use_numpy)
        out_rel = "screens/screens_%d.png" % img_idx
        out_path = os.path.join(out_png_dir, out_rel)
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        save_png(out_path, width, height, rgba)
        with open(out_path, "rb") as fh:
            png_bytes = fh.read()
        fuente = "SCREENS.bin#imagen=%d" % img_idx
        rows.append([fuente, len(record), sha1(record), out_rel,
                     len(png_bytes), sha1(png_bytes),
                     "RGB5A3-embaldosado-supuesto",
                     "%dx%d" % (width, height)])
        stats["png_screens"] += 1


def copy_raw_file(disc_dir, filename, out_png_dir, rows, stats,
                  fmt_note):
    path = os.path.join(disc_dir, filename)
    if not os.path.exists(path):
        stats["error_list"].append("falta %s en el disco" % filename)
        return
    with open(path, "rb") as fh:
        data = fh.read()
    raw_rel = "raw/%s" % filename
    raw_path = os.path.join(out_png_dir, raw_rel)
    os.makedirs(os.path.dirname(raw_path), exist_ok=True)
    with open(raw_path, "wb") as fh:
        fh.write(data)
    rows.append([filename, len(data), sha1(data), raw_rel, len(data),
                 sha1(data), fmt_note, ""])
    stats["raw_files"] += 1


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def default_paths():
    here = os.path.dirname(os.path.abspath(__file__))
    # .../starfoxadventures/assets/herramientas/texturas ->
    # .../starfoxadventures
    root = os.path.dirname(os.path.dirname(os.path.dirname(here)))
    return (os.path.join(root, "disc", "files"),
            os.path.join(root, "assets", "extraidos", "texturas"),
            os.path.join(root, "assets", "inventarios", "texturas.csv"))


def main(argv=None):
    disc_d, out_d, inv_d = default_paths()
    parser = argparse.ArgumentParser(
        description="Extractor de texturas de Star Fox Adventures.")
    parser.add_argument("--disc", default=disc_d,
                        help="directorio files/ del disco (por defecto, "
                        "relativo a este script)")
    parser.add_argument("--out", default=out_d,
                        help="directorio de salida de texturas")
    parser.add_argument("--inventory", default=inv_d,
                        help="CSV de inventario a escribir")
    parser.add_argument("--maps", default="all",
                        help="'all' o lista de mapas separada por comas")
    parser.add_argument("--no-screens", action="store_true",
                        help="no procesar SCREENS.bin")
    parser.add_argument("--no-raw", action="store_true",
                        help="no copiar los ficheros brutos no decodificables")
    parser.add_argument("--no-numpy", action="store_true",
                        help="forzar el decodificador Python puro")
    parser.add_argument("--max-frames", type=int, default=None,
                        help="limite de fotogramas (pruebas)")
    args = parser.parse_args(argv)

    use_numpy = not args.no_numpy
    if use_numpy:
        try:
            import numpy  # noqa: F401
        except ImportError:
            print("aviso: numpy no disponible, usando decodificador "
                  "Python puro (lento)", file=sys.stderr)
            use_numpy = False

    rows = []
    stats = {"frames": 0, "png_main": 0, "png_secondary": 0,
             "png_screens": 0, "raw_files": 0, "errors": 0,
             "undecoded": 0, "with_mipmaps": 0, "with_secondary": 0,
             "by_format": {}, "error_list": [], "undecoded_list": []}
    png_dir = args.out
    os.makedirs(png_dir, exist_ok=True)

    # Bancos de la raiz (TEXPRE compartido + copias raiz de TEX0/TEX1,
    # que la wiki marca como no usadas pero se extraen igual y se
    # etiquetan como root para no mezclarlas con las de mapa).
    for bank in ("TEXPRE", "TEX0", "TEX1"):
        bin_path = os.path.join(args.disc, "%s.bin" % bank)
        tab_path = os.path.join(args.disc, "%s.tab" % bank)
        if os.path.exists(bin_path) and os.path.exists(tab_path):
            process_bank(bin_path, tab_path, "root", bank, png_dir,
                         rows, stats, use_numpy, args.max_frames)

    # Bancos por mapa.
    if args.maps == "all":
        map_names = sorted(
            name for name in os.listdir(args.disc)
            if os.path.isdir(os.path.join(args.disc, name))
            and os.path.exists(os.path.join(args.disc, name, "TEX0.tab")))
    else:
        map_names = [m.strip() for m in args.maps.split(",") if m.strip()]
    for map_name in map_names:
        for bank in ("TEX0", "TEX1"):
            bin_path = os.path.join(args.disc, map_name, "%s.bin" % bank)
            tab_path = os.path.join(args.disc, map_name, "%s.tab" % bank)
            if os.path.exists(bin_path) and os.path.exists(tab_path):
                process_bank(bin_path, tab_path, map_name, bank, png_dir,
                             rows, stats, use_numpy, args.max_frames)

    if not args.no_screens:
        process_screens(args.disc, png_dir, rows, stats, use_numpy)

    if not args.no_raw:
        copy_raw_file(args.disc, "FONTS.bin", png_dir, rows, stats,
                      "fuente-sin-formato-GX")
        copy_raw_file(args.disc, "SPRITES.bin", png_dir, rows, stats,
                      "metadatos-sprite-sin-pixeles")
        copy_raw_file(args.disc, "SPRITES.tab", png_dir, rows, stats,
                      "metadatos-sprite-sin-pixeles")
        copy_raw_file(args.disc, "SPRTABLE.bin", png_dir, rows, stats,
                      "tabla-vacia-ceros")
        copy_raw_file(args.disc, "CACHEFONTSTEX.bin", png_dir, rows,
                      stats, "vacio-0-bytes")

    os.makedirs(os.path.dirname(os.path.abspath(args.inventory)),
                exist_ok=True)
    with open(args.inventory, "w", newline="", encoding="utf-8") as fh:
        writer = csv.writer(fh)
        writer.writerow(["fuente", "tamano_fuente", "sha1_fuente",
                         "salida", "tamano_salida", "sha1_salida",
                         "formato", "dimensiones"])
        writer.writerows(rows)

    print("fotogramas TEX procesados: %d" % stats["frames"])
    print("PNG principales: %d" % stats["png_main"])
    print("PNG secundarias I4: %d" % stats["png_secondary"])
    print("PNG SCREENS: %d" % stats["png_screens"])
    print("ficheros en bruto: %d" % stats["raw_files"])
    print("con mipmaps (solo nivel base emitido): %d"
          % stats["with_mipmaps"])
    print("con secundaria I4: %d" % stats["with_secondary"])
    print("formatos: %s" % stats["by_format"])
    print("no decodificados: %d" % stats["undecoded"])
    print("errores: %d" % stats["errors"])
    for line in stats["error_list"][:20]:
        print("  ERROR: %s" % line)
    for item in stats["undecoded_list"][:20]:
        print("  SIN DECODIFICAR: %s" % (item,))
    print("inventario: %s (%d filas)" % (args.inventory, len(rows)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
