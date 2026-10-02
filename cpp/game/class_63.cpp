// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_63::__clinit() {
}

void class_63::__init() {
    class_61::__init();
    this->field_768 = false;
    this->field_769 = false;
}

void class_63::method_552() {
    this->field_756->method_774();
    this->field_756 = jrt::Ref<class_89>(nullptr);
    this->field_757->method_443();
    this->field_757 = jrt::Ref<class_55>(nullptr);
    this->field_758->method_101();
    this->field_758 = jrt::Ref<class_17>(nullptr);
    this->field_738 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_741->method_417();
    this->field_741 = jrt::Ref<class_51>(nullptr);
    this->field_755->method_311();
    this->field_755 = jrt::Ref<class_36>(nullptr);
    this->field_754 = jrt::Ref<class_121>(nullptr);
    if (this->field_740 != nullptr) {
        this->field_740->method_552();
    }
    this->field_740 = jrt::Ref<class_65>(nullptr);
    this->field_777 = false;
    this->field_739 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    java::lang::System::gc();
}

void class_63::method_554() {
    this->field_768 = true;
}

void class_63::method_551() {
    if (this->field_740 == nullptr) {
        this->field_774 = false;
        if (!class_38::method_356()->at(class_21::method_180()->field_1134)) {
            this->field_774 = true;
        }
        this->field_776 = (class_21::method_180()->method_752()) ? 100 : 50;
        int64_t var1 = class_21::field_221;
        class_21::method_131(class_21::method_180());
        if ((class_21::method_212() - var1) > int64_t(30000)) {
            class_35::method_303(class_21::method_180());
        }
        class_21::method_180()->method_746();
        class_49::method_404();
        this->field_740 = jrt::New<class_65>(0);
    }
    if (!this->field_740->field_823) {
        this->field_740->method_551();
    } else {
        class_14::method_84();
        if (this->field_741 == nullptr) {
            this->field_741 = jrt::New<class_51>();
        }
        this->field_743 = false;
        if (this->field_755 == nullptr) {
            this->field_755 = jrt::New<class_36>();
        } else {
            this->field_745 = false;
            if (this->field_756 == nullptr) {
                this->field_756 = jrt::New<class_89>();
                this->field_756->method_775();
            } else {
                this->field_746 = false;
                if (this->field_757 == nullptr) {
                    this->field_757 = jrt::New<class_55>();
                    this->field_757->method_446();
                } else {
                    this->field_747 = false;
                    this->field_742 = true;
                    this->field_759 = jrt::New<class_50>();
                    this->field_749 = false;
                    this->field_762 = jrt::New<class_12>();
                    this->field_751 = false;
                    this->field_753 = false;
                    this->field_738 = jrt::newArray<int32_t>(7);
                    for (int32_t var3 = 0; var3 < this->field_738->length; var3++) {
                        this->field_738->at(var3) = 0;
                        if (var3 == this->field_737) {
                            this->field_738->at(var3) = 1;
                        }
                    }
                    this->field_765 = 1;
                    this->field_766 = (class_84::field_1121 - 32) - (this->field_738->length * 10);
                    this->field_767 = 60;
                    this->field_771 = 0;
                    this->field_769 = false;
                    this->field_770 = false;
                    this->field_736 = int64_t(0);
                    this->field_754 = jrt::New<class_121>(20, (class_84::field_1121 / 2), (class_84::field_1120 - 40));
                    this->field_739 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/logo_"), (class_14::method_70() ? 2 : ((class_21::method_180()->method_752()) ? 0 : 1)), JRT_LIT(u".png")));
                    if (!this->field_768) {
                        this->method_556();
                        if (class_21::method_180()->method_752()) {
                            this->field_771 = class_21::method_178()->method_620();
                            if (this->field_771 > 0) {
                                this->method_555(jrt::concat(class_84::field_1116->method_4(257), JRT_LIT(u"      "), this->field_771, JRT_LIT(u" $")));
                            }
                        } else if ((class_21::method_143() == 12) && (class_21::method_180()->field_1134 == 3)) {
                            this->method_555(class_84::field_1116->method_4(258));
                        }
                        if (class_21::method_143() == 2) {
                            class_21::method_180()->field_1141 = jrt::arrayOf<jrt::Ref<class_19>>({class_90::method_781()->at(0)->method_120()});
                            this->field_756->method_775();
                        }
                        if (((class_21::method_143() == 33) || (class_21::method_143() == 34)) && (class_21::method_180()->field_1134 == class_21::method_137()->field_1152)) {
                            if (!class_120::method_932(37, class_21::method_180()->field_1142)) {
                                class_21::method_180()->field_1142 = class_120::method_936(class_21::method_180()->field_1142, jrt::arrayOf<jrt::Ref<class_120>>({class_90::method_785()->at(37)->method_929(1)}));
                            }
                        } else if (((class_21::method_143() == 36) || (class_21::method_143() == 37)) && (class_21::method_180()->field_1134 == class_21::method_137()->field_1152)) {
                            if (!class_120::method_932(38, class_21::method_180()->field_1142)) {
                                class_21::method_180()->field_1142 = class_120::method_936(class_21::method_180()->field_1142, jrt::arrayOf<jrt::Ref<class_120>>({class_90::method_785()->at(38)->method_929(1)}));
                            }
                        } else if ((((((class_21::method_143() == 41) && class_120::method_932(36, class_21::method_178()->field_886)) || (class_21::method_143() == 42)) && (class_21::method_180()->field_1134 == 14)) && (!class_21::method_178()->method_609(42))) && (!class_21::method_180()->method_747(42))) {
                            class_21::method_180()->method_748(class_90::method_781()->at(42)->method_120());
                            this->field_756->method_775();
                        }
                    }
                    if ((!this->field_769) && (!this->field_768)) {
                        class_21::method_197(this->field_771);
                        class_27::method_277(3);
                        class_21::method_197((-this->field_771));
                        this->field_769 = true;
                    }
                    if (this->field_758 == nullptr) {
                        this->field_758 = jrt::New<class_17>();
                        this->field_758->method_102();
                    }
                    this->field_748 = false;
                    class_84::field_1122->method_768(1);
                    this->field_735 = int64_t(0);
                    class_49::method_403();
                    java::lang::System::gc();
                    this->field_732 = org::deep3d::Det::millis();
                    this->field_733 = org::deep3d::Det::millis();
                    this->field_777 = true;
                    class_67::method_578((!class_21::method_180()->method_752()));
                }
            }
        }
    }
}

void class_63::method_555(jrt::Ref<java::lang::String> var1) {
    this->field_754->method_939(var1);
    this->field_744 = true;
}

void class_63::method_556() {
    if ((!this->field_752) && (!this->field_753)) {
        this->field_772 = jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>>(nullptr);
        jrt::Ref<jrt::Array<int32_t>> var1 = class_14::method_72();
        int32_t var2 = 0;
        for (int32_t var3 = 0; var3 < var1->length; var3++) {
            if (var1->at(var3) > 0) {
                var2++;
            }
        }
        if (var2 > 0) {
            this->field_772 = jrt::newMultiArray<int32_t, 2>({var2, 2});
            var2 = 0;
            for (int32_t var5 = 0; var5 < var1->length; var5++) {
                if (var1->at(var5) > 0) {
                    this->field_772->at((var2++)) = jrt::arrayOf<int32_t>({var5, var1->at(var5)});
                }
            }
            this->field_752 = true;
            this->field_773 = 0;
            this->field_763 = jrt::New<class_122>();
            this->field_763->method_945(this->field_772->at(0)->at(0), this->field_772->at(0)->at(1));
        }
    } else {
        this->field_773++;
        if (this->field_773 >= this->field_772->length) {
            this->field_752 = false;
        } else {
            this->field_763->method_945(this->field_772->at(this->field_773)->at(0), this->field_772->at(this->field_773)->at(1));
        }
    }
}

bool class_63::method_553() {
    return this->field_777;
}

void class_63::method_549(int32_t var1) {
    if (this->field_777) {
        class_67::method_597(false);
        this->field_732 = org::deep3d::Det::millis();
        this->field_734 = this->field_732 - this->field_733;
        this->field_733 = this->field_732;
        this->field_735 = this->field_735 + this->field_734;
        this->field_736 = this->field_736 + this->field_734;
        class_21::method_211(this->field_734);
        class_14::method_80(class_21::method_182());
        if (((((((!this->field_745) && (!this->field_746)) && (!this->field_747)) && (!this->field_748)) && (!this->field_749)) && (!this->field_751)) && (this->field_740 != nullptr)) {
            this->field_740->method_571();
        }
        if (this->field_736 < int64_t(2300)) {
            org::deep3d::GameUi::controls(1, (-5), 0, 0);
            class_58::method_518(class_84::field_1116->method_4((this->field_768 ? 36 : 32)), 5, ((class_84::field_1121 - class_67::method_577()) - class_58::method_527()), 1);
        } else {
            this->field_768 = false;
        }
        if (this->field_736 >= int64_t(2300)) {
            if (!this->field_750) {
                jrt::Ref<class_87> var2{};
                if ((var2 = class_21::method_148(true, int64_t(0))) != nullptr) {
                    this->field_764 = var2;
                }
                if (var2 != nullptr) {
                    this->field_760 = jrt::New<class_56>(var2, 1);
                    this->field_750 = true;
                }
            }
            if ((!this->field_744) && (!this->field_750)) {
                this->method_557();
            }
            int32_t var3 = var1;
            if (this->field_753) {
                var3 = 0;
            }
            if (this->field_751) {
                this->field_762->method_60(var3, int32_t(this->field_734));
            } else {
                if (this->field_750) {
                    if ((this->field_748 || this->field_745) || this->field_746) {
                        class_67::method_587();
                    }
                    this->field_760->method_460(var3, int32_t(this->field_734));
                    this->field_760->method_467();
                } else if (this->field_743) {
                    this->field_741->method_418(var3, int32_t(this->field_734));
                    this->field_741->method_429();
                } else if (this->field_745) {
                    class_67::method_579(int32_t(this->field_734));
                    this->field_755->method_317(var3, int32_t(this->field_734));
                    if ((this->field_755 != nullptr) && this->field_755->method_319()) {
                        if ((this->field_757->method_449() && (this->field_761 == nullptr)) && (!class_84::field_1096)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(360));
                            class_84::field_1096 = true;
                            this->field_753 = true;
                        }
                        if (((!this->field_757->method_449()) && (this->field_761 == nullptr)) && (!class_84::field_1095)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(359));
                            class_84::field_1095 = true;
                            this->field_753 = true;
                        }
                    } else if ((this->field_755 != nullptr) && this->field_755->method_318()) {
                        if ((this->field_757->method_449() && (this->field_761 == nullptr)) && (!class_84::field_1090)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(362));
                            class_84::field_1090 = true;
                            this->field_753 = true;
                        }
                        if (((!this->field_757->method_449()) && (this->field_761 == nullptr)) && (!class_84::field_1089)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(361));
                            class_84::field_1089 = true;
                            this->field_753 = true;
                        }
                    }
                } else if (this->field_746) {
                    class_67::method_579(int32_t(this->field_734));
                    this->field_756->method_778(var3, int32_t(this->field_734));
                } else if (this->field_747) {
                    this->field_757->method_450(var3, int32_t(this->field_734));
                    if (this->field_757 != nullptr) {
                        if ((this->field_757->method_449() && (this->field_761 == nullptr)) && (!class_84::field_1090)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(362));
                            class_84::field_1090 = true;
                            this->field_753 = true;
                        }
                        if (((!this->field_757->method_449()) && (this->field_761 == nullptr)) && (!class_84::field_1089)) {
                            this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(361));
                            class_84::field_1089 = true;
                            this->field_753 = true;
                        }
                    }
                } else if (this->field_748) {
                    class_67::method_579(int32_t(this->field_734));
                    this->field_758->method_104(var3, int32_t(this->field_734));
                } else if (this->field_749) {
                    class_67::method_579(int32_t(this->field_734));
                    this->field_759->method_413(var3, int32_t(this->field_734));
                } else {
                    this->method_558();
                }
                if (this->field_753) {
                    this->field_761->method_460(var1, int32_t(this->field_734));
                    this->field_761->method_468();
                }
            }
        }
    }
}

void class_63::method_557() {
    if (((this->field_774 && (this->field_761 == nullptr)) && (class_21::method_143() == 16)) && (class_21::method_180()->field_1134 != 5)) {
        this->field_761 = jrt::New<class_56>(class_21::method_219(class_84::field_1116->method_4(280), class_21::method_213()));
        this->field_774 = false;
        this->field_753 = true;
    }
    if ((((this->field_774 && (this->field_761 == nullptr)) && (class_21::method_143() == 18)) && (!class_21::method_180()->method_752())) && (class_21::method_180()->field_1134 != 6)) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(281));
        this->field_753 = true;
        this->field_774 = false;
    }
    if (((this->field_761 == nullptr) && (!class_84::field_1103)) && class_21::method_178()->method_605()) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(346));
        this->field_753 = true;
        class_84::field_1103 = true;
    }
    if ((((!this->field_752) && (this->field_761 == nullptr)) && (!class_84::field_1105)) && class_14::method_69()) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(350));
        class_84::field_1105 = true;
        this->field_753 = true;
    }
    if ((((!this->field_752) && (this->field_761 == nullptr)) && (!class_84::field_1106)) && class_14::method_70()) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(351));
        class_84::field_1106 = true;
        this->field_753 = true;
    }
    if (((((!this->field_752) && (this->field_761 == nullptr)) && (!class_84::field_1107)) && (!class_14::method_69())) && class_21::method_146()) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(352));
        class_84::field_1107 = true;
        this->field_753 = true;
    }
    if ((((!this->field_752) && (this->field_761 == nullptr)) && (!this->field_775)) && (class_14::method_76() > 0)) {
        int32_t var1{};
        int32_t var2 = ((var1 = class_14::method_76()) < 4) ? 284 : ((var1 < 7) ? 285 : ((var1 < 12) ? 286 : 287));
        this->field_761 = jrt::New<class_56>(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(283); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u": "); int32_t __c3 = var1; jrt::Ref<java::lang::String> __c4 = JRT_LIT(u"\n"); int32_t __c5 = var1; jrt::Ref<java::lang::String> __c6 = JRT_LIT(u" x "); int32_t __c7 = var1; jrt::Ref<java::lang::String> __c8 = JRT_LIT(u" x "); int32_t __c9 = this->field_776; jrt::Ref<java::lang::String> __c10 = JRT_LIT(u" $\n"); jrt::Ref<java::lang::String> __c11 = class_84::field_1116->method_4(40); jrt::Ref<java::lang::String> __c12 = JRT_LIT(u": "); int32_t __c13 = ((var1 * var1) * this->field_776); jrt::Ref<java::lang::String> __c14 = JRT_LIT(u" $\n\n"); jrt::Ref<java::lang::String> __c15 = class_84::field_1116->method_4(var2); jrt::Ref<java::lang::String> __c16 = JRT_LIT(u"\n"); return jrt::concat(__c1, __c2, __c3, __c4, __c5, __c6, __c7, __c8, __c9, __c10, __c11, __c12, __c13, __c14, __c15, __c16); }()), true);
        this->field_775 = true;
        this->field_753 = true;
    }
}

void class_63::method_558() {
    if (this->field_742) {
        org::deep3d::GameUi::controls(1, (-5), (-7), (-6));
    } else {
        org::deep3d::GameUi::controls(1, (-6), (-7), 0);
    }
    class_84::field_1117->drawImage(this->field_739, 3, 3, 0);
    class_58::method_516(class_21::method_180()->field_1133, (this->field_739->getWidth() + 6), 3, 0, 17);
    [&]() { jrt::Ref<java::lang::String> __a1 = class_84::field_1116->method_4(int32_t(class_1::field_9->at(((class_21::method_175()->at(class_21::method_180()->field_1134)) ? 1 : 0)))); int32_t __a2 = (this->field_739->getWidth() + 6); int32_t __a3 = 13; int32_t __a4 = 1; int32_t __a5 = 17; return class_58::method_516(__a1, __a2, __a3, __a4, __a5); }();
    [&]() { jrt::Ref<java::lang::String> __a6 = jrt::concat(class_84::field_1116->method_4(44), JRT_LIT(u": "), class_21::method_180()->field_1139); int32_t __a7 = (this->field_739->getWidth() + 6); int32_t __a8 = 23; int32_t __a9 = 1; int32_t __a10 = 17; return class_58::method_516(__a6, __a7, __a8, __a9, __a10); }();
    if (this->field_742) {
        class_67::method_591(JRT_LIT(u""), this->field_765, this->field_766, this->field_767, ((12 + ((this->field_738->length + 1) * 10)) - 5));
        class_67::method_585(class_84::field_1116->method_4(62), this->field_765, (this->field_766 + 12), this->field_767, (this->field_738->at(0) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(37), this->field_765, ((this->field_766 + 12) + 10), this->field_767, (this->field_738->at(1) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(73), this->field_765, ((this->field_766 + 12) + 20), this->field_767, (this->field_738->at(2) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(235), this->field_765, ((this->field_766 + 12) + 30), this->field_767, (this->field_738->at(3) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(64), this->field_765, ((this->field_766 + 12) + 40), this->field_767, (this->field_738->at(4) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(66), this->field_765, ((this->field_766 + 12) + 50), this->field_767, (this->field_738->at(5) == 1), false, true);
        class_67::method_585(class_84::field_1116->method_4(241), this->field_765, ((this->field_766 + 12) + 60), this->field_767, (this->field_738->at(6) == 1), false, true);
    } else if (((((((((!this->field_750) && (!this->field_748)) && (!this->field_746)) && (!this->field_747)) && (!this->field_743)) && (!this->field_745)) && (!this->field_744)) && (!this->field_752)) && (!this->field_749)) {
        class_67::method_579(int32_t(this->field_734));
        class_67::method_597(class_67::method_580());
    }
    if (this->field_752) {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
        this->field_763->method_946();
    } else if (this->field_744) {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
        this->field_754->method_944();
    } else {
        [&]() { jrt::Ref<java::lang::String> __a11 = class_84::field_1116->method_4(67); jrt::Ref<java::lang::String> __a12 = class_84::field_1116->method_4(241); return class_67::method_593(__a11, __a12); }();
    }
}

void class_63::method_550(int32_t var1) {
    if (this->field_777) {
        class_21::method_199();
        if (this->field_736 < int64_t(2300)) {
            if (var1 == 256) {
                this->field_736 = int64_t(2301);
                class_67::method_578((!class_21::method_180()->method_752()));
            }
        } else if (this->field_751) {
            if ((((var1 == 131072) || (var1 == 16384)) || (var1 == 8192)) && (!this->field_762->method_59(131072))) {
                this->field_751 = false;
            }
        } else if (this->field_753) {
            if (var1 == 256) {
                this->field_753 = false;
                this->field_761 = jrt::Ref<class_56>(nullptr);
                class_67::method_578((!class_21::method_180()->method_752()));
                if (this->field_775) {
                    class_21::method_197(((class_14::method_76() * class_14::method_76()) * this->field_776));
                    class_14::method_77();
                    this->field_775 = false;
                }
            }
        } else {
            if (var1 == 131072) {
                if (this->field_746) {
                    this->field_762->method_58(class_84::field_1116->method_4(353));
                } else if (this->field_745) {
                    if (this->field_755->method_313() == 1) {
                        this->field_762->method_58(class_84::field_1116->method_4(355));
                    } else {
                        this->field_762->method_58(class_84::field_1116->method_4(356));
                    }
                } else if (this->field_748) {
                    if (this->field_758->method_106() == 0) {
                        this->field_762->method_58(class_84::field_1116->method_4(357));
                    } else {
                        this->field_762->method_58(class_84::field_1116->method_4(358));
                    }
                } else if (this->field_747) {
                    if (this->field_757->method_444()) {
                        this->field_762->method_58(class_84::field_1116->method_4(361));
                    } else {
                        this->field_762->method_58(class_84::field_1116->method_4(362));
                    }
                } else if (this->field_749) {
                    if (this->field_759->method_412()) {
                        this->field_762->method_58(class_84::field_1116->method_4(364));
                    } else {
                        this->field_762->method_58(class_84::field_1116->method_4(363));
                    }
                } else if (!this->field_743) {
                    this->field_762->method_58(class_84::field_1116->method_4(365));
                }
                if (!this->field_743) {
                    this->field_751 = true;
                }
            }
            if (this->field_750) {
                if (!this->field_760->method_459(var1)) {
                    if ((this->field_764->field_1146 == 13) || (this->field_764->field_1146 == 14)) {
                        if (((!this->field_764->field_1161) || (this->field_764->field_1164 != 36)) || (class_21::method_143() == 41)) {
                            class_21::method_178()->method_610(this->field_764->field_1164, this->field_764->field_1165);
                        }
                        this->field_758->method_102();
                    }
                    if (this->field_764->field_1161) {
                        class_21::method_145();
                    } else {
                        class_21::method_141();
                    }
                    class_21::method_197(this->field_764->field_1150);
                    class_21::method_163(this->field_764);
                    this->field_755->method_310();
                    this->field_750 = false;
                    if (this->field_771 > 0) {
                        class_21::method_197(this->field_771);
                        this->field_771 = 0;
                    }
                }
            } else if (this->field_745) {
                if ((((var1 == 32) && this->field_755->method_314()) && (this->field_761 == nullptr)) && (!class_84::field_1088)) {
                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(355));
                    class_84::field_1088 = true;
                    this->field_753 = true;
                }
                if (!this->field_755->method_315(var1)) {
                    this->field_745 = false;
                }
            } else if (this->field_746) {
                if ((((var1 == 32) && this->field_756->method_776()) && (this->field_761 == nullptr)) && (!class_84::field_1086)) {
                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(354));
                    class_84::field_1086 = true;
                    this->field_753 = true;
                }
                if (!this->field_756->method_777(var1)) {
                    this->field_746 = false;
                }
            } else if (this->field_747) {
                if (!this->field_757->method_447(var1)) {
                    this->field_747 = false;
                }
            } else if (this->field_748) {
                if ((((var1 == 32) && this->field_758->method_107()) && (this->field_761 == nullptr)) && (!class_84::field_1092)) {
                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(358));
                    class_84::field_1092 = true;
                    this->field_753 = true;
                }
                if (!this->field_758->method_103(var1)) {
                    this->field_748 = false;
                }
            } else if (this->field_749) {
                if (((var1 == 32) && (this->field_761 == nullptr)) && (!class_84::field_1094)) {
                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(364));
                    class_84::field_1094 = true;
                    this->field_753 = true;
                }
                if (!this->field_759->method_411(var1)) {
                    this->field_749 = false;
                }
            } else if (this->field_752) {
                if (var1 == 256) {
                    this->method_556();
                }
            } else if (!this->field_744) {
                if (this->field_742 && (!this->field_743)) {
                    if (((var1 == 256) && (!this->field_750)) && (!this->field_752)) {
                        {
                            switch (this->field_737) {
                            case 0:
                                this->field_746 = true;
                                if ((this->field_761 == nullptr) && (!class_84::field_1085)) {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(353));
                                    class_84::field_1085 = true;
                                    this->field_753 = true;
                                }
                                return;
                            case 1:
                                if (class_21::method_143() < 9) {
                                    this->field_761 = jrt::New<class_56>(class_21::method_219(class_84::field_1116->method_4(282), class_21::method_213()));
                                    this->field_753 = true;
                                    return;
                                }
                                if ((class_21::method_143() == 42) && (!class_21::method_178()->method_609(42))) {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(289));
                                    this->field_753 = true;
                                    return;
                                }
                                this->field_745 = true;
                                this->field_755->method_312();
                                this->field_735 = int64_t(-150);
                                if ((this->field_761 == nullptr) && (!class_84::field_1087)) {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(356));
                                    class_84::field_1087 = true;
                                    this->field_753 = true;
                                }
                                return;
                            case 2:
                                if (class_21::method_143() < 7) {
                                    this->field_761 = jrt::New<class_56>(class_21::method_219(class_84::field_1116->method_4(282), class_21::method_213()));
                                    this->field_753 = true;
                                    return;
                                }
                                if ((class_21::method_143() == 42) && (!class_21::method_178()->method_609(42))) {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(289));
                                    this->field_753 = true;
                                    return;
                                }
                                this->field_747 = true;
                                this->field_757->method_445(jrt::Ref<class_87>(nullptr));
                                return;
                            case 3:
                                if (!class_21::method_180()->method_752()) {
                                    this->field_748 = true;
                                    if ((this->field_761 == nullptr) && (!class_84::field_1091)) {
                                        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(357));
                                        class_84::field_1091 = true;
                                        this->field_753 = true;
                                        return;
                                    }
                                } else {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(256));
                                    this->field_753 = true;
                                }
                                return;
                            case 4:
                                this->field_749 = true;
                                this->field_759->method_410();
                                if ((this->field_761 == nullptr) && (!class_84::field_1093)) {
                                    this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(363));
                                    class_84::field_1093 = true;
                                    this->field_753 = true;
                                }
                                return;
                            case 5:
                                this->field_743 = true;
                                this->field_741->method_427(2);
                                return;
                            case 6:
                                this->method_559();
                                return;
                            }
                        }
                    }
                    if (var1 == 64) {
                        this->field_738->at(this->field_737) = 0;
                        if (this->field_737 < (this->field_738->length - 1)) {
                            this->field_737++;
                        } else {
                            this->field_737 = 0;
                        }
                        this->field_738->at(this->field_737) = 1;
                    }
                    if (var1 == 2) {
                        this->field_738->at(this->field_737) = 0;
                        if (this->field_737 > 0) {
                            this->field_737--;
                        } else {
                            this->field_737 = this->field_738->length - 1;
                        }
                        this->field_738->at(this->field_737) = 1;
                    }
                    if (var1 == 16384) {
                        this->field_742 = !this->field_742;
                        return;
                    }
                }
                if ((!this->field_743) && (var1 == 8192)) {
                    this->method_559();
                } else if (this->field_743) {
                    this->field_741->method_430(var1);
                    if (var1 == 4) {
                        this->field_741->method_422();
                    }
                    if (var1 == 32) {
                        this->field_741->method_424();
                    }
                    if (var1 == 2) {
                        this->field_741->method_420(int32_t(this->field_734));
                    }
                    if (var1 == 64) {
                        this->field_741->method_421(int32_t(this->field_734));
                    }
                    if (var1 == 16384) {
                        this->field_741->method_426();
                    }
                    if ((var1 == 8192) && this->field_741->method_425()) {
                        this->field_743 = !this->field_743;
                        this->field_741->method_427(2);
                    }
                    if (((var1 == 256) && (!this->field_750)) && (!this->field_752)) {
                        this->field_774 = false;
                        if (this->field_741->method_419()) {
                            this->field_743 = false;
                        }
                    }
                } else {
                    if (var1 == 16384) {
                        this->field_742 = !this->field_742;
                    }
                }
            } else {
                if (var1 == 4) {
                    this->field_754->method_942();
                }
                if (var1 == 32) {
                    this->field_754->method_943();
                }
                if (var1 == 256) {
                    if (this->field_754->method_941() && this->field_770) {
                        this->field_770 = false;
                        class_21::method_140();
                        class_21::method_131(class_21::method_180());
                        class_21::field_220 = -1;
                        class_21::field_218 = -1;
                        class_21::field_219 = -1;
                        class_14::method_85();
                        class_84::field_1126->method_439(class_84::field_1127->at(2));
                    } else if (this->field_771 > 0) {
                        class_21::method_197(this->field_771);
                        this->field_771 = 0;
                    }
                    this->field_744 = false;
                }
            }
        }
    }
}

void class_63::method_559() {
    if (class_21::method_143() == 3) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(288));
        this->field_753 = true;
    } else if ((class_21::method_143() == 42) && (!class_21::method_178()->method_609(42))) {
        this->field_761 = jrt::New<class_56>(class_84::field_1116->method_4(289));
        this->field_753 = true;
    } else {
        if (((!this->field_744) && (!this->field_750)) && (!this->field_752)) {
            this->field_754->method_940(class_84::field_1116->method_4(234), true);
            this->field_754->method_942();
            this->field_744 = true;
            this->field_770 = true;
        }
    }
}

void class_63::__dumpFields(jrt::Dumper& d) {
    class_61::__dumpFields(d);
    d.f("field_732", this->field_732);
    d.f("field_733", this->field_733);
    d.f("field_734", this->field_734);
    d.f("field_735", this->field_735);
    d.f("field_736", this->field_736);
    d.f("field_737", this->field_737);
    d.f("field_738", this->field_738);
    d.f("field_739", this->field_739);
    d.f("field_740", this->field_740);
    d.f("field_741", this->field_741);
    d.f("field_742", this->field_742);
    d.f("field_743", this->field_743);
    d.f("field_744", this->field_744);
    d.f("field_745", this->field_745);
    d.f("field_746", this->field_746);
    d.f("field_747", this->field_747);
    d.f("field_748", this->field_748);
    d.f("field_749", this->field_749);
    d.f("field_750", this->field_750);
    d.f("field_751", this->field_751);
    d.f("field_752", this->field_752);
    d.f("field_753", this->field_753);
    d.f("field_754", this->field_754);
    d.f("field_755", this->field_755);
    d.f("field_756", this->field_756);
    d.f("field_757", this->field_757);
    d.f("field_758", this->field_758);
    d.f("field_759", this->field_759);
    d.f("field_760", this->field_760);
    d.f("field_761", this->field_761);
    d.f("field_762", this->field_762);
    d.f("field_763", this->field_763);
    d.f("field_764", this->field_764);
    d.f("field_765", this->field_765);
    d.f("field_766", this->field_766);
    d.f("field_767", this->field_767);
    d.f("field_768", this->field_768);
    d.f("field_769", this->field_769);
    d.f("field_770", this->field_770);
    d.f("field_771", this->field_771);
    d.f("field_772", this->field_772);
    d.f("field_773", this->field_773);
    d.f("field_774", this->field_774);
    d.f("field_775", this->field_775);
    d.f("field_776", this->field_776);
    d.f("field_777", this->field_777);
}

