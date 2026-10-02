// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Transform> class_117::field_1438{};
jrt::Ref<jrt::Array<float>> class_117::field_1439{};
jrt::Ref<javax::microedition::m3g::CompositingMode> class_117::field_1441{};

void class_117::__clinit() {
    class_117::field_1438 = jrt::New<javax::microedition::m3g::Transform>();
    class_117::field_1439 = jrt::newArray<float>(16);
}

void class_117::__init(jrt::Ref<java::lang::String> var1) {
    class_108::__init();
    this->method_911(var1);
    this->class_105::field_1348 = 0;
    if (class_117::field_1441 == nullptr) {
        class_117::field_1441 = jrt::New<javax::microedition::m3g::CompositingMode>();
        class_117::field_1441->setBlending(64);
        class_117::field_1441->setDepthTestEnable(true);
        class_117::field_1441->setDepthWriteEnable(false);
    }
}

void class_117::__init(jrt::Ref<class_117> var1) {
    class_108::__init();
    this->class_105::field_1348 = 0;
    this->field_1440 = var1->field_1440;
    this->class_108::field_1367 = var1->field_1367;
    this->class_102::field_1338 = var1->field_1338;
}

void class_117::method_911(jrt::Ref<java::lang::String> var1) {
    {
        try {
            jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> var3 = javax::microedition::m3g::Loader::load(class_28::method_283(jrt::concat(var1, JRT_LIT(u".m3g"))), 0);
            for (int32_t var4 = 0; var4 < var3->length; var4++) {
                if (jrt::isInstance<javax::microedition::m3g::Group>(var3->at(var4))) {
                    this->field_1440 = jrt::cast<javax::microedition::m3g::Node>(var3->at(var4));
                    break;
                }
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex1.t);
                this->field_1440 = jrt::Ref<javax::microedition::m3g::Node>(nullptr);
            } else {
                throw;
            }
        }
    }
}

void class_117::method_887() {
    this->class_108::field_1368->method_505(class_117::field_1439);
    class_117::field_1439->at(3) = class_117::field_1439->at(7) = class_117::field_1439->at(11) = 0.0f;
    class_117::field_1439->at(7) = float(this->field_1442);
    class_117::field_1438->set(class_117::field_1439);
    class_72::field_1016->render(this->field_1440, class_117::field_1438);
}

void class_117::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        this->class_108::field_1368 = var1->field_1342->method_503(this->class_108::field_1368);
        var2->method_30(this->class_108::field_1367, jrt::Ref<class_108>(jrt::Ref<class_117>(this)));
    }
}

jrt::Ref<class_102> class_117::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_117>(jrt::Ref<class_117>(this)));
}

void class_117::method_893(jrt::Ref<class_44> var1) {
    this->method_912(jrt::cast<javax::microedition::m3g::Group>(this->field_1440), (jrt::cast<class_45>(var1))->field_476);
}

void class_117::method_912(jrt::Ref<javax::microedition::m3g::Group> var1, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> var2) {
    for (int32_t var3 = 0; var3 < var1->getChildCount(); var3++) {
        jrt::Ref<javax::microedition::m3g::Node> var4{};
        if (jrt::isInstance<javax::microedition::m3g::Mesh>((var4 = var1->getChild(var3)))) {
            int32_t var5 = (jrt::cast<javax::microedition::m3g::Mesh>(var4))->getUserID();
            for (int32_t var6 = 0; var6 < (jrt::cast<javax::microedition::m3g::Mesh>(var4))->getSubmeshCount(); var6++) {
                jrt::Ref<javax::microedition::m3g::Appearance> var7{};
                (var7 = (jrt::cast<javax::microedition::m3g::Mesh>(var4))->getAppearance(var6))->setMaterial(jrt::Ref<javax::microedition::m3g::Material>(nullptr));
                var7->setCompositingMode(class_117::field_1441);
                if (var7->getTexture(0) != nullptr) {
                    if (var2 != nullptr) {
                        if (var5 < var2->length) {
                            var7->setTexture(0, var2->at(var5));
                        } else {
                            var7->setTexture(0, var2->at(0));
                        }
                    } else {
                        var7->setTexture(0, jrt::Ref<javax::microedition::m3g::Texture2D>(nullptr));
                    }
                }
            }
        } else if (jrt::isInstance<javax::microedition::m3g::Group>(var4)) {
            this->method_912(jrt::cast<javax::microedition::m3g::Group>(var4), var2);
        }
    }
}

void class_117::method_894() {
    this->field_1440 = jrt::Ref<javax::microedition::m3g::Node>(nullptr);
}

void class_117::__dumpFields(jrt::Dumper& d) {
    class_108::__dumpFields(d);
    d.f("field_1440", this->field_1440);
    d.f("field_1442", this->field_1442);
}

