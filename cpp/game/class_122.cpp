// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_122::__clinit() {
}

void class_122::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1501 = var1;
    this->field_1502 = var2;
    this->field_1503 = var3;
    this->field_1504 = class_84::field_1121 / 2;
}

void class_122::__init() {
    this->__init(10, (class_84::field_1121 / 2), (class_84::field_1120 - 20));
}

void class_122::method_945(int32_t var1, int32_t var2) {
    this->field_1508 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/medal_"), var2, JRT_LIT(u".png")));
    this->field_1505 = class_58::method_532(class_84::field_1116->method_4(int32_t(class_1::field_0->at(var1)->at(0))), (((this->field_1503 - 10) - 13) - 4));
    this->field_1506 = class_58::method_532(class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_0->at(var1)->at(1))), jrt::concat(org::deep3d::Scale::medal(var1, class_14::field_135->at(var1)->at((var2 - 1))), JRT_LIT(u""))), (this->field_1503 - 10));
    this->field_1502 = (class_84::field_1121 >> 1) - ((((class_58::method_530(this->field_1506) + 16) + 4) + (2 * class_58::method_527())) >> 1);
    this->field_1507 = ((((this->field_1502 + (this->field_1506->length * class_58::method_527())) + 16) + 4) + 10) + 2;
    this->field_1504 = ((this->field_1507 + class_58::method_527()) + 5) - this->field_1502;
}

void class_122::method_946() {
    org::deep3d::GameUi::controls(3, (-5), (-5), 0);
    org::deep3d::GameUi::button(((this->field_1501 + (this->field_1503 / 2)) - 12), (this->field_1507 - 2), 24, 14, true);
    class_67::method_583();
    class_67::method_592(class_84::field_1116->method_4(163), this->field_1501, this->field_1502, this->field_1503, this->field_1504, true);
    class_84::field_1117->drawImage(this->field_1508, (this->field_1501 + 5), ((this->field_1502 + 10) + 2), 0);
    class_58::method_521(this->field_1505, (((this->field_1501 + 5) + 13) + 4), ((this->field_1502 + 10) + 2), 1);
    class_58::method_521(this->field_1506, (this->field_1501 + 5), (((this->field_1502 + 16) + 2) + 10), 0);
    class_84::field_1117->setColor(class_67::field_844);
    class_58::method_518(JRT_LIT(u"OK"), ((this->field_1501 + (this->field_1503 / 2)) - (class_58::method_523(JRT_LIT(u"OK")) / 2)), this->field_1507, 0);
    class_84::field_1117->drawRect((((this->field_1501 + (this->field_1503 / 2)) - 2) - (class_58::method_523(JRT_LIT(u"OK")) / 2)), this->field_1507, (class_58::method_523(JRT_LIT(u"OK")) + 4), 10);
}

void class_122::__dumpFields(jrt::Dumper& d) {
    d.f("field_1501", this->field_1501);
    d.f("field_1502", this->field_1502);
    d.f("field_1503", this->field_1503);
    d.f("field_1504", this->field_1504);
    d.f("field_1505", this->field_1505);
    d.f("field_1506", this->field_1506);
    d.f("field_1507", this->field_1507);
    d.f("field_1508", this->field_1508);
}

