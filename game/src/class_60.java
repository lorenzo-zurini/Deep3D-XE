// $VF: renamed from: bg
public final class class_60 {
   // $VF: renamed from: a int[]
   private int[] field_718;
   // $VF: renamed from: b int[]
   private int[] field_719;
   // $VF: renamed from: c int[]
   private int[] field_720;
   // $VF: renamed from: a x
   private class_3 field_721 = new class_3();
   // $VF: renamed from: b x
   private class_3 field_722 = new class_3();
   // $VF: renamed from: a ax
   private class_108 field_723;

   public class_60() {
      this.field_720 = new int[15];
      this.field_718 = new int[45];
      this.field_719 = new int[15];
      this.field_723 = class_108.method_890(0, 128, 32, 0, 64, 32, 400, 15, (byte)2);
      this.field_723.method_893(class_43.method_380(2));
      this.field_723.field_1367 = 2;
      this.field_718 = ((class_110)this.field_723).field_1389;

      for (int var1 = 0; var1 < this.field_718.length; var1++) {
         this.field_718[var1] = 100000;
      }

      for (int var2 = 0; var2 < this.field_720.length; var2++) {
         this.field_720[var2] = 250 + class_84.field_1123.nextInt(300);
      }
   }

   // $VF: renamed from: a () void
   public final void method_546() {
      this.field_723.method_894();
      this.field_723 = null;
      this.field_718 = null;
   }

   // $VF: renamed from: a (long, bn, boolean) void
   public final void method_547(long var1, class_57 var3, boolean var4) {
      boolean var5 = false;
      this.field_718 = ((class_110)this.field_723).field_1389;

      for (int var6 = 0; var6 < this.field_718.length; var6 += 3) {
         int var7 = var6 / 3;
         if (!var5 && this.field_719[var7] <= 0) {
            int var8 = class_84.field_1123.nextInt(18000) - 9000;
            int var9 = -5000 - class_84.field_1123.nextInt(10000);
            int var10 = var4 ? -(10000 + class_84.field_1123.nextInt(9000) - 4500) : -(40000 + class_84.field_1123.nextInt(18000) - 9000);
            this.field_722.method_10(var8, var9, var10);
            this.field_721 = var3.method_507(this.field_722, this.field_721);
            this.field_718[var6] = this.field_721.field_37;
            this.field_718[var6 + 1] = this.field_721.field_38;
            this.field_718[var6 + 2] = this.field_721.field_39;
            this.field_719[var7] = 2500;
            var5 = true;
         } else {
            this.field_719[var7] = (int)(this.field_719[var7] - var1);
            this.field_718[var6 + 1] = this.field_718[var6 + 1] + this.field_720[var7];
            if (!var4) {
               this.field_722 = var3.method_481(this.field_722);
               this.field_718[var6] = this.field_718[var6] + (this.field_722.field_37 >> 3);
               this.field_718[var6 + 1] = this.field_718[var6 + 1] + (this.field_722.field_38 >> 3);
               this.field_718[var6 + 2] = this.field_718[var6 + 2] + (this.field_722.field_39 >> 3);
            }
         }
      }

      ((class_110)this.field_723).field_1389 = this.field_718;
   }

   // $VF: renamed from: b () void
   public final void method_548() {
      class_84.field_1110.method_25(this.field_723);
   }
}
