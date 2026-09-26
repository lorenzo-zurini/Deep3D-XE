// $VF: renamed from: ae
public final class class_118 {
   // $VF: renamed from: a cz
   private class_26 field_1443;
   // $VF: renamed from: a int
   private int field_1444;
   // $VF: renamed from: d boolean
   private boolean field_1445;
   // $VF: renamed from: a boolean
   public boolean field_1446;
   // $VF: renamed from: b boolean
   public boolean field_1447;
   // $VF: renamed from: a s
   private class_5 field_1448;
   // $VF: renamed from: b int
   private int field_1449;
   // $VF: renamed from: e boolean
   private boolean field_1450;
   // $VF: renamed from: a x
   private class_3 field_1451 = new class_3();
   // $VF: renamed from: b x
   private class_3 field_1452 = new class_3();
   // $VF: renamed from: c x
   private class_3 field_1453 = new class_3();
   // $VF: renamed from: a ck
   private class_39 field_1454;
   // $VF: renamed from: c int
   private int field_1455;
   // $VF: renamed from: c boolean
   public boolean field_1456;

   public class_118(class_42 var1, class_5 var2, class_26 var3) {
      class_69.method_645(false);
      this.field_1443 = var3;
      this.field_1444 = 0;
      this.field_1445 = true;
      this.field_1446 = true;
      this.field_1447 = false;
      this.field_1450 = false;
      this.field_1448 = var2;
      this.field_1456 = false;
      var1.method_373(false);
      var2.field_53 = true;
      if (class_21.method_143() == 1) {
         class_69.field_963 = true;
         var3.field_272.field_991 = true;
         var3.field_272.method_661();
         this.field_1454 = new class_39(class_84.field_1120, class_84.field_1121, 1);
         class_84.field_1110.method_24(this.field_1454.field_388);
      } else {
         if (class_26.field_301) {
            this.field_1451.field_37 = 2000 + class_84.field_1123.nextInt(2000);
            this.field_1451.field_38 = 2000 + class_84.field_1123.nextInt(2000);
            this.field_1451.field_39 = 30000;
         } else {
            this.field_1451.field_37 = 2000 + class_84.field_1123.nextInt(2000);
            this.field_1451.field_38 = -2000 + class_84.field_1123.nextInt(4000);
            this.field_1451.field_39 = 6000;
         }

         if (class_84.field_1123.nextInt(2) == 0) {
            this.field_1451.field_37 *= -1;
         }

         if (class_84.field_1123.nextInt(2) == 0) {
            this.field_1451.field_38 *= -1;
         }

         class_57 var4;
         (var4 = new class_57()).method_490(var3.field_272.field_970.method_866());
         this.field_1452 = var4.method_508(this.field_1451, this.field_1452);
         this.field_1452.method_15(var3.field_272.field_970.method_848(this.field_1451));
         class_84.field_1110.field_40.method_846(this.field_1452);
         var1.method_370(this.field_1452);
         var2.method_31(var3.field_272.field_970.method_857(), 2);
         if (class_21.method_132().field_1161 && !class_21.method_132().method_754()) {
            switch (class_21.method_143()) {
               case 25:
                  var3.field_274[0].field_1225.method_349();
            }
         }
      }

      var3.field_272.field_997 = false;
   }

   // $VF: renamed from: a (int, ce, y) boolean
   public final boolean method_913(int var1, class_42 var2, class_2 var3) {
      if (this.field_1446) {
         this.field_1449 += var1;
         if (class_21.method_143() == 1) {
            if (this.field_1444 == 0) {
               class_69.method_638("");
               this.field_1443.field_272.field_976.method_547(var1, class_84.field_1110.field_40.field_1342, false);
               this.field_1443.field_272.field_976.method_548();
               this.field_1454.method_364(this.field_1449);
               if (this.field_1449 > 69000) {
                  class_84.field_1122.method_773();
                  class_69.method_638("");
                  class_69.field_963 = false;
                  class_69.method_645(false);
                  this.field_1444 = 1;
                  this.field_1443.field_272.field_991 = false;
                  class_84.field_1110.method_24((class_106)var2.field_454);
                  var2.method_373(true);
                  this.field_1448.field_53 = false;
                  class_84.field_1110.field_40.method_870(this.field_1454.field_388.field_1341);
                  var2.method_374(class_84.field_1110.field_40.method_850());
               } else if (this.field_1449 > 4000 && this.field_1449 < 9000) {
                  class_69.method_638(class_84.field_1116.method_4(622));
               } else if (this.field_1449 > 14000 && this.field_1449 < 19000) {
                  class_69.method_638(class_84.field_1116.method_4(623));
               } else if (this.field_1449 > 24000 && this.field_1449 < 29000) {
                  class_69.method_645(true);
               } else if (this.field_1449 > 34000 && this.field_1449 < 39000) {
                  class_69.method_638(class_84.field_1116.method_4(624));
               } else if (this.field_1449 > 44000 && this.field_1449 < 51000) {
                  class_69.method_638(class_84.field_1116.method_4(625));
               } else if (this.field_1449 > 56000 && this.field_1449 < 61000) {
                  class_69.method_638(class_84.field_1116.method_4(626));
               } else if (this.field_1449 > 65000 && this.field_1449 < 69000) {
                  class_69.method_638(class_84.field_1116.method_4(627));
               }
            }
         } else if (class_26.field_301) {
            this.field_1451.method_10(0, 0, -10 * var1);
            this.field_1453 = this.field_1443.field_272.field_970.field_1341.method_508(this.field_1451, this.field_1453);
            class_84.field_1110.field_40.method_844(this.field_1453);
            if (this.field_1449 > 3500 && !this.field_1450) {
               ((class_99)this.field_1443.field_276[2]).method_824();
               this.field_1450 = true;
            }
         }

         if (class_21.method_143() != 1 && this.field_1449 > 7000 || this.field_1444 == 1) {
            this.field_1449 = 0;
            this.field_1446 = false;
            this.field_1447 = true;
            this.field_1448.field_53 = false;
            if (class_26.field_301) {
               this.field_1451.method_10(0, 0, -10000);
               this.field_1453 = this.field_1443.field_276[2].field_1226.field_1341.method_508(this.field_1451, this.field_1453);
               this.field_1453.method_15(this.field_1443.field_276[2].field_1226.method_850());
               var2.method_374(this.field_1453);
            } else {
               var2.method_374(class_84.field_1110.field_40.method_850());
            }

            var2.method_373(true);
            method_916(var2, this.field_1443);
            this.field_1445 = false;
            this.field_1443.field_272.field_997 = true;
            class_69.method_638(null);
            class_67.method_578(class_21.method_178().field_884);
            if (class_26.field_302 != null) {
               class_69.method_633(5, this.field_1443.field_272);
            }

            class_26.field_301 = false;
            if (class_26.field_302 != null) {
               this.field_1443.field_272.method_667(this.field_1443.field_276[1]);
            }
         }
      }

      if (class_21.method_132().field_1161 && !class_21.method_132().method_754()) {
         switch (class_21.method_143()) {
            case 21:
               if (this.field_1446) {
                  this.field_1443.field_274[0].method_795(false);
               } else if (this.field_1444 == 0 && this.field_1447) {
                  this.field_1444 = 1;
                  this.field_1443.field_274[0].method_795(true);
                  this.field_1443.field_274[0].method_804();
               }
               break;
            case 25:
               if (this.field_1443.field_280[3].field_184) {
                  this.field_1443.field_274[0].method_796(10);
                  this.field_1443.field_274[0].method_797(null);
               }

               if (this.field_1443.field_274[0].field_1230.method_111().field_1298) {
                  this.field_1443.field_274[0].method_795(false);
               }
               break;
            case 43:
               if (this.field_1443.field_280[0].field_184 && !this.field_1443.field_280[0].field_185) {
                  class_91[] var11 = this.field_1443.field_274;

                  for (int var13 = 0; var13 < var11.length; var13++) {
                     var11[var13].method_804();
                  }
               }
               break;
            case 47:
               if (this.field_1443.field_280[2].field_184 && this.field_1444 == 0) {
                  this.field_1444 = 1;
                  boolean var10 = false;
                  this.field_1443.field_273[this.field_1443.field_273.length - 1].field_1225.method_330(100);
               } else if (this.field_1443.field_280[6].field_185 && this.field_1444 == 1) {
                  this.field_1444 = 2;
                  class_91 var9 = this.field_1443.field_273[this.field_1443.field_273.length - 1];
                  this.field_1451 = var9.field_1226.method_848(this.field_1451);
                  var9.field_1226 = class_43.method_381(9994);
                  var9.field_1226.method_846(this.field_1451);
                  var9.field_1226.field_1367 = 2;
                  var9.field_1225.method_349();
                  var9.method_797(null);
                  class_18 var12 = new class_18(new int[]{0, 0, 0});
                  var9.field_1230 = var12;
                  ((class_96)var9).field_1282 = true;
                  var9.field_1225.method_327(32000);
                  var9.method_795(true);
                  var9.field_1224 = 1;
                  var9.method_796(6);
                  class_91[] var15 = this.field_1443.field_274;

                  for (int var7 = 0; var7 < var15.length; var7++) {
                     var15[var7].method_797(null);
                     var15[var7].field_1230 = var12.method_115();
                     var15[var7].field_1225.method_349();
                  }

                  var2.method_373(false);
                  this.field_1448.field_45 = var9.field_1226;
                  this.field_1448.field_53 = true;
                  this.field_1448.method_31(this.field_1443.field_272.field_970.method_857(), 2);
                  this.field_1451.field_39 -= 4000;
                  class_84.field_1110.field_40.method_846(this.field_1451);
                  this.field_1445 = true;
                  this.field_1456 = true;
               } else if (this.field_1443.field_280[10].field_184 && this.field_1444 == 2) {
                  this.field_1451.method_10(0, 4096, 0);
                  this.field_1448.method_31(this.field_1451, 2);
                  class_84.field_1110.field_40.method_845(15000, 8000, 28000);
                  Object var8 = null;
                  this.field_1448.field_45 = ((class_100)this.field_1443.field_276[0]).method_826();
                  this.field_1444 = 3;
               } else {
                  class_91 var4;
                  if (this.field_1444 == 2 && (var4 = this.field_1443.field_273[this.field_1443.field_273.length - 1]).field_1230.method_111().field_1298) {
                     var4.field_1226.method_845(0, 0, 0);
                     var4.method_795(false);
                     var4.method_803();
                     var4.field_1225.method_327(0);
                     class_18 var5;
                     (var5 = new class_18(new int[]{40000, 0, 0, 36000, -3000, 4000})).field_163 = true;

                     for (int var6 = 0; var6 < this.field_1443.field_274.length; var6++) {
                        this.field_1443.field_274[var6].field_1230 = var5.method_115();
                     }

                     class_18 var14;
                     (var14 = new class_18(new int[]{42000, -2000, 3000, 30000, -1000, -5000})).field_163 = true;
                     this.field_1443.field_272.field_982 = var14;
                     this.field_1443.field_272.method_667(var14.method_111());
                  }
               }

               if (this.field_1444 == 3) {
                  this.field_1455 += var1 / 4;
                  ((class_100)this.field_1443.field_276[0]).method_827(0, var1 * 2 + this.field_1455, 0);
                  if (this.field_1443.field_280[12].field_185) {
                     this.field_1444 = 4;
                     this.field_1448.field_53 = true;
                     this.field_1443.field_272.method_670(44000, -5000, 1000);
                     this.field_1451.method_10(0, 4096, 0);
                     this.field_1448.method_31(this.field_1451, 2);
                     this.field_1448.field_45 = this.field_1443.field_272.field_970;
                     this.field_1448.field_48 = class_84.field_1110.field_40;
                     class_84.field_1110.field_40.method_845(33000, -4000, 2000);
                  }
               }

               if (this.field_1444 == 4 && this.field_1443.field_280[15].field_185) {
                  this.field_1444 = 5;
                  this.field_1451 = this.field_1443.field_274[0].method_799(this.field_1451);
                  this.field_1451.field_37 += 5000;
                  this.field_1451.field_38 -= 2000;
                  class_84.field_1110.field_40.method_846(this.field_1451);
                  this.field_1448.field_45 = this.field_1443.field_274[0].field_1226;
               }

               if (this.field_1444 == 5 && this.field_1443.field_280[17].field_185) {
                  this.field_1444 = 6;
                  this.field_1451 = this.field_1443.field_274[1].method_799(this.field_1451);
                  this.field_1451.field_37 -= 5000;
                  this.field_1451.field_38 += 2000;
                  class_84.field_1110.field_40.method_846(this.field_1451);
                  this.field_1448.field_45 = this.field_1443.field_274[1].field_1226;
               }

               if (this.field_1444 == 6 && this.field_1443.field_280[19].field_185) {
                  this.field_1444 = 7;
                  this.field_1451 = this.field_1443.field_274[1].method_799(this.field_1451);
                  this.field_1451.field_39 += 8000;
                  this.field_1451.field_38 += 1000;
                  class_84.field_1110.field_40.method_846(this.field_1451);
                  this.field_1448.field_45 = this.field_1443.field_274[1].field_1226;
               }

               if (this.field_1444 == 7 && this.field_1443.field_280[24].field_185) {
                  this.field_1444 = 8;
                  this.field_1448.field_53 = false;
                  var2.method_373(true);
                  this.field_1449 = 0;
                  class_69.method_635();
                  this.field_1443.field_272.method_670(44000, -5000, 1000);
               }

               if (this.field_1444 == 8) {
                  class_69.method_636(1);
                  if (class_69.method_637()) {
                     this.field_1444 = 9;
                  }
               }

               if (this.field_1444 == 9) {
                  class_21.method_133(class_87.field_1145);
                  class_21.method_145();
                  this.field_1443.field_273[this.field_1443.field_273.length - 1].method_802();
                  this.field_1443.field_272.method_667(null);
                  this.field_1443.field_272.field_982 = null;
                  this.field_1443.method_269();
                  this.field_1443.field_277 = null;
                  new class_2(this.field_1443);
                  this.field_1445 = false;
                  this.field_1444 = 10;
                  this.field_1456 = false;
               }
         }
      }

      return this.field_1445;
   }

   // $VF: renamed from: a () void
   public final void method_914() {
      if (class_21.method_143() > 1) {
         this.field_1449 = 7001;
      }

      class_67.method_578(class_21.method_178().field_884);
   }

   // $VF: renamed from: b () void
   public final void method_915() {
      this.field_1447 = false;
      this.field_1449 = 0;
      this.field_1450 = true;
   }

   // $VF: renamed from: a (ce, cz) void
   public static final void method_916(class_42 var0, class_26 var1) {
      var0.method_368(var1.field_272.field_970);
      var0.method_375(new class_3(0, 850, 0));
      var0.method_376(new class_3(0, 1050, -4000));
      var0.method_372();
   }

   // $VF: renamed from: a (ce) void
   public static final void method_917(class_42 var0) {
      var0.method_375(new class_3(0, 300, 0));
      var0.method_376(new class_3(0, 300, 5600));
   }

   // $VF: renamed from: b (ce) void
   public static final void method_918(class_42 var0) {
      var0.method_375(new class_3(0, 500, 0));
      var0.method_376(new class_3(6000, 500, 0));
   }

   // $VF: renamed from: c (ce) void
   public static final void method_919(class_42 var0) {
      var0.method_375(new class_3(0, 500, 0));
      var0.method_376(new class_3(-6000, 500, 0));
   }
}
