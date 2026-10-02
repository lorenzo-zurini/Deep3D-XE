// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_123::__clinit() {
}

void class_123::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_1509 = var1;
    this->field_1510 = var2;
    this->field_1511 = var3;
    this->field_1512 = var4;
}

void class_123::__init() {
    this->__init(0, 0, 0, 4096);
}

jrt::Ref<java::lang::String> class_123::toString() {
    return jrt::concat(JRT_LIT(u"AEQuaternion | "), this->field_1509, JRT_LIT(u",\t"), this->field_1510, JRT_LIT(u",\t"), this->field_1511, JRT_LIT(u",\t"), this->field_1512);
}

void class_123::__dumpFields(jrt::Dumper& d) {
    d.f("field_1509", this->field_1509);
    d.f("field_1510", this->field_1510);
    d.f("field_1511", this->field_1511);
    d.f("field_1512", this->field_1512);
}

