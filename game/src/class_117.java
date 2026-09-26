// $VF: renamed from: bk
public final class class_117 extends class_113 {
   // $VF: renamed from: a long
   private long field_1438;
   // $VF: renamed from: b long
   private long field_1439;
   // $VF: renamed from: c long
   private long field_1440;
   // $VF: renamed from: d long
   private long field_1441;
   // $VF: renamed from: a int
   private int field_1442;
   // $VF: renamed from: a boolean
   public boolean field_1443;
   // $VF: renamed from: a c
   private class_99 field_1444;
   // $VF: renamed from: a am
   private class_111 field_1445;
   // $VF: renamed from: a ck
   private class_10 field_1446;
   // $VF: renamed from: a ce
   public class_65 field_1447;
   // $VF: renamed from: a s
   public class_71 field_1448;
   // $VF: renamed from: a bb
   private class_16 field_1449;
   // $VF: renamed from: a cy
   public class_57 field_1450;
   // $VF: renamed from: b int
   private int field_1451;
   // $VF: renamed from: a v
   private class_5 field_1452 = new class_5();
   // $VF: renamed from: c int
   private int field_1453;
   // $VF: renamed from: a bh
   private class_52 field_1454;
   // $VF: renamed from: a ay[]
   private class_101[] field_1455;
   // $VF: renamed from: a u
   private class_98 field_1456;

   public class_117(int var1) {
      this.field_1451 = var1;
   }

   // $VF: renamed from: b () void
   public final void method_903() {
      if (this.field_1449 != null) {
         this.field_1449.method_261();
      }

      this.field_1449 = null;
      this.field_1445 = null;
      if (this.field_1450 != null) {
         this.field_1450.method_561();
      }

      this.field_1450 = null;
      if (this.field_1448 != null) {
         this.field_1448.field_1031 = null;
         this.field_1448.field_1034 = null;
      }

      this.field_1448 = null;
      if (this.field_1447 != null) {
         this.field_1447.method_609(null);
         this.field_1447.method_610(null);
      }

      this.field_1447 = null;
      this.field_1444 = null;
      this.field_1443 = false;
      this.field_1452 = null;
      this.field_1455 = null;
      ;
   }

   // $VF: renamed from: a () void
   public final void method_902() {
      try {
         if (this.field_1451 == 1) {
            if (class_3.method_110().field_837 != null) {
               class_32[] var1 = class_3.method_110().field_837;
               this.field_1455 = new class_101[var1.length];

               for (int var2 = 0; var2 < this.field_1455.length; var2++) {
                  this.field_1455[var2] = class_25.method_328(class_24.field_361[var1[var2].field_422]);
               }

               this.field_1445 = class_111.method_899(class_41.field_537, class_41.field_538, 800, 100, 31768);
               this.field_1445.method_839(0, 1000, -1400);
               this.field_1445.method_856(400, 2048, 0);
               this.field_1456 = new class_98();
               this.field_1456.method_875(this.field_1445);
            }
         } else {
            if (this.field_1450 == null) {
               this.field_1450 = new class_57(this.field_1451);
            }

            if (!this.field_1450.method_530()) {
               return;
            }

            this.field_1449 = this.field_1450.field_774;
            if (this.field_1449 != null) {
               this.field_1449.method_247(false);
               this.field_1454 = this.field_1449.field_209;
            } else {
               this.field_1454 = new class_52();
            }

            this.field_1453 = 0;
            this.field_1446 = new class_10(class_41.field_537, class_41.field_538, 0);
            switch (this.field_1451) {
               case 0:
                  class_41.field_527.method_264(this.field_1446.field_170);
                  break;
               case 1:
                  this.field_1445.method_860(380, 2048, 0);
                  break;
               case 2:
                  this.field_1445.method_860(0, 1024, 0);
                  class_41.field_527.method_264(this.field_1445);
            }
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }

      ;
      this.field_1438 = System.currentTimeMillis();
      this.field_1439 = System.currentTimeMillis();
      this.field_1443 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_904() {
      return this.field_1443;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_914(int var1, int var2) {
      this.field_1450.field_776[var1].field_1103 = class_25.method_328(var2);
      this.field_1450.field_776[var1].field_1103.field_1294 = 2;
   }

   // $VF: renamed from: c (int) void
   public final void method_915(int var1) {
      this.field_1453 = var1;
      if (this.field_1445 == null) {
         this.field_1445 = class_111.method_899(class_41.field_537, class_41.field_538, 800, 100, 31768);
         this.field_1445.method_839(0, 1000, -2200);
         this.field_1445.method_856(400, 2048, 0);
         this.field_1456 = new class_98();
         this.field_1456.method_875(this.field_1445);
         this.field_1456.method_855((short)2);
      }

      this.field_1456.method_842(this.field_1450.field_776[this.field_1453].method_746(this.field_1452));
      class_41.field_527.method_264(this.field_1445);
   }

   // $VF: renamed from: c () void
   public final void method_916() {
      class_41.field_527.method_264(this.field_1446.field_170);
   }

   // $VF: renamed from: d () void
   public final void method_917() {
      this.method_900(0);
   }

   // $VF: renamed from: b (int) void
   public final void method_900(int var1) {
      if (this.field_1443) {
         this.field_1438 = System.currentTimeMillis();
         this.field_1440 = this.field_1438 - this.field_1439;
         this.field_1439 = this.field_1438;
         this.field_1441 = this.field_1441 + this.field_1440;
         this.field_1442 = (int)(this.field_1442 + this.field_1440);
         this.field_1446.method_207(System.currentTimeMillis());
         if (this.field_1456 != null) {
            this.field_1456.method_842(this.field_1450.field_776[this.field_1453].method_746(this.field_1452));
            if ((var1 & 2) != 0) {
               this.field_1456.method_856((int)this.field_1440, 0, 0);
            }

            if ((var1 & 64) != 0) {
               this.field_1456.method_856(-((int)this.field_1440), 0, 0);
            }

            if ((var1 & 4) != 0) {
               this.field_1456.method_856(0, (int)this.field_1440, 0);
            }

            if ((var1 & 32) != 0) {
               this.field_1456.method_856(0, -((int)this.field_1440), 0);
            }
         }

         if (this.field_1454 != null) {
            this.field_1454.method_511(this.field_1440, class_41.field_527.field_249.field_1284, true);
         }

         this.method_918();
      }
   }

   // $VF: renamed from: e () void
   private void method_918() {
      try {
         if (this.field_1451 != 1) {
            this.field_1450.method_557(this.field_1440);
            this.field_1450.method_555(this.field_1440);
            if (this.field_1444 != null) {
               this.field_1444.method_835(true);
            }

            this.field_1454.method_512();
         }

         class_41.field_528.method_333(class_41.field_534);
         class_41.field_527.method_267(System.currentTimeMillis());
         class_41.field_528.method_335();
         class_41.field_528.method_334(class_41.field_534);
      } catch (Exception var2) {
         class_41.field_528.method_334(class_41.field_534);
         var2.printStackTrace();
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_901(int var1) {
   }

   static {
      int[][] var10000 = new int[][]{{0, 850, 1500}, {1000, -300, 3000}, {0, 2000, 0}};
      var10000 = new int[][]{{0, 650, 0}, {0, 0, 0}, {0, 0, 0}};
   }
}
