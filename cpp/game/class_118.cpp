// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_118::__clinit() {
}

void class_118::__init(jrt::Ref<class_42> var1, jrt::Ref<class_5> var2, jrt::Ref<class_26> var3) {
    this->field_1451 = jrt::New<class_3>();
    this->field_1452 = jrt::New<class_3>();
    this->field_1453 = jrt::New<class_3>();
    class_69::method_645(false);
    this->field_1443 = var3;
    this->field_1444 = 0;
    this->field_1445 = true;
    this->field_1446 = true;
    this->field_1447 = false;
    this->field_1450 = false;
    this->field_1448 = var2;
    this->field_1456 = false;
    var1->method_373(false);
    var2->field_53 = true;
    if (class_21::method_143() == 1) {
        class_69::field_963 = true;
        var3->field_272->field_991 = true;
        var3->field_272->method_661();
        this->field_1454 = jrt::New<class_39>(class_84::field_1120, class_84::field_1121, 1);
        class_84::field_1110->method_24(this->field_1454->field_388);
    } else {
        if (class_26::field_301) {
            this->field_1451->field_37 = 2000 + class_84::field_1123->nextInt(2000);
            this->field_1451->field_38 = 2000 + class_84::field_1123->nextInt(2000);
            this->field_1451->field_39 = 30000;
        } else {
            this->field_1451->field_37 = 2000 + class_84::field_1123->nextInt(2000);
            this->field_1451->field_38 = (-2000) + class_84::field_1123->nextInt(4000);
            this->field_1451->field_39 = 6000;
        }
        if (class_84::field_1123->nextInt(2) == 0) {
            this->field_1451->field_37 *= (-1);
        }
        if (class_84::field_1123->nextInt(2) == 0) {
            this->field_1451->field_38 *= (-1);
        }
        jrt::Ref<class_57> var4{};
        (var4 = jrt::New<class_57>())->method_490(var3->field_272->field_970->method_866());
        this->field_1452 = var4->method_508(this->field_1451, this->field_1452);
        this->field_1452->method_15(var3->field_272->field_970->method_848(this->field_1451));
        class_84::field_1110->field_40->method_846(this->field_1452);
        var1->method_370(this->field_1452);
        var2->method_31(var3->field_272->field_970->method_857(), 2);
        if (class_21::method_132()->field_1161 && (!class_21::method_132()->method_754())) {
            {
                switch (class_21::method_143()) {
                case 25:
                    var3->field_274->at(0)->field_1225->method_349();
                }
            }
        }
    }
    var3->field_272->field_997 = false;
}

bool class_118::method_913(int32_t var1, jrt::Ref<class_42> var2, jrt::Ref<class_2> var3) {
    if (this->field_1446) {
        this->field_1449 += var1;
        if (class_21::method_143() == 1) {
            if (this->field_1444 == 0) {
                class_69::method_638(JRT_LIT(u""));
                this->field_1443->field_272->field_976->method_547(int64_t(var1), class_84::field_1110->field_40->field_1342, false);
                this->field_1443->field_272->field_976->method_548();
                this->field_1454->method_364(int64_t(this->field_1449));
                if (this->field_1449 > 69000) {
                    class_84::field_1122->method_773();
                    class_69::method_638(JRT_LIT(u""));
                    class_69::field_963 = false;
                    class_69::method_645(false);
                    this->field_1444 = 1;
                    this->field_1443->field_272->field_991 = false;
                    class_84::field_1110->method_24(jrt::cast<class_106>(var2->field_454));
                    var2->method_373(true);
                    this->field_1448->field_53 = false;
                    class_84::field_1110->field_40->method_870(this->field_1454->field_388->field_1341);
                    var2->method_374(class_84::field_1110->field_40->method_850());
                } else if ((this->field_1449 > 4000) && (this->field_1449 < 9000)) {
                    class_69::method_638(class_84::field_1116->method_4(622));
                } else if ((this->field_1449 > 14000) && (this->field_1449 < 19000)) {
                    class_69::method_638(class_84::field_1116->method_4(623));
                } else if ((this->field_1449 > 24000) && (this->field_1449 < 29000)) {
                    class_69::method_645(true);
                } else if ((this->field_1449 > 34000) && (this->field_1449 < 39000)) {
                    class_69::method_638(class_84::field_1116->method_4(624));
                } else if ((this->field_1449 > 44000) && (this->field_1449 < 51000)) {
                    class_69::method_638(class_84::field_1116->method_4(625));
                } else if ((this->field_1449 > 56000) && (this->field_1449 < 61000)) {
                    class_69::method_638(class_84::field_1116->method_4(626));
                } else if ((this->field_1449 > 65000) && (this->field_1449 < 69000)) {
                    class_69::method_638(class_84::field_1116->method_4(627));
                }
            }
        } else if (class_26::field_301) {
            this->field_1451->method_10(0, 0, ((-10) * var1));
            this->field_1453 = this->field_1443->field_272->field_970->field_1341->method_508(this->field_1451, this->field_1453);
            class_84::field_1110->field_40->method_844(this->field_1453);
            if ((this->field_1449 > 3500) && (!this->field_1450)) {
                (jrt::cast<class_99>(this->field_1443->field_276->at(2)))->method_824();
                this->field_1450 = true;
            }
        }
        if (((class_21::method_143() != 1) && (this->field_1449 > 7000)) || (this->field_1444 == 1)) {
            this->field_1449 = 0;
            this->field_1446 = false;
            this->field_1447 = true;
            this->field_1448->field_53 = false;
            if (class_26::field_301) {
                this->field_1451->method_10(0, 0, (-10000));
                this->field_1453 = this->field_1443->field_276->at(2)->field_1226->field_1341->method_508(this->field_1451, this->field_1453);
                this->field_1453->method_15(this->field_1443->field_276->at(2)->field_1226->method_850());
                var2->method_374(this->field_1453);
            } else {
                var2->method_374(class_84::field_1110->field_40->method_850());
            }
            var2->method_373(true);
            class_118::method_916(var2, this->field_1443);
            this->field_1445 = false;
            this->field_1443->field_272->field_997 = true;
            class_69::method_638(jrt::Ref<java::lang::String>(nullptr));
            class_67::method_578(class_21::method_178()->field_884);
            if (class_26::field_302 != nullptr) {
                class_69::method_633(5, this->field_1443->field_272);
            }
            class_26::field_301 = false;
            if (class_26::field_302 != nullptr) {
                this->field_1443->field_272->method_667(this->field_1443->field_276->at(1));
            }
        }
    }
    if (class_21::method_132()->field_1161 && (!class_21::method_132()->method_754())) {
        {
            switch (class_21::method_143()) {
            case 21:
                if (this->field_1446) {
                    this->field_1443->field_274->at(0)->method_795(false);
                } else if ((this->field_1444 == 0) && this->field_1447) {
                    this->field_1444 = 1;
                    this->field_1443->field_274->at(0)->method_795(true);
                    this->field_1443->field_274->at(0)->method_804();
                }
                break;
            case 25:
                if (this->field_1443->field_280->at(3)->field_184) {
                    this->field_1443->field_274->at(0)->method_796(10);
                    this->field_1443->field_274->at(0)->method_797(jrt::Ref<jrt::Array<jrt::Ref<class_37>>>(nullptr));
                }
                if (this->field_1443->field_274->at(0)->field_1230->method_111()->field_1298) {
                    this->field_1443->field_274->at(0)->method_795(false);
                }
                break;
            case 43:
                if (this->field_1443->field_280->at(0)->field_184 && (!this->field_1443->field_280->at(0)->field_185)) {
                    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var11 = this->field_1443->field_274;
                    for (int32_t var13 = 0; var13 < var11->length; var13++) {
                        var11->at(var13)->method_804();
                    }
                }
                break;
            case 47:
                if (this->field_1443->field_280->at(2)->field_184 && (this->field_1444 == 0)) {
                    this->field_1444 = 1;
                    bool var10 = false;
                    this->field_1443->field_273->at((this->field_1443->field_273->length - 1))->field_1225->method_330(100);
                } else if (this->field_1443->field_280->at(6)->field_185 && (this->field_1444 == 1)) {
                    this->field_1444 = 2;
                    jrt::Ref<class_91> var9 = this->field_1443->field_273->at((this->field_1443->field_273->length - 1));
                    this->field_1451 = var9->field_1226->method_848(this->field_1451);
                    var9->field_1226 = class_43::method_381(9994);
                    var9->field_1226->method_846(this->field_1451);
                    var9->field_1226->field_1367 = 2;
                    var9->field_1225->method_349();
                    var9->method_797(jrt::Ref<jrt::Array<jrt::Ref<class_37>>>(nullptr));
                    jrt::Ref<class_18> var12 = jrt::New<class_18>(jrt::arrayOf<int32_t>({0, 0, 0}));
                    var9->field_1230 = var12;
                    (jrt::cast<class_96>(var9))->field_1282 = true;
                    var9->field_1225->method_327(32000);
                    var9->method_795(true);
                    var9->field_1224 = int16_t(1);
                    var9->method_796(6);
                    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var15 = this->field_1443->field_274;
                    for (int32_t var7 = 0; var7 < var15->length; var7++) {
                        var15->at(var7)->method_797(jrt::Ref<jrt::Array<jrt::Ref<class_37>>>(nullptr));
                        var15->at(var7)->field_1230 = var12->method_115();
                        var15->at(var7)->field_1225->method_349();
                    }
                    var2->method_373(false);
                    this->field_1448->field_45 = jrt::Ref<class_102>(var9->field_1226);
                    this->field_1448->field_53 = true;
                    this->field_1448->method_31(this->field_1443->field_272->field_970->method_857(), 2);
                    this->field_1451->field_39 -= 4000;
                    class_84::field_1110->field_40->method_846(this->field_1451);
                    this->field_1445 = true;
                    this->field_1456 = true;
                } else if (this->field_1443->field_280->at(10)->field_184 && (this->field_1444 == 2)) {
                    this->field_1451->method_10(0, 4096, 0);
                    this->field_1448->method_31(this->field_1451, 2);
                    class_84::field_1110->field_40->method_845(15000, 8000, 28000);
                    jrt::Ref<java::lang::Object> var8 = jrt::Ref<java::lang::Object>(nullptr);
                    this->field_1448->field_45 = jrt::Ref<class_102>((jrt::cast<class_100>(this->field_1443->field_276->at(0)))->method_826());
                    this->field_1444 = 3;
                } else {
                    jrt::Ref<class_91> var4{};
                    if ((this->field_1444 == 2) && (var4 = this->field_1443->field_273->at((this->field_1443->field_273->length - 1)))->field_1230->method_111()->field_1298) {
                        var4->field_1226->method_845(0, 0, 0);
                        var4->method_795(false);
                        var4->method_803();
                        var4->field_1225->method_327(0);
                        jrt::Ref<class_18> var5{};
                        (var5 = jrt::New<class_18>(jrt::arrayOf<int32_t>({40000, 0, 0, 36000, (-3000), 4000})))->field_163 = true;
                        for (int32_t var6 = 0; var6 < this->field_1443->field_274->length; var6++) {
                            this->field_1443->field_274->at(var6)->field_1230 = var5->method_115();
                        }
                        jrt::Ref<class_18> var14{};
                        (var14 = jrt::New<class_18>(jrt::arrayOf<int32_t>({42000, (-2000), 3000, 30000, (-1000), (-5000)})))->field_163 = true;
                        this->field_1443->field_272->field_982 = var14;
                        this->field_1443->field_272->method_667(jrt::Ref<class_91>(var14->method_111()));
                    }
                }
                if (this->field_1444 == 3) {
                    this->field_1455 += (var1 / 4);
                    (jrt::cast<class_100>(this->field_1443->field_276->at(0)))->method_827(0, ((var1 * 2) + this->field_1455), 0);
                    if (this->field_1443->field_280->at(12)->field_185) {
                        this->field_1444 = 4;
                        this->field_1448->field_53 = true;
                        this->field_1443->field_272->method_670(44000, (-5000), 1000);
                        this->field_1451->method_10(0, 4096, 0);
                        this->field_1448->method_31(this->field_1451, 2);
                        this->field_1448->field_45 = jrt::Ref<class_102>(this->field_1443->field_272->field_970);
                        this->field_1448->field_48 = jrt::Ref<class_102>(class_84::field_1110->field_40);
                        class_84::field_1110->field_40->method_845(33000, (-4000), 2000);
                    }
                }
                if ((this->field_1444 == 4) && this->field_1443->field_280->at(15)->field_185) {
                    this->field_1444 = 5;
                    this->field_1451 = this->field_1443->field_274->at(0)->method_799(this->field_1451);
                    this->field_1451->field_37 += 5000;
                    this->field_1451->field_38 -= 2000;
                    class_84::field_1110->field_40->method_846(this->field_1451);
                    this->field_1448->field_45 = jrt::Ref<class_102>(this->field_1443->field_274->at(0)->field_1226);
                }
                if ((this->field_1444 == 5) && this->field_1443->field_280->at(17)->field_185) {
                    this->field_1444 = 6;
                    this->field_1451 = this->field_1443->field_274->at(1)->method_799(this->field_1451);
                    this->field_1451->field_37 -= 5000;
                    this->field_1451->field_38 += 2000;
                    class_84::field_1110->field_40->method_846(this->field_1451);
                    this->field_1448->field_45 = jrt::Ref<class_102>(this->field_1443->field_274->at(1)->field_1226);
                }
                if ((this->field_1444 == 6) && this->field_1443->field_280->at(19)->field_185) {
                    this->field_1444 = 7;
                    this->field_1451 = this->field_1443->field_274->at(1)->method_799(this->field_1451);
                    this->field_1451->field_39 += 8000;
                    this->field_1451->field_38 += 1000;
                    class_84::field_1110->field_40->method_846(this->field_1451);
                    this->field_1448->field_45 = jrt::Ref<class_102>(this->field_1443->field_274->at(1)->field_1226);
                }
                if ((this->field_1444 == 7) && this->field_1443->field_280->at(24)->field_185) {
                    this->field_1444 = 8;
                    this->field_1448->field_53 = false;
                    var2->method_373(true);
                    this->field_1449 = 0;
                    class_69::method_635();
                    this->field_1443->field_272->method_670(44000, (-5000), 1000);
                }
                if (this->field_1444 == 8) {
                    class_69::method_636(1);
                    if (class_69::method_637()) {
                        this->field_1444 = 9;
                    }
                }
                if (this->field_1444 == 9) {
                    class_21::method_133(class_87::field_1145);
                    class_21::method_145();
                    this->field_1443->field_273->at((this->field_1443->field_273->length - 1))->method_802();
                    this->field_1443->field_272->method_667(jrt::Ref<class_91>(nullptr));
                    this->field_1443->field_272->field_982 = jrt::Ref<class_18>(nullptr);
                    this->field_1443->method_269();
                    this->field_1443->field_277 = jrt::Ref<class_18>(nullptr);
                    jrt::New<class_2>(this->field_1443);
                    this->field_1445 = false;
                    this->field_1444 = 10;
                    this->field_1456 = false;
                }
            }
        }
    }
    return this->field_1445;
}

void class_118::method_914() {
    if (class_21::method_143() > 1) {
        this->field_1449 = 7001;
    }
    class_67::method_578(class_21::method_178()->field_884);
}

void class_118::method_915() {
    this->field_1447 = false;
    this->field_1449 = 0;
    this->field_1450 = true;
}

void class_118::method_916(jrt::Ref<class_42> var0, jrt::Ref<class_26> var1) {
    var0->method_368(jrt::Ref<class_102>(var1->field_272->field_970));
    var0->method_375(jrt::New<class_3>(0, 850, 0));
    var0->method_376(jrt::New<class_3>(0, 1050, (-4000)));
    var0->method_372();
}

void class_118::method_917(jrt::Ref<class_42> var0) {
    var0->method_375(jrt::New<class_3>(0, 300, 0));
    var0->method_376(jrt::New<class_3>(0, 300, 5600));
}

void class_118::method_918(jrt::Ref<class_42> var0) {
    var0->method_375(jrt::New<class_3>(0, 500, 0));
    var0->method_376(jrt::New<class_3>(6000, 500, 0));
}

void class_118::method_919(jrt::Ref<class_42> var0) {
    var0->method_375(jrt::New<class_3>(0, 500, 0));
    var0->method_376(jrt::New<class_3>((-6000), 500, 0));
}

void class_118::__dumpFields(jrt::Dumper& d) {
    d.f("field_1443", this->field_1443);
    d.f("field_1444", this->field_1444);
    d.f("field_1445", this->field_1445);
    d.f("field_1446", this->field_1446);
    d.f("field_1447", this->field_1447);
    d.f("field_1448", this->field_1448);
    d.f("field_1449", this->field_1449);
    d.f("field_1450", this->field_1450);
    d.f("field_1451", this->field_1451);
    d.f("field_1452", this->field_1452);
    d.f("field_1453", this->field_1453);
    d.f("field_1454", this->field_1454);
    d.f("field_1455", this->field_1455);
    d.f("field_1456", this->field_1456);
}

