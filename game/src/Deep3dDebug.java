// Deep3D-PC: debug options (org.deep3d.Cheats: Options > Debug) and test hooks
// (the input pipe's "call Deep3dDebug <method> <int>")
public final class Deep3dDebug implements org.deep3d.Cheats.Game {
   // the player's damage model: immune while god mode is on (class_37)
   public static class_37 player;

   private static final String[] TINTS = {"yellow", "blue", "orange", "red", "green"};
   private String[] labels;
   private int[] ids;

   private Deep3dDebug() {
   }

   public static void install() {
      org.deep3d.Cheats.install(new Deep3dDebug());
   }

   // Makes station n (data/txt/stations.txt order) the current one; the
   // next flight scene is built around it. Returns its depth.
   public static int warp(int n) {
      class_86 var1 = class_38.method_354(n);
      class_21.method_181(var1);
      System.out.println("[warp] " + var1.field_1133 + " depth " + var1.field_1140);
      return var1.field_1140;
   }

   // On the game thread between frames (class_124): a pending teleport
   // makes the station current and docks there.
   public static void tick() {
      int var0 = org.deep3d.Cheats.takeTeleport();
      if (var0 >= 0 && inGameNow()) {
         warp(var0);
         class_84.field_1126.method_439(class_84.field_1127[1]);
      }
   }

   private static boolean inGameNow() {
      class_61 var0 = class_84.field_1126 != null ? class_84.field_1126.field_595 : null;
      return var0 instanceof class_64 || var0 instanceof class_63;
   }

   public static boolean godFor(class_37 var0) {
      return org.deep3d.Cheats.god && var0 == player;
   }

   public boolean inGame() {
      return inGameNow();
   }

   public String[] stationLabels() {
      this.catalog();
      return this.labels;
   }

   public int[] stationIds() {
      this.catalog();
      return this.ids;
   }

   // One station for each sector tint and depth band (their sky, light and murk)
   private synchronized void catalog() {
      if (this.labels != null) {
         return;
      }
      java.util.LinkedHashMap<String, Integer> var1 = new java.util.LinkedHashMap<>();
      java.util.TreeMap<String, String> var2 = new java.util.TreeMap<>();
      for (int var3 = 0; var3 < 400; var3++) {
         class_86 var4;
         try {
            var4 = class_38.method_354(var3);
         } catch (RuntimeException var10) {
            break;
         }
         if (var4 == null || var4.field_1133 == null || var4.field_1133.length() == 0) {
            break;
         }
         String var5 = "clear";
         try {
            byte[] var6 = class_38.method_363(var4);
            for (int var7 = 0; var7 < var6.length; var7 += 2) {
               if (var6[var7] > 12 && var6[var7] < 18) {
                  var5 = TINTS[var6[var7] - 13];
                  break;
               }
            }
         } catch (RuntimeException var9) {
         }
         int var8 = Math.max(0, Math.min(100, (var4.field_1140 - 15000) / 150));
         String var11 = var8 < 15 ? "shallow" : var8 < 40 ? "mid" : var8 < 70 ? "deep" : "abyss";
         String var12 = var11.charAt(0) + var5;
         if (!var1.containsKey(var12)) {
            var1.put(var12, var3);
            String var13 = (var8 < 15 ? "0" : var8 < 40 ? "1" : var8 < 70 ? "2" : "3") + var5;
            var2.put(var13 + " " + var3, var4.field_1133 + "    " + var5 + " " + var8 + "%");
         }
      }
      this.labels = new String[var2.size()];
      this.ids = new int[var2.size()];
      int var14 = 0;
      for (java.util.Map.Entry<String, String> var15 : var2.entrySet()) {
         this.labels[var14] = var15.getValue();
         this.ids[var14] = Integer.parseInt(var15.getKey().substring(var15.getKey().indexOf(' ') + 1));
         var14++;
      }
   }
}
