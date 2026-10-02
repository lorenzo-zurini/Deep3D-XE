// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_45::__clinit() {
}

void class_45::__init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1) {
    class_44::__init();
    if (var1 != nullptr) {
        this->field_476 = jrt::newArray<jrt::Ref<javax::microedition::m3g::Texture2D>>(var1->length);
        for (int32_t var2 = 0; var2 < var1->length; var2++) {
            {
                try {
                    jrt::Ref<javax::microedition::lcdui::Image> var3 = class_28::method_282(jrt::concat(var1->at(var2), JRT_LIT(u".png")));
                    jrt::Ref<javax::microedition::m3g::Image2D> var4 = jrt::New<javax::microedition::m3g::Image2D>(100, jrt::Ref<java::lang::Object>(var3));
                    this->field_476->at(var2) = jrt::New<javax::microedition::m3g::Texture2D>(var4);
                    this->field_476->at(var2)->setBlending(228);
                    this->field_476->at(var2)->setWrapping(241, 241);
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex1.t);
                        this->field_476 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>>(nullptr);
                    } else {
                        throw;
                    }
                }
            }
        }
    }
}

void class_45::method_387() {
    if (this->field_476 != nullptr) {
        for (int32_t var1 = 0; var1 < this->field_476->length; var1++) {
            this->field_476->at(var1) = jrt::Ref<javax::microedition::m3g::Texture2D>(nullptr);
        }
        this->field_476 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>>(nullptr);
    }
}

void class_45::__dumpFields(jrt::Dumper& d) {
    class_44::__dumpFields(d);
    d.f("field_476", this->field_476);
}

