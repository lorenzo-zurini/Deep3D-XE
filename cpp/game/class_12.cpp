// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_12::__clinit() {
}

void class_12::__init() {
    this->field_118 = jrt::New<class_23>(5, 12, (class_84::field_1120 - 10), (class_84::field_1121 - 30), JRT_LIT(u""));
    this->field_118->method_226(class_90::field_1206, JRT_LIT(u"M.A.I."), true);
}

void class_12::method_58(jrt::Ref<java::lang::String> var1) {
    this->field_118->method_225(var1);
    this->field_118->method_224();
}

bool class_12::method_59(int32_t var1) {
    return var1 != 131072;
}

bool class_12::method_60(int32_t var1, int32_t var2) {
    this->field_119 += var2;
    if (this->field_119 > 200) {
        if ((var1 & 2) != 0) {
            this->field_119 = 0;
            this->field_118->method_230(var2);
        }
        if ((var1 & 64) != 0) {
            this->field_119 = 0;
            this->field_118->method_229(var2);
        }
    }
    this->method_61();
    return true;
}

void class_12::method_61() {
    org::deep3d::GameUi::layer(2);
    org::deep3d::GameUi::controls(2, (-6), (-7), 0);
    class_67::method_587();
    class_67::method_588(class_84::field_1116->method_4(4));
    this->field_118->method_231();
    [&]() { jrt::Ref<java::lang::String> __a1 = jrt::concat(JRT_LIT(u"0: "), class_84::field_1116->method_4(65)); jrt::Ref<java::lang::String> __a2 = jrt::concat(JRT_LIT(u"0: "), class_84::field_1116->method_4(65)); bool __a3 = false; return class_67::method_601(__a1, __a2, __a3); }();
}

void class_12::__dumpFields(jrt::Dumper& d) {
    d.f("field_118", this->field_118);
    d.f("field_119", this->field_119);
}

