// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<int32_t>> class_55::field_598{};
jrt::Ref<jrt::Array<int32_t>> class_55::field_599{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> class_55::field_600{};

void class_55::__clinit() {
    class_55::field_598 = jrt::arrayOf<int32_t>({(-16755805), (-16752451), (-16748839), (-14382613), (-10046209), (-8207873), (-5253121), (-3677185)});
    class_55::field_599 = jrt::arrayOf<int32_t>({(-6697217), (-8864001), (-11360014), (-14448148), (-16748839), (-16752443)});
    class_55::field_600 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({(-15113829), (-12683887), (-9859964), (-6904457), (-4080534), (-1650592), (-8616)}), jrt::arrayOf<int32_t>({(-16753748), (-16685127), (-16681015), (-16677159), (-16673559), (-16670474), (-16602625)}), jrt::arrayOf<int32_t>({(-15968874), (-14788475), (-13476753), (-12033959), (-10656701), (-9541839), (-8754907)}), jrt::arrayOf<int32_t>({(-15181915), (-12691811), (-9875578), (-6928530), (-4112040), (-1688764), (-51401)}), jrt::arrayOf<int32_t>({(-16359528), (-15765367), (-15039625), (-14313116), (-13652654), (-12992957), (-12596680)})});
}

void class_55::__init() {
    this->field_626 = jrt::newArray<int16_t>(200);
    this->field_650 = jrt::New<class_3>();
}

void class_55::method_443() {
    this->field_649 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    this->field_648 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    this->field_603 = false;
    this->field_618 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_624 = jrt::Ref<jrt::Array<jrt::Ref<class_86>>>(nullptr);
    this->field_625 = jrt::Ref<jrt::Array<int16_t>>(nullptr);
    this->field_626 = jrt::Ref<jrt::Array<int16_t>>(nullptr);
    this->field_627 = jrt::Ref<jrt::Array<int16_t>>(nullptr);
    this->field_628 = jrt::Ref<jrt::Array<float>>(nullptr);
    java::lang::System::gc();
}

bool class_55::method_444() {
    return (this->field_623 == 0) || (this->field_623 == 5);
}

void class_55::method_445(jrt::Ref<class_87> var1) {
    this->field_666 = true;
    this->field_630 = -1;
    this->field_670 = false;
    this->field_656 = var1;
    this->field_657 = jrt::Ref<class_87>(nullptr);
    if ((var1 != nullptr) && var1->field_1161) {
        this->field_657 = var1;
    }
    this->field_654 = var1 != nullptr;
    this->field_655 = (var1 == nullptr) ? (-1) : var1->field_1152;
    if (this->field_655 > 0) {
        this->field_608 = float((int32_t(this->field_625->at((this->field_655 * 2))) - (this->field_610 >> 1)));
        this->field_609 = float((int32_t(this->field_625->at(((this->field_655 * 2) + 1))) - (this->field_611 >> 1)));
    }
    if (!this->field_654) {
        this->field_608 = float((this->field_632 - (this->field_610 >> 1)));
        this->field_609 = float((this->field_633 - (this->field_611 >> 1)));
    }
    this->field_623 = 0;
    this->field_605 = class_67::field_849;
    if (this->field_654) {
        this->field_666 = false;
    }
}

void class_55::method_446() {
    this->field_654 = false;
    this->field_662 = class_21::method_175();
    this->field_663 = class_38::method_356();
    this->field_630 = -1;
    this->field_605 = class_67::field_849;
    this->field_604 = class_67::field_848;
    this->field_606 = 3;
    this->field_607 = 11;
    this->field_610 = this->field_611 = this->field_604 / 6;
    this->field_631 = (this->field_610 << 1) - 2;
    int32_t var1{};
    if ((var1 = class_21::method_178()->field_881) != 0) {
        this->field_631 = jrt::f2i(((float((100 + var1)) / 100.0f) * float(this->field_631)));
    }
    this->field_653 = [&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(73); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u"     ("); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(227); jrt::Ref<java::lang::String> __c4 = JRT_LIT(u": "); int32_t __c5 = class_21::method_177(); jrt::Ref<java::lang::String> __c6 = JRT_LIT(u"/"); int32_t __c7 = 200; jrt::Ref<java::lang::String> __c8 = JRT_LIT(u")"); return jrt::concat(__c1, __c2, __c3, __c4, __c5, __c6, __c7, __c8); }();
    this->field_605 = class_67::field_849 - (this->field_611 + 8);
    if (this->field_618 == nullptr) {
        this->field_618 = jrt::newArray<int32_t>(12);
        this->field_618->at(0) = -10046209;
        this->field_618->at(1) = this->field_607 + (this->field_605 >> 3);
        this->field_618->at(2) = this->field_605 - this->field_618->at(1);
        this->field_618->at(3) = -16748839;
        this->field_618->at(4) = (this->field_607 + (this->field_605 >> 3)) + (this->field_605 >> 2);
        this->field_618->at(5) = this->field_605 - this->field_618->at(4);
        this->field_618->at(6) = -16755805;
        this->field_618->at(7) = (this->field_607 + (this->field_605 >> 3)) + (this->field_605 >> 1);
        this->field_618->at(8) = this->field_605 - this->field_618->at(7);
        this->field_618->at(9) = -16765091;
        this->field_618->at(10) = ((this->field_607 + (this->field_605 >> 3)) + (this->field_605 >> 2)) + (this->field_605 >> 1);
        this->field_618->at(11) = (this->field_605 - this->field_618->at(10)) + this->field_607;
        this->field_605 = class_67::field_849;
    }
    if (this->field_634 == nullptr) {
        this->field_634 = class_28::method_282(JRT_LIT(u"/data/interface/p_colonists_0.png"));
        this->field_635 = class_28::method_282(JRT_LIT(u"/data/interface/p_colonists_1.png"));
        this->field_636 = class_28::method_282(JRT_LIT(u"/data/interface/p_rebels_0.png"));
        this->field_637 = class_28::method_282(JRT_LIT(u"/data/interface/p_rebels_1.png"));
        this->field_638 = class_28::method_282(JRT_LIT(u"/data/interface/p_mission.png"));
        this->field_639 = class_28::method_282(JRT_LIT(u"/data/interface/p_home.png"));
        this->field_640 = class_28::method_282(JRT_LIT(u"/data/interface/p_mask.png"));
        this->field_641 = class_28::method_282(JRT_LIT(u"/data/interface/p_colonists_big_0.png"));
        this->field_642 = class_28::method_282(JRT_LIT(u"/data/interface/p_colonists_big_1.png"));
        this->field_643 = class_28::method_282(JRT_LIT(u"/data/interface/p_rebels_big_0.png"));
        this->field_644 = class_28::method_282(JRT_LIT(u"/data/interface/p_rebels_big_1.png"));
        this->field_645 = class_28::method_282(JRT_LIT(u"/data/interface/p_mission_big.png"));
        this->field_646 = class_28::method_282(JRT_LIT(u"/data/interface/p_home_big.png"));
        this->field_647 = class_28::method_282(JRT_LIT(u"/data/interface/p_mask_big.png"));
        this->field_648 = class_28::method_282(JRT_LIT(u"/data/interface/map_radiation.png"));
        this->field_649 = class_28::method_282(JRT_LIT(u"/data/interface/map_pressure.png"));
    }
    if (this->field_625 == nullptr) {
        jrt::Ref<jrt::Array<int8_t>> var2 = class_49::method_404();
        this->field_625 = jrt::newArray<int16_t>(((var2->length / 4) * 2));
        int32_t var3 = 0;
        for (int32_t var4 = 0; var4 < var2->length; var4 += 4) {
            this->field_625->at((var3++)) = int16_t((this->field_606 + jrt::f2i(((float(var2->at((var4 + 1))) / 100.0f) * float(this->field_604)))));
            this->field_625->at((var3++)) = int16_t((this->field_607 + jrt::f2i(((float(var2->at((var4 + 2))) / 100.0f) * float(this->field_605)))));
        }
    }
    this->field_632 = int32_t(this->field_625->at((class_21::method_180()->field_1134 * 2)));
    this->field_633 = int32_t(this->field_625->at(((class_21::method_180()->field_1134 * 2) + 1)));
    this->field_608 = float((this->field_632 - (this->field_610 >> 1)));
    this->field_609 = float((this->field_633 - (this->field_611 >> 1)));
    if (class_84::field_1108 == nullptr) {
        class_84::field_1108 = jrt::newArray<int32_t>((class_55::field_599->length << 1));
        for (int32_t var5 = 0; var5 < class_84::field_1108->length; var5++) {
            class_84::field_1108->at(var5) = -1;
        }
    }
    if (class_84::field_1109 == class_84::field_1108->length) {
        class_84::field_1109 = class_84::field_1108->length - 2;
    }
    class_84::field_1108->at((class_84::field_1109++)) = this->field_632;
    class_84::field_1108->at((class_84::field_1109++)) = this->field_633;
    this->field_623 = 0;
    this->field_658 = false;
    this->field_621 = jrt::New<class_121>();
    this->field_665 = jrt::newArray<int32_t>(2);
    for (int32_t var6 = 0; var6 < this->field_665->length; var6++) {
        this->field_665->at(var6) = 0;
        if (var6 == this->field_664) {
            this->field_665->at(var6) = 1;
        }
    }
    this->field_667 = 1;
    this->field_668 = (class_84::field_1121 - 32) - (this->field_665->length * 10);
    this->field_669 = 70;
    this->field_666 = true;
    this->field_670 = false;
    this->field_671 = false;
    java::lang::System::gc();
    this->field_603 = true;
}

bool class_55::method_447(int32_t var1) {
    if (this->field_623 == 0) {
        if ((var1 == 16384) && (!this->field_654)) {
            this->field_666 = !this->field_666;
            this->field_670 = !this->field_666;
            if (this->field_670) {
                this->method_452((-5.0f), 0.0f);
                this->method_452(5.0f, 0.0f);
            }
            return true;
        }
        if (this->field_666) {
            if (var1 == 256) {
                if (this->field_665->at(0) == 1) {
                    this->field_670 = true;
                    this->field_630 = -1;
                    this->method_452((-5.0f), 0.0f);
                    this->method_452(5.0f, 0.0f);
                } else if (this->field_665->at(1) == 1) {
                    if (this->field_622 == nullptr) {
                        this->field_622 = jrt::New<class_79>();
                    }
                    this->field_623 = 5;
                }
                this->field_666 = false;
                return true;
            }
            if (var1 == 64) {
                this->field_665->at(this->field_664) = 0;
                if (this->field_664 < (this->field_665->length - 1)) {
                    this->field_664++;
                } else {
                    this->field_664 = 0;
                }
                this->field_665->at(this->field_664) = 1;
            }
            if (var1 == 2) {
                this->field_665->at(this->field_664) = 0;
                if (this->field_664 > 0) {
                    this->field_664--;
                } else {
                    this->field_664 = this->field_665->length - 1;
                }
                this->field_665->at(this->field_664) = 1;
            }
        }
        if (((!this->field_654) && (var1 == 256)) || (this->field_654 && (var1 == 16384))) {
            int32_t var2 = 0;
            for (int32_t var3 = 0; var3 < this->field_625->length; var3 += 2) {
                if ((((float(this->field_625->at(var3)) > this->field_608) && (int32_t(this->field_625->at(var3)) < this->field_612)) && (float(this->field_625->at((var3 + 1))) > this->field_609)) && (int32_t(this->field_625->at((var3 + 1))) < this->field_613)) {
                    this->field_619 = (this->field_608 + float((this->field_610 >> 1))) - float(this->field_625->at(var3));
                    this->field_620 = (this->field_609 + float((this->field_611 >> 1))) - float(this->field_625->at((var3 + 1)));
                    if (class_16::method_100((class_16::method_96((jrt::f2l(((this->field_619 * this->field_619) + (this->field_620 * this->field_620))) << 12)) >> 12)) < (this->field_610 >> 1)) {
                        this->field_626->at((var2++)) = int16_t((var3 / 2));
                    }
                }
            }
            if (var2 == 0) {
                return true;
            }
            this->field_605 = class_67::field_849 - (this->field_611 + 8);
            this->field_623 = this->field_654 ? 2 : 1;
            this->field_628 = jrt::newArray<float>((var2 * 2));
            for (int32_t var9 = 0; var9 < this->field_628->length; var9 += 2) {
                this->field_628->at(var9) = float(this->field_625->at((int32_t(this->field_626->at((var9 / 2))) * 2)));
                this->field_628->at((var9 + 1)) = float(this->field_625->at(((int32_t(this->field_626->at((var9 / 2))) * 2) + 1)));
            }
            jrt::Ref<jrt::Array<int16_t>> var10 = jrt::newArray<int16_t>(var2);
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_626), 0, jrt::Ref<java::lang::Object>(var10), 0, var2);
            if (var10->length <= 0) {
                this->field_624 = jrt::Ref<jrt::Array<jrt::Ref<class_86>>>(nullptr);
                this->field_623 = 0;
                return true;
            }
            this->field_624 = class_49::method_401(var10);
            bool var4{};
            do {
                var4 = true;
                for (int32_t var5 = 1; var5 < this->field_624->length; var5++) {
                    if (this->field_624->at((var5 - 1))->field_1135 > this->field_624->at(var5)->field_1135) {
                        jrt::Ref<class_86> var6 = this->field_624->at((var5 - 1));
                        float var7 = this->field_628->at((2 * (var5 - 1)));
                        float var8 = this->field_628->at(((2 * (var5 - 1)) + 1));
                        this->field_624->at((var5 - 1)) = this->field_624->at(var5);
                        this->field_628->at((2 * (var5 - 1))) = this->field_628->at((2 * var5));
                        this->field_628->at(((2 * (var5 - 1)) + 1)) = this->field_628->at(((2 * var5) + 1));
                        this->field_624->at(var5) = var6;
                        this->field_628->at((2 * var5)) = var7;
                        this->field_628->at(((2 * var5) + 1)) = var8;
                        var4 = false;
                    }
                }
            } while (!var4);
            this->field_627 = jrt::newArray<int16_t>((this->field_624->length * 2));
            for (int32_t var11 = 0; var11 < this->field_624->length; var11++) {
                float var13 = (float((this->field_606 + jrt::f2i(((float(this->field_624->at(var11)->field_1135) / 100.0f) * float(this->field_604))))) - this->field_608) / (float(this->field_612) - this->field_608);
                this->field_627->at((2 * var11)) = int16_t((this->field_606 + jrt::f2i((var13 * float(this->field_604)))));
                this->field_627->at(((2 * var11) + 1)) = int16_t((this->field_618->at(1) + jrt::f2i(((float(this->field_624->at(var11)->field_1137) / 100.0f) * float((this->field_605 - (2 * this->field_618->at(11))))))));
            }
            float var12 = 1000.0f / float(this->field_602);
            this->field_616 = (((float((this->field_606 + this->field_604)) - this->field_608) - float(this->field_610)) - 4.0f) / var12;
            this->field_617 = (((float((((this->field_607 + this->field_605) + this->field_611) + 8)) - this->field_609) - float(this->field_611)) - 4.0f) / var12;
            this->field_614 = this->field_608;
            this->field_615 = this->field_609;
            if (this->field_654) {
                this->field_614 = float((((this->field_606 + this->field_604) - this->field_610) - 4));
                this->field_615 = float((((((this->field_607 + this->field_605) + this->field_611) + 8) - this->field_611) - 4));
                for (int32_t var14 = 0; var14 < this->field_628->length; var14 += 2) {
                    this->field_628->at(var14) = this->field_628->at(var14) + (((float((this->field_606 + this->field_604)) - this->field_608) - float(this->field_610)) - 4.0f);
                    this->field_628->at((var14 + 1)) = this->field_628->at((var14 + 1)) + (((float((((this->field_607 + this->field_605) + this->field_611) + 8)) - this->field_609) - float(this->field_611)) - 4.0f);
                }
                for (int32_t var15 = 0; var15 < this->field_624->length; var15++) {
                    if (this->field_624->at(var15)->field_1134 == this->field_655) {
                        this->field_629 = var15;
                        break;
                    }
                }
            }
        }
        if (var1 == 8192) {
            this->field_630 = -1;
            return false;
        }
    } else if (this->field_623 == 2) {
        if (!this->field_654) {
            if (var1 == 4) {
                if (this->field_629 > 0) {
                    this->field_629--;
                } else if (this->field_624 != nullptr) {
                    this->field_629 = this->field_624->length - 1;
                }
            }
            if (var1 == 32) {
                if ((this->field_629 < (this->field_624->length - 1)) && (this->field_624 != nullptr)) {
                    this->field_629++;
                } else {
                    this->field_629 = 0;
                }
            }
            if ((((var1 == 256) || (var1 == 16384)) && (!this->field_654)) && (!this->field_624->at(this->field_629)->method_753(class_21::method_180()))) {
                this->field_621->method_940(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(334); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u": "); jrt::Ref<java::lang::String> __c3 = this->field_624->at(this->field_629)->field_1133; jrt::Ref<java::lang::String> __c4 = JRT_LIT(u"\n"); jrt::Ref<java::lang::String> __c5 = (this->field_661 ? jrt::concat(class_84::field_1116->method_4(255), JRT_LIT(u"\n")) : JRT_LIT(u"")); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(247); return jrt::concat(__c1, __c2, __c3, __c4, __c5, __c6); }()), true);
                this->field_623 = 4;
            }
        }
    } else if (this->field_623 == 4) {
        if (var1 == 256) {
            if (this->field_621->method_941()) {
                if (!this->field_654) {
                    this->method_448();
                    return true;
                }
                if (class_21::method_135() == this->field_656) {
                    class_21::method_136(class_87::field_1145);
                } else {
                    class_21::method_136(this->field_656);
                    class_21::method_180()->method_751(this->field_656);
                    class_21::method_197((-this->field_656->field_1151));
                }
                this->field_623 = 6;
                return true;
            }
            this->field_623 = 2;
        }
        if (var1 == 4) {
            this->field_621->method_942();
        }
        if (var1 == 32) {
            this->field_621->method_943();
        }
    } else if (this->field_623 == 5) {
        if ((var1 == 256) || (var1 == 16384)) {
            this->field_630 = this->field_622->method_728();
            this->field_623 = 0;
            this->field_666 = true;
        }
        if (var1 == 8192) {
            this->field_623 = 0;
            this->field_666 = true;
        }
        return true;
    }
    if (var1 == 8192) {
        {
            switch (this->field_623) {
            case 2:
                this->field_623 = this->field_654 ? 0 : 3;
                this->field_616 = -this->field_616;
                this->field_617 = -this->field_617;
                this->field_614 = float((((this->field_606 + this->field_604) - this->field_610) - 4));
                this->field_615 = float((((((this->field_607 + this->field_605) + this->field_611) + 8) - this->field_611) - 4));
                this->field_605 = class_67::field_849;
            }
        }
    }
    return true;
}

void class_55::method_448() {
    if (class_84::field_1109 >= class_84::field_1108->length) {
        for (int32_t var1 = 2; var1 < class_84::field_1108->length; var1 += 2) {
            class_84::field_1108->at((var1 - 2)) = class_84::field_1108->at(var1);
            class_84::field_1108->at((var1 - 1)) = class_84::field_1108->at((var1 + 1));
        }
        class_84::field_1109 = class_84::field_1108->length - 2;
    }
    if (this->field_658) {
        if (class_21::method_143() == 5) {
            class_21::method_137()->method_759(this->field_624->at(this->field_629)->field_1134);
        }
        class_21::method_131(this->field_624->at(this->field_629));
        class_26::field_302 = jrt::Ref<class_86>(nullptr);
        class_26::method_239();
        class_21::method_150();
    } else {
        if (class_21::method_143() == 3) {
            if (!this->field_671) {
                this->field_621->method_939(class_84::field_1116->method_4(288));
                this->field_671 = true;
                return;
            }
            this->field_623 = 2;
            this->field_671 = false;
            return;
        }
        class_21::field_220 = -1;
        class_21::field_218 = -1;
        class_21::field_219 = -1;
        class_21::method_140();
        class_21::method_131(class_21::method_180());
        if ((this->field_624 != nullptr) && (!this->field_624->at(this->field_629)->method_753(class_21::method_180()))) {
            class_26::field_302 = this->field_624->at(this->field_629);
        }
        class_14::method_85();
    }
    class_84::field_1126->method_439(class_84::field_1127->at(2));
}

bool class_55::method_449() {
    return this->field_623 == 2;
}

bool class_55::method_450(int32_t var1, int32_t var2) {
    if (!this->field_603) {
        return true;
    } else {
        this->field_601 += var2;
        this->field_602 = var2;
        if ((!this->field_654) && (!this->field_658)) {
            class_67::method_579(var2);
        }
        this->field_672 = var1;
        if (((this->field_623 == 0) && (!this->field_666)) && this->field_670) {
            jrt::Ref<jrt::Array<int32_t>> var90 = org::deep3d::GameUi::pointer();
            if (((((var90 != nullptr) && (var90->at(0) >= this->field_606)) && (var90->at(0) < (this->field_606 + this->field_604))) && (var90->at(1) >= this->field_607)) && (var90->at(1) < (this->field_607 + this->field_605))) {
                this->method_452((float(var90->at(0)) - (this->field_608 + (float(this->field_610) / 2.0f))), (float(var90->at(1)) - (this->field_609 + (float(this->field_611) / 2.0f))));
            }
            if (!this->field_654) {
                if ((var1 & 4) != 0) {
                    this->method_452((float((-var2)) / 20.0f), 0.0f);
                }
                if ((var1 & 32) != 0) {
                    this->method_452((float(var2) / 20.0f), 0.0f);
                }
                if ((var1 & 2) != 0) {
                    this->method_452(0.0f, (float((-var2)) / 20.0f));
                }
                if ((var1 & 64) != 0) {
                    this->method_452(0.0f, (float(var2) / 20.0f));
                }
            }
        } else if ((this->field_623 == 5) && (this->field_601 > 200)) {
            this->field_601 = 0;
            if ((var1 & 2) != 0) {
                this->field_622->method_704();
            }
            if ((var1 & 64) != 0) {
                this->field_622->method_705();
            }
        }
        this->method_451();
        return true;
    }
}

void class_55::method_451() {
    if (this->field_623 == 0) {
        if (this->field_654) {
            org::deep3d::GameUi::controls(1, (-6), (-7), 0);
        } else {
            org::deep3d::GameUi::controls(1, (-5), (-7), (-6));
        }
        if (!this->field_666) {
            org::deep3d::GameUi::zone(this->field_606, this->field_607, this->field_604, this->field_605, 100);
        }
    } else if (this->field_623 == 2) {
        org::deep3d::GameUi::controls(1, (this->field_654 ? 0 : (-6)), (-7), 0);
        org::deep3d::GameUi::scrollArea(this->field_606, this->field_607, this->field_604, this->field_605, true);
        if (!this->field_654) {
            org::deep3d::GameUi::zone(this->field_606, this->field_607, this->field_604, this->field_605, 100);
            // Deep3D-PC: the mouse can use the arrows at the edges and pick any station, in
            // the depth view or in the little map below (a click selects it and asks to travel)
            int32_t mid = this->field_607 + (this->field_605 >> 1);
            org::deep3d::GameUi::zone(this->field_606, mid - 14, 18, 28, org::deep3d::GameUi::LEFT);
            org::deep3d::GameUi::zone((this->field_606 + this->field_604) - 18, mid - 14, 18, 28, org::deep3d::GameUi::RIGHT);
            if (this->field_624 != nullptr) {
                jrt::Ref<class_55> self(this);
                org::deep3d::GameUi::menuSelect([self](int32_t i) {
                    if (self->field_624 != nullptr && i >= 0 && i < self->field_624->length) self->field_629 = i;
                });
                auto pick = [&](int32_t i, int32_t x, int32_t y) {
                    org::deep3d::GameUi::rowIndex(i);
                    org::deep3d::GameUi::row(x - 7, y - 7, 14, 14, i == this->field_629, true);
                };
                for (int32_t i = 0; i < this->field_624->length; i++) {
                    if (this->field_627 != nullptr && (i * 2 + 1) < this->field_627->length)
                        pick(i, this->field_627->at(i * 2), this->field_627->at(i * 2 + 1));
                    if (this->field_628 != nullptr && (i * 2 + 1) < this->field_628->length)
                        pick(i, jrt::f2i(this->field_628->at(i * 2)), jrt::f2i(this->field_628->at(i * 2 + 1)));
                }
            }
        }
    } else if (this->field_623 == 5) {
        org::deep3d::GameUi::controls(1, (-6), (-7), 0);
    } else {
        org::deep3d::GameUi::controls(1, 0, 0, 0);
    }
    if (this->field_623 != 5) {
        class_67::method_587();
    }
    {
        jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var10{};
        int32_t var14{};
        switch (this->field_623) {
        case 0:
            ;
        case 5:
            class_84::field_1117->setColor((-16755805));
            class_84::field_1117->fillRect(this->field_606, this->field_607, this->field_604, this->field_605);
            class_84::field_1117->setClip(this->field_606, this->field_607, this->field_604, this->field_605);
            if (this->field_630 == (-3)) {
                for (int32_t var8 = 0; var8 < class_55::field_600->at(0)->length; var8++) {
                    for (int32_t var16 = 0; var16 < class_55::field_600->length; var16++) {
                        if (class_21::method_168()->at((13 + var16))) {
                            this->field_651 = class_90::method_785()->at((13 + var16))->field_1482;
                            class_84::field_1117->setColor(class_55::field_600->at(var16)->at(var8));
                            class_84::field_1117->fillArc(((int32_t(this->field_625->at((this->field_651 << 1))) - 35) + (var8 * 5)), ((int32_t(this->field_625->at(((this->field_651 << 1) + 1))) - 35) + (var8 * 5)), (70 - (var8 * 10)), (70 - (var8 * 10)), 0, 360);
                        }
                    }
                }
                class_84::field_1117->setColor(0);
                class_84::field_1117->drawArc((this->field_632 - (this->field_631 >> 1)), (this->field_633 - (this->field_631 >> 1)), this->field_631, this->field_631, 0, 360);
            } else if (this->field_630 < 0) {
                class_84::field_1117->setColor((-16748839));
                class_84::field_1117->fillArc((this->field_632 - (this->field_631 >> 1)), (this->field_633 - (this->field_631 >> 1)), this->field_631, this->field_631, 0, 360);
            } else {
                this->field_651 = class_90::method_785()->at(this->field_630)->field_1482;
                for (int32_t var1 = 0; var1 < class_55::field_598->length; var1++) {
                    class_84::field_1117->setColor(class_55::field_598->at(var1));
                    class_84::field_1117->fillArc(((int32_t(this->field_625->at((this->field_651 << 1))) - 80) + (var1 * 10)), ((int32_t(this->field_625->at(((this->field_651 << 1) + 1))) - 80) + (var1 * 10)), (160 - (var1 * 20)), (160 - (var1 * 20)), 0, 360);
                }
                class_84::field_1117->setColor(0);
                class_84::field_1117->drawArc((this->field_632 - (this->field_631 >> 1)), (this->field_633 - (this->field_631 >> 1)), this->field_631, this->field_631, 0, 360);
            }
            class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
            class_84::field_1117->setColor(0);
            class_84::field_1117->drawLine((this->field_606 + (this->field_604 >> 2)), this->field_607, (this->field_606 + (this->field_604 >> 2)), (this->field_607 + this->field_605));
            class_84::field_1117->drawLine((this->field_606 + (this->field_604 >> 1)), this->field_607, (this->field_606 + (this->field_604 >> 1)), (this->field_607 + this->field_605));
            class_84::field_1117->drawLine(((this->field_606 + this->field_604) - (this->field_604 >> 2)), this->field_607, ((this->field_606 + this->field_604) - (this->field_604 >> 2)), (this->field_607 + this->field_605));
            class_84::field_1117->drawLine(this->field_606, (this->field_607 + (this->field_605 >> 2)), (this->field_606 + this->field_604), (this->field_607 + (this->field_605 >> 2)));
            class_84::field_1117->drawLine(this->field_606, (this->field_607 + (this->field_605 >> 1)), (this->field_606 + this->field_604), (this->field_607 + (this->field_605 >> 1)));
            class_84::field_1117->drawLine(this->field_606, ((this->field_607 + this->field_605) - (this->field_605 >> 2)), (this->field_606 + this->field_604), ((this->field_607 + this->field_605) - (this->field_605 >> 2)));
            if ((!this->field_654) && this->field_670) {
                this->method_454();
                this->method_453(jrt::f2i(this->field_608), jrt::f2i(this->field_609), this->field_610, this->field_611, this->field_672);
            }
            this->field_612 = jrt::f2i(this->field_608) + this->field_610;
            this->field_613 = jrt::f2i(this->field_609) + this->field_611;
            for (int32_t var9 = 0; var9 < this->field_625->length; var9 += 2) {
                int32_t var17 = var9 >> 1;
                jrt::Ref<javax::microedition::lcdui::Image> var26 = this->field_662->at(var17) ? (this->field_663->at(var17) ? this->field_637 : this->field_636) : (this->field_663->at(var17) ? this->field_635 : this->field_634);
                class_84::field_1117->drawImage(var26, int32_t(this->field_625->at(var9)), int32_t(this->field_625->at((var9 + 1))), 3);
            }
            class_84::field_1117->drawImage(this->field_639, int32_t(this->field_625->at((class_21::method_180()->field_1134 << 1))), int32_t(this->field_625->at(((class_21::method_180()->field_1134 << 1) + 1))), 3);
            if (((this->field_655 > 0) || (this->field_654 && (this->field_657 != nullptr))) && class_67::method_581()) {
                class_84::field_1117->drawImage(this->field_638, int32_t(this->field_625->at((this->field_655 << 1))), int32_t(this->field_625->at(((this->field_655 << 1) + 1))), 3);
            }
            var10 = class_21::method_134();
            for (int32_t var18 = 0; var18 < var10->length; var18++) {
                if (((var10->at(var18) != nullptr) && var10->at(var18)->field_1171) || ((this->field_654 && (this->field_656 != nullptr)) && (!this->field_656->method_754()))) {
                    jrt::Ref<class_87> var27 = this->field_654 ? this->field_656 : var10->at(var18);
                    this->field_651 = var27->field_1152;
                    if (class_67::method_581()) {
                        class_84::field_1117->drawImage(this->field_638, int32_t(this->field_625->at((this->field_651 << 1))), int32_t(this->field_625->at(((this->field_651 << 1) + 1))), 3);
                    }
                    this->field_651 = class_58::method_523(var27->method_757());
                    if ((int32_t(this->field_625->at((var27->field_1152 << 1))) + this->field_651) > (this->field_606 + this->field_604)) {
                        this->field_651 = (int32_t(this->field_625->at((var27->field_1152 << 1))) + this->field_651) - (this->field_606 + this->field_604);
                    } else {
                        this->field_651 = 0;
                    }
                    class_58::method_518(var27->method_757(), (int32_t(this->field_625->at((var27->field_1152 << 1))) - this->field_651), (int32_t(this->field_625->at(((var27->field_1152 << 1) + 1))) - 10), (var27->field_1161 ? 0 : 1));
                }
            }
            if (this->field_630 >= 0) {
                int32_t var19 = this->field_666 ? (this->field_668 - 16) : ((this->field_607 + this->field_605) - 16);
                class_84::field_1117->drawImage(this->field_622->method_727(this->field_630), (this->field_606 + 2), var19, 0);
                class_58::method_518(jrt::concat(class_84::field_1116->method_4(int32_t(class_1::field_7->at(this->field_630)->at(0))), JRT_LIT(u"  ("), class_90::method_787()->at(this->field_630)->method_365(), JRT_LIT(u"t - "), class_90::method_787()->at(this->field_630)->method_366(), JRT_LIT(u"t)")), (this->field_606 + 22), (var19 + 1), 0);
            }
            if ((this->field_622 != nullptr) && (this->field_623 == 5)) {
                this->field_622->method_718();
            }
            if (this->field_666) {
                class_67::method_591(JRT_LIT(u""), this->field_667, this->field_668, this->field_669, ((12 + ((this->field_665->length + 1) * 10)) - 5));
                class_67::method_584(class_84::field_1116->method_4(259), this->field_667, (this->field_668 + 12), this->field_669, (this->field_665->at(0) == 1));
                class_67::method_584(class_84::field_1116->method_4(260), this->field_667, ((this->field_668 + 12) + 10), this->field_669, (this->field_665->at(1) == 1));
            } else if ((this->field_623 != 5) && (!this->field_654)) {
                class_67::method_597(class_67::method_580());
            }
            break;
        case 1:
            class_84::field_1117->setColor((-16755805));
            class_84::field_1117->fillRect(this->field_606, this->field_607, this->field_604, ((this->field_605 + this->field_611) + 8));
            this->method_453(jrt::f2i(this->field_614), jrt::f2i(this->field_615), this->field_610, this->field_611, this->field_672);
            if (this->field_614 < float((((this->field_606 + this->field_604) - this->field_610) - 4))) {
                this->field_614 = this->field_614 + this->field_616;
            }
            if (this->field_615 < float((((((this->field_607 + this->field_605) + this->field_611) + 8) - this->field_611) - 4))) {
                this->field_615 = this->field_615 + this->field_617;
            }
            for (int32_t var15 = 0; var15 < this->field_628->length; var15 += 2) {
                this->field_628->at(var15) = this->field_628->at(var15) + this->field_616;
                this->field_628->at((var15 + 1)) = this->field_628->at((var15 + 1)) + this->field_617;
                int32_t var25 = this->field_624->at((var15 >> 1))->field_1134;
                jrt::Ref<javax::microedition::lcdui::Image> var30 = this->field_662->at(var25) ? (this->field_663->at(var25) ? this->field_637 : this->field_636) : (this->field_663->at(var25) ? this->field_635 : this->field_634);
                class_84::field_1117->drawImage(var30, jrt::f2i(this->field_628->at(var15)), jrt::f2i(this->field_628->at((var15 + 1))), 3);
                if (this->field_624->at((var15 >> 1))->field_1134 == class_21::method_180()->field_1134) {
                    class_84::field_1117->drawImage(this->field_639, jrt::f2i(this->field_628->at(var15)), jrt::f2i(this->field_628->at((var15 + 1))), 3);
                }
            }
            if ((this->field_614 >= float((((this->field_606 + this->field_604) - this->field_610) - 4))) && (this->field_615 >= float((((((this->field_607 + this->field_605) + this->field_611) + 8) - this->field_611) - 4)))) {
                this->field_614 = float((((this->field_606 + this->field_604) - this->field_610) - 4));
                this->field_615 = float((((((this->field_607 + this->field_605) + this->field_611) + 8) - this->field_611) - 4));
                this->field_623 = 2;
                this->field_629 = 0;
            }
            break;
        case 2:
            ;
        case 4:
            ;
        case 6:
            this->field_660 = true;
            this->field_659 = true;
            this->field_661 = false;
            this->field_651 = class_38::method_359(this->field_624->at(this->field_629)->field_1140);
            if (this->field_651 == 0) {
                this->field_651 = -15;
            } else if (this->field_651 == 100) {
                this->field_651 = 115;
            }
            if ((this->field_651 > class_21::method_178()->field_888) || (this->field_651 < class_21::method_178()->field_887)) {
                this->field_661 = true;
                if (class_67::method_580()) {
                    if (this->field_651 < class_21::method_178()->field_887) {
                        this->field_659 = false;
                    } else {
                        this->field_660 = false;
                    }
                }
            }
            class_84::field_1117->setColor((-5253121));
            class_84::field_1117->fillRect(this->field_606, this->field_607, (this->field_604 - 1), this->field_605);
            for (int32_t var2 = 0; var2 < this->field_618->length; var2 += 3) {
                class_84::field_1117->setColor(this->field_618->at(var2));
                class_84::field_1117->fillRect(this->field_606, this->field_618->at((var2 + 1)), (this->field_604 - 1), this->field_618->at((var2 + 2)));
                class_84::field_1117->setColor(0);
                class_84::field_1117->drawLine(this->field_606, this->field_618->at((var2 + 1)), (this->field_606 + this->field_604), this->field_618->at((var2 + 1)));
            }
            for (int32_t var11 = 0; var11 < 2; var11++) {
                this->field_651 = (var11 == 0) ? class_21::method_178()->field_887 : class_21::method_178()->field_888;
                this->field_651 = (this->field_618->at(1) + jrt::f2i(((float(this->field_651) / 100.0f) * float((this->field_605 - (2 * this->field_618->at(11))))))) + 2;
                for (int32_t var20 = 1; var20 < (this->field_618->length - 1); var20 += 3) {
                    if (class_16::method_100((this->field_651 - this->field_618->at(var20))) < (class_84::field_1121 / 20)) {
                        this->field_651 = this->field_618->at(var20);
                    }
                }
                if (var11 == 0) {
                    if (this->field_659) {
                        [&]() { jrt::Ref<java::lang::String> __a1 = class_84::field_1116->method_4(306); int32_t __a2 = ((this->field_606 + this->field_648->getWidth()) + 7); int32_t __a3 = (this->field_651 - 16); int32_t __a4 = 0; return class_58::method_518(__a1, __a2, __a3, __a4); }();
                    }
                    class_67::method_582(this->field_606, this->field_607, this->field_604, (this->field_651 - this->field_607));
                    this->field_651 -= 7;
                } else {
                    if (this->field_660) {
                        [&]() { jrt::Ref<java::lang::String> __a5 = class_84::field_1116->method_4(307); int32_t __a6 = ((this->field_606 + this->field_649->getWidth()) + 7); int32_t __a7 = (this->field_651 + 4); int32_t __a8 = 0; return class_58::method_518(__a5, __a6, __a7, __a8); }();
                    }
                    class_67::method_582(this->field_606, this->field_651, this->field_604, ((this->field_607 + this->field_605) - this->field_651));
                    this->field_651--;
                }
                class_84::field_1117->setColor(0);
                class_84::field_1117->setClip(this->field_606, this->field_651, (this->field_604 - 1), 8);
                for (int32_t var21 = -4; var21 < (this->field_606 + this->field_604); var21 += 3) {
                    class_84::field_1117->drawLine(var21, (this->field_651 + 6), (var21 + 4), (this->field_651 + 2));
                }
                class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
            }
            class_58::method_516(JRT_LIT(u"15000"), ((this->field_606 + this->field_604) - 1), this->field_618->at(1), 1, 34);
            class_58::method_516(JRT_LIT(u"20000"), ((this->field_606 + this->field_604) - 1), this->field_618->at(4), 1, 34);
            class_58::method_516(JRT_LIT(u"25000"), ((this->field_606 + this->field_604) - 1), this->field_618->at(7), 1, 34);
            class_58::method_516(JRT_LIT(u"30000"), ((this->field_606 + this->field_604) - 1), this->field_618->at(10), 1, 34);
            if (this->field_659) {
                class_84::field_1117->drawImage(this->field_648, (this->field_606 + 2), (this->field_607 + 2), 0);
            }
            if (this->field_660) {
                class_84::field_1117->drawImage(this->field_649, (this->field_606 + 2), ((this->field_607 + this->field_605) - 2), 36);
            }
            class_84::field_1117->setColor(class_67::field_845);
            class_84::field_1117->fillRect((this->field_606 - 2), ((this->field_607 + this->field_605) + 1), ((this->field_604 - this->field_610) - 6), (this->field_611 + 6));
            class_84::field_1117->fillRect((((this->field_606 + this->field_604) - this->field_610) - 6), ((this->field_607 + this->field_605) + 1), (this->field_610 + 6), (this->field_611 + 6));
            class_84::field_1117->setColor((-16755805));
            class_84::field_1117->fillRect((((this->field_606 + this->field_604) - this->field_610) - 4), ((this->field_607 + this->field_605) + 3), (this->field_610 + 3), (this->field_611 + 3));
            class_84::field_1117->setColor(class_67::field_844);
            class_84::field_1117->drawRect((this->field_606 - 2), ((this->field_607 + this->field_605) + 1), ((this->field_604 - this->field_610) - 6), (this->field_611 + 6));
            class_84::field_1117->drawRect((((this->field_606 + this->field_604) - this->field_610) - 6), ((this->field_607 + this->field_605) + 1), (this->field_610 + 6), (this->field_611 + 6));
            this->method_453(jrt::f2i(this->field_614), jrt::f2i(this->field_615), this->field_610, this->field_611, this->field_672);
            for (int32_t var12 = 0; var12 < this->field_628->length; var12 += 2) {
                int32_t var22 = this->field_624->at((var12 >> 1))->field_1134;
                jrt::Ref<javax::microedition::lcdui::Image> var28 = this->field_662->at(var22) ? (this->field_663->at(var22) ? this->field_637 : this->field_636) : (this->field_663->at(var22) ? this->field_635 : this->field_634);
                class_84::field_1117->drawImage(var28, jrt::f2i(this->field_628->at(var12)), jrt::f2i(this->field_628->at((var12 + 1))), 3);
                if (((((class_21::method_134()->at(0) != nullptr) && class_21::method_134()->at(0)->field_1171) && (this->field_624->at((var12 / 2))->field_1134 == class_21::method_134()->at(0)->field_1152)) || (((class_21::method_134()->at(1) != nullptr) && class_21::method_134()->at(1)->field_1171) && (this->field_624->at((var12 / 2))->field_1134 == class_21::method_134()->at(1)->field_1152))) && class_67::method_581()) {
                    class_84::field_1117->drawImage(this->field_638, jrt::f2i(this->field_628->at(var12)), jrt::f2i(this->field_628->at((var12 + 1))), 3);
                }
                if (var12 == (this->field_629 * 2)) {
                    class_84::field_1117->drawImage(this->field_640, jrt::f2i(this->field_628->at(var12)), jrt::f2i(this->field_628->at((var12 + 1))), 3);
                }
                if (this->field_624->at((var12 >> 1))->field_1134 == class_21::method_180()->field_1134) {
                    class_84::field_1117->drawImage(this->field_639, jrt::f2i(this->field_628->at(var12)), jrt::f2i(this->field_628->at((var12 + 1))), 3);
                    if (var12 == (this->field_629 * 2)) {
                        class_84::field_1117->drawImage(this->field_640, jrt::f2i(this->field_628->at(var12)), jrt::f2i(this->field_628->at((var12 + 1))), 3);
                    }
                }
            }
            if (!this->field_654) {
                class_84::field_1117->setColor((-9049112));
                int32_t var13 = ((this->field_672 & 4) != 0) ? 2 : 0;
                int32_t var23 = ((this->field_672 & 32) != 0) ? 2 : 0;
                if (this->field_624 != nullptr) {
                    class_84::field_1117->fillTriangle(((this->field_606 + 4) - var13), (this->field_607 + (this->field_605 >> 1)), (this->field_606 + 10), (((this->field_607 + (this->field_605 >> 1)) - 6) - var13), (this->field_606 + 10), (((this->field_607 + (this->field_605 >> 1)) + 6) + var13));
                    class_84::field_1117->fillTriangle((((this->field_606 + this->field_604) - 4) + var23), (this->field_607 + (this->field_605 >> 1)), ((this->field_606 + this->field_604) - 10), (((this->field_607 + (this->field_605 >> 1)) - 6) - var23), ((this->field_606 + this->field_604) - 10), (((this->field_607 + (this->field_605 >> 1)) + 6) + var23));
                }
            }
            var14 = (-1);
            for (int32_t var24 = 0; var24 < this->field_627->length; var24 += 2) {
                jrt::Ref<javax::microedition::lcdui::Image> var31 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
                jrt::Ref<javax::microedition::lcdui::Image> var29{};
                if (this->field_624->at((var24 >> 1))->field_1134 == class_21::method_180()->field_1134) {
                    var29 = this->field_646;
                } else {
                    int32_t var6 = this->field_624->at((var24 >> 1))->field_1134;
                    var29 = this->field_662->at(var6) ? (this->field_663->at(var6) ? this->field_644 : this->field_643) : (this->field_663->at(var6) ? this->field_642 : this->field_641);
                }
                if (var24 == (this->field_629 * 2)) {
                    var14 = var24;
                    var31 = this->field_647;
                }
                if (var29 != nullptr) {
                    if ((((class_21::method_134()->at(0) != nullptr) && class_21::method_134()->at(0)->field_1171) && (this->field_624->at((var24 / 2))->field_1134 == class_21::method_134()->at(0)->field_1152)) || (((class_21::method_134()->at(1) != nullptr) && class_21::method_134()->at(1)->field_1171) && (this->field_624->at((var24 / 2))->field_1134 == class_21::method_134()->at(1)->field_1152))) {
                        if (class_67::method_581()) {
                            class_84::field_1117->drawImage(this->field_645, int32_t(this->field_627->at(var24)), int32_t(this->field_627->at((var24 + 1))), 0);
                        } else {
                            class_84::field_1117->drawImage(var29, int32_t(this->field_627->at(var24)), int32_t(this->field_627->at((var24 + 1))), 0);
                        }
                    } else {
                        class_84::field_1117->drawImage(var29, int32_t(this->field_627->at(var24)), int32_t(this->field_627->at((var24 + 1))), 0);
                    }
                }
                if (var31 != nullptr) {
                    class_84::field_1117->drawImage(var31, (int32_t(this->field_627->at(var24)) - 1), (int32_t(this->field_627->at((var24 + 1))) - 1), 0);
                }
            }
            if (var14 >= 0) {
                this->field_652 = JRT_LIT(u"");
                if (((class_21::method_134()->at(0) != nullptr) && class_21::method_134()->at(0)->field_1171) && (this->field_624->at((var14 / 2))->field_1134 == class_21::method_134()->at(0)->field_1152)) {
                    this->field_652 = jrt::concat(JRT_LIT(u"  \n("), class_21::method_134()->at(0)->method_757(), JRT_LIT(u")"));
                } else if (((class_21::method_134()->at(1) != nullptr) && class_21::method_134()->at(1)->field_1171) && (this->field_624->at((var14 / 2))->field_1134 == class_21::method_134()->at(1)->field_1152)) {
                    this->field_652 = jrt::concat(JRT_LIT(u"  \n("), class_21::method_134()->at(1)->method_757(), JRT_LIT(u")"));
                } else if (this->field_654 && (this->field_656->field_1152 == this->field_624->at((var14 / 2))->field_1134)) {
                    this->field_652 = jrt::concat(JRT_LIT(u"  \n("), this->field_656->method_757(), JRT_LIT(u")"));
                }
                this->field_651 = class_16::method_97(class_58::method_523(this->field_624->at((var14 >> 1))->field_1133), class_58::method_523(this->field_652));
                if (((int32_t(this->field_627->at(var14)) + this->field_651) + 14) > (this->field_606 + this->field_604)) {
                    this->field_651 = ((int32_t(this->field_627->at(var14)) + this->field_651) + 14) - (this->field_606 + this->field_604);
                } else {
                    this->field_651 = 0;
                }
                class_58::method_518(jrt::concat((((!this->field_654) && (var14 > 0)) ? JRT_LIT(u"< ") : JRT_LIT(u"   ")), this->field_624->at((var14 >> 1))->field_1133, (((!this->field_654) && (var14 < (this->field_627->length - 2))) ? JRT_LIT(u" >") : JRT_LIT(u"  "))), (int32_t(this->field_627->at(var14)) - this->field_651), (int32_t(this->field_627->at((var14 + 1))) - 10), 0);
                class_58::method_518(this->field_652, (int32_t(this->field_627->at(var14)) - this->field_651), int32_t(this->field_627->at((var14 + 1))), 0);
            }
            class_58::method_518(class_84::field_1116->method_4(int32_t(class_1::field_9->at(((class_21::method_175()->at(this->field_624->at(this->field_629)->field_1134)) ? 1 : 0)))), (this->field_606 + 2), ((this->field_607 + this->field_605) + 2), 0);
            class_58::method_518(jrt::concat(class_84::field_1116->method_4(44), JRT_LIT(u":  "), (this->field_663->at(this->field_624->at(this->field_629)->field_1134) ? jrt::concat(JRT_LIT(u""), this->field_624->at(this->field_629)->field_1139) : JRT_LIT(u"\?"))), (this->field_606 + 2), (((this->field_607 + this->field_605) + 2) + class_58::method_527()), 0);
            if (((this->field_611 > (class_58::method_527() * 2)) && this->field_659) && this->field_660) {
                class_58::method_518(jrt::concat(class_84::field_1116->method_4(245), JRT_LIT(u":  "), org::deep3d::Scale::depth(this->field_624->at(this->field_629)->field_1140)), (this->field_606 + 2), (((this->field_607 + this->field_605) + 2) + (2 * class_58::method_527())), 0);
            }
            if (this->field_623 == 4) {
                this->field_621->method_944();
            }
            break;
        case 3:
            class_84::field_1117->setColor((-16755805));
            class_84::field_1117->fillRect(this->field_606, this->field_607, this->field_604, this->field_605);
            this->method_453(jrt::f2i(this->field_614), jrt::f2i(this->field_615), this->field_610, this->field_611, this->field_672);
            if (this->field_608 < this->field_614) {
                this->field_614 = this->field_614 + this->field_616;
            }
            if (this->field_609 < this->field_615) {
                this->field_615 = this->field_615 + this->field_617;
            }
            for (int32_t var3 = 0; var3 < this->field_628->length; var3 += 2) {
                this->field_628->at(var3) = this->field_628->at(var3) + this->field_616;
                this->field_628->at((var3 + 1)) = this->field_628->at((var3 + 1)) + this->field_617;
                int32_t var4 = this->field_624->at((var3 >> 1))->field_1134;
                jrt::Ref<javax::microedition::lcdui::Image> var5 = this->field_662->at(var4) ? (this->field_663->at(var4) ? this->field_637 : this->field_636) : (this->field_663->at(var4) ? this->field_635 : this->field_634);
                class_84::field_1117->drawImage(var5, jrt::f2i(this->field_628->at(var3)), jrt::f2i(this->field_628->at((var3 + 1))), 3);
                if (this->field_624->at((var3 / 2))->field_1134 == class_21::method_180()->field_1134) {
                    class_84::field_1117->drawImage(this->field_639, jrt::f2i(this->field_628->at(var3)), jrt::f2i(this->field_628->at((var3 + 1))), 3);
                }
            }
            if ((this->field_608 >= this->field_614) && (this->field_609 >= this->field_615)) {
                this->field_623 = 0;
                this->field_629 = 0;
            }
        }
    }
    class_67::method_588(this->field_653);
    if (this->field_623 == 5) {
        [&]() { jrt::Ref<java::lang::String> __a9 = class_84::field_1116->method_4(265); jrt::Ref<java::lang::String> __a10 = class_84::field_1116->method_4(65); return class_67::method_593(__a9, __a10); }();
    } else if (this->field_623 == 0) {
        if (this->field_654) {
            [&]() { jrt::Ref<java::lang::String> __a11 = class_84::field_1116->method_4(74); jrt::Ref<java::lang::String> __a12 = class_84::field_1116->method_4(65); return class_67::method_593(__a11, __a12); }();
        } else {
            [&]() { jrt::Ref<java::lang::String> __a13 = class_84::field_1116->method_4(67); jrt::Ref<java::lang::String> __a14 = class_84::field_1116->method_4(65); return class_67::method_593(__a13, __a14); }();
        }
    } else if (this->field_623 == 2) {
        if (this->field_654) {
            class_67::method_593(JRT_LIT(u""), class_84::field_1116->method_4(65));
        } else {
            [&]() { jrt::Ref<java::lang::String> __a15 = class_84::field_1116->method_4(41); jrt::Ref<java::lang::String> __a16 = class_84::field_1116->method_4(65); return class_67::method_593(__a15, __a16); }();
        }
    } else {
        class_67::method_593(JRT_LIT(u""), JRT_LIT(u""));
    }
}

void class_55::method_452(float var1, float var2) {
    this->field_608 += var1;
    this->field_609 += var2;
    this->field_619 = (this->field_608 + float((this->field_610 >> 1))) - float(this->field_632);
    this->field_620 = (this->field_609 + float((this->field_611 >> 1))) - float(this->field_633);
    if (class_16::method_100((class_16::method_96((jrt::f2l(((this->field_619 * this->field_619) + (this->field_620 * this->field_620))) << 12)) >> 12)) >= ((this->field_631 >> 1) - (this->field_610 >> 1))) {
        this->field_650->method_10((jrt::f2i(this->field_619) << 12), (jrt::f2i(this->field_620) << 12), 0);
        this->field_650->method_22();
        this->field_650->method_18((((this->field_631 >> 1) - (this->field_610 >> 1)) << 12));
        this->field_608 = (float(this->field_632) + (float(this->field_650->field_37) / 4096.0f)) - float((this->field_610 >> 1));
        this->field_609 = (float(this->field_633) + (float(this->field_650->field_38) / 4096.0f)) - float((this->field_611 >> 1));
    }
    if (this->field_608 <= float(this->field_606)) {
        this->field_608 = float(this->field_606);
    } else if ((this->field_608 + float(this->field_610)) >= float((this->field_606 + this->field_604))) {
        this->field_608 = float(((this->field_606 + this->field_604) - this->field_610));
    }
    if (this->field_609 <= float(this->field_607)) {
        this->field_609 = float(this->field_607);
    } else {
        if ((this->field_609 + float(this->field_611)) >= float((this->field_607 + this->field_605))) {
            this->field_609 = float(((this->field_607 + this->field_605) - this->field_611));
        }
    }
}

void class_55::method_453(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    int32_t var6 = var3 >> 1;
    int32_t var7 = var4 >> 1;
    class_84::field_1117->setColor((-9049112));
    class_84::field_1117->drawArc(var1, var2, var3, var4, 0, 360);
    int32_t var8 = ((var5 & 4) != 0) ? 2 : 0;
    int32_t var9 = ((var5 & 32) != 0) ? 2 : 0;
    int32_t var10 = ((var5 & 2) != 0) ? 2 : 0;
    int32_t var11 = ((var5 & 64) != 0) ? 2 : 0;
    if (this->field_623 == 0) {
        class_84::field_1117->fillTriangle(((var1 - 4) - var8), (var2 + var7), (var1 - 1), (((var2 + var7) + 3) + var8), (var1 - 1), (((var2 + var7) - 3) - var8));
        class_84::field_1117->fillTriangle((((var1 + var3) + 5) + var9), (var2 + var7), ((var1 + var3) + 2), (((var2 + var7) + 3) + var9), ((var1 + var3) + 2), (((var2 + var7) - 3) - var9));
        class_84::field_1117->fillTriangle((var1 + var6), ((var2 - 4) - var10), (((var1 + var6) - 3) - var10), (var2 - 1), (((var1 + var6) + 4) + var10), (var2 - 1));
        class_84::field_1117->fillTriangle((var1 + var6), (((var2 + var4) + 5) + var11), (((var1 + var6) - 2) - var11), ((var2 + var4) + 2), (((var1 + var6) + 3) + var11), ((var2 + var4) + 2));
    }
    class_84::field_1117->setColor(0);
}

void class_55::method_454() {
    for (int32_t var1 = 2; (var1 < class_84::field_1108->length) && (class_84::field_1108->at(var1) > 0); var1 += 2) {
        if (class_84::field_1108->at((var1 + 1)) <= 0) {
            return;
        }
        class_84::field_1117->setColor(class_55::field_599->at((((class_84::field_1109 / 2) - (var1 / 2)) - 1)));
        if ((class_84::field_1108->at((var1 - 1)) > 0) && (class_84::field_1108->at((var1 - 2)) > 0)) {
            class_84::field_1117->drawLine(class_84::field_1108->at((var1 - 2)), class_84::field_1108->at((var1 - 1)), class_84::field_1108->at(var1), class_84::field_1108->at((var1 + 1)));
        }
    }
}

void class_55::__dumpFields(jrt::Dumper& d) {
    d.f("field_601", this->field_601);
    d.f("field_602", this->field_602);
    d.f("field_603", this->field_603);
    d.f("field_604", this->field_604);
    d.f("field_605", this->field_605);
    d.f("field_606", this->field_606);
    d.f("field_607", this->field_607);
    d.f("field_608", this->field_608);
    d.f("field_609", this->field_609);
    d.f("field_610", this->field_610);
    d.f("field_611", this->field_611);
    d.f("field_612", this->field_612);
    d.f("field_613", this->field_613);
    d.f("field_614", this->field_614);
    d.f("field_615", this->field_615);
    d.f("field_616", this->field_616);
    d.f("field_617", this->field_617);
    d.f("field_618", this->field_618);
    d.f("field_619", this->field_619);
    d.f("field_620", this->field_620);
    d.f("field_621", this->field_621);
    d.f("field_622", this->field_622);
    d.f("field_623", this->field_623);
    d.f("field_624", this->field_624);
    d.f("field_625", this->field_625);
    d.f("field_626", this->field_626);
    d.f("field_627", this->field_627);
    d.f("field_628", this->field_628);
    d.f("field_629", this->field_629);
    d.f("field_630", this->field_630);
    d.f("field_631", this->field_631);
    d.f("field_632", this->field_632);
    d.f("field_633", this->field_633);
    d.f("field_634", this->field_634);
    d.f("field_635", this->field_635);
    d.f("field_636", this->field_636);
    d.f("field_637", this->field_637);
    d.f("field_638", this->field_638);
    d.f("field_639", this->field_639);
    d.f("field_640", this->field_640);
    d.f("field_641", this->field_641);
    d.f("field_642", this->field_642);
    d.f("field_643", this->field_643);
    d.f("field_644", this->field_644);
    d.f("field_645", this->field_645);
    d.f("field_646", this->field_646);
    d.f("field_647", this->field_647);
    d.f("field_648", this->field_648);
    d.f("field_649", this->field_649);
    d.f("field_650", this->field_650);
    d.f("field_651", this->field_651);
    d.f("field_652", this->field_652);
    d.f("field_653", this->field_653);
    d.f("field_654", this->field_654);
    d.f("field_655", this->field_655);
    d.f("field_656", this->field_656);
    d.f("field_657", this->field_657);
    d.f("field_658", this->field_658);
    d.f("field_659", this->field_659);
    d.f("field_660", this->field_660);
    d.f("field_661", this->field_661);
    d.f("field_662", this->field_662);
    d.f("field_663", this->field_663);
    d.f("field_664", this->field_664);
    d.f("field_665", this->field_665);
    d.f("field_666", this->field_666);
    d.f("field_667", this->field_667);
    d.f("field_668", this->field_668);
    d.f("field_669", this->field_669);
    d.f("field_670", this->field_670);
    d.f("field_671", this->field_671);
    d.f("field_672", this->field_672);
}

