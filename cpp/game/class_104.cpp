// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_104::__clinit() {
}

void class_104::__init() {
    class_103::__init();
    this->field_1346 = jrt::Ref<jrt::Array<jrt::Ref<class_0>>>(nullptr);
}

void class_104::method_880(jrt::Ref<class_0> var1) {
    if (this->field_1346 == nullptr) {
        this->field_1346 = jrt::newArray<jrt::Ref<class_0>>(1);
        this->field_1346->at(0) = var1;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_0>>> var2 = jrt::newArray<jrt::Ref<class_0>>((this->field_1346->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1346), 0, jrt::Ref<java::lang::Object>(var2), 0, this->field_1346->length);
        var2->at(this->field_1346->length) = var1;
        this->field_1346 = var2;
    }
}

void class_104::method_839(bool var1) {
    if (this->field_1346 != nullptr) {
        if (this->class_102::field_1340 || var1) {
            if (this->class_102::field_1339 || var1) {
                if (this->class_102::field_1336 != nullptr) {
                    this->class_102::field_1342 = this->class_102::field_1336->field_1342->method_473(this->class_102::field_1341, this->class_102::field_1342);
                } else {
                    this->class_102::field_1342->method_470(this->class_102::field_1341);
                }
            }
            for (jrt::Ref<class_102> var2 = this->class_103::field_1345; var2 != nullptr; var2 = var2->field_1337) {
                var2->method_839((this->class_102::field_1339 || var1));
            }
            this->class_102::field_1343->method_89(this->class_102::field_1342->field_698, this->class_102::field_1342->field_699, this->class_102::field_1342->field_700, 0);
            for (jrt::Ref<class_102> var3 = this->class_103::field_1345; var3 != nullptr; var3 = var3->field_1337) {
                this->class_102::field_1343->method_87(var3->field_1343);
            }
            this->class_102::field_1340 = false;
            this->class_102::field_1339 = false;
        }
        for (int32_t var4 = this->field_1346->length - 1; var4 >= 0; var4--) {
            if (this->field_1346->at(var4)->method_1()) {
                this->field_1346->at(var4)->method_0();
            }
        }
    }
    if (this->class_102::field_1340 || var1) {
        if (this->class_102::field_1339 || var1) {
            if (this->class_102::field_1336 != nullptr) {
                this->class_102::field_1342 = this->class_102::field_1336->field_1342->method_473(this->class_102::field_1341, this->class_102::field_1342);
            } else {
                this->class_102::field_1342->method_470(this->class_102::field_1341);
            }
        }
        for (jrt::Ref<class_102> var5 = this->class_103::field_1345; var5 != nullptr; var5 = var5->field_1337) {
            var5->method_839((this->class_102::field_1339 || var1));
        }
        this->class_102::field_1343->method_89(this->class_102::field_1342->field_698, this->class_102::field_1342->field_699, this->class_102::field_1342->field_700, 0);
        for (jrt::Ref<class_102> var6 = this->class_103::field_1345; var6 != nullptr; var6 = var6->field_1337) {
            this->class_102::field_1343->method_87(var6->field_1343);
        }
        this->class_102::field_1340 = false;
        this->class_102::field_1339 = false;
    }
}

void class_104::__dumpFields(jrt::Dumper& d) {
    class_103::__dumpFields(d);
    d.f("field_1346", this->field_1346);
}

