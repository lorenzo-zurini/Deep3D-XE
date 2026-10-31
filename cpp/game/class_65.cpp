// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_65::__clinit() {
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> var10000 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({0, 850, 1500}), jrt::arrayOf<int32_t>({1000, (-300), 3000}), jrt::arrayOf<int32_t>({0, 2000, 0})});
    var10000 = jrt::arrayOf<jrt::Ref<jrt::Array<int32_t>>>({jrt::arrayOf<int32_t>({0, 650, 0}), jrt::arrayOf<int32_t>({0, 0, 0}), jrt::arrayOf<int32_t>({0, 0, 0})});
}

void class_65::__init(int32_t var1) {
    class_61::__init();
    this->field_832 = jrt::New<class_3>();
    this->field_831 = var1;
}

void class_65::method_552() {
    if (this->field_829 != nullptr) {
        this->field_829->method_680();
    }
    this->field_829 = jrt::Ref<class_70>(nullptr);
    this->field_825 = jrt::Ref<class_106>(nullptr);
    if (this->field_830 != nullptr) {
        this->field_830->method_271();
    }
    this->field_830 = jrt::Ref<class_26>(nullptr);
    if (this->field_828 != nullptr) {
        this->field_828->field_45 = jrt::Ref<class_102>(nullptr);
        this->field_828->field_48 = jrt::Ref<class_102>(nullptr);
    }
    this->field_828 = jrt::Ref<class_5>(nullptr);
    if (this->field_827 != nullptr) {
        this->field_827->method_368(jrt::Ref<class_102>(nullptr));
        this->field_827->method_369(jrt::Ref<class_102>(nullptr));
    }
    this->field_827 = jrt::Ref<class_42>(nullptr);
    this->field_824 = jrt::Ref<class_104>(nullptr);
    this->field_823 = false;
    this->field_832 = jrt::Ref<class_3>(nullptr);
    this->field_835 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    java::lang::System::gc();
}

void class_65::method_551() {
    {
        try {
            if (this->field_831 == 1) {
                if (class_21::method_180()->field_1143 != nullptr) {
                    jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var1 = class_21::method_180()->field_1143;
                    this->field_835 = jrt::newArray<jrt::Ref<class_108>>(var1->length);
                    for (int32_t var2 = 0; var2 < this->field_835->length; var2++) {
                        this->field_835->at(var2) = class_43::method_381(int32_t(class_90::field_1205->at(var1->at(var2)->field_863)));
                    }
                    this->field_825 = class_106::method_886(class_84::field_1120, class_84::field_1121, 800, 100, 4194304);
                    this->field_825->method_843(0, 1000, (-1400));
                    this->field_825->method_860(400, 2048, 0);
                    this->field_836 = jrt::New<class_103>();
                    this->field_836->method_879(jrt::Ref<class_102>(this->field_825));
                }
            } else {
                if (this->field_830 == nullptr) {
                    this->field_830 = jrt::New<class_26>(this->field_831);
                }
                if (!this->field_830->method_240()) {
                    return;
                }
                this->field_829 = this->field_830->field_272;
                if (this->field_829 != nullptr) {
                    this->field_829->method_666(false);
                    this->field_834 = this->field_829->field_976;
                } else {
                    this->field_834 = jrt::New<class_60>();
                }
                this->field_833 = 0;
                this->field_826 = jrt::New<class_39>(class_84::field_1120, class_84::field_1121, 0);
                {
                    switch (this->field_831) {
                    case 0:
                        class_84::field_1110->method_24(this->field_826->field_388);
                        break;
                    case 1:
                        this->field_825->method_864(380, 2048, 0);
                        break;
                    case 2:
                        this->field_825->method_864(0, 1024, 0);
                        class_84::field_1110->method_24(this->field_825);
                    }
                }
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
    java::lang::System::gc();
    this->field_818 = org::deep3d::Det::millis();
    this->field_819 = org::deep3d::Det::millis();
    this->field_823 = true;
}

bool class_65::method_553() {
    return this->field_823;
}

void class_65::method_568(int32_t var1, int32_t var2) {
    this->field_830->field_274->at(var1)->field_1226 = class_43::method_381(var2);
    this->field_830->field_274->at(var1)->field_1226->field_1367 = 2;
}

void class_65::method_569(int32_t var1) {
    this->field_833 = var1;
    if (this->field_825 == nullptr) {
        this->field_825 = class_106::method_886(class_84::field_1120, class_84::field_1121, 800, 100, 4194304);
        this->field_825->method_843(0, 1000, (-2200));
        this->field_825->method_860(400, 2048, 0);
        this->field_836 = jrt::New<class_103>();
        this->field_836->method_879(jrt::Ref<class_102>(this->field_825));
        this->field_836->method_859(int16_t(2));
    }
    this->field_836->method_846(this->field_830->field_274->at(this->field_833)->method_799(this->field_832));
    class_84::field_1110->method_24(this->field_825);
}

void class_65::method_570() {
    class_84::field_1110->method_24(this->field_826->field_388);
}

void class_65::method_571() {
    this->method_549(0);
}

void class_65::method_549(int32_t var1) {
    if (this->field_823) {
        this->field_818 = org::deep3d::Det::millis();
        this->field_820 = this->field_818 - this->field_819;
        this->field_819 = this->field_818;
        this->field_821 = this->field_821 + this->field_820;
        this->field_822 = int32_t((int64_t(this->field_822) + this->field_820));
        this->field_826->method_364(org::deep3d::Det::millis());
        if (this->field_836 != nullptr) {
            this->field_836->method_846(this->field_830->field_274->at(this->field_833)->method_799(this->field_832));
            if ((var1 & 2) != 0) {
                this->field_836->method_860((org::deep3d::Step::exact() ? int32_t(this->field_820) : org::deep3d::Step::share(33.0, this->deep3dTurn[0])), 0, 0);
            }
            if ((var1 & 64) != 0) {
                this->field_836->method_860((org::deep3d::Step::exact() ? (-int32_t(this->field_820)) : org::deep3d::Step::share(-33.0, this->deep3dTurn[0])), 0, 0);
            }
            if ((var1 & 4) != 0) {
                this->field_836->method_860(0, (org::deep3d::Step::exact() ? int32_t(this->field_820) : org::deep3d::Step::share(33.0, this->deep3dTurn[1])), 0);
            }
            if ((var1 & 32) != 0) {
                this->field_836->method_860(0, (org::deep3d::Step::exact() ? (-int32_t(this->field_820)) : org::deep3d::Step::share(-33.0, this->deep3dTurn[1])), 0);
            }
        }
        if (this->field_834 != nullptr) {
            this->field_834->method_547(this->field_820, class_84::field_1110->field_40->field_1342, true);
        }
        this->method_572();
    }
}

void class_65::method_572() {
    {
        try {
            if (this->field_831 != 1) {
                this->field_830->method_267(this->field_820);
                this->field_830->method_265(this->field_820);
                if (this->field_824 != nullptr) {
                    this->field_824->method_839(true);
                }
                this->field_834->method_548();
            }
            class_84::field_1111->method_683(class_84::field_1117);
            class_84::field_1110->method_27(org::deep3d::Det::millis());
            class_84::field_1111->method_685();
            class_84::field_1111->method_684(class_84::field_1117);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                class_84::field_1111->method_684(class_84::field_1117);
                var2->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_65::method_550(int32_t var1) {
}

void class_65::__dumpFields(jrt::Dumper& d) {
    class_61::__dumpFields(d);
    d.f("field_818", this->field_818);
    d.f("field_819", this->field_819);
    d.f("field_820", this->field_820);
    d.f("field_821", this->field_821);
    d.f("field_822", this->field_822);
    d.f("field_823", this->field_823);
    d.f("field_824", this->field_824);
    d.f("field_825", this->field_825);
    d.f("field_826", this->field_826);
    d.f("field_827", this->field_827);
    d.f("field_828", this->field_828);
    d.f("field_829", this->field_829);
    d.f("field_830", this->field_830);
    d.f("field_831", this->field_831);
    d.f("field_832", this->field_832);
    d.f("field_833", this->field_833);
    d.f("field_834", this->field_834);
    d.f("field_835", this->field_835);
    d.f("field_836", this->field_836);
}

