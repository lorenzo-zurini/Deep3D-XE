// $VF: renamed from: ce
public final class class_42 implements class_0 {
   // $VF: renamed from: a af
   public class_102 field_452;
   // $VF: renamed from: b af
   public class_102 field_453;
   // $VF: renamed from: c af
   public class_102 field_454;
   // $VF: renamed from: a x
   public class_3 field_455;
   // $VF: renamed from: b x
   public class_3 field_456;
   // $VF: renamed from: c x
   public class_3 field_457;
   // $VF: renamed from: d x
   public class_3 field_458;
   // $VF: renamed from: e x
   public class_3 field_459;
   // $VF: renamed from: a boolean
   public boolean field_460;
   // $VF: renamed from: f x
   private class_3 field_461 = new class_3();
   // $VF: renamed from: g x
   private class_3 field_462 = new class_3();
   // $VF: renamed from: a s
   private class_5 field_463;
   // $VF: renamed from: b boolean
   private boolean field_464 = false;
   // $VF: renamed from: c boolean
   private boolean field_465;
   // Deep3D-PC: the flight camera's field of view as a dolly zoom: the
   // sub's depth from the camera scales by this factor, so a wider view
   // keeps the sub's size and place on screen (class_64)
   public float deep3dDolly = 1.0F;
   private final class_3 deep3dOff = new class_3();
   private class_3 deep3dAim = new class_3();

   public class_42(class_102 var1, class_102 var2) {
      this(var1, var2, null);
   }

   public class_42(class_102 var1, class_102 var2, class_3 var3) {
      this.field_452 = var1;
      this.field_454 = var2;
      this.field_460 = true;
      this.field_459 = var3;
      if (var3 != null) {
         this.field_459.method_22();
      }

      if (this.field_455 == null) {
         this.field_455 = new class_3();
      }

      if (this.field_456 == null) {
         this.field_456 = new class_3();
      }

      if (this.field_457 == null) {
         this.field_457 = new class_3();
      }

      if (this.field_458 == null) {
         this.field_458 = new class_3();
      }

      if (var1 != null && var2 != null) {
         this.field_463 = new class_5(var1, var2);
         this.field_453 = var1;

         while (this.field_453.field_1336 != null) {
            this.field_453 = this.field_453.field_1336;
         }

         Object var4 = var2;

         while (((class_102)var4).field_1336 != null) {
            var4 = ((class_102)var4).field_1336;
         }

         if (var4 == this.field_453) {
            this.field_453 = null;
         }

         this.field_465 = var2 instanceof class_106;
         this.field_462 = var2.method_850().method_16(var1.method_850(), new class_3());
      }
   }

   // $VF: renamed from: a (af) void
   public final void method_368(class_102 var1) {
      this.field_452 = var1;
      if (this.field_463 == null && var1 != null) {
         this.field_463 = new class_5(var1, this.field_454);
      }

      if (this.field_463 != null) {
         this.field_463.field_45 = var1;
      }
   }

   // $VF: renamed from: b (af) void
   public final void method_369(class_102 var1) {
      this.field_454 = var1;
      if (this.field_463 == null && var1 != null) {
         this.field_463 = new class_5(this.field_452, var1);
      }

      if (this.field_463 != null) {
         this.field_463.field_48 = var1;
      }

      this.field_465 = var1 instanceof class_106;
   }

   // $VF: renamed from: a (x) void
   public final void method_370(class_3 var1) {
      this.field_457.method_9(var1);
   }

   // $VF: renamed from: b () void
   public final void method_371() {
      this.field_464 = true;
      this.field_457 = this.field_452.field_1342.method_507(this.field_462, this.field_457);
      this.field_454.method_846(this.field_457);
   }

   // $VF: renamed from: c () void
   public final void method_372() {
      this.field_464 = false;
   }

   // $VF: renamed from: a () void
   public final void method_0() {
      if (this.field_460) {
         if (this.field_464) {
            this.field_463.method_0();
            return;
         }

         if (this.field_452 != null) {
            this.field_455 = this.field_452.method_857();
            this.field_455.method_22();
            this.field_456 = this.field_452.field_1342.method_507(this.field_462, this.field_456);
            this.field_457.field_37 = this.field_457.field_37 - (this.field_457.field_37 - this.field_456.field_37 >> 8);
            this.field_457.field_38 = this.field_457.field_38 - (this.field_457.field_38 - this.field_456.field_38 >> 8);
            this.field_457.field_39 = this.field_457.field_39 - (this.field_457.field_39 - this.field_456.field_39 >> 8);
            this.field_456 = this.field_452.field_1342.method_507(this.field_461, this.field_456);
            this.field_456.field_37 = this.field_456.field_37 - this.field_457.field_37;
            this.field_456.field_38 = this.field_456.field_38 - this.field_457.field_38;
            this.field_456.field_39 = this.field_456.field_39 - this.field_457.field_39;
            if (this.field_465) {
               this.field_456.field_37 = -this.field_456.field_37;
               this.field_456.field_38 = -this.field_456.field_38;
               this.field_456.field_39 = -this.field_456.field_39;
            }

            this.field_456.method_22();
            this.field_458 = this.field_455.method_13(this.field_456, this.field_458);
            this.field_455 = this.field_456.method_13(this.field_458, this.field_455);
            this.field_458.method_22();
            this.field_454.method_872(this.field_458, this.field_455, this.field_456);
            if (this.deep3dDolly != 1.0F && this.field_465) {
               // Deep3D-PC: slide along the view axis only, by the sub's depth
               // times (1 - dolly): its size and place on screen stay put
               this.deep3dAim = this.field_452.method_849(this.deep3dAim);
               long var1 = (long)(this.deep3dAim.field_37 - this.field_457.field_37) * -this.field_456.field_37
                  + (long)(this.deep3dAim.field_38 - this.field_457.field_38) * -this.field_456.field_38
                  + (long)(this.deep3dAim.field_39 - this.field_457.field_39) * -this.field_456.field_39;
               float var2 = var1 / 4096.0F * (1.0F - this.deep3dDolly) / 4096.0F;
               this.deep3dOff.method_10(
                  this.field_457.field_37 - (int)(this.field_456.field_37 * var2),
                  this.field_457.field_38 - (int)(this.field_456.field_38 * var2),
                  this.field_457.field_39 - (int)(this.field_456.field_39 * var2)
               );
               this.field_454.method_846(this.deep3dOff);
            } else {
               this.field_454.method_846(this.field_457);
            }
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_1() {
      return this.field_460;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_373(boolean var1) {
      this.field_460 = var1;
      this.field_463.field_53 = var1;
   }

   // $VF: renamed from: b (x) void
   public final void method_374(class_3 var1) {
      this.field_457.method_9(var1);
   }

   // $VF: renamed from: c (x) void
   public final void method_375(class_3 var1) {
      this.field_461.method_9(var1);
   }

   // $VF: renamed from: d (x) void
   public final void method_376(class_3 var1) {
      this.field_462.method_9(var1);
   }
}
