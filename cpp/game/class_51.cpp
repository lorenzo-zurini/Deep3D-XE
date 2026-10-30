// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_51::field_552{};
int32_t class_51::field_553{};
int32_t class_51::field_554{};
jrt::Ref<jrt::Array<int32_t>> class_51::field_555{};
bool class_51::field_577{};

void class_51::__clinit() {
    class_51::field_555 = jrt::arrayOf<int32_t>({6, 4, 3, 3, 3, 5, 10, 0, 0, 2, 12, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
}

void class_51::__init() {
    this->field_578 = false;
    this->field_579 = jrt::Ref<java::lang::String>(nullptr);
    this->field_580 = jrt::Ref<java::lang::String>(nullptr);
    this->field_581 = jrt::Ref<java::lang::String>(nullptr);
    this->field_582 = (-1);
    this->method_416();
    if (this->field_578) {
        class_51::field_555->at(0) = 7;
    }
    this->field_556 = class_33::method_292();
    class_51::field_553 = this->field_556->getHeight() + 25;
    class_51::field_554 = 114;
    class_51::field_552 = (class_84::field_1120 - class_51::field_554) >> 1;
    this->field_557 = class_58::method_527();
    this->field_559 = 0;
    this->field_560 = 0;
    this->field_562 = jrt::New<class_121>(20, (class_84::field_1121 / 2), (class_84::field_1120 - 40));
    this->field_563 = false;
    this->field_564 = false;
    this->field_568 = jrt::New<class_23>((class_51::field_552 + 5), (class_51::field_553 + 12), (class_51::field_554 - 10), ((class_84::field_1121 - class_51::field_553) - (3 * class_67::method_577())), ([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(25); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(28); return jrt::concat(__c1, __c2, __c3); }()));
    this->field_569 = jrt::New<class_23>((class_51::field_552 + 5), (class_51::field_553 + 12), (class_51::field_554 - 10), ((class_84::field_1121 - class_51::field_553) - (3 * class_67::method_577())), JRT_LIT(u""));
    this->field_570 = jrt::New<class_23>((class_51::field_552 + 5), (class_51::field_553 + 12), (class_51::field_554 - 10), ((class_84::field_1121 - class_51::field_553) - (3 * class_67::method_577())), JRT_LIT(u""));
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1 = jrt::newArray<jrt::Ref<java::lang::String>>(class_1::field_2->length);
    for (int32_t var2 = 0; var2 < var1->length; var2++) {
        var1->at(var2) = class_84::field_1116->method_4(int32_t(class_1::field_1->at(var2)));
    }
    this->field_567 = jrt::New<class_75>(class_51::field_552, class_51::field_553, class_51::field_554, ((class_84::field_1121 - class_51::field_553) - class_67::method_577()), jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr));
    this->field_567->field_1044 = 12;
    this->field_567->method_700(0, jrt::arrayView<jrt::Ref<java::lang::Object>>(var1));
    this->field_567->field_1048 = true;
    this->field_567->field_1047 = false;
    this->field_567->method_711();
    this->field_571 = jrt::New<class_32>(10);
    this->field_576 = class_84::field_1083;
    {
        try {
            java::lang::Class::forName(JRT_LIT(u"javax.microedition.media.control.VideoControl"));
            this->field_574 = jrt::New<class_53>();
            if (java::lang::System::getProperty(JRT_LIT(u"supports.video.capture"))->equalsIgnoreCase(JRT_LIT(u"false"))) {
                jrt::throwJava(jrt::New<java::lang::Exception>());
            }
        } catch (const jrt::Thrown& __ex4) {
            if (jrt::isInstance<java::lang::Exception>(__ex4.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex4.t);
                this->field_574 = jrt::Ref<class_53>(nullptr);
                class_51::field_555->at(12) = 2;
            } else {
                throw;
            }
        }
    }
    class_51::field_577 = true;
}

jrt::Ref<java::lang::String> class_51::method_415(jrt::Ref<java::lang::String> var1) {
    int32_t var2 = 0;
    int32_t var3 = var1->length();
    jrt::Ref<java::lang::StringBuffer> var4 = jrt::New<java::lang::StringBuffer>();
    while (var2 < var3) {
        char16_t var5{};
        if (((int32_t((var5 = var1->charAt(var2))) == int32_t(char16_t(92))) && ((var2 + 6) <= var3)) && (int32_t(var1->charAt((var2 + 1))) == int32_t(u'u'))) {
            char16_t var7 = char16_t(java::lang::Integer::parseInt(var1->substring((var2 + 2), (var2 + 6)), 16));
            var4->append(var7);
            var2 += 6;
        } else {
            var4->append(var5);
            var2++;
        }
    }
    return var4->toString();
}

void class_51::method_416() {
    {
        try {
            {
                try {
                    this->field_579 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-URL-en"));
                    this->field_581 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Menu-en"));
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> var10 = jrt::cast<java::lang::Exception>(__ex1.t);
                        this->field_578 = false;
                        this->field_579 = jrt::Ref<java::lang::String>(nullptr);
                        this->field_580 = jrt::Ref<java::lang::String>(nullptr);
                        this->field_581 = jrt::Ref<java::lang::String>(nullptr);
                        {
                            try {
                                this->field_579 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-URL-gn"));
                                this->field_581 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Menu-gn"));
                            } catch (const jrt::Thrown& __ex2) {
                                if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                                    jrt::Ref<java::lang::Exception> var9 = jrt::cast<java::lang::Exception>(__ex2.t);
                                    this->field_578 = false;
                                    return;
                                } else {
                                    throw;
                                }
                            }
                        }
                        if ((this->field_579 == nullptr) || (this->field_581 == nullptr)) {
                            this->field_578 = false;
                            return;
                        }
                    } else {
                        throw;
                    }
                }
            }
            if ((this->field_579 == nullptr) || (this->field_581 == nullptr)) {
                {
                    try {
                        this->field_579 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-URL-gn"));
                        this->field_581 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Menu-gn"));
                    } catch (const jrt::Thrown& __ex3) {
                        if (jrt::isInstance<java::lang::Exception>(__ex3.t)) {
                            jrt::Ref<java::lang::Exception> var8 = jrt::cast<java::lang::Exception>(__ex3.t);
                            this->field_578 = false;
                            return;
                        } else {
                            throw;
                        }
                    }
                }
            }
            {
                try {
                    this->field_580 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Prompt-en"));
                } catch (const jrt::Thrown& __ex4) {
                    if (jrt::isInstance<java::lang::Exception>(__ex4.t)) {
                        jrt::Ref<java::lang::Exception> var7 = jrt::cast<java::lang::Exception>(__ex4.t);
                        this->field_580 = jrt::Ref<java::lang::String>(nullptr);
                        {
                            try {
                                this->field_580 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Prompt-gn"));
                            } catch (const jrt::Thrown& __ex5) {
                                if (jrt::isInstance<java::lang::Exception>(__ex5.t)) {
                                    jrt::Ref<java::lang::Exception> var6 = jrt::cast<java::lang::Exception>(__ex5.t);
                                } else {
                                    throw;
                                }
                            }
                        }
                    } else {
                        throw;
                    }
                }
            }
            if (this->field_580 == nullptr) {
                {
                    try {
                        this->field_580 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Prompt-gn"));
                    } catch (const jrt::Thrown& __ex6) {
                        if (jrt::isInstance<java::lang::Exception>(__ex6.t)) {
                            jrt::Ref<java::lang::Exception> var5 = jrt::cast<java::lang::Exception>(__ex6.t);
                        } else {
                            throw;
                        }
                    }
                }
            }
            if (this->field_580 != nullptr) {
                this->field_580 = this->method_415(this->field_580);
            }
            if (this->field_581 != nullptr) {
                this->field_581 = this->method_415(this->field_581);
            }
            java::lang::System::out->println(jrt::concat(JRT_LIT(u"wap_url: "), this->field_579));
            java::lang::System::out->println(jrt::concat(JRT_LIT(u"wap_menu: "), this->field_581));
            java::lang::System::out->println(jrt::concat(JRT_LIT(u"wap_prompt: "), this->field_580));
            jrt::Ref<java::lang::String> var1 = class_84::field_1119->getAppProperty(JRT_LIT(u"Operator-Mode"));
            if ((this->field_579 != nullptr) && (var1 != nullptr)) {
                jrt::Ref<jrt::Array<char16_t>> var2 = jrt::arrayOf<char16_t>({u'1', u'2'});
                for (int32_t var3 = 0; var3 < var2->length; var3++) {
                    int32_t var4{};
                    if ((var4 = var1->indexOf(java::lang::String::valueOf(var2->at(var3)))) >= 0) {
                        this->field_582 = (java::lang::Integer::valueOf(java::lang::String::valueOf(var1->charAt(var4))))->intValue();
                    }
                }
                java::lang::System::out->println(jrt::concat(JRT_LIT(u"wap_mode: "), this->field_582));
                if ((this->field_582 < 1) || (this->field_582 > 2)) {
                    this->field_582 = 2;
                }
                this->field_578 = true;
            } else {
                jrt::throwJava(jrt::New<java::lang::Exception>());
            }
        } catch (const jrt::Thrown& __ex7) {
            if (jrt::isInstance<java::lang::Exception>(__ex7.t)) {
                jrt::Ref<java::lang::Exception> var11 = jrt::cast<java::lang::Exception>(__ex7.t);
                this->field_578 = false;
            } else {
                throw;
            }
        }
    }
}

void class_51::method_417() {
    this->field_565 = jrt::Ref<jrt::Array<jrt::Ref<class_41>>>(nullptr);
    this->field_562 = jrt::Ref<class_121>(nullptr);
    this->field_556 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
}

void class_51::method_418(int32_t var1, int32_t var2) {
    this->field_572 = var2;
    class_67::method_579(var2);
    if ((var1 & 64) != 0) {
        if (this->field_560 >= 15) {
            this->field_569->deep3dHeldDown(var2);
            return;
        }
        if (this->field_560 == 8) {
            this->field_568->deep3dHeldDown(var2);
            return;
        }
    } else if ((var1 & 2) != 0) {
        if (this->field_560 >= 15) {
            this->field_569->deep3dHeldUp(var2);
            return;
        }
        if (this->field_560 == 8) {
            this->field_568->deep3dHeldUp(var2);
        }
    }
}

bool class_51::method_419() {
    {
        switch (this->field_560) {
        case 0:
            if (this->field_563 && (this->field_559 == 5)) {
                if (this->field_562->method_941()) {
                    class_84::field_1126->method_440();
                    return true;
                }
                this->field_563 = false;
                return false;
            }
            {
                switch (this->field_559) {
                case 0:
                    if (class_21::method_212() > int64_t(0)) {
                        if (!this->field_563) {
                            this->field_562->method_940(class_84::field_1116->method_4(34), true);
                            this->field_563 = true;
                            return false;
                        }
                        if (this->field_562->method_941()) {
                            this->field_560 = 11;
                            this->field_559 = 0;
                        }
                        this->field_563 = false;
                    } else {
                        this->field_560 = 11;
                        this->field_559 = 0;
                    }
                    return false;
                case 1:
                    this->field_560 = 1;
                    if (this->field_565 == nullptr) {
                        this->field_565 = class_27::method_272();
                    }
                    this->field_559 = 0;
                    return false;
                case 2:
                    this->field_560 = 2;
                    if (this->field_565 == nullptr) {
                        this->field_565 = class_27::method_272();
                    }
                    this->field_559 = 0;
                    return false;
                case 3:
                    org::deep3d::GameSettings::open(jrt::Ref<org::deep3d::GameSettings_Toggle>(([&]() { jrt::Ref<class_51__anon1> __o(new class_51__anon1()); __o->__outer = this; __o->__init(); return __o; }())));
                    return false;
                case 4:
                    this->field_560 = 4;
                    this->field_559 = 0;
                    return false;
                case 5:
                    if (!this->field_563) {
                        this->field_562->method_940(class_84::field_1116->method_4(35), true);
                        this->field_563 = true;
                    }
                    return false;
                case 6:
                    if (this->field_578) {
                        {
                            switch (this->field_582) {
                            case 1:
                                {
                                    try {
                                        if ((!this->field_563) && (this->field_580 != nullptr)) {
                                            this->field_562->method_940(this->field_580, true);
                                        } else if ((this->field_580 == nullptr) || this->field_562->method_941()) {
                                            class_84::field_1119->platformRequest(this->field_579);
                                            class_84::field_1126->method_440();
                                            return true;
                                        }
                                        if (this->field_580 != nullptr) {
                                            this->field_563 = !this->field_563;
                                        }
                                    } catch (const jrt::Thrown& __ex1) {
                                        if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                                            jrt::Ref<java::lang::Exception> var4 = jrt::cast<java::lang::Exception>(__ex1.t);
                                        } else {
                                            throw;
                                        }
                                    }
                                }
                                return false;
                            default:
                                {
                                    try {
                                        if ((!this->field_563) && (this->field_580 != nullptr)) {
                                            this->field_562->method_940(this->field_580, true);
                                        } else if ((this->field_580 == nullptr) || this->field_562->method_941()) {
                                            class_84::field_1119->platformRequest(this->field_579);
                                        }
                                        if (this->field_580 != nullptr) {
                                            this->field_563 = !this->field_563;
                                        }
                                    } catch (const jrt::Thrown& __ex2) {
                                        if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                                            jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex2.t);
                                        } else {
                                            throw;
                                        }
                                    }
                                }
                                return false;
                            }
                        }
                    }
                    return false;
                default:
                    return false;
                }
            }
        case 1:
            if (this->field_565->at(this->field_559) != nullptr) {
                if (class_21::method_212() <= int64_t(0)) {
                    this->field_565->at(this->field_559)->method_367();
                    (jrt::cast<class_63>(class_84::field_1127->at(1)))->method_554();
                    class_84::field_1126->method_439(class_84::field_1127->at(1));
                    return true;
                }
                if (!this->field_563) {
                    this->field_562->method_940(class_84::field_1116->method_4(33), true);
                    this->field_563 = true;
                } else {
                    if (this->field_562->method_941()) {
                        this->field_565->at(this->field_559)->method_367();
                        (jrt::cast<class_63>(class_84::field_1127->at(1)))->method_554();
                        class_84::field_1126->method_439(class_84::field_1127->at(1));
                    }
                    this->field_563 = false;
                }
            }
            break;
        case 2:
            if (this->field_563) {
                if (!this->field_562->method_941()) {
                    this->field_563 = false;
                    return true;
                }
                class_84::field_1113->method_296(false);
                class_27::method_277(this->field_559);
                this->field_565->at(this->field_559) = class_27::method_273(this->field_559);
                class_84::field_1113->method_295();
                this->field_562->method_940(class_84::field_1116->method_4(32), false);
            } else if (this->field_565->at(this->field_559) != nullptr) {
                this->field_562->method_940(class_84::field_1116->method_4(31), true);
                this->field_563 = true;
            } else {
                class_84::field_1113->method_296(false);
                class_27::method_277(this->field_559);
                this->field_565 = class_27::method_272();
                class_84::field_1113->method_295();
                this->field_562->method_940(class_84::field_1116->method_4(32), false);
                this->field_563 = true;
            }
            break;
        case 3:
            this->method_424();
            break;
        case 4:
            {
                switch (this->field_559) {
                case 0:
                    this->field_560 = 6;
                    this->field_559 = 0;
                    this->field_567->field_1039 = 0;
                    return false;
                case 1:
                    this->field_560 = 7;
                    return false;
                case 2:
                    this->field_560 = 8;
                    return false;
                default:
                    return false;
                }
            }
        case 5:
            if (this->field_563) {
                if (this->field_562->method_941()) {
                    class_84::field_1126->method_439(class_84::field_1127->at(0));
                    class_84::field_1122->method_768(0);
                    return true;
                }
                this->field_563 = false;
            } else {
                {
                    switch (this->field_559) {
                    case 0:
                        org::deep3d::GameSettings::open(jrt::Ref<org::deep3d::GameSettings_Toggle>(([&]() { jrt::Ref<class_51__anon2> __o(new class_51__anon2()); __o->__outer = this; __o->__init(); return __o; }())));
                        return false;
                    case 1:
                        this->field_560 = 4;
                        this->field_559 = 0;
                        return false;
                    case 2:
                        if ((!class_21::method_132()->method_754()) && (!class_21::method_132()->field_1161)) {
                            this->field_570->method_225(([&]() { jrt::Ref<java::lang::String> __c3 = class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_12->at(class_21::method_132()->field_1146))), class_21::method_132()->field_1153); jrt::Ref<java::lang::String> __c4 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c5 = class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_13->at(class_21::method_132()->field_1146))), class_21::method_132()->field_1153); return jrt::concat(__c3, __c4, __c5); }()));
                        } else if (!class_21::method_146()) {
                            jrt::Ref<java::lang::String> var1 = class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_11->at(class_21::method_143()))), class_21::method_137()->field_1153);
                            jrt::Ref<class_87> var2{};
                            if ((var2 = class_21::method_137())->field_1146 == 16) {
                                var1 = jrt::concat(var1, JRT_LIT(u" "), class_21::method_202(), JRT_LIT(u" / "), var2->field_1170);
                            } else if (var2->field_1146 == 18) {
                                var1 = jrt::concat(var1, JRT_LIT(u" "), class_21::method_177(), JRT_LIT(u" / "), var2->field_1170);
                            } else if (var2->field_1146 == 21) {
                                var1 = jrt::concat(var1, JRT_LIT(u" "), class_21::method_191(), JRT_LIT(u" / "), var2->field_1170);
                            } else if (var2->field_1146 == 15) {
                                var1 = jrt::concat(var1, JRT_LIT(u" "), class_21::method_209(), JRT_LIT(u" / "), var2->field_1170);
                            }
                            this->field_570->method_225(jrt::concat(class_21::method_219(class_84::field_1116->method_4(int32_t(class_1::field_10->at(class_21::method_143()))), class_21::method_137()->field_1153), JRT_LIT(u"\n\n"), var1));
                        } else if (class_21::method_146()) {
                            this->field_570->method_225(class_84::field_1116->method_4(609));
                        }
                        this->field_560 = 13;
                        this->field_559 = 0;
                        return false;
                    case 3:
                        this->field_560 = 14;
                        this->field_575 = jrt::New<class_80>(class_51::field_552, class_51::field_553, class_51::field_554, (class_84::field_1121 - (2 * class_51::field_553)));
                        return false;
                    case 4:
                        if (!this->field_563) {
                            this->field_562->method_940(class_84::field_1116->method_4(35), true);
                            this->field_563 = true;
                        }
                    }
                }
            }
            break;
        case 6:
            this->field_569->method_224();
            this->field_569->method_225(class_84::field_1116->method_4(int32_t(class_1::field_2->at(this->field_559))));
            this->field_560 = 15 + this->field_559;
            if (this->field_559 == 0) {
                this->field_569->method_225(([&]() { jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(631); jrt::Ref<java::lang::String> __c7 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c8 = class_84::field_1116->method_4(633); jrt::Ref<java::lang::String> __c9 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c10 = class_84::field_1116->method_4(642); jrt::Ref<java::lang::String> __c11 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c12 = class_84::field_1116->method_4(643); jrt::Ref<java::lang::String> __c13 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c14 = class_84::field_1116->method_4(641); jrt::Ref<java::lang::String> __c15 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c16 = class_84::field_1116->method_4(664); jrt::Ref<java::lang::String> __c17 = JRT_LIT(u"\n\n"); return jrt::concat(__c6, __c7, __c8, __c9, __c10, __c11, __c12, __c13, __c14, __c15, __c16, __c17); }()));
            }
        case 7:
            ;
        case 8:
            ;
        case 10:
            ;
        case 11:
            ;
        default:
            break;
        case 9:
            {
                switch (this->field_559) {
                case 0:
                    if (class_21::method_212() > int64_t(0)) {
                        if (!this->field_563) {
                            this->field_562->method_940(class_84::field_1116->method_4(34), true);
                            this->field_563 = true;
                            return false;
                        }
                        if (this->field_562->method_941()) {
                            this->field_560 = 11;
                            this->field_559 = 0;
                        }
                        this->field_563 = false;
                    } else {
                        this->field_560 = 11;
                        this->field_559 = 0;
                    }
                    return false;
                case 1:
                    this->field_560 = 10;
                    this->field_559 = 0;
                    return false;
                default:
                    return false;
                }
            }
        case 12:
            if (this->field_563) {
                if (this->field_562->method_941()) {
                    class_21::method_221();
                    class_84::field_1126->method_439(class_84::field_1127->at(2));
                    class_84::field_1122->method_773();
                    return true;
                }
                this->field_563 = false;
            } else {
                if ((this->field_559 == 2) || ((this->field_574 == nullptr) && (this->field_559 == 1))) {
                    if (class_51::field_577) {
                        class_21::method_216(this->field_573);
                        class_21::method_218(jrt::Ref<javax::microedition::lcdui::Image>(nullptr));
                    } else {
                        class_21::method_218(this->field_574->field_592);
                        class_21::method_216(jrt::Ref<jrt::Array<int8_t>>(nullptr));
                    }
                    this->field_562->method_940(jrt::concat(class_21::method_213(), JRT_LIT(u", "), class_84::field_1116->method_4(298)), true);
                    this->field_563 = true;
                }
                if (this->field_559 == 0) {
                    this->field_573 = class_119::method_920(true, 3);
                    class_51::field_577 = true;
                } else if ((this->field_574 != nullptr) && (this->field_559 == 1)) {
                    this->field_574->method_438();
                    this->field_574->method_436();
                }
            }
        }
    }
    return false;
}

void class_51::method_420(int32_t var1) {
    if (!this->field_563) {
        if (((((this->field_560 != 7) && (this->field_560 != 8)) && (this->field_560 != 13)) && (this->field_560 != 14)) && (this->field_560 < 15)) {
            if (this->field_559 > 0) {
                this->field_559--;
            } else {
                this->field_559 = class_51::field_555->at(this->field_560) - 1;
            }
            if (((this->field_559 == 2) && (this->field_560 == 0)) && (class_21::method_212() == int64_t(0))) {
                this->field_559--;
            }
            if (this->field_560 == 6) {
                this->field_567->method_704();
                return;
            }
        } else {
            if (this->field_560 == 13) {
                this->field_570->method_230(org::deep3d::Step::once(var1));
                return;
            }
            if (this->field_560 == 14) {
                this->field_575->method_704();
            }
        }
    }
}

void class_51::method_421(int32_t var1) {
    if (!this->field_563) {
        if (((((this->field_560 != 7) && (this->field_560 != 8)) && (this->field_560 != 13)) && (this->field_560 != 14)) && (this->field_560 < 15)) {
            if (this->field_559 < (class_51::field_555->at(this->field_560) - 1)) {
                this->field_559++;
            } else {
                this->field_559 = 0;
            }
            if (((this->field_559 == 2) && (this->field_560 == 0)) && (class_21::method_212() == int64_t(0))) {
                this->field_559++;
            }
            if (this->field_560 == 6) {
                this->field_567->method_705();
                return;
            }
        } else {
            if (this->field_560 == 13) {
                this->field_570->method_229(org::deep3d::Step::once(var1));
                return;
            }
            if (this->field_560 == 14) {
                this->field_575->method_705();
            }
        }
    }
}

void class_51::method_422() {
    if (this->field_563) {
        this->field_562->method_942();
    } else {
        if (this->field_560 == 3) {
            {
                switch (this->field_559) {
                case 0:
                    this->field_576--;
                    this->method_423();
                    return;
                case 1:
                    this->method_424();
                    return;
                case 2:
                    this->method_424();
                }
            }
        }
    }
}

void class_51::method_423() {
    if (this->field_576 < 0) {
        this->field_576 = 3;
    }
    if (this->field_576 > 3) {
        this->field_576 = 0;
    }
    {
        switch (this->field_576) {
        case 0:
            class_84::field_1080 = true;
            class_84::field_1122->method_765(60);
            if ((class_84::field_1126->field_595 != class_84::field_1127->at(2)) && (!class_84::field_1122->method_767())) {
                class_84::field_1122->method_768(0);
            }
            break;
        case 1:
            class_84::field_1080 = true;
            class_84::field_1122->method_765(80);
            break;
        case 2:
            class_84::field_1080 = true;
            class_84::field_1122->method_765(100);
            if ((class_84::field_1126->field_595 != class_84::field_1127->at(2)) && (!class_84::field_1122->method_767())) {
                class_84::field_1122->method_768(0);
            }
            break;
        case 3:
            class_84::field_1122->method_773();
            class_84::field_1080 = false;
        }
    }
    class_84::field_1083 = this->field_576;
}

void class_51::method_424() {
    if (this->field_563) {
        this->field_562->method_943();
    } else {
        if (this->field_560 == 3) {
            {
                switch (this->field_559) {
                case 0:
                    this->field_576++;
                    this->method_423();
                    return;
                case 1:
                    class_84::field_1081 = !class_84::field_1081;
                    if (class_84::field_1081) {
                        class_84::method_736(150);
                        return;
                    }
                    break;
                case 2:
                    class_84::field_1082 = !class_84::field_1082;
                }
            }
        }
    }
}

bool class_51::method_425() {
    if (this->field_563) {
        return false;
    } else if ((this->field_560 != 0) && (this->field_560 != 5)) {
        if (this->field_560 == 3) {
            class_27::method_275();
        }
        if (this->field_560 == 7) {
            this->field_559 = 1;
            this->field_560 = 4;
            return false;
        } else if (this->field_560 == 6) {
            this->field_559 = 0;
            this->field_560 = 4;
            return false;
        } else if (this->field_560 >= 15) {
            this->field_560 = 6;
            return false;
        } else if (this->field_560 == 13) {
            this->field_559 = 2;
            this->field_560 = 5;
            return false;
        } else if (this->field_560 == 14) {
            this->field_559 = 3;
            this->field_560 = 5;
            return false;
        } else if (this->field_560 == 10) {
            this->field_559 = 1;
            this->field_560 = 9;
            return false;
        } else if (this->field_560 == 8) {
            this->field_559 = 2;
            this->field_560 = 4;
            return false;
        } else if (this->field_560 == 12) {
            this->field_560 = 11;
            return false;
        } else if (this->field_560 == 11) {
            return false;
        } else {
            if ((this->field_560 > 0) || (this->field_560 == 9)) {
                if (this->field_560 == 9) {
                    this->field_559 = 0;
                } else {
                    this->field_559 = this->field_560;
                }
                this->field_560 = 0;
                if (this->field_564) {
                    this->method_428();
                }
            }
            return false;
        }
    } else {
        return true;
    }
}

bool class_51::method_426() {
    if (this->field_560 == 11) {
        if (this->field_571->field_327->length() > 0) {
            class_21::method_214(jrt::concat(this->field_571->field_327, ((int32_t(this->field_571->field_326) != int32_t(u' ')) ? this->field_571->field_326 : u' '))->trim());
            this->field_560 = 12;
            this->field_573 = class_119::method_920(true, 3);
            this->field_559 = 0;
        }
    } else {
        this->method_419();
    }
    return false;
}

void class_51::method_427(int32_t var1) {
    this->field_559 = var1;
    this->field_560 = 0;
}

void class_51::method_428() {
    this->field_560 = 5;
    this->field_559 = 0;
    this->field_563 = false;
    this->field_564 = true;
}

bool class_51::deep3dRow(int32_t var1) {
    org::deep3d::GameUi::rowIndex(var1);
    return this->field_559 == var1;
}

void class_51::method_429() {
    org::deep3d::GameUi::controls(1, (-6), (-7), 0);
    {
        jrt::Ref<class_51> deep3dSelf(this);
        org::deep3d::GameUi::menuSelect([deep3dSelf](int32_t var1) { deep3dSelf->field_559 = var1; });
    }
    if (this->field_560 == 5) {
        org::deep3d::GameUi::pauseMenuShown();
    }
    class_84::field_1117->drawImage(this->field_556, (class_84::field_1120 / 2), 10, 17);
    if (org::deep3d::Overlay::drawInGameMenu(class_84::field_1117, class_51::field_553)) {
        return;
    }
    {
        int32_t var1{};
        switch (this->field_560) {
        case 0:
            this->field_558 = (class_21::method_212() > int64_t(0)) ? this->field_557 : 0;
            class_67::method_591(class_84::field_1116->method_4(67), class_51::field_552, class_51::field_553, class_51::field_554, ((((class_21::method_212() > int64_t(0)) ? class_51::field_555->at(this->field_560) : (class_51::field_555->at(this->field_560) - 1)) + 2) * this->field_557));
            class_67::method_584(class_84::field_1116->method_4(0), class_51::field_552, (class_51::field_553 + 12), class_51::field_554, this->deep3dRow(0));
            class_67::method_584(class_84::field_1116->method_4(1), class_51::field_552, ((class_51::field_553 + 12) + this->field_557), class_51::field_554, this->deep3dRow(1));
            if (class_21::method_212() > int64_t(0)) {
                class_67::method_584(class_84::field_1116->method_4(2), class_51::field_552, ((class_51::field_553 + 12) + (2 * this->field_557)), class_51::field_554, this->deep3dRow(2));
            }
            class_67::method_584(class_84::field_1116->method_4(3), class_51::field_552, (((class_51::field_553 + 12) + (2 * this->field_557)) + this->field_558), class_51::field_554, this->deep3dRow(3));
            class_67::method_584(class_84::field_1116->method_4(4), class_51::field_552, (((class_51::field_553 + 12) + (3 * this->field_557)) + this->field_558), class_51::field_554, this->deep3dRow(4));
            class_67::method_584(class_84::field_1116->method_4(5), class_51::field_552, (((class_51::field_553 + 12) + (4 * this->field_557)) + this->field_558), class_51::field_554, this->deep3dRow(5));
            if (this->field_578) {
                class_67::method_584(this->field_581, class_51::field_552, (((class_51::field_553 + 12) + (5 * this->field_557)) + this->field_558), class_51::field_554, this->deep3dRow(6));
            }
            break;
        case 1:
            ;
        case 2:
            if (this->field_560 == 2) {
                class_67::method_591(class_84::field_1116->method_4(2), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 3) * this->field_557));
            } else {
                class_67::method_591(class_84::field_1116->method_4(1), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 2) * this->field_557));
            }
            for (int32_t var2 = 0; var2 < this->field_565->length; var2++) {
                this->field_561 = jrt::concat((var2 + 1), JRT_LIT(u".  "));
                if (this->field_565->at(var2) == nullptr) {
                    this->field_561 = jrt::concat(this->field_561, class_84::field_1116->method_4(30));
                } else {
                    this->field_561 = jrt::concat(this->field_561, class_48::method_398(this->field_565->at(var2)->field_397));
                    this->field_566 = this->field_565->at(var2)->field_417;
                    if (var2 == 3) {
                        this->field_561 = jrt::concat(this->field_561, JRT_LIT(u" AUTOSAVE"));
                    } else {
                        this->field_561 = jrt::concat(this->field_561, JRT_LIT(u" "), this->field_566);
                    }
                }
                class_67::method_584(class_67::method_600(this->field_561, (class_51::field_554 - 12)), class_51::field_552, ((class_51::field_553 + 12) + (var2 * this->field_557)), class_51::field_554, this->deep3dRow(var2));
            }
            break;
        case 3:
            class_67::method_591(class_84::field_1116->method_4(3), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 2) * this->field_557));
            class_67::method_584(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(6); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u"    "); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(int32_t(class_1::field_4->at(this->field_576))); return jrt::concat(__c1, __c2, __c3); }()), class_51::field_552, (class_51::field_553 + 12), class_51::field_554, this->deep3dRow(0));
            class_67::method_584(([&]() { jrt::Ref<java::lang::String> __c4 = class_84::field_1116->method_4(10); jrt::Ref<java::lang::String> __c5 = JRT_LIT(u"    "); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4((class_84::field_1081 ? 14 : 15)); return jrt::concat(__c4, __c5, __c6); }()), class_51::field_552, ((class_51::field_553 + 12) + this->field_557), class_51::field_554, this->deep3dRow(1));
            class_67::method_584(([&]() { jrt::Ref<java::lang::String> __c7 = class_84::field_1116->method_4(13); jrt::Ref<java::lang::String> __c8 = JRT_LIT(u"    "); jrt::Ref<java::lang::String> __c9 = class_84::field_1116->method_4((class_84::field_1082 ? 14 : 15)); return jrt::concat(__c7, __c8, __c9); }()), class_51::field_552, ((class_51::field_553 + 12) + (2 * this->field_557)), class_51::field_554, this->deep3dRow(2));
            break;
        case 4:
            class_67::method_591(class_84::field_1116->method_4(4), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 2) * this->field_557));
            class_67::method_584(class_84::field_1116->method_4(18), class_51::field_552, (class_51::field_553 + 12), class_51::field_554, this->deep3dRow(0));
            class_67::method_584(class_84::field_1116->method_4(19), class_51::field_552, ((class_51::field_553 + 12) + this->field_557), class_51::field_554, this->deep3dRow(1));
            class_67::method_584(class_84::field_1116->method_4(20), class_51::field_552, ((class_51::field_553 + 12) + (2 * this->field_557)), class_51::field_554, this->deep3dRow(2));
            break;
        case 5:
            class_67::method_591(class_84::field_1116->method_4(16), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 2) * this->field_557));
            class_67::method_584(class_84::field_1116->method_4(3), class_51::field_552, (class_51::field_553 + 12), class_51::field_554, this->deep3dRow(0));
            class_67::method_584(class_84::field_1116->method_4(4), class_51::field_552, ((class_51::field_553 + 12) + this->field_557), class_51::field_554, this->deep3dRow(1));
            class_67::method_584(class_84::field_1116->method_4(75), class_51::field_552, ((class_51::field_553 + 12) + (2 * this->field_557)), class_51::field_554, this->deep3dRow(2));
            class_67::method_584(class_84::field_1116->method_4(266), class_51::field_552, ((class_51::field_553 + 12) + (3 * this->field_557)), class_51::field_554, this->deep3dRow(3));
            class_67::method_584(class_84::field_1116->method_4(5), class_51::field_552, ((class_51::field_553 + 12) + (4 * this->field_557)), class_51::field_554, this->deep3dRow(4));
            break;
        case 6:
            class_67::method_591(class_84::field_1116->method_4(18), class_51::field_552, class_51::field_553, class_51::field_554, (((class_84::field_1121 - class_51::field_553) - class_67::method_577()) - 10));
            this->field_567->method_712();
            this->field_567->method_709();
            break;
        case 7:
            class_67::method_591(class_84::field_1116->method_4(19), class_51::field_552, class_51::field_553, class_51::field_554, ((8 * this->field_557) + 3));
            class_58::method_518(class_84::field_1116->method_4(21), (class_51::field_552 + 10), (class_51::field_553 + 12), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"5")), ((class_51::field_552 + class_51::field_554) - 10), (class_51::field_553 + 12), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(12), (class_51::field_552 + 10), ((class_51::field_553 + 12) + this->field_557), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"7")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + this->field_557), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(22), (class_51::field_552 + 10), ((class_51::field_553 + 12) + (2 * this->field_557)), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"1")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + (2 * this->field_557)), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(323), (class_51::field_552 + 10), ((class_51::field_553 + 12) + (3 * this->field_557)), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"9")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + (3 * this->field_557)), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(137), (class_51::field_552 + 10), ((class_51::field_553 + 12) + (4 * this->field_557)), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"3")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + (4 * this->field_557)), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(23), (class_51::field_552 + 10), ((class_51::field_553 + 12) + (5 * this->field_557)), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"*,0,#")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + (5 * this->field_557)), 1, 2);
            class_58::method_518(class_84::field_1116->method_4(24), (class_51::field_552 + 10), ((class_51::field_553 + 12) + (6 * this->field_557)), 0);
            class_58::method_516(org::deep3d::GameUi::phoneKeysName(JRT_LIT(u"0")), ((class_51::field_552 + class_51::field_554) - 10), ((class_51::field_553 + 12) + (6 * this->field_557)), 1, 2);
            break;
        case 8:
            class_67::method_591(class_84::field_1116->method_4(20), class_51::field_552, class_51::field_553, class_51::field_554, (((class_84::field_1121 - class_51::field_553) - class_67::method_577()) - 10));
            class_58::method_518(class_84::field_1124, ((class_84::field_1120 >> 1) - (class_58::method_523(class_84::field_1124) >> 1)), ((10 + this->field_556->getHeight()) + 2), 1);
            this->field_568->method_231();
            break;
        case 9:
            class_67::method_591(class_84::field_1116->method_4(0), class_51::field_552, class_51::field_553, class_51::field_554, ((class_51::field_555->at(this->field_560) + 2) * this->field_557));
            class_67::method_584(class_84::field_1116->method_4(232), class_51::field_552, (class_51::field_553 + 12), class_51::field_554, this->deep3dRow(0));
            class_67::method_584(class_84::field_1116->method_4(231), class_51::field_552, ((class_51::field_553 + 12) + this->field_557), class_51::field_554, this->deep3dRow(1));
        case 10:
            ;
        default:
            break;
        case 11:
            class_67::method_592(class_84::field_1116->method_4(38), class_51::field_552, class_51::field_553, class_51::field_554, (4 * this->field_557), true);
            class_58::method_518(jrt::concat(class_84::field_1116->method_4(299), JRT_LIT(u":")), (class_51::field_552 + 10), (class_51::field_553 + 12), 1);
            this->field_571->method_290(this->field_572);
            class_58::method_518(jrt::concat(this->field_571->field_327, this->field_571->field_326), (class_51::field_552 + 10), ((class_51::field_553 + 12) + this->field_557), 0);
            if (class_67::method_581()) {
                class_58::method_518(JRT_LIT(u"_"), ((class_51::field_552 + 10) + class_58::method_523(this->field_571->field_327)), (((class_51::field_553 + 12) + 2) + this->field_557), 0);
            }
            break;
        case 12:
            var1 = ((class_84::field_1121 <= 176) ? 10 : class_51::field_553);
            class_67::method_592(class_84::field_1116->method_4(300), class_51::field_552, var1, class_51::field_554, (11 * this->field_557), true);
            class_58::method_516(jrt::concat(class_84::field_1116->method_4(301), JRT_LIT(u":")), (class_51::field_552 + (class_51::field_554 >> 1)), (var1 + 12), 1, 24);
            class_84::field_1117->setColor(class_67::field_844);
            class_84::field_1117->drawRect(((class_51::field_552 + (class_51::field_554 >> 1)) - (class_119::field_1458 >> 1)), (((var1 + 11) + this->field_557) + 6), (class_119::field_1458 + 1), (class_119::field_1459 + 1));
            if (class_51::field_577) {
                class_119::method_923(this->field_573, ((class_51::field_552 + (class_51::field_554 >> 1)) + 1), (((var1 + 12) + this->field_557) + 6), 17);
            } else if ((this->field_574 != nullptr) && (this->field_574->field_592 != nullptr)) {
                class_84::field_1117->drawImage(this->field_574->field_592, ((class_51::field_552 + (class_51::field_554 >> 1)) + 1), (((var1 + 12) + this->field_557) + 6), 17);
            }
            class_67::method_586(class_84::field_1116->method_4(302), class_51::field_552, ((((var1 + 12) + (2 * this->field_557)) + 6) + class_119::field_1459), class_51::field_554, this->deep3dRow(0), true);
            if (this->field_574 != nullptr) {
                class_67::method_586(class_84::field_1116->method_4(303), class_51::field_552, ((((var1 + 12) + (3 * this->field_557)) + 6) + class_119::field_1459), class_51::field_554, this->deep3dRow(1), true);
                class_67::method_586(class_84::field_1116->method_4(74), class_51::field_552, ((((var1 + 12) + (4 * this->field_557)) + 6) + class_119::field_1459), class_51::field_554, this->deep3dRow(2), true);
            } else {
                class_67::method_586(class_84::field_1116->method_4(74), class_51::field_552, ((((var1 + 12) + (3 * this->field_557)) + 6) + class_119::field_1459), class_51::field_554, this->deep3dRow(1), true);
            }
            break;
        case 13:
            class_67::method_591(class_84::field_1116->method_4(75), class_51::field_552, class_51::field_553, class_51::field_554, (((class_84::field_1121 - class_51::field_553) - class_67::method_577()) - 10));
            this->field_570->method_231();
            break;
        case 14:
            this->field_575->method_718();
            break;
        case 15:
            ;
        case 16:
            ;
        case 17:
            ;
        case 18:
            ;
        case 19:
            ;
        case 20:
            ;
        case 21:
            ;
        case 22:
            ;
        case 23:
            ;
        case 24:
            class_67::method_591(class_84::field_1116->method_4(int32_t(class_1::field_1->at(this->field_559))), class_51::field_552, class_51::field_553, class_51::field_554, (((class_84::field_1121 - class_51::field_553) - class_67::method_577()) - 10));
            this->field_569->method_231();
        }
    }
    if (this->field_563) {
        this->field_562->method_944();
        class_67::method_601(JRT_LIT(u""), JRT_LIT(u""), false);
    } else if (this->field_560 == 0) {
        [&]() { jrt::Ref<java::lang::String> __a10 = class_84::field_1116->method_4(265); jrt::Ref<java::lang::String> __a11 = ((class_21::method_212() == int64_t(0)) ? JRT_LIT(u"") : class_84::field_1116->method_4(65)); bool __a12 = false; return class_67::method_601(__a10, __a11, __a12); }();
    } else if (this->field_560 == 5) {
        [&]() { jrt::Ref<java::lang::String> __a13 = class_84::field_1116->method_4(265); jrt::Ref<java::lang::String> __a14 = class_84::field_1116->method_4(17); bool __a15 = false; return class_67::method_601(__a13, __a14, __a15); }();
    } else if (this->field_560 == 11) {
        if (this->field_571->field_327->length() > 0) {
            [&]() { jrt::Ref<java::lang::String> __a16 = class_84::field_1116->method_4(74); jrt::Ref<java::lang::String> __a17 = class_84::field_1116->method_4(304); bool __a18 = false; return class_67::method_601(__a16, __a17, __a18); }();
        } else {
            class_67::method_601(JRT_LIT(u""), class_84::field_1116->method_4(65), false);
        }
    } else if (((((this->field_560 == 7) || (this->field_560 == 8)) || (this->field_560 == 14)) || (this->field_560 == 13)) || ((this->field_560 >= 15) && (this->field_560 <= 24))) {
        class_67::method_601(JRT_LIT(u""), class_84::field_1116->method_4(65), false);
    } else {
        [&]() { jrt::Ref<java::lang::String> __a19 = class_84::field_1116->method_4(41); jrt::Ref<java::lang::String> __a20 = class_84::field_1116->method_4(65); bool __a21 = false; return class_67::method_601(__a19, __a20, __a21); }();
    }
}

void class_51::method_430(int32_t var1) {
    if (this->field_560 == 11) {
        if ((var1 == 8192) && (this->field_571->field_327->length() == 0)) {
            this->field_559 = 0;
            this->field_560 = 9;
        }
        if ((var1 != 0) && (var1 != (-1))) {
            this->field_571->method_291(var1);
        }
    }
}

void class_51::__dumpFields(jrt::Dumper& d) {
    d.f("field_556", this->field_556);
    d.f("field_557", this->field_557);
    d.f("field_558", this->field_558);
    d.f("field_559", this->field_559);
    d.f("field_560", this->field_560);
    d.f("field_561", this->field_561);
    d.f("field_562", this->field_562);
    d.f("field_563", this->field_563);
    d.f("field_564", this->field_564);
    d.f("field_565", this->field_565);
    d.f("field_566", this->field_566);
    d.f("field_567", this->field_567);
    d.f("field_568", this->field_568);
    d.f("field_569", this->field_569);
    d.f("field_570", this->field_570);
    d.f("field_571", this->field_571);
    d.f("field_572", this->field_572);
    d.f("field_573", this->field_573);
    d.f("field_574", this->field_574);
    d.f("field_575", this->field_575);
    d.f("field_576", this->field_576);
    d.f("field_578", this->field_578);
    d.f("field_579", this->field_579);
    d.f("field_580", this->field_580);
    d.f("field_581", this->field_581);
    d.f("field_582", this->field_582);
}


void class_51__anon1::__clinit() {
}

void class_51__anon1::__init() {
}

bool class_51__anon1::get() {
    return class_84::field_1082;
}

void class_51__anon1::set(bool var1) {
    class_84::field_1082 = var1;
    class_27::method_275();
}

void class_51__anon1::__dumpFields(jrt::Dumper& d) {
}


void class_51__anon2::__clinit() {
}

void class_51__anon2::__init() {
}

bool class_51__anon2::get() {
    return class_84::field_1082;
}

void class_51__anon2::set(bool var1) {
    class_84::field_1082 = var1;
    class_27::method_275();
}

void class_51__anon2::__dumpFields(jrt::Dumper& d) {
}

