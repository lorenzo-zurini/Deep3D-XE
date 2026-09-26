import javax.microedition.lcdui.Image;

// $VF: renamed from: y
public final class class_14 {
   // $VF: renamed from: a int
   private int field_185;
   // $VF: renamed from: b int
   private int field_186;
   // $VF: renamed from: c int
   private int field_187;
   // $VF: renamed from: d int
   private int field_188;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_189;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_190;
   // $VF: renamed from: e int
   private int field_191;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_192;

   public class_14(int var1, int var2, int var3) {
      this.field_185 = var1;
      this.field_186 = var2;
      this.field_187 = var3;
      this.field_188 = class_41.field_538 / 2;
   }

   public class_14() {
      this(10, class_41.field_538 / 2, class_41.field_537 - 20);
   }

   // $VF: renamed from: a (int, int) void
   public final void method_225(int var1, int var2) {
      this.field_192 = class_40.method_412("/data/interface/medal_" + var2 + ".png");
      this.field_189 = class_50.method_499(class_41.field_533.method_297(class_22.field_314[var1][0]), this.field_187 - 10 - 13 - 4);
      this.field_190 = class_50.method_499(
         class_3.method_149(class_41.field_533.method_297(class_22.field_314[var1][1]), class_58.field_805[var1][var2 - 1] + ""), this.field_187 - 10
      );
      this.field_186 = (class_41.field_538 >> 1) - (class_50.method_497(this.field_190) + 16 + 4 + 2 * class_50.method_494() >> 1);
      this.field_191 = this.field_186 + this.field_190.length * class_50.method_494() + 16 + 4 + 10 + 2;
      this.field_188 = this.field_191 + class_50.method_494() + 5 - this.field_186;
   }

   // $VF: renamed from: a () void
   public final void method_226() {
      class_69.method_659();
      class_69.method_668(class_41.field_533.method_297(163), this.field_185, this.field_186, this.field_187, this.field_188, true);
      class_41.field_534.drawImage(this.field_192, this.field_185 + 5, this.field_186 + 10 + 2, 0);
      class_50.method_488(this.field_189, this.field_185 + 5 + 13 + 4, this.field_186 + 10 + 2, 1);
      class_50.method_488(this.field_190, this.field_185 + 5, this.field_186 + 16 + 2 + 10, 0);
      class_41.field_534.setColor(class_69.field_1003);
      class_50.method_485("OK", this.field_185 + this.field_187 / 2 - class_50.method_490("OK") / 2, this.field_191, 0);
      class_41.field_534.drawRect(this.field_185 + this.field_187 / 2 - 2 - class_50.method_490("OK") / 2, this.field_191, class_50.method_490("OK") + 4, 10);
   }
}
