import javax.microedition.lcdui.Image;
import javax.microedition.m3g.Image2D;
import javax.microedition.m3g.Texture2D;

// $VF: renamed from: r
public final class class_45 extends class_44 {
   // $VF: renamed from: a javax.microedition.m3g.Texture2D[]
   public Texture2D[] field_476;

   public class_45(String[] var1) {
      if (var1 != null) {
         this.field_476 = new Texture2D[var1.length];

         for (int var2 = 0; var2 < var1.length; var2++) {
            try {
               Image var3 = class_28.method_282(var1[var2] + ".png");
               Image2D var4 = new Image2D(100, var3);
               this.field_476[var2] = new Texture2D(var4);
               this.field_476[var2].setBlending(228);
               this.field_476[var2].setWrapping(241, 241);
            } catch (Exception var5) {
               this.field_476 = null;
            }
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_387() {
      if (this.field_476 != null) {
         for (int var1 = 0; var1 < this.field_476.length; var1++) {
            this.field_476[var1] = null;
         }

         this.field_476 = null;
      }
   }
}
