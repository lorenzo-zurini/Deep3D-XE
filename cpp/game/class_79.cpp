// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_79::__clinit() {
}

void class_79::__init() {
    class_76::__init((class_84::field_1120 / 8), (class_84::field_1121 / 6), (class_84::field_1120 - (class_84::field_1120 / 4)), ((2 * class_84::field_1121) / 3), jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr), class_84::field_1116->method_4(260));
    jrt::Ref<jrt::Array<jrt::Ref<class_40>>> var1 = class_90::method_787();
    jrt::Ref<jrt::Array<bool>> var2 = class_21::method_168();
    int32_t var3 = 0;
    for (int32_t var4 = 0; var4 < (var2->length - 5); var4++) {
        if (var2->at(var4)) {
            var3++;
        }
    }
    int8_t var8 = int8_t(1);
    if ((((var2->at(13) || var2->at(14)) || var2->at(15)) || var2->at(16)) || var2->at(17)) {
        var8 = int8_t(2);
    }
    jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var5{};
    (var5 = jrt::newArray<jrt::Ref<class_59>>((var3 + int32_t(var8))))->at(0) = [&]() { jrt::Ref<javax::microedition::lcdui::Image> __a1 = class_28::method_282(JRT_LIT(u"/data/interface/x_1.png")); int32_t __a2 = (-1); jrt::Ref<java::lang::String> __a3 = class_84::field_1116->method_4(324); jrt::Ref<class_59> __o(new class_59()); __o->__init(__a1, __a2, __a3); return __o; }();
    if (int32_t(var8) == 2) {
        var5->at(1) = [&]() { jrt::Ref<javax::microedition::lcdui::Image> __a4 = class_28::method_282(JRT_LIT(u"/data/interface/cargo_17.png")); int32_t __a5 = (-3); jrt::Ref<java::lang::String> __a6 = class_84::field_1116->method_4(261); jrt::Ref<class_59> __o(new class_59()); __o->__init(__a4, __a5, __a6); return __o; }();
    }
    int32_t var6 = int32_t(var8);
    for (int32_t var7 = 0; var7 < (var2->length - 5); var7++) {
        if (var2->at(var7)) {
            var5->at((var6++)) = [&]() { jrt::Ref<javax::microedition::lcdui::Image> __a7 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var1->at(var7)->field_391, JRT_LIT(u".png"))); int32_t __a8 = var1->at(var7)->field_391; jrt::Ref<java::lang::String> __a9 = class_84::field_1116->method_4(int32_t(class_1::field_7->at(var1->at(var7)->field_391)->at(0))); jrt::Ref<class_59> __o(new class_59()); __o->__init(__a7, __a8, __a9); return __o; }();
        }
    }
    class_76::method_700(0, jrt::arrayView<jrt::Ref<java::lang::Object>>(var5));
    this->method_703();
}

jrt::Ref<javax::microedition::lcdui::Image> class_79::method_727(int32_t var1) {
    if (var1 >= 0) {
        for (int32_t var2 = 0; var2 < this->class_74::field_1032->at(this->class_74::field_1038)->length; var2++) {
            if ((this->class_74::field_1032->at(this->class_74::field_1038)->at(var2) != nullptr) && ((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(var2)))->field_715 == var1)) {
                return (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(var2)))->field_717;
            }
        }
    }
    return jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
}

int32_t class_79::method_728() {
    return (this->class_74::field_1032->at(0)->at(this->class_74::field_1039) != nullptr) ? (jrt::cast<class_59>(this->class_74::field_1032->at(0)->at(this->class_74::field_1039)))->field_715 : (-1);
}

void class_79::method_720() {
    if (this->class_74::field_1032 != nullptr) {
        class_84::field_1117->setColor(class_67::field_844);
        for (int32_t var1 = this->class_74::field_1040; ((var1 < this->class_74::field_1032->at(this->class_74::field_1038)->length) && (this->class_74::field_1032->at(this->class_74::field_1038)->at(var1) != nullptr)) && (var1 < ((this->class_74::field_1040 + this->class_74::field_1041) + 1)); var1++) {
            jrt::Ref<java::lang::Object> var2 = jrt::Ref<java::lang::Object>(nullptr);
            if ((var1 == this->class_74::field_1039) && (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1)))->field_713) {
                class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), 21, (this->class_74::field_1044 - 1));
                class_84::field_1117->fillRect(((this->class_74::field_1042 + 18) + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((this->class_74::field_1029 - 18) - 10) - this->class_74::field_1035), (this->class_74::field_1044 - 1));
            }
            this->method_721(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1), var1);
        }
        this->method_729();
    }
}

void class_79::method_729() {
    class_67::method_586(class_84::field_1116->method_4(41), this->class_74::field_1027, ((this->class_74::field_1028 + this->class_74::field_1030) - 16), this->class_74::field_1029, true, true);
}

void class_79::method_721(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    jrt::Ref<class_59> var3{};
    if ((var3 = jrt::cast<class_59>(var1))->method_534()) {
        class_84::field_1117->drawImage(var3->field_717, (this->class_74::field_1042 + 2), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + (this->method_698() / 2)) + 1), 6);
        if (class_58::method_523(var3->field_714) > (((this->class_74::field_1029 - 18) - 10) - this->class_74::field_1035)) {
            jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var4{};
            class_58::method_518((var4 = class_58::method_532(var3->field_714, (((this->class_74::field_1029 - 18) - 10) - this->class_74::field_1035)))->at(0), ((this->class_74::field_1042 + 18) + 5), (this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)), ((this->class_74::field_1039 == var2) ? 0 : 1));
            class_58::method_518(var4->at(1), ((this->class_74::field_1042 + 18) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 10), ((this->class_74::field_1039 == var2) ? 0 : 1));
        } else {
            class_58::method_518(var3->field_714, ((this->class_74::field_1042 + 18) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 3), ((this->class_74::field_1039 == var2) ? 0 : 1));
        }
    } else {
        if (!var3->field_713) {
            class_58::method_516(var3->field_714, (this->class_74::field_1042 + (this->class_74::field_1029 / 2)), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 3), 1, 24);
        }
    }
}

void class_79::method_718() {
    this->registerRows();
    this->method_710();
    class_67::method_591(this->class_74::field_1050, this->class_74::field_1027, this->class_74::field_1028, this->class_74::field_1029, this->class_74::field_1030);
    this->method_720();
    this->method_709();
}

int32_t class_79::method_698() {
    return 18;
}

void class_79::__dumpFields(jrt::Dumper& d) {
    class_76::__dumpFields(d);
}

