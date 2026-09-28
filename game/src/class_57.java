// $VF: renamed from: bn
public final class class_57 {
   // $VF: renamed from: a short
   private short field_685;
   // $VF: renamed from: g int
   private int field_686;
   // $VF: renamed from: h int
   private int field_687;
   // $VF: renamed from: i int
   private int field_688;
   // $VF: renamed from: j int
   private int field_689;
   // $VF: renamed from: k int
   private int field_690;
   // $VF: renamed from: l int
   private int field_691;
   // $VF: renamed from: m int
   private int field_692;
   // $VF: renamed from: n int
   private int field_693;
   // $VF: renamed from: o int
   private int field_694;
   // $VF: renamed from: a int
   public int field_695;
   // $VF: renamed from: b int
   public int field_696;
   // $VF: renamed from: c int
   public int field_697;
   // $VF: renamed from: d int
   public int field_698;
   // $VF: renamed from: e int
   public int field_699;
   // $VF: renamed from: f int
   public int field_700;
   // $VF: renamed from: p int
   private int field_701;
   // $VF: renamed from: q int
   private int field_702;
   // $VF: renamed from: r int
   private int field_703;
   // $VF: renamed from: a boolean
   private boolean field_704;
   // $VF: renamed from: a x
   private static class_3 field_705 = new class_3();

   public class_57() {
      this.method_469();
      this.field_685 = 0;
   }

   public class_57(class_57 var1) {
      this.field_686 = var1.field_686;
      this.field_687 = var1.field_687;
      this.field_688 = var1.field_688;
      this.field_689 = var1.field_689;
      this.field_690 = var1.field_690;
      this.field_691 = var1.field_691;
      this.field_692 = var1.field_692;
      this.field_693 = var1.field_693;
      this.field_694 = var1.field_694;
      this.field_695 = var1.field_695;
      this.field_696 = var1.field_696;
      this.field_697 = var1.field_697;
      this.field_698 = var1.field_698;
      this.field_699 = var1.field_699;
      this.field_700 = var1.field_700;
      this.field_701 = var1.field_701;
      this.field_702 = var1.field_702;
      this.field_703 = var1.field_703;
      this.field_704 = var1.field_704;
   }

   // $VF: renamed from: a () void
   public final void method_469() {
      this.field_686 = this.field_687 = this.field_688 = 4096;
      this.field_689 = 4096;
      this.field_692 = 0;
      this.field_695 = 0;
      this.field_690 = 0;
      this.field_693 = 4096;
      this.field_696 = 0;
      this.field_691 = 0;
      this.field_694 = 0;
      this.field_697 = 4096;
      this.field_698 = this.field_699 = this.field_700 = 0;
      this.field_701 = this.field_702 = this.field_703 = 0;
      this.field_704 = false;
   }

   // $VF: renamed from: a (bn) void
   public final void method_470(class_57 var1) {
      this.field_686 = var1.field_686;
      this.field_687 = var1.field_687;
      this.field_688 = var1.field_688;
      this.field_689 = var1.field_689;
      this.field_690 = var1.field_690;
      this.field_691 = var1.field_691;
      this.field_692 = var1.field_692;
      this.field_693 = var1.field_693;
      this.field_694 = var1.field_694;
      this.field_695 = var1.field_695;
      this.field_696 = var1.field_696;
      this.field_697 = var1.field_697;
      this.field_698 = var1.field_698;
      this.field_699 = var1.field_699;
      this.field_700 = var1.field_700;
      this.field_701 = var1.field_701;
      this.field_702 = var1.field_702;
      this.field_703 = var1.field_703;
      this.field_704 = var1.field_704;
   }

   // $VF: renamed from: b (bn) void
   public final void method_471(class_57 var1) {
      int var2 = this.field_689;
      int var3 = this.field_692;
      int var4 = this.field_690;
      int var5 = this.field_693;
      int var6 = this.field_691;
      int var7 = this.field_694;
      this.field_698 = this.field_698
         + (
            this.field_686 * ((this.field_689 * var1.field_698 >> 12) + (this.field_692 * var1.field_699 >> 12) + (this.field_695 * var1.field_700 >> 12))
               >> 12
         );
      this.field_699 = this.field_699
         + (
            this.field_687 * ((this.field_690 * var1.field_698 >> 12) + (this.field_693 * var1.field_699 >> 12) + (this.field_696 * var1.field_700 >> 12))
               >> 12
         );
      this.field_700 = this.field_700
         + (
            this.field_688 * ((this.field_691 * var1.field_698 >> 12) + (this.field_694 * var1.field_699 >> 12) + (this.field_697 * var1.field_700 >> 12))
               >> 12
         );
      this.field_686 = this.field_686 * var1.field_686 >> 12;
      this.field_687 = this.field_687 * var1.field_687 >> 12;
      this.field_688 = this.field_688 * var1.field_688 >> 12;
      this.field_689 = (var2 * var1.field_689 >> 12) + (var3 * var1.field_690 >> 12) + (this.field_695 * var1.field_691 >> 12);
      this.field_690 = (var4 * var1.field_689 >> 12) + (var5 * var1.field_690 >> 12) + (this.field_696 * var1.field_691 >> 12);
      this.field_691 = (var6 * var1.field_689 >> 12) + (var7 * var1.field_690 >> 12) + (this.field_697 * var1.field_691 >> 12);
      this.field_692 = (var2 * var1.field_692 >> 12) + (var3 * var1.field_693 >> 12) + (this.field_695 * var1.field_694 >> 12);
      this.field_693 = (var4 * var1.field_692 >> 12) + (var5 * var1.field_693 >> 12) + (this.field_696 * var1.field_694 >> 12);
      this.field_694 = (var6 * var1.field_692 >> 12) + (var7 * var1.field_693 >> 12) + (this.field_697 * var1.field_694 >> 12);
      this.field_695 = (var2 * var1.field_695 >> 12) + (var3 * var1.field_696 >> 12) + (this.field_695 * var1.field_697 >> 12);
      this.field_696 = (var4 * var1.field_695 >> 12) + (var5 * var1.field_696 >> 12) + (this.field_696 * var1.field_697 >> 12);
      this.field_697 = (var6 * var1.field_695 >> 12) + (var7 * var1.field_696 >> 12) + (this.field_697 * var1.field_697 >> 12);
      this.field_704 = true;
   }

   // $VF: renamed from: c (bn) void
   public final void method_472(class_57 var1) {
      long var2 = this.field_689;
      long var4 = this.field_692;
      long var6 = this.field_690;
      long var8 = this.field_693;
      long var10 = this.field_691;
      long var12 = this.field_694;
      this.field_698 = (int)(
         this.field_698
            + (
               this.field_686
                     * (
                        ((long)this.field_689 * var1.field_698 >> 12)
                           + ((long)this.field_692 * var1.field_699 >> 12)
                           + ((long)this.field_695 * var1.field_700 >> 12)
                     )
                  >> 12
            )
      );
      this.field_699 = (int)(
         this.field_699
            + (
               this.field_687
                     * (
                        ((long)this.field_690 * var1.field_698 >> 12)
                           + ((long)this.field_693 * var1.field_699 >> 12)
                           + ((long)this.field_696 * var1.field_700 >> 12)
                     )
                  >> 12
            )
      );
      this.field_700 = (int)(
         this.field_700
            + (
               this.field_688
                     * (
                        ((long)this.field_691 * var1.field_698 >> 12)
                           + ((long)this.field_694 * var1.field_699 >> 12)
                           + ((long)this.field_697 * var1.field_700 >> 12)
                     )
                  >> 12
            )
      );
      this.field_686 = (int)((long)this.field_686 * var1.field_686 >> 12);
      this.field_687 = (int)((long)this.field_687 * var1.field_687 >> 12);
      this.field_688 = (int)((long)this.field_688 * var1.field_688 >> 12);
      this.field_689 = (int)((var2 * var1.field_689 >> 12) + (var4 * var1.field_690 >> 12) + ((long)this.field_695 * var1.field_691 >> 12));
      this.field_690 = (int)((var6 * var1.field_689 >> 12) + (var8 * var1.field_690 >> 12) + ((long)this.field_696 * var1.field_691 >> 12));
      this.field_691 = (int)((var10 * var1.field_689 >> 12) + (var12 * var1.field_690 >> 12) + ((long)this.field_697 * var1.field_691 >> 12));
      this.field_692 = (int)((var2 * var1.field_692 >> 12) + (var4 * var1.field_693 >> 12) + ((long)this.field_695 * var1.field_694 >> 12));
      this.field_693 = (int)((var6 * var1.field_692 >> 12) + (var8 * var1.field_693 >> 12) + ((long)this.field_696 * var1.field_694 >> 12));
      this.field_694 = (int)((var10 * var1.field_692 >> 12) + (var12 * var1.field_693 >> 12) + ((long)this.field_697 * var1.field_694 >> 12));
      this.field_695 = (int)((var2 * var1.field_695 >> 12) + (var4 * var1.field_696 >> 12) + ((long)this.field_695 * var1.field_697 >> 12));
      this.field_696 = (int)((var6 * var1.field_695 >> 12) + (var8 * var1.field_696 >> 12) + ((long)this.field_696 * var1.field_697 >> 12));
      this.field_697 = (int)((var10 * var1.field_695 >> 12) + (var12 * var1.field_696 >> 12) + ((long)this.field_697 * var1.field_697 >> 12));
      int var14 = class_16.method_95(
         (int)(((long)this.field_689 * this.field_689 >> 12) + ((long)this.field_690 * this.field_690 >> 12) + ((long)this.field_691 * this.field_691 >> 12))
      );
      this.field_689 = this.field_689 * var14 >> 12;
      this.field_690 = this.field_690 * var14 >> 12;
      this.field_691 = this.field_691 * var14 >> 12;
      var14 = class_16.method_95(
         (int)(((long)this.field_692 * this.field_692 >> 12) + ((long)this.field_693 * this.field_693 >> 12) + ((long)this.field_694 * this.field_694 >> 12))
      );
      this.field_692 = this.field_692 * var14 >> 12;
      this.field_693 = this.field_693 * var14 >> 12;
      this.field_694 = this.field_694 * var14 >> 12;
      var14 = class_16.method_95(
         (int)(((long)this.field_695 * this.field_695 >> 12) + ((long)this.field_696 * this.field_696 >> 12) + ((long)this.field_697 * this.field_697 >> 12))
      );
      this.field_695 = this.field_695 * var14 >> 12;
      this.field_696 = this.field_696 * var14 >> 12;
      this.field_697 = this.field_697 * var14 >> 12;
      this.field_704 = true;
   }

   // $VF: renamed from: a (bn, bn) bn
   public final class_57 method_473(class_57 var1, class_57 var2) {
      var2.field_698 = this.field_698
         + (
            this.field_686 * ((this.field_689 * var1.field_698 >> 12) + (this.field_692 * var1.field_699 >> 12) + (this.field_695 * var1.field_700 >> 12))
               >> 12
         );
      var2.field_699 = this.field_699
         + (
            this.field_687 * ((this.field_690 * var1.field_698 >> 12) + (this.field_693 * var1.field_699 >> 12) + (this.field_696 * var1.field_700 >> 12))
               >> 12
         );
      var2.field_700 = this.field_700
         + (
            this.field_688 * ((this.field_691 * var1.field_698 >> 12) + (this.field_694 * var1.field_699 >> 12) + (this.field_697 * var1.field_700 >> 12))
               >> 12
         );
      var2.field_686 = this.field_686 * var1.field_686 >> 12;
      var2.field_687 = this.field_687 * var1.field_687 >> 12;
      var2.field_688 = this.field_688 * var1.field_688 >> 12;
      var2.field_689 = (this.field_689 * var1.field_689 >> 12) + (this.field_692 * var1.field_690 >> 12) + (this.field_695 * var1.field_691 >> 12);
      var2.field_690 = (this.field_690 * var1.field_689 >> 12) + (this.field_693 * var1.field_690 >> 12) + (this.field_696 * var1.field_691 >> 12);
      var2.field_691 = (this.field_691 * var1.field_689 >> 12) + (this.field_694 * var1.field_690 >> 12) + (this.field_697 * var1.field_691 >> 12);
      var2.field_692 = (this.field_689 * var1.field_692 >> 12) + (this.field_692 * var1.field_693 >> 12) + (this.field_695 * var1.field_694 >> 12);
      var2.field_693 = (this.field_690 * var1.field_692 >> 12) + (this.field_693 * var1.field_693 >> 12) + (this.field_696 * var1.field_694 >> 12);
      var2.field_694 = (this.field_691 * var1.field_692 >> 12) + (this.field_694 * var1.field_693 >> 12) + (this.field_697 * var1.field_694 >> 12);
      var2.field_695 = (this.field_689 * var1.field_695 >> 12) + (this.field_692 * var1.field_696 >> 12) + (this.field_695 * var1.field_697 >> 12);
      var2.field_696 = (this.field_690 * var1.field_695 >> 12) + (this.field_693 * var1.field_696 >> 12) + (this.field_696 * var1.field_697 >> 12);
      var2.field_697 = (this.field_691 * var1.field_695 >> 12) + (this.field_694 * var1.field_696 >> 12) + (this.field_697 * var1.field_697 >> 12);
      var2.field_704 = true;
      return var2;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_474(int var1, int var2, int var3) {
      this.field_698 += var1;
      this.field_699 += var2;
      this.field_700 += var3;
   }

   // $VF: renamed from: a (x) void
   public final void method_475(class_3 var1) {
      this.field_698 = this.field_698 + var1.field_37;
      this.field_699 = this.field_699 + var1.field_38;
      this.field_700 = this.field_700 + var1.field_39;
   }

   // $VF: renamed from: b (int, int, int) void
   public final void method_476(int var1, int var2, int var3) {
      this.field_698 = var1;
      this.field_699 = var2;
      this.field_700 = var3;
   }

   // $VF: renamed from: b (x) void
   public final void method_477(class_3 var1) {
      this.field_698 = var1.field_37;
      this.field_699 = var1.field_38;
      this.field_700 = var1.field_39;
   }

   // $VF: renamed from: a (int) void
   public final void method_478(int var1) {
      this.field_698 = this.field_698 + (this.field_695 * var1 >> 12);
      this.field_699 = this.field_699 + (this.field_696 * var1 >> 12);
      this.field_700 = this.field_700 + (this.field_697 * var1 >> 12);
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_479(class_3 var1) {
      var1.field_37 = this.field_698;
      var1.field_38 = this.field_699;
      var1.field_39 = this.field_700;
      return var1;
   }

   // $VF: renamed from: a () x
   public final class_3 method_480() {
      return new class_3(this.field_698, this.field_699, this.field_700);
   }

   // $VF: renamed from: b (x) x
   public final class_3 method_481(class_3 var1) {
      var1.field_37 = this.field_695;
      var1.field_38 = this.field_696;
      var1.field_39 = this.field_697;
      return var1;
   }

   // $VF: renamed from: c (x) x
   public final class_3 method_482(class_3 var1) {
      var1.field_37 = this.field_692;
      var1.field_38 = this.field_693;
      var1.field_39 = this.field_694;
      return var1;
   }

   // $VF: renamed from: b () x
   public final class_3 method_483() {
      return new class_3(this.field_692, this.field_693, this.field_694);
   }

   // $VF: renamed from: d (x) x
   public final class_3 method_484(class_3 var1) {
      var1.field_37 = this.field_689;
      var1.field_38 = this.field_690;
      var1.field_39 = this.field_691;
      return var1;
   }

   // $VF: renamed from: a (short) void
   public final void method_485(short var1) {
      if (this.field_685 != var1) {
         this.field_685 = var1;
         this.method_493();
         this.field_704 = false;
      }
   }

   // $VF: renamed from: c (int, int, int) void
   public final void method_486(int var1, int var2, int var3) {
      if (this.field_704) {
         this.method_493();
         this.field_704 = false;
      }

      this.field_701 += var1;
      this.field_702 += var2;
      this.field_703 += var3;
      this.method_491(this.field_701, this.field_702, this.field_703);
   }

   // $VF: renamed from: b (int) void
   public final void method_487(int var1) {
      int var2 = class_16.method_91(var1);
      int var3 = class_16.method_92(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_695 >> 12) * this.field_697 >> 12;
      int var6 = (var4 * this.field_696 >> 12) * this.field_697 >> 12;
      int var7 = (var4 * this.field_695 >> 12) * this.field_696 >> 12;
      int var8 = var2 * this.field_696 >> 12;
      int var9 = var2 * this.field_695 >> 12;
      int var10 = var2 * this.field_697 >> 12;
      int var11 = ((var4 * this.field_695 >> 12) * this.field_695 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_696 >> 12) * this.field_696 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_697 >> 12) * this.field_697 >> 12) + var3;
      int var20 = this.field_689;
      int var21 = this.field_690;
      this.field_689 = (this.field_689 * var11 >> 12) + (this.field_690 * var12 >> 12) + (this.field_691 * var13 >> 12);
      this.field_690 = (var20 * var14 >> 12) + (this.field_690 * var15 >> 12) + (this.field_691 * var16 >> 12);
      this.field_691 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_691 * var19 >> 12);
      this.field_692 = (this.field_696 * this.field_691 >> 12) - (this.field_697 * this.field_690 >> 12);
      this.field_693 = (this.field_697 * this.field_689 >> 12) - (this.field_695 * this.field_691 >> 12);
      this.field_694 = (this.field_695 * this.field_690 >> 12) - (this.field_696 * this.field_689 >> 12);
      int var22 = class_16.method_95(
         (this.field_692 * this.field_692 >> 12) + (this.field_693 * this.field_693 >> 12) + (this.field_694 * this.field_694 >> 12)
      );
      this.field_692 = this.field_692 * var22 >> 12;
      this.field_693 = this.field_693 * var22 >> 12;
      this.field_694 = this.field_694 * var22 >> 12;
      this.field_689 = (this.field_697 * this.field_693 >> 12) - (this.field_696 * this.field_694 >> 12);
      this.field_690 = (this.field_695 * this.field_694 >> 12) - (this.field_697 * this.field_692 >> 12);
      this.field_691 = (this.field_696 * this.field_692 >> 12) - (this.field_695 * this.field_693 >> 12);
      this.field_704 = true;
   }

   // $VF: renamed from: c (int) void
   public final void method_488(int var1) {
      int var2 = class_16.method_91(var1);
      int var3 = class_16.method_92(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_692 >> 12) * this.field_694 >> 12;
      int var6 = (var4 * this.field_693 >> 12) * this.field_694 >> 12;
      int var7 = (var4 * this.field_692 >> 12) * this.field_693 >> 12;
      int var8 = var2 * this.field_693 >> 12;
      int var9 = var2 * this.field_692 >> 12;
      int var10 = var2 * this.field_694 >> 12;
      int var11 = ((var4 * this.field_692 >> 12) * this.field_692 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_693 >> 12) * this.field_693 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_694 >> 12) * this.field_694 >> 12) + var3;
      int var20 = this.field_695;
      int var21 = this.field_696;
      this.field_695 = (this.field_695 * var11 >> 12) + (this.field_696 * var12 >> 12) + (this.field_697 * var13 >> 12);
      this.field_696 = (var20 * var14 >> 12) + (this.field_696 * var15 >> 12) + (this.field_697 * var16 >> 12);
      this.field_697 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_697 * var19 >> 12);
      this.field_689 = (this.field_697 * this.field_693 >> 12) - (this.field_696 * this.field_694 >> 12);
      this.field_690 = (this.field_695 * this.field_694 >> 12) - (this.field_697 * this.field_692 >> 12);
      this.field_691 = (this.field_696 * this.field_692 >> 12) - (this.field_695 * this.field_693 >> 12);
      int var22 = class_16.method_95(
         (this.field_689 * this.field_689 >> 12) + (this.field_690 * this.field_690 >> 12) + (this.field_691 * this.field_691 >> 12)
      );
      this.field_689 = this.field_689 * var22 >> 12;
      this.field_690 = this.field_690 * var22 >> 12;
      this.field_691 = this.field_691 * var22 >> 12;
      this.field_695 = (this.field_694 * this.field_690 >> 12) - (this.field_693 * this.field_691 >> 12);
      this.field_696 = (this.field_692 * this.field_691 >> 12) - (this.field_694 * this.field_689 >> 12);
      this.field_697 = (this.field_693 * this.field_689 >> 12) - (this.field_692 * this.field_690 >> 12);
      this.field_704 = true;
   }

   // $VF: renamed from: d (int) void
   public final void method_489(int var1) {
      int var2 = class_16.method_91(var1);
      int var3 = class_16.method_92(var1);
      int var4;
      int var5 = ((var4 = 4096 - var3) * this.field_689 >> 12) * this.field_691 >> 12;
      int var6 = (var4 * this.field_690 >> 12) * this.field_691 >> 12;
      int var7 = (var4 * this.field_689 >> 12) * this.field_690 >> 12;
      int var8 = var2 * this.field_690 >> 12;
      int var9 = var2 * this.field_689 >> 12;
      int var10 = var2 * this.field_691 >> 12;
      int var11 = ((var4 * this.field_689 >> 12) * this.field_689 >> 12) + var3;
      int var12 = var7 - var10;
      int var13 = var5 + var8;
      int var14 = var7 + var10;
      int var15 = ((var4 * this.field_690 >> 12) * this.field_690 >> 12) + var3;
      int var16 = var6 - var9;
      int var17 = var5 - var8;
      int var18 = var6 + var9;
      int var19 = ((var4 * this.field_691 >> 12) * this.field_691 >> 12) + var3;
      int var20 = this.field_692;
      int var21 = this.field_693;
      this.field_692 = (this.field_692 * var11 >> 12) + (this.field_693 * var12 >> 12) + (this.field_694 * var13 >> 12);
      this.field_693 = (var20 * var14 >> 12) + (this.field_693 * var15 >> 12) + (this.field_694 * var16 >> 12);
      this.field_694 = (var20 * var17 >> 12) + (var21 * var18 >> 12) + (this.field_694 * var19 >> 12);
      this.field_695 = (this.field_690 * this.field_694 >> 12) - (this.field_691 * this.field_693 >> 12);
      this.field_696 = (this.field_691 * this.field_692 >> 12) - (this.field_689 * this.field_694 >> 12);
      this.field_697 = (this.field_689 * this.field_693 >> 12) - (this.field_690 * this.field_692 >> 12);
      int var22 = class_16.method_95(
         (this.field_695 * this.field_695 >> 12) + (this.field_696 * this.field_696 >> 12) + (this.field_697 * this.field_697 >> 12)
      );
      this.field_695 = this.field_695 * var22 >> 12;
      this.field_696 = this.field_696 * var22 >> 12;
      this.field_697 = this.field_697 * var22 >> 12;
      this.field_692 = (this.field_696 * this.field_691 >> 12) - (this.field_697 * this.field_690 >> 12);
      this.field_693 = (this.field_697 * this.field_689 >> 12) - (this.field_695 * this.field_691 >> 12);
      this.field_694 = (this.field_695 * this.field_690 >> 12) - (this.field_696 * this.field_689 >> 12);
      this.field_704 = true;
   }

   // $VF: renamed from: e (int) void
   public final void method_490(int var1) {
      this.method_491(this.field_701, var1, this.field_703);
   }

   // $VF: renamed from: d (int, int, int) void
   public final void method_491(int var1, int var2, int var3) {
      this.field_701 = var1;
      this.field_702 = var2;
      this.field_703 = var3;
      this.field_704 = false;
      int var4 = class_16.method_91(var1);
      int var5 = class_16.method_91(var2);
      int var6 = class_16.method_91(var3);
      int var7 = class_16.method_92(var1);
      int var8 = class_16.method_92(var2);
      int var9 = class_16.method_92(var3);
      switch (this.field_685) {
         case 0:
            int var17 = var7 * var9 >> 12;
            int var22 = var9 * var4 >> 12;
            int var25 = var5 * var6 >> 12;
            this.field_689 = var8 * var9 >> 12;
            this.field_692 = -(var8 * var6 >> 12);
            this.field_695 = var5;
            this.field_690 = (var22 * var5 >> 12) + (var7 * var6 >> 12);
            this.field_693 = var17 - (var25 * var4 >> 12);
            this.field_696 = -(var8 * var4 >> 12);
            this.field_691 = -(var17 * var5 >> 12) + (var4 * var6 >> 12);
            this.field_694 = var22 + (var25 * var7 >> 12);
            this.field_697 = var7 * var8 >> 12;
            return;
         case 1:
            int var16 = var8 * var6 >> 12;
            int var21 = var5 * var6 >> 12;
            this.field_689 = var8 * var9 >> 12;
            this.field_692 = -var6;
            this.field_695 = var9 * var5 >> 12;
            this.field_690 = (var4 * var5 >> 12) + (var16 * var7 >> 12);
            this.field_693 = var7 * var9 >> 12;
            this.field_696 = -(var8 * var4 >> 12) + (var21 * var7 >> 12);
            this.field_691 = -(var7 * var5 >> 12) + (var16 * var4 >> 12);
            this.field_694 = var9 * var4 >> 12;
            this.field_697 = (var7 * var8 >> 12) + (var21 * var4 >> 12);
            return;
         case 2:
            int var15 = var8 * var9 >> 12;
            int var20 = var4 * var6 >> 12;
            int var24 = var5 * var9 >> 12;
            this.field_689 = var15 + (var20 * var5 >> 12);
            this.field_692 = (var24 * var4 >> 12) - (var8 * var6 >> 12);
            this.field_695 = var7 * var5 >> 12;
            this.field_690 = var7 * var6 >> 12;
            this.field_693 = var7 * var9 >> 12;
            this.field_696 = -var4;
            this.field_691 = -var24 + (var20 * var8 >> 12);
            this.field_694 = (var15 * var4 >> 12) + (var5 * var6 >> 12);
            this.field_697 = var7 * var8 >> 12;
            return;
         case 3:
            int var14 = var4 * var5 >> 12;
            int var19 = var7 * var8 >> 12;
            int var23 = var8 * var4 >> 12;
            this.field_689 = var8 * var9 >> 12;
            this.field_692 = var14 - (var19 * var6 >> 12);
            this.field_695 = (var7 * var5 >> 12) + (var23 * var6 >> 12);
            this.field_690 = var6;
            this.field_693 = var7 * var9 >> 12;
            this.field_696 = -(var9 * var4 >> 12);
            this.field_691 = -(var9 * var5 >> 12);
            this.field_694 = var23 + ((var7 * var5 >> 12) * var6 >> 12);
            this.field_697 = var19 - (var14 * var6 >> 12);
            return;
         case 4:
            int var13 = var4 * var5 >> 12;
            int var18 = var8 * var4 >> 12;
            this.field_689 = (var8 * var9 >> 12) - (var13 * var6 >> 12);
            this.field_692 = -(var7 * var6 >> 12);
            this.field_695 = (var9 * var5 >> 12) + (var18 * var6 >> 12);
            this.field_690 = (var13 * var9 >> 12) + (var8 * var6 >> 12);
            this.field_693 = var7 * var9 >> 12;
            this.field_696 = -(var18 * var9 >> 12) + (var5 * var6 >> 12);
            this.field_691 = -(var7 * var5 >> 12);
            this.field_694 = var4;
            this.field_697 = var7 * var8 >> 12;
            return;
         case 5:
            int var10 = var5 * var6 >> 12;
            boolean var11 = false;
            int var12 = var9 * var5 >> 12;
            this.field_689 = var8 * var9 >> 12;
            this.field_692 = (var12 * var4 >> 12) - (var7 * var6 >> 12);
            this.field_695 = (var12 * var7 >> 12) + (var4 * var6 >> 12);
            this.field_690 = var8 * var6 >> 12;
            this.field_693 = (var7 * var9 >> 12) + (var10 * var4 >> 12);
            this.field_696 = -(var9 * var4 >> 12) + (var10 * var7 >> 12);
            this.field_691 = -var5;
            this.field_694 = var8 * var4 >> 12;
            this.field_697 = var7 * var8 >> 12;
      }
   }

   // $VF: renamed from: a () int
   public final int method_492() {
      if (this.field_704) {
         this.method_493();
         this.field_704 = false;
      }

      return this.field_702;
   }

   // $VF: renamed from: b () void
   private void method_493() {
      switch (this.field_685) {
         case 0:
            this.field_702 = class_16.method_93(this.field_695);
            if (this.field_702 < 2048) {
               if (this.field_702 > -2048) {
                  this.field_701 = class_16.method_94(-this.field_696, this.field_697);
                  this.field_703 = class_16.method_94(-this.field_692, this.field_689);
                  return;
               }

               this.field_701 = -class_16.method_94(this.field_690, this.field_693);
               this.field_703 = 0;
               return;
            }

            this.field_701 = class_16.method_94(this.field_690, this.field_693);
            this.field_703 = 0;
            return;
         case 1:
            this.field_703 = class_16.method_93(-this.field_692);
            if (this.field_703 < 2048) {
               if (this.field_703 > -2048) {
                  this.field_701 = class_16.method_94(this.field_694, this.field_693);
                  this.field_702 = class_16.method_94(this.field_695, this.field_689);
                  return;
               }

               this.field_701 = -class_16.method_94(-this.field_691, this.field_697);
               this.field_702 = 0;
               return;
            }

            this.field_701 = class_16.method_94(-this.field_691, this.field_697);
            this.field_702 = 0;
            return;
         case 2:
            this.field_701 = class_16.method_93(-this.field_696);
            if (this.field_701 < 2048) {
               if (this.field_701 > -2048) {
                  this.field_702 = class_16.method_94(this.field_695, this.field_697);
                  this.field_703 = class_16.method_94(this.field_690, this.field_693);
                  return;
               }

               this.field_702 = -class_16.method_94(-this.field_692, this.field_689);
               this.field_703 = 0;
               return;
            }

            this.field_702 = class_16.method_94(-this.field_692, this.field_689);
            this.field_703 = 0;
            return;
         case 3:
            this.field_703 = class_16.method_93(this.field_690);
            if (this.field_703 < 2048) {
               if (this.field_703 > -2048) {
                  this.field_702 = class_16.method_94(-this.field_691, this.field_689);
                  this.field_701 = class_16.method_94(-this.field_696, this.field_693);
                  return;
               }

               this.field_702 = -class_16.method_94(this.field_694, this.field_697);
               this.field_701 = 0;
               return;
            }

            this.field_702 = class_16.method_94(this.field_694, this.field_697);
            this.field_701 = 0;
            return;
         case 4:
            this.field_701 = class_16.method_93(this.field_694);
            if (this.field_701 < 2048) {
               if (this.field_701 > -2048) {
                  this.field_703 = class_16.method_94(-this.field_692, this.field_693);
                  this.field_702 = class_16.method_94(-this.field_691, this.field_697);
                  return;
               }

               this.field_703 = -class_16.method_94(this.field_695, this.field_689);
               this.field_702 = 0;
               return;
            }

            this.field_703 = class_16.method_94(this.field_695, this.field_689);
            this.field_702 = 0;
            return;
         case 5:
            this.field_702 = class_16.method_93(-this.field_691);
            if (this.field_702 < 2048) {
               if (this.field_702 > -2048) {
                  this.field_703 = class_16.method_94(this.field_690, this.field_689);
                  this.field_701 = class_16.method_94(this.field_694, this.field_697);
                  return;
               }

               this.field_703 = -class_16.method_94(-this.field_692, this.field_695);
               this.field_701 = 0;
               return;
            } else {
               this.field_703 = class_16.method_94(-this.field_692, this.field_695);
               this.field_701 = 0;
            }
      }
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_494(int var1, int var2, int var3, int var4) {
      this.field_689 = 4096 - (2 * var2 * var2 >> 12) - (2 * var3 * var3 >> 12);
      this.field_692 = (2 * var1 * var2 >> 12) - (2 * var4 * var3 >> 12);
      this.field_695 = (2 * var1 * var3 >> 12) + (2 * var4 * var2 >> 12);
      this.field_690 = (2 * var1 * var2 >> 12) + (2 * var4 * var3 >> 12);
      this.field_693 = 4096 - (2 * var1 * var1 >> 12) - (2 * var3 * var3 >> 12);
      this.field_696 = (2 * var2 * var3 >> 12) - (2 * var4 * var1 >> 12);
      this.field_691 = (2 * var1 * var3 >> 12) - (2 * var4 * var2 >> 12);
      this.field_694 = (2 * var4 * var1 >> 12) + (2 * var2 * var3 >> 12);
      this.field_697 = 4096 - (2 * var1 * var1 >> 12) - (2 * var2 * var2 >> 12);
      this.field_704 = true;
   }

   // $VF: renamed from: a (a) void
   public final void method_495(class_123 var1) {
      this.method_494(var1.field_1509, var1.field_1510, var1.field_1511, var1.field_1512);
   }

   // $VF: renamed from: a (int) int
   private int method_496(int var1) {
      return var1 < 2 ? var1 + 1 : 0;
   }

   // $VF: renamed from: b (int) int
   private final int method_497(int var1) {
      switch (var1) {
         case 0:
            return this.field_689;
         case 1:
            return this.field_690;
         case 2:
            return this.field_691;
         case 3:
            return this.field_692;
         case 4:
            return this.field_693;
         case 5:
            return this.field_694;
         case 6:
            return this.field_695;
         case 7:
            return this.field_696;
         case 8:
            return this.field_697;
         default:
            return 0;
      }
   }

   // $VF: renamed from: a (a) a
   public final class_123 method_498(class_123 var1) {
      int var2;
      if ((var2 = 4096 + this.field_689 + this.field_693 + this.field_697) > 0) {
         int var7 = class_16.method_96(var2);
         var1.field_1512 = var7 >> 1;
         var7 = 8388608 / var7;
         var1.field_1509 = (this.field_694 - this.field_696) * var7 >> 12;
         var1.field_1510 = (this.field_695 - this.field_691) * var7 >> 12;
         var1.field_1511 = (this.field_690 - this.field_692) * var7 >> 12;
         return var1;
      } else {
         byte var3 = 0;
         if (this.field_693 > this.field_689) {
            var3 = 1;
         }

         if (this.field_697 > this.method_497(var3 * 4)) {
            var3 = 2;
         }

         int var4 = this.method_496(var3);
         int var5 = this.method_496(var4);
         int var6 = class_16.method_96(4096 + this.method_497(var3 * 4) - this.method_497(var4 * 4) - this.method_497(var5 * 4));
         switch (var3) {
            case 0:
               var1.field_1509 = var6 >> 1;
               break;
            case 1:
               var1.field_1510 = var6 >> 1;
               break;
            case 2:
               var1.field_1511 = var6 >> 1;
         }

         if (var6 != 0) {
            var6 = 8388608 / var6;
         }

         switch (var4) {
            case 0:
               var1.field_1509 = (this.method_497(var3 + var4 * 3) + this.method_497(var4 + var3 * 3)) * var6 >> 12;
               break;
            case 1:
               var1.field_1510 = (this.method_497(var3 + var4 * 3) + this.method_497(var4 + var3 * 3)) * var6 >> 12;
               break;
            case 2:
               var1.field_1511 = (this.method_497(var3 + var4 * 3) + this.method_497(var4 + var3 * 3)) * var6 >> 12;
         }

         switch (var5) {
            case 0:
               var1.field_1509 = (this.method_497(var3 + var5 * 3) + this.method_497(var5 + var3 * 3)) * var6 >> 12;
               break;
            case 1:
               var1.field_1510 = (this.method_497(var3 + var5 * 3) + this.method_497(var5 + var3 * 3)) * var6 >> 12;
               break;
            case 2:
               var1.field_1511 = (this.method_497(var3 + var5 * 3) + this.method_497(var5 + var3 * 3)) * var6 >> 12;
         }

         var1.field_1512 = (this.method_497(var4 + var5 * 3) - this.method_497(var5 + var4 * 3)) * var6 >> 12;
         return var1;
      }
   }

   // $VF: renamed from: a () a
   public final class_123 method_499() {
      return this.method_498(new class_123());
   }

   // $VF: renamed from: e (int, int, int) void
   public final void method_500(int var1, int var2, int var3) {
      this.field_686 = this.field_686 * var1 >> 12;
      this.field_687 = this.field_687 * var2 >> 12;
      this.field_688 = this.field_688 * var3 >> 12;
   }

   // $VF: renamed from: f (int, int, int) void
   public final void method_501(int var1, int var2, int var3) {
      this.field_686 = var1;
      this.field_687 = var2;
      this.field_688 = var3;
   }

   // $VF: renamed from: e (x) x
   public final class_3 method_502(class_3 var1) {
      var1.field_37 = this.field_686;
      var1.field_38 = this.field_687;
      var1.field_39 = this.field_688;
      return var1;
   }

   // $VF: renamed from: a (bn) bn
   public final class_57 method_503(class_57 var1) {
      var1.field_686 = 16777216 / this.field_686;
      var1.field_687 = 16777216 / this.field_687;
      var1.field_688 = 16777216 / this.field_688;
      var1.field_689 = this.field_689;
      var1.field_692 = this.field_690;
      var1.field_695 = this.field_691;
      var1.field_690 = this.field_692;
      var1.field_693 = this.field_693;
      var1.field_696 = this.field_694;
      var1.field_691 = this.field_695;
      var1.field_694 = this.field_696;
      var1.field_697 = this.field_697;
      var1.field_698 = var1.field_686
            * (-(var1.field_689 * this.field_698 >> 12) - (var1.field_692 * this.field_699 >> 12) - (var1.field_695 * this.field_700 >> 12))
         >> 12;
      var1.field_699 = var1.field_687
            * (-(var1.field_690 * this.field_698 >> 12) - (var1.field_693 * this.field_699 >> 12) - (var1.field_696 * this.field_700 >> 12))
         >> 12;
      var1.field_700 = var1.field_688
            * (-(var1.field_691 * this.field_698 >> 12) - (var1.field_694 * this.field_699 >> 12) - (var1.field_697 * this.field_700 >> 12))
         >> 12;
      var1.field_704 = true;
      return var1;
   }

   // $VF: renamed from: a (x, x, x) void
   public final void method_504(class_3 var1, class_3 var2, class_3 var3) {
      this.field_689 = var1.field_37;
      this.field_692 = var2.field_37;
      this.field_695 = var3.field_37;
      this.field_690 = var1.field_38;
      this.field_693 = var2.field_38;
      this.field_696 = var3.field_38;
      this.field_691 = var1.field_39;
      this.field_694 = var2.field_39;
      this.field_697 = var3.field_39;
      this.field_704 = true;
   }

   // $VF: renamed from: a (float[]) void
   public final void method_505(float[] var1) {
      var1[0] = this.field_686 * this.field_689 * 5.9604645E-8F;
      var1[1] = this.field_687 * this.field_692 * 5.9604645E-8F;
      var1[2] = this.field_688 * this.field_695 * 5.9604645E-8F;
      var1[3] = this.field_698;
      var1[4] = this.field_686 * this.field_690 * 5.9604645E-8F;
      var1[5] = this.field_687 * this.field_693 * 5.9604645E-8F;
      var1[6] = this.field_688 * this.field_696 * 5.9604645E-8F;
      var1[7] = this.field_699;
      var1[8] = this.field_686 * this.field_691 * 5.9604645E-8F;
      var1[9] = this.field_687 * this.field_694 * 5.9604645E-8F;
      var1[10] = this.field_688 * this.field_697 * 5.9604645E-8F;
      var1[11] = this.field_700;
      var1[12] = 0.0F;
      var1[13] = 0.0F;
      var1[14] = 0.0F;
      var1[15] = 1.0F;
   }

   public final String toString() {
      String var1 = "";
      var1 = var1
         + "|\t"
         + (this.field_686 * this.field_689 >> 12)
         + ",\t"
         + (this.field_687 * this.field_692 >> 12)
         + ",\t"
         + (this.field_688 * this.field_695 >> 12)
         + ",\t"
         + this.field_698
         + "\t|\n";
      var1 = var1
         + "|\t"
         + (this.field_686 * this.field_690 >> 12)
         + ",\t"
         + (this.field_687 * this.field_693 >> 12)
         + ",\t"
         + (this.field_688 * this.field_696 >> 12)
         + ",\t"
         + this.field_699
         + "\t|\n";
      return var1
         + "|\t"
         + (this.field_686 * this.field_691 >> 12)
         + ",\t"
         + (this.field_687 * this.field_694 >> 12)
         + ",\t"
         + (this.field_688 * this.field_697 >> 12)
         + ",\t"
         + this.field_700
         + "\t|\n";
   }

   // $VF: renamed from: f (x) x
   public final class_3 method_506(class_3 var1) {
      int var2 = var1.field_37;
      int var3 = var1.field_38;
      int var4 = var1.field_39;
      var1.field_37 = ((this.field_686 * this.field_689 >> 12) * var2 >> 12)
         + ((this.field_687 * this.field_692 >> 12) * var3 >> 12)
         + ((this.field_688 * this.field_695 >> 12) * var4 >> 12)
         + this.field_698;
      var1.field_38 = ((this.field_686 * this.field_690 >> 12) * var2 >> 12)
         + ((this.field_687 * this.field_693 >> 12) * var3 >> 12)
         + ((this.field_688 * this.field_696 >> 12) * var4 >> 12)
         + this.field_699;
      var1.field_39 = ((this.field_686 * this.field_691 >> 12) * var2 >> 12)
         + ((this.field_687 * this.field_694 >> 12) * var3 >> 12)
         + ((this.field_688 * this.field_697 >> 12) * var4 >> 12)
         + this.field_700;
      return var1;
   }

   // $VF: renamed from: a (x, x) x
   public final class_3 method_507(class_3 var1, class_3 var2) {
      long var3 = ((long)(this.field_686 * this.field_689 >> 12) * var1.field_37 >> 12)
         + ((long)(this.field_687 * this.field_692 >> 12) * var1.field_38 >> 12)
         + ((long)(this.field_688 * this.field_695 >> 12) * var1.field_39 >> 12)
         + this.field_698;
      long var5 = ((long)(this.field_686 * this.field_690 >> 12) * var1.field_37 >> 12)
         + ((long)(this.field_687 * this.field_693 >> 12) * var1.field_38 >> 12)
         + ((long)(this.field_688 * this.field_696 >> 12) * var1.field_39 >> 12)
         + this.field_699;
      long var7 = ((long)(this.field_686 * this.field_691 >> 12) * var1.field_37 >> 12)
         + ((long)(this.field_687 * this.field_694 >> 12) * var1.field_38 >> 12)
         + ((long)(this.field_688 * this.field_697 >> 12) * var1.field_39 >> 12)
         + this.field_700;
      var2.field_37 = (int)var3;
      var2.field_38 = (int)var5;
      var2.field_39 = (int)var7;
      return var2;
   }

   // $VF: renamed from: b (x, x) x
   public final class_3 method_508(class_3 var1, class_3 var2) {
      var2.field_37 = (this.field_689 * var1.field_37 >> 12) + (this.field_692 * var1.field_38 >> 12) + (this.field_695 * var1.field_39 >> 12);
      var2.field_38 = (this.field_690 * var1.field_37 >> 12) + (this.field_693 * var1.field_38 >> 12) + (this.field_696 * var1.field_39 >> 12);
      var2.field_39 = (this.field_691 * var1.field_37 >> 12) + (this.field_694 * var1.field_38 >> 12) + (this.field_697 * var1.field_39 >> 12);
      return var2;
   }

   // $VF: renamed from: c (x, x) x
   public final class_3 method_509(class_3 var1, class_3 var2) {
      long var3 = ((long)this.field_689 * var1.field_37 >> 12) + ((long)this.field_692 * var1.field_38 >> 12) + ((long)this.field_695 * var1.field_39 >> 12);
      long var5 = ((long)this.field_690 * var1.field_37 >> 12) + ((long)this.field_693 * var1.field_38 >> 12) + ((long)this.field_696 * var1.field_39 >> 12);
      long var7 = ((long)this.field_691 * var1.field_37 >> 12) + ((long)this.field_694 * var1.field_38 >> 12) + ((long)this.field_697 * var1.field_39 >> 12);
      var2.field_37 = (int)var3;
      var2.field_38 = (int)var5;
      var2.field_39 = (int)var7;
      return var2;
   }

   // $VF: renamed from: a (x[], x[]) x[]
   public final class_3[] method_510(class_3[] var1, class_3[] var2) {
      for (int var3 = var2.length - 1; var3 >= 0; var3--) {
         var2[var3].field_37 = (this.field_689 * var1[var3].field_37 >> 12)
            + (this.field_692 * var1[var3].field_38 >> 12)
            + (this.field_695 * var1[var3].field_39 >> 12);
         var2[var3].field_38 = (this.field_690 * var1[var3].field_37 >> 12)
            + (this.field_693 * var1[var3].field_38 >> 12)
            + (this.field_696 * var1[var3].field_39 >> 12);
         var2[var3].field_39 = (this.field_691 * var1[var3].field_37 >> 12)
            + (this.field_694 * var1[var3].field_38 >> 12)
            + (this.field_697 * var1[var3].field_39 >> 12);
      }

      return var2;
   }

   // $VF: renamed from: g (x) x
   public final class_3 method_511(class_3 var1) {
      int var2 = 16777216 / this.field_686;
      int var3 = 16777216 / this.field_687;
      int var4 = 16777216 / this.field_688;
      int var5 = var2 * (-(this.field_689 * this.field_698 >> 12) - (this.field_690 * this.field_699 >> 12) - (this.field_691 * this.field_700 >> 12)) >> 12;
      int var6 = var3 * (-(this.field_692 * this.field_698 >> 12) - (this.field_693 * this.field_699 >> 12) - (this.field_694 * this.field_700 >> 12)) >> 12;
      int var7 = var4 * (-(this.field_695 * this.field_698 >> 12) - (this.field_696 * this.field_699 >> 12) - (this.field_697 * this.field_700 >> 12)) >> 12;
      int var8 = var1.field_37;
      int var9 = var1.field_38;
      int var10 = var1.field_39;
      var1.field_37 = ((var2 * this.field_689 >> 12) * var8 >> 12)
         + ((var3 * this.field_690 >> 12) * var9 >> 12)
         + ((var4 * this.field_691 >> 12) * var10 >> 12)
         + var5;
      var1.field_38 = ((var2 * this.field_692 >> 12) * var8 >> 12)
         + ((var3 * this.field_693 >> 12) * var9 >> 12)
         + ((var4 * this.field_694 >> 12) * var10 >> 12)
         + var6;
      var1.field_39 = ((var2 * this.field_695 >> 12) * var8 >> 12)
         + ((var3 * this.field_696 >> 12) * var9 >> 12)
         + ((var4 * this.field_697 >> 12) * var10 >> 12)
         + var7;
      return var1;
   }

   // $VF: renamed from: c (x) void
   public final void method_512(class_3 var1) {
      field_705.method_9(var1);
      field_705.method_22();
      this.field_695 = field_705.field_37;
      this.field_696 = field_705.field_38;
      this.field_697 = field_705.field_39;
      this.field_692 = 0;
      this.field_693 = 4096;
      this.field_694 = 0;
      this.field_689 = (this.field_693 * this.field_697 >> 12) - (this.field_694 * this.field_696 >> 12);
      this.field_690 = (this.field_694 * this.field_695 >> 12) - (this.field_692 * this.field_697 >> 12);
      this.field_691 = (this.field_692 * this.field_696 >> 12) - (this.field_693 * this.field_695 >> 12);
      field_705.field_37 = this.field_689;
      field_705.field_38 = this.field_690;
      field_705.field_39 = this.field_691;
      field_705.method_22();
      this.field_689 = field_705.field_37;
      this.field_690 = field_705.field_38;
      this.field_691 = field_705.field_39;
      this.field_692 = (this.field_696 * this.field_691 >> 12) - (this.field_697 * this.field_690 >> 12);
      this.field_693 = (this.field_697 * this.field_689 >> 12) - (this.field_695 * this.field_691 >> 12);
      this.field_694 = (this.field_695 * this.field_690 >> 12) - (this.field_696 * this.field_689 >> 12);
      field_705.field_37 = this.field_692;
      field_705.field_38 = this.field_693;
      field_705.field_39 = this.field_694;
      field_705.method_22();
      this.field_692 = field_705.field_37;
      this.field_693 = field_705.field_38;
      this.field_694 = field_705.field_39;
   }
}
