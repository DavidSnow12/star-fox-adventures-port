#include "renderer/gx_gl.h"

#include "log.h"

namespace sfa {

namespace {

const char* kVertexShader =
    "attribute vec2 aPos;\n"
    "attribute vec2 aUv;\n"
    "varying vec2 vUv;\n"
    "void main() {\n"
    "  vUv = aUv;\n"
    "  gl_Position = vec4(aPos, 0.0, 1.0);\n"
    "}\n";

const char* kFragmentShader =
    "precision mediump float;\n"
    "uniform sampler2D uTex;\n"
    "uniform int uUseTex;\n"
    "uniform vec4 uColor;\n"
    "varying vec2 vUv;\n"
    "void main() {\n"
    "  if (uUseTex != 0) {\n"
    "    gl_FragColor = texture2D(uTex, vUv);\n"
    "  } else {\n"
    "    gl_FragColor = uColor;\n"
    "  }\n"
    "}\n";

GLuint CompileShader(GLenum type, const char* src) {
  GLuint sh = glCreateShader(type);
  glShaderSource(sh, 1, &src, nullptr);
  glCompileShader(sh);
  GLint ok = 0;
  glGetShaderiv(sh, GL_COMPILE_STATUS, &ok);
  if (ok == 0) {
    char buf[512];
    glGetShaderInfoLog(sh, sizeof(buf), nullptr, buf);
    SFA_LOGE("gx_gl: shader fallo: %s", buf);
    glDeleteShader(sh);
    return 0;
  }
  return sh;
}

}  // namespace

bool GxGlRenderer::InitGl() {
  if (program_ != 0) return true;
  GLuint vs = CompileShader(GL_VERTEX_SHADER, kVertexShader);
  if (vs == 0) return false;
  GLuint fs = CompileShader(GL_FRAGMENT_SHADER, kFragmentShader);
  if (fs == 0) {
    glDeleteShader(vs);
    return false;
  }
  program_ = glCreateProgram();
  glAttachShader(program_, vs);
  glAttachShader(program_, fs);
  glLinkProgram(program_);
  glDeleteShader(vs);
  glDeleteShader(fs);
  GLint ok = 0;
  glGetProgramiv(program_, GL_LINK_STATUS, &ok);
  if (ok == 0) {
    char buf[512];
    glGetProgramInfoLog(program_, sizeof(buf), nullptr, buf);
    SFA_LOGE("gx_gl: link fallo: %s", buf);
    glDeleteProgram(program_);
    program_ = 0;
    return false;
  }
  loc_pos_ = glGetAttribLocation(program_, "aPos");
  loc_uv_ = glGetAttribLocation(program_, "aUv");
  loc_tex_ = glGetUniformLocation(program_, "uTex");
  loc_use_tex_ = glGetUniformLocation(program_, "uUseTex");
  loc_color_ = glGetUniformLocation(program_, "uColor");
  glGenBuffers(1, &vbo_);
  glUseProgram(program_);
  glUniform1i(loc_tex_, 0);
  return true;
}

void GxGlRenderer::ShutdownGl() {
  if (checker_tex_ != 0) glDeleteTextures(1, &checker_tex_);
  checker_tex_ = 0;
  if (vbo_ != 0) glDeleteBuffers(1, &vbo_);
  vbo_ = 0;
  if (program_ != 0) glDeleteProgram(program_);
  program_ = 0;
}

GLuint GxGlRenderer::UploadTexture(const uint8_t* rgba, int width,
                                   int height) {
  GLuint tex = 0;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, rgba);
  ++textures_uploaded_;
  return tex;
}

void GxGlRenderer::DrawQuadVertices(const GlQuad& q, GLuint tex,
                                    bool use_tex, uint8_t r, uint8_t g,
                                    uint8_t b) {
  // Triangulos (0,1,2) y (0,2,3), como el host. UV sin volteo:
  // el host muestrea la fila ct*(h-1) con ct = t, y al subir
  // la textura con glTexImage2D la primera fila en memoria
  // queda en v=0, asi que v = t reproduce exactamente el
  // muestreo host. Si los logos salen invertidos en
  // dispositivo, el flip va aqui (y se vera en la prueba).
  const int idx[6] = {0, 1, 2, 0, 2, 3};
  float verts[6 * 4];
  for (int k = 0; k < 6; ++k) {
    int i = idx[k];
    verts[k * 4 + 0] = q.x[i];
    verts[k * 4 + 1] = q.y[i];
    verts[k * 4 + 2] = q.s[i];
    verts[k * 4 + 3] = q.t[i];
  }
  glUseProgram(program_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STREAM_DRAW);
  glEnableVertexAttribArray(loc_pos_);
  glVertexAttribPointer(loc_pos_, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                        reinterpret_cast<const void*>(0));
  glEnableVertexAttribArray(loc_uv_);
  glVertexAttribPointer(loc_uv_, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                        reinterpret_cast<const void*>(2 * sizeof(float)));
  if (use_tex) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(loc_use_tex_, 1);
  } else {
    glUniform1i(loc_use_tex_, 0);
    glUniform4f(loc_color_, r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
  }
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glDisableVertexAttribArray(loc_pos_);
  glDisableVertexAttribArray(loc_uv_);
}

void GxGlRenderer::DrawCheckerQuad() {
  if (program_ == 0) return;
  if (checker_tex_ == 0) {
    // Damero 64x64 procedural (blanco/gris oscuro), solo
    // diagnostico: no es arte del juego.
    std::vector<uint8_t> rgba(64 * 64 * 4);
    for (int y = 0; y < 64; ++y) {
      for (int x = 0; x < 64; ++x) {
        bool on = ((x / 8) + (y / 8)) % 2 == 0;
        size_t o = (static_cast<size_t>(y) * 64 + x) * 4;
        rgba[o] = on ? 255 : 64;
        rgba[o + 1] = on ? 255 : 64;
        rgba[o + 2] = on ? 255 : 64;
        rgba[o + 3] = 255;
      }
    }
    checker_tex_ = UploadTexture(rgba.data(), 64, 64);
  }
  GlQuad q;
  q.x[0] = -0.8f; q.y[0] = 0.8f; q.s[0] = 0; q.t[0] = 0;
  q.x[1] = 0.8f;  q.y[1] = 0.8f; q.s[1] = 1; q.t[1] = 0;
  q.x[2] = 0.8f;  q.y[2] = -0.8f; q.s[2] = 1; q.t[2] = 1;
  q.x[3] = -0.8f; q.y[3] = -0.8f; q.s[3] = 0; q.t[3] = 1;
  // El damero es simetrico: este quad no valida orientacion;
  // la orientacion la validan los draws GX (v = t, ver arriba).
  DrawQuadVertices(q, checker_tex_, true, 0, 0, 0);
  ++quads_drawn_;
}

void GxGlRenderer::DrawTexturedQuad(const uint8_t* rgba, int width,
                                    int height) {
  if (program_ == 0 || rgba == nullptr || width <= 0 || height <= 0) {
    return;
  }
  GLuint tex = UploadTexture(rgba, width, height);
  GlQuad q;
  q.x[0] = -1; q.y[0] = 1; q.s[0] = 0; q.t[0] = 0;
  q.x[1] = 1;  q.y[1] = 1; q.s[1] = 1; q.t[1] = 0;
  q.x[2] = 1;  q.y[2] = -1; q.s[2] = 1; q.t[2] = 1;
  q.x[3] = -1; q.y[3] = -1; q.s[3] = 0; q.t[3] = 1;
  DrawQuadVertices(q, tex, true, 0, 0, 0);
  glDeleteTextures(1, &tex);
  ++quads_drawn_;
}

int GxGlRenderer::DrawDraws(const std::vector<GxDraw>& draws,
                            const TexResolver& resolver) {
  if (program_ == 0) return 0;
  // Cache por frame: tex_obj -> textura GL (se borra al final,
  // para que una textura THP reutilizada no quede obsoleta).
  std::map<uint32_t, GLuint> frame_tex;
  GLuint magenta = 0;
  int drawn = 0;
  for (const GxDraw& d : draws) {
    GlQuad q;
    if (!GxDrawToGlQuads(d, 640, 480, &q)) {
      ++quads_skipped_;
      continue;
    }
    if (q.tex_obj == 0) {
      DrawQuadVertices(q, 0, false, 32, 32, 64);
      ++drawn;
      ++quads_drawn_;
      continue;
    }
    GLuint tex = 0;
    auto it = frame_tex.find(q.tex_obj);
    if (it != frame_tex.end()) {
      tex = it->second;
    } else {
      GxDecodedTex dec;
      bool ok = resolver != nullptr && resolver(q.tex_obj, &dec) && dec.ok;
      if (ok) {
        tex = UploadTexture(dec.rgba.data(), dec.width, dec.height);
      } else {
        if (magenta == 0) {
          uint8_t px[4] = {255, 0, 255, 255};
          magenta = UploadTexture(px, 1, 1);
        }
        tex = magenta;
      }
      frame_tex[q.tex_obj] = tex;
    }
    DrawQuadVertices(q, tex, true, 0, 0, 0);
    ++drawn;
    ++quads_drawn_;
  }
  // Borrar cada textura GL una sola vez: varios tex_objs sin
  // resolver comparten la misma magenta, y borrarla dos veces
  // seria confuso aunque GL lo ignore.
  {
    std::map<GLuint, bool> seen;
    for (auto& kv : frame_tex) {
      if (!seen[kv.second]) {
        seen[kv.second] = true;
        glDeleteTextures(1, &kv.second);
      }
    }
  }
  return drawn;
}

}  // namespace sfa
