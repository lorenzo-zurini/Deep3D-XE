// $VF: renamed from: q
public final class class_6 {
   // $VF: renamed from: a ax[]
   public class_108[] field_54 = null;
   // $VF: renamed from: a int
   public int field_55 = 0;

   // $VF: renamed from: a (ax) void
   public final void method_32(class_108 var1) {
      if (this.field_54 == null) {
         this.field_54 = new class_108[1];
         this.field_54[0] = var1;
         this.field_55 = 1;
      } else if (this.field_55 == this.field_54.length) {
         class_108[] var2 = new class_108[this.field_54.length + 1];
         System.arraycopy(this.field_54, 0, var2, 0, this.field_54.length);
         var2[this.field_54.length] = var1;
         this.field_54 = var2;
         this.field_55++;
      } else {
         this.field_54[this.field_55] = var1;
         this.field_55++;
      }
   }

   // $VF: renamed from: a () void
   public final void method_33() {
      this.field_55 = 0;
   }

   // $VF: renamed from: a (long) void
   public final void method_34(long var1) {
      for (int var3 = 0; var3 < this.field_55; var3++) {
         this.field_54[var3].method_895(var1);
      }
   }

   // $VF: renamed from: b () void
   public final void method_35() {
      for (int var1 = 0; var1 < this.field_55; var1++) {
         this.field_54[var1].method_887();
      }

      for (int var2 = 0; var2 < this.field_55; var2++) {
         this.field_54[var2].method_888();
      }
   }
}
