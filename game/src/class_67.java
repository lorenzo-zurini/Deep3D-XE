import javax.microedition.lcdui.Image;

// $VF: renamed from: be
public final class class_67 {
   // $VF: renamed from: a int
   public static int field_844 = -11955272;
   // $VF: renamed from: b int
   public static int field_845 = -14795958;
   // $VF: renamed from: c int
   public static int field_846 = -14461586;
   // $VF: renamed from: d int
   public static int field_847 = -15786202;
   // $VF: renamed from: e int
   public static int field_848 = 0;
   // $VF: renamed from: f int
   public static int field_849 = 0;
   // $VF: renamed from: g int
   private static int field_850;
   // $VF: renamed from: h int
   private static int field_851;
   // $VF: renamed from: i int
   private static int field_852;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_853;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private static Image field_854;
   // $VF: renamed from: c javax.microedition.lcdui.Image
   private static Image field_855;
   // $VF: renamed from: d javax.microedition.lcdui.Image
   private static Image field_856;
   // $VF: renamed from: a int[]
   public static int[] field_857;
   // $VF: renamed from: a long
   private static long field_858;
   // $VF: renamed from: b long
   private static long field_859;
   // $VF: renamed from: j int
   private static int field_860;
   // $VF: renamed from: a boolean
   private static boolean field_861;
   // $VF: renamed from: b boolean
   private static boolean field_862;

   private class_67() {
   }

   // $VF: renamed from: a () void
   public static final void method_574() {
      field_853 = null;
      field_857 = null;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_575() {
      return field_844 == -9783452;
   }

   // $VF: renamed from: b () void
   public static final void method_576() {
      field_851 = class_58.method_523("9999") + 12;
      field_850 = (class_84.field_1120 - field_851 - 6) / 2;
      field_852 = 10;
      field_848 = class_84.field_1120 - 6 + 1;
      field_849 = class_84.field_1121 - 11 - 10 - 4;
      if (field_853 == null) {
         field_853 = class_28.method_282("/data/interface/coin.png");
         field_854 = class_28.method_282("/data/interface/coin_red.png");
         field_855 = class_28.method_282("/data/interface/skip.png");
      }

      if (field_857 == null) {
         field_857 = new int[1024];

         for (int var0 = 0; var0 < field_857.length; var0++) {
            field_857[var0] = -2013265920;
         }
      }
   }

   // $VF: renamed from: a () int
   public static final int method_577() {
      return 12;
   }

   // $VF: renamed from: a (boolean) void
   public static final void method_578(boolean var0) {
      if (var0) {
         field_844 = -9783452;
         field_845 = -14071252;
         field_847 = -15391210;
         field_846 = -12489412;
      } else {
         field_844 = -11955272;
         field_845 = -14795958;
         field_847 = -15786202;
         field_846 = -14461586;
      }

      if (class_14.method_70()) {
         field_844 = -131148;
         field_845 = -8626622;
         field_847 = -14146007;
         field_846 = -3296910;
      }
   }

   // $VF: renamed from: a (int) void
   public static final void method_579(int var0) {
      field_859 += var0;
      field_858 += var0;
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_580() {
      if (field_859 > 1000L) {
         if (field_859 > 2000L) {
            field_859 = 0L;
         }

         return true;
      } else {
         return false;
      }
   }

   // $VF: renamed from: c () boolean
   public static final boolean method_581() {
      if (field_858 > 300L) {
         if (field_858 > 600L) {
            field_858 = 0L;
         }

         return true;
      } else {
         return false;
      }
   }

   // $VF: renamed from: a (int, int, int, int) void
   public static final void method_582(int var0, int var1, int var2, int var3) {
      class_84.field_1117.setClip(var0, var1, var2, var3);
      method_583();
      class_84.field_1117.setClip(0, 0, class_84.field_1120, class_84.field_1121);
   }

   // $VF: renamed from: c () void
   public static final void method_583() {
      for (int var0 = 0; var0 < class_84.field_1120 / 32 + 1; var0++) {
         for (int var1 = 0; var1 < class_84.field_1121 / 32 + 1; var1++) {
            class_84.field_1117.drawRGB(field_857, 0, 32, var0 * 32, var1 * 32, 32, 32, true);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean) void
   public static final void method_584(String var0, int var1, int var2, int var3, boolean var4) {
      method_586(var0, var1, var2, var3, var4, false);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean, boolean, boolean) void
   public static final void method_585(String var0, int var1, int var2, int var3, boolean var4, boolean var5, boolean var6) {
      org.deep3d.GameUi.registerItem(var0, var1, var2, var3, 12, var4); // Deep3D-PC: mouse
      int var7 = class_58.method_523(var0);
      if (var4) {
         class_84.field_1117.setColor(field_844);
         class_84.field_1117.drawLine(var1, var2 + 2, var1 + var3, var2 + 2);
         class_84.field_1117.drawLine(var1, var2 + 4, var1 + var3, var2 + 4);
         class_84.field_1117.drawLine(var1, var2 + 6, var1 + var3, var2 + 6);
         class_84.field_1117.drawLine(var1, var2 + 8, var1 + var3, var2 + 8);
         class_84.field_1117.drawLine(var1, var2 + 10, var1 + var3, var2 + 10);
         class_84.field_1117.fillRect(var5 ? var1 + (var3 >> 1) - (var7 >> 1) - 1 : var1 + 9, var2 + 2, var7 + 3, 8);
      }

      class_58.method_516(var0, var5 ? var1 + (var3 >> 1) : var1 + 10, var2 + 1, var4 ? 0 : 1, var5 ? 24 : 17);
      if (var6) {
         if (field_856 == null) {
            field_856 = class_28.method_282("/data/interface/lock.png");
         }

         if (class_21.method_143() < 9 && var0 == class_84.field_1116.method_4(37)
            || class_21.method_143() < 7 && var0 == class_84.field_1116.method_4(73)
            || class_21.method_180().method_752() && var0 == class_84.field_1116.method_4(235)) {
            class_84.field_1117.drawImage(field_856, var1 + 3, var2 + 2, 0);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean, boolean) void
   public static final void method_586(String var0, int var1, int var2, int var3, boolean var4, boolean var5) {
      method_585(var0, var1, var2, var3, var4, var5, false);
   }

   // $VF: renamed from: d () void
   public static final void method_587() {
      class_84.field_1117.setColor(0);
      class_84.field_1117.fillRect(0, 0, class_84.field_1120, class_84.field_1121);
      class_84.field_1117.setColor(field_845);
      class_84.field_1117.fillRect(1, 1, class_84.field_1120 - 3, class_84.field_1121 - 6 - field_852);
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_588(String var0) {
      method_592(var0, 1, 1, class_84.field_1120 - 3, class_84.field_1121 - 6 - field_852, false);
   }

   // $VF: renamed from: a (java.lang.String, int, boolean, int, int, int, int) void
   public static final void method_589(String var0, int var1, boolean var2, int var3, int var4, int var5, int var6) {
      String var7 = var1 >= 1000000 ? var1 / 1000000 + "M" : (var1 >= 10000 ? var1 / 1000 + "k" : "" + var1);
      class_58.method_516(var0 + var7, var3 + ((var6 & 8) != 0 ? -4 : ((var6 & 2) != 0 ? -10 : 0)), var4, var5, var6);
      if ((var6 & 32) != 0) {
         var4 -= 10;
      }

      if ((var6 & 8) != 0) {
         var3 += class_58.method_523(var0 + var7) / 2 - 2;
      }

      if ((var6 & 2) != 0) {
         var3 -= 9;
      }

      if ((var6 & 1) != 0 || var6 == 0) {
         var3 += class_58.method_523(var0 + var7) + 2;
      }

      class_84.field_1117.drawImage(class_21.method_182() < var1 && var2 ? field_854 : field_853, var3, var4 + 2, 0);
   }

   // $VF: renamed from: a (int, boolean, int, int, int, int) void
   public static final void method_590(int var0, boolean var1, int var2, int var3, int var4, int var5) {
      method_589("", var0, var1, var2, var3, var4, var5);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int) void
   public static final void method_591(String var0, int var1, int var2, int var3, int var4) {
      method_592(var0, var1, var2, var3, var4, true);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int, boolean) void
   public static final void method_592(String var0, int var1, int var2, int var3, int var4, boolean var5) {
      if (var5) {
         class_84.field_1117.setColor(field_845);
         class_84.field_1117.fillRect(var1, var2, var3, var4);
      }

      class_84.field_1117.setColor(field_846);
      class_84.field_1117.fillRect(var1, var2, var3, 8);
      class_84.field_1117.setColor(field_844);
      class_84.field_1117.drawRect(var1, var2, var3, var4);
      class_84.field_1117.setClip(var1, var2, var3, 10);

      for (int var6 = var1; var6 < var1 + var3; var6 += 4) {
         class_84.field_1117.drawLine(var6, var2 + 6, var6 + 4, var2 + 2);
      }

      class_84.field_1117.setClip(0, 0, class_84.field_1120, class_84.field_1121);
      class_84.field_1117.drawLine(var1, var2 + 8, var1 + var3, var2 + 8);
      class_84.field_1117.fillRect(var1, var2, class_58.method_523(var0) + 4, 8);
      class_58.method_518(var0, var1 + 2, var2 - 1, 0);
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String) void
   public static final void method_593(String var0, String var1) {
      method_601(var0, var1, true);
   }

   // $VF: renamed from: b (boolean) void
   public static final void method_594(boolean var0) {
      field_861 = var0;
      field_860 = 5;
   }

   // $VF: renamed from: d () boolean
   public static final boolean method_595() {
      return field_860 <= 0;
   }

   // $VF: renamed from: e () void
   public static final void method_596() {
      field_860--;
   }

   // $VF: renamed from: c (boolean) void
   public static final void method_597(boolean var0) {
      field_862 = var0;
   }

   // $VF: renamed from: b (java.lang.String, int, int, int, int) void
   public static final void method_598(String var0, int var1, int var2, int var3, int var4) {
      method_599(var0, var1, var2, var3, var4, 17);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int, int) void
   public static final void method_599(String var0, int var1, int var2, int var3, int var4, int var5) {
      String var6;
      String var7;
      class_58.method_516((var7 = class_58.method_533(var6 = var0.trim(), var3 - 2, true)).equals(var6) ? var6 : var7 + "...", var1, var2, var4, var5);
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public static final String method_600(String var0, int var1) {
      String var2;
      String var3;
      return (var3 = class_58.method_533(var2 = var0.trim(), var1 - 2, true)).equals(var2) ? var2 : var3 + "...";
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String, boolean) void
   public static final void method_601(String var0, String var1, boolean var2) {
      method_602(var0, var1, var2, false);
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String, boolean, boolean) void
   // Deep3D-PC: the phone's softkey boxes become a PC command bar (same
   // palette and font) naming the keys / buttons of the universal actions
   // for this screen (org.deep3d.GameUi); the chips take mouse clicks.
   public static final void method_602(String var0, String var1, boolean var2, boolean var3) {
      javax.microedition.lcdui.Graphics g = class_84.field_1117;
      int h = field_852;
      int y = class_84.field_1121 - 3 - h;
      int w = class_84.field_1120;
      g.setColor(field_847);
      g.fillRect(0, y - 2, w, h + 5);
      g.setColor(field_844);
      g.drawLine(0, y - 2, w, y - 2);
      String[] chips = org.deep3d.GameUi.barChips(var0, var1);
      int lw = drawCommand(chips[1], chips[0], 2, y, h, false, field_861 && field_860 > 0);
      int rw = drawCommand(chips[3], chips[2], w - 2, y, h, true, !field_861 && field_860 > 0);
      org.deep3d.GameUi.registerBarZones(2, y, lw, h, w - 2 - rw, y, rw, h);
      if (var2) {
         method_590(class_21.method_182(), false, w >> 1, class_84.field_1121 - 2, 0, 40);
      } else if (var3) {
         g.drawImage(field_855, w >> 1, class_84.field_1121 - 3, 33);
      }
   }

   // Deep3D-PC: one "[key] label" chip of the command bar; returns its width.
   private static int drawCommand(String label, String key, int x, int y, int h, boolean alignRight, boolean lit) {
      if (label == null || label.equals("")) {
         return 0;
      }
      javax.microedition.lcdui.Graphics g = class_84.field_1117;
      int kw = key.equals("") ? 0 : class_58.method_523(key) + 7;
      int cw = kw + class_58.method_523(label) + 9;
      int cx = alignRight ? x - cw : x;
      g.setColor(lit ? field_844 : field_846);
      g.fillRect(cx, y, cw, h);
      g.setColor(field_844);
      g.drawRect(cx, y, cw, h);
      if (kw > 0) {
         class_58.method_518(key, cx + 4, y, 1);
      }
      class_58.method_518(label, cx + 4 + kw, y, 0);
      return cw;
   }
}
