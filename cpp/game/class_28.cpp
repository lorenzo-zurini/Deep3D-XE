// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<java::lang::Class> class_28::field_304{};

void class_28::__clinit() {
}

void class_28::__init() {
}

jrt::Ref<javax::microedition::lcdui::Image> class_28::method_280(jrt::Ref<javax::microedition::lcdui::Image> var0, int32_t var1, int32_t var2) {
    {
        try {
            float var3 = float(var1) / float(var0->getWidth());
            float var4 = float(var2) / float(var0->getHeight());
            int32_t var5 = var0->getWidth();
            int32_t var6 = var0->getHeight();
            jrt::Ref<jrt::Array<int32_t>> var7 = jrt::newArray<int32_t>((var5 * var6));
            jrt::Ref<jrt::Array<int32_t>> var8 = jrt::newArray<int32_t>((jrt::f2i((float(var5) * var3)) * jrt::f2i((float(var6) * var4))));
            var0->getRGB(var7, 0, var5, 0, 0, var5, var6);
            var0 = javax::microedition::lcdui::Image::createRGBImage(class_28::method_281(var7, var8, var5, jrt::f2i((float(var5) * var3))), jrt::f2i((float(var5) * var3)), jrt::f2i((float(var6) * var4)), true);
            java::lang::System::gc();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var9 = jrt::cast<java::lang::Exception>(__ex1.t);
                var9->printStackTrace();
            } else {
                throw;
            }
        }
    }
    return var0;
}

jrt::Ref<jrt::Array<int32_t>> class_28::method_281(jrt::Ref<jrt::Array<int32_t>> var0, jrt::Ref<jrt::Array<int32_t>> var1, int32_t var2, int32_t var3) {
    int32_t var4 = jrt::div(var0->length, var2);
    int32_t var5 = jrt::div(var1->length, var3);
    for (int32_t var6 = 0; var6 < var3; var6++) {
        for (int32_t var7 = 0; var7 < var5; var7++) {
            float var8 = (float(var6) * float((var2 - 1))) / float((var3 - 1));
            int32_t var9 = 0;
            if ((double(var8) - java::lang::Math::floor(double(var8))) > 0.5) {
                var9 = jrt::f2i(java::lang::Math::ceil(double(var8)));
            } else {
                var9 = jrt::f2i(java::lang::Math::floor(double(var8)));
            }
            float var10 = (float(var7) * float((var4 - 1))) / float((var5 - 1));
            int32_t var11 = 0;
            if ((double(var10) - java::lang::Math::floor(double(var10))) > 0.5) {
                var11 = jrt::f2i(java::lang::Math::ceil(double(var10)));
            } else {
                var11 = jrt::f2i(java::lang::Math::floor(double(var10)));
            }
            var1->at((var6 + (var7 * var3))) = var0->at((var9 + (var11 * var2)));
        }
    }
    return var1;
}

jrt::Ref<javax::microedition::lcdui::Image> class_28::method_282(jrt::Ref<java::lang::String> var0) {
    jrt::Ref<javax::microedition::lcdui::Image> var1 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    {
        try {
            jrt::Ref<java::io::InputStream> var2 = jrt::getResourceAsStream(var0);
            jrt::Ref<java::io::DataInputStream> var3{};
            int32_t var4{};
            jrt::Ref<jrt::Array<int8_t>> var5 = jrt::newArray<int8_t>(var4 = (var3 = jrt::New<java::io::DataInputStream>(var2))->available());
            var3->read(var5, 0, var4);
            var3->close();
            int32_t var6{};
            if (var4 < 100) {
                var6 = 10 + (var4 % 10);
            } else if (var4 < 200) {
                var6 = 50 + (var4 % 20);
            } else if (var4 < 300) {
                var6 = 80 + (var4 % 20);
            } else {
                var6 = 100 + (var4 % 50);
            }
            for (int32_t var7 = 0; var7 < var6; var7++) {
                int8_t var8 = var5->at(var7);
                var5->at(var7) = var5->at(((var4 - var7) - 1));
                var5->at(((var4 - var7) - 1)) = var8;
            }
            var1 = javax::microedition::lcdui::Image::createImage(var5, 0, var4);
            java::lang::System::gc();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var9 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    return var1;
}

jrt::Ref<jrt::Array<int8_t>> class_28::method_283(jrt::Ref<java::lang::String> var0) {
    jrt::Ref<jrt::Array<int8_t>> var1 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    {
        try {
            jrt::Ref<java::io::InputStream> var2 = jrt::getResourceAsStream(var0);
            jrt::Ref<java::io::DataInputStream> var3{};
            int32_t var4{};
            var1 = jrt::newArray<int8_t>(var4 = (var3 = jrt::New<java::io::DataInputStream>(var2))->available());
            var3->read(var1, 0, var4);
            var3->close();
            int32_t var5{};
            if (var4 < 100) {
                var5 = 10 + (var4 % 10);
            } else if (var4 < 200) {
                var5 = 50 + (var4 % 20);
            } else if (var4 < 300) {
                var5 = 80 + (var4 % 20);
            } else {
                var5 = 100 + (var4 % 50);
            }
            for (int32_t var6 = 0; var6 < var5; var6++) {
                int8_t var7 = var1->at(var6);
                var1->at(var6) = var1->at(((var4 - var6) - 1));
                var1->at(((var4 - var6) - 1)) = var7;
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var8 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    return var1;
}

jrt::Ref<java::lang::Class> class_28::method_284(jrt::Ref<java::lang::String> var0) {
    {
        try {
            return java::lang::Class::forName(var0);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::ClassNotFoundException>(__ex1.t)) {
                jrt::Ref<java::lang::ClassNotFoundException> var2 = jrt::cast<java::lang::ClassNotFoundException>(__ex1.t);
                jrt::throwJava(jrt::New<java::lang::NoClassDefFoundError>(var2->getMessage()));
            } else {
                throw;
            }
        }
    }
}

void class_28::__dumpFields(jrt::Dumper& d) {
}

