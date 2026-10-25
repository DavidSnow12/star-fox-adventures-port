#!/usr/bin/env python3
"""Extractor de video THP de GameCube (formato Nintendo THP v1.0 / v1.1).

Extrae de un archivo .thp:
  * cada frame de video como JPEG estandar (los frames THP son "quasi-JPEG":
    en los datos de scan los bytes 0xFF van SIN el byte 0x00 de relleno que
    exige el estandar JPEG; aqui se repone ese relleno y se recorta la cola
    tras el marcador EOI, de modo que el JPEG resultante abre en cualquier
    visor/decodificador JPEG normal), y
  * el audio como un unico WAV PCM s16le, decodificando el ADPCM propio de
    THP (variante del ADPCM del DSP de GameCube, NO el ADPCM estandar de
    los .dsp: cada frame de audio lleva su propia tabla de coeficientes
    y su propio estado previo en la cabecera).

Formato THP (verificado contra starfox.thp; referencia: YAGCD sec. 15.34,
"Yet Another GameCube Documentation", y la cabecera real del archivo):

  Cabecera THP (48 bytes, big-endian):
    +0x00  u32  magic "THP\\0" (0x54485000)
    +0x04  u32  version (0x00010000 = v1.0, 0x00011000 = v1.1)
    +0x08  u32  maxBufferSize: tamano maximo de un frame completo
    +0x0C  u32  maxAudioSamples: != 0 si hay sonido; max. muestras/frame
    +0x10  f32  fps
    +0x14  u32  numFrames
    +0x18  u32  firstFrameSize: tamano del primer frame (cabecera+video+audio)
    +0x1C  u32  dataSize: tamano de todos los frames (sin cabeceras THP)
    +0x20  u32  componentDataOffset (48 en starfox.thp)
    +0x24  u32  offsetsDataOffset (0 = sin tabla de offsets, como aqui)
    +0x28  u32  firstFrameOffset
    +0x2C  u32  lastFrameOffset

  Componentes (en componentDataOffset):
    u32 numComponents, seguido de 16 bytes de tipos (0 = video, 1 = audio,
    0xFF = vacio; solo los numComponents primeros son validos), y despues
    una estructura de info por componente, en el mismo orden:
      VideoInfo: u32 width, u32 height (+ u32 unknown solo en v1.1)
      AudioInfo: u32 numChannels, u32 sampleRate, u32 numSamples total
                 (+ u32 numData solo en v1.1: n. de frames de audio por
                 frame de video; en v1.0 es siempre 1)

  Frame (en firstFrameOffset, encadenados):
    cabecera de 16 bytes (12 si no hay audio):
      u32 nextTotalSize: tamano TOTAL del frame SIGUIENTE
      u32 prevTotalSize: tamano TOTAL del frame ANTERIOR
      u32 imageSize:     bytes de video de ESTE frame
      u32 audioSize:     bytes de audio de ESTE frame (solo con audio)
    seguidos de imageSize bytes de video ("quasi-JPEG") y audioSize bytes
    de audio. El tamano almacenado de cada frame es el total anterior
    redondeado hacia arriba a multiplo de 32 bytes (relleno con ceros);
    nextTotalSize/prevTotalSize enlazan esos tamanos almacenados (en
    starfox.thp la cadena es incluso circular: prev del frame 0 = tamano
    del ultimo frame y next del ultimo = tamano del primero).

  Frame de audio (80 bytes de cabecera + numChannels * channelSize bytes):
    +0x00 u32 channelSize: bytes de ADPCM por canal
    +0x04 u32 numSamples:  muestras por canal en este frame
    +0x08 s16[16] tabla de coeficientes del canal 1 (punto fijo 5.11)
    +0x28 s16[16] tabla de coeficientes del canal 2 (siempre presente)
    +0x48 s16 channel1Prev1, s16 channel1Prev2
    +0x4C s16 channel2Prev1, s16 channel2Prev2
    Despues: channelSize bytes del canal 1 y luego del canal 2.
    audioSize == 80 + numChannels * channelSize (verificado en todos los
    frames de starfox.thp).
    Los datos son paquetes de 8 bytes = 14 muestras:
      byte 0: index = (b >> 4) & 0x7 (el bit alto se ignora),
              exponent = b & 0xF
              factor1 = tabla[2*index] / 2^11
              factor2 = tabla[2*index + 1] / 2^11
      bytes 1..7: 14 nibbles de 4 bits con signo (complemento a dos).
      muestra = clamp_s16(((prev1*factor1 + prev2*factor2) en entera
                >> 11) + (nibble << exponent)); luego prev2 = prev1,
                prev1 = muestra.
    Si numSamples no es multiplo de 14 (solo ocurre en el ultimo frame),
    se emiten exactamente numSamples muestras y se descarta la cola del
    ultimo paquete.

  Historia del decodificador de audio (--audio-history):
    header  (defecto): cada frame se decodifica con el estado previo de
            su propia cabecera (prev1/prev2). Es lo que el formato
            especifica y permite decodificar/buscar por frames sueltos.
    carried: el estado se arrastra de frame en frame (solo el primer
            frame usa su cabecera). Es lo que hace el decodificador
            adpcm_thp de ffmpeg; coincide con el WAV de ffmpeg salvo en
            el ultimo frame (ver RESUMEN.md de la extraccion).

Uso:
  thp_extract.py ENTRADA.thp --out DIR_SALIDA [--inventory CSV]
                     [--audio-history header|carried] [--no-audio]
                     [--frame-prefix PREFIJO]
Sin rutas absolutas hardcodeadas: ENTRADA y --out son argumentos.
Por defecto --out es "video_extraido" en el directorio actual y el
inventario CSV se escribe en <out>/../video.csv si no se da --inventory.
"""

import argparse
import csv
import hashlib
import os
import struct
import sys
import wave

MAGIC = b"THP\x00"
VERSION_1_0 = 0x00010000
VERSION_1_1 = 0x00011000


def u32be(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def s16be(buf, off):
    return struct.unpack_from(">h", buf, off)[0]


def f32be(buf, off):
    return struct.unpack_from(">f", buf, off)[0]


def pad32(n):
    return (n + 31) // 32 * 32


def clamp_s16(v):
    return -32768 if v < -32768 else (32767 if v > 32767 else v)


class ThpError(Exception):
    pass


class ThpHeader:
    def __init__(self, data):
        if len(data) < 48:
            raise ThpError("archivo demasiado corto para una cabecera THP (48 bytes)")
        if data[0:4] != MAGIC:
            raise ThpError("magic incorrecto: %r (se esperaba b'THP\\x00')" % data[0:4])
        self.version = u32be(data, 4)
        if self.version not in (VERSION_1_0, VERSION_1_1):
            raise ThpError("version THP no soportada: 0x%08x" % self.version)
        self.max_buffer_size = u32be(data, 8)
        self.max_audio_samples = u32be(data, 12)
        self.fps = f32be(data, 16)
        self.num_frames = u32be(data, 20)
        self.first_frame_size = u32be(data, 24)
        self.data_size = u32be(data, 28)
        self.component_data_offset = u32be(data, 32)
        self.offsets_data_offset = u32be(data, 36)
        self.first_frame_offset = u32be(data, 40)
        self.last_frame_offset = u32be(data, 44)
        self.has_audio = False
        self.width = self.height = None
        self.num_channels = 0
        self.sample_rate = 0
        self.total_samples = 0
        self.num_data = 1  # v1.0: un frame de audio por frame de video
        self._parse_components(data)

    def _parse_components(self, data):
        off = self.component_data_offset
        num_components = u32be(data, off)
        types = data[off + 4:off + 20]
        info_off = off + 20
        for i in range(num_components):
            ctype = types[i]
            if ctype == 0:  # video
                self.width = u32be(data, info_off)
                self.height = u32be(data, info_off + 4)
                info_off += 12 if self.version == VERSION_1_1 else 8
            elif ctype == 1:  # audio
                self.has_audio = True
                self.num_channels = u32be(data, info_off)
                self.sample_rate = u32be(data, info_off + 4)
                self.total_samples = u32be(data, info_off + 8)
                if self.version == VERSION_1_1:
                    self.num_data = u32be(data, info_off + 12)
                    info_off += 16
                else:
                    info_off += 12
            elif ctype == 0xFF:
                continue
            else:
                raise ThpError("tipo de componente desconocido: 0x%02x" % ctype)
        if self.width is None:
            raise ThpError("THP sin componente de video")


def walk_frames(data, header):
    """Recorre los frames encadenados. Devuelve lista de dicts con offsets
    y tamanos, y la lista de errores de cadena (vacia si todo enlaza)."""
    frames = []
    errors = []
    off = header.first_frame_offset
    header_size = 16 if header.has_audio else 12
    for i in range(header.num_frames):
        if off + header_size > len(data):
            errors.append("frame %d: cabecera fuera del archivo (offset %d)" % (i, off))
            break
        nxt = u32be(data, off)
        prv = u32be(data, off + 4)
        image_size = u32be(data, off + 8)
        audio_size = u32be(data, off + 12) if header.has_audio else 0
        stored = pad32(header_size + image_size + audio_size)
        frames.append({
            "index": i, "offset": off, "next": nxt, "prev": prv,
            "image_size": image_size, "audio_size": audio_size,
            "stored_size": stored,
            "video_off": off + header_size,
            "audio_off": off + header_size + image_size,
            "padding": stored - (header_size + image_size + audio_size),
        })
        if i > 0:
            if prv != frames[i - 1]["stored_size"]:
                errors.append("frame %d: prevTotalSize %d != tamano del frame "
                              "anterior %d" % (i, prv, frames[i - 1]["stored_size"]))
            if frames[i - 1]["next"] != stored:
                errors.append("frame %d: nextTotalSize del frame anterior %d "
                              "!= tamano de este frame %d" % (i - 1, frames[i - 1]["next"], stored))
        off += stored
    if frames:
        if frames[0]["offset"] != header.first_frame_offset:
            errors.append("primer frame fuera de firstFrameOffset")
        if frames[-1]["offset"] != header.last_frame_offset:
            errors.append("ultimo frame en %d, pero lastFrameOffset = %d"
                          % (frames[-1]["offset"], header.last_frame_offset))
        if off != len(data):
            errors.append("tras el ultimo frame quedan %d bytes (offset %d, "
                          "tamano %d)" % (len(data) - off, off, len(data)))
    return frames, errors


def quasi_jpeg_to_jpeg(raw):
    """Convierte un frame de video THP ("quasi-JPEG") en un JPEG estandar.

    Recorre los segmentos JPEG hasta el SOS (Start Of Scan, 0xFFDA); entre
    el fin del segmento SOS y el EOI (0xFFD9, buscado hacia atras desde el
    final del buffer) cada byte 0xFF bare se convierte en 0xFF 0x00. Los
    bytes tras el EOI (cola de ceros que a veces incluye imageSize) se
    descartan. Devuelve (jpeg_bytes, n_stuffed, n_trailing_trimmed).
    """
    if raw[0:2] != b"\xff\xd8":
        raise ThpError("frame de video sin SOI JPEG (0xFFD8)")
    pos = 2
    sos_end = None
    while pos < len(raw) - 1:
        if raw[pos] != 0xFF:
            raise ThpError("marcador JPEG esperado en %d, hay 0x%02x" % (pos, raw[pos]))
        marker = raw[pos + 1]
        if marker == 0xDA:  # SOS
            seg_len = struct.unpack_from(">H", raw, pos + 2)[0]
            sos_end = pos + 2 + seg_len
            break
        if marker == 0xD8 or marker == 0x01 or 0xD0 <= marker <= 0xD7:
            pos += 2
            continue
        seg_len = struct.unpack_from(">H", raw, pos + 2)[0]
        pos += 2 + seg_len
    if sos_end is None:
        raise ThpError("frame JPEG sin segmento SOS (0xFFDA)")
    eoi = raw.rfind(b"\xff\xd9")
    if eoi < sos_end:
        raise ThpError("frame JPEG sin EOI (0xFFD9)")
    head, scan = raw[:sos_end], raw[sos_end:eoi]
    out = bytearray(head)
    stuffed = 0
    for byte in scan:
        if byte == 0xFF:
            out += b"\xff\x00"
            stuffed += 1
        else:
            out.append(byte)
    out += b"\xff\xd9"
    return bytes(out), stuffed, len(raw) - (eoi + 2)


def decode_audio_frame(data, audio_off, audio_size, num_channels, history):
    """Decodifica un frame de audio THP.

    history: None -> se inicializa con el estado previo de la cabecera de
    este frame (modo 'header'); lista [prev1, prev2] por canal -> se usa
    como estado inicial y se actualiza in situ (modo 'carried').
    Devuelve (muestras_por_canal, info, history_actualizado)."""
    if audio_size < 80:
        raise ThpError("frame de audio de %d bytes (< 80 de cabecera)" % audio_size)
    channel_size = u32be(data, audio_off)
    num_samples = u32be(data, audio_off + 4)
    if audio_size != 80 + num_channels * channel_size:
        raise ThpError("audioSize %d != 80 + %d*%d = %d"
                       % (audio_size, num_channels, channel_size,
                          80 + num_channels * channel_size))
    tables = []
    for ch in range(num_channels):
        tables.append([s16be(data, audio_off + 8 + ch * 32 + k * 2)
                       for k in range(16)])
    header_prev = []
    for ch in range(num_channels):
        base = audio_off + 0x48 + ch * 4
        header_prev.append([s16be(data, base), s16be(data, base + 2)])
    if history is None:
        history = [list(p) for p in header_prev]
    out = []
    for ch in range(num_channels):
        prev1, prev2 = history[ch]
        table = tables[ch]
        src = data[audio_off + 80 + ch * channel_size:
                   audio_off + 80 + (ch + 1) * channel_size]
        samples = []
        n = 0
        for blk in range(0, len(src), 8):
            b0 = src[blk]
            index = (b0 >> 4) & 0x7
            exponent = b0 & 0xF
            f1 = table[2 * index]
            f2 = table[2 * index + 1]
            for k in range(14):
                byte = src[blk + 1 + k // 2]
                nib = (byte >> 4) & 0xF if k % 2 == 0 else byte & 0xF
                if nib >= 8:
                    nib -= 16
                sample = clamp_s16(((prev1 * f1 + prev2 * f2) >> 11)
                                   + (nib << exponent))
                samples.append(sample)
                prev2, prev1 = prev1, sample
                n += 1
                if n >= num_samples:
                    break
            if n >= num_samples:
                break
        if len(samples) != num_samples:
            raise ThpError("canal %d: se decodificaron %d muestras, se "
                           "esperaban %d" % (ch, len(samples), num_samples))
        history[ch] = [prev1, prev2]
        out.append(samples)
    info = {"channel_size": channel_size, "num_samples": num_samples,
            "tables": tables, "header_prev": header_prev}
    return out, info, history


def sha1_of(path):
    h = hashlib.sha1()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main(argv=None):
    ap = argparse.ArgumentParser(description="Extractor THP de GameCube "
                                 "(video JPEG + audio WAV).")
    ap.add_argument("input", help="archivo .thp de entrada")
    ap.add_argument("--out", default="video_extraido",
                    help="directorio de salida (defecto: video_extraido)")
    ap.add_argument("--inventory", default=None,
                    help="ruta del CSV de inventario (defecto: <out>/../video.csv "
                         "si se puede, si no <out>/video.csv)")
    ap.add_argument("--audio-history", choices=["header", "carried"],
                    default="header",
                    help="historia del decodificador ADPCM: 'header' (cada "
                         "frame usa su cabecera, defecto) o 'carried' (se "
                         "arrastra entre frames, como ffmpeg)")
    ap.add_argument("--no-audio", action="store_true",
                    help="no extraer el audio")
    ap.add_argument("--frame-prefix", default="frame_",
                    help="prefijo de los JPEG (defecto: frame_)")
    ap.add_argument("--audio-name", default="audio.wav",
                    help="nombre del WAV dentro de --out (defecto: audio.wav)")
    args = ap.parse_args(argv)

    with open(args.input, "rb") as f:
        data = f.read()
    header = ThpHeader(data)
    frames, errors = walk_frames(data, header)
    if errors:
        for e in errors:
            print("ADVERTENCIA: %s" % e, file=sys.stderr)

    os.makedirs(args.out, exist_ok=True)
    rows = []
    total_stuffed = 0
    total_trimmed = 0
    total_padding = 0
    total_audio_samples = 0
    pcm = bytearray()  # intercalado s16le, solo si hay audio y no --no-audio
    carried_history = None
    for fr in frames:
        raw_video = data[fr["video_off"]:fr["video_off"] + fr["image_size"]]
        jpeg, stuffed, trimmed = quasi_jpeg_to_jpeg(raw_video)
        name = "%s%04d.jpg" % (args.frame_prefix, fr["index"])
        path = os.path.join(args.out, name)
        with open(path, "wb") as f:
            f.write(jpeg)
        total_stuffed += stuffed
        total_trimmed += trimmed
        total_padding += fr["padding"]
        rows.append({
            "tipo": "frame", "indice": fr["index"], "archivo": name,
            "tamano": len(jpeg), "sha1": sha1_of(path),
            "resolucion_o_frecuencia": "%dx%d" % (header.width, header.height),
            "detalle": "stored=%d stuffed=%d trimmed=%d padding32=%d"
                       % (fr["image_size"], stuffed, trimmed, fr["padding"]),
        })
        if header.has_audio and not args.no_audio:
            hist = None if args.audio_history == "header" else carried_history
            samples, info, hist = decode_audio_frame(
                data, fr["audio_off"], fr["audio_size"],
                header.num_channels, hist)
            if args.audio_history == "carried":
                carried_history = hist
            total_audio_samples += info["num_samples"]
            if header.num_channels == 2:
                for a, b in zip(samples[0], samples[1]):
                    pcm += struct.pack("<hh", a, b)
            else:
                for a in samples[0]:
                    pcm += struct.pack("<h", a)

    wav_name = ""
    if header.has_audio and not args.no_audio:
        wav_name = args.audio_name
        wav_path = os.path.join(args.out, wav_name)
        with wave.open(wav_path, "wb") as w:
            w.setnchannels(header.num_channels)
            w.setsampwidth(2)
            w.setframerate(header.sample_rate)
            w.writeframes(bytes(pcm))
        rows.append({
            "tipo": "audio", "indice": "", "archivo": wav_name,
            "tamano": os.path.getsize(wav_path), "sha1": sha1_of(wav_path),
            "resolucion_o_frecuencia": "%d Hz, %d canales, %d muestras/canal"
                % (header.sample_rate, header.num_channels, total_audio_samples),
            "detalle": "ADPCM THP decodificado, historia=%s" % args.audio_history,
        })

    inv_path = args.inventory
    if inv_path is None:
        parent = os.path.dirname(os.path.abspath(args.out))
        inv_path = os.path.join(parent, "video.csv")
    inv_dir = os.path.dirname(os.path.abspath(inv_path))
    os.makedirs(inv_dir, exist_ok=True)
    with open(inv_path, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["tipo", "indice", "archivo", "tamano_bytes", "sha1",
                    "resolucion_o_frecuencia", "detalle"])
        for r in rows:
            w.writerow([r["tipo"], r["indice"], r["archivo"], r["tamano"],
                        r["sha1"], r["resolucion_o_frecuencia"], r["detalle"]])

    print("THP: %s" % args.input)
    print("  version: 0x%08x  fps: %s  frames: %d  %dx%d"
          % (header.version, header.fps, header.num_frames,
             header.width, header.height))
    if header.has_audio:
        print("  audio: %d canales, %d Hz, %d muestras/canal en cabecera, "
              "%d decodificadas"
              % (header.num_channels, header.sample_rate,
                 header.total_samples, total_audio_samples))
    print("  frames extraidos: %d JPEG en %s" % (len(frames), args.out))
    print("  bytes 0xFF rellenados (stuffing): %d; bytes tras EOI recortados: %d; "
          "relleno a 32 bytes: %d" % (total_stuffed, total_trimmed, total_padding))
    if wav_name:
        print("  audio: %s" % os.path.join(args.out, wav_name))
    print("  inventario: %s" % inv_path)
    if errors:
        print("  advertencias de cadena: %d (ver stderr)" % len(errors))
    return 0


if __name__ == "__main__":
    sys.exit(main())
