// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<java::lang::String> class_21::field_187{};
jrt::Ref<jrt::Array<int8_t>> class_21::field_188{};
jrt::Ref<javax::microedition::lcdui::Image> class_21::field_189{};
int32_t class_21::field_190{};
int32_t class_21::field_191{};
int64_t class_21::field_192{};
int32_t class_21::field_193{};
int32_t class_21::field_194{};
int32_t class_21::field_195{};
int32_t class_21::field_196{};
int32_t class_21::field_197{};
int32_t class_21::field_198{};
int32_t class_21::field_199{};
int32_t class_21::field_200{};
int32_t class_21::field_201{};
int32_t class_21::field_202{};
int32_t class_21::field_203{};
int32_t class_21::field_204{};
int32_t class_21::field_205{};
int32_t class_21::field_206{};
int32_t class_21::field_207{};
int32_t class_21::field_208{};
int32_t class_21::field_209{};
jrt::Ref<jrt::Array<bool>> class_21::field_210{};
jrt::Ref<jrt::Array<bool>> class_21::field_211{};
jrt::Ref<jrt::Array<bool>> class_21::field_212{};
jrt::Ref<class_68> class_21::field_213{};
jrt::Ref<class_87> class_21::field_214{};
jrt::Ref<jrt::Array<jrt::Ref<class_87>>> class_21::field_215{};
jrt::Ref<class_86> class_21::field_216{};
jrt::Ref<jrt::Array<jrt::Ref<class_86>>> class_21::field_217{};
int32_t class_21::field_218{};
int32_t class_21::field_219{};
int32_t class_21::field_220{};
int64_t class_21::field_221{};

void class_21::__clinit() {
    class_21::field_187 = JRT_LIT(u"Player");
    class_21::field_188 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    class_21::field_189 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_21::field_198 = 1;
    class_21::field_210 = jrt::newArray<bool>(class_90::field_1202->length);
    class_21::field_211 = jrt::newArray<bool>(42);
    class_21::field_212 = jrt::newArray<bool>(200);
    class_21::field_215 = jrt::newArray<jrt::Ref<class_87>>(2);
    class_21::field_217 = jrt::newArray<jrt::Ref<class_86>>(3);
}

void class_21::__init() {
}

jrt::Ref<jrt::Array<jrt::Ref<class_86>>> class_21::method_127() {
    return class_21::field_217;
}

void class_21::method_128(jrt::Ref<jrt::Array<jrt::Ref<class_86>>> var0) {
    class_21::field_217 = var0;
}

bool class_21::method_129(jrt::Ref<class_86> var0) {
    jrt::Ref<class_86> var1{};
    if ((var1 = class_21::method_130(var0)) != nullptr) {
        class_21::field_216 = var1;
        return false;
    } else if (class_21::field_217->at(0) == nullptr) {
        for (int32_t var3 = 2; var3 >= 0; var3--) {
            if (class_21::field_217->at(var3) == nullptr) {
                class_21::field_217->at(var3) = var0;
                class_21::field_216 = var0;
                return true;
            }
        }
        return false;
    } else {
        for (int32_t var2 = 2; var2 > 0; var2--) {
            class_21::field_217->at(var2) = class_21::field_217->at((var2 - 1));
        }
        class_21::field_217->at(0) = var0;
        class_21::field_216 = var0;
        return true;
    }
}

jrt::Ref<class_86> class_21::method_130(jrt::Ref<class_86> var0) {
    for (int32_t var1 = 0; var1 < 3; var1++) {
        if ((class_21::field_217->at(var1) != nullptr) && class_21::field_217->at(var1)->method_753(var0)) {
            return class_21::field_217->at(var1);
        }
    }
    return jrt::Ref<class_86>(nullptr);
}

void class_21::method_131(jrt::Ref<class_86> var0) {
    if (class_21::method_130(var0) == nullptr) {
        var0->field_1142 = class_35::method_304(var0);
        var0->field_1143 = class_35::method_306(var0);
        var0->field_1141 = class_35::method_305(var0);
        var0->field_1144 = class_35::method_309(var0);
    }
    class_21::method_129(var0);
    class_21::field_221 = class_21::method_212();
    class_21::method_133(class_87::field_1145);
    for (int32_t var2 = 0; var2 < class_21::field_215->length; var2++) {
        if ((((((((class_21::field_215->at(var2) != nullptr) && (class_21::field_215->at(var2)->field_1152 == var0->field_1134)) && (class_21::field_215->at(var2)->field_1146 != 13)) && (class_21::field_215->at(var2)->field_1146 != 14)) && (class_21::field_215->at(var2)->field_1146 != 21)) && (class_21::field_215->at(var2)->field_1146 != 18)) && (class_21::field_215->at(var2)->field_1146 != 16)) && (class_21::field_215->at(var2)->field_1146 != 15)) {
            if (((class_21::field_215->at(var2)->field_1156 < class_21::field_215->at(var2)->field_1155) || (class_21::field_215->at(var2)->field_1155 < 0)) && (class_21::field_215->at(var2)->field_1161 || (class_21::field_215->at(var2)->field_1146 != 8))) {
                if ((class_21::method_143() == 5) && class_21::field_215->at(var2)->field_1161) {
                    class_21::field_215->at(var2)->field_1171 = true;
                }
                class_21::method_133(class_21::field_215->at(var2));
                return;
            }
            break;
        }
    }
}

jrt::Ref<class_87> class_21::method_132() {
    return class_21::field_214;
}

void class_21::method_133(jrt::Ref<class_87> var0) {
    class_21::field_214 = var0;
}

jrt::Ref<jrt::Array<jrt::Ref<class_87>>> class_21::method_134() {
    return class_21::field_215;
}

jrt::Ref<class_87> class_21::method_135() {
    return class_21::field_215->at(1);
}

void class_21::method_136(jrt::Ref<class_87> var0) {
    class_21::field_215->at(1) = var0;
}

jrt::Ref<class_87> class_21::method_137() {
    return class_21::field_215->at(0);
}

void class_21::method_138(jrt::Ref<class_87> var0) {
    var0->field_1161 = true;
    class_21::field_215->at(0) = var0;
}

bool class_21::method_139() {
    return ((class_21::field_215->at(1) != nullptr) && (!class_21::field_215->at(1)->method_754())) && class_21::field_215->at(1)->method_762();
}

void class_21::method_140() {
    if (class_21::field_215->at(1) != nullptr) {
        class_21::field_215->at(1)->method_760();
    }
}

void class_21::method_141() {
    class_21::field_197++;
}

void class_21::method_142(int32_t var0) {
    class_21::field_209 = var0;
}

int32_t class_21::method_143() {
    return class_21::field_209;
}

void class_21::method_144(jrt::Ref<jrt::Array<int32_t>> var0) {
    if (var0 != nullptr) {
        for (int32_t var1 = 0; var1 < var0->length; var1++) {
            class_21::field_212->at(var0->at(var1)) = true;
        }
    }
}

void class_21::method_145() {
    class_21::field_209++;
    {
        switch (class_21::field_209) {
        case 1:
            class_21::method_138(jrt::New<class_87>(20, 0, 0));
            class_21::method_137()->field_1170 = 1;
            return;
        case 2:
            class_21::method_138(jrt::New<class_87>(8, 0, 0));
            return;
        case 3:
            class_21::method_138(jrt::New<class_87>(17, 0, 0));
            class_21::method_137()->field_1170 = 0;
            class_21::method_137()->field_1171 = false;
            return;
        case 4:
            class_21::method_138(jrt::New<class_87>(22, 0, 0));
            return;
        case 5:
            class_21::method_138(jrt::New<class_87>(3, 0, 1));
            class_21::method_137()->field_1171 = false;
            return;
        case 6:
            class_21::method_138(jrt::New<class_87>(8, 0, 0));
            return;
        case 7:
            class_21::method_138(jrt::New<class_87>(7, 0, 1));
            class_21::method_137()->method_755(0, 5, 0);
            return;
        case 8:
            class_21::method_138(jrt::New<class_87>(8, 1000, 1));
            return;
        case 9:
            class_21::method_138(jrt::New<class_87>(15, 0, 2));
            class_21::method_137()->field_1170 = class_21::field_197 + 3;
            class_21::method_137()->field_1171 = false;
            return;
        case 10:
            class_21::method_138(jrt::New<class_87>(11, 0, 2));
            class_21::method_137()->method_755(0, 10, 5);
            return;
        case 11:
            class_21::method_138(jrt::New<class_87>(8, 0, 2));
            class_21::method_144(jrt::arrayOf<int32_t>({3}));
            return;
        case 12:
            class_21::method_138(jrt::New<class_87>(8, 0, 3));
            class_21::method_144(jrt::arrayOf<int32_t>({4}));
            return;
        case 13:
            class_21::method_138(jrt::New<class_87>(8, 0, 4));
            class_21::method_144(jrt::arrayOf<int32_t>({90}));
            return;
        case 14:
            class_21::method_138(jrt::New<class_87>(8, 0, 5));
            class_21::method_144(jrt::arrayOf<int32_t>({80, 47}));
            return;
        case 15:
            class_21::method_138(jrt::New<class_87>(21, 0, 5));
            class_21::method_137()->field_1170 = class_21::field_201 + 5;
            class_21::method_137()->field_1171 = false;
            class_21::method_144(jrt::arrayOf<int32_t>({80, 47}));
            return;
        case 16:
            class_21::method_138(jrt::New<class_87>(18, 0, 0));
            class_21::method_137()->field_1171 = false;
            class_21::method_137()->field_1170 = class_16::method_98((class_21::method_177() + 5), 200);
            return;
        case 17:
            class_21::method_138(jrt::New<class_87>(8, 0, 3));
            class_21::method_144(jrt::arrayOf<int32_t>({6, 12, 106, 180}));
            return;
        case 18:
            class_21::method_138(jrt::New<class_87>(8, 0, 6));
            class_21::method_137()->field_1171 = false;
            return;
        case 19:
            class_21::method_138(jrt::New<class_87>(6, 2000, 7));
            class_21::method_137()->method_755(10, 30, 15);
            class_21::method_144(jrt::arrayOf<int32_t>({8, 28, 35}));
            return;
        case 20:
            class_21::method_138(jrt::New<class_87>(8, 0, 6));
            return;
        case 21:
            class_21::method_138(jrt::New<class_87>(3, 5000, 8));
            return;
        case 22:
            class_21::method_138(jrt::New<class_87>(8, 0, 9));
            class_21::method_144(jrt::arrayOf<int32_t>({9, 159, 20, 110, 89, 5, 117, 37}));
            return;
        case 23:
            class_21::method_138(jrt::New<class_87>(10, 0, 9));
            return;
        case 24:
            class_21::method_138(jrt::New<class_87>(8, 0, 9));
            class_21::method_144(jrt::arrayOf<int32_t>({22, 57, 14, 75, 63, 186, 131, 175, 140, 189, 54, 74, 81, 25, 149, 96}));
            return;
        case 25:
            class_21::method_138(jrt::New<class_87>(5, 0, 10));
            return;
        case 26:
            class_21::method_138(jrt::New<class_87>(16, 0, 0));
            class_21::method_137()->field_1171 = false;
            class_21::method_137()->field_1170 = class_21::method_202() + 10;
            return;
        case 27:
            class_21::method_138(jrt::New<class_87>(2, 0, 11));
            class_21::method_144(jrt::arrayOf<int32_t>({82, 133, 38, 166, 39, 161, 135, 196, 53, 125, 174, 36}));
            return;
        case 28:
            class_21::method_138(jrt::New<class_87>(8, 0, 12));
            return;
        case 29:
            class_21::method_138(jrt::New<class_87>(4, 5000, 13));
            return;
        case 30:
            class_21::method_138(jrt::New<class_87>(8, 0, 14));
            class_21::method_144(jrt::arrayOf<int32_t>({15, 114, 170, 181, 115, 69, 190, 162, 146, 70, 151, 59, 167, 191, 86, 44, 71, 95, 72, 31, 16, 32, 160, 61}));
            return;
        case 31:
            class_21::method_138(jrt::New<class_87>(1, 0, 2));
            return;
        case 32:
            class_21::method_138(jrt::New<class_87>(8, 100000, 14));
            return;
        case 33:
            class_21::method_138(jrt::New<class_87>(8, 0, 15));
            return;
        case 34:
            class_21::method_138(jrt::New<class_87>(13, 0, 15));
            class_21::method_137()->method_756(37, 1);
            class_21::method_144(jrt::arrayOf<int32_t>({83, 116, 55, 171, 103, 156, 172, 127, 43, 13, 76, 141, 40, 45, 124, 49, 48, 165, 154, 148, 107, 16}));
            return;
        case 35:
            class_21::method_138(jrt::New<class_87>(0, 0, 15));
            return;
        case 36:
            class_21::method_138(jrt::New<class_87>(8, 0, 15));
            class_21::method_144(jrt::arrayOf<int32_t>({19, 143, 64, 120, 188, 126, 119, 34, 145, 66, 98, 144, 155, 104, 52, 26, 78, 29, 108, 164, 132, 185, 27, 100}));
            return;
        case 37:
            class_21::method_138(jrt::New<class_87>(13, 0, 15));
            class_21::method_137()->method_756(38, 1);
            return;
        case 38:
            class_21::method_138(jrt::New<class_87>(8, 0, 14));
            return;
        case 39:
            class_21::method_138(jrt::New<class_87>(8, 0, 16));
            class_21::method_144(jrt::arrayOf<int32_t>({142, 7, 183, 10, 150, 65, 85, 41, 176, 184, 58, 197, 21, 168, 62, 130, 169, 17, 67, 118, 23, 182, 93, 128, 84, 158, 33, 24, 147, 152}));
            return;
        case 40:
            class_21::method_138(jrt::New<class_87>(13, 0, 16));
            class_21::method_137()->method_756(36, 1);
            return;
        case 41:
            class_21::method_138(jrt::New<class_87>(13, 0, 14));
            class_21::method_137()->method_756(36, 1);
            return;
        case 42:
            class_21::method_138(jrt::New<class_87>(3, 0, 17));
            return;
        case 43:
            class_21::method_138(jrt::New<class_87>(4, 0, 14));
            return;
        case 44:
            class_21::method_138(jrt::New<class_87>(8, 0, 14));
            return;
        case 45:
            class_21::method_138(jrt::New<class_87>(5, 0, 18));
            return;
        case 46:
            class_21::method_144(jrt::arrayOf<int32_t>({18, 123, 94, 42, 194, 102, 77, 111, 68, 73, 105, 56, 99}));
            class_21::method_144(jrt::arrayOf<int32_t>({109, 195, 137, 199, 173, 50, 121, 2, 88, 157, 11, 97, 136, 46, 193, 139, 122, 60, 79, 91, 92, 163, 187, 198, 87, 138, 177, 1, 178, 30, 101, 112}));
            class_21::method_138(jrt::New<class_87>(8, 0, 18));
            return;
        case 47:
            class_21::method_138(jrt::New<class_87>(5, 0, 0));
            return;
        case 48:
            class_21::method_138(class_87::field_1145);
            class_21::method_144(jrt::arrayOf<int32_t>({51, 129, 179, 192, 134, 0, 113, 153}));
            class_21::method_137()->field_1171 = false;
        }
    }
}

bool class_21::method_146() {
    return class_21::field_209 >= 48;
}

bool class_21::method_147() {
    return class_21::method_146() && (class_21::field_216->field_1134 == 0);
}

jrt::Ref<class_87> class_21::method_148(bool var0, int64_t var1) {
    for (int32_t var3 = 0; var3 < class_21::field_215->length; var3++) {
        jrt::Ref<class_87> var4{};
        if ((var4 = class_21::field_215->at(var3))->field_1163) {
            return jrt::Ref<class_87>(nullptr);
        }
        if (var4 != nullptr) {
            {
                jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var5{};
                switch (var4->field_1146) {
                case 8:
                    if (var0 && (class_21::method_180()->field_1134 == var4->field_1152)) {
                        return var4;
                    }
                case 9:
                    ;
                case 10:
                    ;
                case 11:
                    ;
                case 12:
                    ;
                default:
                    break;
                case 13:
                    ;
                case 14:
                    if ((var0 && (class_21::method_180()->field_1134 == var4->field_1152)) && class_120::method_931(var4->field_1164, var4->field_1165, class_21::method_178()->field_886)) {
                        return var4;
                    }
                    break;
                case 15:
                    if (class_21::field_197 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 16:
                    if (class_21::field_193 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 17:
                    var5 = class_21::method_178()->field_885;
                    for (int32_t var6 = 0; var6 < var5->length; var6++) {
                        if ((var5->at(var6) != nullptr) && (var5->at(var6)->field_166 == var4->field_1170)) {
                            return var4;
                        }
                    }
                    break;
                case 18:
                    if (class_21::field_200 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 19:
                    if (class_21::field_195 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 20:
                    if (class_21::field_213->field_867 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 21:
                    if (class_21::field_201 >= var4->field_1170) {
                        var4->field_1163 = true;
                        return var4;
                    }
                    break;
                case 22:
                    if ((!var0) && (var1 > int64_t(10000))) {
                        return var4;
                    }
                }
            }
        }
    }
    return jrt::Ref<class_87>(nullptr);
}

void class_21::method_149(int32_t var0) {
    class_21::field_204 = var0;
}

void class_21::method_150() {
    class_21::field_204++;
}

int32_t class_21::method_151() {
    return class_21::field_204;
}

void class_21::method_152() {
    class_21::field_205++;
}

void class_21::method_153(int32_t var0) {
    class_21::field_205 = var0;
}

int32_t class_21::method_154() {
    return class_21::field_205;
}

void class_21::method_155() {
    class_21::field_206++;
}

int32_t class_21::method_156() {
    return class_21::field_203;
}

void class_21::method_157(int32_t var0) {
    class_21::field_206 = var0;
}

int32_t class_21::method_158() {
    return class_21::field_206;
}

int32_t class_21::method_159() {
    return class_21::field_207;
}

int32_t class_21::method_160() {
    return class_21::field_208;
}

void class_21::method_161(int32_t var0) {
    class_21::field_207 = var0;
}

void class_21::method_162(int32_t var0) {
    class_21::field_208 = var0;
}

void class_21::method_163(jrt::Ref<class_87> var0) {
    for (int32_t var1 = 0; var1 < class_21::field_215->length; var1++) {
        if (class_21::field_215->at(var1) == var0) {
            class_21::field_215->at(var1) = class_87::field_1145;
        }
    }
    if (class_21::field_214 == var0) {
        class_21::field_214 = jrt::Ref<class_87>(nullptr);
    }
}

void class_21::method_164(int32_t var0) {
    if (var0 < class_21::field_210->length) {
        class_21::field_210->at(var0) = true;
        if ((var0 < 13) || (var0 > 17)) {
            class_21::field_195++;
            class_14::method_78();
        }
    }
}

void class_21::method_165(int32_t var0) {
    class_21::field_203 = var0;
}

void class_21::method_166(int32_t var0) {
    class_21::field_203 += var0;
}

void class_21::method_167(jrt::Ref<jrt::Array<bool>> var0) {
    class_21::field_210 = var0;
}

jrt::Ref<jrt::Array<bool>> class_21::method_168() {
    return class_21::field_210;
}

void class_21::method_169(int32_t var0) {
    class_21::field_195 = var0;
}

int32_t class_21::method_170() {
    return class_21::field_195;
}

void class_21::method_171(int32_t var0) {
    class_21::field_196 = var0;
}

int32_t class_21::method_172() {
    return class_21::field_196;
}

void class_21::method_173() {
    class_21::field_196++;
}

void class_21::method_174(jrt::Ref<jrt::Array<bool>> var0) {
    class_21::field_212 = var0;
}

jrt::Ref<jrt::Array<bool>> class_21::method_175() {
    return class_21::field_212;
}

void class_21::method_176() {
    class_21::field_200++;
}

int32_t class_21::method_177() {
    return class_21::field_200;
}

jrt::Ref<class_68> class_21::method_178() {
    return class_21::field_213;
}

void class_21::method_179(jrt::Ref<class_68> var0) {
    class_21::field_213 = var0;
}

jrt::Ref<class_86> class_21::method_180() {
    return class_21::field_216;
}

void class_21::method_181(jrt::Ref<class_86> var0) {
    class_21::field_216 = var0;
}

int32_t class_21::method_182() {
    return class_21::field_190;
}

void class_21::method_183(int32_t var0) {
    class_21::field_191 = var0;
}

void class_21::method_184(int64_t var0) {
    class_21::field_192 = var0;
}

void class_21::method_185(int32_t var0) {
    class_21::field_193 = var0;
}

void class_21::method_186(int32_t var0) {
    class_21::field_194 = var0;
}

void class_21::method_187(int32_t var0) {
    class_21::field_197 = var0;
}

void class_21::method_188(int32_t var0) {
    class_21::field_198 = var0;
}

void class_21::method_189(int32_t var0) {
    class_21::field_199 = var0;
}

void class_21::method_190(int32_t var0) {
    class_21::field_201 = var0;
}

int32_t class_21::method_191() {
    return class_21::field_201;
}

void class_21::method_192(int32_t var0) {
    class_21::field_201 += var0;
}

void class_21::method_193(int32_t var0) {
    class_21::field_211->at(var0) = true;
}

void class_21::method_194(jrt::Ref<jrt::Array<bool>> var0) {
    class_21::field_211 = var0;
}

jrt::Ref<jrt::Array<bool>> class_21::method_195() {
    return class_21::field_211;
}

void class_21::method_196(int32_t var0) {
    class_21::field_200 = var0;
}

void class_21::method_197(int32_t var0) {
    class_21::field_190 += var0;
}

void class_21::method_198(int32_t var0) {
    class_21::field_190 = var0;
}

void class_21::method_199() {
    int32_t var0 = ((class_21::field_195 + (2 * class_21::field_193)) + class_21::field_201) + (3 * class_21::field_197);
    if ((float(class_21::field_199) * 1.3f) < float(var0)) {
        class_21::field_199 = var0;
        class_21::field_198++;
    }
}

int32_t class_21::method_200() {
    return class_21::field_191;
}

int32_t class_21::method_201() {
    return class_21::field_199;
}

int32_t class_21::method_202() {
    return class_21::field_193;
}

void class_21::method_203() {
    class_21::field_193++;
    class_14::method_73();
}

void class_21::method_204(int32_t var0) {
    class_21::field_202 = var0;
}

int32_t class_21::method_205() {
    return class_21::field_202;
}

void class_21::method_206() {
    class_21::field_202++;
    class_14::method_75();
}

void class_21::method_207() {
    class_21::field_194++;
}

int32_t class_21::method_208() {
    return class_21::field_194;
}

int32_t class_21::method_209() {
    return class_21::field_197;
}

int32_t class_21::method_210() {
    return class_21::field_198;
}

void class_21::method_211(int64_t var0) {
    class_21::field_192 += var0;
}

int64_t class_21::method_212() {
    return class_21::field_192;
}

jrt::Ref<java::lang::String> class_21::method_213() {
    return class_21::field_187;
}

void class_21::method_214(jrt::Ref<java::lang::String> var0) {
    class_21::field_187 = var0;
}

jrt::Ref<jrt::Array<int8_t>> class_21::method_215() {
    return class_21::field_188;
}

void class_21::method_216(jrt::Ref<jrt::Array<int8_t>> var0) {
    class_21::field_188 = var0;
}

jrt::Ref<javax::microedition::lcdui::Image> class_21::method_217() {
    return class_21::field_189;
}

void class_21::method_218(jrt::Ref<javax::microedition::lcdui::Image> var0) {
    class_21::field_189 = var0;
}

jrt::Ref<java::lang::String> class_21::method_219(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1) {
    int32_t var2{};
    return ((var2 = var0->indexOf(35)) >= 0) ? jrt::concat(var0->substring(0, var2), var1, var0->substring((var2 + 1))) : var0;
}

void class_21::method_220() {
    for (int32_t var0 = 0; var0 < 2; var0++) {
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1{};
        if ((var1 = (var0 == 0) ? class_21::field_213->field_886 : class_21::field_216->field_1142) != nullptr) {
            jrt::Ref<jrt::Array<int8_t>> var5 = class_49::method_404();
            for (int32_t var6 = 0; var6 < var1->length; var6++) {
                jrt::Ref<class_120> var7 = var1->at(var6);
                int32_t var4 = class_38::method_361(int32_t(var5->at(((var7->field_1482 * 4) + 1))), int32_t(var5->at(((var7->field_1482 * 4) + 2))), int32_t(var5->at(((var7->field_1483 * 4) + 1))), int32_t(var5->at(((var7->field_1483 * 4) + 2))));
                int32_t var3{};
                if (((var7->field_1480 != 33) && (var7->field_1480 != 34)) && (var7->field_1480 != 35)) {
                    var3 = class_38::method_361(int32_t(var5->at(((var1->at(var6)->field_1482 * 4) + 1))), int32_t(var5->at(((var1->at(var6)->field_1482 * 4) + 2))), class_21::method_180()->field_1135, class_21::method_180()->field_1136);
                } else {
                    var3 = class_38::method_361(int32_t(var5->at(((var1->at(var6)->field_1483 * 4) + 1))), int32_t(var5->at(((var1->at(var6)->field_1483 * 4) + 2))), class_21::method_180()->field_1135, class_21::method_180()->field_1136);
                }
                int32_t var2 = var7->field_1486 + jrt::f2i((class_16::method_99(1.0f, (((100.0f / float(var4)) * float(var3)) / 100.0f)) * float((var7->field_1487 - var7->field_1486))));
                var7->field_1484 = var2;
            }
        }
    }
}

void class_21::method_221() {
    class_21::field_190 = 15000;
    class_21::field_191 = 0;
    class_21::field_193 = 0;
    class_21::field_194 = 0;
    class_21::field_197 = 0;
    class_21::field_201 = 0;
    class_21::field_202 = 0;
    class_21::field_203 = 0;
    class_21::field_204 = 0;
    class_21::field_205 = 0;
    class_21::field_206 = 0;
    class_21::field_208 = 22500;
    class_21::field_207 = class_21::field_208;
    class_21::field_198 = 1;
    class_21::field_195 = 0;
    class_21::field_196 = 0;
    class_21::field_199 = 15;
    class_21::field_200 = 0;
    class_84::field_1108 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    class_21::field_192 = int64_t(0);
    class_14::method_83();
    jrt::Ref<jrt::Array<bool>> var0 = class_38::method_356();
    for (int32_t var1 = 0; var1 < var0->length; var1++) {
        var0->at(var1) = false;
    }
    class_38::method_355(var0);
    for (int32_t var3 = 0; var3 < class_21::field_212->length; var3++) {
        class_21::field_212->at(var3) = false;
    }
    for (int32_t var4 = 0; var4 < class_21::field_210->length; var4++) {
        class_21::field_210->at(var4) = false;
    }
    for (int32_t var5 = 0; var5 < class_21::field_211->length; var5++) {
        class_21::field_211->at(var5) = false;
    }
    class_84::method_737();
    class_21::method_136(class_87::field_1145);
    class_21::method_142(0);
    class_21::method_145();
    class_21::method_133(class_21::method_137());
    class_21::method_179(class_90::method_783()->at(0)->method_627());
    class_21::method_178()->field_884 = false;
    class_21::method_178()->method_628();
    class_21::method_181(class_38::method_354(0));
    if ((class_21::field_188 == nullptr) && (class_21::field_189 == nullptr)) {
        class_21::method_216(class_119::method_920(true, 3));
    }
    class_21::method_178()->method_611(jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr));
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var6{};
    (var6 = jrt::newArray<jrt::Ref<class_19>>(4))->at(0) = class_90::method_781()->at(15)->method_120();
    var6->at(1) = class_90::method_781()->at(18)->method_120();
    var6->at(2) = class_90::method_781()->at(22)->method_120();
    var6->at(3) = class_90::method_781()->at(35)->method_120();
    for (int32_t var2 = 0; var2 < var6->length; var2++) {
        var6->at(var2)->method_124();
        var6->at(var2)->field_176 = true;
    }
    class_21::method_178()->method_616(var6);
    class_21::field_220 = class_21::method_178()->field_864;
    class_21::field_218 = class_21::method_178()->field_871;
    class_21::field_219 = class_21::method_178()->field_872;
}

void class_21::__dumpFields(jrt::Dumper& d) {
}

