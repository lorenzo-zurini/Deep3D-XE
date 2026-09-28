// $VF: renamed from: cu
public final class class_32 {
   // $VF: renamed from: a char[][]
   private static final char[][] field_320 = new char[][]{
      {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'}, {' '}
   };
   // $VF: renamed from: a int
   private int field_321;
   // $VF: renamed from: b int
   private int field_322 = 0;
   // $VF: renamed from: c int
   private int field_323;
   // $VF: renamed from: d int
   private int field_324;
   // $VF: renamed from: e int
   private int field_325;
   // $VF: renamed from: a char
   public char field_326 = ' ';
   // $VF: renamed from: a java.lang.String
   public String field_327 = "";
   // $VF: renamed from: f int
   private int field_328;

   public class_32(int var1) {
      this.field_321 = var1;
   }

   // $VF: renamed from: b (int) int
   private int method_289(int var1) {
      switch (var1) {
         case 2:
            return 0;
         case 4:
            return 2;
         case 32:
            return 4;
         case 64:
            return 6;
         case 256:
            return 3;
         case 512:
            return 5;
         case 1024:
            return 7;
         case 65536:
            return 1;
         default:
            return 8;
      }
   }

   // $VF: renamed from: a (int) int
   public final int method_290(int var1) {
      this.field_325 += var1;
      if (this.field_328 == 16384) {
         return 0;
      } else if (this.field_327.length() >= this.field_321) {
         return 2;
      } else if ((this.field_325 > 1000 || this.field_326 == ' ') && this.field_328 != 0 && this.field_328 != 524288 && this.field_328 != 8192) {
         this.field_325 = 0;
         this.field_322 = 0;
         this.field_327 = this.field_327 + this.field_326;
         this.field_326 = ' ';
         this.field_328 = 0;
         this.field_323 = 0;
         return 0;
      } else {
         return 2;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_291(int var1) {
      this.field_328 = var1;
      this.field_325 = 0;
      if (var1 != 524288 && var1 != 8192) {
         if (var1 != this.field_322 && this.field_326 != ' ' && this.field_327.length() < this.field_321) {
            this.field_327 = this.field_327 + this.field_326;
            this.field_323 = 0;
         }

         this.field_324 = this.method_289(var1);
         if (this.field_323 >= field_320[this.field_324].length) {
            this.field_323 = 0;
         }

         this.field_326 = field_320[this.field_324][this.field_323++];
         if (this.field_327.length() > 0 && this.field_327.charAt(this.field_327.length() - 1) != ' ') {
            this.field_326 = String.valueOf(this.field_326).toLowerCase().charAt(0);
         }

         this.field_322 = var1;
      } else if (this.field_327.length() > 0) {
         this.field_325 = 0;
         this.field_326 = ' ';
         this.field_323 = 0;
         this.field_327 = this.field_327.substring(0, this.field_327.length() - 1);
         return;
      }
   }
}
