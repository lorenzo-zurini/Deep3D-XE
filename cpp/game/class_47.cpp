// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_47::__clinit() {
}

void class_47::__init() {
    this->field_531 = jrt::newArray<jrt::Ref<java::lang::String>>(3);
    this->field_530 = 20 + class_58::method_523(class_84::field_1116->method_4(249));
    this->field_531->at(2) = class_84::field_1116->method_4(65);
    this->field_533 = class_58::method_532(class_84::field_1116->method_4(248), (this->field_530 - 10));
}

void class_47::method_393(bool var1, bool var2) {
    this->field_527 = 0;
    this->field_534 = var2;
    this->field_535 = var1;
    this->field_531->at(0) = class_84::field_1116->method_4((var1 ? 249 : 250));
    this->field_531->at(1) = class_84::field_1116->method_4((var1 ? 251 : (var2 ? 241 : 253)));
    int32_t var3 = (var2 && var1) ? 4 : 5;
    this->field_529 = (class_84::field_1121 >> 1) - ((class_58::method_530(this->field_533) + (var3 * class_58::method_527())) >> 1);
    this->field_528 = (class_84::field_1120 - this->field_530) / 2;
    this->field_532 = class_58::method_530(this->field_533) + (class_58::method_527() * (var3 + 1));
}

void class_47::method_394() {
    if (this->field_527 > 0) {
        this->field_527--;
    } else {
        this->field_527 = 2;
    }
    if ((this->field_534 && this->field_535) && (this->field_527 == 1)) {
        this->method_394();
    }
}

void class_47::method_395() {
    if (this->field_527 < 2) {
        this->field_527++;
    } else {
        this->field_527 = 0;
    }
    if ((this->field_534 && this->field_535) && (this->field_527 == 1)) {
        this->method_395();
    }
}

void class_47::method_396() {
    class_67::method_583();
    class_67::method_592(JRT_LIT(u""), this->field_528, this->field_529, this->field_530, this->field_532, true);
    class_58::method_521(this->field_533, (this->field_528 + 5), (this->field_529 + 17), 0);
    for (int32_t var1 = 0; var1 < this->field_531->length; var1++) {
        if (((!this->field_534) || (!this->field_535)) || (var1 != 1)) {
            class_67::method_584(this->field_531->at(var1), this->field_528, ((((this->field_529 + 12) + class_58::method_530(this->field_533)) + 10) + ((((this->field_534 && this->field_535) && (var1 == 2)) ? (var1 - 1) : var1) * 10)), this->field_530, (this->field_527 == var1));
        }
    }
}

void class_47::__dumpFields(jrt::Dumper& d) {
    d.f("field_527", this->field_527);
    d.f("field_528", this->field_528);
    d.f("field_529", this->field_529);
    d.f("field_530", this->field_530);
    d.f("field_531", this->field_531);
    d.f("field_532", this->field_532);
    d.f("field_533", this->field_533);
    d.f("field_534", this->field_534);
    d.f("field_535", this->field_535);
}

