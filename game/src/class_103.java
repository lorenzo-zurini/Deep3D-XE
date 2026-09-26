// $VF: renamed from: aj
public final class class_103 extends class_101 {
   // $VF: renamed from: a da
   private class_35 field_1301;
   // $VF: renamed from: d boolean
   public boolean field_1302;
   // $VF: renamed from: e boolean
   public boolean field_1303;

   public class_103(class_120 var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, byte var10) {
      this.field_1301 = new class_35(var6, var1, 128, var2, var3, var4, var5, var9, var7, var8, var10);
      this.field_1301.field_460.field_1294 = 2;
      this.field_1302 = true;
      this.field_1303 = var6 > 1;
   }

   public class_103(class_120 var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      this(var1, var2, var3, var4, var5, var6, var7, var8, var9, (byte)2);
   }

   // $VF: renamed from: b (int, int, int) void
   public final void method_841(int var1, int var2, int var3) {
      this.field_1301.field_460.method_841(var1, var2, var3);
   }

   // $VF: renamed from: a (v, v) void
   public final void method_886(class_5 var1, class_5 var2) {
      this.method_887(var1.field_138, var1.field_139, var1.field_140);
   }

   // $VF: renamed from: g (int, int, int) void
   public final void method_887(int var1, int var2, int var3) {
      this.field_1301.field_460.method_841(var1, var2, var3);
      this.field_1301.method_399();
      this.field_1302 = false;
   }

   // $VF: renamed from: e () void
   public final void method_888() {
      this.field_1301.method_399();
      this.field_1302 = false;
   }

   // $VF: renamed from: a (long) void
   public final void method_885(long var1) {
      if (!this.field_1302) {
         this.field_1301.method_400((int)var1);
      }
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      if (!this.field_1302) {
         class_41.field_527.method_265(this.field_1301.field_460);
      }
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return null;
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      this.field_1301.method_398();
   }
}
