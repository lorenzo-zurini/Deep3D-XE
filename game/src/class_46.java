// $VF: renamed from: aa
public final class class_46 {
   // $VF: renamed from: a int
   public int field_626;
   // $VF: renamed from: b int
   public int field_627;
   // $VF: renamed from: c int
   public int field_628;
   // $VF: renamed from: d int
   public int field_629;
   // $VF: renamed from: e int
   public int field_630;
   // $VF: renamed from: f int
   public int field_631;
   // $VF: renamed from: g int
   public int field_632;
   // $VF: renamed from: h int
   public int field_633;
   // $VF: renamed from: a byte[]
   public byte[] field_634;
   // $VF: renamed from: b byte[]
   public byte[] field_635;
   // $VF: renamed from: i int
   public int field_636;
   // $VF: renamed from: j int
   public int field_637;
   // $VF: renamed from: k int
   public int field_638;

   public class_46(int var1, int var2, int var3, int var4, int var5, int var6, int var7, byte[] var8, byte[] var9) {
      this.field_626 = var1;
      this.field_627 = var2;
      this.field_628 = var3;
      this.field_629 = var4;
      this.field_631 = var5;
      this.field_632 = var6;
      this.field_633 = var7;
      this.field_634 = var8;
      this.field_635 = var9;
      this.field_630 = var6 + (var7 - var6) / 2;
      this.field_638 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_442() {
      return this.field_630 * this.field_636;
   }

   // $VF: renamed from: a () float
   public final float method_443() {
      return (float)(this.field_630 - this.field_632) / (this.field_633 - this.field_632);
   }

   // $VF: renamed from: a (int) void
   public final void method_444(int var1) {
      this.field_636 += var1;
   }

   // $VF: renamed from: b (int) void
   public final void method_445(int var1) {
      this.field_637 += var1;
   }

   // $VF: renamed from: a (boolean, int) int
   public final int method_446(boolean var1, int var2) {
      if (var1 && this.field_637 > 0 && class_3.method_112() >= this.field_630 && var2 < class_3.method_108().method_367()) {
         this.method_445(-1);
         this.method_444(1);
         return -this.field_630;
      } else if (!var1 && this.field_636 > 0) {
         this.method_444(-1);
         this.method_445(1);
         return this.field_630;
      } else {
         return 0;
      }
   }

   // $VF: renamed from: a (int) aa
   public final class_46 method_447(int var1) {
      return this.method_448(var1, this.field_630);
   }

   // $VF: renamed from: a (int, int) aa
   public final class_46 method_448(int var1, int var2) {
      class_46 var3;
      (var3 = this.method_455()).field_630 = var2;
      var3.field_636 = var1;
      return var3;
   }

   // $VF: renamed from: a (int, int, aa[]) boolean
   public static final boolean method_449(int var0, int var1, class_46[] var2) {
      if (var2 == null) {
         return false;
      } else {
         for (int var3 = 0; var3 < var2.length; var3++) {
            if (var2[var3].field_626 == var0 && var2[var3].field_636 >= var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (int, aa[]) boolean
   public static final boolean method_450(int var0, class_46[] var1) {
      return method_449(var0, 1, var1);
   }

   // $VF: renamed from: a (aa, aa[], int) aa[]
   public static final class_46[] method_451(class_46 var0, class_46[] var1, int var2) {
      byte[] var3 = var0.field_634;
      byte[] var4 = var0.field_635;

      for (int var5 = 0; var5 < var3.length; var5++) {
         for (int var6 = 0; var6 < var1.length; var6++) {
            if (var1[var6].field_626 == var3[var5]) {
               var1[var6].method_444(-var4[var5] * var2);
               break;
            }
         }
      }

      return method_454(var1, new class_46[]{var0.method_447(var2)});
   }

   // $VF: renamed from: a (aa[], boolean) aa[]
   public static final class_46[] method_452(class_46[] var0, boolean var1) {
      if (var0 == null) {
         return null;
      } else {
         class_46[] var2 = new class_46[var0.length];
         class_46[] var3 = new class_46[var0.length];
         System.arraycopy(var0, 0, var3, 0, var0.length);
         int var4 = 0;

         for (int var5 = 0; var5 < var3.length; var5++) {
            if (var1 && var3[var5].field_636 > 0) {
               var2[var4] = var3[var5].method_447(var3[var5].field_636);
               var4++;
            } else if (!var1 && var3[var5].field_637 > 0) {
               var2[var4] = var3[var5].method_447(var3[var5].field_637);
               var4++;
            }
         }

         class_46[] var6 = new class_46[var4];
         System.arraycopy(var2, 0, var6, 0, var4);
         return var6;
      }
   }

   // $VF: renamed from: a (aa[], aa[]) aa[]
   public static final class_46[] method_453(class_46[] var0, class_46[] var1) {
      int var2 = var0 == null ? 0 : var0.length;
      int var3 = var1 == null ? 0 : var1.length;
      class_46[] var4 = new class_46[var2 + var3];
      if (var2 > 0 && var3 == 0) {
         for (int var10 = 0; var10 < var0.length; var10++) {
            var4[var10] = var0[var10].method_447(var0[var10].field_636);
         }

         return var4;
      } else if (var3 > 0 && var2 == 0) {
         for (int var9 = 0; var9 < var1.length; var9++) {
            var4[var9] = var1[var9].method_447(0);
            var4[var9].field_637 = var1[var9].field_636;
         }

         return var4;
      } else if (var3 == 0 && var2 == 0) {
         return null;
      } else {
         for (int var5 = 0; var5 < var0.length; var5++) {
            var4[var5] = var0[var5].method_447(var0[var5].field_636);
         }

         int var8 = var2;

         for (int var6 = 0; var6 < var1.length; var6++) {
            for (int var7 = 0; var7 < var4.length; var7++) {
               if (var4[var7] == null) {
                  var4[var7] = var1[var6].method_447(0);
                  var4[var7].field_637 = var1[var6].field_636;
                  var8++;
                  break;
               }

               if (var1[var6].method_456(var4[var7])) {
                  var4[var7] = var1[var6].method_447(var4[var7].field_636);
                  var4[var7].field_637 = var1[var6].field_636;
                  break;
               }
            }
         }

         class_46[] var11 = new class_46[var8];
         System.arraycopy(var4, 0, var11, 0, var8);
         return var11;
      }
   }

   // $VF: renamed from: b (aa[], aa[]) aa[]
   public static final class_46[] method_454(class_46[] var0, class_46[] var1) {
      if (var0 == null) {
         return var1;
      } else if (var1 == null) {
         return var0;
      } else {
         class_46[] var2 = new class_46[var1.length];

         for (int var3 = 0; var3 < var1.length; var3++) {
            var2[var3] = var1[var3];
         }

         Object var8 = null;
         int var4 = var2.length;

         for (int var5 = 0; var5 < var0.length; var5++) {
            for (int var6 = 0; var6 < var2.length; var6++) {
               if (var2[var6] != null && var0[var5].field_626 == var2[var6].field_626) {
                  var0[var5].method_444(var2[var6].field_636);
                  var4--;
                  var2[var6] = null;
               }
            }
         }

         if (var4 <= 0) {
            return var0;
         } else {
            var8 = new class_46[var4];
            int var10 = 0;

            for (int var11 = 0; var11 < var2.length; var11++) {
               if (var2[var11] != null) {
                  ((Object[])var8)[var10++] = var2[var11];
               }
            }

            class_46[] var12 = new class_46[var0.length + ((Object[])var8).length];

            for (int var7 = 0; var7 < var0.length; var7++) {
               var12[var7] = var0[var7];
            }

            for (int var13 = 0; var13 < ((Object[])var8).length; var13++) {
               var12[var13 + var0.length] = (class_46)((Object[])var8)[var13];
            }

            return var12;
         }
      }
   }

   // $VF: renamed from: a () aa
   public final class_46 method_455() {
      return new class_46(
         this.field_626, this.field_627, this.field_628, this.field_629, this.field_631, this.field_632, this.field_633, this.field_634, this.field_635
      );
   }

   // $VF: renamed from: a (aa) boolean
   public final boolean method_456(class_46 var1) {
      return var1 == null ? false : this.field_626 == var1.field_626;
   }

   public final String toString() {
      return this.field_626 + " " + this.field_628 + " " + this.field_631 + " " + this.field_632 + " " + this.field_633;
   }
}
