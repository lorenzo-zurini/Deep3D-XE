// $VF: renamed from: ct
public final class class_80 extends class_79 {
   public class_80(int var1, int var2, int var3, int var4) {
      this.method_697(var1, var2, var3, var4, null, class_84.field_1116.method_4(266));
      class_120[] var5 = class_21.method_178().field_886;
      Object var6 = null;
      if (var5 == null) {
         ((Object[])(var6 = new class_59[1]))[0] = new class_59(class_84.field_1116.method_4(30));
      } else {
         var6 = new class_59[var5.length];

         for (int var7 = 0; var7 < var5.length; var7++) {
            ((Object[])var6)[var7] = new class_59(
               class_28.method_282("/data/interface/cargo_" + var5[var7].field_1480 + ".png"),
               var5[var7].field_1480,
               var5[var7].field_1490 + "x " + class_84.field_1116.method_4(class_1.field_7[var5[var7].field_1480][0])
            );
         }
      }

      this.method_700(0, (Object[])var6);
      this.method_703();
   }

   // $VF: renamed from: n () void
   public final void method_729() {
      class_58.method_516(
         class_84.field_1116.method_4(60) + ":" + class_21.method_178().field_867 + "/" + class_21.method_178().method_607(),
         super.field_1027 + super.field_1029 / 2,
         super.field_1028 + super.field_1030 - 16,
         0,
         24
      );
   }
}
