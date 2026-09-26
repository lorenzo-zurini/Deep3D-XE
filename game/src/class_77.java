import javax.microedition.lcdui.Image;

// $VF: renamed from: dq
public class class_77 extends class_74 {
   public class_77() {
      super(
         class_41.field_537 / 8,
         class_41.field_538 / 6,
         class_41.field_537 - class_41.field_537 / 4,
         2 * class_41.field_538 / 3,
         null,
         class_41.field_533.method_297(260)
      );
      class_63[] var1 = class_24.method_317();
      boolean[] var2 = class_3.method_98();
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

      class_2[] var5;
      (var5 = new class_2[var3 + var8])[0] = new class_2(class_40.method_412("/data/interface/x_1.png"), -1, class_41.field_533.method_297(324));
      if (var8 == 2) {
         var5[1] = new class_2(class_40.method_412("/data/interface/cargo_17.png"), -3, class_41.field_533.method_297(261));
      }

      int var6 = var8;

      for (int var7 = 0; var7 < var2.length - 5; var7++) {
         if (var2[var7]) {
            var5[var6++] = new class_2(
               class_40.method_412("/data/interface/cargo_" + var1[var7].field_857 + ".png"),
               var1[var7].field_857,
               class_41.field_533.method_297(class_22.field_321[var1[var7].field_857][0])
            );
         }
      }

      super.method_693(0, var5);
      this.method_696();
   }

   // $VF: renamed from: a (int) javax.microedition.lcdui.Image
   public final Image method_721(int var1) {
      if (var1 >= 0) {
         for (int var2 = 0; var2 < super.field_1051[super.field_1057].length; var2++) {
            if (super.field_1051[super.field_1057][var2] != null && ((class_2)super.field_1051[super.field_1057][var2]).field_27 == var1) {
               return ((class_2)super.field_1051[super.field_1057][var2]).field_29;
            }
         }
      }

      return null;
   }

   // $VF: renamed from: c () int
   public final int method_722() {
      return super.field_1051[0][super.field_1058] != null ? ((class_2)super.field_1051[0][super.field_1058]).field_27 : -1;
   }

   // $VF: renamed from: g () void
   public final void method_713() {
      if (super.field_1051 != null) {
         class_41.field_534.setColor(class_69.field_1003);

         for (int var1 = super.field_1059;
            var1 < super.field_1051[super.field_1057].length
               && super.field_1051[super.field_1057][var1] != null
               && var1 < super.field_1059 + super.field_1060 + 1;
            var1++
         ) {
            Object var2 = null;
            if (var1 == super.field_1058 && ((class_2)super.field_1051[super.field_1057][var1]).field_25) {
               class_41.field_534.fillRect(super.field_1046 + 4, super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2, 21, super.field_1063 - 1);
               class_41.field_534
                  .fillRect(
                     super.field_1061 + 18 + 4,
                     super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                     super.field_1048 - 18 - 10 - super.field_1054,
                     super.field_1063 - 1
                  );
            }

            this.method_714(super.field_1051[super.field_1057][var1], var1);
         }

         this.method_723();
      }
   }

   // $VF: renamed from: n () void
   public void method_723() {
      class_69.method_662(class_41.field_533.method_297(41), super.field_1046, super.field_1047 + super.field_1049 - 16, super.field_1048, true, true);
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_714(Object var1, int var2) {
      class_2 var3;
      if ((var3 = (class_2)var1).method_45()) {
         class_41.field_534
            .drawImage(var3.field_29, super.field_1061 + 2, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + this.method_691() / 2 + 1, 6);
         if (class_50.method_490(var3.field_26) > super.field_1048 - 18 - 10 - super.field_1054) {
            String[] var4;
            class_50.method_485(
               (var4 = class_50.method_499(var3.field_26, super.field_1048 - 18 - 10 - super.field_1054))[0],
               super.field_1061 + 18 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063,
               super.field_1058 == var2 ? 0 : 1
            );
            class_50.method_485(
               var4[1], super.field_1061 + 18 + 5, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 10, super.field_1058 == var2 ? 0 : 1
            );
         } else {
            class_50.method_485(
               var3.field_26, super.field_1061 + 18 + 5, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 3, super.field_1058 == var2 ? 0 : 1
            );
         }
      } else {
         if (!var3.field_25) {
            class_50.method_483(
               var3.field_26, super.field_1061 + super.field_1048 / 2, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 3, 1, 24
            );
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_711() {
      this.method_703();
      class_69.method_667(super.field_1069, super.field_1046, super.field_1047, super.field_1048, super.field_1049);
      this.method_713();
      this.method_702();
   }

   // $VF: renamed from: a () int
   public final int method_691() {
      return 18;
   }
}
