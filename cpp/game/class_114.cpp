// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> class_114::field_1425{};

void class_114::__clinit() {
    class_114::field_1425 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({34, 104, 34, 104}), jrt::arrayOf<int32_t>({29, 101, 29, 101}), jrt::arrayOf<int32_t>({2, 104, 2, 104})});
}

void class_114::__init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, jrt::Ref<class_108> var3, int32_t var4, int32_t var5, int32_t var6) {
    class_112::__init(var1, jrt::Ref<class_108>(nullptr), 10000);
    this->field_1426 = 40;
    this->field_1433 = false;
    var1->field_93 = false;
    if (var4 > 0) {
        var1->method_41(var4, jrt::Ref<class_114>(this));
    }
    this->class_112::field_1411 = var2;
    this->field_1423 = var3;
    this->field_1424 = jrt::Ref<class_108>(nullptr);
    this->field_1422 = jrt::New<class_3>();
    this->field_1431 = var6;
    this->field_1427 = class_108::method_892(0, 2, int8_t(2));
    this->field_1427->method_893(class_43::method_380(2));
    (jrt::cast<class_109>(this->field_1427))->field_1383 = -16711936;
    this->field_1427->field_1367 = 2;
    this->field_1429 = jrt::newArray<int32_t>(24);
    this->field_1428 = jrt::newArray<int32_t>(24);
    this->field_1430 = jrt::newArray<int32_t>(16);
    for (int32_t var7 = 0; var7 < this->field_1430->length; var7 += 8) {
        this->field_1430->at(var7) = class_114::field_1425->at(var5)->at(0);
        this->field_1430->at((var7 + 1)) = class_114::field_1425->at(var5)->at(1);
        this->field_1430->at((var7 + 2)) = class_114::field_1425->at(var5)->at(2);
        this->field_1430->at((var7 + 3)) = class_114::field_1425->at(var5)->at(1);
        this->field_1430->at((var7 + 4)) = class_114::field_1425->at(var5)->at(2);
        this->field_1430->at((var7 + 5)) = class_114::field_1425->at(var5)->at(3);
        this->field_1430->at((var7 + 6)) = class_114::field_1425->at(var5)->at(0);
        this->field_1430->at((var7 + 7)) = class_114::field_1425->at(var5)->at(3);
    }
}

void class_114::method_894() {
    class_112::method_894();
    this->field_1427->method_894();
    this->field_1427 = jrt::Ref<class_108>(nullptr);
}

void class_114::method_887() {
    this->class_112::field_1409->method_50();
    // Deep3D-PC: not while parked at x 50000 (unfired) in Enhanced and Remastered: the phone's
    // far plane hid it there, theirs reach it. Original queues it, as the phone: each queued
    // object moves the chase camera on a step (class_42), so this is game state, as recorded.
    // But it is never drawn (-1): the phone showed it as a green glow wherever its far plane
    // reached x 50000 (in the intro, out of the first station)
    bool deep3dParked = this->class_112::field_1409->field_78->at(0)->field_37 == 50000;
    if ((this->class_112::field_1411 != nullptr) && (!org::deep3d::Demo::enhancedWorld() || !deep3dParked)) {
        int32_t deep3dWas = class_4::deep3dKind;
        if (deep3dParked) class_4::deep3dKind = -1;
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_112::field_1411));
        class_4::deep3dKind = deep3dWas;
    }
    if (this->class_112::field_1409->field_92) {
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1427));
    }
}

void class_114::method_905() {
    if ((this->class_112::field_1409->field_96 != nullptr) && this->class_112::field_1409->field_96->field_1238) {
        (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_831();
    }
    this->class_112::field_1409->field_96->field_1237 = false;
    this->class_112::field_1409->field_96 = jrt::Ref<class_91>(nullptr);
    this->field_1424 = jrt::Ref<class_108>(nullptr);
    this->field_1433 = false;
    class_69::method_634(0, 0, JRT_LIT(u""));
    class_21::method_173();
    this->class_112::field_1409->field_88 = false;
}

void class_114::method_895(int64_t var1) {
    if (this->field_1433 && this->class_112::field_1409->field_88) {
        this->method_905();
    }
    this->class_112::field_1409->method_49(var1);
    if (this->class_112::field_1409->field_96 != nullptr) {
        if (this->field_1424 == nullptr) {
            this->field_1422 = this->class_112::field_1409->field_96->field_1226->method_848(this->field_1422);
            this->field_1422->method_17(this->class_112::field_1409->field_76->field_272->method_664());
            int32_t var3 = class_16::method_98(40000, this->field_1422->method_23());
            float var4 = 1.0f - (float(var3) / 40000.0f);
            int32_t var5 = class_84::field_1122->field_1182;
            class_84::field_1122->method_769(14, jrt::f2i((float(var5) * var4)));
            this->field_1424 = this->class_112::field_1409->field_96->field_1226;
            this->field_1432 = this->class_112::field_1409->field_96->field_1225->field_363;
            this->field_1433 = true;
            if (this->class_112::field_1409->field_96->field_1238 && (!this->class_112::field_1409->field_96->method_800())) {
                (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_830(this->field_1431);
                if (class_84::field_1110->field_40->method_883(class_112::field_1412)) {
                    class_69::method_634((class_112::field_1412->field_37 + 10), (class_112::field_1412->field_38 - 10), jrt::concat(JRT_LIT(u""), (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_832()));
                }
            }
            this->class_112::field_1409->field_88 = false;
        }
        if ((this->class_112::field_1409->field_96->field_1225->field_363 >= this->field_1432) && (((!this->class_112::field_1409->field_96->field_1238) || class_84::field_1110->field_40->method_883(this->field_1424->method_848(this->field_1422))) || (jrt::cast<class_101>(this->class_112::field_1409->field_96))->field_1326)) {
            if (((this->class_112::field_1409->field_96->field_1239 && (this->class_112::field_1409->field_96->method_800() || this->class_112::field_1409->field_96->method_801())) || (this->class_112::field_1409->field_96->field_1227 == 13)) || (this->class_112::field_1409->field_96->field_1238 && (jrt::cast<class_101>(this->class_112::field_1409->field_96))->field_1326)) {
                this->class_112::field_1409->field_78->at(0)->method_9(this->field_1424->method_848(this->field_1422));
                this->field_1422 = this->class_112::field_1409->field_76->field_272->field_970->method_848(this->field_1422);
                this->field_1422->method_17(this->class_112::field_1409->field_78->at(0));
                this->class_112::field_1409->field_96->field_1237 = true;
                if (this->class_112::field_1409->field_96->field_1238) {
                    (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_834(class_16::method_97(0, class_16::method_98(4096, (this->field_1422->method_23() << 1))));
                }
                if (this->field_1422->method_23() <= 400) {
                    if (this->class_112::field_1409->field_96->field_1227 == 13) {
                        (jrt::cast<class_93>(this->class_112::field_1409->field_96))->method_811();
                        return;
                    }
                    if (this->class_112::field_1409->field_96->field_1238) {
                        if (!(jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_833()) {
                            this->field_1424 = jrt::Ref<class_108>(nullptr);
                            this->field_1433 = false;
                            this->class_112::field_1409->field_92 = false;
                            (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_831();
                            this->class_112::field_1409->field_96 = jrt::Ref<class_91>(nullptr);
                            return;
                        }
                    } else {
                        (jrt::cast<class_96>(this->class_112::field_1409->field_96))->method_817();
                        this->field_1433 = false;
                        this->field_1424 = jrt::Ref<class_108>(nullptr);
                    }
                    return;
                }
                this->field_1422->method_22();
                this->field_1422->method_18((org::deep3d::Step::exact() ? (int32_t(var1) * 10) : org::deep3d::Step::share(330.0, this->deep3dPull)));   // Deep3D-PC
                this->field_1424->method_844(this->field_1422);
            } else if (this->class_112::field_1409->field_96->field_1238) {
                this->class_112::field_1409->field_78->at(0)->method_9(this->field_1424->method_848(this->field_1422));
                class_112::field_1412 = this->field_1424->method_848(class_112::field_1412);
                if ((!this->class_112::field_1409->field_96->method_800()) && class_84::field_1110->field_40->method_883(class_112::field_1412)) {
                    class_69::method_634((class_112::field_1412->field_37 + 10), (class_112::field_1412->field_38 - 10), jrt::concat(JRT_LIT(u""), (jrt::cast<class_101>(this->class_112::field_1409->field_96))->method_832()));
                }
            }
        } else {
            this->method_905();
        }
    }
    this->method_907();
}

jrt::Ref<class_3> class_114::method_906(jrt::Ref<class_3> var1) {
    var1->method_9(this->field_1423->method_848(this->field_1422));
    return var1;
}

void class_114::method_907() {
    this->field_1422->method_9(this->class_112::field_1409->field_78->at(0));
    if (this->class_112::field_1411 != nullptr) {
        this->class_112::field_1411->method_846(this->field_1422);
    }
    if (this->class_112::field_1409->field_92) {
        if (this->field_1422->field_39 == 50000) {
            this->class_112::field_1409->field_92 = false;
            this->field_1424 = jrt::Ref<class_108>(nullptr);
            this->field_1433 = false;
            return;
        }
        this->field_1429->at(0) = this->field_1422->field_37 - this->field_1426;
        this->field_1429->at(1) = this->field_1422->field_38;
        this->field_1429->at(2) = this->field_1422->field_39;
        this->field_1429->at(3) = this->field_1422->field_37 + this->field_1426;
        this->field_1429->at(4) = this->field_1422->field_38;
        this->field_1429->at(5) = this->field_1422->field_39;
        this->field_1429->at(12) = this->field_1422->field_37;
        this->field_1429->at(13) = this->field_1422->field_38 - this->field_1426;
        this->field_1429->at(14) = this->field_1422->field_39;
        this->field_1429->at(15) = this->field_1422->field_37;
        this->field_1429->at(16) = this->field_1422->field_38 + this->field_1426;
        this->field_1429->at(17) = this->field_1422->field_39;
        this->field_1422 = this->method_906(this->field_1422);
        this->field_1429->at(6) = this->field_1422->field_37 + this->field_1426;
        this->field_1429->at(7) = this->field_1422->field_38;
        this->field_1429->at(8) = this->field_1422->field_39;
        this->field_1429->at(9) = this->field_1422->field_37 - this->field_1426;
        this->field_1429->at(10) = this->field_1422->field_38;
        this->field_1429->at(11) = this->field_1422->field_39;
        this->field_1429->at(18) = this->field_1422->field_37;
        this->field_1429->at(19) = this->field_1422->field_38 + this->field_1426;
        this->field_1429->at(20) = this->field_1422->field_39;
        this->field_1429->at(21) = this->field_1422->field_37;
        this->field_1429->at(22) = this->field_1422->field_38 - this->field_1426;
        this->field_1429->at(23) = this->field_1422->field_39;
        for (int32_t var1 = 0; var1 < this->field_1429->length; var1 += 3) {
            this->field_1428->at(var1) = this->field_1429->at(var1) - this->field_1422->field_37;
            this->field_1428->at((var1 + 1)) = this->field_1429->at((var1 + 1)) - this->field_1422->field_38;
            this->field_1428->at((var1 + 2)) = this->field_1429->at((var1 + 2)) - this->field_1422->field_39;
        }
        this->field_1427->method_845(this->field_1422->field_37, this->field_1422->field_38, this->field_1422->field_39);
        (jrt::cast<class_109>(this->field_1427))->method_896(this->field_1428, this->field_1430);
    }
}

void class_114::__dumpFields(jrt::Dumper& d) {
    class_112::__dumpFields(d);
    d.f("field_1422", this->field_1422);
    d.f("field_1423", this->field_1423);
    d.f("field_1424", this->field_1424);
    d.f("field_1426", this->field_1426);
    d.f("field_1427", this->field_1427);
    d.f("field_1428", this->field_1428);
    d.f("field_1429", this->field_1429);
    d.f("field_1430", this->field_1430);
    d.f("field_1431", this->field_1431);
    d.f("field_1432", this->field_1432);
    d.f("field_1433", this->field_1433);
}

