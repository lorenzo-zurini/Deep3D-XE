// $VF: renamed from: cr
public final class class_34 {
   // $VF: renamed from: a dk[]
   private class_20[] field_342;
   // $VF: renamed from: a dk
   public class_20 field_343;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_344;
   // $VF: renamed from: a byte[]
   private byte[] field_345;
   // $VF: renamed from: a long
   private long field_346;
   // $VF: renamed from: a int
   private int field_347;
   // $VF: renamed from: a java.lang.String
   private String field_348;

   // $VF: renamed from: a () void
   public final void method_297() {
      this.field_342 = null;
      this.field_343 = null;
   }

   // $VF: renamed from: a (dk[]) void
   public final void method_298(class_20[] var1) {
      this.field_342 = var1;
      if (var1 != null) {
         for (int var2 = 0; var2 < var1.length; var2++) {
            var1[var2].field_177 = this;
         }
      }
   }

   // $VF: renamed from: a (int) dk
   public final class_20 method_299(int var1) {
      return this.field_342[var1];
   }

   // $VF: renamed from: a (long, ba) void
   public final void method_300(long var1, class_70 var3) {
      if (this.field_342 != null) {
         for (int var4 = 0; var4 < this.field_342.length; var4++) {
            if (this.field_342[var4].method_126(var1, var3)) {
               this.field_345 = class_90.field_1218[this.field_342[var4].field_179];
               if (this.field_345 == null) {
                  this.field_345 = class_21.method_215();
               }

               class_119.method_921(this.field_345);
               this.field_344 = class_58.method_532(
                  class_21.method_219(class_84.field_1116.method_4(this.field_342[var4].field_178), class_21.method_213()),
                  class_84.field_1120 - class_119.field_1458 - 10
               );
               this.field_346 = var1;
               this.field_347 = this.field_344.length * 2000 + 1500;
               class_84.field_1122.method_770(10);
               return;
            }
         }
      }
   }

   // $VF: renamed from: b (long, ba) void
   public final void method_301(long var1, class_70 var3) {
      if (this.field_343 == null) {
         this.method_300(var1, var3);
      } else {
         if (var1 > this.field_346 + 2000L) {
            try {
               int var4 = this.field_343.field_179;
               this.field_348 = class_90.field_1219[var4];
               if (this.field_348 == "Colonist") {
                  this.field_348 = class_84.field_1116.method_4(238);
               } else if (this.field_348 == "Rebel") {
                  this.field_348 = class_84.field_1116.method_4(239);
               } else if (this.field_348 == "Pirate") {
                  this.field_348 = class_84.field_1116.method_4(240);
               }

               class_67.method_592(
                  var4 == 0 ? class_21.method_213() : this.field_348,
                  0,
                  0,
                  class_84.field_1120 - 1,
                  class_16.method_97(class_119.field_1459 + 16, (this.field_344.length + 2) * class_58.method_527()),
                  true
               );
            } catch (Exception var5) {
               var5.printStackTrace();
            }

            if (this.field_345 == null && class_21.method_217() != null) {
               class_84.field_1117.drawImage(class_21.method_217(), 3, 13, 0);
            } else {
               class_119.method_923(this.field_345, 3, 13, 0);
            }

            class_58.method_521(this.field_344, class_119.field_1458 + 8, 13, 0);
            if (var1 > this.field_346 + 2000L + this.field_347) {
               this.field_346 = 0L;
               this.field_343.method_125();
               this.field_343 = null;
            }
         }
      }
   }
}
