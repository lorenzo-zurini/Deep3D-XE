// $VF: renamed from: bh
public final class class_52 {
   // $VF: renamed from: a int[]
   private int[] field_722;
   // $VF: renamed from: b int[]
   private int[] field_723;
   // $VF: renamed from: c int[]
   private int[] field_724;
   // $VF: renamed from: a v
   private class_5 field_725 = new class_5();
   // $VF: renamed from: b v
   private class_5 field_726 = new class_5();
   // $VF: renamed from: a ay
   private class_101 field_727;

   public class_52() {
      this.field_724 = new int[15];
      this.field_722 = new int[45];
      this.field_723 = new int[15];
      this.field_727 = class_101.method_880(0, 128, 32, 0, 64, 32, 400, 15, (byte)2);
      this.field_727.method_883(class_25.method_327(2));
      this.field_727.field_1294 = 2;
      this.field_722 = ((class_104)this.field_727).field_1309;

      for (int var1 = 0; var1 < this.field_722.length; var1++) {
         this.field_722[var1] = 100000;
      }

      for (int var2 = 0; var2 < this.field_724.length; var2++) {
         this.field_724[var2] = 250 + class_41.field_540.nextInt(300);
      }
   }

   // $VF: renamed from: a () void
   public final void method_510() {
      this.field_727.method_884();
      this.field_727 = null;
      this.field_722 = null;
   }

   // $VF: renamed from: a (long, bn, boolean) void
   public final void method_511(long var1, class_1 var3, boolean var4) {
      boolean var5 = false;
      this.field_722 = ((class_104)this.field_727).field_1309;

      for (int var6 = 0; var6 < this.field_722.length; var6 += 3) {
         int var7 = var6 / 3;
         if (!var5 && this.field_723[var7] <= 0) {
            int var8 = class_41.field_540.nextInt(18000) - 9000;
            int var9 = -5000 - class_41.field_540.nextInt(10000);
            int var10 = var4 ? -(10000 + class_41.field_540.nextInt(9000) - 4500) : -(40000 + class_41.field_540.nextInt(18000) - 9000);
            this.field_726.method_170(var8, var9, var10);
            this.field_725 = var3.method_39(this.field_726, this.field_725);
            this.field_722[var6] = this.field_725.field_138;
            this.field_722[var6 + 1] = this.field_725.field_139;
            this.field_722[var6 + 2] = this.field_725.field_140;
            this.field_723[var7] = 2500;
            var5 = true;
         } else {
            this.field_723[var7] = (int)(this.field_723[var7] - var1);
            this.field_722[var6 + 1] = this.field_722[var6 + 1] + this.field_724[var7];
            if (!var4) {
               this.field_726 = var3.method_14(this.field_726);
               this.field_722[var6] = this.field_722[var6] + (this.field_726.field_138 >> 3);
               this.field_722[var6 + 1] = this.field_722[var6 + 1] + (this.field_726.field_139 >> 3);
               this.field_722[var6 + 2] = this.field_722[var6 + 2] + (this.field_726.field_140 >> 3);
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_512() {
      class_41.field_527.method_265(this.field_727);
   }
}
