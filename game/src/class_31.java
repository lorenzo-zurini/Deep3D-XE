// $VF: renamed from: dk
public final class class_31 {
   // $VF: renamed from: a cq
   public class_42 field_412;
   // $VF: renamed from: a int
   public int field_413;
   // $VF: renamed from: b int
   public int field_414;
   // $VF: renamed from: c int
   private int field_415;
   // $VF: renamed from: d int
   private int field_416;
   // $VF: renamed from: a int[]
   private int[] field_417;
   // $VF: renamed from: a dh
   private class_15 field_418;
   // $VF: renamed from: a boolean
   public boolean field_419;
   // $VF: renamed from: b boolean
   public boolean field_420;
   // $VF: renamed from: e int
   private int field_421;

   public class_31(int var1, int var2, int var3, int var4) {
      this.field_413 = var1;
      this.field_414 = var2;
      this.field_415 = var3;
      this.field_416 = var4;
      this.field_417 = new int[]{var4};
      this.field_419 = false;
      this.field_420 = false;
   }

   public class_31(int var1, int var2, int var3, int[] var4) {
      this.field_413 = var1;
      this.field_414 = var2;
      this.field_415 = var3;
      this.field_416 = var4[0];
      this.field_417 = var4;
      this.field_419 = false;
   }

   // $VF: renamed from: a () void
   public final void method_361() {
      this.field_420 = true;
   }

   // $VF: renamed from: a (long, bb) boolean
   public final boolean method_362(long var1, class_16 var3) {
      if (this.field_419) {
         return false;
      } else {
         boolean var4;
         var4 = false;
         label201:
         switch (this.field_415) {
            case 0:
               if (var3.field_215 != null) {
                  var4 = var3.field_215.field_184 > this.field_421 && this.field_421 == this.field_416;
                  this.field_421 = var3.field_215.field_184;
               }
               break;
            case 1:
               class_96[] var5 = var3.field_202.field_1253;

               for (int var13 = 0; var13 < this.field_417.length; var13++) {
                  if (var5[this.field_417[var13]].method_824()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 2:
               class_96[] var18 = var3.field_202.field_1254;

               for (int var20 = 0; var20 < this.field_417.length; var20++) {
                  if (var18[this.field_417[var20]].method_824()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 3:
               var4 = var3.field_214.field_783 <= 0;
               break;
            case 4:
               var4 = var3.field_214.field_784 <= 0;
               break;
            case 5:
               var4 = var1 >= this.field_416;
               break;
            case 6:
               var4 = this.field_412.method_419(this.field_416).field_419;
            case 7:
            default:
               break;
            case 8:
               class_96[] var19 = var3.field_202.field_1253;

               for (int var22 = 0; var22 < this.field_417.length; var22++) {
                  if (!var19[var22].method_800() && var19[this.field_417[var22]].field_1268) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 9:
               var4 = true;
               class_96[] var17 = var3.field_202.field_1253;

               for (int var8 = 0; var8 < this.field_417.length; var8++) {
                  if (!var17[this.field_417[var8]].method_824()) {
                     var4 = false;
                     break label201;
                  }
               }
               break;
            case 10:
               class_96[] var21 = var3.field_202.field_1254;

               for (int var24 = 0; var24 < this.field_417.length; var24++) {
                  if (var21[this.field_417[var24]].field_1268) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 11:
               var4 = this.field_418.method_227((int)var1);
               break;
            case 12:
               class_96[] var12 = var3.field_202.field_1253;

               for (int var16 = 0; var16 < this.field_417.length; var16++) {
                  if (var12[this.field_417[var16]].field_1256 < var12[this.field_417[var16]].field_1257 / 2) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 13:
               var4 = class_3.method_100() > 0;
               break;
            case 14:
               var4 = ((class_85)var3.field_202.field_1253[this.field_416].field_1272).method_760();
               break;
            case 15:
               var4 = false;
               class_96[] var15 = var3.field_202.field_1253;

               for (int var23 = 0; var23 < var15.length; var23++) {
                  if (var15[var23].method_824() && !var15[var23].method_800()) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 16:
               class_96[] var9 = var3.field_202.field_1253;

               for (int var10 = 0; var10 < var9.length; var10++) {
                  if (!var9[var10].method_800() && var9[var10].field_1268) {
                     var4 = true;
                     break label201;
                  }
               }
               break;
            case 17:
               class_96[] var14 = var3.field_202.field_1253;
               var4 = true;

               for (int var11 = 0; var11 < var14.length; var11++) {
                  if (var11 != this.field_416 && !var14[var11].method_800() && !var14[var11].method_824()) {
                     var4 = false;
                     break label201;
                  }
               }
               break;
            case 18:
               var4 = ((class_85)var3.field_202.field_1253[this.field_416].field_1272).method_761()
                  || ((class_85)var3.field_202.field_1253[this.field_416].field_1272).field_1151;
               break;
            case 19:
               class_96[] var6 = var3.field_202.field_1253;

               for (int var7 = 0; var7 < this.field_417.length; var7++) {
                  if (var6[this.field_417[var7]].field_1256 < var6[this.field_417[var7]].field_1257 / 4 * 3) {
                     var4 = true;
                     break;
                  }
               }
         }

         this.field_419 = var4;
         if (this.field_419) {
            this.field_412.field_546 = this;
         }

         return var4;
      }
   }
}
