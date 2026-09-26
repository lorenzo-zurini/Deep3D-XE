import javax.microedition.m3g.Appearance;
import javax.microedition.m3g.CompositingMode;
import javax.microedition.m3g.Group;
import javax.microedition.m3g.Loader;
import javax.microedition.m3g.Mesh;
import javax.microedition.m3g.Node;
import javax.microedition.m3g.Object3D;
import javax.microedition.m3g.Texture2D;
import javax.microedition.m3g.Transform;

// $VF: renamed from: ag
public final class class_117 extends class_108 {
   // $VF: renamed from: a javax.microedition.m3g.Transform
   private static Transform field_1438 = new Transform();
   // $VF: renamed from: a float[]
   private static float[] field_1439 = new float[16];
   // $VF: renamed from: a javax.microedition.m3g.Node
   private Node field_1440;
   // $VF: renamed from: a javax.microedition.m3g.CompositingMode
   private static CompositingMode field_1441;
   // $VF: renamed from: c int
   private int field_1442;

   public class_117(String var1) {
      this.method_911(var1);
      super.field_1348 = 0;
      if (field_1441 == null) {
         field_1441 = new CompositingMode();
         field_1441.setBlending(64);
         field_1441.setDepthTestEnable(true);
         field_1441.setDepthWriteEnable(false);
      }
   }

   public class_117(class_117 var1) {
      super.field_1348 = 0;
      this.field_1440 = var1.field_1440;
      super.field_1367 = var1.field_1367;
      super.field_1338 = var1.field_1338;
   }

   // $VF: renamed from: a (java.lang.String) void
   private void method_911(String var1) {
      try {
         Object3D[] var3 = Loader.load(class_28.method_283(var1 + ".m3g"), 0);

         for (int var4 = 0; var4 < var3.length; var4++) {
            if (var3[var4] instanceof Group) {
               this.field_1440 = (Node)var3[var4];
               break;
            }
         }
      } catch (Exception var5) {
         this.field_1440 = null;
      }
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      super.field_1368.method_505(field_1439);
      field_1439[3] = field_1439[7] = field_1439[11] = 0.0F;
      field_1439[7] = this.field_1442;
      field_1438.set(field_1439);
      class_72.field_1016.render(this.field_1440, field_1438);
   }

   // $VF: renamed from: a (an, t) void
   public final void method_837(class_106 var1, class_4 var2) {
      if (super.field_1338) {
         super.field_1368 = var1.field_1342.method_503(super.field_1368);
         var2.method_30(super.field_1367, this);
      }
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_117(this);
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
      this.method_912((Group)this.field_1440, ((class_45)var1).field_476);
   }

   // $VF: renamed from: a (javax.microedition.m3g.Group, javax.microedition.m3g.Texture2D[]) void
   private void method_912(Group var1, Texture2D[] var2) {
      for (int var3 = 0; var3 < var1.getChildCount(); var3++) {
         Node var4;
         if ((var4 = var1.getChild(var3)) instanceof Mesh) {
            int var5 = ((Mesh)var4).getUserID();

            for (int var6 = 0; var6 < ((Mesh)var4).getSubmeshCount(); var6++) {
               Appearance var7;
               (var7 = ((Mesh)var4).getAppearance(var6)).setMaterial(null);
               var7.setCompositingMode(field_1441);
               if (var7.getTexture(0) != null) {
                  if (var2 != null) {
                     if (var5 < var2.length) {
                        var7.setTexture(0, var2[var5]);
                     } else {
                        var7.setTexture(0, var2[0]);
                     }
                  } else {
                     var7.setTexture(0, null);
                  }
               }
            }
         } else if (var4 instanceof Group) {
            this.method_912((Group)var4, var2);
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      this.field_1440 = null;
   }
}
