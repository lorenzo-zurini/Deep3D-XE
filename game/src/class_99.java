// $VF: renamed from: c
public final class class_99 extends class_98 {
   // $VF: renamed from: a dl[]
   public class_0[] field_1288 = null;

   // $VF: renamed from: a (dl) void
   public final void method_876(class_0 var1) {
      if (this.field_1288 == null) {
         this.field_1288 = new class_0[1];
         this.field_1288[0] = var1;
      } else {
         class_0[] var2 = new class_0[this.field_1288.length + 1];
         System.arraycopy(this.field_1288, 0, var2, 0, this.field_1288.length);
         var2[this.field_1288.length] = var1;
         this.field_1288 = var2;
      }
   }

   // $VF: renamed from: a (boolean) void
   public final void method_835(boolean var1) {
      if (this.field_1288 != null) {
         if (super.field_1282 || var1) {
            if (super.field_1281 || var1) {
               if (super.field_1278 != null) {
                  super.field_1284 = super.field_1278.field_1284.method_6(super.field_1283, super.field_1284);
               } else {
                  super.field_1284.method_3(super.field_1283);
               }
            }

            for (class_97 var2 = super.field_1287; var2 != null; var2 = var2.field_1279) {
               var2.method_835(super.field_1281 || var1);
            }

            super.field_1285.method_345(super.field_1284.field_13, super.field_1284.field_14, super.field_1284.field_15, 0);

            for (class_97 var3 = super.field_1287; var3 != null; var3 = var3.field_1279) {
               super.field_1285.method_343(var3.field_1285);
            }

            super.field_1282 = false;
            super.field_1281 = false;
         }

         for (int var4 = this.field_1288.length - 1; var4 >= 0; var4--) {
            if (this.field_1288[var4].method_1()) {
               this.field_1288[var4].method_0();
            }
         }
      }

      if (super.field_1282 || var1) {
         if (super.field_1281 || var1) {
            if (super.field_1278 != null) {
               super.field_1284 = super.field_1278.field_1284.method_6(super.field_1283, super.field_1284);
            } else {
               super.field_1284.method_3(super.field_1283);
            }
         }

         for (class_97 var5 = super.field_1287; var5 != null; var5 = var5.field_1279) {
            var5.method_835(super.field_1281 || var1);
         }

         super.field_1285.method_345(super.field_1284.field_13, super.field_1284.field_14, super.field_1284.field_15, 0);

         for (class_97 var6 = super.field_1287; var6 != null; var6 = var6.field_1279) {
            super.field_1285.method_343(var6.field_1285);
         }

         super.field_1282 = false;
         super.field_1281 = false;
      }
   }
}
