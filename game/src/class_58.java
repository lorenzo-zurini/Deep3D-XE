import javax.microedition.lcdui.Graphics;

// $VF: renamed from: bm
public final class class_58 {
   // $VF: renamed from: a az[]
   private static class_73[] field_706;
   // $VF: renamed from: a javax.microedition.lcdui.Graphics
   private static Graphics field_707;
   // $VF: renamed from: a int
   private static int field_708;

   // $VF: renamed from: a () void
   public static final void method_513() {
      field_706 = null;
      // System.gc() removed: full GCs stall the desktop JVM
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Graphics) void
   public static final void method_514(Graphics var0) {
      field_707 = var0;
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_515(String var0) {
      if (field_707 != null) {
         if (field_706 == null) {
            field_706 = new class_73[1];
            field_706[0] = new class_73(var0, field_707);
            return;
         }

         class_73[] var1 = new class_73[field_706.length + 1];
         System.arraycopy(field_706, 0, var1, 0, field_706.length);
         var1[field_706.length] = new class_73(var0, field_707);
         field_706 = var1;
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int) void
   public static final void method_516(String var0, int var1, int var2, int var3, int var4) {
      if (var3 >= 0 && var3 < field_706.length) {
         field_708 = var3;
         if ((var4 & 8) != 0) {
            var1 -= field_706[field_708].method_690(var0) >> 1;
         }

         if ((var4 & 4) != 0) {
            var2 -= field_706[field_708].field_1022 >> 1;
         } else if ((var4 & 32) != 0) {
            var2 -= field_706[field_708].field_1022;
         }

         if ((var4 & 2) != 0) {
            field_706[field_708].method_694(var0, var1, var2);
         } else {
            field_706[field_708].method_693(var0, var1, var2);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int) void
   public static final void method_517(String var0, int var1, int var2) {
      field_706[field_708].method_693(var0, var1, var2);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int) void
   public static final void method_518(String var0, int var1, int var2, int var3) {
      if (var3 >= 0 && var3 < field_706.length) {
         field_708 = var3;
         field_706[field_708].method_693(var0, var1, var2);
      }
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int, int) void
   public static final void method_519(String[] var0, int var1, int var2, int var3, int var4) {
      method_520(var0, var1, var2, var3, var4, 0, var0.length - 1);
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int, int, int, int) void
   public static final void method_520(String[] var0, int var1, int var2, int var3, int var4, int var5, int var6) {
      var6 = var6 <= var0.length - 1 ? var6 : var0.length - 1;
      var5 = var5 <= var6 ? var5 : var6;
      if (var3 >= 0 && var3 < field_706.length) {
         field_708 = var3;
         switch (var4) {
            case 1:
               int var12 = var5;

               for (int var14 = 0; var12 < var6 + 1; var14++) {
                  field_706[field_708].method_693(var0[var12], var1, var2 + var14 * method_527());
                  var12++;
               }

               return;
            case 2:
               int var11 = var5;

               for (int var13 = 0; var11 < var6 + 1; var13++) {
                  field_706[field_708].method_695(var0[var11], var1, var2 + var13 * method_527());
                  var11++;
               }

               return;
            case 3:
               int var7 = var5;

               for (int var8 = 0; var7 < var6 + 1; var8++) {
                  field_706[field_708].method_693(var0[var7], var1 - (method_523(var0[var7]) >> 1), var2 + var8 * method_527());
                  var7++;
               }
         }
      }
   }

   // $VF: renamed from: a (java.lang.String[], int, int, int) void
   public static final void method_521(String[] var0, int var1, int var2, int var3) {
      if (var3 >= 0 && var3 < field_706.length) {
         field_708 = var3;

         for (int var4 = 0; var4 < var0.length; var4++) {
            field_706[field_708].method_693(var0[var4], var1, var2 + var4 * method_527());
         }
      }
   }

   // $VF: renamed from: a (int, int, int, int, int) void
   public static final void method_522(int var0, int var1, int var2, int var3, int var4) {
      if (var4 >= 0 && var4 < field_706.length) {
         field_706[var4].method_687(var0, var1, var2, var3);
      }
   }

   // $VF: renamed from: a (java.lang.String) int
   public static final int method_523(String var0) {
      return field_706[field_708].method_690(var0);
   }

   // $VF: renamed from: a (java.lang.String, int, int) int
   public static final int method_524(String var0, int var1, int var2) {
      return field_706[field_708].method_691(var0, var1, var2);
   }

   // $VF: renamed from: a (int) void
   public static final void method_525(int var0) {
      field_706[field_708].method_688(var0);
   }

   // $VF: renamed from: a (int, int) void
   public static final void method_526(int var0, int var1) {
      if (var1 >= 0 && var1 < field_706.length) {
         field_706[var1].method_688(var0);
      }
   }

   // $VF: renamed from: a () int
   public static final int method_527() {
      return field_706[field_708].field_1022;
   }

   // $VF: renamed from: b () int
   public static final int method_528() {
      return field_706[field_708].field_1023;
   }

   // $VF: renamed from: b (int) void
   public static final void method_529(int var0) {
      field_706[field_708].method_696(var0);
   }

   // $VF: renamed from: a (java.lang.String[]) int
   public static final int method_530(String[] var0) {
      return field_706[field_708].field_1022 * var0.length;
   }

   // $VF: renamed from: b (int, int) void
   public static final void method_531(int var0, int var1) {
      if (var1 >= 0 && var1 < field_706.length) {
         field_706[var1].method_696(var0);
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String[]
   public static final String[] method_532(String var0, int var1) {
      if (var0 == null) {
         return null;
      } else {
         int var2 = 0;
         int var3 = 0;
         String var4 = null;
         var0 = var0 + "\n";

         while (var3 < var0.length()) {
            var4 = method_533(var0.substring(var3, var0.length()), var1, false);
            var2++;
            var3 += var4.length();
         }

         String[] var5 = new String[var2];
         var3 = 0;

         for (int var6 = 0; var6 < var2; var6++) {
            var5[var6] = method_533(var0.substring(var3, var0.length()), var1, false);
            var3 += var5[var6].length();
            var5[var6].trim();
         }

         return var5;
      }
   }

   // $VF: renamed from: a (java.lang.String, int, boolean) java.lang.String
   public static final String method_533(String var0, int var1, boolean var2) {
      if (var0 == null) {
         return null;
      } else {
         int var3 = 0;
         boolean var4 = false;
         int var5 = method_528() >> 1;
         boolean var6 = false;
         boolean var7 = false;

         for (int var8 = 0; var8 < var0.length(); var8++) {
            if (var2 || var0.charAt(var8) == ' ') {
               var3 = var8;
            }

            if ((var5 += method_524(var0, var8, var8 + 1)) >= var1) {
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
