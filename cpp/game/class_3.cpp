// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_3::__clinit() {
}

void class_3::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_37 = var1;
    this->field_38 = var2;
    this->field_39 = var3;
}

void class_3::__init() {
    this->field_37 = this->field_38 = this->field_39 = 0;
}

void class_3::__init(jrt::Ref<class_3> var1) {
    this->field_37 = var1->field_37;
    this->field_38 = var1->field_38;
    this->field_39 = var1->field_39;
}

void class_3::method_9(jrt::Ref<class_3> var1) {
    this->field_37 = var1->field_37;
    this->field_38 = var1->field_38;
    this->field_39 = var1->field_39;
}

void class_3::method_10(int32_t var1, int32_t var2, int32_t var3) {
    this->field_37 = var1;
    this->field_38 = var2;
    this->field_39 = var3;
}

int32_t class_3::method_11(jrt::Ref<class_3> var1) {
    return int32_t(((((int64_t(this->field_37) * int64_t(var1->field_37)) >> 12) + ((int64_t(this->field_38) * int64_t(var1->field_38)) >> 12)) + ((int64_t(this->field_39) * int64_t(var1->field_39)) >> 12)));
}

int32_t class_3::method_12(jrt::Ref<class_3> var1) {
    return int32_t(((((int64_t(this->field_37) * int64_t(var1->field_37)) >> 12) + ((int64_t(this->field_38) * int64_t(var1->field_38)) >> 12)) + ((int64_t(this->field_39) * int64_t(var1->field_39)) >> 12)));
}

jrt::Ref<class_3> class_3::method_13(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    var2->field_37 = ((this->field_38 * var1->field_39) >> 12) - ((this->field_39 * var1->field_38) >> 12);
    var2->field_38 = ((this->field_39 * var1->field_37) >> 12) - ((this->field_37 * var1->field_39) >> 12);
    var2->field_39 = ((this->field_37 * var1->field_38) >> 12) - ((this->field_38 * var1->field_37) >> 12);
    return var2;
}

jrt::Ref<class_3> class_3::method_14(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    var2->field_37 = this->field_37 + var1->field_37;
    var2->field_38 = this->field_38 + var1->field_38;
    var2->field_39 = this->field_39 + var1->field_39;
    return var2;
}

void class_3::method_15(jrt::Ref<class_3> var1) {
    this->field_37 = this->field_37 + var1->field_37;
    this->field_38 = this->field_38 + var1->field_38;
    this->field_39 = this->field_39 + var1->field_39;
}

jrt::Ref<class_3> class_3::method_16(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    var2->field_37 = this->field_37 - var1->field_37;
    var2->field_38 = this->field_38 - var1->field_38;
    var2->field_39 = this->field_39 - var1->field_39;
    return var2;
}

void class_3::method_17(jrt::Ref<class_3> var1) {
    this->field_37 = this->field_37 - var1->field_37;
    this->field_38 = this->field_38 - var1->field_38;
    this->field_39 = this->field_39 - var1->field_39;
}

void class_3::method_18(int32_t var1) {
    this->field_37 = int32_t(((int64_t(var1) * int64_t(this->field_37)) >> 12));
    this->field_38 = int32_t(((int64_t(var1) * int64_t(this->field_38)) >> 12));
    this->field_39 = int32_t(((int64_t(var1) * int64_t(this->field_39)) >> 12));
}

jrt::Ref<class_3> class_3::method_19(int32_t var1, jrt::Ref<class_3> var2) {
    var2->field_37 = jrt::div((this->field_37 << 12), var1);
    var2->field_38 = jrt::div((this->field_38 << 12), var1);
    var2->field_39 = jrt::div((this->field_39 << 12), var1);
    return var2;
}

void class_3::method_20(int32_t var1) {
    this->field_37 = jrt::div((this->field_37 << 12), var1);
    this->field_38 = jrt::div((this->field_38 << 12), var1);
    this->field_39 = jrt::div((this->field_39 << 12), var1);
}

jrt::Ref<class_3> class_3::method_21(jrt::Ref<class_3> var1) {
    int32_t var2 = class_16::method_95(int32_t(((((int64_t(this->field_37) * int64_t(this->field_37)) >> 12) + ((int64_t(this->field_38) * int64_t(this->field_38)) >> 12)) + ((int64_t(this->field_39) * int64_t(this->field_39)) >> 12))));
    var1->field_37 = (this->field_37 * var2) >> 12;
    var1->field_38 = (this->field_38 * var2) >> 12;
    var1->field_39 = (this->field_39 * var2) >> 12;
    return var1;
}

void class_3::method_22() {
    this->method_21(jrt::Ref<class_3>(this));
}

int32_t class_3::method_23() {
    return class_16::method_96(((((int64_t(this->field_37) * int64_t(this->field_37)) >> 12) + ((int64_t(this->field_38) * int64_t(this->field_38)) >> 12)) + ((int64_t(this->field_39) * int64_t(this->field_39)) >> 12)));
}

jrt::Ref<java::lang::String> class_3::toString() {
    return jrt::concat(JRT_LIT(u"AEVector3D | "), this->field_37, JRT_LIT(u",\t"), this->field_38, JRT_LIT(u",\t"), this->field_39);
}

void class_3::__dumpFields(jrt::Dumper& d) {
    d.f("field_37", this->field_37);
    d.f("field_38", this->field_38);
    d.f("field_39", this->field_39);
}

