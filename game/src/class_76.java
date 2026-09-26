import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.Sprite;

// $VF: renamed from: as
public final class class_76 extends class_74 {
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1086;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_1087;
   // $VF: renamed from: a javax.microedition.lcdui.game.Sprite
   private Sprite field_1088;
   // $VF: renamed from: c java.lang.String
   private String field_1089;

   public class_76(String[] var1, String var2) {
      super(var1, var2);
      super.field_1071 = 18;
      this.field_1086 = new Image[18];
      Image var3 = class_40.method_412("/data/interface/arrows.png");
      this.field_1088 = new Sprite(var3, var3.getHeight(), var3.getHeight());
   }

   // $VF: renamed from: a (int, al[]) void
   public final void method_720(int var1, class_95[] var2) {
      if (var2 == null) {
         class_2[] var6;
         (var6 = new class_2[1])[0] = new class_2(class_41.field_533.method_297(209));
         super.method_693(var1, var6);
      } else {
         if (this.field_1087 == null) {
            this.field_1087 = class_40.method_412("/data/interface/mission_story.png");
         }

         class_2[] var3 = null;
         if (var1 == 1) {
            if (var2 != null && var2.length > 0) {
               (var3 = new class_2[var2.length + 1])[0] = new class_2(class_41.field_533.method_297(309));

               for (int var4 = 0; var4 < var2.length; var4++) {
                  var2[var4].method_798();
                  var3[var4 + 1] = new class_2(var2[var4]);
                  int var5 = var2[var4].field_1226;
                  if (this.field_1086[var5] == null) {
                     this.field_1086[var5] = class_40.method_412("/data/interface/mission_" + var5 + ".png");
                  }
               }
            }
         } else {
            if (class_3.method_76()) {
               if (!var2[1].method_789() && var2[1] != null) {
                  (var3 = new class_2[2])[0] = new class_2(class_41.field_533.method_297(309));
                  var2[1].method_798();
                  var3[1] = new class_2(var2[1]);
               }
            } else {
               (var3 = new class_2[!var2[1].method_789() && var2[1] != null ? 4 : 2])[0] = new class_2(class_41.field_533.method_297(308));
               var2[0].method_798();
               var3[1] = new class_2(var2[0]);
               if (var3.length > 2) {
                  var3[2] = new class_2(class_41.field_533.method_297(309));
                  var2[1].method_798();
                  var3[3] = new class_2(var2[1]);
               }
            }

            for (int var7 = 0; var7 < var2.length; var7++) {
               if (var2[var7] != null && !var2[var7].method_789() && !var2[var7].field_1241) {
                  int var8 = var2[var7].field_1226;
                  if (this.field_1086[var8] == null) {
                     this.field_1086[var8] = class_40.method_412("/data/interface/mission_" + var8 + ".png");
                  }
               }
            }
         }

         super.method_693(var1, var3);
      }
   }

   // $VF: renamed from: a () void
   public final void method_711() {
      super.method_711();
      this.method_712();
   }

   // $VF: renamed from: b () void
   public final void method_712() {
      class_41.field_534.setColor(class_69.field_1005);
      class_41.field_534.fillRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534.drawRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      super.field_1074 = class_41.field_533.method_297(52) + ": " + class_3.method_108().method_366() + "km";
      class_50.method_483(super.field_1074, class_41.field_537 / 2, super.field_1047 + super.field_1049 - 14, 0, 24);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_714(Object var1, int var2) {
      class_2 var3;
      if ((var3 = (class_2)var1).method_50()) {
         if (var3.field_24.field_1226 < this.field_1086.length && this.field_1086[var3.field_24.field_1226] != null || var3.field_24.field_1241) {
            class_41.field_534
               .drawImage(
                  var3.field_24.field_1241 ? this.field_1087 : this.field_1086[var3.field_24.field_1226],
                  super.field_1061 + 2,
                  super.field_1062 + (var2 - super.field_1059) * super.field_1063 + this.method_691() / 2 + 1,
                  6
               );
         }

         if (!var3.field_24.field_1241) {
            class_69.method_665(
               "",
               var3.field_24.field_1230,
               false,
               super.field_1046 + super.field_1048 - 4 - super.field_1054,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
               super.field_1058 == var2 ? 0 : 1,
               18
            );
            class_69.method_666(
               var3.field_24.field_1231,
               true,
               super.field_1046 + super.field_1048 - 4 - super.field_1054,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8,
               super.field_1058 == var2 ? 0 : 1,
               18
            );
            class_69.method_674(
               var3.field_24.method_792(),
               super.field_1061 + super.field_1071 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
               super.field_1048 - super.field_1061 - super.field_1071 - 4 - 4 - super.field_1054 - 30 - 2,
               super.field_1058 == var2 ? 0 : 1
            );
         } else {
            if (var2 == super.field_1058) {
               class_41.field_534
                  .fillRect(
                     super.field_1061 + super.field_1071 + 4,
                     super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 2,
                     super.field_1048 - super.field_1061 - super.field_1071 - 4 - 4 - super.field_1054,
                     super.field_1063 - 1
                  );
            }

            class_69.method_674(
               var3.field_24.method_792(),
               super.field_1061 + super.field_1071 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
               super.field_1048 - super.field_1061 - super.field_1071 - 4 - 4 - super.field_1054 - 2,
               super.field_1058 == var2 ? 0 : 1
            );
         }

         if (var3.field_24.field_1251) {
            this.field_1089 = var3.field_24.field_1232 == class_3.method_110().field_828
               ? class_41.field_533.method_297(310)
               : "- " + var3.field_24.field_1238 + " km -";
            class_50.method_485(
               this.field_1089,
               super.field_1061 + super.field_1071 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8,
               super.field_1058 == var2 ? 0 : 1
            );
         }

         if (!var3.field_24.field_1241) {
            this.field_1088.setFrame(var3.field_24.field_1239);
            this.field_1088
               .setPosition(
                  super.field_1061 + super.field_1071 + 5 + class_50.method_490(this.field_1089) + 3,
                  super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8 + 2
               );
            this.field_1088.paint(class_41.field_534);
            return;
         }
      } else if (var3.method_49()) {
         class_50.method_485(var3.field_26, super.field_1061 + 3, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 5, 0);
      }
   }
}
