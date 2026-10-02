// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_97::__clinit() {
}

void class_97::__init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_18> var4) {
    class_91::__init(0, false, jrt::New<class_37>(2000.0f, 0, 0), jrt::Ref<class_108>(nullptr), var1, var2, var3);
    this->class_91::field_1230 = var4;
    this->class_91::field_1225->field_375 = false;
    this->field_1295 = var1;
    this->field_1296 = var2;
    this->field_1297 = var3;
    this->class_91::field_1234 = var1;
    this->class_91::field_1234 = var2;
    this->class_91::field_1236 = var3;
    this->field_1298 = false;
}

jrt::Ref<class_3> class_97::method_799(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_1295;
    var1->field_38 = this->field_1296;
    var1->field_39 = this->field_1297;
    return var1;
}

void class_97::method_795(bool var1) {
    this->class_91::field_1225->field_375 = var1;
}

void class_97::method_819() {
    this->field_1298 = true;
}

void class_97::method_820() {
    this->field_1298 = false;
    this->class_91::field_1225->field_375 = false;
}

void class_97::method_805(int64_t var1) {
}

void class_97::method_809() {
}

bool class_97::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_97::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1295", this->field_1295);
    d.f("field_1296", this->field_1296);
    d.f("field_1297", this->field_1297);
    d.f("field_1298", this->field_1298);
}

