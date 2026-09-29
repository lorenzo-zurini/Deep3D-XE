import java.util.Random;
import javax.microedition.lcdui.game.GameCanvas;

// $VF: renamed from: de
public final class class_124 extends GameCanvas {
   // $VF: renamed from: a DeepMIDlet
   private DeepMIDlet field_1513;
   // $VF: renamed from: a int
   private int field_1514;
   // $VF: renamed from: b int
   private int field_1515;
   // $VF: renamed from: c int
   private int field_1516;
   // $VF: renamed from: d int
   private int field_1517;
   // $VF: renamed from: e int
   private int field_1518;
   // $VF: renamed from: f int
   private int field_1519;
   // $VF: renamed from: a bq
   private class_54 field_1520 = null;
   // $VF: renamed from: a cs
   private class_33 field_1521;
   // $VF: renamed from: a boolean
   public boolean field_1522;
   // $VF: renamed from: b boolean
   public boolean field_1523 = true;
   // $VF: renamed from: c boolean
   public boolean field_1524 = false;

   public class_124(DeepMIDlet var1) {
      super(false);
      this.field_1513 = var1;
      this.field_1522 = false;
      class_84.field_1112 = var1.getDisplay();
      class_84.field_1123 = new Random();

      try {
         class_84.field_1124 = "v " + var1.getAppProperty("MIDlet-Version");
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_947() {
      if (this.field_1520.field_595 == class_84.field_1127[2]) {
         ((class_64)class_84.field_1127[2]).method_567();
      }

      class_84.field_1122.method_771();
      class_84.field_1125 = true;
   }

   // $VF: renamed from: b () void
   public final void method_948() {
      if (class_84.field_1122 != null && class_84.field_1080) {
         class_84.field_1122.method_772();
      }

      class_84.field_1125 = false;
   }

   public final void hideNotify() {
      if (!this.field_1522) {
         this.field_1513.pause();
      }
   }

   // $VF: renamed from: c () void
   public final synchronized void method_949() {
      if (this.field_1523) {
         this.field_1523 = false;
         class_84.field_1120 = this.getWidth();
         class_84.field_1121 = this.getHeight();
         this.setFullScreenMode(true);
         this.flushGraphics();
         class_84.field_1120 = this.getWidth();
         class_84.field_1121 = this.getHeight();
         this.setFullScreenMode(true);
      } else if (!this.field_1524) {
         this.field_1524 = true;
         class_84.field_1117 = this.getGraphics();
         class_84.field_1120 = this.getWidth();
         class_84.field_1121 = this.getHeight();
         class_84.field_1116 = new class_1();
         class_84.field_1116.method_2(class_84.field_1084);
         class_84.field_1120 = this.getWidth();
         class_84.field_1121 = this.getHeight();
         this.setFullScreenMode(true);
         class_58.method_514(class_84.field_1117);
         class_58.method_515("/data/interface/font_deep_white.png");
         class_58.method_525(-1);
         class_58.method_529(11);
         class_58.method_515("/data/interface/font_deep_white.png");
         class_58.method_526(-1, 1);
         class_58.method_531(11, 1);
         class_58.method_522(192, 192, 192, 0, 1);
         class_84.field_1118 = this;
         class_67.method_576();
         this.field_1521 = new class_33();
         this.field_1521.field_332 = this;
         this.field_1521.method_296(true);
         class_84.field_1113 = this.field_1521;
         class_84.method_737();
         class_27.method_274();
         class_84.field_1080 = false;
         class_84.field_1111 = class_71.method_686();
         class_84.field_1110 = new class_4(class_84.field_1111);
         class_84.field_1110.method_29();
         class_84.field_1110.method_29();
         class_84.field_1110.method_29();
         class_84.field_1122 = new class_88();
         class_90.method_792();
         class_90.method_780();
         class_90.method_784();
         class_90.method_786();
         class_21.method_198(15000);
         class_90.method_782();
         this.field_1520 = new class_54(this.field_1513, this.field_1521);
         class_84.field_1126 = this.field_1520;
         class_84.field_1127 = new class_61[4];
         class_84.field_1127[3] = new class_62();
         class_84.field_1127[0] = new class_66();
         class_84.field_1127[1] = new class_63();
         class_84.field_1127[2] = new class_64();
         Deep3dDebug.install(); // Deep3D-PC
         class_21.method_221();
         this.field_1520.method_439(class_84.field_1127[3]);
      } else {
         Deep3dDebug.tick(); // Deep3D-PC: debug teleport, between frames
         class_67.method_596();
         this.field_1520.method_442(this.field_1514);
         if (this.field_1518 == 16384) {
            class_67.method_594(true);
            this.field_1519 = this.field_1518;
         } else if (this.field_1518 == 8192) {
            class_67.method_594(false);
            this.field_1519 = this.field_1518;
         }

         if (class_67.method_595()) {
            this.field_1520.method_441(this.field_1519);
            this.field_1519 = -1;
         }

         if (this.field_1518 != -1 && this.field_1519 == -1) {
            this.field_1520.method_441(this.field_1518);
         }

         this.field_1518 = -1;
         this.field_1517 = -1;
         this.flushGraphics();
      }
   }

   // $VF: renamed from: d () void
   public final void method_950() {
      this.field_1520.field_595.method_552();
      class_90.method_793();
      class_67.method_574();
      class_58.method_513();
      class_84.field_1122.method_766();
      class_43.method_382();
      this.field_1521.method_295();
      this.field_1521 = null;
   }

   // $VF: renamed from: e () void
   public final void method_951() {
      org.deep3d.GameUi.controls(org.deep3d.GameUi.DIALOG, org.deep3d.GameUi.FIRE, org.deep3d.GameUi.FIRE, org.deep3d.GameUi.NONE); // Deep3D-PC: any of them resumes
      class_84.field_1117.setColor(class_67.field_845);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      class_58.method_519(
         class_58.method_532(class_84.field_1116.method_4(83), class_84.field_1120 - 10), class_84.field_1120 >> 1, class_84.field_1121 >> 1, 0, 3
      );
      if (this.field_1518 == 256) {
         this.field_1513.resume();
         this.field_1518 = 0;
         this.field_1517 = 0;
         this.field_1515 = 0;
         this.field_1516 = 0;
         this.field_1514 = 0;
      }

      this.flushGraphics();
   }

   // $VF: renamed from: f () void
   public final synchronized void method_952() {
      this.field_1514 = this.field_1515;
   }

   public final void keyPressed(int var1) {
      this.field_1516 = this.field_1515;
      if (var1 == -7) {
         this.field_1515 |= 8192;
      }

      if (var1 == -6) {
         this.field_1515 |= 16384;
      }

      if (var1 == 49 || var1 == 101 || var1 == 114) {
         this.field_1515 |= 32768;
      }

      if (var1 == 51 || var1 == 105 || var1 == 117) {
         this.field_1515 |= 65536;
      }

      if (var1 == 48 || var1 == 32) {
         this.field_1515 |= 131072;
      }

      if (var1 == -11) {
         this.field_1515 |= 262144;
      }

      if (var1 == -8) {
         this.field_1515 |= 524288;
      }

      if (var1 == -1 || var1 == 50 || var1 == 121 || var1 == 116) {
         this.field_1515 |= 2;
      }

      if (var1 == -2 || var1 == 56 || var1 == 98 || var1 == 118) {
         this.field_1515 |= 64;
      }

      if (var1 == -3 || var1 == 52 || var1 == 100 || var1 == 102) {
         this.field_1515 |= 4;
      }

      if (var1 == -4 || var1 == 54 || var1 == 106 || var1 == 107) {
         this.field_1515 |= 32;
      }

      if (var1 == -5 || var1 == 53 || var1 == 103 || var1 == 104) {
         this.field_1515 |= 256;
      }

      if (var1 == 55 || var1 == 99 || var1 == 120) {
         this.field_1515 |= 512;
      }

      if (var1 == 57 || var1 == 109 || var1 == 110) {
         this.field_1515 |= 1024;
      }

      if (var1 == 42) {
         this.field_1515 |= 2048;
      }

      if (var1 == 35) {
         this.field_1515 |= 4096;
      }

      this.field_1518 = this.field_1515 & ~this.field_1516;
   }

   public final void keyRepeated(int var1) {
      this.keyPressed(var1);
   }

   public final void keyReleased(int var1) {
      this.field_1516 = this.field_1515;
      if (var1 == -7) {
         this.field_1515 &= -8193;
      }

      if (var1 == -6) {
         this.field_1515 &= -16385;
      }

      if (var1 == 49 || var1 == 101 || var1 == 114) {
         this.field_1515 &= -32769;
      }

      if (var1 == 51 || var1 == 105 || var1 == 117) {
         this.field_1515 &= -65537;
      }

      if (var1 == 48 || var1 == 32) {
         this.field_1515 &= -131073;
      }

      if (var1 == -11) {
         this.field_1515 &= -262145;
      }

      if (var1 == -8) {
         this.field_1515 &= -524289;
      }

      if (var1 == -1 || var1 == 50 || var1 == 121 || var1 == 116) {
         this.field_1515 &= -3;
      }

      if (var1 == -2 || var1 == 56 || var1 == 98 || var1 == 118) {
         this.field_1515 &= -65;
      }

      if (var1 == -3 || var1 == 52 || var1 == 100 || var1 == 102) {
         this.field_1515 &= -5;
      }

      if (var1 == -4 || var1 == 54 || var1 == 106 || var1 == 107) {
         this.field_1515 &= -33;
      }

      if (var1 == -5 || var1 == 53 || var1 == 103 || var1 == 104) {
         this.field_1515 &= -257;
      }

      if (var1 == 55 || var1 == 99 || var1 == 120) {
         this.field_1515 &= -513;
      }

      if (var1 == 57 || var1 == 109 || var1 == 110) {
         this.field_1515 &= -1025;
      }

      if (var1 == 42) {
         this.field_1515 &= -2049;
      }

      if (var1 == 35) {
         this.field_1515 &= -4097;
      }

      this.field_1517 = ~this.field_1515 & this.field_1516;
   }
}
