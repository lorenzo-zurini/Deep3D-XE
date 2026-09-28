// $VF: renamed from: bt
public final class class_52 {
   // $VF: renamed from: b int
   private int field_583;
   // $VF: renamed from: c int
   private int field_584;
   // $VF: renamed from: d int
   private int field_585;
   // $VF: renamed from: e int
   private int field_586;
   // $VF: renamed from: f int
   private int field_587;
   // $VF: renamed from: a ac
   private class_120 field_588;
   // $VF: renamed from: a int
   public int field_589;

   public class_52(int var1, int var2, int var3) {
      this.field_583 = var1;
      this.field_584 = var2;
      this.field_585 = var3;
   }

   public class_52() {
      this(class_84.field_1120 / 2 - 40, class_84.field_1121 / 2 - 15, 80);
   }

   // $VF: renamed from: a (ac) void
   public final void method_431(class_120 var1) {
      this.field_588 = var1;
      this.field_587 = this.field_584 + 1 * class_58.method_527() + 10 + 2;
      this.field_586 = 36;
      this.field_589 = var1.field_1490;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_432() {
      return true;
   }

   // $VF: renamed from: a () void
   public final void method_433() {
      this.field_589--;
      if (this.field_589 < 0) {
         this.field_589 = class_16.method_97(0, this.field_588.field_1490);
      }
   }

   // $VF: renamed from: b () void
   public final void method_434() {
      this.field_589++;
      if (this.field_589 > this.field_588.field_1490) {
         this.field_589 = 0;
      }
   }

   // $VF: renamed from: c () void
   public final void method_435() {
      // Deep3D-PC: "<" / ">" and OK clickable, the wheel changes the amount
      org.deep3d.GameUi.controls(org.deep3d.GameUi.DIALOG, org.deep3d.GameUi.FIRE, org.deep3d.GameUi.NONE, org.deep3d.GameUi.NONE);
      org.deep3d.GameUi.zone(this.field_583 + this.field_585 / 2 - 20, this.field_584 + 8, 14, 14, org.deep3d.GameUi.LEFT);
      org.deep3d.GameUi.zone(this.field_583 + this.field_585 / 2 + 6, this.field_584 + 8, 14, 14, org.deep3d.GameUi.RIGHT);
      org.deep3d.GameUi.scrollArea(this.field_583, this.field_584, this.field_585, this.field_586, true);
      org.deep3d.GameUi.button(this.field_583 + this.field_585 / 2 - 14, this.field_587 - 2, 28, 14, true);
      class_67.method_583();
      class_84.field_1117.setColor(class_67.field_845);
      class_84.field_1117.fillRect(this.field_583, this.field_584, this.field_585, this.field_586);
      class_67.method_591(class_84.field_1116.method_4(263), this.field_583, this.field_584, this.field_585, this.field_586);
      class_58.method_516(this.field_589 + " X", this.field_583 + this.field_585 / 2, this.field_584 + 10, 1, 24);
      class_58.method_516("<", this.field_583 + this.field_585 / 2 - 12, this.field_584 + 10, 1, 18);
      class_58.method_516(">", this.field_583 + this.field_585 / 2 + 12, this.field_584 + 10, 1, 17);
      class_58.method_518(
         class_84.field_1116.method_4(265), this.field_583 + this.field_585 / 2 - class_58.method_523(class_84.field_1116.method_4(265)) / 2, this.field_587, 0
      );
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117
         .drawRect(
            this.field_583 + this.field_585 / 2 - 2 - class_58.method_523(class_84.field_1116.method_4(265)) / 2,
            this.field_587,
            class_58.method_523(class_84.field_1116.method_4(265)) + 4,
            10
         );
   }
}
