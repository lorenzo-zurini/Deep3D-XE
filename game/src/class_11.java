// $VF: renamed from: bv
public final class class_11 {
   // $VF: renamed from: a int
   private static int field_173 = 30;
   // $VF: renamed from: a boolean
   private boolean field_174;
   // $VF: renamed from: a z
   private class_53 field_175;
   // $VF: renamed from: a n
   private class_79 field_176 = new class_79(
      new String[]{class_41.field_533.method_297(64), class_41.field_533.method_297(63)}, class_41.field_533.method_297(64)
   );
   // $VF: renamed from: a dc
   private class_18 field_177;
   // $VF: renamed from: b dc
   private class_18 field_178;

   public class_11() {
      this.field_174 = false;
      this.field_175 = new class_53(20, class_41.field_538 / 3, class_41.field_537 - 40);
      this.field_177 = new class_18(10, field_173, class_41.field_537 - 20, class_41.field_538 - field_173 - class_69.method_653() - 18, "");
      this.field_177.field_275 = 1;
      this.field_178 = new class_18(10, field_173, class_41.field_537 - 20, class_41.field_538 - field_173 - class_69.method_653() - 18, "");
      this.field_178.field_274 = true;
      this.method_208();
   }

   // $VF: renamed from: a () void
   public final void method_208() {
      this.field_177.method_274(class_3.method_145(), class_3.method_147(), class_3.method_143(), true);
      this.field_178.method_274(class_3.method_145(), class_3.method_147(), class_3.method_143(), true);
      String var1 = class_41.field_533.method_297(141);
      var1 = var1 + "\n" + class_41.field_533.method_297(71);
      var1 = var1 + "\n" + class_41.field_533.method_297(82);
      var1 = var1 + "\n" + class_41.field_533.method_297(79);
      var1 = var1 + "\n" + class_41.field_533.method_297(319);
      var1 = var1 + "\n" + class_41.field_533.method_297(320);
      var1 = var1 + "\n" + class_41.field_533.method_297(37);
      var1 = var1 + "\n" + class_41.field_533.method_297(322);
      var1 = var1 + "\n" + class_41.field_533.method_297(321);
      var1 = var1 + "\n" + class_41.field_533.method_297(72);
      var1 = var1 + "\n" + class_41.field_533.method_297(313);
      var1 = var1 + "\n" + class_41.field_533.method_297(311);
      var1 = var1 + "\n" + class_41.field_533.method_297(312);
      var1 = var1 + "\n" + class_41.field_533.method_297(316);
      var1 = var1 + "\n" + class_41.field_533.method_297(317);
      var1 = var1 + "\n" + class_41.field_533.method_297(314);
      var1 = var1 + "\n" + class_41.field_533.method_297(318);
      var1 = var1 + "\n" + class_41.field_533.method_297(315);
      this.field_177.method_272(var1);
      String var2 = "" + class_3.method_140();
      var2 = var2 + "\n" + class_122.method_932(class_3.method_142());
      var2 = var2 + "\n" + class_3.method_112() + " $";
      var2 = var2 + "\n" + class_41.field_533.method_297(class_22.field_322[class_3.method_108().field_422][0]);
      var2 = var2 + "\n" + class_3.method_108().field_441;
      var2 = var2 + "\n" + class_3.method_108().method_364();
      var2 = var2 + "\n" + class_3.method_139();
      var2 = var2 + "\n" + class_3.method_90() + "m";
      var2 = var2 + "\n" + class_3.method_89() + "m";
      var2 = var2 + "\n" + class_3.method_132();
      var2 = var2 + "\n" + class_3.method_138();
      var2 = var2 + "\n" + class_3.method_100();
      var2 = var2 + "\n" + class_3.method_102();
      var2 = var2 + "\n" + class_3.method_86() + "t";
      var2 = var2 + "\n" + class_3.method_84();
      var2 = var2 + "\n" + class_3.method_107();
      var2 = var2 + "\n" + class_3.method_81();
      var2 = var2 + "\n" + class_3.method_121();
      this.field_178.method_272(var2);
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_209(int var1) {
      if ((var1 == 256 || var1 == 16384) && this.field_176.field_1057 == 1 && !this.field_174) {
         class_2 var2 = (class_2)this.field_176.method_694();
         if (class_58.method_566()[var2.field_28] != 0) {
            this.field_175
               .method_513(
                  class_3.method_149(
                     class_41.field_533.method_297(class_22.field_314[var2.field_28][1]), class_58.field_805[var2.field_28][var2.field_27 - 1] + ""
                  )
               );
            this.field_174 = true;
         }

         return true;
      } else if (this.field_174) {
         if (this.field_176.field_1057 == 1 && var1 == 256) {
            this.field_174 = false;
         }

         return true;
      } else {
         if (var1 == 4) {
            this.field_176.method_699();
         }

         if (var1 == 32) {
            this.field_176.method_700();
         }

         if (var1 == 2) {
            this.field_176.method_697();
         }

         if (var1 == 64) {
            this.field_176.method_698();
         }

         return var1 != 8192;
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_210() {
      return this.field_176.field_1057 == 1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_211(int var1, int var2) {
      if ((var1 & 2) != 0 && this.field_176.field_1057 == 0) {
         this.field_177.method_277(var2 / 2);
         this.field_178.method_277(var2 / 2);
      }

      if ((var1 & 64) != 0 && this.field_176.field_1057 == 0) {
         this.field_177.method_276(var2 / 2);
         this.field_178.method_276(var2 / 2);
      }

      class_69.method_663();
      this.field_176.method_711();
      if (this.field_176.field_1057 == 0) {
         this.method_212();
         class_69.method_669("", class_41.field_533.method_297(65));
      } else {
         class_69.method_669(((class_2)this.field_176.method_694()).field_27 > 0 ? class_41.field_533.method_297(226) : "", class_41.field_533.method_297(65));
      }

      if (this.field_174) {
         this.field_175.method_518();
      }
   }

   // $VF: renamed from: b () void
   public final void method_212() {
      this.field_177.method_278();
      this.field_178.method_278();
   }
}
