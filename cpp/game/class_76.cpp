// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_76::__clinit() {
}

void class_76::__init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2) {
    this->__init(0, 0, class_84::field_1120, class_84::field_1121, var1, var2);
}

void class_76::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6) {
    class_74::__init(var1, var2, var3, var4, var5, var6);
    this->field_1052 = 31;
    {
        try {
            this->field_1053 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(class_90::method_781()->length);
            this->field_1054 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>((class_90::method_783()->length * 2));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var8 = jrt::cast<java::lang::Exception>(__ex1.t);
                var8->printStackTrace();
            } else {
                throw;
            }
        }
    }
    if (this->field_1056 == nullptr) {
        this->field_1056 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/logo_"), (class_14::method_70() ? 2 : ((class_21::method_180()->method_752()) ? 0 : 1)), JRT_LIT(u"_t.png")));
    }
}

void class_76::method_714() {
    this->field_1053 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>>(nullptr);
    this->field_1054 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>>(nullptr);
}

void class_76::method_715(int32_t var1, jrt::Ref<class_68> var2) {
    if (var1 > (this->class_74::field_1032->length - 1)) {
        java::lang::System::out->println(jrt::concat(JRT_LIT(u"ERROR: Tab "), var1, JRT_LIT(u" not available!")));
    } else {
        jrt::Ref<java::lang::Object> var3 = jrt::Ref<java::lang::Object>(nullptr);
        jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var4 = var2->field_885;
        var3 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_59>>((var2->field_885->length + 3)));
        int32_t var5 = 0;
        var5++;
        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(0) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(class_84::field_1116->method_4(79)));
        var5++;
        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(1) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(var2));
        bool var6 = var2->field_884;
        int32_t var7 = (jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(1)))->method_545() + (var6 ? class_90::method_783()->length : 0);
        if (this->field_1054->at(var7) == nullptr) {
            this->field_1054->at(var7) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/u"), (jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(1)))->method_545(), (var6 ? JRT_LIT(u"b") : JRT_LIT(u"a")), JRT_LIT(u".png")));
        }
        var5++;
        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(2) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(class_84::field_1116->method_4(69)));
        for (int32_t var8 = 0; var8 < var4->length; var8++) {
            if (var4->at(var8) != nullptr) {
                (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var5++)) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(var4->at(var8)));
                if (this->field_1053->at((jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var5 - 1))))->method_545()) == nullptr) {
                    this->field_1053->at((jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var5 - 1))))->method_545()) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/slot_"), (jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var5 - 1))))->method_545(), JRT_LIT(u".png")));
                }
            } else {
                (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var5++)) = jrt::Ref<java::lang::Object>(jrt::New<class_59>(var8));
            }
        }
        bool var15{};
        do {
            var15 = true;
            for (int32_t var9 = 4; var9 < (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->length; var9++) {
                if ((jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var9 - 1))))->method_545() > (jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(var9)))->method_545()) {
                    jrt::Ref<class_59> var10 = jrt::cast<class_59>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var9 - 1)));
                    (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at((var9 - 1)) = (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(var9);
                    (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3))->at(var9) = jrt::Ref<java::lang::Object>(var10);
                    var15 = false;
                }
            }
        } while (!var15);
        this->class_74::field_1032->at(var1) = jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var3);
        if (this->class_74::field_1032->at(var1) == nullptr) {
            this->class_74::field_1033->at(var1) = 0;
        } else if (this->class_74::field_1032->at(var1)->length == 0) {
            this->class_74::field_1032->at(var1) = jrt::Ref<jrt::Array<jrt::Ref<java::lang::Object>>>(nullptr);
            this->class_74::field_1033->at(var1) = 0;
        } else {
            this->class_74::field_1033->at(var1) = this->class_74::field_1032->at(var1)->length;
        }
        this->class_74::field_1041 = this->class_74::field_1032->at(var1)->length;
        this->class_74::field_1033->at(var1) = this->class_74::field_1041;
        this->method_703();
    }
}

void class_76::method_716(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var2, jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var3) {
    if (var1 > (this->class_74::field_1032->length - 1)) {
        java::lang::System::out->println(jrt::concat(JRT_LIT(u"ERROR: Tab "), var1, JRT_LIT(u" not available!")));
    } else {
        int32_t var4 = 0;
        int8_t var5 = int8_t(0);
        int32_t var6{};
        var4 = ((var6 = (var3 == nullptr) ? 0 : var3->length) > 0) ? 1 : 0;
        int32_t var7{};
        if ((var7 = (var2 == nullptr) ? 0 : var2->length) > 0) {
            var5 = int8_t(1);
        }
        int32_t var8 = ((var7 + var6) + var4) + int32_t(var5);
        jrt::Ref<jrt::Array<jrt::Ref<class_59>>> var9 = jrt::Ref<jrt::Array<jrt::Ref<class_59>>>(nullptr);
        if (var8 > 0) {
            var9 = jrt::newArray<jrt::Ref<class_59>>(var8);
        }
        int32_t var10 = 0;
        if (var4 > 0) {
            var10++;
            var9->at(0) = jrt::New<class_59>(class_84::field_1116->method_4(68));
        }
        for (int32_t var11 = 0; var11 < var6; var11++) {
            var9->at((var10++)) = jrt::New<class_59>(var3->at(var11));
            bool var12 = var3->at(var11)->field_884;
            int32_t var13 = var9->at((var10 - 1))->method_545() + (var12 ? class_90::method_783()->length : 0);
            if (this->field_1054->at(var13) == nullptr) {
                this->field_1054->at(var13) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/u"), var9->at((var10 - 1))->method_545(), (var12 ? JRT_LIT(u"b") : JRT_LIT(u"a")), JRT_LIT(u".png")));
            }
        }
        if (int32_t(var5) > 0) {
            var9->at((var10++)) = jrt::New<class_59>(class_84::field_1116->method_4(69));
        }
        for (int32_t var15 = 0; var15 < var7; var15++) {
            var9->at((var10++)) = jrt::New<class_59>(var2->at(var15));
            if (this->field_1053->at(var9->at((var10 - 1))->method_545()) == nullptr) {
                this->field_1053->at(var9->at((var10 - 1))->method_545()) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/equipment/slot_"), var9->at((var10 - 1))->method_545(), JRT_LIT(u".png")));
            }
        }
        if (var9 != nullptr) {
            if ((var9->length > 0) && (this->class_74::field_1039 >= var9->length)) {
                this->class_74::field_1039 = var9->length - 1;
            }
            bool var16{};
            do {
                var16 = true;
                for (int32_t var17 = ((var6 + var4) + int32_t(var5)) + 1; var17 < var9->length; var17++) {
                    if (var9->at((var17 - 1))->method_545() > var9->at(var17)->method_545()) {
                        jrt::Ref<class_59> var18 = var9->at((var17 - 1));
                        var9->at((var17 - 1)) = var9->at(var17);
                        var9->at(var17) = var18;
                        var16 = false;
                    }
                }
            } while (!var16);
        }
        this->class_74::field_1032->at(var1) = jrt::arrayView<jrt::Ref<java::lang::Object>>(var9);
        if (this->class_74::field_1032->at(var1) == nullptr) {
            this->class_74::field_1033->at(var1) = 0;
        } else {
            this->class_74::field_1033->at(var1) = this->class_74::field_1032->at(var1)->length;
        }
        this->method_703();
    }
}

void class_76::method_704() {
    bool var1 = false;
    int32_t var2 = this->class_74::field_1039;
    for (int32_t var3 = this->class_74::field_1039; var3 > 0; var3--) {
        if ((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at((var3 - 1))))->field_713) {
            var1 = true;
            break;
        }
        var2--;
    }
    if ((this->class_74::field_1039 == 0) || ((this->class_74::field_1039 == 1) && (!(jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(0)))->field_713))) {
        var2 = this->class_74::field_1033->at(this->class_74::field_1038) - 1;
        this->class_74::field_1039 = this->class_74::field_1033->at(this->class_74::field_1038) - 1;
        this->class_74::field_1040 = (this->class_74::field_1033->at(this->class_74::field_1038) - this->class_74::field_1041) - 1;
    }
    if (var1) {
        class_74::method_704();
    }
    if ((var2 > 0) && (!(jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_713)) {
        this->method_704();
    }
    this->method_703();
}

void class_76::method_705() {
    bool var1 = false;
    int32_t var2 = this->class_74::field_1039;
    for (int32_t var3 = this->class_74::field_1039; var3 < (this->class_74::field_1033->at(this->class_74::field_1038) - 1); var3++) {
        if ((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at((var3 + 1))))->field_713) {
            var1 = true;
            break;
        }
        var2++;
    }
    if (this->class_74::field_1039 == (this->class_74::field_1033->at(this->class_74::field_1038) - 1)) {
        var2 = 0;
        this->class_74::field_1039 = 0;
        this->class_74::field_1040 = 0;
    }
    if (var1) {
        class_74::method_705();
    }
    if ((var2 < (this->class_74::field_1033->at(this->class_74::field_1038) - 1)) && (!(jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_713)) {
        this->method_705();
    }
    this->method_703();
}

void class_76::method_703() {
    class_74::method_703();
    if (((this->class_74::field_1033->at(this->class_74::field_1038) > 0) && (this->class_74::field_1039 == 0)) && (!this->method_717())) {
        this->class_74::field_1039++;
        class_74::method_703();
    }
}

bool class_76::method_717() {
    return (this->class_74::field_1033->at(this->class_74::field_1038) == 0) ? false : (jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(this->class_74::field_1039)))->field_713;
}

void class_76::registerRows() {
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::Object>>> var1 = this->class_74::field_1032->at(this->class_74::field_1038);
    for (int32_t var2 = this->class_74::field_1040; (((var1 != nullptr) && (var2 < var1->length)) && (var1->at(var2) != nullptr)) && (var2 < ((this->class_74::field_1040 + this->class_74::field_1041) + 1)); var2++) {
        org::deep3d::GameUi::row((this->class_74::field_1027 + 4), (this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)), (this->class_74::field_1029 - 8), this->class_74::field_1044, (var2 == this->class_74::field_1039), (jrt::cast<class_59>(var1->at(var2)))->field_713);
    }
}

void class_76::method_718() {
    this->registerRows();
    this->method_710();
    class_67::method_591(this->class_74::field_1050, this->class_74::field_1027, this->class_74::field_1028, this->class_74::field_1029, this->class_74::field_1030);
    class_84::field_1117->drawImage(this->field_1056, (class_84::field_1120 - 20), ((class_84::field_1121 - 30) - class_67::method_577()), 40);
    this->method_708();
    this->method_720();
    this->method_709();
}

void class_76::method_719() {
    class_84::field_1117->setColor(class_67::field_846);
    class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), (this->class_74::field_1029 - 8), 10);
    this->field_1055 = jrt::concat(class_84::field_1116->method_4(329), JRT_LIT(u":"), class_21::method_178()->method_623(), JRT_LIT(u"/"), class_21::method_178()->field_869);
    class_58::method_516(this->field_1055, (class_84::field_1120 / 2), ((this->class_74::field_1028 + this->class_74::field_1030) - 14), 0, 24);
}

void class_76::method_720() {
    if (this->class_74::field_1032->at(this->class_74::field_1038) != nullptr) {
        class_84::field_1117->setColor(class_67::field_844);
        for (int32_t var1 = this->class_74::field_1040; ((var1 < this->class_74::field_1032->at(this->class_74::field_1038)->length) && (this->class_74::field_1032->at(this->class_74::field_1038)->at(var1) != nullptr)) && (var1 < ((this->class_74::field_1040 + this->class_74::field_1041) + 1)); var1++) {
            if ((jrt::cast<class_59>(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1)))->method_538()) {
                class_84::field_1117->setColor(class_67::field_846);
                class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((this->class_74::field_1029 - 5) - this->class_74::field_1035) - 3), (this->class_74::field_1044 - 2));
                class_84::field_1117->setColor(class_67::field_844);
                class_84::field_1117->drawRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (((this->class_74::field_1029 - 5) - this->class_74::field_1035) - 3), (this->class_74::field_1044 - 2));
            } else if (var1 == this->class_74::field_1039) {
                class_84::field_1117->fillRect((this->class_74::field_1027 + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), (this->field_1052 + 3), (this->class_74::field_1044 - 1));
                class_84::field_1117->fillRect(((this->class_74::field_1042 + this->field_1052) + 4), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->field_1052) - 4) - 4) - this->class_74::field_1035) - 34), (this->class_74::field_1044 - 1));
                class_84::field_1117->fillRect(((((this->class_74::field_1027 + this->class_74::field_1029) - 5) - this->class_74::field_1035) - 33), ((this->class_74::field_1043 + ((var1 - this->class_74::field_1040) * this->class_74::field_1044)) + 2), 35, (this->class_74::field_1044 - 1));
            }
            this->method_721(this->class_74::field_1032->at(this->class_74::field_1038)->at(var1), var1);
        }
    }
}

void class_76::method_721(jrt::Ref<java::lang::Object> var1, int32_t var2) {
    jrt::Ref<class_59> var3{};
    if ((var3 = jrt::cast<class_59>(var1))->method_538()) {
        class_58::method_518(var3->field_714, (this->class_74::field_1042 + 3), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 5), 0);
    } else if (var3->method_535()) {
        class_84::field_1117->drawImage(this->field_1054->at((var3->field_709->field_863 + (var3->field_709->field_884 ? class_90::method_783()->length : 0))), (this->class_74::field_1042 + 2), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + (this->method_698() / 2)) + 1), 6);
        class_58::method_518(class_84::field_1116->method_4(int32_t(class_1::field_8->at(var3->field_709->field_863)->at(0))), ((this->class_74::field_1042 + this->field_1052) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1));
        class_67::method_590(var3->field_709->method_603(), (((var3->field_709->method_603() - class_21::method_178()->method_603()) <= class_21::method_182()) ? false : (this->class_74::field_1038 == 1)), ((((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035) + 2), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
    } else if (!var3->method_536()) {
        if (var3->method_540()) {
            class_58::method_518(class_84::field_1116->method_4(70), ((this->class_74::field_1042 + this->field_1052) + 5), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 3), ((this->class_74::field_1039 == var2) ? 0 : 1));
            class_84::field_1117->drawRect((this->class_74::field_1027 + 4), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 2) + 4), (this->field_1052 + 2), ((this->class_74::field_1044 - 2) - 8));
            class_58::method_516(JRT_LIT(u"-"), (((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
        }
    } else {
        if (this->class_74::field_1038 == 0) {
            class_84::field_1117->drawRect((this->class_74::field_1027 + 4), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 2) + 4), (this->field_1052 + 2), ((this->class_74::field_1044 - 2) - 8));
        }
        class_84::field_1117->drawImage(this->field_1053->at(var3->field_710->field_166), (this->class_74::field_1042 + 2), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + (this->method_698() / 2)) + 1), 6);
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var4 = class_58::method_532(class_84::field_1116->method_4(int32_t(class_1::field_6->at(var3->field_710->field_166)->at(0))), ((((((this->class_74::field_1029 - this->class_74::field_1042) - this->field_1052) - 4) - 4) - this->class_74::field_1035) - 30));
        for (int32_t var5 = 0; (var5 < var4->length) && (var5 < 2); var5++) {
            class_58::method_518(var4->at(var5), ((this->class_74::field_1042 + this->field_1052) + 5), (((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1) + (var5 * 8)), ((this->class_74::field_1039 == var2) ? 0 : 1));
        }
        class_67::method_590(var3->field_710->field_167, (this->class_74::field_1038 == 1), ((((this->class_74::field_1027 + this->class_74::field_1029) - 4) - this->class_74::field_1035) + 2), ((this->class_74::field_1043 + ((var2 - this->class_74::field_1040) * this->class_74::field_1044)) + 1), ((this->class_74::field_1039 == var2) ? 0 : 1), 18);
    }
}

int32_t class_76::method_698() {
    return 18;
}

int32_t class_76::method_699() {
    return class_58::method_527() + 4;
}

void class_76::__dumpFields(jrt::Dumper& d) {
    class_74::__dumpFields(d);
    d.f("field_1052", this->field_1052);
    d.f("field_1053", this->field_1053);
    d.f("field_1054", this->field_1054);
    d.f("field_1055", this->field_1055);
    d.f("field_1056", this->field_1056);
}

