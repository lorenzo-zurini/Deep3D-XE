// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_116::__clinit() {
}

void class_116::__init(jrt::Ref<class_44> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9, int8_t var10) {
    class_108::__init();
    this->field_1435 = jrt::New<class_24>(var6, var1, 128, var2, var3, var4, var5, var9, var7, var8, var10);
    this->field_1435->field_250->field_1367 = 2;
    this->field_1436 = true;
    this->field_1437 = var6 > 1;
}

void class_116::__init(jrt::Ref<class_44> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9) {
    this->__init(var1, var2, var3, var4, var5, var6, var7, var8, var9, int8_t(2));
}

void class_116::method_845(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1435->field_250->method_845(var1, var2, var3);
}

void class_116::method_908(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    this->method_909(var1->field_37, var1->field_38, var1->field_39);
}

void class_116::method_909(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1435->field_250->method_845(var1, var2, var3);
    this->field_1435->method_233();
    this->field_1436 = false;
}

void class_116::method_910() {
    this->field_1435->method_233();
    this->field_1436 = false;
}

void class_116::method_895(int64_t var1) {
    if (!this->field_1436) {
        this->field_1435->method_234(int32_t(var1));
    }
}

void class_116::method_887() {
    if (!this->field_1436) {
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1435->field_250));
    }
}

jrt::Ref<class_102> class_116::method_840() {
    return jrt::Ref<class_102>(nullptr);
}

void class_116::method_893(jrt::Ref<class_44> var1) {
}

void class_116::method_894() {
    this->field_1435->method_232();
}

void class_116::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1435", this->field_1435);
    d.f("field_1436", this->field_1436);
    d.f("field_1437", this->field_1437);
}

