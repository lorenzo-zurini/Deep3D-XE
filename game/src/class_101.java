// $VF: renamed from: ay
public abstract class class_101 extends class_100 {
   // $VF: renamed from: e int
   private int field_1291 = 0;
   // $VF: renamed from: d bn
   private static class_1 field_1292 = new class_1();
   // $VF: renamed from: e bn
   private static class_1 field_1293 = new class_1();
   // $VF: renamed from: c int
   public int field_1294;
   // $VF: renamed from: c bn
   public class_1 field_1295 = new class_1();

   public class_101() {
      this.field_1294 = 0;
   }

   // $VF: renamed from: a (am, t) void
   public void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280 && var1.method_898(super.field_1285) != 0) {
         this.field_1295 = var1.field_1284.method_36(this.field_1295);
         if (this.field_1291 != 0) {
            field_1292.method_2();
            field_1292.method_24(0, 0, this.field_1291);
            field_1293 = super.field_1284.method_6(field_1292, field_1293);
            this.field_1295.method_4(field_1293);
         } else {
            this.field_1295.method_4(super.field_1284);
         }

         var2.method_270(this.field_1294, this);
      }
   }

   // $VF: renamed from: g (int) void
   public void method_877(int var1) {
      this.field_1291 = var1;
   }

   // $VF: renamed from: b (am, t) void
   public void method_834(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         this.field_1295 = var1.field_1284.method_36(this.field_1295);
         this.field_1295.method_4(super.field_1284);
         var2.method_270(this.field_1294, this);
      }
   }

   // $VF: renamed from: c () void
   public abstract void method_878();

   // $VF: renamed from: a () ae
   public abstract class_97 method_836();

   // $VF: renamed from: a (int, java.lang.String, int) ay
   public static final class_101 method_879(int var0, String var1, int var2) {
      return new class_110(var0, var1, var2);
   }

   // $VF: renamed from: a (int, int, int, int, int, int, int, int, byte) ay
   public static final class_101 method_880(int var0, int var1, int var2, int var3, int var4, int var5, int var6, int var7, byte var8) {
      return new class_104(var0, var2, var3, var4, var5, var6, var7, var8);
   }

   // $VF: renamed from: a (int, java.lang.String) ay
   public static final class_101 method_881(int var0, String var1) {
      return new class_102(var0, var1);
   }

   // $VF: renamed from: a (int, int, byte) ay
   public static final class_101 method_882(int var0, int var1, byte var2) {
      return new class_105(var0, var1, var2);
   }

   // $VF: renamed from: a (cc) void
   public abstract void method_883(class_120 var1);

   // $VF: renamed from: d () void
   public abstract void method_884();

   // $VF: renamed from: a (long) void
   public void method_885(long var1) {
   }
}
