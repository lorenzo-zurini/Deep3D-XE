// $VF: renamed from: ah
public final class class_101 extends class_91 {
   // $VF: renamed from: c x
   private static class_3 field_1311 = new class_3();
   // $VF: renamed from: a cj
   public class_40 field_1312;
   // $VF: renamed from: f int
   private int field_1313;
   // $VF: renamed from: g int
   private int field_1314;
   // $VF: renamed from: h int
   private int field_1315;
   // $VF: renamed from: i int
   private int field_1316;
   // $VF: renamed from: b ax
   private class_108 field_1317;
   // $VF: renamed from: a int[]
   private static int[] field_1318 = new int[3];
   // $VF: renamed from: b int[]
   private static int[] field_1319 = new int[3];
   // $VF: renamed from: d x
   private static class_3 field_1320 = new class_3();
   // $VF: renamed from: e x
   private static class_3 field_1321 = new class_3();
   // $VF: renamed from: a bn
   private static class_57 field_1322 = new class_57();
   // $VF: renamed from: b bn
   private class_57 field_1323 = new class_57();
   // $VF: renamed from: g boolean
   private boolean field_1324 = false;
   // $VF: renamed from: h boolean
   private boolean field_1325 = false;
   // $VF: renamed from: e boolean
   public boolean field_1326 = false;
   // $VF: renamed from: j int
   private int field_1327;
   // $VF: renamed from: a float
   private float field_1328;
   // $VF: renamed from: k int
   private int field_1329;
   // $VF: renamed from: i boolean
   private boolean field_1330;
   // $VF: renamed from: j boolean
   private boolean field_1331;
   // $VF: renamed from: e int
   public int field_1332;
   // $VF: renamed from: f boolean
   public boolean field_1333;
   // $VF: renamed from: l int
   private int field_1334;

   public class_101(int var1, class_108 var2, class_40 var3, int var4, int var5, int var6) {
      super(var1, false, new class_37(1500.0F, var3.field_392 * 2, 0), var2, var4, var5, var6);
      super.field_1225.field_379 = this;
      var2.deep3dNoCull = true; // Deep3D-PC: ships are never culled
      this.field_1312 = var3;
      this.field_1331 = var1 == 4444 || var1 == 4445 || var1 == 4443 || var1 == 4446 || var1 == 4447;
      if (this.field_1331) {
         var2.method_864(256, 0, 0);
         this.field_1332 = var3.field_392;
      } else {
         this.field_1332 = class_16.method_97(1, var3.field_392 + (int)((-25 + class_84.field_1123.nextInt(50)) / 100.0F * var3.field_392));
      }

      this.field_1328 = 1.0F + var3.field_393 / 2.2F;
      this.field_1315 = 2100 + (int)(var3.field_393 / 10.0F * 2100.0F);
      super.field_1224 = 0;
      this.field_1327 = super.field_1225.field_363;
      if (var4 == 0 && var5 == 0 && var6 == 0) {
         field_1321.method_10(-4096 + class_84.field_1123.nextInt(8192), -4096 + class_84.field_1123.nextInt(8192), -4096 + class_84.field_1123.nextInt(8192));
         field_1321.method_22();
         super.field_1226.field_1341.method_512(field_1321);
         field_1320.method_10(
            -30000 + class_84.field_1123.nextInt(59000), -30000 + class_84.field_1123.nextInt(59000), -30000 + class_84.field_1123.nextInt(59000)
         );
      } else {
         field_1320.method_10(
            var4 - 8000 + class_84.field_1123.nextInt(16000),
            var5 - 8000 + class_84.field_1123.nextInt(16000),
            var6 - 8000 + class_84.field_1123.nextInt(16000)
         );
      }

      super.field_1226.method_846(field_1320);
      super.field_1235 = field_1320.field_38;
      if (var1 == 4424 || var1 == 4427 || var1 == 4430 || var1 == 4432 || var1 == 4434 || var1 == 4440 || var1 == 4436 || var1 == 4438) {
         this.field_1317 = class_43.method_381(var1 + 1);
         this.field_1317.field_1367 = 2;
         this.field_1317.deep3dNoCull = true; // Deep3D-PC
         this.field_1317.method_870(super.field_1226.field_1341);
      }

      super.field_1238 = true;
      super.field_1239 = true;
      this.method_831();
      this.field_1330 = false;
      this.field_1333 = false;
   }

   // $VF: renamed from: b (boolean) void
   public final void method_829(boolean var1) {
      this.field_1330 = var1;
      if (var1) {
         field_1321.method_10(0, 0, 4096);
         super.field_1226.field_1341.method_512(field_1321);
      }

      this.method_805(-1024 + class_84.field_1123.nextInt(2048));
      super.field_1225.method_327(10);
      this.field_1327 = super.field_1225.field_363;
   }

   // $VF: renamed from: b (int) void
   public final void method_830(int var1) {
      this.field_1324 = true;
      this.field_1325 = true;
      this.field_1314 = 0;
      this.field_1328 = 1.0F + this.field_1312.field_393 / 2.2F;
      this.field_1328 *= 1.0F - var1 / 100.0F;
   }

   // $VF: renamed from: b () void
   public final void method_831() {
      this.field_1316 = this.field_1331 ? 0 : this.field_1315;
      this.field_1314 = 0;
      this.field_1324 = false;
      this.field_1325 = false;
   }

   // $VF: renamed from: a () int
   public final int method_832() {
      return this.field_1316 / 1000 + 1;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_833() {
      if (super.field_1224 == 4 || super.field_1224 != 4 && class_21.method_178().method_612(this.field_1332)) {
         this.method_795(false);
         super.field_1239 = false;
         super.field_1226.method_869(0, 0, 0);
         if (super.field_1224 != 4) {
            if (class_21.method_132().field_1146 == 7) {
               if (this.field_1312.field_391 == class_21.method_132().field_1166) {
                  super.field_1229.method_260();
               }
            } else {
               super.field_1229.method_260();
            }
         }
      }

      if (super.field_1224 == 4) {
         class_120 var1 = class_90.method_785()[18].method_929(this.field_1332);
         if (class_21.method_178().method_612(var1.field_1490)) {
            class_21.method_166(this.field_1332);
            class_21.method_178().method_613(var1);
            class_69.method_640(var1.field_1480, var1.field_1490, false, false);
         } else {
            class_69.method_640(var1.field_1480, var1.field_1490, true, false);
         }

         this.field_1333 = false;
      } else {
         if (this.field_1317 != null) {
            this.field_1317.method_870(super.field_1226.field_1341);
         }

         if (!class_21.method_178().method_612(this.field_1332)) {
            class_69.method_640(this.field_1312.field_391, this.field_1332, true, false);
            super.field_1226.method_869(4096, 4096, 4096);
            if (this.field_1317 != null) {
               this.field_1317.method_870(super.field_1226.field_1341);
            }

            this.field_1325 = false;
            this.field_1326 = false;
            return false;
         }

         class_21.method_178().method_613(class_90.method_785()[this.field_1312.field_391].method_929(this.field_1332));
         class_69.method_640(this.field_1312.field_391, this.field_1332, false, false);
         class_21.method_164(this.field_1312.field_391);
      }

      return true;
   }

   // $VF: renamed from: c (int) void
   public final void method_834(int var1) {
      super.field_1226.method_869(var1, var1, var1);
      if (this.field_1317 != null) {
         this.field_1317.method_870(super.field_1226.field_1341);
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      this.field_1334 = (int)var1;
      if (super.field_1225.field_375 && !this.field_1326) {
         if (!this.field_1331) {
            this.field_1329 = (int)var1;
            if (this.field_1327 > super.field_1225.field_363 && super.field_1224 != 4) {
               this.field_1324 = true;
            }

            this.field_1327 = super.field_1225.field_363;
         }

         if (this.field_1324) {
            this.field_1328 += 0.01F;
            this.field_1314 = (int)(this.field_1314 + var1);
            this.field_1329 = (int)((float)var1 * this.field_1328);
            var1 <<= 1;
            if (this.field_1314 < 2000) {
               super.field_1226.field_1341.method_472(this.field_1323);
            } else {
               this.field_1316 = this.field_1316 - (this.field_1314 >> 1);
               if (!this.field_1330) {
                  int var3 = this.field_1329 >> 1;
                  this.field_1323.method_491(-(var3 >> 1) + class_84.field_1123.nextInt(var3), -(var3 >> 1) + class_84.field_1123.nextInt(var3), 0);
               }

               this.field_1314 = 0;
            }

            if (this.field_1316 <= 0) {
               if (this.field_1325) {
                  this.field_1326 = true;
                  class_69.method_634(0, 0, "");
               } else {
                  this.method_831();
               }
            }
         }

         if (!this.field_1331 && super.field_1225.field_363 <= 0 && super.field_1224 != 4) {
            field_1320 = super.field_1226.method_848(field_1320);
            if (super.field_1239) {
               super.field_1226 = class_43.method_381(14);
               super.field_1226.field_1367 = 2;
               super.field_1226.method_846(field_1320);
               this.field_1317 = null;
               super.field_1225.field_377 = super.field_1226.field_1341;
               super.field_1225.field_379 = this;
               this.field_1333 = true;
               this.field_1332 = this.field_1332 / 3 + 1;
            }

            field_1320.method_17(super.field_1229.field_272.method_664());
            int var6 = class_16.method_98(40000, field_1320.method_23());
            float var4 = 1.0F - var6 / 40000.0F;
            int var5 = class_84.field_1122.field_1182;
            class_84.field_1122.method_769(9, (int)(var5 * var4));
            super.field_1231.method_741(super.field_1226.method_852(), super.field_1226.method_853(), super.field_1226.method_854());
            class_21.method_207();
            super.field_1224 = 4;
            if (class_21.method_132().field_1146 == 7) {
               if (this.field_1312.field_391 == class_21.method_132().field_1166) {
                  super.field_1229.method_260();
                  return;
               }
            } else {
               super.field_1229.method_260();
            }
         } else if (super.field_1224 == 4) {
            if (!this.field_1325) {
               super.field_1226.method_843(0, (int)var1 / 3, 0);
            }

            if (this.field_1317 != null) {
               this.field_1317.method_870(super.field_1226.field_1341);
            }

            if (this.method_835()) {
               this.method_795(false);
            }
         } else {
            if (!this.field_1331 && super.field_1227 != 4429) {
               super.field_1226.method_847(this.field_1329);
               this.field_1313 = (int)(this.field_1313 + var1);
               this.field_1313 &= 4095;
            }

            switch (super.field_1227) {
               case 4422:
                  super.field_1226.method_869(4096, class_16.method_91(this.field_1313) / 3, 4096);
                  break;
               case 4423:
                  field_1322.method_491(0, class_16.method_91(this.field_1313) >> 7, 0);
                  super.field_1226.field_1341.method_472(field_1322);
                  break;
               case 4424:
                  this.field_1317.method_870(super.field_1226.field_1341);
                  this.field_1317.method_868(4096, 4096, 4096 + (class_16.method_91(this.field_1313 << 2) >> 2));
               case 4425:
               case 4428:
               case 4429:
               case 4431:
               case 4433:
               case 4435:
               case 4437:
               case 4439:
               case 4441:
               default:
                  break;
               case 4426:
                  super.field_1226.method_869(4096, 4096 + (class_16.method_91(this.field_1313 << 1) >> 2), 4096);
                  break;
               case 4427:
               case 4432:
               case 4436:
                  this.field_1317.method_870(super.field_1226.field_1341);
                  field_1322.method_491(-(class_16.method_91(this.field_1313) >> 6), 0, 0);
                  this.field_1317.field_1341.method_472(field_1322);
                  field_1322.method_491(class_16.method_91(this.field_1313) >> 8, 0, 0);
                  super.field_1226.field_1341.method_472(field_1322);
                  break;
               case 4430:
               case 4434:
               case 4440:
                  this.field_1317.method_870(super.field_1226.field_1341);
                  field_1322.method_491(0, class_16.method_91(this.field_1313) >> 5, 0);
                  this.field_1317.field_1341.method_472(field_1322);
                  field_1322.method_491(0, -(class_16.method_91(this.field_1313) >> 7), 0);
                  super.field_1226.field_1341.method_472(field_1322);
                  break;
               case 4438:
                  this.field_1317.method_870(super.field_1226.field_1341);
                  this.field_1317.method_869(4096, 4096 + (class_16.method_91(this.field_1313 << 2) >> 2), 4096);
                  break;
               case 4442:
                  super.field_1226.method_869(4096, 4096, 4096 + (class_16.method_91(this.field_1313 << 2) >> 2));
            }

            if (!this.field_1330 && this.method_835()) {
               this.method_836();
            }
         }
      }
   }

   // $VF: renamed from: d () boolean
   private boolean method_835() {
      super.field_1232 = class_84.field_1110.field_40.method_849(super.field_1232);
      super.field_1233 = super.field_1232.method_16(super.field_1226.method_848(field_1311), super.field_1233);
      return super.field_1233.method_23() > 40000;
   }

   // $VF: renamed from: g () void
   private void method_836() {
      for (int var1 = 0; var1 < field_1318.length; var1++) {
         field_1318[var1] = -2048 + class_84.field_1123.nextInt(4096);
      }

      field_1320.method_10(field_1318[0], field_1318[1] >> 1, field_1318[2]);
      field_1320.method_22();
      field_1318[0] = field_1320.field_37;
      field_1318[1] = field_1320.field_38;
      field_1318[2] = field_1320.field_39;
      field_1320.method_18(30000);
      field_1320.method_15(class_84.field_1110.field_40.method_848(super.field_1233));
      super.field_1226.method_846(field_1320);

      for (int var2 = 0; var2 < field_1319.length; var2++) {
         field_1319[var2] = -15000 + class_84.field_1123.nextInt(30000);
         field_1319[var2] = field_1319[var2] - field_1318[var2];
      }

      field_1321.method_10(field_1319[0], field_1319[1], field_1319[2]);
      field_1321.method_22();
      super.field_1226.field_1341.method_512(field_1321);
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (this.field_1317 != null) {
         class_84.field_1110.method_25(this.field_1317);
      }

      class_84.field_1110.method_25(super.field_1226);
      if (super.field_1224 == 4 && super.field_1231 != null && !super.field_1231.method_743()) {
         super.field_1231.method_742(this.field_1334);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      return false;
   }
}
