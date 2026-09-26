// $VF: renamed from: bq
public final class class_12 {
   // $VF: renamed from: a do
   public class_113 field_179 = null;
   // $VF: renamed from: a DeepMIDlet
   private DeepMIDlet field_180;
   // $VF: renamed from: a cr
   public class_94 field_181;

   public class_12(DeepMIDlet var1, class_94 var2) {
      this.field_180 = var1;
      this.field_181 = var2;
   }

   // $VF: renamed from: a (do) void
   public final void method_213(class_113 var1) {
      if (this.field_179 != null) {
         if (this.field_181 != null) {
            this.field_181.method_788(true);
         }

         class_41.field_533.method_298();
         this.field_179.method_903();
      }

      this.field_179 = var1;
   }

   // $VF: renamed from: a () void
   public final void method_214() {
      this.field_180.quit();
   }

   // $VF: renamed from: a (int) void
   public final void method_215(int var1) {
      if (this.field_179 != null) {
         this.field_179.method_901(var1);
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_216(int var1) {
      if (this.field_179 != null) {
         if (this.field_179.method_904()) {
            this.field_179.method_900(var1);
            return;
         }

         this.field_179.method_902();
         if (this.field_179.method_904() && this.field_181 != null) {
            this.field_181.method_787();
         }

         ;
      }
   }
}
