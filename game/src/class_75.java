// $VF: renamed from: dc
public final class class_75 extends class_74 {
   // $VF: renamed from: d boolean
   private boolean field_1051;

   public class_75(int var1, int var2, int var3, int var4, String[] var5) {
      super(var1, var2, var3, var4, var5, "");
      super.field_1048 = false;
      super.field_1042 = var1;
      this.field_1051 = false;
   }

   // $VF: renamed from: l () void
   public final void method_710() {
      if (this.field_1051) {
         super.method_710();
      }
   }

   // $VF: renamed from: e () void
   public final void method_705() {
      if (super.field_1046 == 0) {
         if (super.field_1032[super.field_1038][super.field_1039 + 1] != null) {
            super.field_1039++;
         } else {
            super.field_1040 = 0;
            super.field_1039 = 0;
         }

         if (super.field_1039 > super.field_1040 + super.field_1041) {
            super.field_1040++;
         }
      } else if (super.field_1032[super.field_1038][0] != null) {
         super.field_1046 = 0;
      }

      this.method_703();
   }

   // $VF: renamed from: d () void
   public final void method_704() {
      if (super.field_1046 == 0) {
         if (super.field_1039 > 0) {
            super.field_1039--;
         } else {
            int var1 = 1;

            while (super.field_1032[super.field_1038][var1++] != null) {
            }

            super.field_1039 = var1 - 2;
            super.field_1040 = var1 - 1 - super.field_1041;
         }

         if (super.field_1040 > 0) {
            super.field_1040--;
         }
      }

      this.method_703();
   }

   // $VF: renamed from: a () void
   public final void method_712() {
      for (int var1 = super.field_1040;
         var1 < super.field_1032[super.field_1038].length && super.field_1032[super.field_1038][var1] != null && var1 < super.field_1040 + super.field_1041 + 1;
         var1++
      ) {
         this.method_713(super.field_1032[super.field_1038][var1], var1);
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_713(Object var1, int var2) {
      class_67.method_584(
         var1.toString(),
         super.field_1042,
         super.field_1043 + (var2 - super.field_1040) * super.field_1044,
         super.field_1034 > 0 ? super.field_1029 - 7 : super.field_1029,
         super.field_1046 == 0 && var2 == super.field_1039 && super.field_1048
      );
   }
}
