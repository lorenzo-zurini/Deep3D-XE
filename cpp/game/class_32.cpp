// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<char16_t>>>> class_32::field_320{};

void class_32::__clinit() {
    class_32::field_320 = jrt::arrayOf<jrt::Ref<jrt::Array<char16_t>>>({jrt::arrayOf<char16_t>({u'A', u'B', u'C'}), jrt::arrayOf<char16_t>({u'D', u'E', u'F'}), jrt::arrayOf<char16_t>({u'G', u'H', u'I'}), jrt::arrayOf<char16_t>({u'J', u'K', u'L'}), jrt::arrayOf<char16_t>({u'M', u'N', u'O'}), jrt::arrayOf<char16_t>({u'P', u'Q', u'R', u'S'}), jrt::arrayOf<char16_t>({u'T', u'U', u'V'}), jrt::arrayOf<char16_t>({u'W', u'X', u'Y', u'Z'}), jrt::arrayOf<char16_t>({u' '})});
}

void class_32::__init(int32_t var1) {
    this->field_322 = 0;
    this->field_326 = u' ';
    this->field_327 = JRT_LIT(u"");
    this->field_321 = var1;
}

int32_t class_32::method_289(int32_t var1) {
    {
        switch (var1) {
        case 2:
            return 0;
        case 4:
            return 2;
        case 32:
            return 4;
        case 64:
            return 6;
        case 256:
            return 3;
        case 512:
            return 5;
        case 1024:
            return 7;
        case 65536:
            return 1;
        default:
            return 8;
        }
    }
}

void class_32::typeFromKeyboard() {
    org::deep3d::GameUi::textEntryTick();
    jrt::Ref<java::lang::String> typed = org::deep3d::GameUi::pollTypedText();
    for (int32_t i = 0; i < typed->length(); i++) {
        char16_t c = typed->charAt(i);
        if (int32_t(c) == int32_t(char16_t(8))) {
            if (this->field_327->length() > 0) {
                this->field_327 = this->field_327->substring(0, (this->field_327->length() - 1));
            }
        } else if ((this->field_327->length() < this->field_321) && (java::lang::Character::isLetterOrDigit(c) || (int32_t(c) == int32_t(u' ')))) {
            this->field_327 = jrt::concat(this->field_327, c);
        } else {
            continue;
        }
        this->field_326 = u' ';
        this->field_323 = 0;
    }
}

int32_t class_32::method_290(int32_t var1) {
    this->typeFromKeyboard();
    this->field_325 += var1;
    if (this->field_328 == 16384) {
        return 0;
    } else if (this->field_327->length() >= this->field_321) {
        return 2;
    } else if (((((this->field_325 > 1000) || (int32_t(this->field_326) == int32_t(u' '))) && (this->field_328 != 0)) && (this->field_328 != 524288)) && (this->field_328 != 8192)) {
        this->field_325 = 0;
        this->field_322 = 0;
        this->field_327 = jrt::concat(this->field_327, this->field_326);
        this->field_326 = u' ';
        this->field_328 = 0;
        this->field_323 = 0;
        return 0;
    } else {
        return 2;
    }
}

void class_32::method_291(int32_t var1) {
    this->field_328 = var1;
    this->field_325 = 0;
    if ((var1 != 524288) && (var1 != 8192)) {
        if (((var1 != this->field_322) && (int32_t(this->field_326) != int32_t(u' '))) && (this->field_327->length() < this->field_321)) {
            this->field_327 = jrt::concat(this->field_327, this->field_326);
            this->field_323 = 0;
        }
        this->field_324 = this->method_289(var1);
        if (this->field_323 >= class_32::field_320->at(this->field_324)->length) {
            this->field_323 = 0;
        }
        this->field_326 = class_32::field_320->at(this->field_324)->at((this->field_323++));
        if ((this->field_327->length() > 0) && (int32_t(this->field_327->charAt((this->field_327->length() - 1))) != int32_t(u' '))) {
            this->field_326 = java::lang::String::valueOf(this->field_326)->toLowerCase()->charAt(0);
        }
        this->field_322 = var1;
    } else if (this->field_327->length() > 0) {
        this->field_325 = 0;
        this->field_326 = u' ';
        this->field_323 = 0;
        this->field_327 = this->field_327->substring(0, (this->field_327->length() - 1));
        return;
    }
}

void class_32::__dumpFields(jrt::Dumper& d) {
    d.f("field_321", this->field_321);
    d.f("field_322", this->field_322);
    d.f("field_323", this->field_323);
    d.f("field_324", this->field_324);
    d.f("field_325", this->field_325);
    d.f("field_326", this->field_326);
    d.f("field_327", this->field_327);
    d.f("field_328", this->field_328);
}

