// The original game's deterministic clock inside FreeJ2ME (see Rewrite.java;
// build.sh puts this class in the game's jar, which FreeJ2ME loads it from,
// so no lambdas: its class adapter takes the old class file features only):
// the same virtual clock, seeds, key timing and pass numbering as DEEP3D_DET=1
// in cpp/deep3d/Det.cpp, so pass N here is pass N there.
//   FJ_KEYS=<file>  lines "<pass> p|r <MIDP key code>": pressed or released at the start of that pass
//   FJ_SHOTS=<n>    the frame presented in every n-th pass, as FJ_OUT/p<pass>.png (240x320, the LCD)
//   FJ_END=<pass>   exits after that pass
//   FJ_DUMP=<pass,...> the game's state at the start of those passes, as FJ_OUT/det_<pass>.txt, in
//                   the format and names of our build's DEEP3D_DET_DUMP (DEEP3D_PHONE: the original's
//                   state only), so the two compare line by line
package deep3d.fj;

import java.awt.image.BufferedImage;
import java.io.*;
import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.nio.file.*;
import java.util.*;

import javax.imageio.ImageIO;
import javax.microedition.lcdui.Displayable;

import org.recompile.mobile.Mobile;
import org.recompile.mobile.MobilePlatform;

public final class Det {
    private static long now = 1000000000000L;
    private static int pass;
    private static final TreeMap<Integer, List<int[]>> KEYS = new TreeMap<Integer, List<int[]>>();
    private static final int SHOT_EVERY = Integer.parseInt(env("FJ_SHOTS", "0"));
    private static final int END = Integer.parseInt(env("FJ_END", "0"));
    private static final String OUT = env("FJ_OUT", ".");
    private static volatile int pendingShot;
    private static boolean hooked;
    private static final Set<Integer> DUMPS = new HashSet<Integer>();

    static {
        String f = System.getenv("FJ_KEYS");
        if (f != null && !f.isEmpty()) {
            try {
                for (String l : Files.readAllLines(Paths.get(f))) {
                    l = l.replaceAll("#.*", "").trim();
                    if (l.isEmpty()) continue;
                    String[] w = l.split("\\s+");
                    Integer at = Integer.valueOf(Integer.parseInt(w[0]));
                    List<int[]> list = KEYS.get(at);
                    if (list == null) KEYS.put(at, list = new ArrayList<int[]>());
                    list.add(new int[] {Integer.parseInt(w[2]), w[1].equals("p") ? 1 : 0});
                }
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }
    }

    static {
        String d = System.getenv("FJ_DUMP");
        if (d != null && !d.isEmpty()) for (String p : d.split(",")) DUMPS.add(Integer.valueOf(p.trim()));
    }

    private static String env(String k, String d) {
        String v = System.getenv(k);
        return v == null ? d : v;
    }

    public static long millis() { return now; }

    public static Random random(int site) { return new Random(0x5EED + site); }

    /** The head of a game loop pass (the game thread). */
    public static void frame() {
        if (!hooked) hook();
        pass++;
        now += 33;
        List<int[]> keys = KEYS.get(pass);
        if (DUMPS.contains(Integer.valueOf(pass))) writeDump();
        if (keys != null) for (int[] k : keys) deliver(k[0], k[1] == 1);
        if (SHOT_EVERY > 0 && pass % SHOT_EVERY == 0) pendingShot = pass;
        if (END > 0 && pass > END) {
            System.out.println("[fj] end at pass " + pass);
            System.exit(0);
        }
    }

    /* straight to the Canvas on the game thread, as Det::deliverKeys does */
    private static void deliver(int code, boolean pressed) {
        Displayable d = Mobile.getDisplay().getCurrent();
        String name = pressed ? "keyPressed" : "keyReleased";
        for (Class<?> c = d == null ? null : d.getClass(); c != null; c = c.getSuperclass()) {
            try {
                Method m = c.getDeclaredMethod(name, int.class);
                m.setAccessible(true);
                m.invoke(d, code);
                return;
            } catch (NoSuchMethodException e) {
                // the superclass, then
            } catch (ReflectiveOperationException e) {
                throw new RuntimeException(e);
            }
        }
        System.out.println("[fj] pass " + pass + ": no canvas for key " + code);
    }

    /* FreeJ2ME's painter, which runs when the game flushes a frame: shots first.
       Set up from here, as the game's own class loader has this class. */
    private static void hook() {
        MobilePlatform p = Mobile.getPlatform();
        Runnable r = p == null ? null : p.painter;
        if (r == null || !r.getClass().getName().startsWith("org.recompile.freej2me.")) return;
        final Runnable inner = r;
        p.painter = new Runnable() {
            public void run() {
                painted();
                inner.run();
            }
        };
        hooked = true;
    }

    /** The game flushed a frame. */
    public static void painted() {
        int p = pendingShot;
        if (p == 0) return;
        pendingShot = 0;
        BufferedImage lcd = Mobile.getPlatform().getLCD();
        BufferedImage copy = new BufferedImage(lcd.getWidth(), lcd.getHeight(), BufferedImage.TYPE_INT_RGB);
        copy.getGraphics().drawImage(lcd, 0, 0, null);
        try {
            ImageIO.write(copy, "png", new File(OUT, String.format("p%06d.png", p)));
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    public static int pass() { return pass; }

    // ------------------------------------------------------------------
    // The state as text: tools/phoneref's port of the Java build's dump
    // (Deep3D-XE-javaref Det.java), with the decompiled names (fieldmap.tsv)
    // ------------------------------------------------------------------

    private static Map<String, String> classNames, fieldNames;   // obfuscated -> decompiled
    private static List<Class<?>> classes;
    private static IdentityHashMap<Object, Integer> ids;
    private static StringBuilder out;

    private static void loadNames() throws IOException {
        classNames = new HashMap<String, String>();
        fieldNames = new HashMap<String, String>();
        BufferedReader r = new BufferedReader(new InputStreamReader(Det.class.getResourceAsStream("/deep3d/fj/fieldmap.tsv"), "UTF-8"));
        for (String l; (l = r.readLine()) != null; ) {
            String[] w = l.split("\t");
            if (w[0].equals("C")) classNames.put(w[1], w[2]);
            else fieldNames.put(w[1] + " " + w[2] + " " + w[3], w[4]);
        }
        List<String> obf = new ArrayList<String>(classNames.keySet());
        Collections.sort(obf, new Comparator<String>() {
            public int compare(String a, String b) { return classNames.get(a).compareTo(classNames.get(b)); }
        });
        classes = new ArrayList<Class<?>>();
        for (String o : obf) {
            String n = classNames.get(o);
            if (n.equals("class_33") || n.equals("class_0")) continue;   // the loading screen's own thread; no class
            try {
                classes.add(Class.forName(o, true, Det.class.getClassLoader()));
            } catch (ClassNotFoundException e) {
                // not in this jar
            }
        }
    }

    private static void writeDump() {
        try {
            if (classes == null) loadNames();
            ids = new IdentityHashMap<Object, Integer>();
            out = new StringBuilder(1 << 20);
            for (Class<?> c : classes) {
                for (Field f : sorted(c, true)) {
                    out.append(classNames.get(c.getName())).append('.').append(name(f)).append('=');
                    value(f.get(null), f.getType());
                    out.append('\n');
                }
            }
            Writer w = new OutputStreamWriter(new FileOutputStream(new File(OUT, "det_" + pass + ".txt")), "UTF-8");
            w.write(out.toString());
            w.close();
        } catch (Exception e) {
            System.out.println("[fj] dump at pass " + pass + ": " + e);
        } finally {
            out = null;
            ids = null;
        }
    }

    private static String name(Field f) {
        String n = fieldNames.get(f.getDeclaringClass().getName() + " " + f.getName() + " " + typeName(f.getType()));
        return n != null ? n : f.getName() + "?";
    }

    private static String typeName(Class<?> t) {
        return t.isArray() ? typeName(t.getComponentType()) + "[]" : t.getName();
    }

    private static List<Field> sorted(Class<?> c, boolean statics) {
        final List<Field> l = new ArrayList<Field>();
        for (Field f : c.getDeclaredFields()) {
            if (Modifier.isStatic(f.getModifiers()) == statics && !f.isSynthetic()) {
                f.setAccessible(true);
                l.add(f);
            }
        }
        Collections.sort(l, new Comparator<Field>() {
            public int compare(Field a, Field b) { return name(a).compareTo(name(b)); }
        });
        return l;
    }

    private static boolean gameClass(Class<?> c) {
        return classNames.containsKey(c.getName());
    }

    private static void value(Object v, Class<?> type) throws Exception {
        if (type.isPrimitive()) {
            if (type == boolean.class) out.append(((Boolean) v).booleanValue());
            else if (type == char.class) out.append('c').append((int) ((Character) v).charValue());
            else if (type == float.class) out.append('f').append(Integer.toHexString(Float.floatToIntBits(((Float) v).floatValue())));
            else if (type == double.class) out.append('d').append(Long.toHexString(Double.doubleToLongBits(((Double) v).doubleValue())));
            else out.append(((Number) v).longValue());
            return;
        }
        if (v == null) {
            out.append("null");
            return;
        }
        if (v instanceof String) {
            out.append('"').append((String) v).append('"');
            return;
        }
        if (v instanceof Random) {
            Field seed = Random.class.getDeclaredField("seed");
            seed.setAccessible(true);
            out.append('R').append(Long.toHexString(((java.util.concurrent.atomic.AtomicLong) seed.get(v)).get()));
            return;
        }
        Class<?> c = v.getClass();
        if (!c.isArray() && (!gameClass(c) || classNames.get(c.getName()).equals("class_33"))) {
            out.append("<obj>");
            return;
        }
        Integer id = ids.get(v);
        if (id != null) {
            out.append('@').append(id.intValue());
            return;
        }
        id = Integer.valueOf(ids.size());
        ids.put(v, id);
        out.append('#').append(id.intValue());
        if (c.isArray()) {
            Class<?> et = c.getComponentType();
            out.append('[');
            int n = Array.getLength(v);
            for (int i = 0; i < n; i++) {
                if (i > 0) out.append(',');
                value(Array.get(v, i), et);
            }
            out.append(']');
            return;
        }
        out.append(' ').append(classNames.get(c.getName())).append('{');
        List<Class<?>> chain = new ArrayList<Class<?>>();
        for (Class<?> k = c; k != null && gameClass(k); k = k.getSuperclass()) chain.add(0, k);
        for (Class<?> k : chain) {
            for (Field f : sorted(k, false)) {
                out.append(name(f)).append('=');
                value(f.get(v), f.getType());
                out.append(';');
            }
        }
        out.append('}');
    }
}
