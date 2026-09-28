import javax.microedition.lcdui.Image;

// $VF: renamed from: dq
public class class_79 extends class_76 {
   public class_79() {
      super(
         class_84.field_1120 / 8,
         class_84.field_1121 / 6,
         class_84.field_1120 - class_84.field_1120 / 4,
         2 * class_84.field_1121 / 3,
         null,
         class_84.field_1116.method_4(260)
      );
      class_40[] var1 = class_90.method_787();
      boolean[] var2 = class_21.method_168();
      int var3 = 0;

      for (int var4 = 0; var4 < var2.length - 5; var4++) {
         if (var2[var4]) {
            var3++;
         }
      }

      byte var8 = 1;
      if (var2[13] || var2[14] || var2[15] || var2[16] || var2[17]) {
         var8 = 2;
      }

      class_59[] var5;
      (var5 = new class_59[var3 + var8])[0] = new class_59(class_28.method_282("/data/interface/x_1.png"), -1, class_84.field_1116.method_4(324));
      if (var8 == 2) {
         var5[1] = new class_59(class_28.method_282("/data/interface/cargo_17.png"), -3, class_84.field_1116.method_4(261));
      }

      int var6 = var8;

      for (int var7 = 0; var7 < var2.length - 5; var7++) {
         if (var2[var7]) {
            var5[var6++] = new class_59(
               class_28.method_282("/data/interface/cargo_" + var1[var7].field_391 + ".png"),
               var1[var7].field_391,
               class_84.field_1116.method_4(class_1.field_7[var1[var7].field_391][0])
            );
         }
      }

      super.method_700(0, var5);
      this.method_703();
   }

   // $VF: renamed from: a (int) javax.microedition.lcdui.Image
   public final Image method_727(int var1) {
      if (var1 >= 0) {
         for (int var2 = 0; var2 < super.field_1032[super.field_1038].length; var2++) {
            if (super.field_1032[super.field_1038][var2] != null && ((class_59)super.field_1032[super.field_1038][var2]).field_715 == var1) {
               return ((class_59)super.field_1032[super.field_1038][var2]).field_717;
            }
         }
      }

      return null;
   }

   // $VF: renamed from: c () int
   public final int method_728() {
      return super.field_1032[0][super.field_1039] != null ? ((class_59)super.field_1032[0][super.field_1039]).field_715 : -1;
   }

   // $VF: renamed from: g () void
   public final void method_720() {
      if (super.field_1032 != null) {
         class_84.field_1117.setColor(class_67.field_844);

         for (int var1 = super.field_1040;
            var1 < super.field_1032[super.field_1038].length
               && super.field_1032[super.field_1038][var1] != null
               && var1 < super.field_1040 + super.field_1041 + 1;
            var1++
         ) {
            Object var2 = null;
            if (var1 == super.field_1039 && ((class_59)super.field_1032[super.field_1038][var1]).field_713) {
               class_84.field_1117
                  .fillRect(super.field_1027 + 4, super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2, 21, super.field_1044 - 1);
               class_84.field_1117
                  .fillRect(
                     super.field_1042 + 18 + 4,
                     super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                     super.field_1029 - 18 - 10 - super.field_1035,
                     super.field_1044 - 1
                  );
            }

            this.method_721(super.field_1032[super.field_1038][var1], var1);
         }

         this.method_729();
      }
   }

   // $VF: renamed from: n () void
   public void method_729() {
      class_67.method_586(class_84.field_1116.method_4(41), super.field_1027, super.field_1028 + super.field_1030 - 16, super.field_1029, true, true);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_721(Object var1, int var2) {
      class_59 var3;
      if ((var3 = (class_59)var1).method_534()) {
         class_84.field_1117
            .drawImage(var3.field_717, super.field_1042 + 2, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + this.method_698() / 2 + 1, 6);
         if (class_58.method_523(var3.field_714) > super.field_1029 - 18 - 10 - super.field_1035) {
            String[] var4;
            class_58.method_518(
               (var4 = class_58.method_532(var3.field_714, super.field_1029 - 18 - 10 - super.field_1035))[0],
               super.field_1042 + 18 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044,
               super.field_1039 == var2 ? 0 : 1
            );
            class_58.method_518(
               var4[1], super.field_1042 + 18 + 5, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 10, super.field_1039 == var2 ? 0 : 1
            );
         } else {
            class_58.method_518(
               var3.field_714, super.field_1042 + 18 + 5, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 3, super.field_1039 == var2 ? 0 : 1
            );
         }
      } else {
         if (!var3.field_713) {
            class_58.method_516(
               var3.field_714, super.field_1042 + super.field_1029 / 2, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 3, 1, 24
            );
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_718() {
      this.registerRows(); // Deep3D-PC
      this.method_710();
      class_67.method_591(super.field_1050, super.field_1027, super.field_1028, super.field_1029, super.field_1030);
      this.method_720();
      this.method_709();
   }

   // $VF: renamed from: a () int
   public final int method_698() {
      return 18;
   }
}
