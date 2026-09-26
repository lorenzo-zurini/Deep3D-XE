// $VF: renamed from: co
public final class class_92 extends class_91 {
   // $VF: renamed from: a ay[]
   private class_101[] field_1202;
   // $VF: renamed from: a int[]
   private int[] field_1203;
   // $VF: renamed from: h int
   private int field_1204;
   // $VF: renamed from: i int
   private int field_1205;

   public class_92(class_60 var1) {
      super(-1, null, 0, 0, 0);
      super.field_1102.method_801(15000);
      class_6.method_184();
      class_6 var2 = new class_6(var1);
      this.field_1202 = new class_101[var2.method_185()];
      this.field_1202 = var2.method_188(this.field_1202);
      this.field_1205 = 0;
      super.field_1198 = new class_36[this.field_1202.length];

      for (int var3 = 0; var3 < this.field_1202.length; var3++) {
         super.field_1109 = this.field_1202[var3].method_844(super.field_1109);
         if (class_124.method_945(super.field_1109.field_138) > this.field_1205) {
            this.field_1205 = class_124.method_945(super.field_1109.field_138);
         }

         if (class_124.method_945(super.field_1109.field_139) > this.field_1205) {
            this.field_1205 = class_124.method_945(super.field_1109.field_139);
         }

         if (class_124.method_945(super.field_1109.field_140) > this.field_1205) {
            this.field_1205 = class_124.method_945(super.field_1109.field_140);
         }

         switch (this.field_1202[var3].field_1286) {
            case 3300:
               super.field_1198[var3] = new class_38(super.field_1109.field_138, super.field_1109.field_139 + 2000, super.field_1109.field_140, 0, 0, 0, 5000);
               break;
            case 3301:
            case 3302:
               super.field_1198[var3] = new class_38(super.field_1109.field_138, super.field_1109.field_139, super.field_1109.field_140, 0, 0, 0, 4000);
               break;
            case 3303:
            case 3311:
               super.field_1198[var3] = new class_38(super.field_1109.field_138, super.field_1109.field_139 - 2000, super.field_1109.field_140, 0, 0, 0, 5000);
               break;
            case 3304:
            case 3310:
               super.field_1110.method_170(0, -250, 1150);
               class_90.field_1194 = this.field_1202[var3].field_1283.method_40(super.field_1110, class_90.field_1194);
               super.field_1110.method_175(super.field_1109);
               super.field_1198[var3] = new class_38(super.field_1110.field_138, super.field_1110.field_139, super.field_1110.field_140, 0, 0, 0, 3000);
               break;
            case 3305:
            case 3307:
               super.field_1198[var3] = new class_38(super.field_1109.field_138, super.field_1109.field_139, super.field_1109.field_140, 0, 0, 0, 8000);
               break;
            case 3306:
            case 3308:
               super.field_1110.method_170(0, 0, 1150);
               class_90.field_1194 = this.field_1202[var3].field_1283.method_40(super.field_1110, class_90.field_1194);
               super.field_1110.method_175(super.field_1109);
               super.field_1198[var3] = new class_37(
                  super.field_1109.field_138, super.field_1109.field_139, super.field_1109.field_140, 0, 0, 0, 8500, 6000, 8500
               );
               break;
            case 3309:
               super.field_1110.method_170(0, -270, 0);
               class_90.field_1194 = this.field_1202[var3].field_1283.method_40(super.field_1110, class_90.field_1194);
               super.field_1110.method_175(super.field_1109);
               super.field_1198[var3] = new class_38(super.field_1110.field_138, super.field_1110.field_139, super.field_1110.field_140, 0, 0, 0, 4000);
         }

         int[] var4;
         if ((var4 = this.method_779(this.field_1202[var3].field_1286, var1.method_592())) != null) {
            this.field_1202[var3].method_869(this.field_1202[var3].field_1286 == 3304 ? 60 : (this.field_1202[var3].field_1286 == 3300 ? 800 : 170));
            this.field_1202[var3].method_872(var4[0], var4[1]);
            this.field_1202[var3].method_873((byte)(var4[0] == var4[1] ? 1 : 2));
         }
      }

      this.field_1205 += 5000;
      this.field_1203 = new int[this.field_1202.length * 3];

      for (int var5 = 0; var5 < this.field_1202.length; var5++) {
         this.field_1203[var5 * 3] = this.field_1202[var5].method_848();
         this.field_1203[var5 * 3 + 1] = this.field_1202[var5].method_849();
         this.field_1203[var5 * 3 + 2] = this.field_1202[var5].method_850();
      }
   }

   // $VF: renamed from: a (int, boolean) int[]
   private int[] method_779(int var1, boolean var2) {
      int[] var3 = new int[2];
      switch (var1) {
         case 3300:
         case 3311:
            var3[0] = var2 ? 0 : 2;
            var3[1] = var2 ? 1 : 3;
            break;
         case 3301:
         case 3302:
         case 3303:
            return null;
         case 3304:
            var3[0] = 0;
            var3[1] = 2;
            break;
         case 3305:
         case 3306:
         case 3309:
         case 3310:
            var3[0] = var2 ? 0 : 2;
            var3[1] = var3[0];
            break;
         case 3307:
         case 3308:
            var3[0] = var2 ? 0 : 3;
            var3[1] = var2 ? 2 : 5;
      }

      return var3;
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      for (int var3 = 0; var3 < this.field_1202.length; var3++) {
         super.field_1109 = class_41.field_527.field_249.method_845(super.field_1109);
         super.field_1110.method_170(this.field_1203[var3 * 3], this.field_1203[var3 * 3 + 1], this.field_1203[var3 * 3 + 2]);
         super.field_1110.method_176(super.field_1109, class_90.field_1194);
         int var4;
         if ((var4 = class_90.field_1194.method_183()) > org.deep3d.Config.impostorDistance()) {
            class_90.field_1194.method_182();
            class_90.field_1194.method_178(org.deep3d.Config.impostorDistance());
            class_90.field_1194.method_175(super.field_1109);
            this.field_1202[var3].method_842(class_90.field_1194);
            int var5 = (int)((float)org.deep3d.Config.impostorDistance() / var4 * 4096.0F);
            this.field_1202[var3].method_865(var5, var5, var5);
         } else {
            this.field_1202[var3].method_865(4096, 4096, 4096);
            this.field_1202[var3].method_841(this.field_1203[var3 * 3], this.field_1203[var3 * 3 + 1], this.field_1203[var3 * 3 + 2]);
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      for (int var1 = 0; var1 < this.field_1202.length; var1++) {
         class_41.field_527.method_265(this.field_1202[var1]);
      }
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_746(class_5 var1) {
      var1.method_170(0, 0, 0);
      return var1;
   }

   // $VF: renamed from: a () ay
   public final class_101 method_780() {
      return this.field_1202[0];
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_781(int var1, int var2, int var3) {
      for (int var4 = 0; var4 < this.field_1202.length; var4++) {
         this.field_1202[var4].method_839(var1, var2, var3);
         this.field_1203[var4 * 3] = this.field_1203[var4 * 3] + var1;
         this.field_1203[var4 * 3 + 1] = this.field_1203[var4 * 3 + 1] + var2;
         this.field_1203[var4 * 3 + 2] = this.field_1203[var4 * 3 + 2] + var3;
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      return var1 < super.field_1102.field_1255
         && var1 > -super.field_1102.field_1255
         && var2 < super.field_1102.field_1255
         && var2 > -super.field_1102.field_1255
         && var3 < super.field_1102.field_1255
         && var3 > -super.field_1102.field_1255;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_782(int var1, int var2, int var3) {
      if (var1 < this.field_1205
         && var1 > -this.field_1205
         && var2 < this.field_1205
         && var2 > -this.field_1205
         && var3 < this.field_1205
         && var3 > -this.field_1205
         && super.field_1198 != null) {
         for (int var4 = 0; var4 < super.field_1198.length; var4++) {
            if (super.field_1198[var4].method_404(var1, var2, var3)) {
               this.field_1204 = var4;
               return true;
            }
         }
      }

      return false;
   }

   // $VF: renamed from: a (v) boolean
   public final boolean method_754(class_5 var1) {
      return this.method_782(var1.field_138, var1.field_139, var1.field_140);
   }

   // $VF: renamed from: b (v) v
   public final class_5 method_755(class_5 var1) {
      return super.field_1198 != null ? super.field_1198[this.field_1204].method_401(var1) : null;
   }

   // $VF: renamed from: a () void
   public final void method_741() {
      if (this.field_1202 != null) {
         for (int var1 = 0; var1 < this.field_1202.length; var1++) {
            if (this.field_1202[var1] != null) {
               this.field_1202[var1].method_884();
               this.field_1202[var1] = null;
            }
         }
      }

      this.field_1202 = null;
      this.field_1203 = null;
   }

   static {
      short[] var10000 = new short[]{3301, 3302, 3304, 3305, 3306, 3309, 3310};
   }
}
