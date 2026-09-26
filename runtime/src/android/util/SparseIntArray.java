package android.util;

import java.util.Arrays;

/**
 * Minimal desktop stand-in for android.util.SparseIntArray used by vendored
 * JL-Mod code. Keys are kept sorted, matching Android's keyAt/valueAt order.
 */
public class SparseIntArray {
    private int[] keys;
    private int[] values;
    private int size;

    public SparseIntArray() {
        this(10);
    }

    public SparseIntArray(int initialCapacity) {
        keys = new int[Math.max(1, initialCapacity)];
        values = new int[keys.length];
    }

    public int get(int key) {
        return get(key, 0);
    }

    public int get(int key, int valueIfKeyNotFound) {
        int i = Arrays.binarySearch(keys, 0, size, key);
        return i >= 0 ? values[i] : valueIfKeyNotFound;
    }

    public void put(int key, int value) {
        int i = Arrays.binarySearch(keys, 0, size, key);
        if (i >= 0) {
            values[i] = value;
            return;
        }
        i = ~i;
        if (size == keys.length) {
            keys = Arrays.copyOf(keys, size * 2);
            values = Arrays.copyOf(values, size * 2);
        }
        System.arraycopy(keys, i, keys, i + 1, size - i);
        System.arraycopy(values, i, values, i + 1, size - i);
        keys[i] = key;
        values[i] = value;
        size++;
    }

    public void append(int key, int value) {
        put(key, value);
    }

    public int keyAt(int index) {
        return keys[index];
    }

    public int valueAt(int index) {
        return values[index];
    }

    public int size() {
        return size;
    }
}
