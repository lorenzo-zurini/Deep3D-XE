// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_74::__clinit() {
}

void class_74::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6) {
    this->field_1044 = 8;
    this->method_697(var1, var2, var3, var4, var5, var6);
    this->field_1038 = 0;
    this->field_1047 = true;
    this->field_1048 = true;
}

void class_74::method_697(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6) {
    if ((((var1 == 0) && (var2 == 0)) && (var3 == class_84::field_1120)) && (var4 == class_84::field_1121)) {
        var2 = 1;
        var1 = 1;
        var3 -= 3;
        var4 = (var4 - 6) - 10;
    }
    this->field_1027 = var1;
    this->field_1028 = var2;
    this->field_1029 = var3;
    this->field_1030 = var4;
    this->field_1037 = true;
    if (var5 == nullptr) {
        var5 = jrt::arrayOf<jrt::Ref<java::lang::String>>({JRT_LIT(u"")});
        this->field_1037 = false;
    }
    this->field_1050 = var6;
    this->field_1031 = var5;
    this->field_1032 = jrt::newMultiArray<jrt::Ref<java::lang::Object>, 2>({var5->length, 30});
    this->field_1033 = jrt::newArray<int32_t>(var5->length);
    for (int32_t var7 = 0; var7 < this->field_1033->length; var7++) {
        this->field_1033->at(var7) = 30;
    }
    this->field_1046 = 0;
    this->field_1039 = 0;
    this->field_1038 = 0;
    this->field_1040 = 0;
    this->field_1044 = this->method_698();
    this->field_1045 = this->method_699();
    this->field_1042 = var1 + 4;
    if (this->field_1037) {
        this->field_1043 = (var2 + 11) + this->field_1045;
    } else {
        this->field_1043 = var2 + 11;
    }
    for (int32_t var8 = 0; var8 < var5->length; var8++) {
        this->field_1038 = var8;
        this->method_703();
    }
}

int32_t class_74::method_698() {
    return this->field_1044;
}

int32_t class_74::method_699() {
    return 16;
}

void class_74::method_700(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<java::lang::Object>>> var2) {
    if (var1 > (this->field_1032->length - 1)) {
        java::lang::System::out->println(jrt::concat(JRT_LIT(u"ERROR: Tab "), var1, JRT_LIT(u" not available!")));
    } else {
        this->field_1032->at(var1) = jrt::newArray<jrt::Ref<java::lang::Object>>(30);
        if (var2 != nullptr) {
            for (int32_t var3 = 0; var3 < var2->length; var3++) {
                this->field_1032->at(var1)->at(var3) = var2->at(var3);
            }
        }
        this->method_703();
    }
}

jrt::Ref<java::lang::Object> class_74::method_701() {
    if (this->field_1039 < 0) {
        this->field_1039 = 0;
        return jrt::Ref<java::lang::Object>(nullptr);
    } else {
        return (this->field_1032->at(this->field_1038) == nullptr) ? jrt::Ref<java::lang::Object>(nullptr) : this->field_1032->at(this->field_1038)->at(this->field_1039);
    }
}

void class_74::method_702(int32_t var1) {
    if (var1 < this->field_1032->length) {
        this->field_1038 = var1;
        this->method_703();
    }
}

void class_74::method_703() {
    this->field_1034 = 0;
    this->field_1035 = 0;
    if (this->field_1032->at(this->field_1038) != nullptr) {
        for (int32_t var1 = 0; var1 < this->field_1032->at(this->field_1038)->length; var1++) {
            if (this->field_1032->at(this->field_1038)->at(var1) == nullptr) {
                this->field_1041 = var1 - 1;
                this->field_1033->at(this->field_1038) = var1;
                break;
            }
        }
    }
    this->field_1041 = this->field_1033->at(this->field_1038) - 1;
    for (int32_t var2 = 0; var2 < this->field_1033->at(this->field_1038); var2++) {
        if ((this->field_1043 + ((var2 + 1) * this->field_1044)) > ((this->field_1028 + this->field_1030) - 12)) {
            this->field_1041 = var2 - 1;
            this->field_1034 = jrt::f2i((float(((this->field_1030 - this->field_1043) + this->field_1028)) * (float(var2) / float(this->field_1033->at(this->field_1038)))));
            break;
        }
    }
    this->field_1036 = jrt::f2i((float(((this->field_1030 - this->field_1043) + this->field_1028)) * (float(this->field_1040) / float(this->field_1033->at(this->field_1038)))));
    if (this->field_1034 > 0) {
        this->field_1035 = 5;
    }
}

void class_74::method_704() {
    if ((this->field_1046 == 0) && (this->field_1039 > 0)) {
        this->field_1039--;
        if (this->field_1039 < this->field_1040) {
            this->field_1040--;
        }
    }
    this->method_703();
}

void class_74::method_705() {
    if (this->field_1046 == 0) {
        if (this->field_1039 == (this->field_1032->at(this->field_1038)->length - 1)) {
            return;
        }
        if (this->field_1032->at(this->field_1038)->at((this->field_1039 + 1)) != nullptr) {
            this->field_1039++;
            if (this->field_1039 > (this->field_1040 + this->field_1041)) {
                this->field_1040++;
            }
        }
    } else if (this->field_1032->at(this->field_1038)->at(0) != nullptr) {
        this->field_1046 = 0;
    }
    this->method_703();
}

void class_74::method_706() {
    if (this->field_1038 > 0) {
        this->field_1038--;
        this->field_1039 = 0;
        this->field_1040 = 0;
    }
    this->method_703();
}

void class_74::method_707() {
    if (this->field_1038 < (this->field_1031->length - 1)) {
        this->field_1038++;
        this->field_1039 = 0;
        this->field_1040 = 0;
    }
    this->method_703();
}

void class_74::method_708() {
    if (this->field_1037) {
        org::deep3d::GameUi::tab((this->field_1027 + 2), (this->field_1028 + 11), ((this->field_1029 / 2) - 2), 14, (this->field_1038 == 0));
        org::deep3d::GameUi::tab((this->field_1027 + (this->field_1029 / 2)), (this->field_1028 + 11), ((this->field_1029 / 2) - 2), 14, (this->field_1038 == 1));
        class_84::field_1117->setColor(class_67::field_844);
        if (this->field_1038 == 0) {
            class_84::field_1117->drawLine((this->field_1027 + 2), (this->field_1028 + 11), ((this->field_1027 + (this->field_1029 / 2)) - 2), (this->field_1028 + 11));
            class_84::field_1117->drawLine((this->field_1027 + 2), (this->field_1028 + 11), (this->field_1027 + 2), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->drawLine(((this->field_1027 + (this->field_1029 / 2)) - 2), (this->field_1028 + 11), ((this->field_1027 + (this->field_1029 / 2)) - 2), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->drawRect((this->field_1027 + (this->field_1029 / 2)), (this->field_1028 + 11), ((this->field_1029 / 2) - 1), 12);
            class_84::field_1117->drawLine(((this->field_1027 + (this->field_1029 / 2)) - 2), (((this->field_1028 + 11) + 12) + 2), ((this->field_1027 + this->field_1029) - 2), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->setColor(class_67::field_847);
            class_84::field_1117->fillRect(((this->field_1027 + (this->field_1029 / 2)) + 1), ((this->field_1028 + 11) + 1), ((this->field_1029 / 2) - 2), 11);
            class_58::method_518(this->field_1031->at(0), ((this->field_1027 + 2) + 2), ((this->field_1028 + 11) + 1), 0);
            class_58::method_518(this->field_1031->at(1), ((this->field_1027 + (this->field_1029 / 2)) + 2), ((this->field_1028 + 11) + 1), 1);
            if (class_67::method_581()) {
                class_84::field_1117->setColor(class_67::field_844);
                class_84::field_1117->fillTriangle(((this->field_1027 + (this->field_1029 / 2)) - 8), ((this->field_1028 + 11) + 11), ((this->field_1027 + (this->field_1029 / 2)) - 8), ((this->field_1028 + 11) + 4), ((this->field_1027 + (this->field_1029 / 2)) - 4), ((this->field_1028 + 11) + 7));
            }
        } else {
            class_84::field_1117->drawLine((this->field_1027 + (this->field_1029 / 2)), (this->field_1028 + 11), ((this->field_1027 + this->field_1029) - 2), (this->field_1028 + 11));
            class_84::field_1117->drawLine((this->field_1027 + (this->field_1029 / 2)), (this->field_1028 + 11), (this->field_1027 + (this->field_1029 / 2)), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->drawLine(((this->field_1027 + this->field_1029) - 2), (this->field_1028 + 11), ((this->field_1027 + this->field_1029) - 2), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->drawRect((this->field_1027 + 2), (this->field_1028 + 11), ((this->field_1029 / 2) - 4), 12);
            class_84::field_1117->drawLine((this->field_1027 + 2), (((this->field_1028 + 11) + 12) + 2), (this->field_1027 + (this->field_1029 / 2)), (((this->field_1028 + 11) + 12) + 2));
            class_84::field_1117->setColor(class_67::field_847);
            class_84::field_1117->fillRect(((this->field_1027 + 2) + 1), ((this->field_1028 + 11) + 1), ((this->field_1029 / 2) - 5), 11);
            class_58::method_518(this->field_1031->at(0), ((this->field_1027 + 2) + 2), ((this->field_1028 + 11) + 1), 1);
            class_58::method_518(this->field_1031->at(1), ((this->field_1027 + (this->field_1029 / 2)) + 2), ((this->field_1028 + 11) + 1), 0);
            if (class_67::method_581()) {
                class_84::field_1117->setColor(class_67::field_844);
                class_84::field_1117->fillTriangle(((this->field_1027 + this->field_1029) - 8), ((this->field_1028 + 11) + 3), ((this->field_1027 + this->field_1029) - 8), ((this->field_1028 + 11) + 11), ((this->field_1027 + this->field_1029) - 12), ((this->field_1028 + 11) + 7));
            }
        }
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->drawLine((this->field_1027 + 2), (((this->field_1028 + 11) + 12) + 2), (this->field_1027 + 2), ((this->field_1028 + this->field_1030) - 2));
        class_84::field_1117->drawLine(((this->field_1027 + this->field_1029) - 2), (((this->field_1028 + 11) + 12) + 2), ((this->field_1027 + this->field_1029) - 2), ((this->field_1028 + this->field_1030) - 2));
        class_84::field_1117->drawLine((this->field_1027 + 2), ((this->field_1028 + this->field_1030) - 2), ((this->field_1027 + this->field_1029) - 2), ((this->field_1028 + this->field_1030) - 2));
    }
}

void class_74::method_709() {
    if (this->field_1034 > 0) {
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->drawLine(((this->field_1027 + this->field_1029) - 5), (this->field_1043 + 2), ((this->field_1027 + this->field_1029) - 5), (((this->field_1028 + this->field_1030) - 5) - 14));
        class_84::field_1117->drawLine(((this->field_1027 + this->field_1029) - 6), (this->field_1043 + 3), ((this->field_1027 + this->field_1029) - 4), (this->field_1043 + 3));
        class_84::field_1117->drawLine(((this->field_1027 + this->field_1029) - 6), (((this->field_1028 + this->field_1030) - 6) - 14), ((this->field_1027 + this->field_1029) - 4), (((this->field_1028 + this->field_1030) - 6) - 14));
        if (class_67::method_581()) {
            class_84::field_1117->setColor(192, 192, 192);
        }
        class_84::field_1117->fillRect(((this->field_1027 + this->field_1029) - 6), ((this->field_1043 + 4) + this->field_1036), 3, ((this->field_1034 - 8) - 14));
        class_84::field_1117->setColor(class_67::field_844);
    }
}

void class_74::method_710() {
    if (this->field_1047) {
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->fillRect(this->field_1027, this->field_1028, this->field_1029, this->field_1030);
    }
}

void class_74::method_711() {
    this->field_1049 = 1 - this->field_1049;
}

void class_74::__dumpFields(jrt::Dumper& d) {
    d.f("field_1027", this->field_1027);
    d.f("field_1028", this->field_1028);
    d.f("field_1029", this->field_1029);
    d.f("field_1030", this->field_1030);
    d.f("field_1031", this->field_1031);
    d.f("field_1032", this->field_1032);
    d.f("field_1033", this->field_1033);
    d.f("field_1034", this->field_1034);
    d.f("field_1035", this->field_1035);
    d.f("field_1036", this->field_1036);
    d.f("field_1037", this->field_1037);
    d.f("field_1038", this->field_1038);
    d.f("field_1039", this->field_1039);
    d.f("field_1040", this->field_1040);
    d.f("field_1041", this->field_1041);
    d.f("field_1042", this->field_1042);
    d.f("field_1043", this->field_1043);
    d.f("field_1044", this->field_1044);
    d.f("field_1045", this->field_1045);
    d.f("field_1046", this->field_1046);
    d.f("field_1047", this->field_1047);
    d.f("field_1048", this->field_1048);
    d.f("field_1049", this->field_1049);
    d.f("field_1050", this->field_1050);
}

