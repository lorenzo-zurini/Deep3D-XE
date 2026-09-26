// $VF: renamed from: ak
public final class class_116 extends class_108 {
   // $VF: renamed from: a db
   private class_24 field_1435;
   // $VF: renamed from: d boolean
   public boolean field_1436;
   // $VF: renamed from: e boolean
   public boolean field_1437;

   public class_116(class_44 var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, byte var10) {
      this.field_1435 = new class_24(var6, var1, 128, var2, var3, var4, var5, var9, var7, var8, var10);
      this.field_1435.field_250.field_1367 = 2;
      this.field_1436 = true;
      this.field_1437 = var6 > 1;
   }

   public class_116(class_44 var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      this(var1, var2, var3, var4, var5, var6, var7, var8, var9, (byte)2);
   }

   // $VF: renamed from: b (int, int, int) void
   public final void method_845(int var1, int var2, int var3) {
      this.field_1435.field_250.method_845(var1, var2, var3);
   }

   // $VF: renamed from: a (x, x) void
   public final void method_908(class_3 var1, class_3 var2) {
      this.method_909(var1.field_37, var1.field_38, var1.field_39);
   }

   // $VF: renamed from: g (int, int, int) void
   public final void method_909(int var1, int var2, int var3) {
      this.field_1435.field_250.method_845(var1, var2, var3);
      this.field_1435.method_233();
      this.field_1436 = false;
   }

   // $VF: renamed from: f () void
   public final void method_910() {
      this.field_1435.method_233();
      this.field_1436 = false;
   }

   // $VF: renamed from: a (long) void
   public final void method_895(long var1) {
      if (!this.field_1436) {
         this.field_1435.method_234((int)var1);
      }
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      if (!this.field_1436) {
         class_84.field_1110.method_25(this.field_1435.field_250);
      }
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return null;
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      this.field_1435.method_232();
   }
}
