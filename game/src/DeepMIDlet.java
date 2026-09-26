import javax.microedition.lcdui.Display;
import javax.microedition.midlet.MIDlet;

public class DeepMIDlet extends MIDlet implements Runnable {
   // $VF: renamed from: a int
   public int field_1040;
   // $VF: renamed from: a dd
   private class_54 field_1041;
   // $VF: renamed from: a javax.microedition.lcdui.Display
   private Display field_1042;
   // $VF: renamed from: a boolean
   private boolean field_1043 = false;
   // $VF: renamed from: b boolean
   private boolean field_1044 = false;
   // $VF: renamed from: a java.lang.Thread
   private Thread field_1045;

   public DeepMIDlet() {
      try {
         this.field_1042 = Display.getDisplay(this);
         class_41.field_529 = this.field_1042;
         class_41.field_536 = this;
         this.field_1041 = new class_54(this);
         this.field_1045 = new Thread(this);
         this.field_1040 = 1;
      } catch (Exception var2) {
      }
   }

   public Display getDisplay() {
      return this.field_1042;
   }

   public void startApp() {
      try {
         this.field_1042.setCurrent(this.field_1041);
         this.field_1041.setFullScreenMode(true);
         if (!this.field_1043) {
            this.field_1045.start();
            this.field_1043 = true;
         }
      } catch (Exception var2) {
      }
   }

   public void pauseApp() {
      this.pause();
   }

   public void resume() {
      this.field_1040 = 2;
   }

   public void pause() {
      this.field_1040 = 4;
   }

   public void destroyApp(boolean var1) {
      try {
         this.field_1044 = true;
         this.field_1041.method_522();
         this.notifyDestroyed();
      } catch (Exception var3) {
      }
   }

   // $VF: renamed from: run () void
   public void run() {
      try {
         while (true) {
            switch (this.field_1040) {
               case 1:
                  if (class_41.field_531 && !this.field_1044 && class_41.field_532 != -1) {
                     class_41.field_539.method_425(class_41.field_532);
                  }

                  this.field_1041.method_521();
                  this.field_1041.method_524();
                  break;
               case 2:
                  this.field_1041.method_520();
                  this.field_1040 = 1;
                  break;
               case 3:
                  this.field_1041.method_523();
                  this.field_1041.method_524();
                  break;
               case 4:
                  this.field_1041.method_519();
                  this.field_1040 = 3;
            }

            try {
               Thread.sleep(2L);
            } catch (InterruptedException var2) {
            }
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   public void quit() {
      this.destroyApp(false);
   }
}
