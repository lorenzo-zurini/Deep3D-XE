import javax.microedition.lcdui.Display;
import javax.microedition.midlet.MIDlet;

public class DeepMIDlet extends MIDlet implements Runnable {
   // $VF: renamed from: a int
   public int field_1525;
   // $VF: renamed from: a de
   private class_124 field_1526;
   // $VF: renamed from: a javax.microedition.lcdui.Display
   private Display field_1527;
   // $VF: renamed from: a boolean
   private boolean field_1528 = false;
   // $VF: renamed from: b boolean
   private volatile boolean field_1529 = false; // Deep3D-PC: volatile, read by the game thread
   // $VF: renamed from: a java.lang.Thread
   private Thread field_1530;

   public DeepMIDlet() {
      try {
         this.field_1527 = Display.getDisplay(this);
         class_84.field_1112 = this.field_1527;
         class_84.field_1119 = this;
         this.field_1526 = new class_124(this);
         this.field_1530 = new Thread(this);
         this.field_1525 = 1;
      } catch (Exception var2) {
      }
   }

   public Display getDisplay() {
      return this.field_1527;
   }

   public void startApp() {
      try {
         this.field_1527.setCurrent(this.field_1526);
         this.field_1526.setFullScreenMode(true);
         if (!this.field_1528) {
            this.field_1530.start();
            this.field_1528 = true;
         }
      } catch (Exception var2) {
      }
   }

   public void pauseApp() {
      this.pause();
   }

   public void resume() {
      this.field_1525 = 2;
   }

   public void pause() {
      this.field_1525 = 4;
   }

   public void destroyApp(boolean var1) {
      try {
         this.field_1529 = true;
         // Deep3D-PC: let the game thread finish its frame before the fonts
         // and images go (the loop never stopped, and drew one more frame)
         if (Thread.currentThread() != this.field_1530 && this.field_1530.isAlive()) {
            this.field_1530.join(2000L);
         }
         this.field_1526.method_950();
         this.notifyDestroyed();
      } catch (Exception var3) {
      }
   }

   // $VF: renamed from: run () void
   public void run() {
      try {
         while (!this.field_1529) { // Deep3D-PC: stops when destroyed
            switch (this.field_1525) {
               case 1:
                  if (class_84.field_1114 && !this.field_1529 && class_84.field_1115 != -1) {
                     class_84.field_1122.method_768(class_84.field_1115);
                  }

                  this.field_1526.method_949();
                  this.field_1526.method_952();
                  break;
               case 2:
                  this.field_1526.method_948();
                  this.field_1525 = 1;
                  break;
               case 3:
                  this.field_1526.method_951();
                  this.field_1526.method_952();
                  break;
               case 4:
                  this.field_1526.method_947();
                  this.field_1525 = 3;
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
