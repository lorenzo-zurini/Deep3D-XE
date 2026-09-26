import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.Item;
import javax.microedition.media.Manager;
import javax.microedition.media.Player;
import javax.microedition.media.PlayerListener;
import javax.microedition.media.control.VideoControl;

// $VF: renamed from: bs
public final class class_123 implements CommandListener, PlayerListener {
   // $VF: renamed from: a javax.microedition.media.Player
   private Player field_1530;
   // $VF: renamed from: a javax.microedition.media.control.VideoControl
   private VideoControl field_1531;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_1532;
   // $VF: renamed from: a byte[]
   private byte[] field_1533;
   // $VF: renamed from: a javax.microedition.lcdui.Form
   private Form field_1534 = new Form("Deep");

   public class_123() {
      this.field_1534.append(class_41.field_533.method_297(303));
      this.field_1534.addCommand(new Command(class_41.field_533.method_297(65), 3, 0));
      this.field_1534.addCommand(new Command("Click!", 1, 1));
      this.field_1534.setCommandListener(this);
   }

   // $VF: renamed from: a () void
   public final void method_933() {
      try {
         if (this.field_1530 == null) {
            this.field_1530 = Manager.createPlayer("capture://video");
            this.field_1530.addPlayerListener(this);
            this.field_1530.realize();
         }

         if (this.field_1531 == null) {
            this.field_1531 = (VideoControl)this.field_1530.getControl("VideoControl");
            if (this.field_1531 != null) {
               this.field_1534.set(0, (Item)this.field_1531.initDisplayMode(0, null));
               this.field_1534.get(0).setLayout(51);

               try {
                  this.field_1531.setDisplaySize(class_41.field_537, class_41.field_537);
               } catch (Exception var2) {
                  var2.printStackTrace();
               }
            }
         }

         this.field_1530.start();
         class_41.field_529.setCurrent(this.field_1534);
      } catch (Exception var3) {
         var3.getMessage();
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public final Image method_934() {
      if (this.field_1530 == null) {
         this.method_933();
      }

      try {
         this.field_1533 = this.field_1531.getSnapshot(null);
         this.field_1532 = Image.createImage(this.field_1533, 0, this.field_1533.length);
         this.field_1532 = class_40.method_410(
            this.field_1532, class_119.field_1504, (int)((float)class_119.field_1505 * class_41.field_538 / class_41.field_537)
         );
         this.field_1532 = Image.createImage(
            this.field_1532, 0, this.field_1532.getHeight() - class_119.field_1505 >> 1, class_119.field_1504, class_119.field_1505, 0
         );
         this.field_1530.stop();
         this.field_1530.deallocate();
         this.field_1530.close();
         this.field_1530 = null;
         return this.field_1532;
      } catch (Exception var2) {
         var2.printStackTrace();
         return null;
      }
   }

   // $VF: renamed from: b () void
   public final void method_935() {
      if (this.field_1530 != null) {
         this.field_1530.deallocate();
      }
   }

   public final void playerUpdate(Player var1, String var2, Object var3) {
   }

   public final void commandAction(Command var1, Displayable var2) {
      if (var1.getLabel().equals("Click!")) {
         this.field_1532 = this.method_934();
         if (this.field_1532 != null) {
            class_67.field_922 = false;
         }
      }

      class_41.field_529.setCurrent(class_41.field_535);
   }
}
