// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<java::io::InputStream> class_49::field_539{};
jrt::Ref<jrt::Array<int8_t>> class_49::field_540{};
jrt::Ref<java::lang::StringBuffer> class_49::field_541{};
char16_t class_49::field_542{};
jrt::Ref<jrt::Array<int8_t>> class_49::field_543{};
jrt::Ref<java::lang::String> class_49::field_544{};
jrt::Ref<java::lang::Class> class_49::field_545{};

void class_49::__clinit() {
}

void class_49::__init() {
}

void class_49::method_399(jrt::Ref<java::lang::String> var0) {
    if ((class_49::field_544 != var0) || (class_49::field_540 == nullptr)) {
        class_49::field_539 = jrt::getResourceAsStream(var0);
        class_49::field_540 = jrt::newArray<int8_t>(class_49::field_539->available());
        class_49::field_539->read(class_49::field_540, 0, class_49::field_539->available());
        class_49::field_539->close();
        class_49::field_544 = var0;
    }
}

jrt::Ref<class_86> class_49::method_400(int32_t var0) {
    return class_49::method_401(jrt::arrayOf<int16_t>({int16_t(var0)}))->at(0);
}

jrt::Ref<jrt::Array<jrt::Ref<class_86>>> class_49::method_401(jrt::Ref<jrt::Array<int16_t>> var0) {
    jrt::Ref<jrt::Array<jrt::Ref<class_86>>> var1 = jrt::newArray<jrt::Ref<class_86>>(var0->length);
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
        });
        try {
            class_49::method_399(JRT_LIT(u"/data/txt/stations.txt"));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            jrt::Ref<java::lang::String> var2 = JRT_LIT(u"");
            jrt::Ref<jrt::Array<int8_t>> var3 = jrt::newArray<int8_t>(4);
            int16_t var4 = int16_t(0);
            int16_t var5 = int16_t(0);
            int16_t var6 = int16_t(0);
            bool var7 = 0 == int32_t(var0->at(0));
            for (int32_t var8 = 0; var8 < class_49::field_540->length; var8++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var8));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        break;
                    case 44:
                        if (var7) {
                            if (int32_t(var4) == 0) {
                                var2 = class_49::field_541->toString();
                            } else {
                                var3->at((int32_t(var4) - 1)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                            }
                            var4++;
                        }
                        class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        break;
                    case 59:
                        if (var7) {
                            var3->at((int32_t(var4) - 1)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                            var4 = int16_t(0);
                            if (int32_t(var6) == int32_t(var0->at(int32_t(var5)))) {
                                if (int32_t(var3->at(3)) == 0) {
                                    var3->at(3) = int8_t((-10));
                                } else if (int32_t(var3->at(3)) == 100) {
                                    var3->at(3) = int8_t(115);
                                }
                                var1->at(int32_t((var5++))) = jrt::New<class_86>(var2, int32_t(var6), int32_t(var3->at(0)), int32_t(var3->at(1)), int32_t(var3->at(2)), int32_t(var3->at(3)));
                                if (int32_t(var5) >= var0->length) {
                                    return var1;
                                }
                            }
                        }
                        var6++;
                        if (var7) {
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        }
                        var7 = int32_t(var6) == int32_t(var0->at(int32_t(var5)));
                        break;
                    default:
                        if (var7) {
                            class_49::field_541->append(class_49::field_542);
                        }
                    }
                }
            }
            return var1;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var13 = jrt::cast<java::lang::Exception>(__ex1.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading stations!"));
                var13->printStackTrace();
                return var1;
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_40>>> class_49::method_402() {
    jrt::Ref<jrt::Array<jrt::Ref<class_40>>> var0 = jrt::newArray<jrt::Ref<class_40>>(class_90::field_1202->length);
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
            class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        });
        try {
            class_49::method_399(JRT_LIT(u"/data/txt/creatures.txt"));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            int32_t var1 = 0;
            int32_t var2 = 0;
            jrt::Ref<jrt::Array<int32_t>> var3 = jrt::newArray<int32_t>(3);
            for (int32_t var4 = 0; var4 < class_49::field_540->length; var4++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var4));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        break;
                    case 44:
                        var3->at(var2) = java::lang::Integer::parseInt(class_49::field_541->toString());
                        class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        var2++;
                        break;
                    case 59:
                        {
                            try {
                                var3->at(var2) = java::lang::Integer::parseInt(class_49::field_541->toString());
                                var0->at((var1++)) = jrt::New<class_40>(var3->at(0), var3->at(1), var3->at(2));
                                var2 = 0;
                                class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            } catch (const jrt::Thrown& __ex1) {
                                if (jrt::isInstance<java::lang::NumberFormatException>(__ex1.t)) {
                                    jrt::Ref<java::lang::NumberFormatException> var10 = jrt::cast<java::lang::NumberFormatException>(__ex1.t);
                                } else {
                                    throw;
                                }
                            }
                        }
                        class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        break;
                    default:
                        class_49::field_541->append(class_49::field_542);
                    }
                }
            }
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var11 = jrt::cast<java::lang::Exception>(__ex2.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading creatures!"));
                var11->printStackTrace();
            } else {
                throw;
            }
        }
    }
    return var0;
}

void class_49::method_403() {
    class_49::field_543 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
}

jrt::Ref<jrt::Array<int8_t>> class_49::method_404() {
    if (class_49::field_543 != nullptr) {
        return class_49::field_543;
    } else {
        class_49::field_543 = jrt::newArray<int8_t>(800);
        {
            jrt::Finally __finally([&]() {
                if (class_49::field_541 != nullptr) {
                    class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
                }
            });
            try {
                class_49::method_399(JRT_LIT(u"/data/txt/stations.txt"));
                class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                int32_t var0 = 0;
                for (int32_t var1 = 0; var1 < class_49::field_540->length; var1++) {
                    class_49::field_542 = char16_t(class_49::field_540->at(var1));
                    {
                        switch (int32_t(class_49::field_542)) {
                        case 9:
                            ;
                        case 10:
                            ;
                        case 13:
                            break;
                        case 44:
                            ;
                        case 59:
                            {
                                try {
                                    class_49::field_543->at(var0) = java::lang::Byte::parseByte(class_49::field_541->toString());
                                    if ((var0 % 4) == 0) {
                                        if (int32_t(class_49::field_543->at(var0)) == 0) {
                                            class_49::field_543->at(var0) = int8_t((-15));
                                        } else if (int32_t(class_49::field_543->at(var0)) == 100) {
                                            class_49::field_543->at(var0) = int8_t(115);
                                        }
                                    }
                                    var0++;
                                } catch (const jrt::Thrown& __ex1) {
                                    if (jrt::isInstance<java::lang::NumberFormatException>(__ex1.t)) {
                                        jrt::Ref<java::lang::NumberFormatException> var7 = jrt::cast<java::lang::NumberFormatException>(__ex1.t);
                                    } else {
                                        throw;
                                    }
                                }
                            }
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            break;
                        default:
                            class_49::field_541->append(class_49::field_542);
                        }
                    }
                }
            } catch (const jrt::Thrown& __ex2) {
                if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                    jrt::Ref<java::lang::Exception> var8 = jrt::cast<java::lang::Exception>(__ex2.t);
                    java::lang::System::out->println(JRT_LIT(u"Error loading stations!"));
                    var8->printStackTrace();
                } else {
                    throw;
                }
            }
        }
        return class_49::field_543;
    }
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_49::method_405() {
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
            class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        });
        try {
            class_49::method_399(JRT_LIT(u"/data/txt/goods.txt"));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            int32_t var0 = 0;
            for (int32_t var1 = 0; var1 < class_49::field_540->length; var1++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var1));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 59:
                        var0++;
                        break;
                    }
                }
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var17 = jrt::newArray<jrt::Ref<class_120>>(var0);
            jrt::Ref<jrt::Array<int8_t>> var2 = jrt::newArray<int8_t>(var0);
            jrt::Ref<jrt::Array<int8_t>> var3 = jrt::newArray<int8_t>(var0);
            int32_t var4 = 0;
            int32_t var5 = 0;
            int32_t var6 = 0;
            int32_t var7 = 0;
            jrt::Ref<jrt::Array<int32_t>> var8 = jrt::newArray<int32_t>(7);
            int32_t var9 = 0;
            while (var9 < class_49::field_540->length) {
                class_49::field_542 = char16_t(class_49::field_540->at(var9));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 11:
                        ;
                    case 12:
                        ;
                    default:
                        if (int32_t(class_49::field_542) == int32_t(u',')) {
                            if (var7 == 6) {
                                var8->at(var7) = java::lang::Integer::parseInt(class_49::field_541->toString());
                                var7 = 7;
                            } else if (var7 == 7) {
                                var2->at((var5++)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                                var7 = 8;
                            } else {
                                var8->at(var7) = java::lang::Integer::parseInt(class_49::field_541->toString());
                                var7++;
                            }
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        } else if (int32_t(class_49::field_542) == int32_t(u' ')) {
                            if (var7 == 7) {
                                var2->at((var5++)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                            } else if (var7 == 8) {
                                var3->at((var6++)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                            }
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        } else if (int32_t(class_49::field_542) == int32_t(u';')) {
                            if (var7 == 8) {
                                var3->at((var6++)) = java::lang::Byte::parseByte(class_49::field_541->toString());
                            } else {
                                var8->at(var7) = java::lang::Integer::parseInt(class_49::field_541->toString());
                            }
                            jrt::Ref<jrt::Array<int8_t>> var10 = jrt::newArray<int8_t>(var5);
                            jrt::Ref<jrt::Array<int8_t>> var11 = jrt::newArray<int8_t>(var6);
                            if ((var6 == 0) && (var5 == 0)) {
                                var10 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
                                var11 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
                            } else {
                                java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var2), 0, jrt::Ref<java::lang::Object>(var10), 0, var5);
                                java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(var3), 0, jrt::Ref<java::lang::Object>(var11), 0, var6);
                            }
                            var17->at((var4++)) = jrt::New<class_120>(var8->at(0), var8->at(1), var8->at(2), var8->at(3), var8->at(4), var8->at(5), var8->at(6), var10, var11);
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            var7 = 0;
                            var5 = 0;
                            var6 = 0;
                            var2 = jrt::newArray<int8_t>(var0);
                            var3 = jrt::newArray<int8_t>(var0);
                        } else {
                            class_49::field_541->append(class_49::field_542);
                        }
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        var9++;
                    }
                }
            }
            return var17;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var15 = jrt::cast<java::lang::Exception>(__ex1.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading cargo!"));
            } else {
                throw;
            }
        }
    }
    return jrt::Ref<jrt::Array<jrt::Ref<class_120>>>(nullptr);
}

jrt::Ref<jrt::Array<jrt::Ref<class_19>>> class_49::method_406() {
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
            class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        });
        try {
            class_49::method_399(JRT_LIT(u"/data/txt/equipment.txt"));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            int32_t var0 = 0;
            for (int32_t var1 = 0; var1 < class_49::field_540->length; var1++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var1));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 59:
                        var0++;
                        break;
                    }
                }
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var11 = jrt::newArray<jrt::Ref<class_19>>(var0);
            int32_t var2 = 0;
            int32_t var3 = 0;
            jrt::Ref<jrt::Array<int32_t>> var4 = jrt::newArray<int32_t>(9);
            int32_t var5 = 0;
            while (var5 < class_49::field_540->length) {
                class_49::field_542 = char16_t(class_49::field_540->at(var5));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 11:
                        ;
                    case 12:
                        ;
                    default:
                        if (int32_t(class_49::field_542) == int32_t(u',')) {
                            var4->at(var3) = java::lang::Integer::parseInt(class_49::field_541->toString());
                            var3++;
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        } else if (int32_t(class_49::field_542) == int32_t(u';')) {
                            var4->at(var3) = java::lang::Integer::parseInt(class_49::field_541->toString());
                            var11->at((var2++)) = jrt::New<class_19>(var4->at(0), var4->at(1), var4->at(2), var4->at(3), var4->at(4), var4->at(5), var4->at(6), var4->at(7), var4->at(8));
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            var3 = 0;
                        } else {
                            class_49::field_541->append(class_49::field_542);
                        }
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        var5++;
                    }
                }
            }
            return var11;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var9 = jrt::cast<java::lang::Exception>(__ex1.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading equipment!"));
            } else {
                throw;
            }
        }
    }
    return jrt::Ref<jrt::Array<jrt::Ref<class_19>>>(nullptr);
}

jrt::Ref<jrt::Array<jrt::Ref<class_68>>> class_49::method_407() {
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
            class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        });
        try {
            class_49::method_399(JRT_LIT(u"/data/txt/ships.txt"));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            int32_t var0 = 0;
            for (int32_t var1 = 0; var1 < class_49::field_540->length; var1++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var1));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 59:
                        var0++;
                        break;
                    }
                }
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var11 = jrt::newArray<jrt::Ref<class_68>>(var0);
            int32_t var2 = 0;
            int32_t var3 = 0;
            jrt::Ref<jrt::Array<int32_t>> var4 = jrt::newArray<int32_t>(6);
            int32_t var5 = 0;
            while (var5 < class_49::field_540->length) {
                class_49::field_542 = char16_t(class_49::field_540->at(var5));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 11:
                        ;
                    case 12:
                        ;
                    default:
                        if (int32_t(class_49::field_542) == int32_t(u',')) {
                            var4->at(var3) = java::lang::Integer::parseInt(class_49::field_541->toString());
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            var3++;
                        } else if (int32_t(class_49::field_542) == int32_t(u';')) {
                            var4->at(var3) = java::lang::Integer::parseInt(class_49::field_541->toString());
                            var11->at((var2++)) = jrt::New<class_68>(var4->at(0), var4->at(1), var4->at(2), var4->at(3), var4->at(4), (float(var4->at(5)) / 100.0f));
                            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                            var3 = 0;
                        } else {
                            class_49::field_541->append(class_49::field_542);
                        }
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        var5++;
                    }
                }
            }
            return var11;
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var9 = jrt::cast<java::lang::Exception>(__ex1.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading ships!"));
            } else {
                throw;
            }
        }
    }
    return jrt::Ref<jrt::Array<jrt::Ref<class_68>>>(nullptr);
}

jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_49::method_408(int32_t var0, bool var1) {
    jrt::Ref<java::lang::Object> var2 = jrt::Ref<java::lang::Object>(nullptr);
    if (var0 == 3) {
        var2 = jrt::Ref<java::lang::Object>(jrt::concat(class_84::field_1079->at(1), JRT_LIT(u"_"), (var1 ? JRT_LIT(u"m") : JRT_LIT(u"f")), JRT_LIT(u".txt")));
    } else {
        var2 = jrt::Ref<java::lang::Object>(jrt::concat(class_84::field_1079->at(0), JRT_LIT(u"_"), (var1 ? JRT_LIT(u"m") : JRT_LIT(u"f")), JRT_LIT(u".txt")));
    }
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var3 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
    {
        jrt::Finally __finally([&]() {
            if (class_49::field_541 != nullptr) {
                class_49::field_541 = jrt::Ref<java::lang::StringBuffer>(nullptr);
            }
            class_49::field_540 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        });
        try {
            class_49::method_399(jrt::cast<java::lang::String>(var2));
            class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
            int32_t var4 = 0;
            for (int32_t var5 = 0; var5 < class_49::field_540->length; var5++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var5));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 59:
                        var4++;
                        break;
                    }
                }
            }
            var3 = jrt::newArray<jrt::Ref<java::lang::String>>(var4);
            int32_t var13 = 0;
            for (int32_t var6 = 0; var6 < class_49::field_540->length; var6++) {
                class_49::field_542 = char16_t(class_49::field_540->at(var6));
                {
                    switch (int32_t(class_49::field_542)) {
                    case 9:
                        ;
                    case 10:
                        ;
                    case 13:
                        break;
                    case 59:
                        var3->at((var13++)) = class_49::field_541->toString();
                        class_49::field_541 = jrt::New<java::lang::StringBuffer>(30);
                        break;
                    default:
                        class_49::field_541->append(class_49::field_542);
                    }
                }
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var10 = jrt::cast<java::lang::Exception>(__ex1.t);
                java::lang::System::out->println(JRT_LIT(u"Error loading names!"));
            } else {
                throw;
            }
        }
    }
    return var3;
}

jrt::Ref<java::lang::Class> class_49::method_409(jrt::Ref<java::lang::String> var0) {
    {
        try {
            return java::lang::Class::forName(var0);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::ClassNotFoundException>(__ex1.t)) {
                jrt::Ref<java::lang::ClassNotFoundException> var2 = jrt::cast<java::lang::ClassNotFoundException>(__ex1.t);
                jrt::throwJava(jrt::New<java::lang::NoClassDefFoundError>(var2->getMessage()));
            } else {
                throw;
            }
        }
    }
}

void class_49::__dumpFields(jrt::Dumper& d) {
}

