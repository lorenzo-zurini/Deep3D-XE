// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_19::__clinit() {
}

void class_19::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9) {
    this->field_166 = var1;
    this->field_165 = var2;
    this->field_168 = var3;
    this->field_169 = var4;
    this->field_170 = var5;
    this->field_171 = var6;
    this->field_172 = var7;
    this->field_173 = var8;
    this->field_174 = var9;
    this->field_167 = var4 + ((var5 - var4) / 2);
    this->field_176 = false;
}

int32_t class_19::method_116() {
    return this->field_167 * this->field_175;
}

int32_t class_19::method_117(int32_t var1) {
    if (var1 == 0) {
        return this->field_171;
    } else if (var1 == 1) {
        return this->field_172;
    } else {
        return (var1 == 2) ? this->field_173 : this->field_174;
    }
}

bool class_19::method_118() {
    return ((this->field_165 == 0) || (this->field_165 == 1)) || (this->field_165 == 2);
}

jrt::Ref<class_19> class_19::method_119(int32_t var1, int32_t var2) {
    jrt::Ref<class_19> var3{};
    (var3 = this->method_121())->field_167 = var2;
    var3->field_175 = var1;
    return var3;
}

jrt::Ref<class_19> class_19::method_120() {
    return this->method_119(1, this->field_167);
}

jrt::Ref<class_19> class_19::method_121() {
    jrt::Ref<class_19> var1{};
    [&]() -> bool& { auto& __l = (var1 = jrt::New<class_19>(this->field_166, this->field_165, this->field_168, this->field_169, this->field_170, this->field_171, this->field_172, this->field_173, this->field_174))->field_176; __l = this->field_176; return __l; }();
    var1->field_167 = this->field_167;
    return var1;
}

bool class_19::method_122(jrt::Ref<class_19> var1) {
    return (var1 == nullptr) ? false : (this->field_166 == var1->field_166);
}

jrt::Ref<java::lang::String> class_19::toString() {
    return jrt::concat(this->field_166, JRT_LIT(u" "), this->field_165, JRT_LIT(u" "), this->field_168, JRT_LIT(u" "), this->field_169, JRT_LIT(u" "), this->field_170, JRT_LIT(u" "), this->field_171, JRT_LIT(u" "), this->field_172, JRT_LIT(u" "), this->field_173, JRT_LIT(u" "), this->field_174);
}

void class_19::method_123(jrt::Ref<class_86> var1) {
    this->field_167 = this->field_169 + jrt::f2i(((float((10 - var1->field_1139)) / 10.0f) * float((this->field_170 - this->field_169))));
    if (this->field_176) {
        this->field_167 = jrt::f2i((float(this->field_167) / 1.25f));
    }
}

void class_19::method_124() {
    this->method_123(class_21::method_180());
    this->field_167 = jrt::f2i((float(this->field_167) / 1.25f));
}

void class_19::__dumpFields(jrt::Dumper& d) {
    d.f("field_165", this->field_165);
    d.f("field_166", this->field_166);
    d.f("field_167", this->field_167);
    d.f("field_168", this->field_168);
    d.f("field_169", this->field_169);
    d.f("field_170", this->field_170);
    d.f("field_171", this->field_171);
    d.f("field_172", this->field_172);
    d.f("field_173", this->field_173);
    d.f("field_174", this->field_174);
    d.f("field_175", this->field_175);
    d.f("field_176", this->field_176);
}

