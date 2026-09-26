// $VF: renamed from: ax
public abstract class class_108 extends class_105 {
   // $VF: renamed from: d int
   public int field_1364 = 0;
   // $VF: renamed from: d bn
   private static class_57 field_1365 = new class_57();
   // $VF: renamed from: e bn
   private static class_57 field_1366 = new class_57();
   // $VF: renamed from: e int
   public int field_1367;
   // $VF: renamed from: c bn
   public class_57 field_1368 = new class_57();

   public class_108() {
      this.field_1367 = 0;
   }

   // $VF: renamed from: a (an, t) void
   public void method_837(class_106 var1, class_4 var2) {
      if (super.field_1338 && var1.method_884(super.field_1343) != 0) {
         this.field_1368 = var1.field_1342.method_503(this.field_1368);
         if (this.field_1364 != 0) {
            field_1365.method_469();
            field_1365.method_491(0, 0, this.field_1364);
            field_1366 = super.field_1342.method_473(field_1365, field_1366);
            this.field_1368.method_471(field_1366);
         } else {
            this.field_1368.method_471(super.field_1342);
         }

         var2.method_30(this.field_1367, this);
      }
   }

   // $VF: renamed from: b (an, t) void
   public final void method_838(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         this.field_1368 = var1.field_1342.method_503(this.field_1368);
         this.field_1368.method_471(super.field_1342);
         var2.method_30(this.field_1367, this);
      }
   }

   // $VF: renamed from: d () void
   public abstract void method_887();

   // $VF: renamed from: e () void
   public void method_888() {
   }

   // $VF: renamed from: a () af
   public abstract class_102 method_840();

   // $VF: renamed from: a (int, java.lang.String, int) ax
   public static final class_108 method_889(int var0, String var1, int var2) {
      return new class_111(var0, var1, var2);
   }

   // $VF: renamed from: a (int, int, int, int, int, int, int, int, byte) ax
   public static final class_108 method_890(int var0, int var1, int var2, int var3, int var4, int var5, int var6, int var7, byte var8) {
      return new class_110(var0, var1, var2, var3, var4, var5, var6, var7, var8);
   }

   // $VF: renamed from: a (int, java.lang.String) ax
   public static final class_108 method_891(int var0, String var1) {
      return new class_117(var1);
   }

   // $VF: renamed from: a (int, int, byte) ax
   public static final class_108 method_892(int var0, int var1, byte var2) {
      return new class_109(var0, var1, var2);
   }

   // $VF: renamed from: a (cc) void
   public abstract void method_893(class_44 var1);

   // $VF: renamed from: c () void
   public abstract void method_894();

   // $VF: renamed from: a (long) void
   public void method_895(long var1) {
   }
}
