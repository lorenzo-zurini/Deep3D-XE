// $VF: renamed from: an
public final class class_60 {
   // $VF: renamed from: a java.lang.String
   public String field_827;
   // $VF: renamed from: a int
   public int field_828;
   // $VF: renamed from: b int
   public int field_829;
   // $VF: renamed from: c int
   public int field_830;
   // $VF: renamed from: d int
   public int field_831;
   // $VF: renamed from: a boolean
   private boolean field_832;
   // $VF: renamed from: e int
   public int field_833;
   // $VF: renamed from: f int
   public int field_834;
   // $VF: renamed from: a dn[]
   public class_51[] field_835;
   // $VF: renamed from: a aa[]
   public class_46[] field_836;
   // $VF: renamed from: a be[]
   public class_32[] field_837;
   // $VF: renamed from: a al[]
   public class_95[] field_838;

   public class_60(String var1, int var2, int var3, int var4, int var5, int var6) {
      this.field_827 = var1;
      this.field_828 = var2;
      this.field_833 = var3;
      this.field_829 = var4;
      this.field_830 = var5;
      this.field_831 = var6;
      this.field_832 = false;
      this.field_835 = null;
      this.field_837 = null;
      this.field_838 = null;
      this.field_834 = class_44.method_435(var6);
   }

   public class_60() {
      this("", 0, 0, 0, 0, 0);
   }

   // $VF: renamed from: a () float
   public final float method_584() {
      return 1.0F - class_124.method_942(0, this.field_834 - 15000) / 15000.0F;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_585() {
      return class_44.method_433()[this.field_828];
   }

   // $VF: renamed from: a () void
   public final void method_586() {
      if (!this.method_585()) {
         this.field_832 = true;
         class_3.method_106();
         class_44.method_434(this.field_828);
      }
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_587(int var1) {
      if (this.field_835 == null) {
         return false;
      } else {
         for (int var2 = 0; var2 < this.field_835.length; var2++) {
            if (this.field_835[var2] != null && this.field_835[var2].field_711 == var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (dn) void
   public final void method_588(class_51 var1) {
      boolean var2 = false;
      if (this.field_835 == null) {
         this.field_835 = new class_51[]{var1};
      } else {
         boolean var3 = false;
         class_51[] var4 = new class_51[this.field_835.length + 1];
         System.arraycopy(this.field_835, 0, var4, 0, this.field_835.length);
         var4[var4.length - 1] = var1;
         this.field_835 = var4;
      }
   }

   // $VF: renamed from: a (aa) void
   public final void method_589(class_46 var1) {
      int var2 = -1;
      if (this.field_836 == null) {
         this.field_836 = new class_46[]{var1};
      } else {
         for (int var3 = 0; var3 < this.field_836.length; var3++) {
            if (this.field_836[var3].method_456(var1)) {
               var2 = var3;
               break;
            }
         }

         if (var2 < 0) {
            class_46[] var4 = new class_46[this.field_836.length + 1];
            System.arraycopy(this.field_836, 0, var4, 0, this.field_836.length);
            var4[var4.length - 1] = var1;
            this.field_836 = var4;
         }
      }
   }

   // $VF: renamed from: b (dn) void
   public final void method_590(class_51 var1) {
      int var2 = -1;

      for (int var3 = 0; var3 < this.field_835.length; var3++) {
         if (this.field_835[var3].method_507(var1)) {
            this.field_835[var3] = null;
            var2 = var3;
            break;
         }
      }

      if (var2 != -1) {
         if (this.field_835.length == 1) {
            this.field_835 = null;
         } else {
            class_51[] var4 = new class_51[this.field_835.length - 1];
            System.arraycopy(this.field_835, 0, var4, 0, var2);
            System.arraycopy(this.field_835, var2 + 1, var4, var2, this.field_835.length - var2 - 1);
            this.field_835 = var4;
         }
      }
   }

   // $VF: renamed from: a (al) void
   public final void method_591(class_95 var1) {
      if (this.field_838 != null) {
         boolean var2 = false;

         for (int var3 = 0; var3 < this.field_838.length; var3++) {
            if (this.field_838[var3] == var1) {
               this.field_838[var3] = null;
               var2 = true;
               break;
            }
         }

         if (!var2) {
            System.out.println("Station.removeMission() failed, mission not in list");
         } else {
            class_95[] var6 = new class_95[this.field_838.length - 1];
            int var4 = 0;

            for (int var5 = 0; var5 < this.field_838.length; var5++) {
               if (this.field_838[var5] != null) {
                  var6[var4++] = this.field_838[var5];
               }
            }

            this.field_838 = var6;
         }
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_592() {
      return !class_3.method_105()[this.field_828];
   }

   public final String toString() {
      return this.field_827
         + "\n"
         + "  tecLevel: \t\t"
         + this.field_833
         + "\n"
         + "  posX: \t\t"
         + this.field_829
         + "\n"
         + "  posY: \t\t"
         + this.field_830
         + "\n"
         + "  discovered: \t\t"
         + this.field_832
         + "\n"
         + "  equipment: \t\t"
         + this.field_835
         + "\n"
         + "  ships: \t\t"
         + this.field_837
         + "\n"
         + "  missions: \t\t"
         + this.field_838
         + "\n\n";
   }

   // $VF: renamed from: a (an) boolean
   public final boolean method_593(class_60 var1) {
      return this.field_827.equals(var1.field_827);
   }
}
