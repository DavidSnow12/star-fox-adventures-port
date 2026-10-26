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

// Vertex shader del camino TEV (Tramo 5): 26 floats por
// vertice (pos 2 + 4 UV empaquetadas + color0 4 + color1 4).
// Las 8 UV y los 2 colores se entregan SIEMPRE (el fragment
// generado declara los 6 varyings siempre; un varying de FS
// no escrito en VS no enlaza). El fragment usa
// vUv<texcoord> con el sampler uTex<texmap>.
const char* kTevVertexShader =
    "attribute vec2 aPos;\n"
    "attribute vec4 aUv01;\n"
    "attribute vec4 aUv23;\n"
    "attribute vec4 aUv45;\n"
    "attribute vec4 aUv67;\n"
    "attribute vec4 aColor0;\n"
    "attribute vec4 aColor1;\n"
    "varying vec4 vUv01;\n"
    "varying vec4 vUv23;\n"
    "varying vec4 vUv45;\n"
    "varying vec4 vUv67;\n"
    "varying vec4 vColor;\n"
    "varying vec4 vColor1;\n"
    "void main() {\n"
    "  vUv01 = aUv01;\n"
    "  vUv23 = aUv23;\n"
    "  vUv45 = aUv45;\n"
    "  vUv67 = aUv67;\n"
    "  vColor = aColor0;\n"
    "  vColor1 = aColor1;\n"
    "  gl_Position = vec4(aPos, 0.0, 1.0);\n"
    "}\n";

// Factor de blend BP (0-7) -> GL. Sin equivalente para
// valores fuera de enum: se trata como ONE (no crash).
GLenum BlendFactorGl(int f) {
  switch (f) {
    case 0: return GL_ZERO;
    case 1: return GL_ONE;
    case 2: return GL_SRC_COLOR;
    case 3: return GL_ONE_MINUS_SRC_COLOR;
    case 4: return GL_SRC_ALPHA;
    case 5: return GL_ONE_MINUS_SRC_ALPHA;
    case 6: return GL_DST_ALPHA;
    case 7: return GL_ONE_MINUS_DST_ALPHA;
    default: return GL_ONE;
  }
}

// Funcion de comparacion BP (0-7) -> GL (Z y alpha-test
// comparten el enum).
GLenum CompareFuncGl(int f) {
  switch (f) {
    case 0: return GL_NEVER;
    case 1: return GL_LESS;
    case 2: return GL_EQUAL;
    case 3: return GL_LEQUAL;
    case 4: return GL_GREATER;
    case 5: return GL_NOTEQUAL;
    case 6: return GL_GEQUAL;
    default: return GL_ALWAYS;
  }
}

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

void GxGlRenderer::DrawSolidQuad(float x0, float y_top, float x1,
                                  float y_bot, uint8_t r, uint8_t g,
                                  uint8_t b) {
  if (program_ == 0) return;
  GlQuad q;
  q.x[0] = x0; q.y[0] = y_top; q.s[0] = 0; q.t[0] = 0;
  q.x[1] = x1; q.y[1] = y_top; q.s[1] = 1; q.t[1] = 0;
  q.x[2] = x1; q.y[2] = y_bot; q.s[2] = 1; q.t[2] = 1;
  q.x[3] = x0; q.y[3] = y_bot; q.s[3] = 0; q.t[3] = 1;
  DrawQuadVertices(q, 0, false, r, g, b);
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
  std::pair<uint32_t, int> key(gen.hash, gen.alpha_test_mode);
  auto it = tev_programs_.find(key);
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
  tp.loc_uv01 = glGetAttribLocation(prog, "aUv01");
  tp.loc_uv23 = glGetAttribLocation(prog, "aUv23");
  tp.loc_uv45 = glGetAttribLocation(prog, "aUv45");
  tp.loc_uv67 = glGetAttribLocation(prog, "aUv67");
  tp.loc_color0 = glGetAttribLocation(prog, "aColor0");
  tp.loc_color1 = glGetAttribLocation(prog, "aColor1");
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
  tp.loc_alpha_ref0 = glGetUniformLocation(prog, "uAlphaRef0");
  tp.loc_alpha_ref1 = glGetUniformLocation(prog, "uAlphaRef1");
  ++tev_programs_compiled_;
  auto inserted = tev_programs_.emplace(key, tp);
  return &inserted.first->second;
}

void GxGlRenderer::DrawTriVerticesTev(const GlTri& tri,
                                      const GLuint tex_by_map[8],
                                      const TevGlProgram& tp,
                                      const TevState& tev,
                                      const GxFixedState& fixed) {
  // 26 floats por vertice: pos(2) + uv01/23/45/67 (16) +
  // color0(4) + color1(4).
  float verts[3 * 26];
  for (int k = 0; k < 3; ++k) {
    float* v = verts + k * 26;
    v[0] = tri.x[k];
    v[1] = tri.y[k];
    v[2] = tri.uv_s[k][0];
    v[3] = tri.uv_t[k][0];
    v[4] = tri.uv_s[k][1];
    v[5] = tri.uv_t[k][1];
    v[6] = tri.uv_s[k][2];
    v[7] = tri.uv_t[k][2];
    v[8] = tri.uv_s[k][3];
    v[9] = tri.uv_t[k][3];
    v[10] = tri.uv_s[k][4];
    v[11] = tri.uv_t[k][4];
    v[12] = tri.uv_s[k][5];
    v[13] = tri.uv_t[k][5];
    v[14] = tri.uv_s[k][6];
    v[15] = tri.uv_t[k][6];
    v[16] = tri.uv_s[k][7];
    v[17] = tri.uv_t[k][7];
    v[18] = tri.cr0[k];
    v[19] = tri.cg0[k];
    v[20] = tri.cb0[k];
    v[21] = tri.ca0[k];
    v[22] = tri.cr1[k];
    v[23] = tri.cg1[k];
    v[24] = tri.cb1[k];
    v[25] = tri.ca1[k];
  }
  glUseProgram(tp.program);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STREAM_DRAW);
  auto set_attr = [&](GLint loc, int size, size_t off) {
    if (loc < 0) return;
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, size, GL_FLOAT, GL_FALSE,
                          26 * sizeof(float),
                          reinterpret_cast<const void*>(off));
  };
  set_attr(tp.loc_pos, 2, 0);
  set_attr(tp.loc_uv01, 4, 2 * sizeof(float));
  set_attr(tp.loc_uv23, 4, 6 * sizeof(float));
  set_attr(tp.loc_uv45, 4, 10 * sizeof(float));
  set_attr(tp.loc_uv67, 4, 14 * sizeof(float));
  set_attr(tp.loc_color0, 4, 18 * sizeof(float));
  set_attr(tp.loc_color1, 4, 22 * sizeof(float));
  // Uniforms TEV: registros y konstantes del snapshot.
  // glUniform con loc -1 (uniform optimizado fuera) se
  // ignora en silencio: seguro.
  for (int i = 0; i < 3; ++i) {
    glUniform3f(tp.loc_regc[i], tev.regcolor[i][0], tev.regcolor[i][1],
                tev.regcolor[i][2]);
    glUniform1f(tp.loc_rega[i], tev.regcolor[i][3]);
  }
  for (int i = 0; i < 4; ++i) {
    glUniform4f(tp.loc_konst[i], tev.konst[i][0], tev.konst[i][1],
                tev.konst[i][2], tev.konst[i][3]);
  }
  // Refs alpha-test (solo si el programa las declara).
  if (fixed.alpha.present) {
    glUniform1f(tp.loc_alpha_ref0, fixed.alpha.ref0 / 255.0f);
    glUniform1f(tp.loc_alpha_ref1, fixed.alpha.ref1 / 255.0f);
  }
  // Samplers: unidad = mapa (DrawDraws pone magenta donde
  // no hay carga o no se resolvio, asi ninguna unidad queda
  // con una textura obsoleta de otro draw).
  for (int m = 0; m < 8; ++m) {
    glActiveTexture(GL_TEXTURE0 + m);
    glBindTexture(GL_TEXTURE_2D, tex_by_map[m]);
    if (tp.loc_tex[m] >= 0) glUniform1i(tp.loc_tex[m], m);
  }
  glDrawArrays(GL_TRIANGLES, 0, 3);
  auto unset_attr = [&](GLint loc) {
    if (loc >= 0) glDisableVertexAttribArray(loc);
  };
  unset_attr(tp.loc_pos);
  unset_attr(tp.loc_uv01);
  unset_attr(tp.loc_uv23);
  unset_attr(tp.loc_uv45);
  unset_attr(tp.loc_uv67);
  unset_attr(tp.loc_color0);
  unset_attr(tp.loc_color1);
  ++tris_drawn_;
}

void GxGlRenderer::ApplyFixedState(const GxFixedState& f) {
  // Z: solo si la palabra 0x40 esta presente.
  if (f.z.present) {
    if (f.z.enable) {
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(CompareFuncGl(f.z.func));
    } else {
      glDisable(GL_DEPTH_TEST);
    }
    glDepthMask(f.z.update ? GL_TRUE : GL_FALSE);
  }
  // Blend: solo si la palabra 0x41 esta presente. Logica
  // (LOGIC) no tiene equivalente GLES: blend desactivado +
  // contador (el resultado no sera el de HW, pero el draw
  // se dibuja en vez de saltarse).
  if (f.blend.present) {
    if (f.blend.logic) {
      glDisable(GL_BLEND);
      ++fixed_logic_fallback_;
    } else if (f.blend.enable) {
      glEnable(GL_BLEND);
      glBlendFunc(BlendFactorGl(f.blend.src),
                  BlendFactorGl(f.blend.dst));
      glBlendEquation(f.blend.subtract ? GL_FUNC_REVERSE_SUBTRACT
                                       : GL_FUNC_ADD);
    } else {
      glDisable(GL_BLEND);
    }
    glColorMask(f.blend.color_update ? GL_TRUE : GL_FALSE,
                f.blend.color_update ? GL_TRUE : GL_FALSE,
                f.blend.color_update ? GL_TRUE : GL_FALSE,
                f.blend.alpha_update ? GL_TRUE : GL_FALSE);
  }
  // Cull: solo si GENMODE esta presente.
  if (f.genmode_present) {
    switch (f.cull) {
      case 0:
        glDisable(GL_CULL_FACE);
        break;
      case 1:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        break;
      case 2:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        break;
      default:
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT_AND_BACK);
        break;
    }
    // SUPOSICION Tramo 5: el traductor niega Y (NDC y arriba
    // desde EFB y abajo), lo que invierte el winding: el
    // frente CCW de GX llega como CW a GL. Si en dispositivo
    // los triangulos con cull salen al reves, el flip va
    // aqui (GL_CCW) y se vera en la prueba de cull.
    glFrontFace(GL_CW);
  }
  // Scissor: solo si las dos palabras estan presentes. EFB
  // y arriba->abajo: GL mide desde abajo.
  if (f.scissor.present) {
    glEnable(GL_SCISSOR_TEST);
    glScissor(f.scissor.x, viewport_h_ - (f.scissor.y + f.scissor.h),
              f.scissor.w, f.scissor.h);
  }
  // Fog: contado, sin aplicar (ver gx.h).
  bool any_fog = false;
  for (int i = 0; i < 5; ++i) any_fog |= f.fog_present[i];
  if (any_fog) ++fixed_fog_draws_;
}

int GxGlRenderer::DrawDraws(const std::vector<GxDraw>& draws,
                            const TexResolver& resolver) {
  if (program_ == 0) return 0;
  // Altura del viewport GL (una vez por llamada) para el
  // flip vertical del scissor.
  {
    GLint vp[4] = {0, 0, 640, 480};
    glGetIntegerv(GL_VIEWPORT, vp);
    if (vp[3] > 0) viewport_h_ = vp[3];
  }
  // Cache por frame: tex_obj -> textura GL (se borra al final,
  // para que una textura THP reutilizada no quede obsoleta).
  std::map<uint32_t, GLuint> frame_tex;
  GLuint magenta = 0;
  auto resolve_tex = [&](uint32_t tex_obj) -> GLuint {
    if (tex_obj == 0) {
      if (magenta == 0) {
        uint8_t px[4] = {255, 0, 255, 255};
        magenta = UploadTexture(px, 1, 1);
      }
      return magenta;
    }
    auto it = frame_tex.find(tex_obj);
    if (it != frame_tex.end()) return it->second;
    GxDecodedTex dec;
    bool ok = resolver != nullptr && resolver(tex_obj, &dec) && dec.ok;
    GLuint tex = 0;
    if (ok) {
      tex = UploadTexture(dec.rgba.data(), dec.width, dec.height);
    } else {
      if (magenta == 0) {
        uint8_t px[4] = {255, 0, 255, 255};
        magenta = UploadTexture(px, 1, 1);
      }
      tex = magenta;
    }
    frame_tex[tex_obj] = tex;
    return tex;
  };
  int drawn = 0;
  for (const GxDraw& d : draws) {
    std::vector<GlTri> tris;
    if (!GxDrawToGlTris(d, 640, 480, &tris)) {
      ++quads_skipped_;
      continue;
    }
    // Estado fijo del draw (Tramo 5): se aplica a TODOS los
    // draws traducibles, tengan o no snapshot TEV (un draw
    // construido a mano trae el estado por defecto: ninguna
    // palabra presente => no toca nada).
    ApplyFixedState(d.fixed);
    // Texturas por mapa (Tramo 5): se resuelven una vez por
    // draw y se reutilizan en sus tris. Mapa sin carga o sin
    // resolver => magenta (placeholder documentado).
    GLuint tex_by_map[8];
    for (int m = 0; m < 8; ++m) {
      tex_by_map[m] = resolve_tex(tris.empty() ? 0 : tris[0].tex_objs[m]);
    }
    // Textura legacy del camino fijo: ultimo mapa cargado.
    uint32_t tex_obj = tris.empty() ? 0 : tris[0].tex_obj;
    GLuint tex = 0;
    bool use_tex = false;
    if (tex_obj != 0) {
      tex = resolve_tex(tex_obj);
      use_tex = true;
    }
    // Camino TEV: si el draw trae snapshot, su programa se
    // genera por hash + modo alpha-test (contado) y se usa
    // siempre que genera (Tramo 5: color y varios samplers
    // soportados); si no compila/enlaza, cae al programa
    // fijo anterior (tev_fallback_), nunca crash. Sin
    // snapshot (has_tev=false) no se tocan los contadores TEV.
    if (d.has_tev) {
      ++tev_draws_;
      TevGenResult gen;
      const GxAlphaTest* alpha =
          d.fixed.alpha.present ? &d.fixed.alpha : nullptr;
      tev_cache_.Get(d.tev, &gen, alpha);
      tev_stages_total_ += gen.stages_processed;
      tev_indirect_noop_ += gen.indirect_noop;
      tev_unsupported_ += gen.unsupported;
      const TevGlProgram* tp = nullptr;
      if (TevGlUsable(gen, d)) tp = GetOrCompileTevProgram(gen);
      if (tp != nullptr) {
        for (const GlTri& tri : tris) {
          DrawTriVerticesTev(tri, tex_by_map, *tp, d.tev, d.fixed);
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
