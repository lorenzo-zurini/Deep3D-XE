// $VF: renamed from: dm
public final class class_107 extends class_106 {
   // $VF: renamed from: a cz
   public class_7 field_1329;
   // $VF: renamed from: a aq
   public class_82 field_1330;
   // $VF: renamed from: b v
   private static class_5 field_1331;
   // $VF: renamed from: d v
   private static class_5 field_1332;
   // $VF: renamed from: e v
   private static class_5 field_1333 = new class_5();
   // $VF: renamed from: f int
   private static int field_1334;
   // $VF: renamed from: g int
   private static int field_1335;
   // $VF: renamed from: h int
   private static int field_1336;
   // $VF: renamed from: d boolean
   private boolean field_1337;

   public class_107(class_19 var1, class_101 var2, int var3, boolean var4) {
      super(var1, null, 1000);
      new class_1();
      this.field_1329 = new class_7();
      this.field_1330 = new class_82();
      super.field_1327 = var2;
      super.field_1327.method_865(8192, 8192, 8192);
      this.field_1337 = var4;
      field_1331 = new class_5();
   }

   // $VF: renamed from: d () void
   public final void method_884() {
      super.method_884();
      if (this.field_1329 != null) {
         this.field_1329.method_189();
      }

      this.field_1329 = null;
      if (this.field_1330 != null) {
         this.field_1330.method_736();
      }

      this.field_1330 = null;
   }

   // $VF: renamed from: c () void
   public final void method_878() {
      super.field_1325.method_288();
      if (super.field_1325.field_293) {
         this.field_1330.method_740();
         class_41.field_527.method_265(super.field_1327);
      }

      this.field_1329.method_192();
   }

   // $VF: renamed from: a (long) void
   public final void method_885(long var1) {
      super.field_1325.method_287(var1);
      field_1331.method_169(super.field_1325.field_279[0]);
      if (super.field_1325.field_289) {
         this.field_1330.method_739(field_1331);
         super.field_1325.field_289 = false;
      }

      super.field_1327.method_842(field_1331);
      class_106.field_1328.method_169(super.field_1325.field_280[0]);
      class_106.field_1328.method_182();
      super.field_1327.field_1283.method_44(class_106.field_1328);
      if (super.field_1325.field_293) {
         if (this.field_1337 && super.field_1325.field_284[0] < super.field_1325.field_287 - 1500) {
            this.method_891(var1);
         }

         field_1331.method_169(super.field_1325.field_279[0]);
         this.field_1329.method_190(field_1331, (int)var1 / 4);
         this.field_1330.method_738(field_1331);
         if (field_1331.field_140 == 50000) {
            super.field_1325.field_293 = false;
         }
      }
   }

   // $VF: renamed from: b (long) void
   private void method_891(long var1) {
      class_96[] var3 = super.field_1325.field_278;
      if (super.field_1325.field_278 != null) {
         int var4 = -1;
         int var5 = Integer.MAX_VALUE;

         for (int var6 = 0; var6 < var3.length; var6++) {
            if (var3[var6].field_1268 && !var3[var6].method_824() && !var3[var6].method_800()) {
               field_1332 = super.field_1325.field_279[0];
               field_1331 = var3[var6].method_823(field_1331);
               field_1334 = field_1332.field_138 - field_1331.field_138;
               field_1335 = field_1332.field_139 - field_1331.field_139;
               field_1336 = field_1332.field_140 - field_1331.field_140;
               int var7;
               if (field_1334 < 15000
                  && field_1334 > -15000
                  && field_1335 < 15000
                  && field_1335 > -15000
                  && field_1336 < 15000
                  && field_1336 > -15000
                  && (var7 = field_1334 * field_1334 + field_1335 * field_1335 + field_1336 * field_1336) < var5) {
                  var4 = var6;
                  var5 = var7;
               }
            }
         }

         if (var4 < 0) {
            return;
         }

         field_1331 = var3[var4].method_823(field_1331);
         class_106.field_1328.field_138 = field_1331.field_138 - super.field_1325.field_279[0].field_138;
         class_106.field_1328.field_139 = field_1331.field_139 - super.field_1325.field_279[0].field_139;
         class_106.field_1328.field_140 = field_1331.field_140 - super.field_1325.field_279[0].field_140;
         field_1333.method_169(super.field_1325.field_280[0]);
         class_106.field_1328.method_177(field_1333);
         class_106.field_1328.method_178((int)var1);
         super.field_1325.field_280[0] = field_1333.method_174(class_106.field_1328, super.field_1325.field_280[0]);
         super.field_1325.field_280[0].method_182();
         super.field_1325.field_280[0].method_178((int)(super.field_1325.field_286 * (float)var1) << 12);
         super.field_1325.field_280[0].field_138 >>= 12;
         super.field_1325.field_280[0].field_139 >>= 12;
         super.field_1325.field_280[0].field_140 >>= 12;
      }
   }
}
