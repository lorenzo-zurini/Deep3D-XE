// $VF: renamed from: cf
public final class class_84 extends class_83 {
   // $VF: renamed from: a dp[]
   public class_36[] field_1118;
   // $VF: renamed from: a long
   private long field_1119;
   // $VF: renamed from: e boolean
   public boolean field_1120;
   // $VF: renamed from: c v
   private class_5 field_1121 = new class_5();
   // $VF: renamed from: d v
   private class_5 field_1122 = new class_5();
   // $VF: renamed from: e v
   private class_5 field_1123 = new class_5();
   // $VF: renamed from: f v
   private class_5 field_1124 = new class_5();
   // $VF: renamed from: g v
   private class_5 field_1125 = new class_5();
   // $VF: renamed from: b cm
   private class_96 field_1126;
   // $VF: renamed from: b ay
   private class_101 field_1127;
   // $VF: renamed from: f boolean
   private boolean field_1128;
   // $VF: renamed from: e int
   private int field_1129;

   public class_84(int var1, int var2, boolean var3, class_96 var4, class_101 var5, int var6, int var7, int var8) {
      super(var1, var3, var4, var5, var6, var7, var8);
      super.field_1102.field_1270 = var5.field_1283;
      this.field_1121.method_170(var6, var7, var8);
      this.field_1120 = false;
      this.field_1127 = (class_101)var5.method_836();
      int[] var9;
      if ((var9 = class_24.method_319(var5.field_1286, var2)) != null) {
         var5.method_872(var9[0], var9[1]);
         var5.method_873((byte)2);
      }
   }

   // $VF: renamed from: a () void
   public final void method_741() {
      super.method_741();
      this.field_1118 = null;
      this.field_1126 = null;
      this.field_1121 = null;
      this.field_1122 = null;
      this.field_1123 = null;
      this.field_1124 = null;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_757(int var1, int var2, int var3) {
      super.field_1111 = var1;
      super.field_1112 = var2;
      super.field_1113 = var3;
      super.field_1103.method_841(var1, var2, var3);
      super.field_1102.field_1270 = super.field_1103.field_1283;
      this.field_1121.method_170(var1, var2, var3);
      this.field_1122.method_170(var1, var2, var3);
      if (this.field_1118 != null) {
         for (int var4 = 0; var4 < this.field_1118.length; var4++) {
            this.field_1118[var4].method_402(super.field_1102.field_1270.field_13, super.field_1102.field_1270.field_14, super.field_1102.field_1270.field_15);
         }
      }
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_746(class_5 var1) {
      return super.field_1103.method_844(var1);
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      this.field_1119 = var1;
      super.field_1102.method_832(var1);
      if (this.field_1120 && super.field_1101 != 3 && super.field_1101 != 4) {
         super.field_1103.method_843((int)var1);
         super.field_1102.field_1270 = super.field_1103.field_1283;
         if (this.field_1118 != null) {
            for (int var3 = 0; var3 < this.field_1118.length; var3++) {
               this.field_1118[var3]
                  .method_402(super.field_1102.field_1270.field_13, super.field_1102.field_1270.field_14, super.field_1102.field_1270.field_15);
            }
         }
      }

      super.field_1109 = class_41.field_527.field_249.method_845(super.field_1109);
      super.field_1110.method_170(super.field_1103.method_848(), super.field_1103.method_849(), super.field_1103.method_850());
      super.field_1110.method_176(super.field_1109, this.field_1125);
      int var6;
      if ((var6 = this.field_1125.method_183()) > org.deep3d.Config.impostorDistance()) {
         this.field_1127.method_866(super.field_1103.field_1283);
         this.field_1125.method_182();
         this.field_1125.method_178(org.deep3d.Config.impostorDistance());
         this.field_1125.method_175(super.field_1109);
         this.field_1127.method_842(this.field_1125);
         int var4 = (int)((float)org.deep3d.Config.impostorDistance() / var6 * 4096.0F);
         this.field_1127.method_865(var4, var4, var4);
         this.field_1128 = true;
      } else {
         this.field_1127.method_865(4096, 4096, 4096);
         this.field_1127.method_841(super.field_1103.method_848(), super.field_1103.method_849(), super.field_1103.method_850());
         this.field_1128 = false;
      }

      if (super.field_1102.field_1256 <= 0 && super.field_1101 != 3 && super.field_1101 != 4) {
         super.field_1102.field_1268 = false;
         if (super.field_1105) {
            super.field_1106.method_547(super.field_1104, super.field_1102.field_1276);
         } else {
            super.field_1106.method_549();
         }

         super.field_1101 = 3;
         if (super.field_1108 != null) {
            super.field_1110 = super.field_1103.method_845(super.field_1110);
            super.field_1108.method_196(super.field_1110.field_138, super.field_1110.field_139, super.field_1110.field_140);
         }
      }

      switch (super.field_1101) {
         case 3:
            if (super.field_1108 != null) {
               if (super.field_1108.method_198()) {
                  super.field_1101 = 4;
                  return;
               }
            } else {
               super.field_1101 = 4;
            }
         case 4:
         default:
            break;
         case 5:
            if (super.field_1101 != 4 && super.field_1101 != 3) {
               class_96[] var7 = super.field_1102.field_1253;
               if (super.field_1102.field_1253 != null) {
                  this.field_1126 = null;

                  for (int var5 = 0; var5 < var7.length; var5++) {
                     if (var7[var5].field_1268) {
                        super.field_1109 = var7[var5].method_823(super.field_1109);
                        if (this.field_1121.field_138 - super.field_1109.field_138 < 50000
                           && this.field_1121.field_138 - super.field_1109.field_138 > -50000
                           && this.field_1121.field_139 - super.field_1109.field_139 < 50000
                           && this.field_1121.field_139 - super.field_1109.field_139 > -50000
                           && this.field_1121.field_140 - super.field_1109.field_140 < 50000
                           && this.field_1121.field_140 - super.field_1109.field_140 > -50000) {
                           this.field_1126 = super.field_1102.method_805(var5);
                           super.field_1109 = this.field_1126.method_823(super.field_1109);
                           this.field_1123.field_138 = super.field_1109.field_138;
                           this.field_1123.field_139 = super.field_1109.field_139;
                           this.field_1123.field_140 = super.field_1109.field_140;
                           break;
                        }
                     }
                  }
               }
            }

            this.field_1124.field_138 = this.field_1123.field_138 - this.field_1121.field_138;
            this.field_1124.field_139 = this.field_1123.field_139 - this.field_1121.field_139;
            this.field_1124.field_140 = this.field_1123.field_140 - this.field_1121.field_140;
            if (this.field_1124.field_138 < 50000
               && this.field_1124.field_138 > -50000
               && this.field_1124.field_139 < 50000
               && this.field_1124.field_139 > -50000
               && this.field_1124.field_140 < 50000
               && this.field_1124.field_140 > -50000) {
               super.field_1101 = 1;
               super.field_1102.field_1268 = true;
               return;
            }
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (super.field_1101 != 4) {
         class_41.field_527.method_265(this.field_1128 ? this.field_1127 : super.field_1103);
         boolean var1 = false;
         if (super.field_1101 == 3 && super.field_1108 != null) {
            super.field_1108.method_197(this.field_1119);
         }
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      if (super.field_1101 != 4 && super.field_1101 != 4) {
         for (int var4 = 0; var4 < this.field_1118.length; var4++) {
            if (this.field_1118[var4].method_403(var1, var2, var3)) {
               return true;
            }
         }

         return false;
      } else {
         return false;
      }
   }

   // $VF: renamed from: b (v) v
   public final class_5 method_755(class_5 var1) {
      return this.field_1118 != null ? this.field_1118[this.field_1129].method_401(var1) : null;
   }

   // $VF: renamed from: a (v) boolean
   public final boolean method_754(class_5 var1) {
      return this.method_758(var1.field_138, var1.field_139, var1.field_140);
   }

   // $VF: renamed from: b (int, int, int) boolean
   public final boolean method_758(int var1, int var2, int var3) {
      if (super.field_1101 == 4) {
         return false;
      } else {
         for (int var4 = 0; var4 < this.field_1118.length; var4++) {
            if (this.field_1118[var4].method_404(var1, var2, var3)) {
               this.field_1129 = var4;
               return true;
            }
         }

         return false;
      }
   }

   static {
      int[][] var10000 = new int[][]{{0, 1700, 6061}, {0, 1995, -6212}, {805, 1779, 927}, {-805, 1779, 927}};
      var10000 = new int[][]{{-680, -78, 3602}, {680, -78, 3602}, {-3119, 1157, -1937}, {3119, 1157, -1937}, {-2127, -1364, -812}, {2127, -1364, -812}};
      class_5[] var1 = new class_5[]{new class_5(0, 0, 4096), new class_5(0, 0, -4096), new class_5(4096, 0, 0), new class_5(-4096, 0, 0)};
      class_5[] var2 = new class_5[]{
         new class_5(0, 0, 4096), new class_5(0, 0, 4096), new class_5(0, 4096, 0), new class_5(0, 4096, 0), new class_5(0, -4096, 0), new class_5(0, -4096, 0)
      };
   }
}
