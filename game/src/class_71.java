// $VF: renamed from: s
public final class class_71 implements class_0 {
   // $VF: renamed from: a ae
   public class_97 field_1031;
   // $VF: renamed from: b ae
   public class_97 field_1032;
   // $VF: renamed from: a int
   public int field_1033;
   // $VF: renamed from: c ae
   public class_97 field_1034;
   // $VF: renamed from: a v
   public static class_5 field_1035;
   // $VF: renamed from: b v
   public static class_5 field_1036;
   // $VF: renamed from: c v
   public static class_5 field_1037;
   // $VF: renamed from: d v
   public class_5 field_1038;
   // $VF: renamed from: a boolean
   public boolean field_1039;

   public class_71(class_97 var1, class_97 var2) {
      this(var1, var2, null, 0);
   }

   public class_71(class_97 var1, class_97 var2, class_5 var3, int var4) {
      this.field_1031 = var1;
      this.field_1034 = var2;
      this.field_1033 = var4;
      this.field_1039 = true;
      this.field_1038 = var3;
      if (field_1035 == null) {
         field_1035 = new class_5();
      }

      if (field_1036 == null) {
         field_1036 = new class_5();
      }

      if (field_1037 == null) {
         field_1037 = new class_5();
      }

      if (var3 != null) {
         this.field_1038.method_182();
      }

      this.field_1032 = var1;

      while (this.field_1032.field_1278 != null) {
         this.field_1032 = this.field_1032.field_1278;
      }

      Object var5 = var2;

      while (((class_97)var5).field_1278 != null) {
         var5 = ((class_97)var5).field_1278;
      }

      if (var5 == this.field_1032) {
         this.field_1032 = null;
      }
   }

   // $VF: renamed from: a (v, int) void
   public final void method_689(class_5 var1, int var2) {
      this.field_1038 = var1;
      this.field_1033 = var2;
      if (var1 != null) {
         this.field_1038.method_182();
      }
   }

   // $VF: renamed from: a () void
   public final void method_0() {
      if (this.field_1039) {
         if (this.field_1032 != null) {
            this.field_1032.method_835(false);
         }

         field_1035 = this.field_1031.method_845(field_1035);
         field_1035 = this.field_1034.field_1278.field_1284.method_43(field_1035);
         field_1036 = this.field_1034.method_844(field_1036);
         field_1036.method_177(field_1035);
         field_1036.method_182();
         if (this.field_1038 != null) {
            field_1037.method_169(this.field_1038);
         } else {
            field_1037.method_170(0, 4096, 0);
         }

         field_1035 = field_1037.method_173(field_1036, field_1035);
         field_1035.method_182();
         if (class_124.method_945(field_1035.field_138 + field_1035.field_139 + field_1035.field_140) < 4) {
            field_1037.method_170(4096, 0, 0);
            field_1035 = field_1037.method_173(field_1036, field_1035);
            field_1035.method_182();
         }

         switch (this.field_1033) {
            case 0:
            case 2:
               field_1037 = field_1036.method_173(field_1035, field_1037);
               break;
            case 1:
               field_1036 = field_1035.method_173(field_1037, field_1036);
         }

         this.field_1034.method_868(field_1035, field_1037, field_1036);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_1() {
      return this.field_1039;
   }
}
