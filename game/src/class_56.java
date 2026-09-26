import javax.microedition.lcdui.Image;

// $VF: renamed from: k
public final class class_56 {
   // $VF: renamed from: a bi
   private class_2 field_751;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_752;
   // $VF: renamed from: a java.lang.String
   private String field_753;
   // $VF: renamed from: b java.lang.String
   private String field_754;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_755;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_756;
   // $VF: renamed from: a dc
   private class_18 field_757;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_758;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_759;
   // $VF: renamed from: a boolean
   private boolean field_760;
   // $VF: renamed from: a boolean[]
   private boolean[] field_761;
   // $VF: renamed from: a int
   private int field_762;
   // $VF: renamed from: b int
   private int field_763;

   // $VF: renamed from: a (bi, boolean) void
   public final void method_525(class_2 var1, boolean var2) {
      this.field_751 = var1;
      if (var1.method_47()) {
         this.field_763 = 31;
         this.field_754 = class_41.field_533.method_297(class_22.field_320[var1.method_56()][0]);
         this.field_753 = class_41.field_533.method_297(class_22.field_320[var1.method_56()][1]);
         int var3 = var1.field_22.field_710;
         switch (var1.field_22.field_710) {
            case 0:
            case 1:
               this.field_755 = new String[]{
                  class_41.field_533.method_297(48), class_41.field_533.method_297(49), class_41.field_533.method_297(52), class_41.field_533.method_297(56)
               };
               break;
            case 2:
               this.field_755 = new String[]{
                  class_41.field_533.method_297(54), class_41.field_533.method_297(55), class_41.field_533.method_297(49), class_41.field_533.method_297(56)
               };
               break;
            case 3:
               this.field_755 = new String[]{class_41.field_533.method_297(50), class_41.field_533.method_297(51), class_41.field_533.method_297(245)};
               break;
            case 4:
               this.field_755 = new String[]{class_41.field_533.method_297(50), class_41.field_533.method_297(245)};
               break;
            case 5:
               this.field_755 = new String[]{class_41.field_533.method_297(57)};
               break;
            case 6:
            case 7:
               this.field_755 = new String[]{class_41.field_533.method_297(57)};
               break;
            case 8:
            case 10:
               this.field_755 = null;
               this.field_756 = null;
               break;
            case 9:
               this.field_755 = new String[]{class_41.field_533.method_297(56), class_41.field_533.method_297(53), class_41.field_533.method_297(51)};
         }

         if (this.field_755 != null) {
            this.field_756 = new String[this.field_755.length];

            for (int var4 = 0; var4 < this.field_756.length; var4++) {
               this.field_756[var4] = "" + var1.field_22.method_502(var4);
               if (this.field_755[var4] == class_41.field_533.method_297(49)
                  || this.field_755[var4] == class_41.field_533.method_297(51)
                  || this.field_755[var4] == class_41.field_533.method_297(53)) {
                  this.field_756[var4] = this.field_756[var4] + " ms";
               } else if (this.field_755[var4] == class_41.field_533.method_297(54) || this.field_755[var4] == class_41.field_533.method_297(245)) {
                  this.field_756[var4] = this.field_756[var4] + " m";
               } else if (this.field_755[var4] == class_41.field_533.method_297(52)) {
                  int var5;
                  int var6 = (var5 = Integer.parseInt(this.field_756[var4]) / 3) % 10;
                  var5 = (var5 + var6) % 10 == 0 ? var5 + var6 : var5 - var6;
                  this.field_756[var4] = var5 + " m";
               } else if (this.field_755[var4] == class_41.field_533.method_297(57) || this.field_755[var4] == class_41.field_533.method_297(55)) {
                  this.field_756[var4] = "+" + this.field_756[var4] + "%";
               }

               if (this.field_755[var4] == class_41.field_533.method_297(51) && var1.field_22.method_502(var4) == 0) {
                  this.field_756[var4] = "-";
               }
            }
         }
      } else if (var1.method_46()) {
         int var8 = var1.field_21.field_431 + var1.field_21.field_430;
         int var14 = var1.field_21.field_433;
         int var21 = (int)(var1.field_21.field_439 / 100.0F * var1.field_21.field_429 * 100.0F);
         this.field_763 = 31;
         this.field_754 = class_41.field_533.method_297(class_22.field_322[var1.method_56()][0]);
         this.field_753 = class_41.field_533.method_297(class_22.field_322[var1.method_56()][1]);
         this.field_755 = new String[]{
            class_41.field_533.method_297(59), class_41.field_533.method_297(60), class_41.field_533.method_297(329), class_41.field_533.method_297(58)
         };
         this.field_756 = new String[]{
            var1.field_21.field_423 + (var8 > 0 ? "+" + var8 : ""),
            var1.field_21.field_425 + (var14 > 0 ? "t+" + var14 + "t" : ""),
            "" + var1.field_21.field_428,
            "" + (int)(var1.field_21.field_429 * 100.0F) + (var21 > 0 ? "+" + var21 : "")
         };
      } else if (var1.method_48()) {
         this.field_763 = 18;
         this.field_753 = "";
         this.field_760 = var1.field_23.field_636 > 0;
         this.field_759 = class_40.method_412("/data/interface/x_1.png");
         this.field_754 = class_41.field_533.method_297(class_22.field_321[var1.field_23.field_626][0]);
         if (var1.field_23.field_634 != null) {
            this.field_753 = class_41.field_533.method_297(330) + ":\n\n";

            for (int var9 = 0; var9 < var1.field_23.field_634.length; var9++) {
               this.field_753 = this.field_753
                  + var1.field_23.field_635[var9]
                  + "t "
                  + class_41.field_533.method_297(class_22.field_321[class_24.method_315()[var1.field_23.field_634[var9]].field_626][0])
                  + "\n";
            }

            this.field_753 = this.field_753 + "\n";
         }

         this.field_753 = this.field_753 + class_41.field_533.method_297(class_22.field_321[var1.field_23.field_626][1]);
         this.field_755 = new String[]{class_41.field_533.method_297(42)};
         this.field_756 = new String[]{""};
         if (var1.field_23.field_634 != null) {
            this.field_758 = new Image[var1.field_23.field_634.length];
            this.field_761 = new boolean[this.field_758.length];

            for (int var10 = 0; var10 < this.field_758.length; var10++) {
               this.field_758[var10] = class_40.method_412("/data/interface/cargo_" + var1.field_23.field_634[var10] + ".png");
               this.field_761[var10] = class_46.method_450(var1.field_23.field_634[var10], class_3.method_108().field_445);
            }
         } else {
            this.field_758 = null;
         }
      } else if (var1.method_50()) {
         this.field_763 = 18;
         this.field_754 = var1.field_24.method_792();
         this.field_753 = class_3.method_149(
            var1.field_24.method_793(), var1.field_24.field_1226 == 6 ? "" + var1.field_24.field_1249 : var1.field_24.field_1233
         );
         if (var1.field_24.field_1226 == 16) {
            this.field_753 = this.field_753 + " " + class_3.method_132() + " / " + var1.field_24.field_1250;
         } else if (var1.field_24.field_1226 == 18) {
            this.field_753 = this.field_753 + " " + class_3.method_107() + " / " + var1.field_24.field_1250;
         } else if (var1.field_24.field_1226 == 21) {
            this.field_753 = this.field_753 + " " + class_3.method_121() + " / " + var1.field_24.field_1250;
         } else if (var1.field_24.field_1226 == 15) {
            this.field_753 = this.field_753 + " " + class_3.method_139() + " / " + var1.field_24.field_1250;
         }

         String var11 = var1.field_24.field_1235 < 0 ? class_41.field_533.method_297(335) : "" + var1.field_24.field_1235;
         if (var1.field_24 == class_3.method_65() && var1.field_24.field_1235 > 0) {
            var11 = var1.field_24.field_1236 + 1 + "/" + var1.field_24.field_1235;
         }

         String var15 = var1.field_24.field_1230 - var1.field_24.field_1231 + " $";
         if (var1.field_24.field_1241) {
            this.field_755 = null;
            this.field_756 = null;
         } else if (var1.field_24.field_1226 == 14 || var1.field_24.field_1226 == 13) {
            this.field_755 = new String[]{class_41.field_533.method_297(332)};
            this.field_756 = new String[]{var15};
         } else if (var1.field_24.field_1226 == 8) {
            this.field_755 = new String[]{
               class_41.field_533.method_297(334),
               class_41.field_533.method_297(245),
               class_41.field_533.method_297(333),
               class_41.field_533.method_297(331),
               class_41.field_533.method_297(332)
            };
            this.field_756 = new String[]{
               var1.field_24.field_1233,
               var1.field_24.field_1240 + " m",
               var1.field_24.field_1238 == 0 ? class_41.field_533.method_297(310) : var1.field_24.field_1238 + " km",
               var11,
               var15
            };
         } else {
            int var22 = var1.field_24.method_799();
            String var23 = class_41.field_533.method_297(var22 < 4 ? 273 : (var22 < 8 ? 274 : 275));
            this.field_755 = new String[]{
               class_41.field_533.method_297(334),
               class_41.field_533.method_297(245),
               class_41.field_533.method_297(333),
               class_41.field_533.method_297(39),
               class_41.field_533.method_297(332)
            };
            this.field_756 = new String[]{
               var1.field_24.field_1233,
               var1.field_24.field_1240 + " m",
               var1.field_24.field_1238 == 0 ? class_41.field_533.method_297(310) : var1.field_24.field_1238 + " km",
               var23,
               var15
            };
         }

         class_119.method_926(var1.field_24.field_1228);
      }

      if (!var1.method_50() && !var1.method_48()) {
         String[] var12;
         String[] var16;
         if (this.field_756 == null) {
            var12 = new String[1];
            var16 = new String[1];
         } else {
            var12 = new String[this.field_755.length + 1];
            var16 = new String[this.field_756.length + 1];
            System.arraycopy(this.field_755, 0, var12, 0, this.field_755.length);
            System.arraycopy(this.field_756, 0, var16, 0, this.field_756.length);
         }

         var12[var12.length - 1] = class_41.field_533.method_297(42);
         var16[var16.length - 1] = var1.method_55() + " $";
         this.field_756 = var16;
         this.field_755 = var12;
      }

      this.field_762 = class_41.field_538 - 10 - (this.field_756 == null ? 0 : this.field_756.length * 10 + 6);
      int var13 = var1.method_48() && this.field_758 != null ? 22 : 0;
      this.field_757 = new class_18(5, 34 + var13, class_41.field_537 - 10, this.field_762 - 2 - 12 - 22 - var13, this.field_753);
      if (var1.method_50() && !var1.field_24.field_1241) {
         this.field_757.method_273(var1.field_24.field_1228, class_41.field_533.method_297(142) + ":\n" + var1.field_24.field_1227, true);
      }

      try {
         if (var1.method_46()) {
            boolean var17 = var1.field_21.field_443;
            this.field_752 = class_40.method_412("/data/interface/equipment/u" + var1.method_56() + (var17 ? "b" : "a") + ".png");
         } else if (var1.method_47()) {
            this.field_752 = class_40.method_412("/data/interface/equipment/slot_" + var1.method_56() + ".png");
         } else if (var1.method_50()) {
            if (var1.field_24.field_1241) {
               this.field_752 = class_40.method_412("/data/interface/mission_story.png");
            } else {
               this.field_752 = class_40.method_412("/data/interface/mission_" + var1.field_24.field_1226 + ".png");
               if (var1.field_24.field_1226 == 13 || var1.field_24.field_1226 == 14) {
                  Image var19 = class_40.method_412("/data/interface/cargo_" + var1.field_24.field_1244 + ".png");
                  this.field_757.method_275(var19, var1.field_24.field_1245, var1.field_24.field_1244);
               } else if (var1.field_24.field_1226 == 7 || var1.field_24.field_1226 == 6) {
                  Image var18 = class_40.method_412("/data/interface/cargo_" + var1.field_24.field_1246 + ".png");
                  this.field_757.method_275(var18, -1, var1.field_24.field_1246);
               }
            }
         } else {
            this.field_752 = class_40.method_412("/data/interface/cargo_" + var1.method_56() + ".png");
         }
      } catch (Exception var7) {
         var7.printStackTrace();
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_526(int var1) {
      this.field_757.method_277(var1);
   }

   // $VF: renamed from: b (int) void
   public final void method_527(int var1) {
      this.field_757.method_276(var1);
   }

   // $VF: renamed from: a () void
   public final void method_528() {
      class_69.method_663();
      class_69.method_664(class_41.field_533.method_297(226));
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534.drawRect(3, 12, class_41.field_537 - 7, 18);
      if (this.field_752 != null) {
         class_41.field_534.drawImage(this.field_752, 5, 14, 0);
      }

      if (this.field_751.method_48() && !this.field_760 && this.field_758 != null) {
         class_41.field_534.drawImage(this.field_759, 5, 14, 0);
      }

      class_69.method_674(this.field_754, 3 + this.field_763 + 4, 16, class_41.field_537 - this.field_763 - 12, 0);
      if (this.field_751.method_48() && this.field_758 != null) {
         for (int var1 = 0; var1 < this.field_758.length; var1++) {
            class_41.field_534.drawImage(this.field_758[var1], 4 + 22 * var1, 34, 0);
            if (!this.field_761[var1]) {
               class_41.field_534.drawImage(this.field_759, 4 + 22 * var1, 34, 0);
            }

            if (var1 > 0) {
               class_50.method_485("+", 4 + 22 * var1 - 4, 42, 0);
            }
         }
      }

      this.field_757.method_278();
      class_41.field_534.drawLine(3, this.field_762, class_41.field_537 - 6, this.field_762);
      int var3 = this.field_762;
      if (this.field_756 != null) {
         for (int var2 = 0; var2 < this.field_756.length; var2++) {
            class_41.field_534.drawLine(3, var3, class_41.field_537 - 4, var3);
            class_50.method_485(this.field_755[var2], 4, var3, 0);
            if (this.field_751.method_50()
               && class_69.method_657()
               && (
                  this.field_755[var2] == class_41.field_533.method_297(245)
                        && (
                           this.field_751.field_24.field_1240 > class_3.method_108().field_449
                              || this.field_751.field_24.field_1240 < class_3.method_108().field_448
                        )
                     || this.field_755[var2] == class_41.field_533.method_297(333) && this.field_751.field_24.field_1238 > class_3.method_108().method_366()
                     || this.field_755[var2] == class_41.field_533.method_297(331) && this.field_751.field_24.field_1235 > 0
               )) {
               class_41.field_534.setColor(255, 0, 0);
               class_41.field_534
                  .fillRect(
                     class_41.field_537 - 6 - class_50.method_490(this.field_756[var2]),
                     var3 + 1,
                     class_50.method_490(this.field_756[var2]) + 3,
                     class_50.method_494() - 1
                  );
               class_41.field_534.setColor(class_69.field_1003);
            }

            if (this.field_751.method_48()) {
               class_69.method_666(
                  this.field_751.field_23.field_632,
                  false,
                  class_41.field_537 - 4 - class_50.method_490(" $  - " + this.field_751.field_23.field_633),
                  var3,
                  0,
                  18
               );
               class_69.method_665(" - ", this.field_751.field_23.field_633, false, class_41.field_537 - 4, var3, 0, 18);
            } else {
               class_50.method_483(this.field_756[var2], class_41.field_537 - 4, var3, 0, 18);
            }

            var3 += 10;
         }
      }
   }
}
