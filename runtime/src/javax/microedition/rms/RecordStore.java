package javax.microedition.rms;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * File-backed MIDP record store. Each store is one file in the save
 * directory holding a record count followed by length-prefixed records.
 * Record IDs are 1-based; deleted records are kept as null slots, matching
 * MIDP semantics closely enough for the game's save code.
 */
public class RecordStore {

    private static File saveDir() {
        String dir = System.getenv("DEEP3D_SAVE_DIR");
        if (dir != null && !dir.isEmpty()) {
            File f = new File(dir);
            f.mkdirs();
            return f;
        }
        return org.deep3d.AppDirs.dir("saves");
    }

    private final String name;
    private final File file;
    private final List<byte[]> records = new ArrayList<>();
    private boolean open;

    private RecordStore(String name) {
        this.name = name;
        this.file = new File(saveDir(), sanitize(name) + ".rms");
    }

    private static String sanitize(String name) {
        return name.replaceAll("[^A-Za-z0-9_.-]", "_");
    }

    public static RecordStore openRecordStore(String name, boolean createIfNecessary)
            throws RecordStoreException {
        RecordStore rs = new RecordStore(name);
        if (rs.file.exists()) {
            rs.load();
        } else if (!createIfNecessary) {
            throw new RecordStoreNotFoundException(name);
        }
        rs.open = true;
        return rs;
    }

    public static void deleteRecordStore(String name) throws RecordStoreException {
        File f = new File(saveDir(), sanitize(name) + ".rms");
        if (!f.exists()) {
            throw new RecordStoreNotFoundException(name);
        }
        if (!f.delete()) {
            throw new RecordStoreException("cannot delete " + name);
        }
    }

    public static String[] listRecordStores() {
        String[] files = saveDir().list((d, n) -> n.endsWith(".rms"));
        if (files == null || files.length == 0) {
            return null;
        }
        for (int i = 0; i < files.length; i++) {
            files[i] = files[i].substring(0, files[i].length() - 4);
        }
        return files;
    }

    private void load() throws RecordStoreException {
        records.clear();
        try (DataInputStream in = new DataInputStream(new FileInputStream(file))) {
            int count = in.readInt();
            for (int i = 0; i < count; i++) {
                int len = in.readInt();
                if (len < 0) {
                    records.add(null);
                } else {
                    byte[] data = new byte[len];
                    in.readFully(data);
                    records.add(data);
                }
            }
        } catch (IOException e) {
            throw new RecordStoreException("cannot read " + name + ": " + e);
        }
    }

    private void save() throws RecordStoreException {
        try (DataOutputStream out = new DataOutputStream(new FileOutputStream(file))) {
            out.writeInt(records.size());
            for (byte[] r : records) {
                if (r == null) {
                    out.writeInt(-1);
                } else {
                    out.writeInt(r.length);
                    out.write(r);
                }
            }
        } catch (IOException e) {
            throw new RecordStoreException("cannot write " + name + ": " + e);
        }
    }

    private void checkOpen() throws RecordStoreNotOpenException {
        if (!open) {
            throw new RecordStoreNotOpenException(name);
        }
    }

    public void closeRecordStore() throws RecordStoreException {
        checkOpen();
        open = false;
    }

    public String getName() {
        return name;
    }

    public int addRecord(byte[] data, int offset, int numBytes) throws RecordStoreException {
        checkOpen();
        byte[] copy = new byte[numBytes];
        if (numBytes > 0) {
            System.arraycopy(data, offset, copy, 0, numBytes);
        }
        records.add(copy);
        save();
        return records.size();
    }

    public void setRecord(int recordId, byte[] data, int offset, int numBytes)
            throws RecordStoreException {
        checkOpen();
        checkId(recordId);
        byte[] copy = new byte[numBytes];
        if (numBytes > 0) {
            System.arraycopy(data, offset, copy, 0, numBytes);
        }
        records.set(recordId - 1, copy);
        save();
    }

    public void deleteRecord(int recordId) throws RecordStoreException {
        checkOpen();
        checkId(recordId);
        records.set(recordId - 1, null);
        save();
    }

    public byte[] getRecord(int recordId) throws RecordStoreException {
        checkOpen();
        checkId(recordId);
        byte[] r = records.get(recordId - 1);
        return r == null ? null : r.clone();
    }

    public int getRecord(int recordId, byte[] buffer, int offset) throws RecordStoreException {
        byte[] r = getRecord(recordId);
        if (r == null) {
            return 0;
        }
        System.arraycopy(r, 0, buffer, offset, r.length);
        return r.length;
    }

    public int getRecordSize(int recordId) throws RecordStoreException {
        byte[] r = getRecord(recordId);
        return r == null ? 0 : r.length;
    }

    public int getNumRecords() throws RecordStoreNotOpenException {
        checkOpen();
        int n = 0;
        for (byte[] r : records) {
            if (r != null) {
                n++;
            }
        }
        return n;
    }

    public int getNextRecordID() throws RecordStoreException {
        checkOpen();
        return records.size() + 1;
    }

    public int getSize() throws RecordStoreNotOpenException {
        checkOpen();
        int n = 0;
        for (byte[] r : records) {
            if (r != null) {
                n += r.length;
            }
        }
        return n;
    }

    public int getSizeAvailable() throws RecordStoreNotOpenException {
        checkOpen();
        return Integer.MAX_VALUE;
    }

    private void checkId(int recordId) throws InvalidRecordIDException {
        if (recordId < 1 || recordId > records.size() || records.get(recordId - 1) == null) {
            throw new InvalidRecordIDException("record " + recordId + " in " + name);
        }
    }
}
