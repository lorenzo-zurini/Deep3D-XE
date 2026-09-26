// $VF: renamed from: dr
public final class class_18 {
   // $VF: renamed from: a bi[]
   private class_97[] field_162;
   // $VF: renamed from: a boolean
   public boolean field_163;
   // $VF: renamed from: a int
   public int field_164 = 0;

   public class_18(int[] var1) {
      this.field_163 = false;
      this.field_162 = new class_97[var1.length / 3];

      for (int var2 = 0; var2 < var1.length; var2 += 3) {
         this.field_162[var2 / 3] = new class_97(var1[var2], var1[var2 + 1], var1[var2 + 2], this);
      }
   }

   // $VF: renamed from: a () void
   public final void method_108() {
      this.field_162 = null;
   }

   // $VF: renamed from: a (int) bi
   public final class_97 method_109(int var1) {
      return var1 < this.field_162.length ? this.field_162[var1] : null;
   }

   // $VF: renamed from: a () bi
   public final class_97 method_110() {
      return this.field_164 < this.field_162.length ? this.field_162[this.field_164] : null;
   }

   // $VF: renamed from: b () bi
   public final class_97 method_111() {
      return this.field_162[this.field_162.length - 1];
   }

   // $VF: renamed from: a (int) void
   public final void method_112(int var1) {
      if (this.field_164 < this.field_162.length - 1) {
         this.field_164 = var1 + 1;
      }

      this.field_162[var1].method_795(false);
      this.field_162[var1].method_819();
   }

   // $VF: renamed from: a () int
   public final int method_113() {
      return this.field_162.length;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_114(int var1, int var2, int var3) {
      if (this.field_164 < this.field_162.length
         && var1 - this.field_162[this.field_164].field_1295 < 2000
         && var1 - this.field_162[this.field_164].field_1295 > -2000
         && var2 - this.field_162[this.field_164].field_1296 < 2000
         && var2 - this.field_162[this.field_164].field_1296 > -2000
         && var3 - this.field_162[this.field_164].field_1297 < 2000
         && var3 - this.field_162[this.field_164].field_1297 > -2000) {
         this.field_162[this.field_164].method_795(false);
         this.field_162[this.field_164].method_819();
         this.field_164++;
         if (this.field_163 && this.field_164 > this.field_162.length - 1) {
            this.field_164 = 0;

            for (int var4 = 0; var4 < this.field_162.length; var4++) {
               this.field_162[var4].method_820();
            }
         }

         if (this.field_164 < this.field_162.length) {
            this.field_162[this.field_164].method_795(true);
         }
      }
   }

   // $VF: renamed from: a () dr
   public final class_18 method_115() {
      int[] var1 = new int[this.field_162.length * 3];

      for (int var2 = 0; var2 < this.field_162.length; var2++) {
         var1[3 * var2] = this.field_162[var2].field_1295;
         var1[3 * var2 + 1] = this.field_162[var2].field_1296;
         var1[3 * var2 + 2] = this.field_162[var2].field_1297;
      }

      class_18 var3;
      (var3 = new class_18(var1)).field_163 = this.field_163;
      return var3;
   }
}
