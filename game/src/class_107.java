import javax.microedition.m3g.Camera;
import javax.microedition.m3g.Transform;

// $VF: renamed from: bw
public final class class_107 extends class_106 {
   // $VF: renamed from: a javax.microedition.m3g.Camera
   public Camera field_1362;
   // $VF: renamed from: a javax.microedition.m3g.Transform
   private static Transform field_1363 = new Transform();

   public class_107(int var1, int var2, int var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
   }

   public class_107(class_107 var1) {
      super(var1);
      this.field_1362 = var1.field_1362;
      field_1363.set(field_1363);
   }

   // $VF: renamed from: g (int, int, int) void
   public final void method_881(int var1, int var2, int var3) {
      float var4 = 0.8F;
      super.method_881(var1, var2, var3);
      if (this.field_1362 == null) {
         this.field_1362 = new Camera();
      }

      if (super.field_1358 != 0 && super.field_1359 != 0) {
         var4 = (float)super.field_1358 / super.field_1359;
      }

      this.field_1362.setPerspective(var1 * 0.087890625F, var4, var2, var3);
   }

   // $VF: renamed from: c () void
   public final void method_885() {
      if (class_72.field_1016 != null) {
         class_72.field_1016.setCamera(this.field_1362, field_1363);
      }
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_107(this);
   }
}
