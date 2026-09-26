import java.util.Random;

// $VF: renamed from: db
public final class class_24 {
   // $VF: renamed from: a ax
   public class_108 field_250;
   // $VF: renamed from: a int[]
   private int[] field_251;
   // $VF: renamed from: a int
   private int field_252;
   // $VF: renamed from: b int
   private int field_253;
   // $VF: renamed from: c int
   private int field_254;

   public class_24(int var1, class_44 var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, int var10, byte var11) {
      this.field_253 = var8;
      this.field_252 = var9;
      this.field_254 = var10;
      this.field_251 = new int[var1];
      this.field_250 = class_108.method_890(0, var3, var4, var5, var6, var7, var8, var1, var11);
      this.field_250.method_893(var2);
      class_110 var12;
      int[] var13 = (var12 = (class_110)this.field_250).field_1389;
      int[] var14 = var12.method_897();
      Random var15 = new Random();

      for (int var16 = 0; var16 < var1; var16++) {
         var13[3 * var16] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var13[3 * var16 + 1] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var13[3 * var16 + 2] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var14[var16] = 0;
         this.field_251[var16] = var15.nextInt(var10) - (var10 >> 1) + this.field_252;
      }
   }

   // $VF: renamed from: a () void
   public final void method_232() {
      if (this.field_250 != null) {
         this.field_250.method_894();
      }

      this.field_250 = null;
   }

   // $VF: renamed from: b () void
   public final void method_233() {
      class_110 var1;
      int[] var2 = (var1 = (class_110)this.field_250).field_1389;
      int[] var3 = var1.method_897();
      int[] var4 = var1.field_1390;
      Random var5 = new Random();

      for (int var6 = 0; var6 < var3.length; var6++) {
         var2[3 * var6] = var5.nextInt(this.field_253 >> 1) - (this.field_253 >> 2);
         var2[3 * var6 + 1] = var5.nextInt(this.field_253 >> 1) - (this.field_253 >> 2);
         var2[3 * var6 + 2] = var5.nextInt(this.field_253 >> 1) - (this.field_253 >> 2);
         var3[var6] = 0;
         var4[var6] = -1;
         this.field_251[var6] = var5.nextInt(this.field_254) - (this.field_254 >> 1) + this.field_252;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_234(int var1) {
      int[] var2 = ((class_110)this.field_250).method_897();
      int[] var3 = ((class_110)this.field_250).field_1390;
      int var4 = var1 * this.field_253 / this.field_252;

      for (int var5 = 0; var5 < var2.length; var5++) {
         if (this.field_251[var5] > 0 && this.field_251[var5] < this.field_252) {
            var2[var5] += var4;
         } else if (this.field_251[var5] > -1024) {
            int var6;
            var6 = (var6 = (var3[var5] >> 24 & 0xFF) - (var1 >> 2)) < 0 ? 0 : var6;
            var3[var5] = var6 << 24 | 16777215;
         } else {
            var2[var5] = 0;
         }

         this.field_251[var5] = this.field_251[var5] - var1;
      }
   }
}
