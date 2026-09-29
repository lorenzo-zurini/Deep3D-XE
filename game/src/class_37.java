// $VF: renamed from: cm
public final class class_37 {
   // $VF: renamed from: a n[][]
   public class_9[][] field_359;
   // $VF: renamed from: a cm[]
   public class_37[] field_360;
   // $VF: renamed from: b cm[]
   public class_37[] field_361;
   // $VF: renamed from: a float
   public float field_362;
   // $VF: renamed from: a int
   public int field_363;
   // $VF: renamed from: b int
   public int field_364;
   // $VF: renamed from: c int
   public int field_365;
   // $VF: renamed from: k int
   private int field_366;
   // $VF: renamed from: d int
   public int field_367;
   // $VF: renamed from: l int
   private int field_368;
   // $VF: renamed from: e int
   public int field_369;
   // $VF: renamed from: f int
   public int field_370;
   // $VF: renamed from: g int
   public int field_371;
   // $VF: renamed from: h int
   public int field_372;
   // $VF: renamed from: a int[]
   private int[] field_373;
   // $VF: renamed from: m int
   private int field_374;
   // $VF: renamed from: a boolean
   public boolean field_375;
   // $VF: renamed from: d boolean
   private boolean field_376;
   // $VF: renamed from: a bn
   public class_57 field_377;
   // $VF: renamed from: a x
   private class_3 field_378 = new class_3();
   // $VF: renamed from: a aw
   public class_91 field_379;
   // $VF: renamed from: b boolean
   public boolean field_380;
   // $VF: renamed from: i int
   public int field_381;
   // $VF: renamed from: j int
   public int field_382;
   // $VF: renamed from: c boolean
   public boolean field_383;

   public class_37(float var1, int var2, int var3) {
      this.field_362 = var1;
      this.field_363 = var2;
      this.field_364 = var2;
      this.method_336();
      this.field_369 = var3;
      if (var3 > 0) {
         this.field_359 = new class_9[var3][];
      }

      this.field_377 = new class_57();
      this.field_375 = true;
      this.field_376 = true;
      this.field_373 = new int[6];
      this.field_373[0] = 1000000;
      this.field_379 = null;
      this.field_380 = false;
      this.field_383 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_321() {
      return this.field_379 != null ? this.field_379.field_1238 : false;
   }

   // $VF: renamed from: a (int) void
   public final void method_322(int var1) {
      this.field_362 = var1;
   }

   // $VF: renamed from: a (cm[]) void
   public final void method_323(class_37[] var1) {
      this.field_360 = var1;
      if (this.field_359 != null) {
         for (int var2 = 0; var2 < this.field_359.length; var2++) {
            if (this.field_359[var2] != null) {
               for (int var3 = 0; var3 < this.field_359[var2].length; var3++) {
                  if (this.field_359[var2][var3] != null) {
                     this.field_359[var2][var3].field_77 = this.field_360;
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: a (cm) void
   public final void method_324(class_37 var1) {
      class_37[] var2;
      (var2 = new class_37[1])[0] = var1;
      this.method_323(var2);
   }

   // $VF: renamed from: b (cm[]) void
   public final void method_325(class_37[] var1) {
      if (this.field_360 == null) {
         this.method_323(var1);
      } else {
         class_37[] var2 = new class_37[this.field_360.length + var1.length];

         for (int var3 = 0; var3 < this.field_360.length; var3++) {
            var2[var3] = this.field_360[var3];
         }

         for (int var4 = 0; var4 < var1.length; var4++) {
            var2[this.field_360.length + var4] = var1[var4];
         }

         this.method_323(var2);
      }
   }

   // $VF: renamed from: a (int) cm
   public final class_37 method_326(int var1) {
      return this.field_360[var1];
   }

   // $VF: renamed from: b (int) void
   public final void method_327(int var1) {
      this.field_363 = var1;
      if (this.field_363 > this.field_364) {
         this.field_364 = this.field_363;
      }

      this.method_336();
   }

   // $VF: renamed from: c (int) void
   public final void method_328(int var1) {
      this.field_365 = var1;
      if (this.field_365 > this.field_366) {
         this.field_365 = this.field_366;
      }

      this.method_336();
   }

   // $VF: renamed from: d (int) void
   public final void method_329(int var1) {
      this.field_367 = var1;
      if (this.field_367 > this.field_368) {
         this.field_367 = this.field_368;
      }

      this.method_336();
   }

   // $VF: renamed from: e (int) void
   public final void method_330(int var1) {
      this.field_364 = var1;
      this.field_363 = var1;
      this.method_336();
   }

   // $VF: renamed from: f (int) void
   public final void method_331(int var1) {
      this.field_366 = var1;
      this.field_365 = var1;
      this.method_336();
   }

   // $VF: renamed from: g (int) void
   public final void method_332(int var1) {
      this.field_368 = var1;
      this.field_367 = var1;
      this.method_336();
   }

   // $VF: renamed from: a () int
   public final int method_333() {
      return this.field_365 + this.field_367 + this.field_363;
   }

   // $VF: renamed from: a () void
   public final void method_334() {
      if (this.field_365 + 1 < this.field_366) {
         this.field_365++;
      } else {
         this.field_365 = this.field_366;
      }

      this.method_336();
   }

   // $VF: renamed from: b () void
   public final void method_335() {
      if (this.field_363 + 1 < this.field_364) {
         this.field_363++;
      } else {
         this.field_363 = this.field_364;
      }

      this.method_336();
   }

   // $VF: renamed from: d () void
   private void method_336() {
      this.field_370 = (int)((float)this.field_363 / this.field_364 * 100.0F);
      this.field_371 = (int)((float)this.field_365 / this.field_366 * 100.0F);
      this.field_372 = (int)((float)this.field_367 / this.field_368 * 100.0F);
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_337(int var1, int var2, int var3) {
      this.field_378.field_37 = var1;
      this.field_378.field_38 = var2;
      this.field_378.field_39 = var3;
   }

   // $VF: renamed from: a (int) float
   public final float method_338(int var1) {
      if (this.field_359 != null) {
         Object var2 = null;
         if (var1 == this.field_382) {
            var2 = this.field_359[var1][this.field_381];
         } else {
            var2 = this.field_359[var1][0];
         }

         if (var2 != null) {
            return (float)((class_9)var2).field_90 / ((class_9)var2).field_91;
         }
      }

      return 0.0F;
   }

   // $VF: renamed from: h (int) void
   public final void method_339(int var1) {
      if (Deep3dDebug.godFor(this)) {
         return; // Deep3D-PC: god mode
      }
      if (this.field_376 && this.field_375) {
         if (this.field_367 <= 0) {
            this.method_341(var1);
         } else {
            this.field_367 -= var1;
         }

         if (this.field_367 < 0) {
            this.field_367 = 0;
         }

         this.method_336();
      }
   }

   // $VF: renamed from: i (int) void
   public final void method_340(int var1) {
      if (Deep3dDebug.godFor(this)) {
         return; // Deep3D-PC: god mode
      }
      if (this.field_376 && this.field_375) {
         if (this.field_365 <= 0) {
            this.method_341(var1);
         } else {
            this.field_365 -= var1;
         }

         if (this.field_365 < 0) {
            this.field_365 = 0;
         }

         this.method_336();
      }
   }

   // $VF: renamed from: j (int) void
   public final void method_341(int var1) {
      if (Deep3dDebug.godFor(this)) {
         return; // Deep3D-PC: god mode
      }
      this.field_363 -= var1;
      if (this.field_363 < 0) {
         this.field_363 = 0;
      }
   }

   // $VF: renamed from: a (int, boolean) void
   public final void method_342(int var1, boolean var2) {
      if (Deep3dDebug.godFor(this)) {
         return; // Deep3D-PC: god mode
      }
      if (this.field_376 && this.field_375) {
         int var3;
         if ((var3 = this.field_365 - var1) < 0) {
            this.field_365 = 0;
            int var4;
            if ((var4 = this.field_367 - -var3) < 0) {
               this.field_367 = 0;
               this.field_363 -= -var4;
            } else {
               this.field_367 = var4;
            }
         } else {
            this.field_365 = var3;
         }

         if (this.field_363 < 0) {
            this.field_363 = 0;
            if (var2) {
               this.field_383 = true;
            }
         }

         this.method_336();
      }
   }

   // $VF: renamed from: k (int) void
   public final void method_343(int var1) {
      this.method_342(var1, false);
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_344(class_3 var1) {
      return this.field_377.method_479(var1);
   }

   // $VF: renamed from: b () boolean
   public final boolean method_345() {
      return this.field_363 <= 0;
   }

   // $VF: renamed from: a (n, int) void
   public final void method_346(class_9 var1, int var2) {
      if (this.field_359 != null) {
         if (var2 <= this.field_369 && var2 >= 0) {
            this.field_359[var2] = new class_9[1];
            this.field_359[var2][0] = var1;
         }

         this.method_348();
      }
   }

   // $VF: renamed from: a (n[], int) void
   public final void method_347(class_9[] var1, int var2) {
      if (this.field_359 != null) {
         if (var2 <= this.field_369 && var2 >= 0) {
            this.field_359[var2] = new class_9[var1.length];
            this.field_359[var2] = var1;
         }

         this.method_348();
      }
   }

   // $VF: renamed from: e () void
   private void method_348() {
      int var1 = 0;
      this.field_381 = 0;
      if (this.field_359 != null) {
         for (int var2 = 0; var2 < this.field_359.length; var2++) {
            if (this.field_359[var2] != null) {
               for (int var3 = 0; var3 < this.field_359[var2].length; var3++) {
                  if (this.field_359[var2][var3].field_91 > var1 && !this.field_359[var2][var3].field_97) {
                     var1 = this.field_359[var2][var3].field_91;
                     this.field_382 = var2;
                     this.field_381 = var3;
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_349() {
      this.field_369 = 0;
      this.field_359 = (class_9[][])null;
   }

   // $VF: renamed from: a (int) int
   public final int method_350(int var1) {
      return this.field_359[var1][0].field_100;
   }

   // $VF: renamed from: l (int) void
   public final void method_351(int var1) {
      if (this.field_359 != null && var1 < this.field_359.length && var1 >= 0 && this.field_359[var1] != null) {
         for (int var2 = 0; var2 < this.field_359[var1].length; var2++) {
            this.field_359[var1][var2].field_90 = 0;
         }
      }
   }

   // $VF: renamed from: a (int, long, boolean) void
   public final void method_352(int var1, long var2, boolean var4) {
      if (this.field_359 != null && var1 < this.field_359.length && var1 >= 0 && this.field_359[var1] != null) {
         for (int var5 = 0; var5 < this.field_359[var1].length; var5++) {
            if (this.field_359[var1][var5].field_90 > this.field_359[var1][var5].field_91 && this.field_359[var1][var5].method_46(this.field_377, var2, var4)) {
               this.field_359[var1][var5].field_90 = 0;
               if (this.field_380 && this.field_359[var1][var5].field_97) {
                  class_84.field_1122.method_770(5);
               }
            }
         }
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_353(long var1) {
      this.field_374 = (int)(this.field_374 + var1);
      if (this.field_374 > 3000) {
         this.field_374 = 0;
      }
   }
}
