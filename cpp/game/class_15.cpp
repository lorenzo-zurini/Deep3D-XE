// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_15::__clinit() {
}

void class_15::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_148 = jrt::New<class_3>(var1, var2, var3);
    this->field_149 = var4;
}

void class_15::__init() {
    this->__init(0, 0, 0, 0);
}

void class_15::__init(jrt::Ref<class_15> var1) {
    this->field_148->field_37 = var1->field_148->field_37;
    this->field_148->field_38 = var1->field_148->field_38;
    this->field_148->field_39 = var1->field_148->field_39;
    this->field_149 = var1->field_149;
}

jrt::Ref<class_15> class_15::method_86(jrt::Ref<class_15> var1, jrt::Ref<class_15> var2) {
    if (this->field_149 == 0) {
        var2->method_88(var1);
        return var2;
    } else if (var1->field_149 == 0) {
        var2->method_88(jrt::Ref<class_15>(this));
        return var2;
    } else {
        int32_t var3 = var1->field_148->field_37 - this->field_148->field_37;
        int32_t var4 = var1->field_148->field_38 - this->field_148->field_38;
        int32_t var5 = var1->field_148->field_39 - this->field_148->field_39;
        int32_t var6{};
        int32_t var7 = [&]() { int32_t __l1 = (var6 = var1->field_149 - this->field_149); int32_t __r1 = var6; return (__l1 * __r1); }();
        int32_t var8 = ((var3 * var3) + (var4 * var4)) + (var5 * var5);
        if (var7 >= var8) {
            if (var6 >= 0) {
                var2->method_90(var1->field_148, var1->field_149);
                return var2;
            } else {
                var2->method_90(this->field_148, this->field_149);
                return var2;
            }
        } else {
            int32_t var9 = class_16::method_96((int64_t(var8) << 12));
            int32_t var10 = int32_t(jrt::div((int64_t(((var6 << 12) + var9)) << 12), int64_t((2 * var9))));
            var2->method_89((this->field_148->field_37 + int32_t(((int64_t(var10) * (int64_t(var3) << 12)) >> 24))), (this->field_148->field_38 + int32_t(((int64_t(var10) * (int64_t(var4) << 12)) >> 24))), (this->field_148->field_39 + int32_t(((int64_t(var10) * (int64_t(var5) << 12)) >> 24))), ((((var9 >> 12) + var1->field_149) + this->field_149) >> 1));
            return var2;
        }
    }
}

void class_15::method_87(jrt::Ref<class_15> var1) {
    this->method_86(var1, jrt::Ref<class_15>(this));
}

void class_15::method_88(jrt::Ref<class_15> var1) {
    this->field_148->method_9(var1->field_148);
    this->field_149 = var1->field_149;
}

void class_15::method_89(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_148->field_37 = var1;
    this->field_148->field_38 = var2;
    this->field_148->field_39 = var3;
    this->field_149 = var4;
}

void class_15::method_90(jrt::Ref<class_3> var1, int32_t var2) {
    this->field_148->method_9(var1);
    this->field_149 = var2;
}

jrt::Ref<java::lang::String> class_15::toString() {
    return jrt::concat(JRT_LIT(u"AEBoundingSphere | x: "), this->field_148->field_37, JRT_LIT(u" y: "), this->field_148->field_38, JRT_LIT(u" z: "), this->field_148->field_39, JRT_LIT(u" r: "), this->field_149);
}

void class_15::__dumpFields(jrt::Dumper& d) {
    d.f("field_148", this->field_148);
    d.f("field_149", this->field_149);
}

