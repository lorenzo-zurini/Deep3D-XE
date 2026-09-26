// $VF: renamed from: bg
public final class class_115 extends class_113 {
   // $VF: renamed from: a long
   private long field_1391;
   // $VF: renamed from: b long
   private long field_1392;
   // $VF: renamed from: c long
   private long field_1393;
   // $VF: renamed from: d long
   private long field_1394;
   // $VF: renamed from: a boolean
   private boolean field_1395;
   // $VF: renamed from: a bk
   private class_117 field_1396;
   // $VF: renamed from: a bu
   private class_67 field_1397;

   // $VF: renamed from: b () void
   public final void method_903() {
      if (this.field_1396 != null) {
         this.field_1396.method_903();
      }

      this.field_1396 = null;
      this.field_1395 = false;
      System.gc();
   }

   // $VF: renamed from: a () void
   public final void method_902() {
      if (this.field_1396 == null) {
         this.field_1396 = new class_117(0);
      }

      if (!this.field_1396.field_1443) {
         this.field_1396.method_902();
      } else {
         class_40.method_412("/data/interface/logo.png");
         class_3.method_114(0L);
         this.field_1397 = new class_67();
         this.field_1397.method_634(0);
         class_69.method_654(false);
         System.gc();
         this.field_1391 = System.currentTimeMillis();
         this.field_1392 = System.currentTimeMillis();
         this.field_1395 = true;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_904() {
      return this.field_1395;
   }

   // $VF: renamed from: b (int) void
   public final void method_900(int var1) {
      if (this.field_1395) {
         this.field_1391 = System.currentTimeMillis();
         this.field_1393 = this.field_1391 - this.field_1392;
         this.field_1392 = this.field_1391;
         this.field_1394 = this.field_1394 + this.field_1393;
         this.field_1396.method_917();
         this.field_1397.method_625(var1, (int)this.field_1393);
         this.method_905();
      }
   }

   // $VF: renamed from: c () void
   private void method_905() {
      this.field_1397.method_636();
   }

   // $VF: renamed from: a (int) void
   public final void method_901(int var1) {
      if (this.field_1395) {
         this.field_1397.method_637(var1);
         if (var1 == 4) {
            this.field_1397.method_629();
         }

         if (var1 == 32) {
            this.field_1397.method_631();
         }

         if (var1 == 2) {
            this.field_1397.method_627((int)this.field_1393);
         }

         if (var1 == 64) {
            this.field_1397.method_628((int)this.field_1393);
         }

         if (var1 == 256) {
            this.field_1397.method_626();
         }

         if (var1 == 262144) {
            this.field_1397.method_633();
         }

         if (var1 == 16384) {
            this.field_1397.method_633();
         }

         if (var1 == 8192) {
            this.field_1397.method_632();
         }
      }
   }
}
