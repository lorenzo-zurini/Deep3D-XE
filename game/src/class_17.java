// $VF: renamed from: t
public final class class_17 {
   // $VF: renamed from: a am
   public class_111 field_249 = null;
   // $VF: renamed from: a ae
   private class_97 field_250;
   // $VF: renamed from: a r[]
   private class_34[] field_251 = new class_34[1];
   // $VF: renamed from: a boolean[]
   private boolean[] field_252;
   // $VF: renamed from: a b
   private class_26 field_253;

   public class_17(class_26 var1) {
      this.field_251[0] = new class_34();
      this.field_252 = new boolean[1];
      this.field_252[0] = true;
      this.field_253 = var1;
   }

   // $VF: renamed from: a (am) void
   public final void method_264(class_111 var1) {
      this.field_249 = var1;
      this.field_250 = this.field_249;

      while (this.field_250.field_1278 != null) {
         this.field_250 = this.field_250.field_1278;
      }
   }

   // $VF: renamed from: a (ae) void
   public final void method_265(class_97 var1) {
      try {
         if (var1 != null && this.field_251 != null && this.field_249 != null) {
            var1.method_835(false);
            if (this.field_250 != null) {
               this.field_250.method_835(false);
            } else {
               this.field_249.method_835(false);
            }

            var1.method_833(this.field_249, this);
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_266() {
      for (int var1 = 0; var1 < this.field_251.length; var1++) {
         this.field_251[var1].method_397();
         if (this.field_252[var1]) {
            this.field_253.method_335();
         }

         this.field_251[var1].method_395();
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_267(long var1) {
      for (int var3 = 0; var3 < this.field_251.length; var3++) {
         this.field_251[var3].method_396(var1);
         this.field_251[var3].method_397();
         if (this.field_252[var3]) {
            this.field_253.method_335();
         }

         this.field_251[var3].method_395();
      }
   }

   // $VF: renamed from: a (boolean) void
   public final void method_268(boolean var1) {
      class_34[] var2 = new class_34[this.field_251.length + 1];
      System.arraycopy(this.field_251, 0, var2, 0, this.field_251.length);
      var2[this.field_251.length] = new class_34();
      this.field_251 = var2;
      boolean[] var3 = new boolean[this.field_252.length + 1];
      System.arraycopy(this.field_252, 0, var3, 0, this.field_252.length);
      var3[this.field_252.length] = var1;
      this.field_252 = var3;
   }

   // $VF: renamed from: b () void
   public final void method_269() {
      this.method_268(true);
   }

   // $VF: renamed from: a (int, ay) void
   public final void method_270(int var1, class_101 var2) {
      this.field_251[var1].method_394(var2);
   }
}
