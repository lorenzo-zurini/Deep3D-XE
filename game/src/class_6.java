import java.util.Random;

// $VF: renamed from: q
public final class class_6 {
   // $VF: renamed from: a v
   private static class_5 field_141 = new class_5(0, 0, 6309);
   // $VF: renamed from: b v
   private static class_5 field_142 = new class_5(0, 0, 6309);
   // $VF: renamed from: c v
   private static class_5 field_143 = new class_5(0, 4500, 0);
   // $VF: renamed from: a java.util.Random
   private static Random field_144 = new Random();
   // $VF: renamed from: a short[][]
   private static short[][] field_145 = new short[][]{{0, 2048}, {0}, {682, 2048, -682}, {0, 1024, 2048, 3072}, {682, -682}, {0, 1024, 3072}};
   // $VF: renamed from: b short[][]
   private static short[][] field_146 = new short[][]{{3301, 3302, 3304, 3309, 3310, 3305, 3306}, {3301, 3302, 3304, 3309, 3310}};
   // $VF: renamed from: a int
   private int field_147;
   // $VF: renamed from: a short[]
   private short[] field_148;
   // $VF: renamed from: b short[]
   private short[] field_149;
   // $VF: renamed from: a q[]
   private class_6[] field_150;
   // $VF: renamed from: a boolean
   private boolean field_151;
   // $VF: renamed from: a ay
   private class_101 field_152;
   // $VF: renamed from: b int
   private static int field_153;
   // $VF: renamed from: c int
   private static int field_154;
   // $VF: renamed from: d int
   private static int field_155;
   // $VF: renamed from: a bn
   private static class_1 field_156 = new class_1();

   // $VF: renamed from: a () void
   public static final void method_184() {
      field_153 = 0;
      field_154 = 0;
      field_155 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_185() {
      return field_153;
   }

   public class_6(class_60 var1) {
      field_144.setSeed(var1.field_828 + var1.field_834 + var1.field_833);
      field_154 = 20;
      this.field_147 = field_144.nextInt(2) == 0 ? 3307 : 3308;
      this.field_152 = class_25.method_328(this.field_147);
      this.field_152.method_860(0, 2048, 0);
      this.field_152.field_1294 = 2;
      this.field_148 = this.field_147 == 3307 ? field_145[4] : field_145[5];
      this.field_149 = field_146[1];
      field_154--;
      field_153 = 1;
      this.method_186();
   }

   private class_6(int var1) {
      field_154--;
      this.field_147 = var1;
      switch (var1) {
         case 3301:
         case 3302:
            this.field_148 = field_145[0];
            this.field_149 = field_146[0];
            return;
         case 3304:
         case 3309:
         case 3310:
            this.field_148 = field_145[1];
            this.field_149 = null;
            return;
         case 3305:
            this.field_148 = field_145[2];
            this.field_149 = field_146[1];
            return;
         case 3306:
            this.field_148 = field_145[3];
            this.field_149 = field_146[1];
            return;
         case 3307:
            this.field_148 = field_145[4];
            this.field_149 = field_146[1];
            return;
         case 3308:
            this.field_148 = field_145[5];
            this.field_149 = field_146[1];
         case 3303:
      }
   }

   // $VF: renamed from: b () void
   private void method_186() {
      if (this.field_149 != null) {
         boolean var1 = this.field_147 == 3307 || this.field_147 == 3308 || this.field_147 == 3305 || this.field_147 == 3306;
         this.field_150 = new class_6[var1 ? this.field_148.length + 2 : this.field_148.length];
         boolean[] var2 = new boolean[this.field_150.length];

         for (int var3 = 0; var3 < var2.length; var3++) {
            if (!var1 || var3 > this.field_150.length - 3 || this.field_147 != 3307 && this.field_147 != 3308) {
               if (this.field_147 != 3300 && this.field_147 != 3311 && this.field_147 != 3303) {
                  var2[var3] = field_144.nextInt(100) < this.method_187(this.field_147);
                  var2[0] = false;
               } else {
                  var2[var3] = false;
               }
            } else {
               var2[var3] = true;
            }
         }

         for (int var6 = 0; var6 < this.field_150.length; var6++) {
            if (field_154 <= 0) {
               return;
            }

            if (var2[var6]) {
               int var4 = 3301;
               if (var1 && var6 > this.field_150.length - 3) {
                  if (var6 == this.field_150.length - 1 && this.field_151 && this.field_147 != 3307 && this.field_147 != 3308
                     || !this.field_151 && this.field_147 != 3307 && this.field_147 != 3308) {
                     return;
                  }

                  if (this.field_147 != 3307 && this.field_147 != 3305) {
                     var4 = 3306;
                  } else {
                     var4 = 3305;
                  }

                  if (field_144.nextInt(2) == 0) {
                     if (var6 == this.field_150.length - 1) {
                        if (this.field_151 && this.field_147 != 3307 && this.field_147 != 3308) {
                           return;
                        }

                        var4 = field_144.nextInt(2) == 0 ? 3311 : 3303;
                     } else {
                        if (!this.field_151 && this.field_147 != 3307 && this.field_147 != 3308) {
                           return;
                        }

                        var4 = 3300;
                     }
                  }
               } else {
                  boolean var5 = false;
                  if (this.field_149 != field_146[1]) {
                     var4 = field_144.nextInt(2) == 0 ? 3305 : 3306;
                  }

                  for (; !var5; var4 = this.field_149[field_144.nextInt(this.field_149.length)]) {
                     if (field_144.nextInt(100) < this.method_187(var4)) {
                        var5 = true;
                     }
                  }
               }

               this.field_150[var6] = new class_6(var4);
               this.field_150[var6].field_151 = var6 != this.field_150.length - 1;
               this.field_150[var6].field_152 = class_25.method_328(this.field_150[var6].field_147);
               this.field_150[var6].field_152.field_1294 = 2;
               this.field_150[var6].field_152.method_866(this.field_152.field_1283);
               class_5 var7 = new class_5();
               if (var1 && var6 > this.field_150.length - 3) {
                  var7.method_170(0, var6 == this.field_150.length - 1 ? field_143.field_139 : -field_143.field_139, 0);
               } else {
                  this.field_150[var6].field_152.method_856(0, 2048 - this.field_148[var6], 0);
                  field_156.method_2();
                  field_156.method_23(this.field_152.method_862());
                  field_156.method_19(0, -this.field_148[var6], 0);
                  if (this.field_147 != 3305 && this.field_147 != 3307) {
                     var7 = field_156.method_40(field_142, var7);
                  } else {
                     var7 = field_156.method_40(field_141, var7);
                  }
               }

               this.field_150[var6].field_152.method_840(var7);
               field_153++;
               this.field_150[var6].method_186();
            }
         }
      }
   }

   // $VF: renamed from: a (int) int
   private int method_187(int var1) {
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

   // $VF: renamed from: a (ay[]) ay[]
   public final class_101[] method_188(class_101[] var1) {
      var1[field_155] = this.field_152;
      if (this.field_150 != null) {
         for (int var2 = 0; var2 < this.field_150.length; var2++) {
            if (this.field_150[var2] != null && this.field_150[var2].field_152 != null) {
               field_155++;
               this.field_150[var2].method_188(var1);
            }
         }
      }

      return var1;
   }
}
