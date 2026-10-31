// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_102::__clinit() {
}

void class_102::__init() {
    this->field_1335 = 32;
    this->field_1336 = jrt::Ref<class_103>(nullptr);
    this->field_1338 = true;
    this->field_1341 = jrt::New<class_57>();
    this->field_1342 = jrt::New<class_57>();
    this->field_1343 = jrt::New<class_15>();
    this->field_1339 = true;
    this->field_1340 = true;
    this->field_1344 = 0;
}

void class_102::__init(jrt::Ref<class_102> var1) {
    this->field_1335 = 32;
    this->field_1336 = jrt::Ref<class_103>(nullptr);
    this->field_1338 = var1->field_1338;
    this->field_1341 = jrt::New<class_57>(var1->field_1341);
    this->field_1342 = jrt::New<class_57>(var1->field_1342);
    this->field_1343 = jrt::New<class_15>(var1->field_1343);
    this->field_1339 = true;
    this->field_1340 = true;
    this->field_1344 = var1->field_1344;
}

void class_102::method_841() {
    this->field_1340 = true;
    if (this->field_1336 != nullptr) {
        this->field_1336->method_841();
    }
}

jrt::Ref<java::lang::String> class_102::toString() {
    return this->method_842(jrt::concat(JRT_LIT(u""), this->field_1344), 0);
}

void class_102::method_843(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_474(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_844(jrt::Ref<class_3> var1) {
    this->field_1341->method_475(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_845(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_476(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_846(jrt::Ref<class_3> var1) {
    this->field_1341->method_477(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_847(int32_t var1) {
    this->field_1341->method_478(var1);
    this->field_1339 = true;
    this->method_841();
}

jrt::Ref<class_3> class_102::method_848(jrt::Ref<class_3> var1) {
    return this->field_1341->method_479(var1);
}

jrt::Ref<class_3> class_102::method_849(jrt::Ref<class_3> var1) {
    return this->field_1342->method_479(var1);
}

jrt::Ref<class_3> class_102::method_850() {
    return this->field_1341->method_480();
}

jrt::Ref<class_3> class_102::method_851() {
    return this->field_1342->method_480();
}

int32_t class_102::method_852() {
    return this->field_1341->field_698;
}

int32_t class_102::method_853() {
    return this->field_1341->field_699;
}

int32_t class_102::method_854() {
    return this->field_1341->field_700;
}

jrt::Ref<class_3> class_102::method_855(jrt::Ref<class_3> var1) {
    return this->field_1341->method_481(var1);
}

jrt::Ref<class_3> class_102::method_856(jrt::Ref<class_3> var1) {
    return this->field_1341->method_482(var1);
}

jrt::Ref<class_3> class_102::method_857() {
    return this->field_1341->method_483();
}

jrt::Ref<class_3> class_102::method_858(jrt::Ref<class_3> var1) {
    return this->field_1341->method_484(var1);
}

void class_102::method_859(int16_t var1) {
    this->field_1341->method_485(var1);
    this->field_1342->method_485(var1);
}

void class_102::method_860(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_486(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

/* Deep3D-PC: see class_57 */
void class_102::deep3dTurn(int32_t axis, double units) {
    this->field_1341->deep3dTurn(axis, units);
    this->field_1339 = true;
    this->method_841();
}

void class_102::deep3dGo(double units) {
    this->field_1341->deep3dGo(units);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_861(int32_t var1) {
    this->field_1341->method_487(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_862(int32_t var1) {
    this->field_1341->method_489(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_863(int32_t var1) {
    this->field_1341->method_488(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_864(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_491(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

jrt::Ref<class_123> class_102::method_865() {
    return this->field_1341->method_499();
}

int32_t class_102::method_866() {
    return this->field_1341->method_492();
}

void class_102::method_867(jrt::Ref<class_123> var1) {
    this->field_1341->method_495(var1);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_868(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_500(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_869(int32_t var1, int32_t var2, int32_t var3) {
    this->field_1341->method_501(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_870(jrt::Ref<class_57> var1) {
    this->field_1341->method_470(var1);
    this->field_1339 = true;
    this->method_841();
}

jrt::Ref<class_57> class_102::method_871(jrt::Ref<class_57> var1) {
    return this->field_1341->method_503(var1);
}

void class_102::method_872(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2, jrt::Ref<class_3> var3) {
    this->field_1341->method_504(var1, var2, var3);
    this->field_1339 = true;
    this->method_841();
}

void class_102::method_873(int32_t var1) {
}

void class_102::method_874(int32_t var1) {
}

int32_t class_102::method_875() {
    return 0;
}

void class_102::method_876(int32_t var1, int32_t var2) {
}

void class_102::method_877(int8_t var1) {
}

void class_102::method_878() {
}

void class_102::__dumpFields(jrt::Dumper& d) {
    d.f("field_1335", this->field_1335);
    d.f("field_1336", this->field_1336);
    d.f("field_1337", this->field_1337);
    d.f("field_1338", this->field_1338);
    d.f("field_1339", this->field_1339);
    d.f("field_1340", this->field_1340);
    d.f("field_1341", this->field_1341);
    d.f("field_1342", this->field_1342);
    d.f("field_1343", this->field_1343);
    d.f("field_1344", this->field_1344);
}

