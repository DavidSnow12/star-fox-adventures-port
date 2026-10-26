package com.starfox.port;

import android.app.NativeActivity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.os.VibratorManager;
import android.provider.DocumentsContract;
import android.util.Log;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Capa Android: NativeActivity para ventana/eventos/entrada, mas
 * el picker SAF de la Fase 13 para los datos del juego.
 *
 * Por que SAF y por que asi: NativeActivity no tiene UI Java
 * (toda la pantalla es la ventana nativa), asi que no hay un
 * boton ni un dialogo Java donde colgar un picker. La via
 * elegida es: el codigo nativo detecta que no hay sfa-data en
 * el primer arranque y llama por JNI a requestDataFolder()
 * (este metodo); este metodo lanza el Intent SAF en el hilo
 * UI (runOnUiThread, porque startActivityForResult desde el
 * hilo nativo no es seguro) y onActivityResult copia el arbol
 * elegido a la carpeta privada en un hilo de fondo (para no
 * bloquear la UI durante una copia de ~240 MB).
 *
 * Flujo completo:
 *   1. Usuario: Drive -> Descargas -> carpeta con sys/main.dol
 *      + files/ (el contenido de Pack B). Elige ESA carpeta
 *      (no su padre: se copian sus hijos directos a sfa-data/).
 *   2. Copia recursiva a <base>/sfa-data/ (interna preferida,
 *      la misma base que usa native-lib para el DOL y para
 *      memcard-a.raw; externa solo si no hay interna).
 *   3. Verificacion: sys/main.dol con tamano 3.405.600 B y
 *      SHA-1 c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66, y
 *      files/ con al menos 2.916 ficheros (Pack B = files/
 *      sin streams/; si el usuario copio tambien streams/,
 *      el conteo es mayor y se registra como aviso, no como
 *      error: los ficheros extra no estorban al juego).
 *   4. Marcador <base>/sfa-data/.saf-copy-done con el resumen;
 *      el bucle nativo lo detecta y carga el juego sin
 *      reiniciar la app. Si falla, .saf-copy-error con la
 *      causa y el juego sigue sin datos (clear + quad).
 *   5. Audio (Tramo 5): verifyAndMark() tambien informa de
 *      audio/ (conteo de WAV MusyX y ADP de streams, y ADP
 *      con tamano no multiplo de 32), pero el audio NO
 *      bloquea la carga del juego: es un overlay opcional
 *      (sin audio, el bridge es inerte; con audio parcial,
 *      suena lo que este y el resto queda en silencio con
 *      log por fichero). Un ADP invalido tampoco bloquea:
 *      el bridge lo salta por fichero (cache -> ADP -> WAV
 *      -> silencio). requestAudioFolder() ("anadir audio")
 *      copia SOLO audio/ a <base>/sfa-data/audio/ sin
 *      tocar sys/ ni files/ y sin reimportar nada, y deja
 *      el marcador .saf-audio-done con su verificacion;
 *      el juego ya cargado lo nota sin reiniciar porque
 *      el bridge lee audio/ en vivo y reconstruye su
 *      indice ADP al primer fallo de busqueda.
 * Sin datos, la app nunca falla: queda en clear + quad de
 * prueba, como antes. NUNCA se meten datos ni disco en Git
 * ni en la APK: solo se copian desde la carpeta del usuario.
 * Progreso y errores van a boot.log (el mismo fichero que
 * el log nativo, en la carpeta interna) y a logcat.
 *
 * Boton visible (Tramo 6, via NATIVA): la pildora
 * inferior-centro la dibuja el renderer y la intercepta el
 * Input nativo ANTES que el layout del juego (ver
 * input/audio_button.h); su disparo drena el bucle nativo
 * y llama a requestAudioFolder() (abajo) via
 * RequestSafAudioPicker() en native-lib.cpp. No se robo
 * ninguna zona tactil del juego (ni la reservada del
 * C-stick): la pildora ocupa una zona disjunta probada en
 * host. La etiqueta textual real queda pendiente del
 * futuro overlay de ajustes; la pildora comunica el estado
 * por color + boot.log (ver TRAMO6-INFORME.md).
 */
public class MainActivity extends NativeActivity {
    private static final String TAG = "StarFoxPort";
    private static final int REQUEST_DATA_FOLDER = 4242;
    private static final int REQUEST_AUDIO_FOLDER = 4243;

    // Verificacion Pack B (ver PORT-STATUS, via de datos).
    private static final long EXPECTED_DOL_SIZE = 3405600L;
    private static final String EXPECTED_DOL_SHA1 =
            "c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66";
    private static final int EXPECTED_FILES_MIN = 2916;

    private volatile boolean copyRunning = false;
    private volatile boolean audioRunning = false;

    // ---- Rumble fase B (Vibrator por JNI, ver rumble_jni.h) ----
    //
    // Llamado por JNI desde JniVibratorSink (hilo del juego,
    // no hilo UI: Vibrator es una llamada binder y no necesita
    // runOnUiThread, al reves que el picker SAF de abajo).
    // Solo llega el canal 0 (el sink JNI filtra el resto):
    // on=true arranca una onda repetida indefinidamente y
    // on=false (o cancelRumble()) la detiene con cancel().
    // La onda es {off 0 ms, on 1000 ms} con repeat=0: en
    // efecto continua (off 0 entre repeticiones), porque la
    // duracion la decide el juego con su STOP, no un
    // one-shot con una duracion inventada aqui. Si el juego
    // pidiera RUMBLE y nunca STOP, vibrar hasta STOP es lo
    // fiel; el riesgo de "motor olvidado" se cierra por
    // otro lado: onPause/onDestroy (abajo) y el StopAllRumble
    // nativo en PAUSE/TERM_WINDOW/DESTROY cancelan siempre.
    // Sin vibrador (hasVibrator false o servicio ausente):
    // no-op silencioso, sin crash y sin dialogo.
    /** Llamado por JNI desde el sink de rumble (canal 0). */
    public void setRumble(boolean on) {
        Vibrator vibrator = vibratorOrNull();
        if (vibrator == null) return;
        try {
            if (on) {
                vibrator.vibrate(VibrationEffect.createWaveform(
                        new long[]{0, 1000}, 0));
            } else {
                vibrator.cancel();
            }
        } catch (Exception e) {
            Log.i(TAG, "rumble: fallo al " + (on ? "vibrar" : "cancelar")
                    + ": " + e);
        }
    }

    /** Llamado por JNI desde el sink (cancelacion total). */
    public void cancelRumble() {
        Vibrator vibrator = vibratorOrNull();
        if (vibrator == null) return;
        try {
            vibrator.cancel();
        } catch (Exception e) {
            Log.i(TAG, "rumble: fallo al cancelar: " + e);
        }
    }

    private Vibrator vibratorOrNull() {
        try {
            // API 31+: VibratorManager es la via vigente (la
            // Tab S8 va por aqui, Android 16). API 26-30:
            // VIBRATOR_SERVICE, la unica disponible entonces.
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
                Object manager = getSystemService(
                        Context.VIBRATOR_MANAGER_SERVICE);
                if (!(manager instanceof VibratorManager)) return null;
                Vibrator vibrator =
                        ((VibratorManager) manager).getDefaultVibrator();
                if (vibrator == null) return null;
                return vibrator.hasVibrator() ? vibrator : null;
            }
            return legacyVibratorOrNull();
        } catch (Exception e) {
            return null;
        }
    }

    // Solo para API < 31: VIBRATOR_SERVICE esta deprecado
    // desde API 31, pero en esas versiones no hay otra via.
    // El SuppressWarnings va aqui, no en el metodo general.
    @SuppressWarnings("deprecation")
    private Vibrator legacyVibratorOrNull() {
        try {
            Object service = getSystemService(Context.VIBRATOR_SERVICE);
            if (!(service instanceof Vibrator)) return null;
            Vibrator vibrator = (Vibrator) service;
            return vibrator.hasVibrator() ? vibrator : null;
        } catch (Exception e) {
            return null;
        }
    }

    // Garantia de ciclo de vida (capa Java, independiente de
    // la nativa): pase lo que pase con el hilo del juego o
    // con el tracker, al pausar o destruir la actividad el
    // motor se detiene. cancel() sin vibracion en curso es
    // inofensivo, asi que no hace falta guardar estado aqui.
    // NativeActivity tambien entrega APP_CMD_PAUSE /
    // TERM_WINDOW / DESTROY al lado nativo, que cancela por
    // su lado (StopAllRumble + reset del tracker para que
    // reanudar vuelva a vibrar): doble cancelacion
    // idempotente, no doble vibracion.
    @Override
    protected void onPause() {
        super.onPause();
        cancelRumble();
    }

    @Override
    protected void onDestroy() {
        cancelRumble();
        super.onDestroy();
    }

    /** Llamado por JNI desde native-lib (primer arranque sin datos). */
    public void requestDataFolder() {
        runOnUiThread(() -> {
            try {
                Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
                        | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);
                startActivityForResult(intent, REQUEST_DATA_FOLDER);
                logSaf("saf: picker abierto (elige la carpeta con "
                        + "sys/main.dol + files/)");
            } catch (Exception e) {
                logSaf("saf: picker fallo: " + e);
            }
        });
    }

    /** Llamado por JNI desde native-lib ("anadir audio"). Abre el
     *  picker SAF para elegir la carpeta del overlay de audio
     *  (la carpeta audio/ en si, o su padre si contiene audio/).
     *  No reimporta sys/ ni files/: copyAudioTree() solo escribe
     *  en <base>/sfa-data/audio/. */
    public void requestAudioFolder() {
        runOnUiThread(() -> {
            try {
                Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
                        | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);
                startActivityForResult(intent, REQUEST_AUDIO_FOLDER);
                logSaf("saf: picker de audio abierto (elige la carpeta "
                        + "audio/ con streams/ y musyx/)");
            } catch (Exception e) {
                logSaf("saf: picker de audio fallo: " + e);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode,
                                    Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != REQUEST_DATA_FOLDER
                && requestCode != REQUEST_AUDIO_FOLDER) return;
        if (resultCode != RESULT_OK || data == null || data.getData() == null) {
            logSaf("saf: picker cancelado por el usuario");
            // Tramo 6: sin esto, el lado nativo no distingue
            // "copia en curso" de "usuario cancelo" (en ambos
            // casos no hay marcador) y la pildora se quedaria
            // en Verificando hasta reiniciar. El marcador de
            // cancelacion lo consume el sondeo nativo, que
            // rederiva el estado (audio/ con medios -> listo;
            // si no, sin audio). Solo para audio: el flujo de
            // datos base no tiene boton con estado que
            // rescatar (su cancelacion ya deja clear + quad).
            if (requestCode == REQUEST_AUDIO_FOLDER) {
                try {
                    File base = dataBase();
                    if (base != null) {
                        writeText(new File(new File(base, "sfa-data"),
                                ".saf-audio-cancelled"),
                                "saf: picker de audio cancelado\n");
                    }
                } catch (Exception ignored) {
                    // El cancel ya esta en boot.log.
                }
            }
            return;
        }
        Uri treeUri = data.getData();
        try {
            getContentResolver().takePersistableUriPermission(treeUri,
                    Intent.FLAG_GRANT_READ_URI_PERMISSION);
        } catch (Exception e) {
            logSaf("saf: aviso, permiso persistente no retenido: " + e);
        }
        if (requestCode == REQUEST_AUDIO_FOLDER) {
            if (audioRunning) {
                logSaf("saf: copia de audio ya en marcha, se ignora "
                        + "la segunda seleccion");
                return;
            }
            audioRunning = true;
            new Thread(() -> copyAudioTree(treeUri)).start();
            return;
        }
        if (copyRunning) {
            logSaf("saf: copia ya en marcha, se ignora la segunda seleccion");
            return;
        }
        copyRunning = true;
        new Thread(() -> copyDataTree(treeUri)).start();
    }

    // ---- Copia solo de audio ("anadir audio", Tramo 5) ----

    private void copyAudioTree(Uri treeUri) {
        try {
            File base = dataBase();
            if (base == null) {
                throw new IOException("sin carpeta privada (interna ni externa)");
            }
            File dest = new File(base, "sfa-data");
            File audioDest = new File(dest, "audio");
            if (!audioDest.exists() && !audioDest.mkdirs()) {
                throw new IOException("no se pudo crear " + audioDest);
            }
            // Tramo 6: borrar marcadores viejos AL EMPEZAR a
            // copiar (el lado nativo ya los borro al pulsar,
            // antes de poner Verifying: doble guarda contra
            // un .saf-audio-done anterior visto durante la
            // copia nueva). Sin esto, el sondeo nativo
            // podria marcar Listo antes de que termine esta
            // copia. El marcador nuevo solo se escribe al
            // final, tras verificar (abajo).
            deleteQuietly(new File(dest, ".saf-audio-done"));
            deleteQuietly(new File(dest, ".saf-audio-error"));
            String treeDocId = DocumentsContract.getTreeDocumentId(treeUri);
            Uri rootDoc = DocumentsContract.buildDocumentUriUsingTree(
                    treeUri, treeDocId);
            // La carpeta elegida puede ser audio/ en si (sus
            // hijos son streams/, musyx/) o su padre (uno de
            // sus hijos es audio/): en el segundo caso se
            // copian los hijos de ese audio/, no el padre
            // entero (sys/ y files/ NO se tocan nunca aqui).
            Uri audioRoot = findAudioChild(treeUri, rootDoc);
            CopyStats stats = new CopyStats();
            copyChildren(treeUri, audioRoot, audioDest, stats);
            logSaf("saf: copia de audio terminada: " + stats.files
                    + " ficheros, " + stats.bytes + " B");
            StringBuilder report = new StringBuilder();
            report.append("saf: verificacion de audio (anadir audio)\n");
            verifyAudio(audioDest, report);
            File dol = new File(new File(dest, "sys"), "main.dol");
            if (!dol.isFile()) {
                report.append("saf: aviso: audio importado pero sin "
                        + "sys/main.dol (falta importar los datos "
                        + "del juego; el audio solo no suena)\n");
            }
            logSaf(report.toString() + "saf: audio listo "
                    + "(marcador .saf-audio-done; el juego ya "
                    + "cargado lo lee en vivo, sin reiniciar)");
            writeText(new File(dest, ".saf-audio-done"), report.toString());
        } catch (Exception e) {
            logSaf("saf: copia de audio FALLO: " + e);
            // Tramo 6: marcador de error para el boton (el
            // lado nativo lo sondea y pone la pildora en
            // rojo). Antes solo quedaba en boot.log y el
            // boton se quedaba en Verifying para siempre
            // en esa ejecucion.
            try {
                File base = dataBase();
                if (base != null) {
                    writeText(new File(new File(base, "sfa-data"),
                            ".saf-audio-error"),
                            "saf: copia de audio fallo: " + e + "\n");
                }
            } catch (Exception ignored) {
                // El error ya esta en boot.log.
            }
        } finally {
            audioRunning = false;
        }
    }

    // Devuelve el documento de audio/ si es hijo de rootDoc,
    // o rootDoc si no lo es (la carpeta elegida ES audio/).
    private Uri findAudioChild(Uri treeUri, Uri rootDoc)
            throws IOException {
        Uri childrenUri = DocumentsContract.buildChildDocumentsUriUsingTree(
                treeUri, DocumentsContract.getDocumentId(rootDoc));
        String[] projection = new String[]{
                DocumentsContract.Document.COLUMN_DOCUMENT_ID,
                DocumentsContract.Document.COLUMN_DISPLAY_NAME,
                DocumentsContract.Document.COLUMN_MIME_TYPE,
        };
        try (Cursor cursor = getContentResolver().query(
                childrenUri, projection, null, null, null)) {
            if (cursor == null) return rootDoc;
            int idCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_DOCUMENT_ID);
            int nameCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_DISPLAY_NAME);
            int mimeCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_MIME_TYPE);
            while (cursor.moveToNext()) {
                String childId = cursor.getString(idCol);
                String name = cursor.getString(nameCol);
                String mime = cursor.getString(mimeCol);
                if (childId == null || name == null) continue;
                if ("audio".equals(name)
                        && DocumentsContract.Document.MIME_TYPE_DIR.equals(mime)) {
                    return DocumentsContract.buildDocumentUriUsingTree(
                            treeUri, childId);
                }
            }
        }
        return rootDoc;
    }

    // ---- Copia y verificacion (hilo de fondo) ----

    private File dataBase() {
        File internal = getFilesDir();
        if (internal != null) return internal;
        File external = getExternalFilesDir(null);
        return external;  // puede ser null: el llamador lo comprueba
    }

    private void copyDataTree(Uri treeUri) {
        try {
            File base = dataBase();
            if (base == null) {
                throw new IOException("sin carpeta privada (interna ni externa)");
            }
            File dest = new File(base, "sfa-data");
            deleteQuietly(new File(dest, ".saf-copy-done"));
            deleteQuietly(new File(dest, ".saf-copy-error"));
            if (!dest.exists() && !dest.mkdirs()) {
                throw new IOException("no se pudo crear " + dest);
            }
            String treeDocId = DocumentsContract.getTreeDocumentId(treeUri);
            Uri rootDoc = DocumentsContract.buildDocumentUriUsingTree(
                    treeUri, treeDocId);
            CopyStats stats = new CopyStats();
            copyChildren(treeUri, rootDoc, dest, stats);
            logSaf("saf: copia terminada: " + stats.files
                    + " ficheros, " + stats.bytes + " B");
            verifyAndMark(dest, stats);
        } catch (Exception e) {
            logSaf("saf: copia FALLO: " + e);
            try {
                File base = dataBase();
                if (base != null) {
                    writeText(new File(new File(base, "sfa-data"),
                            ".saf-copy-error"), "saf: copia fallo: " + e + "\n");
                }
            } catch (Exception ignored) {
                // No hay nada mas que hacer: el error ya esta en boot.log.
            }
        } finally {
            copyRunning = false;
        }
    }

    private static class CopyStats {
        int files = 0;
        long bytes = 0;
    }

    private void copyChildren(Uri treeUri, Uri parentDoc, File destDir,
                              CopyStats stats) throws IOException {
        Uri childrenUri = DocumentsContract.buildChildDocumentsUriUsingTree(
                treeUri, DocumentsContract.getDocumentId(parentDoc));
        String[] projection = new String[]{
                DocumentsContract.Document.COLUMN_DOCUMENT_ID,
                DocumentsContract.Document.COLUMN_DISPLAY_NAME,
                DocumentsContract.Document.COLUMN_MIME_TYPE,
        };
        ContentResolver resolver = getContentResolver();
        try (Cursor cursor = resolver.query(childrenUri, projection,
                null, null, null)) {
            if (cursor == null) {
                throw new IOException("sin acceso a los hijos de " + parentDoc);
            }
            int idCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_DOCUMENT_ID);
            int nameCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_DISPLAY_NAME);
            int mimeCol = cursor.getColumnIndex(
                    DocumentsContract.Document.COLUMN_MIME_TYPE);
            while (cursor.moveToNext()) {
                String childId = cursor.getString(idCol);
                String name = cursor.getString(nameCol);
                String mime = cursor.getString(mimeCol);
                if (childId == null || name == null) continue;
                // Nombres con separador no pueden ocurrir en SAF,
                // pero un nombre manipulado no debe escapar de dest.
                if (name.contains("/") || name.contains("\\")
                        || name.equals(".") || name.equals("..")) {
                    logSaf("saf: nombre ignorado por seguridad: " + name);
                    continue;
                }
                Uri childDoc = DocumentsContract.buildDocumentUriUsingTree(
                        treeUri, childId);
                File out = new File(destDir, name);
                if (DocumentsContract.Document.MIME_TYPE_DIR.equals(mime)) {
                    if (!out.exists() && !out.mkdirs()) {
                        throw new IOException("no se pudo crear " + out);
                    }
                    copyChildren(treeUri, childDoc, out, stats);
                } else {
                    try (InputStream in = resolver.openInputStream(childDoc);
                         OutputStream outStream = new FileOutputStream(out)) {
                        if (in == null) {
                            throw new IOException("no se pudo abrir " + name);
                        }
                        byte[] buf = new byte[65536];
                        int n;
                        while ((n = in.read(buf)) >= 0) {
                            outStream.write(buf, 0, n);
                            stats.bytes += n;
                        }
                    }
                    stats.files++;
                    if (stats.files % 250 == 0) {
                        logSaf("saf: progreso: " + stats.files
                                + " ficheros, " + stats.bytes + " B");
                    }
                }
            }
        }
    }

    private void verifyAndMark(File dest, CopyStats stats) throws IOException {
        File dol = new File(new File(dest, "sys"), "main.dol");
        StringBuilder report = new StringBuilder();
        report.append("saf: verificacion de la copia\n");
        boolean ok = true;
        if (!dol.isFile()) {
            report.append("saf: FALTA sys/main.dol\n");
            ok = false;
        } else {
            String sha1 = sha1Hex(dol);
            report.append("saf: main.dol tamano=").append(dol.length())
                    .append(" sha1=").append(sha1).append("\n");
            if (dol.length() != EXPECTED_DOL_SIZE || !EXPECTED_DOL_SHA1.equals(sha1)) {
                report.append("saf: main.dol NO coincide con lo esperado "
                        + "(tamano ").append(EXPECTED_DOL_SIZE)
                        .append(", sha1 ").append(EXPECTED_DOL_SHA1).append(")\n");
                ok = false;
            }
        }
        File filesDir = new File(dest, "files");
        int count = countFiles(filesDir);
        report.append("saf: files/ ficheros=").append(count)
                .append(" (Pack B esperado >= ").append(EXPECTED_FILES_MIN)
                .append(")\n");
        if (count < EXPECTED_FILES_MIN) {
            report.append("saf: files/ INCOMPLETO: faltan al menos ")
                    .append(EXPECTED_FILES_MIN - count).append(" ficheros\n");
            ok = false;
        } else if (count != EXPECTED_FILES_MIN) {
            report.append("saf: aviso: files/ tiene ").append(count)
                    .append(" ficheros (mas que Pack B: probablemente "
                            + "incluye streams/, inofensivo)\n");
        }
        // Audio (Tramo 5): informativo, NUNCA bloquea la carga.
        // Sin audio el juego carga igual (bridge inerte); con
        // audio parcial suena lo que este. Un ADP invalido
        // tampoco bloquea: el bridge lo salta por fichero.
        verifyAudio(new File(dest, "audio"), report);
        if (!ok) {
            logSaf(report.toString() + "saf: verificacion FALLIDA, "
                    + "el juego NO se cargara desde esta copia");
            writeText(new File(dest, ".saf-copy-error"), report.toString());
            return;
        }
        logSaf(report.toString() + "saf: verificacion OK, juego listo "
                + "para cargar (marcador .saf-copy-done)");
        writeText(new File(dest, ".saf-copy-done"), report.toString());
    }

    // Verificacion de audio/: conteo de WAV (MusyX) y ADP
    // (streams), con aviso si un ADP tiene tamano no
    // multiplo de 32 (el bridge lo rechazara por fichero y
    // caera a WAV o a silencio, sin romper el juego).
    // Referencia de tiers (PAYLOAD.md): Tier 0 = 816 WAV;
    // Tier 1 = 816 WAV + 231 ADP (TTH); Completo-ADP =
    // 816 WAV + 958 ADP. No se exige ningun tier aqui:
    // cualquier subconjunto es un overlay valido.
    private static void verifyAudio(File audioDir, StringBuilder report) {
        if (audioDir == null || !audioDir.isDirectory()) {
            report.append("saf: audio/ ausente (juego sin sonido: "
                    + "SFX y streams en silencio; anadir con "
                    + "'anadir audio' sin reimportar)\n");
            return;
        }
        AudioStats stats = new AudioStats();
        countAudio(audioDir, stats);
        report.append("saf: audio/ wav=").append(stats.wav)
                .append(" adp=").append(stats.adp)
                .append(" adp_invalidos=").append(stats.badAdp).append("\n");
        if (stats.badAdp > 0) {
            report.append("saf: aviso: audio/ tiene ").append(stats.badAdp)
                    .append(" ADP con tamano no multiplo de 32 "
                            + "(el bridge los saltara por fichero)");
            for (String name : stats.badNames) {
                report.append("\n     ").append(name);
            }
            report.append("\n");
        }
    }

    private static class AudioStats {
        int wav = 0;
        int adp = 0;
        int badAdp = 0;
        java.util.ArrayList<String> badNames = new java.util.ArrayList<>();
    }

    private static void countAudio(File dir, AudioStats stats) {
        File[] children = dir.listFiles();
        if (children == null) return;
        for (File child : children) {
            if (child.isDirectory()) {
                countAudio(child, stats);
            } else if (child.isFile()) {
                String name = child.getName().toLowerCase(
                        java.util.Locale.ROOT);
                if (name.endsWith(".wav")) {
                    stats.wav++;
                } else if (name.endsWith(".adp")) {
                    stats.adp++;
                    if (child.length() % 32 != 0) {
                        stats.badAdp++;
                        if (stats.badNames.size() < 10) {
                            stats.badNames.add(child.getPath());
                        }
                    }
                }
            }
        }
    }

    private static int countFiles(File dir) {
        if (dir == null || !dir.isDirectory()) return 0;
        int total = 0;
        File[] children = dir.listFiles();
        if (children == null) return 0;
        for (File child : children) {
            if (child.isDirectory()) total += countFiles(child);
            else if (child.isFile()) total++;
        }
        return total;
    }

    private static String sha1Hex(File file) throws IOException {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-1");
            try (InputStream in = new FileInputStream(file)) {
                byte[] buf = new byte[65536];
                int n;
                while ((n = in.read(buf)) >= 0) digest.update(buf, 0, n);
            }
            byte[] hash = digest.digest();
            StringBuilder hex = new StringBuilder();
            for (byte b : hash) hex.append(String.format("%02x", b));
            return hex.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new IOException("SHA-1 no disponible", e);
        }
    }

    // ---- boot.log compartido con el codigo nativo ----

    private void logSaf(String line) {
        Log.i(TAG, line);
        try {
            File internal = getFilesDir();
            if (internal == null) return;
            try (FileWriter writer = new FileWriter(
                    new File(internal, "boot.log"), true)) {
                writer.write(line);
                writer.write("\n");
            }
        } catch (Exception ignored) {
            // logcat ya tiene la linea; boot.log es secundario aqui.
        }
    }

    private static void writeText(File file, String text) throws IOException {
        try (FileWriter writer = new FileWriter(file, false)) {
            writer.write(text);
        }
    }

    private static void deleteQuietly(File file) {
        try {
            if (file != null) file.delete();
        } catch (Exception ignored) {
        }
    }
}
