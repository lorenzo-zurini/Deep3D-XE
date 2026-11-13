// Makes the original Nokia jar deterministic, as our DEEP3D_DET runs are:
// its clock reads go to deep3d.fj.Det.millis (a virtual 33 ms step), its four
// `new Random()` get the seeds our runs give the same sites (0x5EED + site),
// and its game loop calls deep3d.fj.Det.frame at the head of every pass,
// where Det::frame stands in cpp/game/DeepMIDlet.cpp.
//   java -cp asm.jar:asm-tree.jar:. Rewrite <in.jar> <out.jar>
import java.io.*;
import java.util.*;
import java.util.zip.*;

import org.objectweb.asm.*;
import org.objectweb.asm.tree.*;

public class Rewrite {
    /* the obfuscated classes of the a1 jar: de = class_124, db = class_24, p = class_7 */
    static final Map<String, int[]> RANDOM_SITES = Map.of("de", new int[] {1}, "db", new int[] {2, 3}, "p", new int[] {4});
    static final String DET = "deep3d/fj/Det";

    public static void main(String[] args) throws IOException {
        int clocks = 0, randoms = 0, loops = 0;
        try (ZipInputStream in = new ZipInputStream(new FileInputStream(args[0]));
             ZipOutputStream out = new ZipOutputStream(new FileOutputStream(args[1]))) {
            for (ZipEntry e; (e = in.getNextEntry()) != null; ) {
                byte[] data = in.readAllBytes();
                if (e.getName().endsWith(".class")) {
                    ClassNode c = new ClassNode();
                    new ClassReader(data).accept(c, 0);
                    int[] sites = RANDOM_SITES.get(c.name);
                    int site = 0;
                    for (MethodNode m : c.methods) {
                        for (AbstractInsnNode n = m.instructions.getFirst(); n != null; n = n.getNext()) {
                            if (n instanceof MethodInsnNode mi && mi.owner.equals("java/lang/System") && mi.name.equals("currentTimeMillis")) {
                                mi.owner = DET;
                                mi.name = "millis";
                                clocks++;
                            } else if (n instanceof MethodInsnNode mi && mi.getOpcode() == Opcodes.INVOKESPECIAL
                                       && mi.owner.equals("java/util/Random") && mi.name.equals("<init>") && mi.desc.equals("()V")) {
                                // new Random; dup; invokespecial <init>()V  ->  ldc site; invokestatic Det.random(I)
                                AbstractInsnNode dup = prev(mi), neu = dup == null ? null : prev(dup);
                                if (sites == null || site >= sites.length || dup.getOpcode() != Opcodes.DUP || neu.getOpcode() != Opcodes.NEW)
                                    throw new IllegalStateException("unexpected Random in " + c.name + "." + m.name);
                                m.instructions.insertBefore(mi, new LdcInsnNode(sites[site++]));
                                MethodInsnNode call = new MethodInsnNode(Opcodes.INVOKESTATIC, DET, "random", "(I)Ljava/util/Random;");
                                m.instructions.set(mi, call);
                                m.instructions.remove(dup);
                                m.instructions.remove(neu);
                                n = call;
                                randoms++;
                            }
                        }
                        if (c.name.equals("DeepMIDlet") && m.name.equals("run") && m.desc.equals("()V")) {
                            // the loop jumps back to the method's first instruction
                            AbstractInsnNode head = m.instructions.getFirst();
                            while (head != null && !(head instanceof LabelNode)) head = head.getNext();
                            if (head == null) throw new IllegalStateException("no loop head in DeepMIDlet.run");
                            m.instructions.insert(head, new MethodInsnNode(Opcodes.INVOKESTATIC, DET, "frame", "()V"));
                            loops++;
                        }
                    }
                    if (sites != null && site != sites.length) throw new IllegalStateException("Random sites in " + c.name + ": " + site);
                    ClassWriter w = new ClassWriter(ClassWriter.COMPUTE_MAXS);
                    c.accept(w);
                    data = w.toByteArray();
                }
                ZipEntry o = new ZipEntry(e.getName());
                out.putNextEntry(o);
                out.write(data);
                out.closeEntry();
            }
        }
        System.out.printf("clock reads %d, randoms %d, loop heads %d%n", clocks, randoms, loops);
        if (randoms != 4 || loops != 1) throw new IllegalStateException("expected 4 randoms and 1 loop head");
    }

    static AbstractInsnNode prev(AbstractInsnNode n) {
        do n = n.getPrevious(); while (n != null && n.getOpcode() < 0);   // labels, line numbers
        return n;
    }
}
