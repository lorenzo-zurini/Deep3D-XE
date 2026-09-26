import com.mascotcapsule.micro3d.v3.AffineTrans;
import com.mascotcapsule.micro3d.v3.Effect3D;
import com.mascotcapsule.micro3d.v3.FigureLayout;
import com.mascotcapsule.micro3d.v3.Texture;

// $VF: renamed from: au
public final class class_105 extends class_101 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.FigureLayout
   private FigureLayout field_1315;
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Effect3D
   public static Effect3D field_1316 = new Effect3D(null, 0, true, null);
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.AffineTrans
   private static AffineTrans field_1317 = new AffineTrans();
   // $VF: renamed from: a int[]
   private static int[] field_1318 = new int[12];
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Texture
   private Texture field_1319;
   // $VF: renamed from: b int[]
   private int[] field_1320;
   // $VF: renamed from: c int[]
   private int[] field_1321;
   // $VF: renamed from: d int[]
   private static int[] field_1322 = new int[1];
   // $VF: renamed from: f int
   private int field_1323;
   // $VF: renamed from: g int
   private int field_1324;

   public class_105(int var1, int var2, byte var3) {
      super.field_1286 = var1;
      this.field_1323 = var2;
      this.field_1320 = new int[12 * var2];
      this.field_1321 = new int[8 * var2];
      switch (var3) {
         case 0:
            this.field_1324 = 0;
            return;
         case 1:
            this.field_1324 = 0;
            return;
         case 2:
            this.field_1324 = 64;
            return;
         case 3:
            this.field_1324 = 96;
      }
   }

   public class_105(class_105 var1) {
      super.field_1286 = var1.field_1286;
      this.field_1323 = var1.field_1323;
      this.field_1320 = new int[12 * this.field_1323];
      this.field_1321 = new int[8 * this.field_1323];
      System.arraycopy(var1.field_1320, 0, this.field_1320, 0, var1.field_1320.length);
      System.arraycopy(var1.field_1321, 0, this.field_1321, 0, var1.field_1321.length);
      this.field_1319 = var1.field_1319;
      super.field_1294 = var1.field_1294;
      super.field_1290 = var1.field_1290;
      super.field_1280 = var1.field_1280;
      super.field_1284.method_3(var1.field_1284);
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_105(this);
   }

   // $VF: renamed from: d () void
   public final void method_884() {
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         super.field_1295 = var1.field_1284.method_36(super.field_1295);
         super.field_1295.method_4(super.field_1284);
         var2.method_270(super.field_1294, this);
         this.field_1315 = ((class_112)var1).field_1382;
      }
   }

   // $VF: renamed from: b (am, t) void
   public final void method_834(class_111 var1, class_17 var2) {
      this.method_833(var1, var2);
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1295.method_38(field_1318);
      field_1317.set(field_1318);
      this.field_1315.setAffineTrans(field_1317);
      class_27.field_390
         .renderPrimitives(
            this.field_1319,
            0,
            0,
            this.field_1315,
            field_1316,
            67121152 | this.field_1324,
            this.field_1323,
            this.field_1320,
            field_1322,
            this.field_1321,
            field_1322
         );
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
      this.field_1319 = ((class_121)var1).field_1526[0];
   }

   // $VF: renamed from: a (int[], int[]) void
   public final void method_890(int[] var1, int[] var2) {
      this.field_1320 = var1;
      this.field_1321 = var2;
      super.field_1290 = 0;

      for (byte var3 = 0; var3 < this.field_1320.length; var3 += 3) {
         int var4 = this.field_1320[var3] * this.field_1320[var3]
            + this.field_1320[var3 + 1] * this.field_1320[var3 + 1]
            + this.field_1320[var3 + 2] * this.field_1320[var3 + 2];
         if (super.field_1290 < var4) {
            super.field_1290 = var4;
         }
      }

      super.field_1290 = class_124.method_941(super.field_1290);
   }
}
