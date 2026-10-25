#pragma once

// Plataforma Android: assets y boot.log. Todo el acceso a ficheros
// del juego pasará por aquí, no por rutas absolutas sueltas.

#include <android/asset_manager.h>
#include <android_native_app_glue.h>
#include <cstdint>
#include <string>

namespace sfa {

// Inicializa el boot.log en la carpeta interna de la app
// (<internalDataPath>/boot.log). Se llama una sola vez desde
// android_main, antes que cualquier otro módulo.
void PlatformInit(struct android_app* app);

// Escribe una línea en boot.log (además de logcat, ver log.h).
void BootLog(const char* format, ...);

// Abre un asset del APK (app/src/main/assets). Devuelve nullptr si
// no existe; el llamador debe cerrar con AAsset_close.
AAsset* OpenAsset(const char* path);

// Ruta interna de la app (para boot.log y datos descargados después).
std::string InternalDataPath();

}  // namespace sfa
