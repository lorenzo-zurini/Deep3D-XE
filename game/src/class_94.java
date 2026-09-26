// $VF: renamed from: ci
public final class class_94 extends class_91 {
   // $VF: renamed from: a long
   private long field_1252;

   public class_94(int var1, boolean var2, class_37 var3, class_108 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      super.field_1225.field_377 = var4.field_1341;
      int var8 = 4096 + class_84.field_1123.nextInt(8096);
      var4.method_869(var8, var8, var8);
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      this.field_1252 = var1;
      if (super.field_1225.field_363 <= 0 && super.field_1224 != 3 && super.field_1224 != 4) {
         super.field_1225.field_375 = false;
         super.field_1229.method_258();
         super.field_1224 = 3;
         if (super.field_1231 != null) {
            super.field_1233 = super.field_1226.method_849(super.field_1233);
            super.field_1231.method_741(super.field_1233.field_37, super.field_1233.field_38, super.field_1233.field_39);
         }
      }

      switch (super.field_1224) {
         case 3:
            if (super.field_1231 != null) {
               if (super.field_1231.method_743()) {
                  super.field_1224 = 4;
                  return;
               }
            } else {
               super.field_1224 = 4;
            }
         case 4:
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (super.field_1224 != 4 && super.field_1224 != 3) {
         super.method_809();
      }

      if (super.field_1224 == 3 && super.field_1231 != null) {
         super.field_1231.method_742(this.field_1252);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      return false;
   }
}
