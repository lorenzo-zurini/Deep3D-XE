// $VF: renamed from: x
public final class class_3 {
   // $VF: renamed from: a int
   public int field_37;
   // $VF: renamed from: b int
   public int field_38;
   // $VF: renamed from: c int
   public int field_39;

   public class_3(int var1, int var2, int var3) {
      this.field_37 = var1;
      this.field_38 = var2;
      this.field_39 = var3;
   }

   public class_3() {
      this.field_37 = this.field_38 = this.field_39 = 0;
   }

   public class_3(class_3 var1) {
      this.field_37 = var1.field_37;
      this.field_38 = var1.field_38;
      this.field_39 = var1.field_39;
   }

   // $VF: renamed from: a (x) void
   public final void method_9(class_3 var1) {
      this.field_37 = var1.field_37;
      this.field_38 = var1.field_38;
      this.field_39 = var1.field_39;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_10(int var1, int var2, int var3) {
      this.field_37 = var1;
      this.field_38 = var2;
      this.field_39 = var3;
   }

   // $VF: renamed from: a (x) int
   public final int method_11(class_3 var1) {
      // Deep3D-PC: 64-bit products so extended view distances cannot overflow
      // (identical results wherever the original int math did not).
      return (int)(
         ((long)this.field_37 * var1.field_37 >> 12) + ((long)this.field_38 * var1.field_38 >> 12) + ((long)this.field_39 * var1.field_39 >> 12)
      );
   }

   // $VF: renamed from: b (x) int
   public final int method_12(class_3 var1) {
      return (int)(((long)this.field_37 * var1.field_37 >> 12) + ((long)this.field_38 * var1.field_38 >> 12) + ((long)this.field_39 * var1.field_39 >> 12));
   }

   // $VF: renamed from: a (x, x) x
   public final class_3 method_13(class_3 var1, class_3 var2) {
      var2.field_37 = (this.field_38 * var1.field_39 >> 12) - (this.field_39 * var1.field_38 >> 12);
      var2.field_38 = (this.field_39 * var1.field_37 >> 12) - (this.field_37 * var1.field_39 >> 12);
      var2.field_39 = (this.field_37 * var1.field_38 >> 12) - (this.field_38 * var1.field_37 >> 12);
      return var2;
   }

   // $VF: renamed from: b (x, x) x
   public final class_3 method_14(class_3 var1, class_3 var2) {
      var2.field_37 = this.field_37 + var1.field_37;
      var2.field_38 = this.field_38 + var1.field_38;
      var2.field_39 = this.field_39 + var1.field_39;
      return var2;
   }

   // $VF: renamed from: b (x) void
   public final void method_15(class_3 var1) {
      this.field_37 = this.field_37 + var1.field_37;
      this.field_38 = this.field_38 + var1.field_38;
      this.field_39 = this.field_39 + var1.field_39;
   }

   // $VF: renamed from: c (x, x) x
   public final class_3 method_16(class_3 var1, class_3 var2) {
      var2.field_37 = this.field_37 - var1.field_37;
      var2.field_38 = this.field_38 - var1.field_38;
      var2.field_39 = this.field_39 - var1.field_39;
      return var2;
   }

   // $VF: renamed from: c (x) void
   public final void method_17(class_3 var1) {
      this.field_37 = this.field_37 - var1.field_37;
      this.field_38 = this.field_38 - var1.field_38;
      this.field_39 = this.field_39 - var1.field_39;
   }

   // $VF: renamed from: a (int) void
   public final void method_18(int var1) {
      this.field_37 = (int)((long)var1 * this.field_37 >> 12);
      this.field_38 = (int)((long)var1 * this.field_38 >> 12);
      this.field_39 = (int)((long)var1 * this.field_39 >> 12);
   }

   // $VF: renamed from: a (int, x) x
   public final class_3 method_19(int var1, class_3 var2) {
      var2.field_37 = (this.field_37 << 12) / var1;
      var2.field_38 = (this.field_38 << 12) / var1;
      var2.field_39 = (this.field_39 << 12) / var1;
      return var2;
   }

   // $VF: renamed from: b (int) void
   public final void method_20(int var1) {
      this.field_37 = (this.field_37 << 12) / var1;
      this.field_38 = (this.field_38 << 12) / var1;
      this.field_39 = (this.field_39 << 12) / var1;
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_21(class_3 var1) {
      int var2 = class_16.method_95(
         (int)(((long)this.field_37 * this.field_37 >> 12) + ((long)this.field_38 * this.field_38 >> 12) + ((long)this.field_39 * this.field_39 >> 12))
      );
      var1.field_37 = this.field_37 * var2 >> 12;
      var1.field_38 = this.field_38 * var2 >> 12;
      var1.field_39 = this.field_39 * var2 >> 12;
      return var1;
   }

   // $VF: renamed from: a () void
   public final void method_22() {
      this.method_21(this);
   }

   // $VF: renamed from: a () int
   public final int method_23() {
      return class_16.method_96(
         ((long)this.field_37 * this.field_37 >> 12) + ((long)this.field_38 * this.field_38 >> 12) + ((long)this.field_39 * this.field_39 >> 12)
      );
   }

   public final String toString() {
      return "AEVector3D | " + this.field_37 + ",\t" + this.field_38 + ",\t" + this.field_39;
   }
}
