#include "renderer/renderer.h"

#include <GLES3/gl3.h>

#include "input/audio_label.h"
#include "input/surround_label.h"
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

void Renderer::DrawAudioButton(AudioState state) {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return;
  // Fracciones -> NDC (y hacia arriba en GL): el rectangulo
  // tactil kAudioBtn* es el rectangulo dibujado, sin copias
  // de constantes. Borde oscuro ligeramente mayor + interior
  // de color segun estado (ver audio_button.h).
  auto to_ndc_x = [](float fx) { return 2.0f * fx - 1.0f; };
  auto to_ndc_y = [](float fy) { return 1.0f - 2.0f * fy; };
  const float x0 = to_ndc_x(sfa::kAudioBtnX0);
  const float x1 = to_ndc_x(sfa::kAudioBtnX1);
  // y0 es el borde SUPERIOR en pantalla (y menor) -> NDC mayor.
  const float y_top = to_ndc_y(sfa::kAudioBtnY0);
  const float y_bot = to_ndc_y(sfa::kAudioBtnY1);
  gx_gl_.DrawSolidQuad(x0 - 0.01f, y_top + 0.01f, x1 + 0.01f,
                       y_bot - 0.01f, 20, 20, 30);
  const bool blink_on = (audio_frame_ / 30) % 2 == 0;
  ++audio_frame_;
  const AudioButtonColor c = AudioButtonColorFor(state, blink_on);
  gx_gl_.DrawSolidQuad(x0, y_top, x1, y_bot, c.r, c.g, c.b);
  // Tramo 7: etiqueta bitmap DENTRO de la pildora, despues del
  // interior y antes del swap (mismo orden que el resto de la
  // pildora). Solo pintura: no crea zona tactil nueva ni cambia
  // la interceptacion de Input. Sin pantalla valida, o si la
  // pildora es demasiado pequena para escala 1, se omite la
  // etiqueta y la pildora queda como en el Tramo 6 (color solo).
  // La textura es opaca (fondo = color de la pildora), asi que
  // no necesita blending (el shader no lo activa).
  const int pill_w_px = AudioLabelPillPx(x1 - x0, width_);
  const int pill_h_px = AudioLabelPillPx(y_top - y_bot, height_);
  AudioLabelLayout label_layout;
  std::vector<uint8_t> label_rgba =
      RasterizeAudioLabel(state, blink_on, pill_w_px, pill_h_px,
                          &label_layout);
  if (!label_rgba.empty() && label_layout.ok) {
    const AudioLabelQuad q =
        AudioLabelQuadFor(width_, height_, x0, x1, y_top, y_bot,
                          label_layout.tex_w, label_layout.tex_h);
    if (q.ok) {
      gx_gl_.DrawTexturedQuadRect(label_rgba.data(), label_layout.tex_w,
                                  label_layout.tex_h, q.x0, q.y_top, q.x1,
                                  q.y_bot);
    }
  }
}

void Renderer::DrawSurroundButton(bool enabled) {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return;
  // Tramo 20: misma conversion fraccion->NDC que
  // DrawAudioButton y las mismas constantes de
  // surround_button.h (tactil y dibujo no se pueden
  // desalinear). Tramo 21: etiqueta bitmap DENTRO de la
  // pildora, despues del interior y antes del swap (mismo
  // orden que DrawAudioButton). Solo pintura: no crea zona
  // tactil nueva ni cambia la interceptacion de Input. Sin
  // pantalla valida, o si la pildora es demasiado pequena
  // para escala 1, se omite la etiqueta y la pildora queda
  // como en el Tramo 20 (color solo). La textura es opaca
  // (fondo = color de la pildora), asi que no necesita
  // blending (el shader no lo activa).
  auto to_ndc_x = [](float fx) { return 2.0f * fx - 1.0f; };
  auto to_ndc_y = [](float fy) { return 1.0f - 2.0f * fy; };
  const float x0 = to_ndc_x(sfa::kSurroundBtnX0);
  const float x1 = to_ndc_x(sfa::kSurroundBtnX1);
  const float y_top = to_ndc_y(sfa::kSurroundBtnY0);
  const float y_bot = to_ndc_y(sfa::kSurroundBtnY1);
  gx_gl_.DrawSolidQuad(x0 - 0.01f, y_top + 0.01f, x1 + 0.01f,
                       y_bot - 0.01f, 20, 20, 30);
  const SurroundButtonColor c = SurroundButtonColorFor(enabled);
  gx_gl_.DrawSolidQuad(x0, y_top, x1, y_bot, c.r, c.g, c.b);
  const int pill_w_px = AudioLabelPillPx(x1 - x0, width_);
  const int pill_h_px = AudioLabelPillPx(y_top - y_bot, height_);
  AudioLabelLayout label_layout;
  std::vector<uint8_t> label_rgba =
      RasterizeSurroundLabel(enabled, pill_w_px, pill_h_px, &label_layout);
  if (!label_rgba.empty() && label_layout.ok) {
    const AudioLabelQuad q =
        AudioLabelQuadFor(width_, height_, x0, x1, y_top, y_bot,
                          label_layout.tex_w, label_layout.tex_h);
    if (q.ok) {
      gx_gl_.DrawTexturedQuadRect(label_rgba.data(), label_layout.tex_w,
                                  label_layout.tex_h, q.x0, q.y_top, q.x1,
                                  q.y_bot);
    }
  }
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

bool Renderer::BeginEfbFrame(int width, int height) {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return false;
  if (!gx_gl_.BeginEfbTarget(width, height)) return false;
  glClearColor(0.05f, 0.10f, 0.25f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  return true;
}

std::pair<int, int> Renderer::CopyEfbCopies(
    const std::vector<GxCopy>& copies, uint8_t* ram, size_t ram_size) {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return {0, 0};
  int before_ok = gx_gl_.EfbCopiesOk();
  int before_rej = gx_gl_.EfbCopiesRejected();
  for (const GxCopy& c : copies) {
    std::string why;
    gx_gl_.CopyEfbToGuestRam(c, ram,
                             static_cast<uint32_t>(ram_size), &why);
  }
  return {gx_gl_.EfbCopiesOk() - before_ok,
          gx_gl_.EfbCopiesRejected() - before_rej};
}

bool Renderer::PresentEfb() {
  if (display_ == EGL_NO_DISPLAY || !gx_gl_ready_) return false;
  std::vector<uint8_t> rgba;
  int w = 0, h = 0;
  // ReadEfbRgba exige el FBO EFB enlazado: se lee ANTES de
  // EndEfbTarget (que enlaza el framebuffer 0).
  if (!gx_gl_.ReadEfbRgba(&rgba, &w, &h)) return false;
  gx_gl_.EndEfbTarget();
  glViewport(0, 0, width_, height_);
  gx_gl_.DrawTexturedQuad(rgba.data(), w, h);
  return true;
}

void Renderer::RenderFrame() {
  if (display_ == EGL_NO_DISPLAY) return;
  eglSwapBuffers(display_, surface_);
}

}  // namespace sfa
