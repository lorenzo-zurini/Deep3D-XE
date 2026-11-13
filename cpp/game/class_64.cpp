// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_64::__clinit() {
}

void class_64::__init() {
    class_61::__init();
}

void class_64::method_552() {
    if (this->field_787 != nullptr) {
        this->field_787->method_680();
    }
    this->field_787 = jrt::Ref<class_70>(nullptr);
    if (this->field_804 != nullptr) {
        this->field_804->method_458();
    }
    this->field_804 = jrt::Ref<class_56>(nullptr);
    this->field_794 = false;
    this->field_788 = jrt::Ref<class_106>(nullptr);
    if (this->field_799 != nullptr) {
        this->field_799->method_271();
    }
    this->field_799 = jrt::Ref<class_26>(nullptr);
    if (this->field_801 != nullptr) {
        this->field_801->method_388();
    }
    this->field_801 = jrt::Ref<class_46>(nullptr);
    if (this->field_802 != nullptr) {
        this->field_802->method_297();
    }
    this->field_802 = jrt::Ref<class_34>(nullptr);
    class_69::method_632();
    if (this->field_803 != nullptr) {
        this->field_803->method_417();
    }
    this->field_790->method_368(jrt::Ref<class_102>(nullptr));
    this->field_790->method_369(jrt::Ref<class_102>(nullptr));
    this->field_789 = jrt::Ref<class_104>(nullptr);
    this->field_788 = jrt::Ref<class_106>(nullptr);
    this->field_803 = jrt::Ref<class_51>(nullptr);
    this->field_800 = jrt::Ref<class_118>(nullptr);
    this->field_786 = false;
    this->field_807 = jrt::Ref<class_2>(nullptr);
    java::lang::System::gc();
}

void class_64::method_551() {
    if (this->field_799 == nullptr) {
        this->field_799 = jrt::New<class_26>();
    }
    if (this->field_799->method_240()) {
        this->method_560();
        class_69::method_631();
        this->field_797 = this->field_799->field_291;
        class_84::field_1122->method_773();
        if (class_21::field_220 >= 0) {
            this->field_787->field_969->method_327(class_21::field_220);
        }
        if (class_21::field_218 >= 0) {
            this->field_787->field_969->method_328(class_21::field_218);
        }
        if (class_21::field_219 >= 0) {
            this->field_787->field_969->method_329(class_21::field_219);
        }
        this->field_787->method_649();
        class_21::field_220 = class_21::method_178()->field_864;
        class_21::field_218 = class_21::method_178()->field_871;
        class_21::field_219 = class_21::method_178()->field_872;
        this->field_817 = false;
        this->field_811 = false;
        this->field_813 = false;
        this->field_814 = false;
        int32_t var1{};
        if (((var1 = class_21::method_178()->field_891) >= 0) && (this->field_787->field_969->field_359 != nullptr)) {
            if (var1 >= this->field_787->field_969->field_359->length) {
                var1 = 0;
            }
            while (var1 != this->field_787->field_987) {
                this->field_787->method_661();
            }
        }
        class_67::method_597(false);
        class_69::method_634((-1), (-1), JRT_LIT(u""));
        java::lang::System::gc();
        this->field_779 = org::deep3d::Det::millis();
        this->field_780 = org::deep3d::Det::millis();
        this->field_784 = int64_t(0);
        this->field_785 = int64_t(0);
        this->field_786 = true;
    }
}

void class_64::method_560() {
    org::deep3d::Remaster::newScene();
    this->field_787 = this->field_799->field_272;
    this->field_802 = jrt::New<class_34>();
    this->field_802->method_298(this->field_799->field_280);
    this->field_788 = class_106::method_886(class_84::field_1120, class_84::field_1121, org::deep3d::Config::flightFov(), 100, org::deep3d::Config::enhanced ? 4194304 : 31768);
    this->deep3dFov = org::deep3d::Config::flightFov();
    this->field_798 = this->deep3dFov;
    this->field_789 = jrt::New<class_104>();
    this->field_789->method_879(jrt::Ref<class_102>(this->field_788));
    class_84::field_1110->method_24(this->field_788);
    this->field_790 = jrt::New<class_42>(jrt::Ref<class_102>(this->field_787->field_970), jrt::Ref<class_102>(this->field_788));
    this->field_790->deep3dDolly = class_64::deep3dDolly();
    this->field_791 = jrt::New<class_5>(jrt::Ref<class_102>(this->field_787->field_970), jrt::Ref<class_102>(this->field_788));
    this->field_791->field_53 = false;
    this->field_789->method_880(jrt::Ref<class_0>(this->field_791));
    this->field_789->method_880(jrt::Ref<class_0>(this->field_790));
    this->field_801 = jrt::New<class_46>(this->field_799);
    this->field_797 = this->field_799->field_291;
    class_69::method_638(jrt::Ref<java::lang::String>(nullptr));
    this->field_800 = jrt::New<class_118>(this->field_790, this->field_791, this->field_799);
    class_118::method_916(this->field_790, this->field_799);
    this->field_792 = false;
    this->field_796 = false;
    this->field_778 = 0;
    this->field_793 = false;
    this->field_795 = false;
    this->field_784 = int64_t(0);
    this->field_785 = int64_t(0);
    this->field_812 = false;
    this->field_809 = false;
    this->field_810 = false;
    this->field_815 = false;
    this->field_779 = org::deep3d::Det::millis();
    this->field_780 = org::deep3d::Det::millis();
}

bool class_64::method_553() {
    return this->field_786;
}

void class_64::method_549(int32_t var1) {
    {
        try {
            if (this->field_786) {
                this->field_779 = org::deep3d::Det::millis();
                this->field_781 = this->field_779 - this->field_780;
                this->field_780 = this->field_779;
                this->field_783 = this->field_783 + this->field_781;
                this->field_782 = this->field_782 + this->field_781;
                if (this->field_793) {
                    org::deep3d::Remaster::frozen();
                }
                if (!this->field_793) {
                    this->field_784 = this->field_784 + this->field_781;
                    if (!this->field_795) {
                        this->field_785 = this->field_785 + this->field_781;
                    }
                    class_21::method_211(this->field_781);
                    class_67::method_579(int32_t(this->field_781));
                }
                if (!this->field_796) {
                    if (this->field_793) {
                        if (((((!this->field_794) && (!this->field_812)) && (!this->field_809)) && (!this->field_810)) && (!this->field_817)) {
                            this->field_803->method_418(var1, int32_t(this->field_781));
                            if (this->field_782 > int64_t(150)) {
                                this->field_782 = int64_t(0);
                                if ((var1 & 2) != 0) {
                                    this->field_803->method_420(int32_t(this->field_781));
                                }
                                if ((var1 & 64) != 0) {
                                    this->field_803->method_421(int32_t(this->field_781));
                                }
                            }
                        }
                        if (!this->field_786) {
                            return;
                        }
                        this->field_799->method_266(this->field_781);
                        this->field_787->method_681((!this->field_795));
                        class_84::field_1111->method_683(class_84::field_1117);
                        class_84::field_1110->method_26();
                        class_84::field_1111->method_684(class_84::field_1117);
                        if (this->field_812) {
                            this->field_807->method_8();
                            return;
                        }
                        if ((!this->field_809) && (!this->field_810)) {
                            if (this->field_817) {
                                this->field_805->method_460(var1, int32_t(this->field_781));
                                if (this->field_811) {
                                    this->field_806->method_450(0, int32_t(this->field_781));
                                }
                                this->field_805->method_468();
                                return;
                            }
                            if (this->field_794) {
                                class_67::method_579(int32_t(this->field_781));
                                this->field_804->method_460(var1, int32_t(this->field_781));
                                this->field_804->method_467();
                                return;
                            }
                            this->field_803->method_429();
                            return;
                        }
                        this->field_808->method_944();
                        return;
                    }
                    if ((((this->field_800->field_1447 || (!this->field_800->field_1446)) && (!this->field_809)) && (!this->field_810)) && this->method_566(var1, int32_t(this->field_781))) {
                        return;
                    }
                    if (((((!class_84::field_1104) && (class_21::method_143() > 14)) && (this->field_784 > int64_t(20000))) && (!class_21::method_178()->method_605())) && (this->field_799->field_273 == nullptr)) {
                        this->field_793 = true;
                        if (this->field_805 == nullptr) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(347));
                        }
                        this->field_817 = true;
                        class_84::field_1104 = true;
                    }
                    if ((!class_84::field_1099) && (this->field_787->field_1004 < class_21::method_178()->field_889)) {
                        this->field_793 = true;
                        if (this->field_805 == nullptr) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(344));
                        }
                        this->field_817 = true;
                        class_84::field_1099 = true;
                    }
                    if ((!class_84::field_1100) && (this->field_787->field_1004 > class_21::method_178()->field_890)) {
                        this->field_793 = true;
                        if (this->field_805 == nullptr) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(345));
                        }
                        this->field_817 = true;
                        class_84::field_1100 = true;
                    }
                    if ((!class_84::field_1101) && (class_21::method_172() == 1)) {
                        this->field_793 = true;
                        if (this->field_805 == nullptr) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(348));
                        }
                        this->field_817 = true;
                        class_84::field_1101 = true;
                    }
                    if ((((!class_84::field_1102) && class_69::method_641()) && (class_21::method_143() != 7)) && (class_21::method_180()->field_1134 != 1)) {
                        this->field_793 = true;
                        if (this->field_805 == nullptr) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(349));
                        }
                        this->field_817 = true;
                        class_84::field_1102 = true;
                    }
                    if ((((this->field_785 > int64_t(3000)) && (!this->field_794)) && (!class_21::method_132()->field_1162)) && (!class_21::method_132()->field_1163)) {
                        this->method_565();
                    }
                }
                if (this->field_787->field_994) {
                    this->field_798 = org::deep3d::Config::flightFov() + jrt::f2i((this->field_787->method_652() * 400.0f));
                    this->field_788->method_882(this->field_798);
                } else if (this->deep3dFov != org::deep3d::Config::flightFov()) {
                    this->field_798 += (org::deep3d::Config::flightFov() - this->deep3dFov);
                    this->field_788->method_882(this->field_798);
                }
                if (this->field_790 != nullptr) {
                    this->field_790->deep3dDolly = class_64::deep3dDolly();
                }
                this->deep3dFov = org::deep3d::Config::flightFov();
                if ((class_21::method_132()->field_1162 || this->field_796) || (!this->method_564())) {
                    if (!this->field_796) {
                        this->method_563();
                    }
                    this->field_795 = this->field_800->method_913(int32_t(this->field_781), this->field_790, this->field_807);
                    this->method_561();
                    this->method_562();
                    if ((!this->field_796) && (!this->field_795)) {
                        org::deep3d::MouseFlight::flying();
                        if (((this->field_787->field_987 >= 0) && this->field_792) && (!this->field_787->method_662())) {
                            this->field_787->method_656(this->field_781);
                        }
                        if (org::deep3d::AnalogInput::active()) {
                            var1 &= (-103);
                            if (this->field_787->field_1007) {
                                class_69::method_633(7, this->field_787);
                            } else {
                                float var90 = -org::deep3d::AnalogInput::y();
                                [&]() { auto __r = this->field_787; int64_t __a1 = this->field_781; float __a2 = (-org::deep3d::AnalogInput::x()); float __a3 = ((class_84::field_1082 && (!org::deep3d::AnalogInput::mouseSteering())) ? var90 : (-var90)); return __r->steerAnalog(__a1, __a2, __a3); }();
                            }
                        }
                        if ((var1 & 4) != 0) {
                            if (this->field_787->field_1007) {
                                class_69::method_633(7, this->field_787);
                            } else {
                                this->field_787->method_673(this->field_781);
                            }
                        }
                        if ((var1 & 32) != 0) {
                            if (this->field_787->field_1007) {
                                class_69::method_633(7, this->field_787);
                            } else {
                                this->field_787->method_674(this->field_781);
                            }
                        }
                        if ((var1 & 2) != 0) {
                            if (this->field_787->field_1007) {
                                class_69::method_633(7, this->field_787);
                            } else if (class_84::field_1082) {
                                this->field_787->method_675(this->field_781);
                            } else {
                                this->field_787->method_676(this->field_781);
                            }
                        }
                        if ((var1 & 64) != 0) {
                            if (this->field_787->field_1007) {
                                class_69::method_633(7, this->field_787);
                            } else if (class_84::field_1082) {
                                this->field_787->method_676(this->field_781);
                            } else {
                                this->field_787->method_675(this->field_781);
                            }
                        }
                        if ((var1 & 256) != 0) {
                            this->field_787->method_656(this->field_781);
                        }
                    }
                    if (this->field_800->field_1446 && (class_21::method_143() == 1)) {
                        if (this->field_783 > int64_t(68000)) {
                            this->field_783 = int64_t(0);
                        } else if ((this->field_783 > int64_t(8750)) && (this->field_816 == 2)) {
                            this->field_816++;
                            class_84::field_1122->method_768(0);
                        } else if (((this->field_783 > int64_t(3500)) && (this->field_816 == 0)) || ((this->field_783 > int64_t(7000)) && (this->field_816 == 1))) {
                            this->field_816++;
                            class_84::field_1122->method_770(0);
                        }
                    } else if (this->field_783 > int64_t(10000)) {
                        [&]() { auto __r = class_84::field_1122; int32_t __a4 = class_88::field_1174->at(class_84::field_1123->nextInt(class_88::field_1174->length)); int32_t __a5 = class_16::method_97(60, class_84::field_1123->nextInt(class_84::field_1122->field_1182)); return __r->method_769(__a4, __a5); }();
                        this->field_783 = int64_t(0);
                    }
                }
            }
        } catch (const jrt::Thrown& __ex6) {
            if (jrt::isInstance<java::lang::Exception>(__ex6.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex6.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_64::method_561() {
    {
        try {
            this->field_799->method_267(this->field_781);
            this->field_799->method_265(this->field_781);
            this->field_787->method_671(this->field_781);
            this->field_787->method_681((!this->field_795));
            class_84::field_1111->method_683(class_84::field_1117);
            // Deep3D-PC: a demo's free camera, for the draw only (the game keeps its own)
            jrt::Ref<class_3> deep3dAt = this->field_787->field_970->method_849(jrt::New<class_3>());
            org::deep3d::Demo::sub(deep3dAt->field_37, deep3dAt->field_38, deep3dAt->field_39);
            bool deep3dFree = org::deep3d::Demo::freeCamera(this->field_788);
            this->field_789->method_839(true);
            class_84::field_1110->method_27(org::deep3d::Det::millis());
            if (deep3dFree) {
                org::deep3d::Demo::gameCamera(this->field_788);
            }
            class_84::field_1111->method_684(class_84::field_1117);
            if (org::deep3d::Demo::hudHidden()) {
                org::deep3d::gl::GLBackend::recorder().muted = true;
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                class_84::field_1111->method_684(class_84::field_1117);
                var2->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_64::method_562() {
    if (this->field_795) {
        if ((class_21::method_143() > 1) && (!this->field_800->field_1456)) {
            class_84::field_1113->method_294();
        } else {
            class_69::method_646();
        }
        class_69::method_647();
        if (!this->field_800->field_1456) {
            class_69::method_642(this->field_781, this->field_787, true);
        }
    } else if (this->field_796) {
        class_58::method_516(class_84::field_1116->method_4(139), (class_84::field_1120 / 2), 20, 0, 8);
        if (this->field_785 > int64_t(3000)) {
            this->field_808->method_944();
        }
    } else {
        this->field_787->method_682((!this->field_795), this->field_788);
        this->field_801->method_390(this->field_787->field_969, this->field_788);
        class_69::method_644((this->field_793 ? int64_t(0) : this->field_781), (int64_t(this->field_797) - this->field_784), this->field_787, this->field_792);
    }
    if (!this->field_796) {
        this->field_802->method_301(this->field_784, this->field_787);
    }
}

void class_64::method_563() {
    if (this->field_787->method_659() <= 0) {
        this->field_796 = true;
        class_84::field_1116->method_4(139);
    }
    if (this->field_799->method_270(int32_t(this->field_781))) {
        if (this->field_804 == nullptr) {
            this->field_804 = jrt::New<class_56>();
        }
        this->field_804->method_457(class_21::method_132(), 2);
        this->field_794 = true;
        this->field_793 = true;
    }
    if (this->field_785 > int64_t(3000)) {
        this->field_785 = int64_t(0);
        if (((this->field_797 > 0) && (this->field_784 > int64_t(this->field_797))) && (!this->field_799->field_289->method_223())) {
            if (this->field_804 == nullptr) {
                this->field_804 = jrt::New<class_56>();
            }
            this->field_804->method_457(class_21::method_132(), 2);
            this->field_794 = true;
            this->field_793 = true;
        }
    }
    if (this->field_796) {
        this->field_785 = int64_t(0);
        this->field_790->method_371();
        class_84::method_736(0);
        if (this->field_808 == nullptr) {
            this->field_808 = jrt::New<class_121>();
        }
        this->field_808->method_940(class_84::field_1116->method_4(276), true);
    }
}

bool class_64::method_564() {
    if (this->field_785 > int64_t(3000)) {
        jrt::Ref<class_87> var1 = class_21::method_148(false, this->field_784);
        if (this->field_799->method_268(int32_t(this->field_784)) || (var1 != nullptr)) {
            if (class_21::method_132()->field_1161 && (class_21::method_143() == 27)) {
                class_21::method_145();
                this->field_799->method_269();
                class_21::method_133(class_87::field_1145);
            } else {
                if (!class_21::method_132()->field_1161) {
                    class_21::method_141();
                }
                if (class_21::method_132()->field_1161 && ((!class_21::method_132()->field_1161) || (!class_56::method_456(class_21::method_143())))) {
                    return false;
                }
                if (this->field_804 == nullptr) {
                    this->field_804 = jrt::New<class_56>();
                }
                this->field_804->method_457(((var1 != nullptr) ? var1 : class_21::method_132()), 1);
                this->field_794 = true;
                this->field_793 = true;
            }
            return true;
        }
    }
    return false;
}

void class_64::method_565() {
    if (((((((!this->field_800->field_1447) || ((!class_56::method_455(class_21::method_143())) && class_21::method_132()->field_1161)) || class_21::method_132()->method_754()) || (class_21::method_132()->field_1146 == 13)) || (class_21::method_132()->field_1146 == 14)) || (!class_21::method_132()->field_1171)) && (!class_21::method_139())) {
        if (((class_21::method_132()->field_1161 && (class_21::method_143() == 27)) && (!this->field_815)) && this->field_799->field_273->at(0)->field_1225->field_375) {
            this->field_804 = jrt::New<class_56>(class_21::method_132(), 3);
            this->field_793 = true;
            this->field_794 = true;
            this->field_815 = true;
        }
    } else if (class_21::method_132()->field_1161 || (class_21::method_132()->field_1146 != 8)) {
        if (this->field_804 == nullptr) {
            if (class_21::method_139()) {
                this->field_804 = jrt::New<class_56>(class_21::method_135(), 2);
            } else {
                this->field_804 = jrt::New<class_56>(class_21::method_132(), 0);
            }
        }
        this->field_793 = true;
        this->field_794 = true;
    }
}

bool class_64::method_566(int32_t var1, int32_t var2) {
    this->field_813 = this->field_799->method_263(this->field_787->method_664());
    this->field_814 = this->field_799->method_264(this->field_787->method_664());
    if ((!class_21::method_132()->method_754()) && (class_21::method_132()->field_1146 != 8)) {
        if ((!this->field_814) && (!this->field_813)) {
            class_69::method_638(jrt::Ref<java::lang::String>(nullptr));
        } else {
            class_69::method_638(class_84::field_1116->method_4(269));
        }
        return false;
    } else {
        if (this->field_813 && (jrt::cast<class_99>(this->field_799->field_276->at(1)))->field_1305) {
            class_21::field_220 = this->field_787->field_969->field_363;
            class_21::field_218 = this->field_787->field_969->field_365;
            class_21::field_219 = this->field_787->field_969->field_367;
            if (this->field_787->field_1007 && (class_26::field_302 != nullptr)) {
                if (!this->field_809) {
                    if (this->field_808 == nullptr) {
                        this->field_808 = jrt::New<class_121>();
                    }
                    this->field_808->method_940(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(334); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u": "); jrt::Ref<java::lang::String> __c3 = class_26::field_302->field_1133; jrt::Ref<java::lang::String> __c4 = JRT_LIT(u"\n"); jrt::Ref<java::lang::String> __c5 = class_84::field_1116->method_4(247); return jrt::concat(__c1, __c2, __c3, __c4, __c5); }()), true);
                    this->field_808->method_942();
                    this->field_809 = true;
                    this->field_793 = true;
                    this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                }
                return false;
            }
            if (this->field_811) {
                if ((!class_84::field_1089) && (!this->field_806->method_449())) {
                    this->field_793 = true;
                    if (this->field_805 == nullptr) {
                        this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(361));
                    }
                    this->field_817 = true;
                    class_84::field_1089 = true;
                } else if ((!class_84::field_1090) && this->field_806->method_449()) {
                    this->field_793 = true;
                    if (this->field_805 == nullptr) {
                        this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(362));
                    }
                    this->field_817 = true;
                    class_84::field_1090 = true;
                }
                this->field_811 = this->field_806->method_450(var1, var2);
                this->field_782 = int64_t(0);
                return true;
            }
            if (((!this->field_787->field_1007) && (class_21::method_143() > 2)) && ((class_21::method_143() != 6) || (class_21::method_180()->field_1134 != 0))) {
                class_69::method_638(class_84::field_1116->method_4(270));
                if (!class_84::field_1097) {
                    this->field_793 = true;
                    if (this->field_805 == nullptr) {
                        this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(342));
                    }
                    this->field_817 = true;
                    class_84::field_1097 = true;
                }
            }
            if (((var1 & 131072) != 0) || this->field_787->method_668()) {
                if (class_26::field_302 != nullptr) {
                    if (!this->field_809) {
                        if (this->field_808 == nullptr) {
                            this->field_808 = jrt::New<class_121>();
                        }
                        this->field_808->method_940(([&]() { jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(334); jrt::Ref<java::lang::String> __c7 = JRT_LIT(u": "); jrt::Ref<java::lang::String> __c8 = class_26::field_302->field_1133; jrt::Ref<java::lang::String> __c9 = JRT_LIT(u"\n"); jrt::Ref<java::lang::String> __c10 = class_84::field_1116->method_4(247); return jrt::concat(__c6, __c7, __c8, __c9, __c10); }()), true);
                        this->field_808->method_942();
                        this->field_809 = true;
                        this->field_793 = true;
                        this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                    }
                    return false;
                }
                if (((class_21::method_143() != 1) && (class_21::method_143() != 2)) && ((class_21::method_143() != 6) || (class_21::method_180()->field_1134 != 0))) {
                    if (this->field_806 == nullptr) {
                        this->field_806 = jrt::New<class_55>();
                    }
                    this->field_806->method_446();
                    this->field_806->method_445(jrt::Ref<class_87>(nullptr));
                    this->field_806->field_658 = true;
                    this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                    this->field_811 = true;
                    return true;
                }
                this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(291));
                this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                this->field_817 = true;
                this->field_793 = true;
            }
        } else if (this->field_814) {
            if (!this->field_787->field_1007) {
                class_69::method_638(class_84::field_1116->method_4(271));
                if ((!class_84::field_1098) && (this->field_784 > int64_t(20000))) {
                    this->field_793 = true;
                    if (this->field_805 == nullptr) {
                        this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(343));
                    }
                    this->field_817 = true;
                    class_84::field_1098 = true;
                }
            }
            if (this->field_787->method_669()) {
                if (((class_21::method_143() != 5) || (class_21::method_180()->field_1134 != 0)) && ((class_21::method_143() != 6) || (class_21::method_180()->field_1134 == 0))) {
                    OpenSea::beforeDock();
                    class_14::method_67(this->field_787);
                    class_84::field_1126->method_439(class_84::field_1127->at(1));
                    return true;
                }
                this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(((class_21::method_143() == 5) ? 292 : 291)));
                this->field_817 = true;
                this->field_793 = true;
                this->field_787->method_667(jrt::Ref<class_91>(nullptr));
            }
            if (((var1 & 131072) != 0) && (!this->field_787->method_668())) {
                if (!this->field_810) {
                    if (this->field_808 == nullptr) {
                        this->field_808 = jrt::New<class_121>();
                    }
                    this->field_808->method_940(class_21::method_219(class_84::field_1116->method_4(272), (OpenSea::nearest() != nullptr ? OpenSea::nearest() : class_21::method_180())->field_1133), true);
                    this->field_808->method_942();
                    this->field_810 = true;
                    this->field_793 = true;
                }
                return false;
            }
        } else {
            class_69::method_638(jrt::Ref<java::lang::String>(nullptr));
        }
        return false;
    }
}

void class_64::method_567() {
    if (!this->field_793) {
        if (this->field_803 == nullptr) {
            this->field_803 = jrt::New<class_51>();
        }
        this->field_803->method_428();
        this->field_793 = true;
    }
}

void class_64::method_550(int32_t var1) {
    if (this->field_786) {
        if (this->field_793) {
            if (this->field_817 && (var1 == 256)) {
                this->field_817 = false;
                this->field_793 = false;
                this->field_805 = jrt::Ref<class_56>(nullptr);
                this->field_787->method_679();
                return;
            }
            if (this->field_794) {
                if (!this->field_804->method_459(var1)) {
                    this->field_793 = false;
                    this->field_794 = false;
                    if (class_21::method_139()) {
                        class_21::method_136(class_87::field_1145);
                    } else if (class_21::method_132()->field_1162) {
                        if (class_21::method_132()->field_1161) {
                            class_84::field_1126->method_439(class_84::field_1127->at(0));
                            class_84::field_1122->method_768(0);
                            class_21::method_221();
                            return;
                        }
                        class_21::method_136(class_87::field_1145);
                        this->field_799->method_269();
                        this->field_797 = 0;
                        class_21::method_133(class_87::field_1145);
                        this->field_787->field_982 = jrt::Ref<class_18>(nullptr);
                        if (this->field_787->field_1009) {
                            this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                        }
                        this->field_787->method_654();
                        this->field_799->field_277 = jrt::Ref<class_18>(nullptr);
                        this->field_807 = jrt::New<class_2>(this->field_799);
                    } else if ((!class_21::method_132()->field_1163) && (!class_21::method_137()->field_1163)) {
                        this->field_800->method_915();
                    } else {
                        bool var2 = class_21::method_137()->field_1163 && (!class_21::method_132()->field_1161);
                        jrt::Ref<class_87> var3{};
                        if ((var3 = (class_21::method_132()->field_1163) ? class_21::method_132() : class_21::method_137())->field_1157) {
                            class_84::field_1126->method_439(class_84::field_1127->at(0));
                            class_84::field_1122->method_768(0);
                            return;
                        }
                        if (var3->field_1161) {
                            class_21::method_145();
                        } else {
                            class_21::method_136(class_87::field_1145);
                        }
                        class_21::method_197(var3->field_1150);
                        class_69::method_639(var3->field_1150);
                        this->field_797 = 0;
                        if (!var2) {
                            this->field_799->method_269();
                            class_21::method_133(class_87::field_1145);
                            this->field_787->field_982 = jrt::Ref<class_18>(nullptr);
                            if (this->field_787->field_1009) {
                                this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                            }
                            this->field_787->method_654();
                            this->field_799->field_277 = jrt::Ref<class_18>(nullptr);
                            this->field_807 = jrt::New<class_2>(this->field_799);
                        }
                    }
                    this->field_782 = int64_t(0);
                    return;
                }
            } else {
                if (this->field_812) {
                    if (var1 == 1024) {
                        this->field_812 = false;
                        this->field_793 = false;
                    }
                    if ((var1 == 2) && this->field_812) {
                        this->field_807->method_6();
                    }
                    if ((var1 == 64) && this->field_812) {
                        this->field_807->method_7();
                    }
                    if ((var1 == 256) && this->field_812) {
                        this->field_812 = false;
                        class_69::method_638(jrt::Ref<java::lang::String>(nullptr));
                        class_69::method_633(5, this->field_787);
                        if (this->field_787 != nullptr) {
                            this->field_787->method_679();
                        }
                        this->field_793 = false;
                        int32_t var4 = this->field_807->field_31;
                        {
                            switch (this->field_807->field_31) {
                            case 0:
                                this->field_787->method_667(this->field_799->field_276->at(1));
                                return;
                            case 1:
                                this->field_787->method_667(this->field_799->field_276->at(0));
                                return;
                            case 2:
                                if (this->field_799->field_277 != nullptr) {
                                    this->field_787->method_667(jrt::Ref<class_91>(this->field_799->field_277->method_110()));
                                }
                            }
                        }
                    }
                    return;
                }
                if (this->field_809) {
                    if (var1 == 256) {
                        this->field_809 = false;
                        if (((class_21::method_143() != 1) && (class_21::method_143() != 2)) && ((class_21::method_143() != 6) || (class_21::method_180()->field_1134 != 0))) {
                            if (this->field_808->method_941()) {
                                if (class_21::method_143() == 5) {
                                    class_21::method_137()->method_759(class_26::field_302->field_1134);
                                }
                                class_21::method_131(class_26::field_302);
                                class_26::method_239();
                                class_26::field_302 = jrt::Ref<class_86>(nullptr);
                                class_69::method_639(0);
                                class_84::field_1126->method_439(class_84::field_1127->at(2));
                                class_21::method_150();
                            } else {
                                if (this->field_806 == nullptr) {
                                    this->field_806 = jrt::New<class_55>();
                                }
                                this->field_806->method_446();
                                this->field_806->method_445(jrt::Ref<class_87>(nullptr));
                                this->field_806->field_658 = true;
                                this->field_811 = true;
                                this->field_793 = false;
                            }
                        } else {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(291));
                            this->field_817 = true;
                            this->field_793 = true;
                        }
                    }
                    if (var1 == 4) {
                        this->field_808->method_942();
                    }
                    if (var1 == 32) {
                        this->field_808->method_943();
                        return;
                    }
                } else if (this->field_810) {
                    if (var1 == 256) {
                        this->field_810 = false;
                        if (!this->field_808->method_941()) {
                            this->field_793 = false;
                        } else if (((class_21::method_143() == 5) && (class_21::method_180()->field_1134 == 0)) || ((class_21::method_143() == 6) && (class_21::method_180()->field_1134 != 0))) {
                            this->field_805 = jrt::New<class_56>(class_84::field_1116->method_4(((class_21::method_143() == 5) ? 292 : 291)));
                            this->field_817 = true;
                            this->field_793 = true;
                        } else {
                            OpenSea::beforeDock();
                            class_14::method_67(this->field_787);
                            class_84::field_1126->method_439(class_84::field_1127->at(1));
                        }
                    }
                    if (var1 == 4) {
                        this->field_808->method_942();
                    }
                    if (var1 == 32) {
                        this->field_808->method_943();
                        return;
                    }
                } else if (this->field_803 != nullptr) {
                    this->field_803->method_430(var1);
                    if ((var1 == 256) && this->field_803->method_419()) {
                        this->field_793 = false;
                        return;
                    }
                    if ((var1 == 16384) && this->field_803->method_426()) {
                        this->field_793 = false;
                    }
                    if ((var1 == 8192) && this->field_803->method_425()) {
                        this->field_793 = false;
                    }
                    if (var1 == 4) {
                        this->field_803->method_422();
                    }
                    if (var1 == 32) {
                        this->field_803->method_424();
                        return;
                    }
                }
            }
        } else {
            if (this->field_811) {
                this->field_811 = this->field_806->method_447(var1);
                return;
            }
            if (!this->field_796) {
                if (var1 == 16384) {
                    if (this->field_803 == nullptr) {
                        this->field_803 = jrt::New<class_51>();
                    }
                    this->field_803->method_428();
                    this->field_793 = !this->field_793;
                    if (this->field_793) {
                        return;
                    }
                }
                if (!this->field_795) {
                    if (var1 == 4096) {
                        if (this->field_778 != 2) {
                            class_118::method_918(this->field_790);
                            this->field_778 = 2;
                        } else {
                            class_118::method_916(this->field_790, this->field_799);
                            this->field_778 = 0;
                        }
                    }
                    if (var1 == 131072) {
                        if (this->field_778 != 1) {
                            class_118::method_917(this->field_790);
                            this->field_778 = 1;
                        } else {
                            class_118::method_916(this->field_790, this->field_799);
                            this->field_778 = 0;
                        }
                    }
                    if (var1 == 2048) {
                        if (this->field_778 != 3) {
                            class_118::method_919(this->field_790);
                            this->field_778 = 3;
                        } else {
                            class_118::method_916(this->field_790, this->field_799);
                            this->field_778 = 0;
                        }
                    }
                    if ((var1 == 65536) && (!this->field_787->field_994)) {
                        this->field_787->method_650();
                        class_69::method_633(3, this->field_787);
                    }
                    if ((var1 == 32768) && (this->field_787->field_987 != (-1))) {
                        this->field_787->method_661();
                        class_69::method_633(0, this->field_787);
                    }
                    if (var1 == 512) {
                        this->field_792 = !this->field_792;
                        class_69::method_633((this->field_792 ? 1 : 2), this->field_787);
                    }
                    if (var1 == 1024) {
                        if (this->field_787->field_1007) {
                            this->field_787->method_667(jrt::Ref<class_91>(nullptr));
                            class_69::method_633(6, this->field_787);
                            return;
                        }
                        if (!this->field_812) {
                            if ((this->field_807 == nullptr) || ((this->field_799->field_277 != nullptr) && this->field_799->field_277->method_111()->field_1298)) {
                                this->field_807 = jrt::New<class_2>(this->field_799);
                            }
                            this->field_812 = true;
                            this->field_793 = true;
                            return;
                        }
                    }
                } else {
                    if (var1 == 256) {
                        this->field_800->method_914();
                        this->field_787->method_679();
                    }
                    if ((var1 == 65536) && (!this->field_787->field_994)) {
                        this->field_787->method_650();
                        class_69::method_633(3, this->field_787);
                        return;
                    }
                }
            } else if (this->field_785 > int64_t(3000)) {
                if (class_21::method_177() == 0) {
                    class_84::field_1126->method_439(class_84::field_1127->at(0));
                    class_84::field_1122->method_768(0);
                    return;
                }
                if (var1 == 32) {
                    this->field_808->method_943();
                    return;
                }
                if (var1 == 4) {
                    this->field_808->method_942();
                    return;
                }
                if (var1 == 256) {
                    if (this->field_808->method_941()) {
                        jrt::Ref<jrt::Array<jrt::Ref<class_41>>> var5{};
                        (var5 = class_27::method_272())->at((var5->length - 1))->method_367();
                        (jrt::cast<class_63>(class_84::field_1127->at(1)))->method_554();
                        class_84::field_1126->method_439(class_84::field_1127->at(1));
                        return;
                    }
                    class_84::field_1126->method_439(class_84::field_1127->at(0));
                    class_84::field_1122->method_768(0);
                    return;
                }
            }
        }
    }
}

float class_64::deep3dDolly() {
    int32_t var0 = org::deep3d::Config::flightFov();
    return (var0 == 500) ? 1.0f : float((org::deep3d::Step::tan(0.38349519697141027) / org::deep3d::Step::tan(((double(var0) * 3.141592653589793) / 4096.0))));
}

void class_64::__dumpFields(jrt::Dumper& d) {
    class_61::__dumpFields(d);
    d.f("deep3dFov", this->deep3dFov);
    d.f("field_778", this->field_778);
    d.f("field_779", this->field_779);
    d.f("field_780", this->field_780);
    d.f("field_781", this->field_781);
    d.f("field_782", this->field_782);
    d.f("field_783", this->field_783);
    d.f("field_784", this->field_784);
    d.f("field_785", this->field_785);
    d.f("field_786", this->field_786);
    d.f("field_787", this->field_787);
    d.f("field_788", this->field_788);
    d.f("field_789", this->field_789);
    d.f("field_790", this->field_790);
    d.f("field_791", this->field_791);
    d.f("field_792", this->field_792);
    d.f("field_793", this->field_793);
    d.f("field_794", this->field_794);
    d.f("field_795", this->field_795);
    d.f("field_796", this->field_796);
    d.f("field_797", this->field_797);
    d.f("field_798", this->field_798);
    d.f("field_799", this->field_799);
    d.f("field_800", this->field_800);
    d.f("field_801", this->field_801);
    d.f("field_802", this->field_802);
    d.f("field_803", this->field_803);
    d.f("field_804", this->field_804);
    d.f("field_805", this->field_805);
    d.f("field_806", this->field_806);
    d.f("field_807", this->field_807);
    d.f("field_808", this->field_808);
    d.f("field_809", this->field_809);
    d.f("field_810", this->field_810);
    d.f("field_811", this->field_811);
    d.f("field_812", this->field_812);
    d.f("field_813", this->field_813);
    d.f("field_814", this->field_814);
    d.f("field_815", this->field_815);
    d.f("field_816", this->field_816);
    d.f("field_817", this->field_817);
}

