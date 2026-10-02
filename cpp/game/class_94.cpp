// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_94::__clinit() {
}

void class_94::__init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7) {
    class_91::__init(var1, var2, var3, var4, var5, var6, var7);
    this->class_91::field_1225->field_377 = var4->field_1341;
    int32_t var8 = 4096 + class_84::field_1123->nextInt(8096);
    var4->method_869(var8, var8, var8);
}

void class_94::method_805(int64_t var1) {
    this->field_1252 = var1;
    if (((this->class_91::field_1225->field_363 <= 0) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
        this->class_91::field_1225->field_375 = false;
        this->class_91::field_1229->method_258();
        this->class_91::field_1224 = int16_t(3);
        if (this->class_91::field_1231 != nullptr) {
            this->class_91::field_1233 = this->class_91::field_1226->method_849(this->class_91::field_1233);
            this->class_91::field_1231->method_741(this->class_91::field_1233->field_37, this->class_91::field_1233->field_38, this->class_91::field_1233->field_39);
        }
    }
    {
        switch (int32_t(this->class_91::field_1224)) {
        case 3:
            if (this->class_91::field_1231 != nullptr) {
                if (this->class_91::field_1231->method_743()) {
                    this->class_91::field_1224 = int16_t(4);
                    return;
                }
            } else {
                this->class_91::field_1224 = int16_t(4);
            }
        case 4:
            ;
        }
    }
}

void class_94::method_809() {
    if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
        class_91::method_809();
    }
    if ((int32_t(this->class_91::field_1224) == 3) && (this->class_91::field_1231 != nullptr)) {
        this->class_91::field_1231->method_742(this->field_1252);
    }
}

bool class_94::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_94::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1252", this->field_1252);
}

