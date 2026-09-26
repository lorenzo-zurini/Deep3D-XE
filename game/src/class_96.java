// $VF: renamed from: cm
public final class class_96 {
   // $VF: renamed from: a o[][]
   public class_19[][] field_1252;
   // $VF: renamed from: a cm[]
   public class_96[] field_1253;
   // $VF: renamed from: b cm[]
   public class_96[] field_1254;
   // $VF: renamed from: a float
   public float field_1255;
   // $VF: renamed from: a int
   public int field_1256;
   // $VF: renamed from: b int
   public int field_1257;
   // $VF: renamed from: c int
   public int field_1258;
   // $VF: renamed from: k int
   private int field_1259;
   // $VF: renamed from: d int
   public int field_1260;
   // $VF: renamed from: l int
   private int field_1261;
   // $VF: renamed from: e int
   public int field_1262;
   // $VF: renamed from: f int
   public int field_1263;
   // $VF: renamed from: g int
   public int field_1264;
   // $VF: renamed from: h int
   public int field_1265;
   // $VF: renamed from: a int[]
   private int[] field_1266;
   // $VF: renamed from: m int
   private int field_1267;
   // $VF: renamed from: a boolean
   public boolean field_1268;
   // $VF: renamed from: d boolean
   private boolean field_1269;
   // $VF: renamed from: a bn
   public class_1 field_1270;
   // $VF: renamed from: a v
   private class_5 field_1271 = new class_5();
   // $VF: renamed from: a aw
   public class_83 field_1272;
   // $VF: renamed from: b boolean
   public boolean field_1273;
   // $VF: renamed from: i int
   public int field_1274;
   // $VF: renamed from: j int
   public int field_1275;
   // $VF: renamed from: c boolean
   public boolean field_1276;

   public class_96(float var1, int var2, int var3) {
      this.field_1255 = var1;
      this.field_1256 = var2;
      this.field_1257 = var2;
      this.method_815();
      this.field_1262 = var3;
      if (var3 > 0) {
         this.field_1252 = new class_19[var3][];
      }

      this.field_1270 = new class_1();
      this.field_1268 = true;
      this.field_1269 = true;
      this.field_1266 = new int[6];
      this.field_1266[0] = 1000000;
      this.field_1272 = null;
      this.field_1273 = false;
      this.field_1276 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_800() {
      return this.field_1272 != null ? this.field_1272.field_1115 : false;
   }

   // $VF: renamed from: a (int) void
   public final void method_801(int var1) {
      this.field_1255 = var1;
   }

   // $VF: renamed from: a (cm[]) void
   public final void method_802(class_96[] var1) {
      this.field_1253 = var1;
      if (this.field_1252 != null) {
         for (int var2 = 0; var2 < this.field_1252.length; var2++) {
            if (this.field_1252[var2] != null) {
               for (int var3 = 0; var3 < this.field_1252[var2].length; var3++) {
                  if (this.field_1252[var2][var3] != null) {
                     this.field_1252[var2][var3].field_278 = this.field_1253;
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: a (cm) void
   public final void method_803(class_96 var1) {
      class_96[] var2;
      (var2 = new class_96[1])[0] = var1;
      this.method_802(var2);
   }

   // $VF: renamed from: b (cm[]) void
   public final void method_804(class_96[] var1) {
      if (this.field_1253 == null) {
         this.method_802(var1);
      } else {
         class_96[] var2 = new class_96[this.field_1253.length + var1.length];

         for (int var3 = 0; var3 < this.field_1253.length; var3++) {
            var2[var3] = this.field_1253[var3];
         }

         for (int var4 = 0; var4 < var1.length; var4++) {
            var2[this.field_1253.length + var4] = var1[var4];
         }

         this.method_802(var2);
      }
   }

   // $VF: renamed from: a (int) cm
   public final class_96 method_805(int var1) {
      return this.field_1253[var1];
   }

   // $VF: renamed from: b (int) void
   public final void method_806(int var1) {
      this.field_1256 = var1;
      if (this.field_1256 > this.field_1257) {
         this.field_1257 = this.field_1256;
      }

      this.method_815();
   }

   // $VF: renamed from: c (int) void
   public final void method_807(int var1) {
      this.field_1258 = var1;
      if (this.field_1258 > this.field_1259) {
         this.field_1258 = this.field_1259;
      }

      this.method_815();
   }

   // $VF: renamed from: d (int) void
   public final void method_808(int var1) {
      this.field_1260 = var1;
      if (this.field_1260 > this.field_1261) {
         this.field_1260 = this.field_1261;
      }

      this.method_815();
   }

   // $VF: renamed from: e (int) void
   public final void method_809(int var1) {
      this.field_1257 = var1;
      this.field_1256 = var1;
      this.method_815();
   }

   // $VF: renamed from: f (int) void
   public final void method_810(int var1) {
      this.field_1259 = var1;
      this.field_1258 = var1;
      this.method_815();
   }

   // $VF: renamed from: g (int) void
   public final void method_811(int var1) {
      this.field_1261 = var1;
      this.field_1260 = var1;
      this.method_815();
   }

   // $VF: renamed from: a () int
   public final int method_812() {
      return this.field_1258 + this.field_1260 + this.field_1256;
   }

   // $VF: renamed from: a () void
   public final void method_813() {
      if (this.field_1258 + 1 < this.field_1259) {
         this.field_1258++;
      } else {
         this.field_1258 = this.field_1259;
      }

      this.method_815();
   }

   // $VF: renamed from: b () void
   public final void method_814() {
      if (this.field_1256 + 1 < this.field_1257) {
         this.field_1256++;
      } else {
         this.field_1256 = this.field_1257;
      }

      this.method_815();
   }

   // $VF: renamed from: d () void
   private void method_815() {
      this.field_1263 = (int)((float)this.field_1256 / this.field_1257 * 100.0F);
      this.field_1264 = (int)((float)this.field_1258 / this.field_1259 * 100.0F);
      this.field_1265 = (int)((float)this.field_1260 / this.field_1261 * 100.0F);
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_816(int var1, int var2, int var3) {
      this.field_1271.field_138 = var1;
      this.field_1271.field_139 = var2;
      this.field_1271.field_140 = var3;
   }

   // $VF: renamed from: a (int) float
   public final float method_817(int var1) {
      if (this.field_1252 != null) {
         Object var2 = null;
         if (var1 == this.field_1275) {
            var2 = this.field_1252[var1][this.field_1274];
         } else {
            var2 = this.field_1252[var1][0];
         }

         if (var2 != null) {
            return (float)((class_19)var2).field_291 / ((class_19)var2).field_292;
         }
      }

      return 0.0F;
   }

   // $VF: renamed from: h (int) void
   public final void method_818(int var1) {
      if (this.field_1269 && this.field_1268) {
         if (this.field_1260 <= 0) {
            this.method_820(var1);
         } else {
            this.field_1260 -= var1;
         }

         if (this.field_1260 < 0) {
            this.field_1260 = 0;
         }

         this.method_815();
      }
   }

   // $VF: renamed from: i (int) void
   public final void method_819(int var1) {
      if (this.field_1269 && this.field_1268) {
         if (this.field_1258 <= 0) {
            this.method_820(var1);
         } else {
            this.field_1258 -= var1;
         }

         if (this.field_1258 < 0) {
            this.field_1258 = 0;
         }

         this.method_815();
      }
   }

   // $VF: renamed from: j (int) void
   public final void method_820(int var1) {
      this.field_1256 -= var1;
      if (this.field_1256 < 0) {
         this.field_1256 = 0;
      }
   }

   // $VF: renamed from: a (int, boolean) void
   public final void method_821(int var1, boolean var2) {
      if (this.field_1269 && this.field_1268) {
         int var3;
         if ((var3 = this.field_1258 - var1) < 0) {
            this.field_1258 = 0;
            int var4;
            if ((var4 = this.field_1260 - -var3) < 0) {
               this.field_1260 = 0;
               this.field_1256 -= -var4;
            } else {
               this.field_1260 = var4;
            }
         } else {
            this.field_1258 = var3;
         }

         if (this.field_1256 < 0) {
            this.field_1256 = 0;
            if (var2) {
               this.field_1276 = true;
            }
         }

         this.method_815();
      }
   }

   // $VF: renamed from: k (int) void
   public final void method_822(int var1) {
      this.method_821(var1, false);
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_823(class_5 var1) {
      return this.field_1270.method_12(var1);
   }

   // $VF: renamed from: b () boolean
   public final boolean method_824() {
      return this.field_1256 <= 0;
   }

   // $VF: renamed from: a (o, int) void
   public final void method_825(class_19 var1, int var2) {
      if (this.field_1252 != null) {
         if (var2 <= this.field_1262 && var2 >= 0) {
            this.field_1252[var2] = new class_19[1];
            this.field_1252[var2][0] = var1;
         }

         this.method_827();
      }
   }

   // $VF: renamed from: a (o[], int) void
   public final void method_826(class_19[] var1, int var2) {
      if (this.field_1252 != null) {
         if (var2 <= this.field_1262 && var2 >= 0) {
            this.field_1252[var2] = new class_19[var1.length];
            this.field_1252[var2] = var1;
         }

         this.method_827();
      }
   }

   // $VF: renamed from: e () void
   private void method_827() {
      int var1 = 0;
      this.field_1274 = 0;
      if (this.field_1252 != null) {
         for (int var2 = 0; var2 < this.field_1252.length; var2++) {
            if (this.field_1252[var2] != null) {
               for (int var3 = 0; var3 < this.field_1252[var2].length; var3++) {
                  if (this.field_1252[var2][var3].field_292 > var1 && !this.field_1252[var2][var3].field_298) {
                     var1 = this.field_1252[var2][var3].field_292;
                     this.field_1275 = var2;
                     this.field_1274 = var3;
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_828() {
      this.field_1262 = 0;
      this.field_1252 = (class_19[][])null;
   }

   // $VF: renamed from: a (int) int
   public final int method_829(int var1) {
      return this.field_1252[var1][0].field_301;
   }

   // $VF: renamed from: l (int) void
   public final void method_830(int var1) {
      if (this.field_1252 != null && var1 < this.field_1252.length && var1 >= 0 && this.field_1252[var1] != null) {
         for (int var2 = 0; var2 < this.field_1252[var1].length; var2++) {
            this.field_1252[var1][var2].field_291 = 0;
         }
      }
   }

   // $VF: renamed from: a (int, long, boolean) void
   public final void method_831(int var1, long var2, boolean var4) {
      if (this.field_1252 != null && var1 < this.field_1252.length && var1 >= 0 && this.field_1252[var1] != null) {
         for (int var5 = 0; var5 < this.field_1252[var1].length; var5++) {
            if (this.field_1252[var1][var5].field_291 > this.field_1252[var1][var5].field_292
               && this.field_1252[var1][var5].method_284(this.field_1270, var2, var4)) {
               this.field_1252[var1][var5].field_291 = 0;
               if (this.field_1273 && this.field_1252[var1][var5].field_298) {
                  class_41.field_539.method_427(5);
               }
            }
         }
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_832(long var1) {
      this.field_1267 = (int)(this.field_1267 + var1);
      if (this.field_1267 > 3000) {
         this.field_1267 = 0;
      }
   }
}
