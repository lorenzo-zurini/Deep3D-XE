// $VF: renamed from: cz
public final class class_26 {
   // $VF: renamed from: e int
   private int field_262;
   // $VF: renamed from: a dp
   public static class_29 field_263 = new class_30(0, 0, 0, 0, 0, 0, 10000);
   // $VF: renamed from: a int[][]
   private static final int[][] field_264 = new int[][]{{-1100, 200, 1100}, {-951, 161, -1500}, {-823, 115, -4100}};
   // $VF: renamed from: a ax
   private class_108 field_265;
   // $VF: renamed from: a ak
   private class_116 field_266;
   // $VF: renamed from: b ak
   private class_116 field_267;
   // $VF: renamed from: c ak
   private class_116 field_268;
   // $VF: renamed from: a ax[]
   private class_108[] field_269;
   // $VF: renamed from: b ax[]
   private class_108[] field_270;
   // $VF: renamed from: c ax[]
   private class_108[] field_271;
   // $VF: renamed from: a ba
   public class_70 field_272;
   // $VF: renamed from: a aw[]
   public class_91[] field_273;
   // $VF: renamed from: b aw[]
   public class_91[] field_274;
   // $VF: renamed from: c aw[]
   public class_91[] field_275;
   // $VF: renamed from: d aw[]
   public class_91[] field_276;
   // $VF: renamed from: a dr
   public class_18 field_277;
   // $VF: renamed from: b dr
   private class_18 field_278;
   // $VF: renamed from: c dr
   private class_18 field_279;
   // $VF: renamed from: a dk[]
   public class_20[] field_280;
   // $VF: renamed from: a int
   public int field_281;
   // $VF: renamed from: b int
   public int field_282;
   // $VF: renamed from: f int
   private int field_283;
   // $VF: renamed from: g int
   private int field_284;
   // $VF: renamed from: h int
   private int field_285;
   // $VF: renamed from: a java.lang.String
   public String field_286 = "";
   // $VF: renamed from: c int
   public int field_287;
   // $VF: renamed from: i int
   private int field_288;
   // $VF: renamed from: a dh
   public class_22 field_289;
   // $VF: renamed from: b dh
   public class_22 field_290;
   // $VF: renamed from: d int
   public int field_291;
   // $VF: renamed from: j int
   private int field_292;
   // $VF: renamed from: a boolean
   public boolean field_293;
   // $VF: renamed from: k int
   private int field_294;
   // $VF: renamed from: a float
   private float field_295;
   // $VF: renamed from: b float
   private float field_296;
   // $VF: renamed from: c float
   private float field_297;
   // $VF: renamed from: l int
   private int field_298;
   // $VF: renamed from: m int
   private int field_299;
   // $VF: renamed from: n int
   private int field_300;
   // $VF: renamed from: b boolean
   public static boolean field_301;
   // $VF: renamed from: a ao
   public static class_86 field_302;

   public class_26() {
      this(3);
   }

   public class_26(int var1) {
      this.field_262 = var1;
      this.field_292 = 0;
      this.field_293 = false;
   }

   // $VF: renamed from: a () void
   public static final void method_239() {
      field_301 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_240() {
      if (this.field_292 == 0 || this.field_293) {
         this.field_277 = null;
         this.field_279 = null;
         this.field_278 = null;
         this.field_290 = null;
         this.field_289 = null;
         this.field_266 = new class_116(class_43.method_380(2), 96, 0, 127, 32, 10, 700, 100, 500);
         this.field_268 = new class_116(class_43.method_380(2), 96, 0, 127, 32, 10, 700, 100, 500);
         this.method_241();
         if (this.field_262 != 0) {
            this.method_244();
            if (field_301 && this.field_272.field_970 != null) {
               this.field_272
                  .method_670(this.field_276[2].field_1226.method_852(), this.field_276[2].field_1226.method_853(), this.field_276[2].field_1226.method_854());
            } else {
               this.field_272.method_670(10, 0, 5000);
            }

            if (class_21.method_143() == 1) {
               this.field_272.method_670(0, 0, -110000);
            }
         }
      }

      if (this.field_292 != 1 && !this.field_293) {
         if (this.field_293) {
            this.field_292 = 0;
            return true;
         }
      } else {
         this.method_242();
         if ((this.field_262 != 3 || class_21.method_132().field_1161) && (this.field_262 != 3 || !class_21.method_146())) {
            if (this.field_262 != 3) {
               this.method_249();
               this.field_262 = 3;
            } else if (!class_21.method_132().method_754() && class_21.method_132().field_1161) {
               this.method_248();
            }
         } else {
            this.method_247();
         }

         this.method_250();
         this.method_251();
         if (this.field_272 != null) {
            this.field_272.field_982 = this.field_277;
         }

         this.field_282 = this.field_274 != null ? this.field_274.length - this.field_284 : 0;
         this.field_281 = this.field_273 != null ? this.field_273.length - this.field_283 : 0;
         this.field_285 = 0;
         if (class_21.method_132().field_1146 == 7) {
            if (this.field_275 != null) {
               for (int var1 = 0; var1 < this.field_275.length; var1++) {
                  if (((class_101)this.field_275[var1]).field_1312.field_391 == class_21.method_132().field_1166) {
                     this.field_285++;
                  }
               }
            }
         } else {
            this.field_285 = this.field_275 != null ? this.field_275.length : 0;
         }

         this.field_286 = (int)((float)this.field_285 / class_21.method_132().field_1167 * 100.0F) + "%/" + class_21.method_132().field_1169 + "%";
         this.field_288 = 0;
         this.field_293 = true;
      }

      this.field_292++;
      return this.field_293;
   }

   // $VF: renamed from: b () void
   public final void method_241() {
      if (this.field_265 == null) {
         this.field_265 = class_43.method_381(9991);
      }

      this.field_265.method_893(class_43.method_380(0));
      this.field_276 = new class_91[3];
      if (class_21.method_147()) {
         this.field_276[0] = null;
      } else {
         this.field_276[0] = new class_100(class_21.method_180());
      }

      class_3 var1 = new class_3();
      class_3 var2 = new class_3(var1);
      this.field_294 = 0;

      for (int var3 = 1; var3 <= 2; var3++) {
         if (class_21.method_180() != null) {
            if (var3 == 0) {
               this.field_294 = class_21.method_180().field_1133.length() + class_21.method_180().field_1139 * 3;
               this.field_294 = this.field_294 % 16 * 256;
            } else {
               this.field_294 = this.field_294 + (class_21.method_180().field_1139 > 4 ? 300 : -300);
            }

            var1.field_39 = var3 == 1 ? 90000 : 110000;
            var1.field_39 = var1.field_39 + this.field_294 * 3;
            class_57 var4;
            (var4 = new class_57()).method_490(this.field_294);
            (var2 = var4.method_508(var1, var2)).field_38 = 0;
         }

         this.field_276[var3] = new class_99(15, class_43.method_381(15), var2.field_37, var2.field_38, var2.field_39);
         ((class_99)this.field_276[var3]).method_822(this.field_294 + 2048);
      }

      this.field_294 += 2048;
      if (!field_301) {
         this.field_294 = 0;
      } else {
         ((class_99)this.field_276[2]).method_823();
      }

      ((class_99)this.field_276[1]).method_821();
      short[][] var8 = new short[][]{{255, 255, 128}, {98, 118, 255}, {234, 149, 55}, {239, 90, 95}, {154, 220, 109}};
      byte[] var9 = class_38.method_363(class_21.method_180());

      for (int var5 = 0; var5 < var9.length; var5 += 2) {
         if (var9[var5] > 12 && var9[var5] < 18) {
            float var6 = var9[var5 + 1] / 100.0F * 1.5F;
            this.field_295 = var6 * var8[var9[var5] - 13][0];
            this.field_296 = var6 * var8[var9[var5] - 13][1];
            this.field_297 = var6 * var8[var9[var5] - 13][2];
            float var7 = class_21.method_180().method_744();
            this.field_298 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_295 * var7))));
            this.field_299 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_296 * var7))));
            this.field_300 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_297 * var7))));
            return;
         }
      }
   }

   // $VF: renamed from: p () void
   private void method_242() {
      if (class_21.method_132().method_754()
         || class_21.method_132().field_1146 != 6 && (!class_21.method_132().field_1161 || class_21.method_132().field_1146 != 6)) {
         int var1 = 0;
         int var2 = 0;
         boolean var3 = false;
         this.field_275 = new class_91[class_21.method_147() ? 49 : 20];
         byte[] var4 = class_38.method_363(class_21.method_180());

         for (int var5 = 0; var5 < this.field_275.length; var5++) {
            if (class_21.method_147()) {
               var1 = 13 + var5 / 10;
            } else {
               var3 = false;

               while (!var3) {
                  if (class_84.field_1123.nextInt(100) < var4[var2 + 1]) {
                     var1 = var4[var2];
                     var3 = true;
                     var2 += 2;
                     if (var2 >= var4.length) {
                        var2 = 0;
                     }
                  } else {
                     var2 = 0;
                  }
               }
            }

            this.field_275[var5] = this.method_243(var1, null);
         }
      }
   }

   // $VF: renamed from: a (int, bi) ah
   private class_101 method_243(int var1, class_97 var2) {
      short var3 = class_90.field_1202[var1];
      int var4 = 0;
      int var5 = 0;
      int var6 = 0;
      if (var2 != null) {
         var4 = var2.field_1295;
         var5 = var2.field_1296;
         var6 = var2.field_1297 - 20000;
      }

      class_101 var7;
      (var7 = new class_101(var3, class_43.method_381(var3), class_90.method_787()[var1], var4, var5, var6)).field_1229 = this;
      var7.field_1226.field_1367 = 2;
      class_85 var8 = new class_85(1, 2);
      var7.field_1231 = var8;
      return var7;
   }

   // $VF: renamed from: c () void
   public final void method_244() {
      try {
         class_108 var2;
         (var2 = class_43.method_381(class_90.field_1205[class_21.method_178().field_863])).field_1367 = 2;
         class_19[] var3 = class_21.method_178().field_885;
         int var4 = 0;
         int var5 = 0;
         int var6 = 0;
         class_9[] var7 = null;
         class_9 var8 = null;
         if (var3 != null) {
            for (int var9 = 0; var9 < var3.length; var9++) {
               if (var3[var9] != null) {
                  switch (var3[var9].field_165) {
                     case 0:
                     case 1:
                        var5++;
                        break;
                     case 2:
                        var6++;
                  }
               }
            }
         }

         if (var6 > 0) {
            var4++;
         }

         if (var5 > 0) {
            var4++;
            var7 = new class_9[var5];
         }

         class_37 var15;
         (var15 = new class_37(1200.0F, class_21.method_178().field_864, var4)).method_331(class_21.method_178().field_871);
         var15.method_332(class_21.method_178().field_872);
         this.field_272 = new class_70(var15);
         this.field_272.field_981 = this;
         this.field_272.method_648(var2);
         this.field_272.field_970.method_864(0, this.field_294, 0);
         int[] var10 = new int[]{0, 0, 0};
         class_85 var11 = new class_85(var10.length / 3, 0);
         this.field_272.field_979 = var11;
         if (var3 != null) {
            for (int var12 = 0; var12 < var3.length; var12++) {
               if (var3[var12] != null) {
                  class_9 var13 = null;
                  if (var3[var12].method_118()) {
                     (var13 = this.method_245(var3[var12].field_166, var3[var12].field_171, var3[var12].field_172, var3[var12].field_173, var3[var12].field_174))
                        .field_100 = var3[var12].field_165;
                     switch (var3[var12].field_165) {
                        case 0:
                        case 1:
                           var13.method_42(var5 - 1, var7.length);
                           var7[var5-- - 1] = var13;
                           break;
                        case 2:
                           var8 = var13;
                     }
                  }
               }
            }
         }

         int var16 = 0;
         if (var7 != null) {
            var16++;
            this.field_272.method_658(var7, 0);
         }

         if (var8 != null) {
            this.field_272.method_657(var8, var16);
         }

         class_21.method_178().method_619();
      } catch (Exception var14) {
         var14.printStackTrace();
      }
   }

   // $VF: renamed from: a (int, int, int, int, int) n
   public final class_9 method_245(int var1, int var2, int var3, int var4, int var5) {
      class_9 var6 = null;
      class_108 var7 = null;
      Object var8 = null;
      class_116 var9 = this.field_266;
      switch (var1) {
         case 0:
         case 1:
         case 2:
         case 6:
         case 7:
         case 8:
         case 9:
         case 10:
         case 11:
         case 42:
            var6 = new class_9(var2, 10, -1, var4, var3, var5, new class_3(0, 0, 200), new class_3());
            var8 = new class_112(var6, class_43.method_381(var1 == 42 ? 6766 : class_90.field_1201[var1]), 1000);
            break;
         case 3:
         case 4:
         case 5:
            var6 = new class_9(var2, 1, -1, var4, var3, var5, new class_3(0, 0, 2200), new class_3());
            (var7 = class_108.method_890(0, 128, 64, 0, 96, 32, 300, 1, (byte)2)).method_893(class_43.method_380(2));
            ((class_110)var7).field_1390 = new int[]{-16711936};
            var7.field_1367 = 2;
            var8 = new class_115(var6, var7, this.field_272.field_970, var1 - 3);
            break;
         case 12:
         case 13:
         case 14:
            var6 = new class_9(var2, 1, -1, var4, var3, var5, new class_3(), new class_3());
            (var7 = class_43.method_381(16)).field_1367 = 2;
            var8 = new class_113(var6, var7, -16711936, true);
            var9 = this.field_268;
            break;
         case 15:
         case 16:
         case 17:
            var6 = new class_9(0, 1, -1, var4, var4, var5, new class_3(), new class_3());
            (var7 = class_108.method_890(0, 128, 64, 0, 96, 32, 500, 1, (byte)2)).method_893(class_43.method_380(2));
            ((class_110)var7).field_1390 = new int[]{-16711936};
            var7.field_1367 = 2;
            var8 = new class_114(var6, var7, this.field_272.field_970, var2, var1 - 15, var3);
            var9 = this.field_267;
         case 18:
         case 19:
         case 20:
         case 21:
         case 22:
         case 23:
         case 24:
         case 25:
         case 26:
         case 27:
         case 28:
         case 29:
         case 30:
         case 31:
         case 32:
         case 33:
         case 34:
         case 35:
         case 36:
         case 37:
         case 38:
         case 39:
         case 40:
         case 41:
      }

      var6.field_76 = this;
      if (var1 != 15 && var1 != 16 && var1 != 17) {
         var6.method_44(var9);
      }

      if (this.field_269 == null) {
         this.field_269 = new class_108[]{(class_108)var8};
      } else {
         class_108[] var10 = new class_108[this.field_269.length + 1];
         System.arraycopy(this.field_269, 0, var10, 0, this.field_269.length);
         var10[var10.length - 1] = (class_108)var8;
         this.field_269 = var10;
      }

      return var6;
   }

   // $VF: renamed from: d () void
   public final void method_246() {
      boolean var1 = false;
      this.field_274 = new class_91[1];
      this.field_274[0] = this.method_254(1, 0, 5, false, null);
      if (field_301 && this.field_272.field_970 != null) {
         ((class_96)this.field_274[0])
            .method_818(
               this.field_276[2].field_1226.method_852() - 3000,
               this.field_276[2].field_1226.method_853() + 1000,
               this.field_276[2].field_1226.method_854() + 5000
            );
      } else {
         ((class_96)this.field_274[0])
            .method_818(
               this.field_272.field_970.method_852() + -700 + class_84.field_1123.nextInt(1400),
               this.field_272.field_970.method_853() + -700 + class_84.field_1123.nextInt(1400),
               this.field_272.field_970.method_854() + 2000
            );
      }

      if (this.field_277 != null) {
         this.field_274[0].field_1230 = this.field_277.method_115();
      }

      this.field_274[0].field_1225.method_327(9999999);
   }

   // $VF: renamed from: e () void
   public final void method_247() {
      class_87 var1 = class_21.method_132();
      boolean var2 = false;
      boolean var3 = false;
      if (var1 != null) {
         if (var1.method_754()) {
            this.field_262 = 0;
            this.method_249();
            this.field_262 = 3;
            int var28;
            if (class_21.method_143() > 11 && class_84.field_1123.nextInt(100) < 25 + class_21.method_143() && (var28 = 0 + class_84.field_1123.nextInt(4)) > 0
               )
             {
               this.field_273 = new class_91[var28];
               class_18 var30 = new class_18(new int[]{0, 0, 15000});

               for (int var32 = 0; var32 < this.field_273.length; var32++) {
                  this.field_273[var32] = this.method_254(2, 0, class_90.method_791(), true, var30.method_109(0));
               }
            }
         } else {
            switch (var1.field_1146) {
               case 0:
                  this.field_277 = new class_18(
                     new int[]{
                        (40000 + class_84.field_1123.nextInt(80000)) * (class_84.field_1123.nextInt(2) == 0 ? 1 : -1),
                        0,
                        (40000 + class_84.field_1123.nextInt(80000)) * (class_84.field_1123.nextInt(2) == 0 ? 1 : -1)
                     }
                  );
                  this.field_273 = new class_91[1];
                  this.field_273[0] = this.method_254(2, 0, class_90.method_791(), true, this.field_277.method_109(0));
                  this.field_273[0].method_803();
                  int var34 = class_21.method_132().field_1154 * class_21.method_210();
                  this.field_273[0].field_1225.method_330(300 + var34);
                  this.field_289 = new class_22(1, 0, this);
                  return;
               case 1:
               case 2:
                  this.field_277 = this.method_255(2 + class_84.field_1123.nextInt(2));
                  this.field_273 = new class_91[3 + (int)(3.0F * (class_21.method_132().method_764() / 10.0F))];

                  for (int var27 = 0; var27 < this.field_273.length; var27++) {
                     this.field_273[var27] = this.method_254(
                        2,
                        0,
                        class_90.method_791(),
                        true,
                        var27 == this.field_273.length - 1
                           ? this.field_277.method_109(this.field_277.method_113() - 1)
                           : this.field_277.method_109(class_84.field_1123.nextInt(this.field_277.method_113()))
                     );
                     this.field_273[var27].method_803();
                  }

                  ((class_96)this.field_273[this.field_273.length - 1]).method_814(true);
                  this.field_289 = new class_22(11, this.field_273.length - 1, this);
                  this.field_290 = new class_22(12, this.field_273.length - 1, this);
                  return;
               case 3:
                  this.field_277 = this.method_255(2 + class_84.field_1123.nextInt(2));
                  int var26 = 3 + (int)(3.0F * (class_21.method_132().method_764() / 10.0F));
                  this.field_273 = new class_91[var26];

                  for (int var29 = 0; var29 < this.field_273.length; var29++) {
                     this.field_273[var29] = this.method_254(
                        2, 0, class_90.method_791(), true, this.field_277.method_109(class_84.field_1123.nextInt(this.field_277.method_113()))
                     );
                     this.field_273[var29].method_803();
                  }

                  this.field_289 = new class_22(0, 0, this);
                  return;
               case 4:
                  this.field_279 = new class_18(new int[]{10000, 0, 100000, 10000, 0, 150000, 10000, 0, 200000});
                  int var10 = 2 + (int)(4.0F * (class_21.method_132().method_764() / 10.0F));
                  this.field_273 = new class_91[var10];
                  int var35 = var1.field_1149 == 0 ? 1 : 0;
                  int var12 = var1.field_1149;

                  for (int var13 = 0; var13 < this.field_273.length; var13++) {
                     this.field_273[var13] = this.method_254(
                        var35, 0, class_90.method_791(), true, this.field_279.method_109(class_84.field_1123.nextInt(this.field_279.method_113()))
                     );
                     this.field_273[var13].method_803();
                  }

                  this.field_274 = new class_91[5];

                  for (int var36 = 0; var36 < this.field_274.length; var36++) {
                     this.field_274[var36] = this.method_254(var12, 3, 11, false, null);
                     this.field_274[var36].field_1225.method_330(100 + class_21.method_210() * 2 + class_21.method_143() * 2);
                     ((class_95)this.field_274[var36]).field_1255 = true;
                  }

                  boolean var14 = false;
                  boolean var15 = false;
                  ((class_95)this.field_274[0]).method_812(5500, -300, 20000);
                  ((class_95)this.field_274[1]).method_812(14500, 3000, 17000);
                  ((class_95)this.field_274[2]).method_812(4000, -2000, 12000);
                  ((class_95)this.field_274[3]).method_812(17000, -6000, 10000);
                  ((class_95)this.field_274[4]).method_812(11000, 7000, 8000);
                  this.field_289 = new class_22(0, 0, this);
                  this.field_290 = new class_22(5, 0, this);
                  return;
               case 5:
                  this.field_277 = new class_18(
                     new int[]{
                        -2500 + class_84.field_1123.nextInt(5000),
                        -2500 + class_84.field_1123.nextInt(5000),
                        80000 + class_84.field_1123.nextInt(30000),
                        -2500 + class_84.field_1123.nextInt(5000),
                        -2500 + class_84.field_1123.nextInt(5000),
                        120000 + class_84.field_1123.nextInt(30000)
                     }
                  );
                  int var16 = 2 + class_84.field_1123.nextInt(2);
                  int var17 = 2 + (int)(2.0F * (class_21.method_132().method_764() / 10.0F));
                  int var11 = var1.field_1149 == 0 ? 1 : 0;
                  this.field_273 = new class_91[var16 + var17];

                  for (int var18 = 0; var18 < var16; var18++) {
                     this.field_273[var18] = this.method_254(var11, 3, 11, true, this.field_277.method_109(1));
                     this.field_273[var18].method_803();
                     ((class_95)this.field_273[var18]).field_1255 = false;
                     ((class_95)this.field_273[var18])
                        .method_812(
                           this.field_277.method_109(1).field_1295 + -10000 + class_84.field_1123.nextInt(20000),
                           this.field_277.method_109(1).field_1296 + -10000 + class_84.field_1123.nextInt(20000),
                           this.field_277.method_109(1).field_1297 + -10000 + class_84.field_1123.nextInt(20000)
                        );
                  }

                  for (int var37 = var16; var37 < this.field_273.length; var37++) {
                     this.field_273[var37] = this.method_254(
                        var11, 0, class_90.method_791(), true, this.field_277.method_109(class_84.field_1123.nextInt(this.field_277.method_113()))
                     );
                     this.field_273[var37].method_803();
                  }

                  this.field_289 = new class_22(7, var16, this);
               default:
                  return;
               case 6:
                  this.field_278 = new class_18(new int[]{20000, 0, -40000, 20000, 0, 40000, 20000, 0, 90000});
                  this.field_275 = new class_91[var1.field_1167];

                  for (int var24 = 0; var24 < this.field_275.length; var24++) {
                     this.field_275[var24] = this.method_243(var1.field_1166, this.field_278.method_109(0));
                     ((class_101)this.field_275[var24]).method_829(true);
                     this.field_275[var24].field_1225.method_327(this.field_275[var24].field_1225.field_363 * 2);
                  }

                  this.field_273 = new class_91[2 + (int)(4.0F * (class_21.method_132().method_764() / 10.0F))];

                  for (int var25 = 0; var25 < this.field_273.length; var25++) {
                     this.field_273[var25] = this.method_254(
                        0, 0, class_90.method_791(), true, this.field_278.method_109(1 + class_84.field_1123.nextInt(this.field_278.method_113() - 1))
                     );
                     this.field_273[var25].method_803();
                  }

                  this.field_289 = new class_22(0, 0, this);
                  this.field_290 = new class_22(8, var1.field_1167 - var1.field_1168, this);
                  return;
               case 7:
                  this.field_273 = new class_91[0 + (int)(3.0F * (class_21.method_132().method_764() / 10.0F))];
                  if (this.field_273.length > 0) {
                     for (int var22 = 0; var22 < this.field_273.length; var22++) {
                        this.field_273[var22] = this.method_254(1, 0, class_90.method_791(), true, null);
                     }
                  } else {
                     this.field_273 = null;
                  }

                  for (int var23 = 0; var23 < var1.field_1167 + 3 && var23 < this.field_275.length; var23++) {
                     this.field_275[var23] = this.method_243(var1.field_1166, null);
                  }

                  this.field_289 = new class_22(13, var1.field_1166, var1.field_1167, this);
                  return;
               case 8:
                  return;
               case 9:
                  class_18 var31 = new class_18(new int[]{-20000 + class_84.field_1123.nextInt(40000), 0, 20000 + class_84.field_1123.nextInt(40000)});
                  int var7 = (int)(2.0F * (class_21.method_132().method_764() / 10.0F));
                  int var8 = 15 + (int)(15.0F * (class_21.method_132().method_764() / 10.0F));
                  this.field_273 = new class_91[var8 + var7];

                  for (int var9 = 0; var9 < this.field_273.length - var7; var9++) {
                     this.field_273[var9] = this.method_253(var31.method_109(0), 9996);
                  }

                  for (int var33 = this.field_273.length - var7; var33 < this.field_273.length; var33++) {
                     this.field_273[var33] = this.method_254(2, 0, class_90.method_791(), true, null);
                  }

                  this.field_289 = new class_22(7, this.field_273.length - var7, this);
                  this.field_291 = 151000;
                  return;
               case 10:
                  class_18 var5 = new class_18(new int[]{-20000 + class_84.field_1123.nextInt(40000), 0, 20000 + class_84.field_1123.nextInt(40000)});
                  this.field_273 = new class_91[class_84.field_1123.nextInt(11) + 15 + 1];

                  for (int var6 = 0; var6 < this.field_273.length - 1; var6++) {
                     this.field_273[var6] = this.method_253(var5.method_110(), 13);
                  }

                  this.field_273[this.field_273.length - 1] = this.method_254(2, 0, 1, true, var5.method_109(0));
                  this.field_289 = new class_22(7, this.field_273.length - 1, this);
                  return;
               case 11:
                  this.field_273 = new class_91[2 + (int)(4.0F * (class_21.method_132().method_764() / 10.0F))];

                  for (int var20 = 0; var20 < this.field_273.length; var20++) {
                     this.field_273[var20] = this.method_254(3, 0, 19, true, null);
                  }

                  this.field_274 = new class_91[class_21.method_132().field_1167];

                  for (int var21 = 0; var21 < this.field_274.length; var21++) {
                     this.field_274[var21] = this.method_254(3, 7, 9994, false, null);
                  }

                  this.field_290 = new class_22(14, class_21.method_132().field_1168, this);
                  this.field_289 = new class_22(0, 0, this);
                  return;
               case 12:
                  this.field_273 = new class_91[class_21.method_132().field_1167 + 2 + (int)(4.0F * (class_21.method_132().method_764() / 10.0F))];

                  for (int var4 = 0; var4 < this.field_273.length; var4++) {
                     if (var4 < class_21.method_132().field_1167) {
                        this.field_273[var4] = this.method_254(3, 7, 9994, true, null);
                     } else {
                        this.field_273[var4] = this.method_254(0, 0, class_90.method_791(), true, null);
                     }
                  }

                  this.field_274 = new class_91[0 + (int)(3.0F * (class_21.method_132().method_764() / 10.0F))];
                  if (this.field_274.length > 0) {
                     for (int var19 = 0; var19 < this.field_274.length; var19++) {
                        this.field_274[var19] = this.method_254(3, 0, 19, false, null);
                     }
                  }

                  this.field_289 = new class_22(7, class_21.method_132().field_1167, this);
            }
         }
      }
   }

   // $VF: renamed from: f () void
   public final void method_248() {
      class_87 var4 = class_21.method_132();
      switch (class_21.method_143()) {
         case 5:
            this.field_273 = new class_91[1];
            this.field_273[0] = this.method_254(2, 0, 1, true, null);
            this.field_289 = new class_22(0, 0, this);
         case 6:
         case 8:
         case 9:
         case 11:
         case 12:
         case 13:
         case 14:
         case 15:
         case 16:
         case 17:
         case 18:
         case 20:
         case 22:
         case 24:
         case 26:
         case 28:
         case 30:
         case 32:
         case 33:
         case 34:
         case 36:
         case 37:
         case 38:
         case 39:
         case 40:
         case 41:
         case 44:
         case 46:
         default:
            break;
         case 7:
            for (int var19 = 0; var19 < var4.field_1167; var19++) {
               this.field_275[var19] = this.method_243(var4.field_1166, null);
            }

            this.field_289 = new class_22(13, var4.field_1166, var4.field_1167, this);
            break;
         case 10:
            this.field_273 = new class_91[4];

            for (int var17 = 0; var17 < this.field_273.length; var17++) {
               this.field_273[var17] = this.method_254(3, 0, 19, true, null);
            }

            this.field_274 = new class_91[class_21.method_132().field_1167];

            for (int var18 = 0; var18 < this.field_274.length; var18++) {
               this.field_274[var18] = this.method_254(3, 7, 9994, false, null);
            }

            this.field_290 = new class_22(14, class_21.method_132().field_1168, this);
            this.field_289 = new class_22(0, 0, this);
            break;
         case 19:
            this.field_278 = new class_18(new int[]{-20000, 0, -40000, -20000, 0, 30000, -20000, 0, 100000, -20000, 0, 130000});
            this.field_275 = new class_91[var4.field_1167];

            for (int var14 = 0; var14 < this.field_275.length; var14++) {
               this.field_275[var14] = this.method_243(var4.field_1166, this.field_278.method_109(1));
               ((class_101)this.field_275[var14]).method_829(true);
               this.field_275[var14].field_1225.method_327(this.field_275[var14].field_1225.field_363 * 2);
            }

            this.field_273 = new class_91[3];

            for (int var15 = 0; var15 < this.field_273.length; var15++) {
               this.field_273[var15] = this.method_254(0, 0, class_90.method_791(), true, this.field_278.method_109(var15 == 0 ? 2 : 3));
               this.field_273[var15].method_803();
            }

            this.field_274 = new class_91[3];

            for (int var16 = 0; var16 < this.field_274.length; var16++) {
               this.field_274[var16] = this.method_254(0, 0, 19, false, this.field_278.method_109(0));
            }

            this.field_289 = new class_22(0, 0, this);
            this.field_289 = new class_22(0, 0, this);
            this.field_290 = new class_22(8, var4.field_1167 - var4.field_1168, this);
            break;
         case 21:
            this.field_277 = new class_18(new int[]{0, 0, 200000});
            this.method_246();
            this.field_274[0].field_1226.method_846(this.field_272.method_664());
            class_3 var13 = new class_3();
            class_3 var21 = new class_3();
            var13.method_9(this.field_276[0].method_799(var13));
            var21 = this.field_276[2].method_799(var21);
            var13.method_17(var21);
            var13.method_20(12288);
            var21.method_15(var13);
            this.field_274[0].field_1226.method_846(var21);
            this.field_274[0].field_1226.method_843(0, 0, -10000);
            this.field_274[0].method_803();
            this.field_273 = new class_91[3];

            for (int var23 = 0; var23 < this.field_273.length; var23++) {
               this.field_273[var23] = this.method_254(2, 0, class_90.method_791(), true, this.field_277.method_109(0));
               this.field_273[var23].method_803();
            }

            this.field_289 = new class_22(0, 0, this);
            break;
         case 23:
            class_18 var7 = new class_18(new int[]{80000, 0, 120000});
            this.field_273 = new class_91[20];
            boolean var8 = false;

            for (int var24 = 0; var24 < this.field_273.length - 2; var24++) {
               this.field_273[var24] = this.method_253(var7.method_110(), 13);
            }

            for (int var25 = this.field_273.length - 2 - 1; var25 < this.field_273.length; var25++) {
               this.field_273[var25] = this.method_254(2, 0, class_90.method_791(), true, var7.method_109(0));
            }

            this.field_289 = new class_22(7, this.field_273.length - 2, this);
            break;
         case 25:
            class_18 var9 = new class_18(new int[]{-200000, 0, -200000});
            this.field_274 = new class_91[3];

            for (int var26 = 0; var26 < this.field_274.length; var26++) {
               this.field_274[var26] = this.method_254(1, 0, var26 == 0 ? 5 : 2, false, null);
               this.field_274[var26].field_1226.method_846(this.field_272.method_664());
               this.field_274[var26].field_1226.method_870(this.field_272.field_970.field_1341);
               this.field_274[var26]
                  .field_1226
                  .method_843(
                     var26 == 0 ? 800 : (var26 == 1 ? -1000 : -30),
                     var26 == 0 ? 340 : (var26 == 1 ? -130 : -300),
                     var26 == 0 ? 700 : (var26 == 1 ? -500 : -100)
                  );
               this.field_274[var26].field_1225.method_330(32000);
            }

            this.field_274[0].field_1230 = var9;
            this.field_273 = new class_91[6];

            for (int var27 = 0; var27 < this.field_273.length; var27++) {
               this.field_273[var27] = this.method_254(0, 0, class_90.method_791(), true, null);
               this.field_273[var27].field_1226.method_870(this.field_272.field_970.field_1341);
               this.field_273[var27].field_1226.method_845(-40000 + var27 * 2000, -6000 + var27 * 2000, 10000 + var27 * 2000);
            }

            this.field_289 = new class_22(0, 0, this);
            break;
         case 27:
            this.field_277 = new class_18(new int[]{120000, 0, 130000});
            this.field_273 = new class_91[1];
            this.field_273[0] = this.method_254(1, 0, 5, true, this.field_277.method_109(0));
            this.field_273[0].method_803();
            this.field_273[0].field_1225.method_330(this.field_273[0].field_1225.field_364 * 5);
            this.field_273[0].method_796(5);
            ((class_96)this.field_273[0]).method_814(true);
            this.field_289 = new class_22(11, 0, this);
            this.field_290 = new class_22(12, 0, this);
            break;
         case 29:
            this.field_279 = new class_18(new int[]{-30000, 0, 30000, -30000, 0, 130000, -30000, 0, 200000});
            boolean var10 = false;
            int var11 = class_90.method_791();
            this.field_273 = new class_91[5];

            for (int var41 = 0; var41 < this.field_273.length; var41++) {
               this.field_273[var41] = this.method_254(0, 0, var11, true, this.field_279.method_109(var41 < 2 ? 0 : (var41 < 3 ? 1 : 2)));
               this.field_273[var41].method_803();
            }

            this.field_274 = new class_91[5];

            for (int var42 = 0; var42 < this.field_274.length; var42++) {
               this.field_274[var42] = this.method_254(1, 3, 11, false, null);
               this.field_274[var42].field_1225.method_330(100 + class_21.method_210() * 5 + 50);
               ((class_95)this.field_274[var42]).field_1255 = true;
               this.field_274[var42].method_804();
            }

            boolean var1 = false;
            boolean var2 = false;
            boolean var3 = false;
            ((class_95)this.field_274[0]).method_812(-30000 - 7500, -1300, 20000);
            ((class_95)this.field_274[1]).method_812(-22500, 4000, 17000);
            ((class_95)this.field_274[2]).method_812(-31000, -3000, 13000);
            ((class_95)this.field_274[3]).method_812(-20000, -7000, 10000);
            ((class_95)this.field_274[4]).method_812(-29000, 8000, 8000);
            this.field_289 = new class_22(0, 0, this);
            this.field_290 = new class_22(5, 0, this);
            break;
         case 31:
            this.field_277 = new class_18(new int[]{-160000, 0, 30000});
            this.field_273 = new class_91[4];

            for (int var39 = 0; var39 < this.field_273.length; var39++) {
               this.field_273[var39] = this.method_254(0, 0, class_90.method_791(), true, this.field_277.method_109(0));
               this.field_273[var39].method_803();
               ((class_96)this.field_273[var39]).method_814(true);
            }

            this.field_274 = new class_91[2];

            for (int var40 = 0; var40 < this.field_274.length; var40++) {
               this.field_274[var40] = this.method_254(1, 0, class_90.method_791(), false, null);
               this.field_274[var40].field_1226.method_846(this.field_272.method_664());
               this.field_274[var40].field_1226.method_870(this.field_272.field_970.field_1341);
               this.field_274[var40].field_1226.method_843(var40 == 0 ? 400 : -300, var40 == 0 ? 40 : -30, var40 == 0 ? 400 : -300);
               this.field_274[var40].field_1230 = this.field_277.method_115();
               this.field_274[var40].field_1225.method_330(32000);
            }

            this.field_289 = new class_22(16, 0, this);
            this.field_290 = new class_22(17, 0, this);
            break;
         case 35:
            this.field_277 = new class_18(new int[]{20000, 0, 120000});
            this.field_273 = new class_91[3];

            for (int var38 = 0; var38 < this.field_273.length; var38++) {
               this.field_273[var38] = this.method_254(2, 0, var38 == 0 ? 10 : 0, true, this.field_277.method_109(0));
               this.field_273[var38].method_803();
            }

            this.field_273[0].field_1225.method_330(this.field_273[0].field_1225.field_364 * 5);
            this.field_273[0].method_796(5);
            this.field_289 = new class_22(1, 0, this);
            break;
         case 42:
            this.field_279 = new class_18(new int[]{170000, 0, 0, 240000, 0, 0});
            this.field_277 = this.field_279.method_115();
            this.field_273 = new class_91[6];

            for (int var37 = 0; var37 < this.field_273.length; var37++) {
               this.field_273[var37] = this.method_254(2, 0, class_90.method_791(), true, this.field_279.method_109(var37 < 3 ? 0 : 1));
               this.field_273[var37].method_803();
            }

            this.field_289 = new class_22(0, 0, this);
            break;
         case 43:
            this.field_278 = new class_18(new int[]{150000, 0, 0, 0, 0, 0});
            this.field_273 = new class_91[8];

            for (int var34 = 0; var34 < this.field_273.length; var34++) {
               this.field_273[var34] = this.method_254(0, 0, class_90.method_791(), true, null);
            }

            this.field_274 = new class_91[7];

            for (int var35 = 0; var35 < 2; var35++) {
               this.field_274[var35] = this.method_254(1, 0, class_90.method_791(), false, null);
            }

            for (int var36 = 2; var36 < this.field_274.length; var36++) {
               this.field_274[var36] = this.method_254(3, 0, 19, false, this.field_278.method_109(0));
               this.field_274[var36].method_803();
               this.field_274[var36].field_1230 = this.field_278.method_115();
            }

            this.field_289 = new class_22(0, 0, this);
            break;
         case 45:
            this.field_278 = new class_18(new int[]{0, -60000, 0, 0, 0, 0});
            class_3 var5 = new class_3();
            class_3 var6 = new class_3();
            var5.method_9(this.field_276[0].method_799(var5));
            var6 = this.field_276[2].method_799(var6);
            var5.method_17(var6);
            var5.method_20(28672);
            var6.method_15(var5);
            this.field_274 = new class_91[7];

            for (int var30 = 0; var30 < 4; var30++) {
               this.field_274[var30] = this.method_254(1, 0, class_90.method_791(), false, null);
               if (var30 < 2) {
                  this.field_274[var30].field_1225.method_327(32000);
               }

               this.field_274[var30].field_1226.method_846(var6);
               this.field_274[var30]
                  .field_1226
                  .method_843(-3000 + class_84.field_1123.nextInt(6000), -3000 + class_84.field_1123.nextInt(6000), -3000 + class_84.field_1123.nextInt(6000));
               this.field_274[var30].field_1226.method_867(this.field_272.field_970.method_865());
            }

            for (int var31 = 4; var31 < this.field_274.length; var31++) {
               this.field_274[var31] = this.method_254(3, 0, 19, false, this.field_278.method_109(0));
               this.field_274[var31].field_1230 = this.field_278.method_115();
            }

            this.field_273 = new class_91[12];

            for (int var32 = 0; var32 < 5; var32++) {
               this.field_273[var32] = this.method_254(0, 3, 11, true, null);
               ((class_95)this.field_273[var32]).field_1255 = false;
               ((class_95)this.field_273[var32])
                  .method_812(
                     10000 + class_84.field_1123.nextInt(20000), -10000 + class_84.field_1123.nextInt(20000), 10000 + class_84.field_1123.nextInt(20000)
                  );
               this.field_273[var32].field_1225.method_327(this.field_273[var32].field_1225.field_363 * 2);
            }

            for (int var33 = 5; var33 < this.field_273.length; var33++) {
               this.field_273[var33] = this.method_254(0, 0, class_90.method_791(), true, null);
            }

            this.field_289 = new class_22(0, 0, this);
            break;
         case 47:
            this.field_274 = new class_91[5];

            for (int var12 = 0; var12 < this.field_274.length; var12++) {
               this.field_274[var12] = this.method_254(1, 0, class_90.method_791(), false, null);
               if (var12 < 2) {
                  this.field_274[var12].field_1225.method_327(32000);
               }
            }

            this.field_273 = new class_91[9];

            for (int var28 = 0; var28 < 5; var28++) {
               this.field_273[var28] = this.method_254(0, 3, 11, true, null);
               ((class_95)this.field_273[var28]).field_1255 = false;
               ((class_95)this.field_273[var28])
                  .method_812(
                     10000 + class_84.field_1123.nextInt(20000), -10000 + class_84.field_1123.nextInt(20000), 10000 + class_84.field_1123.nextInt(20000)
                  );
            }

            for (int var29 = 5; var29 < this.field_273.length - 1; var29++) {
               this.field_273[var29] = this.method_254(0, 0, class_90.method_791(), true, null);
            }

            this.field_273[this.field_273.length - 1] = this.method_254(0, 0, 7, true, null);
            this.field_273[this.field_273.length - 1].field_1225.method_327(32000);
            this.field_273[this.field_273.length - 1].method_796(6);
            this.field_273[this.field_273.length - 1].field_1239 = false;
            this.field_289 = new class_22(0, 0, this);
      }

      this.field_280 = this.method_256(class_21.method_143());
   }

   // $VF: renamed from: g () void
   public final void method_249() {
      switch (this.field_262) {
         case 0:
            class_98 var5 = (class_98)this.field_276[1];
            class_98 var3 = (class_98)this.field_276[2];
            this.field_278 = new class_18(
               new int[]{var5.field_1300, var5.field_1301, var5.field_1302 + 3000, var3.field_1300, var3.field_1301, var3.field_1302 + 3000, 0, 0, 6000}
            );
            this.field_278.field_163 = true;
            if (class_21.method_180().field_1143 != null) {
               this.field_274 = new class_91[class_21.method_180().field_1143.length];

               for (int var4 = 0; var4 < this.field_274.length; var4++) {
                  this.field_274[var4] = this.method_254(
                     class_21.method_180().method_752() ? 0 : 1, 0, class_90.field_1205[class_21.method_180().field_1143[var4].field_863], false, null
                  );
                  this.field_274[var4].field_1230 = this.field_278.method_115();
                  if (class_84.field_1123.nextInt(2) == 0) {
                     this.field_274[var4].field_1230.method_112(0);
                  }
               }
            }
            break;
         case 1:
            class_68[] var1;
            if ((var1 = class_21.method_180().field_1143) != null) {
               this.field_274 = new class_91[var1.length];

               for (int var2 = 0; var2 < var1.length; var2++) {
                  this.field_274[var2] = this.method_252(class_90.field_1205[var1[var2].field_863]);
                  this.field_274[var2].field_1226.method_845(field_264[var2][0], field_264[var2][1], field_264[var2][2]);
                  this.field_274[var2].field_1226.method_845(0, 0, var2 * 50000);
               }

               return;
            }
      }
   }

   // $VF: renamed from: h () void
   public final void method_250() {
      this.field_270 = null;
      this.field_271 = null;
      int var1 = (int)(class_21.method_210() / 1.5F) + (int)(class_21.method_143() / 5.0F);
      class_9 var2 = null;
      if (this.field_273 != null) {
         class_9 var3;
         (var3 = new class_9(3 + var1, 4, -1, 3000, 500, 16.0F, null, null)).field_76 = this;
         var3.method_44(this.field_266);

         for (int var4 = 0; var4 < this.field_273.length; var4++) {
            if (this.field_273[var4].field_1227 == 19) {
               this.field_270 = new class_108[2];
            } else {
               this.field_270 = new class_108[1];
            }
         }

         class_112 var9 = new class_112(var3, class_43.method_381(class_90.field_1201[8]), 1000);
         this.field_270[0] = var9;
         if (this.field_270.length == 2) {
            (var2 = new class_9(3 + var1, 6, -1, 3000, 600, 15.0F, null, null)).field_76 = this;
            var2.method_44(this.field_266);
            class_112 var5 = new class_112(var2, class_43.method_381(6767), 1000);
            this.field_270[1] = var5;
         }

         for (int var12 = 0; var12 < this.field_273.length; var12++) {
            if (!this.field_273[var12].field_1238) {
               if (this.field_273[var12].field_1227 == 19) {
                  this.field_273[var12].method_798(var2, 0);
               } else {
                  this.field_273[var12].method_798(var3, 0);
               }
            }
         }
      }

      if (this.field_274 != null) {
         class_9 var6;
         (var6 = new class_9(3 + (int)(var1 * 0.8F), 10, -1, 3000, 500, 16.0F, null, null)).field_76 = this;
         var6.method_44(this.field_266);
         var6.field_101 = true;

         for (int var10 = 0; var10 < this.field_274.length; var10++) {
            if (this.field_274[var10].field_1227 == 19) {
               this.field_271 = new class_108[2];
            } else {
               this.field_271 = new class_108[1];
            }
         }

         class_112 var11 = new class_112(var6, class_43.method_381(class_90.field_1201[2]), 1000);
         this.field_271[0] = var11;
         if (this.field_271.length == 2) {
            (var2 = new class_9(5 + var1, 10, -1, 3000, 600, 15.0F, null, null)).field_76 = this;
            var2.method_44(this.field_266);
            class_112 var13 = new class_112(var2, class_43.method_381(6767), 1000);
            this.field_271[1] = var13;
         }

         for (int var14 = 0; var14 < this.field_274.length; var14++) {
            if ((!(this.field_274[var14] instanceof class_99) || this.field_274[var14].field_1238)
               && (var14 != 0 || !class_21.method_132().field_1161 || class_21.method_143() != 26)) {
               if (this.field_274[var14].field_1227 == 19) {
                  this.field_274[var14].method_798(var2, 0);
               } else {
                  this.field_274[var14].method_798(var6, 0);
               }
            }
         }
      }

      if (this.field_270 != null) {
         for (int var7 = 0; var7 < this.field_270.length; var7++) {
            this.field_270[var7].field_1367 = 2;
         }
      }

      if (this.field_271 != null) {
         for (int var8 = 0; var8 < this.field_271.length; var8++) {
            this.field_271[var8].field_1367 = 2;
         }
      }
   }

   // $VF: renamed from: i () void
   public final void method_251() {
      if (class_21.method_132().field_1146 != 6
         && class_21.method_132().field_1146 != 11
         && class_21.method_132().field_1146 != 4
         && this.field_273 != null
         && this.field_272 != null) {
         for (int var1 = 0; var1 < this.field_273.length; var1++) {
            this.field_273[var1].field_1225.method_324(this.field_272.field_969);
         }
      }

      if (this.field_273 != null && this.field_272 != null) {
         class_37[] var3 = new class_37[this.field_273.length];

         for (int var2 = 0; var2 < var3.length; var2++) {
            var3[var2] = this.field_273[var2].field_1225;
         }

         this.field_272.field_969.method_323(var3);
      }

      if (this.field_275 != null && this.field_272 != null) {
         class_37[] var4 = new class_37[this.field_275.length];

         for (int var10 = 0; var10 < var4.length; var10++) {
            var4[var10] = this.field_275[var10].field_1225;
         }

         this.field_272.field_969.method_325(var4);
      }

      if (this.field_275 != null && this.field_272 != null) {
         for (int var5 = 0; var5 < this.field_275.length; var5++) {
            this.field_275[var5].field_1225.method_324(this.field_272.field_969);
         }
      }

      if (this.field_274 != null && this.field_272 != null) {
         class_37[] var6 = new class_37[this.field_274.length];

         for (int var11 = 0; var11 < var6.length; var11++) {
            var6[var11] = this.field_274[var11].field_1225;
         }

         this.field_272.field_969.field_361 = var6;
      }

      if (!class_21.method_132().method_754() && class_21.method_132().field_1146 == 6 && this.field_273 != null) {
         class_37[] var7;
         (var7 = new class_37[this.field_275.length + 1])[var7.length - 1] = this.field_272.field_969;

         for (int var12 = 0; var12 < var7.length - 1; var12++) {
            var7[var12] = this.field_275[var12].field_1225;
         }

         for (int var13 = 0; var13 < this.field_273.length; var13++) {
            this.field_273[var13].field_1225.method_325(var7);
         }
      }

      if (this.field_273 != null && this.field_274 != null) {
         class_37[] var8 = new class_37[this.field_274.length + 1];
         if (class_21.method_132().method_754()
            || class_21.method_132().field_1146 != 6 && class_21.method_132().field_1146 != 11 && class_21.method_132().field_1146 != 4) {
            var8[0] = this.field_272.field_969;

            for (int var15 = 1; var15 < var8.length; var15++) {
               var8[var15] = this.field_274[var15 - 1].field_1225;
            }
         } else {
            var8 = new class_37[this.field_274.length];

            for (int var14 = 0; var14 < var8.length; var14++) {
               var8[var14] = this.field_274[var14].field_1225;
            }
         }

         for (int var16 = 0; var16 < this.field_273.length; var16++) {
            this.field_273[var16].field_1225.method_325(var8);
         }
      }

      if (this.field_273 != null && this.field_274 != null) {
         class_37[] var9 = new class_37[this.field_273.length];

         for (int var17 = 0; var17 < var9.length; var17++) {
            var9[var17] = this.field_273[var17].field_1225;
         }

         for (int var18 = 0; var18 < this.field_274.length; var18++) {
            this.field_274[var18].field_1225.method_323(var9);
         }
      }
   }

   // $VF: renamed from: a (int) aw
   public final class_91 method_252(int var1) {
      Object var2 = null;
      ((class_108)(var2 = class_43.method_381(var1))).field_1367 = 2;
      return new class_98(var1, (class_108)var2, 0, 0, 0);
   }

   // $VF: renamed from: a (bi, int) aw
   public final class_91 method_253(class_97 var1, int var2) {
      int var3 = var1 != null ? var1.field_1295 : 0;
      int var4 = var1 != null ? var1.field_1296 : 0;
      int var5 = var1 != null ? var1.field_1297 : 0;
      int var6 = var3 + class_84.field_1123.nextInt(20000) - 10000;
      int var7 = var4 + class_84.field_1123.nextInt(20000) - 10000;
      int var8 = var5 + class_84.field_1123.nextInt(20000) - 10000;
      class_108 var9;
      (var9 = class_43.method_381(var2)).field_1367 = 2;
      Object var10 = null;
      Object var11 = null;
      if (var2 == 13) {
         var10 = new class_37(1000.0F, 4, 1);
         ((class_91)(var11 = new class_93(13, true, (class_37)var10, var9, var6, var7, var8))).field_1231 = new class_85(1, 1);
         ((class_93)var11).field_1251 = this.field_268;
      } else if (var2 == 9996) {
         var10 = new class_37(1000.0F, 1, 1);
         var11 = new class_94(9996, true, (class_37)var10, var9, var6, var7, var8);
         Object var12 = null;
         ((class_91)var11).field_1231 = new class_85(1, 0);
         ((class_91)var11).field_1226.method_860(var6, var7, var8);
      }

      ((class_91)var11).field_1229 = this;
      return (class_91)var11;
   }

   // $VF: renamed from: a (int, int, int, boolean, bi) aw
   public final class_91 method_254(int var1, int var2, int var3, boolean var4, class_97 var5) {
      int var6 = var5 != null ? var5.field_1295 : 0;
      int var7 = var5 != null ? var5.field_1296 : 0;
      int var8 = var5 != null ? var5.field_1297 : 0;
      int var9 = class_84.field_1123.nextInt(40000) - 20000;
      int var10 = class_84.field_1123.nextInt(40000) - 20000;
      int var11 = class_84.field_1123.nextInt(40000) - 20000;
      boolean var12 = false;
      if (class_21.method_132() != null && class_21.method_132().field_1146 == 6) {
         var12 = true;
      }

      if (var12) {
         var9 /= 10;
         var10 /= 10;
         var11 /= 10;
      }

      int var13 = var6 + var9;
      int var14 = var7 + var10;
      int var15 = var8 + var11;
      Object var16 = null;
      Object var19 = null;
      class_85 var20 = null;
      Object var21 = null;
      Object var22 = null;
      boolean var23 = false;
      ((class_108)(var16 = class_43.method_381(var3))).field_1367 = 2;
      class_37 var18;
      if (var3 < class_90.field_1204.length) {
         int var17 = class_90.field_1204[var3] + class_21.method_210() * 15 + class_21.method_143() * 4;
         var18 = new class_37(class_90.field_1203[var3], var17, 1);
      } else {
         boolean var25 = false;
         var18 = new class_37(2000.0F, 20, 1);
      }

      switch (var2) {
         case 0:
            var19 = new class_96(var3, var1, var4, var18, (class_108)var16, var13, var14, var15);
            var20 = new class_85(1, var3 == 19 ? 2 : 0);
         case 1:
         case 2:
         case 4:
         default:
            break;
         case 3:
            var19 = new class_95(var3, var1, var4, var18, (class_108)var16, var13, var14, var15);
            ((Object[])(var22 = new class_29[1]))[0] = new class_31(var13, var14, var15, 0, 300, 0, 4000, 4000, 15000);
            ((class_95)var19).field_1253 = (class_29[])var22;
            var21 = new int[]{360, 186, -3370, -844, -507, 880, -449, 437, -983, 880, -275, -983, 360, 186, 4243, 0, 0, 0};
            (var20 = new class_85(((Object[])var21).length / 3, 0)).method_739((int[])var21);
            break;
         case 5:
            var19 = new class_96(var3, var1, var4, var18, (class_108)var16, var13, var14, var15);
            var20 = new class_85(1, 0);
            break;
         case 6:
            var19 = new class_96(var3, var1, var4, var18, (class_108)var16, var13 / 3, var7, var15 / 3);
            break;
         case 7:
            var19 = new class_92(var3, var4, var18, (class_108)var16, 0, 0, 0);
            var20 = new class_85(1, 0);
            var18.method_330(class_21.method_132().field_1146 == 12 ? 32 : 65);
      }

      ((class_91)var19).field_1229 = this;
      ((class_91)var19).field_1231 = var20;
      return (class_91)var19;
   }

   // $VF: renamed from: a (int) dr
   public final class_18 method_255(int var1) {
      int[] var2 = new int[var1 * 3];

      for (int var3 = 0; var3 < var2.length; var3 += 3) {
         var2[var3] = 60000 + class_84.field_1123.nextInt(40000);
         var2[var3 + 1] = 0;
         if (var3 != 0) {
            var2[var3 + 2] = var2[var3 - 1 + 2] + 60000 + class_84.field_1123.nextInt(40000);
         } else {
            var2[var3 + 2] = 60000 + class_84.field_1123.nextInt(40000);
         }
      }

      return new class_18(var2);
   }

   // $VF: renamed from: a (int) dk[]
   public final class_20[] method_256(int var1) {
      this.field_280 = null;
      switch (var1) {
         case 5:
            this.field_280 = new class_20[5];
            this.field_280[0] = new class_20(644, 1, 5, 5000);
            this.field_280[1] = new class_20(645, 0, 6, 0);
            this.field_280[2] = new class_20(646, 1, 6, 1);
            this.field_280[3] = new class_20(647, 10, 12, 0);
            this.field_280[4] = new class_20(648, 1, 18, 0);
         case 6:
         case 7:
         case 8:
         case 9:
         case 10:
         case 11:
         case 12:
         case 13:
         case 14:
         case 15:
         case 16:
         case 17:
         case 18:
         case 20:
         case 22:
         case 24:
         case 26:
         case 28:
         case 30:
         case 32:
         case 33:
         case 34:
         case 36:
         case 37:
         case 38:
         case 39:
         case 40:
         case 41:
         case 44:
         case 46:
         default:
            break;
         case 19:
            this.field_280 = new class_20[2];
            this.field_280[0] = new class_20(766, 1, 8, 0);
            this.field_280[1] = new class_20(767, 1, 6, 1);
            break;
         case 21:
            this.field_280 = new class_20[2];
            this.field_280[0] = new class_20(788, 3, 5, 15000);
            this.field_280[1] = new class_20(789, 3, 8, 0);
            break;
         case 23:
            this.field_280 = new class_20[2];
            this.field_280[0] = new class_20(806, 2, 5, 3000);
            this.field_280[1] = new class_20(807, 2, 6, 0);
            break;
         case 25:
            this.field_280 = new class_20[4];
            this.field_280[0] = new class_20(826, 5, 5, 15000);
            this.field_280[1] = new class_20(827, 3, 6, 0);
            this.field_280[2] = new class_20(828, 3, 6, 1);
            this.field_280[3] = new class_20(829, 5, 6, 2);
            break;
         case 27:
            this.field_280 = new class_20[5];
            this.field_280[0] = new class_20(873, 3, 12, 0);
            this.field_280[1] = new class_20(874, 0, 6, 0);
            this.field_280[2] = new class_20(875, 1, 1, 0);
            this.field_280[3] = new class_20(876, 1, 14, 0);
            this.field_280[4] = new class_20(877, 1, 6, 2);
            break;
         case 29:
            this.field_280 = new class_20[2];
            this.field_280[0] = new class_20(883, 1, 5, 2000);
            this.field_280[1] = new class_20(884, 7, 6, 0);
            break;
         case 31:
            this.field_280 = new class_20[5];
            this.field_280[0] = new class_20(900, 5, 5, 2000);
            this.field_280[1] = new class_20(901, 0, 16, 0);
            this.field_280[2] = new class_20(902, 6, 6, 1);
            this.field_280[3] = new class_20(903, 4, 6, 2);
            this.field_280[4] = new class_20(904, 5, 6, 3);
            break;
         case 35:
            this.field_280 = new class_20[3];
            this.field_280[0] = new class_20(934, 1, 16, 0);
            this.field_280[1] = new class_20(935, 11, 6, 0);
            this.field_280[2] = new class_20(936, 11, 12, 0);
            break;
         case 42:
            int[] var2 = new int[]{0, 1, 2};
            int[] var3 = new int[]{3, 4, 5};
            this.field_280 = new class_20[4];
            this.field_280[0] = new class_20(971, 1, 5, 5000);
            this.field_280[1] = new class_20(972, 1, 8, var2);
            this.field_280[2] = new class_20(973, 10, 15, 0);
            this.field_280[3] = new class_20(974, 1, 8, var3);
            break;
         case 43:
            this.field_280 = new class_20[3];
            this.field_280[0] = new class_20(982, 1, 5, 60000);
            this.field_280[1] = new class_20(983, 1, 6, 0);
            this.field_280[2] = new class_20(984, 9, 6, 1);
            break;
         case 45:
            this.field_280 = new class_20[2];
            this.field_280[0] = new class_20(1004, 0, 5, 30000);
            this.field_280[1] = new class_20(1005, 1, 6, 0);
            break;
         case 47:
            this.field_280 = new class_20[25];
            this.field_280[0] = new class_20(1024, 5, 5, 30000);
            this.field_280[1] = new class_20(1025, 2, 6, 0);
            this.field_280[2] = new class_20(1026, 2, 17, this.field_273.length - 1);
            this.field_280[3] = new class_20(1027, 9, 6, 2);
            this.field_280[4] = new class_20(1028, 0, 19, this.field_273.length - 1);
            this.field_280[5] = new class_20(1029, 1, 6, 4);
            this.field_280[6] = new class_20(1030, 9, 1, this.field_273.length - 1);
            this.field_280[7] = new class_20(1031, 1, 6, 6);
            this.field_280[8] = new class_20(1032, 0, 6, 7);
            this.field_280[9] = new class_20(1033, 9, 6, 8);
            this.field_280[10] = new class_20(1034, 9, 6, 9);
            this.field_280[11] = new class_20(1035, 5, 6, 10);
            this.field_280[12] = new class_20(1036, 9, 6, 11);
            this.field_280[13] = new class_20(1037, 0, 6, 12);
            this.field_280[14] = new class_20(1038, 5, 6, 13);
            this.field_280[15] = new class_20(1039, 0, 6, 14);
            this.field_280[16] = new class_20(1040, 1, 6, 15);
            this.field_280[17] = new class_20(1041, 0, 6, 16);
            this.field_280[18] = new class_20(1042, 1, 6, 17);
            this.field_280[19] = new class_20(1043, 2, 6, 18);
            this.field_280[20] = new class_20(1044, 2, 6, 19);
            this.field_280[21] = new class_20(1045, 2, 6, 20);
            this.field_280[22] = new class_20(1046, 5, 6, 21);
            this.field_280[23] = new class_20(1047, 0, 6, 22);
            this.field_280[24] = new class_20(1048, 1, 6, 23);
      }

      return this.field_280;
   }

   // $VF: renamed from: a (int, boolean) void
   public final void method_257(int var1, boolean var2) {
      this.field_281--;
      this.field_288++;
      if (!var2 && var1 != 13) {
         class_21.method_203();
      }
   }

   // $VF: renamed from: j () void
   public final void method_258() {
      this.field_281--;
   }

   // $VF: renamed from: k () void
   public final void method_259() {
      this.field_282--;
   }

   // $VF: renamed from: l () void
   public final void method_260() {
      this.field_285--;
      this.field_286 = (int)((float)this.field_285 / class_21.method_132().field_1167 * 100.0F) + "%/" + class_21.method_132().field_1169 + "%";
   }

   // $VF: renamed from: m () void
   public final void method_261() {
      this.field_287++;
   }

   // $VF: renamed from: a (x, boolean) boolean
   public final boolean method_262(class_3 var1, boolean var2) {
      return field_263.method_287(var1.field_37, var1.field_38, var1.field_39);
   }

   // $VF: renamed from: a (x) boolean
   public final boolean method_263(class_3 var1) {
      return this.field_276 != null ? this.field_276[1].method_806(var1.field_37, var1.field_38, var1.field_39) : false;
   }

   // $VF: renamed from: b (x) boolean
   public final boolean method_264(class_3 var1) {
      return this.field_276 != null && this.field_276[0] != null && !class_21.method_147()
         ? this.field_276[0].method_806(var1.field_37, var1.field_38, var1.field_39)
         : false;
   }

   // $VF: renamed from: a (long) void
   public final void method_265(long var1) {
      class_84.field_1117.setColor(this.field_298, this.field_299, this.field_300);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      if (!org.deep3d.Remaster.on()) { // Deep3D-PC: Remastered draws its own water
         class_84.field_1110.method_25(this.field_265);
      }
      if (this.field_269 != null) {
         for (int var3 = 0; var3 < this.field_269.length; var3++) {
            this.field_269[var3].method_887();
         }
      }

      if (this.field_270 != null) {
         for (int var4 = 0; var4 < this.field_270.length; var4++) {
            this.field_270[var4].method_887();
         }
      }

      if (this.field_271 != null) {
         for (int var5 = 0; var5 < this.field_271.length; var5++) {
            this.field_271[var5].method_887();
         }
      }

      if (this.field_273 != null) {
         for (int var6 = 0; var6 < this.field_273.length; var6++) {
            this.field_273[var6].method_805(var1);
            this.field_273[var6].method_809();
         }
      }

      if (this.field_274 != null) {
         for (int var7 = 0; var7 < this.field_274.length; var7++) {
            this.field_274[var7].method_805(var1);
            this.field_274[var7].method_809();
         }
      }

      if (this.field_275 != null) {
         for (int var8 = 0; var8 < this.field_275.length; var8++) {
            this.field_275[var8].method_805(var1);
            this.field_275[var8].method_809();
         }
      }

      if (this.field_276 != null) {
         for (int var9 = 0; var9 < this.field_276.length; var9++) {
            if (this.field_276[var9] != null) {
               this.field_276[var9].method_805(var1);
               this.field_276[var9].method_809();
            }
         }
      }
      this.deep3dRemaster(); // Deep3D-PC
      Deep3dDebug.worldFrames++;
   }

   // $VF: renamed from: b (long) void
   public final void method_266(long var1) {
      class_84.field_1117.setColor(this.field_298, this.field_299, this.field_300);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      if (!org.deep3d.Remaster.on()) { // Deep3D-PC: Remastered draws its own water
         class_84.field_1110.method_25(this.field_265);
      }
      if (this.field_269 != null) {
         for (int var3 = 0; var3 < this.field_269.length; var3++) {
            this.field_269[var3].method_887();
         }
      }

      if (this.field_270 != null) {
         for (int var4 = 0; var4 < this.field_270.length; var4++) {
            this.field_270[var4].method_887();
         }
      }

      if (this.field_271 != null) {
         for (int var5 = 0; var5 < this.field_271.length; var5++) {
            this.field_271[var5].method_887();
         }
      }

      if (this.field_273 != null) {
         for (int var6 = 0; var6 < this.field_273.length; var6++) {
            this.field_273[var6].method_809();
         }
      }

      if (this.field_274 != null) {
         for (int var7 = 0; var7 < this.field_274.length; var7++) {
            this.field_274[var7].method_809();
         }
      }

      if (this.field_275 != null) {
         for (int var8 = 0; var8 < this.field_275.length; var8++) {
            this.field_275[var8].method_809();
         }
      }

      if (this.field_276 != null) {
         for (int var9 = 0; var9 < this.field_276.length; var9++) {
            if (this.field_276[var9] != null) {
               this.field_276[var9].method_809();
            }
         }
      }
      this.deep3dRemaster(); // Deep3D-PC
      Deep3dDebug.worldFrames++;
   }

   // $VF: renamed from: c (long) void
   public final void method_267(long var1) {
      if (this.field_272 != null) {
         float var3 = this.field_272.method_665();
         this.field_298 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_295 * var3))));
         this.field_299 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_296 * var3))));
         this.field_300 = class_16.method_97(0, class_16.method_98(255, class_16.method_97(0, (int)(this.field_297 * var3))));
      }

      if (this.field_269 != null) {
         for (int var4 = 0; var4 < this.field_269.length; var4++) {
            ((class_112)this.field_269[var4]).method_895(var1);
         }
      }

      if (this.field_270 != null) {
         for (int var5 = 0; var5 < this.field_270.length; var5++) {
            ((class_112)this.field_270[var5]).method_895(var1);
         }
      }

      if (this.field_271 != null) {
         for (int var6 = 0; var6 < this.field_271.length; var6++) {
            ((class_112)this.field_271[var6]).method_895(var1);
         }
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_268(int var1) {
      return this.field_289 != null ? this.field_289.method_222(var1) : false;
   }

   // $VF: renamed from: n () void
   public final void method_269() {
      this.field_289 = null;
      this.field_290 = null;
   }

   // $VF: renamed from: b (int) boolean
   public final boolean method_270(int var1) {
      return this.field_290 != null ? this.field_290.method_222(var1) : false;
   }

   // $VF: renamed from: o () void
   public final void method_271() {
      class_43.method_384();
      if (this.field_276 != null) {
         for (int var1 = 0; var1 < this.field_276.length; var1++) {
            if (this.field_276[var1] != null) {
               this.field_276[var1].method_794();
               this.field_276[var1] = null;
            }
         }
      }

      this.field_276 = null;
      if (this.field_266 != null) {
         this.field_266.method_894();
      }

      this.field_266 = null;
      if (this.field_268 != null) {
         this.field_268.method_894();
      }

      this.field_268 = null;
      if (this.field_269 != null) {
         for (int var2 = 0; var2 < this.field_269.length; var2++) {
            this.field_269[var2].method_894();
         }
      }

      this.field_269 = null;
      if (this.field_270 != null) {
         for (int var3 = 0; var3 < this.field_270.length; var3++) {
            this.field_270[var3].method_894();
         }
      }

      this.field_270 = null;
      if (this.field_271 != null) {
         for (int var4 = 0; var4 < this.field_271.length; var4++) {
            this.field_271[var4].method_894();
         }
      }

      this.field_271 = null;
      if (this.field_272 != null) {
         this.field_272.method_680();
      }

      this.field_272 = null;
      if (this.field_273 != null) {
         for (int var5 = 0; var5 < this.field_273.length; var5++) {
            this.field_273[var5].method_794();
         }
      }

      this.field_273 = null;
      if (this.field_274 != null) {
         for (int var6 = 0; var6 < this.field_274.length; var6++) {
            this.field_274[var6].method_794();
         }
      }

      this.field_274 = null;
      if (this.field_277 != null) {
         this.field_277.method_108();
      }

      this.field_277 = null;
      if (this.field_278 != null) {
         this.field_278.method_108();
      }

      this.field_278 = null;
      if (this.field_279 != null) {
         this.field_279.method_108();
      }

      this.field_279 = null;
      this.field_280 = null;
      this.field_289 = null;
      this.field_290 = null;
      this.field_292 = 0;
      System.gc();
   }

   // Deep3D-PC: the frame's world for the Remastered renderer (org.deep3d.Remaster)
   private final float[] deep3dCam = new float[16];
   private final class_3 deep3dPos = new class_3();

   private void deep3dRemaster() {
      if (!org.deep3d.Remaster.on() || class_84.field_1110 == null || class_84.field_1110.field_40 == null) {
         return;
      }
      class_84.field_1110.field_40.field_1342.method_505(this.deep3dCam);
      // the background fill the skydome shows through: tint x depth light
      org.deep3d.Remaster.world(
         this.deep3dCam, class_21.method_180() != null ? class_21.method_180().field_1140 : 21000,
         this.field_298 / 255.0F, this.field_299 / 255.0F, this.field_300 / 255.0F
      );
      if (this.field_272 != null && this.field_272.field_970 != null) {
         this.field_272.field_970.method_849(this.deep3dPos);
         class_3 var2 = this.field_272.field_970.method_855(new class_3());
         org.deep3d.Remaster.sub(
            this.deep3dPos.field_37, this.deep3dPos.field_38, this.deep3dPos.field_39,
            var2.field_37 / 4096.0F, var2.field_38 / 4096.0F, var2.field_39 / 4096.0F,
            this.field_272.field_994 ? 1.0F : 0.0F
         );
      }
      class_91[][] var3 = new class_91[][]{this.field_273, this.field_274};
      for (int var4 = 0; var4 < var3.length; var4++) {
         if (var3[var4] != null) {
            for (int var5 = 0; var5 < var3[var4].length; var5++) {
               class_91 var6 = var3[var4][var5];
               if (var6 instanceof class_96 && var6.field_1226 != null && var6.field_1224 != 3 && var6.field_1224 != 4) {
                  var6.field_1226.method_849(this.deep3dPos);
                  org.deep3d.Remaster.light(this.deep3dPos.field_37, this.deep3dPos.field_38, this.deep3dPos.field_39, 1);
               }
            }
         }
      }
   }
}
