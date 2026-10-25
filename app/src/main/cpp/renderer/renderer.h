#pragma once

// Renderer — STUB GLES3 de la base.
//
// Solo inicializa EGL con la ventana nativa, limpia la pantalla con
// un color fijo y hace swap. El GX real de GameCube (display lists,
// TEV, texturas CMPR/RGB5A3/RGBA8 ya extraídas, etc.) es trabajo
// posterior; este stub existe para validar la superficie, el loop
// y el enlace con EGL/GLES3 antes de tocar GX.

#include <EGL/egl.h>
#include <android/native_window.h>

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
  void RenderFrame();

  bool IsReady() const { return display_ != EGL_NO_DISPLAY; }

 private:
  EGLDisplay display_ = EGL_NO_DISPLAY;
  EGLSurface surface_ = EGL_NO_SURFACE;
  EGLContext context_ = EGL_NO_CONTEXT;
  int width_ = 0;
  int height_ = 0;
};

}  // namespace sfa
