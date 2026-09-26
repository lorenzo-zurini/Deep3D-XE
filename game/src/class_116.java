// $VF: renamed from: br
public final class class_116 extends class_113 {
   // $VF: renamed from: a int
   private int field_1398;
   // $VF: renamed from: a long
   private long field_1399;
   // $VF: renamed from: b long
   private long field_1400;
   // $VF: renamed from: c long
   private long field_1401;
   // $VF: renamed from: d long
   private long field_1402;
   // $VF: renamed from: e long
   private long field_1403;
   // $VF: renamed from: f long
   private long field_1404;
   // $VF: renamed from: g long
   private long field_1405;
   // $VF: renamed from: a boolean
   private boolean field_1406;
   // $VF: renamed from: a bb
   private class_16 field_1407;
   // $VF: renamed from: a am
   private class_111 field_1408;
   // $VF: renamed from: a c
   private class_99 field_1409;
   // $VF: renamed from: a ce
   private class_65 field_1410;
   // $VF: renamed from: a s
   private class_71 field_1411;
   // $VF: renamed from: b boolean
   private boolean field_1412;
   // $VF: renamed from: c boolean
   private boolean field_1413;
   // $VF: renamed from: d boolean
   private boolean field_1414;
   // $VF: renamed from: e boolean
   private boolean field_1415;
   // $VF: renamed from: f boolean
   private boolean field_1416;
   // $VF: renamed from: b int
   private int field_1417;
   // $VF: renamed from: c int
   private int field_1418;
   // $VF: renamed from: a cy
   private class_57 field_1419;
   // $VF: renamed from: a ad
   private class_64 field_1420;
   // $VF: renamed from: a cb
   private class_47 field_1421;
   // $VF: renamed from: a cq
   private class_42 field_1422;
   // $VF: renamed from: a bu
   private class_67 field_1423;
   // $VF: renamed from: a bo
   private class_30 field_1424;
   // $VF: renamed from: b bo
   private class_30 field_1425;
   // $VF: renamed from: a bp
   private class_68 field_1426;
   // $VF: renamed from: a w
   private class_33 field_1427;
   // $VF: renamed from: a z
   private class_53 field_1428;
   // $VF: renamed from: g boolean
   private boolean field_1429;
   // $VF: renamed from: h boolean
   private boolean field_1430;
   // $VF: renamed from: i boolean
   private boolean field_1431;
   // $VF: renamed from: j boolean
   private boolean field_1432;
   // $VF: renamed from: k boolean
   private boolean field_1433;
   // $VF: renamed from: l boolean
   private boolean field_1434;
   // $VF: renamed from: m boolean
   private boolean field_1435;
   // $VF: renamed from: d int
   private int field_1436;
   // $VF: renamed from: n boolean
   private boolean field_1437;

   // $VF: renamed from: b () void
   public final void method_903() {
      if (this.field_1407 != null) {
         this.field_1407.method_261();
      }

      this.field_1407 = null;
      if (this.field_1424 != null) {
         this.field_1424.method_350();
      }

      this.field_1424 = null;
      this.field_1408 = null;
      if (this.field_1419 != null) {
         this.field_1419.method_561();
      }

      this.field_1419 = null;
      if (this.field_1421 != null) {
         this.field_1421.method_457();
      }

      this.field_1421 = null;
      if (this.field_1422 != null) {
         this.field_1422.method_417();
      }

      this.field_1422 = null;
      class_4.method_153();
      if (this.field_1423 != null) {
         this.field_1423.method_624();
      }

      this.field_1410.method_609(null);
      this.field_1410.method_610(null);
      this.field_1409 = null;
      this.field_1408 = null;
      this.field_1423 = null;
      this.field_1420 = null;
      this.field_1406 = false;
      this.field_1427 = null;
      ;
   }

   // $VF: renamed from: a () void
   public final void method_902() {
      if (this.field_1419 == null) {
         this.field_1419 = new class_57();
      }

      if (this.field_1419.method_530()) {
         this.method_906();
         class_4.method_152();
         this.field_1417 = this.field_1419.field_793;
         class_41.field_539.method_430();
         if (class_3.field_63 >= 0) {
            this.field_1407.field_202.method_806(class_3.field_63);
         }

         if (class_3.field_61 >= 0) {
            this.field_1407.field_202.method_807(class_3.field_61);
         }

         if (class_3.field_62 >= 0) {
            this.field_1407.field_202.method_808(class_3.field_62);
         }

         this.field_1407.method_230();
         class_3.field_63 = class_3.method_108().field_423;
         class_3.field_61 = class_3.method_108().field_430;
         class_3.field_62 = class_3.method_108().field_431;
         this.field_1437 = false;
         this.field_1431 = false;
         this.field_1433 = false;
         this.field_1434 = false;
         int var1;
         if ((var1 = class_3.method_108().field_450) >= 0 && this.field_1407.field_202.field_1252 != null) {
            if (var1 >= this.field_1407.field_202.field_1252.length) {
               var1 = 0;
            }

            while (var1 != this.field_1407.field_220) {
               this.field_1407.method_242();
            }
         }

         class_69.method_673(false);
         class_4.method_155(-1, -1, "");
         ;
         this.field_1399 = System.currentTimeMillis();
         this.field_1400 = System.currentTimeMillis();
         this.field_1404 = 0L;
         this.field_1405 = 0L;
         this.field_1406 = true;
      }
   }

   // $VF: renamed from: e () void
   private void method_906() {
      this.field_1407 = this.field_1419.field_774;
      this.field_1422 = new class_42();
      this.field_1422.method_418(this.field_1419.field_782);
      this.field_1408 = class_111.method_899(class_41.field_537, class_41.field_538, 500, 100, 31768);
      this.field_1409 = new class_99();
      this.field_1409.method_875(this.field_1408);
      class_41.field_527.method_264(this.field_1408);
      this.field_1410 = new class_65(this.field_1407.field_203, this.field_1408);
      this.field_1411 = new class_71(this.field_1407.field_203, this.field_1408);
      this.field_1411.field_1039 = false;
      this.field_1409.method_876(this.field_1411);
      this.field_1409.method_876(this.field_1410);
      this.field_1421 = new class_47(this.field_1419);
      this.field_1417 = this.field_1419.field_793;
      class_4.method_159(null);
      this.field_1420 = new class_64(this.field_1410, this.field_1411, this.field_1419);
      class_64.method_605(this.field_1410, this.field_1419);
      this.field_1412 = false;
      this.field_1416 = false;
      this.field_1398 = 0;
      this.field_1413 = false;
      this.field_1415 = false;
      this.field_1404 = 0L;
      this.field_1405 = 0L;
      this.field_1432 = false;
      this.field_1429 = false;
      this.field_1430 = false;
      this.field_1435 = false;
      this.field_1399 = System.currentTimeMillis();
      this.field_1400 = System.currentTimeMillis();
   }

   // $VF: renamed from: a () boolean
   public final boolean method_904() {
      return this.field_1406;
   }

   // $VF: renamed from: b (int) void
   public final void method_900(int var1) {
      try {
         if (this.field_1406) {
            this.field_1399 = System.currentTimeMillis();
            this.field_1401 = this.field_1399 - this.field_1400;
            this.field_1400 = this.field_1399;
            this.field_1403 = this.field_1403 + this.field_1401;
            this.field_1402 = this.field_1402 + this.field_1401;
            if (!this.field_1413) {
               this.field_1404 = this.field_1404 + this.field_1401;
               if (!this.field_1415) {
                  this.field_1405 = this.field_1405 + this.field_1401;
               }

               class_3.method_141(this.field_1401);
               class_69.method_655((int)this.field_1401);
            }

            if (!this.field_1416) {
               if (this.field_1413) {
                  if (!this.field_1414 && !this.field_1432 && !this.field_1429 && !this.field_1430 && !this.field_1437) {
                     this.field_1423.method_625(var1, (int)this.field_1401);
                     if (this.field_1402 > 150L) {
                        this.field_1402 = 0L;
                        if ((var1 & 2) != 0) {
                           this.field_1423.method_627((int)this.field_1401);
                        }

                        if ((var1 & 64) != 0) {
                           this.field_1423.method_628((int)this.field_1401);
                        }
                     }
                  }

                  if (!this.field_1406) {
                     return;
                  }

                  this.field_1419.method_556(this.field_1401);
                  this.field_1407.method_262(!this.field_1415);
                  class_41.field_528.method_333(class_41.field_534);
                  class_41.field_527.method_266();
                  class_41.field_528.method_334(class_41.field_534);
                  if (this.field_1432) {
                     this.field_1427.method_393();
                     return;
                  }

                  if (!this.field_1429 && !this.field_1430) {
                     if (this.field_1437) {
                        this.field_1425.method_352(var1, (int)this.field_1401);
                        if (this.field_1431) {
                           this.field_1426.method_645(0, (int)this.field_1401);
                        }

                        this.field_1425.method_360();
                        return;
                     }

                     if (this.field_1414) {
                        class_69.method_655((int)this.field_1401);
                        this.field_1424.method_352(var1, (int)this.field_1401);
                        this.field_1424.method_359();
                        return;
                     }

                     this.field_1423.method_636();
                     return;
                  }

                  this.field_1428.method_518();
                  return;
               }

               if ((this.field_1420.field_864 || !this.field_1420.field_863)
                  && !this.field_1429
                  && !this.field_1430
                  && this.method_912(var1, (int)this.field_1401)) {
                  return;
               }

               if (!class_41.field_521
                  && class_3.method_73() > 14
                  && this.field_1404 > 20000L
                  && !class_3.method_108().method_365()
                  && this.field_1419.field_775 == null) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(347));
                  }

                  this.field_1437 = true;
                  class_41.field_521 = true;
               }

               if (!class_41.field_516 && this.field_1407.field_237 < class_3.method_108().field_448) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(344));
                  }

                  this.field_1437 = true;
                  class_41.field_516 = true;
               }

               if (!class_41.field_517 && this.field_1407.field_237 > class_3.method_108().field_449) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(345));
                  }

                  this.field_1437 = true;
                  class_41.field_517 = true;
               }

               if (!class_41.field_518 && class_3.method_102() == 1) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(348));
                  }

                  this.field_1437 = true;
                  class_41.field_518 = true;
               }

               if (!class_41.field_519 && class_4.method_162() && class_3.method_73() != 7 && class_3.method_110().field_828 != 1) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(349));
                  }

                  this.field_1437 = true;
                  class_41.field_519 = true;
               }

               if (this.field_1405 > 3000L && !this.field_1414 && !class_3.method_62().field_1242 && !class_3.method_62().field_1243) {
                  this.method_911();
               }
            }

            if (this.field_1407.field_227) {
               this.field_1418 = 500 + (int)(this.field_1407.method_233() * 400.0F);
               this.field_1408.method_896(this.field_1418);
            }

            if (class_3.method_62().field_1242 || this.field_1416 || !this.method_910()) {
               if (!this.field_1416) {
                  this.method_909();
               }

               this.field_1415 = this.field_1420.method_602((int)this.field_1401, this.field_1410, this.field_1427);
               this.method_907();
               this.method_908();
               if (!this.field_1416 && !this.field_1415) {
                  if (this.field_1407.field_220 >= 0 && this.field_1412 && !this.field_1407.method_243()) {
                     this.field_1407.method_237(this.field_1401);
                  }

                  // Deep3D-PC: analogue stick steering overrides the digital
                  // direction bits while the stick is deflected.
                  if (org.deep3d.AnalogInput.active()) {
                     var1 &= ~(2 | 4 | 32 | 64);
                     float var90 = -org.deep3d.AnalogInput.x();
                     float var91 = -org.deep3d.AnalogInput.y();
                     if (this.field_1407.field_240) {
                        class_4.method_154(7, this.field_1407);
                     } else {
                        this.field_1407.steerAnalog(this.field_1401, var90,
                              class_41.field_499 ? var91 : -var91);
                     }
                  }

                  if ((var1 & 4) != 0) {
                     if (this.field_1407.field_240) {
                        class_4.method_154(7, this.field_1407);
                     } else {
                        this.field_1407.method_254(this.field_1401);
                     }
                  }

                  if ((var1 & 32) != 0) {
                     if (this.field_1407.field_240) {
                        class_4.method_154(7, this.field_1407);
                     } else {
                        this.field_1407.method_255(this.field_1401);
                     }
                  }

                  if ((var1 & 2) != 0) {
                     if (this.field_1407.field_240) {
                        class_4.method_154(7, this.field_1407);
                     } else if (class_41.field_499) {
                        this.field_1407.method_256(this.field_1401);
                     } else {
                        this.field_1407.method_257(this.field_1401);
                     }
                  }

                  if ((var1 & 64) != 0) {
                     if (this.field_1407.field_240) {
                        class_4.method_154(7, this.field_1407);
                     } else if (class_41.field_499) {
                        this.field_1407.method_257(this.field_1401);
                     } else {
                        this.field_1407.method_256(this.field_1401);
                     }
                  }

                  if ((var1 & 256) != 0) {
                     this.field_1407.method_237(this.field_1401);
                  }
               }

               if (this.field_1420.field_863 && class_3.method_73() == 1) {
                  if (this.field_1403 > 68000L) {
                     this.field_1403 = 0L;
                  } else if (this.field_1403 > 8750L && this.field_1436 == 2) {
                     this.field_1436++;
                     class_41.field_539.method_425(0);
                  } else if (this.field_1403 > 3500L && this.field_1436 == 0 || this.field_1403 > 7000L && this.field_1436 == 1) {
                     this.field_1436++;
                     class_41.field_539.method_427(0);
                  }
               } else if (this.field_1403 > 10000L) {
                  class_41.field_539
                     .method_426(
                        class_43.field_554[class_41.field_540.nextInt(class_43.field_554.length)],
                        class_124.method_942(60, class_41.field_540.nextInt(class_41.field_539.field_562))
                     );
                  this.field_1403 = 0L;
               }
            }
         }
      } catch (Exception var3) {
         var3.printStackTrace();
      }
   }

   // $VF: renamed from: f () void
   private void method_907() {
      try {
         this.field_1419.method_557(this.field_1401);
         this.field_1419.method_555(this.field_1401);
         this.field_1407.method_252(this.field_1401);
         this.field_1407.method_262(!this.field_1415);
         class_41.field_528.method_333(class_41.field_534);
         this.field_1409.method_835(true);
         class_41.field_527.method_267(System.currentTimeMillis());
         class_41.field_528.method_334(class_41.field_534);
      } catch (Exception var2) {
         class_41.field_528.method_334(class_41.field_534);
         var2.printStackTrace();
      }
   }

   // $VF: renamed from: g () void
   private void method_908() {
      if (this.field_1415) {
         if (class_3.method_73() > 1 && !this.field_1420.field_873) {
            class_41.field_530.method_786();
         } else {
            class_4.method_167();
         }

         class_4.method_168();
         if (!this.field_1420.field_873) {
            class_4.method_163(this.field_1401, this.field_1407, true);
         }
      } else if (this.field_1416) {
         class_50.method_483(class_41.field_533.method_297(139), class_41.field_537 / 2, 20, 0, 8);
         if (this.field_1405 > 3000L) {
            this.field_1428.method_518();
         }
      } else {
         this.field_1407.method_263(!this.field_1415, this.field_1408);
         this.field_1421.method_459(this.field_1407.field_202, this.field_1408);
         class_4.method_165(this.field_1413 ? 0L : this.field_1401, this.field_1417 - this.field_1404, this.field_1407, this.field_1412);
      }

      if (!this.field_1416) {
         this.field_1422.method_421(this.field_1404, this.field_1407);
      }
   }

   // $VF: renamed from: h () void
   private void method_909() {
      if (this.field_1407.method_240() <= 0) {
         this.field_1416 = true;
         class_41.field_533.method_297(139);
      }

      if (this.field_1419.method_560((int)this.field_1401)) {
         if (this.field_1424 == null) {
            this.field_1424 = new class_30();
         }

         this.field_1424.method_349(class_3.method_62(), 2);
         this.field_1414 = true;
         this.field_1413 = true;
      }

      if (this.field_1405 > 3000L) {
         this.field_1405 = 0L;
         if (this.field_1417 > 0 && this.field_1404 > this.field_1417 && !this.field_1419.field_791.method_228()) {
            if (this.field_1424 == null) {
               this.field_1424 = new class_30();
            }

            this.field_1424.method_349(class_3.method_62(), 2);
            this.field_1414 = true;
            this.field_1413 = true;
         }
      }

      if (this.field_1416) {
         this.field_1405 = 0L;
         this.field_1410.method_612();
         class_41.method_415(0);
         if (this.field_1428 == null) {
            this.field_1428 = new class_53();
         }

         this.field_1428.method_514(class_41.field_533.method_297(276), true);
      }
   }

   // $VF: renamed from: b () boolean
   private boolean method_910() {
      if (this.field_1405 > 3000L) {
         class_95 var1 = class_3.method_78(false, this.field_1404);
         if (this.field_1419.method_558((int)this.field_1404) || var1 != null) {
            if (class_3.method_62().field_1241 && class_3.method_73() == 27) {
               class_3.method_75();
               this.field_1419.method_559();
               class_3.method_63(class_95.field_1225);
            } else {
               if (!class_3.method_62().field_1241) {
                  class_3.method_71();
               }

               if (class_3.method_62().field_1241 && (!class_3.method_62().field_1241 || !class_30.method_348(class_3.method_73()))) {
                  return false;
               }

               if (this.field_1424 == null) {
                  this.field_1424 = new class_30();
               }

               this.field_1424.method_349(var1 != null ? var1 : class_3.method_62(), 1);
               this.field_1414 = true;
               this.field_1413 = true;
            }

            return true;
         }
      }

      return false;
   }

   // $VF: renamed from: c () void
   public final void method_911() {
      if ((
            !this.field_1420.field_864
               || !class_30.method_347(class_3.method_73()) && class_3.method_62().field_1241
               || class_3.method_62().method_789()
               || class_3.method_62().field_1226 == 13
               || class_3.method_62().field_1226 == 14
               || !class_3.method_62().field_1251
         )
         && !class_3.method_69()) {
         if (class_3.method_62().field_1241 && class_3.method_73() == 27 && !this.field_1435 && this.field_1419.field_775[0].field_1102.field_1268) {
            this.field_1424 = new class_30(class_3.method_62(), 3);
            this.field_1413 = true;
            this.field_1414 = true;
            this.field_1435 = true;
         }
      } else if (class_3.method_62().field_1241 || class_3.method_62().field_1226 != 8) {
         if (this.field_1424 == null) {
            if (class_3.method_69()) {
               this.field_1424 = new class_30(class_3.method_65(), 2);
            } else {
               this.field_1424 = new class_30(class_3.method_62(), 0);
            }
         }

         this.field_1413 = true;
         this.field_1414 = true;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_912(int var1, int var2) {
      this.field_1433 = this.field_1419.method_553(this.field_1407.method_245());
      this.field_1434 = this.field_1419.method_554(this.field_1407.method_245());
      if (!class_3.method_62().method_789() && class_3.method_62().field_1226 != 8) {
         if (!this.field_1434 && !this.field_1433) {
            class_4.method_159(null);
         } else {
            class_4.method_159(class_41.field_533.method_297(269));
         }

         return false;
      } else {
         if (this.field_1433 && ((class_91)this.field_1419.field_778[1]).field_1200) {
            class_3.field_63 = this.field_1407.field_202.field_1256;
            class_3.field_61 = this.field_1407.field_202.field_1258;
            class_3.field_62 = this.field_1407.field_202.field_1260;
            if (this.field_1407.field_240 && class_57.field_804 != null) {
               if (!this.field_1429) {
                  if (this.field_1428 == null) {
                     this.field_1428 = new class_53();
                  }

                  this.field_1428
                     .method_514(class_41.field_533.method_297(334) + ": " + class_57.field_804.field_827 + "\n" + class_41.field_533.method_297(247), true);
                  this.field_1428.method_516();
                  this.field_1429 = true;
                  this.field_1413 = true;
                  this.field_1407.method_248(null);
               }

               return false;
            }

            if (this.field_1431) {
               if (!class_41.field_506 && !this.field_1426.method_644()) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(361));
                  }

                  this.field_1437 = true;
                  class_41.field_506 = true;
               } else if (!class_41.field_507 && this.field_1426.method_644()) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(362));
                  }

                  this.field_1437 = true;
                  class_41.field_507 = true;
               }

               this.field_1431 = this.field_1426.method_645(var1, var2);
               this.field_1402 = 0L;
               return true;
            }

            if (!this.field_1407.field_240 && class_3.method_73() > 2 && (class_3.method_73() != 6 || class_3.method_110().field_828 != 0)) {
               class_4.method_159(class_41.field_533.method_297(270));
               if (!class_41.field_514) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(342));
                  }

                  this.field_1437 = true;
                  class_41.field_514 = true;
               }
            }

            if ((var1 & 131072) != 0 || this.field_1407.method_249()) {
               if (class_57.field_804 != null) {
                  if (!this.field_1429) {
                     if (this.field_1428 == null) {
                        this.field_1428 = new class_53();
                     }

                     this.field_1428
                        .method_514(class_41.field_533.method_297(334) + ": " + class_57.field_804.field_827 + "\n" + class_41.field_533.method_297(247), true);
                     this.field_1428.method_516();
                     this.field_1429 = true;
                     this.field_1413 = true;
                     this.field_1407.method_248(null);
                  }

                  return false;
               }

               if (class_3.method_73() != 1 && class_3.method_73() != 2 && (class_3.method_73() != 6 || class_3.method_110().field_828 != 0)) {
                  if (this.field_1426 == null) {
                     this.field_1426 = new class_68();
                  }

                  this.field_1426.method_641();
                  this.field_1426.method_640(null);
                  this.field_1426.field_988 = true;
                  this.field_1407.method_248(null);
                  this.field_1431 = true;
                  return true;
               }

               this.field_1425 = new class_30(class_41.field_533.method_297(291));
               this.field_1407.method_248(null);
               this.field_1437 = true;
               this.field_1413 = true;
            }
         } else if (this.field_1434) {
            if (!this.field_1407.field_240) {
               class_4.method_159(class_41.field_533.method_297(271));
               if (!class_41.field_515 && this.field_1404 > 20000L) {
                  this.field_1413 = true;
                  if (this.field_1425 == null) {
                     this.field_1425 = new class_30(class_41.field_533.method_297(343));
                  }

                  this.field_1437 = true;
                  class_41.field_515 = true;
               }
            }

            if (this.field_1407.method_250()) {
               if ((class_3.method_73() != 5 || class_3.method_110().field_828 != 0) && (class_3.method_73() != 6 || class_3.method_110().field_828 == 0)) {
                  class_58.method_562(this.field_1407);
                  class_41.field_543.method_213(class_41.field_544[1]);
                  return true;
               }

               this.field_1425 = new class_30(class_41.field_533.method_297(class_3.method_73() == 5 ? 292 : 291));
               this.field_1437 = true;
               this.field_1413 = true;
               this.field_1407.method_248(null);
            }

            if ((var1 & 131072) != 0 && !this.field_1407.method_249()) {
               if (!this.field_1430) {
                  if (this.field_1428 == null) {
                     this.field_1428 = new class_53();
                  }

                  this.field_1428.method_514(class_3.method_149(class_41.field_533.method_297(272), class_3.method_110().field_827), true);
                  this.field_1428.method_516();
                  this.field_1430 = true;
                  this.field_1413 = true;
               }

               return false;
            }
         } else {
            class_4.method_159(null);
         }

         return false;
      }
   }

   // $VF: renamed from: d () void
   public final void method_913() {
      if (!this.field_1413) {
         if (this.field_1423 == null) {
            this.field_1423 = new class_67();
         }

         this.field_1423.method_635();
         this.field_1413 = true;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_901(int var1) {
      if (this.field_1406) {
         if (this.field_1413) {
            if (this.field_1437 && var1 == 256) {
               this.field_1437 = false;
               this.field_1413 = false;
               this.field_1425 = null;
               this.field_1407.method_260();
               return;
            }

            if (this.field_1414) {
               if (!this.field_1424.method_351(var1)) {
                  this.field_1413 = false;
                  this.field_1414 = false;
                  if (class_3.method_69()) {
                     class_3.method_66(class_95.field_1225);
                  } else if (class_3.method_62().field_1242) {
                     if (class_3.method_62().field_1241) {
                        class_41.field_543.method_213(class_41.field_544[0]);
                        class_41.field_539.method_425(0);
                        class_3.method_151();
                        return;
                     }

                     class_3.method_66(class_95.field_1225);
                     this.field_1419.method_559();
                     this.field_1417 = 0;
                     class_3.method_63(class_95.field_1225);
                     this.field_1407.field_215 = null;
                     if (this.field_1407.field_242) {
                        this.field_1407.method_248(null);
                     }

                     this.field_1407.method_235();
                     this.field_1419.field_779 = null;
                     this.field_1427 = new class_33(this.field_1419);
                  } else if (!class_3.method_62().field_1243 && !class_3.method_67().field_1243) {
                     this.field_1420.method_604();
                  } else {
                     boolean var2 = class_3.method_67().field_1243 && !class_3.method_62().field_1241;
                     class_95 var3;
                     if ((var3 = class_3.method_62().field_1243 ? class_3.method_62() : class_3.method_67()).field_1237) {
                        class_41.field_543.method_213(class_41.field_544[0]);
                        class_41.field_539.method_425(0);
                        return;
                     }

                     if (var3.field_1241) {
                        class_3.method_75();
                     } else {
                        class_3.method_66(class_95.field_1225);
                     }

                     class_3.method_127(var3.field_1230);
                     class_4.method_160(var3.field_1230);
                     this.field_1417 = 0;
                     if (!var2) {
                        this.field_1419.method_559();
                        class_3.method_63(class_95.field_1225);
                        this.field_1407.field_215 = null;
                        if (this.field_1407.field_242) {
                           this.field_1407.method_248(null);
                        }

                        this.field_1407.method_235();
                        this.field_1419.field_779 = null;
                        this.field_1427 = new class_33(this.field_1419);
                     }
                  }

                  this.field_1402 = 0L;
                  return;
               }
            } else {
               if (this.field_1432) {
                  if (var1 == 1024) {
                     this.field_1432 = false;
                     this.field_1413 = false;
                  }

                  if (var1 == 2 && this.field_1432) {
                     this.field_1427.method_391();
                  }

                  if (var1 == 64 && this.field_1432) {
                     this.field_1427.method_392();
                  }

                  if (var1 == 256 && this.field_1432) {
                     this.field_1432 = false;
                     class_4.method_159(null);
                     class_4.method_154(5, this.field_1407);
                     if (this.field_1407 != null) {
                        this.field_1407.method_260();
                     }

                     this.field_1413 = false;
                     int var4 = this.field_1427.field_452;
                     switch (this.field_1427.field_452) {
                        case 0:
                           this.field_1407.method_248(this.field_1419.field_778[1]);
                           return;
                        case 1:
                           this.field_1407.method_248(this.field_1419.field_778[0]);
                           return;
                        case 2:
                           if (this.field_1419.field_779 != null) {
                              this.field_1407.method_248(this.field_1419.field_779.method_219());
                           }
                     }
                  }

                  return;
               }

               if (this.field_1429) {
                  if (var1 == 256) {
                     this.field_1429 = false;
                     if (class_3.method_73() != 1 && class_3.method_73() != 2 && (class_3.method_73() != 6 || class_3.method_110().field_828 != 0)) {
                        if (this.field_1428.method_515()) {
                           if (class_3.method_73() == 5) {
                              class_3.method_67().method_794(class_57.field_804.field_828);
                           }

                           class_3.method_61(class_57.field_804);
                           class_57.method_529();
                           class_57.field_804 = null;
                           class_4.method_160(0);
                           class_41.field_543.method_213(class_41.field_544[2]);
                           class_3.method_80();
                        } else {
                           if (this.field_1426 == null) {
                              this.field_1426 = new class_68();
                           }

                           this.field_1426.method_641();
                           this.field_1426.method_640(null);
                           this.field_1426.field_988 = true;
                           this.field_1431 = true;
                           this.field_1413 = false;
                        }
                     } else {
                        this.field_1425 = new class_30(class_41.field_533.method_297(291));
                        this.field_1437 = true;
                        this.field_1413 = true;
                     }
                  }

                  if (var1 == 4) {
                     this.field_1428.method_516();
                  }

                  if (var1 == 32) {
                     this.field_1428.method_517();
                     return;
                  }
               } else if (this.field_1430) {
                  if (var1 == 256) {
                     this.field_1430 = false;
                     if (!this.field_1428.method_515()) {
                        this.field_1413 = false;
                     } else if (class_3.method_73() == 5 && class_3.method_110().field_828 == 0
                        || class_3.method_73() == 6 && class_3.method_110().field_828 != 0) {
                        this.field_1425 = new class_30(class_41.field_533.method_297(class_3.method_73() == 5 ? 292 : 291));
                        this.field_1437 = true;
                        this.field_1413 = true;
                     } else {
                        class_58.method_562(this.field_1407);
                        class_41.field_543.method_213(class_41.field_544[1]);
                     }
                  }

                  if (var1 == 4) {
                     this.field_1428.method_516();
                  }

                  if (var1 == 32) {
                     this.field_1428.method_517();
                     return;
                  }
               } else if (this.field_1423 != null) {
                  this.field_1423.method_637(var1);
                  if (var1 == 256 && this.field_1423.method_626()) {
                     this.field_1413 = false;
                     return;
                  }

                  if (var1 == 16384 && this.field_1423.method_633()) {
                     this.field_1413 = false;
                  }

                  if (var1 == 8192 && this.field_1423.method_632()) {
                     this.field_1413 = false;
                  }

                  if (var1 == 4) {
                     this.field_1423.method_629();
                  }

                  if (var1 == 32) {
                     this.field_1423.method_631();
                     return;
                  }
               }
            }
         } else {
            if (this.field_1431) {
               this.field_1431 = this.field_1426.method_642(var1);
               return;
            }

            if (!this.field_1416) {
               if (var1 == 16384) {
                  if (this.field_1423 == null) {
                     this.field_1423 = new class_67();
                  }

                  this.field_1423.method_635();
                  this.field_1413 = !this.field_1413;
                  if (this.field_1413) {
                     return;
                  }
               }

               if (!this.field_1415) {
                  if (var1 == 4096) {
                     if (this.field_1398 != 2) {
                        class_64.method_607(this.field_1410);
                        this.field_1398 = 2;
                     } else {
                        class_64.method_605(this.field_1410, this.field_1419);
                        this.field_1398 = 0;
                     }
                  }

                  if (var1 == 131072) {
                     if (this.field_1398 != 1) {
                        class_64.method_606(this.field_1410);
                        this.field_1398 = 1;
                     } else {
                        class_64.method_605(this.field_1410, this.field_1419);
                        this.field_1398 = 0;
                     }
                  }

                  if (var1 == 2048) {
                     if (this.field_1398 != 3) {
                        class_64.method_608(this.field_1410);
                        this.field_1398 = 3;
                     } else {
                        class_64.method_605(this.field_1410, this.field_1419);
                        this.field_1398 = 0;
                     }
                  }

                  if (var1 == 65536 && !this.field_1407.field_227) {
                     this.field_1407.method_231();
                     class_4.method_154(3, this.field_1407);
                  }

                  if (var1 == 32768 && this.field_1407.field_220 != -1) {
                     this.field_1407.method_242();
                     class_4.method_154(0, this.field_1407);
                  }

                  if (var1 == 512) {
                     this.field_1412 = !this.field_1412;
                     class_4.method_154(this.field_1412 ? 1 : 2, this.field_1407);
                  }

                  if (var1 == 1024) {
                     if (this.field_1407.field_240) {
                        this.field_1407.method_248(null);
                        class_4.method_154(6, this.field_1407);
                        return;
                     }

                     if (!this.field_1432) {
                        if (this.field_1427 == null || this.field_1419.field_779 != null && this.field_1419.field_779.method_220().field_1164) {
                           this.field_1427 = new class_33(this.field_1419);
                        }

                        this.field_1432 = true;
                        this.field_1413 = true;
                        return;
                     }
                  }
               } else {
                  if (var1 == 256) {
                     this.field_1420.method_603();
                     this.field_1407.method_260();
                  }

                  if (var1 == 65536 && !this.field_1407.field_227) {
                     this.field_1407.method_231();
                     class_4.method_154(3, this.field_1407);
                     return;
                  }
               }
            } else if (this.field_1405 > 3000L) {
               if (class_3.method_107() == 0) {
                  class_41.field_543.method_213(class_41.field_544[0]);
                  class_41.field_539.method_425(0);
                  return;
               }

               if (var1 == 32) {
                  this.field_1428.method_517();
                  return;
               }

               if (var1 == 4) {
                  this.field_1428.method_516();
                  return;
               }

               if (var1 == 256) {
                  if (this.field_1428.method_515()) {
                     class_45[] var5;
                     (var5 = class_81.method_728())[var5.length - 1].method_441();
                     ((class_118)class_41.field_544[1]).method_919();
                     class_41.field_543.method_213(class_41.field_544[1]);
                     return;
                  }

                  class_41.field_543.method_213(class_41.field_544[0]);
                  class_41.field_539.method_425(0);
                  return;
               }
            }
         }
      }
   }
}
