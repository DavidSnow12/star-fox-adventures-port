#pragma once

// Mapa de memoria GameCube (base, sin integración DolRecomp todavía).
//
// Direcciones verificadas del DOL original (FASE2.md):
//   Entry: 0x80003140
//   BSS:   0x803371A0, tamaño 0xB2CB8
//   RAM de GameCube: 24 MiB, 0x80000000 - 0x81800000
//
// La imagen de memoria del juego real deberá incluir, además de la
// RAM, el código como datos legibles (1.646 palabras de datos
// embebidos en código, FASE2.md §6) y el BSS en su dirección exacta.
// Eso todavía no está: esta clase reserva la RAM y valida accesos,
// y el cargador de main.dol es el siguiente bloque de trabajo.

#include <cstdint>
#include <vector>

namespace sfa {

class GCMemory {
 public:
  static constexpr uint32_t kRamBase = 0x80000000u;
  static constexpr uint32_t kRamSize = 24u * 1024u * 1024u;
  static constexpr uint32_t kEntry = 0x80003140u;
  static constexpr uint32_t kBssBase = 0x803371A0u;
  static constexpr uint32_t kBssSize = 0xB2CB8u;

  GCMemory();

  // Reserva la RAM (puesta a cero) y marca el BSS dentro de ella.
  bool Init();

  // Cargador del juego: STUB. Devuelve false con un log claro hasta
  // que exista el cargador de main.dol (secciones text/data en sus
  // direcciones, BSS a cero, entry).
  bool LoadDol(const char* path);

  uint32_t Read32(uint32_t address) const;
  void Write32(uint32_t address, uint32_t value);

  // Accesos big-endian usados por el cargador y por mem.*.
  uint8_t Read8(uint32_t address) const;
  uint16_t Read16(uint32_t address) const;
  uint64_t Read64(uint32_t address) const;
  void Write8(uint32_t address, uint8_t value);
  void Write16(uint32_t address, uint16_t value);
  void Write64(uint32_t address, uint64_t value);
  // Copia un bloque guest->host (para el cargador DOL). Devuelve
  // false si el rango no cabe en RAM.
  bool WriteBytes(uint32_t address, const uint8_t* data, uint32_t size);
  // Pone a cero el BSS en su dirección exacta (ver dol_loader).
  bool ZeroBss();

  // Marca un rango como modificado (SMC). De momento solo registra;
  // la re-traducción/invalidación de código es trabajo del runtime.
  void MarkCodeModified(uint32_t address, uint32_t size);

  bool IsValid(uint32_t address) const {
    return address >= kRamBase && address < kRamBase + kRamSize;
  }

  // Separación guest/host (aportación de la IA de GitHub, integrada):
  // las direcciones 0x8000... son GUEST, lógicas del juego. El juego
  // NUNCA se ejecuta en esas direcciones reales del proceso ARM64:
  // la RAM guest vive en este buffer host, y toda traducción pasa
  // por GuestToHost(). Mapear guest 1:1 en el proceso sería un
  // segfault casi seguro.
  // Devuelve nullptr si la dirección guest no es válida.
  uint8_t* GuestToHost(uint32_t guest_address) {
    if (!IsValid(guest_address)) return nullptr;
    return ram_.data() + (guest_address - kRamBase);
  }

  uint8_t* RamData() { return ram_.data(); }
  uint32_t RamSize() const { return static_cast<uint32_t>(ram_.size()); }

 private:
  std::vector<uint8_t> ram_;
};

}  // namespace sfa
