// $VF: renamed from: r
public final class class_34 {
   // $VF: renamed from: a ay[]
   public class_101[] field_458 = null;
   // $VF: renamed from: a int
   public int field_459 = 0;

   // $VF: renamed from: a (ay) void
   public final void method_394(class_101 var1) {
      if (this.field_458 == null) {
         this.field_458 = new class_101[1];
         this.field_458[0] = var1;
         this.field_459 = 1;
      } else if (this.field_459 == this.field_458.length) {
         class_101[] var2 = new class_101[this.field_458.length + 1];
         System.arraycopy(this.field_458, 0, var2, 0, this.field_458.length);
         var2[this.field_458.length] = var1;
         this.field_458 = var2;
         this.field_459++;
      } else {
         this.field_458[this.field_459] = var1;
         this.field_459++;
      }
   }

   // $VF: renamed from: a () void
   public final void method_395() {
      this.field_459 = 0;
   }

   // $VF: renamed from: a (long) void
   public final void method_396(long var1) {
      for (int var3 = 0; var3 < this.field_459; var3++) {
         this.field_458[var3].method_885(var1);
      }
   }

   // $VF: renamed from: b () void
   public final void method_397() {
      for (int var1 = 0; var1 < this.field_459; var1++) {
         this.field_458[var1].method_878();
      }
   }
}
