// $VF: renamed from: aw
public abstract class class_91 {
   // $VF: renamed from: a short
   public short field_1224 = 0;
   // $VF: renamed from: a cm
   public class_37 field_1225;
   // $VF: renamed from: a ax
   public class_108 field_1226;
   // $VF: renamed from: a int
   public int field_1227;
   // $VF: renamed from: a boolean
   public boolean field_1228;
   // $VF: renamed from: a cz
   public class_26 field_1229;
   // $VF: renamed from: a dr
   public class_18 field_1230;
   // $VF: renamed from: a ap
   public class_85 field_1231;
   // $VF: renamed from: a x
   public class_3 field_1232 = new class_3();
   // $VF: renamed from: b x
   public class_3 field_1233 = new class_3();
   // $VF: renamed from: b int
   public int field_1234;
   // $VF: renamed from: c int
   public int field_1235;
   // $VF: renamed from: d int
   public int field_1236;
   // $VF: renamed from: b boolean
   public boolean field_1237;
   // $VF: renamed from: c boolean
   public boolean field_1238;
   // $VF: renamed from: d boolean
   public boolean field_1239;
   // $VF: renamed from: a ac
   public class_120 field_1240;

   public class_91(int var1, boolean var2, class_37 var3, class_108 var4, int var5, int var6, int var7) {
      this.field_1225 = var3;
      this.field_1226 = var4;
      this.field_1227 = var1;
      this.field_1228 = var2;
      if (this.field_1226 != null) {
         this.field_1226.method_845(var5, var6, var7);
         this.field_1226.method_864(0, 0, 0);
         this.field_1225.field_377 = var4.field_1341;
      }

      this.field_1225.field_379 = this;
      this.field_1234 = var5;
      this.field_1235 = var6;
      this.field_1236 = var7;
      this.field_1238 = false;
      this.field_1239 = false;
      this.field_1237 = false;
      if (this.field_1232 == null) {
         this.field_1232 = new class_3();
      }
   }

   // $VF: renamed from: a () void
   public void method_794() {
      this.field_1225 = null;
      if (this.field_1226 != null) {
         this.field_1226.method_894();
      }

      this.field_1226 = null;
      this.field_1229 = null;
      this.field_1230 = null;
      if (this.field_1231 != null) {
         this.field_1231.method_738();
      }

      this.field_1231 = null;
   }

   // $VF: renamed from: a (boolean) void
   public void method_795(boolean var1) {
      this.field_1225.field_375 = var1;
   }

   // $VF: renamed from: a (int) void
   public void method_796(int var1) {
   }

   // $VF: renamed from: a (cm[]) void
   public final void method_797(class_37[] var1) {
      this.field_1225.method_323(var1);
   }

   // $VF: renamed from: a (n, int) void
   public final void method_798(class_9 var1, int var2) {
      this.field_1225.method_346(var1, var2);
   }

   // $VF: renamed from: a (x) x
   public class_3 method_799(class_3 var1) {
      return this.field_1226.method_851();
   }

   // $VF: renamed from: a () boolean
   public final boolean method_800() {
      return this.field_1224 == 4;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_801() {
      return this.field_1224 == 3;
   }

   // $VF: renamed from: d () void
   public final void method_802() {
      this.field_1224 = 4;
   }

   // $VF: renamed from: e () void
   public final void method_803() {
      this.field_1224 = 5;
      this.field_1225.field_375 = false;
   }

   // $VF: renamed from: f () void
   public final void method_804() {
      this.field_1224 = 1;
      this.field_1225.field_375 = true;
   }

   // $VF: renamed from: a (long) void
   public abstract void method_805(long var1);

   // $VF: renamed from: a (int, int, int) boolean
   public abstract boolean method_806(int var1, int var2, int var3);

   // $VF: renamed from: a (x) boolean
   public boolean method_807(class_3 var1) {
      return false;
   }

   // $VF: renamed from: b (x) x
   public class_3 method_808(class_3 var1) {
      return null;
   }

   // $VF: renamed from: c () void
   public void method_809() {
      if (!deep3dBeyondPhoneFar(this.field_1226)) { // Deep3D-PC
         class_84.field_1110.method_25(this.field_1226);
      }
   }

   // Deep3D-PC: the flight camera's far plane reaches every structure now
   // (class_64), but moving objects - creatures, items - are still
   // drawn only within the phone's far plane, so they appear and vanish
   // (spawn / despawn) exactly where they did
   private static final class_3 deep3dCam = new class_3();
   private static final class_3 deep3dPos = new class_3();

   public static final boolean deep3dBeyondPhoneFar(class_102 var0) {
      if (var0 == null) {
         return false;
      }
      // the world matrix is only refreshed when drawn: refresh it here, or
      // an object hidden once would stay where it was hidden
      var0.method_839(false);
      class_84.field_1110.field_40.method_849(deep3dCam);
      var0.method_849(deep3dPos);
      long var1 = deep3dCam.field_37 - deep3dPos.field_37;
      long var3 = deep3dCam.field_38 - deep3dPos.field_38;
      long var5 = deep3dCam.field_39 - deep3dPos.field_39;
      return var1 * var1 + var3 * var3 + var5 * var5 > 31768L * 31768L;
   }
}
