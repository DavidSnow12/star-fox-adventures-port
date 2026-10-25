#pragma once

// Decodificadores de texturas GX a RGBA (Fase 5b, sin GPU).
//
// Porte a C++ de los decodificadores verificados del extractor del
// repo (herramientas/texturas/extract_textures.py, decode_pure):
// mismos layouts de tile, mismos ensanchados de canal y mismo
// orden de subbloques CMPR; los dos decodificadores del extractor
// (numpy y Python puro) ya daban resultados byte a byte identicos
// en los 7 formatos reales del disco, asi que este porte se
// verifica contra sus PNG/RGBA (ver test host test_gx_tex).
//
// Formatos GX (codigo libogc): 0 I4, 1 I8, 2 IA4, 3 IA8, 4 RGB565,
// 5 RGB5A3, 6 RGBA8, 14 CMPR. Los formatos de paleta (8 C4, 9 C8,
// 10 C14X2) NO se decodifican: necesitan una TLUT que no va en el
// blob; en este disco hay 0 casos reales (ver RESUMEN-texturas).
// Los datos de entrada son el nivel base embaldosado (tiled), sin
// mipmaps ni imagen secundaria; la salida es RGBA fila-mayor, sin
// acolchado, recortada a (width, height) — igual que los PNG del
// extractor (sin voltear: la geometria voltea donde toca).

#include <cstdint>
#include <vector>

namespace sfa {

// Nombre del formato, o "?" si no es un formato GX conocido.
const char* GxFormatName(int format);

// Tamano en bytes del nivel base embaldosado para (width, height).
// false si el formato es de paleta o desconocido.
bool GxTextureBaseSize(uint32_t width, uint32_t height, int format,
                       uint32_t* out_bytes);

// Decodifica el nivel base a RGBA (width*height*4 bytes).
// data_len debe ser exactamente el tamano base; si no, false y
// rgba_out queda vacio. Paleta/desconocido: false.
bool GxDecodeTexture(const uint8_t* data, uint32_t data_len,
                     uint32_t width, uint32_t height, int format,
                     std::vector<uint8_t>* rgba_out);

// Placeholder documentado para una textura sin resolver: magenta
// opaco (nunca una textura inventada que parezca del juego).
void GxPlaceholderTexture(uint32_t width, uint32_t height,
                          std::vector<uint8_t>* rgba_out);

}  // namespace sfa
