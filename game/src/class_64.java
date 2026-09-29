// $VF: renamed from: br
public final class class_64 extends class_61 {
   // $VF: renamed from: a int
   private int field_778;
   // $VF: renamed from: a long
   private long field_779;
   // $VF: renamed from: b long
   private long field_780;
   // $VF: renamed from: c long
   private long field_781;
   // $VF: renamed from: d long
   private long field_782;
   // $VF: renamed from: e long
   private long field_783;
   // $VF: renamed from: f long
   private long field_784;
   // $VF: renamed from: g long
   private long field_785;
   // $VF: renamed from: a boolean
   private boolean field_786;
   // $VF: renamed from: a ba
   private class_70 field_787;
   // $VF: renamed from: a an
   private class_106 field_788;
   // $VF: renamed from: a c
   private class_104 field_789;
   // $VF: renamed from: a ce
   private class_42 field_790;
   // $VF: renamed from: a s
   private class_5 field_791;
   // $VF: renamed from: b boolean
   private boolean field_792;
   // $VF: renamed from: c boolean
   private boolean field_793;
   // $VF: renamed from: d boolean
   private boolean field_794;
   // $VF: renamed from: e boolean
   private boolean field_795;
   // $VF: renamed from: f boolean
   private boolean field_796;
   // $VF: renamed from: b int
   private int field_797;
   // $VF: renamed from: c int
   private int field_798;
   private int deep3dFov;
   // $VF: renamed from: a cz
   private class_26 field_799;
   // $VF: renamed from: a ae
   private class_118 field_800;
   // $VF: renamed from: a cb
   private class_46 field_801;
   // $VF: renamed from: a cr
   private class_34 field_802;
   // $VF: renamed from: a bu
   private class_51 field_803;
   // $VF: renamed from: a bo
   private class_56 field_804;
   // $VF: renamed from: b bo
   private class_56 field_805;
   // $VF: renamed from: a bp
   private class_55 field_806;
   // $VF: renamed from: a y
   private class_2 field_807;
   // $VF: renamed from: a ab
   private class_121 field_808;
   // $VF: renamed from: g boolean
   private boolean field_809;
   // $VF: renamed from: h boolean
   private boolean field_810;
   // $VF: renamed from: i boolean
   private boolean field_811;
   // $VF: renamed from: j boolean
   private boolean field_812;
   // $VF: renamed from: k boolean
   private boolean field_813;
   // $VF: renamed from: l boolean
   private boolean field_814;
   // $VF: renamed from: m boolean
   private boolean field_815;
   // $VF: renamed from: d int
   private int field_816;
   // $VF: renamed from: n boolean
   private boolean field_817;

   // $VF: renamed from: b () void
   public final void method_552() {
      if (this.field_787 != null) {
         this.field_787.method_680();
      }

      this.field_787 = null;
      if (this.field_804 != null) {
         this.field_804.method_458();
      }

      this.field_804 = null;
      this.field_794 = false; // Deep3D-PC: no popup left open without its object
      this.field_788 = null;
      if (this.field_799 != null) {
         this.field_799.method_271();
      }

      this.field_799 = null;
      if (this.field_801 != null) {
         this.field_801.method_388();
      }

      this.field_801 = null;
      if (this.field_802 != null) {
         this.field_802.method_297();
      }

      this.field_802 = null;
      class_69.method_632();
      if (this.field_803 != null) {
         this.field_803.method_417();
      }

      this.field_790.method_368(null);
      this.field_790.method_369(null);
      this.field_789 = null;
      this.field_788 = null;
      this.field_803 = null;
      this.field_800 = null;
      this.field_786 = false;
      this.field_807 = null;
      System.gc();
   }

   // $VF: renamed from: a () void
   public final void method_551() {
      if (this.field_799 == null) {
         this.field_799 = new class_26();
      }

      if (this.field_799.method_240()) {
         this.method_560();
         class_69.method_631();
         this.field_797 = this.field_799.field_291;
         class_84.field_1122.method_773();
         if (class_21.field_220 >= 0) {
            this.field_787.field_969.method_327(class_21.field_220);
         }

         if (class_21.field_218 >= 0) {
            this.field_787.field_969.method_328(class_21.field_218);
         }

         if (class_21.field_219 >= 0) {
            this.field_787.field_969.method_329(class_21.field_219);
         }

         this.field_787.method_649();
         class_21.field_220 = class_21.method_178().field_864;
         class_21.field_218 = class_21.method_178().field_871;
         class_21.field_219 = class_21.method_178().field_872;
         this.field_817 = false;
         this.field_811 = false;
         this.field_813 = false;
         this.field_814 = false;
         int var1;
         if ((var1 = class_21.method_178().field_891) >= 0 && this.field_787.field_969.field_359 != null) {
            if (var1 >= this.field_787.field_969.field_359.length) {
               var1 = 0;
            }

            while (var1 != this.field_787.field_987) {
               this.field_787.method_661();
            }
         }

         class_67.method_597(false);
         class_69.method_634(-1, -1, "");
         System.gc();
         this.field_779 = System.currentTimeMillis();
         this.field_780 = System.currentTimeMillis();
         this.field_784 = 0L;
         this.field_785 = 0L;
         this.field_786 = true;
      }
   }

   // $VF: renamed from: e () void
   private void method_560() {
      this.field_787 = this.field_799.field_272;
      this.field_802 = new class_34();
      this.field_802.method_298(this.field_799.field_280);
      this.field_788 = class_106.method_886(class_84.field_1120, class_84.field_1121, org.deep3d.Config.flightFov(), 100, 4194304);
      // Deep3D-PC: Field of view; the far plane reaches every structure
      this.deep3dFov = org.deep3d.Config.flightFov();
      this.field_798 = this.deep3dFov;
      this.field_789 = new class_104();
      this.field_789.method_879(this.field_788);
      class_84.field_1110.method_24(this.field_788);
      this.field_790 = new class_42(this.field_787.field_970, this.field_788);
      this.field_790.deep3dDolly = deep3dDolly(); // Deep3D-PC
      this.field_791 = new class_5(this.field_787.field_970, this.field_788);
      this.field_791.field_53 = false;
      this.field_789.method_880(this.field_791);
      this.field_789.method_880(this.field_790);
      this.field_801 = new class_46(this.field_799);
      this.field_797 = this.field_799.field_291;
      class_69.method_638(null);
      this.field_800 = new class_118(this.field_790, this.field_791, this.field_799);
      class_118.method_916(this.field_790, this.field_799);
      this.field_792 = false;
      this.field_796 = false;
      this.field_778 = 0;
      this.field_793 = false;
      this.field_795 = false;
      this.field_784 = 0L;
      this.field_785 = 0L;
      this.field_812 = false;
      this.field_809 = false;
      this.field_810 = false;
      this.field_815 = false;
      this.field_779 = System.currentTimeMillis();
      this.field_780 = System.currentTimeMillis();
   }

   // $VF: renamed from: a () boolean
   public final boolean method_553() {
      return this.field_786;
   }

   // $VF: renamed from: b (int) void
   public final void method_549(int var1) {
      try {
         if (this.field_786) {
            this.field_779 = System.currentTimeMillis();
            this.field_781 = this.field_779 - this.field_780;
            this.field_780 = this.field_779;
            this.field_783 = this.field_783 + this.field_781;
            this.field_782 = this.field_782 + this.field_781;
            if (!this.field_793) {
               this.field_784 = this.field_784 + this.field_781;
               if (!this.field_795) {
                  this.field_785 = this.field_785 + this.field_781;
               }

               class_21.method_211(this.field_781);
               class_67.method_579((int)this.field_781);
            }

            if (!this.field_796) {
               if (this.field_793) {
                  if (!this.field_794 && !this.field_812 && !this.field_809 && !this.field_810 && !this.field_817) {
                     this.field_803.method_418(var1, (int)this.field_781);
                     if (this.field_782 > 150L) {
                        this.field_782 = 0L;
                        if ((var1 & 2) != 0) {
                           this.field_803.method_420((int)this.field_781);
                        }

                        if ((var1 & 64) != 0) {
                           this.field_803.method_421((int)this.field_781);
                        }
                     }
                  }

                  if (!this.field_786) {
                     return;
                  }

                  this.field_799.method_266(this.field_781);
                  this.field_787.method_681(!this.field_795);
                  class_84.field_1111.method_683(class_84.field_1117);
                  class_84.field_1110.method_26();
                  class_84.field_1111.method_684(class_84.field_1117);
                  if (this.field_812) {
                     this.field_807.method_8();
                     return;
                  }

                  if (!this.field_809 && !this.field_810) {
                     if (this.field_817) {
                        this.field_805.method_460(var1, (int)this.field_781);
                        if (this.field_811) {
                           this.field_806.method_450(0, (int)this.field_781);
                        }

                        this.field_805.method_468();
                        return;
                     }

                     if (this.field_794) {
                        class_67.method_579((int)this.field_781);
                        this.field_804.method_460(var1, (int)this.field_781);
                        this.field_804.method_467();
                        return;
                     }

                     this.field_803.method_429();
                     return;
                  }

                  this.field_808.method_944();
                  return;
               }

               if ((this.field_800.field_1447 || !this.field_800.field_1446)
                  && !this.field_809
                  && !this.field_810
                  && this.method_566(var1, (int)this.field_781)) {
                  return;
               }

               if (!class_84.field_1104
                  && class_21.method_143() > 14
                  && this.field_784 > 20000L
                  && !class_21.method_178().method_605()
                  && this.field_799.field_273 == null) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(347));
                  }

                  this.field_817 = true;
                  class_84.field_1104 = true;
               }

               if (!class_84.field_1099 && this.field_787.field_1004 < class_21.method_178().field_889) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(344));
                  }

                  this.field_817 = true;
                  class_84.field_1099 = true;
               }

               if (!class_84.field_1100 && this.field_787.field_1004 > class_21.method_178().field_890) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(345));
                  }

                  this.field_817 = true;
                  class_84.field_1100 = true;
               }

               if (!class_84.field_1101 && class_21.method_172() == 1) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(348));
                  }

                  this.field_817 = true;
                  class_84.field_1101 = true;
               }

               if (!class_84.field_1102 && class_69.method_641() && class_21.method_143() != 7 && class_21.method_180().field_1134 != 1) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(349));
                  }

                  this.field_817 = true;
                  class_84.field_1102 = true;
               }

               if (this.field_785 > 3000L && !this.field_794 && !class_21.method_132().field_1162 && !class_21.method_132().field_1163) {
                  this.method_565();
               }
            }

            if (this.field_787.field_994) {
               this.field_798 = org.deep3d.Config.flightFov() + (int)(this.field_787.method_652() * 400.0F);
               this.field_788.method_882(this.field_798);
            } else if (this.deep3dFov != org.deep3d.Config.flightFov()) {
               // Deep3D-PC: a changed Field of view applies at once
               this.field_798 += org.deep3d.Config.flightFov() - this.deep3dFov;
               this.field_788.method_882(this.field_798);
            }

            if (this.field_790 != null) {
               this.field_790.deep3dDolly = deep3dDolly();
            }

            this.deep3dFov = org.deep3d.Config.flightFov();

            if (class_21.method_132().field_1162 || this.field_796 || !this.method_564()) {
               if (!this.field_796) {
                  this.method_563();
               }

               this.field_795 = this.field_800.method_913((int)this.field_781, this.field_790, this.field_807);
               this.method_561();
               this.method_562();
               if (!this.field_796 && !this.field_795) {
                  if (this.field_787.field_987 >= 0 && this.field_792 && !this.field_787.method_662()) {
                     this.field_787.method_656(this.field_781);
                  }

                  // Deep3D-PC: a deflected controller stick replaces the
                  // digital direction keys.
                  if (org.deep3d.AnalogInput.active()) {
                     var1 &= ~(2 | 4 | 32 | 64);
                     if (this.field_787.field_1007) {
                        class_69.method_633(7, this.field_787);
                     } else {
                        float var90 = -org.deep3d.AnalogInput.y();
                        this.field_787.steerAnalog(this.field_781, -org.deep3d.AnalogInput.x(),
                              class_84.field_1082 ? var90 : -var90);
                     }
                  }

                  if ((var1 & 4) != 0) {
                     if (this.field_787.field_1007) {
                        class_69.method_633(7, this.field_787);
                     } else {
                        this.field_787.method_673(this.field_781);
                     }
                  }

                  if ((var1 & 32) != 0) {
                     if (this.field_787.field_1007) {
                        class_69.method_633(7, this.field_787);
                     } else {
                        this.field_787.method_674(this.field_781);
                     }
                  }

                  if ((var1 & 2) != 0) {
                     if (this.field_787.field_1007) {
                        class_69.method_633(7, this.field_787);
                     } else if (class_84.field_1082) {
                        this.field_787.method_675(this.field_781);
                     } else {
                        this.field_787.method_676(this.field_781);
                     }
                  }

                  if ((var1 & 64) != 0) {
                     if (this.field_787.field_1007) {
                        class_69.method_633(7, this.field_787);
                     } else if (class_84.field_1082) {
                        this.field_787.method_676(this.field_781);
                     } else {
                        this.field_787.method_675(this.field_781);
                     }
                  }

                  if ((var1 & 256) != 0) {
                     this.field_787.method_656(this.field_781);
                  }
               }

               if (this.field_800.field_1446 && class_21.method_143() == 1) {
                  if (this.field_783 > 68000L) {
                     this.field_783 = 0L;
                  } else if (this.field_783 > 8750L && this.field_816 == 2) {
                     this.field_816++;
                     class_84.field_1122.method_768(0);
                  } else if (this.field_783 > 3500L && this.field_816 == 0 || this.field_783 > 7000L && this.field_816 == 1) {
                     this.field_816++;
                     class_84.field_1122.method_770(0);
                  }
               } else if (this.field_783 > 10000L) {
                  class_84.field_1122
                     .method_769(
                        class_88.field_1174[class_84.field_1123.nextInt(class_88.field_1174.length)],
                        class_16.method_97(60, class_84.field_1123.nextInt(class_84.field_1122.field_1182))
                     );
                  this.field_783 = 0L;
               }
            }
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: f () void
   private void method_561() {
      try {
         this.field_799.method_267(this.field_781);
         this.field_799.method_265(this.field_781);
         this.field_787.method_671(this.field_781);
         this.field_787.method_681(!this.field_795);
         class_84.field_1111.method_683(class_84.field_1117);
         this.field_789.method_839(true);
         class_84.field_1110.method_27(System.currentTimeMillis());
         class_84.field_1111.method_684(class_84.field_1117);
      } catch (Exception var2) {
         class_84.field_1111.method_684(class_84.field_1117);
         var2.printStackTrace();
      }
   }

   // $VF: renamed from: g () void
   private void method_562() {
      if (this.field_795) {
         if (class_21.method_143() > 1 && !this.field_800.field_1456) {
            class_84.field_1113.method_294();
         } else {
            class_69.method_646();
         }

         class_69.method_647();
         if (!this.field_800.field_1456) {
            class_69.method_642(this.field_781, this.field_787, true);
         }
      } else if (this.field_796) {
         class_58.method_516(class_84.field_1116.method_4(139), class_84.field_1120 / 2, 20, 0, 8);
         if (this.field_785 > 3000L) {
            this.field_808.method_944();
         }
      } else {
         this.field_787.method_682(!this.field_795, this.field_788);
         this.field_801.method_390(this.field_787.field_969, this.field_788);
         class_69.method_644(this.field_793 ? 0L : this.field_781, this.field_797 - this.field_784, this.field_787, this.field_792);
      }

      if (!this.field_796) {
         this.field_802.method_301(this.field_784, this.field_787);
      }
   }

   // $VF: renamed from: h () void
   private void method_563() {
      if (this.field_787.method_659() <= 0) {
         this.field_796 = true;
         class_84.field_1116.method_4(139);
      }

      if (this.field_799.method_270((int)this.field_781)) {
         if (this.field_804 == null) {
            this.field_804 = new class_56();
         }

         this.field_804.method_457(class_21.method_132(), 2);
         this.field_794 = true;
         this.field_793 = true;
      }

      if (this.field_785 > 3000L) {
         this.field_785 = 0L;
         if (this.field_797 > 0 && this.field_784 > this.field_797 && !this.field_799.field_289.method_223()) {
            if (this.field_804 == null) {
               this.field_804 = new class_56();
            }

            this.field_804.method_457(class_21.method_132(), 2);
            this.field_794 = true;
            this.field_793 = true;
         }
      }

      if (this.field_796) {
         this.field_785 = 0L;
         this.field_790.method_371();
         class_84.method_736(0);
         if (this.field_808 == null) {
            this.field_808 = new class_121();
         }

         this.field_808.method_940(class_84.field_1116.method_4(276), true);
      }
   }

   // $VF: renamed from: b () boolean
   private boolean method_564() {
      if (this.field_785 > 3000L) {
         class_87 var1 = class_21.method_148(false, this.field_784);
         if (this.field_799.method_268((int)this.field_784) || var1 != null) {
            if (class_21.method_132().field_1161 && class_21.method_143() == 27) {
               class_21.method_145();
               this.field_799.method_269();
               class_21.method_133(class_87.field_1145);
            } else {
               if (!class_21.method_132().field_1161) {
                  class_21.method_141();
               }

               if (class_21.method_132().field_1161 && (!class_21.method_132().field_1161 || !class_56.method_456(class_21.method_143()))) {
                  return false;
               }

               if (this.field_804 == null) {
                  this.field_804 = new class_56();
               }

               this.field_804.method_457(var1 != null ? var1 : class_21.method_132(), 1);
               this.field_794 = true;
               this.field_793 = true;
            }

            return true;
         }
      }

      return false;
   }

   // $VF: renamed from: c () void
   public final void method_565() {
      if ((
            !this.field_800.field_1447
               || !class_56.method_455(class_21.method_143()) && class_21.method_132().field_1161
               || class_21.method_132().method_754()
               || class_21.method_132().field_1146 == 13
               || class_21.method_132().field_1146 == 14
               || !class_21.method_132().field_1171
         )
         && !class_21.method_139()) {
         if (class_21.method_132().field_1161 && class_21.method_143() == 27 && !this.field_815 && this.field_799.field_273[0].field_1225.field_375) {
            this.field_804 = new class_56(class_21.method_132(), 3);
            this.field_793 = true;
            this.field_794 = true;
            this.field_815 = true;
         }
      } else if (class_21.method_132().field_1161 || class_21.method_132().field_1146 != 8) {
         if (this.field_804 == null) {
            if (class_21.method_139()) {
               this.field_804 = new class_56(class_21.method_135(), 2);
            } else {
               this.field_804 = new class_56(class_21.method_132(), 0);
            }
         }

         this.field_793 = true;
         this.field_794 = true;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_566(int var1, int var2) {
      this.field_813 = this.field_799.method_263(this.field_787.method_664());
      this.field_814 = this.field_799.method_264(this.field_787.method_664());
      if (!class_21.method_132().method_754() && class_21.method_132().field_1146 != 8) {
         if (!this.field_814 && !this.field_813) {
            class_69.method_638(null);
         } else {
            class_69.method_638(class_84.field_1116.method_4(269));
         }

         return false;
      } else {
         if (this.field_813 && ((class_99)this.field_799.field_276[1]).field_1305) {
            class_21.field_220 = this.field_787.field_969.field_363;
            class_21.field_218 = this.field_787.field_969.field_365;
            class_21.field_219 = this.field_787.field_969.field_367;
            if (this.field_787.field_1007 && class_26.field_302 != null) {
               if (!this.field_809) {
                  if (this.field_808 == null) {
                     this.field_808 = new class_121();
                  }

                  this.field_808
                     .method_940(class_84.field_1116.method_4(334) + ": " + class_26.field_302.field_1133 + "\n" + class_84.field_1116.method_4(247), true);
                  this.field_808.method_942();
                  this.field_809 = true;
                  this.field_793 = true;
                  this.field_787.method_667(null);
               }

               return false;
            }

            if (this.field_811) {
               if (!class_84.field_1089 && !this.field_806.method_449()) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(361));
                  }

                  this.field_817 = true;
                  class_84.field_1089 = true;
               } else if (!class_84.field_1090 && this.field_806.method_449()) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(362));
                  }

                  this.field_817 = true;
                  class_84.field_1090 = true;
               }

               this.field_811 = this.field_806.method_450(var1, var2);
               this.field_782 = 0L;
               return true;
            }

            if (!this.field_787.field_1007 && class_21.method_143() > 2 && (class_21.method_143() != 6 || class_21.method_180().field_1134 != 0)) {
               class_69.method_638(class_84.field_1116.method_4(270));
               if (!class_84.field_1097) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(342));
                  }

                  this.field_817 = true;
                  class_84.field_1097 = true;
               }
            }

            if ((var1 & 131072) != 0 || this.field_787.method_668()) {
               if (class_26.field_302 != null) {
                  if (!this.field_809) {
                     if (this.field_808 == null) {
                        this.field_808 = new class_121();
                     }

                     this.field_808
                        .method_940(class_84.field_1116.method_4(334) + ": " + class_26.field_302.field_1133 + "\n" + class_84.field_1116.method_4(247), true);
                     this.field_808.method_942();
                     this.field_809 = true;
                     this.field_793 = true;
                     this.field_787.method_667(null);
                  }

                  return false;
               }

               if (class_21.method_143() != 1 && class_21.method_143() != 2 && (class_21.method_143() != 6 || class_21.method_180().field_1134 != 0)) {
                  if (this.field_806 == null) {
                     this.field_806 = new class_55();
                  }

                  this.field_806.method_446();
                  this.field_806.method_445(null);
                  this.field_806.field_658 = true;
                  this.field_787.method_667(null);
                  this.field_811 = true;
                  return true;
               }

               this.field_805 = new class_56(class_84.field_1116.method_4(291));
               this.field_787.method_667(null);
               this.field_817 = true;
               this.field_793 = true;
            }
         } else if (this.field_814) {
            if (!this.field_787.field_1007) {
               class_69.method_638(class_84.field_1116.method_4(271));
               if (!class_84.field_1098 && this.field_784 > 20000L) {
                  this.field_793 = true;
                  if (this.field_805 == null) {
                     this.field_805 = new class_56(class_84.field_1116.method_4(343));
                  }

                  this.field_817 = true;
                  class_84.field_1098 = true;
               }
            }

            if (this.field_787.method_669()) {
               if ((class_21.method_143() != 5 || class_21.method_180().field_1134 != 0)
                  && (class_21.method_143() != 6 || class_21.method_180().field_1134 == 0)) {
                  class_14.method_67(this.field_787);
                  class_84.field_1126.method_439(class_84.field_1127[1]);
                  return true;
               }

               this.field_805 = new class_56(class_84.field_1116.method_4(class_21.method_143() == 5 ? 292 : 291));
               this.field_817 = true;
               this.field_793 = true;
               this.field_787.method_667(null);
            }

            if ((var1 & 131072) != 0 && !this.field_787.method_668()) {
               if (!this.field_810) {
                  if (this.field_808 == null) {
                     this.field_808 = new class_121();
                  }

                  this.field_808.method_940(class_21.method_219(class_84.field_1116.method_4(272), class_21.method_180().field_1133), true);
                  this.field_808.method_942();
                  this.field_810 = true;
                  this.field_793 = true;
               }

               return false;
            }
         } else {
            class_69.method_638(null);
         }

         return false;
      }
   }

   // $VF: renamed from: d () void
   public final void method_567() {
      if (!this.field_793) {
         if (this.field_803 == null) {
            this.field_803 = new class_51();
         }

         this.field_803.method_428();
         this.field_793 = true;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_550(int var1) {
      if (this.field_786) {
         if (this.field_793) {
            if (this.field_817 && var1 == 256) {
               this.field_817 = false;
               this.field_793 = false;
               this.field_805 = null;
               this.field_787.method_679();
               return;
            }

            if (this.field_794) {
               if (!this.field_804.method_459(var1)) {
                  this.field_793 = false;
                  this.field_794 = false;
                  if (class_21.method_139()) {
                     class_21.method_136(class_87.field_1145);
                  } else if (class_21.method_132().field_1162) {
                     if (class_21.method_132().field_1161) {
                        class_84.field_1126.method_439(class_84.field_1127[0]);
                        class_84.field_1122.method_768(0);
                        class_21.method_221();
                        return;
                     }

                     class_21.method_136(class_87.field_1145);
                     this.field_799.method_269();
                     this.field_797 = 0;
                     class_21.method_133(class_87.field_1145);
                     this.field_787.field_982 = null;
                     if (this.field_787.field_1009) {
                        this.field_787.method_667(null);
                     }

                     this.field_787.method_654();
                     this.field_799.field_277 = null;
                     this.field_807 = new class_2(this.field_799);
                  } else if (!class_21.method_132().field_1163 && !class_21.method_137().field_1163) {
                     this.field_800.method_915();
                  } else {
                     boolean var2 = class_21.method_137().field_1163 && !class_21.method_132().field_1161;
                     class_87 var3;
                     if ((var3 = class_21.method_132().field_1163 ? class_21.method_132() : class_21.method_137()).field_1157) {
                        class_84.field_1126.method_439(class_84.field_1127[0]);
                        class_84.field_1122.method_768(0);
                        return;
                     }

                     if (var3.field_1161) {
                        class_21.method_145();
                     } else {
                        class_21.method_136(class_87.field_1145);
                     }

                     class_21.method_197(var3.field_1150);
                     class_69.method_639(var3.field_1150);
                     this.field_797 = 0;
                     if (!var2) {
                        this.field_799.method_269();
                        class_21.method_133(class_87.field_1145);
                        this.field_787.field_982 = null;
                        if (this.field_787.field_1009) {
                           this.field_787.method_667(null);
                        }

                        this.field_787.method_654();
                        this.field_799.field_277 = null;
                        this.field_807 = new class_2(this.field_799);
                     }
                  }

                  this.field_782 = 0L;
                  return;
               }
            } else {
               if (this.field_812) {
                  if (var1 == 1024) {
                     this.field_812 = false;
                     this.field_793 = false;
                  }

                  if (var1 == 2 && this.field_812) {
                     this.field_807.method_6();
                  }

                  if (var1 == 64 && this.field_812) {
                     this.field_807.method_7();
                  }

                  if (var1 == 256 && this.field_812) {
                     this.field_812 = false;
                     class_69.method_638(null);
                     class_69.method_633(5, this.field_787);
                     if (this.field_787 != null) {
                        this.field_787.method_679();
                     }

                     this.field_793 = false;
                     int var4 = this.field_807.field_31;
                     switch (this.field_807.field_31) {
                        case 0:
                           this.field_787.method_667(this.field_799.field_276[1]);
                           return;
                        case 1:
                           this.field_787.method_667(this.field_799.field_276[0]);
                           return;
                        case 2:
                           if (this.field_799.field_277 != null) {
                              this.field_787.method_667(this.field_799.field_277.method_110());
                           }
                     }
                  }

                  return;
               }

               if (this.field_809) {
                  if (var1 == 256) {
                     this.field_809 = false;
                     if (class_21.method_143() != 1 && class_21.method_143() != 2 && (class_21.method_143() != 6 || class_21.method_180().field_1134 != 0)) {
                        if (this.field_808.method_941()) {
                           if (class_21.method_143() == 5) {
                              class_21.method_137().method_759(class_26.field_302.field_1134);
                           }

                           class_21.method_131(class_26.field_302);
                           class_26.method_239();
                           class_26.field_302 = null;
                           class_69.method_639(0);
                           class_84.field_1126.method_439(class_84.field_1127[2]);
                           class_21.method_150();
                        } else {
                           if (this.field_806 == null) {
                              this.field_806 = new class_55();
                           }

                           this.field_806.method_446();
                           this.field_806.method_445(null);
                           this.field_806.field_658 = true;
                           this.field_811 = true;
                           this.field_793 = false;
                        }
                     } else {
                        this.field_805 = new class_56(class_84.field_1116.method_4(291));
                        this.field_817 = true;
                        this.field_793 = true;
                     }
                  }

                  if (var1 == 4) {
                     this.field_808.method_942();
                  }

                  if (var1 == 32) {
                     this.field_808.method_943();
                     return;
                  }
               } else if (this.field_810) {
                  if (var1 == 256) {
                     this.field_810 = false;
                     if (!this.field_808.method_941()) {
                        this.field_793 = false;
                     } else if (class_21.method_143() == 5 && class_21.method_180().field_1134 == 0
                        || class_21.method_143() == 6 && class_21.method_180().field_1134 != 0) {
                        this.field_805 = new class_56(class_84.field_1116.method_4(class_21.method_143() == 5 ? 292 : 291));
                        this.field_817 = true;
                        this.field_793 = true;
                     } else {
                        class_14.method_67(this.field_787);
                        class_84.field_1126.method_439(class_84.field_1127[1]);
                     }
                  }

                  if (var1 == 4) {
                     this.field_808.method_942();
                  }

                  if (var1 == 32) {
                     this.field_808.method_943();
                     return;
                  }
               } else if (this.field_803 != null) {
                  this.field_803.method_430(var1);
                  if (var1 == 256 && this.field_803.method_419()) {
                     this.field_793 = false;
                     return;
                  }

                  if (var1 == 16384 && this.field_803.method_426()) {
                     this.field_793 = false;
                  }

                  if (var1 == 8192 && this.field_803.method_425()) {
                     this.field_793 = false;
                  }

                  if (var1 == 4) {
                     this.field_803.method_422();
                  }

                  if (var1 == 32) {
                     this.field_803.method_424();
                     return;
                  }
               }
            }
         } else {
            if (this.field_811) {
               this.field_811 = this.field_806.method_447(var1);
               return;
            }

            if (!this.field_796) {
               if (var1 == 16384) {
                  if (this.field_803 == null) {
                     this.field_803 = new class_51();
                  }

                  this.field_803.method_428();
                  this.field_793 = !this.field_793;
                  if (this.field_793) {
                     return;
                  }
               }

               if (!this.field_795) {
                  if (var1 == 4096) {
                     if (this.field_778 != 2) {
                        class_118.method_918(this.field_790);
                        this.field_778 = 2;
                     } else {
                        class_118.method_916(this.field_790, this.field_799);
                        this.field_778 = 0;
                     }
                  }

                  if (var1 == 131072) {
                     if (this.field_778 != 1) {
                        class_118.method_917(this.field_790);
                        this.field_778 = 1;
                     } else {
                        class_118.method_916(this.field_790, this.field_799);
                        this.field_778 = 0;
                     }
                  }

                  if (var1 == 2048) {
                     if (this.field_778 != 3) {
                        class_118.method_919(this.field_790);
                        this.field_778 = 3;
                     } else {
                        class_118.method_916(this.field_790, this.field_799);
                        this.field_778 = 0;
                     }
                  }

                  if (var1 == 65536 && !this.field_787.field_994) {
                     this.field_787.method_650();
                     class_69.method_633(3, this.field_787);
                  }

                  if (var1 == 32768 && this.field_787.field_987 != -1) {
                     this.field_787.method_661();
                     class_69.method_633(0, this.field_787);
                  }

                  if (var1 == 512) {
                     this.field_792 = !this.field_792;
                     class_69.method_633(this.field_792 ? 1 : 2, this.field_787);
                  }

                  if (var1 == 1024) {
                     if (this.field_787.field_1007) {
                        this.field_787.method_667(null);
                        class_69.method_633(6, this.field_787);
                        return;
                     }

                     if (!this.field_812) {
                        if (this.field_807 == null || this.field_799.field_277 != null && this.field_799.field_277.method_111().field_1298) {
                           this.field_807 = new class_2(this.field_799);
                        }

                        this.field_812 = true;
                        this.field_793 = true;
                        return;
                     }
                  }
               } else {
                  if (var1 == 256) {
                     this.field_800.method_914();
                     this.field_787.method_679();
                  }

                  if (var1 == 65536 && !this.field_787.field_994) {
                     this.field_787.method_650();
                     class_69.method_633(3, this.field_787);
                     return;
                  }
               }
            } else if (this.field_785 > 3000L) {
               if (class_21.method_177() == 0) {
                  class_84.field_1126.method_439(class_84.field_1127[0]);
                  class_84.field_1122.method_768(0);
                  return;
               }

               if (var1 == 32) {
                  this.field_808.method_943();
                  return;
               }

               if (var1 == 4) {
                  this.field_808.method_942();
                  return;
               }

               if (var1 == 256) {
                  if (this.field_808.method_941()) {
                     class_41[] var5;
                     (var5 = class_27.method_272())[var5.length - 1].method_367();
                     ((class_63)class_84.field_1127[1]).method_554();
                     class_84.field_1126.method_439(class_84.field_1127[1]);
                     return;
                  }

                  class_84.field_1126.method_439(class_84.field_1127[0]);
                  class_84.field_1122.method_768(0);
                  return;
               }
            }
         }
      }
   }

   // Deep3D-PC: how far in the chase camera moves for the Field of view
   // (1 at the phone's 44 degrees, 500 units): tan(phone / 2) / tan(fov / 2)
   private static float deep3dDolly() {
      int var0 = org.deep3d.Config.flightFov();
      return var0 == 500 ? 1.0F : (float)(Math.tan(500 * Math.PI / 4096.0) / Math.tan(var0 * Math.PI / 4096.0));
   }
}
