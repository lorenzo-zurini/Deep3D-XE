// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<int32_t>> class_33::field_330{};
jrt::Ref<javax::microedition::lcdui::Image> class_33::field_334{};
jrt::Ref<java::lang::String> class_33::field_341{};

void class_33::__clinit() {
    class_33::field_330 = jrt::arrayOf<int32_t>({50, 40, 30, 40, 50, 60, 70, 60, 50});
    class_33::field_341 = JRT_LIT(u"");
}

void class_33::__init() {
    this->field_331 = false;
    class_33::field_334 = class_28::method_282(JRT_LIT(u"/data/interface/logo.png"));
    this->field_335 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(6);
    for (int32_t var1 = 0; var1 < this->field_335->length; var1++) {
        this->field_335->at(var1) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/bubble_"), var1, JRT_LIT(u".png")));
    }
    this->field_336 = jrt::newArray<int32_t>(18);
    this->field_329 = class_84::field_1120 - 50;
    for (int32_t var2 = 0; var2 < this->field_336->length; var2 += 2) {
        this->field_336->at(var2) = this->field_329 + jrt::f2i(((float(class_33::field_330->at((var2 >> 1))) / 100.0f) * 50.0f));
        this->field_336->at((var2 + 1)) = class_84::field_1121 - ((var2 >> 1) * (class_84::field_1121 / 8));
    }
}

jrt::Ref<javax::microedition::lcdui::Image> class_33::method_292() {
    return class_33::field_334;
}

void class_33::run() {
    while (this->field_331 && (!class_84::field_1125)) {
        this->method_293();
        if (this->field_332 != nullptr) {
            this->field_332->flushGraphics();
        }
        {
            try {
                java::lang::Thread::sleep(int64_t(10));
            } catch (const jrt::Thrown& __ex1) {
                if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                    jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                    this->field_331 = false;
                } else {
                    throw;
                }
            }
        }
    }
}

void class_33::method_293() {
    this->field_337 = class_67::method_575();
    class_84::field_1117->setColor((class_14::method_70() ? (-8626622) : class_67::field_845));
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    class_58::method_518(this->field_340, ((class_84::field_1120 / 2) - (class_58::method_523(this->field_340) / 2)), (((class_84::field_1121 / 2) - (class_58::method_527() / 2)) - 10), 0);
    class_58::method_518(class_33::field_341, ((class_84::field_1120 / 2) - (class_58::method_523(this->field_340) / 2)), (((class_84::field_1121 / 2) - (class_58::method_527() * 2)) - 10), 0);
    for (int32_t var1 = 0; var1 < 9; var1++) {
        int32_t var2 = class_14::method_70() ? ((this->field_338 == var1) ? 5 : 4) : (this->field_337 ? ((this->field_338 == var1) ? 3 : 2) : ((this->field_338 == var1) ? 1 : 0));
        class_84::field_1117->drawImage(this->field_335->at(var2), this->field_336->at((var1 << 1)), this->field_336->at(((var1 << 1) + 1)), 3);
    }
    // Deep3D-PC: one a step, not one a draw (this thread has no game frames: the clock)
    if (org::deep3d::Step::exact()) {
        this->field_338++;
    } else if ((org::deep3d::Det::uiNanos() - this->deep3dBubbleAt) >= int64_t(33000000)) {
        this->deep3dBubbleAt = org::deep3d::Det::uiNanos();
        this->field_338++;
    }
    if (this->field_338 > 9) {
        this->field_338 = 0;
    }
    class_84::field_1117->drawImage(class_33::field_334, (class_84::field_1120 >> 1), 10, 17);
    if (((class_84::field_1126 != nullptr) && (class_84::field_1126->field_595 != nullptr)) && (class_84::field_1126->field_595 != class_84::field_1127->at(3))) {
        this->method_294();
    }
}

void class_33::method_294() {
    class_67::method_582(10, ((class_84::field_1121 - (10 * this->field_339->length)) - 32), (class_84::field_1120 - 20), ((10 * this->field_339->length) + 20));
    class_67::method_592(class_84::field_1116->method_4(305), 10, ((class_84::field_1121 - (10 * this->field_339->length)) - 32), (class_84::field_1120 - 20), ((10 * this->field_339->length) + 20), false);
    class_58::method_521(this->field_339, 15, ((class_84::field_1121 - (10 * this->field_339->length)) - 20), 1);
}

void class_33::method_295() {
    this->field_331 = false;
}

void class_33::method_296(bool var1) {
    this->field_340 = class_84::field_1116->method_4((var1 ? 229 : 230));
    int32_t var2 = class_84::field_1123->nextInt(class_1::field_5->length);
    if (class_21::method_143() < 12) {
        var2 = 4 + class_84::field_1123->nextInt((class_1::field_5->length - 4));
    }
    this->field_339 = class_58::method_532(class_84::field_1116->method_4(int32_t(class_1::field_5->at(var2))), (class_84::field_1120 - 30));
    this->field_331 = true;
    this->field_333 = jrt::New<java::lang::Thread>(jrt::Ref<java::lang::Runnable>(jrt::Ref<class_33>(this)));
    this->field_333->start();
}

void class_33::__dumpFields(jrt::Dumper& d) {
    d.f("field_329", this->field_329);
    d.f("field_331", this->field_331);
    d.f("field_332", this->field_332);
    d.f("field_333", this->field_333);
    d.f("field_335", this->field_335);
    d.f("field_336", this->field_336);
    d.f("field_337", this->field_337);
    d.f("field_338", this->field_338);
    d.f("field_339", this->field_339);
    d.f("field_340", this->field_340);
}

