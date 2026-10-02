// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int8_t class_119::field_1457{};
int32_t class_119::field_1458{};
int32_t class_119::field_1459{};
int8_t class_119::field_1460{};
int8_t class_119::field_1461{};
int8_t class_119::field_1462{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1463{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1464{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1465{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1466{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1467{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1468{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1469{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1470{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1471{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1472{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1473{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1474{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1475{};
jrt::Ref<jrt::Array<int8_t>> class_119::field_1476{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int8_t>>>>>> class_119::field_1477{};
jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> class_119::field_1478{};
jrt::Ref<javax::microedition::lcdui::Image> class_119::field_1479{};

void class_119::__clinit() {
    class_119::field_1457 = int8_t(6);
    class_119::field_1458 = 40;
    class_119::field_1459 = 40;
    class_119::field_1460 = int8_t(95);
    class_119::field_1461 = int8_t(20);
    class_119::field_1462 = int8_t(60);
    class_119::field_1463 = jrt::arrayOf<int8_t>({int8_t(0), int8_t(1)});
    class_119::field_1464 = jrt::arrayOf<int8_t>({int8_t(72), int8_t(2), int8_t(3), int8_t(4), int8_t(5), int8_t(6), int8_t(7), int8_t(8)});
    class_119::field_1465 = jrt::arrayOf<int8_t>({int8_t(9), int8_t(10), int8_t(11), int8_t(12), int8_t(88)});
    class_119::field_1466 = jrt::arrayOf<int8_t>({int8_t(13), int8_t(14), int8_t(15)});
    class_119::field_1467 = jrt::arrayOf<int8_t>({int8_t(16), int8_t(17), int8_t(18), int8_t(19), int8_t(20), int8_t(21), int8_t(22), int8_t(23), int8_t(24), int8_t(25), int8_t(26), int8_t(27)});
    class_119::field_1468 = jrt::arrayOf<int8_t>({int8_t(84), int8_t(85), int8_t(86), int8_t(87)});
    class_119::field_1469 = jrt::arrayOf<int8_t>({int8_t(30), int8_t(31), int8_t(32), int8_t(33), int8_t(34), int8_t(35), int8_t(36), int8_t(89), int8_t(90), int8_t(91), int8_t(92), int8_t(93)});
    class_119::field_1470 = jrt::arrayOf<int8_t>({int8_t(37), int8_t(38), int8_t(39), int8_t(40)});
    class_119::field_1471 = jrt::arrayOf<int8_t>({int8_t(31), int8_t(33), int8_t(36), int8_t(41), int8_t(42), int8_t(43), int8_t(44), int8_t(45), int8_t(46), int8_t(47), int8_t(48), int8_t(49), int8_t(50), int8_t(51), int8_t(52), int8_t(53), int8_t(54)});
    class_119::field_1472 = jrt::arrayOf<int8_t>({int8_t(58), int8_t(59), int8_t(60), int8_t(61), int8_t(94)});
    class_119::field_1473 = jrt::arrayOf<int8_t>({int8_t(62), int8_t(63), int8_t(64)});
    class_119::field_1474 = jrt::arrayOf<int8_t>({int8_t(29), int8_t(65), int8_t(66), int8_t(67), int8_t(68), int8_t(69), int8_t(70), int8_t(71)});
    class_119::field_1475 = jrt::arrayOf<int8_t>({int8_t(74), int8_t(75), int8_t(76), int8_t(77)});
    class_119::field_1476 = jrt::arrayOf<int8_t>({int8_t(28), int8_t(78), int8_t(79), int8_t(80), int8_t(81), int8_t(82), int8_t(83)});
    class_119::field_1477 = jrt::arrayOf<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int8_t>>>>>({jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1468, class_119::field_1468, class_119::field_1468}), jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1476, class_119::field_1476, class_119::field_1475}), jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1474, class_119::field_1473, class_119::field_1472}), jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1467, class_119::field_1466, class_119::field_1465}), jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1471, class_119::field_1470, class_119::field_1469}), jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({class_119::field_1464, class_119::field_1464, class_119::field_1463})});
    class_119::field_1478 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(int32_t(class_119::field_1460));
}

void class_119::__init() {
}

jrt::Ref<jrt::Array<int8_t>> class_119::method_920(bool var0, int32_t var1) {
    if (class_119::field_1478 == nullptr) {
        class_119::field_1478 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(int32_t(class_119::field_1460));
    }
    jrt::Ref<jrt::Array<int8_t>> var2 = jrt::newArray<int8_t>(int32_t(class_119::field_1457));
    int32_t var3 = 0;
    int8_t var4 = int8_t(0);
    int32_t var5 = 0;
    bool var6 = var0 && (class_84::field_1123->nextInt(100) < int32_t(class_119::field_1461));
    for (int32_t var7 = 0; var7 < class_119::field_1477->length; var7++) {
        var5 = var0 ? (var6 ? 1 : 0) : 2;
        if (var7 == 0) {
            var4 = class_119::field_1468->at(var1);
        } else if ((var7 != 5) || ((var7 == 5) && (class_84::field_1123->nextInt(100) < int32_t(class_119::field_1462)))) {
            int32_t var8 = ((var7 == 1) && (!var0)) ? 2 : (((var7 == 2) && (!var0)) ? 1 : var7);
            var4 = class_119::field_1477->at(var8)->at(var5)->at(class_84::field_1123->nextInt(class_119::field_1477->at(var8)->at(var5)->length));
            if (class_119::field_1478->at(int32_t(var4)) == nullptr) {
                class_119::method_922(int32_t(var4));
            }
        } else {
            var4 = int8_t((-1));
        }
        var2->at((var3++)) = var4;
    }
    return var2;
}

void class_119::method_921(jrt::Ref<jrt::Array<int8_t>> var0) {
    if (var0 != nullptr) {
        for (int32_t var1 = 0; var1 < var0->length; var1++) {
            if ((int32_t(var0->at(var1)) >= 0) && (class_119::field_1478->at(int32_t(var0->at(var1))) == nullptr)) {
                class_119::method_922(int32_t(var0->at(var1)));
            }
        }
    }
}

void class_119::method_922(int32_t var0) {
    class_119::field_1478->at(var0) = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/faces/"), var0, JRT_LIT(u".png")));
}

void class_119::method_923(jrt::Ref<jrt::Array<int8_t>> var0, int32_t var1, int32_t var2, int32_t var3) {
    if (var0 != nullptr) {
        if (int32_t(var0->at(0)) < 0) {
            if (class_119::field_1479 == nullptr) {
                class_119::field_1479 = class_28::method_282(JRT_LIT(u"/data/interface/mai.png"));
            }
            class_84::field_1117->drawImage(class_119::field_1479, var1, var2, var3);
        } else {
            for (int32_t var4 = 0; var4 < var0->length; var4++) {
                if (int32_t(var0->at(var4)) >= 0) {
                    if (class_119::field_1478->at(int32_t(var0->at(var4))) == nullptr) {
                        class_119::method_922(int32_t(var0->at(var4)));
                    }
                    class_84::field_1117->drawImage(class_119::field_1478->at(int32_t(var0->at(var4))), var1, var2, var3);
                }
            }
        }
    }
}

void class_119::__dumpFields(jrt::Dumper& d) {
}

