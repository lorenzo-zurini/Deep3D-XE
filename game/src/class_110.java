import javax.microedition.m3g.Appearance;
import javax.microedition.m3g.CompositingMode;
import javax.microedition.m3g.Mesh;
import javax.microedition.m3g.PolygonMode;
import javax.microedition.m3g.Texture2D;
import javax.microedition.m3g.Transform;
import javax.microedition.m3g.TriangleStripArray;
import javax.microedition.m3g.VertexArray;
import javax.microedition.m3g.VertexBuffer;

// $VF: renamed from: cq
public final class class_110 extends class_108 {
   // $VF: renamed from: a javax.microedition.m3g.Transform
   private static Transform field_1384 = new Transform();
   // $VF: renamed from: b x
   private static class_3 field_1385 = new class_3();
   // $VF: renamed from: a javax.microedition.m3g.Appearance
   private Appearance field_1386;
   // $VF: renamed from: c int
   private int field_1387;
   // $VF: renamed from: a javax.microedition.m3g.Mesh
   private Mesh field_1388;
   // $VF: renamed from: a int[]
   public int[] field_1389;
   // $VF: renamed from: b int[]
   public int[] field_1390;
   // $VF: renamed from: c int[]
   private int[] field_1391;
   // $VF: renamed from: a float
   private float field_1392;

   public class_110(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, byte var9) {
      super.field_1344 = var1;
      this.field_1386 = new Appearance();
      if (var9 != 0) {
         CompositingMode var10 = new CompositingMode();
         switch (var9) {
            case 1:
            case 3:
               var10.setBlending(64);
               break;
            case 2:
               var10.setBlending(65);
         }

         var10.setDepthWriteEnable(false);
         var10.setDepthTestEnable(true);
         this.field_1386.setCompositingMode(var10);
      }

      PolygonMode var21;
      (var21 = new PolygonMode()).setCulling(160);
      var21.setShading(164);
      var21.setPerspectiveCorrectionEnable(false);
      this.field_1386.setPolygonMode(var21);
      this.field_1387 = var8;
      this.field_1389 = new int[3 * var8];
      this.field_1390 = new int[var8];

      for (int var11 = 0; var11 < this.field_1390.length; var11++) {
         this.field_1390[var11] = -1;
      }

      VertexBuffer var22 = new VertexBuffer();
      VertexArray var12 = new VertexArray(4, 3, 1);
      VertexArray var13 = new VertexArray(4, 2, 2);
      byte[] var14 = new byte[]{-1, 1, 0, 1, 1, 0, 1, -1, 0, -1, -1, 0};
      var12.set(0, 4, var14);
      short[] var15 = new short[]{(short)var3, (short)var4, (short)var5, (short)var4, (short)var5, (short)var6, (short)var3, (short)var6};
      var13.set(0, 4, var15);
      float[] var16 = new float[]{0.0F, 0.0F, 0.0F};
      var22.setPositions(var12, 1.0F, var16);
      float[] var17 = new float[]{0.0F, 0.0F};
      var22.setTexCoords(0, var13, 1.0F / var2, var17);
      int[] var18 = new int[]{0, 2, 1, 3, 2, 0};
      int[] var19 = new int[]{3, 3};
      TriangleStripArray var20 = new TriangleStripArray(var18, var19);
      this.field_1388 = new Mesh(var22, var20, this.field_1386);
      super.field_1348 = var7 >> 1;
      this.field_1392 = var7 >> 1;
      this.field_1391 = null;
   }

   public class_110(class_110 var1) {
      this.field_1387 = var1.field_1387;
      this.field_1389 = new int[3 * this.field_1387];
      this.field_1390 = new int[this.field_1387];
      System.arraycopy(var1.field_1390, 0, this.field_1390, 0, this.field_1390.length);
      System.arraycopy(var1.field_1389, 0, this.field_1389, 0, this.field_1389.length);
      this.field_1388 = var1.field_1388;
      super.field_1348 = var1.field_1348;
      this.field_1392 = var1.field_1392;
      super.field_1338 = var1.field_1338;
      super.field_1367 = var1.field_1367;
      if (var1.field_1391 != null) {
         this.field_1391 = new int[this.field_1387];
         System.arraycopy(var1.field_1391, 0, this.field_1391, 0, this.field_1391.length);
      }
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_110(this);
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      this.field_1386 = null;
      this.field_1388 = null;
      this.field_1389 = null;
      this.field_1390 = null;
      this.field_1391 = null;
   }

   // $VF: renamed from: a (an, t) void
   public final void method_837(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         super.field_1368 = var1.field_1342.method_503(super.field_1368);
         super.field_1368.method_471(super.field_1342);
         var2.method_30(super.field_1367, this);
      }
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_1387; var1 += 3) {
         field_1385.method_10(this.field_1389[var1], this.field_1389[var1 + 1], this.field_1389[var1 + 2]);
         field_1385 = super.field_1368.method_506(field_1385);
         field_1384.setIdentity();
         field_1384.postTranslate(field_1385.field_37, field_1385.field_38, field_1385.field_39);
         if (this.field_1391 != null) {
            field_1384.postScale(this.field_1391[var2] >> 1, this.field_1391[var2] >> 1, this.field_1391[var2] >> 1);
         } else {
            field_1384.postScale(this.field_1392, this.field_1392, this.field_1392);
         }

         this.field_1388.getVertexBuffer().setDefaultColor(this.field_1390[var2]);
         class_72.field_1016.render(this.field_1388, field_1384);
         var2++;
      }
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
      Texture2D var2;
      (var2 = new Texture2D(((class_45)var1).field_476[0].getImage())).setBlending(227);
      var2.setFiltering(208, 210);
      var2.setWrapping(240, 240);
      this.field_1386.setTexture(0, var2);
   }

   // $VF: renamed from: a () int[]
   public final int[] method_897() {
      if (this.field_1391 == null) {
         this.field_1391 = new int[this.field_1387];

         for (int var1 = 0; var1 < this.field_1391.length; var1++) {
            this.field_1391[var1] = (int)this.field_1392;
         }
      }

      return this.field_1391;
   }
}
