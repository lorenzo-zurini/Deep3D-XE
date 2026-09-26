// $VF: renamed from: dk
public final class class_20 {
   // $VF: renamed from: a cr
   public class_34 field_177;
   // $VF: renamed from: a int
   public int field_178;
   // $VF: renamed from: b int
   public int field_179;
   // $VF: renamed from: c int
   private int field_180;
   // $VF: renamed from: d int
   private int field_181;
   // $VF: renamed from: a int[]
   private int[] field_182;
   // $VF: renamed from: a dh
   private class_22 field_183;
   // $VF: renamed from: a boolean
   public boolean field_184;
   // $VF: renamed from: b boolean
   public boolean field_185;
   // $VF: renamed from: e int
   private int field_186;

   public class_20(int var1, int var2, int var3, int var4) {
      this.field_178 = var1;
      this.field_179 = var2;
      this.field_180 = var3;
      this.field_181 = var4;
      this.field_182 = new int[]{var4};
      this.field_184 = false;
      this.field_185 = false;
   }

   public class_20(int var1, int var2, int var3, int[] var4) {
      this.field_178 = var1;
      this.field_179 = var2;
      this.field_180 = var3;
      this.field_181 = var4[0];
      this.field_182 = var4;
      this.field_184 = false;
   }

   // $VF: renamed from: a () void
   public final void method_125() {
      this.field_185 = true;
   }

   // $VF: renamed from: a (long, ba) boolean
   public final boolean method_126(long var1, class_70 var3) {
      if (this.field_184) {
         return false;
      } else {
         boolean var4;
         var4 = false;
         label201:
         switch (this.field_180) {
            case 0:
               if (var3.field_982 != null) {
                  var4 = var3.field_982.field_164 > this.field_186 && this.field_186 == this.field_181;
                  this.field_186 = var3.field_982.field_164;
               }
               break;
            case 1:
               class_37[] var5 = var3.field_969.field_360;

               for (int var13 = 0; var13 < this.field_182.length; var13++) {
                  if (var5[this.field_182[var13]].method_345()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 2:
               class_37[] var18 = var3.field_969.field_361;

               for (int var20 = 0; var20 < this.field_182.length; var20++) {
                  if (var18[this.field_182[var20]].method_345()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 3:
               var4 = var3.field_981.field_281 <= 0;
               break;
            case 4:
               var4 = var3.field_981.field_282 <= 0;
               break;
            case 5:
               var4 = var1 >= this.field_181;
               break;
            case 6:
               var4 = this.field_177.method_299(this.field_181).field_184;
            case 7:
            default:
               break;
            case 8:
               class_37[] var19 = var3.field_969.field_360;

               for (int var22 = 0; var22 < this.field_182.length; var22++) {
                  if (!var19[var22].method_321() && var19[this.field_182[var22]].field_375) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 9:
               var4 = true;
               class_37[] var17 = var3.field_969.field_360;

               for (int var8 = 0; var8 < this.field_182.length; var8++) {
                  if (!var17[this.field_182[var8]].method_345()) {
                     var4 = false;
                     break label201;
                  }
               }
               break;
            case 10:
               class_37[] var21 = var3.field_969.field_361;

               for (int var24 = 0; var24 < this.field_182.length; var24++) {
                  if (var21[this.field_182[var24]].field_375) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 11:
               var4 = this.field_183.method_222((int)var1);
               break;
            case 12:
               class_37[] var12 = var3.field_969.field_360;

               for (int var16 = 0; var16 < this.field_182.length; var16++) {
                  if (var12[this.field_182[var16]].field_363 < var12[this.field_182[var16]].field_364 / 2) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 13:
               var4 = class_21.method_170() > 0;
               break;
            case 14:
               var4 = ((class_96)var3.field_969.field_360[this.field_181].field_379).method_815();
               break;
            case 15:
               var4 = false;
               class_37[] var15 = var3.field_969.field_360;

               for (int var23 = 0; var23 < var15.length; var23++) {
                  if (var15[var23].method_345() && !var15[var23].method_321()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 16:
               class_37[] var9 = var3.field_969.field_360;

               for (int var10 = 0; var10 < var9.length; var10++) {
                  if (!var9[var10].method_321() && var9[var10].field_375) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 17:
               class_37[] var14 = var3.field_969.field_360;
               var4 = true;

               for (int var11 = 0; var11 < var14.length; var11++) {
                  if (var11 != this.field_181 && !var14[var11].method_321() && !var14[var11].method_345()) {
                     var4 = false;
                     break label201;
                  }
               }
               break;
            case 18:
               var4 = ((class_96)var3.field_969.field_360[this.field_181].field_379).method_816()
                  || ((class_96)var3.field_969.field_360[this.field_181].field_379).field_1286;
               break;
            case 19:
               class_37[] var6 = var3.field_969.field_360;

               for (int var7 = 0; var7 < this.field_182.length; var7++) {
                  if (var6[this.field_182[var7]].field_363 < var6[this.field_182[var7]].field_364 / 4 * 3) {
                     var4 = true;
                     break;
                  }
               }
         }

         this.field_184 = var4;
         if (this.field_184) {
            this.field_177.field_343 = this;
         }

         return var4;
      }
   }
}
