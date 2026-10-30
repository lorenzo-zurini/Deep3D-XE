// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_29> class_26::field_263{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> class_26::field_264{};
bool class_26::field_301{};
jrt::Ref<class_86> class_26::field_302{};

void class_26::__clinit() {
    class_26::field_263 = jrt::Ref<class_29>(jrt::New<class_30>(0, 0, 0, 0, 0, 0, 10000));
    class_26::field_264 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({(-1100), 200, 1100}), jrt::arrayOf<int32_t>({(-951), 161, (-1500)}), jrt::arrayOf<int32_t>({(-823), 115, (-4100)})});
}

void class_26::__init() {
    this->__init(3);
}

void class_26::__init(int32_t var1) {
    this->field_286 = JRT_LIT(u"");
    this->deep3dCam = jrt::newArray<float>(16);
    this->deep3dPos = jrt::New<class_3>();
    this->field_262 = var1;
    this->field_292 = 0;
    this->field_293 = false;
}

void class_26::method_239() {
    class_26::field_301 = true;
}

bool class_26::method_240() {
    if ((this->field_292 == 0) || this->field_293) {
        this->field_277 = jrt::Ref<class_18>(nullptr);
        this->field_279 = jrt::Ref<class_18>(nullptr);
        this->field_278 = jrt::Ref<class_18>(nullptr);
        this->field_290 = jrt::Ref<class_22>(nullptr);
        this->field_289 = jrt::Ref<class_22>(nullptr);
        this->field_266 = jrt::New<class_116>(class_43::method_380(2), 96, 0, 127, 32, 10, 700, 100, 500);
        this->field_268 = jrt::New<class_116>(class_43::method_380(2), 96, 0, 127, 32, 10, 700, 100, 500);
        this->method_241();
        OpenSea::begin(this);
        if (this->field_262 != 0) {
            this->method_244();
            if (class_26::field_301 && (this->field_272->field_970 != nullptr)) {
                this->field_272->method_670(this->field_276->at(2)->field_1226->method_852(), this->field_276->at(2)->field_1226->method_853(), this->field_276->at(2)->field_1226->method_854());
            } else {
                this->field_272->method_670(10, 0, 5000);
            }
            if (class_21::method_143() == 1) {
                this->field_272->method_670(0, 0, (-110000));
            }
        }
    }
    if ((this->field_292 != 1) && (!this->field_293)) {
        if (this->field_293) {
            this->field_292 = 0;
            return true;
        }
    } else {
        this->method_242();
        if (((this->field_262 != 3) || class_21::method_132()->field_1161) && ((this->field_262 != 3) || (!class_21::method_146()))) {
            if (this->field_262 != 3) {
                this->method_249();
                this->field_262 = 3;
            } else if ((!class_21::method_132()->method_754()) && class_21::method_132()->field_1161) {
                this->method_248();
            }
        } else {
            this->method_247();
        }
        this->method_250();
        this->method_251();
        if (this->field_272 != nullptr) {
            this->field_272->field_982 = this->field_277;
        }
        this->field_282 = (this->field_274 != nullptr) ? (this->field_274->length - this->field_284) : 0;
        this->field_281 = (this->field_273 != nullptr) ? (this->field_273->length - this->field_283) : 0;
        this->field_285 = 0;
        if (class_21::method_132()->field_1146 == 7) {
            if (this->field_275 != nullptr) {
                for (int32_t var1 = 0; var1 < this->field_275->length; var1++) {
                    if ((jrt::cast<class_101>(this->field_275->at(var1)))->field_1312->field_391 == class_21::method_132()->field_1166) {
                        this->field_285++;
                    }
                }
            }
        } else {
            this->field_285 = (this->field_275 != nullptr) ? this->field_275->length : 0;
        }
        this->field_286 = jrt::concat(jrt::f2i(((float(this->field_285) / float(class_21::method_132()->field_1167)) * 100.0f)), JRT_LIT(u"%/"), class_21::method_132()->field_1169, JRT_LIT(u"%"));
        this->field_288 = 0;
        this->field_293 = true;
    }
    this->field_292++;
    return this->field_293;
}

void class_26::method_241() {
    if (this->field_265 == nullptr) {
        this->field_265 = class_43::method_381(9991);
    }
    this->field_265->method_893(class_43::method_380(0));
    this->field_276 = jrt::newArray<jrt::Ref<class_91>>(3);
    if (class_21::method_147()) {
        this->field_276->at(0) = jrt::Ref<class_91>(nullptr);
    } else {
        this->field_276->at(0) = jrt::Ref<class_91>(jrt::New<class_100>(class_21::method_180()));
    }
    jrt::Ref<class_3> var1 = jrt::New<class_3>();
    jrt::Ref<class_3> var2 = jrt::New<class_3>(var1);
    this->field_294 = 0;
    for (int32_t var3 = 1; var3 <= 2; var3++) {
        if (class_21::method_180() != nullptr) {
            if (var3 == 0) {
                this->field_294 = class_21::method_180()->field_1133->length() + (class_21::method_180()->field_1139 * 3);
                this->field_294 = (this->field_294 % 16) * 256;
            } else {
                this->field_294 = this->field_294 + ((class_21::method_180()->field_1139 > 4) ? 300 : (-300));
            }
            var1->field_39 = (var3 == 1) ? 90000 : 110000;
            var1->field_39 = var1->field_39 + (this->field_294 * 3);
            jrt::Ref<class_57> var4{};
            (var4 = jrt::New<class_57>())->method_490(this->field_294);
            (var2 = var4->method_508(var1, var2))->field_38 = 0;
        }
        this->field_276->at(var3) = jrt::Ref<class_91>(([&]() { int32_t __a1 = 15; jrt::Ref<class_108> __a2 = class_43::method_381(15); int32_t __a3 = var2->field_37; int32_t __a4 = var2->field_38; int32_t __a5 = var2->field_39; jrt::Ref<class_99> __o(new class_99()); __o->__init(__a1, __a2, __a3, __a4, __a5); return __o; }()));
        (jrt::cast<class_99>(this->field_276->at(var3)))->method_822((this->field_294 + 2048));
    }
    this->field_294 += 2048;
    if (!class_26::field_301) {
        this->field_294 = 0;
    } else {
        (jrt::cast<class_99>(this->field_276->at(2)))->method_823();
    }
    (jrt::cast<class_99>(this->field_276->at(1)))->method_821();
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> var8 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(255), int16_t(255), int16_t(128)}), jrt::arrayOf<int16_t>({int16_t(98), int16_t(118), int16_t(255)}), jrt::arrayOf<int16_t>({int16_t(234), int16_t(149), int16_t(55)}), jrt::arrayOf<int16_t>({int16_t(239), int16_t(90), int16_t(95)}), jrt::arrayOf<int16_t>({int16_t(154), int16_t(220), int16_t(109)})});
    jrt::Ref<jrt::Array<int8_t>> var9 = class_38::method_363(class_21::method_180());
    for (int32_t var5 = 0; var5 < var9->length; var5 += 2) {
        if ((int32_t(var9->at(var5)) > 12) && (int32_t(var9->at(var5)) < 18)) {
            float var6 = (float(var9->at((var5 + 1))) / 100.0f) * 1.5f;
            this->field_295 = var6 * float(var8->at((int32_t(var9->at(var5)) - 13))->at(0));
            this->field_296 = var6 * float(var8->at((int32_t(var9->at(var5)) - 13))->at(1));
            this->field_297 = var6 * float(var8->at((int32_t(var9->at(var5)) - 13))->at(2));
            float var7 = class_21::method_180()->method_744();
            this->field_298 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_295 * var7)))));
            this->field_299 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_296 * var7)))));
            this->field_300 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_297 * var7)))));
            return;
        }
    }
}

void class_26::method_242() {
    if (class_21::method_132()->method_754() || ((class_21::method_132()->field_1146 != 6) && ((!class_21::method_132()->field_1161) || (class_21::method_132()->field_1146 != 6)))) {
        int32_t var1 = 0;
        int32_t var2 = 0;
        bool var3 = false;
        this->field_275 = jrt::newArray<jrt::Ref<class_91>>((class_21::method_147() ? 49 : 20));
        jrt::Ref<jrt::Array<int8_t>> var4 = class_38::method_363(class_21::method_180());
        for (int32_t var5 = 0; var5 < this->field_275->length; var5++) {
            if (class_21::method_147()) {
                var1 = 13 + (var5 / 10);
            } else {
                var3 = false;
                while (!var3) {
                    if (class_84::field_1123->nextInt(100) < int32_t(var4->at((var2 + 1)))) {
                        var1 = int32_t(var4->at(var2));
                        var3 = true;
                        var2 += 2;
                        if (var2 >= var4->length) {
                            var2 = 0;
                        }
                    } else {
                        var2 = 0;
                    }
                }
            }
            this->field_275->at(var5) = jrt::Ref<class_91>(this->method_243(var1, jrt::Ref<class_97>(nullptr)));
        }
    }
}

jrt::Ref<class_101> class_26::method_243(int32_t var1, jrt::Ref<class_97> var2) {
    int16_t var3 = class_90::field_1202->at(var1);
    int32_t var4 = 0;
    int32_t var5 = 0;
    int32_t var6 = 0;
    if (var2 != nullptr) {
        var4 = var2->field_1295;
        var5 = var2->field_1296;
        var6 = var2->field_1297 - 20000;
    }
    jrt::Ref<class_101> var7{};
    (var7 = jrt::New<class_101>(int32_t(var3), class_43::method_381(int32_t(var3)), class_90::method_787()->at(var1), var4, var5, var6))->field_1229 = jrt::Ref<class_26>(this);
    var7->field_1226->field_1367 = 2;
    jrt::Ref<class_85> var8 = jrt::New<class_85>(1, 2);
    var7->field_1231 = var8;
    return var7;
}

void class_26::method_244() {
    {
        try {
            jrt::Ref<class_108> var2{};
            (var2 = class_43::method_381(int32_t(class_90::field_1205->at(class_21::method_178()->field_863))))->field_1367 = 2;
            jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var3 = class_21::method_178()->field_885;
            int32_t var4 = 0;
            int32_t var5 = 0;
            int32_t var6 = 0;
            jrt::Ref<jrt::Array<jrt::Ref<class_9>>> var7 = jrt::Ref<jrt::Array<jrt::Ref<class_9>>>(nullptr);
            jrt::Ref<class_9> var8 = jrt::Ref<class_9>(nullptr);
            if (var3 != nullptr) {
                for (int32_t var9 = 0; var9 < var3->length; var9++) {
                    if (var3->at(var9) != nullptr) {
                        {
                            switch ((var3->at(var9)->field_165)) {
                            case 0:
                                ;
                            case 1:
                                var5++;
                                break;
                            case 2:
                                var6++;
                            }
                        }
                    }
                }
            }
            if (var6 > 0) {
                var4++;
            }
            if (var5 > 0) {
                var4++;
                var7 = jrt::newArray<jrt::Ref<class_9>>(var5);
            }
            jrt::Ref<class_37> var15{};
            (var15 = jrt::New<class_37>(1200.0f, class_21::method_178()->field_864, var4))->method_331(class_21::method_178()->field_871);
            var15->method_332(class_21::method_178()->field_872);
            this->field_272 = jrt::New<class_70>(var15);
            this->field_272->field_981 = jrt::Ref<class_26>(this);
            this->field_272->method_648(var2);
            this->field_272->field_970->method_864(0, this->field_294, 0);
            jrt::Ref<jrt::Array<int32_t>> var10 = jrt::arrayOf<int32_t>({0, 0, 0});
            jrt::Ref<class_85> var11 = jrt::New<class_85>((var10->length / 3), 0);
            this->field_272->field_979 = var11;
            if (var3 != nullptr) {
                for (int32_t var12 = 0; var12 < var3->length; var12++) {
                    if (var3->at(var12) != nullptr) {
                        jrt::Ref<class_9> var13 = jrt::Ref<class_9>(nullptr);
                        if (var3->at(var12)->method_118()) {
                            (var13 = this->method_245(var3->at(var12)->field_166, var3->at(var12)->field_171, var3->at(var12)->field_172, var3->at(var12)->field_173, var3->at(var12)->field_174))->field_100 = var3->at(var12)->field_165;
                            {
                                switch ((var3->at(var12)->field_165)) {
                                case 0:
                                    ;
                                case 1:
                                    var13->method_42((var5 - 1), var7->length);
                                    var7->at(((var5--) - 1)) = var13;
                                    break;
                                case 2:
                                    var8 = var13;
                                }
                            }
                        }
                    }
                }
            }
            int32_t var16 = 0;
            if (var7 != nullptr) {
                var16++;
                this->field_272->method_658(var7, 0);
            }
            if (var8 != nullptr) {
                this->field_272->method_657(var8, var16);
            }
            class_21::method_178()->method_619();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var14 = jrt::cast<java::lang::Exception>(__ex1.t);
                var14->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<class_9> class_26::method_245(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    jrt::Ref<class_9> var6 = jrt::Ref<class_9>(nullptr);
    jrt::Ref<class_108> var7 = jrt::Ref<class_108>(nullptr);
    jrt::Ref<java::lang::Object> var8 = jrt::Ref<java::lang::Object>(nullptr);
    jrt::Ref<class_116> var9 = this->field_266;
    {
        switch (var1) {
        case 0:
            ;
        case 1:
            ;
        case 2:
            ;
        case 6:
            ;
        case 7:
            ;
        case 8:
            ;
        case 9:
            ;
        case 10:
            ;
        case 11:
            ;
        case 42:
            var6 = [&]() { int32_t __a1 = var2; int32_t __a2 = 10; int32_t __a3 = (-1); int32_t __a4 = var4; int32_t __a5 = var3; float __a6 = float(var5); jrt::Ref<class_3> __a7 = jrt::New<class_3>(0, 0, 200); jrt::Ref<class_3> __a8 = jrt::New<class_3>(); jrt::Ref<class_9> __o(new class_9()); __o->__init(__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8); return __o; }();
            var8 = jrt::Ref<java::lang::Object>(jrt::New<class_112>(var6, class_43::method_381(int32_t(((var1 == 42) ? int16_t(6766) : class_90::field_1201->at(var1)))), 1000));
            break;
        case 3:
            ;
        case 4:
            ;
        case 5:
            var6 = [&]() { int32_t __a9 = var2; int32_t __a10 = 1; int32_t __a11 = (-1); int32_t __a12 = var4; int32_t __a13 = var3; float __a14 = float(var5); jrt::Ref<class_3> __a15 = jrt::New<class_3>(0, 0, 2200); jrt::Ref<class_3> __a16 = jrt::New<class_3>(); jrt::Ref<class_9> __o(new class_9()); __o->__init(__a9, __a10, __a11, __a12, __a13, __a14, __a15, __a16); return __o; }();
            (var7 = class_108::method_890(0, 128, 64, 0, 96, 32, 300, 1, int8_t(2)))->method_893(class_43::method_380(2));
            (jrt::cast<class_110>(var7))->field_1390 = jrt::arrayOf<int32_t>({(-16711936)});
            var7->field_1367 = 2;
            var8 = jrt::Ref<java::lang::Object>(jrt::New<class_115>(var6, var7, this->field_272->field_970, (var1 - 3)));
            break;
        case 12:
            ;
        case 13:
            ;
        case 14:
            var6 = [&]() { int32_t __a17 = var2; int32_t __a18 = 1; int32_t __a19 = (-1); int32_t __a20 = var4; int32_t __a21 = var3; float __a22 = float(var5); jrt::Ref<class_3> __a23 = jrt::New<class_3>(); jrt::Ref<class_3> __a24 = jrt::New<class_3>(); jrt::Ref<class_9> __o(new class_9()); __o->__init(__a17, __a18, __a19, __a20, __a21, __a22, __a23, __a24); return __o; }();
            (var7 = class_43::method_381(16))->field_1367 = 2;
            var8 = jrt::Ref<java::lang::Object>(jrt::New<class_113>(var6, var7, (-16711936), true));
            var9 = this->field_268;
            break;
        case 15:
            ;
        case 16:
            ;
        case 17:
            var6 = [&]() { int32_t __a25 = 0; int32_t __a26 = 1; int32_t __a27 = (-1); int32_t __a28 = var4; int32_t __a29 = var4; float __a30 = float(var5); jrt::Ref<class_3> __a31 = jrt::New<class_3>(); jrt::Ref<class_3> __a32 = jrt::New<class_3>(); jrt::Ref<class_9> __o(new class_9()); __o->__init(__a25, __a26, __a27, __a28, __a29, __a30, __a31, __a32); return __o; }();
            (var7 = class_108::method_890(0, 128, 64, 0, 96, 32, 500, 1, int8_t(2)))->method_893(class_43::method_380(2));
            (jrt::cast<class_110>(var7))->field_1390 = jrt::arrayOf<int32_t>({(-16711936)});
            var7->field_1367 = 2;
            var8 = jrt::Ref<java::lang::Object>(jrt::New<class_114>(var6, var7, this->field_272->field_970, var2, (var1 - 15), var3));
            var9 = this->field_267;
        case 18:
            ;
        case 19:
            ;
        case 20:
            ;
        case 21:
            ;
        case 22:
            ;
        case 23:
            ;
        case 24:
            ;
        case 25:
            ;
        case 26:
            ;
        case 27:
            ;
        case 28:
            ;
        case 29:
            ;
        case 30:
            ;
        case 31:
            ;
        case 32:
            ;
        case 33:
            ;
        case 34:
            ;
        case 35:
            ;
        case 36:
            ;
        case 37:
            ;
        case 38:
            ;
        case 39:
            ;
        case 40:
            ;
        case 41:
            ;
        }
    }
    var6->field_76 = jrt::Ref<class_26>(this);
    if (((var1 != 15) && (var1 != 16)) && (var1 != 17)) {
        var6->method_44(var9);
    }
    if (this->field_269 == nullptr) {
        this->field_269 = jrt::arrayOf<jrt::Ref<class_108>>({jrt::cast<class_108>(var8)});
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_108>>> var10 = jrt::newArray<jrt::Ref<class_108>>((this->field_269->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_269), 0, jrt::Ref<java::lang::Object>(var10), 0, this->field_269->length);
        var10->at((var10->length - 1)) = jrt::cast<class_108>(var8);
        this->field_269 = var10;
    }
    return var6;
}

void class_26::method_246() {
    bool var1 = false;
    this->field_274 = jrt::newArray<jrt::Ref<class_91>>(1);
    [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(0); __l = this->method_254(1, 0, 5, false, jrt::Ref<class_97>(nullptr)); return __l; }();
    if (class_26::field_301 && (this->field_272->field_970 != nullptr)) {
        (jrt::cast<class_96>(this->field_274->at(0)))->method_818((this->field_276->at(2)->field_1226->method_852() - 3000), (this->field_276->at(2)->field_1226->method_853() + 1000), (this->field_276->at(2)->field_1226->method_854() + 5000));
    } else {
        [&]() { auto __r = (jrt::cast<class_96>(this->field_274->at(0))); int32_t __a1 = ((this->field_272->field_970->method_852() + (-700)) + class_84::field_1123->nextInt(1400)); int32_t __a2 = ((this->field_272->field_970->method_853() + (-700)) + class_84::field_1123->nextInt(1400)); int32_t __a3 = (this->field_272->field_970->method_854() + 2000); return __r->method_818(__a1, __a2, __a3); }();
    }
    if (this->field_277 != nullptr) {
        this->field_274->at(0)->field_1230 = this->field_277->method_115();
    }
    this->field_274->at(0)->field_1225->method_327(9999999);
}

void class_26::method_247() {
    jrt::Ref<class_87> var1 = class_21::method_132();
    bool var2 = false;
    bool var3 = false;
    if (var1 != nullptr) {
        if (var1->method_754()) {
            this->field_262 = 0;
            this->method_249();
            this->field_262 = 3;
            int32_t var28{};
            if (((class_21::method_143() > 11) && (class_84::field_1123->nextInt(100) < (25 + class_21::method_143()))) && ((var28 = 0 + class_84::field_1123->nextInt(4)) > 0)) {
                this->field_273 = jrt::newArray<jrt::Ref<class_91>>(var28);
                jrt::Ref<class_18> var30 = jrt::New<class_18>(jrt::arrayOf<int32_t>({0, 0, 15000}));
                for (int32_t var32 = 0; var32 < this->field_273->length; var32++) {
                    [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var32); __l = this->method_254(2, 0, class_90::method_791(), true, var30->method_109(0)); return __l; }();
                }
            }
        } else {
            {
                int32_t var34{};
                int32_t var26{};
                int32_t var10{};
                int32_t var35{};
                int32_t var12{};
                bool var14{};
                bool var15{};
                int32_t var16{};
                int32_t var17{};
                int32_t var11{};
                jrt::Ref<class_18> var31{};
                int32_t var7{};
                int32_t var8{};
                jrt::Ref<class_18> var5{};
                switch (var1->field_1146) {
                case 0:
                    this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({([&]() { int32_t __l1 = (40000 + class_84::field_1123->nextInt(80000)); int32_t __r1 = ((class_84::field_1123->nextInt(2) == 0) ? 1 : (-1)); return (__l1 * __r1); }()), 0, ([&]() { int32_t __l2 = (40000 + class_84::field_1123->nextInt(80000)); int32_t __r2 = ((class_84::field_1123->nextInt(2) == 0) ? 1 : (-1)); return (__l2 * __r2); }())}));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>(1);
                    [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(0); __l = this->method_254(2, 0, class_90::method_791(), true, this->field_277->method_109(0)); return __l; }();
                    this->field_273->at(0)->method_803();
                    var34 = (class_21::method_132()->field_1154 * class_21::method_210());
                    this->field_273->at(0)->field_1225->method_330((300 + var34));
                    this->field_289 = jrt::New<class_22>(1, 0, jrt::Ref<class_26>(this));
                    return;
                case 1:
                    ;
                case 2:
                    this->field_277 = this->method_255((2 + class_84::field_1123->nextInt(2)));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((3 + jrt::f2i((3.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    for (int32_t var27 = 0; var27 < this->field_273->length; var27++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var27); __l = ([&]() { int32_t __a3 = 2; int32_t __a4 = 0; int32_t __a5 = class_90::method_791(); bool __a6 = true; jrt::Ref<class_97> __a7 = ((var27 == (this->field_273->length - 1)) ? this->field_277->method_109((this->field_277->method_113() - 1)) : this->field_277->method_109(class_84::field_1123->nextInt(this->field_277->method_113()))); return this->method_254(__a3, __a4, __a5, __a6, __a7); }()); return __l; }();
                        this->field_273->at(var27)->method_803();
                    }
                    (jrt::cast<class_96>(this->field_273->at((this->field_273->length - 1))))->method_814(true);
                    this->field_289 = jrt::New<class_22>(11, (this->field_273->length - 1), jrt::Ref<class_26>(this));
                    this->field_290 = jrt::New<class_22>(12, (this->field_273->length - 1), jrt::Ref<class_26>(this));
                    return;
                case 3:
                    this->field_277 = this->method_255((2 + class_84::field_1123->nextInt(2)));
                    var26 = (3 + jrt::f2i((3.0f * (float(class_21::method_132()->method_764()) / 10.0f))));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>(var26);
                    for (int32_t var29 = 0; var29 < this->field_273->length; var29++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var29); __l = ([&]() { int32_t __a8 = 2; int32_t __a9 = 0; int32_t __a10 = class_90::method_791(); bool __a11 = true; jrt::Ref<class_97> __a12 = this->field_277->method_109(class_84::field_1123->nextInt(this->field_277->method_113())); return this->method_254(__a8, __a9, __a10, __a11, __a12); }()); return __l; }();
                        this->field_273->at(var29)->method_803();
                    }
                    this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
                    return;
                case 4:
                    this->field_279 = jrt::New<class_18>(jrt::arrayOf<int32_t>({10000, 0, 100000, 10000, 0, 150000, 10000, 0, 200000}));
                    var10 = (2 + jrt::f2i((4.0f * (float(class_21::method_132()->method_764()) / 10.0f))));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>(var10);
                    var35 = ((var1->field_1149 == 0) ? 1 : 0);
                    var12 = var1->field_1149;
                    for (int32_t var13 = 0; var13 < this->field_273->length; var13++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var13); __l = ([&]() { int32_t __a13 = var35; int32_t __a14 = 0; int32_t __a15 = class_90::method_791(); bool __a16 = true; jrt::Ref<class_97> __a17 = this->field_279->method_109(class_84::field_1123->nextInt(this->field_279->method_113())); return this->method_254(__a13, __a14, __a15, __a16, __a17); }()); return __l; }();
                        this->field_273->at(var13)->method_803();
                    }
                    this->field_274 = jrt::newArray<jrt::Ref<class_91>>(5);
                    for (int32_t var36 = 0; var36 < this->field_274->length; var36++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var36); __l = this->method_254(var12, 3, 11, false, jrt::Ref<class_97>(nullptr)); return __l; }();
                        this->field_274->at(var36)->field_1225->method_330(((100 + (class_21::method_210() * 2)) + (class_21::method_143() * 2)));
                        (jrt::cast<class_95>(this->field_274->at(var36)))->field_1255 = true;
                    }
                    var14 = false;
                    var15 = false;
                    (jrt::cast<class_95>(this->field_274->at(0)))->method_812(5500, (-300), 20000);
                    (jrt::cast<class_95>(this->field_274->at(1)))->method_812(14500, 3000, 17000);
                    (jrt::cast<class_95>(this->field_274->at(2)))->method_812(4000, (-2000), 12000);
                    (jrt::cast<class_95>(this->field_274->at(3)))->method_812(17000, (-6000), 10000);
                    (jrt::cast<class_95>(this->field_274->at(4)))->method_812(11000, 7000, 8000);
                    this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
                    this->field_290 = jrt::New<class_22>(5, 0, jrt::Ref<class_26>(this));
                    return;
                case 5:
                    this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({((-2500) + class_84::field_1123->nextInt(5000)), ((-2500) + class_84::field_1123->nextInt(5000)), (80000 + class_84::field_1123->nextInt(30000)), ((-2500) + class_84::field_1123->nextInt(5000)), ((-2500) + class_84::field_1123->nextInt(5000)), (120000 + class_84::field_1123->nextInt(30000))}));
                    var16 = (2 + class_84::field_1123->nextInt(2));
                    var17 = (2 + jrt::f2i((2.0f * (float(class_21::method_132()->method_764()) / 10.0f))));
                    var11 = ((var1->field_1149 == 0) ? 1 : 0);
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((var16 + var17));
                    for (int32_t var18 = 0; var18 < var16; var18++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var18); __l = this->method_254(var11, 3, 11, true, this->field_277->method_109(1)); return __l; }();
                        this->field_273->at(var18)->method_803();
                        (jrt::cast<class_95>(this->field_273->at(var18)))->field_1255 = false;
                        [&]() { auto __r = (jrt::cast<class_95>(this->field_273->at(var18))); int32_t __a18 = ((this->field_277->method_109(1)->field_1295 + (-10000)) + class_84::field_1123->nextInt(20000)); int32_t __a19 = ((this->field_277->method_109(1)->field_1296 + (-10000)) + class_84::field_1123->nextInt(20000)); int32_t __a20 = ((this->field_277->method_109(1)->field_1297 + (-10000)) + class_84::field_1123->nextInt(20000)); return __r->method_812(__a18, __a19, __a20); }();
                    }
                    for (int32_t var37 = var16; var37 < this->field_273->length; var37++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var37); __l = ([&]() { int32_t __a21 = var11; int32_t __a22 = 0; int32_t __a23 = class_90::method_791(); bool __a24 = true; jrt::Ref<class_97> __a25 = this->field_277->method_109(class_84::field_1123->nextInt(this->field_277->method_113())); return this->method_254(__a21, __a22, __a23, __a24, __a25); }()); return __l; }();
                        this->field_273->at(var37)->method_803();
                    }
                    this->field_289 = jrt::New<class_22>(7, var16, jrt::Ref<class_26>(this));
                default:
                    return;
                case 6:
                    this->field_278 = jrt::New<class_18>(jrt::arrayOf<int32_t>({20000, 0, (-40000), 20000, 0, 40000, 20000, 0, 90000}));
                    this->field_275 = jrt::newArray<jrt::Ref<class_91>>(var1->field_1167);
                    for (int32_t var24 = 0; var24 < this->field_275->length; var24++) {
                        this->field_275->at(var24) = jrt::Ref<class_91>(this->method_243(var1->field_1166, this->field_278->method_109(0)));
                        (jrt::cast<class_101>(this->field_275->at(var24)))->method_829(true);
                        this->field_275->at(var24)->field_1225->method_327((this->field_275->at(var24)->field_1225->field_363 * 2));
                    }
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((2 + jrt::f2i((4.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    for (int32_t var25 = 0; var25 < this->field_273->length; var25++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var25); __l = ([&]() { int32_t __a26 = 0; int32_t __a27 = 0; int32_t __a28 = class_90::method_791(); bool __a29 = true; jrt::Ref<class_97> __a30 = this->field_278->method_109((1 + class_84::field_1123->nextInt((this->field_278->method_113() - 1)))); return this->method_254(__a26, __a27, __a28, __a29, __a30); }()); return __l; }();
                        this->field_273->at(var25)->method_803();
                    }
                    this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
                    this->field_290 = jrt::New<class_22>(8, (var1->field_1167 - var1->field_1168), jrt::Ref<class_26>(this));
                    return;
                case 7:
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((0 + jrt::f2i((3.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    if (this->field_273->length > 0) {
                        for (int32_t var22 = 0; var22 < this->field_273->length; var22++) {
                            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var22); __l = this->method_254(1, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
                        }
                    } else {
                        this->field_273 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
                    }
                    for (int32_t var23 = 0; (var23 < (var1->field_1167 + 3)) && (var23 < this->field_275->length); var23++) {
                        this->field_275->at(var23) = jrt::Ref<class_91>(this->method_243(var1->field_1166, jrt::Ref<class_97>(nullptr)));
                    }
                    this->field_289 = jrt::New<class_22>(13, var1->field_1166, var1->field_1167, jrt::Ref<class_26>(this));
                    return;
                case 8:
                    return;
                case 9:
                    var31 = jrt::New<class_18>(jrt::arrayOf<int32_t>({((-20000) + class_84::field_1123->nextInt(40000)), 0, (20000 + class_84::field_1123->nextInt(40000))}));
                    var7 = jrt::f2i((2.0f * (float(class_21::method_132()->method_764()) / 10.0f)));
                    var8 = (15 + jrt::f2i((15.0f * (float(class_21::method_132()->method_764()) / 10.0f))));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((var8 + var7));
                    for (int32_t var9 = 0; var9 < (this->field_273->length - var7); var9++) {
                        this->field_273->at(var9) = this->method_253(var31->method_109(0), 9996);
                    }
                    for (int32_t var33 = this->field_273->length - var7; var33 < this->field_273->length; var33++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var33); __l = this->method_254(2, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
                    }
                    this->field_289 = jrt::New<class_22>(7, (this->field_273->length - var7), jrt::Ref<class_26>(this));
                    this->field_291 = 151000;
                    return;
                case 10:
                    var5 = jrt::New<class_18>(jrt::arrayOf<int32_t>({((-20000) + class_84::field_1123->nextInt(40000)), 0, (20000 + class_84::field_1123->nextInt(40000))}));
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>(((class_84::field_1123->nextInt(11) + 15) + 1));
                    for (int32_t var6 = 0; var6 < (this->field_273->length - 1); var6++) {
                        this->field_273->at(var6) = this->method_253(var5->method_110(), 13);
                    }
                    [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at((this->field_273->length - 1)); __l = this->method_254(2, 0, 1, true, var5->method_109(0)); return __l; }();
                    this->field_289 = jrt::New<class_22>(7, (this->field_273->length - 1), jrt::Ref<class_26>(this));
                    return;
                case 11:
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>((2 + jrt::f2i((4.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    for (int32_t var20 = 0; var20 < this->field_273->length; var20++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var20); __l = this->method_254(3, 0, 19, true, jrt::Ref<class_97>(nullptr)); return __l; }();
                    }
                    this->field_274 = jrt::newArray<jrt::Ref<class_91>>(class_21::method_132()->field_1167);
                    for (int32_t var21 = 0; var21 < this->field_274->length; var21++) {
                        [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var21); __l = this->method_254(3, 7, 9994, false, jrt::Ref<class_97>(nullptr)); return __l; }();
                    }
                    this->field_290 = jrt::New<class_22>(14, class_21::method_132()->field_1168, jrt::Ref<class_26>(this));
                    this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
                    return;
                case 12:
                    this->field_273 = jrt::newArray<jrt::Ref<class_91>>(((class_21::method_132()->field_1167 + 2) + jrt::f2i((4.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    for (int32_t var4 = 0; var4 < this->field_273->length; var4++) {
                        if (var4 < class_21::method_132()->field_1167) {
                            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var4); __l = this->method_254(3, 7, 9994, true, jrt::Ref<class_97>(nullptr)); return __l; }();
                        } else {
                            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var4); __l = this->method_254(0, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
                        }
                    }
                    this->field_274 = jrt::newArray<jrt::Ref<class_91>>((0 + jrt::f2i((3.0f * (float(class_21::method_132()->method_764()) / 10.0f)))));
                    if (this->field_274->length > 0) {
                        for (int32_t var19 = 0; var19 < this->field_274->length; var19++) {
                            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var19); __l = this->method_254(3, 0, 19, false, jrt::Ref<class_97>(nullptr)); return __l; }();
                        }
                    }
                    this->field_289 = jrt::New<class_22>(7, class_21::method_132()->field_1167, jrt::Ref<class_26>(this));
                }
            }
        }
    }
}

void class_26::method_248() {
    jrt::Ref<class_87> var4 = class_21::method_132();
    {
        jrt::Ref<class_3> var13{};
        jrt::Ref<class_3> var21{};
        jrt::Ref<class_18> var7{};
        bool var8{};
        jrt::Ref<class_18> var9{};
        bool var10{};
        int32_t var11{};
        bool var1{};
        bool var2{};
        bool var3{};
        jrt::Ref<class_3> var5{};
        jrt::Ref<class_3> var6{};
        switch (class_21::method_143()) {
        case 5:
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(1);
            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(0); __l = this->method_254(2, 0, 1, true, jrt::Ref<class_97>(nullptr)); return __l; }();
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
        case 6:
            ;
        case 8:
            ;
        case 9:
            ;
        case 11:
            ;
        case 12:
            ;
        case 13:
            ;
        case 14:
            ;
        case 15:
            ;
        case 16:
            ;
        case 17:
            ;
        case 18:
            ;
        case 20:
            ;
        case 22:
            ;
        case 24:
            ;
        case 26:
            ;
        case 28:
            ;
        case 30:
            ;
        case 32:
            ;
        case 33:
            ;
        case 34:
            ;
        case 36:
            ;
        case 37:
            ;
        case 38:
            ;
        case 39:
            ;
        case 40:
            ;
        case 41:
            ;
        case 44:
            ;
        case 46:
            ;
        default:
            break;
        case 7:
            for (int32_t var19 = 0; var19 < var4->field_1167; var19++) {
                this->field_275->at(var19) = jrt::Ref<class_91>(this->method_243(var4->field_1166, jrt::Ref<class_97>(nullptr)));
            }
            this->field_289 = jrt::New<class_22>(13, var4->field_1166, var4->field_1167, jrt::Ref<class_26>(this));
            break;
        case 10:
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(4);
            for (int32_t var17 = 0; var17 < this->field_273->length; var17++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var17); __l = this->method_254(3, 0, 19, true, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(class_21::method_132()->field_1167);
            for (int32_t var18 = 0; var18 < this->field_274->length; var18++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var18); __l = this->method_254(3, 7, 9994, false, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            this->field_290 = jrt::New<class_22>(14, class_21::method_132()->field_1168, jrt::Ref<class_26>(this));
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 19:
            this->field_278 = jrt::New<class_18>(jrt::arrayOf<int32_t>({(-20000), 0, (-40000), (-20000), 0, 30000, (-20000), 0, 100000, (-20000), 0, 130000}));
            this->field_275 = jrt::newArray<jrt::Ref<class_91>>(var4->field_1167);
            for (int32_t var14 = 0; var14 < this->field_275->length; var14++) {
                this->field_275->at(var14) = jrt::Ref<class_91>(this->method_243(var4->field_1166, this->field_278->method_109(1)));
                (jrt::cast<class_101>(this->field_275->at(var14)))->method_829(true);
                this->field_275->at(var14)->field_1225->method_327((this->field_275->at(var14)->field_1225->field_363 * 2));
            }
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(3);
            for (int32_t var15 = 0; var15 < this->field_273->length; var15++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var15); __l = this->method_254(0, 0, class_90::method_791(), true, this->field_278->method_109(((var15 == 0) ? 2 : 3))); return __l; }();
                this->field_273->at(var15)->method_803();
            }
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(3);
            for (int32_t var16 = 0; var16 < this->field_274->length; var16++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var16); __l = this->method_254(0, 0, 19, false, this->field_278->method_109(0)); return __l; }();
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            this->field_290 = jrt::New<class_22>(8, (var4->field_1167 - var4->field_1168), jrt::Ref<class_26>(this));
            break;
        case 21:
            this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({0, 0, 200000}));
            this->method_246();
            this->field_274->at(0)->field_1226->method_846(this->field_272->method_664());
            var13 = jrt::New<class_3>();
            var21 = jrt::New<class_3>();
            var13->method_9(this->field_276->at(0)->method_799(var13));
            var21 = this->field_276->at(2)->method_799(var21);
            var13->method_17(var21);
            var13->method_20(12288);
            var21->method_15(var13);
            this->field_274->at(0)->field_1226->method_846(var21);
            this->field_274->at(0)->field_1226->method_843(0, 0, (-10000));
            this->field_274->at(0)->method_803();
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(3);
            for (int32_t var23 = 0; var23 < this->field_273->length; var23++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var23); __l = this->method_254(2, 0, class_90::method_791(), true, this->field_277->method_109(0)); return __l; }();
                this->field_273->at(var23)->method_803();
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 23:
            var7 = jrt::New<class_18>(jrt::arrayOf<int32_t>({80000, 0, 120000}));
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(20);
            var8 = false;
            for (int32_t var24 = 0; var24 < (this->field_273->length - 2); var24++) {
                this->field_273->at(var24) = this->method_253(var7->method_110(), 13);
            }
            for (int32_t var25 = (this->field_273->length - 2) - 1; var25 < this->field_273->length; var25++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var25); __l = this->method_254(2, 0, class_90::method_791(), true, var7->method_109(0)); return __l; }();
            }
            this->field_289 = jrt::New<class_22>(7, (this->field_273->length - 2), jrt::Ref<class_26>(this));
            break;
        case 25:
            var9 = jrt::New<class_18>(jrt::arrayOf<int32_t>({(-200000), 0, (-200000)}));
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(3);
            for (int32_t var26 = 0; var26 < this->field_274->length; var26++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var26); __l = this->method_254(1, 0, ((var26 == 0) ? 5 : 2), false, jrt::Ref<class_97>(nullptr)); return __l; }();
                this->field_274->at(var26)->field_1226->method_846(this->field_272->method_664());
                this->field_274->at(var26)->field_1226->method_870(this->field_272->field_970->field_1341);
                this->field_274->at(var26)->field_1226->method_843(((var26 == 0) ? 800 : ((var26 == 1) ? (-1000) : (-30))), ((var26 == 0) ? 340 : ((var26 == 1) ? (-130) : (-300))), ((var26 == 0) ? 700 : ((var26 == 1) ? (-500) : (-100))));
                this->field_274->at(var26)->field_1225->method_330(32000);
            }
            this->field_274->at(0)->field_1230 = var9;
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(6);
            for (int32_t var27 = 0; var27 < this->field_273->length; var27++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var27); __l = this->method_254(0, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
                this->field_273->at(var27)->field_1226->method_870(this->field_272->field_970->field_1341);
                this->field_273->at(var27)->field_1226->method_845(((-40000) + (var27 * 2000)), ((-6000) + (var27 * 2000)), (10000 + (var27 * 2000)));
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 27:
            this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({120000, 0, 130000}));
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(1);
            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(0); __l = this->method_254(1, 0, 5, true, this->field_277->method_109(0)); return __l; }();
            this->field_273->at(0)->method_803();
            this->field_273->at(0)->field_1225->method_330((this->field_273->at(0)->field_1225->field_364 * 5));
            this->field_273->at(0)->method_796(5);
            (jrt::cast<class_96>(this->field_273->at(0)))->method_814(true);
            this->field_289 = jrt::New<class_22>(11, 0, jrt::Ref<class_26>(this));
            this->field_290 = jrt::New<class_22>(12, 0, jrt::Ref<class_26>(this));
            break;
        case 29:
            this->field_279 = jrt::New<class_18>(jrt::arrayOf<int32_t>({(-30000), 0, 30000, (-30000), 0, 130000, (-30000), 0, 200000}));
            var10 = false;
            var11 = class_90::method_791();
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(5);
            for (int32_t var41 = 0; var41 < this->field_273->length; var41++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var41); __l = this->method_254(0, 0, var11, true, this->field_279->method_109(((var41 < 2) ? 0 : ((var41 < 3) ? 1 : 2)))); return __l; }();
                this->field_273->at(var41)->method_803();
            }
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(5);
            for (int32_t var42 = 0; var42 < this->field_274->length; var42++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var42); __l = this->method_254(1, 3, 11, false, jrt::Ref<class_97>(nullptr)); return __l; }();
                this->field_274->at(var42)->field_1225->method_330(((100 + (class_21::method_210() * 5)) + 50));
                (jrt::cast<class_95>(this->field_274->at(var42)))->field_1255 = true;
                this->field_274->at(var42)->method_804();
            }
            var1 = false;
            var2 = false;
            var3 = false;
            (jrt::cast<class_95>(this->field_274->at(0)))->method_812((-37500), (-1300), 20000);
            (jrt::cast<class_95>(this->field_274->at(1)))->method_812((-22500), 4000, 17000);
            (jrt::cast<class_95>(this->field_274->at(2)))->method_812((-31000), (-3000), 13000);
            (jrt::cast<class_95>(this->field_274->at(3)))->method_812((-20000), (-7000), 10000);
            (jrt::cast<class_95>(this->field_274->at(4)))->method_812((-29000), 8000, 8000);
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            this->field_290 = jrt::New<class_22>(5, 0, jrt::Ref<class_26>(this));
            break;
        case 31:
            this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({(-160000), 0, 30000}));
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(4);
            for (int32_t var39 = 0; var39 < this->field_273->length; var39++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var39); __l = this->method_254(0, 0, class_90::method_791(), true, this->field_277->method_109(0)); return __l; }();
                this->field_273->at(var39)->method_803();
                (jrt::cast<class_96>(this->field_273->at(var39)))->method_814(true);
            }
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(2);
            for (int32_t var40 = 0; var40 < this->field_274->length; var40++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var40); __l = this->method_254(1, 0, class_90::method_791(), false, jrt::Ref<class_97>(nullptr)); return __l; }();
                this->field_274->at(var40)->field_1226->method_846(this->field_272->method_664());
                this->field_274->at(var40)->field_1226->method_870(this->field_272->field_970->field_1341);
                this->field_274->at(var40)->field_1226->method_843(((var40 == 0) ? 400 : (-300)), ((var40 == 0) ? 40 : (-30)), ((var40 == 0) ? 400 : (-300)));
                this->field_274->at(var40)->field_1230 = this->field_277->method_115();
                this->field_274->at(var40)->field_1225->method_330(32000);
            }
            this->field_289 = jrt::New<class_22>(16, 0, jrt::Ref<class_26>(this));
            this->field_290 = jrt::New<class_22>(17, 0, jrt::Ref<class_26>(this));
            break;
        case 35:
            this->field_277 = jrt::New<class_18>(jrt::arrayOf<int32_t>({20000, 0, 120000}));
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(3);
            for (int32_t var38 = 0; var38 < this->field_273->length; var38++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var38); __l = this->method_254(2, 0, ((var38 == 0) ? 10 : 0), true, this->field_277->method_109(0)); return __l; }();
                this->field_273->at(var38)->method_803();
            }
            this->field_273->at(0)->field_1225->method_330((this->field_273->at(0)->field_1225->field_364 * 5));
            this->field_273->at(0)->method_796(5);
            this->field_289 = jrt::New<class_22>(1, 0, jrt::Ref<class_26>(this));
            break;
        case 42:
            this->field_279 = jrt::New<class_18>(jrt::arrayOf<int32_t>({170000, 0, 0, 240000, 0, 0}));
            this->field_277 = this->field_279->method_115();
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(6);
            for (int32_t var37 = 0; var37 < this->field_273->length; var37++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var37); __l = this->method_254(2, 0, class_90::method_791(), true, this->field_279->method_109(((var37 < 3) ? 0 : 1))); return __l; }();
                this->field_273->at(var37)->method_803();
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 43:
            this->field_278 = jrt::New<class_18>(jrt::arrayOf<int32_t>({150000, 0, 0, 0, 0, 0}));
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(8);
            for (int32_t var34 = 0; var34 < this->field_273->length; var34++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var34); __l = this->method_254(0, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(7);
            for (int32_t var35 = 0; var35 < 2; var35++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var35); __l = this->method_254(1, 0, class_90::method_791(), false, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            for (int32_t var36 = 2; var36 < this->field_274->length; var36++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var36); __l = this->method_254(3, 0, 19, false, this->field_278->method_109(0)); return __l; }();
                this->field_274->at(var36)->method_803();
                this->field_274->at(var36)->field_1230 = this->field_278->method_115();
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 45:
            this->field_278 = jrt::New<class_18>(jrt::arrayOf<int32_t>({0, (-60000), 0, 0, 0, 0}));
            var5 = jrt::New<class_3>();
            var6 = jrt::New<class_3>();
            var5->method_9(this->field_276->at(0)->method_799(var5));
            var6 = this->field_276->at(2)->method_799(var6);
            var5->method_17(var6);
            var5->method_20(28672);
            var6->method_15(var5);
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(7);
            for (int32_t var30 = 0; var30 < 4; var30++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var30); __l = this->method_254(1, 0, class_90::method_791(), false, jrt::Ref<class_97>(nullptr)); return __l; }();
                if (var30 < 2) {
                    this->field_274->at(var30)->field_1225->method_327(32000);
                }
                this->field_274->at(var30)->field_1226->method_846(var6);
                [&]() { auto __r = this->field_274->at(var30)->field_1226; int32_t __a1 = ((-3000) + class_84::field_1123->nextInt(6000)); int32_t __a2 = ((-3000) + class_84::field_1123->nextInt(6000)); int32_t __a3 = ((-3000) + class_84::field_1123->nextInt(6000)); return __r->method_843(__a1, __a2, __a3); }();
                this->field_274->at(var30)->field_1226->method_867(this->field_272->field_970->method_865());
            }
            for (int32_t var31 = 4; var31 < this->field_274->length; var31++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var31); __l = this->method_254(3, 0, 19, false, this->field_278->method_109(0)); return __l; }();
                this->field_274->at(var31)->field_1230 = this->field_278->method_115();
            }
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(12);
            for (int32_t var32 = 0; var32 < 5; var32++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var32); __l = this->method_254(0, 3, 11, true, jrt::Ref<class_97>(nullptr)); return __l; }();
                (jrt::cast<class_95>(this->field_273->at(var32)))->field_1255 = false;
                [&]() { auto __r = (jrt::cast<class_95>(this->field_273->at(var32))); int32_t __a4 = (10000 + class_84::field_1123->nextInt(20000)); int32_t __a5 = ((-10000) + class_84::field_1123->nextInt(20000)); int32_t __a6 = (10000 + class_84::field_1123->nextInt(20000)); return __r->method_812(__a4, __a5, __a6); }();
                this->field_273->at(var32)->field_1225->method_327((this->field_273->at(var32)->field_1225->field_363 * 2));
            }
            for (int32_t var33 = 5; var33 < this->field_273->length; var33++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var33); __l = this->method_254(0, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
            break;
        case 47:
            this->field_274 = jrt::newArray<jrt::Ref<class_91>>(5);
            for (int32_t var12 = 0; var12 < this->field_274->length; var12++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var12); __l = this->method_254(1, 0, class_90::method_791(), false, jrt::Ref<class_97>(nullptr)); return __l; }();
                if (var12 < 2) {
                    this->field_274->at(var12)->field_1225->method_327(32000);
                }
            }
            this->field_273 = jrt::newArray<jrt::Ref<class_91>>(9);
            for (int32_t var28 = 0; var28 < 5; var28++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var28); __l = this->method_254(0, 3, 11, true, jrt::Ref<class_97>(nullptr)); return __l; }();
                (jrt::cast<class_95>(this->field_273->at(var28)))->field_1255 = false;
                [&]() { auto __r = (jrt::cast<class_95>(this->field_273->at(var28))); int32_t __a7 = (10000 + class_84::field_1123->nextInt(20000)); int32_t __a8 = ((-10000) + class_84::field_1123->nextInt(20000)); int32_t __a9 = (10000 + class_84::field_1123->nextInt(20000)); return __r->method_812(__a7, __a8, __a9); }();
            }
            for (int32_t var29 = 5; var29 < (this->field_273->length - 1); var29++) {
                [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at(var29); __l = this->method_254(0, 0, class_90::method_791(), true, jrt::Ref<class_97>(nullptr)); return __l; }();
            }
            [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_273->at((this->field_273->length - 1)); __l = this->method_254(0, 0, 7, true, jrt::Ref<class_97>(nullptr)); return __l; }();
            this->field_273->at((this->field_273->length - 1))->field_1225->method_327(32000);
            this->field_273->at((this->field_273->length - 1))->method_796(6);
            this->field_273->at((this->field_273->length - 1))->field_1239 = false;
            this->field_289 = jrt::New<class_22>(0, 0, jrt::Ref<class_26>(this));
        }
    }
    this->field_280 = this->method_256(class_21::method_143());
}

void class_26::method_249() {
    {
        jrt::Ref<class_98> var5{};
        jrt::Ref<class_98> var3{};
        jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var1{};
        switch (this->field_262) {
        case 0:
            var5 = jrt::cast<class_98>(this->field_276->at(1));
            var3 = jrt::cast<class_98>(this->field_276->at(2));
            this->field_278 = jrt::New<class_18>(jrt::arrayOf<int32_t>({var5->field_1300, var5->field_1301, (var5->field_1302 + 3000), var3->field_1300, var3->field_1301, (var3->field_1302 + 3000), 0, 0, 6000}));
            this->field_278->field_163 = true;
            if (class_21::method_180()->field_1143 != nullptr) {
                this->field_274 = jrt::newArray<jrt::Ref<class_91>>(class_21::method_180()->field_1143->length);
                for (int32_t var4 = 0; var4 < this->field_274->length; var4++) {
                    [&]() -> jrt::Ref<class_91>& { auto& __l = this->field_274->at(var4); __l = this->method_254(((class_21::method_180()->method_752()) ? 0 : 1), 0, int32_t(class_90::field_1205->at(class_21::method_180()->field_1143->at(var4)->field_863)), false, jrt::Ref<class_97>(nullptr)); return __l; }();
                    this->field_274->at(var4)->field_1230 = this->field_278->method_115();
                    if (class_84::field_1123->nextInt(2) == 0) {
                        this->field_274->at(var4)->field_1230->method_112(0);
                    }
                }
            }
            break;
        case 1:
            if ((var1 = class_21::method_180()->field_1143) != nullptr) {
                this->field_274 = jrt::newArray<jrt::Ref<class_91>>(var1->length);
                for (int32_t var2 = 0; var2 < var1->length; var2++) {
                    this->field_274->at(var2) = this->method_252(int32_t(class_90::field_1205->at(var1->at(var2)->field_863)));
                    this->field_274->at(var2)->field_1226->method_845(class_26::field_264->at(var2)->at(0), class_26::field_264->at(var2)->at(1), class_26::field_264->at(var2)->at(2));
                    this->field_274->at(var2)->field_1226->method_845(0, 0, (var2 * 50000));
                }
                return;
            }
        }
    }
}

void class_26::method_250() {
    this->field_270 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    this->field_271 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    int32_t var1 = jrt::f2i((float(class_21::method_210()) / 1.5f)) + jrt::f2i((float(class_21::method_143()) / 5.0f));
    jrt::Ref<class_9> var2 = jrt::Ref<class_9>(nullptr);
    if (this->field_273 != nullptr) {
        jrt::Ref<class_9> var3{};
        (var3 = jrt::New<class_9>((3 + var1), 4, (-1), 3000, 500, 16.0f, jrt::Ref<class_3>(nullptr), jrt::Ref<class_3>(nullptr)))->field_76 = jrt::Ref<class_26>(this);
        var3->method_44(this->field_266);
        for (int32_t var4 = 0; var4 < this->field_273->length; var4++) {
            if (this->field_273->at(var4)->field_1227 == 19) {
                this->field_270 = jrt::newArray<jrt::Ref<class_108>>(2);
            } else {
                this->field_270 = jrt::newArray<jrt::Ref<class_108>>(1);
            }
        }
        jrt::Ref<class_112> var9 = jrt::New<class_112>(var3, class_43::method_381(int32_t(class_90::field_1201->at(8))), 1000);
        this->field_270->at(0) = jrt::Ref<class_108>(var9);
        if (this->field_270->length == 2) {
            (var2 = jrt::New<class_9>((3 + var1), 6, (-1), 3000, 600, 15.0f, jrt::Ref<class_3>(nullptr), jrt::Ref<class_3>(nullptr)))->field_76 = jrt::Ref<class_26>(this);
            var2->method_44(this->field_266);
            jrt::Ref<class_112> var5 = jrt::New<class_112>(var2, class_43::method_381(6767), 1000);
            this->field_270->at(1) = jrt::Ref<class_108>(var5);
        }
        for (int32_t var12 = 0; var12 < this->field_273->length; var12++) {
            if (!this->field_273->at(var12)->field_1238) {
                if (this->field_273->at(var12)->field_1227 == 19) {
                    this->field_273->at(var12)->method_798(var2, 0);
                } else {
                    this->field_273->at(var12)->method_798(var3, 0);
                }
            }
        }
    }
    if (this->field_274 != nullptr) {
        jrt::Ref<class_9> var6{};
        (var6 = jrt::New<class_9>((3 + jrt::f2i((float(var1) * 0.8f))), 10, (-1), 3000, 500, 16.0f, jrt::Ref<class_3>(nullptr), jrt::Ref<class_3>(nullptr)))->field_76 = jrt::Ref<class_26>(this);
        var6->method_44(this->field_266);
        var6->field_101 = true;
        for (int32_t var10 = 0; var10 < this->field_274->length; var10++) {
            if (this->field_274->at(var10)->field_1227 == 19) {
                this->field_271 = jrt::newArray<jrt::Ref<class_108>>(2);
            } else {
                this->field_271 = jrt::newArray<jrt::Ref<class_108>>(1);
            }
        }
        jrt::Ref<class_112> var11 = jrt::New<class_112>(var6, class_43::method_381(int32_t(class_90::field_1201->at(2))), 1000);
        this->field_271->at(0) = jrt::Ref<class_108>(var11);
        if (this->field_271->length == 2) {
            (var2 = jrt::New<class_9>((5 + var1), 10, (-1), 3000, 600, 15.0f, jrt::Ref<class_3>(nullptr), jrt::Ref<class_3>(nullptr)))->field_76 = jrt::Ref<class_26>(this);
            var2->method_44(this->field_266);
            jrt::Ref<class_112> var13 = jrt::New<class_112>(var2, class_43::method_381(6767), 1000);
            this->field_271->at(1) = jrt::Ref<class_108>(var13);
        }
        for (int32_t var14 = 0; var14 < this->field_274->length; var14++) {
            if (((!(jrt::isInstance<class_99>(this->field_274->at(var14)))) || this->field_274->at(var14)->field_1238) && (((var14 != 0) || (!class_21::method_132()->field_1161)) || (class_21::method_143() != 26))) {
                if (this->field_274->at(var14)->field_1227 == 19) {
                    this->field_274->at(var14)->method_798(var2, 0);
                } else {
                    this->field_274->at(var14)->method_798(var6, 0);
                }
            }
        }
    }
    if (this->field_270 != nullptr) {
        for (int32_t var7 = 0; var7 < this->field_270->length; var7++) {
            this->field_270->at(var7)->field_1367 = 2;
        }
    }
    if (this->field_271 != nullptr) {
        for (int32_t var8 = 0; var8 < this->field_271->length; var8++) {
            this->field_271->at(var8)->field_1367 = 2;
        }
    }
}

void class_26::method_251() {
    if (((((class_21::method_132()->field_1146 != 6) && (class_21::method_132()->field_1146 != 11)) && (class_21::method_132()->field_1146 != 4)) && (this->field_273 != nullptr)) && (this->field_272 != nullptr)) {
        for (int32_t var1 = 0; var1 < this->field_273->length; var1++) {
            this->field_273->at(var1)->field_1225->method_324(this->field_272->field_969);
        }
    }
    if ((this->field_273 != nullptr) && (this->field_272 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var3 = jrt::newArray<jrt::Ref<class_37>>(this->field_273->length);
        for (int32_t var2 = 0; var2 < var3->length; var2++) {
            var3->at(var2) = this->field_273->at(var2)->field_1225;
        }
        this->field_272->field_969->method_323(var3);
    }
    if ((this->field_275 != nullptr) && (this->field_272 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var4 = jrt::newArray<jrt::Ref<class_37>>(this->field_275->length);
        for (int32_t var10 = 0; var10 < var4->length; var10++) {
            var4->at(var10) = this->field_275->at(var10)->field_1225;
        }
        this->field_272->field_969->method_325(var4);
    }
    if ((this->field_275 != nullptr) && (this->field_272 != nullptr)) {
        for (int32_t var5 = 0; var5 < this->field_275->length; var5++) {
            this->field_275->at(var5)->field_1225->method_324(this->field_272->field_969);
        }
    }
    if ((this->field_274 != nullptr) && (this->field_272 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var6 = jrt::newArray<jrt::Ref<class_37>>(this->field_274->length);
        for (int32_t var11 = 0; var11 < var6->length; var11++) {
            var6->at(var11) = this->field_274->at(var11)->field_1225;
        }
        this->field_272->field_969->field_361 = var6;
    }
    if (((!class_21::method_132()->method_754()) && (class_21::method_132()->field_1146 == 6)) && (this->field_273 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var7{};
        (var7 = jrt::newArray<jrt::Ref<class_37>>((this->field_275->length + 1)))->at((var7->length - 1)) = this->field_272->field_969;
        for (int32_t var12 = 0; var12 < (var7->length - 1); var12++) {
            var7->at(var12) = this->field_275->at(var12)->field_1225;
        }
        for (int32_t var13 = 0; var13 < this->field_273->length; var13++) {
            this->field_273->at(var13)->field_1225->method_325(var7);
        }
    }
    if ((this->field_273 != nullptr) && (this->field_274 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var8 = jrt::newArray<jrt::Ref<class_37>>((this->field_274->length + 1));
        if (class_21::method_132()->method_754() || (((class_21::method_132()->field_1146 != 6) && (class_21::method_132()->field_1146 != 11)) && (class_21::method_132()->field_1146 != 4))) {
            var8->at(0) = this->field_272->field_969;
            for (int32_t var15 = 1; var15 < var8->length; var15++) {
                var8->at(var15) = this->field_274->at((var15 - 1))->field_1225;
            }
        } else {
            var8 = jrt::newArray<jrt::Ref<class_37>>(this->field_274->length);
            for (int32_t var14 = 0; var14 < var8->length; var14++) {
                var8->at(var14) = this->field_274->at(var14)->field_1225;
            }
        }
        for (int32_t var16 = 0; var16 < this->field_273->length; var16++) {
            this->field_273->at(var16)->field_1225->method_325(var8);
        }
    }
    if ((this->field_273 != nullptr) && (this->field_274 != nullptr)) {
        jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var9 = jrt::newArray<jrt::Ref<class_37>>(this->field_273->length);
        for (int32_t var17 = 0; var17 < var9->length; var17++) {
            var9->at(var17) = this->field_273->at(var17)->field_1225;
        }
        for (int32_t var18 = 0; var18 < this->field_274->length; var18++) {
            this->field_274->at(var18)->field_1225->method_323(var9);
        }
    }
}

jrt::Ref<class_91> class_26::method_252(int32_t var1) {
    jrt::Ref<java::lang::Object> var2 = jrt::Ref<java::lang::Object>(nullptr);
    (jrt::cast<class_108>((var2 = jrt::Ref<java::lang::Object>(class_43::method_381(var1)))))->field_1367 = 2;
    return jrt::Ref<class_91>(jrt::New<class_98>(var1, jrt::cast<class_108>(var2), 0, 0, 0));
}

jrt::Ref<class_91> class_26::method_253(jrt::Ref<class_97> var1, int32_t var2) {
    int32_t var3 = (var1 != nullptr) ? var1->field_1295 : 0;
    int32_t var4 = (var1 != nullptr) ? var1->field_1296 : 0;
    int32_t var5 = (var1 != nullptr) ? var1->field_1297 : 0;
    int32_t var6 = (var3 + class_84::field_1123->nextInt(20000)) - 10000;
    int32_t var7 = (var4 + class_84::field_1123->nextInt(20000)) - 10000;
    int32_t var8 = (var5 + class_84::field_1123->nextInt(20000)) - 10000;
    jrt::Ref<class_108> var9{};
    (var9 = class_43::method_381(var2))->field_1367 = 2;
    jrt::Ref<java::lang::Object> var10 = jrt::Ref<java::lang::Object>(nullptr);
    jrt::Ref<java::lang::Object> var11 = jrt::Ref<java::lang::Object>(nullptr);
    if (var2 == 13) {
        var10 = jrt::Ref<java::lang::Object>(jrt::New<class_37>(1000.0f, 4, 1));
        [&]() -> jrt::Ref<class_85>& { auto& __l = (jrt::cast<class_91>((var11 = jrt::Ref<java::lang::Object>(jrt::New<class_93>(13, true, jrt::cast<class_37>(var10), var9, var6, var7, var8)))))->field_1231; __l = jrt::New<class_85>(1, 1); return __l; }();
        (jrt::cast<class_93>(var11))->field_1251 = this->field_268;
    } else if (var2 == 9996) {
        var10 = jrt::Ref<java::lang::Object>(jrt::New<class_37>(1000.0f, 1, 1));
        var11 = jrt::Ref<java::lang::Object>(jrt::New<class_94>(9996, true, jrt::cast<class_37>(var10), var9, var6, var7, var8));
        jrt::Ref<java::lang::Object> var12 = jrt::Ref<java::lang::Object>(nullptr);
        (jrt::cast<class_91>(var11))->field_1231 = jrt::New<class_85>(1, 0);
        (jrt::cast<class_91>(var11))->field_1226->method_860(var6, var7, var8);
    }
    (jrt::cast<class_91>(var11))->field_1229 = jrt::Ref<class_26>(this);
    return jrt::cast<class_91>(var11);
}

jrt::Ref<class_91> class_26::method_254(int32_t var1, int32_t var2, int32_t var3, bool var4, jrt::Ref<class_97> var5) {
    int32_t var6 = (var5 != nullptr) ? var5->field_1295 : 0;
    int32_t var7 = (var5 != nullptr) ? var5->field_1296 : 0;
    int32_t var8 = (var5 != nullptr) ? var5->field_1297 : 0;
    int32_t var9 = class_84::field_1123->nextInt(40000) - 20000;
    int32_t var10 = class_84::field_1123->nextInt(40000) - 20000;
    int32_t var11 = class_84::field_1123->nextInt(40000) - 20000;
    bool var12 = false;
    if ((class_21::method_132() != nullptr) && (class_21::method_132()->field_1146 == 6)) {
        var12 = true;
    }
    if (var12) {
        var9 = ([&]() { int32_t __v1 = var9; return (jrt::div(__v1, 10)); }());
        var10 = ([&]() { int32_t __v2 = var10; return (jrt::div(__v2, 10)); }());
        var11 = ([&]() { int32_t __v3 = var11; return (jrt::div(__v3, 10)); }());
    }
    int32_t var13 = var6 + var9;
    int32_t var14 = var7 + var10;
    int32_t var15 = var8 + var11;
    jrt::Ref<java::lang::Object> var16 = jrt::Ref<java::lang::Object>(nullptr);
    jrt::Ref<java::lang::Object> var19 = jrt::Ref<java::lang::Object>(nullptr);
    jrt::Ref<class_85> var20 = jrt::Ref<class_85>(nullptr);
    jrt::Ref<java::lang::Object> var21 = jrt::Ref<java::lang::Object>(nullptr);
    jrt::Ref<java::lang::Object> var22 = jrt::Ref<java::lang::Object>(nullptr);
    bool var23 = false;
    (jrt::cast<class_108>((var16 = jrt::Ref<java::lang::Object>(class_43::method_381(var3)))))->field_1367 = 2;
    jrt::Ref<class_37> var18{};
    if (var3 < class_90::field_1204->length) {
        int32_t var17 = (int32_t(class_90::field_1204->at(var3)) + (class_21::method_210() * 15)) + (class_21::method_143() * 4);
        var18 = jrt::New<class_37>(float(class_90::field_1203->at(var3)), var17, 1);
    } else {
        bool var25 = false;
        var18 = jrt::New<class_37>(2000.0f, 20, 1);
    }
    {
        switch (var2) {
        case 0:
            var19 = jrt::Ref<java::lang::Object>(jrt::New<class_96>(var3, var1, var4, var18, jrt::cast<class_108>(var16), var13, var14, var15));
            var20 = jrt::New<class_85>(1, ((var3 == 19) ? 2 : 0));
        case 1:
            ;
        case 2:
            ;
        case 4:
            ;
        default:
            break;
        case 3:
            var19 = jrt::Ref<java::lang::Object>(jrt::New<class_95>(var3, var1, var4, var18, jrt::cast<class_108>(var16), var13, var14, var15));
            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>((var22 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_29>>(1)))))->at(0) = jrt::Ref<java::lang::Object>(jrt::New<class_31>(var13, var14, var15, 0, 300, 0, 4000, 4000, 15000));
            (jrt::cast<class_95>(var19))->field_1253 = jrt::cast<jrt::Array<jrt::Ref<class_29>>>(var22);
            var21 = jrt::Ref<java::lang::Object>(jrt::arrayOf<int32_t>({360, 186, (-3370), (-844), (-507), 880, (-449), 437, (-983), 880, (-275), (-983), 360, 186, 4243, 0, 0, 0}));
            (var20 = jrt::New<class_85>(((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var21))->length / 3), 0))->method_739(jrt::cast<jrt::Array<int32_t>>(var21));
            break;
        case 5:
            var19 = jrt::Ref<java::lang::Object>(jrt::New<class_96>(var3, var1, var4, var18, jrt::cast<class_108>(var16), var13, var14, var15));
            var20 = jrt::New<class_85>(1, 0);
            break;
        case 6:
            var19 = jrt::Ref<java::lang::Object>(jrt::New<class_96>(var3, var1, var4, var18, jrt::cast<class_108>(var16), (var13 / 3), var7, (var15 / 3)));
            break;
        case 7:
            var19 = jrt::Ref<java::lang::Object>(jrt::New<class_92>(var3, var4, var18, jrt::cast<class_108>(var16), 0, 0, 0));
            var20 = jrt::New<class_85>(1, 0);
            var18->method_330(((class_21::method_132()->field_1146 == 12) ? 32 : 65));
        }
    }
    (jrt::cast<class_91>(var19))->field_1229 = jrt::Ref<class_26>(this);
    (jrt::cast<class_91>(var19))->field_1231 = var20;
    return jrt::cast<class_91>(var19);
}

jrt::Ref<class_18> class_26::method_255(int32_t var1) {
    jrt::Ref<jrt::Array<int32_t>> var2 = jrt::newArray<int32_t>((var1 * 3));
    for (int32_t var3 = 0; var3 < var2->length; var3 += 3) {
        var2->at(var3) = 60000 + class_84::field_1123->nextInt(40000);
        var2->at((var3 + 1)) = 0;
        if (var3 != 0) {
            var2->at((var3 + 2)) = (var2->at(((var3 - 1) + 2)) + 60000) + class_84::field_1123->nextInt(40000);
        } else {
            var2->at((var3 + 2)) = 60000 + class_84::field_1123->nextInt(40000);
        }
    }
    return jrt::New<class_18>(var2);
}

jrt::Ref<jrt::Array<jrt::Ref<class_20>>> class_26::method_256(int32_t var1) {
    this->field_280 = jrt::Ref<jrt::Array<jrt::Ref<class_20>>>(nullptr);
    {
        jrt::Ref<jrt::Array<int32_t>> var2{};
        jrt::Ref<jrt::Array<int32_t>> var3{};
        switch (var1) {
        case 5:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(5);
            this->field_280->at(0) = jrt::New<class_20>(644, 1, 5, 5000);
            this->field_280->at(1) = jrt::New<class_20>(645, 0, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(646, 1, 6, 1);
            this->field_280->at(3) = jrt::New<class_20>(647, 10, 12, 0);
            this->field_280->at(4) = jrt::New<class_20>(648, 1, 18, 0);
        case 6:
            ;
        case 7:
            ;
        case 8:
            ;
        case 9:
            ;
        case 10:
            ;
        case 11:
            ;
        case 12:
            ;
        case 13:
            ;
        case 14:
            ;
        case 15:
            ;
        case 16:
            ;
        case 17:
            ;
        case 18:
            ;
        case 20:
            ;
        case 22:
            ;
        case 24:
            ;
        case 26:
            ;
        case 28:
            ;
        case 30:
            ;
        case 32:
            ;
        case 33:
            ;
        case 34:
            ;
        case 36:
            ;
        case 37:
            ;
        case 38:
            ;
        case 39:
            ;
        case 40:
            ;
        case 41:
            ;
        case 44:
            ;
        case 46:
            ;
        default:
            break;
        case 19:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(2);
            this->field_280->at(0) = jrt::New<class_20>(766, 1, 8, 0);
            this->field_280->at(1) = jrt::New<class_20>(767, 1, 6, 1);
            break;
        case 21:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(2);
            this->field_280->at(0) = jrt::New<class_20>(788, 3, 5, 15000);
            this->field_280->at(1) = jrt::New<class_20>(789, 3, 8, 0);
            break;
        case 23:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(2);
            this->field_280->at(0) = jrt::New<class_20>(806, 2, 5, 3000);
            this->field_280->at(1) = jrt::New<class_20>(807, 2, 6, 0);
            break;
        case 25:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(4);
            this->field_280->at(0) = jrt::New<class_20>(826, 5, 5, 15000);
            this->field_280->at(1) = jrt::New<class_20>(827, 3, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(828, 3, 6, 1);
            this->field_280->at(3) = jrt::New<class_20>(829, 5, 6, 2);
            break;
        case 27:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(5);
            this->field_280->at(0) = jrt::New<class_20>(873, 3, 12, 0);
            this->field_280->at(1) = jrt::New<class_20>(874, 0, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(875, 1, 1, 0);
            this->field_280->at(3) = jrt::New<class_20>(876, 1, 14, 0);
            this->field_280->at(4) = jrt::New<class_20>(877, 1, 6, 2);
            break;
        case 29:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(2);
            this->field_280->at(0) = jrt::New<class_20>(883, 1, 5, 2000);
            this->field_280->at(1) = jrt::New<class_20>(884, 7, 6, 0);
            break;
        case 31:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(5);
            this->field_280->at(0) = jrt::New<class_20>(900, 5, 5, 2000);
            this->field_280->at(1) = jrt::New<class_20>(901, 0, 16, 0);
            this->field_280->at(2) = jrt::New<class_20>(902, 6, 6, 1);
            this->field_280->at(3) = jrt::New<class_20>(903, 4, 6, 2);
            this->field_280->at(4) = jrt::New<class_20>(904, 5, 6, 3);
            break;
        case 35:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(3);
            this->field_280->at(0) = jrt::New<class_20>(934, 1, 16, 0);
            this->field_280->at(1) = jrt::New<class_20>(935, 11, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(936, 11, 12, 0);
            break;
        case 42:
            var2 = jrt::arrayOf<int32_t>({0, 1, 2});
            var3 = jrt::arrayOf<int32_t>({3, 4, 5});
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(4);
            this->field_280->at(0) = jrt::New<class_20>(971, 1, 5, 5000);
            this->field_280->at(1) = jrt::New<class_20>(972, 1, 8, var2);
            this->field_280->at(2) = jrt::New<class_20>(973, 10, 15, 0);
            this->field_280->at(3) = jrt::New<class_20>(974, 1, 8, var3);
            break;
        case 43:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(3);
            this->field_280->at(0) = jrt::New<class_20>(982, 1, 5, 60000);
            this->field_280->at(1) = jrt::New<class_20>(983, 1, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(984, 9, 6, 1);
            break;
        case 45:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(2);
            this->field_280->at(0) = jrt::New<class_20>(1004, 0, 5, 30000);
            this->field_280->at(1) = jrt::New<class_20>(1005, 1, 6, 0);
            break;
        case 47:
            this->field_280 = jrt::newArray<jrt::Ref<class_20>>(25);
            this->field_280->at(0) = jrt::New<class_20>(1024, 5, 5, 30000);
            this->field_280->at(1) = jrt::New<class_20>(1025, 2, 6, 0);
            this->field_280->at(2) = jrt::New<class_20>(1026, 2, 17, (this->field_273->length - 1));
            this->field_280->at(3) = jrt::New<class_20>(1027, 9, 6, 2);
            this->field_280->at(4) = jrt::New<class_20>(1028, 0, 19, (this->field_273->length - 1));
            this->field_280->at(5) = jrt::New<class_20>(1029, 1, 6, 4);
            this->field_280->at(6) = jrt::New<class_20>(1030, 9, 1, (this->field_273->length - 1));
            this->field_280->at(7) = jrt::New<class_20>(1031, 1, 6, 6);
            this->field_280->at(8) = jrt::New<class_20>(1032, 0, 6, 7);
            this->field_280->at(9) = jrt::New<class_20>(1033, 9, 6, 8);
            this->field_280->at(10) = jrt::New<class_20>(1034, 9, 6, 9);
            this->field_280->at(11) = jrt::New<class_20>(1035, 5, 6, 10);
            this->field_280->at(12) = jrt::New<class_20>(1036, 9, 6, 11);
            this->field_280->at(13) = jrt::New<class_20>(1037, 0, 6, 12);
            this->field_280->at(14) = jrt::New<class_20>(1038, 5, 6, 13);
            this->field_280->at(15) = jrt::New<class_20>(1039, 0, 6, 14);
            this->field_280->at(16) = jrt::New<class_20>(1040, 1, 6, 15);
            this->field_280->at(17) = jrt::New<class_20>(1041, 0, 6, 16);
            this->field_280->at(18) = jrt::New<class_20>(1042, 1, 6, 17);
            this->field_280->at(19) = jrt::New<class_20>(1043, 2, 6, 18);
            this->field_280->at(20) = jrt::New<class_20>(1044, 2, 6, 19);
            this->field_280->at(21) = jrt::New<class_20>(1045, 2, 6, 20);
            this->field_280->at(22) = jrt::New<class_20>(1046, 5, 6, 21);
            this->field_280->at(23) = jrt::New<class_20>(1047, 0, 6, 22);
            this->field_280->at(24) = jrt::New<class_20>(1048, 1, 6, 23);
        }
    }
    return this->field_280;
}

void class_26::method_257(int32_t var1, bool var2) {
    this->field_281--;
    this->field_288++;
    if ((!var2) && (var1 != 13)) {
        class_21::method_203();
    }
}

void class_26::method_258() {
    this->field_281--;
}

void class_26::method_259() {
    this->field_282--;
}

void class_26::method_260() {
    this->field_285--;
    this->field_286 = jrt::concat(jrt::f2i(((float(this->field_285) / float(class_21::method_132()->field_1167)) * 100.0f)), JRT_LIT(u"%/"), class_21::method_132()->field_1169, JRT_LIT(u"%"));
}

void class_26::method_261() {
    this->field_287++;
}

bool class_26::method_262(jrt::Ref<class_3> var1, bool var2) {
    return class_26::field_263->method_287(var1->field_37, var1->field_38, var1->field_39);
}

bool class_26::method_263(jrt::Ref<class_3> var1) {
    return (this->field_276 != nullptr) ? this->field_276->at(1)->method_806(var1->field_37, var1->field_38, var1->field_39) : false;
}

bool class_26::method_264(jrt::Ref<class_3> var1) {
    return (((this->field_276 != nullptr) && (this->field_276->at(0) != nullptr)) && (!class_21::method_147())) ? this->field_276->at(0)->method_806(var1->field_37, var1->field_38, var1->field_39) : false;
}

void class_26::method_265(int64_t var1) {
    class_84::field_1117->setColor(this->field_298, this->field_299, this->field_300);
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    if (org::deep3d::Remaster::on()) {
        class_4::deep3dKind = 3;
    }
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_265));
    class_4::deep3dKind = 0;
    if (this->field_269 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_269->length; var3++) {
            this->field_269->at(var3)->method_887();
        }
    }
    if (this->field_270 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_270->length; var4++) {
            this->field_270->at(var4)->method_887();
        }
    }
    if (this->field_271 != nullptr) {
        for (int32_t var5 = 0; var5 < this->field_271->length; var5++) {
            this->field_271->at(var5)->method_887();
        }
    }
    if (this->field_273 != nullptr) {
        for (int32_t var6 = 0; var6 < this->field_273->length; var6++) {
            this->field_273->at(var6)->method_805(var1);
            this->field_273->at(var6)->method_809();
        }
    }
    if (this->field_274 != nullptr) {
        for (int32_t var7 = 0; var7 < this->field_274->length; var7++) {
            this->field_274->at(var7)->method_805(var1);
            this->field_274->at(var7)->method_809();
        }
    }
    if (this->field_275 != nullptr) {
        for (int32_t var8 = 0; var8 < this->field_275->length; var8++) {
            this->field_275->at(var8)->method_805(var1);
            this->field_275->at(var8)->method_809();
        }
    }
    OpenSea::step(this, var1, true);
    if (this->field_276 != nullptr) {
        for (int32_t var9 = 0; var9 < this->field_276->length; var9++) {
            if (this->field_276->at(var9) != nullptr) {
                this->field_276->at(var9)->method_805(var1);
                this->field_276->at(var9)->method_809();
            }
        }
    }
    this->deep3dSurface();
    this->deep3dRemaster();
    Deep3dDebug::worldFrames++;
    if (!this->deep3dShown) {
        this->deep3dShown = true;
        org::deep3d::gl::GLBackend::holdFrame();
    }
}

void class_26::method_266(int64_t var1) {
    class_84::field_1117->setColor(this->field_298, this->field_299, this->field_300);
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    if (org::deep3d::Remaster::on()) {
        class_4::deep3dKind = 3;
    }
    class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_265));
    class_4::deep3dKind = 0;
    if (this->field_269 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_269->length; var3++) {
            this->field_269->at(var3)->method_887();
        }
    }
    if (this->field_270 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_270->length; var4++) {
            this->field_270->at(var4)->method_887();
        }
    }
    if (this->field_271 != nullptr) {
        for (int32_t var5 = 0; var5 < this->field_271->length; var5++) {
            this->field_271->at(var5)->method_887();
        }
    }
    if (this->field_273 != nullptr) {
        for (int32_t var6 = 0; var6 < this->field_273->length; var6++) {
            this->field_273->at(var6)->method_809();
        }
    }
    if (this->field_274 != nullptr) {
        for (int32_t var7 = 0; var7 < this->field_274->length; var7++) {
            this->field_274->at(var7)->method_809();
        }
    }
    if (this->field_275 != nullptr) {
        for (int32_t var8 = 0; var8 < this->field_275->length; var8++) {
            this->field_275->at(var8)->method_809();
        }
    }
    OpenSea::step(this, 0, false);
    if (this->field_276 != nullptr) {
        for (int32_t var9 = 0; var9 < this->field_276->length; var9++) {
            if (this->field_276->at(var9) != nullptr) {
                this->field_276->at(var9)->method_809();
            }
        }
    }
    this->deep3dSurface();
    this->deep3dRemaster();
    Deep3dDebug::worldFrames++;
    if (!this->deep3dShown) {
        this->deep3dShown = true;
        org::deep3d::gl::GLBackend::holdFrame();
    }
}

void class_26::method_267(int64_t var1) {
    if (this->field_272 != nullptr) {
        float var3 = this->field_272->method_665();
        this->field_298 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_295 * var3)))));
        this->field_299 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_296 * var3)))));
        this->field_300 = class_16::method_97(0, class_16::method_98(255, class_16::method_97(0, jrt::f2i((this->field_297 * var3)))));
    }
    if (this->field_269 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_269->length; var4++) {
            (jrt::cast<class_112>(this->field_269->at(var4)))->method_895(var1);
        }
    }
    if (this->field_270 != nullptr) {
        for (int32_t var5 = 0; var5 < this->field_270->length; var5++) {
            (jrt::cast<class_112>(this->field_270->at(var5)))->method_895(var1);
        }
    }
    if (this->field_271 != nullptr) {
        for (int32_t var6 = 0; var6 < this->field_271->length; var6++) {
            (jrt::cast<class_112>(this->field_271->at(var6)))->method_895(var1);
        }
    }
}

bool class_26::method_268(int32_t var1) {
    return (this->field_289 != nullptr) ? this->field_289->method_222(var1) : false;
}

void class_26::method_269() {
    this->field_289 = jrt::Ref<class_22>(nullptr);
    this->field_290 = jrt::Ref<class_22>(nullptr);
}

bool class_26::method_270(int32_t var1) {
    return (this->field_290 != nullptr) ? this->field_290->method_222(var1) : false;
}

void class_26::method_271() {
    OpenSea::end(this);
    class_43::method_384();
    if (this->field_276 != nullptr) {
        for (int32_t var1 = 0; var1 < this->field_276->length; var1++) {
            if (this->field_276->at(var1) != nullptr) {
                this->field_276->at(var1)->method_794();
                this->field_276->at(var1) = jrt::Ref<class_91>(nullptr);
            }
        }
    }
    this->field_276 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    if (this->field_266 != nullptr) {
        this->field_266->method_894();
    }
    this->field_266 = jrt::Ref<class_116>(nullptr);
    if (this->field_268 != nullptr) {
        this->field_268->method_894();
    }
    this->field_268 = jrt::Ref<class_116>(nullptr);
    if (this->field_269 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_269->length; var2++) {
            this->field_269->at(var2)->method_894();
        }
    }
    this->field_269 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    if (this->field_270 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_270->length; var3++) {
            this->field_270->at(var3)->method_894();
        }
    }
    this->field_270 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    if (this->field_271 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_271->length; var4++) {
            this->field_271->at(var4)->method_894();
        }
    }
    this->field_271 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    if (this->field_272 != nullptr) {
        this->field_272->method_680();
    }
    this->field_272 = jrt::Ref<class_70>(nullptr);
    if (this->field_273 != nullptr) {
        for (int32_t var5 = 0; var5 < this->field_273->length; var5++) {
            this->field_273->at(var5)->method_794();
        }
    }
    this->field_273 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    if (this->field_274 != nullptr) {
        for (int32_t var6 = 0; var6 < this->field_274->length; var6++) {
            this->field_274->at(var6)->method_794();
        }
    }
    this->field_274 = jrt::Ref<jrt::Array<jrt::Ref<class_91>>>(nullptr);
    if (this->field_277 != nullptr) {
        this->field_277->method_108();
    }
    this->field_277 = jrt::Ref<class_18>(nullptr);
    if (this->field_278 != nullptr) {
        this->field_278->method_108();
    }
    this->field_278 = jrt::Ref<class_18>(nullptr);
    if (this->field_279 != nullptr) {
        this->field_279->method_108();
    }
    this->field_279 = jrt::Ref<class_18>(nullptr);
    this->field_280 = jrt::Ref<jrt::Array<jrt::Ref<class_20>>>(nullptr);
    this->field_289 = jrt::Ref<class_22>(nullptr);
    this->field_290 = jrt::Ref<class_22>(nullptr);
    this->field_292 = 0;
    java::lang::System::gc();
}

void class_26::deep3dSurface() {
    if ((this->field_272 == nullptr) || (this->field_272->field_970 == nullptr)) {
        return;
    }
    int32_t var1 = this->field_272->field_1003 * 8;
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<class_91>>>>> var2 = jrt::arrayOf<jrt::Ref<jrt::Array<jrt::Ref<class_91>>>>({this->field_273, this->field_274, this->field_275});
    for (int32_t var3 = 0; var3 < var2->length; var3++) {
        if (var2->at(var3) != nullptr) {
            for (int32_t var4 = 0; var4 < var2->at(var3)->length; var4++) {
                jrt::Ref<class_91> var5 = var2->at(var3)->at(var4);
                if (((var5 != nullptr) && (var5->field_1226 != nullptr)) && (var5->field_1226->method_853() > (var1 - 3000))) {
                    var5->field_1226->method_845(var5->field_1226->method_852(), (var1 - 3000), var5->field_1226->method_854());
                }
            }
        }
    }
    if (((this->field_272 != nullptr) && (this->field_272->field_970 != nullptr)) && (this->field_272->field_970->method_853() > (var1 - 1200))) {
        this->field_272->field_970->method_845(this->field_272->field_970->method_852(), (var1 - 1200), this->field_272->field_970->method_854());
    }
}

void class_26::deep3dRemaster() {
    if (((!org::deep3d::Remaster::on()) || (class_84::field_1110 == nullptr)) || (class_84::field_1110->field_40 == nullptr)) {
        return;
    }
    class_84::field_1110->field_40->field_1342->method_505(this->deep3dCam);
    // Deep3D-PC: on the open sea, positions go to the renderer relative to an origin under the camera
    // (cells of 65536 units), taken off in whole numbers before they become floats
    jrt::Ref<class_57> deep3dCamM = class_84::field_1110->field_40->field_1342;
    int32_t deep3dOX = 0, deep3dOZ = 0;
    if (org::deep3d::Config::openSeaOn()) {
        deep3dOX = deep3dCamM->field_698 >> 16;
        deep3dOZ = deep3dCamM->field_700 >> 16;
        this->deep3dCam->at(3) = float(deep3dCamM->field_698 - (deep3dOX << 16));
        this->deep3dCam->at(11) = float(deep3dCamM->field_700 - (deep3dOZ << 16));
    }
    org::deep3d::Remaster::world(this->deep3dCam, ((class_21::method_180() != nullptr) ? class_21::method_180()->field_1140 : 21000), (float(this->field_298) / 255.0f), (float(this->field_299) / 255.0f), (float(this->field_300) / 255.0f));
    org::deep3d::Remaster::origin(deep3dOX + OpenSea::shiftCellsX(), deep3dOZ + OpenSea::shiftCellsZ());
    if ((this->field_272 != nullptr) && (this->field_272->field_970 != nullptr)) {
        this->field_272->field_970->method_849(this->deep3dPos);
        jrt::Ref<class_3> var2 = this->field_272->field_970->method_855(jrt::New<class_3>());
        org::deep3d::Remaster::sub(float(this->deep3dPos->field_37 - (deep3dOX << 16)), float(this->deep3dPos->field_38), float(this->deep3dPos->field_39 - (deep3dOZ << 16)), (float(var2->field_37) / 4096.0f), (float(var2->field_38) / 4096.0f), (float(var2->field_39) / 4096.0f), (this->field_272->field_994 ? 1.0f : 0.0f));
    }
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<class_91>>>>> var3 = jrt::arrayOf<jrt::Ref<jrt::Array<jrt::Ref<class_91>>>>({this->field_273, this->field_274});
    for (int32_t var4 = 0; var4 < var3->length; var4++) {
        if (var3->at(var4) != nullptr) {
            for (int32_t var5 = 0; var5 < var3->at(var4)->length; var5++) {
                jrt::Ref<class_91> var6 = var3->at(var4)->at(var5);
                if (((jrt::isInstance<class_96>(var6) && (var6->field_1226 != nullptr)) && (int32_t(var6->field_1224) != 3)) && (int32_t(var6->field_1224) != 4)) {
                    var6->field_1226->method_849(this->deep3dPos);
                    org::deep3d::Remaster::light(float(this->deep3dPos->field_37 - (deep3dOX << 16)), float(this->deep3dPos->field_38), float(this->deep3dPos->field_39 - (deep3dOZ << 16)), 1);
                }
            }
        }
    }
}

void class_26::__dumpFields(jrt::Dumper& d) {
    d.f("deep3dCam", this->deep3dCam);
    d.f("deep3dPos", this->deep3dPos);
    d.f("deep3dShown", this->deep3dShown);
    d.f("field_262", this->field_262);
    d.f("field_265", this->field_265);
    d.f("field_266", this->field_266);
    d.f("field_267", this->field_267);
    d.f("field_268", this->field_268);
    d.f("field_269", this->field_269);
    d.f("field_270", this->field_270);
    d.f("field_271", this->field_271);
    d.f("field_272", this->field_272);
    d.f("field_273", this->field_273);
    d.f("field_274", this->field_274);
    d.f("field_275", this->field_275);
    d.f("field_276", this->field_276);
    d.f("field_277", this->field_277);
    d.f("field_278", this->field_278);
    d.f("field_279", this->field_279);
    d.f("field_280", this->field_280);
    d.f("field_281", this->field_281);
    d.f("field_282", this->field_282);
    d.f("field_283", this->field_283);
    d.f("field_284", this->field_284);
    d.f("field_285", this->field_285);
    d.f("field_286", this->field_286);
    d.f("field_287", this->field_287);
    d.f("field_288", this->field_288);
    d.f("field_289", this->field_289);
    d.f("field_290", this->field_290);
    d.f("field_291", this->field_291);
    d.f("field_292", this->field_292);
    d.f("field_293", this->field_293);
    d.f("field_294", this->field_294);
    d.f("field_295", this->field_295);
    d.f("field_296", this->field_296);
    d.f("field_297", this->field_297);
    d.f("field_298", this->field_298);
    d.f("field_299", this->field_299);
    d.f("field_300", this->field_300);
}

