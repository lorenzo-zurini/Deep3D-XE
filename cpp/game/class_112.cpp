// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_112::field_1412{};

void class_112::__clinit() {
}

void class_112::__init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, int32_t var3) {
    class_108::__init();
    this->field_1409 = var1;
    class_112::field_1412 = jrt::New<class_3>();
    if (var2 == nullptr) {
        this->field_1410 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    } else {
        this->field_1410 = jrt::newArray<jrt::Ref<class_108>>(var1->field_78->length);
        for (int32_t var4 = 0; var4 < this->field_1410->length; var4++) {
            this->field_1410->at(var4) = jrt::cast<class_108>(var2->method_840());
            this->field_1410->at(var4)->field_1367 = 2;
        }
    }
}

void class_112::method_894() {
    this->field_1409->method_43();
    this->field_1409 = jrt::Ref<class_9>(nullptr);
}

void class_112::method_887() {
    this->field_1409->method_50();
    if (this->field_1409->field_92 && (this->field_1410 != nullptr)) {
        int32_t var1 = 0;
        for (int32_t var2 = 0; var2 < this->field_1409->field_78->length; var2++) {
            if (this->field_1409->field_78->at(var2)->field_37 != 50000) {
                this->field_1410->at(var2)->method_846(this->field_1409->field_78->at(var2));
                class_112::field_1412->method_9(this->field_1409->field_79->at(var2));
                class_112::field_1412->method_22();
                this->field_1410->at(var2)->field_1341->method_512(class_112::field_1412);
                class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1410->at(var2)));
            } else {
                var1++;
            }
        }
        if (var1 >= this->field_1409->field_83->length) {
            this->field_1409->field_92 = false;
        }
    }
}

void class_112::method_895(int64_t var1) {
    this->field_1409->method_49(var1);
}

jrt::Ref<class_102> class_112::method_840() {
    return jrt::Ref<class_102>(nullptr);
}

void class_112::method_893(jrt::Ref<class_44> var1) {
}

void class_112::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1409", this->field_1409);
    d.f("field_1410", this->field_1410);
    d.f("field_1411", this->field_1411);
}

