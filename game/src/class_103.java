// $VF: renamed from: v
public class class_103 extends class_102 {
   // $VF: renamed from: a af
   public class_102 field_1345;

   public class_103() {
      this.field_1345 = null;
   }

   public class_103(class_103 var1) {
      super(var1);

      for (class_102 var2 = var1.field_1345; var2 != null; var2 = var2.field_1337) {
         this.method_879(var2.method_840());
      }
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_103(this);
   }

   // $VF: renamed from: a (af) void
   public final void method_879(class_102 var1) {
      if (var1 != null) {
         var1.field_1336 = this;
         var1.field_1337 = this.field_1345;
         this.field_1345 = var1;
      }
   }

   // $VF: renamed from: a (an, t) void
   public final void method_837(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         switch (2) { // Deep3D-PC: no culling (class_108)
            case 1:
               for (class_102 var5 = this.field_1345; var5 != null; var5 = var5.field_1337) {
                  var5.method_837(var1, var2);
               }
               break;
            case 2:
               for (class_102 var4 = this.field_1345; var4 != null; var4 = var4.field_1337) {
                  var4.method_838(var1, var2);
               }

               return;
         }
      }
   }

   // $VF: renamed from: b (an, t) void
   public final void method_838(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         for (class_102 var3 = this.field_1345; var3 != null; var3 = var3.field_1337) {
            var3.method_838(var1, var2);
         }
      }
   }

   // $VF: renamed from: a (boolean) void
   public void method_839(boolean var1) {
      if (super.field_1340 || var1) {
         if (super.field_1339 || var1) {
            if (super.field_1336 != null) {
               super.field_1342 = super.field_1336.field_1342.method_473(super.field_1341, super.field_1342);
            } else {
               super.field_1342.method_470(super.field_1341);
            }
         }

         for (class_102 var2 = this.field_1345; var2 != null; var2 = var2.field_1337) {
            var2.method_839(super.field_1339 || var1);
         }

         super.field_1343.method_89(super.field_1342.field_698, super.field_1342.field_699, super.field_1342.field_700, 0);

         for (class_102 var3 = this.field_1345; var3 != null; var3 = var3.field_1337) {
            super.field_1343.method_87(var3.field_1343);
         }

         super.field_1340 = false;
         super.field_1339 = false;
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public final String method_842(String var1, int var2) {
      for (int var3 = 0; var3 < var2; var3++) {
         var1 = var1 + "  ";
      }

      var1 = var1
         + " |\t"
         + super.field_1343.field_148.field_37
         + "\t\t"
         + super.field_1343.field_148.field_38
         + "\t\t"
         + super.field_1343.field_148.field_39
         + "\t\t"
         + super.field_1343.field_149
         + "\n";
      var2++;

      for (class_102 var6 = this.field_1345; var6 != null; var6 = var6.field_1337) {
         var1 = var6.method_842(var1, var2);
      }

      return var1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_876(int var1, int var2) {
      for (class_102 var3 = this.field_1345; var3 != null; var3 = var3.field_1337) {
         var3.method_876(var1, var2);
      }
   }

   // $VF: renamed from: a (byte) void
   public final void method_877(byte var1) {
      for (class_102 var2 = this.field_1345; var2 != null; var2 = var2.field_1337) {
         var2.method_877(var1);
      }
   }

   // $VF: renamed from: a () void
   public final void method_878() {
      for (class_102 var1 = this.field_1345; var1 != null; var1 = var1.field_1337) {
         var1.method_878();
      }
   }
}
