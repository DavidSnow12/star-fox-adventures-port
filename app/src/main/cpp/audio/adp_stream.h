#pragma once

// Streaming ADP por bloques + resampleo 32 kHz -> 48 kHz por
// bloques (Tramo 5, Star Fox Android). Sustituye a la
// decodificacion de fichero entero de adp_decode.h (v1 Fase 18)
// en el camino de reproduccion: el primer bloque esta listo
// tras abrir, sin esperar a decodificar 12 MB (~3,2 s en VM
// para el mayor ADP del disco, gnr1423.adp).
//
// Decodificador: puerto directo del DTK de adp_decode.cpp
// (mismos coeficientes, misma saturacion en dos etapas,
// mismo estado arrastrado entre bloques, int64 obligatorio
// en el predictor: c*X llega a ~2,5e11 y desborda int32).
// Formato: bloques de 32 B [hdrL, hdrR, hdrL, hdrR, 28 B];
// 28 frames estereo por bloque; salida s16 32.000 Hz estereo.
// NO se reinicia el estado por bloque (eso sonaria a ruido).
//
// Resampleo: la misma matematica que Audio::ResampleToStereo
// (interpolacion lineal, pos = j * 32000 / 48000 en doble,
// i1 clamp al ultimo frame), pero incremental: el indice de
// salida j es global y monotono, asi que i0/frac coinciden
// exactamente con el camino de fichero entero. La posicion
// fraccionaria vive en el contador de salida, no se resetea
// por bloque: no hay chasquidos en las fronteras.
// Un lector nativo solo avanza hacia adelante (el ADP no
// puede rebobinar sin reabrir); el resampleador solo pide
// frames en orden creciente, asi que un bufer deslizante
// de un chunk basta.
//
// Sin asignaciones en el callback de audio: la decodificacion
// y la lectura ocurren en el hilo del juego (Tick), nunca en
// el callback AAudio (que solo drena el anillo, como hoy).
// Errores = silencio con log en el bridge, nunca crash:
// Open() false con tamano % 32 != 0, fichero ausente o
// lectura fallida; un fichero vacio (0 B) es valido
// degenerado (0 frames), igual que en la verificacion host.

#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

namespace sfa {

// Estado del predictor DTK (x2048) por canal.
struct DtkState {
  int32_t x1l = 0;
  int32_t x2l = 0;
  int32_t x1r = 0;
  int32_t x2r = 0;
};

// Decodifica UN bloque de 32 B a 28 frames estereo (56 s16).
// No toca el fichero: es la unidad que comparten el lector
// por bloques y cualquier verificacion host. Devuelve false
// solo si block == nullptr o out == nullptr.
bool DecodeDtkBlock(const uint8_t* block, DtkState* state,
                    int16_t* out_28_frames);

// Decodificador ADP por bloques sobre un .adp abierto.
// ReadNative() entrega hasta max_frames nativos (32 kHz
// estereo); 0 = EOF. El estado del predictor persiste
// entre llamadas. Sin estado global: dos streams no se
// contaminan (el juego solo tiene una voz de stream, pero
// el decodificador no depende de eso).
class AdpStreamDecoder {
 public:
  AdpStreamDecoder() = default;
  ~AdpStreamDecoder();
  AdpStreamDecoder(const AdpStreamDecoder&) = delete;
  AdpStreamDecoder& operator=(const AdpStreamDecoder&) = delete;

  // false si el fichero no existe, su tamano no es multiplo
  // de 32, o no se puede leer. Un fichero vacio abre bien
  // (0 frames totales).
  bool Open(const char* adp_path);
  void Close();
  bool IsOpen() const { return file_ != nullptr; }
  // Frames nativos totales (adp_bytes / 32 * 28).
  uint64_t TotalNativeFrames() const { return total_frames_; }
  uint64_t PositionNative() const { return position_; }
  bool AtEof() const { return position_ >= total_frames_; }
  size_t ReadNative(int16_t* out, size_t max_frames);

 private:
  std::FILE* file_ = nullptr;
  uint64_t total_frames_ = 0;
  uint64_t position_ = 0;  // Frames ya entregados.
  DtkState state_;
  // Bloque en curso: 28 frames decodificados, de los que
  // ya se entregaron block_pos_.
  int16_t block_pcm_[56];
  size_t block_len_ = 0;  // Frames validos en block_pcm_.
  size_t block_pos_ = 0;  // Frames ya entregados del bloque.
};

// Fuente nativa secuencial (32 kHz estereo) para el
// resampleador: solo avanza hacia adelante.
class NativeReader {
 public:
  virtual ~NativeReader() = default;
  virtual size_t ReadNative(int16_t* out, size_t max_frames) = 0;
  virtual uint64_t TotalNativeFrames() const = 0;
  virtual bool NativeEof() const = 0;
  // Cierre con semantica propia (p. ej. abortar la escritura
  // de cache en curso). Llamar una sola vez al detener la voz.
  virtual void CloseNative() = 0;
};

// Lector nativo sobre un .adp (sin cache: la cache la
// escribe AdpCachedReader, no este lector).
class AdpNativeReader : public NativeReader {
 public:
  bool Open(const char* adp_path) { return decoder_.Open(adp_path); }
  size_t ReadNative(int16_t* out, size_t max_frames) override {
    return decoder_.ReadNative(out, max_frames);
  }
  uint64_t TotalNativeFrames() const override {
    return decoder_.TotalNativeFrames();
  }
  bool NativeEof() const override { return decoder_.AtEof(); }
  void CloseNative() override { decoder_.Close(); }

 private:
  AdpStreamDecoder decoder_;
};

// Lector nativo sobre un .pcm de cache (s16le, 32 kHz
// estereo, sin cabecera). El tamano debe ser multiplo de 4;
// un .pcm truncado a la mitad de un frame se trata como
// error de apertura (la validez de la cache ya se comprobo
// antes; esto es doble red, no el criterio principal).
class PcmNativeReader : public NativeReader {
 public:
  PcmNativeReader() = default;
  ~PcmNativeReader() override;
  PcmNativeReader(const PcmNativeReader&) = delete;
  PcmNativeReader& operator=(const PcmNativeReader&) = delete;

  bool Open(const char* pcm_path);
  size_t ReadNative(int16_t* out, size_t max_frames) override;
  uint64_t TotalNativeFrames() const override {
    return total_frames_;
  }
  bool NativeEof() const override { return position_ >= total_frames_; }
  void CloseNative() override { Close(); }

 private:
  void Close();
  std::FILE* file_ = nullptr;
  uint64_t total_frames_ = 0;
  uint64_t position_ = 0;
};

// Fuente de stream a 48 kHz estereo para la voz de stream
// del bridge: tira de un NativeReader y resamplea por
// bloques con la matematica de ResampleToStereo.
class StreamSource {
 public:
  virtual ~StreamSource() = default;
  // Hasta max_frames a 48 kHz; 0 = EOF. Puede devolver
  // menos que lo pedido en el ultimo bloque (EOF parcial).
  virtual size_t Read48k(int16_t* out, size_t max_frames) = 0;
  // Total a 48 kHz, con la misma formula truncante que
  // ResampleToStereo: native * 48000 / 32000.
  virtual uint64_t TotalFrames48() const = 0;
  virtual uint64_t Position48() const = 0;
  virtual bool AtEof() const = 0;
  virtual void Close() = 0;
};

// Resampleador incremental sobre un NativeReader propio.
// El bufer de chunk (4096 frames nativos) solo avanza:
// GetFrame(i0) e GetFrame(i0+1) con i0 monotono.
class ResamplingSource : public StreamSource {
 public:
  explicit ResamplingSource(std::unique_ptr<NativeReader> reader)
      : reader_(std::move(reader)) {}
  ~ResamplingSource() override { Close(); }
  ResamplingSource(const ResamplingSource&) = delete;
  ResamplingSource& operator=(const ResamplingSource&) = delete;

  size_t Read48k(int16_t* out, size_t max_frames) override;
  uint64_t TotalFrames48() const override;
  uint64_t Position48() const override { return out_index_; }
  bool AtEof() const override {
    return eof_ || out_index_ >= TotalFrames48();
  }
  void Close() override {
    if (reader_ != nullptr) {
      reader_->CloseNative();
      reader_.reset();
    }
  }

 private:
  // Frame nativo idx (estereo) o false si no se puede leer
  // (EOF prematuro / truncado: el llamador corta el stream).
  bool GetFrame(uint64_t idx, int16_t* frame_out);
  std::unique_ptr<NativeReader> reader_;
  uint64_t out_index_ = 0;  // Frames a 48 kHz ya emitidos.
  bool eof_ = false;
  // Chunk deslizante: frames [chunk_base_, chunk_base_ +
  // chunk_len_), leidos en orden desde el NativeReader.
  static constexpr size_t kChunkFrames = 4096;
  std::vector<int16_t> chunk_;
  uint64_t chunk_base_ = 0;
  size_t chunk_len_ = 0;
  uint64_t next_native_ = 0;  // Frames nativos ya leidos del reader.
};

}  // namespace sfa
