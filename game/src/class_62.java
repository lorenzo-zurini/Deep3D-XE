import javax.microedition.lcdui.Image;

// $VF: renamed from: k
public final class class_62 extends class_61 {
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_724;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_725;
   // $VF: renamed from: a boolean
   private boolean field_726;
   // $VF: renamed from: a long
   private long field_727;
   // $VF: renamed from: a int
   private int field_728;
   // $VF: renamed from: b int
   private int field_729;
   // $VF: renamed from: c int
   private int field_730;
   // $VF: renamed from: a byte[]
   private byte[] field_731;

   // $VF: renamed from: a () void
   public final void method_551() {
      try {
         this.field_724 = class_28.method_282("/data/interface/fishlabs.png");
         this.field_725 = class_28.method_282("/data/interface/abyss.png");
      } catch (Exception var2) {
         var2.printStackTrace();
      }

      this.field_726 = true;
      this.field_729 = 0;
      // Deep3D-PC: no music on/off prompt; music is on (volume lives in the
      // PC options). Same effect as confirming "Music On".
      class_84.field_1080 = true;
      class_84.field_1083 = 1;
      class_84.field_1122.method_765(100);
      class_84.field_1122.method_768(0);
      this.field_727 = System.currentTimeMillis();
      this.field_728 = 1;
   }

   // $VF: renamed from: b () void
   public final void method_552() {
      this.field_724 = null;
      this.field_725 = null;
      this.field_726 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_553() {
      return this.field_726;
   }

   // $VF: renamed from: a (int) void
   public final void method_550(int var1) {
      if (this.field_728 == 0) {
         if (var1 == 2 && this.field_729 == 1) {
            this.field_729--;
         }

         if (var1 == 64 && this.field_729 == 0) {
            this.field_729++;
         }

         if (var1 == 32768) {
            this.field_730++;
            if (this.field_730 > class_90.field_1218.length) {
               this.field_730 = 0;
            }

            this.field_731 = class_90.field_1218[this.field_730];
         }

         if (var1 == 256 || var1 == 16384) {
            class_84.field_1080 = this.field_729 == 0;
            if (this.field_729 == 1) {
               class_84.field_1083 = 3;
            } else {
               class_84.field_1083 = 1;
            }

            class_84.field_1122.method_765(100);
            class_84.field_1122.method_768(0);
            this.field_727 = System.currentTimeMillis();
            this.field_728 = 1;
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_549(int var1) {
      class_84.field_1117.setColor(class_67.field_845);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      if (this.field_728 == 0) {
         class_84.field_1117.drawImage(class_33.method_292(), class_84.field_1120 >> 1, 10, 17);
         class_67.method_584(
            class_84.field_1116.method_4(6) + " " + class_84.field_1116.method_4(14), 0, class_84.field_1121 >> 1, class_84.field_1120, this.field_729 == 0
         );
         class_67.method_584(
            class_84.field_1116.method_4(6) + " " + class_84.field_1116.method_4(15),
            0,
            (class_84.field_1121 >> 1) + class_58.method_527(),
            class_84.field_1120,
            this.field_729 == 1
         );
         class_67.method_601(class_84.field_1116.method_4(265), "", false);
         if (this.field_731 != null) {
            class_119.method_923(this.field_731, 0, 40, 0);
            class_58.method_518(class_90.field_1219[this.field_730], 40, 40, 0);
            return;
         }
      } else if (this.field_728 == 1) {
         class_84.field_1117.drawImage(this.field_724, class_84.field_1120 / 2, class_84.field_1121 / 2, 3);
         if (System.currentTimeMillis() - this.field_727 > 3000L) {
            this.field_728++;
            return;
         }
      } else if (this.field_728 == 2) {
         class_84.field_1117.drawImage(this.field_725, class_84.field_1120 / 2, class_84.field_1121 / 2, 3);
         if (System.currentTimeMillis() - this.field_727 > 6000L) {
            this.field_728++;
            return;
         }
      } else {
         class_84.field_1126.method_439(class_84.field_1127[0]);
      }
   }
}
