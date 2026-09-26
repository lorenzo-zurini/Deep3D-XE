// $VF: renamed from: v
public final class class_5 {
   // $VF: renamed from: a int
   public int field_138;
   // $VF: renamed from: b int
   public int field_139;
   // $VF: renamed from: c int
   public int field_140;

   public class_5(int var1, int var2, int var3) {
      this.field_138 = var1;
      this.field_139 = var2;
      this.field_140 = var3;
   }

   public class_5() {
      this.field_138 = this.field_139 = this.field_140 = 0;
   }

   public class_5(class_5 var1) {
      this.field_138 = var1.field_138;
      this.field_139 = var1.field_139;
      this.field_140 = var1.field_140;
   }

   // $VF: renamed from: a (v) void
   public final void method_169(class_5 var1) {
      this.field_138 = var1.field_138;
      this.field_139 = var1.field_139;
      this.field_140 = var1.field_140;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_170(int var1, int var2, int var3) {
      this.field_138 = var1;
      this.field_139 = var2;
      this.field_140 = var3;
   }

   // $VF: renamed from: a (v) int
   public final int method_171(class_5 var1) {
      // Deep3D-PC: 64-bit products so extended view distances cannot overflow
      // (identical results wherever the original int math did not).
      return (int)(
         ((long)this.field_138 * var1.field_138 >> 12) + ((long)this.field_139 * var1.field_139 >> 12) + ((long)this.field_140 * var1.field_140 >> 12)
      );
   }

   // $VF: renamed from: b (v) int
   public final int method_172(class_5 var1) {
      return (int)(
         ((long)this.field_138 * var1.field_138 >> 12) + ((long)this.field_139 * var1.field_139 >> 12) + ((long)this.field_140 * var1.field_140 >> 12)
      );
   }

   // $VF: renamed from: a (v, v) v
   public final class_5 method_173(class_5 var1, class_5 var2) {
      var2.field_138 = (this.field_139 * var1.field_140 >> 12) - (this.field_140 * var1.field_139 >> 12);
      var2.field_139 = (this.field_140 * var1.field_138 >> 12) - (this.field_138 * var1.field_140 >> 12);
      var2.field_140 = (this.field_138 * var1.field_139 >> 12) - (this.field_139 * var1.field_138 >> 12);
      return var2;
   }

   // $VF: renamed from: b (v, v) v
   public final class_5 method_174(class_5 var1, class_5 var2) {
      var2.field_138 = this.field_138 + var1.field_138;
      var2.field_139 = this.field_139 + var1.field_139;
      var2.field_140 = this.field_140 + var1.field_140;
      return var2;
   }

   // $VF: renamed from: b (v) void
   public final void method_175(class_5 var1) {
      this.field_138 = this.field_138 + var1.field_138;
      this.field_139 = this.field_139 + var1.field_139;
      this.field_140 = this.field_140 + var1.field_140;
   }

   // $VF: renamed from: c (v, v) v
   public final class_5 method_176(class_5 var1, class_5 var2) {
      var2.field_138 = this.field_138 - var1.field_138;
      var2.field_139 = this.field_139 - var1.field_139;
      var2.field_140 = this.field_140 - var1.field_140;
      return var2;
   }

   // $VF: renamed from: c (v) void
   public final void method_177(class_5 var1) {
      this.field_138 = this.field_138 - var1.field_138;
      this.field_139 = this.field_139 - var1.field_139;
      this.field_140 = this.field_140 - var1.field_140;
   }

   // $VF: renamed from: a (int) void
   public final void method_178(int var1) {
      this.field_138 = (int)((long)var1 * this.field_138 >> 12);
      this.field_139 = (int)((long)var1 * this.field_139 >> 12);
      this.field_140 = (int)((long)var1 * this.field_140 >> 12);
   }

   // $VF: renamed from: a (int, v) v
   public final class_5 method_179(int var1, class_5 var2) {
      var2.field_138 = (this.field_138 << 12) / var1;
      var2.field_139 = (this.field_139 << 12) / var1;
      var2.field_140 = (this.field_140 << 12) / var1;
      return var2;
   }

   // $VF: renamed from: b (int) void
   public final void method_180(int var1) {
      this.field_138 = (this.field_138 << 12) / var1;
      this.field_139 = (this.field_139 << 12) / var1;
      this.field_140 = (this.field_140 << 12) / var1;
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_181(class_5 var1) {
      int var2 = class_124.method_940(
         (int)(((long)this.field_138 * this.field_138 >> 12) + ((long)this.field_139 * this.field_139 >> 12) + ((long)this.field_140 * this.field_140 >> 12))
      );
      var1.field_138 = this.field_138 * var2 >> 12;
      var1.field_139 = this.field_139 * var2 >> 12;
      var1.field_140 = this.field_140 * var2 >> 12;
      return var1;
   }

   // $VF: renamed from: a () void
   public final void method_182() {
      this.method_181(this);
   }

   // $VF: renamed from: a () int
   public final int method_183() {
      return class_124.method_941(
         ((long)this.field_138 * this.field_138 >> 12) + ((long)this.field_139 * this.field_139 >> 12) + ((long)this.field_140 * this.field_140 >> 12)
      );
   }

   public final String toString() {
      return "AEVector3D | " + this.field_138 + ",\t" + this.field_139 + ",\t" + this.field_140;
   }
}
