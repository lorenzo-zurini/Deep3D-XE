// $VF: renamed from: cy
public class class_114 extends class_112 {
   // $VF: renamed from: b x
   public class_3 field_1422;
   // $VF: renamed from: a ax
   public class_108 field_1423;
   // $VF: renamed from: b ax
   public class_108 field_1424;
   // $VF: renamed from: a int[][]
   public static int[][] field_1425 = new int[][]{{34, 104, 34, 104}, {29, 101, 29, 101}, {2, 104, 2, 104}};
   // $VF: renamed from: c int
   public int field_1426 = 40;
   // $VF: renamed from: c ax
   public class_108 field_1427;
   // $VF: renamed from: a int[]
   public int[] field_1428;
   // $VF: renamed from: b int[]
   public int[] field_1429;
   // $VF: renamed from: c int[]
   public int[] field_1430;
   // $VF: renamed from: g int
   public int field_1431;
   // $VF: renamed from: h int
   public int field_1432;
   // $VF: renamed from: d boolean
   public boolean field_1433 = false;

   public class_114(class_9 var1, class_108 var2, class_108 var3, int var4, int var5, int var6) {
      super(var1, null, 10000);
      var1.field_93 = false;
      if (var4 > 0) {
         var1.method_41(var4, this);
      }

      super.field_1411 = var2;
      this.field_1423 = var3;
      this.field_1424 = null;
      this.field_1422 = new class_3();
      this.field_1431 = var6;
      this.field_1427 = class_108.method_892(0, 2, (byte)2);
      this.field_1427.method_893(class_43.method_380(2));
      ((class_109)this.field_1427).field_1383 = -16711936;
      this.field_1427.field_1367 = 2;
      this.field_1429 = new int[24];
      this.field_1428 = new int[24];
      this.field_1430 = new int[16];

      for (int var7 = 0; var7 < this.field_1430.length; var7 += 8) {
         this.field_1430[var7] = field_1425[var5][0];
         this.field_1430[var7 + 1] = field_1425[var5][1];
         this.field_1430[var7 + 2] = field_1425[var5][2];
         this.field_1430[var7 + 3] = field_1425[var5][1];
         this.field_1430[var7 + 4] = field_1425[var5][2];
         this.field_1430[var7 + 5] = field_1425[var5][3];
         this.field_1430[var7 + 6] = field_1425[var5][0];
         this.field_1430[var7 + 7] = field_1425[var5][3];
      }
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      super.method_894();
      this.field_1427.method_894();
      this.field_1427 = null;
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      super.field_1409.method_50();
      if (super.field_1411 != null) {
         class_84.field_1110.method_25(super.field_1411);
      }

      if (super.field_1409.field_92) {
         class_84.field_1110.method_25(this.field_1427);
      }
   }

   // $VF: renamed from: g () void
   private void method_905() {
      if (super.field_1409.field_96 != null && super.field_1409.field_96.field_1238) {
         ((class_101)super.field_1409.field_96).method_831();
      }

      super.field_1409.field_96.field_1237 = false;
      super.field_1409.field_96 = null;
      this.field_1424 = null;
      this.field_1433 = false;
      class_69.method_634(0, 0, "");
      class_21.method_173();
      super.field_1409.field_88 = false;
   }

   // $VF: renamed from: a (long) void
   public void method_895(long var1) {
      if (this.field_1433 && super.field_1409.field_88) {
         this.method_905();
      }

      super.field_1409.method_49(var1);
      if (super.field_1409.field_96 != null) {
         if (this.field_1424 == null) {
            this.field_1422 = super.field_1409.field_96.field_1226.method_848(this.field_1422);
            this.field_1422.method_17(super.field_1409.field_76.field_272.method_664());
            int var3 = class_16.method_98(40000, this.field_1422.method_23());
            float var4 = 1.0F - var3 / 40000.0F;
            int var5 = class_84.field_1122.field_1182;
            class_84.field_1122.method_769(14, (int)(var5 * var4));
            this.field_1424 = super.field_1409.field_96.field_1226;
            this.field_1432 = super.field_1409.field_96.field_1225.field_363;
            this.field_1433 = true;
            if (super.field_1409.field_96.field_1238 && !super.field_1409.field_96.method_800()) {
               ((class_101)super.field_1409.field_96).method_830(this.field_1431);
               if (class_84.field_1110.field_40.method_883(class_112.field_1412)) {
                  class_69.method_634(
                     class_112.field_1412.field_37 + 10, class_112.field_1412.field_38 - 10, "" + ((class_101)super.field_1409.field_96).method_832()
                  );
               }
            }

            super.field_1409.field_88 = false;
         }

         if (super.field_1409.field_96.field_1225.field_363 >= this.field_1432
            && (
               !super.field_1409.field_96.field_1238
                  || class_84.field_1110.field_40.method_883(this.field_1424.method_848(this.field_1422))
                  || ((class_101)super.field_1409.field_96).field_1326
            )) {
            if (super.field_1409.field_96.field_1239 && (super.field_1409.field_96.method_800() || super.field_1409.field_96.method_801())
               || super.field_1409.field_96.field_1227 == 13
               || super.field_1409.field_96.field_1238 && ((class_101)super.field_1409.field_96).field_1326) {
               super.field_1409.field_78[0].method_9(this.field_1424.method_848(this.field_1422));
               this.field_1422 = super.field_1409.field_76.field_272.field_970.method_848(this.field_1422);
               this.field_1422.method_17(super.field_1409.field_78[0]);
               super.field_1409.field_96.field_1237 = true;
               if (super.field_1409.field_96.field_1238) {
                  ((class_101)super.field_1409.field_96).method_834(class_16.method_97(0, class_16.method_98(4096, this.field_1422.method_23() << 1)));
               }

               if (this.field_1422.method_23() <= 400) {
                  if (super.field_1409.field_96.field_1227 == 13) {
                     ((class_93)super.field_1409.field_96).method_811();
                     return;
                  }

                  if (super.field_1409.field_96.field_1238) {
                     if (!((class_101)super.field_1409.field_96).method_833()) {
                        this.field_1424 = null;
                        this.field_1433 = false;
                        super.field_1409.field_92 = false;
                        ((class_101)super.field_1409.field_96).method_831();
                        super.field_1409.field_96 = null;
                        return;
                     }
                  } else {
                     ((class_96)super.field_1409.field_96).method_817();
                     this.field_1433 = false;
                     this.field_1424 = null;
                  }

                  return;
               }

               this.field_1422.method_22();
               this.field_1422.method_18((int)var1 * 10);
               this.field_1424.method_844(this.field_1422);
            } else if (super.field_1409.field_96.field_1238) {
               super.field_1409.field_78[0].method_9(this.field_1424.method_848(this.field_1422));
               class_112.field_1412 = this.field_1424.method_848(class_112.field_1412);
               if (!super.field_1409.field_96.method_800() && class_84.field_1110.field_40.method_883(class_112.field_1412)) {
                  class_69.method_634(
                     class_112.field_1412.field_37 + 10, class_112.field_1412.field_38 - 10, "" + ((class_101)super.field_1409.field_96).method_832()
                  );
               }
            }
         } else {
            this.method_905();
         }
      }

      this.method_907();
   }

   // $VF: renamed from: f (x) x
   public class_3 method_906(class_3 var1) {
      var1.method_9(this.field_1423.method_848(this.field_1422));
      return var1;
   }

   // $VF: renamed from: f () void
   public final void method_907() {
      this.field_1422.method_9(super.field_1409.field_78[0]);
      if (super.field_1411 != null) {
         super.field_1411.method_846(this.field_1422);
      }

      if (super.field_1409.field_92) {
         if (this.field_1422.field_39 == 50000) {
            super.field_1409.field_92 = false;
            this.field_1424 = null;
            this.field_1433 = false;
            return;
         }

         this.field_1429[0] = this.field_1422.field_37 - this.field_1426;
         this.field_1429[1] = this.field_1422.field_38;
         this.field_1429[2] = this.field_1422.field_39;
         this.field_1429[3] = this.field_1422.field_37 + this.field_1426;
         this.field_1429[4] = this.field_1422.field_38;
         this.field_1429[5] = this.field_1422.field_39;
         this.field_1429[12] = this.field_1422.field_37;
         this.field_1429[13] = this.field_1422.field_38 - this.field_1426;
         this.field_1429[14] = this.field_1422.field_39;
         this.field_1429[15] = this.field_1422.field_37;
         this.field_1429[16] = this.field_1422.field_38 + this.field_1426;
         this.field_1429[17] = this.field_1422.field_39;
         this.field_1422 = this.method_906(this.field_1422);
         this.field_1429[6] = this.field_1422.field_37 + this.field_1426;
         this.field_1429[7] = this.field_1422.field_38;
         this.field_1429[8] = this.field_1422.field_39;
         this.field_1429[9] = this.field_1422.field_37 - this.field_1426;
         this.field_1429[10] = this.field_1422.field_38;
         this.field_1429[11] = this.field_1422.field_39;
         this.field_1429[18] = this.field_1422.field_37;
         this.field_1429[19] = this.field_1422.field_38 + this.field_1426;
         this.field_1429[20] = this.field_1422.field_39;
         this.field_1429[21] = this.field_1422.field_37;
         this.field_1429[22] = this.field_1422.field_38 - this.field_1426;
         this.field_1429[23] = this.field_1422.field_39;

         for (int var1 = 0; var1 < this.field_1429.length; var1 += 3) {
            this.field_1428[var1] = this.field_1429[var1] - this.field_1422.field_37;
            this.field_1428[var1 + 1] = this.field_1429[var1 + 1] - this.field_1422.field_38;
            this.field_1428[var1 + 2] = this.field_1429[var1 + 2] - this.field_1422.field_39;
         }

         this.field_1427.method_845(this.field_1422.field_37, this.field_1422.field_38, this.field_1422.field_39);
         ((class_109)this.field_1427).method_896(this.field_1428, this.field_1430);
      }
   }
}
