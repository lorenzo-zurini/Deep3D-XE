import javax.microedition.lcdui.Image;

// $VF: renamed from: dj
public final class class_3 {
   // $VF: renamed from: a java.lang.String
   private static String field_30 = "Player";
   // $VF: renamed from: a byte[]
   private static byte[] field_31 = null;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_32 = null;
   // $VF: renamed from: d int
   private static int field_33;
   // $VF: renamed from: e int
   private static int field_34;
   // $VF: renamed from: b long
   private static long field_35;
   // $VF: renamed from: f int
   private static int field_36;
   // $VF: renamed from: g int
   private static int field_37;
   // $VF: renamed from: h int
   private static int field_38;
   // $VF: renamed from: i int
   private static int field_39;
   // $VF: renamed from: j int
   private static int field_40;
   // $VF: renamed from: k int
   private static int field_41 = 1;
   // $VF: renamed from: l int
   private static int field_42;
   // $VF: renamed from: m int
   private static int field_43;
   // $VF: renamed from: n int
   private static int field_44;
   // $VF: renamed from: o int
   private static int field_45;
   // $VF: renamed from: p int
   private static int field_46;
   // $VF: renamed from: q int
   private static int field_47;
   // $VF: renamed from: r int
   private static int field_48;
   // $VF: renamed from: s int
   private static int field_49;
   // $VF: renamed from: t int
   private static int field_50;
   // $VF: renamed from: u int
   private static int field_51;
   // $VF: renamed from: v int
   private static int field_52;
   // $VF: renamed from: a boolean[]
   private static boolean[] field_53 = new boolean[class_24.field_358.length];
   // $VF: renamed from: b boolean[]
   private static boolean[] field_54 = new boolean[42];
   // $VF: renamed from: c boolean[]
   private static boolean[] field_55 = new boolean[200];
   // $VF: renamed from: a be
   private static class_32 field_56;
   // $VF: renamed from: a al
   private static class_95 field_57;
   // $VF: renamed from: a al[]
   private static class_95[] field_58 = new class_95[2];
   // $VF: renamed from: a an
   private static class_60 field_59;
   // $VF: renamed from: a an[]
   private static class_60[] field_60 = new class_60[3];
   // $VF: renamed from: a int
   public static int field_61;
   // $VF: renamed from: b int
   public static int field_62;
   // $VF: renamed from: c int
   public static int field_63;
   // $VF: renamed from: a long
   public static long field_64;

   // $VF: renamed from: a () an[]
   public static final class_60[] method_57() {
      return field_60;
   }

   // $VF: renamed from: a (an[]) void
   public static final void method_58(class_60[] var0) {
      field_60 = var0;
   }

   // $VF: renamed from: a (an) boolean
   public static final boolean method_59(class_60 var0) {
      class_60 var1;
      if ((var1 = method_60(var0)) != null) {
         field_59 = var1;
         return false;
      } else if (field_60[0] == null) {
         for (int var3 = 2; var3 >= 0; var3--) {
            if (field_60[var3] == null) {
               field_60[var3] = var0;
               field_59 = var0;
               return true;
            }
         }

         return false;
      } else {
         for (int var2 = 2; var2 > 0; var2--) {
            field_60[var2] = field_60[var2 - 1];
         }

         field_60[0] = var0;
         field_59 = var0;
         return true;
      }
   }

   // $VF: renamed from: a (an) an
   public static final class_60 method_60(class_60 var0) {
      for (int var1 = 0; var1 < 3; var1++) {
         if (field_60[var1] != null && field_60[var1].method_593(var0)) {
            return field_60[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (an) void
   public static final void method_61(class_60 var0) {
      if (method_60(var0) == null) {
         var0.field_836 = class_9.method_201(var0);
         var0.field_837 = class_9.method_203(var0);
         var0.field_835 = class_9.method_202(var0);
         var0.field_838 = class_9.method_206(var0);
      }

      method_59(var0);
      field_64 = method_142();
      method_63(class_95.field_1225);

      for (int var2 = 0; var2 < field_58.length; var2++) {
         if (field_58[var2] != null
            && field_58[var2].field_1232 == var0.field_828
            && field_58[var2].field_1226 != 13
            && field_58[var2].field_1226 != 14
            && field_58[var2].field_1226 != 21
            && field_58[var2].field_1226 != 18
            && field_58[var2].field_1226 != 16
            && field_58[var2].field_1226 != 15) {
            if ((field_58[var2].field_1236 < field_58[var2].field_1235 || field_58[var2].field_1235 < 0)
               && (field_58[var2].field_1241 || field_58[var2].field_1226 != 8)) {
               if (method_73() == 5 && field_58[var2].field_1241) {
                  field_58[var2].field_1251 = true;
               }

               method_63(field_58[var2]);
               return;
            }
            break;
         }
      }
   }

   // $VF: renamed from: a () al
   public static final class_95 method_62() {
      return field_57;
   }

   // $VF: renamed from: a (al) void
   public static final void method_63(class_95 var0) {
      field_57 = var0;
   }

   // $VF: renamed from: a () al[]
   public static final class_95[] method_64() {
      return field_58;
   }

   // $VF: renamed from: b () al
   public static final class_95 method_65() {
      return field_58[1];
   }

   // $VF: renamed from: b (al) void
   public static final void method_66(class_95 var0) {
      field_58[1] = var0;
   }

   // $VF: renamed from: c () al
   public static final class_95 method_67() {
      return field_58[0];
   }

   // $VF: renamed from: c (al) void
   public static final void method_68(class_95 var0) {
      var0.field_1241 = true;
      field_58[0] = var0;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_69() {
      return field_58[1] != null && !field_58[1].method_789() && field_58[1].method_797();
   }

   // $VF: renamed from: a () void
   public static final void method_70() {
      if (field_58[1] != null) {
         field_58[1].method_795();
      }
   }

   // $VF: renamed from: b () void
   public static final void method_71() {
      field_40++;
   }

   // $VF: renamed from: a (int) void
   public static final void method_72(int var0) {
      field_52 = var0;
   }

   // $VF: renamed from: a () int
   public static final int method_73() {
      return field_52;
   }

   // $VF: renamed from: a (int[]) void
   public static final void method_74(int[] var0) {
      if (var0 != null) {
         for (int var1 = 0; var1 < var0.length; var1++) {
            field_55[var0[var1]] = true;
         }
      }
   }

   // $VF: renamed from: c () void
   public static final void method_75() {
      field_52++;
      switch (field_52) {
         case 1:
            method_68(new class_95(20, 0, 0));
            method_67().field_1250 = 1;
            return;
         case 2:
            method_68(new class_95(8, 0, 0));
            return;
         case 3:
            method_68(new class_95(17, 0, 0));
            method_67().field_1250 = 0;
            method_67().field_1251 = false;
            return;
         case 4:
            method_68(new class_95(22, 0, 0));
            return;
         case 5:
            method_68(new class_95(3, 0, 1));
            method_67().field_1251 = false;
            return;
         case 6:
            method_68(new class_95(8, 0, 0));
            return;
         case 7:
            method_68(new class_95(7, 0, 1));
            method_67().method_790(0, 5, 0);
            return;
         case 8:
            method_68(new class_95(8, 1000, 1));
            return;
         case 9:
            method_68(new class_95(15, 0, 2));
            method_67().field_1250 = field_40 + 3;
            method_67().field_1251 = false;
            return;
         case 10:
            method_68(new class_95(11, 0, 2));
            method_67().method_790(0, 10, 5);
            return;
         case 11:
            method_68(new class_95(8, 0, 2));
            method_74(new int[]{3});
            return;
         case 12:
            method_68(new class_95(8, 0, 3));
            method_74(new int[]{4});
            return;
         case 13:
            method_68(new class_95(8, 0, 4));
            method_74(new int[]{90});
            return;
         case 14:
            method_68(new class_95(8, 0, 5));
            method_74(new int[]{80, 47});
            return;
         case 15:
            method_68(new class_95(21, 0, 5));
            method_67().field_1250 = field_44 + 5;
            method_67().field_1251 = false;
            method_74(new int[]{80, 47});
            return;
         case 16:
            method_68(new class_95(18, 0, 0));
            method_67().field_1251 = false;
            method_67().field_1250 = class_124.method_943(method_107() + 5, 200);
            return;
         case 17:
            method_68(new class_95(8, 0, 3));
            method_74(new int[]{6, 12, 106, 180});
            return;
         case 18:
            method_68(new class_95(8, 0, 6));
            method_67().field_1251 = false;
            return;
         case 19:
            method_68(new class_95(6, 2000, 7));
            method_67().method_790(10, 30, 15);
            method_74(new int[]{8, 28, 35});
            return;
         case 20:
            method_68(new class_95(8, 0, 6));
            return;
         case 21:
            method_68(new class_95(3, 5000, 8));
            return;
         case 22:
            method_68(new class_95(8, 0, 9));
            method_74(new int[]{9, 159, 20, 110, 89, 5, 117, 37});
            return;
         case 23:
            method_68(new class_95(10, 0, 9));
            return;
         case 24:
            method_68(new class_95(8, 0, 9));
            method_74(new int[]{22, 57, 14, 75, 63, 186, 131, 175, 140, 189, 54, 74, 81, 25, 149, 96});
            return;
         case 25:
            method_68(new class_95(5, 0, 10));
            return;
         case 26:
            method_68(new class_95(16, 0, 0));
            method_67().field_1251 = false;
            method_67().field_1250 = method_132() + 10;
            return;
         case 27:
            method_68(new class_95(2, 0, 11));
            method_74(new int[]{82, 133, 38, 166, 39, 161, 135, 196, 53, 125, 174, 36});
            return;
         case 28:
            method_68(new class_95(8, 0, 12));
            return;
         case 29:
            method_68(new class_95(4, 5000, 13));
            return;
         case 30:
            method_68(new class_95(8, 0, 14));
            method_74(new int[]{15, 114, 170, 181, 115, 69, 190, 162, 146, 70, 151, 59, 167, 191, 86, 44, 71, 95, 72, 31, 16, 32, 160, 61});
            return;
         case 31:
            method_68(new class_95(1, 0, 2));
            return;
         case 32:
            method_68(new class_95(8, 100000, 14));
            return;
         case 33:
            method_68(new class_95(8, 0, 15));
            return;
         case 34:
            method_68(new class_95(13, 0, 15));
            method_67().method_791(37, 1);
            method_74(new int[]{83, 116, 55, 171, 103, 156, 172, 127, 43, 13, 76, 141, 40, 45, 124, 49, 48, 165, 154, 148, 107, 16});
            return;
         case 35:
            method_68(new class_95(0, 0, 15));
            return;
         case 36:
            method_68(new class_95(8, 0, 15));
            method_74(new int[]{19, 143, 64, 120, 188, 126, 119, 34, 145, 66, 98, 144, 155, 104, 52, 26, 78, 29, 108, 164, 132, 185, 27, 100});
            return;
         case 37:
            method_68(new class_95(13, 0, 15));
            method_67().method_791(38, 1);
            return;
         case 38:
            method_68(new class_95(8, 0, 14));
            return;
         case 39:
            method_68(new class_95(8, 0, 16));
            method_74(
               new int[]{142, 7, 183, 10, 150, 65, 85, 41, 176, 184, 58, 197, 21, 168, 62, 130, 169, 17, 67, 118, 23, 182, 93, 128, 84, 158, 33, 24, 147, 152}
            );
            return;
         case 40:
            method_68(new class_95(13, 0, 16));
            method_67().method_791(36, 1);
            return;
         case 41:
            method_68(new class_95(13, 0, 14));
            method_67().method_791(36, 1);
            return;
         case 42:
            method_68(new class_95(3, 0, 17));
            return;
         case 43:
            method_68(new class_95(4, 0, 14));
            return;
         case 44:
            method_68(new class_95(8, 0, 14));
            return;
         case 45:
            method_68(new class_95(5, 0, 18));
            return;
         case 46:
            method_74(new int[]{18, 123, 94, 42, 194, 102, 77, 111, 68, 73, 105, 56, 99});
            method_74(
               new int[]{
                  109,
                  195,
                  137,
                  199,
                  173,
                  50,
                  121,
                  2,
                  88,
                  157,
                  11,
                  97,
                  136,
                  46,
                  193,
                  139,
                  122,
                  60,
                  79,
                  91,
                  92,
                  163,
                  187,
                  198,
                  87,
                  138,
                  177,
                  1,
                  178,
                  30,
                  101,
                  112
               }
            );
            method_68(new class_95(8, 0, 18));
            return;
         case 47:
            method_68(new class_95(5, 0, 0));
            return;
         case 48:
            method_68(class_95.field_1225);
            method_74(new int[]{51, 129, 179, 192, 134, 0, 113, 153});
            method_67().field_1251 = false;
      }
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_76() {
      return field_52 >= 48;
   }

   // $VF: renamed from: c () boolean
   public static final boolean method_77() {
      return method_76() && field_59.field_828 == 0;
   }

   // $VF: renamed from: a (boolean, long) al
   public static final class_95 method_78(boolean var0, long var1) {
      for (int var3 = 0; var3 < field_58.length; var3++) {
         class_95 var4;
         if ((var4 = field_58[var3]).field_1243) {
            return null;
         }

         if (var4 != null) {
            switch (var4.field_1226) {
               case 8:
                  if (var0 && method_110().field_828 == var4.field_1232) {
                     return var4;
                  }
               case 9:
               case 10:
               case 11:
               case 12:
               default:
                  break;
               case 13:
               case 14:
                  if (var0 && method_110().field_828 == var4.field_1232 && class_46.method_449(var4.field_1244, var4.field_1245, method_108().field_445)) {
                     return var4;
                  }
                  break;
               case 15:
                  if (field_40 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 16:
                  if (field_36 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 17:
                  class_51[] var5 = method_108().field_444;

                  for (int var6 = 0; var6 < var5.length; var6++) {
                     if (var5[var6] != null && var5[var6].field_711 == var4.field_1250) {
                        return var4;
                     }
                  }
                  break;
               case 18:
                  if (field_43 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 19:
                  if (field_38 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 20:
                  if (field_56.field_426 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 21:
                  if (field_44 >= var4.field_1250) {
                     var4.field_1243 = true;
                     return var4;
                  }
                  break;
               case 22:
                  if (!var0 && var1 > 10000L) {
                     return var4;
                  }
            }
         }
      }

      return null;
   }

   // $VF: renamed from: b (int) void
   public static final void method_79(int var0) {
      field_47 = var0;
   }

   // $VF: renamed from: d () void
   public static final void method_80() {
      field_47++;
   }

   // $VF: renamed from: b () int
   public static final int method_81() {
      return field_47;
   }

   // $VF: renamed from: e () void
   public static final void method_82() {
      field_48++;
   }

   // $VF: renamed from: c (int) void
   public static final void method_83(int var0) {
      field_48 = var0;
   }

   // $VF: renamed from: c () int
   public static final int method_84() {
      return field_48;
   }

   // $VF: renamed from: f () void
   public static final void method_85() {
      field_49++;
   }

   // $VF: renamed from: d () int
   public static final int method_86() {
      return field_46;
   }

   // $VF: renamed from: d (int) void
   public static final void method_87(int var0) {
      field_49 = var0;
   }

   // $VF: renamed from: e () int
   public static final int method_88() {
      return field_49;
   }

   // $VF: renamed from: f () int
   public static final int method_89() {
      return field_50;
   }

   // $VF: renamed from: g () int
   public static final int method_90() {
      return field_51;
   }

   // $VF: renamed from: e (int) void
   public static final void method_91(int var0) {
      field_50 = var0;
   }

   // $VF: renamed from: f (int) void
   public static final void method_92(int var0) {
      field_51 = var0;
   }

   // $VF: renamed from: d (al) void
   public static final void method_93(class_95 var0) {
      for (int var1 = 0; var1 < field_58.length; var1++) {
         if (field_58[var1] == var0) {
            field_58[var1] = class_95.field_1225;
         }
      }

      if (field_57 == var0) {
         field_57 = null;
      }
   }

   // $VF: renamed from: g (int) void
   public static final void method_94(int var0) {
      if (var0 < field_53.length) {
         field_53[var0] = true;
         if (var0 < 13 || var0 > 17) {
            field_38++;
            class_58.method_573();
         }
      }
   }

   // $VF: renamed from: h (int) void
   public static final void method_95(int var0) {
      field_46 = var0;
   }

   // $VF: renamed from: i (int) void
   public static final void method_96(int var0) {
      field_46 += var0;
   }

   // $VF: renamed from: a (boolean[]) void
   public static final void method_97(boolean[] var0) {
      field_53 = var0;
   }

   // $VF: renamed from: a () boolean[]
   public static final boolean[] method_98() {
      return field_53;
   }

   // $VF: renamed from: j (int) void
   public static final void method_99(int var0) {
      field_38 = var0;
   }

   // $VF: renamed from: h () int
   public static final int method_100() {
      return field_38;
   }

   // $VF: renamed from: k (int) void
   public static final void method_101(int var0) {
      field_39 = var0;
   }

   // $VF: renamed from: i () int
   public static final int method_102() {
      return field_39;
   }

   // $VF: renamed from: g () void
   public static final void method_103() {
      field_39++;
   }

   // $VF: renamed from: b (boolean[]) void
   public static final void method_104(boolean[] var0) {
      field_55 = var0;
   }

   // $VF: renamed from: b () boolean[]
   public static final boolean[] method_105() {
      return field_55;
   }

   // $VF: renamed from: h () void
   public static final void method_106() {
      field_43++;
   }

   // $VF: renamed from: j () int
   public static final int method_107() {
      return field_43;
   }

   // $VF: renamed from: a () be
   public static final class_32 method_108() {
      return field_56;
   }

   // $VF: renamed from: a (be) void
   public static final void method_109(class_32 var0) {
      field_56 = var0;
   }

   // $VF: renamed from: a () an
   public static final class_60 method_110() {
      return field_59;
   }

   // $VF: renamed from: b (an) void
   public static final void method_111(class_60 var0) {
      field_59 = var0;
   }

   // $VF: renamed from: k () int
   public static final int method_112() {
      return field_33;
   }

   // $VF: renamed from: l (int) void
   public static final void method_113(int var0) {
      field_34 = var0;
   }

   // $VF: renamed from: a (long) void
   public static final void method_114(long var0) {
      field_35 = var0;
   }

   // $VF: renamed from: m (int) void
   public static final void method_115(int var0) {
      field_36 = var0;
   }

   // $VF: renamed from: n (int) void
   public static final void method_116(int var0) {
      field_37 = var0;
   }

   // $VF: renamed from: o (int) void
   public static final void method_117(int var0) {
      field_40 = var0;
   }

   // $VF: renamed from: p (int) void
   public static final void method_118(int var0) {
      field_41 = var0;
   }

   // $VF: renamed from: q (int) void
   public static final void method_119(int var0) {
      field_42 = var0;
   }

   // $VF: renamed from: r (int) void
   public static final void method_120(int var0) {
      field_44 = var0;
   }

   // $VF: renamed from: l () int
   public static final int method_121() {
      return field_44;
   }

   // $VF: renamed from: s (int) void
   public static final void method_122(int var0) {
      field_44 += var0;
   }

   // $VF: renamed from: t (int) void
   public static final void method_123(int var0) {
      field_54[var0] = true;
   }

   // $VF: renamed from: c (boolean[]) void
   public static final void method_124(boolean[] var0) {
      field_54 = var0;
   }

   // $VF: renamed from: c () boolean[]
   public static final boolean[] method_125() {
      return field_54;
   }

   // $VF: renamed from: u (int) void
   public static final void method_126(int var0) {
      field_43 = var0;
   }

   // $VF: renamed from: v (int) void
   public static final void method_127(int var0) {
      field_33 += var0;
   }

   // $VF: renamed from: w (int) void
   public static final void method_128(int var0) {
      field_33 = var0;
   }

   // $VF: renamed from: i () void
   public static final void method_129() {
      int var0 = field_38 + 2 * field_36 + field_44 + 3 * field_40;
      if (field_42 * 1.3F < var0) {
         field_42 = var0;
         field_41++;
      }
   }

   // $VF: renamed from: m () int
   public static final int method_130() {
      return field_34;
   }

   // $VF: renamed from: n () int
   public static final int method_131() {
      return field_42;
   }

   // $VF: renamed from: o () int
   public static final int method_132() {
      return field_36;
   }

   // $VF: renamed from: j () void
   public static final void method_133() {
      field_36++;
      class_58.method_568();
   }

   // $VF: renamed from: x (int) void
   public static final void method_134(int var0) {
      field_45 = var0;
   }

   // $VF: renamed from: p () int
   public static final int method_135() {
      return field_45;
   }

   // $VF: renamed from: k () void
   public static final void method_136() {
      field_45++;
      class_58.method_570();
   }

   // $VF: renamed from: l () void
   public static final void method_137() {
      field_37++;
   }

   // $VF: renamed from: q () int
   public static final int method_138() {
      return field_37;
   }

   // $VF: renamed from: r () int
   public static final int method_139() {
      return field_40;
   }

   // $VF: renamed from: s () int
   public static final int method_140() {
      return field_41;
   }

   // $VF: renamed from: b (long) void
   public static final void method_141(long var0) {
      field_35 += var0;
   }

   // $VF: renamed from: a () long
   public static final long method_142() {
      return field_35;
   }

   // $VF: renamed from: a () java.lang.String
   public static final String method_143() {
      return field_30;
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_144(String var0) {
      field_30 = var0;
   }

   // $VF: renamed from: a () byte[]
   public static final byte[] method_145() {
      return field_31;
   }

   // $VF: renamed from: a (byte[]) void
   public static final void method_146(byte[] var0) {
      field_31 = var0;
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public static final Image method_147() {
      return field_32;
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Image) void
   public static final void method_148(Image var0) {
      field_32 = var0;
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String) java.lang.String
   public static final String method_149(String var0, String var1) {
      int var2;
      return (var2 = var0.indexOf(35)) >= 0 ? var0.substring(0, var2) + var1 + var0.substring(var2 + 1) : var0;
   }

   // $VF: renamed from: m () void
   public static final void method_150() {
      for (int var0 = 0; var0 < 2; var0++) {
         class_46[] var1;
         if ((var1 = var0 == 0 ? field_56.field_445 : field_59.field_836) != null) {
            byte[] var5 = class_48.method_467();

            for (int var6 = 0; var6 < var1.length; var6++) {
               class_46 var7 = var1[var6];
               int var4 = class_44.method_438(
                  var5[var7.field_628 * 4 + 1], var5[var7.field_628 * 4 + 2], var5[var7.field_629 * 4 + 1], var5[var7.field_629 * 4 + 2]
               );
               int var3;
               if (var7.field_626 != 33 && var7.field_626 != 34 && var7.field_626 != 35) {
                  var3 = class_44.method_438(
                     var5[var1[var6].field_628 * 4 + 1], var5[var1[var6].field_628 * 4 + 2], method_110().field_829, method_110().field_830
                  );
               } else {
                  var3 = class_44.method_438(
                     var5[var1[var6].field_629 * 4 + 1], var5[var1[var6].field_629 * 4 + 2], method_110().field_829, method_110().field_830
                  );
               }

               int var2 = var7.field_632 + (int)(class_124.method_944(1.0F, 100.0F / var4 * var3 / 100.0F) * (var7.field_633 - var7.field_632));
               var7.field_630 = var2;
            }
         }
      }
   }

   // $VF: renamed from: n () void
   public static final void method_151() {
      field_33 = 15000;
      field_34 = 0;
      field_36 = 0;
      field_37 = 0;
      field_40 = 0;
      field_44 = 0;
      field_45 = 0;
      field_46 = 0;
      field_47 = 0;
      field_48 = 0;
      field_49 = 0;
      field_51 = 22500;
      field_50 = field_51;
      field_41 = 1;
      field_38 = 0;
      field_39 = 0;
      field_42 = 15;
      field_43 = 0;
      class_41.field_525 = null;
      field_35 = 0L;
      class_58.method_578();
      boolean[] var0 = class_44.method_433();

      for (int var1 = 0; var1 < var0.length; var1++) {
         var0[var1] = false;
      }

      class_44.method_432(var0);

      for (int var3 = 0; var3 < field_55.length; var3++) {
         field_55[var3] = false;
      }

      for (int var4 = 0; var4 < field_53.length; var4++) {
         field_53[var4] = false;
      }

      for (int var5 = 0; var5 < field_54.length; var5++) {
         field_54[var5] = false;
      }

      class_41.method_416();
      method_66(class_95.field_1225);
      method_72(0);
      method_75();
      method_63(method_67());
      method_109(class_24.method_313()[0].method_387());
      method_108().field_443 = false;
      method_108().method_388();
      method_111(class_44.method_431(0));
      if (field_31 == null && field_32 == null) {
         method_146(class_119.method_925(true, 3));
      }

      method_108().method_371(null);
      class_51[] var6;
      (var6 = new class_51[4])[0] = class_24.method_311()[15].method_505();
      var6[1] = class_24.method_311()[18].method_505();
      var6[2] = class_24.method_311()[22].method_505();
      var6[3] = class_24.method_311()[35].method_505();

      for (int var2 = 0; var2 < var6.length; var2++) {
         var6[var2].method_509();
         var6[var2].field_721 = true;
      }

      method_108().method_376(var6);
      field_63 = method_108().field_423;
      field_61 = method_108().field_430;
      field_62 = method_108().field_431;
   }
}
