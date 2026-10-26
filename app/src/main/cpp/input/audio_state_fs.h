#pragma once

// Ayudas de sistema de ficheros para el estado del boton de
// audio (Tramo 6). Solo POSIX (opendir/stat), sin Android:
// las usa native-lib.cpp (NDK) y el test host (Linux) con
// el MISMO codigo, asi que el escaneo inicial de audio/
// queda cubierto por el test, no solo por compilacion.
//
// Que decide cada funcion (y que NO decide):
// - IsAudioMediaFile: solo el sufijo (.wav/.adp, insensible
//   a caso). NO valida contenido: un ADP vacio o corrupto
//   cuenta como "presente" aqui; su rechazo por fichero lo
//   hace el bridge (Tramo 5: cache -> ADP -> WAV -> silencio,
//   nunca crash) y la verificacion Java (ADP no multiplo de
//   32 listado). "Listo" significa "hay audio importado",
//   no "todo el audio es valido".
// - AudioDirHasMedia: true si el arbol contiene al menos un
//   medio, con parada al primer hallazgo. Directorio
//   ausente o sin medios: false, sin error.

#include <cstring>
#include <string>

#include <dirent.h>
#include <sys/stat.h>

namespace sfa {

inline bool IsAudioMediaFile(const std::string& path) {
  size_t dot = path.rfind('.');
  if (dot == std::string::npos) return false;
  std::string ext = path.substr(dot + 1);
  for (char& c : ext) {
    if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
  }
  return ext == "wav" || ext == "adp";
}

inline bool AudioDirHasMedia(const std::string& dir) {
  DIR* d = opendir(dir.c_str());
  if (d == nullptr) return false;
  bool found = false;
  while (!found) {
    struct dirent* e = readdir(d);
    if (e == nullptr) break;
    if (std::strcmp(e->d_name, ".") == 0 ||
        std::strcmp(e->d_name, "..") == 0) {
      continue;
    }
    std::string child = dir + "/" + e->d_name;
    struct stat st;
    if (stat(child.c_str(), &st) != 0) continue;
    if (S_ISDIR(st.st_mode)) {
      found = AudioDirHasMedia(child);
    } else if (S_ISREG(st.st_mode)) {
      found = IsAudioMediaFile(child);
    }
  }
  closedir(d);
  return found;
}

}  // namespace sfa
