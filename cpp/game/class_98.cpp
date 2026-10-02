// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_98::field_1299{};

void class_98::__clinit() {
    class_98::field_1299 = jrt::New<class_3>();
}

void class_98::__init(int32_t var1, jrt::Ref<class_108> var2, int32_t var3, int32_t var4, int32_t var5) {
    class_91::__init(var1, false, jrt::New<class_37>(2000.0f, 0, 0), var2, var3, var4, var5);
    this->field_1300 = var3;
    this->field_1301 = var4;
    this->field_1302 = var5;
}

void class_98::method_805(int64_t var1) {
}

jrt::Ref<class_3> class_98::method_799(jrt::Ref<class_3> var1) {
    var1->method_10(this->field_1300, this->field_1301, this->field_1302);
    return var1;
}

void class_98::method_809() {
    class_4::deep3dKind = 1;
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_91::field_1226));
    class_4::deep3dKind = 0;
}

bool class_98::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_98::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1300", this->field_1300);
    d.f("field_1301", this->field_1301);
    d.f("field_1302", this->field_1302);
}

