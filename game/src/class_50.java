import javax.microedition.lcdui.Graphics;

// $VF: renamed from: bm
public final class class_50 {
   // $VF: renamed from: a ba[]
   private static class_70[] field_707;
   // $VF: renamed from: a javax.microedition.lcdui.Graphics
   private static Graphics field_708;
   // $VF: renamed from: a int
   private static int field_709;

   // $VF: renamed from: a () void
   public static final void method_480() {
      field_707 = null;
      System.gc();
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Graphics) void
   public static final void method_481(Graphics var0) {
      field_708 = var0;
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_482(String var0) {
      if (field_708 != null) {
         if (field_707 == null) {
            field_707 = new class_70[1];
            field_707[0] = new class_70(var0, field_708);
            return;
         }

         class_70[] var1 = new class_70[field_707.length + 1];
         System.arraycopy(field_707, 0, var1, 0, field_707.length);
         var1[field_707.length] = new class_70(var0, field_708);
         field_707 = var1;
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int) void
   public static final void method_483(String var0, int var1, int var2, int var3, int var4) {
      if (var3 >= 0 && var3 < field_707.length) {
         field_709 = var3;
         if ((var4 & 8) != 0) {
            var1 -= field_707[field_709].method_682(var0) >> 1;
         }

         if ((var4 & 4) != 0) {
            var2 -= field_707[field_709].field_1026 >> 1;
         } else if ((var4 & 32) != 0) {
            var2 -= field_707[field_709].field_1026;
         }

         if ((var4 & 2) != 0) {
            field_707[field_709].method_686(var0, var1, var2);
         } else {
            field_707[field_709].method_685(var0, var1, var2);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int) void
   public static final void method_484(String var0, int var1, int var2) {
      field_707[field_709].method_685(var0, var1, var2);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int) void
   public static final void method_485(String var0, int var1, int var2, int var3) {
      if (var3 >= 0 && var3 < field_707.length) {
         field_709 = var3;
         field_707[field_709].method_685(var0, var1, var2);
      }
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int, int) void
   public static final void method_486(String[] var0, int var1, int var2, int var3, int var4) {
      method_487(var0, var1, var2, var3, var4, 0, var0.length - 1);
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int, int, int, int) void
   public static final void method_487(String[] var0, int var1, int var2, int var3, int var4, int var5, int var6) {
      var6 = var6 <= var0.length - 1 ? var6 : var0.length - 1;
      var5 = var5 <= var6 ? var5 : var6;
      if (var3 >= 0 && var3 < field_707.length) {
         field_709 = var3;
         switch (var4) {
            case 1:
               int var12 = var5;

               for (int var14 = 0; var12 < var6 + 1; var14++) {
                  field_707[field_709].method_685(var0[var12], var1, var2 + var14 * method_494());
                  var12++;
               }

               return;
            case 2:
               int var11 = var5;

               for (int var13 = 0; var11 < var6 + 1; var13++) {
                  field_707[field_709].method_687(var0[var11], var1, var2 + var13 * method_494());
                  var11++;
               }

               return;
            case 3:
               int var7 = var5;

               for (int var8 = 0; var7 < var6 + 1; var8++) {
                  field_707[field_709].method_685(var0[var7], var1 - (method_490(var0[var7]) >> 1), var2 + var8 * method_494());
                  var7++;
               }
         }
      }
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int) void
   public static final void method_488(String[] var0, int var1, int var2, int var3) {
      if (var3 >= 0 && var3 < field_707.length) {
         field_709 = var3;

         for (int var4 = 0; var4 < var0.length; var4++) {
            field_707[field_709].method_685(var0[var4], var1, var2 + var4 * method_494());
         }
      }
   }

   // $VF: renamed from: a (int, int, int, int, int) void
   public static final void method_489(int var0, int var1, int var2, int var3, int var4) {
      if (var4 >= 0 && var4 < field_707.length) {
         field_707[var4].method_679(var0, var1, var2, var3);
      }
   }

   // $VF: renamed from: a (java.lang.String) int
   public static final int method_490(String var0) {
      return field_707[field_709].method_682(var0);
   }

   // $VF: renamed from: a (java.lang.String, int, int) int
   public static final int method_491(String var0, int var1, int var2) {
      return field_707[field_709].method_683(var0, var1, var2);
   }

   // $VF: renamed from: a (int) void
   public static final void method_492(int var0) {
      field_707[field_709].method_680(var0);
   }

   // $VF: renamed from: a (int, int) void
   public static final void method_493(int var0, int var1) {
      if (var1 >= 0 && var1 < field_707.length) {
         field_707[var1].method_680(var0);
      }
   }

   // $VF: renamed from: a () int
   public static final int method_494() {
      return field_707[field_709].field_1026;
   }

   // $VF: renamed from: b () int
   public static final int method_495() {
      return field_707[field_709].field_1027;
   }

   // $VF: renamed from: b (int) void
   public static final void method_496(int var0) {
      field_707[field_709].method_688(var0);
   }

   // $VF: renamed from: a (java.lang.String[]) int
   public static final int method_497(String[] var0) {
      return field_707[field_709].field_1026 * var0.length;
   }

   // $VF: renamed from: b (int, int) void
   public static final void method_498(int var0, int var1) {
      if (var1 >= 0 && var1 < field_707.length) {
         field_707[var1].method_688(var0);
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String[]
   public static final String[] method_499(String var0, int var1) {
      if (var0 == null) {
         return null;
      } else {
         int var2 = 0;
         int var3 = 0;
         String var4 = null;
         var0 = var0 + "\n";

         while (var3 < var0.length()) {
            var4 = method_500(var0.substring(var3, var0.length()), var1, false);
            var2++;
            var3 += var4.length();
         }

         String[] var5 = new String[var2];
         var3 = 0;

         for (int var6 = 0; var6 < var2; var6++) {
            var5[var6] = method_500(var0.substring(var3, var0.length()), var1, false);
            var3 += var5[var6].length();
            var5[var6].trim();
         }

         return var5;
      }
   }

   // $VF: renamed from: a (java.lang.String, int, boolean) java.lang.String
   public static final String method_500(String var0, int var1, boolean var2) {
      if (var0 == null) {
         return null;
      } else {
         int var3 = 0;
         boolean var4 = false;
         int var5 = method_495() >> 1;
         boolean var6 = false;
         boolean var7 = false;

         for (int var8 = 0; var8 < var0.length(); var8++) {
            if (var2 || var0.charAt(var8) == ' ') {
               var3 = var8;
            }

            if ((var5 += method_491(var0, var8, var8 + 1)) >= var1) {
               if (0 < var3) {
                  return var0.substring(0, var3 + 1);
               }

               return var0.substring(0, var8 + 1);
            }

            if (var0.charAt(var8) == '\n' || var0.charAt(var8) == '\r') {
               return var0.substring(0, var8 + 1);
            }
         }

         return 0 < var0.length() - 1 ? var0.substring(0, var0.length()) : "";
      }
   }
}
