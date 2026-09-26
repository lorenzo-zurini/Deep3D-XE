import com.mascotcapsule.micro3d.v3.AffineTrans;
import com.mascotcapsule.micro3d.v3.Effect3D;
import com.mascotcapsule.micro3d.v3.FigureLayout;
import com.mascotcapsule.micro3d.v3.Texture;

// $VF: renamed from: ac
public final class class_104 extends class_101 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.FigureLayout
   private FigureLayout field_1304;
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Effect3D
   public static Effect3D field_1305 = new Effect3D(null, 0, true, null);
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.AffineTrans
   private static AffineTrans field_1306 = new AffineTrans();
   // $VF: renamed from: b int[]
   private static int[] field_1307 = new int[12];
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Texture
   private Texture field_1308;
   // $VF: renamed from: a int[]
   public int[] field_1309;
   // $VF: renamed from: c int[]
   private int[] field_1310;
   // $VF: renamed from: d int[]
   private static int[] field_1311;
   // $VF: renamed from: f int
   private int field_1312;
   // $VF: renamed from: e int[]
   private int[] field_1313;
   // $VF: renamed from: g int
   private int field_1314;

   public class_104(int var1, int var2, int var3, int var4, int var5, int var6, int var7, byte var8) {
      super.field_1286 = var1;
      this.field_1310 = new int[8];
      this.field_1310[0] = this.field_1310[1] = var6;
      this.field_1310[2] = 0;
      this.field_1310[3] = var2;
      this.field_1310[4] = var3;
      this.field_1310[5] = var4;
      this.field_1310[6] = var5;
      this.field_1310[7] = 0;
      this.field_1312 = var7;
      this.field_1309 = new int[3 * var7];
      if (field_1311 == null) {
         field_1311 = new int[1];
      }

      this.field_1304 = null;
      super.field_1290 = var6 << 1;
      this.field_1313 = null;
      switch (var8) {
         case 0:
            this.field_1314 = 0;
            return;
         case 1:
            this.field_1314 = 0;
            return;
         case 2:
            this.field_1314 = 64;
            return;
         case 3:
            this.field_1314 = 96;
      }
   }

   public class_104(class_104 var1) {
      super.field_1286 = var1.field_1286;
      this.field_1310 = var1.field_1310;
      this.field_1312 = var1.field_1312;
      this.field_1309 = new int[3 * this.field_1312];
      System.arraycopy(var1.field_1309, 0, this.field_1309, 0, this.field_1309.length);
      this.field_1304 = null;
      super.field_1290 = var1.field_1290;
      super.field_1280 = var1.field_1280;
      if (var1.field_1313 != null) {
         this.field_1313 = new int[this.field_1312];
         System.arraycopy(var1.field_1313, 0, this.field_1313, 0, this.field_1313.length);
      }
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_104(this);
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      this.field_1309 = null;
      this.field_1310 = null;
      this.field_1308 = null;
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         super.field_1295 = var1.field_1284.method_36(super.field_1295);
         super.field_1295.method_4(super.field_1284);
         var2.method_270(super.field_1294, this);
         this.field_1304 = ((class_112)var1).field_1382;
      }
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1295.method_38(field_1307);
      field_1306.set(field_1307);
      this.field_1304.setAffineTrans(field_1306);
      if (this.field_1313 == null) {
         class_27.field_390
            .renderPrimitives(
               this.field_1308,
               0,
               0,
               this.field_1304,
               field_1305,
               83886080 | this.field_1314 | 4096,
               this.field_1312,
               this.field_1309,
               field_1311,
               this.field_1310,
               field_1311
            );
      } else {
         int var1 = 0;

         for (int var2 = 0; var2 < this.field_1312; var1 += 8) {
            this.field_1310[var1] = this.field_1310[var1 + 1] = this.field_1313[var2];
            var2++;
         }

         class_27.field_390
            .renderPrimitives(
               this.field_1308,
               0,
               0,
               this.field_1304,
               field_1305,
               83886080 | this.field_1314 | 8192,
               this.field_1312,
               this.field_1309,
               field_1311,
               this.field_1310,
               field_1311
            );
      }
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
      this.field_1308 = ((class_121)var1).field_1526[0];
   }

   // $VF: renamed from: a () int[]
   public final int[] method_889() {
      if (this.field_1313 == null) {
         this.field_1313 = new int[this.field_1312];

         for (int var1 = 0; var1 < this.field_1313.length; var1++) {
            this.field_1313[var1] = this.field_1310[0];
         }

         int[] var3 = new int[8 * this.field_1312];

         for (int var2 = 0; var2 < var3.length; var2 += 8) {
            var3[var2] = var3[var2 + 1] = this.field_1310[0];
            var3[var2 + 2] = 0;
            var3[var2 + 3] = this.field_1310[3];
            var3[var2 + 4] = this.field_1310[4];
            var3[var2 + 5] = this.field_1310[5];
            var3[var2 + 6] = this.field_1310[6];
            var3[var2 + 7] = 0;
         }

         this.field_1310 = var3;
      }

      return this.field_1313;
   }
}
