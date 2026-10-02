// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::lcdui::Graphics> class_73::field_1025{};

void class_73::__clinit() {
}

void class_73::__init(jrt::Ref<java::lang::String> var1, jrt::Ref<javax::microedition::lcdui::Graphics> var2) {
    class_73::field_1025 = var2;
    {
        try {
            this->field_1018 = class_28::method_282(var1);
            this->field_1019 = jrt::newArray<int16_t>(224);
            this->field_1020 = jrt::newArray<int16_t>(this->field_1019->length);
            this->field_1021 = jrt::newArray<int8_t>(this->field_1019->length);
            this->field_1023 = this->field_1022 = int8_t((this->field_1018->getHeight() / 14));
            this->field_1024 = int8_t((this->field_1018->getWidth() / 16));
            jrt::Ref<jrt::Array<int32_t>> var3 = jrt::newArray<int32_t>(([&]() { int32_t __l1 = this->field_1018->getWidth(); int32_t __r1 = this->field_1018->getHeight(); return (__l1 * __r1); }()));
            [&]() { auto __r = this->field_1018; jrt::Ref<jrt::Array<int32_t>> __a2 = var3; int32_t __a3 = 0; int32_t __a4 = this->field_1018->getWidth(); int32_t __a5 = 0; int32_t __a6 = 0; int32_t __a7 = this->field_1018->getWidth(); int32_t __a8 = this->field_1018->getHeight(); return __r->getRGB(__a2, __a3, __a4, __a5, __a6, __a7, __a8); }();
            for (int32_t var4 = 0; var4 < 16; var4++) {
                for (int32_t var5 = 0; var5 < 14; var5++) {
                    this->field_1019->at((var4 + (16 * var5))) = int16_t((var4 * int32_t(this->field_1024)));
                    this->field_1020->at((var4 + (16 * var5))) = int16_t((var5 * int32_t(this->field_1022)));
                    this->field_1021->at((var4 + (16 * var5))) = this->method_689((var4 * int32_t(this->field_1024)), (var5 * int32_t(this->field_1022)), var3);
                }
            }
            this->field_1026 = int8_t(1);
            this->field_1021->at(0) = int8_t(3);
        } catch (const jrt::Thrown& __ex9) {
            if (jrt::isInstance<java::lang::Exception>(__ex9.t)) {
                jrt::Ref<java::lang::Exception> var6 = jrt::cast<java::lang::Exception>(__ex9.t);
                this->field_1018 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
            } else {
                throw;
            }
        }
    }
    java::lang::System::gc();
}

void class_73::method_687(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    bool var5 = var4 != (-1);
    jrt::Ref<jrt::Array<int32_t>> var6 = jrt::newArray<int32_t>(([&]() { int32_t __l1 = this->field_1018->getWidth(); int32_t __r1 = this->field_1018->getHeight(); return (__l1 * __r1); }()));
    [&]() { auto __r = this->field_1018; jrt::Ref<jrt::Array<int32_t>> __a2 = var6; int32_t __a3 = 0; int32_t __a4 = this->field_1018->getWidth(); int32_t __a5 = 0; int32_t __a6 = 0; int32_t __a7 = this->field_1018->getWidth(); int32_t __a8 = this->field_1018->getHeight(); return __r->getRGB(__a2, __a3, __a4, __a5, __a6, __a7, __a8); }();
    int32_t var7 = this->field_1018->getWidth();
    int32_t var8 = 0;
    for (int32_t var9 = 0; var9 < this->field_1018->getHeight(); var9++) {
        for (int32_t var10 = 0; var10 < this->field_1018->getWidth(); var10++) {
            if (var5) {
                if ((var6->at((var10 + var8)) & 16777215) != var4) {
                    if (var6->at((var10 + var8)) == (-1)) {
                        var6->at((var10 + var8)) = 16777215;
                    } else {
                        int32_t var13 = (var6->at((var10 + var8)) >> 24) & 255;
                        var6->at((var10 + var8)) = (((var13 << 24) | (var1 << 16)) | (var2 << 8)) | var3;
                    }
                }
            } else if (var6->at((var10 + var8)) == (-1)) {
                var6->at((var10 + var8)) = 16777215;
            } else {
                int32_t var11 = (var6->at((var10 + var8)) >> 24) & 255;
                var6->at((var10 + var8)) = (((var11 << 24) | (var1 << 16)) | (var2 << 8)) | var3;
            }
        }
        var8 += var7;
    }
    jrt::Ref<javax::microedition::lcdui::Image> var14 = [&]() { jrt::Ref<jrt::Array<int32_t>> __a9 = var6; int32_t __a10 = this->field_1018->getWidth(); int32_t __a11 = this->field_1018->getHeight(); bool __a12 = true; return javax::microedition::lcdui::Image::createRGBImage(__a9, __a10, __a11, __a12); }();
    this->field_1018 = var14;
}

void class_73::method_688(int32_t var1) {
    this->field_1026 = int8_t(var1);
}

int8_t class_73::method_689(int32_t var1, int32_t var2, jrt::Ref<jrt::Array<int32_t>> var3) {
    int32_t var4 = int32_t(this->field_1024) - 1;
    int32_t var5 = this->field_1018->getWidth();
    for (int32_t var6 = 0; var6 < int32_t(this->field_1024); var6++) {
        for (int32_t var7 = 0; var7 < int32_t(this->field_1022); var7++) {
            if ((((var3->at(((var6 + var1) + ((var7 + var2) * var5))) >> 24) & 255) > 0) && (var3->at(((var6 + var1) + ((var7 + var2) * var5))) != (-1))) {
                var4 = var6;
                break;
            }
        }
    }
    return int8_t((var4 + 1));
}

int32_t class_73::method_690(jrt::Ref<java::lang::String> var1) {
    int32_t var2 = 0;
    int32_t var3 = 0;
    for (int32_t var4 = 0; var4 < var1->length(); var4++) {
        var3 = this->method_692(var1->charAt(var4));
        var2 += (int32_t(this->field_1021->at(var3)) + int32_t(this->field_1026));
    }
    return var2;
}

int32_t class_73::method_691(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3) {
    int32_t var4 = 0;
    int32_t var5 = 0;
    var2 = (var2 >= 0) ? var2 : 0;
    var3 = (var3 <= var1->length()) ? var3 : var1->length();
    for (int32_t var6 = var2; var6 < var3; var6++) {
        var5 = this->method_692(var1->charAt(var6));
        var4 += (int32_t(this->field_1021->at(var5)) + int32_t(this->field_1026));
    }
    return var4;
}

int32_t class_73::method_692(char16_t var1) {
    {
        switch (int32_t(var1)) {
        case 32:
            return 0;
        case 33:
            return 1;
        case 34:
            return 2;
        case 35:
            return 3;
        case 36:
            return 4;
        case 37:
            return 5;
        case 38:
            return 6;
        case 39:
            return 7;
        case 40:
            return 8;
        case 41:
            return 9;
        case 42:
            return 10;
        case 43:
            return 11;
        case 44:
            return 12;
        case 45:
            return 13;
        case 46:
            return 14;
        case 47:
            return 15;
        case 48:
            return 16;
        case 49:
            return 17;
        case 50:
            return 18;
        case 51:
            return 19;
        case 52:
            return 20;
        case 53:
            return 21;
        case 54:
            return 22;
        case 55:
            return 23;
        case 56:
            return 24;
        case 57:
            return 25;
        case 58:
            return 26;
        case 59:
            return 27;
        case 60:
            return 28;
        case 61:
            return 29;
        case 62:
            return 30;
        case 63:
            return 31;
        case 64:
            return 32;
        case 65:
            return 33;
        case 66:
            return 34;
        case 67:
            return 35;
        case 68:
            return 36;
        case 69:
            return 37;
        case 70:
            return 38;
        case 71:
            return 39;
        case 72:
            return 40;
        case 73:
            return 41;
        case 74:
            return 42;
        case 75:
            return 43;
        case 76:
            return 44;
        case 77:
            return 45;
        case 78:
            return 46;
        case 79:
            return 47;
        case 80:
            return 48;
        case 81:
            return 49;
        case 82:
            return 50;
        case 83:
            return 51;
        case 84:
            return 52;
        case 85:
            return 53;
        case 86:
            return 54;
        case 87:
            return 55;
        case 88:
            return 56;
        case 89:
            return 57;
        case 90:
            return 58;
        case 91:
            return 59;
        case 92:
            return 60;
        case 93:
            return 61;
        case 94:
            return 62;
        case 95:
            return 63;
        case 96:
            return 64;
        case 97:
            return 65;
        case 98:
            return 66;
        case 99:
            return 67;
        case 100:
            return 68;
        case 101:
            return 69;
        case 102:
            return 70;
        case 103:
            return 71;
        case 104:
            return 72;
        case 105:
            return 73;
        case 106:
            return 74;
        case 107:
            return 75;
        case 108:
            return 76;
        case 109:
            return 77;
        case 110:
            return 78;
        case 111:
            return 79;
        case 112:
            return 80;
        case 113:
            return 81;
        case 114:
            return 82;
        case 115:
            return 83;
        case 116:
            return 84;
        case 117:
            return 85;
        case 118:
            return 86;
        case 119:
            return 87;
        case 120:
            return 88;
        case 121:
            return 89;
        case 122:
            return 90;
        case 123:
            return 91;
        case 124:
            return 92;
        case 125:
            return 93;
        case 126:
            return 94;
        case 153:
            ;
        case 8482:
            return 155;
        case 161:
            return 96;
        case 169:
            return 154;
        case 171:
            return 97;
        case 174:
            return 153;
        case 187:
            return 98;
        case 191:
            return 99;
        case 192:
            return 100;
        case 193:
            return 101;
        case 194:
            return 102;
        case 196:
            return 103;
        case 199:
            return 104;
        case 200:
            return 105;
        case 201:
            return 106;
        case 202:
            return 107;
        case 203:
            return 108;
        case 204:
            return 109;
        case 205:
            return 110;
        case 206:
            return 111;
        case 207:
            return 112;
        case 209:
            return 113;
        case 210:
            return 114;
        case 211:
            return 115;
        case 212:
            return 116;
        case 214:
            return 117;
        case 217:
            return 118;
        case 218:
            return 119;
        case 219:
            return 120;
        case 220:
            return 121;
        case 221:
            return 156;
        case 223:
            return 122;
        case 224:
            return 123;
        case 225:
            return 124;
        case 226:
            return 125;
        case 228:
            return 126;
        case 231:
            return 127;
        case 232:
            return 128;
        case 233:
            return 129;
        case 234:
            return 130;
        case 235:
            return 131;
        case 236:
            return 132;
        case 237:
            return 133;
        case 238:
            return 134;
        case 239:
            return 135;
        case 241:
            return 136;
        case 242:
            return 137;
        case 243:
            return 138;
        case 244:
            return 139;
        case 246:
            return 140;
        case 249:
            return 141;
        case 250:
            return 142;
        case 251:
            return 143;
        case 252:
            return 144;
        case 253:
            return 157;
        case 268:
            return 158;
        case 269:
            return 159;
        case 270:
            return 160;
        case 271:
            return 161;
        case 282:
            return 162;
        case 283:
            return 163;
        case 286:
            return 147;
        case 287:
            return 148;
        case 304:
            return 151;
        case 305:
            return 152;
        case 327:
            return 164;
        case 328:
            return 165;
        case 338:
            return 146;
        case 339:
            return 145;
        case 344:
            return 166;
        case 345:
            return 167;
        case 350:
            return 149;
        case 351:
            return 150;
        case 352:
            return 168;
        case 353:
            return 169;
        case 356:
            return 170;
        case 357:
            return 171;
        case 366:
            return 172;
        case 367:
            return 173;
        case 381:
            return 174;
        case 382:
            return 175;
        case 1040:
            return 33;
        case 1041:
            return 176;
        case 1042:
            return 34;
        case 1043:
            return 177;
        case 1044:
            return 178;
        case 1045:
            return 37;
        case 1046:
            return 179;
        case 1047:
            return 180;
        case 1048:
            return 181;
        case 1049:
            return 182;
        case 1050:
            return 43;
        case 1051:
            return 183;
        case 1052:
            return 45;
        case 1053:
            return 40;
        case 1054:
            return 47;
        case 1055:
            return 184;
        case 1056:
            return 48;
        case 1057:
            return 35;
        case 1058:
            return 52;
        case 1059:
            return 185;
        case 1060:
            return 186;
        case 1061:
            return 56;
        case 1062:
            return 187;
        case 1063:
            return 188;
        case 1064:
            return 189;
        case 1065:
            return 190;
        case 1066:
            return 191;
        case 1067:
            return 192;
        case 1068:
            return 193;
        case 1069:
            return 194;
        case 1070:
            return 195;
        case 1071:
            return 196;
        case 1072:
            return 65;
        case 1073:
            return 197;
        case 1074:
            return 198;
        case 1075:
            return 199;
        case 1076:
            return 200;
        case 1077:
            return 69;
        case 1078:
            return 201;
        case 1079:
            return 202;
        case 1080:
            return 203;
        case 1081:
            return 204;
        case 1082:
            return 205;
        case 1083:
            return 206;
        case 1084:
            return 207;
        case 1085:
            return 208;
        case 1086:
            return 79;
        case 1087:
            return 209;
        case 1088:
            return 80;
        case 1089:
            return 67;
        case 1090:
            return 210;
        case 1091:
            return 89;
        case 1092:
            return 211;
        case 1093:
            return 88;
        case 1094:
            return 212;
        case 1095:
            return 213;
        case 1096:
            return 214;
        case 1097:
            return 215;
        case 1098:
            return 216;
        case 1099:
            return 217;
        case 1100:
            return 218;
        case 1101:
            return 219;
        case 1102:
            return 220;
        case 1103:
            return 221;
        default:
            return 0;
        }
    }
}

void class_73::method_693(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3) {
    int32_t var4 = 0;
    int32_t var5 = 0;
    int32_t var6 = var3 - 2;
    for (int32_t var7 = 0; var7 < var1->length(); var7++) {
        var5 = this->method_692(var1->charAt(var7));
        class_73::field_1025->drawRegion(this->field_1018, int32_t(this->field_1019->at(var5)), int32_t(this->field_1020->at(var5)), int32_t(this->field_1021->at(var5)), int32_t(this->field_1023), 0, (var2 + var4), var6, 0);
        var4 += (int32_t(this->field_1021->at(var5)) + int32_t(this->field_1026));
    }
}

void class_73::method_694(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3) {
    int32_t var4 = 0;
    int32_t var5 = 0;
    int32_t var6 = var3 - 2;
    for (int32_t var7 = var1->length() - 1; var7 >= 0; var7--) {
        var5 = this->method_692(var1->charAt(var7));
        var4 += int32_t(this->field_1021->at(var5));
        class_73::field_1025->drawRegion(this->field_1018, int32_t(this->field_1019->at(var5)), int32_t(this->field_1020->at(var5)), int32_t(this->field_1021->at(var5)), int32_t(this->field_1023), 0, (var2 - var4), var6, 0);
        var4 += int32_t(this->field_1026);
    }
}

void class_73::method_695(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3) {
    int32_t var4 = 0;
    int32_t var5 = 0;
    int32_t var6 = var3 - 2;
    for (int32_t var7 = var1->length() - 1; var7 >= 0; var7--) {
        var5 = this->method_692(var1->charAt(var7));
        var4 += int32_t(this->field_1021->at(var5));
        class_73::field_1025->drawRegion(this->field_1018, int32_t(this->field_1019->at(var5)), int32_t(this->field_1020->at(var5)), int32_t(this->field_1021->at(var5)), int32_t(this->field_1023), 0, (var2 - var4), var6, 0);
        var4 += int32_t(this->field_1026);
    }
}

void class_73::method_696(int32_t var1) {
    this->field_1022 = int8_t(var1);
}

void class_73::__dumpFields(jrt::Dumper& d) {
    d.f("field_1018", this->field_1018);
    d.f("field_1019", this->field_1019);
    d.f("field_1020", this->field_1020);
    d.f("field_1021", this->field_1021);
    d.f("field_1022", this->field_1022);
    d.f("field_1023", this->field_1023);
    d.f("field_1024", this->field_1024);
    d.f("field_1026", this->field_1026);
}

