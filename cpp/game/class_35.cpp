// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_35::__clinit() {
}

void class_35::__init() {
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_35::method_302() {
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0{};
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1 = jrt::newArray<jrt::Ref<class_120>>((var0 = class_90::method_785())->length);
    int32_t var2 = 0;
    for (int32_t var3 = 0; var3 < var0->length; var3++) {
        if ((var0->at(var3)->field_1488 != nullptr) && (var0->at(var3)->field_1481 <= class_21::method_180()->field_1139)) {
            var1->at((var2++)) = var0->at(var3)->method_929(0);
        }
    }
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var13 = jrt::newArray<jrt::Ref<class_120>>(var2);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1), 0, jrt::Ref<java::lang::Object>(var13), 0, var2);
    if ((var0 = class_21::method_178()->field_886) != nullptr) {
        for (int32_t var4 = 0; var4 < var13->length; var4++) {
            jrt::Ref<jrt::Array<int8_t>> var5 = var13->at(var4)->field_1488;
            if (var13->at(var4)->field_1488 != nullptr) {
                jrt::Ref<jrt::Array<int8_t>> var6 = var13->at(var4)->field_1489;
                jrt::Ref<jrt::Array<int8_t>> var7 = jrt::newArray<int8_t>(var5->length);
                int32_t var8 = 0;
                int32_t var9 = 2147483647;
                for (int32_t var10 = 0; var10 < var5->length; var10++) {
                    for (int32_t var11 = 0; var11 < var0->length; var11++) {
                        if (var0->at(var11)->field_1480 == int32_t(var5->at(var10))) {
                            if (var0->at(var11)->field_1490 > 0) {
                                var7->at(var10) = int8_t(jrt::div(var0->at(var11)->field_1490, int32_t(var6->at(var10))));
                                if (int32_t(var7->at(var10)) < var9) {
                                    var9 = int32_t(var7->at(var10));
                                }
                            } else {
                                var9 = 0;
                            }
                            var8++;
                        }
                    }
                }
                if (var8 >= var5->length) {
                    var13->at(var4)->field_1490 = var9;
                }
                var13->at(var4)->field_1492 = var5->length - var8;
            }
        }
    }
    bool var14{};
    do {
        var14 = true;
        for (int32_t var15 = 1; var15 < var13->length; var15++) {
            if ((float(var13->at((var15 - 1))->field_1488->length) / float(var13->at((var15 - 1))->field_1492)) < (float(var13->at(var15)->field_1488->length) / float(var13->at(var15)->field_1492))) {
                jrt::Ref<class_120> var16 = var13->at((var15 - 1));
                var13->at((var15 - 1)) = var13->at(var15);
                var13->at(var15) = var16;
                var14 = false;
            }
        }
    } while (!var14);
    return var13;
}

void class_35::method_303(jrt::Ref<class_86> var0) {
    for (int32_t var2 = 33; var2 < 36; var2++) {
        int32_t var1{};
        if ((!class_120::method_932(var2, var0->field_1142)) && ((var1 = class_84::field_1123->nextInt(class_16::method_97(5, (class_21::method_143() / 2)))) > 0)) {
            jrt::Ref<class_120> var3 = class_90::method_785()->at(var2)->method_929(var1);
            var0->method_749(var3);
        }
    }
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var6 = var0->field_1142;
    if (var0->field_1142 != nullptr) {
        for (int32_t var7 = 0; var7 < var6->length; var7++) {
            int32_t var5 = var6->at(var7)->field_1490;
            int32_t var4{};
            if ((var4 = class_84::field_1123->nextInt(3)) < var5) {
                var6->at(var7)->method_926((-var4));
            }
        }
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_35::method_304(jrt::Ref<class_86> var0) {
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2 = jrt::newArray<jrt::Ref<class_120>>((0 + class_84::field_1123->nextInt(5)));
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var3 = class_90::method_785();
    jrt::Ref<jrt::Array<int8_t>> var4 = class_49::method_404();
    for (int32_t var5 = 0; var5 < var2->length; var5++) {
        bool var6 = false;
        int32_t var7 = 0;
        int32_t var8 = 0;
        int32_t var9 = 0;
        while (!var6) {
            while ((var7 = 19 + class_84::field_1123->nextInt((var3->length - 19))) == 36) {
            }
            if ((var7 != 37) && (var7 != 38)) {
                int8_t var10 = var4->at(((var3->at(var7)->field_1482 * 4) + 1));
                int8_t var11 = var4->at(((var3->at(var7)->field_1482 * 4) + 2));
                int32_t var12 = var3->at(var7)->field_1481;
                bool var13{};
                if (var13 = var3->at(var7)->field_1489 != nullptr) {
                    var8 = class_38::method_360(var0->field_1135, var0->field_1136, int32_t(var10), int32_t(var11));
                }
                if ((class_84::field_1123->nextInt(100) < var8) && (var12 <= var0->field_1139)) {
                    bool var14 = false;
                    for (int32_t var15 = 0; var15 < var2->length; var15++) {
                        if (var3->at(var7)->method_938(var2->at(var15))) {
                            var14 = true;
                            break;
                        }
                    }
                    if ((!var14) && (class_84::field_1123->nextInt(100) <= var3->at(var7)->field_1485)) {
                        var6 = true;
                    }
                }
                if ((++var9) > 100) {
                    return jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
                }
            }
        }
        int32_t var16 = 5 + class_84::field_1123->nextInt(15);
        var2->at(var5) = var3->at(var7)->method_929(var16);
    }
    return var2;
}

jrt::Ref<jrt::Array<jrt::Ref<class_19>>> class_35::method_305(jrt::Ref<class_86> var0) {
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var1 = class_90::method_781();
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var2 = jrt::Ref<jrt::Array<jrt::Ref<class_19>>>(nullptr);
    bool var3{};
    var2 = jrt::newArray<jrt::Ref<class_19>>(((var3 = var0->field_1137 < 0) ? 42 : (2 + class_84::field_1123->nextInt(4))));
    for (int32_t var5 = 0; var5 < var2->length; var5++) {
        int32_t var6 = 0;
        if (var3) {
            var6 = var5;
        } else {
            bool var7 = false;
            while (!var7) {
                var6 = class_84::field_1123->nextInt(var1->length);
                bool var8 = false;
                for (int32_t var9 = 0; var9 < var2->length; var9++) {
                    if (var1->at(var6)->method_122(var2->at(var9))) {
                        var8 = true;
                        break;
                    }
                }
                if (((!var8) && (var1->at(var6)->field_168 > 0)) && (class_84::field_1123->nextInt(100) < (var1->at(var6)->field_168 + class_21::method_143()))) {
                    var7 = true;
                }
            }
        }
        var2->at(var5) = var1->at(var6)->method_120();
        var2->at(var5)->method_123(var0);
    }
    return var2;
}

jrt::Ref<jrt::Array<jrt::Ref<class_68>>> class_35::method_306(jrt::Ref<class_86> var0) {
    jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var1 = class_90::method_783();
    jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var2 = jrt::Ref<jrt::Array<jrt::Ref<class_68>>>(nullptr);
    bool var3{};
    int32_t var4{};
    if ((var4 = (var3 = var0->field_1137 > 100) ? var1->length : class_84::field_1123->nextInt(4)) == 0) {
        return jrt::Ref<jrt::Array<jrt::Ref<class_68>>>(nullptr);
    } else {
        var2 = jrt::newArray<jrt::Ref<class_68>>(var4);
        for (int32_t var5 = 0; var5 < var2->length; var5++) {
            int32_t var6 = 0;
            if (var3) {
                var6 = var5;
            } else {
                bool var7 = false;
                while (!var7) {
                    if ((((var6 = class_84::field_1123->nextInt(class_90::field_1205->length)) - 2) * 5) <= class_21::method_143()) {
                        var7 = true;
                    }
                }
            }
            var2->at(var5) = class_90::method_788(int32_t(class_90::field_1205->at(var6)))->method_627();
            var2->at(var5)->field_884 = !var0->method_752();
            var2->at(var5)->method_629();
        }
        return var2;
    }
}

jrt::Ref<class_120> class_35::method_307() {
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0 = class_90::method_785();
    bool var1 = false;
    int32_t var2 = 0;
    while (!var1) {
        while ((((var2 = class_84::field_1123->nextInt(var0->length)) == 36) || (var2 == 37)) || (var2 == 38)) {
        }
        if (class_84::field_1123->nextInt(100) < var0->at(var2)->field_1485) {
            var1 = true;
        }
    }
    int32_t var3 = (var2 == 40) ? 1 : (1 + class_84::field_1123->nextInt(7));
    return var0->at(var2)->method_930(var3, var0->at(var2)->field_1487);
}

int32_t class_35::method_308(jrt::Ref<jrt::Array<int8_t>> var0, jrt::Ref<class_86> var1) {
    int32_t var2 = 0;
    bool var3 = false;
    while (!var3) {
        var2 = class_16::method_97(20, class_84::field_1123->nextInt(200));
        if (((class_84::field_1123->nextInt(100) >= 70) || ((int32_t(var0->at(((var2 * 4) + 3))) <= class_21::method_178()->field_888) && (int32_t(var0->at(((var2 * 4) + 3))) >= class_21::method_178()->field_887))) && ((class_84::field_1123->nextInt(100) >= 100) || ((class_16::method_100((int32_t(var0->at(((var2 * 4) + 1))) - var1->field_1135)) <= (20 + class_21::method_143())) && (class_16::method_100((int32_t(var0->at(((var2 * 4) + 2))) - var1->field_1136)) <= (20 + class_21::method_143()))))) {
            var3 = true;
        }
    }
    return var2;
}

jrt::Ref<jrt::Array<jrt::Ref<class_87>>> class_35::method_309(jrt::Ref<class_86> var0) {
    jrt::Ref<jrt::Array<int8_t>> var1 = class_49::method_404();
    jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var2 = jrt::newArray<jrt::Ref<class_87>>((1 + class_84::field_1123->nextInt(8)));
    for (int32_t var3 = 0; var3 < var2->length; var3++) {
        int32_t var4 = 0;
        do {
            if (class_84::field_1123->nextInt(100) < 40) {
                var4 = var0->field_1134;
            } else {
                var4 = class_35::method_308(var1, var0);
            }
        } while (var4 <= 20);
        bool var5 = false;
        int32_t var6 = 0;
        while (!var5) {
            var6 = class_84::field_1123->nextInt(15);
            var5 = true;
            if ((var6 == 13) || (var6 == 14)) {
                if (var0->field_1134 > 20) {
                    var4 = var0->field_1134;
                    var5 = true;
                } else {
                    var5 = false;
                }
            }
            if (var0->method_752()) {
                if (((((var6 == 13) || (var6 == 14)) || (var6 == 6)) || (var6 == 12)) || (var6 == 13)) {
                    var5 = false;
                }
            } else {
                if ((((class_21::method_146() && (var6 == 6)) || (var6 == 12)) || (var6 == 5)) || (var6 == 4)) {
                    var5 = false;
                }
                if ((var6 == 7) || (var6 == 11)) {
                    var5 = false;
                }
            }
        }
        int32_t var7 = var0->method_752() ? 0 : 1;
        bool var8 = class_84::field_1123->nextInt(100) < 60;
        jrt::Ref<java::lang::String> var9 = class_90::method_790(0, var8);
        jrt::Ref<jrt::Array<int8_t>> var10 = class_119::method_920(var8, var7);
        int32_t var13 = 0;
        int32_t var14 = 0;
        int32_t var11{};
        if ((var6 != 13) && (var6 != 14)) {
            if (class_21::method_143() < 10) {
                var11 = 1 + class_84::field_1123->nextInt(2);
            } else {
                var11 = 1 + class_84::field_1123->nextInt(9);
            }
        } else {
            jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var15 = class_90::method_785();
            bool var16 = false;
            int32_t var17 = 0;
            while (!var16) {
                do {
                    if (var6 == 13) {
                        var17 = (class_90::field_1202->length + 1) + class_84::field_1123->nextInt(((var15->length - class_90::field_1202->length) - 1));
                    } else {
                        var17 = class_84::field_1123->nextInt(class_90::field_1202->length);
                    }
                } while (((((((var17 == 33) || (var17 == 34)) || (var17 == 35)) || (var17 == 37)) || (var17 == 38)) || (var17 == 39)) || (var17 == 40));
                if (class_84::field_1123->nextInt(100) < var15->at(var17)->field_1485) {
                    var16 = true;
                }
            }
            var14 = var17;
            if (var6 == 14) {
                var13 = 3 + class_84::field_1123->nextInt(22);
            } else {
                var13 = 1 + class_84::field_1123->nextInt(9);
            }
            var11 = (var6 == 14) ? jrt::f2i(((float(var13) / 25.0f) * 10.0f)) : (var15->at(var17)->field_1481 + 2);
        }
        if ((var6 != 10) && (var6 != 8)) {
            if ((var6 == 12) || (var6 == 11)) {
                int32_t var25{};
                for (var25 = 100; (((var6 == 12) && class_21::method_175()->at(var4)) || ((var6 == 11) && (!class_21::method_175()->at(var4)))) && (var25 > 0); var25--) {
                    var4 = class_35::method_308(var1, var0);
                }
                if (var25 <= 0) {
                    var6 = 3;
                }
            }
        } else {
            while (var4 == var0->field_1134) {
                var4 = class_35::method_308(var1, var0);
            }
        }
        int32_t var12 = var11 * class_16::method_98(20, class_16::method_97(1, (class_21::method_210() / 2)));
        int32_t var26 = (var6 != 8) ? (-1) : (class_84::field_1123->nextInt(6) - 1);
        float var27 = 1.0f + (class_38::method_362(var0, class_38::method_354(var4)) / 1500.0f);
        float var28{};
        var28 = (var28 = float((3500 + jrt::f2i(((float(var12) / 200.0f) * 9500.0f))))) * var27;
        if (var6 == 9) {
            var28 *= 0.7f;
        } else if (((var6 == 6) || (var6 == 4)) || (var6 == 11)) {
            var28 *= 1.3f;
        } else if ((var6 == 12) || (var6 == 7)) {
            var28 *= 1.2f;
        } else if (var6 == 13) {
            var28 = (var28 / 2.0f) + float(((var13 * class_90::method_785()->at(var14)->field_1487) * 3));
        } else if ((var6 == 8) && (var26 >= 0)) {
            var28 += float(jrt::f2i(((float((6 - var26)) * var28) / 20.0f)));
        }
        int32_t var18 = jrt::f2i(var28) % 50;
        var28 = (jrt::fmod((var28 + float(var18)), 50.0f) == 0.0f) ? (var28 + float(var18)) : (var28 - float(var18));
        var2->at(var3) = jrt::New<class_87>(var6, var9, var10, var7, jrt::f2i(var28), var4, var12, var26);
        int32_t var19 = jrt::f2i(((var28 / 10.0f) + float(class_84::field_1123->nextInt((jrt::f2i(var28) / 10)))));
        if ((var6 == 13) || (var6 == 14)) {
            var19 = jrt::f2i((float(var19) * 0.5f));
        }
        var18 = var19 % 50;
        var19 = (((var19 + var18) % 50) == 0) ? (var19 + var18) : (var19 - var18);
        var2->at(var3)->field_1151 = var19;
        var2->at(var3)->method_756(var14, var13);
        int32_t var20 = 0;
        float var21 = float(var11) / 10.0f;
        if (var6 == 7) {
            var20 = class_84::field_1123->nextInt(13);
            var2->at(var3)->method_755(var20, (3 + jrt::f2i((var21 * 7.0f))), 0);
        } else if (var6 != 6) {
            if (var6 == 11) {
                int32_t var34{};
                int32_t var36 = [&]() { int32_t __l1 = (var34 = 5 + class_84::field_1123->nextInt(10)); int32_t __r1 = jrt::f2i(((1.0f - var21) * float(var34))); return (__l1 - __r1); }();
                var2->at(var3)->method_755(0, var34, var36);
            } else if (var6 == 12) {
                int32_t var35 = 3 + class_84::field_1123->nextInt(3);
                var2->at(var3)->method_755(0, var35, var35);
            }
        } else {
            while (((((var20 == 0) || (var20 == 2)) || (var20 == 9)) || (var20 == 11)) || (var20 == 12)) {
                var20 = class_84::field_1123->nextInt(13);
            }
            int32_t var22{};
            int32_t var23 = [&]() { int32_t __l2 = (var22 = 15 + class_84::field_1123->nextInt(10)); int32_t __r2 = jrt::f2i(((1.0f - var21) * (float(var22) * 0.35f))); return (__l2 - __r2); }();
            var2->at(var3)->method_755(var20, var22, var23);
        }
    }
    return var2;
}

void class_35::__dumpFields(jrt::Dumper& d) {
}

