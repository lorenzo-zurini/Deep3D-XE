// $VF: renamed from: bj
public final class class_65 extends class_61 {
   // $VF: renamed from: a long
   private long field_818;
   // $VF: renamed from: b long
   private long field_819;
   // $VF: renamed from: c long
   private long field_820;
   // $VF: renamed from: d long
   private long field_821;
   // $VF: renamed from: a int
   private int field_822;
   // $VF: renamed from: a boolean
   public boolean field_823;
   // $VF: renamed from: a c
   private class_104 field_824;
   // $VF: renamed from: a an
   private class_106 field_825;
   // $VF: renamed from: a ck
   private class_39 field_826;
   // $VF: renamed from: a ce
   public class_42 field_827;
   // $VF: renamed from: a s
   public class_5 field_828;
   // $VF: renamed from: a ba
   private class_70 field_829;
   // $VF: renamed from: a cz
   public class_26 field_830;
   // $VF: renamed from: b int
   private int field_831;
   // $VF: renamed from: a x
   private class_3 field_832 = new class_3();
   // $VF: renamed from: c int
   private int field_833;
   // $VF: renamed from: a bg
   private class_60 field_834;
   // $VF: renamed from: a ax[]
   private class_108[] field_835;
   // $VF: renamed from: a v
   private class_103 field_836;

   public class_65(int var1) {
      this.field_831 = var1;
   }

   // $VF: renamed from: b () void
   public final void method_552() {
      if (this.field_829 != null) {
         this.field_829.method_680();
      }

      this.field_829 = null;
      this.field_825 = null;
      if (this.field_830 != null) {
         this.field_830.method_271();
      }

      this.field_830 = null;
      if (this.field_828 != null) {
         this.field_828.field_45 = null;
         this.field_828.field_48 = null;
      }

      this.field_828 = null;
      if (this.field_827 != null) {
         this.field_827.method_368(null);
         this.field_827.method_369(null);
      }

      this.field_827 = null;
      this.field_824 = null;
      this.field_823 = false;
      this.field_832 = null;
      this.field_835 = null;
      System.gc();
   }

   // $VF: renamed from: a () void
   public final void method_551() {
      try {
         if (this.field_831 == 1) {
            if (class_21.method_180().field_1143 != null) {
               class_68[] var1 = class_21.method_180().field_1143;
               this.field_835 = new class_108[var1.length];

               for (int var2 = 0; var2 < this.field_835.length; var2++) {
                  this.field_835[var2] = class_43.method_381(class_90.field_1205[var1[var2].field_863]);
               }

               this.field_825 = class_106.method_886(class_84.field_1120, class_84.field_1121, 800, 100, 4194304);
               this.field_825.method_843(0, 1000, -1400);
               this.field_825.method_860(400, 2048, 0);
               this.field_836 = new class_103();
               this.field_836.method_879(this.field_825);
            }
         } else {
            if (this.field_830 == null) {
               this.field_830 = new class_26(this.field_831);
            }

            if (!this.field_830.method_240()) {
               return;
            }

            this.field_829 = this.field_830.field_272;
            if (this.field_829 != null) {
               this.field_829.method_666(false);
               this.field_834 = this.field_829.field_976;
            } else {
               this.field_834 = new class_60();
            }

            this.field_833 = 0;
            this.field_826 = new class_39(class_84.field_1120, class_84.field_1121, 0);
            switch (this.field_831) {
               case 0:
                  class_84.field_1110.method_24(this.field_826.field_388);
                  break;
               case 1:
                  this.field_825.method_864(380, 2048, 0);
                  break;
               case 2:
                  this.field_825.method_864(0, 1024, 0);
                  class_84.field_1110.method_24(this.field_825);
            }
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }

      System.gc();
      this.field_818 = System.currentTimeMillis();
      this.field_819 = System.currentTimeMillis();
      this.field_823 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_553() {
      return this.field_823;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_568(int var1, int var2) {
      this.field_830.field_274[var1].field_1226 = class_43.method_381(var2);
      this.field_830.field_274[var1].field_1226.field_1367 = 2;
   }

   // $VF: renamed from: c (int) void
   public final void method_569(int var1) {
      this.field_833 = var1;
      if (this.field_825 == null) {
         this.field_825 = class_106.method_886(class_84.field_1120, class_84.field_1121, 800, 100, 4194304);
         this.field_825.method_843(0, 1000, -2200);
         this.field_825.method_860(400, 2048, 0);
         this.field_836 = new class_103();
         this.field_836.method_879(this.field_825);
         this.field_836.method_859((short)2);
      }

      this.field_836.method_846(this.field_830.field_274[this.field_833].method_799(this.field_832));
      class_84.field_1110.method_24(this.field_825);
   }

   // $VF: renamed from: c () void
   public final void method_570() {
      class_84.field_1110.method_24(this.field_826.field_388);
   }

   // $VF: renamed from: d () void
   public final void method_571() {
      this.method_549(0);
   }

   // $VF: renamed from: b (int) void
   public final void method_549(int var1) {
      if (this.field_823) {
         this.field_818 = System.currentTimeMillis();
         this.field_820 = this.field_818 - this.field_819;
         this.field_819 = this.field_818;
         this.field_821 = this.field_821 + this.field_820;
         this.field_822 = (int)(this.field_822 + this.field_820);
         this.field_826.method_364(System.currentTimeMillis());
         if (this.field_836 != null) {
            this.field_836.method_846(this.field_830.field_274[this.field_833].method_799(this.field_832));
            if ((var1 & 2) != 0) {
               this.field_836.method_860((int)this.field_820, 0, 0);
            }

            if ((var1 & 64) != 0) {
               this.field_836.method_860(-((int)this.field_820), 0, 0);
            }

            if ((var1 & 4) != 0) {
               this.field_836.method_860(0, (int)this.field_820, 0);
            }

            if ((var1 & 32) != 0) {
               this.field_836.method_860(0, -((int)this.field_820), 0);
            }
         }

         if (this.field_834 != null) {
            this.field_834.method_547(this.field_820, class_84.field_1110.field_40.field_1342, true);
         }

         this.method_572();
      }
   }

   // $VF: renamed from: e () void
   private void method_572() {
      try {
         if (this.field_831 != 1) {
            this.field_830.method_267(this.field_820);
            this.field_830.method_265(this.field_820);
            if (this.field_824 != null) {
               this.field_824.method_839(true);
            }

            this.field_834.method_548();
         }

         class_84.field_1111.method_683(class_84.field_1117);
         class_84.field_1110.method_27(System.currentTimeMillis());
         class_84.field_1111.method_685();
         class_84.field_1111.method_684(class_84.field_1117);
      } catch (Exception var2) {
         class_84.field_1111.method_684(class_84.field_1117);
         var2.printStackTrace();
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_550(int var1) {
   }

   static {
      int[][] var10000 = new int[][]{{0, 850, 1500}, {1000, -300, 3000}, {0, 2000, 0}};
      var10000 = new int[][]{{0, 650, 0}, {0, 0, 0}, {0, 0, 0}};
   }
}
