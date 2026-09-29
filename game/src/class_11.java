import javax.microedition.lcdui.Image;

// $VF: renamed from: i
public final class class_11 {
   // $VF: renamed from: a int[]
   private int[] field_115;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_116;
   // $VF: renamed from: a x
   private class_3 field_117 = new class_3();

   public class_11() {
      try {
         this.field_116 = class_28.method_282("/data/interface/crosshair.png");
      } catch (Exception var2) {
         var2.printStackTrace();
      }

      this.field_115 = new int[3];
   }

   // $VF: renamed from: a (bn) void
   public final void method_55(class_57 var1) {
      this.field_115[0] = var1.field_698 + 5 * var1.field_695;
      this.field_115[1] = var1.field_699 + 5 * var1.field_696;
      this.field_115[2] = var1.field_700 + 5 * var1.field_697;
      this.field_117.method_10(this.field_115[0], this.field_115[1], this.field_115[2]);
   }

   // $VF: renamed from: a () void
   public final void method_56() {
      this.field_115 = null;
      this.field_116 = null;
   }

   // $VF: renamed from: a (an) void
   public final void method_57(class_106 var1) {
      var1.method_883(this.field_117);
      // Deep3D-PC: pinned where it rests in level flight (the projected aim
      // point jittered with every movement of the chase camera)
      int var2 = class_84.field_1120 >> 1;
      int var3 = class_84.field_1121 * 157 / 320;
      class_84.field_1117.drawImage(this.field_116, var2, var3, 3);
      org.deep3d.MouseFlight.crosshair(var2, var3);
   }
}
