#pragma once

// Generador de shader TEV multi-etapa (Fase TEV, sin dependencias
// GL: genera texto GLSL ES 1.00 + decodifica palabras BP; el
// renderer GLES lo usa en gx_gl.cpp y los tests host lo ejercen
// sin contexto GL).
//
// Fuente: TEV-DESIGN.md (work-port/fase18-tev/). Puntos fijados
// por ese diseño y NO reinventados aqui:
//  - Palabra color BP 0xC0+2*etapa, palabra alfa 0xC1+2*etapa,
//    GENMODE (BP 0x00) bits [13:10] + 1 = nº de etapas.
//  - Campos palabra color: d[3:0], c[7:4], b[11:8], a[15:12],
//    bias[17:16], op-bit[18], clamp[19], scale[21:20],
//    out[23:22]; bits[17:16]==3 => COMP (op = 8 + bit[18] +
//    (bits[21:20]<<1)), si no ADD (bit[18]=0) o SUB (1).
//  - Palabra alfa: misma estructura de operacion; sus 4 campos
//    de entrada son de 3 bits (enum GX_CA), ANCLADOS Tramo 5
//    en GXSetTevAlphaIn 0x8025C430: swap_ras[1:0]
//    swap_tex[3:2] d[6:4] c[9:7] b[12:10] a[15:13].
//    (La fase A asumia d[2:0] c[5:3] b[8:6] a[11:9] por
//    simetria con color: ERRONEO, corregido aqui; los tests
//    que fijaban el layout viejo deben actualizarse, no el
//    decodificador.)
//  - Formula ADD: out = (mix(a,b,c) + d + bias) * scale, con
//    clamp opcional a [0,1]; SUB: mix(a,-b,c) + d (misma
//    forma, b negado). COMP: por canal, c si la comparacion
//    a OP b es cierta, 0 en caso contrario; ancho: R8 solo R,
//    GR16 R y G (B=0), BGR24/RGB8 R, G y B independientes
//    (eleccion fijada aqui y cubierta por el test sombra;
//    BGR24 vs RGB8 solo difieren en orden de canales y en la
//    practica del juego el caso es R8_GT).
//  - Indirecto: no-op CONTADO (texcoord sin perturbar, el
//    combining de la etapa se genera igual). Input/op fuera
//    de enum: passthrough de la etapa + contador, nunca crash
//    ni magenta. Etapas > 16: truncadas a 16 con marca.
//  - Etapa identidad (ADD, bias/scale neutros, c=ZERO, d=ZERO,
//    a=PREV, out=PREV en color y alfa): no emite codigo, pero
//    cuenta como procesada (no como "no soportada").
//  - Samplers: un uniform por TEXMAP usado (max 8), no por
//    etapa. Textura no resuelta -> magenta 1x1 (lo pone el
//    renderer, no el generador).
//  - GLSL ES 1.00 (attribute/varying/texture2D), misma
//    sintaxis que los shaders actuales: migrar a 300 es un
//    cambio separado, no parte de TEV.
//  - PREV inicial: (0,0,0) / 0.0. Registros C0-C2: se
//    inicializan con las constantes TevColor de BP
//    (uniforms uRegC/uRegA; 0 si la palabra no esta
//    presente). CORRECCION Tramo 5: la fase A los
//    inicializaba a 0 y trataba C0 como uniform distinto
//    del local out_reg; el modelo correcto es unificado
//    (ver el comentario en GenerateTevFragment).
//  - RASC/RASA: color de vertice. Campo BP de canal 0 ->
//    varying vColor; campo 1 -> vColor1; campo 7 = NULL
//    (sin color: RASC/RASA caen a vColor por el else del
//    generador, caso que el juego no deberia producir).
//    Tramo 5: gx_gl.cpp entrega vColor/vColor1 y las 8 UV
//    por mapa (varyings empaquetados vUv01/vUv23/vUv45/
//    vUv67), asi que TevGlUsable ya no rechaza programas
//    con color ni con varios samplers.
//  - Order/KSEL/indirecto/konst/regcolor del snapshot:
//    ANCLADOS Tramo 5 (ver gx.h para los layouts y las
//    direcciones SDK). El generador confia en lo que
//    TevState dice; un TevState construido a mano debe usar
//    el CAMPO BP de canal (0/1/7), no el enum GX (0,1,4,5).
//  - Swap: si la tabla swap de ras/tex de la etapa no es
//    identidad, el generador emite la permutacion (salida
//    indexada: out.r = in[tabla[0]], etc.). Tabla con una
//    entrada fuera de [0,3] => swap ignorado (identidad).
//  - Alpha-compare (estado fijo, no TEV): GenerateTevFragment
//    acepta un GxAlphaTest opcional y, si el test puede
//    fallar, inyecta un discard antes de gl_FragColor con
//    refs en uniforms (uAlphaRef0/uAlphaRef1); el modo
//    (comp0/comp1/op) queda en TevGenResult.alpha_test_mode
//    para la clave de caché GL. Refs en float: comparacion
//    exacta en float de valores k/255 (aproximacion
//    documentada: el TEV puede dejar prev_a fuera de k/255
//    exacto tras aritmetica).
//  - Indirecto: sigue siendo no-op CONTADO (Tramo 5 ancla
//    la palabra y el ind order, pero la matriz/escala ind
//    no estan decodificadas: perturbar seria inventar).

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "gamecube_runtime/gx.h"

namespace sfa {

// Enums GX_CC (color, 4 bits) y GX_CA (alfa, 3 bits), libogc.
namespace tev {
inline constexpr int kCcPrev = 0, kCcAPrev = 1, kCcC0 = 2, kCcA0 = 3;
inline constexpr int kCcC1 = 4, kCcA1 = 5, kCcC2 = 6, kCcA2 = 7;
inline constexpr int kCcTexC = 8, kCcTexA = 9, kCcRasC = 10;
inline constexpr int kCcRasA = 11, kCcOne = 12, kCcHalf = 13;
inline constexpr int kCcKonst = 14, kCcZero = 15;
inline constexpr int kCaPrev = 0, kCaA0 = 1, kCaA1 = 2, kCaA2 = 3;
inline constexpr int kCaTexA = 4, kCaRasA = 5, kCaKonst = 6;
inline constexpr int kCaZero = 7;
inline constexpr int kOpAdd = 0, kOpSub = 1;
inline constexpr int kOpCompR8Gt = 8, kOpCompR8Eq = 9;
inline constexpr int kOpCompGr16Gt = 10, kOpCompGr16Eq = 11;
inline constexpr int kOpCompBgr24Gt = 12, kOpCompBgr24Eq = 13;
inline constexpr int kOpCompRgb8Gt = 14, kOpCompRgb8Eq = 15;
}  // namespace tev

// Decodifica una palabra color BP en inputs + operacion.
inline void DecodeColorWord(uint32_t w, TevInput* in, TevOp* op) {
  in->d = static_cast<int>(w & 0xF);
  in->c = static_cast<int>((w >> 4) & 0xF);
  in->b = static_cast<int>((w >> 8) & 0xF);
  in->a = static_cast<int>((w >> 12) & 0xF);
  int bias_field = static_cast<int>((w >> 16) & 0x3);
  int op_bit = static_cast<int>((w >> 18) & 0x1);
  int scale_field = static_cast<int>((w >> 20) & 0x3);
  if (bias_field == 3) {
    // Rama COMP del SDK: bits[17:16]=3 fuerza COMP.
    op->op = 8 + op_bit + (scale_field << 1);
    op->bias = 0;
    op->scale = 0;
  } else {
    op->op = op_bit;  // 0=ADD, 1=SUB
    op->bias = bias_field;
    op->scale = scale_field;
  }
  op->clamp = static_cast<int>((w >> 19) & 0x1);
  op->out_reg = static_cast<int>((w >> 22) & 0x3);
}

// Decodifica una palabra alfa BP. ANCLADO Tramo 5 en
// GXSetTevAlphaIn 0x8025C430 (d<<4, c<<7, b<<10, a<<13) y
// GXSetTevSwapMode 0x8025C868 (tablas en bits 0-3).
// Operacion: misma estructura de bits que color.
inline void DecodeAlphaWord(uint32_t w, TevInput* in, TevOp* op) {
  in->d = static_cast<int>((w >> 4) & 0x7);
  in->c = static_cast<int>((w >> 7) & 0x7);
  in->b = static_cast<int>((w >> 10) & 0x7);
  in->a = static_cast<int>((w >> 13) & 0x7);
  int bias_field = static_cast<int>((w >> 16) & 0x3);
  int op_bit = static_cast<int>((w >> 18) & 0x1);
  int scale_field = static_cast<int>((w >> 20) & 0x3);
  if (bias_field == 3) {
    op->op = 8 + op_bit + (scale_field << 1);
    op->bias = 0;
    op->scale = 0;
  } else {
    op->op = op_bit;
    op->bias = bias_field;
    op->scale = scale_field;
  }
  op->clamp = static_cast<int>((w >> 19) & 0x1);
  op->out_reg = static_cast<int>((w >> 22) & 0x3);
}

// Ids de tabla swap de una palabra alfa (GXSetTevSwapMode:
// ras en bits 0-1, tex en bits 2-3).
inline void DecodeAlphaSwap(uint32_t w, int* swap_ras, int* swap_tex) {
  *swap_ras = static_cast<int>(w & 0x3);
  *swap_tex = static_cast<int>((w >> 2) & 0x3);
}

// Palabra order 0x28+p (GXSetTevOrder 0x8025CA34). Etapa par
// = mitad alta, impar = mitad baja. Sin flag de presente,
// texmap = 255 (NULL). colorchan = CAMPO BP (0/1/7).
inline void DecodeOrderWord(uint32_t w, bool even, int* texcoord,
                            int* texmap, int* colorchan) {
  if (even) {
    *texmap = static_cast<int>((w >> 12) & 0x7);
    *texcoord = static_cast<int>((w >> 15) & 0x7);
    if (!((w >> 18) & 0x1)) *texmap = 255;
    *colorchan = static_cast<int>((w >> 19) & 0x7);
  } else {
    *texmap = static_cast<int>(w & 0x7);
    *texcoord = static_cast<int>((w >> 3) & 0x7);
    if (!((w >> 6) & 0x1)) *texmap = 255;
    *colorchan = static_cast<int>((w >> 7) & 0x7);
  }
  // El campo de canal solo toma 0/1/7 en entradas validas
  // (tabla GXSetTevOrder en DOL 0x803303E0 + NULL=7); otro
  // valor se trata como NULL (nunca como set 1).
  if (*colorchan != 0 && *colorchan != 1) *colorchan = 255;
}

// Palabra ksel 0xF6+p (GXSetTevKColorSel 0x8025C790,
// GXSetTevKAlphaSel 0x8025C7FC). Bits 0-3 = datos swap.
inline void DecodeKselWord(uint32_t w, bool even, int* kcolor_sel,
                           int* kalpha_sel) {
  if (even) {
    *kcolor_sel = static_cast<int>((w >> 14) & 0x1F);
    *kalpha_sel = static_cast<int>((w >> 19) & 0x1F);
  } else {
    *kcolor_sel = static_cast<int>((w >> 4) & 0x1F);
    *kalpha_sel = static_cast<int>((w >> 9) & 0x1F);
  }
}

// Tablas swap desde las palabras ksel (GXSetTevSwapModeTable
// 0x8025C8C0): tabla t = (bits 0-1 de 0xF6+2t, bits 2-3 de
// 0xF6+2t, bits 0-1 de 0xF6+2t+1, bits 2-3 de 0xF6+2t+1).
// Solo se sobrescriben las entradas cuyas palabras estan
// presentes; el resto conserva el defecto GXInit del estado.
inline void DecodeSwapTables(const std::map<uint32_t, uint32_t>& bp,
                             int tables[4][4]) {
  for (int t = 0; t < 4; ++t) {
    auto it0 = bp.find(0xF6u + 2u * static_cast<uint32_t>(t));
    if (it0 != bp.end()) {
      tables[t][0] = static_cast<int>(it0->second & 0x3);
      tables[t][1] = static_cast<int>((it0->second >> 2) & 0x3);
    }
    auto it1 = bp.find(0xF6u + 2u * static_cast<uint32_t>(t) + 1u);
    if (it1 != bp.end()) {
      tables[t][2] = static_cast<int>(it1->second & 0x3);
      tables[t][3] = static_cast<int>((it1->second >> 2) & 0x3);
    }
  }
}

// Palabra indirecta 0x10+etapa (GXSetTevIndirect 0x8025BB58).
inline void DecodeIndirectWord(uint32_t w, TevStage* s) {
  s->indstage = static_cast<int>(w & 0x3);
  s->ind_format = static_cast<int>((w >> 2) & 0x3);
  s->ind_bias = static_cast<int>((w >> 4) & 0x7);
  s->ind_alpha = static_cast<int>((w >> 7) & 0x3);
  s->ind_mtx = static_cast<int>((w >> 9) & 0xF);
  s->ind_wrap_s = static_cast<int>((w >> 13) & 0x7);
  s->ind_wrap_t = static_cast<int>((w >> 16) & 0x7);
  s->ind_flag19 = static_cast<int>((w >> 19) & 0x1);
  s->ind_add = static_cast<int>((w >> 20) & 0x3);
}

// Konst/regcolor desde 0xE0+2*i / 0xE1+2*i (GXSetTevColor
// 0x8025C634, GXSetTevKColor 0x8025C71C): bit 23 = 1 =>
// KColor, 0 => TevColor. Devuelve true si el par estaba
// presente (al menos una palabra).
inline bool DecodeKonstRegcolor(const std::map<uint32_t, uint32_t>& bp,
                                int i, float konst_out[4],
                                float regcolor_out[4]) {
  auto it0 = bp.find(0xE0u + 2u * static_cast<uint32_t>(i));
  auto it1 = bp.find(0xE1u + 2u * static_cast<uint32_t>(i));
  if (it0 == bp.end() && it1 == bp.end()) return false;
  uint32_t w0 = it0 == bp.end() ? 0 : it0->second;
  uint32_t w1 = it1 == bp.end() ? 0 : it1->second;
  float r = static_cast<float>(w0 & 0xFF) / 255.0f;
  float a = static_cast<float>((w0 >> 12) & 0xFF) / 255.0f;
  float b = static_cast<float>(w1 & 0xFF) / 255.0f;
  float g = static_cast<float>((w1 >> 12) & 0xFF) / 255.0f;
  float* dst = ((w0 >> 23) & 0x1) ? konst_out : regcolor_out;
  dst[0] = r;
  dst[1] = g;
  dst[2] = b;
  dst[3] = a;
  return true;
}

// --- Estado fijo (decodificadores puros, sin GL) ---

// Blend 0x41 (GXSetBlendMode 0x8025CEF4). Bit 2 sin asignar:
// se ignora (no se afirma nada sobre el).
inline void DecodeBlendWord(uint32_t w, GxBlendState* out) {
  out->present = true;
  out->enable = (w & 0x1) != 0;
  out->logic = (w & 0x2) != 0;
  out->color_update = (w & 0x8) != 0;
  out->alpha_update = (w & 0x10) != 0;
  out->dst = static_cast<int>((w >> 5) & 0x7);
  out->src = static_cast<int>((w >> 8) & 0x7);
  out->subtract = (w & 0x800) != 0;
  out->op = static_cast<int>((w >> 12) & 0xF);
}

// Z 0x40 (GXSetZMode 0x8025D078).
inline void DecodeZWord(uint32_t w, GxZState* out) {
  out->present = true;
  out->enable = (w & 0x1) != 0;
  out->func = static_cast<int>((w >> 1) & 0x7);
  out->update = (w & 0x10) != 0;
}

// Alpha-compare 0xF3 (GXSetAlphaCompare 0x8025C960, args
// comp0/ref0/op/comp1/ref1). Ver gx.h: empaquetado limpio
// ref0[7:0] ref1[15:8] comp0[18:16] comp1[21:19] op[23:22].
inline void DecodeAlphaCompareWord(uint32_t w, GxAlphaTest* out) {
  out->present = true;
  out->ref0 = static_cast<int>(w & 0xFF);
  out->ref1 = static_cast<int>((w >> 8) & 0xFF);
  out->comp0 = static_cast<int>((w >> 16) & 0x7);
  out->comp1 = static_cast<int>((w >> 19) & 0x7);
  out->op = static_cast<int>((w >> 22) & 0x3);
}

// GENMODE 0x00 (GXSetNumTexGens 0x80258B50, GXSetNumTevStages
// 0x8025CC10, GXSetCullMode 0x80259494, GXSetNumIndStages
// 0x8025C060).
inline void DecodeGenmodeWord(uint32_t w, int* num_texgens,
                              int* num_stages, int* cull,
                              int* num_ind_stages) {
  *num_texgens = static_cast<int>(w & 0xF);
  *num_stages = static_cast<int>(((w >> 10) & 0xF) + 1);
  *cull = static_cast<int>((w >> 14) & 0x3);
  *num_ind_stages = static_cast<int>((w >> 16) & 0x7);
}

// Scissor 0x20/0x21 (GXSetScissor 0x8025DC94). Devuelve false
// si falta alguna palabra (sin scissor completo no hay rect).
inline bool DecodeScissorWords(uint32_t w20, uint32_t w21,
                               GxScissorState* out) {
  int x0 = static_cast<int>((w20 >> 12) & 0x7FF) - 342;
  int y0 = static_cast<int>(w20 & 0x7FF) - 342;
  int x1 = static_cast<int>((w21 >> 12) & 0x7FF) - 342;
  int y1 = static_cast<int>(w21 & 0x7FF) - 342;
  out->present = true;
  out->x = x0;
  out->y = y0;
  out->w = x1 - x0 + 1;
  out->h = y1 - y0 + 1;
  return true;
}

// Snapshot de estado fijo desde el mapa BP vigente (lo llama
// GxParser::ParseDraw junto al snapshot TEV).
inline GxFixedState SnapshotFixedFromBp(
    const std::map<uint32_t, uint32_t>& bp) {
  GxFixedState f;
  auto get = [&](uint32_t reg, uint32_t* out) {
    auto it = bp.find(reg);
    if (it == bp.end()) return false;
    *out = it->second;
    return true;
  };
  uint32_t w = 0;
  if (get(0x00, &w)) {
    f.genmode_present = true;
    int ns = 1, ni = 0;
    // num_ind_stages no vive en GxFixedState (va en TevState);
    // se decodifica alli desde el mismo GENMODE.
    DecodeGenmodeWord(w, &f.num_texgens, &ns, &f.cull, &ni);
  }
  if (get(0x41, &w)) DecodeBlendWord(w, &f.blend);
  if (get(0x40, &w)) DecodeZWord(w, &f.z);
  if (get(0xF3, &w)) DecodeAlphaCompareWord(w, &f.alpha);
  uint32_t w20 = 0, w21 = 0;
  if (get(0x20, &w20) && get(0x21, &w21))
    DecodeScissorWords(w20, w21, &f.scissor);
  for (int i = 0; i < 5; ++i) {
    if (get(0xEEu + static_cast<uint32_t>(i), &w)) {
      f.fog_words[i] = w;
      f.fog_present[i] = true;
    }
  }
  static const uint32_t kCopyRegs[3] = {0x49, 0x4A, 0x4D};
  for (int i = 0; i < 3; ++i) {
    if (get(kCopyRegs[i], &w)) {
      f.copy_words[i] = w;
      f.copy_present[i] = true;
    }
  }
  if (get(0x27, &w)) {
    f.ind_order_word = w;
    f.ind_order_present = true;
  }
  return f;
}

// Etapa identidad: devuelve PREV intacto (color y alfa).
inline bool IsIdentityStage(const TevStage& s) {
  const TevOp& co = s.color_op;
  const TevOp& ao = s.alpha_op;
  bool color_id = co.op == 0 && co.bias == 0 && co.scale == 0 &&
                  co.out_reg == 0 && s.color.a == tev::kCcPrev &&
                  s.color.c == tev::kCcZero && s.color.d == tev::kCcZero;
  bool alpha_id = ao.op == 0 && ao.bias == 0 && ao.scale == 0 &&
                  ao.out_reg == 0 && s.alpha.a == tev::kCaPrev &&
                  s.alpha.c == tev::kCaZero && s.alpha.d == tev::kCaZero;
  return color_id && alpha_id;
}

// Validez estructural de un TevState (no de su procedencia).
// Devuelve false con motivo en error si algo esta fuera de
// enum o num_stages fuera de [1,16].
inline bool ValidateTevState(const TevState& st, std::string* error) {
  auto fail = [&](const char* msg) {
    if (error != nullptr) *error = msg;
    return false;
  };
  if (st.num_stages < 1 || st.num_stages > 16)
    return fail("num_stages fuera de [1,16]");
  for (int i = 0; i < st.num_stages; ++i) {
    const TevStage& s = st.stages[i];
    const int* ci[4] = {&s.color.a, &s.color.b, &s.color.c, &s.color.d};
    for (int k = 0; k < 4; ++k)
      if (*ci[k] < 0 || *ci[k] > 15) return fail("input color fuera de enum");
    const int* ai[4] = {&s.alpha.a, &s.alpha.b, &s.alpha.c, &s.alpha.d};
    for (int k = 0; k < 4; ++k)
      if (*ai[k] < 0 || *ai[k] > 7) return fail("input alfa fuera de enum");
    for (const TevOp* op : {&s.color_op, &s.alpha_op}) {
      bool ok_op = op->op == 0 || op->op == 1 ||
                   (op->op >= 8 && op->op <= 15);
      if (!ok_op) return fail("op fuera de enum");
      if (op->out_reg < 0 || op->out_reg > 3)
        return fail("out_reg fuera de enum");
      if (op->bias < 0 || op->bias > 2 || op->scale < 0 ||
          op->scale > 3 || (op->clamp != 0 && op->clamp != 1))
        return fail("bias/scale/clamp fuera de enum");
    }
    if (!((s.texmap == 255) || (s.texmap >= 0 && s.texmap <= 7)))
      return fail("texmap fuera de enum");
    if (s.kcolor_sel < 0 || s.kcolor_sel > 27 ||
        s.kalpha_sel < 0 || s.kalpha_sel > 27)
      return fail("ksel fuera de enum");
    if (s.swap_ras < 0 || s.swap_ras > 3 || s.swap_tex < 0 ||
        s.swap_tex > 3)
      return fail("swap fuera de enum");
  }
  return true;
}

// Hash FNV-1a del TevState completo (clave de caché: dos
// estados con un campo distinto deben dar hash distinto).
inline uint32_t TevHash(const TevState& st) {
  uint32_t h = 2166136261u;
  auto mix = [&](uint32_t v) {
    h ^= v;
    h *= 16777619u;
  };
  mix(static_cast<uint32_t>(st.num_stages));
  mix(static_cast<uint32_t>(st.num_ind_stages));
  for (int t = 0; t < 4; ++t)
    for (int c = 0; c < 4; ++c)
      mix(static_cast<uint32_t>(st.swap_tables[t][c]));
  for (int i = 0; i < 16; ++i) {
    const TevStage& s = st.stages[i];
    mix(static_cast<uint32_t>(s.texcoord));
    mix(static_cast<uint32_t>(s.texmap));
    mix(static_cast<uint32_t>(s.colorchan));
    mix(static_cast<uint32_t>(s.swap_ras) |
        (static_cast<uint32_t>(s.swap_tex) << 4) |
        (static_cast<uint32_t>(s.indstage) << 8) |
        (static_cast<uint32_t>(s.ind_format) << 12) |
        (static_cast<uint32_t>(s.ind_bias) << 16) |
        (static_cast<uint32_t>(s.ind_alpha) << 20) |
        (static_cast<uint32_t>(s.ind_mtx) << 24) |
        (static_cast<uint32_t>(s.ind_wrap_s) << 28));
    mix(static_cast<uint32_t>(s.ind_wrap_t) |
        (static_cast<uint32_t>(s.ind_add) << 4) |
        (static_cast<uint32_t>(s.ind_flag19) << 8) |
        (static_cast<uint32_t>(s.ind_texmap) << 12) |
        (static_cast<uint32_t>(s.ind_texcoord) << 20));
    mix(static_cast<uint32_t>(s.color.a) |
        (static_cast<uint32_t>(s.color.b) << 4) |
        (static_cast<uint32_t>(s.color.c) << 8) |
        (static_cast<uint32_t>(s.color.d) << 12));
    mix(static_cast<uint32_t>(s.alpha.a) |
        (static_cast<uint32_t>(s.alpha.b) << 3) |
        (static_cast<uint32_t>(s.alpha.c) << 6) |
        (static_cast<uint32_t>(s.alpha.d) << 9));
    mix(static_cast<uint32_t>(s.color_op.op) |
        (static_cast<uint32_t>(s.color_op.bias) << 4) |
        (static_cast<uint32_t>(s.color_op.scale) << 6) |
        (static_cast<uint32_t>(s.color_op.clamp) << 8) |
        (static_cast<uint32_t>(s.color_op.out_reg) << 9));
    mix(static_cast<uint32_t>(s.alpha_op.op) |
        (static_cast<uint32_t>(s.alpha_op.bias) << 4) |
        (static_cast<uint32_t>(s.alpha_op.scale) << 6) |
        (static_cast<uint32_t>(s.alpha_op.clamp) << 8) |
        (static_cast<uint32_t>(s.alpha_op.out_reg) << 9));
    mix(static_cast<uint32_t>(s.kcolor_sel) |
        (static_cast<uint32_t>(s.kalpha_sel) << 8) |
        (static_cast<uint32_t>(s.has_indirect ? 1 : 0) << 16));
  }
  for (int k = 0; k < 4; ++k)
    for (int c = 0; c < 4; ++c) {
      // Los floats se mezclan por bits (sin convertir a int
      // con perdida: un cambio de konst debe cambiar el hash).
      uint32_t bits = 0;
      float v = st.konst[k][c];
      __builtin_memcpy(&bits, &v, sizeof(bits));
      mix(bits);
      v = st.regcolor[k][c];
      __builtin_memcpy(&bits, &v, sizeof(bits));
      mix(bits);
    }
  return h;
}

// Snapshot TEV desde el mapa BP vigente en el momento del
// draw (lo llama GxParser::ParseDraw). ANCLADO Tramo 5 (ver
// gx.h): order 0x28+p, ksel 0xF6+p, indirecto 0x10+e, ind
// order 0x27, konst/regcolor 0xE0-0xE7, swap en alfa bits
// 0-3 y tablas en bits bajos ksel. Palabra ausente =>
// defecto GXInit (order NULL, ksel 0, indirecto directo,
// swap tablas GXInit). Palabra de etapa ausente en bp_
// (etapa dentro de num_stages pero sin escritura previa):
// etapa identidad (devuelve PREV), no basura.
inline TevState SnapshotTevFromBp(
    const std::map<uint32_t, uint32_t>& bp) {
  TevState st;
  st.bp_raw = bp;
  st.order_anchored = true;
  st.ksel_anchored = true;
  st.truncated = false;
  auto get = [&](uint32_t reg, uint32_t* out) {
    auto it = bp.find(reg);
    if (it == bp.end()) return false;
    *out = it->second;
    return true;
  };
  uint32_t genmode = 0;
  if (get(0x00, &genmode)) {
    int nt = 0, c = 0;
    DecodeGenmodeWord(genmode, &nt, &st.num_stages, &c,
                      &st.num_ind_stages);
  } else {
    st.num_stages = 1;
    st.num_ind_stages = 0;
  }
  if (st.num_stages < 1) st.num_stages = 1;
  if (st.num_stages > 16) {
    st.num_stages = 16;
    st.truncated = true;
  }
  // Tablas swap: defecto GXInit del estado, sobrescrito por
  // las palabras ksel presentes (DecodeSwapTables).
  DecodeSwapTables(bp, st.swap_tables);
  // Ind order 0x27 (ausente => ind_texmap/coord -1).
  uint32_t ind_order = 0;
  bool has_ind_order = get(0x27, &ind_order);
  // Konst/regcolor (ausente => 0).
  for (int i = 0; i < 4; ++i) {
    float* k = st.konst[i];
    float* r = st.regcolor[i];
    // DecodeKonstRegcolor escribe solo en el destino que
    // indica el bit 23; el otro queda a 0 (defecto).
    DecodeKonstRegcolor(bp, i, k, r);
  }
  for (int i = 0; i < 16; ++i) {
    TevStage& s = st.stages[i];
    // Order: defecto GXInit = NULL en todo.
    s.texcoord = 255;
    s.texmap = 255;
    s.colorchan = 255;
    uint32_t ow = 0;
    if (get(0x28u + static_cast<uint32_t>(i / 2), &ow)) {
      DecodeOrderWord(ow, (i % 2) == 0, &s.texcoord, &s.texmap,
                      &s.colorchan);
    }
    // KSEL + swap de la etapa.
    s.kcolor_sel = 0;
    s.kalpha_sel = 0;
    uint32_t kw = 0;
    if (get(0xF6u + static_cast<uint32_t>(i / 2), &kw)) {
      DecodeKselWord(kw, (i % 2) == 0, &s.kcolor_sel, &s.kalpha_sel);
    }
    s.swap_ras = 0;
    s.swap_tex = 0;
    // Indirecto: defecto = directo.
    s.has_indirect = false;
    s.indstage = 0;
    s.ind_format = 0;
    s.ind_bias = 0;
    s.ind_alpha = 0;
    s.ind_mtx = 0;
    s.ind_wrap_s = 0;
    s.ind_wrap_t = 0;
    s.ind_flag19 = 0;
    s.ind_add = 0;
    s.ind_texmap = -1;
    s.ind_texcoord = -1;
    uint32_t iw = 0;
    if (get(0x10u + static_cast<uint32_t>(i), &iw) && iw != 0) {
      s.has_indirect = true;
      DecodeIndirectWord(iw, &s);
      if (has_ind_order) {
        int ind = s.indstage;
        s.ind_texmap = static_cast<int>((ind_order >> (3 * ind)) & 0x7);
        s.ind_texcoord =
            static_cast<int>((ind_order >> (3 * ind + 3)) & 0x7);
      }
    }
    uint32_t w = 0;
    if (get(0xC0u + 2u * static_cast<uint32_t>(i), &w)) {
      DecodeColorWord(w, &s.color, &s.color_op);
    } else {
      // Identidad color: a=PREV, c=ZERO, d=ZERO, ADD.
      s.color = TevInput{0, 0, 15, 15};
      s.color_op = TevOp{0, 0, 0, 0, 0};
    }
    if (get(0xC1u + 2u * static_cast<uint32_t>(i), &w)) {
      DecodeAlphaWord(w, &s.alpha, &s.alpha_op);
      DecodeAlphaSwap(w, &s.swap_ras, &s.swap_tex);
    } else {
      s.alpha = TevInput{0, 0, 7, 7};
      s.alpha_op = TevOp{0, 0, 0, 0, 0};
    }
  }
  st.hash = TevHash(st);
  return st;
}

struct TevGenResult {
  bool ok = false;
  std::string fragment;  // GLSL ES 1.00 completo (fragment shader)
  std::vector<int> sampler_maps;  // texmaps usados, en orden
  bool needs_color = false;        // alguna etapa usa RASC/RASA canal 0
  bool needs_color1 = false;       // alguna etapa usa canal 1
  int stages_processed = 0;        // etapas dentro de num_stages
  int stages_emitted = 0;          // etapas que emitieron codigo
  int indirect_noop = 0;           // etapas con indirecto (no-op)
  int unsupported = 0;             // etapas en passthrough
  bool truncated = false;          // num_stages > 16 (defensa)
  uint32_t hash = 0;
  // Modo alpha-test inyectado (0 = sin discard; si no, 1 +
  // comp0 + 8*comp1 + 64*op). Parte de la clave de caché GL
  // junto a hash (las refs son uniforms, no parte de la clave).
  int alpha_test_mode = 0;
  std::string error;
};

namespace tev_detail {

inline std::string KonstColorExpr(int sel, int* unsupported) {
  // Constantes KColorSel 0-7 (libogc, ver TEV-DESIGN.md §3.4).
  static const char* kLits[8] = {
      "vec3(1.0)", "vec3(0.875)", "vec3(0.75)", "vec3(0.625)",
      "vec3(0.5)", "vec3(0.375)", "vec3(0.25)", "vec3(0.125)"};
  if (sel >= 0 && sel <= 7) return kLits[sel];
  if (sel >= 8 && sel <= 11)
    return "uKonst" + std::to_string(sel - 8) + ".rgb";
  if (sel >= 12 && sel <= 27) {
    int reg = (sel - 12) % 4;
    int chan = (sel - 12) / 4;  // 0=R, 1=G, 2=B, 3=A
    static const char* kChan[4] = {"r", "g", "b", "a"};
    return "vec3(uKonst" + std::to_string(reg) + "." + kChan[chan] + ")";
  }
  ++(*unsupported);
  return "vec3(0.0)";
}

inline std::string KonstAlphaExpr(int sel, int* unsupported) {
  static const char* kLits[8] = {"1.0", "0.875", "0.75", "0.625",
                                 "0.5", "0.375", "0.25", "0.125"};
  if (sel >= 0 && sel <= 7) return kLits[sel];
  if (sel >= 8 && sel <= 27) {
    // Orden libogc KAlphaSel: R(8-11), G(12-15), B(16-19),
    // A(20-23)... y 24-27 repiten A por registro (ver diseño
    // §3.4: 24=K0_A..27=K3_A). Se resuelve por (reg, canal)
    // con la misma tabla que color para 8-23 y A para 24-27.
    int reg = 0, chan = 3;
    if (sel <= 23) {
      reg = (sel - 8) % 4;
      chan = (sel - 8) / 4;
    } else {
      reg = sel - 24;
      chan = 3;
    }
    static const char* kChan[4] = {"r", "g", "b", "a"};
    return "uKonst" + std::to_string(reg) + "." + kChan[chan];
  }
  ++(*unsupported);
  return "0.0";
}

inline std::string BiasExpr(int bias) {
  return bias == 1 ? "0.5" : (bias == 2 ? "-0.5" : "0.0");
}

inline std::string ScaleExpr(int scale) {
  return scale == 1 ? "2.0" : (scale == 2 ? "4.0" : (scale == 3 ? "0.5" : "1.0"));
}

// Comparacion COMP por canal: emite la asignacion completa
// del resultado (vec3 o float) a la variable destino.
inline std::string CompColorExpr(const std::string& a, const std::string& b,
                                 const std::string& c, int op) {
  bool eq = (op % 2 == 1);  // 9,11,13,15 son _EQ; 8,10,12,14 _GT
  const char* cmp = eq ? "==" : ">";
  std::string out;
  auto chan = [&](const char* ch) {
    return "((" + a + "." + ch + " " + cmp + " " + b + "." + ch + ") ? " +
           c + "." + ch + " : 0.0)";
  };
  if (op == 8 || op == 9) {
    // R8: solo R; G y B a 0.
    out = "vec3(" + chan("r") + ", 0.0, 0.0)";
  } else if (op == 10 || op == 11) {
    // GR16: R y G comparados, B a 0.
    out = "vec3(" + chan("r") + ", " + chan("g") + ", 0.0)";
  } else {
    // BGR24 / RGB8: R, G y B independientes.
    out = "vec3(" + chan("r") + ", " + chan("g") + ", " + chan("b") + ")";
  }
  return out;
}

// Expresion UV empaquetada para una coord: las 8 UV viajan
// en 4 varyings vec4 (vUv01/vUv23/vUv45/vUv67) para no
// superar el minimo de varyings de GLES2 (el APK es GLES3,
// pero el empaquetado no cuesta nada). La COORD selecciona
// el varying, el MAPA selecciona el sampler: el muestreo es
// texture2D(uTex<texmap>, vUv<texcoord>). Fase A usaba
// vUv<texmap>: mal cuando texcoord != texmap (caso UI etapa
// 1: texcoord 0, texmap 1).
inline std::string UvExpr(int texcoord) {
  static const char* kPair[4] = {"vUv01", "vUv23", "vUv45", "vUv67"};
  static const char* kSwz[8] = {"xy", "zw", "xy", "zw",
                                "xy", "zw", "xy", "zw"};
  if (texcoord < 0 || texcoord > 7) return "vec2(0.0)";
  return std::string(kPair[texcoord / 2]) + "." + kSwz[texcoord];
}

// Codigo alpha-test (discard) para un GxAlphaTest. mode = 0
// si el test siempre pasa (sin discard); si no, 1 + comp0 +
// 8*comp1 + 64*op. uniforms solo declara las refs que usa un
// comp no constante. El valor testeado es prev_a (alfa final
// tras todas las etapas, como en HW).
struct AlphaGlsl {
  int mode = 0;
  std::string uniforms;
  std::string discard;
};

inline AlphaGlsl AlphaTestGlsl(const GxAlphaTest& at) {
  AlphaGlsl out;
  if (!at.present) return out;
  auto comp_is_const = [](int c) { return c == 0 || c == 7; };
  auto comp_val = [](int c) { return c == 7; };
  auto comp_expr = [](int c, const std::string& ref) -> std::string {
    switch (c) {
      case 0: return "false";
      case 1: return "(prev_a < " + ref + ")";
      case 2: return "(prev_a == " + ref + ")";
      case 3: return "(prev_a <= " + ref + ")";
      case 4: return "(prev_a > " + ref + ")";
      case 5: return "(prev_a != " + ref + ")";
      case 6: return "(prev_a >= " + ref + ")";
      default: return "true";
    }
  };
  bool c0c = comp_is_const(at.comp0), c1c = comp_is_const(at.comp1);
  bool v0 = comp_val(at.comp0), v1 = comp_val(at.comp1);
  bool comb_const = false, comb_val = false;
  switch (at.op) {
    case 0: comb_const = c0c && c1c; comb_val = v0 && v1; break;  // AND
    case 1: comb_const = c0c && c1c; comb_val = v0 || v1; break;  // OR
    case 2: comb_const = c0c && c1c; comb_val = v0 != v1; break;  // XOR
    default: comb_const = c0c && c1c; comb_val = v0 == v1; break;  // XNOR
  }
  if (comb_const && comb_val) return out;  // siempre pasa: sin codigo
  out.mode = 1 + at.comp0 + 8 * at.comp1 + 64 * at.op;
  if (!c0c) out.uniforms += "uniform float uAlphaRef0;\n";
  if (!c1c) out.uniforms += "uniform float uAlphaRef1;\n";
  if (comb_const) {
    // Siempre falla: discard incondicional.
    out.discard = "  discard;\n";
    return out;
  }
  std::string t0 = c0c ? (v0 ? "true" : "false")
                       : comp_expr(at.comp0, "uAlphaRef0");
  std::string t1 = c1c ? (v1 ? "true" : "false")
                       : comp_expr(at.comp1, "uAlphaRef1");
  const char* op = at.op == 0 ? "&&" : (at.op == 1 ? "||" : (at.op == 2 ? "!=" : "=="));
  out.discard = "  if (!(" + t0 + " " + op + " " + t1 + ")) discard;\n";
  return out;
}

}  // namespace tev_detail

// Genera el fragment shader GLSL ES 1.00 de un TevState.
// Tolerante por etapa (TEV-DESIGN.md §6): un input/op/ksel
// fuera de enum en UNA etapa deja esa etapa en passthrough
// y sube unsupported, sin tumbar el resto del shader ni el
// frame. Solo falla (ok=false) si num_stages < 1; num_stages
// > 16 se trunca a 16 con marca (defensa ante stream
// corrupto). ValidateTevState sigue siendo el chequeo
// estricto para quien lo quiera (tests de estructura).
// alpha_test: estado fijo del draw (puede ser null o sin
// present: entonces no hay discard). El modo va a
// TevGenResult.alpha_test_mode (clave de caché GL).
inline TevGenResult GenerateTevFragment(
    const TevState& st_in, const GxAlphaTest* alpha_test = nullptr) {
  TevGenResult r;
  r.hash = TevHash(st_in);
  tev_detail::AlphaGlsl alpha_glsl;
  if (alpha_test != nullptr) alpha_glsl = tev_detail::AlphaTestGlsl(*alpha_test);
  r.alpha_test_mode = alpha_glsl.mode;
  TevState st = st_in;
  if (st.num_stages < 1) {
    r.error = "num_stages < 1";
    return r;
  }
  if (st.num_stages > 16) {
    st.num_stages = 16;
    r.truncated = true;
  }
  int n = st.num_stages;
  r.stages_processed = n;
  // Primer pase: que samplers y varyings hacen falta.
  bool sampler_used[8] = {false, false, false, false,
                          false, false, false, false};
  for (int i = 0; i < n; ++i) {
    const TevStage& s = st.stages[i];
    if (s.color.a == tev::kCcTexC || s.color.b == tev::kCcTexC ||
        s.color.c == tev::kCcTexC || s.color.d == tev::kCcTexC ||
        s.alpha.a == tev::kCaTexA || s.alpha.b == tev::kCaTexA ||
        s.alpha.c == tev::kCaTexA || s.alpha.d == tev::kCaTexA) {
      if (s.texmap >= 0 && s.texmap <= 7) sampler_used[s.texmap] = true;
    }
    if (s.color.a == tev::kCcTexA || s.color.b == tev::kCcTexA ||
        s.color.c == tev::kCcTexA || s.color.d == tev::kCcTexA) {
      if (s.texmap >= 0 && s.texmap <= 7) sampler_used[s.texmap] = true;
    }
    // colorchan es el CAMPO BP (0 = set 0, 1 = set 1, 7 =
    // NULL): solo 1 selecciona vColor1. (Fase A comparaba
    // con el enum GX 1/5; el snapshot Tramo 5 ya entrega el
    // campo, asi que 5 ya no significa nada aqui.)
    bool chan1 = (s.colorchan == 1);
    if (s.color.a == tev::kCcRasC || s.color.b == tev::kCcRasC ||
        s.color.c == tev::kCcRasC || s.color.d == tev::kCcRasC ||
        s.color.a == tev::kCcRasA || s.color.b == tev::kCcRasA ||
        s.color.c == tev::kCcRasA || s.color.d == tev::kCcRasA ||
        s.alpha.a == tev::kCaRasA || s.alpha.b == tev::kCaRasA ||
        s.alpha.c == tev::kCaRasA || s.alpha.d == tev::kCaRasA) {
      if (chan1) r.needs_color1 = true; else r.needs_color = true;
    }
  }
  for (int m = 0; m < 8; ++m)
    if (sampler_used[m]) r.sampler_maps.push_back(m);

  std::string src;
  src += "precision mediump float;\n";
  for (int m : r.sampler_maps) {
    src += "uniform sampler2D uTex" + std::to_string(m) + ";\n";
  }
  // UV y colores: varyings empaquetados, siempre declarados
  // (el vertex shader TEV de gx_gl.cpp los escribe siempre;
  // un varying declarado en FS y no escrito en VS no enlaza).
  src += "varying vec4 vUv01;\nvarying vec4 vUv23;\n";
  src += "varying vec4 vUv45;\nvarying vec4 vUv67;\n";
  src += "uniform vec3 uRegC0;\nuniform vec3 uRegC1;\nuniform vec3 uRegC2;\n";
  src += "uniform float uRegA0;\nuniform float uRegA1;\nuniform float uRegA2;\n";
  src += "uniform vec4 uKonst0;\nuniform vec4 uKonst1;\nuniform vec4 uKonst2;\nuniform vec4 uKonst3;\n";
  src += alpha_glsl.uniforms;
  if (r.needs_color) src += "varying vec4 vColor;\n";
  if (r.needs_color1) src += "varying vec4 vColor1;\n";
  src += "void main() {\n";
  src += "  vec3 prev_c = vec3(0.0);\n  float prev_a = 0.0;\n";
  // REGISTROS UNIFICADOS (correccion Tramo 5, probada con la
  // sombra literal): los inputs C0/C1/C2 (A0/A1/A2) leen LOS
  // MISMOS registros que escriben los out_reg, y esos
  // registros se inicializan con las constantes TevColor de
  // BP (uniforms uRegC/uRegA, decodificadas de 0xE0-0xE7).
  // La fase A los trataba como cosas distintas (C0 ->
  // uniform, out_reg -> local a 0): bajo ese modelo, la
  // escritura REG0 de la etapa base de la sombra seria
  // codigo muerto (ninguna etapa posterior la leeria) y la
  // comparacion COMP leeria la constante en vez de la
  // muestra. Con el modelo unificado, la etapa base escribe
  // regs_c0 y la etapa COMP lo lee: flujo real.
  src += "  vec3 regs_c0 = uRegC0;\n  vec3 regs_c1 = uRegC1;\n  vec3 regs_c2 = uRegC2;\n";
  src += "  float regs_a0 = uRegA0;\n  float regs_a1 = uRegA1;\n  float regs_a2 = uRegA2;\n";

  for (int i = 0; i < n; ++i) {
    const TevStage& s = st.stages[i];
    if (s.has_indirect) {
      // No-op documentado: la texcoord se usa sin perturbar.
      // El combining de la etapa se genera igual debajo.
      ++r.indirect_noop;
    }
    // Etapa fuera de enum: passthrough + contador (nunca
    // crash ni magenta). El chequeo estricto completo vive
    // en ValidateTevState; aqui solo se aparta la etapa.
    {
      bool bad = false;
      const int* ci[4] = {&s.color.a, &s.color.b, &s.color.c, &s.color.d};
      for (int k = 0; k < 4; ++k) bad |= (*ci[k] < 0 || *ci[k] > 15);
      const int* ai[4] = {&s.alpha.a, &s.alpha.b, &s.alpha.c, &s.alpha.d};
      for (int k = 0; k < 4; ++k) bad |= (*ai[k] < 0 || *ai[k] > 7);
      for (const TevOp* op : {&s.color_op, &s.alpha_op}) {
        bool ok_op = op->op == 0 || op->op == 1 ||
                     (op->op >= 8 && op->op <= 15);
        bad |= !ok_op || op->out_reg < 0 || op->out_reg > 3 ||
               op->bias < 0 || op->bias > 2 || op->scale < 0 ||
               op->scale > 3 || (op->clamp != 0 && op->clamp != 1);
      }
      bad |= (s.kcolor_sel < 0 || s.kcolor_sel > 27 ||
              s.kalpha_sel < 0 || s.kalpha_sel > 27);
      // Ids swap fuera de [0,3] (solo posibles en estados
      // construidos a mano: el BP da 2 bits): passthrough.
      bad |= (s.swap_ras < 0 || s.swap_ras > 3 ||
              s.swap_tex < 0 || s.swap_tex > 3);
      if (bad) {
        ++r.unsupported;
        continue;
      }
    }
    if (IsIdentityStage(s)) continue;
    // Resolucion de inputs de la etapa.
    bool bad_texmap =
        (s.texmap != 255 && (s.texmap < 0 || s.texmap > 7));
    bool uses_tex_c = s.color.a == tev::kCcTexC ||
                      s.color.b == tev::kCcTexC ||
                      s.color.c == tev::kCcTexC ||
                      s.color.d == tev::kCcTexC;
    bool uses_tex_a = s.color.a == tev::kCcTexA ||
                      s.color.b == tev::kCcTexA ||
                      s.color.c == tev::kCcTexA ||
                      s.color.d == tev::kCcTexA ||
                      s.alpha.a == tev::kCaTexA ||
                      s.alpha.b == tev::kCaTexA ||
                      s.alpha.c == tev::kCaTexA ||
                      s.alpha.d == tev::kCaTexA;
    if (bad_texmap && (uses_tex_c || uses_tex_a)) {
      ++r.unsupported;  // passthrough de la etapa
      continue;
    }
    // Sin texcoord valida no se puede muestrear (texmap
    // valido + texcoord NULL = material roto en el juego).
    bool bad_texcoord = (s.texcoord < 0 || s.texcoord > 7);
    if (bad_texcoord && s.texmap != 255 && (uses_tex_c || uses_tex_a)) {
      ++r.unsupported;
      continue;
    }
    // Swap de la etapa (identidad si la tabla es identidad o
    // tiene una entrada fuera de [0,3]).
    auto swap_active = [&](const int tab[4]) {
      for (int k = 0; k < 4; ++k)
        if (tab[k] < 0 || tab[k] > 3) return false;
      return !(tab[0] == 0 && tab[1] == 1 && tab[2] == 2 &&
               tab[3] == 3);
    };
    const int* ras_tab = st.swap_tables[s.swap_ras];
    const int* tex_tab = st.swap_tables[s.swap_tex];
    bool ras_swap = swap_active(ras_tab);
    bool tex_swap = swap_active(tex_tab);
    std::string pfx = "  ";  // cuerpo de main
    std::string tex_c, tex_a;
    if (uses_tex_c || uses_tex_a) {
      if (s.texmap == 255) {
        tex_c = "vec3(0.0)";
        tex_a = "0.0";
      } else {
        // Sampler = texmap, UV = texcoord (ver UvExpr).
        std::string smp = "texture2D(uTex" + std::to_string(s.texmap) +
                          ", " + tev_detail::UvExpr(s.texcoord) + ")";
        if (tex_swap) {
          // Muestra completa: la permutacion de alfa puede
          // tomar R/G/B, no solo A.
          src += pfx + "vec4 tex" + std::to_string(i) + " = " + smp +
                 ";\n";
          static const char* kCh[4] = {"r", "g", "b", "a"};
          std::string v = "tex" + std::to_string(i);
          tex_c = "vec3(" + v + "." + kCh[tex_tab[0]] + ", " + v + "." +
                  kCh[tex_tab[1]] + ", " + v + "." + kCh[tex_tab[2]] +
                  ")";
          tex_a = v + "." + kCh[tex_tab[3]];
        } else {
          if (uses_tex_c) {
            src += pfx + "vec3 tex" + std::to_string(i) + "c = " + smp +
                   ".rgb;\n";
            tex_c = "tex" + std::to_string(i) + "c";
          }
          if (uses_tex_a) {
            src += pfx + "float tex" + std::to_string(i) + "a = " + smp +
                   ".a;\n";
            tex_a = "tex" + std::to_string(i) + "a";
          }
        }
      }
    }
    std::string ras_base = (s.colorchan == 1) ? "vColor1" : "vColor";
    std::string ras_c, ras_a;
    if (ras_swap) {
      static const char* kCh[4] = {"r", "g", "b", "a"};
      src += pfx + "vec3 ras" + std::to_string(i) + "c = vec3(" +
             ras_base + "." + kCh[ras_tab[0]] + ", " + ras_base + "." +
             kCh[ras_tab[1]] + ", " + ras_base + "." + kCh[ras_tab[2]] +
             ");\n";
      src += pfx + "float ras" + std::to_string(i) + "a = " + ras_base +
             "." + kCh[ras_tab[3]] + ";\n";
      ras_c = "ras" + std::to_string(i) + "c";
      ras_a = "ras" + std::to_string(i) + "a";
    } else {
      ras_c = ras_base + ".rgb";
      ras_a = ras_base + ".a";
    }
    int stage_unsupported_before = r.unsupported;
    auto color_expr = [&](int sel) -> std::string {
      switch (sel) {
        case 0: return "prev_c";
        case 1: return "vec3(prev_a)";
        case 2: return "regs_c0";
        case 3: return "vec3(regs_a0)";
        case 4: return "regs_c1";
        case 5: return "vec3(regs_a1)";
        case 6: return "regs_c2";
        case 7: return "vec3(regs_a2)";
        case 8: return tex_c;
        case 9: return "vec3(" + tex_a + ")";
        case 10: return ras_c;
        case 11: return "vec3(" + ras_a + ")";
        case 12: return "vec3(1.0)";
        case 13: return "vec3(0.5)";
        case 14: return tev_detail::KonstColorExpr(s.kcolor_sel, &r.unsupported);
        case 15: return "vec3(0.0)";
        default: ++r.unsupported; return "vec3(0.0)";
      }
    };
    auto alpha_expr = [&](int sel) -> std::string {
      switch (sel) {
        case 0: return "prev_a";
        case 1: return "regs_a0";
        case 2: return "regs_a1";
        case 3: return "regs_a2";
        case 4: return tex_a;
        case 5: return ras_a;
        case 6: return tev_detail::KonstAlphaExpr(s.kalpha_sel, &r.unsupported);
        case 7: return "0.0";
        default: ++r.unsupported; return "0.0";
      }
    };
    std::string ca = color_expr(s.color.a);
    std::string cb = color_expr(s.color.b);
    std::string cc = color_expr(s.color.c);
    std::string cd = color_expr(s.color.d);
    std::string aa = alpha_expr(s.alpha.a);
    std::string ab = alpha_expr(s.alpha.b);
    std::string ac = alpha_expr(s.alpha.c);
    std::string ad = alpha_expr(s.alpha.d);
    if (r.unsupported > stage_unsupported_before) {
      // KSEL fuera de enum en esta etapa: passthrough (el
      // contador ya subio en la resolucion; no duplicarlo).
      continue;
    }
    // Color.
    {
      const TevOp& op = s.color_op;
      std::string dst = op.out_reg == 0
                            ? "prev_c"
                            : ("regs_c" + std::to_string(op.out_reg - 1));
      if (op.op >= 8) {
        src += pfx + dst + " = " +
               tev_detail::CompColorExpr(ca, cb, cc, op.op) + ";\n";
      } else {
        std::string expr;
        if (op.op == 0) {
          expr = "mix(" + ca + ", " + cb + ", " + cc + ") + " + cd;
        } else {
          expr = "mix(" + ca + ", -(" + cb + "), " + cc + ") + " + cd;
        }
        if (op.bias != 0) expr += " + " + tev_detail::BiasExpr(op.bias);
        if (op.scale != 0) expr = "(" + expr + ") * " + tev_detail::ScaleExpr(op.scale);
        if (op.clamp != 0) expr = "clamp(" + expr + ", 0.0, 1.0)";
        src += pfx + dst + " = " + expr + ";\n";
      }
    }
    // Alfa (escalar; COMP alfa compara escalares).
    {
      const TevOp& op = s.alpha_op;
      std::string dst = op.out_reg == 0
                            ? "prev_a"
                            : ("regs_a" + std::to_string(op.out_reg - 1));
      if (op.op >= 8) {
        bool eq = (op.op % 2 == 1);
        const char* cmp = eq ? "==" : ">";
        src += pfx + dst + " = ((" + aa + " " + cmp + " " + ab + ") ? " +
               ac + " : 0.0);\n";
      } else {
        std::string expr;
        if (op.op == 0) {
          expr = "mix(" + aa + ", " + ab + ", " + ac + ") + " + ad;
        } else {
          expr = "mix(" + aa + ", -(" + ab + "), " + ac + ") + " + ad;
        }
        if (op.bias != 0) expr += " + " + tev_detail::BiasExpr(op.bias);
        if (op.scale != 0) expr = "(" + expr + ") * " + tev_detail::ScaleExpr(op.scale);
        if (op.clamp != 0) expr = "clamp(" + expr + ", 0.0, 1.0)";
        src += pfx + dst + " = " + expr + ";\n";
      }
    }
    ++r.stages_emitted;
  }
  // Alpha-compare: sobre el alfa FINAL (prev tras todas las
  // etapas), antes de asignar gl_FragColor.
  src += alpha_glsl.discard;
  src += "  gl_FragColor = vec4(prev_c, prev_a);\n";
  src += "}\n";
  r.fragment = src;
  r.ok = true;
  return r;
}

// Caché de programas TEV por hash (texto GLSL, sin GL): tope
// de 128 programas con eviccion del mas antiguo; si el tope
// se dispara en un frame, la causa probable es la clave
// (p. ej. konstantes que cambian por frame), no el generador.
class TevProgramCache {
 public:
  static constexpr size_t kMaxPrograms = 128;

  // Devuelve el GLSL del estado (genera en miss, reutiliza
  // en hit) y acumula contadores en stats si no es null.
  // La clave mezcla el hash TEV con el modo alpha-test (las
  // refs son uniforms y NO forman parte de la clave).
  const std::string& Get(const TevState& st, TevGenResult* stats,
                         const GxAlphaTest* alpha_test = nullptr) {
    uint32_t h = TevHash(st);
    int mode = 0;
    if (alpha_test != nullptr && alpha_test->present)
      mode = tev_detail::AlphaTestGlsl(*alpha_test).mode;
    uint32_t key = h ^ (static_cast<uint32_t>(mode) * 2654435761u);
    auto it = programs_.find(key);
    if (it != programs_.end()) {
      if (stats != nullptr) *stats = it->second.second;
      return it->second.first;
    }
    TevGenResult gen = GenerateTevFragment(st, alpha_test);
    if (programs_.size() >= kMaxPrograms && !order_.empty()) {
      programs_.erase(order_.front());
      order_.erase(order_.begin());
    }
    auto inserted = programs_.emplace(
        key, std::make_pair(gen.fragment, gen));
    order_.push_back(key);
    ++compiled_;
    if (stats != nullptr) *stats = gen;
    return inserted.first->second.first;
  }

  size_t Size() const { return programs_.size(); }
  uint64_t CompiledCount() const { return compiled_; }
  void Clear() {
    programs_.clear();
    order_.clear();
    compiled_ = 0;
  }

 private:
  std::map<uint32_t, std::pair<std::string, TevGenResult>> programs_;
  std::vector<uint32_t> order_;
  uint64_t compiled_ = 0;
};

}  // namespace sfa
