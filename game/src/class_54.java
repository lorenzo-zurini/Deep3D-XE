import java.util.Random;
import javax.microedition.lcdui.game.GameCanvas;

// $VF: renamed from: dd
public final class class_54 extends GameCanvas {
   // $VF: renamed from: a DeepMIDlet
   private DeepMIDlet field_736;
   // $VF: renamed from: a int
   private int field_737;
   // $VF: renamed from: b int
   private int field_738;
   // $VF: renamed from: c int
   private int field_739;
   // $VF: renamed from: d int
   private int field_740;
   // $VF: renamed from: e int
   private int field_741;
   // $VF: renamed from: f int
   private int field_742;
   // $VF: renamed from: a bq
   private class_12 field_743 = null;
   // $VF: renamed from: a cr
   private class_94 field_744;
   // $VF: renamed from: a boolean
   public boolean field_745;
   // $VF: renamed from: b boolean
   public boolean field_746 = true;
   // $VF: renamed from: c boolean
   public boolean field_747 = false;

   public class_54(DeepMIDlet var1) {
      super(false);
      this.field_736 = var1;
      this.field_745 = false;
      class_41.field_529 = var1.getDisplay();
      class_41.field_540 = new Random();

      try {
         class_41.field_541 = "v " + var1.getAppProperty("MIDlet-Version");
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () void
   public final void method_519() {
      if (this.field_743.field_179 == class_41.field_544[2]) {
         ((class_116)class_41.field_544[2]).method_913();
      }

      class_41.field_539.method_428();
      class_41.field_542 = true;
   }

   // $VF: renamed from: b () void
   public final void method_520() {
      if (class_41.field_539 != null && class_41.field_497) {
         class_41.field_539.method_429();
      }

      class_41.field_542 = false;
   }

   public final void hideNotify() {
      if (!this.field_745) {
         this.field_736.pause();
      }
   }

   // $VF: renamed from: c () void
   public final synchronized void method_521() {
      if (this.field_746) {
         this.field_746 = false;
         class_41.field_537 = this.getWidth();
         class_41.field_538 = this.getHeight();
         this.setFullScreenMode(true);
         this.flushGraphics();
         class_41.field_537 = this.getWidth();
         class_41.field_538 = this.getHeight();
         this.setFullScreenMode(true);
      } else if (!this.field_747) {
         this.field_747 = true;
         class_41.field_534 = this.getGraphics();
         class_41.field_537 = this.getWidth();
         class_41.field_538 = this.getHeight();
         class_41.field_533 = new class_22();
         class_41.field_533.method_295(class_41.field_501);
         class_41.field_537 = this.getWidth();
         class_41.field_538 = this.getHeight();
         this.setFullScreenMode(true);
         class_50.method_481(class_41.field_534);
         class_50.method_482("/data/interface/font_deep_white.png");
         class_50.method_492(-1);
         class_50.method_496(11);
         class_50.method_482("/data/interface/font_deep_white.png");
         class_50.method_493(-1, 1);
         class_50.method_498(11, 1);
         class_50.method_489(192, 192, 192, 0, 1);
         class_41.field_535 = this;
         class_69.method_652();
         this.field_744 = new class_94();
         this.field_744.field_1215 = this;
         this.field_744.method_788(true);
         class_41.field_530 = this.field_744;
         class_41.method_416();
         class_81.method_730();
         class_41.field_497 = false;
         class_41.field_528 = class_26.method_336();
         class_41.field_527 = new class_17(class_41.field_528);
         class_41.field_527.method_269();
         class_41.field_527.method_269();
         class_41.field_527.method_269();
         class_41.field_539 = new class_43();
         class_24.method_322();
         class_24.method_310();
         class_24.method_314();
         class_24.method_316();
         class_3.method_128(15000);
         class_24.method_312();
         this.field_743 = new class_12(this.field_736, this.field_744);
         class_41.field_543 = this.field_743;
         class_41.field_544 = new class_113[4];
         class_41.field_544[3] = new class_114();
         class_41.field_544[0] = new class_115();
         class_41.field_544[1] = new class_118();
         class_41.field_544[2] = new class_116();
         class_3.method_151();
         this.field_743.method_213(class_41.field_544[3]);
      } else {
         class_69.method_672();
         this.field_743.method_216(this.field_737);
         if (this.field_741 == 16384) {
            class_69.method_670(true);
            this.field_742 = this.field_741;
         } else if (this.field_741 == 8192) {
            class_69.method_670(false);
            this.field_742 = this.field_741;
         }

         if (class_69.method_671()) {
            this.field_743.method_215(this.field_742);
            this.field_742 = -1;
         }

         if (this.field_741 != -1 && this.field_742 == -1) {
            this.field_743.method_215(this.field_741);
         }

         this.field_741 = -1;
         this.field_740 = -1;
         this.flushGraphics();
      }
   }

   // $VF: renamed from: d () void
   public final void method_522() {
      this.field_743.field_179.method_903();
      class_24.method_323();
      class_69.method_650();
      class_50.method_480();
      class_41.field_539.method_423();
      class_25.method_329();
      this.field_744.method_787();
      this.field_744 = null;
   }

   // $VF: renamed from: e () void
   public final void method_523() {
      class_41.field_534.setColor(class_69.field_1004);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      class_50.method_486(
         class_50.method_499(class_41.field_533.method_297(83), class_41.field_537 - 10), class_41.field_537 >> 1, class_41.field_538 >> 1, 0, 3
      );
      if (this.field_741 == 256) {
         this.field_736.resume();
         this.field_741 = 0;
         this.field_740 = 0;
         this.field_738 = 0;
         this.field_739 = 0;
         this.field_737 = 0;
      }

      this.flushGraphics();
   }

   // $VF: renamed from: f () void
   public final synchronized void method_524() {
      this.field_737 = this.field_738;
   }

   public final void keyPressed(int var1) {
      this.field_739 = this.field_738;
      if (var1 == -7) {
         this.field_738 |= 8192;
      }

      if (var1 == -6) {
         this.field_738 |= 16384;
      }

      if (var1 == 49 || var1 == 101 || var1 == 114) {
         this.field_738 |= 32768;
      }

      if (var1 == 51 || var1 == 105 || var1 == 117) {
         this.field_738 |= 65536;
      }

      if (var1 == 48 || var1 == 32) {
         this.field_738 |= 131072;
      }

      if (var1 == -11) {
         this.field_738 |= 262144;
      }

      if (var1 == -8) {
         this.field_738 |= 524288;
      }

      if (var1 == -1 || var1 == 50 || var1 == 121 || var1 == 116) {
         this.field_738 |= 2;
      }

      if (var1 == -2 || var1 == 56 || var1 == 98 || var1 == 118) {
         this.field_738 |= 64;
      }

      if (var1 == -3 || var1 == 52 || var1 == 100 || var1 == 102) {
         this.field_738 |= 4;
      }

      if (var1 == -4 || var1 == 54 || var1 == 106 || var1 == 107) {
         this.field_738 |= 32;
      }

      if (var1 == -5 || var1 == 53 || var1 == 103 || var1 == 104) {
         this.field_738 |= 256;
      }

      if (var1 == 55 || var1 == 99 || var1 == 120) {
         this.field_738 |= 512;
      }

      if (var1 == 57 || var1 == 109 || var1 == 110) {
         this.field_738 |= 1024;
      }

      if (var1 == 42) {
         this.field_738 |= 2048;
      }

      if (var1 == 35) {
         this.field_738 |= 4096;
      }

      this.field_741 = this.field_738 & ~this.field_739;
   }

   public final void keyRepeated(int var1) {
      this.keyPressed(var1);
   }

   public final void keyReleased(int var1) {
      this.field_739 = this.field_738;
      if (var1 == -7) {
         this.field_738 &= -8193;
      }

      if (var1 == -6) {
         this.field_738 &= -16385;
      }

      if (var1 == 49 || var1 == 101 || var1 == 114) {
         this.field_738 &= -32769;
      }

      if (var1 == 51 || var1 == 105 || var1 == 117) {
         this.field_738 &= -65537;
      }

      if (var1 == 48 || var1 == 32) {
         this.field_738 &= -131073;
      }

      if (var1 == -11) {
         this.field_738 &= -262145;
      }

      if (var1 == -8) {
         this.field_738 &= -524289;
      }

      if (var1 == -1 || var1 == 50 || var1 == 121 || var1 == 116) {
         this.field_738 &= -3;
      }

      if (var1 == -2 || var1 == 56 || var1 == 98 || var1 == 118) {
         this.field_738 &= -65;
      }

      if (var1 == -3 || var1 == 52 || var1 == 100 || var1 == 102) {
         this.field_738 &= -5;
      }

      if (var1 == -4 || var1 == 54 || var1 == 106 || var1 == 107) {
         this.field_738 &= -33;
      }

      if (var1 == -5 || var1 == 53 || var1 == 103 || var1 == 104) {
         this.field_738 &= -257;
      }

      if (var1 == 55 || var1 == 99 || var1 == 120) {
         this.field_738 &= -513;
      }

      if (var1 == 57 || var1 == 109 || var1 == 110) {
         this.field_738 &= -1025;
      }

      if (var1 == 42) {
         this.field_738 &= -2049;
      }

      if (var1 == 35) {
         this.field_738 &= -4097;
      }

      this.field_740 = ~this.field_738 & this.field_739;
   }
}
