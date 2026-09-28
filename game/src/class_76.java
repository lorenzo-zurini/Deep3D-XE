import javax.microedition.lcdui.Image;

// $VF: renamed from: ay
public class class_76 extends class_74 {
   // $VF: renamed from: a int
   public int field_1052 = 31;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   public Image[] field_1053;
   // $VF: renamed from: b javax.microedition.lcdui.Image[]
   public Image[] field_1054;
   // $VF: renamed from: a java.lang.String
   public String field_1055;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_1056;

   public class_76(String[] var1, String var2) {
      this(0, 0, class_84.field_1120, class_84.field_1121, var1, var2);
   }

   public class_76(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      super(var1, var2, var3, var4, var5, var6);

      try {
         this.field_1053 = new Image[class_90.method_781().length];
         this.field_1054 = new Image[class_90.method_783().length * 2];
      } catch (Exception var8) {
         var8.printStackTrace();
      }

      if (this.field_1056 == null) {
         this.field_1056 = class_28.method_282("/data/interface/logo_" + (class_14.method_70() ? 2 : (class_21.method_180().method_752() ? 0 : 1)) + "_t.png");
      }
   }

   // $VF: renamed from: c () void
   public void method_714() {
      this.field_1053 = null;
      this.field_1054 = null;
   }

   // $VF: renamed from: a (int, bd) void
   public final void method_715(int var1, class_68 var2) {
      if (var1 > super.field_1032.length - 1) {
         System.out.println("ERROR: Tab " + var1 + " not available!");
      } else {
         Object var3 = null;
         class_19[] var4 = var2.field_885;
         var3 = new class_59[var2.field_885.length + 3];
         int var5 = 0;
         var5++;
         ((Object[])var3)[0] = new class_59(class_84.field_1116.method_4(79));
         var5++;
         ((Object[])var3)[1] = new class_59(var2);
         boolean var6 = var2.field_884;
         int var7 = ((class_59)((Object[])var3)[1]).method_545() + (var6 ? class_90.method_783().length : 0);
         if (this.field_1054[var7] == null) {
            this.field_1054[var7] = class_28.method_282(
               "/data/interface/equipment/u" + ((class_59)((Object[])var3)[1]).method_545() + (var6 ? "b" : "a") + ".png"
            );
         }

         var5++;
         ((Object[])var3)[2] = new class_59(class_84.field_1116.method_4(69));

         for (int var8 = 0; var8 < var4.length; var8++) {
            if (var4[var8] != null) {
               ((Object[])var3)[var5++] = new class_59(var4[var8]);
               if (this.field_1053[((class_59)((Object[])var3)[var5 - 1]).method_545()] == null) {
                  this.field_1053[((class_59)((Object[])var3)[var5 - 1]).method_545()] = class_28.method_282(
                     "/data/interface/equipment/slot_" + ((class_59)((Object[])var3)[var5 - 1]).method_545() + ".png"
                  );
               }
            } else {
               ((Object[])var3)[var5++] = new class_59(var8);
            }
         }

         boolean var15;
         do {
            var15 = true;

            for (int var9 = 4; var9 < ((Object[])var3).length; var9++) {
               if (((class_59)((Object[])var3)[var9 - 1]).method_545() > ((class_59)((Object[])var3)[var9]).method_545()) {
                  class_59 var10 = (class_59)((Object[])var3)[var9 - 1];
                  ((Object[])var3)[var9 - 1] = ((Object[])var3)[var9];
                  ((Object[])var3)[var9] = var10;
                  var15 = false;
               }
            }
         } while (!var15);

         super.field_1032[var1] = (Object[])var3;
         if (super.field_1032[var1] == null) {
            super.field_1033[var1] = 0;
         } else if (super.field_1032[var1].length == 0) {
            super.field_1032[var1] = null;
            super.field_1033[var1] = 0;
         } else {
            super.field_1033[var1] = super.field_1032[var1].length;
         }

         super.field_1041 = super.field_1032[var1].length;
         super.field_1033[var1] = super.field_1041;
         this.method_703();
      }
   }

   // $VF: renamed from: a (int, dn[], bd[]) void
   public final void method_716(int var1, class_19[] var2, class_68[] var3) {
      if (var1 > super.field_1032.length - 1) {
         System.out.println("ERROR: Tab " + var1 + " not available!");
      } else {
         int var4 = 0;
         byte var5 = 0;
         int var6;
         var4 = (var6 = var3 == null ? 0 : var3.length) > 0 ? 1 : 0;
         int var7;
         if ((var7 = var2 == null ? 0 : var2.length) > 0) {
            var5 = 1;
         }

         int var8 = var7 + var6 + var4 + var5;
         class_59[] var9 = null;
         if (var8 > 0) {
            var9 = new class_59[var8];
         }

         int var10 = 0;
         if (var4 > 0) {
            var10++;
            var9[0] = new class_59(class_84.field_1116.method_4(68));
         }

         for (int var11 = 0; var11 < var6; var11++) {
            var9[var10++] = new class_59(var3[var11]);
            boolean var12 = var3[var11].field_884;
            int var13 = var9[var10 - 1].method_545() + (var12 ? class_90.method_783().length : 0);
            if (this.field_1054[var13] == null) {
               this.field_1054[var13] = class_28.method_282("/data/interface/equipment/u" + var9[var10 - 1].method_545() + (var12 ? "b" : "a") + ".png");
            }
         }

         if (var5 > 0) {
            var9[var10++] = new class_59(class_84.field_1116.method_4(69));
         }

         for (int var15 = 0; var15 < var7; var15++) {
            var9[var10++] = new class_59(var2[var15]);
            if (this.field_1053[var9[var10 - 1].method_545()] == null) {
               this.field_1053[var9[var10 - 1].method_545()] = class_28.method_282("/data/interface/equipment/slot_" + var9[var10 - 1].method_545() + ".png");
            }
         }

         if (var9 != null) {
            if (var9.length > 0 && super.field_1039 >= var9.length) {
               super.field_1039 = var9.length - 1;
            }

            boolean var16;
            do {
               var16 = true;

               for (int var17 = var6 + var4 + var5 + 1; var17 < var9.length; var17++) {
                  if (var9[var17 - 1].method_545() > var9[var17].method_545()) {
                     class_59 var18 = var9[var17 - 1];
                     var9[var17 - 1] = var9[var17];
                     var9[var17] = var18;
                     var16 = false;
                  }
               }
            } while (!var16);
         }

         super.field_1032[var1] = var9;
         if (super.field_1032[var1] == null) {
            super.field_1033[var1] = 0;
         } else {
            super.field_1033[var1] = super.field_1032[var1].length;
         }

         this.method_703();
      }
   }

   // $VF: renamed from: d () void
   public void method_704() {
      boolean var1 = false;
      int var2 = super.field_1039;

      for (int var3 = super.field_1039; var3 > 0; var3--) {
         if (((class_59)super.field_1032[super.field_1038][var3 - 1]).field_713) {
            var1 = true;
            break;
         }

         var2--;
      }

      if (super.field_1039 == 0 || super.field_1039 == 1 && !((class_59)super.field_1032[super.field_1038][0]).field_713) {
         var2 = super.field_1033[super.field_1038] - 1;
         super.field_1039 = super.field_1033[super.field_1038] - 1;
         super.field_1040 = super.field_1033[super.field_1038] - super.field_1041 - 1;
      }

      if (var1) {
         super.method_704();
      }

      if (var2 > 0 && !((class_59)super.field_1032[super.field_1038][super.field_1039]).field_713) {
         this.method_704();
      }

      this.method_703();
   }

   // $VF: renamed from: e () void
   public void method_705() {
      boolean var1 = false;
      int var2 = super.field_1039;

      for (int var3 = super.field_1039; var3 < super.field_1033[super.field_1038] - 1; var3++) {
         if (((class_59)super.field_1032[super.field_1038][var3 + 1]).field_713) {
            var1 = true;
            break;
         }

         var2++;
      }

      if (super.field_1039 == super.field_1033[super.field_1038] - 1) {
         var2 = 0;
         super.field_1039 = 0;
         super.field_1040 = 0;
      }

      if (var1) {
         super.method_705();
      }

      if (var2 < super.field_1033[super.field_1038] - 1 && !((class_59)super.field_1032[super.field_1038][super.field_1039]).field_713) {
         this.method_705();
      }

      this.method_703();
   }

   // $VF: renamed from: f () void
   public final void method_703() {
      super.method_703();
      if (super.field_1033[super.field_1038] > 0 && super.field_1039 == 0 && !this.method_717()) {
         super.field_1039++;
         super.method_703();
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_717() {
      return super.field_1033[super.field_1038] == 0 ? false : ((class_59)super.field_1032[super.field_1038][super.field_1039]).field_713;
   }

   // $VF: renamed from: a () void
   public void method_718() {
      this.method_710();
      class_67.method_591(super.field_1050, super.field_1027, super.field_1028, super.field_1029, super.field_1030);
      class_84.field_1117.drawImage(this.field_1056, class_84.field_1120 - 20, class_84.field_1121 - 30 - class_67.method_577(), 40);
      this.method_708();
      this.method_720();
      this.method_709();
   }

   // $VF: renamed from: b () void
   public void method_719() {
      class_84.field_1117.setColor(class_67.field_846);
      class_84.field_1117.fillRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117.drawRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      this.field_1055 = class_84.field_1116.method_4(329) + ":" + class_21.method_178().method_623() + "/" + class_21.method_178().field_869;
      class_58.method_516(this.field_1055, class_84.field_1120 / 2, super.field_1028 + super.field_1030 - 14, 0, 24);
   }

   // $VF: renamed from: g () void
   public void method_720() {
      if (super.field_1032[super.field_1038] != null) {
         class_84.field_1117.setColor(class_67.field_844);

         for (int var1 = super.field_1040;
            var1 < super.field_1032[super.field_1038].length
               && super.field_1032[super.field_1038][var1] != null
               && var1 < super.field_1040 + super.field_1041 + 1;
            var1++
         ) {
            if (((class_59)super.field_1032[super.field_1038][var1]).method_538()) {
               class_84.field_1117.setColor(class_67.field_846);
               class_84.field_1117
                  .fillRect(
                     super.field_1027 + 4,
                     super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                     super.field_1029 - 5 - super.field_1035 - 3,
                     super.field_1044 - 2
                  );
               class_84.field_1117.setColor(class_67.field_844);
               class_84.field_1117
                  .drawRect(
                     super.field_1027 + 4,
                     super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                     super.field_1029 - 5 - super.field_1035 - 3,
                     super.field_1044 - 2
                  );
            } else if (var1 == super.field_1039) {
               class_84.field_1117
                  .fillRect(
                     super.field_1027 + 4, super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2, this.field_1052 + 3, super.field_1044 - 1
                  );
               class_84.field_1117
                  .fillRect(
                     super.field_1042 + this.field_1052 + 4,
                     super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                     super.field_1029 - super.field_1042 - this.field_1052 - 4 - 4 - super.field_1035 - 34,
                     super.field_1044 - 1
                  );
               class_84.field_1117
                  .fillRect(
                     super.field_1027 + super.field_1029 - 5 - super.field_1035 - 33,
                     super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                     35,
                     super.field_1044 - 1
                  );
            }

            this.method_721(super.field_1032[super.field_1038][var1], var1);
         }
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public void method_721(Object var1, int var2) {
      class_59 var3;
      if ((var3 = (class_59)var1).method_538()) {
         class_58.method_518(var3.field_714, super.field_1042 + 3, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 5, 0);
      } else if (var3.method_535()) {
         class_84.field_1117
            .drawImage(
               this.field_1054[var3.field_709.field_863 + (var3.field_709.field_884 ? class_90.method_783().length : 0)],
               super.field_1042 + 2,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + this.method_698() / 2 + 1,
               6
            );
         class_58.method_518(
            class_84.field_1116.method_4(class_1.field_8[var3.field_709.field_863][0]),
            super.field_1042 + this.field_1052 + 5,
            super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
            super.field_1039 == var2 ? 0 : 1
         );
         class_67.method_590(
            var3.field_709.method_603(),
            var3.field_709.method_603() - class_21.method_178().method_603() <= class_21.method_182() ? false : super.field_1038 == 1,
            super.field_1027 + super.field_1029 - 4 - super.field_1035 + 2,
            super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
            super.field_1039 == var2 ? 0 : 1,
            18
         );
      } else if (!var3.method_536()) {
         if (var3.method_540()) {
            class_58.method_518(
               class_84.field_1116.method_4(70),
               super.field_1042 + this.field_1052 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 3,
               super.field_1039 == var2 ? 0 : 1
            );
            class_84.field_1117
               .drawRect(
                  super.field_1027 + 4, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 2 + 4, this.field_1052 + 2, super.field_1044 - 2 - 8
               );
            class_58.method_516(
               "-",
               super.field_1027 + super.field_1029 - 4 - super.field_1035,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
               super.field_1039 == var2 ? 0 : 1,
               18
            );
         }
      } else {
         if (super.field_1038 == 0) {
            class_84.field_1117
               .drawRect(
                  super.field_1027 + 4, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 2 + 4, this.field_1052 + 2, super.field_1044 - 2 - 8
               );
         }

         class_84.field_1117
            .drawImage(
               this.field_1053[var3.field_710.field_166],
               super.field_1042 + 2,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + this.method_698() / 2 + 1,
               6
            );
         String[] var4 = class_58.method_532(
            class_84.field_1116.method_4(class_1.field_6[var3.field_710.field_166][0]),
            super.field_1029 - super.field_1042 - this.field_1052 - 4 - 4 - super.field_1035 - 30
         );

         for (int var5 = 0; var5 < var4.length && var5 < 2; var5++) {
            class_58.method_518(
               var4[var5],
               super.field_1042 + this.field_1052 + 5,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + var5 * 8,
               super.field_1039 == var2 ? 0 : 1
            );
         }

         class_67.method_590(
            var3.field_710.field_167,
            super.field_1038 == 1,
            super.field_1027 + super.field_1029 - 4 - super.field_1035 + 2,
            super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
            super.field_1039 == var2 ? 0 : 1,
            18
         );
      }
   }

   // $VF: renamed from: a () int
   public int method_698() {
      return 18;
   }

   // $VF: renamed from: b () int
   public final int method_699() {
      return class_58.method_527() + 4;
   }
}
