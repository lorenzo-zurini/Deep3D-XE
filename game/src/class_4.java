// $VF: renamed from: t
public final class class_4 {
   // $VF: renamed from: a an
   public class_106 field_40 = null;
   // $VF: renamed from: a af
   private class_102 field_41;
   // $VF: renamed from: a q[]
   private class_6[] field_42 = new class_6[1];
   // $VF: renamed from: a boolean[]
   private boolean[] field_43;
   // $VF: renamed from: a b
   private class_71 field_44;

   public class_4(class_71 var1) {
      this.field_42[0] = new class_6();
      this.field_43 = new boolean[1];
      this.field_43[0] = true;
      this.field_44 = var1;
   }

   // $VF: renamed from: a (an) void
   public final void method_24(class_106 var1) {
      this.field_40 = var1;
      this.field_40.method_885();
      this.field_41 = this.field_40;

      while (this.field_41.field_1336 != null) {
         this.field_41 = this.field_41.field_1336;
      }
   }

   // $VF: renamed from: a (af) void
   public final void method_25(class_102 var1) {
      try {
         if (var1 != null && this.field_42 != null && this.field_40 != null) {
            var1.method_839(false);
            if (this.field_41 != null) {
               this.field_41.method_839(false);
            } else {
               this.field_40.method_839(false);
            }

            var1.method_837(this.field_40, this);
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_26() {
      for (int var1 = 0; var1 < this.field_42.length; var1++) {
         this.field_42[var1].method_35();
         if (this.field_43[var1]) {
            this.field_44.method_685();
         }

         this.field_42[var1].method_33();
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_27(long var1) {
      for (int var3 = 0; var3 < this.field_42.length; var3++) {
         this.field_42[var3].method_34(var1);
         this.field_42[var3].method_35();
         if (this.field_43[var3]) {
            this.field_44.method_685();
         }

         this.field_42[var3].method_33();
      }
   }

   // $VF: renamed from: a (boolean) void
   public final void method_28(boolean var1) {
      class_6[] var2 = new class_6[this.field_42.length + 1];
      System.arraycopy(this.field_42, 0, var2, 0, this.field_42.length);
      var2[this.field_42.length] = new class_6();
      this.field_42 = var2;
      boolean[] var3 = new boolean[this.field_43.length + 1];
      System.arraycopy(this.field_43, 0, var3, 0, this.field_43.length);
      var3[this.field_43.length] = var1;
      this.field_43 = var3;
   }

   // $VF: renamed from: b () void
   public final void method_29() {
      this.method_28(true);
   }

   // $VF: renamed from: a (int, ax) void
   public final void method_30(int var1, class_108 var2) {
      this.field_42[var1].method_32(var2);
   }
}
