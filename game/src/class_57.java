// $VF: renamed from: cy
public final class class_57 {
   // $VF: renamed from: e int
   private int field_764;
   // $VF: renamed from: a dp
   public static class_36 field_765 = new class_38(0, 0, 0, 0, 0, 0, 10000);
   // $VF: renamed from: a int[][]
   private static final int[][] field_766 = new int[][]{{-1100, 200, 1100}, {-951, 161, -1500}, {-823, 115, -4100}};
   // $VF: renamed from: a ay
   private class_101 field_767;
   // $VF: renamed from: a aj
   private class_103 field_768;
   // $VF: renamed from: b aj
   private class_103 field_769;
   // $VF: renamed from: c aj
   private class_103 field_770;
   // $VF: renamed from: a ay[]
   private class_101[] field_771;
   // $VF: renamed from: b ay[]
   private class_101[] field_772;
   // $VF: renamed from: c ay[]
   private class_101[] field_773;
   // $VF: renamed from: a bb
   public class_16 field_774;
   // $VF: renamed from: a aw[]
   public class_83[] field_775;
   // $VF: renamed from: b aw[]
   public class_83[] field_776;
   // $VF: renamed from: c aw[]
   public class_83[] field_777;
   // $VF: renamed from: d aw[]
   public class_83[] field_778;
   // $VF: renamed from: a dr
   public class_13 field_779;
   // $VF: renamed from: b dr
   private class_13 field_780;
   // $VF: renamed from: c dr
   private class_13 field_781;
   // $VF: renamed from: a dk[]
   public class_31[] field_782;
   // $VF: renamed from: a int
   public int field_783;
   // $VF: renamed from: b int
   public int field_784;
   // $VF: renamed from: f int
   private int field_785;
   // $VF: renamed from: g int
   private int field_786;
   // $VF: renamed from: h int
   private int field_787;
   // $VF: renamed from: a java.lang.String
   public String field_788 = "";
   // $VF: renamed from: c int
   public int field_789;
   // $VF: renamed from: i int
   private int field_790;
   // $VF: renamed from: a dh
   public class_15 field_791;
   // $VF: renamed from: b dh
   public class_15 field_792;
   // $VF: renamed from: d int
   public int field_793;
   // $VF: renamed from: j int
   private int field_794;
   // $VF: renamed from: a boolean
   public boolean field_795;
   // $VF: renamed from: k int
   private int field_796;
   // $VF: renamed from: a float
   private float field_797;
   // $VF: renamed from: b float
   private float field_798;
   // $VF: renamed from: c float
   private float field_799;
   // $VF: renamed from: l int
   private int field_800;
   // $VF: renamed from: m int
   private int field_801;
   // $VF: renamed from: n int
   private int field_802;
   // $VF: renamed from: b boolean
   public static boolean field_803;
   // $VF: renamed from: a an
   public static class_60 field_804;

   public class_57() {
      this(3);
   }

   public class_57(int var1) {
      this.field_764 = var1;
      this.field_794 = 0;
      this.field_795 = false;
   }

   // $VF: renamed from: a () void
   public static final void method_529() {
      field_803 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_530() {
      if (this.field_794 == 0 || this.field_795) {
         this.field_779 = null;
         this.field_781 = null;
         this.field_780 = null;
         this.field_792 = null;
         this.field_791 = null;
         this.field_768 = new class_103(class_25.method_327(2), 96, 0, 127, 32, 10, 700, 100, 500);
         this.field_770 = new class_103(class_25.method_327(2), 96, 0, 127, 32, 10, 700, 100, 500);
         this.method_531();
         if (this.field_764 != 0) {
            this.method_534();
            if (field_803 && this.field_774.field_203 != null) {
               this.field_774
                  .method_251(this.field_778[2].field_1103.method_848(), this.field_778[2].field_1103.method_849(), this.field_778[2].field_1103.method_850());
            } else {
               this.field_774.method_251(10, 0, 5000);
            }

            if (class_3.method_73() == 1) {
               this.field_774.method_251(0, 0, -110000);
            }
         }
      }

      if (this.field_794 != 1 && !this.field_795) {
         if (this.field_795) {
            this.field_794 = 0;
            return true;
         }
      } else {
         this.method_532();
         if ((this.field_764 != 3 || class_3.method_62().field_1241) && (this.field_764 != 3 || !class_3.method_76())) {
            if (this.field_764 != 3) {
               this.method_539();
               this.field_764 = 3;
            } else if (!class_3.method_62().method_789() && class_3.method_62().field_1241) {
               this.method_538();
            }
         } else {
            this.method_537();
         }

         this.method_540();
         this.method_541();
         if (this.field_774 != null) {
            this.field_774.field_215 = this.field_779;
         }

         this.field_784 = this.field_776 != null ? this.field_776.length - this.field_786 : 0;
         this.field_783 = this.field_775 != null ? this.field_775.length - this.field_785 : 0;
         this.field_787 = 0;
         if (class_3.method_62().field_1226 == 7) {
            if (this.field_777 != null) {
               for (int var1 = 0; var1 < this.field_777.length; var1++) {
                  if (((class_89)this.field_777[var1]).field_1171.field_857 == class_3.method_62().field_1246) {
                     this.field_787++;
                  }
               }
            }
         } else {
            this.field_787 = this.field_777 != null ? this.field_777.length : 0;
         }

         this.field_788 = (int)((float)this.field_787 / class_3.method_62().field_1247 * 100.0F) + "%/" + class_3.method_62().field_1249 + "%";
         this.field_790 = 0;
         this.field_795 = true;
      }

      this.field_794++;
      return this.field_795;
   }

   // $VF: renamed from: b () void
   public final void method_531() {
      if (this.field_767 == null) {
         this.field_767 = class_25.method_328(9991);
      }

      this.field_767.method_883(class_25.method_327(0));
      this.field_778 = new class_83[3];
      if (class_3.method_77()) {
         this.field_778[0] = null;
      } else {
         this.field_778[0] = new class_92(class_3.method_110());
      }

      class_5 var1 = new class_5();
      class_5 var2 = new class_5(var1);
      this.field_796 = 0;

      for (int var3 = 1; var3 <= 2; var3++) {
         if (class_3.method_110() != null) {
            if (var3 == 0) {
               this.field_796 = class_3.method_110().field_827.length() + class_3.method_110().field_833 * 3;
               this.field_796 = this.field_796 % 16 * 256;
            } else {
               this.field_796 = this.field_796 + (class_3.method_110().field_833 > 4 ? 300 : -300);
            }

            var1.field_140 = var3 == 1 ? 90000 : 110000;
            var1.field_140 = var1.field_140 + this.field_796 * 3;
            class_1 var4;
            (var4 = new class_1()).method_23(this.field_796);
            (var2 = var4.method_40(var1, var2)).field_139 = 0;
         }

         this.field_778[var3] = new class_91(15, class_25.method_328(15), var2.field_138, var2.field_139, var2.field_140);
         ((class_91)this.field_778[var3]).method_776(this.field_796 + 2048);
      }

      this.field_796 += 2048;
      if (!field_803) {
         this.field_796 = 0;
      } else {
         ((class_91)this.field_778[2]).method_777();
      }

      ((class_91)this.field_778[1]).method_775();
      short[][] var8 = new short[][]{{255, 255, 128}, {98, 118, 255}, {234, 149, 55}, {239, 90, 95}, {154, 220, 109}};
      byte[] var9 = class_44.method_440(class_3.method_110());
      if (System.getenv("DEEP3D_DEBUG_WATER") != null) {
         System.out.println("[water] zone data " + java.util.Arrays.toString(var9));
      }

      for (int var5 = 0; var5 < var9.length; var5 += 2) {
         if (var9[var5] > 12 && var9[var5] < 18) {
            float var6 = var9[var5 + 1] / 100.0F * 1.5F;
            this.field_797 = var6 * var8[var9[var5] - 13][0];
            this.field_798 = var6 * var8[var9[var5] - 13][1];
            this.field_799 = var6 * var8[var9[var5] - 13][2];
            float var7 = class_3.method_110().method_584();
            this.field_800 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_797 * var7))));
            this.field_801 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_798 * var7))));
            this.field_802 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_799 * var7))));
            class_110.field_1352.setDirIntensity((int)class_124.method_944(4096.0F, 4096.0F * (var7 + 0.25F)));
            class_110.field_1352.setAmbientIntensity((int)class_124.method_944(2048.0F, 1024.0F + 1024.0F * (var7 + 0.25F)));
            return;
         }
      }
   }

   // $VF: renamed from: p () void
   private void method_532() {
      if (class_3.method_62().method_789() || class_3.method_62().field_1226 != 6 && (!class_3.method_62().field_1241 || class_3.method_62().field_1226 != 6)) {
         int var1 = 0;
         int var2 = 0;
         boolean var3 = false;
         this.field_777 = new class_83[class_3.method_77() ? 49 : 20];
         byte[] var4 = class_44.method_440(class_3.method_110());

         for (int var5 = 0; var5 < this.field_777.length; var5++) {
            if (class_3.method_77()) {
               var1 = 13 + var5 / 10;
            } else {
               var3 = false;

               while (!var3) {
                  if (class_41.field_540.nextInt(100) < var4[var2 + 1]) {
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

            this.field_777[var5] = this.method_533(var1, null);
         }
      }
   }

   // $VF: renamed from: a (int, bj) af
   private class_89 method_533(int var1, class_87 var2) {
      short var3 = class_24.field_358[var1];
      int var4 = 0;
      int var5 = 0;
      int var6 = 0;
      if (var2 != null) {
         var4 = var2.field_1161;
         var5 = var2.field_1162;
         var6 = var2.field_1163 - 20000;
      }

      class_89 var7;
      (var7 = new class_89(var3, class_25.method_328(var3), class_24.method_317()[var1], var4, var5, var6)).field_1106 = this;
      var7.field_1103.field_1294 = 2;
      class_8 var8 = new class_8(1, 2);
      var7.field_1108 = var8;
      return var7;
   }

   // $VF: renamed from: c () void
   public final void method_534() {
      try {
         class_101 var2;
         (var2 = class_25.method_328(class_24.field_361[class_3.method_108().field_422])).field_1294 = 2;
         class_51[] var3 = class_3.method_108().field_444;
         int var4 = 0;
         int var5 = 0;
         int var6 = 0;
         class_19[] var7 = null;
         class_19 var8 = null;
         if (var3 != null) {
            for (int var9 = 0; var9 < var3.length; var9++) {
               if (var3[var9] != null) {
                  switch (var3[var9].field_710) {
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
            var7 = new class_19[var5];
         }

         class_96 var15;
         (var15 = new class_96(1200.0F, class_3.method_108().field_423, var4)).method_810(class_3.method_108().field_430);
         var15.method_811(class_3.method_108().field_431);
         this.field_774 = new class_16(var15);
         this.field_774.field_214 = this;
         this.field_774.method_229(var2);
         this.field_774.field_203.method_860(0, this.field_796, 0);
         int[] var10 = new int[]{0, 0, 0};
         class_8 var11 = new class_8(var10.length / 3, 0);
         this.field_774.field_212 = var11;
         if (var3 != null) {
            for (int var12 = 0; var12 < var3.length; var12++) {
               if (var3[var12] != null) {
                  class_19 var13 = null;
                  if (var3[var12].method_503()) {
                     (var13 = this.method_535(var3[var12].field_711, var3[var12].field_716, var3[var12].field_717, var3[var12].field_718, var3[var12].field_719))
                        .field_301 = var3[var12].field_710;
                     switch (var3[var12].field_710) {
                        case 0:
                        case 1:
                           var13.method_280(var5 - 1, var7.length);
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
            this.field_774.method_239(var7, 0);
         }

         if (var8 != null) {
            this.field_774.method_238(var8, var16);
         }

         class_3.method_108().method_379();
      } catch (Exception var14) {
         var14.printStackTrace();
      }
   }

   // $VF: renamed from: a (int, int, int, int, int) o
   public final class_19 method_535(int var1, int var2, int var3, int var4, int var5) {
      class_19 var6 = null;
      class_101 var7 = null;
      Object var8 = null;
      class_103 var9 = this.field_768;
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
            var6 = new class_19(var2, 10, -1, var4, var3, var5, new class_5(0, 0, 200), new class_5());
            var8 = new class_106(var6, class_25.method_328(var1 == 42 ? 6766 : class_24.field_357[var1]), 1000);
            break;
         case 3:
         case 4:
         case 5:
            var6 = new class_19(var2, 1, -1, var4, var3, var5, new class_5(0, 0, 2200), new class_5());
            (var7 = class_101.method_880(0, 128, 64, 0, 96, 32, 300, 1, (byte)2)).method_883(class_25.method_327(2));
            int[] var14 = new int[]{-16711936};
            var7.field_1294 = 2;
            var8 = new class_109(var6, var7, this.field_774.field_203, var1 - 3);
            break;
         case 12:
         case 13:
         case 14:
            var6 = new class_19(var2, 1, -1, var4, var3, var5, new class_5(), new class_5());
            (var7 = class_25.method_328(16)).field_1294 = 2;
            var8 = new class_107(var6, var7, -16711936, true);
            var9 = this.field_770;
            break;
         case 15:
         case 16:
         case 17:
            var6 = new class_19(0, 1, -1, var4, var4, var5, new class_5(), new class_5());
            (var7 = class_101.method_880(0, 128, 64, 0, 96, 32, 500, 1, (byte)2)).method_883(class_25.method_327(2));
            int[] var10000 = new int[]{-16711936};
            var7.field_1294 = 2;
            var8 = new class_108(var6, var7, this.field_774.field_203, var2, var1 - 15, var3);
            var9 = this.field_769;
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

      var6.field_277 = this;
      if (var1 != 15 && var1 != 16 && var1 != 17) {
         var6.method_282(var9);
      }

      if (this.field_771 == null) {
         this.field_771 = new class_101[]{(class_101)var8};
      } else {
         class_101[] var10 = new class_101[this.field_771.length + 1];
         System.arraycopy(this.field_771, 0, var10, 0, this.field_771.length);
         var10[var10.length - 1] = (class_101)var8;
         this.field_771 = var10;
      }

      return var6;
   }

   // $VF: renamed from: d () void
   public final void method_536() {
      boolean var1 = false;
      this.field_776 = new class_83[1];
      this.field_776[0] = this.method_544(1, 0, 5, false, null);
      if (field_803 && this.field_774.field_203 != null) {
         ((class_85)this.field_776[0])
            .method_763(
               this.field_778[2].field_1103.method_848() - 3000,
               this.field_778[2].field_1103.method_849() + 1000,
               this.field_778[2].field_1103.method_850() + 5000
            );
      } else {
         ((class_85)this.field_776[0])
            .method_763(
               this.field_774.field_203.method_848() + -700 + class_41.field_540.nextInt(1400),
               this.field_774.field_203.method_849() + -700 + class_41.field_540.nextInt(1400),
               this.field_774.field_203.method_850() + 2000
            );
      }

      if (this.field_779 != null) {
         this.field_776[0].field_1107 = this.field_779.method_224();
      }

      this.field_776[0].field_1102.method_806(9999999);
   }

   // $VF: renamed from: e () void
   public final void method_537() {
      class_95 var1 = class_3.method_62();
      boolean var2 = false;
      boolean var3 = false;
      if (var1 != null) {
         if (var1.method_789()) {
            this.field_764 = 0;
            this.method_539();
            this.field_764 = 3;
            int var28;
            if (class_3.method_73() > 11 && class_41.field_540.nextInt(100) < 25 + class_3.method_73() && (var28 = 0 + class_41.field_540.nextInt(4)) > 0) {
               this.field_775 = new class_83[var28];
               class_13 var30 = new class_13(new int[]{0, 0, 15000});

               for (int var32 = 0; var32 < this.field_775.length; var32++) {
                  this.field_775[var32] = this.method_544(2, 0, class_24.method_321(), true, var30.method_218(0));
               }
            }
         } else {
            switch (var1.field_1226) {
               case 0:
                  this.field_779 = new class_13(
                     new int[]{
                        (40000 + class_41.field_540.nextInt(80000)) * (class_41.field_540.nextInt(2) == 0 ? 1 : -1),
                        0,
                        (40000 + class_41.field_540.nextInt(80000)) * (class_41.field_540.nextInt(2) == 0 ? 1 : -1)
                     }
                  );
                  this.field_775 = new class_83[1];
                  this.field_775[0] = this.method_544(2, 0, class_24.method_321(), true, this.field_779.method_218(0));
                  this.field_775[0].method_750();
                  int var34 = class_3.method_62().field_1234 * class_3.method_140();
                  this.field_775[0].field_1102.method_809(300 + var34);
                  this.field_791 = new class_15(1, 0, this);
                  return;
               case 1:
               case 2:
                  this.field_779 = this.method_545(2 + class_41.field_540.nextInt(2));
                  this.field_775 = new class_83[3 + (int)(3.0F * (class_3.method_62().method_799() / 10.0F))];

                  for (int var27 = 0; var27 < this.field_775.length; var27++) {
                     this.field_775[var27] = this.method_544(
                        2,
                        0,
                        class_24.method_321(),
                        true,
                        var27 == this.field_775.length - 1
                           ? this.field_779.method_218(this.field_779.method_222() - 1)
                           : this.field_779.method_218(class_41.field_540.nextInt(this.field_779.method_222()))
                     );
                     this.field_775[var27].method_750();
                  }

                  ((class_85)this.field_775[this.field_775.length - 1]).method_759(true);
                  this.field_791 = new class_15(11, this.field_775.length - 1, this);
                  this.field_792 = new class_15(12, this.field_775.length - 1, this);
                  return;
               case 3:
                  this.field_779 = this.method_545(2 + class_41.field_540.nextInt(2));
                  int var26 = 3 + (int)(3.0F * (class_3.method_62().method_799() / 10.0F));
                  this.field_775 = new class_83[var26];

                  for (int var29 = 0; var29 < this.field_775.length; var29++) {
                     this.field_775[var29] = this.method_544(
                        2, 0, class_24.method_321(), true, this.field_779.method_218(class_41.field_540.nextInt(this.field_779.method_222()))
                     );
                     this.field_775[var29].method_750();
                  }

                  this.field_791 = new class_15(0, 0, this);
                  return;
               case 4:
                  this.field_781 = new class_13(new int[]{10000, 0, 100000, 10000, 0, 150000, 10000, 0, 200000});
                  int var10 = 2 + (int)(4.0F * (class_3.method_62().method_799() / 10.0F));
                  this.field_775 = new class_83[var10];
                  int var35 = var1.field_1229 == 0 ? 1 : 0;
                  int var12 = var1.field_1229;

                  for (int var13 = 0; var13 < this.field_775.length; var13++) {
                     this.field_775[var13] = this.method_544(
                        var35, 0, class_24.method_321(), true, this.field_781.method_218(class_41.field_540.nextInt(this.field_781.method_222()))
                     );
                     this.field_775[var13].method_750();
                  }

                  this.field_776 = new class_83[5];

                  for (int var36 = 0; var36 < this.field_776.length; var36++) {
                     this.field_776[var36] = this.method_544(var12, 3, 11, false, null);
                     this.field_776[var36].field_1102.method_809(100 + class_3.method_140() * 2 + class_3.method_73() * 2);
                     ((class_84)this.field_776[var36]).field_1120 = true;
                  }

                  boolean var14 = false;
                  boolean var15 = false;
                  ((class_84)this.field_776[0]).method_757(5500, -300, 20000);
                  ((class_84)this.field_776[1]).method_757(14500, 3000, 17000);
                  ((class_84)this.field_776[2]).method_757(4000, -2000, 12000);
                  ((class_84)this.field_776[3]).method_757(17000, -6000, 10000);
                  ((class_84)this.field_776[4]).method_757(11000, 7000, 8000);
                  this.field_791 = new class_15(0, 0, this);
                  this.field_792 = new class_15(5, 0, this);
                  return;
               case 5:
                  this.field_779 = new class_13(
                     new int[]{
                        -2500 + class_41.field_540.nextInt(5000),
                        -2500 + class_41.field_540.nextInt(5000),
                        80000 + class_41.field_540.nextInt(30000),
                        -2500 + class_41.field_540.nextInt(5000),
                        -2500 + class_41.field_540.nextInt(5000),
                        120000 + class_41.field_540.nextInt(30000)
                     }
                  );
                  int var16 = 2 + class_41.field_540.nextInt(2);
                  int var17 = 2 + (int)(2.0F * (class_3.method_62().method_799() / 10.0F));
                  int var11 = var1.field_1229 == 0 ? 1 : 0;
                  this.field_775 = new class_83[var16 + var17];

                  for (int var18 = 0; var18 < var16; var18++) {
                     this.field_775[var18] = this.method_544(var11, 3, 11, true, this.field_779.method_218(1));
                     this.field_775[var18].method_750();
                     ((class_84)this.field_775[var18]).field_1120 = false;
                     ((class_84)this.field_775[var18])
                        .method_757(
                           this.field_779.method_218(1).field_1161 + -10000 + class_41.field_540.nextInt(20000),
                           this.field_779.method_218(1).field_1162 + -10000 + class_41.field_540.nextInt(20000),
                           this.field_779.method_218(1).field_1163 + -10000 + class_41.field_540.nextInt(20000)
                        );
                  }

                  for (int var37 = var16; var37 < this.field_775.length; var37++) {
                     this.field_775[var37] = this.method_544(
                        var11, 0, class_24.method_321(), true, this.field_779.method_218(class_41.field_540.nextInt(this.field_779.method_222()))
                     );
                     this.field_775[var37].method_750();
                  }

                  this.field_791 = new class_15(7, var16, this);
               default:
                  return;
               case 6:
                  this.field_780 = new class_13(new int[]{20000, 0, -40000, 20000, 0, 40000, 20000, 0, 90000});
                  this.field_777 = new class_83[var1.field_1247];

                  for (int var24 = 0; var24 < this.field_777.length; var24++) {
                     this.field_777[var24] = this.method_533(var1.field_1246, this.field_780.method_218(0));
                     ((class_89)this.field_777[var24]).method_767(true);
                     this.field_777[var24].field_1102.method_806(this.field_777[var24].field_1102.field_1256 * 2);
                  }

                  this.field_775 = new class_83[2 + (int)(4.0F * (class_3.method_62().method_799() / 10.0F))];

                  for (int var25 = 0; var25 < this.field_775.length; var25++) {
                     this.field_775[var25] = this.method_544(
                        0, 0, class_24.method_321(), true, this.field_780.method_218(1 + class_41.field_540.nextInt(this.field_780.method_222() - 1))
                     );
                     this.field_775[var25].method_750();
                  }

                  this.field_791 = new class_15(0, 0, this);
                  this.field_792 = new class_15(8, var1.field_1247 - var1.field_1248, this);
                  return;
               case 7:
                  this.field_775 = new class_83[0 + (int)(3.0F * (class_3.method_62().method_799() / 10.0F))];
                  if (this.field_775.length > 0) {
                     for (int var22 = 0; var22 < this.field_775.length; var22++) {
                        this.field_775[var22] = this.method_544(1, 0, class_24.method_321(), true, null);
                     }
                  } else {
                     this.field_775 = null;
                  }

                  for (int var23 = 0; var23 < var1.field_1247 + 3 && var23 < this.field_777.length; var23++) {
                     this.field_777[var23] = this.method_533(var1.field_1246, null);
                  }

                  this.field_791 = new class_15(13, var1.field_1246, var1.field_1247, this);
                  return;
               case 8:
                  return;
               case 9:
                  class_13 var31 = new class_13(new int[]{-20000 + class_41.field_540.nextInt(40000), 0, 20000 + class_41.field_540.nextInt(40000)});
                  int var7 = (int)(2.0F * (class_3.method_62().method_799() / 10.0F));
                  int var8 = 15 + (int)(15.0F * (class_3.method_62().method_799() / 10.0F));
                  this.field_775 = new class_83[var8 + var7];

                  for (int var9 = 0; var9 < this.field_775.length - var7; var9++) {
                     this.field_775[var9] = this.method_543(var31.method_218(0), 9996);
                  }

                  for (int var33 = this.field_775.length - var7; var33 < this.field_775.length; var33++) {
                     this.field_775[var33] = this.method_544(2, 0, class_24.method_321(), true, null);
                  }

                  this.field_791 = new class_15(7, this.field_775.length - var7, this);
                  this.field_793 = 151000;
                  return;
               case 10:
                  class_13 var5 = new class_13(new int[]{-20000 + class_41.field_540.nextInt(40000), 0, 20000 + class_41.field_540.nextInt(40000)});
                  this.field_775 = new class_83[class_41.field_540.nextInt(11) + 15 + 1];

                  for (int var6 = 0; var6 < this.field_775.length - 1; var6++) {
                     this.field_775[var6] = this.method_543(var5.method_219(), 13);
                  }

                  this.field_775[this.field_775.length - 1] = this.method_544(2, 0, 1, true, var5.method_218(0));
                  this.field_791 = new class_15(7, this.field_775.length - 1, this);
                  return;
               case 11:
                  this.field_775 = new class_83[2 + (int)(4.0F * (class_3.method_62().method_799() / 10.0F))];

                  for (int var20 = 0; var20 < this.field_775.length; var20++) {
                     this.field_775[var20] = this.method_544(3, 0, 19, true, null);
                  }

                  this.field_776 = new class_83[class_3.method_62().field_1247];

                  for (int var21 = 0; var21 < this.field_776.length; var21++) {
                     this.field_776[var21] = this.method_544(3, 7, 9994, false, null);
                  }

                  this.field_792 = new class_15(14, class_3.method_62().field_1248, this);
                  this.field_791 = new class_15(0, 0, this);
                  return;
               case 12:
                  this.field_775 = new class_83[class_3.method_62().field_1247 + 2 + (int)(4.0F * (class_3.method_62().method_799() / 10.0F))];

                  for (int var4 = 0; var4 < this.field_775.length; var4++) {
                     if (var4 < class_3.method_62().field_1247) {
                        this.field_775[var4] = this.method_544(3, 7, 9994, true, null);
                     } else {
                        this.field_775[var4] = this.method_544(0, 0, class_24.method_321(), true, null);
                     }
                  }

                  this.field_776 = new class_83[0 + (int)(3.0F * (class_3.method_62().method_799() / 10.0F))];
                  if (this.field_776.length > 0) {
                     for (int var19 = 0; var19 < this.field_776.length; var19++) {
                        this.field_776[var19] = this.method_544(3, 0, 19, false, null);
                     }
                  }

                  this.field_791 = new class_15(7, class_3.method_62().field_1247, this);
            }
         }
      }
   }

   // $VF: renamed from: f () void
   public final void method_538() {
      class_95 var4 = class_3.method_62();
      switch (class_3.method_73()) {
         case 5:
            this.field_775 = new class_83[1];
            this.field_775[0] = this.method_544(2, 0, 1, true, null);
            this.field_791 = new class_15(0, 0, this);
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
            for (int var19 = 0; var19 < var4.field_1247; var19++) {
               this.field_777[var19] = this.method_533(var4.field_1246, null);
            }

            this.field_791 = new class_15(13, var4.field_1246, var4.field_1247, this);
            break;
         case 10:
            this.field_775 = new class_83[4];

            for (int var17 = 0; var17 < this.field_775.length; var17++) {
               this.field_775[var17] = this.method_544(3, 0, 19, true, null);
            }

            this.field_776 = new class_83[class_3.method_62().field_1247];

            for (int var18 = 0; var18 < this.field_776.length; var18++) {
               this.field_776[var18] = this.method_544(3, 7, 9994, false, null);
            }

            this.field_792 = new class_15(14, class_3.method_62().field_1248, this);
            this.field_791 = new class_15(0, 0, this);
            break;
         case 19:
            this.field_780 = new class_13(new int[]{-20000, 0, -40000, -20000, 0, 30000, -20000, 0, 100000, -20000, 0, 130000});
            this.field_777 = new class_83[var4.field_1247];

            for (int var14 = 0; var14 < this.field_777.length; var14++) {
               this.field_777[var14] = this.method_533(var4.field_1246, this.field_780.method_218(1));
               ((class_89)this.field_777[var14]).method_767(true);
               this.field_777[var14].field_1102.method_806(this.field_777[var14].field_1102.field_1256 * 2);
            }

            this.field_775 = new class_83[3];

            for (int var15 = 0; var15 < this.field_775.length; var15++) {
               this.field_775[var15] = this.method_544(0, 0, class_24.method_321(), true, this.field_780.method_218(var15 == 0 ? 2 : 3));
               this.field_775[var15].method_750();
            }

            this.field_776 = new class_83[3];

            for (int var16 = 0; var16 < this.field_776.length; var16++) {
               this.field_776[var16] = this.method_544(0, 0, 19, false, this.field_780.method_218(0));
            }

            this.field_791 = new class_15(0, 0, this);
            this.field_791 = new class_15(0, 0, this);
            this.field_792 = new class_15(8, var4.field_1247 - var4.field_1248, this);
            break;
         case 21:
            this.field_779 = new class_13(new int[]{0, 0, 200000});
            this.method_536();
            this.field_776[0].field_1103.method_842(this.field_774.method_245());
            class_5 var13 = new class_5();
            class_5 var21 = new class_5();
            var13.method_169(this.field_778[0].method_746(var13));
            var21 = this.field_778[2].method_746(var21);
            var13.method_177(var21);
            var13.method_180(12288);
            var21.method_175(var13);
            this.field_776[0].field_1103.method_842(var21);
            this.field_776[0].field_1103.method_839(0, 0, -10000);
            this.field_776[0].method_750();
            this.field_775 = new class_83[3];

            for (int var23 = 0; var23 < this.field_775.length; var23++) {
               this.field_775[var23] = this.method_544(2, 0, class_24.method_321(), true, this.field_779.method_218(0));
               this.field_775[var23].method_750();
            }

            this.field_791 = new class_15(0, 0, this);
            break;
         case 23:
            class_13 var7 = new class_13(new int[]{80000, 0, 120000});
            this.field_775 = new class_83[20];
            boolean var8 = false;

            for (int var24 = 0; var24 < this.field_775.length - 2; var24++) {
               this.field_775[var24] = this.method_543(var7.method_219(), 13);
            }

            for (int var25 = this.field_775.length - 2 - 1; var25 < this.field_775.length; var25++) {
               this.field_775[var25] = this.method_544(2, 0, class_24.method_321(), true, var7.method_218(0));
            }

            this.field_791 = new class_15(7, this.field_775.length - 2, this);
            break;
         case 25:
            class_13 var9 = new class_13(new int[]{-200000, 0, -200000});
            this.field_776 = new class_83[3];

            for (int var26 = 0; var26 < this.field_776.length; var26++) {
               this.field_776[var26] = this.method_544(1, 0, var26 == 0 ? 5 : 2, false, null);
               this.field_776[var26].field_1103.method_842(this.field_774.method_245());
               this.field_776[var26].field_1103.method_866(this.field_774.field_203.field_1283);
               this.field_776[var26]
                  .field_1103
                  .method_839(
                     var26 == 0 ? 800 : (var26 == 1 ? -1000 : -30),
                     var26 == 0 ? 340 : (var26 == 1 ? -130 : -300),
                     var26 == 0 ? 700 : (var26 == 1 ? -500 : -100)
                  );
               this.field_776[var26].field_1102.method_809(32000);
            }

            this.field_776[0].field_1107 = var9;
            this.field_775 = new class_83[6];

            for (int var27 = 0; var27 < this.field_775.length; var27++) {
               this.field_775[var27] = this.method_544(0, 0, class_24.method_321(), true, null);
               this.field_775[var27].field_1103.method_866(this.field_774.field_203.field_1283);
               this.field_775[var27].field_1103.method_841(-40000 + var27 * 2000, -6000 + var27 * 2000, 10000 + var27 * 2000);
            }

            this.field_791 = new class_15(0, 0, this);
            break;
         case 27:
            this.field_779 = new class_13(new int[]{120000, 0, 130000});
            this.field_775 = new class_83[1];
            this.field_775[0] = this.method_544(1, 0, 5, true, this.field_779.method_218(0));
            this.field_775[0].method_750();
            this.field_775[0].field_1102.method_809(this.field_775[0].field_1102.field_1257 * 5);
            this.field_775[0].method_743(5);
            ((class_85)this.field_775[0]).method_759(true);
            this.field_791 = new class_15(11, 0, this);
            this.field_792 = new class_15(12, 0, this);
            break;
         case 29:
            this.field_781 = new class_13(new int[]{-30000, 0, 30000, -30000, 0, 130000, -30000, 0, 200000});
            boolean var10 = false;
            int var11 = class_24.method_321();
            this.field_775 = new class_83[5];

            for (int var41 = 0; var41 < this.field_775.length; var41++) {
               this.field_775[var41] = this.method_544(0, 0, var11, true, this.field_781.method_218(var41 < 2 ? 0 : (var41 < 3 ? 1 : 2)));
               this.field_775[var41].method_750();
            }

            this.field_776 = new class_83[5];

            for (int var42 = 0; var42 < this.field_776.length; var42++) {
               this.field_776[var42] = this.method_544(1, 3, 11, false, null);
               this.field_776[var42].field_1102.method_809(100 + class_3.method_140() * 5 + 50);
               ((class_84)this.field_776[var42]).field_1120 = true;
               this.field_776[var42].method_751();
            }

            boolean var1 = false;
            boolean var2 = false;
            boolean var3 = false;
            ((class_84)this.field_776[0]).method_757(-30000 - 7500, -1300, 20000);
            ((class_84)this.field_776[1]).method_757(-22500, 4000, 17000);
            ((class_84)this.field_776[2]).method_757(-31000, -3000, 13000);
            ((class_84)this.field_776[3]).method_757(-20000, -7000, 10000);
            ((class_84)this.field_776[4]).method_757(-29000, 8000, 8000);
            this.field_791 = new class_15(0, 0, this);
            this.field_792 = new class_15(5, 0, this);
            break;
         case 31:
            this.field_779 = new class_13(new int[]{-160000, 0, 30000});
            this.field_775 = new class_83[4];

            for (int var39 = 0; var39 < this.field_775.length; var39++) {
               this.field_775[var39] = this.method_544(0, 0, class_24.method_321(), true, this.field_779.method_218(0));
               this.field_775[var39].method_750();
               ((class_85)this.field_775[var39]).method_759(true);
            }

            this.field_776 = new class_83[2];

            for (int var40 = 0; var40 < this.field_776.length; var40++) {
               this.field_776[var40] = this.method_544(1, 0, class_24.method_321(), false, null);
               this.field_776[var40].field_1103.method_842(this.field_774.method_245());
               this.field_776[var40].field_1103.method_866(this.field_774.field_203.field_1283);
               this.field_776[var40].field_1103.method_839(var40 == 0 ? 400 : -300, var40 == 0 ? 40 : -30, var40 == 0 ? 400 : -300);
               this.field_776[var40].field_1107 = this.field_779.method_224();
               this.field_776[var40].field_1102.method_809(32000);
            }

            this.field_791 = new class_15(16, 0, this);
            this.field_792 = new class_15(17, 0, this);
            break;
         case 35:
            this.field_779 = new class_13(new int[]{20000, 0, 120000});
            this.field_775 = new class_83[3];

            for (int var38 = 0; var38 < this.field_775.length; var38++) {
               this.field_775[var38] = this.method_544(2, 0, var38 == 0 ? 10 : 0, true, this.field_779.method_218(0));
               this.field_775[var38].method_750();
            }

            this.field_775[0].field_1102.method_809(this.field_775[0].field_1102.field_1257 * 5);
            this.field_775[0].method_743(5);
            this.field_791 = new class_15(1, 0, this);
            break;
         case 42:
            this.field_781 = new class_13(new int[]{170000, 0, 0, 240000, 0, 0});
            this.field_779 = this.field_781.method_224();
            this.field_775 = new class_83[6];

            for (int var37 = 0; var37 < this.field_775.length; var37++) {
               this.field_775[var37] = this.method_544(2, 0, class_24.method_321(), true, this.field_781.method_218(var37 < 3 ? 0 : 1));
               this.field_775[var37].method_750();
            }

            this.field_791 = new class_15(0, 0, this);
            break;
         case 43:
            this.field_780 = new class_13(new int[]{150000, 0, 0, 0, 0, 0});
            this.field_775 = new class_83[8];

            for (int var34 = 0; var34 < this.field_775.length; var34++) {
               this.field_775[var34] = this.method_544(0, 0, class_24.method_321(), true, null);
            }

            this.field_776 = new class_83[7];

            for (int var35 = 0; var35 < 2; var35++) {
               this.field_776[var35] = this.method_544(1, 0, class_24.method_321(), false, null);
            }

            for (int var36 = 2; var36 < this.field_776.length; var36++) {
               this.field_776[var36] = this.method_544(3, 0, 19, false, this.field_780.method_218(0));
               this.field_776[var36].method_750();
               this.field_776[var36].field_1107 = this.field_780.method_224();
            }

            this.field_791 = new class_15(0, 0, this);
            break;
         case 45:
            this.field_780 = new class_13(new int[]{0, -60000, 0, 0, 0, 0});
            class_5 var5 = new class_5();
            class_5 var6 = new class_5();
            var5.method_169(this.field_778[0].method_746(var5));
            var6 = this.field_778[2].method_746(var6);
            var5.method_177(var6);
            var5.method_180(28672);
            var6.method_175(var5);
            this.field_776 = new class_83[7];

            for (int var30 = 0; var30 < 4; var30++) {
               this.field_776[var30] = this.method_544(1, 0, class_24.method_321(), false, null);
               if (var30 < 2) {
                  this.field_776[var30].field_1102.method_806(32000);
               }

               this.field_776[var30].field_1103.method_842(var6);
               this.field_776[var30]
                  .field_1103
                  .method_839(-3000 + class_41.field_540.nextInt(6000), -3000 + class_41.field_540.nextInt(6000), -3000 + class_41.field_540.nextInt(6000));
               this.field_776[var30].field_1103.method_863(this.field_774.field_203.method_861());
            }

            for (int var31 = 4; var31 < this.field_776.length; var31++) {
               this.field_776[var31] = this.method_544(3, 0, 19, false, this.field_780.method_218(0));
               this.field_776[var31].field_1107 = this.field_780.method_224();
            }

            this.field_775 = new class_83[12];

            for (int var32 = 0; var32 < 5; var32++) {
               this.field_775[var32] = this.method_544(0, 3, 11, true, null);
               ((class_84)this.field_775[var32]).field_1120 = false;
               ((class_84)this.field_775[var32])
                  .method_757(10000 + class_41.field_540.nextInt(20000), -10000 + class_41.field_540.nextInt(20000), 10000 + class_41.field_540.nextInt(20000));
               this.field_775[var32].field_1102.method_806(this.field_775[var32].field_1102.field_1256 * 2);
            }

            for (int var33 = 5; var33 < this.field_775.length; var33++) {
               this.field_775[var33] = this.method_544(0, 0, class_24.method_321(), true, null);
            }

            this.field_791 = new class_15(0, 0, this);
            break;
         case 47:
            this.field_776 = new class_83[5];

            for (int var12 = 0; var12 < this.field_776.length; var12++) {
               this.field_776[var12] = this.method_544(1, 0, class_24.method_321(), false, null);
               if (var12 < 2) {
                  this.field_776[var12].field_1102.method_806(32000);
               }
            }

            this.field_775 = new class_83[9];

            for (int var28 = 0; var28 < 5; var28++) {
               this.field_775[var28] = this.method_544(0, 3, 11, true, null);
               ((class_84)this.field_775[var28]).field_1120 = false;
               ((class_84)this.field_775[var28])
                  .method_757(10000 + class_41.field_540.nextInt(20000), -10000 + class_41.field_540.nextInt(20000), 10000 + class_41.field_540.nextInt(20000));
            }

            for (int var29 = 5; var29 < this.field_775.length - 1; var29++) {
               this.field_775[var29] = this.method_544(0, 0, class_24.method_321(), true, null);
            }

            this.field_775[this.field_775.length - 1] = this.method_544(0, 0, 7, true, null);
            this.field_775[this.field_775.length - 1].field_1102.method_806(32000);
            this.field_775[this.field_775.length - 1].method_743(6);
            this.field_775[this.field_775.length - 1].field_1116 = false;
            this.field_791 = new class_15(0, 0, this);
      }

      this.field_782 = this.method_546(class_3.method_73());
   }

   // $VF: renamed from: g () void
   public final void method_539() {
      switch (this.field_764) {
         case 0:
            class_90 var5 = (class_90)this.field_778[1];
            class_90 var3 = (class_90)this.field_778[2];
            this.field_780 = new class_13(
               new int[]{var5.field_1195, var5.field_1196, var5.field_1197 + 3000, var3.field_1195, var3.field_1196, var3.field_1197 + 3000, 0, 0, 6000}
            );
            this.field_780.field_183 = true;
            if (class_3.method_110().field_837 != null) {
               this.field_776 = new class_83[class_3.method_110().field_837.length];

               for (int var4 = 0; var4 < this.field_776.length; var4++) {
                  this.field_776[var4] = this.method_544(
                     class_3.method_110().method_592() ? 0 : 1, 0, class_24.field_361[class_3.method_110().field_837[var4].field_422], false, null
                  );
                  this.field_776[var4].field_1107 = this.field_780.method_224();
                  if (class_41.field_540.nextInt(2) == 0) {
                     this.field_776[var4].field_1107.method_221(0);
                  }
               }
            }
            break;
         case 1:
            class_32[] var1;
            if ((var1 = class_3.method_110().field_837) != null) {
               this.field_776 = new class_83[var1.length];

               for (int var2 = 0; var2 < var1.length; var2++) {
                  this.field_776[var2] = this.method_542(class_24.field_361[var1[var2].field_422]);
                  this.field_776[var2].field_1103.method_841(field_766[var2][0], field_766[var2][1], field_766[var2][2]);
                  this.field_776[var2].field_1103.method_841(0, 0, var2 * 50000);
               }

               return;
            }
      }
   }

   // $VF: renamed from: h () void
   public final void method_540() {
      this.field_772 = null;
      this.field_773 = null;
      int var1 = (int)(class_3.method_140() / 1.5F) + (int)(class_3.method_73() / 5.0F);
      class_19 var2 = null;
      if (this.field_775 != null) {
         class_19 var3;
         (var3 = new class_19(3 + var1, 4, -1, 3000, 500, 16.0F, null, null)).field_277 = this;
         var3.method_282(this.field_768);

         for (int var4 = 0; var4 < this.field_775.length; var4++) {
            if (this.field_775[var4].field_1104 == 19) {
               this.field_772 = new class_101[2];
            } else {
               this.field_772 = new class_101[1];
            }
         }

         class_106 var9 = new class_106(var3, class_25.method_328(class_24.field_357[8]), 1000);
         this.field_772[0] = var9;
         if (this.field_772.length == 2) {
            (var2 = new class_19(3 + var1, 6, -1, 3000, 600, 15.0F, null, null)).field_277 = this;
            var2.method_282(this.field_768);
            class_106 var5 = new class_106(var2, class_25.method_328(6767), 1000);
            this.field_772[1] = var5;
         }

         for (int var12 = 0; var12 < this.field_775.length; var12++) {
            if (!this.field_775[var12].field_1115) {
               if (this.field_775[var12].field_1104 == 19) {
                  this.field_775[var12].method_745(var2, 0);
               } else {
                  this.field_775[var12].method_745(var3, 0);
               }
            }
         }
      }

      if (this.field_776 != null) {
         class_19 var6;
         (var6 = new class_19(3 + (int)(var1 * 0.8F), 10, -1, 3000, 500, 16.0F, null, null)).field_277 = this;
         var6.method_282(this.field_768);
         var6.field_302 = true;

         for (int var10 = 0; var10 < this.field_776.length; var10++) {
            if (this.field_776[var10].field_1104 == 19) {
               this.field_773 = new class_101[2];
            } else {
               this.field_773 = new class_101[1];
            }
         }

         class_106 var11 = new class_106(var6, class_25.method_328(class_24.field_357[2]), 1000);
         this.field_773[0] = var11;
         if (this.field_773.length == 2) {
            (var2 = new class_19(5 + var1, 10, -1, 3000, 600, 15.0F, null, null)).field_277 = this;
            var2.method_282(this.field_768);
            class_106 var13 = new class_106(var2, class_25.method_328(6767), 1000);
            this.field_773[1] = var13;
         }

         for (int var14 = 0; var14 < this.field_776.length; var14++) {
            if ((!(this.field_776[var14] instanceof class_91) || this.field_776[var14].field_1115)
               && (var14 != 0 || !class_3.method_62().field_1241 || class_3.method_73() != 26)) {
               if (this.field_776[var14].field_1104 == 19) {
                  this.field_776[var14].method_745(var2, 0);
               } else {
                  this.field_776[var14].method_745(var6, 0);
               }
            }
         }
      }

      if (this.field_772 != null) {
         for (int var7 = 0; var7 < this.field_772.length; var7++) {
            this.field_772[var7].field_1294 = 2;
         }
      }

      if (this.field_773 != null) {
         for (int var8 = 0; var8 < this.field_773.length; var8++) {
            this.field_773[var8].field_1294 = 2;
         }
      }
   }

   // $VF: renamed from: i () void
   public final void method_541() {
      if (class_3.method_62().field_1226 != 6
         && class_3.method_62().field_1226 != 11
         && class_3.method_62().field_1226 != 4
         && this.field_775 != null
         && this.field_774 != null) {
         for (int var1 = 0; var1 < this.field_775.length; var1++) {
            this.field_775[var1].field_1102.method_803(this.field_774.field_202);
         }
      }

      if (this.field_775 != null && this.field_774 != null) {
         class_96[] var3 = new class_96[this.field_775.length];

         for (int var2 = 0; var2 < var3.length; var2++) {
            var3[var2] = this.field_775[var2].field_1102;
         }

         this.field_774.field_202.method_802(var3);
      }

      if (this.field_777 != null && this.field_774 != null) {
         class_96[] var4 = new class_96[this.field_777.length];

         for (int var10 = 0; var10 < var4.length; var10++) {
            var4[var10] = this.field_777[var10].field_1102;
         }

         this.field_774.field_202.method_804(var4);
      }

      if (this.field_777 != null && this.field_774 != null) {
         for (int var5 = 0; var5 < this.field_777.length; var5++) {
            this.field_777[var5].field_1102.method_803(this.field_774.field_202);
         }
      }

      if (this.field_776 != null && this.field_774 != null) {
         class_96[] var6 = new class_96[this.field_776.length];

         for (int var11 = 0; var11 < var6.length; var11++) {
            var6[var11] = this.field_776[var11].field_1102;
         }

         this.field_774.field_202.field_1254 = var6;
      }

      if (!class_3.method_62().method_789() && class_3.method_62().field_1226 == 6 && this.field_775 != null) {
         class_96[] var7;
         (var7 = new class_96[this.field_777.length + 1])[var7.length - 1] = this.field_774.field_202;

         for (int var12 = 0; var12 < var7.length - 1; var12++) {
            var7[var12] = this.field_777[var12].field_1102;
         }

         for (int var13 = 0; var13 < this.field_775.length; var13++) {
            this.field_775[var13].field_1102.method_804(var7);
         }
      }

      if (this.field_775 != null && this.field_776 != null) {
         class_96[] var8 = new class_96[this.field_776.length + 1];
         if (class_3.method_62().method_789()
            || class_3.method_62().field_1226 != 6 && class_3.method_62().field_1226 != 11 && class_3.method_62().field_1226 != 4) {
            var8[0] = this.field_774.field_202;

            for (int var15 = 1; var15 < var8.length; var15++) {
               var8[var15] = this.field_776[var15 - 1].field_1102;
            }
         } else {
            var8 = new class_96[this.field_776.length];

            for (int var14 = 0; var14 < var8.length; var14++) {
               var8[var14] = this.field_776[var14].field_1102;
            }
         }

         for (int var16 = 0; var16 < this.field_775.length; var16++) {
            this.field_775[var16].field_1102.method_804(var8);
         }
      }

      if (this.field_775 != null && this.field_776 != null) {
         class_96[] var9 = new class_96[this.field_775.length];

         for (int var17 = 0; var17 < var9.length; var17++) {
            var9[var17] = this.field_775[var17].field_1102;
         }

         for (int var18 = 0; var18 < this.field_776.length; var18++) {
            this.field_776[var18].field_1102.method_802(var9);
         }
      }
   }

   // $VF: renamed from: a (int) aw
   public final class_83 method_542(int var1) {
      Object var2 = null;
      ((class_101)(var2 = class_25.method_328(var1))).field_1294 = 2;
      return new class_90(var1, (class_101)var2, 0, 0, 0);
   }

   // $VF: renamed from: a (bj, int) aw
   public final class_83 method_543(class_87 var1, int var2) {
      int var3 = var1 != null ? var1.field_1161 : 0;
      int var4 = var1 != null ? var1.field_1162 : 0;
      int var5 = var1 != null ? var1.field_1163 : 0;
      int var6 = var3 + class_41.field_540.nextInt(20000) - 10000;
      int var7 = var4 + class_41.field_540.nextInt(20000) - 10000;
      int var8 = var5 + class_41.field_540.nextInt(20000) - 10000;
      class_101 var9;
      (var9 = class_25.method_328(var2)).field_1294 = 2;
      Object var10 = null;
      Object var11 = null;
      if (var2 == 13) {
         var10 = new class_96(1000.0F, 4, 1);
         ((class_83)(var11 = new class_93(13, true, (class_96)var10, var9, var6, var7, var8))).field_1108 = new class_8(1, 1);
         ((class_93)var11).field_1211 = this.field_770;
      } else if (var2 == 9996) {
         var10 = new class_96(1000.0F, 1, 1);
         var11 = new class_86(9996, true, (class_96)var10, var9, var6, var7, var8);
         Object var12 = null;
         ((class_83)var11).field_1108 = new class_8(1, 0);
         ((class_83)var11).field_1103.method_856(var6, var7, var8);
      }

      ((class_83)var11).field_1106 = this;
      return (class_83)var11;
   }

   // $VF: renamed from: a (int, int, int, boolean, bj) aw
   public final class_83 method_544(int var1, int var2, int var3, boolean var4, class_87 var5) {
      int var6 = var5 != null ? var5.field_1161 : 0;
      int var7 = var5 != null ? var5.field_1162 : 0;
      int var8 = var5 != null ? var5.field_1163 : 0;
      int var9 = class_41.field_540.nextInt(40000) - 20000;
      int var10 = class_41.field_540.nextInt(40000) - 20000;
      int var11 = class_41.field_540.nextInt(40000) - 20000;
      boolean var12 = false;
      if (class_3.method_62() != null && class_3.method_62().field_1226 == 6) {
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
      class_8 var20 = null;
      Object var21 = null;
      Object var22 = null;
      boolean var23 = false;
      ((class_101)(var16 = class_25.method_328(var3))).field_1294 = 2;
      class_96 var18;
      if (var3 < class_24.field_360.length) {
         int var17 = class_24.field_360[var3] + class_3.method_140() * 15 + class_3.method_73() * 4;
         var18 = new class_96(class_24.field_359[var3], var17, 1);
      } else {
         boolean var25 = false;
         var18 = new class_96(2000.0F, 20, 1);
      }

      switch (var2) {
         case 0:
            var19 = new class_85(var3, var1, var4, var18, (class_101)var16, var13, var14, var15);
            var20 = new class_8(1, var3 == 19 ? 2 : 0);
         case 1:
         case 2:
         case 4:
         default:
            break;
         case 3:
            var19 = new class_84(var3, var1, var4, var18, (class_101)var16, var13, var14, var15);
            ((Object[])(var22 = new class_36[1]))[0] = new class_37(var13, var14, var15, 0, 300, 0, 4000, 4000, 15000);
            ((class_84)var19).field_1118 = (class_36[])var22;
            var21 = new int[]{360, 186, -3370, -844, -507, 880, -449, 437, -983, 880, -275, -983, 360, 186, 4243, 0, 0, 0};
            (var20 = new class_8(((Object[])var21).length / 3, 0)).method_194((int[])var21);
            break;
         case 5:
            var19 = new class_85(var3, var1, var4, var18, (class_101)var16, var13, var14, var15);
            var20 = new class_8(1, 0);
            break;
         case 6:
            var19 = new class_85(var3, var1, var4, var18, (class_101)var16, var13 / 3, var7, var15 / 3);
            break;
         case 7:
            var19 = new class_88(var3, var4, var18, (class_101)var16, 0, 0, 0);
            var20 = new class_8(1, 0);
            var18.method_809(class_3.method_62().field_1226 == 12 ? 32 : 65);
      }

      ((class_83)var19).field_1106 = this;
      ((class_83)var19).field_1108 = var20;
      return (class_83)var19;
   }

   // $VF: renamed from: a (int) dr
   public final class_13 method_545(int var1) {
      int[] var2 = new int[var1 * 3];

      for (int var3 = 0; var3 < var2.length; var3 += 3) {
         var2[var3] = 60000 + class_41.field_540.nextInt(40000);
         var2[var3 + 1] = 0;
         if (var3 != 0) {
            var2[var3 + 2] = var2[var3 - 1 + 2] + 60000 + class_41.field_540.nextInt(40000);
         } else {
            var2[var3 + 2] = 60000 + class_41.field_540.nextInt(40000);
         }
      }

      return new class_13(var2);
   }

   // $VF: renamed from: a (int) dk[]
   public final class_31[] method_546(int var1) {
      this.field_782 = null;
      switch (var1) {
         case 5:
            this.field_782 = new class_31[5];
            this.field_782[0] = new class_31(644, 1, 5, 5000);
            this.field_782[1] = new class_31(645, 0, 6, 0);
            this.field_782[2] = new class_31(646, 1, 6, 1);
            this.field_782[3] = new class_31(647, 10, 12, 0);
            this.field_782[4] = new class_31(648, 1, 18, 0);
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
            this.field_782 = new class_31[2];
            this.field_782[0] = new class_31(766, 1, 8, 0);
            this.field_782[1] = new class_31(767, 1, 6, 1);
            break;
         case 21:
            this.field_782 = new class_31[2];
            this.field_782[0] = new class_31(788, 3, 5, 15000);
            this.field_782[1] = new class_31(789, 3, 8, 0);
            break;
         case 23:
            this.field_782 = new class_31[2];
            this.field_782[0] = new class_31(806, 2, 5, 3000);
            this.field_782[1] = new class_31(807, 2, 6, 0);
            break;
         case 25:
            this.field_782 = new class_31[4];
            this.field_782[0] = new class_31(826, 5, 5, 15000);
            this.field_782[1] = new class_31(827, 3, 6, 0);
            this.field_782[2] = new class_31(828, 3, 6, 1);
            this.field_782[3] = new class_31(829, 5, 6, 2);
            break;
         case 27:
            this.field_782 = new class_31[5];
            this.field_782[0] = new class_31(873, 3, 12, 0);
            this.field_782[1] = new class_31(874, 0, 6, 0);
            this.field_782[2] = new class_31(875, 1, 1, 0);
            this.field_782[3] = new class_31(876, 1, 14, 0);
            this.field_782[4] = new class_31(877, 1, 6, 2);
            break;
         case 29:
            this.field_782 = new class_31[2];
            this.field_782[0] = new class_31(883, 1, 5, 2000);
            this.field_782[1] = new class_31(884, 7, 6, 0);
            break;
         case 31:
            this.field_782 = new class_31[5];
            this.field_782[0] = new class_31(900, 5, 5, 2000);
            this.field_782[1] = new class_31(901, 0, 16, 0);
            this.field_782[2] = new class_31(902, 6, 6, 1);
            this.field_782[3] = new class_31(903, 4, 6, 2);
            this.field_782[4] = new class_31(904, 5, 6, 3);
            break;
         case 35:
            this.field_782 = new class_31[3];
            this.field_782[0] = new class_31(934, 1, 16, 0);
            this.field_782[1] = new class_31(935, 11, 6, 0);
            this.field_782[2] = new class_31(936, 11, 12, 0);
            break;
         case 42:
            int[] var2 = new int[]{0, 1, 2};
            int[] var3 = new int[]{3, 4, 5};
            this.field_782 = new class_31[4];
            this.field_782[0] = new class_31(971, 1, 5, 5000);
            this.field_782[1] = new class_31(972, 1, 8, var2);
            this.field_782[2] = new class_31(973, 10, 15, 0);
            this.field_782[3] = new class_31(974, 1, 8, var3);
            break;
         case 43:
            this.field_782 = new class_31[3];
            this.field_782[0] = new class_31(982, 1, 5, 60000);
            this.field_782[1] = new class_31(983, 1, 6, 0);
            this.field_782[2] = new class_31(984, 9, 6, 1);
            break;
         case 45:
            this.field_782 = new class_31[2];
            this.field_782[0] = new class_31(1004, 0, 5, 30000);
            this.field_782[1] = new class_31(1005, 1, 6, 0);
            break;
         case 47:
            this.field_782 = new class_31[25];
            this.field_782[0] = new class_31(1024, 5, 5, 30000);
            this.field_782[1] = new class_31(1025, 2, 6, 0);
            this.field_782[2] = new class_31(1026, 2, 17, this.field_775.length - 1);
            this.field_782[3] = new class_31(1027, 9, 6, 2);
            this.field_782[4] = new class_31(1028, 0, 19, this.field_775.length - 1);
            this.field_782[5] = new class_31(1029, 1, 6, 4);
            this.field_782[6] = new class_31(1030, 9, 1, this.field_775.length - 1);
            this.field_782[7] = new class_31(1031, 1, 6, 6);
            this.field_782[8] = new class_31(1032, 0, 6, 7);
            this.field_782[9] = new class_31(1033, 9, 6, 8);
            this.field_782[10] = new class_31(1034, 9, 6, 9);
            this.field_782[11] = new class_31(1035, 5, 6, 10);
            this.field_782[12] = new class_31(1036, 9, 6, 11);
            this.field_782[13] = new class_31(1037, 0, 6, 12);
            this.field_782[14] = new class_31(1038, 5, 6, 13);
            this.field_782[15] = new class_31(1039, 0, 6, 14);
            this.field_782[16] = new class_31(1040, 1, 6, 15);
            this.field_782[17] = new class_31(1041, 0, 6, 16);
            this.field_782[18] = new class_31(1042, 1, 6, 17);
            this.field_782[19] = new class_31(1043, 2, 6, 18);
            this.field_782[20] = new class_31(1044, 2, 6, 19);
            this.field_782[21] = new class_31(1045, 2, 6, 20);
            this.field_782[22] = new class_31(1046, 5, 6, 21);
            this.field_782[23] = new class_31(1047, 0, 6, 22);
            this.field_782[24] = new class_31(1048, 1, 6, 23);
      }

      return this.field_782;
   }

   // $VF: renamed from: a (int, boolean) void
   public final void method_547(int var1, boolean var2) {
      this.field_783--;
      this.field_790++;
      if (!var2 && var1 != 13) {
         class_3.method_133();
      }
   }

   // $VF: renamed from: j () void
   public final void method_548() {
      this.field_783--;
   }

   // $VF: renamed from: k () void
   public final void method_549() {
      this.field_784--;
   }

   // $VF: renamed from: l () void
   public final void method_550() {
      this.field_787--;
      this.field_788 = (int)((float)this.field_787 / class_3.method_62().field_1247 * 100.0F) + "%/" + class_3.method_62().field_1249 + "%";
   }

   // $VF: renamed from: m () void
   public final void method_551() {
      this.field_789++;
   }

   // $VF: renamed from: a (v, boolean) boolean
   public final boolean method_552(class_5 var1, boolean var2) {
      return field_765.method_403(var1.field_138, var1.field_139, var1.field_140);
   }

   // $VF: renamed from: a (v) boolean
   public final boolean method_553(class_5 var1) {
      return this.field_778 != null ? this.field_778[1].method_753(var1.field_138, var1.field_139, var1.field_140) : false;
   }

   // $VF: renamed from: b (v) boolean
   public final boolean method_554(class_5 var1) {
      return this.field_778 != null && this.field_778[0] != null && !class_3.method_77()
         ? this.field_778[0].method_753(var1.field_138, var1.field_139, var1.field_140)
         : false;
   }

   // $VF: renamed from: a (long) void
   public final void method_555(long var1) {
      class_41.field_534.setColor(this.field_800, this.field_801, this.field_802);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      class_41.field_527.method_265(this.field_767);
      if (this.field_771 != null) {
         for (int var3 = 0; var3 < this.field_771.length; var3++) {
            this.field_771[var3].method_878();
         }
      }

      if (this.field_772 != null) {
         for (int var4 = 0; var4 < this.field_772.length; var4++) {
            this.field_772[var4].method_878();
         }
      }

      if (this.field_773 != null) {
         for (int var5 = 0; var5 < this.field_773.length; var5++) {
            this.field_773[var5].method_878();
         }
      }

      if (this.field_775 != null) {
         for (int var6 = 0; var6 < this.field_775.length; var6++) {
            this.field_775[var6].method_752(var1);
            this.field_775[var6].method_756();
         }
      }

      if (this.field_776 != null) {
         for (int var7 = 0; var7 < this.field_776.length; var7++) {
            this.field_776[var7].method_752(var1);
            this.field_776[var7].method_756();
         }
      }

      if (this.field_777 != null) {
         for (int var8 = 0; var8 < this.field_777.length; var8++) {
            this.field_777[var8].method_752(var1);
            this.field_777[var8].method_756();
         }
      }

      if (this.field_778 != null) {
         for (int var9 = 0; var9 < this.field_778.length; var9++) {
            if (this.field_778[var9] != null) {
               this.field_778[var9].method_752(var1);
               this.field_778[var9].method_756();
            }
         }
      }
   }

   // $VF: renamed from: b (long) void
   public final void method_556(long var1) {
      class_41.field_534.setColor(this.field_800, this.field_801, this.field_802);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      class_41.field_527.method_265(this.field_767);
      if (this.field_771 != null) {
         for (int var3 = 0; var3 < this.field_771.length; var3++) {
            this.field_771[var3].method_878();
         }
      }

      if (this.field_772 != null) {
         for (int var4 = 0; var4 < this.field_772.length; var4++) {
            this.field_772[var4].method_878();
         }
      }

      if (this.field_773 != null) {
         for (int var5 = 0; var5 < this.field_773.length; var5++) {
            this.field_773[var5].method_878();
         }
      }

      if (this.field_775 != null) {
         for (int var6 = 0; var6 < this.field_775.length; var6++) {
            this.field_775[var6].method_756();
         }
      }

      if (this.field_776 != null) {
         for (int var7 = 0; var7 < this.field_776.length; var7++) {
            this.field_776[var7].method_756();
         }
      }

      if (this.field_777 != null) {
         for (int var8 = 0; var8 < this.field_777.length; var8++) {
            this.field_777[var8].method_756();
         }
      }

      if (this.field_778 != null) {
         for (int var9 = 0; var9 < this.field_778.length; var9++) {
            if (this.field_778[var9] != null) {
               this.field_778[var9].method_756();
            }
         }
      }
   }

   // $VF: renamed from: c (long) void
   public final void method_557(long var1) {
      if (this.field_774 != null) {
         float var3 = this.field_774.method_246();
         this.field_800 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_797 * var3))));
         this.field_801 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_798 * var3))));
         this.field_802 = class_124.method_942(0, class_124.method_943(255, class_124.method_942(0, (int)(this.field_799 * var3))));
         class_110.field_1352.setDirIntensity((int)class_124.method_944(4096.0F, 4096.0F * (var3 + 0.25F)));
         class_110.field_1352.setAmbientIntensity((int)class_124.method_944(2048.0F, 1024.0F + 1024.0F * (var3 + 0.25F)));
      }

      if (this.field_771 != null) {
         for (int var4 = 0; var4 < this.field_771.length; var4++) {
            ((class_106)this.field_771[var4]).method_885(var1);
         }
      }

      if (this.field_772 != null) {
         for (int var5 = 0; var5 < this.field_772.length; var5++) {
            ((class_106)this.field_772[var5]).method_885(var1);
         }
      }

      if (this.field_773 != null) {
         for (int var6 = 0; var6 < this.field_773.length; var6++) {
            ((class_106)this.field_773[var6]).method_885(var1);
         }
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_558(int var1) {
      return this.field_791 != null ? this.field_791.method_227(var1) : false;
   }

   // $VF: renamed from: n () void
   public final void method_559() {
      this.field_791 = null;
      this.field_792 = null;
   }

   // $VF: renamed from: b (int) boolean
   public final boolean method_560(int var1) {
      return this.field_792 != null ? this.field_792.method_227(var1) : false;
   }

   // $VF: renamed from: o () void
   public final void method_561() {
      class_25.method_331();
      class_25.method_330();
      if (this.field_778 != null) {
         for (int var1 = 0; var1 < this.field_778.length; var1++) {
            if (this.field_778[var1] != null) {
               this.field_778[var1].method_741();
               this.field_778[var1] = null;
            }
         }
      }

      this.field_778 = null;
      if (this.field_768 != null) {
         this.field_768.method_884();
      }

      this.field_768 = null;
      if (this.field_770 != null) {
         this.field_770.method_884();
      }

      this.field_770 = null;
      if (this.field_771 != null) {
         for (int var2 = 0; var2 < this.field_771.length; var2++) {
            this.field_771[var2].method_884();
         }
      }

      this.field_771 = null;
      if (this.field_772 != null) {
         for (int var3 = 0; var3 < this.field_772.length; var3++) {
            this.field_772[var3].method_884();
         }
      }

      this.field_772 = null;
      if (this.field_773 != null) {
         for (int var4 = 0; var4 < this.field_773.length; var4++) {
            this.field_773[var4].method_884();
         }
      }

      this.field_773 = null;
      if (this.field_774 != null) {
         this.field_774.method_261();
      }

      this.field_774 = null;
      if (this.field_775 != null) {
         for (int var5 = 0; var5 < this.field_775.length; var5++) {
            this.field_775[var5].method_741();
         }
      }

      this.field_775 = null;
      if (this.field_776 != null) {
         for (int var6 = 0; var6 < this.field_776.length; var6++) {
            this.field_776[var6].method_741();
         }
      }

      this.field_776 = null;
      if (this.field_779 != null) {
         this.field_779.method_217();
      }

      this.field_779 = null;
      if (this.field_780 != null) {
         this.field_780.method_217();
      }

      this.field_780 = null;
      if (this.field_781 != null) {
         this.field_781.method_217();
      }

      this.field_781 = null;
      this.field_782 = null;
      this.field_791 = null;
      this.field_792 = null;
      this.field_794 = 0;
      ;
   }
}
