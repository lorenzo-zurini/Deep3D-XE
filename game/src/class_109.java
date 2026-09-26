import javax.microedition.m3g.Appearance;
import javax.microedition.m3g.CompositingMode;
import javax.microedition.m3g.Mesh;
import javax.microedition.m3g.PolygonMode;
import javax.microedition.m3g.Texture2D;
import javax.microedition.m3g.Transform;
import javax.microedition.m3g.TriangleStripArray;
import javax.microedition.m3g.VertexArray;
import javax.microedition.m3g.VertexBuffer;

// $VF: renamed from: u
public final class class_109 extends class_108 {
   // $VF: renamed from: a javax.microedition.m3g.Transform
   private static Transform field_1369 = new Transform();
   // $VF: renamed from: a float[]
   private static float[] field_1370 = new float[16];
   // $VF: renamed from: a javax.microedition.m3g.Appearance
   private Appearance field_1371;
   // $VF: renamed from: g int
   private int field_1372;
   // $VF: renamed from: a javax.microedition.m3g.Mesh
   private Mesh field_1373;
   // $VF: renamed from: a javax.microedition.m3g.VertexBuffer
   private VertexBuffer field_1374;
   // $VF: renamed from: a javax.microedition.m3g.VertexArray
   private VertexArray field_1375;
   // $VF: renamed from: b javax.microedition.m3g.VertexArray
   private VertexArray field_1376;
   // $VF: renamed from: a javax.microedition.m3g.TriangleStripArray
   private TriangleStripArray field_1377;
   // $VF: renamed from: a short[]
   private short[] field_1378;
   // $VF: renamed from: a byte[]
   private byte[] field_1379;
   // $VF: renamed from: b float[]
   private static float[] field_1380 = new float[]{0.0F, 0.0F, 0.0F};
   // $VF: renamed from: c float[]
   private static float[] field_1381 = new float[]{0.0F, 0.0F};
   // $VF: renamed from: h int
   private int field_1382;
   // $VF: renamed from: c int
   public int field_1383 = -1;

   public class_109(int var1, int var2, byte var3) {
      super.field_1344 = var1;
      if (this.field_1371 == null) {
         this.field_1371 = new Appearance();
         if (var3 != 0) {
            CompositingMode var4 = new CompositingMode();
            switch (var3) {
               case 1:
               case 3:
                  var4.setBlending(64);
                  break;
               case 2:
                  var4.setBlending(65);
            }

            var4.setDepthWriteEnable(false);
            var4.setDepthTestEnable(true);
            this.field_1371.setCompositingMode(var4);
         }

         PolygonMode var8;
         (var8 = new PolygonMode()).setCulling(162);
         var8.setShading(164);
         var8.setPerspectiveCorrectionEnable(false);
         this.field_1371.setPolygonMode(var8);
      }

      this.field_1372 = var2;
      this.field_1378 = new short[12 * var2];
      this.field_1379 = new byte[8 * var2];
      this.field_1374 = new VertexBuffer();
      this.field_1375 = new VertexArray(4 * var2, 3, 2);
      this.field_1376 = new VertexArray(4 * var2, 2, 1);
      this.field_1375.set(0, 4 * var2, this.field_1378);
      this.field_1376.set(0, 4 * var2, this.field_1379);
      this.field_1374.setPositions(this.field_1375, 1.0F, field_1380);
      this.field_1374.setTexCoords(0, this.field_1376, 0.00390625F, field_1381);
      int[] var9 = new int[6 * var2];
      int var5 = 0;

      for (int var6 = 0; var6 < var9.length; var5 += 4) {
         var9[var6] = var5;
         var9[var6 + 1] = var5 + 2;
         var9[var6 + 2] = var5 + 1;
         var9[var6 + 3] = var5 + 3;
         var9[var6 + 4] = var5 + 2;
         var9[var6 + 5] = var5;
         var6 += 6;
      }

      int[] var10 = new int[2 * var2];

      for (int var7 = 0; var7 < var10.length; var7++) {
         var10[var7] = 3;
      }

      this.field_1377 = new TriangleStripArray(var9, var10);
      this.field_1373 = new Mesh(this.field_1374, this.field_1377, this.field_1371);
   }

   public class_109(class_109 var1) {
      this.field_1372 = var1.field_1372;
      this.field_1373 = var1.field_1373;
      this.field_1374 = var1.field_1374;
      this.field_1375 = var1.field_1375;
      this.field_1376 = var1.field_1376;
      this.field_1377 = var1.field_1377;
      this.field_1378 = var1.field_1378;
      this.field_1379 = var1.field_1379;
      this.field_1382 = var1.field_1382;
      super.field_1348 = var1.field_1348;
      super.field_1338 = var1.field_1338;
      super.field_1367 = var1.field_1367;
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_109(this);
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      this.field_1373 = null;
      this.field_1374 = null;
      this.field_1375 = null;
      this.field_1376 = null;
      this.field_1377 = null;
      this.field_1378 = null;
      this.field_1379 = null;
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      super.field_1368.method_505(field_1370);
      field_1369.set(field_1370);
      class_72.field_1016.render(this.field_1373, field_1369);
   }

   // $VF: renamed from: a (an, t) void
   public final void method_837(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         super.field_1368 = var1.field_1342.method_503(super.field_1368);
         super.field_1368.method_471(super.field_1342);
         var2.method_30(super.field_1367, this);
      }
   }

   // $VF: renamed from: a (int[], int[]) void
   public final void method_896(int[] var1, int[] var2) {
      for (int var3 = 0; var3 < var1.length; var3++) {
         this.field_1378[var3] = (short)var1[var3];
      }

      this.field_1375.set(0, 4 * this.field_1372, this.field_1378);
      this.field_1373.getVertexBuffer().setPositions(this.field_1375, 1.0F, field_1380);

      for (int var5 = 0; var5 < var2.length; var5++) {
         this.field_1379[var5] = (byte)var2[var5];
      }

      this.field_1376.set(0, 4 * this.field_1372, this.field_1379);
      this.field_1373.getVertexBuffer().setTexCoords(0, this.field_1376, 1.0F / this.field_1382, field_1381);
      this.field_1373.getVertexBuffer().setDefaultColor(this.field_1383);
      super.field_1348 = 0;

      for (int var6 = 0; var6 < var1.length; var6 += 3) {
         int var4 = var1[var6] * var1[var6] + var1[var6 + 1] * var1[var6 + 1] + var1[var6 + 2] * var1[var6 + 2];
         if (super.field_1348 < var4) {
            super.field_1348 = var4;
         }
      }

      super.field_1348 = class_16.method_96(super.field_1348);
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
      Texture2D var2;
      (var2 = new Texture2D(((class_45)var1).field_476[0].getImage())).setBlending(227);
      var2.setFiltering(208, 210);
      var2.setWrapping(240, 240);
      this.field_1371.setTexture(0, var2);
      this.field_1382 = var2.getImage().getWidth();
   }
}
