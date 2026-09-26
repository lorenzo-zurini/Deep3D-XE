// $VF: renamed from: dr
public final class class_13 {
   // $VF: renamed from: a bj[]
   private class_87[] field_182;
   // $VF: renamed from: a boolean
   public boolean field_183;
   // $VF: renamed from: a int
   public int field_184 = 0;

   public class_13(int[] var1) {
      this.field_183 = false;
      this.field_182 = new class_87[var1.length / 3];

      for (byte var2 = 0; var2 < var1.length; var2 += 3) {
         this.field_182[var2 / 3] = new class_87(var1[var2], var1[var2 + 1], var1[var2 + 2], this);
      }
   }

   // $VF: renamed from: a () void
   public final void method_217() {
      this.field_182 = null;
   }

   // $VF: renamed from: a (int) bj
   public final class_87 method_218(int var1) {
      return var1 < this.field_182.length ? this.field_182[var1] : null;
   }

   // $VF: renamed from: a () bj
   public final class_87 method_219() {
      return this.field_184 < this.field_182.length ? this.field_182[this.field_184] : null;
   }

   // $VF: renamed from: b () bj
   public final class_87 method_220() {
      return this.field_182[this.field_182.length - 1];
   }

   // $VF: renamed from: a (int) void
   public final void method_221(int var1) {
      if (this.field_184 < this.field_182.length - 1) {
         this.field_184 = var1 + 1;
      }

      this.field_182[var1].method_742(false);
      this.field_182[var1].method_764();
   }

   // $VF: renamed from: a () int
   public final int method_222() {
      return this.field_182.length;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_223(int var1, int var2, int var3) {
      if (this.field_184 < this.field_182.length
         && var1 - this.field_182[this.field_184].field_1161 < 2000
         && var1 - this.field_182[this.field_184].field_1161 > -2000
         && var2 - this.field_182[this.field_184].field_1162 < 2000
         && var2 - this.field_182[this.field_184].field_1162 > -2000
         && var3 - this.field_182[this.field_184].field_1163 < 2000
         && var3 - this.field_182[this.field_184].field_1163 > -2000) {
         this.field_182[this.field_184].method_742(false);
         this.field_182[this.field_184].method_764();
         this.field_184++;
         if (this.field_183 && this.field_184 > this.field_182.length - 1) {
            this.field_184 = 0;

            for (int var4 = 0; var4 < this.field_182.length; var4++) {
               this.field_182[var4].method_765();
            }
         }

         if (this.field_184 < this.field_182.length) {
            this.field_182[this.field_184].method_742(true);
         }
      }
   }

   // $VF: renamed from: a () dr
   public final class_13 method_224() {
      int[] var1 = new int[this.field_182.length * 3];

      for (int var2 = 0; var2 < this.field_182.length; var2++) {
         var1[3 * var2] = this.field_182[var2].field_1161;
         var1[3 * var2 + 1] = this.field_182[var2].field_1162;
         var1[3 * var2 + 2] = this.field_182[var2].field_1163;
      }

      class_13 var3;
      (var3 = new class_13(var1)).field_183 = this.field_183;
      return var3;
   }
}
