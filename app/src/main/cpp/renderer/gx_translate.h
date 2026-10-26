#pragma once

// Traduccion GX -> GL sin dependencias GLES (Fase 10).
//
// La misma matematica que el renderer host de Fase 5b
// (test_gx_render.cpp) y el mismo layout GXTexObj verificado:
//   - GxDrawToGlQuads(): pos_matrix 3x4, proyeccion orto o
//     perspectiva (camino perspectiva NO validado en run19),
//     viewport y region EFB (342,342); salida NDC (y arriba)
//     en vez de pixeles de canvas (y abajo).
//   - DecodeGxTexObj(): texObj+8 dims/formato, +12 direccion,
//     +36 tamano base; decodificacion en gx_texture.h. False
//     si el tamano base no coincide o el formato es de
//     paleta/desconocido.

#include <cstdint>
#include <vector>

#include "gamecube_runtime/gx.h"

namespace sfa {

struct GxDecodedTex {
  int width = 0;
  int height = 0;
  int format = 0;
  std::vector<uint8_t> rgba;
  bool ok = false;
};

bool DecodeGxTexObj(const uint8_t* ram, size_t ram_size, uint32_t tex_obj,
                    GxDecodedTex* out);

struct GlQuad {
  float x[4] = {0, 0, 0, 0};
  float y[4] = {0, 0, 0, 0};
  float s[4] = {0, 0, 0, 0};
  float t[4] = {0, 0, 0, 0};
  uint32_t tex_obj = 0;
  int tex_map = 0;
};

// Un triangulo GL (misma transformada que GlQuad, por vertice).
// Tramo 5: color0/color1 y UV por mapa (s/t = coord 0).
// Las UV ya llevan la matriz de textura aplicada (ver
// ApplyTexMatrix en gx_translate.cpp); el renderer GL solo
// las entrega como varyings.
struct GlTri {
  float x[3] = {0, 0, 0};
  float y[3] = {0, 0, 0};
  float s[3] = {0, 0, 0};
  float t[3] = {0, 0, 0};
  // Color vertice 0/1 en [0,1] (sin color en el vertice:
  // blanco opaco, igual que el parser).
  float cr0[3] = {1, 1, 1};
  float cg0[3] = {1, 1, 1};
  float cb0[3] = {1, 1, 1};
  float ca0[3] = {1, 1, 1};
  float cr1[3] = {1, 1, 1};
  float cg1[3] = {1, 1, 1};
  float cb1[3] = {1, 1, 1};
  float ca1[3] = {1, 1, 1};
  // UV por mapa (8 pares), con matriz ya aplicada.
  float uv_s[3][8] = {};
  float uv_t[3][8] = {};
  uint32_t tex_obj = 0;
  int tex_map = 0;
  // Texturas por mapa del draw (0 = sin carga para el mapa).
  uint32_t tex_objs[8] = {0, 0, 0, 0, 0, 0, 0, 0};
};

// Aplica una matriz de textura XF (12 floats, layout 3x4) a
// una UV (s,t) con la regla (s,t,1) 3x3 + division proyectiva
// si la fila 3 es no nula y w' != 0. SUPOSICION Tramo 5 (ver
// gx.h): el vector de entrada es (s,t,1) y la traslacion son
// m[2]/m[6]; una matriz 2x4 (8 palabras) deja la fila 3 a
// cero y no divide. La convencion de entrada para coords
// generadas (fuente POS/NRM) NO esta anclada: este camino
// solo transforma UV directas de vertice con TnMIDX.
bool ApplyTexMatrix(const float m[12], float s, float t, float* s_out,
                    float* t_out);

// 0 o 1 quad; false si no es QUADS de 4 vertices o no trae
// viewport/proyeccion. canvas 640x480 del renderer host; el
// mapeo a ventana real es estirado a NDC, sin correccion de
// aspecto todavia.
bool GxDrawToGlQuads(const GxDraw& draw, int canvas_w, int canvas_h,
                     GlQuad* out);

// Triangulacion general (Fase 11): QUADS -> 2 tris (0,1,2)
// (0,2,3), identicos a los que dibujaba GxDrawToGlQuads;
// TRIANGLES -> grupos de 3; TRIANGLESTRIP -> (v0,v1,v2),
// (v1,v3,v2), (v2,v3,v4)... (orden YAGCD 5.11.5.2.3, que
// alterna para conservar el winding); TRIANGLEFAN ->
// (v0,v1,v2), (v0,v2,v3)... LINES/LINESTRIP/POINTS y draws
// indexados/opacos (sin verts decodificados) devuelven false
// y se cuentan como saltados, no se dibujan. La matematica
// por vertice es la misma que GxDrawToGlQuads (perspectiva:
// camino NO validado en run19, igual que antes).
bool GxDrawToGlTris(const GxDraw& draw, int canvas_w, int canvas_h,
                    std::vector<GlTri>* out);

}  // namespace sfa
