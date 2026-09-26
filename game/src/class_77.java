import javax.microedition.lcdui.Image;

// $VF: renamed from: m
public final class class_77 extends class_76 {
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1057;

   public class_77(String[] var1, String var2) {
      super(var1, var2);
      super.field_1052 = 18;
      this.field_1057 = new Image[5];

      for (int var3 = 0; var3 < this.field_1057.length - 2; var3++) {
         this.field_1057[var3] = class_28.method_282("/data/interface/medal_" + (var3 + 1) + ".png");
      }

      int var8 = class_21.method_180().method_752() ? 4 : 6;
      this.field_1057[3] = class_28.method_282("/data/interface/medal_" + var8 + ".png");
      this.field_1057[4] = class_28.method_282("/data/interface/medal_" + (var8 + 1) + ".png");
      int[] var4 = class_14.method_71();
      int var5 = 0;
      if (var4 != null) {
         for (int var6 = 0; var6 < var4.length; var6++) {
            if (var4[var6] > 0) {
               var5++;
            }
         }

         class_59[] var9 = new class_59[var4.length];

         for (int var7 = 0; var7 < var4.length; var7++) {
            var9[var7] = new class_59(var7, var4[var7]);
         }

         super.method_700(1, var9);
      }

      super.field_1055 = class_84.field_1116.method_4(63) + ": " + var5 + "/" + class_14.field_135.length;
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
      class_58.method_516(super.field_1055, class_84.field_1120 / 2, super.field_1028 + super.field_1030 - 14, 0, 24);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_721(Object var1, int var2) {
      class_59 var3 = (class_59)var1;
      if (var2 == super.field_1039) {
         class_84.field_1117
            .fillRect(
               super.field_1042 + super.field_1052 + 4,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 2,
               super.field_1029 - super.field_1042 - super.field_1052 - 4 - 4 - super.field_1035,
               super.field_1044 - 1
            );
      }

      Object var4 = null;
      if (var3.field_715 == 0) {
         var4 = super.field_1039 == var2 ? this.field_1057[3] : this.field_1057[4];
      } else {
         var4 = this.field_1057[var3.field_715 - 1];
      }

      class_84.field_1117
         .drawImage((Image)var4, super.field_1042 + 4, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + this.method_698() / 2 + 1, 6);
      class_67.method_598(
         class_84.field_1116.method_4(class_1.field_0[var3.field_716][0]),
         super.field_1042 + super.field_1052 + 5,
         super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
         super.field_1029 - super.field_1042 - super.field_1052 - 4 - 4 - super.field_1035 - 2,
         super.field_1039 == var2 ? 0 : 1
      );
   }
}
