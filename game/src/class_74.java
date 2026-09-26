import javax.microedition.lcdui.Image;

// $VF: renamed from: az
public class class_74 extends class_72 {
   // $VF: renamed from: a int
   public int field_1071 = 31;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   public Image[] field_1072;
   // $VF: renamed from: b javax.microedition.lcdui.Image[]
   public Image[] field_1073;
   // $VF: renamed from: a java.lang.String
   public String field_1074;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_1075;

   public class_74(String[] var1, String var2) {
      this(0, 0, class_41.field_537, class_41.field_538, var1, var2);
   }

   public class_74(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      super(var1, var2, var3, var4, var5, var6);

      try {
         this.field_1072 = new Image[class_24.method_311().length];
         this.field_1073 = new Image[class_24.method_313().length * 2];
      } catch (Exception var8) {
         var8.printStackTrace();
      }

      if (this.field_1075 == null) {
         this.field_1075 = class_40.method_412("/data/interface/logo_" + (class_58.method_565() ? 2 : (class_3.method_110().method_592() ? 0 : 1)) + "_t.png");
      }
   }

   // $VF: renamed from: c () void
   public void method_707() {
      this.field_1072 = null;
      this.field_1073 = null;
   }

   // $VF: renamed from: a (int, be) void
   public final void method_708(int var1, class_32 var2) {
      if (var1 > super.field_1051.length - 1) {
         System.out.println("ERROR: Tab " + var1 + " not available!");
      } else {
         Object var3 = null;
         class_51[] var4 = var2.field_444;
         var3 = new class_2[var2.field_444.length + 3];
         int var5 = 0;
         var5++;
         ((Object[])var3)[0] = new class_2(class_41.field_533.method_297(79));
         var5++;
         ((Object[])var3)[1] = new class_2(var2);
         boolean var6 = var2.field_443;
         int var7 = ((class_2)((Object[])var3)[1]).method_56() + (var6 ? class_24.method_313().length : 0);
         if (this.field_1073[var7] == null) {
            this.field_1073[var7] = class_40.method_412(
               "/data/interface/equipment/u" + ((class_2)((Object[])var3)[1]).method_56() + (var6 ? "b" : "a") + ".png"
            );
         }

         var5++;
         ((Object[])var3)[2] = new class_2(class_41.field_533.method_297(69));

         for (int var8 = 0; var8 < var4.length; var8++) {
            if (var4[var8] != null) {
               ((Object[])var3)[var5++] = new class_2(var4[var8]);
               if (this.field_1072[((class_2)((Object[])var3)[var5 - 1]).method_56()] == null) {
                  this.field_1072[((class_2)((Object[])var3)[var5 - 1]).method_56()] = class_40.method_412(
                     "/data/interface/equipment/slot_" + ((class_2)((Object[])var3)[var5 - 1]).method_56() + ".png"
                  );
               }
            } else {
               ((Object[])var3)[var5++] = new class_2(var8);
            }
         }

         boolean var15;
         do {
            var15 = true;

            for (int var9 = 4; var9 < ((Object[])var3).length; var9++) {
               if (((class_2)((Object[])var3)[var9 - 1]).method_56() > ((class_2)((Object[])var3)[var9]).method_56()) {
                  class_2 var10 = (class_2)((Object[])var3)[var9 - 1];
                  ((Object[])var3)[var9 - 1] = ((Object[])var3)[var9];
                  ((Object[])var3)[var9] = var10;
                  var15 = false;
               }
            }
         } while (!var15);

         super.field_1051[var1] = (Object[])var3;
         if (super.field_1051[var1] == null) {
            super.field_1052[var1] = 0;
         } else if (super.field_1051[var1].length == 0) {
            super.field_1051[var1] = null;
            super.field_1052[var1] = 0;
         } else {
            super.field_1052[var1] = super.field_1051[var1].length;
         }

         super.field_1060 = super.field_1051[var1].length;
         super.field_1052[var1] = super.field_1060;
         this.method_696();
      }
   }

   // $VF: renamed from: a (int, dn[], be[]) void
   public final void method_709(int var1, class_51[] var2, class_32[] var3) {
      if (var1 > super.field_1051.length - 1) {
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
         class_2[] var9 = null;
         if (var8 > 0) {
            var9 = new class_2[var8];
         }

         int var10 = 0;
         if (var4 > 0) {
            var10++;
            var9[0] = new class_2(class_41.field_533.method_297(68));
         }

         for (int var11 = 0; var11 < var6; var11++) {
            var9[var10++] = new class_2(var3[var11]);
            boolean var12 = var3[var11].field_443;
            int var13 = var9[var10 - 1].method_56() + (var12 ? class_24.method_313().length : 0);
            if (this.field_1073[var13] == null) {
               this.field_1073[var13] = class_40.method_412("/data/interface/equipment/u" + var9[var10 - 1].method_56() + (var12 ? "b" : "a") + ".png");
            }
         }

         if (var5 > 0) {
            var9[var10++] = new class_2(class_41.field_533.method_297(69));
         }

         for (int var15 = 0; var15 < var7; var15++) {
            var9[var10++] = new class_2(var2[var15]);
            if (this.field_1072[var9[var10 - 1].method_56()] == null) {
               this.field_1072[var9[var10 - 1].method_56()] = class_40.method_412("/data/interface/equipment/slot_" + var9[var10 - 1].method_56() + ".png");
            }
         }

         if (var9 != null) {
            if (var9.length > 0 && super.field_1058 >= var9.length) {
               super.field_1058 = var9.length - 1;
            }

            boolean var16;
            do {
               var16 = true;

               for (int var17 = var6 + var4 + var5 + 1; var17 < var9.length; var17++) {
                  if (var9[var17 - 1].method_56() > var9[var17].method_56()) {
                     class_2 var18 = var9[var17 - 1];
                     var9[var17 - 1] = var9[var17];
                     var9[var17] = var18;
                     var16 = false;
                  }
               }
            } while (!var16);
         }

         super.field_1051[var1] = var9;
         if (super.field_1051[var1] == null) {
            super.field_1052[var1] = 0;
         } else {
            super.field_1052[var1] = super.field_1051[var1].length;
         }

         this.method_696();
      }
   }

   // $VF: renamed from: d () void
   public void method_697() {
      boolean var1 = false;
      int var2 = super.field_1058;

      for (int var3 = super.field_1058; var3 > 0; var3--) {
         if (((class_2)super.field_1051[super.field_1057][var3 - 1]).field_25) {
            var1 = true;
            break;
         }

         var2--;
      }

      if (super.field_1058 == 0 || super.field_1058 == 1 && !((class_2)super.field_1051[super.field_1057][0]).field_25) {
         var2 = super.field_1052[super.field_1057] - 1;
         super.field_1058 = super.field_1052[super.field_1057] - 1;
         super.field_1059 = super.field_1052[super.field_1057] - super.field_1060 - 1;
      }

      if (var1) {
         super.method_697();
      }

      if (var2 > 0 && !((class_2)super.field_1051[super.field_1057][super.field_1058]).field_25) {
         this.method_697();
      }

      this.method_696();
   }

   // $VF: renamed from: e () void
   public void method_698() {
      boolean var1 = false;
      int var2 = super.field_1058;

      for (int var3 = super.field_1058; var3 < super.field_1052[super.field_1057] - 1; var3++) {
         if (((class_2)super.field_1051[super.field_1057][var3 + 1]).field_25) {
            var1 = true;
            break;
         }

         var2++;
      }

      if (super.field_1058 == super.field_1052[super.field_1057] - 1) {
         var2 = 0;
         super.field_1058 = 0;
         super.field_1059 = 0;
      }

      if (var1) {
         super.method_698();
      }

      if (var2 < super.field_1052[super.field_1057] - 1 && !((class_2)super.field_1051[super.field_1057][super.field_1058]).field_25) {
         this.method_698();
      }

      this.method_696();
   }

   // $VF: renamed from: f () void
   public final void method_696() {
      super.method_696();
      if (super.field_1052[super.field_1057] > 0 && super.field_1058 == 0 && !this.method_710()) {
         super.field_1058++;
         super.method_696();
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_710() {
      return super.field_1052[super.field_1057] == 0 ? false : ((class_2)super.field_1051[super.field_1057][super.field_1058]).field_25;
   }

   // $VF: renamed from: a () void
   public void method_711() {
      this.method_703();
      class_69.method_667(super.field_1069, super.field_1046, super.field_1047, super.field_1048, super.field_1049);
      class_41.field_534.drawImage(this.field_1075, class_41.field_537 - 20, class_41.field_538 - 30 - class_69.method_653(), 40);
      this.method_701();
      this.method_713();
      this.method_702();
   }

   // $VF: renamed from: b () void
   public void method_712() {
      class_41.field_534.setColor(class_69.field_1005);
      class_41.field_534.fillRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534.drawRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      this.field_1074 = class_41.field_533.method_297(329) + ":" + class_3.method_108().method_383() + "/" + class_3.method_108().field_428;
      class_50.method_483(this.field_1074, class_41.field_537 / 2, super.field_1047 + super.field_1049 - 14, 0, 24);
   }

   // $VF: renamed from: g () void
   public void method_713() {
      if (super.field_1051[super.field_1057] != null) {
         class_41.field_534.setColor(class_69.field_1003);

         for (int var1 = super.field_1059;
            var1 < super.field_1051[super.field_1057].length
               && super.field_1051[super.field_1057][var1] != null
               && var1 < super.field_1059 + super.field_1060 + 1;
            var1++
         ) {
            if (((class_2)super.field_1051[super.field_1057][var1]).method_49()) {
               class_41.field_534.setColor(class_69.field_1005);
               class_41.field_534
                  .fillRect(
                     super.field_1046 + 4,
                     super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                     super.field_1048 - 5 - super.field_1054 - 3,
                     super.field_1063 - 2
                  );
               class_41.field_534.setColor(class_69.field_1003);
               class_41.field_534
                  .drawRect(
                     super.field_1046 + 4,
                     super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                     super.field_1048 - 5 - super.field_1054 - 3,
                     super.field_1063 - 2
                  );
            } else if (var1 == super.field_1058) {
               class_41.field_534
                  .fillRect(
                     super.field_1046 + 4, super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2, this.field_1071 + 3, super.field_1063 - 1
                  );
               class_41.field_534
                  .fillRect(
                     super.field_1061 + this.field_1071 + 4,
                     super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                     super.field_1048 - super.field_1061 - this.field_1071 - 4 - 4 - super.field_1054 - 34,
                     super.field_1063 - 1
                  );
               class_41.field_534
                  .fillRect(
                     super.field_1046 + super.field_1048 - 5 - super.field_1054 - 33,
                     super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                     35,
                     super.field_1063 - 1
                  );
            }

            this.method_714(super.field_1051[super.field_1057][var1], var1);
         }
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public void method_714(Object var1, int var2) {
      class_2 var3;
      if ((var3 = (class_2)var1).method_49()) {
         class_50.method_485(var3.field_26, super.field_1061 + 3, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 5, 0);
      } else if (var3.method_46()) {
         class_41.field_534
            .drawImage(
               this.field_1073[var3.field_21.field_422 + (var3.field_21.field_443 ? class_24.method_313().length : 0)],
               super.field_1061 + 2,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + this.method_691() / 2 + 1,
               6
            );
         class_50.method_485(
            class_41.field_533.method_297(class_22.field_322[var3.field_21.field_422][0]),
            super.field_1061 + this.field_1071 + 5,
            super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
            super.field_1058 == var2 ? 0 : 1
         );
         class_69.method_666(
            var3.field_21.method_363(),
            var3.field_21.method_363() - class_3.method_108().method_363() <= class_3.method_112() ? false : super.field_1057 == 1,
            super.field_1046 + super.field_1048 - 4 - super.field_1054 + 2,
            super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
            super.field_1058 == var2 ? 0 : 1,
            18
         );
      } else if (!var3.method_47()) {
         if (var3.method_51()) {
            class_50.method_485(
               class_41.field_533.method_297(70),
               super.field_1061 + this.field_1071 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 3,
               super.field_1058 == var2 ? 0 : 1
            );
            class_41.field_534
               .drawRect(
                  super.field_1046 + 4, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 2 + 4, this.field_1071 + 2, super.field_1063 - 2 - 8
               );
            class_50.method_483(
               "-",
               super.field_1046 + super.field_1048 - 4 - super.field_1054,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
               super.field_1058 == var2 ? 0 : 1,
               18
            );
         }
      } else {
         if (super.field_1057 == 0) {
            class_41.field_534
               .drawRect(
                  super.field_1046 + 4, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 2 + 4, this.field_1071 + 2, super.field_1063 - 2 - 8
               );
         }

         class_41.field_534
            .drawImage(
               this.field_1072[var3.field_22.field_711],
               super.field_1061 + 2,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + this.method_691() / 2 + 1,
               6
            );
         String[] var4 = class_50.method_499(
            class_41.field_533.method_297(class_22.field_320[var3.field_22.field_711][0]),
            super.field_1048 - super.field_1061 - this.field_1071 - 4 - 4 - super.field_1054 - 30
         );

         for (int var5 = 0; var5 < var4.length && var5 < 2; var5++) {
            class_50.method_485(
               var4[var5],
               super.field_1061 + this.field_1071 + 5,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + var5 * 8,
               super.field_1058 == var2 ? 0 : 1
            );
         }

         class_69.method_666(
            var3.field_22.field_712,
            super.field_1057 == 1,
            super.field_1046 + super.field_1048 - 4 - super.field_1054 + 2,
            super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
            super.field_1058 == var2 ? 0 : 1,
            18
         );
      }
   }

   // $VF: renamed from: a () int
   public int method_691() {
      return 18;
   }

   // $VF: renamed from: b () int
   public final int method_692() {
      return class_50.method_494() + 4;
   }
}
