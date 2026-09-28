// $VF: renamed from: ck
public final class class_39 {
   // $VF: renamed from: a long
   private long field_387;
   // $VF: renamed from: a an
   // Deep3D-PC: far plane reaches every structure (no stand-ins, see class_95)
   public class_106 field_388 = class_106.method_886(class_84.field_1120, class_84.field_1121, 800, 100, 4194304);
   // $VF: renamed from: a g
   private class_13 field_389;
   // $VF: renamed from: a int[][]
   private static final int[][] field_390 = new int[][]{
      {
            0,
            0,
            0,
            20000,
            0,
            -300,
            0,
            800,
            15000,
            15000,
            5000,
            -5000,
            -128,
            1400,
            0,
            800,
            30000,
            0,
            0,
            -20000,
            0,
            2048,
            0,
            800,
            45000,
            -15000,
            -5000,
            10000,
            128,
            3072,
            0,
            800,
            60000,
            0,
            0,
            20000,
            0,
            3796,
            0,
            800
      },
      {
            5000,
            150000,
            5000,
            0,
            -1024,
            1024,
            0,
            800,
            20000,
            120000,
            5000,
            0,
            -500,
            1024,
            0,
            800,
            30000,
            20000,
            0,
            0,
            0,
            1024,
            0,
            800,
            40000,
            0,
            -3000,
            -20000,
            0,
            2048,
            0,
            800,
            55000,
            30000,
            0,
            0,
            0,
            1024,
            0,
            800,
            65000,
            30000,
            0,
            -50000,
            0,
            1800,
            0,
            800,
            70000,
            6000,
            1000,
            -116000,
            0,
            2048,
            0,
            800
      }
   };

   public class_39(int var1, int var2, int var3) {
      this.field_388.method_859((short)2);
      this.field_389 = new class_13(field_390, var3, field_390[var3][field_390[var3].length - 8]);
   }

   // $VF: renamed from: a (long) void
   public final void method_364(long var1) {
      if (this.field_387 == 0L) {
         this.field_387 = var1;
      }

      this.field_389.method_63(var1);
      this.field_388.method_845(this.field_389.field_130.field_37, this.field_389.field_130.field_38, this.field_389.field_130.field_39);
      this.field_388.method_864(this.field_389.field_131.field_37, this.field_389.field_131.field_38, this.field_389.field_131.field_39);
      this.field_388.method_882(this.field_389.field_132);
   }
}
