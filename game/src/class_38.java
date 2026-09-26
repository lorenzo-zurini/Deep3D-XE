// $VF: renamed from: m
public final class class_38 extends class_36 {
   // $VF: renamed from: j int
   private int field_476;
   // $VF: renamed from: a int
   public int field_477;
   // $VF: renamed from: b int
   public int field_478;
   // $VF: renamed from: c int
   public int field_479;

   public class_38(int var1, int var2, int var3, int var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6);
      this.field_476 = var7;
      this.method_402(var1, var2, var3);
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_403(int var1, int var2, int var3) {
      return this.method_404(var1, var2, var3) ? true : super.method_403(var1, var2, var3);
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_404(int var1, int var2, int var3) {
      return var1 - this.field_477 < this.field_476
         && var1 - this.field_477 > -this.field_476
         && var2 - this.field_478 < this.field_476
         && var2 - this.field_478 > -this.field_476
         && var3 - this.field_479 < this.field_476
         && var3 - this.field_479 > -this.field_476;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_402(int var1, int var2, int var3) {
      super.method_402(var1, var2, var3);
      this.field_477 = var1 + super.field_470;
      this.field_478 = var2 + super.field_471;
      this.field_479 = var3 + super.field_472;
   }
}
