// $VF: renamed from: bl
public final class class_85 extends class_83 {
   // $VF: renamed from: f int
   private int field_1130 = 500;
   // $VF: renamed from: a float
   private float field_1131 = 2.1F;
   // $VF: renamed from: b float
   private float field_1132 = 2.0F;
   // $VF: renamed from: g int
   private int field_1133 = 20;
   // $VF: renamed from: a cz
   private class_7 field_1134;
   // $VF: renamed from: c v
   private class_5 field_1135 = new class_5();
   // $VF: renamed from: d v
   private class_5 field_1136 = new class_5();
   // $VF: renamed from: e v
   private class_5 field_1137 = new class_5();
   // $VF: renamed from: f v
   private class_5 field_1138 = new class_5();
   // $VF: renamed from: a bn
   private static class_1 field_1139 = new class_1();
   // $VF: renamed from: h int
   private int field_1140;
   // $VF: renamed from: j boolean
   private boolean field_1141;
   // $VF: renamed from: i int
   private int field_1142;
   // $VF: renamed from: j int
   private int field_1143;
   // $VF: renamed from: k int
   private int field_1144;
   // $VF: renamed from: l int
   private int field_1145;
   // $VF: renamed from: b cm
   private class_96 field_1146;
   // $VF: renamed from: e boolean
   public boolean field_1147;
   // $VF: renamed from: a long
   private long field_1148;
   // $VF: renamed from: k boolean
   private boolean field_1149;
   // $VF: renamed from: f boolean
   public boolean field_1150;
   // $VF: renamed from: g boolean
   public boolean field_1151;
   // $VF: renamed from: a aq
   private class_82 field_1152;
   // $VF: renamed from: l boolean
   private boolean field_1153;
   // $VF: renamed from: c float
   private float field_1154;
   // $VF: renamed from: d float
   private float field_1155;
   // $VF: renamed from: a dp[]
   private class_36[] field_1156;
   // $VF: renamed from: h boolean
   public boolean field_1157;
   // $VF: renamed from: i boolean
   public boolean field_1158;
   // $VF: renamed from: e int
   public int field_1159;

   public class_85(int var1, int var2, boolean var3, class_96 var4, class_101 var5, int var6, int var7, int var8) {
      super(var1, var3, var4, var5, var6, var7, var8);
      this.field_1159 = var2;
      this.field_1136.method_170(var6, var7, var8);
      super.field_1116 = var1 != 19;
      this.field_1134 = new class_7();
      this.field_1152 = new class_82();
      this.field_1152.field_1094 = 50;
      this.field_1152.method_739(this.field_1136);
      this.field_1141 = var3 && class_3.method_73() > 15;
      if (var1 == 19) {
         var5.method_869(64);
         var5.method_873((byte)2);
         this.field_1141 = false;
         this.field_1154 = 2.1F;
         this.field_1155 = 1.5F;
      } else {
         int[] var9;
         if ((var9 = class_24.method_319(var5.field_1286, var2)) != null) {
            var5.method_872(var9[0], var9[1]);
            var5.method_873((byte)2);
         }

         this.field_1154 = this.field_1131;
         this.field_1155 = this.field_1132;
      }

      this.field_1149 = false;
      this.field_1150 = false;
      this.field_1151 = false;
      this.field_1153 = false;
      super.field_1117 = class_9.method_204();
      this.field_1158 = true;
   }

   // $VF: renamed from: a () void
   public final void method_741() {
      super.method_741();
      if (this.field_1134 != null) {
         this.field_1134.method_189();
      }

      this.field_1134 = null;
      if (this.field_1152 != null) {
         this.field_1152.method_736();
      }

      this.field_1152 = null;
      this.field_1146 = null;
      this.field_1156 = null;
   }

   // $VF: renamed from: b (boolean) void
   public final void method_759(boolean var1) {
      this.field_1149 = var1;
      if (var1) {
         super.field_1117 = null;
      }
   }

   // $VF: renamed from: c () boolean
   public final boolean method_760() {
      return this.field_1149 && !super.field_1116;
   }

   // $VF: renamed from: d () boolean
   public final boolean method_761() {
      return !super.field_1116;
   }

   // $VF: renamed from: b () void
   public final void method_762() {
      super.field_1116 = false;
      this.method_742(false);
      if (this.field_1149) {
         class_4.method_161(0, 0, false, true);
      } else if (class_3.method_108().method_372(super.field_1117.field_636)) {
         class_3.method_82();
         class_3.method_108().method_373(super.field_1117);
         class_4.method_161(super.field_1117.field_626, super.field_1117.field_636, false, false);
      } else {
         class_4.method_161(super.field_1117.field_626, super.field_1117.field_636, true, false);
      }
   }

   // $VF: renamed from: a (int, int, int) void
   public final void method_763(int var1, int var2, int var3) {
      super.field_1111 = var1;
      super.field_1112 = var2;
      super.field_1113 = var3;
      super.field_1103.method_841(var1, var2, var3);
      this.field_1136.method_170(var1, var2, var3);
      if (this.field_1152 != null) {
         this.field_1152.method_739(this.field_1136);
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_743(int var1) {
      this.field_1141 = false;
      this.field_1131 = var1;
      this.field_1154 = this.field_1131;
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      if (super.field_1101 == 4 && !super.field_1116) {
         this.method_742(false);
      } else {
         this.field_1143 = (int)(this.field_1143 + var1);
         this.field_1142 = (int)(this.field_1142 + var1);
         this.field_1148 = var1;
         this.field_1135 = super.field_1103.method_844(this.field_1135);
         if (this.field_1134 != null) {
            super.field_1109.method_169(this.field_1135);
            if (super.field_1101 != 4 && super.field_1101 != 3) {
               super.field_1110 = super.field_1103.method_851(super.field_1110);
               super.field_1110.method_182();
               super.field_1110.method_179(32768, super.field_1110);
               super.field_1109.method_177(super.field_1110);
            }

            this.field_1134.method_190(super.field_1109, (int)var1);
            this.field_1145 = (int)(this.field_1145 + var1);
            if (this.field_1145 > 200) {
               if (this.field_1152 != null) {
                  this.field_1152.method_738(this.field_1135);
               }

               this.field_1145 = 0;
            }
         }

         super.field_1102.field_1270 = super.field_1103.field_1283;
         if (super.field_1101 != 4 && super.field_1101 != 3) {
            super.field_1102.method_832(var1);
            class_96[] var3 = super.field_1102.field_1253;
            if (super.field_1102.field_1253 != null && this.field_1134 != null) {
               if (!this.field_1157) {
                  this.field_1140 = -1;
               } else if (this.field_1140 >= 0 && !var3[this.field_1140].field_1268) {
                  this.field_1157 = false;
               }

               this.field_1146 = null;
               if (this.field_1142 > 5000) {
                  if (this.field_1153) {
                     this.field_1153 = false;
                  } else {
                     this.field_1153 = class_41.field_540.nextInt(100) < 20;
                  }

                  this.field_1142 = 0;
                  if (class_41.field_540.nextInt(100) < 30 && var3.length > 1) {
                     this.field_1157 = false;

                     for (int var9 = 0; var9 < 5 && !this.field_1157; var9++) {
                        this.field_1140 = class_41.field_540.nextInt(var3.length);
                        if (var3[this.field_1140].field_1268) {
                           super.field_1109 = var3[this.field_1140].method_823(super.field_1109);
                           if (this.field_1135.field_138 - super.field_1109.field_138 < 50000
                              && this.field_1135.field_138 - super.field_1109.field_138 > -50000
                              && this.field_1135.field_139 - super.field_1109.field_139 < 50000
                              && this.field_1135.field_139 - super.field_1109.field_139 > -50000
                              && this.field_1135.field_140 - super.field_1109.field_140 < 50000
                              && this.field_1135.field_140 - super.field_1109.field_140 > -50000) {
                              this.field_1157 = true;
                              break;
                           }
                        }
                     }

                     if (!this.field_1157) {
                        this.field_1140 = 0;
                     }
                  } else {
                     this.field_1140 = 0;
                  }

                  if (var3[this.field_1140].field_1268 && !var3[this.field_1140].method_824()) {
                     super.field_1109 = var3[this.field_1140].method_823(super.field_1109);
                     if (this.field_1135.field_138 - super.field_1109.field_138 < 50000
                        && this.field_1135.field_138 - super.field_1109.field_138 > -50000
                        && this.field_1135.field_139 - super.field_1109.field_139 < 50000
                        && this.field_1135.field_139 - super.field_1109.field_139 > -50000
                        && this.field_1135.field_140 - super.field_1109.field_140 < 50000
                        && this.field_1135.field_140 - super.field_1109.field_140 > -50000) {
                        this.field_1140 = this.field_1140;
                     } else {
                        this.field_1140 = -1;
                     }
                  } else {
                     this.field_1140 = -1;
                  }
               } else if (!this.field_1157) {
                  for (int var4 = 0; var4 < var3.length; var4++) {
                     if (var3[var4].field_1268 && !var3[var4].method_824()) {
                        super.field_1109 = var3[var4].method_823(super.field_1109);
                        if (this.field_1135.field_138 - super.field_1109.field_138 < 50000
                           && this.field_1135.field_138 - super.field_1109.field_138 > -50000
                           && this.field_1135.field_139 - super.field_1109.field_139 < 50000
                           && this.field_1135.field_139 - super.field_1109.field_139 > -50000
                           && this.field_1135.field_140 - super.field_1109.field_140 < 50000
                           && this.field_1135.field_140 - super.field_1109.field_140 > -50000) {
                           this.field_1140 = var4;
                           break;
                        }
                     }
                  }
               }

               this.field_1147 = false;
               if (this.field_1140 == -1 && super.field_1107 != null) {
                  if (super.field_1107.method_219() != null && super.field_1102.field_1268) {
                     super.field_1107
                        .method_223(super.field_1102.field_1270.field_13, super.field_1102.field_1270.field_14, super.field_1102.field_1270.field_15);
                     if (super.field_1107.method_219() != null) {
                        this.field_1137.field_138 = super.field_1107.method_219().field_1161;
                        this.field_1137.field_139 = super.field_1107.method_219().field_1162;
                        this.field_1137.field_140 = super.field_1107.method_219().field_1163;
                        this.field_1147 = true;
                     }
                  } else {
                     this.field_1140 = 0;
                     this.field_1146 = super.field_1102.method_805(this.field_1140);
                     super.field_1109 = this.field_1146.method_823(super.field_1109);
                     this.field_1137.field_138 = super.field_1109.field_138;
                     this.field_1137.field_139 = super.field_1109.field_139;
                     this.field_1137.field_140 = super.field_1109.field_140;
                  }
               } else {
                  if (this.field_1140 < 0) {
                     this.field_1140 = 0;
                  }

                  this.field_1146 = super.field_1102.method_805(this.field_1140);
                  super.field_1109 = this.field_1146.method_823(super.field_1109);
                  this.field_1137.field_138 = super.field_1109.field_138;
                  this.field_1137.field_139 = super.field_1109.field_139;
                  this.field_1137.field_140 = super.field_1109.field_140;
               }
            } else if (super.field_1107 != null) {
               super.field_1107.method_223(super.field_1102.field_1270.field_13, super.field_1102.field_1270.field_14, super.field_1102.field_1270.field_15);
               if (super.field_1107.method_219() != null) {
                  this.field_1137.field_138 = super.field_1107.method_219().field_1161;
                  this.field_1137.field_139 = super.field_1107.method_219().field_1162;
                  this.field_1137.field_140 = super.field_1107.method_219().field_1163;
                  this.field_1147 = true;
               }
            } else {
               super.field_1101 = 5;
            }
         }

         this.field_1138.field_138 = this.field_1137.field_138 - this.field_1135.field_138;
         this.field_1138.field_139 = this.field_1137.field_139 - this.field_1135.field_139;
         this.field_1138.field_140 = this.field_1137.field_140 - this.field_1135.field_140;
         if (!super.field_1105 && super.field_1101 == 5) {
            super.field_1109 = super.field_1106.field_774.field_202.method_823(super.field_1109);
            this.field_1138.field_138 = super.field_1109.field_138 - this.field_1135.field_138;
            this.field_1138.field_139 = super.field_1109.field_139 - this.field_1135.field_139;
            this.field_1138.field_140 = super.field_1109.field_140 - this.field_1135.field_140;
            if (this.field_1138.field_138 < 10000
               && this.field_1138.field_138 > -10000
               && this.field_1138.field_139 < 10000
               && this.field_1138.field_139 > -10000
               && this.field_1138.field_140 < 10000
               && this.field_1138.field_140 > -10000) {
               super.field_1101 = 1;
               super.field_1102.field_1268 = true;
            }
         }

         if (this.field_1156 != null) {
            for (int var6 = 0; var6 < this.field_1156.length; var6++) {
               this.field_1156[var6]
                  .method_402(super.field_1102.field_1270.field_13, super.field_1102.field_1270.field_14, super.field_1102.field_1270.field_15);
            }
         }

         if (super.field_1102.field_1256 <= 0 && super.field_1101 != 3 && super.field_1101 != 4) {
            if (super.field_1105) {
               if (this.field_1159 == 2 && !super.field_1102.field_1276) {
                  class_3.method_136();
               }

               super.field_1106.method_547(super.field_1104, super.field_1102.field_1276);
            } else {
               super.field_1106.method_549();
            }

            super.field_1101 = 3;
            if (super.field_1108 != null) {
               super.field_1108.method_196(this.field_1135.field_138, this.field_1135.field_139, this.field_1135.field_140);
            }

            int var7 = class_124.method_943(40000, this.field_1138.method_183());
            float var10 = 1.0F - var7 / 40000.0F;
            int var5 = class_41.field_539.field_562;
            class_41.field_539.method_426(super.field_1104 == 19 ? 9 : 6, (int)(var5 * var10));
            if (super.field_1116) {
               this.field_1136.method_169(this.field_1135);
               super.field_1103 = class_25.method_328(17);
               super.field_1103.field_1294 = 2;
               super.field_1103.method_842(this.field_1135);
               super.field_1102.field_1270 = super.field_1103.field_1283;
               super.field_1102.field_1272 = this;
               this.field_1152 = null;
            }
         }

         switch (super.field_1101) {
            case 0:
               super.field_1101 = 1;
               break;
            case 1:
               if (this.field_1141) {
                  if (this.field_1143 > 5000 && this.field_1154 != 4.0F) {
                     if (class_41.field_540.nextInt(100) < this.field_1133) {
                        this.field_1144 = class_41.field_540.nextInt(3000) + 5000;
                     }

                     this.field_1143 = 0;
                     this.field_1154 = 4.0F;
                     this.field_1155 = 1.3F;
                  }

                  if (this.field_1154 == 4.0F && this.field_1143 > this.field_1144) {
                     this.field_1143 = 0;
                     this.field_1154 = this.field_1131;
                     this.field_1155 = this.field_1132;
                  }
               }

               if (this.field_1146 != null
                  && !this.field_1147
                  && this.field_1138.field_138 < 8000
                  && this.field_1138.field_138 > -8000
                  && this.field_1138.field_139 < 8000
                  && this.field_1138.field_139 > -8000
                  && this.field_1138.field_140 < 8000
                  && this.field_1138.field_140 > -8000) {
                  this.field_1138 = super.field_1103.method_854(this.field_1138);
               }

               this.field_1138.method_182();
               super.field_1110.method_169(this.field_1138);
               this.field_1138 = super.field_1103.method_867(field_1139).method_41(super.field_1110, this.field_1138);
               this.field_1138.field_139 = -this.field_1138.field_139;
               if (!this.field_1147
                  && this.field_1146 != null
                  && this.field_1138.field_138 < this.field_1130
                  && this.field_1138.field_138 > -this.field_1130
                  && this.field_1138.field_139 < this.field_1130
                  && this.field_1138.field_139 > -this.field_1130
                  && this.field_1137.field_138 - this.field_1135.field_138 < 35000
                  && this.field_1137.field_138 - this.field_1135.field_138 > -35000
                  && this.field_1137.field_139 - this.field_1135.field_139 < 35000
                  && this.field_1137.field_139 - this.field_1135.field_139 > -35000
                  && this.field_1137.field_140 - this.field_1135.field_140 < 35000
                  && this.field_1137.field_140 - this.field_1135.field_140 > -35000) {
                  if (this.field_1146.field_1268 && !this.field_1146.method_824()) {
                     super.field_1102.method_831(0, var1, false);
                  } else {
                     this.field_1157 = false;
                  }
               }

               if (!this.field_1153) {
                  super.field_1109.method_169(super.field_1103.method_851(super.field_1109));
                  super.field_1110.method_177(super.field_1109);
                  super.field_1110.method_182();
                  super.field_1110.method_178((int)((float)var1 * this.field_1155));
                  this.field_1138 = super.field_1109.method_174(super.field_1110, this.field_1138);
                  this.field_1138.method_182();
                  super.field_1103.field_1283.method_44(this.field_1138);
               }

               super.field_1103.method_843((int)((float)var1 * this.field_1154));
            case 2:
            default:
               break;
            case 3:
               this.field_1158 = false;
               if (super.field_1108 != null) {
                  if (super.field_1108.method_198()) {
                     super.field_1101 = 4;
                  }
               } else {
                  super.field_1101 = 4;
               }
               break;
            case 4:
               if (super.field_1116 && super.field_1102.field_1268) {
                  if (!super.field_1114) {
                     super.field_1103.method_839(0, -((int)var1) / 2, 0);
                  }

                  if (super.field_1103.method_844(super.field_1109).field_139 < this.field_1136.field_139 - 30000) {
                     this.field_1150 = true;
                     this.method_742(false);
                  }
               } else {
                  this.method_742(false);
               }
               break;
            case 5:
               if (super.field_1105
                  && this.field_1138.field_138 < 50000
                  && this.field_1138.field_138 > -50000
                  && this.field_1138.field_139 < 50000
                  && this.field_1138.field_139 > -50000
                  && this.field_1138.field_140 < 50000
                  && this.field_1138.field_140 > -50000) {
                  super.field_1101 = 1;
                  super.field_1102.field_1268 = true;
               }
         }

         if (this.field_1158) {
            class_83[] var8 = super.field_1106.field_778;
            if (super.field_1106.field_778 != null) {
               for (int var11 = 0; var11 < var8.length; var11++) {
                  if (var8[var11] != null && var8[var11].method_754(super.field_1103.method_844(super.field_1110))) {
                     super.field_1110 = var8[var11].method_755(super.field_1103.method_844(super.field_1110));
                     if (super.field_1110 != null) {
                        super.field_1109.method_169(super.field_1103.method_851(super.field_1109));
                        super.field_1110.method_177(super.field_1109);
                        super.field_1110.method_178((int)((float)var1 * 5.0F));
                        this.field_1135 = super.field_1109.method_174(super.field_1110, this.field_1135);
                        this.field_1135.method_182();
                        super.field_1103.field_1283.method_44(this.field_1135);
                        super.field_1103.method_843((int)((float)var1 * this.field_1154));
                     }
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (super.field_1101 != 4 && super.field_1101 != 3 || super.field_1116 && super.field_1102.field_1268) {
         super.method_756();
         if (this.field_1134 != null) {
            this.field_1134.method_192();
         }

         if (this.field_1152 != null) {
            this.field_1152.method_740();
         }
      }

      if (super.field_1101 == 3 && super.field_1108.method_195() > 1) {
         super.method_756();
      }

      if (super.field_1101 == 3 && super.field_1108 != null) {
         super.field_1108.method_197(this.field_1148);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      if (super.field_1101 != 4 && super.field_1101 != 3) {
         if (this.field_1156 != null) {
            for (int var4 = 0; var4 < this.field_1156.length; var4++) {
               if (this.field_1156[var4].method_403(var1, var2, var3)) {
                  return true;
               }
            }
         }

         return false;
      } else {
         return false;
      }
   }
}
