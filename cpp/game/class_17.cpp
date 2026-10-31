// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_17::__clinit() {
}

void class_17::__init() {
}

void class_17::method_101() {
    this->field_155->method_714();
    this->field_155 = jrt::Ref<class_78>(nullptr);
    this->field_156 = jrt::Ref<class_10>(nullptr);
    this->field_157 = jrt::Ref<class_121>(nullptr);
    this->field_154 = false;
    java::lang::System::gc();
}

void class_17::method_102() {
    this->field_159 = 0;
    this->field_153 = false;
    this->field_155 = [&]() { jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> __a1 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(266), class_84::field_1116->method_4(267)}); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(235); jrt::Ref<class_78> __o(new class_78()); __o->__init(__a1, __a2); return __o; }();
    this->field_156 = jrt::New<class_10>();
    this->field_157 = jrt::New<class_121>(20, (class_84::field_1121 / 3), (class_84::field_1120 - 40));
    class_21::method_220();
    this->field_155->method_722(0, class_120::method_935(class_21::method_178()->field_886, class_21::method_180()->field_1142));
    class_21::method_178()->method_611(class_120::method_934(this->field_155->field_1062, true));
    class_21::method_180()->field_1142 = class_120::method_934(this->field_155->field_1062, false);
    this->field_155->method_722(1, class_35::method_302());
    java::lang::System::gc();
    this->field_154 = true;
}

bool class_17::method_103(int32_t var1) {
    this->field_158 = jrt::cast<class_59>(this->field_155->method_701());
    if (var1 == 256) {
        if (this->field_153) {
            this->field_153 = false;
            return true;
        }
        if (this->field_159 == 0) {
            this->field_155->method_726();
        } else if (this->field_159 == 2) {
            this->field_159 = 0;
        } else if (this->field_159 == 1) {
            this->field_159 = 0;
        }
    }
    if ((var1 == 4) && (this->field_159 == 0)) {
        this->field_155->method_706();
    }
    if ((var1 == 32) && (this->field_159 == 0)) {
        this->field_155->method_707();
    }
    if (var1 == 2) {
        if (this->field_159 == 0) {
            this->field_155->method_704();
        } else if (this->field_159 == 2) {
            this->field_156->method_52(org::deep3d::Step::once(this->field_152));
        }
    }
    if (var1 == 64) {
        if (this->field_159 == 0) {
            this->field_155->method_705();
        } else if (this->field_159 == 2) {
            this->field_156->method_53(org::deep3d::Step::once(this->field_152));
        }
    }
    if (var1 == 8192) {
        if ((this->field_159 == 0) && (!this->field_155->method_723())) {
            return false;
        }
        if (this->field_159 == 2) {
            this->field_159 = 0;
        }
    }
    if (var1 == 16384) {
        if ((this->field_159 == 0) && (!this->field_155->method_723())) {
            if (this->field_158 != nullptr) {
                this->field_159 = 2;
                this->field_156->method_51(this->field_158, (this->field_155->field_1038 == 0));
            }
        } else if (this->field_159 == 1) {
            this->field_159 = 0;
        }
    }
    return this->field_153 ? true : true;
}

bool class_17::method_104(int32_t var1, int32_t var2) {
    if (!this->field_154) {
        return true;
    } else {
        this->field_151 += int64_t(var2);
        this->field_152 = var2;
        this->method_105();
        if (this->field_155->method_701() != nullptr) {
            this->field_158 = jrt::cast<class_59>(this->field_155->method_701());
        }
        if (this->field_153) {
            return true;
        } else {
            if (this->field_159 == 0) {
                if ((var1 & 4) == 0) {
                    this->field_160 = 0;
                } else {
                    this->field_160 += var2;
                }
                if ((var1 & 32) == 0) {
                    this->field_161 = 0;
                } else {
                    this->field_161 += var2;
                }
                if (this->field_160 > 500) {
                    this->field_155->method_724();
                    this->field_160 = 0;
                }
                if (this->field_161 > 500) {
                    this->field_155->method_725();
                    this->field_161 = 0;
                }
            }
            return true;
        }
    }
}

void class_17::method_105() {
    if ((this->field_159 == 0) && this->field_155->method_723()) {
        org::deep3d::GameUi::controls(1, (-5), (-5), 0);
        org::deep3d::GameUi::scrollArea(this->field_155->field_1027, this->field_155->field_1028, this->field_155->field_1029, this->field_155->field_1030, true);
    } else {
        org::deep3d::GameUi::controls(1, (-5), (-7), ((this->field_159 == 0) ? (-6) : 0));
    }
    class_67::method_587();
    if (this->field_159 == 0) {
        this->field_155->method_718();
    }
    if (this->field_159 == 2) {
        this->field_156->method_54();
    }
    if ((this->field_159 == 1) || this->field_155->method_723()) {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
    } else if (this->field_159 == 0) {
        [&]() { jrt::Ref<java::lang::String> __a1 = class_84::field_1116->method_4(226); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(65); return class_67::method_593(__a1, __a2); }();
    } else {
        class_67::method_593(JRT_LIT(u""), class_84::field_1116->method_4(65));
    }
    if (this->field_159 == 1) {
        this->field_155->method_718();
        this->field_157->method_944();
    }
    if (this->field_153) {
        this->field_157->method_944();
    }
}

int32_t class_17::method_106() {
    return this->field_155->field_1038;
}

bool class_17::method_107() {
    return (this->field_159 == 0) && (!this->field_155->method_723());
}

void class_17::__dumpFields(jrt::Dumper& d) {
    d.f("field_151", this->field_151);
    d.f("field_152", this->field_152);
    d.f("field_153", this->field_153);
    d.f("field_154", this->field_154);
    d.f("field_155", this->field_155);
    d.f("field_156", this->field_156);
    d.f("field_157", this->field_157);
    d.f("field_158", this->field_158);
    d.f("field_159", this->field_159);
    d.f("field_160", this->field_160);
    d.f("field_161", this->field_161);
}

