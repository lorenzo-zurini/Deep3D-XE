// $VF: renamed from: d
public final class class_93 extends class_91 {
   // $VF: renamed from: c x
   private class_3 field_1246 = new class_3();
   // $VF: renamed from: a o
   private class_8 field_1247 = new class_8();
   // $VF: renamed from: a long
   private long field_1248;
   // $VF: renamed from: b long
   private long field_1249;
   // $VF: renamed from: b cm
   private class_37 field_1250;
   // $VF: renamed from: a ak
   public class_116 field_1251;

   public class_93(int var1, boolean var2, class_37 var3, class_108 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      super.field_1225.field_377 = var4.field_1341;
      this.field_1246.method_10(var5, var6, var7);
      super.field_1224 = 5;
      var4.method_876(0, 0);
      var4.method_878();
   }

   // $VF: renamed from: a () void
   public final void method_794() {
      super.method_794();
      this.field_1250 = null;
      this.field_1251 = null;
   }

   // $VF: renamed from: b () void
   public final void method_811() {
      if (this.field_1247.field_72 < 3000.0F && this.field_1247.field_73 < 3000.0F && this.field_1247.field_74 < 3000.0F) {
         this.field_1250.method_343(25);
      }

      super.field_1224 = 999;
      if (super.field_1231 != null) {
         super.field_1231.method_741(super.field_1226.method_850().field_37, super.field_1226.method_850().field_38, super.field_1226.method_850().field_39);
      }

      super.field_1225.field_375 = false;
      super.field_1229.method_257(super.field_1227, super.field_1225.field_383);
   }

   // $VF: renamed from: a (long) void
   public final void method_805(long var1) {
      if (super.field_1224 != 4) {
         this.field_1248 = var1;
         super.field_1225.field_377 = super.field_1226.field_1341;
         if (super.field_1224 != 4 && super.field_1224 != 3 && super.field_1224 != 999) {
            super.field_1225.method_353(var1);
            class_37[] var3 = super.field_1225.field_360;
            if (super.field_1225.field_360 != null) {
               int var4 = 0;
               this.field_1250 = null;

               for (int var5 = 0; var5 < var3.length; var5++) {
                  if (var3[var5].field_375) {
                     super.field_1232 = var3[var5].method_344(super.field_1232);
                     this.field_1246 = super.field_1226.method_848(this.field_1246);
                     this.field_1247.field_72 = this.field_1246.field_37 - super.field_1232.field_37;
                     this.field_1247.field_73 = this.field_1246.field_38 - super.field_1232.field_38;
                     this.field_1247.field_74 = this.field_1246.field_39 - super.field_1232.field_39;
                     if (super.field_1224 != 1
                        && this.field_1247.field_72 < 3000.0F
                        && this.field_1247.field_72 > -3000.0F
                        && this.field_1247.field_73 < 3000.0F
                        && this.field_1247.field_73 > -3000.0F
                        && this.field_1247.field_74 < 3000.0F
                        && this.field_1247.field_74 > -3000.0F) {
                        super.field_1224 = 1;
                        super.field_1226.method_876(1, 1);
                        super.field_1226.method_877((byte)2);
                        this.field_1249 = 0L;
                        super.field_1225.method_327(super.field_1225.field_364);
                        class_84.field_1122.method_770(11);
                        var4 = var5;
                        break;
                     }
                  }
               }

               this.field_1250 = super.field_1225.method_326(var4);
            }

            if (super.field_1225.field_363 <= 0 && super.field_1224 != 5 && super.field_1224 != 3 && super.field_1224 != 4) {
               super.field_1225.field_375 = false;
               super.field_1229.method_257(super.field_1227, super.field_1225.field_383);
               super.field_1224 = 3;
               this.field_1249 = 0L;
               if (this.field_1251 != null) {
                  this.field_1251.method_909(this.field_1246.field_37, this.field_1246.field_38, this.field_1246.field_39);
               }
            }
         }

         this.field_1249 += var1;
         super.field_1226.method_843(0, class_16.method_91((int)this.field_1249) >> 6, 0);
         switch (super.field_1224) {
            case 0:
               super.field_1224 = 5;
               return;
            case 1:
               this.field_1249 += var1;
               super.field_1226.method_860(0, (int)var1 << 1, 0);
               if (this.field_1249 > 2000L) {
                  this.method_811();
                  return;
               }
               break;
            case 3:
               if (this.field_1251 != null) {
                  this.field_1251.method_895(var1);
               }

               this.field_1249 += var1;
               if (this.field_1249 > 2000L) {
                  super.field_1224 = 4;
                  super.field_1225.method_327(0);
               }
            case 4:
            default:
               break;
            case 5:
               super.field_1225.method_327(super.field_1225.field_364);
               return;
            case 999:
               super.field_1226.method_868(2048, 2048, 2048);
               super.field_1226.method_860(0, (int)var1 << 1, 0);
               if (super.field_1231 == null) {
                  super.field_1224 = 4;
                  super.field_1225.method_327(0);
                  return;
               }

               if (super.field_1231.method_743()) {
                  super.field_1224 = 4;
                  super.field_1225.method_327(0);
                  return;
               }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_809() {
      if (super.field_1224 != 4) {
         if (deep3dBeyondPhoneFar(super.field_1226)) { // Deep3D-PC
         } else if (super.field_1224 == 5) {
            class_84.field_1110.method_25(super.field_1226);
         } else if (super.field_1224 != 3 && super.field_1224 != 4) {
            class_84.field_1110.method_25(super.field_1226);
         }

         if (super.field_1224 == 3 && this.field_1251 != null) {
            this.field_1251.method_887();
         }

         if (super.field_1224 == 999 && super.field_1231 != null) {
            super.field_1231.method_742(this.field_1248);
         }
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_806(int var1, int var2, int var3) {
      return false;
   }
}
