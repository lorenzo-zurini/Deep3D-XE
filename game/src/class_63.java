import javax.microedition.lcdui.Image;

// $VF: renamed from: ch
public final class class_63 extends class_61 {
   // $VF: renamed from: a long
   private long field_732;
   // $VF: renamed from: b long
   private long field_733;
   // $VF: renamed from: c long
   private long field_734;
   // $VF: renamed from: d long
   private long field_735;
   // $VF: renamed from: e long
   private long field_736;
   // $VF: renamed from: a int
   private int field_737;
   // $VF: renamed from: a int[]
   private int[] field_738;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_739;
   // $VF: renamed from: a bj
   public class_65 field_740;
   // $VF: renamed from: a bu
   private class_51 field_741;
   // $VF: renamed from: a boolean
   private boolean field_742;
   // $VF: renamed from: b boolean
   private boolean field_743;
   // $VF: renamed from: c boolean
   private boolean field_744;
   // $VF: renamed from: d boolean
   private boolean field_745;
   // $VF: renamed from: e boolean
   private boolean field_746;
   // $VF: renamed from: f boolean
   private boolean field_747;
   // $VF: renamed from: g boolean
   private boolean field_748;
   // $VF: renamed from: h boolean
   private boolean field_749;
   // $VF: renamed from: i boolean
   private boolean field_750;
   // $VF: renamed from: j boolean
   private boolean field_751;
   // $VF: renamed from: k boolean
   private boolean field_752;
   // $VF: renamed from: l boolean
   private boolean field_753;
   // $VF: renamed from: a ab
   private class_121 field_754;
   // $VF: renamed from: a cn
   private class_36 field_755;
   // $VF: renamed from: a aj
   private class_89 field_756;
   // $VF: renamed from: a bp
   public class_55 field_757;
   // $VF: renamed from: a ds
   private class_17 field_758;
   // $VF: renamed from: a bv
   private class_50 field_759;
   // $VF: renamed from: a bo
   private class_56 field_760;
   // $VF: renamed from: b bo
   private class_56 field_761;
   // $VF: renamed from: a h
   private class_12 field_762;
   // $VF: renamed from: a aa
   private class_122 field_763;
   // $VF: renamed from: a am
   private class_87 field_764;
   // $VF: renamed from: b int
   private int field_765;
   // $VF: renamed from: c int
   private int field_766;
   // $VF: renamed from: d int
   private int field_767;
   // $VF: renamed from: m boolean
   private boolean field_768 = false;
   // $VF: renamed from: n boolean
   private boolean field_769 = false;
   // $VF: renamed from: o boolean
   private boolean field_770;
   // $VF: renamed from: e int
   private int field_771;
   // $VF: renamed from: a int[][]
   private int[][] field_772;
   // $VF: renamed from: f int
   private int field_773;
   // $VF: renamed from: p boolean
   private boolean field_774;
   // $VF: renamed from: q boolean
   private boolean field_775;
   // $VF: renamed from: g int
   private int field_776;
   // $VF: renamed from: r boolean
   private boolean field_777;

   // $VF: renamed from: b () void
   public final void method_552() {
      this.field_756.method_774();
      this.field_756 = null;
      this.field_757.method_443();
      this.field_757 = null;
      this.field_758.method_101();
      this.field_758 = null;
      this.field_738 = null;
      this.field_741.method_417();
      this.field_741 = null;
      this.field_755.method_311();
      this.field_755 = null;
      this.field_754 = null;
      if (this.field_740 != null) {
         this.field_740.method_552();
      }

      this.field_740 = null;
      this.field_777 = false;
      this.field_739 = null;
      System.gc();
   }

   // $VF: renamed from: c () void
   public final void method_554() {
      this.field_768 = true;
   }

   // $VF: renamed from: a () void
   public final void method_551() {
      if (this.field_740 == null) {
         this.field_774 = false;
         if (!class_38.method_356()[class_21.method_180().field_1134]) {
            this.field_774 = true;
         }

         this.field_776 = class_21.method_180().method_752() ? 100 : 50;
         long var1 = class_21.field_221;
         class_21.method_131(class_21.method_180());
         if (class_21.method_212() - var1 > 30000L) {
            class_35.method_303(class_21.method_180());
         }

         class_21.method_180().method_746();
         class_49.method_404();
         this.field_740 = new class_65(0);
      }

      if (!this.field_740.field_823) {
         this.field_740.method_551();
      } else {
         class_14.method_84();
         if (this.field_741 == null) {
            this.field_741 = new class_51();
         }

         this.field_743 = false;
         if (this.field_755 == null) {
            this.field_755 = new class_36();
         } else {
            this.field_745 = false;
            if (this.field_756 == null) {
               this.field_756 = new class_89();
               this.field_756.method_775();
            } else {
               this.field_746 = false;
               if (this.field_757 == null) {
                  this.field_757 = new class_55();
                  this.field_757.method_446();
               } else {
                  this.field_747 = false;
                  this.field_742 = true;
                  this.field_759 = new class_50();
                  this.field_749 = false;
                  this.field_762 = new class_12();
                  this.field_751 = false;
                  this.field_753 = false;
                  this.field_738 = new int[7];

                  for (int var3 = 0; var3 < this.field_738.length; var3++) {
                     this.field_738[var3] = 0;
                     if (var3 == this.field_737) {
                        this.field_738[var3] = 1;
                     }
                  }

                  this.field_765 = 1;
                  this.field_766 = class_84.field_1121 - 32 - this.field_738.length * 10;
                  this.field_767 = 60;
                  this.field_771 = 0;
                  this.field_769 = false;
                  this.field_770 = false;
                  this.field_736 = 0L;
                  this.field_754 = new class_121(20, class_84.field_1121 / 2, class_84.field_1120 - 40);
                  this.field_739 = class_28.method_282(
                     "/data/interface/logo_" + (class_14.method_70() ? 2 : (class_21.method_180().method_752() ? 0 : 1)) + ".png"
                  );
                  if (!this.field_768) {
                     this.method_556();
                     if (class_21.method_180().method_752()) {
                        this.field_771 = class_21.method_178().method_620();
                        if (this.field_771 > 0) {
                           this.method_555(class_84.field_1116.method_4(257) + "      " + this.field_771 + " $");
                        }
                     } else if (class_21.method_143() == 12 && class_21.method_180().field_1134 == 3) {
                        this.method_555(class_84.field_1116.method_4(258));
                     }

                     if (class_21.method_143() == 2) {
                        class_21.method_180().field_1141 = new class_19[]{class_90.method_781()[0].method_120()};
                        this.field_756.method_775();
                     }

                     if ((class_21.method_143() == 33 || class_21.method_143() == 34) && class_21.method_180().field_1134 == class_21.method_137().field_1152) {
                        if (!class_120.method_932(37, class_21.method_180().field_1142)) {
                           class_21.method_180().field_1142 = class_120.method_936(
                              class_21.method_180().field_1142, new class_120[]{class_90.method_785()[37].method_929(1)}
                           );
                        }
                     } else if ((class_21.method_143() == 36 || class_21.method_143() == 37)
                        && class_21.method_180().field_1134 == class_21.method_137().field_1152) {
                        if (!class_120.method_932(38, class_21.method_180().field_1142)) {
                           class_21.method_180().field_1142 = class_120.method_936(
                              class_21.method_180().field_1142, new class_120[]{class_90.method_785()[38].method_929(1)}
                           );
                        }
                     } else if ((class_21.method_143() == 41 && class_120.method_932(36, class_21.method_178().field_886) || class_21.method_143() == 42)
                        && class_21.method_180().field_1134 == 14
                        && !class_21.method_178().method_609(42)
                        && !class_21.method_180().method_747(42)) {
                        class_21.method_180().method_748(class_90.method_781()[42].method_120());
                        this.field_756.method_775();
                     }
                  }

                  if (!this.field_769 && !this.field_768) {
                     class_21.method_197(this.field_771);
                     class_27.method_277(3);
                     class_21.method_197(-this.field_771);
                     this.field_769 = true;
                  }

                  if (this.field_758 == null) {
                     this.field_758 = new class_17();
                     this.field_758.method_102();
                  }

                  this.field_748 = false;
                  class_84.field_1122.method_768(1);
                  this.field_735 = 0L;
                  class_49.method_403();
                  System.gc();
                  this.field_732 = System.currentTimeMillis();
                  this.field_733 = System.currentTimeMillis();
                  this.field_777 = true;
                  class_67.method_578(!class_21.method_180().method_752());
               }
            }
         }
      }
   }

   // $VF: renamed from: a (java.lang.String) void
   private void method_555(String var1) {
      this.field_754.method_939(var1);
      this.field_744 = true;
   }

   // $VF: renamed from: e () void
   private void method_556() {
      if (!this.field_752 && !this.field_753) {
         this.field_772 = (int[][])null;
         int[] var1 = class_14.method_72();
         int var2 = 0;

         for (int var3 = 0; var3 < var1.length; var3++) {
            if (var1[var3] > 0) {
               var2++;
            }
         }

         if (var2 > 0) {
            this.field_772 = new int[var2][2];
            var2 = 0;

            for (int var5 = 0; var5 < var1.length; var5++) {
               if (var1[var5] > 0) {
                  this.field_772[var2++] = new int[]{var5, var1[var5]};
               }
            }

            this.field_752 = true;
            this.field_773 = 0;
            this.field_763 = new class_122();
            this.field_763.method_945(this.field_772[0][0], this.field_772[0][1]);
         }
      } else {
         this.field_773++;
         if (this.field_773 >= this.field_772.length) {
            this.field_752 = false;
         } else {
            this.field_763.method_945(this.field_772[this.field_773][0], this.field_772[this.field_773][1]);
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_553() {
      return this.field_777;
   }

   // $VF: renamed from: b (int) void
   public final void method_549(int var1) {
      if (this.field_777) {
         class_67.method_597(false);
         this.field_732 = System.currentTimeMillis();
         this.field_734 = this.field_732 - this.field_733;
         this.field_733 = this.field_732;
         this.field_735 = this.field_735 + this.field_734;
         this.field_736 = this.field_736 + this.field_734;
         class_21.method_211(this.field_734);
         class_14.method_80(class_21.method_182());
         if (!this.field_745 && !this.field_746 && !this.field_747 && !this.field_748 && !this.field_749 && !this.field_751 && this.field_740 != null) {
            this.field_740.method_571();
         }

         if (this.field_736 < 2300L) {
            org.deep3d.GameUi.controls(org.deep3d.GameUi.SCREEN, org.deep3d.GameUi.FIRE, org.deep3d.GameUi.NONE, org.deep3d.GameUi.NONE); // Deep3D-PC: skip the banner
            class_58.method_518(
               class_84.field_1116.method_4(this.field_768 ? 36 : 32), 5, class_84.field_1121 - class_67.method_577() - class_58.method_527(), 1
            );
         } else {
            this.field_768 = false;
         }

         if (this.field_736 >= 2300L) {
            if (!this.field_750) {
               class_87 var2;
               if ((var2 = class_21.method_148(true, 0L)) != null) {
                  this.field_764 = var2;
               }

               if (var2 != null) {
                  this.field_760 = new class_56(var2, 1);
                  this.field_750 = true;
               }
            }

            if (!this.field_744 && !this.field_750) {
               this.method_557();
            }

            int var3 = var1;
            if (this.field_753) {
               var3 = 0;
            }

            if (this.field_751) {
               this.field_762.method_60(var3, (int)this.field_734);
            } else {
               if (this.field_750) {
                  if (this.field_748 || this.field_745 || this.field_746) {
                     class_67.method_587();
                  }

                  this.field_760.method_460(var3, (int)this.field_734);
                  this.field_760.method_467();
               } else if (this.field_743) {
                  this.field_741.method_418(var3, (int)this.field_734);
                  this.field_741.method_429();
               } else if (this.field_745) {
                  class_67.method_579((int)this.field_734);
                  this.field_755.method_317(var3, (int)this.field_734);
                  if (this.field_755 != null && this.field_755.method_319()) {
                     if (this.field_757.method_449() && this.field_761 == null && !class_84.field_1096) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(360));
                        class_84.field_1096 = true;
                        this.field_753 = true;
                     }

                     if (!this.field_757.method_449() && this.field_761 == null && !class_84.field_1095) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(359));
                        class_84.field_1095 = true;
                        this.field_753 = true;
                     }
                  } else if (this.field_755 != null && this.field_755.method_318()) {
                     if (this.field_757.method_449() && this.field_761 == null && !class_84.field_1090) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(362));
                        class_84.field_1090 = true;
                        this.field_753 = true;
                     }

                     if (!this.field_757.method_449() && this.field_761 == null && !class_84.field_1089) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(361));
                        class_84.field_1089 = true;
                        this.field_753 = true;
                     }
                  }
               } else if (this.field_746) {
                  class_67.method_579((int)this.field_734);
                  this.field_756.method_778(var3, (int)this.field_734);
               } else if (this.field_747) {
                  this.field_757.method_450(var3, (int)this.field_734);
                  if (this.field_757 != null) {
                     if (this.field_757.method_449() && this.field_761 == null && !class_84.field_1090) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(362));
                        class_84.field_1090 = true;
                        this.field_753 = true;
                     }

                     if (!this.field_757.method_449() && this.field_761 == null && !class_84.field_1089) {
                        this.field_761 = new class_56(class_84.field_1116.method_4(361));
                        class_84.field_1089 = true;
                        this.field_753 = true;
                     }
                  }
               } else if (this.field_748) {
                  class_67.method_579((int)this.field_734);
                  this.field_758.method_104(var3, (int)this.field_734);
               } else if (this.field_749) {
                  class_67.method_579((int)this.field_734);
                  this.field_759.method_413(var3, (int)this.field_734);
               } else {
                  this.method_558();
               }

               if (this.field_753) {
                  this.field_761.method_460(var1, (int)this.field_734);
                  this.field_761.method_468();
               }
            }
         }
      }
   }

   // $VF: renamed from: d () void
   public final void method_557() {
      if (this.field_774 && this.field_761 == null && class_21.method_143() == 16 && class_21.method_180().field_1134 != 5) {
         this.field_761 = new class_56(class_21.method_219(class_84.field_1116.method_4(280), class_21.method_213()));
         this.field_774 = false;
         this.field_753 = true;
      }

      if (this.field_774
         && this.field_761 == null
         && class_21.method_143() == 18
         && !class_21.method_180().method_752()
         && class_21.method_180().field_1134 != 6) {
         this.field_761 = new class_56(class_84.field_1116.method_4(281));
         this.field_753 = true;
         this.field_774 = false;
      }

      if (this.field_761 == null && !class_84.field_1103 && class_21.method_178().method_605()) {
         this.field_761 = new class_56(class_84.field_1116.method_4(346));
         this.field_753 = true;
         class_84.field_1103 = true;
      }

      if (!this.field_752 && this.field_761 == null && !class_84.field_1105 && class_14.method_69()) {
         this.field_761 = new class_56(class_84.field_1116.method_4(350));
         class_84.field_1105 = true;
         this.field_753 = true;
      }

      if (!this.field_752 && this.field_761 == null && !class_84.field_1106 && class_14.method_70()) {
         this.field_761 = new class_56(class_84.field_1116.method_4(351));
         class_84.field_1106 = true;
         this.field_753 = true;
      }

      if (!this.field_752 && this.field_761 == null && !class_84.field_1107 && !class_14.method_69() && class_21.method_146()) {
         this.field_761 = new class_56(class_84.field_1116.method_4(352));
         class_84.field_1107 = true;
         this.field_753 = true;
      }

      if (!this.field_752 && this.field_761 == null && !this.field_775 && class_14.method_76() > 0) {
         int var1;
         int var2 = (var1 = class_14.method_76()) < 4 ? 284 : (var1 < 7 ? 285 : (var1 < 12 ? 286 : 287));
         this.field_761 = new class_56(
            class_84.field_1116.method_4(283)
               + ": "
               + var1
               + "\n"
               + var1
               + " x "
               + var1
               + " x "
               + this.field_776
               + " $\n"
               + class_84.field_1116.method_4(40)
               + ": "
               + var1 * var1 * this.field_776
               + " $\n\n"
               + class_84.field_1116.method_4(var2)
               + "\n",
            true
         );
         this.field_775 = true;
         this.field_753 = true;
      }
   }

   // $VF: renamed from: f () void
   private void method_558() {
      // Deep3D-PC: Confirm opens the highlighted entry (FIRE); the left
      // softkey hides the menu (Secondary) or brings it back (Confirm);
      // Back = Depart
      if (this.field_742) {
         org.deep3d.GameUi.controls(org.deep3d.GameUi.SCREEN, org.deep3d.GameUi.FIRE, org.deep3d.GameUi.RSK, org.deep3d.GameUi.LSK);
      } else {
         org.deep3d.GameUi.controls(org.deep3d.GameUi.SCREEN, org.deep3d.GameUi.LSK, org.deep3d.GameUi.RSK, org.deep3d.GameUi.NONE);
      }
      class_84.field_1117.drawImage(this.field_739, 3, 3, 0);
      class_58.method_516(class_21.method_180().field_1133, this.field_739.getWidth() + 6, 3, 0, 17);
      class_58.method_516(
         class_84.field_1116.method_4(class_1.field_9[class_21.method_175()[class_21.method_180().field_1134] ? 1 : 0]),
         this.field_739.getWidth() + 6,
         13,
         1,
         17
      );
      class_58.method_516(class_84.field_1116.method_4(44) + ": " + class_21.method_180().field_1139, this.field_739.getWidth() + 6, 23, 1, 17);
      if (this.field_742) {
         class_67.method_591("", this.field_765, this.field_766, this.field_767, 12 + (this.field_738.length + 1) * 10 - 5);
         class_67.method_585(class_84.field_1116.method_4(62), this.field_765, this.field_766 + 12, this.field_767, this.field_738[0] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(37), this.field_765, this.field_766 + 12 + 10, this.field_767, this.field_738[1] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(73), this.field_765, this.field_766 + 12 + 20, this.field_767, this.field_738[2] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(235), this.field_765, this.field_766 + 12 + 30, this.field_767, this.field_738[3] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(64), this.field_765, this.field_766 + 12 + 40, this.field_767, this.field_738[4] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(66), this.field_765, this.field_766 + 12 + 50, this.field_767, this.field_738[5] == 1, false, true);
         class_67.method_585(class_84.field_1116.method_4(241), this.field_765, this.field_766 + 12 + 60, this.field_767, this.field_738[6] == 1, false, true);
      } else if (!this.field_750
         && !this.field_748
         && !this.field_746
         && !this.field_747
         && !this.field_743
         && !this.field_745
         && !this.field_744
         && !this.field_752
         && !this.field_749) {
         class_67.method_579((int)this.field_734);
         class_67.method_597(class_67.method_580());
      }

      if (this.field_752) {
         class_67.method_593("", "");
         this.field_763.method_946();
      } else if (this.field_744) {
         class_67.method_593("", "");
         this.field_754.method_944();
      } else {
         class_67.method_593(class_84.field_1116.method_4(67), class_84.field_1116.method_4(241));
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_550(int var1) {
      if (this.field_777) {
         class_21.method_199();
         if (this.field_736 < 2300L) {
            if (var1 == 256) {
               this.field_736 = 2301L;
               class_67.method_578(!class_21.method_180().method_752());
            }
         } else if (this.field_751) {
            if ((var1 == 131072 || var1 == 16384 || var1 == 8192) && !this.field_762.method_59(131072)) {
               this.field_751 = false;
            }
         } else if (this.field_753) {
            if (var1 == 256) {
               this.field_753 = false;
               this.field_761 = null;
               class_67.method_578(!class_21.method_180().method_752());
               if (this.field_775) {
                  class_21.method_197(class_14.method_76() * class_14.method_76() * this.field_776);
                  class_14.method_77();
                  this.field_775 = false;
               }
            }
         } else {
            if (var1 == 131072) {
               if (this.field_746) {
                  this.field_762.method_58(class_84.field_1116.method_4(353));
               } else if (this.field_745) {
                  if (this.field_755.method_313() == 1) {
                     this.field_762.method_58(class_84.field_1116.method_4(355));
                  } else {
                     this.field_762.method_58(class_84.field_1116.method_4(356));
                  }
               } else if (this.field_748) {
                  if (this.field_758.method_106() == 0) {
                     this.field_762.method_58(class_84.field_1116.method_4(357));
                  } else {
                     this.field_762.method_58(class_84.field_1116.method_4(358));
                  }
               } else if (this.field_747) {
                  if (this.field_757.method_444()) {
                     this.field_762.method_58(class_84.field_1116.method_4(361));
                  } else {
                     this.field_762.method_58(class_84.field_1116.method_4(362));
                  }
               } else if (this.field_749) {
                  if (this.field_759.method_412()) {
                     this.field_762.method_58(class_84.field_1116.method_4(364));
                  } else {
                     this.field_762.method_58(class_84.field_1116.method_4(363));
                  }
               } else if (!this.field_743) {
                  this.field_762.method_58(class_84.field_1116.method_4(365));
               }

               if (!this.field_743) {
                  this.field_751 = true;
               }
            }

            if (this.field_750) {
               if (!this.field_760.method_459(var1)) {
                  if (this.field_764.field_1146 == 13 || this.field_764.field_1146 == 14) {
                     if (!this.field_764.field_1161 || this.field_764.field_1164 != 36 || class_21.method_143() == 41) {
                        class_21.method_178().method_610(this.field_764.field_1164, this.field_764.field_1165);
                     }

                     this.field_758.method_102();
                  }

                  if (this.field_764.field_1161) {
                     class_21.method_145();
                  } else {
                     class_21.method_141();
                  }

                  class_21.method_197(this.field_764.field_1150);
                  class_21.method_163(this.field_764);
                  this.field_755.method_310();
                  this.field_750 = false;
                  if (this.field_771 > 0) {
                     class_21.method_197(this.field_771);
                     this.field_771 = 0;
                  }
               }
            } else if (this.field_745) {
               if (var1 == 32 && this.field_755.method_314() && this.field_761 == null && !class_84.field_1088) {
                  this.field_761 = new class_56(class_84.field_1116.method_4(355));
                  class_84.field_1088 = true;
                  this.field_753 = true;
               }

               if (!this.field_755.method_315(var1)) {
                  this.field_745 = false;
               }
            } else if (this.field_746) {
               if (var1 == 32 && this.field_756.method_776() && this.field_761 == null && !class_84.field_1086) {
                  this.field_761 = new class_56(class_84.field_1116.method_4(354));
                  class_84.field_1086 = true;
                  this.field_753 = true;
               }

               if (!this.field_756.method_777(var1)) {
                  this.field_746 = false;
               }
            } else if (this.field_747) {
               if (!this.field_757.method_447(var1)) {
                  this.field_747 = false;
               }
            } else if (this.field_748) {
               if (var1 == 32 && this.field_758.method_107() && this.field_761 == null && !class_84.field_1092) {
                  this.field_761 = new class_56(class_84.field_1116.method_4(358));
                  class_84.field_1092 = true;
                  this.field_753 = true;
               }

               if (!this.field_758.method_103(var1)) {
                  this.field_748 = false;
               }
            } else if (this.field_749) {
               if (var1 == 32 && this.field_761 == null && !class_84.field_1094) {
                  this.field_761 = new class_56(class_84.field_1116.method_4(364));
                  class_84.field_1094 = true;
                  this.field_753 = true;
               }

               if (!this.field_759.method_411(var1)) {
                  this.field_749 = false;
               }
            } else if (this.field_752) {
               if (var1 == 256) {
                  this.method_556();
               }
            } else if (!this.field_744) {
               if (this.field_742 && !this.field_743) {
                  if (var1 == 256 && !this.field_750 && !this.field_752) {
                     switch (this.field_737) {
                        case 0:
                           this.field_746 = true;
                           if (this.field_761 == null && !class_84.field_1085) {
                              this.field_761 = new class_56(class_84.field_1116.method_4(353));
                              class_84.field_1085 = true;
                              this.field_753 = true;
                           }

                           return;
                        case 1:
                           if (class_21.method_143() < 9) {
                              this.field_761 = new class_56(class_21.method_219(class_84.field_1116.method_4(282), class_21.method_213()));
                              this.field_753 = true;
                              return;
                           }

                           if (class_21.method_143() == 42 && !class_21.method_178().method_609(42)) {
                              this.field_761 = new class_56(class_84.field_1116.method_4(289));
                              this.field_753 = true;
                              return;
                           }

                           this.field_745 = true;
                           this.field_755.method_312();
                           this.field_735 = -150L;
                           if (this.field_761 == null && !class_84.field_1087) {
                              this.field_761 = new class_56(class_84.field_1116.method_4(356));
                              class_84.field_1087 = true;
                              this.field_753 = true;
                           }

                           return;
                        case 2:
                           if (class_21.method_143() < 7) {
                              this.field_761 = new class_56(class_21.method_219(class_84.field_1116.method_4(282), class_21.method_213()));
                              this.field_753 = true;
                              return;
                           }

                           if (class_21.method_143() == 42 && !class_21.method_178().method_609(42)) {
                              this.field_761 = new class_56(class_84.field_1116.method_4(289));
                              this.field_753 = true;
                              return;
                           }

                           this.field_747 = true;
                           this.field_757.method_445(null);
                           return;
                        case 3:
                           if (!class_21.method_180().method_752()) {
                              this.field_748 = true;
                              if (this.field_761 == null && !class_84.field_1091) {
                                 this.field_761 = new class_56(class_84.field_1116.method_4(357));
                                 class_84.field_1091 = true;
                                 this.field_753 = true;
                                 return;
                              }
                           } else {
                              this.field_761 = new class_56(class_84.field_1116.method_4(256));
                              this.field_753 = true;
                           }

                           return;
                        case 4:
                           this.field_749 = true;
                           this.field_759.method_410();
                           if (this.field_761 == null && !class_84.field_1093) {
                              this.field_761 = new class_56(class_84.field_1116.method_4(363));
                              class_84.field_1093 = true;
                              this.field_753 = true;
                           }

                           return;
                        case 5:
                           this.field_743 = true;
                           this.field_741.method_427(2);
                           return;
                        case 6:
                           this.method_559();
                           return;
                     }
                  }

                  if (var1 == 64) {
                     this.field_738[this.field_737] = 0;
                     if (this.field_737 < this.field_738.length - 1) {
                        this.field_737++;
                     } else {
                        this.field_737 = 0;
                     }

                     this.field_738[this.field_737] = 1;
                  }

                  if (var1 == 2) {
                     this.field_738[this.field_737] = 0;
                     if (this.field_737 > 0) {
                        this.field_737--;
                     } else {
                        this.field_737 = this.field_738.length - 1;
                     }

                     this.field_738[this.field_737] = 1;
                  }

                  if (var1 == 16384) {
                     this.field_742 = !this.field_742;
                     return;
                  }
               }

               if (!this.field_743 && var1 == 8192) {
                  this.method_559();
               } else if (this.field_743) {
                  this.field_741.method_430(var1);
                  if (var1 == 4) {
                     this.field_741.method_422();
                  }

                  if (var1 == 32) {
                     this.field_741.method_424();
                  }

                  if (var1 == 2) {
                     this.field_741.method_420((int)this.field_734);
                  }

                  if (var1 == 64) {
                     this.field_741.method_421((int)this.field_734);
                  }

                  if (var1 == 16384) {
                     this.field_741.method_426();
                  }

                  if (var1 == 8192 && this.field_741.method_425()) {
                     this.field_743 = !this.field_743;
                     this.field_741.method_427(2);
                  }

                  if (var1 == 256 && !this.field_750 && !this.field_752) {
                     this.field_774 = false;
                     if (this.field_741.method_419()) {
                        this.field_743 = false;
                     }
                  }
               } else {
                  if (var1 == 16384) {
                     this.field_742 = !this.field_742;
                  }
               }
            } else {
               if (var1 == 4) {
                  this.field_754.method_942();
               }

               if (var1 == 32) {
                  this.field_754.method_943();
               }

               if (var1 == 256) {
                  if (this.field_754.method_941() && this.field_770) {
                     this.field_770 = false;
                     class_21.method_140();
                     class_21.method_131(class_21.method_180());
                     class_21.field_220 = -1;
                     class_21.field_218 = -1;
                     class_21.field_219 = -1;
                     class_14.method_85();
                     class_84.field_1126.method_439(class_84.field_1127[2]);
                  } else if (this.field_771 > 0) {
                     class_21.method_197(this.field_771);
                     this.field_771 = 0;
                  }

                  this.field_744 = false;
               }
            }
         }
      }
   }

   // $VF: renamed from: g () void
   private void method_559() {
      if (class_21.method_143() == 3) {
         this.field_761 = new class_56(class_84.field_1116.method_4(288));
         this.field_753 = true;
      } else if (class_21.method_143() == 42 && !class_21.method_178().method_609(42)) {
         this.field_761 = new class_56(class_84.field_1116.method_4(289));
         this.field_753 = true;
      } else {
         if (!this.field_744 && !this.field_750 && !this.field_752) {
            this.field_754.method_940(class_84.field_1116.method_4(234), true);
            this.field_754.method_942();
            this.field_744 = true;
            this.field_770 = true;
         }
      }
   }
}
