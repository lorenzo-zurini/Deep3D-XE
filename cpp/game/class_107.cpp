// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::m3g::Transform> class_107::field_1363{};

void class_107::__clinit() {
    class_107::field_1363 = jrt::New<javax::microedition::m3g::Transform>();
}

void class_107::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    class_106::__init(var1, var2, var3, var4, var5);
}

void class_107::__init(jrt::Ref<class_107> var1) {
    class_106::__init(jrt::Ref<class_106>(var1));
    this->field_1362 = var1->field_1362;
    class_107::field_1363->set(class_107::field_1363);
}

void class_107::method_881(int32_t var1, int32_t var2, int32_t var3) {
    float var4 = 0.8f;
    class_106::method_881(var1, var2, var3);
    if (this->field_1362 == nullptr) {
        this->field_1362 = jrt::New<javax::microedition::m3g::Camera>();
    }
    if ((this->class_106::field_1358 != 0) && (this->class_106::field_1359 != 0)) {
        var4 = float(this->class_106::field_1358) / float(this->class_106::field_1359);
    }
    this->field_1362->setPerspective((float(var1) * 0.087890625f), var4, float(var2), float(var3));
}

void class_107::method_885() {
    if (class_72::field_1016 != nullptr) {
        class_72::field_1016->setCamera(this->field_1362, class_107::field_1363);
    }
}

jrt::Ref<class_102> class_107::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_107>(jrt::Ref<class_107>(this)));
}

void class_107::__dumpFields(jrt::Dumper& d) {
    class_106::__dumpFields(d);
    d.f("field_1362", this->field_1362);
}

