import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.Sprite;

// $VF: renamed from: di
public final class class_75 extends class_74 {
   // $VF: renamed from: d boolean
   private boolean field_1076;
   // $VF: renamed from: e boolean
   private boolean field_1077;
   // $VF: renamed from: f boolean
   private boolean field_1078;
   // $VF: renamed from: s int
   private int field_1079;
   // $VF: renamed from: a aa[]
   public class_46[] field_1080;
   // $VF: renamed from: c javax.microedition.lcdui.Image[]
   private Image[] field_1081;
   // $VF: renamed from: d javax.microedition.lcdui.Image[]
   private Image[] field_1082;
   // $VF: renamed from: a bt
   private class_28 field_1083;
   // $VF: renamed from: a z
   private class_53 field_1084;
   // $VF: renamed from: a javax.microedition.lcdui.game.Sprite
   private Sprite field_1085;

   public class_75(String[] var1, String var2) {
      super(var1, var2);
      super.field_1071 = 18;
      this.field_1076 = false;
      this.field_1081 = new Image[class_24.method_315().length];
      this.field_1083 = new class_28();
      this.field_1084 = new class_53();
      super.field_1062 = super.field_1047 + 11 + super.field_1064 + super.field_1063 + 2;
   }

   // $VF: renamed from: c () void
   public final void method_707() {
      super.method_707();
      this.field_1080 = null;
      this.field_1081 = null;
      this.field_1082 = null;
   }

   // $VF: renamed from: a (int, aa[]) void
   public final void method_715(int var1, class_46[] var2) {
      if (var1 == 0) {
         this.field_1080 = var2;
      }

      if (var2 != null) {
         if (this.field_1082 == null) {
            this.field_1082 = new Image[3];

            for (int var3 = 0; var3 < this.field_1082.length; var3++) {
               this.field_1082[var3] = class_40.method_412("/data/interface/x_" + (var3 + 1) + ".png");
            }
         }

         if (this.field_1085 == null) {
            Image var5 = class_40.method_412("/data/interface/coins.png");
            this.field_1085 = new Sprite(var5, var5.getWidth() / 5, var5.getHeight());
         }

         class_2[] var6 = new class_2[var2.length];

         for (int var4 = 0; var4 < var2.length; var4++) {
            var6[var4] = new class_2(var2[var4]);
            if (this.field_1081[var2[var4].field_626] == null) {
               this.field_1081[var2[var4].field_626] = class_40.method_412("/data/interface/cargo_" + var2[var4].field_626 + ".png");
            }
         }

         super.method_693(var1, var6);
         this.field_1079 = class_3.method_108().field_426;
         this.method_696();
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_716() {
      return this.field_1076 || this.field_1077 || this.field_1078;
   }

   // $VF: renamed from: n () void
   public final void method_717() {
      if (this.field_1076) {
         boolean var1 = false;

         for (int var2 = 0; var2 < 5; var2++) {
            this.method_699();
         }
      }
   }

   // $VF: renamed from: o () void
   public final void method_718() {
      if (this.field_1076) {
         boolean var1 = false;

         for (int var2 = 0; var2 < 5; var2++) {
            this.method_700();
         }
      }
   }

   // $VF: renamed from: h () void
   public final void method_699() {
      if (this.field_1076) {
         int var1;
         if ((var1 = ((class_2)super.field_1051[super.field_1057][super.field_1058]).field_23.method_446(false, this.field_1079)) > 0) {
            this.field_1079--;
         }

         class_3.method_127(var1);
         this.method_696();
      } else if (this.field_1077) {
         this.field_1083.method_339();
      } else {
         if (!this.field_1078) {
            super.method_699();
         }
      }
   }

   // $VF: renamed from: i () void
   public final void method_700() {
      if (this.field_1076) {
         int var1;
         if ((var1 = ((class_2)super.field_1051[super.field_1057][super.field_1058]).field_23.method_446(true, this.field_1079)) < 0) {
            this.field_1079++;
         }

         class_3.method_127(var1);
         this.method_696();
      } else if (this.field_1077) {
         this.field_1083.method_340();
      } else {
         if (!this.field_1078) {
            super.method_700();
         }
      }
   }

   // $VF: renamed from: p () void
   public final void method_719() {
      if (this.field_1078) {
         this.field_1078 = false;
      } else if (super.field_1051[super.field_1057] != null) {
         if (super.field_1051[super.field_1057][super.field_1058] != null) {
            class_46 var1 = ((class_2)super.field_1051[super.field_1057][super.field_1058]).field_23;
            if (super.field_1057 == 0) {
               if (var1.field_636 == 0 && class_3.method_112() < var1.field_630) {
                  this.field_1084.method_513(class_3.method_149(class_41.field_533.method_297(85), "" + (var1.field_630 - class_3.method_112())));
                  this.field_1078 = true;
                  return;
               }

               this.field_1076 = !this.field_1076;
               if (!this.field_1076) {
                  class_3.method_108().method_371(class_46.method_452(this.field_1080, true));
                  class_3.method_110().field_836 = class_46.method_452(this.field_1080, false);
                  this.method_715(0, class_46.method_453(class_3.method_108().field_445, class_3.method_110().field_836));
                  this.method_715(1, class_9.method_199());
                  this.method_696();
                  return;
               }
            } else {
               if (this.field_1077) {
                  if (this.field_1083.method_338() && this.field_1083.field_397 > 0) {
                     class_3.method_122(this.field_1083.field_397);
                     this.field_1080 = class_46.method_451(
                        ((class_2)super.field_1051[super.field_1057][super.field_1058]).field_23, this.field_1080, this.field_1083.field_397
                     );
                     class_3.method_123(((class_2)super.field_1051[super.field_1057][super.field_1058]).field_23.field_626);
                     class_3.method_108().method_371(class_46.method_452(this.field_1080, true));
                     class_3.method_110().field_836 = class_46.method_452(this.field_1080, false);
                     class_3.method_150();
                     this.method_715(0, class_46.method_453(class_3.method_108().field_445, class_3.method_110().field_836));
                     this.method_715(1, class_9.method_199());
                     this.method_696();
                  }

                  this.field_1077 = false;
                  return;
               }

               if (var1.field_636 > 0) {
                  this.field_1077 = true;
                  this.field_1083.method_337(var1);
               }
            }
         }
      }
   }

   // $VF: renamed from: d () void
   public final void method_697() {
      if (!this.field_1076 && !this.field_1078 && !this.field_1077) {
         super.method_697();
      }
   }

   // $VF: renamed from: e () void
   public final void method_698() {
      if (!this.field_1076 && !this.field_1078 && !this.field_1077) {
         super.method_698();
      }
   }

   // $VF: renamed from: b () void
   public final void method_712() {
      if ((!this.field_1076 || this.field_1079 < class_3.method_108().method_367() || !class_69.method_657())
         && this.field_1076
         && this.field_1079 >= class_3.method_108().method_367()) {
         class_41.field_534.setColor(class_69.field_1003);
      } else {
         class_41.field_534.setColor(class_69.field_1005);
      }

      class_41.field_534.fillRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534.drawRect(super.field_1046 + 4, super.field_1047 + super.field_1049 - 14, super.field_1048 - 8, 10);
      super.field_1074 = class_41.field_533.method_297(60) + ":" + this.field_1079 + "/" + class_3.method_108().method_367();
      class_50.method_483(super.field_1074, class_41.field_537 / 2, super.field_1047 + super.field_1049 - 14, 0, 24);
   }

   // $VF: renamed from: a () void
   public final void method_711() {
      super.method_711();
      if (super.field_1057 == 0) {
         this.method_712();
      }

      if (this.field_1077) {
         this.field_1083.method_341();
      }

      if (this.field_1078) {
         this.field_1084.method_518();
      }
   }

   // $VF: renamed from: g () void
   public final void method_713() {
      if (super.field_1051[super.field_1057] != null) {
         class_41.field_534.setColor(class_69.field_1003);
         class_41.field_534.drawRect(super.field_1046 + 4, super.field_1062 - super.field_1063 + 2, super.field_1048 - 5 - 3, super.field_1063 - 2);
         class_50.method_485(
            super.field_1057 == 0 ? class_41.field_533.method_297(47) : class_41.field_533.method_297(268),
            super.field_1061 + 3,
            super.field_1062 - super.field_1063 + 5,
            0
         );
         class_50.method_483(
            super.field_1057 == 0 ? class_41.field_533.method_297(79) : "",
            super.field_1046 + super.field_1048 - 4 - 2,
            super.field_1062 - super.field_1063 + 5,
            0,
            18
         );

         for (int var1 = super.field_1059;
            var1 < super.field_1051[super.field_1057].length
               && super.field_1051[super.field_1057][var1] != null
               && var1 < super.field_1059 + super.field_1060 + 1;
            var1++
         ) {
            Object var2 = null;
            if (var1 == super.field_1058) {
               class_41.field_534.fillRect(super.field_1046 + 4, super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2, 23, super.field_1063 - 1);
               class_41.field_534
                  .fillRect(
                     super.field_1061 + 22 + 2, super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2, super.field_1071 + 2, super.field_1063 - 1
                  );
               if (super.field_1057 == 0) {
                  class_41.field_534
                     .fillRect(
                        super.field_1061 + 22 + 2 + super.field_1071 + 3,
                        super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                        super.field_1048 - super.field_1061 - super.field_1071 - 44 - 9 - super.field_1054,
                        super.field_1063 - 1
                     );
                  class_41.field_534
                     .fillRect(
                        super.field_1046 + super.field_1048 - super.field_1054 - 4 - 22,
                        super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                        23,
                        super.field_1063 - 1
                     );
               } else {
                  class_41.field_534
                     .fillRect(
                        super.field_1061 + 22 + 2 + super.field_1071 + 3,
                        super.field_1062 + (var1 - super.field_1059) * super.field_1063 + 2,
                        super.field_1048 - super.field_1061 - super.field_1071 - 22 + 3 - 9 - super.field_1054,
                        super.field_1063 - 1
                     );
               }
            }

            this.method_714(super.field_1051[super.field_1057][var1], var1);
         }
      }
   }

   // $VF: renamed from: a (java.lang.Object, int) void
   public final void method_714(Object var1, int var2) {
      class_46 var3 = ((class_2)var1).field_23;
      class_41.field_534
         .drawImage(this.field_1081[var3.field_626], super.field_1061 + 22 + 3, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 3, 0);
      class_50.method_483(
         super.field_1057 == 0 ? var3.field_637 + "t" : var3.field_636 + " X",
         super.field_1061 + 22,
         super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
         super.field_1058 == var2 ? 0 : 1,
         18
      );
      class_69.method_674(
         class_41.field_533.method_297(class_22.field_321[var3.field_626][0]) + " ",
         super.field_1061 + 22 + super.field_1071 + 6,
         super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
         super.field_1048 - super.field_1061 - super.field_1071 - 44 - 9 - super.field_1054 + (super.field_1057 == 1 ? 25 : 2),
         super.field_1058 == var2 ? 0 : 1
      );
      if (super.field_1057 == 0) {
         if (var3.field_636 == 0 && var3.field_630 > class_3.method_112()) {
            class_69.method_666(
               var3.field_630,
               var3.field_636 == 0,
               super.field_1061 + 22 + super.field_1071 + 6,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8,
               0,
               0
            );
         } else {
            class_50.method_483(
               var3.field_630 + "", super.field_1061 + 22 + super.field_1071 + 6, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8, 0, 0
            );
            this.field_1085.setFrame((int)(var3.method_443() * (this.field_1085.getRawFrameCount() - 1.0F)));
            this.field_1085
               .setPosition(
                  class_50.method_490(var3.field_630 + " ") + super.field_1061 + 22 + super.field_1071 + 6,
                  super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8 + 2
               );
            this.field_1085.paint(class_41.field_534);
         }

         class_50.method_485(
            var3.field_636 + "t",
            super.field_1046 + super.field_1048 - 4 - super.field_1054 - 22 + 1,
            super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1,
            super.field_1058 == var2 ? 0 : 1
         );
         if (this.field_1076 && var2 == super.field_1058 && class_69.method_657()) {
            class_50.method_483("<", super.field_1061 + 22, super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8, 0, 18);
            class_50.method_485(
               ">",
               super.field_1046 + super.field_1048 - 4 - super.field_1054 - 22 + 1,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 1 + 8,
               0
            );
            return;
         }
      } else if (var3.field_636 == 0) {
         int var4 = var3.field_638;
         class_41.field_534
            .drawImage(
               var4 == 1 ? this.field_1082[1] : (var4 == var3.field_634.length ? this.field_1082[0] : this.field_1082[2]),
               super.field_1061 + 22 + 3,
               super.field_1062 + (var2 - super.field_1059) * super.field_1063 + 3,
               0
            );
      }
   }
}
