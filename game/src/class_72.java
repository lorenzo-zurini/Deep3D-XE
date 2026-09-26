// $VF: renamed from: x
public class class_72 {
   // $VF: renamed from: b int
   public int field_1046;
   // $VF: renamed from: c int
   public int field_1047;
   // $VF: renamed from: d int
   public int field_1048;
   // $VF: renamed from: e int
   public int field_1049;
   // $VF: renamed from: a java.lang.String[]
   public String[] field_1050;
   // $VF: renamed from: a java.lang.Object[][]
   public Object[][] field_1051;
   // $VF: renamed from: a int[]
   public int[] field_1052;
   // $VF: renamed from: f int
   public int field_1053;
   // $VF: renamed from: g int
   public int field_1054;
   // $VF: renamed from: h int
   public int field_1055;
   // $VF: renamed from: a boolean
   public boolean field_1056;
   // $VF: renamed from: i int
   public int field_1057;
   // $VF: renamed from: j int
   public int field_1058;
   // $VF: renamed from: k int
   public int field_1059;
   // $VF: renamed from: l int
   public int field_1060;
   // $VF: renamed from: m int
   public int field_1061;
   // $VF: renamed from: n int
   public int field_1062;
   // $VF: renamed from: o int
   public int field_1063 = 8;
   // $VF: renamed from: p int
   public int field_1064;
   // $VF: renamed from: q int
   public int field_1065;
   // $VF: renamed from: b boolean
   public boolean field_1066;
   // $VF: renamed from: c boolean
   public boolean field_1067;
   // $VF: renamed from: r int
   public int field_1068;
   // $VF: renamed from: b java.lang.String
   public String field_1069;

   public class_72(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      this.method_690(var1, var2, var3, var4, var5, var6);
      this.field_1057 = 0;
      this.field_1066 = true;
      this.field_1067 = true;
   }

   // $VF: renamed from: a (int, int, int, int, java.lang.String[], java.lang.String) void
   public final void method_690(int var1, int var2, int var3, int var4, String[] var5, String var6) {
      if (var1 == 0 && var2 == 0 && var3 == class_41.field_537 && var4 == class_41.field_538) {
         var2 = 1;
         var1 = 1;
         var3 -= 3;
         var4 = var4 - 6 - 10;
      }

      this.field_1046 = var1;
      this.field_1047 = var2;
      this.field_1048 = var3;
      this.field_1049 = var4;
      this.field_1056 = true;
      if (var5 == null) {
         var5 = new String[]{""};
         this.field_1056 = false;
      }

      this.field_1069 = var6;
      this.field_1050 = var5;
      this.field_1051 = new Object[var5.length][30];
      this.field_1052 = new int[var5.length];

      for (int var7 = 0; var7 < this.field_1052.length; var7++) {
         this.field_1052[var7] = 30;
      }

      this.field_1065 = 0;
      this.field_1058 = 0;
      this.field_1057 = 0;
      this.field_1059 = 0;
      this.field_1063 = this.method_691();
      this.field_1064 = this.method_692();
      this.field_1061 = var1 + 4;
      if (this.field_1056) {
         this.field_1062 = var2 + 11 + this.field_1064;
      } else {
         this.field_1062 = var2 + 11;
      }

      for (int var8 = 0; var8 < var5.length; var8++) {
         this.field_1057 = var8;
         this.method_696();
      }
   }

   // $VF: renamed from: a () int
   public int method_691() {
      return this.field_1063;
   }

   // $VF: renamed from: b () int
   public int method_692() {
      return 16;
   }

   // $VF: renamed from: a (int, java.lang.Object[]) void
   public final void method_693(int var1, Object[] var2) {
      if (var1 > this.field_1051.length - 1) {
         System.out.println("ERROR: Tab " + var1 + " not available!");
      } else {
         this.field_1051[var1] = new Object[30];
         if (var2 != null) {
            for (int var3 = 0; var3 < var2.length; var3++) {
               this.field_1051[var1][var3] = var2[var3];
            }
         }

         this.method_696();
      }
   }

   // $VF: renamed from: a () java.lang.Object
   public final Object method_694() {
      if (this.field_1058 < 0) {
         this.field_1058 = 0;
         return null;
      } else {
         return this.field_1051[this.field_1057] == null ? null : this.field_1051[this.field_1057][this.field_1058];
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_695(int var1) {
      if (var1 < this.field_1051.length) {
         this.field_1057 = var1;
         this.method_696();
      }
   }

   // $VF: renamed from: f () void
   public void method_696() {
      this.field_1053 = 0;
      this.field_1054 = 0;
      if (this.field_1051[this.field_1057] != null) {
         for (int var1 = 0; var1 < this.field_1051[this.field_1057].length; var1++) {
            if (this.field_1051[this.field_1057][var1] == null) {
               this.field_1060 = var1 - 1;
               this.field_1052[this.field_1057] = var1;
               break;
            }
         }
      }

      this.field_1060 = this.field_1052[this.field_1057] - 1;

      for (int var2 = 0; var2 < this.field_1052[this.field_1057]; var2++) {
         if (this.field_1062 + (var2 + 1) * this.field_1063 > this.field_1047 + this.field_1049 - 12) {
            this.field_1060 = var2 - 1;
            this.field_1053 = (int)((this.field_1049 - this.field_1062 + this.field_1047) * ((float)var2 / this.field_1052[this.field_1057]));
            break;
         }
      }

      this.field_1055 = (int)((this.field_1049 - this.field_1062 + this.field_1047) * ((float)this.field_1059 / this.field_1052[this.field_1057]));
      if (this.field_1053 > 0) {
         this.field_1054 = 5;
      }
   }

   // $VF: renamed from: d () void
   public void method_697() {
      if (this.field_1065 == 0 && this.field_1058 > 0) {
         this.field_1058--;
         if (this.field_1058 < this.field_1059) {
            this.field_1059--;
         }
      }

      this.method_696();
   }

   // $VF: renamed from: e () void
   public void method_698() {
      if (this.field_1065 == 0) {
         if (this.field_1058 == this.field_1051[this.field_1057].length - 1) {
            return;
         }

         if (this.field_1051[this.field_1057][this.field_1058 + 1] != null) {
            this.field_1058++;
            if (this.field_1058 > this.field_1059 + this.field_1060) {
               this.field_1059++;
            }
         }
      } else if (this.field_1051[this.field_1057][0] != null) {
         this.field_1065 = 0;
      }

      this.method_696();
   }

   // $VF: renamed from: h () void
   public void method_699() {
      if (this.field_1057 > 0) {
         this.field_1057--;
         this.field_1058 = 0;
         this.field_1059 = 0;
      }

      this.method_696();
   }

   // $VF: renamed from: i () void
   public void method_700() {
      if (this.field_1057 < this.field_1050.length - 1) {
         this.field_1057++;
         this.field_1058 = 0;
         this.field_1059 = 0;
      }

      this.method_696();
   }

   // $VF: renamed from: j () void
   public final void method_701() {
      if (this.field_1056) {
         class_41.field_534.setColor(class_69.field_1003);
         if (this.field_1057 == 0) {
            class_41.field_534.drawLine(this.field_1046 + 2, this.field_1047 + 11, this.field_1046 + this.field_1048 / 2 - 2, this.field_1047 + 11);
            class_41.field_534.drawLine(this.field_1046 + 2, this.field_1047 + 11, this.field_1046 + 2, this.field_1047 + 11 + 12 + 2);
            class_41.field_534
               .drawLine(
                  this.field_1046 + this.field_1048 / 2 - 2, this.field_1047 + 11, this.field_1046 + this.field_1048 / 2 - 2, this.field_1047 + 11 + 12 + 2
               );
            class_41.field_534.drawRect(this.field_1046 + this.field_1048 / 2, this.field_1047 + 11, this.field_1048 / 2 - 1, 12);
            class_41.field_534
               .drawLine(
                  this.field_1046 + this.field_1048 / 2 - 2,
                  this.field_1047 + 11 + 12 + 2,
                  this.field_1046 + this.field_1048 - 2,
                  this.field_1047 + 11 + 12 + 2
               );
            class_41.field_534.setColor(class_69.field_1006);
            class_41.field_534.fillRect(this.field_1046 + this.field_1048 / 2 + 1, this.field_1047 + 11 + 1, this.field_1048 / 2 - 2, 11);
            class_50.method_485(this.field_1050[0], this.field_1046 + 2 + 2, this.field_1047 + 11 + 1, 0);
            class_50.method_485(this.field_1050[1], this.field_1046 + this.field_1048 / 2 + 2, this.field_1047 + 11 + 1, 1);
            if (class_69.method_657()) {
               class_41.field_534.setColor(class_69.field_1003);
               class_41.field_534
                  .fillTriangle(
                     this.field_1046 + this.field_1048 / 2 - 8,
                     this.field_1047 + 11 + 11,
                     this.field_1046 + this.field_1048 / 2 - 8,
                     this.field_1047 + 11 + 4,
                     this.field_1046 + this.field_1048 / 2 - 4,
                     this.field_1047 + 11 + 7
                  );
            }
         } else {
            class_41.field_534
               .drawLine(this.field_1046 + this.field_1048 / 2, this.field_1047 + 11, this.field_1046 + this.field_1048 - 2, this.field_1047 + 11);
            class_41.field_534
               .drawLine(this.field_1046 + this.field_1048 / 2, this.field_1047 + 11, this.field_1046 + this.field_1048 / 2, this.field_1047 + 11 + 12 + 2);
            class_41.field_534
               .drawLine(this.field_1046 + this.field_1048 - 2, this.field_1047 + 11, this.field_1046 + this.field_1048 - 2, this.field_1047 + 11 + 12 + 2);
            class_41.field_534.drawRect(this.field_1046 + 2, this.field_1047 + 11, this.field_1048 / 2 - 4, 12);
            class_41.field_534
               .drawLine(this.field_1046 + 2, this.field_1047 + 11 + 12 + 2, this.field_1046 + this.field_1048 / 2, this.field_1047 + 11 + 12 + 2);
            class_41.field_534.setColor(class_69.field_1006);
            class_41.field_534.fillRect(this.field_1046 + 2 + 1, this.field_1047 + 11 + 1, this.field_1048 / 2 - 5, 11);
            class_50.method_485(this.field_1050[0], this.field_1046 + 2 + 2, this.field_1047 + 11 + 1, 1);
            class_50.method_485(this.field_1050[1], this.field_1046 + this.field_1048 / 2 + 2, this.field_1047 + 11 + 1, 0);
            if (class_69.method_657()) {
               class_41.field_534.setColor(class_69.field_1003);
               class_41.field_534
                  .fillTriangle(
                     this.field_1046 + this.field_1048 - 8,
                     this.field_1047 + 11 + 3,
                     this.field_1046 + this.field_1048 - 8,
                     this.field_1047 + 11 + 11,
                     this.field_1046 + this.field_1048 - 12,
                     this.field_1047 + 11 + 7
                  );
            }
         }

         class_41.field_534.setColor(class_69.field_1003);
         class_41.field_534.drawLine(this.field_1046 + 2, this.field_1047 + 11 + 12 + 2, this.field_1046 + 2, this.field_1047 + this.field_1049 - 2);
         class_41.field_534
            .drawLine(
               this.field_1046 + this.field_1048 - 2,
               this.field_1047 + 11 + 12 + 2,
               this.field_1046 + this.field_1048 - 2,
               this.field_1047 + this.field_1049 - 2
            );
         class_41.field_534
            .drawLine(this.field_1046 + 2, this.field_1047 + this.field_1049 - 2, this.field_1046 + this.field_1048 - 2, this.field_1047 + this.field_1049 - 2);
      }
   }

   // $VF: renamed from: k () void
   public final void method_702() {
      if (this.field_1053 > 0) {
         class_41.field_534.setColor(class_69.field_1003);
         class_41.field_534
            .drawLine(
               this.field_1046 + this.field_1048 - 5, this.field_1062 + 2, this.field_1046 + this.field_1048 - 5, this.field_1047 + this.field_1049 - 5 - 14
            );
         class_41.field_534.drawLine(this.field_1046 + this.field_1048 - 6, this.field_1062 + 3, this.field_1046 + this.field_1048 - 4, this.field_1062 + 3);
         class_41.field_534
            .drawLine(
               this.field_1046 + this.field_1048 - 6,
               this.field_1047 + this.field_1049 - 6 - 14,
               this.field_1046 + this.field_1048 - 4,
               this.field_1047 + this.field_1049 - 6 - 14
            );
         if (class_69.method_657()) {
            class_41.field_534.setColor(192, 192, 192);
         }

         class_41.field_534.fillRect(this.field_1046 + this.field_1048 - 6, this.field_1062 + 4 + this.field_1055, 3, this.field_1053 - 8 - 14);
         class_41.field_534.setColor(class_69.field_1003);
      }
   }

   // $VF: renamed from: l () void
   public void method_703() {
      if (this.field_1066) {
         class_41.field_534.setColor(class_69.field_1004);
         class_41.field_534.fillRect(this.field_1046, this.field_1047, this.field_1048, this.field_1049);
      }
   }

   // $VF: renamed from: m () void
   public final void method_704() {
      this.field_1068 = 1 - this.field_1068;
   }
}
