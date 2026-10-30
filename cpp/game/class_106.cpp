// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_106::field_1355{};
jrt::Ref<class_3> class_106::field_1356{};
jrt::Ref<class_3> class_106::field_1357{};

void class_106::__clinit() {
    class_106::field_1355 = jrt::New<class_3>();
    class_106::field_1356 = jrt::New<class_3>();
    class_106::field_1357 = jrt::New<class_3>();
}

void class_106::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    class_105::__init();
    this->field_1352 = jrt::newArray<jrt::Ref<class_3>>(6);
    this->field_1353 = jrt::newArray<jrt::Ref<class_3>>(6);
    for (int32_t var6 = this->field_1353->length - 1; var6 >= 0; var6--) {
        this->field_1353->at(var6) = jrt::New<class_3>();
    }
    this->field_1354 = jrt::newArray<int32_t>(6);
    this->field_1352->at(0) = jrt::New<class_3>(0, 0, (-4096));
    this->field_1352->at(1) = jrt::New<class_3>(0, 0, 4096);
    this->field_1352->at(2) = jrt::New<class_3>();
    this->field_1352->at(3) = jrt::New<class_3>();
    this->field_1352->at(4) = jrt::New<class_3>();
    this->field_1352->at(5) = jrt::New<class_3>();
    this->field_1358 = var1;
    this->field_1359 = var2;
    this->method_881(var3, var4, var5);
}

void class_106::__init(jrt::Ref<class_106> var1) {
    class_105::__init(jrt::Ref<class_105>(var1));
    this->field_1349 = var1->field_1349;
    this->field_1350 = var1->field_1350;
    this->field_1351 = var1->field_1351;
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1353), 0, jrt::Ref<java::lang::Object>(this->field_1353), 0, var1->field_1353->length);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1352), 0, jrt::Ref<java::lang::Object>(this->field_1352), 0, var1->field_1352->length);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1354), 0, jrt::Ref<java::lang::Object>(this->field_1354), 0, var1->field_1354->length);
    this->field_1360 = var1->field_1360;
    this->field_1361 = var1->field_1361;
    this->field_1358 = var1->field_1358;
    this->field_1359 = var1->field_1359;
}

void class_106::method_839(bool var1) {
    if (this->class_102::field_1339 || var1) {
        if (this->class_102::field_1336 != nullptr) {
            this->class_102::field_1342 = this->class_102::field_1336->field_1342->method_473(this->class_102::field_1341, this->class_102::field_1342);
        } else {
            this->class_102::field_1342->method_470(this->class_102::field_1341);
        }
        this->field_1353 = this->class_102::field_1342->method_510(this->field_1352, this->field_1353);
        class_106::field_1355 = this->class_102::field_1342->method_479(class_106::field_1355);
        class_106::field_1356 = this->class_102::field_1342->method_481(class_106::field_1356);
        class_106::field_1357->method_9(class_106::field_1356);
        class_106::field_1356->method_18((-this->field_1350));
        class_106::field_1357->method_18((-this->field_1351));
        class_106::field_1356->method_15(class_106::field_1355);
        class_106::field_1357->method_15(class_106::field_1355);
        this->field_1354->at(0) = class_106::field_1356->method_11(this->field_1353->at(0));
        this->field_1354->at(1) = class_106::field_1357->method_11(this->field_1353->at(1));
        this->field_1354->at(2) = class_106::field_1355->method_11(this->field_1353->at(2));
        this->field_1354->at(3) = class_106::field_1355->method_11(this->field_1353->at(3));
        this->field_1354->at(4) = class_106::field_1355->method_11(this->field_1353->at(4));
        this->field_1354->at(5) = class_106::field_1355->method_11(this->field_1353->at(5));
        this->class_102::field_1339 = false;
        this->class_102::field_1340 = false;
    }
}

void class_106::method_881(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1349 = var1;
    this->field_1350 = var2;
    this->field_1351 = var3;
    int32_t var4 = class_16::method_91((var1 >> 1));
    int32_t var5 = class_16::method_92((var1 >> 1));
    this->field_1352->at(2)->method_10(var5, 0, (-var4));
    this->field_1352->at(3)->method_10((-var5), 0, (-var4));
    this->field_1352->at(4)->method_10(0, (-var5), (-var4));
    this->field_1352->at(5)->method_10(0, var5, (-var4));
    double var90 = (double((var1 >> 1)) * 3.141592653589793) / 2048.0;
    double var91 = (this->field_1359 > 0) ? (double(this->field_1358) / double(this->field_1359)) : 1.0;
    int32_t var92 = jrt::f2i(java::lang::Math::min(1000.0, (((java::lang::Math::atan((java::lang::Math::tan(var90) * java::lang::Math::max(1.0, var91))) + 0.2) * 2048.0) / 3.141592653589793)));
    int32_t var93 = jrt::f2i(java::lang::Math::min(1000.0, (((var90 + 0.2) * 2048.0) / 3.141592653589793)));
    this->field_1352->at(2)->method_10(class_16::method_92(var92), 0, (-class_16::method_91(var92)));
    this->field_1352->at(3)->method_10((-class_16::method_92(var92)), 0, (-class_16::method_91(var92)));
    this->field_1352->at(4)->method_10(0, (-class_16::method_92(var93)), (-class_16::method_91(var93)));
    this->field_1352->at(5)->method_10(0, class_16::method_92(var93), (-class_16::method_91(var93)));
    this->field_1360 = jrt::div((var4 << 12), var5);
    this->field_1361 = (this->field_1360 * jrt::div((this->field_1358 << 12), this->field_1359)) >> 12;
}

void class_106::method_882(int32_t var1) {
    this->method_881(var1, this->field_1350, this->field_1351);
}

bool class_106::method_883(jrt::Ref<class_3> var1) {
    if ((var1 = this->class_102::field_1342->method_511(var1))->field_39 > this->field_1350) {
        return false;
    } else {
        // Deep3D-PC: in 64 bits (the same results), so a far point (the open sea's stations) can't overflow
        int64_t var2 = (int64_t(this->field_1361) * int64_t(var1->field_39)) >> 12;
        int64_t var3 = (int64_t(this->field_1360) * int64_t(var1->field_39)) >> 12;
        if ((var2 != 0) && (var3 != 0)) {
            auto fit = [](int64_t v) { return int32_t(v < -(int64_t(1) << 30) ? -(int64_t(1) << 30) : v > (int64_t(1) << 30) ? (int64_t(1) << 30) : v); };
            var1->field_37 = fit((-((((int64_t(var1->field_37) << 11) / var2) * this->field_1358) >> 12)) + (this->field_1358 >> 1));
            var1->field_38 = fit(((((int64_t(var1->field_38) << 11) / var3) * this->field_1359) >> 12) + (this->field_1359 >> 1));
            return (((var1->field_37 >= 0) && (var1->field_38 >= 0)) && (var1->field_37 < this->field_1358)) && (var1->field_38 < this->field_1359);
        } else {
            return false;
        }
    }
}

int8_t class_106::method_884(jrt::Ref<class_15> var1) {
    for (int32_t var3 = 5; var3 >= 0; var3--) {
        int32_t var2{};
        if ((var2 = var1->field_148->method_11(this->field_1353->at(var3)) - this->field_1354->at(var3)) < (-var1->field_149)) {
            return int8_t(0);
        }
        if (class_16::method_100(var2) < var1->field_149) {
            return int8_t(1);
        }
    }
    return int8_t(2);
}

void class_106::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
}

void class_106::method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
}

jrt::Ref<class_106> class_106::method_886(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    return jrt::Ref<class_106>(jrt::New<class_107>(var0, var1, var2, var3, var4));
}

void class_106::__dumpFields(jrt::Dumper& d) {
    class_105::__dumpFields(d);
    d.f("field_1349", this->field_1349);
    d.f("field_1350", this->field_1350);
    d.f("field_1351", this->field_1351);
    d.f("field_1352", this->field_1352);
    d.f("field_1353", this->field_1353);
    d.f("field_1354", this->field_1354);
    d.f("field_1358", this->field_1358);
    d.f("field_1359", this->field_1359);
    d.f("field_1360", this->field_1360);
    d.f("field_1361", this->field_1361);
}

