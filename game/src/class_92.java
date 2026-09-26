// $VF: renamed from: dg
public final class class_92 extends class_91 {
   // $VF: renamed from: e int
   private int field_1241;
   // $VF: renamed from: f int
   private int field_1242;
   // $VF: renamed from: g int
   private int field_1243;
   // $VF: renamed from: h int
   private int field_1244;
   // $VF: renamed from: i int
   private int field_1245;

   public class_92(int var1, boolean var2, class_37 var3, class_108 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      this.field_1243 = var5;
      this.field_1244 = var6 + 3000;
      this.field_1245 = var7;
      this.method_810();
      var4.method_845(var5, class_84.field_1123.nextInt(75000), var7);
      var4.method_869(8192, 8192, 8192);
      var4.method_864(-1024, 0, 0);
   }

   // $VF: renamed from: b () void
   public final void method_810() {
      super.field_1224 = 0;
      this.method_795(true);
      super.field_1226.method_845(this.field_1243, this.field_1244, this.field_1245);
      this.field_1242 = 0;
      super.field_1225.method_327(super.field_1225.field_364);
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      this.field_1241 = (int)var1;
      if (super.field_1225.field_363 <= 0 && super.field_1224 != 3 && super.field_1224 != 4) {
         super.field_1229.method_261();
         super.field_1225.field_375 = false;
         super.field_1224 = 3;
         if (super.field_1231 != null) {
            super.field_1233 = super.field_1226.method_849(super.field_1233);
            super.field_1231.method_741(super.field_1233.field_37, super.field_1233.field_38, super.field_1233.field_39);
         }
      }

      switch (super.field_1224) {
         case 0:
            super.field_1226.method_843(0, this.field_1241 + this.field_1242++, 0);
            if (super.field_1226.method_853() > 75000) {
               this.method_810();
               return;
            }
         case 1:
         case 2:
         default:
            break;
         case 3:
            if (super.field_1231 == null) {
               super.field_1224 = 4;
               return;
            }

            if (super.field_1231.method_743()) {
               super.field_1224 = 4;
               return;
            }
            break;
         case 4:
            this.method_810();
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (super.field_1224 != 4 && super.field_1224 != 3) {
         super.method_809();
      }

      if (super.field_1224 == 3 && super.field_1231 != null) {
         super.field_1231.method_742(this.field_1241);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      return false;
   }
}
