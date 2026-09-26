// $VF: renamed from: bl
public final class class_96 extends class_91 {
   // $VF: renamed from: f int
   private int field_1265 = 500;
   // $VF: renamed from: a float
   private float field_1266 = 2.1F;
   // $VF: renamed from: b float
   private float field_1267 = 2.0F;
   // $VF: renamed from: g int
   private int field_1268 = 20;
   // $VF: renamed from: a da
   private class_25 field_1269;
   // $VF: renamed from: c x
   private class_3 field_1270 = new class_3();
   // $VF: renamed from: d x
   private class_3 field_1271 = new class_3();
   // $VF: renamed from: e x
   private class_3 field_1272 = new class_3();
   // $VF: renamed from: f x
   private class_3 field_1273 = new class_3();
   // $VF: renamed from: a bn
   private static class_57 field_1274 = new class_57();
   // $VF: renamed from: h int
   private int field_1275;
   // $VF: renamed from: j boolean
   private boolean field_1276;
   // $VF: renamed from: i int
   private int field_1277;
   // $VF: renamed from: j int
   private int field_1278;
   // $VF: renamed from: k int
   private int field_1279;
   // $VF: renamed from: l int
   private int field_1280;
   // $VF: renamed from: b cm
   private class_37 field_1281;
   // $VF: renamed from: e boolean
   public boolean field_1282;
   // $VF: renamed from: a long
   private long field_1283;
   // $VF: renamed from: k boolean
   private boolean field_1284;
   // $VF: renamed from: f boolean
   public boolean field_1285;
   // $VF: renamed from: g boolean
   public boolean field_1286;
   // $VF: renamed from: a ar
   private class_83 field_1287;
   // $VF: renamed from: l boolean
   private boolean field_1288;
   // $VF: renamed from: c float
   private float field_1289;
   // $VF: renamed from: d float
   private float field_1290;
   // $VF: renamed from: a dp[]
   private class_29[] field_1291;
   // $VF: renamed from: h boolean
   public boolean field_1292;
   // $VF: renamed from: i boolean
   public boolean field_1293;
   // $VF: renamed from: e int
   public int field_1294;

   public class_96(int var1, int var2, boolean var3, class_37 var4, class_108 var5, int var6, int var7, int var8) {
      super(var1, var3, var4, var5, var6, var7, var8);
      this.field_1294 = var2;
      this.field_1271.method_10(var6, var7, var8);
      super.field_1239 = var1 != 19;
      this.field_1269 = new class_25();
      this.field_1287 = new class_83();
      this.field_1287.field_1072 = 50;
      this.field_1287.method_734(this.field_1271);
      this.field_1276 = var3 && class_21.method_143() > 15;
      if (var1 == 19) {
         var5.method_873(64);
         var5.method_877((byte)2);
         this.field_1276 = false;
         this.field_1289 = 2.1F;
         this.field_1290 = 1.5F;
      } else {
         int[] var9;
         if ((var9 = class_90.method_789(var5.field_1344, var2)) != null) {
            var5.method_876(var9[0], var9[1]);
            var5.method_877((byte)2);
         }

         this.field_1289 = this.field_1266;
         this.field_1290 = this.field_1267;
      }

      this.field_1284 = false;
      this.field_1285 = false;
      this.field_1286 = false;
      this.field_1288 = false;
      super.field_1240 = class_35.method_307();
      this.field_1293 = true;
   }

   // $VF: renamed from: a () void
   public final void method_794() {
      super.method_794();
      if (this.field_1269 != null) {
         this.field_1269.method_235();
      }

      this.field_1269 = null;
      if (this.field_1287 != null) {
         this.field_1287.method_731();
      }

      this.field_1287 = null;
      this.field_1281 = null;
      this.field_1291 = null;
   }

   // $VF: renamed from: b (boolean) void
   public final void method_814(boolean var1) {
      this.field_1284 = var1;
      if (var1) {
         super.field_1240 = null;
      }
   }

   // $VF: renamed from: c () boolean
   public final boolean method_815() {
      return this.field_1284 && !super.field_1239;
   }

   // $VF: renamed from: d () boolean
   public final boolean method_816() {
      return !super.field_1239;
   }

   // $VF: renamed from: b () void
   public final void method_817() {
      super.field_1239 = false;
      this.method_795(false);
      if (this.field_1284) {
         class_69.method_640(0, 0, false, true);
      } else if (class_21.method_178().method_612(super.field_1240.field_1490)) {
         class_21.method_152();
         class_21.method_178().method_613(super.field_1240);
         class_69.method_640(super.field_1240.field_1480, super.field_1240.field_1490, false, false);
      } else {
         class_69.method_640(super.field_1240.field_1480, super.field_1240.field_1490, true, false);
      }
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_818(int var1, int var2, int var3) {
      super.field_1234 = var1;
      super.field_1235 = var2;
      super.field_1236 = var3;
      super.field_1226.method_845(var1, var2, var3);
      this.field_1271.method_10(var1, var2, var3);
      if (this.field_1287 != null) {
         this.field_1287.method_734(this.field_1271);
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_796(int var1) {
      this.field_1276 = false;
      this.field_1266 = var1;
      this.field_1289 = this.field_1266;
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      if (super.field_1224 == 4 && !super.field_1239) {
         this.method_795(false);
      } else {
         this.field_1278 = (int)(this.field_1278 + var1);
         this.field_1277 = (int)(this.field_1277 + var1);
         this.field_1283 = var1;
         this.field_1270 = super.field_1226.method_848(this.field_1270);
         if (this.field_1269 != null) {
            super.field_1232.method_9(this.field_1270);
            if (super.field_1224 != 4 && super.field_1224 != 3) {
               super.field_1233 = super.field_1226.method_855(super.field_1233);
               super.field_1233.method_22();
               super.field_1233.method_19(32768, super.field_1233);
               super.field_1232.method_17(super.field_1233);
            }

            this.field_1269.method_236(super.field_1232, (int)var1);
            this.field_1280 = (int)(this.field_1280 + var1);
            if (this.field_1280 > 200) {
               if (this.field_1287 != null) {
                  this.field_1287.method_733(this.field_1270);
               }

               this.field_1280 = 0;
            }
         }

         super.field_1225.field_377 = super.field_1226.field_1341;
         if (super.field_1224 != 4 && super.field_1224 != 3) {
            super.field_1225.method_353(var1);
            class_37[] var3 = super.field_1225.field_360;
            if (super.field_1225.field_360 != null && this.field_1269 != null) {
               if (!this.field_1292) {
                  this.field_1275 = -1;
               } else if (this.field_1275 >= 0 && !var3[this.field_1275].field_375) {
                  this.field_1292 = false;
               }

               this.field_1281 = null;
               if (this.field_1277 > 5000) {
                  if (this.field_1288) {
                     this.field_1288 = false;
                  } else {
                     this.field_1288 = class_84.field_1123.nextInt(100) < 20;
                  }

                  this.field_1277 = 0;
                  if (class_84.field_1123.nextInt(100) < 30 && var3.length > 1) {
                     this.field_1292 = false;

                     for (int var9 = 0; var9 < 5 && !this.field_1292; var9++) {
                        this.field_1275 = class_84.field_1123.nextInt(var3.length);
                        if (var3[this.field_1275].field_375) {
                           super.field_1232 = var3[this.field_1275].method_344(super.field_1232);
                           if (this.field_1270.field_37 - super.field_1232.field_37 < 50000
                              && this.field_1270.field_37 - super.field_1232.field_37 > -50000
                              && this.field_1270.field_38 - super.field_1232.field_38 < 50000
                              && this.field_1270.field_38 - super.field_1232.field_38 > -50000
                              && this.field_1270.field_39 - super.field_1232.field_39 < 50000
                              && this.field_1270.field_39 - super.field_1232.field_39 > -50000) {
                              this.field_1292 = true;
                              break;
                           }
                        }
                     }

                     if (!this.field_1292) {
                        this.field_1275 = 0;
                     }
                  } else {
                     this.field_1275 = 0;
                  }

                  if (var3[this.field_1275].field_375 && !var3[this.field_1275].method_345()) {
                     super.field_1232 = var3[this.field_1275].method_344(super.field_1232);
                     if (this.field_1270.field_37 - super.field_1232.field_37 < 50000
                        && this.field_1270.field_37 - super.field_1232.field_37 > -50000
                        && this.field_1270.field_38 - super.field_1232.field_38 < 50000
                        && this.field_1270.field_38 - super.field_1232.field_38 > -50000
                        && this.field_1270.field_39 - super.field_1232.field_39 < 50000
                        && this.field_1270.field_39 - super.field_1232.field_39 > -50000) {
                        this.field_1275 = this.field_1275;
                     } else {
                        this.field_1275 = -1;
                     }
                  } else {
                     this.field_1275 = -1;
                  }
               } else if (!this.field_1292) {
                  for (int var4 = 0; var4 < var3.length; var4++) {
                     if (var3[var4].field_375 && !var3[var4].method_345()) {
                        super.field_1232 = var3[var4].method_344(super.field_1232);
                        if (this.field_1270.field_37 - super.field_1232.field_37 < 50000
                           && this.field_1270.field_37 - super.field_1232.field_37 > -50000
                           && this.field_1270.field_38 - super.field_1232.field_38 < 50000
                           && this.field_1270.field_38 - super.field_1232.field_38 > -50000
                           && this.field_1270.field_39 - super.field_1232.field_39 < 50000
                           && this.field_1270.field_39 - super.field_1232.field_39 > -50000) {
                           this.field_1275 = var4;
                           break;
                        }
                     }
                  }
               }

               this.field_1282 = false;
               if (this.field_1275 == -1 && super.field_1230 != null) {
                  if (super.field_1230.method_110() != null && super.field_1225.field_375) {
                     super.field_1230
                        .method_114(super.field_1225.field_377.field_698, super.field_1225.field_377.field_699, super.field_1225.field_377.field_700);
                     if (super.field_1230.method_110() != null) {
                        this.field_1272.field_37 = super.field_1230.method_110().field_1295;
                        this.field_1272.field_38 = super.field_1230.method_110().field_1296;
                        this.field_1272.field_39 = super.field_1230.method_110().field_1297;
                        this.field_1282 = true;
                     }
                  } else {
                     this.field_1275 = 0;
                     this.field_1281 = super.field_1225.method_326(this.field_1275);
                     super.field_1232 = this.field_1281.method_344(super.field_1232);
                     this.field_1272.field_37 = super.field_1232.field_37;
                     this.field_1272.field_38 = super.field_1232.field_38;
                     this.field_1272.field_39 = super.field_1232.field_39;
                  }
               } else {
                  if (this.field_1275 < 0) {
                     this.field_1275 = 0;
                  }

                  this.field_1281 = super.field_1225.method_326(this.field_1275);
                  super.field_1232 = this.field_1281.method_344(super.field_1232);
                  this.field_1272.field_37 = super.field_1232.field_37;
                  this.field_1272.field_38 = super.field_1232.field_38;
                  this.field_1272.field_39 = super.field_1232.field_39;
               }
            } else if (super.field_1230 != null) {
               super.field_1230.method_114(super.field_1225.field_377.field_698, super.field_1225.field_377.field_699, super.field_1225.field_377.field_700);
               if (super.field_1230.method_110() != null) {
                  this.field_1272.field_37 = super.field_1230.method_110().field_1295;
                  this.field_1272.field_38 = super.field_1230.method_110().field_1296;
                  this.field_1272.field_39 = super.field_1230.method_110().field_1297;
                  this.field_1282 = true;
               }
            } else {
               super.field_1224 = 5;
            }
         }

         this.field_1273.field_37 = this.field_1272.field_37 - this.field_1270.field_37;
         this.field_1273.field_38 = this.field_1272.field_38 - this.field_1270.field_38;
         this.field_1273.field_39 = this.field_1272.field_39 - this.field_1270.field_39;
         if (!super.field_1228 && super.field_1224 == 5) {
            super.field_1232 = super.field_1229.field_272.field_969.method_344(super.field_1232);
            this.field_1273.field_37 = super.field_1232.field_37 - this.field_1270.field_37;
            this.field_1273.field_38 = super.field_1232.field_38 - this.field_1270.field_38;
            this.field_1273.field_39 = super.field_1232.field_39 - this.field_1270.field_39;
            if (this.field_1273.field_37 < 10000
               && this.field_1273.field_37 > -10000
               && this.field_1273.field_38 < 10000
               && this.field_1273.field_38 > -10000
               && this.field_1273.field_39 < 10000
               && this.field_1273.field_39 > -10000) {
               super.field_1224 = 1;
               super.field_1225.field_375 = true;
            }
         }

         if (this.field_1291 != null) {
            for (int var6 = 0; var6 < this.field_1291.length; var6++) {
               this.field_1291[var6]
                  .method_286(super.field_1225.field_377.field_698, super.field_1225.field_377.field_699, super.field_1225.field_377.field_700);
            }
         }

         if (super.field_1225.field_363 <= 0 && super.field_1224 != 3 && super.field_1224 != 4) {
            if (super.field_1228) {
               if (this.field_1294 == 2 && !super.field_1225.field_383) {
                  class_21.method_206();
               }

               super.field_1229.method_257(super.field_1227, super.field_1225.field_383);
            } else {
               super.field_1229.method_259();
            }

            super.field_1224 = 3;
            if (super.field_1231 != null) {
               super.field_1231.method_741(this.field_1270.field_37, this.field_1270.field_38, this.field_1270.field_39);
            }

            int var7 = class_16.method_98(40000, this.field_1273.method_23());
            float var10 = 1.0F - var7 / 40000.0F;
            int var5 = class_84.field_1122.field_1182;
            class_84.field_1122.method_769(super.field_1227 == 19 ? 9 : 6, (int)(var5 * var10));
            if (super.field_1239) {
               this.field_1271.method_9(this.field_1270);
               super.field_1226 = class_43.method_381(17);
               super.field_1226.field_1367 = 2;
               super.field_1226.method_846(this.field_1270);
               super.field_1225.field_377 = super.field_1226.field_1341;
               super.field_1225.field_379 = this;
               this.field_1287 = null;
            }
         }

         switch (super.field_1224) {
            case 0:
               super.field_1224 = 1;
               break;
            case 1:
               if (this.field_1276) {
                  if (this.field_1278 > 5000 && this.field_1289 != 4.0F) {
                     if (class_84.field_1123.nextInt(100) < this.field_1268) {
                        this.field_1279 = class_84.field_1123.nextInt(3000) + 5000;
                     }

                     this.field_1278 = 0;
                     this.field_1289 = 4.0F;
                     this.field_1290 = 1.3F;
                  }

                  if (this.field_1289 == 4.0F && this.field_1278 > this.field_1279) {
                     this.field_1278 = 0;
                     this.field_1289 = this.field_1266;
                     this.field_1290 = this.field_1267;
                  }
               }

               if (this.field_1281 != null
                  && !this.field_1282
                  && this.field_1273.field_37 < 8000
                  && this.field_1273.field_37 > -8000
                  && this.field_1273.field_38 < 8000
                  && this.field_1273.field_38 > -8000
                  && this.field_1273.field_39 < 8000
                  && this.field_1273.field_39 > -8000) {
                  this.field_1273 = super.field_1226.method_858(this.field_1273);
               }

               this.field_1273.method_22();
               super.field_1233.method_9(this.field_1273);
               this.field_1273 = super.field_1226.method_871(field_1274).method_509(super.field_1233, this.field_1273);
               this.field_1273.field_38 = -this.field_1273.field_38;
               if (!this.field_1282
                  && this.field_1281 != null
                  && this.field_1273.field_37 < this.field_1265
                  && this.field_1273.field_37 > -this.field_1265
                  && this.field_1273.field_38 < this.field_1265
                  && this.field_1273.field_38 > -this.field_1265
                  && this.field_1272.field_37 - this.field_1270.field_37 < 35000
                  && this.field_1272.field_37 - this.field_1270.field_37 > -35000
                  && this.field_1272.field_38 - this.field_1270.field_38 < 35000
                  && this.field_1272.field_38 - this.field_1270.field_38 > -35000
                  && this.field_1272.field_39 - this.field_1270.field_39 < 35000
                  && this.field_1272.field_39 - this.field_1270.field_39 > -35000) {
                  if (this.field_1281.field_375 && !this.field_1281.method_345()) {
                     super.field_1225.method_352(0, var1, false);
                  } else {
                     this.field_1292 = false;
                  }
               }

               if (!this.field_1288) {
                  super.field_1232.method_9(super.field_1226.method_855(super.field_1232));
                  super.field_1233.method_17(super.field_1232);
                  super.field_1233.method_22();
                  super.field_1233.method_18((int)((float)var1 * this.field_1290));
                  this.field_1273 = super.field_1232.method_14(super.field_1233, this.field_1273);
                  this.field_1273.method_22();
                  super.field_1226.field_1341.method_512(this.field_1273);
               }

               super.field_1226.method_847((int)((float)var1 * this.field_1289));
            case 2:
            default:
               break;
            case 3:
               this.field_1293 = false;
               if (super.field_1231 != null) {
                  if (super.field_1231.method_743()) {
                     super.field_1224 = 4;
                  }
               } else {
                  super.field_1224 = 4;
               }
               break;
            case 4:
               if (super.field_1239 && super.field_1225.field_375) {
                  if (!super.field_1237) {
                     super.field_1226.method_843(0, -((int)var1) / 2, 0);
                  }

                  if (super.field_1226.method_848(super.field_1232).field_38 < this.field_1271.field_38 - 30000) {
                     this.field_1285 = true;
                     this.method_795(false);
                  }
               } else {
                  this.method_795(false);
               }
               break;
            case 5:
               if (super.field_1228
                  && this.field_1273.field_37 < 50000
                  && this.field_1273.field_37 > -50000
                  && this.field_1273.field_38 < 50000
                  && this.field_1273.field_38 > -50000
                  && this.field_1273.field_39 < 50000
                  && this.field_1273.field_39 > -50000) {
                  super.field_1224 = 1;
                  super.field_1225.field_375 = true;
               }
         }

         if (this.field_1293) {
            class_91[] var8 = super.field_1229.field_276;
            if (super.field_1229.field_276 != null) {
               for (int var11 = 0; var11 < var8.length; var11++) {
                  if (var8[var11] != null && var8[var11].method_807(super.field_1226.method_848(super.field_1233))) {
                     super.field_1233 = var8[var11].method_808(super.field_1226.method_848(super.field_1233));
                     if (super.field_1233 != null) {
                        super.field_1232.method_9(super.field_1226.method_855(super.field_1232));
                        super.field_1233.method_17(super.field_1232);
                        super.field_1233.method_18((int)((float)var1 * 5.0F));
                        this.field_1270 = super.field_1232.method_14(super.field_1233, this.field_1270);
                        this.field_1270.method_22();
                        super.field_1226.field_1341.method_512(this.field_1270);
                        super.field_1226.method_847((int)((float)var1 * this.field_1289));
                     }
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (super.field_1224 != 4 && super.field_1224 != 3 || super.field_1239 && super.field_1225.field_375) {
         super.method_809();
         if (this.field_1269 != null) {
            this.field_1269.method_238();
         }

         if (this.field_1287 != null) {
            this.field_1287.method_735();
         }
      }

      if (super.field_1224 == 3 && super.field_1231.method_740() > 1) {
         super.method_809();
      }

      if (super.field_1224 == 3 && super.field_1231 != null) {
         super.field_1231.method_742(this.field_1283);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      if (super.field_1224 != 4 && super.field_1224 != 3) {
         if (this.field_1291 != null) {
            for (int var4 = 0; var4 < this.field_1291.length; var4++) {
               if (this.field_1291[var4].method_287(var1, var2, var3)) {
                  return true;
               }
            }
         }

         return false;
      } else {
         return false;
      }
   }
}
