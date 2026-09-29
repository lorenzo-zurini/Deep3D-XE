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
      applyPin();
      // the world drew within the last few loop passes
      idleTicks = worldFrames != tickWorldFrames ? 0 : idleTicks + 1;
      tickWorldFrames = worldFrames;
      worldAlive = idleTicks < 5;
      org.deep3d.Scenario.tick();
   }

   public String scene() {
      class_61 var0 = class_84.field_1126 != null ? class_84.field_1126.field_595 : null;
      if (var0 == null) {
         return "none";
      }
      if (var0 instanceof class_64) {
         // loaded, drawing its world, and not in one of its cutscenes
         if (!flag(var0, "field_786") || !worldAlive) {
            return "flight-loading";
         }
         return flag(var0, "field_795") ? "flight-cutscene" : "flight";
      }
      if (var0 instanceof class_63) {
         return "station";
      }
      if (var0 instanceof class_66) {
         return "title";
      }
      if (var0 instanceof class_62) {
         return "intro";
      }
      return var0.getClass().getName();
   }

   // world render passes (class_26), to tell a drawing flight from a loading one
   public static int worldFrames;
   private static int tickWorldFrames;
   private static int idleTicks;
   private static boolean worldAlive;
   private static final java.util.HashMap<String, java.lang.reflect.Field> FLAGS = new java.util.HashMap<>();

   private static boolean flag(Object var0, String var1) {
      try {
         java.lang.reflect.Field var2 = FLAGS.get(var1);
         if (var2 == null) {
            var2 = class_64.class.getDeclaredField(var1);
            var2.setAccessible(true);
            FLAGS.put(var1, var2);
         }
         return var2.getBoolean(var0);
      } catch (ReflectiveOperationException var3) {
         return false;
      }
   }

   // Test scenarios: a creature or ship held in front of the camera
   private static String pinKind;
   private static class_91 pinned;
   private static int pinDist;
   private static int pinDx;
   private static int pinDy;

   public boolean pin(String var1, int var2, int var3, int var4) {
      if ("off".equals(var1)) {
         pinKind = null;
         pinned = null;
         return true;
      }
      pinKind = var1;
      pinned = null;
      pinDist = var2;
      pinDx = var3;
      pinDy = var4;
      return findPin() != null;
   }

   private static class_26 world() {
      class_61 var0 = class_84.field_1126 != null ? class_84.field_1126.field_595 : null;
      if (!(var0 instanceof class_64)) {
         return null;
      }
      try {
         java.lang.reflect.Field var1 = class_64.class.getDeclaredField("field_799");
         var1.setAccessible(true);
         return (class_26) var1.get(var0);
      } catch (ReflectiveOperationException var2) {
         return null;
      }
   }

   private static class_91 findPin() {
      class_26 var0 = world();
      if (var0 == null || pinKind == null) {
         return null;
      }
      class_91[][] var1 = new class_91[][]{var0.field_273, var0.field_274, var0.field_275};
      for (int var2 = 0; var2 < var1.length; var2++) {
         if (var1[var2] != null) {
            for (int var3 = 0; var3 < var1[var2].length; var3++) {
               class_91 var4 = var1[var2][var3];
               if (var4 != null && var4.field_1226 != null && var4.field_1224 != 3 && var4.field_1224 != 4
                  && ("ship".equals(pinKind) ? var4 instanceof class_96 : var4 instanceof class_101)) {
                  pinned = var4;
                  return var4;
               }
            }
         }
      }
      return null;
   }

   private static void applyPin() {
      if (pinKind == null) {
         return;
      }
      if (pinned == null || pinned.field_1226 == null || world() == null) {
         if (findPin() == null) {
            return;
         }
      }
      if (class_84.field_1110 == null || class_84.field_1110.field_40 == null) {
         return;
      }
      class_3 var0 = class_84.field_1110.field_40.field_1342.method_507(new class_3(pinDx, pinDy, -pinDist), new class_3());
      pinned.field_1226.method_846(var0);
      pinned.field_1226.method_839(true);
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
