// $VF: renamed from: aw
public abstract class class_83 {
   // $VF: renamed from: a short
   public short field_1101 = 0;
   // $VF: renamed from: a cm
   public class_96 field_1102;
   // $VF: renamed from: a ay
   public class_101 field_1103;
   // $VF: renamed from: a int
   public int field_1104;
   // $VF: renamed from: a boolean
   public boolean field_1105;
   // $VF: renamed from: a cy
   public class_57 field_1106;
   // $VF: renamed from: a dr
   public class_13 field_1107;
   // $VF: renamed from: a ao
   public class_8 field_1108;
   // $VF: renamed from: a v
   public class_5 field_1109 = new class_5();
   // $VF: renamed from: b v
   public class_5 field_1110 = new class_5();
   // $VF: renamed from: b int
   public int field_1111;
   // $VF: renamed from: c int
   public int field_1112;
   // $VF: renamed from: d int
   public int field_1113;
   // $VF: renamed from: b boolean
   public boolean field_1114;
   // $VF: renamed from: c boolean
   public boolean field_1115;
   // $VF: renamed from: d boolean
   public boolean field_1116;
   // $VF: renamed from: a aa
   public class_46 field_1117;

   public class_83(int var1, boolean var2, class_96 var3, class_101 var4, int var5, int var6, int var7) {
      this.field_1102 = var3;
      this.field_1103 = var4;
      this.field_1104 = var1;
      this.field_1105 = var2;
      if (this.field_1103 != null) {
         this.field_1103.method_841(var5, var6, var7);
         this.field_1103.method_860(0, 0, 0);
         this.field_1102.field_1270 = var4.field_1283;
      }

      this.field_1102.field_1272 = this;
      this.field_1111 = var5;
      this.field_1112 = var6;
      this.field_1113 = var7;
      this.field_1115 = false;
      this.field_1116 = false;
      this.field_1114 = false;
      if (this.field_1109 == null) {
         this.field_1109 = new class_5();
      }
   }

   // $VF: renamed from: a () void
   public void method_741() {
      this.field_1102 = null;
      if (this.field_1103 != null) {
         this.field_1103.method_884();
      }

      this.field_1103 = null;
      this.field_1106 = null;
      this.field_1107 = null;
      if (this.field_1108 != null) {
         this.field_1108.method_193();
      }

      this.field_1108 = null;
   }

   // $VF: renamed from: a (boolean) void
   public void method_742(boolean var1) {
      this.field_1102.field_1268 = var1;
   }

   // $VF: renamed from: a (int) void
   public void method_743(int var1) {
   }

   // $VF: renamed from: a (cm[]) void
   public final void method_744(class_96[] var1) {
      this.field_1102.method_802(var1);
   }

   // $VF: renamed from: a (o, int) void
   public final void method_745(class_19 var1, int var2) {
      this.field_1102.method_825(var1, var2);
   }

   // $VF: renamed from: a (v) v
   public class_5 method_746(class_5 var1) {
      return this.field_1103.method_847();
   }

   // $VF: renamed from: a () boolean
   public final boolean method_747() {
      return this.field_1101 == 4;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_748() {
      return this.field_1101 == 3;
   }

   // $VF: renamed from: d () void
   public final void method_749() {
      this.field_1101 = 4;
   }

   // $VF: renamed from: e () void
   public final void method_750() {
      this.field_1101 = 5;
      this.field_1102.field_1268 = false;
   }

   // $VF: renamed from: f () void
   public final void method_751() {
      this.field_1101 = 1;
      this.field_1102.field_1268 = true;
   }

   // $VF: renamed from: a (long) void
   public abstract void method_752(long var1);

   // $VF: renamed from: a (int, int, int) boolean
   public abstract boolean method_753(int var1, int var2, int var3);

   // $VF: renamed from: a (v) boolean
   public boolean method_754(class_5 var1) {
      return false;
   }

   // $VF: renamed from: b (v) v
   public class_5 method_755(class_5 var1) {
      return null;
   }

   // $VF: renamed from: c () void
   public void method_756() {
      class_41.field_527.method_265(this.field_1103);
   }
}
