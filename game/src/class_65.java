// $VF: renamed from: ce
public final class class_65 implements class_0 {
   // $VF: renamed from: a ae
   public class_97 field_874;
   // $VF: renamed from: b ae
   public class_97 field_875;
   // $VF: renamed from: c ae
   public class_97 field_876;
   // $VF: renamed from: a v
   public class_5 field_877;
   // $VF: renamed from: b v
   public class_5 field_878;
   // $VF: renamed from: c v
   public class_5 field_879;
   // $VF: renamed from: d v
   public class_5 field_880;
   // $VF: renamed from: e v
   public class_5 field_881;
   // $VF: renamed from: a boolean
   public boolean field_882;
   // $VF: renamed from: f v
   private class_5 field_883 = new class_5();
   // $VF: renamed from: g v
   private class_5 field_884 = new class_5();
   // $VF: renamed from: a s
   private class_71 field_885;
   // $VF: renamed from: b boolean
   private boolean field_886 = false;
   // $VF: renamed from: c boolean
   private boolean field_887;

   public class_65(class_97 var1, class_97 var2) {
      this(var1, var2, null);
   }

   public class_65(class_97 var1, class_97 var2, class_5 var3) {
      this.field_874 = var1;
      this.field_876 = var2;
      this.field_882 = true;
      this.field_881 = var3;
      if (var3 != null) {
         this.field_881.method_182();
      }

      if (this.field_877 == null) {
         this.field_877 = new class_5();
      }

      if (this.field_878 == null) {
         this.field_878 = new class_5();
      }

      if (this.field_879 == null) {
         this.field_879 = new class_5();
      }

      if (this.field_880 == null) {
         this.field_880 = new class_5();
      }

      if (var1 != null && var2 != null) {
         this.field_885 = new class_71(var1, var2);
         this.field_875 = var1;

         while (this.field_875.field_1278 != null) {
            this.field_875 = this.field_875.field_1278;
         }

         Object var4 = var2;

         while (((class_97)var4).field_1278 != null) {
            var4 = ((class_97)var4).field_1278;
         }

         if (var4 == this.field_875) {
            this.field_875 = null;
         }

         this.field_887 = var2 instanceof class_111;
         this.field_884 = var2.method_846().method_176(var1.method_846(), new class_5());
      }
   }

   // $VF: renamed from: a (ae) void
   public final void method_609(class_97 var1) {
      this.field_874 = var1;
      if (this.field_885 == null && var1 != null) {
         this.field_885 = new class_71(var1, this.field_876);
      }

      if (this.field_885 != null) {
         this.field_885.field_1031 = var1;
      }
   }

   // $VF: renamed from: b (ae) void
   public final void method_610(class_97 var1) {
      this.field_876 = var1;
      if (this.field_885 == null && var1 != null) {
         this.field_885 = new class_71(this.field_874, var1);
      }

      if (this.field_885 != null) {
         this.field_885.field_1034 = var1;
      }

      this.field_887 = var1 instanceof class_111;
   }

   // $VF: renamed from: a (v) void
   public final void method_611(class_5 var1) {
      this.field_879.method_169(var1);
   }

   // $VF: renamed from: b () void
   public final void method_612() {
      this.field_886 = true;
      this.field_879 = this.field_874.field_1284.method_39(this.field_884, this.field_879);
      this.field_876.method_842(this.field_879);
   }

   // $VF: renamed from: c () void
   public final void method_613() {
      this.field_886 = false;
   }

   // $VF: renamed from: a () void
   public final void method_0() {
      if (this.field_882) {
         if (this.field_886) {
            this.field_885.method_0();
            return;
         }

         if (this.field_874 != null) {
            this.field_877 = this.field_874.method_853();
            this.field_877.method_182();
            this.field_878 = this.field_874.field_1284.method_39(this.field_884, this.field_878);
            this.field_879.field_138 = this.field_879.field_138 - (this.field_879.field_138 - this.field_878.field_138 >> 8);
            this.field_879.field_139 = this.field_879.field_139 - (this.field_879.field_139 - this.field_878.field_139 >> 8);
            this.field_879.field_140 = this.field_879.field_140 - (this.field_879.field_140 - this.field_878.field_140 >> 8);
            this.field_878 = this.field_874.field_1284.method_39(this.field_883, this.field_878);
            this.field_878.field_138 = this.field_878.field_138 - this.field_879.field_138;
            this.field_878.field_139 = this.field_878.field_139 - this.field_879.field_139;
            this.field_878.field_140 = this.field_878.field_140 - this.field_879.field_140;
            if (this.field_887) {
               this.field_878.field_138 = -this.field_878.field_138;
               this.field_878.field_139 = -this.field_878.field_139;
               this.field_878.field_140 = -this.field_878.field_140;
            }

            this.field_878.method_182();
            this.field_880 = this.field_877.method_173(this.field_878, this.field_880);
            this.field_877 = this.field_878.method_173(this.field_880, this.field_877);
            this.field_880.method_182();
            this.field_876.method_868(this.field_880, this.field_877, this.field_878);
            this.field_876.method_842(this.field_879);
         }
      }
   }

   // $VF: renamed from: a () boolean
   public final boolean method_1() {
      return this.field_882;
   }

   // $VF: renamed from: a (boolean) void
   public final void method_614(boolean var1) {
      this.field_882 = var1;
      this.field_885.field_1039 = var1;
   }

   // $VF: renamed from: b (v) void
   public final void method_615(class_5 var1) {
      this.field_879.method_169(var1);
   }

   // $VF: renamed from: c (v) void
   public final void method_616(class_5 var1) {
      this.field_883.method_169(var1);
   }

   // $VF: renamed from: d (v) void
   public final void method_617(class_5 var1) {
      this.field_884.method_169(var1);
   }
}
