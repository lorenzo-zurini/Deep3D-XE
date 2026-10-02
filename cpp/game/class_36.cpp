// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_36::__clinit() {
}

void class_36::__init() {
    this->field_349 = ([&]() { jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> __a1 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(37), class_84::field_1116->method_4(328)}); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(37); jrt::Ref<class_81> __o(new class_81()); __o->__init(__a1, __a2); return __o; }());
    this->field_349->method_730(1, class_21::method_180()->field_1144);
    this->field_349->method_730(0, class_21::method_134());
    this->field_355 = 0;
    this->field_351 = jrt::New<class_10>();
    this->field_352 = jrt::New<class_121>(20, (class_84::field_1121 / 3), (class_84::field_1120 - 40));
    this->field_357 = jrt::New<class_47>();
    this->field_356 = false;
    java::lang::System::gc();
}

void class_36::method_310() {
    this->field_349->method_730(0, class_21::method_134());
}

void class_36::method_311() {
    this->field_349 = jrt::Ref<class_81>(nullptr);
    this->field_350 = jrt::Ref<class_87>(nullptr);
    this->field_351 = jrt::Ref<class_10>(nullptr);
    this->field_352 = jrt::Ref<class_121>(nullptr);
    java::lang::System::gc();
}

void class_36::method_312() {
    this->field_355 = 0;
    this->field_350 = jrt::Ref<class_87>(nullptr);
}

int32_t class_36::method_313() {
    return this->field_349->field_1038;
}

bool class_36::method_314() {
    return this->field_355 == 0;
}

bool class_36::method_315(int32_t var1) {
    if (this->field_355 == 2) {
        if (!this->field_353->method_447(var1)) {
            if (this->field_353->field_654) {
                this->field_355 = 3;
            } else {
                this->field_355 = 1;
            }
        }
    } else if (this->field_355 == 0) {
        if (this->field_356) {
            if (var1 == 256) {
                if (this->field_352->method_941()) {
                    this->method_316(false);
                } else {
                    this->field_355 = 0;
                }
                this->field_356 = false;
                return true;
            }
            if (var1 == 32) {
                this->field_352->method_943();
            } else if (var1 == 4) {
                this->field_352->method_942();
            }
            return true;
        }
        if ((var1 == 256) || (var1 == 16384)) {
            if (this->field_349->method_701() != nullptr) {
                this->field_350 = (jrt::cast<class_59>(this->field_349->method_701()))->field_712;
                if ((var1 == 256) && this->field_356) {
                    this->field_355 = 0;
                } else {
                    if (class_21::method_182() < this->field_350->field_1151) {
                        this->field_352->method_939(class_21::method_219(class_84::field_1116->method_4(85), jrt::concat(JRT_LIT(u""), (this->field_350->field_1151 - class_21::method_182()))));
                        this->field_356 = true;
                        return true;
                    }
                    this->field_351->method_51(jrt::cast<class_59>(this->field_349->method_701()), true);
                    this->field_355 = 1;
                }
            }
            return true;
        }
        if ((var1 == 4) && (this->field_355 == 0)) {
            this->field_349->method_706();
        }
        if ((var1 == 32) && (this->field_355 == 0)) {
            this->field_349->method_707();
        }
        if ((var1 == 2) && (this->field_355 == 0)) {
            this->field_349->method_704();
        }
        if ((var1 == 64) && (this->field_355 == 0)) {
            this->field_349->method_705();
        }
        if (var1 == 8192) {
            if (this->field_355 == 0) {
                return false;
            }
            if (this->field_355 == 1) {
                this->field_355 = 0;
                return true;
            }
        }
    } else if (this->field_355 == 1) {
        if (this->field_356) {
            if (var1 == 256) {
                if (this->field_352->method_941()) {
                    this->method_316(false);
                } else {
                    this->field_355 = 1;
                }
                this->field_356 = false;
            } else if (var1 == 32) {
                this->field_352->method_943();
            } else if (var1 == 4) {
                this->field_352->method_942();
            }
        } else if ((var1 != 256) && (var1 != 16384)) {
            if (var1 == 8192) {
                this->field_355 = 0;
            }
        } else if ((this->field_350->field_1161 && this->field_350->field_1171) && (this->field_350->field_1152 != class_21::method_180()->field_1134)) {
            this->field_352->method_940(class_84::field_1116->method_4(252), true);
            this->field_352->method_942();
            this->field_356 = true;
        } else if (!this->field_350->field_1161) {
            this->field_358 = class_38::method_354(this->field_350->field_1152);
            this->field_357->method_393((this->field_349->field_1038 == 1), (this->field_350->field_1152 == class_21::method_180()->field_1134));
            this->field_355 = 3;
        }
    } else if (this->field_355 == 3) {
        if (this->field_356) {
            if (var1 == 256) {
                if (this->field_352->method_941()) {
                    this->field_356 = false;
                    this->field_355 = 0;
                    if (this->field_349->field_1038 == 0) {
                        class_21::method_136(class_87::field_1145);
                        this->field_349->method_705();
                    } else {
                        class_21::method_136(this->field_350);
                        class_21::method_180()->method_751(this->field_350);
                        class_21::method_197((-this->field_350->field_1151));
                        this->field_349->method_706();
                        if (this->field_350->field_1152 != class_21::method_180()->field_1134) {
                            this->field_352->method_940(class_84::field_1116->method_4(252), true);
                            this->field_356 = true;
                        }
                    }
                    if (this->field_349 == nullptr) {
                        return false;
                    }
                    this->field_349->method_730(1, class_21::method_180()->field_1144);
                    this->field_349->method_730(0, class_21::method_134());
                    this->field_349->method_705();
                    return true;
                }
                this->field_356 = false;
            } else if (var1 == 4) {
                this->field_352->method_942();
            } else if (var1 == 32) {
                this->field_352->method_943();
            }
            return true;
        }
        if (var1 == 2) {
            this->field_357->method_394();
        } else if (var1 == 64) {
            this->field_357->method_395();
        } else if (var1 == 256) {
            {
                switch (this->field_357->field_527) {
                case 0:
                    if (this->field_349->field_1038 == 0) {
                        this->field_352->method_940(class_84::field_1116->method_4(244), true);
                    } else {
                        bool var2 = (this->field_358->field_1140 > class_21::method_178()->field_890) || (this->field_358->field_1140 < class_21::method_178()->field_889);
                        if ((this->field_350->field_1152 == class_21::method_180()->field_1134) || (this->field_350->field_1146 == 13)) {
                            var2 = false;
                        }
                        if (class_21::method_135()->method_754()) {
                            this->field_352->method_940(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(264); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u": "); int32_t __c3 = this->field_350->field_1151; jrt::Ref<java::lang::String> __c4 = JRT_LIT(u" $\n"); jrt::Ref<java::lang::String> __c5 = (var2 ? jrt::concat(class_84::field_1116->method_4(255), JRT_LIT(u"\n")) : JRT_LIT(u"")); return jrt::concat(__c1, __c2, __c3, __c4, __c5); }()), true);
                        } else {
                            this->field_352->method_940(([&]() { jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(242); jrt::Ref<java::lang::String> __c7 = JRT_LIT(u"\n"); jrt::Ref<java::lang::String> __c8 = class_84::field_1116->method_4(264); jrt::Ref<java::lang::String> __c9 = JRT_LIT(u": "); int32_t __c10 = this->field_350->field_1151; jrt::Ref<java::lang::String> __c11 = JRT_LIT(u" $\n"); jrt::Ref<java::lang::String> __c12 = class_84::field_1116->method_4(243); jrt::Ref<java::lang::String> __c13 = JRT_LIT(u": "); int32_t __c14 = class_21::method_135()->field_1151; jrt::Ref<java::lang::String> __c15 = JRT_LIT(u" $\n"); jrt::Ref<java::lang::String> __c16 = (var2 ? jrt::concat(class_84::field_1116->method_4(255), JRT_LIT(u"\n")) : JRT_LIT(u"")); jrt::Ref<java::lang::String> __c17 = class_84::field_1116->method_4(244); return jrt::concat(__c6, __c7, __c8, __c9, __c10, __c11, __c12, __c13, __c14, __c15, __c16, __c17); }()), true);
                        }
                    }
                    this->field_356 = true;
                    break;
                case 1:
                    if (this->field_350->field_1152 == class_21::method_180()->field_1134) {
                        this->field_353 = (jrt::cast<class_63>(class_84::field_1127->at(1)))->field_757;
                        this->field_353->method_448();
                        return false;
                    }
                    this->method_316((this->field_349->field_1038 == 1));
                    break;
                case 2:
                    this->field_355 = 1;
                }
            }
        }
    }
    return true;
}

void class_36::method_316(bool var1) {
    this->field_353 = (jrt::cast<class_63>(class_84::field_1127->at(1)))->field_757;
    this->field_353->method_445((var1 ? this->field_350 : jrt::Ref<class_87>(nullptr)));
    this->field_355 = 2;
}

bool class_36::method_317(int32_t var1, int32_t var2) {
    this->field_354 += int64_t(var2);
    if (this->field_355 == 2) {
        this->field_353->method_450(var1, var2);
        return true;
    } else {
        if (((var1 & 2) != 0) && (this->field_355 == 1)) {
            this->field_351->method_52(var2);
        }
        if (((var1 & 64) != 0) && (this->field_355 == 1)) {
            this->field_351->method_53(var2);
        }
        this->method_320();
        return true;
    }
}

bool class_36::method_318() {
    return this->field_355 == 2;
}

bool class_36::method_319() {
    return (this->field_355 == 2) && (this->field_349->field_1038 == 1);
}

void class_36::method_320() {
    org::deep3d::GameUi::controls(1, ((this->field_355 == 3) ? (-5) : (-6)), ((this->field_355 == 3) ? 2 : (-7)), 0);
    class_67::method_587();
    if (this->field_355 == 0) {
        this->field_349->method_718();
    }
    if (this->field_355 == 1) {
        this->field_351->method_54();
    }
    if (this->field_355 == 0) {
        [&]() { jrt::Ref<java::lang::String> __a1 = ((this->field_349->method_701() != nullptr) ? class_84::field_1116->method_4(226) : JRT_LIT(u"")); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(65); return class_67::method_593(__a1, __a2); }();
    } else if (((this->field_350 == nullptr) || (!this->field_350->field_1171)) || (this->field_350->field_1161 && (this->field_350->field_1152 == class_21::method_180()->field_1134))) {
        class_67::method_593(JRT_LIT(u""), class_84::field_1116->method_4(65));
    } else {
        [&]() { jrt::Ref<java::lang::String> __a3 = class_84::field_1116->method_4(74); jrt::Ref<java::lang::String> __a4 = class_84::field_1116->method_4(65); return class_67::method_593(__a3, __a4); }();
    }
    if (this->field_355 == 3) {
        this->field_351->method_54();
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
        this->field_357->method_396();
    }
    if (this->field_356) {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
        this->field_352->method_944();
    }
}

void class_36::__dumpFields(jrt::Dumper& d) {
    d.f("field_349", this->field_349);
    d.f("field_350", this->field_350);
    d.f("field_351", this->field_351);
    d.f("field_352", this->field_352);
    d.f("field_353", this->field_353);
    d.f("field_354", this->field_354);
    d.f("field_355", this->field_355);
    d.f("field_356", this->field_356);
    d.f("field_357", this->field_357);
    d.f("field_358", this->field_358);
}

