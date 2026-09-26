// $VF: renamed from: dm
public final class class_113 extends class_112 {
   // $VF: renamed from: a da
   public class_25 field_1413;
   // $VF: renamed from: a ar
   public class_83 field_1414;
   // $VF: renamed from: b x
   private static class_3 field_1415;
   // $VF: renamed from: d x
   private static class_3 field_1416;
   // $VF: renamed from: e x
   private static class_3 field_1417 = new class_3();
   // $VF: renamed from: c int
   private static int field_1418;
   // $VF: renamed from: g int
   private static int field_1419;
   // $VF: renamed from: h int
   private static int field_1420;
   // $VF: renamed from: d boolean
   private boolean field_1421;

   public class_113(class_9 var1, class_108 var2, int var3, boolean var4) {
      super(var1, null, 1000);
      new class_57();
      this.field_1413 = new class_25();
      this.field_1414 = new class_83();
      super.field_1411 = var2;
      super.field_1411.method_869(8192, 8192, 8192);
      this.field_1421 = var4;
      field_1415 = new class_3();
   }

   // $VF: renamed from: c () void
   public final void method_894() {
      super.method_894();
      if (this.field_1413 != null) {
         this.field_1413.method_235();
      }

      this.field_1413 = null;
      if (this.field_1414 != null) {
         this.field_1414.method_731();
      }

      this.field_1414 = null;
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      super.field_1409.method_50();
      if (super.field_1409.field_92) {
         this.field_1414.method_735();
         class_84.field_1110.method_25(super.field_1411);
      }

      this.field_1413.method_238();
   }

   // $VF: renamed from: a (long) void
   public final void method_895(long var1) {
      super.field_1409.method_49(var1);
      field_1415.method_9(super.field_1409.field_78[0]);
      if (super.field_1409.field_88) {
         this.field_1414.method_734(field_1415);
         super.field_1409.field_88 = false;
      }

      super.field_1411.method_846(field_1415);
      class_112.field_1412.method_9(super.field_1409.field_79[0]);
      class_112.field_1412.method_22();
      super.field_1411.field_1341.method_512(class_112.field_1412);
      if (super.field_1409.field_92) {
         if (this.field_1421 && super.field_1409.field_83[0] < super.field_1409.field_86 - 1500) {
            this.method_904(var1);
         }

         field_1415.method_9(super.field_1409.field_78[0]);
         this.field_1413.method_236(field_1415, (int)var1 / 4);
         this.field_1414.method_733(field_1415);
         if (field_1415.field_39 == 50000) {
            super.field_1409.field_92 = false;
         }
      }
   }

   // $VF: renamed from: b (long) void
   private void method_904(long var1) {
      class_37[] var3 = super.field_1409.field_77;
      if (super.field_1409.field_77 != null) {
         int var4 = -1;
         int var5 = Integer.MAX_VALUE;

         for (int var6 = 0; var6 < var3.length; var6++) {
            if (var3[var6].field_375 && !var3[var6].method_345() && !var3[var6].method_321()) {
               field_1416 = super.field_1409.field_78[0];
               field_1415 = var3[var6].method_344(field_1415);
               field_1418 = field_1416.field_37 - field_1415.field_37;
               field_1419 = field_1416.field_38 - field_1415.field_38;
               field_1420 = field_1416.field_39 - field_1415.field_39;
               int var7;
               if (field_1418 < 15000
                  && field_1418 > -15000
                  && field_1419 < 15000
                  && field_1419 > -15000
                  && field_1420 < 15000
                  && field_1420 > -15000
                  && (var7 = field_1418 * field_1418 + field_1419 * field_1419 + field_1420 * field_1420) < var5) {
                  var4 = var6;
                  var5 = var7;
               }
            }
         }

         if (var4 < 0) {
            return;
         }

         field_1415 = var3[var4].method_344(field_1415);
         class_112.field_1412.field_37 = field_1415.field_37 - super.field_1409.field_78[0].field_37;
         class_112.field_1412.field_38 = field_1415.field_38 - super.field_1409.field_78[0].field_38;
         class_112.field_1412.field_39 = field_1415.field_39 - super.field_1409.field_78[0].field_39;
         field_1417.method_9(super.field_1409.field_79[0]);
         class_112.field_1412.method_17(field_1417);
         class_112.field_1412.method_18((int)var1);
         super.field_1409.field_79[0] = field_1417.method_14(class_112.field_1412, super.field_1409.field_79[0]);
         super.field_1409.field_79[0].method_22();
         super.field_1409.field_79[0].method_18((int)(super.field_1409.field_85 * (float)var1) << 12);
         super.field_1409.field_79[0].field_37 >>= 12;
         super.field_1409.field_79[0].field_38 >>= 12;
         super.field_1409.field_79[0].field_39 >>= 12;
      }
   }
}
