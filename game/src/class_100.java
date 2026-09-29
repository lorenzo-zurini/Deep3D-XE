// $VF: renamed from: co
public final class class_100 extends class_99 {
   // $VF: renamed from: a ax[]
   private class_108[] field_1307;
   // $VF: renamed from: a int[]
   private int[] field_1308;
   // $VF: renamed from: h int
   private int field_1309;
   // $VF: renamed from: i int
   private int field_1310;

   public class_100(class_86 var1) {
      super(-1, null, 0, 0, 0);
      super.field_1225.method_322(15000);
      class_7.method_36();
      class_7 var2 = new class_7(var1);
      this.field_1307 = new class_108[var2.method_37()];
      this.field_1307 = var2.method_40(this.field_1307);
      this.field_1310 = 0;
      super.field_1303 = new class_29[this.field_1307.length];

      for (int var3 = 0; var3 < this.field_1307.length; var3++) {
         super.field_1232 = this.field_1307[var3].method_848(super.field_1232);
         if (class_16.method_100(super.field_1232.field_37) > this.field_1310) {
            this.field_1310 = class_16.method_100(super.field_1232.field_37);
         }

         if (class_16.method_100(super.field_1232.field_38) > this.field_1310) {
            this.field_1310 = class_16.method_100(super.field_1232.field_38);
         }

         if (class_16.method_100(super.field_1232.field_39) > this.field_1310) {
            this.field_1310 = class_16.method_100(super.field_1232.field_39);
         }

         switch (this.field_1307[var3].field_1344) {
            case 3300:
               super.field_1303[var3] = new class_30(super.field_1232.field_37, super.field_1232.field_38 + 2000, super.field_1232.field_39, 0, 0, 0, 5000);
               break;
            case 3301:
            case 3302:
               super.field_1303[var3] = new class_30(super.field_1232.field_37, super.field_1232.field_38, super.field_1232.field_39, 0, 0, 0, 4000);
               break;
            case 3303:
            case 3311:
               super.field_1303[var3] = new class_30(super.field_1232.field_37, super.field_1232.field_38 - 2000, super.field_1232.field_39, 0, 0, 0, 5000);
               break;
            case 3304:
            case 3310:
               super.field_1233.method_10(0, -250, 1150);
               class_98.field_1299 = this.field_1307[var3].field_1341.method_508(super.field_1233, class_98.field_1299);
               super.field_1233.method_15(super.field_1232);
               super.field_1303[var3] = new class_30(super.field_1233.field_37, super.field_1233.field_38, super.field_1233.field_39, 0, 0, 0, 3000);
               break;
            case 3305:
            case 3307:
               super.field_1303[var3] = new class_30(super.field_1232.field_37, super.field_1232.field_38, super.field_1232.field_39, 0, 0, 0, 8000);
               break;
            case 3306:
            case 3308:
               super.field_1233.method_10(0, 0, 1150);
               class_98.field_1299 = this.field_1307[var3].field_1341.method_508(super.field_1233, class_98.field_1299);
               super.field_1233.method_15(super.field_1232);
               super.field_1303[var3] = new class_31(super.field_1232.field_37, super.field_1232.field_38, super.field_1232.field_39, 0, 0, 0, 8500, 6000, 8500);
               break;
            case 3309:
               super.field_1233.method_10(0, -270, 0);
               class_98.field_1299 = this.field_1307[var3].field_1341.method_508(super.field_1233, class_98.field_1299);
               super.field_1233.method_15(super.field_1232);
               super.field_1303[var3] = new class_30(super.field_1233.field_37, super.field_1233.field_38, super.field_1233.field_39, 0, 0, 0, 4000);
         }

         int[] var4;
         if ((var4 = this.method_825(this.field_1307[var3].field_1344, var1.method_752())) != null) {
            this.field_1307[var3].method_873(this.field_1307[var3].field_1344 == 3304 ? 60 : (this.field_1307[var3].field_1344 == 3300 ? 800 : 170));
            this.field_1307[var3].method_876(var4[0], var4[1]);
            this.field_1307[var3].method_877(var4[0] == var4[1] ? (byte)1 : (byte)2);
         }
      }

      this.field_1310 += 5000;
      this.field_1308 = new int[this.field_1307.length * 3];

      for (int var5 = 0; var5 < this.field_1307.length; var5++) {
         this.field_1308[var5 * 3] = this.field_1307[var5].method_852();
         this.field_1308[var5 * 3 + 1] = this.field_1307[var5].method_853();
         this.field_1308[var5 * 3 + 2] = this.field_1307[var5].method_854();
      }
   }

   // $VF: renamed from: a (int, boolean) int[]
   private int[] method_825(int var1, boolean var2) {
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
            var3[0] = var2 ? 0 : 2;
            var3[1] = var2 ? 1 : 3;
      }

      return var3;
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      for (int var3 = 0; var3 < this.field_1307.length; var3++) {
         super.field_1232 = class_84.field_1110.field_40.method_849(super.field_1232);
         super.field_1233.method_10(this.field_1308[var3 * 3], this.field_1308[var3 * 3 + 1], this.field_1308[var3 * 3 + 2]);
         super.field_1233.method_16(super.field_1232, class_98.field_1299);
         // Deep3D-PC: always full detail. The phone swapped distant structures for
         // scaled-down stand-ins kept inside its short far plane; the far plane now
         // reaches them (class_64).
         this.field_1307[var3].method_869(4096, 4096, 4096);
         this.field_1307[var3].method_845(this.field_1308[var3 * 3], this.field_1308[var3 * 3 + 1], this.field_1308[var3 * 3 + 2]);
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      class_4.deep3dStructure = true; // Deep3D-PC
      for (int var1 = 0; var1 < this.field_1307.length; var1++) {
         class_84.field_1110.method_25(this.field_1307[var1]);
      }
      class_4.deep3dStructure = false; // Deep3D-PC
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_799(class_3 var1) {
      var1.method_10(0, 0, 0);
      return var1;
   }

   // $VF: renamed from: a () ax
   public final class_108 method_826() {
      return this.field_1307[0];
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_827(int var1, int var2, int var3) {
      for (int var4 = 0; var4 < this.field_1307.length; var4++) {
         this.field_1307[var4].method_843(var1, var2, var3);
         this.field_1308[var4 * 3] = this.field_1308[var4 * 3] + var1;
         this.field_1308[var4 * 3 + 1] = this.field_1308[var4 * 3 + 1] + var2;
         this.field_1308[var4 * 3 + 2] = this.field_1308[var4 * 3 + 2] + var3;
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      return var1 < super.field_1225.field_362
         && var1 > -super.field_1225.field_362
         && var2 < super.field_1225.field_362
         && var2 > -super.field_1225.field_362
         && var3 < super.field_1225.field_362
         && var3 > -super.field_1225.field_362;
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_828(int var1, int var2, int var3) {
      if (var1 < this.field_1310
         && var1 > -this.field_1310
         && var2 < this.field_1310
         && var2 > -this.field_1310
         && var3 < this.field_1310
         && var3 > -this.field_1310
         && super.field_1303 != null) {
         for (int var4 = 0; var4 < super.field_1303.length; var4++) {
            if (super.field_1303[var4].method_288(var1, var2, var3)) {
               this.field_1309 = var4;
               return true;
            }
         }
      }

      return false;
   }

   // $VF: renamed from: a (x) boolean
   public final boolean method_807(class_3 var1) {
      return this.method_828(var1.field_37, var1.field_38, var1.field_39);
   }

   // $VF: renamed from: b (x) x
   public final class_3 method_808(class_3 var1) {
      return super.field_1303 != null ? super.field_1303[this.field_1309].method_285(var1) : null;
   }

   // $VF: renamed from: a () void
   public final void method_794() {
      if (this.field_1307 != null) {
         for (int var1 = 0; var1 < this.field_1307.length; var1++) {
            if (this.field_1307[var1] != null) {
               this.field_1307[var1].method_894();
               this.field_1307[var1] = null;
            }
         }
      }

      this.field_1307 = null;
      this.field_1308 = null;
   }

   static {
      short[] var10000 = new short[]{3301, 3302, 3304, 3305, 3306, 3309, 3310};
   }
}
