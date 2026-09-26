// $VF: renamed from: am
public final class class_87 {
   // $VF: renamed from: a am
   public static final class_87 field_1145 = new class_87();
   // $VF: renamed from: a int
   public int field_1146;
   // $VF: renamed from: a java.lang.String
   public String field_1147 = "";
   // $VF: renamed from: a byte[]
   public byte[] field_1148;
   // $VF: renamed from: b int
   public int field_1149;
   // $VF: renamed from: c int
   public int field_1150;
   // $VF: renamed from: d int
   public int field_1151;
   // $VF: renamed from: e int
   public int field_1152;
   // $VF: renamed from: b java.lang.String
   public String field_1153 = "";
   // $VF: renamed from: f int
   public int field_1154;
   // $VF: renamed from: g int
   public int field_1155;
   // $VF: renamed from: h int
   public int field_1156;
   // $VF: renamed from: a boolean
   public boolean field_1157;
   // $VF: renamed from: i int
   public int field_1158;
   // $VF: renamed from: j int
   public int field_1159;
   // $VF: renamed from: k int
   public int field_1160;
   // $VF: renamed from: b boolean
   public boolean field_1161;
   // $VF: renamed from: c boolean
   public boolean field_1162 = false;
   // $VF: renamed from: d boolean
   public boolean field_1163 = false;
   // $VF: renamed from: l int
   public int field_1164;
   // $VF: renamed from: m int
   public int field_1165;
   // $VF: renamed from: n int
   public int field_1166;
   // $VF: renamed from: o int
   public int field_1167;
   // $VF: renamed from: p int
   public int field_1168;
   // $VF: renamed from: q int
   public int field_1169;
   // $VF: renamed from: r int
   public int field_1170;
   // $VF: renamed from: e boolean
   public boolean field_1171;

   public class_87(int var1, String var2, byte[] var3, int var4, int var5, int var6, int var7, int var8) {
      this.field_1146 = var1;
      this.field_1147 = var2;
      this.field_1148 = var3;
      this.field_1149 = var4;
      this.field_1150 = var5;
      this.field_1152 = var6;
      this.field_1153 = class_38.method_354(var6).field_1133;
      this.field_1154 = var7;
      this.field_1155 = var8;
      this.field_1156 = -1;
      this.field_1161 = false;
      this.field_1171 = true;
      this.field_1159 = 0;
   }

   public class_87(int var1, int var2, int var3) {
      this.field_1146 = var1;
      this.field_1150 = var2;
      this.field_1152 = var3;
      this.field_1153 = class_38.method_354(var3).field_1133;
      this.field_1155 = -1;
      this.field_1156 = -1;
      this.field_1161 = true;
      this.field_1171 = true;
   }

   private class_87() {
      this.field_1146 = -1;
      this.field_1161 = false;
      this.field_1171 = false;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_754() {
      return this.field_1146 == -1;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_755(int var1, int var2, int var3) {
      this.field_1166 = var1;
      this.field_1167 = var2;
      this.field_1168 = var3;
      this.field_1169 = (int)((float)var3 / var2 * 100.0F);
   }

   // $VF: renamed from: a (int, int) void
   public final void method_756(int var1, int var2) {
      this.field_1164 = var1;
      this.field_1165 = var2;
   }

   // $VF: renamed from: a () java.lang.String
   public final String method_757() {
      return this.field_1161
         ? class_21.method_219(class_84.field_1116.method_4(class_1.field_10[class_21.method_143()]), this.field_1153)
         : class_84.field_1116.method_4(class_1.field_12[this.field_1146]);
   }

   // $VF: renamed from: b () java.lang.String
   public final String method_758() {
      return this.field_1161
         ? class_21.method_219(class_84.field_1116.method_4(class_1.field_11[class_21.method_143()]), this.field_1153)
         : class_84.field_1116.method_4(class_1.field_13[this.field_1146]);
   }

   // $VF: renamed from: a (int) void
   public final void method_759(int var1) {
      this.field_1152 = var1;
      this.field_1153 = class_38.method_354(this.field_1152).field_1133;
   }

   // $VF: renamed from: a () void
   public final void method_760() {
      if (this.field_1155 > -1) {
         this.field_1156++;
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_761(int var1) {
      this.field_1156 += var1;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_762() {
      return this.field_1156 > this.field_1155;
   }

   // $VF: renamed from: b () void
   public final void method_763() {
      class_86 var1 = class_38.method_354(this.field_1152);
      this.field_1158 = (int)class_38.method_362(class_21.method_180(), var1);
      this.field_1160 = var1.field_1140;
      int var2 = class_21.method_180().field_1135;
      int var3 = class_21.method_180().field_1136;
      int var4 = var1.field_1135;
      int var5 = var1.field_1136;
      int var6 = var4 - var2;
      int var7 = var5 - var3;
      if (var6 > 0
         && class_16.method_100(var6) > class_16.method_100(var7)
         && class_16.method_100(var6 - var7) > (class_16.method_100(var6) + class_16.method_100(var7)) / 5) {
         this.field_1159 = 1;
      } else if (var6 < 0
         && class_16.method_100(var6) > class_16.method_100(var7)
         && class_16.method_100(var6 - var7) > (class_16.method_100(var6) + class_16.method_100(var7)) / 5) {
         this.field_1159 = 3;
      } else if (var7 > 0
         && class_16.method_100(var7) > class_16.method_100(var6)
         && class_16.method_100(var6 - var7) > (class_16.method_100(var6) + class_16.method_100(var7)) / 5) {
         this.field_1159 = 2;
      } else if (var7 < 0
         && class_16.method_100(var7) > class_16.method_100(var6)
         && class_16.method_100(var6 - var7) > (class_16.method_100(var6) + class_16.method_100(var7)) / 5) {
         this.field_1159 = 4;
      } else if (var6 > 0 && var7 > 0) {
         this.field_1159 = 5;
      } else if (var6 > 0 && var7 < 0) {
         this.field_1159 = 8;
      } else if (var6 < 0 && var7 > 0) {
         this.field_1159 = 6;
      } else {
         if (var6 < 0 && var7 < 0) {
            this.field_1159 = 7;
         }
      }
   }

   // $VF: renamed from: a () int
   public final int method_764() {
      return this.field_1154 / class_16.method_98(20, class_16.method_97(1, class_21.method_210() / 2));
   }
}
