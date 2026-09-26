import javax.microedition.lcdui.Image;

// $VF: renamed from: bf
public final class class_69 {
   // $VF: renamed from: a int
   public static int field_1003 = -11955272;
   // $VF: renamed from: b int
   public static int field_1004 = -14795958;
   // $VF: renamed from: c int
   public static int field_1005 = -14461586;
   // $VF: renamed from: d int
   public static int field_1006 = -15786202;
   // $VF: renamed from: e int
   public static int field_1007 = 0;
   // $VF: renamed from: f int
   public static int field_1008 = 0;
   // $VF: renamed from: g int
   private static int field_1009;
   // $VF: renamed from: h int
   private static int field_1010;
   // $VF: renamed from: i int
   private static int field_1011;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_1012;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   private static Image field_1013;
   // $VF: renamed from: c javax.microedition.lcdui.Image
   private static Image field_1014;
   // $VF: renamed from: d javax.microedition.lcdui.Image
   private static Image field_1015;
   // $VF: renamed from: a int[]
   public static int[] field_1016;
   // $VF: renamed from: a long
   private static long field_1017;
   // $VF: renamed from: b long
   private static long field_1018;
   // $VF: renamed from: j int
   private static int field_1019;
   // $VF: renamed from: a boolean
   private static boolean field_1020;
   // $VF: renamed from: b boolean
   private static boolean field_1021;

   private class_69() {
   }

   // $VF: renamed from: a () void
   public static final void method_650() {
      field_1012 = null;
      field_1016 = null;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_651() {
      return field_1003 == -9783452;
   }

   // $VF: renamed from: b () void
   public static final void method_652() {
      field_1010 = class_50.method_490("9999") + 12;
      field_1009 = (class_41.field_537 - field_1010 - 6) / 2;
      field_1011 = 10;
      field_1007 = class_41.field_537 - 6 + 1;
      field_1008 = class_41.field_538 - 11 - 10 - 4;
      if (field_1012 == null) {
         field_1012 = class_40.method_412("/data/interface/coin.png");
         field_1013 = class_40.method_412("/data/interface/coin_red.png");
         field_1014 = class_40.method_412("/data/interface/skip.png");
      }

      if (field_1016 == null) {
         field_1016 = new int[1024];

         for (int var0 = 0; var0 < field_1016.length; var0++) {
            field_1016[var0] = -2013265920;
         }
      }
   }

   // $VF: renamed from: a () int
   public static final int method_653() {
      return 12;
   }

   // $VF: renamed from: a (boolean) void
   public static final void method_654(boolean var0) {
      if (var0) {
         field_1003 = -9783452;
         field_1004 = -14071252;
         field_1006 = -15391210;
         field_1005 = -12489412;
      } else {
         field_1003 = -11955272;
         field_1004 = -14795958;
         field_1006 = -15786202;
         field_1005 = -14461586;
      }

      if (class_58.method_565()) {
         field_1003 = -131148;
         field_1004 = -8626622;
         field_1006 = -14146007;
         field_1005 = -3296910;
      }
   }

   // $VF: renamed from: a (int) void
   public static final void method_655(int var0) {
      field_1018 += var0;
      field_1017 += var0;
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_656() {
      if (field_1018 > 1000L) {
         if (field_1018 > 2000L) {
            field_1018 = 0L;
         }

         return true;
      } else {
         return false;
      }
   }

   // $VF: renamed from: c () boolean
   public static final boolean method_657() {
      if (field_1017 > 300L) {
         if (field_1017 > 600L) {
            field_1017 = 0L;
         }

         return true;
      } else {
         return false;
      }
   }

   // $VF: renamed from: a (int, int, int, int) void
   public static final void method_658(int var0, int var1, int var2, int var3) {
      class_41.field_534.setClip(var0, var1, var2, var3);
      method_659();
      class_41.field_534.setClip(0, 0, class_41.field_537, class_41.field_538);
   }

   // $VF: renamed from: c () void
   public static final void method_659() {
      for (int var0 = 0; var0 < class_41.field_537 / 32 + 1; var0++) {
         for (int var1 = 0; var1 < class_41.field_538 / 32 + 1; var1++) {
            class_41.field_534.drawRGB(field_1016, 0, 32, var0 * 32, var1 * 32, 32, 32, true);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean) void
   public static final void method_660(String var0, int var1, int var2, int var3, boolean var4) {
      method_662(var0, var1, var2, var3, var4, false);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean, boolean, boolean) void
   public static final void method_661(String var0, int var1, int var2, int var3, boolean var4, boolean var5, boolean var6) {
      org.deep3d.GameUi.registerItem(var0, var1, var2, var3, 12, var4);
      int var7 = class_50.method_490(var0);
      if (var4) {
         class_41.field_534.setColor(field_1003);
         class_41.field_534.drawLine(var1, var2 + 2, var1 + var3, var2 + 2);
         class_41.field_534.drawLine(var1, var2 + 4, var1 + var3, var2 + 4);
         class_41.field_534.drawLine(var1, var2 + 6, var1 + var3, var2 + 6);
         class_41.field_534.drawLine(var1, var2 + 8, var1 + var3, var2 + 8);
         class_41.field_534.drawLine(var1, var2 + 10, var1 + var3, var2 + 10);
         class_41.field_534.fillRect(var5 ? var1 + (var3 >> 1) - (var7 >> 1) - 1 : var1 + 9, var2 + 2, var7 + 3, 8);
      }

      class_50.method_483(var0, var5 ? var1 + (var3 >> 1) : var1 + 10, var2 + 1, var4 ? 0 : 1, var5 ? 24 : 17);
      if (var6) {
         if (field_1015 == null) {
            field_1015 = class_40.method_412("/data/interface/lock.png");
         }

         if (class_3.method_73() < 9 && var0 == class_41.field_533.method_297(37)
            || class_3.method_73() < 7 && var0 == class_41.field_533.method_297(73)
            || class_3.method_110().method_592() && var0 == class_41.field_533.method_297(235)) {
            class_41.field_534.drawImage(field_1015, var1 + 3, var2 + 2, 0);
         }
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, boolean, boolean) void
   public static final void method_662(String var0, int var1, int var2, int var3, boolean var4, boolean var5) {
      method_661(var0, var1, var2, var3, var4, var5, false);
   }

   // $VF: renamed from: d () void
   public static final void method_663() {
      class_41.field_534.setColor(0);
      class_41.field_534.fillRect(0, 0, class_41.field_537, class_41.field_538);
      class_41.field_534.setColor(field_1004);
      class_41.field_534.fillRect(1, 1, class_41.field_537 - 3, class_41.field_538 - 6 - field_1011);
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_664(String var0) {
      method_668(var0, 1, 1, class_41.field_537 - 3, class_41.field_538 - 6 - field_1011, false);
   }

   // $VF: renamed from: a (java.lang.String, int, boolean, int, int, int, int) void
   public static final void method_665(String var0, int var1, boolean var2, int var3, int var4, int var5, int var6) {
      String var7 = var1 >= 1000000 ? var1 / 1000000 + "M" : (var1 >= 10000 ? var1 / 1000 + "k" : "" + var1);
      class_50.method_483(var0 + var7, var3 + ((var6 & 8) != 0 ? -4 : ((var6 & 2) != 0 ? -10 : 0)), var4, var5, var6);
      if ((var6 & 32) != 0) {
         var4 -= 10;
      }

      if ((var6 & 8) != 0) {
         var3 += class_50.method_490(var0 + var7) / 2 - 2;
      }

      if ((var6 & 2) != 0) {
         var3 -= 9;
      }

      if ((var6 & 1) != 0 || var6 == 0) {
         var3 += class_50.method_490(var0 + var7) + 2;
      }

      class_41.field_534.drawImage(class_3.method_112() < var1 && var2 ? field_1013 : field_1012, var3, var4 + 2, 0);
   }

   // $VF: renamed from: a (int, boolean, int, int, int, int) void
   public static final void method_666(int var0, boolean var1, int var2, int var3, int var4, int var5) {
      method_665("", var0, var1, var2, var3, var4, var5);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int) void
   public static final void method_667(String var0, int var1, int var2, int var3, int var4) {
      method_668(var0, var1, var2, var3, var4, true);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int, boolean) void
   public static final void method_668(String var0, int var1, int var2, int var3, int var4, boolean var5) {
      if (var5) {
         class_41.field_534.setColor(field_1004);
         class_41.field_534.fillRect(var1, var2, var3, var4);
      }

      class_41.field_534.setColor(field_1005);
      class_41.field_534.fillRect(var1, var2, var3, 8);
      class_41.field_534.setColor(field_1003);
      class_41.field_534.drawRect(var1, var2, var3, var4);
      class_41.field_534.setClip(var1, var2, var3, 10);

      for (int var6 = var1; var6 < var1 + var3; var6 += 4) {
         class_41.field_534.drawLine(var6, var2 + 6, var6 + 4, var2 + 2);
      }

      class_41.field_534.setClip(0, 0, class_41.field_537, class_41.field_538);
      class_41.field_534.drawLine(var1, var2 + 8, var1 + var3, var2 + 8);
      class_41.field_534.fillRect(var1, var2, class_50.method_490(var0) + 4, 8);
      class_50.method_485(var0, var1 + 2, var2 - 1, 0);
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String) void
   public static final void method_669(String var0, String var1) {
      method_677(var0, var1, true);
   }

   // $VF: renamed from: b (boolean) void
   public static final void method_670(boolean var0) {
      field_1020 = var0;
      field_1019 = 5;
   }

   // $VF: renamed from: d () boolean
   public static final boolean method_671() {
      return field_1019 <= 0;
   }

   // $VF: renamed from: e () void
   public static final void method_672() {
      field_1019--;
   }

   // $VF: renamed from: c (boolean) void
   public static final void method_673(boolean var0) {
      field_1021 = var0;
   }

   // $VF: renamed from: b (java.lang.String, int, int, int, int) void
   public static final void method_674(String var0, int var1, int var2, int var3, int var4) {
      method_675(var0, var1, var2, var3, var4, 17);
   }

   // $VF: renamed from: a (java.lang.String, int, int, int, int, int) void
   public static final void method_675(String var0, int var1, int var2, int var3, int var4, int var5) {
      String var6;
      String var7;
      class_50.method_483((var7 = class_50.method_500(var6 = var0.trim(), var3 - 2, true)).equals(var6) ? var6 : var7 + "...", var1, var2, var4, var5);
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public static final String method_676(String var0, int var1) {
      String var2;
      String var3;
      return (var3 = class_50.method_500(var2 = var0.trim(), var1 - 2, true)).equals(var2) ? var2 : var3 + "...";
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String, boolean) void
   public static final void method_677(String var0, String var1, boolean var2) {
      method_678(var0, var1, var2, false);
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String, boolean, boolean) void
   // Deep3D-PC: phone softkey boxes replaced with a PC command bar (same
   // palette and font); zones are registered for mouse clicks.
   public static final void method_678(String var0, String var1, boolean var2, boolean var3) {
      javax.microedition.lcdui.Graphics g = class_41.field_534;
      int barH = field_1011;
      int y = class_41.field_538 - 3 - barH;
      int w = class_41.field_537;
      g.setColor(field_1006);
      g.fillRect(0, y - 2, w, barH + 5);
      g.setColor(field_1003);
      g.drawLine(0, y - 2, w, y - 2);

      int lx = 0;
      int lw = 0;
      int rx = 0;
      int rw = 0;
      if (var0 != null && !var0.equals("")) {
         String key = org.deep3d.GameUi.confirmKeyLabel();
         int kw = class_50.method_490(key);
         int tw = class_50.method_490(var0);
         lw = kw + tw + 16;
         lx = 2;
         g.setColor(field_1020 && field_1019 > 0 ? field_1003 : field_1005);
         g.fillRect(lx, y, lw, barH);
         g.setColor(field_1003);
         g.drawRect(lx, y, lw, barH);
         class_50.method_485(key, lx + 4, y, 1);
         class_50.method_485(var0, lx + 4 + kw + 7, y, 0);
      }

      if (var1 != null && !var1.equals("")) {
         String key = org.deep3d.GameUi.backKeyLabel();
         int kw = class_50.method_490(key);
         int tw = class_50.method_490(var1);
         rw = kw + tw + 16;
         rx = w - rw - 2;
         g.setColor(!field_1020 && field_1019 > 0 ? field_1003 : field_1005);
         g.fillRect(rx, y, rw, barH);
         g.setColor(field_1003);
         g.drawRect(rx, y, rw, barH);
         class_50.method_485(key, rx + 4, y, 1);
         class_50.method_485(var1, rx + 4 + kw + 7, y, 0);
      }

      org.deep3d.GameUi.registerBarZones(lx, y, lw, barH, rx, y, rw, barH);
      if (var2) {
         method_666(class_3.method_112(), false, w >> 1, class_41.field_538 - 2, 0, 40);
      } else if (var3) {
         g.drawImage(field_1014, w >> 1, class_41.field_538 - 3, 33);
      }
   }
}
