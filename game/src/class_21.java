// $VF: renamed from: ar
public final class class_21 {
   // $VF: renamed from: a int[]
   private int[] field_306;
   // $VF: renamed from: b int[]
   private int[] field_307;
   // $VF: renamed from: c int[]
   private int[] field_308;
   // $VF: renamed from: d int[]
   private int[] field_309;
   // $VF: renamed from: a v
   private class_5 field_310 = new class_5();
   // $VF: renamed from: b v
   private class_5 field_311 = new class_5();
   // $VF: renamed from: a a
   private class_61 field_312;
   // $VF: renamed from: a ay[]
   private class_101[] field_313;

   public class_21() {
      this.field_308 = new int[10];
      this.field_306 = new int[12];
      this.field_307 = new int[10];
      this.field_309 = new int[8];
      this.field_309[0] = 64;
      this.field_309[1] = 0;
      this.field_309[2] = 96;
      this.field_309[3] = 0;
      this.field_309[4] = 96;
      this.field_309[5] = 31;
      this.field_309[6] = 64;
      this.field_309[7] = 31;
      this.field_306[0] = -100;
      this.field_306[1] = 0;
      this.field_306[2] = 0;
      this.field_306[3] = 100;
      this.field_306[4] = 0;
      this.field_306[5] = 0;
      this.field_306[6] = 100;
      this.field_306[7] = 0;
      this.field_306[8] = 1000;
      this.field_306[9] = -100;
      this.field_306[10] = 0;
      this.field_306[11] = 1000;
      this.field_313 = new class_101[10];

      for (int var1 = 0; var1 < this.field_313.length; var1++) {
         this.field_313[var1] = class_101.method_882(0, 1, (byte)2);
         this.field_313[var1].method_883(class_25.method_327(2));
         this.field_313[var1].field_1294 = 2;
         ((class_105)this.field_313[var1]).method_890(this.field_306, this.field_309);
         this.field_313[var1].method_841(100000, 100000, 100000);
      }

      this.field_312 = new class_61();
   }

   // $VF: renamed from: a () void
   public final void method_292() {
      for (int var1 = 0; var1 < this.field_313.length; var1++) {
         this.field_313[var1].method_884();
      }

      this.field_313 = null;
      this.field_306 = null;
      this.field_309 = null;
   }

   // $VF: renamed from: a (long, bn) void
   public final void method_293(long var1, class_1 var3) {
      boolean var4 = false;

      for (int var5 = 0; var5 < 10; var5++) {
         if (this.field_307[var5] <= 0 && !var4) {
            int var6 = class_41.field_540.nextInt(18000) - 9000;
            int var7 = class_41.field_540.nextInt(18000) - 9000;
            boolean var8 = false;
            this.field_311.method_170(var6, var7, 20000);
            this.field_310 = var3.method_39(this.field_311, this.field_310);
            this.field_312 = var3.method_31(this.field_312);
            this.field_313[var5].method_842(this.field_310);
            this.field_313[var5].method_863(this.field_312);
            this.field_307[var5] = 2000;
            this.field_308[var5] = 300 + class_41.field_540.nextInt(300);
            var4 = true;
         } else {
            this.field_307[var5] = (int)(this.field_307[var5] - var1);
            this.field_313[var5].method_843(-this.field_308[var5]);
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_294() {
      for (int var1 = 0; var1 < this.field_313.length; var1++) {
         class_41.field_527.method_265(this.field_313[var1]);
      }
   }
}
