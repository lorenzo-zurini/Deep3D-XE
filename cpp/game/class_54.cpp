// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_54::__clinit() {
}

void class_54::__init(jrt::Ref<DeepMIDlet> var1, jrt::Ref<class_33> var2) {
    this->field_595 = jrt::Ref<class_61>(nullptr);
    this->field_596 = var1;
    this->field_597 = var2;
}

void class_54::method_439(jrt::Ref<class_61> var1) {
    if (this->field_595 != nullptr) {
        if (this->field_597 != nullptr) {
            this->field_597->method_296(true);
        }
        class_84::field_1116->method_5();
        this->field_595->method_552();
    }
    this->field_595 = var1;
}

void class_54::method_440() {
    this->field_596->quit();
}

void class_54::method_441(int32_t var1) {
    if ((this->field_595 != nullptr) && this->field_595->method_553()) {
        this->field_595->method_550(var1);
    }
}

void class_54::method_442(int32_t var1) {
    if (this->field_595 != nullptr) {
        if (this->field_595->method_553()) {
            this->field_595->method_549(var1);
            return;
        }
        this->field_595->method_551();
        if (this->field_595->method_553() && (this->field_597 != nullptr)) {
            this->field_597->method_295();
        }
        java::lang::System::gc();
    }
}

void class_54::__dumpFields(jrt::Dumper& d) {
    d.f("field_595", this->field_595);
    d.f("field_596", this->field_596);
    d.f("field_597", this->field_597);
}

