// $VF: renamed from: ci
public final class class_86 extends class_83 {
   // $VF: renamed from: a long
   private long field_1160;

   public class_86(int var1, boolean var2, class_96 var3, class_101 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      super.field_1102.field_1270 = var4.field_1283;
      int var8 = 4096 + class_41.field_540.nextInt(8096);
      var4.method_865(var8, var8, var8);
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      this.field_1160 = var1;
      if (super.field_1102.field_1256 <= 0 && super.field_1101 != 3 && super.field_1101 != 4) {
         super.field_1102.field_1268 = false;
         super.field_1106.method_548();
         super.field_1101 = 3;
         if (super.field_1108 != null) {
            super.field_1110 = super.field_1103.method_845(super.field_1110);
            super.field_1108.method_196(super.field_1110.field_138, super.field_1110.field_139, super.field_1110.field_140);
         }
      }

      switch (super.field_1101) {
         case 3:
            if (super.field_1108 != null) {
               if (super.field_1108.method_198()) {
                  super.field_1101 = 4;
                  return;
               }
            } else {
               super.field_1101 = 4;
            }
         case 4:
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (super.field_1101 != 4 && super.field_1101 != 3) {
         super.method_756();
      }

      if (super.field_1101 == 3 && super.field_1108 != null) {
         super.field_1108.method_197(this.field_1160);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      return false;
   }
}
