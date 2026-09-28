import javax.microedition.lcdui.Graphics;

// Deep3D-PC: the game's UI toolkit for the settings menu (org.deep3d.MenuToolkit).
public final class Deep3dMenu implements org.deep3d.MenuToolkit {
   private Graphics saved;

   public void begin(Graphics g) {
      this.saved = class_84.field_1117;
      class_84.field_1117 = g;
      g.setClip(0, 0, class_84.field_1120, class_84.field_1121);
      org.deep3d.GameUi.suspend(true);
   }

   public void end() {
      org.deep3d.GameUi.suspend(false);
      class_84.field_1117 = this.saved;
      this.saved = null;
   }

   public String text(int id) {
      return class_84.field_1116.method_4(id);
   }

   public int textWidth(String s) {
      return class_58.method_523(s);
   }

   public int lineHeight() {
      return class_58.method_527();
   }

   public String fit(String s, int w) {
      return class_67.method_600(s, w);
   }

   public void dim() {
      if (class_67.field_857 != null) {
         class_67.method_583();
      }
   }

   public void panel(String title, int x, int y, int w, int h) {
      class_67.method_591(title, x, y, w, h);
   }

   public void row(String s, int x, int y, int w, boolean selected) {
      class_67.method_584(s, x, y, w, selected);
   }

   public int[] bar(String lk, String ll, String rk, String rl) {
      return class_67.deep3dBar(lk, ll, rk, rl);
   }
}
