// $VF: renamed from: c
public final class class_104 extends class_103 {
   // $VF: renamed from: a dl[]
   public class_0[] field_1346 = null;

   // $VF: renamed from: a (dl) void
   public final void method_880(class_0 var1) {
      if (this.field_1346 == null) {
         this.field_1346 = new class_0[1];
         this.field_1346[0] = var1;
      } else {
         class_0[] var2 = new class_0[this.field_1346.length + 1];
         System.arraycopy(this.field_1346, 0, var2, 0, this.field_1346.length);
         var2[this.field_1346.length] = var1;
         this.field_1346 = var2;
      }
   }

   // $VF: renamed from: a (boolean) void
   public final void method_839(boolean var1) {
      if (this.field_1346 != null) {
         if (super.field_1340 || var1) {
            if (super.field_1339 || var1) {
               if (super.field_1336 != null) {
                  super.field_1342 = super.field_1336.field_1342.method_473(super.field_1341, super.field_1342);
               } else {
                  super.field_1342.method_470(super.field_1341);
               }
            }

            for (class_102 var2 = super.field_1345; var2 != null; var2 = var2.field_1337) {
               var2.method_839(super.field_1339 || var1);
            }

            super.field_1343.method_89(super.field_1342.field_698, super.field_1342.field_699, super.field_1342.field_700, 0);

            for (class_102 var3 = super.field_1345; var3 != null; var3 = var3.field_1337) {
               super.field_1343.method_87(var3.field_1343);
            }

            super.field_1340 = false;
            super.field_1339 = false;
         }

         for (int var4 = this.field_1346.length - 1; var4 >= 0; var4--) {
            if (this.field_1346[var4].method_1()) {
               this.field_1346[var4].method_0();
            }
         }
      }

      if (super.field_1340 || var1) {
         if (super.field_1339 || var1) {
            if (super.field_1336 != null) {
               super.field_1342 = super.field_1336.field_1342.method_473(super.field_1341, super.field_1342);
            } else {
               super.field_1342.method_470(super.field_1341);
            }
         }

         for (class_102 var5 = super.field_1345; var5 != null; var5 = var5.field_1337) {
            var5.method_839(super.field_1339 || var1);
         }

         super.field_1343.method_89(super.field_1342.field_698, super.field_1342.field_699, super.field_1342.field_700, 0);

         for (class_102 var6 = super.field_1345; var6 != null; var6 = var6.field_1337) {
            super.field_1343.method_87(var6.field_1343);
         }

         super.field_1340 = false;
         super.field_1339 = false;
      }
   }
}
