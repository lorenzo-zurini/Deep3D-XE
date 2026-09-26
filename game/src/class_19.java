// $VF: renamed from: dn
public final class class_19 {
   // $VF: renamed from: a int
   public int field_165;
   // $VF: renamed from: b int
   public int field_166;
   // $VF: renamed from: c int
   public int field_167;
   // $VF: renamed from: d int
   public int field_168;
   // $VF: renamed from: k int
   private int field_169;
   // $VF: renamed from: e int
   public int field_170;
   // $VF: renamed from: f int
   public int field_171;
   // $VF: renamed from: g int
   public int field_172;
   // $VF: renamed from: h int
   public int field_173;
   // $VF: renamed from: i int
   public int field_174;
   // $VF: renamed from: j int
   public int field_175;
   // $VF: renamed from: a boolean
   public boolean field_176;

   public class_19(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      this.field_166 = var1;
      this.field_165 = var2;
      this.field_168 = var3;
      this.field_169 = var4;
      this.field_170 = var5;
      this.field_171 = var6;
      this.field_172 = var7;
      this.field_173 = var8;
      this.field_174 = var9;
      this.field_167 = var4 + (var5 - var4) / 2;
      this.field_176 = false;
   }

   // $VF: renamed from: a () int
   public final int method_116() {
      return this.field_167 * this.field_175;
   }

   // $VF: renamed from: a (int) int
   public final int method_117(int var1) {
      if (var1 == 0) {
         return this.field_171;
      } else if (var1 == 1) {
         return this.field_172;
      } else {
         return var1 == 2 ? this.field_173 : this.field_174;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_118() {
      return this.field_165 == 0 || this.field_165 == 1 || this.field_165 == 2;
   }

   // $VF: renamed from: a (int, int) dn
   public final class_19 method_119(int var1, int var2) {
      class_19 var3;
      (var3 = this.method_121()).field_167 = var2;
      var3.field_175 = var1;
      return var3;
   }

   // $VF: renamed from: a () dn
   public final class_19 method_120() {
      return this.method_119(1, this.field_167);
   }

   // $VF: renamed from: b () dn
   public final class_19 method_121() {
      class_19 var1;
      (var1 = new class_19(
            this.field_166, this.field_165, this.field_168, this.field_169, this.field_170, this.field_171, this.field_172, this.field_173, this.field_174
         ))
         .field_176 = this.field_176;
      var1.field_167 = this.field_167;
      return var1;
   }

   // $VF: renamed from: a (dn) boolean
   public final boolean method_122(class_19 var1) {
      return var1 == null ? false : this.field_166 == var1.field_166;
   }

   public final String toString() {
      return this.field_166
         + " "
         + this.field_165
         + " "
         + this.field_168
         + " "
         + this.field_169
         + " "
         + this.field_170
         + " "
         + this.field_171
         + " "
         + this.field_172
         + " "
         + this.field_173
         + " "
         + this.field_174;
   }

   // $VF: renamed from: a (ao) void
   public final void method_123(class_86 var1) {
      this.field_167 = this.field_169 + (int)((10 - var1.field_1139) / 10.0F * (this.field_170 - this.field_169));
      if (this.field_176) {
         this.field_167 = (int)(this.field_167 / 1.25F);
      }
   }

   // $VF: renamed from: a () void
   public final void method_124() {
      this.method_123(class_21.method_180());
      this.field_167 = (int)(this.field_167 / 1.25F);
   }
}
