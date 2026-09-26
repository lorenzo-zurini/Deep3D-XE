// $VF: renamed from: ct
public final class class_59 {
   // $VF: renamed from: a char[][]
   private static final char[][] field_818 = new char[][]{
      {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'}, {' '}
   };
   // $VF: renamed from: a int
   private int field_819;
   // $VF: renamed from: b int
   private int field_820 = 0;
   // $VF: renamed from: c int
   private int field_821;
   // $VF: renamed from: d int
   private int field_822;
   // $VF: renamed from: e int
   private int field_823;
   // $VF: renamed from: a char
   public char field_824 = ' ';
   // $VF: renamed from: a java.lang.String
   public String field_825 = "";
   // $VF: renamed from: f int
   private int field_826;

   public class_59(int var1) {
      this.field_819 = var1;
   }

   // $VF: renamed from: b (int) int
   private int method_581(int var1) {
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
   public final int method_582(int var1) {
      // Deep3D-PC: real keyboard typing (multi-tap kept as fallback).
      org.deep3d.GameUi.textEntryTick();
      String var9 = org.deep3d.GameUi.pollTypedText();

      for (int var10 = 0; var10 < var9.length(); var10++) {
         char var11 = var9.charAt(var10);
         if (var11 == '\b') {
            if (this.field_825.length() > 0) {
               this.field_825 = this.field_825.substring(0, this.field_825.length() - 1);
            }

            this.field_824 = ' ';
            this.field_821 = 0;
         } else if (this.field_825.length() < this.field_819
               && (Character.isLetterOrDigit(var11) || var11 == ' ')) {
            this.field_825 = this.field_825 + var11;
            this.field_824 = ' ';
            this.field_821 = 0;
         }
      }

      this.field_823 += var1;
      if (this.field_826 == 16384) {
         return 0;
      } else if (this.field_825.length() >= this.field_819) {
         return 2;
      } else if ((this.field_823 > 1000 || this.field_824 == ' ') && this.field_826 != 0 && this.field_826 != 524288 && this.field_826 != 8192) {
         this.field_823 = 0;
         this.field_820 = 0;
         this.field_825 = this.field_825 + this.field_824;
         this.field_824 = ' ';
         this.field_826 = 0;
         this.field_821 = 0;
         return 0;
      } else {
         return 2;
      }
   }

   // $VF: renamed from: a (int) void
   public final void method_583(int var1) {
      this.field_826 = var1;
      this.field_823 = 0;
      if (var1 != 524288 && var1 != 8192) {
         if (var1 != this.field_820 && this.field_824 != ' ' && this.field_825.length() < this.field_819) {
            this.field_825 = this.field_825 + this.field_824;
            this.field_821 = 0;
         }

         this.field_822 = this.method_581(var1);
         if (this.field_821 >= field_818[this.field_822].length) {
            this.field_821 = 0;
         }

         this.field_824 = field_818[this.field_822][this.field_821++];
         if (this.field_825.length() > 0 && this.field_825.charAt(this.field_825.length() - 1) != ' ') {
            this.field_824 = String.valueOf(this.field_824).toLowerCase().charAt(0);
         }

         this.field_820 = var1;
      } else if (this.field_825.length() > 0) {
         this.field_823 = 0;
         this.field_824 = ' ';
         this.field_821 = 0;
         this.field_825 = this.field_825.substring(0, this.field_825.length() - 1);
         return;
      }
   }
}
