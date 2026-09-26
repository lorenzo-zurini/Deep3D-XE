// $VF: renamed from: s
public final class class_5 implements class_0 {
   // $VF: renamed from: a af
   public class_102 field_45;
   // $VF: renamed from: b af
   public class_102 field_46;
   // $VF: renamed from: a int
   public int field_47;
   // $VF: renamed from: c af
   public class_102 field_48;
   // $VF: renamed from: a x
   public static class_3 field_49;
   // $VF: renamed from: b x
   public static class_3 field_50;
   // $VF: renamed from: c x
   public static class_3 field_51;
   // $VF: renamed from: d x
   public class_3 field_52;
   // $VF: renamed from: a boolean
   public boolean field_53;

   public class_5(class_102 var1, class_102 var2) {
      this(var1, var2, null, 0);
   }

   public class_5(class_102 var1, class_102 var2, class_3 var3, int var4) {
      this.field_45 = var1;
      this.field_48 = var2;
      this.field_47 = var4;
      this.field_53 = true;
      this.field_52 = var3;
      if (field_49 == null) {
         field_49 = new class_3();
      }

      if (field_50 == null) {
         field_50 = new class_3();
      }

      if (field_51 == null) {
         field_51 = new class_3();
      }

      if (var3 != null) {
         this.field_52.method_22();
      }

      this.field_46 = var1;

      while (this.field_46.field_1336 != null) {
         this.field_46 = this.field_46.field_1336;
      }

      Object var5 = var2;

      while (((class_102)var5).field_1336 != null) {
         var5 = ((class_102)var5).field_1336;
      }

      if (var5 == this.field_46) {
         this.field_46 = null;
      }
   }

   // $VF: renamed from: a (x, int) void
   public final void method_31(class_3 var1, int var2) {
      this.field_52 = var1;
      this.field_47 = var2;
      if (var1 != null) {
         this.field_52.method_22();
      }
   }

   // $VF: renamed from: a () void
   public final void method_0() {
      if (this.field_53) {
         if (this.field_46 != null) {
            this.field_46.method_839(false);
         }

         field_49 = this.field_45.method_849(field_49);
         field_49 = this.field_48.field_1336.field_1342.method_511(field_49);
         field_50 = this.field_48.method_848(field_50);
         field_50.method_17(field_49);
         field_50.method_22();
         if (this.field_52 != null) {
            field_51.method_9(this.field_52);
         } else {
            field_51.method_10(0, 4096, 0);
         }

         field_49 = field_51.method_13(field_50, field_49);
         field_49.method_22();
         if (class_16.method_100(field_49.field_37 + field_49.field_38 + field_49.field_39) < 4) {
            field_51.method_10(4096, 0, 0);
            field_49 = field_51.method_13(field_50, field_49);
            field_49.method_22();
         }

         switch (this.field_47) {
            case 0:
            case 2:
               field_51 = field_50.method_13(field_49, field_51);
               break;
            case 1:
               field_50 = field_49.method_13(field_51, field_50);
         }

         this.field_48.method_872(field_49, field_51, field_50);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_1() {
      return this.field_53;
   }
}
