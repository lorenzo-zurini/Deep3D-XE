// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void DeepMIDlet::__clinit() {
}

void DeepMIDlet::__init() {
    javax::microedition::midlet::MIDlet::__init();
    this->field_1528 = false;
    this->field_1529 = false;
    {
        try {
            this->field_1527 = javax::microedition::lcdui::Display::getDisplay(jrt::Ref<javax::microedition::midlet::MIDlet>(jrt::Ref<DeepMIDlet>(this)));
            class_84::field_1112 = this->field_1527;
            class_84::field_1119 = jrt::Ref<javax::microedition::midlet::MIDlet>(jrt::Ref<DeepMIDlet>(this));
            this->field_1526 = jrt::New<class_124>(jrt::Ref<DeepMIDlet>(this));
            this->field_1530 = jrt::New<java::lang::Thread>(jrt::Ref<java::lang::Runnable>(jrt::Ref<DeepMIDlet>(this)));
            this->field_1525 = 1;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<javax::microedition::lcdui::Display> DeepMIDlet::getDisplay() {
    return this->field_1527;
}

void DeepMIDlet::startApp() {
    {
        try {
            this->field_1527->setCurrent(jrt::Ref<javax::microedition::lcdui::Displayable>(this->field_1526));
            this->field_1526->setFullScreenMode(true);
            if (!this->field_1528) {
                this->field_1530->start();
                this->field_1528 = true;
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

void DeepMIDlet::pauseApp() {
    this->pause();
}

void DeepMIDlet::resume() {
    this->field_1525 = 2;
}

void DeepMIDlet::pause() {
    this->field_1525 = 4;
}

void DeepMIDlet::destroyApp(bool var1) {
    {
        try {
            this->field_1529 = true;
            if ((java::lang::Thread::currentThread() != this->field_1530) && this->field_1530->isAlive()) {
                this->field_1530->join(int64_t(2000));
            }
            this->field_1526->method_950();
            this->notifyDestroyed();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

void DeepMIDlet::run() {
    {
        try {
            while (!this->field_1529) {
                org::deep3d::Det::frame();
                {
                    switch (this->field_1525) {
                    case 1:
                        if ((class_84::field_1114 && (!this->field_1529)) && (class_84::field_1115 != (-1))) {
                            class_84::field_1122->method_768(class_84::field_1115);
                        }
                        this->field_1526->method_949();
                        this->field_1526->method_952();
                        break;
                    case 2:
                        this->field_1526->method_948();
                        this->field_1525 = 1;
                        break;
                    case 3:
                        this->field_1526->method_951();
                        this->field_1526->method_952();
                        break;
                    case 4:
                        this->field_1526->method_947();
                        this->field_1525 = 3;
                    }
                }
                {
                    try {
                        org::deep3d::Runtime::loopRest(int64_t(2));   // Deep3D-PC: Thread.sleep(2)
                    } catch (const jrt::Thrown& __ex1) {
                        if (jrt::isInstance<java::lang::InterruptedException>(__ex1.t)) {
                            jrt::Ref<java::lang::InterruptedException> var2 = jrt::cast<java::lang::InterruptedException>(__ex1.t);
                        } else {
                            throw;
                        }
                    }
                }
            }
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex2.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void DeepMIDlet::quit() {
    this->destroyApp(false);
}

void DeepMIDlet::__dumpFields(jrt::Dumper& d) {
    d.f("field_1525", this->field_1525);
    d.f("field_1526", this->field_1526);
    d.f("field_1527", this->field_1527);
    d.f("field_1528", this->field_1528);
    d.f("field_1529", this->field_1529);
    d.f("field_1530", this->field_1530);
}

