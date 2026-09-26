// $VF: renamed from: bq
public final class class_54 {
   // $VF: renamed from: a do
   public class_61 field_595 = null;
   // $VF: renamed from: a DeepMIDlet
   private DeepMIDlet field_596;
   // $VF: renamed from: a cs
   public class_33 field_597;

   public class_54(DeepMIDlet var1, class_33 var2) {
      this.field_596 = var1;
      this.field_597 = var2;
   }

   // $VF: renamed from: a (do) void
   public final void method_439(class_61 var1) {
      if (this.field_595 != null) {
         if (this.field_597 != null) {
            this.field_597.method_296(true);
         }

         class_84.field_1116.method_5();
         this.field_595.method_552();
      }

      this.field_595 = var1;
   }

   // $VF: renamed from: a () void
   public final void method_440() {
      this.field_596.quit();
   }

   // $VF: renamed from: a (int) void
   public final void method_441(int var1) {
      if (this.field_595 != null) {
         this.field_595.method_550(var1);
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_442(int var1) {
      if (this.field_595 != null) {
         if (this.field_595.method_553()) {
            this.field_595.method_549(var1);
            return;
         }

         this.field_595.method_551();
         if (this.field_595.method_553() && this.field_597 != null) {
            this.field_597.method_295();
         }

         // System.gc() removed: full GCs stall the desktop JVM
      }
   }
}
