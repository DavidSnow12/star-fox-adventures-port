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
//   - Bucles: desde el Tramo 8, 99 y 74 repiten su segmento
//     medido (notas 2..5 y 3..14) con snapshot CC; 5, 22 y 95
//     siguen en primer pase (al consumir el ultimo evento,
//     la cancion termina, como la liberacion del slot de
//     track 5 en el paso huesped 27.215).
//   - Sin pitch-bend/modulacion (pb/mod constantes en 99/74;
//     en track 5 no se aplican: rango en semitonos sin
//     determinar, ver TRAMO5.md §7).
//   - Sin robo por prioridad del juego (64 voces): el bridge
//     tiene 16 voces de musica; los 3 temas verificados usan
//     como maximo 14 simultaneas, asi que no se roba en ellos.
//   - speed/trackMute/volumen de SynthPlayParams: desde el
//     Tramo 8 el bridge SI los lee (SetGuestRam + OnSeqPlay)
//     y sndSeqVolume modela los fades; sin RAM huesped,
//     speed = 256 (1,0x) y sin mutes (defaults v1).
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

// Tramo 9 frente A - seccion de bucle por secciones (canciones 22/95).
// Una seccion = subconjunto de las notas planas (indices en la tabla
// plana, en orden de tabla == orden de tiempo) que pertenecen a una
// seccion huesped (seq_host.py). period_ticks (puente Tramo 9) =
// max(time+length) - min(time) de la seccion; loops = la seccion
// buclea en el huesped (loopCount > 0 tras 100.000 pasos).
// Tramo 10: la fase de bucle reproduce cada seccion que buclea con
// el reloj absoluto huesped (loop_point -> loop_end) y repite sus
// CC7/CC10 de vuelta (loop_ccs). Las secciones sin bucle no se
// repiten. El evento kSectionLoop marca cada vuelta nueva (y la
// entrada en fase); los CC de vuelta llegan como eventos kCc
// normales, antes que las notas del mismo tick.
struct MusyxSection {
  uint32_t section_id = 0;  // Id de seccion huesped (0..15).
  const size_t* note_indices = nullptr;  // Indices en la tabla plana.
  size_t note_count = 0;
  uint32_t period_ticks = 0;  // Tramo 9: span del primer pase
                              // (max fin - min inicio). Referencia;
                              // la fase de bucle Tramo 10 usa
                              // loop_end - loop_point.
  bool loops = false;
  // Tramo 10 — vuelta medida huesped (lap 1 == lap 2, == primer pase
  // filtrado a time >= loop_point; ver gen_section_loops.py).
  // loop_point = loopPoint del arreglo huesped (reloj de seccion al
  // buclear); loop_end = reloj huesped al que la seccion buclea
  // (old_high medido en la transicion, constante en todas las
  // vueltas medidas). La vuelta dura loop_end - loop_point ticks
  // exactos (22: 49152; 95 sec0/1: 6144, sec2: 30624, sec3: 29088,
  // sec4: 27552). loop_note_indices = notas de la vuelta (las de
  // intro < loop_point NO se repiten en el huesped); loop_ccs =
  // CC7/CC10 de la vuelta en tiempos absolutos huesped (dedup
  // consecutivos por (midi, cc)). Sin tablas de vuelta (nullptr),
  // la seccion no entra en fase de bucle.
  uint32_t loop_point = 0;
  uint32_t loop_end = 0;
  const size_t* loop_note_indices = nullptr;
  size_t loop_note_count = 0;
  const MusyxCc* loop_ccs = nullptr;
  size_t loop_cc_count = 0;
  uint32_t LoopPeriod() const {
    return loop_end > loop_point ? loop_end - loop_point : 0;
  }
};

struct MusyxSong {
  uint32_t track_id = 0;  // sid de sndSeqPlayEx (trigger->track).
  uint32_t group_id = 0;  // gid del proyecto (.pro) de la cancion.
  uint32_t bpm = 0;
  const MusyxNote* notes = nullptr;
  size_t note_count = 0;
  const MusyxCc* ccs = nullptr;
  size_t cc_count = 0;
  // Tramo 8 — bucle de cancion (primer pase + repeticion).
  // loop_start_note = indice de la primera nota del bucle
  // (SIZE_MAX = sin bucle: la cancion termina como en v1).
  // loop_cc_index = primer CC con tiempo >= tiempo de esa
  // nota (los CC del intro no se repiten; los de la ventana
  // del bucle si, con sus tiempos absolutos de tabla).
  // loop_period_ticks = fin del primer pase (maximo
  // time+length de las notas) menos tiempo de la nota de
  // bucle: al envolver, tick_ retrocede ese periodo, asi
  // que las notas del bucle vuelven a vencer en orden y
  // los NoteOffs pendientes (vacio en el momento del
  // envoltorio: se espera a que suenen) no se desplazan.
  // Medido Tramo 8 desde seq_host.py + tablas Tramo 6:
  // 99: notas 2..5, periodo 9212-1540=7672; 74: notas
  // 3..14, periodo 32252-3073=29179; 5/22/95: sin bucle
  // en este tramo (22 y 95 buclean por secciones, sin
  // segmento unico medido: quedan en primer pase).
  size_t loop_start_note = static_cast<size_t>(-1);
  size_t loop_cc_index = 0;
  uint32_t loop_period_ticks = 0;
  // Tramo 9: bucle por secciones (22/95). nullptr/0 = sin secciones
  // (comportamiento v1/Tramo 8 intacto).
  const MusyxSection* sections = nullptr;
  size_t section_count = 0;
  bool HasSections() const { return sections != nullptr && section_count > 0; }
  bool HasLoop() const {
    return loop_start_note < note_count && loop_period_ticks > 0;
  }
};

// ticks/s = BPM x 6,4 (ver cabecera). BPM 60 -> 384; 120 -> 768.
inline double MusyxTicksPerSecond(uint32_t bpm) {
  return static_cast<double>(bpm) * 6.4;
}

class MusyxSequencer {
 public:
  struct Event {
    enum Kind { kNoteOn, kNoteOff, kCc, kLoop, kSectionLoop } kind =
        kNoteOn;
    size_t note_index = 0;  // Valido en NoteOn/NoteOff.
    const MusyxNote* note = nullptr;
    const MusyxCc* cc = nullptr;
    // Valido en kSectionLoop: id de seccion huesped que empieza
    // una vuelta nueva en la fase de bucle por secciones.
    uint32_t section_id = 0;
  };

  void Start(const MusyxSong* song, uint32_t speed = 256);
  void Stop();
  // Avanza el reloj dt segundos y vuelca los eventos vencidos
  // en orden: CC, NoteOff, NoteOn ante el mismo tick (el CC
  // debe estar vigente cuando suena la nota; el NoteOff
  // libera la voz antes de un NoteOn simultaneo). Con bucle,
  // al consumir todos los eventos y vaciarse los NoteOffs
  // pendientes se emite un evento kLoop (el bridge debe
  // restaurar CC7/CC10 al snapshot de inicio de bucle, ver
  // LoopCc7/LoopCc10) y la iteracion siguiente arranca en
  // el mismo Advance: las notas del bucle vuelven a salir
  // en orden, sin hueco ni nota cortada.
  void Advance(double dt_seconds, std::vector<Event>* out);
  bool Active() const { return active_; }
  // Terminada: todos los eventos consumidos (notas y CC) y
  // ningun NoteOff pendiente. Con bucle (segmento unico o por
  // secciones con al menos una seccion que buclea) nunca es
  // terminal: solo Stop() (o un nuevo Start) termina la cancion.
  bool Finished() const {
    if (song_ == nullptr || song_->HasLoop()) return false;
    if (next_note_ < song_->note_count ||
        next_cc_ < song_->cc_count || !pending_offs_.empty())
      return false;
    if (song_->HasSections()) {
      for (size_t i = 0; i < song_->section_count; ++i) {
        if (song_->sections[i].loops) return false;
      }
    }
    return true;
  }
  // Fase de bucle por secciones activa (tras el primer pase).
  bool InLoopPhase() const { return in_loop_phase_; }
  // Vueltas completadas de la seccion i-esima de la tabla de
  // secciones de la cancion (0 si no esta en fase de bucle, no
  // buclea o no existe). sec_runs_ solo contiene secciones que
  // buclean, asi que se busca por indice de tabla.
  uint64_t SectionLaps(size_t section_index) const {
    for (const SecRun& r : sec_runs_) {
      if (r.section_index == section_index) return r.lap;
    }
    return 0;
  }
  // Vueltas de bucle completadas desde Start().
  uint64_t Loops() const { return loops_; }
  // Snapshot CC7/CC10 vigente en el tiempo de la nota de
  // bucle (ultimo CC <= ese tiempo por canal, o preset
  // 127/64 si no hay): el bridge lo restaura al ver kLoop.
  // Sin bucle, el preset.
  uint32_t LoopCc7(uint32_t midi) const {
    return midi < 16 ? loop_cc7_[midi] : 127;
  }
  uint32_t LoopCc10(uint32_t midi) const {
    return midi < 16 ? loop_cc10_[midi] : 64;
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
  uint64_t loops_ = 0;
  // Snapshot CC de inicio de bucle (ver LoopCc7/LoopCc10).
  uint32_t loop_cc7_[16] = {};
  uint32_t loop_cc10_[16] = {};
  // NoteOffs pendientes, ordenados por tick de fin. section = indice
  // en la tabla de secciones en fase de bucle, -1 en primer pase.
  struct PendingOff {
    double tick = 0.0;
    size_t note_index = 0;
    int section = -1;
  };
  std::vector<PendingOff> pending_offs_;
  // Fase de bucle por secciones (Tramo 10): un estado por seccion.
  // Reloj absoluto por seccion: la vuelta k empieza en lap_start
  // (tick_ exacto, multiplo de loop_end-loop_point desde loop_end,
  // sin deriva por overshoot de bloque) y los eventos con tiempo
  // huesped T vencen en lap_start + (T - loop_point). La vuelta
  // termina exactamente en lap_start + (loop_end - loop_point);
  // los NoteOffs cruzan la frontera sin cortar la voz (su tick de
  // fin es absoluto). A diferencia del Tramo 9, las secciones NO
  // se anclan a su primera nota (eso desplazaba sec0 de 22 unos
  // 21504 ticks frente a sec10) ni esperan al drenaje (eso alargaba
  // cada vuelta hasta el span de notas en vez de hasta loop_end).
  struct SecRun {
    size_t section_index = 0;
    size_t next = 0;       // Siguiente indice en loop_note_indices.
    size_t next_cc = 0;    // Siguiente indice en loop_ccs.
    uint64_t lap = 0;      // Vueltas completadas (0 = primera vuelta).
    double lap_start = 0.0;  // tick_ en el que empezo la vuelta actual.
    double loop_point = 0.0;  // loopPoint huesped de la seccion.
    double loop_end = 0.0;    // loop_end huesped de la seccion.
  };
  std::vector<SecRun> sec_runs_;
  bool in_loop_phase_ = false;
  bool active_ = false;
};

}  // namespace sfa
