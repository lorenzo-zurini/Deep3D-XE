// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> class_14::field_135{};
jrt::Ref<jrt::Array<int32_t>> class_14::field_136{};
jrt::Ref<jrt::Array<int32_t>> class_14::field_137{};
int32_t class_14::field_138{};
int32_t class_14::field_139{};
int32_t class_14::field_140{};
int32_t class_14::field_141{};
int32_t class_14::field_142{};
int32_t class_14::field_143{};
bool class_14::field_144{};
bool class_14::field_145{};
int32_t class_14::field_146{};
int32_t class_14::field_147{};

void class_14::__clinit() {
    class_14::field_135 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({5, 15, 30}), jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({400, 200, 50}), jrt::arrayOf<int32_t>({300, 150, 50}), jrt::arrayOf<int32_t>({200, 100, 50}), jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({500, 250, 50}), jrt::arrayOf<int32_t>({15, 10, 5}), jrt::arrayOf<int32_t>({15, 10, 5}), jrt::arrayOf<int32_t>({10, 7, 5}), jrt::arrayOf<int32_t>({50, 25, 10}), jrt::arrayOf<int32_t>({300, 150, 50}), jrt::arrayOf<int32_t>({350, 150, 25}), jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({8, 5, 3}), jrt::arrayOf<int32_t>({0}), jrt::arrayOf<int32_t>({350, 150, 25}), jrt::arrayOf<int32_t>({1000000, 500000, 125000}), jrt::arrayOf<int32_t>({20, 10, 5}), jrt::arrayOf<int32_t>({10000, 12000, 15000}), jrt::arrayOf<int32_t>({35000, 32000, 30000}), jrt::arrayOf<int32_t>({0})});
    class_14::field_136 = jrt::newArray<int32_t>(class_14::field_135->length);
    class_14::field_137 = jrt::newArray<int32_t>(class_14::field_135->length);
}

void class_14::__init() {
}

void class_14::method_67(jrt::Ref<class_70> var0) {
    class_14::method_81();
    for (int32_t var1 = 0; var1 < class_14::field_135->length; var1++) {
        int32_t var2 = 0;
        if (class_14::field_136->at(var1) != 1) {
            for (int32_t var3 = 0; (var3 < class_14::field_135->at(var1)->length) && (var2 <= 0); var3++) {
                bool var4{};
                var4 = false;
                {
                    jrt::Ref<jrt::Array<bool>> var9{};
                    jrt::Ref<jrt::Array<bool>> var5{};
                    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var6{};
                    jrt::Ref<jrt::Array<bool>> var7{};
                    switch (var1) {
                    case 1:
                        var4 = var0->method_660() <= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 2:
                        var4 = ((((var9 = class_21::method_168())->at(13) && var9->at(14)) && var9->at(15)) && var9->at(16)) && var9->at(17);
                        break;
                    case 3:
                        var5 = class_21::method_168();
                        var4 = true;
                        for (int32_t var10 = 0; var10 < var5->length; var10++) {
                            if (((var10 < 13) || (var10 > 17)) && (!var5->at(var10))) {
                                var4 = false;
                                goto label192_break;
                            }
                        }
                        break;
                    case 4:
                        var4 = class_21::method_202() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 5:
                        var4 = class_21::method_170() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 6:
                        var4 = class_21::method_177() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 7:
                        var6 = class_90::method_785();
                        var7 = class_21::method_195();
                        var4 = true;
                        for (int32_t var11 = 0; var11 < var7->length; var11++) {
                            if ((var6->at(var11)->field_1488 != nullptr) && (!var7->at(var11))) {
                                var4 = false;
                                goto label192_break;
                            }
                        }
                        break;
                    case 8:
                        var4 = class_21::method_191() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 9:
                        var4 = class_14::field_138 >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 10:
                        var4 = class_14::field_139 >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 11:
                        var4 = class_21::method_212() >= int64_t((class_14::field_135->at(var1)->at(var3) * 3600000));
                        break;
                    case 12:
                        var4 = class_21::method_209() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 13:
                        var4 = class_21::method_151() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 14:
                        var4 = class_21::method_205() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 15:
                        var4 = class_14::field_141 == 0;
                        break;
                    case 16:
                        var4 = class_14::field_141 >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 17:
                        var4 = class_21::method_146();
                        break;
                    case 18:
                        var4 = class_21::method_154() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 19:
                        var4 = class_14::field_143 >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 20:
                        var4 = class_21::method_158() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 21:
                        var4 = class_21::method_160() <= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 22:
                        var4 = class_21::method_159() >= class_14::field_135->at(var1)->at(var3);
                        break;
                    case 23:
                        var4 = true;
                        for (int32_t var8 = 0; var8 < (class_14::field_136->length - 1); var8++) {
                            if (class_14::field_136->at(var8) == 0) {
                                var4 = false;
                                break;
                            }
                        }
                    }
                }
                label192_break:;
                if (var4) {
                    var2 = var3 + 1;
                }
            }
        }
        if ((class_14::field_136->at(var1) > var2) || (class_14::field_136->at(var1) == 0)) {
            class_14::field_137->at(var1) = var2;
        }
    }
}

void class_14::method_68() {
    class_14::field_147 = 0;
    class_14::field_146 = 0;
    for (int32_t var0 = 0; var0 < class_14::field_136->length; var0++) {
        if (class_14::field_136->at(var0) == 1) {
            class_14::field_147++;
            class_14::field_146++;
        } else if (class_14::field_136->at(var0) != 0) {
            class_14::field_147++;
        }
    }
    class_14::field_144 = class_14::field_147 == class_14::field_136->length;
    class_14::field_145 = class_14::field_146 == class_14::field_136->length;
}

bool class_14::method_69() {
    return class_14::field_144;
}

bool class_14::method_70() {
    return class_14::field_145;
}

jrt::Ref<jrt::Array<int32_t>> class_14::method_71() {
    return class_14::field_136;
}

jrt::Ref<jrt::Array<int32_t>> class_14::method_72() {
    return class_14::field_137;
}

void class_14::method_73() {
    class_14::field_138++;
}

int32_t class_14::method_74() {
    return class_14::field_138;
}

void class_14::method_75() {
    class_14::field_140++;
}

int32_t class_14::method_76() {
    return class_14::field_140;
}

void class_14::method_77() {
    class_14::field_140 = 0;
}

void class_14::method_78() {
    class_14::field_139++;
}

int32_t class_14::method_79() {
    return class_14::field_139;
}

void class_14::method_80(int32_t var0) {
    if (var0 > class_14::field_143) {
        class_14::field_143 = var0;
    }
    if (var0 < class_14::field_142) {
        class_14::field_142 = var0;
    }
}

void class_14::method_81() {
    if (class_21::method_143() <= 3) {
        class_14::field_141 = 1;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var0{};
        if ((var0 = class_21::method_178()->field_885) != nullptr) {
            for (int32_t var1 = 0; var1 < var0->length; var1++) {
                if ((var0->at(var1) != nullptr) && ((var0->at(var1)->field_165 == 0) || (var0->at(var1)->field_165 == 1))) {
                    class_14::field_141++;
                }
            }
        }
    }
}

void class_14::method_82(jrt::Ref<jrt::Array<int32_t>> var0) {
    class_14::field_136 = var0;
}

void class_14::method_83() {
    for (int32_t var0 = 0; var0 < class_14::field_136->length; var0++) {
        class_14::field_136->at(var0) = 0;
    }
    class_14::field_136->at(0) = 1;
    class_14::method_85();
    class_14::field_143 = 0;
    class_14::field_142 = 1000000;
}

void class_14::method_84() {
    for (int32_t var0 = 0; var0 < class_14::field_136->length; var0++) {
        if ((class_14::field_137->at(var0) > 0) && ((class_14::field_137->at(var0) < class_14::field_136->at(var0)) || (class_14::field_136->at(var0) == 0))) {
            class_14::field_136->at(var0) = class_14::field_137->at(var0);
        }
    }
    class_14::method_68();
    if (class_14::field_147 == (class_14::field_136->length - 1)) {
        class_14::field_137->at(23) = 1;
        class_14::field_136->at(23) = 1;
        class_14::method_68();
    }
}

void class_14::method_85() {
    for (int32_t var0 = 0; var0 < class_14::field_137->length; var0++) {
        class_14::field_137->at(var0) = 0;
    }
    class_14::field_138 = 0;
    class_14::field_139 = 0;
    class_14::field_140 = 0;
    class_14::field_141 = 0;
}

void class_14::__dumpFields(jrt::Dumper& d) {
}

