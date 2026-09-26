// $VF: renamed from: bd
public final class class_68 {
   // $VF: renamed from: a int
   public int field_863;
   // $VF: renamed from: b int
   public int field_864;
   // $VF: renamed from: w int
   private int field_865;
   // $VF: renamed from: c int
   public int field_866;
   // $VF: renamed from: d int
   public int field_867;
   // $VF: renamed from: x int
   private int field_868;
   // $VF: renamed from: e int
   public int field_869;
   // $VF: renamed from: a float
   public float field_870;
   // $VF: renamed from: f int
   public int field_871;
   // $VF: renamed from: g int
   public int field_872;
   // $VF: renamed from: h int
   public int field_873;
   // $VF: renamed from: i int
   public int field_874;
   // $VF: renamed from: j int
   public int field_875;
   // $VF: renamed from: k int
   public int field_876;
   // $VF: renamed from: l int
   public int field_877;
   // $VF: renamed from: m int
   public int field_878;
   // $VF: renamed from: n int
   public int field_879;
   // $VF: renamed from: o int
   public int field_880;
   // $VF: renamed from: p int
   public int field_881;
   // $VF: renamed from: q int
   public int field_882;
   // $VF: renamed from: a boolean
   public boolean field_883;
   // $VF: renamed from: b boolean
   public boolean field_884;
   // $VF: renamed from: a dn[]
   public class_19[] field_885;
   // $VF: renamed from: a ac[]
   public class_120[] field_886;
   // $VF: renamed from: r int
   public int field_887;
   // $VF: renamed from: s int
   public int field_888;
   // $VF: renamed from: t int
   public int field_889;
   // $VF: renamed from: u int
   public int field_890;
   // $VF: renamed from: v int
   public int field_891;
   // $VF: renamed from: b dn[]
   private class_19[] field_892;

   public class_68(int var1, int var2, int var3, int var4, int var5, float var6) {
      this.field_863 = var1;
      this.field_864 = var2;
      this.field_866 = var3;
      this.field_867 = 0;
      this.field_868 = var4;
      this.field_865 = var4;
      this.field_869 = var5;
      this.field_870 = var6;
      this.field_885 = new class_19[var5];
      this.field_886 = null;
      this.field_884 = false;
      this.method_618();
   }

   // $VF: renamed from: a () int
   public final int method_603() {
      return this.field_863 == 10 && class_14.method_69() ? 50000 : this.field_868;
   }

   // $VF: renamed from: b () int
   public final int method_604() {
      return this.field_864 + this.field_871 + this.field_872;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_605() {
      return this.field_877 > 0;
   }

   // $VF: renamed from: c () int
   public final int method_606() {
      return (int)(275.0F + (int)(275.0F * this.field_881) / 100.0F);
   }

   // $VF: renamed from: d () int
   public final int method_607() {
      return this.field_866 + this.field_874;
   }

   // $VF: renamed from: a (ac[]) void
   public final void method_608(class_120[] var1) {
      this.field_886 = var1;
      this.field_867 = 0;

      for (int var2 = 0; var2 < this.field_886.length; var2++) {
         this.field_867 = this.field_867 + this.field_886[var2].field_1490;
      }

      this.method_618();
   }

   // $VF: renamed from: a (int) boolean
   public final boolean method_609(int var1) {
      if (this.field_885 == null) {
         return false;
      } else {
         for (int var2 = 0; var2 < this.field_885.length; var2++) {
            if (this.field_885[var2] != null && this.field_885[var2].field_166 == var1) {
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (int, int) boolean
   public final boolean method_610(int var1, int var2) {
      boolean var3 = false;

      for (int var4 = 0; var4 < this.field_886.length; var4++) {
         if (this.field_886[var4].field_1480 == var1) {
            this.field_886[var4].method_926(-var2);
            if (this.field_886[var4].field_1490 <= 0) {
               var3 = true;
            }
            break;
         }
      }

      if (var3) {
         this.method_611(class_120.method_934(this.field_886, true));
      } else {
         this.method_611(this.field_886);
      }

      return var3;
   }

   // $VF: renamed from: b (ac[]) void
   public final void method_611(class_120[] var1) {
      this.field_886 = var1;
      this.field_867 = 0;
      if (var1 != null) {
         for (int var2 = 0; var2 < this.field_886.length; var2++) {
            this.field_867 = this.field_867 + this.field_886[var2].field_1490;
         }
      }

      this.method_618();
   }

   // $VF: renamed from: b (int) boolean
   public final boolean method_612(int var1) {
      return this.field_867 + var1 <= this.field_866 + this.field_874;
   }

   // $VF: renamed from: a (ac) void
   public final void method_613(class_120 var1) {
      this.method_614(new class_120[]{var1});
   }

   // $VF: renamed from: c (ac[]) void
   public final void method_614(class_120[] var1) {
      this.method_611(class_120.method_936(this.field_886, var1));
   }

   // $VF: renamed from: a (dn[]) void
   public final void method_615(class_19[] var1) {
      this.field_885 = var1;
      this.method_618();
   }

   // $VF: renamed from: b (dn[]) void
   public final void method_616(class_19[] var1) {
      for (int var2 = 0; var2 < var1.length; var2++) {
         this.method_617(var1[var2]);
      }
   }

   // $VF: renamed from: a (dn) void
   public final void method_617(class_19 var1) {
      for (int var2 = 0; var2 < this.field_885.length; var2++) {
         if (this.field_885[var2] == null) {
            this.field_885[var2] = var1;
            break;
         }
      }

      this.method_618();
   }

   // $VF: renamed from: a () void
   public final void method_618() {
      this.field_883 = false;
      this.field_871 = 0;
      this.field_873 = 0;
      this.field_874 = 0;
      this.field_876 = 0;
      this.field_878 = 0;
      this.field_877 = 0;
      this.field_879 = 0;
      this.field_880 = 0;
      this.field_881 = 0;
      this.field_872 = 0;
      this.field_882 = 0;
      this.field_889 = 22000;
      this.field_890 = 23000;
      this.field_887 = class_38.method_359(this.field_889);
      this.field_888 = class_38.method_359(this.field_890);
      this.method_619();
      this.field_865 = this.field_868;

      for (int var1 = 0; var1 < this.field_885.length; var1++) {
         if (this.field_885[var1] != null) {
            switch (this.field_885[var1].field_165) {
               case 0:
               case 1:
                  this.field_882 = this.field_882 + this.field_885[var1].field_171;
               case 2:
               default:
                  break;
               case 3:
                  this.field_871 = this.field_885[var1].field_171;
                  this.field_873 = this.field_885[var1].field_172;
                  this.field_889 = this.field_885[var1].field_173;
                  this.field_887 = class_38.method_359(this.field_889);
                  break;
               case 4:
                  this.field_872 = this.field_885[var1].field_171;
                  this.field_890 = this.field_885[var1].field_172;
                  this.field_888 = class_38.method_359(this.field_890);
                  break;
               case 5:
                  this.field_874 = this.field_874 + this.field_885[var1].field_171;
                  break;
               case 6:
                  this.field_881 = this.field_885[var1].field_171;
                  break;
               case 7:
                  this.field_880 = this.field_885[var1].field_171;
                  break;
               case 8:
                  this.field_876 = this.field_885[var1].field_171;
                  break;
               case 9:
                  this.field_877 = this.field_885[var1].field_171;
                  this.field_879 = this.field_885[var1].field_172;
                  this.field_878 = this.field_885[var1].field_173;
                  break;
               case 10:
                  this.field_883 = true;
            }

            this.field_865 = this.field_865 + this.field_885[var1].method_116();
         }
      }

      this.field_875 = this.field_874;
      this.field_874 = (int)((float)this.field_866 * this.field_874 / 100.0F);
      this.field_865 = this.field_865 + this.method_621();
   }

   // $VF: renamed from: b () void
   public final void method_619() {
      this.field_892 = new class_19[this.method_624()];
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_885.length; var2++) {
         if (this.field_885[var2] != null && this.field_885[var2].method_118()) {
            this.field_892[var1++] = this.field_885[var2];
         }
      }
   }

   // $VF: renamed from: e () int
   public final int method_620() {
      int var1 = 0;
      if (this.field_886 != null) {
         for (int var2 = 0; var2 < this.field_886.length; var2++) {
            if (this.field_886[var2] != null) {
               var1 += (int)((float)this.field_886[var2].field_1490 * this.field_886[var2].field_1486);
            }
         }
      }

      this.field_886 = null;
      this.field_867 = 0;
      return var1;
   }

   // $VF: renamed from: f () int
   public final int method_621() {
      int var1 = 0;
      if (this.field_886 != null) {
         for (int var2 = 0; var2 < this.field_886.length; var2++) {
            if (this.field_886[var2] != null) {
               var1 += this.field_886[var2].method_924();
            }
         }
      }

      return var1;
   }

   // $VF: renamed from: b (dn) void
   public final void method_622(class_19 var1) {
      for (int var2 = 0; var2 < this.field_885.length; var2++) {
         if (this.field_885[var2] != null && this.field_885[var2].method_122(var1)) {
            this.field_885[var2] = null;
            break;
         }
      }

      this.method_618();
   }

   // $VF: renamed from: g () int
   public final int method_623() {
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_885.length; var2++) {
         if (this.field_885[var2] != null) {
            var1++;
         }
      }

      return var1;
   }

   // $VF: renamed from: h () int
   public final int method_624() {
      int var1 = 0;

      for (int var2 = 0; var2 < this.field_885.length; var2++) {
         if (this.field_885[var2] != null && this.field_885[var2].method_118()) {
            var1++;
         }
      }

      return var1;
   }

   // $VF: renamed from: c (int) boolean
   public final boolean method_625(int var1) {
      if (var1 != 5 && var1 != 0) {
         for (int var2 = 0; var2 < this.field_885.length; var2++) {
            if (this.field_885[var2] != null && this.field_885[var2].field_165 == var1) {
               return false;
            }
         }

         return true;
      } else {
         return true;
      }
   }

   // $VF: renamed from: b () boolean
   public final boolean method_626() {
      for (int var1 = 0; var1 < this.field_885.length; var1++) {
         if (this.field_885[var1] == null) {
            return true;
         }
      }

      return false;
   }

   // $VF: renamed from: a () bd
   public final class_68 method_627() {
      return this.method_630();
   }

   // $VF: renamed from: c () void
   public final void method_628() {
      this.field_868 = (int)(class_90.method_783()[this.field_863].method_603() / 1.25F);
   }

   // $VF: renamed from: d () void
   public final void method_629() {
      if (class_21.method_180() != null) {
         this.field_868 = class_90.method_783()[this.field_863].method_603()
            - (int)(class_21.method_180().field_1139 / 100.0F * class_90.method_783()[this.field_863].method_603());
      }
   }

   // $VF: renamed from: b () bd
   public final class_68 method_630() {
      return new class_68(this.field_863, this.field_864, this.field_866, this.field_868, this.field_869, this.field_870);
   }
}
