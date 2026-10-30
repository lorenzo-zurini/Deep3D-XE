// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_99::__clinit() {
}

void class_99::__init(int32_t var1, jrt::Ref<class_108> var2, int32_t var3, int32_t var4, int32_t var5) {
    class_98::__init(var1, var2, var3, var4, var5);
    this->class_91::field_1234 = var3;
    this->class_91::field_1235 = var4;
    this->class_91::field_1236 = var5;
    if (var2 != nullptr) {
        if (var1 == 15) {
            this->class_91::field_1226->field_1367 = 2;
            this->class_91::field_1226->method_878();
            this->class_91::field_1226->method_874(1);
            this->field_1304 = false;
            this->field_1305 = false;
            this->class_91::field_1225->method_322(15000);
        }
        this->field_1303 = jrt::newArray<jrt::Ref<class_29>>(1);
        this->field_1303->at(0) = jrt::Ref<class_29>(jrt::New<class_31>(var3, var4, var5, 0, 0, 0, 15000, 15000, 8000));
        this->field_1306 = false;
    }
}

/* Deep3D-PC: Open Sea moves a gate when the planet's chart re-centres */
void class_99::deep3dMove(int32_t dx, int32_t dy, int32_t dz) {
    this->class_98::field_1300 += dx, this->class_98::field_1301 += dy, this->class_98::field_1302 += dz;
    this->class_91::field_1234 += dx, this->class_91::field_1235 += dy, this->class_91::field_1236 += dz;
    if (this->field_1303 != nullptr) {
        jrt::Ref<class_29> v = this->field_1303->at(0);
        v->method_286(v->field_307 + dx, v->field_308 + dy, v->field_309 + dz);
    }
}

void class_99::method_821() {
    this->field_1306 = true;
}

void class_99::method_822(int32_t var1) {
    this->class_91::field_1226->method_864(0, var1, 0);
}

void class_99::method_809() {
    class_98::method_809();
}

void class_99::method_805(int64_t var1) {
    if (this->field_1304) {
        if (this->class_91::field_1226->method_875() == 19) {
            this->class_91::field_1226->method_876(20, 39);
            this->class_91::field_1226->method_877(int8_t(2));
            this->field_1305 = true;
        }
    } else if (!this->field_1305) {
        this->class_91::field_1226->method_874(1);
        this->class_91::field_1226->method_876(1, 1);
        this->class_91::field_1226->method_877(int8_t(2));
        this->class_91::field_1226->method_860(0, 0, (org::deep3d::Step::exact() ? (int32_t(var1) >> 1) : org::deep3d::Step::share(16.0, this->deep3dSpin)));   // Deep3D-PC
    }
    this->class_91::field_1232 = class_84::field_1110->field_40->method_849(this->class_91::field_1232);
    this->class_91::field_1233->method_10(this->class_98::field_1300, this->class_98::field_1301, this->class_98::field_1302);
    this->class_91::field_1233->method_16(this->class_91::field_1232, class_98::field_1299);
    this->class_91::field_1226->method_869(4096, 4096, 4096);
    this->class_91::field_1226->method_845(this->class_98::field_1300, this->class_98::field_1301, this->class_98::field_1302);
}

bool class_99::method_806(int32_t var1, int32_t var2, int32_t var3) {
    if ((((((float((var1 - this->class_98::field_1300)) < this->class_91::field_1225->field_362) && (float((var1 - this->class_98::field_1300)) > (-this->class_91::field_1225->field_362))) && (float((var2 - this->class_98::field_1301)) < this->class_91::field_1225->field_362)) && (float((var2 - this->class_98::field_1301)) > (-this->class_91::field_1225->field_362))) && (float((var3 - this->class_98::field_1302)) < this->class_91::field_1225->field_362)) && (float((var3 - this->class_98::field_1302)) > (-this->class_91::field_1225->field_362))) {
        this->method_823();
        return true;
    } else {
        this->method_824();
        return false;
    }
}

void class_99::method_823() {
    if (((this->field_1306 && (!this->field_1304)) && (class_21::method_132() == class_87::field_1145)) || (!this->field_1306)) {
        this->class_91::field_1226->method_876(1, 19);
        this->class_91::field_1226->method_874(1);
        this->class_91::field_1226->method_877(int8_t(1));
        this->field_1304 = true;
        class_84::field_1122->method_770(3);
    }
}

void class_99::method_824() {
    if (this->field_1304) {
        this->class_91::field_1226->method_876(1, this->class_91::field_1226->method_875());
        this->class_91::field_1226->method_877(int8_t(3));
        this->field_1304 = false;
        this->field_1305 = false;
        class_84::field_1122->method_770(3);
    }
}

bool class_99::method_807(jrt::Ref<class_3> var1) {
    return (this->field_1303 != nullptr) ? this->field_1303->at(0)->method_288(var1->field_37, var1->field_38, var1->field_39) : false;
}

jrt::Ref<class_3> class_99::method_808(jrt::Ref<class_3> var1) {
    return (this->field_1303 != nullptr) ? this->field_1303->at(0)->method_285(var1) : jrt::Ref<class_3>(nullptr);
}

void class_99::__dumpFields(jrt::Dumper& d) {
    class_98::__dumpFields(d);
    d.f("field_1303", this->field_1303);
    d.f("field_1304", this->field_1304);
    d.f("field_1305", this->field_1305);
    d.f("field_1306", this->field_1306);
}

