#pragma once

// CPU Gekko (PowerPC) — STUB de la base.
//
// El código real ya existe como C recompilado por DolRecomp (176
// chunks, 0 instrucciones desconocidas), pero su integración no es
// pegar los chunks aquí: en el DolRecomp actual el mapa de símbolos
// NO renombra funciones en el C (los chunks salen como func_<chunk>),
// y el mapa solo sirve al runtime vía generated_symbols.h (9.591
// símbolos ejecutables, FASE2.md §6).
//
// Por eso este stub solo guarda el PC y registra los primeros pasos.
// El dispatch por nombre (o el post-procesado de chunks) es el
// siguiente bloque de trabajo, no un detalle menor.

#include <cstdint>

#include "gamecube_runtime/memory.h"

namespace sfa {

class GekkoCpu {
 public:
  explicit GekkoCpu(GCMemory* memory) : memory_(memory) {}

  void Reset();
  // Un paso: STUB. Avanza el PC de forma nominal y registra los
  // primeros pasos; no ejecuta código del juego todavía.
  void Step();

  uint32_t Pc() const { return pc_; }
  uint64_t Steps() const { return steps_; }

 private:
  GCMemory* memory_ = nullptr;
  uint32_t pc_ = GCMemory::kEntry;
  uint64_t steps_ = 0;
};

}  // namespace sfa
