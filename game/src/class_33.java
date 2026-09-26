import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;

// $VF: renamed from: cs
public final class class_33 implements Runnable {
   // $VF: renamed from: a int
   private int field_329;
   // $VF: renamed from: a int[]
   private static final int[] field_330 = new int[]{50, 40, 30, 40, 50, 60, 70, 60, 50};
   // $VF: renamed from: a boolean
   private boolean field_331 = false;
   // $VF: renamed from: a javax.microedition.lcdui.game.GameCanvas
   public GameCanvas field_332;
   // $VF: renamed from: a java.lang.Thread
   private Thread field_333;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_334;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_335;
   // $VF: renamed from: b int[]
   private int[] field_336;
   // $VF: renamed from: b boolean
   private boolean field_337;
   // $VF: renamed from: b int
   private int field_338;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_339;
   // $VF: renamed from: b java.lang.String
   private String field_340;
   // $VF: renamed from: a java.lang.String
   public static String field_341 = "";

   public class_33() {
      field_334 = class_28.method_282("/data/interface/logo.png");
      this.field_335 = new Image[6];

      for (int var1 = 0; var1 < this.field_335.length; var1++) {
         this.field_335[var1] = class_28.method_282("/data/interface/bubble_" + var1 + ".png");
      }

      this.field_336 = new int[18];
      this.field_329 = class_84.field_1120 - 50;

      for (int var2 = 0; var2 < this.field_336.length; var2 += 2) {
         this.field_336[var2] = this.field_329 + (int)(field_330[var2 >> 1] / 100.0F * 50.0F);
         this.field_336[var2 + 1] = class_84.field_1121 - (var2 >> 1) * (class_84.field_1121 / 8);
      }
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public static final Image method_292() {
      return field_334;
   }

   // $VF: renamed from: run () void
   public final void run() {
      while (this.field_331 && !class_84.field_1125) {
         this.method_293();
         if (this.field_332 != null) {
            this.field_332.flushGraphics();
         }

         try {
            Thread.sleep(10L);
         } catch (Exception var2) {
            this.field_331 = false;
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_293() {
      this.field_337 = class_67.method_575();
      class_84.field_1117.setColor(class_14.method_70() ? -8626622 : class_67.field_845);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      class_58.method_518(
         this.field_340, class_84.field_1120 / 2 - class_58.method_523(this.field_340) / 2, class_84.field_1121 / 2 - class_58.method_527() / 2 - 10, 0
      );
      class_58.method_518(
         field_341, class_84.field_1120 / 2 - class_58.method_523(this.field_340) / 2, class_84.field_1121 / 2 - class_58.method_527() * 2 - 10, 0
      );

      for (int var1 = 0; var1 < 9; var1++) {
         int var2 = class_14.method_70()
            ? (this.field_338 == var1 ? 5 : 4)
            : (this.field_337 ? (this.field_338 == var1 ? 3 : 2) : (this.field_338 == var1 ? 1 : 0));
         class_84.field_1117.drawImage(this.field_335[var2], this.field_336[var1 << 1], this.field_336[(var1 << 1) + 1], 3);
      }

      this.field_338++;
      if (this.field_338 > 9) {
         this.field_338 = 0;
      }

      class_84.field_1117.drawImage(field_334, class_84.field_1120 >> 1, 10, 17);
      if (class_84.field_1126 != null && class_84.field_1126.field_595 != null && class_84.field_1126.field_595 != class_84.field_1127[3]) {
         this.method_294();
      }
   }

   // $VF: renamed from: b () void
   public final void method_294() {
      class_67.method_582(10, class_84.field_1121 - 10 * this.field_339.length - 32, class_84.field_1120 - 20, 10 * this.field_339.length + 20);
      class_67.method_592(
         class_84.field_1116.method_4(305),
         10,
         class_84.field_1121 - 10 * this.field_339.length - 32,
         class_84.field_1120 - 20,
         10 * this.field_339.length + 20,
         false
      );
      class_58.method_521(this.field_339, 15, class_84.field_1121 - 10 * this.field_339.length - 20, 1);
   }

   // $VF: renamed from: c () void
   public final void method_295() {
      this.field_331 = false;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_296(boolean var1) {
      this.field_340 = class_84.field_1116.method_4(var1 ? 229 : 230);
      int var2 = class_84.field_1123.nextInt(class_1.field_5.length);
      if (class_21.method_143() < 12) {
         var2 = 4 + class_84.field_1123.nextInt(class_1.field_5.length - 4);
      }

      this.field_339 = class_58.method_532(class_84.field_1116.method_4(class_1.field_5[var2]), class_84.field_1120 - 30);
      this.field_331 = true;
      this.field_333 = new Thread(this);
      this.field_333.start();
   }
}
