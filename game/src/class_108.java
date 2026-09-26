// $VF: renamed from: cx
public class class_108 extends class_106 {
   // $VF: renamed from: b v
   public class_5 field_1338;
   // $VF: renamed from: a ay
   public class_101 field_1339;
   // $VF: renamed from: b ay
   public class_101 field_1340;
   // $VF: renamed from: a int[][]
   public static int[][] field_1341 = new int[][]{{34, 104, 34, 104}, {29, 101, 29, 101}, {2, 104, 2, 104}};
   // $VF: renamed from: f int
   public int field_1342 = 40;
   // $VF: renamed from: c ay
   public class_101 field_1343;
   // $VF: renamed from: a int[]
   public int[] field_1344;
   // $VF: renamed from: b int[]
   public int[] field_1345;
   // $VF: renamed from: c int[]
   public int[] field_1346;
   // $VF: renamed from: g int
   public int field_1347;
   // $VF: renamed from: h int
   public int field_1348;
   // $VF: renamed from: d boolean
   public boolean field_1349 = false;
   // $VF: renamed from: e boolean
   public boolean field_1350 = false;

   public class_108(class_19 var1, class_101 var2, class_101 var3, int var4, int var5, int var6) {
      super(var1, null, 10000);
      var1.field_294 = false;
      if (var4 > 0) {
         var1.method_279(var4, this);
      }

      super.field_1327 = var2;
      this.field_1339 = var3;
      this.field_1340 = null;
      this.field_1338 = new class_5();
      this.field_1347 = var6;
      this.field_1343 = class_101.method_882(0, 2, (byte)2);
      this.field_1343.method_883(class_25.method_327(2));
      this.field_1343.field_1294 = 2;
      this.field_1345 = new int[24];
      this.field_1344 = new int[24];
      this.field_1346 = new int[16];

      for (int var7 = 0; var7 < this.field_1346.length; var7 += 8) {
         this.field_1346[var7] = field_1341[var5][0];
         this.field_1346[var7 + 1] = field_1341[var5][1];
         this.field_1346[var7 + 2] = field_1341[var5][2];
         this.field_1346[var7 + 3] = field_1341[var5][1];
         this.field_1346[var7 + 4] = field_1341[var5][2];
         this.field_1346[var7 + 5] = field_1341[var5][3];
         this.field_1346[var7 + 6] = field_1341[var5][0];
         this.field_1346[var7 + 7] = field_1341[var5][3];
      }
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      super.method_884();
      this.field_1343.method_884();
      this.field_1343 = null;
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1325.method_288();
      if (super.field_1327 != null) {
         class_41.field_527.method_265(super.field_1327);
      }

      if (super.field_1325.field_293) {
         class_41.field_527.method_265(this.field_1343);
      }
   }

   // $VF: renamed from: f () void
   private void method_892() {
      if (super.field_1325.field_297 != null && super.field_1325.field_297.field_1115) {
         ((class_89)super.field_1325.field_297).method_769();
      }

      super.field_1325.field_297.field_1114 = false;
      super.field_1325.field_297 = null;
      this.field_1340 = null;
      this.field_1349 = false;
      class_4.method_155(0, 0, "");
      class_3.method_103();
      super.field_1325.field_289 = false;
   }

   // $VF: renamed from: a (long) void
   public void method_885(long var1) {
      if (this.field_1349 && super.field_1325.field_289) {
         this.method_892();
      }

      super.field_1325.method_287(var1);
      if (super.field_1325.field_297 != null) {
         if (this.field_1340 == null) {
            this.field_1338 = super.field_1325.field_297.field_1103.method_844(this.field_1338);
            this.field_1338.method_177(super.field_1325.field_277.field_774.method_245());
            int var3 = class_124.method_943(40000, this.field_1338.method_183());
            float var4 = 1.0F - var3 / 40000.0F;
            int var5 = class_41.field_539.field_562;
            class_41.field_539.method_426(14, (int)(var5 * var4));
            this.field_1340 = super.field_1325.field_297.field_1103;
            this.field_1348 = super.field_1325.field_297.field_1102.field_1256;
            this.field_1349 = true;
            if (super.field_1325.field_297.field_1115 && !super.field_1325.field_297.method_747()) {
               ((class_89)super.field_1325.field_297).method_768(this.field_1347);
               if (class_41.field_527.field_249.method_897(class_106.field_1328)) {
                  class_4.method_155(
                     class_106.field_1328.field_138 + 10, class_106.field_1328.field_139 - 10, "" + ((class_89)super.field_1325.field_297).method_770()
                  );
               }
            }

            super.field_1325.field_289 = false;
         }

         if (super.field_1325.field_297.field_1102.field_1256 >= this.field_1348
            && (
               !super.field_1325.field_297.field_1115
                  || class_41.field_527.field_249.method_897(this.field_1340.method_844(this.field_1338))
                  || ((class_89)super.field_1325.field_297).field_1185
            )) {
            if (super.field_1325.field_297.field_1116 && (super.field_1325.field_297.method_747() || super.field_1325.field_297.method_748())
               || super.field_1325.field_297.field_1104 == 13
               || super.field_1325.field_297.field_1115 && ((class_89)super.field_1325.field_297).field_1185) {
               super.field_1325.field_279[0].method_169(this.field_1340.method_844(this.field_1338));
               this.field_1338 = super.field_1325.field_277.field_774.field_203.method_844(this.field_1338);
               this.field_1338.method_177(super.field_1325.field_279[0]);
               super.field_1325.field_297.field_1114 = true;
               if (super.field_1325.field_297.field_1115) {
                  ((class_89)super.field_1325.field_297).method_772(class_124.method_942(0, class_124.method_943(4096, this.field_1338.method_183() << 1)));
               }

               if (this.field_1338.method_183() <= 400) {
                  if (super.field_1325.field_297.field_1104 == 13) {
                     ((class_93)super.field_1325.field_297).method_783();
                  } else if (super.field_1325.field_297.field_1115) {
                     if (!((class_89)super.field_1325.field_297).method_771()) {
                        this.field_1340 = null;
                        this.field_1349 = false;
                        super.field_1325.field_293 = false;
                        ((class_89)super.field_1325.field_297).method_769();
                        super.field_1325.field_297 = null;
                     }
                  } else {
                     ((class_85)super.field_1325.field_297).method_762();
                     this.field_1349 = false;
                     this.field_1340 = null;
                  }

                  this.field_1350 = false;
                  return;
               }

               this.field_1338.method_182();
               this.field_1338.method_178((int)var1 * 10);
               this.field_1340.method_840(this.field_1338);
               if (!this.field_1350) {
                  class_41.field_539.method_427(1);
                  this.field_1350 = true;
               }
            } else if (super.field_1325.field_297.field_1115) {
               super.field_1325.field_279[0].method_169(this.field_1340.method_844(this.field_1338));
               class_106.field_1328 = this.field_1340.method_844(class_106.field_1328);
               if (!super.field_1325.field_297.method_747() && class_41.field_527.field_249.method_897(class_106.field_1328)) {
                  class_4.method_155(
                     class_106.field_1328.field_138 + 10, class_106.field_1328.field_139 - 10, "" + ((class_89)super.field_1325.field_297).method_770()
                  );
               }
            }
         } else {
            this.method_892();
         }
      }

      this.method_894();
   }

   // $VF: renamed from: f (v) v
   public class_5 method_893(class_5 var1) {
      var1.method_169(this.field_1339.method_844(this.field_1338));
      return var1;
   }

   // $VF: renamed from: e () void
   public final void method_894() {
      this.field_1338.method_169(super.field_1325.field_279[0]);
      if (super.field_1327 != null) {
         super.field_1327.method_842(this.field_1338);
      }

      if (super.field_1325.field_293) {
         if (this.field_1338.field_140 == 50000) {
            super.field_1325.field_293 = false;
            this.field_1340 = null;
            this.field_1349 = false;
            return;
         }

         this.field_1345[0] = this.field_1338.field_138 - this.field_1342;
         this.field_1345[1] = this.field_1338.field_139;
         this.field_1345[2] = this.field_1338.field_140;
         this.field_1345[3] = this.field_1338.field_138 + this.field_1342;
         this.field_1345[4] = this.field_1338.field_139;
         this.field_1345[5] = this.field_1338.field_140;
         this.field_1345[12] = this.field_1338.field_138;
         this.field_1345[13] = this.field_1338.field_139 - this.field_1342;
         this.field_1345[14] = this.field_1338.field_140;
         this.field_1345[15] = this.field_1338.field_138;
         this.field_1345[16] = this.field_1338.field_139 + this.field_1342;
         this.field_1345[17] = this.field_1338.field_140;
         this.field_1338 = this.method_893(this.field_1338);
         this.field_1345[6] = this.field_1338.field_138 + this.field_1342;
         this.field_1345[7] = this.field_1338.field_139;
         this.field_1345[8] = this.field_1338.field_140;
         this.field_1345[9] = this.field_1338.field_138 - this.field_1342;
         this.field_1345[10] = this.field_1338.field_139;
         this.field_1345[11] = this.field_1338.field_140;
         this.field_1345[18] = this.field_1338.field_138;
         this.field_1345[19] = this.field_1338.field_139 + this.field_1342;
         this.field_1345[20] = this.field_1338.field_140;
         this.field_1345[21] = this.field_1338.field_138;
         this.field_1345[22] = this.field_1338.field_139 - this.field_1342;
         this.field_1345[23] = this.field_1338.field_140;

         for (int var1 = 0; var1 < this.field_1345.length; var1 += 3) {
            this.field_1344[var1] = this.field_1345[var1] - this.field_1338.field_138;
            this.field_1344[var1 + 1] = this.field_1345[var1 + 1] - this.field_1338.field_139;
            this.field_1344[var1 + 2] = this.field_1345[var1 + 2] - this.field_1338.field_140;
         }

         this.field_1343.method_841(this.field_1338.field_138, this.field_1338.field_139, this.field_1338.field_140);
         ((class_105)this.field_1343).method_890(this.field_1344, this.field_1346);
      }
   }
}
