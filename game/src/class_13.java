// $VF: renamed from: g
public final class class_13 {
   // $VF: renamed from: a float[]
   public float[] field_120;
   // $VF: renamed from: b float[]
   public float[] field_121;
   // $VF: renamed from: c float[]
   public float[] field_122;
   // $VF: renamed from: a int
   public int field_123;
   // $VF: renamed from: a float
   public float field_124;
   // $VF: renamed from: d float[]
   public float[] field_125;
   // $VF: renamed from: e float[]
   public float[] field_126;
   // $VF: renamed from: f float[]
   public float[] field_127;
   // $VF: renamed from: a int[]
   private int[] field_128 = new int[3];
   // $VF: renamed from: b int[]
   private int[] field_129 = new int[3];
   // $VF: renamed from: a x
   public class_3 field_130 = new class_3();
   // $VF: renamed from: b x
   public class_3 field_131 = new class_3();
   // $VF: renamed from: b int
   public int field_132 = 0;
   // $VF: renamed from: a int[][]
   private int[][] field_133;
   // $VF: renamed from: a long
   private long field_134;

   public class_13(int[][] var1, int var2, long var3) {
      this.field_123 = 0;
      this.field_134 = var3;
      if (var1 != null && var1[var2] != null) {
         this.field_133 = new int[var1[var2].length / 8][];

         for (int var5 = 0; var5 < var1[var2].length / 8; var5++) {
            this.field_133[var5] = new int[8];
            System.arraycopy(var1[var2], var5 * 8, this.field_133[var5], 0, 8);
         }

         this.method_62();
      }
   }

   // $VF: renamed from: c () void
   private void method_62() {
      if (this.field_133 != null) {
         this.field_123 = this.field_133.length;
         this.field_120 = new float[(this.field_123 + 1) * 3];
         this.field_121 = new float[(this.field_123 + 1) * 3];
         this.field_122 = new float[this.field_123 + 1];
         this.field_125 = new float[(this.field_123 + 1) * 3];
         this.field_126 = new float[(this.field_123 + 1) * 3];
         this.field_127 = new float[3];
         this.method_66();
         this.method_65();
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_63(long var1) {
      if (this.field_123 >= 2) {
         if (var1 > this.field_134) {
            var1 %= this.field_134;
         }

         if (this.field_123 == 2) {
            this.method_64((float)var1 / this.field_133[1][0], 0);
         } else {
            for (int var3 = this.field_123 - 1; var3 >= 0; var3--) {
               if (this.field_133[var3][0] < var1) {
                  float var4;
                  if (var3 == 0) {
                     var4 = (float)(var1 - this.field_133[var3][0]) / (this.field_133[var3 + 1][0] - this.field_133[var3][0]);
                  } else if (var3 == this.field_123 - 1) {
                     var4 = (float)(var1 - this.field_133[var3][0]) / (float)(this.field_134 - this.field_133[var3][0]);
                  } else {
                     var4 = (float)(var1 - this.field_133[var3][0]) / (this.field_133[var3 + 1][0] - this.field_133[var3][0]);
                  }

                  this.method_64(var4, var3);
                  return;
               }
            }
         }
      }
   }

   // $VF: renamed from: a (float, int) void
   private void method_64(float var1, int var2) {
      float var3;
      float var4 = (var3 = var1 * var1) * var1;
      float var5 = 2.0F * var4 - 3.0F * var3 + 1.0F;
      float var6 = var4 - 2.0F * var3 + var1;
      float var7 = -2.0F * var4 + 3.0F * var3;
      float var8 = var4 - var3;
      this.field_128[0] = this.field_133[var2][1];
      this.field_128[1] = this.field_133[var2][2];
      this.field_128[2] = this.field_133[var2][3];
      if (var2 == this.field_133.length - 1) {
         this.field_129[0] = this.field_133[0][1];
         this.field_129[1] = this.field_133[0][2];
         this.field_129[2] = this.field_133[0][3];
      } else {
         this.field_129[0] = this.field_133[var2 + 1][1];
         this.field_129[1] = this.field_133[var2 + 1][2];
         this.field_129[2] = this.field_133[var2 + 1][3];
      }

      this.field_130.field_37 = (int)(
         var5 * this.field_128[0] + var6 * this.field_120[var2 * 3] + var7 * this.field_129[0] + var8 * this.field_120[(var2 + 1) * 3]
      );
      this.field_130.field_38 = (int)(
         var5 * this.field_128[1] + var6 * this.field_120[var2 * 3 + 1] + var7 * this.field_129[1] + var8 * this.field_120[(var2 + 1) * 3 + 1]
      );
      this.field_130.field_39 = (int)(
         var5 * this.field_128[2] + var6 * this.field_120[var2 * 3 + 2] + var7 * this.field_129[2] + var8 * this.field_120[(var2 + 1) * 3 + 2]
      );
      this.field_128[0] = this.field_133[var2][4];
      this.field_128[1] = this.field_133[var2][5];
      this.field_128[2] = this.field_133[var2][6];
      if (var2 == this.field_133.length - 1) {
         this.field_129[0] = this.field_133[0][4];
         this.field_129[1] = this.field_133[0][5];
         this.field_129[2] = this.field_133[0][6];
      } else {
         this.field_129[0] = this.field_133[var2 + 1][4];
         this.field_129[1] = this.field_133[var2 + 1][5];
         this.field_129[2] = this.field_133[var2 + 1][6];
      }

      this.field_131.field_37 = (int)(
         var5 * this.field_128[0] + var6 * this.field_121[var2 * 3] + var7 * this.field_129[0] + var8 * this.field_121[(var2 + 1) * 3]
      );
      this.field_131.field_38 = (int)(
         var5 * this.field_128[1] + var6 * this.field_121[var2 * 3 + 1] + var7 * this.field_129[1] + var8 * this.field_121[(var2 + 1) * 3 + 1]
      );
      this.field_131.field_39 = (int)(
         var5 * this.field_128[2] + var6 * this.field_121[var2 * 3 + 2] + var7 * this.field_129[2] + var8 * this.field_121[(var2 + 1) * 3 + 2]
      );
      this.field_128[0] = this.field_133[var2][7];
      if (var2 == this.field_133.length - 1) {
         this.field_129[0] = this.field_133[0][7];
      } else {
         this.field_129[0] = this.field_133[var2 + 1][7];
      }

      this.field_132 = (int)(var5 * this.field_128[0] + var6 * this.field_122[var2] + var7 * this.field_129[0] + var8 * this.field_122[var2 + 1]);
   }

   // $VF: renamed from: a () void
   public final void method_65() {
      if (this.field_123 <= 1) {
         this.field_124 = 0.0F;
      } else {
         this.field_124 = 0.0F;

         for (int var1 = 0; var1 < this.field_123; var1++) {
            int var2 = 1;
            float var3 = 1.0F;

            for (float var4 = 0.0F; var3 > 0.005; var2 *= 2) {
               float var5 = 1.0F / var2;
               this.field_127[0] = this.field_133[var1][1];
               this.field_127[1] = this.field_133[var1][2];
               this.field_127[2] = this.field_133[var1][3];
               this.field_125[var1] = 0.0F;

               for (int var6 = 1; var6 <= var2; var6++) {
                  float var7 = var6 * var5;
                  this.method_64(var7, var1);
                  this.field_125[var1] = (float)(
                     this.field_125[var1]
                        + Math.sqrt(
                           (this.field_130.field_37 - this.field_127[0]) * (this.field_130.field_37 - this.field_127[0])
                              + (this.field_130.field_38 - this.field_127[1]) * (this.field_130.field_38 - this.field_127[1])
                              + (this.field_130.field_39 - this.field_127[2]) * (this.field_130.field_39 - this.field_127[2])
                        )
                  );
                  this.field_127[0] = this.field_130.field_37;
                  this.field_127[1] = this.field_130.field_38;
                  this.field_127[2] = this.field_130.field_39;
               }

               var3 = (this.field_125[var1] - var4) / this.field_125[var1];
               var4 = this.field_125[var1];
            }

            this.field_124 = this.field_124 + this.field_125[var1];
         }

         for (int var8 = 0; var8 < this.field_123; var8++) {
            if (var8 == 0) {
               this.field_126[var8] = this.field_125[var8] / this.field_124;
            } else {
               this.field_126[var8] = this.field_126[var8 - 1] + this.field_125[var8] / this.field_124;
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_66() {
      if (this.field_123 > 1) {
         this.field_120[0] = 0.0F;
         this.field_120[1] = 0.0F;
         this.field_120[2] = 0.0F;
         this.field_120[(this.field_123 - 1) * 3] = 0.0F;
         this.field_120[(this.field_123 - 1) * 3 + 1] = 0.0F;
         this.field_120[(this.field_123 - 1) * 3 + 2] = 0.0F;

         for (int var1 = 0; var1 < this.field_123; var1++) {
            if (var1 == this.field_123 - 1) {
               this.field_128[0] = this.field_133[0][1];
               this.field_128[1] = this.field_133[0][2];
               this.field_128[2] = this.field_133[0][3];
            } else {
               this.field_128[0] = this.field_133[var1 + 1][1];
               this.field_128[1] = this.field_133[var1 + 1][2];
               this.field_128[2] = this.field_133[var1 + 1][3];
            }

            if (var1 == 0) {
               this.field_129[0] = this.field_133[this.field_133.length - 1][1];
               this.field_129[1] = this.field_133[this.field_133.length - 1][2];
               this.field_129[2] = this.field_133[this.field_133.length - 1][3];
            } else {
               this.field_129[0] = this.field_133[var1 - 1][1];
               this.field_129[1] = this.field_133[var1 - 1][2];
               this.field_129[2] = this.field_133[var1 - 1][3];
            }

            this.field_120[var1 * 3] = 0.5F * (this.field_128[0] - this.field_129[0]);
            this.field_120[var1 * 3 + 1] = 0.5F * (this.field_128[1] - this.field_129[1]);
            this.field_120[var1 * 3 + 2] = 0.5F * (this.field_128[2] - this.field_129[2]);
         }

         this.field_120[this.field_123 * 3] = this.field_120[0];
         this.field_120[this.field_123 * 3 + 1] = this.field_120[1];
         this.field_120[this.field_123 * 3 + 2] = this.field_120[2];
         this.field_121[0] = 0.0F;
         this.field_121[1] = 0.0F;
         this.field_121[2] = 0.0F;
         this.field_121[(this.field_123 - 1) * 3] = 0.0F;
         this.field_121[(this.field_123 - 1) * 3 + 1] = 0.0F;
         this.field_121[(this.field_123 - 1) * 3 + 2] = 0.0F;

         for (int var2 = 0; var2 < this.field_123; var2++) {
            if (var2 == this.field_123 - 1) {
               this.field_128[0] = this.field_133[0][4];
               this.field_128[1] = this.field_133[0][5];
               this.field_128[2] = this.field_133[0][6];
            } else {
               this.field_128[0] = this.field_133[var2 + 1][4];
               this.field_128[1] = this.field_133[var2 + 1][5];
               this.field_128[2] = this.field_133[var2 + 1][6];
            }

            if (var2 == 0) {
               this.field_129[0] = this.field_133[this.field_133.length - 1][4];
               this.field_129[1] = this.field_133[this.field_133.length - 1][5];
               this.field_129[2] = this.field_133[this.field_133.length - 1][6];
            } else {
               this.field_129[0] = this.field_133[var2 - 1][4];
               this.field_129[1] = this.field_133[var2 - 1][5];
               this.field_129[2] = this.field_133[var2 - 1][6];
            }

            this.field_121[var2 * 3] = 0.5F * (this.field_128[0] - this.field_129[0]);
            this.field_121[var2 * 3 + 1] = 0.5F * (this.field_128[1] - this.field_129[1]);
            this.field_121[var2 * 3 + 2] = 0.5F * (this.field_128[2] - this.field_129[2]);
         }

         this.field_121[this.field_123 * 3] = this.field_121[0];
         this.field_121[this.field_123 * 3 + 1] = this.field_121[1];
         this.field_121[this.field_123 * 3 + 2] = this.field_121[2];
         this.field_122[0] = 0.0F;
         this.field_122[this.field_123 - 1] = 0.0F;

         for (int var3 = 0; var3 < this.field_123; var3++) {
            if (var3 == this.field_123 - 1) {
               this.field_128[0] = this.field_133[0][7];
            } else {
               this.field_128[0] = this.field_133[var3 + 1][7];
            }

            if (var3 == 0) {
               this.field_129[0] = this.field_133[this.field_133.length - 1][7];
            } else {
               this.field_129[0] = this.field_133[var3 - 1][7];
            }

            this.field_122[var3] = 0.5F * (this.field_128[0] - this.field_129[0]);
         }

         this.field_122[this.field_123] = this.field_122[0];
      }
   }
}
