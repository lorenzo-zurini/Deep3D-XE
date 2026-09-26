import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.Sprite;

// $VF: renamed from: di
public final class class_78 extends class_76 {
   // $VF: renamed from: d boolean
   private boolean field_1058;
   // $VF: renamed from: e boolean
   private boolean field_1059;
   // $VF: renamed from: f boolean
   private boolean field_1060;
   // $VF: renamed from: s int
   private int field_1061;
   // $VF: renamed from: a ac[]
   public class_120[] field_1062;
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1063;
   // $VF: renamed from: d javax.microedition.lcdui.Image[]
   private Image[] field_1064;
   // $VF: renamed from: a bt
   private class_52 field_1065;
   // $VF: renamed from: a ab
   private class_121 field_1066;
   // $VF: renamed from: a javax.microedition.lcdui.game.Sprite
   private Sprite field_1067;

   public class_78(String[] var1, String var2) {
      super(var1, var2);
      super.field_1052 = 18;
      this.field_1058 = false;
      this.field_1063 = new Image[class_90.method_785().length];
      this.field_1065 = new class_52();
      this.field_1066 = new class_121();
      super.field_1043 = super.field_1028 + 11 + super.field_1045 + super.field_1044 + 2;
   }

   // $VF: renamed from: c () void
   public final void method_714() {
      super.method_714();
      this.field_1062 = null;
      this.field_1063 = null;
      this.field_1064 = null;
   }

   // $VF: renamed from: a (int, ac[]) void
   public final void method_722(int var1, class_120[] var2) {
      if (var1 == 0) {
         this.field_1062 = var2;
      }

      if (var2 != null) {
         if (this.field_1064 == null) {
            this.field_1064 = new Image[3];

            for (int var3 = 0; var3 < this.field_1064.length; var3++) {
               this.field_1064[var3] = class_28.method_282("/data/interface/x_" + (var3 + 1) + ".png");
            }
         }

         if (this.field_1067 == null) {
            Image var5 = class_28.method_282("/data/interface/coins.png");
            this.field_1067 = new Sprite(var5, var5.getWidth() / 5, var5.getHeight());
         }

         class_59[] var6 = new class_59[var2.length];

         for (int var4 = 0; var4 < var2.length; var4++) {
            var6[var4] = new class_59(var2[var4]);
            if (this.field_1063[var2[var4].field_1480] == null) {
               this.field_1063[var2[var4].field_1480] = class_28.method_282("/data/interface/cargo_" + var2[var4].field_1480 + ".png");
            }
         }

         super.method_700(var1, var6);
         this.field_1061 = class_21.method_178().field_867;
         this.method_703();
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_723() {
      return this.field_1058 || this.field_1059 || this.field_1060;
   }

   // $VF: renamed from: n () void
   public final void method_724() {
      if (this.field_1058) {
         boolean var1 = false;

         for (int var2 = 0; var2 < 5; var2++) {
            this.method_706();
         }
      }
   }

   // $VF: renamed from: o () void
   public final void method_725() {
      if (this.field_1058) {
         boolean var1 = false;

         for (int var2 = 0; var2 < 5; var2++) {
            this.method_707();
         }
      }
   }

   // $VF: renamed from: h () void
   public final void method_706() {
      if (this.field_1058) {
         int var1;
         if ((var1 = ((class_59)super.field_1032[super.field_1038][super.field_1039]).field_711.method_928(false, this.field_1061)) > 0) {
            this.field_1061--;
         }

         class_21.method_197(var1);
         this.method_703();
      } else if (this.field_1059) {
         this.field_1065.method_433();
      } else {
         if (!this.field_1060) {
            super.method_706();
         }
      }
   }

   // $VF: renamed from: i () void
   public final void method_707() {
      if (this.field_1058) {
         int var1;
         if ((var1 = ((class_59)super.field_1032[super.field_1038][super.field_1039]).field_711.method_928(true, this.field_1061)) < 0) {
            this.field_1061++;
         }

         class_21.method_197(var1);
         this.method_703();
      } else if (this.field_1059) {
         this.field_1065.method_434();
      } else {
         if (!this.field_1060) {
            super.method_707();
         }
      }
   }

   // $VF: renamed from: p () void
   public final void method_726() {
      if (this.field_1060) {
         this.field_1060 = false;
      } else if (super.field_1032[super.field_1038] != null) {
         if (super.field_1032[super.field_1038][super.field_1039] != null) {
            class_120 var1 = ((class_59)super.field_1032[super.field_1038][super.field_1039]).field_711;
            if (super.field_1038 == 0) {
               if (var1.field_1490 == 0 && class_21.method_182() < var1.field_1484) {
                  this.field_1066.method_939(class_21.method_219(class_84.field_1116.method_4(85), "" + (var1.field_1484 - class_21.method_182())));
                  this.field_1060 = true;
                  return;
               }

               this.field_1058 = !this.field_1058;
               if (!this.field_1058) {
                  class_21.method_178().method_611(class_120.method_934(this.field_1062, true));
                  class_21.method_180().field_1142 = class_120.method_934(this.field_1062, false);
                  this.method_722(0, class_120.method_935(class_21.method_178().field_886, class_21.method_180().field_1142));
                  this.method_722(1, class_35.method_302());
                  this.method_703();
                  return;
               }
            } else {
               if (this.field_1059) {
                  if (this.field_1065.method_432() && this.field_1065.field_589 > 0) {
                     class_21.method_192(this.field_1065.field_589);
                     this.field_1062 = class_120.method_933(
                        ((class_59)super.field_1032[super.field_1038][super.field_1039]).field_711, this.field_1062, this.field_1065.field_589
                     );
                     class_21.method_193(((class_59)super.field_1032[super.field_1038][super.field_1039]).field_711.field_1480);
                     class_21.method_178().method_611(class_120.method_934(this.field_1062, true));
                     class_21.method_180().field_1142 = class_120.method_934(this.field_1062, false);
                     class_21.method_220();
                     this.method_722(0, class_120.method_935(class_21.method_178().field_886, class_21.method_180().field_1142));
                     this.method_722(1, class_35.method_302());
                     this.method_703();
                  }

                  this.field_1059 = false;
                  return;
               }

               if (var1.field_1490 > 0) {
                  this.field_1059 = true;
                  this.field_1065.method_431(var1);
               }
            }
         }
      }
   }

   // $VF: renamed from: d () void
   public final void method_704() {
      if (!this.field_1058 && !this.field_1060 && !this.field_1059) {
         super.method_704();
      }
   }

   // $VF: renamed from: e () void
   public final void method_705() {
      if (!this.field_1058 && !this.field_1060 && !this.field_1059) {
         super.method_705();
      }
   }

   // $VF: renamed from: b () void
   public final void method_719() {
      if ((!this.field_1058 || this.field_1061 < class_21.method_178().method_607() || !class_67.method_581())
         && this.field_1058
         && this.field_1061 >= class_21.method_178().method_607()) {
         class_84.field_1117.setColor(class_67.field_844);
      } else {
         class_84.field_1117.setColor(class_67.field_846);
      }

      class_84.field_1117.fillRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117.drawRect(super.field_1027 + 4, super.field_1028 + super.field_1030 - 14, super.field_1029 - 8, 10);
      super.field_1055 = class_84.field_1116.method_4(60) + ":" + this.field_1061 + "/" + class_21.method_178().method_607();
      class_58.method_516(super.field_1055, class_84.field_1120 / 2, super.field_1028 + super.field_1030 - 14, 0, 24);
   }

   // $VF: renamed from: a () void
   public final void method_718() {
      super.method_718();
      if (super.field_1038 == 0) {
         this.method_719();
      }

      if (this.field_1059) {
         this.field_1065.method_435();
      }

      if (this.field_1060) {
         this.field_1066.method_944();
      }
   }

   // $VF: renamed from: g () void
   public final void method_720() {
      if (super.field_1032[super.field_1038] != null) {
         class_84.field_1117.setColor(class_67.field_844);
         class_84.field_1117.drawRect(super.field_1027 + 4, super.field_1043 - super.field_1044 + 2, super.field_1029 - 5 - 3, super.field_1044 - 2);
         class_58.method_518(
            super.field_1038 == 0 ? class_84.field_1116.method_4(47) : class_84.field_1116.method_4(268),
            super.field_1042 + 3,
            super.field_1043 - super.field_1044 + 5,
            0
         );
         class_58.method_516(
            super.field_1038 == 0 ? class_84.field_1116.method_4(79) : "",
            super.field_1027 + super.field_1029 - 4 - 2,
            super.field_1043 - super.field_1044 + 5,
            0,
            18
         );

         for (int var1 = super.field_1040;
            var1 < super.field_1032[super.field_1038].length
               && super.field_1032[super.field_1038][var1] != null
               && var1 < super.field_1040 + super.field_1041 + 1;
            var1++
         ) {
            Object var2 = null;
            if (var1 == super.field_1039) {
               class_84.field_1117
                  .fillRect(super.field_1027 + 4, super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2, 23, super.field_1044 - 1);
               class_84.field_1117
                  .fillRect(
                     super.field_1042 + 22 + 2, super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2, super.field_1052 + 2, super.field_1044 - 1
                  );
               if (super.field_1038 == 0) {
                  class_84.field_1117
                     .fillRect(
                        super.field_1042 + 22 + 2 + super.field_1052 + 3,
                        super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                        super.field_1029 - super.field_1042 - super.field_1052 - 44 - 9 - super.field_1035,
                        super.field_1044 - 1
                     );
                  class_84.field_1117
                     .fillRect(
                        super.field_1027 + super.field_1029 - super.field_1035 - 4 - 22,
                        super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                        23,
                        super.field_1044 - 1
                     );
               } else {
                  class_84.field_1117
                     .fillRect(
                        super.field_1042 + 22 + 2 + super.field_1052 + 3,
                        super.field_1043 + (var1 - super.field_1040) * super.field_1044 + 2,
                        super.field_1029 - super.field_1042 - super.field_1052 - 22 + 3 - 9 - super.field_1035,
                        super.field_1044 - 1
                     );
               }
            }

            this.method_721(super.field_1032[super.field_1038][var1], var1);
         }
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_721(Object var1, int var2) {
      class_120 var3 = ((class_59)var1).field_711;
      class_84.field_1117
         .drawImage(this.field_1063[var3.field_1480], super.field_1042 + 22 + 3, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 3, 0);
      class_58.method_516(
         super.field_1038 == 0 ? var3.field_1491 + "t" : var3.field_1490 + " X",
         super.field_1042 + 22,
         super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
         super.field_1039 == var2 ? 0 : 1,
         18
      );
      class_67.method_598(
         class_84.field_1116.method_4(class_1.field_7[var3.field_1480][0]) + " ",
         super.field_1042 + 22 + super.field_1052 + 6,
         super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
         super.field_1029 - super.field_1042 - super.field_1052 - 44 - 9 - super.field_1035 + (super.field_1038 == 1 ? 25 : 2),
         super.field_1039 == var2 ? 0 : 1
      );
      if (super.field_1038 == 0) {
         if (var3.field_1490 == 0 && var3.field_1484 > class_21.method_182()) {
            class_67.method_590(
               var3.field_1484,
               var3.field_1490 == 0,
               super.field_1042 + 22 + super.field_1052 + 6,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8,
               0,
               0
            );
         } else {
            class_58.method_516(
               var3.field_1484 + "",
               super.field_1042 + 22 + super.field_1052 + 6,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8,
               0,
               0
            );
            this.field_1067.setFrame((int)(var3.method_925() * (this.field_1067.getRawFrameCount() - 1.0F)));
            this.field_1067
               .setPosition(
                  class_58.method_523(var3.field_1484 + " ") + super.field_1042 + 22 + super.field_1052 + 6,
                  super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8 + 2
               );
            this.field_1067.paint(class_84.field_1117);
         }

         class_58.method_518(
            var3.field_1490 + "t",
            super.field_1027 + super.field_1029 - 4 - super.field_1035 - 22 + 1,
            super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1,
            super.field_1039 == var2 ? 0 : 1
         );
         if (this.field_1058 && var2 == super.field_1039 && class_67.method_581()) {
            class_58.method_516("<", super.field_1042 + 22, super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8, 0, 18);
            class_58.method_518(
               ">",
               super.field_1027 + super.field_1029 - 4 - super.field_1035 - 22 + 1,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 1 + 8,
               0
            );
            return;
         }
      } else if (var3.field_1490 == 0) {
         int var4 = var3.field_1492;
         class_84.field_1117
            .drawImage(
               var4 == 1 ? this.field_1064[1] : (var4 == var3.field_1488.length ? this.field_1064[0] : this.field_1064[2]),
               super.field_1042 + 22 + 3,
               super.field_1043 + (var2 - super.field_1040) * super.field_1044 + 3,
               0
            );
      }
   }
}
