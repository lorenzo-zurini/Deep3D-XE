// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_113::field_1415{};
jrt::Ref<class_3> class_113::field_1416{};
jrt::Ref<class_3> class_113::field_1417{};
int32_t class_113::field_1418{};
int32_t class_113::field_1419{};
int32_t class_113::field_1420{};

void class_113::__clinit() {
    class_113::field_1417 = jrt::New<class_3>();
}

void class_113::__init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, int32_t var3, bool var4) {
    class_112::__init(var1, jrt::Ref<class_108>(nullptr), 1000);
    jrt::New<class_57>();
    this->field_1413 = jrt::New<class_25>();
    this->field_1414 = jrt::New<class_83>();
    this->class_112::field_1411 = var2;
    this->class_112::field_1411->method_869(8192, 8192, 8192);
    this->field_1421 = var4;
    class_113::field_1415 = jrt::New<class_3>();
}

void class_113::method_894() {
    class_112::method_894();
    if (this->field_1413 != nullptr) {
        this->field_1413->method_235();
    }
    this->field_1413 = jrt::Ref<class_25>(nullptr);
    if (this->field_1414 != nullptr) {
        this->field_1414->method_731();
    }
    this->field_1414 = jrt::Ref<class_83>(nullptr);
}

void class_113::method_887() {
    this->class_112::field_1409->method_50();
    if (this->class_112::field_1409->field_92) {
        this->field_1414->method_735();
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_112::field_1411));
    }
    this->field_1413->method_238();
}

void class_113::method_895(int64_t var1) {
    this->class_112::field_1409->method_49(var1);
    class_113::field_1415->method_9(this->class_112::field_1409->field_78->at(0));
    if (this->class_112::field_1409->field_88) {
        this->field_1414->method_734(class_113::field_1415);
        this->class_112::field_1409->field_88 = false;
    }
    this->class_112::field_1411->method_846(class_113::field_1415);
    class_112::field_1412->method_9(this->class_112::field_1409->field_79->at(0));
    class_112::field_1412->method_22();
    this->class_112::field_1411->field_1341->method_512(class_112::field_1412);
    if (this->class_112::field_1409->field_92) {
        if (this->field_1421 && (this->class_112::field_1409->field_83->at(0) < (this->class_112::field_1409->field_86 - 1500))) {
            this->method_904(var1);
        }
        class_113::field_1415->method_9(this->class_112::field_1409->field_78->at(0));
        this->field_1413->method_236(class_113::field_1415, (int32_t(var1) / 4));
        this->field_1414->method_733(class_113::field_1415);
        if (class_113::field_1415->field_39 == 50000) {
            this->class_112::field_1409->field_92 = false;
        }
    }
}

void class_113::method_904(int64_t var1) {
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var3 = this->class_112::field_1409->field_77;
    if (this->class_112::field_1409->field_77 != nullptr) {
        int32_t var4 = -1;
        int32_t var5 = 2147483647;
        for (int32_t var6 = 0; var6 < var3->length; var6++) {
            if ((var3->at(var6)->field_375 && (!var3->at(var6)->method_345())) && (!var3->at(var6)->method_321())) {
                class_113::field_1416 = this->class_112::field_1409->field_78->at(0);
                class_113::field_1415 = var3->at(var6)->method_344(class_113::field_1415);
                class_113::field_1418 = class_113::field_1416->field_37 - class_113::field_1415->field_37;
                class_113::field_1419 = class_113::field_1416->field_38 - class_113::field_1415->field_38;
                class_113::field_1420 = class_113::field_1416->field_39 - class_113::field_1415->field_39;
                int32_t var7{};
                if (((((((class_113::field_1418 < 15000) && (class_113::field_1418 > (-15000))) && (class_113::field_1419 < 15000)) && (class_113::field_1419 > (-15000))) && (class_113::field_1420 < 15000)) && (class_113::field_1420 > (-15000))) && ((var7 = ((class_113::field_1418 * class_113::field_1418) + (class_113::field_1419 * class_113::field_1419)) + (class_113::field_1420 * class_113::field_1420)) < var5)) {
                    var4 = var6;
                    var5 = var7;
                }
            }
        }
        if (var4 < 0) {
            return;
        }
        class_113::field_1415 = var3->at(var4)->method_344(class_113::field_1415);
        class_112::field_1412->field_37 = class_113::field_1415->field_37 - this->class_112::field_1409->field_78->at(0)->field_37;
        class_112::field_1412->field_38 = class_113::field_1415->field_38 - this->class_112::field_1409->field_78->at(0)->field_38;
        class_112::field_1412->field_39 = class_113::field_1415->field_39 - this->class_112::field_1409->field_78->at(0)->field_39;
        class_113::field_1417->method_9(this->class_112::field_1409->field_79->at(0));
        class_112::field_1412->method_17(class_113::field_1417);
        class_112::field_1412->method_18(int32_t(var1));
        this->class_112::field_1409->field_79->at(0) = class_113::field_1417->method_14(class_112::field_1412, this->class_112::field_1409->field_79->at(0));
        this->class_112::field_1409->field_79->at(0)->method_22();
        this->class_112::field_1409->field_79->at(0)->method_18((jrt::f2i((this->class_112::field_1409->field_85 * float(var1))) << 12));
        this->class_112::field_1409->field_79->at(0)->field_37 >>= 12;
        this->class_112::field_1409->field_79->at(0)->field_38 >>= 12;
        this->class_112::field_1409->field_79->at(0)->field_39 >>= 12;
    }
}

void class_113::__dumpFields(jrt::Dumper& d) {
    class_112::__dumpFields(d);
    d.f("field_1413", this->field_1413);
    d.f("field_1414", this->field_1414);
    d.f("field_1421", this->field_1421);
}

