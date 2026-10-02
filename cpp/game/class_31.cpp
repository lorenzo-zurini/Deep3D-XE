// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_31::__clinit() {
}

void class_31::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9) {
    class_29::__init(var1, var2, var3, var4, var5, var6);
    this->field_317 = var7 / 2;
    this->field_318 = var8 / 2;
    this->field_319 = var9 / 2;
}

bool class_31::method_287(int32_t var1, int32_t var2, int32_t var3) {
    return this->method_288(var1, var2, var3) ? class_29::method_287(var1, var2, var3) : false;
}

bool class_31::method_288(int32_t var1, int32_t var2, int32_t var3) {
    return (((((var1 > ((this->class_29::field_307 + this->class_29::field_310) - this->field_317)) && (var1 < ((this->class_29::field_307 + this->class_29::field_310) + this->field_317))) && (var2 > ((this->class_29::field_308 + this->class_29::field_311) - this->field_318))) && (var2 < ((this->class_29::field_308 + this->class_29::field_311) + this->field_318))) && (var3 > ((this->class_29::field_309 + this->class_29::field_312) - this->field_319))) && (var3 < ((this->class_29::field_309 + this->class_29::field_312) + this->field_319));
}

void class_31::method_286(int32_t var1, int32_t var2, int32_t var3) {
    class_29::method_286(var1, var2, var3);
}

void class_31::__dumpFields(jrt::Dumper& d) {
    class_29::__dumpFields(d);
    d.f("field_317", this->field_317);
    d.f("field_318", this->field_318);
    d.f("field_319", this->field_319);
}

