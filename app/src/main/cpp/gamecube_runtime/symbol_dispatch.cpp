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
