#pragma once

// Cargador DOL de GameCube (Fase 1 del port).
//
// Formato DOL verificado con main.dol real (GSAP01 Rev 1):
//   offset 0x00: 7 offsets text (u32 BE)
//   offset 0x1C: 11 offsets data (u32 BE)
//   offset 0x48: 7 direcciones text (u32 BE)
//   offset 0x64: 11 direcciones data (u32 BE)
//   offset 0x90: 7 tamaños text (u32 BE)
//   offset 0xAC: 11 tamaños data (u32 BE)
//   offset 0xD8: dirección BSS (u32 BE)
//   offset 0xDC: tamaño BSS (u32 BE)
//   offset 0xE0: entry (u32 BE)
//   offset 0x100: primera sección (text0)
//
// Para main.dol: text0 0x80003100 (9.504 B), text1 0x800066E0
// (2.865.952 B), 8 secciones data, BSS 0x803371A0 (732.344 B),
// entry 0x80003140. Total text 2.875.456 B, total data 529.888 B.
//
// El cargador NO ejecuta nada: copia cada sección en su dirección
// guest exacta (vía GCMemory::WriteBytes, que traduce guest->host),
// pone el BSS a cero y devuelve la entry. Si cualquier sección
// no cabe en el fichero o en RAM, falla sin cargar parcialmente
// en la medida de lo posible (devuelve false y registra el motivo).

#include <cstdint>

#include "gamecube_runtime/memory.h"

namespace sfa {

struct DolLoadResult {
  bool ok = false;
  uint32_t entry = 0;
  uint32_t text_sections = 0;
  uint32_t data_sections = 0;
  uint32_t text_bytes = 0;
  uint32_t data_bytes = 0;
  const char* error = nullptr;
};

// Carga un DOL desde un buffer en memoria (el llamador Android
// leerá el fichero desde su paquete de datos; el test host lo lee
// desde disco). dol_size debe ser el tamaño completo del fichero.
DolLoadResult LoadDolFromBuffer(const uint8_t* dol, uint32_t dol_size,
                                GCMemory* memory);

// Carga un DOL desde un fichero del sistema de ficheros host/Android
// (ruta interna de la app, nunca una ruta absoluta de desarrollo).
DolLoadResult LoadDolFromFile(const char* path, GCMemory* memory);

}  // namespace sfa
