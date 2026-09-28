// $VF: renamed from: au
public class class_99 extends class_98 {
   // $VF: renamed from: a dp[]
   public class_29[] field_1303;
   // $VF: renamed from: e boolean
   public boolean field_1304;
   // $VF: renamed from: f boolean
   public boolean field_1305;
   // $VF: renamed from: g boolean
   public boolean field_1306;

   public class_99(int var1, class_108 var2, int var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
      super.field_1234 = var3;
      super.field_1235 = var4;
      super.field_1236 = var5;
      if (var2 != null) {
         if (var1 == 15) {
            super.field_1226.field_1367 = 2;
            super.field_1226.method_878();
            super.field_1226.method_874(1);
            this.field_1304 = false;
            this.field_1305 = false;
            super.field_1225.method_322(15000);
         }

         this.field_1303 = new class_29[1];
         this.field_1303[0] = new class_31(var3, var4, var5, 0, 0, 0, 15000, 15000, 8000);
         this.field_1306 = false;
      }
   }

   // $VF: renamed from: b () void
   public final void method_821() {
      this.field_1306 = true;
   }

   // $VF: renamed from: b (int) void
   public final void method_822(int var1) {
      super.field_1226.method_864(0, var1, 0);
   }

   // $VF: renamed from: c () void
   public void method_809() {
      super.method_809();
   }

   // $VF: renamed from: a (long) void
   public void method_805(long var1) {
      if (this.field_1304) {
         if (super.field_1226.method_875() == 19) {
            super.field_1226.method_876(20, 39);
            super.field_1226.method_877((byte)2);
            this.field_1305 = true;
         }
      } else if (!this.field_1305) {
         super.field_1226.method_874(1);
         super.field_1226.method_876(1, 1);
         super.field_1226.method_877((byte)2);
         super.field_1226.method_860(0, 0, (int)var1 >> 1);
      }

      super.field_1232 = class_84.field_1110.field_40.method_849(super.field_1232);
      super.field_1233.method_10(super.field_1300, super.field_1301, super.field_1302);
      super.field_1233.method_16(super.field_1232, class_98.field_1299);
      int var3;
      if ((var3 = class_98.field_1299.method_23()) > 30000) {
         class_98.field_1299.method_22();
         class_98.field_1299.method_18(30000);
         class_98.field_1299.method_15(super.field_1232);
         super.field_1226.method_846(class_98.field_1299);
         int var4 = (int)(30000.0F / var3 * 4096.0F);
         super.field_1226.method_869(var4, var4, var4);
      } else {
         super.field_1226.method_869(4096, 4096, 4096);
         super.field_1226.method_845(super.field_1300, super.field_1301, super.field_1302);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public boolean method_806(int var1, int var2, int var3) {
      if (var1 - super.field_1300 < super.field_1225.field_362
         && var1 - super.field_1300 > -super.field_1225.field_362
         && var2 - super.field_1301 < super.field_1225.field_362
         && var2 - super.field_1301 > -super.field_1225.field_362
         && var3 - super.field_1302 < super.field_1225.field_362
         && var3 - super.field_1302 > -super.field_1225.field_362) {
         this.method_823();
         return true;
      } else {
         this.method_824();
         return false;
      }
   }

   // $VF: renamed from: g () void
   public final void method_823() {
      if (this.field_1306 && !this.field_1304 && class_21.method_132() == class_87.field_1145 || !this.field_1306) {
         super.field_1226.method_876(1, 19);
         super.field_1226.method_874(1);
         super.field_1226.method_877((byte)1);
         this.field_1304 = true;
         class_84.field_1122.method_770(3);
      }
   }

   // $VF: renamed from: h () void
   public final void method_824() {
      if (this.field_1304) {
         super.field_1226.method_876(1, super.field_1226.method_875());
         super.field_1226.method_877((byte)3);
         this.field_1304 = false;
         this.field_1305 = false;
         class_84.field_1122.method_770(3);
      }
   }

   // $VF: renamed from: a (x) boolean
   public boolean method_807(class_3 var1) {
      return this.field_1303 != null ? this.field_1303[0].method_288(var1.field_37, var1.field_38, var1.field_39) : false;
   }

   // $VF: renamed from: b (x) x
   public class_3 method_808(class_3 var1) {
      return this.field_1303 != null ? this.field_1303[0].method_285(var1) : null;
   }
}
