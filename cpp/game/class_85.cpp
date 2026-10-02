// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_85::__clinit() {
}

void class_85::__init(int32_t var1, int32_t var2) {
    if (var1 > 1) {
        this->field_1131 = jrt::newArray<jrt::Ref<class_116>>(var1);
        this->field_1128 = jrt::newArray<int32_t>(var1);
        bool var3 = false;
        bool var4 = false;
        for (int32_t var5 = 0; var5 < this->field_1131->length; var5++) {
            this->field_1131->at(var5) = jrt::New<class_116>(class_43::method_380(2), 96, 0, 127, 32, 10, 1000, 200, 3000);
            if (var5 == 0) {
                this->field_1128->at(var5) = 0;
            } else {
                this->field_1128->at(var5) = (this->field_1128->at((var5 - 1)) + class_84::field_1123->nextInt(1000)) + 1000;
            }
        }
    }
    if (var2 == 2) {
        this->field_1132 = class_43::method_381(9995);
        this->field_1132->method_873(60);
        this->field_1132->method_869(2048, 2048, 2048);
    } else {
        this->field_1132 = class_43::method_381(9992);
        this->field_1132->method_873(100);
    }
    this->field_1132->field_1367 = 2;
    this->field_1132->method_878();
}

void class_85::method_738() {
    this->field_1128 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_1129 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    if (this->field_1131 != nullptr) {
        for (int32_t var1 = 0; var1 < this->field_1131->length; var1++) {
            if (this->field_1131->at(var1) != nullptr) {
                this->field_1131->at(var1)->method_894();
            }
        }
    }
    this->field_1131 = jrt::Ref<jrt::Array<jrt::Ref<class_116>>>(nullptr);
}

void class_85::method_739(jrt::Ref<jrt::Array<int32_t>> var1) {
    if (this->field_1131 != nullptr) {
        if (var1->length != (3 * this->field_1131->length)) {
            java::lang::System::out->println(JRT_LIT(u"Explosion offset size must be 3 * explosion count"));
            class_84::field_1126->method_440();
        }
        this->field_1129 = var1;
    }
}

int32_t class_85::method_740() {
    return (this->field_1131 != nullptr) ? this->field_1131->length : 1;
}

void class_85::method_741(int32_t var1, int32_t var2, int32_t var3) {
    if (this->field_1131 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_1131->length; var4++) {
            if (this->field_1129 != nullptr) {
                this->field_1131->at(var4)->method_845((var1 + this->field_1129->at((3 * var4))), (var2 + this->field_1129->at(((3 * var4) + 1))), (var3 + this->field_1129->at(((3 * var4) + 2))));
            } else {
                this->field_1131->at(var4)->method_845(var1, var2, var3);
            }
        }
        this->field_1132->method_845(var1, var2, var3);
    } else {
        this->field_1132->method_845(var1, var2, var3);
        this->field_1132->method_877(int8_t(1));
    }
}

void class_85::method_742(int64_t var1) {
    this->field_1130 = int32_t((int64_t(this->field_1130) + var1));
    if (this->field_1131 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_1131->length; var3++) {
            if (this->field_1131->at(var3)->field_1436) {
                if (this->field_1130 > this->field_1128->at(var3)) {
                    if (var3 == (this->field_1131->length - 1)) {
                        this->field_1132->method_869(16384, 16384, 16384);
                        this->field_1132->method_877(int8_t(1));
                    }
                    this->field_1131->at(var3)->method_910();
                }
            } else {
                if (var3 == (this->field_1131->length - 1)) {
                    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1132));
                }
                this->field_1131->at(var3)->method_895(var1);
                this->field_1131->at(var3)->method_887();
            }
        }
    } else {
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1132));
    }
}

bool class_85::method_743() {
    return (this->field_1131 != nullptr) ? (this->field_1130 > (this->field_1128->at((this->field_1128->length - 1)) + 1000)) : (this->field_1130 > 4000);
}

void class_85::__dumpFields(jrt::Dumper& d) {
    d.f("field_1128", this->field_1128);
    d.f("field_1129", this->field_1129);
    d.f("field_1130", this->field_1130);
    d.f("field_1131", this->field_1131);
    d.f("field_1132", this->field_1132);
}

