// $VF: renamed from: bv
public final class class_50 {
   // $VF: renamed from: a int
   private static int field_546 = 30;
   // $VF: renamed from: a boolean
   private boolean field_547;
   // $VF: renamed from: a ab
   private class_121 field_548;
   // $VF: renamed from: a m
   private class_77 field_549 = new class_77(new String[]{class_84.field_1116.method_4(64), class_84.field_1116.method_4(63)}, class_84.field_1116.method_4(64));
   // $VF: renamed from: a dd
   private class_23 field_550;
   // $VF: renamed from: b dd
   private class_23 field_551;

   public class_50() {
      this.field_547 = false;
      this.field_548 = new class_121(20, class_84.field_1121 / 3, class_84.field_1120 - 40);
      this.field_550 = new class_23(10, field_546, class_84.field_1120 - 20, class_84.field_1121 - field_546 - class_67.method_577() - 18, "");
      this.field_550.field_249 = 1;
      this.field_551 = new class_23(10, field_546, class_84.field_1120 - 20, class_84.field_1121 - field_546 - class_67.method_577() - 18, "");
      this.field_551.field_248 = true;
      this.method_410();
   }

   // $VF: renamed from: a () void
   public final void method_410() {
      this.field_550.method_227(class_21.method_215(), class_21.method_217(), class_21.method_213(), true);
      this.field_551.method_227(class_21.method_215(), class_21.method_217(), class_21.method_213(), true);
      String var1 = class_84.field_1116.method_4(141);
      var1 = var1 + "\n" + class_84.field_1116.method_4(71);
      var1 = var1 + "\n" + class_84.field_1116.method_4(82);
      var1 = var1 + "\n" + class_84.field_1116.method_4(79);
      var1 = var1 + "\n" + class_84.field_1116.method_4(319);
      var1 = var1 + "\n" + class_84.field_1116.method_4(320);
      var1 = var1 + "\n" + class_84.field_1116.method_4(37);
      var1 = var1 + "\n" + class_84.field_1116.method_4(322);
      var1 = var1 + "\n" + class_84.field_1116.method_4(321);
      var1 = var1 + "\n" + class_84.field_1116.method_4(72);
      var1 = var1 + "\n" + class_84.field_1116.method_4(313);
      var1 = var1 + "\n" + class_84.field_1116.method_4(311);
      var1 = var1 + "\n" + class_84.field_1116.method_4(312);
      var1 = var1 + "\n" + class_84.field_1116.method_4(316);
      var1 = var1 + "\n" + class_84.field_1116.method_4(317);
      var1 = var1 + "\n" + class_84.field_1116.method_4(314);
      var1 = var1 + "\n" + class_84.field_1116.method_4(318);
      var1 = var1 + "\n" + class_84.field_1116.method_4(315);
      this.field_550.method_225(var1);
      String var2 = "" + class_21.method_210();
      var2 = var2 + "\n" + class_48.method_398(class_21.method_212());
      var2 = var2 + "\n" + class_21.method_182() + " $";
      var2 = var2 + "\n" + class_84.field_1116.method_4(class_1.field_8[class_21.method_178().field_863][0]);
      var2 = var2 + "\n" + class_21.method_178().field_882;
      var2 = var2 + "\n" + class_21.method_178().method_604();
      var2 = var2 + "\n" + class_21.method_209();
      var2 = var2 + "\n" + class_21.method_160() + "m";
      var2 = var2 + "\n" + class_21.method_159() + "m";
      var2 = var2 + "\n" + class_21.method_202();
      var2 = var2 + "\n" + class_21.method_208();
      var2 = var2 + "\n" + class_21.method_170();
      var2 = var2 + "\n" + class_21.method_172();
      var2 = var2 + "\n" + class_21.method_156() + "t";
      var2 = var2 + "\n" + class_21.method_154();
      var2 = var2 + "\n" + class_21.method_177();
      var2 = var2 + "\n" + class_21.method_151();
      var2 = var2 + "\n" + class_21.method_191();
      this.field_551.method_225(var2);
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_411(int var1) {
      if ((var1 == 256 || var1 == 16384) && this.field_549.field_1038 == 1 && !this.field_547) {
         class_59 var2 = (class_59)this.field_549.method_701();
         if (class_14.method_71()[var2.field_716] != 0) {
            this.field_548
               .method_939(
                  class_21.method_219(
                     class_84.field_1116.method_4(class_1.field_0[var2.field_716][1]), class_14.field_135[var2.field_716][var2.field_715 - 1] + ""
                  )
               );
            this.field_547 = true;
         }

         return true;
      } else if (this.field_547) {
         if (this.field_549.field_1038 == 1 && var1 == 256) {
            this.field_547 = false;
         }

         return true;
      } else {
         if (var1 == 4) {
            this.field_549.method_706();
         }

         if (var1 == 32) {
            this.field_549.method_707();
         }

         if (var1 == 2) {
            this.field_549.method_704();
         }

         if (var1 == 64) {
            this.field_549.method_705();
         }

         return var1 != 8192;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_412() {
      return this.field_549.field_1038 == 1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_413(int var1, int var2) {
      if ((var1 & 2) != 0 && this.field_549.field_1038 == 0) {
         this.field_550.method_230(var2 / 2);
         this.field_551.method_230(var2 / 2);
      }

      if ((var1 & 64) != 0 && this.field_549.field_1038 == 0) {
         this.field_550.method_229(var2 / 2);
         this.field_551.method_229(var2 / 2);
      }

      class_67.method_587();
      this.field_549.method_718();
      if (this.field_549.field_1038 == 0) {
         this.method_414();
         class_67.method_593("", class_84.field_1116.method_4(65));
      } else {
         class_67.method_593(((class_59)this.field_549.method_701()).field_715 > 0 ? class_84.field_1116.method_4(226) : "", class_84.field_1116.method_4(65));
      }

      if (this.field_547) {
         this.field_548.method_944();
      }
   }

   // $VF: renamed from: b () void
   public final void method_414() {
      this.field_550.method_231();
      this.field_551.method_231();
   }
}
