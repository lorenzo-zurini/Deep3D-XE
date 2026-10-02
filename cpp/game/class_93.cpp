// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_93::__clinit() {
}

void class_93::__init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7) {
    class_91::__init(var1, var2, var3, var4, var5, var6, var7);
    this->field_1246 = jrt::New<class_3>();
    this->field_1247 = jrt::New<class_8>();
    this->class_91::field_1225->field_377 = var4->field_1341;
    this->field_1246->method_10(var5, var6, var7);
    this->class_91::field_1224 = int16_t(5);
    var4->method_876(0, 0);
    var4->method_878();
}

void class_93::method_794() {
    class_91::method_794();
    this->field_1250 = jrt::Ref<class_37>(nullptr);
    this->field_1251 = jrt::Ref<class_116>(nullptr);
}

void class_93::method_811() {
    if (((this->field_1247->field_72 < 3000.0f) && (this->field_1247->field_73 < 3000.0f)) && (this->field_1247->field_74 < 3000.0f)) {
        this->field_1250->method_343(25);
    }
    this->class_91::field_1224 = int16_t(999);
    if (this->class_91::field_1231 != nullptr) {
        [&]() { auto __r = this->class_91::field_1231; int32_t __a1 = this->class_91::field_1226->method_850()->field_37; int32_t __a2 = this->class_91::field_1226->method_850()->field_38; int32_t __a3 = this->class_91::field_1226->method_850()->field_39; return __r->method_741(__a1, __a2, __a3); }();
    }
    this->class_91::field_1225->field_375 = false;
    this->class_91::field_1229->method_257(this->class_91::field_1227, this->class_91::field_1225->field_383);
}

void class_93::method_805(int64_t var1) {
    if (int32_t(this->class_91::field_1224) != 4) {
        this->field_1248 = var1;
        this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
        if (((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 999)) {
            this->class_91::field_1225->method_353(var1);
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var3 = this->class_91::field_1225->field_360;
            if (this->class_91::field_1225->field_360 != nullptr) {
                int32_t var4 = 0;
                this->field_1250 = jrt::Ref<class_37>(nullptr);
                for (int32_t var5 = 0; var5 < var3->length; var5++) {
                    if (var3->at(var5)->field_375) {
                        this->class_91::field_1232 = var3->at(var5)->method_344(this->class_91::field_1232);
                        this->field_1246 = this->class_91::field_1226->method_848(this->field_1246);
                        this->field_1247->field_72 = float((this->field_1246->field_37 - this->class_91::field_1232->field_37));
                        this->field_1247->field_73 = float((this->field_1246->field_38 - this->class_91::field_1232->field_38));
                        this->field_1247->field_74 = float((this->field_1246->field_39 - this->class_91::field_1232->field_39));
                        if (((((((int32_t(this->class_91::field_1224) != 1) && (this->field_1247->field_72 < 3000.0f)) && (this->field_1247->field_72 > (-3000.0f))) && (this->field_1247->field_73 < 3000.0f)) && (this->field_1247->field_73 > (-3000.0f))) && (this->field_1247->field_74 < 3000.0f)) && (this->field_1247->field_74 > (-3000.0f))) {
                            this->class_91::field_1224 = int16_t(1);
                            this->class_91::field_1226->method_876(1, 1);
                            this->class_91::field_1226->method_877(int8_t(2));
                            this->field_1249 = int64_t(0);
                            this->class_91::field_1225->method_327(this->class_91::field_1225->field_364);
                            class_84::field_1122->method_770(11);
                            var4 = var5;
                            break;
                        }
                    }
                }
                this->field_1250 = this->class_91::field_1225->method_326(var4);
            }
            if ((((this->class_91::field_1225->field_363 <= 0) && (int32_t(this->class_91::field_1224) != 5)) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
                this->class_91::field_1225->field_375 = false;
                this->class_91::field_1229->method_257(this->class_91::field_1227, this->class_91::field_1225->field_383);
                this->class_91::field_1224 = int16_t(3);
                this->field_1249 = int64_t(0);
                if (this->field_1251 != nullptr) {
                    this->field_1251->method_909(this->field_1246->field_37, this->field_1246->field_38, this->field_1246->field_39);
                }
            }
        }
        this->field_1249 += var1;
        this->class_91::field_1226->method_843(0, (class_16::method_91(int32_t(this->field_1249)) >> 6), 0);
        {
            switch (int32_t(this->class_91::field_1224)) {
            case 0:
                this->class_91::field_1224 = int16_t(5);
                return;
            case 1:
                this->field_1249 += var1;
                this->class_91::field_1226->method_860(0, (int32_t(var1) << 1), 0);
                if (this->field_1249 > int64_t(2000)) {
                    this->method_811();
                    return;
                }
                break;
            case 3:
                if (this->field_1251 != nullptr) {
                    this->field_1251->method_895(var1);
                }
                this->field_1249 += var1;
                if (this->field_1249 > int64_t(2000)) {
                    this->class_91::field_1224 = int16_t(4);
                    this->class_91::field_1225->method_327(0);
                }
            case 4:
                ;
            default:
                break;
            case 5:
                this->class_91::field_1225->method_327(this->class_91::field_1225->field_364);
                return;
            case 999:
                this->class_91::field_1226->method_868(2048, 2048, 2048);
                this->class_91::field_1226->method_860(0, (int32_t(var1) << 1), 0);
                if (this->class_91::field_1231 == nullptr) {
                    this->class_91::field_1224 = int16_t(4);
                    this->class_91::field_1225->method_327(0);
                    return;
                }
                if (this->class_91::field_1231->method_743()) {
                    this->class_91::field_1224 = int16_t(4);
                    this->class_91::field_1225->method_327(0);
                    return;
                }
            }
        }
    }
}

void class_93::method_809() {
    class_4::deep3dKind = 2;
    this->deep3dRender();
    class_4::deep3dKind = 0;
}

void class_93::deep3dRender() {
    if (int32_t(this->class_91::field_1224) != 4) {
        if (int32_t(this->class_91::field_1224) == 5) {
            class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_91::field_1226));
        } else if ((int32_t(this->class_91::field_1224) != 3) && (int32_t(this->class_91::field_1224) != 4)) {
            class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_91::field_1226));
        }
        if ((int32_t(this->class_91::field_1224) == 3) && (this->field_1251 != nullptr)) {
            this->field_1251->method_887();
        }
        if ((int32_t(this->class_91::field_1224) == 999) && (this->class_91::field_1231 != nullptr)) {
            this->class_91::field_1231->method_742(this->field_1248);
        }
    }
}

bool class_93::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_93::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1246", this->field_1246);
    d.f("field_1247", this->field_1247);
    d.f("field_1248", this->field_1248);
    d.f("field_1249", this->field_1249);
    d.f("field_1250", this->field_1250);
    d.f("field_1251", this->field_1251);
}

