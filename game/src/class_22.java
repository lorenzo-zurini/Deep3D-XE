// $VF: renamed from: dh
public final class class_22 {
   // $VF: renamed from: b int
   private int field_222;
   // $VF: renamed from: c int
   private int field_223;
   // $VF: renamed from: d int
   private int field_224;
   // $VF: renamed from: a cz
   private class_26 field_225;
   // $VF: renamed from: a dh[]
   private class_22[] field_226;
   // $VF: renamed from: a int
   public int field_227;

   public class_22(int var1, int var2, class_26 var3) {
      this.field_222 = var1;
      this.field_223 = var2;
      this.field_225 = var3;
   }

   public class_22(int var1, int var2, int var3, class_26 var4) {
      this(var1, var2, var4);
      this.field_224 = var3;
      if (var1 == 13) {
         this.field_227 = var3;
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_222(int var1) {
      boolean var2 = true;
      if (this.field_226 != null) {
         for (int var3 = 0; var3 < this.field_226.length; var3++) {
            var2 = var2 && this.field_226[var3].method_222(var1);
         }

         if (var2) {
            return true;
         }
      }

      switch (this.field_222) {
         case 0:
            if (var2 && this.field_225.field_281 == 0) {
               return true;
            }

            return false;
         case 1:
            if (var2 && this.field_225.field_273[this.field_223].method_800()) {
               return true;
            }

            return false;
         case 2:
            if (var2 && this.field_225.field_277.method_111().field_1298) {
               return true;
            }

            return false;
         case 3:
            if (var2 && var1 > this.field_223) {
               return true;
            }

            return false;
         case 4:
            if (var2 && this.field_225.field_280[this.field_223].field_184) {
               return true;
            }

            return false;
         case 5:
            if (var2 && this.field_225.field_282 == 0) {
               return true;
            }

            return false;
         case 6:
            if (var2 && this.field_225.field_274[this.field_223].method_800()) {
               return true;
            }

            return false;
         case 7:
            class_91[] var14 = this.field_225.field_273;
            int var4 = 0;

            for (int var15 = 0; var15 < this.field_223; var15++) {
               if (var14[var15].method_800()) {
                  var4++;
               }
            }

            if (var4 == this.field_223) {
               return true;
            }

            return false;
         case 8:
            class_91[] var5 = this.field_225.field_275;
            int var17 = 0;

            for (int var18 = 0; var18 < var5.length; var18++) {
               if (var5[var18].method_800()) {
                  var17++;
               }
            }

            if (var17 > this.field_223) {
               return true;
            }

            return false;
         case 9:
            class_91[] var7 = this.field_225.field_275;
            int var16 = 0;

            for (int var19 = 0; var19 < var7.length; var19++) {
               if (((class_101)var7[var19]).field_1326) {
                  var16++;
               }

               if (var19 >= this.field_223) {
                  if (var16 >= this.field_223) {
                     return true;
                  }

                  return false;
               }
            }
            break;
         case 10:
            class_91[] var8 = this.field_225.field_275;
            boolean var6 = false;

            for (int var20 = 0; var20 < var8.length; var20++) {
               if (var8[var20].method_800() && !((class_101)var8[var20]).field_1326) {
                  return true;
               }

               if (var20 >= this.field_223) {
                  return false;
               }
            }
            break;
         case 11:
            return ((class_96)this.field_225.field_273[this.field_223]).method_815();
         case 12:
            return ((class_96)this.field_225.field_273[this.field_223]).field_1285;
         case 13:
            class_91[] var9 = this.field_225.field_275;
            int var10 = 0;

            for (int var21 = 0; var21 < var9.length; var21++) {
               class_101 var23;
               if ((var23 = (class_101)var9[var21]).field_1312.field_391 == this.field_223 && (var9[var21].method_800() || ((class_101)var9[var21]).field_1326)
                  )
                {
                  var10++;
               }
            }

            this.field_227 = this.field_224 - var10;
            if (var10 >= this.field_224) {
               return true;
            }

            return false;
         case 14:
            if (this.field_225.field_287 >= this.field_223) {
               return true;
            }

            return false;
         case 15:
            return this.field_225.field_273[this.field_223].field_1225.field_375;
         case 16:
            class_91[] var11 = this.field_225.field_273;

            for (int var22 = 0; var22 < var11.length; var22++) {
               if (!((class_96)var11[var22]).method_815()) {
                  return false;
               }
            }

            return true;
         case 17:
            class_91[] var12 = this.field_225.field_273;

            for (int var13 = 0; var13 < var12.length; var13++) {
               if (((class_96)var12[var13]).field_1285) {
                  return true;
               }
            }

            return false;
      }

      return false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_223() {
      return this.field_222 == 3;
   }
}
