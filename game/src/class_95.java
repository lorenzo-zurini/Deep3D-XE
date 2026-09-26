// $VF: renamed from: al
public final class class_95 {
   // $VF: renamed from: a al
   public static final class_95 field_1225 = new class_95();
   // $VF: renamed from: a int
   public int field_1226;
   // $VF: renamed from: a java.lang.String
   public String field_1227 = "";
   // $VF: renamed from: a byte[]
   public byte[] field_1228;
   // $VF: renamed from: b int
   public int field_1229;
   // $VF: renamed from: c int
   public int field_1230;
   // $VF: renamed from: d int
   public int field_1231;
   // $VF: renamed from: e int
   public int field_1232;
   // $VF: renamed from: b java.lang.String
   public String field_1233 = "";
   // $VF: renamed from: f int
   public int field_1234;
   // $VF: renamed from: g int
   public int field_1235;
   // $VF: renamed from: h int
   public int field_1236;
   // $VF: renamed from: a boolean
   public boolean field_1237;
   // $VF: renamed from: i int
   public int field_1238;
   // $VF: renamed from: j int
   public int field_1239;
   // $VF: renamed from: k int
   public int field_1240;
   // $VF: renamed from: b boolean
   public boolean field_1241;
   // $VF: renamed from: c boolean
   public boolean field_1242 = false;
   // $VF: renamed from: d boolean
   public boolean field_1243 = false;
   // $VF: renamed from: l int
   public int field_1244;
   // $VF: renamed from: m int
   public int field_1245;
   // $VF: renamed from: n int
   public int field_1246;
   // $VF: renamed from: o int
   public int field_1247;
   // $VF: renamed from: p int
   public int field_1248;
   // $VF: renamed from: q int
   public int field_1249;
   // $VF: renamed from: r int
   public int field_1250;
   // $VF: renamed from: e boolean
   public boolean field_1251;

   public class_95(int var1, String var2, byte[] var3, int var4, int var5, int var6, int var7, int var8) {
      this.field_1226 = var1;
      this.field_1227 = var2;
      this.field_1228 = var3;
      this.field_1229 = var4;
      this.field_1230 = var5;
      this.field_1232 = var6;
      this.field_1233 = class_44.method_431(var6).field_827;
      this.field_1234 = var7;
      this.field_1235 = var8;
      this.field_1236 = -1;
      this.field_1241 = false;
      this.field_1251 = true;
      this.field_1239 = 0;
   }

   public class_95(int var1, int var2, int var3) {
      this.field_1226 = var1;
      this.field_1230 = var2;
      this.field_1232 = var3;
      this.field_1233 = class_44.method_431(var3).field_827;
      this.field_1235 = -1;
      this.field_1236 = -1;
      this.field_1241 = true;
      this.field_1251 = true;
   }

   private class_95() {
      this.field_1226 = -1;
      this.field_1241 = false;
      this.field_1251 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_789() {
      return this.field_1226 == -1;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_790(int var1, int var2, int var3) {
      this.field_1246 = var1;
      this.field_1247 = var2;
      this.field_1248 = var3;
      this.field_1249 = (int)((float)var3 / var2 * 100.0F);
   }

   // $VF: renamed from: a (int, int) void
   public final void method_791(int var1, int var2) {
      this.field_1244 = var1;
      this.field_1245 = var2;
   }

   // $VF: renamed from: a () java.lang.String
   public final String method_792() {
      return this.field_1241
         ? class_3.method_149(class_41.field_533.method_297(class_22.field_324[class_3.method_73()]), this.field_1233)
         : class_41.field_533.method_297(class_22.field_326[this.field_1226]);
   }

   // $VF: renamed from: b () java.lang.String
   public final String method_793() {
      return this.field_1241
         ? class_3.method_149(class_41.field_533.method_297(class_22.field_325[class_3.method_73()]), this.field_1233)
         : class_41.field_533.method_297(class_22.field_327[this.field_1226]);
   }

   // $VF: renamed from: a (int) void
   public final void method_794(int var1) {
      this.field_1232 = var1;
      this.field_1233 = class_44.method_431(this.field_1232).field_827;
   }

   // $VF: renamed from: a () void
   public final void method_795() {
      if (this.field_1235 > -1) {
         this.field_1236++;
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_796(int var1) {
      this.field_1236 += var1;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_797() {
      return this.field_1236 > this.field_1235;
   }

   // $VF: renamed from: b () void
   public final void method_798() {
      class_60 var1 = class_44.method_431(this.field_1232);
      this.field_1238 = (int)class_44.method_439(class_3.method_110(), var1);
      this.field_1240 = var1.field_834;
      int var2 = class_3.method_110().field_829;
      int var3 = class_3.method_110().field_830;
      int var4 = var1.field_829;
      int var5 = var1.field_830;
      int var6 = var4 - var2;
      int var7 = var5 - var3;
      if (var6 > 0
         && class_124.method_945(var6) > class_124.method_945(var7)
         && class_124.method_945(var6 - var7) > (class_124.method_945(var6) + class_124.method_945(var7)) / 5) {
         this.field_1239 = 1;
      } else if (var6 < 0
         && class_124.method_945(var6) > class_124.method_945(var7)
         && class_124.method_945(var6 - var7) > (class_124.method_945(var6) + class_124.method_945(var7)) / 5) {
         this.field_1239 = 3;
      } else if (var7 > 0
         && class_124.method_945(var7) > class_124.method_945(var6)
         && class_124.method_945(var6 - var7) > (class_124.method_945(var6) + class_124.method_945(var7)) / 5) {
         this.field_1239 = 2;
      } else if (var7 < 0
         && class_124.method_945(var7) > class_124.method_945(var6)
         && class_124.method_945(var6 - var7) > (class_124.method_945(var6) + class_124.method_945(var7)) / 5) {
         this.field_1239 = 4;
      } else if (var6 > 0 && var7 > 0) {
         this.field_1239 = 5;
      } else if (var6 > 0 && var7 < 0) {
         this.field_1239 = 8;
      } else if (var6 < 0 && var7 > 0) {
         this.field_1239 = 6;
      } else {
         if (var6 < 0 && var7 < 0) {
            this.field_1239 = 7;
         }
      }
   }

   // $VF: renamed from: a () int
   public final int method_799() {
      return this.field_1234 / class_124.method_943(20, class_124.method_942(1, class_3.method_140() / 2));
   }
}
