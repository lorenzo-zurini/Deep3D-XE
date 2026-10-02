// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_13::__clinit() {
}

void class_13::__init(jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> var1, int32_t var2, int64_t var3) {
    this->field_128 = jrt::newArray<int32_t>(3);
    this->field_129 = jrt::newArray<int32_t>(3);
    this->field_130 = jrt::New<class_3>();
    this->field_131 = jrt::New<class_3>();
    this->field_132 = 0;
    this->field_123 = 0;
    this->field_134 = var3;
    if ((var1 != nullptr) && (var1->at(var2) != nullptr)) {
        this->field_133 = jrt::newArray<jrt::Ref<jrt::Array<int32_t>>>((var1->at(var2)->length / 8));
        for (int32_t var5 = 0; var5 < (var1->at(var2)->length / 8); var5++) {
            this->field_133->at(var5) = jrt::newArray<int32_t>(8);
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->at(var2)), (var5 * 8), jrt::Ref<java::lang::Object>(this->field_133->at(var5)), 0, 8);
        }
        this->method_62();
    }
}

void class_13::method_62() {
    if (this->field_133 != nullptr) {
        this->field_123 = this->field_133->length;
        this->field_120 = jrt::newArray<float>(((this->field_123 + 1) * 3));
        this->field_121 = jrt::newArray<float>(((this->field_123 + 1) * 3));
        this->field_122 = jrt::newArray<float>((this->field_123 + 1));
        this->field_125 = jrt::newArray<float>(((this->field_123 + 1) * 3));
        this->field_126 = jrt::newArray<float>(((this->field_123 + 1) * 3));
        this->field_127 = jrt::newArray<float>(3);
        this->method_66();
        this->method_65();
    }
}

void class_13::method_63(int64_t var1) {
    if (this->field_123 >= 2) {
        if (var1 > this->field_134) {
            var1 = ([&]() { int64_t __v1 = var1; return (jrt::rem(__v1, this->field_134)); }());
        }
        if (this->field_123 == 2) {
            this->method_64((float(var1) / float(this->field_133->at(1)->at(0))), 0);
        } else {
            for (int32_t var3 = this->field_123 - 1; var3 >= 0; var3--) {
                if (int64_t(this->field_133->at(var3)->at(0)) < var1) {
                    float var4{};
                    if (var3 == 0) {
                        var4 = float((var1 - int64_t(this->field_133->at(var3)->at(0)))) / float((this->field_133->at((var3 + 1))->at(0) - this->field_133->at(var3)->at(0)));
                    } else if (var3 == (this->field_123 - 1)) {
                        var4 = float((var1 - int64_t(this->field_133->at(var3)->at(0)))) / float((this->field_134 - int64_t(this->field_133->at(var3)->at(0))));
                    } else {
                        var4 = float((var1 - int64_t(this->field_133->at(var3)->at(0)))) / float((this->field_133->at((var3 + 1))->at(0) - this->field_133->at(var3)->at(0)));
                    }
                    this->method_64(var4, var3);
                    return;
                }
            }
        }
    }
}

void class_13::method_64(float var1, int32_t var2) {
    float var3{};
    float var4 = (var3 = var1 * var1) * var1;
    float var5 = ((2.0f * var4) - (3.0f * var3)) + 1.0f;
    float var6 = (var4 - (2.0f * var3)) + var1;
    float var7 = ((-2.0f) * var4) + (3.0f * var3);
    float var8 = var4 - var3;
    this->field_128->at(0) = this->field_133->at(var2)->at(1);
    this->field_128->at(1) = this->field_133->at(var2)->at(2);
    this->field_128->at(2) = this->field_133->at(var2)->at(3);
    if (var2 == (this->field_133->length - 1)) {
        this->field_129->at(0) = this->field_133->at(0)->at(1);
        this->field_129->at(1) = this->field_133->at(0)->at(2);
        this->field_129->at(2) = this->field_133->at(0)->at(3);
    } else {
        this->field_129->at(0) = this->field_133->at((var2 + 1))->at(1);
        this->field_129->at(1) = this->field_133->at((var2 + 1))->at(2);
        this->field_129->at(2) = this->field_133->at((var2 + 1))->at(3);
    }
    this->field_130->field_37 = jrt::f2i(((((var5 * float(this->field_128->at(0))) + (var6 * this->field_120->at((var2 * 3)))) + (var7 * float(this->field_129->at(0)))) + (var8 * this->field_120->at(((var2 + 1) * 3)))));
    this->field_130->field_38 = jrt::f2i(((((var5 * float(this->field_128->at(1))) + (var6 * this->field_120->at(((var2 * 3) + 1)))) + (var7 * float(this->field_129->at(1)))) + (var8 * this->field_120->at((((var2 + 1) * 3) + 1)))));
    this->field_130->field_39 = jrt::f2i(((((var5 * float(this->field_128->at(2))) + (var6 * this->field_120->at(((var2 * 3) + 2)))) + (var7 * float(this->field_129->at(2)))) + (var8 * this->field_120->at((((var2 + 1) * 3) + 2)))));
    this->field_128->at(0) = this->field_133->at(var2)->at(4);
    this->field_128->at(1) = this->field_133->at(var2)->at(5);
    this->field_128->at(2) = this->field_133->at(var2)->at(6);
    if (var2 == (this->field_133->length - 1)) {
        this->field_129->at(0) = this->field_133->at(0)->at(4);
        this->field_129->at(1) = this->field_133->at(0)->at(5);
        this->field_129->at(2) = this->field_133->at(0)->at(6);
    } else {
        this->field_129->at(0) = this->field_133->at((var2 + 1))->at(4);
        this->field_129->at(1) = this->field_133->at((var2 + 1))->at(5);
        this->field_129->at(2) = this->field_133->at((var2 + 1))->at(6);
    }
    this->field_131->field_37 = jrt::f2i(((((var5 * float(this->field_128->at(0))) + (var6 * this->field_121->at((var2 * 3)))) + (var7 * float(this->field_129->at(0)))) + (var8 * this->field_121->at(((var2 + 1) * 3)))));
    this->field_131->field_38 = jrt::f2i(((((var5 * float(this->field_128->at(1))) + (var6 * this->field_121->at(((var2 * 3) + 1)))) + (var7 * float(this->field_129->at(1)))) + (var8 * this->field_121->at((((var2 + 1) * 3) + 1)))));
    this->field_131->field_39 = jrt::f2i(((((var5 * float(this->field_128->at(2))) + (var6 * this->field_121->at(((var2 * 3) + 2)))) + (var7 * float(this->field_129->at(2)))) + (var8 * this->field_121->at((((var2 + 1) * 3) + 2)))));
    this->field_128->at(0) = this->field_133->at(var2)->at(7);
    if (var2 == (this->field_133->length - 1)) {
        this->field_129->at(0) = this->field_133->at(0)->at(7);
    } else {
        this->field_129->at(0) = this->field_133->at((var2 + 1))->at(7);
    }
    this->field_132 = jrt::f2i(((((var5 * float(this->field_128->at(0))) + (var6 * this->field_122->at(var2))) + (var7 * float(this->field_129->at(0)))) + (var8 * this->field_122->at((var2 + 1)))));
}

void class_13::method_65() {
    if (this->field_123 <= 1) {
        this->field_124 = 0.0f;
    } else {
        this->field_124 = 0.0f;
        for (int32_t var1 = 0; var1 < this->field_123; var1++) {
            int32_t var2 = 1;
            float var3 = 1.0f;
            for (float var4 = 0.0f; double(var3) > 0.005; var2 *= 2) {
                float var5 = 1.0f / float(var2);
                this->field_127->at(0) = float(this->field_133->at(var1)->at(1));
                this->field_127->at(1) = float(this->field_133->at(var1)->at(2));
                this->field_127->at(2) = float(this->field_133->at(var1)->at(3));
                this->field_125->at(var1) = 0.0f;
                for (int32_t var6 = 1; var6 <= var2; var6++) {
                    float var7 = float(var6) * var5;
                    this->method_64(var7, var1);
                    this->field_125->at(var1) = float((double(this->field_125->at(var1)) + java::lang::Math::sqrt(double(((((float(this->field_130->field_37) - this->field_127->at(0)) * (float(this->field_130->field_37) - this->field_127->at(0))) + ((float(this->field_130->field_38) - this->field_127->at(1)) * (float(this->field_130->field_38) - this->field_127->at(1)))) + ((float(this->field_130->field_39) - this->field_127->at(2)) * (float(this->field_130->field_39) - this->field_127->at(2))))))));
                    this->field_127->at(0) = float(this->field_130->field_37);
                    this->field_127->at(1) = float(this->field_130->field_38);
                    this->field_127->at(2) = float(this->field_130->field_39);
                }
                var3 = (this->field_125->at(var1) - var4) / this->field_125->at(var1);
                var4 = this->field_125->at(var1);
            }
            this->field_124 = this->field_124 + this->field_125->at(var1);
        }
        for (int32_t var8 = 0; var8 < this->field_123; var8++) {
            if (var8 == 0) {
                this->field_126->at(var8) = this->field_125->at(var8) / this->field_124;
            } else {
                this->field_126->at(var8) = this->field_126->at((var8 - 1)) + (this->field_125->at(var8) / this->field_124);
            }
        }
    }
}

void class_13::method_66() {
    if (this->field_123 > 1) {
        this->field_120->at(0) = 0.0f;
        this->field_120->at(1) = 0.0f;
        this->field_120->at(2) = 0.0f;
        this->field_120->at(((this->field_123 - 1) * 3)) = 0.0f;
        this->field_120->at((((this->field_123 - 1) * 3) + 1)) = 0.0f;
        this->field_120->at((((this->field_123 - 1) * 3) + 2)) = 0.0f;
        for (int32_t var1 = 0; var1 < this->field_123; var1++) {
            if (var1 == (this->field_123 - 1)) {
                this->field_128->at(0) = this->field_133->at(0)->at(1);
                this->field_128->at(1) = this->field_133->at(0)->at(2);
                this->field_128->at(2) = this->field_133->at(0)->at(3);
            } else {
                this->field_128->at(0) = this->field_133->at((var1 + 1))->at(1);
                this->field_128->at(1) = this->field_133->at((var1 + 1))->at(2);
                this->field_128->at(2) = this->field_133->at((var1 + 1))->at(3);
            }
            if (var1 == 0) {
                this->field_129->at(0) = this->field_133->at((this->field_133->length - 1))->at(1);
                this->field_129->at(1) = this->field_133->at((this->field_133->length - 1))->at(2);
                this->field_129->at(2) = this->field_133->at((this->field_133->length - 1))->at(3);
            } else {
                this->field_129->at(0) = this->field_133->at((var1 - 1))->at(1);
                this->field_129->at(1) = this->field_133->at((var1 - 1))->at(2);
                this->field_129->at(2) = this->field_133->at((var1 - 1))->at(3);
            }
            this->field_120->at((var1 * 3)) = 0.5f * float((this->field_128->at(0) - this->field_129->at(0)));
            this->field_120->at(((var1 * 3) + 1)) = 0.5f * float((this->field_128->at(1) - this->field_129->at(1)));
            this->field_120->at(((var1 * 3) + 2)) = 0.5f * float((this->field_128->at(2) - this->field_129->at(2)));
        }
        this->field_120->at((this->field_123 * 3)) = this->field_120->at(0);
        this->field_120->at(((this->field_123 * 3) + 1)) = this->field_120->at(1);
        this->field_120->at(((this->field_123 * 3) + 2)) = this->field_120->at(2);
        this->field_121->at(0) = 0.0f;
        this->field_121->at(1) = 0.0f;
        this->field_121->at(2) = 0.0f;
        this->field_121->at(((this->field_123 - 1) * 3)) = 0.0f;
        this->field_121->at((((this->field_123 - 1) * 3) + 1)) = 0.0f;
        this->field_121->at((((this->field_123 - 1) * 3) + 2)) = 0.0f;
        for (int32_t var2 = 0; var2 < this->field_123; var2++) {
            if (var2 == (this->field_123 - 1)) {
                this->field_128->at(0) = this->field_133->at(0)->at(4);
                this->field_128->at(1) = this->field_133->at(0)->at(5);
                this->field_128->at(2) = this->field_133->at(0)->at(6);
            } else {
                this->field_128->at(0) = this->field_133->at((var2 + 1))->at(4);
                this->field_128->at(1) = this->field_133->at((var2 + 1))->at(5);
                this->field_128->at(2) = this->field_133->at((var2 + 1))->at(6);
            }
            if (var2 == 0) {
                this->field_129->at(0) = this->field_133->at((this->field_133->length - 1))->at(4);
                this->field_129->at(1) = this->field_133->at((this->field_133->length - 1))->at(5);
                this->field_129->at(2) = this->field_133->at((this->field_133->length - 1))->at(6);
            } else {
                this->field_129->at(0) = this->field_133->at((var2 - 1))->at(4);
                this->field_129->at(1) = this->field_133->at((var2 - 1))->at(5);
                this->field_129->at(2) = this->field_133->at((var2 - 1))->at(6);
            }
            this->field_121->at((var2 * 3)) = 0.5f * float((this->field_128->at(0) - this->field_129->at(0)));
            this->field_121->at(((var2 * 3) + 1)) = 0.5f * float((this->field_128->at(1) - this->field_129->at(1)));
            this->field_121->at(((var2 * 3) + 2)) = 0.5f * float((this->field_128->at(2) - this->field_129->at(2)));
        }
        this->field_121->at((this->field_123 * 3)) = this->field_121->at(0);
        this->field_121->at(((this->field_123 * 3) + 1)) = this->field_121->at(1);
        this->field_121->at(((this->field_123 * 3) + 2)) = this->field_121->at(2);
        this->field_122->at(0) = 0.0f;
        this->field_122->at((this->field_123 - 1)) = 0.0f;
        for (int32_t var3 = 0; var3 < this->field_123; var3++) {
            if (var3 == (this->field_123 - 1)) {
                this->field_128->at(0) = this->field_133->at(0)->at(7);
            } else {
                this->field_128->at(0) = this->field_133->at((var3 + 1))->at(7);
            }
            if (var3 == 0) {
                this->field_129->at(0) = this->field_133->at((this->field_133->length - 1))->at(7);
            } else {
                this->field_129->at(0) = this->field_133->at((var3 - 1))->at(7);
            }
            this->field_122->at(var3) = 0.5f * float((this->field_128->at(0) - this->field_129->at(0)));
        }
        this->field_122->at(this->field_123) = this->field_122->at(0);
    }
}

void class_13::__dumpFields(jrt::Dumper& d) {
    d.f("field_120", this->field_120);
    d.f("field_121", this->field_121);
    d.f("field_122", this->field_122);
    d.f("field_123", this->field_123);
    d.f("field_124", this->field_124);
    d.f("field_125", this->field_125);
    d.f("field_126", this->field_126);
    d.f("field_127", this->field_127);
    d.f("field_128", this->field_128);
    d.f("field_129", this->field_129);
    d.f("field_130", this->field_130);
    d.f("field_131", this->field_131);
    d.f("field_132", this->field_132);
    d.f("field_133", this->field_133);
    d.f("field_134", this->field_134);
}

