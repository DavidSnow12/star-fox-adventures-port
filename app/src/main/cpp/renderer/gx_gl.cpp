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

// Vertex shader del camino TEV: la unica UV del formato de
// vertice actual se replica en vUv0..vUv7, asi que un programa
// TEV de 1 sampler muestrea bien sea cual sea su mapa (el
// mapa es el tex_map del draw, ver TevGlUsable). El color de
// vertice NO se entrega aqui: un programa TEV que lo pida no
// es usable y cae al programa fijo (GX-RESTO.md P0.3).
const char* kTevVertexShader =
    "attribute vec2 aPos;\n"
    "attribute vec2 aUv;\n"
    "varying vec2 vUv0;\n"
    "varying vec2 vUv1;\n"
    "varying vec2 vUv2;\n"
    "varying vec2 vUv3;\n"
    "varying vec2 vUv4;\n"
    "varying vec2 vUv5;\n"
    "varying vec2 vUv6;\n"
    "varying vec2 vUv7;\n"
    "void main() {\n"
    "  vUv0 = aUv;\n"
    "  vUv1 = aUv;\n"
    "  vUv2 = aUv;\n"
    "  vUv3 = aUv;\n"
    "  vUv4 = aUv;\n"
    "  vUv5 = aUv;\n"
    "  vUv6 = aUv;\n"
    "  vUv7 = aUv;\n"
    "  gl_Position = vec4(aPos, 0.0, 1.0);\n"
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
  for (auto& kv : tev_programs_) {
    if (kv.second.program != 0) glDeleteProgram(kv.second.program);
  }
  tev_programs_.clear();
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

void GxGlRenderer::DrawTriVertices(const GlTri& tri, GLuint tex,
                                   bool use_tex, uint8_t r, uint8_t g,
                                   uint8_t b) {
  float verts[3 * 4];
  for (int k = 0; k < 3; ++k) {
    verts[k * 4 + 0] = tri.x[k];
    verts[k * 4 + 1] = tri.y[k];
    verts[k * 4 + 2] = tri.s[k];
    verts[k * 4 + 3] = tri.t[k];
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
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(loc_pos_);
  glDisableVertexAttribArray(loc_uv_);
  ++tris_drawn_;
}

const GxGlRenderer::TevGlProgram* GxGlRenderer::GetOrCompileTevProgram(
    const TevGenResult& gen) {
  auto it = tev_programs_.find(gen.hash);
  if (it != tev_programs_.end()) return &it->second;
  GLuint vs = CompileShader(GL_VERTEX_SHADER, kTevVertexShader);
  if (vs == 0) return nullptr;
  GLuint fs = CompileShader(GL_FRAGMENT_SHADER, gen.fragment.c_str());
  if (fs == 0) {
    glDeleteShader(vs);
    if (!tev_compile_failed_logged_) {
      tev_compile_failed_logged_ = true;
      SFA_LOGE("gx_gl: TEV fragment fallo (hash 0x%08X): cae al "
               "programa fijo",
               gen.hash);
    }
    return nullptr;
  }
  GLuint prog = glCreateProgram();
  glAttachShader(prog, vs);
  glAttachShader(prog, fs);
  glLinkProgram(prog);
  glDeleteShader(vs);
  glDeleteShader(fs);
  GLint ok = 0;
  glGetProgramiv(prog, GL_LINK_STATUS, &ok);
  if (ok == 0) {
    char buf[512];
    glGetProgramInfoLog(prog, sizeof(buf), nullptr, buf);
    if (!tev_compile_failed_logged_) {
      tev_compile_failed_logged_ = true;
      SFA_LOGE("gx_gl: TEV link fallo (hash 0x%08X): %s", gen.hash, buf);
    }
    glDeleteProgram(prog);
    return nullptr;
  }
  TevGlProgram tp;
  tp.program = prog;
  tp.loc_pos = glGetAttribLocation(prog, "aPos");
  tp.loc_uv = glGetAttribLocation(prog, "aUv");
  for (int m = 0; m < 8; ++m) {
    tp.loc_tex[m] = glGetUniformLocation(
        prog, ("uTex" + std::to_string(m)).c_str());
  }
  for (int i = 0; i < 3; ++i) {
    tp.loc_regc[i] = glGetUniformLocation(
        prog, ("uRegC" + std::to_string(i)).c_str());
    tp.loc_rega[i] = glGetUniformLocation(
        prog, ("uRegA" + std::to_string(i)).c_str());
  }
  for (int i = 0; i < 4; ++i) {
    tp.loc_konst[i] = glGetUniformLocation(
        prog, ("uKonst" + std::to_string(i)).c_str());
  }
  ++tev_programs_compiled_;
  auto inserted = tev_programs_.emplace(gen.hash, tp);
  return &inserted.first->second;
}

void GxGlRenderer::DrawTriVerticesTev(const GlTri& tri, GLuint tex,
                                      bool use_tex,
                                      const TevGlProgram& tp,
                                      const TevState& tev) {
  float verts[3 * 4];
  for (int k = 0; k < 3; ++k) {
    verts[k * 4 + 0] = tri.x[k];
    verts[k * 4 + 1] = tri.y[k];
    verts[k * 4 + 2] = tri.s[k];
    verts[k * 4 + 3] = tri.t[k];
  }
  glUseProgram(tp.program);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STREAM_DRAW);
  glEnableVertexAttribArray(tp.loc_pos);
  glVertexAttribPointer(tp.loc_pos, 2, GL_FLOAT, GL_FALSE,
                        4 * sizeof(float),
                        reinterpret_cast<const void*>(0));
  glEnableVertexAttribArray(tp.loc_uv);
  glVertexAttribPointer(tp.loc_uv, 2, GL_FLOAT, GL_FALSE,
                        4 * sizeof(float),
                        reinterpret_cast<const void*>(2 * sizeof(float)));
  // Uniforms TEV: registros y konstantes del snapshot (el
  // snapshot sin anclar los deja a 0; un TevState construido
  // a mano los trae explicitos). glUniform con loc -1 (uniform
  // optimizado fuera) se ignora en silencio: seguro.
  for (int i = 0; i < 3; ++i) {
    glUniform3f(tp.loc_regc[i], tev.regcolor[i][0], tev.regcolor[i][1],
                tev.regcolor[i][2]);
    glUniform1f(tp.loc_rega[i], tev.regcolor[i][3]);
  }
  for (int i = 0; i < 4; ++i) {
    glUniform4f(tp.loc_konst[i], tev.konst[i][0], tev.konst[i][1],
                tev.konst[i][2], tev.konst[i][3]);
  }
  if (use_tex) {
    // Camino usable = como mucho 1 sampler: la unidad 0.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    for (int m = 0; m < 8; ++m) {
      if (tp.loc_tex[m] >= 0) glUniform1i(tp.loc_tex[m], 0);
    }
  }
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(tp.loc_pos);
  glDisableVertexAttribArray(tp.loc_uv);
  ++tris_drawn_;
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
    std::vector<GlTri> tris;
    if (!GxDrawToGlTris(d, 640, 480, &tris)) {
      ++quads_skipped_;
      continue;
    }
    // La textura es por draw (no por triangulo): se resuelve
    // una vez y se reutiliza en sus tris.
    uint32_t tex_obj = tris.empty() ? 0 : tris[0].tex_obj;
    GLuint tex = 0;
    bool use_tex = false;
    if (tex_obj == 0) {
      use_tex = false;
    } else {
      auto it = frame_tex.find(tex_obj);
      if (it != frame_tex.end()) {
        tex = it->second;
        use_tex = true;
      } else {
        GxDecodedTex dec;
        bool ok = resolver != nullptr && resolver(tex_obj, &dec) && dec.ok;
        if (ok) {
          tex = UploadTexture(dec.rgba.data(), dec.width, dec.height);
        } else {
          if (magenta == 0) {
            uint8_t px[4] = {255, 0, 255, 255};
            magenta = UploadTexture(px, 1, 1);
          }
          tex = magenta;
        }
        use_tex = true;
        frame_tex[tex_obj] = tex;
      }
    }
    // Camino TEV fase A: si el draw trae snapshot, su programa
    // se genera por hash (contado) y se usa solo si es
    // resoluble con el formato actual; si no, cae al programa
    // fijo anterior (tev_fallback_), nunca crash. Sin snapshot
    // (has_tev=false) no se tocan los contadores TEV.
    if (d.has_tev) {
      ++tev_draws_;
      TevGenResult gen;
      tev_cache_.Get(d.tev, &gen);
      tev_stages_total_ += gen.stages_processed;
      tev_indirect_noop_ += gen.indirect_noop;
      tev_unsupported_ += gen.unsupported;
      const TevGlProgram* tp = nullptr;
      // Con sampler pero sin textura (tex_obj 0): no dibujar
      // con un sampler sin enlazar (negro en GL); caer al
      // camino fijo, que usa el color diagnostico.
      if (TevGlUsable(gen, d) &&
          (gen.sampler_maps.empty() || use_tex))
        tp = GetOrCompileTevProgram(gen);
      if (tp != nullptr) {
        for (const GlTri& tri : tris) {
          DrawTriVerticesTev(tri, tex, use_tex, *tp, d.tev);
        }
        ++drawn;
        ++quads_drawn_;
        continue;
      }
      ++tev_fallback_;
    }
    for (const GlTri& tri : tris) {
      if (use_tex) {
        DrawTriVertices(tri, tex, true, 0, 0, 0);
      } else {
        DrawTriVertices(tri, 0, false, 32, 32, 64);
      }
    }
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
