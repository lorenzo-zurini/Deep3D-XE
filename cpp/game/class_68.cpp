// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_68::__clinit() {
}

void class_68::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, float var6) {
    this->field_863 = var1;
    this->field_864 = var2;
    this->field_866 = var3;
    this->field_867 = 0;
    this->field_868 = var4;
    this->field_865 = var4;
    this->field_869 = var5;
    this->field_870 = var6;
    this->field_885 = jrt::newArray<jrt::Ref<class_19>>(var5);
    this->field_886 = jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
    this->field_884 = false;
    this->method_618();
}

int32_t class_68::method_603() {
    return ((this->field_863 == 10) && class_14::method_69()) ? 50000 : this->field_868;
}

int32_t class_68::method_604() {
    return (this->field_864 + this->field_871) + this->field_872;
}

bool class_68::method_605() {
    return this->field_877 > 0;
}

int32_t class_68::method_606() {
    return jrt::f2i((275.0f + (float(jrt::f2i((275.0f * float(this->field_881)))) / 100.0f)));
}

int32_t class_68::method_607() {
    return this->field_866 + this->field_874;
}

void class_68::method_608(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    this->field_886 = var1;
    this->field_867 = 0;
    for (int32_t var2 = 0; var2 < this->field_886->length; var2++) {
        this->field_867 = this->field_867 + this->field_886->at(var2)->field_1490;
    }
    this->method_618();
}

bool class_68::method_609(int32_t var1) {
    if (this->field_885 == nullptr) {
        return false;
    } else {
        for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
            if ((this->field_885->at(var2) != nullptr) && (this->field_885->at(var2)->field_166 == var1)) {
                return true;
            }
        }
        return false;
    }
}

bool class_68::method_610(int32_t var1, int32_t var2) {
    bool var3 = false;
    for (int32_t var4 = 0; var4 < this->field_886->length; var4++) {
        if (this->field_886->at(var4)->field_1480 == var1) {
            this->field_886->at(var4)->method_926((-var2));
            if (this->field_886->at(var4)->field_1490 <= 0) {
                var3 = true;
            }
            break;
        }
    }
    if (var3) {
        this->method_611(class_120::method_934(this->field_886, true));
    } else {
        this->method_611(this->field_886);
    }
    return var3;
}

void class_68::method_611(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    this->field_886 = var1;
    this->field_867 = 0;
    if (var1 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_886->length; var2++) {
            this->field_867 = this->field_867 + this->field_886->at(var2)->field_1490;
        }
    }
    this->method_618();
}

bool class_68::method_612(int32_t var1) {
    return (this->field_867 + var1) <= (this->field_866 + this->field_874);
}

void class_68::method_613(jrt::Ref<class_120> var1) {
    this->method_614(jrt::arrayOf<jrt::Ref<class_120>>({var1}));
}

void class_68::method_614(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    this->method_611(class_120::method_936(this->field_886, var1));
}

void class_68::method_615(jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var1) {
    this->field_885 = var1;
    this->method_618();
}

void class_68::method_616(jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var1) {
    for (int32_t var2 = 0; var2 < var1->length; var2++) {
        this->method_617(var1->at(var2));
    }
}

void class_68::method_617(jrt::Ref<class_19> var1) {
    for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
        if (this->field_885->at(var2) == nullptr) {
            this->field_885->at(var2) = var1;
            break;
        }
    }
    this->method_618();
}

void class_68::method_618() {
    this->field_883 = false;
    this->field_871 = 0;
    this->field_873 = 0;
    this->field_874 = 0;
    this->field_876 = 0;
    this->field_878 = 0;
    this->field_877 = 0;
    this->field_879 = 0;
    this->field_880 = 0;
    this->field_881 = 0;
    this->field_872 = 0;
    this->field_882 = 0;
    this->field_889 = 22000;
    this->field_890 = 23000;
    this->field_887 = class_38::method_359(this->field_889);
    this->field_888 = class_38::method_359(this->field_890);
    this->method_619();
    this->field_865 = this->field_868;
    for (int32_t var1 = 0; var1 < this->field_885->length; var1++) {
        if (this->field_885->at(var1) != nullptr) {
            {
                switch ((this->field_885->at(var1)->field_165)) {
                case 0:
                    ;
                case 1:
                    this->field_882 = this->field_882 + this->field_885->at(var1)->field_171;
                case 2:
                    ;
                default:
                    break;
                case 3:
                    this->field_871 = this->field_885->at(var1)->field_171;
                    this->field_873 = this->field_885->at(var1)->field_172;
                    this->field_889 = this->field_885->at(var1)->field_173;
                    this->field_887 = class_38::method_359(this->field_889);
                    break;
                case 4:
                    this->field_872 = this->field_885->at(var1)->field_171;
                    this->field_890 = this->field_885->at(var1)->field_172;
                    this->field_888 = class_38::method_359(this->field_890);
                    break;
                case 5:
                    this->field_874 = this->field_874 + this->field_885->at(var1)->field_171;
                    break;
                case 6:
                    this->field_881 = this->field_885->at(var1)->field_171;
                    break;
                case 7:
                    this->field_880 = this->field_885->at(var1)->field_171;
                    break;
                case 8:
                    this->field_876 = this->field_885->at(var1)->field_171;
                    break;
                case 9:
                    this->field_877 = this->field_885->at(var1)->field_171;
                    this->field_879 = this->field_885->at(var1)->field_172;
                    this->field_878 = this->field_885->at(var1)->field_173;
                    break;
                case 10:
                    this->field_883 = true;
                }
            }
            this->field_865 = this->field_865 + this->field_885->at(var1)->method_116();
        }
    }
    this->field_875 = this->field_874;
    this->field_874 = jrt::f2i(((float(this->field_866) * float(this->field_874)) / 100.0f));
    this->field_865 = this->field_865 + this->method_621();
}

void class_68::method_619() {
    this->field_892 = jrt::newArray<jrt::Ref<class_19>>(this->method_624());
    int32_t var1 = 0;
    for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
        if ((this->field_885->at(var2) != nullptr) && this->field_885->at(var2)->method_118()) {
            this->field_892->at((var1++)) = this->field_885->at(var2);
        }
    }
}

int32_t class_68::method_620() {
    int32_t var1 = 0;
    if (this->field_886 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_886->length; var2++) {
            if (this->field_886->at(var2) != nullptr) {
                var1 += jrt::f2i((float(this->field_886->at(var2)->field_1490) * float(this->field_886->at(var2)->field_1486)));
            }
        }
    }
    this->field_886 = jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
    this->field_867 = 0;
    return var1;
}

int32_t class_68::method_621() {
    int32_t var1 = 0;
    if (this->field_886 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_886->length; var2++) {
            if (this->field_886->at(var2) != nullptr) {
                var1 += this->field_886->at(var2)->method_924();
            }
        }
    }
    return var1;
}

void class_68::method_622(jrt::Ref<class_19> var1) {
    for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
        if ((this->field_885->at(var2) != nullptr) && this->field_885->at(var2)->method_122(var1)) {
            this->field_885->at(var2) = jrt::Ref<class_19>(nullptr);
            break;
        }
    }
    this->method_618();
}

int32_t class_68::method_623() {
    int32_t var1 = 0;
    for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
        if (this->field_885->at(var2) != nullptr) {
            var1++;
        }
    }
    return var1;
}

int32_t class_68::method_624() {
    int32_t var1 = 0;
    for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
        if ((this->field_885->at(var2) != nullptr) && this->field_885->at(var2)->method_118()) {
            var1++;
        }
    }
    return var1;
}

bool class_68::method_625(int32_t var1) {
    if ((var1 != 5) && (var1 != 0)) {
        for (int32_t var2 = 0; var2 < this->field_885->length; var2++) {
            if ((this->field_885->at(var2) != nullptr) && (this->field_885->at(var2)->field_165 == var1)) {
                return false;
            }
        }
        return true;
    } else {
        return true;
    }
}

bool class_68::method_626() {
    for (int32_t var1 = 0; var1 < this->field_885->length; var1++) {
        if (this->field_885->at(var1) == nullptr) {
            return true;
        }
    }
    return false;
}

jrt::Ref<class_68> class_68::method_627() {
    return this->method_630();
}

void class_68::method_628() {
    this->field_868 = jrt::f2i((float(class_90::method_783()->at(this->field_863)->method_603()) / 1.25f));
}

void class_68::method_629() {
    if (class_21::method_180() != nullptr) {
        this->field_868 = class_90::method_783()->at(this->field_863)->method_603() - jrt::f2i(((float(class_21::method_180()->field_1139) / 100.0f) * float(class_90::method_783()->at(this->field_863)->method_603())));
    }
}

jrt::Ref<class_68> class_68::method_630() {
    return jrt::New<class_68>(this->field_863, this->field_864, this->field_866, this->field_868, this->field_869, this->field_870);
}

void class_68::__dumpFields(jrt::Dumper& d) {
    d.f("field_863", this->field_863);
    d.f("field_864", this->field_864);
    d.f("field_865", this->field_865);
    d.f("field_866", this->field_866);
    d.f("field_867", this->field_867);
    d.f("field_868", this->field_868);
    d.f("field_869", this->field_869);
    d.f("field_870", this->field_870);
    d.f("field_871", this->field_871);
    d.f("field_872", this->field_872);
    d.f("field_873", this->field_873);
    d.f("field_874", this->field_874);
    d.f("field_875", this->field_875);
    d.f("field_876", this->field_876);
    d.f("field_877", this->field_877);
    d.f("field_878", this->field_878);
    d.f("field_879", this->field_879);
    d.f("field_880", this->field_880);
    d.f("field_881", this->field_881);
    d.f("field_882", this->field_882);
    d.f("field_883", this->field_883);
    d.f("field_884", this->field_884);
    d.f("field_885", this->field_885);
    d.f("field_886", this->field_886);
    d.f("field_887", this->field_887);
    d.f("field_888", this->field_888);
    d.f("field_889", this->field_889);
    d.f("field_890", this->field_890);
    d.f("field_891", this->field_891);
    d.f("field_892", this->field_892);
}

