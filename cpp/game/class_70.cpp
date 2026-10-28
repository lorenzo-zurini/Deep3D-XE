// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_70::field_966{};
int32_t class_70::field_967{};
int32_t class_70::field_968{};

void class_70::__clinit() {
    class_70::field_966 = 5;
    class_70::field_967 = 5000;
    class_70::field_968 = 20000;
}

void class_70::__init(jrt::Ref<class_37> var1) {
    this->field_1002 = jrt::New<class_57>();
    this->field_969 = var1;
    this->field_969->field_380 = true;
    this->field_974 = jrt::New<class_3>();
    this->field_975 = jrt::New<class_3>();
    this->field_1010 = jrt::New<class_3>();
    this->field_1000 = jrt::New<class_3>();
    this->field_1001 = jrt::New<class_3>();
    this->field_986 = 1;
    this->field_976 = jrt::New<class_60>();
    this->field_977 = jrt::New<class_82>();
    this->field_978 = jrt::New<class_11>();
    this->field_980 = jrt::New<class_25>();
    this->field_987 = -1;
    this->field_990 = this->field_969->method_333();
    this->field_983 = 2;
    this->field_994 = false;
    this->field_997 = true;
    this->field_1007 = false;
    this->field_1008 = jrt::Ref<class_91>(nullptr);
    this->field_1003 = class_21::method_180()->field_1140;
    Deep3dDebug::player = this->field_969;
    this->field_1004 = this->field_1003;
    class_70::field_968 = class_21::method_178()->field_878;
    class_70::field_966 = class_21::method_178()->field_877;
    class_70::field_967 = class_21::method_178()->field_879;
    this->field_999 = class_70::field_968 > 0;
    this->field_1005 = class_21::method_178()->field_870;
    this->field_1006 = class_21::method_178()->field_880;
    this->field_1005 = this->field_1005 + (float(this->field_1006) / 100.0f);
    this->field_1011 = class_43::method_381(9993);
    this->field_1011->field_1367 = 2;
    this->field_1012 = class_43::method_381(9997);
    this->field_1012->field_1367 = 2;
    this->field_971 = class_43::method_381(6768);
    this->field_971->field_1367 = 3;
    (jrt::New<class_103>())->method_879(jrt::Ref<class_102>(this->field_971));
    this->field_972 = jrt::New<class_5>(jrt::Ref<class_102>(this->field_1011), jrt::Ref<class_102>(this->field_971));
    this->field_972->field_53 = true;
    this->field_973 = jrt::New<class_104>();
    this->field_973->method_880(jrt::Ref<class_0>(this->field_972));
    this->field_1013 = (this->field_1003 - class_21::method_178()->field_889) << 3;
    this->field_1014 = (this->field_1003 - class_21::method_178()->field_890) << 3;
}

void class_70::method_648(jrt::Ref<class_108> var1) {
    this->field_970 = var1;
    jrt::Ref<jrt::Array<int32_t>> var2{};
    if ((var2 = class_90::method_789(var1->field_1344, ((class_21::method_178()->field_884) ? 1 : 0))) != nullptr) {
        var1->method_876(var2->at(0), var2->at(1));
        var1->method_877(int8_t(2));
    }
    var1->field_1341->method_491(0, 0, 0);
}

void class_70::method_649() {
    this->field_990 = this->field_969->method_333();
}

void class_70::method_650() {
    if (((!this->field_994) && this->field_999) && (this->field_993 >= 0)) {
        class_84::field_1122->method_770(7);
        this->field_993 = 0;
        this->field_983 = class_70::field_966;
        this->field_994 = true;
        this->field_970->method_849(this->field_1000);
        this->field_1001->method_9(this->field_1000);
    }
}

bool class_70::method_651() {
    return this->field_993 >= 0;
}

float class_70::method_652() {
    float var1{};
    if ((var1 = float(this->field_993) / float((class_70::field_967 / 6))) < 1.0f) {
        return var1;
    } else {
        return (var1 > 5.0f) ? (6.0f - var1) : 1.0f;
    }
}

float class_70::method_653() {
    float var1{};
    return ((var1 = float(this->field_993) / float(class_70::field_968)) > 0.0f) ? 1.0f : (1.0f + var1);
}

void class_70::method_654() {
    this->field_982 = jrt::Ref<class_18>(nullptr);
}

bool class_70::method_655() {
    return this->method_659() <= 0;
}

void class_70::method_656(int64_t var1) {
    if (this->field_987 >= 0) {
        this->field_969->method_352(this->field_987, var1, false);
    }
}

void class_70::method_657(jrt::Ref<class_9> var1, int32_t var2) {
    this->field_969->method_346(var1, var2);
    this->field_987 = 0;
}

void class_70::method_658(jrt::Ref<jrt::Array<jrt::Ref<class_9>>> var1, int32_t var2) {
    this->field_969->method_347(var1, var2);
    this->field_987 = 0;
}

int32_t class_70::method_659() {
    return this->field_969->field_363;
}

int32_t class_70::method_660() {
    return this->field_969->field_370;
}

void class_70::method_661() {
    this->field_987++;
    if (this->field_987 > (this->field_969->field_369 - 1)) {
        this->field_987 = 0;
    }
    class_21::method_178()->field_891 = this->field_987;
}

bool class_70::method_662() {
    return (((this->field_987 >= 0) && (this->field_969->field_359 != nullptr)) && (this->field_969->field_359->at(this->field_987) != nullptr)) && this->field_969->field_359->at(this->field_987)->at(0)->field_97;
}

int32_t class_70::method_663() {
    return this->field_969->method_350(this->field_987);
}

jrt::Ref<class_3> class_70::method_664() {
    return this->field_970->method_848(this->field_974);
}

float class_70::method_665() {
    return 1.0f - (float(class_16::method_97(0, (this->field_1004 - 15000))) / 15000.0f);
}

void class_70::method_666(bool var1) {
    this->field_969->field_375 = var1;
}

void class_70::method_667(jrt::Ref<class_91> var1) {
    this->field_1008 = var1;
    this->field_1009 = false;
    this->field_1007 = this->field_1008 != nullptr;
    if ((this->field_1008 != nullptr) && jrt::isInstance<class_97>(this->field_1008)) {
        this->field_1009 = true;
    }
}

bool class_70::method_668() {
    return this->field_1008 == this->field_981->field_276->at(1);
}

bool class_70::method_669() {
    return (this->field_981->field_276->at(0) != nullptr) ? (this->field_1008 == this->field_981->field_276->at(0)) : false;
}

void class_70::method_670(int32_t var1, int32_t var2, int32_t var3) {
    this->field_970->method_845(var1, var2, var3);
    this->field_969->field_377->method_476(var1, var2, var3);
}

void class_70::method_671(int64_t var1) {
    if (!this->field_991) {
        int32_t var3 = this->field_1003 - (this->field_970->method_853() >> 3);
        this->field_1004 = (var3 > 500) ? var3 : 500;
        this->field_1000 = this->field_970->method_849(this->field_1000);
        this->field_992 = var1;
        if ((this->field_993 < 0) && ((int64_t(this->field_993) + (int64_t(3) * var1)) > int64_t(0))) {
            class_69::method_633(4, jrt::Ref<class_70>(this));
            this->field_993 = 0;
        }
        this->field_993 = int32_t((int64_t(this->field_993) + var1));
        if (this->field_994) {
            if (this->field_993 > class_70::field_967) {
                this->field_983 = 2;
                this->field_994 = false;
                this->field_993 = -class_70::field_968;
            }
            if (this->field_980 != nullptr) {
                this->field_980->method_236(this->field_1000, int32_t(this->field_992));
                this->field_1001->method_9(this->field_1000);
            }
        }
        this->field_998 = false;
        if (this->field_997) {
            this->method_672(this->field_981->field_276);
            this->method_672(this->field_981->field_274);
            this->method_672(this->field_981->field_273);
        }
        if ((this->field_1007 && (this->field_1008 != nullptr)) && (!this->field_998)) {
            if (this->field_1009) {
                this->field_1008 = jrt::Ref<class_91>((jrt::cast<class_97>(this->field_1008))->field_1230->method_110());
            }
            if (this->field_1008 != nullptr) {
                this->field_975 = this->field_1008->method_799(this->field_975);
                this->field_975->method_17(this->field_970->method_848(this->field_1000));
                this->field_975->method_22();
                this->field_974->method_9(this->field_970->method_855(this->field_974));
                this->field_974->method_22();
                this->field_975->method_17(this->field_974);
                this->field_975->method_18(jrt::f2i((float(this->field_992) * 5.0f)));
                this->field_1010 = this->field_974->method_14(this->field_975, this->field_1010);
                this->field_1010->method_22();
                this->field_970->field_1341->method_512(this->field_1010);
                if ((this->field_984 == float(0)) && (this->field_985 == float(0))) {
                    this->method_677(int32_t(this->field_992));
                }
                this->field_970->method_847((int32_t(var1) * this->field_983));
            } else {
                this->method_667(jrt::Ref<class_91>(nullptr));
            }
        } else if (!this->field_998) {
            this->field_970->method_862(jrt::f2i((this->field_1005 * ((this->field_984 * float(int32_t(var1))) / float(3)))));
            this->field_995 = jrt::f2i((this->field_1005 * ((this->field_985 * float(int32_t(var1))) / float(3))));
            this->field_970->method_863(this->field_995);
            this->field_996 = this->field_996 + jrt::f2i((this->field_1005 * ((this->field_984 * float(int32_t(var1))) / float(3))));
            if ((this->field_984 == float(0)) && (this->field_985 == float(0))) {
                this->method_677(int32_t(this->field_992));
            } else if (org::deep3d::AnalogInput::active()) {
                int32_t deep3dLevel = org::deep3d::AnalogInput::levelRate(this->field_984, int32_t(this->field_992));
                if (deep3dLevel > 0) {
                    this->method_677(deep3dLevel);
                }
            }
            this->field_970->method_847((int32_t(var1) * this->field_983));
        }
        if (!this->field_998) {
            this->field_970->field_1364 = -this->field_986;
            if ((this->field_986 > 0) && (this->field_985 == float(0))) {
                this->field_986 = int32_t((int64_t(this->field_986) - (var1 / int64_t(5))));
            } else if ((int64_t(this->field_986) < ((-var1) / int64_t(5))) && (this->field_985 == float(0))) {
                this->field_986 = int32_t((int64_t(this->field_986) + (var1 / int64_t(5))));
            }
            this->field_984 = this->field_985 = float(0);
        }
        if (((this->field_1004 > class_21::method_178()->field_889) && (class_21::method_178()->field_871 > 0)) && (class_21::method_178()->field_873 > 0)) {
            this->field_988 += var1;
            if (this->field_988 > int64_t(class_21::method_178()->field_873)) {
                this->field_988 = int64_t(0);
                this->field_969->method_334();
            }
        }
        if (class_21::method_178()->field_883 && (this->field_969->field_363 < this->field_969->field_364)) {
            this->field_989 += var1;
            if (this->field_989 > int64_t(600)) {
                this->field_989 = int64_t(0);
                this->field_969->method_335();
            }
        }
        this->field_969->method_353(var1);
        this->field_976->method_547(var1, class_84::field_1110->field_40->field_1342, false);
        this->field_978->method_55(this->field_970->field_1341);
        this->field_969->field_377 = this->field_970->field_1341;
        this->field_1011->method_845(this->field_970->method_852(), this->field_1013, this->field_970->method_854());
        this->field_1012->method_845(this->field_970->method_852(), this->field_1014, this->field_970->method_854());
        if (this->field_982 != nullptr) {
            this->field_982->method_114(this->field_970->method_852(), this->field_970->method_853(), this->field_970->method_854());
        }
        if (!this->field_997) {
            if (this->field_980 != nullptr) {
                this->field_980->method_236(this->field_1000, int32_t(this->field_992));
                this->field_1001->method_9(this->field_1000);
            }
        } else {
            if (this->field_990 > this->field_969->method_333()) {
                class_84::method_736(110);
                this->field_990 = this->field_969->method_333();
            }
            this->field_1015 = false;
            if (this->field_1004 > (class_21::method_178()->field_890 + 200)) {
                this->field_974 = this->field_1012->method_848(this->field_974);
                this->field_972->field_45 = jrt::Ref<class_102>(this->field_1012);
                this->field_1015 = true;
            } else if (this->field_1004 < (class_21::method_178()->field_889 - 200)) {
                this->field_974 = this->field_1011->method_848(this->field_974);
                this->field_972->field_45 = jrt::Ref<class_102>(this->field_1011);
                this->field_1015 = true;
            }
            if (this->field_1004 > class_21::method_159()) {
                class_21::method_161(this->field_1004);
            } else if (this->field_1004 < class_21::method_160()) {
                class_21::method_162(this->field_1004);
            }
            if (this->field_1015) {
                this->field_971->method_870(class_84::field_1110->field_40->field_1341);
                this->field_971->method_847((-4200));
                this->deep3dCornerArrow();
                this->field_973->method_839(false);
            }
            if (this->field_1000->method_23() > 500000) {
                this->field_970->method_845(20000, this->field_1000->field_38, 20000);
            }
            if (this->method_655()) {
                this->method_678(var1);
            }
        }
    }
}

void class_70::method_672(jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var1) {
    if (var1 != nullptr) {
        for (int32_t var2 = 0; var2 < var1->length; var2++) {
            if ((var1->at(var2) != nullptr) && var1->at(var2)->method_807(this->field_970->method_848(this->field_975))) {
                this->field_975 = var1->at(var2)->method_808(this->field_970->method_848(this->field_975));
                this->field_975->field_37 += 100;
                if (this->field_975 != nullptr) {
                    this->field_974->method_9(this->field_970->method_855(this->field_974));
                    this->field_975->method_17(this->field_974);
                    this->field_975->method_18(jrt::f2i((float(this->field_992) * 5.0f)));
                    this->field_1000 = this->field_974->method_14(this->field_975, this->field_1000);
                    this->field_1000->method_22();
                    this->field_970->field_1341->method_512(this->field_1000);
                    this->field_970->method_847((int32_t(this->field_992) * this->field_983));
                    this->method_677(int32_t(this->field_992));
                    this->field_998 = true;
                    return;
                }
            }
        }
    }
}

void class_70::method_673(int64_t var1) {
    this->field_985 = float(1);
    if (this->field_986 < 384) {
        this->field_986 = int32_t((int64_t(this->field_986) + var1));
    }
}

void class_70::method_674(int64_t var1) {
    this->field_985 = float((-1));
    if (this->field_986 > (-384)) {
        this->field_986 = int32_t((int64_t(this->field_986) - var1));
    }
}

void class_70::steerAnalog(int64_t var1, float yaw, float pitch) {
    this->field_985 = yaw;
    /* the bank follows the turn both ways: into it at the keys' rate, out
       of it at the rate it levels when the keys are released */
    float bank = 384.0f * yaw;
    if (float(this->field_986) < bank) {
        this->field_986 = int32_t(java::lang::Math::min(bank, float(int64_t(this->field_986) + (yaw > 0.0f ? var1 : var1 / int64_t(5)))));
    } else if (float(this->field_986) > bank) {
        this->field_986 = int32_t(java::lang::Math::max(bank, float(int64_t(this->field_986) - (yaw < 0.0f ? var1 : var1 / int64_t(5)))));
    }
    this->field_984 = pitch;
}

void class_70::method_675(int64_t var1) {
    this->field_984 = float(1);
}

void class_70::method_676(int64_t var1) {
    this->field_984 = float((-1));
}

void class_70::method_677(int32_t var1) {
    this->field_1002->method_469();
    var1 = class_16::method_98(var1, 60);
    this->field_974 = this->field_970->method_856(this->field_974);
    this->field_975 = this->field_970->method_858(this->field_975);
    this->field_1002->method_469();
    int32_t var2 = this->field_1002->method_483()->method_12(this->field_975);
    if (this->field_1002->method_483()->method_12(this->field_974) < 0) {
        if (var2 > 0) {
            this->field_970->method_861(((-var1) >> 1));
        } else {
            this->field_970->method_861((var1 >> 1));
        }
    } else {
        if (((var2 > 128) && (var2 < 3968)) || ((var2 < (-128)) && (var2 > (-3968)))) {
            if (var2 < 0) {
                this->field_970->method_861((var1 >> 1));
                return;
            }
            this->field_970->method_861(((-var1) >> 1));
        }
    }
}

void class_70::method_678(int64_t var1) {
    if (this->field_969->field_375) {
        this->field_979->method_741(this->field_970->method_852(), this->field_970->method_853(), this->field_970->method_854());
    }
    this->field_969->field_375 = false;
}

void class_70::method_679() {
    this->field_969->method_351(this->field_987);
}

void class_70::method_680() {
    this->field_981 = jrt::Ref<class_26>(nullptr);
    if (this->field_979 != nullptr) {
        this->field_979->method_738();
    }
    this->field_979 = jrt::Ref<class_85>(nullptr);
    if (this->field_978 != nullptr) {
        this->field_978->method_56();
    }
    this->field_978 = jrt::Ref<class_11>(nullptr);
    if (this->field_976 != nullptr) {
        this->field_976->method_546();
    }
    this->field_976 = jrt::Ref<class_60>(nullptr);
    this->field_977 = jrt::Ref<class_82>(nullptr);
    if (this->field_980 != nullptr) {
        this->field_980->method_235();
    }
    this->field_980 = jrt::Ref<class_25>(nullptr);
    java::lang::System::gc();
}

void class_70::method_681(bool var1) {
    if (this->method_655()) {
        this->field_979->method_742(this->field_992);
        this->field_976->method_548();
    } else {
        class_4::deep3dKind = 4;
        class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_970));
        class_4::deep3dKind = 0;
        if (this->field_1015) {
            class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_971));
        }
        this->field_976->method_548();
        if ((!this->field_991) && var1) {
            class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1011));
            class_84::field_1110->method_25(jrt::Ref<class_102>(this->field_1012));
        }
        if (this->field_994 || (!this->field_997)) {
            this->field_980->method_238();
        }
    }
}

void class_70::method_682(bool var1, jrt::Ref<class_106> var2) {
    if (((!this->method_655()) && (!this->field_991)) && var1) {
        this->field_978->method_57(var2);
    }
}

void class_70::__dumpFields(jrt::Dumper& d) {
    d.f("field_1000", this->field_1000);
    d.f("field_1001", this->field_1001);
    d.f("field_1002", this->field_1002);
    d.f("field_1003", this->field_1003);
    d.f("field_1004", this->field_1004);
    d.f("field_1005", this->field_1005);
    d.f("field_1006", this->field_1006);
    d.f("field_1007", this->field_1007);
    d.f("field_1008", this->field_1008);
    d.f("field_1009", this->field_1009);
    d.f("field_1010", this->field_1010);
    d.f("field_1011", this->field_1011);
    d.f("field_1012", this->field_1012);
    d.f("field_1013", this->field_1013);
    d.f("field_1014", this->field_1014);
    d.f("field_1015", this->field_1015);
    d.f("field_969", this->field_969);
    d.f("field_970", this->field_970);
    d.f("field_971", this->field_971);
    d.f("field_972", this->field_972);
    d.f("field_973", this->field_973);
    d.f("field_974", this->field_974);
    d.f("field_975", this->field_975);
    d.f("field_976", this->field_976);
    d.f("field_977", this->field_977);
    d.f("field_978", this->field_978);
    d.f("field_979", this->field_979);
    d.f("field_980", this->field_980);
    d.f("field_981", this->field_981);
    d.f("field_982", this->field_982);
    d.f("field_983", this->field_983);
    d.f("field_984", this->field_984);
    d.f("field_985", this->field_985);
    d.f("field_986", this->field_986);
    d.f("field_987", this->field_987);
    d.f("field_988", this->field_988);
    d.f("field_989", this->field_989);
    d.f("field_990", this->field_990);
    d.f("field_991", this->field_991);
    d.f("field_992", this->field_992);
    d.f("field_993", this->field_993);
    d.f("field_994", this->field_994);
    d.f("field_995", this->field_995);
    d.f("field_996", this->field_996);
    d.f("field_997", this->field_997);
    d.f("field_998", this->field_998);
    d.f("field_999", this->field_999);
}

// Deep3D-PC: the arrow that points back into the sector's depth range sits
// in the bottom-left corner of the view rather than under the reticle. It is
// 4200 ahead of the camera; this moves it across the view plane there, by the
// camera's own projection (so any field of view or aspect).
void class_70::deep3dCornerArrow() {
    float fovy = 44.0f, aspect = class_84::field_1121 > 0 ? float(class_84::field_1120) / float(class_84::field_1121) : 1.0f;
    jrt::Ref<class_107> cam = jrt::cast<class_107>(class_84::field_1110->field_40);
    if (cam != nullptr && cam->field_1362 != nullptr) {
        jrt::Ref<jrt::Array<float>> p = jrt::newArray<float>(4);
        if (cam->field_1362->getProjection(p) == javax::microedition::m3g::Camera::PERSPECTIVE) {
            fovy = p->at(0);
            aspect = p->at(1);
        }
    }
    float halfH = 4200.0f * float(std::tan(double(fovy) * 3.141592653589793 / 360.0));
    int32_t ox = int32_t(-0.80f * halfH * aspect);
    int32_t oy = int32_t(-0.62f * halfH);
    jrt::Ref<class_57> m = this->field_971->field_1341;
    m->field_698 += ((m->field_689 * ox) >> 12) + ((m->field_692 * oy) >> 12);
    m->field_699 += ((m->field_690 * ox) >> 12) + ((m->field_693 * oy) >> 12);
    m->field_700 += ((m->field_691 * ox) >> 12) + ((m->field_694 * oy) >> 12);
    this->field_971->method_847(0);   // marks the transform changed
}
