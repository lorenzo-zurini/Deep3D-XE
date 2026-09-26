// $VF: renamed from: af
public final class class_89 extends class_83 {
   // $VF: renamed from: c v
   private static class_5 field_1170 = new class_5();
   // $VF: renamed from: a cj
   public class_63 field_1171;
   // $VF: renamed from: f int
   private int field_1172;
   // $VF: renamed from: g int
   private int field_1173;
   // $VF: renamed from: h int
   private int field_1174;
   // $VF: renamed from: i int
   private int field_1175;
   // $VF: renamed from: b ay
   private class_101 field_1176;
   // $VF: renamed from: a int[]
   private static int[] field_1177 = new int[3];
   // $VF: renamed from: b int[]
   private static int[] field_1178 = new int[3];
   // $VF: renamed from: d v
   private static class_5 field_1179 = new class_5();
   // $VF: renamed from: e v
   private static class_5 field_1180 = new class_5();
   // $VF: renamed from: a bn
   private static class_1 field_1181 = new class_1();
   // $VF: renamed from: b bn
   private class_1 field_1182 = new class_1();
   // $VF: renamed from: g boolean
   private boolean field_1183 = false;
   // $VF: renamed from: h boolean
   private boolean field_1184 = false;
   // $VF: renamed from: e boolean
   public boolean field_1185 = false;
   // $VF: renamed from: j int
   private int field_1186;
   // $VF: renamed from: a float
   private float field_1187;
   // $VF: renamed from: k int
   private int field_1188;
   // $VF: renamed from: i boolean
   private boolean field_1189;
   // $VF: renamed from: j boolean
   private boolean field_1190;
   // $VF: renamed from: e int
   public int field_1191;
   // $VF: renamed from: f boolean
   public boolean field_1192;
   // $VF: renamed from: l int
   private int field_1193;

   public class_89(int var1, class_101 var2, class_63 var3, int var4, int var5, int var6) {
      super(var1, false, new class_96(1500.0F, var3.field_858 * 2, 0), var2, var4, var5, var6);
      super.field_1102.field_1272 = this;
      this.field_1171 = var3;
      this.field_1190 = var1 == 4444 || var1 == 4445 || var1 == 4443 || var1 == 4446 || var1 == 4447;
      if (this.field_1190) {
         var2.method_860(256, 0, 0);
         this.field_1191 = var3.field_858;
      } else {
         this.field_1191 = class_124.method_942(1, var3.field_858 + (int)((-25 + class_41.field_540.nextInt(50)) / 100.0F * var3.field_858));
      }

      this.field_1187 = 1.0F + var3.field_859 / 2.2F;
      this.field_1174 = 2100 + (int)(var3.field_859 / 10.0F * 2100.0F);
      super.field_1101 = 0;
      this.field_1186 = super.field_1102.field_1256;
      if (var4 == 0 && var5 == 0 && var6 == 0) {
         field_1180.method_170(-4096 + class_41.field_540.nextInt(8192), -4096 + class_41.field_540.nextInt(8192), -4096 + class_41.field_540.nextInt(8192));
         field_1180.method_182();
         super.field_1103.field_1283.method_44(field_1180);
         field_1179.method_170(
            -30000 + class_41.field_540.nextInt(59000), -30000 + class_41.field_540.nextInt(59000), -30000 + class_41.field_540.nextInt(59000)
         );
      } else {
         field_1179.method_170(
            var4 - 8000 + class_41.field_540.nextInt(16000), var5 - 8000 + class_41.field_540.nextInt(16000), var6 - 8000 + class_41.field_540.nextInt(16000)
         );
      }

      super.field_1103.method_842(field_1179);
      super.field_1112 = field_1179.field_139;
      if (var1 == 4424 || var1 == 4427 || var1 == 4430 || var1 == 4432 || var1 == 4434 || var1 == 4440 || var1 == 4436 || var1 == 4438) {
         this.field_1176 = class_25.method_328(var1 + 1);
         this.field_1176.field_1294 = 2;
         this.field_1176.method_866(super.field_1103.field_1283);
      }

      super.field_1115 = true;
      super.field_1116 = true;
      this.method_769();
      this.field_1189 = false;
      this.field_1192 = false;
   }

   // $VF: renamed from: b (boolean) void
   public final void method_767(boolean var1) {
      this.field_1189 = var1;
      if (var1) {
         field_1180.method_170(0, 0, 4096);
         super.field_1103.field_1283.method_44(field_1180);
      }

      this.method_752(-1024 + class_41.field_540.nextInt(2048));
      super.field_1102.method_806(10);
      this.field_1186 = super.field_1102.field_1256;
   }

   // $VF: renamed from: b (int) void
   public final void method_768(int var1) {
      this.field_1183 = true;
      this.field_1184 = true;
      this.field_1173 = 0;
      this.field_1187 = 1.0F + this.field_1171.field_859 / 2.2F;
      this.field_1187 *= 1.0F - var1 / 100.0F;
   }

   // $VF: renamed from: b () void
   public final void method_769() {
      this.field_1175 = this.field_1190 ? 0 : this.field_1174;
      this.field_1173 = 0;
      this.field_1183 = false;
      this.field_1184 = false;
   }

   // $VF: renamed from: a () int
   public final int method_770() {
      return this.field_1175 / 1000 + 1;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_771() {
      if (super.field_1101 == 4 || super.field_1101 != 4 && class_3.method_108().method_372(this.field_1191)) {
         this.method_742(false);
         super.field_1116 = false;
         super.field_1103.method_865(0, 0, 0);
         if (super.field_1101 != 4) {
            if (class_3.method_62().field_1226 == 7) {
               if (this.field_1171.field_857 == class_3.method_62().field_1246) {
                  super.field_1106.method_550();
               }
            } else {
               super.field_1106.method_550();
            }
         }
      }

      if (super.field_1101 == 4) {
         class_46 var1 = class_24.method_315()[18].method_447(this.field_1191);
         if (class_3.method_108().method_372(var1.field_636)) {
            class_3.method_96(this.field_1191);
            class_3.method_108().method_373(var1);
            class_4.method_161(var1.field_626, var1.field_636, false, false);
         } else {
            class_4.method_161(var1.field_626, var1.field_636, true, false);
         }

         this.field_1192 = false;
      } else {
         if (this.field_1176 != null) {
            this.field_1176.method_866(super.field_1103.field_1283);
         }

         if (!class_3.method_108().method_372(this.field_1191)) {
            class_4.method_161(this.field_1171.field_857, this.field_1191, true, false);
            super.field_1103.method_865(4096, 4096, 4096);
            if (this.field_1176 != null) {
               this.field_1176.method_866(super.field_1103.field_1283);
            }

            this.field_1184 = false;
            this.field_1185 = false;
            return false;
         }

         class_3.method_108().method_373(class_24.method_315()[this.field_1171.field_857].method_447(this.field_1191));
         class_4.method_161(this.field_1171.field_857, this.field_1191, false, false);
         class_3.method_94(this.field_1171.field_857);
      }

      return true;
   }

   // $VF: renamed from: c (int) void
   public final void method_772(int var1) {
      super.field_1103.method_865(var1, var1, var1);
      if (this.field_1176 != null) {
         this.field_1176.method_866(super.field_1103.field_1283);
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      this.field_1193 = (int)var1;
      if (super.field_1102.field_1268 && !this.field_1185) {
         if (!this.field_1190) {
            this.field_1188 = (int)var1;
            if (this.field_1186 > super.field_1102.field_1256 && super.field_1101 != 4) {
               this.field_1183 = true;
            }

            this.field_1186 = super.field_1102.field_1256;
         }

         if (this.field_1183) {
            this.field_1187 += 0.01F;
            this.field_1173 = (int)(this.field_1173 + var1);
            this.field_1188 = (int)((float)var1 * this.field_1187);
            var1 <<= 1;
            if (this.field_1173 < 2000) {
               super.field_1103.field_1283.method_5(this.field_1182);
            } else {
               this.field_1175 = this.field_1175 - (this.field_1173 >> 1);
               if (!this.field_1189) {
                  int var3 = this.field_1188 >> 1;
                  this.field_1182.method_24(-(var3 >> 1) + class_41.field_540.nextInt(var3), -(var3 >> 1) + class_41.field_540.nextInt(var3), 0);
               }

               this.field_1173 = 0;
            }

            if (this.field_1175 <= 0) {
               if (this.field_1184) {
                  this.field_1185 = true;
                  class_4.method_155(0, 0, "");
               } else {
                  this.method_769();
               }
            }
         }

         if (!this.field_1190 && super.field_1102.field_1256 <= 0 && super.field_1101 != 4) {
            field_1179 = super.field_1103.method_844(field_1179);
            if (super.field_1116) {
               super.field_1103 = class_25.method_328(14);
               super.field_1103.field_1294 = 2;
               super.field_1103.method_842(field_1179);
               this.field_1176 = null;
               super.field_1102.field_1270 = super.field_1103.field_1283;
               super.field_1102.field_1272 = this;
               this.field_1192 = true;
               this.field_1191 = this.field_1191 / 3 + 1;
            }

            field_1179.method_177(super.field_1106.field_774.method_245());
            int var6 = class_124.method_943(40000, field_1179.method_183());
            float var4 = 1.0F - var6 / 40000.0F;
            int var5 = class_41.field_539.field_562;
            class_41.field_539.method_426(9, (int)(var5 * var4));
            super.field_1108.method_196(super.field_1103.method_848(), super.field_1103.method_849(), super.field_1103.method_850());
            class_3.method_137();
            super.field_1101 = 4;
            if (class_3.method_62().field_1226 == 7) {
               if (this.field_1171.field_857 == class_3.method_62().field_1246) {
                  super.field_1106.method_550();
                  return;
               }
            } else {
               super.field_1106.method_550();
            }
         } else if (super.field_1101 == 4) {
            if (!this.field_1184) {
               super.field_1103.method_839(0, (int)var1 / 3, 0);
            }

            if (this.field_1176 != null) {
               this.field_1176.method_866(super.field_1103.field_1283);
            }

            if (this.method_773()) {
               this.method_742(false);
            }
         } else {
            if (!this.field_1190 && super.field_1104 != 4429) {
               super.field_1103.method_843(this.field_1188);
               this.field_1172 = (int)(this.field_1172 + var1);
               this.field_1172 &= 4095;
            }

            switch (super.field_1104) {
               case 4422:
                  super.field_1103.method_865(4096, class_124.method_936(this.field_1172) / 3, 4096);
                  break;
               case 4423:
                  field_1181.method_24(0, class_124.method_936(this.field_1172) >> 7, 0);
                  super.field_1103.field_1283.method_5(field_1181);
                  break;
               case 4424:
                  this.field_1176.method_866(super.field_1103.field_1283);
                  this.field_1176.method_864(4096, 4096, 4096 + (class_124.method_936(this.field_1172 << 2) >> 2));
               case 4425:
               case 4428:
               case 4429:
               case 4431:
               case 4433:
               case 4435:
               case 4437:
               case 4439:
               case 4441:
               default:
                  break;
               case 4426:
                  super.field_1103.method_865(4096, 4096 + (class_124.method_936(this.field_1172 << 1) >> 2), 4096);
                  break;
               case 4427:
               case 4432:
               case 4436:
                  this.field_1176.method_866(super.field_1103.field_1283);
                  field_1181.method_24(-(class_124.method_936(this.field_1172) >> 6), 0, 0);
                  this.field_1176.field_1283.method_5(field_1181);
                  field_1181.method_24(class_124.method_936(this.field_1172) >> 8, 0, 0);
                  super.field_1103.field_1283.method_5(field_1181);
                  break;
               case 4430:
               case 4434:
               case 4440:
                  this.field_1176.method_866(super.field_1103.field_1283);
                  field_1181.method_24(0, class_124.method_936(this.field_1172) >> 5, 0);
                  this.field_1176.field_1283.method_5(field_1181);
                  field_1181.method_24(0, -(class_124.method_936(this.field_1172) >> 7), 0);
                  super.field_1103.field_1283.method_5(field_1181);
                  break;
               case 4438:
                  this.field_1176.method_866(super.field_1103.field_1283);
                  this.field_1176.method_865(4096, 4096 + (class_124.method_936(this.field_1172 << 2) >> 2), 4096);
                  break;
               case 4442:
                  super.field_1103.method_865(4096, 4096, 4096 + (class_124.method_936(this.field_1172 << 2) >> 2));
            }

            if (!this.field_1189 && this.method_773()) {
               this.method_774();
            }
         }
      }
   }

   // $VF: renamed from: d () boolean
   private boolean method_773() {
      super.field_1109 = class_41.field_527.field_249.method_845(super.field_1109);
      super.field_1110 = super.field_1109.method_176(super.field_1103.method_844(field_1170), super.field_1110);
      return super.field_1110.method_183() > 40000;
   }

   // $VF: renamed from: g () void
   private void method_774() {
      for (int var1 = 0; var1 < field_1177.length; var1++) {
         field_1177[var1] = -2048 + class_41.field_540.nextInt(4096);
      }

      field_1179.method_170(field_1177[0], field_1177[1] >> 1, field_1177[2]);
      field_1179.method_182();
      field_1177[0] = field_1179.field_138;
      field_1177[1] = field_1179.field_139;
      field_1177[2] = field_1179.field_140;
      field_1179.method_178(30000);
      field_1179.method_175(class_41.field_527.field_249.method_844(super.field_1110));
      super.field_1103.method_842(field_1179);

      for (int var2 = 0; var2 < field_1178.length; var2++) {
         field_1178[var2] = -15000 + class_41.field_540.nextInt(30000);
         field_1178[var2] = field_1178[var2] - field_1177[var2];
      }

      field_1180.method_170(field_1178[0], field_1178[1], field_1178[2]);
      field_1180.method_182();
      super.field_1103.field_1283.method_44(field_1180);
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (this.field_1176 != null) {
         class_41.field_527.method_265(this.field_1176);
      }

      class_41.field_527.method_265(super.field_1103);
      if (super.field_1101 == 4 && super.field_1108 != null && !super.field_1108.method_198()) {
         super.field_1108.method_197(this.field_1193);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      return false;
   }
}
