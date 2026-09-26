import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;

// $VF: renamed from: az
public final class class_73 {
   // $VF: renamed from: a javax.microedition.lcdui.Image
   private Image field_1018;
   // $VF: renamed from: a short[]
   private short[] field_1019;
   // $VF: renamed from: b short[]
   private short[] field_1020;
   // $VF: renamed from: a byte[]
   private byte[] field_1021;
   // $VF: renamed from: a byte
   public byte field_1022;
   // $VF: renamed from: b byte
   public byte field_1023;
   // $VF: renamed from: c byte
   private byte field_1024;
   // $VF: renamed from: a javax.microedition.lcdui.Graphics
   private static Graphics field_1025;
   // $VF: renamed from: d byte
   private byte field_1026;

   public class_73(String var1, Graphics var2) {
      field_1025 = var2;

      try {
         this.field_1018 = class_28.method_282(var1);
         this.field_1019 = new short[224];
         this.field_1020 = new short[this.field_1019.length];
         this.field_1021 = new byte[this.field_1019.length];
         this.field_1023 = this.field_1022 = (byte)(this.field_1018.getHeight() / 14);
         this.field_1024 = (byte)(this.field_1018.getWidth() / 16);
         int[] var3 = new int[this.field_1018.getWidth() * this.field_1018.getHeight()];
         this.field_1018.getRGB(var3, 0, this.field_1018.getWidth(), 0, 0, this.field_1018.getWidth(), this.field_1018.getHeight());

         for (int var4 = 0; var4 < 16; var4++) {
            for (int var5 = 0; var5 < 14; var5++) {
               this.field_1019[var4 + 16 * var5] = (short)(var4 * this.field_1024);
               this.field_1020[var4 + 16 * var5] = (short)(var5 * this.field_1022);
               this.field_1021[var4 + 16 * var5] = this.method_689(var4 * this.field_1024, var5 * this.field_1022, var3);
            }
         }

         this.field_1026 = 1;
         this.field_1021[0] = 3;
      } catch (Exception var6) {
         this.field_1018 = null;
      }

      // System.gc() removed: full GCs stall the desktop JVM
   }

   // $VF: renamed from: a (int, int, int, int) void
   public final void method_687(int var1, int var2, int var3, int var4) {
      boolean var5 = var4 != -1;
      int[] var6 = new int[this.field_1018.getWidth() * this.field_1018.getHeight()];
      this.field_1018.getRGB(var6, 0, this.field_1018.getWidth(), 0, 0, this.field_1018.getWidth(), this.field_1018.getHeight());
      int var7 = this.field_1018.getWidth();
      int var8 = 0;

      for (int var9 = 0; var9 < this.field_1018.getHeight(); var9++) {
         for (int var10 = 0; var10 < this.field_1018.getWidth(); var10++) {
            if (var5) {
               if ((var6[var10 + var8] & 16777215) != var4) {
                  if (var6[var10 + var8] == -1) {
                     var6[var10 + var8] = 16777215;
                  } else {
                     int var13 = var6[var10 + var8] >> 24 & 0xFF;
                     var6[var10 + var8] = var13 << 24 | var1 << 16 | var2 << 8 | var3;
                  }
               }
            } else if (var6[var10 + var8] == -1) {
               var6[var10 + var8] = 16777215;
            } else {
               int var11 = var6[var10 + var8] >> 24 & 0xFF;
               var6[var10 + var8] = var11 << 24 | var1 << 16 | var2 << 8 | var3;
            }
         }

         var8 += var7;
      }

      Image var14 = Image.createRGBImage(var6, this.field_1018.getWidth(), this.field_1018.getHeight(), true);
      this.field_1018 = var14;
   }

   // $VF: renamed from: a (int) void
   public final void method_688(int var1) {
      this.field_1026 = (byte)var1;
   }

   // $VF: renamed from: a (int, int, int[]) byte
   private byte method_689(int var1, int var2, int[] var3) {
      int var4 = this.field_1024 - 1;
      int var5 = this.field_1018.getWidth();

      for (int var6 = 0; var6 < this.field_1024; var6++) {
         for (int var7 = 0; var7 < this.field_1022; var7++) {
            if ((var3[var6 + var1 + (var7 + var2) * var5] >> 24 & 0xFF) > 0 && var3[var6 + var1 + (var7 + var2) * var5] != -1) {
               var4 = var6;
               break;
            }
         }
      }

      return (byte)(var4 + 1);
   }

   // $VF: renamed from: a (java.lang.String) int
   public final int method_690(String var1) {
      int var2 = 0;
      int var3 = 0;

      for (int var4 = 0; var4 < var1.length(); var4++) {
         var3 = this.method_692(var1.charAt(var4));
         var2 += this.field_1021[var3] + this.field_1026;
      }

      return var2;
   }

   // $VF: renamed from: a (java.lang.String, int, int) int
   public final int method_691(String var1, int var2, int var3) {
      int var4 = 0;
      int var5 = 0;
      var2 = var2 >= 0 ? var2 : 0;
      var3 = var3 <= var1.length() ? var3 : var1.length();

      for (int var6 = var2; var6 < var3; var6++) {
         var5 = this.method_692(var1.charAt(var6));
         var4 += this.field_1021[var5] + this.field_1026;
      }

      return var4;
   }

   // $VF: renamed from: a (char) int
   public final int method_692(char var1) {
      switch (var1) {
         case ' ':
            return 0;
         case '!':
            return 1;
         case '"':
            return 2;
         case '#':
            return 3;
         case '$':
            return 4;
         case '%':
            return 5;
         case '&':
            return 6;
         case '\'':
            return 7;
         case '(':
            return 8;
         case ')':
            return 9;
         case '*':
            return 10;
         case '+':
            return 11;
         case ',':
            return 12;
         case '-':
            return 13;
         case '.':
            return 14;
         case '/':
            return 15;
         case '0':
            return 16;
         case '1':
            return 17;
         case '2':
            return 18;
         case '3':
            return 19;
         case '4':
            return 20;
         case '5':
            return 21;
         case '6':
            return 22;
         case '7':
            return 23;
         case '8':
            return 24;
         case '9':
            return 25;
         case ':':
            return 26;
         case ';':
            return 27;
         case '<':
            return 28;
         case '=':
            return 29;
         case '>':
            return 30;
         case '?':
            return 31;
         case '@':
            return 32;
         case 'A':
            return 33;
         case 'B':
            return 34;
         case 'C':
            return 35;
         case 'D':
            return 36;
         case 'E':
            return 37;
         case 'F':
            return 38;
         case 'G':
            return 39;
         case 'H':
            return 40;
         case 'I':
            return 41;
         case 'J':
            return 42;
         case 'K':
            return 43;
         case 'L':
            return 44;
         case 'M':
            return 45;
         case 'N':
            return 46;
         case 'O':
            return 47;
         case 'P':
            return 48;
         case 'Q':
            return 49;
         case 'R':
            return 50;
         case 'S':
            return 51;
         case 'T':
            return 52;
         case 'U':
            return 53;
         case 'V':
            return 54;
         case 'W':
            return 55;
         case 'X':
            return 56;
         case 'Y':
            return 57;
         case 'Z':
            return 58;
         case '[':
            return 59;
         case '\\':
            return 60;
         case ']':
            return 61;
         case '^':
            return 62;
         case '_':
            return 63;
         case '`':
            return 64;
         case 'a':
            return 65;
         case 'b':
            return 66;
         case 'c':
            return 67;
         case 'd':
            return 68;
         case 'e':
            return 69;
         case 'f':
            return 70;
         case 'g':
            return 71;
         case 'h':
            return 72;
         case 'i':
            return 73;
         case 'j':
            return 74;
         case 'k':
            return 75;
         case 'l':
            return 76;
         case 'm':
            return 77;
         case 'n':
            return 78;
         case 'o':
            return 79;
         case 'p':
            return 80;
         case 'q':
            return 81;
         case 'r':
            return 82;
         case 's':
            return 83;
         case 't':
            return 84;
         case 'u':
            return 85;
         case 'v':
            return 86;
         case 'w':
            return 87;
         case 'x':
            return 88;
         case 'y':
            return 89;
         case 'z':
            return 90;
         case '{':
            return 91;
         case '|':
            return 92;
         case '}':
            return 93;
         case '~':
            return 94;
         case '\u0099':
         case '™':
            return 155;
         case '¡':
            return 96;
         case '©':
            return 154;
         case '«':
            return 97;
         case '®':
            return 153;
         case '»':
            return 98;
         case '¿':
            return 99;
         case 'À':
            return 100;
         case 'Á':
            return 101;
         case 'Â':
            return 102;
         case 'Ä':
            return 103;
         case 'Ç':
            return 104;
         case 'È':
            return 105;
         case 'É':
            return 106;
         case 'Ê':
            return 107;
         case 'Ë':
            return 108;
         case 'Ì':
            return 109;
         case 'Í':
            return 110;
         case 'Î':
            return 111;
         case 'Ï':
            return 112;
         case 'Ñ':
            return 113;
         case 'Ò':
            return 114;
         case 'Ó':
            return 115;
         case 'Ô':
            return 116;
         case 'Ö':
            return 117;
         case 'Ù':
            return 118;
         case 'Ú':
            return 119;
         case 'Û':
            return 120;
         case 'Ü':
            return 121;
         case 'Ý':
            return 156;
         case 'ß':
            return 122;
         case 'à':
            return 123;
         case 'á':
            return 124;
         case 'â':
            return 125;
         case 'ä':
            return 126;
         case 'ç':
            return 127;
         case 'è':
            return 128;
         case 'é':
            return 129;
         case 'ê':
            return 130;
         case 'ë':
            return 131;
         case 'ì':
            return 132;
         case 'í':
            return 133;
         case 'î':
            return 134;
         case 'ï':
            return 135;
         case 'ñ':
            return 136;
         case 'ò':
            return 137;
         case 'ó':
            return 138;
         case 'ô':
            return 139;
         case 'ö':
            return 140;
         case 'ù':
            return 141;
         case 'ú':
            return 142;
         case 'û':
            return 143;
         case 'ü':
            return 144;
         case 'ý':
            return 157;
         case 'Č':
            return 158;
         case 'č':
            return 159;
         case 'Ď':
            return 160;
         case 'ď':
            return 161;
         case 'Ě':
            return 162;
         case 'ě':
            return 163;
         case 'Ğ':
            return 147;
         case 'ğ':
            return 148;
         case 'İ':
            return 151;
         case 'ı':
            return 152;
         case 'Ň':
            return 164;
         case 'ň':
            return 165;
         case 'Œ':
            return 146;
         case 'œ':
            return 145;
         case 'Ř':
            return 166;
         case 'ř':
            return 167;
         case 'Ş':
            return 149;
         case 'ş':
            return 150;
         case 'Š':
            return 168;
         case 'š':
            return 169;
         case 'Ť':
            return 170;
         case 'ť':
            return 171;
         case 'Ů':
            return 172;
         case 'ů':
            return 173;
         case 'Ž':
            return 174;
         case 'ž':
            return 175;
         case 'А':
            return 33;
         case 'Б':
            return 176;
         case 'В':
            return 34;
         case 'Г':
            return 177;
         case 'Д':
            return 178;
         case 'Е':
            return 37;
         case 'Ж':
            return 179;
         case 'З':
            return 180;
         case 'И':
            return 181;
         case 'Й':
            return 182;
         case 'К':
            return 43;
         case 'Л':
            return 183;
         case 'М':
            return 45;
         case 'Н':
            return 40;
         case 'О':
            return 47;
         case 'П':
            return 184;
         case 'Р':
            return 48;
         case 'С':
            return 35;
         case 'Т':
            return 52;
         case 'У':
            return 185;
         case 'Ф':
            return 186;
         case 'Х':
            return 56;
         case 'Ц':
            return 187;
         case 'Ч':
            return 188;
         case 'Ш':
            return 189;
         case 'Щ':
            return 190;
         case 'Ъ':
            return 191;
         case 'Ы':
            return 192;
         case 'Ь':
            return 193;
         case 'Э':
            return 194;
         case 'Ю':
            return 195;
         case 'Я':
            return 196;
         case 'а':
            return 65;
         case 'б':
            return 197;
         case 'в':
            return 198;
         case 'г':
            return 199;
         case 'д':
            return 200;
         case 'е':
            return 69;
         case 'ж':
            return 201;
         case 'з':
            return 202;
         case 'и':
            return 203;
         case 'й':
            return 204;
         case 'к':
            return 205;
         case 'л':
            return 206;
         case 'м':
            return 207;
         case 'н':
            return 208;
         case 'о':
            return 79;
         case 'п':
            return 209;
         case 'р':
            return 80;
         case 'с':
            return 67;
         case 'т':
            return 210;
         case 'у':
            return 89;
         case 'ф':
            return 211;
         case 'х':
            return 88;
         case 'ц':
            return 212;
         case 'ч':
            return 213;
         case 'ш':
            return 214;
         case 'щ':
            return 215;
         case 'ъ':
            return 216;
         case 'ы':
            return 217;
         case 'ь':
            return 218;
         case 'э':
            return 219;
         case 'ю':
            return 220;
         case 'я':
            return 221;
         default:
            return 0;
      }
   }

   // $VF: renamed from: a (java.lang.String, int, int) void
   public final void method_693(String var1, int var2, int var3) {
      int var4 = 0;
      int var5 = 0;
      int var6 = var3 - 2;

      for (int var7 = 0; var7 < var1.length(); var7++) {
         var5 = this.method_692(var1.charAt(var7));
         field_1025.drawRegion(this.field_1018, this.field_1019[var5], this.field_1020[var5], this.field_1021[var5], this.field_1023, 0, var2 + var4, var6, 0);
         var4 += this.field_1021[var5] + this.field_1026;
      }
   }

   // $VF: renamed from: b (java.lang.String, int, int) void
   public final void method_694(String var1, int var2, int var3) {
      int var4 = 0;
      int var5 = 0;
      int var6 = var3 - 2;

      for (int var7 = var1.length() - 1; var7 >= 0; var7--) {
         var5 = this.method_692(var1.charAt(var7));
         var4 += this.field_1021[var5];
         field_1025.drawRegion(this.field_1018, this.field_1019[var5], this.field_1020[var5], this.field_1021[var5], this.field_1023, 0, var2 - var4, var6, 0);
         var4 += this.field_1026;
      }
   }

   // $VF: renamed from: c (java.lang.String, int, int) void
   public final void method_695(String var1, int var2, int var3) {
      int var4 = 0;
      int var5 = 0;
      int var6 = var3 - 2;

      for (int var7 = var1.length() - 1; var7 >= 0; var7--) {
         var5 = this.method_692(var1.charAt(var7));
         var4 += this.field_1021[var5];
         field_1025.drawRegion(this.field_1018, this.field_1019[var5], this.field_1020[var5], this.field_1021[var5], this.field_1023, 0, var2 - var4, var6, 0);
         var4 += this.field_1026;
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_696(int var1) {
      this.field_1022 = (byte)var1;
   }
}
