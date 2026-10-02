// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_103::__clinit() {
}

void class_103::__init() {
    class_102::__init();
    this->field_1345 = jrt::Ref<class_102>(nullptr);
}

void class_103::__init(jrt::Ref<class_103> var1) {
    class_102::__init(jrt::Ref<class_102>(var1));
    for (jrt::Ref<class_102> var2 = var1->field_1345; var2 != nullptr; var2 = var2->field_1337) {
        this->method_879(var2->method_840());
    }
}

jrt::Ref<class_102> class_103::method_840() {
    return jrt::Ref<class_102>(jrt::New<class_103>(jrt::Ref<class_103>(this)));
}

void class_103::method_879(jrt::Ref<class_102> var1) {
    if (var1 != nullptr) {
        var1->field_1336 = jrt::Ref<class_103>(this);
        var1->field_1337 = this->field_1345;
        this->field_1345 = var1;
    }
}

void class_103::method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        {
            switch (2) {
            case 1:
                for (jrt::Ref<class_102> var5 = this->field_1345; var5 != nullptr; var5 = var5->field_1337) {
                    var5->method_837(var1, var2);
                }
                break;
            case 2:
                for (jrt::Ref<class_102> var4 = this->field_1345; var4 != nullptr; var4 = var4->field_1337) {
                    var4->method_838(var1, var2);
                }
                return;
            }
        }
    }
}

void class_103::method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) {
    if (this->class_102::field_1338) {
        for (jrt::Ref<class_102> var3 = this->field_1345; var3 != nullptr; var3 = var3->field_1337) {
            var3->method_838(var1, var2);
        }
    }
}

void class_103::method_839(bool var1) {
    if (this->class_102::field_1340 || var1) {
        if (this->class_102::field_1339 || var1) {
            if (this->class_102::field_1336 != nullptr) {
                this->class_102::field_1342 = this->class_102::field_1336->field_1342->method_473(this->class_102::field_1341, this->class_102::field_1342);
            } else {
                this->class_102::field_1342->method_470(this->class_102::field_1341);
            }
        }
        for (jrt::Ref<class_102> var2 = this->field_1345; var2 != nullptr; var2 = var2->field_1337) {
            var2->method_839((this->class_102::field_1339 || var1));
        }
        this->class_102::field_1343->method_89(this->class_102::field_1342->field_698, this->class_102::field_1342->field_699, this->class_102::field_1342->field_700, 0);
        for (jrt::Ref<class_102> var3 = this->field_1345; var3 != nullptr; var3 = var3->field_1337) {
            this->class_102::field_1343->method_87(var3->field_1343);
        }
        this->class_102::field_1340 = false;
        this->class_102::field_1339 = false;
    }
}

jrt::Ref<java::lang::String> class_103::method_842(jrt::Ref<java::lang::String> var1, int32_t var2) {
    for (int32_t var3 = 0; var3 < var2; var3++) {
        var1 = jrt::concat(var1, JRT_LIT(u"  "));
    }
    var1 = jrt::concat(var1, JRT_LIT(u" |\t"), this->class_102::field_1343->field_148->field_37, JRT_LIT(u"\t\t"), this->class_102::field_1343->field_148->field_38, JRT_LIT(u"\t\t"), this->class_102::field_1343->field_148->field_39, JRT_LIT(u"\t\t"), this->class_102::field_1343->field_149, JRT_LIT(u"\n"));
    var2++;
    for (jrt::Ref<class_102> var6 = this->field_1345; var6 != nullptr; var6 = var6->field_1337) {
        var1 = var6->method_842(var1, var2);
    }
    return var1;
}

void class_103::method_876(int32_t var1, int32_t var2) {
    for (jrt::Ref<class_102> var3 = this->field_1345; var3 != nullptr; var3 = var3->field_1337) {
        var3->method_876(var1, var2);
    }
}

void class_103::method_877(int8_t var1) {
    for (jrt::Ref<class_102> var2 = this->field_1345; var2 != nullptr; var2 = var2->field_1337) {
        var2->method_877(var1);
    }
}

void class_103::method_878() {
    for (jrt::Ref<class_102> var1 = this->field_1345; var1 != nullptr; var1 = var1->field_1337) {
        var1->method_878();
    }
}

void class_103::__dumpFields(jrt::Dumper& d) {
    class_102::__dumpFields(d);
    d.f("field_1345", this->field_1345);
}

