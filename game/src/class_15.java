// $VF: renamed from: dh
public final class class_15 {
   // $VF: renamed from: b int
   private int field_193;
   // $VF: renamed from: c int
   private int field_194;
   // $VF: renamed from: d int
   private int field_195;
   // $VF: renamed from: a cy
   private class_57 field_196;
   // $VF: renamed from: a dh[]
   private class_15[] field_197;
   // $VF: renamed from: a int
   public int field_198;

   public class_15(int var1, int var2, class_57 var3) {
      this.field_193 = var1;
      this.field_194 = var2;
      this.field_196 = var3;
   }

   public class_15(int var1, int var2, int var3, class_57 var4) {
      this(var1, var2, var4);
      this.field_195 = var3;
      if (var1 == 13) {
         this.field_198 = var3;
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_227(int var1) {
      boolean var2 = true;
      if (this.field_197 != null) {
         for (int var3 = 0; var3 < this.field_197.length; var3++) {
            var2 = var2 && this.field_197[var3].method_227(var1);
         }

         if (var2) {
            return true;
         }
      }

      switch (this.field_193) {
         case 0:
            if (var2 && this.field_196.field_783 == 0) {
               return true;
            }

            return false;
         case 1:
            if (var2 && this.field_196.field_775[this.field_194].method_747()) {
               return true;
            }

            return false;
         case 2:
            if (var2 && this.field_196.field_779.method_220().field_1164) {
               return true;
            }

            return false;
         case 3:
            if (var2 && var1 > this.field_194) {
               return true;
            }

            return false;
         case 4:
            if (var2 && this.field_196.field_782[this.field_194].field_419) {
               return true;
            }

            return false;
         case 5:
            if (var2 && this.field_196.field_784 == 0) {
               return true;
            }

            return false;
         case 6:
            if (var2 && this.field_196.field_776[this.field_194].method_747()) {
               return true;
            }

            return false;
         case 7:
            class_83[] var14 = this.field_196.field_775;
            int var4 = 0;

            for (int var15 = 0; var15 < this.field_194; var15++) {
               if (var14[var15].method_747()) {
                  var4++;
               }
            }

            if (var4 == this.field_194) {
               return true;
            }

            return false;
         case 8:
            class_83[] var5 = this.field_196.field_777;
            int var17 = 0;

            for (int var18 = 0; var18 < var5.length; var18++) {
               if (var5[var18].method_747()) {
                  var17++;
               }
            }

            if (var17 > this.field_194) {
               return true;
            }

            return false;
         case 9:
            class_83[] var7 = this.field_196.field_777;
            int var16 = 0;

            for (int var19 = 0; var19 < var7.length; var19++) {
               if (((class_89)var7[var19]).field_1185) {
                  var16++;
               }

               if (var19 >= this.field_194) {
                  if (var16 >= this.field_194) {
                     return true;
                  }

                  return false;
               }
            }
            break;
         case 10:
            class_83[] var8 = this.field_196.field_777;
            boolean var6 = false;

            for (int var20 = 0; var20 < var8.length; var20++) {
               if (var8[var20].method_747() && !((class_89)var8[var20]).field_1185) {
                  return true;
               }

               if (var20 >= this.field_194) {
                  return false;
               }
            }
            break;
         case 11:
            return ((class_85)this.field_196.field_775[this.field_194]).method_760();
         case 12:
            return ((class_85)this.field_196.field_775[this.field_194]).field_1150;
         case 13:
            class_83[] var9 = this.field_196.field_777;
            int var10 = 0;

            for (int var21 = 0; var21 < var9.length; var21++) {
               class_89 var23;
               if ((var23 = (class_89)var9[var21]).field_1171.field_857 == this.field_194 && (var9[var21].method_747() || ((class_89)var9[var21]).field_1185)) {
                  var10++;
               }
            }

            this.field_198 = this.field_195 - var10;
            if (var10 >= this.field_195) {
               return true;
            }

            return false;
         case 14:
            if (this.field_196.field_789 >= this.field_194) {
               return true;
            }

            return false;
         case 15:
            return this.field_196.field_775[this.field_194].field_1102.field_1268;
         case 16:
            class_83[] var11 = this.field_196.field_775;

            for (int var22 = 0; var22 < var11.length; var22++) {
               if (!((class_85)var11[var22]).method_760()) {
                  return false;
               }
            }

            return true;
         case 17:
            class_83[] var12 = this.field_196.field_775;

            for (int var13 = 0; var13 < var12.length; var13++) {
               if (((class_85)var12[var13]).field_1150) {
                  return true;
               }
            }

            return false;
      }

      return false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_228() {
      return this.field_193 == 3;
   }
}
