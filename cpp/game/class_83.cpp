// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_83::__clinit() {
}

void class_83::__init() {
    this->field_1072 = 120;
    this->field_1077 = jrt::New<class_3>();
    this->field_1078 = false;
    this->field_1076 = class_108::method_892(0, 12, int8_t(2));
    this->field_1076->method_893(class_43::method_380(2));
    this->field_1076->field_1367 = 2;
    this->field_1074 = jrt::newArray<int32_t>(144);
    this->field_1073 = jrt::newArray<int32_t>(144);
    int32_t var1 = 19;
    int32_t var2 = 20;
    this->field_1075 = jrt::newArray<int32_t>(96);
    for (int32_t var3 = 8; var3 < this->field_1075->length; var3 += 8) {
        this->field_1075->at(var3) = 83;
        this->field_1075->at((var3 + 1)) = var1;
        this->field_1075->at((var3 + 2)) = 84;
        this->field_1075->at((var3 + 3)) = var1;
        this->field_1075->at((var3 + 4)) = 84;
        this->field_1075->at((var3 + 5)) = var2;
        this->field_1075->at((var3 + 6)) = 83;
        this->field_1075->at((var3 + 7)) = var2;
        var1++;
        var2++;
    }
}

void class_83::method_731() {
    this->field_1076->method_894();
    this->field_1076 = jrt::Ref<class_108>(nullptr);
}

void class_83::method_732(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6) {
    this->field_1074->at(0) = var1 - this->field_1072;
    this->field_1074->at(1) = var2;
    this->field_1074->at(2) = var3;
    this->field_1074->at(3) = var1 + this->field_1072;
    this->field_1074->at(4) = var2;
    this->field_1074->at(5) = var3;
    this->field_1074->at(6) = var4 + this->field_1072;
    this->field_1074->at(7) = var5;
    this->field_1074->at(8) = var6;
    this->field_1074->at(9) = var4 - this->field_1072;
    this->field_1074->at(10) = var5;
    this->field_1074->at(11) = var6;
    for (int32_t var7 = this->field_1074->length - 1; var7 >= 23; var7 -= 12) {
        this->field_1074->at(var7) = this->field_1074->at((var7 - 12));
        this->field_1074->at((var7 - 1)) = this->field_1074->at((var7 - 13));
        this->field_1074->at((var7 - 2)) = this->field_1074->at((var7 - 14));
        this->field_1074->at((var7 - 3)) = this->field_1074->at((var7 - 15));
        this->field_1074->at((var7 - 4)) = this->field_1074->at((var7 - 16));
        this->field_1074->at((var7 - 5)) = this->field_1074->at((var7 - 17));
        this->field_1074->at((var7 - 6)) = this->field_1074->at((var7 - 18));
        this->field_1074->at((var7 - 7)) = this->field_1074->at((var7 - 19));
        this->field_1074->at((var7 - 8)) = this->field_1074->at((var7 - 20));
        this->field_1074->at((var7 - 9)) = this->field_1074->at((var7 - 21));
        this->field_1074->at((var7 - 10)) = this->field_1074->at((var7 - 22));
        this->field_1074->at((var7 - 11)) = this->field_1074->at((var7 - 23));
    }
    for (int32_t var8 = 0; var8 < this->field_1074->length; var8 += 3) {
        this->field_1073->at(var8) = this->field_1074->at(var8) - var1;
        this->field_1073->at((var8 + 1)) = this->field_1074->at((var8 + 1)) - var2;
        this->field_1073->at((var8 + 2)) = this->field_1074->at((var8 + 2)) - var3;
    }
    this->field_1076->method_845(var1, var2, var3);
    (jrt::cast<class_109>(this->field_1076))->method_896(this->field_1073, this->field_1075);
}

void class_83::method_733(jrt::Ref<class_3> var1) {
    if (this->field_1078) {
        this->field_1077->method_9(var1);
        this->field_1078 = false;
    }
    this->method_732(var1->field_37, var1->field_38, var1->field_39, this->field_1077->field_37, this->field_1077->field_38, this->field_1077->field_39);
    this->field_1077->method_9(var1);
}

void class_83::method_734(jrt::Ref<class_3> var1) {
    for (int32_t var2 = 0; var2 < this->field_1074->length; var2 += 3) {
        this->field_1074->at(var2) = var1->field_37;
        this->field_1074->at((var2 + 1)) = var1->field_38;
        this->field_1074->at((var2 + 2)) = var1->field_39;
    }
    this->field_1077->method_9(var1);
    this->field_1078 = true;
}

void class_83::method_735() {
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1076));
}

void class_83::__dumpFields(jrt::Dumper& d) {
    d.f("field_1072", this->field_1072);
    d.f("field_1073", this->field_1073);
    d.f("field_1074", this->field_1074);
    d.f("field_1075", this->field_1075);
    d.f("field_1076", this->field_1076);
    d.f("field_1077", this->field_1077);
    d.f("field_1078", this->field_1078);
}

