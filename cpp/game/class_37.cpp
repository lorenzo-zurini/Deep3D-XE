// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_37::__clinit() {
}

void class_37::__init(float var1, int32_t var2, int32_t var3) {
    this->field_378 = jrt::New<class_3>();
    this->field_362 = var1;
    this->field_363 = var2;
    this->field_364 = var2;
    this->method_336();
    this->field_369 = var3;
    if (var3 > 0) {
        this->field_359 = jrt::newArray<jrt::Ref<jrt::Array<jrt::Ref<class_9>>>>(var3);
    }
    this->field_377 = jrt::New<class_57>();
    this->field_375 = true;
    this->field_376 = true;
    this->field_373 = jrt::newArray<int32_t>(6);
    this->field_373->at(0) = 1000000;
    this->field_379 = jrt::Ref<class_91>(nullptr);
    this->field_380 = false;
    this->field_383 = false;
}

bool class_37::method_321() {
    return (this->field_379 != nullptr) ? this->field_379->field_1238 : false;
}

void class_37::method_322(int32_t var1) {
    this->field_362 = float(var1);
}

void class_37::method_323(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1) {
    this->field_360 = var1;
    if (this->field_359 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_359->length; var2++) {
            if (this->field_359->at(var2) != nullptr) {
                for (int32_t var3 = 0; var3 < this->field_359->at(var2)->length; var3++) {
                    if (this->field_359->at(var2)->at(var3) != nullptr) {
                        this->field_359->at(var2)->at(var3)->field_77 = this->field_360;
                    }
                }
            }
        }
    }
}

void class_37::method_324(jrt::Ref<class_37> var1) {
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var2{};
    (var2 = jrt::newArray<jrt::Ref<class_37>>(1))->at(0) = var1;
    this->method_323(var2);
}

void class_37::method_325(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1) {
    if (this->field_360 == nullptr) {
        this->method_323(var1);
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var2 = jrt::newArray<jrt::Ref<class_37>>((this->field_360->length + var1->length));
        for (int32_t var3 = 0; var3 < this->field_360->length; var3++) {
            var2->at(var3) = this->field_360->at(var3);
        }
        for (int32_t var4 = 0; var4 < var1->length; var4++) {
            var2->at((this->field_360->length + var4)) = var1->at(var4);
        }
        this->method_323(var2);
    }
}

jrt::Ref<class_37> class_37::method_326(int32_t var1) {
    return this->field_360->at(var1);
}

void class_37::method_327(int32_t var1) {
    this->field_363 = var1;
    if (this->field_363 > this->field_364) {
        this->field_364 = this->field_363;
    }
    this->method_336();
}

void class_37::method_328(int32_t var1) {
    this->field_365 = var1;
    if (this->field_365 > this->field_366) {
        this->field_365 = this->field_366;
    }
    this->method_336();
}

void class_37::method_329(int32_t var1) {
    this->field_367 = var1;
    if (this->field_367 > this->field_368) {
        this->field_367 = this->field_368;
    }
    this->method_336();
}

void class_37::method_330(int32_t var1) {
    this->field_364 = var1;
    this->field_363 = var1;
    this->method_336();
}

void class_37::method_331(int32_t var1) {
    this->field_366 = var1;
    this->field_365 = var1;
    this->method_336();
}

void class_37::method_332(int32_t var1) {
    this->field_368 = var1;
    this->field_367 = var1;
    this->method_336();
}

int32_t class_37::method_333() {
    return (this->field_365 + this->field_367) + this->field_363;
}

void class_37::method_334() {
    if ((this->field_365 + 1) < this->field_366) {
        this->field_365++;
    } else {
        this->field_365 = this->field_366;
    }
    this->method_336();
}

void class_37::method_335() {
    if ((this->field_363 + 1) < this->field_364) {
        this->field_363++;
    } else {
        this->field_363 = this->field_364;
    }
    this->method_336();
}

void class_37::method_336() {
    this->field_370 = jrt::f2i(((float(this->field_363) / float(this->field_364)) * 100.0f));
    this->field_371 = jrt::f2i(((float(this->field_365) / float(this->field_366)) * 100.0f));
    this->field_372 = jrt::f2i(((float(this->field_367) / float(this->field_368)) * 100.0f));
}

void class_37::method_337(int32_t var1, int32_t var2, int32_t var3) {
    this->field_378->field_37 = var1;
    this->field_378->field_38 = var2;
    this->field_378->field_39 = var3;
}

float class_37::method_338(int32_t var1) {
    if (this->field_359 != nullptr) {
        jrt::Ref<java::lang::Object> var2 = jrt::Ref<java::lang::Object>(nullptr);
        if (var1 == this->field_382) {
            var2 = jrt::Ref<java::lang::Object>(this->field_359->at(var1)->at(this->field_381));
        } else {
            var2 = jrt::Ref<java::lang::Object>(this->field_359->at(var1)->at(0));
        }
        if (var2 != nullptr) {
            return float((jrt::cast<class_9>(var2))->field_90) / float((jrt::cast<class_9>(var2))->field_91);
        }
    }
    return 0.0f;
}

void class_37::method_339(int32_t var1) {
    if (Deep3dDebug::godFor(jrt::Ref<class_37>(this))) {
        return;
    }
    if (this->field_376 && this->field_375) {
        if (this->field_367 <= 0) {
            this->method_341(var1);
        } else {
            this->field_367 -= var1;
        }
        if (this->field_367 < 0) {
            this->field_367 = 0;
        }
        this->method_336();
    }
}

void class_37::method_340(int32_t var1) {
    if (Deep3dDebug::godFor(jrt::Ref<class_37>(this))) {
        return;
    }
    if (this->field_376 && this->field_375) {
        if (this->field_365 <= 0) {
            this->method_341(var1);
        } else {
            this->field_365 -= var1;
        }
        if (this->field_365 < 0) {
            this->field_365 = 0;
        }
        this->method_336();
    }
}

void class_37::method_341(int32_t var1) {
    if (Deep3dDebug::godFor(jrt::Ref<class_37>(this))) {
        return;
    }
    this->field_363 -= var1;
    if (this->field_363 < 0) {
        this->field_363 = 0;
    }
}

void class_37::method_342(int32_t var1, bool var2) {
    if (Deep3dDebug::godFor(jrt::Ref<class_37>(this))) {
        return;
    }
    if (this->field_376 && this->field_375) {
        int32_t var3{};
        if ((var3 = this->field_365 - var1) < 0) {
            this->field_365 = 0;
            int32_t var4{};
            if ((var4 = this->field_367 - (-var3)) < 0) {
                this->field_367 = 0;
                this->field_363 -= (-var4);
            } else {
                this->field_367 = var4;
            }
        } else {
            this->field_365 = var3;
        }
        if (this->field_363 < 0) {
            this->field_363 = 0;
            if (var2) {
                this->field_383 = true;
            }
        }
        this->method_336();
    }
}

void class_37::method_343(int32_t var1) {
    this->method_342(var1, false);
}

jrt::Ref<class_3> class_37::method_344(jrt::Ref<class_3> var1) {
    return this->field_377->method_479(var1);
}

bool class_37::method_345() {
    return this->field_363 <= 0;
}

void class_37::method_346(jrt::Ref<class_9> var1, int32_t var2) {
    if (this->field_359 != nullptr) {
        if ((var2 <= this->field_369) && (var2 >= 0)) {
            this->field_359->at(var2) = jrt::newArray<jrt::Ref<class_9>>(1);
            this->field_359->at(var2)->at(0) = var1;
        }
        this->method_348();
    }
}

void class_37::method_347(jrt::Ref<jrt::Array<jrt::Ref<class_9>>> var1, int32_t var2) {
    if (this->field_359 != nullptr) {
        if ((var2 <= this->field_369) && (var2 >= 0)) {
            this->field_359->at(var2) = jrt::newArray<jrt::Ref<class_9>>(var1->length);
            this->field_359->at(var2) = var1;
        }
        this->method_348();
    }
}

void class_37::method_348() {
    int32_t var1 = 0;
    this->field_381 = 0;
    if (this->field_359 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_359->length; var2++) {
            if (this->field_359->at(var2) != nullptr) {
                for (int32_t var3 = 0; var3 < this->field_359->at(var2)->length; var3++) {
                    if ((this->field_359->at(var2)->at(var3)->field_91 > var1) && (!this->field_359->at(var2)->at(var3)->field_97)) {
                        var1 = this->field_359->at(var2)->at(var3)->field_91;
                        this->field_382 = var2;
                        this->field_381 = var3;
                    }
                }
            }
        }
    }
}

void class_37::method_349() {
    this->field_369 = 0;
    this->field_359 = jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<class_9>>>>>(nullptr);
}

int32_t class_37::method_350(int32_t var1) {
    return this->field_359->at(var1)->at(0)->field_100;
}

void class_37::method_351(int32_t var1) {
    if ((((this->field_359 != nullptr) && (var1 < this->field_359->length)) && (var1 >= 0)) && (this->field_359->at(var1) != nullptr)) {
        for (int32_t var2 = 0; var2 < this->field_359->at(var1)->length; var2++) {
            this->field_359->at(var1)->at(var2)->field_90 = 0;
        }
    }
}

void class_37::method_352(int32_t var1, int64_t var2, bool var4) {
    if ((((this->field_359 != nullptr) && (var1 < this->field_359->length)) && (var1 >= 0)) && (this->field_359->at(var1) != nullptr)) {
        for (int32_t var5 = 0; var5 < this->field_359->at(var1)->length; var5++) {
            if (org::deep3d::Step::past(this->field_359->at(var1)->at(var5)->field_90, this->field_359->at(var1)->at(var5)->field_91) && this->field_359->at(var1)->at(var5)->method_46(this->field_377, var2, var4)) {
                this->field_359->at(var1)->at(var5)->field_90 = 0;
                if (this->field_380 && this->field_359->at(var1)->at(var5)->field_97) {
                    class_84::field_1122->method_770(5);
                }
            }
        }
    }
}

void class_37::method_353(int64_t var1) {
    this->field_374 = int32_t((int64_t(this->field_374) + var1));
    if (this->field_374 > 3000) {
        this->field_374 = 0;
    }
}

void class_37::__dumpFields(jrt::Dumper& d) {
    d.f("field_359", this->field_359);
    d.f("field_360", this->field_360);
    d.f("field_361", this->field_361);
    d.f("field_362", this->field_362);
    d.f("field_363", this->field_363);
    d.f("field_364", this->field_364);
    d.f("field_365", this->field_365);
    d.f("field_366", this->field_366);
    d.f("field_367", this->field_367);
    d.f("field_368", this->field_368);
    d.f("field_369", this->field_369);
    d.f("field_370", this->field_370);
    d.f("field_371", this->field_371);
    d.f("field_372", this->field_372);
    d.f("field_373", this->field_373);
    d.f("field_374", this->field_374);
    d.f("field_375", this->field_375);
    d.f("field_376", this->field_376);
    d.f("field_377", this->field_377);
    d.f("field_378", this->field_378);
    d.f("field_379", this->field_379);
    d.f("field_380", this->field_380);
    d.f("field_381", this->field_381);
    d.f("field_382", this->field_382);
    d.f("field_383", this->field_383);
}

