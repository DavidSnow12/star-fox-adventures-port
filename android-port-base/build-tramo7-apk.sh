#!/bin/bash
# build-tramo7-apk.sh — Wrapper del pipeline APK manual del Tramo 7.
#
# Copia actualizada de work-port/tramo6-data/build-tramo6-apk.sh.
# Cambios Tramo 7 (ver PIPELINE-APK-TRAMO7.md):
#  1. Descubrimiento del JDK: PATH, $JAVA_HOME, y el Temurin 21
#     que vive en ~/tools/jdk-21.0.13+9 (NO en /usr/lib/jvm: el
#     informe del Tramo 6 lo dio por ausente porque solo miro
#     PATH y /usr/lib/jvm; en realidad estaba en ~/tools).
#  2. Guarda de simbolos CORREGIDA: el patron del Tramo 6
#     ("^(mem_|ppc_|func_|dolrecomp_)") nunca casaba con la
#     salida de llvm-nm -u (las lineas empiezan con espacios +
#     " U "), asi que pasaba por vacio. Aqui se extrae el nombre
#     (ultimo campo) y se exige 0 coincidencias con esos prefijos.
#  3. Guarda de version insensible a mayusculas (jugable/
#     playable/release/final en cualquier caja) y sufijo -test
#     obligatorio; sin numeros por defecto: el coordinador
#     asigna VERSION_CODE y VERSION_NAME en el momento del build.
#  4. Salidas en work-port/tramo7-apk/ y build NDK en
#     work-port/tramo7-ndk-build/ (no se sobrescribe el build
#     del Tramo 6). Re-validacion independiente completa
#     (badging entero, no solo 20 lineas; permisos = solo VIBRATE).
#
# NO construye una APK "jugable": solo APKs de PRUEBA (sufijo
# -test obligatorio). NO hace commit ni push, NO toca el repo:
# la APK y el log salen fuera de github-repo. NO mete datos del
# juego en la APK. NO asigna el proximo numero GX: un build de
# validacion usa un nombre *-validation-test, nunca un GX nuevo.
#
# Uso:
#   ./build-tramo7-apk.sh --check-only
#       Solo preflight (JDK, SDK, NDK, repo limpio). No construye nada.
#   ./build-tramo7-apk.sh <VERSION_CODE> <VERSION_NAME-test>
#       Pipeline completo: lib NDK -> APK manual -> re-validacion.
#
# Requisitos: NDK r28c en ~/tools/android-ndk/android-ndk-r28c,
#   SDK en $ANDROID_HOME o ~/tools/android-sdk (build-tools 34.0.0,
#   platforms android-34), JDK 17+ (javac/java/keytool), keystore
#   de prueba en work-port/test-debug.keystore.
set -eu

REPO=${REPO:-$HOME/workspace/starfoxadventures/github-repo}
OUTDIR=${OUTDIR:-$HOME/workspace/starfoxadventures/work-port/tramo7-apk}
SDK=${ANDROID_HOME:-$HOME/tools/android-sdk}
BT=$SDK/build-tools/34.0.0
NDK=${NDK_DIR:-$HOME/tools/android-ndk/android-ndk-r28c}
KEYSTORE=${KEYSTORE:-$HOME/workspace/starfoxadventures/work-port/test-debug.keystore}

fail() { echo "PREFLIGHT FALLO: $*" >&2; exit 1; }

# --- Descubrimiento del JDK (Tramo 7, correccion al Tramo 6) ---
# Orden: PATH, $JAVA_HOME, Temurin persistente en ~/tools.
if ! command -v javac >/dev/null 2>&1 || ! command -v java >/dev/null 2>&1; then
  for cand in "${JAVA_HOME:-}" "$HOME/tools/jdk-21.0.13+9" "$HOME/tools/jdk21"; do
    if [ -n "$cand" ] && [ -x "$cand/bin/javac" ] && [ -x "$cand/bin/java" ]; then
      export PATH="$cand/bin:$PATH"
      export JAVA_HOME="$cand"
      echo "JDK descubierto en: $cand"
      break
    fi
  done
fi

# Validacion de version ANTES del preflight: la guarda anti-"jugable"
# debe ser comprobable incluso cuando el entorno no puede construir.
if [ "${1:-}" != "--check-only" ] && [ -n "${1:-}" ]; then
  VERSION_CODE_ARG=$1
  VERSION_NAME_ARG=${2:-}
  case "$VERSION_NAME_ARG" in
    *-test) ;;
    *) echo "VERSION FALLO: VERSION_NAME debe terminar en -test (recibido: $VERSION_NAME_ARG)" >&2; exit 1 ;;
  esac
  LOWER_NAME=$(printf '%s' "$VERSION_NAME_ARG" | tr '[:upper:]' '[:lower:]')
  case "$LOWER_NAME" in
    *jugable*|*playable*|*release*|*final*) echo "VERSION FALLO: VERSION_NAME no puede sugerir jugable/release: $VERSION_NAME_ARG" >&2; exit 1 ;;
  esac
  case "$VERSION_NAME_ARG" in
    *gx[0-9]*)
      echo "VERSION AVISO: un nombre con gx<N> es un numero de prueba oficial; solo el coordinador lo asigna." >&2
      echo "Para validacion del pipeline usar *-validation-test, no un GX nuevo." >&2
      ;;
  esac
fi

echo "== preflight Tramo 7 =="
[ -d "$REPO" ] || fail "repo no encontrado: $REPO"
BRANCH=$(git -C "$REPO" rev-parse --abbrev-ref HEAD)
COMMIT=$(git -C "$REPO" rev-parse --short HEAD)
FULL_COMMIT=$(git -C "$REPO" rev-parse HEAD)
echo "repo: $REPO rama=$BRANCH commit=$COMMIT ($FULL_COMMIT)"
[ "$BRANCH" = "android-port-base" ] || fail "rama inesperada: $BRANCH (se espera android-port-base)"
[ -z "$(git -C "$REPO" status --porcelain)" ] || fail "repo con cambios sin commitear; no construir sobre un arbol sucio"
[ -x "$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang" ] \
  || fail "NDK r28c no encontrado en $NDK"
for t in aapt2 d8 apksigner zipalign; do
  [ -x "$BT/$t" ] || fail "falta $BT/$t"
done
[ -f "$SDK/platforms/android-34/android.jar" ] || fail "falta platforms/android-34/android.jar"
command -v javac >/dev/null 2>&1 || fail "javac no encontrado: JDK ausente. Buscar en PATH, \$JAVA_HOME o ~/tools/jdk-21.0.13+9/bin; si no existe, instalar openjdk-17/21-jdk-headless (ver PIPELINE-APK-TRAMO7.md §3)"
command -v java >/dev/null 2>&1 || fail "java no encontrado: JDK ausente (apksigner/d8 lo necesitan)"
command -v keytool >/dev/null 2>&1 || fail "keytool no encontrado: JDK ausente"
javac -version 2>&1
java -version 2>&1 | head -n 1
[ -f "$KEYSTORE" ] || fail "keystore de prueba no encontrado: $KEYSTORE (no se genera uno nuevo en silencio: la firma de prueba debe ser la conocida)"
echo "preflight OK (rama=$BRANCH commit=$COMMIT)"

if [ "${1:-}" = "--check-only" ]; then
  echo "--check-only: no se construye nada."
  exit 0
fi

VERSION_CODE=${1:?uso: build-tramo7-apk.sh <VERSION_CODE> <VERSION_NAME-test> | --check-only}
VERSION_NAME=${2:?uso: build-tramo7-apk.sh <VERSION_CODE> <VERSION_NAME-test> | --check-only}
echo "version: code=$VERSION_CODE name=$VERSION_NAME (PRUEBA, NO jugable)"

mkdir -p "$OUTDIR"
NDK_OUT=$HOME/workspace/starfoxadventures/work-port/tramo7-ndk-build
LOG=$OUTDIR/tramo7-apk-build-$VERSION_NAME.log
APK=$OUTDIR/app-debug-tramo7-test.apk
exec > >(tee "$LOG") 2>&1
echo "== build Tramo 7: $VERSION_NAME (commit $COMMIT, $FULL_COMMIT) =="
echo "== 1. lib NDK =="
"$REPO/android-port-base/build-libstarfox-ndk.sh" "$NDK_OUT"
SO=$NDK_OUT/libstarfox.so
echo "== 2. validar lib =="
file "$SO"
NM="$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-nm"
echo "-- undefined totales --"
"$NM" -u "$SO" | wc -l
echo "-- undefined con prefijo de juego (debe ser 0; patron CORREGIDO Tramo 7) --"
BAD=$("$NM" -u "$SO" | awk '{print $NF}' | grep -E "^(mem_|ppc_|func_|dolrecomp_)" || true)
if [ -n "$BAD" ]; then
  echo "$BAD"
  fail "simbolos de juego sin resolver en libstarfox.so"
fi
echo "lib: 0 simbolos mem_/ppc_/func_/dolrecomp_ sin resolver (patron corregido)"
echo "-- definidos mem_/ppc_ en T (deben existir) --"
"$NM" "$SO" | grep -E " T (mem_|ppc_)" | wc -l
"$NM" "$SO" | grep -w "android_main" || fail "android_main no definido en libstarfox.so"
ls -l "$SO"
"$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/llvm-readelf" -d "$SO" | grep -E "NEEDED"
echo "== 3. APK manual =="
"$REPO/android-port-base/build-apk-manual.sh" "$SO" "$APK" \
  "$KEYSTORE" \
  "$VERSION_CODE" "$VERSION_NAME"
echo "== 4. re-validacion independiente =="
"$BT/apksigner" verify --verbose "$APK"
"$BT/zipalign" -c 4 "$APK" && echo "zipalign: OK"
echo "-- badging completo --"
"$BT/aapt2" dump badging "$APK"
echo "-- permisos (debe ser solo VIBRATE) --"
"$BT/aapt2" dump badging "$APK" | grep "uses-permission" || fail "sin permisos declarados (se espera VIBRATE)"
if "$BT/aapt2" dump badging "$APK" | grep "uses-permission" | grep -qv "android.permission.VIBRATE"; then
  fail "permiso distinto de VIBRATE declarado"
fi
echo "permisos: solo VIBRATE, OK"
echo "-- debuggable (obligatorio en APK de prueba, para run-as/boot.log) --"
"$BT/aapt2" dump badging "$APK" | grep -q "application-debuggable" || fail "APK de prueba sin application-debuggable"
echo "debuggable: OK"
unzip -l "$APK"
if unzip -l "$APK" | grep -qE "(^|/)files/|(^|/)sys/|sfa-data|(^|/)audio/"; then
  fail "la APK contiene datos del juego (prohibido)"
fi
echo "APK sin datos: OK (assets/README.md del proyecto base es el unico asset permitido)"
echo "-- lib extraida --"
TMPD=$(mktemp -d)
trap 'rm -rf "$TMPD"' EXIT
unzip -q -o "$APK" "lib/arm64-v8a/libstarfox.so" -d "$TMPD"
file "$TMPD/lib/arm64-v8a/libstarfox.so"
ls -lh "$TMPD/lib/arm64-v8a/libstarfox.so"
echo "APK: $APK"
ls -lh "$APK"
sha256sum "$APK"
echo "== OK: APK de PRUEBA en $APK (NO jugable). Log: $LOG =="
