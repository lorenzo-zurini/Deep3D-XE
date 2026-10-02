// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_87> class_87::field_1145{};

void class_87::__clinit() {
    class_87::field_1145 = jrt::New<class_87>();
}

void class_87::__init(int32_t var1, jrt::Ref<java::lang::String> var2, jrt::Ref<jrt::Array<int8_t>> var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8) {
    this->field_1147 = JRT_LIT(u"");
    this->field_1153 = JRT_LIT(u"");
    this->field_1162 = false;
    this->field_1163 = false;
    this->field_1146 = var1;
    this->field_1147 = var2;
    this->field_1148 = var3;
    this->field_1149 = var4;
    this->field_1150 = var5;
    this->field_1152 = var6;
    this->field_1153 = class_38::method_354(var6)->field_1133;
    this->field_1154 = var7;
    this->field_1155 = var8;
    this->field_1156 = -1;
    this->field_1161 = false;
    this->field_1171 = true;
    this->field_1159 = 0;
}

void class_87::__init(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1147 = JRT_LIT(u"");
    this->field_1153 = JRT_LIT(u"");
    this->field_1162 = false;
    this->field_1163 = false;
    this->field_1146 = var1;
    this->field_1150 = var2;
    this->field_1152 = var3;
    this->field_1153 = class_38::method_354(var3)->field_1133;
    this->field_1155 = -1;
    this->field_1156 = -1;
    this->field_1161 = true;
    this->field_1171 = true;
}

void class_87::__init() {
    this->field_1147 = JRT_LIT(u"");
    this->field_1153 = JRT_LIT(u"");
    this->field_1162 = false;
    this->field_1163 = false;
    this->field_1146 = -1;
    this->field_1161 = false;
    this->field_1171 = false;
}

bool class_87::method_754() {
    return this->field_1146 == (-1);
}

void class_87::method_755(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1166 = var1;
    this->field_1167 = var2;
    this->field_1168 = var3;
    this->field_1169 = jrt::f2i(((float(var3) / float(var2)) * 100.0f));
}

void class_87::method_756(int32_t var1, int32_t var2) {
    this->field_1164 = var1;
    this->field_1165 = var2;
}

jrt::Ref<java::lang::String> class_87::method_757() {
    return this->field_1161 ? class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_10->at(class_21::method_143()))), this->field_1153) : class_84::field_1116->method_4(int32_t(class_1::field_12->at(this->field_1146)));
}

jrt::Ref<java::lang::String> class_87::method_758() {
    return this->field_1161 ? class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_11->at(class_21::method_143()))), this->field_1153) : class_84::field_1116->method_4(int32_t(class_1::field_13->at(this->field_1146)));
}

void class_87::method_759(int32_t var1) {
    this->field_1152 = var1;
    this->field_1153 = class_38::method_354(this->field_1152)->field_1133;
}

void class_87::method_760() {
    if (this->field_1155 > (-1)) {
        this->field_1156++;
    }
}

void class_87::method_761(int32_t var1) {
    this->field_1156 += var1;
}

bool class_87::method_762() {
    return this->field_1156 > this->field_1155;
}

void class_87::method_763() {
    jrt::Ref<class_86> var1 = class_38::method_354(this->field_1152);
    this->field_1158 = jrt::f2i(class_38::method_362(class_21::method_180(), var1));
    this->field_1160 = var1->field_1140;
    int32_t var2 = class_21::method_180()->field_1135;
    int32_t var3 = class_21::method_180()->field_1136;
    int32_t var4 = var1->field_1135;
    int32_t var5 = var1->field_1136;
    int32_t var6 = var4 - var2;
    int32_t var7 = var5 - var3;
    if (((var6 > 0) && (class_16::method_100(var6) > class_16::method_100(var7))) && (class_16::method_100((var6 - var7)) > ((class_16::method_100(var6) + class_16::method_100(var7)) / 5))) {
        this->field_1159 = 1;
    } else if (((var6 < 0) && (class_16::method_100(var6) > class_16::method_100(var7))) && (class_16::method_100((var6 - var7)) > ((class_16::method_100(var6) + class_16::method_100(var7)) / 5))) {
        this->field_1159 = 3;
    } else if (((var7 > 0) && (class_16::method_100(var7) > class_16::method_100(var6))) && (class_16::method_100((var6 - var7)) > ((class_16::method_100(var6) + class_16::method_100(var7)) / 5))) {
        this->field_1159 = 2;
    } else if (((var7 < 0) && (class_16::method_100(var7) > class_16::method_100(var6))) && (class_16::method_100((var6 - var7)) > ((class_16::method_100(var6) + class_16::method_100(var7)) / 5))) {
        this->field_1159 = 4;
    } else if ((var6 > 0) && (var7 > 0)) {
        this->field_1159 = 5;
    } else if ((var6 > 0) && (var7 < 0)) {
        this->field_1159 = 8;
    } else if ((var6 < 0) && (var7 > 0)) {
        this->field_1159 = 6;
    } else {
        if ((var6 < 0) && (var7 < 0)) {
            this->field_1159 = 7;
        }
    }
}

int32_t class_87::method_764() {
    return jrt::div(this->field_1154, class_16::method_98(20, class_16::method_97(1, (class_21::method_210() / 2))));
}

void class_87::__dumpFields(jrt::Dumper& d) {
    d.f("field_1146", this->field_1146);
    d.f("field_1147", this->field_1147);
    d.f("field_1148", this->field_1148);
    d.f("field_1149", this->field_1149);
    d.f("field_1150", this->field_1150);
    d.f("field_1151", this->field_1151);
    d.f("field_1152", this->field_1152);
    d.f("field_1153", this->field_1153);
    d.f("field_1154", this->field_1154);
    d.f("field_1155", this->field_1155);
    d.f("field_1156", this->field_1156);
    d.f("field_1157", this->field_1157);
    d.f("field_1158", this->field_1158);
    d.f("field_1159", this->field_1159);
    d.f("field_1160", this->field_1160);
    d.f("field_1161", this->field_1161);
    d.f("field_1162", this->field_1162);
    d.f("field_1163", this->field_1163);
    d.f("field_1164", this->field_1164);
    d.f("field_1165", this->field_1165);
    d.f("field_1166", this->field_1166);
    d.f("field_1167", this->field_1167);
    d.f("field_1168", this->field_1168);
    d.f("field_1169", this->field_1169);
    d.f("field_1170", this->field_1170);
    d.f("field_1171", this->field_1171);
}

