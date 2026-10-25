#include "gamecube_runtime/symbol_dispatch.h"

#include <cstring>

#include "log.h"

namespace sfa {

void SymbolDispatch::Register(const char* name, void* address) {
  if (name == nullptr || count_ >= kMaxEntries) return;
  for (std::size_t i = 0; i < count_; ++i) {
    if (std::strcmp(names_[i], name) == 0) {
      addresses_[i] = address;
      return;
    }
  }
  names_[count_] = name;
  addresses_[count_] = address;
  ++count_;
}

void SymbolDispatch::RegisterGuest(const char* name,
                                   uint32_t guest_address) {
  if (name == nullptr || guest_count_ >= kMaxEntries) return;
  for (std::size_t i = 0; i < guest_count_; ++i) {
    if (std::strcmp(guest_names_[i], name) == 0) {
      guest_addresses_[i] = guest_address;
      return;
    }
  }
  guest_names_[guest_count_] = name;
  guest_addresses_[guest_count_] = guest_address;
  ++guest_count_;
}

uint32_t SymbolDispatch::LookupGuest(const char* name) const {
  if (name == nullptr) return 0;
  for (std::size_t i = 0; i < guest_count_; ++i) {
    if (std::strcmp(guest_names_[i], name) == 0) {
      return guest_addresses_[i];
    }
  }
  return 0;
}

void SymbolDispatch::RegisterGuestBoot() {
  // Direcciones verificadas en codigo/generated/generated_symbols.h
  // (y en codigo/symbols.map). No son punteros host.
  RegisterGuest("__start", 0x80003140u);
  RegisterGuest("__init_registers", 0x80003278u);
  RegisterGuest("__init_data", 0x80003294u);
  RegisterGuest("__init_hardware", 0x80003354u);
  RegisterGuest("__flush_cache", 0x80003374u);
  RegisterGuest("memset", 0x800033A8u);
  RegisterGuest("memcpy", 0x80003494u);
}

void* SymbolDispatch::Lookup(const char* name) {
  if (name == nullptr) return nullptr;
  for (std::size_t i = 0; i < count_; ++i) {
    if (std::strcmp(names_[i], name) == 0) return addresses_[i];
  }
  // STUB: sin tabla DolRecomp todavía, todo lookup falla de forma
  // explícita. No se devuelve una dirección inventada.
  SFA_LOGI("dispatch: simbolo '%s' no registrado todavia", name);
  return nullptr;
}

}  // namespace sfa
