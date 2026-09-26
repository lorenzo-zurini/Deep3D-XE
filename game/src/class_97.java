// $VF: renamed from: ae
public abstract class class_97 {
   // $VF: renamed from: a int
   public int field_1277 = 32;
   // $VF: renamed from: a u
   public class_98 field_1278 = null;
   // $VF: renamed from: b ae
   public class_97 field_1279;
   // $VF: renamed from: a boolean
   public boolean field_1280;
   // $VF: renamed from: b boolean
   public boolean field_1281;
   // $VF: renamed from: c boolean
   public boolean field_1282;
   // $VF: renamed from: a bn
   public class_1 field_1283;
   // $VF: renamed from: b bn
   public class_1 field_1284;
   // $VF: renamed from: a du
   public class_29 field_1285;
   // $VF: renamed from: b int
   public int field_1286;

   public class_97() {
      this.field_1280 = true;
      this.field_1283 = new class_1();
      this.field_1284 = new class_1();
      this.field_1285 = new class_29();
      this.field_1281 = true;
      this.field_1282 = true;
      this.field_1286 = 0;
   }

   public class_97(class_97 var1) {
      this.field_1280 = var1.field_1280;
      this.field_1283 = new class_1(var1.field_1283);
      this.field_1284 = new class_1(var1.field_1284);
      this.field_1285 = new class_29(var1.field_1285);
      this.field_1281 = true;
      this.field_1282 = true;
      this.field_1286 = var1.field_1286;
   }

   // $VF: renamed from: a (am, t) void
   public abstract void method_833(class_111 var1, class_17 var2);

   // $VF: renamed from: b (am, t) void
   public abstract void method_834(class_111 var1, class_17 var2);

   // $VF: renamed from: a (boolean) void
   public abstract void method_835(boolean var1);

   // $VF: renamed from: a () ae
   public abstract class_97 method_836();

   // $VF: renamed from: b () void
   public final void method_837() {
      this.field_1282 = true;
      if (this.field_1278 != null) {
         this.field_1278.method_837();
      }
   }

   public final String toString() {
      return this.method_838("" + this.field_1286, 0);
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public abstract String method_838(String var1, int var2);

   // $VF: renamed from: a (int, int, int) void
   public final void method_839(int var1, int var2, int var3) {
      this.field_1283.method_7(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a (v) void
   public final void method_840(class_5 var1) {
      this.field_1283.method_8(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: b (int, int, int) void
   public void method_841(int var1, int var2, int var3) {
      this.field_1283.method_9(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: b (v) void
   public final void method_842(class_5 var1) {
      this.field_1283.method_10(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a (int) void
   public final void method_843(int var1) {
      this.field_1283.method_11(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a (v) v
   public final class_5 method_844(class_5 var1) {
      return this.field_1283.method_12(var1);
   }

   // $VF: renamed from: b (v) v
   public final class_5 method_845(class_5 var1) {
      return this.field_1284.method_12(var1);
   }

   // $VF: renamed from: a () v
   public final class_5 method_846() {
      return this.field_1283.method_13();
   }

   // $VF: renamed from: b () v
   public final class_5 method_847() {
      return this.field_1284.method_13();
   }

   // $VF: renamed from: a () int
   public final int method_848() {
      return this.field_1283.field_13;
   }

   // $VF: renamed from: b () int
   public final int method_849() {
      return this.field_1283.field_14;
   }

   // $VF: renamed from: c () int
   public final int method_850() {
      return this.field_1283.field_15;
   }

   // $VF: renamed from: c (v) v
   public final class_5 method_851(class_5 var1) {
      return this.field_1283.method_14(var1);
   }

   // $VF: renamed from: d (v) v
   public final class_5 method_852(class_5 var1) {
      return this.field_1283.method_15(var1);
   }

   // $VF: renamed from: c () v
   public final class_5 method_853() {
      return this.field_1283.method_16();
   }

   // $VF: renamed from: e (v) v
   public final class_5 method_854(class_5 var1) {
      return this.field_1283.method_17(var1);
   }

   // $VF: renamed from: a (short) void
   public final void method_855(short var1) {
      this.field_1283.method_18(var1);
      this.field_1284.method_18(var1);
   }

   // $VF: renamed from: c (int, int, int) void
   public final void method_856(int var1, int var2, int var3) {
      this.field_1283.method_19(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: b (int) void
   public final void method_857(int var1) {
      this.field_1283.method_20(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: c (int) void
   public final void method_858(int var1) {
      this.field_1283.method_22(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: d (int) void
   public final void method_859(int var1) {
      this.field_1283.method_21(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: d (int, int, int) void
   public final void method_860(int var1, int var2, int var3) {
      this.field_1283.method_24(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a () a
   public final class_61 method_861() {
      return this.field_1283.method_32();
   }

   // $VF: renamed from: d () int
   public final int method_862() {
      return this.field_1283.method_25();
   }

   // $VF: renamed from: a (a) void
   public final void method_863(class_61 var1) {
      this.field_1283.method_28(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: e (int, int, int) void
   public final void method_864(int var1, int var2, int var3) {
      this.field_1283.method_33(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: f (int, int, int) void
   public final void method_865(int var1, int var2, int var3) {
      this.field_1283.method_34(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a (bn) void
   public final void method_866(class_1 var1) {
      this.field_1283.method_3(var1);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: a (bn) bn
   public final class_1 method_867(class_1 var1) {
      return this.field_1283.method_36(var1);
   }

   // $VF: renamed from: a (v, v, v) void
   public final void method_868(class_5 var1, class_5 var2, class_5 var3) {
      this.field_1283.method_37(var1, var2, var3);
      this.field_1281 = true;
      this.method_837();
   }

   // $VF: renamed from: e (int) void
   public void method_869(int var1) {
   }

   // $VF: renamed from: f (int) void
   public void method_870(int var1) {
   }

   // $VF: renamed from: e () int
   public int method_871() {
      return 0;
   }

   // $VF: renamed from: a (int, int) void
   public void method_872(int var1, int var2) {
   }

   // $VF: renamed from: a (byte) void
   public void method_873(byte var1) {
   }

   // $VF: renamed from: a () void
   public void method_874() {
   }
}
