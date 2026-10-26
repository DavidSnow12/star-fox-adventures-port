#pragma once

// Decodificador DTK (ADPCM GameCube, streams .adp) — puerto del
// verificador host de la Fase 18 (work-port/fase18-payload/
// host-verify/dtk_decode.c), bit a bit idéntico al WAV host en
// 7 ficheros (0 muestras diferentes).
//
// Formato: bloques de 32 B [hdrL, hdrR, hdrL, hdrR, 28 B datos];
// nibble bajo = L, alto = R; 28 frames estéreo por bloque.
// Cabecera por canal: nibble alto = índice de coeficientes
// (0-3), nibble bajo = exponente, escala = 4096 >> exp.
// Coeficientes /2048: {0:(0,0), 1:(1920,0), 2:(3680,-1664),
// 3:(3136,-1760)}; saturación en dos etapas; estado arrastrado
// entre bloques. Salida: 32.000 Hz estéreo s16.
// CORRECCIÓN CRÍTICA (Fase 18): el producto c*X llega a
// ~2,5e11 y DESBORDA int32 (la primera versión daba hasta
// ~33.000 LSB de error); aquí se acumula en int64.
//
// Limitación v1, documentada: decodifica el fichero entero
// en memoria (el mayor ADP, 12,1 MB, tarda ~3,2 s con este
// puerto ingenuo en la VM de desarrollo). El diseño de la
// Fase 18 (streaming por bloques + caché PCM en
// sfa-data/audio-cache/v1/) queda como siguiente paso;
// esta v1 desbloquea que un stream solo-ADP suene, sin
// pretender latencia de producción.

#include "audio/audio.h"

namespace sfa {

// Decodifica un .adp completo a WavData (32.000 Hz, 2 canales).
// Devuelve false si el fichero no existe, su tamaño no es
// múltiplo de 32, o no se puede leer (sin salida parcial).
bool DecodeAdpFile(const char* path, Audio::WavData* out);

}  // namespace sfa
