// $VF: renamed from: cn
public final class class_23 {
   // $VF: renamed from: a as
   private class_76 field_345 = new class_76(
      new String[]{class_41.field_533.method_297(37), class_41.field_533.method_297(328)}, class_41.field_533.method_297(37)
   );
   // $VF: renamed from: a al
   private class_95 field_346;
   // $VF: renamed from: a k
   private class_56 field_347;
   // $VF: renamed from: a z
   private class_53 field_348;
   // $VF: renamed from: a bp
   private class_68 field_349;
   // $VF: renamed from: a long
   private long field_350;
   // $VF: renamed from: a int
   private int field_351;
   // $VF: renamed from: a boolean
   private boolean field_352;
   // $VF: renamed from: a bz
   private class_66 field_353;
   // $VF: renamed from: a an
   private class_60 field_354;

   public class_23() {
      this.field_345.method_720(1, class_3.method_110().field_838);
      this.field_345.method_720(0, class_3.method_64());
      this.field_351 = 0;
      this.field_347 = new class_56();
      this.field_348 = new class_53(20, class_41.field_538 / 3, class_41.field_537 - 40);
      this.field_353 = new class_66();
      this.field_352 = false;
      System.gc();
   }

   // $VF: renamed from: a () void
   public final void method_299() {
      this.field_345.method_720(0, class_3.method_64());
   }

   // $VF: renamed from: b () void
   public final void method_300() {
      this.field_345 = null;
      this.field_346 = null;
      this.field_347 = null;
      this.field_348 = null;
      System.gc();
   }

   // $VF: renamed from: c () void
   public final void method_301() {
      this.field_351 = 0;
      this.field_346 = null;
   }

   // $VF: renamed from: a () int
   public final int method_302() {
      return this.field_345.field_1057;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_303() {
      return this.field_351 == 0;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_304(int var1) {
      if (this.field_351 == 2) {
         if (!this.field_349.method_642(var1)) {
            if (this.field_349.field_984) {
               this.field_351 = 3;
            } else {
               this.field_351 = 1;
            }
         }
      } else if (this.field_351 == 0) {
         if (this.field_352) {
            if (var1 == 256) {
               if (this.field_348.method_515()) {
                  this.method_305(false);
               } else {
                  this.field_351 = 0;
               }

               this.field_352 = false;
               return true;
            }

            if (var1 == 32) {
               this.field_348.method_517();
            } else if (var1 == 4) {
               this.field_348.method_516();
            }

            return true;
         }

         if (var1 == 256 || var1 == 16384) {
            if (this.field_345.method_694() != null) {
               this.field_346 = ((class_2)this.field_345.method_694()).field_24;
               if (var1 == 256 && this.field_352) {
                  this.field_351 = 0;
               } else {
                  if (class_3.method_112() < this.field_346.field_1231) {
                     this.field_348.method_513(class_3.method_149(class_41.field_533.method_297(85), "" + (this.field_346.field_1231 - class_3.method_112())));
                     this.field_352 = true;
                     return true;
                  }

                  this.field_347.method_525((class_2)this.field_345.method_694(), true);
                  this.field_351 = 1;
               }
            }

            return true;
         }

         if (var1 == 4 && this.field_351 == 0) {
            this.field_345.method_699();
         }

         if (var1 == 32 && this.field_351 == 0) {
            this.field_345.method_700();
         }

         if (var1 == 2 && this.field_351 == 0) {
            this.field_345.method_697();
         }

         if (var1 == 64 && this.field_351 == 0) {
            this.field_345.method_698();
         }

         if (var1 == 8192) {
            if (this.field_351 == 0) {
               return false;
            }

            if (this.field_351 == 1) {
               this.field_351 = 0;
               return true;
            }
         }
      } else if (this.field_351 == 1) {
         if (this.field_352) {
            if (var1 == 256) {
               if (this.field_348.method_515()) {
                  this.method_305(false);
               } else {
                  this.field_351 = 1;
               }

               this.field_352 = false;
            } else if (var1 == 32) {
               this.field_348.method_517();
            } else if (var1 == 4) {
               this.field_348.method_516();
            }
         } else if (var1 != 256 && var1 != 16384) {
            if (var1 == 8192) {
               this.field_351 = 0;
            }
         } else if (this.field_346.field_1241 && this.field_346.field_1251 && this.field_346.field_1232 != class_3.method_110().field_828) {
            this.field_348.method_514(class_41.field_533.method_297(252), true);
            this.field_348.method_516();
            this.field_352 = true;
         } else if (!this.field_346.field_1241) {
            this.field_354 = class_44.method_431(this.field_346.field_1232);
            this.field_353.method_618(this.field_345.field_1057 == 1, this.field_346.field_1232 == class_3.method_110().field_828);
            this.field_351 = 3;
         }
      } else if (this.field_351 == 3) {
         if (this.field_352) {
            if (var1 == 256) {
               if (this.field_348.method_515()) {
                  this.field_352 = false;
                  this.field_351 = 0;
                  if (this.field_345.field_1057 == 0) {
                     class_3.method_66(class_95.field_1225);
                     this.field_345.method_698();
                  } else {
                     class_3.method_66(this.field_346);
                     class_3.method_110().method_591(this.field_346);
                     class_3.method_127(-this.field_346.field_1231);
                     this.field_345.method_699();
                     if (this.field_346.field_1232 != class_3.method_110().field_828) {
                        this.field_348.method_514(class_41.field_533.method_297(252), true);
                        this.field_352 = true;
                     }
                  }

                  if (this.field_345 == null) {
                     return false;
                  }

                  this.field_345.method_720(1, class_3.method_110().field_838);
                  this.field_345.method_720(0, class_3.method_64());
                  this.field_345.method_698();
                  return true;
               }

               this.field_352 = false;
            } else if (var1 == 4) {
               this.field_348.method_516();
            } else if (var1 == 32) {
               this.field_348.method_517();
            }

            return true;
         }

         if (var1 == 2) {
            this.field_353.method_619();
         } else if (var1 == 64) {
            this.field_353.method_620();
         } else if (var1 == 256) {
            switch (this.field_353.field_888) {
               case 0:
                  if (this.field_345.field_1057 == 0) {
                     this.field_348.method_514(class_41.field_533.method_297(244), true);
                  } else {
                     boolean var2 = this.field_354.field_834 > class_3.method_108().field_449 || this.field_354.field_834 < class_3.method_108().field_448;
                     if (this.field_346.field_1232 == class_3.method_110().field_828 || this.field_346.field_1226 == 13) {
                        var2 = false;
                     }

                     if (class_3.method_65().method_789()) {
                        this.field_348
                           .method_514(
                              class_41.field_533.method_297(264)
                                 + ": "
                                 + this.field_346.field_1231
                                 + " $\n"
                                 + (var2 ? class_41.field_533.method_297(255) + "\n" : ""),
                              true
                           );
                     } else {
                        this.field_348
                           .method_514(
                              class_41.field_533.method_297(242)
                                 + "\n"
                                 + class_41.field_533.method_297(264)
                                 + ": "
                                 + this.field_346.field_1231
                                 + " $\n"
                                 + class_41.field_533.method_297(243)
                                 + ": "
                                 + class_3.method_65().field_1231
                                 + " $\n"
                                 + (var2 ? class_41.field_533.method_297(255) + "\n" : "")
                                 + class_41.field_533.method_297(244),
                              true
                           );
                     }
                  }

                  this.field_352 = true;
                  break;
               case 1:
                  if (this.field_346.field_1232 == class_3.method_110().field_828) {
                     this.field_349 = ((class_118)class_41.field_544[1]).field_1482;
                     this.field_349.method_643();
                     return false;
                  }

                  this.method_305(this.field_345.field_1057 == 1);
                  break;
               case 2:
                  this.field_351 = 1;
            }
         }
      }

      return true;
   }

   // $VF: renamed from: a (boolean) void
   private void method_305(boolean var1) {
      this.field_349 = ((class_118)class_41.field_544[1]).field_1482;
      this.field_349.method_640(var1 ? this.field_346 : null);
      this.field_351 = 2;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_306(int var1, int var2) {
      this.field_350 += var2;
      if (this.field_351 == 2) {
         this.field_349.method_645(var1, var2);
         return true;
      } else {
         if ((var1 & 2) != 0 && this.field_351 == 1) {
            this.field_347.method_526(var2);
         }

         if ((var1 & 64) != 0 && this.field_351 == 1) {
            this.field_347.method_527(var2);
         }

         this.method_309();
         return true;
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_307() {
      return this.field_351 == 2;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_308() {
      return this.field_351 == 2 && this.field_345.field_1057 == 1;
   }

   // $VF: renamed from: d () void
   public final void method_309() {
      class_69.method_663();
      if (this.field_351 == 0) {
         this.field_345.method_711();
      }

      if (this.field_351 == 1) {
         this.field_347.method_528();
      }

      if (this.field_351 == 0) {
         class_69.method_669(this.field_345.method_694() != null ? class_41.field_533.method_297(226) : "", class_41.field_533.method_297(65));
      } else if (this.field_346 == null
         || !this.field_346.field_1251
         || this.field_346.field_1241 && this.field_346.field_1232 == class_3.method_110().field_828) {
         class_69.method_669("", class_41.field_533.method_297(65));
      } else {
         class_69.method_669(class_41.field_533.method_297(74), class_41.field_533.method_297(65));
      }

      if (this.field_351 == 3) {
         this.field_347.method_528();
         class_69.method_669("", "");
         this.field_353.method_621();
      }

      if (this.field_352) {
         class_69.method_669("", "");
         this.field_348.method_518();
      }
   }
}
