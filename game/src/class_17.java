// $VF: renamed from: ds
public final class class_17 {
   // $VF: renamed from: a long
   private long field_151;
   // $VF: renamed from: a int
   private int field_152;
   // $VF: renamed from: a boolean
   private boolean field_153;
   // $VF: renamed from: b boolean
   private boolean field_154;
   // $VF: renamed from: a di
   private class_78 field_155;
   // $VF: renamed from: a j
   private class_10 field_156;
   // $VF: renamed from: a ab
   private class_121 field_157;
   // $VF: renamed from: a bh
   private class_59 field_158;
   // $VF: renamed from: b int
   private int field_159;
   // $VF: renamed from: c int
   private int field_160;
   // $VF: renamed from: d int
   private int field_161;

   // $VF: renamed from: a () void
   public final void method_101() {
      this.field_155.method_714();
      this.field_155 = null;
      this.field_156 = null;
      this.field_157 = null;
      this.field_154 = false;
      System.gc();
   }

   // $VF: renamed from: b () void
   public final void method_102() {
      this.field_159 = 0;
      this.field_153 = false;
      this.field_155 = new class_78(new String[]{class_84.field_1116.method_4(266), class_84.field_1116.method_4(267)}, class_84.field_1116.method_4(235));
      this.field_156 = new class_10();
      this.field_157 = new class_121(20, class_84.field_1121 / 3, class_84.field_1120 - 40);
      class_21.method_220();
      this.field_155.method_722(0, class_120.method_935(class_21.method_178().field_886, class_21.method_180().field_1142));
      class_21.method_178().method_611(class_120.method_934(this.field_155.field_1062, true));
      class_21.method_180().field_1142 = class_120.method_934(this.field_155.field_1062, false);
      this.field_155.method_722(1, class_35.method_302());
      System.gc();
      this.field_154 = true;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_103(int var1) {
      this.field_158 = (class_59)this.field_155.method_701();
      if (var1 == 256) {
         if (this.field_153) {
            this.field_153 = false;
            return true;
         }

         if (this.field_159 == 0) {
            this.field_155.method_726();
         } else if (this.field_159 == 2) {
            this.field_159 = 0;
         } else if (this.field_159 == 1) {
            this.field_159 = 0;
         }
      }

      if (var1 == 4 && this.field_159 == 0) {
         this.field_155.method_706();
      }

      if (var1 == 32 && this.field_159 == 0) {
         this.field_155.method_707();
      }

      if (var1 == 2) {
         if (this.field_159 == 0) {
            this.field_155.method_704();
         } else if (this.field_159 == 2) {
            this.field_156.method_52(this.field_152);
         }
      }

      if (var1 == 64) {
         if (this.field_159 == 0) {
            this.field_155.method_705();
         } else if (this.field_159 == 2) {
            this.field_156.method_53(this.field_152);
         }
      }

      if (var1 == 8192) {
         if (this.field_159 == 0 && !this.field_155.method_723()) {
            return false;
         }

         if (this.field_159 == 2) {
            this.field_159 = 0;
         }
      }

      if (var1 == 16384) {
         if (this.field_159 == 0 && !this.field_155.method_723()) {
            if (this.field_158 != null) {
               this.field_159 = 2;
               this.field_156.method_51(this.field_158, this.field_155.field_1038 == 0);
            }
         } else if (this.field_159 == 1) {
            this.field_159 = 0;
         }
      }

      return this.field_153 ? true : true;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_104(int var1, int var2) {
      if (!this.field_154) {
         return true;
      } else {
         this.field_151 += var2;
         this.field_152 = var2;
         this.method_105();
         if (this.field_155.method_701() != null) {
            this.field_158 = (class_59)this.field_155.method_701();
         }

         if (this.field_153) {
            return true;
         } else {
            if (this.field_159 == 0) {
               if ((var1 & 4) == 0) {
                  this.field_160 = 0;
               } else {
                  this.field_160 += var2;
               }

               if ((var1 & 32) == 0) {
                  this.field_161 = 0;
               } else {
                  this.field_161 += var2;
               }

               if (this.field_160 > 500) {
                  this.field_155.method_724();
                  this.field_160 = 0;
               }

               if (this.field_161 > 500) {
                  this.field_155.method_725();
                  this.field_161 = 0;
               }
            }

            return true;
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_105() {
      class_67.method_587();
      if (this.field_159 == 0) {
         this.field_155.method_718();
      }

      if (this.field_159 == 2) {
         this.field_156.method_54();
      }

      if (this.field_159 == 1 || this.field_155.method_723()) {
         class_67.method_593("", "");
      } else if (this.field_159 == 0) {
         class_67.method_593(class_84.field_1116.method_4(226), class_84.field_1116.method_4(65));
      } else {
         class_67.method_593("", class_84.field_1116.method_4(65));
      }

      if (this.field_159 == 1) {
         this.field_155.method_718();
         this.field_157.method_944();
      }

      if (this.field_153) {
         this.field_157.method_944();
      }
   }

   // $VF: renamed from: a () int
   public final int method_106() {
      return this.field_155.field_1038;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_107() {
      return this.field_159 == 0 && !this.field_155.method_723();
   }
}
