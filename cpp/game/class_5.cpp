// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_5::field_49{};
jrt::Ref<class_3> class_5::field_50{};
jrt::Ref<class_3> class_5::field_51{};

void class_5::__clinit() {
}

void class_5::__init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2) {
    this->__init(var1, var2, jrt::Ref<class_3>(nullptr), 0);
}

void class_5::__init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2, jrt::Ref<class_3> var3, int32_t var4) {
    this->field_45 = var1;
    this->field_48 = var2;
    this->field_47 = var4;
    this->field_53 = true;
    this->field_52 = var3;
    if (class_5::field_49 == nullptr) {
        class_5::field_49 = jrt::New<class_3>();
    }
    if (class_5::field_50 == nullptr) {
        class_5::field_50 = jrt::New<class_3>();
    }
    if (class_5::field_51 == nullptr) {
        class_5::field_51 = jrt::New<class_3>();
    }
    if (var3 != nullptr) {
        this->field_52->method_22();
    }
    this->field_46 = var1;
    while (this->field_46->field_1336 != nullptr) {
        this->field_46 = jrt::Ref<class_102>(this->field_46->field_1336);
    }
    jrt::Ref<java::lang::Object> var5 = jrt::Ref<java::lang::Object>(var2);
    while ((jrt::cast<class_102>(var5))->field_1336 != nullptr) {
        var5 = jrt::Ref<java::lang::Object>((jrt::cast<class_102>(var5))->field_1336);
    }
    if (var5 == this->field_46) {
        this->field_46 = jrt::Ref<class_102>(nullptr);
    }
}

void class_5::method_31(jrt::Ref<class_3> var1, int32_t var2) {
    this->field_52 = var1;
    this->field_47 = var2;
    if (var1 != nullptr) {
        this->field_52->method_22();
    }
}

void class_5::method_0() {
    if (this->field_53) {
        if (this->field_46 != nullptr) {
            this->field_46->method_839(false);
        }
        class_5::field_49 = this->field_45->method_849(class_5::field_49);
        class_5::field_49 = this->field_48->field_1336->field_1342->method_511(class_5::field_49);
        class_5::field_50 = this->field_48->method_848(class_5::field_50);
        class_5::field_50->method_17(class_5::field_49);
        class_5::field_50->method_22();
        if (this->field_52 != nullptr) {
            class_5::field_51->method_9(this->field_52);
        } else {
            class_5::field_51->method_10(0, 4096, 0);
        }
        class_5::field_49 = class_5::field_51->method_13(class_5::field_50, class_5::field_49);
        class_5::field_49->method_22();
        if (class_16::method_100(((class_5::field_49->field_37 + class_5::field_49->field_38) + class_5::field_49->field_39)) < 4) {
            class_5::field_51->method_10(4096, 0, 0);
            class_5::field_49 = class_5::field_51->method_13(class_5::field_50, class_5::field_49);
            class_5::field_49->method_22();
        }
        {
            switch (this->field_47) {
            case 0:
                ;
            case 2:
                class_5::field_51 = class_5::field_50->method_13(class_5::field_49, class_5::field_51);
                break;
            case 1:
                class_5::field_50 = class_5::field_49->method_13(class_5::field_51, class_5::field_50);
            }
        }
        this->field_48->method_872(class_5::field_49, class_5::field_51, class_5::field_50);
    }
}

bool class_5::method_1() {
    return this->field_53;
}

void class_5::__dumpFields(jrt::Dumper& d) {
    d.f("field_45", this->field_45);
    d.f("field_46", this->field_46);
    d.f("field_47", this->field_47);
    d.f("field_48", this->field_48);
    d.f("field_52", this->field_52);
    d.f("field_53", this->field_53);
}

