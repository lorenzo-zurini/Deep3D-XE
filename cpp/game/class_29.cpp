// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_29::field_306{};

void class_29::__clinit() {
    class_29::field_306 = jrt::New<class_3>();
}

void class_29::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6) {
    this->field_307 = var1;
    this->field_308 = var2;
    this->field_309 = var3;
    this->field_310 = var4;
    this->field_311 = var5;
    this->field_312 = var6;
}

jrt::Ref<class_3> class_29::method_285(jrt::Ref<class_3> var1) {
    class_29::field_306->method_10((var1->field_37 - this->field_307), (var1->field_38 - this->field_308), (var1->field_39 - this->field_309));
    class_29::field_306->method_22();
    return class_29::field_306;
}

void class_29::method_286(int32_t var1, int32_t var2, int32_t var3) {
    if (this->field_305 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_305->length; var4++) {
            this->field_305->at(var4)->method_286(var1, var2, var3);
        }
    }
    this->field_307 = var1;
    this->field_308 = var2;
    this->field_309 = var3;
}

bool class_29::method_287(int32_t var1, int32_t var2, int32_t var3) {
    if (this->field_305 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_305->length; var4++) {
            if (this->field_305->at(var4)->method_287(this->field_307, this->field_308, this->field_309)) {
                return true;
            }
        }
    }
    return false;
}

bool class_29::method_288(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_29::__dumpFields(jrt::Dumper& d) {
    d.f("field_305", this->field_305);
    d.f("field_307", this->field_307);
    d.f("field_308", this->field_308);
    d.f("field_309", this->field_309);
    d.f("field_310", this->field_310);
    d.f("field_311", this->field_311);
    d.f("field_312", this->field_312);
}

