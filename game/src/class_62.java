// $VF: renamed from: ai
public final class class_62 {
   // $VF: renamed from: a int
   private static int field_843 = 0;
   // $VF: renamed from: a long
   private long field_844;
   // $VF: renamed from: a bk
   private class_117 field_845;
   // $VF: renamed from: a boolean
   private boolean field_846;
   // $VF: renamed from: a az
   private class_74 field_847;
   // $VF: renamed from: a bi
   private class_2 field_848;
   // $VF: renamed from: a k
   private class_56 field_849;
   // $VF: renamed from: a z
   private class_53 field_850;
   // $VF: renamed from: b z
   private class_53 field_851;
   // $VF: renamed from: b boolean
   private boolean field_852;
   // $VF: renamed from: b int
   private int field_853;
   // $VF: renamed from: c int
   private int field_854;
   // $VF: renamed from: a int[]
   private int[] field_855;
   // $VF: renamed from: d int
   private int field_856;

   // $VF: renamed from: a () void
   public final void method_594() {
      this.field_855 = null;
      if (this.field_847 != null) {
         this.field_847.method_707();
      }

      this.field_847 = null;
      this.field_848 = null;
      this.field_849 = null;
      this.field_850 = null;
      this.field_851 = null;
      this.field_846 = false;
      System.gc();
   }

   // $VF: renamed from: b () void
   public final void method_595() {
      this.field_847 = new class_74(new String[]{class_41.field_533.method_297(79), class_41.field_533.method_297(81)}, class_41.field_533.method_297(62));
      this.field_847.method_708(0, class_3.method_108());
      this.field_847.method_709(1, class_3.method_110().field_835, class_3.method_110().field_837);
      this.field_849 = new class_56();
      this.field_850 = new class_53(20, class_41.field_538 / 3, class_41.field_537 - 40);
      this.field_856 = 0;
      this.field_845 = ((class_118)class_41.field_544[1]).field_1465;
      this.field_851 = new class_53(10, class_41.field_538 / 3, class_41.field_537 - 20);
      this.field_853 = 5;
      this.field_854 = class_41.field_537 - 10;
      this.field_855 = new int[3];
      this.field_855[0] = this.field_854 / 3 - 2;
      this.field_855[1] = this.field_855[0];
      this.field_855[2] = this.field_854 - this.field_855[0] - this.field_855[1] - 4;
      this.field_847.method_695(field_843);
      System.gc();
      this.field_846 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_596() {
      return this.field_856 == 0;
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_597(int var1) {
      this.field_848 = (class_2)this.field_847.method_694();
      if (var1 == 256) {
         if (this.field_852 && this.field_844 > 200L) {
            this.field_852 = false;
            return true;
         }

         if (this.field_856 == 4) {
            this.field_856 = 0;
         } else if (this.field_856 == 0) {
            if (this.field_847.method_710() && this.field_847.method_694() != null) {
               if (this.field_848.method_51()) {
                  this.field_851.method_513(class_41.field_533.method_297(84));
                  this.field_852 = true;
               } else if (this.field_848.method_47() || this.field_848.method_46()) {
                  this.field_849.method_525((class_2)this.field_847.method_694(), this.field_847.field_1057 == 2);
                  this.field_856 = 1;
               }
            }
         } else if (this.field_856 == 1) {
            this.field_856 = 0;
         } else if (this.field_856 == 2) {
            this.field_856 = 0;
         } else if (this.field_856 == 3) {
            this.field_856 = 0;
            this.field_847.method_708(1, class_3.method_108());
         }
      }

      if (this.field_852) {
         return true;
      } else {
         if (var1 == 2 && this.field_856 == 0) {
            this.field_847.method_697();
         }

         if (var1 == 64 && this.field_856 == 0) {
            this.field_847.method_698();
         }

         if (var1 == 4 && (this.field_856 == 4 || this.field_856 == 0)) {
            this.field_847.method_699();
         }

         if (var1 == 32 && (this.field_856 == 4 || this.field_856 == 0)) {
            this.field_847.method_700();
         }

         if (var1 == 8192) {
            if (this.field_856 == 4) {
               field_843 = this.field_847.field_1057;
               return false;
            }

            if (this.field_856 == 0) {
               return false;
            }

            if (this.field_856 == 1) {
               this.field_856 = 0;
            } else if (this.field_856 == 5) {
               this.field_856 = 4;
            } else if (this.field_856 == 6) {
               this.field_856 = 1;
               this.field_845.method_916();
            }
         }

         if (var1 == 16384) {
            if (this.field_856 == 4) {
               this.field_856 = 5;
            } else if (this.field_856 == 0) {
               if (this.field_848 != null) {
                  if (this.field_848.method_47() || this.field_848.method_46()) {
                     this.field_849.method_525((class_2)this.field_847.method_694(), this.field_847.field_1057 == 1);
                     this.field_856 = 1;
                  }

                  if (this.field_848.method_51()) {
                     this.field_851.method_513(class_41.field_533.method_297(84));
                     this.field_852 = true;
                  }
               }
            } else if (this.field_856 == 1) {
               this.field_856 = 2;
               if (this.field_847.field_1057 == 0) {
                  if (this.field_848.method_47()) {
                     int var2 = 0;
                     if (this.field_848.field_22.field_710 == 5) {
                        var2 = (int)(class_3.method_108().method_367() - this.field_848.field_22.field_716 / 100.0F * class_3.method_108().field_425);
                     }

                     if (!class_3.method_76() && this.field_848.field_22.field_711 == 42) {
                        this.field_850.method_513(class_41.field_533.method_297(290));
                        this.field_856 = 2;
                     } else if (this.field_848.field_22.field_710 == 5 && var2 < class_3.method_108().field_426) {
                        this.field_850.method_513(class_3.method_149(class_41.field_533.method_297(88), "" + (class_3.method_108().field_426 - var2)));
                        this.field_856 = 2;
                     } else {
                        class_3.method_108().method_382(this.field_848.field_22);
                        class_3.method_127(this.field_848.method_55());
                        this.field_847.method_708(0, class_3.method_108());
                        class_51 var3;
                        (var3 = this.field_848.field_22.method_505()).method_509();
                        var3.field_721 = true;
                        class_3.method_110().method_588(var3);
                        this.field_847.method_709(1, class_3.method_110().field_835, class_3.method_110().field_837);
                        this.field_850
                           .method_513(
                              class_41.field_533.method_297(class_22.field_320[this.field_848.method_56()][0]) + " " + class_41.field_533.method_297(90)
                           );
                     }
                  } else {
                     this.field_856 = 1;
                  }
               } else if (this.field_847.field_1057 == 1) {
                  if (this.field_848.method_47()) {
                     if (!this.field_848.method_52()) {
                        this.field_850
                           .method_513(class_3.method_149(class_41.field_533.method_297(85), "" + (this.field_848.method_55() - class_3.method_112())));
                     } else if (!this.field_848.method_53()) {
                        this.field_850.method_513(class_41.field_533.method_297(145));
                     } else if (this.field_848.method_54() && (this.field_848.method_56() != 42 || !class_3.method_108().method_369(42))) {
                        class_51 var6;
                        if (!(var6 = this.field_848.field_22.method_505()).field_721) {
                           class_3.method_85();
                        }

                        var6.method_509();
                        var6.field_721 = true;
                        class_3.method_108().method_377(var6);
                        class_3.method_127(-this.field_848.method_55());
                        class_3.method_110().method_590(this.field_848.field_22);
                        this.field_847.method_709(1, class_3.method_110().field_835, class_3.method_110().field_837);
                        this.field_847.method_708(0, class_3.method_108());
                        this.field_850
                           .method_513(
                              class_41.field_533.method_297(class_22.field_320[this.field_848.method_56()][0]) + " " + class_41.field_533.method_297(91)
                           );
                        if (this.field_848.field_22.field_710 == 6) {
                           ((class_118)class_41.field_544[1]).field_1482.method_641();
                        }
                     } else {
                        this.field_850.method_513(class_41.field_533.method_297(144));
                     }

                     this.field_856 = 2;
                  } else if (this.field_848.method_46()) {
                     this.field_856 = 6;

                     for (int var7 = 0; var7 < class_3.method_110().field_837.length; var7++) {
                        if (this.field_848.method_56() == class_3.method_110().field_837[var7].field_422) {
                           this.field_845.method_915(var7);
                           break;
                        }
                     }
                  }
               }
            } else if (this.field_856 == 6) {
               if (this.field_848.field_21.method_363() > class_3.method_112() + class_3.method_108().method_363()) {
                  this.field_850
                     .method_513(
                        class_3.method_149(
                           class_41.field_533.method_297(85), "" + (this.field_848.method_55() - class_3.method_112() - class_3.method_108().method_363())
                        )
                     );
                  this.field_856 = 2;
               } else if (this.field_848.field_21.field_428 < class_3.method_108().method_383()) {
                  this.field_850
                     .method_513(
                        class_3.method_149(class_41.field_533.method_297(86), "" + (class_3.method_108().field_428 - this.field_848.field_21.field_428))
                     );
                  this.field_856 = 2;
               } else if ((int)(this.field_848.field_21.method_367() + class_3.method_108().field_434 / 100.0F * this.field_848.field_21.method_367())
                  < class_3.method_108().field_426) {
                  this.field_850
                     .method_513(
                        class_41.field_533.method_297(87)
                           + " "
                           + class_3.method_149(class_41.field_533.method_297(88), "" + (class_3.method_108().field_426 - this.field_848.field_21.method_367()))
                     );
                  this.field_856 = 2;
               } else {
                  int var8 = 0;

                  for (int var9 = 0; var9 < class_3.method_110().field_837.length; var9++) {
                     if (this.field_848.method_56() == class_3.method_110().field_837[var9].field_422) {
                        var8 = var9;
                        break;
                     }
                  }

                  class_3.method_127(class_3.method_108().method_363() - this.field_848.field_21.method_363());
                  class_32 var10;
                  class_51[] var4 = (var10 = class_3.method_108()).field_444;
                  class_46[] var5 = var10.field_445;
                  class_3.method_109(class_24.method_313()[this.field_848.field_21.field_422].method_387());
                  class_3.method_108().field_443 = this.field_848.field_21.field_443;
                  class_3.method_108().method_389();
                  class_3.method_108().method_376(var4);
                  class_3.method_108().method_371(var5);
                  class_3.method_108().method_388();
                  this.field_845.method_914(var8, var10.field_422);
                  class_3.method_110().field_837[var8] = class_24.method_313()[var10.field_422].method_387();
                  class_3.method_110().field_837[var8].method_388();
                  class_3.method_110().field_837[var8].field_443 = var10.field_443;
                  this.field_847.method_708(0, class_3.method_108());
                  this.field_847.method_709(1, class_3.method_110().field_835, class_3.method_110().field_837);
                  this.field_850
                     .method_513(class_41.field_533.method_297(class_22.field_322[class_3.method_108().field_422][0]) + " " + class_41.field_533.method_297(89));
                  this.field_856 = 2;
               }

               this.field_845.method_916();
            }
         }

         return true;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_598(int var1, int var2) {
      if (!this.field_846) {
         return true;
      } else {
         this.field_844 += var2;
         if (this.field_856 == 6) {
            this.field_845.method_900(var1);
         }

         this.method_599();
         this.field_848 = (class_2)this.field_847.method_694();
         if (this.field_852) {
            return true;
         } else {
            if ((var1 & 2) != 0 && this.field_856 == 1) {
               this.field_849.method_526(var2);
            }

            if ((var1 & 64) != 0 && this.field_856 == 1) {
               this.field_849.method_527(var2);
            }

            return true;
         }
      }
   }

   // $VF: renamed from: c () void
   private void method_599() {
      if (this.field_856 != 6) {
         class_69.method_663();
      }

      if (this.field_856 == 0) {
         this.field_847.method_711();
         this.field_847.method_712();
      }

      if (this.field_856 == 1) {
         this.field_849.method_528();
      } else if (this.field_856 == 2) {
         this.field_847.method_711();
         this.field_847.method_712();
         this.field_850.method_518();
      } else if (this.field_856 == 6) {
         this.field_848 = (class_2)this.field_847.method_694();
         class_50.method_483(class_41.field_533.method_297(class_22.field_322[this.field_848.method_56()][0]), this.field_853 + this.field_854 / 2, 5, 1, 8);
      }

      if (!this.field_852 && this.field_856 != 2) {
         if (this.field_856 != 6 && (this.field_856 != 1 || this.field_847.field_1057 != 1 || this.field_848.method_46())) {
            if (this.field_856 == 1 && this.field_847.field_1057 == 0 && !this.field_848.method_46()) {
               class_69.method_669(class_41.field_533.method_297(61), class_41.field_533.method_297(65));
            } else if (this.field_856 == 1 && this.field_847.field_1057 == 1 && this.field_848.method_46()) {
               class_69.method_669(class_41.field_533.method_297(225), class_41.field_533.method_297(65));
            } else if (this.field_856 == 1 && this.field_847.field_1057 == 0 && this.field_848.method_46()) {
               class_69.method_669("", class_41.field_533.method_297(65));
            } else {
               class_69.method_669(class_41.field_533.method_297(226), class_41.field_533.method_297(65));
            }
         } else {
            class_69.method_669(class_41.field_533.method_297(43), class_41.field_533.method_297(65));
         }
      } else {
         class_69.method_669("", "");
      }

      if (this.field_852) {
         this.field_851.method_518();
      }
   }
}
