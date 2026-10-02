// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<javax::microedition::rms::RecordStore> class_27::field_303{};

void class_27::__clinit() {
    class_27::field_303 = jrt::Ref<javax::microedition::rms::RecordStore>(nullptr);
}

void class_27::__init() {
}

jrt::Ref<jrt::Array<jrt::Ref<class_41>>> class_27::method_272() {
    jrt::Ref<jrt::Array<jrt::Ref<class_41>>> var0 = jrt::newArray<jrt::Ref<class_41>>(4);
    for (int32_t var1 = 0; var1 < var0->length; var1++) {
        var0->at(var1) = class_27::method_276(var1);
    }
    return var0;
}

jrt::Ref<class_41> class_27::method_273(int32_t var0) {
    jrt::New<class_41>();
    jrt::Ref<java::lang::Object> var1 = jrt::Ref<java::lang::Object>(nullptr);
    return class_27::method_276(var0);
}

void class_27::method_274() {
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(JRT_LIT(u"Deep_Options"), false);
            class_27::field_303->closeRecordStore();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex1.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var5 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(JRT_LIT(u"Deep_Options"), false);
            jrt::Ref<jrt::Array<int8_t>> var0 = class_27::field_303->getRecord((class_27::field_303->getNextRecordID() - 1));
            jrt::Ref<java::io::ByteArrayInputStream> var1 = jrt::New<java::io::ByteArrayInputStream>(var0);
            jrt::Ref<java::io::DataInputStream> var2{};
            class_84::field_1080 = (var2 = jrt::New<java::io::DataInputStream>(jrt::Ref<java::io::InputStream>(var1)))->readBoolean();
            class_84::field_1081 = var2->readBoolean();
            class_84::field_1082 = var2->readBoolean();
            class_84::field_1083 = var2->readInt();
            var2->close();
            var1->close();
            class_27::field_303->closeRecordStore();
            class_27::field_303 = jrt::Ref<javax::microedition::rms::RecordStore>(nullptr);
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex2.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var3 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex2.t);
            } else if (jrt::isInstance<java::io::IOException>(__ex2.t)) {
                jrt::Ref<java::io::IOException> var4 = jrt::cast<java::io::IOException>(__ex2.t);
            } else {
                throw;
            }
        }
    }
}

void class_27::method_275() {
    {
        try {
            javax::microedition::rms::RecordStore::deleteRecordStore(JRT_LIT(u"Deep_Options"));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex1.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var6 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(JRT_LIT(u"Deep_Options"), true);
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex2.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var5 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex2.t);
            } else {
                throw;
            }
        }
    }
    jrt::Ref<java::io::ByteArrayOutputStream> var0 = jrt::Ref<java::io::ByteArrayOutputStream>(nullptr);
    jrt::Ref<java::io::DataOutputStream> var1 = jrt::Ref<java::io::DataOutputStream>(nullptr);
    {
        try {
            var0 = jrt::New<java::io::ByteArrayOutputStream>();
            (var1 = jrt::New<java::io::DataOutputStream>(jrt::Ref<java::io::OutputStream>(var0)))->writeBoolean(class_84::field_1080);
            var1->writeBoolean(class_84::field_1081);
            var1->writeBoolean(class_84::field_1082);
            var1->writeInt(class_84::field_1083);
            var1->close();
            var0->close();
            [&]() { auto __r = class_27::field_303; jrt::Ref<jrt::Array<int8_t>> __a3 = var0->toByteArray(); int32_t __a4 = 0; int32_t __a5 = var0->toByteArray()->length; return __r->addRecord(__a3, __a4, __a5); }();
            class_27::field_303->closeRecordStore();
            class_27::field_303 = jrt::Ref<javax::microedition::rms::RecordStore>(nullptr);
        } catch (const jrt::Thrown& __ex6) {
            if (jrt::isInstance<java::io::IOException>(__ex6.t)) {
                jrt::Ref<java::io::IOException> var3 = jrt::cast<java::io::IOException>(__ex6.t);
            } else if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex6.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var4 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex6.t);
                var4->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<class_41> class_27::method_276(int32_t var0) {
    jrt::Ref<class_41> var1 = jrt::Ref<class_41>(nullptr);
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(jrt::concat(JRT_LIT(u"Deep_"), var0), false);
            class_27::field_303->closeRecordStore();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex1.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var22 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(jrt::concat(JRT_LIT(u"Deep_"), var0), false);
            jrt::Ref<jrt::Array<int8_t>> var2 = class_27::field_303->getRecord((class_27::field_303->getNextRecordID() - 1));
            jrt::Ref<java::io::ByteArrayInputStream> var3 = jrt::New<java::io::ByteArrayInputStream>(var2);
            jrt::Ref<java::io::DataInputStream> var4 = jrt::New<java::io::DataInputStream>(jrt::Ref<java::io::InputStream>(var3));
            var1 = jrt::New<class_41>();
            for (int32_t var5 = 0; var5 < var1->field_394->length; var5++) {
                var1->field_394->at(var5) = var4->readBoolean();
            }
            var1->field_395 = var4->readInt();
            var1->field_396 = var4->readInt();
            var1->field_397 = var4->readLong();
            var1->field_398 = var4->readInt();
            var1->field_399 = var4->readInt();
            var1->field_410 = var4->readInt();
            var1->field_411 = var4->readInt();
            var1->field_400 = var4->readInt();
            var1->field_401 = var4->readInt();
            var1->field_402 = var4->readInt();
            var1->field_403 = var4->readInt();
            var1->field_409 = var4->readInt();
            var1->field_414 = var4->readInt();
            var1->field_415 = class_27::method_279(var4);
            var1->field_416 = class_27::method_279(var4);
            var1->field_417 = var4->readUTF();
            var1->field_405 = var4->readInt();
            var1->field_406 = var4->readInt();
            var1->field_407 = var4->readInt();
            var1->field_408 = var4->readInt();
            var1->field_404 = var4->readInt();
            var1->field_413 = var4->readInt();
            var1->field_412 = var4->readInt();
            var1->field_422 = jrt::newArray<bool>(class_21::method_195()->length);
            for (int32_t var24 = 0; var24 < var1->field_422->length; var24++) {
                var1->field_422->at(var24) = var4->readBoolean();
            }
            var1->field_426 = jrt::newArray<int32_t>(class_14::field_135->length);
            for (int32_t var25 = 0; var25 < var1->field_426->length; var25++) {
                var1->field_426->at(var25) = var4->readInt();
            }
            if (var4->readBoolean()) {
                jrt::Ref<jrt::Array<int8_t>> var27 = jrt::newArray<int8_t>(int32_t(class_119::field_1457));
                for (int32_t var29 = 0; var29 < int32_t(class_119::field_1457); var29++) {
                    var27->at(var29) = var4->readByte();
                }
                var1->field_418 = var27;
            } else {
                jrt::Ref<jrt::Array<int32_t>> var26 = jrt::newArray<int32_t>(var4->readInt());
                for (int32_t var6 = 0; var6 < var26->length; var6++) {
                    var26->at(var6) = var4->readInt();
                }
                var1->field_419 = javax::microedition::lcdui::Image::createRGBImage(var26, class_119::field_1458, class_119::field_1459, false);
            }
            jrt::Ref<jrt::Array<bool>> var28 = jrt::newArray<bool>(200);
            for (int32_t var30 = 0; var30 < var28->length; var30++) {
                var28->at(var30) = var4->readBoolean();
            }
            var1->field_420 = var28;
            jrt::Ref<jrt::Array<bool>> var31 = jrt::newArray<bool>(class_21::method_168()->length);
            for (int32_t var7 = 0; var7 < var31->length; var7++) {
                var31->at(var7) = var4->readBoolean();
            }
            var1->field_421 = var31;
            var1->field_450 = class_90::method_783()->at(var4->readInt())->method_627();
            var1->field_450->field_884 = var4->readBoolean();
            var1->field_450->method_628();
            int32_t var32 = var4->readInt();
            jrt::Ref<java::lang::Object> var8 = jrt::Ref<java::lang::Object>(nullptr);
            if (var32 > 0) {
                var8 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_19>>(var32));
                for (int32_t var9 = 0; var9 < var32; var9++) {
                    int32_t var10{};
                    if ((var10 = var4->readInt()) == (-1)) {
                        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->at(var9) = jrt::Ref<java::lang::Object>(nullptr);
                    } else {
                        (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->at(var9) = jrt::Ref<java::lang::Object>(class_90::method_781()->at(var10)->method_119(1, class_90::method_781()->at(var10)->field_170));
                        (jrt::cast<class_19>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var8))->at(var9)))->method_124();
                    }
                }
                var1->field_450->method_615(jrt::cast<jrt::Array<jrt::Ref<class_19>>>(var8));
            }
            int32_t var35 = var4->readInt();
            jrt::Ref<java::lang::Object> var37 = jrt::Ref<java::lang::Object>(nullptr);
            if (var35 > 0) {
                var37 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_120>>(var35));
                for (int32_t var11 = 0; var11 < var35; var11++) {
                    int32_t var12 = var4->readInt();
                    int32_t var13 = var4->readInt();
                    int32_t var14 = var4->readInt();
                    (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var37))->at(var11) = jrt::Ref<java::lang::Object>(class_90::method_785()->at(var12)->method_930(var13, class_90::method_785()->at(var12)->field_1487));
                    (jrt::cast<class_120>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var37))->at(var11)))->field_1484 = var14;
                }
                var1->field_450->method_608(jrt::cast<jrt::Array<jrt::Ref<class_120>>>(var37));
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_86>>> var39 = jrt::newArray<jrt::Ref<class_86>>(3);
            for (int32_t var40 = 0; var40 < (var39->length + 1); var40++) {
                jrt::Ref<class_86> var42 = jrt::Ref<class_86>(nullptr);
                int16_t var45{};
                if (int32_t((var45 = var4->readShort())) == (-1)) {
                    var42 = jrt::Ref<class_86>(nullptr);
                } else {
                    var42 = class_38::method_354(int32_t(var45));
                    var32 = var4->readInt();
                    jrt::Ref<java::lang::Object> var15 = jrt::Ref<java::lang::Object>(nullptr);
                    if (var32 > 0) {
                        var15 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_19>>(var32));
                        for (int32_t var16 = 0; var16 < var32; var16++) {
                            int32_t var17 = var4->readInt();
                            int32_t var18 = var4->readInt();
                            bool var19 = var4->readBoolean();
                            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var15))->at(var16) = jrt::Ref<java::lang::Object>(class_90::method_781()->at(var17)->method_119(var18, class_90::method_781()->at(var17)->field_170));
                            if (var19) {
                                (jrt::cast<class_19>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var15))->at(var16)))->method_124();
                                (jrt::cast<class_19>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var15))->at(var16)))->field_176 = true;
                            }
                        }
                        var42->field_1141 = jrt::cast<jrt::Array<jrt::Ref<class_19>>>(var15);
                    }
                    var35 = var4->readInt();
                    jrt::Ref<java::lang::Object> var47 = jrt::Ref<java::lang::Object>(nullptr);
                    if (var35 > 0) {
                        var47 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_120>>(var35));
                        for (int32_t var49 = 0; var49 < var35; var49++) {
                            int32_t var51 = var4->readInt();
                            int32_t var54 = var4->readInt();
                            int32_t var20 = var4->readInt();
                            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var47))->at(var49) = jrt::Ref<java::lang::Object>(class_90::method_785()->at(var51)->method_930(var54, class_90::method_785()->at(var51)->field_1487));
                            (jrt::cast<class_120>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var47))->at(var49)))->field_1484 = var20;
                        }
                        var42->field_1142 = jrt::cast<jrt::Array<jrt::Ref<class_120>>>(var47);
                    }
                    int32_t var50 = var4->readInt();
                    jrt::Ref<java::lang::Object> var52 = jrt::Ref<java::lang::Object>(nullptr);
                    if (var50 > 0) {
                        var52 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_68>>(var50));
                        for (int32_t var55 = 0; var55 < var50; var55++) {
                            int32_t var57 = var4->readInt();
                            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var52))->at(var55) = jrt::Ref<java::lang::Object>(class_90::method_783()->at(var57)->method_627());
                            (jrt::cast<class_68>((jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var52))->at(var55)))->field_884 = var4->readBoolean();
                        }
                        var42->field_1143 = jrt::cast<jrt::Array<jrt::Ref<class_68>>>(var52);
                    }
                    int32_t var56 = var4->readInt();
                    jrt::Ref<java::lang::Object> var58 = jrt::Ref<java::lang::Object>(nullptr);
                    if (var56 > 0) {
                        var58 = jrt::Ref<java::lang::Object>(jrt::newArray<jrt::Ref<class_87>>(var56));
                        for (int32_t var21 = 0; var21 < var56; var21++) {
                            (jrt::cast<jrt::Array<jrt::Ref<java::lang::Object>>>(var58))->at(var21) = jrt::Ref<java::lang::Object>(class_27::method_279(var4));
                        }
                        var42->field_1144 = jrt::cast<jrt::Array<jrt::Ref<class_87>>>(var58);
                    }
                }
                if (var40 == var39->length) {
                    var1->field_451 = var42;
                } else {
                    var39->at(var40) = var42;
                }
            }
            var1->field_423 = var39;
            int32_t var41{};
            if ((var41 = var4->readInt()) > 0) {
                var1->field_424 = jrt::newArray<int32_t>(var41);
                for (int32_t var44 = 0; var44 < var41; var44++) {
                    var1->field_424->at(var44) = var4->readInt();
                }
            }
            var1->field_425 = var4->readInt();
            var1->field_427 = var4->readBoolean();
            var1->field_428 = var4->readBoolean();
            var1->field_429 = var4->readBoolean();
            var1->field_430 = var4->readBoolean();
            var1->field_431 = var4->readBoolean();
            var1->field_432 = var4->readBoolean();
            var1->field_433 = var4->readBoolean();
            var1->field_434 = var4->readBoolean();
            var1->field_435 = var4->readBoolean();
            var1->field_436 = var4->readBoolean();
            var1->field_437 = var4->readBoolean();
            var1->field_438 = var4->readBoolean();
            var1->field_439 = var4->readBoolean();
            var1->field_440 = var4->readBoolean();
            var1->field_441 = var4->readBoolean();
            var1->field_442 = var4->readBoolean();
            var1->field_443 = var4->readBoolean();
            var1->field_444 = var4->readBoolean();
            var1->field_445 = var4->readBoolean();
            var1->field_446 = var4->readBoolean();
            var1->field_447 = var4->readBoolean();
            var1->field_448 = var4->readBoolean();
            var1->field_449 = var4->readBoolean();
            var4->close();
            var3->close();
            class_27::field_303->closeRecordStore();
            class_27::field_303 = jrt::Ref<javax::microedition::rms::RecordStore>(nullptr);
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> var23 = jrt::cast<java::lang::Exception>(__ex2.t);
            } else {
                throw;
            }
        }
    }
    return var1;
}

void class_27::method_277(int32_t var0) {
    {
        try {
            javax::microedition::rms::RecordStore::deleteRecordStore(jrt::concat(JRT_LIT(u"Deep_"), var0));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex1.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var16 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
    {
        try {
            class_27::field_303 = javax::microedition::rms::RecordStore::openRecordStore(jrt::concat(JRT_LIT(u"Deep_"), var0), true);
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex2.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var15 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex2.t);
            } else {
                throw;
            }
        }
    }
    jrt::Ref<java::io::ByteArrayOutputStream> var1 = jrt::Ref<java::io::ByteArrayOutputStream>(nullptr);
    jrt::Ref<java::io::DataOutputStream> var2 = jrt::Ref<java::io::DataOutputStream>(nullptr);
    {
        try {
            var1 = jrt::New<java::io::ByteArrayOutputStream>();
            var2 = jrt::New<java::io::DataOutputStream>(jrt::Ref<java::io::OutputStream>(var1));
            jrt::Ref<jrt::Array<bool>> var3 = class_38::method_356();
            for (int32_t var4 = 0; var4 < var3->length; var4++) {
                var2->writeBoolean(var3->at(var4));
            }
            var2->writeInt(class_21::method_182());
            var2->writeInt(class_21::method_200());
            var2->writeLong(class_21::method_212());
            var2->writeInt(class_21::method_202());
            var2->writeInt(class_21::method_208());
            var2->writeInt(class_21::method_170());
            var2->writeInt(class_21::method_172());
            var2->writeInt(class_21::method_209());
            var2->writeInt(class_21::method_210());
            var2->writeInt(class_21::method_201());
            var2->writeInt(class_21::method_191());
            var2->writeInt(class_21::method_177());
            var2->writeInt(class_21::method_143());
            class_27::method_278(var2, class_21::method_135());
            class_27::method_278(var2, class_21::method_137());
            var2->writeUTF(class_21::method_213());
            var2->writeInt(class_21::method_156());
            var2->writeInt(class_21::method_151());
            var2->writeInt(class_21::method_154());
            var2->writeInt(class_21::method_158());
            var2->writeInt(class_21::method_205());
            var2->writeInt(class_21::method_160());
            var2->writeInt(class_21::method_159());
            jrt::Ref<jrt::Array<bool>> var21 = class_21::method_195();
            for (int32_t var5 = 0; var5 < var21->length; var5++) {
                var2->writeBoolean(var21->at(var5));
            }
            jrt::Ref<jrt::Array<int32_t>> var22 = class_14::method_71();
            for (int32_t var6 = 0; var6 < var22->length; var6++) {
                var2->writeInt(var22->at(var6));
            }
            var2->writeBoolean((class_21::method_215() != nullptr));
            if (class_21::method_215() != nullptr) {
                for (int32_t var23 = 0; var23 < int32_t(class_119::field_1457); var23++) {
                    var2->writeByte(int32_t(class_21::method_215()->at(var23)));
                }
            } else {
                jrt::Ref<jrt::Array<int32_t>> var24 = jrt::newArray<int32_t>(([&]() { int32_t __l3 = class_21::method_217()->getWidth(); int32_t __r3 = class_21::method_217()->getHeight(); return (__l3 * __r3); }()));
                [&]() { auto __r = class_21::method_217(); jrt::Ref<jrt::Array<int32_t>> __a4 = var24; int32_t __a5 = 0; int32_t __a6 = class_21::method_217()->getWidth(); int32_t __a7 = 0; int32_t __a8 = 0; int32_t __a9 = class_21::method_217()->getWidth(); int32_t __a10 = class_21::method_217()->getHeight(); return __r->getRGB(__a4, __a5, __a6, __a7, __a8, __a9, __a10); }();
                var2->writeInt(var24->length);
                for (int32_t var7 = 0; var7 < var24->length; var7++) {
                    var2->writeInt(var24->at(var7));
                }
            }
            jrt::Ref<jrt::Array<bool>> var25 = class_21::method_175();
            for (int32_t var26 = 0; var26 < var25->length; var26++) {
                var2->writeBoolean(var25->at(var26));
            }
            jrt::Ref<jrt::Array<bool>> var27 = class_21::method_168();
            for (int32_t var8 = 0; var8 < var27->length; var8++) {
                var2->writeBoolean(var27->at(var8));
            }
            var2->writeInt(class_21::method_178()->field_863);
            var2->writeBoolean(class_21::method_178()->field_884);
            jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var28{};
            if ((var28 = class_21::method_178()->field_885) == nullptr) {
                var2->writeInt(0);
            } else {
                var2->writeInt(var28->length);
                for (int32_t var9 = 0; var9 < var28->length; var9++) {
                    if (var28->at(var9) != nullptr) {
                        var2->writeInt(var28->at(var9)->field_166);
                    } else {
                        var2->writeInt((-1));
                    }
                }
            }
            jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var30{};
            if ((var30 = class_21::method_178()->field_886) == nullptr) {
                var2->writeInt(0);
            } else {
                var2->writeInt(var30->length);
                for (int32_t var10 = 0; var10 < var30->length; var10++) {
                    var2->writeInt(var30->at(var10)->field_1480);
                    var2->writeInt(var30->at(var10)->field_1490);
                    var2->writeInt(var30->at(var10)->field_1484);
                }
            }
            for (int32_t var32 = 0; var32 < (class_21::method_127()->length + 1); var32++) {
                jrt::Ref<class_86> var11 = jrt::Ref<class_86>(nullptr);
                if (var32 == class_21::method_127()->length) {
                    var11 = class_21::method_180();
                } else {
                    var11 = class_21::method_127()->at(var32);
                }
                if (var11 == nullptr) {
                    var2->writeShort((-1));
                } else {
                    var2->writeShort(var11->field_1134);
                    var28 = var11->field_1141;
                    if (var11->field_1141 == nullptr) {
                        var2->writeInt(0);
                    } else {
                        var2->writeInt(var28->length);
                        for (int32_t var12 = 0; var12 < var28->length; var12++) {
                            var2->writeInt(var28->at(var12)->field_166);
                            var2->writeInt(var28->at(var12)->field_175);
                            var2->writeBoolean(var28->at(var12)->field_176);
                        }
                    }
                    var30 = var11->field_1142;
                    if (var11->field_1142 == nullptr) {
                        var2->writeInt(0);
                    } else {
                        var2->writeInt(var30->length);
                        for (int32_t var35 = 0; var35 < var30->length; var35++) {
                            var2->writeInt(var30->at(var35)->field_1480);
                            var2->writeInt(var30->at(var35)->field_1490);
                            var2->writeInt(var30->at(var35)->field_1484);
                        }
                    }
                    jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var36 = var11->field_1143;
                    if (var11->field_1143 == nullptr) {
                        var2->writeInt(0);
                    } else {
                        var2->writeInt(var36->length);
                        for (int32_t var13 = 0; var13 < var36->length; var13++) {
                            var2->writeInt(var36->at(var13)->field_863);
                            var2->writeBoolean(var36->at(var13)->field_884);
                        }
                    }
                    jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var37 = var11->field_1144;
                    if (var11->field_1144 == nullptr) {
                        var2->writeInt(0);
                    } else {
                        var2->writeInt(var37->length);
                        for (int32_t var14 = 0; var14 < var37->length; var14++) {
                            class_27::method_278(var2, var37->at(var14));
                        }
                    }
                }
            }
            if (class_84::field_1108 == nullptr) {
                var2->writeInt(0);
            } else {
                var2->writeInt(class_84::field_1108->length);
                for (int32_t var33 = 0; var33 < class_84::field_1108->length; var33++) {
                    var2->writeInt(class_84::field_1108->at(var33));
                }
            }
            var2->writeInt(class_84::field_1109);
            var2->writeBoolean(class_84::field_1085);
            var2->writeBoolean(class_84::field_1086);
            var2->writeBoolean(class_84::field_1087);
            var2->writeBoolean(class_84::field_1088);
            var2->writeBoolean(class_84::field_1089);
            var2->writeBoolean(class_84::field_1090);
            var2->writeBoolean(class_84::field_1091);
            var2->writeBoolean(class_84::field_1092);
            var2->writeBoolean(class_84::field_1093);
            var2->writeBoolean(class_84::field_1094);
            var2->writeBoolean(class_84::field_1095);
            var2->writeBoolean(class_84::field_1096);
            var2->writeBoolean(class_84::field_1097);
            var2->writeBoolean(class_84::field_1098);
            var2->writeBoolean(class_84::field_1099);
            var2->writeBoolean(class_84::field_1100);
            var2->writeBoolean(class_84::field_1101);
            var2->writeBoolean(class_84::field_1102);
            var2->writeBoolean(class_84::field_1104);
            var2->writeBoolean(class_84::field_1103);
            var2->writeBoolean(class_84::field_1105);
            var2->writeBoolean(class_84::field_1106);
            var2->writeBoolean(class_84::field_1107);
            var2->close();
            var1->close();
            [&]() { auto __r = class_27::field_303; jrt::Ref<jrt::Array<int8_t>> __a11 = var1->toByteArray(); int32_t __a12 = 0; int32_t __a13 = var1->toByteArray()->length; return __r->addRecord(__a11, __a12, __a13); }();
            class_27::field_303->closeRecordStore();
            class_27::field_303 = jrt::Ref<javax::microedition::rms::RecordStore>(nullptr);
        } catch (const jrt::Thrown& __ex14) {
            if (jrt::isInstance<java::io::IOException>(__ex14.t)) {
                jrt::Ref<java::io::IOException> var17 = jrt::cast<java::io::IOException>(__ex14.t);
            } else if (jrt::isInstance<javax::microedition::rms::RecordStoreException>(__ex14.t)) {
                jrt::Ref<javax::microedition::rms::RecordStoreException> var18 = jrt::cast<javax::microedition::rms::RecordStoreException>(__ex14.t);
                var18->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_27::method_278(jrt::Ref<java::io::DataOutputStream> var0, jrt::Ref<class_87> var1) {
    var0->writeInt(var1->field_1146);
    if (!var1->method_754()) {
        var0->writeBoolean(var1->field_1161);
        if (!var1->field_1161) {
            var0->writeUTF(var1->field_1147);
            for (int32_t var2 = 0; var2 < int32_t(class_119::field_1457); var2++) {
                var0->writeByte(int32_t(var1->field_1148->at(var2)));
            }
        }
        var0->writeInt(var1->field_1149);
        var0->writeInt(var1->field_1151);
        var0->writeInt(var1->field_1150);
        var0->writeInt(var1->field_1152);
        var0->writeInt(var1->field_1154);
        var0->writeInt(var1->field_1156);
        var0->writeInt(var1->field_1155);
        var0->writeInt(var1->field_1167);
        var0->writeInt(var1->field_1166);
        var0->writeInt(var1->field_1168);
        var0->writeInt(var1->field_1165);
        var0->writeInt(var1->field_1164);
        var0->writeInt(var1->field_1170);
        var0->writeBoolean(var1->field_1171);
    }
}

jrt::Ref<class_87> class_27::method_279(jrt::Ref<java::io::DataInputStream> var0) {
    int32_t var1{};
    if ((var1 = var0->readInt()) == (-1)) {
        return class_87::field_1145;
    } else {
        bool var2 = var0->readBoolean();
        jrt::Ref<java::lang::String> var3 = JRT_LIT(u"");
        jrt::Ref<jrt::Array<int8_t>> var4 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
        if (!var2) {
            var3 = var0->readUTF();
            var4 = jrt::newArray<int8_t>(int32_t(class_119::field_1457));
            for (int32_t var5 = 0; var5 < int32_t(class_119::field_1457); var5++) {
                var4->at(var5) = var0->readByte();
            }
        }
        int32_t var20 = var0->readInt();
        int32_t var6 = var0->readInt();
        int32_t var7 = var0->readInt();
        int32_t var8 = var0->readInt();
        int32_t var9 = var0->readInt();
        int32_t var10 = var0->readInt();
        int32_t var11 = var0->readInt();
        int32_t var12 = var0->readInt();
        int32_t var13 = var0->readInt();
        int32_t var14 = var0->readInt();
        int32_t var15 = var0->readInt();
        int32_t var16 = var0->readInt();
        int32_t var17 = var0->readInt();
        bool var18 = var0->readBoolean();
        jrt::Ref<class_87> var19 = jrt::Ref<class_87>(nullptr);
        if (var2) {
            var19 = jrt::New<class_87>(var1, var7, var8);
        } else {
            var19 = jrt::New<class_87>(var1, var3, var4, var20, var7, var8, var9, var11);
        }
        var19->field_1151 = var6;
        var19->method_755(var13, var12, var14);
        var19->method_756(var16, var15);
        var19->field_1170 = var17;
        var19->field_1171 = var18;
        var19->method_761(var10);
        return var19;
    }
}

void class_27::__dumpFields(jrt::Dumper& d) {
}

