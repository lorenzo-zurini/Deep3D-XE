import com.mascotcapsule.micro3d.v3.ActionTable;
import com.mascotcapsule.micro3d.v3.AffineTrans;
import com.mascotcapsule.micro3d.v3.Effect3D;
import com.mascotcapsule.micro3d.v3.Figure;
import com.mascotcapsule.micro3d.v3.FigureLayout;
import com.mascotcapsule.micro3d.v3.Light;
import com.mascotcapsule.micro3d.v3.Vector3D;

// $VF: renamed from: dg
public final class class_110 extends class_101 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Light
   public static Light field_1352 = new Light(new Vector3D(1134, 3929, 0), 4096, 1024);
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Effect3D
   public static Effect3D field_1353 = null;
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.AffineTrans
   private static AffineTrans field_1354 = new AffineTrans();
   // $VF: renamed from: a int[]
   private static int[] field_1355 = new int[12];
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Figure
   private Figure field_1356;
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.ActionTable
   private ActionTable field_1357;
   // $VF: renamed from: f int
   private int field_1358;
   // $VF: renamed from: g int
   private int field_1359;
   // $VF: renamed from: h int
   private int field_1360;
   // $VF: renamed from: i int
   private int field_1361;
   // $VF: renamed from: a long
   private long field_1362;
   // $VF: renamed from: d boolean
   private boolean field_1363;
   // $VF: renamed from: a byte
   private byte field_1364;
   // $VF: renamed from: j int
   private int field_1365 = 0;
   // $VF: renamed from: f bn
   private static class_1 field_1366 = new class_1();
   // $VF: renamed from: g bn
   private static class_1 field_1367 = new class_1();
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.FigureLayout
   private FigureLayout field_1368;

   public class_110(int var1, String var2, int var3) {
      if (field_1353 == null) {
         field_1353 = new Effect3D(field_1352, 0, true, null);
      }

      super.field_1286 = var1;
      super.field_1290 = var3;

      try {
         this.field_1356 = new Figure(class_40.method_413(var2 + ".mbac"));
      } catch (Exception var6) {
         this.field_1356 = null;
      }

      try {
         byte[] var4;
         if ((var4 = class_40.method_413(var2 + ".mtra")) != null) {
            this.field_1357 = new ActionTable(var4);
            this.field_1363 = true;
            this.field_1364 = 2;
            this.field_1358 = this.field_1357.getNumFrames(0) >> 16;
            this.field_1359 = this.field_1361 = 0;
            this.field_1360 = this.field_1358;
            this.field_1362 = -1L;
         }
      } catch (Exception var5) {
         this.field_1357 = null;
         this.field_1363 = false;
      }

      this.field_1368 = null;
   }

   public class_110(class_110 var1) {
      super.field_1290 = var1.field_1290;
      this.field_1356 = var1.field_1356;
      this.field_1357 = var1.field_1357;
      super.field_1294 = var1.field_1294;
      super.field_1280 = var1.field_1280;
      this.field_1368 = null;
      this.field_1363 = var1.field_1363;
      this.field_1364 = var1.field_1364;
      this.field_1358 = var1.field_1358;
      this.field_1359 = var1.field_1359;
      this.field_1360 = var1.field_1360;
      this.field_1362 = var1.field_1362;
      super.field_1286 = var1.field_1286;
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_110(this);
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280 && var1.method_898(super.field_1285) != 0) {
         super.field_1295 = var1.field_1284.method_36(super.field_1295);
         if (this.field_1365 != 0) {
            field_1366.method_2();
            field_1366.method_24(0, 0, this.field_1365);
            field_1367 = super.field_1284.method_6(field_1366, field_1367);
            super.field_1295.method_4(field_1367);
         } else {
            super.field_1295.method_4(super.field_1284);
         }

         var2.method_270(super.field_1294, this);
         this.field_1368 = ((class_112)var1).field_1382;
      }
   }

   // $VF: renamed from: g (int) void
   public final void method_877(int var1) {
      this.field_1365 = var1;
   }

   // $VF: renamed from: b (am, t) void
   public final void method_834(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         super.field_1295 = var1.field_1284.method_36(super.field_1295);
         super.field_1295.method_4(super.field_1284);
         var2.method_270(super.field_1294, this);
         this.field_1368 = ((class_112)var1).field_1382;
      }
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1295.method_38(field_1355);
      field_1354.set(field_1355);
      this.field_1368.setAffineTrans(field_1354);
      if (this.field_1357 != null) {
         if (this.field_1364 == 3) {
            this.field_1356.setPosture(this.field_1357, 0, this.field_1360 - this.field_1361 << 16);
         } else {
            this.field_1356.setPosture(this.field_1357, 0, this.field_1361 << 16);
         }
      }

      class_27.field_390.renderFigure(this.field_1356, 0, 0, this.field_1368, field_1353);
   }

   // $VF: renamed from: a (long) void
   public final void method_885(long var1) {
      if (this.field_1363) {
         if (this.field_1362 == -1L) {
            this.field_1362 = var1;
         }

         this.field_1361 = this.field_1359 + (int)((var1 - this.field_1362) / super.field_1277);
         if (this.field_1361 > this.field_1360) {
            if (this.field_1364 == 2) {
               this.field_1361 = this.field_1359;
               this.field_1362 = var1 - (this.field_1361 - this.field_1359) * super.field_1277;
               return;
            }

            this.field_1363 = false;
            this.field_1361 = this.field_1360;
            this.field_1362 = -1L;
         }
      }
   }

   // $VF: renamed from: e (int) void
   public final void method_869(int var1) {
      super.field_1277 = var1 > 0 ? var1 : 1;
   }

   // $VF: renamed from: e () int
   public final int method_871() {
      return this.field_1361;
   }

   // $VF: renamed from: f (int) void
   public final void method_870(int var1) {
      this.field_1361 = var1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_872(int var1, int var2) {
      this.field_1359 = var1 >= 0 && var1 <= this.field_1358 ? var1 : 0;
      this.field_1360 = var2 >= 0 && var2 <= this.field_1358 ? var2 : this.field_1358;
      this.field_1361 = this.field_1361 < var1 ? var1 : (this.field_1361 > var2 ? var2 : this.field_1361);
      this.field_1362 = -1L;
   }

   // $VF: renamed from: a (byte) void
   public final void method_873(byte var1) {
      this.field_1364 = var1;
      this.field_1362 = -1L;
      this.field_1363 = this.field_1358 > 0;
   }

   // $VF: renamed from: a () void
   public final void method_874() {
      this.field_1363 = false;
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
      this.field_1356.setTexture(((class_121)var1).field_1526);
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      if (this.field_1356 != null) {
         this.field_1356.dispose();
      }

      this.field_1356 = null;
   }
}
