// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_6::__clinit() {
}

void class_6::__init() {
    this->field_54 = jrt::Ref<jrt::Array<jrt::Ref<class_108>>>(nullptr);
    this->field_55 = 0;
    this->deep3dKind = jrt::newArray<int32_t>(1);
}

void class_6::deep3dTag(int32_t kind) {
    if (this->deep3dKind->length < this->field_54->length) {
        jrt::Ref<jrt::Array<int32_t>> var2 = jrt::newArray<int32_t>(this->field_54->length);
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->deep3dKind), 0, jrt::Ref<java::lang::Object>(var2), 0, this->deep3dKind->length);
        this->deep3dKind = var2;
    }
    this->deep3dKind->at((this->field_55 - 1)) = kind;
}

void class_6::method_32(jrt::Ref<class_108> var1) {
    if (this->field_54 == nullptr) {
        this->field_54 = jrt::newArray<jrt::Ref<class_108>>(1);
        this->field_54->at(0) = var1;
        this->field_55 = 1;
    } else if (this->field_55 == this->field_54->length) {
        jrt::Ref<jrt::Array<jrt::Ref<class_108>>> var2 = jrt::newArray<jrt::Ref<class_108>>((this->field_54->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_54), 0, jrt::Ref<java::lang::Object>(var2), 0, this->field_54->length);
        var2->at(this->field_54->length) = var1;
        this->field_54 = var2;
        this->field_55++;
    } else {
        this->field_54->at(this->field_55) = var1;
        this->field_55++;
    }
}

void class_6::method_33() {
    this->field_55 = 0;
}

void class_6::method_34(int64_t var1) {
    for (int32_t var3 = 0; var3 < this->field_55; var3++) {
        this->field_54->at(var3)->method_895(var1);
    }
}

void class_6::method_35() {
    // Deep3D-PC: kind -1 is queued (game state) but never drawn (class_114)
    for (int32_t var1 = 0; var1 < this->field_55; var1++) {
        if (this->deep3dKind->at(var1) < 0) continue;
        org::deep3d::Remaster::object(this->deep3dKind->at(var1));
        this->field_54->at(var1)->method_887();
    }
    for (int32_t var2 = 0; var2 < this->field_55; var2++) {
        if (this->deep3dKind->at(var2) < 0) continue;
        org::deep3d::Remaster::object(this->deep3dKind->at(var2));
        this->field_54->at(var2)->method_888();
    }
    org::deep3d::Remaster::object(0);
}

void class_6::__dumpFields(jrt::Dumper& d) {
    d.f("deep3dKind", this->deep3dKind);
    d.f("field_54", this->field_54);
    d.f("field_55", this->field_55);
}

