// $VF: renamed from: at
public class class_91 extends class_90 {
   // $VF: renamed from: a dp[]
   public class_36[] field_1198;
   // $VF: renamed from: e boolean
   public boolean field_1199;
   // $VF: renamed from: f boolean
   public boolean field_1200;
   // $VF: renamed from: g boolean
   public boolean field_1201;

   public class_91(int var1, class_101 var2, int var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
      super.field_1111 = var3;
      super.field_1112 = var4;
      super.field_1113 = var5;
      if (var2 != null) {
         if (var1 == 15) {
            super.field_1103.field_1294 = 2;
            super.field_1103.method_874();
            this.field_1199 = false;
            this.field_1200 = false;
            super.field_1102.method_801(15000);
         }

         this.field_1198 = new class_36[1];
         this.field_1198[0] = new class_37(var3, var4, var5, 0, 0, 0, 15000, 15000, 8000);
         this.field_1201 = false;
      }
   }

   // $VF: renamed from: b () void
   public final void method_775() {
      this.field_1201 = true;
   }

   // $VF: renamed from: b (int) void
   public final void method_776(int var1) {
      super.field_1103.method_860(0, var1, 0);
   }

   // $VF: renamed from: c () void
   public void method_756() {
      super.method_756();
   }

   // $VF: renamed from: a (long) void
   public void method_752(long var1) {
      if (this.field_1199) {
         if (super.field_1103.method_871() == 19) {
            super.field_1103.method_872(20, 39);
            super.field_1103.method_873((byte)2);
            this.field_1200 = true;
         }
      } else if (!this.field_1200) {
         super.field_1103.method_856(0, 0, (int)var1 >> 1);
      }

      super.field_1109 = class_41.field_527.field_249.method_845(super.field_1109);
      super.field_1110.method_170(super.field_1195, super.field_1196, super.field_1197);
      super.field_1110.method_176(super.field_1109, class_90.field_1194);
      int var3;
      if ((var3 = class_90.field_1194.method_183()) > org.deep3d.Config.impostorDistance()) {
         class_90.field_1194.method_182();
         class_90.field_1194.method_178(org.deep3d.Config.impostorDistance());
         class_90.field_1194.method_175(super.field_1109);
         super.field_1103.method_842(class_90.field_1194);
         int var4 = (int)((float)org.deep3d.Config.impostorDistance() / var3 * 4096.0F);
         super.field_1103.method_865(var4, var4, var4);
      } else {
         super.field_1103.method_865(4096, 4096, 4096);
         super.field_1103.method_841(super.field_1195, super.field_1196, super.field_1197);
      }
   }

   // $VF: renamed from: a (int, int, int) boolean
   public boolean method_753(int var1, int var2, int var3) {
      if (var1 - super.field_1195 < super.field_1102.field_1255
         && var1 - super.field_1195 > -super.field_1102.field_1255
         && var2 - super.field_1196 < super.field_1102.field_1255
         && var2 - super.field_1196 > -super.field_1102.field_1255
         && var3 - super.field_1197 < super.field_1102.field_1255
         && var3 - super.field_1197 > -super.field_1102.field_1255) {
         this.method_777();
         return true;
      } else {
         this.method_778();
         return false;
      }
   }

   // $VF: renamed from: g () void
   public final void method_777() {
      if (this.field_1201 && !this.field_1199 && class_3.method_62() == class_95.field_1225 || !this.field_1201) {
         super.field_1103.method_872(0, 19);
         super.field_1103.method_870(0);
         super.field_1103.method_873((byte)1);
         this.field_1199 = true;
         class_41.field_539.method_427(3);
      }
   }

   // $VF: renamed from: h () void
   public final void method_778() {
      if (this.field_1199) {
         super.field_1103.method_872(0, super.field_1103.method_871());
         super.field_1103.method_873((byte)3);
         this.field_1199 = false;
         this.field_1200 = false;
         class_41.field_539.method_427(3);
      }
   }

   // $VF: renamed from: a (v) boolean
   public boolean method_754(class_5 var1) {
      return this.field_1198 != null ? this.field_1198[0].method_404(var1.field_138, var1.field_139, var1.field_140) : false;
   }

   // $VF: renamed from: b (v) v
   public class_5 method_755(class_5 var1) {
      return this.field_1198 != null ? this.field_1198[0].method_401(var1) : null;
   }
}
