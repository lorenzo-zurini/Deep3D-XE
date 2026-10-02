// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_59::__clinit() {
}

void class_59::__init(jrt::Ref<javax::microedition::lcdui::Image> var1, int32_t var2, jrt::Ref<java::lang::String> var3) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_717 = var1;
    this->field_714 = var3;
    this->field_715 = var2;
    this->field_713 = true;
}

void class_59::__init(jrt::Ref<class_68> var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_709 = var1;
    this->field_713 = true;
}

void class_59::__init(jrt::Ref<class_19> var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_710 = var1;
    this->field_713 = true;
}

void class_59::__init(jrt::Ref<class_120> var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_711 = var1;
    this->field_713 = true;
}

void class_59::__init(jrt::Ref<java::lang::String> var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_714 = var1;
    this->field_713 = false;
}

void class_59::__init(int32_t var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_715 = var1;
    this->field_713 = true;
}

void class_59::__init(int32_t var1, int32_t var2) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_716 = var1;
    this->field_715 = var2;
    this->field_713 = true;
}

void class_59::__init(jrt::Ref<class_87> var1) {
    this->field_715 = (-1);
    this->field_716 = 0;
    this->field_712 = var1;
    this->field_713 = true;
}

bool class_59::method_534() {
    return this->field_717 != nullptr;
}

bool class_59::method_535() {
    return this->field_709 != nullptr;
}

bool class_59::method_536() {
    return this->field_710 != nullptr;
}

bool class_59::method_537() {
    return this->field_711 != nullptr;
}

bool class_59::method_538() {
    return !this->field_713;
}

bool class_59::method_539() {
    return this->field_712 != nullptr;
}

bool class_59::method_540() {
    return this->field_715 >= 0;
}

bool class_59::method_541() {
    if (this->method_535()) {
        return this->field_709->method_603() <= class_21::method_182();
    } else if (this->method_536()) {
        return this->field_710->field_167 <= class_21::method_182();
    } else {
        return this->method_537() ? (this->field_711->field_1484 <= class_21::method_182()) : false;
    }
}

bool class_59::method_542() {
    return this->method_536() ? class_21::method_178()->method_626() : false;
}

bool class_59::method_543() {
    return this->method_536() ? class_21::method_178()->method_625(this->field_710->field_165) : false;
}

int32_t class_59::method_544() {
    if (this->method_535()) {
        return this->field_709->method_603();
    } else if (this->method_536()) {
        return this->field_710->field_167;
    } else {
        return this->method_537() ? this->field_711->field_1484 : 0;
    }
}

int32_t class_59::method_545() {
    if (this->method_535()) {
        return this->field_709->field_863;
    } else if (this->method_536()) {
        return this->field_710->field_166;
    } else {
        return this->method_537() ? this->field_711->field_1480 : 999999;
    }
}

void class_59::__dumpFields(jrt::Dumper& d) {
    d.f("field_709", this->field_709);
    d.f("field_710", this->field_710);
    d.f("field_711", this->field_711);
    d.f("field_712", this->field_712);
    d.f("field_713", this->field_713);
    d.f("field_714", this->field_714);
    d.f("field_715", this->field_715);
    d.f("field_716", this->field_716);
    d.f("field_717", this->field_717);
}

