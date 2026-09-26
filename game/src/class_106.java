// $VF: renamed from: ca
public class class_106 extends class_101 {
   // $VF: renamed from: a o
   public class_19 field_1325;
   // $VF: renamed from: a ay[]
   public class_101[] field_1326;
   // $VF: renamed from: d ay
   public class_101 field_1327;
   // $VF: renamed from: c v
   public static class_5 field_1328;

   public class_106(class_19 var1, class_101 var2, int var3) {
      this.field_1325 = var1;
      field_1328 = new class_5();
      if (var2 == null) {
         this.field_1326 = null;
      } else {
         this.field_1326 = new class_101[var1.field_279.length];

         for (int var4 = 0; var4 < this.field_1326.length; var4++) {
            this.field_1326[var4] = (class_101)var2.method_836();
            this.field_1326[var4].field_1294 = 2;
         }
      }
   }

   // $VF: renamed from: d () void
   public void method_884() {
      this.field_1325.method_281();
      this.field_1325 = null;
   }

   // $VF: renamed from: c () void
   public void method_878() {
      this.field_1325.method_288();
      if (this.field_1325.field_293 && this.field_1326 != null) {
         int var1 = 0;

         for (int var2 = 0; var2 < this.field_1325.field_279.length; var2++) {
            if (this.field_1325.field_279[var2].field_138 != 50000) {
               this.field_1326[var2].method_842(this.field_1325.field_279[var2]);
               field_1328.method_169(this.field_1325.field_280[var2]);
               field_1328.method_182();
               this.field_1326[var2].field_1283.method_44(field_1328);
               class_41.field_527.method_265(this.field_1326[var2]);
            } else {
               var1++;
            }
         }

         if (var1 >= this.field_1325.field_284.length) {
            this.field_1325.field_293 = false;
         }
      }
   }

   // $VF: renamed from: a (long) void
   public void method_885(long var1) {
      this.field_1325.method_287(var1);
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return null;
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
   }
}
