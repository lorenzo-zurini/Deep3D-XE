// $VF: renamed from: du
public final class class_15 {
   // $VF: renamed from: a x
   public class_3 field_148;
   // $VF: renamed from: a int
   public int field_149;

   public class_15(int var1, int var2, int var3, int var4) {
      this.field_148 = new class_3(var1, var2, var3);
      this.field_149 = var4;
   }

   public class_15() {
      this(0, 0, 0, 0);
   }

   public class_15(class_15 var1) {
      this.field_148.field_37 = var1.field_148.field_37;
      this.field_148.field_38 = var1.field_148.field_38;
      this.field_148.field_39 = var1.field_148.field_39;
      this.field_149 = var1.field_149;
   }

   // $VF: renamed from: a (du, du) du
   public final class_15 method_86(class_15 var1, class_15 var2) {
      if (this.field_149 == 0) {
         var2.method_88(var1);
         return var2;
      } else if (var1.field_149 == 0) {
         var2.method_88(this);
         return var2;
      } else {
         int var3 = var1.field_148.field_37 - this.field_148.field_37;
         int var4 = var1.field_148.field_38 - this.field_148.field_38;
         int var5 = var1.field_148.field_39 - this.field_148.field_39;
         int var6;
         int var7 = (var6 = var1.field_149 - this.field_149) * var6;
         int var8 = var3 * var3 + var4 * var4 + var5 * var5;
         if (var7 >= var8) {
            if (var6 >= 0) {
               var2.method_90(var1.field_148, var1.field_149);
               return var2;
            } else {
               var2.method_90(this.field_148, this.field_149);
               return var2;
            }
         } else {
            int var9 = class_16.method_96((long)var8 << 12);
            int var10 = (int)(((long)((var6 << 12) + var9) << 12) / (2 * var9));
            var2.method_89(
               this.field_148.field_37 + (int)(var10 * ((long)var3 << 12) >> 24),
               this.field_148.field_38 + (int)(var10 * ((long)var4 << 12) >> 24),
               this.field_148.field_39 + (int)(var10 * ((long)var5 << 12) >> 24),
               (var9 >> 12) + var1.field_149 + this.field_149 >> 1
            );
            return var2;
         }
      }
   }

   // $VF: renamed from: a (du) void
   public final void method_87(class_15 var1) {
      this.method_86(var1, this);
   }

   // $VF: renamed from: b (du) void
   public final void method_88(class_15 var1) {
      this.field_148.method_9(var1.field_148);
      this.field_149 = var1.field_149;
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_89(int var1, int var2, int var3, int var4) {
      this.field_148.field_37 = var1;
      this.field_148.field_38 = var2;
      this.field_148.field_39 = var3;
      this.field_149 = var4;
   }

   // $VF: renamed from: a (x, int) void
   public final void method_90(class_3 var1, int var2) {
      this.field_148.method_9(var1);
      this.field_149 = var2;
   }

   public final String toString() {
      return "AEBoundingSphere | x: " + this.field_148.field_37 + " y: " + this.field_148.field_38 + " z: " + this.field_148.field_39 + " r: " + this.field_149;
   }
}
