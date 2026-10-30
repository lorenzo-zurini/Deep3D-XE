// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_57> class_96::field_1274{};

void class_96::__clinit() {
    class_96::field_1274 = jrt::New<class_57>();
}

void class_96::__init(int32_t var1, int32_t var2, bool var3, jrt::Ref<class_37> var4, jrt::Ref<class_108> var5, int32_t var6, int32_t var7, int32_t var8) {
    class_91::__init(var1, var3, var4, var5, var6, var7, var8);
    this->field_1265 = 500;
    this->field_1266 = 2.1f;
    this->field_1267 = 2.0f;
    this->field_1268 = 20;
    this->field_1270 = jrt::New<class_3>();
    this->field_1271 = jrt::New<class_3>();
    this->field_1272 = jrt::New<class_3>();
    this->field_1273 = jrt::New<class_3>();
    this->field_1294 = var2;
    this->field_1271->method_10(var6, var7, var8);
    this->class_91::field_1239 = var1 != 19;
    this->field_1269 = jrt::New<class_25>();
    this->field_1287 = jrt::New<class_83>();
    this->field_1287->field_1072 = 50;
    this->field_1287->method_734(this->field_1271);
    this->field_1276 = var3 && (class_21::method_143() > 15);
    if (var1 == 19) {
        var5->method_873(64);
        var5->method_877(int8_t(2));
        this->field_1276 = false;
        this->field_1289 = 2.1f;
        this->field_1290 = 1.5f;
    } else {
        jrt::Ref<jrt::Array<int32_t>> var9{};
        if ((var9 = class_90::method_789(var5->field_1344, var2)) != nullptr) {
            var5->method_876(var9->at(0), var9->at(1));
            var5->method_877(int8_t(2));
        }
        this->field_1289 = this->field_1266;
        this->field_1290 = this->field_1267;
    }
    this->field_1284 = false;
    this->field_1285 = false;
    this->field_1286 = false;
    this->field_1288 = false;
    this->class_91::field_1240 = class_35::method_307();
    this->field_1293 = true;
}

void class_96::method_794() {
    class_91::method_794();
    if (this->field_1269 != nullptr) {
        this->field_1269->method_235();
    }
    this->field_1269 = jrt::Ref<class_25>(nullptr);
    if (this->field_1287 != nullptr) {
        this->field_1287->method_731();
    }
    this->field_1287 = jrt::Ref<class_83>(nullptr);
    this->field_1281 = jrt::Ref<class_37>(nullptr);
    this->field_1291 = jrt::Ref<jrt::Array<jrt::Ref<class_29>>>(nullptr);
}

void class_96::method_814(bool var1) {
    this->field_1284 = var1;
    if (var1) {
        this->class_91::field_1240 = jrt::Ref<class_120>(nullptr);
    }
}

bool class_96::method_815() {
    return this->field_1284 && (!this->class_91::field_1239);
}

bool class_96::method_816() {
    return !this->class_91::field_1239;
}

void class_96::method_817() {
    this->class_91::field_1239 = false;
    this->method_795(false);
    if (this->field_1284) {
        class_69::method_640(0, 0, false, true);
    } else if (class_21::method_178()->method_612(this->class_91::field_1240->field_1490)) {
        class_21::method_152();
        class_21::method_178()->method_613(this->class_91::field_1240);
        class_69::method_640(this->class_91::field_1240->field_1480, this->class_91::field_1240->field_1490, false, false);
    } else {
        class_69::method_640(this->class_91::field_1240->field_1480, this->class_91::field_1240->field_1490, true, false);
    }
}

void class_96::method_818(int32_t var1, int32_t var2, int32_t var3) {
    this->class_91::field_1234 = var1;
    this->class_91::field_1235 = var2;
    this->class_91::field_1236 = var3;
    this->class_91::field_1226->method_845(var1, var2, var3);
    this->field_1271->method_10(var1, var2, var3);
    if (this->field_1287 != nullptr) {
        this->field_1287->method_734(this->field_1271);
    }
}

void class_96::method_796(int32_t var1) {
    this->field_1276 = false;
    this->field_1266 = float(var1);
    this->field_1289 = this->field_1266;
}

void class_96::method_805(int64_t var1) {
    if ((int32_t(this->class_91::field_1224) == 4) && (!this->class_91::field_1239)) {
        this->method_795(false);
    } else {
        this->field_1278 = int32_t((int64_t(this->field_1278) + var1));
        this->field_1277 = int32_t((int64_t(this->field_1277) + var1));
        this->field_1283 = var1;
        this->field_1270 = this->class_91::field_1226->method_848(this->field_1270);
        if (this->field_1269 != nullptr) {
            this->class_91::field_1232->method_9(this->field_1270);
            if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
                this->class_91::field_1233 = this->class_91::field_1226->method_855(this->class_91::field_1233);
                this->class_91::field_1233->method_22();
                this->class_91::field_1233->method_19(32768, this->class_91::field_1233);
                this->class_91::field_1232->method_17(this->class_91::field_1233);
            }
            this->field_1269->method_236(this->class_91::field_1232, int32_t(var1));
            this->field_1280 = int32_t((int64_t(this->field_1280) + var1));
            if (this->field_1280 > 200) {
                if (this->field_1287 != nullptr) {
                    this->field_1287->method_733(this->field_1270);
                }
                this->field_1280 = 0;
            }
        }
        this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
        if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
            this->class_91::field_1225->method_353(var1);
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var3 = this->class_91::field_1225->field_360;
            if ((this->class_91::field_1225->field_360 != nullptr) && (this->field_1269 != nullptr)) {
                if (!this->field_1292) {
                    this->field_1275 = -1;
                } else if ((this->field_1275 >= 0) && (!var3->at(this->field_1275)->field_375)) {
                    this->field_1292 = false;
                }
                this->field_1281 = jrt::Ref<class_37>(nullptr);
                if (this->field_1277 > 5000) {
                    if (this->field_1288) {
                        this->field_1288 = false;
                    } else {
                        this->field_1288 = class_84::field_1123->nextInt(100) < 20;
                    }
                    this->field_1277 = 0;
                    if ((class_84::field_1123->nextInt(100) < 30) && (var3->length > 1)) {
                        this->field_1292 = false;
                        for (int32_t var9 = 0; (var9 < 5) && (!this->field_1292); var9++) {
                            this->field_1275 = class_84::field_1123->nextInt(var3->length);
                            if (var3->at(this->field_1275)->field_375) {
                                this->class_91::field_1232 = var3->at(this->field_1275)->method_344(this->class_91::field_1232);
                                if (((((((this->field_1270->field_37 - this->class_91::field_1232->field_37) < 50000) && ((this->field_1270->field_37 - this->class_91::field_1232->field_37) > (-50000))) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) < 50000)) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) > (-50000))) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) < 50000)) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) > (-50000))) {
                                    this->field_1292 = true;
                                    break;
                                }
                            }
                        }
                        if (!this->field_1292) {
                            this->field_1275 = 0;
                        }
                    } else {
                        this->field_1275 = 0;
                    }
                    if (var3->at(this->field_1275)->field_375 && (!var3->at(this->field_1275)->method_345())) {
                        this->class_91::field_1232 = var3->at(this->field_1275)->method_344(this->class_91::field_1232);
                        if (((((((this->field_1270->field_37 - this->class_91::field_1232->field_37) < 50000) && ((this->field_1270->field_37 - this->class_91::field_1232->field_37) > (-50000))) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) < 50000)) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) > (-50000))) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) < 50000)) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) > (-50000))) {
                            this->field_1275 = this->field_1275;
                        } else {
                            this->field_1275 = -1;
                        }
                    } else {
                        this->field_1275 = -1;
                    }
                } else if (!this->field_1292) {
                    for (int32_t var4 = 0; var4 < var3->length; var4++) {
                        if (var3->at(var4)->field_375 && (!var3->at(var4)->method_345())) {
                            this->class_91::field_1232 = var3->at(var4)->method_344(this->class_91::field_1232);
                            if (((((((this->field_1270->field_37 - this->class_91::field_1232->field_37) < 50000) && ((this->field_1270->field_37 - this->class_91::field_1232->field_37) > (-50000))) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) < 50000)) && ((this->field_1270->field_38 - this->class_91::field_1232->field_38) > (-50000))) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) < 50000)) && ((this->field_1270->field_39 - this->class_91::field_1232->field_39) > (-50000))) {
                                this->field_1275 = var4;
                                break;
                            }
                        }
                    }
                }
                this->field_1282 = false;
                if ((this->field_1275 == (-1)) && (this->class_91::field_1230 != nullptr)) {
                    if ((this->class_91::field_1230->method_110() != nullptr) && this->class_91::field_1225->field_375) {
                        this->class_91::field_1230->method_114(this->class_91::field_1225->field_377->field_698, this->class_91::field_1225->field_377->field_699, this->class_91::field_1225->field_377->field_700);
                        if (this->class_91::field_1230->method_110() != nullptr) {
                            this->field_1272->field_37 = this->class_91::field_1230->method_110()->field_1295;
                            this->field_1272->field_38 = this->class_91::field_1230->method_110()->field_1296;
                            this->field_1272->field_39 = this->class_91::field_1230->method_110()->field_1297;
                            this->field_1282 = true;
                        }
                    } else {
                        this->field_1275 = 0;
                        this->field_1281 = this->class_91::field_1225->method_326(this->field_1275);
                        this->class_91::field_1232 = this->field_1281->method_344(this->class_91::field_1232);
                        this->field_1272->field_37 = this->class_91::field_1232->field_37;
                        this->field_1272->field_38 = this->class_91::field_1232->field_38;
                        this->field_1272->field_39 = this->class_91::field_1232->field_39;
                    }
                } else {
                    if (this->field_1275 < 0) {
                        this->field_1275 = 0;
                    }
                    this->field_1281 = this->class_91::field_1225->method_326(this->field_1275);
                    this->class_91::field_1232 = this->field_1281->method_344(this->class_91::field_1232);
                    this->field_1272->field_37 = this->class_91::field_1232->field_37;
                    this->field_1272->field_38 = this->class_91::field_1232->field_38;
                    this->field_1272->field_39 = this->class_91::field_1232->field_39;
                }
            } else if (this->class_91::field_1230 != nullptr) {
                this->class_91::field_1230->method_114(this->class_91::field_1225->field_377->field_698, this->class_91::field_1225->field_377->field_699, this->class_91::field_1225->field_377->field_700);
                if (this->class_91::field_1230->method_110() != nullptr) {
                    this->field_1272->field_37 = this->class_91::field_1230->method_110()->field_1295;
                    this->field_1272->field_38 = this->class_91::field_1230->method_110()->field_1296;
                    this->field_1272->field_39 = this->class_91::field_1230->method_110()->field_1297;
                    this->field_1282 = true;
                }
            } else {
                this->class_91::field_1224 = int16_t(5);
            }
        }
        this->field_1273->field_37 = this->field_1272->field_37 - this->field_1270->field_37;
        this->field_1273->field_38 = this->field_1272->field_38 - this->field_1270->field_38;
        this->field_1273->field_39 = this->field_1272->field_39 - this->field_1270->field_39;
        if ((!this->class_91::field_1228) && (int32_t(this->class_91::field_1224) == 5)) {
            this->class_91::field_1232 = this->class_91::field_1229->field_272->field_969->method_344(this->class_91::field_1232);
            this->field_1273->field_37 = this->class_91::field_1232->field_37 - this->field_1270->field_37;
            this->field_1273->field_38 = this->class_91::field_1232->field_38 - this->field_1270->field_38;
            this->field_1273->field_39 = this->class_91::field_1232->field_39 - this->field_1270->field_39;
            if ((((((this->field_1273->field_37 < 10000) && (this->field_1273->field_37 > (-10000))) && (this->field_1273->field_38 < 10000)) && (this->field_1273->field_38 > (-10000))) && (this->field_1273->field_39 < 10000)) && (this->field_1273->field_39 > (-10000))) {
                this->class_91::field_1224 = int16_t(1);
                this->class_91::field_1225->field_375 = true;
            }
        }
        if (this->field_1291 != nullptr) {
            for (int32_t var6 = 0; var6 < this->field_1291->length; var6++) {
                this->field_1291->at(var6)->method_286(this->class_91::field_1225->field_377->field_698, this->class_91::field_1225->field_377->field_699, this->class_91::field_1225->field_377->field_700);
            }
        }
        if (((this->class_91::field_1225->field_363 <= 0) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
            if (this->class_91::field_1228) {
                if ((this->field_1294 == 2) && (!this->class_91::field_1225->field_383)) {
                    class_21::method_206();
                }
                this->class_91::field_1229->method_257(this->class_91::field_1227, this->class_91::field_1225->field_383);
            } else {
                this->class_91::field_1229->method_259();
            }
            this->class_91::field_1224 = int16_t(3);
            if (this->class_91::field_1231 != nullptr) {
                this->class_91::field_1231->method_741(this->field_1270->field_37, this->field_1270->field_38, this->field_1270->field_39);
            }
            int32_t var7 = class_16::method_98(40000, this->field_1273->method_23());
            float var10 = 1.0f - (float(var7) / 40000.0f);
            int32_t var5 = class_84::field_1122->field_1182;
            class_84::field_1122->method_769(((this->class_91::field_1227 == 19) ? 9 : 6), jrt::f2i((float(var5) * var10)));
            if (this->class_91::field_1239) {
                this->field_1271->method_9(this->field_1270);
                this->class_91::field_1226 = class_43::method_381(17);
                this->class_91::field_1226->field_1367 = 2;
                this->class_91::field_1226->method_846(this->field_1270);
                this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
                this->class_91::field_1225->field_379 = jrt::Ref<class_91>(jrt::Ref<class_96>(this));
                this->field_1287 = jrt::Ref<class_83>(nullptr);
            }
        }
        {
            switch (int32_t(this->class_91::field_1224)) {
            case 0:
                this->class_91::field_1224 = int16_t(1);
                break;
            case 1:
                if (this->field_1276) {
                    if ((this->field_1278 > 5000) && (this->field_1289 != 4.0f)) {
                        if (class_84::field_1123->nextInt(100) < this->field_1268) {
                            this->field_1279 = class_84::field_1123->nextInt(3000) + 5000;
                        }
                        this->field_1278 = 0;
                        this->field_1289 = 4.0f;
                        this->field_1290 = 1.3f;
                    }
                    if ((this->field_1289 == 4.0f) && (this->field_1278 > this->field_1279)) {
                        this->field_1278 = 0;
                        this->field_1289 = this->field_1266;
                        this->field_1290 = this->field_1267;
                    }
                }
                if ((((((((this->field_1281 != nullptr) && (!this->field_1282)) && (this->field_1273->field_37 < 8000)) && (this->field_1273->field_37 > (-8000))) && (this->field_1273->field_38 < 8000)) && (this->field_1273->field_38 > (-8000))) && (this->field_1273->field_39 < 8000)) && (this->field_1273->field_39 > (-8000))) {
                    this->field_1273 = this->class_91::field_1226->method_858(this->field_1273);
                }
                this->field_1273->method_22();
                this->class_91::field_1233->method_9(this->field_1273);
                this->field_1273 = this->class_91::field_1226->method_871(class_96::field_1274)->method_509(this->class_91::field_1233, this->field_1273);
                this->field_1273->field_38 = -this->field_1273->field_38;
                if ((((((((((((!this->field_1282) && (this->field_1281 != nullptr)) && (this->field_1273->field_37 < this->field_1265)) && (this->field_1273->field_37 > (-this->field_1265))) && (this->field_1273->field_38 < this->field_1265)) && (this->field_1273->field_38 > (-this->field_1265))) && ((this->field_1272->field_37 - this->field_1270->field_37) < 35000)) && ((this->field_1272->field_37 - this->field_1270->field_37) > (-35000))) && ((this->field_1272->field_38 - this->field_1270->field_38) < 35000)) && ((this->field_1272->field_38 - this->field_1270->field_38) > (-35000))) && ((this->field_1272->field_39 - this->field_1270->field_39) < 35000)) && ((this->field_1272->field_39 - this->field_1270->field_39) > (-35000))) {
                    if (this->field_1281->field_375 && (!this->field_1281->method_345())) {
                        this->class_91::field_1225->method_352(0, var1, false);
                    } else {
                        this->field_1292 = false;
                    }
                }
                if (!this->field_1288) {
                    this->class_91::field_1232->method_9(this->class_91::field_1226->method_855(this->class_91::field_1232));
                    this->class_91::field_1233->method_17(this->class_91::field_1232);
                    this->class_91::field_1233->method_22();
                    this->class_91::field_1233->method_18(org::deep3d::Step::exact() ? jrt::f2i((float(var1) * this->field_1290)) : org::deep3d::Step::shareAtLeast(jrt::f2i((float(33) * this->field_1290)), 16.0, this->deep3dSteer));   // Deep3D-PC
                    this->field_1273 = this->class_91::field_1232->method_14(this->class_91::field_1233, this->field_1273);
                    this->field_1273->method_22();
                    this->class_91::field_1226->field_1341->method_512(this->field_1273);
                }
                if (org::deep3d::Step::exact()) {
                    this->class_91::field_1226->method_847(jrt::f2i((float(var1) * this->field_1289)));
                } else {
                    this->class_91::field_1226->deep3dGo(jrt::f2i((float(33) * this->field_1289)) * org::deep3d::Step::scale());
                }   // Deep3D-PC
            case 2:
                ;
            default:
                break;
            case 3:
                this->field_1293 = false;
                if (this->class_91::field_1231 != nullptr) {
                    if (this->class_91::field_1231->method_743()) {
                        this->class_91::field_1224 = int16_t(4);
                    }
                } else {
                    this->class_91::field_1224 = int16_t(4);
                }
                break;
            case 4:
                if (this->class_91::field_1239 && this->class_91::field_1225->field_375) {
                    if (!this->class_91::field_1237) {
                        this->class_91::field_1226->method_843(0, (org::deep3d::Step::exact() ? ((-int32_t(var1)) / 2) : org::deep3d::Step::share(-16.0, this->deep3dSink)), 0);   // Deep3D-PC
                    }
                    if ([&]() { int32_t __l1 = this->class_91::field_1226->method_848(this->class_91::field_1232)->field_38; int32_t __r1 = (this->field_1271->field_38 - 30000); return (__l1 < __r1); }()) {
                        this->field_1285 = true;
                        this->method_795(false);
                    }
                } else {
                    this->method_795(false);
                }
                break;
            case 5:
                if ((((((this->class_91::field_1228 && (this->field_1273->field_37 < 50000)) && (this->field_1273->field_37 > (-50000))) && (this->field_1273->field_38 < 50000)) && (this->field_1273->field_38 > (-50000))) && (this->field_1273->field_39 < 50000)) && (this->field_1273->field_39 > (-50000))) {
                    this->class_91::field_1224 = int16_t(1);
                    this->class_91::field_1225->field_375 = true;
                }
            }
        }
        if (this->field_1293) {
            jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var8 = this->class_91::field_1229->field_276;
            if (this->class_91::field_1229->field_276 != nullptr) {
                for (int32_t var11 = 0; var11 < var8->length; var11++) {
                    if ((var8->at(var11) != nullptr) && var8->at(var11)->method_807(this->class_91::field_1226->method_848(this->class_91::field_1233))) {
                        this->class_91::field_1233 = var8->at(var11)->method_808(this->class_91::field_1226->method_848(this->class_91::field_1233));
                        if (this->class_91::field_1233 != nullptr) {
                            this->class_91::field_1232->method_9(this->class_91::field_1226->method_855(this->class_91::field_1232));
                            this->class_91::field_1233->method_17(this->class_91::field_1232);
                            this->class_91::field_1233->method_18(org::deep3d::Step::exact() ? jrt::f2i((float(var1) * 5.0f)) : org::deep3d::Step::shareAtLeast(165.0, 16.0, this->deep3dAvoid));   // Deep3D-PC
                            this->field_1270 = this->class_91::field_1232->method_14(this->class_91::field_1233, this->field_1270);
                            this->field_1270->method_22();
                            this->class_91::field_1226->field_1341->method_512(this->field_1270);
                            if (org::deep3d::Step::exact()) {
                                this->class_91::field_1226->method_847(jrt::f2i((float(var1) * this->field_1289)));
                            } else {
                                this->class_91::field_1226->deep3dGo(jrt::f2i((float(33) * this->field_1289)) * org::deep3d::Step::scale());
                            }
                        }
                    }
                }
            }
        }
    }
}

void class_96::method_809() {
    class_4::deep3dKind = 5;
    this->deep3dRender();
    class_4::deep3dKind = 0;
}

void class_96::deep3dRender() {
    if (((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) || (this->class_91::field_1239 && this->class_91::field_1225->field_375)) {
        class_91::method_809();
        if (this->field_1269 != nullptr) {
            this->field_1269->method_238();
        }
        if (this->field_1287 != nullptr) {
            this->field_1287->method_735();
        }
    }
    if ((int32_t(this->class_91::field_1224) == 3) && (this->class_91::field_1231->method_740() > 1)) {
        class_91::method_809();
    }
    if ((int32_t(this->class_91::field_1224) == 3) && (this->class_91::field_1231 != nullptr)) {
        this->class_91::field_1231->method_742(this->field_1283);
    }
}

bool class_96::method_806(int32_t var1, int32_t var2, int32_t var3) {
    if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
        if (this->field_1291 != nullptr) {
            for (int32_t var4 = 0; var4 < this->field_1291->length; var4++) {
                if (this->field_1291->at(var4)->method_287(var1, var2, var3)) {
                    return true;
                }
            }
        }
        return false;
    } else {
        return false;
    }
}

void class_96::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1265", this->field_1265);
    d.f("field_1266", this->field_1266);
    d.f("field_1267", this->field_1267);
    d.f("field_1268", this->field_1268);
    d.f("field_1269", this->field_1269);
    d.f("field_1270", this->field_1270);
    d.f("field_1271", this->field_1271);
    d.f("field_1272", this->field_1272);
    d.f("field_1273", this->field_1273);
    d.f("field_1275", this->field_1275);
    d.f("field_1276", this->field_1276);
    d.f("field_1277", this->field_1277);
    d.f("field_1278", this->field_1278);
    d.f("field_1279", this->field_1279);
    d.f("field_1280", this->field_1280);
    d.f("field_1281", this->field_1281);
    d.f("field_1282", this->field_1282);
    d.f("field_1283", this->field_1283);
    d.f("field_1284", this->field_1284);
    d.f("field_1285", this->field_1285);
    d.f("field_1286", this->field_1286);
    d.f("field_1287", this->field_1287);
    d.f("field_1288", this->field_1288);
    d.f("field_1289", this->field_1289);
    d.f("field_1290", this->field_1290);
    d.f("field_1291", this->field_1291);
    d.f("field_1292", this->field_1292);
    d.f("field_1293", this->field_1293);
    d.f("field_1294", this->field_1294);
}

