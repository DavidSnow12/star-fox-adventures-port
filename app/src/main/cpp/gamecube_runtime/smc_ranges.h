#pragma once

// Rangos SMC (código automodificable) — STUB de la base, aportación
// de la IA de GitHub.
//
// Los 107 rangos documentados en generated_smc.txt (FASE2.md) se
// tratan como un catálogo de patches aplicables por el runtime, no
// como modificaciones al C original ni como parches aplicados a
// ciegas en memoria ejecutada.
//
// Reglas:
//   - El C original no se modifica en disco.
//   - Apply() en esta base solo REGISTRA el rango como aplicado;
//     un patch real en código ejecutado exigirá, además, flush de
//     caché de instrucciones, y eso es trabajo del runtime completo.
//   - Los datos embebidos en código no se dejan flotando: en la
//     integración, .text / .rodata / .data / .bss se separan y los
//     literales relativos a PC se recolocan por chunk.

#include <cstdint>
#include <vector>

namespace sfa {

struct SmcRange {
  uint32_t start_gc = 0;  // Dirección guest (0x8000..., no host).
  uint32_t end_gc = 0;
  bool patched = false;
};

class SmcTable {
 public:
  void AddRange(uint32_t start_gc, uint32_t end_gc);
  bool IsInSmcRange(uint32_t guest_address) const;
  // STUB: registra el patch, no modifica código ejecutado todavía.
  bool Apply(uint32_t start_gc);
  std::size_t Count() const { return ranges_.size(); }

 private:
  std::vector<SmcRange> ranges_;
};

}  // namespace sfa
