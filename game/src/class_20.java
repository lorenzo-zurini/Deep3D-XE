import javax.microedition.lcdui.Image;

// $VF: renamed from: j
public final class class_20 {
   // $VF: renamed from: a int[]
   private int[] field_303;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_304;
   // $VF: renamed from: a v
   private class_5 field_305 = new class_5();

   public class_20() {
      try {
         this.field_304 = class_40.method_412("/data/interface/crosshair.png");
      } catch (Exception var2) {
         var2.printStackTrace();
      }

      this.field_303 = new int[3];
   }

   // $VF: renamed from: a (bn) void
   public final void method_289(class_1 var1) {
      this.field_303[0] = var1.field_13 + 5 * var1.field_10;
      this.field_303[1] = var1.field_14 + 5 * var1.field_11;
      this.field_303[2] = var1.field_15 + 5 * var1.field_12;
      this.field_305.method_170(this.field_303[0], this.field_303[1], this.field_303[2]);
   }

   // $VF: renamed from: a () void
   public final void method_290() {
      this.field_303 = null;
      this.field_304 = null;
   }

   // $VF: renamed from: a (am) void
   public final void method_291(class_111 var1) {
      var1.method_897(this.field_305);
      class_41.field_534.drawImage(this.field_304, this.field_305.field_138, this.field_305.field_139, 3);
   }
}
