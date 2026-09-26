// $VF: renamed from: cp
public final class class_9 {
   private class_9() {
   }

   // $VF: renamed from: a () aa[]
   public static final class_46[] method_199() {
      class_46[] var0;
      class_46[] var1 = new class_46[(var0 = class_24.method_315()).length];
      int var2 = 0;

      for (int var3 = 0; var3 < var0.length; var3++) {
         if (var0[var3].field_634 != null && var0[var3].field_627 <= class_3.method_110().field_833) {
            var1[var2++] = var0[var3].method_447(0);
         }
      }

      class_46[] var13 = new class_46[var2];
      System.arraycopy(var1, 0, var13, 0, var2);
      if ((var0 = class_3.method_108().field_445) != null) {
         for (int var4 = 0; var4 < var13.length; var4++) {
            byte[] var5 = var13[var4].field_634;
            if (var13[var4].field_634 != null) {
               byte[] var6 = var13[var4].field_635;
               byte[] var7 = new byte[var5.length];
               int var8 = 0;
               int var9 = Integer.MAX_VALUE;

               for (int var10 = 0; var10 < var5.length; var10++) {
                  for (int var11 = 0; var11 < var0.length; var11++) {
                     if (var0[var11].field_626 == var5[var10]) {
                        if (var0[var11].field_636 > 0) {
                           var7[var10] = (byte)(var0[var11].field_636 / var6[var10]);
                           if (var7[var10] < var9) {
                              var9 = var7[var10];
                           }
                        } else {
                           var9 = 0;
                        }

                        var8++;
                     }
                  }
               }

               if (var8 >= var5.length) {
                  var13[var4].field_636 = var9;
               }

               var13[var4].field_638 = var5.length - var8;
            }
         }
      }

      boolean var14;
      do {
         var14 = true;

         for (int var15 = 1; var15 < var13.length; var15++) {
            if ((float)var13[var15 - 1].field_634.length / var13[var15 - 1].field_638 < (float)var13[var15].field_634.length / var13[var15].field_638) {
               class_46 var16 = var13[var15 - 1];
               var13[var15 - 1] = var13[var15];
               var13[var15] = var16;
               var14 = false;
            }
         }
      } while (!var14);

      return var13;
   }

   // $VF: renamed from: a (an) void
   public static final void method_200(class_60 var0) {
      for (int var2 = 33; var2 < 36; var2++) {
         int var1;
         if (!class_46.method_450(var2, var0.field_836) && (var1 = class_41.field_540.nextInt(class_124.method_942(5, class_3.method_73() / 2))) > 0) {
            class_46 var3 = class_24.method_315()[var2].method_447(var1);
            var0.method_589(var3);
         }
      }

      class_46[] var6 = var0.field_836;
      if (var0.field_836 != null) {
         for (int var7 = 0; var7 < var6.length; var7++) {
            int var5 = var6[var7].field_636;
            int var4;
            if ((var4 = class_41.field_540.nextInt(3)) < var5) {
               var6[var7].method_444(-var4);
            }
         }
      }
   }

   // $VF: renamed from: a (an) aa[]
   public static final class_46[] method_201(class_60 var0) {
      class_46[] var2 = new class_46[0 + class_41.field_540.nextInt(5)];
      class_46[] var3 = class_24.method_315();
      byte[] var4 = class_48.method_467();

      for (int var5 = 0; var5 < var2.length; var5++) {
         boolean var6 = false;
         int var7 = 0;
         int var8 = 0;
         int var9 = 0;

         while (!var6) {
            while ((var7 = 19 + class_41.field_540.nextInt(var3.length - 19)) == 36) {
            }

            if (var7 != 37 && var7 != 38) {
               byte var10 = var4[var3[var7].field_628 * 4 + 1];
               byte var11 = var4[var3[var7].field_628 * 4 + 2];
               int var12 = var3[var7].field_627;
               boolean var13;
               if (var13 = var3[var7].field_635 != null) {
                  var8 = class_44.method_437(var0.field_829, var0.field_830, var10, var11);
               }

               if (class_41.field_540.nextInt(100) < var8 && var12 <= var0.field_833) {
                  boolean var14 = false;

                  for (int var15 = 0; var15 < var2.length; var15++) {
                     if (var3[var7].method_456(var2[var15])) {
                        var14 = true;
                        break;
                     }
                  }

                  if (!var14 && class_41.field_540.nextInt(100) <= var3[var7].field_631) {
                     var6 = true;
                  }
               }

               if (++var9 > 100) {
                  return null;
               }
            }
         }

         int var16 = 5 + class_41.field_540.nextInt(15);
         var2[var5] = var3[var7].method_447(var16);
      }

      return var2;
   }

   // $VF: renamed from: a (an) dn[]
   public static final class_51[] method_202(class_60 var0) {
      class_51[] var1 = class_24.method_311();
      boolean var3;
      class_51[] var2 = new class_51[(var3 = var0.field_831 < 0) ? 42 : 2 + class_41.field_540.nextInt(4)];

      for (int var5 = 0; var5 < var2.length; var5++) {
         int var6 = 0;
         if (var3) {
            var6 = var5;
         } else {
            boolean var7 = false;

            while (!var7) {
               var6 = class_41.field_540.nextInt(var1.length);
               boolean var8 = false;

               for (int var9 = 0; var9 < var2.length; var9++) {
                  if (var1[var6].method_507(var2[var9])) {
                     var8 = true;
                     break;
                  }
               }

               if (!var8 && var1[var6].field_713 > 0 && class_41.field_540.nextInt(100) < var1[var6].field_713 + class_3.method_73()) {
                  var7 = true;
               }
            }
         }

         var2[var5] = var1[var6].method_505();
         var2[var5].method_508(var0);
      }

      return var2;
   }

   // $VF: renamed from: a (an) be[]
   public static final class_32[] method_203(class_60 var0) {
      class_32[] var1 = class_24.method_313();
      class_32[] var2;
      boolean var3;
      int var4;
      if ((var4 = (var3 = var0.field_831 > 100) ? var1.length : class_41.field_540.nextInt(4)) == 0) {
         return null;
      } else {
         var2 = new class_32[var4];

         for (int var5 = 0; var5 < var2.length; var5++) {
            int var6 = 0;
            if (var3) {
               var6 = var5;
            } else {
               boolean var7 = false;

               while (!var7) {
                  if (((var6 = class_41.field_540.nextInt(class_24.field_361.length)) - 2) * 5 <= class_3.method_73()) {
                     var7 = true;
                  }
               }
            }

            var2[var5] = class_24.method_318(class_24.field_361[var6]).method_387();
            var2[var5].field_443 = !var0.method_592();
            var2[var5].method_389();
         }

         return var2;
      }
   }

   // $VF: renamed from: a () aa
   public static final class_46 method_204() {
      class_46[] var0 = class_24.method_315();
      boolean var1 = false;
      int var2 = 0;

      while (!var1) {
         while ((var2 = class_41.field_540.nextInt(var0.length)) == 36 || var2 == 37 || var2 == 38) {
         }

         if (class_41.field_540.nextInt(100) < var0[var2].field_631) {
            var1 = true;
         }
      }

      int var3 = var2 == 40 ? 1 : 1 + class_41.field_540.nextInt(7);
      return var0[var2].method_448(var3, var0[var2].field_633);
   }

   // $VF: renamed from: a (byte[], an) int
   private static int method_205(byte[] var0, class_60 var1) {
      int var2 = 0;
      boolean var3 = false;

      while (!var3) {
         var2 = class_124.method_942(20, class_41.field_540.nextInt(200));
         if ((
               class_41.field_540.nextInt(100) >= 70
                  || var0[var2 * 4 + 3] <= class_3.method_108().field_447 && var0[var2 * 4 + 3] >= class_3.method_108().field_446
            )
            && (
               class_41.field_540.nextInt(100) >= 100
                  || class_124.method_945(var0[var2 * 4 + 1] - var1.field_829) <= 20 + class_3.method_73()
                     && class_124.method_945(var0[var2 * 4 + 2] - var1.field_830) <= 20 + class_3.method_73()
            )) {
            var3 = true;
         }
      }

      return var2;
   }

   // $VF: renamed from: a (an) al[]
   public static final class_95[] method_206(class_60 var0) {
      byte[] var1 = class_48.method_467();
      class_95[] var2 = new class_95[1 + class_41.field_540.nextInt(8)];

      for (int var3 = 0; var3 < var2.length; var3++) {
         int var4 = 0;

         do {
            if (class_41.field_540.nextInt(100) < 40) {
               var4 = var0.field_828;
            } else {
               var4 = method_205(var1, var0);
            }
         } while (var4 <= 20);

         boolean var5 = false;
         int var6 = 0;

         while (!var5) {
            var6 = class_41.field_540.nextInt(15);
            var5 = true;
            if (var6 == 13 || var6 == 14) {
               if (var0.field_828 > 20) {
                  var4 = var0.field_828;
                  var5 = true;
               } else {
                  var5 = false;
               }
            }

            if (var0.method_592()) {
               if (var6 == 13 || var6 == 14 || var6 == 6 || var6 == 12 || var6 == 13) {
                  var5 = false;
               }
            } else {
               if (class_3.method_76() && var6 == 6 || var6 == 12 || var6 == 5 || var6 == 4) {
                  var5 = false;
               }

               if (var6 == 7 || var6 == 11) {
                  var5 = false;
               }
            }
         }

         int var7 = var0.method_592() ? 0 : 1;
         boolean var8 = class_41.field_540.nextInt(100) < 60;
         String var9 = class_24.method_320(0, var8);
         byte[] var10 = class_119.method_925(var8, var7);
         int var13 = 0;
         int var14 = 0;
         int var11;
         if (var6 != 13 && var6 != 14) {
            if (class_3.method_73() < 10) {
               var11 = 1 + class_41.field_540.nextInt(2);
            } else {
               var11 = 1 + class_41.field_540.nextInt(9);
            }
         } else {
            class_46[] var15 = class_24.method_315();
            boolean var16 = false;
            int var17 = 0;

            while (!var16) {
               do {
                  if (var6 == 13) {
                     var17 = class_24.field_358.length + 1 + class_41.field_540.nextInt(var15.length - class_24.field_358.length - 1);
                  } else {
                     var17 = class_41.field_540.nextInt(class_24.field_358.length);
                  }
               } while (var17 == 33 || var17 == 34 || var17 == 35 || var17 == 37 || var17 == 38 || var17 == 39 || var17 == 40);

               if (class_41.field_540.nextInt(100) < var15[var17].field_631) {
                  var16 = true;
               }
            }

            var14 = var17;
            if (var6 == 14) {
               var13 = 3 + class_41.field_540.nextInt(22);
            } else {
               var13 = 1 + class_41.field_540.nextInt(9);
            }

            var11 = var6 == 14 ? (int)(var13 / 25.0F * 10.0F) : var15[var17].field_627 + 2;
         }

         if (var6 != 10 && var6 != 8) {
            if (var6 == 12 || var6 == 11) {
               int var25;
               for (var25 = 100; (var6 == 12 && class_3.method_105()[var4] || var6 == 11 && !class_3.method_105()[var4]) && var25 > 0; var25--) {
                  var4 = method_205(var1, var0);
               }

               if (var25 <= 0) {
                  var6 = 3;
               }
            }
         } else {
            while (var4 == var0.field_828) {
               var4 = method_205(var1, var0);
            }
         }

         int var12 = var11 * class_124.method_943(20, class_124.method_942(1, class_3.method_140() / 2));
         int var26 = var6 != 8 ? -1 : class_41.field_540.nextInt(6) - 1;
         float var27 = 1.0F + class_44.method_439(var0, class_44.method_431(var4)) / 1500.0F;
         float var28;
         var28 = (var28 = 3500 + (int)(var12 / 200.0F * 9500.0F)) * var27;
         if (var6 == 9) {
            var28 *= 0.7F;
         } else if (var6 == 6 || var6 == 4 || var6 == 11) {
            var28 *= 1.3F;
         } else if (var6 == 12 || var6 == 7) {
            var28 *= 1.2F;
         } else if (var6 == 13) {
            var28 = var28 / 2.0F + var13 * class_24.method_315()[var14].field_633 * 3;
         } else if (var6 == 8 && var26 >= 0) {
            var28 += (int)((6 - var26) * var28 / 20.0F);
         }

         int var18 = (int)var28 % 50;
         var28 = (var28 + var18) % 50.0F == 0.0F ? var28 + var18 : var28 - var18;
         var2[var3] = new class_95(var6, var9, var10, var7, (int)var28, var4, var12, var26);
         int var19 = (int)(var28 / 10.0F + class_41.field_540.nextInt((int)var28 / 10));
         if (var6 == 13 || var6 == 14) {
            var19 = (int)(var19 * 0.5F);
         }

         var18 = var19 % 50;
         var19 = (var19 + var18) % 50 == 0 ? var19 + var18 : var19 - var18;
         var2[var3].field_1231 = var19;
         var2[var3].method_791(var14, var13);
         int var20 = 0;
         float var21 = var11 / 10.0F;
         if (var6 == 7) {
            var20 = class_41.field_540.nextInt(13);
            var2[var3].method_790(var20, 3 + (int)(var21 * 7.0F), 0);
         } else if (var6 != 6) {
            if (var6 == 11) {
               int var34;
               int var36 = (var34 = 5 + class_41.field_540.nextInt(10)) - (int)((1.0F - var21) * var34);
               var2[var3].method_790(0, var34, var36);
            } else if (var6 == 12) {
               int var35 = 3 + class_41.field_540.nextInt(3);
               var2[var3].method_790(0, var35, var35);
            }
         } else {
            while (var20 == 0 || var20 == 2 || var20 == 9 || var20 == 11 || var20 == 12) {
               var20 = class_41.field_540.nextInt(13);
            }

            int var22;
            int var23 = (var22 = 15 + class_41.field_540.nextInt(10)) - (int)((1.0F - var21) * (var22 * 0.35F));
            var2[var3].method_790(var20, var22, var23);
         }
      }

      return var2;
   }
}
