// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_78::__clinit() {
}

void class_78::__init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2) {
    class_76::__init(var1, var2);
    this->class_76::field_1052 = 18;
    this->field_1058 = false;
    this->field_1063 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(class_90::method_785()->length);
    this->field_1065 = jrt::New<class_52>();
    this->field_1066 = jrt::New<class_121>();
    this->class_74::field_1043 = (((this->class_74::field_1028 + 11) + this->class_74::field_1045) + this->class_74::field_1044) + 2;
}

void class_78::method_714() {
    class_76::method_714();
    this->field_1062 = jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
    this->field_1063 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>>(nullptr);
    this->field_1064 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>>(nullptr);
}

void class_78::method_722(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2) {
    if (var1 == 0) {
        this->field_1062 = var2;
    }
    if (var2 != nullptr) {
        if (this->field_1064 == nullptr) {
            this->field_1064 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(3);
            for (int32_t var3 = 0; var3 < this->field_1064->length; var3++) {
                this->field_1064->at(var3) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/x_"), (var3 + 1), JRT_LIT(u".png")));
            }
        }
        if (this->field_1067 == nullptr) {
            jrt::Ref<javax::microedition::lcdui::Image> var5 = class_28::method_282(JRT_LIT(u"/data/interface/coins.png"));
            this->field_1067 = [&]() { jrt::Ref<javax::microedition::lcdui::Image> __a1 = var5; int32_t __a2 = (var5->getWidth() / 5); int32_t __a3 = var5->getHeight(); jrt::Ref<javax::microedition::lcdui::game::Sprite> __o(new javax::microedition::lcdui::game::Sprite()); __o->__init(__a1, __a2, __a3); return __o; }();
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var6 = jrt::newArray<jrt::Ref<class_59>>(var2->length);
        for (int32_t var4 = 0; var4 < var2->length; var4++) {
            var6->at(var4) = jrt::New<class_59>(var2->at(var4));
            if (this->field_1063->at(var2->at(var4)->field_1480) == nullptr) {
                this->field_1063->at(var2->at(var4)->field_1480) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var2->at(var4)->field_1480, JRT_LIT(u".png")));
            }
        }
        class_76::method_700(var1, jrt::arrayView<jrt::Ref<java::lang::Object>>(var6));
        this->field_1061 = class_21::method_178()->field_867;
        this->method_703();
    }
}

bool class_78::method_723() {
    return (this->field_1058 || this->field_1059) || this->field_1060;
}

void class_78::method_724() {
    if (this->field_1058) {
        bool var1 = false;
        for (int32_t var2 = 0; var2 < 5; var2++) {
            this->method_706();
        }
    }
}

void class_78::method_725() {
    if (this->field_1058) {
        bool var1 = false;
        for (int32_t var2 = 0; var2 < 5; var2++) {
            this->method_707();
        }
    }
}

void class_78::method_706() {
    if (this->field_1058) {
        int32_t var1{};
        if ((var1 = (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_711->method_928(false, this->field_1061)) > 0) {
            this->field_1061--;
        }
        class_21::method_197(var1);
        this->method_703();
    } else if (this->field_1059) {
        this->field_1065->method_433();
    } else {
        if (!this->field_1060) {
            class_76::method_706();
        }
    }
}

void class_78::method_707() {
    if (this->field_1058) {
        int32_t var1{};
        if ((var1 = (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_711->method_928(true, this->field_1061)) < 0) {
            this->field_1061++;
        }
        class_21::method_197(var1);
        this->method_703();
    } else if (this->field_1059) {
        this->field_1065->method_434();
    } else {
        if (!this->field_1060) {
            class_76::method_707();
        }
    }
}

void class_78::method_726() {
    if (this->field_1060) {
        this->field_1060 = false;
    } else if (this->class_74::field_1032->at(this->class_74::field_1038) != nullptr) {
        if (this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039) != nullptr) {
            jrt::Ref<class_120> var1 = (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_711;
            if (this->class_74::field_1038 == 0) {
                if ((var1->field_1490 == 0) && (class_21::method_182() < var1->field_1484)) {
                    this->field_1066->method_939(class_21::method_219(class_84::field_1116->method_4(85), jrt::concat(JRT_LIT(u""), (var1->field_1484 - class_21::method_182()))));
                    this->field_1060 = true;
                    return;
                }
                this->field_1058 = !this->field_1058;
                if (!this->field_1058) {
                    class_21::method_178()->method_611(class_120::method_934(this->field_1062, true));
                    class_21::method_180()->field_1142 = class_120::method_934(this->field_1062, false);
                    this->method_722(0, class_120::method_935(class_21::method_178()->field_886, class_21::method_180()->field_1142));
                    this->method_722(1, class_35::method_302());
                    this->method_703();
                    return;
                }
            } else {
                if (this->field_1059) {
                    if (this->field_1065->method_432() && (this->field_1065->field_589 > 0)) {
                        class_21::method_192(this->field_1065->field_589);
                        this->field_1062 = class_120::method_933((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_711, this->field_1062, this->field_1065->field_589);
                        class_21::method_193((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_711->field_1480);
                        class_21::method_178()->method_611(class_120::method_934(this->field_1062, true));
                        class_21::method_180()->field_1142 = class_120::method_934(this->field_1062, false);
                        class_21::method_220();
                        this->method_722(0, class_120::method_935(class_21::method_178()->field_886, class_21::method_180()->field_1142));
                        this->method_722(1, class_35::method_302());
                        this->method_703();
                    }
                    this->field_1059 = false;
                    return;
                }
                if (var1->field_1490 > 0) {
                    this->field_1059 = true;
                    this->field_1065->method_431(var1);
                }
            }
        }
    }
}

void class_78::method_704() {
    if (((!this->field_1058) && (!this->field_1060)) && (!this->field_1059)) {
        class_76::method_704();
    }
}

void class_78::method_705() {
    if (((!this->field_1058) && (!this->field_1060)) && (!this->field_1059)) {
        class_76::method_705();
    }
}

void class_78::method_719() {
    if (((((!this->field_1058) || (this->field_1061 < class_21::method_178()->method_607())) || (!class_67::method_581())) && this->field_1058) && (this->field_1061 >= class_21::method_178()->method_607())) {
        class_84::field_1117->setColor(class_67::field_844);
    } else {
        class_84::field_1117->setColor(class_67::field_846);
    }
    class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    this->class_76::field_1055 = jrt::concat(class_84::field_1116->method_4(60), JRT_LIT(u":"), this->field_1061, JRT_LIT(u"/"), class_21::method_178()->method_607());
    class_58::method_516(this->class_76::field_1055, (class_84::field_1120 / 2), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), 0, 24);
}

void class_78::method_718() {
    class_76::method_718();
    if (this->class_74::field_1038 == 0) {
        this->method_719();
    }
    if (this->field_1059) {
        this->field_1065->method_435();
    }
    if (this->field_1060) {
        this->field_1066->method_944();
    }
}

void class_78::method_720() {
    if (this->class_74::field_1032->at(this->class_74::field_1038) != nullptr) {
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 - this->class_74::field_1044) + 2), ((this->class_74::field_1029 - 5) - 3), (this->class_74::field_1044 - 2));
        class_58::method_518(((this->class_74::field_1038 == 0) ? class_84::field_1116->method_4(47) : class_84::field_1116->method_4(268)), (this->class_74::field_1042 + 3), ((this->class_74::field_1043 - this->class_74::field_1044) + 5), 0);
        class_58::method_516(((this->class_74::field_1038 == 0) ? class_84::field_1116->method_4(79) : JRT_LIT(u"")), (((this->class_74::field_1027 + this->class_74::field_1029) - 4) - 2), ((this->class_74::field_1043 - this->class_74::field_1044) + 5), 0, 18);
        for (int32_t var1 = this->class_74::field_1040; ((var1 < this->class_74::field_1032->at(this->class_74::field_1038)->length) && (this->class_74::field_1032->at(this->class_74::field_1038)->at(var1) != nullptr)) && (var1 < ((this->class_74::field_1040 + this->class_74::field_1041) + 1)); var1++) {
            jrt::Ref<java::lang::Object> var2 = jrt::Ref<java::lang::Object>(nullptr);
            if (var1 == this->class_74::field_1039) {
                class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), 23, (this->class_74::field_1044 - 1));
                class_84::field_1117->fillRect(((this->class_74::field_1042 + 22) + 2), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (this->class_76::field_1052 + 2), (this->class_74::field_1044 - 1));
                if (this->class_74::field_1038 == 0) {
                    class_84::field_1117->fillRect(((((this->class_74::field_1042 + 22) + 2) + this->class_76::field_1052) + 3), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 44) - 9) - this->class_74::field_1035), (this->class_74::field_1044 - 1));
                    class_84::field_1117->fillRect(((((this->class_74::field_1027 + this->class_74::field_1029) - this->class_74::field_1035) - 4) - 22), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), 23, (this->class_74::field_1044 - 1));
                } else {
                    class_84::field_1117->fillRect(((((this->class_74::field_1042 + 22) + 2) + this->class_76::field_1052) + 3), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 22) + 3) - 9) - this->class_74::field_1035), (this->class_74::field_1044 - 1));
                }
            }
            this->method_721(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1), var1);
        }
    }
}

void class_78::method_721(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    jrt::Ref<class_120> var3 = (jrt::cast<class_59>(var1))->field_711;
    class_84::field_1117->drawImage(this->field_1063->at(var3->field_1480), ((this->class_74::field_1042 + 22) + 3), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 3), 0);
    class_58::method_516(((this->class_74::field_1038 == 0) ? jrt::concat(var3->field_1491, JRT_LIT(u"t")) : jrt::concat(var3->field_1490, JRT_LIT(u" X"))), (this->class_74::field_1042 + 22), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
    class_67::method_598(jrt::concat(class_84::field_1116->method_4(int32_t(class_1::field_7->at(var3->field_1480)->at(0))), JRT_LIT(u" ")), (((this->class_74::field_1042 + 22) + this->class_76::field_1052) + 6), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->class_76::field_1052) - 44) - 9) - this->class_74::field_1035) + ((this->class_74::field_1038 == 1) ? 25 : 2)), ((this->class_74::field_1039 == var2) ? 0 : 1));
    if (this->class_74::field_1038 == 0) {
        if ((var3->field_1490 == 0) && (var3->field_1484 > class_21::method_182())) {
            class_67::method_590(var3->field_1484, (var3->field_1490 == 0), (((this->class_74::field_1042 + 22) + this->class_76::field_1052) + 6), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), 0, 0);
        } else {
            class_58::method_516(jrt::concat(var3->field_1484, JRT_LIT(u"")), (((this->class_74::field_1042 + 22) + this->class_76::field_1052) + 6), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), 0, 0);
            this->field_1067->setFrame(jrt::f2i((var3->method_925() * (float(this->field_1067->getRawFrameCount()) - 1.0f))));
            this->field_1067->setPosition(((((class_58::method_523(jrt::concat(var3->field_1484, JRT_LIT(u" "))) + this->class_74::field_1042) + 22) + this->class_76::field_1052) + 6), ((((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8) + 2));
            this->field_1067->paint(class_84::field_1117);
        }
        class_58::method_518(jrt::concat(var3->field_1490, JRT_LIT(u"t")), (((((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035) - 22) + 1), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1));
        if ((this->field_1058 && (var2 == this->class_74::field_1039)) && class_67::method_581()) {
            class_58::method_516(JRT_LIT(u"<"), (this->class_74::field_1042 + 22), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), 0, 18);
            class_58::method_518(JRT_LIT(u">"), (((((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035) - 22) + 1), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + 8), 0);
            return;
        }
    } else if (var3->field_1490 == 0) {
        int32_t var4 = var3->field_1492;
        class_84::field_1117->drawImage(((var4 == 1) ? this->field_1064->at(1) : ((var4 == var3->field_1488->length) ? this->field_1064->at(0) : this->field_1064->at(2))), ((this->class_74::field_1042 + 22) + 3), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 3), 0);
    }
}

void class_78::__dumpFields(jrt::Dumper& d) {
    class_76::__dumpFields(d);
    d.f("field_1058", this->field_1058);
    d.f("field_1059", this->field_1059);
    d.f("field_1060", this->field_1060);
    d.f("field_1061", this->field_1061);
    d.f("field_1062", this->field_1062);
    d.f("field_1063", this->field_1063);
    d.f("field_1064", this->field_1064);
    d.f("field_1065", this->field_1065);
    d.f("field_1066", this->field_1066);
    d.f("field_1067", this->field_1067);
}

