// $VF: renamed from: df
public final class class_88 extends class_83 {
   // $VF: renamed from: e int
   private int field_1165;
   // $VF: renamed from: f int
   private int field_1166;
   // $VF: renamed from: g int
   private int field_1167;
   // $VF: renamed from: h int
   private int field_1168;
   // $VF: renamed from: i int
   private int field_1169;

   public class_88(int var1, boolean var2, class_96 var3, class_101 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      this.field_1167 = var5;
      this.field_1168 = var6 + 3000;
      this.field_1169 = var7;
      this.method_766();
      var4.method_841(var5, class_41.field_540.nextInt(75000), var7);
      var4.method_865(8192, 8192, 8192);
      var4.method_860(-1024, 0, 0);
   }

   // $VF: renamed from: b () void
   public final void method_766() {
      super.field_1101 = 0;
      this.method_742(true);
      super.field_1103.method_841(this.field_1167, this.field_1168, this.field_1169);
      this.field_1166 = 0;
      super.field_1102.method_806(super.field_1102.field_1257);
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      this.field_1165 = (int)var1;
      if (super.field_1102.field_1256 <= 0 && super.field_1101 != 3 && super.field_1101 != 4) {
         super.field_1106.method_551();
         super.field_1102.field_1268 = false;
         super.field_1101 = 3;
         if (super.field_1108 != null) {
            super.field_1110 = super.field_1103.method_845(super.field_1110);
            super.field_1108.method_196(super.field_1110.field_138, super.field_1110.field_139, super.field_1110.field_140);
         }
      }

      switch (super.field_1101) {
         case 0:
            super.field_1103.method_839(0, this.field_1165 + this.field_1166++, 0);
            if (super.field_1103.method_849() > 75000) {
               this.method_766();
               return;
            }
         case 1:
         case 2:
         default:
            break;
         case 3:
            if (super.field_1108 == null) {
               super.field_1101 = 4;
               return;
            }

            if (super.field_1108.method_198()) {
               super.field_1101 = 4;
               return;
            }
            break;
         case 4:
            this.method_766();
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (super.field_1101 != 4 && super.field_1101 != 3) {
         super.method_756();
      }

      if (super.field_1101 == 3 && super.field_1108 != null) {
         super.field_1108.method_197(this.field_1165);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      return false;
   }
}
