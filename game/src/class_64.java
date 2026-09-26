import com.nokia.mid.ui.DeviceControl;

// $VF: renamed from: ad
public final class class_64 {
   // $VF: renamed from: a cy
   private class_57 field_860;
   // $VF: renamed from: a int
   private int field_861;
   // $VF: renamed from: d boolean
   private boolean field_862;
   // $VF: renamed from: a boolean
   public boolean field_863;
   // $VF: renamed from: b boolean
   public boolean field_864;
   // $VF: renamed from: a s
   private class_71 field_865;
   // $VF: renamed from: b int
   private int field_866;
   // $VF: renamed from: e boolean
   private boolean field_867;
   // $VF: renamed from: a v
   private class_5 field_868 = new class_5();
   // $VF: renamed from: b v
   private class_5 field_869 = new class_5();
   // $VF: renamed from: c v
   private class_5 field_870 = new class_5();
   // $VF: renamed from: a ck
   private class_10 field_871;
   // $VF: renamed from: c int
   private int field_872;
   // $VF: renamed from: c boolean
   public boolean field_873;

   public class_64(class_65 var1, class_71 var2, class_57 var3) {
      class_4.method_166(false);
      this.field_860 = var3;
      this.field_861 = 0;
      this.field_862 = true;
      this.field_863 = true;
      this.field_864 = false;
      this.field_867 = false;
      this.field_865 = var2;
      this.field_873 = false;
      var1.method_614(false);
      var2.field_1039 = true;
      if (class_3.method_73() == 1) {
         class_4.field_135 = true;
         var3.field_774.field_224 = true;
         var3.field_774.method_242();
         this.field_871 = new class_10(class_41.field_537, class_41.field_538, 1);
         class_41.field_527.method_264(this.field_871.field_170);
      } else {
         if (class_57.field_803) {
            this.field_868.field_138 = 2000 + class_41.field_540.nextInt(2000);
            this.field_868.field_139 = 2000 + class_41.field_540.nextInt(2000);
            this.field_868.field_140 = 30000;
         } else {
            this.field_868.field_138 = 2000 + class_41.field_540.nextInt(2000);
            this.field_868.field_139 = -2000 + class_41.field_540.nextInt(4000);
            this.field_868.field_140 = 6000;
         }

         if (class_41.field_540.nextInt(2) == 0) {
            this.field_868.field_138 *= -1;
         }

         if (class_41.field_540.nextInt(2) == 0) {
            this.field_868.field_139 *= -1;
         }

         class_1 var4;
         (var4 = new class_1()).method_23(var3.field_774.field_203.method_862());
         this.field_869 = var4.method_40(this.field_868, this.field_869);
         this.field_869.method_175(var3.field_774.field_203.method_844(this.field_868));
         class_41.field_527.field_249.method_842(this.field_869);
         var1.method_611(this.field_869);
         var2.method_689(var3.field_774.field_203.method_853(), 2);
         if (class_3.method_62().field_1241 && !class_3.method_62().method_789()) {
            switch (class_3.method_73()) {
               case 25:
                  var3.field_776[0].field_1102.method_828();
            }
         }
      }

      var3.field_774.field_230 = false;
   }

   // $VF: renamed from: a (int, ce, w) boolean
   public final boolean method_602(int var1, class_65 var2, class_33 var3) {
      if (this.field_863) {
         this.field_866 += var1;
         if (class_3.method_73() == 1) {
            if (this.field_861 == 0) {
               class_4.method_159("");
               this.field_860.field_774.field_209.method_511(var1, class_41.field_527.field_249.field_1284, false);
               this.field_860.field_774.field_209.method_512();
               this.field_871.method_207(this.field_866);
               if (this.field_866 > 69000) {
                  class_41.field_539.method_430();
                  class_4.method_159("");
                  class_4.field_135 = false;
                  class_4.method_166(false);
                  this.field_861 = 1;
                  this.field_860.field_774.field_224 = false;
                  class_41.field_527.method_264((class_111)var2.field_876);
                  var2.method_614(true);
                  this.field_865.field_1039 = false;
                  class_41.field_527.field_249.method_866(this.field_871.field_170.field_1283);
                  var2.method_615(class_41.field_527.field_249.method_846());
               } else if (this.field_866 > 4000 && this.field_866 < 9000) {
                  class_4.method_159(class_41.field_533.method_297(622));
                  DeviceControl.setLights(0, 100);
               } else if (this.field_866 > 14000 && this.field_866 < 19000) {
                  class_4.method_159(class_41.field_533.method_297(623));
               } else if (this.field_866 > 24000 && this.field_866 < 29000) {
                  class_4.method_166(true);
                  DeviceControl.setLights(0, 100);
               } else if (this.field_866 > 34000 && this.field_866 < 39000) {
                  class_4.method_159(class_41.field_533.method_297(624));
                  DeviceControl.setLights(0, 100);
               } else if (this.field_866 > 44000 && this.field_866 < 51000) {
                  class_4.method_159(class_41.field_533.method_297(625));
                  DeviceControl.setLights(0, 100);
               } else if (this.field_866 > 56000 && this.field_866 < 61000) {
                  class_4.method_159(class_41.field_533.method_297(626));
                  DeviceControl.setLights(0, 100);
               } else if (this.field_866 > 65000 && this.field_866 < 69000) {
                  class_4.method_159(class_41.field_533.method_297(627));
                  DeviceControl.setLights(0, 100);
               }
            }
         } else if (class_57.field_803) {
            this.field_868.method_170(0, 0, -10 * var1);
            this.field_870 = this.field_860.field_774.field_203.field_1283.method_40(this.field_868, this.field_870);
            class_41.field_527.field_249.method_840(this.field_870);
            if (this.field_866 > 3500 && !this.field_867) {
               ((class_91)this.field_860.field_778[2]).method_778();
               this.field_867 = true;
            }
         }

         if (class_3.method_73() != 1 && this.field_866 > 7000 || this.field_861 == 1) {
            this.field_866 = 0;
            this.field_863 = false;
            this.field_864 = true;
            this.field_865.field_1039 = false;
            if (class_57.field_803) {
               this.field_868.method_170(0, 0, -10000);
               this.field_870 = this.field_860.field_778[2].field_1103.field_1283.method_40(this.field_868, this.field_870);
               this.field_870.method_175(this.field_860.field_778[2].field_1103.method_846());
               var2.method_615(this.field_870);
            } else {
               var2.method_615(class_41.field_527.field_249.method_846());
            }

            var2.method_614(true);
            method_605(var2, this.field_860);
            this.field_862 = false;
            this.field_860.field_774.field_230 = true;
            class_4.method_159(null);
            class_69.method_654(class_3.method_108().field_443);
            if (class_57.field_804 != null) {
               class_4.method_154(5, this.field_860.field_774);
            }

            class_57.field_803 = false;
            if (class_57.field_804 != null) {
               this.field_860.field_774.method_248(this.field_860.field_778[1]);
            }
         }
      }

      if (class_3.method_62().field_1241 && !class_3.method_62().method_789()) {
         switch (class_3.method_73()) {
            case 21:
               if (this.field_863) {
                  this.field_860.field_776[0].method_742(false);
               } else if (this.field_861 == 0 && this.field_864) {
                  this.field_861 = 1;
                  this.field_860.field_776[0].method_742(true);
                  this.field_860.field_776[0].method_751();
               }
               break;
            case 25:
               if (this.field_860.field_782[3].field_419) {
                  this.field_860.field_776[0].method_743(10);
                  this.field_860.field_776[0].method_744(null);
               }

               if (this.field_860.field_776[0].field_1107.method_220().field_1164) {
                  this.field_860.field_776[0].method_742(false);
               }
               break;
            case 43:
               if (this.field_860.field_782[0].field_419 && !this.field_860.field_782[0].field_420) {
                  class_83[] var11 = this.field_860.field_776;

                  for (int var13 = 0; var13 < var11.length; var13++) {
                     var11[var13].method_751();
                  }
               }
               break;
            case 47:
               if (this.field_860.field_782[2].field_419 && this.field_861 == 0) {
                  this.field_861 = 1;
                  boolean var10 = false;
                  this.field_860.field_775[this.field_860.field_775.length - 1].field_1102.method_809(100);
               } else if (this.field_860.field_782[6].field_420 && this.field_861 == 1) {
                  this.field_861 = 2;
                  class_83 var9 = this.field_860.field_775[this.field_860.field_775.length - 1];
                  this.field_868 = var9.field_1103.method_844(this.field_868);
                  var9.field_1103 = class_25.method_328(9994);
                  var9.field_1103.method_842(this.field_868);
                  var9.field_1103.field_1294 = 2;
                  var9.field_1102.method_828();
                  var9.method_744(null);
                  class_13 var12 = new class_13(new int[]{0, 0, 0});
                  var9.field_1107 = var12;
                  ((class_85)var9).field_1147 = true;
                  var9.field_1102.method_806(32000);
                  var9.method_742(true);
                  var9.field_1101 = 1;
                  var9.method_743(6);
                  class_83[] var15 = this.field_860.field_776;

                  for (int var7 = 0; var7 < var15.length; var7++) {
                     var15[var7].method_744(null);
                     var15[var7].field_1107 = var12.method_224();
                     var15[var7].field_1102.method_828();
                  }

                  var2.method_614(false);
                  this.field_865.field_1031 = var9.field_1103;
                  this.field_865.field_1039 = true;
                  this.field_865.method_689(this.field_860.field_774.field_203.method_853(), 2);
                  this.field_868.field_140 -= 4000;
                  class_41.field_527.field_249.method_842(this.field_868);
                  this.field_862 = true;
                  this.field_873 = true;
               } else if (this.field_860.field_782[10].field_419 && this.field_861 == 2) {
                  this.field_868.method_170(0, 4096, 0);
                  this.field_865.method_689(this.field_868, 2);
                  class_41.field_527.field_249.method_841(15000, 8000, 28000);
                  Object var8 = null;
                  this.field_865.field_1031 = ((class_92)this.field_860.field_778[0]).method_780();
                  this.field_861 = 3;
               } else {
                  class_83 var4;
                  if (this.field_861 == 2 && (var4 = this.field_860.field_775[this.field_860.field_775.length - 1]).field_1107.method_220().field_1164) {
                     var4.field_1103.method_841(0, 0, 0);
                     var4.method_742(false);
                     var4.method_750();
                     var4.field_1102.method_806(0);
                     class_13 var5;
                     (var5 = new class_13(new int[]{40000, 0, 0, 36000, -3000, 4000})).field_183 = true;

                     for (int var6 = 0; var6 < this.field_860.field_776.length; var6++) {
                        this.field_860.field_776[var6].field_1107 = var5.method_224();
                     }

                     class_13 var14;
                     (var14 = new class_13(new int[]{42000, -2000, 3000, 30000, -1000, -5000})).field_183 = true;
                     this.field_860.field_774.field_215 = var14;
                     this.field_860.field_774.method_248(var14.method_220());
                  }
               }

               if (this.field_861 == 3) {
                  this.field_872 += var1 / 4;
                  ((class_92)this.field_860.field_778[0]).method_781(0, var1 * 2 + this.field_872, 0);
                  if (this.field_860.field_782[12].field_420) {
                     this.field_861 = 4;
                     this.field_865.field_1039 = true;
                     this.field_860.field_774.method_251(44000, -5000, 1000);
                     this.field_868.method_170(0, 4096, 0);
                     this.field_865.method_689(this.field_868, 2);
                     this.field_865.field_1031 = this.field_860.field_774.field_203;
                     this.field_865.field_1034 = class_41.field_527.field_249;
                     class_41.field_527.field_249.method_841(33000, -4000, 2000);
                  }
               }

               if (this.field_861 == 4 && this.field_860.field_782[15].field_420) {
                  this.field_861 = 5;
                  this.field_868 = this.field_860.field_776[0].method_746(this.field_868);
                  this.field_868.field_138 += 5000;
                  this.field_868.field_139 -= 2000;
                  class_41.field_527.field_249.method_842(this.field_868);
                  this.field_865.field_1031 = this.field_860.field_776[0].field_1103;
               }

               if (this.field_861 == 5 && this.field_860.field_782[17].field_420) {
                  this.field_861 = 6;
                  this.field_868 = this.field_860.field_776[1].method_746(this.field_868);
                  this.field_868.field_138 -= 5000;
                  this.field_868.field_139 += 2000;
                  class_41.field_527.field_249.method_842(this.field_868);
                  this.field_865.field_1031 = this.field_860.field_776[1].field_1103;
               }

               if (this.field_861 == 6 && this.field_860.field_782[19].field_420) {
                  this.field_861 = 7;
                  this.field_868 = this.field_860.field_776[1].method_746(this.field_868);
                  this.field_868.field_140 += 8000;
                  this.field_868.field_139 += 1000;
                  class_41.field_527.field_249.method_842(this.field_868);
                  this.field_865.field_1031 = this.field_860.field_776[1].field_1103;
               }

               if (this.field_861 == 7 && this.field_860.field_782[24].field_420) {
                  this.field_861 = 8;
                  this.field_865.field_1039 = false;
                  var2.method_614(true);
                  this.field_866 = 0;
                  class_4.method_156();
                  this.field_860.field_774.method_251(44000, -5000, 1000);
               }

               if (this.field_861 == 8) {
                  class_4.method_157(1);
                  if (class_4.method_158()) {
                     this.field_861 = 9;
                  }
               }

               if (this.field_861 == 9) {
                  class_3.method_63(class_95.field_1225);
                  class_3.method_75();
                  this.field_860.field_775[this.field_860.field_775.length - 1].method_749();
                  this.field_860.field_774.method_248(null);
                  this.field_860.field_774.field_215 = null;
                  this.field_860.method_559();
                  this.field_860.field_779 = null;
                  new class_33(this.field_860);
                  this.field_862 = false;
                  this.field_861 = 10;
                  this.field_873 = false;
               }
         }
      }

      return this.field_862;
   }

   // $VF: renamed from: a () void
   public final void method_603() {
      if (class_3.method_73() > 1) {
         this.field_866 = 7001;
      }

      class_69.method_654(class_3.method_108().field_443);
   }

   // $VF: renamed from: b () void
   public final void method_604() {
      this.field_864 = false;
      this.field_866 = 0;
      this.field_867 = true;
   }

   // $VF: renamed from: a (ce, cy) void
   public static final void method_605(class_65 var0, class_57 var1) {
      var0.method_609(var1.field_774.field_203);
      var0.method_616(new class_5(0, 850, 0));
      var0.method_617(new class_5(0, 1050, -4000));
      var0.method_613();
   }

   // $VF: renamed from: a (ce) void
   public static final void method_606(class_65 var0) {
      var0.method_616(new class_5(0, 300, 0));
      var0.method_617(new class_5(0, 300, 5600));
   }

   // $VF: renamed from: b (ce) void
   public static final void method_607(class_65 var0) {
      var0.method_616(new class_5(0, 500, 0));
      var0.method_617(new class_5(6000, 500, 0));
   }

   // $VF: renamed from: c (ce) void
   public static final void method_608(class_65 var0) {
      var0.method_616(new class_5(0, 500, 0));
      var0.method_617(new class_5(-6000, 500, 0));
   }
}
