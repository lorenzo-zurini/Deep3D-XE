// $VF: renamed from: cn
public final class class_36 {
   // $VF: renamed from: a at
   private class_81 field_349 = new class_81(
      new String[]{class_84.field_1116.method_4(37), class_84.field_1116.method_4(328)}, class_84.field_1116.method_4(37)
   );
   // $VF: renamed from: a am
   private class_87 field_350;
   // $VF: renamed from: a j
   private class_10 field_351;
   // $VF: renamed from: a ab
   private class_121 field_352;
   // $VF: renamed from: a bp
   private class_55 field_353;
   // $VF: renamed from: a long
   private long field_354;
   // $VF: renamed from: a int
   private int field_355;
   // $VF: renamed from: a boolean
   private boolean field_356;
   // $VF: renamed from: a bz
   private class_47 field_357;
   // $VF: renamed from: a ao
   private class_86 field_358;

   public class_36() {
      this.field_349.method_730(1, class_21.method_180().field_1144);
      this.field_349.method_730(0, class_21.method_134());
      this.field_355 = 0;
      this.field_351 = new class_10();
      this.field_352 = new class_121(20, class_84.field_1121 / 3, class_84.field_1120 - 40);
      this.field_357 = new class_47();
      this.field_356 = false;
      // System.gc() removed: full GCs stall the desktop JVM
   }

   // $VF: renamed from: a () void
   public final void method_310() {
      this.field_349.method_730(0, class_21.method_134());
   }

   // $VF: renamed from: b () void
   public final void method_311() {
      this.field_349 = null;
      this.field_350 = null;
      this.field_351 = null;
      this.field_352 = null;
      // System.gc() removed: full GCs stall the desktop JVM
   }

   // $VF: renamed from: c () void
   public final void method_312() {
      this.field_355 = 0;
      this.field_350 = null;
   }

   // $VF: renamed from: a () int
   public final int method_313() {
      return this.field_349.field_1038;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_314() {
      return this.field_355 == 0;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_315(int var1) {
      if (this.field_355 == 2) {
         if (!this.field_353.method_447(var1)) {
            if (this.field_353.field_654) {
               this.field_355 = 3;
            } else {
               this.field_355 = 1;
            }
         }
      } else if (this.field_355 == 0) {
         if (this.field_356) {
            if (var1 == 256) {
               if (this.field_352.method_941()) {
                  this.method_316(false);
               } else {
                  this.field_355 = 0;
               }

               this.field_356 = false;
               return true;
            }

            if (var1 == 32) {
               this.field_352.method_943();
            } else if (var1 == 4) {
               this.field_352.method_942();
            }

            return true;
         }

         if (var1 == 256 || var1 == 16384) {
            if (this.field_349.method_701() != null) {
               this.field_350 = ((class_59)this.field_349.method_701()).field_712;
               if (var1 == 256 && this.field_356) {
                  this.field_355 = 0;
               } else {
                  if (class_21.method_182() < this.field_350.field_1151) {
                     this.field_352.method_939(class_21.method_219(class_84.field_1116.method_4(85), "" + (this.field_350.field_1151 - class_21.method_182())));
                     this.field_356 = true;
                     return true;
                  }

                  this.field_351.method_51((class_59)this.field_349.method_701(), true);
                  this.field_355 = 1;
               }
            }

            return true;
         }

         if (var1 == 4 && this.field_355 == 0) {
            this.field_349.method_706();
         }

         if (var1 == 32 && this.field_355 == 0) {
            this.field_349.method_707();
         }

         if (var1 == 2 && this.field_355 == 0) {
            this.field_349.method_704();
         }

         if (var1 == 64 && this.field_355 == 0) {
            this.field_349.method_705();
         }

         if (var1 == 8192) {
            if (this.field_355 == 0) {
               return false;
            }

            if (this.field_355 == 1) {
               this.field_355 = 0;
               return true;
            }
         }
      } else if (this.field_355 == 1) {
         if (this.field_356) {
            if (var1 == 256) {
               if (this.field_352.method_941()) {
                  this.method_316(false);
               } else {
                  this.field_355 = 1;
               }

               this.field_356 = false;
            } else if (var1 == 32) {
               this.field_352.method_943();
            } else if (var1 == 4) {
               this.field_352.method_942();
            }
         } else if (var1 != 256 && var1 != 16384) {
            if (var1 == 8192) {
               this.field_355 = 0;
            }
         } else if (this.field_350.field_1161 && this.field_350.field_1171 && this.field_350.field_1152 != class_21.method_180().field_1134) {
            this.field_352.method_940(class_84.field_1116.method_4(252), true);
            this.field_352.method_942();
            this.field_356 = true;
         } else if (!this.field_350.field_1161) {
            this.field_358 = class_38.method_354(this.field_350.field_1152);
            this.field_357.method_393(this.field_349.field_1038 == 1, this.field_350.field_1152 == class_21.method_180().field_1134);
            this.field_355 = 3;
         }
      } else if (this.field_355 == 3) {
         if (this.field_356) {
            if (var1 == 256) {
               if (this.field_352.method_941()) {
                  this.field_356 = false;
                  this.field_355 = 0;
                  if (this.field_349.field_1038 == 0) {
                     class_21.method_136(class_87.field_1145);
                     this.field_349.method_705();
                  } else {
                     class_21.method_136(this.field_350);
                     class_21.method_180().method_751(this.field_350);
                     class_21.method_197(-this.field_350.field_1151);
                     this.field_349.method_706();
                     if (this.field_350.field_1152 != class_21.method_180().field_1134) {
                        this.field_352.method_940(class_84.field_1116.method_4(252), true);
                        this.field_356 = true;
                     }
                  }

                  if (this.field_349 == null) {
                     return false;
                  }

                  this.field_349.method_730(1, class_21.method_180().field_1144);
                  this.field_349.method_730(0, class_21.method_134());
                  this.field_349.method_705();
                  return true;
               }

               this.field_356 = false;
            } else if (var1 == 4) {
               this.field_352.method_942();
            } else if (var1 == 32) {
               this.field_352.method_943();
            }

            return true;
         }

         if (var1 == 2) {
            this.field_357.method_394();
         } else if (var1 == 64) {
            this.field_357.method_395();
         } else if (var1 == 256) {
            switch (this.field_357.field_527) {
               case 0:
                  if (this.field_349.field_1038 == 0) {
                     this.field_352.method_940(class_84.field_1116.method_4(244), true);
                  } else {
                     boolean var2 = this.field_358.field_1140 > class_21.method_178().field_890 || this.field_358.field_1140 < class_21.method_178().field_889;
                     if (this.field_350.field_1152 == class_21.method_180().field_1134 || this.field_350.field_1146 == 13) {
                        var2 = false;
                     }

                     if (class_21.method_135().method_754()) {
                        this.field_352
                           .method_940(
                              class_84.field_1116.method_4(264)
                                 + ": "
                                 + this.field_350.field_1151
                                 + " $\n"
                                 + (var2 ? class_84.field_1116.method_4(255) + "\n" : ""),
                              true
                           );
                     } else {
                        this.field_352
                           .method_940(
                              class_84.field_1116.method_4(242)
                                 + "\n"
                                 + class_84.field_1116.method_4(264)
                                 + ": "
                                 + this.field_350.field_1151
                                 + " $\n"
                                 + class_84.field_1116.method_4(243)
                                 + ": "
                                 + class_21.method_135().field_1151
                                 + " $\n"
                                 + (var2 ? class_84.field_1116.method_4(255) + "\n" : "")
                                 + class_84.field_1116.method_4(244),
                              true
                           );
                     }
                  }

                  this.field_356 = true;
                  break;
               case 1:
                  if (this.field_350.field_1152 == class_21.method_180().field_1134) {
                     this.field_353 = ((class_63)class_84.field_1127[1]).field_757;
                     this.field_353.method_448();
                     return false;
                  }

                  this.method_316(this.field_349.field_1038 == 1);
                  break;
               case 2:
                  this.field_355 = 1;
            }
         }
      }

      return true;
   }

   // $VF: renamed from: a (boolean) void
   private void method_316(boolean var1) {
      this.field_353 = ((class_63)class_84.field_1127[1]).field_757;
      this.field_353.method_445(var1 ? this.field_350 : null);
      this.field_355 = 2;
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_317(int var1, int var2) {
      this.field_354 += var2;
      if (this.field_355 == 2) {
         this.field_353.method_450(var1, var2);
         return true;
      } else {
         if ((var1 & 2) != 0 && this.field_355 == 1) {
            this.field_351.method_52(var2);
         }

         if ((var1 & 64) != 0 && this.field_355 == 1) {
            this.field_351.method_53(var2);
         }

         this.method_320();
         return true;
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_318() {
      return this.field_355 == 2;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_319() {
      return this.field_355 == 2 && this.field_349.field_1038 == 1;
   }

   // $VF: renamed from: d () void
   public final void method_320() {
      class_67.method_587();
      if (this.field_355 == 0) {
         this.field_349.method_718();
      }

      if (this.field_355 == 1) {
         this.field_351.method_54();
      }

      if (this.field_355 == 0) {
         class_67.method_593(this.field_349.method_701() != null ? class_84.field_1116.method_4(226) : "", class_84.field_1116.method_4(65));
      } else if (this.field_350 == null
         || !this.field_350.field_1171
         || this.field_350.field_1161 && this.field_350.field_1152 == class_21.method_180().field_1134) {
         class_67.method_593("", class_84.field_1116.method_4(65));
      } else {
         class_67.method_593(class_84.field_1116.method_4(74), class_84.field_1116.method_4(65));
      }

      if (this.field_355 == 3) {
         this.field_351.method_54();
         class_67.method_593("", "");
         this.field_357.method_396();
      }

      if (this.field_356) {
         class_67.method_593("", "");
         this.field_352.method_944();
      }
   }
}
