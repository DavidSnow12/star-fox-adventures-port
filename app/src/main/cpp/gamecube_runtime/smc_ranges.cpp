#include "gamecube_runtime/smc_ranges.h"

#include <cstdio>
#include <cstring>

#include "log.h"

uint32_t sfa::SmcTable::LoadFromText(const char* text) {
  if (text == nullptr) return 0;
  uint32_t loaded = 0;
  const char* p = text;
  while (*p != '\0') {
    // Saltar hasta el inicio de una línea "0x".
    if (p[0] != '0' || p[1] != 'x') {
      while (*p != '\0' && *p != '\n') ++p;
      if (*p == '\n') ++p;
      continue;
    }
    uint32_t start_gc = 0;
    uint32_t end_gc = 0;
    int consumed = 0;
    if (std::sscanf(p, "0x%X-0x%X%n", &start_gc, &end_gc, &consumed) == 2) {
      AddRange(start_gc, end_gc);
      ++loaded;
      p += consumed;
    } else {
      while (*p != '\0' && *p != '\n') ++p;
    }
    while (*p != '\0' && *p != '\n') ++p;
    if (*p == '\n') ++p;
  }
  return loaded;
}

namespace sfa {

void SmcTable::AddRange(uint32_t start_gc, uint32_t end_gc) {
  // Los rangos de generated_smc.txt son INCLUSIVOS: la mayoría son
  // una sola dirección (start == end), y algunos son rangos
  // (p. ej. 0x8024B66C-0x8024B67C). No se descarta start == end.
  if (end_gc < start_gc) return;
  ranges_.push_back(SmcRange{start_gc, end_gc, false});
}

bool SmcTable::IsInSmcRange(uint32_t guest_address) const {
  for (const SmcRange& range : ranges_) {
    if (guest_address >= range.start_gc && guest_address <= range.end_gc) {
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
