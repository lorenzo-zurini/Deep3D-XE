// $VF: renamed from: cd
public final class class_25 {
   // $VF: renamed from: a int[]
   private static int[] field_380;
   // $VF: renamed from: a cc[]
   private static class_120[] field_381;
   // $VF: renamed from: a java.lang.String[]
   private static String[] field_382;
   // $VF: renamed from: a boolean[]
   private static boolean[] field_383;
   // $VF: renamed from: b int[]
   private static int[] field_384;
   // $VF: renamed from: a ay[]
   private static class_101[] field_385;
   // $VF: renamed from: c int[]
   private static int[] field_386;
   // $VF: renamed from: b java.lang.String[]
   private static String[] field_387;
   // $VF: renamed from: b boolean[]
   private static boolean[] field_388;
   // $VF: renamed from: d int[]
   private static int[] field_389;

   // $VF: renamed from: a (int, java.lang.String) void
   public static final void method_324(int var0, String var1) {
      if (field_382 == null) {
         field_382 = new String[1];
         field_382[0] = var1;
         field_381 = new class_120[1];
         field_380 = new int[1];
         field_380[0] = var0;
         field_383 = new boolean[1];
         field_383[0] = false;
      } else {
         String[] var2 = new String[field_382.length + 1];
         System.arraycopy(field_382, 0, var2, 0, field_382.length);
         var2[field_382.length] = var1;
         field_382 = var2;
         class_120[] var3 = new class_120[field_381.length + 1];
         System.arraycopy(field_381, 0, var3, 0, field_381.length);
         field_381 = var3;
         int[] var4 = new int[field_380.length + 1];
         System.arraycopy(field_380, 0, var4, 0, field_380.length);
         var4[field_380.length] = var0;
         field_380 = var4;
         boolean[] var5 = new boolean[field_383.length + 1];
         System.arraycopy(field_383, 0, var5, 0, field_383.length);
         var5[field_383.length] = false;
         field_383 = var5;
      }
   }

   // $VF: renamed from: a (int, java.lang.String, int, int) void
   public static final void method_325(int var0, String var1, int var2, int var3) {
      if (field_387 == null) {
         field_387 = new String[1];
         field_387[0] = var1;
         field_386 = new int[1];
         field_386[0] = var2;
         field_385 = new class_101[1];
         field_384 = new int[1];
         field_384[0] = var0;
         field_388 = new boolean[1];
         field_388[0] = false;
         field_389 = new int[1];
         field_389[0] = var3;
      } else {
         String[] var4 = new String[field_387.length + 1];
         System.arraycopy(field_387, 0, var4, 0, field_387.length);
         var4[field_387.length] = var1;
         field_387 = var4;
         int[] var5 = new int[field_386.length + 1];
         System.arraycopy(field_386, 0, var5, 0, field_386.length);
         var5[field_386.length] = var2;
         field_386 = var5;
         class_101[] var6 = new class_101[field_385.length + 1];
         System.arraycopy(field_385, 0, var6, 0, field_385.length);
         field_385 = var6;
         int[] var7 = new int[field_384.length + 1];
         System.arraycopy(field_384, 0, var7, 0, field_384.length);
         var7[field_384.length] = var0;
         field_384 = var7;
         boolean[] var8 = new boolean[field_388.length + 1];
         System.arraycopy(field_388, 0, var8, 0, field_388.length);
         var8[field_388.length] = false;
         field_388 = var8;
         int[] var9 = new int[field_389.length + 1];
         System.arraycopy(field_389, 0, var9, 0, field_389.length);
         var9[field_389.length] = var3;
         field_389 = var9;
      }
   }

   // $VF: renamed from: a (int, java.lang.String, int) void
   public static final void method_326(int var0, String var1, int var2) {
      method_325(var0, var1, -1, var2);
   }

   // $VF: renamed from: a (int) cc
   public static final class_120 method_327(int var0) {
      for (int var1 = 0; var1 < field_380.length; var1++) {
         if (var0 == field_380[var1]) {
            field_383[var1] = true;
            if (field_381[var1] == null) {
               String[] var2 = new String[]{field_382[var1]};
               return field_381[var1] = class_120.method_929(var2);
            }

            return field_381[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (int) ay
   public static final class_101 method_328(int var0) {
      for (int var1 = 0; var1 < field_384.length; var1++) {
         if (var0 == field_384[var1]) {
            field_388[var1] = true;
            if (field_385[var1] == null) {
               if (field_386[var1] == -1) {
                  field_385[var1] = class_101.method_881(field_384[var1], field_387[var1]);
               } else {
                  field_385[var1] = class_101.method_879(field_384[var1], field_387[var1], field_386[var1]);
               }

               if (field_385[var1] != null && field_389[var1] != Integer.MIN_VALUE) {
                  field_385[var1].method_883(method_327(field_389[var1]));
               }

               return field_385[var1];
            }

            return (class_101)field_385[var1].method_836();
         }
      }

      System.out.println("ERROR | AEResourceManager.getGeometryResource(" + var0 + ") not found !");
      return null;
   }

   // $VF: renamed from: a () void
   public static final void method_329() {
      method_330();
      method_332();
   }

   // $VF: renamed from: b () void
   public static final void method_330() {
      for (int var0 = 0; var0 < field_385.length; var0++) {
         if (field_385[var0] != null) {
            field_385[var0].method_884();
            field_385[var0] = null;
         }
      }
   }

   // $VF: renamed from: c () void
   public static final void method_331() {
      for (int var0 = 0; var0 < field_385.length; var0++) {
         if (field_385[var0] != null) {
            field_385[var0].method_866(new class_1());
         }
      }
   }

   // $VF: renamed from: d () void
   public static final void method_332() {
      for (int var0 = 0; var0 < field_381.length; var0++) {
         if (field_381[var0] != null) {
            field_381[var0].method_930();
            field_381[var0] = null;
         }
      }
   }
}
