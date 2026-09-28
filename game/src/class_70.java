// $VF: renamed from: ba
public final class class_70 {
   // $VF: renamed from: c int
   private static int field_966 = 5;
   // $VF: renamed from: d int
   private static int field_967 = 5000;
   // $VF: renamed from: e int
   private static int field_968 = 20000;
   // $VF: renamed from: a cm
   public class_37 field_969;
   // $VF: renamed from: a ax
   public class_108 field_970;
   // $VF: renamed from: b ax
   private class_108 field_971;
   // $VF: renamed from: a s
   private class_5 field_972;
   // $VF: renamed from: a c
   private class_104 field_973;
   // $VF: renamed from: a x
   private class_3 field_974;
   // $VF: renamed from: b x
   private class_3 field_975;
   // $VF: renamed from: a bg
   public class_60 field_976;
   // $VF: renamed from: a as
   private class_82 field_977;
   // $VF: renamed from: a i
   private class_11 field_978;
   // $VF: renamed from: a ap
   public class_85 field_979;
   // $VF: renamed from: a da
   private class_25 field_980;
   // $VF: renamed from: a cz
   public class_26 field_981;
   // $VF: renamed from: a dr
   public class_18 field_982;
   // $VF: renamed from: f int
   private int field_983;
   // $VF: renamed from: g int
   private int field_984;
   // $VF: renamed from: h int
   private int field_985;
   // $VF: renamed from: i int
   private int field_986;
   // $VF: renamed from: a int
   public int field_987;
   // $VF: renamed from: a long
   private long field_988;
   // $VF: renamed from: b long
   private long field_989;
   // $VF: renamed from: j int
   private int field_990;
   // $VF: renamed from: a boolean
   public boolean field_991;
   // $VF: renamed from: c long
   private long field_992;
   // $VF: renamed from: k int
   private int field_993;
   // $VF: renamed from: b boolean
   public boolean field_994;
   // $VF: renamed from: l int
   private int field_995;
   // $VF: renamed from: m int
   private int field_996;
   // $VF: renamed from: c boolean
   public boolean field_997;
   // $VF: renamed from: f boolean
   private boolean field_998;
   // $VF: renamed from: g boolean
   private boolean field_999;
   // $VF: renamed from: c x
   private class_3 field_1000;
   // $VF: renamed from: d x
   private class_3 field_1001;
   // $VF: renamed from: a bn
   private class_57 field_1002 = new class_57();
   // $VF: renamed from: n int
   private int field_1003;
   // $VF: renamed from: b int
   public int field_1004;
   // $VF: renamed from: a float
   private float field_1005;
   // $VF: renamed from: o int
   private int field_1006;
   // $VF: renamed from: d boolean
   public boolean field_1007;
   // $VF: renamed from: a aw
   private class_91 field_1008;
   // $VF: renamed from: e boolean
   public boolean field_1009;
   // $VF: renamed from: e x
   private class_3 field_1010;
   // $VF: renamed from: c ax
   private class_108 field_1011;
   // $VF: renamed from: d ax
   private class_108 field_1012;
   // $VF: renamed from: p int
   private int field_1013;
   // $VF: renamed from: q int
   private int field_1014;
   // $VF: renamed from: h boolean
   private boolean field_1015;

   public class_70(class_37 var1) {
      this.field_969 = var1;
      this.field_969.field_380 = true;
      this.field_974 = new class_3();
      this.field_975 = new class_3();
      this.field_1010 = new class_3();
      this.field_1000 = new class_3();
      this.field_1001 = new class_3();
      this.field_986 = 1;
      this.field_976 = new class_60();
      this.field_977 = new class_82();
      this.field_978 = new class_11();
      this.field_980 = new class_25();
      this.field_987 = -1;
      this.field_990 = this.field_969.method_333();
      this.field_983 = 2;
      this.field_994 = false;
      this.field_997 = true;
      this.field_1007 = false;
      this.field_1008 = null;
      this.field_1003 = class_21.method_180().field_1140;
      this.field_1004 = this.field_1003;
      field_968 = class_21.method_178().field_878;
      field_966 = class_21.method_178().field_877;
      field_967 = class_21.method_178().field_879;
      this.field_999 = field_968 > 0;
      this.field_1005 = class_21.method_178().field_870;
      this.field_1006 = class_21.method_178().field_880;
      this.field_1005 = this.field_1005 + this.field_1006 / 100.0F;
      this.field_1011 = class_43.method_381(9993);
      this.field_1011.field_1367 = 2;
      this.field_1012 = class_43.method_381(9997);
      this.field_1012.field_1367 = 2;
      this.field_971 = class_43.method_381(6768);
      this.field_971.field_1367 = 3;
      new class_103().method_879(this.field_971);
      this.field_972 = new class_5(this.field_1011, this.field_971);
      this.field_972.field_53 = true;
      this.field_973 = new class_104();
      this.field_973.method_880(this.field_972);
      this.field_1013 = this.field_1003 - class_21.method_178().field_889 << 3;
      this.field_1014 = this.field_1003 - class_21.method_178().field_890 << 3;
   }

   // $VF: renamed from: a (ax) void
   public final void method_648(class_108 var1) {
      this.field_970 = var1;
      int[] var2;
      if ((var2 = class_90.method_789(var1.field_1344, class_21.method_178().field_884 ? 1 : 0)) != null) {
         var1.method_876(var2[0], var2[1]);
         var1.method_877((byte)2);
      }

      var1.field_1341.method_491(0, 0, 0);
   }

   // $VF: renamed from: a () void
   public final void method_649() {
      this.field_990 = this.field_969.method_333();
   }

   // $VF: renamed from: b () void
   public final void method_650() {
      if (!this.field_994 && this.field_999 && this.field_993 >= 0) {
         class_84.field_1122.method_770(7);
         this.field_993 = 0;
         this.field_983 = field_966;
         this.field_994 = true;
         this.field_970.method_849(this.field_1000);
         this.field_1001.method_9(this.field_1000);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_651() {
      return this.field_993 >= 0;
   }

   // $VF: renamed from: a () float
   public final float method_652() {
      float var1;
      if ((var1 = (float)this.field_993 / (field_967 / 6)) < 1.0F) {
         return var1;
      } else {
         return var1 > 5.0F ? 6.0F - var1 : 1.0F;
      }
   }

   // $VF: renamed from: b () float
   public final float method_653() {
      float var1;
      return (var1 = (float)this.field_993 / field_968) > 0.0F ? 1.0F : 1.0F + var1;
   }

   // $VF: renamed from: c () void
   public final void method_654() {
      this.field_982 = null;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_655() {
      return this.method_659() <= 0;
   }

   // $VF: renamed from: a (long) void
   public final void method_656(long var1) {
      if (this.field_987 >= 0) {
         this.field_969.method_352(this.field_987, var1, false);
      }
   }

   // $VF: renamed from: a (n, int) void
   public final void method_657(class_9 var1, int var2) {
      this.field_969.method_346(var1, var2);
      this.field_987 = 0;
   }

   // $VF: renamed from: a (n[], int) void
   public final void method_658(class_9[] var1, int var2) {
      this.field_969.method_347(var1, var2);
      this.field_987 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_659() {
      return this.field_969.field_363;
   }

   // $VF: renamed from: b () int
   public final int method_660() {
      return this.field_969.field_370;
   }

   // $VF: renamed from: d () void
   public final void method_661() {
      this.field_987++;
      if (this.field_987 > this.field_969.field_369 - 1) {
         this.field_987 = 0;
      }

      class_21.method_178().field_891 = this.field_987;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_662() {
      return this.field_987 >= 0
         && this.field_969.field_359 != null
         && this.field_969.field_359[this.field_987] != null
         && this.field_969.field_359[this.field_987][0].field_97;
   }

   // $VF: renamed from: c () int
   public final int method_663() {
      return this.field_969.method_350(this.field_987);
   }

   // $VF: renamed from: a () x
   public final class_3 method_664() {
      return this.field_970.method_848(this.field_974);
   }

   // $VF: renamed from: c () float
   public final float method_665() {
      return 1.0F - class_16.method_97(0, this.field_1004 - 15000) / 15000.0F;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_666(boolean var1) {
      this.field_969.field_375 = var1;
   }

   // $VF: renamed from: a (aw) void
   public final void method_667(class_91 var1) {
      this.field_1008 = var1;
      this.field_1009 = false;
      this.field_1007 = this.field_1008 != null;
      if (this.field_1008 != null && this.field_1008 instanceof class_97) {
         this.field_1009 = true;
      }
   }

   // $VF: renamed from: d () boolean
   public final boolean method_668() {
      return this.field_1008 == this.field_981.field_276[1];
   }

   // $VF: renamed from: e () boolean
   public final boolean method_669() {
      return this.field_981.field_276[0] != null ? this.field_1008 == this.field_981.field_276[0] : false;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_670(int var1, int var2, int var3) {
      this.field_970.method_845(var1, var2, var3);
      this.field_969.field_377.method_476(var1, var2, var3);
   }

   // $VF: renamed from: b (long) void
   public final void method_671(long var1) {
      if (!this.field_991) {
         int var3 = this.field_1003 - (this.field_970.method_853() >> 3);
         this.field_1004 = var3 > 500 ? var3 : 500;
         this.field_1000 = this.field_970.method_849(this.field_1000);
         this.field_992 = var1;
         if (this.field_993 < 0 && this.field_993 + 3L * var1 > 0L) {
            class_69.method_633(4, this);
            this.field_993 = 0;
         }

         this.field_993 = (int)(this.field_993 + var1);
         if (this.field_994) {
            if (this.field_993 > field_967) {
               this.field_983 = 2;
               this.field_994 = false;
               this.field_993 = -field_968;
            }

            if (this.field_980 != null) {
               this.field_980.method_236(this.field_1000, (int)this.field_992);
               this.field_1001.method_9(this.field_1000);
            }
         }

         this.field_998 = false;
         if (this.field_997) {
            this.method_672(this.field_981.field_276);
            this.method_672(this.field_981.field_274);
            this.method_672(this.field_981.field_273);
         }

         if (this.field_1007 && this.field_1008 != null && !this.field_998) {
            if (this.field_1009) {
               this.field_1008 = ((class_97)this.field_1008).field_1230.method_110();
            }

            if (this.field_1008 != null) {
               this.field_975 = this.field_1008.method_799(this.field_975);
               this.field_975.method_17(this.field_970.method_848(this.field_1000));
               this.field_975.method_22();
               this.field_974.method_9(this.field_970.method_855(this.field_974));
               this.field_974.method_22();
               this.field_975.method_17(this.field_974);
               this.field_975.method_18((int)((float)this.field_992 * 5.0F));
               this.field_1010 = this.field_974.method_14(this.field_975, this.field_1010);
               this.field_1010.method_22();
               this.field_970.field_1341.method_512(this.field_1010);
               if (this.field_984 == 0 && this.field_985 == 0) {
                  this.method_677((int)this.field_992);
               }

               this.field_970.method_847((int)var1 * this.field_983);
            } else {
               this.method_667(null);
            }
         } else if (!this.field_998) {
            this.field_970.method_862((int)(this.field_1005 * (this.field_984 * (int)var1 / 3)));
            this.field_995 = (int)(this.field_1005 * (this.field_985 * (int)var1 / 3));
            this.field_970.method_863(this.field_995);
            this.field_996 = this.field_996 + (int)(this.field_1005 * (this.field_984 * (int)var1 / 3));
            if (this.field_984 == 0 && this.field_985 == 0) {
               this.method_677((int)this.field_992);
            }

            this.field_970.method_847((int)var1 * this.field_983);
         }

         if (!this.field_998) {
            this.field_970.field_1364 = -this.field_986;
            if (this.field_986 > 0 && this.field_985 == 0) {
               this.field_986 = (int)(this.field_986 - var1 / 5L);
            } else if (this.field_986 < -var1 / 5L && this.field_985 == 0) {
               this.field_986 = (int)(this.field_986 + var1 / 5L);
            }

            this.field_984 = this.field_985 = 0;
         }

         if (this.field_1004 > class_21.method_178().field_889 && class_21.method_178().field_871 > 0 && class_21.method_178().field_873 > 0) {
            this.field_988 += var1;
            if (this.field_988 > class_21.method_178().field_873) {
               this.field_988 = 0L;
               this.field_969.method_334();
            }
         }

         if (class_21.method_178().field_883 && this.field_969.field_363 < this.field_969.field_364) {
            this.field_989 += var1;
            if (this.field_989 > 600L) {
               this.field_989 = 0L;
               this.field_969.method_335();
            }
         }

         this.field_969.method_353(var1);
         this.field_976.method_547(var1, class_84.field_1110.field_40.field_1342, false);
         this.field_978.method_55(this.field_970.field_1341);
         this.field_969.field_377 = this.field_970.field_1341;
         this.field_1011.method_845(this.field_970.method_852(), this.field_1013, this.field_970.method_854());
         this.field_1012.method_845(this.field_970.method_852(), this.field_1014, this.field_970.method_854());
         if (this.field_982 != null) {
            this.field_982.method_114(this.field_970.method_852(), this.field_970.method_853(), this.field_970.method_854());
         }

         if (!this.field_997) {
            if (this.field_980 != null) {
               this.field_980.method_236(this.field_1000, (int)this.field_992);
               this.field_1001.method_9(this.field_1000);
            }
         } else {
            if (this.field_990 > this.field_969.method_333()) {
               class_84.method_736(110);
               this.field_990 = this.field_969.method_333();
            }

            this.field_1015 = false;
            if (this.field_1004 > class_21.method_178().field_890 + 200) {
               this.field_974 = this.field_1012.method_848(this.field_974);
               this.field_972.field_45 = this.field_1012;
               this.field_1015 = true;
            } else if (this.field_1004 < class_21.method_178().field_889 - 200) {
               this.field_974 = this.field_1011.method_848(this.field_974);
               this.field_972.field_45 = this.field_1011;
               this.field_1015 = true;
            }

            if (this.field_1004 > class_21.method_159()) {
               class_21.method_161(this.field_1004);
            } else if (this.field_1004 < class_21.method_160()) {
               class_21.method_162(this.field_1004);
            }

            if (this.field_1015) {
               this.field_971.method_870(class_84.field_1110.field_40.field_1341);
               this.field_971.method_847(-4200);
               this.field_973.method_839(false);
            }

            if (this.field_1000.method_23() > 500000) {
               this.field_970.method_845(20000, this.field_1000.field_38, 20000);
            }

            if (this.method_655()) {
               this.method_678(var1);
            }
         }
      }
   }

   // $VF: renamed from: a (aw[]) void
   private void method_672(class_91[] var1) {
      if (var1 != null) {
         for (int var2 = 0; var2 < var1.length; var2++) {
            if (var1[var2] != null && var1[var2].method_807(this.field_970.method_848(this.field_975))) {
               this.field_975 = var1[var2].method_808(this.field_970.method_848(this.field_975));
               this.field_975.field_37 += 100;
               if (this.field_975 != null) {
                  this.field_974.method_9(this.field_970.method_855(this.field_974));
                  this.field_975.method_17(this.field_974);
                  this.field_975.method_18((int)((float)this.field_992 * 5.0F));
                  this.field_1000 = this.field_974.method_14(this.field_975, this.field_1000);
                  this.field_1000.method_22();
                  this.field_970.field_1341.method_512(this.field_1000);
                  this.field_970.method_847((int)this.field_992 * this.field_983);
                  this.method_677((int)this.field_992);
                  this.field_998 = true;
                  return;
               }
            }
         }
      }
   }

   // $VF: renamed from: c (long) void
   public final void method_673(long var1) {
      this.field_985 = 1;
      if (this.field_986 < 384) {
         this.field_986 = (int)(this.field_986 + var1);
      }
   }

   // $VF: renamed from: d (long) void
   public final void method_674(long var1) {
      this.field_985 = -1;
      if (this.field_986 > -384) {
         this.field_986 = (int)(this.field_986 - var1);
      }
   }

   // $VF: renamed from: e (long) void
   public final void method_675(long var1) {
      this.field_984 = 1;
   }

   // $VF: renamed from: f (long) void
   public final void method_676(long var1) {
      this.field_984 = -1;
   }

   // $VF: renamed from: a (int) void
   public final void method_677(int var1) {
      this.field_1002.method_469();
      var1 = class_16.method_98(var1, 60);
      this.field_974 = this.field_970.method_856(this.field_974);
      this.field_975 = this.field_970.method_858(this.field_975);
      this.field_1002.method_469();
      int var2 = this.field_1002.method_483().method_12(this.field_975);
      if (this.field_1002.method_483().method_12(this.field_974) < 0) {
         if (var2 > 0) {
            this.field_970.method_861(-var1 >> 1);
         } else {
            this.field_970.method_861(var1 >> 1);
         }
      } else {
         if (var2 > 128 && var2 < 3968 || var2 < -128 && var2 > -3968) {
            if (var2 < 0) {
               this.field_970.method_861(var1 >> 1);
               return;
            }

            this.field_970.method_861(-var1 >> 1);
         }
      }
   }

   // $VF: renamed from: g (long) void
   private void method_678(long var1) {
      if (this.field_969.field_375) {
         this.field_979.method_741(this.field_970.method_852(), this.field_970.method_853(), this.field_970.method_854());
      }

      this.field_969.field_375 = false;
   }

   // $VF: renamed from: e () void
   public final void method_679() {
      this.field_969.method_351(this.field_987);
   }

   // $VF: renamed from: f () void
   public final void method_680() {
      this.field_981 = null;
      if (this.field_979 != null) {
         this.field_979.method_738();
      }

      this.field_979 = null;
      if (this.field_978 != null) {
         this.field_978.method_56();
      }

      this.field_978 = null;
      if (this.field_976 != null) {
         this.field_976.method_546();
      }

      this.field_976 = null;
      this.field_977 = null;
      if (this.field_980 != null) {
         this.field_980.method_235();
      }

      this.field_980 = null;
      System.gc();
   }

   // $VF: renamed from: b (boolean) void
   public final void method_681(boolean var1) {
      if (this.method_655()) {
         this.field_979.method_742(this.field_992);
         this.field_976.method_548();
      } else {
         class_84.field_1110.method_25(this.field_970);
         if (this.field_1015) {
            class_84.field_1110.method_25(this.field_971);
         }

         this.field_976.method_548();
         if (!this.field_991 && var1) {
            class_84.field_1110.method_25(this.field_1011);
            class_84.field_1110.method_25(this.field_1012);
         }

         if (this.field_994 || !this.field_997) {
            this.field_980.method_238();
         }
      }
   }

   // $VF: renamed from: a (boolean, an) void
   public final void method_682(boolean var1, class_106 var2) {
      if (!this.method_655() && !this.field_991 && var1) {
         this.field_978.method_57(var2);
      }
   }
}
