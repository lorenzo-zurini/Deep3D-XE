// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<int32_t>> class_43::field_466{};
jrt::Ref<jrt::Array<jrt::Ref<class_44>>> class_43::field_467{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_43::field_468{};
jrt::Ref<jrt::Array<bool>> class_43::field_469{};
jrt::Ref<jrt::Array<int32_t>> class_43::field_470{};
jrt::Ref<jrt::Array<jrt::Ref<class_108>>> class_43::field_471{};
jrt::Ref<jrt::Array<int32_t>> class_43::field_472{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_43::field_473{};
jrt::Ref<jrt::Array<bool>> class_43::field_474{};
jrt::Ref<jrt::Array<int32_t>> class_43::field_475{};

void class_43::__clinit() {
}

void class_43::__init() {
}

void class_43::method_377(int32_t var0, jrt::Ref<java::lang::String> var1) {
    if (class_43::field_468 == nullptr) {
        class_43::field_468 = jrt::newArray<jrt::Ref<java::lang::String>>(1);
        class_43::field_468->at(0) = var1;
        class_43::field_467 = jrt::newArray<jrt::Ref<class_44>>(1);
        class_43::field_466 = jrt::newArray<int32_t>(1);
        class_43::field_466->at(0) = var0;
        class_43::field_469 = jrt::newArray<bool>(1);
        class_43::field_469->at(0) = false;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var2 = jrt::newArray<jrt::Ref<java::lang::String>>((class_43::field_468->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_468), 0, jrt::Ref<java::lang::Object>(var2), 0, class_43::field_468->length);
        var2->at(class_43::field_468->length) = var1;
        class_43::field_468 = var2;
        jrt::Ref<jrt::Array<jrt::Ref<class_44>>> var3 = jrt::newArray<jrt::Ref<class_44>>((class_43::field_467->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_467), 0, jrt::Ref<java::lang::Object>(var3), 0, class_43::field_467->length);
        class_43::field_467 = var3;
        jrt::Ref<jrt::Array<int32_t>> var4 = jrt::newArray<int32_t>((class_43::field_466->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_466), 0, jrt::Ref<java::lang::Object>(var4), 0, class_43::field_466->length);
        var4->at(class_43::field_466->length) = var0;
        class_43::field_466 = var4;
        jrt::Ref<jrt::Array<bool>> var5 = jrt::newArray<bool>((class_43::field_469->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_469), 0, jrt::Ref<java::lang::Object>(var5), 0, class_43::field_469->length);
        var5->at(class_43::field_469->length) = false;
        class_43::field_469 = var5;
    }
}

void class_43::method_378(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3) {
    if (class_43::field_473 == nullptr) {
        class_43::field_473 = jrt::newArray<jrt::Ref<java::lang::String>>(1);
        class_43::field_473->at(0) = var1;
        class_43::field_472 = jrt::newArray<int32_t>(1);
        class_43::field_472->at(0) = var2;
        class_43::field_471 = jrt::newArray<jrt::Ref<class_108>>(1);
        class_43::field_470 = jrt::newArray<int32_t>(1);
        class_43::field_470->at(0) = var0;
        class_43::field_474 = jrt::newArray<bool>(1);
        class_43::field_474->at(0) = false;
        class_43::field_475 = jrt::newArray<int32_t>(1);
        class_43::field_475->at(0) = var3;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var4 = jrt::newArray<jrt::Ref<java::lang::String>>((class_43::field_473->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_473), 0, jrt::Ref<java::lang::Object>(var4), 0, class_43::field_473->length);
        var4->at(class_43::field_473->length) = var1;
        class_43::field_473 = var4;
        jrt::Ref<jrt::Array<int32_t>> var5 = jrt::newArray<int32_t>((class_43::field_472->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_472), 0, jrt::Ref<java::lang::Object>(var5), 0, class_43::field_472->length);
        var5->at(class_43::field_472->length) = var2;
        class_43::field_472 = var5;
        jrt::Ref<jrt::Array<jrt::Ref<class_108>>> var6 = jrt::newArray<jrt::Ref<class_108>>((class_43::field_471->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_471), 0, jrt::Ref<java::lang::Object>(var6), 0, class_43::field_471->length);
        class_43::field_471 = var6;
        jrt::Ref<jrt::Array<int32_t>> var7 = jrt::newArray<int32_t>((class_43::field_470->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_470), 0, jrt::Ref<java::lang::Object>(var7), 0, class_43::field_470->length);
        var7->at(class_43::field_470->length) = var0;
        class_43::field_470 = var7;
        jrt::Ref<jrt::Array<bool>> var8 = jrt::newArray<bool>((class_43::field_474->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_474), 0, jrt::Ref<java::lang::Object>(var8), 0, class_43::field_474->length);
        var8->at(class_43::field_474->length) = false;
        class_43::field_474 = var8;
        jrt::Ref<jrt::Array<int32_t>> var9 = jrt::newArray<int32_t>((class_43::field_475->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(class_43::field_475), 0, jrt::Ref<java::lang::Object>(var9), 0, class_43::field_475->length);
        var9->at(class_43::field_475->length) = var3;
        class_43::field_475 = var9;
    }
}

void class_43::method_379(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2) {
    class_43::method_378(var0, var1, (-1), var2);
}

jrt::Ref<class_44> class_43::method_380(int32_t var0) {
    for (int32_t var1 = 0; var1 < class_43::field_466->length; var1++) {
        if (var0 == class_43::field_466->at(var1)) {
            class_43::field_469->at(var1) = true;
            if (class_43::field_467->at(var1) == nullptr) {
                jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var2 = jrt::arrayOf<jrt::Ref<java::lang::String>>({class_43::field_468->at(var1)});
                return class_43::field_467->at(var1) = class_44::method_386(var2);
            }
            return class_43::field_467->at(var1);
        }
    }
    return jrt::Ref<class_44>(nullptr);
}

jrt::Ref<class_108> class_43::method_381(int32_t var0) {
    for (int32_t var1 = 0; var1 < class_43::field_470->length; var1++) {
        if (var0 == class_43::field_470->at(var1)) {
            class_43::field_474->at(var1) = true;
            if (class_43::field_471->at(var1) == nullptr) {
                if (class_43::field_472->at(var1) == (-1)) {
                    class_43::field_471->at(var1) = class_108::method_891(class_43::field_470->at(var1), class_43::field_473->at(var1));
                } else {
                    class_43::field_471->at(var1) = class_108::method_889(class_43::field_470->at(var1), class_43::field_473->at(var1), class_43::field_472->at(var1));
                }
                if ((class_43::field_471->at(var1) != nullptr) && (class_43::field_475->at(var1) != int32_t(-2147483647 - 1))) {
                    class_43::field_471->at(var1)->method_893(class_43::method_380(class_43::field_475->at(var1)));
                }
                return class_43::field_471->at(var1);
            }
            return jrt::cast<class_108>(class_43::field_471->at(var1)->method_840());
        }
    }
    java::lang::System::out->println(jrt::concat(JRT_LIT(u"ERROR | AEResourceManager.getGeometryResource("), var0, JRT_LIT(u") not found !")));
    return jrt::Ref<class_108>(nullptr);
}

void class_43::method_382() {
    class_43::method_383();
    class_43::method_385();
}

void class_43::method_383() {
    for (int32_t var0 = 0; var0 < class_43::field_471->length; var0++) {
        if (class_43::field_471->at(var0) != nullptr) {
            class_43::field_471->at(var0)->method_894();
            class_43::field_471->at(var0) = jrt::Ref<class_108>(nullptr);
        }
    }
}

void class_43::method_384() {
    for (int32_t var0 = 0; var0 < class_43::field_471->length; var0++) {
        if (class_43::field_471->at(var0) != nullptr) {
            class_43::field_471->at(var0)->method_870(jrt::New<class_57>());
        }
    }
}

void class_43::method_385() {
    for (int32_t var0 = 0; var0 < class_43::field_467->length; var0++) {
        if (class_43::field_467->at(var0) != nullptr) {
            class_43::field_467->at(var0)->method_387();
            class_43::field_467->at(var0) = jrt::Ref<class_44>(nullptr);
        }
    }
}

void class_43::__dumpFields(jrt::Dumper& d) {
}

