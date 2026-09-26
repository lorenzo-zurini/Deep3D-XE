// $VF: renamed from: da
public final class class_25 {
   // $VF: renamed from: a int[]
   private int[] field_255;
   // $VF: renamed from: b int[]
   private int[] field_256;
   // $VF: renamed from: c int[]
   private int[] field_257;
   // $VF: renamed from: d int[]
   private int[] field_258;
   // $VF: renamed from: a int
   private int field_259;
   // $VF: renamed from: b int
   private int field_260;
   // $VF: renamed from: a ax
   private class_108 field_261;

   public class_25() {
      new class_3();
      new class_3();
      this.field_257 = new int[20];
      this.field_258 = new int[20];
      this.field_255 = new int[60];
      this.field_256 = new int[20];
      this.field_261 = class_108.method_890(0, 128, 32, 0, 64, 32, 120, 20, (byte)2);
      this.field_261.method_893(class_43.method_380(2));
      this.field_261.field_1367 = 2;
      this.field_255 = ((class_110)this.field_261).field_1389;

      for (int var1 = 0; var1 < this.field_255.length; var1++) {
         this.field_255[var1] = 100000;
      }
   }

   // $VF: renamed from: a () void
   public final void method_235() {
      this.field_261.method_894();
      this.field_261 = null;
      this.field_255 = null;
   }

   // $VF: renamed from: a (x, int) void
   public final void method_236(class_3 var1, int var2) {
      this.method_237(var1.field_37, var1.field_38, var1.field_39, var2);
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_237(int var1, int var2, int var3, int var4) {
      this.field_260 += var4;
      this.field_255 = ((class_110)this.field_261).field_1389;
      boolean var5 = false;

      for (int var6 = 0; var6 < this.field_255.length; var6 += 3) {
         this.field_259 = var6 / 3;
         if (this.field_256[this.field_259] <= 0 && !var5 && this.field_260 > 100) {
            this.field_260 = 0;
            this.field_258[this.field_259] = 4096;
            this.field_255[var6] = var1;
            this.field_255[var6 + 1] = var2;
            this.field_255[var6 + 2] = var3;
            this.field_256[this.field_259] = 2000;
            this.field_257[this.field_259] = 10 + class_84.field_1123.nextInt(40);
            var5 = true;
         } else {
            this.field_256[this.field_259] = this.field_256[this.field_259] - var4;
            this.field_255[var6 + 1] = this.field_255[var6 + 1] + this.field_257[this.field_259];
            this.field_258[this.field_259] = (int)(this.field_256[this.field_259] / 2000.0F * 4096.0F);
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_238() {
      class_84.field_1110.method_25(this.field_261);
   }
}
