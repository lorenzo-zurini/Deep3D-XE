// $VF: renamed from: db
public final class class_73 extends class_72 {
   // $VF: renamed from: d boolean
   private boolean field_1070;

   public class_73(int var1, int var2, int var3, int var4, String[] var5) {
      super(var1, var2, var3, var4, var5, "");
      super.field_1067 = false;
      super.field_1061 = var1;
      this.field_1070 = false;
   }

   // $VF: renamed from: l () void
   public final void method_703() {
      if (this.field_1070) {
         super.method_703();
      }
   }

   // $VF: renamed from: e () void
   public final void method_698() {
      if (super.field_1065 == 0) {
         if (super.field_1051[super.field_1057][super.field_1058 + 1] != null) {
            super.field_1058++;
         } else {
            super.field_1059 = 0;
            super.field_1058 = 0;
         }

         if (super.field_1058 > super.field_1059 + super.field_1060) {
            super.field_1059++;
         }
      } else if (super.field_1051[super.field_1057][0] != null) {
         super.field_1065 = 0;
      }

      this.method_696();
   }

   // $VF: renamed from: d () void
   public final void method_697() {
      if (super.field_1065 == 0) {
         if (super.field_1058 > 0) {
            super.field_1058--;
         } else {
            int var1 = 1;

            while (super.field_1051[super.field_1057][var1++] != null) {
            }

            super.field_1058 = var1 - 2;
            super.field_1059 = var1 - 1 - super.field_1060;
         }

         if (super.field_1059 > 0) {
            super.field_1059--;
         }
      }

      this.method_696();
   }

   // $VF: renamed from: a () void
   public final void method_705() {
      for (int var1 = super.field_1059;
         var1 < super.field_1051[super.field_1057].length && super.field_1051[super.field_1057][var1] != null && var1 < super.field_1059 + super.field_1060 + 1;
         var1++
      ) {
         this.method_706(super.field_1051[super.field_1057][var1], var1);
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_706(Object var1, int var2) {
      class_69.method_660(
         var1.toString(),
         super.field_1061,
         super.field_1062 + (var2 - super.field_1059) * super.field_1063,
         super.field_1053 > 0 ? super.field_1048 - 7 : super.field_1048,
         super.field_1065 == 0 && var2 == super.field_1058 && super.field_1067
      );
   }
}
