// $VF: renamed from: cz
public final class class_7 {
   // $VF: renamed from: a int[]
   private int[] field_157;
   // $VF: renamed from: b int[]
   private int[] field_158;
   // $VF: renamed from: c int[]
   private int[] field_159;
   // $VF: renamed from: d int[]
   private int[] field_160;
   // $VF: renamed from: a int
   private int field_161;
   // $VF: renamed from: b int
   private int field_162;
   // $VF: renamed from: a ay
   private class_101 field_163;

   public class_7() {
      new class_5();
      new class_5();
      this.field_159 = new int[20];
      this.field_160 = new int[20];
      this.field_157 = new int[60];
      this.field_158 = new int[20];
      this.field_163 = class_101.method_880(0, 128, 32, 0, 64, 32, 120, 20, (byte)2);
      this.field_163.method_883(class_25.method_327(2));
      this.field_163.field_1294 = 2;
      this.field_157 = ((class_104)this.field_163).field_1309;

      for (int var1 = 0; var1 < this.field_157.length; var1++) {
         this.field_157[var1] = 100000;
      }
   }

   // $VF: renamed from: a () void
   public final void method_189() {
      this.field_163.method_884();
      this.field_163 = null;
      this.field_157 = null;
   }

   // $VF: renamed from: a (v, int) void
   public final void method_190(class_5 var1, int var2) {
      this.method_191(var1.field_138, var1.field_139, var1.field_140, var2);
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_191(int var1, int var2, int var3, int var4) {
      this.field_162 += var4;
      this.field_157 = ((class_104)this.field_163).field_1309;
      boolean var5 = false;

      for (byte var6 = 0; var6 < this.field_157.length; var6 += 3) {
         this.field_161 = var6 / 3;
         if (this.field_158[this.field_161] <= 0 && !var5 && this.field_162 > 100) {
            this.field_162 = 0;
            this.field_160[this.field_161] = 4096;
            this.field_157[var6] = var1;
            this.field_157[var6 + 1] = var2;
            this.field_157[var6 + 2] = var3;
            this.field_158[this.field_161] = 2000;
            this.field_159[this.field_161] = 10 + class_41.field_540.nextInt(40);
            var5 = true;
         } else {
            this.field_158[this.field_161] = this.field_158[this.field_161] - var4;
            this.field_157[var6 + 1] = this.field_157[var6 + 1] + this.field_159[this.field_161];
            this.field_160[this.field_161] = (int)(this.field_158[this.field_161] / 2000.0F * 4096.0F);
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_192() {
      class_41.field_527.method_265(this.field_163);
   }
}
