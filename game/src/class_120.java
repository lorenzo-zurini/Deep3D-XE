// $VF: renamed from: ac
public final class class_120 {
   // $VF: renamed from: a int
   public int field_1480;
   // $VF: renamed from: b int
   public int field_1481;
   // $VF: renamed from: c int
   public int field_1482;
   // $VF: renamed from: d int
   public int field_1483;
   // $VF: renamed from: e int
   public int field_1484;
   // $VF: renamed from: f int
   public int field_1485;
   // $VF: renamed from: g int
   public int field_1486;
   // $VF: renamed from: h int
   public int field_1487;
   // $VF: renamed from: a byte[]
   public byte[] field_1488;
   // $VF: renamed from: b byte[]
   public byte[] field_1489;
   // $VF: renamed from: i int
   public int field_1490;
   // $VF: renamed from: j int
   public int field_1491;
   // $VF: renamed from: k int
   public int field_1492;

   public class_120(int var1, int var2, int var3, int var4, int var5, int var6, int var7, byte[] var8, byte[] var9) {
      this.field_1480 = var1;
      this.field_1481 = var2;
      this.field_1482 = var3;
      this.field_1483 = var4;
      this.field_1485 = var5;
      this.field_1486 = var6;
      this.field_1487 = var7;
      this.field_1488 = var8;
      this.field_1489 = var9;
      this.field_1484 = var6 + (var7 - var6) / 2;
      this.field_1492 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_924() {
      return this.field_1484 * this.field_1490;
   }

   // $VF: renamed from: a () float
   public final float method_925() {
      return (float)(this.field_1484 - this.field_1486) / (this.field_1487 - this.field_1486);
   }

   // $VF: renamed from: a (int) void
   public final void method_926(int var1) {
      this.field_1490 += var1;
   }

   // $VF: renamed from: b (int) void
   public final void method_927(int var1) {
      this.field_1491 += var1;
   }

   // $VF: renamed from: a (boolean, int) int
   public final int method_928(boolean var1, int var2) {
      if (var1 && this.field_1491 > 0 && class_21.method_182() >= this.field_1484 && var2 < class_21.method_178().method_607()) {
         this.method_927(-1);
         this.method_926(1);
         return -this.field_1484;
      } else if (!var1 && this.field_1490 > 0) {
         this.method_926(-1);
         this.method_927(1);
         return this.field_1484;
      } else {
         return 0;
      }
   }

   // $VF: renamed from: a (int) ac
   public final class_120 method_929(int var1) {
      return this.method_930(var1, this.field_1484);
   }

   // $VF: renamed from: a (int, int) ac
   public final class_120 method_930(int var1, int var2) {
      class_120 var3;
      (var3 = this.method_937()).field_1484 = var2;
      var3.field_1490 = var1;
      return var3;
   }

   // $VF: renamed from: a (int, int, ac[]) boolean
   public static final boolean method_931(int var0, int var1, class_120[] var2) {
      if (var2 == null) {
         return false;
      } else {
         for (int var3 = 0; var3 < var2.length; var3++) {
            if (var2[var3].field_1480 == var0 && var2[var3].field_1490 >= var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (int, ac[]) boolean
   public static final boolean method_932(int var0, class_120[] var1) {
      return method_931(var0, 1, var1);
   }

   // $VF: renamed from: a (ac, ac[], int) ac[]
   public static final class_120[] method_933(class_120 var0, class_120[] var1, int var2) {
      byte[] var3 = var0.field_1488;
      byte[] var4 = var0.field_1489;

      for (int var5 = 0; var5 < var3.length; var5++) {
         for (int var6 = 0; var6 < var1.length; var6++) {
            if (var1[var6].field_1480 == var3[var5]) {
               var1[var6].method_926(-var4[var5] * var2);
               break;
            }
         }
      }

      return method_936(var1, new class_120[]{var0.method_929(var2)});
   }

   // $VF: renamed from: a (ac[], boolean) ac[]
   public static final class_120[] method_934(class_120[] var0, boolean var1) {
      if (var0 == null) {
         return null;
      } else {
         class_120[] var2 = new class_120[var0.length];
         class_120[] var3 = new class_120[var0.length];
         System.arraycopy(var0, 0, var3, 0, var0.length);
         int var4 = 0;

         for (int var5 = 0; var5 < var3.length; var5++) {
            if (var1 && var3[var5].field_1490 > 0) {
               var2[var4] = var3[var5].method_929(var3[var5].field_1490);
               var4++;
            } else if (!var1 && var3[var5].field_1491 > 0) {
               var2[var4] = var3[var5].method_929(var3[var5].field_1491);
               var4++;
            }
         }

         class_120[] var6 = new class_120[var4];
         System.arraycopy(var2, 0, var6, 0, var4);
         return var6;
      }
   }

   // $VF: renamed from: a (ac[], ac[]) ac[]
   public static final class_120[] method_935(class_120[] var0, class_120[] var1) {
      int var2 = var0 == null ? 0 : var0.length;
      int var3 = var1 == null ? 0 : var1.length;
      class_120[] var4 = new class_120[var2 + var3];
      if (var2 > 0 && var3 == 0) {
         for (int var10 = 0; var10 < var0.length; var10++) {
            var4[var10] = var0[var10].method_929(var0[var10].field_1490);
         }

         return var4;
      } else if (var3 > 0 && var2 == 0) {
         for (int var9 = 0; var9 < var1.length; var9++) {
            var4[var9] = var1[var9].method_929(0);
            var4[var9].field_1491 = var1[var9].field_1490;
         }

         return var4;
      } else if (var3 == 0 && var2 == 0) {
         return null;
      } else {
         for (int var5 = 0; var5 < var0.length; var5++) {
            var4[var5] = var0[var5].method_929(var0[var5].field_1490);
         }

         int var8 = var2;

         for (int var6 = 0; var6 < var1.length; var6++) {
            for (int var7 = 0; var7 < var4.length; var7++) {
               if (var4[var7] == null) {
                  var4[var7] = var1[var6].method_929(0);
                  var4[var7].field_1491 = var1[var6].field_1490;
                  var8++;
                  break;
               }

               if (var1[var6].method_938(var4[var7])) {
                  var4[var7] = var1[var6].method_929(var4[var7].field_1490);
                  var4[var7].field_1491 = var1[var6].field_1490;
                  break;
               }
            }
         }

         class_120[] var11 = new class_120[var8];
         System.arraycopy(var4, 0, var11, 0, var8);
         return var11;
      }
   }

   // $VF: renamed from: b (ac[], ac[]) ac[]
   public static final class_120[] method_936(class_120[] var0, class_120[] var1) {
      if (var0 == null) {
         return var1;
      } else if (var1 == null) {
         return var0;
      } else {
         class_120[] var2 = new class_120[var1.length];

         for (int var3 = 0; var3 < var1.length; var3++) {
            var2[var3] = var1[var3];
         }

         Object var8 = null;
         int var4 = var2.length;

         for (int var5 = 0; var5 < var0.length; var5++) {
            for (int var6 = 0; var6 < var2.length; var6++) {
               if (var2[var6] != null && var0[var5].field_1480 == var2[var6].field_1480) {
                  var0[var5].method_926(var2[var6].field_1490);
                  var4--;
                  var2[var6] = null;
               }
            }
         }

         if (var4 <= 0) {
            return var0;
         } else {
            var8 = new class_120[var4];
            int var10 = 0;

            for (int var11 = 0; var11 < var2.length; var11++) {
               if (var2[var11] != null) {
                  ((Object[])var8)[var10++] = var2[var11];
               }
            }

            class_120[] var12 = new class_120[var0.length + ((Object[])var8).length];

            for (int var7 = 0; var7 < var0.length; var7++) {
               var12[var7] = var0[var7];
            }

            for (int var13 = 0; var13 < ((Object[])var8).length; var13++) {
               var12[var13 + var0.length] = (class_120)((Object[])var8)[var13];
            }

            return var12;
         }
      }
   }

   // $VF: renamed from: a () ac
   public final class_120 method_937() {
      return new class_120(
         this.field_1480,
         this.field_1481,
         this.field_1482,
         this.field_1483,
         this.field_1485,
         this.field_1486,
         this.field_1487,
         this.field_1488,
         this.field_1489
      );
   }

   // $VF: renamed from: a (ac) boolean
   public final boolean method_938(class_120 var1) {
      return var1 == null ? false : this.field_1480 == var1.field_1480;
   }

   public final String toString() {
      return this.field_1480 + " " + this.field_1482 + " " + this.field_1485 + " " + this.field_1486 + " " + this.field_1487;
   }
}
