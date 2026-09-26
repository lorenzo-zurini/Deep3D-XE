// $VF: renamed from: z
public final class class_53 {
   // $VF: renamed from: a int
   private int field_728;
   // $VF: renamed from: b int
   private int field_729;
   // $VF: renamed from: c int
   private int field_730;
   // $VF: renamed from: d int
   private int field_731;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_732;
   // $VF: renamed from: e int
   private int field_733;
   // $VF: renamed from: a boolean
   private boolean field_734;
   // $VF: renamed from: b boolean
   private boolean field_735;

   public class_53(int var1, int var2, int var3) {
      this.field_728 = var1;
      this.field_729 = var2;
      this.field_730 = var3;
      this.field_731 = class_41.field_538 / 2;
   }

   public class_53() {
      this(class_41.field_537 < 176 ? 10 : 20, class_41.field_538 / 2, class_41.field_537 - (class_41.field_537 < 176 ? 20 : 40));
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_513(String var1) {
      this.method_514(var1, false);
   }

   // $VF: renamed from: a (java.lang.String, boolean) void
   public final void method_514(String var1, boolean var2) {
      this.field_734 = true;
      this.field_735 = var2;
      this.field_732 = class_50.method_499(var1, this.field_730 - 10);
      this.field_729 = (class_41.field_538 >> 1) - (class_50.method_497(this.field_732) + 2 * class_50.method_494() >> 1);
      this.field_733 = this.field_729 + this.field_732.length * class_50.method_494() + 10 + 2;
      this.field_731 = this.field_733 + class_50.method_494() + 5 - this.field_729;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_515() {
      return this.field_735 ? this.field_734 : false;
   }

   // $VF: renamed from: a () void
   public final void method_516() {
      if (!this.field_734 && this.field_735) {
         this.field_734 = true;
      }
   }

   // $VF: renamed from: b () void
   public final void method_517() {
      if (this.field_734 && this.field_735) {
         this.field_734 = false;
      }
   }

   // $VF: renamed from: c () void
   public final void method_518() {
      class_69.method_659();
      class_69.method_668("", this.field_728, this.field_729, this.field_730, this.field_731, true);
      class_50.method_488(this.field_732, this.field_728 + 5, this.field_729 + 10, 0);
      class_41.field_534.setColor(class_69.field_1003);
      if (this.field_735) {
         class_50.method_483(class_41.field_533.method_297(45), this.field_728 + this.field_730 / 3, this.field_733, this.field_734 ? 0 : 1, 24);
         class_50.method_483(
            class_41.field_533.method_297(46), this.field_728 + this.field_730 - this.field_730 / 3, this.field_733, this.field_734 ? 1 : 0, 24
         );
         if (this.field_734) {
            class_41.field_534
               .drawRect(
                  this.field_728 + this.field_730 / 3 - 2 - class_50.method_490(class_41.field_533.method_297(45)) / 2,
                  this.field_733,
                  class_50.method_490(class_41.field_533.method_297(45)) + 4,
                  10
               );
         } else {
            class_41.field_534
               .drawRect(
                  this.field_728 + this.field_730 - this.field_730 / 3 - 2 - class_50.method_490(class_41.field_533.method_297(46)) / 2,
                  this.field_733,
                  class_50.method_490(class_41.field_533.method_297(46)) + 4,
                  10
               );
         }
      } else {
         class_50.method_485("OK", this.field_728 + this.field_730 / 2 - class_50.method_490("OK") / 2, this.field_733, 0);
         class_41.field_534
            .drawRect(this.field_728 + this.field_730 / 2 - 2 - class_50.method_490("OK") / 2, this.field_733, class_50.method_490("OK") + 4, 10);
      }
   }
}
