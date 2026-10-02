// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<class_73>>> class_58::field_706{};
jrt::Ref<javax::microedition::lcdui::Graphics> class_58::field_707{};
int32_t class_58::field_708{};

void class_58::__clinit() {
}

void class_58::__init() {
}

void class_58::method_513() {
    class_58::field_706 = jrt::Ref<jrt::Array<jrt::Ref<class_73>>>(nullptr);
    java::lang::System::gc();
}

void class_58::method_514(jrt::Ref<javax::microedition::lcdui::Graphics> var0) {
    class_58::field_707 = var0;
}

void class_58::method_515(jrt::Ref<java::lang::String> var0) {
    if (class_58::field_707 != nullptr) {
        if (class_58::field_706 == nullptr) {
            class_58::field_706 = jrt::newArray<jrt::Ref<class_73>>(1);
            class_58::field_706->at(0) = jrt::New<class_73>(var0, class_58::field_707);
            return;
        }
        jrt::Ref<jrt::Array<jrt::Ref<class_73>>> var1 = jrt::newArray<jrt::Ref<class_73>>((class_58::field_706->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_58::field_706), 0, jrt::Ref<java::lang::Object>(var1), 0, class_58::field_706->length);
        var1->at(class_58::field_706->length) = jrt::New<class_73>(var0, class_58::field_707);
        class_58::field_706 = var1;
    }
}

void class_58::method_516(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    if ((var3 >= 0) && (var3 < class_58::field_706->length)) {
        class_58::field_708 = var3;
        if ((var4 & 8) != 0) {
            var1 -= (class_58::field_706->at(class_58::field_708)->method_690(var0) >> 1);
        }
        if ((var4 & 4) != 0) {
            var2 -= (int32_t(class_58::field_706->at(class_58::field_708)->field_1022) >> 1);
        } else if ((var4 & 32) != 0) {
            var2 -= int32_t(class_58::field_706->at(class_58::field_708)->field_1022);
        }
        if ((var4 & 2) != 0) {
            class_58::field_706->at(class_58::field_708)->method_694(var0, var1, var2);
        } else {
            class_58::field_706->at(class_58::field_708)->method_693(var0, var1, var2);
        }
    }
}

void class_58::method_517(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2) {
    class_58::field_706->at(class_58::field_708)->method_693(var0, var1, var2);
}

void class_58::method_518(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3) {
    if ((var3 >= 0) && (var3 < class_58::field_706->length)) {
        class_58::field_708 = var3;
        class_58::field_706->at(class_58::field_708)->method_693(var0, var1, var2);
    }
}

void class_58::method_519(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    class_58::method_520(var0, var1, var2, var3, var4, 0, (var0->length - 1));
}

void class_58::method_520(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6) {
    var6 = (var6 <= (var0->length - 1)) ? var6 : (var0->length - 1);
    var5 = (var5 <= var6) ? var5 : var6;
    if ((var3 >= 0) && (var3 < class_58::field_706->length)) {
        class_58::field_708 = var3;
        {
            int32_t var12{};
            int32_t var11{};
            int32_t var7{};
            switch (var4) {
            case 1:
                var12 = var5;
                for (int32_t var14 = 0; var12 < (var6 + 1); var14++) {
                    class_58::field_706->at(class_58::field_708)->method_693(var0->at(var12), var1, (var2 + (var14 * class_58::method_527())));
                    var12++;
                }
                return;
            case 2:
                var11 = var5;
                for (int32_t var13 = 0; var11 < (var6 + 1); var13++) {
                    class_58::field_706->at(class_58::field_708)->method_695(var0->at(var11), var1, (var2 + (var13 * class_58::method_527())));
                    var11++;
                }
                return;
            case 3:
                var7 = var5;
                for (int32_t var8 = 0; var7 < (var6 + 1); var8++) {
                    class_58::field_706->at(class_58::field_708)->method_693(var0->at(var7), (var1 - (class_58::method_523(var0->at(var7)) >> 1)), (var2 + (var8 * class_58::method_527())));
                    var7++;
                }
            }
        }
    }
}

void class_58::method_521(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3) {
    if ((var3 >= 0) && (var3 < class_58::field_706->length)) {
        class_58::field_708 = var3;
        for (int32_t var4 = 0; var4 < var0->length; var4++) {
            class_58::field_706->at(class_58::field_708)->method_693(var0->at(var4), var1, (var2 + (var4 * class_58::method_527())));
        }
    }
}

void class_58::method_522(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    if ((var4 >= 0) && (var4 < class_58::field_706->length)) {
        class_58::field_706->at(var4)->method_687(var0, var1, var2, var3);
    }
}

int32_t class_58::method_523(jrt::Ref<java::lang::String> var0) {
    return class_58::field_706->at(class_58::field_708)->method_690(var0);
}

int32_t class_58::method_524(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2) {
    return class_58::field_706->at(class_58::field_708)->method_691(var0, var1, var2);
}

void class_58::method_525(int32_t var0) {
    class_58::field_706->at(class_58::field_708)->method_688(var0);
}

void class_58::method_526(int32_t var0, int32_t var1) {
    if ((var1 >= 0) && (var1 < class_58::field_706->length)) {
        class_58::field_706->at(var1)->method_688(var0);
    }
}

int32_t class_58::method_527() {
    return int32_t(class_58::field_706->at(class_58::field_708)->field_1022);
}

int32_t class_58::method_528() {
    return int32_t(class_58::field_706->at(class_58::field_708)->field_1023);
}

void class_58::method_529(int32_t var0) {
    class_58::field_706->at(class_58::field_708)->method_696(var0);
}

int32_t class_58::method_530(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0) {
    return int32_t(class_58::field_706->at(class_58::field_708)->field_1022) * var0->length;
}

void class_58::method_531(int32_t var0, int32_t var1) {
    if ((var1 >= 0) && (var1 < class_58::field_706->length)) {
        class_58::field_706->at(var1)->method_696(var0);
    }
}

jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_58::method_532(jrt::Ref<java::lang::String> var0, int32_t var1) {
    if (var0 == nullptr) {
        return jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
    } else {
        int32_t var2 = 0;
        int32_t var3 = 0;
        jrt::Ref<java::lang::String> var4 = jrt::Ref<java::lang::String>(nullptr);
        var0 = jrt::concat(var0, JRT_LIT(u"\n"));
        while (var3 < var0->length()) {
            var4 = class_58::method_533(var0->substring(var3, var0->length()), var1, false);
            var2++;
            var3 += var4->length();
        }
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5 = jrt::newArray<jrt::Ref<java::lang::String>>(var2);
        var3 = 0;
        for (int32_t var6 = 0; var6 < var2; var6++) {
            var5->at(var6) = class_58::method_533(var0->substring(var3, var0->length()), var1, false);
            var3 += var5->at(var6)->length();
            var5->at(var6)->trim();
        }
        return var5;
    }
}

jrt::Ref<java::lang::String> class_58::method_533(jrt::Ref<java::lang::String> var0, int32_t var1, bool var2) {
    if (var0 == nullptr) {
        return jrt::Ref<java::lang::String>(nullptr);
    } else {
        int32_t var3 = 0;
        bool var4 = false;
        int32_t var5 = class_58::method_528() >> 1;
        bool var6 = false;
        bool var7 = false;
        for (int32_t var8 = 0; var8 < var0->length(); var8++) {
            if (var2 || (int32_t(var0->charAt(var8)) == int32_t(u' '))) {
                var3 = var8;
            }
            if ((var5 += class_58::method_524(var0, var8, (var8 + 1))) >= var1) {
                if (0 < var3) {
                    return var0->substring(0, (var3 + 1));
                }
                return var0->substring(0, (var8 + 1));
            }
            if ((int32_t(var0->charAt(var8)) == int32_t(char16_t(10))) || (int32_t(var0->charAt(var8)) == int32_t(char16_t(13)))) {
                return var0->substring(0, (var8 + 1));
            }
        }
        return (0 < (var0->length() - 1)) ? var0->substring(0, var0->length()) : JRT_LIT(u"");
    }
}

void class_58::__dumpFields(jrt::Dumper& d) {
}

