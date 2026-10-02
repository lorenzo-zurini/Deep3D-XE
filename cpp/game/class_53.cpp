// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_53::__clinit() {
}

void class_53::__init() {
    this->field_594 = jrt::New<javax::microedition::lcdui::Form>(JRT_LIT(u"Deep"));
    this->field_594->append(class_84::field_1116->method_4(303));
    this->field_594->addCommand(jrt::New<javax::microedition::lcdui::Command>(class_84::field_1116->method_4(65), 3, 0));
    this->field_594->addCommand(jrt::New<javax::microedition::lcdui::Command>(JRT_LIT(u"Click!"), 1, 1));
    this->field_594->setCommandListener(jrt::Ref<javax::microedition::lcdui::CommandListener>(jrt::Ref<class_53>(this)));
}

void class_53::method_436() {
    {
        try {
            if (this->field_590 == nullptr) {
                this->field_590 = javax::microedition::media::Manager::createPlayer(JRT_LIT(u"capture://image"));
                this->field_590->addPlayerListener(jrt::Ref<javax::microedition::media::PlayerListener>(jrt::Ref<class_53>(this)));
                this->field_590->realize();
            }
            if (this->field_591 == nullptr) {
                this->field_591 = jrt::cast<javax::microedition::media::control::VideoControl>(this->field_590->getControl(JRT_LIT(u"VideoControl")));
                if (this->field_591 != nullptr) {
                    this->field_594->set(0, jrt::cast<javax::microedition::lcdui::Item>(this->field_591->initDisplayMode(0, jrt::Ref<java::lang::Object>(nullptr))));
                    this->field_594->get(0)->setLayout(51);
                    {
                        try {
                            this->field_591->setDisplaySize(class_84::field_1120, class_84::field_1120);
                        } catch (const jrt::Thrown& __ex1) {
                            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                                var2->printStackTrace();
                            } else {
                                throw;
                            }
                        }
                    }
                }
            }
            this->field_590->start();
            class_84::field_1112->setCurrent(jrt::Ref<javax::microedition::lcdui::Displayable>(this->field_594));
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex2.t);
                var3->getMessage();
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<javax::microedition::lcdui::Image> class_53::method_437() {
    if (this->field_590 == nullptr) {
        this->method_436();
    }
    {
        try {
            this->field_593 = this->field_591->getSnapshot(jrt::Ref<java::lang::String>(nullptr));
            this->field_592 = javax::microedition::lcdui::Image::createImage(this->field_593, 0, this->field_593->length);
            this->field_592 = class_28::method_280(this->field_592, class_119::field_1458, jrt::f2i(((float(class_119::field_1459) * float(class_84::field_1121)) / float(class_84::field_1120))));
            this->field_592 = javax::microedition::lcdui::Image::createImage(this->field_592, 0, ((this->field_592->getHeight() - class_119::field_1459) >> 1), class_119::field_1458, class_119::field_1459, 0);
            this->field_590->stop();
            this->field_590->deallocate();
            this->field_590->close();
            this->field_590 = jrt::Ref<javax::microedition::media::Player>(nullptr);
            return this->field_592;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                var2->printStackTrace();
                return jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
            } else {
                throw;
            }
        }
    }
}

void class_53::method_438() {
    if (this->field_590 != nullptr) {
        this->field_590->deallocate();
    }
}

void class_53::playerUpdate(jrt::Ref<javax::microedition::media::Player> var1, jrt::Ref<java::lang::String> var2, jrt::Ref<java::lang::Object> var3) {
}

void class_53::commandAction(jrt::Ref<javax::microedition::lcdui::Command> var1, jrt::Ref<javax::microedition::lcdui::Displayable> var2) {
    if (var1->getLabel()->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u"Click!")))) {
        this->field_592 = this->method_437();
        if (this->field_592 != nullptr) {
            class_51::field_577 = false;
        }
    }
    class_84::field_1112->setCurrent(jrt::Ref<javax::microedition::lcdui::Displayable>(class_84::field_1118));
}

void class_53::__dumpFields(jrt::Dumper& d) {
    d.f("field_590", this->field_590);
    d.f("field_591", this->field_591);
    d.f("field_592", this->field_592);
    d.f("field_593", this->field_593);
    d.f("field_594", this->field_594);
}

