import javax.microedition.lcdui.Image;

// $VF: renamed from: dj
public final class class_21 {
   // $VF: renamed from: a java.lang.String
   private static String field_187 = "Player";
   // $VF: renamed from: a byte[]
   private static byte[] field_188 = null;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private static Image field_189 = null;
   // $VF: renamed from: d int
   private static int field_190;
   // $VF: renamed from: e int
   private static int field_191;
   // $VF: renamed from: b long
   private static long field_192;
   // $VF: renamed from: f int
   private static int field_193;
   // $VF: renamed from: g int
   private static int field_194;
   // $VF: renamed from: h int
   private static int field_195;
   // $VF: renamed from: i int
   private static int field_196;
   // $VF: renamed from: j int
   private static int field_197;
   // $VF: renamed from: k int
   private static int field_198 = 1;
   // $VF: renamed from: l int
   private static int field_199;
   // $VF: renamed from: m int
   private static int field_200;
   // $VF: renamed from: n int
   private static int field_201;
   // $VF: renamed from: o int
   private static int field_202;
   // $VF: renamed from: p int
   private static int field_203;
   // $VF: renamed from: q int
   private static int field_204;
   // $VF: renamed from: r int
   private static int field_205;
   // $VF: renamed from: s int
   private static int field_206;
   // $VF: renamed from: t int
   private static int field_207;
   // $VF: renamed from: u int
   private static int field_208;
   // $VF: renamed from: v int
   private static int field_209;
   // $VF: renamed from: a boolean[]
   private static boolean[] field_210 = new boolean[class_90.field_1202.length];
   // $VF: renamed from: b boolean[]
   private static boolean[] field_211 = new boolean[42];
   // $VF: renamed from: c boolean[]
   private static boolean[] field_212 = new boolean[200];
   // $VF: renamed from: a bd
   private static class_68 field_213;
   // $VF: renamed from: a am
   private static class_87 field_214;
   // $VF: renamed from: a am[]
   private static class_87[] field_215 = new class_87[2];
   // $VF: renamed from: a ao
   private static class_86 field_216;
   // $VF: renamed from: a ao[]
   private static class_86[] field_217 = new class_86[3];
   // $VF: renamed from: a int
   public static int field_218;
   // $VF: renamed from: b int
   public static int field_219;
   // $VF: renamed from: c int
   public static int field_220;
   // $VF: renamed from: a long
   public static long field_221;

   // $VF: renamed from: a () ao[]
   public static final class_86[] method_127() {
      return field_217;
   }

   // $VF: renamed from: a (ao[]) void
   public static final void method_128(class_86[] var0) {
      field_217 = var0;
   }

   // $VF: renamed from: a (ao) boolean
   public static final boolean method_129(class_86 var0) {
      class_86 var1;
      if ((var1 = method_130(var0)) != null) {
         field_216 = var1;
         return false;
      } else if (field_217[0] == null) {
         for (int var3 = 2; var3 >= 0; var3--) {
            if (field_217[var3] == null) {
               field_217[var3] = var0;
               field_216 = var0;
               return true;
            }
         }

         return false;
      } else {
         for (int var2 = 2; var2 > 0; var2--) {
            field_217[var2] = field_217[var2 - 1];
         }

         field_217[0] = var0;
         field_216 = var0;
         return true;
      }
   }

   // $VF: renamed from: a (ao) ao
   public static final class_86 method_130(class_86 var0) {
      for (int var1 = 0; var1 < 3; var1++) {
         if (field_217[var1] != null && field_217[var1].method_753(var0)) {
            return field_217[var1];
         }
      }

      return null;
   }

   // $VF: renamed from: a (ao) void
   public static final void method_131(class_86 var0) {
      if (method_130(var0) == null) {
         var0.field_1142 = class_35.method_304(var0);
         var0.field_1143 = class_35.method_306(var0);
         var0.field_1141 = class_35.method_305(var0);
         var0.field_1144 = class_35.method_309(var0);
      }

      method_129(var0);
      field_221 = method_212();
      method_133(class_87.field_1145);

      for (int var2 = 0; var2 < field_215.length; var2++) {
         if (field_215[var2] != null
            && field_215[var2].field_1152 == var0.field_1134
            && field_215[var2].field_1146 != 13
            && field_215[var2].field_1146 != 14
            && field_215[var2].field_1146 != 21
            && field_215[var2].field_1146 != 18
            && field_215[var2].field_1146 != 16
            && field_215[var2].field_1146 != 15) {
            if ((field_215[var2].field_1156 < field_215[var2].field_1155 || field_215[var2].field_1155 < 0)
               && (field_215[var2].field_1161 || field_215[var2].field_1146 != 8)) {
               if (method_143() == 5 && field_215[var2].field_1161) {
                  field_215[var2].field_1171 = true;
               }

               method_133(field_215[var2]);
               return;
            }
            break;
         }
      }
   }

   // $VF: renamed from: a () am
   public static final class_87 method_132() {
      return field_214;
   }

   // $VF: renamed from: a (am) void
   public static final void method_133(class_87 var0) {
      field_214 = var0;
   }

   // $VF: renamed from: a () am[]
   public static final class_87[] method_134() {
      return field_215;
   }

   // $VF: renamed from: b () am
   public static final class_87 method_135() {
      return field_215[1];
   }

   // $VF: renamed from: b (am) void
   public static final void method_136(class_87 var0) {
      field_215[1] = var0;
   }

   // $VF: renamed from: c () am
   public static final class_87 method_137() {
      return field_215[0];
   }

   // $VF: renamed from: c (am) void
   public static final void method_138(class_87 var0) {
      var0.field_1161 = true;
      field_215[0] = var0;
   }

   // $VF: renamed from: a () boolean
   public static final boolean method_139() {
      return field_215[1] != null && !field_215[1].method_754() && field_215[1].method_762();
   }

   // $VF: renamed from: a () void
   public static final void method_140() {
      if (field_215[1] != null) {
         field_215[1].method_760();
      }
   }

   // $VF: renamed from: b () void
   public static final void method_141() {
      field_197++;
   }

   // $VF: renamed from: a (int) void
   public static final void method_142(int var0) {
      field_209 = var0;
   }

   // $VF: renamed from: a () int
   public static final int method_143() {
      return field_209;
   }

   // $VF: renamed from: a (int[]) void
   public static final void method_144(int[] var0) {
      if (var0 != null) {
         for (int var1 = 0; var1 < var0.length; var1++) {
            field_212[var0[var1]] = true;
         }
      }
   }

   // $VF: renamed from: c () void
   public static final void method_145() {
      field_209++;
      switch (field_209) {
         case 1:
            method_138(new class_87(20, 0, 0));
            method_137().field_1170 = 1;
            return;
         case 2:
            method_138(new class_87(8, 0, 0));
            return;
         case 3:
            method_138(new class_87(17, 0, 0));
            method_137().field_1170 = 0;
            method_137().field_1171 = false;
            return;
         case 4:
            method_138(new class_87(22, 0, 0));
            return;
         case 5:
            method_138(new class_87(3, 0, 1));
            method_137().field_1171 = false;
            return;
         case 6:
            method_138(new class_87(8, 0, 0));
            return;
         case 7:
            method_138(new class_87(7, 0, 1));
            method_137().method_755(0, 5, 0);
            return;
         case 8:
            method_138(new class_87(8, 1000, 1));
            return;
         case 9:
            method_138(new class_87(15, 0, 2));
            method_137().field_1170 = field_197 + 3;
            method_137().field_1171 = false;
            return;
         case 10:
            method_138(new class_87(11, 0, 2));
            method_137().method_755(0, 10, 5);
            return;
         case 11:
            method_138(new class_87(8, 0, 2));
            method_144(new int[]{3});
            return;
         case 12:
            method_138(new class_87(8, 0, 3));
            method_144(new int[]{4});
            return;
         case 13:
            method_138(new class_87(8, 0, 4));
            method_144(new int[]{90});
            return;
         case 14:
            method_138(new class_87(8, 0, 5));
            method_144(new int[]{80, 47});
            return;
         case 15:
            method_138(new class_87(21, 0, 5));
            method_137().field_1170 = field_201 + 5;
            method_137().field_1171 = false;
            method_144(new int[]{80, 47});
            return;
         case 16:
            method_138(new class_87(18, 0, 0));
            method_137().field_1171 = false;
            method_137().field_1170 = class_16.method_98(method_177() + 5, 200);
            return;
         case 17:
            method_138(new class_87(8, 0, 3));
            method_144(new int[]{6, 12, 106, 180});
            return;
         case 18:
            method_138(new class_87(8, 0, 6));
            method_137().field_1171 = false;
            return;
         case 19:
            method_138(new class_87(6, 2000, 7));
            method_137().method_755(10, 30, 15);
            method_144(new int[]{8, 28, 35});
            return;
         case 20:
            method_138(new class_87(8, 0, 6));
            return;
         case 21:
            method_138(new class_87(3, 5000, 8));
            return;
         case 22:
            method_138(new class_87(8, 0, 9));
            method_144(new int[]{9, 159, 20, 110, 89, 5, 117, 37});
            return;
         case 23:
            method_138(new class_87(10, 0, 9));
            return;
         case 24:
            method_138(new class_87(8, 0, 9));
            method_144(new int[]{22, 57, 14, 75, 63, 186, 131, 175, 140, 189, 54, 74, 81, 25, 149, 96});
            return;
         case 25:
            method_138(new class_87(5, 0, 10));
            return;
         case 26:
            method_138(new class_87(16, 0, 0));
            method_137().field_1171 = false;
            method_137().field_1170 = method_202() + 10;
            return;
         case 27:
            method_138(new class_87(2, 0, 11));
            method_144(new int[]{82, 133, 38, 166, 39, 161, 135, 196, 53, 125, 174, 36});
            return;
         case 28:
            method_138(new class_87(8, 0, 12));
            return;
         case 29:
            method_138(new class_87(4, 5000, 13));
            return;
         case 30:
            method_138(new class_87(8, 0, 14));
            method_144(new int[]{15, 114, 170, 181, 115, 69, 190, 162, 146, 70, 151, 59, 167, 191, 86, 44, 71, 95, 72, 31, 16, 32, 160, 61});
            return;
         case 31:
            method_138(new class_87(1, 0, 2));
            return;
         case 32:
            method_138(new class_87(8, 100000, 14));
            return;
         case 33:
            method_138(new class_87(8, 0, 15));
            return;
         case 34:
            method_138(new class_87(13, 0, 15));
            method_137().method_756(37, 1);
            method_144(new int[]{83, 116, 55, 171, 103, 156, 172, 127, 43, 13, 76, 141, 40, 45, 124, 49, 48, 165, 154, 148, 107, 16});
            return;
         case 35:
            method_138(new class_87(0, 0, 15));
            return;
         case 36:
            method_138(new class_87(8, 0, 15));
            method_144(new int[]{19, 143, 64, 120, 188, 126, 119, 34, 145, 66, 98, 144, 155, 104, 52, 26, 78, 29, 108, 164, 132, 185, 27, 100});
            return;
         case 37:
            method_138(new class_87(13, 0, 15));
            method_137().method_756(38, 1);
            return;
         case 38:
            method_138(new class_87(8, 0, 14));
            return;
         case 39:
            method_138(new class_87(8, 0, 16));
            method_144(
               new int[]{142, 7, 183, 10, 150, 65, 85, 41, 176, 184, 58, 197, 21, 168, 62, 130, 169, 17, 67, 118, 23, 182, 93, 128, 84, 158, 33, 24, 147, 152}
            );
            return;
         case 40:
            method_138(new class_87(13, 0, 16));
            method_137().method_756(36, 1);
            return;
         case 41:
            method_138(new class_87(13, 0, 14));
            method_137().method_756(36, 1);
            return;
         case 42:
            method_138(new class_87(3, 0, 17));
            return;
         case 43:
            method_138(new class_87(4, 0, 14));
            return;
         case 44:
            method_138(new class_87(8, 0, 14));
            return;
         case 45:
            method_138(new class_87(5, 0, 18));
            return;
         case 46:
            method_144(new int[]{18, 123, 94, 42, 194, 102, 77, 111, 68, 73, 105, 56, 99});
            method_144(
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
            method_138(new class_87(8, 0, 18));
            return;
         case 47:
            method_138(new class_87(5, 0, 0));
            return;
         case 48:
            method_138(class_87.field_1145);
            method_144(new int[]{51, 129, 179, 192, 134, 0, 113, 153});
            method_137().field_1171 = false;
      }
   }

   // $VF: renamed from: b () boolean
   public static final boolean method_146() {
      return field_209 >= 48;
   }

   // $VF: renamed from: c () boolean
   public static final boolean method_147() {
      return method_146() && field_216.field_1134 == 0;
   }

   // $VF: renamed from: a (boolean, long) am
   public static final class_87 method_148(boolean var0, long var1) {
      for (int var3 = 0; var3 < field_215.length; var3++) {
         class_87 var4;
         if ((var4 = field_215[var3]).field_1163) {
            return null;
         }

         if (var4 != null) {
            switch (var4.field_1146) {
               case 8:
                  if (var0 && method_180().field_1134 == var4.field_1152) {
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
                  if (var0 && method_180().field_1134 == var4.field_1152 && class_120.method_931(var4.field_1164, var4.field_1165, method_178().field_886)) {
                     return var4;
                  }
                  break;
               case 15:
                  if (field_197 >= var4.field_1170) {
                     var4.field_1163 = true;
                     return var4;
                  }
                  break;
               case 16:
                  if (field_193 >= var4.field_1170) {
                     var4.field_1163 = true;
                     return var4;
                  }
                  break;
               case 17:
                  class_19[] var5 = method_178().field_885;

                  for (int var6 = 0; var6 < var5.length; var6++) {
                     if (var5[var6] != null && var5[var6].field_166 == var4.field_1170) {
                        return var4;
                     }
                  }
                  break;
               case 18:
                  if (field_200 >= var4.field_1170) {
                     var4.field_1163 = true;
                     return var4;
                  }
                  break;
               case 19:
                  if (field_195 >= var4.field_1170) {
                     var4.field_1163 = true;
                     return var4;
                  }
                  break;
               case 20:
                  if (field_213.field_867 >= var4.field_1170) {
                     var4.field_1163 = true;
                     return var4;
                  }
                  break;
               case 21:
                  if (field_201 >= var4.field_1170) {
                     var4.field_1163 = true;
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
   public static final void method_149(int var0) {
      field_204 = var0;
   }

   // $VF: renamed from: d () void
   public static final void method_150() {
      field_204++;
   }

   // $VF: renamed from: b () int
   public static final int method_151() {
      return field_204;
   }

   // $VF: renamed from: e () void
   public static final void method_152() {
      field_205++;
   }

   // $VF: renamed from: c (int) void
   public static final void method_153(int var0) {
      field_205 = var0;
   }

   // $VF: renamed from: c () int
   public static final int method_154() {
      return field_205;
   }

   // $VF: renamed from: f () void
   public static final void method_155() {
      field_206++;
   }

   // $VF: renamed from: d () int
   public static final int method_156() {
      return field_203;
   }

   // $VF: renamed from: d (int) void
   public static final void method_157(int var0) {
      field_206 = var0;
   }

   // $VF: renamed from: e () int
   public static final int method_158() {
      return field_206;
   }

   // $VF: renamed from: f () int
   public static final int method_159() {
      return field_207;
   }

   // $VF: renamed from: g () int
   public static final int method_160() {
      return field_208;
   }

   // $VF: renamed from: e (int) void
   public static final void method_161(int var0) {
      field_207 = var0;
   }

   // $VF: renamed from: f (int) void
   public static final void method_162(int var0) {
      field_208 = var0;
   }

   // $VF: renamed from: d (am) void
   public static final void method_163(class_87 var0) {
      for (int var1 = 0; var1 < field_215.length; var1++) {
         if (field_215[var1] == var0) {
            field_215[var1] = class_87.field_1145;
         }
      }

      if (field_214 == var0) {
         field_214 = null;
      }
   }

   // $VF: renamed from: g (int) void
   public static final void method_164(int var0) {
      if (var0 < field_210.length) {
         field_210[var0] = true;
         if (var0 < 13 || var0 > 17) {
            field_195++;
            class_14.method_78();
         }
      }
   }

   // $VF: renamed from: h (int) void
   public static final void method_165(int var0) {
      field_203 = var0;
   }

   // $VF: renamed from: i (int) void
   public static final void method_166(int var0) {
      field_203 += var0;
   }

   // $VF: renamed from: a (boolean[]) void
   public static final void method_167(boolean[] var0) {
      field_210 = var0;
   }

   // $VF: renamed from: a () boolean[]
   public static final boolean[] method_168() {
      return field_210;
   }

   // $VF: renamed from: j (int) void
   public static final void method_169(int var0) {
      field_195 = var0;
   }

   // $VF: renamed from: h () int
   public static final int method_170() {
      return field_195;
   }

   // $VF: renamed from: k (int) void
   public static final void method_171(int var0) {
      field_196 = var0;
   }

   // $VF: renamed from: i () int
   public static final int method_172() {
      return field_196;
   }

   // $VF: renamed from: g () void
   public static final void method_173() {
      field_196++;
   }

   // $VF: renamed from: b (boolean[]) void
   public static final void method_174(boolean[] var0) {
      field_212 = var0;
   }

   // $VF: renamed from: b () boolean[]
   public static final boolean[] method_175() {
      return field_212;
   }

   // $VF: renamed from: h () void
   public static final void method_176() {
      field_200++;
   }

   // $VF: renamed from: j () int
   public static final int method_177() {
      return field_200;
   }

   // $VF: renamed from: a () bd
   public static final class_68 method_178() {
      return field_213;
   }

   // $VF: renamed from: a (bd) void
   public static final void method_179(class_68 var0) {
      field_213 = var0;
   }

   // $VF: renamed from: a () ao
   public static final class_86 method_180() {
      return field_216;
   }

   // $VF: renamed from: b (ao) void
   public static final void method_181(class_86 var0) {
      field_216 = var0;
   }

   // $VF: renamed from: k () int
   public static final int method_182() {
      return field_190;
   }

   // $VF: renamed from: l (int) void
   public static final void method_183(int var0) {
      field_191 = var0;
   }

   // $VF: renamed from: a (long) void
   public static final void method_184(long var0) {
      field_192 = var0;
   }

   // $VF: renamed from: m (int) void
   public static final void method_185(int var0) {
      field_193 = var0;
   }

   // $VF: renamed from: n (int) void
   public static final void method_186(int var0) {
      field_194 = var0;
   }

   // $VF: renamed from: o (int) void
   public static final void method_187(int var0) {
      field_197 = var0;
   }

   // $VF: renamed from: p (int) void
   public static final void method_188(int var0) {
      field_198 = var0;
   }

   // $VF: renamed from: q (int) void
   public static final void method_189(int var0) {
      field_199 = var0;
   }

   // $VF: renamed from: r (int) void
   public static final void method_190(int var0) {
      field_201 = var0;
   }

   // $VF: renamed from: l () int
   public static final int method_191() {
      return field_201;
   }

   // $VF: renamed from: s (int) void
   public static final void method_192(int var0) {
      field_201 += var0;
   }

   // $VF: renamed from: t (int) void
   public static final void method_193(int var0) {
      field_211[var0] = true;
   }

   // $VF: renamed from: c (boolean[]) void
   public static final void method_194(boolean[] var0) {
      field_211 = var0;
   }

   // $VF: renamed from: c () boolean[]
   public static final boolean[] method_195() {
      return field_211;
   }

   // $VF: renamed from: u (int) void
   public static final void method_196(int var0) {
      field_200 = var0;
   }

   // $VF: renamed from: v (int) void
   public static final void method_197(int var0) {
      field_190 += var0;
   }

   // $VF: renamed from: w (int) void
   public static final void method_198(int var0) {
      field_190 = var0;
   }

   // $VF: renamed from: i () void
   public static final void method_199() {
      int var0 = field_195 + 2 * field_193 + field_201 + 3 * field_197;
      if (field_199 * 1.3F < var0) {
         field_199 = var0;
         field_198++;
      }
   }

   // $VF: renamed from: m () int
   public static final int method_200() {
      return field_191;
   }

   // $VF: renamed from: n () int
   public static final int method_201() {
      return field_199;
   }

   // $VF: renamed from: o () int
   public static final int method_202() {
      return field_193;
   }

   // $VF: renamed from: j () void
   public static final void method_203() {
      field_193++;
      class_14.method_73();
   }

   // $VF: renamed from: x (int) void
   public static final void method_204(int var0) {
      field_202 = var0;
   }

   // $VF: renamed from: p () int
   public static final int method_205() {
      return field_202;
   }

   // $VF: renamed from: k () void
   public static final void method_206() {
      field_202++;
      class_14.method_75();
   }

   // $VF: renamed from: l () void
   public static final void method_207() {
      field_194++;
   }

   // $VF: renamed from: q () int
   public static final int method_208() {
      return field_194;
   }

   // $VF: renamed from: r () int
   public static final int method_209() {
      return field_197;
   }

   // $VF: renamed from: s () int
   public static final int method_210() {
      return field_198;
   }

   // $VF: renamed from: b (long) void
   public static final void method_211(long var0) {
      field_192 += var0;
   }

   // $VF: renamed from: a () long
   public static final long method_212() {
      return field_192;
   }

   // $VF: renamed from: a () java.lang.String
   public static final String method_213() {
      return field_187;
   }

   // $VF: renamed from: a (java.lang.String) void
   public static final void method_214(String var0) {
      field_187 = var0;
   }

   // $VF: renamed from: a () byte[]
   public static final byte[] method_215() {
      return field_188;
   }

   // $VF: renamed from: a (byte[]) void
   public static final void method_216(byte[] var0) {
      field_188 = var0;
   }

   // $VF: renamed from: a () javax.microedition.lcdui.Image
   public static final Image method_217() {
      return field_189;
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Image) void
   public static final void method_218(Image var0) {
      field_189 = var0;
   }

   // $VF: renamed from: a (java.lang.String, java.lang.String) java.lang.String
   public static final String method_219(String var0, String var1) {
      int var2;
      return (var2 = var0.indexOf(35)) >= 0 ? var0.substring(0, var2) + var1 + var0.substring(var2 + 1) : var0;
   }

   // $VF: renamed from: m () void
   public static final void method_220() {
      for (int var0 = 0; var0 < 2; var0++) {
         class_120[] var1;
         if ((var1 = var0 == 0 ? field_213.field_886 : field_216.field_1142) != null) {
            byte[] var5 = class_49.method_404();

            for (int var6 = 0; var6 < var1.length; var6++) {
               class_120 var7 = var1[var6];
               int var4 = class_38.method_361(
                  var5[var7.field_1482 * 4 + 1], var5[var7.field_1482 * 4 + 2], var5[var7.field_1483 * 4 + 1], var5[var7.field_1483 * 4 + 2]
               );
               int var3;
               if (var7.field_1480 != 33 && var7.field_1480 != 34 && var7.field_1480 != 35) {
                  var3 = class_38.method_361(
                     var5[var1[var6].field_1482 * 4 + 1], var5[var1[var6].field_1482 * 4 + 2], method_180().field_1135, method_180().field_1136
                  );
               } else {
                  var3 = class_38.method_361(
                     var5[var1[var6].field_1483 * 4 + 1], var5[var1[var6].field_1483 * 4 + 2], method_180().field_1135, method_180().field_1136
                  );
               }

               int var2 = var7.field_1486 + (int)(class_16.method_99(1.0F, 100.0F / var4 * var3 / 100.0F) * (var7.field_1487 - var7.field_1486));
               var7.field_1484 = var2;
            }
         }
      }
   }

   // $VF: renamed from: n () void
   public static final void method_221() {
      field_190 = 15000;
      field_191 = 0;
      field_193 = 0;
      field_194 = 0;
      field_197 = 0;
      field_201 = 0;
      field_202 = 0;
      field_203 = 0;
      field_204 = 0;
      field_205 = 0;
      field_206 = 0;
      field_208 = 22500;
      field_207 = field_208;
      field_198 = 1;
      field_195 = 0;
      field_196 = 0;
      field_199 = 15;
      field_200 = 0;
      class_84.field_1108 = null;
      field_192 = 0L;
      class_14.method_83();
      boolean[] var0 = class_38.method_356();

      for (int var1 = 0; var1 < var0.length; var1++) {
         var0[var1] = false;
      }

      class_38.method_355(var0);

      for (int var3 = 0; var3 < field_212.length; var3++) {
         field_212[var3] = false;
      }

      for (int var4 = 0; var4 < field_210.length; var4++) {
         field_210[var4] = false;
      }

      for (int var5 = 0; var5 < field_211.length; var5++) {
         field_211[var5] = false;
      }

      class_84.method_737();
      method_136(class_87.field_1145);
      method_142(0);
      method_145();
      method_133(method_137());
      method_179(class_90.method_783()[0].method_627());
      method_178().field_884 = false;
      method_178().method_628();
      method_181(class_38.method_354(0));
      if (field_188 == null && field_189 == null) {
         method_216(class_119.method_920(true, 3));
      }

      method_178().method_611(null);
      class_19[] var6;
      (var6 = new class_19[4])[0] = class_90.method_781()[15].method_120();
      var6[1] = class_90.method_781()[18].method_120();
      var6[2] = class_90.method_781()[22].method_120();
      var6[3] = class_90.method_781()[35].method_120();

      for (int var2 = 0; var2 < var6.length; var2++) {
         var6[var2].method_124();
         var6[var2].field_176 = true;
      }

      method_178().method_616(var6);
      field_220 = method_178().field_864;
      field_218 = method_178().field_871;
      field_219 = method_178().field_872;
   }
}
