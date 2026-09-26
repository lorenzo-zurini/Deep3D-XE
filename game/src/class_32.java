// $VF: renamed from: be
public final class class_32 {
   // $VF: renamed from: a int
   public int field_422;
   // $VF: renamed from: b int
   public int field_423;
   // $VF: renamed from: w int
   private int field_424;
   // $VF: renamed from: c int
   public int field_425;
   // $VF: renamed from: d int
   public int field_426;
   // $VF: renamed from: x int
   private int field_427;
   // $VF: renamed from: e int
   public int field_428;
   // $VF: renamed from: a float
   public float field_429;
   // $VF: renamed from: f int
   public int field_430;
   // $VF: renamed from: g int
   public int field_431;
   // $VF: renamed from: h int
   public int field_432;
   // $VF: renamed from: i int
   public int field_433;
   // $VF: renamed from: j int
   public int field_434;
   // $VF: renamed from: k int
   public int field_435;
   // $VF: renamed from: l int
   public int field_436;
   // $VF: renamed from: m int
   public int field_437;
   // $VF: renamed from: n int
   public int field_438;
   // $VF: renamed from: o int
   public int field_439;
   // $VF: renamed from: p int
   public int field_440;
   // $VF: renamed from: q int
   public int field_441;
   // $VF: renamed from: a boolean
   public boolean field_442;
   // $VF: renamed from: b boolean
   public boolean field_443;
   // $VF: renamed from: a dn[]
   public class_51[] field_444;
   // $VF: renamed from: a aa[]
   public class_46[] field_445;
   // $VF: renamed from: r int
   public int field_446;
   // $VF: renamed from: s int
   public int field_447;
   // $VF: renamed from: t int
   public int field_448;
   // $VF: renamed from: u int
   public int field_449;
   // $VF: renamed from: v int
   public int field_450;
   // $VF: renamed from: b dn[]
   private class_51[] field_451;

   public class_32(int var1, int var2, int var3, int var4, int var5, float var6) {
      this.field_422 = var1;
      this.field_423 = var2;
      this.field_425 = var3;
      this.field_426 = 0;
      this.field_427 = var4;
      this.field_424 = var4;
      this.field_428 = var5;
      this.field_429 = var6;
      this.field_444 = new class_51[var5];
      this.field_445 = null;
      this.field_443 = false;
      this.method_378();
   }

   // $VF: renamed from: a () int
   public final int method_363() {
      return this.field_422 == 10 && class_58.method_564() ? 50000 : this.field_427;
   }

   // $VF: renamed from: b () int
   public final int method_364() {
      return this.field_423 + this.field_430 + this.field_431;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_365() {
      return this.field_436 > 0;
   }

   // $VF: renamed from: c () int
   public final int method_366() {
      return (int)(275.0F + (int)(275.0F * this.field_440) / 100.0F);
   }

   // $VF: renamed from: d () int
   public final int method_367() {
      return this.field_425 + this.field_433;
   }

   // $VF: renamed from: a (aa[]) void
   public final void method_368(class_46[] var1) {
      this.field_445 = var1;
      this.field_426 = 0;

      for (int var2 = 0; var2 < this.field_445.length; var2++) {
         this.field_426 = this.field_426 + this.field_445[var2].field_636;
      }

      this.method_378();
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_369(int var1) {
      if (this.field_444 == null) {
         return false;
      } else {
         for (int var2 = 0; var2 < this.field_444.length; var2++) {
            if (this.field_444[var2] != null && this.field_444[var2].field_711 == var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_370(int var1, int var2) {
      boolean var3 = false;

      for (int var4 = 0; var4 < this.field_445.length; var4++) {
         if (this.field_445[var4].field_626 == var1) {
            this.field_445[var4].method_444(-var2);
            if (this.field_445[var4].field_636 <= 0) {
               var3 = true;
            }
            break;
         }
      }

      if (var3) {
         this.method_371(class_46.method_452(this.field_445, true));
      } else {
         this.method_371(this.field_445);
      }

      return var3;
   }

   // $VF: renamed from: b (aa[]) void
   public final void method_371(class_46[] var1) {
      this.field_445 = var1;
      this.field_426 = 0;
      if (var1 != null) {
         for (int var2 = 0; var2 < this.field_445.length; var2++) {
            this.field_426 = this.field_426 + this.field_445[var2].field_636;
         }
      }

      this.method_378();
   }

   // $VF: renamed from: b (int) boolean
   public final boolean method_372(int var1) {
      return this.field_426 + var1 <= this.field_425 + this.field_433;
   }

   // $VF: renamed from: a (aa) void
   public final void method_373(class_46 var1) {
      this.method_374(new class_46[]{var1});
   }

   // $VF: renamed from: c (aa[]) void
   public final void method_374(class_46[] var1) {
      this.method_371(class_46.method_454(this.field_445, var1));
   }

   // $VF: renamed from: a (dn[]) void
   public final void method_375(class_51[] var1) {
      this.field_444 = var1;
      this.method_378();
   }

   // $VF: renamed from: b (dn[]) void
   public final void method_376(class_51[] var1) {
      for (int var2 = 0; var2 < var1.length; var2++) {
         this.method_377(var1[var2]);
      }
   }

   // $VF: renamed from: a (dn) void
   public final void method_377(class_51 var1) {
      for (int var2 = 0; var2 < this.field_444.length; var2++) {
         if (this.field_444[var2] == null) {
            this.field_444[var2] = var1;
            break;
         }
      }

      this.method_378();
   }

   // $VF: renamed from: a () void
   public final void method_378() {
      this.field_442 = false;
      this.field_430 = 0;
      this.field_432 = 0;
      this.field_433 = 0;
      this.field_435 = 0;
      this.field_437 = 0;
      this.field_436 = 0;
      this.field_438 = 0;
      this.field_439 = 0;
      this.field_440 = 0;
      this.field_431 = 0;
      this.field_441 = 0;
      this.field_448 = 22000;
      this.field_449 = 23000;
      this.field_446 = class_44.method_436(this.field_448);
      this.field_447 = class_44.method_436(this.field_449);
      this.method_379();
      this.field_424 = this.field_427;

      for (int var1 = 0; var1 < this.field_444.length; var1++) {
         if (this.field_444[var1] != null) {
            switch (this.field_444[var1].field_710) {
               case 0:
               case 1:
                  this.field_441 = this.field_441 + this.field_444[var1].field_716;
               case 2:
               default:
                  break;
               case 3:
                  this.field_430 = this.field_444[var1].field_716;
                  this.field_432 = this.field_444[var1].field_717;
                  this.field_448 = this.field_444[var1].field_718;
                  this.field_446 = class_44.method_436(this.field_448);
                  break;
               case 4:
                  this.field_431 = this.field_444[var1].field_716;
                  this.field_449 = this.field_444[var1].field_717;
                  this.field_447 = class_44.method_436(this.field_449);
                  break;
               case 5:
                  this.field_433 = this.field_433 + this.field_444[var1].field_716;
                  break;
               case 6:
                  this.field_440 = this.field_444[var1].field_716;
                  break;
               case 7:
                  this.field_439 = this.field_444[var1].field_716;
                  break;
               case 8:
                  this.field_435 = this.field_444[var1].field_716;
                  break;
               case 9:
                  this.field_436 = this.field_444[var1].field_716;
                  this.field_438 = this.field_444[var1].field_717;
                  this.field_437 = this.field_444[var1].field_718;
                  break;
               case 10:
                  this.field_442 = true;
            }

            this.field_424 = this.field_424 + this.field_444[var1].method_501();
         }
      }

      this.field_434 = this.field_433;
      this.field_433 = (int)((float)this.field_425 * this.field_433 / 100.0F);
      this.field_424 = this.field_424 + this.method_381();
   }

   // $VF: renamed from: b () void
   public final void method_379() {
      this.field_451 = new class_51[this.method_384()];
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_444.length; var2++) {
         if (this.field_444[var2] != null && this.field_444[var2].method_503()) {
            this.field_451[var1++] = this.field_444[var2];
         }
      }
   }

   // $VF: renamed from: e () int
   public final int method_380() {
      int var1 = 0;
      if (this.field_445 != null) {
         for (int var2 = 0; var2 < this.field_445.length; var2++) {
            if (this.field_445[var2] != null) {
               var1 += (int)((float)this.field_445[var2].field_636 * this.field_445[var2].field_632);
            }
         }
      }

      this.field_445 = null;
      this.field_426 = 0;
      return var1;
   }

   // $VF: renamed from: f () int
   public final int method_381() {
      int var1 = 0;
      if (this.field_445 != null) {
         for (int var2 = 0; var2 < this.field_445.length; var2++) {
            if (this.field_445[var2] != null) {
               var1 += this.field_445[var2].method_442();
            }
         }
      }

      return var1;
   }

   // $VF: renamed from: b (dn) void
   public final void method_382(class_51 var1) {
      for (int var2 = 0; var2 < this.field_444.length; var2++) {
         if (this.field_444[var2] != null && this.field_444[var2].method_507(var1)) {
            this.field_444[var2] = null;
            break;
         }
      }

      this.method_378();
   }

   // $VF: renamed from: g () int
   public final int method_383() {
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_444.length; var2++) {
         if (this.field_444[var2] != null) {
            var1++;
         }
      }

      return var1;
   }

   // $VF: renamed from: h () int
   public final int method_384() {
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_444.length; var2++) {
         if (this.field_444[var2] != null && this.field_444[var2].method_503()) {
            var1++;
         }
      }

      return var1;
   }

   // $VF: renamed from: c (int) boolean
   public final boolean method_385(int var1) {
      if (var1 != 5 && var1 != 0) {
         for (int var2 = 0; var2 < this.field_444.length; var2++) {
            if (this.field_444[var2] != null && this.field_444[var2].field_710 == var1) {
               return false;
            }
         }

         return true;
      } else {
         return true;
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_386() {
      for (int var1 = 0; var1 < this.field_444.length; var1++) {
         if (this.field_444[var1] == null) {
            return true;
         }
      }

      return false;
   }

   // $VF: renamed from: a () be
   public final class_32 method_387() {
      return this.method_390();
   }

   // $VF: renamed from: c () void
   public final void method_388() {
      this.field_427 = (int)(class_24.method_313()[this.field_422].method_363() / 1.25F);
   }

   // $VF: renamed from: d () void
   public final void method_389() {
      if (class_3.method_110() != null) {
         this.field_427 = class_24.method_313()[this.field_422].method_363()
            - (int)(class_3.method_110().field_833 / 100.0F * class_24.method_313()[this.field_422].method_363());
      }
   }

   // $VF: renamed from: b () be
   public final class_32 method_390() {
      return new class_32(this.field_422, this.field_423, this.field_425, this.field_427, this.field_428, this.field_429);
   }
}
