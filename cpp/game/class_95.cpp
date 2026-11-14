// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_95::__clinit() {
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> var10000 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({0, 1700, 6061}), jrt::arrayOf<int32_t>({0, 1995, (-6212)}), jrt::arrayOf<int32_t>({805, 1779, 927}), jrt::arrayOf<int32_t>({(-805), 1779, 927})});
    var10000 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({(-680), (-78), 3602}), jrt::arrayOf<int32_t>({680, (-78), 3602}), jrt::arrayOf<int32_t>({(-3119), 1157, (-1937)}), jrt::arrayOf<int32_t>({3119, 1157, (-1937)}), jrt::arrayOf<int32_t>({(-2127), (-1364), (-812)}), jrt::arrayOf<int32_t>({2127, (-1364), (-812)})});
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var1 = jrt::arrayOf<jrt::Ref<class_3>>({jrt::New<class_3>(0, 0, 4096), jrt::New<class_3>(0, 0, (-4096)), jrt::New<class_3>(4096, 0, 0), jrt::New<class_3>((-4096), 0, 0)});
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var2 = jrt::arrayOf<jrt::Ref<class_3>>({jrt::New<class_3>(0, 0, 4096), jrt::New<class_3>(0, 0, 4096), jrt::New<class_3>(0, 4096, 0), jrt::New<class_3>(0, 4096, 0), jrt::New<class_3>(0, (-4096), 0), jrt::New<class_3>(0, (-4096), 0)});
}

void class_95::__init(int32_t var1, int32_t var2, bool var3, jrt::Ref<class_37> var4, jrt::Ref<class_108> var5, int32_t var6, int32_t var7, int32_t var8) {
    class_91::__init(var1, var3, var4, var5, var6, var7, var8);
    this->field_1256 = jrt::New<class_3>();
    this->field_1257 = jrt::New<class_3>();
    this->field_1258 = jrt::New<class_3>();
    this->field_1259 = jrt::New<class_3>();
    this->field_1260 = jrt::New<class_3>();
    this->class_91::field_1225->field_377 = var5->field_1341;
    this->field_1256->method_10(var6, var7, var8);
    this->field_1255 = false;
    this->field_1262 = jrt::cast<class_108>(var5->method_840());
    jrt::Ref<jrt::Array<int32_t>> var9{};
    if ((var9 = class_90::method_789(var5->field_1344, var2)) != nullptr) {
        var5->method_876(var9->at(0), var9->at(1));
        var5->method_877(int8_t(2));
    }
}

void class_95::method_794() {
    class_91::method_794();
    this->field_1253 = jrt::Ref<jrt::Array<jrt::Ref<class_29>>>(nullptr);
    this->field_1261 = jrt::Ref<class_37>(nullptr);
    this->field_1256 = jrt::Ref<class_3>(nullptr);
    this->field_1257 = jrt::Ref<class_3>(nullptr);
    this->field_1258 = jrt::Ref<class_3>(nullptr);
    this->field_1259 = jrt::Ref<class_3>(nullptr);
}

void class_95::method_812(int32_t var1, int32_t var2, int32_t var3) {
    this->class_91::field_1234 = var1;
    this->class_91::field_1235 = var2;
    this->class_91::field_1236 = var3;
    this->class_91::field_1226->method_845(var1, var2, var3);
    this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
    this->field_1256->method_10(var1, var2, var3);
    this->field_1257->method_10(var1, var2, var3);
    if (this->field_1253 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_1253->length; var4++) {
            this->field_1253->at(var4)->method_286(this->class_91::field_1225->field_377->field_698, this->class_91::field_1225->field_377->field_699, this->class_91::field_1225->field_377->field_700);
        }
    }
}

jrt::Ref<class_3> class_95::method_799(jrt::Ref<class_3> var1) {
    return this->class_91::field_1226->method_848(var1);
}

void class_95::method_805(int64_t var1) {
    this->field_1254 = var1;
    this->class_91::field_1225->method_353(var1);
    if ((this->field_1255 && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
        if (org::deep3d::Step::exact()) {
            this->class_91::field_1226->method_847(int32_t(var1));
        } else {
            this->class_91::field_1226->deep3dGo(33.0 * org::deep3d::Step::scale());   // Deep3D-PC
        }
        this->class_91::field_1225->field_377 = this->class_91::field_1226->field_1341;
        if (this->field_1253 != nullptr) {
            for (int32_t var3 = 0; var3 < this->field_1253->length; var3++) {
                this->field_1253->at(var3)->method_286(this->class_91::field_1225->field_377->field_698, this->class_91::field_1225->field_377->field_699, this->class_91::field_1225->field_377->field_700);
            }
        }
    }
    this->class_91::field_1232 = class_84::field_1110->field_40->method_849(this->class_91::field_1232);
    this->class_91::field_1233->method_10(this->class_91::field_1226->method_852(), this->class_91::field_1226->method_853(), this->class_91::field_1226->method_854());
    this->class_91::field_1233->method_16(this->class_91::field_1232, this->field_1260);
    // Deep3D-PC: the far view (Config::farViewOn) sees far ships where they are; the
    // phone's view draws a copy brought in to 30000 and shrunk to match
    int32_t var6;
    if (!org::deep3d::Config::farViewOn() && (var6 = this->field_1260->method_23()) > 30000) {
        this->field_1262->method_870(this->class_91::field_1226->field_1341);
        this->field_1260->method_22();
        this->field_1260->method_18(30000);
        this->field_1260->method_15(this->class_91::field_1232);
        this->field_1262->method_846(this->field_1260);
        int32_t var4 = jrt::f2i((30000.0f / float(var6)) * 4096.0f);
        this->field_1262->method_869(var4, var4, var4);
        this->field_1263 = true;
    } else {
        this->field_1262->method_869(4096, 4096, 4096);
        this->field_1262->method_845(this->class_91::field_1226->method_852(), this->class_91::field_1226->method_853(), this->class_91::field_1226->method_854());
        this->field_1263 = false;
    }
    if (((this->class_91::field_1225->field_363 <= 0) && (int32_t(this->class_91::field_1224) != 3)) && (int32_t(this->class_91::field_1224) != 4)) {
        this->class_91::field_1225->field_375 = false;
        if (this->class_91::field_1228) {
            this->class_91::field_1229->method_257(this->class_91::field_1227, this->class_91::field_1225->field_383);
        } else {
            this->class_91::field_1229->method_259();
        }
        this->class_91::field_1224 = int16_t(3);
        if (this->class_91::field_1231 != nullptr) {
            this->class_91::field_1233 = this->class_91::field_1226->method_849(this->class_91::field_1233);
            this->class_91::field_1231->method_741(this->class_91::field_1233->field_37, this->class_91::field_1233->field_38, this->class_91::field_1233->field_39);
        }
    }
    {
        switch (int32_t(this->class_91::field_1224)) {
        case 3:
            if (this->class_91::field_1231 != nullptr) {
                if (this->class_91::field_1231->method_743()) {
                    this->class_91::field_1224 = int16_t(4);
                    return;
                }
            } else {
                this->class_91::field_1224 = int16_t(4);
            }
        case 4:
            ;
        default:
            break;
        case 5:
            if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 3)) {
                jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var7 = this->class_91::field_1225->field_360;
                if (this->class_91::field_1225->field_360 != nullptr) {
                    this->field_1261 = jrt::Ref<class_37>(nullptr);
                    for (int32_t var5 = 0; var5 < var7->length; var5++) {
                        if (var7->at(var5)->field_375) {
                            this->class_91::field_1232 = var7->at(var5)->method_344(this->class_91::field_1232);
                            if (((((((this->field_1256->field_37 - this->class_91::field_1232->field_37) < 50000) && ((this->field_1256->field_37 - this->class_91::field_1232->field_37) > (-50000))) && ((this->field_1256->field_38 - this->class_91::field_1232->field_38) < 50000)) && ((this->field_1256->field_38 - this->class_91::field_1232->field_38) > (-50000))) && ((this->field_1256->field_39 - this->class_91::field_1232->field_39) < 50000)) && ((this->field_1256->field_39 - this->class_91::field_1232->field_39) > (-50000))) {
                                this->field_1261 = this->class_91::field_1225->method_326(var5);
                                this->class_91::field_1232 = this->field_1261->method_344(this->class_91::field_1232);
                                this->field_1258->field_37 = this->class_91::field_1232->field_37;
                                this->field_1258->field_38 = this->class_91::field_1232->field_38;
                                this->field_1258->field_39 = this->class_91::field_1232->field_39;
                                break;
                            }
                        }
                    }
                }
            }
            this->field_1259->field_37 = this->field_1258->field_37 - this->field_1256->field_37;
            this->field_1259->field_38 = this->field_1258->field_38 - this->field_1256->field_38;
            this->field_1259->field_39 = this->field_1258->field_39 - this->field_1256->field_39;
            if ((((((this->field_1259->field_37 < 50000) && (this->field_1259->field_37 > (-50000))) && (this->field_1259->field_38 < 50000)) && (this->field_1259->field_38 > (-50000))) && (this->field_1259->field_39 < 50000)) && (this->field_1259->field_39 > (-50000))) {
                this->class_91::field_1224 = int16_t(1);
                this->class_91::field_1225->field_375 = true;
                return;
            }
        }
    }
}

void class_95::method_809() {
    if (int32_t(this->class_91::field_1224) != 4) {
        class_4::deep3dKind = 1;
        class_84::field_1110->method_25((this->field_1263 ? jrt::Ref<class_102>(this->field_1262) : jrt::Ref<class_102>(this->class_91::field_1226)));
        class_4::deep3dKind = 0;
        bool var1 = false;
        if ((int32_t(this->class_91::field_1224) == 3) && (this->class_91::field_1231 != nullptr)) {
            this->class_91::field_1231->method_742(this->field_1254);
        }
    }
}

bool class_95::method_806(int32_t var1, int32_t var2, int32_t var3) {
    if ((int32_t(this->class_91::field_1224) != 4) && (int32_t(this->class_91::field_1224) != 4)) {
        for (int32_t var4 = 0; var4 < this->field_1253->length; var4++) {
            if (this->field_1253->at(var4)->method_287(var1, var2, var3)) {
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

jrt::Ref<class_3> class_95::method_808(jrt::Ref<class_3> var1) {
    return (this->field_1253 != nullptr) ? this->field_1253->at(this->field_1264)->method_285(var1) : jrt::Ref<class_3>(nullptr);
}

bool class_95::method_807(jrt::Ref<class_3> var1) {
    return this->method_813(var1->field_37, var1->field_38, var1->field_39);
}

bool class_95::method_813(int32_t var1, int32_t var2, int32_t var3) {
    if (int32_t(this->class_91::field_1224) == 4) {
        return false;
    } else {
        for (int32_t var4 = 0; var4 < this->field_1253->length; var4++) {
            if (this->field_1253->at(var4)->method_288(var1, var2, var3)) {
                this->field_1264 = var4;
                return true;
            }
        }
        return false;
    }
}

void class_95::__dumpFields(jrt::Dumper& d) {
    class_91::__dumpFields(d);
    d.f("field_1253", this->field_1253);
    d.f("field_1254", this->field_1254);
    d.f("field_1255", this->field_1255);
    d.f("field_1256", this->field_1256);
    d.f("field_1257", this->field_1257);
    d.f("field_1258", this->field_1258);
    d.f("field_1259", this->field_1259);
    d.f("field_1260", this->field_1260);
    d.f("field_1261", this->field_1261);
    d.f("field_1262", this->field_1262);
    d.f("field_1263", this->field_1263);
    d.f("field_1264", this->field_1264);
}

