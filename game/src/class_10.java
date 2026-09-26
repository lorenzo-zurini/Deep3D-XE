// $VF: renamed from: ck
public final class class_10 {
   // $VF: renamed from: a long
   private long field_169;
   // $VF: renamed from: a am
   public class_111 field_170 = class_111.method_899(class_41.field_537, class_41.field_538, 800, 100, org.deep3d.Config.farPlane());
   // $VF: renamed from: a h
   private class_39 field_171;
   // $VF: renamed from: a int[][]
   private static final int[][] field_172 = new int[][]{
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

   public class_10(int var1, int var2, int var3) {
      this.field_170.method_855((short)2);
      this.field_171 = new class_39(field_172, var3, field_172[var3][field_172[var3].length - 8]);
   }

   // $VF: renamed from: a (long) void
   public final void method_207(long var1) {
      if (this.field_169 == 0L) {
         this.field_169 = var1;
      }

      this.field_171.method_406(var1);
      this.field_170.method_841(this.field_171.field_490.field_138, this.field_171.field_490.field_139, this.field_171.field_490.field_140);
      this.field_170.method_860(this.field_171.field_491.field_138, this.field_171.field_491.field_139, this.field_171.field_491.field_140);
      this.field_170.method_896(this.field_171.field_492);
   }
}
