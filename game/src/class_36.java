// $VF: renamed from: dp
public abstract class class_36 {
   // $VF: renamed from: a dp[]
   public class_36[] field_465;
   // $VF: renamed from: a v
   private static class_5 field_466 = new class_5();
   // $VF: renamed from: d int
   public int field_467;
   // $VF: renamed from: e int
   public int field_468;
   // $VF: renamed from: f int
   public int field_469;
   // $VF: renamed from: g int
   public int field_470;
   // $VF: renamed from: h int
   public int field_471;
   // $VF: renamed from: i int
   public int field_472;

   public class_36(int var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_467 = var1;
      this.field_468 = var2;
      this.field_469 = var3;
      this.field_470 = var4;
      this.field_471 = var5;
      this.field_472 = var6;
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_401(class_5 var1) {
      field_466.method_170(var1.field_138 - this.field_467, var1.field_139 - this.field_468, var1.field_140 - this.field_469);
      field_466.method_182();
      return field_466;
   }

   // $VF: renamed from: a (int, int, int) void
   public void method_402(int var1, int var2, int var3) {
      if (this.field_465 != null) {
         for (int var4 = 0; var4 < this.field_465.length; var4++) {
            this.field_465[var4].method_402(var1, var2, var3);
         }
      }

      this.field_467 = var1;
      this.field_468 = var2;
      this.field_469 = var3;
   }

   // $VF: renamed from: a (int, int, int) boolean
   public boolean method_403(int var1, int var2, int var3) {
      if (this.field_465 != null) {
         for (int var4 = 0; var4 < this.field_465.length; var4++) {
            if (this.field_465[var4].method_403(this.field_467, this.field_468, this.field_469)) {
               return true;
            }
         }
      }

      return false;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public boolean method_404(int var1, int var2, int var3) {
      return false;
   }
}
