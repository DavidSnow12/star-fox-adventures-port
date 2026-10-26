package com.starfox.port;

import android.app.NativeActivity;
import android.content.ContentResolver;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
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
 * Sin datos, la app nunca falla: queda en clear + quad de
 * prueba, como antes. NUNCA se meten datos ni disco en Git
 * ni en la APK: solo se copian desde la carpeta del usuario.
 * Progreso y errores van a boot.log (el mismo fichero que
 * el log nativo, en la carpeta interna) y a logcat.
 */
public class MainActivity extends NativeActivity {
    private static final String TAG = "StarFoxPort";
    private static final int REQUEST_DATA_FOLDER = 4242;

    // Verificacion Pack B (ver PORT-STATUS, via de datos).
    private static final long EXPECTED_DOL_SIZE = 3405600L;
    private static final String EXPECTED_DOL_SHA1 =
            "c1a6ccdc61c7e719e20ea7cc59c8de09fd183e66";
    private static final int EXPECTED_FILES_MIN = 2916;

    private volatile boolean copyRunning = false;

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

    @Override
    protected void onActivityResult(int requestCode, int resultCode,
                                    Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != REQUEST_DATA_FOLDER) return;
        if (resultCode != RESULT_OK || data == null || data.getData() == null) {
            logSaf("saf: picker cancelado por el usuario; sin datos, "
                    + "la app sigue en modo clear + quad");
            return;
        }
        Uri treeUri = data.getData();
        try {
            getContentResolver().takePersistableUriPermission(treeUri,
                    Intent.FLAG_GRANT_READ_URI_PERMISSION);
        } catch (Exception e) {
            logSaf("saf: aviso, permiso persistente no retenido: " + e);
        }
        if (copyRunning) {
            logSaf("saf: copia ya en marcha, se ignora la segunda seleccion");
            return;
        }
        copyRunning = true;
        new Thread(() -> copyDataTree(treeUri)).start();
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
