import javax.microedition.lcdui.Image;

// $VF: renamed from: bu
public final class class_51 {
   // $VF: renamed from: a int
   private static int field_552;
   // $VF: renamed from: b int
   private static int field_553;
   // $VF: renamed from: c int
   private static int field_554;
   // $VF: renamed from: a int[]
   private static int[] field_555 = new int[]{6, 4, 3, 3, 3, 5, 10, 0, 0, 2, 12, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_556;
   // $VF: renamed from: d int
   private int field_557;
   // $VF: renamed from: e int
   private int field_558;
   // $VF: renamed from: f int
   private int field_559;
   // $VF: renamed from: g int
   private int field_560;
   // $VF: renamed from: a java.lang.String
   private String field_561;
   // $VF: renamed from: a ab
   private class_121 field_562;
   // $VF: renamed from: b boolean
   private boolean field_563;
   // $VF: renamed from: c boolean
   private boolean field_564;
   // $VF: renamed from: a cg[]
   private class_41[] field_565;
   // $VF: renamed from: b java.lang.String
   private String field_566;
   // $VF: renamed from: a dc
   private class_75 field_567;
   // $VF: renamed from: a dd
   private class_23 field_568;
   // $VF: renamed from: b dd
   private class_23 field_569;
   // $VF: renamed from: c dd
   private class_23 field_570;
   // $VF: renamed from: a cu
   private class_32 field_571;
   // $VF: renamed from: h int
   private int field_572;
   // $VF: renamed from: a byte[]
   private byte[] field_573;
   // $VF: renamed from: a bs
   private class_53 field_574;
   // $VF: renamed from: a ct
   private class_80 field_575;
   // $VF: renamed from: i int
   private int field_576;
   // $VF: renamed from: a boolean
   public static boolean field_577;
   // $VF: renamed from: d boolean
   private boolean field_578 = false;
   // $VF: renamed from: c java.lang.String
   private String field_579 = null;
   // $VF: renamed from: d java.lang.String
   private String field_580 = null;
   // $VF: renamed from: e java.lang.String
   private String field_581 = null;
   // $VF: renamed from: j int
   private int field_582 = -1;

   public class_51() {
      this.method_416();
      if (this.field_578) {
         field_555[0] = 7;
      }

      this.field_556 = class_33.method_292();
      field_553 = this.field_556.getHeight() + 25;
      field_554 = 114;
      field_552 = class_84.field_1120 - field_554 >> 1;
      this.field_557 = class_58.method_527();
      this.field_559 = 0;
      this.field_560 = 0;
      this.field_562 = new class_121(20, class_84.field_1121 / 2, class_84.field_1120 - 40);
      this.field_563 = false;
      this.field_564 = false;
      this.field_568 = new class_23(
         field_552 + 5,
         field_553 + 12,
         field_554 - 10,
         class_84.field_1121 - field_553 - 3 * class_67.method_577(),
         class_84.field_1116.method_4(25) + "\n\n" + class_84.field_1116.method_4(28)
      );
      this.field_569 = new class_23(field_552 + 5, field_553 + 12, field_554 - 10, class_84.field_1121 - field_553 - 3 * class_67.method_577(), "");
      this.field_570 = new class_23(field_552 + 5, field_553 + 12, field_554 - 10, class_84.field_1121 - field_553 - 3 * class_67.method_577(), "");
      String[] var1 = new String[class_1.field_2.length];

      for (int var2 = 0; var2 < var1.length; var2++) {
         var1[var2] = class_84.field_1116.method_4(class_1.field_1[var2]);
      }

      this.field_567 = new class_75(field_552, field_553, field_554, class_84.field_1121 - field_553 - class_67.method_577(), null);
      this.field_567.field_1044 = 12;
      this.field_567.method_700(0, var1);
      this.field_567.field_1048 = true;
      this.field_567.field_1047 = false;
      this.field_567.method_711();
      this.field_571 = new class_32(10);
      this.field_576 = class_84.field_1083;

      try {
         Class.forName("javax.microedition.media.control.VideoControl");
         this.field_574 = new class_53();
         if (System.getProperty("supports.video.capture").equalsIgnoreCase("false")) {
            throw new Exception();
         }
      } catch (Exception var3) {
         this.field_574 = null;
         field_555[12] = 2;
      }

      field_577 = true;
   }

   // $VF: renamed from: a (java.lang.String) java.lang.String
   private String method_415(String var1) {
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
   private void method_416() {
      try {
         try {
            this.field_579 = class_84.field_1119.getAppProperty("Operator-URL-en");
            this.field_581 = class_84.field_1119.getAppProperty("Operator-Menu-en");
         } catch (Exception var10) {
            this.field_578 = false;
            this.field_579 = null;
            this.field_580 = null;
            this.field_581 = null;

            try {
               this.field_579 = class_84.field_1119.getAppProperty("Operator-URL-gn");
               this.field_581 = class_84.field_1119.getAppProperty("Operator-Menu-gn");
            } catch (Exception var9) {
               this.field_578 = false;
               return;
            }

            if (this.field_579 == null || this.field_581 == null) {
               this.field_578 = false;
               return;
            }
         }

         if (this.field_579 == null || this.field_581 == null) {
            try {
               this.field_579 = class_84.field_1119.getAppProperty("Operator-URL-gn");
               this.field_581 = class_84.field_1119.getAppProperty("Operator-Menu-gn");
            } catch (Exception var8) {
               this.field_578 = false;
               return;
            }
         }

         try {
            this.field_580 = class_84.field_1119.getAppProperty("Operator-Prompt-en");
         } catch (Exception var7) {
            this.field_580 = null;

            try {
               this.field_580 = class_84.field_1119.getAppProperty("Operator-Prompt-gn");
            } catch (Exception var6) {
            }
         }

         if (this.field_580 == null) {
            try {
               this.field_580 = class_84.field_1119.getAppProperty("Operator-Prompt-gn");
            } catch (Exception var5) {
            }
         }

         if (this.field_580 != null) {
            this.field_580 = this.method_415(this.field_580);
         }

         if (this.field_581 != null) {
            this.field_581 = this.method_415(this.field_581);
         }

         System.out.println("wap_url: " + this.field_579);
         System.out.println("wap_menu: " + this.field_581);
         System.out.println("wap_prompt: " + this.field_580);
         String var1 = class_84.field_1119.getAppProperty("Operator-Mode");
         if (this.field_579 != null && var1 != null) {
            char[] var2 = new char[]{'1', '2'};

            for (int var3 = 0; var3 < var2.length; var3++) {
               int var4;
               if ((var4 = var1.indexOf(String.valueOf(var2[var3]))) >= 0) {
                  this.field_582 = Integer.valueOf(String.valueOf(var1.charAt(var4)));
               }
            }

            System.out.println("wap_mode: " + this.field_582);
            if (this.field_582 < 1 || this.field_582 > 2) {
               this.field_582 = 2;
            }

            this.field_578 = true;
         } else {
            throw new Exception();
         }
      } catch (Exception var11) {
         this.field_578 = false;
      }
   }

   // $VF: renamed from: a () void
   public final void method_417() {
      this.field_565 = null;
      this.field_562 = null;
      this.field_556 = null;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_418(int var1, int var2) {
      this.field_572 = var2;
      class_67.method_579(var2);
      if ((var1 & 64) != 0) {
         if (this.field_560 >= 15) {
            this.field_569.method_229(var2);
            return;
         }

         if (this.field_560 == 8) {
            this.field_568.method_229(var2);
            return;
         }
      } else if ((var1 & 2) != 0) {
         if (this.field_560 >= 15) {
            this.field_569.method_230(var2);
            return;
         }

         if (this.field_560 == 8) {
            this.field_568.method_230(var2);
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_419() {
      switch (this.field_560) {
         case 0:
            if (this.field_563 && this.field_559 == 5) {
               if (this.field_562.method_941()) {
                  class_84.field_1126.method_440();
                  return true;
               }

               this.field_563 = false;
               return false;
            }

            switch (this.field_559) {
               case 0:
                  if (class_21.method_212() > 0L) {
                     if (!this.field_563) {
                        this.field_562.method_940(class_84.field_1116.method_4(34), true);
                        this.field_563 = true;
                        return false;
                     }

                     if (this.field_562.method_941()) {
                        this.field_560 = 11;
                        this.field_559 = 0;
                     }

                     this.field_563 = false;
                  } else {
                     this.field_560 = 11;
                     this.field_559 = 0;
                  }

                  return false;
               case 1:
                  this.field_560 = 1;
                  if (this.field_565 == null) {
                     this.field_565 = class_27.method_272();
                  }

                  this.field_559 = 0;
                  return false;
               case 2:
                  this.field_560 = 2;
                  if (this.field_565 == null) {
                     this.field_565 = class_27.method_272();
                  }

                  this.field_559 = 0;
                  return false;
               case 3:
                  this.field_560 = 3;
                  this.field_559 = 0;
                  return false;
               case 4:
                  this.field_560 = 4;
                  this.field_559 = 0;
                  return false;
               case 5:
                  if (!this.field_563) {
                     this.field_562.method_940(class_84.field_1116.method_4(35), true);
                     this.field_563 = true;
                  }

                  return false;
               case 6:
                  if (this.field_578) {
                     switch (this.field_582) {
                        case 1:
                           try {
                              if (!this.field_563 && this.field_580 != null) {
                                 this.field_562.method_940(this.field_580, true);
                              } else if (this.field_580 == null || this.field_562.method_941()) {
                                 class_84.field_1119.platformRequest(this.field_579);
                                 class_84.field_1126.method_440();
                                 return true;
                              }

                              if (this.field_580 != null) {
                                 this.field_563 = !this.field_563;
                              }
                           } catch (Exception var4) {
                           }

                           return false;
                        default:
                           try {
                              if (!this.field_563 && this.field_580 != null) {
                                 this.field_562.method_940(this.field_580, true);
                              } else if (this.field_580 == null || this.field_562.method_941()) {
                                 class_84.field_1119.platformRequest(this.field_579);
                              }

                              if (this.field_580 != null) {
                                 this.field_563 = !this.field_563;
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
            if (this.field_565[this.field_559] != null) {
               if (class_21.method_212() <= 0L) {
                  this.field_565[this.field_559].method_367();
                  ((class_63)class_84.field_1127[1]).method_554();
                  class_84.field_1126.method_439(class_84.field_1127[1]);
                  return true;
               }

               if (!this.field_563) {
                  this.field_562.method_940(class_84.field_1116.method_4(33), true);
                  this.field_563 = true;
               } else {
                  if (this.field_562.method_941()) {
                     this.field_565[this.field_559].method_367();
                     ((class_63)class_84.field_1127[1]).method_554();
                     class_84.field_1126.method_439(class_84.field_1127[1]);
                  }

                  this.field_563 = false;
               }
            }
            break;
         case 2:
            if (this.field_563) {
               if (!this.field_562.method_941()) {
                  this.field_563 = false;
                  return true;
               }

               class_84.field_1113.method_296(false);
               class_27.method_277(this.field_559);
               this.field_565[this.field_559] = class_27.method_273(this.field_559);
               class_84.field_1113.method_295();
               this.field_562.method_940(class_84.field_1116.method_4(32), false);
            } else if (this.field_565[this.field_559] != null) {
               this.field_562.method_940(class_84.field_1116.method_4(31), true);
               this.field_563 = true;
            } else {
               class_84.field_1113.method_296(false);
               class_27.method_277(this.field_559);
               this.field_565 = class_27.method_272();
               class_84.field_1113.method_295();
               this.field_562.method_940(class_84.field_1116.method_4(32), false);
               this.field_563 = true;
            }
            break;
         case 3:
            this.method_424();
            break;
         case 4:
            switch (this.field_559) {
               case 0:
                  this.field_560 = 6;
                  this.field_559 = 0;
                  this.field_567.field_1039 = 0;
                  return false;
               case 1:
                  this.field_560 = 7;
                  return false;
               case 2:
                  this.field_560 = 8;
                  return false;
               default:
                  return false;
            }
         case 5:
            if (this.field_563) {
               if (this.field_562.method_941()) {
                  class_84.field_1126.method_439(class_84.field_1127[0]);
                  class_84.field_1122.method_768(0);
                  return true;
               }

               this.field_563 = false;
            } else {
               switch (this.field_559) {
                  case 0:
                     this.field_560 = 3;
                     this.field_559 = 0;
                     return false;
                  case 1:
                     this.field_560 = 4;
                     this.field_559 = 0;
                     return false;
                  case 2:
                     if (!class_21.method_132().method_754() && !class_21.method_132().field_1161) {
                        this.field_570
                           .method_225(
                              class_21.method_219(
                                    class_84.field_1116.method_4(class_1.field_12[class_21.method_132().field_1146]), class_21.method_132().field_1153
                                 )
                                 + "\n\n"
                                 + class_21.method_219(
                                    class_84.field_1116.method_4(class_1.field_13[class_21.method_132().field_1146]), class_21.method_132().field_1153
                                 )
                           );
                     } else if (!class_21.method_146()) {
                        String var1 = class_21.method_219(
                           class_84.field_1116.method_4(class_1.field_11[class_21.method_143()]), class_21.method_137().field_1153
                        );
                        class_87 var2;
                        if ((var2 = class_21.method_137()).field_1146 == 16) {
                           var1 = var1 + " " + class_21.method_202() + " / " + var2.field_1170;
                        } else if (var2.field_1146 == 18) {
                           var1 = var1 + " " + class_21.method_177() + " / " + var2.field_1170;
                        } else if (var2.field_1146 == 21) {
                           var1 = var1 + " " + class_21.method_191() + " / " + var2.field_1170;
                        } else if (var2.field_1146 == 15) {
                           var1 = var1 + " " + class_21.method_209() + " / " + var2.field_1170;
                        }

                        this.field_570
                           .method_225(
                              class_21.method_219(class_84.field_1116.method_4(class_1.field_10[class_21.method_143()]), class_21.method_137().field_1153)
                                 + "\n\n"
                                 + var1
                           );
                     } else if (class_21.method_146()) {
                        this.field_570.method_225(class_84.field_1116.method_4(609));
                     }

                     this.field_560 = 13;
                     this.field_559 = 0;
                     return false;
                  case 3:
                     this.field_560 = 14;
                     this.field_575 = new class_80(field_552, field_553, field_554, class_84.field_1121 - 2 * field_553);
                     return false;
                  case 4:
                     if (!this.field_563) {
                        this.field_562.method_940(class_84.field_1116.method_4(35), true);
                        this.field_563 = true;
                     }
               }
            }
            break;
         case 6:
            this.field_569.method_224();
            this.field_569.method_225(class_84.field_1116.method_4(class_1.field_2[this.field_559]));
            this.field_560 = 15 + this.field_559;
            if (this.field_559 == 0) {
               this.field_569
                  .method_225(
                     class_84.field_1116.method_4(631)
                        + "\n\n"
                        + class_84.field_1116.method_4(633)
                        + "\n\n"
                        + class_84.field_1116.method_4(642)
                        + "\n\n"
                        + class_84.field_1116.method_4(643)
                        + "\n\n"
                        + class_84.field_1116.method_4(641)
                        + "\n\n"
                        + class_84.field_1116.method_4(664)
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
            switch (this.field_559) {
               case 0:
                  if (class_21.method_212() > 0L) {
                     if (!this.field_563) {
                        this.field_562.method_940(class_84.field_1116.method_4(34), true);
                        this.field_563 = true;
                        return false;
                     }

                     if (this.field_562.method_941()) {
                        this.field_560 = 11;
                        this.field_559 = 0;
                     }

                     this.field_563 = false;
                  } else {
                     this.field_560 = 11;
                     this.field_559 = 0;
                  }

                  return false;
               case 1:
                  this.field_560 = 10;
                  this.field_559 = 0;
                  return false;
               default:
                  return false;
            }
         case 12:
            if (this.field_563) {
               if (this.field_562.method_941()) {
                  class_21.method_221();
                  class_84.field_1126.method_439(class_84.field_1127[2]);
                  class_84.field_1122.method_773();
                  return true;
               }

               this.field_563 = false;
            } else {
               if (this.field_559 == 2 || this.field_574 == null && this.field_559 == 1) {
                  if (field_577) {
                     class_21.method_216(this.field_573);
                     class_21.method_218(null);
                  } else {
                     class_21.method_218(this.field_574.field_592);
                     class_21.method_216(null);
                  }

                  this.field_562.method_940(class_21.method_213() + ", " + class_84.field_1116.method_4(298), true);
                  this.field_563 = true;
               }

               if (this.field_559 == 0) {
                  this.field_573 = class_119.method_920(true, 3);
                  field_577 = true;
               } else if (this.field_574 != null && this.field_559 == 1) {
                  this.field_574.method_438();
                  this.field_574.method_436();
               }
            }
      }

      return false;
   }

   // $VF: renamed from: a (int) void
   public final void method_420(int var1) {
      if (!this.field_563) {
         if (this.field_560 != 7 && this.field_560 != 8 && this.field_560 != 13 && this.field_560 != 14 && this.field_560 < 15) {
            if (this.field_559 > 0) {
               this.field_559--;
            } else {
               this.field_559 = field_555[this.field_560] - 1;
            }

            if (this.field_559 == 2 && this.field_560 == 0 && class_21.method_212() == 0L) {
               this.field_559--;
            }

            if (this.field_560 == 6) {
               this.field_567.method_704();
               return;
            }
         } else {
            if (this.field_560 == 13) {
               this.field_570.method_230(var1);
               return;
            }

            if (this.field_560 == 14) {
               this.field_575.method_704();
            }
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_421(int var1) {
      if (!this.field_563) {
         if (this.field_560 != 7 && this.field_560 != 8 && this.field_560 != 13 && this.field_560 != 14 && this.field_560 < 15) {
            if (this.field_559 < field_555[this.field_560] - 1) {
               this.field_559++;
            } else {
               this.field_559 = 0;
            }

            if (this.field_559 == 2 && this.field_560 == 0 && class_21.method_212() == 0L) {
               this.field_559++;
            }

            if (this.field_560 == 6) {
               this.field_567.method_705();
               return;
            }
         } else {
            if (this.field_560 == 13) {
               this.field_570.method_229(var1);
               return;
            }

            if (this.field_560 == 14) {
               this.field_575.method_705();
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_422() {
      if (this.field_563) {
         this.field_562.method_942();
      } else {
         if (this.field_560 == 3) {
            switch (this.field_559) {
               case 0:
                  this.field_576--;
                  this.method_423();
                  return;
               case 1:
                  this.method_424();
                  return;
               case 2:
                  this.method_424();
            }
         }
      }
   }

   // $VF: renamed from: g () void
   private void method_423() {
      if (this.field_576 < 0) {
         this.field_576 = 3;
      }

      if (this.field_576 > 3) {
         this.field_576 = 0;
      }

      switch (this.field_576) {
         case 0:
            class_84.field_1080 = true;
            class_84.field_1122.method_765(60);
            if (class_84.field_1126.field_595 != class_84.field_1127[2] && !class_84.field_1122.method_767()) {
               class_84.field_1122.method_768(0);
            }
            break;
         case 1:
            class_84.field_1080 = true;
            class_84.field_1122.method_765(80);
            break;
         case 2:
            class_84.field_1080 = true;
            class_84.field_1122.method_765(100);
            if (class_84.field_1126.field_595 != class_84.field_1127[2] && !class_84.field_1122.method_767()) {
               class_84.field_1122.method_768(0);
            }
            break;
         case 3:
            class_84.field_1122.method_773();
            class_84.field_1080 = false;
      }

      class_84.field_1083 = this.field_576;
   }

   // $VF: renamed from: c () void
   public final void method_424() {
      if (this.field_563) {
         this.field_562.method_943();
      } else {
         if (this.field_560 == 3) {
            switch (this.field_559) {
               case 0:
                  this.field_576++;
                  this.method_423();
                  return;
               case 1:
                  class_84.field_1081 = !class_84.field_1081;
                  if (class_84.field_1081) {
                     class_84.method_736(150);
                     return;
                  }
                  break;
               case 2:
                  class_84.field_1082 = !class_84.field_1082;
            }
         }
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_425() {
      if (this.field_563) {
         return false;
      } else if (this.field_560 != 0 && this.field_560 != 5) {
         if (this.field_560 == 3) {
            class_27.method_275();
         }

         if (this.field_560 == 7) {
            this.field_559 = 1;
            this.field_560 = 4;
            return false;
         } else if (this.field_560 == 6) {
            this.field_559 = 0;
            this.field_560 = 4;
            return false;
         } else if (this.field_560 >= 15) {
            this.field_560 = 6;
            return false;
         } else if (this.field_560 == 13) {
            this.field_559 = 2;
            this.field_560 = 5;
            return false;
         } else if (this.field_560 == 14) {
            this.field_559 = 3;
            this.field_560 = 5;
            return false;
         } else if (this.field_560 == 10) {
            this.field_559 = 1;
            this.field_560 = 9;
            return false;
         } else if (this.field_560 == 8) {
            this.field_559 = 2;
            this.field_560 = 4;
            return false;
         } else if (this.field_560 == 12) {
            this.field_560 = 11;
            return false;
         } else if (this.field_560 == 11) {
            return false;
         } else {
            if (this.field_560 > 0 || this.field_560 == 9) {
               if (this.field_560 == 9) {
                  this.field_559 = 0;
               } else {
                  this.field_559 = this.field_560;
               }

               this.field_560 = 0;
               if (this.field_564) {
                  this.method_428();
               }
            }

            return false;
         }
      } else {
         return true;
      }
   }

   // $VF: renamed from: c () boolean
   public final boolean method_426() {
      if (this.field_560 == 11) {
         if (this.field_571.field_327.length() > 0) {
            class_21.method_214((this.field_571.field_327 + (this.field_571.field_326 != ' ' ? this.field_571.field_326 : ' ')).trim());
            this.field_560 = 12;
            this.field_573 = class_119.method_920(true, 3);
            this.field_559 = 0;
         }
      } else {
         this.method_419();
      }

      return false;
   }

   // $VF: renamed from: c (int) void
   public final void method_427(int var1) {
      this.field_559 = var1;
      this.field_560 = 0;
   }

   // $VF: renamed from: d () void
   public final void method_428() {
      this.field_560 = 5;
      this.field_559 = 0;
      this.field_563 = false;
      this.field_564 = true;
   }

   // $VF: renamed from: e () void
   public final void method_429() {
      class_84.field_1117.drawImage(this.field_556, class_84.field_1120 / 2, 10, 17);
      switch (this.field_560) {
         case 0:
            this.field_558 = class_21.method_212() > 0L ? this.field_557 : 0;
            class_67.method_591(
               class_84.field_1116.method_4(67),
               field_552,
               field_553,
               field_554,
               ((class_21.method_212() > 0L ? field_555[this.field_560] : field_555[this.field_560] - 1) + 2) * this.field_557
            );
            class_67.method_584(class_84.field_1116.method_4(0), field_552, field_553 + 12, field_554, this.field_559 == 0);
            class_67.method_584(class_84.field_1116.method_4(1), field_552, field_553 + 12 + this.field_557, field_554, this.field_559 == 1);
            if (class_21.method_212() > 0L) {
               class_67.method_584(class_84.field_1116.method_4(2), field_552, field_553 + 12 + 2 * this.field_557, field_554, this.field_559 == 2);
            }

            class_67.method_584(
               class_84.field_1116.method_4(3), field_552, field_553 + 12 + 2 * this.field_557 + this.field_558, field_554, this.field_559 == 3
            );
            class_67.method_584(
               class_84.field_1116.method_4(4), field_552, field_553 + 12 + 3 * this.field_557 + this.field_558, field_554, this.field_559 == 4
            );
            class_67.method_584(
               class_84.field_1116.method_4(5), field_552, field_553 + 12 + 4 * this.field_557 + this.field_558, field_554, this.field_559 == 5
            );
            if (this.field_578) {
               class_67.method_584(this.field_581, field_552, field_553 + 12 + 5 * this.field_557 + this.field_558, field_554, this.field_559 == 6);
            }
            break;
         case 1:
         case 2:
            if (this.field_560 == 2) {
               class_67.method_591(class_84.field_1116.method_4(2), field_552, field_553, field_554, (field_555[this.field_560] + 3) * this.field_557);
            } else {
               class_67.method_591(class_84.field_1116.method_4(1), field_552, field_553, field_554, (field_555[this.field_560] + 2) * this.field_557);
            }

            for (int var2 = 0; var2 < this.field_565.length; var2++) {
               this.field_561 = var2 + 1 + ".  ";
               if (this.field_565[var2] == null) {
                  this.field_561 = this.field_561 + class_84.field_1116.method_4(30);
               } else {
                  this.field_561 = this.field_561 + class_48.method_398(this.field_565[var2].field_397);
                  this.field_566 = this.field_565[var2].field_417;
                  if (var2 == 3) {
                     this.field_561 = this.field_561 + " AUTOSAVE";
                  } else {
                     this.field_561 = this.field_561 + " " + this.field_566;
                  }
               }

               class_67.method_584(
                  class_67.method_600(this.field_561, field_554 - 12), field_552, field_553 + 12 + var2 * this.field_557, field_554, this.field_559 == var2
               );
            }
            break;
         case 3:
            class_67.method_591(class_84.field_1116.method_4(3), field_552, field_553, field_554, (field_555[this.field_560] + 2) * this.field_557);
            class_67.method_584(
               class_84.field_1116.method_4(6) + "    " + class_84.field_1116.method_4(class_1.field_4[this.field_576]),
               field_552,
               field_553 + 12,
               field_554,
               this.field_559 == 0
            );
            class_67.method_584(
               class_84.field_1116.method_4(10) + "    " + class_84.field_1116.method_4(class_84.field_1081 ? 14 : 15),
               field_552,
               field_553 + 12 + this.field_557,
               field_554,
               this.field_559 == 1
            );
            class_67.method_584(
               class_84.field_1116.method_4(13) + "    " + class_84.field_1116.method_4(class_84.field_1082 ? 14 : 15),
               field_552,
               field_553 + 12 + 2 * this.field_557,
               field_554,
               this.field_559 == 2
            );
            break;
         case 4:
            class_67.method_591(class_84.field_1116.method_4(4), field_552, field_553, field_554, (field_555[this.field_560] + 2) * this.field_557);
            class_67.method_584(class_84.field_1116.method_4(18), field_552, field_553 + 12, field_554, this.field_559 == 0);
            class_67.method_584(class_84.field_1116.method_4(19), field_552, field_553 + 12 + this.field_557, field_554, this.field_559 == 1);
            class_67.method_584(class_84.field_1116.method_4(20), field_552, field_553 + 12 + 2 * this.field_557, field_554, this.field_559 == 2);
            break;
         case 5:
            class_67.method_591(class_84.field_1116.method_4(16), field_552, field_553, field_554, (field_555[this.field_560] + 2) * this.field_557);
            class_67.method_584(class_84.field_1116.method_4(3), field_552, field_553 + 12, field_554, this.field_559 == 0);
            class_67.method_584(class_84.field_1116.method_4(4), field_552, field_553 + 12 + this.field_557, field_554, this.field_559 == 1);
            class_67.method_584(class_84.field_1116.method_4(75), field_552, field_553 + 12 + 2 * this.field_557, field_554, this.field_559 == 2);
            class_67.method_584(class_84.field_1116.method_4(266), field_552, field_553 + 12 + 3 * this.field_557, field_554, this.field_559 == 3);
            class_67.method_584(class_84.field_1116.method_4(5), field_552, field_553 + 12 + 4 * this.field_557, field_554, this.field_559 == 4);
            break;
         case 6:
            class_67.method_591(class_84.field_1116.method_4(18), field_552, field_553, field_554, class_84.field_1121 - field_553 - class_67.method_577() - 10);
            this.field_567.method_712();
            this.field_567.method_709();
            break;
         case 7:
            class_67.method_591(class_84.field_1116.method_4(19), field_552, field_553, field_554, 8 * this.field_557 + 3);
            class_58.method_518(class_84.field_1116.method_4(21), field_552 + 10, field_553 + 12, 0);
            class_58.method_516("5", field_552 + field_554 - 10, field_553 + 12, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(12), field_552 + 10, field_553 + 12 + this.field_557, 0);
            class_58.method_516("7", field_552 + field_554 - 10, field_553 + 12 + this.field_557, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(22), field_552 + 10, field_553 + 12 + 2 * this.field_557, 0);
            class_58.method_516("1", field_552 + field_554 - 10, field_553 + 12 + 2 * this.field_557, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(323), field_552 + 10, field_553 + 12 + 3 * this.field_557, 0);
            class_58.method_516("9", field_552 + field_554 - 10, field_553 + 12 + 3 * this.field_557, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(137), field_552 + 10, field_553 + 12 + 4 * this.field_557, 0);
            class_58.method_516("3", field_552 + field_554 - 10, field_553 + 12 + 4 * this.field_557, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(23), field_552 + 10, field_553 + 12 + 5 * this.field_557, 0);
            class_58.method_516("*,0,#", field_552 + field_554 - 10, field_553 + 12 + 5 * this.field_557, 1, 2);
            class_58.method_518(class_84.field_1116.method_4(24), field_552 + 10, field_553 + 12 + 6 * this.field_557, 0);
            class_58.method_516("0", field_552 + field_554 - 10, field_553 + 12 + 6 * this.field_557, 1, 2);
            break;
         case 8:
            class_67.method_591(class_84.field_1116.method_4(20), field_552, field_553, field_554, class_84.field_1121 - field_553 - class_67.method_577() - 10);
            class_58.method_518(
               class_84.field_1124, (class_84.field_1120 >> 1) - (class_58.method_523(class_84.field_1124) >> 1), 10 + this.field_556.getHeight() + 2, 1
            );
            this.field_568.method_231();
            break;
         case 9:
            class_67.method_591(class_84.field_1116.method_4(0), field_552, field_553, field_554, (field_555[this.field_560] + 2) * this.field_557);
            class_67.method_584(class_84.field_1116.method_4(232), field_552, field_553 + 12, field_554, this.field_559 == 0);
            class_67.method_584(class_84.field_1116.method_4(231), field_552, field_553 + 12 + this.field_557, field_554, this.field_559 == 1);
         case 10:
         default:
            break;
         case 11:
            class_67.method_592(class_84.field_1116.method_4(38), field_552, field_553, field_554, 4 * this.field_557, true);
            class_58.method_518(class_84.field_1116.method_4(299) + ":", field_552 + 10, field_553 + 12, 1);
            this.field_571.method_290(this.field_572);
            class_58.method_518(this.field_571.field_327 + this.field_571.field_326, field_552 + 10, field_553 + 12 + this.field_557, 0);
            if (class_67.method_581()) {
               class_58.method_518("_", field_552 + 10 + class_58.method_523(this.field_571.field_327), field_553 + 12 + 2 + this.field_557, 0);
            }
            break;
         case 12:
            int var1 = class_84.field_1121 <= 176 ? 10 : field_553;
            class_67.method_592(class_84.field_1116.method_4(300), field_552, var1, field_554, 11 * this.field_557, true);
            class_58.method_516(class_84.field_1116.method_4(301) + ":", field_552 + (field_554 >> 1), var1 + 12, 1, 24);
            class_84.field_1117.setColor(class_67.field_844);
            class_84.field_1117
               .drawRect(
                  field_552 + (field_554 >> 1) - (class_119.field_1458 >> 1),
                  var1 + 11 + this.field_557 + 6,
                  class_119.field_1458 + 1,
                  class_119.field_1459 + 1
               );
            if (field_577) {
               class_119.method_923(this.field_573, field_552 + (field_554 >> 1) + 1, var1 + 12 + this.field_557 + 6, 17);
            } else if (this.field_574 != null && this.field_574.field_592 != null) {
               class_84.field_1117.drawImage(this.field_574.field_592, field_552 + (field_554 >> 1) + 1, var1 + 12 + this.field_557 + 6, 17);
            }

            class_67.method_586(
               class_84.field_1116.method_4(302), field_552, var1 + 12 + 2 * this.field_557 + 6 + class_119.field_1459, field_554, this.field_559 == 0, true
            );
            if (this.field_574 != null) {
               class_67.method_586(
                  class_84.field_1116.method_4(303), field_552, var1 + 12 + 3 * this.field_557 + 6 + class_119.field_1459, field_554, this.field_559 == 1, true
               );
               class_67.method_586(
                  class_84.field_1116.method_4(74), field_552, var1 + 12 + 4 * this.field_557 + 6 + class_119.field_1459, field_554, this.field_559 == 2, true
               );
            } else {
               class_67.method_586(
                  class_84.field_1116.method_4(74), field_552, var1 + 12 + 3 * this.field_557 + 6 + class_119.field_1459, field_554, this.field_559 == 1, true
               );
            }
            break;
         case 13:
            class_67.method_591(class_84.field_1116.method_4(75), field_552, field_553, field_554, class_84.field_1121 - field_553 - class_67.method_577() - 10);
            this.field_570.method_231();
            break;
         case 14:
            this.field_575.method_718();
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
            class_67.method_591(
               class_84.field_1116.method_4(class_1.field_1[this.field_559]),
               field_552,
               field_553,
               field_554,
               class_84.field_1121 - field_553 - class_67.method_577() - 10
            );
            this.field_569.method_231();
      }

      if (this.field_563) {
         this.field_562.method_944();
         class_67.method_601("", "", false);
      } else if (this.field_560 == 0) {
         class_67.method_601(class_84.field_1116.method_4(265), class_21.method_212() == 0L ? "" : class_84.field_1116.method_4(65), false);
      } else if (this.field_560 == 5) {
         class_67.method_601(class_84.field_1116.method_4(265), class_84.field_1116.method_4(17), false);
      } else if (this.field_560 == 11) {
         if (this.field_571.field_327.length() > 0) {
            class_67.method_601(class_84.field_1116.method_4(74), class_84.field_1116.method_4(304), false);
         } else {
            class_67.method_601("", class_84.field_1116.method_4(65), false);
         }
      } else if (this.field_560 == 7 || this.field_560 == 8 || this.field_560 == 14 || this.field_560 == 13 || this.field_560 >= 15 && this.field_560 <= 24) {
         class_67.method_601("", class_84.field_1116.method_4(65), false);
      } else {
         class_67.method_601(class_84.field_1116.method_4(41), class_84.field_1116.method_4(65), false);
      }
   }

   // $VF: renamed from: d (int) void
   public final void method_430(int var1) {
      if (this.field_560 == 11) {
         if (var1 == 8192 && this.field_571.field_327.length() == 0) {
            this.field_559 = 0;
            this.field_560 = 9;
         }

         if (var1 != 0 && var1 != -1) {
            this.field_571.method_291(var1);
         }
      }
   }
}
