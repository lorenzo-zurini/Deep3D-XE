// $VF: renamed from: o
public final class class_19 {
   // $VF: renamed from: a short[][][]
   private static final short[][][] field_276 = new short[][][]{
      {{0, 0, 0}},
      {{270, 0, 100}, {-270, 0, 100}},
      {{320, 0, 100}, {0, 0, 100}, {-320, 0, 100}},
      {{370, 0, 100}, {170, 100, 150}, {-170, 100, 150}, {-370, 0, 100}},
      {{350, 100, 200}, {270, -100, 150}, {0, 0, 100}, {-270, -100, 150}, {-350, 100, 200}},
      {{500, 100, 150}, {500, -100, 150}, {200, 0, 100}, {-200, 0, 100}, {-500, -100, 150}, {-500, 100, 150}},
      {{500, -100, 150}, {400, 100, 150}, {200, -50, 100}, {0, 0, 150}, {-200, -50, 100}, {-400, 100, 150}, {-500, -100, 150}},
      {{550, -100, 100}, {550, 100, 100}, {300, 0, 100}, {100, 0, 150}, {-100, 0, 150}, {-300, 0, 100}, {-550, 100, 100}, {-550, -100, 100}},
      {{550, -100, 100}, {550, 100, 100}, {300, 0, 100}, {100, 100, 150}, {0, -100, 100}, {-100, 100, 150}, {-300, 0, 100}, {-550, 100, 100}, {-550, -100, 100}},
      {
            {600, -120, 100},
            {600, 120, 100},
            {400, 0, 100},
            {200, 100, 150},
            {200, -100, 100},
            {-200, -100, 100},
            {-200, 100, 150},
            {-400, 0, 100},
            {-600, 120, 100},
            {-600, -120, 100}
      }
   };
   // $VF: renamed from: a cy
   public class_57 field_277;
   // $VF: renamed from: a cm[]
   public class_96[] field_278;
   // $VF: renamed from: a v[]
   public class_5[] field_279;
   // $VF: renamed from: b v[]
   public class_5[] field_280;
   // $VF: renamed from: a v
   public class_5 field_281;
   // $VF: renamed from: b v
   public class_5 field_282;
   // $VF: renamed from: a cm
   public class_96 field_283;
   // $VF: renamed from: a int[]
   public int[] field_284;
   // $VF: renamed from: e int
   private int field_285;
   // $VF: renamed from: a float
   public float field_286;
   // $VF: renamed from: a int
   public int field_287;
   // $VF: renamed from: c v
   public class_5 field_288;
   // $VF: renamed from: a boolean
   public boolean field_289;
   // $VF: renamed from: d v
   private class_5 field_290;
   // $VF: renamed from: b int
   public int field_291;
   // $VF: renamed from: c int
   public int field_292;
   // $VF: renamed from: b boolean
   public boolean field_293;
   // $VF: renamed from: c boolean
   public boolean field_294;
   // $VF: renamed from: a aj
   public class_103 field_295;
   // $VF: renamed from: f boolean
   private boolean field_296;
   // $VF: renamed from: a aw
   public class_83 field_297;
   // $VF: renamed from: d boolean
   public boolean field_298;
   // $VF: renamed from: a cx
   private class_108 field_299;
   // $VF: renamed from: f int
   private int field_300;
   // $VF: renamed from: d int
   public int field_301;
   // $VF: renamed from: e boolean
   public boolean field_302;

   public class_19(int var1, int var2, int var3, int var4, int var5, float var6, class_5 var7, class_5 var8) {
      this.field_285 = var1;
      this.field_286 = var6;
      this.field_288 = var7;
      this.field_287 = var4;
      this.field_292 = var5;
      this.field_291 = 0;
      this.field_284 = new int[var2];
      this.field_279 = new class_5[var2];
      this.field_280 = new class_5[var2];
      this.field_281 = new class_5();
      this.field_282 = new class_5();

      for (int var9 = 0; var9 < var2; var9++) {
         this.field_279[var9] = new class_5(50000, 0, 0);
         this.field_280[var9] = new class_5();
         this.field_284[var9] = -1;
      }

      this.field_294 = true;
      this.field_289 = false;
      this.field_290 = new class_5();
      this.field_293 = false;
      this.field_295 = null;
      this.field_296 = false;
      this.field_278 = null;
      this.field_298 = false;
      this.field_299 = null;
      this.field_302 = false;
   }

   // $VF: renamed from: a (int, cx) void
   public final void method_279(int var1, class_108 var2) {
      this.field_299 = var2;
      this.field_298 = true;
      this.field_300 = var1 * 200;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_280(int var1, int var2) {
      short[] var3 = field_276[var2 - 1][var1];
      this.field_290.method_169(this.field_288);
      this.field_288 = new class_5(var3[0] + this.field_290.field_138, var3[1] + this.field_290.field_139, var3[2] + this.field_290.field_140);
   }

   // $VF: renamed from: a () void
   public final void method_281() {
      this.field_277 = null;
      this.field_278 = null;
      this.field_279 = null;
      this.field_280 = null;
      this.field_281 = null;
      this.field_282 = null;
      this.field_283 = null;
      this.field_284 = null;
      this.field_288 = null;
      this.field_295 = null;
   }

   // $VF: renamed from: a (aj) void
   public final void method_282(class_103 var1) {
      this.field_295 = var1;
      if (var1.field_1303) {
         this.field_296 = true;
      }
   }

   // $VF: renamed from: a (bn, long, cm, boolean) boolean
   public final boolean method_283(class_1 var1, long var2, class_96 var4, boolean var5) {
      if (this.field_299 != null && this.field_298 && this.field_299.field_1349) {
         return false;
      } else {
         this.field_291 = 0;
         this.field_289 = true;
         this.field_293 = true;

         for (int var6 = 0; var6 < this.field_279.length; var6++) {
            if (this.field_284[var6] <= 0) {
               this.field_279[var6].method_169(var1.method_12(this.field_290));
               if (this.field_288 != null) {
                  this.field_290.method_169(this.field_288);
                  this.field_281 = var1.method_40(this.field_290, this.field_281);
                  this.field_279[var6].method_175(this.field_281);
               }

               if (var4 == null) {
                  this.field_290.method_169(var1.method_14(this.field_290));
               } else {
                  this.field_290.method_176(var4.method_823(this.field_290), this.field_279[var6]);
               }

               this.field_280[var6].method_169(this.field_290);
               this.field_280[var6].method_182();
               this.field_280[var6].method_178((int)(this.field_286 * (float)var2) << 12);
               this.field_280[var6].field_138 >>= 12;
               this.field_280[var6].field_139 >>= 12;
               this.field_280[var6].field_140 >>= 12;
               this.field_284[var6] = this.field_287;
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (bn, long, boolean) boolean
   public final boolean method_284(class_1 var1, long var2, boolean var4) {
      return this.method_283(var1, var2, null, var4);
   }

   // $VF: renamed from: c () void
   private void method_285() {
      if (this.field_278 != null) {
         this.field_297 = null;

         for (int var1 = 0; var1 < this.field_278.length; var1++) {
            this.field_283 = this.field_278[var1];
            if (this.field_283.field_1268) {
               for (int var2 = 0; var2 < this.field_279.length; var2++) {
                  this.field_281.method_169(this.field_279[var2]);
                  this.field_282.method_169(this.field_280[var2]);
                  int var3 = this.field_283.field_1270.field_13 - this.field_281.field_138 + this.field_282.field_138;
                  int var4 = this.field_283.field_1270.field_14 - this.field_281.field_139 + this.field_282.field_139;
                  int var5 = this.field_283.field_1270.field_15 - this.field_281.field_140 + this.field_282.field_140;
                  int var6 = this.field_298 ? this.field_300 : (int)this.field_283.field_1255;
                  if (var3 < var6 && var3 > -var6 && var4 < var6 && var4 > -var6 && var5 < var6 && var5 > -var6) {
                     this.field_283.method_821(this.field_285, this.field_302);
                     this.field_283.method_816(-this.field_282.field_138, -this.field_282.field_139, -this.field_282.field_140);
                     this.field_284[var2] = -1;
                     this.field_290.method_169(this.field_280[var2]);
                     this.field_290.method_182();
                     this.field_297 = this.field_283.field_1272;
                     if (this.field_295 != null) {
                        this.field_295.method_886(this.field_279[var2], this.field_290);
                     }
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: b (long) void
   private void method_286(long var1) {
      this.field_290.method_170(0, 0, 0);
      if (this.field_277 != null) {
         for (int var3 = 0; var3 < this.field_279.length; var3++) {
            if (this.field_284[var3] > 0 && this.field_277.method_552(this.field_279[var3], !this.field_296)) {
               this.field_284[var3] = -1;
               this.field_290.method_169(this.field_280[var3]);
               this.field_290.method_182();
               if (this.field_295 != null) {
                  this.field_295.method_886(this.field_279[var3], this.field_290);
               }
            }
         }
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_287(long var1) {
      this.field_291 = (int)(this.field_291 + var1);
      if (this.field_295 != null) {
         this.field_295.method_885(var1);
      }

      if (this.field_293) {
         this.method_285();
         if (this.field_294) {
            this.method_286(var1);
         }

         for (int var3 = 0; var3 < this.field_279.length; var3++) {
            if (this.field_284[var3] > 0) {
               this.field_284[var3] = this.field_284[var3] - (int)var1;
               this.field_279[var3].method_175(this.field_280[var3]);
            } else {
               this.field_279[var3].method_170(50000, 50000, 50000);
               this.field_280[var3].method_170(0, 0, 0);
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_288() {
      if (this.field_295 != null) {
         this.field_295.method_878();
      }
   }
}
