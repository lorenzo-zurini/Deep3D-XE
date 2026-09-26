// $VF: renamed from: am
public abstract class class_111 extends class_100 {
   // $VF: renamed from: c int
   public int field_1369;
   // $VF: renamed from: e int
   public int field_1370;
   // $VF: renamed from: f int
   public int field_1371;
   // $VF: renamed from: a v[]
   public class_5[] field_1372;
   // $VF: renamed from: b v[]
   public class_5[] field_1373;
   // $VF: renamed from: a int[]
   public int[] field_1374;
   // $VF: renamed from: b v
   public static class_5 field_1375 = new class_5();
   // $VF: renamed from: c v
   public static class_5 field_1376 = new class_5();
   // $VF: renamed from: d v
   public static class_5 field_1377 = new class_5();
   // $VF: renamed from: g int
   public int field_1378;
   // $VF: renamed from: h int
   public int field_1379;
   // $VF: renamed from: i int
   public int field_1380;
   // $VF: renamed from: j int
   public int field_1381;

   public class_111(int var1, int var2, int var3, int var4, int var5) {
      this.field_1372 = new class_5[6];
      this.field_1373 = new class_5[6];

      for (int var6 = this.field_1373.length - 1; var6 >= 0; var6--) {
         this.field_1373[var6] = new class_5();
      }

      this.field_1374 = new int[6];
      this.field_1372[0] = new class_5(0, 0, -4096);
      this.field_1372[1] = new class_5(0, 0, 4096);
      this.field_1372[2] = new class_5();
      this.field_1372[3] = new class_5();
      this.field_1372[4] = new class_5();
      this.field_1372[5] = new class_5();
      this.field_1378 = var1;
      this.field_1379 = var2;
      this.method_895(var3, var4, var5);
   }

   public class_111(class_111 var1) {
      super(var1);
      this.field_1369 = var1.field_1369;
      this.field_1370 = var1.field_1370;
      this.field_1371 = var1.field_1371;
      System.arraycopy(var1.field_1373, 0, this.field_1373, 0, var1.field_1373.length);
      System.arraycopy(var1.field_1372, 0, this.field_1372, 0, var1.field_1372.length);
      System.arraycopy(var1.field_1374, 0, this.field_1374, 0, var1.field_1374.length);
      this.field_1380 = var1.field_1380;
      this.field_1381 = var1.field_1381;
      this.field_1378 = var1.field_1378;
      this.field_1379 = var1.field_1379;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_835(boolean var1) {
      if (super.field_1281 || var1) {
         if (super.field_1278 != null) {
            super.field_1284 = super.field_1278.field_1284.method_6(super.field_1283, super.field_1284);
         } else {
            super.field_1284.method_3(super.field_1283);
         }

         this.field_1373 = super.field_1284.method_42(this.field_1372, this.field_1373);
         field_1375 = super.field_1284.method_12(field_1375);
         field_1376 = super.field_1284.method_14(field_1376);
         field_1377.method_169(field_1376);
         field_1376.method_178(-this.field_1370);
         field_1377.method_178(-this.field_1371);
         field_1376.method_175(field_1375);
         field_1377.method_175(field_1375);
         this.field_1374[0] = field_1376.method_171(this.field_1373[0]);
         this.field_1374[1] = field_1377.method_171(this.field_1373[1]);
         this.field_1374[2] = field_1375.method_171(this.field_1373[2]);
         this.field_1374[3] = field_1375.method_171(this.field_1373[3]);
         this.field_1374[4] = field_1375.method_171(this.field_1373[4]);
         this.field_1374[5] = field_1375.method_171(this.field_1373[5]);
         super.field_1281 = false;
         super.field_1282 = false;
      }
   }

   // $VF: renamed from: g (int, int, int) void
   public void method_895(int var1, int var2, int var3) {
      this.field_1369 = var1;
      this.field_1370 = var2;
      this.field_1371 = var3;
      int var4 = class_124.method_936(var1 >> 1);
      int var5 = class_124.method_937(var1 >> 1);
      this.field_1372[2].method_170(var5, 0, -var4);
      this.field_1372[3].method_170(-var5, 0, -var4);
      this.field_1372[4].method_170(0, -var5, -var4);
      this.field_1372[5].method_170(0, var5, -var4);
      this.field_1380 = (var4 << 12) / var5;
      this.field_1381 = this.field_1380 * ((this.field_1378 << 12) / this.field_1379) >> 12;
   }

   // $VF: renamed from: g (int) void
   public final void method_896(int var1) {
      this.method_895(var1, this.field_1370, this.field_1371);
   }

   // $VF: renamed from: a (v) boolean
   public final boolean method_897(class_5 var1) {
      if ((var1 = super.field_1284.method_43(var1)).field_140 > this.field_1370) {
         return false;
      } else {
         int var2 = this.field_1381 * var1.field_140 >> 12;
         int var3 = this.field_1380 * var1.field_140 >> 12;
         if (var2 != 0 && var3 != 0) {
            var1.field_138 = -((var1.field_138 << 11) / var2 * this.field_1378 >> 12) + (this.field_1378 >> 1);
            var1.field_139 = ((var1.field_139 << 11) / var3 * this.field_1379 >> 12) + (this.field_1379 >> 1);
            return var1.field_138 >= 0 && var1.field_139 >= 0 && var1.field_138 < this.field_1378 && var1.field_139 < this.field_1379;
         } else {
            return false;
         }
      }
   }

   // $VF: renamed from: a (du) byte
   public final byte method_898(class_29 var1) {
      for (int var3 = 5; var3 >= 0; var3--) {
         int var2;
         if ((var2 = var1.field_398.method_171(this.field_1373[var3]) - this.field_1374[var3]) < -var1.field_399) {
            return 0;
         }

         if (class_124.method_945(var2) < var1.field_399) {
            return 1;
         }
      }

      return 2;
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
   }

   // $VF: renamed from: b (am, t) void
   public final void method_834(class_111 var1, class_17 var2) {
   }

   // $VF: renamed from: a (int, int, int, int, int) am
   public static final class_111 method_899(int var0, int var1, int var2, int var3, int var4) {
      return new class_112(var0, var1, var2, var3, var4);
   }
}
