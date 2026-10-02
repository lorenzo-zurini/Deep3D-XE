// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_4::deep3dKind{};

void class_4::__clinit() {
}

void class_4::__init(jrt::Ref<class_71> var1) {
    this->field_40 = jrt::Ref<class_106>(nullptr);
    this->field_42 = jrt::newArray<jrt::Ref<class_6>>(1);
    this->field_42->at(0) = jrt::New<class_6>();
    this->field_43 = jrt::newArray<bool>(1);
    this->field_43->at(0) = true;
    this->field_44 = var1;
}

void class_4::method_24(jrt::Ref<class_106> var1) {
    this->field_40 = var1;
    this->field_40->method_885();
    this->field_41 = jrt::Ref<class_102>(this->field_40);
    while (this->field_41->field_1336 != nullptr) {
        this->field_41 = jrt::Ref<class_102>(this->field_41->field_1336);
    }
}

void class_4::method_25(jrt::Ref<class_102> var1) {
    {
        try {
            if (((var1 != nullptr) && (this->field_42 != nullptr)) && (this->field_40 != nullptr)) {
                var1->method_839(false);
                if (this->field_41 != nullptr) {
                    this->field_41->method_839(false);
                } else {
                    this->field_40->method_839(false);
                }
                var1->method_837(this->field_40, jrt::Ref<class_4>(this));
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_4::method_26() {
    for (int32_t var1 = 0; var1 < this->field_42->length; var1++) {
        this->field_42->at(var1)->method_35();
        if (this->field_43->at(var1)) {
            this->field_44->method_685();
        }
        this->field_42->at(var1)->method_33();
    }
}

void class_4::method_27(int64_t var1) {
    for (int32_t var3 = 0; var3 < this->field_42->length; var3++) {
        this->field_42->at(var3)->method_34(var1);
        this->field_42->at(var3)->method_35();
        if (this->field_43->at(var3)) {
            this->field_44->method_685();
        }
        this->field_42->at(var3)->method_33();
    }
}

void class_4::method_28(bool var1) {
    jrt::Ref<jrt::Array<jrt::Ref<class_6>>> var2 = jrt::newArray<jrt::Ref<class_6>>((this->field_42->length + 1));
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_42), 0, jrt::Ref<java::lang::Object>(var2), 0, this->field_42->length);
    var2->at(this->field_42->length) = jrt::New<class_6>();
    this->field_42 = var2;
    jrt::Ref<jrt::Array<bool>> var3 = jrt::newArray<bool>((this->field_43->length + 1));
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_43), 0, jrt::Ref<java::lang::Object>(var3), 0, this->field_43->length);
    var3->at(this->field_43->length) = var1;
    this->field_43 = var3;
}

void class_4::method_29() {
    this->method_28(true);
}

void class_4::method_30(int32_t var1, jrt::Ref<class_108> var2) {
    this->field_42->at(var1)->method_32(var2);
    this->field_42->at(var1)->deep3dTag(class_4::deep3dKind);
}

void class_4::__dumpFields(jrt::Dumper& d) {
    d.f("field_40", this->field_40);
    d.f("field_41", this->field_41);
    d.f("field_42", this->field_42);
    d.f("field_43", this->field_43);
    d.f("field_44", this->field_44);
}

