// $VF: renamed from: bn
public final class class_1 {
   // $VF: renamed from: a short
   private short field_0;
   // $VF: renamed from: g int
   private int field_1;
   // $VF: renamed from: h int
   private int field_2;
   // $VF: renamed from: i int
   private int field_3;
   // $VF: renamed from: j int
   private int field_4;
   // $VF: renamed from: k int
   private int field_5;
   // $VF: renamed from: l int
   private int field_6;
   // $VF: renamed from: m int
   private int field_7;
   // $VF: renamed from: n int
   private int field_8;
   // $VF: renamed from: o int
   private int field_9;
   // $VF: renamed from: a int
   public int field_10;
   // $VF: renamed from: b int
   public int field_11;
   // $VF: renamed from: c int
   public int field_12;
   // $VF: renamed from: d int
   public int field_13;
   // $VF: renamed from: e int
   public int field_14;
   // $VF: renamed from: f int
   public int field_15;
   // $VF: renamed from: p int
   private int field_16;
   // $VF: renamed from: q int
   private int field_17;
   // $VF: renamed from: r int
   private int field_18;
   // $VF: renamed from: a boolean
   private boolean field_19;
   // $VF: renamed from: a v
   private static class_5 field_20 = new class_5();

   public class_1() {
      this.method_2();
      this.field_0 = 0;
   }

   public class_1(class_1 var1) {
      this.field_1 = var1.field_1;
      this.field_2 = var1.field_2;
      this.field_3 = var1.field_3;
      this.field_4 = var1.field_4;
      this.field_5 = var1.field_5;
      this.field_6 = var1.field_6;
      this.field_7 = var1.field_7;
      this.field_8 = var1.field_8;
      this.field_9 = var1.field_9;
      this.field_10 = var1.field_10;
      this.field_11 = var1.field_11;
      this.field_12 = var1.field_12;
      this.field_13 = var1.field_13;
      this.field_14 = var1.field_14;
      this.field_15 = var1.field_15;
      this.field_16 = var1.field_16;
      this.field_17 = var1.field_17;
      this.field_18 = var1.field_18;
      this.field_19 = var1.field_19;
   }

   // $VF: renamed from: a () void
   public final void method_2() {
      this.field_1 = this.field_2 = this.field_3 = 4096;
      this.field_4 = 4096;
      this.field_7 = 0;
      this.field_10 = 0;
      this.field_5 = 0;
      this.field_8 = 4096;
      this.field_11 = 0;
      this.field_6 = 0;
      this.field_9 = 0;
      this.field_12 = 4096;
      this.field_13 = this.field_14 = this.field_15 = 0;
      this.field_16 = this.field_17 = this.field_18 = 0;
      this.field_19 = false;
   }

   // $VF: renamed from: a (bn) void
   public final void method_3(class_1 var1) {
      this.field_1 = var1.field_1;
      this.field_2 = var1.field_2;
      this.field_3 = var1.field_3;
      this.field_4 = var1.field_4;
      this.field_5 = var1.field_5;
      this.field_6 = var1.field_6;
      this.field_7 = var1.field_7;
      this.field_8 = var1.field_8;
      this.field_9 = var1.field_9;
      this.field_10 = var1.field_10;
      this.field_11 = var1.field_11;
      this.field_12 = var1.field_12;
      this.field_13 = var1.field_13;
      this.field_14 = var1.field_14;
      this.field_15 = var1.field_15;
      this.field_16 = var1.field_16;
      this.field_17 = var1.field_17;
      this.field_18 = var1.field_18;
      this.field_19 = var1.field_19;
   }

   // $VF: renamed from: b (bn) void
   public final void method_4(class_1 var1) {
      int var2 = this.field_4;
      int var3 = this.field_7;
      int var4 = this.field_5;
      int var5 = this.field_8;
      int var6 = this.field_6;
      int var7 = this.field_9;
      this.field_13 = this.field_13
         + (this.field_1 * ((this.field_4 * var1.field_13 >> 12) + (this.field_7 * var1.field_14 >> 12) + (this.field_10 * var1.field_15 >> 12)) >> 12);
      this.field_14 = this.field_14
         + (this.field_2 * ((this.field_5 * var1.field_13 >> 12) + (this.field_8 * var1.field_14 >> 12) + (this.field_11 * var1.field_15 >> 12)) >> 12);
      this.field_15 = this.field_15
         + (this.field_3 * ((this.field_6 * var1.field_13 >> 12) + (this.field_9 * var1.field_14 >> 12) + (this.field_12 * var1.field_15 >> 12)) >> 12);
      this.field_1 = this.field_1 * var1.field_1 >> 12;
      this.field_2 = this.field_2 * var1.field_2 >> 12;
      this.field_3 = this.field_3 * var1.field_3 >> 12;
      this.field_4 = (var2 * var1.field_4 >> 12) + (var3 * var1.field_5 >> 12) + (this.field_10 * var1.field_6 >> 12);
      this.field_5 = (var4 * var1.field_4 >> 12) + (var5 * var1.field_5 >> 12) + (this.field_11 * var1.field_6 >> 12);
      this.field_6 = (var6 * var1.field_4 >> 12) + (var7 * var1.field_5 >> 12) + (this.field_12 * var1.field_6 >> 12);
      this.field_7 = (var2 * var1.field_7 >> 12) + (var3 * var1.field_8 >> 12) + (this.field_10 * var1.field_9 >> 12);
      this.field_8 = (var4 * var1.field_7 >> 12) + (var5 * var1.field_8 >> 12) + (this.field_11 * var1.field_9 >> 12);
      this.field_9 = (var6 * var1.field_7 >> 12) + (var7 * var1.field_8 >> 12) + (this.field_12 * var1.field_9 >> 12);
      this.field_10 = (var2 * var1.field_10 >> 12) + (var3 * var1.field_11 >> 12) + (this.field_10 * var1.field_12 >> 12);
      this.field_11 = (var4 * var1.field_10 >> 12) + (var5 * var1.field_11 >> 12) + (this.field_11 * var1.field_12 >> 12);
      this.field_12 = (var6 * var1.field_10 >> 12) + (var7 * var1.field_11 >> 12) + (this.field_12 * var1.field_12 >> 12);
      this.field_19 = true;
   }

   // $VF: renamed from: c (bn) void
   public final void method_5(class_1 var1) {
      long var2 = this.field_4;
      long var4 = this.field_7;
      long var6 = this.field_5;
      long var8 = this.field_8;
      long var10 = this.field_6;
      long var12 = this.field_9;
      this.field_13 = (int)(
         this.field_13
            + (
               this.field_1
                     * (((long)this.field_4 * var1.field_13 >> 12) + ((long)this.field_7 * var1.field_14 >> 12) + ((long)this.field_10 * var1.field_15 >> 12))
                  >> 12
            )
      );
      this.field_14 = (int)(
         this.field_14
            + (
               this.field_2
                     * (((long)this.field_5 * var1.field_13 >> 12) + ((long)this.field_8 * var1.field_14 >> 12) + ((long)this.field_11 * var1.field_15 >> 12))
                  >> 12
            )
      );
      this.field_15 = (int)(
         this.field_15
            + (
               this.field_3
                     * (((long)this.field_6 * var1.field_13 >> 12) + ((long)this.field_9 * var1.field_14 >> 12) + ((long)this.field_12 * var1.field_15 >> 12))
                  >> 12
            )
      );
      this.field_1 = (int)((long)this.field_1 * var1.field_1 >> 12);
      this.field_2 = (int)((long)this.field_2 * var1.field_2 >> 12);
      this.field_3 = (int)((long)this.field_3 * var1.field_3 >> 12);
      this.field_4 = (int)((var2 * var1.field_4 >> 12) + (var4 * var1.field_5 >> 12) + ((long)this.field_10 * var1.field_6 >> 12));
      this.field_5 = (int)((var6 * var1.field_4 >> 12) + (var8 * var1.field_5 >> 12) + ((long)this.field_11 * var1.field_6 >> 12));
      this.field_6 = (int)((var10 * var1.field_4 >> 12) + (var12 * var1.field_5 >> 12) + ((long)this.field_12 * var1.field_6 >> 12));
      this.field_7 = (int)((var2 * var1.field_7 >> 12) + (var4 * var1.field_8 >> 12) + ((long)this.field_10 * var1.field_9 >> 12));
      this.field_8 = (int)((var6 * var1.field_7 >> 12) + (var8 * var1.field_8 >> 12) + ((long)this.field_11 * var1.field_9 >> 12));
      this.field_9 = (int)((var10 * var1.field_7 >> 12) + (var12 * var1.field_8 >> 12) + ((long)this.field_12 * var1.field_9 >> 12));
      this.field_10 = (int)((var2 * var1.field_10 >> 12) + (var4 * var1.field_11 >> 12) + ((long)this.field_10 * var1.field_12 >> 12));
      this.field_11 = (int)((var6 * var1.field_10 >> 12) + (var8 * var1.field_11 >> 12) + ((long)this.field_11 * var1.field_12 >> 12));
      this.field_12 = (int)((var10 * var1.field_10 >> 12) + (var12 * var1.field_11 >> 12) + ((long)this.field_12 * var1.field_12 >> 12));
      int var14 = class_124.method_940(
         (int)(((long)this.field_4 * this.field_4 >> 12) + ((long)this.field_5 * this.field_5 >> 12) + ((long)this.field_6 * this.field_6 >> 12))
      );
      this.field_4 = this.field_4 * var14 >> 12;
      this.field_5 = this.field_5 * var14 >> 12;
      this.field_6 = this.field_6 * var14 >> 12;
      var14 = class_124.method_940(
         (int)(((long)this.field_7 * this.field_7 >> 12) + ((long)this.field_8 * this.field_8 >> 12) + ((long)this.field_9 * this.field_9 >> 12))
      );
      this.field_7 = this.field_7 * var14 >> 12;
      this.field_8 = this.field_8 * var14 >> 12;
      this.field_9 = this.field_9 * var14 >> 12;
      var14 = class_124.method_940(
         (int)(((long)this.field_10 * this.field_10 >> 12) + ((long)this.field_11 * this.field_11 >> 12) + ((long)this.field_12 * this.field_12 >> 12))
      );
      this.field_10 = this.field_10 * var14 >> 12;
      this.field_11 = this.field_11 * var14 >> 12;
      this.field_12 = this.field_12 * var14 >> 12;
      this.field_19 = true;
   }

   // $VF: renamed from: a (bn, bn) bn
   public final class_1 method_6(class_1 var1, class_1 var2) {
      var2.field_13 = this.field_13
         + (this.field_1 * ((this.field_4 * var1.field_13 >> 12) + (this.field_7 * var1.field_14 >> 12) + (this.field_10 * var1.field_15 >> 12)) >> 12);
      var2.field_14 = this.field_14
         + (this.field_2 * ((this.field_5 * var1.field_13 >> 12) + (this.field_8 * var1.field_14 >> 12) + (this.field_11 * var1.field_15 >> 12)) >> 12);
      var2.field_15 = this.field_15
         + (this.field_3 * ((this.field_6 * var1.field_13 >> 12) + (this.field_9 * var1.field_14 >> 12) + (this.field_12 * var1.field_15 >> 12)) >> 12);
      var2.field_1 = this.field_1 * var1.field_1 >> 12;
      var2.field_2 = this.field_2 * var1.field_2 >> 12;
      var2.field_3 = this.field_3 * var1.field_3 >> 12;
      var2.field_4 = (this.field_4 * var1.field_4 >> 12) + (this.field_7 * var1.field_5 >> 12) + (this.field_10 * var1.field_6 >> 12);
      var2.field_5 = (this.field_5 * var1.field_4 >> 12) + (this.field_8 * var1.field_5 >> 12) + (this.field_11 * var1.field_6 >> 12);
      var2.field_6 = (this.field_6 * var1.field_4 >> 12) + (this.field_9 * var1.field_5 >> 12) + (this.field_12 * var1.field_6 >> 12);
      var2.field_7 = (this.field_4 * var1.field_7 >> 12) + (this.field_7 * var1.field_8 >> 12) + (this.field_10 * var1.field_9 >> 12);
      var2.field_8 = (this.field_5 * var1.field_7 >> 12) + (this.field_8 * var1.field_8 >> 12) + (this.field_11 * var1.field_9 >> 12);
      var2.field_9 = (this.field_6 * var1.field_7 >> 12) + (this.field_9 * var1.field_8 >> 12) + (this.field_12 * var1.field_9 >> 12);
      var2.field_10 = (this.field_4 * var1.field_10 >> 12) + (this.field_7 * var1.field_11 >> 12) + (this.field_10 * var1.field_12 >> 12);
      var2.field_11 = (this.field_5 * var1.field_10 >> 12) + (this.field_8 * var1.field_11 >> 12) + (this.field_11 * var1.field_12 >> 12);
      var2.field_12 = (this.field_6 * var1.field_10 >> 12) + (this.field_9 * var1.field_11 >> 12) + (this.field_12 * var1.field_12 >> 12);
      var2.field_19 = true;
      return var2;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_7(int var1, int var2, int var3) {
      this.field_13 += var1;
      this.field_14 += var2;
      this.field_15 += var3;
   }

   // $VF: renamed from: a (v) void
   public final void method_8(class_5 var1) {
      this.field_13 = this.field_13 + var1.field_138;
      this.field_14 = this.field_14 + var1.field_139;
      this.field_15 = this.field_15 + var1.field_140;
   }

   // $VF: renamed from: b (int, int, int) void
   public final void method_9(int var1, int var2, int var3) {
      this.field_13 = var1;
      this.field_14 = var2;
      this.field_15 = var3;
   }

   // $VF: renamed from: b (v) void
   public final void method_10(class_5 var1) {
      this.field_13 = var1.field_138;
      this.field_14 = var1.field_139;
      this.field_15 = var1.field_140;
   }

   // $VF: renamed from: a (int) void
   public final void method_11(int var1) {
      this.field_13 = this.field_13 + (this.field_10 * var1 >> 12);
      this.field_14 = this.field_14 + (this.field_11 * var1 >> 12);
      this.field_15 = this.field_15 + (this.field_12 * var1 >> 12);
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_12(class_5 var1) {
      var1.field_138 = this.field_13;
      var1.field_139 = this.field_14;
      var1.field_140 = this.field_15;
      return var1;
   }

   // $VF: renamed from: a () v
   public final class_5 method_13() {
      return new class_5(this.field_13, this.field_14, this.field_15);
   }

   // $VF: renamed from: b (v) v
   public final class_5 method_14(class_5 var1) {
      var1.field_138 = this.field_10;
      var1.field_139 = this.field_11;
      var1.field_140 = this.field_12;
      return var1;
   }

   // $VF: renamed from: c (v) v
   public final class_5 method_15(class_5 var1) {
      var1.field_138 = this.field_7;
      var1.field_139 = this.field_8;
      var1.field_140 = this.field_9;
      return var1;
   }

   // $VF: renamed from: b () v
   public final class_5 method_16() {
      return new class_5(this.field_7, this.field_8, this.field_9);
   }

   // $VF: renamed from: d (v) v
   public final class_5 method_17(class_5 var1) {
      var1.field_138 = this.field_4;
      var1.field_139 = this.field_5;
      var1.field_140 = this.field_6;
      return var1;
   }

   // $VF: renamed from: a (short) void
   public final void method_18(short var1) {
      if (this.field_0 != var1) {
         this.field_0 = var1;
         this.method_26();
         this.field_19 = false;
      }
   }

   // $VF: renamed from: c (int, int, int) void
   public final void method_19(int var1, int var2, int var3) {
      if (this.field_19) {
         this.method_26();
         this.field_19 = false;
      }

      this.field_16 += var1;
      this.field_17 += var2;
      this.field_18 += var3;
      this.method_24(this.field_16, this.field_17, this.field_18);
   }

   // $VF: renamed from: b (int) void
   public final void method_20(int var1) {
      int var2 = class_124.method_936(var1);
      int var3 = class_124.method_937(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_10 >> 12) * this.field_12 >> 12;
      int var6 = (var4 * this.field_11 >> 12) * this.field_12 >> 12;
      int var7 = (var4 * this.field_10 >> 12) * this.field_11 >> 12;
      int var8 = var2 * this.field_11 >> 12;
      int var9 = var2 * this.field_10 >> 12;
      int var10 = var2 * this.field_12 >> 12;
      int var11 = ((var4 * this.field_10 >> 12) * this.field_10 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_11 >> 12) * this.field_11 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_12 >> 12) * this.field_12 >> 12) + var3;
      int var20 = this.field_4;
      int var21 = this.field_5;
      this.field_4 = (this.field_4 * var11 >> 12) + (this.field_5 * var12 >> 12) + (this.field_6 * var13 >> 12);
      this.field_5 = (var20 * var14 >> 12) + (this.field_5 * var15 >> 12) + (this.field_6 * var16 >> 12);
      this.field_6 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_6 * var19 >> 12);
      this.field_7 = (this.field_11 * this.field_6 >> 12) - (this.field_12 * this.field_5 >> 12);
      this.field_8 = (this.field_12 * this.field_4 >> 12) - (this.field_10 * this.field_6 >> 12);
      this.field_9 = (this.field_10 * this.field_5 >> 12) - (this.field_11 * this.field_4 >> 12);
      int var22 = class_124.method_940((this.field_7 * this.field_7 >> 12) + (this.field_8 * this.field_8 >> 12) + (this.field_9 * this.field_9 >> 12));
      this.field_7 = this.field_7 * var22 >> 12;
      this.field_8 = this.field_8 * var22 >> 12;
      this.field_9 = this.field_9 * var22 >> 12;
      this.field_4 = (this.field_12 * this.field_8 >> 12) - (this.field_11 * this.field_9 >> 12);
      this.field_5 = (this.field_10 * this.field_9 >> 12) - (this.field_12 * this.field_7 >> 12);
      this.field_6 = (this.field_11 * this.field_7 >> 12) - (this.field_10 * this.field_8 >> 12);
      this.field_19 = true;
   }

   // $VF: renamed from: c (int) void
   public final void method_21(int var1) {
      int var2 = class_124.method_936(var1);
      int var3 = class_124.method_937(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_7 >> 12) * this.field_9 >> 12;
      int var6 = (var4 * this.field_8 >> 12) * this.field_9 >> 12;
      int var7 = (var4 * this.field_7 >> 12) * this.field_8 >> 12;
      int var8 = var2 * this.field_8 >> 12;
      int var9 = var2 * this.field_7 >> 12;
      int var10 = var2 * this.field_9 >> 12;
      int var11 = ((var4 * this.field_7 >> 12) * this.field_7 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_8 >> 12) * this.field_8 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_9 >> 12) * this.field_9 >> 12) + var3;
      int var20 = this.field_10;
      int var21 = this.field_11;
      this.field_10 = (this.field_10 * var11 >> 12) + (this.field_11 * var12 >> 12) + (this.field_12 * var13 >> 12);
      this.field_11 = (var20 * var14 >> 12) + (this.field_11 * var15 >> 12) + (this.field_12 * var16 >> 12);
      this.field_12 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_12 * var19 >> 12);
      this.field_4 = (this.field_12 * this.field_8 >> 12) - (this.field_11 * this.field_9 >> 12);
      this.field_5 = (this.field_10 * this.field_9 >> 12) - (this.field_12 * this.field_7 >> 12);
      this.field_6 = (this.field_11 * this.field_7 >> 12) - (this.field_10 * this.field_8 >> 12);
      int var22 = class_124.method_940((this.field_4 * this.field_4 >> 12) + (this.field_5 * this.field_5 >> 12) + (this.field_6 * this.field_6 >> 12));
      this.field_4 = this.field_4 * var22 >> 12;
      this.field_5 = this.field_5 * var22 >> 12;
      this.field_6 = this.field_6 * var22 >> 12;
      this.field_10 = (this.field_9 * this.field_5 >> 12) - (this.field_8 * this.field_6 >> 12);
      this.field_11 = (this.field_7 * this.field_6 >> 12) - (this.field_9 * this.field_4 >> 12);
      this.field_12 = (this.field_8 * this.field_4 >> 12) - (this.field_7 * this.field_5 >> 12);
      this.field_19 = true;
   }

   // $VF: renamed from: d (int) void
   public final void method_22(int var1) {
      int var2 = class_124.method_936(var1);
      int var3 = class_124.method_937(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_4 >> 12) * this.field_6 >> 12;
      int var6 = (var4 * this.field_5 >> 12) * this.field_6 >> 12;
      int var7 = (var4 * this.field_4 >> 12) * this.field_5 >> 12;
      int var8 = var2 * this.field_5 >> 12;
      int var9 = var2 * this.field_4 >> 12;
      int var10 = var2 * this.field_6 >> 12;
      int var11 = ((var4 * this.field_4 >> 12) * this.field_4 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_5 >> 12) * this.field_5 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_6 >> 12) * this.field_6 >> 12) + var3;
      int var20 = this.field_7;
      int var21 = this.field_8;
      this.field_7 = (this.field_7 * var11 >> 12) + (this.field_8 * var12 >> 12) + (this.field_9 * var13 >> 12);
      this.field_8 = (var20 * var14 >> 12) + (this.field_8 * var15 >> 12) + (this.field_9 * var16 >> 12);
      this.field_9 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_9 * var19 >> 12);
      this.field_10 = (this.field_5 * this.field_9 >> 12) - (this.field_6 * this.field_8 >> 12);
      this.field_11 = (this.field_6 * this.field_7 >> 12) - (this.field_4 * this.field_9 >> 12);
      this.field_12 = (this.field_4 * this.field_8 >> 12) - (this.field_5 * this.field_7 >> 12);
      int var22 = class_124.method_940((this.field_10 * this.field_10 >> 12) + (this.field_11 * this.field_11 >> 12) + (this.field_12 * this.field_12 >> 12));
      this.field_10 = this.field_10 * var22 >> 12;
      this.field_11 = this.field_11 * var22 >> 12;
      this.field_12 = this.field_12 * var22 >> 12;
      this.field_7 = (this.field_11 * this.field_6 >> 12) - (this.field_12 * this.field_5 >> 12);
      this.field_8 = (this.field_12 * this.field_4 >> 12) - (this.field_10 * this.field_6 >> 12);
      this.field_9 = (this.field_10 * this.field_5 >> 12) - (this.field_11 * this.field_4 >> 12);
      this.field_19 = true;
   }

   // $VF: renamed from: e (int) void
   public final void method_23(int var1) {
      this.method_24(this.field_16, var1, this.field_18);
   }

   // $VF: renamed from: d (int, int, int) void
   public final void method_24(int var1, int var2, int var3) {
      this.field_16 = var1;
      this.field_17 = var2;
      this.field_18 = var3;
      this.field_19 = false;
      int var4 = class_124.method_936(var1);
      int var5 = class_124.method_936(var2);
      int var6 = class_124.method_936(var3);
      int var7 = class_124.method_937(var1);
      int var8 = class_124.method_937(var2);
      int var9 = class_124.method_937(var3);
      switch (this.field_0) {
         case 0:
            int var17 = var7 * var9 >> 12;
            int var22 = var9 * var4 >> 12;
            int var25 = var5 * var6 >> 12;
            this.field_4 = var8 * var9 >> 12;
            this.field_7 = -(var8 * var6 >> 12);
            this.field_10 = var5;
            this.field_5 = (var22 * var5 >> 12) + (var7 * var6 >> 12);
            this.field_8 = var17 - (var25 * var4 >> 12);
            this.field_11 = -(var8 * var4 >> 12);
            this.field_6 = -(var17 * var5 >> 12) + (var4 * var6 >> 12);
            this.field_9 = var22 + (var25 * var7 >> 12);
            this.field_12 = var7 * var8 >> 12;
            return;
         case 1:
            int var16 = var8 * var6 >> 12;
            int var21 = var5 * var6 >> 12;
            this.field_4 = var8 * var9 >> 12;
            this.field_7 = -var6;
            this.field_10 = var9 * var5 >> 12;
            this.field_5 = (var4 * var5 >> 12) + (var16 * var7 >> 12);
            this.field_8 = var7 * var9 >> 12;
            this.field_11 = -(var8 * var4 >> 12) + (var21 * var7 >> 12);
            this.field_6 = -(var7 * var5 >> 12) + (var16 * var4 >> 12);
            this.field_9 = var9 * var4 >> 12;
            this.field_12 = (var7 * var8 >> 12) + (var21 * var4 >> 12);
            return;
         case 2:
            int var15 = var8 * var9 >> 12;
            int var20 = var4 * var6 >> 12;
            int var24 = var5 * var9 >> 12;
            this.field_4 = var15 + (var20 * var5 >> 12);
            this.field_7 = (var24 * var4 >> 12) - (var8 * var6 >> 12);
            this.field_10 = var7 * var5 >> 12;
            this.field_5 = var7 * var6 >> 12;
            this.field_8 = var7 * var9 >> 12;
            this.field_11 = -var4;
            this.field_6 = -var24 + (var20 * var8 >> 12);
            this.field_9 = (var15 * var4 >> 12) + (var5 * var6 >> 12);
            this.field_12 = var7 * var8 >> 12;
            return;
         case 3:
            int var14 = var4 * var5 >> 12;
            int var19 = var7 * var8 >> 12;
            int var23 = var8 * var4 >> 12;
            this.field_4 = var8 * var9 >> 12;
            this.field_7 = var14 - (var19 * var6 >> 12);
            this.field_10 = (var7 * var5 >> 12) + (var23 * var6 >> 12);
            this.field_5 = var6;
            this.field_8 = var7 * var9 >> 12;
            this.field_11 = -(var9 * var4 >> 12);
            this.field_6 = -(var9 * var5 >> 12);
            this.field_9 = var23 + ((var7 * var5 >> 12) * var6 >> 12);
            this.field_12 = var19 - (var14 * var6 >> 12);
            return;
         case 4:
            int var13 = var4 * var5 >> 12;
            int var18 = var8 * var4 >> 12;
            this.field_4 = (var8 * var9 >> 12) - (var13 * var6 >> 12);
            this.field_7 = -(var7 * var6 >> 12);
            this.field_10 = (var9 * var5 >> 12) + (var18 * var6 >> 12);
            this.field_5 = (var13 * var9 >> 12) + (var8 * var6 >> 12);
            this.field_8 = var7 * var9 >> 12;
            this.field_11 = -(var18 * var9 >> 12) + (var5 * var6 >> 12);
            this.field_6 = -(var7 * var5 >> 12);
            this.field_9 = var4;
            this.field_12 = var7 * var8 >> 12;
            return;
         case 5:
            int var10 = var5 * var6 >> 12;
            boolean var11 = false;
            int var12 = var9 * var5 >> 12;
            this.field_4 = var8 * var9 >> 12;
            this.field_7 = (var12 * var4 >> 12) - (var7 * var6 >> 12);
            this.field_10 = (var12 * var7 >> 12) + (var4 * var6 >> 12);
            this.field_5 = var8 * var6 >> 12;
            this.field_8 = (var7 * var9 >> 12) + (var10 * var4 >> 12);
            this.field_11 = -(var9 * var4 >> 12) + (var10 * var7 >> 12);
            this.field_6 = -var5;
            this.field_9 = var8 * var4 >> 12;
            this.field_12 = var7 * var8 >> 12;
      }
   }

   // $VF: renamed from: a () int
   public final int method_25() {
      if (this.field_19) {
         this.method_26();
         this.field_19 = false;
      }

      return this.field_17;
   }

   // $VF: renamed from: b () void
   private void method_26() {
      switch (this.field_0) {
         case 0:
            this.field_17 = class_124.method_938(this.field_10);
            if (this.field_17 < 2048) {
               if (this.field_17 > -2048) {
                  this.field_16 = class_124.method_939(-this.field_11, this.field_12);
                  this.field_18 = class_124.method_939(-this.field_7, this.field_4);
                  return;
               }

               this.field_16 = -class_124.method_939(this.field_5, this.field_8);
               this.field_18 = 0;
               return;
            }

            this.field_16 = class_124.method_939(this.field_5, this.field_8);
            this.field_18 = 0;
            return;
         case 1:
            this.field_18 = class_124.method_938(-this.field_7);
            if (this.field_18 < 2048) {
               if (this.field_18 > -2048) {
                  this.field_16 = class_124.method_939(this.field_9, this.field_8);
                  this.field_17 = class_124.method_939(this.field_10, this.field_4);
                  return;
               }

               this.field_16 = -class_124.method_939(-this.field_6, this.field_12);
               this.field_17 = 0;
               return;
            }

            this.field_16 = class_124.method_939(-this.field_6, this.field_12);
            this.field_17 = 0;
            return;
         case 2:
            this.field_16 = class_124.method_938(-this.field_11);
            if (this.field_16 < 2048) {
               if (this.field_16 > -2048) {
                  this.field_17 = class_124.method_939(this.field_10, this.field_12);
                  this.field_18 = class_124.method_939(this.field_5, this.field_8);
                  return;
               }

               this.field_17 = -class_124.method_939(-this.field_7, this.field_4);
               this.field_18 = 0;
               return;
            }

            this.field_17 = class_124.method_939(-this.field_7, this.field_4);
            this.field_18 = 0;
            return;
         case 3:
            this.field_18 = class_124.method_938(this.field_5);
            if (this.field_18 < 2048) {
               if (this.field_18 > -2048) {
                  this.field_17 = class_124.method_939(-this.field_6, this.field_4);
                  this.field_16 = class_124.method_939(-this.field_11, this.field_8);
                  return;
               }

               this.field_17 = -class_124.method_939(this.field_9, this.field_12);
               this.field_16 = 0;
               return;
            }

            this.field_17 = class_124.method_939(this.field_9, this.field_12);
            this.field_16 = 0;
            return;
         case 4:
            this.field_16 = class_124.method_938(this.field_9);
            if (this.field_16 < 2048) {
               if (this.field_16 > -2048) {
                  this.field_18 = class_124.method_939(-this.field_7, this.field_8);
                  this.field_17 = class_124.method_939(-this.field_6, this.field_12);
                  return;
               }

               this.field_18 = -class_124.method_939(this.field_10, this.field_4);
               this.field_17 = 0;
               return;
            }

            this.field_18 = class_124.method_939(this.field_10, this.field_4);
            this.field_17 = 0;
            return;
         case 5:
            this.field_17 = class_124.method_938(-this.field_6);
            if (this.field_17 < 2048) {
               if (this.field_17 > -2048) {
                  this.field_18 = class_124.method_939(this.field_5, this.field_4);
                  this.field_16 = class_124.method_939(this.field_9, this.field_12);
                  return;
               }

               this.field_18 = -class_124.method_939(-this.field_7, this.field_10);
               this.field_16 = 0;
               return;
            } else {
               this.field_18 = class_124.method_939(-this.field_7, this.field_10);
               this.field_16 = 0;
            }
      }
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_27(int var1, int var2, int var3, int var4) {
      this.field_4 = 4096 - (2 * var2 * var2 >> 12) - (2 * var3 * var3 >> 12);
      this.field_7 = (2 * var1 * var2 >> 12) - (2 * var4 * var3 >> 12);
      this.field_10 = (2 * var1 * var3 >> 12) + (2 * var4 * var2 >> 12);
      this.field_5 = (2 * var1 * var2 >> 12) + (2 * var4 * var3 >> 12);
      this.field_8 = 4096 - (2 * var1 * var1 >> 12) - (2 * var3 * var3 >> 12);
      this.field_11 = (2 * var2 * var3 >> 12) - (2 * var4 * var1 >> 12);
      this.field_6 = (2 * var1 * var3 >> 12) - (2 * var4 * var2 >> 12);
      this.field_9 = (2 * var4 * var1 >> 12) + (2 * var2 * var3 >> 12);
      this.field_12 = 4096 - (2 * var1 * var1 >> 12) - (2 * var2 * var2 >> 12);
      this.field_19 = true;
   }

   // $VF: renamed from: a (a) void
   public final void method_28(class_61 var1) {
      this.method_27(var1.field_839, var1.field_840, var1.field_841, var1.field_842);
   }

   // $VF: renamed from: a (int) int
   private int method_29(int var1) {
      return var1 < 2 ? var1 + 1 : 0;
   }

   // $VF: renamed from: b (int) int
   private final int method_30(int var1) {
      switch (var1) {
         case 0:
            return this.field_4;
         case 1:
            return this.field_5;
         case 2:
            return this.field_6;
         case 3:
            return this.field_7;
         case 4:
            return this.field_8;
         case 5:
            return this.field_9;
         case 6:
            return this.field_10;
         case 7:
            return this.field_11;
         case 8:
            return this.field_12;
         default:
            return 0;
      }
   }

   // $VF: renamed from: a (a) a
   public final class_61 method_31(class_61 var1) {
      int var2;
      if ((var2 = 4096 + this.field_4 + this.field_8 + this.field_12) > 0) {
         int var7 = class_124.method_941(var2);
         var1.field_842 = var7 >> 1;
         var7 = 8388608 / var7;
         var1.field_839 = (this.field_9 - this.field_11) * var7 >> 12;
         var1.field_840 = (this.field_10 - this.field_6) * var7 >> 12;
         var1.field_841 = (this.field_5 - this.field_7) * var7 >> 12;
         return var1;
      } else {
         byte var3 = 0;
         if (this.field_8 > this.field_4) {
            var3 = 1;
         }

         if (this.field_12 > this.method_30(var3 * 4)) {
            var3 = 2;
         }

         int var4 = this.method_29(var3);
         int var5 = this.method_29(var4);
         int var6 = class_124.method_941(4096 + this.method_30(var3 * 4) - this.method_30(var4 * 4) - this.method_30(var5 * 4));
         switch (var3) {
            case 0:
               var1.field_839 = var6 >> 1;
               break;
            case 1:
               var1.field_840 = var6 >> 1;
               break;
            case 2:
               var1.field_841 = var6 >> 1;
         }

         if (var6 != 0) {
            var6 = 8388608 / var6;
         }

         switch (var4) {
            case 0:
               var1.field_839 = (this.method_30(var3 + var4 * 3) + this.method_30(var4 + var3 * 3)) * var6 >> 12;
               break;
            case 1:
               var1.field_840 = (this.method_30(var3 + var4 * 3) + this.method_30(var4 + var3 * 3)) * var6 >> 12;
               break;
            case 2:
               var1.field_841 = (this.method_30(var3 + var4 * 3) + this.method_30(var4 + var3 * 3)) * var6 >> 12;
         }

         switch (var5) {
            case 0:
               var1.field_839 = (this.method_30(var3 + var5 * 3) + this.method_30(var5 + var3 * 3)) * var6 >> 12;
               break;
            case 1:
               var1.field_840 = (this.method_30(var3 + var5 * 3) + this.method_30(var5 + var3 * 3)) * var6 >> 12;
               break;
            case 2:
               var1.field_841 = (this.method_30(var3 + var5 * 3) + this.method_30(var5 + var3 * 3)) * var6 >> 12;
         }

         var1.field_842 = (this.method_30(var4 + var5 * 3) - this.method_30(var5 + var4 * 3)) * var6 >> 12;
         return var1;
      }
   }

   // $VF: renamed from: a () a
   public final class_61 method_32() {
      return this.method_31(new class_61());
   }

   // $VF: renamed from: e (int, int, int) void
   public final void method_33(int var1, int var2, int var3) {
      this.field_1 = this.field_1 * var1 >> 12;
      this.field_2 = this.field_2 * var2 >> 12;
      this.field_3 = this.field_3 * var3 >> 12;
   }

   // $VF: renamed from: f (int, int, int) void
   public final void method_34(int var1, int var2, int var3) {
      this.field_1 = var1;
      this.field_2 = var2;
      this.field_3 = var3;
   }

   // $VF: renamed from: e (v) v
   public final class_5 method_35(class_5 var1) {
      var1.field_138 = this.field_1;
      var1.field_139 = this.field_2;
      var1.field_140 = this.field_3;
      return var1;
   }

   // $VF: renamed from: a (bn) bn
   public final class_1 method_36(class_1 var1) {
      var1.field_1 = 16777216 / this.field_1;
      var1.field_2 = 16777216 / this.field_2;
      var1.field_3 = 16777216 / this.field_3;
      var1.field_4 = this.field_4;
      var1.field_7 = this.field_5;
      var1.field_10 = this.field_6;
      var1.field_5 = this.field_7;
      var1.field_8 = this.field_8;
      var1.field_11 = this.field_9;
      var1.field_6 = this.field_10;
      var1.field_9 = this.field_11;
      var1.field_12 = this.field_12;
      var1.field_13 = var1.field_1 * (-(var1.field_4 * this.field_13 >> 12) - (var1.field_7 * this.field_14 >> 12) - (var1.field_10 * this.field_15 >> 12))
         >> 12;
      var1.field_14 = var1.field_2 * (-(var1.field_5 * this.field_13 >> 12) - (var1.field_8 * this.field_14 >> 12) - (var1.field_11 * this.field_15 >> 12))
         >> 12;
      var1.field_15 = var1.field_3 * (-(var1.field_6 * this.field_13 >> 12) - (var1.field_9 * this.field_14 >> 12) - (var1.field_12 * this.field_15 >> 12))
         >> 12;
      var1.field_19 = true;
      return var1;
   }

   // $VF: renamed from: a (v, v, v) void
   public final void method_37(class_5 var1, class_5 var2, class_5 var3) {
      this.field_4 = var1.field_138;
      this.field_7 = var2.field_138;
      this.field_10 = var3.field_138;
      this.field_5 = var1.field_139;
      this.field_8 = var2.field_139;
      this.field_11 = var3.field_139;
      this.field_6 = var1.field_140;
      this.field_9 = var2.field_140;
      this.field_12 = var3.field_140;
      this.field_19 = true;
   }

   // $VF: renamed from: a (int[]) void
   public final void method_38(int[] var1) {
      var1[0] = this.field_1 * this.field_4 >> 12;
      var1[1] = this.field_2 * this.field_7 >> 12;
      var1[2] = this.field_3 * this.field_10 >> 12;
      var1[3] = this.field_13;
      var1[4] = -(this.field_1 * this.field_5 >> 12);
      var1[5] = -(this.field_2 * this.field_8 >> 12);
      var1[6] = -(this.field_3 * this.field_11 >> 12);
      var1[7] = -this.field_14;
      var1[8] = -(this.field_1 * this.field_6 >> 12);
      var1[9] = -(this.field_2 * this.field_9 >> 12);
      var1[10] = -(this.field_3 * this.field_12 >> 12);
      var1[11] = -this.field_15;
   }

   public final String toString() {
      String var1 = "";
      var1 = var1
         + "|\t"
         + (this.field_1 * this.field_4 >> 12)
         + ",\t"
         + (this.field_2 * this.field_7 >> 12)
         + ",\t"
         + (this.field_3 * this.field_10 >> 12)
         + ",\t"
         + this.field_13
         + "\t|\n";
      var1 = var1
         + "|\t"
         + (this.field_1 * this.field_5 >> 12)
         + ",\t"
         + (this.field_2 * this.field_8 >> 12)
         + ",\t"
         + (this.field_3 * this.field_11 >> 12)
         + ",\t"
         + this.field_14
         + "\t|\n";
      return var1
         + "|\t"
         + (this.field_1 * this.field_6 >> 12)
         + ",\t"
         + (this.field_2 * this.field_9 >> 12)
         + ",\t"
         + (this.field_3 * this.field_12 >> 12)
         + ",\t"
         + this.field_15
         + "\t|\n";
   }

   // $VF: renamed from: a (v, v) v
   public final class_5 method_39(class_5 var1, class_5 var2) {
      long var3 = ((long)(this.field_1 * this.field_4 >> 12) * var1.field_138 >> 12)
         + ((long)(this.field_2 * this.field_7 >> 12) * var1.field_139 >> 12)
         + ((long)(this.field_3 * this.field_10 >> 12) * var1.field_140 >> 12)
         + this.field_13;
      long var5 = ((long)(this.field_1 * this.field_5 >> 12) * var1.field_138 >> 12)
         + ((long)(this.field_2 * this.field_8 >> 12) * var1.field_139 >> 12)
         + ((long)(this.field_3 * this.field_11 >> 12) * var1.field_140 >> 12)
         + this.field_14;
      long var7 = ((long)(this.field_1 * this.field_6 >> 12) * var1.field_138 >> 12)
         + ((long)(this.field_2 * this.field_9 >> 12) * var1.field_139 >> 12)
         + ((long)(this.field_3 * this.field_12 >> 12) * var1.field_140 >> 12)
         + this.field_15;
      var2.field_138 = (int)var3;
      var2.field_139 = (int)var5;
      var2.field_140 = (int)var7;
      return var2;
   }

   // $VF: renamed from: b (v, v) v
   public final class_5 method_40(class_5 var1, class_5 var2) {
      var2.field_138 = (this.field_4 * var1.field_138 >> 12) + (this.field_7 * var1.field_139 >> 12) + (this.field_10 * var1.field_140 >> 12);
      var2.field_139 = (this.field_5 * var1.field_138 >> 12) + (this.field_8 * var1.field_139 >> 12) + (this.field_11 * var1.field_140 >> 12);
      var2.field_140 = (this.field_6 * var1.field_138 >> 12) + (this.field_9 * var1.field_139 >> 12) + (this.field_12 * var1.field_140 >> 12);
      return var2;
   }

   // $VF: renamed from: c (v, v) v
   public final class_5 method_41(class_5 var1, class_5 var2) {
      long var3 = ((long)this.field_4 * var1.field_138 >> 12) + ((long)this.field_7 * var1.field_139 >> 12) + ((long)this.field_10 * var1.field_140 >> 12);
      long var5 = ((long)this.field_5 * var1.field_138 >> 12) + ((long)this.field_8 * var1.field_139 >> 12) + ((long)this.field_11 * var1.field_140 >> 12);
      long var7 = ((long)this.field_6 * var1.field_138 >> 12) + ((long)this.field_9 * var1.field_139 >> 12) + ((long)this.field_12 * var1.field_140 >> 12);
      var2.field_138 = (int)var3;
      var2.field_139 = (int)var5;
      var2.field_140 = (int)var7;
      return var2;
   }

   // $VF: renamed from: a (v[], v[]) v[]
   public final class_5[] method_42(class_5[] var1, class_5[] var2) {
      for (int var3 = var2.length - 1; var3 >= 0; var3--) {
         var2[var3].field_138 = (this.field_4 * var1[var3].field_138 >> 12)
            + (this.field_7 * var1[var3].field_139 >> 12)
            + (this.field_10 * var1[var3].field_140 >> 12);
         var2[var3].field_139 = (this.field_5 * var1[var3].field_138 >> 12)
            + (this.field_8 * var1[var3].field_139 >> 12)
            + (this.field_11 * var1[var3].field_140 >> 12);
         var2[var3].field_140 = (this.field_6 * var1[var3].field_138 >> 12)
            + (this.field_9 * var1[var3].field_139 >> 12)
            + (this.field_12 * var1[var3].field_140 >> 12);
      }

      return var2;
   }

   // $VF: renamed from: f (v) v
   public final class_5 method_43(class_5 var1) {
      int var2 = 16777216 / this.field_1;
      int var3 = 16777216 / this.field_2;
      int var4 = 16777216 / this.field_3;
      int var5 = var2 * (-(this.field_4 * this.field_13 >> 12) - (this.field_5 * this.field_14 >> 12) - (this.field_6 * this.field_15 >> 12)) >> 12;
      int var6 = var3 * (-(this.field_7 * this.field_13 >> 12) - (this.field_8 * this.field_14 >> 12) - (this.field_9 * this.field_15 >> 12)) >> 12;
      int var7 = var4 * (-(this.field_10 * this.field_13 >> 12) - (this.field_11 * this.field_14 >> 12) - (this.field_12 * this.field_15 >> 12)) >> 12;
      int var8 = var1.field_138;
      int var9 = var1.field_139;
      int var10 = var1.field_140;
      var1.field_138 = ((var2 * this.field_4 >> 12) * var8 >> 12)
         + ((var3 * this.field_5 >> 12) * var9 >> 12)
         + ((var4 * this.field_6 >> 12) * var10 >> 12)
         + var5;
      var1.field_139 = ((var2 * this.field_7 >> 12) * var8 >> 12)
         + ((var3 * this.field_8 >> 12) * var9 >> 12)
         + ((var4 * this.field_9 >> 12) * var10 >> 12)
         + var6;
      var1.field_140 = ((var2 * this.field_10 >> 12) * var8 >> 12)
         + ((var3 * this.field_11 >> 12) * var9 >> 12)
         + ((var4 * this.field_12 >> 12) * var10 >> 12)
         + var7;
      return var1;
   }

   // $VF: renamed from: c (v) void
   public final void method_44(class_5 var1) {
      field_20.method_169(var1);
      field_20.method_182();
      this.field_10 = field_20.field_138;
      this.field_11 = field_20.field_139;
      this.field_12 = field_20.field_140;
      this.field_7 = 0;
      this.field_8 = 4096;
      this.field_9 = 0;
      this.field_4 = (this.field_8 * this.field_12 >> 12) - (this.field_9 * this.field_11 >> 12);
      this.field_5 = (this.field_9 * this.field_10 >> 12) - (this.field_7 * this.field_12 >> 12);
      this.field_6 = (this.field_7 * this.field_11 >> 12) - (this.field_8 * this.field_10 >> 12);
      field_20.field_138 = this.field_4;
      field_20.field_139 = this.field_5;
      field_20.field_140 = this.field_6;
      field_20.method_182();
      this.field_4 = field_20.field_138;
      this.field_5 = field_20.field_139;
      this.field_6 = field_20.field_140;
      this.field_7 = (this.field_11 * this.field_6 >> 12) - (this.field_12 * this.field_5 >> 12);
      this.field_8 = (this.field_12 * this.field_4 >> 12) - (this.field_10 * this.field_6 >> 12);
      this.field_9 = (this.field_10 * this.field_5 >> 12) - (this.field_11 * this.field_4 >> 12);
      field_20.field_138 = this.field_7;
      field_20.field_139 = this.field_8;
      field_20.field_140 = this.field_9;
      field_20.method_182();
      this.field_7 = field_20.field_138;
      this.field_8 = field_20.field_139;
      this.field_9 = field_20.field_140;
   }
}
