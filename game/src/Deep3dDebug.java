// Deep3D-PC: test hooks (the input pipe's "call Deep3dDebug <method> <int>")
public final class Deep3dDebug {
   private Deep3dDebug() {
   }

   // Makes station n (data/txt/stations.txt order) the current one; the
   // next flight scene is built around it. Returns its depth.
   public static int warp(int n) {
      class_86 var1 = class_38.method_354(n);
      class_21.method_181(var1);
      System.out.println("[warp] " + var1.field_1133 + " depth " + var1.field_1140);
      return var1.field_1140;
   }
}
