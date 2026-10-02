// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_41::__clinit() {
}

void class_41::__init() {
    this->field_421 = jrt::newArray<bool>(class_90::field_1202->length);
    this->field_422 = jrt::newArray<bool>(42);
    this->field_427 = false;
    this->field_428 = false;
    this->field_429 = false;
    this->field_430 = false;
    this->field_431 = false;
    this->field_432 = false;
    this->field_433 = false;
    this->field_434 = false;
    this->field_435 = false;
    this->field_436 = false;
    this->field_437 = false;
    this->field_438 = false;
    this->field_439 = false;
    this->field_440 = false;
    this->field_441 = false;
    this->field_442 = false;
    this->field_443 = false;
    this->field_444 = false;
    this->field_445 = false;
    this->field_446 = false;
    this->field_447 = false;
    this->field_448 = false;
    this->field_449 = false;
    this->field_394 = jrt::newArray<bool>(200);
}

void class_41::method_367() {
    class_21::method_221();
    class_38::method_355(this->field_394);
    class_21::method_189(this->field_402);
    class_21::method_198(this->field_395);
    class_21::method_183(this->field_396);
    class_21::method_184(this->field_397);
    class_21::method_185(this->field_398);
    class_21::method_186(this->field_399);
    class_21::method_187(this->field_400);
    class_21::method_188(this->field_401);
    class_21::method_189(this->field_402);
    class_21::method_190(this->field_403);
    class_21::method_204(this->field_404);
    class_21::method_165(this->field_405);
    class_21::method_149(this->field_406);
    class_21::method_153(this->field_407);
    class_21::method_157(this->field_408);
    class_21::method_196(this->field_409);
    class_21::method_169(this->field_410);
    class_21::method_171(this->field_411);
    class_21::method_142(this->field_414);
    class_21::method_136(this->field_415);
    class_21::method_138(this->field_416);
    class_21::method_214(this->field_417);
    class_21::method_216(this->field_418);
    class_21::method_218(this->field_419);
    class_21::method_174(this->field_420);
    class_21::method_167(this->field_421);
    class_21::method_128(this->field_423);
    class_21::method_194(this->field_422);
    if ((this->field_413 == 0) && (this->field_412 == 0)) {
        this->field_413 = 22500;
        this->field_412 = this->field_413;
    }
    class_21::method_162(this->field_413);
    class_21::method_161(this->field_412);
    class_14::method_83();
    if (this->field_426 != nullptr) {
        class_14::method_82(this->field_426);
    }
    class_21::method_179(this->field_450);
    class_21::method_181(this->field_451);
    class_21::method_133(class_87::field_1145);
    class_84::field_1108 = this->field_424;
    class_84::field_1109 = this->field_425;
    class_84::field_1085 = this->field_427;
    class_84::field_1086 = this->field_428;
    class_84::field_1087 = this->field_429;
    class_84::field_1088 = this->field_430;
    class_84::field_1089 = this->field_431;
    class_84::field_1090 = this->field_432;
    class_84::field_1091 = this->field_433;
    class_84::field_1092 = this->field_434;
    class_84::field_1093 = this->field_435;
    class_84::field_1094 = this->field_436;
    class_84::field_1095 = this->field_437;
    class_84::field_1096 = this->field_438;
    class_84::field_1097 = this->field_439;
    class_84::field_1098 = this->field_440;
    class_84::field_1099 = this->field_441;
    class_84::field_1100 = this->field_442;
    class_84::field_1101 = this->field_443;
    class_84::field_1102 = this->field_444;
    class_84::field_1104 = this->field_445;
    class_84::field_1103 = this->field_446;
    class_84::field_1105 = this->field_447;
    class_84::field_1106 = this->field_448;
    class_84::field_1107 = this->field_449;
    this->field_394 = jrt::Ref<jrt::Array<bool>>(nullptr);
}

jrt::Ref<java::lang::String> class_41::toString() {
    return jrt::concat(JRT_LIT(u"Playing time: \t\t"), class_48::method_397(this->field_397), JRT_LIT(u"\nLevel: \t\t"), this->field_401, JRT_LIT(u"\nCredits: \t\t"), this->field_395, JRT_LIT(u"\n\nRating: \t\t"), this->field_396, JRT_LIT(u"\nKills: \t\t"), this->field_398, JRT_LIT(u"\nMissionCount: \t\t"), this->field_400, JRT_LIT(u"\nLastWorth: \t\t"), this->field_402, JRT_LIT(u"\nStationsVisited: \t\t"), this->field_409, JRT_LIT(u"\n"));
}

void class_41::__dumpFields(jrt::Dumper& d) {
    d.f("field_394", this->field_394);
    d.f("field_395", this->field_395);
    d.f("field_396", this->field_396);
    d.f("field_397", this->field_397);
    d.f("field_398", this->field_398);
    d.f("field_399", this->field_399);
    d.f("field_400", this->field_400);
    d.f("field_401", this->field_401);
    d.f("field_402", this->field_402);
    d.f("field_403", this->field_403);
    d.f("field_404", this->field_404);
    d.f("field_405", this->field_405);
    d.f("field_406", this->field_406);
    d.f("field_407", this->field_407);
    d.f("field_408", this->field_408);
    d.f("field_409", this->field_409);
    d.f("field_410", this->field_410);
    d.f("field_411", this->field_411);
    d.f("field_412", this->field_412);
    d.f("field_413", this->field_413);
    d.f("field_414", this->field_414);
    d.f("field_415", this->field_415);
    d.f("field_416", this->field_416);
    d.f("field_417", this->field_417);
    d.f("field_418", this->field_418);
    d.f("field_419", this->field_419);
    d.f("field_420", this->field_420);
    d.f("field_421", this->field_421);
    d.f("field_422", this->field_422);
    d.f("field_423", this->field_423);
    d.f("field_424", this->field_424);
    d.f("field_425", this->field_425);
    d.f("field_426", this->field_426);
    d.f("field_427", this->field_427);
    d.f("field_428", this->field_428);
    d.f("field_429", this->field_429);
    d.f("field_430", this->field_430);
    d.f("field_431", this->field_431);
    d.f("field_432", this->field_432);
    d.f("field_433", this->field_433);
    d.f("field_434", this->field_434);
    d.f("field_435", this->field_435);
    d.f("field_436", this->field_436);
    d.f("field_437", this->field_437);
    d.f("field_438", this->field_438);
    d.f("field_439", this->field_439);
    d.f("field_440", this->field_440);
    d.f("field_441", this->field_441);
    d.f("field_442", this->field_442);
    d.f("field_443", this->field_443);
    d.f("field_444", this->field_444);
    d.f("field_445", this->field_445);
    d.f("field_446", this->field_446);
    d.f("field_447", this->field_447);
    d.f("field_448", this->field_448);
    d.f("field_449", this->field_449);
    d.f("field_450", this->field_450);
    d.f("field_451", this->field_451);
}

