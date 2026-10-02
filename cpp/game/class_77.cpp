// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_77::__clinit() {
}

void class_77::__init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2) {
    class_76::__init(var1, var2);
    this->class_76::field_1052 = 18;
    this->field_1057 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(5);
    for (int32_t var3 = 0; var3 < (this->field_1057->length - 2); var3++) {
        this->field_1057->at(var3) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/medal_"), (var3 + 1), JRT_LIT(u".png")));
    }
    int32_t var8 = (class_21::method_180()->method_752()) ? 4 : 6;
    this->field_1057->at(3) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/medal_"), var8, JRT_LIT(u".png")));
    this->field_1057->at(4) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/medal_"), (var8 + 1), JRT_LIT(u".png")));
    jrt::Ref<jrt::Array<int32_t>> var4 = class_14::method_71();
    int32_t var5 = 0;
    if (var4 != nullptr) {
        for (int32_t var6 = 0; var6 < var4->length; var6++) {
            if (var4->at(var6) > 0) {
                var5++;
            }
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var9 = jrt::newArray<jrt::Ref<class_59>>(var4->length);
        for (int32_t var7 = 0; var7 < var4->length; var7++) {
            var9->at(var7) = jrt::New<class_59>(var7, var4->at(var7));
        }
        class_76::method_700(1, jrt::arrayView<jrt::Ref<java::lang::Object>>(var9));
    }
    this->class_76::field_1055 = jrt::concat(class_84::field_1116->method_4(63), JRT_LIT(u": "), var5, JRT_LIT(u"/"), class_14::field_135->length);
}

void class_77::method_718() {
    class_76::method_718();
    this->method_719();
}

void class_77::method_719() {
    class_84::field_1117->setColor(class_67::field_846);
    class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    class_58::method_516(this->class_76::field_1055, (class_84::field_1120 / 2), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), 0, 24);
}

void class_77::method_721(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    jrt::Ref<class_59> var3 = jrt::cast<class_59>(var1);
    if (var2 == this->class_74::field_1039) {
        class_84::field_1117->fillRect(((this->class_74::field_1042 + this->class_76::field_1052) + 4), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 4) - 4) - this->class_74::field_1035), (this->class_74::field_1044 - 1));
    }
    jrt::Ref<java::lang::Object> var4 = jrt::Ref<java::lang::Object>(nullptr);
    if (var3->field_715 == 0) {
        var4 = (this->class_74::field_1039 == var2) ? jrt::Ref<java::lang::Object>(this->field_1057->at(3)) : jrt::Ref<java::lang::Object>(this->field_1057->at(4));
    } else {
        var4 = jrt::Ref<java::lang::Object>(this->field_1057->at((var3->field_715 - 1)));
    }
    class_84::field_1117->drawImage(jrt::cast<javax::microedition::lcdui::Image>(var4), (this->class_74::field_1042 + 4), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + (this->method_698() / 2)) + 1), 6);
    class_67::method_598(class_84::field_1116->method_4(int32_t(class_1::field_0->at(var3->field_716)->at(0))), ((this->class_74::field_1042 + this->class_76::field_1052) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 4) - 4) - this->class_74::field_1035) - 2), ((this->class_74::field_1039 == var2) ? 0 : 1));
}

void class_77::__dumpFields(jrt::Dumper& d) {
    class_76::__dumpFields(d);
    d.f("field_1057", this->field_1057);
}

