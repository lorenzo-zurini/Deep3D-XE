import javax.microedition.lcdui.Image;

// $VF: renamed from: ad
public final class class_119 {
   // $VF: renamed from: a byte
   public static byte field_1457 = 6;
   // $VF: renamed from: a int
   public static int field_1458 = 40;
   // $VF: renamed from: b int
   public static int field_1459 = 40;
   // $VF: renamed from: b byte
   private static byte field_1460 = 95;
   // $VF: renamed from: c byte
   private static byte field_1461 = 20;
   // $VF: renamed from: d byte
   private static byte field_1462 = 60;
   // $VF: renamed from: a byte[]
   private static byte[] field_1463 = new byte[]{0, 1};
   // $VF: renamed from: b byte[]
   private static byte[] field_1464 = new byte[]{72, 2, 3, 4, 5, 6, 7, 8};
   // $VF: renamed from: c byte[]
   private static byte[] field_1465 = new byte[]{9, 10, 11, 12, 88};
   // $VF: renamed from: d byte[]
   private static byte[] field_1466 = new byte[]{13, 14, 15};
   // $VF: renamed from: e byte[]
   private static byte[] field_1467 = new byte[]{16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
   // $VF: renamed from: f byte[]
   private static byte[] field_1468 = new byte[]{84, 85, 86, 87};
   // $VF: renamed from: g byte[]
   private static byte[] field_1469 = new byte[]{30, 31, 32, 33, 34, 35, 36, 89, 90, 91, 92, 93};
   // $VF: renamed from: h byte[]
   private static byte[] field_1470 = new byte[]{37, 38, 39, 40};
   // $VF: renamed from: i byte[]
   private static byte[] field_1471 = new byte[]{31, 33, 36, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54};
   // $VF: renamed from: j byte[]
   private static byte[] field_1472 = new byte[]{58, 59, 60, 61, 94};
   // $VF: renamed from: k byte[]
   private static byte[] field_1473 = new byte[]{62, 63, 64};
   // $VF: renamed from: l byte[]
   private static byte[] field_1474 = new byte[]{29, 65, 66, 67, 68, 69, 70, 71};
   // $VF: renamed from: m byte[]
   private static byte[] field_1475 = new byte[]{74, 75, 76, 77};
   // $VF: renamed from: n byte[]
   private static byte[] field_1476 = new byte[]{28, 78, 79, 80, 81, 82, 83};
   // $VF: renamed from: a byte[][][]
   private static byte[][][] field_1477 = new byte[][][]{
      {field_1468, field_1468, field_1468},
      {field_1476, field_1476, field_1475},
      {field_1474, field_1473, field_1472},
      {field_1467, field_1466, field_1465},
      {field_1471, field_1470, field_1469},
      {field_1464, field_1464, field_1463}
   };
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private static Image[] field_1478 = new Image[field_1460];
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_1479;

   private class_119() {
   }

   // $VF: renamed from: a (boolean, int) byte[]
   public static final byte[] method_920(boolean var0, int var1) {
      if (field_1478 == null) {
         field_1478 = new Image[field_1460];
      }

      byte[] var2 = new byte[field_1457];
      int var3 = 0;
      int var4 = 0;
      int var5 = 0;
      boolean var6 = var0 && class_84.field_1123.nextInt(100) < field_1461;

      for (int var7 = 0; var7 < field_1477.length; var7++) {
         var5 = var0 ? (var6 ? 1 : 0) : 2;
         if (var7 == 0) {
            var4 = field_1468[var1];
         } else if (var7 != 5 || var7 == 5 && class_84.field_1123.nextInt(100) < field_1462) {
            int var8 = var7 == 1 && !var0 ? 2 : (var7 == 2 && !var0 ? 1 : var7);
            var4 = field_1477[var8][var5][class_84.field_1123.nextInt(field_1477[var8][var5].length)];
            if (field_1478[var4] == null) {
               method_922(var4);
            }
         } else {
            var4 = -1;
         }

         var2[var3++] = (byte)var4;
      }

      return var2;
   }

   // $VF: renamed from: a (byte[]) void
   public static final void method_921(byte[] var0) {
      if (var0 != null) {
         for (int var1 = 0; var1 < var0.length; var1++) {
            if (var0[var1] >= 0 && field_1478[var0[var1]] == null) {
               method_922(var0[var1]);
            }
         }
      }
   }

   // $VF: renamed from: a (int) void
   private static void method_922(int var0) {
      field_1478[var0] = class_28.method_282("/data/interface/faces/" + var0 + ".png");
   }

   // $VF: renamed from: a (byte[], int, int, int) void
   public static final void method_923(byte[] var0, int var1, int var2, int var3) {
      if (var0 != null) {
         if (var0[0] < 0) {
            if (field_1479 == null) {
               field_1479 = class_28.method_282("/data/interface/mai.png");
            }

            class_84.field_1117.drawImage(field_1479, var1, var2, var3);
         } else {
            for (int var4 = 0; var4 < var0.length; var4++) {
               if (var0[var4] >= 0) {
                  if (field_1478[var0[var4]] == null) {
                     method_922(var0[var4]);
                  }

                  class_84.field_1117.drawImage(field_1478[var0[var4]], var1, var2, var3);
               }
            }
         }
      }
   }
}
