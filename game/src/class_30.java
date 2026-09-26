// $VF: renamed from: l
public final class class_30 extends class_29 {
   // $VF: renamed from: j int
   private int field_313;
   // $VF: renamed from: a int
   public int field_314;
   // $VF: renamed from: b int
   public int field_315;
   // $VF: renamed from: c int
   public int field_316;

   public class_30(int var1, int var2, int var3, int var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6);
      this.field_313 = var7;
      this.method_286(var1, var2, var3);
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_287(int var1, int var2, int var3) {
      return this.method_288(var1, var2, var3) ? true : super.method_287(var1, var2, var3);
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_288(int var1, int var2, int var3) {
      return var1 - this.field_314 < this.field_313
         && var1 - this.field_314 > -this.field_313
         && var2 - this.field_315 < this.field_313
         && var2 - this.field_315 > -this.field_313
         && var3 - this.field_316 < this.field_313
         && var3 - this.field_316 > -this.field_313;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_286(int var1, int var2, int var3) {
      super.method_286(var1, var2, var3);
      this.field_314 = var1 + super.field_310;
      this.field_315 = var2 + super.field_311;
      this.field_316 = var3 + super.field_312;
   }
}
