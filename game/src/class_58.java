// $VF: renamed from: f
public final class class_58 {
   // $VF: renamed from: a int[][]
   public static final int[][] field_805 = new int[][]{
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
   private static int[] field_806 = new int[field_805.length];
   // $VF: renamed from: b int[]
   private static int[] field_807 = new int[field_805.length];
   // $VF: renamed from: a int
   private static int field_808;
   // $VF: renamed from: b int
   private static int field_809;
   // $VF: renamed from: c int
   private static int field_810;
   // $VF: renamed from: d int
   private static int field_811;
   // $VF: renamed from: e int
   private static int field_812;
   // $VF: renamed from: f int
   private static int field_813;
   // $VF: renamed from: a boolean
   private static boolean field_814;
   // $VF: renamed from: b boolean
   private static boolean field_815;
   // $VF: renamed from: g int
   private static int field_816;
   // $VF: renamed from: h int
   private static int field_817;

   // $VF: renamed from: a (bb) void
   public static final void method_562(class_16 var0) {
      method_576();

      for (int var1 = 0; var1 < field_805.length; var1++) {
         int var2 = 0;
         if (field_806[var1] != 1) {
            for (int var3 = 0; var3 < field_805[var1].length && var2 <= 0; var3++) {
               boolean var4;
               var4 = false;
               label192:
               switch (var1) {
                  case 1:
                     var4 = var0.method_241() <= field_805[var1][var3];
                     break;
                  case 2:
                     boolean[] var9;
                     var4 = (var9 = class_3.method_98())[13] && var9[14] && var9[15] && var9[16] && var9[17];
                     break;
                  case 3:
                     boolean[] var5 = class_3.method_98();
                     var4 = true;

                     for (int var10 = 0; var10 < var5.length; var10++) {
                        if ((var10 < 13 || var10 > 17) && !var5[var10]) {
                           var4 = false;
                           break label192;
                        }
                     }
                     break;
                  case 4:
                     var4 = class_3.method_132() >= field_805[var1][var3];
                     break;
                  case 5:
                     var4 = class_3.method_100() >= field_805[var1][var3];
                     break;
                  case 6:
                     var4 = class_3.method_107() >= field_805[var1][var3];
                     break;
                  case 7:
                     class_46[] var6 = class_24.method_315();
                     boolean[] var7 = class_3.method_125();
                     var4 = true;

                     for (int var11 = 0; var11 < var7.length; var11++) {
                        if (var6[var11].field_634 != null && !var7[var11]) {
                           var4 = false;
                           break label192;
                        }
                     }
                     break;
                  case 8:
                     var4 = class_3.method_121() >= field_805[var1][var3];
                     break;
                  case 9:
                     var4 = field_808 >= field_805[var1][var3];
                     break;
                  case 10:
                     var4 = field_809 >= field_805[var1][var3];
                     break;
                  case 11:
                     var4 = class_3.method_142() >= field_805[var1][var3] * 3600000;
                     break;
                  case 12:
                     var4 = class_3.method_139() >= field_805[var1][var3];
                     break;
                  case 13:
                     var4 = class_3.method_81() >= field_805[var1][var3];
                     break;
                  case 14:
                     var4 = class_3.method_135() >= field_805[var1][var3];
                     break;
                  case 15:
                     var4 = field_811 == 0;
                     break;
                  case 16:
                     var4 = field_811 >= field_805[var1][var3];
                     break;
                  case 17:
                     var4 = class_3.method_76();
                     break;
                  case 18:
                     var4 = class_3.method_84() >= field_805[var1][var3];
                     break;
                  case 19:
                     var4 = field_813 >= field_805[var1][var3];
                     break;
                  case 20:
                     var4 = class_3.method_88() >= field_805[var1][var3];
                     break;
                  case 21:
                     var4 = class_3.method_90() <= field_805[var1][var3];
                     break;
                  case 22:
                     var4 = class_3.method_89() >= field_805[var1][var3];
                     break;
                  case 23:
                     var4 = true;

                     for (int var8 = 0; var8 < field_806.length - 1; var8++) {
                        if (field_806[var8] == 0) {
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

         if (field_806[var1] > var2 || field_806[var1] == 0) {
            field_807[var1] = var2;
         }
      }
   }

   // $VF: renamed from: h () void
   private static void method_563() {
      field_817 = 0;
      field_816 = 0;

      for (int var0 = 0; var0 < field_806.length; var0++) {
         if (field_806[var0] == 1) {
            field_817++;
            field_816++;
         } else if (field_806[var0] != 0) {
            field_817++;
         }
      }

      field_814 = field_817 == field_806.length;
      field_815 = field_816 == field_806.length;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_564() {
      return field_814;
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_565() {
      return field_815;
   }

   // $VF: renamed from: a () int[]
   public static final int[] method_566() {
      return field_806;
   }

   // $VF: renamed from: b () int[]
   public static final int[] method_567() {
      return field_807;
   }

   // $VF: renamed from: a () void
   public static final void method_568() {
      field_808++;
   }

   // $VF: renamed from: a () int
   public static final int method_569() {
      return field_808;
   }

   // $VF: renamed from: b () void
   public static final void method_570() {
      field_810++;
   }

   // $VF: renamed from: b () int
   public static final int method_571() {
      return field_810;
   }

   // $VF: renamed from: c () void
   public static final void method_572() {
      field_810 = 0;
   }

   // $VF: renamed from: d () void
   public static final void method_573() {
      field_809++;
   }

   // $VF: renamed from: c () int
   public static final int method_574() {
      return field_809;
   }

   // $VF: renamed from: a (int) void
   public static final void method_575(int var0) {
      if (var0 > field_813) {
         field_813 = var0;
      }

      if (var0 < field_812) {
         field_812 = var0;
      }
   }

   // $VF: renamed from: i () void
   private static void method_576() {
      if (class_3.method_73() <= 3) {
         field_811 = 1;
      } else {
         class_51[] var0;
         if ((var0 = class_3.method_108().field_444) != null) {
            for (int var1 = 0; var1 < var0.length; var1++) {
               if (var0[var1] != null && (var0[var1].field_710 == 0 || var0[var1].field_710 == 1)) {
                  field_811++;
               }
            }
         }
      }
   }

   // $VF: renamed from: a (int[]) void
   public static final void method_577(int[] var0) {
      field_806 = var0;
   }

   // $VF: renamed from: e () void
   public static final void method_578() {
      for (int var0 = 0; var0 < field_806.length; var0++) {
         field_806[var0] = 0;
      }

      field_806[0] = 1;
      method_580();
      field_813 = 0;
      field_812 = 1000000;
   }

   // $VF: renamed from: f () void
   public static final void method_579() {
      for (int var0 = 0; var0 < field_806.length; var0++) {
         if (field_807[var0] > 0 && (field_807[var0] < field_806[var0] || field_806[var0] == 0)) {
            field_806[var0] = field_807[var0];
         }
      }

      method_563();
      if (field_817 == field_806.length - 1) {
         field_807[23] = 1;
         field_806[23] = 1;
         method_563();
      }
   }

   // $VF: renamed from: g () void
   public static final void method_580() {
      for (int var0 = 0; var0 < field_807.length; var0++) {
         field_807[var0] = 0;
      }

      field_808 = 0;
      field_809 = 0;
      field_810 = 0;
      field_811 = 0;
   }
}
