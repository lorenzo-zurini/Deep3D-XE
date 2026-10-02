// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_121::__clinit() {
}

void class_121::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1493 = var1;
    this->field_1494 = var2;
    this->field_1495 = var3;
    this->field_1496 = class_84::field_1121 / 2;
}

void class_121::__init() {
    this->__init(((class_84::field_1120 < 176) ? 10 : 20), (class_84::field_1121 / 2), (class_84::field_1120 - ((class_84::field_1120 < 176) ? 20 : 40)));
}

void class_121::method_939(jrt::Ref<java::lang::String> var1) {
    this->method_940(var1, false);
}

void class_121::method_940(jrt::Ref<java::lang::String> var1, bool var2) {
    this->field_1499 = true;
    this->field_1500 = var2;
    this->field_1497 = class_58::method_532(var1, (this->field_1495 - 10));
    this->field_1494 = (class_84::field_1121 >> 1) - ((class_58::method_530(this->field_1497) + (2 * class_58::method_527())) >> 1);
    this->field_1498 = ((this->field_1494 + (this->field_1497->length * class_58::method_527())) + 10) + 2;
    this->field_1496 = ((this->field_1498 + class_58::method_527()) + 5) - this->field_1494;
}

bool class_121::method_941() {
    return this->field_1500 ? this->field_1499 : false;
}

void class_121::method_942() {
    if ((!this->field_1499) && this->field_1500) {
        this->field_1499 = true;
    }
}

void class_121::method_943() {
    if (this->field_1499 && this->field_1500) {
        this->field_1499 = false;
    }
}

void class_121::method_944() {
    org::deep3d::GameUi::controls(3, (-5), (this->field_1500 ? 1 : (-5)), 0);
    class_67::method_583();
    class_67::method_592(JRT_LIT(u""), this->field_1493, this->field_1494, this->field_1495, this->field_1496, true);
    class_58::method_521(this->field_1497, (this->field_1493 + 5), (this->field_1494 + 10), 0);
    class_84::field_1117->setColor(class_67::field_844);
    if (this->field_1500) {
        class_58::method_516(class_84::field_1116->method_4(45), (this->field_1493 + (this->field_1495 / 3)), this->field_1498, (this->field_1499 ? 0 : 1), 24);
        class_58::method_516(class_84::field_1116->method_4(46), ((this->field_1493 + this->field_1495) - (this->field_1495 / 3)), this->field_1498, (this->field_1499 ? 1 : 0), 24);
        int32_t var90 = class_58::method_523(class_84::field_1116->method_4(45)) + 12;
        int32_t var91 = class_58::method_523(class_84::field_1116->method_4(46)) + 12;
        org::deep3d::GameUi::button(((this->field_1493 + (this->field_1495 / 3)) - (var90 / 2)), (this->field_1498 - 2), var90, 14, this->field_1499);
        org::deep3d::GameUi::button((((this->field_1493 + this->field_1495) - (this->field_1495 / 3)) - (var91 / 2)), (this->field_1498 - 2), var91, 14, (!this->field_1499));
        if (this->field_1499) {
            [&]() { auto __r = class_84::field_1117; int32_t __a1 = (((this->field_1493 + (this->field_1495 / 3)) - 2) - (class_58::method_523(class_84::field_1116->method_4(45)) / 2)); int32_t __a2 = this->field_1498; int32_t __a3 = (class_58::method_523(class_84::field_1116->method_4(45)) + 4); int32_t __a4 = 10; return __r->drawRect(__a1, __a2, __a3, __a4); }();
        } else {
            [&]() { auto __r = class_84::field_1117; int32_t __a5 = ((((this->field_1493 + this->field_1495) - (this->field_1495 / 3)) - 2) - (class_58::method_523(class_84::field_1116->method_4(46)) / 2)); int32_t __a6 = this->field_1498; int32_t __a7 = (class_58::method_523(class_84::field_1116->method_4(46)) + 4); int32_t __a8 = 10; return __r->drawRect(__a5, __a6, __a7, __a8); }();
        }
    } else {
        org::deep3d::GameUi::button(((this->field_1493 + (this->field_1495 / 2)) - 12), (this->field_1498 - 2), 24, 14, true);
        class_58::method_518(JRT_LIT(u"OK"), ((this->field_1493 + (this->field_1495 / 2)) - (class_58::method_523(JRT_LIT(u"OK")) / 2)), this->field_1498, 0);
        class_84::field_1117->drawRect((((this->field_1493 + (this->field_1495 / 2)) - 2) - (class_58::method_523(JRT_LIT(u"OK")) / 2)), this->field_1498, (class_58::method_523(JRT_LIT(u"OK")) + 4), 10);
    }
}

void class_121::__dumpFields(jrt::Dumper& d) {
    d.f("field_1493", this->field_1493);
    d.f("field_1494", this->field_1494);
    d.f("field_1495", this->field_1495);
    d.f("field_1496", this->field_1496);
    d.f("field_1497", this->field_1497);
    d.f("field_1498", this->field_1498);
    d.f("field_1499", this->field_1499);
    d.f("field_1500", this->field_1500);
}

