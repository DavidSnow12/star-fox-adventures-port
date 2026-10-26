#include "renderer/renderer.h"

#include <GLES3/gl3.h>

#include "log.h"

namespace sfa {

bool Renderer::Init(ANativeWindow* window) {
  if (window == nullptr) return false;
  display_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
  if (display_ == EGL_NO_DISPLAY) {
    SFA_LOGE("renderer: eglGetDisplay fallo");
    return false;
  }
  if (!eglInitialize(display_, nullptr, nullptr)) {
    SFA_LOGE("renderer: eglInitialize fallo");
    return false;
  }
  const EGLint attribs[] = {EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
                            EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8,
                            EGL_RED_SIZE, 8, EGL_DEPTH_SIZE, 16,
                            EGL_NONE};
  EGLConfig config = nullptr;
  EGLint num_configs = 0;
  if (!eglChooseConfig(display_, attribs, &config, 1, &num_configs) ||
      num_configs < 1) {
    SFA_LOGE("renderer: eglChooseConfig fallo");
    return false;
  }
  const EGLint ctx_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
  context_ = eglCreateContext(display_, config, EGL_NO_CONTEXT, ctx_attribs);
  if (context_ == EGL_NO_CONTEXT) {
    SFA_LOGE("renderer: eglCreateContext fallo");
    return false;
  }
  surface_ = eglCreateWindowSurface(display_, config, window, nullptr);
  if (surface_ == EGL_NO_SURFACE) {
    SFA_LOGE("renderer: eglCreateWindowSurface fallo");
    return false;
  }
  if (!eglMakeCurrent(display_, surface_, surface_, context_)) {
    SFA_LOGE("renderer: eglMakeCurrent fallo");
    return false;
  }
  eglQuerySurface(display_, surface_, EGL_WIDTH, &width_);
  eglQuerySurface(display_, surface_, EGL_HEIGHT, &height_);
  glViewport(0, 0, width_, height_);
  // Fase 10: programa GX tras el contexto vigente. Si falla, el
  // renderer sigue haciendo clear (el fallo queda en log).
  gx_gl_ready_ = gx_gl_.InitGl();
  SFA_LOGI("renderer: EGL/GLES3 listo, %dx%d, gx_gl=%d", width_, height_,
           gx_gl_ready_ ? 1 : 0);
  return true;
}

void Renderer::Shutdown() {
  gx_gl_.ShutdownGl();
  gx_gl_ready_ = false;
  if (display_ != EGL_NO_DISPLAY) {
    eglMakeCurrent(display_, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    if (surface_ != EGL_NO_SURFACE) eglDestroySurface(display_, surface_);
    if (context_ != EGL_NO_CONTEXT) eglDestroyContext(display_, context_);
    eglTerminate(display_);
  }
  display_ = EGL_NO_DISPLAY;
  surface_ = EGL_NO_SURFACE;
  context_ = EGL_NO_CONTEXT;
}

void Renderer::Resize(int width, int height) {
  width_ = width;
  height_ = height;
  if (display_ != EGL_NO_DISPLAY) glViewport(0, 0, width_, height_);
}

void Renderer::DrawQuad() {
  static bool logged = false;
  if (!logged) {
    logged = true;
    SFA_LOGI("renderer: DrawQuad stub (sin geometria GX todavia)");
  }
}

void Renderer::DrawTestQuad() {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return;
  gx_gl_.DrawCheckerQuad();
}

int Renderer::DrawGxFrame(const std::vector<GxDraw>& draws,
                          const uint8_t* ram, size_t ram_size) {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return 0;
  return gx_gl_.DrawDraws(
      draws, [ram, ram_size](uint32_t tex_obj, GxDecodedTex* out) {
        return DecodeGxTexObj(ram, ram_size, tex_obj, out);
      });
}

void Renderer::BeginFrame() {
  if (display_ == EGL_NO_DISPLAY) return;
  glClearColor(0.05f, 0.10f, 0.25f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderFrame() {
  if (display_ == EGL_NO_DISPLAY) return;
  eglSwapBuffers(display_, surface_);
}

}  // namespace sfa
