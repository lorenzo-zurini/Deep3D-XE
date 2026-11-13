// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_62::__clinit() {
}

void class_62::__init() {
    class_61::__init();
}

void class_62::method_551() {
    {
        try {
            this->field_724 = class_28::method_282(JRT_LIT(u"/data/interface/fishlabs.png"));
            this->field_725 = class_28::method_282(JRT_LIT(u"/data/interface/abyss.png"));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                var2->printStackTrace();
            } else {
                throw;
            }
        }
    }
    this->field_727 = org::deep3d::Det::millis();
    this->field_728 = 0;
    this->field_726 = true;
    this->field_729 = 0;
    java::lang::System::gc();
    // Deep3D-PC: no "music on or off?" first: the settings have the volumes
    if (org::deep3d::Config::pcAdditions()) {
        class_84::field_1080 = true;
        class_84::field_1083 = 1;
        class_84::field_1122->method_765(100);
        class_84::field_1122->method_768(0);
        this->field_728 = 1;
    }
}

void class_62::method_552() {
    this->field_724 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    this->field_725 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    this->field_726 = false;
}

bool class_62::method_553() {
    return this->field_726;
}

void class_62::method_550(int32_t var1) {
    if (this->field_728 == 0) {
        if ((var1 == 2) && (this->field_729 == 1)) {
            this->field_729--;
        }
        if ((var1 == 64) && (this->field_729 == 0)) {
            this->field_729++;
        }
        if (var1 == 32768) {
            this->field_730++;
            if (this->field_730 > class_90::field_1218->length) {
                this->field_730 = 0;
            }
            this->field_731 = class_90::field_1218->at(this->field_730);
        }
        if ((var1 == 256) || (var1 == 16384)) {
            class_84::field_1080 = this->field_729 == 0;
            if (this->field_729 == 1) {
                class_84::field_1083 = 3;
            } else {
                class_84::field_1083 = 1;
            }
            class_84::field_1122->method_765(100);
            class_84::field_1122->method_768(0);
            this->field_727 = org::deep3d::Det::millis();
            this->field_728 = 1;
        }
    }
}

void class_62::method_549(int32_t var1) {
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    if (this->field_728 == 0) {
        class_84::field_1117->drawImage(class_33::method_292(), (class_84::field_1120 >> 1), 10, 17);
        class_67::method_584(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(6); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(14); return jrt::concat(__c1, __c2, __c3); }()), 0, (class_84::field_1121 >> 1), class_84::field_1120, (this->field_729 == 0));
        class_67::method_584(([&]() { jrt::Ref<java::lang::String> __c4 = class_84::field_1116->method_4(6); jrt::Ref<java::lang::String> __c5 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(15); return jrt::concat(__c4, __c5, __c6); }()), 0, ((class_84::field_1121 >> 1) + class_58::method_527()), class_84::field_1120, (this->field_729 == 1));
        class_67::method_601(class_84::field_1116->method_4(265), JRT_LIT(u""), false);
        if (this->field_731 != nullptr) {
            class_119::method_923(this->field_731, 0, 40, 0);
            class_58::method_518(class_90::field_1219->at(this->field_730), 40, 40, 0);
            return;
        }
    } else if (this->field_728 == 1) {
        class_84::field_1117->drawImage(this->field_724, (class_84::field_1120 / 2), (class_84::field_1121 / 2), 3);
        if ((org::deep3d::Det::millis() - this->field_727) > int64_t(3000)) {
            this->field_728++;
            return;
        }
    } else if (this->field_728 == 2) {
        class_84::field_1117->drawImage(this->field_725, (class_84::field_1120 / 2), (class_84::field_1121 / 2), 3);
        if ((org::deep3d::Det::millis() - this->field_727) > int64_t(6000)) {
            this->field_728++;
            return;
        }
    } else {
        class_84::field_1126->method_439(class_84::field_1127->at(0));
    }
}

void class_62::__dumpFields(jrt::Dumper& d) {
    class_61::__dumpFields(d);
    d.f("field_724", this->field_724);
    d.f("field_725", this->field_725);
    d.f("field_726", this->field_726);
    d.f("field_727", this->field_727);
    d.f("field_728", this->field_728);
    d.f("field_729", this->field_729);
    d.f("field_730", this->field_730);
    d.f("field_731", this->field_731);
}

