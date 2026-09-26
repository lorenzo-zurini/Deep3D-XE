// $VF: renamed from: dn
public final class class_51 {
   // $VF: renamed from: a int
   public int field_710;
   // $VF: renamed from: b int
   public int field_711;
   // $VF: renamed from: c int
   public int field_712;
   // $VF: renamed from: d int
   public int field_713;
   // $VF: renamed from: k int
   private int field_714;
   // $VF: renamed from: e int
   public int field_715;
   // $VF: renamed from: f int
   public int field_716;
   // $VF: renamed from: g int
   public int field_717;
   // $VF: renamed from: h int
   public int field_718;
   // $VF: renamed from: i int
   public int field_719;
   // $VF: renamed from: j int
   public int field_720;
   // $VF: renamed from: a boolean
   public boolean field_721;

   public class_51(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      this.field_711 = var1;
      this.field_710 = var2;
      this.field_713 = var3;
      this.field_714 = var4;
      this.field_715 = var5;
      this.field_716 = var6;
      this.field_717 = var7;
      this.field_718 = var8;
      this.field_719 = var9;
      this.field_712 = var4 + (var5 - var4) / 2;
      this.field_721 = false;
   }

   // $VF: renamed from: a () int
   public final int method_501() {
      return this.field_712 * this.field_720;
   }

   // $VF: renamed from: a (int) int
   public final int method_502(int var1) {
      if (var1 == 0) {
         return this.field_716;
      } else if (var1 == 1) {
         return this.field_717;
      } else {
         return var1 == 2 ? this.field_718 : this.field_719;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_503() {
      return this.field_710 == 0 || this.field_710 == 1 || this.field_710 == 2;
   }

   // $VF: renamed from: a (int, int) dn
   public final class_51 method_504(int var1, int var2) {
      class_51 var3;
      (var3 = this.method_506()).field_712 = var2;
      var3.field_720 = var1;
      return var3;
   }

   // $VF: renamed from: a () dn
   public final class_51 method_505() {
      return this.method_504(1, this.field_712);
   }

   // $VF: renamed from: b () dn
   public final class_51 method_506() {
      class_51 var1;
      (var1 = new class_51(
            this.field_711, this.field_710, this.field_713, this.field_714, this.field_715, this.field_716, this.field_717, this.field_718, this.field_719
         ))
         .field_721 = this.field_721;
      var1.field_712 = this.field_712;
      return var1;
   }

   // $VF: renamed from: a (dn) boolean
   public final boolean method_507(class_51 var1) {
      return var1 == null ? false : this.field_711 == var1.field_711;
   }

   public final String toString() {
      return this.field_711
         + " "
         + this.field_710
         + " "
         + this.field_713
         + " "
         + this.field_714
         + " "
         + this.field_715
         + " "
         + this.field_716
         + " "
         + this.field_717
         + " "
         + this.field_718
         + " "
         + this.field_719;
   }

   // $VF: renamed from: a (an) void
   public final void method_508(class_60 var1) {
      this.field_712 = this.field_714 + (int)((10 - var1.field_833) / 10.0F * (this.field_715 - this.field_714));
      if (this.field_721) {
         this.field_712 = (int)(this.field_712 / 1.25F);
      }
   }

   // $VF: renamed from: a () void
   public final void method_509() {
      this.method_508(class_3.method_110());
      this.field_712 = (int)(this.field_712 / 1.25F);
   }
}
