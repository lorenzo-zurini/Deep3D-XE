// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_25::__clinit() {
}

void class_25::__init() {
    jrt::New<class_3>();
    jrt::New<class_3>();
    this->field_257 = jrt::newArray<int32_t>(20);
    this->field_258 = jrt::newArray<int32_t>(20);
    this->field_255 = jrt::newArray<int32_t>(60);
    this->field_256 = jrt::newArray<int32_t>(20);
    this->field_261 = class_108::method_890(0, 128, 32, 0, 64, 32, 120, 20, int8_t(2));
    this->field_261->method_893(class_43::method_380(2));
    this->field_261->field_1367 = 2;
    this->field_255 = (jrt::cast<class_110>(this->field_261))->field_1389;
    for (int32_t var1 = 0; var1 < this->field_255->length; var1++) {
        this->field_255->at(var1) = 100000;
    }
}

void class_25::method_235() {
    this->field_261->method_894();
    this->field_261 = jrt::Ref<class_108>(nullptr);
    this->field_255 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

void class_25::method_236(jrt::Ref<class_3> var1, int32_t var2) {
    this->method_237(var1->field_37, var1->field_38, var1->field_39, var2);
}

void class_25::method_237(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_260 += var4;
    this->field_255 = (jrt::cast<class_110>(this->field_261))->field_1389;
    bool var5 = false;
    for (int32_t var6 = 0; var6 < this->field_255->length; var6 += 3) {
        this->field_259 = var6 / 3;
        if (((this->field_256->at(this->field_259) <= 0) && (!var5)) && (this->field_260 > 100)) {
            this->field_260 = 0;
            this->field_258->at(this->field_259) = 4096;
            this->field_255->at(var6) = var1;
            this->field_255->at((var6 + 1)) = var2;
            this->field_255->at((var6 + 2)) = var3;
            this->field_256->at(this->field_259) = 2000;
            this->field_257->at(this->field_259) = 10 + class_84::field_1123->nextInt(40);
            var5 = true;
        } else {
            this->field_256->at(this->field_259) = this->field_256->at(this->field_259) - var4;
            this->field_255->at((var6 + 1)) = this->field_255->at((var6 + 1)) + org::deep3d::Step::share(this->field_257->at(this->field_259), this->deep3dRise[this->field_259]);   // Deep3D-PC
            this->field_258->at(this->field_259) = jrt::f2i(((float(this->field_256->at(this->field_259)) / 2000.0f) * 4096.0f));
        }
    }
}

void class_25::method_238() {
    int32_t deep3dWas = class_4::deep3dKind;
    if (org::deep3d::Remaster::on()) class_4::deep3dKind = 7;   // Deep3D-PC: bubbles (lit by the water they are in, not glowing)
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_261));
    class_4::deep3dKind = deep3dWas;
}

void class_25::__dumpFields(jrt::Dumper& d) {
    d.f("field_255", this->field_255);
    d.f("field_256", this->field_256);
    d.f("field_257", this->field_257);
    d.f("field_258", this->field_258);
    d.f("field_259", this->field_259);
    d.f("field_260", this->field_260);
    d.f("field_261", this->field_261);
}

