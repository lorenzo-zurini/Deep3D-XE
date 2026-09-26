import javax.microedition.lcdui.Image;

// $VF: renamed from: cb
public final class class_46 {
   // $VF: renamed from: e int
   private static int field_477;
   // $VF: renamed from: f int
   private static int field_478;
   // $VF: renamed from: g int
   private static int field_479;
   // $VF: renamed from: h int
   private static int field_480;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_481;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_482;
   // $VF: renamed from: c javax.microedition.lcdui.Image
   private Image field_483;
   // $VF: renamed from: d javax.microedition.lcdui.Image
   private Image field_484;
   // $VF: renamed from: e javax.microedition.lcdui.Image
   private Image field_485;
   // $VF: renamed from: f javax.microedition.lcdui.Image
   private Image field_486;
   // $VF: renamed from: g javax.microedition.lcdui.Image
   private Image field_487;
   // $VF: renamed from: h javax.microedition.lcdui.Image
   private Image field_488;
   // $VF: renamed from: i javax.microedition.lcdui.Image
   private Image field_489;
   // $VF: renamed from: j javax.microedition.lcdui.Image
   private Image field_490;
   // $VF: renamed from: k javax.microedition.lcdui.Image
   private Image field_491;
   // $VF: renamed from: l javax.microedition.lcdui.Image
   private Image field_492;
   // $VF: renamed from: m javax.microedition.lcdui.Image
   private Image field_493;
   // $VF: renamed from: n javax.microedition.lcdui.Image
   private Image field_494;
   // $VF: renamed from: o javax.microedition.lcdui.Image
   private Image field_495;
   // $VF: renamed from: p javax.microedition.lcdui.Image
   private Image field_496;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_497;
   // $VF: renamed from: b javax.microedition.lcdui.Image[]
   private Image[] field_498;
   // $VF: renamed from: q javax.microedition.lcdui.Image
   private Image field_499;
   // $VF: renamed from: a int
   public int field_500;
   // $VF: renamed from: b int
   public int field_501;
   // $VF: renamed from: c int
   public int field_502;
   // $VF: renamed from: d int
   public int field_503;
   // $VF: renamed from: a boolean
   public boolean field_504;
   // $VF: renamed from: b boolean
   public boolean field_505;
   // $VF: renamed from: c boolean
   public boolean field_506;
   // $VF: renamed from: d boolean
   public boolean field_507;
   // $VF: renamed from: e boolean
   public boolean field_508;
   // $VF: renamed from: a aw[]
   public class_91[] field_509;
   // $VF: renamed from: b aw[]
   public class_91[] field_510;
   // $VF: renamed from: c aw[]
   public class_91[] field_511;
   // $VF: renamed from: d aw[]
   public class_91[] field_512;
   // $VF: renamed from: a dr
   public class_18 field_513;
   // $VF: renamed from: a cz
   public class_26 field_514;
   // $VF: renamed from: a bn
   private class_57 field_515 = new class_57();
   // $VF: renamed from: a x
   private class_3 field_516 = new class_3();
   // $VF: renamed from: b x
   private class_3 field_517 = new class_3();
   // $VF: renamed from: c x
   private class_3 field_518 = new class_3();
   // $VF: renamed from: d x
   private class_3 field_519 = new class_3();
   // $VF: renamed from: a o
   private class_8 field_520 = new class_8();
   // $VF: renamed from: i int
   private int field_521;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_522 = new String[3];
   // $VF: renamed from: j int
   private int field_523;
   // $VF: renamed from: a java.lang.String
   private String field_524;
   // $VF: renamed from: r javax.microedition.lcdui.Image
   private Image field_525;
   // $VF: renamed from: s javax.microedition.lcdui.Image
   private Image field_526;

   public class_46(class_26 var1) {
      this.field_514 = var1;
      this.field_502 = class_84.field_1120 / 2;
      this.field_503 = class_84.field_1121 / 2;
      field_477 = class_84.field_1120 / 3;
      field_478 = class_84.field_1120 - field_477;
      field_479 = class_84.field_1121 / 2 - (class_84.field_1120 / 2 - field_477);
      field_480 = class_84.field_1121 / 2 + (class_84.field_1120 / 2 - field_477);
      this.field_522[0] = class_21.method_180().field_1133;
      this.field_522[1] = "S.T.R.E.A.M. OUT";
      this.field_522[2] = "";

      try {
         this.field_481 = class_28.method_282("/data/interface/bracket_enemy_in.png");
         this.field_482 = class_28.method_282("/data/interface/bracket_enemy_out.png");
         this.field_483 = class_28.method_282("/data/interface/bracket_friend_in.png");
         this.field_484 = class_28.method_282("/data/interface/bracket_friend_out.png");
         this.field_485 = class_28.method_282("/data/interface/bracket_waypoint_in.png");
         this.field_486 = class_28.method_282("/data/interface/bracket_waypoint_out.png");
         this.field_490 = class_28.method_282("/data/interface/bracket_landmark_out.png");
         this.field_489 = class_28.method_282("/data/interface/bracket_landmark_in.png");
         this.field_492 = class_28.method_282("/data/interface/bracket_creature_out.png");
         this.field_491 = class_28.method_282("/data/interface/bracket_creature_in.png");
         this.field_487 = class_28.method_282("/data/interface/bracket_enemy_far.png");
         this.field_488 = class_28.method_282("/data/interface/bracket_friend_far.png");
         this.field_495 = class_28.method_282("/data/interface/bracket_box.png");
         this.field_496 = class_28.method_282("/data/interface/crate.png");
         this.field_499 = class_28.method_282("/data/interface/cargo_18.png");
         this.field_493 = class_28.method_282("/data/interface/radar_logo_0.png");
         this.field_494 = class_28.method_282("/data/interface/radar_logo_1.png");
         String var2 = class_14.method_70() ? "go" : (class_21.method_178().field_884 ? "g" : "b");
         this.field_525 = class_28.method_282("/data/interface/c_" + var2 + "_s.png");
         this.field_526 = class_28.method_282("/data/interface/c_" + var2 + "_f.png");
         this.field_523 = class_21.method_178().field_876;
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_388() {
      this.field_509 = null;
      this.field_510 = null;
      this.field_511 = null;
      this.field_513 = null;
      this.field_514 = null;
      this.field_518 = null;
      this.field_519 = null;
      this.field_516 = null;
   }

   // $VF: renamed from: a (an, aw) void
   public final void method_389(class_106 var1, class_91 var2) {
      this.field_517 = var2.method_799(this.field_517);
      this.field_516 = var1.method_871(this.field_515).method_507(this.field_517, this.field_516);
      this.field_516.field_38 = -this.field_516.field_38;
      this.field_516.field_39 = -this.field_516.field_39;
      var1.method_883(this.field_517);
      this.field_500 = this.field_517.field_37;
      this.field_501 = this.field_517.field_38;
      float var3 = this.field_500 > class_84.field_1120
         ? (float)(this.field_503 - this.field_501) / (this.field_500 - this.field_502)
         : (float)(this.field_503 - this.field_501) / (this.field_502 - this.field_500);
      float var4 = this.field_501 > class_84.field_1121
         ? (float)(this.field_502 - this.field_500) / (this.field_501 - this.field_503)
         : (float)(this.field_502 - this.field_500) / (this.field_503 - this.field_501);
      if (this.field_516.field_39 < 0) {
         if (this.field_500 < this.field_502) {
            this.field_500 = -1;
         } else {
            this.field_500 = class_84.field_1120 + 1;
         }

         if (this.field_501 < this.field_503) {
            this.field_501 = -1;
         } else {
            this.field_501 = class_84.field_1121 + 1;
         }
      }

      this.field_504 = this.field_500 <= class_84.field_1120 && this.field_500 >= 0 && this.field_501 <= class_84.field_1121 && this.field_501 >= 0;
      this.field_505 = this.field_506 = this.field_507 = this.field_508 = false;
      if (this.field_500 > class_84.field_1120) {
         this.field_500 = class_84.field_1120 - 14;
         this.field_501 = this.field_503 - (int)(var3 * (this.field_500 - this.field_502));
         this.field_506 = true;
      } else if (this.field_500 < 0) {
         this.field_500 = 14;
         this.field_501 = this.field_503 + (int)(var3 * (this.field_500 - this.field_502));
         this.field_505 = true;
      }

      if (this.field_501 > class_84.field_1121) {
         this.field_501 = 33 + class_69.field_894;
         this.field_500 = this.field_502 - (int)(var4 * (this.field_501 - this.field_503));
         this.field_508 = true;
      } else if (this.field_501 < 0) {
         this.field_501 = 33;
         this.field_500 = this.field_502 + (int)(var4 * (this.field_501 - this.field_503));
         this.field_507 = true;
      }

      if (this.field_500 > 14 + class_69.field_893) {
         this.field_500 = 14 + class_69.field_893;
      } else if (this.field_500 < 14) {
         this.field_500 = 14;
      }

      if (this.field_501 > 33 + class_69.field_894) {
         this.field_501 = 33 + class_69.field_894;
      } else {
         if (this.field_501 < 33) {
            this.field_501 = 33;
         }
      }
   }

   // $VF: renamed from: a (cm, an) void
   public final void method_390(class_37 var1, class_106 var2) {
      this.field_509 = this.field_514.field_273;
      this.field_510 = this.field_514.field_274;
      this.field_511 = this.field_514.field_276;
      this.field_513 = this.field_514.field_277;
      this.field_512 = this.field_514.field_275;
      boolean var3 = false;
      if ((this.field_523 == 2 || this.field_523 == 4) && this.field_497 == null && this.field_509 != null) {
         this.field_497 = new Image[this.field_509.length];

         for (int var4 = 0; var4 < this.field_509.length; var4++) {
            if (this.field_509[var4].field_1239) {
               class_120 var5 = this.field_509[var4].field_1240;
               if (this.field_509[var4].field_1240 != null) {
                  this.field_497[var4] = class_28.method_282("/data/interface/cargo_" + this.field_509[var4].field_1240.field_1480 + ".png");
               } else if (class_21.method_132().field_1146 == 2) {
                  this.field_497[var4] = class_28.method_282("/data/interface/cargo_salvage.png");
               } else {
                  this.field_497[var4] = class_28.method_282("/data/interface/cargo_recovery.png");
               }
            }
         }
      }

      if ((this.field_523 == 3 || this.field_523 == 4) && this.field_498 == null && this.field_512 != null) {
         this.field_498 = new Image[this.field_512.length];

         for (int var9 = 0; var9 < this.field_512.length; var9++) {
            this.field_498[var9] = class_28.method_282("/data/interface/cargo_" + ((class_101)this.field_512[var9]).field_1312.field_391 + ".png");
         }
      }

      if (this.field_523 > 0) {
         class_84.field_1117.setColor(class_67.field_845);
         class_84.field_1117.drawLine(14, 33, 14, 45);
         class_84.field_1117.drawLine(14, 33, 26, 33);
         class_84.field_1117.drawLine(14, 33 + class_69.field_894, 26, 33 + class_69.field_894);
         class_84.field_1117.drawLine(14, 33 + class_69.field_894, 14, 33 + class_69.field_894 - 12);
         class_84.field_1117.drawLine(14 + class_69.field_893, 33, 14 + class_69.field_893 - 12, 33);
         class_84.field_1117.drawLine(14 + class_69.field_893, 33, 14 + class_69.field_893, 45);
         class_84.field_1117.drawLine(14 + class_69.field_893, 33 + class_69.field_894, 14 + class_69.field_893 - 12, 33 + class_69.field_894);
         class_84.field_1117.drawLine(14 + class_69.field_893, 33 + class_69.field_894, 14 + class_69.field_893, 33 + class_69.field_894 - 12);
         class_84.field_1117.setColor(class_67.field_844);

         for (int var10 = 0; var10 < 2; var10++) {
            int var14;
            if ((var14 = var10 == 0 ? class_14.method_74() : class_14.method_79()) != 0) {
               class_84.field_1117.drawImage(var10 == 0 ? this.field_525 : this.field_526, var10 == 0 ? 16 : 14 + class_69.field_893 - 3 - 40, 35, 0);
               int var6 = var10 == 0 ? 28 : 14 + class_69.field_893 - 30;
               int var7 = 36;

               for (int var8 = 0; var8 < var14; var8++) {
                  if ((var8 + 1) % 5 == 0) {
                     class_84.field_1117.drawLine(var6 - 9, var7 + 5, var6 - 1, var7);
                  } else {
                     class_84.field_1117.drawLine(var6, var7, var6, var7 + 5);
                  }

                  var6 += 2;
                  if (var6 > (var10 == 0 ? 56 : 14 + class_69.field_893 - 2)) {
                     var6 = var10 == 0 ? 18 : 14 + class_69.field_893 - 40;
                     var7 += 8;
                  }
               }
            }
         }

         if (this.field_510 != null) {
            for (int var11 = 0; var11 < this.field_510.length; var11++) {
               if (this.field_510[var11].field_1225.field_375 && !this.field_510[var11].method_801()) {
                  this.method_389(var2, this.field_510[var11]);
                  if (this.field_504) {
                     this.field_518 = var1.method_344(this.field_518);
                     this.field_519 = this.field_510[var11].field_1225.method_344(this.field_519);
                     if (this.field_518.field_37 - this.field_519.field_37 <= 24000
                        && this.field_518.field_37 - this.field_519.field_37 >= -24000
                        && this.field_518.field_38 - this.field_519.field_38 <= 24000
                        && this.field_518.field_38 - this.field_519.field_38 >= -24000
                        && this.field_518.field_39 - this.field_519.field_39 <= 24000
                        && this.field_518.field_39 - this.field_519.field_39 >= -24000) {
                        class_84.field_1117.drawImage(this.field_483, this.field_500, this.field_501, 3);
                        this.field_521 = (int)(this.field_510[var11].field_1225.field_370 / 100.0F * 16.0F);
                        class_84.field_1117.setColor(-13319376);
                        class_84.field_1117.fillRect(this.field_500 + 10, this.field_501 + 10 - 2 - this.field_521, 2, this.field_521);
                     } else {
                        class_84.field_1117.drawImage(this.field_488, this.field_500, this.field_501, 3);
                     }
                  } else {
                     class_84.field_1117.drawImage(this.field_484, this.field_500, this.field_501, 3);
                  }
               }
            }
         }
      }

      if (this.field_511 != null) {
         for (int var12 = 0; var12 < this.field_511.length; var12++) {
            if (this.field_511[var12] != null) {
               this.method_389(var2, this.field_511[var12]);
               if (this.field_504) {
                  this.field_518 = var1.method_344(this.field_518);
                  this.field_519 = this.field_511[var12].field_1225.method_344(this.field_519);
                  class_84.field_1117.drawImage(this.field_489, this.field_500, this.field_501, 3);
                  if (var12 == 0) {
                     class_84.field_1117
                        .drawImage(class_21.method_180().method_752() ? this.field_494 : this.field_493, this.field_500 + 5, this.field_501 + 2, 0);
                  }

                  class_58.method_518(this.field_522[var12], var12 == 0 ? this.field_500 + 25 : this.field_500 + 5, this.field_501, 0);
                  if (var12 < 2) {
                     this.field_524 = this.method_391(
                        this.field_511[var12].field_1234, this.field_511[var12].field_1235, this.field_511[var12].field_1236, var1
                     );
                     class_58.method_518(this.field_524, var12 == 0 ? this.field_500 + 25 : this.field_500 + 5, this.field_501 + 10, 1);
                  }
               }
            }
         }
      }

      if (this.field_513 != null && this.field_513.method_110() != null) {
         this.method_389(var2, this.field_513.method_110());
         this.field_524 = this.method_391(
            this.field_513.method_110().field_1295, this.field_513.method_110().field_1296, this.field_513.method_110().field_1297, var1
         );
         if (this.field_504) {
            class_84.field_1117.drawImage(this.field_485, this.field_500, this.field_501, 3);
            class_58.method_518(this.field_524, this.field_500 - 10, this.field_501 + 10, 1);
         } else if (this.field_523 > 0) {
            class_84.field_1117.drawImage(this.field_486, this.field_500, this.field_501, 3);
         }
      }

      boolean var13 = class_21.method_132().field_1146 == 6;
      if (this.field_512 != null) {
         for (int var15 = 0; var15 < this.field_512.length; var15++) {
            if (!((class_101)this.field_512[var15]).field_1326 && (!this.field_512[var15].method_800() || ((class_101)this.field_512[var15]).field_1333)) {
               this.method_389(var2, this.field_512[var15]);
               if (this.field_504) {
                  this.field_518 = var1.method_344(this.field_518);
                  this.field_519 = this.field_512[var15].field_1225.method_344(this.field_519);
                  if (var13) {
                     class_84.field_1117.drawImage(this.field_491, this.field_500, this.field_501, 3);
                  }

                  if ((this.field_523 == 3 || this.field_523 == 4)
                     && this.field_498[var15] != null
                     && this.field_500 > field_477
                     && this.field_500 < field_478
                     && this.field_501 > field_479
                     && this.field_501 < field_480) {
                     class_84.field_1117
                        .drawImage(
                           ((class_101)this.field_512[var15]).field_1333 ? this.field_499 : this.field_498[var15], this.field_500 - 20, this.field_501 + 10, 0
                        );
                     class_58.method_518(((class_101)this.field_512[var15]).field_1332 + "t", this.field_500 - 20 + 20, this.field_501 + 10 + 3, 0);
                  }
               } else if (this.field_523 > 0 && var13) {
                  class_84.field_1117.drawImage(this.field_492, this.field_500, this.field_501, 3);
               }
            }
         }
      }

      if (this.field_523 > 0 && this.field_509 != null) {
         for (int var16 = 0; var16 < this.field_509.length; var16++) {
            class_91 var17;
            if ((var17 = this.field_509[var16]).field_1225.field_375 && (!var17.method_801() || var17.field_1239)) {
               this.method_389(var2, var17);
               boolean var18 = var17.field_1239 && (var17.method_800() || var17.method_801());
               if (this.field_504) {
                  this.field_518 = var1.method_344(this.field_518);
                  this.field_519 = var17.field_1225.method_344(this.field_519);
                  if (this.field_518.field_37 - this.field_519.field_37 <= 24000
                     && this.field_518.field_37 - this.field_519.field_37 >= -24000
                     && this.field_518.field_38 - this.field_519.field_38 <= 24000
                     && this.field_518.field_38 - this.field_519.field_38 >= -24000
                     && this.field_518.field_39 - this.field_519.field_39 <= 24000
                     && this.field_518.field_39 - this.field_519.field_39 >= -24000
                     && var17.field_1227 != 13
                     && var17.field_1227 != 9996) {
                     class_84.field_1117.drawImage(var18 ? this.field_495 : this.field_481, this.field_500, this.field_501, 3);
                     this.field_521 = (int)(var17.field_1225.field_370 / 100.0F * 16.0F);
                     class_84.field_1117.setColor(-1047803);
                     class_84.field_1117.fillRect(this.field_500 + 10, this.field_501 + 10 - 2 - this.field_521, 2, this.field_521);
                     if ((this.field_523 == 2 || this.field_523 == 4)
                        && this.field_497[var16] != null
                        && this.field_500 > field_477
                        && this.field_500 < field_478
                        && this.field_501 > field_479
                        && this.field_501 < field_480) {
                        class_84.field_1117.drawImage(this.field_497[var16], this.field_500 - 20, this.field_501 + 10, 0);
                     }
                  } else {
                     class_84.field_1117.drawImage(var18 ? this.field_495 : this.field_487, this.field_500, this.field_501, 3);
                  }
               } else {
                  class_84.field_1117.drawImage(this.field_482, this.field_500, this.field_501, 3);
                  if (var18) {
                     class_84.field_1117.drawImage(this.field_490, this.field_500, this.field_501, 3);
                     class_84.field_1117
                        .drawImage(
                           this.field_496,
                           this.field_505 && !this.field_507 && !this.field_508
                              ? this.field_500 + 11
                              : (this.field_506 && !this.field_507 && !this.field_508 ? this.field_500 - 11 : this.field_500),
                           this.field_507 ? this.field_501 + 11 : (this.field_508 ? this.field_501 - 11 : this.field_501),
                           3
                        );
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: a (int, int, int, cm) java.lang.String
   private String method_391(int var1, int var2, int var3, class_37 var4) {
      this.field_518 = var4.method_344(this.field_518);
      this.field_520.field_72 = this.field_518.field_37 >> 1;
      this.field_520.field_73 = this.field_518.field_38 >> 1;
      this.field_520.field_74 = this.field_518.field_39 >> 1;
      int var5 = var1 >> 1;
      int var6 = var2 >> 1;
      int var7 = var3 >> 1;
      int var8 = (int)method_392(
            (
                  (this.field_520.field_72 - var5) * (this.field_520.field_72 - var5)
                     + (this.field_520.field_73 - var6) * (this.field_520.field_73 - var6)
                     + (this.field_520.field_74 - var7) * (this.field_520.field_74 - var7)
               )
               / 4096.0F
         )
         * 12;
      String var9 = var8 + "m";
      if (var8 >= 1000) {
         int var10;
         if ((var10 = var8 % 1000) >= 100) {
            var9 = "" + var10;
         } else {
            var9 = "0";
         }

         var9 = var9.substring(0, 1);
         var9 = var8 / 1000 + "." + var9 + "km";
      }

      return var9;
   }

   // $VF: renamed from: a (float) float
   public static final float method_392(float var0) {
      float var1 = 65536.0F;
      float var2 = 65536.0F;

      for (int var4 = 0; var4 < 20; var4++) {
         var1 *= 0.5F;
         float var3;
         if ((var3 = var0 - var2 * var2) > 0.0F) {
            var2 += var1;
         } else if (var3 < 0.0F) {
            var2 -= var1;
         }
      }

      return var2;
   }
}
