import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.Sprite;

// $VF: renamed from: at
public final class class_81 extends class_76 {
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1068;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_1069;
   // $VF: renamed from: a javax.microedition.lcdui.game.Sprite
   private Sprite field_1070;
   // $VF: renamed from: c java.lang.String
   private String field_1071;

   public class_81(String[] var1, String var2) {
      super(var1, var2);
      super.field_1052 = 18;
      this.field_1068 = new Image[18];
      Image var3 = class_28.method_282("/data/interface/arrows.png");
      this.field_1070 = new Sprite(var3, var3.getHeight(), var3.getHeight());
   }

   // $VF: renamed from: a (int, am[]) void
   public final void method_730(int var1, class_87[] var2) {
      if (var2 == null) {
         class_59[] var6;
         (var6 = new class_59[1])[0] = new class_59(class_84.field_1116.method_4(209));
         super.method_700(var1, var6);
      } else {
         if (this.field_1069 == null) {
            this.field_1069 = class_28.method_282("/data/interface/mission_story.png");
         }

         class_59[] var3 = null;
         if (var1 == 1) {
            if (var2 != null && var2.length > 0) {
               (var3 = new class_59[var2.length + 1])[0] = new class_59(class_84.field_1116.method_4(309));

               for (int var4 = 0; var4 < var2.length; var4++) {
                  var2[var4].method_763();
                  var3[var4 + 1] = new class_59(var2[var4]);
                  int var5 = var2[var4].field_1146;
                  if (this.field_1068[var5] == null) {
                     this.field_1068[var5] = class_28.method_282("/data/interface/mission_" + var5 + ".png");
                  }
               }
            }
         } else {
            if (class_21.method_146()) {
               if (!var2[1].method_754() && var2[1] != null) {
                  (var3 = new class_59[2])[0] = new class_59(class_84.field_1116.method_4(309));
                  var2[1].method_763();
                  var3[1] = new class_59(var2[1]);
               }
            } else {
               (var3 = new class_59[!var2[1].method_754() && var2[1] != null ? 4 : 2])[0] = new class_59(class_84.field_1116.method_4(308));
               var2[0].method_763();
               var3[1] = new class_59(var2[0]);
               if (var3.length > 2) {
                  var3[2] = new class_59(class_84.field_1116.method_4(309));
                  var2[1].method_763();
                  var3[3] = new class_59(var2[1]);
               }
            }

            for (int var7 = 0; var7 < var2.length; var7++) {
               if (var2[var7] != null && !var2[var7].method_754() && !var2[var7].field_1161) {
                  int var8 = var2[var7].field_1146;
                  if (this.field_1068[var8] == null) {
                     this.field_1068[var8] = class_28.method_282("/data/interface/mission_" + var8 + ".png");
                  }
               }
            }
         }

         super.method_700(var1, var3);
      }
   }

   // $VF: renamed from: a () void
   public final void method_718() {
      super.method_718();
      this.method_719();
   }

   // $VF: renamed from: b () void
   public final void method_719() {
      class_84.field_1117.setColor(class_67.field_846);
      class_84.field_1117.fillRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117.drawRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      super.field_1055 = class_84.field_1116.method_4(52) + ": " + class_21.method_178().method_606() + "km";
      class_58.method_516(super.field_1055, class_84.field_1120 / 2, super.field_1028 + super.field_1030 - 14, 0, 24);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_721(Object var1, int var2) {
      class_59 var3;
      if ((var3 = (class_59)var1).method_539()) {
         if (var3.field_712.field_1146 < this.field_1068.length && this.field_1068[var3.field_712.field_1146] != null || var3.field_712.field_1161) {
            class_84.field_1117
               .drawImage(
                  var3.field_712.field_1161 ? this.field_1069 : this.field_1068[var3.field_712.field_1146],
                  super.field_1042 + 2,
                  super.field_1043 + (var2 - super.field_1040) * super.field_1044 + this.method_698() / 2 + 1,
                  6
               );
         }

         if (!var3.field_712.field_1161) {
            class_67.method_589(
               "",
               var3.field_712.field_1150,
               false,
               super.field_1027 + super.field_1029 - 4 - super.field_1035,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
               super.field_1039 == var2 ? 0 : 1,
               18
            );
            class_67.method_590(
               var3.field_712.field_1151,
               true,
               super.field_1027 + super.field_1029 - 4 - super.field_1035,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8,
               super.field_1039 == var2 ? 0 : 1,
               18
            );
            class_67.method_598(
               var3.field_712.method_757(),
               super.field_1042 + super.field_1052 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
               super.field_1029 - super.field_1042 - super.field_1052 - 4 - 4 - super.field_1035 - 30 - 2,
               super.field_1039 == var2 ? 0 : 1
            );
         } else {
            if (var2 == super.field_1039) {
               class_84.field_1117
                  .fillRect(
                     super.field_1042 + super.field_1052 + 4,
                     super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 2,
                     super.field_1029 - super.field_1042 - super.field_1052 - 4 - 4 - super.field_1035,
                     super.field_1044 - 1
                  );
            }

            class_67.method_598(
               var3.field_712.method_757(),
               super.field_1042 + super.field_1052 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
               super.field_1029 - super.field_1042 - super.field_1052 - 4 - 4 - super.field_1035 - 2,
               super.field_1039 == var2 ? 0 : 1
            );
         }

         if (var3.field_712.field_1171) {
            this.field_1071 = var3.field_712.field_1152 == class_21.method_180().field_1134
               ? class_84.field_1116.method_4(310)
               : "- " + var3.field_712.field_1158 + " km -";
            class_58.method_518(
               this.field_1071,
               super.field_1042 + super.field_1052 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8,
               super.field_1039 == var2 ? 0 : 1
            );
         }

         if (!var3.field_712.field_1161) {
            this.field_1070.setFrame(var3.field_712.field_1159);
            this.field_1070
               .setPosition(
                  super.field_1042 + super.field_1052 + 5 + class_58.method_523(this.field_1071) + 3,
                  super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8 + 2
               );
            this.field_1070.paint(class_84.field_1117);
            return;
         }
      } else if (var3.method_538()) {
         class_58.method_518(var3.field_714, super.field_1042 + 3, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 5, 0);
      }
   }
}
