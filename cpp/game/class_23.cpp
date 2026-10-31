// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_23::__clinit() {
}

void class_23::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<java::lang::String> var5) {
    this->field_228 = var1;
    this->field_229 = var2;
    this->field_230 = var3;
    this->field_231 = var4;
    this->field_232 = 0;
    if (var5 != nullptr) {
        this->method_225(var5);
    }
    this->field_248 = false;
    this->field_249 = 0;
}

void class_23::method_224() {
    this->field_232 = 0;
}

void class_23::method_225(jrt::Ref<java::lang::String> var1) {
    this->field_238 = var1;
    if ((this->field_240 == nullptr) && (this->field_241 == nullptr)) {
        this->field_244 = 0;
    }
    if (var1 != nullptr) {
        if (this->field_239 != nullptr) {
            this->field_244 = this->field_244 + this->field_237;
        }
        this->field_233 = class_58::method_532(var1, (this->field_230 + 5));
        this->field_234 = class_58::method_530(this->field_233) + this->field_244;
        this->field_235 = this->field_234 > this->field_231;
        if (this->field_235) {
            this->field_233 = class_58::method_532(var1, (this->field_230 - 3));
            this->field_234 = class_58::method_530(this->field_233) + this->field_244;
            this->field_236 = jrt::f2i(((float(this->field_231) / float(this->field_234)) * float(this->field_231))) - 1;
        }
    }
}

void class_23::method_226(jrt::Ref<jrt::Array<int8_t>> var1, jrt::Ref<java::lang::String> var2, bool var3) {
    this->method_227(var1, jrt::Ref<javax::microedition::lcdui::Image>(nullptr), var2, var3);
}

void class_23::method_227(jrt::Ref<jrt::Array<int8_t>> var1, jrt::Ref<javax::microedition::lcdui::Image> var2, jrt::Ref<java::lang::String> var3, bool var4) {
    this->field_240 = var1;
    this->field_241 = var2;
    this->field_242 = var4;
    this->field_243 = class_58::method_532(var3, ((this->field_230 - class_119::field_1458) - 2));
    this->field_244 = class_119::field_1459 + 4;
    this->method_225(this->field_238);
}

void class_23::method_228(jrt::Ref<javax::microedition::lcdui::Image> var1, int32_t var2, int32_t var3) {
    this->field_245 = var1;
    this->field_246 = var2;
    this->field_247 = var3;
    this->field_244 += 22;
    this->method_225(this->field_238);
}

void class_23::method_229(int32_t var1) {
    if (this->field_234 > this->field_231) {
        this->field_232 -= (var1 / 10);
        if (this->field_232 < (-(this->field_234 - this->field_231))) {
            this->field_232 = -(this->field_234 - this->field_231);
        }
    }
}

void class_23::method_230(int32_t var1) {
    this->field_232 += (var1 / 10);
    if (this->field_232 > 0) {
        this->field_232 = 0;
    }
}

/* Deep3D-PC: while a key is held these run every frame, and dt / 10 is 0 under
   10 ms: the text moves a step's share */
void class_23::deep3dHeldDown(int32_t var1, int32_t perStep) {
    this->method_229(org::deep3d::Step::exact() ? var1 : (10 * org::deep3d::Step::share(perStep, this->deep3dScroll)));
}

void class_23::deep3dHeldUp(int32_t var1, int32_t perStep) {
    this->method_230(org::deep3d::Step::exact() ? var1 : (10 * org::deep3d::Step::share(perStep, this->deep3dScroll)));
}

void class_23::method_231() {
    org::deep3d::GameUi::scrollArea(this->field_228, this->field_229, this->field_230, this->field_231, false);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->setClip(this->field_228, this->field_229, this->field_230, this->field_231);
    if (this->field_239 != nullptr) {
        class_58::method_521(this->field_239, this->field_228, (this->field_229 + this->field_232), 0);
    }
    if ((this->field_240 != nullptr) || (this->field_241 != nullptr)) {
        class_84::field_1117->drawRect((this->field_242 ? this->field_228 : (((this->field_228 + this->field_230) - class_119::field_1458) - 4)), ((this->field_229 + this->field_232) + this->field_237), (class_119::field_1458 + 1), (class_119::field_1459 + 1));
    }
    if (this->field_240 != nullptr) {
        class_119::method_923(this->field_240, (this->field_242 ? (this->field_228 + 1) : (((this->field_228 + this->field_230) - class_119::field_1458) - 3)), (((this->field_229 + this->field_232) + 1) + this->field_237), 0);
    } else if (this->field_241 != nullptr) {
        class_84::field_1117->drawImage(this->field_241, (this->field_242 ? (this->field_228 + 1) : (((this->field_228 + this->field_230) - class_119::field_1458) - 3)), (((this->field_229 + this->field_232) + 1) + this->field_237), 0);
    }
    if (this->field_243 != nullptr) {
        class_58::method_519(this->field_243, (this->field_242 ? ((this->field_228 + class_119::field_1458) + 6) : (((this->field_228 + this->field_230) - class_119::field_1458) - 8)), ((this->field_229 + this->field_232) + this->field_237), 0, (this->field_242 ? 1 : 2));
    }
    if (this->field_245 != nullptr) {
        class_84::field_1117->drawImage(this->field_245, (this->field_228 + 1), (((((this->field_229 + this->field_232) + 1) + this->field_237) + class_119::field_1459) + 4), 0);
        class_58::method_517(jrt::concat(((this->field_246 > 0) ? jrt::concat(this->field_246, JRT_LIT(u"t ")) : JRT_LIT(u"")), class_84::field_1116->method_4(int32_t(class_1::field_7->at(this->field_247)->at(0)))), (this->field_228 + 23), (((((this->field_229 + this->field_232) + 1) + this->field_237) + class_119::field_1459) + 7));
    }
    if (this->field_233 != nullptr) {
        if (this->field_248) {
            class_58::method_519(this->field_233, ((this->field_228 + this->field_230) - 3), (((this->field_229 + this->field_232) + this->field_244) + this->field_237), this->field_249, 2);
        } else {
            class_58::method_521(this->field_233, this->field_228, (((this->field_229 + this->field_232) + this->field_244) + this->field_237), this->field_249);
        }
    }
    class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
    if (this->field_235) {
        class_84::field_1117->drawLine((this->field_228 + this->field_230), this->field_229, (this->field_228 + this->field_230), ((this->field_229 + this->field_231) - 4));
        class_84::field_1117->drawLine(((this->field_228 + this->field_230) - 1), (this->field_229 + 1), ((this->field_228 + this->field_230) + 1), (this->field_229 + 1));
        class_84::field_1117->drawLine(((this->field_228 + this->field_230) - 1), ((this->field_229 + this->field_231) - 5), ((this->field_228 + this->field_230) + 1), ((this->field_229 + this->field_231) - 5));
        if (class_67::method_581()) {
            class_84::field_1117->setColor(192, 192, 192);
        }
        class_84::field_1117->fillRect(((this->field_228 + this->field_230) - 1), ((this->field_229 + 2) - jrt::f2i(((float(this->field_232) / float(this->field_234)) * float((this->field_231 - 7))))), 3, this->field_236);
        class_84::field_1117->setColor(class_67::field_844);
    }
}

void class_23::__dumpFields(jrt::Dumper& d) {
    d.f("field_228", this->field_228);
    d.f("field_229", this->field_229);
    d.f("field_230", this->field_230);
    d.f("field_231", this->field_231);
    d.f("field_232", this->field_232);
    d.f("field_233", this->field_233);
    d.f("field_234", this->field_234);
    d.f("field_235", this->field_235);
    d.f("field_236", this->field_236);
    d.f("field_237", this->field_237);
    d.f("field_238", this->field_238);
    d.f("field_239", this->field_239);
    d.f("field_240", this->field_240);
    d.f("field_241", this->field_241);
    d.f("field_242", this->field_242);
    d.f("field_243", this->field_243);
    d.f("field_244", this->field_244);
    d.f("field_245", this->field_245);
    d.f("field_246", this->field_246);
    d.f("field_247", this->field_247);
    d.f("field_248", this->field_248);
    d.f("field_249", this->field_249);
}

