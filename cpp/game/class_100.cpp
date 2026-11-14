// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_100::__clinit() {
    jrt::Ref<jrt::Array<int16_t>> var10000 = jrt::arrayOf<int16_t>({int16_t(3301), int16_t(3302), int16_t(3304), int16_t(3305), int16_t(3306), int16_t(3309), int16_t(3310)});
}

void class_100::__init(jrt::Ref<class_86> var1) {
    class_99::__init((-1), jrt::Ref<class_108>(nullptr), 0, 0, 0);
    this->class_91::field_1225->method_322(15000);
    class_7::method_36();
    jrt::Ref<class_7> var2 = jrt::New<class_7>(var1);
    this->field_1307 = jrt::newArray<jrt::Ref<class_108>>(var2->method_37());
    this->field_1307 = var2->method_40(this->field_1307);
    this->field_1310 = 0;
    this->class_99::field_1303 = jrt::newArray<jrt::Ref<class_29>>(this->field_1307->length);
    for (int32_t var3 = 0; var3 < this->field_1307->length; var3++) {
        this->class_91::field_1232 = this->field_1307->at(var3)->method_848(this->class_91::field_1232);
        if (class_16::method_100(this->class_91::field_1232->field_37) > this->field_1310) {
            this->field_1310 = class_16::method_100(this->class_91::field_1232->field_37);
        }
        if (class_16::method_100(this->class_91::field_1232->field_38) > this->field_1310) {
            this->field_1310 = class_16::method_100(this->class_91::field_1232->field_38);
        }
        if (class_16::method_100(this->class_91::field_1232->field_39) > this->field_1310) {
            this->field_1310 = class_16::method_100(this->class_91::field_1232->field_39);
        }
        {
            switch ((this->field_1307->at(var3)->field_1344)) {
            case 3300:
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1232->field_37, (this->class_91::field_1232->field_38 + 2000), this->class_91::field_1232->field_39, 0, 0, 0, 5000));
                break;
            case 3301:
                ;
            case 3302:
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1232->field_37, this->class_91::field_1232->field_38, this->class_91::field_1232->field_39, 0, 0, 0, 4000));
                break;
            case 3303:
                ;
            case 3311:
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1232->field_37, (this->class_91::field_1232->field_38 - 2000), this->class_91::field_1232->field_39, 0, 0, 0, 5000));
                break;
            case 3304:
                ;
            case 3310:
                this->class_91::field_1233->method_10(0, (-250), 1150);
                class_98::field_1299 = this->field_1307->at(var3)->field_1341->method_508(this->class_91::field_1233, class_98::field_1299);
                this->class_91::field_1233->method_15(this->class_91::field_1232);
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1233->field_37, this->class_91::field_1233->field_38, this->class_91::field_1233->field_39, 0, 0, 0, 3000));
                break;
            case 3305:
                ;
            case 3307:
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1232->field_37, this->class_91::field_1232->field_38, this->class_91::field_1232->field_39, 0, 0, 0, 8000));
                break;
            case 3306:
                ;
            case 3308:
                this->class_91::field_1233->method_10(0, 0, 1150);
                class_98::field_1299 = this->field_1307->at(var3)->field_1341->method_508(this->class_91::field_1233, class_98::field_1299);
                this->class_91::field_1233->method_15(this->class_91::field_1232);
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_31>(this->class_91::field_1232->field_37, this->class_91::field_1232->field_38, this->class_91::field_1232->field_39, 0, 0, 0, 8500, 6000, 8500));
                break;
            case 3309:
                this->class_91::field_1233->method_10(0, (-270), 0);
                class_98::field_1299 = this->field_1307->at(var3)->field_1341->method_508(this->class_91::field_1233, class_98::field_1299);
                this->class_91::field_1233->method_15(this->class_91::field_1232);
                this->class_99::field_1303->at(var3) = jrt::Ref<class_29>(jrt::New<class_30>(this->class_91::field_1233->field_37, this->class_91::field_1233->field_38, this->class_91::field_1233->field_39, 0, 0, 0, 4000));
            }
        }
        jrt::Ref<jrt::Array<int32_t>> var4{};
        if ((var4 = this->method_825(this->field_1307->at(var3)->field_1344, var1->method_752())) != nullptr) {
            this->field_1307->at(var3)->method_873(((this->field_1307->at(var3)->field_1344 == 3304) ? 60 : ((this->field_1307->at(var3)->field_1344 == 3300) ? 800 : 170)));
            this->field_1307->at(var3)->method_876(var4->at(0), var4->at(1));
            this->field_1307->at(var3)->method_877(((var4->at(0) == var4->at(1)) ? int8_t(1) : int8_t(2)));
        }
    }
    this->field_1310 += 5000;
    this->field_1308 = jrt::newArray<int32_t>((this->field_1307->length * 3));
    for (int32_t var5 = 0; var5 < this->field_1307->length; var5++) {
        this->field_1308->at((var5 * 3)) = this->field_1307->at(var5)->method_852();
        this->field_1308->at(((var5 * 3) + 1)) = this->field_1307->at(var5)->method_853();
        this->field_1308->at(((var5 * 3) + 2)) = this->field_1307->at(var5)->method_854();
    }
}

jrt::Ref<jrt::Array<int32_t>> class_100::method_825(int32_t var1, bool var2) {
    jrt::Ref<jrt::Array<int32_t>> var3 = jrt::newArray<int32_t>(2);
    {
        switch (var1) {
        case 3300:
            ;
        case 3311:
            var3->at(0) = var2 ? 0 : 2;
            var3->at(1) = var2 ? 1 : 3;
            break;
        case 3301:
            ;
        case 3302:
            ;
        case 3303:
            return jrt::Ref<jrt::Array<int32_t>>(nullptr);
        case 3304:
            var3->at(0) = 0;
            var3->at(1) = 2;
            break;
        case 3305:
            ;
        case 3306:
            ;
        case 3309:
            ;
        case 3310:
            var3->at(0) = var2 ? 0 : 2;
            var3->at(1) = var3->at(0);
            break;
        case 3307:
            ;
        case 3308:
            var3->at(0) = var2 ? 0 : 2;
            var3->at(1) = var2 ? 1 : 3;
        }
    }
    return var3;
}

void class_100::method_805(int64_t var1) {
    for (int32_t var3 = 0; var3 < this->field_1307->length; var3++) {
        this->class_91::field_1232 = class_84::field_1110->field_40->method_849(this->class_91::field_1232);
        this->class_91::field_1233->method_10(this->field_1308->at((var3 * 3)), this->field_1308->at(((var3 * 3) + 1)), this->field_1308->at(((var3 * 3) + 2)));
        this->class_91::field_1233->method_16(this->class_91::field_1232, class_98::field_1299);
        // Deep3D-PC: the far view (Config::farViewOn) sees far parts where they are;
        // the phone's view brings those past 30000 in to 30000 and shrinks them to match
        int32_t var4;
        if (!org::deep3d::Config::farViewOn() && (var4 = class_98::field_1299->method_23()) > 30000) {
            class_98::field_1299->method_22();
            class_98::field_1299->method_18(30000);
            class_98::field_1299->method_15(this->class_91::field_1232);
            this->field_1307->at(var3)->method_846(class_98::field_1299);
            int32_t var5 = jrt::f2i((30000.0f / float(var4)) * 4096.0f);
            this->field_1307->at(var3)->method_869(var5, var5, var5);
            continue;
        }
        this->field_1307->at(var3)->method_869(4096, 4096, 4096);
        this->field_1307->at(var3)->method_845(this->field_1308->at((var3 * 3)), this->field_1308->at(((var3 * 3) + 1)), this->field_1308->at(((var3 * 3) + 2)));
    }
}

void class_100::method_809() {
    class_4::deep3dKind = 1;
    for (int32_t var1 = 0; var1 < this->field_1307->length; var1++) {
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1307->at(var1)));
    }
    class_4::deep3dKind = 0;
}

jrt::Ref<class_3> class_100::method_799(jrt::Ref<class_3> var1) {
    var1->method_10(this->deep3dOX, this->deep3dOY, this->deep3dOZ);
    return var1;
}

/* Deep3D-PC: Open Sea puts every station at its place on the map. Its
   modules move there; its docking box and collision volumes stay where
   they were built, and what is tested against them is taken there first */
void class_100::deep3dPlace(int32_t x, int32_t y, int32_t z) {
    this->method_827(x - this->deep3dOX, y - this->deep3dOY, z - this->deep3dOZ);
    this->deep3dOX = x, this->deep3dOY = y, this->deep3dOZ = z;
    this->class_91::field_1234 = x, this->class_91::field_1235 = y, this->class_91::field_1236 = z;
    this->class_98::field_1300 = x, this->class_98::field_1301 = y, this->class_98::field_1302 = z;
}

jrt::Ref<class_108> class_100::method_826() {
    return this->field_1307->at(0);
}

void class_100::method_827(int32_t var1, int32_t var2, int32_t var3) {
    for (int32_t var4 = 0; var4 < this->field_1307->length; var4++) {
        this->field_1307->at(var4)->method_843(var1, var2, var3);
        this->field_1308->at((var4 * 3)) = this->field_1308->at((var4 * 3)) + var1;
        this->field_1308->at(((var4 * 3) + 1)) = this->field_1308->at(((var4 * 3) + 1)) + var2;
        this->field_1308->at(((var4 * 3) + 2)) = this->field_1308->at(((var4 * 3) + 2)) + var3;
    }
}

bool class_100::method_806(int32_t var1, int32_t var2, int32_t var3) {
    var1 -= this->deep3dOX, var2 -= this->deep3dOY, var3 -= this->deep3dOZ;
    return (((((float(var1) < this->class_91::field_1225->field_362) && (float(var1) > (-this->class_91::field_1225->field_362))) && (float(var2) < this->class_91::field_1225->field_362)) && (float(var2) > (-this->class_91::field_1225->field_362))) && (float(var3) < this->class_91::field_1225->field_362)) && (float(var3) > (-this->class_91::field_1225->field_362));
}

bool class_100::method_828(int32_t var1, int32_t var2, int32_t var3) {
    var1 -= this->deep3dOX, var2 -= this->deep3dOY, var3 -= this->deep3dOZ;
    if (((((((var1 < this->field_1310) && (var1 > (-this->field_1310))) && (var2 < this->field_1310)) && (var2 > (-this->field_1310))) && (var3 < this->field_1310)) && (var3 > (-this->field_1310))) && (this->class_99::field_1303 != nullptr)) {
        for (int32_t var4 = 0; var4 < this->class_99::field_1303->length; var4++) {
            if (this->class_99::field_1303->at(var4)->method_288(var1, var2, var3)) {
                this->field_1309 = var4;
                return true;
            }
        }
    }
    return false;
}

bool class_100::method_807(jrt::Ref<class_3> var1) {
    return this->method_828(var1->field_37, var1->field_38, var1->field_39);
}

jrt::Ref<class_3> class_100::method_808(jrt::Ref<class_3> var1) {
    if (this->class_99::field_1303 != nullptr && (this->deep3dOX | this->deep3dOY | this->deep3dOZ) != 0) {
        jrt::Ref<class_3> rel = jrt::New<class_3>(var1->field_37 - this->deep3dOX, var1->field_38 - this->deep3dOY, var1->field_39 - this->deep3dOZ);
        return this->class_99::field_1303->at(this->field_1309)->method_285(rel);
    }
    return (this->class_99::field_1303 != nullptr) ? this->class_99::field_1303->at(this->field_1309)->method_285(var1) : jrt::Ref<class_3>(nullptr);
}

void class_100::method_794() {
    if (this->field_1307 != nullptr) {
        for (int32_t var1 = 0; var1 < this->field_1307->length; var1++) {
            if (this->field_1307->at(var1) != nullptr) {
                this->field_1307->at(var1)->method_894();
                this->field_1307->at(var1) = jrt::Ref<class_108>(nullptr);
            }
        }
    }
    this->field_1307 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    this->field_1308 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

void class_100::__dumpFields(jrt::Dumper& d) {
    class_99::__dumpFields(d);
    d.f("field_1307", this->field_1307);
    d.f("field_1308", this->field_1308);
    d.f("field_1309", this->field_1309);
    d.f("field_1310", this->field_1310);
}

