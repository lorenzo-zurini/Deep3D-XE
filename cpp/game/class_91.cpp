// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_91::__clinit() {
}

void class_91::__init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7) {
    this->field_1224 = int16_t(0);
    this->field_1232 = jrt::New<class_3>();
    this->field_1233 = jrt::New<class_3>();
    this->field_1225 = var3;
    this->field_1226 = var4;
    this->field_1227 = var1;
    this->field_1228 = var2;
    if (this->field_1226 != nullptr) {
        this->field_1226->method_845(var5, var6, var7);
        this->field_1226->method_864(0, 0, 0);
        this->field_1225->field_377 = var4->field_1341;
    }
    this->field_1225->field_379 = jrt::Ref<class_91>(this);
    this->field_1234 = var5;
    this->field_1235 = var6;
    this->field_1236 = var7;
    this->field_1238 = false;
    this->field_1239 = false;
    this->field_1237 = false;
    if (this->field_1232 == nullptr) {
        this->field_1232 = jrt::New<class_3>();
    }
}

void class_91::method_794() {
    this->field_1225 = jrt::Ref<class_37>(nullptr);
    if (this->field_1226 != nullptr) {
        this->field_1226->method_894();
    }
    this->field_1226 = jrt::Ref<class_108>(nullptr);
    this->field_1229 = jrt::Ref<class_26>(nullptr);
    this->field_1230 = jrt::Ref<class_18>(nullptr);
    if (this->field_1231 != nullptr) {
        this->field_1231->method_738();
    }
    this->field_1231 = jrt::Ref<class_85>(nullptr);
}

void class_91::method_795(bool var1) {
    this->field_1225->field_375 = var1;
}

void class_91::method_796(int32_t var1) {
}

void class_91::method_797(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1) {
    this->field_1225->method_323(var1);
}

void class_91::method_798(jrt::Ref<class_9> var1, int32_t var2) {
    this->field_1225->method_346(var1, var2);
}

jrt::Ref<class_3> class_91::method_799(jrt::Ref<class_3> var1) {
    return this->field_1226->method_851();
}

bool class_91::method_800() {
    return int32_t(this->field_1224) == 4;
}

bool class_91::method_801() {
    return int32_t(this->field_1224) == 3;
}

void class_91::method_802() {
    this->field_1224 = int16_t(4);
}

void class_91::method_803() {
    this->field_1224 = int16_t(5);
    this->field_1225->field_375 = false;
}

void class_91::method_804() {
    this->field_1224 = int16_t(1);
    this->field_1225->field_375 = true;
}

bool class_91::method_807(jrt::Ref<class_3> var1) {
    return false;
}

jrt::Ref<class_3> class_91::method_808(jrt::Ref<class_3> var1) {
    return jrt::Ref<class_3>(nullptr);
}

void class_91::method_809() {
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1226));
}

void class_91::__dumpFields(jrt::Dumper& d) {
    d.f("field_1224", this->field_1224);
    d.f("field_1225", this->field_1225);
    d.f("field_1226", this->field_1226);
    d.f("field_1227", this->field_1227);
    d.f("field_1228", this->field_1228);
    d.f("field_1229", this->field_1229);
    d.f("field_1230", this->field_1230);
    d.f("field_1231", this->field_1231);
    d.f("field_1232", this->field_1232);
    d.f("field_1233", this->field_1233);
    d.f("field_1234", this->field_1234);
    d.f("field_1235", this->field_1235);
    d.f("field_1236", this->field_1236);
    d.f("field_1237", this->field_1237);
    d.f("field_1238", this->field_1238);
    d.f("field_1239", this->field_1239);
    d.f("field_1240", this->field_1240);
}

