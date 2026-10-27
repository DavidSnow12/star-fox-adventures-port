#pragma once

// Plan de ejecucion entrelazada draws/copias por fifo_offset
// (Tramo 11, puro: sin GL, sin RAM, sin parser). Frame()
// lo usa para ejecutar las copias a textura EN EL MISMO
// frame que los draws que las preceden (antes: todas las
// copias se ejecutaban tras todos los draws, asi que una
// textura copiada en este frame solo estaba disponible
// para los draws del frame siguiente).
//
// Entrada: dos listas YA ordenadas por fifo_offset de forma
// estable (el parser las entrega en orden FIFO; Frame()
// aplica stable_sort defensivo antes de llamar: con la
// entrada bien formada es no-op). Los offsets de draw son
// uint32 (truncados en ParseDraw) y los de copia uint64;
// se comparan como uint64 (el truncado solo envuelve tras
// ~4 GiB de FIFO acumulado, muy por encima de un frame).
//
// Regla de empate: DRAWS ANTES QUE COPIAS (<= para draws).
// Motivo: los draws y copias dentro de una misma display
// list comparten el offset del punto de llamada (in-DL
// fifo_offset = base_offset), asi que un empate no ordena
// por si solo; las copias observadas en trazas son de fin
// de frame (tras todos los draws) y no hay copias dentro
// de DL observadas, asi que draws-antes-copias reproduce
// el orden real en todos los casos vistos y es la opcion
// conservadora dentro de un DL (una copia suele copiar lo
// que los draws anteriores del mismo DL acaban de dibujar).
// Si algun dia aparece una copia dentro de DL ANTES de sus
// draws, el remedio es un numero de secuencia del parser
// (unas lineas, no una reescritura), no cambiar esta regla
// a ciegas.
//
// Salida: segmentos contiguos sobre las listas ordenadas.
// Un segmento de draws se ejecuta con UN DrawGxFrame y un
// segmento de copias con UN CopyEfbCopies: el numero de
// llamadas es (n_segmentos), no (n_draws + n_copias).
// Casos sin regresion por construccion:
//  - sin copias: un unico segmento de draws = el DrawGxFrame
//    unico de antes (orden identico).
//  - sin draws: solo segmentos de copias = el CopyEfbCopies
//    unico de antes.
//  - copias todas tras los draws (caso observado en trazas):
//    un segmento de draws + segmentos de copias = el orden
//    antiguo exacto.
// Coste del segmentado: cada DrawGxFrame re-resuelve sus
// texturas (frame_tex es local por llamada) y cada
// DrawDraws invalida la cache de readback EFB (correcto:
// el contenido del FBO cambia); copias consecutivas sin
// draws entre medias comparten una sola lectura.

#include <cstddef>
#include <cstdint>
#include <vector>

namespace sfa {

// Un segmento del plan: [begin, end) sobre la lista
// ordenada de draws (is_copy = false) o de copias
// (is_copy = true). Los indices son posiciones en las
// listas de entrada, no offsets FIFO.
struct GxSegment {
  bool is_copy = false;
  size_t begin = 0;
  size_t end = 0;
};

// Calcula el plan entrelazado. Las listas deben venir
// ordenadas por fifo_offset (estable); si no lo estan, el
// plan sigue siendo determinista pero no corresponde al
// orden FIFO real (el llamador debe ordenar antes).
inline std::vector<GxSegment> GxMergeSegments(
    size_t n_draws, const uint64_t* draw_off, size_t n_copies,
    const uint64_t* copy_off) {
  std::vector<GxSegment> segs;
  size_t di = 0, ci = 0;
  while (di < n_draws || ci < n_copies) {
    bool take_draw = di < n_draws &&
                     (ci >= n_copies || draw_off[di] <= copy_off[ci]);
    if (take_draw) {
      size_t d_end = di;
      if (ci >= n_copies) {
        d_end = n_draws;
      } else {
        while (d_end < n_draws && draw_off[d_end] <= copy_off[ci])
          ++d_end;
      }
      // d_end > di: draw_off[di] <= copy_off[ci] por take_draw.
      segs.push_back(GxSegment{false, di, d_end});
      di = d_end;
    } else {
      size_t c_end = ci;
      if (di >= n_draws) {
        c_end = n_copies;
      } else {
        // Estricto (<): en empate gana el draw (ya consumido
        // arriba); aqui solo entran copias con offset menor
        // que el proximo draw.
        while (c_end < n_copies && copy_off[c_end] < draw_off[di])
          ++c_end;
      }
      // c_end > ci: si take_draw fue falso con draws
      // pendientes, copy_off[ci] < draw_off[di]; sin draws
      // pendientes se consumen todas las copias restantes.
      segs.push_back(GxSegment{true, ci, c_end});
      ci = c_end;
    }
  }
  return segs;
}

}  // namespace sfa
