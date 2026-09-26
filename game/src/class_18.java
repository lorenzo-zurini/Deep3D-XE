import javax.microedition.lcdui.Image;

// $VF: renamed from: dc
public final class class_18 {
   // $VF: renamed from: a int
   public int field_254;
   // $VF: renamed from: b int
   public int field_255;
   // $VF: renamed from: c int
   public int field_256;
   // $VF: renamed from: d int
   public int field_257;
   // $VF: renamed from: e int
   public int field_258;
   // $VF: renamed from: a java.lang.String[]
   public String[] field_259;
   // $VF: renamed from: f int
   public int field_260;
   // $VF: renamed from: a boolean
   public boolean field_261;
   // $VF: renamed from: g int
   public int field_262;
   // $VF: renamed from: h int
   public int field_263;
   // $VF: renamed from: a java.lang.String
   public String field_264;
   // $VF: renamed from: b java.lang.String[]
   public String[] field_265;
   // $VF: renamed from: a byte[]
   public byte[] field_266;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_267;
   // $VF: renamed from: b boolean
   public boolean field_268;
   // $VF: renamed from: c java.lang.String[]
   public String[] field_269;
   // $VF: renamed from: i int
   public int field_270;
   // $VF: renamed from: b javax.microedition.lcdui.Image
   public Image field_271;
   // $VF: renamed from: j int
   public int field_272;
   // $VF: renamed from: k int
   public int field_273;
   // $VF: renamed from: c boolean
   public boolean field_274;
   // $VF: renamed from: l int
   public int field_275;

   public class_18(int var1, int var2, int var3, int var4, String var5) {
      this.field_254 = var1;
      this.field_255 = var2;
      this.field_256 = var3;
      this.field_257 = var4;
      this.field_258 = 0;
      if (var5 != null) {
         this.method_272(var5);
      }

      this.field_274 = false;
      this.field_275 = 0;
   }

   // $VF: renamed from: a () void
   public final void method_271() {
      this.field_258 = 0;
   }

   // $VF: renamed from: a (java.lang.String) void
   public final void method_272(String var1) {
      this.field_264 = var1;
      if (this.field_266 == null && this.field_267 == null) {
         this.field_270 = 0;
      }

      if (var1 != null) {
         if (this.field_265 != null) {
            this.field_270 = this.field_270 + this.field_263;
         }

         this.field_259 = class_50.method_499(var1, this.field_256 + 5);
         this.field_260 = class_50.method_497(this.field_259) + this.field_270;
         this.field_261 = this.field_260 > this.field_257;
         if (this.field_261) {
            this.field_259 = class_50.method_499(var1, this.field_256 - 3);
            this.field_260 = class_50.method_497(this.field_259) + this.field_270;
            this.field_262 = (int)((float)this.field_257 / this.field_260 * this.field_257) - 1;
         }
      }
   }

   // $VF: renamed from: a (byte[], java.lang.String, boolean) void
   public final void method_273(byte[] var1, String var2, boolean var3) {
      this.method_274(var1, null, var2, var3);
   }

   // $VF: renamed from: a (byte[], javax.microedition.lcdui.Image, java.lang.String, boolean) void
   public final void method_274(byte[] var1, Image var2, String var3, boolean var4) {
      this.field_266 = var1;
      this.field_267 = var2;
      this.field_268 = var4;
      this.field_269 = class_50.method_499(var3, this.field_256 - class_119.field_1504 - 2);
      this.field_270 = class_119.field_1505 + 4;
      this.method_272(this.field_264);
   }

   // $VF: renamed from: a (javax.microedition.lcdui.Image, int, int) void
   public final void method_275(Image var1, int var2, int var3) {
      this.field_271 = var1;
      this.field_272 = var2;
      this.field_273 = var3;
      this.field_270 += 22;
      this.method_272(this.field_264);
   }

   // $VF: renamed from: a (int) void
   public final void method_276(int var1) {
      if (this.field_260 > this.field_257) {
         this.field_258 -= var1 / 10;
         if (this.field_258 < -(this.field_260 - this.field_257)) {
            this.field_258 = -(this.field_260 - this.field_257);
         }
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_277(int var1) {
      this.field_258 += var1 / 10;
      if (this.field_258 > 0) {
         this.field_258 = 0;
      }
   }

   // $VF: renamed from: b () void
   public final void method_278() {
      class_41.field_534.setColor(class_69.field_1003);
      class_41.field_534.setClip(this.field_254, this.field_255, this.field_256, this.field_257);
      if (this.field_265 != null) {
         class_50.method_488(this.field_265, this.field_254, this.field_255 + this.field_258, 0);
      }

      if (this.field_266 != null || this.field_267 != null) {
         class_41.field_534
            .drawRect(
               this.field_268 ? this.field_254 : this.field_254 + this.field_256 - class_119.field_1504 - 4,
               this.field_255 + this.field_258 + this.field_263,
               class_119.field_1504 + 1,
               class_119.field_1505 + 1
            );
      }

      if (this.field_266 != null) {
         class_119.method_928(
            this.field_266,
            this.field_268 ? this.field_254 + 1 : this.field_254 + this.field_256 - class_119.field_1504 - 3,
            this.field_255 + this.field_258 + 1 + this.field_263,
            0
         );
      } else if (this.field_267 != null) {
         class_41.field_534
            .drawImage(
               this.field_267,
               this.field_268 ? this.field_254 + 1 : this.field_254 + this.field_256 - class_119.field_1504 - 3,
               this.field_255 + this.field_258 + 1 + this.field_263,
               0
            );
      }

      if (this.field_269 != null) {
         class_50.method_486(
            this.field_269,
            this.field_268 ? this.field_254 + class_119.field_1504 + 6 : this.field_254 + this.field_256 - class_119.field_1504 - 8,
            this.field_255 + this.field_258 + this.field_263,
            0,
            this.field_268 ? 1 : 2
         );
      }

      if (this.field_271 != null) {
         class_41.field_534.drawImage(this.field_271, this.field_254 + 1, this.field_255 + this.field_258 + 1 + this.field_263 + class_119.field_1505 + 4, 0);
         class_50.method_484(
            (this.field_272 > 0 ? this.field_272 + "t " : "") + class_41.field_533.method_297(class_22.field_321[this.field_273][0]),
            this.field_254 + 23,
            this.field_255 + this.field_258 + 1 + this.field_263 + class_119.field_1505 + 7
         );
      }

      if (this.field_259 != null) {
         if (this.field_274) {
            class_50.method_486(
               this.field_259, this.field_254 + this.field_256 - 3, this.field_255 + this.field_258 + this.field_270 + this.field_263, this.field_275, 2
            );
         } else {
            class_50.method_488(this.field_259, this.field_254, this.field_255 + this.field_258 + this.field_270 + this.field_263, this.field_275);
         }
      }

      class_41.field_534.setClip(0, 0, class_41.field_537, class_41.field_538);
      if (this.field_261) {
         class_41.field_534.drawLine(this.field_254 + this.field_256, this.field_255, this.field_254 + this.field_256, this.field_255 + this.field_257 - 4);
         class_41.field_534.drawLine(this.field_254 + this.field_256 - 1, this.field_255 + 1, this.field_254 + this.field_256 + 1, this.field_255 + 1);
         class_41.field_534
            .drawLine(
               this.field_254 + this.field_256 - 1,
               this.field_255 + this.field_257 - 5,
               this.field_254 + this.field_256 + 1,
               this.field_255 + this.field_257 - 5
            );
         if (class_69.method_657()) {
            class_41.field_534.setColor(192, 192, 192);
         }

         class_41.field_534
            .fillRect(
               this.field_254 + this.field_256 - 1,
               this.field_255 + 2 - (int)((float)this.field_258 / this.field_260 * (this.field_257 - 7)),
               3,
               this.field_262
            );
         class_41.field_534.setColor(class_69.field_1003);
      }
   }
}
