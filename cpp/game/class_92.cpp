// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_92::__clinit() {
}

void class_92::__init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7) {
    class_91::__init(var1, var2, var3, var4, var5, var6, var7);
    this->field_1243 = var5;
    this->field_1244 = var6 + 3000;
    this->field_1245 = var7;
    this->method_810();
    var4->method_845(var5, class_84::field_1123->nextInt(75000), var7);
    var4->method_869(8192, 8192, 8192);
    var4->method_864((-1024), 0, 0);
}

void class_92::method_810() {
    this->class_91::field_1224 = int16_t(0);
    this->method_795(true);
    this->class_91::field_1226->method_845(this->field_1243, this->field_1244, this->field_1245);
    this->field_1242 = 0;
    this->class_91::field_1225->method_327(this->class_91::field_1225->field_364);
}

void class_92::method_805(int64_t var1) {
    this->field_1241 = int32_t(var1);
    if (((this->class_91::field_1225->field_363 <= 0) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
        this->class_91::field_1229->method_261();
        this->class_91::field_1225->field_375 = false;
        this->class_91::field_1224 = int16_t(3);
        if (this->class_91::field_1231 != nullptr) {
            this->class_91::field_1233 = this->class_91::field_1226->method_849(this->class_91::field_1233);
            this->class_91::field_1231->method_741(this->class_91::field_1233->field_37, this->class_91::field_1233->field_38, this->class_91::field_1233->field_39);
        }
    }
    {
        switch (int32_t(this->class_91::field_1224)) {
        case 0:
            this->class_91::field_1226->method_843(0, (this->field_1241 + (this->field_1242++)), 0);
            if (this->class_91::field_1226->method_853() > 75000) {
                this->method_810();
                return;
            }
        case 1:
            ;
        case 2:
            ;
        default:
            break;
        case 3:
            if (this->class_91::field_1231 == nullptr) {
                this->class_91::field_1224 = int16_t(4);
                return;
            }
            if (this->class_91::field_1231->method_743()) {
                this->class_91::field_1224 = int16_t(4);
                return;
            }
            break;
        case 4:
            this->method_810();
        }
    }
}

void class_92::method_809() {
    if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
        class_91::method_809();
    }
    if ((int32_t(this->class_91::field_1224) == 3) && (this->class_91::field_1231 != nullptr)) {
        this->class_91::field_1231->method_742(int64_t(this->field_1241));
    }
}

bool class_92::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_92::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1241", this->field_1241);
    d.f("field_1242", this->field_1242);
    d.f("field_1243", this->field_1243);
    d.f("field_1244", this->field_1244);
    d.f("field_1245", this->field_1245);
}

