import javax.microedition.lcdui.Image;

// $VF: renamed from: cb
public final class class_47 {
   // $VF: renamed from: e int
   private static int field_639;
   // $VF: renamed from: f int
   private static int field_640;
   // $VF: renamed from: g int
   private static int field_641;
   // $VF: renamed from: h int
   private static int field_642;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_643;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_644;
   // $VF: renamed from: c javax.microedition.lcdui.Image
   private Image field_645;
   // $VF: renamed from: d javax.microedition.lcdui.Image
   private Image field_646;
   // $VF: renamed from: e javax.microedition.lcdui.Image
   private Image field_647;
   // $VF: renamed from: f javax.microedition.lcdui.Image
   private Image field_648;
   // $VF: renamed from: g javax.microedition.lcdui.Image
   private Image field_649;
   // $VF: renamed from: h javax.microedition.lcdui.Image
   private Image field_650;
   // $VF: renamed from: i javax.microedition.lcdui.Image
   private Image field_651;
   // $VF: renamed from: j javax.microedition.lcdui.Image
   private Image field_652;
   // $VF: renamed from: k javax.microedition.lcdui.Image
   private Image field_653;
   // $VF: renamed from: l javax.microedition.lcdui.Image
   private Image field_654;
   // $VF: renamed from: m javax.microedition.lcdui.Image
   private Image field_655;
   // $VF: renamed from: n javax.microedition.lcdui.Image
   private Image field_656;
   // $VF: renamed from: o javax.microedition.lcdui.Image
   private Image field_657;
   // $VF: renamed from: p javax.microedition.lcdui.Image
   private Image field_658;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_659;
   // $VF: renamed from: b javax.microedition.lcdui.Image[]
   private Image[] field_660;
   // $VF: renamed from: q javax.microedition.lcdui.Image
   private Image field_661;
   // $VF: renamed from: a int
   public int field_662;
   // $VF: renamed from: b int
   public int field_663;
   // $VF: renamed from: c int
   public int field_664;
   // $VF: renamed from: d int
   public int field_665;
   // $VF: renamed from: a boolean
   public boolean field_666;
   // $VF: renamed from: b boolean
   public boolean field_667;
   // $VF: renamed from: c boolean
   public boolean field_668;
   // $VF: renamed from: d boolean
   public boolean field_669;
   // $VF: renamed from: e boolean
   public boolean field_670;
   // $VF: renamed from: a aw[]
   public class_83[] field_671;
   // $VF: renamed from: b aw[]
   public class_83[] field_672;
   // $VF: renamed from: c aw[]
   public class_83[] field_673;
   // $VF: renamed from: d aw[]
   public class_83[] field_674;
   // $VF: renamed from: a dr
   public class_13 field_675;
   // $VF: renamed from: a cy
   public class_57 field_676;
   // $VF: renamed from: a bn
   private class_1 field_677 = new class_1();
   // $VF: renamed from: a v
   private class_5 field_678 = new class_5();
   // $VF: renamed from: b v
   private class_5 field_679 = new class_5();
   // $VF: renamed from: c v
   private class_5 field_680 = new class_5();
   // $VF: renamed from: d v
   private class_5 field_681 = new class_5();
   // $VF: renamed from: a p
   private class_55 field_682 = new class_55();
   // $VF: renamed from: i int
   private int field_683;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_684 = new String[3];
   // $VF: renamed from: j int
   private int field_685;
   // $VF: renamed from: a java.lang.String
   private String field_686;
   // $VF: renamed from: r javax.microedition.lcdui.Image
   private Image field_687;
   // $VF: renamed from: s javax.microedition.lcdui.Image
   private Image field_688;

   public class_47(class_57 var1) {
      this.field_676 = var1;
      this.field_664 = class_41.field_537 / 2;
      this.field_665 = class_41.field_538 / 2;
      field_639 = class_41.field_537 / 3;
      field_640 = class_41.field_537 - field_639;
      field_641 = class_41.field_538 / 2 - (class_41.field_537 / 2 - field_639);
      field_642 = class_41.field_538 / 2 + (class_41.field_537 / 2 - field_639);
      this.field_684[0] = class_3.method_110().field_827;
      this.field_684[1] = "S.T.R.E.A.M. OUT";
      this.field_684[2] = "";

      try {
         this.field_643 = class_40.method_412("/data/interface/bracket_enemy_in.png");
         this.field_644 = class_40.method_412("/data/interface/bracket_enemy_out.png");
         this.field_645 = class_40.method_412("/data/interface/bracket_friend_in.png");
         this.field_646 = class_40.method_412("/data/interface/bracket_friend_out.png");
         this.field_647 = class_40.method_412("/data/interface/bracket_waypoint_in.png");
         this.field_648 = class_40.method_412("/data/interface/bracket_waypoint_out.png");
         this.field_652 = class_40.method_412("/data/interface/bracket_landmark_out.png");
         this.field_651 = class_40.method_412("/data/interface/bracket_landmark_in.png");
         this.field_654 = class_40.method_412("/data/interface/bracket_creature_out.png");
         this.field_653 = class_40.method_412("/data/interface/bracket_creature_in.png");
         this.field_649 = class_40.method_412("/data/interface/bracket_enemy_far.png");
         this.field_650 = class_40.method_412("/data/interface/bracket_friend_far.png");
         this.field_657 = class_40.method_412("/data/interface/bracket_box.png");
         this.field_658 = class_40.method_412("/data/interface/crate.png");
         this.field_661 = class_40.method_412("/data/interface/cargo_18.png");
         this.field_655 = class_40.method_412("/data/interface/radar_logo_0.png");
         this.field_656 = class_40.method_412("/data/interface/radar_logo_1.png");
         String var2 = class_58.method_565() ? "go" : (class_3.method_108().field_443 ? "g" : "b");
         this.field_687 = class_40.method_412("/data/interface/c_" + var2 + "_s.png");
         this.field_688 = class_40.method_412("/data/interface/c_" + var2 + "_f.png");
         this.field_685 = class_3.method_108().field_435;
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_457() {
      this.field_671 = null;
      this.field_672 = null;
      this.field_673 = null;
      this.field_675 = null;
      this.field_676 = null;
      this.field_680 = null;
      this.field_681 = null;
      this.field_678 = null;
   }

   // $VF: renamed from: a (am, aw) void
   public final void method_458(class_111 var1, class_83 var2) {
      this.field_679 = var2.method_746(this.field_679);
      this.field_678 = var1.method_867(this.field_677).method_39(this.field_679, this.field_678);
      this.field_678.field_139 = -this.field_678.field_139;
      this.field_678.field_140 = -this.field_678.field_140;
      var1.method_897(this.field_679);
      this.field_662 = this.field_679.field_138;
      this.field_663 = this.field_679.field_139;
      float var3 = this.field_662 > class_41.field_537
         ? (float)(this.field_665 - this.field_663) / (this.field_662 - this.field_664)
         : (float)(this.field_665 - this.field_663) / (this.field_664 - this.field_662);
      float var4 = this.field_663 > class_41.field_538
         ? (float)(this.field_664 - this.field_662) / (this.field_663 - this.field_665)
         : (float)(this.field_664 - this.field_662) / (this.field_665 - this.field_663);
      if (this.field_678.field_140 < 0) {
         if (this.field_662 < this.field_664) {
            this.field_662 = -1;
         } else {
            this.field_662 = class_41.field_537 + 1;
         }

         if (this.field_663 < this.field_665) {
            this.field_663 = -1;
         } else {
            this.field_663 = class_41.field_538 + 1;
         }
      }

      this.field_666 = this.field_662 <= class_41.field_537 && this.field_662 >= 0 && this.field_663 <= class_41.field_538 && this.field_663 >= 0;
      this.field_667 = this.field_668 = this.field_669 = this.field_670 = false;
      if (this.field_662 > class_41.field_537) {
         this.field_662 = class_41.field_537 - 14;
         this.field_663 = this.field_665 - (int)(var3 * (this.field_662 - this.field_664));
         this.field_668 = true;
      } else if (this.field_662 < 0) {
         this.field_662 = 14;
         this.field_663 = this.field_665 + (int)(var3 * (this.field_662 - this.field_664));
         this.field_667 = true;
      }

      if (this.field_663 > class_41.field_538) {
         this.field_663 = 33 + class_4.field_66;
         this.field_662 = this.field_664 - (int)(var4 * (this.field_663 - this.field_665));
         this.field_670 = true;
      } else if (this.field_663 < 0) {
         this.field_663 = 33;
         this.field_662 = this.field_664 + (int)(var4 * (this.field_663 - this.field_665));
         this.field_669 = true;
      }

      if (this.field_662 > 14 + class_4.field_65) {
         this.field_662 = 14 + class_4.field_65;
      } else if (this.field_662 < 14) {
         this.field_662 = 14;
      }

      if (this.field_663 > 33 + class_4.field_66) {
         this.field_663 = 33 + class_4.field_66;
      } else {
         if (this.field_663 < 33) {
            this.field_663 = 33;
         }
      }
   }

   // $VF: renamed from: a (cm, am) void
   public final void method_459(class_96 var1, class_111 var2) {
      this.field_671 = this.field_676.field_775;
      this.field_672 = this.field_676.field_776;
      this.field_673 = this.field_676.field_778;
      this.field_675 = this.field_676.field_779;
      this.field_674 = this.field_676.field_777;
      boolean var3 = false;
      if ((this.field_685 == 2 || this.field_685 == 4) && this.field_659 == null && this.field_671 != null) {
         this.field_659 = new Image[this.field_671.length];

         for (int var4 = 0; var4 < this.field_671.length; var4++) {
            if (this.field_671[var4].field_1116) {
               class_46 var5 = this.field_671[var4].field_1117;
               if (this.field_671[var4].field_1117 != null) {
                  this.field_659[var4] = class_40.method_412("/data/interface/cargo_" + this.field_671[var4].field_1117.field_626 + ".png");
               } else if (class_3.method_62().field_1226 == 2) {
                  this.field_659[var4] = class_40.method_412("/data/interface/cargo_salvage.png");
               } else {
                  this.field_659[var4] = class_40.method_412("/data/interface/cargo_recovery.png");
               }
            }
         }
      }

      if ((this.field_685 == 3 || this.field_685 == 4) && this.field_660 == null && this.field_674 != null) {
         this.field_660 = new Image[this.field_674.length];

         for (int var9 = 0; var9 < this.field_674.length; var9++) {
            this.field_660[var9] = class_40.method_412("/data/interface/cargo_" + ((class_89)this.field_674[var9]).field_1171.field_857 + ".png");
         }
      }

      if (this.field_685 > 0) {
         class_41.field_534.setColor(class_69.field_1004);
         class_41.field_534.drawLine(14, 33, 14, 45);
         class_41.field_534.drawLine(14, 33, 26, 33);
         class_41.field_534.drawLine(14, 33 + class_4.field_66, 26, 33 + class_4.field_66);
         class_41.field_534.drawLine(14, 33 + class_4.field_66, 14, 33 + class_4.field_66 - 12);
         class_41.field_534.drawLine(14 + class_4.field_65, 33, 14 + class_4.field_65 - 12, 33);
         class_41.field_534.drawLine(14 + class_4.field_65, 33, 14 + class_4.field_65, 45);
         class_41.field_534.drawLine(14 + class_4.field_65, 33 + class_4.field_66, 14 + class_4.field_65 - 12, 33 + class_4.field_66);
         class_41.field_534.drawLine(14 + class_4.field_65, 33 + class_4.field_66, 14 + class_4.field_65, 33 + class_4.field_66 - 12);
         class_41.field_534.setColor(class_69.field_1003);

         for (int var10 = 0; var10 < 2; var10++) {
            int var14;
            if ((var14 = var10 == 0 ? class_58.method_569() : class_58.method_574()) != 0) {
               class_41.field_534.drawImage(var10 == 0 ? this.field_687 : this.field_688, var10 == 0 ? 16 : 14 + class_4.field_65 - 3 - 40, 35, 0);
               int var6 = var10 == 0 ? 28 : 14 + class_4.field_65 - 30;
               byte var7 = 36;

               for (int var8 = 0; var8 < var14; var8++) {
                  if ((var8 + 1) % 5 == 0) {
                     class_41.field_534.drawLine(var6 - 9, var7 + 5, var6 - 1, var7);
                  } else {
                     class_41.field_534.drawLine(var6, var7, var6, var7 + 5);
                  }

                  var6 += 2;
                  if (var6 > (var10 == 0 ? 56 : 14 + class_4.field_65 - 2)) {
                     var6 = var10 == 0 ? 18 : 14 + class_4.field_65 - 40;
                     var7 += 8;
                  }
               }
            }
         }

         if (this.field_672 != null) {
            for (int var11 = 0; var11 < this.field_672.length; var11++) {
               if (this.field_672[var11].field_1102.field_1268 && !this.field_672[var11].method_748()) {
                  this.method_458(var2, this.field_672[var11]);
                  if (this.field_666) {
                     this.field_680 = var1.method_823(this.field_680);
                     this.field_681 = this.field_672[var11].field_1102.method_823(this.field_681);
                     if (this.field_680.field_138 - this.field_681.field_138 <= 24000
                        && this.field_680.field_138 - this.field_681.field_138 >= -24000
                        && this.field_680.field_139 - this.field_681.field_139 <= 24000
                        && this.field_680.field_139 - this.field_681.field_139 >= -24000
                        && this.field_680.field_140 - this.field_681.field_140 <= 24000
                        && this.field_680.field_140 - this.field_681.field_140 >= -24000) {
                        class_41.field_534.drawImage(this.field_645, this.field_662, this.field_663, 3);
                        this.field_683 = (int)(this.field_672[var11].field_1102.field_1263 / 100.0F * 16.0F);
                        class_41.field_534.setColor(-13319376);
                        class_41.field_534.fillRect(this.field_662 + 10, this.field_663 + 10 - 2 - this.field_683, 2, this.field_683);
                     } else {
                        class_41.field_534.drawImage(this.field_650, this.field_662, this.field_663, 3);
                     }
                  } else {
                     class_41.field_534.drawImage(this.field_646, this.field_662, this.field_663, 3);
                  }
               }
            }
         }
      }

      if (this.field_673 != null) {
         for (int var12 = 0; var12 < this.field_673.length; var12++) {
            if (this.field_673[var12] != null) {
               this.method_458(var2, this.field_673[var12]);
               if (this.field_666) {
                  this.field_680 = var1.method_823(this.field_680);
                  this.field_681 = this.field_673[var12].field_1102.method_823(this.field_681);
                  class_41.field_534.drawImage(this.field_651, this.field_662, this.field_663, 3);
                  if (var12 == 0) {
                     class_41.field_534
                        .drawImage(class_3.method_110().method_592() ? this.field_656 : this.field_655, this.field_662 + 5, this.field_663 + 2, 0);
                  }

                  class_50.method_485(this.field_684[var12], var12 == 0 ? this.field_662 + 25 : this.field_662 + 5, this.field_663, 0);
                  if (var12 < 2) {
                     this.field_686 = this.method_460(
                        this.field_673[var12].field_1111, this.field_673[var12].field_1112, this.field_673[var12].field_1113, var1
                     );
                     class_50.method_485(this.field_686, var12 == 0 ? this.field_662 + 25 : this.field_662 + 5, this.field_663 + 10, 1);
                  }
               }
            }
         }
      }

      if (this.field_675 != null && this.field_675.method_219() != null) {
         this.method_458(var2, this.field_675.method_219());
         this.field_686 = this.method_460(
            this.field_675.method_219().field_1161, this.field_675.method_219().field_1162, this.field_675.method_219().field_1163, var1
         );
         if (this.field_666) {
            class_41.field_534.drawImage(this.field_647, this.field_662, this.field_663, 3);
            class_50.method_485(this.field_686, this.field_662 - 10, this.field_663 + 10, 1);
         } else if (this.field_685 > 0) {
            class_41.field_534.drawImage(this.field_648, this.field_662, this.field_663, 3);
         }
      }

      boolean var13 = class_3.method_62().field_1226 == 6;
      if (this.field_674 != null) {
         for (int var15 = 0; var15 < this.field_674.length; var15++) {
            if (!((class_89)this.field_674[var15]).field_1185 && (!this.field_674[var15].method_747() || ((class_89)this.field_674[var15]).field_1192)) {
               this.method_458(var2, this.field_674[var15]);
               if (this.field_666) {
                  this.field_680 = var1.method_823(this.field_680);
                  this.field_681 = this.field_674[var15].field_1102.method_823(this.field_681);
                  if (var13) {
                     class_41.field_534.drawImage(this.field_653, this.field_662, this.field_663, 3);
                  }

                  if ((this.field_685 == 3 || this.field_685 == 4)
                     && this.field_660[var15] != null
                     && this.field_662 > field_639
                     && this.field_662 < field_640
                     && this.field_663 > field_641
                     && this.field_663 < field_642) {
                     class_41.field_534
                        .drawImage(
                           ((class_89)this.field_674[var15]).field_1192 ? this.field_661 : this.field_660[var15], this.field_662 - 20, this.field_663 + 10, 0
                        );
                     class_50.method_485(((class_89)this.field_674[var15]).field_1191 + "t", this.field_662 - 20 + 20, this.field_663 + 10 + 3, 0);
                  }
               } else if (this.field_685 > 0 && var13) {
                  class_41.field_534.drawImage(this.field_654, this.field_662, this.field_663, 3);
               }
            }
         }
      }

      if (this.field_685 > 0 && this.field_671 != null) {
         for (int var16 = 0; var16 < this.field_671.length; var16++) {
            class_83 var17;
            if ((var17 = this.field_671[var16]).field_1102.field_1268 && (!var17.method_748() || var17.field_1116)) {
               this.method_458(var2, var17);
               boolean var18 = var17.field_1116 && (var17.method_747() || var17.method_748());
               if (this.field_666) {
                  this.field_680 = var1.method_823(this.field_680);
                  this.field_681 = var17.field_1102.method_823(this.field_681);
                  if (this.field_680.field_138 - this.field_681.field_138 <= 24000
                     && this.field_680.field_138 - this.field_681.field_138 >= -24000
                     && this.field_680.field_139 - this.field_681.field_139 <= 24000
                     && this.field_680.field_139 - this.field_681.field_139 >= -24000
                     && this.field_680.field_140 - this.field_681.field_140 <= 24000
                     && this.field_680.field_140 - this.field_681.field_140 >= -24000
                     && var17.field_1104 != 13
                     && var17.field_1104 != 9996) {
                     class_41.field_534.drawImage(var18 ? this.field_657 : this.field_643, this.field_662, this.field_663, 3);
                     this.field_683 = (int)(var17.field_1102.field_1263 / 100.0F * 16.0F);
                     class_41.field_534.setColor(-1047803);
                     class_41.field_534.fillRect(this.field_662 + 10, this.field_663 + 10 - 2 - this.field_683, 2, this.field_683);
                     if ((this.field_685 == 2 || this.field_685 == 4)
                        && this.field_659[var16] != null
                        && this.field_662 > field_639
                        && this.field_662 < field_640
                        && this.field_663 > field_641
                        && this.field_663 < field_642) {
                        class_41.field_534.drawImage(this.field_659[var16], this.field_662 - 20, this.field_663 + 10, 0);
                     }
                  } else {
                     class_41.field_534.drawImage(var18 ? this.field_657 : this.field_649, this.field_662, this.field_663, 3);
                  }
               } else {
                  class_41.field_534.drawImage(this.field_644, this.field_662, this.field_663, 3);
                  if (var18) {
                     class_41.field_534.drawImage(this.field_652, this.field_662, this.field_663, 3);
                     class_41.field_534
                        .drawImage(
                           this.field_658,
                           this.field_667 && !this.field_669 && !this.field_670
                              ? this.field_662 + 11
                              : (this.field_668 && !this.field_669 && !this.field_670 ? this.field_662 - 11 : this.field_662),
                           this.field_669 ? this.field_663 + 11 : (this.field_670 ? this.field_663 - 11 : this.field_663),
                           3
                        );
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: a (int, int, int, cm) java.lang.String
   private String method_460(int var1, int var2, int var3, class_96 var4) {
      this.field_680 = var4.method_823(this.field_680);
      this.field_682.field_748 = this.field_680.field_138 >> 1;
      this.field_682.field_749 = this.field_680.field_139 >> 1;
      this.field_682.field_750 = this.field_680.field_140 >> 1;
      int var5 = var1 >> 1;
      int var6 = var2 >> 1;
      int var7 = var3 >> 1;
      int var8 = (int)method_461(
            (
                  (this.field_682.field_748 - var5) * (this.field_682.field_748 - var5)
                     + (this.field_682.field_749 - var6) * (this.field_682.field_749 - var6)
                     + (this.field_682.field_750 - var7) * (this.field_682.field_750 - var7)
               )
               / 4096.0F
         )
         * 12;
      String var9 = var8 + "m";
      if (var8 >= 1000) {
         int var10;
         if ((var10 = var8 % 1000) >= 100) {
            var9 = "" + var10;
         } else {
            var9 = "0";
         }

         var9 = var9.substring(0, 1);
         var9 = var8 / 1000 + "." + var9 + "km";
      }

      return var9;
   }

   // $VF: renamed from: a (float) float
   public static final float method_461(float var0) {
      float var1 = 65536.0F;
      float var2 = 65536.0F;

      for (int var4 = 0; var4 < 20; var4++) {
         var1 *= 0.5F;
         float var3;
         if ((var3 = var0 - var2 * var2) > 0.0F) {
            var2 += var1;
         } else if (var3 < 0.0F) {
            var2 -= var1;
         }
      }

      return var2;
   }
}
