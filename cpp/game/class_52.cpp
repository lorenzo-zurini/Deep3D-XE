// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_52::__clinit() {
}

void class_52::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_583 = var1;
    this->field_584 = var2;
    this->field_585 = var3;
}

void class_52::__init() {
    this->__init(((class_84::field_1120 / 2) - 40), ((class_84::field_1121 / 2) - 15), 80);
}

void class_52::method_431(jrt::Ref<class_120> var1) {
    this->field_588 = var1;
    this->field_587 = ((this->field_584 + (1 * class_58::method_527())) + 10) + 2;
    this->field_586 = 36;
    this->field_589 = var1->field_1490;
}

bool class_52::method_432() {
    return true;
}

void class_52::method_433() {
    this->field_589--;
    if (this->field_589 < 0) {
        this->field_589 = class_16::method_97(0, this->field_588->field_1490);
    }
}

void class_52::method_434() {
    this->field_589++;
    if (this->field_589 > this->field_588->field_1490) {
        this->field_589 = 0;
    }
}

void class_52::method_435() {
    org::deep3d::GameUi::controls(3, (-5), 0, 0);
    org::deep3d::GameUi::zone(((this->field_583 + (this->field_585 / 2)) - 20), (this->field_584 + 8), 14, 14, (-3));
    org::deep3d::GameUi::zone(((this->field_583 + (this->field_585 / 2)) + 6), (this->field_584 + 8), 14, 14, (-4));
    org::deep3d::GameUi::scrollArea(this->field_583, this->field_584, this->field_585, this->field_586, true);
    org::deep3d::GameUi::button(((this->field_583 + (this->field_585 / 2)) - 14), (this->field_587 - 2), 28, 14, true);
    class_67::method_583();
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(this->field_583, this->field_584, this->field_585, this->field_586);
    class_67::method_591(class_84::field_1116->method_4(263), this->field_583, this->field_584, this->field_585, this->field_586);
    class_58::method_516(jrt::concat(this->field_589, JRT_LIT(u" X")), (this->field_583 + (this->field_585 / 2)), (this->field_584 + 10), 1, 24);
    class_58::method_516(JRT_LIT(u"<"), ((this->field_583 + (this->field_585 / 2)) - 12), (this->field_584 + 10), 1, 18);
    class_58::method_516(JRT_LIT(u">"), ((this->field_583 + (this->field_585 / 2)) + 12), (this->field_584 + 10), 1, 17);
    [&]() { jrt::Ref<java::lang::String> __a1 = class_84::field_1116->method_4(265); int32_t __a2 = ((this->field_583 + (this->field_585 / 2)) - (class_58::method_523(class_84::field_1116->method_4(265)) / 2)); int32_t __a3 = this->field_587; int32_t __a4 = 0; return class_58::method_518(__a1, __a2, __a3, __a4); }();
    class_84::field_1117->setColor(class_67::field_844);
    [&]() { auto __r = class_84::field_1117; int32_t __a5 = (((this->field_583 + (this->field_585 / 2)) - 2) - (class_58::method_523(class_84::field_1116->method_4(265)) / 2)); int32_t __a6 = this->field_587; int32_t __a7 = (class_58::method_523(class_84::field_1116->method_4(265)) + 4); int32_t __a8 = 10; return __r->drawRect(__a5, __a6, __a7, __a8); }();
}

void class_52::__dumpFields(jrt::Dumper& d) {
    d.f("field_583", this->field_583);
    d.f("field_584", this->field_584);
    d.f("field_585", this->field_585);
    d.f("field_586", this->field_586);
    d.f("field_587", this->field_587);
    d.f("field_588", this->field_588);
    d.f("field_589", this->field_589);
}

