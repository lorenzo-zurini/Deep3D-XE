// $VF: renamed from: ab
public final class class_121 {
   // $VF: renamed from: a int
   private int field_1493;
   // $VF: renamed from: b int
   private int field_1494;
   // $VF: renamed from: c int
   private int field_1495;
   // $VF: renamed from: d int
   private int field_1496;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_1497;
   // $VF: renamed from: e int
   private int field_1498;
   // $VF: renamed from: a boolean
   private boolean field_1499;
   // $VF: renamed from: b boolean
   private boolean field_1500;

   public class_121(int var1, int var2, int var3) {
      this.field_1493 = var1;
      this.field_1494 = var2;
      this.field_1495 = var3;
      this.field_1496 = class_84.field_1121 / 2;
   }

   public class_121() {
      this(class_84.field_1120 < 176 ? 10 : 20, class_84.field_1121 / 2, class_84.field_1120 - (class_84.field_1120 < 176 ? 20 : 40));
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_939(String var1) {
      this.method_940(var1, false);
   }

   // $VF: renamed from: a (java.lang.String, boolean) void
   public final void method_940(String var1, boolean var2) {
      this.field_1499 = true;
      this.field_1500 = var2;
      this.field_1497 = class_58.method_532(var1, this.field_1495 - 10);
      this.field_1494 = (class_84.field_1121 >> 1) - (class_58.method_530(this.field_1497) + 2 * class_58.method_527() >> 1);
      this.field_1498 = this.field_1494 + this.field_1497.length * class_58.method_527() + 10 + 2;
      this.field_1496 = this.field_1498 + class_58.method_527() + 5 - this.field_1494;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_941() {
      return this.field_1500 ? this.field_1499 : false;
   }

   // $VF: renamed from: a () void
   public final void method_942() {
      if (!this.field_1499 && this.field_1500) {
         this.field_1499 = true;
      }
   }

   // $VF: renamed from: b () void
   public final void method_943() {
      if (this.field_1499 && this.field_1500) {
         this.field_1499 = false;
      }
   }

   // $VF: renamed from: c () void
   public final void method_944() {
      class_67.method_583();
      class_67.method_592("", this.field_1493, this.field_1494, this.field_1495, this.field_1496, true);
      class_58.method_521(this.field_1497, this.field_1493 + 5, this.field_1494 + 10, 0);
      class_84.field_1117.setColor(class_67.field_844);
      if (this.field_1500) {
         class_58.method_516(class_84.field_1116.method_4(45), this.field_1493 + this.field_1495 / 3, this.field_1498, this.field_1499 ? 0 : 1, 24);
         class_58.method_516(
            class_84.field_1116.method_4(46), this.field_1493 + this.field_1495 - this.field_1495 / 3, this.field_1498, this.field_1499 ? 1 : 0, 24
         );
         if (this.field_1499) {
            class_84.field_1117
               .drawRect(
                  this.field_1493 + this.field_1495 / 3 - 2 - class_58.method_523(class_84.field_1116.method_4(45)) / 2,
                  this.field_1498,
                  class_58.method_523(class_84.field_1116.method_4(45)) + 4,
                  10
               );
         } else {
            class_84.field_1117
               .drawRect(
                  this.field_1493 + this.field_1495 - this.field_1495 / 3 - 2 - class_58.method_523(class_84.field_1116.method_4(46)) / 2,
                  this.field_1498,
                  class_58.method_523(class_84.field_1116.method_4(46)) + 4,
                  10
               );
         }
      } else {
         class_58.method_518("OK", this.field_1493 + this.field_1495 / 2 - class_58.method_523("OK") / 2, this.field_1498, 0);
         class_84.field_1117
            .drawRect(this.field_1493 + this.field_1495 / 2 - 2 - class_58.method_523("OK") / 2, this.field_1498, class_58.method_523("OK") + 4, 10);
      }
   }
}
