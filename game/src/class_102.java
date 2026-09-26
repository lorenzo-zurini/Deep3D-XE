// $VF: renamed from: af
public abstract class class_102 {
   // $VF: renamed from: a int
   public int field_1335 = 32;
   // $VF: renamed from: a v
   public class_103 field_1336 = null;
   // $VF: renamed from: b af
   public class_102 field_1337;
   // $VF: renamed from: a boolean
   public boolean field_1338;
   // $VF: renamed from: b boolean
   public boolean field_1339;
   // $VF: renamed from: c boolean
   public boolean field_1340;
   // $VF: renamed from: a bn
   public class_57 field_1341;
   // $VF: renamed from: b bn
   public class_57 field_1342;
   // $VF: renamed from: a du
   public class_15 field_1343;
   // $VF: renamed from: b int
   public int field_1344;

   public class_102() {
      this.field_1338 = true;
      this.field_1341 = new class_57();
      this.field_1342 = new class_57();
      this.field_1343 = new class_15();
      this.field_1339 = true;
      this.field_1340 = true;
      this.field_1344 = 0;
   }

   public class_102(class_102 var1) {
      this.field_1338 = var1.field_1338;
      this.field_1341 = new class_57(var1.field_1341);
      this.field_1342 = new class_57(var1.field_1342);
      this.field_1343 = new class_15(var1.field_1343);
      this.field_1339 = true;
      this.field_1340 = true;
      this.field_1344 = var1.field_1344;
   }

   // $VF: renamed from: a (an, t) void
   public abstract void method_837(class_106 var1, class_4 var2);

   // $VF: renamed from: b (an, t) void
   public abstract void method_838(class_106 var1, class_4 var2);

   // $VF: renamed from: a (boolean) void
   public abstract void method_839(boolean var1);

   // $VF: renamed from: a () af
   public abstract class_102 method_840();

   // $VF: renamed from: b () void
   public final void method_841() {
      this.field_1340 = true;
      if (this.field_1336 != null) {
         this.field_1336.method_841();
      }
   }

   public final String toString() {
      return this.method_842("" + this.field_1344, 0);
   }

   // $VF: renamed from: a (java.lang.String, int) java.lang.String
   public abstract String method_842(String var1, int var2);

   // $VF: renamed from: a (int, int, int) void
   public final void method_843(int var1, int var2, int var3) {
      this.field_1341.method_474(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a (x) void
   public final void method_844(class_3 var1) {
      this.field_1341.method_475(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: b (int, int, int) void
   public void method_845(int var1, int var2, int var3) {
      this.field_1341.method_476(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: b (x) void
   public final void method_846(class_3 var1) {
      this.field_1341.method_477(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a (int) void
   public final void method_847(int var1) {
      this.field_1341.method_478(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a (x) x
   public final class_3 method_848(class_3 var1) {
      return this.field_1341.method_479(var1);
   }

   // $VF: renamed from: b (x) x
   public final class_3 method_849(class_3 var1) {
      return this.field_1342.method_479(var1);
   }

   // $VF: renamed from: a () x
   public final class_3 method_850() {
      return this.field_1341.method_480();
   }

   // $VF: renamed from: b () x
   public final class_3 method_851() {
      return this.field_1342.method_480();
   }

   // $VF: renamed from: a () int
   public final int method_852() {
      return this.field_1341.field_698;
   }

   // $VF: renamed from: b () int
   public final int method_853() {
      return this.field_1341.field_699;
   }

   // $VF: renamed from: c () int
   public final int method_854() {
      return this.field_1341.field_700;
   }

   // $VF: renamed from: c (x) x
   public final class_3 method_855(class_3 var1) {
      return this.field_1341.method_481(var1);
   }

   // $VF: renamed from: d (x) x
   public final class_3 method_856(class_3 var1) {
      return this.field_1341.method_482(var1);
   }

   // $VF: renamed from: c () x
   public final class_3 method_857() {
      return this.field_1341.method_483();
   }

   // $VF: renamed from: e (x) x
   public final class_3 method_858(class_3 var1) {
      return this.field_1341.method_484(var1);
   }

   // $VF: renamed from: a (short) void
   public final void method_859(short var1) {
      this.field_1341.method_485(var1);
      this.field_1342.method_485(var1);
   }

   // $VF: renamed from: c (int, int, int) void
   public final void method_860(int var1, int var2, int var3) {
      this.field_1341.method_486(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: b (int) void
   public final void method_861(int var1) {
      this.field_1341.method_487(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: c (int) void
   public final void method_862(int var1) {
      this.field_1341.method_489(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: d (int) void
   public final void method_863(int var1) {
      this.field_1341.method_488(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: d (int, int, int) void
   public final void method_864(int var1, int var2, int var3) {
      this.field_1341.method_491(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a () a
   public final class_123 method_865() {
      return this.field_1341.method_499();
   }

   // $VF: renamed from: d () int
   public final int method_866() {
      return this.field_1341.method_492();
   }

   // $VF: renamed from: a (a) void
   public final void method_867(class_123 var1) {
      this.field_1341.method_495(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: e (int, int, int) void
   public final void method_868(int var1, int var2, int var3) {
      this.field_1341.method_500(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: f (int, int, int) void
   public final void method_869(int var1, int var2, int var3) {
      this.field_1341.method_501(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a (bn) void
   public final void method_870(class_57 var1) {
      this.field_1341.method_470(var1);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: a (bn) bn
   public final class_57 method_871(class_57 var1) {
      return this.field_1341.method_503(var1);
   }

   // $VF: renamed from: a (x, x, x) void
   public final void method_872(class_3 var1, class_3 var2, class_3 var3) {
      this.field_1341.method_504(var1, var2, var3);
      this.field_1339 = true;
      this.method_841();
   }

   // $VF: renamed from: e (int) void
   public void method_873(int var1) {
   }

   // $VF: renamed from: f (int) void
   public void method_874(int var1) {
   }

   // $VF: renamed from: e () int
   public int method_875() {
      return 0;
   }

   // $VF: renamed from: a (int, int) void
   public void method_876(int var1, int var2) {
   }

   // $VF: renamed from: a (byte) void
   public void method_877(byte var1) {
   }

   // $VF: renamed from: a () void
   public void method_878() {
   }
}
