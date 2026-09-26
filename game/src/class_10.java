import javax.microedition.lcdui.Image;

// $VF: renamed from: j
public final class class_10 {
   // $VF: renamed from: a bh
   private class_59 field_102;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_103;
   // $VF: renamed from: a java.lang.String
   private String field_104;
   // $VF: renamed from: b java.lang.String
   private String field_105;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_106;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_107;
   // $VF: renamed from: a dd
   private class_23 field_108;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_109;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_110;
   // $VF: renamed from: a boolean
   private boolean field_111;
   // $VF: renamed from: a boolean[]
   private boolean[] field_112;
   // $VF: renamed from: a int
   private int field_113;
   // $VF: renamed from: b int
   private int field_114;

   // $VF: renamed from: a (bh, boolean) void
   public final void method_51(class_59 var1, boolean var2) {
      this.field_102 = var1;
      if (var1.method_536()) {
         this.field_114 = 31;
         this.field_105 = class_84.field_1116.method_4(class_1.field_6[var1.method_545()][0]);
         this.field_104 = class_84.field_1116.method_4(class_1.field_6[var1.method_545()][1]);
         int var3 = var1.field_710.field_165;
         switch (var1.field_710.field_165) {
            case 0:
            case 1:
               this.field_106 = new String[]{
                  class_84.field_1116.method_4(48), class_84.field_1116.method_4(49), class_84.field_1116.method_4(52), class_84.field_1116.method_4(56)
               };
               break;
            case 2:
               this.field_106 = new String[]{
                  class_84.field_1116.method_4(54), class_84.field_1116.method_4(55), class_84.field_1116.method_4(49), class_84.field_1116.method_4(56)
               };
               break;
            case 3:
               this.field_106 = new String[]{class_84.field_1116.method_4(50), class_84.field_1116.method_4(51), class_84.field_1116.method_4(245)};
               break;
            case 4:
               this.field_106 = new String[]{class_84.field_1116.method_4(50), class_84.field_1116.method_4(245)};
               break;
            case 5:
               this.field_106 = new String[]{class_84.field_1116.method_4(57)};
               break;
            case 6:
            case 7:
               this.field_106 = new String[]{class_84.field_1116.method_4(57)};
               break;
            case 8:
            case 10:
               this.field_106 = null;
               this.field_107 = null;
               break;
            case 9:
               this.field_106 = new String[]{class_84.field_1116.method_4(56), class_84.field_1116.method_4(53), class_84.field_1116.method_4(51)};
         }

         if (this.field_106 != null) {
            this.field_107 = new String[this.field_106.length];

            for (int var4 = 0; var4 < this.field_107.length; var4++) {
               this.field_107[var4] = "" + var1.field_710.method_117(var4);
               if (this.field_106[var4] == class_84.field_1116.method_4(49)
                  || this.field_106[var4] == class_84.field_1116.method_4(51)
                  || this.field_106[var4] == class_84.field_1116.method_4(53)) {
                  this.field_107[var4] = this.field_107[var4] + " ms";
               } else if (this.field_106[var4] == class_84.field_1116.method_4(54) || this.field_106[var4] == class_84.field_1116.method_4(245)) {
                  this.field_107[var4] = this.field_107[var4] + " m";
               } else if (this.field_106[var4] == class_84.field_1116.method_4(52)) {
                  int var5;
                  int var6 = (var5 = Integer.parseInt(this.field_107[var4]) / 3) % 10;
                  var5 = (var5 + var6) % 10 == 0 ? var5 + var6 : var5 - var6;
                  this.field_107[var4] = var5 + " m";
               } else if (this.field_106[var4] == class_84.field_1116.method_4(57) || this.field_106[var4] == class_84.field_1116.method_4(55)) {
                  this.field_107[var4] = "+" + this.field_107[var4] + "%";
               }

               if (this.field_106[var4] == class_84.field_1116.method_4(51) && var1.field_710.method_117(var4) == 0) {
                  this.field_107[var4] = "-";
               }
            }
         }
      } else if (var1.method_535()) {
         int var8 = var1.field_709.field_872 + var1.field_709.field_871;
         int var14 = var1.field_709.field_874;
         int var21 = (int)(var1.field_709.field_880 / 100.0F * var1.field_709.field_870 * 100.0F);
         this.field_114 = 31;
         this.field_105 = class_84.field_1116.method_4(class_1.field_8[var1.method_545()][0]);
         this.field_104 = class_84.field_1116.method_4(class_1.field_8[var1.method_545()][1]);
         this.field_106 = new String[]{
            class_84.field_1116.method_4(59), class_84.field_1116.method_4(60), class_84.field_1116.method_4(329), class_84.field_1116.method_4(58)
         };
         this.field_107 = new String[]{
            var1.field_709.field_864 + (var8 > 0 ? "+" + var8 : ""),
            var1.field_709.field_866 + (var14 > 0 ? "t+" + var14 + "t" : ""),
            "" + var1.field_709.field_869,
            "" + (int)(var1.field_709.field_870 * 100.0F) + (var21 > 0 ? "+" + var21 : "")
         };
      } else if (var1.method_537()) {
         this.field_114 = 18;
         this.field_104 = "";
         this.field_111 = var1.field_711.field_1490 > 0;
         this.field_110 = class_28.method_282("/data/interface/x_1.png");
         this.field_105 = class_84.field_1116.method_4(class_1.field_7[var1.field_711.field_1480][0]);
         if (var1.field_711.field_1488 != null) {
            this.field_104 = class_84.field_1116.method_4(330) + ":\n\n";

            for (int var9 = 0; var9 < var1.field_711.field_1488.length; var9++) {
               this.field_104 = this.field_104
                  + var1.field_711.field_1489[var9]
                  + "t "
                  + class_84.field_1116.method_4(class_1.field_7[class_90.method_785()[var1.field_711.field_1488[var9]].field_1480][0])
                  + "\n";
            }

            this.field_104 = this.field_104 + "\n";
         }

         this.field_104 = this.field_104 + class_84.field_1116.method_4(class_1.field_7[var1.field_711.field_1480][1]);
         this.field_106 = new String[]{class_84.field_1116.method_4(42)};
         this.field_107 = new String[]{""};
         if (var1.field_711.field_1488 != null) {
            this.field_109 = new Image[var1.field_711.field_1488.length];
            this.field_112 = new boolean[this.field_109.length];

            for (int var10 = 0; var10 < this.field_109.length; var10++) {
               this.field_109[var10] = class_28.method_282("/data/interface/cargo_" + var1.field_711.field_1488[var10] + ".png");
               this.field_112[var10] = class_120.method_932(var1.field_711.field_1488[var10], class_21.method_178().field_886);
            }
         } else {
            this.field_109 = null;
         }
      } else if (var1.method_539()) {
         this.field_114 = 18;
         this.field_105 = var1.field_712.method_757();
         this.field_104 = class_21.method_219(
            var1.field_712.method_758(), var1.field_712.field_1146 == 6 ? "" + var1.field_712.field_1169 : var1.field_712.field_1153
         );
         if (var1.field_712.field_1146 == 16) {
            this.field_104 = this.field_104 + " " + class_21.method_202() + " / " + var1.field_712.field_1170;
         } else if (var1.field_712.field_1146 == 18) {
            this.field_104 = this.field_104 + " " + class_21.method_177() + " / " + var1.field_712.field_1170;
         } else if (var1.field_712.field_1146 == 21) {
            this.field_104 = this.field_104 + " " + class_21.method_191() + " / " + var1.field_712.field_1170;
         } else if (var1.field_712.field_1146 == 15) {
            this.field_104 = this.field_104 + " " + class_21.method_209() + " / " + var1.field_712.field_1170;
         }

         String var11 = var1.field_712.field_1155 < 0 ? class_84.field_1116.method_4(335) : "" + var1.field_712.field_1155;
         if (var1.field_712 == class_21.method_135() && var1.field_712.field_1155 > 0) {
            var11 = var1.field_712.field_1156 + 1 + "/" + var1.field_712.field_1155;
         }

         String var15 = var1.field_712.field_1150 - var1.field_712.field_1151 + " $";
         if (var1.field_712.field_1161) {
            this.field_106 = null;
            this.field_107 = null;
         } else if (var1.field_712.field_1146 == 14 || var1.field_712.field_1146 == 13) {
            this.field_106 = new String[]{class_84.field_1116.method_4(332)};
            this.field_107 = new String[]{var15};
         } else if (var1.field_712.field_1146 == 8) {
            this.field_106 = new String[]{
               class_84.field_1116.method_4(334),
               class_84.field_1116.method_4(245),
               class_84.field_1116.method_4(333),
               class_84.field_1116.method_4(331),
               class_84.field_1116.method_4(332)
            };
            this.field_107 = new String[]{
               var1.field_712.field_1153,
               var1.field_712.field_1160 + " m",
               var1.field_712.field_1158 == 0 ? class_84.field_1116.method_4(310) : var1.field_712.field_1158 + " km",
               var11,
               var15
            };
         } else {
            int var22 = var1.field_712.method_764();
            String var23 = class_84.field_1116.method_4(var22 < 4 ? 273 : (var22 < 8 ? 274 : 275));
            this.field_106 = new String[]{
               class_84.field_1116.method_4(334),
               class_84.field_1116.method_4(245),
               class_84.field_1116.method_4(333),
               class_84.field_1116.method_4(39),
               class_84.field_1116.method_4(332)
            };
            this.field_107 = new String[]{
               var1.field_712.field_1153,
               var1.field_712.field_1160 + " m",
               var1.field_712.field_1158 == 0 ? class_84.field_1116.method_4(310) : var1.field_712.field_1158 + " km",
               var23,
               var15
            };
         }

         class_119.method_921(var1.field_712.field_1148);
      }

      if (!var1.method_539() && !var1.method_537()) {
         String[] var12;
         String[] var16;
         if (this.field_107 == null) {
            var12 = new String[1];
            var16 = new String[1];
         } else {
            var12 = new String[this.field_106.length + 1];
            var16 = new String[this.field_107.length + 1];
            System.arraycopy(this.field_106, 0, var12, 0, this.field_106.length);
            System.arraycopy(this.field_107, 0, var16, 0, this.field_107.length);
         }

         var12[var12.length - 1] = class_84.field_1116.method_4(42);
         var16[var16.length - 1] = var1.method_544() + " $";
         this.field_107 = var16;
         this.field_106 = var12;
      }

      this.field_113 = class_84.field_1121 - 10 - (this.field_107 == null ? 0 : this.field_107.length * 10 + 6);
      int var13 = var1.method_537() && this.field_109 != null ? 22 : 0;
      this.field_108 = new class_23(5, 34 + var13, class_84.field_1120 - 10, this.field_113 - 2 - 12 - 22 - var13, this.field_104);
      if (var1.method_539() && !var1.field_712.field_1161) {
         this.field_108.method_226(var1.field_712.field_1148, class_84.field_1116.method_4(142) + ":\n" + var1.field_712.field_1147, true);
      }

      try {
         if (var1.method_535()) {
            boolean var17 = var1.field_709.field_884;
            this.field_103 = class_28.method_282("/data/interface/equipment/u" + var1.method_545() + (var17 ? "b" : "a") + ".png");
         } else if (var1.method_536()) {
            this.field_103 = class_28.method_282("/data/interface/equipment/slot_" + var1.method_545() + ".png");
         } else if (var1.method_539()) {
            if (var1.field_712.field_1161) {
               this.field_103 = class_28.method_282("/data/interface/mission_story.png");
            } else {
               this.field_103 = class_28.method_282("/data/interface/mission_" + var1.field_712.field_1146 + ".png");
               if (var1.field_712.field_1146 == 13 || var1.field_712.field_1146 == 14) {
                  Image var19 = class_28.method_282("/data/interface/cargo_" + var1.field_712.field_1164 + ".png");
                  this.field_108.method_228(var19, var1.field_712.field_1165, var1.field_712.field_1164);
               } else if (var1.field_712.field_1146 == 7 || var1.field_712.field_1146 == 6) {
                  Image var18 = class_28.method_282("/data/interface/cargo_" + var1.field_712.field_1166 + ".png");
                  this.field_108.method_228(var18, -1, var1.field_712.field_1166);
               }
            }
         } else {
            this.field_103 = class_28.method_282("/data/interface/cargo_" + var1.method_545() + ".png");
         }
      } catch (Exception var7) {
         var7.printStackTrace();
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_52(int var1) {
      this.field_108.method_230(var1);
   }

   // $VF: renamed from: b (int) void
   public final void method_53(int var1) {
      this.field_108.method_229(var1);
   }

   // $VF: renamed from: a () void
   public final void method_54() {
      class_67.method_587();
      class_67.method_588(class_84.field_1116.method_4(226));
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117.drawRect(3, 12, class_84.field_1120 - 7, 18);
      if (this.field_103 != null) {
         class_84.field_1117.drawImage(this.field_103, 5, 14, 0);
      }

      if (this.field_102.method_537() && !this.field_111 && this.field_109 != null) {
         class_84.field_1117.drawImage(this.field_110, 5, 14, 0);
      }

      class_67.method_598(this.field_105, 3 + this.field_114 + 4, 16, class_84.field_1120 - this.field_114 - 12, 0);
      if (this.field_102.method_537() && this.field_109 != null) {
         for (int var1 = 0; var1 < this.field_109.length; var1++) {
            class_84.field_1117.drawImage(this.field_109[var1], 4 + 22 * var1, 34, 0);
            if (!this.field_112[var1]) {
               class_84.field_1117.drawImage(this.field_110, 4 + 22 * var1, 34, 0);
            }

            if (var1 > 0) {
               class_58.method_518("+", 4 + 22 * var1 - 4, 42, 0);
            }
         }
      }

      this.field_108.method_231();
      class_84.field_1117.drawLine(3, this.field_113, class_84.field_1120 - 6, this.field_113);
      int var3 = this.field_113;
      if (this.field_107 != null) {
         for (int var2 = 0; var2 < this.field_107.length; var2++) {
            class_84.field_1117.drawLine(3, var3, class_84.field_1120 - 4, var3);
            class_58.method_518(this.field_106[var2], 4, var3, 0);
            if (this.field_102.method_539()
               && class_67.method_581()
               && (
                  this.field_106[var2] == class_84.field_1116.method_4(245)
                        && (
                           this.field_102.field_712.field_1160 > class_21.method_178().field_890
                              || this.field_102.field_712.field_1160 < class_21.method_178().field_889
                        )
                     || this.field_106[var2] == class_84.field_1116.method_4(333) && this.field_102.field_712.field_1158 > class_21.method_178().method_606()
                     || this.field_106[var2] == class_84.field_1116.method_4(331) && this.field_102.field_712.field_1155 > 0
               )) {
               class_84.field_1117.setColor(255, 0, 0);
               class_84.field_1117
                  .fillRect(
                     class_84.field_1120 - 6 - class_58.method_523(this.field_107[var2]),
                     var3 + 1,
                     class_58.method_523(this.field_107[var2]) + 3,
                     class_58.method_527() - 1
                  );
               class_84.field_1117.setColor(class_67.field_844);
            }

            if (this.field_102.method_537()) {
               class_67.method_590(
                  this.field_102.field_711.field_1486,
                  false,
                  class_84.field_1120 - 4 - class_58.method_523(" $  - " + this.field_102.field_711.field_1487),
                  var3,
                  0,
                  18
               );
               class_67.method_589(" - ", this.field_102.field_711.field_1487, false, class_84.field_1120 - 4, var3, 0, 18);
            } else {
               class_58.method_516(this.field_107[var2], class_84.field_1120 - 4, var3, 0, 18);
            }

            var3 += 10;
         }
      }
   }
}
