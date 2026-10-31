// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

bool class_9::DEEP3D_LOG{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>>>> class_9::field_75{};

void class_9::__clinit() {
    class_9::DEEP3D_LOG = (java::lang::System::getenv(JRT_LIT(u"DEEP3D_LOG_HITS")) != nullptr);
    class_9::field_75 = jrt::arrayOf<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>>>({jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(0), int16_t(0), int16_t(0)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(270), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-270)), int16_t(0), int16_t(100)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(320), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-320)), int16_t(0), int16_t(100)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(370), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(170), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-170)), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-370)), int16_t(0), int16_t(100)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(350), int16_t(100), int16_t(200)}), jrt::arrayOf<int16_t>({int16_t(270), int16_t((-100)), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-270)), int16_t((-100)), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-350)), int16_t(100), int16_t(200)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(500), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(500), int16_t((-100)), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(200), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-200)), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-500)), int16_t((-100)), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-500)), int16_t(100), int16_t(150)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(500), int16_t((-100)), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(400), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(200), int16_t((-50)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-200)), int16_t((-50)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-400)), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-500)), int16_t((-100)), int16_t(150)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(550), int16_t((-100)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(550), int16_t(100), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(300), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(100), int16_t(0), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-100)), int16_t(0), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-300)), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-550)), int16_t(100), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-550)), int16_t((-100)), int16_t(100)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(550), int16_t((-100)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(550), int16_t(100), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(300), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(100), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t((-100)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-100)), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-300)), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-550)), int16_t(100), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-550)), int16_t((-100)), int16_t(100)})}), jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(600), int16_t((-120)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(600), int16_t(120), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(400), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t(200), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t(200), int16_t((-100)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-200)), int16_t((-100)), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-200)), int16_t(100), int16_t(150)}), jrt::arrayOf<int16_t>({int16_t((-400)), int16_t(0), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-600)), int16_t(120), int16_t(100)}), jrt::arrayOf<int16_t>({int16_t((-600)), int16_t((-120)), int16_t(100)})})});
}

void class_9::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, float var6, jrt::Ref<class_3> var7, jrt::Ref<class_3> var8) {
    this->field_84 = var1;
    this->field_85 = var6;
    this->field_87 = var7;
    this->field_86 = var4;
    this->field_91 = var5;
    this->field_90 = 0;
    this->deep3dVel.assign(size_t(var2) * 3, 0.0);
    this->deep3dCarry.assign(size_t(var2) * 3, 0.0);
    this->field_83 = jrt::newArray<int32_t>(var2);
    this->field_78 = jrt::newArray<jrt::Ref<class_3>>(var2);
    this->field_79 = jrt::newArray<jrt::Ref<class_3>>(var2);
    this->field_80 = jrt::New<class_3>();
    this->field_81 = jrt::New<class_3>();
    for (int32_t var9 = 0; var9 < var2; var9++) {
        this->field_78->at(var9) = jrt::New<class_3>(50000, 0, 0);
        this->field_79->at(var9) = jrt::New<class_3>();
        this->field_83->at(var9) = -1;
    }
    this->field_93 = true;
    this->field_88 = false;
    this->field_89 = jrt::New<class_3>();
    this->field_92 = false;
    this->field_94 = jrt::Ref<class_116>(nullptr);
    this->field_95 = false;
    this->field_77 = jrt::Ref<jrt::Array<jrt::Ref<class_37>>>(nullptr);
    this->field_97 = false;
    this->field_98 = jrt::Ref<class_114>(nullptr);
    this->field_101 = false;
}

void class_9::method_41(int32_t var1, jrt::Ref<class_114> var2) {
    this->field_98 = var2;
    this->field_97 = true;
    this->field_99 = var1 * 200;
}

void class_9::method_42(int32_t var1, int32_t var2) {
    jrt::Ref<jrt::Array<int16_t>> var3 = class_9::field_75->at((var2 - 1))->at(var1);
    this->field_89->method_9(this->field_87);
    this->field_87 = jrt::New<class_3>((int32_t(var3->at(0)) + this->field_89->field_37), (int32_t(var3->at(1)) + this->field_89->field_38), (int32_t(var3->at(2)) + this->field_89->field_39));
}

void class_9::method_43() {
    this->field_76 = jrt::Ref<class_26>(nullptr);
    this->field_77 = jrt::Ref<jrt::Array<jrt::Ref<class_37>>>(nullptr);
    this->field_78 = jrt::Ref<jrt::Array<jrt::Ref<class_3>>>(nullptr);
    this->field_79 = jrt::Ref<jrt::Array<jrt::Ref<class_3>>>(nullptr);
    this->field_80 = jrt::Ref<class_3>(nullptr);
    this->field_81 = jrt::Ref<class_3>(nullptr);
    this->field_82 = jrt::Ref<class_37>(nullptr);
    this->field_83 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_87 = jrt::Ref<class_3>(nullptr);
    this->field_94 = jrt::Ref<class_116>(nullptr);
}

void class_9::method_44(jrt::Ref<class_116> var1) {
    this->field_94 = var1;
    if (var1->field_1437) {
        this->field_95 = true;
    }
}

bool class_9::method_45(jrt::Ref<class_57> var1, int64_t var2, jrt::Ref<class_37> var4, bool var5) {
    if (((this->field_98 != nullptr) && this->field_97) && this->field_98->field_1433) {
        return false;
    } else {
        this->field_90 = 0;
        this->field_88 = true;
        this->field_92 = true;
        for (int32_t var6 = 0; var6 < this->field_78->length; var6++) {
            if (this->field_83->at(var6) <= 0) {
                this->field_78->at(var6)->method_9(var1->method_479(this->field_89));
                if (this->field_87 != nullptr) {
                    this->field_89->method_9(this->field_87);
                    this->field_80 = var1->method_508(this->field_89, this->field_80);
                    this->field_78->at(var6)->method_15(this->field_80);
                }
                if (var4 == nullptr) {
                    this->field_89->method_9(var1->method_481(this->field_89));
                } else {
                    this->field_89->method_16(var4->method_344(this->field_89), this->field_78->at(var6));
                }
                this->field_79->at(var6)->method_9(this->field_89);
                this->field_79->at(var6)->method_22();
                // Deep3D-PC: a shot's velocity was the frame's when it fired, and it moved by that every
                // frame after: here it is one original step's, and each frame moves its share
                this->field_79->at(var6)->method_18((jrt::f2i((this->field_85 * float(org::deep3d::Step::once(int32_t(var2))))) << 12));
                this->field_79->at(var6)->field_37 >>= 12;
                this->field_79->at(var6)->field_38 >>= 12;
                this->field_79->at(var6)->field_39 >>= 12;
                this->deep3dVel[3 * var6] = this->field_79->at(var6)->field_37;
                this->deep3dVel[3 * var6 + 1] = this->field_79->at(var6)->field_38;
                this->deep3dVel[3 * var6 + 2] = this->field_79->at(var6)->field_39;
                this->field_83->at(var6) = this->field_86;
                return true;
            }
        }
        return false;
    }
}

bool class_9::method_46(jrt::Ref<class_57> var1, int64_t var2, bool var4) {
    return this->method_45(var1, var2, jrt::Ref<class_37>(nullptr), var4);
}

void class_9::method_47() {
    if (this->field_77 != nullptr) {
        this->field_96 = jrt::Ref<class_91>(nullptr);
        for (int32_t var1 = 0; var1 < this->field_77->length; var1++) {
            this->field_82 = this->field_77->at(var1);
            if (this->field_82->field_375) {
                for (int32_t var2 = 0; var2 < this->field_78->length; var2++) {
                    this->field_80->method_9(this->field_78->at(var2));
                    this->field_81->method_9(this->field_79->at(var2));
                    // Deep3D-PC: tests where the shot is after this frame's move
                    double deep3dNext = org::deep3d::Step::exact() ? 1.0 : org::deep3d::Step::scale();
                    int32_t var3 = (this->field_82->field_377->field_698 - this->field_80->field_37) + int32_t(this->field_81->field_37 * deep3dNext);
                    int32_t var4 = (this->field_82->field_377->field_699 - this->field_80->field_38) + int32_t(this->field_81->field_38 * deep3dNext);
                    int32_t var5 = (this->field_82->field_377->field_700 - this->field_80->field_39) + int32_t(this->field_81->field_39 * deep3dNext);
                    int32_t var6 = this->field_97 ? this->field_99 : jrt::f2i(this->field_82->field_362);
                    if ((((((var3 < var6) && (var3 > (-var6))) && (var4 < var6)) && (var4 > (-var6))) && (var5 < var6)) && (var5 > (-var6))) {
                        if (class_9::DEEP3D_LOG) {
                            java::lang::System::out->println(jrt::concat(JRT_LIT(u"[hit] target "), this->field_82, JRT_LIT(u" owner "), this->field_82->field_379, JRT_LIT(u" at "), this->field_80->field_37, JRT_LIT(u" "), this->field_80->field_38, JRT_LIT(u" "), this->field_80->field_39, JRT_LIT(u" life "), this->field_83->at(var2)));
                        }
                        this->field_82->method_342(this->field_84, this->field_101);
                        this->field_82->method_337((-this->field_81->field_37), (-this->field_81->field_38), (-this->field_81->field_39));
                        this->field_83->at(var2) = -1;
                        this->field_89->method_9(this->field_79->at(var2));
                        this->field_89->method_22();
                        this->field_96 = this->field_82->field_379;
                        if (this->field_94 != nullptr) {
                            this->field_94->method_908(this->field_78->at(var2), this->field_89);
                        }
                    }
                }
            }
        }
    }
}

void class_9::method_48(int64_t var1) {
    this->field_89->method_10(0, 0, 0);
    if (this->field_76 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_78->length; var3++) {
            if ((this->field_83->at(var3) > 0) && this->field_76->method_262(this->field_78->at(var3), (!this->field_95))) {
                if (class_9::DEEP3D_LOG) {
                    java::lang::System::out->println(jrt::concat(JRT_LIT(u"[hit] world at "), this->field_78->at(var3)->field_37, JRT_LIT(u" "), this->field_78->at(var3)->field_38, JRT_LIT(u" "), this->field_78->at(var3)->field_39, JRT_LIT(u" life "), this->field_83->at(var3)));
                }
                this->field_83->at(var3) = -1;
                this->field_89->method_9(this->field_79->at(var3));
                this->field_89->method_22();
                if (this->field_94 != nullptr) {
                    this->field_94->method_908(this->field_78->at(var3), this->field_89);
                }
            }
        }
    }
}

void class_9::method_49(int64_t var1) {
    this->field_90 = int32_t((int64_t(this->field_90) + var1));
    if (this->field_94 != nullptr) {
        this->field_94->method_895(var1);
    }
    if (this->field_92) {
        this->method_47();
        if (this->field_93) {
            this->method_48(var1);
        }
        for (int32_t var3 = 0; var3 < this->field_78->length; var3++) {
            if (this->field_83->at(var3) > 0) {
                this->field_83->at(var3) = this->field_83->at(var3) - int32_t(var1);
                if (org::deep3d::Step::exact()) {
                    this->field_78->at(var3)->method_15(this->field_79->at(var3));
                } else {
                    this->field_78->at(var3)->field_37 += org::deep3d::Step::share(this->deep3dVel[3 * var3], this->deep3dCarry[3 * var3]);
                    this->field_78->at(var3)->field_38 += org::deep3d::Step::share(this->deep3dVel[3 * var3 + 1], this->deep3dCarry[3 * var3 + 1]);
                    this->field_78->at(var3)->field_39 += org::deep3d::Step::share(this->deep3dVel[3 * var3 + 2], this->deep3dCarry[3 * var3 + 2]);
                }
            } else {
                this->field_78->at(var3)->method_10(50000, 50000, 50000);
                this->field_79->at(var3)->method_10(0, 0, 0);
            }
        }
    }
}

void class_9::method_50() {
    if (this->field_94 != nullptr) {
        this->field_94->method_887();
    }
}

void class_9::__dumpFields(jrt::Dumper& d) {
    d.f("field_100", this->field_100);
    d.f("field_101", this->field_101);
    d.f("field_76", this->field_76);
    d.f("field_77", this->field_77);
    d.f("field_78", this->field_78);
    d.f("field_79", this->field_79);
    d.f("field_80", this->field_80);
    d.f("field_81", this->field_81);
    d.f("field_82", this->field_82);
    d.f("field_83", this->field_83);
    d.f("field_84", this->field_84);
    d.f("field_85", this->field_85);
    d.f("field_86", this->field_86);
    d.f("field_87", this->field_87);
    d.f("field_88", this->field_88);
    d.f("field_89", this->field_89);
    d.f("field_90", this->field_90);
    d.f("field_91", this->field_91);
    d.f("field_92", this->field_92);
    d.f("field_93", this->field_93);
    d.f("field_94", this->field_94);
    d.f("field_95", this->field_95);
    d.f("field_96", this->field_96);
    d.f("field_97", this->field_97);
    d.f("field_98", this->field_98);
    d.f("field_99", this->field_99);
}

