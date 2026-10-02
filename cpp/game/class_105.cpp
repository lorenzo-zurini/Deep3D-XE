// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_105::field_1347{};

void class_105::__clinit() {
    class_105::field_1347 = jrt::New<class_3>();
}

void class_105::__init() {
    class_102::__init();
    this->field_1348 = 0;
}

void class_105::__init(jrt::Ref<class_105> var1) {
    class_102::__init(jrt::Ref<class_102>(var1));
    this->field_1348 = 0;
    this->field_1348 = var1->field_1348;
}

void class_105::method_839(bool var1) {
    if (this->class_102::field_1339 || var1) {
        if (this->class_102::field_1336 != nullptr) {
            this->class_102::field_1342 = this->class_102::field_1336->field_1342->method_473(this->class_102::field_1341, this->class_102::field_1342);
        } else {
            this->class_102::field_1342->method_470(this->class_102::field_1341);
        }
        class_105::field_1347 = this->class_102::field_1342->method_502(class_105::field_1347);
        int32_t var2 = (class_16::method_97(class_16::method_97(class_16::method_100(class_105::field_1347->field_37), class_16::method_100(class_105::field_1347->field_38)), class_16::method_100(class_105::field_1347->field_39)) * this->field_1348) >> 12;
        class_105::field_1347 = this->class_102::field_1342->method_479(class_105::field_1347);
        this->class_102::field_1343->method_89(class_105::field_1347->field_37, class_105::field_1347->field_38, class_105::field_1347->field_39, var2);
        this->class_102::field_1339 = false;
        this->class_102::field_1340 = false;
    }
}

jrt::Ref<java::lang::String> class_105::method_842(jrt::Ref<java::lang::String> var1, int32_t var2) {
    for (int32_t var3 = 0; var3 < var2; var3++) {
        var1 = jrt::concat(var1, JRT_LIT(u"  "));
    }
    return jrt::concat(var1, JRT_LIT(u"\n"));
}

void class_105::__dumpFields(jrt::Dumper& d) {
    class_102::__dumpFields(d);
    d.f("field_1348", this->field_1348);
}

