#pragma once

// Maquina de estado GX en host (Fase 5b, sin dependencias Android).
//
// Interpreta el stream FIFO GX (capturado de 0xCC008000, ver cpu.h)
// y el estado CP/XF/BP que lleva, mas las display lists leidas de
// RAM huesped. Solo lectura: no toca el estado del juego.
//
// Layouts verificados contra el propio stream (run19) y contra
// YAGCD (registros CP/XF/BP):
// - Comandos: 0x00 NOP (1 B), 0x08 CP (1+1+4), 0x10 XF (1+4+4n),
//   0x20/0x28/0x30/0x38 INDX (XF indexado, YAGCD 5.11.5.9:
//   1+2 indice +2 (longitud-1:4 bits, direccion:12 bits) +4n
//   datos; se parsea y cuenta, pero NO muta el mapa XF: su
//   direccionamiento indexado exacto no esta modelado y ningun
//   draw observado hasta ahora depende de el),
//   0x40 DL (1+4+4), 0x48 invalidar cache (1 B), 0x61 BP (1+4),
//   0x80-0xBF draw (1+2+vertices).
// - Desviaciones MEDIDAS del stream de la pelicula/titulo
//   (run42/46), NO reglas GX generales: el calculo aritmetico
//   VCD/VAT da un stride que NO reproduce los limites de
//   comando del stream para dos casos, y el parser usa el
//   stride medido (validado por periodicidad + limite limpio),
//   documentado en gx.cpp. Fuera de esos dos casos exactos
//   (prim+vat+stride aritmetico), rige la aritmetica VCD/VAT.
//   El "opcode desconocido 0x03" de la Fase 10 NO era un
//   opcode: era el 4o byte de un vertice de strip de 8 B,
//   alcanzado por sobre-consumir el draw como 21 B.
// - VAT: CP 0x70+vat (A), 0x80+vat (B), 0x90+vat (C). VAT_A:
//   POSCNT@0 (0=XY,1=XYZ), POSFMT@1-3 (0=U8,1=S8,2=U16,3=S16,
//   4=F32), POSSHFT@4-8, NRMCNT@9, NRMFMT@10-12, COL0CNT@13,
//   COL0FMT@14-16, COL1CNT@17, COL1FMT@18-20, TEX0CNT@21,
//   TEX0FMT@22-24, TEX0SHFT@25-29, BYTEDEQUANT@30,
//   NORMALINDEX3@31. VAT_B: TEX1CNT@0, TEX1FMT@1-3,
//   TEX1SHFT@4-8, TEX2CNT@9, TEX2FMT@10-12, TEX2SHFT@13-17,
//   TEX3CNT@18, TEX3FMT@19-21, TEX3SHFT@22-26, TEX4CNT@27,
//   TEX4FMT@28-30, VCACHE_ENHANCE@31. VAT_C: TEX5-7 analogos.
//   Formatos de color: 0=RGB565,1=RGB8,2=RGBX8,3=RGBA4,4=RGBA6,
//   5=RGBA8.
// - VCD (layout YAGCD 5.11.2, CORREGIDO en Fase 11: la version
//   anterior tenia los campos desplazados y run19 solo parseaba
//   por compensacion de dos errores): CP 0x50 (LO): PMIDX@0,
//   TnMIDX@1+n (1 bit cada uno), POS@9-10, NRM@11-12,
//   COL0@13-14, COL1@15-16. CP 0x60 (HI):
//   TEXn@2n (0=nada,1=directo,2=indice8,3=indice16).
//   Orden de componentes en el vertice: PMIDX, TnMIDX,
//   POS, NRM, CLR0, CLR1, TEX0-7. Los atributos indexados se
//   decodifican como indices (sin resolver contra arrays CP, que
//   el stream no trae): el draw queda marcado indexed y el
//   renderer lo salta, contado.
// - Posiciones enteras: el campo shift de VAT1 es 2 (bits 4-8) y
//   el quad de pantalla completa (0,0)-(10240,7680) solo cuadra
//   con la proyeccion orto + viewport del stream si el divisor
//   es 16, es decir 2^(shift+2). Se usa esa formula para S16/U16
//   (y analogamente para S8/U8 y texcoords enteras) y queda
//   marcada como validada solo para VAT1: si otro VAT dibuja,
//   hay que revalidarla (ver PORT-STATUS).
// - Texturas: el stream de esta fase NO trae registros BP de
//   textura (GXLoadTexObj esta HLEado y no los escribe). La
//   textura vigente de cada draw se resuelve con la lista
//   externa de cargas (offset FIFO -> texObj/mapa, la misma que
//   registra el HLE), no con BP. Direccion sin resolver ->
//   tex_obj = 0 (el renderer usa el placeholder magenta).
// - Display lists: se leen de RAM huesped via el lector que da
//   el llamador; profundidad maxima 4; un DL puede contener
//   draws y cambios de estado que afectan al estado posterior.

#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace sfa {

// Un vertice decodificado. Tramo 5: CLR1 y TEX1-7 ya no se
// descartan (el renderer TEV los necesita); s/t siguen siendo
// la coord 0 y tex_mtx_idx su indice (compatibilidad).
struct GxVertex {
  uint8_t pos_mtx_idx = 0;
  bool has_pos_mtx_idx = false;
  uint8_t tex_mtx_idx = 60;  // GX_IDENTITY si no viene en el vertice
  // Indice de matriz de textura por coord (TnMIDX del vertice;
  // 60 = identidad si el VCD no trae TnMIDX para esa coord).
  uint8_t tex_mtx_idx_arr[8] = {60, 60, 60, 60, 60, 60, 60, 60};
  // Atributos indexados (VCD 2 = indice8, 3 = indice16): el
  // parser guarda los indices, pero NO resuelve el atributo
  // (necesitaria base/stride CP 0xA0-0xBF + lector de RAM del
  // array); el draw queda marcado indexed y el renderer lo
  // salta (contado, no silencioso).
  bool has_pos_index = false;
  uint32_t pos_index = 0;
  bool has_tex_index = false;
  uint32_t tex_index = 0;
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
  float nx = 0.0f;
  float ny = 0.0f;
  float nz = 0.0f;
  bool has_normal = false;
  uint8_t r = 255;
  uint8_t g = 255;
  uint8_t b = 255;
  uint8_t a = 255;
  bool has_color = false;
  // CLR1 (segundo juego de colores; antes se decodificaba y
  // se tiraba). Sin CLR1 en el vertice: blanco opaco.
  uint8_t r1 = 255;
  uint8_t g1 = 255;
  uint8_t b1 = 255;
  uint8_t a1 = 255;
  bool has_color1 = false;
  float s = 0.0f;
  float t = 0.0f;
  bool has_tex = false;
  // TEX1-7 (antes solo se guardaba TEX0 en s/t). s/t siguen
  // siendo la coord 0; uv_s/uv_t[0] la duplican para que el
  // traductor recorra las 8 por igual.
  float uv_s[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  float uv_t[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  bool has_uv[8] = {false, false, false, false,
                    false, false, false, false};
};

// --- Estado TEV por draw (Fase TEV + Tramo 5, ver
// renderer/gx_tev.h). Anclaje Tramo 5: todo decodificado de
// palabras BP reales segun el codigo SDK recompilado
// (GXSetTevOrder 0x8025CA34, GXSetTevKColorSel 0x8025C790,
// GXSetTevKAlphaSel 0x8025C7FC, GXSetTevIndirect 0x8025BB58,
// GXSetTevColor 0x8025C634, GXSetTevKColor 0x8025C71C,
// GXSetTevSwapMode 0x8025C868, GXSetTevSwapModeTable
// 0x8025C8C0, GXSetTevAlphaIn 0x8025C430). Palabra ausente en
// bp_ => valor por defecto de GXInit (documentado en cada
// campo), que es lo que el HW real tendria: GXInit siempre
// corre antes del juego, asi que el defecto es medido, no
// inventado (TevOrder(i,255,255,255), KSEL 0, SwapModeTable
// 0=(0,1,2,3) 1=(0,0,0,3) 2=(1,1,1,3) 3=(2,2,2,3)).
//   color 0xC0+2*e: d[3:0] c[7:4] b[11:8] a[15:12]
//     bias[17:16] op-bit[18] clamp[19] scale[21:20] out[23:22]
//     (bias==3 => COMP, op = 8 + bit[18] + (scale<<1)).
//   alfa 0xC1+2*e: swap_ras[1:0] swap_tex[3:2]
//     d[6:4] c[9:7] b[12:10] a[15:13], misma op que color.
//     CORRECCION Tramo 5: la fase A asumia d[2:0] c[5:3]
//     b[8:6] a[11:9] (simetria con color); el SDK demuestra
//     d en 4-6, c en 7-9, b en 10-12, a en 13-15 y swap en
//     0-3 (GXSetTevSwapMode escribe las tablas ahi).
//   order 0x28+p (p = e/2): etapa par (mitad alta):
//     texmap[14:12] texcoord[17:15] presente[18]
//     canal[21:19]; etapa impar (mitad baja): texmap[2:0]
//     texcoord[5:3] presente[6] canal[9:7]. Sin presente,
//     texmap = 255 (NULL). Canal = CAMPO BP (0 = set 0,
//     1 = set 1, 7 = NULL), NO el enum GX (0,1,4,5,255):
//     el generador usa el campo (==1 => vColor1).
//   ksel 0xF6+p: etapa par: kcolor[18:14] kalpha[23:19];
//     impar: kcolor[8:4] kalpha[13:9]; bits 0-3 = datos de
//     swap table (ver abajo). KColorSel/KAlphaSel 0-7 =
//     constantes 1, 7/8, 3/4, 5/8, 1/2, 3/8, 1/4, 1/8;
//     8-11 = K0-K3 enteros; 12-27 = K por canal.
//   swap table t: bits 0-1 de 0xF6+2t, bits 2-3 de 0xF6+2t
//     (r, g), bits 0-1 de 0xF6+2t+1, bits 2-3 de 0xF6+2t+1
//     (b, a). Cada entrada = canal de entrada que alimenta
//     ese canal de salida (0=R, 1=G, 2=B, 3=A).
//   indirecto 0x10+e: indstage[1:0] formato[3:2]
//     bias[6:4] alpha[8:7] mtx[12:9] wrap_s[15:13]
//     wrap_t[18:16] bit19 add[21:20]. has_indirect = palabra
//     presente y != 0 (Direct escribe 0; un indirecto todo
//     a cero es indistinguible de Direct y equivale a el).
//   ind order 0x27: indN: texmap[3N+2:3N] texcoord[3N+5:3N+3].
//   konst/regcolor 0xE0+2*i / 0xE1+2*i: R[7:0] A[19:12] /
//     B[7:0] G[19:12]; bit 23 = 1 => KColor, 0 => TevColor.
//   GENMODE 0x00: texgens[3:0] etapas[13:10]+1 cull[15:14]
//     ind_etapas[18:16]; cull: 0=NONE 1=BACK 2=FRONT 3=ALL.
struct TevInput {
  int a = 0, b = 0, c = 0, d = 0;  // enums GX_CC (color) o GX_CA (alfa)
};
struct TevOp {
  int op = 0;       // 0=ADD, 1=SUB, 8-15=COMP (ver gx_tev.h)
  int bias = 0;     // 0=ZERO, 1=ADDHALF, 2=SUBHALF (solo ADD/SUB)
  int scale = 0;    // 0=x1, 1=x2, 2=x4, 3=/2 (solo ADD/SUB)
  int clamp = 0;    // 0=no, 1=sí (a [0,1])
  int out_reg = 0;  // 0=PREV, 1=REG0, 2=REG1, 3=REG2
};
struct TevStage {
  // Order: colorchan es el CAMPO BP (0/1/7), ver cabecera.
  int texcoord = 255, texmap = 255, colorchan = 255;
  TevInput color, alpha;
  TevOp color_op, alpha_op;
  int kcolor_sel = 0, kalpha_sel = 0;  // selectores K (0 = constante 1)
  int swap_ras = 0, swap_tex = 0;      // ids de tabla swap (0-3)
  bool has_indirect = false;
  int indstage = 0;
  int ind_format = 0, ind_bias = 0, ind_alpha = 0, ind_mtx = 0;
  int ind_wrap_s = 0, ind_wrap_t = 0, ind_add = 0;
  // Bit 19 de la palabra indirecta (byte bajo del 1er arg de
  // pila de GXSetTevIndirect): preservado, significado sin
  // asignar (no se usa en el generador).
  int ind_flag19 = 0;
  // Mapa/coord indirectos resueltos desde BP 0x27 (-1 si 0x27
  // ausente). Tramo 6: la perturbacion GLSL esta implementada
  // SOLO bajo el gate de IndPerturbGate (gx_tev.h: formato
  // ITF_8, alfa OFF, wrap OFF, add 0, matriz ind presente en
  // BP 0x06-0x0E y escalas de coord ITS_1); fuera del gate la
  // etapa sigue en no-op contado (indirect_noop) y se suma a
  // indirect_gated_out. Tramo 7B: el multiplicador de escala
  // SI se aplica, plegado en la matriz (2^scale_exp; campo
  // de 6 bits repartido en las 3 palabras BP, ver
  // DecodeIndTexMtxWords en gx_tev.h).
  int ind_texmap = -1, ind_texcoord = -1;
};
struct TevState {
  int num_stages = 1;
  int num_ind_stages = 0;
  TevStage stages[16];
  // K0..K3 y C0..C2 RGBA decodificados de BP 0xE0-0xE7
  // (0 si la palabra no esta presente). C3 no existe en el
  // generador (el juego usa C0-C2); regcolor[3] queda a 0.
  float konst[4][4] = {};
  float regcolor[4][4] = {};
  // Tablas swap por defecto = valores GXInit (ver cabecera).
  // Tramo 6: matrices indirectas decodificadas de BP
  // 0x06-0x0E (GXSetIndTexMtx 0x8025BBF4: 3 palabras por
  // matriz, 2 valores S11/1024 por palabra; CORRECCION
  // Tramo 7B: los campos [23:22] de las 3 palabras son
  // los trozos bits 1..0 / 3..2 / 5..4 de (scale_exp+17);
  // juntos forman scale_exp = S-17, guardado en
  // ind_mtx_scale; la exigencia Tramo 6 de campos
  // iguales rechazaba TODA matriz real del juego) y
  // escalas de coord indirecta de BP 0x25/0x26
  // (GXSetIndTexCoordScale 0x8025BD54: 4 bits por componente;
  // etapa 0/1 en 0x25, 2/3 en 0x26). Layout por matriz k:
  // [m00 m01 m02 m10 m11 m12] (fila 0 = m00,m01,m02).
  float ind_mtx_vals[3][6] = {};
  bool ind_mtx_present[3] = {false, false, false};
  int ind_mtx_scale[3] = {0, 0, 0};  // scale_exp (Tramo 7B)
  int ind_scale_s[4] = {0, 0, 0, 0};
  int ind_scale_t[4] = {0, 0, 0, 0};
  bool ind_scale_present[4] = {false, false, false, false};
  int swap_tables[4][4] = {{0, 1, 2, 3},
                           {0, 0, 0, 3},
                           {1, 1, 1, 3},
                           {2, 2, 2, 3}};
  // Copia cruda de bp_ en el momento del draw (reg -> valor24).
  std::map<uint32_t, uint32_t> bp_raw;
  bool order_anchored = true;  // Order decodificado de BP real
  bool ksel_anchored = true;   // KSEL decodificado de BP real
  bool truncated = false;      // num_stages BP > 16 (defensa)
  uint32_t hash = 0;           // clave de caché (ver gx_tev.h)
};

// --- Estado fijo GL por draw (Tramo 5, decodificado en
// renderer/gx_tev.h, funcion SnapshotFixedFromBp) ---
// Layouts anclados en codigo SDK recompilado (ver gx_tev.h):
//   blend 0x41 (GXSetBlendMode 0x8025CEF4): enable[0]
//     logic[1] color_update[3] alpha_update[4] dst[7:5]
//     src[10:8] subtract[11] op[15:12]. Bit 2 sin asignar
//     (posible dst-alpha, NO verificado: se ignora).
//     Factor: 0=ZERO 1=ONE 2=SRCCLR 3=INVSRCCLR 4=SRCALPHA
//     5=INVSRCALPHA 6=DSTALPHA 7=INVDSTALPHA.
//   z 0x40 (GXSetZMode 0x8025D078): enable[0] func[3:1]
//     update[4]. Func = enum compare (0=NEVER 1=LESS 2=EQUAL
//     3=LEQUAL 4=GREATER 5=NEQUAL 6=GEQUAL 7=ALWAYS).
//   alpha 0xF3 (GXSetAlphaCompare 0x8025C960, args
//     comp0/ref0/op/comp1/ref1): ref0[7:0] ref1[15:8]
//     comp0[18:16] comp1[21:19] op[23:22] (0=AND 1=OR 2=XOR
//     3=XNOR). CORRECCION Tramo 5: el resumen previo daba
//     op[9:8]/ref1[26:19]/comp1[24:22] (solapa ref1/comp1);
//     el asm prueba el empaquetado limpio de arriba: los
//     clears previos a cada campo coinciden exactamente con
//     su ancho (comp1 3 bits en 19-21, op 2 bits en 22-23).
//   scissor 0x20/0x21 (GXSetScissor 0x8025DC94):
//     0x20 = (x+342)<<12 | (y+342),
//     0x21 = (x+w-1+342)<<12 | (y+h-1+342).
//   fog 0xEE-0xF2: Tramo 6 decodificado (GXSetFog 0x8025CC44,
//     ver renderer/gx_tev.h: DecodeFogWords + FogStartEnd):
//     0xEE = campo C' (top 20 bits del float C/2^exp),
//     0xEF = mantisa entera de A (A_norm * 8388638.0),
//     0xF0 = exponente r30, 0xF1 = tipo[23:21] + campo B
//     (top 20 bits), 0xF2 = color RGB. A = far/(far-near),
//     B = start/(end-start),
//     C = far*near/((far-near)*(end-start)); start/end se
//     recuperan solo si se conocen near/far (típicamente los
//     de la proyección) y A es consistente con ellos.
//   copia 0x49/0x4A (+0x4B/0x4D en el evento): CORRECCION
//     Tramo 6 a la nota Tramo 5: el disparo NO va por MMIO
//     del PE, sino por el propio stream FIFO: GXCopyDisp
//     0x80259CA8 y GXCopyTex 0x80259E18 escriben SOLO en
//     0xCC008000 (FIFO) y la ultima palabra BP es el reg
//     0x52 con el bit 0x4000 (ejecutar) forzado; el parser
//     emite un GxCopy por cada escritura BP 0x52 (ver
//     GxParser::Copies()). La copia EFB completa (leer EFB,
//     filtrar, escribir XFB/textura) sigue pendiente: no hay
//     buffer EFB en el renderer.
struct GxBlendState {
  bool present = false;
  bool enable = false, logic = false, subtract = false;
  bool color_update = true, alpha_update = true;
  int src = 4, dst = 5, op = 0;
};
struct GxZState {
  bool present = false;
  bool enable = false, update = true;
  int func = 3;  // LEQUAL por defecto
};
struct GxAlphaTest {
  bool present = false;
  int comp0 = 7, ref0 = 0, comp1 = 7, ref1 = 0, op = 0;
};
struct GxScissorState {
  bool present = false;
  int x = 0, y = 0, w = 0, h = 0;  // ya sin el +342, en coords EFB
};
struct GxFixedState {
  GxBlendState blend;
  GxZState z;
  GxAlphaTest alpha;
  int cull = 0;  // campo GENMODE: 0=NONE 1=BACK 2=FRONT 3=ALL
  bool genmode_present = false;
  int num_texgens = 0;
  GxScissorState scissor;
  // Fog y copia: palabras crudas + presencia (sin aplicar).
  uint32_t fog_words[5] = {0, 0, 0, 0, 0};
  bool fog_present[5] = {false, false, false, false, false};
  uint32_t copy_words[3] = {0, 0, 0};  // 0x49, 0x4A, 0x4D
  bool copy_present[3] = {false, false, false};
  uint32_t ind_order_word = 0;
  bool ind_order_present = false;
};

// Un draw completo con el estado vigente en su offset.
struct GxDraw {
  uint32_t fifo_offset = 0;
  int prim = 0;  // opcode & 0xF8 (0x80 QUADS, 0x90 TRIANGLES, ...)
  int vat = 0;
  std::vector<GxVertex> verts;
  // Draws con vertices opacos (stride medido, contenido sin
  // decodificar: strips VAT2, ver gx.cpp): los bytes crudos
  // van aqui y verts queda vacio; el renderer los salta.
  bool has_raw_vertices = false;
  std::vector<uint8_t> raw_vertex_data;
  // True si algun vertice trae atributos indexados.
  bool indexed = false;
  uint32_t tex_obj = 0;  // 0 = sin resolver (placeholder)
  int tex_map = 0;
  // Tramo 5: ultima carga por mapa (map -> tex_obj, 0 = sin
  // carga para ese mapa). tex_obj/tex_map legacy = ultimo
  // mapa cargado (cualquier mapa), sin cambios.
  uint32_t tex_objs[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  // Estado vigente (copia en el momento del draw).
  float viewport[6] = {0, 0, 0, 0, 0, 0};
  bool has_viewport = false;
  float projection[6] = {0, 0, 0, 0, 0, 0};
  int projection_type = 0;  // 0 = perspectiva, 1 = orto
  bool has_projection = false;
  float pos_matrix[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
  // Instantánea TEV (Fase TEV): copia del estado BP vigente en
  // el momento del draw, rellenada en ParseDraw(). bp_ muta
  // con el stream, asi que leerlo al final del frame daria a
  // todos los draws la configuracion del ultimo. has_tev es
  // false solo en draws construidos a mano sin snapshot.
  TevState tev;
  bool has_tev = false;
  // Estado fijo (Tramo 5): mismo punto de snapshot que TEV.
  GxFixedState fixed;
  // Texgen XF por coord (GXSetTexCoordGen2: palabra 1 en
  // XF 0x1040+coord, palabra 2 en 0x1050+coord). has_texgen
  // false = XF sin esa palabra (sin texgen para la coord).
  // Tramo 6: palabra 1 = [src:10-7][hasMatrix:2]
  // [forma:1-0] (0 = MTX2x4, 2 = MTX3x4); palabra 2 =
  // (postmtx-64)[7:0] + normalize[8]. El id de matriz del
  // texgen (arg mtx de GXSetTexCoordGen2) va al shadow GX
  // +128/+132, NO a palabras XF: el parser no lo ve; la
  // matriz aplicada en traduccion es la TnMIDX del vertice
  // (60 = identidad), ver gx_translate.h. Tramo 7B: en el
  // traductor (GlTri) se aplican POS (src 0), NRM (src 1)
  // y TEX0-7 (src 5-12), forma 2x4/3x4, normalize 0, mas
  // la matriz post (postmtx != 125) si esta capturada en
  // post_matrices; normalize != 0, BINRM/TANGENT/COLOR y
  // post sin matriz capturada conservan UV directa.
  // Matrices post (dual texture, GXLoadTexMtxImm):
  // id -> 12 floats 3x4 de XF base 1280 + (id-64)*4,
  // capturadas en el momento del draw (igual que
  // tex_matrices). Ausencia = sin post (no se inventa).
  uint32_t texgen_w1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  uint32_t texgen_w2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  bool has_texgen[8] = {false, false, false, false,
                        false, false, false, false};
  // Matrices de textura (XF) para los indices TnMIDX
  // distintos usados por los vertices del draw (solo camino
  // normal; opacos/POINTS no las llevan porque el renderer
  // los salta igualmente). Indice 60 (identidad) no se
  // guarda: ausencia = identidad. 12 palabras en layout
  // 3x4 como PosMatrix (base indice*4; id >= 64: base
  // 1280 + (id-64)*4, segun GXLoadTexMtxImm). Palabras
  // ausentes = 0 (una matriz 2x4 de 8 palabras deja la
  // fila 3 a cero: sin division proyectiva, ver
  // gx_translate.h).
  std::map<int, std::vector<float>> tex_matrices;
  // Tramo 7B: matrices post por id (ver comentario arriba).
  std::map<int, std::vector<float>> post_matrices;
};

// Carga de textura externa (la que registra el HLE GXLoadTexObj).
// Evento de copia EFB (Tramo 6): una escritura BP 0x52 en el
// stream FIFO. Los regs 0x49/0x4A/0x4B/0x4D son los valores
// BP vigentes en ese momento (0x4B bajo = destino >> 5, ver
// GXCopyDisp: 0x4B = (dest>>5)&0xFFFFFF). Tramo 9: TODO
// evento 0x52 ejecuta una copia; el bit 14 (0x4000) es la
// CLASE de destino (1 = display/XFB, 0 = textura), no un
// gate (GXCopyTex 0x80259E18 no lo fuerza; GXCopyDisp
// 0x80259CA8 si). has_* = false si ese reg no se habia
// escrito antes del disparo. has52 = true solo en eventos
// producidos por el parser al ver un 0x52 real.
struct GxCopy {
  uint64_t fifo_offset = 0;
  bool has52 = false;
  uint32_t reg49 = 0, reg4a = 0, reg4b = 0, reg4d = 0, reg52 = 0;
  bool has49 = false, has4a = false, has4b = false, has4d = false;
  // Tramo 9: escala Y de copia BP 0x4E vigente en el disparo
  // (GXSetDispCopyYScale 0x80259928: valor = yscale_int de 9
  // bits; bit 10 de 0x52 = (256 - yscale_int) > 0). Sin 0x4E
  // previo, has4e = false y la escala es desconocida.
  uint32_t reg4e = 0;
  bool has4e = false;
  // Tramo 11: escritura BP 0x00 vigente en el disparo. La
  // libreria GX emite por FIFO las palabras de estado
  // +472/+476 SIN byte de registro (stb 0x61 + stw del valor
  // crudo: GXCopyTex 0x80259E18, GXCopyDisp 0x80259CA8,
  // GXPixModeSync 0x80258E30), asi que aparecen como BP
  // 0x00; +476 es PE_CONTROL (YAGCD 0x43: bits 0-2 formato
  // de pixel, 3-5 formato Z, 6 Z comp loc). GXCopyTex
  // fuerza bits 0-2 = 3 (Z24) cuando el fmt de copia tiene
  // bit 4 (fmt 17/19) y lo emite justo antes de la copia:
  // en traza run39, las 23 copias fmt 0x11 van precedidas
  // de `61 00 000003` y las RGB565 de `61 00 000000`.
  // reg00/has00 es ese valor: (reg00 & 7) == 3 distingue
  // una copia Z8 de una copia I8 de color, que en FIFO son
  // identicas (misma geometria 8x4/32 B). Misma robustez
  // que reg53/54/4e (mismo mecanismo bp_); sin 0x00 previo
  // has00 = false y la copia NO se trata como Z (rechazo
  // conservador, nunca bytes inventados).
  // reg00_adjacent: true SOLO si entre esa escritura 0x00
  // y este disparo no hubo ningun draw ni llamada a DL
  // (es decir, la escritura pertenece al propio grupo de
  // emision de este GXCopyTex, que emite 0x00, 0x49, 0x4A,
  // 0x4D, 0x4B y 0x52 contiguos). Sin adyacencia, un valor
  // 3 heredado de una copia Z anterior o de un material
  // no puede marcar esta copia: la regla Z exige
  // adyacencia (ver efb_copy.h). El flag se consume con
  // cada disparo (una copia Z no marca a la siguiente).
  uint32_t reg00 = 0;
  bool has00 = false;
  bool reg00_adjacent = false;
  // Tramo 8: filtro de copia BP 0x53/0x54 vigente en el
  // disparo (GXSetCopyFilter 0x80259A64; YAGCD: 0x53/0x54
  // = copy filter). Valores crudos, sin decodificar a
  // coeficientes: el empaquetado de GXSetCopyFilter (7
  // bytes vfilter -> 2 palabras, o defecto 0x595000 /
  // 0x000015 si vfilter es nulo) no esta invertido del
  // todo; el censo Tramo 8 los mide, no los interpreta.
  uint32_t reg53 = 0, reg54 = 0;
  bool has53 = false, has54 = false;
};

struct GxTexLoad {
  uint64_t fifo_offset = 0;
  uint32_t tex_obj = 0;
  int map = 0;
};

// Decodificador de copia EFB (Tramo 7B, corregido Tramo 9,
// puro: sin EFB, sin escritura en RAM; la copia de pixeles
// vive en renderer/efb_copy.h). Grado de evidencia por campo
// (no mezclar lo probado con lo supuesto):
//  - CORRECCION Tramo 9 (bit 14): NO es un "execute gate".
//    GXCopyDisp 0x80259CA8 fuerza bit 14 (ori 0x4000) y
//    GXCopyTex 0x80259E18 NO lo pone: su palabra final es
//    la sombra 0x1fc sin bit 14. YAGCD: bit 14 "execute ?
//    (1: to XFB 0: to texture ?!)". Conclusion: TODA
//    escritura 0x52 ejecuta una copia; bit 14 = clase de
//    destino (1 = display/XFB, 0 = textura). La lectura
//    Tramo 7/8 ("sin exec = control, no copia") queda
//    REFUTADA: las 782 copias "sin exec" del censo son
//    copias reales a textura via GXCopyTex. El campo
//    `execute` se conserva por compatibilidad y vale siempre
//    true para un evento parseado (un GxCopy solo existe
//    por una escritura 0x52); usar `is_disp` en su lugar.
//  - dest_guest: PROBADO (reconstruccion). GXCopyDisp
//    escribe 0x4B = (dest>>5)&0xFFFFFF (rlwinm+oris);
//    para RAM MEM1 (0x80000000-0x81800000) el bit
//    perdido es el bit 31: dest = 0x80000000|(reg<<5).
//    Verificado: 0x020000->0x80400000, 0x0252A8->
//    0x804A5500 (doble buffer XFB alternante en run19),
//    0x0Bxxxx->0x816xxxxx (dentro de ram.bin 24 MB).
//  - width/height: PROBADO por 3 valores independientes.
//    0x4A = ((h-1)<<10)|(w-1): 0x077E7F = 640x480,
//    0x007C1F = 32x32, 0x00EC4F = 80x60.
//  - stride_bytes: CONVENCION GX (reg x 32). Display:
//    pitch lineal (0x28 -> 1280 B XFB 640). Textura: bytes
//    por fila de tiles (ver PlanTexCopy en efb_copy.h).
//  - src_x/src_y: PROVISIONAL (convencion GX, 10 bits
//    cada uno, mismo estilo que 0x4A). En TODAS las
//    trazas reg49 = 0 (origen (0,0)): sin contraejemplo
//    ni confirmacion independiente.
//  - bit16_marker (antes tex_dest_hint): correlacion
//    perfecta en trazas (26.233 copias: bit 16 a 1 <=>
//    destinos 0x0Bxxxx textura; a 0 <=> XFB), con origen
//    SIN LOCALIZAR (Tramo 9: descartados path A de
//    GXSetTexCopyDst, arg2 de GXCopyTex y GXSetCopyClamp;
//    escaneo completo de escrituras a 0x1fc en el DOL).
//    El puerto no necesita el origen: lee palabras FIFO.
//  - low52: DECODIFICADO Tramo 9 (ver efb_copy.h):
//    bits 0-1 clamp, 3-6 formato textura (permutado),
//    7-8 gamma (YAGCD, crudo), 9 mipmap (textura),
//    10 escala Y (display), 11 clear, 12-13 Frame2Field.
//    El filtro NO va en low52: va en BP 0x53/0x54
//    (GXSetCopyFilter 0x80259A64; Tramo 9: taps
//    decodificados exactos, ver DecodeCopyFilter).
struct EfbCopyDecoded {
  bool execute = false;  // Tramo 9: siempre true (ver arriba).
  bool is_disp = false;  // Tramo 9: bit 14 (1 = XFB, 0 = tex).
  bool has_dest = false;
  uint32_t dest_guest = 0;
  bool has_size = false;
  int width = 0, height = 0;
  bool has_stride = false;
  int stride_bytes = 0;
  bool has_src = false;
  int src_x = 0, src_y = 0;
  bool tex_dest_hint = false;  // Tramo 9: alias de bit16_marker.
  bool bit16_marker = false;  // Tramo 9: bit 16.
  uint32_t low52 = 0;
  // Tramo 8: filtro vigente (crudo, ver GxCopy).
  bool has_filter = false;
  uint32_t filter53 = 0, filter54 = 0;
  // Tramo 9: escala Y BP 0x4E vigente (si se capturo).
  bool has_yscale = false;
  int yscale_int = 0;  // 9 bits; flag bit10 = (256 - x) > 0.
  // Tramo 11: PE_CONTROL vigente (BP 0x00, ver GxCopy).
  // bits 0-2 == 3 (Z24) + fmt_low 1 + adyacencia = copia Z8
  // (fmt 17). Sin adyacencia no hay Z aunque el valor sea 3.
  bool has_pe_ctrl = false;
  uint32_t pe_ctrl = 0;
  bool pe_ctrl_adjacent = false;
};

inline EfbCopyDecoded DecodeEfbCopy(const GxCopy& c) {
  EfbCopyDecoded d;
  // Tramo 9: todo evento 0x52 ejecuta una copia (ver arriba);
  // bit 14 = clase de destino, no gate de ejecucion. Un
  // GxCopy sin palabra 0x52 (construido a mano, nunca por el
  // parser) no es un evento de copia: execute = false.
  d.execute = c.has52;
  d.is_disp = (c.reg52 & 0x4000u) != 0;
  d.tex_dest_hint = (c.reg52 & 0x10000u) != 0;
  d.bit16_marker = d.tex_dest_hint;
  d.low52 = c.reg52 & 0x3FFFu;
  if (c.has4b) {
    d.has_dest = true;
    // reg4b es de 24 bits; <<5 cabe en 29 bits y la base
    // MEM1 restaura el bit 31 perdido (ver arriba).
    d.dest_guest =
        0x80000000u + ((c.reg4b & 0xFFFFFFu) << 5);
  }
  if (c.has4a) {
    d.has_size = true;
    d.width = static_cast<int>(c.reg4a & 0x3FFu) + 1;
    d.height = static_cast<int>((c.reg4a >> 10) & 0x3FFu) + 1;
  }
  if (c.has4d) {
    d.has_stride = true;
    d.stride_bytes = static_cast<int>(c.reg4d & 0xFFFFFFu) * 32;
  }
  if (c.has49) {
    d.has_src = true;
    d.src_x = static_cast<int>(c.reg49 & 0x3FFu);
    d.src_y = static_cast<int>((c.reg49 >> 10) & 0x3FFu);
  }
  if (c.has53 && c.has54) {
    d.has_filter = true;
    d.filter53 = c.reg53;
    d.filter54 = c.reg54;
  }
  if (c.has4e) {
    d.has_yscale = true;
    d.yscale_int = static_cast<int>(c.reg4e & 0x1FFu);
  }
  if (c.has00) {
    d.has_pe_ctrl = true;
    d.pe_ctrl = c.reg00;
    d.pe_ctrl_adjacent = c.reg00_adjacent;
  }
  return d;
}

// --- Plan de copia EFB (Tramo 8, corregido Tramo 9) ---
//
// La copia de pixeles tiene dos partes separables:
// (a) el trazado de filas (independiente del formato:
//     origen fila a fila, destino con pitch = stride),
//     implementado aqui y probado en host; (b) la
//     conversion de formato + filtro, implementada en
//     renderer/efb_copy.h (formato low52 y taps 0x53/0x54
//     decodificados Tramo 9; YUY2/RGB565/RGBA8/tiled).
// PlanEfbCopy es el plan LINEAL (display/XFB): exige
// is_disp (Tramo 9: el plan lineal es geometricamente
// incorrecto para texturas, que van en tiles; una copia
// a textura debe planearse con PlanTexCopy en efb_copy.h,
// no con esta funcion). Correccion Tramo 9: el antiguo
// requisito `execute` (bit 14) se sustituye por is_disp:
//   - una copia a textura real (bit 14 = 0) ya NO se
//     rechaza como "sin exec": se rechaza aqui por ser
//     textura (plan lineal no aplicable) y se acepta en
//     PlanTexCopy;
//   - una palabra 0x000C00 (destino XFB con bit 14 = 0,
//     inconsistente: clase textura + destino XFB) sigue
//     rechazada, ahora por clase, no por "falta de exec".
// Sin destino/tamano/stride, destino fuera de MEM1
// (0x80000000-0x81800000), stride menor que la fila, o
// copia que excede la RAM dada -> false.
// CopyEfbRows copia filas con pitches distintos
// (src_pitch, dst_pitch = stride): el nucleo de (a).
struct EfbCopyPlan {
  uint32_t dest_offset = 0;  // dest_guest - 0x80000000
  int row_bytes = 0;
  int total_bytes = 0;
};

inline bool PlanEfbCopy(const EfbCopyDecoded& d, uint32_t ram_size,
                        int bytes_per_pixel, EfbCopyPlan* plan) {
  if (plan == nullptr) return false;
  if (!d.is_disp || !d.has_dest || !d.has_size || !d.has_stride)
    return false;
  if (d.dest_guest < 0x80000000u ||
      d.dest_guest >= 0x81800000u)
    return false;
  if (d.width <= 0 || d.height <= 0 || bytes_per_pixel <= 0)
    return false;
  int row = d.width * bytes_per_pixel;
  if (d.stride_bytes < row) return false;
  uint32_t off = d.dest_guest - 0x80000000u;
  uint64_t total =
      static_cast<uint64_t>(d.stride_bytes) *
      static_cast<uint64_t>(d.height - 1) +
      static_cast<uint64_t>(row);
  if (off + total > ram_size) return false;
  plan->dest_offset = off;
  plan->row_bytes = row;
  plan->total_bytes = static_cast<int>(total);
  return true;
}

inline bool CopyEfbRows(const uint8_t* src, int src_pitch,
                        uint8_t* dst, int dst_pitch, int row_bytes,
                        int height) {
  if (src == nullptr || dst == nullptr) return false;
  if (src_pitch < row_bytes || dst_pitch < row_bytes ||
      row_bytes <= 0 || height <= 0)
    return false;
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < row_bytes; ++x)
      dst[static_cast<size_t>(y) * dst_pitch + x] =
          src[static_cast<size_t>(y) * src_pitch + x];
  }
  return true;
}

struct GxStats {
  uint64_t total_bytes = 0;
  uint64_t n_nop = 0;
  uint64_t n_cp = 0;
  uint64_t n_xf = 0;
  uint64_t n_indx = 0;  // comandos XF indexados 0x20-0x38
  uint64_t n_bp = 0;
  uint64_t n_dl = 0;
  uint64_t n_dl_skipped = 0;  // DL sin lector valido: 9 B, sin
                              // contenido (ver ParseStream)
  uint64_t n_inv = 0;
  uint64_t n_draw = 0;
  uint64_t dl_bytes = 0;
  uint64_t indexed_attrs = 0;  // vertices con atributo indexado
  uint64_t n_opaque_draws = 0;  // draws con stride medido
  uint64_t n_indexed_draws = 0;  // draws con algun indice
  std::map<int, uint64_t> draws_by_prim;
  std::map<int, uint64_t> draws_by_vat;
};

class GxParser {
 public:
  // Lector de RAM huesped: devuelve puntero a size bytes en guest,
  // o nullptr si fuera de rango. Solo se usa para display lists.
  using RamReader =
      std::function<const uint8_t*(uint32_t guest, uint32_t size)>;

  GxParser();

  void SetRamReader(RamReader reader) { ram_reader_ = reader; }
  // Copia y ordena por offset FIFO (el HLE las registra en orden,
  // pero se ordena aqui para que la busqueda sea valida siempre).
  void SetTexLoads(const std::vector<GxTexLoad>& loads);

  // Parsea todo el stream. Devuelve false si se detiene en un
  // opcode desconocido o un vertice truncado (ver FirstUnknown()
  // y Stats()). Un DL sin lector valido NO detiene el parse:
  // se salta (n_dl_skipped). Los atributos indexados
  // ya NO detienen el parse: se guardan los indices y el draw
  // queda marcado indexed.
  bool Parse(const uint8_t* fifo, size_t fifo_len);

  // Alimentacion incremental (Fase 11, APK): el estado CP/XF/BP
  // persiste entre llamadas; solo se emiten los draws de
  // comandos completos y el resto incompleto queda pendiente
  // para el siguiente Feed. base_offset es el offset FIFO
  // global del primer byte de data (para que los draws y las
  // texloads sigan siendo comparables tras drenar la captura).
  // Devuelve false si el stream se desincroniza (opcode
  // desconocido / DL ilegible): en ese caso el llamador debe
  // descartar el estado con ResetFeed() (el juego reescribe
  // VCD/VAT/XF cada frame, asi que el estado se restablece).
  // ResetFeed() deja el parser listo para un stream nuevo.
  void ResetFeed();
  bool Feed(const uint8_t* data, size_t len, uint64_t base_offset);
  // Draws emitidos por el ultimo Feed (se vacia en cada Feed).
  std::vector<GxDraw> TakeFedDraws();
  // Tramo 10: copias EFB emitidas por el ultimo Feed (se
  // vacia en cada TakeFedCopies). Espejo de fed_draws_:
  // cada escritura BP 0x52 anade el evento tanto a copies_
  // (acumulado historico, usado por tests/censos via
  // Copies()) como a fed_copies_ (drenaje por frame para
  // Frame()). Sin este drenaje, Frame() no podria ejecutar
  // las copias del frame sin reprocesar todo el historico.
  std::vector<GxCopy> TakeFedCopies();
  // Anade cargas de textura sin reordenar (el llamador las
  // entrega en orden creciente de offset, como las registra
  // el HLE). Para stream completo, usar SetTexLoads().
  void AppendTexLoads(const std::vector<GxTexLoad>& loads);

  const std::vector<GxDraw>& Draws() const { return draws_; }
  // Eventos de copia EFB del stream (Tramo 6, uno por BP 0x52).
  const std::vector<GxCopy>& Copies() const { return copies_; }
  const GxStats& Stats() const { return stats_; }
  const std::map<uint32_t, uint32_t>& CpRegs() const { return cp_; }
  const std::map<uint32_t, uint32_t>& BpRegs() const { return bp_; }
  // Viewport (XF 0x101A) y proyeccion (XF 0x1020) finales.
  bool Viewport(float out[6]) const;
  bool Projection(float out[6], int* type) const;
  // Matriz de posicion XF (indice 0-63) final, o identidad si no
  // se cargo.
  void PosMatrix(int index, float out[12]) const;
  // Primer problema: offset, opcode y contexto en hex.
  std::string FirstUnknown() const { return first_unknown_; }

  // Tamano de vertice directo para un VAT con el VCD vigente.
  // Devuelve 0 si el VAT usa atributos indexados o desconocidos.
  uint32_t VertexSize(int vat) const;

 private:
  // Resultado de ParseStream: kDone (stream completo), kTrunc
  // (el ultimo comando esta incompleto: consumed marca su
  // inicio y el resto queda pendiente), kFailed (ver
  // first_unknown_).
  enum class StreamResult { kDone, kTrunc, kFailed };

  struct VatFmt {
    int pos_count = 0;  // 0 = XY, 1 = XYZ
    int pos_type = 0;
    int pos_shift = 0;
    int nrm_count = 0;  // 0 = normal(3), 1 = NBT(9)
    int nrm_type = 0;
    int col0_count = 0;  // 0 = RGB, 1 = RGBA
    int col0_type = 0;
    int col1_count = 0;
    int col1_type = 0;
    int tex_count[8] = {0, 0, 0, 0, 0, 0, 0, 0};  // 0 = S, 1 = ST
    int tex_type[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int tex_shift[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  };

  StreamResult ParseStream(const uint8_t* data, size_t len, bool in_dl,
                           int depth, uint64_t base_offset,
                           size_t* consumed_io);
  bool ParseDraw(const uint8_t* data, size_t len, size_t* pos_io,
                 int prim, int vat, uint64_t fifo_offset);
  bool DecodeVertex(const uint8_t* data, size_t avail, int vat,
                    uint32_t* consumed, GxVertex* out) const;
  VatFmt VatFormat(int vat) const;
  // Decodifica un componente entero/flotante. Devuelve false si
  // no hay bytes suficientes.
  bool ReadComp(const uint8_t* data, size_t avail, size_t* off, int type,
                int shift, float* out) const;
  bool ReadColor(const uint8_t* data, size_t avail, size_t* off,
                 int type, int count, GxVertex* out) const;
  uint32_t TexLoadFor(uint64_t fifo_offset) const;
  int TexMapFor(uint64_t fifo_offset) const;
  // Ultima carga por mapa (map -> tex_obj, 0 si no hay carga
  // para ese mapa en offset <= fifo_offset).
  void TexLoadsFor(uint64_t fifo_offset, uint32_t out[8]) const;

  RamReader ram_reader_;
  std::vector<GxTexLoad> tex_loads_;
  std::vector<GxDraw> draws_;
  std::vector<GxCopy> copies_;
  std::vector<GxCopy> fed_copies_;  // Tramo 10: drenaje por Feed.
  GxStats stats_;
  std::map<uint32_t, uint32_t> cp_;
  std::map<uint32_t, uint32_t> bp_;
  std::map<uint32_t, std::vector<uint32_t>> xf_;  // addr -> palabras
  std::string first_unknown_;
  bool failed_ = false;
  // True si el ultimo fallo de ParseDraw fue solo falta de
  // bytes (comando incompleto al final del buffer), no un
  // error real: ParseStream lo traduce a kTrunc.
  bool trunc_ = false;
  // Estado incremental (Feed): bytes pendientes del comando
  // incompleto, base FIFO global del stream actual y draws del
  // ultimo Feed. stream_base_ es la base del ParseStream en
  // curso (0 en Parse() completo; base_offset en Feed()).
  std::vector<uint8_t> pending_;
  uint64_t feed_base_ = 0;
  uint64_t stream_base_ = 0;
  std::vector<GxDraw> fed_draws_;
};

}  // namespace sfa
