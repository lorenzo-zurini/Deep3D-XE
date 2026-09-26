import com.mascotcapsule.micro3d.v3.AffineTrans;
import com.mascotcapsule.micro3d.v3.Effect3D;
import com.mascotcapsule.micro3d.v3.Figure;
import com.mascotcapsule.micro3d.v3.FigureLayout;

// $VF: renamed from: g
public final class class_102 extends class_101 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Effect3D
   public static Effect3D field_1296 = new Effect3D(null, 0, true, null);
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.AffineTrans
   private static AffineTrans field_1297 = new AffineTrans();
   // $VF: renamed from: a int[]
   private static int[] field_1298 = new int[12];
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Figure
   private Figure field_1299;
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.FigureLayout
   private FigureLayout field_1300;

   public class_102(int var1, String var2) {
      super.field_1286 = var1;
      super.field_1290 = 0;

      try {
         this.field_1299 = new Figure(class_40.method_413(var2 + ".mbac"));
         System.out.println("loading V3-mesh: " + var2 + ".mbac");
      } catch (Exception var4) {
         this.field_1299 = null;
      }

      this.field_1300 = null;
   }

   public class_102(class_102 var1) {
      super.field_1290 = 0;
      this.field_1299 = var1.field_1299;
      super.field_1294 = var1.field_1294;
      super.field_1286 = var1.field_1286;
      this.field_1300 = null;
      super.field_1280 = var1.field_1280;
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_102(this);
   }

   // $VF: renamed from: a (am, t) void
   public final void method_833(class_111 var1, class_17 var2) {
      if (super.field_1280) {
         super.field_1295 = var1.field_1284.method_36(super.field_1295);
         var2.method_270(super.field_1294, this);
         this.field_1300 = ((class_112)var1).field_1382;
      }
   }

   // $VF: renamed from: b (am, t) void
   public final void method_834(class_111 var1, class_17 var2) {
      this.method_833(var1, var2);
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1295.method_38(field_1298);
      field_1297.set(field_1298);
      field_1297.m03 = field_1297.m13 = field_1297.m23 = 0;
      this.field_1300.setAffineTrans(field_1297);
      class_27.field_390.renderFigure(this.field_1299, 0, 0, this.field_1300, field_1296);
   }

   // $VF: renamed from: a (cc) void
   public final void method_883(class_120 var1) {
      this.field_1299.setTexture(((class_121)var1).field_1526);
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      if (this.field_1299 != null) {
         this.field_1299.dispose();
      }

      this.field_1299 = null;
   }
}
