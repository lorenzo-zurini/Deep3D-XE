// $VF: renamed from: aj
public final class class_89 {
   // $VF: renamed from: a int
   private static int field_1185 = 0;
   // $VF: renamed from: a long
   private long field_1186;
   // $VF: renamed from: a bj
   private class_65 field_1187;
   // $VF: renamed from: a boolean
   private boolean field_1188;
   // $VF: renamed from: a ay
   private class_76 field_1189;
   // $VF: renamed from: a bh
   private class_59 field_1190;
   // $VF: renamed from: a j
   private class_10 field_1191;
   // $VF: renamed from: a ab
   private class_121 field_1192;
   // $VF: renamed from: b ab
   private class_121 field_1193;
   // $VF: renamed from: b boolean
   private boolean field_1194;
   // $VF: renamed from: b int
   private int field_1195;
   // $VF: renamed from: c int
   private int field_1196;
   // $VF: renamed from: a int[]
   private int[] field_1197;
   // $VF: renamed from: d int
   private int field_1198;

   // $VF: renamed from: a () void
   public final void method_774() {
      this.field_1197 = null;
      if (this.field_1189 != null) {
         this.field_1189.method_714();
      }

      this.field_1189 = null;
      this.field_1190 = null;
      this.field_1191 = null;
      this.field_1192 = null;
      this.field_1193 = null;
      this.field_1188 = false;
      System.gc();
   }

   // $VF: renamed from: b () void
   public final void method_775() {
      this.field_1189 = new class_76(new String[]{class_84.field_1116.method_4(79), class_84.field_1116.method_4(81)}, class_84.field_1116.method_4(62));
      this.field_1189.method_715(0, class_21.method_178());
      this.field_1189.method_716(1, class_21.method_180().field_1141, class_21.method_180().field_1143);
      this.field_1191 = new class_10();
      this.field_1192 = new class_121(20, class_84.field_1121 / 3, class_84.field_1120 - 40);
      this.field_1198 = 0;
      this.field_1187 = ((class_63)class_84.field_1127[1]).field_740;
      this.field_1193 = new class_121(10, class_84.field_1121 / 3, class_84.field_1120 - 20);
      this.field_1195 = 5;
      this.field_1196 = class_84.field_1120 - 10;
      this.field_1197 = new int[3];
      this.field_1197[0] = this.field_1196 / 3 - 2;
      this.field_1197[1] = this.field_1197[0];
      this.field_1197[2] = this.field_1196 - this.field_1197[0] - this.field_1197[1] - 4;
      this.field_1189.method_702(field_1185);
      System.gc();
      this.field_1188 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_776() {
      return this.field_1198 == 0;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_777(int var1) {
      this.field_1190 = (class_59)this.field_1189.method_701();
      if (var1 == 256) {
         if (this.field_1194 && this.field_1186 > 200L) {
            this.field_1194 = false;
            return true;
         }

         if (this.field_1198 == 4) {
            this.field_1198 = 0;
         } else if (this.field_1198 == 0) {
            if (this.field_1189.method_717() && this.field_1189.method_701() != null) {
               if (this.field_1190.method_540()) {
                  this.field_1193.method_939(class_84.field_1116.method_4(84));
                  this.field_1194 = true;
               } else if (this.field_1190.method_536() || this.field_1190.method_535()) {
                  this.field_1191.method_51((class_59)this.field_1189.method_701(), this.field_1189.field_1038 == 2);
                  this.field_1198 = 1;
               }
            }
         } else if (this.field_1198 == 1) {
            this.field_1198 = 0;
         } else if (this.field_1198 == 2) {
            this.field_1198 = 0;
         } else if (this.field_1198 == 3) {
            this.field_1198 = 0;
            this.field_1189.method_715(1, class_21.method_178());
         }
      }

      if (this.field_1194) {
         return true;
      } else {
         if (var1 == 2 && this.field_1198 == 0) {
            this.field_1189.method_704();
         }

         if (var1 == 64 && this.field_1198 == 0) {
            this.field_1189.method_705();
         }

         if (var1 == 4 && (this.field_1198 == 4 || this.field_1198 == 0)) {
            this.field_1189.method_706();
         }

         if (var1 == 32 && (this.field_1198 == 4 || this.field_1198 == 0)) {
            this.field_1189.method_707();
         }

         if (var1 == 8192) {
            if (this.field_1198 == 4) {
               field_1185 = this.field_1189.field_1038;
               return false;
            }

            if (this.field_1198 == 0) {
               return false;
            }

            if (this.field_1198 == 1) {
               this.field_1198 = 0;
            } else if (this.field_1198 == 5) {
               this.field_1198 = 4;
            } else if (this.field_1198 == 6) {
               this.field_1198 = 1;
               this.field_1187.method_570();
            }
         }

         if (var1 == 16384) {
            if (this.field_1198 == 4) {
               this.field_1198 = 5;
            } else if (this.field_1198 == 0) {
               if (this.field_1190 != null) {
                  if (this.field_1190.method_536() || this.field_1190.method_535()) {
                     this.field_1191.method_51((class_59)this.field_1189.method_701(), this.field_1189.field_1038 == 1);
                     this.field_1198 = 1;
                  }

                  if (this.field_1190.method_540()) {
                     this.field_1193.method_939(class_84.field_1116.method_4(84));
                     this.field_1194 = true;
                  }
               }
            } else if (this.field_1198 == 1) {
               this.field_1198 = 2;
               if (this.field_1189.field_1038 == 0) {
                  if (this.field_1190.method_536()) {
                     int var2 = 0;
                     if (this.field_1190.field_710.field_165 == 5) {
                        var2 = (int)(class_21.method_178().method_607() - this.field_1190.field_710.field_171 / 100.0F * class_21.method_178().field_866);
                     }

                     if (!class_21.method_146() && this.field_1190.field_710.field_166 == 42) {
                        this.field_1192.method_939(class_84.field_1116.method_4(290));
                        this.field_1198 = 2;
                     } else if (this.field_1190.field_710.field_165 == 5 && var2 < class_21.method_178().field_867) {
                        this.field_1192.method_939(class_21.method_219(class_84.field_1116.method_4(88), "" + (class_21.method_178().field_867 - var2)));
                        this.field_1198 = 2;
                     } else {
                        class_21.method_178().method_622(this.field_1190.field_710);
                        class_21.method_197(this.field_1190.method_544());
                        this.field_1189.method_715(0, class_21.method_178());
                        class_19 var3;
                        (var3 = this.field_1190.field_710.method_120()).method_124();
                        var3.field_176 = true;
                        class_21.method_180().method_748(var3);
                        this.field_1189.method_716(1, class_21.method_180().field_1141, class_21.method_180().field_1143);
                        this.field_1192
                           .method_939(class_84.field_1116.method_4(class_1.field_6[this.field_1190.method_545()][0]) + " " + class_84.field_1116.method_4(90));
                     }
                  } else {
                     this.field_1198 = 1;
                  }
               } else if (this.field_1189.field_1038 == 1) {
                  if (this.field_1190.method_536()) {
                     if (!this.field_1190.method_541()) {
                        this.field_1192
                           .method_939(class_21.method_219(class_84.field_1116.method_4(85), "" + (this.field_1190.method_544() - class_21.method_182())));
                     } else if (!this.field_1190.method_542()) {
                        this.field_1192.method_939(class_84.field_1116.method_4(145));
                     } else if (this.field_1190.method_543() && (this.field_1190.method_545() != 42 || !class_21.method_178().method_609(42))) {
                        class_19 var6;
                        if (!(var6 = this.field_1190.field_710.method_120()).field_176) {
                           class_21.method_155();
                        }

                        var6.method_124();
                        var6.field_176 = true;
                        class_21.method_178().method_617(var6);
                        class_21.method_197(-this.field_1190.method_544());
                        class_21.method_180().method_750(this.field_1190.field_710);
                        this.field_1189.method_716(1, class_21.method_180().field_1141, class_21.method_180().field_1143);
                        this.field_1189.method_715(0, class_21.method_178());
                        this.field_1192
                           .method_939(class_84.field_1116.method_4(class_1.field_6[this.field_1190.method_545()][0]) + " " + class_84.field_1116.method_4(91));
                        if (this.field_1190.field_710.field_165 == 6) {
                           ((class_63)class_84.field_1127[1]).field_757.method_446();
                        }
                     } else {
                        this.field_1192.method_939(class_84.field_1116.method_4(144));
                     }

                     this.field_1198 = 2;
                  } else if (this.field_1190.method_535()) {
                     this.field_1198 = 6;

                     for (int var7 = 0; var7 < class_21.method_180().field_1143.length; var7++) {
                        if (this.field_1190.method_545() == class_21.method_180().field_1143[var7].field_863) {
                           this.field_1187.method_569(var7);
                           break;
                        }
                     }
                  }
               }
            } else if (this.field_1198 == 6) {
               if (this.field_1190.field_709.method_603() > class_21.method_182() + class_21.method_178().method_603()) {
                  this.field_1192
                     .method_939(
                        class_21.method_219(
                           class_84.field_1116.method_4(85), "" + (this.field_1190.method_544() - class_21.method_182() - class_21.method_178().method_603())
                        )
                     );
                  this.field_1198 = 2;
               } else if (this.field_1190.field_709.field_869 < class_21.method_178().method_623()) {
                  this.field_1192
                     .method_939(
                        class_21.method_219(class_84.field_1116.method_4(86), "" + (class_21.method_178().field_869 - this.field_1190.field_709.field_869))
                     );
                  this.field_1198 = 2;
               } else if ((int)(this.field_1190.field_709.method_607() + class_21.method_178().field_875 / 100.0F * this.field_1190.field_709.method_607())
                  < class_21.method_178().field_867) {
                  this.field_1192
                     .method_939(
                        class_84.field_1116.method_4(87)
                           + " "
                           + class_21.method_219(
                              class_84.field_1116.method_4(88), "" + (class_21.method_178().field_867 - this.field_1190.field_709.method_607())
                           )
                     );
                  this.field_1198 = 2;
               } else {
                  int var8 = 0;

                  for (int var9 = 0; var9 < class_21.method_180().field_1143.length; var9++) {
                     if (this.field_1190.method_545() == class_21.method_180().field_1143[var9].field_863) {
                        var8 = var9;
                        break;
                     }
                  }

                  class_21.method_197(class_21.method_178().method_603() - this.field_1190.field_709.method_603());
                  class_68 var10;
                  class_19[] var4 = (var10 = class_21.method_178()).field_885;
                  class_120[] var5 = var10.field_886;
                  class_21.method_179(class_90.method_783()[this.field_1190.field_709.field_863].method_627());
                  class_21.method_178().field_884 = this.field_1190.field_709.field_884;
                  class_21.method_178().method_629();
                  class_21.method_178().method_616(var4);
                  class_21.method_178().method_611(var5);
                  class_21.method_178().method_628();
                  this.field_1187.method_568(var8, var10.field_863);
                  class_21.method_180().field_1143[var8] = class_90.method_783()[var10.field_863].method_627();
                  class_21.method_180().field_1143[var8].method_628();
                  class_21.method_180().field_1143[var8].field_884 = var10.field_884;
                  this.field_1189.method_715(0, class_21.method_178());
                  this.field_1189.method_716(1, class_21.method_180().field_1141, class_21.method_180().field_1143);
                  this.field_1192
                     .method_939(class_84.field_1116.method_4(class_1.field_8[class_21.method_178().field_863][0]) + " " + class_84.field_1116.method_4(89));
                  this.field_1198 = 2;
               }

               this.field_1187.method_570();
            }
         }

         return true;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_778(int var1, int var2) {
      if (!this.field_1188) {
         return true;
      } else {
         this.field_1186 += var2;
         if (this.field_1198 == 6) {
            this.field_1187.method_549(var1);
         }

         this.method_779();
         this.field_1190 = (class_59)this.field_1189.method_701();
         if (this.field_1194) {
            return true;
         } else {
            if ((var1 & 2) != 0 && this.field_1198 == 1) {
               this.field_1191.method_52(var2);
            }

            if ((var1 & 64) != 0 && this.field_1198 == 1) {
               this.field_1191.method_53(var2);
            }

            return true;
         }
      }
   }

   // $VF: renamed from: c () void
   private void method_779() {
      if (this.field_1198 != 6) {
         class_67.method_587();
      }

      if (this.field_1198 == 0) {
         this.field_1189.method_718();
         this.field_1189.method_719();
      }

      if (this.field_1198 == 1) {
         this.field_1191.method_54();
      } else if (this.field_1198 == 2) {
         this.field_1189.method_718();
         this.field_1189.method_719();
         this.field_1192.method_944();
      } else if (this.field_1198 == 6) {
         this.field_1190 = (class_59)this.field_1189.method_701();
         class_58.method_516(class_84.field_1116.method_4(class_1.field_8[this.field_1190.method_545()][0]), this.field_1195 + this.field_1196 / 2, 5, 1, 8);
      }

      if (!this.field_1194 && this.field_1198 != 2) {
         if (this.field_1198 != 6 && (this.field_1198 != 1 || this.field_1189.field_1038 != 1 || this.field_1190.method_535())) {
            if (this.field_1198 == 1 && this.field_1189.field_1038 == 0 && !this.field_1190.method_535()) {
               class_67.method_593(class_84.field_1116.method_4(61), class_84.field_1116.method_4(65));
            } else if (this.field_1198 == 1 && this.field_1189.field_1038 == 1 && this.field_1190.method_535()) {
               class_67.method_593(class_84.field_1116.method_4(225), class_84.field_1116.method_4(65));
            } else if (this.field_1198 == 1 && this.field_1189.field_1038 == 0 && this.field_1190.method_535()) {
               class_67.method_593("", class_84.field_1116.method_4(65));
            } else {
               class_67.method_593(class_84.field_1116.method_4(226), class_84.field_1116.method_4(65));
            }
         } else {
            class_67.method_593(class_84.field_1116.method_4(43), class_84.field_1116.method_4(65));
         }
      } else {
         class_67.method_593("", "");
      }

      if (this.field_1194) {
         this.field_1193.method_944();
      }
   }
}
