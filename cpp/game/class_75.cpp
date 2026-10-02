// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_75::__clinit() {
}

void class_75::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5) {
    class_74::__init(var1, var2, var3, var4, var5, JRT_LIT(u""));
    this->class_74::field_1048 = false;
    this->class_74::field_1042 = var1;
    this->field_1051 = false;
}

void class_75::method_710() {
    if (this->field_1051) {
        class_74::method_710();
    }
}

void class_75::method_705() {
    if (this->class_74::field_1046 == 0) {
        if (this->class_74::field_1032->at(this->class_74::field_1038)->at((this->class_74::field_1039 + 1)) != nullptr) {
            this->class_74::field_1039++;
        } else {
            this->class_74::field_1040 = 0;
            this->class_74::field_1039 = 0;
        }
        if (this->class_74::field_1039 > (this->class_74::field_1040 + this->class_74::field_1041)) {
            this->class_74::field_1040++;
        }
    } else if (this->class_74::field_1032->at(this->class_74::field_1038)->at(0) != nullptr) {
        this->class_74::field_1046 = 0;
    }
    this->method_703();
}

void class_75::method_704() {
    if (this->class_74::field_1046 == 0) {
        if (this->class_74::field_1039 > 0) {
            this->class_74::field_1039--;
        } else {
            int32_t var1 = 1;
            while (this->class_74::field_1032->at(this->class_74::field_1038)->at((var1++)) != nullptr) {
            }
            this->class_74::field_1039 = var1 - 2;
            this->class_74::field_1040 = (var1 - 1) - this->class_74::field_1041;
        }
        if (this->class_74::field_1040 > 0) {
            this->class_74::field_1040--;
        }
    }
    this->method_703();
}

void class_75::method_712() {
    for (int32_t var1 = this->class_74::field_1040; ((var1 < this->class_74::field_1032->at(this->class_74::field_1038)->length) && (this->class_74::field_1032->at(this->class_74::field_1038)->at(var1) != nullptr)) && (var1 < ((this->class_74::field_1040 + this->class_74::field_1041) + 1)); var1++) {
        this->method_713(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1), var1);
    }
}

void class_75::method_713(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    class_67::method_584(var1->toString(), this->class_74::field_1042, (this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)), ((this->class_74::field_1034 > 0) ? (this->class_74::field_1029 - 7) : this->class_74::field_1029), (((this->class_74::field_1046 == 0) && (var2 == this->class_74::field_1039)) && this->class_74::field_1048));
}

void class_75::__dumpFields(jrt::Dumper& d) {
    class_74::__dumpFields(d);
    d.f("field_1051", this->field_1051);
}

