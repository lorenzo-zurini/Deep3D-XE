// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_42::__clinit() {
}

void class_42::__init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2) {
    this->__init(var1, var2, jrt::Ref<class_3>(nullptr));
}

void class_42::__init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2, jrt::Ref<class_3> var3) {
    this->field_461 = jrt::New<class_3>();
    this->field_462 = jrt::New<class_3>();
    this->field_464 = false;
    this->deep3dDolly = 1.0f;
    this->deep3dOff = jrt::New<class_3>();
    this->deep3dAim = jrt::New<class_3>();
    this->field_452 = var1;
    this->field_454 = var2;
    this->field_460 = true;
    this->field_459 = var3;
    if (var3 != nullptr) {
        this->field_459->method_22();
    }
    if (this->field_455 == nullptr) {
        this->field_455 = jrt::New<class_3>();
    }
    if (this->field_456 == nullptr) {
        this->field_456 = jrt::New<class_3>();
    }
    if (this->field_457 == nullptr) {
        this->field_457 = jrt::New<class_3>();
    }
    if (this->field_458 == nullptr) {
        this->field_458 = jrt::New<class_3>();
    }
    if ((var1 != nullptr) && (var2 != nullptr)) {
        this->field_463 = jrt::New<class_5>(var1, var2);
        this->field_453 = var1;
        while (this->field_453->field_1336 != nullptr) {
            this->field_453 = jrt::Ref<class_102>(this->field_453->field_1336);
        }
        jrt::Ref<java::lang::Object> var4 = jrt::Ref<java::lang::Object>(var2);
        while ((jrt::cast<class_102>(var4))->field_1336 != nullptr) {
            var4 = jrt::Ref<java::lang::Object>((jrt::cast<class_102>(var4))->field_1336);
        }
        if (var4 == this->field_453) {
            this->field_453 = jrt::Ref<class_102>(nullptr);
        }
        this->field_465 = jrt::isInstance<class_106>(var2);
        this->field_462 = [&]() { auto __r = var2->method_850(); jrt::Ref<class_3> __a1 = var1->method_850(); jrt::Ref<class_3> __a2 = jrt::New<class_3>(); return __r->method_16(__a1, __a2); }();
    }
}

void class_42::method_368(jrt::Ref<class_102> var1) {
    this->field_452 = var1;
    if ((this->field_463 == nullptr) && (var1 != nullptr)) {
        this->field_463 = jrt::New<class_5>(var1, this->field_454);
    }
    if (this->field_463 != nullptr) {
        this->field_463->field_45 = var1;
    }
}

void class_42::method_369(jrt::Ref<class_102> var1) {
    this->field_454 = var1;
    if ((this->field_463 == nullptr) && (var1 != nullptr)) {
        this->field_463 = jrt::New<class_5>(this->field_452, var1);
    }
    if (this->field_463 != nullptr) {
        this->field_463->field_48 = var1;
    }
    this->field_465 = jrt::isInstance<class_106>(var1);
}

void class_42::method_370(jrt::Ref<class_3> var1) {
    this->field_457->method_9(var1);
}

void class_42::method_371() {
    this->field_464 = true;
    this->field_457 = this->field_452->field_1342->method_507(this->field_462, this->field_457);
    this->field_454->method_846(this->field_457);
}

void class_42::method_372() {
    this->field_464 = false;
}

void class_42::method_0() {
    if (this->field_460) {
        if (this->field_464) {
            this->field_463->method_0();
            return;
        }
        if (this->field_452 != nullptr) {
            this->field_455 = this->field_452->method_857();
            this->field_455->method_22();
            this->field_456 = this->field_452->field_1342->method_507(this->field_462, this->field_456);
            // Deep3D-PC: this runs for every object drawn (class_4::method_25), each run a frame's share
            this->field_457->field_37 = org::deep3d::Step::chase(this->field_457->field_37, this->field_456->field_37, 8, this->deep3dChase[0]);
            this->field_457->field_38 = org::deep3d::Step::chase(this->field_457->field_38, this->field_456->field_38, 8, this->deep3dChase[1]);
            this->field_457->field_39 = org::deep3d::Step::chase(this->field_457->field_39, this->field_456->field_39, 8, this->deep3dChase[2]);
            this->field_456 = this->field_452->field_1342->method_507(this->field_461, this->field_456);
            this->field_456->field_37 = this->field_456->field_37 - this->field_457->field_37;
            this->field_456->field_38 = this->field_456->field_38 - this->field_457->field_38;
            this->field_456->field_39 = this->field_456->field_39 - this->field_457->field_39;
            if (this->field_465) {
                this->field_456->field_37 = -this->field_456->field_37;
                this->field_456->field_38 = -this->field_456->field_38;
                this->field_456->field_39 = -this->field_456->field_39;
            }
            this->field_456->method_22();
            this->field_458 = this->field_455->method_13(this->field_456, this->field_458);
            this->field_455 = this->field_456->method_13(this->field_458, this->field_455);
            this->field_458->method_22();
            this->field_454->method_872(this->field_458, this->field_455, this->field_456);
            if ((this->deep3dDolly != 1.0f) && this->field_465) {
                this->deep3dAim = this->field_452->method_849(this->deep3dAim);
                int64_t var1 = ((int64_t((this->deep3dAim->field_37 - this->field_457->field_37)) * int64_t((-this->field_456->field_37))) + (int64_t((this->deep3dAim->field_38 - this->field_457->field_38)) * int64_t((-this->field_456->field_38)))) + (int64_t((this->deep3dAim->field_39 - this->field_457->field_39)) * int64_t((-this->field_456->field_39)));
                float var2 = ((float(var1) / 4096.0f) * (1.0f - this->deep3dDolly)) / 4096.0f;
                this->deep3dOff->method_10((this->field_457->field_37 - jrt::f2i((float(this->field_456->field_37) * var2))), (this->field_457->field_38 - jrt::f2i((float(this->field_456->field_38) * var2))), (this->field_457->field_39 - jrt::f2i((float(this->field_456->field_39) * var2))));
                this->field_454->method_846(this->deep3dOff);
            } else {
                this->field_454->method_846(this->field_457);
            }
        }
    }
}

bool class_42::method_1() {
    return this->field_460;
}

void class_42::method_373(bool var1) {
    this->field_460 = var1;
    this->field_463->field_53 = var1;
}

void class_42::method_374(jrt::Ref<class_3> var1) {
    this->field_457->method_9(var1);
}

void class_42::method_375(jrt::Ref<class_3> var1) {
    this->field_461->method_9(var1);
}

void class_42::method_376(jrt::Ref<class_3> var1) {
    this->field_462->method_9(var1);
}

void class_42::__dumpFields(jrt::Dumper& d) {
    d.f("deep3dAim", this->deep3dAim);
    d.f("deep3dDolly", this->deep3dDolly);
    d.f("deep3dOff", this->deep3dOff);
    d.f("field_452", this->field_452);
    d.f("field_453", this->field_453);
    d.f("field_454", this->field_454);
    d.f("field_455", this->field_455);
    d.f("field_456", this->field_456);
    d.f("field_457", this->field_457);
    d.f("field_458", this->field_458);
    d.f("field_459", this->field_459);
    d.f("field_460", this->field_460);
    d.f("field_461", this->field_461);
    d.f("field_462", this->field_462);
    d.f("field_463", this->field_463);
    d.f("field_464", this->field_464);
    d.f("field_465", this->field_465);
}

