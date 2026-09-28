// $VF: renamed from: z
public class class_74 {
   // $VF: renamed from: b int
   public int field_1027;
   // $VF: renamed from: c int
   public int field_1028;
   // $VF: renamed from: d int
   public int field_1029;
   // $VF: renamed from: e int
   public int field_1030;
   // $VF: renamed from: a java.lang.String[]
   public String[] field_1031;
   // $VF: renamed from: a java.lang.Object[][]
   public Object[][] field_1032;
   // $VF: renamed from: a int[]
   public int[] field_1033;
   // $VF: renamed from: f int
   public int field_1034;
   // $VF: renamed from: g int
   public int field_1035;
   // $VF: renamed from: h int
   public int field_1036;
   // $VF: renamed from: a boolean
   public boolean field_1037;
   // $VF: renamed from: i int
   public int field_1038;
   // $VF: renamed from: j int
   public int field_1039;
   // $VF: renamed from: k int
   public int field_1040;
   // $VF: renamed from: l int
   public int field_1041;
   // $VF: renamed from: m int
   public int field_1042;
   // $VF: renamed from: n int
   public int field_1043;
   // $VF: renamed from: o int
   public int field_1044 = 8;
   // $VF: renamed from: p int
   public int field_1045;
   // $VF: renamed from: q int
   public int field_1046;
   // $VF: renamed from: b boolean
   public boolean field_1047;
   // $VF: renamed from: c boolean
   public boolean field_1048;
   // $VF: renamed from: r int
   public int field_1049;
   // $VF: renamed from: b java.lang.String
   public String field_1050;

   public class_74(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      this.method_697(var1, var2, var3, var4, var5, var6);
      this.field_1038 = 0;
      this.field_1047 = true;
      this.field_1048 = true;
   }

   // $VF: renamed from: a (int, int, int, int, java.lang.String[], java.lang.String) void
   public final void method_697(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      if (var1 == 0 && var2 == 0 && var3 == class_84.field_1120 && var4 == class_84.field_1121) {
         var2 = 1;
         var1 = 1;
         var3 -= 3;
         var4 = var4 - 6 - 10;
      }

      this.field_1027 = var1;
      this.field_1028 = var2;
      this.field_1029 = var3;
      this.field_1030 = var4;
      this.field_1037 = true;
      if (var5 == null) {
         var5 = new String[]{""};
         this.field_1037 = false;
      }

      this.field_1050 = var6;
      this.field_1031 = var5;
      this.field_1032 = new Object[var5.length][30];
      this.field_1033 = new int[var5.length];

      for (int var7 = 0; var7 < this.field_1033.length; var7++) {
         this.field_1033[var7] = 30;
      }

      this.field_1046 = 0;
      this.field_1039 = 0;
      this.field_1038 = 0;
      this.field_1040 = 0;
      this.field_1044 = this.method_698();
      this.field_1045 = this.method_699();
      this.field_1042 = var1 + 4;
      if (this.field_1037) {
         this.field_1043 = var2 + 11 + this.field_1045;
      } else {
         this.field_1043 = var2 + 11;
      }

      for (int var8 = 0; var8 < var5.length; var8++) {
         this.field_1038 = var8;
         this.method_703();
      }
   }

   // $VF: renamed from: a () int
   public int method_698() {
      return this.field_1044;
   }

   // $VF: renamed from: b () int
   public int method_699() {
      return 16;
   }

   // $VF: renamed from: a (int, java.lang.Object[]) void
   public final void method_700(int var1, Object[] var2) {
      if (var1 > this.field_1032.length - 1) {
         System.out.println("ERROR: Tab " + var1 + " not available!");
      } else {
         this.field_1032[var1] = new Object[30];
         if (var2 != null) {
            for (int var3 = 0; var3 < var2.length; var3++) {
               this.field_1032[var1][var3] = var2[var3];
            }
         }

         this.method_703();
      }
   }

   // $VF: renamed from: a () java.lang.Object
   public final Object method_701() {
      if (this.field_1039 < 0) {
         this.field_1039 = 0;
         return null;
      } else {
         return this.field_1032[this.field_1038] == null ? null : this.field_1032[this.field_1038][this.field_1039];
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_702(int var1) {
      if (var1 < this.field_1032.length) {
         this.field_1038 = var1;
         this.method_703();
      }
   }

   // $VF: renamed from: f () void
   public void method_703() {
      this.field_1034 = 0;
      this.field_1035 = 0;
      if (this.field_1032[this.field_1038] != null) {
         for (int var1 = 0; var1 < this.field_1032[this.field_1038].length; var1++) {
            if (this.field_1032[this.field_1038][var1] == null) {
               this.field_1041 = var1 - 1;
               this.field_1033[this.field_1038] = var1;
               break;
            }
         }
      }

      this.field_1041 = this.field_1033[this.field_1038] - 1;

      for (int var2 = 0; var2 < this.field_1033[this.field_1038]; var2++) {
         if (this.field_1043 + (var2 + 1) * this.field_1044 > this.field_1028 + this.field_1030 - 12) {
            this.field_1041 = var2 - 1;
            this.field_1034 = (int)((this.field_1030 - this.field_1043 + this.field_1028) * ((float)var2 / this.field_1033[this.field_1038]));
            break;
         }
      }

      this.field_1036 = (int)((this.field_1030 - this.field_1043 + this.field_1028) * ((float)this.field_1040 / this.field_1033[this.field_1038]));
      if (this.field_1034 > 0) {
         this.field_1035 = 5;
      }
   }

   // $VF: renamed from: d () void
   public void method_704() {
      if (this.field_1046 == 0 && this.field_1039 > 0) {
         this.field_1039--;
         if (this.field_1039 < this.field_1040) {
            this.field_1040--;
         }
      }

      this.method_703();
   }

   // $VF: renamed from: e () void
   public void method_705() {
      if (this.field_1046 == 0) {
         if (this.field_1039 == this.field_1032[this.field_1038].length - 1) {
            return;
         }

         if (this.field_1032[this.field_1038][this.field_1039 + 1] != null) {
            this.field_1039++;
            if (this.field_1039 > this.field_1040 + this.field_1041) {
               this.field_1040++;
            }
         }
      } else if (this.field_1032[this.field_1038][0] != null) {
         this.field_1046 = 0;
      }

      this.method_703();
   }

   // $VF: renamed from: h () void
   public void method_706() {
      if (this.field_1038 > 0) {
         this.field_1038--;
         this.field_1039 = 0;
         this.field_1040 = 0;
      }

      this.method_703();
   }

   // $VF: renamed from: i () void
   public void method_707() {
      if (this.field_1038 < this.field_1031.length - 1) {
         this.field_1038++;
         this.field_1039 = 0;
         this.field_1040 = 0;
      }

      this.method_703();
   }

   // $VF: renamed from: j () void
   public final void method_708() {
      if (this.field_1037) {
         // Deep3D-PC: tab headers take clicks
         org.deep3d.GameUi.tab(this.field_1027 + 2, this.field_1028 + 11, this.field_1029 / 2 - 2, 14, this.field_1038 == 0);
         org.deep3d.GameUi.tab(this.field_1027 + this.field_1029 / 2, this.field_1028 + 11, this.field_1029 / 2 - 2, 14, this.field_1038 == 1);
         class_84.field_1117.setColor(class_67.field_844);
         if (this.field_1038 == 0) {
            class_84.field_1117.drawLine(this.field_1027 + 2, this.field_1028 + 11, this.field_1027 + this.field_1029 / 2 - 2, this.field_1028 + 11);
            class_84.field_1117.drawLine(this.field_1027 + 2, this.field_1028 + 11, this.field_1027 + 2, this.field_1028 + 11 + 12 + 2);
            class_84.field_1117
               .drawLine(
                  this.field_1027 + this.field_1029 / 2 - 2, this.field_1028 + 11, this.field_1027 + this.field_1029 / 2 - 2, this.field_1028 + 11 + 12 + 2
               );
            class_84.field_1117.drawRect(this.field_1027 + this.field_1029 / 2, this.field_1028 + 11, this.field_1029 / 2 - 1, 12);
            class_84.field_1117
               .drawLine(
                  this.field_1027 + this.field_1029 / 2 - 2,
                  this.field_1028 + 11 + 12 + 2,
                  this.field_1027 + this.field_1029 - 2,
                  this.field_1028 + 11 + 12 + 2
               );
            class_84.field_1117.setColor(class_67.field_847);
            class_84.field_1117.fillRect(this.field_1027 + this.field_1029 / 2 + 1, this.field_1028 + 11 + 1, this.field_1029 / 2 - 2, 11);
            class_58.method_518(this.field_1031[0], this.field_1027 + 2 + 2, this.field_1028 + 11 + 1, 0);
            class_58.method_518(this.field_1031[1], this.field_1027 + this.field_1029 / 2 + 2, this.field_1028 + 11 + 1, 1);
            if (class_67.method_581()) {
               class_84.field_1117.setColor(class_67.field_844);
               class_84.field_1117
                  .fillTriangle(
                     this.field_1027 + this.field_1029 / 2 - 8,
                     this.field_1028 + 11 + 11,
                     this.field_1027 + this.field_1029 / 2 - 8,
                     this.field_1028 + 11 + 4,
                     this.field_1027 + this.field_1029 / 2 - 4,
                     this.field_1028 + 11 + 7
                  );
            }
         } else {
            class_84.field_1117
               .drawLine(this.field_1027 + this.field_1029 / 2, this.field_1028 + 11, this.field_1027 + this.field_1029 - 2, this.field_1028 + 11);
            class_84.field_1117
               .drawLine(this.field_1027 + this.field_1029 / 2, this.field_1028 + 11, this.field_1027 + this.field_1029 / 2, this.field_1028 + 11 + 12 + 2);
            class_84.field_1117
               .drawLine(this.field_1027 + this.field_1029 - 2, this.field_1028 + 11, this.field_1027 + this.field_1029 - 2, this.field_1028 + 11 + 12 + 2);
            class_84.field_1117.drawRect(this.field_1027 + 2, this.field_1028 + 11, this.field_1029 / 2 - 4, 12);
            class_84.field_1117
               .drawLine(this.field_1027 + 2, this.field_1028 + 11 + 12 + 2, this.field_1027 + this.field_1029 / 2, this.field_1028 + 11 + 12 + 2);
            class_84.field_1117.setColor(class_67.field_847);
            class_84.field_1117.fillRect(this.field_1027 + 2 + 1, this.field_1028 + 11 + 1, this.field_1029 / 2 - 5, 11);
            class_58.method_518(this.field_1031[0], this.field_1027 + 2 + 2, this.field_1028 + 11 + 1, 1);
            class_58.method_518(this.field_1031[1], this.field_1027 + this.field_1029 / 2 + 2, this.field_1028 + 11 + 1, 0);
            if (class_67.method_581()) {
               class_84.field_1117.setColor(class_67.field_844);
               class_84.field_1117
                  .fillTriangle(
                     this.field_1027 + this.field_1029 - 8,
                     this.field_1028 + 11 + 3,
                     this.field_1027 + this.field_1029 - 8,
                     this.field_1028 + 11 + 11,
                     this.field_1027 + this.field_1029 - 12,
                     this.field_1028 + 11 + 7
                  );
            }
         }

         class_84.field_1117.setColor(class_67.field_844);
         class_84.field_1117.drawLine(this.field_1027 + 2, this.field_1028 + 11 + 12 + 2, this.field_1027 + 2, this.field_1028 + this.field_1030 - 2);
         class_84.field_1117
            .drawLine(
               this.field_1027 + this.field_1029 - 2,
               this.field_1028 + 11 + 12 + 2,
               this.field_1027 + this.field_1029 - 2,
               this.field_1028 + this.field_1030 - 2
            );
         class_84.field_1117
            .drawLine(this.field_1027 + 2, this.field_1028 + this.field_1030 - 2, this.field_1027 + this.field_1029 - 2, this.field_1028 + this.field_1030 - 2);
      }
   }

   // $VF: renamed from: k () void
   public final void method_709() {
      if (this.field_1034 > 0) {
         class_84.field_1117.setColor(class_67.field_844);
         class_84.field_1117
            .drawLine(
               this.field_1027 + this.field_1029 - 5, this.field_1043 + 2, this.field_1027 + this.field_1029 - 5, this.field_1028 + this.field_1030 - 5 - 14
            );
         class_84.field_1117.drawLine(this.field_1027 + this.field_1029 - 6, this.field_1043 + 3, this.field_1027 + this.field_1029 - 4, this.field_1043 + 3);
         class_84.field_1117
            .drawLine(
               this.field_1027 + this.field_1029 - 6,
               this.field_1028 + this.field_1030 - 6 - 14,
               this.field_1027 + this.field_1029 - 4,
               this.field_1028 + this.field_1030 - 6 - 14
            );
         if (class_67.method_581()) {
            class_84.field_1117.setColor(192, 192, 192);
         }

         class_84.field_1117.fillRect(this.field_1027 + this.field_1029 - 6, this.field_1043 + 4 + this.field_1036, 3, this.field_1034 - 8 - 14);
         class_84.field_1117.setColor(class_67.field_844);
      }
   }

   // $VF: renamed from: l () void
   public void method_710() {
      if (this.field_1047) {
         class_84.field_1117.setColor(class_67.field_845);
         class_84.field_1117.fillRect(this.field_1027, this.field_1028, this.field_1029, this.field_1030);
      }
   }

   // $VF: renamed from: m () void
   public final void method_711() {
      this.field_1049 = 1 - this.field_1049;
   }
}
