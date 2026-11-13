// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> class_39::field_390{};

void class_39::__clinit() {
    class_39::field_390 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({0, 0, 0, 20000, 0, (-300), 0, 800, 15000, 15000, 5000, (-5000), (-128), 1400, 0, 800, 30000, 0, 0, (-20000), 0, 2048, 0, 800, 45000, (-15000), (-5000), 10000, 128, 3072, 0, 800, 60000, 0, 0, 20000, 0, 3796, 0, 800}), jrt::arrayOf<int32_t>({5000, 150000, 5000, 0, (-1024), 1024, 0, 800, 20000, 120000, 5000, 0, (-500), 1024, 0, 800, 30000, 20000, 0, 0, 0, 1024, 0, 800, 40000, 0, (-3000), (-20000), 0, 2048, 0, 800, 55000, 30000, 0, 0, 0, 1024, 0, 800, 65000, 30000, 0, (-50000), 0, 1800, 0, 800, 70000, 6000, 1000, (-116000), 0, 2048, 0, 800})});
}

void class_39::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_388 = class_106::method_886(class_84::field_1120, class_84::field_1121, 800, 100, org::deep3d::Config::enhanced ? 4194304 : 31768);
    this->field_388->method_859(int16_t(2));
    this->field_389 = jrt::New<class_13>(class_39::field_390, var3, int64_t(class_39::field_390->at(var3)->at((class_39::field_390->at(var3)->length - 8))));
}

void class_39::method_364(int64_t var1) {
    if (this->field_387 == int64_t(0)) {
        this->field_387 = var1;
    }
    this->field_389->method_63(var1);
    this->field_388->method_845(this->field_389->field_130->field_37, this->field_389->field_130->field_38, this->field_389->field_130->field_39);
    this->field_388->method_864(this->field_389->field_131->field_37, this->field_389->field_131->field_38, this->field_389->field_131->field_39);
    this->field_388->method_882(this->field_389->field_132);
}

void class_39::__dumpFields(jrt::Dumper& d) {
    d.f("field_387", this->field_387);
    d.f("field_388", this->field_388);
    d.f("field_389", this->field_389);
}

