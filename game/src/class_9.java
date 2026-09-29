// $VF: renamed from: n
public final class class_9 {
   private static final boolean DEEP3D_LOG = System.getenv("DEEP3D_LOG_HITS") != null; // Deep3D-PC: tests
   // $VF: renamed from: a short[][][]
   private static final short[][][] field_75 = new short[][][]{
      {{0, 0, 0}},
      {{270, 0, 100}, {-270, 0, 100}},
      {{320, 0, 100}, {0, 0, 100}, {-320, 0, 100}},
      {{370, 0, 100}, {170, 100, 150}, {-170, 100, 150}, {-370, 0, 100}},
      {{350, 100, 200}, {270, -100, 150}, {0, 0, 100}, {-270, -100, 150}, {-350, 100, 200}},
      {{500, 100, 150}, {500, -100, 150}, {200, 0, 100}, {-200, 0, 100}, {-500, -100, 150}, {-500, 100, 150}},
      {{500, -100, 150}, {400, 100, 150}, {200, -50, 100}, {0, 0, 150}, {-200, -50, 100}, {-400, 100, 150}, {-500, -100, 150}},
      {{550, -100, 100}, {550, 100, 100}, {300, 0, 100}, {100, 0, 150}, {-100, 0, 150}, {-300, 0, 100}, {-550, 100, 100}, {-550, -100, 100}},
      {{550, -100, 100}, {550, 100, 100}, {300, 0, 100}, {100, 100, 150}, {0, -100, 100}, {-100, 100, 150}, {-300, 0, 100}, {-550, 100, 100}, {-550, -100, 100}},
      {
            {600, -120, 100},
            {600, 120, 100},
            {400, 0, 100},
            {200, 100, 150},
            {200, -100, 100},
            {-200, -100, 100},
            {-200, 100, 150},
            {-400, 0, 100},
            {-600, 120, 100},
            {-600, -120, 100}
      }
   };
   // $VF: renamed from: a cz
   public class_26 field_76;
   // $VF: renamed from: a cm[]
   public class_37[] field_77;
   // $VF: renamed from: a x[]
   public class_3[] field_78;
   // $VF: renamed from: b x[]
   public class_3[] field_79;
   // $VF: renamed from: a x
   public class_3 field_80;
   // $VF: renamed from: b x
   public class_3 field_81;
   // $VF: renamed from: a cm
   public class_37 field_82;
   // $VF: renamed from: a int[]
   public int[] field_83;
   // $VF: renamed from: e int
   private int field_84;
   // $VF: renamed from: a float
   public float field_85;
   // $VF: renamed from: a int
   public int field_86;
   // $VF: renamed from: c x
   public class_3 field_87;
   // $VF: renamed from: a boolean
   public boolean field_88;
   // $VF: renamed from: d x
   private class_3 field_89;
   // $VF: renamed from: b int
   public int field_90;
   // $VF: renamed from: c int
   public int field_91;
   // $VF: renamed from: b boolean
   public boolean field_92;
   // $VF: renamed from: c boolean
   public boolean field_93;
   // $VF: renamed from: a ak
   public class_116 field_94;
   // $VF: renamed from: f boolean
   private boolean field_95;
   // $VF: renamed from: a aw
   public class_91 field_96;
   // $VF: renamed from: d boolean
   public boolean field_97;
   // $VF: renamed from: a cy
   private class_114 field_98;
   // $VF: renamed from: f int
   private int field_99;
   // $VF: renamed from: d int
   public int field_100;
   // $VF: renamed from: e boolean
   public boolean field_101;

   public class_9(int var1, int var2, int var3, int var4, int var5, float var6, class_3 var7, class_3 var8) {
      this.field_84 = var1;
      this.field_85 = var6;
      this.field_87 = var7;
      this.field_86 = var4;
      this.field_91 = var5;
      this.field_90 = 0;
      this.field_83 = new int[var2];
      this.field_78 = new class_3[var2];
      this.field_79 = new class_3[var2];
      this.field_80 = new class_3();
      this.field_81 = new class_3();

      for (int var9 = 0; var9 < var2; var9++) {
         this.field_78[var9] = new class_3(50000, 0, 0);
         this.field_79[var9] = new class_3();
         this.field_83[var9] = -1;
      }

      this.field_93 = true;
      this.field_88 = false;
      this.field_89 = new class_3();
      this.field_92 = false;
      this.field_94 = null;
      this.field_95 = false;
      this.field_77 = null;
      this.field_97 = false;
      this.field_98 = null;
      this.field_101 = false;
   }

   // $VF: renamed from: a (int, cy) void
   public final void method_41(int var1, class_114 var2) {
      this.field_98 = var2;
      this.field_97 = true;
      this.field_99 = var1 * 200;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_42(int var1, int var2) {
      short[] var3 = field_75[var2 - 1][var1];
      this.field_89.method_9(this.field_87);
      this.field_87 = new class_3(var3[0] + this.field_89.field_37, var3[1] + this.field_89.field_38, var3[2] + this.field_89.field_39);
   }

   // $VF: renamed from: a () void
   public final void method_43() {
      this.field_76 = null;
      this.field_77 = null;
      this.field_78 = null;
      this.field_79 = null;
      this.field_80 = null;
      this.field_81 = null;
      this.field_82 = null;
      this.field_83 = null;
      this.field_87 = null;
      this.field_94 = null;
   }

   // $VF: renamed from: a (ak) void
   public final void method_44(class_116 var1) {
      this.field_94 = var1;
      if (var1.field_1437) {
         this.field_95 = true;
      }
   }

   // $VF: renamed from: a (bn, long, cm, boolean) boolean
   public final boolean method_45(class_57 var1, long var2, class_37 var4, boolean var5) {
      if (this.field_98 != null && this.field_97 && this.field_98.field_1433) {
         return false;
      } else {
         this.field_90 = 0;
         this.field_88 = true;
         this.field_92 = true;

         for (int var6 = 0; var6 < this.field_78.length; var6++) {
            if (this.field_83[var6] <= 0) {
               this.field_78[var6].method_9(var1.method_479(this.field_89));
               if (this.field_87 != null) {
                  this.field_89.method_9(this.field_87);
                  this.field_80 = var1.method_508(this.field_89, this.field_80);
                  this.field_78[var6].method_15(this.field_80);
               }

               if (var4 == null) {
                  this.field_89.method_9(var1.method_481(this.field_89));
               } else {
                  this.field_89.method_16(var4.method_344(this.field_89), this.field_78[var6]);
               }

               this.field_79[var6].method_9(this.field_89);
               this.field_79[var6].method_22();
               this.field_79[var6].method_18((int)(this.field_85 * (float)var2) << 12);
               this.field_79[var6].field_37 >>= 12;
               this.field_79[var6].field_38 >>= 12;
               this.field_79[var6].field_39 >>= 12;
               this.field_83[var6] = this.field_86;
               return true;
            }
         }

         return false;
      }
   }

   // $VF: renamed from: a (bn, long, boolean) boolean
   public final boolean method_46(class_57 var1, long var2, boolean var4) {
      return this.method_45(var1, var2, null, var4);
   }

   // $VF: renamed from: c () void
   private void method_47() {
      if (this.field_77 != null) {
         this.field_96 = null;

         for (int var1 = 0; var1 < this.field_77.length; var1++) {
            this.field_82 = this.field_77[var1];
            if (this.field_82.field_375) {
               for (int var2 = 0; var2 < this.field_78.length; var2++) {
                  this.field_80.method_9(this.field_78[var2]);
                  this.field_81.method_9(this.field_79[var2]);
                  int var3 = this.field_82.field_377.field_698 - this.field_80.field_37 + this.field_81.field_37;
                  int var4 = this.field_82.field_377.field_699 - this.field_80.field_38 + this.field_81.field_38;
                  int var5 = this.field_82.field_377.field_700 - this.field_80.field_39 + this.field_81.field_39;
                  int var6 = this.field_97 ? this.field_99 : (int)this.field_82.field_362;
                  if (var3 < var6 && var3 > -var6 && var4 < var6 && var4 > -var6 && var5 < var6 && var5 > -var6) {
                     if (DEEP3D_LOG) System.out.println("[hit] target " + this.field_82 + " owner " + this.field_82.field_379 + " at " + this.field_80.field_37 + " " + this.field_80.field_38 + " " + this.field_80.field_39 + " life " + this.field_83[var2]);
                     this.field_82.method_342(this.field_84, this.field_101);
                     this.field_82.method_337(-this.field_81.field_37, -this.field_81.field_38, -this.field_81.field_39);
                     this.field_83[var2] = -1;
                     this.field_89.method_9(this.field_79[var2]);
                     this.field_89.method_22();
                     this.field_96 = this.field_82.field_379;
                     if (this.field_94 != null) {
                        this.field_94.method_908(this.field_78[var2], this.field_89);
                     }
                  }
               }
            }
         }
      }
   }

   // $VF: renamed from: b (long) void
   private void method_48(long var1) {
      this.field_89.method_10(0, 0, 0);
      if (this.field_76 != null) {
         for (int var3 = 0; var3 < this.field_78.length; var3++) {
            if (this.field_83[var3] > 0 && this.field_76.method_262(this.field_78[var3], !this.field_95)) {
               if (DEEP3D_LOG) System.out.println("[hit] world at " + this.field_78[var3].field_37 + " " + this.field_78[var3].field_38 + " " + this.field_78[var3].field_39 + " life " + this.field_83[var3]);
               this.field_83[var3] = -1;
               this.field_89.method_9(this.field_79[var3]);
               this.field_89.method_22();
               if (this.field_94 != null) {
                  this.field_94.method_908(this.field_78[var3], this.field_89);
               }
            }
         }
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_49(long var1) {
      this.field_90 = (int)(this.field_90 + var1);
      if (this.field_94 != null) {
         this.field_94.method_895(var1);
      }

      if (this.field_92) {
         this.method_47();
         if (this.field_93) {
            this.method_48(var1);
         }

         for (int var3 = 0; var3 < this.field_78.length; var3++) {
            if (this.field_83[var3] > 0) {
               this.field_83[var3] = this.field_83[var3] - (int)var1;
               this.field_78[var3].method_15(this.field_79[var3]);
            } else {
               this.field_78[var3].method_10(50000, 50000, 50000);
               this.field_79[var3].method_10(0, 0, 0);
            }
         }
      }
   }

   // $VF: renamed from: b () void
   public final void method_50() {
      if (this.field_94 != null) {
         this.field_94.method_887();
      }
   }
}
