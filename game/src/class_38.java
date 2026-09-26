// $VF: renamed from: cl
public final class class_38 {
   // $VF: renamed from: a x
   private static class_3 field_384 = new class_3();
   // $VF: renamed from: b x
   private static class_3 field_385 = new class_3();
   // $VF: renamed from: a boolean[]
   private static boolean[] field_386 = new boolean[200];

   // $VF: renamed from: a (int) ao
   public static final class_86 method_354(int var0) {
      return class_49.method_400(var0);
   }

   // $VF: renamed from: a (boolean[]) void
   public static final void method_355(boolean[] var0) {
      field_386 = var0;
   }

   // $VF: renamed from: a () boolean[]
   public static final boolean[] method_356() {
      return field_386;
   }

   // $VF: renamed from: a (int) void
   public static final void method_357(int var0) {
      field_386[var0] = true;
   }

   // $VF: renamed from: a (int) int
   public static final int method_358(int var0) {
      return 15000 + (int)(var0 / 100.0F * 15000.0F);
   }

   // $VF: renamed from: b (int) int
   public static final int method_359(int var0) {
      return class_16.method_98(100, class_16.method_97(0, (int)((var0 - 15000) / 15000.0F * 100.0F)));
   }

   // $VF: renamed from: a (int, int, int, int) int
   public static final int method_360(int var0, int var1, int var2, int var3) {
      return 100 - (class_16.method_96((var2 - var0) * (var2 - var0) + (var3 - var1) * (var3 - var1) << 12) >> 12);
   }

   // $VF: renamed from: b (int, int, int, int) int
   public static final int method_361(int var0, int var1, int var2, int var3) {
      return class_16.method_96((var2 - var0) * (var2 - var0) + (var3 - var1) * (var3 - var1) << 12) >> 12;
   }

   // $VF: renamed from: a (ao, ao) float
   public static final float method_362(class_86 var0, class_86 var1) {
      if (var0.method_753(var1)) {
         return 0.0F;
      } else {
         field_384.method_10(var0.field_1135, var0.field_1136, var0.field_1137 / 10);
         field_385.method_10(var1.field_1135, var1.field_1136, var1.field_1137 / 10);
         field_384.method_17(field_385);
         return (
               class_16.method_96(
                     field_384.field_37 * field_384.field_37 + field_384.field_38 * field_384.field_38 + field_384.field_39 * field_384.field_39 << 12
                  )
                  >> 12
            )
            * 18.85F;
      }
   }

   // $VF: renamed from: a (ao) byte[]
   public static final byte[] method_363(class_86 var0) {
      byte[] var1 = class_49.method_404();
      class_120[] var2 = class_90.method_785();
      byte[] var3 = new byte[class_90.method_787().length];
      byte[] var4 = new byte[class_90.method_787().length];

      for (int var5 = 0; var5 < var3.length; var5++) {
         var4[var5] = (byte)var5;
         var3[var5] = (byte)method_360(var0.field_1135, var0.field_1136, var1[var2[var5].field_1482 * 4 + 1], var1[var2[var5].field_1482 * 4 + 2]);
         if (var3[var5] < 50) {
            var3[var5] = 0;
         }
      }

      boolean var9;
      do {
         var9 = true;

         for (int var6 = 1; var6 < var3.length; var6++) {
            if (var3[var6 - 1] < var3[var6]) {
               int var7 = var3[var6 - 1];
               int var8 = var4[var6 - 1];
               var3[var6 - 1] = var3[var6];
               var4[var6 - 1] = var4[var6];
               var3[var6] = (byte)var7;
               var4[var6] = (byte)var8;
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

      for (int var12 = 0; var12 < var11.length; var12 += 2) {
         var11[var12] = var4[var12 / 2];
         var11[var12 + 1] = var3[var12 / 2];
      }

      return var11;
   }
}
