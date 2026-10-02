// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_8::__clinit() {
}

void class_8::__init() {
    this->field_72 = this->field_73 = this->field_74 = 0.0f;
}

jrt::Ref<java::lang::String> class_8::toString() {
    return jrt::concat(JRT_LIT(u"x: "), this->field_72, JRT_LIT(u"   y: "), this->field_73, JRT_LIT(u"   z: "), this->field_74);
}

void class_8::__dumpFields(jrt::Dumper& d) {
    d.f("field_72", this->field_72);
    d.f("field_73", this->field_73);
    d.f("field_74", this->field_74);
}

