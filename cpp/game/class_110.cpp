// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Transform> class_110::field_1384{};
jrt::Ref<class_3> class_110::field_1385{};

void class_110::__clinit() {
    class_110::field_1384 = jrt::New<javax::microedition::m3g::Transform>();
    class_110::field_1385 = jrt::New<class_3>();
}

void class_110::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int8_t var9) {
    class_108::__init();
    this->class_102::field_1344 = var1;
    this->field_1386 = jrt::New<javax::microedition::m3g::Appearance>();
    if (int32_t(var9) != 0) {
        jrt::Ref<javax::microedition::m3g::CompositingMode> var10 = jrt::New<javax::microedition::m3g::CompositingMode>();
        {
            switch (int32_t(var9)) {
            case 1:
                ;
            case 3:
                var10->setBlending(64);
                break;
            case 2:
                var10->setBlending(65);
            }
        }
        var10->setDepthWriteEnable(false);
        var10->setDepthTestEnable(true);
        this->field_1386->setCompositingMode(var10);
    }
    jrt::Ref<javax::microedition::m3g::PolygonMode> var21{};
    (var21 = jrt::New<javax::microedition::m3g::PolygonMode>())->setCulling(160);
    var21->setShading(164);
    var21->setPerspectiveCorrectionEnable(false);
    this->field_1386->setPolygonMode(var21);
    this->field_1387 = var8;
    this->field_1389 = jrt::newArray<int32_t>((3 * var8));
    this->field_1390 = jrt::newArray<int32_t>(var8);
    for (int32_t var11 = 0; var11 < this->field_1390->length; var11++) {
        this->field_1390->at(var11) = -1;
    }
    jrt::Ref<javax::microedition::m3g::VertexBuffer> var22 = jrt::New<javax::microedition::m3g::VertexBuffer>();
    jrt::Ref<javax::microedition::m3g::VertexArray> var12 = jrt::New<javax::microedition::m3g::VertexArray>(4, 3, 1);
    jrt::Ref<javax::microedition::m3g::VertexArray> var13 = jrt::New<javax::microedition::m3g::VertexArray>(4, 2, 2);
    jrt::Ref<jrt::Array<int8_t>> var14 = jrt::arrayOf<int8_t>({int8_t((-1)), int8_t(1), int8_t(0), int8_t(1), int8_t(1), int8_t(0), int8_t(1), int8_t((-1)), int8_t(0), int8_t((-1)), int8_t((-1)), int8_t(0)});
    var12->set(0, 4, var14);
    jrt::Ref<jrt::Array<int16_t>> var15 = jrt::arrayOf<int16_t>({int16_t(var3), int16_t(var4), int16_t(var5), int16_t(var4), int16_t(var5), int16_t(var6), int16_t(var3), int16_t(var6)});
    var13->set(0, 4, var15);
    jrt::Ref<jrt::Array<float>> var16 = jrt::arrayOf<float>({0.0f, 0.0f, 0.0f});
    var22->setPositions(var12, 1.0f, var16);
    jrt::Ref<jrt::Array<float>> var17 = jrt::arrayOf<float>({0.0f, 0.0f});
    var22->setTexCoords(0, var13, (1.0f / float(var2)), var17);
    jrt::Ref<jrt::Array<int32_t>> var18 = jrt::arrayOf<int32_t>({0, 2, 1, 3, 2, 0});
    jrt::Ref<jrt::Array<int32_t>> var19 = jrt::arrayOf<int32_t>({3, 3});
    jrt::Ref<javax::microedition::m3g::TriangleStripArray> var20 = jrt::New<javax::microedition::m3g::TriangleStripArray>(var18, var19);
    this->field_1388 = jrt::New<javax::microedition::m3g::Mesh>(var22, jrt::Ref<javax::microedition::m3g::IndexBuffer>(var20), this->field_1386);
    this->class_105::field_1348 = var7 >> 1;
    this->field_1392 = float((var7 >> 1));
    this->field_1391 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

void class_110::__init(jrt::Ref<class_110> var1) {
    class_108::__init();
    this->field_1387 = var1->field_1387;
    this->field_1389 = jrt::newArray<int32_t>((3 * this->field_1387));
    this->field_1390 = jrt::newArray<int32_t>(this->field_1387);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1390), 0, jrt::Ref<java::lang::Object>(this->field_1390), 0, this->field_1390->length);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1389), 0, jrt::Ref<java::lang::Object>(this->field_1389), 0, this->field_1389->length);
    this->field_1388 = var1->field_1388;
    this->class_105::field_1348 = var1->field_1348;
    this->field_1392 = var1->field_1392;
    this->class_102::field_1338 = var1->field_1338;
    this->class_108::field_1367 = var1->field_1367;
    if (var1->field_1391 != nullptr) {
        this->field_1391 = jrt::newArray<int32_t>(this->field_1387);
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var1->field_1391), 0, jrt::Ref<java::lang::Object>(this->field_1391), 0, this->field_1391->length);
    }
}

jrt::Ref<class_102> class_110::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_110>(jrt::Ref<class_110>(this)));
}

void class_110::method_894() {
    this->field_1386 = jrt::Ref<javax::microedition::m3g::Appearance>(nullptr);
    this->field_1388 = jrt::Ref<javax::microedition::m3g::Mesh>(nullptr);
    this->field_1389 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_1390 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
    this->field_1391 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

void class_110::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        this->class_108::field_1368 = var1->field_1342->method_503(this->class_108::field_1368);
        this->class_108::field_1368->method_471(this->class_102::field_1342);
        var2->method_30(this->class_108::field_1367, jrt::Ref<class_108>(jrt::Ref<class_110>(this)));
    }
}

void class_110::method_887() {
    int32_t var1 = 0;
    for (int32_t var2 = 0; var2 < this->field_1387; var1 += 3) {
        class_110::field_1385->method_10(this->field_1389->at(var1), this->field_1389->at((var1 + 1)), this->field_1389->at((var1 + 2)));
        class_110::field_1385 = this->class_108::field_1368->method_506(class_110::field_1385);
        class_110::field_1384->setIdentity();
        class_110::field_1384->postTranslate(float(class_110::field_1385->field_37), float(class_110::field_1385->field_38), float(class_110::field_1385->field_39));
        if (this->field_1391 != nullptr) {
            class_110::field_1384->postScale(float((this->field_1391->at(var2) >> 1)), float((this->field_1391->at(var2) >> 1)), float((this->field_1391->at(var2) >> 1)));
        } else {
            class_110::field_1384->postScale(this->field_1392, this->field_1392, this->field_1392);
        }
        this->field_1388->getVertexBuffer()->setDefaultColor(this->field_1390->at(var2));
        class_72::field_1016->render(jrt::Ref<javax::microedition::m3g::Node>(this->field_1388), class_110::field_1384);
        var2++;
    }
}

void class_110::method_893(jrt::Ref<class_44> var1) {
    jrt::Ref<javax::microedition::m3g::Texture2D> var2{};
    (var2 = jrt::New<javax::microedition::m3g::Texture2D>((jrt::cast<class_45>(var1))->field_476->at(0)->getImage()))->setBlending(227);
    var2->setFiltering(208, 210);
    var2->setWrapping(240, 240);
    this->field_1386->setTexture(0, var2);
}

jrt::Ref<jrt::Array<int32_t>> class_110::method_897() {
    if (this->field_1391 == nullptr) {
        this->field_1391 = jrt::newArray<int32_t>(this->field_1387);
        for (int32_t var1 = 0; var1 < this->field_1391->length; var1++) {
            this->field_1391->at(var1) = jrt::f2i(this->field_1392);
        }
    }
    return this->field_1391;
}

void class_110::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1386", this->field_1386);
    d.f("field_1387", this->field_1387);
    d.f("field_1388", this->field_1388);
    d.f("field_1389", this->field_1389);
    d.f("field_1390", this->field_1390);
    d.f("field_1391", this->field_1391);
    d.f("field_1392", this->field_1392);
}

