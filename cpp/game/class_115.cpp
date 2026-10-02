// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_115::__clinit() {
}

void class_115::__init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, jrt::Ref<class_108> var3, int32_t var4) {
    class_114::__init(var1, jrt::Ref<class_108>(nullptr), var3, (-1), var4, (-1));
    this->field_1434 = jrt::New<class_3>();
}

jrt::Ref<class_3> class_115::method_906(jrt::Ref<class_3> var1) {
    this->field_1434->method_9(this->class_112::field_1409->field_79->at(0));
    bool var2 = false;
    this->field_1434->field_37 *= (-2);
    this->field_1434->field_38 *= (-2);
    this->field_1434->field_39 *= (-2);
    var1->method_9(this->class_112::field_1409->field_78->at(0));
    var1->method_15(this->field_1434);
    return var1;
}

void class_115::method_895(int64_t var1) {
    this->class_112::field_1409->method_49(var1);
    this->method_907();
}

void class_115::__dumpFields(jrt::Dumper& d) {
    class_114::__dumpFields(d);
    d.f("field_1434", this->field_1434);
}

