#pragma once

// Secuenciador host MusyX (Tramo 6, port — NO harness de test).
//
// Que es: el reloj y la agenda del secuenciador del juego, portados
// al codigo del port para que sndSeqPlayEx arranque musica real por
// el bridge/mixer existente. NO es el secuenciador completo del
// juego (seq.c): es el primer pase verificado de cada cancion,
// generado desde seq_host.py (Tramo 5) a musyx_notes.h. Cada nota
// ya viene resuelta nota -> macro -> muestra, con mac_key (pitch
// tras transposes de layer/keymap), mac_vol y midi.
//
// Calibracion (Tramo 5, medida en codigo, corrige BPMx51,2 de la
// Fase 18): ticks/s = BPM x 6,4 = (BPM/60) x 384. Cadena: callback
// AI a 32 kHz (160 frames/chunk -> 200 chunks/s) x 5 seqHandle
// por chunk x BPMx0,0064 ticks por llamada. Supuesto residual:
// AI a 32 kHz estereo (tasa de synthInit); si la AI corriera a
// otra tasa, el factor cambiaria en proporcion.
//
// Limites v1 (honestos, no defectos ocultos):
//   - Solo primer pase: sin bucles de cancion (loopPoint con flip
//     de timeIndex). Al consumir el ultimo evento, la cancion
//     termina (como la liberacion del slot de track 5 en el paso
//     huesped 27.215) y el bridge la da por terminada.
//   - Sin pitch-bend/modulacion (pb/mod constantes en 99/74;
//     en track 5 no se aplican: rango en semitonos sin
//     determinar, ver TRAMO5.md §7).
//   - Sin robo por prioridad del juego (64 voces): el bridge
//     tiene 16 voces de musica; los 3 temas verificados usan
//     como maximo 14 simultaneas, asi que no se roba en ellos.
//   - speed/trackMute/volumen de SynthPlayParams (puntero r6
//     del juego) NO se leen: el bridge no tiene acceso a la
//     RAM huesped. speed = 256 (1,0x) y sin mutes en v1; el
//     puntero queda registrado en el log de inicio para traza.
//   - CC7 se automatiza por bloque de mezcla (85 ms a 48 kHz),
//     no por muestra; CC10 (pan) se fija en el note-on.

#include <cstddef>
#include <cstdint>
#include <vector>

namespace sfa {

// Una nota del primer pase: tiempos en ticks de secuenciador.
struct MusyxNote {
  uint32_t time_ticks = 0;
  uint32_t length_ticks = 0;
  uint32_t sample_id = 0;  // Muestra MusyX (id de audio_id_map.h).
  int32_t pitch_base = 0;  // Pitch base de la muestra (audio.csv).
  int32_t mac_key = 0;     // Key que recibe macStart (fija el pitch).
  uint32_t mac_vol = 0;    // Volumen tras layers (0-127).
  uint32_t midi = 0;       // Canal MIDI (para CC7/CC10).
};

// Evento de controlador del patron en el primer pase.
struct MusyxCc {
  uint32_t time_ticks = 0;
  uint32_t midi = 0;
  uint32_t cc = 0;  // 7 (volumen) o 10 (pan) en v1.
  uint32_t value = 0;
};

struct MusyxSong {
  uint32_t track_id = 0;  // sid de sndSeqPlayEx (trigger->track).
  uint32_t group_id = 0;  // gid del proyecto (.pro) de la cancion.
  uint32_t bpm = 0;
  const MusyxNote* notes = nullptr;
  size_t note_count = 0;
  const MusyxCc* ccs = nullptr;
  size_t cc_count = 0;
};

// ticks/s = BPM x 6,4 (ver cabecera). BPM 60 -> 384; 120 -> 768.
inline double MusyxTicksPerSecond(uint32_t bpm) {
  return static_cast<double>(bpm) * 6.4;
}

class MusyxSequencer {
 public:
  struct Event {
    enum Kind { kNoteOn, kNoteOff, kCc } kind = kNoteOn;
    size_t note_index = 0;  // Valido en NoteOn/NoteOff.
    const MusyxNote* note = nullptr;
    const MusyxCc* cc = nullptr;
  };

  void Start(const MusyxSong* song, uint32_t speed = 256);
  void Stop();
  // Avanza el reloj dt segundos y vuelca los eventos vencidos
  // en orden: CC, NoteOff, NoteOn ante el mismo tick (el CC
  // debe estar vigente cuando suena la nota; el NoteOff
  // libera la voz antes de un NoteOn simultaneo).
  void Advance(double dt_seconds, std::vector<Event>* out);
  bool Active() const { return active_; }
  // Terminada: todos los eventos consumidos (notas y CC).
  bool Finished() const {
    return song_ != nullptr && next_note_ >= song_->note_count &&
           next_cc_ >= song_->cc_count;
  }
  const MusyxSong* Song() const { return song_; }
  double CurrentTick() const { return tick_; }
  double ElapsedSeconds() const { return elapsed_; }

 private:
  const MusyxSong* song_ = nullptr;
  uint32_t speed_ = 256;
  double tick_ = 0.0;
  double elapsed_ = 0.0;
  size_t next_note_ = 0;
  size_t next_cc_ = 0;
  // NoteOffs pendientes, ordenados por tick de fin.
  std::vector<std::pair<double, size_t>> pending_offs_;
  bool active_ = false;
};

}  // namespace sfa
