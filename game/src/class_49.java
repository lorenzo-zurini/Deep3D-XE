// $VF: renamed from: ds
public final class class_49 {
   // $VF: renamed from: a long
   private long field_696;
   // $VF: renamed from: a int
   private int field_697;
   // $VF: renamed from: a boolean
   private boolean field_698;
   // $VF: renamed from: b boolean
   private boolean field_699;
   // $VF: renamed from: a di
   private class_75 field_700;
   // $VF: renamed from: a k
   private class_56 field_701;
   // $VF: renamed from: a z
   private class_53 field_702;
   // $VF: renamed from: a bi
   private class_2 field_703;
   // $VF: renamed from: b int
   private int field_704;
   // $VF: renamed from: c int
   private int field_705;
   // $VF: renamed from: d int
   private int field_706;

   // $VF: renamed from: a () void
   public final void method_473() {
      this.field_700.method_707();
      this.field_700 = null;
      this.field_701 = null;
      this.field_702 = null;
      this.field_699 = false;
      ;
   }

   // $VF: renamed from: b () void
   public final void method_474() {
      this.field_704 = 0;
      this.field_698 = false;
      this.field_700 = new class_75(new String[]{class_41.field_533.method_297(266), class_41.field_533.method_297(267)}, class_41.field_533.method_297(235));
      this.field_701 = new class_56();
      this.field_702 = new class_53(20, class_41.field_538 / 3, class_41.field_537 - 40);
      class_3.method_150();
      this.field_700.method_715(0, class_46.method_453(class_3.method_108().field_445, class_3.method_110().field_836));
      class_3.method_108().method_371(class_46.method_452(this.field_700.field_1080, true));
      class_3.method_110().field_836 = class_46.method_452(this.field_700.field_1080, false);
      this.field_700.method_715(1, class_9.method_199());
      ;
      this.field_699 = true;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_475(int var1) {
      this.field_703 = (class_2)this.field_700.method_694();
      if (var1 == 256) {
         if (this.field_698) {
            this.field_698 = false;
            return true;
         }

         if (this.field_704 == 0) {
            this.field_700.method_719();
         } else if (this.field_704 == 2) {
            this.field_704 = 0;
         } else if (this.field_704 == 1) {
            this.field_704 = 0;
         }
      }

      if (var1 == 4 && this.field_704 == 0) {
         this.field_700.method_699();
      }

      if (var1 == 32 && this.field_704 == 0) {
         this.field_700.method_700();
      }

      if (var1 == 2) {
         if (this.field_704 == 0) {
            this.field_700.method_697();
         } else if (this.field_704 == 2) {
            this.field_701.method_526(this.field_697);
         }
      }

      if (var1 == 64) {
         if (this.field_704 == 0) {
            this.field_700.method_698();
         } else if (this.field_704 == 2) {
            this.field_701.method_527(this.field_697);
         }
      }

      if (var1 == 8192) {
         if (this.field_704 == 0 && !this.field_700.method_716()) {
            return false;
         }

         if (this.field_704 == 2) {
            this.field_704 = 0;
         }
      }

      if (var1 == 16384) {
         if (this.field_704 == 0 && !this.field_700.method_716()) {
            if (this.field_703 != null) {
               this.field_704 = 2;
               this.field_701.method_525(this.field_703, this.field_700.field_1057 == 0);
            }
         } else if (this.field_704 == 1) {
            this.field_704 = 0;
         }
      }

      return this.field_698 ? true : true;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_476(int var1, int var2) {
      if (!this.field_699) {
         return true;
      } else {
         this.field_696 += var2;
         this.field_697 = var2;
         this.method_477();
         if (this.field_700.method_694() != null) {
            this.field_703 = (class_2)this.field_700.method_694();
         }

         if (this.field_698) {
            return true;
         } else {
            if (this.field_704 == 0) {
               if ((var1 & 4) == 0) {
                  this.field_705 = 0;
               } else {
                  this.field_705 += var2;
               }

               if ((var1 & 32) == 0) {
                  this.field_706 = 0;
               } else {
                  this.field_706 += var2;
               }

               if (this.field_705 > 500) {
                  this.field_700.method_717();
                  this.field_705 = 0;
               }

               if (this.field_706 > 500) {
                  this.field_700.method_718();
                  this.field_706 = 0;
               }
            }

            return true;
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_477() {
      class_69.method_663();
      if (this.field_704 == 0) {
         this.field_700.method_711();
      }

      if (this.field_704 == 2) {
         this.field_701.method_528();
      }

      if (this.field_704 == 1 || this.field_700.method_716()) {
         class_69.method_669("", "");
      } else if (this.field_704 == 0) {
         class_69.method_669(class_41.field_533.method_297(226), class_41.field_533.method_297(65));
      } else {
         class_69.method_669("", class_41.field_533.method_297(65));
      }

      if (this.field_704 == 1) {
         this.field_700.method_711();
         this.field_702.method_518();
      }

      if (this.field_698) {
         this.field_702.method_518();
      }
   }

   // $VF: renamed from: a () int
   public final int method_478() {
      return this.field_700.field_1057;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_479() {
      return this.field_704 == 0 && !this.field_700.method_716();
   }
}
