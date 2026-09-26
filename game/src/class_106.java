// $VF: renamed from: an
public abstract class class_106 extends class_105 {
   // $VF: renamed from: c int
   public int field_1349;
   // $VF: renamed from: d int
   public int field_1350;
   // $VF: renamed from: e int
   public int field_1351;
   // $VF: renamed from: a x[]
   public class_3[] field_1352;
   // $VF: renamed from: b x[]
   public class_3[] field_1353;
   // $VF: renamed from: a int[]
   public int[] field_1354;
   // $VF: renamed from: b x
   public static class_3 field_1355 = new class_3();
   // $VF: renamed from: c x
   public static class_3 field_1356 = new class_3();
   // $VF: renamed from: d x
   public static class_3 field_1357 = new class_3();
   // $VF: renamed from: g int
   public int field_1358;
   // $VF: renamed from: h int
   public int field_1359;
   // $VF: renamed from: i int
   public int field_1360;
   // $VF: renamed from: j int
   public int field_1361;

   public class_106(int var1, int var2, int var3, int var4, int var5) {
      this.field_1352 = new class_3[6];
      this.field_1353 = new class_3[6];

      for (int var6 = this.field_1353.length - 1; var6 >= 0; var6--) {
         this.field_1353[var6] = new class_3();
      }

      this.field_1354 = new int[6];
      this.field_1352[0] = new class_3(0, 0, -4096);
      this.field_1352[1] = new class_3(0, 0, 4096);
      this.field_1352[2] = new class_3();
      this.field_1352[3] = new class_3();
      this.field_1352[4] = new class_3();
      this.field_1352[5] = new class_3();
      this.field_1358 = var1;
      this.field_1359 = var2;
      this.method_881(var3, var4, var5);
   }

   public class_106(class_106 var1) {
      super(var1);
      this.field_1349 = var1.field_1349;
      this.field_1350 = var1.field_1350;
      this.field_1351 = var1.field_1351;
      System.arraycopy(var1.field_1353, 0, this.field_1353, 0, var1.field_1353.length);
      System.arraycopy(var1.field_1352, 0, this.field_1352, 0, var1.field_1352.length);
      System.arraycopy(var1.field_1354, 0, this.field_1354, 0, var1.field_1354.length);
      this.field_1360 = var1.field_1360;
      this.field_1361 = var1.field_1361;
      this.field_1358 = var1.field_1358;
      this.field_1359 = var1.field_1359;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_839(boolean var1) {
      if (super.field_1339 || var1) {
         if (super.field_1336 != null) {
            super.field_1342 = super.field_1336.field_1342.method_473(super.field_1341, super.field_1342);
         } else {
            super.field_1342.method_470(super.field_1341);
         }

         this.field_1353 = super.field_1342.method_510(this.field_1352, this.field_1353);
         field_1355 = super.field_1342.method_479(field_1355);
         field_1356 = super.field_1342.method_481(field_1356);
         field_1357.method_9(field_1356);
         field_1356.method_18(-this.field_1350);
         field_1357.method_18(-this.field_1351);
         field_1356.method_15(field_1355);
         field_1357.method_15(field_1355);
         this.field_1354[0] = field_1356.method_11(this.field_1353[0]);
         this.field_1354[1] = field_1357.method_11(this.field_1353[1]);
         this.field_1354[2] = field_1355.method_11(this.field_1353[2]);
         this.field_1354[3] = field_1355.method_11(this.field_1353[3]);
         this.field_1354[4] = field_1355.method_11(this.field_1353[4]);
         this.field_1354[5] = field_1355.method_11(this.field_1353[5]);
         super.field_1339 = false;
         super.field_1340 = false;
      }
   }

   // $VF: renamed from: g (int, int, int) void
   public void method_881(int var1, int var2, int var3) {
      this.field_1349 = var1;
      this.field_1350 = var2;
      this.field_1351 = var3;
      int var4 = class_16.method_91(var1 >> 1);
      int var5 = class_16.method_92(var1 >> 1);
      this.field_1352[2].method_10(var5, 0, -var4);
      this.field_1352[3].method_10(-var5, 0, -var4);
      this.field_1352[4].method_10(0, -var5, -var4);
      this.field_1352[5].method_10(0, var5, -var4);
      this.field_1360 = (var4 << 12) / var5;
      this.field_1361 = this.field_1360 * ((this.field_1358 << 12) / this.field_1359) >> 12;
   }

   // $VF: renamed from: g (int) void
   public final void method_882(int var1) {
      this.method_881(var1, this.field_1350, this.field_1351);
   }

   // $VF: renamed from: a (x) boolean
   public final boolean method_883(class_3 var1) {
      if ((var1 = super.field_1342.method_511(var1)).field_39 > this.field_1350) {
         return false;
      } else {
         int var2 = this.field_1361 * var1.field_39 >> 12;
         int var3 = this.field_1360 * var1.field_39 >> 12;
         if (var2 != 0 && var3 != 0) {
            var1.field_37 = -((var1.field_37 << 11) / var2 * this.field_1358 >> 12) + (this.field_1358 >> 1);
            var1.field_38 = ((var1.field_38 << 11) / var3 * this.field_1359 >> 12) + (this.field_1359 >> 1);
            return var1.field_37 >= 0 && var1.field_38 >= 0 && var1.field_37 < this.field_1358 && var1.field_38 < this.field_1359;
         } else {
            return false;
         }
      }
   }

   // $VF: renamed from: a (du) byte
   public final byte method_884(class_15 var1) {
      for (int var3 = 5; var3 >= 0; var3--) {
         int var2;
         if ((var2 = var1.field_148.method_11(this.field_1353[var3]) - this.field_1354[var3]) < -var1.field_149) {
            return 0;
         }

         if (class_16.method_100(var2) < var1.field_149) {
            return 1;
         }
      }

      return 2;
   }

   // $VF: renamed from: a (an, t) void
   public final void method_837(class_106 var1, class_4 var2) {
   }

   // $VF: renamed from: b (an, t) void
   public final void method_838(class_106 var1, class_4 var2) {
   }

   // $VF: renamed from: c () void
   public abstract void method_885();

   // $VF: renamed from: a (int, int, int, int, int) an
   public static final class_106 method_886(int var0, int var1, int var2, int var3, int var4) {
      return new class_107(var0, var1, var2, var3, var4);
   }
}
