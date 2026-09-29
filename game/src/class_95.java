// $VF: renamed from: cf
public final class class_95 extends class_91 {
   // $VF: renamed from: a dp[]
   public class_29[] field_1253;
   // $VF: renamed from: a long
   private long field_1254;
   // $VF: renamed from: e boolean
   public boolean field_1255;
   // $VF: renamed from: c x
   private class_3 field_1256 = new class_3();
   // $VF: renamed from: d x
   private class_3 field_1257 = new class_3();
   // $VF: renamed from: e x
   private class_3 field_1258 = new class_3();
   // $VF: renamed from: f x
   private class_3 field_1259 = new class_3();
   // $VF: renamed from: g x
   private class_3 field_1260 = new class_3();
   // $VF: renamed from: b cm
   private class_37 field_1261;
   // $VF: renamed from: b ax
   private class_108 field_1262;
   // $VF: renamed from: f boolean
   private boolean field_1263;
   // $VF: renamed from: e int
   private int field_1264;

   public class_95(int var1, int var2, boolean var3, class_37 var4, class_108 var5, int var6, int var7, int var8) {
      super(var1, var3, var4, var5, var6, var7, var8);
      super.field_1225.field_377 = var5.field_1341;
      this.field_1256.method_10(var6, var7, var8);
      this.field_1255 = false;
      this.field_1262 = (class_108)var5.method_840();
      int[] var9;
      if ((var9 = class_90.method_789(var5.field_1344, var2)) != null) {
         var5.method_876(var9[0], var9[1]);
         var5.method_877((byte)2);
      }
   }

   // $VF: renamed from: a () void
   public final void method_794() {
      super.method_794();
      this.field_1253 = null;
      this.field_1261 = null;
      this.field_1256 = null;
      this.field_1257 = null;
      this.field_1258 = null;
      this.field_1259 = null;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_812(int var1, int var2, int var3) {
      super.field_1234 = var1;
      super.field_1235 = var2;
      super.field_1236 = var3;
      super.field_1226.method_845(var1, var2, var3);
      super.field_1225.field_377 = super.field_1226.field_1341;
      this.field_1256.method_10(var1, var2, var3);
      this.field_1257.method_10(var1, var2, var3);
      if (this.field_1253 != null) {
         for (int var4 = 0; var4 < this.field_1253.length; var4++) {
            this.field_1253[var4].method_286(super.field_1225.field_377.field_698, super.field_1225.field_377.field_699, super.field_1225.field_377.field_700);
         }
      }
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_799(class_3 var1) {
      return super.field_1226.method_848(var1);
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      this.field_1254 = var1;
      super.field_1225.method_353(var1);
      if (this.field_1255 && super.field_1224 != 3 && super.field_1224 != 4) {
         super.field_1226.method_847((int)var1);
         super.field_1225.field_377 = super.field_1226.field_1341;
         if (this.field_1253 != null) {
            for (int var3 = 0; var3 < this.field_1253.length; var3++) {
               this.field_1253[var3]
                  .method_286(super.field_1225.field_377.field_698, super.field_1225.field_377.field_699, super.field_1225.field_377.field_700);
            }
         }
      }

      super.field_1232 = class_84.field_1110.field_40.method_849(super.field_1232);
      super.field_1233.method_10(super.field_1226.method_852(), super.field_1226.method_853(), super.field_1226.method_854());
      super.field_1233.method_16(super.field_1232, this.field_1260);
      // Deep3D-PC: always full detail. The phone swapped distant structures for
      // scaled-down stand-ins kept inside its short far plane; the far plane now
      // reaches them (class_64).
      this.field_1262.method_869(4096, 4096, 4096);
      this.field_1262.method_845(super.field_1226.method_852(), super.field_1226.method_853(), super.field_1226.method_854());
      this.field_1263 = false;

      if (super.field_1225.field_363 <= 0 && super.field_1224 != 3 && super.field_1224 != 4) {
         super.field_1225.field_375 = false;
         if (super.field_1228) {
            super.field_1229.method_257(super.field_1227, super.field_1225.field_383);
         } else {
            super.field_1229.method_259();
         }

         super.field_1224 = 3;
         if (super.field_1231 != null) {
            super.field_1233 = super.field_1226.method_849(super.field_1233);
            super.field_1231.method_741(super.field_1233.field_37, super.field_1233.field_38, super.field_1233.field_39);
         }
      }

      switch (super.field_1224) {
         case 3:
            if (super.field_1231 != null) {
               if (super.field_1231.method_743()) {
                  super.field_1224 = 4;
                  return;
               }
            } else {
               super.field_1224 = 4;
            }
         case 4:
         default:
            break;
         case 5:
            if (super.field_1224 != 4 && super.field_1224 != 3) {
               class_37[] var7 = super.field_1225.field_360;
               if (super.field_1225.field_360 != null) {
                  this.field_1261 = null;

                  for (int var5 = 0; var5 < var7.length; var5++) {
                     if (var7[var5].field_375) {
                        super.field_1232 = var7[var5].method_344(super.field_1232);
                        if (this.field_1256.field_37 - super.field_1232.field_37 < 50000
                           && this.field_1256.field_37 - super.field_1232.field_37 > -50000
                           && this.field_1256.field_38 - super.field_1232.field_38 < 50000
                           && this.field_1256.field_38 - super.field_1232.field_38 > -50000
                           && this.field_1256.field_39 - super.field_1232.field_39 < 50000
                           && this.field_1256.field_39 - super.field_1232.field_39 > -50000) {
                           this.field_1261 = super.field_1225.method_326(var5);
                           super.field_1232 = this.field_1261.method_344(super.field_1232);
                           this.field_1258.field_37 = super.field_1232.field_37;
                           this.field_1258.field_38 = super.field_1232.field_38;
                           this.field_1258.field_39 = super.field_1232.field_39;
                           break;
                        }
                     }
                  }
               }
            }

            this.field_1259.field_37 = this.field_1258.field_37 - this.field_1256.field_37;
            this.field_1259.field_38 = this.field_1258.field_38 - this.field_1256.field_38;
            this.field_1259.field_39 = this.field_1258.field_39 - this.field_1256.field_39;
            if (this.field_1259.field_37 < 50000
               && this.field_1259.field_37 > -50000
               && this.field_1259.field_38 < 50000
               && this.field_1259.field_38 > -50000
               && this.field_1259.field_39 < 50000
               && this.field_1259.field_39 > -50000) {
               super.field_1224 = 1;
               super.field_1225.field_375 = true;
               return;
            }
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (super.field_1224 != 4) {
         class_4.deep3dStructure = true; // Deep3D-PC
         class_84.field_1110.method_25(this.field_1263 ? this.field_1262 : super.field_1226);
         class_4.deep3dStructure = false; // Deep3D-PC
         boolean var1 = false;
         if (super.field_1224 == 3 && super.field_1231 != null) {
            super.field_1231.method_742(this.field_1254);
         }
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      if (super.field_1224 != 4 && super.field_1224 != 4) {
         for (int var4 = 0; var4 < this.field_1253.length; var4++) {
            if (this.field_1253[var4].method_287(var1, var2, var3)) {
               return true;
            }
         }

         return false;
      } else {
         return false;
      }
   }

   // $VF: renamed from: b (x) x
   public final class_3 method_808(class_3 var1) {
      return this.field_1253 != null ? this.field_1253[this.field_1264].method_285(var1) : null;
   }

   // $VF: renamed from: a (x) boolean
   public final boolean method_807(class_3 var1) {
      return this.method_813(var1.field_37, var1.field_38, var1.field_39);
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_813(int var1, int var2, int var3) {
      if (super.field_1224 == 4) {
         return false;
      } else {
         for (int var4 = 0; var4 < this.field_1253.length; var4++) {
            if (this.field_1253[var4].method_288(var1, var2, var3)) {
               this.field_1264 = var4;
               return true;
            }
         }

         return false;
      }
   }

   static {
      int[][] var10000 = new int[][]{{0, 1700, 6061}, {0, 1995, -6212}, {805, 1779, 927}, {-805, 1779, 927}};
      var10000 = new int[][]{{-680, -78, 3602}, {680, -78, 3602}, {-3119, 1157, -1937}, {3119, 1157, -1937}, {-2127, -1364, -812}, {2127, -1364, -812}};
      class_3[] var1 = new class_3[]{new class_3(0, 0, 4096), new class_3(0, 0, -4096), new class_3(4096, 0, 0), new class_3(-4096, 0, 0)};
      class_3[] var2 = new class_3[]{
         new class_3(0, 0, 4096), new class_3(0, 0, 4096), new class_3(0, 4096, 0), new class_3(0, 4096, 0), new class_3(0, -4096, 0), new class_3(0, -4096, 0)
      };
   }
}
