// $VF: renamed from: h
public final class class_12 {
   // $VF: renamed from: a dd
   private class_23 field_118 = new class_23(5, 12, class_84.field_1120 - 10, class_84.field_1121 - 30, "");
   // $VF: renamed from: a int
   private int field_119;

   public class_12() {
      this.field_118.method_226(class_90.field_1206, "M.A.I.", true);
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_58(String var1) {
      this.field_118.method_225(var1);
      this.field_118.method_224();
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_59(int var1) {
      return var1 != 131072;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_60(int var1, int var2) {
      this.field_119 += var2;
      if (this.field_119 > 200) {
         if ((var1 & 2) != 0) {
            this.field_119 = 0;
            this.field_118.method_230(var2);
         }

         if ((var1 & 64) != 0) {
            this.field_119 = 0;
            this.field_118.method_229(var2);
         }
      }

      this.method_61();
      return true;
   }

   // $VF: renamed from: a () void
   public final void method_61() {
      class_67.method_587();
      class_67.method_588(class_84.field_1116.method_4(4));
      this.field_118.method_231();
      class_67.method_601("0: " + class_84.field_1116.method_4(65), "0: " + class_84.field_1116.method_4(65), false);
   }
}
