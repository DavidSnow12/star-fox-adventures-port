#include "audio/audio_bridge.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <memory>

#include "audio/audio_id_map.h"
#include "audio/fx_table.h"
#include "audio/musyx_notes.h"
#include "log.h"

namespace sfa {

namespace {

// Direcciones guest verificadas en codigo/symbols.map.
constexpr uint32_t kAudioStreamPlay = 0x8000D220u;
constexpr uint32_t kAudioStreamStopCurrent = 0x8000D03Cu;
// Tramo 9 (patch-A, observacion): AudioStream_StartPrepared y
// AudioStream_GetCurrentId. El chassis debe anadir GetCurrentId
// a la lista de hook (diff de chassis.cpp, 1 linea); StartPrepared
// ya estaba en la lista pero solo se contaba.
constexpr uint32_t kAudioStreamStartPrepared = 0x8000D158u;
constexpr uint32_t kAudioStreamGetCurrentId = 0x8000CFB8u;
// currentId huesped (GetCurrentId: lwz r3, -26904(r13); r13 =
// 0x803E4B40 en el arranque real; StartPrepared escribe ahi el
// prepared B). Solo para observacion en OnGetCurrentId; verificar
// en integracion si r13 base cambiara (no cambia el sonido).
constexpr uint32_t kGuestCurrentIdAddr = 0x803DE228u;
constexpr uint32_t kSndFxStartEx = 0x80273218u;
constexpr uint32_t kSndSeqPlayEx = 0x8027C34Cu;
constexpr uint32_t kSndSeqStop = 0x80272F80u;
// Tramo 8: sndSeqVolume (ver audio_bridge.h).
constexpr uint32_t kSndSeqVolume = 0x80273090u;

int16_t ClampS16(int32_t v) {
  if (v > 32767) return 32767;
  if (v < -32768) return -32768;
  return static_cast<int16_t>(v);
}

bool FileExists(const char* path) {
  std::FILE* f = std::fopen(path, "rb");
  if (f == nullptr) return false;
  std::fclose(f);
  return true;
}

// Lector nativo ADP con escritura de cache en streaming:
// decodifica por bloques para reproducir y escribe ese
// mismo PCM en <rel>.pcm.tmp; al llegar a EOF promueve
// la cache (meta + rename + poda LRU). Si se cierra
// antes de EOF (stop o nuevo Play), el .tmp se aborta:
// la cache parcial NO se promueve (limitacion v1).
class AdpCachedReader : public NativeReader {
 public:
  bool Open(const char* adp_path, const std::string& cache_root,
            const std::string& adp_rel, uint64_t cap_bytes) {
    if (!decoder_.Open(adp_path)) return false;
    cache_root_ = cache_root;
    adp_rel_ = adp_rel;
    adp_path_ = adp_path;
    cap_bytes_ = cap_bytes;
    uint64_t total = decoder_.TotalNativeFrames();
    uint64_t adp_bytes = total / 28 * 32;
    // Best effort: si la cache no se puede abrir, el
    // sonido sigue sin cache (no es error de reproduccion).
    if (writer_.Open(cache_root, adp_rel, adp_bytes, total)) {
      writer_open_ = true;
    }
    return true;
  }

  size_t ReadNative(int16_t* out, size_t max_frames) override {
    size_t got = decoder_.ReadNative(out, max_frames);
    if (got > 0 && writer_open_) {
      if (!writer_.Write(out, got)) writer_open_ = false;
    }
    if (decoder_.AtEof() && !finalized_) {
      finalized_ = true;
      if (writer_open_) {
        if (writer_.Finalize(adp_path_, cap_bytes_)) {
          SFA_LOGI("bridge: cache ADP promovida '%s'",
                   adp_rel_.c_str());
        } else {
          SFA_LOGI("bridge: cache ADP no promovida '%s' "
                   "(seguir sonando sin cache)",
                   adp_rel_.c_str());
        }
        writer_open_ = false;
      }
    }
    return got;
  }

  uint64_t TotalNativeFrames() const override {
    return decoder_.TotalNativeFrames();
  }
  bool NativeEof() const override { return decoder_.AtEof(); }
  void CloseNative() override {
    if (!finalized_ && writer_open_) writer_.Abort();
    writer_open_ = false;
    decoder_.Close();
  }

 private:
  AdpStreamDecoder decoder_;
  CacheWriter writer_;
  bool writer_open_ = false;
  bool finalized_ = false;
  std::string cache_root_;
  std::string adp_rel_;
  std::string adp_path_;
  uint64_t cap_bytes_ = kAdpCacheCapBytes;
};

}  // namespace

AudioBridge::AudioBridge() {
  // Preset huesped (Tramo 5, seq_host.py): CC7=127, CC10=64,
  // CC19=0 (FULL_PRESET[19]).
  for (SongSlot& slot : song_slots_) {
    slot.cc7.fill(127);
    slot.cc10.fill(64);
    slot.cc19.fill(0);
  }
}

// ---- Tramo 9: slots de cancion ----
AudioBridge::SongSlot* AudioBridge::FindSlot(uint32_t handle) {
  for (SongSlot& slot : song_slots_) {
    if (slot.active && slot.handle == handle) return &slot;
  }
  return nullptr;
}
const AudioBridge::SongSlot* AudioBridge::FindSlot(uint32_t handle) const {
  for (const SongSlot& slot : song_slots_) {
    if (slot.active && slot.handle == handle) return &slot;
  }
  return nullptr;
}
AudioBridge::SongSlot* AudioBridge::FirstActiveSlot() {
  SongSlot* best = nullptr;
  for (SongSlot& slot : song_slots_) {
    if (slot.active && (best == nullptr || slot.handle < best->handle))
      best = &slot;
  }
  return best;
}
const AudioBridge::SongSlot* AudioBridge::FirstActiveSlot() const {
  const SongSlot* best = nullptr;
  for (const SongSlot& slot : song_slots_) {
    if (slot.active && (best == nullptr || slot.handle < best->handle))
      best = &slot;
  }
  return best;
}
bool AudioBridge::AnySongActive() const {
  for (const SongSlot& slot : song_slots_) {
    if (slot.active) return true;
  }
  return false;
}
bool AudioBridge::SeqActive() const { return AnySongActive(); }
int AudioBridge::CurrentSeqTrack() const {
  const SongSlot* slot = FirstActiveSlot();
  return slot != nullptr && slot->seq.Song() != nullptr
             ? static_cast<int>(slot->seq.Song()->track_id)
             : -1;
}
std::vector<int> AudioBridge::ActiveSeqTracks() const {
  std::vector<int> out;
  for (const SongSlot& slot : song_slots_) {
    if (slot.active && slot.seq.Song() != nullptr)
      out.push_back(static_cast<int>(slot.seq.Song()->track_id));
  }
  return out;
}
size_t AudioBridge::ActiveSongCount() const {
  size_t n = 0;
  for (const SongSlot& slot : song_slots_) {
    if (slot.active) ++n;
  }
  return n;
}
uint32_t AudioBridge::SeqHandleForTrack(uint32_t track) const {
  for (const SongSlot& slot : song_slots_) {
    if (slot.active && slot.track_id == track) return slot.handle;
  }
  return 0;
}
float AudioBridge::SeqVolume() const {
  const SongSlot* slot = FirstActiveSlot();
  return slot != nullptr ? slot->vol_current : 1.0f;
}
float AudioBridge::SeqVolumeTarget() const {
  const SongSlot* slot = FirstActiveSlot();
  return slot != nullptr ? slot->vol_to : 1.0f;
}
float AudioBridge::SeqVolumeOf(uint32_t handle) const {
  const SongSlot* slot = FindSlot(handle);
  return slot != nullptr ? slot->vol_current : 1.0f;
}
uint32_t AudioBridge::SeqCc7Of(uint32_t handle, uint32_t midi) const {
  const SongSlot* slot = FindSlot(handle);
  if (slot == nullptr || midi >= 16) return 127;
  return slot->cc7[midi];
}
uint32_t AudioBridge::SeqCc10Of(uint32_t handle, uint32_t midi) const {
  const SongSlot* slot = FindSlot(handle);
  if (slot == nullptr || midi >= 16) return 64;
  return slot->cc10[midi];
}
uint32_t AudioBridge::SeqCc19Of(uint32_t handle, uint32_t midi) const {
  const SongSlot* slot = FindSlot(handle);
  if (slot == nullptr || midi >= 16) return 0;
  return slot->cc19[midi];
}
bool AudioBridge::SlotMusicActive(const SongSlot* slot) const {
  if (slot == nullptr) return false;
  size_t idx = static_cast<size_t>(slot - song_slots_.data());
  for (const MusicVoice& v : music_voices_) {
    if (v.active && v.slot == idx) return true;
  }
  return false;
}
void AudioBridge::StopSlotMusic(SongSlot* slot) {
  if (slot == nullptr) return;
  size_t idx = static_cast<size_t>(slot - song_slots_.data());
  for (MusicVoice& v : music_voices_) {
    if (v.active && v.slot == idx) {
      v.active = false;
      v.pcm.clear();
      v.pos = 0;
    }
  }
}
void AudioBridge::StopSlot(SongSlot* slot) {
  if (slot == nullptr) return;
  StopSlotMusic(slot);
  slot->seq.Stop();
  slot->mute_active = false;
  slot->vol_current = 1.0f;
  slot->vol_from = 1.0f;
  slot->vol_to = 1.0f;
  slot->vol_t = 0.0;
  slot->vol_dur = 0.0;
  slot->active = false;
  SFA_LOGI("bridge: sndSeqStop (slot handle %u detenido)", slot->handle);
}
void AudioBridge::FinishSlots() {
  for (SongSlot& slot : song_slots_) {
    if (slot.active && slot.seq.Finished() && !SlotMusicActive(&slot)) {
      uint32_t h = slot.handle;
      StopSlot(&slot);
      SFA_LOGI("bridge: MusyX cancion terminada (handle %u, slot "
               "liberado)", h);
    }
  }
}

// ---- Musica MusyX (Tramo 6) ----

int AudioBridge::OnSeqPlay(uint32_t group_id, uint32_t seq_id,
                           uint32_t params_ptr) {
  if (audio_ == nullptr) return 0;
  const MusyxSong* song = nullptr;
  for (const MusyxSong& s : kMusyxSongs) {
    if (s.track_id == seq_id) {
      song = &s;
      break;
    }
  }
  if (song == nullptr) {
    Unresolved u;
    u.id = seq_id;
    u.kind = "musyx_cancion";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: sndSeqPlayEx grupo %u cancion %u sin tabla "
             "verificada (no se inventa sonido)",
             group_id, seq_id);
    return 0;
  }
  // Tramo 8 - params reales (SynthPlayParams, layout medido en RAM
  // huesped en el Tramo 7, big-endian): +0 flags u32, +4 mute[2]
  // u32, +12 speed u16, +14 vol.time u16, +16 vol.target u8,
  // +17 numVolDefs u8, +20 volDefs ptr, +24 numFaded u8, +28
  // faded ptr. flags: bit 0 = mutes, bit 1 = speed, bit 2 =
  // volumen, bit 3 = seqVolumeDefinitions (0 en la llamada
  // medida). Sin RAM huesped (o params fuera de rango):
  // defaults v1 (speed 256, sin mutes, volumen 1,0).
  // El volumen de params es el punto de partida del fade, NO
  // una ganancia estatica (la llamada real trae target 0 y
  // luego sndSeqVolume sube; una ganancia estatica 0 la
  // silenciaria).
  uint32_t speed = 256;
  uint32_t params_flags = 0;
  uint32_t mute0 = 0xFFFFFFFFu, mute1 = 0xFFFFFFFFu;
  bool mute_active = false;
  float vol_init = 1.0f;
  bool params_read = false;
  if (guest_ram_ != nullptr && params_ptr >= 0x80000000u) {
    uint32_t off = params_ptr - 0x80000000u;
    if (off + 32 <= guest_ram_size_) {
      const uint8_t* q = guest_ram_ + off;
      auto rd32 = [&](int o) -> uint32_t {
        return (static_cast<uint32_t>(q[o]) << 24) |
               (static_cast<uint32_t>(q[o + 1]) << 16) |
               (static_cast<uint32_t>(q[o + 2]) << 8) |
               static_cast<uint32_t>(q[o + 3]);
      };
      auto rd16 = [&](int o) -> uint32_t {
        return (static_cast<uint32_t>(q[o]) << 8) |
               static_cast<uint32_t>(q[o + 1]);
      };
      params_flags = rd32(0);
      mute0 = rd32(4);
      mute1 = rd32(8);
      uint32_t p_speed = rd16(12);
      uint32_t p_vol_target = q[16];
      mute_active = (params_flags & 1u) != 0;
      if ((params_flags & 2u) != 0 && p_speed != 0) speed = p_speed;
      if ((params_flags & 4u) != 0) {
        vol_init = static_cast<float>(p_vol_target > 127 ? 127
                                                         : p_vol_target) /
                   127.0f;
      }
      params_read = true;
    }
  }
  // Tramo 9 - varias canciones a la vez (limite v1 roto): si el
  // track ya suena, se reinicia SU slot; si no, se usa el primer
  // slot libre. Las demas canciones NO se tocan (antes,
  // StopAllMusic() + seq_.Stop() las cortaban: en G3, al
  // arrancar 95 la 22 se cortaba). Sin slot libre: no se
  // arranca y se cuenta (no se roba una cancion en curso).
  SongSlot* slot = nullptr;
  for (SongSlot& sl : song_slots_) {
    if (sl.active && sl.track_id == seq_id) {
      slot = &sl;
      break;
    }
  }
  if (slot == nullptr) {
    for (SongSlot& sl : song_slots_) {
      if (!sl.active) {
        slot = &sl;
        break;
      }
    }
  }
  if (slot == nullptr) {
    ++seq_slots_full_;
    SFA_LOGI("bridge: sndSeqPlayEx grupo %u cancion %u sin slot "
             "libre (4 canciones en curso, no se roba)",
             group_id, seq_id);
    return 0;
  }
  bool restarting = slot->active;
  if (restarting) StopSlot(slot);
  slot->handle = next_seq_handle_++;
  slot->group_id = group_id;
  slot->track_id = seq_id;
  slot->speed = speed;
  slot->mute[0] = mute0;
  slot->mute[1] = mute1;
  slot->mute_active = mute_active;
  slot->vol_current = vol_init;
  slot->vol_from = vol_init;
  slot->vol_to = vol_init;
  slot->vol_t = 0.0;
  slot->vol_dur = 0.0;
  slot->cc7.fill(127);
  slot->cc10.fill(64);
  slot->cc19.fill(0);
  slot->active = true;
  slot->seq.Start(song, speed);
  SeqStarted rec;
  rec.group_id = group_id;
  rec.seq_id = seq_id;
  rec.bpm = song->bpm;
  rec.notes = song->note_count;
  rec.params_ptr = params_ptr;
  rec.speed = speed;
  rec.params_flags = params_flags;
  rec.handle = slot->handle;
  seq_started_.push_back(rec);
  SFA_LOGI("bridge: sndSeqPlayEx grupo %u cancion %u -> tabla "
           "verificada (gid %u, BPM %u, %zu notas, %.1f ticks/s, "
           "params huesped 0x%08X %s: flags %u speed %u mutes %s "
           "vol %.3f, handle %u%s)",
           group_id, seq_id, song->group_id, song->bpm,
           song->note_count, MusyxTicksPerSecond(song->bpm),
           params_ptr, params_read ? "leidos" : "sin leer",
           params_flags, speed, mute_active ? "activos" : "no",
           vol_init, slot->handle, restarting ? ", reinicio" : "");
  if (song->group_id != group_id) {
    SFA_LOGI("bridge: aviso MusyX: group_id %u != gid de tabla %u "
             "(equivalencia sgid<->gid sin verificar; se arranca "
             "por seq_id)",
             group_id, song->group_id);
  }
  return 1;
}

void AudioBridge::OnSeqStop() {
  for (SongSlot& slot : song_slots_) {
    if (slot.active) StopSlot(&slot);
  }
  SFA_LOGI("bridge: sndSeqStop (todas las canciones detenidas)");
}

int AudioBridge::OnSeqStopHandle(uint32_t handle) {
  // Tramo 10: r3 = seqHandle, verificado en el codigo huesped
  // (sndSeqStop -> seqStop 0x8026DBE8: busca nodo+12 == r3 &
  // 0x7FFFFFFF en dos listas; sndSeqVolume -> seqVolume 0x8026E054
  // usa EXACTAMENTE la misma busqueda con su r5; los 3 llamadores
  // del juego pasan chan+4, el valor que Music_ChannelLoadedCallback
  // guarda del retorno de sndSeqPlayEx y que pasa como r5 a
  // sndSeqVolume; en G3, fades con handle 1 = 22 y 2 = 95).
  // El bit 31 de r3 es un flag huesped, no parte del handle:
  // seqStop con bit 31 solo limpia un flag (no detiene, no
  // desengancha la secuencia) y con -1 (sin coincidencia) sale
  // sin tocar nada. Esos valores nunca detienen ni usan el
  // fallback de una sola cancion (un chan+4 borrado vale -1, no
  // un handle valido; ver SeqStopFlagged()).
  if ((handle & 0x80000000u) != 0) {
    ++seq_stop_flagged_;
    SFA_LOGI("bridge: sndSeqStop handle 0x%08X con bit 31 (flag "
             "huesped, no stop): se cuenta, no se detiene nada",
             handle);
    return 0;
  }
  SongSlot* slot = FindSlot(handle);
  if (slot != nullptr) {
    StopSlot(slot);
    return 1;
  }
  // Fallback: una unica cancion activa se detiene aunque el
  // handle no coincida (cubre handle 0 y llamadas "para la
  // cancion en curso"); sin cancion, nada que hacer.
  size_t active = ActiveSongCount();
  if (active == 1) {
    SongSlot* only = FirstActiveSlot();
    SFA_LOGI("bridge: sndSeqStop handle %u sin coincidencia, "
             "unica cancion activa (handle %u): se detiene",
             handle, only->handle);
    StopSlot(only);
    return 1;
  }
  if (active == 0) return 0;
  ++seq_stop_unmatched_;
  SFA_LOGI("bridge: sndSeqStop handle %u sin coincidencia con "
           "%zu canciones activas: no se detiene ninguna",
           handle, active);
  return 0;
}

// Tramo 8 - fade de musica (sndSeqVolume, ver .h); Tramo 9: el
// fade se aplica AL SLOT DEL HANDLE (en G3: 60/500 ms a
// handle 1 = cancion 22, 100/500 ms a handle 2 = cancion 95;
// antes, con una sola cancion, cualquier fade era "la"
// cancion). Sin coincidencia y una unica cancion activa,
// se aplica a esa (mismo fallback que OnSeqStopHandle).
bool AudioBridge::OnSeqVolume(uint32_t volume, uint32_t time_ms,
                              uint32_t seq_handle) {
  SongSlot* slot = FindSlot(seq_handle);
  if (slot == nullptr && ActiveSongCount() == 1) {
    slot = FirstActiveSlot();
    SFA_LOGI("bridge: sndSeqVolume handle %u sin coincidencia, "
             "unica cancion activa (handle %u): se aplica",
             seq_handle, slot->handle);
  }
  if (slot == nullptr) {
    SFA_LOGI("bridge: sndSeqVolume vol %u tiempo %u handle %u "
             "sin cancion correspondiente (ignorado)",
             volume, time_ms, seq_handle);
    return false;
  }
  float target =
      static_cast<float>(volume > 127 ? 127 : volume) / 127.0f;
  slot->vol_from = slot->vol_current;
  slot->vol_to = target;
  slot->vol_t = 0.0;
  slot->vol_dur = static_cast<double>(time_ms) / 1000.0;
  if (slot->vol_dur <= 0.0) slot->vol_current = target;
  SFA_LOGI("bridge: sndSeqVolume vol %u -> %.3f en %u ms "
           "(handle %u, cancion %u, desde %.3f)",
           volume, target, time_ms, seq_handle, slot->track_id,
           slot->vol_from);
  return true;
}

void AudioBridge::AdvanceSlotVolume(SongSlot* slot, double dt_seconds) {
  if (slot == nullptr) return;
  if (slot->vol_dur <= 0.0 || slot->vol_t >= slot->vol_dur) {
    slot->vol_current = slot->vol_to;
    return;
  }
  slot->vol_t += dt_seconds;
  double f = slot->vol_t >= slot->vol_dur
                 ? 1.0
                 : slot->vol_t / slot->vol_dur;
  slot->vol_current = static_cast<float>(
      slot->vol_from + (slot->vol_to - slot->vol_from) * f);
}

void AudioBridge::AdvanceSeqVolume(double dt_seconds) {
  for (SongSlot& slot : song_slots_) {
    if (slot.active) AdvanceSlotVolume(&slot, dt_seconds);
  }
}

// Tramo 9 - observacion de streams (patch-A, ver INFORME.md
// §1): StartPrepared confirma el pendiente de Play; un
// segundo StartPrepared sin pendiente nuevo es doble
// arranque (devuelve false, no duplica sonido: el bridge
// ya suena desde Play y el juego ya esta en playing=1).
bool AudioBridge::OnStartPrepared() {
  ++start_prepared_entries_;
  if (pending_prepared_id_ == 0) {
    SFA_LOGI("bridge: StartPrepared sin stream pendiente "
             "(duplicado o sin Play previo: sin efecto)");
    return false;
  }
  uint32_t id = pending_prepared_id_;
  pending_prepared_id_ = 0;
  ++start_prepared_confirms_;
  SFA_LOGI("bridge: StartPrepared confirma stream %u (juego en "
           "playing)", id);
  return true;
}

bool AudioBridge::OnGetCurrentId() {
  ++getcurrentid_polls_;
  if (guest_ram_ == nullptr ||
      kGuestCurrentIdAddr < 0x80000000u ||
      kGuestCurrentIdAddr - 0x80000000u + 4 > guest_ram_size_) {
    return false;
  }
  uint32_t off = kGuestCurrentIdAddr - 0x80000000u;
  const uint8_t* q = guest_ram_ + off;
  uint32_t value = (static_cast<uint32_t>(q[0]) << 24) |
                   (static_cast<uint32_t>(q[1]) << 16) |
                   (static_cast<uint32_t>(q[2]) << 8) |
                   static_cast<uint32_t>(q[3]);
  getcurrentid_last_ = value;
  // currentId es indice+1 (340 para 1301), NO el id de stream:
  // solo se compara cero / no-cero, y solo fuera de la
  // ventana Play->StartPrepared (pendiente != 0).
  bool guest_playing = value != 0;
  bool bridge_playing = stream_voice_.active || StreamSourceActive();
  if (pending_prepared_id_ == 0 && guest_playing != bridge_playing) {
    ++getcurrentid_mismatches_;
    SFA_LOGI("bridge: GetCurrentId desajuste: juego currentId=%u "
             "(%s) vs bridge stream %s",
             value, guest_playing ? "sonando" : "parado",
             bridge_playing ? "activo" : "inactivo");
  }
  return true;
}

void AudioBridge::StopAllMusic() {
  for (SongSlot& slot : song_slots_) StopSlotMusic(&slot);
}

bool AudioBridge::MusyxVoicePcmCopy(size_t note_index,
                                    std::vector<int16_t>* out) const {
  if (out == nullptr) return false;
  for (const MusicVoice& v : music_voices_) {
    if (v.active && v.note_index == note_index) {
      *out = v.pcm;
      return true;
    }
  }
  return false;
}

size_t AudioBridge::MusyxActiveNotes() const {
  size_t n = 0;
  for (const MusicVoice& v : music_voices_) {
    if (v.active) ++n;
  }
  return n;
}

bool AudioBridge::StartMusicNote(const MusyxNote& note,
                                 size_t note_index, size_t slot_idx) {
  const MusyxSampleEntry* entry = LookupSampleEntry(note.sample_id);
  if (entry == nullptr) {
    Unresolved u;
    u.id = note.sample_id;
    u.kind = "musyx_muestra";
    unresolved_.push_back(u);
    return false;
  }
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += entry->wav;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav) || wav.rate <= 0 ||
      wav.channels <= 0 || wav.Frames() == 0) {
    SFA_LOGI("bridge: MusyX WAV no legible '%s' (muestra %u)",
             path.c_str(), note.sample_id);
    return false;
  }
  // Pitch por resampleo lineal (Tramo 5, verificado 0,13 % en
  // S797): ratio = 2^((mac_key - pitch_base)/12).
  double ratio =
      std::pow(2.0, static_cast<double>(note.mac_key - note.pitch_base) /
                          12.0);
  double step = ratio * static_cast<double>(wav.rate) /
                static_cast<double>(Audio::kOutputRate);
  if (!(step > 0.0)) return false;
  // Duracion en frames a 48 kHz (key-off en time+length).
  const MusyxSong* song =
      slot_idx < song_slots_.size() ? song_slots_[slot_idx].seq.Song()
                                    : nullptr;
  double tps = song != nullptr ? MusyxTicksPerSecond(song->bpm) : 384.0;
  size_t dur_frames = static_cast<size_t>(
      static_cast<double>(note.length_ticks) / tps *
      static_cast<double>(Audio::kOutputRate));
  if (dur_frames == 0) return false;
  // Bucle de muestra por metadato (frames fuente; 0,0 = sin
  // bucle). Sin bucle, la voz termina al agotar la muestra
  // aunque la nota dure mas (igual que el render Tramo 5).
  uint64_t src_frames = wav.Frames();
  uint64_t loop_start = entry->loop_start;
  uint64_t loop_len = entry->loop_len;
  bool has_loop = loop_len > 0 && loop_start < src_frames &&
                  loop_start + loop_len <= src_frames;
  // Pan CC10 vigente en el note-on (formula del render
  // Tramo 5, balance lineal, no ley DSP).
  uint32_t pan = 64;
  if (note.midi < 16 && slot_idx < song_slots_.size())
    pan = song_slots_[slot_idx].cc10[note.midi];
  double gl = 1.0, gr = 1.0;
  if (pan <= 64) {
    gl = 1.0;
    gr = pan == 0 ? 0.0 : static_cast<double>(pan) / 64.0;
  } else {
    gl = static_cast<double>(127 - pan) / 63.0;
    gr = 1.0;
  }
  std::vector<int16_t> pcm;
  pcm.reserve(dur_frames * 2);
  double pos = 0.0;
  for (size_t f = 0; f < dur_frames; ++f) {
    uint64_t p = static_cast<uint64_t>(pos);
    if (p >= src_frames) break;
    if (has_loop && p >= loop_start + loop_len) {
      pos = static_cast<double>(loop_start) +
            std::fmod(pos - static_cast<double>(loop_start + loop_len),
                      static_cast<double>(loop_len));
      p = static_cast<uint64_t>(pos);
    }
    double frac = pos - static_cast<double>(p);
    auto sample_at = [&](uint64_t idx) -> double {
      if (idx >= src_frames) return 0.0;
      if (wav.channels == 1) {
        return static_cast<double>(wav.samples[idx]);
      }
      // Estereo inesperado en MusyX: media de canales.
      double a = static_cast<double>(wav.samples[idx * 2]);
      double b = static_cast<double>(wav.samples[idx * 2 + 1]);
      return (a + b) * 0.5;
    };
    double s = sample_at(p) + (sample_at(p + 1) - sample_at(p)) * frac;
    pcm.push_back(static_cast<int16_t>(std::lround(s * gl)));
    pcm.push_back(static_cast<int16_t>(std::lround(s * gr)));
    pos += step;
    if (has_loop && pos >= static_cast<double>(loop_start + loop_len)) {
      pos = static_cast<double>(loop_start) +
            std::fmod(pos - static_cast<double>(loop_start),
                      static_cast<double>(loop_len));
    }
  }
  if (pcm.empty()) return false;
  MusicVoice* slot = nullptr;
  for (MusicVoice& v : music_voices_) {
    if (!v.active) {
      slot = &v;
      break;
    }
  }
  if (slot == nullptr) {
    // Robo: la voz activa mas antigua (primer slot activo).
    for (MusicVoice& v : music_voices_) {
      if (v.active) {
        slot = &v;
        break;
      }
    }
    ++musyx_stolen_;
    SFA_LOGI("bridge: MusyX voz robada (32 ocupadas, nota %zu)",
             note_index);
  }
  Played p;
  p.id = note.sample_id;
  p.kind = "musyx_nota";
  p.wav = entry->wav;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->base_gain = static_cast<float>(note.mac_vol) / 127.0f;
  slot->midi = note.midi;
  slot->note_index = note_index;
  slot->slot = slot_idx;
  slot->active = true;
  ++musyx_started_;
  return true;
}

void AudioBridge::StopMusicNote(size_t slot_idx, size_t note_index) {
  for (MusicVoice& v : music_voices_) {
    if (v.active && v.slot == slot_idx && v.note_index == note_index) {
      v.active = false;
      v.pcm.clear();
      v.pos = 0;
      ++musyx_ended_;
      return;
    }
  }
}

void AudioBridge::PumpSlot(SongSlot* slot, double dt_seconds) {
  if (slot == nullptr || !slot->seq.Active()) return;
  size_t slot_idx = static_cast<size_t>(slot - song_slots_.data());
  std::vector<MusyxSequencer::Event> events;
  slot->seq.Advance(dt_seconds, &events);
  for (const MusyxSequencer::Event& e : events) {
    if (e.kind == MusyxSequencer::Event::kCc && e.cc != nullptr) {
      if (e.cc->midi < 16) {
        if (e.cc->cc == 7) slot->cc7[e.cc->midi] = e.cc->value;
        if (e.cc->cc == 10) slot->cc10[e.cc->midi] = e.cc->value;
        // Tramo 11: CC19 (pan surround) se guarda como estado; NO
        // se aplica a la mezcla estereo (el mezclador no tiene
        // bus surround; ver INFORME.md).
        if (e.cc->cc == 19) slot->cc19[e.cc->midi] = e.cc->value;
      }
    } else if (e.kind == MusyxSequencer::Event::kLoop) {
      // Tramo 8: al envolver, los CC vuelven al snapshot
      // de inicio de bucle (sin esto, la segunda vuelta
      // sonaria con la automatizacion final de la primera:
      // en 74, CC7 de midi 1/2 seria 37/40 en vez de
      // 101/75). Los CC de la ventana del bucle que vencen
      // despues reescriben estos valores en orden.
      for (int m = 0; m < 16; ++m) {
        slot->cc7[m] = slot->seq.LoopCc7(static_cast<uint32_t>(m));
        slot->cc10[m] = slot->seq.LoopCc10(static_cast<uint32_t>(m));
      }
    } else if (e.kind == MusyxSequencer::Event::kSectionLoop) {
      // Tramo 10: vuelta de seccion en la fase de bucle por
      // secciones. Los CC de vuelta llegan como eventos kCc
      // (secuenciador) y se aplican en la rama kCc; este
      // evento solo se registra.
      SFA_LOGI("bridge: MusyX cancion %u seccion %u vuelta nueva "
               "(handle %u)",
               slot->track_id, e.section_id, slot->handle);
    } else if (e.kind == MusyxSequencer::Event::kNoteOn &&
               e.note != nullptr) {
      // Tramo 8: mute de params (flags bit 0). Bit a 1 =
      // pista activa; bit a 0 = nota silenciada (no se
      // arranca voz ni se cuenta como nota iniciada; su
      // NoteOff posterior no encuentra voz y no hace nada).
      if (slot->mute_active && e.note->midi < 64) {
        uint32_t word = slot->mute[e.note->midi / 32];
        uint32_t bit = (word >> (e.note->midi % 32)) & 1u;
        if (bit == 0) continue;
      }
      StartMusicNote(*e.note, e.note_index, slot_idx);
    } else if (e.kind == MusyxSequencer::Event::kNoteOff) {
      StopMusicNote(slot_idx, e.note_index);
    }
  }
}

void AudioBridge::PumpSequencer(double dt_seconds) {
  for (SongSlot& slot : song_slots_) {
    if (slot.active) PumpSlot(&slot, dt_seconds);
  }
}

const char* AudioBridge::LookupStreamWav(uint32_t id) const {
  for (const StreamIdEntry& e : kStreamIdMap) {
    if (e.id == id) return e.wav;
  }
  return nullptr;
}

const MusyxSampleEntry* AudioBridge::LookupSampleEntry(
    uint32_t id) const {
  for (const MusyxSampleEntry& e : kMusyxSampleMap) {
    if (e.id == id) return &e;
  }
  return nullptr;
}

bool AudioBridge::EnqueueWav(const char* rel, uint32_t id,
                             const char* kind, float gain,
                             size_t loop_start_48k,
                             size_t loop_len_48k, bool is_stream) {
  if (audio_ == nullptr || rel == nullptr) return false;
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += rel;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV no legible '%s' (id %u, %s)",
             path.c_str(), id, kind);
    return false;
  }
  return EnqueueDecoded(wav, rel, id, kind, gain, loop_start_48k,
                        loop_len_48k, is_stream);
}

std::string AudioBridge::AdpRelForWav(const char* wav_rel) {
  if (wav_rel == nullptr) return "";
  if (indexed_root_ != wav_root_) {
    adp_index_.Build(wav_root_);
    indexed_root_ = wav_root_;
  }
  std::string found = adp_index_.Lookup(wav_rel);
  if (!found.empty()) return found;
  // Audio anadido a mitad de sesion (picker "anadir
  // audio"): el indice puede estar obsoleto; reconstruir
  // una vez y reintentar antes de rendirse al WAV.
  adp_index_.Build(wav_root_);
  found = adp_index_.Lookup(wav_rel);
  if (!found.empty()) return found;
  // Red de seguridad: sustitucion directa .wav -> .adp,
  // solo si ese fichero existe realmente (el indice es
  // la via principal; esto cubre packs sin streams/ en
  // el arbol esperado por el indice).
  std::string direct = wav_rel;
  size_t dot = direct.rfind(".wav");
  if (dot != std::string::npos) {
    direct.replace(dot, 4, ".adp");
    std::string path = wav_root_;
    if (!path.empty() && path.back() != '/') path += '/';
    path += direct;
    if (FileExists(path.c_str())) return direct;
  }
  return "";
}

bool AudioBridge::StartStreamSource(std::unique_ptr<StreamSource> src,
                                    const char* rel, const char* via,
                                    uint32_t id) {
  if (audio_ == nullptr || src == nullptr || rel == nullptr) {
    return false;
  }
  uint64_t total48 = src->TotalFrames48();
  if (total48 == 0) return false;
  CloseStreamSource();
  stream_voice_.active = false;
  stream_voice_.pcm.clear();
  stream_voice_.pos = 0;
  Played p;
  p.id = id;
  p.kind = "stream";
  p.wav = rel;
  p.src_rate = 32000;
  p.src_channels = 2;
  p.frames_48k = total48;
  played_.push_back(p);
  last_stream_via_ = via != nullptr ? via : "";
  stream_source_ = std::move(src);
  SFA_LOGI("bridge: stream por %s '%s' (32000 Hz x2, %llu "
           "frames a 48 kHz)",
           via != nullptr ? via : "?",
           rel, static_cast<unsigned long long>(total48));
  return true;
}

void AudioBridge::CloseStreamSource() {
  if (stream_source_ != nullptr) {
    stream_source_->Close();
    stream_source_.reset();
  }
}

bool AudioBridge::EnqueueDecoded(const Audio::WavData& wav,
                                 const char* rel, uint32_t id,
                                 const char* kind, float gain,
                                 size_t loop_start_48k,
                                 size_t loop_len_48k,
                                 bool is_stream) {
  if (audio_ == nullptr || rel == nullptr) return false;
  if (is_stream) CloseStreamSource();  // WAV sustituye al streaming.
  Voice* slot = nullptr;
  if (is_stream) {
    slot = &stream_voice_;  // La voz de stream es única.
  } else {
    for (Voice& v : sfx_voices_) {
      if (!v.active) {
        slot = &v;
        break;
      }
    }
    if (slot == nullptr) {
      ++dropped_sfx_;
      SFA_LOGI("bridge: SFX id %u descartado (8 voces "
               "ocupadas)", id);
      return false;
    }
  }
  std::vector<int16_t> pcm =
      Audio::ResampleToStereo(wav, Audio::kOutputRate);
  if (pcm.empty()) return false;
  Played p;
  p.id = id;
  p.kind = kind;
  p.wav = rel;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->gain = gain;
  slot->loop_start = loop_start_48k;
  slot->loop_len = loop_len_48k;
  slot->active = true;
  SFA_LOGI("bridge: %s id %u -> '%s' (%d Hz x%d, %llu frames "
           "a 48 kHz, bucle [%llu, %llu))",
           kind, id, rel, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k),
           static_cast<unsigned long long>(loop_start_48k),
           static_cast<unsigned long long>(loop_start_48k +
                                            loop_len_48k));
  return true;
}

bool AudioBridge::OnStreamPlay(uint32_t stream_id) {
  const char* wav = LookupStreamWav(stream_id);
  if (wav == nullptr) {
    Unresolved u;
    u.id = stream_id;
    u.kind = "stream";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: stream id %u sin resolver en la tabla "
             "(no se inventa sonido)",
             stream_id);
    return false;
  }
  // Tramo 9 (patch-A): el stream queda pendiente de confirmar
  // por StartPrepared (el juego solo esta en playing tras
  // StartPrepared; el bridge, como en v1, ya suena desde
  // Play: el pendiente es observacion, no puerta de sonido).
  pending_prepared_id_ = stream_id;
  last_stream_id_ = stream_id;
  // Tramo 5, orden: cache PCM -> ADP por bloques -> WAV
  // en memoria -> silencio + unresolved. El ADP es la
  // fuente de verdad (su PCM es bit a bit el WAV host);
  // preferir un WAV viejo sobre un ADP presente
  // introduciria divergencias si el pack mezcla
  // generaciones. El WAV queda como red de seguridad.
  if (!cache_cleaned_) {
    cache_cleaned_ = true;
    // Huerfanos de una sesion anterior (cierre a mitad,
    // falta de espacio): nunca se reproducen, se borran.
    CleanupCacheOrphans(cache_root_);
  }
  std::string adp_rel = AdpRelForWav(wav);
  if (!adp_rel.empty()) {
    std::string adp_path = wav_root_;
    if (!adp_path.empty() && adp_path.back() != '/') adp_path += '/';
    adp_path += adp_rel;
    // 1) Cache valida: lector por bloques sobre el .pcm.
    AdpCacheMeta meta;
    if (IsCacheValid(cache_root_, adp_rel, adp_path, &meta)) {
      auto reader = std::make_unique<PcmNativeReader>();
      if (reader->Open(CachePcmPath(cache_root_, adp_rel).c_str())) {
        TouchCache(cache_root_, adp_rel);
        auto src =
            std::make_unique<ResamplingSource>(std::move(reader));
        if (StartStreamSource(std::move(src), adp_rel.c_str(),
                              "cache", stream_id)) {
          return true;
        }
      }
      SFA_LOGI("bridge: cache valida pero ilegible '%s', "
               "se redecodifica del ADP",
               adp_rel.c_str());
    }
    // 2) ADP por bloques (+ escritura de cache en vivo).
    auto cached = std::make_unique<AdpCachedReader>();
    if (cached->Open(adp_path.c_str(), cache_root_, adp_rel,
                     cache_cap_) &&
        cached->TotalNativeFrames() > 0) {
      auto src =
          std::make_unique<ResamplingSource>(std::move(cached));
      if (StartStreamSource(std::move(src), adp_rel.c_str(), "adp",
                            stream_id)) {
        return true;
      }
    }
    SFA_LOGI("bridge: stream %u sin ADP utilizable ('%s'), "
             "se intenta el WAV",
             stream_id, adp_rel.c_str());
  }
  // 3) WAV por el camino viejo en memoria (red de seguridad;
  // para streams largos, con su limite conocido del anillo).
  if (EnqueueWav(wav, stream_id, "stream", 1.0f, 0, 0, true)) {
    return true;
  }
  // 4) Nada reproducible: silencio + unresolved, sin crash.
  // Sin sonido no hay nada que confirme StartPrepared.
  pending_prepared_id_ = 0;
  last_stream_id_ = 0;
  Unresolved u;
  u.id = stream_id;
  u.kind = "stream";
  unresolved_.push_back(u);
  return false;
}

void AudioBridge::OnStreamStop() {
  // Detener SOLO la voz de stream. El backend sigue con lo
  // ya entregado (el anillo se drena solo); no se puede
  // "des-entregar" lo enviado, y no se pretende. Los SFX
  // en curso NO se tocan (Fase 17: antes se vaciaba toda
  // la cola serial, incluidos SFX que sonaban en paralelo).
  // Cerrar la fuente en streaming aborta su escritura de
  // cache parcial (no se promueve: limitacion v1).
  CloseStreamSource();
  stream_voice_.active = false;
  stream_voice_.pcm.clear();
  stream_voice_.pos = 0;
  pending_prepared_id_ = 0;
  last_stream_id_ = 0;
  SFA_LOGI("bridge: stop de stream (solo voz de stream)");
}

void AudioBridge::OnSfxStop() {
  for (Voice& v : sfx_voices_) {
    v.active = false;
    v.pcm.clear();
    v.pos = 0;
  }
  SFA_LOGI("bridge: stop de SFX (voces SFX vaciadas)");
}

int AudioBridge::OnSfxTrigger(uint32_t trigger_id) {
  const SfxTriggerEntry* found = nullptr;
  for (const SfxTriggerEntry& e : kSfxTriggerMap) {
    if (e.id == trigger_id) {
      found = &e;
      break;
    }
  }
  if (found == nullptr) {
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u desconocido", trigger_id);
    return 0;
  }
  // Fase 16, corrección verificada en código huésped: los 4 campos
  // de Sfx.bin son VARIANTES alternativas (una por disparo,
  // elegida por pesos en Sfx_ReadTriggerParams), NO 4 sonidos
  // simultáneos. Hasta que los pesos estén en el mapa, se
  // reproduce la primera variante no nula documentada como
  // aproximación; para triggers de variante única (un solo
  // campo no nulo) esa primera variante ES la única, sin
  // ambigüedad.
  // TODO(Fase 16, siguiente paso): pesos + volRand/pitchRand
  // en audio_id_map.h y selección ponderada real.
  // TRAMO 5 (corrección Fase 18): cada variante NO es una
  // muestra, es un ID FX (sfxIds[] de Sfx.bin). Se resuelve
  // FX -> muestra por fx_table.h (kFxSample, tabla
  // verificada, NO identidad) y se encola por EnqueueSample,
  // el mismo camino que OnFxStart (bucle por metadato de la
  // muestra real y ganancia vol_base/127). El código anterior
  // usaba la variante como muestra directa y sonaba con el
  // WAV equivocado en 1331/1331 variantes (p. ej. trigger 13:
  // sonaba 175 y debe sonar 841, vía FX 175 -> macro 1040).
  // OnFxStart NO se toca: el camino real del juego
  // (sndFXStartEx) ya resolvía por esta tabla.
  // Nota Tramo 5: para FX 96/162/820 la tabla lleva la muestra
  // lineal de su macro, CONFIRMADA por recorrido MCMD completo
  // (play-macro = voz hija paralela con la misma muestra:
  // 96->1173, 162->1172, 820->1147; el doblaje a 2 voces queda
  // pendiente, la muestra no); aquí se usa esa misma muestra
  // lineal, igual que OnFxStart.
  uint16_t fx_id = 0;
  for (int i = 0; i < 4; ++i) {
    if (found->samples[i] != 0) {
      fx_id = found->samples[i];
      break;
    }
  }
  if (fx_id == 0) {
    // Trigger conocido pero sin variante (secuencia o grupo
    // MusyX): queda como no resuelto, no como silencio
    // inventado.
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u sin variante "
             "(secuencia/grupo, fuera de esta fase)",
             trigger_id);
    return 0;
  }
  if (fx_id >= kFxTableCount) {
    Unresolved u;
    u.id = trigger_id;
    u.kind = "sfx_trigger";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: trigger SFX id %u con FX %u fuera de "
             "tabla (0-832)",
             trigger_id, fx_id);
    return 0;
  }
  uint32_t sample_id = kFxSample[fx_id];
  SFA_LOGI("bridge: trigger SFX id %u -> FX %u -> muestra %u "
           "(tabla FX, no identidad)",
           trigger_id, fx_id, sample_id);
  uint64_t dropped_before = dropped_sfx_;
  if (EnqueueSample(sample_id,
                    static_cast<float>(found->vol_base) / 127.0f)) {
    return 1;
  }
  if (dropped_sfx_ > dropped_before) {
    // Voces llenas: ya contado en dropped_sfx_ por
    // EnqueueSample; no se añade un Unresolved espurio.
    return 0;
  }
  Unresolved u;
  u.id = trigger_id;
  u.kind = "sfx_trigger";
  unresolved_.push_back(u);
  return 0;
}

bool AudioBridge::EnqueueSample(uint32_t sample_id, float gain) {
  const MusyxSampleEntry* entry = LookupSampleEntry(sample_id);
  if (entry == nullptr) return false;
  Voice* slot = nullptr;
  for (Voice& v : sfx_voices_) {
    if (!v.active) {
      slot = &v;
      break;
    }
  }
  if (slot == nullptr) {
    ++dropped_sfx_;
    SFA_LOGI("bridge: SFX muestra %u descartada (8 voces ocupadas)",
             sample_id);
    return false;
  }
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += entry->wav;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV no legible '%s' (muestra %u)", path.c_str(),
             sample_id);
    return false;
  }
  std::vector<int16_t> pcm =
      Audio::ResampleToStereo(wav, Audio::kOutputRate);
  if (pcm.empty()) return false;
  size_t loop_start_48k = 0;
  size_t loop_len_48k = 0;
  if (entry->loop_len > 0 && wav.rate > 0) {
    loop_start_48k = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_start) *
         static_cast<uint64_t>(Audio::kOutputRate)) /
        static_cast<uint64_t>(wav.rate));
    loop_len_48k = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_len) *
         static_cast<uint64_t>(Audio::kOutputRate)) /
        static_cast<uint64_t>(wav.rate));
    size_t total = pcm.size() / 2;
    if (loop_start_48k + loop_len_48k > total) {
      loop_len_48k =
          total > loop_start_48k ? total - loop_start_48k : 0;
    }
  }
  Played p;
  p.id = sample_id;
  p.kind = "sfx_muestra";
  p.wav = entry->wav;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->gain = gain;
  slot->loop_start = loop_start_48k;
  slot->loop_len = loop_len_48k;
  slot->active = true;
  SFA_LOGI("bridge: sfx_muestra id %u -> '%s' (%d Hz x%d, %llu "
           "frames a 48 kHz, bucle [%llu, %llu), ganancia %.3f)",
           sample_id, entry->wav, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k),
           static_cast<unsigned long long>(loop_start_48k),
           static_cast<unsigned long long>(loop_start_48k +
                                            loop_len_48k),
           static_cast<double>(gain));
  return true;
}

int AudioBridge::OnFxStart(uint32_t fx_id, uint32_t volume,
                           uint32_t pan, uint32_t studio) {
  // Fase 18: fxId ya viene enmascarado por el llamador del
  // hook (r3&0xFFFF); aquí se vuelve a enmascarar por
  // seguridad para llamadas directas del test host.
  fx_id &= 0xFFFFu;
  volume &= 0xFFu;
  pan &= 0xFFu;
  studio &= 0xFFu;
  if (fx_id >= kFxTableCount) {
    Unresolved u;
    u.id = fx_id;
    u.kind = "sfx_fx";
    unresolved_.push_back(u);
    SFA_LOGI("bridge: FX %u desconocido (fuera de tabla 0-832)",
             fx_id);
    return 0;
  }
  // 0xFF = valor del descriptor (volume 127, panning 64 en
  // los 833). El panning hoy solo se registra: no se aplica
  // ley de paneo inventada sobre un WAV ya estéreo/mono
  // resampleado.
  uint32_t vol = (volume == 0xFFu) ? 127u : volume;
  uint32_t pan_eff = (pan == 0xFFu) ? 64u : pan;
  float gain = static_cast<float>(vol) / 127.0f;
  uint32_t sample_id = kFxSample[fx_id];
  SFA_LOGI("bridge: sndFXStartEx fx=%u studio=%u pan=%u -> "
           "muestra %u (tabla FX, no identidad)",
           fx_id, studio, pan_eff, sample_id);
  if (!EnqueueSample(sample_id, gain)) {
    Unresolved u;
    u.id = fx_id;
    u.kind = "sfx_fx";
    unresolved_.push_back(u);
    return 0;
  }
  return 1;
}

// Tramo 6 — voz hija con pitch (copia deliberada de
// EnqueueSample, ver fx_double.h): tasa efectiva 48000/ratio.
bool AudioBridge::EnqueueSamplePitched(uint32_t sample_id, float gain,
                                       double pitch_ratio) {
  if (pitch_ratio <= 0.0) return false;
  int eff_rate = static_cast<int>(
      std::lround(static_cast<double>(Audio::kOutputRate) / pitch_ratio));
  if (eff_rate <= 0) return false;
  const MusyxSampleEntry* entry = LookupSampleEntry(sample_id);
  if (entry == nullptr) return false;
  Voice* slot = nullptr;
  for (Voice& v : sfx_voices_) {
    if (!v.active) {
      slot = &v;
      break;
    }
  }
  if (slot == nullptr) {
    ++dropped_sfx_;
    SFA_LOGI("bridge: SFX hija muestra %u descartada (8 voces ocupadas)",
             sample_id);
    return false;
  }
  std::string path = wav_root_;
  if (!path.empty() && path.back() != '/') path += '/';
  path += entry->wav;
  Audio::WavData wav;
  if (!Audio::LoadWavFile(path.c_str(), &wav)) {
    SFA_LOGI("bridge: WAV hija no legible '%s' (muestra %u)", path.c_str(),
             sample_id);
    return false;
  }
  std::vector<int16_t> pcm = Audio::ResampleToStereo(wav, eff_rate);
  if (pcm.empty()) return false;
  size_t loop_start_eff = 0;
  size_t loop_len_eff = 0;
  if (entry->loop_len > 0 && wav.rate > 0) {
    loop_start_eff = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_start) *
         static_cast<uint64_t>(eff_rate)) /
        static_cast<uint64_t>(wav.rate));
    loop_len_eff = static_cast<size_t>(
        (static_cast<uint64_t>(entry->loop_len) *
         static_cast<uint64_t>(eff_rate)) /
        static_cast<uint64_t>(wav.rate));
    size_t total = pcm.size() / 2;
    if (loop_start_eff + loop_len_eff > total) {
      loop_len_eff =
          total > loop_start_eff ? total - loop_start_eff : 0;
    }
  }
  Played p;
  p.id = sample_id;
  p.kind = "sfx_muestra";
  p.wav = entry->wav;
  p.src_rate = wav.rate;
  p.src_channels = wav.channels;
  p.frames_48k = pcm.size() / 2;
  played_.push_back(p);
  slot->pcm = std::move(pcm);
  slot->pos = 0;
  slot->gain = gain;
  slot->loop_start = loop_start_eff;
  slot->loop_len = loop_len_eff;
  slot->active = true;
  SFA_LOGI("bridge: sfx_muestra hija id %u -> '%s' (%d Hz x%d, %llu "
           "frames a 48 kHz efectivos, tasa %d, bucle [%llu, %llu), "
           "ganancia %.3f)",
           sample_id, entry->wav, wav.rate, wav.channels,
           static_cast<unsigned long long>(p.frames_48k), eff_rate,
           static_cast<unsigned long long>(loop_start_eff),
           static_cast<unsigned long long>(loop_start_eff + loop_len_eff),
           static_cast<double>(gain));
  return true;
}

// Tramo 6 — doblaje: padre por OnFxStart + hija por pitch.
int AudioBridge::OnFxStartDoubled(uint32_t fx_id, uint32_t volume,
                                  uint32_t pan, uint32_t studio) {
  if (OnFxStart(fx_id, volume, pan, studio) != 1) return 0;
  const FxChildVoice* child = FindFxChildVoice(fx_id & 0xFFFFu);
  if (child == nullptr) return 1;
  if (child->sample_id != kFxSample[fx_id & 0xFFFFu]) {
    SFA_LOGI("bridge: doblaje FX %u incoherente con fx_table "
             "(hija %u != tabla %u): solo padre",
             fx_id & 0xFFFFu, child->sample_id,
             kFxSample[fx_id & 0xFFFFu]);
    return 1;
  }
  uint32_t vol = (volume & 0xFFu) == 0xFFu ? 127u : (volume & 0xFFu);
  float gain = static_cast<float>(vol) / 127.0f;
  double ratio = std::pow(2.0, static_cast<double>(child->child_key -
                                                  child->parent_key) /
                                     12.0);
  SFA_LOGI("bridge: doblaje FX %u -> hija muestra %u (tecla %d -> %d, "
           "ratio %.6f, pan padre %d / hija %d registrado sin aplicar)",
           fx_id & 0xFFFFu, child->sample_id, child->parent_key,
           child->child_key, ratio, child->parent_pan, child->child_pan);
  if (!EnqueueSamplePitched(child->sample_id, gain, ratio)) {
    return 1;
  }
  return 2;
}

bool AudioBridge::OnAudioEntry(uint32_t pc, uint32_t r3,
                               uint32_t r4, uint32_t r5,
                               uint32_t r6, uint32_t r7) {
  Counted c;
  c.pc = pc;
  c.r3 = r3;
  counted_.push_back(c);
  if (pc == kAudioStreamPlay) return OnStreamPlay(r3);
  if (pc == kAudioStreamStopCurrent) {
    OnStreamStop();
    return true;
  }
  if (pc == kAudioStreamStartPrepared) {
    return OnStartPrepared();
  }
  if (pc == kAudioStreamGetCurrentId) {
    return OnGetCurrentId();
  }
  if (pc == kSndFxStartEx) {
    // sndFXStartEx (Fase 18, layout verificado en código
    // huésped): r3=fxId, r4=volume, r5=pan, r6=studio.
    // r7 se ignora (basura del llamador).
    // Tramo 6, decisión de integración: el hook pasa a
    // OnFxStartDoubled (padre por OnFxStart + hija para
    // 96/162/820); OnFxStart sigue intacto y OnSfxTrigger
    // sigue siendo 1 voz a propósito.
    return OnFxStartDoubled(r3 & 0xFFFFu, r4 & 0xFFu, r5 & 0xFFu,
                            r6 & 0xFFu) >= 1;
  }
  if (pc == kSndSeqPlayEx) {
    // sndSeqPlayEx (Tramo 6, layout verificado en codigo
    // huesped y en TRAMO5.md §7): r3=sgid, r4=sid (track),
    // r5=arrfile (puntero huesped, no se lee), r6=params
    // (puntero huesped a SynthPlayParams: se registra, no
    // se lee — sin acceso a RAM huesped), r7=studio (0 en
    // el camino Music_ChannelLoadedCallback).
    (void)r5;
    (void)r7;
    return OnSeqPlay(r3, r4, r6) == 1;
  }
  if (pc == kSndSeqStop) {
    // Tramo 10: r3 = seqHandle (verificado en codigo huesped,
    // ver OnSeqStopHandle; con una unica cancion, el fallback
    // cubre handle 0; bit 31 / -1 no detienen).
    return OnSeqStopHandle(r3) == 1;
  }
  if (pc == kSndSeqVolume) {
    // sndSeqVolume (Tramo 8, layout verificado en codigo
    // huesped): r3=volumen, r4=tiempo, r5=seqHandle.
    // r6 se ignora (0 en la llamada medida).
    return OnSeqVolume(r3, r4, r5);
  }
  // Demas entradas de audio: solo conteo (layout de
  // argumentos sin verificar; ver cabecera).
  return false;
}

uint64_t AudioBridge::QueuedFrames() const {
  uint64_t total = 0;
  auto add = [&total](const Voice& v) {
    if (!v.active) return;
    if (v.HasLoop()) {
      // Hasta el fin de la iteración actual del bucle.
      total += v.LoopEnd() > v.pos ? v.LoopEnd() - v.pos : 0;
    } else {
      total += v.Total() > v.pos ? v.Total() - v.pos : 0;
    }
  };
  for (const Voice& v : sfx_voices_) add(v);
  add(stream_voice_);
  if (StreamSourceActive()) {
    uint64_t total48 = stream_source_->TotalFrames48();
    uint64_t pos48 = stream_source_->Position48();
    total += total48 > pos48 ? total48 - pos48 : 0;
  }
  return total;
}

size_t AudioBridge::ActiveVoiceCount() const {
  size_t n = 0;
  for (const Voice& v : sfx_voices_) {
    if (v.active) ++n;
  }
  if (stream_voice_.active) ++n;
  if (StreamSourceActive()) ++n;
  return n;
}

std::vector<uint64_t> AudioBridge::ActiveVoicePositions() const {
  std::vector<uint64_t> out;
  for (const Voice& v : sfx_voices_) {
    if (v.active) out.push_back(static_cast<uint64_t>(v.pos));
  }
  if (stream_voice_.active) {
    out.push_back(static_cast<uint64_t>(stream_voice_.pos));
  }
  if (StreamSourceActive()) {
    out.push_back(stream_source_->Position48());
  }
  return out;
}

void AudioBridge::Tick() {
  if (audio_ == nullptr) return;
  // Tramo 6: eventos MusyX vencidos hasta el tick actual
  // (el reloj avanza al final del Tick anterior; el primer
  // Tick procesa tick 0). Los eventos que vencen con el
  // avance de este Tick se procesan en el Tick siguiente:
  // latencia de arranque <= 1 bloque (85 ms), documentada.
  // Tramo 9: PumpSequencer itera los slots activos.
  PumpSequencer(0.0);
  // Una fuente en streaming que llego a EOF en el Tick
  // anterior se cierra aqui (no en mitad de la mezcla).
  if (stream_source_ != nullptr && stream_source_->AtEof()) {
    CloseStreamSource();
  }
  // Voces activas en orden: SFX (slots) + stream.
  Voice* voices[9];
  size_t nvoices = 0;
  for (Voice& v : sfx_voices_) {
    if (v.active) voices[nvoices++] = &v;
  }
  if (stream_voice_.active) voices[nvoices++] = &stream_voice_;
  bool stream_on = StreamSourceActive();
  size_t nmusic = MusyxActiveNotes();
  if (nvoices == 0 && !stream_on && nmusic == 0) {
    if (AnySongActive()) {
      // Sin voces pero con cancion en curso: el reloj debe
      // seguir hasta la proxima nota (huecos entre notas).
      // Se entrega un bloque de silencio y se avanza.
      std::vector<int16_t> silence(
          static_cast<size_t>(kFeedFrames) * 2, 0);
      audio_->SubmitBuffer(silence.data(), kFeedFrames);
      AdvanceSeqVolume(static_cast<double>(kFeedFrames) /
                       static_cast<double>(Audio::kOutputRate));
      PumpSequencer(static_cast<double>(kFeedFrames) /
                    static_cast<double>(Audio::kOutputRate));
      FinishSlots();
    }
    return;
  }

  // Tamaño del bloque: el mayor restante entre voces no
  // en bucle (una voz en bucle puede llenar el bloque
  // entero), recortado a kFeedFrames. Así, con voces en
  // paralelo, el total entregado es el máximo de las
  // longitudes, no la suma (la serie anterior sumaba).
  // La fuente en streaming aporta kFeedFrames mientras
  // no llegue a EOF (su restante exacto lo conoce ella,
  // pero el bloque se recorta igual a kFeedFrames).
  size_t block = 0;
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    size_t avail = v->HasLoop()
                       ? static_cast<size_t>(kFeedFrames)
                       : (v->Total() > v->pos ? v->Total() - v->pos
                                              : 0);
    if (avail > block) block = avail;
  }
  // Tramo 6: las voces de musica cuentan para el bloque
  // (sin bucle: lo que queda hasta su key-off).
  for (MusicVoice& v : music_voices_) {
    if (!v.active) continue;
    size_t avail = v.Total() > v.pos ? v.Total() - v.pos : 0;
    if (avail > block) block = avail;
  }
  if (stream_on && block < static_cast<size_t>(kFeedFrames)) {
    block = static_cast<size_t>(kFeedFrames);
  }
  if (block > static_cast<size_t>(kFeedFrames)) {
    block = static_cast<size_t>(kFeedFrames);
  }
  if (block == 0) return;

  // Bloque del stream en streaming (si lo hay): se lee
  // una sola vez por Tick, antes de mezclar.
  size_t stream_frames = 0;
  if (stream_on) {
    if (stream_scratch_.size() < block * 2) {
      stream_scratch_.resize(block * 2);
    }
    stream_frames =
        stream_source_->Read48k(stream_scratch_.data(), block);
  }

  // Suma en int32 y clamp duro UNA vez al final (no clamp
  // progresivo por voz: 20000+20000-20000 debe dar 20000,
  // no 12767).
  std::vector<int32_t> acc(block * 2, 0);
  // Voz en streaming: suma su bloque leido (puede ser
  // parcial en EOF; el resto del bloque es silencio para
  // ella, no para las demas voces).
  if (stream_on) {
    for (size_t f = 0; f < stream_frames; ++f) {
      acc[f * 2] += stream_scratch_[f * 2];
      acc[f * 2 + 1] += stream_scratch_[f * 2 + 1];
    }
  }
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    for (size_t f = 0; f < block; ++f) {
      size_t idx;
      if (v->HasLoop()) {
        size_t raw = v->pos + f;
        if (raw < v->LoopEnd()) {
          idx = raw;
        } else {
          idx = v->loop_start +
                (raw - v->LoopEnd()) % v->loop_len;
        }
      } else {
        if (v->pos + f >= v->Total()) continue;
        idx = v->pos + f;
      }
      acc[f * 2] += static_cast<int32_t>(std::lround(
          static_cast<float>(v->pcm[idx * 2]) * v->gain));
      acc[f * 2 + 1] += static_cast<int32_t>(std::lround(
          static_cast<float>(v->pcm[idx * 2 + 1]) * v->gain));
    }
  }
  // Tramo 6: voces de musica. Ganancia por bloque (no por
  // muestra): base_gain (mac_vol/127) x CC7 vigente del
  // canal / 127. El pan ya va horneado en el PCM (CC10 del
  // note-on). La rampa CC7 intra-nota queda asi a
  // resolucion de bloque (85 ms), no por muestra como en
  // el render offline Tramo 5.
  // Tramo 8: el fade sndSeqVolume avanza con el bloque
  // mezclado (antes de mezclar, para que el bloque ya lo
  // refleje) y multiplica la ganancia de musica.
  AdvanceSeqVolume(static_cast<double>(block) /
                   static_cast<double>(Audio::kOutputRate));
  for (MusicVoice& v : music_voices_) {
    if (!v.active) continue;
    // Tramo 9: CC7 y fade del slot de la voz, no globales.
    const SongSlot& vs =
        v.slot < song_slots_.size()
            ? song_slots_[v.slot]
            : song_slots_[0];
    float g = v.base_gain *
              static_cast<float>(v.midi < 16 ? vs.cc7[v.midi] : 127) /
              127.0f *
              vs.vol_current;
    for (size_t f = 0; f < block; ++f) {
      if (v.pos + f >= v.Total()) continue;
      size_t idx = v.pos + f;
      acc[f * 2] += static_cast<int32_t>(
          std::lround(static_cast<float>(v.pcm[idx * 2]) * g));
      acc[f * 2 + 1] += static_cast<int32_t>(
          std::lround(static_cast<float>(v.pcm[idx * 2 + 1]) * g));
    }
  }
  std::vector<int16_t> mixed(block * 2);
  for (size_t i = 0; i < block * 2; ++i) {
    mixed[i] = ClampS16(acc[i]);
  }
  audio_->SubmitBuffer(mixed.data(), static_cast<int>(block));

  // Avance de la fuente en streaming: si llego a EOF con
  // este bloque, se cierra (la cache, si la habia, ya se
  // promovio al decodificar el ultimo frame nativo).
  if (stream_on && stream_source_->AtEof()) {
    CloseStreamSource();
  }

  // Avance: no en bucle termina en EOF; en bucle, al
  // llegar a loop_end se repite la región (la cola tras
  // loop_end nunca se alcanza).
  for (size_t i = 0; i < nvoices; ++i) {
    Voice* v = voices[i];
    if (v->HasLoop()) {
      size_t np = v->pos + block;
      if (np >= v->LoopEnd()) {
        v->pos = v->loop_start +
                 (np - v->LoopEnd()) % v->loop_len;
      } else {
        v->pos = np;
      }
    } else {
      v->pos += block;
      if (v->pos >= v->Total()) {
        v->active = false;
        v->pcm.clear();
        v->pos = 0;
      }
    }
  }
  // Tramo 6: avance de voces de musica (sin bucle: el
  // bucle de muestra ya se expandio al renderizar) y del
  // reloj del secuenciador (el bloque mezclado es el
  // tiempo de audio entregado).
  for (MusicVoice& v : music_voices_) {
    if (!v.active) continue;
    v.pos += block;
    if (v.pos >= v.Total()) {
      v.active = false;
      v.pcm.clear();
      v.pos = 0;
    }
  }
  PumpSequencer(static_cast<double>(block) /
                static_cast<double>(Audio::kOutputRate));
  FinishSlots();
}

}  // namespace sfa
