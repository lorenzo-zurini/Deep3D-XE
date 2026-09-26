// $VF: renamed from: cl
public final class class_44 {
   // $VF: renamed from: a v
   private static class_5 field_565 = new class_5();
   // $VF: renamed from: b v
   private static class_5 field_566 = new class_5();
   // $VF: renamed from: a boolean[]
   private static boolean[] field_567 = new boolean[200];

   // $VF: renamed from: a (int) an
   public static final class_60 method_431(int var0) {
      return class_48.method_463(var0);
   }

   // $VF: renamed from: a (boolean[]) void
   public static final void method_432(boolean[] var0) {
      field_567 = var0;
   }

   // $VF: renamed from: a () boolean[]
   public static final boolean[] method_433() {
      return field_567;
   }

   // $VF: renamed from: a (int) void
   public static final void method_434(int var0) {
      field_567[var0] = true;
   }

   // $VF: renamed from: a (int) int
   public static final int method_435(int var0) {
      return 15000 + (int)(var0 / 100.0F * 15000.0F);
   }

   // $VF: renamed from: b (int) int
   public static final int method_436(int var0) {
      return class_124.method_943(100, class_124.method_942(0, (int)((var0 - 15000) / 15000.0F * 100.0F)));
   }

   // $VF: renamed from: a (int, int, int, int) int
   public static final int method_437(int var0, int var1, int var2, int var3) {
      return 100 - (class_124.method_941((var2 - var0) * (var2 - var0) + (var3 - var1) * (var3 - var1) << 12) >> 12);
   }

   // $VF: renamed from: b (int, int, int, int) int
   public static final int method_438(int var0, int var1, int var2, int var3) {
      return class_124.method_941((var2 - var0) * (var2 - var0) + (var3 - var1) * (var3 - var1) << 12) >> 12;
   }

   // $VF: renamed from: a (an, an) float
   public static final float method_439(class_60 var0, class_60 var1) {
      if (var0.method_593(var1)) {
         return 0.0F;
      } else {
         field_565.method_170(var0.field_829, var0.field_830, var0.field_831 / 10);
         field_566.method_170(var1.field_829, var1.field_830, var1.field_831 / 10);
         field_565.method_177(field_566);
         return (
               class_124.method_941(
                     field_565.field_138 * field_565.field_138 + field_565.field_139 * field_565.field_139 + field_565.field_140 * field_565.field_140 << 12
                  )
                  >> 12
            )
            * 18.85F;
      }
   }

   // $VF: renamed from: a (an) byte[]
   public static final byte[] method_440(class_60 var0) {
      byte[] var1 = class_48.method_467();
      class_46[] var2 = class_24.method_315();
      byte[] var3 = new byte[class_24.method_317().length];
      byte[] var4 = new byte[class_24.method_317().length];

      for (byte var5 = 0; var5 < var3.length; var5++) {
         var4[var5] = var5;
         var3[var5] = (byte)method_437(var0.field_829, var0.field_830, var1[var2[var5].field_628 * 4 + 1], var1[var2[var5].field_628 * 4 + 2]);
         if (var3[var5] < 50) {
            var3[var5] = 0;
         }
      }

      boolean var9;
      do {
         var9 = true;

         for (int var6 = 1; var6 < var3.length; var6++) {
            if (var3[var6 - 1] < var3[var6]) {
               byte var7 = var3[var6 - 1];
               byte var8 = var4[var6 - 1];
               var3[var6 - 1] = var3[var6];
               var4[var6 - 1] = var4[var6];
               var3[var6] = var7;
               var4[var6] = var8;
               var9 = false;
            }
         }
      } while (!var9);

      for (int var10 = 0; var10 < var3.length; var10++) {
         if (var3[var10] > 0) {
            var3[var10] = (byte)(var3[var10] - 2 * var10);
         }
      }

      byte[] var11 = new byte[var3.length * 2];

      for (byte var12 = 0; var12 < var11.length; var12 += 2) {
         var11[var12] = var4[var12 / 2];
         var11[var12 + 1] = var3[var12 / 2];
      }

      return var11;
   }
}
