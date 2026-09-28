// $VF: renamed from: df
public class class_98 extends class_91 {
   // $VF: renamed from: c x
   public static class_3 field_1299 = new class_3();
   // $VF: renamed from: e int
   public int field_1300;
   // $VF: renamed from: f int
   public int field_1301;
   // $VF: renamed from: g int
   public int field_1302;

   public class_98(int var1, class_108 var2, int var3, int var4, int var5) {
      super(var1, false, new class_37(2000.0F, 0, 0), var2, var3, var4, var5);
      this.field_1300 = var3;
      this.field_1301 = var4;
      this.field_1302 = var5;
      if (var2 != null) {
         var2.deep3dNoCull = true; // Deep3D-PC: structures are never culled
      }
   }

   // $VF: renamed from: a (long) void
   public void method_805(long var1) {
   }

   // $VF: renamed from: a (x) x
   public class_3 method_799(class_3 var1) {
      var1.method_10(this.field_1300, this.field_1301, this.field_1302);
      return var1;
   }

   // $VF: renamed from: c () void
   public void method_809() {
      class_84.field_1110.method_25(super.field_1226);
   }

   // $VF: renamed from: a (int, int, int) boolean
   public boolean method_806(int var1, int var2, int var3) {
      return false;
   }
}
