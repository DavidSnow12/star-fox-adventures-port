#!/bin/bash
# Build directo de libstarfox.so con el NDK (sin Gradle), para
# verificar la Fase 1: shim cpu/cpu.c + generated.c + 176 chunks
# enlazan sin simbolos sin resolver. No escribe en el repo: todo va
# a OUT (por defecto /tmp/sfa-ndk-build; para una verificacion que
# sobreviva a un reinicio de /tmp, pasar un OUT bajo ~/workspace).
#
# Uso:  ./android-port-base/build-libstarfox-ndk.sh [OUT]
# Requisitos: NDK r28c en ~/tools/android-ndk/android-ndk-r28c
# (o NDK_DIR en el entorno). Compila con clang aarch64 API 26,
# igual que el build.gradle (minSdk 26, arm64-v8a).
#
# Los objetos se nombran por basename, salvo cpu_shim.o: hay
# colision de basenames entre cpu/cpu.c (shim C) y
# gamecube_runtime/cpu.cpp (stub C++), que NO pueden compartir
# cpu.o; en la primera version de este script el segundo
# sobrescribia al primero y el .so quedaba sin mem_*/ppc_*.
# La recompilacion es incremental: un objeto mas nuevo que su
# fuente no se recompila.
# NOTA Fase 2 (2026-10-25): se anadio -fPIC a C y C++: sin el, el
# enlace del .so rechazaba reubicaciones absolutas contra
# simbolos globales de hle.cpp (bug latente de la Fase 1: sus
# objetos no referenciaban globales de datos y enlazaban igual).
# Los objetos viejos sin -fPIC que ya enlazaban en la Fase 1 se
# reutilizan; solo se recompilan con -fPIC los ficheros nuevos o
# tocados (el script es incremental por fecha, no por flags).
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
OUT=${1:-/tmp/sfa-ndk-build}
NDK_DIR=${NDK_DIR:-$HOME/tools/android-ndk/android-ndk-r28c}
TC=$NDK_DIR/toolchains/llvm/prebuilt/linux-x86_64/bin
CC=$TC/aarch64-linux-android26-clang
CXX=$TC/aarch64-linux-android26-clang++
NM=$TC/llvm-nm
mkdir -p "$OUT/obj"
CPP=$ROOT/app/src/main/cpp
GEN=$ROOT/codigo/generated
objname() {
  # Unica colision real de basenames: cpu/cpu.c (shim C) frente a
  # gamecube_runtime/cpu.cpp (stub C++). Solo ese caso se renombra;
  # el resto usa el basename, asi los objetos ya compilados se
  # reutilizan entre ejecuciones.
  if [ "$1" = "$CPP/cpu/cpu.c" ]; then
    printf 'cpu_shim'
    return
  fi
  basename "$1" | sed 's/\.[^.]*$//'
}
compile_c() {
  o="$OUT/obj/$(objname "$1").o"
  if [ ! -f "$o" ] || [ "$1" -nt "$o" ]; then
    $CC -c -O2 -fPIC -std=c11 -I"$CPP" -I"$GEN" \
      -I"$NDK_DIR/sources/android/native_app_glue" "$1" -o "$o"
  fi
  printf '%s\n' "$o"
}
compile_cxx() {
  o="$OUT/obj/$(objname "$1").o"
  if [ ! -f "$o" ] || [ "$1" -nt "$o" ]; then
    $CXX -c -O2 -fPIC -std=c++17 -I"$CPP" -I"$GEN" \
      -I"$NDK_DIR/sources/android/native_app_glue" "$1" -o "$o"
  fi
  printf '%s\n' "$o"
}
OBJS=""
# native_app_glue (C, del NDK)
OBJS="$OBJS $(compile_c "$NDK_DIR/sources/android/native_app_glue/android_native_app_glue.c")"
# Shim C + generated + chunks (C, sin mangling). generated.h exige
# "cpu/cpu.h": -I app/src/main/cpp. generated.c exige
# "generated.h": -I codigo/generated. Los chunks usan
# "../generated.h" relativo, que resuelve solo.
# Compilacion C en paralelo (JOBS, por defecto 2: los chunks son
# ~40k lineas cada uno y en serie el build tarda ~30 min).
export -f compile_c objname
export CC CXX CPP GEN NDK_DIR OUT
JOBS=${JOBS:-2}
{
  printf '%s\n' "$CPP/cpu/cpu.c" "$GEN/generated.c" "$GEN"/chunks/*.c
} | xargs -P"$JOBS" -I{} bash -c 'compile_c "$@"' _ {} > "$OUT/objs-c.txt"
OBJS="$OBJS $(tr '\n' ' ' < "$OUT/objs-c.txt")"
# Runtime C++ de la app
for f in $(find "$CPP" -name '*.cpp'); do
  OBJS="$OBJS $(compile_cxx "$f")"
done
# shellcheck disable=SC2086
$CXX -shared -o "$OUT/libstarfox.so" $OBJS \
  -landroid -llog -lEGL -lGLESv3 -laaudio -lm
echo "OK: $OUT/libstarfox.so"
echo "--- simbolos sin resolver (nm -u, sin filtrar) ---"
$NM -u "$OUT/libstarfox.so" | sort
echo "--- comprobacion shim/chunks ---"
$NM -u "$OUT/libstarfox.so" | awk '{print $NF}' | sort -u > "$OUT/undefined.txt"
# Los undefined de un .so enlazado dinamicamente son solo nombres;
# el filtro util es: ninguno debe empezar por mem_/ppc_/func_/dolrecomp_
if grep -Eq '^(mem_|ppc_|func_|dolrecomp_)' "$OUT/undefined.txt"; then
  echo "FALLO: quedan simbolos de chunks/shim sin resolver:" >&2
  grep -E '^(mem_|ppc_|func_|dolrecomp_)' "$OUT/undefined.txt" >&2
  exit 1
fi
echo "OK: ningun simbolo mem_/ppc_/func_/dolrecomp_ sin resolver"
wc -l < "$OUT/undefined.txt" | xargs echo "undefined totales (solo libs del sistema, p. ej. libc/pthread en bionic):"
