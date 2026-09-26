import javax.microedition.lcdui.Image;

// $VF: renamed from: aa
public final class class_122 {
   // $VF: renamed from: a int
   private int field_1501;
   // $VF: renamed from: b int
   private int field_1502;
   // $VF: renamed from: c int
   private int field_1503;
   // $VF: renamed from: d int
   private int field_1504;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_1505;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_1506;
   // $VF: renamed from: e int
   private int field_1507;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_1508;

   public class_122(int var1, int var2, int var3) {
      this.field_1501 = var1;
      this.field_1502 = var2;
      this.field_1503 = var3;
      this.field_1504 = class_84.field_1121 / 2;
   }

   public class_122() {
      this(10, class_84.field_1121 / 2, class_84.field_1120 - 20);
   }

   // $VF: renamed from: a (int, int) void
   public final void method_945(int var1, int var2) {
      this.field_1508 = class_28.method_282("/data/interface/medal_" + var2 + ".png");
      this.field_1505 = class_58.method_532(class_84.field_1116.method_4(class_1.field_0[var1][0]), this.field_1503 - 10 - 13 - 4);
      this.field_1506 = class_58.method_532(
         class_21.method_219(class_84.field_1116.method_4(class_1.field_0[var1][1]), class_14.field_135[var1][var2 - 1] + ""), this.field_1503 - 10
      );
      this.field_1502 = (class_84.field_1121 >> 1) - (class_58.method_530(this.field_1506) + 16 + 4 + 2 * class_58.method_527() >> 1);
      this.field_1507 = this.field_1502 + this.field_1506.length * class_58.method_527() + 16 + 4 + 10 + 2;
      this.field_1504 = this.field_1507 + class_58.method_527() + 5 - this.field_1502;
   }

   // $VF: renamed from: a () void
   public final void method_946() {
      class_67.method_583();
      class_67.method_592(class_84.field_1116.method_4(163), this.field_1501, this.field_1502, this.field_1503, this.field_1504, true);
      class_84.field_1117.drawImage(this.field_1508, this.field_1501 + 5, this.field_1502 + 10 + 2, 0);
      class_58.method_521(this.field_1505, this.field_1501 + 5 + 13 + 4, this.field_1502 + 10 + 2, 1);
      class_58.method_521(this.field_1506, this.field_1501 + 5, this.field_1502 + 16 + 2 + 10, 0);
      class_84.field_1117.setColor(class_67.field_844);
      class_58.method_518("OK", this.field_1501 + this.field_1503 / 2 - class_58.method_523("OK") / 2, this.field_1507, 0);
      class_84.field_1117
         .drawRect(this.field_1501 + this.field_1503 / 2 - 2 - class_58.method_523("OK") / 2, this.field_1507, class_58.method_523("OK") + 4, 10);
   }
}
