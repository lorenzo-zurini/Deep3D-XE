// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_7::field_56{};
jrt::Ref<class_3> class_7::field_57{};
jrt::Ref<class_3> class_7::field_58{};
jrt::Ref<java::util::Random> class_7::field_59{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> class_7::field_60{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> class_7::field_61{};
int32_t class_7::field_68{};
int32_t class_7::field_69{};
int32_t class_7::field_70{};
jrt::Ref<class_57> class_7::field_71{};

void class_7::__clinit() {
    class_7::field_56 = jrt::New<class_3>(0, 0, 6309);
    class_7::field_57 = jrt::New<class_3>(0, 0, 6309);
    class_7::field_58 = jrt::New<class_3>(0, 4500, 0);
    class_7::field_59 = org::deep3d::Det::random(4);
    class_7::field_60 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(0), int16_t(2048)}), jrt::arrayOf<int16_t>({int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(682), int16_t(2048), int16_t((-682))}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(1024), int16_t(2048), int16_t(3072)}), jrt::arrayOf<int16_t>({int16_t(682), int16_t((-682))}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(1024), int16_t(3072)})});
    class_7::field_61 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(3301), int16_t(3302), int16_t(3304), int16_t(3309), int16_t(3310), int16_t(3305), int16_t(3306)}), jrt::arrayOf<int16_t>({int16_t(3301), int16_t(3302), int16_t(3304), int16_t(3309), int16_t(3310)})});
    class_7::field_71 = jrt::New<class_57>();
}

void class_7::method_36() {
    class_7::field_68 = 0;
    class_7::field_69 = 0;
    class_7::field_70 = 0;
}

int32_t class_7::method_37() {
    return class_7::field_68;
}

void class_7::__init(jrt::Ref<class_86> var1) {
    class_7::field_59->setSeed(int64_t(((var1->field_1134 + var1->field_1140) + var1->field_1139)));
    class_7::field_69 = 20;
    this->field_62 = (class_7::field_59->nextInt(2) == 0) ? 3307 : 3308;
    this->field_67 = class_43::method_381(this->field_62);
    this->field_67->method_864(0, 2048, 0);
    this->field_67->field_1367 = 2;
    this->field_63 = (this->field_62 == 3307) ? class_7::field_60->at(4) : class_7::field_60->at(5);
    this->field_64 = class_7::field_61->at(1);
    class_7::field_69--;
    class_7::field_68 = 1;
    this->method_38();
}

void class_7::__init(int32_t var1) {
    class_7::field_69--;
    this->field_62 = var1;
    {
        switch (var1) {
        case 3301:
            ;
        case 3302:
            this->field_63 = class_7::field_60->at(0);
            this->field_64 = class_7::field_61->at(0);
            return;
        case 3304:
            ;
        case 3309:
            ;
        case 3310:
            this->field_63 = class_7::field_60->at(1);
            this->field_64 = jrt::Ref<jrt::Array<int16_t>>(nullptr);
            return;
        case 3305:
            this->field_63 = class_7::field_60->at(2);
            this->field_64 = class_7::field_61->at(1);
            return;
        case 3306:
            this->field_63 = class_7::field_60->at(3);
            this->field_64 = class_7::field_61->at(1);
            return;
        case 3307:
            this->field_63 = class_7::field_60->at(4);
            this->field_64 = class_7::field_61->at(1);
            return;
        case 3308:
            this->field_63 = class_7::field_60->at(5);
            this->field_64 = class_7::field_61->at(1);
        case 3303:
            ;
        }
    }
}

void class_7::method_38() {
    if (this->field_64 != nullptr) {
        bool var1 = (((this->field_62 == 3307) || (this->field_62 == 3308)) || (this->field_62 == 3305)) || (this->field_62 == 3306);
        this->field_65 = jrt::newArray<jrt::Ref<class_7>>((var1 ? (this->field_63->length + 2) : this->field_63->length));
        jrt::Ref<jrt::Array<bool>> var2 = jrt::newArray<bool>(this->field_65->length);
        for (int32_t var3 = 0; var3 < var2->length; var3++) {
            if (((!var1) || (var3 > (this->field_65->length - 3))) || ((this->field_62 != 3307) && (this->field_62 != 3308))) {
                if (((this->field_62 != 3300) && (this->field_62 != 3311)) && (this->field_62 != 3303)) {
                    var2->at(var3) = class_7::field_59->nextInt(100) < this->method_39(this->field_62);
                    var2->at(0) = false;
                } else {
                    var2->at(var3) = false;
                }
            } else {
                var2->at(var3) = true;
            }
        }
        for (int32_t var6 = 0; var6 < this->field_65->length; var6++) {
            if (class_7::field_69 <= 0) {
                return;
            }
            if (var2->at(var6)) {
                int32_t var4 = 3301;
                if (var1 && (var6 > (this->field_65->length - 3))) {
                    if (((((var6 == (this->field_65->length - 1)) && this->field_66) && (this->field_62 != 3307)) && (this->field_62 != 3308)) || (((!this->field_66) && (this->field_62 != 3307)) && (this->field_62 != 3308))) {
                        return;
                    }
                    if ((this->field_62 != 3307) && (this->field_62 != 3305)) {
                        var4 = 3306;
                    } else {
                        var4 = 3305;
                    }
                    if (class_7::field_59->nextInt(2) == 0) {
                        if (var6 == (this->field_65->length - 1)) {
                            if ((this->field_66 && (this->field_62 != 3307)) && (this->field_62 != 3308)) {
                                return;
                            }
                            var4 = (class_7::field_59->nextInt(2) == 0) ? 3311 : 3303;
                        } else {
                            if (((!this->field_66) && (this->field_62 != 3307)) && (this->field_62 != 3308)) {
                                return;
                            }
                            var4 = 3300;
                        }
                    }
                } else {
                    bool var5 = false;
                    if (this->field_64 != class_7::field_61->at(1)) {
                        var4 = (class_7::field_59->nextInt(2) == 0) ? 3305 : 3306;
                    }
                    for (; !var5; var4 = int32_t(this->field_64->at(class_7::field_59->nextInt(this->field_64->length)))) {
                        if (class_7::field_59->nextInt(100) < this->method_39(var4)) {
                            var5 = true;
                        }
                    }
                }
                this->field_65->at(var6) = jrt::New<class_7>(var4);
                this->field_65->at(var6)->field_66 = var6 != (this->field_65->length - 1);
                this->field_65->at(var6)->field_67 = class_43::method_381(this->field_65->at(var6)->field_62);
                this->field_65->at(var6)->field_67->field_1367 = 2;
                this->field_65->at(var6)->field_67->method_870(this->field_67->field_1341);
                jrt::Ref<class_3> var7 = jrt::New<class_3>();
                if (var1 && (var6 > (this->field_65->length - 3))) {
                    var7->method_10(0, ((var6 == (this->field_65->length - 1)) ? class_7::field_58->field_38 : (-class_7::field_58->field_38)), 0);
                } else {
                    this->field_65->at(var6)->field_67->method_860(0, (2048 - int32_t(this->field_63->at(var6))), 0);
                    class_7::field_71->method_469();
                    class_7::field_71->method_490(this->field_67->method_866());
                    class_7::field_71->method_486(0, (-int32_t(this->field_63->at(var6))), 0);
                    if ((this->field_62 != 3305) && (this->field_62 != 3307)) {
                        var7 = class_7::field_71->method_508(class_7::field_57, var7);
                    } else {
                        var7 = class_7::field_71->method_508(class_7::field_56, var7);
                    }
                }
                this->field_65->at(var6)->field_67->method_844(var7);
                class_7::field_68++;
                this->field_65->at(var6)->method_38();
            }
        }
    }
}

int32_t class_7::method_39(int32_t var1) {
    {
        switch (var1) {
        case 3301:
            ;
        case 3302:
            return 90;
        case 3303:
            ;
        default:
            return 50;
        case 3304:
            ;
        case 3309:
            ;
        case 3310:
            return 30;
        case 3305:
            return 70;
        case 3306:
            return 50;
        case 3307:
            return 70;
        case 3308:
            return 70;
        }
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_108>>> class_7::method_40(jrt::Ref<jrt::Array<jrt::Ref<class_108>>> var1) {
    var1->at(class_7::field_70) = this->field_67;
    if (this->field_65 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_65->length; var2++) {
            if ((this->field_65->at(var2) != nullptr) && (this->field_65->at(var2)->field_67 != nullptr)) {
                class_7::field_70++;
                this->field_65->at(var2)->method_40(var1);
            }
        }
    }
    return var1;
}

void class_7::__dumpFields(jrt::Dumper& d) {
    d.f("field_62", this->field_62);
    d.f("field_63", this->field_63);
    d.f("field_64", this->field_64);
    d.f("field_65", this->field_65);
    d.f("field_66", this->field_66);
    d.f("field_67", this->field_67);
}

