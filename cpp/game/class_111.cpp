// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Transform> class_111::field_1400{};
jrt::Ref<jrt::Array<float>> class_111::field_1401{};
jrt::Ref<javax::microedition::m3g::PolygonMode> class_111::field_1404{};
jrt::Ref<javax::microedition::m3g::PolygonMode> class_111::field_1405{};
jrt::Ref<javax::microedition::m3g::CompositingMode> class_111::field_1406{};

void class_111::__clinit() {
    class_111::field_1400 = jrt::New<javax::microedition::m3g::Transform>();
    class_111::field_1401 = jrt::newArray<float>(16);
}

void class_111::__init(int32_t var1, jrt::Ref<java::lang::String> var2, int32_t var3) {
    class_108::__init();
    this->field_1407 = false;
    this->field_1408 = jrt::Ref<javax::microedition::m3g::Texture2D>(nullptr);
    this->class_102::field_1344 = var1;
    this->method_898();
    this->method_899(var2);
    this->class_105::field_1348 = var3;
}

void class_111::__init(jrt::Ref<class_111> var1) {
    class_108::__init();
    this->field_1407 = false;
    this->field_1408 = jrt::Ref<javax::microedition::m3g::Texture2D>(nullptr);
    this->method_898();
    this->class_105::field_1348 = var1->field_1348;
    this->field_1402 = var1->field_1402;
    this->field_1403 = var1->field_1403;
    this->class_108::field_1367 = var1->field_1367;
    this->class_102::field_1338 = var1->field_1338;
    this->field_1393 = var1->field_1393;
    this->field_1394 = var1->field_1394;
    this->field_1395 = var1->field_1395;
    this->field_1396 = var1->field_1396;
    this->field_1397 = var1->field_1397;
    this->field_1398 = var1->field_1398;
    this->field_1399 = var1->field_1399;
    this->class_102::field_1344 = var1->field_1344;
}

void class_111::method_898() {
    if (class_111::field_1404 == nullptr) {
        class_111::field_1404 = jrt::New<javax::microedition::m3g::PolygonMode>();
        class_111::field_1404->setCulling(160);
        class_111::field_1404->setShading(165);
    }
    if (class_111::field_1405 == nullptr) {
        class_111::field_1405 = jrt::New<javax::microedition::m3g::PolygonMode>();
        class_111::field_1405->setCulling(162);
        class_111::field_1405->setShading(164);
    }
    if (class_111::field_1406 == nullptr) {
        class_111::field_1406 = jrt::New<javax::microedition::m3g::CompositingMode>();
        class_111::field_1406->setBlending(64);
        class_111::field_1406->setDepthTestEnable(true);
        class_111::field_1406->setDepthWriteEnable(false);
    }
}

void class_111::method_899(jrt::Ref<java::lang::String> var1) {
    {
        try {
            jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> var3 = javax::microedition::m3g::Loader::load(class_28::method_283(jrt::concat(var1, JRT_LIT(u".m3g"))), 0);
            for (int32_t var4 = 0; var4 < var3->length; var4++) {
                if (!(jrt::isInstance<javax::microedition::m3g::World>(var3->at(var4)))) {
                    if (jrt::isInstance<javax::microedition::m3g::Group>(var3->at(var4))) {
                        int32_t var12{};
                        if ((var12 = this->method_902(jrt::Ref<javax::microedition::m3g::Node>(jrt::cast<javax::microedition::m3g::Group>(var3->at(var4))), 0)) == 0) {
                            for (int32_t var13 = 0; var13 < (jrt::cast<javax::microedition::m3g::Group>(var3->at(var4)))->getChildCount(); var13++) {
                                jrt::Ref<javax::microedition::m3g::Node> var15{};
                                if (jrt::isInstance<javax::microedition::m3g::Mesh>((var15 = (jrt::cast<javax::microedition::m3g::Group>(var3->at(var4)))->getChild(var13)))) {
                                    jrt::Ref<javax::microedition::m3g::Transform> var16 = jrt::New<javax::microedition::m3g::Transform>();
                                    var15->getTransform(var16);
                                    (jrt::cast<javax::microedition::m3g::Group>(var3->at(var4)))->removeChild(var15);
                                    var15->setTransform(var16);
                                    this->method_900(var15);
                                }
                            }
                        } else {
                            this->method_900(jrt::Ref<javax::microedition::m3g::Node>(jrt::cast<javax::microedition::m3g::Group>(var3->at(var4))));
                            this->field_1393 = (this->field_1393 < var12) ? var12 : this->field_1393;
                        }
                    }
                } else {
                    for (int32_t var5 = 0; var5 < (jrt::cast<javax::microedition::m3g::World>(var3->at(var4)))->getChildCount(); var5++) {
                        jrt::Ref<javax::microedition::m3g::Node> var6 = (jrt::cast<javax::microedition::m3g::World>(var3->at(var4)))->getChild(var5);
                        int32_t var7 = 0;
                        var7 = this->method_902(var6, 0);
                        if (jrt::isInstance<javax::microedition::m3g::Group>(var6)) {
                            if (var7 == 0) {
                                for (int32_t var8 = 0; var8 < (jrt::cast<javax::microedition::m3g::Group>(var6))->getChildCount(); var8++) {
                                    jrt::Ref<javax::microedition::m3g::Node> var9{};
                                    if (jrt::isInstance<javax::microedition::m3g::Mesh>((var9 = (jrt::cast<javax::microedition::m3g::Group>(var6))->getChild(var8)))) {
                                        jrt::Ref<javax::microedition::m3g::Transform> var10 = jrt::New<javax::microedition::m3g::Transform>();
                                        var9->getTransform(var10);
                                        (jrt::cast<javax::microedition::m3g::Group>(var6))->removeChild(var9);
                                        var9->setTransform(var10);
                                        this->method_900(var9);
                                    }
                                }
                            } else {
                                this->method_900(var6);
                                this->field_1393 = (this->field_1393 < var7) ? var7 : this->field_1393;
                            }
                        } else if (jrt::isInstance<javax::microedition::m3g::Mesh>(var6)) {
                            this->method_900(var6);
                            this->field_1393 = (this->field_1393 < var7) ? var7 : this->field_1393;
                        }
                    }
                }
            }
            if (this->field_1393 != 0) {
                this->field_1394 = 0;
                this->field_1395 = this->field_1393;
                this->field_1396 = 0;
                this->field_1397 = int64_t(-1);
                this->field_1398 = true;
                this->field_1399 = int8_t(2);
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var11 = jrt::cast<java::lang::Exception>(__ex1.t);
                this->field_1402 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>>(nullptr);
                this->field_1403 = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>>(nullptr);
            } else {
                throw;
            }
        }
    }
}

void class_111::method_900(jrt::Ref<javax::microedition::m3g::Node> var1) {
    if (this->method_901(var1)) {
        if (this->field_1403 == nullptr) {
            this->field_1403 = jrt::newArray<jrt::Ref<javax::microedition::m3g::Node>>(1);
            this->field_1403->at(0) = var1;
        } else {
            jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>> var3 = jrt::newArray<jrt::Ref<javax::microedition::m3g::Node>>((this->field_1403->length + 1));
            java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1403), 0, jrt::Ref<java::lang::Object>(var3), 0, this->field_1403->length);
            var3->at(this->field_1403->length) = var1;
            this->field_1403 = var3;
        }
    } else if (this->field_1402 == nullptr) {
        this->field_1402 = jrt::newArray<jrt::Ref<javax::microedition::m3g::Node>>(1);
        this->field_1402->at(0) = var1;
    } else {
        jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>> var2 = jrt::newArray<jrt::Ref<javax::microedition::m3g::Node>>((this->field_1402->length + 1));
        java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->field_1402), 0, jrt::Ref<java::lang::Object>(var2), 0, this->field_1402->length);
        var2->at(this->field_1402->length) = var1;
        this->field_1402 = var2;
    }
}

bool class_111::method_901(jrt::Ref<javax::microedition::m3g::Node> var1) {
    if (jrt::isInstance<javax::microedition::m3g::Group>(var1)) {
        for (int32_t var2 = 0; var2 < (jrt::cast<javax::microedition::m3g::Group>(var1))->getChildCount(); var2++) {
            jrt::Ref<javax::microedition::m3g::Node> var3{};
            if (jrt::isInstance<javax::microedition::m3g::Mesh>((var3 = (jrt::cast<javax::microedition::m3g::Group>(var1))->getChild(var2)))) {
                for (int32_t var4 = 0; var4 < (jrt::cast<javax::microedition::m3g::Mesh>(var3))->getSubmeshCount(); var4++) {
                    jrt::Ref<javax::microedition::m3g::Material> var6{};
                    if (((var6 = (jrt::cast<javax::microedition::m3g::Mesh>(var3))->getAppearance(var4)->getMaterial()) != nullptr) && (var6->getColor(8192) == 65280)) {
                        return true;
                    }
                }
            }
        }
    } else if (jrt::isInstance<javax::microedition::m3g::Mesh>(var1)) {
        for (int32_t var7 = 0; var7 < (jrt::cast<javax::microedition::m3g::Mesh>(var1))->getSubmeshCount(); var7++) {
            jrt::Ref<javax::microedition::m3g::Material> var8{};
            if (((var8 = (jrt::cast<javax::microedition::m3g::Mesh>(var1))->getAppearance(var7)->getMaterial()) != nullptr) && (var8->getColor(8192) == 65280)) {
                return true;
            }
        }
    }
    return false;
}

int32_t class_111::method_902(jrt::Ref<javax::microedition::m3g::Node> var1, int32_t var2) {
    for (int32_t var3 = 0; var3 < var1->getAnimationTrackCount(); var3++) {
        jrt::Ref<javax::microedition::m3g::KeyframeSequence> var4{};
        if ((var4 = var1->getAnimationTrack(var3)->getKeyframeSequence())->getDuration() > var2) {
            var2 = var4->getDuration();
        }
    }
    if (jrt::isInstance<javax::microedition::m3g::Group>(var1)) {
        for (int32_t var7 = 0; var7 < (jrt::cast<javax::microedition::m3g::Group>(var1))->getChildCount(); var7++) {
            jrt::Ref<javax::microedition::m3g::Node> var8 = (jrt::cast<javax::microedition::m3g::Group>(var1))->getChild(var7);
            for (int32_t var5 = 0; var5 < var8->getAnimationTrackCount(); var5++) {
                jrt::Ref<javax::microedition::m3g::KeyframeSequence> var6{};
                if ((var6 = var8->getAnimationTrack(var5)->getKeyframeSequence())->getDuration() > var2) {
                    var2 = var6->getDuration();
                }
            }
            if (jrt::isInstance<javax::microedition::m3g::Group>(var8)) {
                var2 = this->method_902(jrt::Ref<javax::microedition::m3g::Node>(jrt::cast<javax::microedition::m3g::Group>(var8)), var2);
            }
        }
    }
    return var2;
}

void class_111::method_887() {
    if (this->field_1402 != nullptr) {
        this->class_108::field_1368->method_505(class_111::field_1401);
        class_111::field_1400->set(class_111::field_1401);
        if (this->field_1393 > 0) {
            for (int32_t var2 = 0; var2 < this->field_1402->length; var2++) {
                if (int32_t(this->field_1399) == 3) {
                    this->field_1402->at(var2)->animate((this->field_1395 - this->field_1396));
                } else {
                    this->field_1402->at(var2)->animate(this->field_1396);
                }
                class_72::field_1016->render(this->field_1402->at(var2), class_111::field_1400);
            }
            return;
        }
        for (int32_t var1 = 0; var1 < this->field_1402->length; var1++) {
            class_72::field_1016->render(this->field_1402->at(var1), class_111::field_1400);
        }
    }
}

void class_111::method_888() {
    if (this->field_1403 != nullptr) {
        this->class_108::field_1368->method_505(class_111::field_1401);
        class_111::field_1400->set(class_111::field_1401);
        if (this->field_1393 > 0) {
            for (int32_t var2 = 0; var2 < this->field_1403->length; var2++) {
                if (int32_t(this->field_1399) == 3) {
                    this->field_1403->at(var2)->animate((this->field_1395 - this->field_1396));
                } else {
                    this->field_1403->at(var2)->animate(this->field_1396);
                }
                class_72::field_1016->render(this->field_1403->at(var2), class_111::field_1400);
            }
            return;
        }
        for (int32_t var1 = 0; var1 < this->field_1403->length; var1++) {
            class_72::field_1016->render(this->field_1403->at(var1), class_111::field_1400);
        }
    }
}

void class_111::method_895(int64_t var1) {
    if (this->field_1398) {
        if (this->field_1397 == int64_t(-1)) {
            this->field_1397 = var1;
        }
        this->field_1396 = this->field_1394 + int32_t(jrt::div((var1 - this->field_1397), int64_t(this->class_102::field_1335)));
        if (this->field_1396 > this->field_1395) {
            if (int32_t(this->field_1399) == 2) {
                this->field_1396 = this->field_1394;
                this->field_1397 = var1 - int64_t(((this->field_1396 - this->field_1394) * this->class_102::field_1335));
                return;
            }
            this->field_1398 = false;
            this->field_1396 = this->field_1395;
            this->field_1397 = int64_t(-1);
        }
    }
}

int32_t class_111::method_875() {
    return this->field_1396;
}

void class_111::method_874(int32_t var1) {
    this->field_1396 = var1;
}

void class_111::method_873(int32_t var1) {
    this->class_102::field_1335 = (var1 > 0) ? var1 : 1;
}

void class_111::method_876(int32_t var1, int32_t var2) {
    this->field_1394 = ((var1 >= 0) && (var1 <= this->field_1393)) ? var1 : 0;
    this->field_1395 = ((var2 >= 0) && (var2 <= this->field_1393)) ? var2 : this->field_1393;
    this->field_1396 = (this->field_1396 < var1) ? var1 : ((this->field_1396 > var2) ? var2 : this->field_1396);
    this->field_1397 = int64_t(-1);
    if (this->field_1407) {
        if (((((var1 == 1) && (var2 == 1)) || ((var1 == 3) && (var2 == 5))) || ((var1 == 2) && (var2 == 3))) || ((((((this->class_102::field_1344 == 3305) || (this->class_102::field_1344 == 3306)) || (this->class_102::field_1344 == 3309)) || (this->class_102::field_1344 == 3310)) && (var1 == 2)) && (var2 == 2))) {
            this->field_1408->setTranslation(0.0f, 0.125f, 0.0f);
            return;
        }
        if (((var1 == 2) && (var2 == 2)) || ((var1 == 6) && (var2 == 8))) {
            this->field_1408->setTranslation(0.0f, 0.25f, 0.0f);
        }
    }
}

void class_111::method_877(int8_t var1) {
    if ((((!this->field_1407) || (this->class_102::field_1344 == 3300)) || (this->class_102::field_1344 == 3311)) || (this->class_102::field_1344 == 3308)) {
        this->field_1399 = var1;
        this->field_1397 = int64_t(-1);
        this->field_1398 = this->field_1393 > 0;
    }
}

void class_111::method_878() {
    this->field_1398 = false;
}

jrt::Ref<class_102> class_111::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_111>(jrt::Ref<class_111>(this)));
}

void class_111::method_893(jrt::Ref<class_44> var1) {
    if (this->field_1402 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_1402->length; var2++) {
            this->method_903(this->field_1402->at(var2), (jrt::cast<class_45>(var1))->field_476, false);
        }
    }
    if (this->field_1403 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_1403->length; var3++) {
            this->method_903(this->field_1403->at(var3), (jrt::cast<class_45>(var1))->field_476, true);
        }
    }
}

void class_111::method_903(jrt::Ref<javax::microedition::m3g::Node> var1, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> var2, bool var3) {
    if (jrt::isInstance<javax::microedition::m3g::Mesh>(var1)) {
        int32_t var8 = (jrt::cast<javax::microedition::m3g::Mesh>(var1))->getUserID();
        for (int32_t var9 = 0; var9 < (jrt::cast<javax::microedition::m3g::Mesh>(var1))->getSubmeshCount(); var9++) {
            jrt::Ref<javax::microedition::m3g::Appearance> var6 = (jrt::cast<javax::microedition::m3g::Mesh>(var1))->getAppearance(var9);
            if (var3) {
                var6->setCompositingMode(class_111::field_1406);
                var6->setPolygonMode(class_111::field_1405);
            } else {
                var6->setCompositingMode(jrt::Ref<javax::microedition::m3g::CompositingMode>(nullptr));
                var6->setPolygonMode(class_111::field_1404);
            }
            bool var7 = false;
            if (var6->getMaterial() != nullptr) {
                var7 = var6->getMaterial()->getColor(8192) == 16711680;
            }
            var6->setMaterial(jrt::Ref<javax::microedition::m3g::Material>(nullptr));
            if ((var6->getTexture(0) != nullptr) && (var2 != nullptr)) {
                if (var8 < var2->length) {
                    if (var7) {
                        this->field_1408 = jrt::cast<javax::microedition::m3g::Texture2D>(var2->at(var8)->duplicate());
                        var6->setTexture(0, this->field_1408);
                    } else {
                        var6->setTexture(0, var2->at(var8));
                    }
                } else if (var7) {
                    this->field_1408 = jrt::cast<javax::microedition::m3g::Texture2D>(var2->at(0)->duplicate());
                    var6->setTexture(0, this->field_1408);
                } else {
                    var6->setTexture(0, var2->at(0));
                }
            }
            (jrt::cast<javax::microedition::m3g::Mesh>(var1))->setAppearance(var9, var6);
            if (var7) {
                this->field_1407 = true;
            }
        }
    } else {
        if (jrt::isInstance<javax::microedition::m3g::Group>(var1)) {
            for (int32_t var4 = 0; var4 < (jrt::cast<javax::microedition::m3g::Group>(var1))->getChildCount(); var4++) {
                jrt::Ref<javax::microedition::m3g::Node> var5 = (jrt::cast<javax::microedition::m3g::Group>(var1))->getChild(var4);
                this->method_903(var5, var2, var3);
            }
        }
    }
}

void class_111::method_894() {
}

void class_111::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1393", this->field_1393);
    d.f("field_1394", this->field_1394);
    d.f("field_1395", this->field_1395);
    d.f("field_1396", this->field_1396);
    d.f("field_1397", this->field_1397);
    d.f("field_1398", this->field_1398);
    d.f("field_1399", this->field_1399);
    d.f("field_1402", this->field_1402);
    d.f("field_1403", this->field_1403);
    d.f("field_1407", this->field_1407);
    d.f("field_1408", this->field_1408);
}

