cmake_minimum_required(VERSION 3.22.1)

project("starfox")

# Base compilable del port Android. Solo C++17, sin dependencias
# externas: NDK (android, log, EGL, GLESv3) + native_app_glue.
#
# Fase 1 del port (2026-10-25): los 176 chunks DolRecomp y su
# generated.c ya enlazan en libstarfox.so, junto al shim C
# cpu/cpu.c (CPUState + mem_* + ppc_*). Los chunks se compilan
# como C (sin name mangling) y el runtime C++ sigue siendo stub:
# todavia no se ejecuta el juego (falta el HLE de la Fase 2), pero
# el enlace ya no tiene simbolos de chunks sin resolver.
# Fases 2-4 (2026-10-25): gamecube_runtime/hle.cpp (HLE minimo en
# orden de init + DVD desde el arbol extraido + retrace simulado)
# y chassis.cpp (bucle dolrecomp_call desde 0x80003140 con hitos
# y paradas con causa) ya ejecutan la ruta real hasta videoInit
# en el test host; la APK Fase 0 sigue sin juego (ver PORT-STATUS).
# Los chunks viven en codigo/generated/ (raiz del repo), NO en app/,
# porque son la recompilacion de main (ya en main) y no codigo de
# la app; CMake los referencia por ruta relativa, sin copiarlos.

add_library(native_app_glue STATIC
    ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

target_include_directories(native_app_glue PUBLIC
    ${ANDROID_NDK}/sources/android/native_app_glue)

# generated.c incluye "generated.h" (su propio directorio) y
# generated.h incluye "cpu/cpu.h": hacen falta ambos directorios.
set(SFA_GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../codigo/generated)
file(GLOB SFA_CHUNKS_C ${SFA_GENERATED_DIR}/chunks/*.c)
list(LENGTH SFA_CHUNKS_C SFA_CHUNKS_COUNT)
if(NOT SFA_CHUNKS_COUNT EQUAL 176)
    message(FATAL_ERROR
        "Se esperaban 176 chunks DolRecomp, hay ${SFA_CHUNKS_COUNT} en ${SFA_GENERATED_DIR}/chunks")
endif()

add_library(starfox SHARED
    native-lib.cpp
    cpu/cpu.c
    ${SFA_GENERATED_DIR}/generated.c
    ${SFA_CHUNKS_C}
    gamecube_runtime/runtime.cpp
    gamecube_runtime/hle.cpp
    gamecube_runtime/rumble_jni.cpp
    gamecube_runtime/card.cpp
    gamecube_runtime/chassis.cpp
    gamecube_runtime/cpu.cpp
    gamecube_runtime/memory.cpp
    gamecube_runtime/dol_loader.cpp
    gamecube_runtime/mem.cpp
    gamecube_runtime/symbol_dispatch.cpp
    gamecube_runtime/smc_ranges.cpp
    gamecube_runtime/gx.cpp
    gamecube_runtime/gx_texture.cpp
    renderer/renderer.cpp
    renderer/gx_gl.cpp
    renderer/gx_translate.cpp
    audio/audio.cpp
    audio/audio_bridge.cpp
    audio/adp_decode.cpp
    audio/adp_stream.cpp
    audio/adp_cache.cpp
    input/input.cpp
    platform/platform.cpp)

target_include_directories(starfox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SFA_GENERATED_DIR})

target_link_libraries(starfox
    native_app_glue
    android
    log
    EGL
    GLESv3
    aaudio
    m)
