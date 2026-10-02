// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_120::__clinit() {
}

void class_120::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, jrt::Ref<jrt::Array<int8_t>> var8, jrt::Ref<jrt::Array<int8_t>> var9) {
    this->field_1480 = var1;
    this->field_1481 = var2;
    this->field_1482 = var3;
    this->field_1483 = var4;
    this->field_1485 = var5;
    this->field_1486 = var6;
    this->field_1487 = var7;
    this->field_1488 = var8;
    this->field_1489 = var9;
    this->field_1484 = var6 + ((var7 - var6) / 2);
    this->field_1492 = 0;
}

int32_t class_120::method_924() {
    return this->field_1484 * this->field_1490;
}

float class_120::method_925() {
    return float((this->field_1484 - this->field_1486)) / float((this->field_1487 - this->field_1486));
}

void class_120::method_926(int32_t var1) {
    this->field_1490 += var1;
}

void class_120::method_927(int32_t var1) {
    this->field_1491 += var1;
}

int32_t class_120::method_928(bool var1, int32_t var2) {
    if (((var1 && (this->field_1491 > 0)) && (class_21::method_182() >= this->field_1484)) && (var2 < class_21::method_178()->method_607())) {
        this->method_927((-1));
        this->method_926(1);
        return -this->field_1484;
    } else if ((!var1) && (this->field_1490 > 0)) {
        this->method_926((-1));
        this->method_927(1);
        return this->field_1484;
    } else {
        return 0;
    }
}

jrt::Ref<class_120> class_120::method_929(int32_t var1) {
    return this->method_930(var1, this->field_1484);
}

jrt::Ref<class_120> class_120::method_930(int32_t var1, int32_t var2) {
    jrt::Ref<class_120> var3{};
    (var3 = this->method_937())->field_1484 = var2;
    var3->field_1490 = var1;
    return var3;
}

bool class_120::method_931(int32_t var0, int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2) {
    if (var2 == nullptr) {
        return false;
    } else {
        for (int32_t var3 = 0; var3 < var2->length; var3++) {
            if ((var2->at(var3)->field_1480 == var0) && (var2->at(var3)->field_1490 >= var1)) {
                return true;
            }
        }
        return false;
    }
}

bool class_120::method_932(int32_t var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    return class_120::method_931(var0, 1, var1);
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_120::method_933(jrt::Ref<class_120> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1, int32_t var2) {
    jrt::Ref<jrt::Array<int8_t>> var3 = var0->field_1488;
    jrt::Ref<jrt::Array<int8_t>> var4 = var0->field_1489;
    for (int32_t var5 = 0; var5 < var3->length; var5++) {
        for (int32_t var6 = 0; var6 < var1->length; var6++) {
            if (var1->at(var6)->field_1480 == int32_t(var3->at(var5))) {
                var1->at(var6)->method_926(((-int32_t(var4->at(var5))) * var2));
                break;
            }
        }
    }
    return class_120::method_936(var1, jrt::arrayOf<jrt::Ref<class_120>>({var0->method_929(var2)}));
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_120::method_934(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, bool var1) {
    if (var0 == nullptr) {
        return jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2 = jrt::newArray<jrt::Ref<class_120>>(var0->length);
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var3 = jrt::newArray<jrt::Ref<class_120>>(var0->length);
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var0), 0, jrt::Ref<java::lang::Object>(var3), 0, var0->length);
        int32_t var4 = 0;
        for (int32_t var5 = 0; var5 < var3->length; var5++) {
            if (var1 && (var3->at(var5)->field_1490 > 0)) {
                var2->at(var4) = var3->at(var5)->method_929(var3->at(var5)->field_1490);
                var4++;
            } else if ((!var1) && (var3->at(var5)->field_1491 > 0)) {
                var2->at(var4) = var3->at(var5)->method_929(var3->at(var5)->field_1491);
                var4++;
            }
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var6 = jrt::newArray<jrt::Ref<class_120>>(var4);
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var2), 0, jrt::Ref<java::lang::Object>(var6), 0, var4);
        return var6;
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_120::method_935(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    int32_t var2 = (var0 == nullptr) ? 0 : var0->length;
    int32_t var3 = (var1 == nullptr) ? 0 : var1->length;
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var4 = jrt::newArray<jrt::Ref<class_120>>((var2 + var3));
    if ((var2 > 0) && (var3 == 0)) {
        for (int32_t var10 = 0; var10 < var0->length; var10++) {
            var4->at(var10) = var0->at(var10)->method_929(var0->at(var10)->field_1490);
        }
        return var4;
    } else if ((var3 > 0) && (var2 == 0)) {
        for (int32_t var9 = 0; var9 < var1->length; var9++) {
            var4->at(var9) = var1->at(var9)->method_929(0);
            var4->at(var9)->field_1491 = var1->at(var9)->field_1490;
        }
        return var4;
    } else if ((var3 == 0) && (var2 == 0)) {
        return jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
    } else {
        for (int32_t var5 = 0; var5 < var0->length; var5++) {
            var4->at(var5) = var0->at(var5)->method_929(var0->at(var5)->field_1490);
        }
        int32_t var8 = var2;
        for (int32_t var6 = 0; var6 < var1->length; var6++) {
            for (int32_t var7 = 0; var7 < var4->length; var7++) {
                if (var4->at(var7) == nullptr) {
                    var4->at(var7) = var1->at(var6)->method_929(0);
                    var4->at(var7)->field_1491 = var1->at(var6)->field_1490;
                    var8++;
                    break;
                }
                if (var1->at(var6)->method_938(var4->at(var7))) {
                    var4->at(var7) = var1->at(var6)->method_929(var4->at(var7)->field_1490);
                    var4->at(var7)->field_1491 = var1->at(var6)->field_1490;
                    break;
                }
            }
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var11 = jrt::newArray<jrt::Ref<class_120>>(var8);
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var4), 0, jrt::Ref<java::lang::Object>(var11), 0, var8);
        return var11;
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_120::method_936(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1) {
    if (var0 == nullptr) {
        return var1;
    } else if (var1 == nullptr) {
        return var0;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2 = jrt::newArray<jrt::Ref<class_120>>(var1->length);
        for (int32_t var3 = 0; var3 < var1->length; var3++) {
            var2->at(var3) = var1->at(var3);
        }
        jrt::Ref<java::lang::Object> var8 = jrt::Ref<java::lang::Object>(nullptr);
        int32_t var4 = var2->length;
        for (int32_t var5 = 0; var5 < var0->length; var5++) {
            for (int32_t var6 = 0; var6 < var2->length; var6++) {
                if ((var2->at(var6) != nullptr) && (var0->at(var5)->field_1480 == var2->at(var6)->field_1480)) {
                    var0->at(var5)->method_926(var2->at(var6)->field_1490);
                    var4--;
                    var2->at(var6) = jrt::Ref<class_120>(nullptr);
                }
            }
        }
        if (var4 <= 0) {
            return var0;
        } else {
            var8 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_120>>(var4));
            int32_t var10 = 0;
            for (int32_t var11 = 0; var11 < var2->length; var11++) {
                if (var2->at(var11) != nullptr) {
                    (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->at((var10++)) = jrt::Ref<java::lang::Object>(var2->at(var11));
                }
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var12 = jrt::newArray<jrt::Ref<class_120>>((var0->length + (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->length));
            for (int32_t var7 = 0; var7 < var0->length; var7++) {
                var12->at(var7) = var0->at(var7);
            }
            for (int32_t var13 = 0; var13 < (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->length; var13++) {
                var12->at((var13 + var0->length)) = jrt::cast<class_120>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->at(var13));
            }
            return var12;
        }
    }
}

jrt::Ref<class_120> class_120::method_937() {
    return jrt::New<class_120>(this->field_1480, this->field_1481, this->field_1482, this->field_1483, this->field_1485, this->field_1486, this->field_1487, this->field_1488, this->field_1489);
}

bool class_120::method_938(jrt::Ref<class_120> var1) {
    return (var1 == nullptr) ? false : (this->field_1480 == var1->field_1480);
}

jrt::Ref<java::lang::String> class_120::toString() {
    return jrt::concat(this->field_1480, JRT_LIT(u" "), this->field_1482, JRT_LIT(u" "), this->field_1485, JRT_LIT(u" "), this->field_1486, JRT_LIT(u" "), this->field_1487);
}

void class_120::__dumpFields(jrt::Dumper& d) {
    d.f("field_1480", this->field_1480);
    d.f("field_1481", this->field_1481);
    d.f("field_1482", this->field_1482);
    d.f("field_1483", this->field_1483);
    d.f("field_1484", this->field_1484);
    d.f("field_1485", this->field_1485);
    d.f("field_1486", this->field_1486);
    d.f("field_1487", this->field_1487);
    d.f("field_1488", this->field_1488);
    d.f("field_1489", this->field_1489);
    d.f("field_1490", this->field_1490);
    d.f("field_1491", this->field_1491);
    d.f("field_1492", this->field_1492);
}

