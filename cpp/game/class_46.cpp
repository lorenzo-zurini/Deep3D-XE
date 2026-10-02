// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_46::field_477{};
int32_t class_46::field_478{};
int32_t class_46::field_479{};
int32_t class_46::field_480{};

void class_46::__clinit() {
}

void class_46::__init(jrt::Ref<class_26> var1) {
    this->field_515 = jrt::New<class_57>();
    this->field_516 = jrt::New<class_3>();
    this->field_517 = jrt::New<class_3>();
    this->field_518 = jrt::New<class_3>();
    this->field_519 = jrt::New<class_3>();
    this->field_520 = jrt::New<class_8>();
    this->field_522 = jrt::newArray<jrt::Ref<java::lang::String>>(3);
    this->field_514 = var1;
    this->field_502 = class_84::field_1120 / 2;
    this->field_503 = class_84::field_1121 / 2;
    class_46::field_477 = class_84::field_1120 / 3;
    class_46::field_478 = class_84::field_1120 - class_46::field_477;
    class_46::field_479 = (class_84::field_1121 / 2) - ((class_84::field_1120 / 2) - class_46::field_477);
    class_46::field_480 = (class_84::field_1121 / 2) + ((class_84::field_1120 / 2) - class_46::field_477);
    this->field_522->at(0) = class_21::method_180()->field_1133;
    this->field_522->at(1) = JRT_LIT(u"S.T.R.E.A.M. OUT");
    this->field_522->at(2) = JRT_LIT(u"");
    {
        try {
            this->field_481 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_enemy_in.png"));
            this->field_482 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_enemy_out.png"));
            this->field_483 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_friend_in.png"));
            this->field_484 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_friend_out.png"));
            this->field_485 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_waypoint_in.png"));
            this->field_486 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_waypoint_out.png"));
            this->field_490 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_landmark_out.png"));
            this->field_489 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_landmark_in.png"));
            this->field_492 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_creature_out.png"));
            this->field_491 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_creature_in.png"));
            this->field_487 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_enemy_far.png"));
            this->field_488 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_friend_far.png"));
            this->field_495 = class_28::method_282(JRT_LIT(u"/data/interface/bracket_box.png"));
            this->field_496 = class_28::method_282(JRT_LIT(u"/data/interface/crate.png"));
            this->field_499 = class_28::method_282(JRT_LIT(u"/data/interface/cargo_18.png"));
            this->field_493 = class_28::method_282(JRT_LIT(u"/data/interface/radar_logo_0.png"));
            this->field_494 = class_28::method_282(JRT_LIT(u"/data/interface/radar_logo_1.png"));
            jrt::Ref<java::lang::String> var2 = class_14::method_70() ? JRT_LIT(u"go") : ((class_21::method_178()->field_884) ? JRT_LIT(u"g") : JRT_LIT(u"b"));
            this->field_525 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/c_"), var2, JRT_LIT(u"_s.png")));
            this->field_526 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/c_"), var2, JRT_LIT(u"_f.png")));
            this->field_523 = class_21::method_178()->field_876;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_46::method_388() {
    this->field_509 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    this->field_510 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    this->field_511 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    this->field_513 = jrt::Ref<class_18>(nullptr);
    this->field_514 = jrt::Ref<class_26>(nullptr);
    this->field_518 = jrt::Ref<class_3>(nullptr);
    this->field_519 = jrt::Ref<class_3>(nullptr);
    this->field_516 = jrt::Ref<class_3>(nullptr);
}

void class_46::method_389(jrt::Ref<class_106> var1, jrt::Ref<class_91> var2) {
    this->field_517 = var2->method_799(this->field_517);
    this->field_516 = var1->method_871(this->field_515)->method_507(this->field_517, this->field_516);
    this->field_516->field_38 = -this->field_516->field_38;
    this->field_516->field_39 = -this->field_516->field_39;
    var1->method_883(this->field_517);
    this->field_500 = this->field_517->field_37;
    this->field_501 = this->field_517->field_38;
    float var3 = (this->field_500 > class_84::field_1120) ? (float((this->field_503 - this->field_501)) / float((this->field_500 - this->field_502))) : (float((this->field_503 - this->field_501)) / float((this->field_502 - this->field_500)));
    float var4 = (this->field_501 > class_84::field_1121) ? (float((this->field_502 - this->field_500)) / float((this->field_501 - this->field_503))) : (float((this->field_502 - this->field_500)) / float((this->field_503 - this->field_501)));
    if (this->field_516->field_39 < 0) {
        if (this->field_500 < this->field_502) {
            this->field_500 = -1;
        } else {
            this->field_500 = class_84::field_1120 + 1;
        }
        if (this->field_501 < this->field_503) {
            this->field_501 = -1;
        } else {
            this->field_501 = class_84::field_1121 + 1;
        }
    }
    this->field_504 = (((this->field_500 <= class_84::field_1120) && (this->field_500 >= 0)) && (this->field_501 <= class_84::field_1121)) && (this->field_501 >= 0);
    this->field_505 = this->field_506 = this->field_507 = this->field_508 = false;
    if (this->field_500 > class_84::field_1120) {
        this->field_500 = class_84::field_1120 - 14;
        this->field_501 = this->field_503 - jrt::f2i((var3 * float((this->field_500 - this->field_502))));
        this->field_506 = true;
    } else if (this->field_500 < 0) {
        this->field_500 = 14;
        this->field_501 = this->field_503 + jrt::f2i((var3 * float((this->field_500 - this->field_502))));
        this->field_505 = true;
    }
    if (this->field_501 > class_84::field_1121) {
        this->field_501 = 33 + class_69::field_894;
        this->field_500 = this->field_502 - jrt::f2i((var4 * float((this->field_501 - this->field_503))));
        this->field_508 = true;
    } else if (this->field_501 < 0) {
        this->field_501 = 33;
        this->field_500 = this->field_502 + jrt::f2i((var4 * float((this->field_501 - this->field_503))));
        this->field_507 = true;
    }
    if (this->field_500 > (14 + class_69::field_893)) {
        this->field_500 = 14 + class_69::field_893;
    } else if (this->field_500 < 14) {
        this->field_500 = 14;
    }
    if (this->field_501 > (33 + class_69::field_894)) {
        this->field_501 = 33 + class_69::field_894;
    } else {
        if (this->field_501 < 33) {
            this->field_501 = 33;
        }
    }
}

void class_46::method_390(jrt::Ref<class_37> var1, jrt::Ref<class_106> var2) {
    this->field_509 = this->field_514->field_273;
    this->field_510 = this->field_514->field_274;
    this->field_511 = this->field_514->field_276;
    this->field_513 = this->field_514->field_277;
    this->field_512 = this->field_514->field_275;
    bool var3 = false;
    if ((((this->field_523 == 2) || (this->field_523 == 4)) && (this->field_497 == nullptr)) && (this->field_509 != nullptr)) {
        this->field_497 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(this->field_509->length);
        for (int32_t var4 = 0; var4 < this->field_509->length; var4++) {
            if (this->field_509->at(var4)->field_1239) {
                jrt::Ref<class_120> var5 = this->field_509->at(var4)->field_1240;
                if (this->field_509->at(var4)->field_1240 != nullptr) {
                    this->field_497->at(var4) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), this->field_509->at(var4)->field_1240->field_1480, JRT_LIT(u".png")));
                } else if (class_21::method_132()->field_1146 == 2) {
                    this->field_497->at(var4) = class_28::method_282(JRT_LIT(u"/data/interface/cargo_salvage.png"));
                } else {
                    this->field_497->at(var4) = class_28::method_282(JRT_LIT(u"/data/interface/cargo_recovery.png"));
                }
            }
        }
    }
    if ((((this->field_523 == 3) || (this->field_523 == 4)) && (this->field_498 == nullptr)) && (this->field_512 != nullptr)) {
        this->field_498 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(this->field_512->length);
        for (int32_t var9 = 0; var9 < this->field_512->length; var9++) {
            this->field_498->at(var9) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), (jrt::cast<class_101>(this->field_512->at(var9)))->field_1312->field_391, JRT_LIT(u".png")));
        }
    }
    if (this->field_523 > 0) {
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->drawLine(14, 33, 14, 45);
        class_84::field_1117->drawLine(14, 33, 26, 33);
        class_84::field_1117->drawLine(14, (33 + class_69::field_894), 26, (33 + class_69::field_894));
        class_84::field_1117->drawLine(14, (33 + class_69::field_894), 14, ((33 + class_69::field_894) - 12));
        class_84::field_1117->drawLine((14 + class_69::field_893), 33, ((14 + class_69::field_893) - 12), 33);
        class_84::field_1117->drawLine((14 + class_69::field_893), 33, (14 + class_69::field_893), 45);
        class_84::field_1117->drawLine((14 + class_69::field_893), (33 + class_69::field_894), ((14 + class_69::field_893) - 12), (33 + class_69::field_894));
        class_84::field_1117->drawLine((14 + class_69::field_893), (33 + class_69::field_894), (14 + class_69::field_893), ((33 + class_69::field_894) - 12));
        class_84::field_1117->setColor(class_67::field_844);
        for (int32_t var10 = 0; var10 < 2; var10++) {
            int32_t var14{};
            if ((var14 = (var10 == 0) ? class_14::method_74() : class_14::method_79()) != 0) {
                class_84::field_1117->drawImage(((var10 == 0) ? this->field_525 : this->field_526), ((var10 == 0) ? 16 : (((14 + class_69::field_893) - 3) - 40)), 35, 0);
                int32_t var6 = (var10 == 0) ? 28 : ((14 + class_69::field_893) - 30);
                int32_t var7 = 36;
                for (int32_t var8 = 0; var8 < var14; var8++) {
                    if (((var8 + 1) % 5) == 0) {
                        class_84::field_1117->drawLine((var6 - 9), (var7 + 5), (var6 - 1), var7);
                    } else {
                        class_84::field_1117->drawLine(var6, var7, var6, (var7 + 5));
                    }
                    var6 += 2;
                    if (var6 > ((var10 == 0) ? 56 : ((14 + class_69::field_893) - 2))) {
                        var6 = (var10 == 0) ? 18 : ((14 + class_69::field_893) - 40);
                        var7 += 8;
                    }
                }
            }
        }
        if (this->field_510 != nullptr) {
            for (int32_t var11 = 0; var11 < this->field_510->length; var11++) {
                if (this->field_510->at(var11)->field_1225->field_375 && (!this->field_510->at(var11)->method_801())) {
                    this->method_389(var2, this->field_510->at(var11));
                    if (this->field_504) {
                        this->field_518 = var1->method_344(this->field_518);
                        this->field_519 = this->field_510->at(var11)->field_1225->method_344(this->field_519);
                        if (((((((this->field_518->field_37 - this->field_519->field_37) <= 24000) && ((this->field_518->field_37 - this->field_519->field_37) >= (-24000))) && ((this->field_518->field_38 - this->field_519->field_38) <= 24000)) && ((this->field_518->field_38 - this->field_519->field_38) >= (-24000))) && ((this->field_518->field_39 - this->field_519->field_39) <= 24000)) && ((this->field_518->field_39 - this->field_519->field_39) >= (-24000))) {
                            class_84::field_1117->drawImage(this->field_483, this->field_500, this->field_501, 3);
                            this->field_521 = jrt::f2i(((float(this->field_510->at(var11)->field_1225->field_370) / 100.0f) * 16.0f));
                            class_84::field_1117->setColor((-13319376));
                            class_84::field_1117->fillRect((this->field_500 + 10), (((this->field_501 + 10) - 2) - this->field_521), 2, this->field_521);
                        } else {
                            class_84::field_1117->drawImage(this->field_488, this->field_500, this->field_501, 3);
                        }
                    } else {
                        class_84::field_1117->drawImage(this->field_484, this->field_500, this->field_501, 3);
                    }
                }
            }
        }
    }
    if (this->field_511 != nullptr) {
        for (int32_t var12 = 0; var12 < this->field_511->length; var12++) {
            if (this->field_511->at(var12) != nullptr) {
                this->method_389(var2, this->field_511->at(var12));
                if (this->field_504) {
                    this->field_518 = var1->method_344(this->field_518);
                    this->field_519 = this->field_511->at(var12)->field_1225->method_344(this->field_519);
                    class_84::field_1117->drawImage(this->field_489, this->field_500, this->field_501, 3);
                    if (var12 == 0) {
                        class_84::field_1117->drawImage(((class_21::method_180()->method_752()) ? this->field_494 : this->field_493), (this->field_500 + 5), (this->field_501 + 2), 0);
                    }
                    class_58::method_518(this->field_522->at(var12), ((var12 == 0) ? (this->field_500 + 25) : (this->field_500 + 5)), this->field_501, 0);
                    if (var12 < 2) {
                        this->field_524 = this->method_391(this->field_511->at(var12)->field_1234, this->field_511->at(var12)->field_1235, this->field_511->at(var12)->field_1236, var1);
                        class_58::method_518(this->field_524, ((var12 == 0) ? (this->field_500 + 25) : (this->field_500 + 5)), (this->field_501 + 10), 1);
                    }
                }
            }
        }
    }
    if ((this->field_513 != nullptr) && (this->field_513->method_110() != nullptr)) {
        this->method_389(var2, jrt::Ref<class_91>(this->field_513->method_110()));
        this->field_524 = this->method_391(this->field_513->method_110()->field_1295, this->field_513->method_110()->field_1296, this->field_513->method_110()->field_1297, var1);
        if (this->field_504) {
            class_84::field_1117->drawImage(this->field_485, this->field_500, this->field_501, 3);
            class_58::method_518(this->field_524, (this->field_500 - 10), (this->field_501 + 10), 1);
        } else if (this->field_523 > 0) {
            class_84::field_1117->drawImage(this->field_486, this->field_500, this->field_501, 3);
        }
    }
    bool var13 = class_21::method_132()->field_1146 == 6;
    if (this->field_512 != nullptr) {
        for (int32_t var15 = 0; var15 < this->field_512->length; var15++) {
            if ((!(jrt::cast<class_101>(this->field_512->at(var15)))->field_1326) && ((!this->field_512->at(var15)->method_800()) || (jrt::cast<class_101>(this->field_512->at(var15)))->field_1333)) {
                this->method_389(var2, this->field_512->at(var15));
                if (this->field_504) {
                    this->field_518 = var1->method_344(this->field_518);
                    this->field_519 = this->field_512->at(var15)->field_1225->method_344(this->field_519);
                    if (var13) {
                        class_84::field_1117->drawImage(this->field_491, this->field_500, this->field_501, 3);
                    }
                    if (((((((this->field_523 == 3) || (this->field_523 == 4)) && (this->field_498->at(var15) != nullptr)) && (this->field_500 > class_46::field_477)) && (this->field_500 < class_46::field_478)) && (this->field_501 > class_46::field_479)) && (this->field_501 < class_46::field_480)) {
                        class_84::field_1117->drawImage((((jrt::cast<class_101>(this->field_512->at(var15)))->field_1333) ? this->field_499 : this->field_498->at(var15)), (this->field_500 - 20), (this->field_501 + 10), 0);
                        class_58::method_518(jrt::concat((jrt::cast<class_101>(this->field_512->at(var15)))->field_1332, JRT_LIT(u"t")), ((this->field_500 - 20) + 20), ((this->field_501 + 10) + 3), 0);
                    }
                } else if ((this->field_523 > 0) && var13) {
                    class_84::field_1117->drawImage(this->field_492, this->field_500, this->field_501, 3);
                }
            }
        }
    }
    if ((this->field_523 > 0) && (this->field_509 != nullptr)) {
        for (int32_t var16 = 0; var16 < this->field_509->length; var16++) {
            jrt::Ref<class_91> var17{};
            if ((var17 = this->field_509->at(var16))->field_1225->field_375 && ((!var17->method_801()) || var17->field_1239)) {
                this->method_389(var2, var17);
                bool var18 = var17->field_1239 && (var17->method_800() || var17->method_801());
                if (this->field_504) {
                    this->field_518 = var1->method_344(this->field_518);
                    this->field_519 = var17->field_1225->method_344(this->field_519);
                    if (((((((((this->field_518->field_37 - this->field_519->field_37) <= 24000) && ((this->field_518->field_37 - this->field_519->field_37) >= (-24000))) && ((this->field_518->field_38 - this->field_519->field_38) <= 24000)) && ((this->field_518->field_38 - this->field_519->field_38) >= (-24000))) && ((this->field_518->field_39 - this->field_519->field_39) <= 24000)) && ((this->field_518->field_39 - this->field_519->field_39) >= (-24000))) && (var17->field_1227 != 13)) && (var17->field_1227 != 9996)) {
                        class_84::field_1117->drawImage((var18 ? this->field_495 : this->field_481), this->field_500, this->field_501, 3);
                        this->field_521 = jrt::f2i(((float(var17->field_1225->field_370) / 100.0f) * 16.0f));
                        class_84::field_1117->setColor((-1047803));
                        class_84::field_1117->fillRect((this->field_500 + 10), (((this->field_501 + 10) - 2) - this->field_521), 2, this->field_521);
                        if (((((((this->field_523 == 2) || (this->field_523 == 4)) && (this->field_497->at(var16) != nullptr)) && (this->field_500 > class_46::field_477)) && (this->field_500 < class_46::field_478)) && (this->field_501 > class_46::field_479)) && (this->field_501 < class_46::field_480)) {
                            class_84::field_1117->drawImage(this->field_497->at(var16), (this->field_500 - 20), (this->field_501 + 10), 0);
                        }
                    } else {
                        class_84::field_1117->drawImage((var18 ? this->field_495 : this->field_487), this->field_500, this->field_501, 3);
                    }
                } else {
                    class_84::field_1117->drawImage(this->field_482, this->field_500, this->field_501, 3);
                    if (var18) {
                        class_84::field_1117->drawImage(this->field_490, this->field_500, this->field_501, 3);
                        class_84::field_1117->drawImage(this->field_496, (((this->field_505 && (!this->field_507)) && (!this->field_508)) ? (this->field_500 + 11) : (((this->field_506 && (!this->field_507)) && (!this->field_508)) ? (this->field_500 - 11) : this->field_500)), (this->field_507 ? (this->field_501 + 11) : (this->field_508 ? (this->field_501 - 11) : this->field_501)), 3);
                    }
                }
            }
        }
    }
}

jrt::Ref<java::lang::String> class_46::method_391(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_37> var4) {
    this->field_518 = var4->method_344(this->field_518);
    this->field_520->field_72 = float((this->field_518->field_37 >> 1));
    this->field_520->field_73 = float((this->field_518->field_38 >> 1));
    this->field_520->field_74 = float((this->field_518->field_39 >> 1));
    int32_t var5 = var1 >> 1;
    int32_t var6 = var2 >> 1;
    int32_t var7 = var3 >> 1;
    int32_t var8 = jrt::f2i(class_46::method_392((((((this->field_520->field_72 - float(var5)) * (this->field_520->field_72 - float(var5))) + ((this->field_520->field_73 - float(var6)) * (this->field_520->field_73 - float(var6)))) + ((this->field_520->field_74 - float(var7)) * (this->field_520->field_74 - float(var7)))) / 4096.0f))) * 12;
    jrt::Ref<java::lang::String> var9 = jrt::concat(var8, JRT_LIT(u"m"));
    if (var8 >= 1000) {
        int32_t var10{};
        if ((var10 = var8 % 1000) >= 100) {
            var9 = jrt::concat(JRT_LIT(u""), var10);
        } else {
            var9 = JRT_LIT(u"0");
        }
        var9 = var9->substring(0, 1);
        var9 = jrt::concat((var8 / 1000), JRT_LIT(u"."), var9, JRT_LIT(u"km"));
    }
    return var9;
}

float class_46::method_392(float var0) {
    float var1 = 65536.0f;
    float var2 = 65536.0f;
    for (int32_t var4 = 0; var4 < 20; var4++) {
        var1 *= 0.5f;
        float var3{};
        if ((var3 = var0 - (var2 * var2)) > 0.0f) {
            var2 += var1;
        } else if (var3 < 0.0f) {
            var2 -= var1;
        }
    }
    return var2;
}

void class_46::__dumpFields(jrt::Dumper& d) {
    d.f("field_481", this->field_481);
    d.f("field_482", this->field_482);
    d.f("field_483", this->field_483);
    d.f("field_484", this->field_484);
    d.f("field_485", this->field_485);
    d.f("field_486", this->field_486);
    d.f("field_487", this->field_487);
    d.f("field_488", this->field_488);
    d.f("field_489", this->field_489);
    d.f("field_490", this->field_490);
    d.f("field_491", this->field_491);
    d.f("field_492", this->field_492);
    d.f("field_493", this->field_493);
    d.f("field_494", this->field_494);
    d.f("field_495", this->field_495);
    d.f("field_496", this->field_496);
    d.f("field_497", this->field_497);
    d.f("field_498", this->field_498);
    d.f("field_499", this->field_499);
    d.f("field_500", this->field_500);
    d.f("field_501", this->field_501);
    d.f("field_502", this->field_502);
    d.f("field_503", this->field_503);
    d.f("field_504", this->field_504);
    d.f("field_505", this->field_505);
    d.f("field_506", this->field_506);
    d.f("field_507", this->field_507);
    d.f("field_508", this->field_508);
    d.f("field_509", this->field_509);
    d.f("field_510", this->field_510);
    d.f("field_511", this->field_511);
    d.f("field_512", this->field_512);
    d.f("field_513", this->field_513);
    d.f("field_514", this->field_514);
    d.f("field_515", this->field_515);
    d.f("field_516", this->field_516);
    d.f("field_517", this->field_517);
    d.f("field_518", this->field_518);
    d.f("field_519", this->field_519);
    d.f("field_520", this->field_520);
    d.f("field_521", this->field_521);
    d.f("field_522", this->field_522);
    d.f("field_523", this->field_523);
    d.f("field_524", this->field_524);
    d.f("field_525", this->field_525);
    d.f("field_526", this->field_526);
}

