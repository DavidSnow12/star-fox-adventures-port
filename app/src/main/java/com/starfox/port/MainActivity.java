package com.starfox.port;

import android.app.NativeActivity;

/**
 * Capa Android mínima: toda la lógica vive en C++ (native-lib.cpp,
 * android_main). Esta actividad solo hereda de NativeActivity para que
 * el sistema entregue la ventana, los eventos de ciclo de vida y la
 * entrada táctil al código nativo.
 *
 * El nombre de la librería nativa ("starfox") se declara en
 * AndroidManifest.xml con android.app.lib_name.
 */
public class MainActivity extends NativeActivity {
}
