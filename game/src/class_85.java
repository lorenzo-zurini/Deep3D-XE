// $VF: renamed from: ap
public final class class_85 {
   // $VF: renamed from: a int[]
   private int[] field_1128;
   // $VF: renamed from: b int[]
   private int[] field_1129;
   // $VF: renamed from: a int
   private int field_1130;
   // $VF: renamed from: a ak[]
   public class_116[] field_1131;
   // $VF: renamed from: a ax
   public class_108 field_1132;

   public class_85(int var1, int var2) {
      if (var1 > 1) {
         this.field_1131 = new class_116[var1];
         this.field_1128 = new int[var1];
         boolean var3 = false;
         boolean var4 = false;

         for (int var5 = 0; var5 < this.field_1131.length; var5++) {
            this.field_1131[var5] = new class_116(class_43.method_380(2), 96, 0, 127, 32, 10, 1000, 200, 3000);
            if (var5 == 0) {
               this.field_1128[var5] = 0;
            } else {
               this.field_1128[var5] = this.field_1128[var5 - 1] + class_84.field_1123.nextInt(1000) + 1000;
            }
         }
      }

      if (var2 == 2) {
         this.field_1132 = class_43.method_381(9995);
         this.field_1132.method_873(60);
         this.field_1132.method_869(2048, 2048, 2048);
      } else {
         this.field_1132 = class_43.method_381(9992);
         this.field_1132.method_873(100);
      }

      this.field_1132.field_1367 = 2;
      this.field_1132.method_878();
   }

   // $VF: renamed from: a () void
   public final void method_738() {
      this.field_1128 = null;
      this.field_1129 = null;
      if (this.field_1131 != null) {
         for (int var1 = 0; var1 < this.field_1131.length; var1++) {
            if (this.field_1131[var1] != null) {
               this.field_1131[var1].method_894();
            }
         }
      }

      this.field_1131 = null;
   }

   // $VF: renamed from: a (int[]) void
   public final void method_739(int[] var1) {
      if (this.field_1131 != null) {
         if (var1.length != 3 * this.field_1131.length) {
            System.out.println("Explosion offset size must be 3 * explosion count");
            class_84.field_1126.method_440();
         }

         this.field_1129 = var1;
      }
   }

   // $VF: renamed from: a () int
   public final int method_740() {
      return this.field_1131 != null ? this.field_1131.length : 1;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_741(int var1, int var2, int var3) {
      if (this.field_1131 != null) {
         for (int var4 = 0; var4 < this.field_1131.length; var4++) {
            if (this.field_1129 != null) {
               this.field_1131[var4].method_845(var1 + this.field_1129[3 * var4], var2 + this.field_1129[3 * var4 + 1], var3 + this.field_1129[3 * var4 + 2]);
            } else {
               this.field_1131[var4].method_845(var1, var2, var3);
            }
         }

         this.field_1132.method_845(var1, var2, var3);
      } else {
         this.field_1132.method_845(var1, var2, var3);
         this.field_1132.method_877((byte)1);
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_742(long var1) {
      this.field_1130 = (int)(this.field_1130 + var1);
      if (this.field_1131 != null) {
         for (int var3 = 0; var3 < this.field_1131.length; var3++) {
            if (this.field_1131[var3].field_1436) {
               if (this.field_1130 > this.field_1128[var3]) {
                  if (var3 == this.field_1131.length - 1) {
                     this.field_1132.method_869(16384, 16384, 16384);
                     this.field_1132.method_877((byte)1);
                  }

                  this.field_1131[var3].method_910();
               }
            } else {
               if (var3 == this.field_1131.length - 1) {
                  class_84.field_1110.method_25(this.field_1132);
               }

               this.field_1131[var3].method_895(var1);
               this.field_1131[var3].method_887();
            }
         }
      } else {
         class_84.field_1110.method_25(this.field_1132);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_743() {
      return this.field_1131 != null ? this.field_1130 > this.field_1128[this.field_1128.length - 1] + 1000 : this.field_1130 > 4000;
   }
}
