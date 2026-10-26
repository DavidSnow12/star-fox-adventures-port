#pragma once

// Renderer GX para APK (Fase 10, GLES3; Fase 11: triangulos) —
// camino host verificado, portado sin cambiar su matematica.
//
// Parte independiente de GL (usable y testeable en host):
//   - GxDrawToGlQuads(): la misma transformada que el renderer host
//     de Fase 5b (test_gx_render.cpp): pos_matrix 3x4 del draw,
//     proyeccion orto [a,b,c,d,e,f] o perspectiva (w = -z, camino
//     NO validado: en run19 no habia draws de ese tipo),
//     viewport y region EFB (342,342). La unica diferencia es la
//     salida: coordenadas NDC de GLES (y hacia arriba) en vez de
//     pixeles de canvas (y hacia abajo).
//   - DecodeGxTexObj(): el mismo layout GXTexObj verificado en
//     host (texObj+8 dims/formato, +12 direccion de imagen,
//     +36 tamano base, imagen en texObj+64 en RAM huesped) y la
//     misma decodificacion de gamecube_runtime/gx_texture.h.
//     Devuelve false si el tamano base no coincide o el formato
//     es de paleta/desconocido: el llamador usa magenta, nunca
//     una textura inventada.
// Parte GLES3 (solo APK, necesita contexto EGL vigente):
//   - GxGlRenderer: programa de textura simple (sin TEV, sin
//     lighting, sin Rcp_*, sin EFB: todo eso es no-op
//     documentado, no un fallo silencioso). Solo QUADS (prim
//     0x80, 4 vertices, atributos directos, VAT con viewport y
//     proyeccion): cualquier otro draw se cuenta en
//     quads_skipped_ y no se dibuja.
//   - Texturas THP: el contenido de una textura decodificada
//     cambia en cada frame aunque su texObj sea el mismo, asi
//     que DrawDraws() vuelve a subir cada textura distinta en
//     cada llamada y borra las texturas GL al final del frame.
//     Es deliberadamente lento para una prueba; el cache por
//     hash de contenido queda para despues.
//   - Sin textura (tex_obj 0): color diagnostico (32,32,64),
//     igual que el renderer host. Textura sin resolver:
//     magenta 1x1, igual que el host.
//   - DrawCheckerQuad(): quad de prueba con una textura
//     procedural (damero, generada en codigo, NO arte del
//     juego) para validar el camino textura->GL sin datos del
//     disco. Es el paso "quad con textura" de la Fase 10; no
//     es un frame del juego.

#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

#include <GLES3/gl3.h>

#include "gamecube_runtime/gx.h"
#include "renderer/gx_translate.h"

namespace sfa {

class GxGlRenderer {
 public:
  // Resolver de texturas: dado un tex_obj huesped, devuelve su
  // RGBA decodificado. En la APK lee de la RAM del runtime.
  using TexResolver =
      std::function<bool(uint32_t tex_obj, GxDecodedTex* out)>;

  bool InitGl();
  void ShutdownGl();
  bool IsReady() const { return program_ != 0; }

  // Quad de prueba procedural (damero). Solo diagnostico.
  void DrawCheckerQuad();
  // Un quad a pantalla completa con una textura RGBA dada.
  void DrawTexturedQuad(const uint8_t* rgba, int width, int height);
  // Dibuja los draws GX traducibles de la lista. Devuelve el
  // numero de draws dibujados (QUADS, TRIANGLES, TRIANGLESTRIP
  // y TRIANGLEFAN via GxDrawToGlTris; LINES/POINTS, draws
  // indexados y opacos se cuentan en quads_skipped_).
  int DrawDraws(const std::vector<GxDraw>& draws,
                const TexResolver& resolver);

  int QuadsDrawn() const { return quads_drawn_; }
  int QuadsSkipped() const { return quads_skipped_; }
  int TrisDrawn() const { return tris_drawn_; }
  int TexturesUploaded() const { return textures_uploaded_; }
  const std::string& LastError() const { return last_error_; }

 private:
  GLuint UploadTexture(const uint8_t* rgba, int width, int height);
  void DrawQuadVertices(const GlQuad& q, GLuint tex, bool use_tex,
                        uint8_t r, uint8_t g, uint8_t b);
  void DrawTriVertices(const GlTri& tri, GLuint tex, bool use_tex,
                       uint8_t r, uint8_t g, uint8_t b);

  GLuint program_ = 0;
  GLuint vbo_ = 0;
  GLint loc_pos_ = -1;
  GLint loc_uv_ = -1;
  GLint loc_tex_ = -1;
  GLint loc_use_tex_ = -1;
  GLint loc_color_ = -1;
  GLuint checker_tex_ = 0;
  int quads_drawn_ = 0;
  int quads_skipped_ = 0;
  int tris_drawn_ = 0;
  int textures_uploaded_ = 0;
  std::string last_error_;
};

}  // namespace sfa
