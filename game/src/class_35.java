// $VF: renamed from: cp
public final class class_35 {
   private class_35() {
   }

   // $VF: renamed from: a () ac[]
   public static final class_120[] method_302() {
      class_120[] var0;
      class_120[] var1 = new class_120[(var0 = class_90.method_785()).length];
      int var2 = 0;

      for (int var3 = 0; var3 < var0.length; var3++) {
         if (var0[var3].field_1488 != null && var0[var3].field_1481 <= class_21.method_180().field_1139) {
            var1[var2++] = var0[var3].method_929(0);
         }
      }

      class_120[] var13 = new class_120[var2];
      System.arraycopy(var1, 0, var13, 0, var2);
      if ((var0 = class_21.method_178().field_886) != null) {
         for (int var4 = 0; var4 < var13.length; var4++) {
            byte[] var5 = var13[var4].field_1488;
            if (var13[var4].field_1488 != null) {
               byte[] var6 = var13[var4].field_1489;
               byte[] var7 = new byte[var5.length];
               int var8 = 0;
               int var9 = Integer.MAX_VALUE;

               for (int var10 = 0; var10 < var5.length; var10++) {
                  for (int var11 = 0; var11 < var0.length; var11++) {
                     if (var0[var11].field_1480 == var5[var10]) {
                        if (var0[var11].field_1490 > 0) {
                           var7[var10] = (byte)(var0[var11].field_1490 / var6[var10]);
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
                  var13[var4].field_1490 = var9;
               }

               var13[var4].field_1492 = var5.length - var8;
            }
         }
      }

      boolean var14;
      do {
         var14 = true;

         for (int var15 = 1; var15 < var13.length; var15++) {
            if ((float)var13[var15 - 1].field_1488.length / var13[var15 - 1].field_1492 < (float)var13[var15].field_1488.length / var13[var15].field_1492) {
               class_120 var16 = var13[var15 - 1];
               var13[var15 - 1] = var13[var15];
               var13[var15] = var16;
               var14 = false;
            }
         }
      } while (!var14);

      return var13;
   }

   // $VF: renamed from: a (ao) void
   public static final void method_303(class_86 var0) {
      for (int var2 = 33; var2 < 36; var2++) {
         int var1;
         if (!class_120.method_932(var2, var0.field_1142) && (var1 = class_84.field_1123.nextInt(class_16.method_97(5, class_21.method_143() / 2))) > 0) {
            class_120 var3 = class_90.method_785()[var2].method_929(var1);
            var0.method_749(var3);
         }
      }

      class_120[] var6 = var0.field_1142;
      if (var0.field_1142 != null) {
         for (int var7 = 0; var7 < var6.length; var7++) {
            int var5 = var6[var7].field_1490;
            int var4;
            if ((var4 = class_84.field_1123.nextInt(3)) < var5) {
               var6[var7].method_926(-var4);
            }
         }
      }
   }

   // $VF: renamed from: a (ao) ac[]
   public static final class_120[] method_304(class_86 var0) {
      class_120[] var2 = new class_120[0 + class_84.field_1123.nextInt(5)];
      class_120[] var3 = class_90.method_785();
      byte[] var4 = class_49.method_404();

      for (int var5 = 0; var5 < var2.length; var5++) {
         boolean var6 = false;
         int var7 = 0;
         int var8 = 0;
         int var9 = 0;

         while (!var6) {
            while ((var7 = 19 + class_84.field_1123.nextInt(var3.length - 19)) == 36) {
            }

            if (var7 != 37 && var7 != 38) {
               int var10 = var4[var3[var7].field_1482 * 4 + 1];
               int var11 = var4[var3[var7].field_1482 * 4 + 2];
               int var12 = var3[var7].field_1481;
               boolean var13;
               if (var13 = var3[var7].field_1489 != null) {
                  var8 = class_38.method_360(var0.field_1135, var0.field_1136, var10, var11);
               }

               if (class_84.field_1123.nextInt(100) < var8 && var12 <= var0.field_1139) {
                  boolean var14 = false;

                  for (int var15 = 0; var15 < var2.length; var15++) {
                     if (var3[var7].method_938(var2[var15])) {
                        var14 = true;
                        break;
                     }
                  }

                  if (!var14 && class_84.field_1123.nextInt(100) <= var3[var7].field_1485) {
                     var6 = true;
                  }
               }

               if (++var9 > 100) {
                  return null;
               }
            }
         }

         int var16 = 5 + class_84.field_1123.nextInt(15);
         var2[var5] = var3[var7].method_929(var16);
      }

      return var2;
   }

   // $VF: renamed from: a (ao) dn[]
   public static final class_19[] method_305(class_86 var0) {
      class_19[] var1 = class_90.method_781();
      class_19[] var2 = null;
      boolean var3;
      var2 = new class_19[(var3 = var0.field_1137 < 0) ? 42 : 2 + class_84.field_1123.nextInt(4)];

      for (int var5 = 0; var5 < var2.length; var5++) {
         int var6 = 0;
         if (var3) {
            var6 = var5;
         } else {
            boolean var7 = false;

            while (!var7) {
               var6 = class_84.field_1123.nextInt(var1.length);
               boolean var8 = false;

               for (int var9 = 0; var9 < var2.length; var9++) {
                  if (var1[var6].method_122(var2[var9])) {
                     var8 = true;
                     break;
                  }
               }

               if (!var8 && var1[var6].field_168 > 0 && class_84.field_1123.nextInt(100) < var1[var6].field_168 + class_21.method_143()) {
                  var7 = true;
               }
            }
         }

         var2[var5] = var1[var6].method_120();
         var2[var5].method_123(var0);
      }

      return var2;
   }

   // $VF: renamed from: a (ao) bd[]
   public static final class_68[] method_306(class_86 var0) {
      class_68[] var1 = class_90.method_783();
      class_68[] var2 = null;
      boolean var3;
      int var4;
      if ((var4 = (var3 = var0.field_1137 > 100) ? var1.length : class_84.field_1123.nextInt(4)) == 0) {
         return null;
      } else {
         var2 = new class_68[var4];

         for (int var5 = 0; var5 < var2.length; var5++) {
            int var6 = 0;
            if (var3) {
               var6 = var5;
            } else {
               boolean var7 = false;

               while (!var7) {
                  if (((var6 = class_84.field_1123.nextInt(class_90.field_1205.length)) - 2) * 5 <= class_21.method_143()) {
                     var7 = true;
                  }
               }
            }

            var2[var5] = class_90.method_788(class_90.field_1205[var6]).method_627();
            var2[var5].field_884 = !var0.method_752();
            var2[var5].method_629();
         }

         return var2;
      }
   }

   // $VF: renamed from: a () ac
   public static final class_120 method_307() {
      class_120[] var0 = class_90.method_785();
      boolean var1 = false;
      int var2 = 0;

      while (!var1) {
         while ((var2 = class_84.field_1123.nextInt(var0.length)) == 36 || var2 == 37 || var2 == 38) {
         }

         if (class_84.field_1123.nextInt(100) < var0[var2].field_1485) {
            var1 = true;
         }
      }

      int var3 = var2 == 40 ? 1 : 1 + class_84.field_1123.nextInt(7);
      return var0[var2].method_930(var3, var0[var2].field_1487);
   }

   // $VF: renamed from: a (byte[], ao) int
   private static int method_308(byte[] var0, class_86 var1) {
      int var2 = 0;
      boolean var3 = false;

      while (!var3) {
         var2 = class_16.method_97(20, class_84.field_1123.nextInt(200));
         if ((
               class_84.field_1123.nextInt(100) >= 70
                  || var0[var2 * 4 + 3] <= class_21.method_178().field_888 && var0[var2 * 4 + 3] >= class_21.method_178().field_887
            )
            && (
               class_84.field_1123.nextInt(100) >= 100
                  || class_16.method_100(var0[var2 * 4 + 1] - var1.field_1135) <= 20 + class_21.method_143()
                     && class_16.method_100(var0[var2 * 4 + 2] - var1.field_1136) <= 20 + class_21.method_143()
            )) {
            var3 = true;
         }
      }

      return var2;
   }

   // $VF: renamed from: a (ao) am[]
   public static final class_87[] method_309(class_86 var0) {
      byte[] var1 = class_49.method_404();
      class_87[] var2 = new class_87[1 + class_84.field_1123.nextInt(8)];

      for (int var3 = 0; var3 < var2.length; var3++) {
         int var4 = 0;

         do {
            if (class_84.field_1123.nextInt(100) < 40) {
               var4 = var0.field_1134;
            } else {
               var4 = method_308(var1, var0);
            }
         } while (var4 <= 20);

         boolean var5 = false;
         int var6 = 0;

         while (!var5) {
            var6 = class_84.field_1123.nextInt(15);
            var5 = true;
            if (var6 == 13 || var6 == 14) {
               if (var0.field_1134 > 20) {
                  var4 = var0.field_1134;
                  var5 = true;
               } else {
                  var5 = false;
               }
            }

            if (var0.method_752()) {
               if (var6 == 13 || var6 == 14 || var6 == 6 || var6 == 12 || var6 == 13) {
                  var5 = false;
               }
            } else {
               if (class_21.method_146() && var6 == 6 || var6 == 12 || var6 == 5 || var6 == 4) {
                  var5 = false;
               }

               if (var6 == 7 || var6 == 11) {
                  var5 = false;
               }
            }
         }

         int var7 = var0.method_752() ? 0 : 1;
         boolean var8 = class_84.field_1123.nextInt(100) < 60;
         String var9 = class_90.method_790(0, var8);
         byte[] var10 = class_119.method_920(var8, var7);
         int var13 = 0;
         int var14 = 0;
         int var11;
         if (var6 != 13 && var6 != 14) {
            if (class_21.method_143() < 10) {
               var11 = 1 + class_84.field_1123.nextInt(2);
            } else {
               var11 = 1 + class_84.field_1123.nextInt(9);
            }
         } else {
            class_120[] var15 = class_90.method_785();
            boolean var16 = false;
            int var17 = 0;

            while (!var16) {
               do {
                  if (var6 == 13) {
                     var17 = class_90.field_1202.length + 1 + class_84.field_1123.nextInt(var15.length - class_90.field_1202.length - 1);
                  } else {
                     var17 = class_84.field_1123.nextInt(class_90.field_1202.length);
                  }
               } while (var17 == 33 || var17 == 34 || var17 == 35 || var17 == 37 || var17 == 38 || var17 == 39 || var17 == 40);

               if (class_84.field_1123.nextInt(100) < var15[var17].field_1485) {
                  var16 = true;
               }
            }

            var14 = var17;
            if (var6 == 14) {
               var13 = 3 + class_84.field_1123.nextInt(22);
            } else {
               var13 = 1 + class_84.field_1123.nextInt(9);
            }

            var11 = var6 == 14 ? (int)(var13 / 25.0F * 10.0F) : var15[var17].field_1481 + 2;
         }

         if (var6 != 10 && var6 != 8) {
            if (var6 == 12 || var6 == 11) {
               int var25;
               for (var25 = 100; (var6 == 12 && class_21.method_175()[var4] || var6 == 11 && !class_21.method_175()[var4]) && var25 > 0; var25--) {
                  var4 = method_308(var1, var0);
               }

               if (var25 <= 0) {
                  var6 = 3;
               }
            }
         } else {
            while (var4 == var0.field_1134) {
               var4 = method_308(var1, var0);
            }
         }

         int var12 = var11 * class_16.method_98(20, class_16.method_97(1, class_21.method_210() / 2));
         int var26 = var6 != 8 ? -1 : class_84.field_1123.nextInt(6) - 1;
         float var27 = 1.0F + class_38.method_362(var0, class_38.method_354(var4)) / 1500.0F;
         float var28;
         var28 = (var28 = 3500 + (int)(var12 / 200.0F * 9500.0F)) * var27;
         if (var6 == 9) {
            var28 *= 0.7F;
         } else if (var6 == 6 || var6 == 4 || var6 == 11) {
            var28 *= 1.3F;
         } else if (var6 == 12 || var6 == 7) {
            var28 *= 1.2F;
         } else if (var6 == 13) {
            var28 = var28 / 2.0F + var13 * class_90.method_785()[var14].field_1487 * 3;
         } else if (var6 == 8 && var26 >= 0) {
            var28 += (int)((6 - var26) * var28 / 20.0F);
         }

         int var18 = (int)var28 % 50;
         var28 = (var28 + var18) % 50.0F == 0.0F ? var28 + var18 : var28 - var18;
         var2[var3] = new class_87(var6, var9, var10, var7, (int)var28, var4, var12, var26);
         int var19 = (int)(var28 / 10.0F + class_84.field_1123.nextInt((int)var28 / 10));
         if (var6 == 13 || var6 == 14) {
            var19 = (int)(var19 * 0.5F);
         }

         var18 = var19 % 50;
         var19 = (var19 + var18) % 50 == 0 ? var19 + var18 : var19 - var18;
         var2[var3].field_1151 = var19;
         var2[var3].method_756(var14, var13);
         int var20 = 0;
         float var21 = var11 / 10.0F;
         if (var6 == 7) {
            var20 = class_84.field_1123.nextInt(13);
            var2[var3].method_755(var20, 3 + (int)(var21 * 7.0F), 0);
         } else if (var6 != 6) {
            if (var6 == 11) {
               int var34;
               int var36 = (var34 = 5 + class_84.field_1123.nextInt(10)) - (int)((1.0F - var21) * var34);
               var2[var3].method_755(0, var34, var36);
            } else if (var6 == 12) {
               int var35 = 3 + class_84.field_1123.nextInt(3);
               var2[var3].method_755(0, var35, var35);
            }
         } else {
            while (var20 == 0 || var20 == 2 || var20 == 9 || var20 == 11 || var20 == 12) {
               var20 = class_84.field_1123.nextInt(13);
            }

            int var22;
            int var23 = (var22 = 15 + class_84.field_1123.nextInt(10)) - (int)((1.0F - var21) * (var22 * 0.35F));
            var2[var3].method_755(var20, var22, var23);
         }
      }

      return var2;
   }
}
