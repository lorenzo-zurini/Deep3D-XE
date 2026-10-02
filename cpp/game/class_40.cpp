// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_40::__clinit() {
}

void class_40::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_391 = var1;
    this->field_392 = var2;
    this->field_393 = var3;
}

int32_t class_40::method_365() {
    return jrt::f2i((float(this->field_392) * 0.75f));
}

int32_t class_40::method_366() {
    return jrt::f2i((float(this->field_392) * 1.25f));
}

void class_40::__dumpFields(jrt::Dumper& d) {
    d.f("field_391", this->field_391);
    d.f("field_392", this->field_392);
    d.f("field_393", this->field_393);
}

