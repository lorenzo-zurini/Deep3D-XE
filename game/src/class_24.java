// $VF: renamed from: ah
public final class class_24 {
   // $VF: renamed from: a java.lang.String
   private static String field_355 = "/data/v3d/";
   // $VF: renamed from: b java.lang.String
   private static String field_356 = "/data/textures/";
   // $VF: renamed from: a short[]
   public static final short[] field_357 = new short[]{6754, 6755, 6756, 0, 0, 0, 6760, 6761, 6762, 6763, 6764, 6765};
   // $VF: renamed from: b short[]
   public static final short[] field_358 = new short[]{
      4429, 4442, 4426, 4422, 4423, 4430, 4432, 4434, 4440, 4436, 4424, 4438, 4427, 4443, 4444, 4445, 4446, 4447
   };
   // $VF: renamed from: c short[]
   public static final short[] field_359 = new short[]{
      2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 1000, 1000, 15000, 1000, 1000, 1000, 2000
   };
   // $VF: renamed from: d short[]
   public static final short[] field_360 = new short[]{20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 100, 20, 4, 1, 32000, 32000, 5, 10, 15};
   // $VF: renamed from: e short[]
   public static final short[] field_361 = new short[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   // $VF: renamed from: a byte[]
   public static final byte[] field_362 = new byte[]{-1, 60, 76, 11, 31, 0};
   // $VF: renamed from: b byte[]
   public static final byte[] field_363 = new byte[]{85, 58, 75, 12, 93, -1};
   // $VF: renamed from: c byte[]
   public static final byte[] field_364 = new byte[]{87, 80, 68, 16, 50, -1};
   // $VF: renamed from: d byte[]
   public static final byte[] field_365 = new byte[]{85, 81, 68, 21, 44, 3};
   // $VF: renamed from: e byte[]
   public static final byte[] field_366 = new byte[]{85, 60, 76, 11, 36, -1};
   // $VF: renamed from: f byte[]
   public static final byte[] field_367 = new byte[]{84, 83, 71, 25, 46, 3};
   // $VF: renamed from: g byte[]
   public static final byte[] field_368 = new byte[]{85, 82, 65, 25, 43, -1};
   // $VF: renamed from: h byte[]
   public static final byte[] field_369 = new byte[]{86, 78, 69, 20, 51, -1};
   // $VF: renamed from: i byte[]
   public static final byte[] field_370 = new byte[]{84, 28, 71, 23, 52, -1};
   // $VF: renamed from: j byte[]
   public static final byte[] field_371 = new byte[]{86, 83, 68, 16, 48, -1};
   // $VF: renamed from: k byte[]
   public static final byte[] field_372 = new byte[]{87, 83, 70, 20, 41, -1};
   // $VF: renamed from: l byte[]
   public static final byte[] field_373 = new byte[]{85, 82, 69, 26, 47, -1};
   // $VF: renamed from: a byte[][]
   public static final byte[][] field_374 = new byte[][]{
      null, field_362, field_363, field_364, field_365, field_366, field_367, field_368, field_369, field_370, field_371, field_372, field_373
   };
   // $VF: renamed from: a java.lang.String[]
   public static final String[] field_375 = new String[]{
      null, "M.A.I.", "Ayumi", "Raymond", "Pierre", "Leah", "Colonist", "Rebel", "Fenko", "Jack", "Pirate", "Raoul", "Colin"
   };
   // $VF: renamed from: a dn[]
   private static class_51[] field_376;
   // $VF: renamed from: a be[]
   private static class_32[] field_377;
   // $VF: renamed from: a aa[]
   private static class_46[] field_378;
   // $VF: renamed from: a cj[]
   private static class_63[] field_379;

   private class_24() {
   }

   // $VF: renamed from: a () void
   public static final void method_310() {
      field_376 = class_48.method_469();
   }

   // $VF: renamed from: a () dn[]
   public static final class_51[] method_311() {
      return field_376;
   }

   // $VF: renamed from: b () void
   public static final void method_312() {
      field_377 = class_48.method_470();
   }

   // $VF: renamed from: a () be[]
   public static final class_32[] method_313() {
      return field_377;
   }

   // $VF: renamed from: c () void
   public static final void method_314() {
      field_378 = class_48.method_468();
   }

   // $VF: renamed from: a () aa[]
   public static final class_46[] method_315() {
      return field_378;
   }

   // $VF: renamed from: d () void
   public static final void method_316() {
      field_379 = class_48.method_465();
   }

   // $VF: renamed from: a () cj[]
   public static final class_63[] method_317() {
      return field_379;
   }

   // $VF: renamed from: a (int) be
   public static final class_32 method_318(int var0) {
      for (int var1 = 0; var1 < field_361.length; var1++) {
         if (var0 == field_361[var1]) {
            return field_377[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (int, int) int[]
   public static final int[] method_319(int var0, int var1) {
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
   public static final String method_320(int var0, boolean var1) {
      String[] var2;
      return (var2 = class_48.method_471(var0, var1))[class_41.field_540.nextInt(var2.length)];
   }

   // $VF: renamed from: a () int
   public static final int method_321() {
      return field_361[class_41.field_540.nextInt(field_361.length - 1)];
   }

   // $VF: renamed from: e () void
   public static final void method_322() {
      class_25.method_324(1, field_356 + "deep");
      class_25.method_324(2, field_356 + "fx");
      class_25.method_324(0, field_356 + "skybox");
      class_25.method_325(19, field_355 + "aquar", 2000, 2);
      class_25.method_325(0, field_355 + "u0", 2000, 1);
      class_25.method_325(1, field_355 + "u1", 2000, 1);
      class_25.method_325(2, field_355 + "u2", 2000, 1);
      class_25.method_325(3, field_355 + "u3", 2000, 1);
      class_25.method_325(4, field_355 + "u4", 2000, 1);
      class_25.method_325(5, field_355 + "u5", 2000, 1);
      class_25.method_325(6, field_355 + "u6", 2000, 1);
      class_25.method_325(7, field_355 + "u7", 2000, 1);
      class_25.method_325(8, field_355 + "u8", 2000, 1);
      class_25.method_325(9, field_355 + "u9", 2000, 1);
      class_25.method_325(10, field_355 + "u10", 2000, 1);
      class_25.method_325(11, field_355 + "tanker1", 10000, 1);
      class_25.method_325(14, field_355 + "biowaste", 2000, 2);
      class_25.method_325(13, field_355 + "mine", 2000, 1);
      class_25.method_326(9991, field_355 + "skybox", 0);
      class_25.method_325(16, field_355 + "torpedo", 1000, 1);
      class_25.method_325(17, field_355 + "box", 2000, 1);
      class_25.method_325(15, field_355 + "stream", 5000, 1);
      class_25.method_325(4422, field_355 + "manta", 2000, 2);
      class_25.method_325(4424, field_355 + "squid_01", 2000, 2);
      class_25.method_325(4425, field_355 + "squid_02", 2000, 2);
      class_25.method_325(4423, field_355 + "fish_swarm", 2000, 2);
      class_25.method_325(4426, field_355 + "jellyfish", 1000, 2);
      class_25.method_325(4427, field_355 + "whale_01", 10000, 2);
      class_25.method_325(4428, field_355 + "whale_02", 10000, 2);
      class_25.method_325(4429, field_355 + "nautilus", 2000, 2);
      class_25.method_325(4430, field_355 + "anglerfish_01", 2000, 2);
      class_25.method_325(4431, field_355 + "anglerfish_02", 2000, 2);
      class_25.method_325(4432, field_355 + "devilfish_01", 2000, 2);
      class_25.method_325(4433, field_355 + "devilfish_02", 2000, 2);
      class_25.method_325(4442, field_355 + "gulper_eel", 2000, 2);
      class_25.method_325(4434, field_355 + "marlin_01", 2000, 2);
      class_25.method_325(4435, field_355 + "marlin_02", 2000, 2);
      class_25.method_325(4440, field_355 + "shark_01", 2000, 2);
      class_25.method_325(4441, field_355 + "shark_02", 2000, 2);
      class_25.method_325(4436, field_355 + "shrimp_01", 2000, 2);
      class_25.method_325(4437, field_355 + "shrimp_02", 2000, 2);
      class_25.method_325(4438, field_355 + "turtle_01", 2000, 2);
      class_25.method_325(4439, field_355 + "turtle_02", 2000, 2);
      class_25.method_325(4443, field_355 + "alga_gold", 1000, 2);
      class_25.method_325(4444, field_355 + "alga_blue", 1000, 2);
      class_25.method_325(4445, field_355 + "alga_brown", 1000, 2);
      class_25.method_325(4446, field_355 + "alga_red", 1000, 2);
      class_25.method_325(4447, field_355 + "alga_green", 1000, 2);
      class_25.method_325(3300, field_355 + "station_bottom", 15000, 1);
      class_25.method_325(3301, field_355 + "station_bridge_01", 15000, 1);
      class_25.method_325(3310, field_355 + "station_starter", 15000, 1);
      class_25.method_325(3302, field_355 + "station_bridge_02", 15000, 1);
      class_25.method_325(3303, field_355 + "station_cannon", 15000, 1);
      class_25.method_325(3304, field_355 + "station_engine", 15000, 1);
      class_25.method_325(3305, field_355 + "station_habitat_de", 15000, 1);
      class_25.method_325(3306, field_355 + "station_habitat_ve", 15000, 1);
      class_25.method_325(3307, field_355 + "station_hangar_de", 15000, 1);
      class_25.method_325(3308, field_355 + "station_hangar_ve", 15000, 1);
      class_25.method_325(3309, field_355 + "station_sidehabitat", 15000, 1);
      class_25.method_325(3311, field_355 + "station_top", 15000, 1);
      class_25.method_325(9992, field_355 + "explosion", 2000, 2);
      class_25.method_325(9995, field_355 + "fischtod", 2000, 2);
      class_25.method_325(9993, field_355 + "limiter_up", 5000, 2);
      class_25.method_325(9997, field_355 + "limiter_down", 5000, 2);
      class_25.method_325(9994, field_355 + "kapsel", 5000, 1);
      class_25.method_325(9996, field_355 + "trash", 2000, 1);
      class_25.method_325(6768, field_355 + "pfeil", 2000, 2);
      class_25.method_325(6754, field_355 + "laser_0", 2000, 2);
      class_25.method_325(6755, field_355 + "laser_1", 2000, 2);
      class_25.method_325(6756, field_355 + "laser_2", 2000, 2);
      class_25.method_325(6760, field_355 + "laser_6", 2000, 2);
      class_25.method_325(6761, field_355 + "laser_7", 2000, 2);
      class_25.method_325(6762, field_355 + "laser_8", 2000, 2);
      class_25.method_325(6763, field_355 + "laser_9", 2000, 2);
      class_25.method_325(6764, field_355 + "laser_10", 2000, 2);
      class_25.method_325(6765, field_355 + "laser_11", 2000, 2);
      class_25.method_325(6766, field_355 + "eclipse", 2000, 2);
      class_25.method_325(6767, field_355 + "laser_aqua", 2000, 2);
   }

   // $VF: renamed from: f () void
   public static final void method_323() {
      field_377 = null;
      field_376 = null;
      class_25.method_329();
   }

   static {
      short[] var10000 = new short[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
      var10000 = new short[]{2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 10000, 2000, 2000, 2000, 5000, 1000, 2000, 2000, 2000};
      short[][] var1 = new short[][]{{11, 22, 28, 5, 7}, {4, 30}, {3, 14}, {9, 16}};
      short[][] var2 = new short[][]{{11, 22, 28, 5, 7}, {4, 30}, {3, 14}, {9, 16}};
   }
}
