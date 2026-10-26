// Tarjeta virtual Memory Card (Slot A) para el HLE CARD, Fase 12.
//
// Modelo puro, sin dependencias guest ni Android: el HLE (hle.cpp)
// traduce entre las estructuras guest (CARDFileInfo / CARDStat) y
// este modelo, y este modelo persiste en un fichero con el formato
// RAW real de GameCube, verificado en dos fuentes independientes:
//   - YAGCD §12 (estructura): bloque 0x2000 B; los 5 primeros
//     bloques son sistema (cabecera, directorio, copia del
//     directorio, BAM, copia de la BAM); datos desde 0xA000.
//     Cabecera: serie 12 B @0, hora de formato 8 B @0xC, tamano
//     en Mbits u16 BE @0x22, codificacion u16 BE @0x24, resto
//     0xFF, contador @0x1FA, checksums @0x1FC/0x1FE.
//     Directorio: 127 entradas de 64 B, relleno, contador
//     @8186, checksums @8188/8190.
//   - El propio SDK del juego (codigo generado): __CARDCheckSum
//     (0x80261484) suma palabras u16 BE y suma sus complementos,
//     con 0xFFFF normalizado a 0; __CARDUpdateDir (0x802613C0)
//     comprueba el directorio sobre 8188 B con checksum
//     @8188 e inverso @8190 y contador @8186; __CARDUpdateFatBlock
//     (0x80261174) comprueba la BAM sobre 8188 B desde +4 con
//     checksum @0, inverso @2 y contador @4. Este modulo usa
//     exactamente ese algoritmo y esos offsets.
// Codigos de error: valores del SDK, verificados contra el uso
// del juego (cardProbe: -1 ocupado/bucle, -2 wrong device,
// -3 no card; saveGame: -4 nofile, -5 ioerror, -6 broken,
// -7 exist, -9 insspace, -13 encoding; el resto, numeracion
// SDK estandar contigua).
//
// Solo se emula el Slot A (canal 0): el juego solo usa Slot A
// ("only supports Memory Card Slot A") y el canal 1 devuelve
// NOCARD, como una ranura vacia real. La tarjeta es de 59
// bloques (4 Mbit, imagen 0x80000 B = 64 bloques de 8192 B,
// 5 de sistema + 59 usables), que es la capacidad clasica y la
// que el juego espera: CARDProbeEx devuelve sectorSize 8192,
// que es lo que cardProbe exige para dar el retorno 1
// ("tarjeta usable") a saveGame.
//
// Persistencia: si se fija una ruta (Hle::SetCardPath), cada
// mutacion (crear/escribir/borrar/SetStatus/formatear) reescribe
// la imagen completa en esa ruta. Sin ruta, la tarjeta vive solo
// en RAM (util para tests host sin disco). La serie de la
// tarjeta se genera en el formateo y queda guardada en la
// cabecera, asi que CARDGetSerialNo es estable entre arranques.
//
// Lo que NO hace este modulo: no emula EXI ni interrupciones
// (el codigo huesped CARD queda sustituido entero por el HLE);
// no verifica checksums al cargar una imagen externa (si el
// tamano no es 0x80000 o el directorio no parsea, se arranca
// con una tarjeta formateada en RAM y se registra el problema
// en el log del llamador; nunca se sobrescribe el fichero
// existente hasta la primera mutacion valida).

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace sfa {

// Campos del CARDStat guest que el juego lee/escribe, con los
// offsets del SDK tal como los usa el juego (saveGame: +46
// bannerFormat, +48 iconAddr, +52 iconFormat, +54 iconSpeed,
// +56 palabra de comentario). El resto del stat (nombre,
// longitud, hora, gamecode, maker, offsets de banner/icono)
// viaja en los mismos campos del struct.
struct CardStatData {
  std::string file_name;
  uint32_t length = 0;
  uint32_t time = 0;
  char game_name[4] = {'G', 'S', 'A', 'P'};
  char company[2] = {'0', '1'};
  uint8_t banner_format = 0;
  uint32_t icon_addr = 0xFFFFFFFFu;
  uint16_t icon_format = 0;
  uint16_t icon_speed = 0;
  uint32_t comment_word = 0xFFFFFFFFu;
  uint32_t offset_banner = 0xFFFFFFFFu;
  uint32_t offset_banner_tlut = 0xFFFFFFFFu;
  uint32_t offset_icon[8] = {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                             0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                             0xFFFFFFFFu, 0xFFFFFFFFu};
  uint32_t offset_icon_tlut = 0xFFFFFFFFu;
  uint32_t offset_data = 0xFFFFFFFFu;
};

class VirtualCard {
 public:
  // Codigos de resultado CARD (SDK).
  static constexpr int kReady = 0;
  static constexpr int kBusy = -1;
  static constexpr int kWrongDevice = -2;
  static constexpr int kNoCard = -3;
  static constexpr int kNoFile = -4;
  static constexpr int kIoError = -5;
  static constexpr int kBroken = -6;
  static constexpr int kExist = -7;
  static constexpr int kNoEnt = -8;
  static constexpr int kInsSpace = -9;
  static constexpr int kNoPerm = -10;
  static constexpr int kLimit = -11;
  static constexpr int kNameTooLong = -12;
  static constexpr int kEncoding = -13;
  static constexpr int kCanceled = -14;
  static constexpr int kFatalError = -128;

  static constexpr uint32_t kImageSize = 0x80000u;
  static constexpr uint32_t kBlockSize = 8192u;
  static constexpr int kTotalBlocks = 64;
  static constexpr int kFirstDataBlock = 5;
  static constexpr int kUsableBlocks = 59;
  static constexpr uint32_t kProbeMemSize = 0x80000u;
  static constexpr uint32_t kProbeSectorSize = 8192u;
  static constexpr uint32_t kMaxFileName = 32u;

  void SetPath(const std::string& path) { path_ = path; }
  const std::string& Path() const { return path_; }

  // Carga la imagen de path_ si existe y parsea; si no existe,
  // formatea una tarjeta nueva vacia (sin escribirla todavia:
  // la primera mutacion la persiste). Devuelve false solo si
  // path_ esta fijada y no se pudo ni leer ni crear en RAM
  // (no ocurre en la practica: el formateo en RAM no falla).
  // Si el fichero existe pero no parsea, se arranca formateado
  // en RAM y se devuelve false para que el llamador lo registre;
  // el fichero NO se toca hasta una mutacion.
  bool EnsureLoaded();

  bool Loaded() const { return loaded_; }
  bool Mounted(int chan) const {
    return chan == 0 && mounted_;
  }
  uint64_t SerialNo() const { return serial_no_; }

  int Probe(int chan, uint32_t* mem_size, uint32_t* sector_size) const;
  int Init();
  int Mount(int chan);
  int Unmount(int chan);
  int Check(int chan) const;
  int CheckEx(int chan) const { return Check(chan); }
  int Format(int chan);

  // fileNo = indice de entrada de directorio (como en el SDK).
  int Open(int chan, const std::string& name, int* file_no);
  int Create(int chan, const std::string& name, uint32_t size,
             int* file_no);
  int Close(int file_no);
  int Read(int file_no, uint32_t offset, uint32_t length,
           uint8_t* out) const;
  int Write(int file_no, uint32_t offset, const uint8_t* data,
            uint32_t length);
  int Delete(int chan, const std::string& name);
  int GetStatus(int chan, int file_no, CardStatData* stat) const;
  int SetStatus(int chan, int file_no, const CardStatData& stat);
  int GetSerialNo(int chan, uint64_t* serial) const;

  // Solo para diagnostico host (informe de fase, no para el
  // juego): numero de ficheros vivos y sus nombres/tamanos
  // (index = n-esimo fichero vivo, no fileNo).
  size_t FileCount() const;
  bool FileInfo(size_t index, std::string* name, uint32_t* length) const;

  // Serializa la imagen RAW completa (0x80000 B) tal como se
  // persistiria. Util para tests host y para Save().
  std::vector<uint8_t> Serialize() const;

 private:
  struct File {
    // alive=false = hueco de directorio (borrado): se conserva
    // el hueco para que los fileNo (indices de directorio) de
    // los demas ficheros no cambien, como en el SDK (la entrada
    // borrada queda en 0xFFFFFFFF, no se compacta).
    bool alive = true;
    std::string name;
    uint32_t length = 0;  // tamano logico pedido en Create
    std::vector<uint8_t> data;  // capacidad = bloques * 8192
    uint32_t time = 0;
    CardStatData stat;
    int first_block = -1;
    int block_count = 0;
  };

  void FormatNew();
  bool ParseImage(const std::vector<uint8_t>& image);
  bool Persist();
  int FindFile(const std::string& name) const;
  int FreeBlocks() const;
  bool AllocBlocks(int count, int* first_block);

  std::string path_;
  bool loaded_ = false;
  bool mounted_ = false;
  bool image_parse_failed_ = false;
  uint64_t serial_no_ = 0;
  uint32_t format_time_ = 0;
  uint16_t dir_update_ = 0;
  uint16_t bam_update_ = 0;
  std::vector<File> files_;
  std::vector<int> bam_;  // por bloque: 0 libre, siguiente, o -1 ultimo
};

}  // namespace sfa
