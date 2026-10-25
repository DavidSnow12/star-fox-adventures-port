#pragma once

// Dispatch por nombre — STUB de la base, aportación de la IA de GitHub.
//
// Idea integrada (sin tocar el C de DolRecomp): el runtime no debe
// depender de que las funciones recompiladas se renombren o no. El
// C actual se compila tal cual (chunks como func_<chunk>) y esta
// capa resuelve por nombre a partir de generated_symbols.h y
// symbols.map, cuando esa integración llegue.
//
// Reglas de esta capa, desde el primer día:
//   - No se renombra ni se parchea el C original.
//   - No se resuelven los 9.591 símbolos ejecutables de golpe: solo
//     la tabla mínima de arranque (boot, frame, render, audio,
//     input, memoria, log), y el resto cuando lo pida una ruta real.
//   - Lookup() devuelve nullptr con un log si el símbolo no está
//     registrado todavía; nunca se inventa una dirección.
//
// Los nombres de kMinimalImports son marcadores de ruta (boot,
// frame, render...), no símbolos reales de generated_symbols.h:
// la tabla real se generará desde ese fichero en la integración.

#include <cstddef>

namespace sfa {

class SymbolDispatch {
 public:
  // Nombres de ruta mínima, a sustituir por símbolos reales de
  // generated_symbols.h en la integración DolRecomp.
  static constexpr const char* kMinimalImports[] = {
      "boot", "frame_tick", "render", "audio", "input",
      "memory_alloc", "debug_log",
  };
  static constexpr std::size_t kMinimalImportCount =
      sizeof(kMinimalImports) / sizeof(kMinimalImports[0]);

  void Register(const char* name, void* address);
  // Devuelve nullptr si no está registrado (con log, una vez por
  // nombre, para no inundar el log en el loop).
  void* Lookup(const char* name);
  std::size_t RegisteredCount() const { return count_; }

 private:
  static constexpr std::size_t kMaxEntries = 64;
  const char* names_[kMaxEntries] = {};
  void* addresses_[kMaxEntries] = {};
  std::size_t count_ = 0;
};

}  // namespace sfa
