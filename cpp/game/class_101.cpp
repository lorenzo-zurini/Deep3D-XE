// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_101::field_1311{};
jrt::Ref<jrt::Array<int32_t>> class_101::field_1318{};
jrt::Ref<jrt::Array<int32_t>> class_101::field_1319{};
jrt::Ref<class_3> class_101::field_1320{};
jrt::Ref<class_3> class_101::field_1321{};
jrt::Ref<class_57> class_101::field_1322{};

void class_101::__clinit() {
    class_101::field_1311 = jrt::New<class_3>();
    class_101::field_1318 = jrt::newArray<int32_t>(3);
    class_101::field_1319 = jrt::newArray<int32_t>(3);
    class_101::field_1320 = jrt::New<class_3>();
    class_101::field_1321 = jrt::New<class_3>();
    class_101::field_1322 = jrt::New<class_57>();
}

void class_101::__init(int32_t var1, jrt::Ref<class_108> var2, jrt::Ref<class_40> var3, int32_t var4, int32_t var5, int32_t var6) {
    class_91::__init(var1, false, jrt::New<class_37>(1500.0f, (var3->field_392 * 2), 0), var2, var4, var5, var6);
    this->field_1323 = jrt::New<class_57>();
    this->field_1324 = false;
    this->field_1325 = false;
    this->field_1326 = false;
    this->class_91::field_1225->field_379 = jrt::Ref<class_91>(jrt::Ref<class_101>(this));
    this->field_1312 = var3;
    this->field_1331 = ((((var1 == 4444) || (var1 == 4445)) || (var1 == 4443)) || (var1 == 4446)) || (var1 == 4447);
    if (this->field_1331) {
        var2->method_864(256, 0, 0);
        this->field_1332 = var3->field_392;
    } else {
        this->field_1332 = class_16::method_97(1, (var3->field_392 + jrt::f2i(((float(((-25) + class_84::field_1123->nextInt(50))) / 100.0f) * float(var3->field_392)))));
    }
    this->field_1328 = 1.0f + (float(var3->field_393) / 2.2f);
    this->field_1315 = 2100 + jrt::f2i(((float(var3->field_393) / 10.0f) * 2100.0f));
    this->class_91::field_1224 = int16_t(0);
    this->field_1327 = this->class_91::field_1225->field_363;
    if (((var4 == 0) && (var5 == 0)) && (var6 == 0)) {
        [&]() { auto __r = class_101::field_1321; int32_t __a1 = ((-4096) + class_84::field_1123->nextInt(8192)); int32_t __a2 = ((-4096) + class_84::field_1123->nextInt(8192)); int32_t __a3 = ((-4096) + class_84::field_1123->nextInt(8192)); return __r->method_10(__a1, __a2, __a3); }();
        class_101::field_1321->method_22();
        this->class_91::field_1226->field_1341->method_512(class_101::field_1321);
        [&]() { auto __r = class_101::field_1320; int32_t __a4 = ((-30000) + class_84::field_1123->nextInt(59000)); int32_t __a5 = ((-30000) + class_84::field_1123->nextInt(59000)); int32_t __a6 = ((-30000) + class_84::field_1123->nextInt(59000)); return __r->method_10(__a4, __a5, __a6); }();
    } else {
        [&]() { auto __r = class_101::field_1320; int32_t __a7 = ((var4 - 8000) + class_84::field_1123->nextInt(16000)); int32_t __a8 = ((var5 - 8000) + class_84::field_1123->nextInt(16000)); int32_t __a9 = ((var6 - 8000) + class_84::field_1123->nextInt(16000)); return __r->method_10(__a7, __a8, __a9); }();
    }
    this->class_91::field_1226->method_846(class_101::field_1320);
    this->class_91::field_1235 = class_101::field_1320->field_38;
    if ((((((((var1 == 4424) || (var1 == 4427)) || (var1 == 4430)) || (var1 == 4432)) || (var1 == 4434)) || (var1 == 4440)) || (var1 == 4436)) || (var1 == 4438)) {
        this->field_1317 = class_43::method_381((var1 + 1));
        this->field_1317->field_1367 = 2;
        this->field_1317->method_870(this->class_91::field_1226->field_1341);
    }
    this->class_91::field_1238 = true;
    this->class_91::field_1239 = true;
    this->method_831();
    this->field_1330 = false;
    this->field_1333 = false;
}

void class_101::method_829(bool var1) {
    this->field_1330 = var1;
    if (var1) {
        class_101::field_1321->method_10(0, 0, 4096);
        this->class_91::field_1226->field_1341->method_512(class_101::field_1321);
    }
    this->method_805(int64_t(((-1024) + class_84::field_1123->nextInt(2048))));
    this->class_91::field_1225->method_327(10);
    this->field_1327 = this->class_91::field_1225->field_363;
}

void class_101::method_830(int32_t var1) {
    this->field_1324 = true;
    this->field_1325 = true;
    this->field_1314 = 0;
    this->field_1328 = 1.0f + (float(this->field_1312->field_393) / 2.2f);
    this->field_1328 *= (1.0f - (float(var1) / 100.0f));
}

void class_101::method_831() {
    this->field_1316 = this->field_1331 ? 0 : this->field_1315;
    this->field_1314 = 0;
    this->field_1324 = false;
    this->field_1325 = false;
}

int32_t class_101::method_832() {
    return (this->field_1316 / 1000) + 1;
}

bool class_101::method_833() {
    if ((int32_t(this->class_91::field_1224) == 4) || ((int32_t(this->class_91::field_1224) != 4) && class_21::method_178()->method_612(this->field_1332))) {
        this->method_795(false);
        this->class_91::field_1239 = false;
        this->class_91::field_1226->method_869(0, 0, 0);
        if (int32_t(this->class_91::field_1224) != 4) {
            if (class_21::method_132()->field_1146 == 7) {
                if (this->field_1312->field_391 == class_21::method_132()->field_1166) {
                    this->class_91::field_1229->method_260();
                }
            } else {
                this->class_91::field_1229->method_260();
            }
        }
    }
    if (int32_t(this->class_91::field_1224) == 4) {
        jrt::Ref<class_120> var1 = class_90::method_785()->at(18)->method_929(this->field_1332);
        if (class_21::method_178()->method_612(var1->field_1490)) {
            class_21::method_166(this->field_1332);
            class_21::method_178()->method_613(var1);
            class_69::method_640(var1->field_1480, var1->field_1490, false, false);
        } else {
            class_69::method_640(var1->field_1480, var1->field_1490, true, false);
        }
        this->field_1333 = false;
    } else {
        if (this->field_1317 != nullptr) {
            this->field_1317->method_870(this->class_91::field_1226->field_1341);
        }
        if (!class_21::method_178()->method_612(this->field_1332)) {
            class_69::method_640(this->field_1312->field_391, this->field_1332, true, false);
            this->class_91::field_1226->method_869(4096, 4096, 4096);
            if (this->field_1317 != nullptr) {
                this->field_1317->method_870(this->class_91::field_1226->field_1341);
            }
            this->field_1325 = false;
            this->field_1326 = false;
            return false;
        }
        class_21::method_178()->method_613(class_90::method_785()->at(this->field_1312->field_391)->method_929(this->field_1332));
        class_69::method_640(this->field_1312->field_391, this->field_1332, false, false);
        class_21::method_164(this->field_1312->field_391);
    }
    return true;
}

void class_101::method_834(int32_t var1) {
    this->class_91::field_1226->method_869(var1, var1, var1);
    if (this->field_1317 != nullptr) {
        this->field_1317->method_870(this->class_91::field_1226->field_1341);
    }
}

void class_101::method_805(int64_t var1) {
    this->field_1334 = int32_t(var1);
    if (this->class_91::field_1225->field_375 && (!this->field_1326)) {
        if (!this->field_1331) {
            this->field_1329 = int32_t(var1);
            if ((this->field_1327 > this->class_91::field_1225->field_363) && (int32_t(this->class_91::field_1224) != 4)) {
                this->field_1324 = true;
            }
            this->field_1327 = this->class_91::field_1225->field_363;
        }
        if (this->field_1324) {
            this->field_1328 += 0.01f;
            this->field_1314 = int32_t((int64_t(this->field_1314) + var1));
            this->field_1329 = jrt::f2i((float(var1) * this->field_1328));
            var1 <<= 1;
            if (this->field_1314 < 2000) {
                this->class_91::field_1226->field_1341->method_472(this->field_1323);
            } else {
                this->field_1316 = this->field_1316 - (this->field_1314 >> 1);
                if (!this->field_1330) {
                    int32_t var3 = this->field_1329 >> 1;
                    [&]() { auto __r = this->field_1323; int32_t __a1 = ((-(var3 >> 1)) + class_84::field_1123->nextInt(var3)); int32_t __a2 = ((-(var3 >> 1)) + class_84::field_1123->nextInt(var3)); int32_t __a3 = 0; return __r->method_491(__a1, __a2, __a3); }();
                }
                this->field_1314 = 0;
            }
            if (this->field_1316 <= 0) {
                if (this->field_1325) {
                    this->field_1326 = true;
                    class_69::method_634(0, 0, JRT_LIT(u""));
                } else {
                    this->method_831();
                }
            }
        }
        if (((!this->field_1331) && (this->class_91::field_1225->field_363 <= 0)) && (int32_t(this->class_91::field_1224) != 4)) {
            class_101::field_1320 = this->class_91::field_1226->method_848(class_101::field_1320);
            if (this->class_91::field_1239) {
                this->class_91::field_1226 = class_43::method_381(14);
                this->class_91::field_1226->field_1367 = 2;
                this->class_91::field_1226->method_846(class_101::field_1320);
                this->field_1317 = jrt::Ref<class_108>(nullptr);
                this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
                this->class_91::field_1225->field_379 = jrt::Ref<class_91>(jrt::Ref<class_101>(this));
                this->field_1333 = true;
                this->field_1332 = (this->field_1332 / 3) + 1;
            }
            class_101::field_1320->method_17(this->class_91::field_1229->field_272->method_664());
            int32_t var6 = class_16::method_98(40000, class_101::field_1320->method_23());
            float var4 = 1.0f - (float(var6) / 40000.0f);
            int32_t var5 = class_84::field_1122->field_1182;
            class_84::field_1122->method_769(9, jrt::f2i((float(var5) * var4)));
            this->class_91::field_1231->method_741(this->class_91::field_1226->method_852(), this->class_91::field_1226->method_853(), this->class_91::field_1226->method_854());
            class_21::method_207();
            this->class_91::field_1224 = int16_t(4);
            if (class_21::method_132()->field_1146 == 7) {
                if (this->field_1312->field_391 == class_21::method_132()->field_1166) {
                    this->class_91::field_1229->method_260();
                    return;
                }
            } else {
                this->class_91::field_1229->method_260();
            }
        } else if (int32_t(this->class_91::field_1224) == 4) {
            if (!this->field_1325) {
                this->class_91::field_1226->method_843(0, (int32_t(var1) / 3), 0);
            }
            if (this->field_1317 != nullptr) {
                this->field_1317->method_870(this->class_91::field_1226->field_1341);
            }
            if (this->method_835()) {
                this->method_795(false);
            }
        } else {
            if ((!this->field_1331) && (this->class_91::field_1227 != 4429)) {
                this->class_91::field_1226->method_847(this->field_1329);
                this->field_1313 = int32_t((int64_t(this->field_1313) + var1));
                this->field_1313 &= 4095;
            }
            {
                switch (this->class_91::field_1227) {
                case 4422:
                    this->class_91::field_1226->method_869(4096, (class_16::method_91(this->field_1313) / 3), 4096);
                    break;
                case 4423:
                    class_101::field_1322->method_491(0, (class_16::method_91(this->field_1313) >> 7), 0);
                    this->class_91::field_1226->field_1341->method_472(class_101::field_1322);
                    break;
                case 4424:
                    this->field_1317->method_870(this->class_91::field_1226->field_1341);
                    this->field_1317->method_868(4096, 4096, (4096 + (class_16::method_91((this->field_1313 << 2)) >> 2)));
                case 4425:
                    ;
                case 4428:
                    ;
                case 4429:
                    ;
                case 4431:
                    ;
                case 4433:
                    ;
                case 4435:
                    ;
                case 4437:
                    ;
                case 4439:
                    ;
                case 4441:
                    ;
                default:
                    break;
                case 4426:
                    this->class_91::field_1226->method_869(4096, (4096 + (class_16::method_91((this->field_1313 << 1)) >> 2)), 4096);
                    break;
                case 4427:
                    ;
                case 4432:
                    ;
                case 4436:
                    this->field_1317->method_870(this->class_91::field_1226->field_1341);
                    class_101::field_1322->method_491((-(class_16::method_91(this->field_1313) >> 6)), 0, 0);
                    this->field_1317->field_1341->method_472(class_101::field_1322);
                    class_101::field_1322->method_491((class_16::method_91(this->field_1313) >> 8), 0, 0);
                    this->class_91::field_1226->field_1341->method_472(class_101::field_1322);
                    break;
                case 4430:
                    ;
                case 4434:
                    ;
                case 4440:
                    this->field_1317->method_870(this->class_91::field_1226->field_1341);
                    class_101::field_1322->method_491(0, (class_16::method_91(this->field_1313) >> 5), 0);
                    this->field_1317->field_1341->method_472(class_101::field_1322);
                    class_101::field_1322->method_491(0, (-(class_16::method_91(this->field_1313) >> 7)), 0);
                    this->class_91::field_1226->field_1341->method_472(class_101::field_1322);
                    break;
                case 4438:
                    this->field_1317->method_870(this->class_91::field_1226->field_1341);
                    this->field_1317->method_869(4096, (4096 + (class_16::method_91((this->field_1313 << 2)) >> 2)), 4096);
                    break;
                case 4442:
                    this->class_91::field_1226->method_869(4096, 4096, (4096 + (class_16::method_91((this->field_1313 << 2)) >> 2)));
                }
            }
            if ((!this->field_1330) && this->method_835()) {
                this->method_836();
            }
        }
    }
}

bool class_101::method_835() {
    this->class_91::field_1232 = class_84::field_1110->field_40->method_849(this->class_91::field_1232);
    this->class_91::field_1233 = this->class_91::field_1232->method_16(this->class_91::field_1226->method_848(class_101::field_1311), this->class_91::field_1233);
    return this->class_91::field_1233->method_23() > (org::deep3d::Remaster::on() ? 46000 : 40000);
}

void class_101::method_836() {
    for (int32_t var1 = 0; var1 < class_101::field_1318->length; var1++) {
        class_101::field_1318->at(var1) = (-2048) + class_84::field_1123->nextInt(4096);
    }
    class_101::field_1320->method_10(class_101::field_1318->at(0), (class_101::field_1318->at(1) >> 1), class_101::field_1318->at(2));
    class_101::field_1320->method_22();
    class_101::field_1318->at(0) = class_101::field_1320->field_37;
    class_101::field_1318->at(1) = class_101::field_1320->field_38;
    class_101::field_1318->at(2) = class_101::field_1320->field_39;
    class_101::field_1320->method_18((org::deep3d::Remaster::on() ? 36000 : 30000));
    class_101::field_1320->method_15(class_84::field_1110->field_40->method_848(this->class_91::field_1233));
    this->class_91::field_1226->method_846(class_101::field_1320);
    for (int32_t var2 = 0; var2 < class_101::field_1319->length; var2++) {
        class_101::field_1319->at(var2) = (-15000) + class_84::field_1123->nextInt(30000);
        class_101::field_1319->at(var2) = class_101::field_1319->at(var2) - class_101::field_1318->at(var2);
    }
    class_101::field_1321->method_10(class_101::field_1319->at(0), class_101::field_1319->at(1), class_101::field_1319->at(2));
    class_101::field_1321->method_22();
    this->class_91::field_1226->field_1341->method_512(class_101::field_1321);
}

void class_101::method_809() {
    class_4::deep3dKind = 2;
    if (this->field_1317 != nullptr) {
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1317));
    }
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->class_91::field_1226));
    if (((int32_t(this->class_91::field_1224) == 4) && (this->class_91::field_1231 != nullptr)) && (!this->class_91::field_1231->method_743())) {
        this->class_91::field_1231->method_742(int64_t(this->field_1334));
    }
    class_4::deep3dKind = 0;
}

bool class_101::method_806(int32_t var1, int32_t var2, int32_t var3) {
    return false;
}

void class_101::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1312", this->field_1312);
    d.f("field_1313", this->field_1313);
    d.f("field_1314", this->field_1314);
    d.f("field_1315", this->field_1315);
    d.f("field_1316", this->field_1316);
    d.f("field_1317", this->field_1317);
    d.f("field_1323", this->field_1323);
    d.f("field_1324", this->field_1324);
    d.f("field_1325", this->field_1325);
    d.f("field_1326", this->field_1326);
    d.f("field_1327", this->field_1327);
    d.f("field_1328", this->field_1328);
    d.f("field_1329", this->field_1329);
    d.f("field_1330", this->field_1330);
    d.f("field_1331", this->field_1331);
    d.f("field_1332", this->field_1332);
    d.f("field_1333", this->field_1333);
    d.f("field_1334", this->field_1334);
}

