// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_66::__clinit() {
}

void class_66::__init() {
    class_61::__init();
}

void class_66::method_552() {
    if (this->field_842 != nullptr) {
        this->field_842->method_552();
    }
    this->field_842 = jrt::Ref<class_65>(nullptr);
    this->field_841 = false;
    java::lang::System::gc();
}

void class_66::method_551() {
    if (this->field_842 == nullptr) {
        this->field_842 = jrt::New<class_65>(0);
    }
    if (!this->field_842->field_823) {
        this->field_842->method_551();
    } else {
        class_28::method_282(JRT_LIT(u"/data/interface/logo.png"));
        class_21::method_184(int64_t(0));
        this->field_843 = jrt::New<class_51>();
        this->field_843->method_427(0);
        class_67::method_578(false);
        java::lang::System::gc();
        this->field_837 = org::deep3d::Det::millis();
        this->field_838 = org::deep3d::Det::millis();
        this->field_841 = true;
    }
}

bool class_66::method_553() {
    return this->field_841;
}

void class_66::method_549(int32_t var1) {
    if (this->field_841) {
        this->field_837 = org::deep3d::Det::millis();
        this->field_839 = this->field_837 - this->field_838;
        this->field_838 = this->field_837;
        this->field_840 = this->field_840 + this->field_839;
        this->field_842->method_571();
        this->field_843->method_418(var1, int32_t(this->field_839));
        this->method_573();
    }
}

void class_66::method_573() {
    this->field_843->method_429();
}

void class_66::method_550(int32_t var1) {
    if (this->field_841) {
        this->field_843->method_430(var1);
        if (var1 == 4) {
            this->field_843->method_422();
        }
        if (var1 == 32) {
            this->field_843->method_424();
        }
        if (var1 == 2) {
            this->field_843->method_420(int32_t(this->field_839));
        }
        if (var1 == 64) {
            this->field_843->method_421(int32_t(this->field_839));
        }
        if (var1 == 256) {
            this->field_843->method_419();
        }
        if (var1 == 262144) {
            this->field_843->method_426();
        }
        if (var1 == 16384) {
            this->field_843->method_426();
        }
        if (var1 == 8192) {
            this->field_843->method_425();
        }
    }
}

void class_66::__dumpFields(jrt::Dumper& d) {
    class_61::__dumpFields(d);
    d.f("field_837", this->field_837);
    d.f("field_838", this->field_838);
    d.f("field_839", this->field_839);
    d.f("field_840", this->field_840);
    d.f("field_841", this->field_841);
    d.f("field_842", this->field_842);
    d.f("field_843", this->field_843);
}

