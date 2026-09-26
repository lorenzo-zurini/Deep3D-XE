// $VF: renamed from: dp
public abstract class class_29 {
   // $VF: renamed from: a dp[]
   public class_29[] field_305;
   // $VF: renamed from: a x
   private static class_3 field_306 = new class_3();
   // $VF: renamed from: d int
   public int field_307;
   // $VF: renamed from: e int
   public int field_308;
   // $VF: renamed from: f int
   public int field_309;
   // $VF: renamed from: g int
   public int field_310;
   // $VF: renamed from: h int
   public int field_311;
   // $VF: renamed from: i int
   public int field_312;

   public class_29(int var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_307 = var1;
      this.field_308 = var2;
      this.field_309 = var3;
      this.field_310 = var4;
      this.field_311 = var5;
      this.field_312 = var6;
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_285(class_3 var1) {
      field_306.method_10(var1.field_37 - this.field_307, var1.field_38 - this.field_308, var1.field_39 - this.field_309);
      field_306.method_22();
      return field_306;
   }

   // $VF: renamed from: a (int, int, int) void
   public void method_286(int var1, int var2, int var3) {
      if (this.field_305 != null) {
         for (int var4 = 0; var4 < this.field_305.length; var4++) {
            this.field_305[var4].method_286(var1, var2, var3);
         }
      }

      this.field_307 = var1;
      this.field_308 = var2;
      this.field_309 = var3;
   }

   // $VF: renamed from: a (int, int, int) boolean
   public boolean method_287(int var1, int var2, int var3) {
      if (this.field_305 != null) {
         for (int var4 = 0; var4 < this.field_305.length; var4++) {
            if (this.field_305[var4].method_287(this.field_307, this.field_308, this.field_309)) {
               return true;
            }
         }
      }

      return false;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public boolean method_288(int var1, int var2, int var3) {
      return false;
   }
}
