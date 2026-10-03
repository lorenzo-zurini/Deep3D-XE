// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_124::__clinit() {
}

void class_124::__init(jrt::Ref<DeepMIDlet> var1) {
    javax::microedition::lcdui::game::GameCanvas::__init(false);
    this->field_1520 = jrt::Ref<class_54>(nullptr);
    this->field_1523 = true;
    this->field_1524 = false;
    this->field_1513 = var1;
    this->field_1522 = false;
    class_84::field_1112 = var1->getDisplay();
    class_84::field_1123 = org::deep3d::Det::random(1);
    {
        try {
            class_84::field_1124 = jrt::concat(JRT_LIT(u"v "), var1->getAppProperty(JRT_LIT(u"MIDlet-Version")));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var3 = jrt::cast<java::lang::Exception>(__ex1.t);
                var3->printStackTrace();
            } else {
                throw;
            }
        }
    }
}

void class_124::method_947() {
    if (this->field_1520->field_595 == class_84::field_1127->at(2)) {
        (jrt::cast<class_64>(class_84::field_1127->at(2)))->method_567();
    }
    class_84::field_1122->method_771();
    class_84::field_1125 = true;
}

void class_124::method_948() {
    if ((class_84::field_1122 != nullptr) && class_84::field_1080) {
        class_84::field_1122->method_772();
    }
    class_84::field_1125 = false;
}

void class_124::hideNotify() {
    if (!this->field_1522) {
        this->field_1513->pause();
    }
}

void class_124::method_949() {
    jrt::Synchronized __sync(this);
    if (this->field_1523) {
        this->field_1523 = false;
        class_84::field_1120 = this->getWidth();
        class_84::field_1121 = this->getHeight();
        this->setFullScreenMode(true);
        this->flushGraphics();
        class_84::field_1120 = this->getWidth();
        class_84::field_1121 = this->getHeight();
        this->setFullScreenMode(true);
    } else if (!this->field_1524) {
        this->field_1524 = true;
        class_84::field_1117 = this->getGraphics();
        class_84::field_1120 = this->getWidth();
        class_84::field_1121 = this->getHeight();
        class_84::field_1116 = jrt::New<class_1>();
        class_84::field_1116->method_2(class_84::field_1084);
        class_84::field_1120 = this->getWidth();
        class_84::field_1121 = this->getHeight();
        this->setFullScreenMode(true);
        class_58::method_514(class_84::field_1117);
        class_58::method_515(JRT_LIT(u"/data/interface/font_deep_white.png"));
        class_58::method_525((-1));
        class_58::method_529(11);
        class_58::method_515(JRT_LIT(u"/data/interface/font_deep_white.png"));
        class_58::method_526((-1), 1);
        class_58::method_531(11, 1);
        class_58::method_522(192, 192, 192, 0, 1);
        class_84::field_1118 = jrt::Ref<javax::microedition::lcdui::Canvas>(jrt::Ref<class_124>(this));
        // Java initialised class_67 here, its first use: its static
        // initialiser installed the toolkit (the other statics are constants)
        org::deep3d::MenuToolkit::install(jrt::Ref<org::deep3d::MenuToolkit>(jrt::New<Deep3dMenu>()));
        class_67::method_576();
        this->field_1521 = jrt::New<class_33>();
        this->field_1521->field_332 = jrt::Ref<javax::microedition::lcdui::game::GameCanvas>(jrt::Ref<class_124>(this));
        this->field_1521->method_296(true);
        class_84::field_1113 = this->field_1521;
        class_84::method_737();
        class_27::method_274();
        class_84::field_1080 = false;
        class_84::field_1111 = class_71::method_686();
        class_84::field_1110 = jrt::New<class_4>(class_84::field_1111);
        class_84::field_1110->method_29();
        class_84::field_1110->method_29();
        class_84::field_1110->method_29();
        class_84::field_1122 = jrt::New<class_88>();
        class_90::method_792();
        class_90::method_780();
        class_90::method_784();
        class_90::method_786();
        class_21::method_198(15000);
        class_90::method_782();
        this->field_1520 = jrt::New<class_54>(this->field_1513, this->field_1521);
        class_84::field_1126 = this->field_1520;
        class_84::field_1127 = jrt::newArray<jrt::Ref<class_61>>(4);
        class_84::field_1127->at(3) = jrt::Ref<class_61>(jrt::New<class_62>());
        class_84::field_1127->at(0) = jrt::Ref<class_61>(jrt::New<class_66>());
        class_84::field_1127->at(1) = jrt::Ref<class_61>(jrt::New<class_63>());
        class_84::field_1127->at(2) = jrt::Ref<class_61>(jrt::New<class_64>());
        Deep3dDebug::install();
        class_21::method_221();
        this->field_1520->method_439(class_84::field_1127->at(3));
    } else {
        Deep3dDebug::tick();
        class_67::method_596();
        this->field_1520->method_442(this->field_1514);
        if (this->field_1518 == 16384) {
            class_67::method_594(true);
            this->field_1519 = this->field_1518;
        } else if (this->field_1518 == 8192) {
            class_67::method_594(false);
            this->field_1519 = this->field_1518;
        }
        if (class_67::method_595()) {
            this->field_1520->method_441(this->field_1519);
            this->field_1519 = -1;
        }
        if ((this->field_1518 != (-1)) && (this->field_1519 == (-1))) {
            this->field_1520->method_441(this->field_1518);
        }
        this->field_1518 = -1;
        this->field_1517 = -1;
        this->flushGraphics();
    }
}

void class_124::method_950() {
    this->field_1520->field_595->method_552();
    class_90::method_793();
    class_67::method_574();
    class_58::method_513();
    class_84::field_1122->method_766();
    class_43::method_382();
    this->field_1521->method_295();
    this->field_1521 = jrt::Ref<class_33>(nullptr);
}

void class_124::method_951() {
    org::deep3d::GameUi::controls(3, (-5), (-5), 0);
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    class_58::method_519(class_58::method_532(class_84::field_1116->method_4(83), (class_84::field_1120 - 10)), (class_84::field_1120 >> 1), (class_84::field_1121 >> 1), 0, 3);
    if (this->field_1518 == 256) {
        this->field_1513->resume();
        this->field_1518 = 0;
        this->field_1517 = 0;
        this->field_1515 = 0;
        this->field_1516 = 0;
        this->field_1514 = 0;
    }
    this->flushGraphics();
}

void class_124::method_952() {
    jrt::Synchronized __sync(this);
    this->field_1514 = this->field_1515;
}

void class_124::keyPressed(int32_t var1) {
    this->field_1516 = this->field_1515;
    if (var1 == (-7)) {
        this->field_1515 |= 8192;
    }
    if (var1 == (-6)) {
        this->field_1515 |= 16384;
    }
    if (((var1 == 49) || (var1 == 101)) || (var1 == 114)) {
        this->field_1515 |= 32768;
    }
    if (((var1 == 51) || (var1 == 105)) || (var1 == 117)) {
        this->field_1515 |= 65536;
    }
    if ((var1 == 48) || (var1 == 32)) {
        this->field_1515 |= 131072;
    }
    if (var1 == (-11)) {
        this->field_1515 |= 262144;
    }
    if (var1 == (-8)) {
        this->field_1515 |= 524288;
    }
    if ((((var1 == (-1)) || (var1 == 50)) || (var1 == 121)) || (var1 == 116)) {
        this->field_1515 |= 2;
    }
    if ((((var1 == (-2)) || (var1 == 56)) || (var1 == 98)) || (var1 == 118)) {
        this->field_1515 |= 64;
    }
    if ((((var1 == (-3)) || (var1 == 52)) || (var1 == 100)) || (var1 == 102)) {
        this->field_1515 |= 4;
    }
    if ((((var1 == (-4)) || (var1 == 54)) || (var1 == 106)) || (var1 == 107)) {
        this->field_1515 |= 32;
    }
    if ((((var1 == (-5)) || (var1 == 53)) || (var1 == 103)) || (var1 == 104)) {
        this->field_1515 |= 256;
    }
    if (((var1 == 55) || (var1 == 99)) || (var1 == 120)) {
        this->field_1515 |= 512;
    }
    if (((var1 == 57) || (var1 == 109)) || (var1 == 110)) {
        this->field_1515 |= 1024;
    }
    if (var1 == 42) {
        this->field_1515 |= 2048;
    }
    if (var1 == 35) {
        this->field_1515 |= 4096;
    }
    this->field_1518 = this->field_1515 & (~this->field_1516);
}

void class_124::keyRepeated(int32_t var1) {
    this->keyPressed(var1);
}

void class_124::keyReleased(int32_t var1) {
    this->field_1516 = this->field_1515;
    if (var1 == (-7)) {
        this->field_1515 &= (-8193);
    }
    if (var1 == (-6)) {
        this->field_1515 &= (-16385);
    }
    if (((var1 == 49) || (var1 == 101)) || (var1 == 114)) {
        this->field_1515 &= (-32769);
    }
    if (((var1 == 51) || (var1 == 105)) || (var1 == 117)) {
        this->field_1515 &= (-65537);
    }
    if ((var1 == 48) || (var1 == 32)) {
        this->field_1515 &= (-131073);
    }
    if (var1 == (-11)) {
        this->field_1515 &= (-262145);
    }
    if (var1 == (-8)) {
        this->field_1515 &= (-524289);
    }
    if ((((var1 == (-1)) || (var1 == 50)) || (var1 == 121)) || (var1 == 116)) {
        this->field_1515 &= (-3);
    }
    if ((((var1 == (-2)) || (var1 == 56)) || (var1 == 98)) || (var1 == 118)) {
        this->field_1515 &= (-65);
    }
    if ((((var1 == (-3)) || (var1 == 52)) || (var1 == 100)) || (var1 == 102)) {
        this->field_1515 &= (-5);
    }
    if ((((var1 == (-4)) || (var1 == 54)) || (var1 == 106)) || (var1 == 107)) {
        this->field_1515 &= (-33);
    }
    if ((((var1 == (-5)) || (var1 == 53)) || (var1 == 103)) || (var1 == 104)) {
        this->field_1515 &= (-257);
    }
    if (((var1 == 55) || (var1 == 99)) || (var1 == 120)) {
        this->field_1515 &= (-513);
    }
    if (((var1 == 57) || (var1 == 109)) || (var1 == 110)) {
        this->field_1515 &= (-1025);
    }
    if (var1 == 42) {
        this->field_1515 &= (-2049);
    }
    if (var1 == 35) {
        this->field_1515 &= (-4097);
    }
    this->field_1517 = (~this->field_1515) & this->field_1516;
}

void class_124::__dumpFields(jrt::Dumper& d) {
    d.f("field_1513", this->field_1513);
    d.f("field_1514", this->field_1514);
    d.f("field_1515", this->field_1515);
    d.f("field_1516", this->field_1516);
    d.f("field_1517", this->field_1517);
    d.f("field_1518", this->field_1518);
    d.f("field_1519", this->field_1519);
    d.f("field_1520", this->field_1520);
    d.f("field_1521", this->field_1521);
    d.f("field_1522", this->field_1522);
    d.f("field_1523", this->field_1523);
    d.f("field_1524", this->field_1524);
}

