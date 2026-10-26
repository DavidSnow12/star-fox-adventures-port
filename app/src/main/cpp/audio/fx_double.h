#pragma once

// Tramo 6 — Doblaje a 2 voces de FX con play-macro (voz hija
// paralela), NUEVO y sin tocar OnFxStart ni OnSfxTrigger.
//
// Origen (re-verificado el 2026-10-26 con walk_mcmd.py sobre
// disc/files/audio/starfoxs.poo, semántica SFA-Decomp
// mcmd_setup.c/mcmd_exec.c): play-macro (0x08) NO es un salto:
// genera una voz hija paralela (macStart) y el padre continúa.
// En estos 3 FX el hijo no tiene, a su vez, ningún play-macro,
// y no hay condicionales (if-key/if-vel/loop/goto/gosub) en
// padre ni hijo antes del START-SAMPLE. Padre e hijo tocan la
// MISMA muestra; lo que cambia es la tecla (y, en 675/595, el
// pan inicial):
//
//   FX   macro padre  tecla  pan   macro hijo  tecla  pan   muestra
//   96   675          24     0     676         22     127   1173
//   162  669          60     64*   670         58     64*   1172
//   820  595          60     0     596         55     127   1147
//
//   * 669/670 no tienen set-pan: pan = panning del descriptor
//     FX (64 en los 833, ver fx_table.h). 675/595 ponen pan 0
//     en el padre y 127 en el hijo (flags>>8 del set-pan).
//
// Qué modela el bridge y qué no:
//   - SÍ: dos voces paralelas de la misma muestra, la hija con
//     pitch por tecla: ratio = 2^((tecla_hija - tecla_padre)/12)
//     (-2 semitonos -> 0,890899; -5 -> 0,749154). El pitch se
//     aplica con la MISMA matemática de Audio::ResampleToStereo
//     (interpolación lineal), llamándola con una tasa efectiva
//     48000/ratio (53878 Hz para -2, 64072 Hz para -5): las
//     muestras resultantes, reproducidas a 48 kHz, suenan más
//     graves y duran 1/ratio veces más. Ganancia de la hija =
//     ganancia del padre (el scale-vol es idéntico en padre e
//     hijo: 0xff007f0d, valor 511, en los 6 macros) y bucle por
//     el mismo metadato de la muestra, reescalado a la tasa
//     efectiva (igual que EnqueueSample reescala a 48 kHz).
//   - NO: ley de paneo. El bridge no aplica paneo al padre
//     (limitación documentada de OnFxStart: el WAV ya es
//     estéreo/mono resampleado), así que tampoco se inventa
//     una para la hija; el pan queda registrado aquí para el
//     futuro, sin efecto en la mezcla. Tampoco se modelan los
//     wait-ms/envelope posteriores al arranque (irrelevantes
//     para qué muestra suena y cuándo arranca: step = 0, la
//     hija arranca en el mismo instante que el padre).
//   - Si no hay voz libre para la hija, se cuenta en
//     dropped_sfx_ (misma política que una voz SFX normal) y
//     suena solo el padre: exactamente lo que haría el
//     voiceAllocate del sintetizador sin voz libre.
//
// Uso: AudioBridge::OnFxStartDoubled (nuevo). OnFxStart sigue
// siendo 1 voz (camino verificado, sin cambios) y OnSfxTrigger
// sigue siendo 1 voz (camino por trigger corregido en el
// Tramo 5, sin cambios): el doblaje es opt-in por FX, no un
// cambio de comportamiento por defecto, hasta que el
// coordinador decida cablear el hook sndFXStartEx a la
// variante doblada.

#include <cstddef>
#include <cstdint>

namespace sfa {

struct FxChildVoice {
  uint32_t fx_id;
  uint32_t sample_id;  // Debe coincidir con kFxSample[fx_id].
  int parent_key;
  int child_key;
  int parent_pan;  // Registrado, sin efecto en la mezcla (ver arriba).
  int child_pan;   // Registrado, sin efecto en la mezcla (ver arriba).
};

constexpr FxChildVoice kFxChildVoices[] = {
    {96, 1173, 24, 22, 0, 127},
    {162, 1172, 60, 58, 64, 64},
    {820, 1147, 60, 55, 0, 127},
};

constexpr size_t kFxChildVoiceCount =
    sizeof(kFxChildVoices) / sizeof(kFxChildVoices[0]);

inline const FxChildVoice* FindFxChildVoice(uint32_t fx_id) {
  for (size_t i = 0; i < kFxChildVoiceCount; ++i) {
    if (kFxChildVoices[i].fx_id == fx_id) return &kFxChildVoices[i];
  }
  return nullptr;
}

}  // namespace sfa
