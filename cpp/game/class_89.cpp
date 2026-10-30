// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_89::field_1185{};

void class_89::__clinit() {
    class_89::field_1185 = 0;
}

void class_89::__init() {
}

void class_89::method_774() {
    this->field_1197 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    if (this->field_1189 != nullptr) {
        this->field_1189->method_714();
    }
    this->field_1189 = jrt::Ref<class_76>(nullptr);
    this->field_1190 = jrt::Ref<class_59>(nullptr);
    this->field_1191 = jrt::Ref<class_10>(nullptr);
    this->field_1192 = jrt::Ref<class_121>(nullptr);
    this->field_1193 = jrt::Ref<class_121>(nullptr);
    this->field_1188 = false;
    java::lang::System::gc();
}

void class_89::method_775() {
    this->field_1189 = [&]() { jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> __a1 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(79), class_84::field_1116->method_4(81)}); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(62); jrt::Ref<class_76> __o(new class_76()); __o->__init(__a1, __a2); return __o; }();
    this->field_1189->method_715(0, class_21::method_178());
    this->field_1189->method_716(1, class_21::method_180()->field_1141, class_21::method_180()->field_1143);
    this->field_1191 = jrt::New<class_10>();
    this->field_1192 = jrt::New<class_121>(20, (class_84::field_1121 / 3), (class_84::field_1120 - 40));
    this->field_1198 = 0;
    this->field_1187 = (jrt::cast<class_63>(class_84::field_1127->at(1)))->field_740;
    this->field_1193 = jrt::New<class_121>(10, (class_84::field_1121 / 3), (class_84::field_1120 - 20));
    this->field_1195 = 5;
    this->field_1196 = class_84::field_1120 - 10;
    this->field_1197 = jrt::newArray<int32_t>(3);
    this->field_1197->at(0) = (this->field_1196 / 3) - 2;
    this->field_1197->at(1) = this->field_1197->at(0);
    this->field_1197->at(2) = ((this->field_1196 - this->field_1197->at(0)) - this->field_1197->at(1)) - 4;
    this->field_1189->method_702(class_89::field_1185);
    java::lang::System::gc();
    this->field_1188 = true;
}

bool class_89::method_776() {
    return this->field_1198 == 0;
}

bool class_89::method_777(int32_t var1) {
    this->field_1190 = jrt::cast<class_59>(this->field_1189->method_701());
    if (var1 == 256) {
        if (this->field_1194 && (this->field_1186 > int64_t(200))) {
            this->field_1194 = false;
            return true;
        }
        if (this->field_1198 == 4) {
            this->field_1198 = 0;
        } else if (this->field_1198 == 0) {
            if (this->field_1189->method_717() && (this->field_1189->method_701() != nullptr)) {
                if (this->field_1190->method_540()) {
                    this->field_1193->method_939(class_84::field_1116->method_4(84));
                    this->field_1194 = true;
                } else if (this->field_1190->method_536() || this->field_1190->method_535()) {
                    this->field_1191->method_51(jrt::cast<class_59>(this->field_1189->method_701()), (this->field_1189->field_1038 == 2));
                    this->field_1198 = 1;
                }
            }
        } else if (this->field_1198 == 1) {
            this->field_1198 = 0;
        } else if (this->field_1198 == 2) {
            this->field_1198 = 0;
        } else if (this->field_1198 == 3) {
            this->field_1198 = 0;
            this->field_1189->method_715(1, class_21::method_178());
        }
    }
    if (this->field_1194) {
        return true;
    } else {
        if ((var1 == 2) && (this->field_1198 == 0)) {
            this->field_1189->method_704();
        }
        if ((var1 == 64) && (this->field_1198 == 0)) {
            this->field_1189->method_705();
        }
        if ((var1 == 4) && ((this->field_1198 == 4) || (this->field_1198 == 0))) {
            this->field_1189->method_706();
        }
        if ((var1 == 32) && ((this->field_1198 == 4) || (this->field_1198 == 0))) {
            this->field_1189->method_707();
        }
        if (var1 == 8192) {
            if (this->field_1198 == 4) {
                class_89::field_1185 = this->field_1189->field_1038;
                return false;
            }
            if (this->field_1198 == 0) {
                return false;
            }
            if (this->field_1198 == 1) {
                this->field_1198 = 0;
            } else if (this->field_1198 == 5) {
                this->field_1198 = 4;
            } else if (this->field_1198 == 6) {
                this->field_1198 = 1;
                this->field_1187->method_570();
            }
        }
        if (var1 == 16384) {
            if (this->field_1198 == 4) {
                this->field_1198 = 5;
            } else if (this->field_1198 == 0) {
                if (this->field_1190 != nullptr) {
                    if (this->field_1190->method_536() || this->field_1190->method_535()) {
                        this->field_1191->method_51(jrt::cast<class_59>(this->field_1189->method_701()), (this->field_1189->field_1038 == 1));
                        this->field_1198 = 1;
                    }
                    if (this->field_1190->method_540()) {
                        this->field_1193->method_939(class_84::field_1116->method_4(84));
                        this->field_1194 = true;
                    }
                }
            } else if (this->field_1198 == 1) {
                this->field_1198 = 2;
                if (this->field_1189->field_1038 == 0) {
                    if (this->field_1190->method_536()) {
                        int32_t var2 = 0;
                        if (this->field_1190->field_710->field_165 == 5) {
                            var2 = jrt::f2i((float(class_21::method_178()->method_607()) - ((float(this->field_1190->field_710->field_171) / 100.0f) * float(class_21::method_178()->field_866))));
                        }
                        if ((!class_21::method_146()) && (this->field_1190->field_710->field_166 == 42)) {
                            this->field_1192->method_939(class_84::field_1116->method_4(290));
                            this->field_1198 = 2;
                        } else if ((this->field_1190->field_710->field_165 == 5) && (var2 < class_21::method_178()->field_867)) {
                            this->field_1192->method_939(class_21::method_219(class_84::field_1116->method_4(88), jrt::concat(JRT_LIT(u""), (class_21::method_178()->field_867 - var2))));
                            this->field_1198 = 2;
                        } else {
                            class_21::method_178()->method_622(this->field_1190->field_710);
                            class_21::method_197(this->field_1190->method_544());
                            this->field_1189->method_715(0, class_21::method_178());
                            jrt::Ref<class_19> var3{};
                            (var3 = this->field_1190->field_710->method_120())->method_124();
                            var3->field_176 = true;
                            class_21::method_180()->method_748(var3);
                            this->field_1189->method_716(1, class_21::method_180()->field_1141, class_21::method_180()->field_1143);
                            this->field_1192->method_939(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(int32_t(class_1::field_6->at(this->field_1190->method_545())->at(0))); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(90); return jrt::concat(__c1, __c2, __c3); }()));
                        }
                    } else {
                        this->field_1198 = 1;
                    }
                } else if (this->field_1189->field_1038 == 1) {
                    if (this->field_1190->method_536()) {
                        if (!this->field_1190->method_541()) {
                            this->field_1192->method_939(class_21::method_219(class_84::field_1116->method_4(85), jrt::concat(JRT_LIT(u""), (this->field_1190->method_544() - class_21::method_182()))));
                        } else if (!this->field_1190->method_542()) {
                            this->field_1192->method_939(class_84::field_1116->method_4(145));
                        } else if (this->field_1190->method_543() && ((this->field_1190->method_545() != 42) || (!class_21::method_178()->method_609(42)))) {
                            jrt::Ref<class_19> var6{};
                            if (!(var6 = this->field_1190->field_710->method_120())->field_176) {
                                class_21::method_155();
                            }
                            var6->method_124();
                            var6->field_176 = true;
                            class_21::method_178()->method_617(var6);
                            class_21::method_197((-this->field_1190->method_544()));
                            class_21::method_180()->method_750(this->field_1190->field_710);
                            this->field_1189->method_716(1, class_21::method_180()->field_1141, class_21::method_180()->field_1143);
                            this->field_1189->method_715(0, class_21::method_178());
                            this->field_1192->method_939(([&]() { jrt::Ref<java::lang::String> __c4 = class_84::field_1116->method_4(int32_t(class_1::field_6->at(this->field_1190->method_545())->at(0))); jrt::Ref<java::lang::String> __c5 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(91); return jrt::concat(__c4, __c5, __c6); }()));
                            if (this->field_1190->field_710->field_165 == 6) {
                                (jrt::cast<class_63>(class_84::field_1127->at(1)))->field_757->method_446();
                            }
                        } else {
                            this->field_1192->method_939(class_84::field_1116->method_4(144));
                        }
                        this->field_1198 = 2;
                    } else if (this->field_1190->method_535()) {
                        this->field_1198 = 6;
                        for (int32_t var7 = 0; var7 < class_21::method_180()->field_1143->length; var7++) {
                            if (this->field_1190->method_545() == class_21::method_180()->field_1143->at(var7)->field_863) {
                                this->field_1187->method_569(var7);
                                break;
                            }
                        }
                    }
                }
            } else if (this->field_1198 == 6) {
                if (this->field_1190->field_709->method_603() > (class_21::method_182() + class_21::method_178()->method_603())) {
                    this->field_1192->method_939(class_21::method_219(class_84::field_1116->method_4(85), jrt::concat(JRT_LIT(u""), ((this->field_1190->method_544() - class_21::method_182()) - class_21::method_178()->method_603()))));
                    this->field_1198 = 2;
                } else if (this->field_1190->field_709->field_869 < class_21::method_178()->method_623()) {
                    this->field_1192->method_939(class_21::method_219(class_84::field_1116->method_4(86), jrt::concat(JRT_LIT(u""), (class_21::method_178()->field_869 - this->field_1190->field_709->field_869))));
                    this->field_1198 = 2;
                } else if (jrt::f2i((float(this->field_1190->field_709->method_607()) + ((float(class_21::method_178()->field_875) / 100.0f) * float(this->field_1190->field_709->method_607())))) < class_21::method_178()->field_867) {
                    this->field_1192->method_939(([&]() { jrt::Ref<java::lang::String> __c7 = class_84::field_1116->method_4(87); jrt::Ref<java::lang::String> __c8 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c9 = class_21::method_219(class_84::field_1116->method_4(88), jrt::concat(JRT_LIT(u""), (class_21::method_178()->field_867 - this->field_1190->field_709->method_607()))); return jrt::concat(__c7, __c8, __c9); }()));
                    this->field_1198 = 2;
                } else {
                    int32_t var8 = 0;
                    for (int32_t var9 = 0; var9 < class_21::method_180()->field_1143->length; var9++) {
                        if (this->field_1190->method_545() == class_21::method_180()->field_1143->at(var9)->field_863) {
                            var8 = var9;
                            break;
                        }
                    }
                    class_21::method_197((class_21::method_178()->method_603() - this->field_1190->field_709->method_603()));
                    jrt::Ref<class_68> var10{};
                    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var4 = (var10 = class_21::method_178())->field_885;
                    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var5 = var10->field_886;
                    class_21::method_179(class_90::method_783()->at(this->field_1190->field_709->field_863)->method_627());
                    class_21::method_178()->field_884 = this->field_1190->field_709->field_884;
                    class_21::method_178()->method_629();
                    class_21::method_178()->method_616(var4);
                    class_21::method_178()->method_611(var5);
                    class_21::method_178()->method_628();
                    this->field_1187->method_568(var8, var10->field_863);
                    class_21::method_180()->field_1143->at(var8) = class_90::method_783()->at(var10->field_863)->method_627();
                    class_21::method_180()->field_1143->at(var8)->method_628();
                    class_21::method_180()->field_1143->at(var8)->field_884 = var10->field_884;
                    this->field_1189->method_715(0, class_21::method_178());
                    this->field_1189->method_716(1, class_21::method_180()->field_1141, class_21::method_180()->field_1143);
                    this->field_1192->method_939(([&]() { jrt::Ref<java::lang::String> __c10 = class_84::field_1116->method_4(int32_t(class_1::field_8->at(class_21::method_178()->field_863)->at(0))); jrt::Ref<java::lang::String> __c11 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c12 = class_84::field_1116->method_4(89); return jrt::concat(__c10, __c11, __c12); }()));
                    this->field_1198 = 2;
                }
                this->field_1187->method_570();
            }
        }
        return true;
    }
}

bool class_89::method_778(int32_t var1, int32_t var2) {
    if (!this->field_1188) {
        return true;
    } else {
        this->field_1186 += int64_t(var2);
        if (this->field_1198 == 6) {
            this->field_1187->method_549(var1);
        }
        this->method_779();
        this->field_1190 = jrt::cast<class_59>(this->field_1189->method_701());
        if (this->field_1194) {
            return true;
        } else {
            if (((var1 & 2) != 0) && (this->field_1198 == 1)) {
                this->field_1191->deep3dHeldUp(var2);
            }
            if (((var1 & 64) != 0) && (this->field_1198 == 1)) {
                this->field_1191->deep3dHeldDown(var2);
            }
            return true;
        }
    }
}

void class_89::method_779() {
    org::deep3d::GameUi::controls(1, (-6), (-7), 0);
    if (this->field_1198 != 6) {
        class_67::method_587();
    }
    if (this->field_1198 == 0) {
        this->field_1189->method_718();
        this->field_1189->method_719();
    }
    if (this->field_1198 == 1) {
        this->field_1191->method_54();
    } else if (this->field_1198 == 2) {
        this->field_1189->method_718();
        this->field_1189->method_719();
        this->field_1192->method_944();
    } else if (this->field_1198 == 6) {
        this->field_1190 = jrt::cast<class_59>(this->field_1189->method_701());
        class_58::method_516(class_84::field_1116->method_4(int32_t(class_1::field_8->at(this->field_1190->method_545())->at(0))), (this->field_1195 + (this->field_1196 / 2)), 5, 1, 8);
    }
    if ((!this->field_1194) && (this->field_1198 != 2)) {
        if ((this->field_1198 != 6) && (((this->field_1198 != 1) || (this->field_1189->field_1038 != 1)) || this->field_1190->method_535())) {
            if (((this->field_1198 == 1) && (this->field_1189->field_1038 == 0)) && (!this->field_1190->method_535())) {
                [&]() { jrt::Ref<java::lang::String> __a1 = class_84::field_1116->method_4(61); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(65); return class_67::method_593(__a1, __a2); }();
            } else if (((this->field_1198 == 1) && (this->field_1189->field_1038 == 1)) && this->field_1190->method_535()) {
                [&]() { jrt::Ref<java::lang::String> __a3 = class_84::field_1116->method_4(225); jrt::Ref<java::lang::String> __a4 = class_84::field_1116->method_4(65); return class_67::method_593(__a3, __a4); }();
            } else if (((this->field_1198 == 1) && (this->field_1189->field_1038 == 0)) && this->field_1190->method_535()) {
                class_67::method_593(JRT_LIT(u""), class_84::field_1116->method_4(65));
            } else {
                [&]() { jrt::Ref<java::lang::String> __a5 = class_84::field_1116->method_4(226); jrt::Ref<java::lang::String> __a6 = class_84::field_1116->method_4(65); return class_67::method_593(__a5, __a6); }();
            }
        } else {
            [&]() { jrt::Ref<java::lang::String> __a7 = class_84::field_1116->method_4(43); jrt::Ref<java::lang::String> __a8 = class_84::field_1116->method_4(65); return class_67::method_593(__a7, __a8); }();
        }
    } else {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
    }
    if (this->field_1194) {
        this->field_1193->method_944();
    }
}

void class_89::__dumpFields(jrt::Dumper& d) {
    d.f("field_1186", this->field_1186);
    d.f("field_1187", this->field_1187);
    d.f("field_1188", this->field_1188);
    d.f("field_1189", this->field_1189);
    d.f("field_1190", this->field_1190);
    d.f("field_1191", this->field_1191);
    d.f("field_1192", this->field_1192);
    d.f("field_1193", this->field_1193);
    d.f("field_1194", this->field_1194);
    d.f("field_1195", this->field_1195);
    d.f("field_1196", this->field_1196);
    d.f("field_1197", this->field_1197);
    d.f("field_1198", this->field_1198);
}

