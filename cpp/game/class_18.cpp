// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_18::__clinit() {
}

void class_18::__init(jrt::Ref<jrt::Array<int32_t>> var1) {
    this->field_164 = 0;
    this->field_163 = false;
    this->field_162 = jrt::newArray<jrt::Ref<class_97>>((var1->length / 3));
    for (int32_t var2 = 0; var2 < var1->length; var2 += 3) {
        this->field_162->at((var2 / 3)) = jrt::New<class_97>(var1->at(var2), var1->at((var2 + 1)), var1->at((var2 + 2)), jrt::Ref<class_18>(this));
    }
}

void class_18::method_108() {
    this->field_162 = jrt::Ref<jrt::Array<jrt::Ref<class_97>>>(nullptr);
}

jrt::Ref<class_97> class_18::method_109(int32_t var1) {
    return (var1 < this->field_162->length) ? this->field_162->at(var1) : jrt::Ref<class_97>(nullptr);
}

jrt::Ref<class_97> class_18::method_110() {
    return (this->field_164 < this->field_162->length) ? this->field_162->at(this->field_164) : jrt::Ref<class_97>(nullptr);
}

jrt::Ref<class_97> class_18::method_111() {
    return this->field_162->at((this->field_162->length - 1));
}

void class_18::method_112(int32_t var1) {
    if (this->field_164 < (this->field_162->length - 1)) {
        this->field_164 = var1 + 1;
    }
    this->field_162->at(var1)->method_795(false);
    this->field_162->at(var1)->method_819();
}

int32_t class_18::method_113() {
    return this->field_162->length;
}

void class_18::method_114(int32_t var1, int32_t var2, int32_t var3) {
    if (((((((this->field_164 < this->field_162->length) && ((var1 - this->field_162->at(this->field_164)->field_1295) < 2000)) && ((var1 - this->field_162->at(this->field_164)->field_1295) > (-2000))) && ((var2 - this->field_162->at(this->field_164)->field_1296) < 2000)) && ((var2 - this->field_162->at(this->field_164)->field_1296) > (-2000))) && ((var3 - this->field_162->at(this->field_164)->field_1297) < 2000)) && ((var3 - this->field_162->at(this->field_164)->field_1297) > (-2000))) {
        this->field_162->at(this->field_164)->method_795(false);
        this->field_162->at(this->field_164)->method_819();
        this->field_164++;
        if (this->field_163 && (this->field_164 > (this->field_162->length - 1))) {
            this->field_164 = 0;
            for (int32_t var4 = 0; var4 < this->field_162->length; var4++) {
                this->field_162->at(var4)->method_820();
            }
        }
        if (this->field_164 < this->field_162->length) {
            this->field_162->at(this->field_164)->method_795(true);
        }
    }
}

jrt::Ref<class_18> class_18::method_115() {
    jrt::Ref<jrt::Array<int32_t>> var1 = jrt::newArray<int32_t>((this->field_162->length * 3));
    for (int32_t var2 = 0; var2 < this->field_162->length; var2++) {
        var1->at((3 * var2)) = this->field_162->at(var2)->field_1295;
        var1->at(((3 * var2) + 1)) = this->field_162->at(var2)->field_1296;
        var1->at(((3 * var2) + 2)) = this->field_162->at(var2)->field_1297;
    }
    jrt::Ref<class_18> var3{};
    [&]() -> bool& { auto& __l = (var3 = jrt::New<class_18>(var1))->field_163; __l = this->field_163; return __l; }();
    return var3;
}

void class_18::__dumpFields(jrt::Dumper& d) {
    d.f("field_162", this->field_162);
    d.f("field_163", this->field_163);
    d.f("field_164", this->field_164);
}

