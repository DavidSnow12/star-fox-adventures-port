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
//    de entrada son de 3 bits (enum GX_CA). SU POSICION
//    EXACTA es simetria asumida (d[2:0], c[5:3], b[8:6],
//    a[11:9]), PENDIENTE del anclaje §3.3 del diseño: si el
//    anclaje la corrige, cambia solo DecodeAlphaWord.
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
//  - PREV inicial y registros C0-C2: (0,0,0) / 0.0.
//  - RASC/RASA: color de vertice. Canal 0/4 (COLOR0[A0]) ->
//    varying vColor; canal 1/5 (COLOR1[A1]) -> vColor1. El
//    vertex shader actual no entrega ninguno: el camino GL
//    de gx_gl.cpp solo usa el programa TEV cuando no hace
//    falta color de vertice (ver TevGlUsable); el resto cae
//    al programa fijo anterior con log (GX-RESTO.md P0.3
//    pendiente: varyings de color + UV por mapa).
//  - Order/KSEL/indirecto/konst/regcolor del snapshot: NO
//    anclados (ver gx.h). El generador confia en lo que
//    TevState dice; un TevState construido a mano con esos
//    campos explicitos genera el GLSL completo (casos
//    dorados del diseño §4).

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

// Decodifica una palabra alfa BP. Campos de 3 bits en simetria
// asumida con la palabra color (ver cabecera: pendiente de
// anclaje). Operacion: misma estructura de bits que color.
inline void DecodeAlphaWord(uint32_t w, TevInput* in, TevOp* op) {
  in->d = static_cast<int>(w & 0x7);
  in->c = static_cast<int>((w >> 3) & 0x7);
  in->b = static_cast<int>((w >> 6) & 0x7);
  in->a = static_cast<int>((w >> 9) & 0x7);
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
  for (int i = 0; i < 16; ++i) {
    const TevStage& s = st.stages[i];
    mix(static_cast<uint32_t>(s.texcoord));
    mix(static_cast<uint32_t>(s.texmap));
    mix(static_cast<uint32_t>(s.colorchan));
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
// draw (lo llama GxParser::ParseDraw). Copia bp_raw completo
// y decodifica GENMODE + palabras color/alfa. Order: sin
// anclar -> heuristica documentada texcoord=texmap=etapa
// (coincide con el caso dorado UI 2 etapas; NO garantizada
// para mundo) con order_anchored=false. KSEL: sin anclar ->
// sel 0 (constante 1) con ksel_anchored=false; la palabra
// cruda 0xF6+etapa queda en bp_raw para el anclaje futuro.
// Konst/regcolor: sin anclar -> 0. Palabra de etapa ausente
// en bp_ (etapa dentro de num_stages pero sin escritura
// previa): etapa identidad (devuelve PREV), no basura.
inline TevState SnapshotTevFromBp(
    const std::map<uint32_t, uint32_t>& bp) {
  TevState st;
  st.bp_raw = bp;
  st.order_anchored = false;
  st.ksel_anchored = false;
  st.truncated = false;
  auto get = [&](uint32_t reg, uint32_t* out) {
    auto it = bp.find(reg);
    if (it == bp.end()) return false;
    *out = it->second;
    return true;
  };
  uint32_t genmode = 0;
  if (get(0x00, &genmode)) {
    st.num_stages = static_cast<int>(((genmode >> 10) & 0xF) + 1);
  } else {
    st.num_stages = 1;
  }
  if (st.num_stages < 1) st.num_stages = 1;
  if (st.num_stages > 16) {
    st.num_stages = 16;
    st.truncated = true;
  }
  for (int i = 0; i < 16; ++i) {
    TevStage& s = st.stages[i];
    s.texcoord = i;
    s.texmap = i;
    s.colorchan = 255;
    s.kcolor_sel = 0;
    s.kalpha_sel = 0;
    s.swap_ras = 0;
    s.swap_tex = 0;
    s.has_indirect = false;
    s.indstage = 0;
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

}  // namespace tev_detail

// Genera el fragment shader GLSL ES 1.00 de un TevState.
// Tolerante por etapa (TEV-DESIGN.md §6): un input/op/ksel
// fuera de enum en UNA etapa deja esa etapa en passthrough
// y sube unsupported, sin tumbar el resto del shader ni el
// frame. Solo falla (ok=false) si num_stages < 1; num_stages
// > 16 se trunca a 16 con marca (defensa ante stream
// corrupto). ValidateTevState sigue siendo el chequeo
// estricto para quien lo quiera (tests de estructura).
inline TevGenResult GenerateTevFragment(const TevState& st_in) {
  TevGenResult r;
  r.hash = TevHash(st_in);
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
    bool chan1 = (s.colorchan == 1 || s.colorchan == 5);
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
    src += "varying vec2 vUv" + std::to_string(m) + ";\n";
  }
  src += "uniform vec3 uRegC0;\nuniform vec3 uRegC1;\nuniform vec3 uRegC2;\n";
  src += "uniform float uRegA0;\nuniform float uRegA1;\nuniform float uRegA2;\n";
  src += "uniform vec4 uKonst0;\nuniform vec4 uKonst1;\nuniform vec4 uKonst2;\nuniform vec4 uKonst3;\n";
  if (r.needs_color) src += "varying vec4 vColor;\n";
  if (r.needs_color1) src += "varying vec4 vColor1;\n";
  src += "void main() {\n";
  src += "  vec3 prev_c = vec3(0.0);\n  float prev_a = 0.0;\n";
  src += "  vec3 regs_c0 = vec3(0.0);\n  vec3 regs_c1 = vec3(0.0);\n  vec3 regs_c2 = vec3(0.0);\n";
  src += "  float regs_a0 = 0.0;\n  float regs_a1 = 0.0;\n  float regs_a2 = 0.0;\n";

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
    std::string pfx = "  ";  // cuerpo de main
    std::string tex_c, tex_a;
    if (uses_tex_c || uses_tex_a) {
      if (s.texmap == 255) {
        tex_c = "vec3(0.0)";
        tex_a = "0.0";
      } else {
        std::string smp = "texture2D(uTex" + std::to_string(s.texmap) +
                          ", vUv" + std::to_string(s.texmap) + ")";
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
    std::string ras_c = (s.colorchan == 1 || s.colorchan == 5)
                            ? "vColor1.rgb"
                            : "vColor.rgb";
    std::string ras_a = (s.colorchan == 1 || s.colorchan == 5)
                            ? "vColor1.a"
                            : "vColor.a";
    int stage_unsupported_before = r.unsupported;
    auto color_expr = [&](int sel) -> std::string {
      switch (sel) {
        case 0: return "prev_c";
        case 1: return "vec3(prev_a)";
        case 2: return "uRegC0";
        case 3: return "vec3(uRegA0)";
        case 4: return "uRegC1";
        case 5: return "vec3(uRegA1)";
        case 6: return "uRegC2";
        case 7: return "vec3(uRegA2)";
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
        case 1: return "uRegA0";
        case 2: return "uRegA1";
        case 3: return "uRegA2";
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
  const std::string& Get(const TevState& st, TevGenResult* stats) {
    uint32_t h = TevHash(st);
    auto it = programs_.find(h);
    if (it != programs_.end()) {
      if (stats != nullptr) *stats = it->second.second;
      return it->second.first;
    }
    TevGenResult gen = GenerateTevFragment(st);
    if (programs_.size() >= kMaxPrograms && !order_.empty()) {
      programs_.erase(order_.front());
      order_.erase(order_.begin());
    }
    auto inserted = programs_.emplace(
        h, std::make_pair(gen.fragment, gen));
    order_.push_back(h);
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
