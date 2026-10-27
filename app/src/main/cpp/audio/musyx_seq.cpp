#include "audio/musyx_seq.h"

#include <algorithm>
#include <cmath>

namespace sfa {

void MusyxSequencer::Start(const MusyxSong* song, uint32_t speed) {
  song_ = song;
  speed_ = speed == 0 ? 256 : speed;
  tick_ = 0.0;
  elapsed_ = 0.0;
  next_note_ = 0;
  next_cc_ = 0;
  loops_ = 0;
  pending_offs_.clear();
  sec_runs_.clear();
  in_loop_phase_ = false;
  active_ = song_ != nullptr;
  // Snapshot CC de inicio de bucle (Tramo 8, solo bucle de segmento
  // unico 99/74): preset, luego el ultimo CC <= tiempo de la nota
  // de bucle por canal.
  for (int i = 0; i < 16; ++i) {
    loop_cc7_[i] = 127;
    loop_cc10_[i] = 64;
  }
  if (song_ != nullptr && song_->HasLoop()) {
    uint32_t loop_time = song_->notes[song_->loop_start_note].time_ticks;
    for (size_t i = 0; i < song_->cc_count; ++i) {
      const MusyxCc& cc = song_->ccs[i];
      if (cc.time_ticks > loop_time || cc.midi >= 16) continue;
      if (cc.cc == 7) loop_cc7_[cc.midi] = cc.value;
      if (cc.cc == 10) loop_cc10_[cc.midi] = cc.value;
    }
  }
}

void MusyxSequencer::Stop() {
  active_ = false;
  song_ = nullptr;
  pending_offs_.clear();
  sec_runs_.clear();
  in_loop_phase_ = false;
}

void MusyxSequencer::Advance(double dt_seconds, std::vector<Event>* out) {
  if (!active_ || song_ == nullptr || out == nullptr) return;
  if (dt_seconds < 0.0) dt_seconds = 0.0;
  elapsed_ += dt_seconds;
  double dt_ticks = dt_seconds * MusyxTicksPerSecond(song_->bpm) *
                    (static_cast<double>(speed_) / 256.0);
  tick_ += dt_ticks;
  if (!in_loop_phase_) {
    // ---- Primer pase (v1 / Tramo 8, intacto) ----
    // Eventos vencidos, agrupados por tick: CC, luego NoteOff,
    // luego NoteOn. Los NoteOff se generan al vencer el fin de
    // nota (time+length), no son eventos de la tabla.
    // Tramo 8 (bucle): si no queda evento vencido pero la
    // cancion tiene bucle y ya se consumieron todas las notas
    // y CC y no queda ningun NoteOff pendiente, se envuelve:
    // el reloj retrocede el periodo del bucle (tick_ queda
    // >= tiempo de la nota de bucle, porque el envoltorio
    // solo ocurre con tick_ >= fin del primer pase), los
    // indices vuelven al bucle y se emite kLoop antes de
    // los eventos de la siguiente iteracion. Sin bucle, o
    // con NoteOffs pendientes, se sale como en v1.
    while (true) {
      bool has_cc = next_cc_ < song_->cc_count &&
                    static_cast<double>(song_->ccs[next_cc_].time_ticks) <=
                        tick_;
      bool has_on = next_note_ < song_->note_count &&
                    static_cast<double>(song_->notes[next_note_].time_ticks) <=
                        tick_;
      bool has_off = !pending_offs_.empty() && pending_offs_.front().tick <= tick_;
      if (!has_cc && !has_on && !has_off) {
        if (song_->HasLoop() && next_note_ >= song_->note_count &&
            next_cc_ >= song_->cc_count && pending_offs_.empty()) {
          tick_ -= static_cast<double>(song_->loop_period_ticks);
          next_note_ = song_->loop_start_note;
          next_cc_ = song_->loop_cc_index;
          ++loops_;
          Event e;
          e.kind = Event::kLoop;
          out->push_back(e);
          continue;
        }
        break;
      }
      // Orden dentro del mismo instante: CC, NoteOff, NoteOn.
      if (has_cc) {
        Event e;
        e.kind = Event::kCc;
        e.cc = &song_->ccs[next_cc_++];
        out->push_back(e);
        continue;
      }
      if (has_off) {
        PendingOff off = pending_offs_.front();
        pending_offs_.erase(pending_offs_.begin());
        Event e;
        e.kind = Event::kNoteOff;
        e.note_index = off.note_index;
        e.note = &song_->notes[off.note_index];
        out->push_back(e);
        continue;
      }
      // NoteOn: programa su NoteOff.
      size_t idx = next_note_++;
      const MusyxNote& n = song_->notes[idx];
      double off_tick =
          static_cast<double>(n.time_ticks) + static_cast<double>(n.length_ticks);
      auto it = pending_offs_.begin();
      while (it != pending_offs_.end() && it->tick <= off_tick) ++it;
      PendingOff po;
      po.tick = off_tick;
      po.note_index = idx;
      po.section = -1;
      pending_offs_.insert(it, po);
      Event e;
      e.kind = Event::kNoteOn;
      e.note_index = idx;
      e.note = &n;
      out->push_back(e);
    }
    // Tramo 10: transicion a la fase de bucle por secciones cuando
    // el primer pase ha terminado (notas y CC consumidos, sin
    // NoteOffs pendientes) y hay al menos una seccion que buclea
    // con tablas de vuelta. Sin secciones que buclean, la cancion
    // termina como en v1 (Finished() pasa a true; el bridge la
    // detiene). La entrada se alinea en fase con el reloj huesped
    // (ver abajo); tras la transicion, esta misma llamada procesa
    // la fase de bucle (los eventos vencidos suenan con retraso
    // <= 1 bloque, la latencia documentada del primer pase).
    if (!song_->HasLoop() && next_note_ >= song_->note_count &&
        next_cc_ >= song_->cc_count && pending_offs_.empty() &&
        song_->HasSections()) {
      bool any_loop = false;
      for (size_t i = 0; i < song_->section_count; ++i) {
        if (song_->sections[i].loops) any_loop = true;
      }
      if (any_loop) {
        in_loop_phase_ = true;
        sec_runs_.clear();
        double entry = tick_;
        for (size_t i = 0; i < song_->section_count; ++i) {
          const MusyxSection& sec = song_->sections[i];
          if (!sec.loops || sec.loop_note_count == 0 ||
              sec.loop_note_indices == nullptr) {
            continue;
          }
          double period = static_cast<double>(sec.loop_end) -
                          static_cast<double>(sec.loop_point);
          if (period <= 0.0) continue;
          SecRun run;
          run.section_index = i;
          run.next = 0;
          run.next_cc = 0;
          run.loop_point = static_cast<double>(sec.loop_point);
          run.loop_end = static_cast<double>(sec.loop_end);
          // Entrada alineada en fase: si la seccion aun no buclea
          // en el huesped (loop_end >= entry), su vuelta empieza
          // en loop_end (espera en silencio); si ya buclea, su
          // vuelta actual empezo en loop_end + k*periodo (k =
          // vueltas completas antes de entry), de modo que las
          // vueltas siguientes caen exactamente sobre las del
          // huesped y el desfase no crece. Sin esta alineacion,
          // 95 quedaria desfasada hasta 79,75 s (sec2) o 71,75 s
          // (sec4) para siempre.
          if (static_cast<double>(sec.loop_end) >= entry) {
            run.lap_start = static_cast<double>(sec.loop_end);
            run.lap = 0;
          } else {
            double k = std::floor((entry - static_cast<double>(sec.loop_end)) /
                                  period);
            run.lap_start =
                static_cast<double>(sec.loop_end) + k * period;
            run.lap = static_cast<uint64_t>(k);
          }
          // Saltar eventos de la vuelta actual mas viejos que el
          // bloque actual (fire < entry - dt_ticks): pertenecen
          // a vueltas que el puente no toco y sonar ahora seria
          // un fantasma (p. ej. 95 sec0: su nota de la vuelta
          // empezo 7,5 s antes de entry). Los eventos del bloque
          // actual (fire >= entry - dt_ticks) los emite la fase
          // de bucle debajo, con retraso <= 1 bloque.
          double window_start = entry - dt_ticks;
          auto fire_of_note = [&](size_t flat_idx) {
            const MusyxNote& nn = song_->notes[flat_idx];
            return run.lap_start +
                   (static_cast<double>(nn.time_ticks) - run.loop_point);
          };
          auto fire_of_cc = [&](const MusyxCc& cc) {
            return run.lap_start +
                   (static_cast<double>(cc.time_ticks) - run.loop_point);
          };
          while (run.next < sec.loop_note_count &&
                 fire_of_note(sec.loop_note_indices[run.next]) < window_start) {
            ++run.next;
          }
          // CCs de alcance (catch-up): el estado vigente a mitad
          // de vuelta. Por cada (midi, cc) de la tabla de vuelta:
          // ultimo CC con fire <= entry (si no hay, ultimo de la
          // vuelta: valor heredado de la vuelta anterior). Tras
          // emitirlos, next_cc queda tras todos los CC con fire
          // <= entry (no se reemiten en la fase de bucle).
          if (sec.loop_ccs != nullptr) {
            for (size_t ci = 0; ci < sec.loop_cc_count; ++ci) {
              const MusyxCc& cc = sec.loop_ccs[ci];
              bool seen = false;
              for (size_t pj = 0; pj < ci; ++pj) {
                if (sec.loop_ccs[pj].midi == cc.midi &&
                    sec.loop_ccs[pj].cc == cc.cc) {
                  seen = true;
                  break;
                }
              }
              if (seen) continue;
              const MusyxCc* best = nullptr;
              const MusyxCc* last = nullptr;
              for (size_t cj = 0; cj < sec.loop_cc_count; ++cj) {
                const MusyxCc& cand = sec.loop_ccs[cj];
                if (cand.midi != cc.midi || cand.cc != cc.cc) continue;
                last = &cand;
                if (fire_of_cc(cand) <= entry) best = &cand;
              }
              if (best == nullptr) best = last;
              if (best != nullptr) {
                Event e;
                e.kind = Event::kCc;
                e.cc = best;
                out->push_back(e);
              }
            }
            while (run.next_cc < sec.loop_cc_count &&
                   fire_of_cc(sec.loop_ccs[run.next_cc]) <= entry) {
              ++run.next_cc;
            }
          }
          sec_runs_.push_back(run);
          Event e;
          e.kind = Event::kSectionLoop;
          e.section_id = sec.section_id;
          out->push_back(e);
        }
      }
    }
    if (!in_loop_phase_) return;
  }
  // ---- Fase de bucle por secciones (Tramo 10) ----
  // 1) NoteOffs vencidos (globales, en orden de tick; cruzan las
  //    fronteras de vuelta sin cortar la voz).
  while (!pending_offs_.empty() && pending_offs_.front().tick <= tick_) {
    PendingOff off = pending_offs_.front();
    pending_offs_.erase(pending_offs_.begin());
    Event e;
    e.kind = Event::kNoteOff;
    e.note_index = off.note_index;
    e.note = &song_->notes[off.note_index];
    out->push_back(e);
  }
  // 2) Por seccion (en orden de tabla): eventos vencidos de la
  //    vuelta actual hasta la frontera (si la llamada la cruza)
  //    o hasta tick_ (si no), luego el cruce, luego los eventos
  //    vencidos de la vuelta nueva. El orden importa: sin la
  //    primera emision, los eventos de la vuelta vieja vencidos
  //    en el bloque del cruce se perderian al resetear
  //    next/next_cc (caso real en 22: el CC 111 final de la
  //    rampa de sec11, fire 104424, en el bloque que cruza la
  //    frontera 104448; con el orden viejo el slot quedaba en
  //    110 para siempre en la vuelta 2).
  for (SecRun& run : sec_runs_) {
    const MusyxSection& sec = song_->sections[run.section_index];
    double period = run.loop_end - run.loop_point;
    if (period <= 0.0) continue;
    auto emit_due = [&](double limit) {
      // CCs vencidos (antes que las notas del mismo tick: el
      // pan CC10 debe estar vigente en el note-on).
      while (run.next_cc < sec.loop_cc_count) {
        const MusyxCc& cc = sec.loop_ccs[run.next_cc];
        double fire = run.lap_start +
                      (static_cast<double>(cc.time_ticks) - run.loop_point);
        if (fire > limit) break;
        ++run.next_cc;
        Event e;
        e.kind = Event::kCc;
        e.cc = &cc;
        out->push_back(e);
      }
      // Notas vencidas.
      while (run.next < sec.loop_note_count) {
        size_t flat_idx = sec.loop_note_indices[run.next];
        const MusyxNote& n = song_->notes[flat_idx];
        double fire = run.lap_start +
                      (static_cast<double>(n.time_ticks) - run.loop_point);
        if (fire > limit) break;
        double off_tick = fire + static_cast<double>(n.length_ticks);
        PendingOff po;
        po.tick = off_tick;
        po.note_index = flat_idx;
        po.section = static_cast<int>(run.section_index);
        auto it = pending_offs_.begin();
        while (it != pending_offs_.end() && it->tick <= off_tick) ++it;
        pending_offs_.insert(it, po);
        ++run.next;
        Event e;
        e.kind = Event::kNoteOn;
        e.note_index = flat_idx;
        e.note = &n;
        out->push_back(e);
      }
    };
    emit_due(std::min(tick_, run.lap_start + period));
    // Fronteras exactas: lap_start avanza por periodos exactos
    // (no por tick_, para no acumular el overshoot de bloque).
    while (tick_ >= run.lap_start + period) {
      run.lap_start += period;
      ++run.lap;
      run.next = 0;
      run.next_cc = 0;
      Event e;
      e.kind = Event::kSectionLoop;
      e.section_id = sec.section_id;
      out->push_back(e);
    }
    // Eventos vencidos de la vuelta nueva.
    emit_due(tick_);
  }
}

}  // namespace sfa
