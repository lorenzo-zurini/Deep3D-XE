// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_2::__clinit() {
}

void class_2::__init(jrt::Ref<class_26> var1) {
    this->field_36 = ((var1->field_272->field_982 != nullptr) && (!var1->field_272->field_982->method_111()->field_1298)) ? 3 : ((class_21::method_146() && (class_21::method_180()->field_1134 == 0)) ? 1 : 2);
    this->field_35 = jrt::newArray<jrt::Ref<java::lang::String>>(this->field_36);
    this->field_35->at(0) = class_84::field_1116->method_4(327);
    if (this->field_36 > 1) {
        this->field_35->at(1) = class_21::method_180()->field_1133;
    }
    if (this->field_36 == 3) {
        this->field_35->at(2) = class_84::field_1116->method_4(326);
    }
    this->field_34 = 0;
    for (int32_t var2 = 0; var2 < this->field_35->length; var2++) {
        int32_t var3{};
        if (((var3 = class_58::method_523(this->field_35->at(var2))) + 15) > this->field_34) {
            this->field_34 = var3 + 15;
        }
    }
    this->field_32 = (class_84::field_1120 - this->field_34) / 2;
    this->field_33 = (class_84::field_1121 - ((this->field_36 * 10) + 12)) / 2;
}

void class_2::method_6() {
    if (this->field_31 > 0) {
        this->field_31--;
    } else {
        this->field_31 = this->field_36 - 1;
    }
}

void class_2::method_7() {
    if (this->field_31 < (this->field_36 - 1)) {
        this->field_31++;
    } else {
        this->field_31 = 0;
    }
}

void class_2::method_8() {
    org::deep3d::GameUi::layer(2);
    org::deep3d::GameUi::controls(2, (-5), 57, 0);
    class_67::method_591(class_84::field_1116->method_4(325), this->field_32, this->field_33, this->field_34, ((12 + ((this->field_36 + 1) * 10)) - 5));
    for (int32_t var1 = 0; var1 < this->field_35->length; var1++) {
        class_67::method_584(this->field_35->at(var1), this->field_32, ((this->field_33 + 12) + (var1 * 10)), this->field_34, (this->field_31 == var1));
    }
}

void class_2::__dumpFields(jrt::Dumper& d) {
    d.f("field_31", this->field_31);
    d.f("field_32", this->field_32);
    d.f("field_33", this->field_33);
    d.f("field_34", this->field_34);
    d.f("field_35", this->field_35);
    d.f("field_36", this->field_36);
}

