#pragma once

// Renderer — EGL/GLES3 + GX (Fase 10).
//
// Clear + quad de prueba + draws GX traducibles (ver
// renderer/gx_gl.h): TEV multi-etapa, Rcp_*, EFB y display lists
// complejas son no-op documentados, no un fallo silencioso.
// Sin draws GX pendientes, RenderFrame solo hace clear; el
// llamador dibuja antes (quad de prueba o draws GX).

#include <EGL/egl.h>
#include <android/native_window.h>

#include <vector>

#include "gamecube_runtime/gx.h"
#include "input/audio_button.h"
#include "renderer/gx_gl.h"

namespace sfa {

class Renderer {
 public:
  bool Init(ANativeWindow* window);
  void Shutdown();
  void Resize(int width, int height);
  // Quad de prueba (aportación de la IA de GitHub, integrada como
  // stub): la primera imagen útil del runtime será clear + quad,
  // antes de cualquier GX real. En esta base solo registra una vez.
  void DrawQuad();
  // Fase 10: quad de prueba con textura procedural (damero,
  // GxGlRenderer::DrawCheckerQuad). No es arte del juego.
  void DrawTestQuad();
  // Tramo 6: pildora "anadir audio" (color segun AudioState,
  // parpadeo en Verifying). Se dibuja DESPUES de los draws GX
  // y del damero, ANTES del swap: queda por encima del juego
  // a proposito (es UI, no arte). Sin contexto GX listo es
  // no-op, igual que DrawTestQuad. Las fracciones tactiles
  // y el rectangulo dibujado son las mismas constantes de
  // audio_button.h: tactil y dibujo no se pueden desalinear.
  void DrawAudioButton(AudioState state);
  // Fase 10: draws GX (parser host) con texturas decodificadas
  // desde la RAM huesped dada. Sin draws, no dibuja nada.
  int DrawGxFrame(const std::vector<GxDraw>& draws, const uint8_t* ram,
                  size_t ram_size);
  // Orden de frame: BeginFrame (clear) -> DrawTestQuad o
  // DrawGxFrame -> RenderFrame (swap). Sin BeginFrame, el
  // contenido del frame anterior persistiria.
  void BeginFrame();
  int GxQuadsDrawn() const { return gx_gl_.QuadsDrawn(); }
  int GxQuadsSkipped() const { return gx_gl_.QuadsSkipped(); }
  int GxTexturesUploaded() const { return gx_gl_.TexturesUploaded(); }
  bool GxReady() const { return gx_gl_ready_; }
  void RenderFrame();

  bool IsReady() const { return display_ != EGL_NO_DISPLAY; }

 private:
  EGLDisplay display_ = EGL_NO_DISPLAY;
  EGLSurface surface_ = EGL_NO_SURFACE;
  EGLContext context_ = EGL_NO_CONTEXT;
  int width_ = 0;
  int height_ = 0;
  GxGlRenderer gx_gl_;
  bool gx_gl_ready_ = false;
  int audio_frame_ = 0;  // Tramo 6: parpadeo Verifying (30 f on/off)
};

}  // namespace sfa
