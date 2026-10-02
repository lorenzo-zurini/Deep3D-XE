// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_38::field_384{};
jrt::Ref<class_3> class_38::field_385{};
jrt::Ref<jrt::Array<bool>> class_38::field_386{};

void class_38::__clinit() {
    class_38::field_384 = jrt::New<class_3>();
    class_38::field_385 = jrt::New<class_3>();
    class_38::field_386 = jrt::newArray<bool>(200);
}

void class_38::__init() {
}

jrt::Ref<class_86> class_38::method_354(int32_t var0) {
    return class_49::method_400(var0);
}

void class_38::method_355(jrt::Ref<jrt::Array<bool>> var0) {
    class_38::field_386 = var0;
}

jrt::Ref<jrt::Array<bool>> class_38::method_356() {
    return class_38::field_386;
}

void class_38::method_357(int32_t var0) {
    class_38::field_386->at(var0) = true;
}

int32_t class_38::method_358(int32_t var0) {
    return 15000 + jrt::f2i(((float(var0) / 100.0f) * 15000.0f));
}

int32_t class_38::method_359(int32_t var0) {
    return class_16::method_98(100, class_16::method_97(0, jrt::f2i(((float((var0 - 15000)) / 15000.0f) * 100.0f))));
}

int32_t class_38::method_360(int32_t var0, int32_t var1, int32_t var2, int32_t var3) {
    return 100 - (class_16::method_96(int64_t(((((var2 - var0) * (var2 - var0)) + ((var3 - var1) * (var3 - var1))) << 12))) >> 12);
}

int32_t class_38::method_361(int32_t var0, int32_t var1, int32_t var2, int32_t var3) {
    return class_16::method_96(int64_t(((((var2 - var0) * (var2 - var0)) + ((var3 - var1) * (var3 - var1))) << 12))) >> 12;
}

float class_38::method_362(jrt::Ref<class_86> var0, jrt::Ref<class_86> var1) {
    if (var0->method_753(var1)) {
        return 0.0f;
    } else {
        class_38::field_384->method_10(var0->field_1135, var0->field_1136, (var0->field_1137 / 10));
        class_38::field_385->method_10(var1->field_1135, var1->field_1136, (var1->field_1137 / 10));
        class_38::field_384->method_17(class_38::field_385);
        return float((class_16::method_96(int64_t(((((class_38::field_384->field_37 * class_38::field_384->field_37) + (class_38::field_384->field_38 * class_38::field_384->field_38)) + (class_38::field_384->field_39 * class_38::field_384->field_39)) << 12))) >> 12)) * 18.85f;
    }
}

jrt::Ref<jrt::Array<int8_t>> class_38::method_363(jrt::Ref<class_86> var0) {
    jrt::Ref<jrt::Array<int8_t>> var1 = class_49::method_404();
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2 = class_90::method_785();
    jrt::Ref<jrt::Array<int8_t>> var3 = jrt::newArray<int8_t>(class_90::method_787()->length);
    jrt::Ref<jrt::Array<int8_t>> var4 = jrt::newArray<int8_t>(class_90::method_787()->length);
    for (int32_t var5 = 0; var5 < var3->length; var5++) {
        var4->at(var5) = int8_t(var5);
        var3->at(var5) = int8_t(class_38::method_360(var0->field_1135, var0->field_1136, int32_t(var1->at(((var2->at(var5)->field_1482 * 4) + 1))), int32_t(var1->at(((var2->at(var5)->field_1482 * 4) + 2)))));
        if (int32_t(var3->at(var5)) < 50) {
            var3->at(var5) = int8_t(0);
        }
    }
    bool var9{};
    do {
        var9 = true;
        for (int32_t var6 = 1; var6 < var3->length; var6++) {
            if (int32_t(var3->at((var6 - 1))) < int32_t(var3->at(var6))) {
                int8_t var7 = var3->at((var6 - 1));
                int8_t var8 = var4->at((var6 - 1));
                var3->at((var6 - 1)) = var3->at(var6);
                var4->at((var6 - 1)) = var4->at(var6);
                var3->at(var6) = var7;
                var4->at(var6) = var8;
                var9 = false;
            }
        }
    } while (!var9);
    for (int32_t var10 = 0; var10 < var3->length; var10++) {
        if (int32_t(var3->at(var10)) > 0) {
            var3->at(var10) = int8_t((int32_t(var3->at(var10)) - (2 * var10)));
        }
    }
    jrt::Ref<jrt::Array<int8_t>> var11 = jrt::newArray<int8_t>((var3->length * 2));
    for (int32_t var12 = 0; var12 < var11->length; var12 += 2) {
        var11->at(var12) = var4->at((var12 / 2));
        var11->at((var12 + 1)) = var3->at((var12 / 2));
    }
    return var11;
}

void class_38::__dumpFields(jrt::Dumper& d) {
}

