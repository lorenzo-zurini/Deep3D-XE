// $VF: renamed from: du
public final class class_29 {
   // $VF: renamed from: a v
   public class_5 field_398;
   // $VF: renamed from: a int
   public int field_399;

   public class_29(int var1, int var2, int var3, int var4) {
      this.field_398 = new class_5(var1, var2, var3);
      this.field_399 = var4;
   }

   public class_29() {
      this(0, 0, 0, 0);
   }

   public class_29(class_29 var1) {
      this.field_398.field_138 = var1.field_398.field_138;
      this.field_398.field_139 = var1.field_398.field_139;
      this.field_398.field_140 = var1.field_398.field_140;
      this.field_399 = var1.field_399;
   }

   // $VF: renamed from: a (du, du) du
   public final class_29 method_342(class_29 var1, class_29 var2) {
      if (this.field_399 == 0) {
         var2.method_344(var1);
         return var2;
      } else if (var1.field_399 == 0) {
         var2.method_344(this);
         return var2;
      } else {
         int var3 = var1.field_398.field_138 - this.field_398.field_138;
         int var4 = var1.field_398.field_139 - this.field_398.field_139;
         int var5 = var1.field_398.field_140 - this.field_398.field_140;
         int var6;
         int var7 = (var6 = var1.field_399 - this.field_399) * var6;
         int var8 = var3 * var3 + var4 * var4 + var5 * var5;
         if (var7 >= var8) {
            if (var6 >= 0) {
               var2.method_346(var1.field_398, var1.field_399);
               return var2;
            } else {
               var2.method_346(this.field_398, this.field_399);
               return var2;
            }
         } else {
            int var9 = class_124.method_941((long)var8 << 12);
            int var10 = (int)(((long)((var6 << 12) + var9) << 12) / (2 * var9));
            var2.method_345(
               this.field_398.field_138 + (int)(var10 * ((long)var3 << 12) >> 24),
               this.field_398.field_139 + (int)(var10 * ((long)var4 << 12) >> 24),
               this.field_398.field_140 + (int)(var10 * ((long)var5 << 12) >> 24),
               (var9 >> 12) + var1.field_399 + this.field_399 >> 1
            );
            return var2;
         }
      }
   }

   // $VF: renamed from: a (du) void
   public final void method_343(class_29 var1) {
      this.method_342(var1, this);
   }

   // $VF: renamed from: b (du) void
   public final void method_344(class_29 var1) {
      this.field_398.method_169(var1.field_398);
      this.field_399 = var1.field_399;
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_345(int var1, int var2, int var3, int var4) {
      this.field_398.field_138 = var1;
      this.field_398.field_139 = var2;
      this.field_398.field_140 = var3;
      this.field_399 = var4;
   }

   // $VF: renamed from: a (v, int) void
   public final void method_346(class_5 var1, int var2) {
      this.field_398.method_169(var1);
      this.field_399 = var2;
   }

   public final String toString() {
      return "AEBoundingSphere | x: "
         + this.field_398.field_138
         + " y: "
         + this.field_398.field_139
         + " z: "
         + this.field_398.field_140
         + " r: "
         + this.field_399;
   }
}
