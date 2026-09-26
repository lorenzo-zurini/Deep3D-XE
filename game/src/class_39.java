// $VF: renamed from: h
public final class class_39 {
   // $VF: renamed from: a float[]
   public float[] field_480;
   // $VF: renamed from: b float[]
   public float[] field_481;
   // $VF: renamed from: c float[]
   public float[] field_482;
   // $VF: renamed from: a int
   public int field_483;
   // $VF: renamed from: a float
   public float field_484;
   // $VF: renamed from: d float[]
   public float[] field_485;
   // $VF: renamed from: e float[]
   public float[] field_486;
   // $VF: renamed from: f float[]
   public float[] field_487;
   // $VF: renamed from: a int[]
   private int[] field_488 = new int[3];
   // $VF: renamed from: b int[]
   private int[] field_489 = new int[3];
   // $VF: renamed from: a v
   public class_5 field_490 = new class_5();
   // $VF: renamed from: b v
   public class_5 field_491 = new class_5();
   // $VF: renamed from: b int
   public int field_492 = 0;
   // $VF: renamed from: a int[][]
   private int[][] field_493;
   // $VF: renamed from: a long
   private long field_494;

   public class_39(int[][] var1, int var2, long var3) {
      this.field_483 = 0;
      this.field_494 = var3;
      if (var1 != null && var1[var2] != null) {
         this.field_493 = new int[var1[var2].length / 8][];

         for (int var5 = 0; var5 < var1[var2].length / 8; var5++) {
            this.field_493[var5] = new int[8];
            System.arraycopy(var1[var2], var5 * 8, this.field_493[var5], 0, 8);
         }

         this.method_405();
      }
   }

   // $VF: renamed from: c () void
   private void method_405() {
      if (this.field_493 != null) {
         this.field_483 = this.field_493.length;
         this.field_480 = new float[(this.field_483 + 1) * 3];
         this.field_481 = new float[(this.field_483 + 1) * 3];
         this.field_482 = new float[this.field_483 + 1];
         this.field_485 = new float[(this.field_483 + 1) * 3];
         this.field_486 = new float[(this.field_483 + 1) * 3];
         this.field_487 = new float[3];
         this.method_409();
         this.method_408();
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_406(long var1) {
      if (this.field_483 >= 2) {
         if (var1 > this.field_494) {
            var1 %= this.field_494;
         }

         if (this.field_483 == 2) {
            this.method_407((float)var1 / this.field_493[1][0], 0);
         } else {
            for (int var3 = this.field_483 - 1; var3 >= 0; var3--) {
               if (this.field_493[var3][0] < var1) {
                  float var4;
                  if (var3 == 0) {
                     var4 = (float)(var1 - this.field_493[var3][0]) / (this.field_493[var3 + 1][0] - this.field_493[var3][0]);
                  } else if (var3 == this.field_483 - 1) {
                     var4 = (float)(var1 - this.field_493[var3][0]) / (float)(this.field_494 - this.field_493[var3][0]);
                  } else {
                     var4 = (float)(var1 - this.field_493[var3][0]) / (this.field_493[var3 + 1][0] - this.field_493[var3][0]);
                  }

                  this.method_407(var4, var3);
                  return;
               }
            }
         }
      }
   }

   // $VF: renamed from: a (float, int) void
   private void method_407(float var1, int var2) {
      float var3;
      float var4 = (var3 = var1 * var1) * var1;
      float var5 = 2.0F * var4 - 3.0F * var3 + 1.0F;
      float var6 = var4 - 2.0F * var3 + var1;
      float var7 = -2.0F * var4 + 3.0F * var3;
      float var8 = var4 - var3;
      this.field_488[0] = this.field_493[var2][1];
      this.field_488[1] = this.field_493[var2][2];
      this.field_488[2] = this.field_493[var2][3];
      if (var2 == this.field_493.length - 1) {
         this.field_489[0] = this.field_493[0][1];
         this.field_489[1] = this.field_493[0][2];
         this.field_489[2] = this.field_493[0][3];
      } else {
         this.field_489[0] = this.field_493[var2 + 1][1];
         this.field_489[1] = this.field_493[var2 + 1][2];
         this.field_489[2] = this.field_493[var2 + 1][3];
      }

      this.field_490.field_138 = (int)(
         var5 * this.field_488[0] + var6 * this.field_480[var2 * 3] + var7 * this.field_489[0] + var8 * this.field_480[(var2 + 1) * 3]
      );
      this.field_490.field_139 = (int)(
         var5 * this.field_488[1] + var6 * this.field_480[var2 * 3 + 1] + var7 * this.field_489[1] + var8 * this.field_480[(var2 + 1) * 3 + 1]
      );
      this.field_490.field_140 = (int)(
         var5 * this.field_488[2] + var6 * this.field_480[var2 * 3 + 2] + var7 * this.field_489[2] + var8 * this.field_480[(var2 + 1) * 3 + 2]
      );
      this.field_488[0] = this.field_493[var2][4];
      this.field_488[1] = this.field_493[var2][5];
      this.field_488[2] = this.field_493[var2][6];
      if (var2 == this.field_493.length - 1) {
         this.field_489[0] = this.field_493[0][4];
         this.field_489[1] = this.field_493[0][5];
         this.field_489[2] = this.field_493[0][6];
      } else {
         this.field_489[0] = this.field_493[var2 + 1][4];
         this.field_489[1] = this.field_493[var2 + 1][5];
         this.field_489[2] = this.field_493[var2 + 1][6];
      }

      this.field_491.field_138 = (int)(
         var5 * this.field_488[0] + var6 * this.field_481[var2 * 3] + var7 * this.field_489[0] + var8 * this.field_481[(var2 + 1) * 3]
      );
      this.field_491.field_139 = (int)(
         var5 * this.field_488[1] + var6 * this.field_481[var2 * 3 + 1] + var7 * this.field_489[1] + var8 * this.field_481[(var2 + 1) * 3 + 1]
      );
      this.field_491.field_140 = (int)(
         var5 * this.field_488[2] + var6 * this.field_481[var2 * 3 + 2] + var7 * this.field_489[2] + var8 * this.field_481[(var2 + 1) * 3 + 2]
      );
      this.field_488[0] = this.field_493[var2][7];
      if (var2 == this.field_493.length - 1) {
         this.field_489[0] = this.field_493[0][7];
      } else {
         this.field_489[0] = this.field_493[var2 + 1][7];
      }

      this.field_492 = (int)(var5 * this.field_488[0] + var6 * this.field_482[var2] + var7 * this.field_489[0] + var8 * this.field_482[var2 + 1]);
   }

   // $VF: renamed from: a () void
   public final void method_408() {
      if (this.field_483 <= 1) {
         this.field_484 = 0.0F;
      } else {
         this.field_484 = 0.0F;

         for (int var1 = 0; var1 < this.field_483; var1++) {
            byte var2 = 1;
            float var3 = 1.0F;

            for (float var4 = 0.0F; var3 > 0.005; var2 *= 2) {
               float var5 = 1.0F / var2;
               this.field_487[0] = this.field_493[var1][1];
               this.field_487[1] = this.field_493[var1][2];
               this.field_487[2] = this.field_493[var1][3];
               this.field_485[var1] = 0.0F;

               for (int var6 = 1; var6 <= var2; var6++) {
                  float var7 = var6 * var5;
                  this.method_407(var7, var1);
                  this.field_485[var1] = (float)(
                     this.field_485[var1]
                        + Math.sqrt(
                           (this.field_490.field_138 - this.field_487[0]) * (this.field_490.field_138 - this.field_487[0])
                              + (this.field_490.field_139 - this.field_487[1]) * (this.field_490.field_139 - this.field_487[1])
                              + (this.field_490.field_140 - this.field_487[2]) * (this.field_490.field_140 - this.field_487[2])
                        )
                  );
                  this.field_487[0] = this.field_490.field_138;
                  this.field_487[1] = this.field_490.field_139;
                  this.field_487[2] = this.field_490.field_140;
               }

               var3 = (this.field_485[var1] - var4) / this.field_485[var1];
               var4 = this.field_485[var1];
            }

            this.field_484 = this.field_484 + this.field_485[var1];
         }

         for (int var8 = 0; var8 < this.field_483; var8++) {
            if (var8 == 0) {
               this.field_486[var8] = this.field_485[var8] / this.field_484;
            } else {
               this.field_486[var8] = this.field_486[var8 - 1] + this.field_485[var8] / this.field_484;
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_409() {
      if (this.field_483 > 1) {
         this.field_480[0] = 0.0F;
         this.field_480[1] = 0.0F;
         this.field_480[2] = 0.0F;
         this.field_480[(this.field_483 - 1) * 3] = 0.0F;
         this.field_480[(this.field_483 - 1) * 3 + 1] = 0.0F;
         this.field_480[(this.field_483 - 1) * 3 + 2] = 0.0F;

         for (int var1 = 0; var1 < this.field_483; var1++) {
            if (var1 == this.field_483 - 1) {
               this.field_488[0] = this.field_493[0][1];
               this.field_488[1] = this.field_493[0][2];
               this.field_488[2] = this.field_493[0][3];
            } else {
               this.field_488[0] = this.field_493[var1 + 1][1];
               this.field_488[1] = this.field_493[var1 + 1][2];
               this.field_488[2] = this.field_493[var1 + 1][3];
            }

            if (var1 == 0) {
               this.field_489[0] = this.field_493[this.field_493.length - 1][1];
               this.field_489[1] = this.field_493[this.field_493.length - 1][2];
               this.field_489[2] = this.field_493[this.field_493.length - 1][3];
            } else {
               this.field_489[0] = this.field_493[var1 - 1][1];
               this.field_489[1] = this.field_493[var1 - 1][2];
               this.field_489[2] = this.field_493[var1 - 1][3];
            }

            this.field_480[var1 * 3] = 0.5F * (this.field_488[0] - this.field_489[0]);
            this.field_480[var1 * 3 + 1] = 0.5F * (this.field_488[1] - this.field_489[1]);
            this.field_480[var1 * 3 + 2] = 0.5F * (this.field_488[2] - this.field_489[2]);
         }

         this.field_480[this.field_483 * 3] = this.field_480[0];
         this.field_480[this.field_483 * 3 + 1] = this.field_480[1];
         this.field_480[this.field_483 * 3 + 2] = this.field_480[2];
         this.field_481[0] = 0.0F;
         this.field_481[1] = 0.0F;
         this.field_481[2] = 0.0F;
         this.field_481[(this.field_483 - 1) * 3] = 0.0F;
         this.field_481[(this.field_483 - 1) * 3 + 1] = 0.0F;
         this.field_481[(this.field_483 - 1) * 3 + 2] = 0.0F;

         for (int var2 = 0; var2 < this.field_483; var2++) {
            if (var2 == this.field_483 - 1) {
               this.field_488[0] = this.field_493[0][4];
               this.field_488[1] = this.field_493[0][5];
               this.field_488[2] = this.field_493[0][6];
            } else {
               this.field_488[0] = this.field_493[var2 + 1][4];
               this.field_488[1] = this.field_493[var2 + 1][5];
               this.field_488[2] = this.field_493[var2 + 1][6];
            }

            if (var2 == 0) {
               this.field_489[0] = this.field_493[this.field_493.length - 1][4];
               this.field_489[1] = this.field_493[this.field_493.length - 1][5];
               this.field_489[2] = this.field_493[this.field_493.length - 1][6];
            } else {
               this.field_489[0] = this.field_493[var2 - 1][4];
               this.field_489[1] = this.field_493[var2 - 1][5];
               this.field_489[2] = this.field_493[var2 - 1][6];
            }

            this.field_481[var2 * 3] = 0.5F * (this.field_488[0] - this.field_489[0]);
            this.field_481[var2 * 3 + 1] = 0.5F * (this.field_488[1] - this.field_489[1]);
            this.field_481[var2 * 3 + 2] = 0.5F * (this.field_488[2] - this.field_489[2]);
         }

         this.field_481[this.field_483 * 3] = this.field_481[0];
         this.field_481[this.field_483 * 3 + 1] = this.field_481[1];
         this.field_481[this.field_483 * 3 + 2] = this.field_481[2];
         this.field_482[0] = 0.0F;
         this.field_482[this.field_483 - 1] = 0.0F;

         for (int var3 = 0; var3 < this.field_483; var3++) {
            if (var3 == this.field_483 - 1) {
               this.field_488[0] = this.field_493[0][7];
            } else {
               this.field_488[0] = this.field_493[var3 + 1][7];
            }

            if (var3 == 0) {
               this.field_489[0] = this.field_493[this.field_493.length - 1][7];
            } else {
               this.field_489[0] = this.field_493[var3 - 1][7];
            }

            this.field_482[var3] = 0.5F * (this.field_488[0] - this.field_489[0]);
         }

         this.field_482[this.field_483] = this.field_482[0];
      }
   }
}
