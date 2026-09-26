import java.util.Random;

// $VF: renamed from: da
public final class class_35 {
   // $VF: renamed from: a ay
   public class_101 field_460;
   // $VF: renamed from: a int[]
   private int[] field_461;
   // $VF: renamed from: a int
   private int field_462;
   // $VF: renamed from: b int
   private int field_463;
   // $VF: renamed from: c int
   private int field_464;

   public class_35(int var1, class_120 var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, int var10, byte var11) {
      this.field_463 = var8;
      this.field_462 = var9;
      this.field_464 = var10;
      this.field_461 = new int[var1];
      this.field_460 = class_101.method_880(0, var3, var4, var5, var6, var7, var8, var1, var11);
      this.field_460.method_883(var2);
      class_104 var12;
      int[] var13 = (var12 = (class_104)this.field_460).field_1309;
      int[] var14 = var12.method_889();
      Random var15 = new Random();

      for (int var16 = 0; var16 < var1; var16++) {
         var13[3 * var16] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var13[3 * var16 + 1] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var13[3 * var16 + 2] = var15.nextInt(var8 >> 1) - (var8 >> 2);
         var14[var16] = 0;
         this.field_461[var16] = var15.nextInt(var10) - (var10 >> 1) + this.field_462;
      }
   }

   // $VF: renamed from: a () void
   public final void method_398() {
      if (this.field_460 != null) {
         this.field_460.method_884();
      }

      this.field_460 = null;
   }

   // $VF: renamed from: b () void
   public final void method_399() {
      class_104 var1;
      int[] var2 = (var1 = (class_104)this.field_460).field_1309;
      int[] var3 = var1.method_889();
      Random var4 = new Random();

      for (int var5 = 0; var5 < var3.length; var5++) {
         var2[3 * var5] = var4.nextInt(this.field_463 >> 1) - (this.field_463 >> 2);
         var2[3 * var5 + 1] = var4.nextInt(this.field_463 >> 1) - (this.field_463 >> 2);
         var2[3 * var5 + 2] = var4.nextInt(this.field_463 >> 1) - (this.field_463 >> 2);
         var3[var5] = 0;
         this.field_461[var5] = var4.nextInt(this.field_464) - (this.field_464 >> 1) + this.field_462;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_400(int var1) {
      int[] var2 = ((class_104)this.field_460).method_889();
      int var3 = var1 * this.field_463 / this.field_462;

      for (int var4 = 0; var4 < var2.length; var4++) {
         if (this.field_461[var4] > 0 && this.field_461[var4] < this.field_462) {
            var2[var4] += var3;
         } else {
            var2[var4] = 0;
         }

         this.field_461[var4] = this.field_461[var4] - var1;
      }
   }
}
