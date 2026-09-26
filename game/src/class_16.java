// $VF: renamed from: bb
public final class class_16 {
   // $VF: renamed from: c int
   private static int field_199 = 5;
   // $VF: renamed from: d int
   private static int field_200 = 5000;
   // $VF: renamed from: e int
   private static int field_201 = 20000;
   // $VF: renamed from: a cm
   public class_96 field_202;
   // $VF: renamed from: a ay
   public class_101 field_203;
   // $VF: renamed from: b ay
   private class_101 field_204;
   // $VF: renamed from: a s
   private class_71 field_205;
   // $VF: renamed from: a c
   private class_99 field_206;
   // $VF: renamed from: a v
   private class_5 field_207;
   // $VF: renamed from: b v
   private class_5 field_208;
   // $VF: renamed from: a bh
   public class_52 field_209;
   // $VF: renamed from: a ar
   private class_21 field_210;
   // $VF: renamed from: a j
   private class_20 field_211;
   // $VF: renamed from: a ao
   public class_8 field_212;
   // $VF: renamed from: a cz
   private class_7 field_213;
   // $VF: renamed from: a cy
   public class_57 field_214;
   // $VF: renamed from: a dr
   public class_13 field_215;
   // $VF: renamed from: f int
   private int field_216;
   // $VF: renamed from: g int
   // Deep3D-PC: float so a controller stick can command partial rates.
   private float field_217;
   // $VF: renamed from: h int
   private float field_218;
   // $VF: renamed from: i int
   private int field_219;
   // $VF: renamed from: a int
   public int field_220;
   // $VF: renamed from: a long
   private long field_221;
   // $VF: renamed from: b long
   private long field_222;
   // $VF: renamed from: j int
   private int field_223;
   // $VF: renamed from: a boolean
   public boolean field_224;
   // $VF: renamed from: c long
   private long field_225;
   // $VF: renamed from: k int
   private int field_226;
   // $VF: renamed from: b boolean
   public boolean field_227;
   // $VF: renamed from: l int
   private int field_228;
   // $VF: renamed from: m int
   private int field_229;
   // $VF: renamed from: c boolean
   public boolean field_230;
   // $VF: renamed from: f boolean
   private boolean field_231;
   // $VF: renamed from: g boolean
   private boolean field_232;
   // $VF: renamed from: c v
   private class_5 field_233;
   // $VF: renamed from: d v
   private class_5 field_234;
   // $VF: renamed from: a bn
   private class_1 field_235 = new class_1();
   // $VF: renamed from: n int
   private int field_236;
   // $VF: renamed from: b int
   public int field_237;
   // $VF: renamed from: a float
   private float field_238;
   // $VF: renamed from: o int
   private int field_239;
   // $VF: renamed from: d boolean
   public boolean field_240;
   // $VF: renamed from: a aw
   private class_83 field_241;
   // $VF: renamed from: e boolean
   public boolean field_242;
   // $VF: renamed from: e v
   private class_5 field_243;
   // $VF: renamed from: c ay
   private class_101 field_244;
   // $VF: renamed from: d ay
   private class_101 field_245;
   // $VF: renamed from: p int
   private int field_246;
   // $VF: renamed from: q int
   private int field_247;
   // $VF: renamed from: h boolean
   private boolean field_248;

   public class_16(class_96 var1) {
      this.field_202 = var1;
      this.field_202.field_1273 = true;
      this.field_207 = new class_5();
      this.field_208 = new class_5();
      this.field_243 = new class_5();
      this.field_233 = new class_5();
      this.field_234 = new class_5();
      this.field_219 = 1;
      this.field_209 = new class_52();
      this.field_210 = new class_21();
      this.field_211 = new class_20();
      this.field_213 = new class_7();
      this.field_220 = -1;
      this.field_223 = this.field_202.method_812();
      this.field_216 = 2;
      this.field_227 = false;
      this.field_230 = true;
      this.field_240 = false;
      this.field_241 = null;
      this.field_236 = class_3.method_110().field_834;
      this.field_237 = this.field_236;
      field_201 = class_3.method_108().field_437;
      field_199 = class_3.method_108().field_436;
      field_200 = class_3.method_108().field_438;
      this.field_232 = field_201 > 0;
      this.field_238 = class_3.method_108().field_429;
      this.field_239 = class_3.method_108().field_439;
      this.field_238 = this.field_238 + this.field_239 / 100.0F;
      this.field_244 = class_25.method_328(9993);
      this.field_244.field_1294 = 2;
      this.field_245 = class_25.method_328(9997);
      this.field_245.field_1294 = 2;
      this.field_204 = class_25.method_328(6768);
      this.field_204.field_1294 = 3;
      new class_98().method_875(this.field_204);
      this.field_205 = new class_71(this.field_244, this.field_204);
      this.field_205.field_1039 = true;
      this.field_206 = new class_99();
      this.field_206.method_876(this.field_205);
      this.field_246 = this.field_236 - class_3.method_108().field_448 << 3;
      this.field_247 = this.field_236 - class_3.method_108().field_449 << 3;
   }

   // $VF: renamed from: a (ay) void
   public final void method_229(class_101 var1) {
      this.field_203 = var1;
      int[] var2;
      if ((var2 = class_24.method_319(var1.field_1286, class_3.method_108().field_443 ? 1 : 0)) != null) {
         var1.method_872(var2[0], var2[1]);
         var1.method_873((byte)2);
      }

      var1.field_1283.method_24(0, 0, 0);
   }

   // $VF: renamed from: a () void
   public final void method_230() {
      this.field_223 = this.field_202.method_812();
   }

   // $VF: renamed from: b () void
   public final void method_231() {
      if (!this.field_227 && this.field_232 && this.field_226 >= 0) {
         class_41.field_539.method_427(7);
         this.field_226 = 0;
         this.field_216 = field_199;
         this.field_227 = true;
         this.field_203.method_845(this.field_233);
         this.field_234.method_169(this.field_233);
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_232() {
      return this.field_226 >= 0;
   }

   // $VF: renamed from: a () float
   public final float method_233() {
      float var1;
      if ((var1 = (float)this.field_226 / (field_200 / 6)) < 1.0F) {
         return var1;
      } else {
         return var1 > 5.0F ? 6.0F - var1 : 1.0F;
      }
   }

   // $VF: renamed from: b () float
   public final float method_234() {
      float var1;
      return (var1 = (float)this.field_226 / field_201) > 0.0F ? 1.0F : 1.0F + var1;
   }

   // $VF: renamed from: c () void
   public final void method_235() {
      this.field_215 = null;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_236() {
      return this.method_240() <= 0;
   }

   // $VF: renamed from: a (long) void
   public final void method_237(long var1) {
      if (this.field_220 >= 0) {
         this.field_202.method_831(this.field_220, var1, false);
      }
   }

   // $VF: renamed from: a (o, int) void
   public final void method_238(class_19 var1, int var2) {
      this.field_202.method_825(var1, var2);
      this.field_220 = 0;
   }

   // $VF: renamed from: a (o[], int) void
   public final void method_239(class_19[] var1, int var2) {
      this.field_202.method_826(var1, var2);
      this.field_220 = 0;
   }

   // $VF: renamed from: a () int
   public final int method_240() {
      return this.field_202.field_1256;
   }

   // $VF: renamed from: b () int
   public final int method_241() {
      return this.field_202.field_1263;
   }

   // $VF: renamed from: d () void
   public final void method_242() {
      this.field_220++;
      if (this.field_220 > this.field_202.field_1262 - 1) {
         this.field_220 = 0;
      }

      class_3.method_108().field_450 = this.field_220;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_243() {
      return this.field_220 >= 0
         && this.field_202.field_1252 != null
         && this.field_202.field_1252[this.field_220] != null
         && this.field_202.field_1252[this.field_220][0].field_298;
   }

   // $VF: renamed from: c () int
   public final int method_244() {
      return this.field_202.method_829(this.field_220);
   }

   // $VF: renamed from: a () v
   public final class_5 method_245() {
      return this.field_203.method_844(this.field_207);
   }

   // $VF: renamed from: c () float
   public final float method_246() {
      return 1.0F - class_124.method_942(0, this.field_237 - 15000) / 15000.0F;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_247(boolean var1) {
      this.field_202.field_1268 = var1;
   }

   // $VF: renamed from: a (aw) void
   public final void method_248(class_83 var1) {
      this.field_241 = var1;
      this.field_242 = false;
      this.field_240 = this.field_241 != null;
      if (this.field_241 != null && this.field_241 instanceof class_87) {
         this.field_242 = true;
      }
   }

   // $VF: renamed from: d () boolean
   public final boolean method_249() {
      return this.field_241 == this.field_214.field_778[1];
   }

   // $VF: renamed from: e () boolean
   public final boolean method_250() {
      return this.field_214.field_778[0] != null ? this.field_241 == this.field_214.field_778[0] : false;
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_251(int var1, int var2, int var3) {
      this.field_203.method_841(var1, var2, var3);
      this.field_202.field_1270.method_9(var1, var2, var3);
   }

   // $VF: renamed from: b (long) void
   public final void method_252(long var1) {
      if (!this.field_224) {
         int var3 = this.field_236 - (this.field_203.method_849() >> 3);
         this.field_237 = var3 > 500 ? var3 : 500;
         this.field_233 = this.field_203.method_845(this.field_233);
         this.field_225 = var1;
         if (this.field_226 < 0 && this.field_226 + 3L * var1 > 0L) {
            class_4.method_154(4, this);
            this.field_226 = 0;
         }

         this.field_226 = (int)(this.field_226 + var1);
         if (this.field_227) {
            if (this.field_226 > field_200) {
               this.field_216 = 2;
               this.field_227 = false;
               this.field_226 = -field_201;
            }

            if (this.field_213 != null) {
               this.field_213.method_190(this.field_233, (int)this.field_225);
               this.field_234.method_169(this.field_233);
            }
         }

         this.field_231 = false;
         if (this.field_230) {
            this.method_253(this.field_214.field_778);
            this.method_253(this.field_214.field_776);
            this.method_253(this.field_214.field_775);
         }

         if (this.field_240 && this.field_241 != null && !this.field_231) {
            if (this.field_242) {
               this.field_241 = ((class_87)this.field_241).field_1107.method_219();
            }

            if (this.field_241 != null) {
               this.field_208 = this.field_241.method_746(this.field_208);
               this.field_208.method_177(this.field_203.method_844(this.field_233));
               this.field_208.method_182();
               this.field_207.method_169(this.field_203.method_851(this.field_207));
               this.field_207.method_182();
               this.field_208.method_177(this.field_207);
               this.field_208.method_178((int)((float)this.field_225 * 5.0F));
               this.field_243 = this.field_207.method_174(this.field_208, this.field_243);
               this.field_243.method_182();
               this.field_203.field_1283.method_44(this.field_243);
               if (this.field_217 == 0 && this.field_218 == 0) {
                  this.method_258((int)this.field_225);
               }

               this.field_203.method_843((int)var1 * this.field_216);
            } else {
               this.method_248(null);
            }
         } else if (!this.field_231) {
            this.field_203.method_858((int)(this.field_238 * (this.field_217 * (int)var1 / 3)));
            this.field_228 = (int)(this.field_238 * (this.field_218 * (int)var1 / 3));
            this.field_203.method_859(this.field_228);
            this.field_229 = this.field_229 + (int)(this.field_238 * (this.field_217 * (int)var1 / 3));
            if (this.field_217 == 0 && this.field_218 == 0) {
               this.method_258((int)this.field_225);
            }

            this.field_203.method_843((int)var1 * this.field_216);
         }

         if (!this.field_231) {
            this.field_203.method_877(-this.field_219);
            if (this.field_219 > 0 && this.field_218 == 0) {
               this.field_219 = (int)(this.field_219 - var1 / 5L);
            } else if (this.field_219 < -var1 / 5L && this.field_218 == 0) {
               this.field_219 = (int)(this.field_219 + var1 / 5L);
            }

            this.field_217 = this.field_218 = 0;
         }

         if (this.field_237 > class_3.method_108().field_448 && class_3.method_108().field_430 > 0 && class_3.method_108().field_432 > 0) {
            this.field_221 += var1;
            if (this.field_221 > class_3.method_108().field_432) {
               this.field_221 = 0L;
               this.field_202.method_813();
            }
         }

         if (class_3.method_108().field_442 && this.field_202.field_1256 < this.field_202.field_1257) {
            this.field_222 += var1;
            if (this.field_222 > 600L) {
               this.field_222 = 0L;
               this.field_202.method_814();
            }
         }

         this.field_202.method_832(var1);
         this.field_209.method_511(var1, class_41.field_527.field_249.field_1284, false);
         this.field_210.method_293(var1, this.field_202.field_1270);
         this.field_211.method_289(this.field_203.field_1283);
         this.field_202.field_1270 = this.field_203.field_1283;
         this.field_244.method_841(this.field_203.method_848(), this.field_246, this.field_203.method_850());
         this.field_245.method_841(this.field_203.method_848(), this.field_247, this.field_203.method_850());
         if (this.field_215 != null) {
            this.field_215.method_223(this.field_203.method_848(), this.field_203.method_849(), this.field_203.method_850());
         }

         if (!this.field_230) {
            if (this.field_213 != null) {
               this.field_213.method_190(this.field_233, (int)this.field_225);
               this.field_234.method_169(this.field_233);
            }
         } else {
            if (this.field_223 > this.field_202.method_812()) {
               class_41.method_415(110);
               this.field_223 = this.field_202.method_812();
            }

            this.field_248 = false;
            if (this.field_237 > class_3.method_108().field_449 + 200) {
               this.field_207 = this.field_245.method_844(this.field_207);
               this.field_205.field_1031 = this.field_245;
               this.field_248 = true;
            } else if (this.field_237 < class_3.method_108().field_448 - 200) {
               this.field_207 = this.field_244.method_844(this.field_207);
               this.field_205.field_1031 = this.field_244;
               this.field_248 = true;
            }

            if (this.field_237 > class_3.method_89()) {
               class_3.method_91(this.field_237);
            } else if (this.field_237 < class_3.method_90()) {
               class_3.method_92(this.field_237);
            }

            if (this.field_248) {
               this.field_204.method_866(class_41.field_527.field_249.field_1283);
               this.field_204.method_843(-4200);
               this.field_206.method_835(false);
            }

            if (this.field_233.method_183() > 500000) {
               this.field_203.method_841(20000, this.field_233.field_139, 20000);
            }

            if (this.method_236()) {
               this.method_259(var1);
            }
         }
      }
   }

   // $VF: renamed from: a (aw[]) void
   private void method_253(class_83[] var1) {
      if (var1 != null) {
         for (int var2 = 0; var2 < var1.length; var2++) {
            if (var1[var2] != null && var1[var2].method_754(this.field_203.method_844(this.field_208))) {
               this.field_208 = var1[var2].method_755(this.field_203.method_844(this.field_208));
               this.field_208.field_138 += 100;
               if (this.field_208 != null) {
                  this.field_207.method_169(this.field_203.method_851(this.field_207));
                  this.field_208.method_177(this.field_207);
                  this.field_208.method_178((int)((float)this.field_225 * 5.0F));
                  this.field_233 = this.field_207.method_174(this.field_208, this.field_233);
                  this.field_233.method_182();
                  this.field_203.field_1283.method_44(this.field_233);
                  this.field_203.method_843((int)this.field_225 * this.field_216);
                  this.method_258((int)this.field_225);
                  this.field_231 = true;
                  return;
               }
            }
         }
      }
   }

   // $VF: renamed from: c (long) void
   public final void method_254(long var1) {
      this.field_218 = 1;
      if (this.field_219 < 384) {
         this.field_219 = (int)(this.field_219 + var1);
      }
   }

   // $VF: renamed from: d (long) void
   public final void method_255(long var1) {
      this.field_218 = -1;
      if (this.field_219 > -384) {
         this.field_219 = (int)(this.field_219 - var1);
      }
   }

   /**
    * Deep3D-PC: analogue steering. yaw > 0 turns left (like method_254),
    * pitch uses the same sign as method_256/257. Magnitudes 0..1 scale the
    * turn rate and the visual bank.
    */
   public final void steerAnalog(long var1, float yaw, float pitch) {
      this.field_218 = yaw;
      float bankLimit = 384.0F * Math.abs(yaw);
      if (yaw > 0.0F) {
         if (this.field_219 < bankLimit) {
            this.field_219 = (int)(this.field_219 + var1);
         }
      } else if (yaw < 0.0F && this.field_219 > -bankLimit) {
         this.field_219 = (int)(this.field_219 - var1);
      }

      this.field_217 = pitch;
   }

   // $VF: renamed from: e (long) void
   public final void method_256(long var1) {
      this.field_217 = 1;
   }

   // $VF: renamed from: f (long) void
   public final void method_257(long var1) {
      this.field_217 = -1;
   }

   // $VF: renamed from: a (int) void
   public final void method_258(int var1) {
      this.field_235.method_2();
      var1 = class_124.method_943(var1, 60);
      this.field_207 = this.field_203.method_852(this.field_207);
      this.field_208 = this.field_203.method_854(this.field_208);
      this.field_235.method_2();
      int var2 = this.field_235.method_16().method_172(this.field_208);
      if (this.field_235.method_16().method_172(this.field_207) < 0) {
         if (var2 > 0) {
            this.field_203.method_857(-var1 >> 1);
         } else {
            this.field_203.method_857(var1 >> 1);
         }
      } else {
         if (var2 > 128 && var2 < 3968 || var2 < -128 && var2 > -3968) {
            if (var2 < 0) {
               this.field_203.method_857(var1 >> 1);
               return;
            }

            this.field_203.method_857(-var1 >> 1);
         }
      }
   }

   // $VF: renamed from: g (long) void
   private void method_259(long var1) {
      if (this.field_202.field_1268) {
         this.field_212.method_196(this.field_203.method_848(), this.field_203.method_849(), this.field_203.method_850());
      }

      this.field_202.field_1268 = false;
   }

   // $VF: renamed from: e () void
   public final void method_260() {
      this.field_202.method_830(this.field_220);
   }

   // $VF: renamed from: f () void
   public final void method_261() {
      this.field_214 = null;
      if (this.field_212 != null) {
         this.field_212.method_193();
      }

      this.field_212 = null;
      if (this.field_211 != null) {
         this.field_211.method_290();
      }

      this.field_211 = null;
      if (this.field_209 != null) {
         this.field_209.method_510();
      }

      this.field_209 = null;
      if (this.field_210 != null) {
         this.field_210.method_292();
      }

      this.field_210 = null;
      if (this.field_213 != null) {
         this.field_213.method_189();
      }

      this.field_213 = null;
      ;
   }

   // $VF: renamed from: b (boolean) void
   public final void method_262(boolean var1) {
      if (this.method_236()) {
         this.field_212.method_197(this.field_225);
         this.field_209.method_512();
         this.field_210.method_294();
      } else {
         class_41.field_527.method_265(this.field_203);
         if (this.field_248) {
            class_41.field_527.method_265(this.field_204);
         }

         this.field_209.method_512();
         if (!this.field_224 && var1) {
            this.field_210.method_294();
            class_41.field_527.method_265(this.field_244);
            class_41.field_527.method_265(this.field_245);
         }

         if (this.field_227 || !this.field_230) {
            this.field_213.method_192();
         }
      }
   }

   // $VF: renamed from: a (boolean, am) void
   public final void method_263(boolean var1, class_111 var2) {
      if (!this.method_236() && !this.field_224 && var1) {
         this.field_211.method_291(var2);
      }
   }
}
