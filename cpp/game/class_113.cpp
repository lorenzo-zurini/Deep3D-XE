// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_113::field_1415{};
jrt::Ref<class_3> class_113::field_1416{};
jrt::Ref<class_3> class_113::field_1417{};
int32_t class_113::field_1418{};
int32_t class_113::field_1419{};
int32_t class_113::field_1420{};

void class_113::__clinit() {
    class_113::field_1417 = jrt::New<class_3>();
}

void class_113::__init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, int32_t var3, bool var4) {
    class_112::__init(var1, jrt::Ref<class_108>(nullptr), 1000);
    jrt::New<class_57>();
    this->field_1413 = jrt::New<class_25>();
    this->field_1414 = jrt::New<class_83>();
    this->class_112::field_1411 = var2;
    this->class_112::field_1411->method_869(8192, 8192, 8192);
    this->field_1421 = var4;
    class_113::field_1415 = jrt::New<class_3>();
}

void class_113::method_894() {
    class_112::method_894();
    if (this->field_1413 != nullptr) {
        this->field_1413->method_235();
    }
    this->field_1413 = jrt::Ref<class_25>(nullptr);
    if (this->field_1414 != nullptr) {
        this->field_1414->method_731();
    }
    this->field_1414 = jrt::Ref<class_83>(nullptr);
}

void class_113::method_887() {
    this->class_112::field_1409->method_50();
    if (this->class_112::field_1409->field_92) {
        this->field_1414->method_735();
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_112::field_1411));
    }
    this->field_1413->method_238();
}

void class_113::method_895(int64_t var1) {
    this->class_112::field_1409->method_49(var1);
    class_113::field_1415->method_9(this->class_112::field_1409->field_78->at(0));
    if (this->class_112::field_1409->field_88) {
        this->field_1414->method_734(class_113::field_1415);
        this->class_112::field_1409->field_88 = false;
    }
    this->class_112::field_1411->method_846(class_113::field_1415);
    class_112::field_1412->method_9(this->class_112::field_1409->field_79->at(0));
    class_112::field_1412->method_22();
    this->class_112::field_1411->field_1341->method_512(class_112::field_1412);
    if (this->class_112::field_1409->field_92) {
        if (this->field_1421 && (this->class_112::field_1409->field_83->at(0) < (this->class_112::field_1409->field_86 - 1500))) {
            this->method_904(var1);
        }
        class_113::field_1415->method_9(this->class_112::field_1409->field_78->at(0));
        // Deep3D-PC: the trail runs at a quarter of the time: 0 under 4 ms, so a share of a step's;
        // the ribbon moves on once a step (11 links: as long at any frame rate), its head always
        this->field_1413->method_236(class_113::field_1415, (org::deep3d::Step::exact() ? (int32_t(var1) / 4) : org::deep3d::Step::share(8.0, this->deep3dFeed)));
        if (org::deep3d::Step::steps(this->deep3dRibbon) > 0) {
            this->field_1414->method_733(class_113::field_1415);
        } else {
            this->field_1414->deep3dHead(class_113::field_1415);
        }
        if (class_113::field_1415->field_39 == 50000) {
            this->class_112::field_1409->field_92 = false;
        }
    }
}

void class_113::method_904(int64_t var1) {
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var3 = this->class_112::field_1409->field_77;
    if (this->class_112::field_1409->field_77 != nullptr) {
        int32_t var4 = -1;
        int32_t var5 = 2147483647;
        for (int32_t var6 = 0; var6 < var3->length; var6++) {
            if ((var3->at(var6)->field_375 && (!var3->at(var6)->method_345())) && (!var3->at(var6)->method_321())) {
                class_113::field_1416 = this->class_112::field_1409->field_78->at(0);
                class_113::field_1415 = var3->at(var6)->method_344(class_113::field_1415);
                class_113::field_1418 = class_113::field_1416->field_37 - class_113::field_1415->field_37;
                class_113::field_1419 = class_113::field_1416->field_38 - class_113::field_1415->field_38;
                class_113::field_1420 = class_113::field_1416->field_39 - class_113::field_1415->field_39;
                int32_t var7{};
                if (((((((class_113::field_1418 < 15000) && (class_113::field_1418 > (-15000))) && (class_113::field_1419 < 15000)) && (class_113::field_1419 > (-15000))) && (class_113::field_1420 < 15000)) && (class_113::field_1420 > (-15000))) && ((var7 = ((class_113::field_1418 * class_113::field_1418) + (class_113::field_1419 * class_113::field_1419)) + (class_113::field_1420 * class_113::field_1420)) < var5)) {
                    var4 = var6;
                    var5 = var7;
                }
            }
        }
        if (var4 < 0) {
            return;
        }
        class_113::field_1415 = var3->at(var4)->method_344(class_113::field_1415);
        if (!org::deep3d::Step::exact()) {
            this->deep3dHome();
            return;
        }
        class_112::field_1412->field_37 = class_113::field_1415->field_37 - this->class_112::field_1409->field_78->at(0)->field_37;
        class_112::field_1412->field_38 = class_113::field_1415->field_38 - this->class_112::field_1409->field_78->at(0)->field_38;
        class_112::field_1412->field_39 = class_113::field_1415->field_39 - this->class_112::field_1409->field_78->at(0)->field_39;
        class_113::field_1417->method_9(this->class_112::field_1409->field_79->at(0));
        class_112::field_1412->method_17(class_113::field_1417);
        class_112::field_1412->method_18(int32_t(var1));
        this->class_112::field_1409->field_79->at(0) = class_113::field_1417->method_14(class_112::field_1412, this->class_112::field_1409->field_79->at(0));
        this->class_112::field_1409->field_79->at(0)->method_22();
        this->class_112::field_1409->field_79->at(0)->method_18((jrt::f2i((this->class_112::field_1409->field_85 * float(var1))) << 12));
        this->class_112::field_1409->field_79->at(0)->field_37 >>= 12;
        this->class_112::field_1409->field_79->at(0)->field_38 >>= 12;
        this->class_112::field_1409->field_79->at(0)->field_39 >>= 12;
    }
}

/* Deep3D-PC: homing bends the velocity toward the target by dt / 4096 of the
   way, and the velocity's length was the frame's: per frame the same angle at
   any dt, so at 300 FPS ten times the turn. Here the velocity is the step's,
   as it is at 33 ms, and each frame bends it by its share. In doubles: a
   frame's bend is a fraction of a unit. */
void class_113::deep3dHome() {
    jrt::Ref<class_9> s = this->class_112::field_1409;
    double* v = s->deep3dVel.data();
    double k = 33.0 * org::deep3d::Step::scale() / 4096.0;
    v[0] += (double(class_113::field_1415->field_37 - s->field_78->at(0)->field_37) - v[0]) * k;
    v[1] += (double(class_113::field_1415->field_38 - s->field_78->at(0)->field_38) - v[1]) * k;
    v[2] += (double(class_113::field_1415->field_39 - s->field_78->at(0)->field_39) - v[2]) * k;
    double len = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (len > 0.0) {
        double speed = double(jrt::f2i((s->field_85 * float(33)))) / len;
        v[0] *= speed, v[1] *= speed, v[2] *= speed;
    }
    s->field_79->at(0)->method_10(int32_t(std::lround(v[0])), int32_t(std::lround(v[1])), int32_t(std::lround(v[2])));
}

void class_113::__dumpFields(jrt::Dumper& d) {
    class_112::__dumpFields(d);
    d.f("field_1413", this->field_1413);
    d.f("field_1414", this->field_1414);
    d.f("field_1421", this->field_1421);
}

