import javax.microedition.lcdui.Image;

// $VF: renamed from: l
public final class class_114 extends class_113 {
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_1383;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private Image field_1384;
   // $VF: renamed from: a boolean
   private boolean field_1385;
   // $VF: renamed from: a long
   private long field_1386;
   // $VF: renamed from: a int
   private int field_1387;
   // $VF: renamed from: b int
   private int field_1388;
   // $VF: renamed from: c int
   private int field_1389;
   // $VF: renamed from: a byte[]
   private byte[] field_1390;

   // $VF: renamed from: a () void
   public final void method_902() {
      try {
         this.field_1383 = class_40.method_412("/data/interface/fishlabs.png");
         this.field_1384 = class_40.method_412("/data/interface/abyss.png");
      } catch (Exception var2) {
         var2.printStackTrace();
      }

      this.field_1386 = System.currentTimeMillis();
      this.field_1387 = 0;
      this.field_1385 = true;
      this.field_1388 = 0;
      ;
   }

   // $VF: renamed from: b () void
   public final void method_903() {
      this.field_1383 = null;
      this.field_1384 = null;
      this.field_1385 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_904() {
      return this.field_1385;
   }

   // $VF: renamed from: a (int) void
   public final void method_901(int var1) {
      if (this.field_1387 == 0) {
         if (var1 == 2 && this.field_1388 == 1) {
            this.field_1388--;
         }

         if (var1 == 64 && this.field_1388 == 0) {
            this.field_1388++;
         }

         if (var1 == 32768) {
            this.field_1389++;
            if (this.field_1389 > class_24.field_374.length) {
               this.field_1389 = 0;
            }

            this.field_1390 = class_24.field_374[this.field_1389];
         }

         if (var1 == 256 || var1 == 16384) {
            class_41.field_497 = this.field_1388 == 0;
            if (this.field_1388 == 1) {
               class_41.field_500 = 3;
            } else {
               class_41.field_500 = 1;
            }

            class_41.field_539.method_422(100);
            class_41.field_539.method_425(0);
            this.field_1386 = System.currentTimeMillis();
            this.field_1387 = 1;
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_900(int var1) {
      class_41.field_534.setColor(class_69.field_1004);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      if (this.field_1387 == 0) {
         class_41.field_534.drawImage(class_94.method_784(), class_41.field_537 >> 1, 10, 17);
         class_69.method_660(
            class_41.field_533.method_297(6) + " " + class_41.field_533.method_297(14), 0, class_41.field_538 >> 1, class_41.field_537, this.field_1388 == 0
         );
         class_69.method_660(
            class_41.field_533.method_297(6) + " " + class_41.field_533.method_297(15),
            0,
            (class_41.field_538 >> 1) + class_50.method_494(),
            class_41.field_537,
            this.field_1388 == 1
         );
         class_69.method_677(class_41.field_533.method_297(265), "", false);
         if (this.field_1390 != null) {
            class_119.method_928(this.field_1390, 0, 40, 0);
            class_50.method_485(class_24.field_375[this.field_1389], 40, 40, 0);
            return;
         }
      } else if (this.field_1387 == 1) {
         class_41.field_534.drawImage(this.field_1383, class_41.field_537 / 2, class_41.field_538 / 2, 3);
         if (System.currentTimeMillis() - this.field_1386 > 3000L) {
            this.field_1387++;
            return;
         }
      } else if (this.field_1387 == 2) {
         class_41.field_534.drawImage(this.field_1384, class_41.field_537 / 2, class_41.field_538 / 2, 3);
         if (System.currentTimeMillis() - this.field_1386 > 6000L) {
            this.field_1387++;
            return;
         }
      } else {
         class_41.field_543.method_213(class_41.field_544[0]);
      }
   }
}
