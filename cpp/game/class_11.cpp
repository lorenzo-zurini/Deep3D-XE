// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_11::__clinit() {
}

void class_11::__init() {
    this->field_117 = jrt::New<class_3>();
    {
        try {
            this->field_116 = class_28::method_282(JRT_LIT(u"/data/interface/crosshair.png"));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                var2->printStackTrace();
            } else {
                throw;
            }
        }
    }
    this->field_115 = jrt::newArray<int32_t>(3);
}

void class_11::method_55(jrt::Ref<class_57> var1) {
    this->field_115->at(0) = var1->field_698 + (5 * var1->field_695);
    this->field_115->at(1) = var1->field_699 + (5 * var1->field_696);
    this->field_115->at(2) = var1->field_700 + (5 * var1->field_697);
    this->field_117->method_10(this->field_115->at(0), this->field_115->at(1), this->field_115->at(2));
}

void class_11::method_56() {
    this->field_115 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_116 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
}

void class_11::method_57(jrt::Ref<class_106> var1) {
    var1->method_883(this->field_117);
    // Deep3D-PC: the reticle holds still near the middle (mouse flight aims from
    // there); the phone's drifted with the point ahead of the sub
    int32_t var2 = org::deep3d::Config::pcAdditions() ? class_84::field_1120 >> 1 : this->field_117->field_37;
    int32_t var3 = org::deep3d::Config::pcAdditions() ? (class_84::field_1121 * 157) / 320 : this->field_117->field_38;
    class_84::field_1117->drawImage(this->field_116, var2, var3, 3);
    org::deep3d::MouseFlight::crosshair(var2, var3);
}

void class_11::__dumpFields(jrt::Dumper& d) {
    d.f("field_115", this->field_115);
    d.f("field_116", this->field_116);
    d.f("field_117", this->field_117);
}

