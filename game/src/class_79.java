import javax.microedition.lcdui.Image;

// $VF: renamed from: n
public final class class_79 extends class_74 {
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1090;

   public class_79(String[] var1, String var2) {
      super(var1, var2);
      super.field_1071 = 18;
      this.field_1090 = new Image[5];

      for (int var3 = 0; var3 < this.field_1090.length - 2; var3++) {
         this.field_1090[var3] = class_40.method_412("/data/interface/medal_" + (var3 + 1) + ".png");
      }

      int var8 = class_3.method_110().method_592() ? 4 : 6;
      this.field_1090[3] = class_40.method_412("/data/interface/medal_" + var8 + ".png");
      this.field_1090[4] = class_40.method_412("/data/interface/medal_" + (var8 + 1) + ".png");
      int[] var4 = class_58.method_566();
      int var5 = 0;
      if (var4 != null) {
         for (int var6 = 0; var6 < var4.length; var6++) {
            if (var4[var6] > 0) {
               var5++;
            }
         }

         class_2[] var9 = new class_2[var4.length];

         for (int var7 = 0; var7 < var4.length; var7++) {
            var9[var7] = new class_2(var7, var4[var7]);
         }

         super.method_693(1, var9);
      }

      super.field_1074 = class_41.field_533.method_297(63) + ": " + var5 + "/" + class_58.field_805.length;
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
      class_50.method_483(super.field_1074, class_41.field_537 / 2, super.field_1047 + super.field_1049 - 14, 0, 24);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_714(Object var1, int var2) {
      class_2 var3 = (class_2)var1;
      if (var2 == super.field_1058) {
         class_41.field_534
            .fillRect(
               super.field_1061 + super.field_1071 + 4,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 2,
               super.field_1048 - super.field_1061 - super.field_1071 - 4 - 4 - super.field_1054,
               super.field_1063 - 1
            );
      }

      Object var4 = null;
      if (var3.field_27 == 0) {
         var4 = super.field_1058 == var2 ? this.field_1090[3] : this.field_1090[4];
      } else {
         var4 = this.field_1090[var3.field_27 - 1];
      }

      class_41.field_534
         .drawImage((Image)var4, super.field_1061 + 4, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + this.method_691() / 2 + 1, 6);
      class_69.method_674(
         class_41.field_533.method_297(class_22.field_314[var3.field_28][0]),
         super.field_1061 + super.field_1071 + 5,
         super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
         super.field_1048 - super.field_1061 - super.field_1071 - 4 - 4 - super.field_1054 - 2,
         super.field_1058 == var2 ? 0 : 1
      );
   }
}
