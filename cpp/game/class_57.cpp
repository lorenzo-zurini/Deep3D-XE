// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<class_3> class_57::field_705{};

void class_57::__clinit() {
    class_57::field_705 = jrt::New<class_3>();
}

void class_57::__init() {
    this->method_469();
    this->field_685 = int16_t(0);
}

void class_57::__init(jrt::Ref<class_57> var1) {
    this->field_686 = var1->field_686;
    this->field_687 = var1->field_687;
    this->field_688 = var1->field_688;
    this->field_689 = var1->field_689;
    this->field_690 = var1->field_690;
    this->field_691 = var1->field_691;
    this->field_692 = var1->field_692;
    this->field_693 = var1->field_693;
    this->field_694 = var1->field_694;
    this->field_695 = var1->field_695;
    this->field_696 = var1->field_696;
    this->field_697 = var1->field_697;
    this->field_698 = var1->field_698;
    this->field_699 = var1->field_699;
    this->field_700 = var1->field_700;
    this->field_701 = var1->field_701;
    this->field_702 = var1->field_702;
    this->field_703 = var1->field_703;
    this->field_704 = var1->field_704;
}

void class_57::method_469() {
    this->field_686 = this->field_687 = this->field_688 = 4096;
    this->field_689 = 4096;
    this->field_692 = 0;
    this->field_695 = 0;
    this->field_690 = 0;
    this->field_693 = 4096;
    this->field_696 = 0;
    this->field_691 = 0;
    this->field_694 = 0;
    this->field_697 = 4096;
    this->field_698 = this->field_699 = this->field_700 = 0;
    this->field_701 = this->field_702 = this->field_703 = 0;
    this->field_704 = false;
}

void class_57::method_470(jrt::Ref<class_57> var1) {
    this->field_686 = var1->field_686;
    this->field_687 = var1->field_687;
    this->field_688 = var1->field_688;
    this->field_689 = var1->field_689;
    this->field_690 = var1->field_690;
    this->field_691 = var1->field_691;
    this->field_692 = var1->field_692;
    this->field_693 = var1->field_693;
    this->field_694 = var1->field_694;
    this->field_695 = var1->field_695;
    this->field_696 = var1->field_696;
    this->field_697 = var1->field_697;
    this->field_698 = var1->field_698;
    this->field_699 = var1->field_699;
    this->field_700 = var1->field_700;
    this->field_701 = var1->field_701;
    this->field_702 = var1->field_702;
    this->field_703 = var1->field_703;
    this->field_704 = var1->field_704;
}

void class_57::method_471(jrt::Ref<class_57> var1) {
    int32_t var2 = this->field_689;
    int32_t var3 = this->field_692;
    int32_t var4 = this->field_690;
    int32_t var5 = this->field_693;
    int32_t var6 = this->field_691;
    int32_t var7 = this->field_694;
    this->field_698 = int32_t(this->field_698 + ((this->field_686 * ((((int64_t(this->field_689) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_692) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_700)) >> 12))) >> 12));
    this->field_699 = int32_t(this->field_699 + ((this->field_687 * ((((int64_t(this->field_690) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_693) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_700)) >> 12))) >> 12));
    this->field_700 = int32_t(this->field_700 + ((this->field_688 * ((((int64_t(this->field_691) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_694) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_700)) >> 12))) >> 12));
    this->field_686 = (this->field_686 * var1->field_686) >> 12;
    this->field_687 = (this->field_687 * var1->field_687) >> 12;
    this->field_688 = (this->field_688 * var1->field_688) >> 12;
    this->field_689 = (((var2 * var1->field_689) >> 12) + ((var3 * var1->field_690) >> 12)) + ((this->field_695 * var1->field_691) >> 12);
    this->field_690 = (((var4 * var1->field_689) >> 12) + ((var5 * var1->field_690) >> 12)) + ((this->field_696 * var1->field_691) >> 12);
    this->field_691 = (((var6 * var1->field_689) >> 12) + ((var7 * var1->field_690) >> 12)) + ((this->field_697 * var1->field_691) >> 12);
    this->field_692 = (((var2 * var1->field_692) >> 12) + ((var3 * var1->field_693) >> 12)) + ((this->field_695 * var1->field_694) >> 12);
    this->field_693 = (((var4 * var1->field_692) >> 12) + ((var5 * var1->field_693) >> 12)) + ((this->field_696 * var1->field_694) >> 12);
    this->field_694 = (((var6 * var1->field_692) >> 12) + ((var7 * var1->field_693) >> 12)) + ((this->field_697 * var1->field_694) >> 12);
    this->field_695 = (((var2 * var1->field_695) >> 12) + ((var3 * var1->field_696) >> 12)) + ((this->field_695 * var1->field_697) >> 12);
    this->field_696 = (((var4 * var1->field_695) >> 12) + ((var5 * var1->field_696) >> 12)) + ((this->field_696 * var1->field_697) >> 12);
    this->field_697 = (((var6 * var1->field_695) >> 12) + ((var7 * var1->field_696) >> 12)) + ((this->field_697 * var1->field_697) >> 12);
    this->field_704 = true;
}

void class_57::method_472(jrt::Ref<class_57> var1) {
    int64_t var2 = int64_t(this->field_689);
    int64_t var4 = int64_t(this->field_692);
    int64_t var6 = int64_t(this->field_690);
    int64_t var8 = int64_t(this->field_693);
    int64_t var10 = int64_t(this->field_691);
    int64_t var12 = int64_t(this->field_694);
    this->field_698 = int32_t((int64_t(this->field_698) + ((int64_t(this->field_686) * ((((int64_t(this->field_689) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_692) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_700)) >> 12))) >> 12)));
    this->field_699 = int32_t((int64_t(this->field_699) + ((int64_t(this->field_687) * ((((int64_t(this->field_690) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_693) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_700)) >> 12))) >> 12)));
    this->field_700 = int32_t((int64_t(this->field_700) + ((int64_t(this->field_688) * ((((int64_t(this->field_691) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_694) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_700)) >> 12))) >> 12)));
    this->field_686 = int32_t(((int64_t(this->field_686) * int64_t(var1->field_686)) >> 12));
    this->field_687 = int32_t(((int64_t(this->field_687) * int64_t(var1->field_687)) >> 12));
    this->field_688 = int32_t(((int64_t(this->field_688) * int64_t(var1->field_688)) >> 12));
    this->field_689 = int32_t(((((var2 * int64_t(var1->field_689)) >> 12) + ((var4 * int64_t(var1->field_690)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_691)) >> 12)));
    this->field_690 = int32_t(((((var6 * int64_t(var1->field_689)) >> 12) + ((var8 * int64_t(var1->field_690)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_691)) >> 12)));
    this->field_691 = int32_t(((((var10 * int64_t(var1->field_689)) >> 12) + ((var12 * int64_t(var1->field_690)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_691)) >> 12)));
    this->field_692 = int32_t(((((var2 * int64_t(var1->field_692)) >> 12) + ((var4 * int64_t(var1->field_693)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_694)) >> 12)));
    this->field_693 = int32_t(((((var6 * int64_t(var1->field_692)) >> 12) + ((var8 * int64_t(var1->field_693)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_694)) >> 12)));
    this->field_694 = int32_t(((((var10 * int64_t(var1->field_692)) >> 12) + ((var12 * int64_t(var1->field_693)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_694)) >> 12)));
    this->field_695 = int32_t(((((var2 * int64_t(var1->field_695)) >> 12) + ((var4 * int64_t(var1->field_696)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_697)) >> 12)));
    this->field_696 = int32_t(((((var6 * int64_t(var1->field_695)) >> 12) + ((var8 * int64_t(var1->field_696)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_697)) >> 12)));
    this->field_697 = int32_t(((((var10 * int64_t(var1->field_695)) >> 12) + ((var12 * int64_t(var1->field_696)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_697)) >> 12)));
    int32_t var14 = class_16::method_95(int32_t(((((int64_t(this->field_689) * int64_t(this->field_689)) >> 12) + ((int64_t(this->field_690) * int64_t(this->field_690)) >> 12)) + ((int64_t(this->field_691) * int64_t(this->field_691)) >> 12))));
    this->field_689 = (this->field_689 * var14) >> 12;
    this->field_690 = (this->field_690 * var14) >> 12;
    this->field_691 = (this->field_691 * var14) >> 12;
    var14 = class_16::method_95(int32_t(((((int64_t(this->field_692) * int64_t(this->field_692)) >> 12) + ((int64_t(this->field_693) * int64_t(this->field_693)) >> 12)) + ((int64_t(this->field_694) * int64_t(this->field_694)) >> 12))));
    this->field_692 = (this->field_692 * var14) >> 12;
    this->field_693 = (this->field_693 * var14) >> 12;
    this->field_694 = (this->field_694 * var14) >> 12;
    var14 = class_16::method_95(int32_t(((((int64_t(this->field_695) * int64_t(this->field_695)) >> 12) + ((int64_t(this->field_696) * int64_t(this->field_696)) >> 12)) + ((int64_t(this->field_697) * int64_t(this->field_697)) >> 12))));
    this->field_695 = (this->field_695 * var14) >> 12;
    this->field_696 = (this->field_696 * var14) >> 12;
    this->field_697 = (this->field_697 * var14) >> 12;
    this->field_704 = true;
}

jrt::Ref<class_57> class_57::method_473(jrt::Ref<class_57> var1, jrt::Ref<class_57> var2) {
    var2->field_698 = int32_t(this->field_698 + ((this->field_686 * ((((int64_t(this->field_689) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_692) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_700)) >> 12))) >> 12));
    var2->field_699 = int32_t(this->field_699 + ((this->field_687 * ((((int64_t(this->field_690) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_693) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_700)) >> 12))) >> 12));
    var2->field_700 = int32_t(this->field_700 + ((this->field_688 * ((((int64_t(this->field_691) * int64_t(var1->field_698)) >> 12) + ((int64_t(this->field_694) * int64_t(var1->field_699)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_700)) >> 12))) >> 12));
    var2->field_686 = (this->field_686 * var1->field_686) >> 12;
    var2->field_687 = (this->field_687 * var1->field_687) >> 12;
    var2->field_688 = (this->field_688 * var1->field_688) >> 12;
    var2->field_689 = (((this->field_689 * var1->field_689) >> 12) + ((this->field_692 * var1->field_690) >> 12)) + ((this->field_695 * var1->field_691) >> 12);
    var2->field_690 = (((this->field_690 * var1->field_689) >> 12) + ((this->field_693 * var1->field_690) >> 12)) + ((this->field_696 * var1->field_691) >> 12);
    var2->field_691 = (((this->field_691 * var1->field_689) >> 12) + ((this->field_694 * var1->field_690) >> 12)) + ((this->field_697 * var1->field_691) >> 12);
    var2->field_692 = (((this->field_689 * var1->field_692) >> 12) + ((this->field_692 * var1->field_693) >> 12)) + ((this->field_695 * var1->field_694) >> 12);
    var2->field_693 = (((this->field_690 * var1->field_692) >> 12) + ((this->field_693 * var1->field_693) >> 12)) + ((this->field_696 * var1->field_694) >> 12);
    var2->field_694 = (((this->field_691 * var1->field_692) >> 12) + ((this->field_694 * var1->field_693) >> 12)) + ((this->field_697 * var1->field_694) >> 12);
    var2->field_695 = (((this->field_689 * var1->field_695) >> 12) + ((this->field_692 * var1->field_696) >> 12)) + ((this->field_695 * var1->field_697) >> 12);
    var2->field_696 = (((this->field_690 * var1->field_695) >> 12) + ((this->field_693 * var1->field_696) >> 12)) + ((this->field_696 * var1->field_697) >> 12);
    var2->field_697 = (((this->field_691 * var1->field_695) >> 12) + ((this->field_694 * var1->field_696) >> 12)) + ((this->field_697 * var1->field_697) >> 12);
    var2->field_704 = true;
    return var2;
}

void class_57::method_474(int32_t var1, int32_t var2, int32_t var3) {
    this->field_698 += var1;
    this->field_699 += var2;
    this->field_700 += var3;
}

void class_57::method_475(jrt::Ref<class_3> var1) {
    this->field_698 = this->field_698 + var1->field_37;
    this->field_699 = this->field_699 + var1->field_38;
    this->field_700 = this->field_700 + var1->field_39;
}

void class_57::method_476(int32_t var1, int32_t var2, int32_t var3) {
    this->field_698 = var1;
    this->field_699 = var2;
    this->field_700 = var3;
}

void class_57::method_477(jrt::Ref<class_3> var1) {
    this->field_698 = var1->field_37;
    this->field_699 = var1->field_38;
    this->field_700 = var1->field_39;
}

void class_57::method_478(int32_t var1) {
    this->field_698 = this->field_698 + ((this->field_695 * var1) >> 12);
    this->field_699 = this->field_699 + ((this->field_696 * var1) >> 12);
    this->field_700 = this->field_700 + ((this->field_697 * var1) >> 12);
}

jrt::Ref<class_3> class_57::method_479(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_698;
    var1->field_38 = this->field_699;
    var1->field_39 = this->field_700;
    return var1;
}

jrt::Ref<class_3> class_57::method_480() {
    return jrt::New<class_3>(this->field_698, this->field_699, this->field_700);
}

jrt::Ref<class_3> class_57::method_481(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_695;
    var1->field_38 = this->field_696;
    var1->field_39 = this->field_697;
    return var1;
}

jrt::Ref<class_3> class_57::method_482(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_692;
    var1->field_38 = this->field_693;
    var1->field_39 = this->field_694;
    return var1;
}

jrt::Ref<class_3> class_57::method_483() {
    return jrt::New<class_3>(this->field_692, this->field_693, this->field_694);
}

jrt::Ref<class_3> class_57::method_484(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_689;
    var1->field_38 = this->field_690;
    var1->field_39 = this->field_691;
    return var1;
}

void class_57::method_485(int16_t var1) {
    if (int32_t(this->field_685) != int32_t(var1)) {
        this->field_685 = var1;
        this->method_493();
        this->field_704 = false;
    }
}

void class_57::method_486(int32_t var1, int32_t var2, int32_t var3) {
    if (this->field_704) {
        this->method_493();
        this->field_704 = false;
    }
    this->field_701 += var1;
    this->field_702 += var2;
    this->field_703 += var3;
    this->method_491(this->field_701, this->field_702, this->field_703);
}

/* Deep3D-PC: a turn about one of the axes (0 x, 1 y, 2 z), in the game's units
   of 4096 a circle, as method_489, method_488 and method_487 and a method_491
   by method_472 do it. A frame's share of a turn can be a unit or less, and
   those lose it: their terms are (sin * axis) >> 12, and sin(1) is 6, so 12
   bits of axes round away a good part of each turn. Here the axes turn in
   doubles, and the ints follow; if anything else moved them, the doubles start
   again from there. */
void class_57::deep3dTurn(int32_t axis, double units) {
    int32_t* m[9] = {&this->field_689, &this->field_690, &this->field_691, &this->field_692, &this->field_693,
                     &this->field_694, &this->field_695, &this->field_696, &this->field_697};
    double* d = this->deep3dAxes;
    bool same = true;
    for (int32_t i = 0; i < 9; i++) {
        same = same && (std::lround(d[i] * 4096.0) == *m[i]);
    }
    if (!same) {
        for (int32_t i = 0; i < 9; i += 3) {
            double x = *m[i], y = *m[i + 1], z = *m[i + 2];
            double n = std::sqrt(x * x + y * y + z * z);
            n = n > 0.0 ? n : 1.0;
            d[i] = x / n, d[i + 1] = y / n, d[i + 2] = z / n;
        }
    }
    double angle = units * 3.141592653589793 / 2048.0, c = std::cos(angle), s = std::sin(angle);
    const double* a = d + axis * 3;
    for (int32_t k = 1; k < 3; k++) {
        double* v = d + ((axis + k) % 3) * 3;
        double dot = a[0] * v[0] + a[1] * v[1] + a[2] * v[2];
        double x = v[0] * c + (a[1] * v[2] - a[2] * v[1]) * s + a[0] * dot * (1.0 - c);
        double y = v[1] * c + (a[2] * v[0] - a[0] * v[2]) * s + a[1] * dot * (1.0 - c);
        double z = v[2] * c + (a[0] * v[1] - a[1] * v[0]) * s + a[2] * dot * (1.0 - c);
        double n = std::sqrt(x * x + y * y + z * z);
        v[0] = x / n, v[1] = y / n, v[2] = z / n;
    }
    for (int32_t i = 0; i < 9; i++) {
        *m[i] = int32_t(std::lround(d[i] * 4096.0));
    }
    this->field_704 = true;
}

/* Deep3D-PC: method_478 for a frame's share of a move. Its (axis * n) >> 12
   floors each of x, y and z once a call: nothing at a step's 66 units, but ten
   calls of 6 or 7 lose a tenth of the speed on a diagonal, none along an axis */
void class_57::deep3dGo(double units) {
    double x = this->field_695 * units / 4096.0 + this->deep3dGoLeft[0];
    double y = this->field_696 * units / 4096.0 + this->deep3dGoLeft[1];
    double z = this->field_697 * units / 4096.0 + this->deep3dGoLeft[2];
    int32_t wx = int32_t(x), wy = int32_t(y), wz = int32_t(z);
    this->deep3dGoLeft[0] = x - wx, this->deep3dGoLeft[1] = y - wy, this->deep3dGoLeft[2] = z - wz;
    this->field_698 += wx, this->field_699 += wy, this->field_700 += wz;
}

void class_57::method_487(int32_t var1) {
    int32_t var2 = class_16::method_91(var1);
    int32_t var3 = class_16::method_92(var1);
    int32_t var4{};
    int32_t var5 = ((((var4 = 4096 - var3) * this->field_695) >> 12) * this->field_697) >> 12;
    int32_t var6 = (((var4 * this->field_696) >> 12) * this->field_697) >> 12;
    int32_t var7 = (((var4 * this->field_695) >> 12) * this->field_696) >> 12;
    int32_t var8 = (var2 * this->field_696) >> 12;
    int32_t var9 = (var2 * this->field_695) >> 12;
    int32_t var10 = (var2 * this->field_697) >> 12;
    int32_t var11 = ((((var4 * this->field_695) >> 12) * this->field_695) >> 12) + var3;
    int32_t var12 = var7 - var10;
    int32_t var13 = var5 + var8;
    int32_t var14 = var7 + var10;
    int32_t var15 = ((((var4 * this->field_696) >> 12) * this->field_696) >> 12) + var3;
    int32_t var16 = var6 - var9;
    int32_t var17 = var5 - var8;
    int32_t var18 = var6 + var9;
    int32_t var19 = ((((var4 * this->field_697) >> 12) * this->field_697) >> 12) + var3;
    int32_t var20 = this->field_689;
    int32_t var21 = this->field_690;
    this->field_689 = (((this->field_689 * var11) >> 12) + ((this->field_690 * var12) >> 12)) + ((this->field_691 * var13) >> 12);
    this->field_690 = (((var20 * var14) >> 12) + ((this->field_690 * var15) >> 12)) + ((this->field_691 * var16) >> 12);
    this->field_691 = (((var20 * var17) >> 12) + ((var21 * var18) >> 12)) + ((this->field_691 * var19) >> 12);
    this->field_692 = ((this->field_696 * this->field_691) >> 12) - ((this->field_697 * this->field_690) >> 12);
    this->field_693 = ((this->field_697 * this->field_689) >> 12) - ((this->field_695 * this->field_691) >> 12);
    this->field_694 = ((this->field_695 * this->field_690) >> 12) - ((this->field_696 * this->field_689) >> 12);
    int32_t var22 = class_16::method_95(((((this->field_692 * this->field_692) >> 12) + ((this->field_693 * this->field_693) >> 12)) + ((this->field_694 * this->field_694) >> 12)));
    this->field_692 = (this->field_692 * var22) >> 12;
    this->field_693 = (this->field_693 * var22) >> 12;
    this->field_694 = (this->field_694 * var22) >> 12;
    this->field_689 = ((this->field_697 * this->field_693) >> 12) - ((this->field_696 * this->field_694) >> 12);
    this->field_690 = ((this->field_695 * this->field_694) >> 12) - ((this->field_697 * this->field_692) >> 12);
    this->field_691 = ((this->field_696 * this->field_692) >> 12) - ((this->field_695 * this->field_693) >> 12);
    this->field_704 = true;
}

void class_57::method_488(int32_t var1) {
    int32_t var2 = class_16::method_91(var1);
    int32_t var3 = class_16::method_92(var1);
    int32_t var4{};
    int32_t var5 = ((((var4 = 4096 - var3) * this->field_692) >> 12) * this->field_694) >> 12;
    int32_t var6 = (((var4 * this->field_693) >> 12) * this->field_694) >> 12;
    int32_t var7 = (((var4 * this->field_692) >> 12) * this->field_693) >> 12;
    int32_t var8 = (var2 * this->field_693) >> 12;
    int32_t var9 = (var2 * this->field_692) >> 12;
    int32_t var10 = (var2 * this->field_694) >> 12;
    int32_t var11 = ((((var4 * this->field_692) >> 12) * this->field_692) >> 12) + var3;
    int32_t var12 = var7 - var10;
    int32_t var13 = var5 + var8;
    int32_t var14 = var7 + var10;
    int32_t var15 = ((((var4 * this->field_693) >> 12) * this->field_693) >> 12) + var3;
    int32_t var16 = var6 - var9;
    int32_t var17 = var5 - var8;
    int32_t var18 = var6 + var9;
    int32_t var19 = ((((var4 * this->field_694) >> 12) * this->field_694) >> 12) + var3;
    int32_t var20 = this->field_695;
    int32_t var21 = this->field_696;
    this->field_695 = (((this->field_695 * var11) >> 12) + ((this->field_696 * var12) >> 12)) + ((this->field_697 * var13) >> 12);
    this->field_696 = (((var20 * var14) >> 12) + ((this->field_696 * var15) >> 12)) + ((this->field_697 * var16) >> 12);
    this->field_697 = (((var20 * var17) >> 12) + ((var21 * var18) >> 12)) + ((this->field_697 * var19) >> 12);
    this->field_689 = ((this->field_697 * this->field_693) >> 12) - ((this->field_696 * this->field_694) >> 12);
    this->field_690 = ((this->field_695 * this->field_694) >> 12) - ((this->field_697 * this->field_692) >> 12);
    this->field_691 = ((this->field_696 * this->field_692) >> 12) - ((this->field_695 * this->field_693) >> 12);
    int32_t var22 = class_16::method_95(((((this->field_689 * this->field_689) >> 12) + ((this->field_690 * this->field_690) >> 12)) + ((this->field_691 * this->field_691) >> 12)));
    this->field_689 = (this->field_689 * var22) >> 12;
    this->field_690 = (this->field_690 * var22) >> 12;
    this->field_691 = (this->field_691 * var22) >> 12;
    this->field_695 = ((this->field_694 * this->field_690) >> 12) - ((this->field_693 * this->field_691) >> 12);
    this->field_696 = ((this->field_692 * this->field_691) >> 12) - ((this->field_694 * this->field_689) >> 12);
    this->field_697 = ((this->field_693 * this->field_689) >> 12) - ((this->field_692 * this->field_690) >> 12);
    this->field_704 = true;
}

void class_57::method_489(int32_t var1) {
    int32_t var2 = class_16::method_91(var1);
    int32_t var3 = class_16::method_92(var1);
    int32_t var4{};
    int32_t var5 = ((((var4 = 4096 - var3) * this->field_689) >> 12) * this->field_691) >> 12;
    int32_t var6 = (((var4 * this->field_690) >> 12) * this->field_691) >> 12;
    int32_t var7 = (((var4 * this->field_689) >> 12) * this->field_690) >> 12;
    int32_t var8 = (var2 * this->field_690) >> 12;
    int32_t var9 = (var2 * this->field_689) >> 12;
    int32_t var10 = (var2 * this->field_691) >> 12;
    int32_t var11 = ((((var4 * this->field_689) >> 12) * this->field_689) >> 12) + var3;
    int32_t var12 = var7 - var10;
    int32_t var13 = var5 + var8;
    int32_t var14 = var7 + var10;
    int32_t var15 = ((((var4 * this->field_690) >> 12) * this->field_690) >> 12) + var3;
    int32_t var16 = var6 - var9;
    int32_t var17 = var5 - var8;
    int32_t var18 = var6 + var9;
    int32_t var19 = ((((var4 * this->field_691) >> 12) * this->field_691) >> 12) + var3;
    int32_t var20 = this->field_692;
    int32_t var21 = this->field_693;
    this->field_692 = (((this->field_692 * var11) >> 12) + ((this->field_693 * var12) >> 12)) + ((this->field_694 * var13) >> 12);
    this->field_693 = (((var20 * var14) >> 12) + ((this->field_693 * var15) >> 12)) + ((this->field_694 * var16) >> 12);
    this->field_694 = (((var20 * var17) >> 12) + ((var21 * var18) >> 12)) + ((this->field_694 * var19) >> 12);
    this->field_695 = ((this->field_690 * this->field_694) >> 12) - ((this->field_691 * this->field_693) >> 12);
    this->field_696 = ((this->field_691 * this->field_692) >> 12) - ((this->field_689 * this->field_694) >> 12);
    this->field_697 = ((this->field_689 * this->field_693) >> 12) - ((this->field_690 * this->field_692) >> 12);
    int32_t var22 = class_16::method_95(((((this->field_695 * this->field_695) >> 12) + ((this->field_696 * this->field_696) >> 12)) + ((this->field_697 * this->field_697) >> 12)));
    this->field_695 = (this->field_695 * var22) >> 12;
    this->field_696 = (this->field_696 * var22) >> 12;
    this->field_697 = (this->field_697 * var22) >> 12;
    this->field_692 = ((this->field_696 * this->field_691) >> 12) - ((this->field_697 * this->field_690) >> 12);
    this->field_693 = ((this->field_697 * this->field_689) >> 12) - ((this->field_695 * this->field_691) >> 12);
    this->field_694 = ((this->field_695 * this->field_690) >> 12) - ((this->field_696 * this->field_689) >> 12);
    this->field_704 = true;
}

void class_57::method_490(int32_t var1) {
    this->method_491(this->field_701, var1, this->field_703);
}

void class_57::method_491(int32_t var1, int32_t var2, int32_t var3) {
    this->field_701 = var1;
    this->field_702 = var2;
    this->field_703 = var3;
    this->field_704 = false;
    int32_t var4 = class_16::method_91(var1);
    int32_t var5 = class_16::method_91(var2);
    int32_t var6 = class_16::method_91(var3);
    int32_t var7 = class_16::method_92(var1);
    int32_t var8 = class_16::method_92(var2);
    int32_t var9 = class_16::method_92(var3);
    {
        int32_t var17{};
        int32_t var22{};
        int32_t var25{};
        int32_t var16{};
        int32_t var21{};
        int32_t var15{};
        int32_t var20{};
        int32_t var24{};
        int32_t var14{};
        int32_t var19{};
        int32_t var23{};
        int32_t var13{};
        int32_t var18{};
        int32_t var10{};
        bool var11{};
        int32_t var12{};
        switch (int32_t(this->field_685)) {
        case 0:
            var17 = ((var7 * var9) >> 12);
            var22 = ((var9 * var4) >> 12);
            var25 = ((var5 * var6) >> 12);
            this->field_689 = (var8 * var9) >> 12;
            this->field_692 = -((var8 * var6) >> 12);
            this->field_695 = var5;
            this->field_690 = ((var22 * var5) >> 12) + ((var7 * var6) >> 12);
            this->field_693 = var17 - ((var25 * var4) >> 12);
            this->field_696 = -((var8 * var4) >> 12);
            this->field_691 = (-((var17 * var5) >> 12)) + ((var4 * var6) >> 12);
            this->field_694 = var22 + ((var25 * var7) >> 12);
            this->field_697 = (var7 * var8) >> 12;
            return;
        case 1:
            var16 = ((var8 * var6) >> 12);
            var21 = ((var5 * var6) >> 12);
            this->field_689 = (var8 * var9) >> 12;
            this->field_692 = -var6;
            this->field_695 = (var9 * var5) >> 12;
            this->field_690 = ((var4 * var5) >> 12) + ((var16 * var7) >> 12);
            this->field_693 = (var7 * var9) >> 12;
            this->field_696 = (-((var8 * var4) >> 12)) + ((var21 * var7) >> 12);
            this->field_691 = (-((var7 * var5) >> 12)) + ((var16 * var4) >> 12);
            this->field_694 = (var9 * var4) >> 12;
            this->field_697 = ((var7 * var8) >> 12) + ((var21 * var4) >> 12);
            return;
        case 2:
            var15 = ((var8 * var9) >> 12);
            var20 = ((var4 * var6) >> 12);
            var24 = ((var5 * var9) >> 12);
            this->field_689 = var15 + ((var20 * var5) >> 12);
            this->field_692 = ((var24 * var4) >> 12) - ((var8 * var6) >> 12);
            this->field_695 = (var7 * var5) >> 12;
            this->field_690 = (var7 * var6) >> 12;
            this->field_693 = (var7 * var9) >> 12;
            this->field_696 = -var4;
            this->field_691 = (-var24) + ((var20 * var8) >> 12);
            this->field_694 = ((var15 * var4) >> 12) + ((var5 * var6) >> 12);
            this->field_697 = (var7 * var8) >> 12;
            return;
        case 3:
            var14 = ((var4 * var5) >> 12);
            var19 = ((var7 * var8) >> 12);
            var23 = ((var8 * var4) >> 12);
            this->field_689 = (var8 * var9) >> 12;
            this->field_692 = var14 - ((var19 * var6) >> 12);
            this->field_695 = ((var7 * var5) >> 12) + ((var23 * var6) >> 12);
            this->field_690 = var6;
            this->field_693 = (var7 * var9) >> 12;
            this->field_696 = -((var9 * var4) >> 12);
            this->field_691 = -((var9 * var5) >> 12);
            this->field_694 = var23 + ((((var7 * var5) >> 12) * var6) >> 12);
            this->field_697 = var19 - ((var14 * var6) >> 12);
            return;
        case 4:
            var13 = ((var4 * var5) >> 12);
            var18 = ((var8 * var4) >> 12);
            this->field_689 = ((var8 * var9) >> 12) - ((var13 * var6) >> 12);
            this->field_692 = -((var7 * var6) >> 12);
            this->field_695 = ((var9 * var5) >> 12) + ((var18 * var6) >> 12);
            this->field_690 = ((var13 * var9) >> 12) + ((var8 * var6) >> 12);
            this->field_693 = (var7 * var9) >> 12;
            this->field_696 = (-((var18 * var9) >> 12)) + ((var5 * var6) >> 12);
            this->field_691 = -((var7 * var5) >> 12);
            this->field_694 = var4;
            this->field_697 = (var7 * var8) >> 12;
            return;
        case 5:
            var10 = ((var5 * var6) >> 12);
            var11 = false;
            var12 = ((var9 * var5) >> 12);
            this->field_689 = (var8 * var9) >> 12;
            this->field_692 = ((var12 * var4) >> 12) - ((var7 * var6) >> 12);
            this->field_695 = ((var12 * var7) >> 12) + ((var4 * var6) >> 12);
            this->field_690 = (var8 * var6) >> 12;
            this->field_693 = ((var7 * var9) >> 12) + ((var10 * var4) >> 12);
            this->field_696 = (-((var9 * var4) >> 12)) + ((var10 * var7) >> 12);
            this->field_691 = -var5;
            this->field_694 = (var8 * var4) >> 12;
            this->field_697 = (var7 * var8) >> 12;
        }
    }
}

int32_t class_57::method_492() {
    if (this->field_704) {
        this->method_493();
        this->field_704 = false;
    }
    return this->field_702;
}

void class_57::method_493() {
    {
        switch (int32_t(this->field_685)) {
        case 0:
            this->field_702 = class_16::method_93(this->field_695);
            if (this->field_702 < 2048) {
                if (this->field_702 > (-2048)) {
                    this->field_701 = class_16::method_94((-this->field_696), this->field_697);
                    this->field_703 = class_16::method_94((-this->field_692), this->field_689);
                    return;
                }
                this->field_701 = -class_16::method_94(this->field_690, this->field_693);
                this->field_703 = 0;
                return;
            }
            this->field_701 = class_16::method_94(this->field_690, this->field_693);
            this->field_703 = 0;
            return;
        case 1:
            this->field_703 = class_16::method_93((-this->field_692));
            if (this->field_703 < 2048) {
                if (this->field_703 > (-2048)) {
                    this->field_701 = class_16::method_94(this->field_694, this->field_693);
                    this->field_702 = class_16::method_94(this->field_695, this->field_689);
                    return;
                }
                this->field_701 = -class_16::method_94((-this->field_691), this->field_697);
                this->field_702 = 0;
                return;
            }
            this->field_701 = class_16::method_94((-this->field_691), this->field_697);
            this->field_702 = 0;
            return;
        case 2:
            this->field_701 = class_16::method_93((-this->field_696));
            if (this->field_701 < 2048) {
                if (this->field_701 > (-2048)) {
                    this->field_702 = class_16::method_94(this->field_695, this->field_697);
                    this->field_703 = class_16::method_94(this->field_690, this->field_693);
                    return;
                }
                this->field_702 = -class_16::method_94((-this->field_692), this->field_689);
                this->field_703 = 0;
                return;
            }
            this->field_702 = class_16::method_94((-this->field_692), this->field_689);
            this->field_703 = 0;
            return;
        case 3:
            this->field_703 = class_16::method_93(this->field_690);
            if (this->field_703 < 2048) {
                if (this->field_703 > (-2048)) {
                    this->field_702 = class_16::method_94((-this->field_691), this->field_689);
                    this->field_701 = class_16::method_94((-this->field_696), this->field_693);
                    return;
                }
                this->field_702 = -class_16::method_94(this->field_694, this->field_697);
                this->field_701 = 0;
                return;
            }
            this->field_702 = class_16::method_94(this->field_694, this->field_697);
            this->field_701 = 0;
            return;
        case 4:
            this->field_701 = class_16::method_93(this->field_694);
            if (this->field_701 < 2048) {
                if (this->field_701 > (-2048)) {
                    this->field_703 = class_16::method_94((-this->field_692), this->field_693);
                    this->field_702 = class_16::method_94((-this->field_691), this->field_697);
                    return;
                }
                this->field_703 = -class_16::method_94(this->field_695, this->field_689);
                this->field_702 = 0;
                return;
            }
            this->field_703 = class_16::method_94(this->field_695, this->field_689);
            this->field_702 = 0;
            return;
        case 5:
            this->field_702 = class_16::method_93((-this->field_691));
            if (this->field_702 < 2048) {
                if (this->field_702 > (-2048)) {
                    this->field_703 = class_16::method_94(this->field_690, this->field_689);
                    this->field_701 = class_16::method_94(this->field_694, this->field_697);
                    return;
                }
                this->field_703 = -class_16::method_94((-this->field_692), this->field_695);
                this->field_701 = 0;
                return;
            } else {
                this->field_703 = class_16::method_94((-this->field_692), this->field_695);
                this->field_701 = 0;
            }
        }
    }
}

void class_57::method_494(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_689 = (4096 - (((2 * var2) * var2) >> 12)) - (((2 * var3) * var3) >> 12);
    this->field_692 = (((2 * var1) * var2) >> 12) - (((2 * var4) * var3) >> 12);
    this->field_695 = (((2 * var1) * var3) >> 12) + (((2 * var4) * var2) >> 12);
    this->field_690 = (((2 * var1) * var2) >> 12) + (((2 * var4) * var3) >> 12);
    this->field_693 = (4096 - (((2 * var1) * var1) >> 12)) - (((2 * var3) * var3) >> 12);
    this->field_696 = (((2 * var2) * var3) >> 12) - (((2 * var4) * var1) >> 12);
    this->field_691 = (((2 * var1) * var3) >> 12) - (((2 * var4) * var2) >> 12);
    this->field_694 = (((2 * var4) * var1) >> 12) + (((2 * var2) * var3) >> 12);
    this->field_697 = (4096 - (((2 * var1) * var1) >> 12)) - (((2 * var2) * var2) >> 12);
    this->field_704 = true;
}

void class_57::method_495(jrt::Ref<class_123> var1) {
    this->method_494(var1->field_1509, var1->field_1510, var1->field_1511, var1->field_1512);
}

int32_t class_57::method_496(int32_t var1) {
    return (var1 < 2) ? (var1 + 1) : 0;
}

int32_t class_57::method_497(int32_t var1) {
    {
        switch (var1) {
        case 0:
            return this->field_689;
        case 1:
            return this->field_690;
        case 2:
            return this->field_691;
        case 3:
            return this->field_692;
        case 4:
            return this->field_693;
        case 5:
            return this->field_694;
        case 6:
            return this->field_695;
        case 7:
            return this->field_696;
        case 8:
            return this->field_697;
        default:
            return 0;
        }
    }
}

jrt::Ref<class_123> class_57::method_498(jrt::Ref<class_123> var1) {
    int32_t var2{};
    if ((var2 = ((4096 + this->field_689) + this->field_693) + this->field_697) > 0) {
        int32_t var7 = class_16::method_96(int64_t(var2));
        var1->field_1512 = var7 >> 1;
        var7 = jrt::div(8388608, var7);
        var1->field_1509 = ((this->field_694 - this->field_696) * var7) >> 12;
        var1->field_1510 = ((this->field_695 - this->field_691) * var7) >> 12;
        var1->field_1511 = ((this->field_690 - this->field_692) * var7) >> 12;
        return var1;
    } else {
        int8_t var3 = int8_t(0);
        if (this->field_693 > this->field_689) {
            var3 = int8_t(1);
        }
        if (this->field_697 > this->method_497((int32_t(var3) * 4))) {
            var3 = int8_t(2);
        }
        int32_t var4 = this->method_496(int32_t(var3));
        int32_t var5 = this->method_496(var4);
        int32_t var6 = class_16::method_96(int64_t((((4096 + this->method_497((int32_t(var3) * 4))) - this->method_497((var4 * 4))) - this->method_497((var5 * 4)))));
        {
            switch (int32_t(var3)) {
            case 0:
                var1->field_1509 = var6 >> 1;
                break;
            case 1:
                var1->field_1510 = var6 >> 1;
                break;
            case 2:
                var1->field_1511 = var6 >> 1;
            }
        }
        if (var6 != 0) {
            var6 = jrt::div(8388608, var6);
        }
        {
            switch (var4) {
            case 0:
                var1->field_1509 = ((this->method_497((int32_t(var3) + (var4 * 3))) + this->method_497((var4 + (int32_t(var3) * 3)))) * var6) >> 12;
                break;
            case 1:
                var1->field_1510 = ((this->method_497((int32_t(var3) + (var4 * 3))) + this->method_497((var4 + (int32_t(var3) * 3)))) * var6) >> 12;
                break;
            case 2:
                var1->field_1511 = ((this->method_497((int32_t(var3) + (var4 * 3))) + this->method_497((var4 + (int32_t(var3) * 3)))) * var6) >> 12;
            }
        }
        {
            switch (var5) {
            case 0:
                var1->field_1509 = ((this->method_497((int32_t(var3) + (var5 * 3))) + this->method_497((var5 + (int32_t(var3) * 3)))) * var6) >> 12;
                break;
            case 1:
                var1->field_1510 = ((this->method_497((int32_t(var3) + (var5 * 3))) + this->method_497((var5 + (int32_t(var3) * 3)))) * var6) >> 12;
                break;
            case 2:
                var1->field_1511 = ((this->method_497((int32_t(var3) + (var5 * 3))) + this->method_497((var5 + (int32_t(var3) * 3)))) * var6) >> 12;
            }
        }
        var1->field_1512 = ((this->method_497((var4 + (var5 * 3))) - this->method_497((var5 + (var4 * 3)))) * var6) >> 12;
        return var1;
    }
}

jrt::Ref<class_123> class_57::method_499() {
    return this->method_498(jrt::New<class_123>());
}

void class_57::method_500(int32_t var1, int32_t var2, int32_t var3) {
    this->field_686 = (this->field_686 * var1) >> 12;
    this->field_687 = (this->field_687 * var2) >> 12;
    this->field_688 = (this->field_688 * var3) >> 12;
}

void class_57::method_501(int32_t var1, int32_t var2, int32_t var3) {
    this->field_686 = var1;
    this->field_687 = var2;
    this->field_688 = var3;
}

jrt::Ref<class_3> class_57::method_502(jrt::Ref<class_3> var1) {
    var1->field_37 = this->field_686;
    var1->field_38 = this->field_687;
    var1->field_39 = this->field_688;
    return var1;
}

jrt::Ref<class_57> class_57::method_503(jrt::Ref<class_57> var1) {
    var1->field_686 = jrt::div(16777216, this->field_686);
    var1->field_687 = jrt::div(16777216, this->field_687);
    var1->field_688 = jrt::div(16777216, this->field_688);
    var1->field_689 = this->field_689;
    var1->field_692 = this->field_690;
    var1->field_695 = this->field_691;
    var1->field_690 = this->field_692;
    var1->field_693 = this->field_693;
    var1->field_696 = this->field_694;
    var1->field_691 = this->field_695;
    var1->field_694 = this->field_696;
    var1->field_697 = this->field_697;
    var1->field_698 = int32_t((var1->field_686 * (((-((int64_t(var1->field_689) * int64_t(this->field_698)) >> 12)) - ((int64_t(var1->field_692) * int64_t(this->field_699)) >> 12)) - ((int64_t(var1->field_695) * int64_t(this->field_700)) >> 12))) >> 12);
    var1->field_699 = int32_t((var1->field_687 * (((-((int64_t(var1->field_690) * int64_t(this->field_698)) >> 12)) - ((int64_t(var1->field_693) * int64_t(this->field_699)) >> 12)) - ((int64_t(var1->field_696) * int64_t(this->field_700)) >> 12))) >> 12);
    var1->field_700 = int32_t((var1->field_688 * (((-((int64_t(var1->field_691) * int64_t(this->field_698)) >> 12)) - ((int64_t(var1->field_694) * int64_t(this->field_699)) >> 12)) - ((int64_t(var1->field_697) * int64_t(this->field_700)) >> 12))) >> 12);
    var1->field_704 = true;
    return var1;
}

void class_57::method_504(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2, jrt::Ref<class_3> var3) {
    this->field_689 = var1->field_37;
    this->field_692 = var2->field_37;
    this->field_695 = var3->field_37;
    this->field_690 = var1->field_38;
    this->field_693 = var2->field_38;
    this->field_696 = var3->field_38;
    this->field_691 = var1->field_39;
    this->field_694 = var2->field_39;
    this->field_697 = var3->field_39;
    this->field_704 = true;
}

void class_57::method_505(jrt::Ref<jrt::Array<float>> var1) {
    var1->at(0) = float((this->field_686 * this->field_689)) * 5.9604645E-8f;
    var1->at(1) = float((this->field_687 * this->field_692)) * 5.9604645E-8f;
    var1->at(2) = float((this->field_688 * this->field_695)) * 5.9604645E-8f;
    var1->at(3) = float(this->field_698);
    var1->at(4) = float((this->field_686 * this->field_690)) * 5.9604645E-8f;
    var1->at(5) = float((this->field_687 * this->field_693)) * 5.9604645E-8f;
    var1->at(6) = float((this->field_688 * this->field_696)) * 5.9604645E-8f;
    var1->at(7) = float(this->field_699);
    var1->at(8) = float((this->field_686 * this->field_691)) * 5.9604645E-8f;
    var1->at(9) = float((this->field_687 * this->field_694)) * 5.9604645E-8f;
    var1->at(10) = float((this->field_688 * this->field_697)) * 5.9604645E-8f;
    var1->at(11) = float(this->field_700);
    var1->at(12) = 0.0f;
    var1->at(13) = 0.0f;
    var1->at(14) = 0.0f;
    var1->at(15) = 1.0f;
}

jrt::Ref<java::lang::String> class_57::toString() {
    jrt::Ref<java::lang::String> var1 = JRT_LIT(u"");
    var1 = jrt::concat(var1, JRT_LIT(u"|\t"), ((this->field_686 * this->field_689) >> 12), JRT_LIT(u",\t"), ((this->field_687 * this->field_692) >> 12), JRT_LIT(u",\t"), ((this->field_688 * this->field_695) >> 12), JRT_LIT(u",\t"), this->field_698, JRT_LIT(u"\t|\n"));
    var1 = jrt::concat(var1, JRT_LIT(u"|\t"), ((this->field_686 * this->field_690) >> 12), JRT_LIT(u",\t"), ((this->field_687 * this->field_693) >> 12), JRT_LIT(u",\t"), ((this->field_688 * this->field_696) >> 12), JRT_LIT(u",\t"), this->field_699, JRT_LIT(u"\t|\n"));
    return jrt::concat(var1, JRT_LIT(u"|\t"), ((this->field_686 * this->field_691) >> 12), JRT_LIT(u",\t"), ((this->field_687 * this->field_694) >> 12), JRT_LIT(u",\t"), ((this->field_688 * this->field_697) >> 12), JRT_LIT(u",\t"), this->field_700, JRT_LIT(u"\t|\n"));
}

jrt::Ref<class_3> class_57::method_506(jrt::Ref<class_3> var1) {
    int32_t var2 = var1->field_37;
    int32_t var3 = var1->field_38;
    int32_t var4 = var1->field_39;
    var1->field_37 = int32_t(((((((int64_t(this->field_686) * int64_t(this->field_689)) >> 12) * var2) >> 12) + ((((int64_t(this->field_687) * int64_t(this->field_692)) >> 12) * var3) >> 12)) + ((((int64_t(this->field_688) * int64_t(this->field_695)) >> 12) * var4) >> 12)) + this->field_698);
    var1->field_38 = int32_t(((((((int64_t(this->field_686) * int64_t(this->field_690)) >> 12) * var2) >> 12) + ((((int64_t(this->field_687) * int64_t(this->field_693)) >> 12) * var3) >> 12)) + ((((int64_t(this->field_688) * int64_t(this->field_696)) >> 12) * var4) >> 12)) + this->field_699);
    var1->field_39 = int32_t(((((((int64_t(this->field_686) * int64_t(this->field_691)) >> 12) * var2) >> 12) + ((((int64_t(this->field_687) * int64_t(this->field_694)) >> 12) * var3) >> 12)) + ((((int64_t(this->field_688) * int64_t(this->field_697)) >> 12) * var4) >> 12)) + this->field_700);
    return var1;
}

jrt::Ref<class_3> class_57::method_507(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    int64_t var3 = ((((int64_t(((this->field_686 * this->field_689) >> 12)) * int64_t(var1->field_37)) >> 12) + ((int64_t(((this->field_687 * this->field_692) >> 12)) * int64_t(var1->field_38)) >> 12)) + ((int64_t(((this->field_688 * this->field_695) >> 12)) * int64_t(var1->field_39)) >> 12)) + int64_t(this->field_698);
    int64_t var5 = ((((int64_t(((this->field_686 * this->field_690) >> 12)) * int64_t(var1->field_37)) >> 12) + ((int64_t(((this->field_687 * this->field_693) >> 12)) * int64_t(var1->field_38)) >> 12)) + ((int64_t(((this->field_688 * this->field_696) >> 12)) * int64_t(var1->field_39)) >> 12)) + int64_t(this->field_699);
    int64_t var7 = ((((int64_t(((this->field_686 * this->field_691) >> 12)) * int64_t(var1->field_37)) >> 12) + ((int64_t(((this->field_687 * this->field_694) >> 12)) * int64_t(var1->field_38)) >> 12)) + ((int64_t(((this->field_688 * this->field_697) >> 12)) * int64_t(var1->field_39)) >> 12)) + int64_t(this->field_700);
    var2->field_37 = int32_t(var3);
    var2->field_38 = int32_t(var5);
    var2->field_39 = int32_t(var7);
    return var2;
}

jrt::Ref<class_3> class_57::method_508(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    var2->field_37 = (((this->field_689 * var1->field_37) >> 12) + ((this->field_692 * var1->field_38) >> 12)) + ((this->field_695 * var1->field_39) >> 12);
    var2->field_38 = (((this->field_690 * var1->field_37) >> 12) + ((this->field_693 * var1->field_38) >> 12)) + ((this->field_696 * var1->field_39) >> 12);
    var2->field_39 = (((this->field_691 * var1->field_37) >> 12) + ((this->field_694 * var1->field_38) >> 12)) + ((this->field_697 * var1->field_39) >> 12);
    return var2;
}

jrt::Ref<class_3> class_57::method_509(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2) {
    int64_t var3 = (((int64_t(this->field_689) * int64_t(var1->field_37)) >> 12) + ((int64_t(this->field_692) * int64_t(var1->field_38)) >> 12)) + ((int64_t(this->field_695) * int64_t(var1->field_39)) >> 12);
    int64_t var5 = (((int64_t(this->field_690) * int64_t(var1->field_37)) >> 12) + ((int64_t(this->field_693) * int64_t(var1->field_38)) >> 12)) + ((int64_t(this->field_696) * int64_t(var1->field_39)) >> 12);
    int64_t var7 = (((int64_t(this->field_691) * int64_t(var1->field_37)) >> 12) + ((int64_t(this->field_694) * int64_t(var1->field_38)) >> 12)) + ((int64_t(this->field_697) * int64_t(var1->field_39)) >> 12);
    var2->field_37 = int32_t(var3);
    var2->field_38 = int32_t(var5);
    var2->field_39 = int32_t(var7);
    return var2;
}

jrt::Ref<jrt::Array<jrt::Ref<class_3>>> class_57::method_510(jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var1, jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var2) {
    for (int32_t var3 = var2->length - 1; var3 >= 0; var3--) {
        var2->at(var3)->field_37 = (((this->field_689 * var1->at(var3)->field_37) >> 12) + ((this->field_692 * var1->at(var3)->field_38) >> 12)) + ((this->field_695 * var1->at(var3)->field_39) >> 12);
        var2->at(var3)->field_38 = (((this->field_690 * var1->at(var3)->field_37) >> 12) + ((this->field_693 * var1->at(var3)->field_38) >> 12)) + ((this->field_696 * var1->at(var3)->field_39) >> 12);
        var2->at(var3)->field_39 = (((this->field_691 * var1->at(var3)->field_37) >> 12) + ((this->field_694 * var1->at(var3)->field_38) >> 12)) + ((this->field_697 * var1->at(var3)->field_39) >> 12);
    }
    return var2;
}

jrt::Ref<class_3> class_57::method_511(jrt::Ref<class_3> var1) {
    int32_t var2 = jrt::div(16777216, this->field_686);
    int32_t var3 = jrt::div(16777216, this->field_687);
    int32_t var4 = jrt::div(16777216, this->field_688);
    int32_t var5 = int32_t((var2 * (((-((int64_t(this->field_689) * int64_t(this->field_698)) >> 12)) - ((int64_t(this->field_690) * int64_t(this->field_699)) >> 12)) - ((int64_t(this->field_691) * int64_t(this->field_700)) >> 12))) >> 12);
    int32_t var6 = int32_t((var3 * (((-((int64_t(this->field_692) * int64_t(this->field_698)) >> 12)) - ((int64_t(this->field_693) * int64_t(this->field_699)) >> 12)) - ((int64_t(this->field_694) * int64_t(this->field_700)) >> 12))) >> 12);
    int32_t var7 = int32_t((var4 * (((-((int64_t(this->field_695) * int64_t(this->field_698)) >> 12)) - ((int64_t(this->field_696) * int64_t(this->field_699)) >> 12)) - ((int64_t(this->field_697) * int64_t(this->field_700)) >> 12))) >> 12);
    int32_t var8 = var1->field_37;
    int32_t var9 = var1->field_38;
    int32_t var10 = var1->field_39;
    var1->field_37 = int32_t(((((((int64_t(var2) * int64_t(this->field_689)) >> 12) * var8) >> 12) + ((((int64_t(var3) * int64_t(this->field_690)) >> 12) * var9) >> 12)) + ((((int64_t(var4) * int64_t(this->field_691)) >> 12) * var10) >> 12)) + var5);
    var1->field_38 = int32_t(((((((int64_t(var2) * int64_t(this->field_692)) >> 12) * var8) >> 12) + ((((int64_t(var3) * int64_t(this->field_693)) >> 12) * var9) >> 12)) + ((((int64_t(var4) * int64_t(this->field_694)) >> 12) * var10) >> 12)) + var6);
    var1->field_39 = int32_t(((((((int64_t(var2) * int64_t(this->field_695)) >> 12) * var8) >> 12) + ((((int64_t(var3) * int64_t(this->field_696)) >> 12) * var9) >> 12)) + ((((int64_t(var4) * int64_t(this->field_697)) >> 12) * var10) >> 12)) + var7);
    return var1;
}

void class_57::method_512(jrt::Ref<class_3> var1) {
    class_57::field_705->method_9(var1);
    class_57::field_705->method_22();
    this->field_695 = class_57::field_705->field_37;
    this->field_696 = class_57::field_705->field_38;
    this->field_697 = class_57::field_705->field_39;
    this->field_692 = 0;
    this->field_693 = 4096;
    this->field_694 = 0;
    this->field_689 = ((this->field_693 * this->field_697) >> 12) - ((this->field_694 * this->field_696) >> 12);
    this->field_690 = ((this->field_694 * this->field_695) >> 12) - ((this->field_692 * this->field_697) >> 12);
    this->field_691 = ((this->field_692 * this->field_696) >> 12) - ((this->field_693 * this->field_695) >> 12);
    class_57::field_705->field_37 = this->field_689;
    class_57::field_705->field_38 = this->field_690;
    class_57::field_705->field_39 = this->field_691;
    class_57::field_705->method_22();
    this->field_689 = class_57::field_705->field_37;
    this->field_690 = class_57::field_705->field_38;
    this->field_691 = class_57::field_705->field_39;
    this->field_692 = ((this->field_696 * this->field_691) >> 12) - ((this->field_697 * this->field_690) >> 12);
    this->field_693 = ((this->field_697 * this->field_689) >> 12) - ((this->field_695 * this->field_691) >> 12);
    this->field_694 = ((this->field_695 * this->field_690) >> 12) - ((this->field_696 * this->field_689) >> 12);
    class_57::field_705->field_37 = this->field_692;
    class_57::field_705->field_38 = this->field_693;
    class_57::field_705->field_39 = this->field_694;
    class_57::field_705->method_22();
    this->field_692 = class_57::field_705->field_37;
    this->field_693 = class_57::field_705->field_38;
    this->field_694 = class_57::field_705->field_39;
}

void class_57::__dumpFields(jrt::Dumper& d) {
    d.f("field_685", this->field_685);
    d.f("field_686", this->field_686);
    d.f("field_687", this->field_687);
    d.f("field_688", this->field_688);
    d.f("field_689", this->field_689);
    d.f("field_690", this->field_690);
    d.f("field_691", this->field_691);
    d.f("field_692", this->field_692);
    d.f("field_693", this->field_693);
    d.f("field_694", this->field_694);
    d.f("field_695", this->field_695);
    d.f("field_696", this->field_696);
    d.f("field_697", this->field_697);
    d.f("field_698", this->field_698);
    d.f("field_699", this->field_699);
    d.f("field_700", this->field_700);
    d.f("field_701", this->field_701);
    d.f("field_702", this->field_702);
    d.f("field_703", this->field_703);
    d.f("field_704", this->field_704);
}

