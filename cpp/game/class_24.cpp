// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_24::__clinit() {
}

void class_24::__init(int32_t var1, jrt::Ref<class_44> var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9, int32_t var10, int8_t var11) {
    this->field_253 = var8;
    this->field_252 = var9;
    this->field_254 = var10;
    this->field_251 = jrt::newArray<int32_t>(var1);
    this->field_250 = class_108::method_890(0, var3, var4, var5, var6, var7, var8, var1, var11);
    this->field_250->method_893(var2);
    jrt::Ref<class_110> var12{};
    jrt::Ref<jrt::Array<int32_t>> var13 = (var12 = jrt::cast<class_110>(this->field_250))->field_1389;
    jrt::Ref<jrt::Array<int32_t>> var14 = var12->method_897();
    jrt::Ref<java::util::Random> var15 = org::deep3d::Det::random(2);
    for (int32_t var16 = 0; var16 < var1; var16++) {
        var13->at((3 * var16)) = var15->nextInt((var8 >> 1)) - (var8 >> 2);
        var13->at(((3 * var16) + 1)) = var15->nextInt((var8 >> 1)) - (var8 >> 2);
        var13->at(((3 * var16) + 2)) = var15->nextInt((var8 >> 1)) - (var8 >> 2);
        var14->at(var16) = 0;
        this->field_251->at(var16) = (var15->nextInt(var10) - (var10 >> 1)) + this->field_252;
    }
}

void class_24::method_232() {
    if (this->field_250 != nullptr) {
        this->field_250->method_894();
    }
    this->field_250 = jrt::Ref<class_108>(nullptr);
}

void class_24::method_233() {
    jrt::Ref<class_110> var1{};
    jrt::Ref<jrt::Array<int32_t>> var2 = (var1 = jrt::cast<class_110>(this->field_250))->field_1389;
    jrt::Ref<jrt::Array<int32_t>> var3 = var1->method_897();
    jrt::Ref<jrt::Array<int32_t>> var4 = var1->field_1390;
    jrt::Ref<java::util::Random> var5 = org::deep3d::Det::random(3);
    for (int32_t var6 = 0; var6 < var3->length; var6++) {
        var2->at((3 * var6)) = var5->nextInt((this->field_253 >> 1)) - (this->field_253 >> 2);
        var2->at(((3 * var6) + 1)) = var5->nextInt((this->field_253 >> 1)) - (this->field_253 >> 2);
        var2->at(((3 * var6) + 2)) = var5->nextInt((this->field_253 >> 1)) - (this->field_253 >> 2);
        var3->at(var6) = 0;
        var4->at(var6) = -1;
        this->field_251->at(var6) = (var5->nextInt(this->field_254) - (this->field_254 >> 1)) + this->field_252;
    }
}

void class_24::method_234(int32_t var1) {
    jrt::Ref<jrt::Array<int32_t>> var2 = (jrt::cast<class_110>(this->field_250))->method_897();
    jrt::Ref<jrt::Array<int32_t>> var3 = (jrt::cast<class_110>(this->field_250))->field_1390;
    // Deep3D-PC: both truncate to nothing at short frames: shares of what a step did
    int32_t var4 = org::deep3d::Step::exact() ? jrt::div((var1 * this->field_253), this->field_252) : org::deep3d::Step::share(jrt::div((33 * this->field_253), this->field_252), this->deep3dGrow);
    int32_t deep3dFadeNow = org::deep3d::Step::exact() ? (var1 >> 2) : org::deep3d::Step::share(8.0, this->deep3dFade);
    for (int32_t var5 = 0; var5 < var2->length; var5++) {
        if ((this->field_251->at(var5) > 0) && (this->field_251->at(var5) < this->field_252)) {
            var2->at(var5) += var4;
        } else if (this->field_251->at(var5) > (-1024)) {
            int32_t var6{};
            var6 = ((var6 = ((var3->at(var5) >> 24) & 255) - deep3dFadeNow) < 0) ? 0 : var6;
            var3->at(var5) = (var6 << 24) | 16777215;
        } else {
            var2->at(var5) = 0;
        }
        this->field_251->at(var5) = this->field_251->at(var5) - var1;
    }
}

void class_24::__dumpFields(jrt::Dumper& d) {
    d.f("field_250", this->field_250);
    d.f("field_251", this->field_251);
    d.f("field_252", this->field_252);
    d.f("field_253", this->field_253);
    d.f("field_254", this->field_254);
}

