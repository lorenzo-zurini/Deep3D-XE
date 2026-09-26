// $VF: renamed from: bt
public final class class_28 {
   // $VF: renamed from: b int
   private int field_391;
   // $VF: renamed from: c int
   private int field_392;
   // $VF: renamed from: d int
   private int field_393;
   // $VF: renamed from: e int
   private int field_394;
   // $VF: renamed from: f int
   private int field_395;
   // $VF: renamed from: a aa
   private class_46 field_396;
   // $VF: renamed from: a int
   public int field_397;

   public class_28(int var1, int var2, int var3) {
      this.field_391 = var1;
      this.field_392 = var2;
      this.field_393 = var3;
   }

   public class_28() {
      this(class_41.field_537 / 2 - 40, class_41.field_538 / 2 - 15, 80);
   }

   // $VF: renamed from: a (aa) void
   public final void method_337(class_46 var1) {
      this.field_396 = var1;
      this.field_395 = this.field_392 + 1 * class_50.method_494() + 10 + 2;
      this.field_394 = 36;
      this.field_397 = var1.field_636;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_338() {
      return true;
   }

   // $VF: renamed from: a () void
   public final void method_339() {
      this.field_397--;
      if (this.field_397 < 0) {
         this.field_397 = class_124.method_942(0, this.field_396.field_636);
      }
   }

   // $VF: renamed from: b () void
   public final void method_340() {
      this.field_397++;
      if (this.field_397 > this.field_396.field_636) {
         this.field_397 = 0;
      }
   }

   // $VF: renamed from: c () void
   public final void method_341() {
      class_69.method_659();
      class_41.field_534.setColor(class_69.field_1004);
      class_41.field_534.fillRect(this.field_391, this.field_392, this.field_393, this.field_394);
      class_69.method_667(class_41.field_533.method_297(263), this.field_391, this.field_392, this.field_393, this.field_394);
      class_50.method_483(this.field_397 + " X", this.field_391 + this.field_393 / 2, this.field_392 + 10, 1, 24);
      class_50.method_483("<", this.field_391 + this.field_393 / 2 - 12, this.field_392 + 10, 1, 18);
      class_50.method_483(">", this.field_391 + this.field_393 / 2 + 12, this.field_392 + 10, 1, 17);
      class_50.method_485(
         class_41.field_533.method_297(265),
         this.field_391 + this.field_393 / 2 - class_50.method_490(class_41.field_533.method_297(265)) / 2,
         this.field_395,
         0
      );
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534
         .drawRect(
            this.field_391 + this.field_393 / 2 - 2 - class_50.method_490(class_41.field_533.method_297(265)) / 2,
            this.field_395,
            class_50.method_490(class_41.field_533.method_297(265)) + 4,
            10
         );
   }
}
