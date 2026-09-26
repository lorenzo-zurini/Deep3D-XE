// $VF: renamed from: y
public final class class_2 {
   // $VF: renamed from: a int
   public int field_31;
   // $VF: renamed from: b int
   private int field_32;
   // $VF: renamed from: c int
   private int field_33;
   // $VF: renamed from: d int
   private int field_34;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_35;
   // $VF: renamed from: e int
   private int field_36;

   public class_2(class_26 var1) {
      this.field_36 = var1.field_272.field_982 != null && !var1.field_272.field_982.method_111().field_1298
         ? 3
         : (class_21.method_146() && class_21.method_180().field_1134 == 0 ? 1 : 2);
      this.field_35 = new String[this.field_36];
      this.field_35[0] = class_84.field_1116.method_4(327);
      if (this.field_36 > 1) {
         this.field_35[1] = class_21.method_180().field_1133;
      }

      if (this.field_36 == 3) {
         this.field_35[2] = class_84.field_1116.method_4(326);
      }

      this.field_34 = 0;

      for (int var2 = 0; var2 < this.field_35.length; var2++) {
         int var3;
         if ((var3 = class_58.method_523(this.field_35[var2])) + 15 > this.field_34) {
            this.field_34 = var3 + 15;
         }
      }

      this.field_32 = (class_84.field_1120 - this.field_34) / 2;
      this.field_33 = (class_84.field_1121 - (this.field_36 * 10 + 12)) / 2;
   }

   // $VF: renamed from: a () void
   public final void method_6() {
      if (this.field_31 > 0) {
         this.field_31--;
      } else {
         this.field_31 = this.field_36 - 1;
      }
   }

   // $VF: renamed from: b () void
   public final void method_7() {
      if (this.field_31 < this.field_36 - 1) {
         this.field_31++;
      } else {
         this.field_31 = 0;
      }
   }

   // $VF: renamed from: c () void
   public final void method_8() {
      class_67.method_591(class_84.field_1116.method_4(325), this.field_32, this.field_33, this.field_34, 12 + (this.field_36 + 1) * 10 - 5);

      for (int var1 = 0; var1 < this.field_35.length; var1++) {
         class_67.method_584(this.field_35[var1], this.field_32, this.field_33 + 12 + var1 * 10, this.field_34, this.field_31 == var1);
      }
   }
}
