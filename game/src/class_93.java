// $VF: renamed from: d
public final class class_93 extends class_83 {
   // $VF: renamed from: c v
   private class_5 field_1206 = new class_5();
   // $VF: renamed from: a p
   private class_55 field_1207 = new class_55();
   // $VF: renamed from: a long
   private long field_1208;
   // $VF: renamed from: b long
   private long field_1209;
   // $VF: renamed from: b cm
   private class_96 field_1210;
   // $VF: renamed from: a aj
   public class_103 field_1211;

   public class_93(int var1, boolean var2, class_96 var3, class_101 var4, int var5, int var6, int var7) {
      super(var1, var2, var3, var4, var5, var6, var7);
      super.field_1102.field_1270 = var4.field_1283;
      this.field_1206.method_170(var5, var6, var7);
      super.field_1101 = 5;
      var4.method_872(0, 0);
      var4.method_874();
   }

   // $VF: renamed from: a () void
   public final void method_741() {
      super.method_741();
      this.field_1210 = null;
      this.field_1211 = null;
   }

   // $VF: renamed from: b () void
   public final void method_783() {
      if (this.field_1207.field_748 < 3000.0F && this.field_1207.field_749 < 3000.0F && this.field_1207.field_750 < 3000.0F) {
         this.field_1210.method_822(25);
      }

      super.field_1101 = 999;
      if (super.field_1108 != null) {
         super.field_1108.method_196(super.field_1103.method_846().field_138, super.field_1103.method_846().field_139, super.field_1103.method_846().field_140);
      }

      super.field_1102.field_1268 = false;
      super.field_1106.method_547(super.field_1104, super.field_1102.field_1276);
   }

   // $VF: renamed from: a (long) void
   public final void method_752(long var1) {
      if (super.field_1101 != 4) {
         this.field_1208 = var1;
         super.field_1102.field_1270 = super.field_1103.field_1283;
         if (super.field_1101 != 4 && super.field_1101 != 3 && super.field_1101 != 999) {
            super.field_1102.method_832(var1);
            class_96[] var3 = super.field_1102.field_1253;
            if (super.field_1102.field_1253 != null) {
               int var4 = 0;
               this.field_1210 = null;

               for (int var5 = 0; var5 < var3.length; var5++) {
                  if (var3[var5].field_1268) {
                     super.field_1109 = var3[var5].method_823(super.field_1109);
                     this.field_1206 = super.field_1103.method_844(this.field_1206);
                     this.field_1207.field_748 = this.field_1206.field_138 - super.field_1109.field_138;
                     this.field_1207.field_749 = this.field_1206.field_139 - super.field_1109.field_139;
                     this.field_1207.field_750 = this.field_1206.field_140 - super.field_1109.field_140;
                     if (super.field_1101 != 1
                        && this.field_1207.field_748 < 3000.0F
                        && this.field_1207.field_748 > -3000.0F
                        && this.field_1207.field_749 < 3000.0F
                        && this.field_1207.field_749 > -3000.0F
                        && this.field_1207.field_750 < 3000.0F
                        && this.field_1207.field_750 > -3000.0F) {
                        super.field_1101 = 1;
                        super.field_1103.method_872(1, 1);
                        super.field_1103.method_873((byte)2);
                        this.field_1209 = 0L;
                        super.field_1102.method_806(super.field_1102.field_1257);
                        class_41.field_539.method_427(11);
                        var4 = var5;
                        break;
                     }
                  }
               }

               this.field_1210 = super.field_1102.method_805(var4);
            }

            if (super.field_1102.field_1256 <= 0 && super.field_1101 != 5 && super.field_1101 != 3 && super.field_1101 != 4) {
               super.field_1102.field_1268 = false;
               super.field_1106.method_547(super.field_1104, super.field_1102.field_1276);
               super.field_1101 = 3;
               this.field_1209 = 0L;
               if (this.field_1211 != null) {
                  this.field_1211.method_887(this.field_1206.field_138, this.field_1206.field_139, this.field_1206.field_140);
               }
            }
         }

         this.field_1209 += var1;
         super.field_1103.method_839(0, class_124.method_936((int)this.field_1209) >> 6, 0);
         switch (super.field_1101) {
            case 0:
               super.field_1101 = 5;
               return;
            case 1:
               this.field_1209 += var1;
               super.field_1103.method_856(0, (int)var1 << 1, 0);
               if (this.field_1209 > 2000L) {
                  this.method_783();
                  return;
               }
               break;
            case 3:
               if (this.field_1211 != null) {
                  this.field_1211.method_885(var1);
               }

               this.field_1209 += var1;
               if (this.field_1209 > 2000L) {
                  super.field_1101 = 4;
                  super.field_1102.method_806(0);
               }
            case 4:
            default:
               break;
            case 5:
               super.field_1102.method_806(super.field_1102.field_1257);
               return;
            case 999:
               super.field_1103.method_864(2048, 2048, 2048);
               super.field_1103.method_856(0, (int)var1 << 1, 0);
               if (super.field_1108 == null) {
                  super.field_1101 = 4;
                  super.field_1102.method_806(0);
                  return;
               }

               if (super.field_1108.method_198()) {
                  super.field_1101 = 4;
                  super.field_1102.method_806(0);
                  return;
               }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_756() {
      if (super.field_1101 != 4) {
         if (super.field_1101 == 5) {
            class_41.field_527.method_265(super.field_1103);
         } else if (super.field_1101 != 3 && super.field_1101 != 4) {
            class_41.field_527.method_265(super.field_1103);
         }

         if (super.field_1101 == 3 && this.field_1211 != null) {
            this.field_1211.method_878();
         }

         if (super.field_1101 == 999 && super.field_1108 != null) {
            super.field_1108.method_197(this.field_1208);
         }
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public final boolean method_753(int var1, int var2, int var3) {
      return false;
   }
}
