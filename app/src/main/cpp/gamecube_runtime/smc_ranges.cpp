#include "gamecube_runtime/smc_ranges.h"

#include "log.h"

namespace sfa {

void SmcTable::AddRange(uint32_t start_gc, uint32_t end_gc) {
  if (end_gc <= start_gc) return;
  ranges_.push_back(SmcRange{start_gc, end_gc, false});
}

bool SmcTable::IsInSmcRange(uint32_t guest_address) const {
  for (const SmcRange& range : ranges_) {
    if (guest_address >= range.start_gc && guest_address < range.end_gc) {
      return true;
    }
  }
  return false;
}

bool SmcTable::Apply(uint32_t start_gc) {
  for (SmcRange& range : ranges_) {
    if (range.start_gc == start_gc) {
      range.patched = true;
      SFA_LOGI("smc: rango 0x%08X registrado como aplicado (STUB, sin "
               "modificar codigo ejecutado, sin flush de cache todavia)",
               start_gc);
      return true;
    }
  }
  return false;
}

}  // namespace sfa
