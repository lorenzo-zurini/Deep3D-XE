// $VF: renamed from: ar
public final class class_83 {
   // $VF: renamed from: a int
   public int field_1072 = 120;
   // $VF: renamed from: a int[]
   private int[] field_1073;
   // $VF: renamed from: b int[]
   private int[] field_1074;
   // $VF: renamed from: c int[]
   private int[] field_1075;
   // $VF: renamed from: a ax
   private class_108 field_1076;
   // $VF: renamed from: a x
   private class_3 field_1077 = new class_3();
   // $VF: renamed from: a boolean
   private boolean field_1078 = false;

   public class_83() {
      this.field_1076 = class_108.method_892(0, 12, (byte)2);
      this.field_1076.method_893(class_43.method_380(2));
      this.field_1076.field_1367 = 2;
      this.field_1074 = new int[144];
      this.field_1073 = new int[144];
      int var1 = 19;
      int var2 = 20;
      this.field_1075 = new int[96];

      for (int var3 = 8; var3 < this.field_1075.length; var3 += 8) {
         this.field_1075[var3] = 83;
         this.field_1075[var3 + 1] = var1;
         this.field_1075[var3 + 2] = 84;
         this.field_1075[var3 + 3] = var1;
         this.field_1075[var3 + 4] = 84;
         this.field_1075[var3 + 5] = var2;
         this.field_1075[var3 + 6] = 83;
         this.field_1075[var3 + 7] = var2;
         var1++;
         var2++;
      }
   }

   // $VF: renamed from: a () void
   public final void method_731() {
      this.field_1076.method_894();
      this.field_1076 = null;
   }

   // $VF: renamed from: a (int, int, int, int, int, int) void
   public final void method_732(int var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_1074[0] = var1 - this.field_1072;
      this.field_1074[1] = var2;
      this.field_1074[2] = var3;
      this.field_1074[3] = var1 + this.field_1072;
      this.field_1074[4] = var2;
      this.field_1074[5] = var3;
      this.field_1074[6] = var4 + this.field_1072;
      this.field_1074[7] = var5;
      this.field_1074[8] = var6;
      this.field_1074[9] = var4 - this.field_1072;
      this.field_1074[10] = var5;
      this.field_1074[11] = var6;

      for (int var7 = this.field_1074.length - 1; var7 >= 23; var7 -= 12) {
         this.field_1074[var7] = this.field_1074[var7 - 12];
         this.field_1074[var7 - 1] = this.field_1074[var7 - 13];
         this.field_1074[var7 - 2] = this.field_1074[var7 - 14];
         this.field_1074[var7 - 3] = this.field_1074[var7 - 15];
         this.field_1074[var7 - 4] = this.field_1074[var7 - 16];
         this.field_1074[var7 - 5] = this.field_1074[var7 - 17];
         this.field_1074[var7 - 6] = this.field_1074[var7 - 18];
         this.field_1074[var7 - 7] = this.field_1074[var7 - 19];
         this.field_1074[var7 - 8] = this.field_1074[var7 - 20];
         this.field_1074[var7 - 9] = this.field_1074[var7 - 21];
         this.field_1074[var7 - 10] = this.field_1074[var7 - 22];
         this.field_1074[var7 - 11] = this.field_1074[var7 - 23];
      }

      for (int var8 = 0; var8 < this.field_1074.length; var8 += 3) {
         this.field_1073[var8] = this.field_1074[var8] - var1;
         this.field_1073[var8 + 1] = this.field_1074[var8 + 1] - var2;
         this.field_1073[var8 + 2] = this.field_1074[var8 + 2] - var3;
      }

      this.field_1076.method_845(var1, var2, var3);
      ((class_109)this.field_1076).method_896(this.field_1073, this.field_1075);
   }

   // $VF: renamed from: a (x) void
   public final void method_733(class_3 var1) {
      if (this.field_1078) {
         this.field_1077.method_9(var1);
         this.field_1078 = false;
      }

      this.method_732(var1.field_37, var1.field_38, var1.field_39, this.field_1077.field_37, this.field_1077.field_38, this.field_1077.field_39);
      this.field_1077.method_9(var1);
   }

   // $VF: renamed from: b (x) void
   public final void method_734(class_3 var1) {
      for (int var2 = 0; var2 < this.field_1074.length; var2 += 3) {
         this.field_1074[var2] = var1.field_37;
         this.field_1074[var2 + 1] = var1.field_38;
         this.field_1074[var2 + 2] = var1.field_39;
      }

      this.field_1077.method_9(var1);
      this.field_1078 = true;
   }

   // $VF: renamed from: b () void
   public final void method_735() {
      class_84.field_1110.method_25(this.field_1076);
   }
}
