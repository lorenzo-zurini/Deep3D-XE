// $VF: renamed from: av
public abstract class class_100 extends class_97 {
   // $VF: renamed from: a v
   public static class_5 field_1289 = new class_5();
   // $VF: renamed from: d int
   public int field_1290 = 0;

   public class_100() {
   }

   public class_100(class_100 var1) {
      super(var1);
      this.field_1290 = var1.field_1290;
   }

   // $VF: renamed from: a (boolean) void
   public void method_835(boolean var1) {
      if (super.field_1281 || var1) {
         if (super.field_1278 != null) {
            super.field_1284 = super.field_1278.field_1284.method_6(super.field_1283, super.field_1284);
         } else {
            super.field_1284.method_3(super.field_1283);
         }

         field_1289 = super.field_1284.method_35(field_1289);
         int var2 = class_124.method_942(
                  class_124.method_942(class_124.method_945(field_1289.field_138), class_124.method_945(field_1289.field_139)),
                  class_124.method_945(field_1289.field_140)
               )
               * this.field_1290
            >> 12;
         field_1289 = super.field_1284.method_12(field_1289);
         super.field_1285.method_345(field_1289.field_138, field_1289.field_139, field_1289.field_140, var2);
         super.field_1281 = false;
         super.field_1282 = false;
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public final String method_838(String var1, int var2) {
      for (int var3 = 0; var3 < var2; var3++) {
         var1 = var1 + "  ";
      }

      return var1 + "\n";
   }
}
