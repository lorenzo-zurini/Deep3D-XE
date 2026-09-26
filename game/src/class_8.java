// $VF: renamed from: ao
public final class class_8 {
   // $VF: renamed from: a int[]
   private int[] field_164;
   // $VF: renamed from: b int[]
   private int[] field_165;
   // $VF: renamed from: a int
   private int field_166;
   // $VF: renamed from: a aj[]
   public class_103[] field_167;
   // $VF: renamed from: a ay
   public class_101 field_168;

   public class_8(int var1, int var2) {
      if (var1 > 1) {
         this.field_167 = new class_103[var1];
         this.field_164 = new int[var1];
         boolean var3 = false;
         boolean var4 = false;

         for (int var5 = 0; var5 < this.field_167.length; var5++) {
            this.field_167[var5] = new class_103(class_25.method_327(2), 96, 0, 127, 32, 10, 1000, 200, 3000);
            if (var5 == 0) {
               this.field_164[var5] = 0;
            } else {
               this.field_164[var5] = this.field_164[var5 - 1] + class_41.field_540.nextInt(1000) + 1000;
            }
         }
      }

      if (var2 == 2) {
         this.field_168 = class_25.method_328(9995);
         this.field_168.method_869(60);
         this.field_168.method_865(2048, 2048, 2048);
      } else {
         this.field_168 = class_25.method_328(9992);
         this.field_168.method_869(100);
      }

      this.field_168.field_1294 = 2;
      this.field_168.method_874();
   }

   // $VF: renamed from: a () void
   public final void method_193() {
      this.field_164 = null;
      this.field_165 = null;
      if (this.field_167 != null) {
         for (int var1 = 0; var1 < this.field_167.length; var1++) {
            if (this.field_167[var1] != null) {
               this.field_167[var1].method_884();
            }
         }
      }

      this.field_167 = null;
   }

   // $VF: renamed from: a (int[]) void
   public final void method_194(int[] var1) {
      if (this.field_167 != null) {
         if (var1.length != 3 * this.field_167.length) {
            System.out.println("Explosion offset size must be 3 * explosion count");
            class_41.field_543.method_214();
         }

         this.field_165 = var1;
      }
   }

   // $VF: renamed from: a () int
   public final int method_195() {
      return this.field_167 != null ? this.field_167.length : 1;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_196(int var1, int var2, int var3) {
      if (this.field_167 != null) {
         for (int var4 = 0; var4 < this.field_167.length; var4++) {
            if (this.field_165 != null) {
               this.field_167[var4].method_841(var1 + this.field_165[3 * var4], var2 + this.field_165[3 * var4 + 1], var3 + this.field_165[3 * var4 + 2]);
            } else {
               this.field_167[var4].method_841(var1, var2, var3);
            }
         }

         this.field_168.method_841(var1, var2, var3);
      } else {
         this.field_168.method_841(var1, var2, var3);
         this.field_168.method_873((byte)1);
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_197(long var1) {
      this.field_166 = (int)(this.field_166 + var1);
      if (this.field_167 != null) {
         for (int var3 = 0; var3 < this.field_167.length; var3++) {
            if (this.field_167[var3].field_1302) {
               if (this.field_166 > this.field_164[var3]) {
                  if (var3 == this.field_167.length - 1) {
                     this.field_168.method_865(16384, 16384, 16384);
                     this.field_168.method_873((byte)1);
                  }

                  this.field_167[var3].method_888();
               }
            } else {
               if (var3 == this.field_167.length - 1) {
                  class_41.field_527.method_265(this.field_168);
               }

               this.field_167[var3].method_885(var1);
               this.field_167[var3].method_878();
            }
         }
      } else {
         class_41.field_527.method_265(this.field_168);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_198() {
      return this.field_167 != null ? this.field_166 > this.field_164[this.field_164.length - 1] + 1000 : this.field_166 > 4000;
   }
}
