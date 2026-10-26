#!/bin/bash
# Build manual de APK de prueba (Fase 10; Fase 11: version por
# argumentos), sin Gradle.
#
# Por que manual: Gradle 8.6 falla en este entorno con
# "Could not receive a message from the daemon" (daemon arranca y
# queda en espera; causa de entorno, no del codigo) y sdkmanager
# falla por el tunel proxy Java (curl directo funciona). La via
# javac/d8/aapt2/apksigner/zipalign YA funciono para la APK
# Fase 0 (57.916 B) y se reutiliza aqui.
#
# Uso: ./android-port-base/build-apk-manual.sh <libstarfox.so> <out.apk>
#   [keystore] [version-code] [version-name]
#   (si no se da keystore, genera uno de prueba en <out>.keystore;
#   version por defecto 3 / 0.3.0-gx11-test desde la Fase 11)
# Requisitos: SDK en $ANDROID_HOME o ~/tools/android-sdk
#   (build-tools 34.0.0, platforms android-34), JDK (javac/keytool).
# Salida: APK de PRUEBA, debuggable (ver AndroidManifest.xml),
#   paquete com.starfox.port, solo arm64-v8a. NO es release: la
#   firma es autofirmada de prueba y el manifiesto lleva
#   android:debuggable="true" solo porque es build de prueba
#   (para leer boot.log con run-as). Quitar para release.
#   Sin datos del juego: la APK arranca en clear + quad de
#   prueba (damero procedural) si no hay sfa-data (ver
#   PORT-STATUS, via de datos). NUNCA meter disco/datos en el APK.
set -eu
ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
SO=${1:?uso: build-apk-manual.sh <libstarfox.so> <out.apk> [keystore] [version-code] [version-name]}
OUT_APK=${2:?}
KEYSTORE=${3:-$(dirname "$OUT_APK")/test-debug.keystore}
VERSION_CODE=${4:-3}
VERSION_NAME=${5:-0.3.0-gx11-test}
SDK=${ANDROID_HOME:-$HOME/tools/android-sdk}
BT=$SDK/build-tools/34.0.0
ANDROID_JAR=$SDK/platforms/android-34/android.jar
APP=$ROOT/app/src/main
WORK=$(mktemp -d)
trap 'rm -rf "$WORK"' EXIT
echo "== javac MainActivity =="
mkdir -p "$WORK/classes"
javac --release 17 -cp "$ANDROID_JAR" -d "$WORK/classes" \
  "$APP/java/com/starfox/port/MainActivity.java"
echo "== d8 dex =="
# --lib android.jar: sin el, d8 avisa de que NativeActivity no se
# encuentra (desugaring) aunque el dex salga; con el, no hay aviso.
"$BT/d8" --lib "$ANDROID_JAR" --output "$WORK" "$WORK/classes/com/starfox/port/MainActivity.class"
echo "== aapt2 compile/link =="
mkdir -p "$WORK/res"
"$BT/aapt2" compile "$APP/res/values/strings.xml" -o "$WORK/compiled_res.zip"
"$BT/aapt2" link -o "$WORK/apk_unsigned.apk" -I "$ANDROID_JAR" \
  --manifest "$APP/AndroidManifest.xml" \
  --version-code "$VERSION_CODE" --version-name "$VERSION_NAME" \
  --auto-add-overlay -A "$APP/assets" "$WORK/compiled_res.zip"
echo "== anadir dex + lib =="
mkdir -p "$WORK/stage/lib/arm64-v8a"
cp "$WORK/classes.dex" "$WORK/stage/classes.dex"
cp "$SO" "$WORK/stage/lib/arm64-v8a/libstarfox.so"
# libc++_shared: solo si el .so lo necesita (NDK clang++ enlaza
# libc++_shared por defecto para codigo C++).
NDK=${NDK_DIR:-$HOME/tools/android-ndk/android-ndk-r28c}
if "$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-readelf" -d "$SO" 2>/dev/null | grep -q "libc++_shared"; then
  echo "== anadir libc++_shared.so (NEEDED por libstarfox.so) =="
  cp "$NDK/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/lib/aarch64-linux-android/libc++_shared.so" \
    "$WORK/stage/lib/arm64-v8a/libc++_shared.so"
else
  echo "== libstarfox.so no necesita libc++_shared (estatico) =="
fi
(cd "$WORK/stage" && zip -q -r "$WORK/apk_unsigned.apk" classes.dex lib)
echo "== zipalign + firma de prueba =="
"$BT/zipalign" -f 4 "$WORK/apk_unsigned.apk" "$WORK/apk_aligned.apk"
if [ ! -f "$KEYSTORE" ]; then
  echo "== generando keystore de prueba en $KEYSTORE =="
  keytool -genkeypair -v -keystore "$KEYSTORE" -alias test \
    -keyalg RSA -keysize 2048 -validity 10000 \
    -storepass android -keypass android \
    -dname "CN=StarFoxPortTest, OU=Test, O=Personal, C=ES" >/dev/null 2>&1
fi
"$BT/apksigner" sign --ks "$KEYSTORE" --ks-pass pass:android \
  --key-pass pass:android --out "$OUT_APK" "$WORK/apk_aligned.apk"
echo "== verificacion =="
"$BT/apksigner" verify --verbose "$OUT_APK"
"$BT/zipalign" -c 4 "$OUT_APK" && echo "zipalign OK"
"$BT/aapt2" dump badging "$OUT_APK" | head -20
ls -lh "$OUT_APK"
sha256sum "$OUT_APK"
