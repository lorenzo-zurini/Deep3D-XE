// $VF: renamed from: w
public final class class_33 {
   // $VF: renamed from: a int
   public int field_452;
   // $VF: renamed from: b int
   private int field_453;
   // $VF: renamed from: c int
   private int field_454;
   // $VF: renamed from: d int
   private int field_455;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_456;
   // $VF: renamed from: e int
   private int field_457;

   public class_33(class_57 var1) {
      this.field_457 = var1.field_774.field_215 != null && !var1.field_774.field_215.method_220().field_1164
         ? 3
         : (class_3.method_76() && class_3.method_110().field_828 == 0 ? 1 : 2);
      this.field_456 = new String[this.field_457];
      this.field_456[0] = class_41.field_533.method_297(327);
      if (this.field_457 > 1) {
         this.field_456[1] = class_3.method_110().field_827;
      }

      if (this.field_457 == 3) {
         this.field_456[2] = class_41.field_533.method_297(326);
      }

      this.field_455 = 0;

      for (int var2 = 0; var2 < this.field_456.length; var2++) {
         int var3;
         if ((var3 = class_50.method_490(this.field_456[var2])) + 15 > this.field_455) {
            this.field_455 = var3 + 15;
         }
      }

      this.field_453 = (class_41.field_537 - this.field_455) / 2;
      this.field_454 = (class_41.field_538 - (this.field_457 * 10 + 12)) / 2;
   }

   // $VF: renamed from: a () void
   public final void method_391() {
      if (this.field_452 > 0) {
         this.field_452--;
      } else {
         this.field_452 = this.field_457 - 1;
      }
   }

   // $VF: renamed from: b () void
   public final void method_392() {
      if (this.field_452 < this.field_457 - 1) {
         this.field_452++;
      } else {
         this.field_452 = 0;
      }
   }

   // $VF: renamed from: c () void
   public final void method_393() {
      class_69.method_667(class_41.field_533.method_297(325), this.field_453, this.field_454, this.field_455, 12 + (this.field_457 + 1) * 10 - 5);

      for (int var1 = 0; var1 < this.field_456.length; var1++) {
         class_69.method_660(this.field_456[var1], this.field_453, this.field_454 + 12 + var1 * 10, this.field_455, this.field_452 == var1);
      }
   }
}
