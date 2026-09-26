// $VF: renamed from: ai
public final class class_90 {
   // $VF: renamed from: a java.lang.String
   private static String field_1199 = "/data/3d/";
   // $VF: renamed from: b java.lang.String
   private static String field_1200 = "/data/textures/";
   // $VF: renamed from: a short[]
   public static final short[] field_1201 = new short[]{6754, 6755, 6756, 0, 0, 0, 6760, 6761, 6762, 6763, 6764, 6765};
   // $VF: renamed from: b short[]
   public static final short[] field_1202 = new short[]{
      4429, 4442, 4426, 4422, 4423, 4430, 4432, 4434, 4440, 4436, 4424, 4438, 4427, 4443, 4444, 4445, 4446, 4447
   };
   // $VF: renamed from: c short[]
   public static final short[] field_1203 = new short[]{
      2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 1000, 1000, 15000, 1000, 1000, 1000, 2000
   };
   // $VF: renamed from: d short[]
   public static final short[] field_1204 = new short[]{20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 100, 20, 4, 1, 32000, 32000, 5, 10, 15};
   // $VF: renamed from: e short[]
   public static final short[] field_1205 = new short[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   // $VF: renamed from: a byte[]
   public static final byte[] field_1206 = new byte[]{-1, 60, 76, 11, 31, 0};
   // $VF: renamed from: b byte[]
   public static final byte[] field_1207 = new byte[]{85, 58, 75, 12, 93, -1};
   // $VF: renamed from: c byte[]
   public static final byte[] field_1208 = new byte[]{87, 80, 68, 16, 50, -1};
   // $VF: renamed from: d byte[]
   public static final byte[] field_1209 = new byte[]{85, 81, 68, 21, 44, 3};
   // $VF: renamed from: e byte[]
   public static final byte[] field_1210 = new byte[]{85, 60, 76, 11, 36, -1};
   // $VF: renamed from: f byte[]
   public static final byte[] field_1211 = new byte[]{84, 83, 71, 25, 46, 3};
   // $VF: renamed from: g byte[]
   public static final byte[] field_1212 = new byte[]{85, 82, 65, 25, 43, -1};
   // $VF: renamed from: h byte[]
   public static final byte[] field_1213 = new byte[]{86, 78, 69, 20, 51, -1};
   // $VF: renamed from: i byte[]
   public static final byte[] field_1214 = new byte[]{84, 28, 71, 23, 52, -1};
   // $VF: renamed from: j byte[]
   public static final byte[] field_1215 = new byte[]{86, 83, 68, 16, 48, -1};
   // $VF: renamed from: k byte[]
   public static final byte[] field_1216 = new byte[]{87, 83, 70, 20, 41, -1};
   // $VF: renamed from: l byte[]
   public static final byte[] field_1217 = new byte[]{85, 82, 69, 26, 47, -1};
   // $VF: renamed from: a byte[][]
   public static final byte[][] field_1218 = new byte[][]{
      null, field_1206, field_1207, field_1208, field_1209, field_1210, field_1211, field_1212, field_1213, field_1214, field_1215, field_1216, field_1217
   };
   // $VF: renamed from: a java.lang.String[]
   public static final String[] field_1219 = new String[]{
      null, "M.A.I.", "Ayumi", "Raymond", "Pierre", "Leah", "Colonist", "Rebel", "Fenko", "Jack", "Pirate", "Raoul", "Colin"
   };
   // $VF: renamed from: a dn[]
   private static class_19[] field_1220;
   // $VF: renamed from: a bd[]
   private static class_68[] field_1221;
   // $VF: renamed from: a ac[]
   private static class_120[] field_1222;
   // $VF: renamed from: a cj[]
   private static class_40[] field_1223;

   private class_90() {
   }

   // $VF: renamed from: a () void
   public static final void method_780() {
      field_1220 = class_49.method_406();
   }

   // $VF: renamed from: a () dn[]
   public static final class_19[] method_781() {
      return field_1220;
   }

   // $VF: renamed from: b () void
   public static final void method_782() {
      field_1221 = class_49.method_407();
   }

   // $VF: renamed from: a () bd[]
   public static final class_68[] method_783() {
      return field_1221;
   }

   // $VF: renamed from: c () void
   public static final void method_784() {
      field_1222 = class_49.method_405();
   }

   // $VF: renamed from: a () ac[]
   public static final class_120[] method_785() {
      return field_1222;
   }

   // $VF: renamed from: d () void
   public static final void method_786() {
      field_1223 = class_49.method_402();
   }

   // $VF: renamed from: a () cj[]
   public static final class_40[] method_787() {
      return field_1223;
   }

   // $VF: renamed from: a (int) bd
   public static final class_68 method_788(int var0) {
      for (int var1 = 0; var1 < field_1205.length; var1++) {
         if (var0 == field_1205[var1]) {
            return field_1221[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (int, int) int[]
   public static final int[] method_789(int var0, int var1) {
      if (var1 != 0 && var1 != 1 && var1 != 2) {
         return null;
      } else {
         switch (var0) {
            case 0:
            case 1:
            case 3:
            case 9:
            case 10:
            case 11:
               if (var1 == 0) {
                  return new int[]{0, 0};
               } else {
                  if (var1 == 1) {
                     return new int[]{1, 1};
                  }

                  return new int[]{2, 2};
               }
            case 2:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
               if (var1 == 0) {
                  return new int[]{0, 2};
               } else {
                  if (var1 == 1) {
                     return new int[]{3, 5};
                  }

                  return new int[]{6, 8};
               }
            default:
               return null;
         }
      }
   }

   // $VF: renamed from: a (int, boolean) java.lang.String
   public static final String method_790(int var0, boolean var1) {
      String[] var2;
      return (var2 = class_49.method_408(var0, var1))[class_84.field_1123.nextInt(var2.length)];
   }

   // $VF: renamed from: a () int
   public static final int method_791() {
      return field_1205[class_84.field_1123.nextInt(field_1205.length - 1)];
   }

   // $VF: renamed from: e () void
   public static final void method_792() {
      class_43.method_377(1, field_1200 + "deep");
      class_43.method_377(2, field_1200 + "fx");
      class_43.method_377(0, field_1200 + "skybox");
      class_43.method_378(19, field_1199 + "aquar", 2000, 2);
      class_43.method_378(0, field_1199 + "u0", 2000, 1);
      class_43.method_378(1, field_1199 + "u1", 2000, 1);
      class_43.method_378(2, field_1199 + "u2", 2000, 1);
      class_43.method_378(3, field_1199 + "u3", 2000, 1);
      class_43.method_378(4, field_1199 + "u4", 2000, 1);
      class_43.method_378(5, field_1199 + "u5", 2000, 1);
      class_43.method_378(6, field_1199 + "u6", 2000, 1);
      class_43.method_378(7, field_1199 + "u7", 2000, 1);
      class_43.method_378(8, field_1199 + "u8", 2000, 1);
      class_43.method_378(9, field_1199 + "u9", 2000, 1);
      class_43.method_378(10, field_1199 + "u10", 2000, 1);
      class_43.method_378(11, field_1199 + "tanker1", 10000, 1);
      class_43.method_378(14, field_1199 + "biowaste", 2000, 2);
      class_43.method_378(13, field_1199 + "mine", 2000, 1);
      class_43.method_379(9991, field_1199 + "skybox", 0);
      class_43.method_378(16, field_1199 + "torpedo", 1000, 1);
      class_43.method_378(17, field_1199 + "box", 2000, 1);
      class_43.method_378(15, field_1199 + "stream", 5000, 1);
      class_43.method_378(4422, field_1199 + "manta", 2000, 2);
      class_43.method_378(4424, field_1199 + "squid_01", 2000, 2);
      class_43.method_378(4425, field_1199 + "squid_02", 2000, 2);
      class_43.method_378(4423, field_1199 + "fish_swarm", 2000, 2);
      class_43.method_378(4426, field_1199 + "jellyfish", 1000, 2);
      class_43.method_378(4427, field_1199 + "whale_01", 10000, 2);
      class_43.method_378(4428, field_1199 + "whale_02", 10000, 2);
      class_43.method_378(4429, field_1199 + "nautilus", 2000, 2);
      class_43.method_378(4430, field_1199 + "anglerfish_01", 2000, 2);
      class_43.method_378(4431, field_1199 + "anglerfish_02", 2000, 2);
      class_43.method_378(4432, field_1199 + "devilfish_01", 2000, 2);
      class_43.method_378(4433, field_1199 + "devilfish_02", 2000, 2);
      class_43.method_378(4442, field_1199 + "gulper_eel", 2000, 2);
      class_43.method_378(4434, field_1199 + "marlin_01", 2000, 2);
      class_43.method_378(4435, field_1199 + "marlin_02", 2000, 2);
      class_43.method_378(4440, field_1199 + "shark_01", 2000, 2);
      class_43.method_378(4441, field_1199 + "shark_02", 2000, 2);
      class_43.method_378(4436, field_1199 + "shrimp_01", 2000, 2);
      class_43.method_378(4437, field_1199 + "shrimp_02", 2000, 2);
      class_43.method_378(4438, field_1199 + "turtle_01", 2000, 2);
      class_43.method_378(4439, field_1199 + "turtle_02", 2000, 2);
      class_43.method_378(4443, field_1199 + "alga_gold", 1000, 2);
      class_43.method_378(4444, field_1199 + "alga_blue", 1000, 2);
      class_43.method_378(4445, field_1199 + "alga_brown", 1000, 2);
      class_43.method_378(4446, field_1199 + "alga_red", 1000, 2);
      class_43.method_378(4447, field_1199 + "alga_green", 1000, 2);
      class_43.method_378(3300, field_1199 + "station_bottom", 15000, 1);
      class_43.method_378(3301, field_1199 + "station_bridge_01", 15000, 1);
      class_43.method_378(3310, field_1199 + "station_starter", 15000, 1);
      class_43.method_378(3302, field_1199 + "station_bridge_02", 15000, 1);
      class_43.method_378(3303, field_1199 + "station_cannon", 15000, 1);
      class_43.method_378(3304, field_1199 + "station_engine", 15000, 1);
      class_43.method_378(3305, field_1199 + "station_habitat_de", 15000, 1);
      class_43.method_378(3306, field_1199 + "station_habitat_ve", 15000, 1);
      class_43.method_378(3307, field_1199 + "station_hangar_de", 15000, 1);
      class_43.method_378(3308, field_1199 + "station_hangar_ve", 15000, 1);
      class_43.method_378(3309, field_1199 + "station_sidehabitat", 15000, 1);
      class_43.method_378(3311, field_1199 + "station_top", 15000, 1);
      class_43.method_378(9992, field_1199 + "explosion", 2000, 2);
      class_43.method_378(9995, field_1199 + "fischtod", 2000, 2);
      class_43.method_378(9993, field_1199 + "limiter_up", 5000, 2);
      class_43.method_378(9997, field_1199 + "limiter_down", 5000, 2);
      class_43.method_378(9994, field_1199 + "kapsel", 5000, 1);
      class_43.method_378(9996, field_1199 + "trash", 2000, 1);
      class_43.method_378(6768, field_1199 + "pfeil", 2000, 2);
      class_43.method_378(6754, field_1199 + "laser_0", 2000, 2);
      class_43.method_378(6755, field_1199 + "laser_1", 2000, 2);
      class_43.method_378(6756, field_1199 + "laser_2", 2000, 2);
      class_43.method_378(6760, field_1199 + "laser_6", 2000, 2);
      class_43.method_378(6761, field_1199 + "laser_7", 2000, 2);
      class_43.method_378(6762, field_1199 + "laser_8", 2000, 2);
      class_43.method_378(6763, field_1199 + "laser_9", 2000, 2);
      class_43.method_378(6764, field_1199 + "laser_10", 2000, 2);
      class_43.method_378(6765, field_1199 + "laser_11", 2000, 2);
      class_43.method_378(6766, field_1199 + "eclipse", 2000, 2);
      class_43.method_378(6767, field_1199 + "laser_aqua", 2000, 2);
   }

   // $VF: renamed from: f () void
   public static final void method_793() {
      field_1221 = null;
      field_1220 = null;
      class_43.method_382();
   }

   static {
      short[] var10000 = new short[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
      var10000 = new short[]{2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 10000, 2000, 2000, 2000, 5000, 1000, 2000, 2000, 2000};
      short[][] var1 = new short[][]{{11, 22, 28, 5, 7}, {4, 30}, {3, 14}, {9, 16}};
      short[][] var2 = new short[][]{{11, 22, 28, 5, 7}, {4, 30}, {3, 14}, {9, 16}};
   }
}
