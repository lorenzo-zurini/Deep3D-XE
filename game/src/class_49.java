import java.io.InputStream;

// $VF: renamed from: bx
public final class class_49 {
   // $VF: renamed from: a java.io.InputStream
   private static InputStream field_539;
   // $VF: renamed from: a byte[]
   private static byte[] field_540;
   // $VF: renamed from: a java.lang.StringBuffer
   private static StringBuffer field_541;
   // $VF: renamed from: a char
   private static char field_542;
   // $VF: renamed from: b byte[]
   private static byte[] field_543;
   // $VF: renamed from: a java.lang.String
   private static String field_544;
   // $VF: renamed from: a java.lang.Class
   public static Class field_545;

   private class_49() {
   }

   // $VF: renamed from: a (java.lang.String) void
   private static void method_399(String var0) throws Exception {
      if (field_544 != var0 || field_540 == null) {
         field_539 = class_49.class.getResourceAsStream(var0);
         field_540 = field_539.readAllBytes();
         field_539.close();
         field_544 = var0;
      }
   }

   // $VF: renamed from: a (int) ao
   public static final class_86 method_400(int var0) {
      return method_401(new short[]{(short)var0})[0];
   }

   // $VF: renamed from: a (short[]) ao[]
   public static final class_86[] method_401(short[] var0) {
      class_86[] var1 = new class_86[var0.length];

      try {
         method_399("/data/txt/stations.txt");
         field_541 = new StringBuffer(30);
         String var2 = "";
         byte[] var3 = new byte[4];
         int var4 = 0;
         int var5 = 0;
         int var6 = 0;
         boolean var7 = 0 == var0[0];

         for (int var8 = 0; var8 < field_540.length; var8++) {
            field_542 = (char)field_540[var8];
            switch (field_542) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ',':
                  if (var7) {
                     if (var4 == 0) {
                        var2 = field_541.toString();
                     } else {
                        var3[var4 - 1] = Byte.parseByte(field_541.toString());
                     }

                     var4++;
                  }

                  field_541 = new StringBuffer(30);
                  break;
               case ';':
                  if (var7) {
                     var3[var4 - 1] = Byte.parseByte(field_541.toString());
                     var4 = 0;
                     if (var6 == var0[var5]) {
                        if (var3[3] == 0) {
                           var3[3] = -10;
                        } else if (var3[3] == 100) {
                           var3[3] = 115;
                        }

                        var1[var5++] = new class_86(var2, var6, var3[0], var3[1], var3[2], var3[3]);
                        if (var5 >= var0.length) {
                           return var1;
                        }
                     }
                  }

                  var6++;
                  if (var7) {
                     field_541 = new StringBuffer(30);
                  }

                  var7 = var6 == var0[var5];
                  break;
               default:
                  if (var7) {
                     field_541.append(field_542);
                  }
            }
         }

         return var1;
      } catch (Exception var13) {
         System.out.println("Error loading stations!");
         var13.printStackTrace();
         return var1;
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }
      }
   }

   // $VF: renamed from: a () cj[]
   public static final class_40[] method_402() {
      class_40[] var0 = new class_40[class_90.field_1202.length];

      try {
         method_399("/data/txt/creatures.txt");
         field_541 = new StringBuffer(30);
         int var1 = 0;
         int var2 = 0;
         int[] var3 = new int[3];

         for (int var4 = 0; var4 < field_540.length; var4++) {
            field_542 = (char)field_540[var4];
            switch (field_542) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ',':
                  var3[var2] = Integer.parseInt(field_541.toString());
                  field_541 = new StringBuffer(30);
                  var2++;
                  break;
               case ';':
                  try {
                     var3[var2] = Integer.parseInt(field_541.toString());
                     var0[var1++] = new class_40(var3[0], var3[1], var3[2]);
                     var2 = 0;
                     field_541 = new StringBuffer(30);
                  } catch (NumberFormatException var10) {
                  }

                  field_541 = new StringBuffer(30);
                  break;
               default:
                  field_541.append(field_542);
            }
         }
      } catch (Exception var11) {
         System.out.println("Error loading creatures!");
         var11.printStackTrace();
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }

         field_540 = null;
      }

      return var0;
   }

   // $VF: renamed from: a () void
   public static final void method_403() {
      field_543 = null;
      field_540 = null;
   }

   // $VF: renamed from: a () byte[]
   public static final byte[] method_404() {
      if (field_543 != null) {
         return field_543;
      } else {
         field_543 = new byte[800];

         try {
            method_399("/data/txt/stations.txt");
            field_541 = new StringBuffer(30);
            int var0 = 0;

            for (int var1 = 0; var1 < field_540.length; var1++) {
               field_542 = (char)field_540[var1];
               switch (field_542) {
                  case '\t':
                  case '\n':
                  case '\r':
                     break;
                  case ',':
                  case ';':
                     try {
                        field_543[var0] = Byte.parseByte(field_541.toString());
                        if (var0 % 4 == 0) {
                           if (field_543[var0] == 0) {
                              field_543[var0] = -15;
                           } else if (field_543[var0] == 100) {
                              field_543[var0] = 115;
                           }
                        }

                        var0++;
                     } catch (NumberFormatException var7) {
                     }

                     field_541 = new StringBuffer(30);
                     break;
                  default:
                     field_541.append(field_542);
               }
            }
         } catch (Exception var8) {
            System.out.println("Error loading stations!");
            var8.printStackTrace();
         } finally {
            if (field_541 != null) {
               field_541 = null;
            }
         }

         return field_543;
      }
   }

   // $VF: renamed from: a () ac[]
   public static final class_120[] method_405() {
      try {
         method_399("/data/txt/goods.txt");
         field_541 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_540.length; var1++) {
            field_542 = (char)field_540[var1];
            switch (field_542) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_120[] var17 = new class_120[var0];
         byte[] var2 = new byte[var0];
         byte[] var3 = new byte[var0];
         int var4 = 0;
         int var5 = 0;
         int var6 = 0;
         int var7 = 0;
         int[] var8 = new int[7];
         int var9 = 0;

         while (var9 < field_540.length) {
            field_542 = (char)field_540[var9];
            switch (field_542) {
               case '\u000b':
               case '\f':
               default:
                  if (field_542 == ',') {
                     if (var7 == 6) {
                        var8[var7] = Integer.parseInt(field_541.toString());
                        var7 = 7;
                     } else if (var7 == 7) {
                        var2[var5++] = Byte.parseByte(field_541.toString());
                        var7 = 8;
                     } else {
                        var8[var7] = Integer.parseInt(field_541.toString());
                        var7++;
                     }

                     field_541 = new StringBuffer(30);
                  } else if (field_542 == ' ') {
                     if (var7 == 7) {
                        var2[var5++] = Byte.parseByte(field_541.toString());
                     } else if (var7 == 8) {
                        var3[var6++] = Byte.parseByte(field_541.toString());
                     }

                     field_541 = new StringBuffer(30);
                  } else if (field_542 == ';') {
                     if (var7 == 8) {
                        var3[var6++] = Byte.parseByte(field_541.toString());
                     } else {
                        var8[var7] = Integer.parseInt(field_541.toString());
                     }

                     byte[] var10 = new byte[var5];
                     byte[] var11 = new byte[var6];
                     if (var6 == 0 && var5 == 0) {
                        var10 = null;
                        var11 = null;
                     } else {
                        System.arraycopy(var2, 0, var10, 0, var5);
                        System.arraycopy(var3, 0, var11, 0, var6);
                     }

                     var17[var4++] = new class_120(var8[0], var8[1], var8[2], var8[3], var8[4], var8[5], var8[6], var10, var11);
                     field_541 = new StringBuffer(30);
                     var7 = 0;
                     var5 = 0;
                     var6 = 0;
                     var2 = new byte[var0];
                     var3 = new byte[var0];
                  } else {
                     field_541.append(field_542);
                  }
               case '\t':
               case '\n':
               case '\r':
                  var9++;
            }
         }

         return var17;
      } catch (Exception var15) {
         System.out.println("Error loading cargo!");
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }

         field_540 = null;
      }

      return null;
   }

   // $VF: renamed from: a () dn[]
   public static final class_19[] method_406() {
      try {
         method_399("/data/txt/equipment.txt");
         field_541 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_540.length; var1++) {
            field_542 = (char)field_540[var1];
            switch (field_542) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_19[] var11 = new class_19[var0];
         int var2 = 0;
         int var3 = 0;
         int[] var4 = new int[9];
         int var5 = 0;

         while (var5 < field_540.length) {
            field_542 = (char)field_540[var5];
            switch (field_542) {
               case '\u000b':
               case '\f':
               default:
                  if (field_542 == ',') {
                     var4[var3] = Integer.parseInt(field_541.toString());
                     var3++;
                     field_541 = new StringBuffer(30);
                  } else if (field_542 == ';') {
                     var4[var3] = Integer.parseInt(field_541.toString());
                     var11[var2++] = new class_19(var4[0], var4[1], var4[2], var4[3], var4[4], var4[5], var4[6], var4[7], var4[8]);
                     field_541 = new StringBuffer(30);
                     var3 = 0;
                  } else {
                     field_541.append(field_542);
                  }
               case '\t':
               case '\n':
               case '\r':
                  var5++;
            }
         }

         return var11;
      } catch (Exception var9) {
         System.out.println("Error loading equipment!");
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }

         field_540 = null;
      }

      return null;
   }

   // $VF: renamed from: a () bd[]
   public static final class_68[] method_407() {
      try {
         method_399("/data/txt/ships.txt");
         field_541 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_540.length; var1++) {
            field_542 = (char)field_540[var1];
            switch (field_542) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_68[] var11 = new class_68[var0];
         int var2 = 0;
         int var3 = 0;
         int[] var4 = new int[6];
         int var5 = 0;

         while (var5 < field_540.length) {
            field_542 = (char)field_540[var5];
            switch (field_542) {
               case '\u000b':
               case '\f':
               default:
                  if (field_542 == ',') {
                     var4[var3] = Integer.parseInt(field_541.toString());
                     field_541 = new StringBuffer(30);
                     var3++;
                  } else if (field_542 == ';') {
                     var4[var3] = Integer.parseInt(field_541.toString());
                     var11[var2++] = new class_68(var4[0], var4[1], var4[2], var4[3], var4[4], var4[5] / 100.0F);
                     field_541 = new StringBuffer(30);
                     var3 = 0;
                  } else {
                     field_541.append(field_542);
                  }
               case '\t':
               case '\n':
               case '\r':
                  var5++;
            }
         }

         return var11;
      } catch (Exception var9) {
         System.out.println("Error loading ships!");
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }

         field_540 = null;
      }

      return null;
   }

   // $VF: renamed from: a (int, boolean) java.lang.String[]
   public static final String[] method_408(int var0, boolean var1) {
      Object var2 = null;
      if (var0 == 3) {
         var2 = class_84.field_1079[1] + "_" + (var1 ? "m" : "f") + ".txt";
      } else {
         var2 = class_84.field_1079[0] + "_" + (var1 ? "m" : "f") + ".txt";
      }

      String[] var3 = null;

      try {
         method_399((String)var2);
         field_541 = new StringBuffer(30);
         int var4 = 0;

         for (int var5 = 0; var5 < field_540.length; var5++) {
            field_542 = (char)field_540[var5];
            switch (field_542) {
               case ';':
                  var4++;
                  break;
            }
         }

         var3 = new String[var4];
         int var13 = 0;

         for (int var6 = 0; var6 < field_540.length; var6++) {
            field_542 = (char)field_540[var6];
            switch (field_542) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ';':
                  var3[var13++] = field_541.toString();
                  field_541 = new StringBuffer(30);
                  break;
               default:
                  field_541.append(field_542);
            }
         }
      } catch (Exception var10) {
         System.out.println("Error loading names!");
      } finally {
         if (field_541 != null) {
            field_541 = null;
         }

         field_540 = null;
      }

      return var3;
   }

   // $VF: renamed from: a (java.lang.String) java.lang.Class
   public static final Class method_409(String var0) {
      try {
         return Class.forName(var0);
      } catch (ClassNotFoundException var2) {
         throw new NoClassDefFoundError(var2.getMessage());
      }
   }
}
