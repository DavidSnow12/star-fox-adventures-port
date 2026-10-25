#pragma once

// Sistema de log de la base del port: logcat + boot.log en la carpeta
// interna de la app (ver platform/platform.cpp). El boot.log es el
// diagnóstico de primer arranque: si la app se cierra al abrir, ese
// fichero dice hasta dónde llegó, sin depender solo de logcat.

#include <android/log.h>
#include <cstdio>

namespace sfa {

void BootLog(const char* format, ...);

}  // namespace sfa

#define SFA_LOGI(...) \
  do { \
    __android_log_print(ANDROID_LOG_INFO, "StarFoxPort", __VA_ARGS__); \
    sfa::BootLog(__VA_ARGS__); \
  } while (0)

#define SFA_LOGE(...) \
  do { \
    __android_log_print(ANDROID_LOG_ERROR, "StarFoxPort", __VA_ARGS__); \
    sfa::BootLog(__VA_ARGS__); \
  } while (0)
