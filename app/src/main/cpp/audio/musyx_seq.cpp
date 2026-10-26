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
  pending_offs_.clear();
  active_ = song_ != nullptr;
}

void MusyxSequencer::Stop() {
  active_ = false;
  song_ = nullptr;
  pending_offs_.clear();
}

void MusyxSequencer::Advance(double dt_seconds, std::vector<Event>* out) {
  if (!active_ || song_ == nullptr || out == nullptr) return;
  if (dt_seconds < 0.0) dt_seconds = 0.0;
  elapsed_ += dt_seconds;
  tick_ += dt_seconds * MusyxTicksPerSecond(song_->bpm) *
           (static_cast<double>(speed_) / 256.0);
  // Eventos vencidos, agrupados por tick: CC, luego NoteOff,
  // luego NoteOn. Los NoteOff se generan al vencer el fin de
  // nota (time+length), no son eventos de la tabla.
  while (true) {
    bool has_cc = next_cc_ < song_->cc_count &&
                  static_cast<double>(song_->ccs[next_cc_].time_ticks) <=
                      tick_;
    bool has_on = next_note_ < song_->note_count &&
                  static_cast<double>(song_->notes[next_note_].time_ticks) <=
                      tick_;
    bool has_off = !pending_offs_.empty() && pending_offs_.front().first <= tick_;
    if (!has_cc && !has_on && !has_off) break;
    // Orden dentro del mismo instante: CC, NoteOff, NoteOn.
    if (has_cc) {
      Event e;
      e.kind = Event::kCc;
      e.cc = &song_->ccs[next_cc_++];
      out->push_back(e);
      continue;
    }
    if (has_off) {
      size_t idx = pending_offs_.front().second;
      pending_offs_.erase(pending_offs_.begin());
      Event e;
      e.kind = Event::kNoteOff;
      e.note_index = idx;
      e.note = &song_->notes[idx];
      out->push_back(e);
      continue;
    }
    // NoteOn: programa su NoteOff.
    size_t idx = next_note_++;
    const MusyxNote& n = song_->notes[idx];
    double off_tick =
        static_cast<double>(n.time_ticks) + static_cast<double>(n.length_ticks);
    auto it = pending_offs_.begin();
    while (it != pending_offs_.end() && it->first <= off_tick) ++it;
    pending_offs_.insert(it, std::make_pair(off_tick, idx));
    Event e;
    e.kind = Event::kNoteOn;
    e.note_index = idx;
    e.note = &n;
    out->push_back(e);
  }
}

}  // namespace sfa
