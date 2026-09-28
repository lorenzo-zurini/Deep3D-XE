// $VF: renamed from: bf
public final class class_66 extends class_61 {
   // $VF: renamed from: a long
   private long field_837;
   // $VF: renamed from: b long
   private long field_838;
   // $VF: renamed from: c long
   private long field_839;
   // $VF: renamed from: d long
   private long field_840;
   // $VF: renamed from: a boolean
   private boolean field_841;
   // $VF: renamed from: a bj
   private class_65 field_842;
   // $VF: renamed from: a bu
   private class_51 field_843;

   // $VF: renamed from: b () void
   public final void method_552() {
      if (this.field_842 != null) {
         this.field_842.method_552();
      }

      this.field_842 = null;
      this.field_841 = false;
      System.gc();
   }

   // $VF: renamed from: a () void
   public final void method_551() {
      if (this.field_842 == null) {
         this.field_842 = new class_65(0);
      }

      if (!this.field_842.field_823) {
         this.field_842.method_551();
      } else {
         class_28.method_282("/data/interface/logo.png");
         class_21.method_184(0L);
         this.field_843 = new class_51();
         this.field_843.method_427(0);
         class_67.method_578(false);
         System.gc();
         this.field_837 = System.currentTimeMillis();
         this.field_838 = System.currentTimeMillis();
         this.field_841 = true;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_553() {
      return this.field_841;
   }

   // $VF: renamed from: b (int) void
   public final void method_549(int var1) {
      if (this.field_841) {
         this.field_837 = System.currentTimeMillis();
         this.field_839 = this.field_837 - this.field_838;
         this.field_838 = this.field_837;
         this.field_840 = this.field_840 + this.field_839;
         this.field_842.method_571();
         this.field_843.method_418(var1, (int)this.field_839);
         this.method_573();
      }
   }

   // $VF: renamed from: c () void
   private void method_573() {
      this.field_843.method_429();
   }

   // $VF: renamed from: a (int) void
   public final void method_550(int var1) {
      if (this.field_841) {
         this.field_843.method_430(var1);
         if (var1 == 4) {
            this.field_843.method_422();
         }

         if (var1 == 32) {
            this.field_843.method_424();
         }

         if (var1 == 2) {
            this.field_843.method_420((int)this.field_839);
         }

         if (var1 == 64) {
            this.field_843.method_421((int)this.field_839);
         }

         if (var1 == 256) {
            this.field_843.method_419();
         }

         if (var1 == 262144) {
            this.field_843.method_426();
         }

         if (var1 == 16384) {
            this.field_843.method_426();
         }

         if (var1 == 8192) {
            this.field_843.method_425();
         }
      }
   }
}
