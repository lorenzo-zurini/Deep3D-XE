import com.mascotcapsule.micro3d.v3.Graphics3D;
import javax.microedition.lcdui.Graphics;

// $VF: renamed from: by
public final class class_27 extends class_26 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Graphics3D
   public static Graphics3D field_390;

   public class_27() {
      field_390 = new Graphics3D();
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Graphics) void
   public final void method_333(Graphics var1) {
      try {
         field_390.bind(var1);
      } catch (Exception var3) {
         field_390.release(var1);
      }
   }

   // $VF: renamed from: a () void
   public final void method_335() {
      try {
         field_390.flush();
      } catch (Exception var2) {
      }
   }

   // $VF: renamed from: b (javax.microedition.lcdui.Graphics) void
   public final void method_334(Graphics var1) {
      try {
         field_390.release(var1);
      } catch (Exception var3) {
      }
   }
}
