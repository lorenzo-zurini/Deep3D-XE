// $VF: renamed from: cs
public final class class_78 extends class_77 {
   public class_78(int var1, int var2, int var3, int var4) {
      this.method_690(var1, var2, var3, var4, null, class_41.field_533.method_297(266));
      class_46[] var5 = class_3.method_108().field_445;
      Object var6 = null;
      if (var5 == null) {
         ((Object[])(var6 = new class_2[1]))[0] = new class_2(class_41.field_533.method_297(30));
      } else {
         var6 = new class_2[var5.length];

         for (int var7 = 0; var7 < var5.length; var7++) {
            ((Object[])var6)[var7] = new class_2(
               class_40.method_412("/data/interface/cargo_" + var5[var7].field_626 + ".png"),
               var5[var7].field_626,
               var5[var7].field_636 + "x " + class_41.field_533.method_297(class_22.field_321[var5[var7].field_626][0])
            );
         }
      }

      this.method_693(0, (Object[])var6);
      this.method_696();
   }

   // $VF: renamed from: n () void
   public final void method_723() {
      class_50.method_483(
         class_41.field_533.method_297(60) + ":" + class_3.method_108().field_426 + "/" + class_3.method_108().method_367(),
         super.field_1046 + super.field_1048 / 2,
         super.field_1047 + super.field_1049 - 16,
         0,
         24
      );
   }
}
