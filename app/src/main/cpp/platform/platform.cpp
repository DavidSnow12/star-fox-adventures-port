#include "platform/platform.h"

#include <android/log.h>
#include <cstdarg>
#include <cstdio>

namespace sfa {

namespace {
struct android_app* g_app = nullptr;
FILE* g_boot_log = nullptr;
}  // namespace

void PlatformInit(struct android_app* app) {
  g_app = app;
  if (app != nullptr && app->activity != nullptr &&
      app->activity->internalDataPath != nullptr) {
    std::string path = std::string(app->activity->internalDataPath) + "/boot.log";
    g_boot_log = fopen(path.c_str(), "w");
  }
  if (g_boot_log != nullptr) {
    fprintf(g_boot_log, "StarFoxPort boot.log: inicio\n");
    fflush(g_boot_log);
  }
}

void BootLog(const char* format, ...) {
  if (g_boot_log == nullptr) return;
  va_list args;
  va_start(args, format);
  vfprintf(g_boot_log, format, args);
  va_end(args);
  fprintf(g_boot_log, "\n");
  fflush(g_boot_log);
}

AAsset* OpenAsset(const char* path) {
  if (g_app == nullptr || g_app->activity == nullptr ||
      g_app->activity->assetManager == nullptr) {
    return nullptr;
  }
  return AAssetManager_open(g_app->activity->assetManager, path,
                            AASSET_MODE_BUFFER);
}

std::string InternalDataPath() {
  if (g_app != nullptr && g_app->activity != nullptr &&
      g_app->activity->internalDataPath != nullptr) {
    return std::string(g_app->activity->internalDataPath);
  }
  return std::string();
}

}  // namespace sfa
