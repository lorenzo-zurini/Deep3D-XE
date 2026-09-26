// $VF: renamed from: ao
public final class class_86 {
   // $VF: renamed from: a java.lang.String
   public String field_1133;
   // $VF: renamed from: a int
   public int field_1134;
   // $VF: renamed from: b int
   public int field_1135;
   // $VF: renamed from: c int
   public int field_1136;
   // $VF: renamed from: d int
   public int field_1137;
   // $VF: renamed from: a boolean
   private boolean field_1138;
   // $VF: renamed from: e int
   public int field_1139;
   // $VF: renamed from: f int
   public int field_1140;
   // $VF: renamed from: a dn[]
   public class_19[] field_1141;
   // $VF: renamed from: a ac[]
   public class_120[] field_1142;
   // $VF: renamed from: a bd[]
   public class_68[] field_1143;
   // $VF: renamed from: a am[]
   public class_87[] field_1144;

   public class_86(String var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_1133 = var1;
      this.field_1134 = var2;
      this.field_1139 = var3;
      this.field_1135 = var4;
      this.field_1136 = var5;
      this.field_1137 = var6;
      this.field_1138 = false;
      this.field_1141 = null;
      this.field_1143 = null;
      this.field_1144 = null;
      this.field_1140 = class_38.method_358(var6);
   }

   public class_86() {
      this("", 0, 0, 0, 0, 0);
   }

   // $VF: renamed from: a () float
   public final float method_744() {
      return 1.0F - class_16.method_97(0, this.field_1140 - 15000) / 15000.0F;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_745() {
      return class_38.method_356()[this.field_1134];
   }

   // $VF: renamed from: a () void
   public final void method_746() {
      if (!this.method_745()) {
         this.field_1138 = true;
         class_21.method_176();
         class_38.method_357(this.field_1134);
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_747(int var1) {
      if (this.field_1141 == null) {
         return false;
      } else {
         for (int var2 = 0; var2 < this.field_1141.length; var2++) {
            if (this.field_1141[var2] != null && this.field_1141[var2].field_166 == var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (dn) void
   public final void method_748(class_19 var1) {
      boolean var2 = false;
      if (this.field_1141 == null) {
         this.field_1141 = new class_19[]{var1};
      } else {
         boolean var3 = false;
         class_19[] var4 = new class_19[this.field_1141.length + 1];
         System.arraycopy(this.field_1141, 0, var4, 0, this.field_1141.length);
         var4[var4.length - 1] = var1;
         this.field_1141 = var4;
      }
   }

   // $VF: renamed from: a (ac) void
   public final void method_749(class_120 var1) {
      int var2 = -1;
      if (this.field_1142 == null) {
         this.field_1142 = new class_120[]{var1};
      } else {
         for (int var3 = 0; var3 < this.field_1142.length; var3++) {
            if (this.field_1142[var3].method_938(var1)) {
               var2 = var3;
               break;
            }
         }

         if (var2 < 0) {
            class_120[] var4 = new class_120[this.field_1142.length + 1];
            System.arraycopy(this.field_1142, 0, var4, 0, this.field_1142.length);
            var4[var4.length - 1] = var1;
            this.field_1142 = var4;
         }
      }
   }

   // $VF: renamed from: b (dn) void
   public final void method_750(class_19 var1) {
      int var2 = -1;

      for (int var3 = 0; var3 < this.field_1141.length; var3++) {
         if (this.field_1141[var3].method_122(var1)) {
            this.field_1141[var3] = null;
            var2 = var3;
            break;
         }
      }

      if (var2 != -1) {
         if (this.field_1141.length == 1) {
            this.field_1141 = null;
         } else {
            class_19[] var4 = new class_19[this.field_1141.length - 1];
            System.arraycopy(this.field_1141, 0, var4, 0, var2);
            System.arraycopy(this.field_1141, var2 + 1, var4, var2, this.field_1141.length - var2 - 1);
            this.field_1141 = var4;
         }
      }
   }

   // $VF: renamed from: a (am) void
   public final void method_751(class_87 var1) {
      if (this.field_1144 != null) {
         boolean var2 = false;

         for (int var3 = 0; var3 < this.field_1144.length; var3++) {
            if (this.field_1144[var3] == var1) {
               this.field_1144[var3] = null;
               var2 = true;
               break;
            }
         }

         if (!var2) {
            System.out.println("Station.removeMission() failed, mission not in list");
         } else {
            class_87[] var6 = new class_87[this.field_1144.length - 1];
            int var4 = 0;

            for (int var5 = 0; var5 < this.field_1144.length; var5++) {
               if (this.field_1144[var5] != null) {
                  var6[var4++] = this.field_1144[var5];
               }
            }

            this.field_1144 = var6;
         }
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_752() {
      return !class_21.method_175()[this.field_1134];
   }

   public final String toString() {
      return this.field_1133
         + "\n"
         + "  tecLevel: \t\t"
         + this.field_1139
         + "\n"
         + "  posX: \t\t"
         + this.field_1135
         + "\n"
         + "  posY: \t\t"
         + this.field_1136
         + "\n"
         + "  discovered: \t\t"
         + this.field_1138
         + "\n"
         + "  equipment: \t\t"
         + this.field_1141
         + "\n"
         + "  ships: \t\t"
         + this.field_1143
         + "\n"
         + "  missions: \t\t"
         + this.field_1144
         + "\n\n";
   }

   // $VF: renamed from: a (ao) boolean
   public final boolean method_753(class_86 var1) {
      return this.field_1133.equals(var1.field_1133);
   }
}
