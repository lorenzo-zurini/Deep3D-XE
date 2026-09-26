import javax.microedition.lcdui.Graphics;
import javax.microedition.m3g.Background;
import javax.microedition.m3g.Graphics3D;

// $VF: renamed from: w
public final class class_72 extends class_71 {
   // $VF: renamed from: a javax.microedition.m3g.Graphics3D
   public static Graphics3D field_1016;
   // $VF: renamed from: a javax.microedition.m3g.Background
   private static Background field_1017;

   public class_72() {
      field_1016 = Graphics3D.getInstance();
      if (field_1017 == null) {
         field_1017 = new Background();
         field_1017.setColorClearEnable(false);
         field_1017.setDepthClearEnable(true);
      }
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Graphics) void
   public final void method_683(Graphics var1) {
      try {
         field_1016.bindTarget(var1);
      } catch (Exception var3) {
         field_1016.releaseTarget();
      }
   }

   // $VF: renamed from: a () void
   public final void method_685() {
      try {
         field_1016.clear(field_1017);
      } catch (Exception var2) {
      }
   }

   // $VF: renamed from: b (javax.microedition.lcdui.Graphics) void
   public final void method_684(Graphics var1) {
      try {
         field_1016.releaseTarget();
      } catch (Exception var3) {
      }
   }
}
