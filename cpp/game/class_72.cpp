// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Graphics3D> class_72::field_1016{};
jrt::Ref<javax::microedition::m3g::Background> class_72::field_1017{};

void class_72::__clinit() {
}

void class_72::__init() {
    class_71::__init();
    class_72::field_1016 = javax::microedition::m3g::Graphics3D::getInstance();
    if (class_72::field_1017 == nullptr) {
        class_72::field_1017 = jrt::New<javax::microedition::m3g::Background>();
        class_72::field_1017->setColorClearEnable(false);
        class_72::field_1017->setDepthClearEnable(true);
    }
}

void class_72::method_683(jrt::Ref<javax::microedition::lcdui::Graphics> var1) {
    {
        try {
            class_72::field_1016->bindTarget(jrt::Ref<java::lang::Object>(var1));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
                class_72::field_1016->releaseTarget();
            } else {
                throw;
            }
        }
    }
}

void class_72::method_685() {
    if (org::deep3d::Remaster::worldPass()) {
        org::deep3d::Remaster::nextLayer();
        if (org::deep3d::Remaster::sharedDepth()) {
            return;
        }
    }
    {
        try {
            class_72::field_1016->clear(class_72::field_1017);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

void class_72::method_684(jrt::Ref<javax::microedition::lcdui::Graphics> var1) {
    {
        try {
            class_72::field_1016->releaseTarget();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

void class_72::__dumpFields(jrt::Dumper& d) {
    class_71::__dumpFields(d);
}

