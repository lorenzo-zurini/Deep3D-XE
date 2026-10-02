// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_88::field_1172{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_88::field_1173{};
jrt::Ref<jrt::Array<int32_t>> class_88::field_1174{};
int32_t class_88::field_1175{};
int64_t class_88::field_1176{};
jrt::Ref<jrt::Array<int64_t>> class_88::field_1177{};
jrt::Ref<jrt::Array<int16_t>> class_88::field_1178{};
jrt::Ref<javax::microedition::media::Player> class_88::field_1179{};

void class_88::__clinit() {
    class_88::field_1172 = jrt::arrayOf<jrt::Ref<java::lang::String>>({JRT_LIT(u"/data/sound/station.mid"), JRT_LIT(u"/data/sound/station.mid")});
    class_88::field_1173 = jrt::arrayOf<jrt::Ref<java::lang::String>>({JRT_LIT(u"/data/sound/echolot.amr"), JRT_LIT(u"/data/sound/traktor.amr"), JRT_LIT(u"/data/sound/message.amr"), JRT_LIT(u"/data/sound/gate.amr"), JRT_LIT(u"/data/sound/alert.amr"), JRT_LIT(u"/data/sound/harpoon.amr"), JRT_LIT(u"/data/sound/explosion.amr"), JRT_LIT(u"/data/sound/turbo.amr"), JRT_LIT(u"/data/sound/water.amr"), JRT_LIT(u"/data/sound/tiertot.amr"), JRT_LIT(u"/data/sound/signal.amr"), JRT_LIT(u"/data/sound/mine.amr"), JRT_LIT(u"/data/sound/amb02.amr"), JRT_LIT(u"/data/sound/amb03.amr"), JRT_LIT(u"/data/sound/harpoon_hit.amr"), JRT_LIT(u"/data/sound/beep.amr")});
    class_88::field_1174 = jrt::arrayOf<int32_t>({0, 8, 12, 13});
    class_88::field_1177 = jrt::arrayOf<int64_t>({int64_t(1300), int64_t(2500), int64_t(1100), int64_t(3000), int64_t(1400), int64_t(900), int64_t(2800), int64_t(3200), int64_t(2800), int64_t(1000), int64_t(1000), int64_t(300), int64_t(1500), int64_t(1500), int64_t(150), int64_t(90)});
    class_88::field_1178 = jrt::arrayOf<int16_t>({int16_t(0), int16_t(95), int16_t(100), int16_t(100), int16_t(100), int16_t(90), int16_t(100), int16_t(100), int16_t(0), int16_t(100), int16_t(100), int16_t(80), int16_t(80), int16_t(80), int16_t(90), int16_t(80)});
}

void class_88::__init() {
    this->field_1183 = false;
    this->field_1182 = 100;
    this->field_1180 = jrt::newArray<jrt::Ref<javax::microedition::media::Player>>(class_88::field_1173->length);
}

void class_88::method_765(int32_t var1) {
    if ((class_88::field_1179 != nullptr) && (class_88::field_1179->getState() != 0)) {
        this->field_1181 = jrt::cast<javax::microedition::media::control::VolumeControl>(class_88::field_1179->getControl(JRT_LIT(u"VolumeControl")));
        this->field_1181->setLevel(var1);
    }
    if (this->field_1180 != nullptr) {
        for (int32_t var2 = 0; var2 < this->field_1180->length; var2++) {
            if ((this->field_1180->at(var2) != nullptr) && (this->field_1180->at(var2)->getState() != 0)) {
                this->field_1181 = jrt::cast<javax::microedition::media::control::VolumeControl>(this->field_1180->at(var2)->getControl(JRT_LIT(u"VolumeControl")));
                this->field_1181->setLevel(var1);
            }
        }
    }
    this->field_1182 = var1;
}

void class_88::method_766() {
    if (class_88::field_1179 != nullptr) {
        if (class_88::field_1179->getState() != 0) {
            class_88::field_1179->deallocate();
        }
        class_88::field_1179->close();
        class_88::field_1179 = jrt::Ref<javax::microedition::media::Player>(nullptr);
    }
    this->field_1181 = jrt::Ref<javax::microedition::media::control::VolumeControl>(nullptr);
}

bool class_88::method_767() {
    if (!class_84::field_1080) {
        return false;
    } else {
        return (class_88::field_1179 == nullptr) ? false : (class_88::field_1179->getState() == 400);
    }
}

void class_88::method_768(int32_t var1) {
    if (class_84::field_1080) {
        this->method_773();
        {
            try {
                class_88::field_1179 = javax::microedition::media::Manager::createPlayer(jrt::getResourceAsStream(class_88::field_1172->at(var1)), JRT_LIT(u"audio/midi"));
                class_88::field_1179->addPlayerListener(jrt::Ref<javax::microedition::media::PlayerListener>(jrt::Ref<class_88>(this)));
                class_88::field_1179->setLoopCount((-1));
                class_88::field_1179->start();
                class_84::field_1115 = var1;
                jrt::Ref<javax::microedition::media::control::VolumeControl> var3{};
                (var3 = jrt::cast<javax::microedition::media::control::VolumeControl>(class_88::field_1179->getControl(JRT_LIT(u"VolumeControl"))))->setLevel(40);
                {
                    try {
                        var3->setMute(false);
                    } catch (const jrt::Thrown& __ex1) {
                        if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                            jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex1.t);
                        } else {
                            throw;
                        }
                    }
                }
                class_84::field_1114 = false;
            } catch (const jrt::Thrown& __ex2) {
                if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                    jrt::Ref<java::lang::Exception> var6 = jrt::cast<java::lang::Exception>(__ex2.t);
                    class_84::field_1114 = true;
                    if (class_88::field_1179 != nullptr) {
                        class_88::field_1179->deallocate();
                        class_88::field_1179->close();
                    }
                    class_88::field_1179 = jrt::Ref<javax::microedition::media::Player>(nullptr);
                } else {
                    throw;
                }
            }
        }
    }
}

void class_88::method_769(int32_t var1, int32_t var2) {
    if (class_84::field_1080) {
        if ((org::deep3d::Det::millis() > (class_88::field_1176 + class_88::field_1177->at(class_88::field_1175))) || (int32_t(class_88::field_1178->at(var1)) >= int32_t(class_88::field_1178->at(class_88::field_1175)))) {
            {
                try {
                    if (this->field_1180->at(var1) == nullptr) {
                        {
                            try {
                                jrt::Ref<java::io::InputStream> var3 = jrt::getResourceAsStream(class_88::field_1173->at(var1));
                                this->field_1180->at(var1) = javax::microedition::media::Manager::createPlayer(var3, JRT_LIT(u"audio/amr"));
                                this->field_1180->at(var1)->setLoopCount(1);
                                this->field_1180->at(var1)->prefetch();
                            } catch (const jrt::Thrown& __ex1) {
                                if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                                    jrt::Ref<java::lang::Exception> var4 = jrt::cast<java::lang::Exception>(__ex1.t);
                                    var4->printStackTrace();
                                } else {
                                    throw;
                                }
                            }
                        }
                    }
                    (jrt::cast<javax::microedition::media::control::VolumeControl>(this->field_1180->at(var1)->getControl(JRT_LIT(u"VolumeControl"))))->setLevel(var2);
                    this->field_1180->at(var1)->stop();
                    this->field_1180->at(var1)->setMediaTime(int64_t(0));
                    this->field_1180->at(var1)->start();
                    class_88::field_1175 = var1;
                    class_88::field_1176 = org::deep3d::Det::millis();
                    return;
                } catch (const jrt::Thrown& __ex2) {
                    if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                        jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex2.t);
                        var5->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
        }
    }
}

void class_88::method_770(int32_t var1) {
    this->method_769(var1, this->field_1182);
}

void class_88::method_771() {
    {
        try {
            {
                try {
                    jrt::Ref<javax::microedition::media::control::VolumeControl> var1 = jrt::cast<javax::microedition::media::control::VolumeControl>(class_88::field_1179->getControl(JRT_LIT(u"VolumeControl")));
                    this->field_1184 = var1->getLevel();
                    var1->setMute(true);
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> var2 = jrt::cast<java::lang::Exception>(__ex1.t);
                    } else {
                        throw;
                    }
                }
            }
            class_88::field_1179->stop();
            for (int32_t var4 = 0; var4 < this->field_1180->length; var4++) {
                if (this->field_1180->at(var4) != nullptr) {
                    this->field_1180->at(var4)->stop();
                }
            }
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex2.t);
            } else {
                throw;
            }
        }
    }
}

void class_88::method_772() {
    {
        try {
            if (class_84::field_1080) {
                {
                    try {
                        jrt::Ref<javax::microedition::media::control::VolumeControl> var1{};
                        (var1 = jrt::cast<javax::microedition::media::control::VolumeControl>(class_88::field_1179->getControl(JRT_LIT(u"VolumeControl"))))->setMute(false);
                        javax::microedition::lcdui::AlertType::ERROR->playSound(class_84::field_1112);
                        var1->setLevel(this->field_1184);
                    } catch (const jrt::Thrown& __ex1) {
                        if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                            jrt::Ref<java::lang::Exception> var4 = jrt::cast<java::lang::Exception>(__ex1.t);
                        } else {
                            throw;
                        }
                    }
                }
                class_88::field_1179->start();
            }
            class_84::field_1114 = false;
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex2.t);
                class_84::field_1114 = true;
                if (class_88::field_1179 != nullptr) {
                    {
                        try {
                            class_88::field_1179->deallocate();
                            class_88::field_1179->close();
                        } catch (const jrt::Thrown& __ex3) {
                            if (jrt::isInstance<java::lang::Exception>(__ex3.t)) {
                                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex3.t);
                            } else {
                                throw;
                            }
                        }
                    }
                }
                class_88::field_1179 = jrt::Ref<javax::microedition::media::Player>(nullptr);
            } else {
                throw;
            }
        }
    }
}

void class_88::method_773() {
    {
        try {
            if (class_88::field_1179->getState() == 400) {
                class_88::field_1179->stop();
                class_88::field_1179->deallocate();
                class_88::field_1179->close();
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

void class_88::playerUpdate(jrt::Ref<javax::microedition::media::Player> var1, jrt::Ref<java::lang::String> var2, jrt::Ref<java::lang::Object> var3) {
    if (((var2->compareTo(JRT_LIT(u"deviceUnavailable")) == 0) && (class_88::field_1179 != nullptr)) && (class_88::field_1179->getState() != 0)) {
        this->field_1183 = true;
    }
    if ((var2->compareTo(JRT_LIT(u"deviceAvailable")) == 0) && this->field_1183) {
        this->field_1183 = false;
        class_84::field_1114 = true;
    }
}

void class_88::__dumpFields(jrt::Dumper& d) {
    d.f("field_1180", this->field_1180);
    d.f("field_1181", this->field_1181);
    d.f("field_1182", this->field_1182);
    d.f("field_1183", this->field_1183);
    d.f("field_1184", this->field_1184);
}

