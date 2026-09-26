// $VF: renamed from: aq
public final class class_82 {
   // $VF: renamed from: a int
   public int field_1094 = 120;
   // $VF: renamed from: a int[]
   private int[] field_1095;
   // $VF: renamed from: b int[]
   private int[] field_1096;
   // $VF: renamed from: c int[]
   private int[] field_1097;
   // $VF: renamed from: a ay
   private class_101 field_1098;
   // $VF: renamed from: a v
   private class_5 field_1099 = new class_5();
   // $VF: renamed from: a boolean
   private boolean field_1100 = false;

   public class_82() {
      this.field_1098 = class_101.method_882(0, 12, (byte)2);
      this.field_1098.method_883(class_25.method_327(2));
      this.field_1098.field_1294 = 2;
      this.field_1096 = new int[144];
      this.field_1095 = new int[144];
      int var1 = 19;
      int var2 = 20;
      this.field_1097 = new int[96];

      for (byte var3 = 8; var3 < this.field_1097.length; var3 += 8) {
         this.field_1097[var3] = 83;
         this.field_1097[var3 + 1] = var1;
         this.field_1097[var3 + 2] = 84;
         this.field_1097[var3 + 3] = var1;
         this.field_1097[var3 + 4] = 84;
         this.field_1097[var3 + 5] = var2;
         this.field_1097[var3 + 6] = 83;
         this.field_1097[var3 + 7] = var2;
         var1++;
         var2++;
      }
   }

   // $VF: renamed from: a () void
   public final void method_736() {
      this.field_1098.method_884();
      this.field_1098 = null;
   }

   // $VF: renamed from: a (int, int, int, int, int, int) void
   public final void method_737(int var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_1096[0] = var1 - this.field_1094;
      this.field_1096[1] = var2;
      this.field_1096[2] = var3;
      this.field_1096[3] = var1 + this.field_1094;
      this.field_1096[4] = var2;
      this.field_1096[5] = var3;
      this.field_1096[6] = var4 + this.field_1094;
      this.field_1096[7] = var5;
      this.field_1096[8] = var6;
      this.field_1096[9] = var4 - this.field_1094;
      this.field_1096[10] = var5;
      this.field_1096[11] = var6;

      for (int var7 = this.field_1096.length - 1; var7 >= 23; var7 -= 12) {
         this.field_1096[var7] = this.field_1096[var7 - 12];
         this.field_1096[var7 - 1] = this.field_1096[var7 - 13];
         this.field_1096[var7 - 2] = this.field_1096[var7 - 14];
         this.field_1096[var7 - 3] = this.field_1096[var7 - 15];
         this.field_1096[var7 - 4] = this.field_1096[var7 - 16];
         this.field_1096[var7 - 5] = this.field_1096[var7 - 17];
         this.field_1096[var7 - 6] = this.field_1096[var7 - 18];
         this.field_1096[var7 - 7] = this.field_1096[var7 - 19];
         this.field_1096[var7 - 8] = this.field_1096[var7 - 20];
         this.field_1096[var7 - 9] = this.field_1096[var7 - 21];
         this.field_1096[var7 - 10] = this.field_1096[var7 - 22];
         this.field_1096[var7 - 11] = this.field_1096[var7 - 23];
      }

      for (byte var8 = 0; var8 < this.field_1096.length; var8 += 3) {
         this.field_1095[var8] = this.field_1096[var8] - var1;
         this.field_1095[var8 + 1] = this.field_1096[var8 + 1] - var2;
         this.field_1095[var8 + 2] = this.field_1096[var8 + 2] - var3;
      }

      this.field_1098.method_841(var1, var2, var3);
      ((class_105)this.field_1098).method_890(this.field_1095, this.field_1097);
   }

   // $VF: renamed from: a (v) void
   public final void method_738(class_5 var1) {
      if (this.field_1100) {
         this.field_1099.method_169(var1);
         this.field_1100 = false;
      }

      this.method_737(var1.field_138, var1.field_139, var1.field_140, this.field_1099.field_138, this.field_1099.field_139, this.field_1099.field_140);
      this.field_1099.method_169(var1);
   }

   // $VF: renamed from: b (v) void
   public final void method_739(class_5 var1) {
      for (byte var2 = 0; var2 < this.field_1096.length; var2 += 3) {
         this.field_1096[var2] = var1.field_138;
         this.field_1096[var2 + 1] = var1.field_139;
         this.field_1096[var2 + 2] = var1.field_140;
      }

      this.field_1099.method_169(var1);
      this.field_1100 = true;
   }

   // $VF: renamed from: b () void
   public final void method_740() {
      class_41.field_527.method_265(this.field_1098);
   }
}
