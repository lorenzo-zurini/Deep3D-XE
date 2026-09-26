// $VF: renamed from: bz
public final class class_47 {
   // $VF: renamed from: a int
   public int field_527;
   // $VF: renamed from: b int
   private int field_528;
   // $VF: renamed from: c int
   private int field_529;
   // $VF: renamed from: d int
   private int field_530;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_531 = new String[3];
   // $VF: renamed from: e int
   private int field_532;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_533;
   // $VF: renamed from: a boolean
   private boolean field_534;
   // $VF: renamed from: b boolean
   private boolean field_535;

   public class_47() {
      this.field_530 = 20 + class_58.method_523(class_84.field_1116.method_4(249));
      this.field_531[2] = class_84.field_1116.method_4(65);
      this.field_533 = class_58.method_532(class_84.field_1116.method_4(248), this.field_530 - 10);
   }

   // $VF: renamed from: a (boolean, boolean) void
   public final void method_393(boolean var1, boolean var2) {
      this.field_527 = 0;
      this.field_534 = var2;
      this.field_535 = var1;
      this.field_531[0] = class_84.field_1116.method_4(var1 ? 249 : 250);
      this.field_531[1] = class_84.field_1116.method_4(var1 ? 251 : (var2 ? 241 : 253));
      int var3 = var2 && var1 ? 4 : 5;
      this.field_529 = (class_84.field_1121 >> 1) - (class_58.method_530(this.field_533) + var3 * class_58.method_527() >> 1);
      this.field_528 = (class_84.field_1120 - this.field_530) / 2;
      this.field_532 = class_58.method_530(this.field_533) + class_58.method_527() * (var3 + 1);
   }

   // $VF: renamed from: a () void
   public final void method_394() {
      if (this.field_527 > 0) {
         this.field_527--;
      } else {
         this.field_527 = 2;
      }

      if (this.field_534 && this.field_535 && this.field_527 == 1) {
         this.method_394();
      }
   }

   // $VF: renamed from: b () void
   public final void method_395() {
      if (this.field_527 < 2) {
         this.field_527++;
      } else {
         this.field_527 = 0;
      }

      if (this.field_534 && this.field_535 && this.field_527 == 1) {
         this.method_395();
      }
   }

   // $VF: renamed from: c () void
   public final void method_396() {
      class_67.method_583();
      class_67.method_592("", this.field_528, this.field_529, this.field_530, this.field_532, true);
      class_58.method_521(this.field_533, this.field_528 + 5, this.field_529 + 17, 0);

      for (int var1 = 0; var1 < this.field_531.length; var1++) {
         if (!this.field_534 || !this.field_535 || var1 != 1) {
            class_67.method_584(
               this.field_531[var1],
               this.field_528,
               this.field_529 + 12 + class_58.method_530(this.field_533) + 10 + (this.field_534 && this.field_535 && var1 == 2 ? var1 - 1 : var1) * 10,
               this.field_530,
               this.field_527 == var1
            );
         }
      }
   }
}
