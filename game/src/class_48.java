import java.io.InputStream;

// $VF: renamed from: bw
public final class class_48 {
   // $VF: renamed from: a java.io.InputStream
   private static InputStream field_689;
   // $VF: renamed from: a byte[]
   private static byte[] field_690;
   // $VF: renamed from: a java.lang.StringBuffer
   private static StringBuffer field_691;
   // $VF: renamed from: a char
   private static char field_692;
   // $VF: renamed from: b byte[]
   private static byte[] field_693;
   // $VF: renamed from: a java.lang.String
   private static String field_694;
   // $VF: renamed from: a java.lang.Class
   public static Class field_695;

   private class_48() {
   }

   // $VF: renamed from: a (java.lang.String) void
   private static void method_462(String var0) throws Exception {
      if (field_694 != var0 || field_690 == null) {
         field_689 = class_48.class.getResourceAsStream(var0);
         java.io.DataInputStream var1dis = new java.io.DataInputStream(field_689);
         field_690 = new byte[field_689.available()];
         var1dis.readFully(field_690);
         var1dis.close();
         field_694 = var0;
      }
   }

   // $VF: renamed from: a (int) an
   public static final class_60 method_463(int var0) {
      return method_464(new short[]{(short)var0})[0];
   }

   // $VF: renamed from: a (short[]) an[]
   public static final class_60[] method_464(short[] var0) {
      class_60[] var1 = new class_60[var0.length];

      try {
         method_462("/data/txt/stations.txt");
         field_691 = new StringBuffer(30);
         String var2 = "";
         byte[] var3 = new byte[4];
         short var4 = 0;
         short var5 = 0;
         short var6 = 0;
         boolean var7 = 0 == var0[0];

         for (int var8 = 0; var8 < field_690.length; var8++) {
            field_692 = (char)field_690[var8];
            switch (field_692) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ',':
                  if (var7) {
                     if (var4 == 0) {
                        var2 = field_691.toString();
                     } else {
                        var3[var4 - 1] = Byte.parseByte(field_691.toString());
                     }

                     var4++;
                  }

                  field_691 = new StringBuffer(30);
                  break;
               case ';':
                  if (var7) {
                     var3[var4 - 1] = Byte.parseByte(field_691.toString());
                     var4 = 0;
                     if (var6 == var0[var5]) {
                        if (var3[3] == 0) {
                           var3[3] = -10;
                        } else if (var3[3] == 100) {
                           var3[3] = 115;
                        }

                        var1[var5++] = new class_60(var2, var6, var3[0], var3[1], var3[2], var3[3]);
                        if (var5 >= var0.length) {
                           return var1;
                        }
                     }
                  }

                  var6++;
                  if (var7) {
                     field_691 = new StringBuffer(30);
                  }

                  var7 = var6 == var0[var5];
                  break;
               default:
                  if (var7) {
                     field_691.append(field_692);
                  }
            }
         }

         return var1;
      } catch (Exception var13) {
         System.out.println("Error loading stations!");
         var13.printStackTrace();
         return var1;
      } finally {
         if (field_691 != null) {
            field_691 = null;
         }
      }
   }

   // $VF: renamed from: a () cj[]
   public static final class_63[] method_465() {
      class_63[] var0 = new class_63[class_24.field_358.length];

      try {
         method_462("/data/txt/creatures.txt");
         field_691 = new StringBuffer(30);
         int var1 = 0;
         int var2 = 0;
         int[] var3 = new int[3];

         for (int var4 = 0; var4 < field_690.length; var4++) {
            field_692 = (char)field_690[var4];
            switch (field_692) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ',':
                  var3[var2] = Integer.parseInt(field_691.toString());
                  field_691 = new StringBuffer(30);
                  var2++;
                  break;
               case ';':
                  try {
                     var3[var2] = Integer.parseInt(field_691.toString());
                     var0[var1++] = new class_63(var3[0], var3[1], var3[2]);
                     var2 = 0;
                     field_691 = new StringBuffer(30);
                  } catch (NumberFormatException var10) {
                  }

                  field_691 = new StringBuffer(30);
                  break;
               default:
                  field_691.append(field_692);
            }
         }
      } catch (Exception var11) {
         System.out.println("Error loading creatures!");
         var11.printStackTrace();
      } finally {
         if (field_691 != null) {
            field_691 = null;
         }

         field_690 = null;
      }

      return var0;
   }

   // $VF: renamed from: a () void
   public static final void method_466() {
      field_693 = null;
      field_690 = null;
   }

   // $VF: renamed from: a () byte[]
   public static final byte[] method_467() {
      if (field_693 != null) {
         return field_693;
      } else {
         field_693 = new byte[800];

         try {
            method_462("/data/txt/stations.txt");
            field_691 = new StringBuffer(30);
            int var0 = 0;

            for (int var1 = 0; var1 < field_690.length; var1++) {
               field_692 = (char)field_690[var1];
               switch (field_692) {
                  case '\t':
                  case '\n':
                  case '\r':
                     break;
                  case ',':
                  case ';':
                     try {
                        field_693[var0] = Byte.parseByte(field_691.toString());
                        if (var0 % 4 == 0) {
                           if (field_693[var0] == 0) {
                              field_693[var0] = -15;
                           } else if (field_693[var0] == 100) {
                              field_693[var0] = 115;
                           }
                        }

                        var0++;
                     } catch (NumberFormatException var7) {
                     }

                     field_691 = new StringBuffer(30);
                     break;
                  default:
                     field_691.append(field_692);
               }
            }
         } catch (Exception var8) {
            System.out.println("Error loading stations!");
            var8.printStackTrace();
         } finally {
            if (field_691 != null) {
               field_691 = null;
            }
         }

         return field_693;
      }
   }

   // $VF: renamed from: a () aa[]
   public static final class_46[] method_468() {
      try {
         method_462("/data/txt/goods.txt");
         field_691 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_690.length; var1++) {
            field_692 = (char)field_690[var1];
            switch (field_692) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_46[] var17 = new class_46[var0];
         byte[] var2 = new byte[var0];
         byte[] var3 = new byte[var0];
         int var4 = 0;
         int var5 = 0;
         int var6 = 0;
         int var7 = 0;
         int[] var8 = new int[7];
         int var9 = 0;

         while (var9 < field_690.length) {
            field_692 = (char)field_690[var9];
            switch (field_692) {
               case '\u000b':
               case '\f':
               default:
                  if (field_692 == ',') {
                     if (var7 == 6) {
                        var8[var7] = Integer.parseInt(field_691.toString());
                        var7 = 7;
                     } else if (var7 == 7) {
                        var2[var5++] = Byte.parseByte(field_691.toString());
                        var7 = 8;
                     } else {
                        var8[var7] = Integer.parseInt(field_691.toString());
                        var7++;
                     }

                     field_691 = new StringBuffer(30);
                  } else if (field_692 == ' ') {
                     if (var7 == 7) {
                        var2[var5++] = Byte.parseByte(field_691.toString());
                     } else if (var7 == 8) {
                        var3[var6++] = Byte.parseByte(field_691.toString());
                     }

                     field_691 = new StringBuffer(30);
                  } else if (field_692 == ';') {
                     if (var7 == 8) {
                        var3[var6++] = Byte.parseByte(field_691.toString());
                     } else {
                        var8[var7] = Integer.parseInt(field_691.toString());
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

                     var17[var4++] = new class_46(var8[0], var8[1], var8[2], var8[3], var8[4], var8[5], var8[6], var10, var11);
                     field_691 = new StringBuffer(30);
                     var7 = 0;
                     var5 = 0;
                     var6 = 0;
                     var2 = new byte[var0];
                     var3 = new byte[var0];
                  } else {
                     field_691.append(field_692);
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
         if (field_691 != null) {
            field_691 = null;
         }

         field_690 = null;
      }

      return null;
   }

   // $VF: renamed from: a () dn[]
   public static final class_51[] method_469() {
      try {
         method_462("/data/txt/equipment.txt");
         field_691 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_690.length; var1++) {
            field_692 = (char)field_690[var1];
            switch (field_692) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_51[] var11 = new class_51[var0];
         int var2 = 0;
         int var3 = 0;
         int[] var4 = new int[9];
         int var5 = 0;

         while (var5 < field_690.length) {
            field_692 = (char)field_690[var5];
            switch (field_692) {
               case '\u000b':
               case '\f':
               default:
                  if (field_692 == ',') {
                     var4[var3] = Integer.parseInt(field_691.toString());
                     var3++;
                     field_691 = new StringBuffer(30);
                  } else if (field_692 == ';') {
                     var4[var3] = Integer.parseInt(field_691.toString());
                     var11[var2++] = new class_51(var4[0], var4[1], var4[2], var4[3], var4[4], var4[5], var4[6], var4[7], var4[8]);
                     field_691 = new StringBuffer(30);
                     var3 = 0;
                  } else {
                     field_691.append(field_692);
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
         if (field_691 != null) {
            field_691 = null;
         }

         field_690 = null;
      }

      return null;
   }

   // $VF: renamed from: a () be[]
   public static final class_32[] method_470() {
      try {
         method_462("/data/txt/ships.txt");
         field_691 = new StringBuffer(30);
         int var0 = 0;

         for (int var1 = 0; var1 < field_690.length; var1++) {
            field_692 = (char)field_690[var1];
            switch (field_692) {
               case ';':
                  var0++;
                  break;
            }
         }

         class_32[] var11 = new class_32[var0];
         int var2 = 0;
         int var3 = 0;
         int[] var4 = new int[6];
         int var5 = 0;

         while (var5 < field_690.length) {
            field_692 = (char)field_690[var5];
            switch (field_692) {
               case '\u000b':
               case '\f':
               default:
                  if (field_692 == ',') {
                     var4[var3] = Integer.parseInt(field_691.toString());
                     field_691 = new StringBuffer(30);
                     var3++;
                  } else if (field_692 == ';') {
                     var4[var3] = Integer.parseInt(field_691.toString());
                     var11[var2++] = new class_32(var4[0], var4[1], var4[2], var4[3], var4[4], var4[5] / 100.0F);
                     field_691 = new StringBuffer(30);
                     var3 = 0;
                  } else {
                     field_691.append(field_692);
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
         if (field_691 != null) {
            field_691 = null;
         }

         field_690 = null;
      }

      return null;
   }

   // $VF: renamed from: a (int, boolean) java.lang.String[]
   public static final String[] method_471(int var0, boolean var1) {
      Object var2 = null;
      if (var0 == 3) {
         var2 = class_41.field_496[1] + "_" + (var1 ? "m" : "f") + ".txt";
      } else {
         var2 = class_41.field_496[0] + "_" + (var1 ? "m" : "f") + ".txt";
      }

      String[] var3 = null;

      try {
         method_462((String)var2);
         field_691 = new StringBuffer(30);
         int var4 = 0;

         for (int var5 = 0; var5 < field_690.length; var5++) {
            field_692 = (char)field_690[var5];
            switch (field_692) {
               case ';':
                  var4++;
                  break;
            }
         }

         var3 = new String[var4];
         int var13 = 0;

         for (int var6 = 0; var6 < field_690.length; var6++) {
            field_692 = (char)field_690[var6];
            switch (field_692) {
               case '\t':
               case '\n':
               case '\r':
                  break;
               case ';':
                  var3[var13++] = field_691.toString();
                  field_691 = new StringBuffer(30);
                  break;
               default:
                  field_691.append(field_692);
            }
         }
      } catch (Exception var10) {
         System.out.println("Error loading names!");
      } finally {
         if (field_691 != null) {
            field_691 = null;
         }

         field_690 = null;
      }

      return var3;
   }

   // $VF: renamed from: a (java.lang.String) java.lang.Class
   public static final Class method_472(String var0) {
      try {
         return Class.forName(var0);
      } catch (ClassNotFoundException var2) {
         throw new NoClassDefFoundError(var2.getMessage());
      }
   }
}
