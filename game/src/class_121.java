import com.mascotcapsule.micro3d.v3.Texture;

// $VF: renamed from: ax
public final class class_121 extends class_120 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.Texture[]
   public Texture[] field_1526;

   public class_121(String[] var1) {
      if (var1 != null) {
         try {
            this.field_1526 = new Texture[var1.length];

            for (int var2 = 0; var2 < var1.length; var2++) {
               System.out.println(var1[var2]);
               boolean var3 = var1[var2].indexOf("spec") == -1;
               this.field_1526[var2] = new Texture(class_40.method_413(var1[var2] + ".bmp"), var3);
            }

            return;
         } catch (Exception var4) {
            this.field_1526 = null;
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_930() {
      if (this.field_1526 != null) {
         for (int var1 = 0; var1 < this.field_1526.length; var1++) {
            this.field_1526[var1].dispose();
            this.field_1526[var1] = null;
         }

         this.field_1526 = null;
      }
   }
}
