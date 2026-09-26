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
public final class class_53 implements CommandListener, PlayerListener {
   // $VF: renamed from: a javax.microedition.media.Player
   private Player field_590;
   // $VF: renamed from: a javax.microedition.media.control.VideoControl
   private VideoControl field_591;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_592;
   // $VF: renamed from: a byte[]
   private byte[] field_593;
   // $VF: renamed from: a javax.microedition.lcdui.Form
   private Form field_594 = new Form("Deep");

   public class_53() {
      this.field_594.append(class_84.field_1116.method_4(303));
      this.field_594.addCommand(new Command(class_84.field_1116.method_4(65), 3, 0));
      this.field_594.addCommand(new Command("Click!", 1, 1));
      this.field_594.setCommandListener(this);
   }

   // $VF: renamed from: a () void
   public final void method_436() {
      try {
         if (this.field_590 == null) {
            this.field_590 = Manager.createPlayer("capture://image");
            this.field_590.addPlayerListener(this);
            this.field_590.realize();
         }

         if (this.field_591 == null) {
            this.field_591 = (VideoControl)this.field_590.getControl("VideoControl");
            if (this.field_591 != null) {
               this.field_594.set(0, (Item)this.field_591.initDisplayMode(0, null));
               this.field_594.get(0).setLayout(51);

               try {
                  this.field_591.setDisplaySize(class_84.field_1120, class_84.field_1120);
               } catch (Exception var2) {
                  var2.printStackTrace();
               }
            }
         }

         this.field_590.start();
         class_84.field_1112.setCurrent(this.field_594);
      } catch (Exception var3) {
         var3.getMessage();
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public final Image method_437() {
      if (this.field_590 == null) {
         this.method_436();
      }

      try {
         this.field_593 = this.field_591.getSnapshot(null);
         this.field_592 = Image.createImage(this.field_593, 0, this.field_593.length);
         this.field_592 = class_28.method_280(
            this.field_592, class_119.field_1458, (int)((float)class_119.field_1459 * class_84.field_1121 / class_84.field_1120)
         );
         this.field_592 = Image.createImage(
            this.field_592, 0, this.field_592.getHeight() - class_119.field_1459 >> 1, class_119.field_1458, class_119.field_1459, 0
         );
         this.field_590.stop();
         this.field_590.deallocate();
         this.field_590.close();
         this.field_590 = null;
         return this.field_592;
      } catch (Exception var2) {
         var2.printStackTrace();
         return null;
      }
   }

   // $VF: renamed from: b () void
   public final void method_438() {
      if (this.field_590 != null) {
         this.field_590.deallocate();
      }
   }

   public final void playerUpdate(Player var1, String var2, Object var3) {
   }

   public final void commandAction(Command var1, Displayable var2) {
      if (var1.getLabel().equals("Click!")) {
         this.field_592 = this.method_437();
         if (this.field_592 != null) {
            class_51.field_577 = false;
         }
      }

      class_84.field_1112.setCurrent(class_84.field_1118);
   }
}
