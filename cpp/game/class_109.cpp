// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Transform> class_109::field_1369{};
jrt::Ref<jrt::Array<float>> class_109::field_1370{};
jrt::Ref<jrt::Array<float>> class_109::field_1380{};
jrt::Ref<jrt::Array<float>> class_109::field_1381{};

void class_109::__clinit() {
    class_109::field_1369 = jrt::New<javax::microedition::m3g::Transform>();
    class_109::field_1370 = jrt::newArray<float>(16);
    class_109::field_1380 = jrt::arrayOf<float>({0.0f, 0.0f, 0.0f});
    class_109::field_1381 = jrt::arrayOf<float>({0.0f, 0.0f});
}

void class_109::__init(int32_t var1, int32_t var2, int8_t var3) {
    class_108::__init();
    this->field_1383 = (-1);
    this->class_102::field_1344 = var1;
    if (this->field_1371 == nullptr) {
        this->field_1371 = jrt::New<javax::microedition::m3g::Appearance>();
        if (int32_t(var3) != 0) {
            jrt::Ref<javax::microedition::m3g::CompositingMode> var4 = jrt::New<javax::microedition::m3g::CompositingMode>();
            {
                switch (int32_t(var3)) {
                case 1:
                    ;
                case 3:
                    var4->setBlending(64);
                    break;
                case 2:
                    var4->setBlending(65);
                }
            }
            var4->setDepthWriteEnable(false);
            var4->setDepthTestEnable(true);
            this->field_1371->setCompositingMode(var4);
        }
        jrt::Ref<javax::microedition::m3g::PolygonMode> var8{};
        (var8 = jrt::New<javax::microedition::m3g::PolygonMode>())->setCulling(162);
        var8->setShading(164);
        var8->setPerspectiveCorrectionEnable(false);
        this->field_1371->setPolygonMode(var8);
    }
    this->field_1372 = var2;
    this->field_1378 = jrt::newArray<int16_t>((12 * var2));
    this->field_1379 = jrt::newArray<int8_t>((8 * var2));
    this->field_1374 = jrt::New<javax::microedition::m3g::VertexBuffer>();
    this->field_1375 = jrt::New<javax::microedition::m3g::VertexArray>((4 * var2), 3, 2);
    this->field_1376 = jrt::New<javax::microedition::m3g::VertexArray>((4 * var2), 2, 1);
    this->field_1375->set(0, (4 * var2), this->field_1378);
    this->field_1376->set(0, (4 * var2), this->field_1379);
    this->field_1374->setPositions(this->field_1375, 1.0f, class_109::field_1380);
    this->field_1374->setTexCoords(0, this->field_1376, 0.00390625f, class_109::field_1381);
    jrt::Ref<jrt::Array<int32_t>> var9 = jrt::newArray<int32_t>((6 * var2));
    int32_t var5 = 0;
    for (int32_t var6 = 0; var6 < var9->length; var5 += 4) {
        var9->at(var6) = var5;
        var9->at((var6 + 1)) = var5 + 2;
        var9->at((var6 + 2)) = var5 + 1;
        var9->at((var6 + 3)) = var5 + 3;
        var9->at((var6 + 4)) = var5 + 2;
        var9->at((var6 + 5)) = var5;
        var6 += 6;
    }
    jrt::Ref<jrt::Array<int32_t>> var10 = jrt::newArray<int32_t>((2 * var2));
    for (int32_t var7 = 0; var7 < var10->length; var7++) {
        var10->at(var7) = 3;
    }
    this->field_1377 = jrt::New<javax::microedition::m3g::TriangleStripArray>(var9, var10);
    this->field_1373 = jrt::New<javax::microedition::m3g::Mesh>(this->field_1374, jrt::Ref<javax::microedition::m3g::IndexBuffer>(this->field_1377), this->field_1371);
}

void class_109::__init(jrt::Ref<class_109> var1) {
    class_108::__init();
    this->field_1383 = (-1);
    this->field_1372 = var1->field_1372;
    this->field_1373 = var1->field_1373;
    this->field_1374 = var1->field_1374;
    this->field_1375 = var1->field_1375;
    this->field_1376 = var1->field_1376;
    this->field_1377 = var1->field_1377;
    this->field_1378 = var1->field_1378;
    this->field_1379 = var1->field_1379;
    this->field_1382 = var1->field_1382;
    this->class_105::field_1348 = var1->field_1348;
    this->class_102::field_1338 = var1->field_1338;
    this->class_108::field_1367 = var1->field_1367;
}

jrt::Ref<class_102> class_109::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_109>(jrt::Ref<class_109>(this)));
}

void class_109::method_894() {
    this->field_1373 = jrt::Ref<javax::microedition::m3g::Mesh>(nullptr);
    this->field_1374 = jrt::Ref<javax::microedition::m3g::VertexBuffer>(nullptr);
    this->field_1375 = jrt::Ref<javax::microedition::m3g::VertexArray>(nullptr);
    this->field_1376 = jrt::Ref<javax::microedition::m3g::VertexArray>(nullptr);
    this->field_1377 = jrt::Ref<javax::microedition::m3g::TriangleStripArray>(nullptr);
    this->field_1378 = jrt::Ref<jrt::Array<int16_t>>(nullptr);
    this->field_1379 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
}

void class_109::method_887() {
    this->class_108::field_1368->method_505(class_109::field_1370);
    class_109::field_1369->set(class_109::field_1370);
    class_72::field_1016->render(jrt::Ref<javax::microedition::m3g::Node>(this->field_1373), class_109::field_1369);
}

void class_109::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        this->class_108::field_1368 = var1->field_1342->method_503(this->class_108::field_1368);
        this->class_108::field_1368->method_471(this->class_102::field_1342);
        var2->method_30(this->class_108::field_1367, jrt::Ref<class_108>(jrt::Ref<class_109>(this)));
    }
}

void class_109::method_896(jrt::Ref<jrt::Array<int32_t>> var1, jrt::Ref<jrt::Array<int32_t>> var2) {
    for (int32_t var3 = 0; var3 < var1->length; var3++) {
        this->field_1378->at(var3) = int16_t(var1->at(var3));
    }
    this->field_1375->set(0, (4 * this->field_1372), this->field_1378);
    this->field_1373->getVertexBuffer()->setPositions(this->field_1375, 1.0f, class_109::field_1380);
    for (int32_t var5 = 0; var5 < var2->length; var5++) {
        this->field_1379->at(var5) = int8_t(var2->at(var5));
    }
    this->field_1376->set(0, (4 * this->field_1372), this->field_1379);
    this->field_1373->getVertexBuffer()->setTexCoords(0, this->field_1376, (1.0f / float(this->field_1382)), class_109::field_1381);
    this->field_1373->getVertexBuffer()->setDefaultColor(this->field_1383);
    this->class_105::field_1348 = 0;
    for (int32_t var6 = 0; var6 < var1->length; var6 += 3) {
        int32_t var4 = ((var1->at(var6) * var1->at(var6)) + (var1->at((var6 + 1)) * var1->at((var6 + 1)))) + (var1->at((var6 + 2)) * var1->at((var6 + 2)));
        if (this->class_105::field_1348 < var4) {
            this->class_105::field_1348 = var4;
        }
    }
    this->class_105::field_1348 = class_16::method_96(int64_t(this->class_105::field_1348));
}

void class_109::method_893(jrt::Ref<class_44> var1) {
    jrt::Ref<javax::microedition::m3g::Texture2D> var2{};
    (var2 = jrt::New<javax::microedition::m3g::Texture2D>((jrt::cast<class_45>(var1))->field_476->at(0)->getImage()))->setBlending(227);
    var2->setFiltering(208, 210);
    var2->setWrapping(240, 240);
    this->field_1371->setTexture(0, var2);
    this->field_1382 = var2->getImage()->getWidth();
}

void class_109::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1371", this->field_1371);
    d.f("field_1372", this->field_1372);
    d.f("field_1373", this->field_1373);
    d.f("field_1374", this->field_1374);
    d.f("field_1375", this->field_1375);
    d.f("field_1376", this->field_1376);
    d.f("field_1377", this->field_1377);
    d.f("field_1378", this->field_1378);
    d.f("field_1379", this->field_1379);
    d.f("field_1382", this->field_1382);
    d.f("field_1383", this->field_1383);
}

