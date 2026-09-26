import java.io.DataInputStream;
import java.io.InputStream;
import javax.microedition.lcdui.Image;

// $VF: renamed from: cw
public final class class_28 {
   // $VF: renamed from: a java.lang.Class
   public static Class field_304;

   // $VF: renamed from: a (javax.microedition.lcdui.Image, int, int) javax.microedition.lcdui.Image
   public static final Image method_280(Image var0, int var1, int var2) {
      try {
         float var3 = (float)var1 / var0.getWidth();
         float var4 = (float)var2 / var0.getHeight();
         int var5 = var0.getWidth();
         int var6 = var0.getHeight();
         int[] var7 = new int[var5 * var6];
         int[] var8 = new int[(int)(var5 * var3) * (int)(var6 * var4)];
         var0.getRGB(var7, 0, var5, 0, 0, var5, var6);
         var0 = Image.createRGBImage(method_281(var7, var8, var5, (int)(var5 * var3)), (int)(var5 * var3), (int)(var6 * var4), true);
         // System.gc() removed: full GCs stall the desktop JVM
      } catch (Exception var9) {
         var9.printStackTrace();
      }

      return var0;
   }

   // $VF: renamed from: a (int[], int[], int, int) int[]
   private static int[] method_281(int[] var0, int[] var1, int var2, int var3) {
      int var4 = var0.length / var2;
      int var5 = var1.length / var3;

      for (int var6 = 0; var6 < var3; var6++) {
         for (int var7 = 0; var7 < var5; var7++) {
            float var8 = (float)var6 * (var2 - 1) / (var3 - 1);
            int var9 = 0;
            if (var8 - Math.floor(var8) > 0.5) {
               var9 = (int)Math.ceil(var8);
            } else {
               var9 = (int)Math.floor(var8);
            }

            float var10 = (float)var7 * (var4 - 1) / (var5 - 1);
            int var11 = 0;
            if (var10 - Math.floor(var10) > 0.5) {
               var11 = (int)Math.ceil(var10);
            } else {
               var11 = (int)Math.floor(var10);
            }

            var1[var6 + var7 * var3] = var0[var9 + var11 * var2];
         }
      }

      return var1;
   }

   // $VF: renamed from: a (java.lang.String) javax.microedition.lcdui.Image
   public static final Image method_282(String var0) {
      Image var1 = null;

      try {
         InputStream var2 = class_28.class.getResourceAsStream(var0);
         DataInputStream var3;
         int var4;
         byte[] var5 = var2.readAllBytes();
         var4 = var5.length;
         var2.close();
         int var6;
         if (var4 < 100) {
            var6 = 10 + var4 % 10;
         } else if (var4 < 200) {
            var6 = 50 + var4 % 20;
         } else if (var4 < 300) {
            var6 = 80 + var4 % 20;
         } else {
            var6 = 100 + var4 % 50;
         }

         for (int var7 = 0; var7 < var6; var7++) {
            int var8 = var5[var7];
            var5[var7] = var5[var4 - var7 - 1];
            var5[var4 - var7 - 1] = (byte)var8;
         }

         var1 = Image.createImage(var5, 0, var4);
      } catch (Exception var9) {
         System.err.println("[res] image load failed: " + var0 + ": " + var9);
      }

      return var1;
   }

   // $VF: renamed from: a (java.lang.String) byte[]
   public static final byte[] method_283(String var0) {
      byte[] var1 = null;

      try {
         InputStream var2 = class_28.class.getResourceAsStream(var0);
         DataInputStream var3;
         int var4;
         var1 = var2.readAllBytes();
         var4 = var1.length;
         var2.close();
         int var5;
         if (var4 < 100) {
            var5 = 10 + var4 % 10;
         } else if (var4 < 200) {
            var5 = 50 + var4 % 20;
         } else if (var4 < 300) {
            var5 = 80 + var4 % 20;
         } else {
            var5 = 100 + var4 % 50;
         }

         for (int var6 = 0; var6 < var5; var6++) {
            int var7 = var1[var6];
            var1[var6] = var1[var4 - var6 - 1];
            var1[var4 - var6 - 1] = (byte)var7;
         }
      } catch (Exception var8) {
      }

      return var1;
   }

   // $VF: renamed from: a (java.lang.String) java.lang.Class
   public static final Class method_284(String var0) {
      try {
         return Class.forName(var0);
      } catch (ClassNotFoundException var2) {
         throw new NoClassDefFoundError(var2.getMessage());
      }
   }
}
