// $VF: renamed from: u
public class class_98 extends class_97 {
   // $VF: renamed from: a ae
   public class_97 field_1287;

   public class_98() {
      this.field_1287 = null;
   }

   public class_98(class_98 var1) {
      super(var1);

      for (class_97 var2 = var1.field_1287; var2 != null; var2 = var2.field_1279) {
         this.method_875(var2.method_836());
      }
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_98(this);
   }

   // $VF: renamed from: a (ae) void
   public final void method_875(class_97 var1) {
      if (var1 != null) {
         var1.field_1278 = this;
         var1.field_1279 = this.field_1287;
         this.field_1287 = var1;
      }
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         switch (var1.method_898(super.field_1285)) {
            case 1:
               for (class_97 var5 = this.field_1287; var5 != null; var5 = var5.field_1279) {
                  var5.method_833(var1, var2);
               }
               break;
            case 2:
               for (class_97 var4 = this.field_1287; var4 != null; var4 = var4.field_1279) {
                  var4.method_834(var1, var2);
               }

               return;
         }
      }
   }

   // $VF: renamed from: b (am, t) void
   public final void method_834(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         for (class_97 var3 = this.field_1287; var3 != null; var3 = var3.field_1279) {
            var3.method_834(var1, var2);
         }
      }
   }

   // $VF: renamed from: a (boolean) void
   public void method_835(boolean var1) {
      if (super.field_1282 || var1) {
         if (super.field_1281 || var1) {
            if (super.field_1278 != null) {
               super.field_1284 = super.field_1278.field_1284.method_6(super.field_1283, super.field_1284);
            } else {
               super.field_1284.method_3(super.field_1283);
            }
         }

         for (class_97 var2 = this.field_1287; var2 != null; var2 = var2.field_1279) {
            var2.method_835(super.field_1281 || var1);
         }

         super.field_1285.method_345(super.field_1284.field_13, super.field_1284.field_14, super.field_1284.field_15, 0);

         for (class_97 var3 = this.field_1287; var3 != null; var3 = var3.field_1279) {
            super.field_1285.method_343(var3.field_1285);
         }

         super.field_1282 = false;
         super.field_1281 = false;
      }
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public final String method_838(String var1, int var2) {
      for (int var3 = 0; var3 < var2; var3++) {
         var1 = var1 + "  ";
      }

      var1 = var1
         + " |\t"
         + super.field_1285.field_398.field_138
         + "\t\t"
         + super.field_1285.field_398.field_139
         + "\t\t"
         + super.field_1285.field_398.field_140
         + "\t\t"
         + super.field_1285.field_399
         + "\n";
      var2++;

      for (class_97 var6 = this.field_1287; var6 != null; var6 = var6.field_1279) {
         var1 = var6.method_838(var1, var2);
      }

      return var1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_872(int var1, int var2) {
      for (class_97 var3 = this.field_1287; var3 != null; var3 = var3.field_1279) {
         var3.method_872(var1, var2);
      }
   }

   // $VF: renamed from: a (byte) void
   public final void method_873(byte var1) {
      for (class_97 var2 = this.field_1287; var2 != null; var2 = var2.field_1279) {
         var2.method_873(var1);
      }
   }

   // $VF: renamed from: a () void
   public final void method_874() {
      for (class_97 var1 = this.field_1287; var1 != null; var1 = var1.field_1279) {
         var1.method_874();
      }
   }
}
