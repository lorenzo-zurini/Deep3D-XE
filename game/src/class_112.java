// $VF: renamed from: ca
public class class_112 extends class_108 {
   // $VF: renamed from: a n
   public class_9 field_1409;
   // $VF: renamed from: a ax[]
   public class_108[] field_1410;
   // $VF: renamed from: d ax
   public class_108 field_1411;
   // $VF: renamed from: c x
   public static class_3 field_1412;

   public class_112(class_9 var1, class_108 var2, int var3) {
      this.field_1409 = var1;
      field_1412 = new class_3();
      if (var2 == null) {
         this.field_1410 = null;
      } else {
         this.field_1410 = new class_108[var1.field_78.length];

         for (int var4 = 0; var4 < this.field_1410.length; var4++) {
            this.field_1410[var4] = (class_108)var2.method_840();
            this.field_1410[var4].field_1367 = 2;
         }
      }
   }

   // $VF: renamed from: c () void
   public void method_894() {
      this.field_1409.method_43();
      this.field_1409 = null;
   }

   // $VF: renamed from: d () void
   public void method_887() {
      this.field_1409.method_50();
      if (this.field_1409.field_92 && this.field_1410 != null) {
         int var1 = 0;

         for (int var2 = 0; var2 < this.field_1409.field_78.length; var2++) {
            if (this.field_1409.field_78[var2].field_37 != 50000) {
               this.field_1410[var2].method_846(this.field_1409.field_78[var2]);
               field_1412.method_9(this.field_1409.field_79[var2]);
               field_1412.method_22();
               this.field_1410[var2].field_1341.method_512(field_1412);
               class_84.field_1110.method_25(this.field_1410[var2]);
            } else {
               var1++;
            }
         }

         if (var1 >= this.field_1409.field_83.length) {
            this.field_1409.field_92 = false;
         }
      }
   }

   // $VF: renamed from: a (long) void
   public void method_895(long var1) {
      this.field_1409.method_49(var1);
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return null;
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
   }
}
