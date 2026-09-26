// $VF: renamed from: cv
public final class class_31 extends class_29 {
   // $VF: renamed from: a int
   private int field_317;
   // $VF: renamed from: b int
   private int field_318;
   // $VF: renamed from: c int
   private int field_319;

   public class_31(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      super(var1, var2, var3, var4, var5, var6);
      this.field_317 = var7 / 2;
      this.field_318 = var8 / 2;
      this.field_319 = var9 / 2;
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_287(int var1, int var2, int var3) {
      return this.method_288(var1, var2, var3) ? super.method_287(var1, var2, var3) : false;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_288(int var1, int var2, int var3) {
      return var1 > super.field_307 + super.field_310 - this.field_317
         && var1 < super.field_307 + super.field_310 + this.field_317
         && var2 > super.field_308 + super.field_311 - this.field_318
         && var2 < super.field_308 + super.field_311 + this.field_318
         && var3 > super.field_309 + super.field_312 - this.field_319
         && var3 < super.field_309 + super.field_312 + this.field_319;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_286(int var1, int var2, int var3) {
      super.method_286(var1, var2, var3);
   }
}
