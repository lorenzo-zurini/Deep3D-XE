import javax.microedition.lcdui.Image;

// $VF: renamed from: ch
public final class class_118 extends class_113 {
   // $VF: renamed from: a long
   private long field_1457;
   // $VF: renamed from: b long
   private long field_1458;
   // $VF: renamed from: c long
   private long field_1459;
   // $VF: renamed from: d long
   private long field_1460;
   // $VF: renamed from: e long
   private long field_1461;
   // $VF: renamed from: a int
   private int field_1462;
   // $VF: renamed from: a int[]
   private int[] field_1463;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_1464;
   // $VF: renamed from: a bk
   public class_117 field_1465;
   // $VF: renamed from: a bu
   private class_67 field_1466;
   // $VF: renamed from: a boolean
   private boolean field_1467;
   // $VF: renamed from: b boolean
   private boolean field_1468;
   // $VF: renamed from: c boolean
   private boolean field_1469;
   // $VF: renamed from: d boolean
   private boolean field_1470;
   // $VF: renamed from: e boolean
   private boolean field_1471;
   // $VF: renamed from: f boolean
   private boolean field_1472;
   // $VF: renamed from: g boolean
   private boolean field_1473;
   // $VF: renamed from: h boolean
   private boolean field_1474;
   // $VF: renamed from: i boolean
   private boolean field_1475;
   // $VF: renamed from: j boolean
   private boolean field_1476;
   // $VF: renamed from: k boolean
   private boolean field_1477;
   // $VF: renamed from: l boolean
   private boolean field_1478;
   // $VF: renamed from: a z
   private class_53 field_1479;
   // $VF: renamed from: a cn
   private class_23 field_1480;
   // $VF: renamed from: a ai
   private class_62 field_1481;
   // $VF: renamed from: a bp
   public class_68 field_1482;
   // $VF: renamed from: a ds
   private class_49 field_1483;
   // $VF: renamed from: a bv
   private class_11 field_1484;
   // $VF: renamed from: a bo
   private class_30 field_1485;
   // $VF: renamed from: b bo
   private class_30 field_1486;
   // $VF: renamed from: a i
   private class_80 field_1487;
   // $VF: renamed from: a y
   private class_14 field_1488;
   // $VF: renamed from: a al
   private class_95 field_1489;
   // $VF: renamed from: b int
   private int field_1490;
   // $VF: renamed from: c int
   private int field_1491;
   // $VF: renamed from: d int
   private int field_1492;
   // $VF: renamed from: m boolean
   private boolean field_1493 = false;
   // $VF: renamed from: n boolean
   private boolean field_1494 = false;
   // $VF: renamed from: o boolean
   private boolean field_1495;
   // $VF: renamed from: e int
   private int field_1496;
   // $VF: renamed from: a int[][]
   private int[][] field_1497;
   // $VF: renamed from: f int
   private int field_1498;
   // $VF: renamed from: p boolean
   private boolean field_1499;
   // $VF: renamed from: q boolean
   private boolean field_1500;
   // $VF: renamed from: g int
   private int field_1501;
   // $VF: renamed from: r boolean
   private boolean field_1502;

   // $VF: renamed from: b () void
   public final void method_903() {
      this.field_1481.method_594();
      this.field_1481 = null;
      this.field_1482.method_638();
      this.field_1482 = null;
      this.field_1483.method_473();
      this.field_1483 = null;
      this.field_1463 = null;
      this.field_1466.method_624();
      this.field_1466 = null;
      this.field_1480.method_300();
      this.field_1480 = null;
      this.field_1479 = null;
      if (this.field_1465 != null) {
         this.field_1465.method_903();
      }

      this.field_1465 = null;
      this.field_1502 = false;
      this.field_1464 = null;
      System.gc();
   }

   // $VF: renamed from: c () void
   public final void method_919() {
      this.field_1493 = true;
   }

   // $VF: renamed from: a () void
   public final void method_902() {
      if (this.field_1465 == null) {
         this.field_1499 = false;
         if (!class_44.method_433()[class_3.method_110().field_828]) {
            this.field_1499 = true;
         }

         this.field_1501 = class_3.method_110().method_592() ? 100 : 50;
         long var1 = class_3.field_64;
         class_3.method_61(class_3.method_110());
         if (class_3.method_142() - var1 > 30000L) {
            class_9.method_200(class_3.method_110());
         }

         class_3.method_110().method_586();
         class_48.method_467();
         this.field_1465 = new class_117(0);
      }

      if (!this.field_1465.field_1443) {
         this.field_1465.method_902();
      } else {
         class_58.method_579();
         if (this.field_1466 == null) {
            this.field_1466 = new class_67();
         }

         this.field_1468 = false;
         if (this.field_1480 == null) {
            this.field_1480 = new class_23();
         } else {
            this.field_1470 = false;
            if (this.field_1481 == null) {
               this.field_1481 = new class_62();
               this.field_1481.method_595();
            } else {
               this.field_1471 = false;
               if (this.field_1482 == null) {
                  this.field_1482 = new class_68();
                  this.field_1482.method_641();
               } else {
                  this.field_1472 = false;
                  this.field_1467 = true;
                  this.field_1484 = new class_11();
                  this.field_1474 = false;
                  this.field_1487 = new class_80();
                  this.field_1476 = false;
                  this.field_1478 = false;
                  this.field_1463 = new int[7];

                  for (int var3 = 0; var3 < this.field_1463.length; var3++) {
                     this.field_1463[var3] = 0;
                     if (var3 == this.field_1462) {
                        this.field_1463[var3] = 1;
                     }
                  }

                  this.field_1490 = 1;
                  this.field_1491 = class_41.field_538 - 32 - this.field_1463.length * 10;
                  this.field_1492 = 60;
                  this.field_1496 = 0;
                  this.field_1494 = false;
                  this.field_1495 = false;
                  this.field_1461 = 0L;
                  this.field_1479 = new class_53(20, class_41.field_538 / 2, class_41.field_537 - 40);
                  this.field_1464 = class_40.method_412(
                     "/data/interface/logo_" + (class_58.method_565() ? 2 : (class_3.method_110().method_592() ? 0 : 1)) + ".png"
                  );
                  if (!this.field_1493) {
                     this.method_921();
                     if (class_3.method_110().method_592()) {
                        this.field_1496 = class_3.method_108().method_380();
                        if (this.field_1496 > 0) {
                           this.method_920(class_41.field_533.method_297(257) + "      " + this.field_1496 + " $");
                        }
                     } else if (class_3.method_73() == 12 && class_3.method_110().field_828 == 3) {
                        this.method_920(class_41.field_533.method_297(258));
                     }

                     if (class_3.method_73() == 2) {
                        class_3.method_110().field_835 = new class_51[]{class_24.method_311()[0].method_505()};
                        this.field_1481.method_595();
                     }

                     if ((class_3.method_73() == 33 || class_3.method_73() == 34) && class_3.method_110().field_828 == class_3.method_67().field_1232) {
                        if (!class_46.method_450(37, class_3.method_110().field_836)) {
                           class_3.method_110().field_836 = class_46.method_454(
                              class_3.method_110().field_836, new class_46[]{class_24.method_315()[37].method_447(1)}
                           );
                        }
                     } else if ((class_3.method_73() == 36 || class_3.method_73() == 37) && class_3.method_110().field_828 == class_3.method_67().field_1232) {
                        if (!class_46.method_450(38, class_3.method_110().field_836)) {
                           class_3.method_110().field_836 = class_46.method_454(
                              class_3.method_110().field_836, new class_46[]{class_24.method_315()[38].method_447(1)}
                           );
                        }
                     } else if ((class_3.method_73() == 41 && class_46.method_450(36, class_3.method_108().field_445) || class_3.method_73() == 42)
                        && class_3.method_110().field_828 == 14
                        && !class_3.method_108().method_369(42)
                        && !class_3.method_110().method_587(42)) {
                        class_3.method_110().method_588(class_24.method_311()[42].method_505());
                        this.field_1481.method_595();
                     }
                  }

                  if (!this.field_1494 && !this.field_1493) {
                     class_3.method_127(this.field_1496);
                     class_81.method_733(3);
                     class_3.method_127(-this.field_1496);
                     this.field_1494 = true;
                  }

                  if (this.field_1483 == null) {
                     this.field_1483 = new class_49();
                     this.field_1483.method_474();
                  }

                  this.field_1473 = false;
                  class_41.field_539.method_425(1);
                  this.field_1460 = 0L;
                  class_48.method_466();
                  System.gc();
                  this.field_1457 = System.currentTimeMillis();
                  this.field_1458 = System.currentTimeMillis();
                  this.field_1502 = true;
                  class_69.method_654(!class_3.method_110().method_592());
               }
            }
         }
      }
   }

   // $VF: renamed from: a (java.lang.String) void
   private void method_920(String var1) {
      this.field_1479.method_513(var1);
      this.field_1469 = true;
   }

   // $VF: renamed from: e () void
   private void method_921() {
      if (!this.field_1477 && !this.field_1478) {
         this.field_1497 = (int[][])null;
         int[] var1 = class_58.method_567();
         int var2 = 0;

         for (int var3 = 0; var3 < var1.length; var3++) {
            if (var1[var3] > 0) {
               var2++;
            }
         }

         if (var2 > 0) {
            this.field_1497 = new int[var2][2];
            var2 = 0;

            for (int var5 = 0; var5 < var1.length; var5++) {
               if (var1[var5] > 0) {
                  this.field_1497[var2++] = new int[]{var5, var1[var5]};
               }
            }

            this.field_1477 = true;
            this.field_1498 = 0;
            this.field_1488 = new class_14();
            this.field_1488.method_225(this.field_1497[0][0], this.field_1497[0][1]);
         }
      } else {
         this.field_1498++;
         if (this.field_1498 >= this.field_1497.length) {
            this.field_1477 = false;
         } else {
            this.field_1488.method_225(this.field_1497[this.field_1498][0], this.field_1497[this.field_1498][1]);
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_904() {
      return this.field_1502;
   }

   // $VF: renamed from: b (int) void
   public final void method_900(int var1) {
      if (this.field_1502) {
         class_69.method_673(false);
         this.field_1457 = System.currentTimeMillis();
         this.field_1459 = this.field_1457 - this.field_1458;
         this.field_1458 = this.field_1457;
         this.field_1460 = this.field_1460 + this.field_1459;
         this.field_1461 = this.field_1461 + this.field_1459;
         class_3.method_141(this.field_1459);
         class_58.method_575(class_3.method_112());
         if (!this.field_1470 && !this.field_1471 && !this.field_1472 && !this.field_1473 && !this.field_1474 && !this.field_1476 && this.field_1465 != null) {
            this.field_1465.method_917();
         }

         if (this.field_1461 < 2300L) {
            class_50.method_485(
               class_41.field_533.method_297(this.field_1493 ? 36 : 32), 5, class_41.field_538 - class_69.method_653() - class_50.method_494(), 1
            );
         } else {
            this.field_1493 = false;
         }

         if (this.field_1461 >= 2300L) {
            if (!this.field_1475) {
               class_95 var2;
               if ((var2 = class_3.method_78(true, 0L)) != null) {
                  this.field_1489 = var2;
               }

               if (var2 != null) {
                  this.field_1485 = new class_30(var2, 1);
                  this.field_1475 = true;
               }
            }

            if (!this.field_1469 && !this.field_1475) {
               this.method_922();
            }

            int var3 = var1;
            if (this.field_1478) {
               var3 = 0;
            }

            if (this.field_1476) {
               this.field_1487.method_726(var3, (int)this.field_1459);
            } else {
               if (this.field_1475) {
                  if (this.field_1473 || this.field_1470 || this.field_1471) {
                     class_69.method_663();
                  }

                  this.field_1485.method_352(var3, (int)this.field_1459);
                  this.field_1485.method_359();
               } else if (this.field_1468) {
                  this.field_1466.method_625(var3, (int)this.field_1459);
                  this.field_1466.method_636();
               } else if (this.field_1470) {
                  class_69.method_655((int)this.field_1459);
                  this.field_1480.method_306(var3, (int)this.field_1459);
                  if (this.field_1480 != null && this.field_1480.method_308()) {
                     if (this.field_1482.method_644() && this.field_1486 == null && !class_41.field_513) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(360));
                        class_41.field_513 = true;
                        this.field_1478 = true;
                     }

                     if (!this.field_1482.method_644() && this.field_1486 == null && !class_41.field_512) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(359));
                        class_41.field_512 = true;
                        this.field_1478 = true;
                     }
                  } else if (this.field_1480 != null && this.field_1480.method_307()) {
                     if (this.field_1482.method_644() && this.field_1486 == null && !class_41.field_507) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(362));
                        class_41.field_507 = true;
                        this.field_1478 = true;
                     }

                     if (!this.field_1482.method_644() && this.field_1486 == null && !class_41.field_506) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(361));
                        class_41.field_506 = true;
                        this.field_1478 = true;
                     }
                  }
               } else if (this.field_1471) {
                  class_69.method_655((int)this.field_1459);
                  this.field_1481.method_598(var3, (int)this.field_1459);
               } else if (this.field_1472) {
                  this.field_1482.method_645(var3, (int)this.field_1459);
                  if (this.field_1482 != null) {
                     if (this.field_1482.method_644() && this.field_1486 == null && !class_41.field_507) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(362));
                        class_41.field_507 = true;
                        this.field_1478 = true;
                     }

                     if (!this.field_1482.method_644() && this.field_1486 == null && !class_41.field_506) {
                        this.field_1486 = new class_30(class_41.field_533.method_297(361));
                        class_41.field_506 = true;
                        this.field_1478 = true;
                     }
                  }
               } else if (this.field_1473) {
                  class_69.method_655((int)this.field_1459);
                  this.field_1483.method_476(var3, (int)this.field_1459);
               } else if (this.field_1474) {
                  class_69.method_655((int)this.field_1459);
                  this.field_1484.method_211(var3, (int)this.field_1459);
               } else {
                  this.method_923();
               }

               if (this.field_1478) {
                  this.field_1486.method_352(var1, (int)this.field_1459);
                  this.field_1486.method_360();
               }
            }
         }
      }
   }

   // $VF: renamed from: d () void
   public final void method_922() {
      if (this.field_1499 && this.field_1486 == null && class_3.method_73() == 16 && class_3.method_110().field_828 != 5) {
         this.field_1486 = new class_30(class_3.method_149(class_41.field_533.method_297(280), class_3.method_143()));
         this.field_1499 = false;
         this.field_1478 = true;
      }

      if (this.field_1499 && this.field_1486 == null && class_3.method_73() == 18 && !class_3.method_110().method_592() && class_3.method_110().field_828 != 6) {
         this.field_1486 = new class_30(class_41.field_533.method_297(281));
         this.field_1478 = true;
         this.field_1499 = false;
      }

      if (this.field_1486 == null && !class_41.field_520 && class_3.method_108().method_365()) {
         this.field_1486 = new class_30(class_41.field_533.method_297(346));
         this.field_1478 = true;
         class_41.field_520 = true;
      }

      if (!this.field_1477 && this.field_1486 == null && !class_41.field_522 && class_58.method_564()) {
         this.field_1486 = new class_30(class_41.field_533.method_297(350));
         class_41.field_522 = true;
         this.field_1478 = true;
      }

      if (!this.field_1477 && this.field_1486 == null && !class_41.field_523 && class_58.method_565()) {
         this.field_1486 = new class_30(class_41.field_533.method_297(351));
         class_41.field_523 = true;
         this.field_1478 = true;
      }

      if (!this.field_1477 && this.field_1486 == null && !class_41.field_524 && !class_58.method_564() && class_3.method_76()) {
         this.field_1486 = new class_30(class_41.field_533.method_297(352));
         class_41.field_524 = true;
         this.field_1478 = true;
      }

      if (!this.field_1477 && this.field_1486 == null && !this.field_1500 && class_58.method_571() > 0) {
         int var1;
         int var2 = (var1 = class_58.method_571()) < 4 ? 284 : (var1 < 7 ? 285 : (var1 < 12 ? 286 : 287));
         this.field_1486 = new class_30(
            class_41.field_533.method_297(283)
               + ": "
               + var1
               + "\n"
               + var1
               + " x "
               + var1
               + " x "
               + this.field_1501
               + " $\n"
               + class_41.field_533.method_297(40)
               + ": "
               + var1 * var1 * this.field_1501
               + " $\n\n"
               + class_41.field_533.method_297(var2)
               + "\n",
            true
         );
         this.field_1500 = true;
         this.field_1478 = true;
      }
   }

   // $VF: renamed from: f () void
   private void method_923() {
      class_41.field_534.drawImage(this.field_1464, 3, 3, 0);
      class_50.method_483(class_3.method_110().field_827, this.field_1464.getWidth() + 6, 3, 0, 17);
      class_50.method_483(
         class_41.field_533.method_297(class_22.field_323[class_3.method_105()[class_3.method_110().field_828] ? 1 : 0]),
         this.field_1464.getWidth() + 6,
         13,
         1,
         17
      );
      class_50.method_483(class_41.field_533.method_297(44) + ": " + class_3.method_110().field_833, this.field_1464.getWidth() + 6, 23, 1, 17);
      if (this.field_1467) {
         class_69.method_667("", this.field_1490, this.field_1491, this.field_1492, 12 + (this.field_1463.length + 1) * 10 - 5);
         class_69.method_661(class_41.field_533.method_297(62), this.field_1490, this.field_1491 + 12, this.field_1492, this.field_1463[0] == 1, false, true);
         class_69.method_661(
            class_41.field_533.method_297(37), this.field_1490, this.field_1491 + 12 + 10, this.field_1492, this.field_1463[1] == 1, false, true
         );
         class_69.method_661(
            class_41.field_533.method_297(73), this.field_1490, this.field_1491 + 12 + 20, this.field_1492, this.field_1463[2] == 1, false, true
         );
         class_69.method_661(
            class_41.field_533.method_297(235), this.field_1490, this.field_1491 + 12 + 30, this.field_1492, this.field_1463[3] == 1, false, true
         );
         class_69.method_661(
            class_41.field_533.method_297(64), this.field_1490, this.field_1491 + 12 + 40, this.field_1492, this.field_1463[4] == 1, false, true
         );
         class_69.method_661(
            class_41.field_533.method_297(66), this.field_1490, this.field_1491 + 12 + 50, this.field_1492, this.field_1463[5] == 1, false, true
         );
         class_69.method_661(
            class_41.field_533.method_297(241), this.field_1490, this.field_1491 + 12 + 60, this.field_1492, this.field_1463[6] == 1, false, true
         );
      } else if (!this.field_1475
         && !this.field_1473
         && !this.field_1471
         && !this.field_1472
         && !this.field_1468
         && !this.field_1470
         && !this.field_1469
         && !this.field_1477
         && !this.field_1474) {
         class_69.method_655((int)this.field_1459);
         class_69.method_673(class_69.method_656());
      }

      if (this.field_1477) {
         class_69.method_669("", "");
         this.field_1488.method_226();
      } else if (this.field_1469) {
         class_69.method_669("", "");
         this.field_1479.method_518();
      } else {
         class_69.method_669(class_41.field_533.method_297(67), class_41.field_533.method_297(241));
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_901(int var1) {
      if (this.field_1502) {
         class_3.method_129();
         if (this.field_1461 < 2300L) {
            if (var1 == 256) {
               this.field_1461 = 2301L;
               class_69.method_654(!class_3.method_110().method_592());
            }
         } else if (this.field_1476) {
            if ((var1 == 131072 || var1 == 16384 || var1 == 8192) && !this.field_1487.method_725(131072)) {
               this.field_1476 = false;
            }
         } else if (this.field_1478) {
            if (var1 == 256) {
               this.field_1478 = false;
               this.field_1486 = null;
               class_69.method_654(!class_3.method_110().method_592());
               if (this.field_1500) {
                  class_3.method_127(class_58.method_571() * class_58.method_571() * this.field_1501);
                  class_58.method_572();
                  this.field_1500 = false;
               }
            }
         } else {
            if (var1 == 131072) {
               if (this.field_1471) {
                  this.field_1487.method_724(class_41.field_533.method_297(353));
               } else if (this.field_1470) {
                  if (this.field_1480.method_302() == 1) {
                     this.field_1487.method_724(class_41.field_533.method_297(355));
                  } else {
                     this.field_1487.method_724(class_41.field_533.method_297(356));
                  }
               } else if (this.field_1473) {
                  if (this.field_1483.method_478() == 0) {
                     this.field_1487.method_724(class_41.field_533.method_297(357));
                  } else {
                     this.field_1487.method_724(class_41.field_533.method_297(358));
                  }
               } else if (this.field_1472) {
                  if (this.field_1482.method_639()) {
                     this.field_1487.method_724(class_41.field_533.method_297(361));
                  } else {
                     this.field_1487.method_724(class_41.field_533.method_297(362));
                  }
               } else if (this.field_1474) {
                  if (this.field_1484.method_210()) {
                     this.field_1487.method_724(class_41.field_533.method_297(364));
                  } else {
                     this.field_1487.method_724(class_41.field_533.method_297(363));
                  }
               } else if (!this.field_1468) {
                  this.field_1487.method_724(class_41.field_533.method_297(365));
               }

               if (!this.field_1468) {
                  this.field_1476 = true;
               }
            }

            if (this.field_1475) {
               if (!this.field_1485.method_351(var1)) {
                  if (this.field_1489.field_1226 == 13 || this.field_1489.field_1226 == 14) {
                     if (!this.field_1489.field_1241 || this.field_1489.field_1244 != 36 || class_3.method_73() == 41) {
                        class_3.method_108().method_370(this.field_1489.field_1244, this.field_1489.field_1245);
                     }

                     this.field_1483.method_474();
                  }

                  if (this.field_1489.field_1241) {
                     class_3.method_75();
                  } else {
                     class_3.method_71();
                  }

                  class_3.method_127(this.field_1489.field_1230);
                  class_3.method_93(this.field_1489);
                  this.field_1480.method_299();
                  this.field_1475 = false;
                  if (this.field_1496 > 0) {
                     class_3.method_127(this.field_1496);
                     this.field_1496 = 0;
                  }
               }
            } else if (this.field_1470) {
               if (var1 == 32 && this.field_1480.method_303() && this.field_1486 == null && !class_41.field_505) {
                  this.field_1486 = new class_30(class_41.field_533.method_297(355));
                  class_41.field_505 = true;
                  this.field_1478 = true;
               }

               if (!this.field_1480.method_304(var1)) {
                  this.field_1470 = false;
               }
            } else if (this.field_1471) {
               if (var1 == 32 && this.field_1481.method_596() && this.field_1486 == null && !class_41.field_503) {
                  this.field_1486 = new class_30(class_41.field_533.method_297(354));
                  class_41.field_503 = true;
                  this.field_1478 = true;
               }

               if (!this.field_1481.method_597(var1)) {
                  this.field_1471 = false;
               }
            } else if (this.field_1472) {
               if (!this.field_1482.method_642(var1)) {
                  this.field_1472 = false;
               }
            } else if (this.field_1473) {
               if (var1 == 32 && this.field_1483.method_479() && this.field_1486 == null && !class_41.field_509) {
                  this.field_1486 = new class_30(class_41.field_533.method_297(358));
                  class_41.field_509 = true;
                  this.field_1478 = true;
               }

               if (!this.field_1483.method_475(var1)) {
                  this.field_1473 = false;
               }
            } else if (this.field_1474) {
               if (var1 == 32 && this.field_1486 == null && !class_41.field_511) {
                  this.field_1486 = new class_30(class_41.field_533.method_297(364));
                  class_41.field_511 = true;
                  this.field_1478 = true;
               }

               if (!this.field_1484.method_209(var1)) {
                  this.field_1474 = false;
               }
            } else if (this.field_1477) {
               if (var1 == 256) {
                  this.method_921();
               }
            } else if (!this.field_1469) {
               if (this.field_1467 && !this.field_1468) {
                  if (var1 == 256 && !this.field_1475 && !this.field_1477) {
                     switch (this.field_1462) {
                        case 0:
                           this.field_1471 = true;
                           if (this.field_1486 == null && !class_41.field_502) {
                              this.field_1486 = new class_30(class_41.field_533.method_297(353));
                              class_41.field_502 = true;
                              this.field_1478 = true;
                           }

                           return;
                        case 1:
                           if (class_3.method_73() < 9) {
                              this.field_1486 = new class_30(class_3.method_149(class_41.field_533.method_297(282), class_3.method_143()));
                              this.field_1478 = true;
                              return;
                           }

                           if (class_3.method_73() == 42 && !class_3.method_108().method_369(42)) {
                              this.field_1486 = new class_30(class_41.field_533.method_297(289));
                              this.field_1478 = true;
                              return;
                           }

                           this.field_1470 = true;
                           this.field_1480.method_301();
                           this.field_1460 = -150L;
                           if (this.field_1486 == null && !class_41.field_504) {
                              this.field_1486 = new class_30(class_41.field_533.method_297(356));
                              class_41.field_504 = true;
                              this.field_1478 = true;
                           }

                           return;
                        case 2:
                           if (class_3.method_73() < 7) {
                              this.field_1486 = new class_30(class_3.method_149(class_41.field_533.method_297(282), class_3.method_143()));
                              this.field_1478 = true;
                              return;
                           }

                           if (class_3.method_73() == 42 && !class_3.method_108().method_369(42)) {
                              this.field_1486 = new class_30(class_41.field_533.method_297(289));
                              this.field_1478 = true;
                              return;
                           }

                           this.field_1472 = true;
                           this.field_1482.method_640(null);
                           return;
                        case 3:
                           if (!class_3.method_110().method_592()) {
                              this.field_1473 = true;
                              if (this.field_1486 == null && !class_41.field_508) {
                                 this.field_1486 = new class_30(class_41.field_533.method_297(357));
                                 class_41.field_508 = true;
                                 this.field_1478 = true;
                                 return;
                              }
                           } else {
                              this.field_1486 = new class_30(class_41.field_533.method_297(256));
                              this.field_1478 = true;
                           }

                           return;
                        case 4:
                           this.field_1474 = true;
                           this.field_1484.method_208();
                           if (this.field_1486 == null && !class_41.field_510) {
                              this.field_1486 = new class_30(class_41.field_533.method_297(363));
                              class_41.field_510 = true;
                              this.field_1478 = true;
                           }

                           return;
                        case 5:
                           this.field_1468 = true;
                           this.field_1466.method_634(2);
                           return;
                        case 6:
                           this.method_924();
                           return;
                     }
                  }

                  if (var1 == 64) {
                     this.field_1463[this.field_1462] = 0;
                     if (this.field_1462 < this.field_1463.length - 1) {
                        this.field_1462++;
                     } else {
                        this.field_1462 = 0;
                     }

                     this.field_1463[this.field_1462] = 1;
                  }

                  if (var1 == 2) {
                     this.field_1463[this.field_1462] = 0;
                     if (this.field_1462 > 0) {
                        this.field_1462--;
                     } else {
                        this.field_1462 = this.field_1463.length - 1;
                     }

                     this.field_1463[this.field_1462] = 1;
                  }

                  if (var1 == 16384) {
                     this.field_1467 = !this.field_1467;
                     return;
                  }
               }

               if (!this.field_1468 && var1 == 8192) {
                  this.method_924();
               } else if (this.field_1468) {
                  this.field_1466.method_637(var1);
                  if (var1 == 4) {
                     this.field_1466.method_629();
                  }

                  if (var1 == 32) {
                     this.field_1466.method_631();
                  }

                  if (var1 == 2) {
                     this.field_1466.method_627((int)this.field_1459);
                  }

                  if (var1 == 64) {
                     this.field_1466.method_628((int)this.field_1459);
                  }

                  if (var1 == 16384) {
                     this.field_1466.method_633();
                  }

                  if (var1 == 8192 && this.field_1466.method_632()) {
                     this.field_1468 = !this.field_1468;
                     this.field_1466.method_634(2);
                  }

                  if (var1 == 256 && !this.field_1475 && !this.field_1477) {
                     this.field_1499 = false;
                     if (this.field_1466.method_626()) {
                        this.field_1468 = false;
                     }
                  }
               } else {
                  if (var1 == 16384) {
                     this.field_1467 = !this.field_1467;
                  }
               }
            } else {
               if (var1 == 4) {
                  this.field_1479.method_516();
               }

               if (var1 == 32) {
                  this.field_1479.method_517();
               }

               if (var1 == 256) {
                  if (this.field_1479.method_515() && this.field_1495) {
                     this.field_1495 = false;
                     class_3.method_70();
                     class_3.method_61(class_3.method_110());
                     class_3.field_63 = -1;
                     class_3.field_61 = -1;
                     class_3.field_62 = -1;
                     class_58.method_580();
                     class_41.field_543.method_213(class_41.field_544[2]);
                  } else if (this.field_1496 > 0) {
                     class_3.method_127(this.field_1496);
                     this.field_1496 = 0;
                  }

                  this.field_1469 = false;
               }
            }
         }
      }
   }

   // $VF: renamed from: g () void
   private void method_924() {
      if (class_3.method_73() == 3) {
         this.field_1486 = new class_30(class_41.field_533.method_297(288));
         this.field_1478 = true;
      } else if (class_3.method_73() == 42 && !class_3.method_108().method_369(42)) {
         this.field_1486 = new class_30(class_41.field_533.method_297(289));
         this.field_1478 = true;
      } else {
         if (!this.field_1469 && !this.field_1475 && !this.field_1477) {
            this.field_1479.method_514(class_41.field_533.method_297(234), true);
            this.field_1479.method_516();
            this.field_1469 = true;
            this.field_1495 = true;
         }
      }
   }
}
