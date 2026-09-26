import com.mascotcapsule.micro3d.v3.FigureLayout;

// $VF: renamed from: ag
public final class class_112 extends class_111 {
   // $VF: renamed from: a com.mascotcapsule.micro3d.v3.FigureLayout
   public FigureLayout field_1382;

   public class_112(int var1, int var2, int var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
   }

   public class_112(class_112 var1) {
      super(var1);
      this.field_1382 = var1.field_1382;
   }

   // $VF: renamed from: a () ae
   public final class_97 method_836() {
      return new class_112(this);
   }

   // $VF: renamed from: g (int, int, int) void
   public final void method_895(int var1, int var2, int var3) {
      super.method_895(var1, var2, var3);
      if (this.field_1382 == null) {
         this.field_1382 = new FigureLayout();
      }

      int var4;
      int var5 = (int)(
         (long)(var4 = (int)(8192L * var2 * class_124.method_936(var1 >> 1) / class_124.method_937(var1 >> 1))) * super.field_1378 / super.field_1379
      );
      this.field_1382.setPerspective(var2, var3, var5, var4);
      this.field_1382.setCenter(super.field_1378 >> 1, super.field_1379 >> 1);
   }
}
