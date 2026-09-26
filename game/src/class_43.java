// $VF: renamed from: cd
public final class class_43 {
   // $VF: renamed from: a int[]
   private static int[] field_466;
   // $VF: renamed from: a cc[]
   private static class_44[] field_467;
   // $VF: renamed from: a java.lang.String[]
   private static String[] field_468;
   // $VF: renamed from: a boolean[]
   private static boolean[] field_469;
   // $VF: renamed from: b int[]
   private static int[] field_470;
   // $VF: renamed from: a ax[]
   private static class_108[] field_471;
   // $VF: renamed from: c int[]
   private static int[] field_472;
   // $VF: renamed from: b java.lang.String[]
   private static String[] field_473;
   // $VF: renamed from: b boolean[]
   private static boolean[] field_474;
   // $VF: renamed from: d int[]
   private static int[] field_475;

   // $VF: renamed from: a (int, java.lang.String) void
   public static final void method_377(int var0, String var1) {
      if (field_468 == null) {
         field_468 = new String[1];
         field_468[0] = var1;
         field_467 = new class_44[1];
         field_466 = new int[1];
         field_466[0] = var0;
         field_469 = new boolean[1];
         field_469[0] = false;
      } else {
         String[] var2 = new String[field_468.length + 1];
         System.arraycopy(field_468, 0, var2, 0, field_468.length);
         var2[field_468.length] = var1;
         field_468 = var2;
         class_44[] var3 = new class_44[field_467.length + 1];
         System.arraycopy(field_467, 0, var3, 0, field_467.length);
         field_467 = var3;
         int[] var4 = new int[field_466.length + 1];
         System.arraycopy(field_466, 0, var4, 0, field_466.length);
         var4[field_466.length] = var0;
         field_466 = var4;
         boolean[] var5 = new boolean[field_469.length + 1];
         System.arraycopy(field_469, 0, var5, 0, field_469.length);
         var5[field_469.length] = false;
         field_469 = var5;
      }
   }

   // $VF: renamed from: a (int, java.lang.String, int, int) void
   public static final void method_378(int var0, String var1, int var2, int var3) {
      if (field_473 == null) {
         field_473 = new String[1];
         field_473[0] = var1;
         field_472 = new int[1];
         field_472[0] = var2;
         field_471 = new class_108[1];
         field_470 = new int[1];
         field_470[0] = var0;
         field_474 = new boolean[1];
         field_474[0] = false;
         field_475 = new int[1];
         field_475[0] = var3;
      } else {
         String[] var4 = new String[field_473.length + 1];
         System.arraycopy(field_473, 0, var4, 0, field_473.length);
         var4[field_473.length] = var1;
         field_473 = var4;
         int[] var5 = new int[field_472.length + 1];
         System.arraycopy(field_472, 0, var5, 0, field_472.length);
         var5[field_472.length] = var2;
         field_472 = var5;
         class_108[] var6 = new class_108[field_471.length + 1];
         System.arraycopy(field_471, 0, var6, 0, field_471.length);
         field_471 = var6;
         int[] var7 = new int[field_470.length + 1];
         System.arraycopy(field_470, 0, var7, 0, field_470.length);
         var7[field_470.length] = var0;
         field_470 = var7;
         boolean[] var8 = new boolean[field_474.length + 1];
         System.arraycopy(field_474, 0, var8, 0, field_474.length);
         var8[field_474.length] = false;
         field_474 = var8;
         int[] var9 = new int[field_475.length + 1];
         System.arraycopy(field_475, 0, var9, 0, field_475.length);
         var9[field_475.length] = var3;
         field_475 = var9;
      }
   }

   // $VF: renamed from: a (int, java.lang.String, int) void
   public static final void method_379(int var0, String var1, int var2) {
      method_378(var0, var1, -1, var2);
   }

   // $VF: renamed from: a (int) cc
   public static final class_44 method_380(int var0) {
      for (int var1 = 0; var1 < field_466.length; var1++) {
         if (var0 == field_466[var1]) {
            field_469[var1] = true;
            if (field_467[var1] == null) {
               String[] var2 = new String[]{field_468[var1]};
               return field_467[var1] = class_44.method_386(var2);
            }

            return field_467[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (int) ax
   public static final class_108 method_381(int var0) {
      for (int var1 = 0; var1 < field_470.length; var1++) {
         if (var0 == field_470[var1]) {
            field_474[var1] = true;
            if (field_471[var1] == null) {
               if (field_472[var1] == -1) {
                  field_471[var1] = class_108.method_891(field_470[var1], field_473[var1]);
               } else {
                  field_471[var1] = class_108.method_889(field_470[var1], field_473[var1], field_472[var1]);
               }

               if (field_471[var1] != null && field_475[var1] != Integer.MIN_VALUE) {
                  field_471[var1].method_893(method_380(field_475[var1]));
               }

               return field_471[var1];
            }

            return (class_108)field_471[var1].method_840();
         }
      }

      System.out.println("ERROR | AEResourceManager.getGeometryResource(" + var0 + ") not found !");
      return null;
   }

   // $VF: renamed from: a () void
   public static final void method_382() {
      method_383();
      method_385();
   }

   // $VF: renamed from: b () void
   public static final void method_383() {
      for (int var0 = 0; var0 < field_471.length; var0++) {
         if (field_471[var0] != null) {
            field_471[var0].method_894();
            field_471[var0] = null;
         }
      }
   }

   // $VF: renamed from: c () void
   public static final void method_384() {
      for (int var0 = 0; var0 < field_471.length; var0++) {
         if (field_471[var0] != null) {
            field_471[var0].method_870(new class_57());
         }
      }
   }

   // $VF: renamed from: d () void
   public static final void method_385() {
      for (int var0 = 0; var0 < field_467.length; var0++) {
         if (field_467[var0] != null) {
            field_467[var0].method_387();
            field_467[var0] = null;
         }
      }
   }
}
