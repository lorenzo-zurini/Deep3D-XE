// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_60::__clinit() {
}

void class_60::__init() {
    this->field_721 = jrt::New<class_3>();
    this->field_722 = jrt::New<class_3>();
    this->field_720 = jrt::newArray<int32_t>(15);
    this->field_718 = jrt::newArray<int32_t>(45);
    this->field_719 = jrt::newArray<int32_t>(15);
    this->field_723 = class_108::method_890(0, 128, 32, 0, 64, 32, 400, 15, int8_t(2));
    this->field_723->method_893(class_43::method_380(2));
    this->field_723->field_1367 = 2;
    this->field_718 = (jrt::cast<class_110>(this->field_723))->field_1389;
    for (int32_t var1 = 0; var1 < this->field_718->length; var1++) {
        this->field_718->at(var1) = 100000;
    }
    for (int32_t var2 = 0; var2 < this->field_720->length; var2++) {
        this->field_720->at(var2) = 250 + class_84::field_1123->nextInt(300);
    }
}

void class_60::method_546() {
    this->field_723->method_894();
    this->field_723 = jrt::Ref<class_108>(nullptr);
    this->field_718 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

void class_60::method_547(int64_t var1, jrt::Ref<class_57> var3, bool var4) {
    bool var5 = false;
    this->field_718 = (jrt::cast<class_110>(this->field_723))->field_1389;
    for (int32_t var6 = 0; var6 < this->field_718->length; var6 += 3) {
        int32_t var7 = var6 / 3;
        if ((!var5) && (this->field_719->at(var7) <= 0)) {
            int32_t var8 = class_84::field_1123->nextInt(18000) - 9000;
            int32_t var9 = (-5000) - class_84::field_1123->nextInt(10000);
            int32_t var10 = var4 ? (-((10000 + class_84::field_1123->nextInt(9000)) - 4500)) : (-((40000 + class_84::field_1123->nextInt(18000)) - 9000));
            this->field_722->method_10(var8, var9, var10);
            this->field_721 = var3->method_507(this->field_722, this->field_721);
            this->field_718->at(var6) = this->field_721->field_37;
            this->field_718->at((var6 + 1)) = this->field_721->field_38;
            this->field_718->at((var6 + 2)) = this->field_721->field_39;
            this->field_719->at(var7) = 2500;
            var5 = true;
        } else {
            this->field_719->at(var7) = int32_t((int64_t(this->field_719->at(var7)) - var1));
            this->field_718->at((var6 + 1)) = this->field_718->at((var6 + 1)) + this->field_720->at(var7);
            if (!var4) {
                this->field_722 = var3->method_481(this->field_722);
                this->field_718->at(var6) = this->field_718->at(var6) + (this->field_722->field_37 >> 3);
                this->field_718->at((var6 + 1)) = this->field_718->at((var6 + 1)) + (this->field_722->field_38 >> 3);
                this->field_718->at((var6 + 2)) = this->field_718->at((var6 + 2)) + (this->field_722->field_39 >> 3);
            }
        }
    }
    (jrt::cast<class_110>(this->field_723))->field_1389 = this->field_718;
}

void class_60::method_548() {
    int32_t deep3dWas = class_4::deep3dKind;
    if (org::deep3d::Remaster::on()) class_4::deep3dKind = 7;   // Deep3D-PC: bubbles (lit by the water they are in, not glowing)
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_723));
    class_4::deep3dKind = deep3dWas;
}

void class_60::__dumpFields(jrt::Dumper& d) {
    d.f("field_718", this->field_718);
    d.f("field_719", this->field_719);
    d.f("field_720", this->field_720);
    d.f("field_721", this->field_721);
    d.f("field_722", this->field_722);
    d.f("field_723", this->field_723);
}

