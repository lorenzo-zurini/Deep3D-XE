// $VF: renamed from: cq
public final class class_42 {
   // $VF: renamed from: a dk[]
   private class_31[] field_545;
   // $VF: renamed from: a dk
   public class_31 field_546;
   // $VF: renamed from: a java.lang.String[]
   private String[] field_547;
   // $VF: renamed from: a byte[]
   private byte[] field_548;
   // $VF: renamed from: a long
   private long field_549;
   // $VF: renamed from: a int
   private int field_550;
   // $VF: renamed from: a java.lang.String
   private String field_551;

   // $VF: renamed from: a () void
   public final void method_417() {
      this.field_545 = null;
      this.field_546 = null;
   }

   // $VF: renamed from: a (dk[]) void
   public final void method_418(class_31[] var1) {
      this.field_545 = var1;
      if (var1 != null) {
         for (int var2 = 0; var2 < var1.length; var2++) {
            var1[var2].field_412 = this;
         }
      }
   }

   // $VF: renamed from: a (int) dk
   public final class_31 method_419(int var1) {
      return this.field_545[var1];
   }

   // $VF: renamed from: a (long, bb) void
   public final void method_420(long var1, class_16 var3) {
      if (this.field_545 != null) {
         for (int var4 = 0; var4 < this.field_545.length; var4++) {
            if (this.field_545[var4].method_362(var1, var3)) {
               this.field_548 = class_24.field_374[this.field_545[var4].field_414];
               if (this.field_548 == null) {
                  this.field_548 = class_3.method_145();
               }

               class_119.method_926(this.field_548);
               this.field_547 = class_50.method_499(
                  class_3.method_149(class_41.field_533.method_297(this.field_545[var4].field_413), class_3.method_143()),
                  class_41.field_537 - class_119.field_1504 - 10
               );
               this.field_549 = var1;
               this.field_550 = this.field_547.length * 2000 + 1500;
               class_41.field_539.method_427(10);
               return;
            }
         }
      }
   }

   // $VF: renamed from: b (long, bb) void
   public final void method_421(long var1, class_16 var3) {
      if (this.field_546 == null) {
         this.method_420(var1, var3);
      } else {
         if (var1 > this.field_549 + 2000L) {
            try {
               int var4 = this.field_546.field_414;
               this.field_551 = class_24.field_375[var4];
               if (this.field_551 == "Colonist") {
                  this.field_551 = class_41.field_533.method_297(238);
               } else if (this.field_551 == "Rebel") {
                  this.field_551 = class_41.field_533.method_297(239);
               } else if (this.field_551 == "Pirate") {
                  this.field_551 = class_41.field_533.method_297(240);
               }

               class_69.method_668(
                  var4 == 0 ? class_3.method_143() : this.field_551,
                  0,
                  0,
                  class_41.field_537 - 1,
                  class_124.method_942(class_119.field_1505 + 16, (this.field_547.length + 2) * class_50.method_494()),
                  true
               );
            } catch (Exception var5) {
               var5.printStackTrace();
            }

            if (this.field_548 == null && class_3.method_147() != null) {
               class_41.field_534.drawImage(class_3.method_147(), 3, 13, 0);
            } else {
               class_119.method_928(this.field_548, 3, 13, 0);
            }

            class_50.method_488(this.field_547, class_119.field_1504 + 8, 13, 0);
            if (var1 > this.field_549 + 2000L + this.field_550) {
               this.field_549 = 0L;
               this.field_546.method_361();
               this.field_546 = null;
            }
         }
      }
   }
}
