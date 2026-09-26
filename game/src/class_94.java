import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;

// $VF: renamed from: cr
public final class class_94 implements Runnable {
   // $VF: renamed from: a int
   private int field_1212;
   // $VF: renamed from: a int[]
   private static final int[] field_1213 = new int[]{50, 40, 30, 40, 50, 60, 70, 60, 50};
   // $VF: renamed from: a boolean
   private boolean field_1214 = false;
   // $VF: renamed from: a javax.microedition.lcdui.game.GameCanvas
   public GameCanvas field_1215;
   // $VF: renamed from: a java.lang.Thread
   private Thread field_1216;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_1217;
   // $VF: renamed from: a javax.microedition.lcdui.Image[]
   private Image[] field_1218;
   // $VF: renamed from: b int[]
   private int[] field_1219;
   // $VF: renamed from: b boolean
   private boolean field_1220;
   // $VF: renamed from: b int
   private int field_1221;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_1222;
   // $VF: renamed from: b java.lang.String
   private String field_1223;
   // $VF: renamed from: a java.lang.String
   public static String field_1224 = "";

   public class_94() {
      field_1217 = class_40.method_412("/data/interface/logo.png");
      this.field_1218 = new Image[6];

      for (int var1 = 0; var1 < this.field_1218.length; var1++) {
         this.field_1218[var1] = class_40.method_412("/data/interface/bubble_" + var1 + ".png");
      }

      this.field_1219 = new int[18];
      this.field_1212 = class_41.field_537 - 50;

      for (int var2 = 0; var2 < this.field_1219.length; var2 += 2) {
         this.field_1219[var2] = this.field_1212 + (int)(field_1213[var2 >> 1] / 100.0F * 50.0F);
         this.field_1219[var2 + 1] = class_41.field_538 - (var2 >> 1) * (class_41.field_538 / 8);
      }
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public static final Image method_784() {
      return field_1217;
   }

   // $VF: renamed from: run () void
   public final void run() {
      while (this.field_1214 && !class_41.field_542) {
         this.method_785();
         if (this.field_1215 != null) {
            this.field_1215.flushGraphics();
         }

         try {
            Thread.sleep(10L);
         } catch (Exception var2) {
            this.field_1214 = false;
         }
      }
   }

   // $VF: renamed from: a () void
   public final void method_785() {
      this.field_1220 = class_69.method_651();
      class_41.field_534.setColor(class_58.method_565() ? -8626622 : class_69.field_1004);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      class_50.method_485(
         this.field_1223, class_41.field_537 / 2 - class_50.method_490(this.field_1223) / 2, class_41.field_538 / 2 - class_50.method_494() / 2 - 10, 0
      );
      class_50.method_485(
         field_1224, class_41.field_537 / 2 - class_50.method_490(this.field_1223) / 2, class_41.field_538 / 2 - class_50.method_494() * 2 - 10, 0
      );

      for (int var1 = 0; var1 < 9; var1++) {
         int var2 = class_58.method_565()
            ? (this.field_1221 == var1 ? 5 : 4)
            : (this.field_1220 ? (this.field_1221 == var1 ? 3 : 2) : (this.field_1221 == var1 ? 1 : 0));
         class_41.field_534.drawImage(this.field_1218[var2], this.field_1219[var1 << 1], this.field_1219[(var1 << 1) + 1], 3);
      }

      this.field_1221++;
      if (this.field_1221 > 9) {
         this.field_1221 = 0;
      }

      class_41.field_534.drawImage(field_1217, class_41.field_537 >> 1, 10, 17);
      if (class_41.field_543 != null && class_41.field_543.field_179 != null && class_41.field_543.field_179 != class_41.field_544[3]) {
         this.method_786();
      }
   }

   // $VF: renamed from: b () void
   public final void method_786() {
      class_69.method_658(10, class_41.field_538 - 10 * this.field_1222.length - 32, class_41.field_537 - 20, 10 * this.field_1222.length + 20);
      class_69.method_668(
         class_41.field_533.method_297(305),
         10,
         class_41.field_538 - 10 * this.field_1222.length - 32,
         class_41.field_537 - 20,
         10 * this.field_1222.length + 20,
         false
      );
      class_50.method_488(this.field_1222, 15, class_41.field_538 - 10 * this.field_1222.length - 20, 1);
   }

   // $VF: renamed from: c () void
   public final void method_787() {
      this.field_1214 = false;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_788(boolean var1) {
      this.field_1223 = class_41.field_533.method_297(var1 ? 229 : 230);
      int var2 = class_41.field_540.nextInt(class_22.field_319.length);
      if (class_3.method_73() < 12) {
         var2 = 4 + class_41.field_540.nextInt(class_22.field_319.length - 4);
      }

      this.field_1222 = class_50.method_499(class_41.field_533.method_297(class_22.field_319[var2]), class_41.field_537 - 30);
      this.field_1214 = true;
      this.field_1216 = new Thread(this);
      this.field_1216.start();
   }
}
