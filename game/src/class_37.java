// $VF: renamed from: cu
public final class class_37 extends class_36 {
   // $VF: renamed from: a int
   private int field_473;
   // $VF: renamed from: b int
   private int field_474;
   // $VF: renamed from: c int
   private int field_475;

   public class_37(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      super(var1, var2, var3, var4, var5, var6);
      this.field_473 = var7 / 2;
      this.field_474 = var8 / 2;
      this.field_475 = var9 / 2;
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_403(int var1, int var2, int var3) {
      return this.method_404(var1, var2, var3) ? super.method_403(var1, var2, var3) : false;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_404(int var1, int var2, int var3) {
      return var1 > super.field_467 + super.field_470 - this.field_473
         && var1 < super.field_467 + super.field_470 + this.field_473
         && var2 > super.field_468 + super.field_471 - this.field_474
         && var2 < super.field_468 + super.field_471 + this.field_474
         && var3 > super.field_469 + super.field_472 - this.field_475
         && var3 < super.field_469 + super.field_472 + this.field_475;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_402(int var1, int var2, int var3) {
      super.method_402(var1, var2, var3);
   }
}
