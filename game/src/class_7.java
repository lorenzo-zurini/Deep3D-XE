import java.util.Random;

// $VF: renamed from: p
public final class class_7 {
   // $VF: renamed from: a x
   private static class_3 field_56 = new class_3(0, 0, 6309);
   // $VF: renamed from: b x
   private static class_3 field_57 = new class_3(0, 0, 6309);
   // $VF: renamed from: c x
   private static class_3 field_58 = new class_3(0, 4500, 0);
   // $VF: renamed from: a java.util.Random
   private static Random field_59 = new Random();
   // $VF: renamed from: a short[][]
   private static short[][] field_60 = new short[][]{{0, 2048}, {0}, {682, 2048, -682}, {0, 1024, 2048, 3072}, {682, -682}, {0, 1024, 3072}};
   // $VF: renamed from: b short[][]
   private static short[][] field_61 = new short[][]{{3301, 3302, 3304, 3309, 3310, 3305, 3306}, {3301, 3302, 3304, 3309, 3310}};
   // $VF: renamed from: a int
   private int field_62;
   // $VF: renamed from: a short[]
   private short[] field_63;
   // $VF: renamed from: b short[]
   private short[] field_64;
   // $VF: renamed from: a p[]
   private class_7[] field_65;
   // $VF: renamed from: a boolean
   private boolean field_66;
   // $VF: renamed from: a ax
   private class_108 field_67;
   // $VF: renamed from: b int
   private static int field_68;
   // $VF: renamed from: c int
   private static int field_69;
   // $VF: renamed from: d int
   private static int field_70;
   // $VF: renamed from: a bn
   private static class_57 field_71 = new class_57();

   // $VF: renamed from: a () void
   public static final void method_36() {
      field_68 = 0;
      field_69 = 0;
      field_70 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_37() {
      return field_68;
   }

   public class_7(class_86 var1) {
      field_59.setSeed(var1.field_1134 + var1.field_1140 + var1.field_1139);
      field_69 = 20;
      this.field_62 = field_59.nextInt(2) == 0 ? 3307 : 3308;
      this.field_67 = class_43.method_381(this.field_62);
      this.field_67.method_864(0, 2048, 0);
      this.field_67.field_1367 = 2;
      this.field_63 = this.field_62 == 3307 ? field_60[4] : field_60[5];
      this.field_64 = field_61[1];
      field_69--;
      field_68 = 1;
      this.method_38();
   }

   private class_7(int var1) {
      field_69--;
      this.field_62 = var1;
      switch (var1) {
         case 3301:
         case 3302:
            this.field_63 = field_60[0];
            this.field_64 = field_61[0];
            return;
         case 3304:
         case 3309:
         case 3310:
            this.field_63 = field_60[1];
            this.field_64 = null;
            return;
         case 3305:
            this.field_63 = field_60[2];
            this.field_64 = field_61[1];
            return;
         case 3306:
            this.field_63 = field_60[3];
            this.field_64 = field_61[1];
            return;
         case 3307:
            this.field_63 = field_60[4];
            this.field_64 = field_61[1];
            return;
         case 3308:
            this.field_63 = field_60[5];
            this.field_64 = field_61[1];
         case 3303:
      }
   }

   // $VF: renamed from: b () void
   private void method_38() {
      if (this.field_64 != null) {
         boolean var1 = this.field_62 == 3307 || this.field_62 == 3308 || this.field_62 == 3305 || this.field_62 == 3306;
         this.field_65 = new class_7[var1 ? this.field_63.length + 2 : this.field_63.length];
         boolean[] var2 = new boolean[this.field_65.length];

         for (int var3 = 0; var3 < var2.length; var3++) {
            if (!var1 || var3 > this.field_65.length - 3 || this.field_62 != 3307 && this.field_62 != 3308) {
               if (this.field_62 != 3300 && this.field_62 != 3311 && this.field_62 != 3303) {
                  var2[var3] = field_59.nextInt(100) < this.method_39(this.field_62);
                  var2[0] = false;
               } else {
                  var2[var3] = false;
               }
            } else {
               var2[var3] = true;
            }
         }

         for (int var6 = 0; var6 < this.field_65.length; var6++) {
            if (field_69 <= 0) {
               return;
            }

            if (var2[var6]) {
               int var4 = 3301;
               if (var1 && var6 > this.field_65.length - 3) {
                  if (var6 == this.field_65.length - 1 && this.field_66 && this.field_62 != 3307 && this.field_62 != 3308
                     || !this.field_66 && this.field_62 != 3307 && this.field_62 != 3308) {
                     return;
                  }

                  if (this.field_62 != 3307 && this.field_62 != 3305) {
                     var4 = 3306;
                  } else {
                     var4 = 3305;
                  }

                  if (field_59.nextInt(2) == 0) {
                     if (var6 == this.field_65.length - 1) {
                        if (this.field_66 && this.field_62 != 3307 && this.field_62 != 3308) {
                           return;
                        }

                        var4 = field_59.nextInt(2) == 0 ? 3311 : 3303;
                     } else {
                        if (!this.field_66 && this.field_62 != 3307 && this.field_62 != 3308) {
                           return;
                        }

                        var4 = 3300;
                     }
                  }
               } else {
                  boolean var5 = false;
                  if (this.field_64 != field_61[1]) {
                     var4 = field_59.nextInt(2) == 0 ? 3305 : 3306;
                  }

                  for (; !var5; var4 = this.field_64[field_59.nextInt(this.field_64.length)]) {
                     if (field_59.nextInt(100) < this.method_39(var4)) {
                        var5 = true;
                     }
                  }
               }

               this.field_65[var6] = new class_7(var4);
               this.field_65[var6].field_66 = var6 != this.field_65.length - 1;
               this.field_65[var6].field_67 = class_43.method_381(this.field_65[var6].field_62);
               this.field_65[var6].field_67.field_1367 = 2;
               this.field_65[var6].field_67.method_870(this.field_67.field_1341);
               class_3 var7 = new class_3();
               if (var1 && var6 > this.field_65.length - 3) {
                  var7.method_10(0, var6 == this.field_65.length - 1 ? field_58.field_38 : -field_58.field_38, 0);
               } else {
                  this.field_65[var6].field_67.method_860(0, 2048 - this.field_63[var6], 0);
                  field_71.method_469();
                  field_71.method_490(this.field_67.method_866());
                  field_71.method_486(0, -this.field_63[var6], 0);
                  if (this.field_62 != 3305 && this.field_62 != 3307) {
                     var7 = field_71.method_508(field_57, var7);
                  } else {
                     var7 = field_71.method_508(field_56, var7);
                  }
               }

               this.field_65[var6].field_67.method_844(var7);
               field_68++;
               this.field_65[var6].method_38();
            }
         }
      }
   }

   // $VF: renamed from: a (int) int
   private int method_39(int var1) {
      switch (var1) {
         case 3301:
         case 3302:
            return 90;
         case 3303:
         default:
            return 50;
         case 3304:
         case 3309:
         case 3310:
            return 30;
         case 3305:
            return 70;
         case 3306:
            return 50;
         case 3307:
            return 70;
         case 3308:
            return 70;
      }
   }

   // $VF: renamed from: a (ax[]) ax[]
   public final class_108[] method_40(class_108[] var1) {
      var1[field_70] = this.field_67;
      if (this.field_65 != null) {
         for (int var2 = 0; var2 < this.field_65.length; var2++) {
            if (this.field_65[var2] != null && this.field_65[var2].field_67 != null) {
               field_70++;
               this.field_65[var2].method_40(var1);
            }
         }
      }

      return var1;
   }
}
