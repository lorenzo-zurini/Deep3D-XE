// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_34::__clinit() {
}

void class_34::__init() {
}

void class_34::method_297() {
    this->field_342 = jrt::Ref<jrt::Array<jrt::Ref<class_20>>>(nullptr);
    this->field_343 = jrt::Ref<class_20>(nullptr);
}

void class_34::method_298(jrt::Ref<jrt::Array<jrt::Ref<class_20>>> var1) {
    this->field_342 = var1;
    if (var1 != nullptr) {
        for (int32_t var2 = 0; var2 < var1->length; var2++) {
            var1->at(var2)->field_177 = jrt::Ref<class_34>(this);
        }
    }
}

jrt::Ref<class_20> class_34::method_299(int32_t var1) {
    return this->field_342->at(var1);
}

void class_34::method_300(int64_t var1, jrt::Ref<class_70> var3) {
    if (this->field_342 != nullptr) {
        for (int32_t var4 = 0; var4 < this->field_342->length; var4++) {
            if (this->field_342->at(var4)->method_126(var1, var3)) {
                this->field_345 = class_90::field_1218->at(this->field_342->at(var4)->field_179);
                if (this->field_345 == nullptr) {
                    this->field_345 = class_21::method_215();
                }
                class_119::method_921(this->field_345);
                this->field_344 = class_58::method_532(class_21::method_219(class_84::field_1116->method_4(this->field_342->at(var4)->field_178), class_21::method_213()), ((class_84::field_1120 - class_119::field_1458) - 10));
                this->field_346 = var1;
                this->field_347 = (this->field_344->length * 2000) + 1500;
                class_84::field_1122->method_770(10);
                return;
            }
        }
    }
}

void class_34::method_301(int64_t var1, jrt::Ref<class_70> var3) {
    if (this->field_343 == nullptr) {
        this->method_300(var1, var3);
    } else {
        if (var1 > (this->field_346 + int64_t(2000))) {
            {
                try {
                    int32_t var4 = this->field_343->field_179;
                    this->field_348 = class_90::field_1219->at(var4);
                    if (this->field_348 == JRT_LIT(u"Colonist")) {
                        this->field_348 = class_84::field_1116->method_4(238);
                    } else if (this->field_348 == JRT_LIT(u"Rebel")) {
                        this->field_348 = class_84::field_1116->method_4(239);
                    } else if (this->field_348 == JRT_LIT(u"Pirate")) {
                        this->field_348 = class_84::field_1116->method_4(240);
                    }
                    class_67::method_592(((var4 == 0) ? class_21::method_213() : this->field_348), 0, 0, (class_84::field_1120 - 1), class_16::method_97((class_119::field_1459 + 16), ((this->field_344->length + 2) * class_58::method_527())), true);
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex1.t);
                        var5->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
            if ((this->field_345 == nullptr) && (class_21::method_217() != nullptr)) {
                class_84::field_1117->drawImage(class_21::method_217(), 3, 13, 0);
            } else {
                class_119::method_923(this->field_345, 3, 13, 0);
            }
            class_58::method_521(this->field_344, (class_119::field_1458 + 8), 13, 0);
            if (var1 > ((this->field_346 + int64_t(2000)) + int64_t(this->field_347))) {
                this->field_346 = int64_t(0);
                this->field_343->method_125();
                this->field_343 = jrt::Ref<class_20>(nullptr);
            }
        }
    }
}

void class_34::__dumpFields(jrt::Dumper& d) {
    d.f("field_342", this->field_342);
    d.f("field_343", this->field_343);
    d.f("field_344", this->field_344);
    d.f("field_345", this->field_345);
    d.f("field_346", this->field_346);
    d.f("field_347", this->field_347);
    d.f("field_348", this->field_348);
}

