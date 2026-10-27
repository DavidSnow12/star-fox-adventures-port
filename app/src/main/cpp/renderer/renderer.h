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

#include <utility>
#include <vector>

#include "gamecube_runtime/gx.h"
#include "input/audio_button.h"
#include "input/surround_button.h"
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
  // Tramo 20: pildora "surround" (color segun enabled, sin
  // etiqueta bitmap todavia). Se dibuja DESPUES de la de
  // audio y ANTES del swap: queda por encima del juego a
  // proposito (es UI, no arte). Sin contexto GX listo es
  // no-op, igual que DrawAudioButton.
  void DrawSurroundButton(bool enabled);
  // Fase 10: draws GX (parser host) con texturas decodificadas
  // desde la RAM huesped dada. Sin draws, no dibuja nada.
  int DrawGxFrame(const std::vector<GxDraw>& draws, const uint8_t* ram,
                  size_t ram_size);
  // Tramo 10: camino EFB (ver DIFF Tramo 10). Renderizar UNA
  // vez al target EFB y presentar con el quad texturado
  // existente (sin dibujar dos veces y sin inventar un blit):
  //   BeginEfbFrame(640,480) -> DrawGxFrame (al FBO) ->
  //   CopyEfbCopies (readback + escrituras en RAM) ->
  //   PresentEfb (readback + End + viewport + quad) ->
  //   DrawAudioButton -> RenderFrame.
  // Tramo 11: DrawGxFrame y CopyEfbCopies se llaman POR
  // SEGMENTOS entrelazados por fifo_offset (ver
  // gamecube_runtime/gx_merge.h y Frame()): una copia a
  // textura del frame ya alimenta a los draws posteriores
  // del mismo frame. Sin copias, un unico segmento de draws
  // (orden identico al Tramo 10); con copias todas tras los
  // draws (caso observado), el orden es el antiguo exacto.
  // BeginEfbFrame enlaza el FBO (o lo recrea si cambia el
  // tamano) y hace clear con el mismo color que BeginFrame.
  // Devuelve false si el FBO no se pudo crear: el llamador
  // debe usar el camino de pantalla de siempre (DrawGxFrame
  // sin EFB) para no perder el frame. CopyEfbCopies ejecuta
  // las copias que recibe en orden FIFO y devuelve (ok,
  // rechazadas); el motivo de la ultima rechazada queda en
  // EfbLastReject(). Tramo 11: Frame() la llama POR
  // SEGMENTOS entrelazados con los draws (ver gx_merge.h):
  // las copias a textura quedan disponibles para los draws
  // posteriores DEL MISMO frame (antes, solo para el frame
  // siguiente); las copias XFB son de fin de frame y no se
  // ven afectadas. PresentEfb lee el EFB (cache del
  // frame), restaura el framebuffer 0 y el viewport de
  // pantalla, y dibuja el EFB a pantalla completa con el
  // quad texturado existente (filtro LINEAR de
  // UploadTexture: la presentacion suaviza ligeramente
  // frente al estirado por viewport del camino directo;
  // alternativa futura, NO en este parche: glBlitFramebuffer
  // con NEAREST, que el coordinador puede aprobar aparte).
  // Sin contexto EGL o sin gx listo, los tres son no-op
  // seguros (BeginEfbFrame false, CopyEfbCopies (0,0),
  // PresentEfb false).
  bool BeginEfbFrame(int width, int height);
  std::pair<int, int> CopyEfbCopies(const std::vector<GxCopy>& copies,
                                    uint8_t* ram, size_t ram_size);
  bool PresentEfb();
  int EfbCopiesOk() const { return gx_gl_.EfbCopiesOk(); }
  int EfbCopiesRejected() const { return gx_gl_.EfbCopiesRejected(); }
  const std::string& EfbLastReject() const {
    return gx_gl_.EfbLastReject();
  }
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
