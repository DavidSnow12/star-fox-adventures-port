# Assets del APK (preparación posterior)

En esta base no se copia ningún asset del juego dentro del APK.

Los assets extraídos ya están en el repositorio (`assets/extraidos/`,
cerca de 2 GB) y en la carpeta de Drive del proyecto. Empaquetarlos
tal cual dentro de `app/src/main/assets/` haría un APK inmanejable y
duplicaría el material.

La decisión pendiente, para la fase de integración, es cómo cargará
la app los datos: paquete de datos aparte en el dispositivo, descarga
desde la carpeta privada del usuario, o selección de carpeta en el
primer arranque. Hasta entonces, esta carpeta queda solo con este
README, para que la estructura `app/src/main/assets/` exista y el
código de plataforma (`platform.cpp`, `OpenAsset`) tenga dónde
apoyarse cuando llegue ese bloque.
