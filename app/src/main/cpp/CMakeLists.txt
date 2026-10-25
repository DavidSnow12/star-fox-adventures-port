cmake_minimum_required(VERSION 3.22.1)

project("starfox")

# Base compilable del port Android. Solo C++17, sin dependencias
# externas: NDK (android, log, EGL, GLESv3) + native_app_glue.
# La integración de los chunks DolRecomp vendrá después, como
# librería aparte enlazada aquí, no como código pegado en estos stubs.

add_library(native_app_glue STATIC
    ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

target_include_directories(native_app_glue PUBLIC
    ${ANDROID_NDK}/sources/android/native_app_glue)

add_library(starfox SHARED
    native-lib.cpp
    gamecube_runtime/runtime.cpp
    gamecube_runtime/cpu.cpp
    gamecube_runtime/memory.cpp
    gamecube_runtime/symbol_dispatch.cpp
    gamecube_runtime/smc_ranges.cpp
    renderer/renderer.cpp
    audio/audio.cpp
    input/input.cpp
    platform/platform.cpp)

target_include_directories(starfox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(starfox
    native_app_glue
    android
    log
    EGL
    GLESv3)
