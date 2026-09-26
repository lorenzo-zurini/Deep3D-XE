// $VF: renamed from: f
public final class class_14 {
   // $VF: renamed from: a int[][]
   public static final int[][] field_135 = new int[][]{
      {0},
      {5, 15, 30},
      {0},
      {0},
      {400, 200, 50},
      {300, 150, 50},
      {200, 100, 50},
      {0},
      {500, 250, 50},
      {15, 10, 5},
      {15, 10, 5},
      {10, 7, 5},
      {50, 25, 10},
      {300, 150, 50},
      {350, 150, 25},
      {0},
      {8, 5, 3},
      {0},
      {350, 150, 25},
      {1000000, 500000, 125000},
      {20, 10, 5},
      {10000, 12000, 15000},
      {35000, 32000, 30000},
      {0}
   };
   // $VF: renamed from: a int[]
   private static int[] field_136 = new int[field_135.length];
   // $VF: renamed from: b int[]
   private static int[] field_137 = new int[field_135.length];
   // $VF: renamed from: a int
   private static int field_138;
   // $VF: renamed from: b int
   private static int field_139;
   // $VF: renamed from: c int
   private static int field_140;
   // $VF: renamed from: d int
   private static int field_141;
   // $VF: renamed from: e int
   private static int field_142;
   // $VF: renamed from: f int
   private static int field_143;
   // $VF: renamed from: a boolean
   private static boolean field_144;
   // $VF: renamed from: b boolean
   private static boolean field_145;
   // $VF: renamed from: g int
   private static int field_146;
   // $VF: renamed from: h int
   private static int field_147;

   // $VF: renamed from: a (ba) void
   public static final void method_67(class_70 var0) {
      method_81();

      for (int var1 = 0; var1 < field_135.length; var1++) {
         int var2 = 0;
         if (field_136[var1] != 1) {
            for (int var3 = 0; var3 < field_135[var1].length && var2 <= 0; var3++) {
               boolean var4;
               var4 = false;
               label192:
               switch (var1) {
                  case 1:
                     var4 = var0.method_660() <= field_135[var1][var3];
                     break;
                  case 2:
                     boolean[] var9;
                     var4 = (var9 = class_21.method_168())[13] && var9[14] && var9[15] && var9[16] && var9[17];
                     break;
                  case 3:
                     boolean[] var5 = class_21.method_168();
                     var4 = true;

                     for (int var10 = 0; var10 < var5.length; var10++) {
                        if ((var10 < 13 || var10 > 17) && !var5[var10]) {
                           var4 = false;
                           break label192;
                        }
                     }
                     break;
                  case 4:
                     var4 = class_21.method_202() >= field_135[var1][var3];
                     break;
                  case 5:
                     var4 = class_21.method_170() >= field_135[var1][var3];
                     break;
                  case 6:
                     var4 = class_21.method_177() >= field_135[var1][var3];
                     break;
                  case 7:
                     class_120[] var6 = class_90.method_785();
                     boolean[] var7 = class_21.method_195();
                     var4 = true;

                     for (int var11 = 0; var11 < var7.length; var11++) {
                        if (var6[var11].field_1488 != null && !var7[var11]) {
                           var4 = false;
                           break label192;
                        }
                     }
                     break;
                  case 8:
                     var4 = class_21.method_191() >= field_135[var1][var3];
                     break;
                  case 9:
                     var4 = field_138 >= field_135[var1][var3];
                     break;
                  case 10:
                     var4 = field_139 >= field_135[var1][var3];
                     break;
                  case 11:
                     var4 = class_21.method_212() >= field_135[var1][var3] * 3600000;
                     break;
                  case 12:
                     var4 = class_21.method_209() >= field_135[var1][var3];
                     break;
                  case 13:
                     var4 = class_21.method_151() >= field_135[var1][var3];
                     break;
                  case 14:
                     var4 = class_21.method_205() >= field_135[var1][var3];
                     break;
                  case 15:
                     var4 = field_141 == 0;
                     break;
                  case 16:
                     var4 = field_141 >= field_135[var1][var3];
                     break;
                  case 17:
                     var4 = class_21.method_146();
                     break;
                  case 18:
                     var4 = class_21.method_154() >= field_135[var1][var3];
                     break;
                  case 19:
                     var4 = field_143 >= field_135[var1][var3];
                     break;
                  case 20:
                     var4 = class_21.method_158() >= field_135[var1][var3];
                     break;
                  case 21:
                     var4 = class_21.method_160() <= field_135[var1][var3];
                     break;
                  case 22:
                     var4 = class_21.method_159() >= field_135[var1][var3];
                     break;
                  case 23:
                     var4 = true;

                     for (int var8 = 0; var8 < field_136.length - 1; var8++) {
                        if (field_136[var8] == 0) {
                           var4 = false;
                           break;
                        }
                     }
               }

               if (var4) {
                  var2 = var3 + 1;
               }
            }
         }

         if (field_136[var1] > var2 || field_136[var1] == 0) {
            field_137[var1] = var2;
         }
      }
   }

   // $VF: renamed from: h () void
   private static void method_68() {
      field_147 = 0;
      field_146 = 0;

      for (int var0 = 0; var0 < field_136.length; var0++) {
         if (field_136[var0] == 1) {
            field_147++;
            field_146++;
         } else if (field_136[var0] != 0) {
            field_147++;
         }
      }

      field_144 = field_147 == field_136.length;
      field_145 = field_146 == field_136.length;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_69() {
      return field_144;
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_70() {
      return field_145;
   }

   // $VF: renamed from: a () int[]
   public static final int[] method_71() {
      return field_136;
   }

   // $VF: renamed from: b () int[]
   public static final int[] method_72() {
      return field_137;
   }

   // $VF: renamed from: a () void
   public static final void method_73() {
      field_138++;
   }

   // $VF: renamed from: a () int
   public static final int method_74() {
      return field_138;
   }

   // $VF: renamed from: b () void
   public static final void method_75() {
      field_140++;
   }

   // $VF: renamed from: b () int
   public static final int method_76() {
      return field_140;
   }

   // $VF: renamed from: c () void
   public static final void method_77() {
      field_140 = 0;
   }

   // $VF: renamed from: d () void
   public static final void method_78() {
      field_139++;
   }

   // $VF: renamed from: c () int
   public static final int method_79() {
      return field_139;
   }

   // $VF: renamed from: a (int) void
   public static final void method_80(int var0) {
      if (var0 > field_143) {
         field_143 = var0;
      }

      if (var0 < field_142) {
         field_142 = var0;
      }
   }

   // $VF: renamed from: i () void
   private static void method_81() {
      if (class_21.method_143() <= 3) {
         field_141 = 1;
      } else {
         class_19[] var0;
         if ((var0 = class_21.method_178().field_885) != null) {
            for (int var1 = 0; var1 < var0.length; var1++) {
               if (var0[var1] != null && (var0[var1].field_165 == 0 || var0[var1].field_165 == 1)) {
                  field_141++;
               }
            }
         }
      }
   }

   // $VF: renamed from: a (int[]) void
   public static final void method_82(int[] var0) {
      field_136 = var0;
   }

   // $VF: renamed from: e () void
   public static final void method_83() {
      for (int var0 = 0; var0 < field_136.length; var0++) {
         field_136[var0] = 0;
      }

      field_136[0] = 1;
      method_85();
      field_143 = 0;
      field_142 = 1000000;
   }

   // $VF: renamed from: f () void
   public static final void method_84() {
      for (int var0 = 0; var0 < field_136.length; var0++) {
         if (field_137[var0] > 0 && (field_137[var0] < field_136[var0] || field_136[var0] == 0)) {
            field_136[var0] = field_137[var0];
         }
      }

      method_68();
      if (field_147 == field_136.length - 1) {
         field_137[23] = 1;
         field_136[23] = 1;
         method_68();
      }
   }

   // $VF: renamed from: g () void
   public static final void method_85() {
      for (int var0 = 0; var0 < field_137.length; var0++) {
         field_137[var0] = 0;
      }

      field_138 = 0;
      field_139 = 0;
      field_140 = 0;
      field_141 = 0;
   }
}
