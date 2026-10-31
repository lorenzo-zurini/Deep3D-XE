// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_50::field_546{};

void class_50::__clinit() {
    class_50::field_546 = 30;
}

void class_50::__init() {
    this->field_549 = ([&]() { jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> __a1 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_84::field_1116->method_4(64), class_84::field_1116->method_4(63)}); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(64); jrt::Ref<class_77> __o(new class_77()); __o->__init(__a1, __a2); return __o; }());
    this->field_547 = false;
    this->field_548 = jrt::New<class_121>(20, (class_84::field_1121 / 3), (class_84::field_1120 - 40));
    this->field_550 = jrt::New<class_23>(10, class_50::field_546, (class_84::field_1120 - 20), (((class_84::field_1121 - class_50::field_546) - class_67::method_577()) - 18), JRT_LIT(u""));
    this->field_550->field_249 = 1;
    this->field_551 = jrt::New<class_23>(10, class_50::field_546, (class_84::field_1120 - 20), (((class_84::field_1121 - class_50::field_546) - class_67::method_577()) - 18), JRT_LIT(u""));
    this->field_551->field_248 = true;
    this->method_410();
}

void class_50::method_410() {
    this->field_550->method_227(class_21::method_215(), class_21::method_217(), class_21::method_213(), true);
    this->field_551->method_227(class_21::method_215(), class_21::method_217(), class_21::method_213(), true);
    jrt::Ref<java::lang::String> var1 = class_84::field_1116->method_4(141);
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(71));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(82));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(79));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(319));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(320));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(37));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(322));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(321));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(72));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(313));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(311));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(312));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(316));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(317));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(314));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(318));
    var1 = jrt::concat(var1, JRT_LIT(u"\n"), class_84::field_1116->method_4(315));
    this->field_550->method_225(var1);
    jrt::Ref<java::lang::String> var2 = jrt::concat(JRT_LIT(u""), class_21::method_210());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_48::method_398(class_21::method_212()));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_182(), JRT_LIT(u" $"));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_84::field_1116->method_4(int32_t(class_1::field_8->at(class_21::method_178()->field_863)->at(0))));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_178()->field_882);
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_178()->method_604());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_209());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), org::deep3d::Scale::depth(class_21::method_160()), JRT_LIT(u"m"));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), org::deep3d::Scale::depth(class_21::method_159()), JRT_LIT(u"m"));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_202());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_208());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_170());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_172());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_156(), JRT_LIT(u"t"));
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_154());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_177());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_151());
    var2 = jrt::concat(var2, JRT_LIT(u"\n"), class_21::method_191());
    this->field_551->method_225(var2);
}

bool class_50::method_411(int32_t var1) {
    if ((((var1 == 256) || (var1 == 16384)) && (this->field_549->field_1038 == 1)) && (!this->field_547)) {
        jrt::Ref<class_59> var2 = jrt::cast<class_59>(this->field_549->method_701());
        if (class_14::method_71()->at(var2->field_716) != 0) {
            this->field_548->method_939(class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_0->at(var2->field_716)->at(1))), jrt::concat(org::deep3d::Scale::medal(var2->field_716, class_14::field_135->at(var2->field_716)->at((var2->field_715 - 1))), JRT_LIT(u""))));
            this->field_547 = true;
        }
        return true;
    } else if (this->field_547) {
        if ((this->field_549->field_1038 == 1) && (var1 == 256)) {
            this->field_547 = false;
        }
        return true;
    } else {
        if (var1 == 4) {
            this->field_549->method_706();
        }
        if (var1 == 32) {
            this->field_549->method_707();
        }
        if (var1 == 2) {
            this->field_549->method_704();
        }
        if (var1 == 64) {
            this->field_549->method_705();
        }
        return var1 != 8192;
    }
}

bool class_50::method_412() {
    return this->field_549->field_1038 == 1;
}

void class_50::method_413(int32_t var1, int32_t var2) {
    org::deep3d::GameUi::controls(1, (-6), (-7), 0);
    if (((var1 & 2) != 0) && (this->field_549->field_1038 == 0)) {
        this->field_550->deep3dHeldUp((var2 / 2), 1);
        this->field_551->deep3dHeldUp((var2 / 2), 1);
    }
    if (((var1 & 64) != 0) && (this->field_549->field_1038 == 0)) {
        this->field_550->deep3dHeldDown((var2 / 2), 1);
        this->field_551->deep3dHeldDown((var2 / 2), 1);
    }
    class_67::method_587();
    this->field_549->method_718();
    if (this->field_549->field_1038 == 0) {
        this->method_414();
        class_67::method_593(JRT_LIT(u""), class_84::field_1116->method_4(65));
    } else {
        [&]() { jrt::Ref<java::lang::String> __a1 = (((jrt::cast<class_59>(this->field_549->method_701()))->field_715 > 0) ? class_84::field_1116->method_4(226) : JRT_LIT(u"")); jrt::Ref<java::lang::String> __a2 = class_84::field_1116->method_4(65); return class_67::method_593(__a1, __a2); }();
    }
    if (this->field_547) {
        this->field_548->method_944();
    }
}

void class_50::method_414() {
    this->field_550->method_231();
    this->field_551->method_231();
}

void class_50::__dumpFields(jrt::Dumper& d) {
    d.f("field_547", this->field_547);
    d.f("field_548", this->field_548);
    d.f("field_549", this->field_549);
    d.f("field_550", this->field_550);
    d.f("field_551", this->field_551);
}

