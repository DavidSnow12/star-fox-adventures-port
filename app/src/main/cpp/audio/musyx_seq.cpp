#include "audio/musyx_seq.h"

#include <algorithm>

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
  // Snapshot CC de inicio de bucle (Tramo 8): preset, luego
  // el ultimo CC <= tiempo de la nota de bucle por canal.
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
  tick_ += dt_seconds * MusyxTicksPerSecond(song_->bpm) *
           (static_cast<double>(speed_) / 256.0);
  if (in_loop_phase_) {
    // ---- Fase de bucle por secciones (Tramo 9) ----
    // 1) NoteOffs vencidos (todas las secciones, en orden de tick):
    //    decrementan el pendiente de su seccion.
    while (!pending_offs_.empty() && pending_offs_.front().tick <= tick_) {
      PendingOff off = pending_offs_.front();
      pending_offs_.erase(pending_offs_.begin());
      if (off.section >= 0 &&
          static_cast<size_t>(off.section) < sec_runs_.size() &&
          sec_runs_[static_cast<size_t>(off.section)].pending > 0) {
        sec_runs_[static_cast<size_t>(off.section)].pending--;
      }
      Event e;
      e.kind = Event::kNoteOff;
      e.note_index = off.note_index;
      e.note = &song_->notes[off.note_index];
      out->push_back(e);
    }
    // 2) Por seccion (en orden de tabla): avanzar vueltas y notas.
    for (SecRun& run : sec_runs_) {
      const MusyxSection& sec = song_->sections[run.section_index];
      if (!sec.loops) continue;
      while (true) {
        if (run.next >= sec.note_count) {
          if (run.pending > 0) break;  // Espera al drenaje.
          ++run.lap;
          run.next = 0;
          run.lap_start = tick_;
          Event e;
          e.kind = Event::kSectionLoop;
          e.section_id = sec.section_id;
          out->push_back(e);
          continue;
        }
        size_t flat_idx = sec.note_indices[run.next];
        const MusyxNote& n = song_->notes[flat_idx];
        double fire = run.lap_start +
                      (static_cast<double>(n.time_ticks) - run.first_time);
        if (fire > tick_) break;
        double off_tick = fire + static_cast<double>(n.length_ticks);
        PendingOff po;
        po.tick = off_tick;
        po.note_index = flat_idx;
        po.section = static_cast<int>(run.section_index);
        auto it = pending_offs_.begin();
        while (it != pending_offs_.end() && it->tick <= off_tick) ++it;
        pending_offs_.insert(it, po);
        ++run.pending;
        ++run.next;
        Event e;
        e.kind = Event::kNoteOn;
        e.note_index = flat_idx;
        e.note = &n;
        out->push_back(e);
      }
    }
    return;
  }
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
  // Tramo 9: transicion a la fase de bucle por secciones cuando el
  // primer pase ha terminado (notas y CC consumidos, sin NoteOffs
  // pendientes) y hay al menos una seccion que buclea. Sin
  // secciones que buclean, la cancion termina como en v1
  // (Finished() pasa a true; el bridge la detiene).
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
      for (size_t i = 0; i < song_->section_count; ++i) {
        const MusyxSection& sec = song_->sections[i];
        if (!sec.loops || sec.note_count == 0) continue;
        SecRun run;
        run.section_index = i;
        run.next = 0;
        run.lap = 0;
        run.lap_start = tick_;
        run.first_time =
            static_cast<double>(song_->notes[sec.note_indices[0]].time_ticks);
        run.pending = 0;
        sec_runs_.push_back(run);
        Event e;
        e.kind = Event::kSectionLoop;
        e.section_id = sec.section_id;
        out->push_back(e);
      }
    }
  }
}

}  // namespace sfa
