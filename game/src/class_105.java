// $VF: renamed from: av
public abstract class class_105 extends class_102 {
   // $VF: renamed from: a x
   public static class_3 field_1347 = new class_3();
   // $VF: renamed from: f int
   public int field_1348 = 0;

   public class_105() {
   }

   public class_105(class_105 var1) {
      super(var1);
      this.field_1348 = var1.field_1348;
   }

   // $VF: renamed from: a (boolean) void
   public void method_839(boolean var1) {
      if (super.field_1339 || var1) {
         if (super.field_1336 != null) {
            super.field_1342 = super.field_1336.field_1342.method_473(super.field_1341, super.field_1342);
         } else {
            super.field_1342.method_470(super.field_1341);
         }

         field_1347 = super.field_1342.method_502(field_1347);
         int var2 = class_16.method_97(
                  class_16.method_97(class_16.method_100(field_1347.field_37), class_16.method_100(field_1347.field_38)),
                  class_16.method_100(field_1347.field_39)
               )
               * this.field_1348
            >> 12;
         field_1347 = super.field_1342.method_479(field_1347);
         super.field_1343.method_89(field_1347.field_37, field_1347.field_38, field_1347.field_39, var2);
         super.field_1339 = false;
         super.field_1340 = false;
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public final String method_842(String var1, int var2) {
      for (int var3 = 0; var3 < var2; var3++) {
         var1 = var1 + "  ";
      }

      return var1 + "\n";
   }
}
