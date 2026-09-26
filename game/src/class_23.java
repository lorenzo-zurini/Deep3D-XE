import javax.microedition.lcdui.Image;

// $VF: renamed from: dd
public final class class_23 {
   // $VF: renamed from: a int
   public int field_228;
   // $VF: renamed from: b int
   public int field_229;
   // $VF: renamed from: c int
   public int field_230;
   // $VF: renamed from: d int
   public int field_231;
   // $VF: renamed from: e int
   public int field_232;
   // $VF: renamed from: a java.lang.String[]
   public String[] field_233;
   // $VF: renamed from: f int
   public int field_234;
   // $VF: renamed from: a boolean
   public boolean field_235;
   // $VF: renamed from: g int
   public int field_236;
   // $VF: renamed from: h int
   public int field_237;
   // $VF: renamed from: a java.lang.String
   public String field_238;
   // $VF: renamed from: b java.lang.String[]
   public String[] field_239;
   // $VF: renamed from: a byte[]
   public byte[] field_240;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_241;
   // $VF: renamed from: b boolean
   public boolean field_242;
   // $VF: renamed from: c java.lang.String[]
   public String[] field_243;
   // $VF: renamed from: i int
   public int field_244;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   public Image field_245;
   // $VF: renamed from: j int
   public int field_246;
   // $VF: renamed from: k int
   public int field_247;
   // $VF: renamed from: c boolean
   public boolean field_248;
   // $VF: renamed from: l int
   public int field_249;

   public class_23(int var1, int var2, int var3, int var4, String var5) {
      this.field_228 = var1;
      this.field_229 = var2;
      this.field_230 = var3;
      this.field_231 = var4;
      this.field_232 = 0;
      if (var5 != null) {
         this.method_225(var5);
      }

      this.field_248 = false;
      this.field_249 = 0;
   }

   // $VF: renamed from: a () void
   public final void method_224() {
      this.field_232 = 0;
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_225(String var1) {
      this.field_238 = var1;
      if (this.field_240 == null && this.field_241 == null) {
         this.field_244 = 0;
      }

      if (var1 != null) {
         if (this.field_239 != null) {
            this.field_244 = this.field_244 + this.field_237;
         }

         this.field_233 = class_58.method_532(var1, this.field_230 + 5);
         this.field_234 = class_58.method_530(this.field_233) + this.field_244;
         this.field_235 = this.field_234 > this.field_231;
         if (this.field_235) {
            this.field_233 = class_58.method_532(var1, this.field_230 - 3);
            this.field_234 = class_58.method_530(this.field_233) + this.field_244;
            this.field_236 = (int)((float)this.field_231 / this.field_234 * this.field_231) - 1;
         }
      }
   }

   // $VF: renamed from: a (byte[], java.lang.String, boolean) void
   public final void method_226(byte[] var1, String var2, boolean var3) {
      this.method_227(var1, null, var2, var3);
   }

   // $VF: renamed from: a (byte[], javax.microedition.lcdui.Image, java.lang.String, boolean) void
   public final void method_227(byte[] var1, Image var2, String var3, boolean var4) {
      this.field_240 = var1;
      this.field_241 = var2;
      this.field_242 = var4;
      this.field_243 = class_58.method_532(var3, this.field_230 - class_119.field_1458 - 2);
      this.field_244 = class_119.field_1459 + 4;
      this.method_225(this.field_238);
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Image, int, int) void
   public final void method_228(Image var1, int var2, int var3) {
      this.field_245 = var1;
      this.field_246 = var2;
      this.field_247 = var3;
      this.field_244 += 22;
      this.method_225(this.field_238);
   }

   // $VF: renamed from: a (int) void
   public final void method_229(int var1) {
      if (this.field_234 > this.field_231) {
         this.field_232 -= var1 / 10;
         if (this.field_232 < -(this.field_234 - this.field_231)) {
            this.field_232 = -(this.field_234 - this.field_231);
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_230(int var1) {
      this.field_232 += var1 / 10;
      if (this.field_232 > 0) {
         this.field_232 = 0;
      }
   }

   // $VF: renamed from: b () void
   public final void method_231() {
      class_84.field_1117.setColor(class_67.field_844);
      class_84.field_1117.setClip(this.field_228, this.field_229, this.field_230, this.field_231);
      if (this.field_239 != null) {
         class_58.method_521(this.field_239, this.field_228, this.field_229 + this.field_232, 0);
      }

      if (this.field_240 != null || this.field_241 != null) {
         class_84.field_1117
            .drawRect(
               this.field_242 ? this.field_228 : this.field_228 + this.field_230 - class_119.field_1458 - 4,
               this.field_229 + this.field_232 + this.field_237,
               class_119.field_1458 + 1,
               class_119.field_1459 + 1
            );
      }

      if (this.field_240 != null) {
         class_119.method_923(
            this.field_240,
            this.field_242 ? this.field_228 + 1 : this.field_228 + this.field_230 - class_119.field_1458 - 3,
            this.field_229 + this.field_232 + 1 + this.field_237,
            0
         );
      } else if (this.field_241 != null) {
         class_84.field_1117
            .drawImage(
               this.field_241,
               this.field_242 ? this.field_228 + 1 : this.field_228 + this.field_230 - class_119.field_1458 - 3,
               this.field_229 + this.field_232 + 1 + this.field_237,
               0
            );
      }

      if (this.field_243 != null) {
         class_58.method_519(
            this.field_243,
            this.field_242 ? this.field_228 + class_119.field_1458 + 6 : this.field_228 + this.field_230 - class_119.field_1458 - 8,
            this.field_229 + this.field_232 + this.field_237,
            0,
            this.field_242 ? 1 : 2
         );
      }

      if (this.field_245 != null) {
         class_84.field_1117.drawImage(this.field_245, this.field_228 + 1, this.field_229 + this.field_232 + 1 + this.field_237 + class_119.field_1459 + 4, 0);
         class_58.method_517(
            (this.field_246 > 0 ? this.field_246 + "t " : "") + class_84.field_1116.method_4(class_1.field_7[this.field_247][0]),
            this.field_228 + 23,
            this.field_229 + this.field_232 + 1 + this.field_237 + class_119.field_1459 + 7
         );
      }

      if (this.field_233 != null) {
         if (this.field_248) {
            class_58.method_519(
               this.field_233, this.field_228 + this.field_230 - 3, this.field_229 + this.field_232 + this.field_244 + this.field_237, this.field_249, 2
            );
         } else {
            class_58.method_521(this.field_233, this.field_228, this.field_229 + this.field_232 + this.field_244 + this.field_237, this.field_249);
         }
      }

      class_84.field_1117.setClip(0, 0, class_84.field_1120, class_84.field_1121);
      if (this.field_235) {
         class_84.field_1117.drawLine(this.field_228 + this.field_230, this.field_229, this.field_228 + this.field_230, this.field_229 + this.field_231 - 4);
         class_84.field_1117.drawLine(this.field_228 + this.field_230 - 1, this.field_229 + 1, this.field_228 + this.field_230 + 1, this.field_229 + 1);
         class_84.field_1117
            .drawLine(
               this.field_228 + this.field_230 - 1,
               this.field_229 + this.field_231 - 5,
               this.field_228 + this.field_230 + 1,
               this.field_229 + this.field_231 - 5
            );
         if (class_67.method_581()) {
            class_84.field_1117.setColor(192, 192, 192);
         }

         class_84.field_1117
            .fillRect(
               this.field_228 + this.field_230 - 1,
               this.field_229 + 2 - (int)((float)this.field_232 / this.field_234 * (this.field_231 - 7)),
               3,
               this.field_236
            );
         class_84.field_1117.setColor(class_67.field_844);
      }
   }
}
