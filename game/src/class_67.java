import javax.microedition.lcdui.Image;

// $VF: renamed from: bu
public final class class_67 {
   // $VF: renamed from: a int
   private static int field_897;
   // $VF: renamed from: b int
   private static int field_898;
   // $VF: renamed from: c int
   private static int field_899;
   // $VF: renamed from: a int[]
   private static int[] field_900 = new int[]{6, 4, 3, 3, 3, 5, 10, 0, 0, 2, 12, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_901;
   // $VF: renamed from: d int
   private int field_902;
   // $VF: renamed from: e int
   private int field_903;
   // $VF: renamed from: f int
   private int field_904;
   // $VF: renamed from: g int
   private int field_905;
   // $VF: renamed from: a java.lang.String
   private String field_906;
   // $VF: renamed from: a z
   private class_53 field_907;
   // $VF: renamed from: b boolean
   private boolean field_908;
   // $VF: renamed from: c boolean
   private boolean field_909;
   // $VF: renamed from: a cg[]
   private class_45[] field_910;
   // $VF: renamed from: b java.lang.String
   private String field_911;
   // $VF: renamed from: a db
   private class_73 field_912;
   // $VF: renamed from: a dc
   private class_18 field_913;
   // $VF: renamed from: b dc
   private class_18 field_914;
   // $VF: renamed from: c dc
   private class_18 field_915;
   // $VF: renamed from: a ct
   private class_59 field_916;
   // $VF: renamed from: h int
   private int field_917;
   // $VF: renamed from: a byte[]
   private byte[] field_918;
   // $VF: renamed from: a bs
   private class_123 field_919;
   // $VF: renamed from: a cs
   private class_78 field_920;
   // $VF: renamed from: i int
   private int field_921;
   // $VF: renamed from: a boolean
   public static boolean field_922;
   // $VF: renamed from: d boolean
   private boolean field_923 = false;
   // $VF: renamed from: c java.lang.String
   private String field_924 = null;
   // $VF: renamed from: d java.lang.String
   private String field_925 = null;
   // $VF: renamed from: e java.lang.String
   private String field_926 = null;
   // $VF: renamed from: j int
   private int field_927 = -1;

   public class_67() {
      this.method_623();
      if (this.field_923) {
         field_900[0] = 7;
      }

      this.field_901 = class_94.method_784();
      field_898 = this.field_901.getHeight() + 25;
      field_899 = 114;
      field_897 = class_41.field_537 - field_899 >> 1;
      this.field_902 = class_50.method_494();
      this.field_904 = 0;
      this.field_905 = 0;
      this.field_907 = new class_53(20, class_41.field_538 / 2, class_41.field_537 - 40);
      this.field_908 = false;
      this.field_909 = false;
      this.field_913 = new class_18(
         field_897 + 5,
         field_898 + 12,
         field_899 - 10,
         class_41.field_538 - field_898 - 3 * class_69.method_653(),
         class_41.field_533.method_297(25) + "\n\n" + class_41.field_533.method_297(28)
      );
      this.field_914 = new class_18(field_897 + 5, field_898 + 12, field_899 - 10, class_41.field_538 - field_898 - 3 * class_69.method_653(), "");
      this.field_915 = new class_18(field_897 + 5, field_898 + 12, field_899 - 10, class_41.field_538 - field_898 - 3 * class_69.method_653(), "");
      String[] var1 = new String[class_22.field_316.length];

      for (int var2 = 0; var2 < var1.length; var2++) {
         var1[var2] = class_41.field_533.method_297(class_22.field_315[var2]);
      }

      this.field_912 = new class_73(field_897, field_898, field_899, class_41.field_538 - field_898 - class_69.method_653(), null);
      this.field_912.field_1063 = 12;
      this.field_912.method_693(0, var1);
      this.field_912.field_1067 = true;
      this.field_912.field_1066 = false;
      this.field_912.method_704();
      this.field_916 = new class_59(10);
      this.field_921 = class_41.field_500;

      try {
         Class.forName("javax.microedition.media.control.VideoControl");
         this.field_919 = new class_123();
         if (System.getProperty("supports.video.capture").equalsIgnoreCase("false")) {
            throw new Exception();
         }
      } catch (Exception var3) {
         this.field_919 = null;
         field_900[12] = 2;
      }

      field_922 = true;
   }

   // $VF: renamed from: a (java.lang.String) java.lang.String
   private String method_622(String var1) {
      int var2 = 0;
      int var3 = var1.length();
      StringBuffer var4 = new StringBuffer();

      while (var2 < var3) {
         char var5;
         if ((var5 = var1.charAt(var2)) == '\\' && var2 + 6 <= var3 && var1.charAt(var2 + 1) == 'u') {
            char var7 = (char)Integer.parseInt(var1.substring(var2 + 2, var2 + 6), 16);
            var4.append(var7);
            var2 += 6;
         } else {
            var4.append(var5);
            var2++;
         }
      }

      return var4.toString();
   }

   // $VF: renamed from: f () void
   private void method_623() {
      try {
         try {
            this.field_924 = class_41.field_536.getAppProperty("Operator-URL-en");
            this.field_926 = class_41.field_536.getAppProperty("Operator-Menu-en");
         } catch (Exception var10) {
            this.field_923 = false;
            this.field_924 = null;
            this.field_925 = null;
            this.field_926 = null;

            try {
               this.field_924 = class_41.field_536.getAppProperty("Operator-URL-gn");
               this.field_926 = class_41.field_536.getAppProperty("Operator-Menu-gn");
            } catch (Exception var9) {
               this.field_923 = false;
               return;
            }

            if (this.field_924 == null || this.field_926 == null) {
               this.field_923 = false;
               return;
            }
         }

         if (this.field_924 == null || this.field_926 == null) {
            try {
               this.field_924 = class_41.field_536.getAppProperty("Operator-URL-gn");
               this.field_926 = class_41.field_536.getAppProperty("Operator-Menu-gn");
            } catch (Exception var8) {
               this.field_923 = false;
               return;
            }
         }

         try {
            this.field_925 = class_41.field_536.getAppProperty("Operator-Prompt-en");
         } catch (Exception var7) {
            this.field_925 = null;

            try {
               this.field_925 = class_41.field_536.getAppProperty("Operator-Prompt-gn");
            } catch (Exception var6) {
            }
         }

         if (this.field_925 == null) {
            try {
               this.field_925 = class_41.field_536.getAppProperty("Operator-Prompt-gn");
            } catch (Exception var5) {
            }
         }

         if (this.field_925 != null) {
            this.field_925 = this.method_622(this.field_925);
         }

         if (this.field_926 != null) {
            this.field_926 = this.method_622(this.field_926);
         }

         System.out.println("wap_url: " + this.field_924);
         System.out.println("wap_menu: " + this.field_926);
         System.out.println("wap_prompt: " + this.field_925);
         String var1 = class_41.field_536.getAppProperty("Operator-Mode");
         if (this.field_924 != null && var1 != null) {
            char[] var2 = new char[]{'1', '2'};

            for (int var3 = 0; var3 < var2.length; var3++) {
               int var4;
               if ((var4 = var1.indexOf(String.valueOf(var2[var3]))) >= 0) {
                  this.field_927 = Integer.valueOf(String.valueOf(var1.charAt(var4)));
               }
            }

            System.out.println("wap_mode: " + this.field_927);
            if (this.field_927 < 1 || this.field_927 > 2) {
               this.field_927 = 2;
            }

            this.field_923 = true;
         } else {
            throw new Exception();
         }
      } catch (Exception var11) {
         this.field_923 = false;
      }
   }

   // $VF: renamed from: a () void
   public final void method_624() {
      this.field_910 = null;
      this.field_907 = null;
      this.field_901 = null;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_625(int var1, int var2) {
      this.field_917 = var2;
      class_69.method_655(var2);
      if ((var1 & 64) != 0) {
         if (this.field_905 >= 15) {
            this.field_914.method_276(var2);
            return;
         }

         if (this.field_905 == 8) {
            this.field_913.method_276(var2);
            return;
         }
      } else if ((var1 & 2) != 0) {
         if (this.field_905 >= 15) {
            this.field_914.method_277(var2);
            return;
         }

         if (this.field_905 == 8) {
            this.field_913.method_277(var2);
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_626() {
      switch (this.field_905) {
         case 0:
            if (this.field_908 && this.field_904 == 5) {
               if (this.field_907.method_515()) {
                  class_41.field_543.method_214();
                  return true;
               }

               this.field_908 = false;
               return false;
            }

            switch (this.field_904) {
               case 0:
                  if (class_3.method_142() > 0L) {
                     if (!this.field_908) {
                        this.field_907.method_514(class_41.field_533.method_297(34), true);
                        this.field_908 = true;
                        return false;
                     }

                     if (this.field_907.method_515()) {
                        this.field_905 = 11;
                        this.field_904 = 0;
                     }

                     this.field_908 = false;
                  } else {
                     this.field_905 = 11;
                     this.field_904 = 0;
                  }

                  return false;
               case 1:
                  this.field_905 = 1;
                  if (this.field_910 == null) {
                     this.field_910 = class_81.method_728();
                  }

                  this.field_904 = 0;
                  return false;
               case 2:
                  this.field_905 = 2;
                  if (this.field_910 == null) {
                     this.field_910 = class_81.method_728();
                  }

                  this.field_904 = 0;
                  return false;
               case 3:
                  this.field_905 = 3;
                  this.field_904 = 0;
                  return false;
               case 4:
                  this.field_905 = 4;
                  this.field_904 = 0;
                  return false;
               case 5:
                  if (!this.field_908) {
                     this.field_907.method_514(class_41.field_533.method_297(35), true);
                     this.field_908 = true;
                  }

                  return false;
               case 6:
                  if (this.field_923) {
                     switch (this.field_927) {
                        case 1:
                           try {
                              if (!this.field_908 && this.field_925 != null) {
                                 this.field_907.method_514(this.field_925, true);
                              } else if (this.field_925 == null || this.field_907.method_515()) {
                                 class_41.field_536.platformRequest(this.field_924);
                                 class_41.field_543.method_214();
                                 return true;
                              }

                              if (this.field_925 != null) {
                                 this.field_908 = !this.field_908;
                              }
                           } catch (Exception var4) {
                           }

                           return false;
                        default:
                           try {
                              if (!this.field_908 && this.field_925 != null) {
                                 this.field_907.method_514(this.field_925, true);
                              } else if (this.field_925 == null || this.field_907.method_515()) {
                                 class_41.field_536.platformRequest(this.field_924);
                              }

                              if (this.field_925 != null) {
                                 this.field_908 = !this.field_908;
                              }
                           } catch (Exception var3) {
                           }

                           return false;
                     }
                  }

                  return false;
               default:
                  return false;
            }
         case 1:
            if (this.field_910[this.field_904] != null) {
               if (class_3.method_142() <= 0L) {
                  this.field_910[this.field_904].method_441();
                  ((class_118)class_41.field_544[1]).method_919();
                  class_41.field_543.method_213(class_41.field_544[1]);
                  return true;
               }

               if (!this.field_908) {
                  this.field_907.method_514(class_41.field_533.method_297(33), true);
                  this.field_908 = true;
               } else {
                  if (this.field_907.method_515()) {
                     this.field_910[this.field_904].method_441();
                     ((class_118)class_41.field_544[1]).method_919();
                     class_41.field_543.method_213(class_41.field_544[1]);
                  }

                  this.field_908 = false;
               }
            }
            break;
         case 2:
            if (this.field_908) {
               if (!this.field_907.method_515()) {
                  this.field_908 = false;
                  return true;
               }

               class_41.field_530.method_788(false);
               class_81.method_733(this.field_904);
               this.field_910[this.field_904] = class_81.method_729(this.field_904);
               class_41.field_530.method_787();
               this.field_907.method_514(class_41.field_533.method_297(32), false);
            } else if (this.field_910[this.field_904] != null) {
               this.field_907.method_514(class_41.field_533.method_297(31), true);
               this.field_908 = true;
            } else {
               class_41.field_530.method_788(false);
               class_81.method_733(this.field_904);
               this.field_910 = class_81.method_728();
               class_41.field_530.method_787();
               this.field_907.method_514(class_41.field_533.method_297(32), false);
               this.field_908 = true;
            }
            break;
         case 3:
            this.method_631();
            break;
         case 4:
            switch (this.field_904) {
               case 0:
                  this.field_905 = 6;
                  this.field_904 = 0;
                  this.field_912.field_1058 = 0;
                  return false;
               case 1:
                  this.field_905 = 7;
                  return false;
               case 2:
                  this.field_905 = 8;
                  return false;
               default:
                  return false;
            }
         case 5:
            if (this.field_908) {
               if (this.field_907.method_515()) {
                  class_41.field_543.method_213(class_41.field_544[0]);
                  class_41.field_539.method_425(0);
                  return true;
               }

               this.field_908 = false;
            } else {
               switch (this.field_904) {
                  case 0:
                     this.field_905 = 3;
                     this.field_904 = 0;
                     return false;
                  case 1:
                     this.field_905 = 4;
                     this.field_904 = 0;
                     return false;
                  case 2:
                     if (!class_3.method_62().method_789() && !class_3.method_62().field_1241) {
                        this.field_915
                           .method_272(
                              class_3.method_149(
                                    class_41.field_533.method_297(class_22.field_326[class_3.method_62().field_1226]), class_3.method_62().field_1233
                                 )
                                 + "\n\n"
                                 + class_3.method_149(
                                    class_41.field_533.method_297(class_22.field_327[class_3.method_62().field_1226]), class_3.method_62().field_1233
                                 )
                           );
                     } else if (!class_3.method_76()) {
                        String var1 = class_3.method_149(class_41.field_533.method_297(class_22.field_325[class_3.method_73()]), class_3.method_67().field_1233);
                        class_95 var2;
                        if ((var2 = class_3.method_67()).field_1226 == 16) {
                           var1 = var1 + " " + class_3.method_132() + " / " + var2.field_1250;
                        } else if (var2.field_1226 == 18) {
                           var1 = var1 + " " + class_3.method_107() + " / " + var2.field_1250;
                        } else if (var2.field_1226 == 21) {
                           var1 = var1 + " " + class_3.method_121() + " / " + var2.field_1250;
                        } else if (var2.field_1226 == 15) {
                           var1 = var1 + " " + class_3.method_139() + " / " + var2.field_1250;
                        }

                        this.field_915
                           .method_272(
                              class_3.method_149(class_41.field_533.method_297(class_22.field_324[class_3.method_73()]), class_3.method_67().field_1233)
                                 + "\n\n"
                                 + var1
                           );
                     } else if (class_3.method_76()) {
                        this.field_915.method_272(class_41.field_533.method_297(609));
                     }

                     this.field_905 = 13;
                     this.field_904 = 0;
                     return false;
                  case 3:
                     this.field_905 = 14;
                     this.field_920 = new class_78(field_897, field_898, field_899, class_41.field_538 - 2 * field_898);
                     return false;
                  case 4:
                     if (!this.field_908) {
                        this.field_907.method_514(class_41.field_533.method_297(35), true);
                        this.field_908 = true;
                     }
               }
            }
            break;
         case 6:
            this.field_914.method_271();
            this.field_914.method_272(class_41.field_533.method_297(class_22.field_316[this.field_904]));
            this.field_905 = 15 + this.field_904;
            if (this.field_904 == 0) {
               this.field_914
                  .method_272(
                     class_41.field_533.method_297(631)
                        + "\n\n"
                        + class_41.field_533.method_297(633)
                        + "\n\n"
                        + class_41.field_533.method_297(642)
                        + "\n\n"
                        + class_41.field_533.method_297(643)
                        + "\n\n"
                        + class_41.field_533.method_297(641)
                        + "\n\n"
                        + class_41.field_533.method_297(664)
                        + "\n\n"
                  );
            }
         case 7:
         case 8:
         case 10:
         case 11:
         default:
            break;
         case 9:
            switch (this.field_904) {
               case 0:
                  if (class_3.method_142() > 0L) {
                     if (!this.field_908) {
                        this.field_907.method_514(class_41.field_533.method_297(34), true);
                        this.field_908 = true;
                        return false;
                     }

                     if (this.field_907.method_515()) {
                        this.field_905 = 11;
                        this.field_904 = 0;
                     }

                     this.field_908 = false;
                  } else {
                     this.field_905 = 11;
                     this.field_904 = 0;
                  }

                  return false;
               case 1:
                  this.field_905 = 10;
                  this.field_904 = 0;
                  return false;
               default:
                  return false;
            }
         case 12:
            if (this.field_908) {
               if (this.field_907.method_515()) {
                  class_3.method_151();
                  class_41.field_543.method_213(class_41.field_544[2]);
                  class_41.field_539.method_430();
                  return true;
               }

               this.field_908 = false;
            } else {
               if (this.field_904 == 2 || this.field_919 == null && this.field_904 == 1) {
                  if (field_922) {
                     class_3.method_146(this.field_918);
                     class_3.method_148(null);
                  } else {
                     class_3.method_148(this.field_919.field_1532);
                     class_3.method_146(null);
                  }

                  this.field_907.method_514(class_3.method_143() + ", " + class_41.field_533.method_297(298), true);
                  this.field_908 = true;
               }

               if (this.field_904 == 0) {
                  this.field_918 = class_119.method_925(true, 3);
                  field_922 = true;
               } else if (this.field_919 != null && this.field_904 == 1) {
                  this.field_919.method_935();
                  this.field_919.method_933();
               }
            }
      }

      return false;
   }

   // $VF: renamed from: a (int) void
   public final void method_627(int var1) {
      if (!this.field_908) {
         if (this.field_905 != 7 && this.field_905 != 8 && this.field_905 != 13 && this.field_905 != 14 && this.field_905 < 15) {
            if (this.field_904 > 0) {
               this.field_904--;
            } else {
               this.field_904 = field_900[this.field_905] - 1;
            }

            if (this.field_904 == 2 && this.field_905 == 0 && class_3.method_142() == 0L) {
               this.field_904--;
            }

            if (this.field_905 == 6) {
               this.field_912.method_697();
               return;
            }
         } else {
            if (this.field_905 == 13) {
               this.field_915.method_277(var1);
               return;
            }

            if (this.field_905 == 14) {
               this.field_920.method_697();
            }
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_628(int var1) {
      if (!this.field_908) {
         if (this.field_905 != 7 && this.field_905 != 8 && this.field_905 != 13 && this.field_905 != 14 && this.field_905 < 15) {
            if (this.field_904 < field_900[this.field_905] - 1) {
               this.field_904++;
            } else {
               this.field_904 = 0;
            }

            if (this.field_904 == 2 && this.field_905 == 0 && class_3.method_142() == 0L) {
               this.field_904++;
            }

            if (this.field_905 == 6) {
               this.field_912.method_698();
               return;
            }
         } else {
            if (this.field_905 == 13) {
               this.field_915.method_276(var1);
               return;
            }

            if (this.field_905 == 14) {
               this.field_920.method_698();
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_629() {
      if (this.field_908) {
         this.field_907.method_516();
      } else {
         if (this.field_905 == 3) {
            switch (this.field_904) {
               case 0:
                  this.field_921--;
                  this.method_630();
                  return;
               case 1:
                  this.method_631();
                  return;
               case 2:
                  this.method_631();
            }
         }
      }
   }

   // $VF: renamed from: g () void
   private void method_630() {
      if (this.field_921 < 0) {
         this.field_921 = 3;
      }

      if (this.field_921 > 3) {
         this.field_921 = 0;
      }

      switch (this.field_921) {
         case 0:
            class_41.field_497 = true;
            class_41.field_539.method_422(60);
            if (class_41.field_543.field_179 != class_41.field_544[2] && !class_41.field_539.method_424()) {
               class_41.field_539.method_425(0);
            }
            break;
         case 1:
            class_41.field_497 = true;
            class_41.field_539.method_422(80);
            break;
         case 2:
            class_41.field_497 = true;
            class_41.field_539.method_422(100);
            if (class_41.field_543.field_179 != class_41.field_544[2] && !class_41.field_539.method_424()) {
               class_41.field_539.method_425(0);
            }
            break;
         case 3:
            class_41.field_539.method_430();
            class_41.field_497 = false;
      }

      class_41.field_500 = this.field_921;
   }

   // $VF: renamed from: c () void
   public final void method_631() {
      if (this.field_908) {
         this.field_907.method_517();
      } else {
         if (this.field_905 == 3) {
            switch (this.field_904) {
               case 0:
                  this.field_921++;
                  this.method_630();
                  return;
               case 1:
                  class_41.field_498 = !class_41.field_498;
                  if (class_41.field_498) {
                     class_41.method_415(150);
                     return;
                  }
                  break;
               case 2:
                  class_41.field_499 = !class_41.field_499;
            }
         }
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_632() {
      if (this.field_908) {
         return false;
      } else if (this.field_905 != 0 && this.field_905 != 5) {
         if (this.field_905 == 3) {
            class_81.method_731();
         }

         if (this.field_905 == 7) {
            this.field_904 = 1;
            this.field_905 = 4;
            return false;
         } else if (this.field_905 == 6) {
            this.field_904 = 0;
            this.field_905 = 4;
            return false;
         } else if (this.field_905 >= 15) {
            this.field_905 = 6;
            return false;
         } else if (this.field_905 == 13) {
            this.field_904 = 2;
            this.field_905 = 5;
            return false;
         } else if (this.field_905 == 14) {
            this.field_904 = 3;
            this.field_905 = 5;
            return false;
         } else if (this.field_905 == 10) {
            this.field_904 = 1;
            this.field_905 = 9;
            return false;
         } else if (this.field_905 == 8) {
            this.field_904 = 2;
            this.field_905 = 4;
            return false;
         } else if (this.field_905 == 12) {
            this.field_905 = 11;
            return false;
         } else if (this.field_905 == 11) {
            return false;
         } else {
            if (this.field_905 > 0 || this.field_905 == 9) {
               if (this.field_905 == 9) {
                  this.field_904 = 0;
               } else {
                  this.field_904 = this.field_905;
               }

               this.field_905 = 0;
               if (this.field_909) {
                  this.method_635();
               }
            }

            return false;
         }
      } else {
         return true;
      }
   }

   // $VF: renamed from: c () boolean
   public final boolean method_633() {
      if (this.field_905 == 11) {
         if (this.field_916.field_825.length() > 0) {
            class_3.method_144((this.field_916.field_825 + (this.field_916.field_824 != ' ' ? this.field_916.field_824 : ' ')).trim());
            this.field_905 = 12;
            this.field_918 = class_119.method_925(true, 3);
            this.field_904 = 0;
         }
      } else {
         this.method_626();
      }

      return false;
   }

   // $VF: renamed from: c (int) void
   public final void method_634(int var1) {
      this.field_904 = var1;
      this.field_905 = 0;
   }

   // $VF: renamed from: d () void
   public final void method_635() {
      this.field_905 = 5;
      this.field_904 = 0;
      this.field_908 = false;
      this.field_909 = true;
   }

   // $VF: renamed from: e () void
   public final void method_636() {
      class_41.field_534.drawImage(this.field_901, class_41.field_537 / 2, 10, 17);
      switch (this.field_905) {
         case 0:
            this.field_903 = class_3.method_142() > 0L ? this.field_902 : 0;
            class_69.method_667(
               class_41.field_533.method_297(67),
               field_897,
               field_898,
               field_899,
               ((class_3.method_142() > 0L ? field_900[this.field_905] : field_900[this.field_905] - 1) + 2) * this.field_902
            );
            class_69.method_660(class_41.field_533.method_297(0), field_897, field_898 + 12, field_899, this.field_904 == 0);
            class_69.method_660(class_41.field_533.method_297(1), field_897, field_898 + 12 + this.field_902, field_899, this.field_904 == 1);
            if (class_3.method_142() > 0L) {
               class_69.method_660(class_41.field_533.method_297(2), field_897, field_898 + 12 + 2 * this.field_902, field_899, this.field_904 == 2);
            }

            class_69.method_660(
               class_41.field_533.method_297(3), field_897, field_898 + 12 + 2 * this.field_902 + this.field_903, field_899, this.field_904 == 3
            );
            class_69.method_660(
               class_41.field_533.method_297(4), field_897, field_898 + 12 + 3 * this.field_902 + this.field_903, field_899, this.field_904 == 4
            );
            class_69.method_660(
               class_41.field_533.method_297(5), field_897, field_898 + 12 + 4 * this.field_902 + this.field_903, field_899, this.field_904 == 5
            );
            if (this.field_923) {
               class_69.method_660(this.field_926, field_897, field_898 + 12 + 5 * this.field_902 + this.field_903, field_899, this.field_904 == 6);
            }
            break;
         case 1:
         case 2:
            if (this.field_905 == 2) {
               class_69.method_667(class_41.field_533.method_297(2), field_897, field_898, field_899, (field_900[this.field_905] + 3) * this.field_902);
            } else {
               class_69.method_667(class_41.field_533.method_297(1), field_897, field_898, field_899, (field_900[this.field_905] + 2) * this.field_902);
            }

            for (int var2 = 0; var2 < this.field_910.length; var2++) {
               this.field_906 = var2 + 1 + ".  ";
               if (this.field_910[var2] == null) {
                  this.field_906 = this.field_906 + class_41.field_533.method_297(30);
               } else {
                  this.field_906 = this.field_906 + class_122.method_932(this.field_910[var2].field_571);
                  this.field_911 = this.field_910[var2].field_591;
                  if (var2 == 3) {
                     this.field_906 = this.field_906 + " AUTOSAVE";
                  } else {
                     this.field_906 = this.field_906 + " " + this.field_911;
                  }
               }

               class_69.method_660(
                  class_69.method_676(this.field_906, field_899 - 12), field_897, field_898 + 12 + var2 * this.field_902, field_899, this.field_904 == var2
               );
            }
            break;
         case 3:
            class_69.method_667(class_41.field_533.method_297(3), field_897, field_898, field_899, (field_900[this.field_905] + 2) * this.field_902);
            class_69.method_660(
               class_41.field_533.method_297(6) + "    " + class_41.field_533.method_297(class_22.field_318[this.field_921]),
               field_897,
               field_898 + 12,
               field_899,
               this.field_904 == 0
            );
            class_69.method_660(
               class_41.field_533.method_297(10) + "    " + class_41.field_533.method_297(class_41.field_498 ? 14 : 15),
               field_897,
               field_898 + 12 + this.field_902,
               field_899,
               this.field_904 == 1
            );
            class_69.method_660(
               class_41.field_533.method_297(13) + "    " + class_41.field_533.method_297(class_41.field_499 ? 14 : 15),
               field_897,
               field_898 + 12 + 2 * this.field_902,
               field_899,
               this.field_904 == 2
            );
            break;
         case 4:
            class_69.method_667(class_41.field_533.method_297(4), field_897, field_898, field_899, (field_900[this.field_905] + 2) * this.field_902);
            class_69.method_660(class_41.field_533.method_297(18), field_897, field_898 + 12, field_899, this.field_904 == 0);
            class_69.method_660(class_41.field_533.method_297(19), field_897, field_898 + 12 + this.field_902, field_899, this.field_904 == 1);
            class_69.method_660(class_41.field_533.method_297(20), field_897, field_898 + 12 + 2 * this.field_902, field_899, this.field_904 == 2);
            break;
         case 5:
            class_69.method_667(class_41.field_533.method_297(16), field_897, field_898, field_899, (field_900[this.field_905] + 2) * this.field_902);
            class_69.method_660(class_41.field_533.method_297(3), field_897, field_898 + 12, field_899, this.field_904 == 0);
            class_69.method_660(class_41.field_533.method_297(4), field_897, field_898 + 12 + this.field_902, field_899, this.field_904 == 1);
            class_69.method_660(class_41.field_533.method_297(75), field_897, field_898 + 12 + 2 * this.field_902, field_899, this.field_904 == 2);
            class_69.method_660(class_41.field_533.method_297(266), field_897, field_898 + 12 + 3 * this.field_902, field_899, this.field_904 == 3);
            class_69.method_660(class_41.field_533.method_297(5), field_897, field_898 + 12 + 4 * this.field_902, field_899, this.field_904 == 4);
            break;
         case 6:
            class_69.method_667(class_41.field_533.method_297(18), field_897, field_898, field_899, class_41.field_538 - field_898 - class_69.method_653() - 10);
            this.field_912.method_705();
            this.field_912.method_702();
            break;
         case 7:
            class_69.method_667(class_41.field_533.method_297(19), field_897, field_898, field_899, 8 * this.field_902 + 3);
            class_50.method_485(class_41.field_533.method_297(21), field_897 + 10, field_898 + 12, 0);
            class_50.method_483("5", field_897 + field_899 - 10, field_898 + 12, 1, 2);
            class_50.method_485(class_41.field_533.method_297(12), field_897 + 10, field_898 + 12 + this.field_902, 0);
            class_50.method_483("7", field_897 + field_899 - 10, field_898 + 12 + this.field_902, 1, 2);
            class_50.method_485(class_41.field_533.method_297(22), field_897 + 10, field_898 + 12 + 2 * this.field_902, 0);
            class_50.method_483("1", field_897 + field_899 - 10, field_898 + 12 + 2 * this.field_902, 1, 2);
            class_50.method_485(class_41.field_533.method_297(323), field_897 + 10, field_898 + 12 + 3 * this.field_902, 0);
            class_50.method_483("9", field_897 + field_899 - 10, field_898 + 12 + 3 * this.field_902, 1, 2);
            class_50.method_485(class_41.field_533.method_297(137), field_897 + 10, field_898 + 12 + 4 * this.field_902, 0);
            class_50.method_483("3", field_897 + field_899 - 10, field_898 + 12 + 4 * this.field_902, 1, 2);
            class_50.method_485(class_41.field_533.method_297(23), field_897 + 10, field_898 + 12 + 5 * this.field_902, 0);
            class_50.method_483("*,0,#", field_897 + field_899 - 10, field_898 + 12 + 5 * this.field_902, 1, 2);
            class_50.method_485(class_41.field_533.method_297(24), field_897 + 10, field_898 + 12 + 6 * this.field_902, 0);
            class_50.method_483("0", field_897 + field_899 - 10, field_898 + 12 + 6 * this.field_902, 1, 2);
            break;
         case 8:
            class_69.method_667(class_41.field_533.method_297(20), field_897, field_898, field_899, class_41.field_538 - field_898 - class_69.method_653() - 10);
            class_50.method_485(
               class_41.field_541, (class_41.field_537 >> 1) - (class_50.method_490(class_41.field_541) >> 1), 10 + this.field_901.getHeight() + 2, 1
            );
            this.field_913.method_278();
            break;
         case 9:
            class_69.method_667(class_41.field_533.method_297(0), field_897, field_898, field_899, (field_900[this.field_905] + 2) * this.field_902);
            class_69.method_660(class_41.field_533.method_297(232), field_897, field_898 + 12, field_899, this.field_904 == 0);
            class_69.method_660(class_41.field_533.method_297(231), field_897, field_898 + 12 + this.field_902, field_899, this.field_904 == 1);
         case 10:
         default:
            break;
         case 11:
            class_69.method_668(class_41.field_533.method_297(38), field_897, field_898, field_899, 4 * this.field_902, true);
            class_50.method_485(class_41.field_533.method_297(299) + ":", field_897 + 10, field_898 + 12, 1);
            this.field_916.method_582(this.field_917);
            class_50.method_485(this.field_916.field_825 + this.field_916.field_824, field_897 + 10, field_898 + 12 + this.field_902, 0);
            if (class_69.method_657()) {
               class_50.method_485("_", field_897 + 10 + class_50.method_490(this.field_916.field_825), field_898 + 12 + 2 + this.field_902, 0);
            }
            break;
         case 12:
            int var1 = class_41.field_538 <= 176 ? 10 : field_898;
            class_69.method_668(class_41.field_533.method_297(300), field_897, var1, field_899, 11 * this.field_902, true);
            class_50.method_483(class_41.field_533.method_297(301) + ":", field_897 + (field_899 >> 1), var1 + 12, 1, 24);
            class_41.field_534.setColor(class_69.field_1003);
            class_41.field_534
               .drawRect(
                  field_897 + (field_899 >> 1) - (class_119.field_1504 >> 1),
                  var1 + 11 + this.field_902 + 6,
                  class_119.field_1504 + 1,
                  class_119.field_1505 + 1
               );
            if (field_922) {
               class_119.method_928(this.field_918, field_897 + (field_899 >> 1) + 1, var1 + 12 + this.field_902 + 6, 17);
            } else if (this.field_919 != null && this.field_919.field_1532 != null) {
               class_41.field_534.drawImage(this.field_919.field_1532, field_897 + (field_899 >> 1) + 1, var1 + 12 + this.field_902 + 6, 17);
            }

            class_69.method_662(
               class_41.field_533.method_297(302), field_897, var1 + 12 + 2 * this.field_902 + 6 + class_119.field_1505, field_899, this.field_904 == 0, true
            );
            if (this.field_919 != null) {
               class_69.method_662(
                  class_41.field_533.method_297(303),
                  field_897,
                  var1 + 12 + 3 * this.field_902 + 6 + class_119.field_1505,
                  field_899,
                  this.field_904 == 1,
                  true
               );
               class_69.method_662(
                  class_41.field_533.method_297(74), field_897, var1 + 12 + 4 * this.field_902 + 6 + class_119.field_1505, field_899, this.field_904 == 2, true
               );
            } else {
               class_69.method_662(
                  class_41.field_533.method_297(74), field_897, var1 + 12 + 3 * this.field_902 + 6 + class_119.field_1505, field_899, this.field_904 == 1, true
               );
            }
            break;
         case 13:
            class_69.method_667(class_41.field_533.method_297(75), field_897, field_898, field_899, class_41.field_538 - field_898 - class_69.method_653() - 10);
            this.field_915.method_278();
            break;
         case 14:
            this.field_920.method_711();
            break;
         case 15:
         case 16:
         case 17:
         case 18:
         case 19:
         case 20:
         case 21:
         case 22:
         case 23:
         case 24:
            class_69.method_667(
               class_41.field_533.method_297(class_22.field_315[this.field_904]),
               field_897,
               field_898,
               field_899,
               class_41.field_538 - field_898 - class_69.method_653() - 10
            );
            this.field_914.method_278();
      }

      if (this.field_908) {
         this.field_907.method_518();
         class_69.method_677("", "", false);
      } else if (this.field_905 == 0) {
         class_69.method_677(class_41.field_533.method_297(265), class_3.method_142() == 0L ? "" : class_41.field_533.method_297(65), false);
      } else if (this.field_905 == 5) {
         class_69.method_677(class_41.field_533.method_297(265), class_41.field_533.method_297(17), false);
      } else if (this.field_905 == 11) {
         if (this.field_916.field_825.length() > 0) {
            class_69.method_677(class_41.field_533.method_297(74), class_41.field_533.method_297(304), false);
         } else {
            class_69.method_677("", class_41.field_533.method_297(65), false);
         }
      } else if (this.field_905 == 7 || this.field_905 == 8 || this.field_905 == 14 || this.field_905 == 13 || this.field_905 >= 15 && this.field_905 <= 24) {
         class_69.method_677("", class_41.field_533.method_297(65), false);
      } else {
         class_69.method_677(class_41.field_533.method_297(41), class_41.field_533.method_297(65), false);
      }
   }

   // $VF: renamed from: d (int) void
   public final void method_637(int var1) {
      if (this.field_905 == 11) {
         if (var1 == 8192 && this.field_916.field_825.length() == 0) {
            this.field_904 = 0;
            this.field_905 = 9;
         }

         if (var1 != 0 && var1 != -1) {
            this.field_916.method_583(var1);
         }
      }
   }
}
