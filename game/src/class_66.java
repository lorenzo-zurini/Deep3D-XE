// $VF: renamed from: bz
public final class class_66 {
   // $VF: renamed from: a int
   public int field_888;
   // $VF: renamed from: b int
   private int field_889;
   // $VF: renamed from: c int
   private int field_890;
   // $VF: renamed from: d int
   private int field_891;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_892 = new String[3];
   // $VF: renamed from: e int
   private int field_893;
   // $VF: renamed from: b java.lang.String[]
   private String[] field_894;
   // $VF: renamed from: a boolean
   private boolean field_895;
   // $VF: renamed from: b boolean
   private boolean field_896;

   public class_66() {
      this.field_891 = 20 + class_50.method_490(class_41.field_533.method_297(249));
      this.field_892[2] = class_41.field_533.method_297(65);
      this.field_894 = class_50.method_499(class_41.field_533.method_297(248), this.field_891 - 10);
   }

   // $VF: renamed from: a (boolean, boolean) void
   public final void method_618(boolean var1, boolean var2) {
      this.field_888 = 0;
      this.field_895 = var2;
      this.field_896 = var1;
      this.field_892[0] = class_41.field_533.method_297(var1 ? 249 : 250);
      this.field_892[1] = class_41.field_533.method_297(var1 ? 251 : (var2 ? 241 : 253));
      int var3 = var2 && var1 ? 4 : 5;
      this.field_890 = (class_41.field_538 >> 1) - (class_50.method_497(this.field_894) + var3 * class_50.method_494() >> 1);
      this.field_889 = (class_41.field_537 - this.field_891) / 2;
      this.field_893 = class_50.method_497(this.field_894) + class_50.method_494() * (var3 + 1);
   }

   // $VF: renamed from: a () void
   public final void method_619() {
      if (this.field_888 > 0) {
         this.field_888--;
      } else {
         this.field_888 = 2;
      }

      if (this.field_895 && this.field_896 && this.field_888 == 1) {
         this.method_619();
      }
   }

   // $VF: renamed from: b () void
   public final void method_620() {
      if (this.field_888 < 2) {
         this.field_888++;
      } else {
         this.field_888 = 0;
      }

      if (this.field_895 && this.field_896 && this.field_888 == 1) {
         this.method_620();
      }
   }

   // $VF: renamed from: c () void
   public final void method_621() {
      class_69.method_659();
      class_69.method_668("", this.field_889, this.field_890, this.field_891, this.field_893, true);
      class_50.method_488(this.field_894, this.field_889 + 5, this.field_890 + 17, 0);

      for (int var1 = 0; var1 < this.field_892.length; var1++) {
         if (!this.field_895 || !this.field_896 || var1 != 1) {
            class_69.method_660(
               this.field_892[var1],
               this.field_889,
               this.field_890 + 12 + class_50.method_497(this.field_894) + 10 + (this.field_895 && this.field_896 && var1 == 2 ? var1 - 1 : var1) * 10,
               this.field_891,
               this.field_888 == var1
            );
         }
      }
   }
}
