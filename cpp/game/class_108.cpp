// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_57> class_108::field_1365{};
jrt::Ref<class_57> class_108::field_1366{};

void class_108::__clinit() {
    class_108::field_1365 = jrt::New<class_57>();
    class_108::field_1366 = jrt::New<class_57>();
}

void class_108::__init() {
    class_105::__init();
    this->field_1364 = 0;
    this->field_1368 = jrt::New<class_57>();
    this->field_1367 = 0;
}

void class_108::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        this->field_1368 = var1->field_1342->method_503(this->field_1368);
        if (this->field_1364 != 0) {
            class_108::field_1365->method_469();
            class_108::field_1365->method_491(0, 0, this->field_1364);
            class_108::field_1366 = this->class_102::field_1342->method_473(class_108::field_1365, class_108::field_1366);
            this->field_1368->method_471(class_108::field_1366);
        } else {
            this->field_1368->method_471(this->class_102::field_1342);
        }
        var2->method_30(this->field_1367, jrt::Ref<class_108>(this));
    }
}

void class_108::method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        this->field_1368 = var1->field_1342->method_503(this->field_1368);
        this->field_1368->method_471(this->class_102::field_1342);
        var2->method_30(this->field_1367, jrt::Ref<class_108>(this));
    }
}

void class_108::method_888() {
}

jrt::Ref<class_108> class_108::method_889(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2) {
    return jrt::Ref<class_108>(jrt::New<class_111>(var0, var1, var2));
}

jrt::Ref<class_108> class_108::method_890(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int8_t var8) {
    return jrt::Ref<class_108>(jrt::New<class_110>(var0, var1, var2, var3, var4, var5, var6, var7, var8));
}

jrt::Ref<class_108> class_108::method_891(int32_t var0, jrt::Ref<java::lang::String> var1) {
    return jrt::Ref<class_108>(jrt::New<class_117>(var1));
}

jrt::Ref<class_108> class_108::method_892(int32_t var0, int32_t var1, int8_t var2) {
    return jrt::Ref<class_108>(jrt::New<class_109>(var0, var1, var2));
}

void class_108::method_895(int64_t var1) {
}

void class_108::__dumpFields(jrt::Dumper& d) {
    class_105::__dumpFields(d);
    d.f("field_1364", this->field_1364);
    d.f("field_1367", this->field_1367);
    d.f("field_1368", this->field_1368);
}

