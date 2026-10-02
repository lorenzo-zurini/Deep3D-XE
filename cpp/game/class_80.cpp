// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_80::__clinit() {
}

void class_80::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    class_79::__init();
    this->method_697(var1, var2, var3, var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr), class_84::field_1116->method_4(266));
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var5 = class_21::method_178()->field_886;
    jrt::Ref<java::lang::Object> var6 = jrt::Ref<java::lang::Object>(nullptr);
    if (var5 == nullptr) {
        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>((var6 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_59>>(1)))))->at(0) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(class_84::field_1116->method_4(30)));
    } else {
        var6 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_59>>(var5->length));
        for (int32_t var7 = 0; var7 < var5->length; var7++) {
            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var6))->at(var7) = jrt::Ref<java::lang::Object>(([&]() { jrt::Ref<javax::microedition::lcdui::Image> __a1 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var5->at(var7)->field_1480, JRT_LIT(u".png"))); int32_t __a2 = var5->at(var7)->field_1480; jrt::Ref<java::lang::String> __a3 = jrt::concat(var5->at(var7)->field_1490, JRT_LIT(u"x "), class_84::field_1116->method_4(int32_t(class_1::field_7->at(var5->at(var7)->field_1480)->at(0)))); jrt::Ref<class_59> __o(new class_59()); __o->__init(__a1, __a2, __a3); return __o; }()));
        }
    }
    this->method_700(0, jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var6));
    this->method_703();
}

void class_80::method_729() {
    class_58::method_516(jrt::concat(class_84::field_1116->method_4(60), JRT_LIT(u":"), class_21::method_178()->field_867, JRT_LIT(u"/"), class_21::method_178()->method_607()), (this->class_74::field_1027 + (this->class_74::field_1029 / 2)), ((this->class_74::field_1028 + this->class_74::field_1030) - 16), 0, 24);
}

void class_80::__dumpFields(jrt::Dumper& d) {
    class_79::__dumpFields(d);
}

