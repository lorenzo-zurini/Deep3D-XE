// $VF: renamed from: i
public final class class_80 {
   // $VF: renamed from: a dc
   private class_18 field_1091 = new class_18(5, 12, class_41.field_537 - 10, class_41.field_538 - 30, "");
   // $VF: renamed from: a int
   private int field_1092;

   public class_80() {
      this.field_1091.method_273(class_24.field_362, "M.A.I.", true);
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_724(String var1) {
      this.field_1091.method_272(var1);
      this.field_1091.method_271();
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_725(int var1) {
      return var1 != 131072;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_726(int var1, int var2) {
      this.field_1092 += var2;
      if (this.field_1092 > 200) {
         if ((var1 & 2) != 0) {
            this.field_1092 = 0;
            this.field_1091.method_277(var2);
         }

         if ((var1 & 64) != 0) {
            this.field_1092 = 0;
            this.field_1091.method_276(var2);
         }
      }

      this.method_727();
      return true;
   }

   // $VF: renamed from: a () void
   public final void method_727() {
      class_69.method_663();
      class_69.method_664(class_41.field_533.method_297(4));
      this.field_1091.method_278();
      class_69.method_677("0: " + class_41.field_533.method_297(65), "0: " + class_41.field_533.method_297(65), false);
   }
}
