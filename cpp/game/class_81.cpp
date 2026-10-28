// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_81::__clinit() {
}

void class_81::__init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2) {
    class_76::__init(var1, var2);
    this->class_76::field_1052 = 18;
    this->field_1068 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(18);
    jrt::Ref<javax::microedition::lcdui::Image> var3 = class_28::method_282(JRT_LIT(u"/data/interface/arrows.png"));
    this->field_1070 = [&]() { jrt::Ref<javax::microedition::lcdui::Image> __a1 = var3; int32_t __a2 = var3->getHeight(); int32_t __a3 = var3->getHeight(); jrt::Ref<javax::microedition::lcdui::game::Sprite> __o(new javax::microedition::lcdui::game::Sprite()); __o->__init(__a1, __a2, __a3); return __o; }();
}

void class_81::method_730(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var2) {
    if (var2 == nullptr) {
        jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var6{};
        (var6 = jrt::newArray<jrt::Ref<class_59>>(1))->at(0) = jrt::New<class_59>(class_84::field_1116->method_4(209));
        class_76::method_700(var1, jrt::arrayView<jrt::Ref<java::lang::Object>>(var6));
    } else {
        if (this->field_1069 == nullptr) {
            this->field_1069 = class_28::method_282(JRT_LIT(u"/data/interface/mission_story.png"));
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var3 = jrt::Ref<jrt::Array<jrt::Ref<class_59>>>(nullptr);
        if (var1 == 1) {
            if ((var2 != nullptr) && (var2->length > 0)) {
                (var3 = jrt::newArray<jrt::Ref<class_59>>((var2->length + 1)))->at(0) = jrt::New<class_59>(class_84::field_1116->method_4(309));
                for (int32_t var4 = 0; var4 < var2->length; var4++) {
                    var2->at(var4)->method_763();
                    var3->at((var4 + 1)) = jrt::New<class_59>(var2->at(var4));
                    int32_t var5 = var2->at(var4)->field_1146;
                    if (this->field_1068->at(var5) == nullptr) {
                        this->field_1068->at(var5) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/mission_"), var5, JRT_LIT(u".png")));
                    }
                }
            }
        } else {
            if (class_21::method_146()) {
                if ((!var2->at(1)->method_754()) && (var2->at(1) != nullptr)) {
                    (var3 = jrt::newArray<jrt::Ref<class_59>>(2))->at(0) = jrt::New<class_59>(class_84::field_1116->method_4(309));
                    var2->at(1)->method_763();
                    var3->at(1) = jrt::New<class_59>(var2->at(1));
                }
            } else {
                (var3 = jrt::newArray<jrt::Ref<class_59>>((((!var2->at(1)->method_754()) && (var2->at(1) != nullptr)) ? 4 : 2)))->at(0) = jrt::New<class_59>(class_84::field_1116->method_4(308));
                var2->at(0)->method_763();
                var3->at(1) = jrt::New<class_59>(var2->at(0));
                if (var3->length > 2) {
                    var3->at(2) = jrt::New<class_59>(class_84::field_1116->method_4(309));
                    var2->at(1)->method_763();
                    var3->at(3) = jrt::New<class_59>(var2->at(1));
                }
            }
            for (int32_t var7 = 0; var7 < var2->length; var7++) {
                if (((var2->at(var7) != nullptr) && (!var2->at(var7)->method_754())) && (!var2->at(var7)->field_1161)) {
                    int32_t var8 = var2->at(var7)->field_1146;
                    if (this->field_1068->at(var8) == nullptr) {
                        this->field_1068->at(var8) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/mission_"), var8, JRT_LIT(u".png")));
                    }
                }
            }
        }
        class_76::method_700(var1, jrt::arrayView<jrt::Ref<java::lang::Object>>(var3));
    }
}

void class_81::method_718() {
    class_76::method_718();
    this->method_719();
}

void class_81::method_719() {
    class_84::field_1117->setColor(class_67::field_846);
    class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    this->class_76::field_1055 = jrt::concat(class_84::field_1116->method_4(52), JRT_LIT(u": "), org::deep3d::Scale::km(class_21::method_178()->method_606(), false));
    class_58::method_516(this->class_76::field_1055, (class_84::field_1120 / 2), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), 0, 24);
}

void class_81::method_721(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    jrt::Ref<class_59> var3{};
    if ((var3 = jrt::cast<class_59>(var1))->method_539()) {
        if (((var3->field_712->field_1146 < this->field_1068->length) && (this->field_1068->at(var3->field_712->field_1146) != nullptr)) || var3->field_712->field_1161) {
            class_84::field_1117->drawImage((var3->field_712->field_1161 ? this->field_1069 : this->field_1068->at(var3->field_712->field_1146)), (this->class_74::field_1042 + 2), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + (this->method_698() / 2)) + 1), 6);
        }
        if (!var3->field_712->field_1161) {
            class_67::method_589(JRT_LIT(u""), var3->field_712->field_1150, false, (((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
            class_67::method_590(var3->field_712->field_1151, true, (((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
            class_67::method_598(var3->field_712->method_757(), ((this->class_74::field_1042 + this->class_76::field_1052) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), (((((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 4) - 4) - this->class_74::field_1035) - 30) - 2), ((this->class_74::field_1039 == var2) ? 0 : 1));
        } else {
            if (var2 == this->class_74::field_1039) {
                class_84::field_1117->fillRect(((this->class_74::field_1042 + this->class_76::field_1052) + 4), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 4) - 4) - this->class_74::field_1035), (this->class_74::field_1044 - 1));
            }
            class_67::method_598(var3->field_712->method_757(), ((this->class_74::field_1042 + this->class_76::field_1052) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 4) - 4) - this->class_74::field_1035) - 2), ((this->class_74::field_1039 == var2) ? 0 : 1));
        }
        if (var3->field_712->field_1171) {
            this->field_1071 = (var3->field_712->field_1152 == class_21::method_180()->field_1134) ? class_84::field_1116->method_4(310) : jrt::concat(JRT_LIT(u"- "), var3->field_712->field_1158, JRT_LIT(u" km -"));
            class_58::method_518(this->field_1071, ((this->class_74::field_1042 + this->class_76::field_1052) + 5), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), ((this->class_74::field_1039 == var2) ? 0 : 1));
        }
        if (!var3->field_712->field_1161) {
            this->field_1070->setFrame(var3->field_712->field_1159);
            this->field_1070->setPosition(((((this->class_74::field_1042 + this->class_76::field_1052) + 5) + class_58::method_523(this->field_1071)) + 3), ((((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8) + 2));
            this->field_1070->paint(class_84::field_1117);
            return;
        }
    } else if (var3->method_538()) {
        class_58::method_518(var3->field_714, (this->class_74::field_1042 + 3), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 5), 0);
    }
}

void class_81::__dumpFields(jrt::Dumper& d) {
    class_76::__dumpFields(d);
    d.f("field_1068", this->field_1068);
    d.f("field_1069", this->field_1069);
    d.f("field_1070", this->field_1070);
    d.f("field_1071", this->field_1071);
}

