// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_86::__clinit() {
}

void class_86::__init(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6) {
    this->field_1133 = var1;
    this->field_1134 = var2;
    this->field_1139 = var3;
    this->field_1135 = var4;
    this->field_1136 = var5;
    this->field_1137 = var6;
    this->field_1138 = false;
    this->field_1141 = jrt::Ref<jrt::Array<jrt::Ref<class_19>>>(nullptr);
    this->field_1143 = jrt::Ref<jrt::Array<jrt::Ref<class_68>>>(nullptr);
    this->field_1144 = jrt::Ref<jrt::Array<jrt::Ref<class_87>>>(nullptr);
    this->field_1140 = class_38::method_358(var6);
}

void class_86::__init() {
    this->__init(JRT_LIT(u""), 0, 0, 0, 0, 0);
}

float class_86::method_744() {
    return 1.0f - (float(class_16::method_97(0, (this->field_1140 - 15000))) / 15000.0f);
}

bool class_86::method_745() {
    return class_38::method_356()->at(this->field_1134);
}

void class_86::method_746() {
    if (!this->method_745()) {
        this->field_1138 = true;
        class_21::method_176();
        class_38::method_357(this->field_1134);
    }
}

bool class_86::method_747(int32_t var1) {
    if (this->field_1141 == nullptr) {
        return false;
    } else {
        for (int32_t var2 = 0; var2 < this->field_1141->length; var2++) {
            if ((this->field_1141->at(var2) != nullptr) && (this->field_1141->at(var2)->field_166 == var1)) {
                return true;
            }
        }
        return false;
    }
}

void class_86::method_748(jrt::Ref<class_19> var1) {
    bool var2 = false;
    if (this->field_1141 == nullptr) {
        this->field_1141 = jrt::arrayOf<jrt::Ref<class_19>>({var1});
    } else {
        bool var3 = false;
        jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var4 = jrt::newArray<jrt::Ref<class_19>>((this->field_1141->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1141), 0, jrt::Ref<java::lang::Object>(var4), 0, this->field_1141->length);
        var4->at((var4->length - 1)) = var1;
        this->field_1141 = var4;
    }
}

void class_86::method_749(jrt::Ref<class_120> var1) {
    int32_t var2 = -1;
    if (this->field_1142 == nullptr) {
        this->field_1142 = jrt::arrayOf<jrt::Ref<class_120>>({var1});
    } else {
        for (int32_t var3 = 0; var3 < this->field_1142->length; var3++) {
            if (this->field_1142->at(var3)->method_938(var1)) {
                var2 = var3;
                break;
            }
        }
        if (var2 < 0) {
            jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var4 = jrt::newArray<jrt::Ref<class_120>>((this->field_1142->length + 1));
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1142), 0, jrt::Ref<java::lang::Object>(var4), 0, this->field_1142->length);
            var4->at((var4->length - 1)) = var1;
            this->field_1142 = var4;
        }
    }
}

void class_86::method_750(jrt::Ref<class_19> var1) {
    int32_t var2 = -1;
    for (int32_t var3 = 0; var3 < this->field_1141->length; var3++) {
        if (this->field_1141->at(var3)->method_122(var1)) {
            this->field_1141->at(var3) = jrt::Ref<class_19>(nullptr);
            var2 = var3;
            break;
        }
    }
    if (var2 != (-1)) {
        if (this->field_1141->length == 1) {
            this->field_1141 = jrt::Ref<jrt::Array<jrt::Ref<class_19>>>(nullptr);
        } else {
            jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var4 = jrt::newArray<jrt::Ref<class_19>>((this->field_1141->length - 1));
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1141), 0, jrt::Ref<java::lang::Object>(var4), 0, var2);
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1141), (var2 + 1), jrt::Ref<java::lang::Object>(var4), var2, ((this->field_1141->length - var2) - 1));
            this->field_1141 = var4;
        }
    }
}

void class_86::method_751(jrt::Ref<class_87> var1) {
    if (this->field_1144 != nullptr) {
        bool var2 = false;
        for (int32_t var3 = 0; var3 < this->field_1144->length; var3++) {
            if (this->field_1144->at(var3) == var1) {
                this->field_1144->at(var3) = jrt::Ref<class_87>(nullptr);
                var2 = true;
                break;
            }
        }
        if (!var2) {
            java::lang::System::out->println(JRT_LIT(u"Station.removeMission() failed, mission not in list"));
        } else {
            jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var6 = jrt::newArray<jrt::Ref<class_87>>((this->field_1144->length - 1));
            int32_t var4 = 0;
            for (int32_t var5 = 0; var5 < this->field_1144->length; var5++) {
                if (this->field_1144->at(var5) != nullptr) {
                    var6->at((var4++)) = this->field_1144->at(var5);
                }
            }
            this->field_1144 = var6;
        }
    }
}

bool class_86::method_752() {
    return !class_21::method_175()->at(this->field_1134);
}

jrt::Ref<java::lang::String> class_86::toString() {
    return jrt::concat(this->field_1133, JRT_LIT(u"\n  tecLevel: \t\t"), this->field_1139, JRT_LIT(u"\n  posX: \t\t"), this->field_1135, JRT_LIT(u"\n  posY: \t\t"), this->field_1136, JRT_LIT(u"\n  discovered: \t\t"), this->field_1138, JRT_LIT(u"\n  equipment: \t\t"), this->field_1141, JRT_LIT(u"\n  ships: \t\t"), this->field_1143, JRT_LIT(u"\n  missions: \t\t"), this->field_1144, JRT_LIT(u"\n\n"));
}

bool class_86::method_753(jrt::Ref<class_86> var1) {
    return this->field_1133->equals(jrt::Ref<java::lang::Object>(var1->field_1133));
}

void class_86::__dumpFields(jrt::Dumper& d) {
    d.f("field_1133", this->field_1133);
    d.f("field_1134", this->field_1134);
    d.f("field_1135", this->field_1135);
    d.f("field_1136", this->field_1136);
    d.f("field_1137", this->field_1137);
    d.f("field_1138", this->field_1138);
    d.f("field_1139", this->field_1139);
    d.f("field_1140", this->field_1140);
    d.f("field_1141", this->field_1141);
    d.f("field_1142", this->field_1142);
    d.f("field_1143", this->field_1143);
    d.f("field_1144", this->field_1144);
}

