// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_10::__clinit() {
}

void class_10::__init() {
}

void class_10::method_51(jrt::Ref<class_59> var1, bool var2) {
    this->field_102 = var1;
    if (var1->method_536()) {
        this->field_114 = 31;
        this->field_105 = class_84::field_1116->method_4(int32_t(class_1::field_6->at(var1->method_545())->at(0)));
        this->field_104 = class_84::field_1116->method_4(int32_t(class_1::field_6->at(var1->method_545())->at(1)));
        int32_t var3 = var1->field_710->field_165;
        {
            switch (var1->field_710->field_165) {
            case 0:
                ;
            case 1:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(48), class_84::field_1116->method_4(49), class_84::field_1116->method_4(52), class_84::field_1116->method_4(56)});
                break;
            case 2:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(54), class_84::field_1116->method_4(55), class_84::field_1116->method_4(49), class_84::field_1116->method_4(56)});
                break;
            case 3:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(50), class_84::field_1116->method_4(51), class_84::field_1116->method_4(245)});
                break;
            case 4:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(50), class_84::field_1116->method_4(245)});
                break;
            case 5:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(57)});
                break;
            case 6:
                ;
            case 7:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(57)});
                break;
            case 8:
                ;
            case 10:
                this->field_106 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
                this->field_107 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
                break;
            case 9:
                this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(56), class_84::field_1116->method_4(53), class_84::field_1116->method_4(51)});
            }
        }
        if (this->field_106 != nullptr) {
            this->field_107 = jrt::newArray<jrt::Ref<java::lang::String>>(this->field_106->length);
            for (int32_t var4 = 0; var4 < this->field_107->length; var4++) {
                this->field_107->at(var4) = jrt::concat(JRT_LIT(u""), var1->field_710->method_117(var4));
                if ((([&]() { auto __l1 = this->field_106->at(var4); auto __r1 = class_84::field_1116->method_4(49); return (__l1 == __r1); }()) || ([&]() { auto __l2 = this->field_106->at(var4); auto __r2 = class_84::field_1116->method_4(51); return (__l2 == __r2); }())) || ([&]() { auto __l3 = this->field_106->at(var4); auto __r3 = class_84::field_1116->method_4(53); return (__l3 == __r3); }())) {
                    this->field_107->at(var4) = jrt::concat(this->field_107->at(var4), JRT_LIT(u" ms"));
                } else if (([&]() { auto __l4 = this->field_106->at(var4); auto __r4 = class_84::field_1116->method_4(54); return (__l4 == __r4); }()) || ([&]() { auto __l5 = this->field_106->at(var4); auto __r5 = class_84::field_1116->method_4(245); return (__l5 == __r5); }())) {
                    this->field_107->at(var4) = jrt::concat(org::deep3d::Scale::depth(var1->field_710->method_117(var4)), JRT_LIT(u" m"));
                } else if ([&]() { auto __l6 = this->field_106->at(var4); auto __r6 = class_84::field_1116->method_4(52); return (__l6 == __r6); }()) {
                    int32_t var5{};
                    int32_t var6 = (var5 = java::lang::Integer::parseInt(this->field_107->at(var4)) / 3) % 10;
                    var5 = (((var5 + var6) % 10) == 0) ? (var5 + var6) : (var5 - var6);
                    this->field_107->at(var4) = jrt::concat(org::deep3d::Scale::dist(var5), JRT_LIT(u" m"));
                } else if (([&]() { auto __l7 = this->field_106->at(var4); auto __r7 = class_84::field_1116->method_4(57); return (__l7 == __r7); }()) || ([&]() { auto __l8 = this->field_106->at(var4); auto __r8 = class_84::field_1116->method_4(55); return (__l8 == __r8); }())) {
                    this->field_107->at(var4) = jrt::concat(JRT_LIT(u"+"), this->field_107->at(var4), JRT_LIT(u"%"));
                }
                if (([&]() { auto __l9 = this->field_106->at(var4); auto __r9 = class_84::field_1116->method_4(51); return (__l9 == __r9); }()) && (var1->field_710->method_117(var4) == 0)) {
                    this->field_107->at(var4) = JRT_LIT(u"-");
                }
            }
        }
    } else if (var1->method_535()) {
        int32_t var8 = var1->field_709->field_872 + var1->field_709->field_871;
        int32_t var14 = var1->field_709->field_874;
        int32_t var21 = jrt::f2i((((float(var1->field_709->field_880) / 100.0f) * var1->field_709->field_870) * 100.0f));
        this->field_114 = 31;
        this->field_105 = class_84::field_1116->method_4(int32_t(class_1::field_8->at(var1->method_545())->at(0)));
        this->field_104 = class_84::field_1116->method_4(int32_t(class_1::field_8->at(var1->method_545())->at(1)));
        this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(59), class_84::field_1116->method_4(60), class_84::field_1116->method_4(329), class_84::field_1116->method_4(58)});
        this->field_107 = jrt::arrayOf<jrt::Ref<java::lang::String>>({jrt::concat(var1->field_709->field_864, ((var8 > 0) ? jrt::concat(JRT_LIT(u"+"), var8) : JRT_LIT(u""))), jrt::concat(var1->field_709->field_866, ((var14 > 0) ? jrt::concat(JRT_LIT(u"t+"), var14, JRT_LIT(u"t")) : JRT_LIT(u""))), jrt::concat(JRT_LIT(u""), var1->field_709->field_869), jrt::concat(JRT_LIT(u""), jrt::f2i((var1->field_709->field_870 * 100.0f)), ((var21 > 0) ? jrt::concat(JRT_LIT(u"+"), var21) : JRT_LIT(u"")))});
    } else if (var1->method_537()) {
        this->field_114 = 18;
        this->field_104 = JRT_LIT(u"");
        this->field_111 = var1->field_711->field_1490 > 0;
        this->field_110 = class_28::method_282(JRT_LIT(u"/data/interface/x_1.png"));
        this->field_105 = class_84::field_1116->method_4(int32_t(class_1::field_7->at(var1->field_711->field_1480)->at(0)));
        if (var1->field_711->field_1488 != nullptr) {
            this->field_104 = jrt::concat(class_84::field_1116->method_4(330), JRT_LIT(u":\n\n"));
            for (int32_t var9 = 0; var9 < var1->field_711->field_1488->length; var9++) {
                this->field_104 = jrt::concat(this->field_104, var1->field_711->field_1489->at(var9), JRT_LIT(u"t "), class_84::field_1116->method_4(int32_t(class_1::field_7->at(class_90::method_785()->at(int32_t(var1->field_711->field_1488->at(var9)))->field_1480)->at(0))), JRT_LIT(u"\n"));
            }
            this->field_104 = jrt::concat(this->field_104, JRT_LIT(u"\n"));
        }
        this->field_104 = jrt::concat(this->field_104, class_84::field_1116->method_4(int32_t(class_1::field_7->at(var1->field_711->field_1480)->at(1))));
        this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(42)});
        this->field_107 = jrt::arrayOf<jrt::Ref<java::lang::String>>({JRT_LIT(u"")});
        if (var1->field_711->field_1488 != nullptr) {
            this->field_109 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(var1->field_711->field_1488->length);
            this->field_112 = jrt::newArray<bool>(this->field_109->length);
            for (int32_t var10 = 0; var10 < this->field_109->length; var10++) {
                this->field_109->at(var10) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var1->field_711->field_1488->at(var10), JRT_LIT(u".png")));
                this->field_112->at(var10) = class_120::method_932(int32_t(var1->field_711->field_1488->at(var10)), class_21::method_178()->field_886);
            }
        } else {
            this->field_109 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>>(nullptr);
        }
    } else if (var1->method_539()) {
        this->field_114 = 18;
        this->field_105 = var1->field_712->method_757();
        this->field_104 = class_21::method_219(var1->field_712->method_758(), ((var1->field_712->field_1146 == 6) ? jrt::concat(JRT_LIT(u""), var1->field_712->field_1169) : var1->field_712->field_1153));
        if (var1->field_712->field_1146 == 16) {
            this->field_104 = jrt::concat(this->field_104, JRT_LIT(u" "), class_21::method_202(), JRT_LIT(u" / "), var1->field_712->field_1170);
        } else if (var1->field_712->field_1146 == 18) {
            this->field_104 = jrt::concat(this->field_104, JRT_LIT(u" "), class_21::method_177(), JRT_LIT(u" / "), var1->field_712->field_1170);
        } else if (var1->field_712->field_1146 == 21) {
            this->field_104 = jrt::concat(this->field_104, JRT_LIT(u" "), class_21::method_191(), JRT_LIT(u" / "), var1->field_712->field_1170);
        } else if (var1->field_712->field_1146 == 15) {
            this->field_104 = jrt::concat(this->field_104, JRT_LIT(u" "), class_21::method_209(), JRT_LIT(u" / "), var1->field_712->field_1170);
        }
        jrt::Ref<java::lang::String> var11 = (var1->field_712->field_1155 < 0) ? class_84::field_1116->method_4(335) : jrt::concat(JRT_LIT(u""), var1->field_712->field_1155);
        if ((var1->field_712 == class_21::method_135()) && (var1->field_712->field_1155 > 0)) {
            var11 = jrt::concat((var1->field_712->field_1156 + 1), JRT_LIT(u"/"), var1->field_712->field_1155);
        }
        jrt::Ref<java::lang::String> var15 = jrt::concat((var1->field_712->field_1150 - var1->field_712->field_1151), JRT_LIT(u" $"));
        if (var1->field_712->field_1161) {
            this->field_106 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
            this->field_107 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
        } else if ((var1->field_712->field_1146 == 14) || (var1->field_712->field_1146 == 13)) {
            this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(332)});
            this->field_107 = jrt::arrayOf<jrt::Ref<java::lang::String>>({var15});
        } else if (var1->field_712->field_1146 == 8) {
            this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(334), class_84::field_1116->method_4(245), class_84::field_1116->method_4(333), class_84::field_1116->method_4(331), class_84::field_1116->method_4(332)});
            this->field_107 = jrt::arrayOf<jrt::Ref<java::lang::String>>({var1->field_712->field_1153, jrt::concat(org::deep3d::Scale::depth(var1->field_712->field_1160), JRT_LIT(u" m")), ((var1->field_712->field_1158 == 0) ? class_84::field_1116->method_4(310) : org::deep3d::Scale::km(var1->field_712->field_1158, true)), var11, var15});
        } else {
            int32_t var22 = var1->field_712->method_764();
            jrt::Ref<java::lang::String> var23 = class_84::field_1116->method_4(((var22 < 4) ? 273 : ((var22 < 8) ? 274 : 275)));
            this->field_106 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(334), class_84::field_1116->method_4(245), class_84::field_1116->method_4(333), class_84::field_1116->method_4(39), class_84::field_1116->method_4(332)});
            this->field_107 = jrt::arrayOf<jrt::Ref<java::lang::String>>({var1->field_712->field_1153, jrt::concat(org::deep3d::Scale::depth(var1->field_712->field_1160), JRT_LIT(u" m")), ((var1->field_712->field_1158 == 0) ? class_84::field_1116->method_4(310) : org::deep3d::Scale::km(var1->field_712->field_1158, true)), var23, var15});
        }
        class_119::method_921(var1->field_712->field_1148);
    }
    if ((!var1->method_539()) && (!var1->method_537())) {
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var12{};
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var16{};
        if (this->field_107 == nullptr) {
            var12 = jrt::newArray<jrt::Ref<java::lang::String>>(1);
            var16 = jrt::newArray<jrt::Ref<java::lang::String>>(1);
        } else {
            var12 = jrt::newArray<jrt::Ref<java::lang::String>>((this->field_106->length + 1));
            var16 = jrt::newArray<jrt::Ref<java::lang::String>>((this->field_107->length + 1));
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_106), 0, jrt::Ref<java::lang::Object>(var12), 0, this->field_106->length);
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_107), 0, jrt::Ref<java::lang::Object>(var16), 0, this->field_107->length);
        }
        var12->at((var12->length - 1)) = class_84::field_1116->method_4(42);
        var16->at((var16->length - 1)) = jrt::concat(var1->method_544(), JRT_LIT(u" $"));
        this->field_107 = var16;
        this->field_106 = var12;
    }
    this->field_113 = (class_84::field_1121 - 10) - ((this->field_107 == nullptr) ? 0 : ((this->field_107->length * 10) + 6));
    int32_t var13 = (var1->method_537() && (this->field_109 != nullptr)) ? 22 : 0;
    this->field_108 = jrt::New<class_23>(5, (34 + var13), (class_84::field_1120 - 10), ((((this->field_113 - 2) - 12) - 22) - var13), this->field_104);
    if (var1->method_539() && (!var1->field_712->field_1161)) {
        this->field_108->method_226(var1->field_712->field_1148, jrt::concat(class_84::field_1116->method_4(142), JRT_LIT(u":\n"), var1->field_712->field_1147), true);
    }
    {
        try {
            if (var1->method_535()) {
                bool var17 = var1->field_709->field_884;
                this->field_103 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/u"), var1->method_545(), (var17 ? JRT_LIT(u"b") : JRT_LIT(u"a")), JRT_LIT(u".png")));
            } else if (var1->method_536()) {
                this->field_103 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/slot_"), var1->method_545(), JRT_LIT(u".png")));
            } else if (var1->method_539()) {
                if (var1->field_712->field_1161) {
                    this->field_103 = class_28::method_282(JRT_LIT(u"/data/interface/mission_story.png"));
                } else {
                    this->field_103 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/mission_"), var1->field_712->field_1146, JRT_LIT(u".png")));
                    if ((var1->field_712->field_1146 == 13) || (var1->field_712->field_1146 == 14)) {
                        jrt::Ref<javax::microedition::lcdui::Image> var19 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var1->field_712->field_1164, JRT_LIT(u".png")));
                        this->field_108->method_228(var19, var1->field_712->field_1165, var1->field_712->field_1164);
                    } else if ((var1->field_712->field_1146 == 7) || (var1->field_712->field_1146 == 6)) {
                        jrt::Ref<javax::microedition::lcdui::Image> var18 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var1->field_712->field_1166, JRT_LIT(u".png")));
                        this->field_108->method_228(var18, (-1), var1->field_712->field_1166);
                    }
                }
            } else {
                this->field_103 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var1->method_545(), JRT_LIT(u".png")));
            }
        } catch (const jrt::Thrown& __ex10) {
            if (jrt::isInstance<java::lang::Exception>(__ex10.t)) {
                jrt::Ref<java::lang::Exception> var7 = jrt::cast<java::lang::Exception>(__ex10.t);
                var7->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_10::method_52(int32_t var1) {
    this->field_108->method_230(var1);
}

void class_10::deep3dHeldUp(int32_t var1) {
    this->field_108->deep3dHeldUp(var1);
}

void class_10::deep3dHeldDown(int32_t var1) {
    this->field_108->deep3dHeldDown(var1);
}

void class_10::method_53(int32_t var1) {
    this->field_108->method_229(var1);
}

void class_10::method_54() {
    class_67::method_587();
    class_67::method_588(class_84::field_1116->method_4(226));
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect(3, 12, (class_84::field_1120 - 7), 18);
    if (this->field_103 != nullptr) {
        class_84::field_1117->drawImage(this->field_103, 5, 14, 0);
    }
    if ((this->field_102->method_537() && (!this->field_111)) && (this->field_109 != nullptr)) {
        class_84::field_1117->drawImage(this->field_110, 5, 14, 0);
    }
    class_67::method_598(this->field_105, ((3 + this->field_114) + 4), 16, ((class_84::field_1120 - this->field_114) - 12), 0);
    if (this->field_102->method_537() && (this->field_109 != nullptr)) {
        for (int32_t var1 = 0; var1 < this->field_109->length; var1++) {
            class_84::field_1117->drawImage(this->field_109->at(var1), (4 + (22 * var1)), 34, 0);
            if (!this->field_112->at(var1)) {
                class_84::field_1117->drawImage(this->field_110, (4 + (22 * var1)), 34, 0);
            }
            if (var1 > 0) {
                class_58::method_518(JRT_LIT(u"+"), ((4 + (22 * var1)) - 4), 42, 0);
            }
        }
    }
    this->field_108->method_231();
    class_84::field_1117->drawLine(3, this->field_113, (class_84::field_1120 - 6), this->field_113);
    int32_t var3 = this->field_113;
    if (this->field_107 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_107->length; var2++) {
            class_84::field_1117->drawLine(3, var3, (class_84::field_1120 - 4), var3);
            class_58::method_518(this->field_106->at(var2), 4, var3, 0);
            if ((this->field_102->method_539() && class_67::method_581()) && (((([&]() { auto __l1 = this->field_106->at(var2); auto __r1 = class_84::field_1116->method_4(245); return (__l1 == __r1); }()) && ((this->field_102->field_712->field_1160 > class_21::method_178()->field_890) || (this->field_102->field_712->field_1160 < class_21::method_178()->field_889))) || (([&]() { auto __l2 = this->field_106->at(var2); auto __r2 = class_84::field_1116->method_4(333); return (__l2 == __r2); }()) && (this->field_102->field_712->field_1158 > class_21::method_178()->method_606()))) || (([&]() { auto __l3 = this->field_106->at(var2); auto __r3 = class_84::field_1116->method_4(331); return (__l3 == __r3); }()) && (this->field_102->field_712->field_1155 > 0)))) {
                class_84::field_1117->setColor(255, 0, 0);
                class_84::field_1117->fillRect(((class_84::field_1120 - 6) - class_58::method_523(this->field_107->at(var2))), (var3 + 1), (class_58::method_523(this->field_107->at(var2)) + 3), (class_58::method_527() - 1));
                class_84::field_1117->setColor(class_67::field_844);
            }
            if (this->field_102->method_537()) {
                class_67::method_590(this->field_102->field_711->field_1486, false, ((class_84::field_1120 - 4) - class_58::method_523(jrt::concat(JRT_LIT(u" $  - "), this->field_102->field_711->field_1487))), var3, 0, 18);
                class_67::method_589(JRT_LIT(u" - "), this->field_102->field_711->field_1487, false, (class_84::field_1120 - 4), var3, 0, 18);
            } else {
                class_58::method_516(this->field_107->at(var2), (class_84::field_1120 - 4), var3, 0, 18);
            }
            var3 += 10;
        }
    }
}

void class_10::__dumpFields(jrt::Dumper& d) {
    d.f("field_102", this->field_102);
    d.f("field_103", this->field_103);
    d.f("field_104", this->field_104);
    d.f("field_105", this->field_105);
    d.f("field_106", this->field_106);
    d.f("field_107", this->field_107);
    d.f("field_108", this->field_108);
    d.f("field_109", this->field_109);
    d.f("field_110", this->field_110);
    d.f("field_111", this->field_111);
    d.f("field_112", this->field_112);
    d.f("field_113", this->field_113);
    d.f("field_114", this->field_114);
}

