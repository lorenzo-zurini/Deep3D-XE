// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_30::__clinit() {
}

void class_30::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7) {
    class_29::__init(var1, var2, var3, var4, var5, var6);
    this->field_313 = var7;
    this->method_286(var1, var2, var3);
}

bool class_30::method_287(int32_t var1, int32_t var2, int32_t var3) {
    return this->method_288(var1, var2, var3) ? true : class_29::method_287(var1, var2, var3);
}

bool class_30::method_288(int32_t var1, int32_t var2, int32_t var3) {
    return ((((((var1 - this->field_314) < this->field_313) && ((var1 - this->field_314) > (-this->field_313))) && ((var2 - this->field_315) < this->field_313)) && ((var2 - this->field_315) > (-this->field_313))) && ((var3 - this->field_316) < this->field_313)) && ((var3 - this->field_316) > (-this->field_313));
}

void class_30::method_286(int32_t var1, int32_t var2, int32_t var3) {
    class_29::method_286(var1, var2, var3);
    this->field_314 = var1 + this->class_29::field_310;
    this->field_315 = var2 + this->class_29::field_311;
    this->field_316 = var3 + this->class_29::field_312;
}

void class_30::__dumpFields(jrt::Dumper& d) {
    class_29::__dumpFields(d);
    d.f("field_313", this->field_313);
    d.f("field_314", this->field_314);
    d.f("field_315", this->field_315);
    d.f("field_316", this->field_316);
}

