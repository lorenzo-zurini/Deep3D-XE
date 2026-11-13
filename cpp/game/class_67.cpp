// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_67::field_844{};
int32_t class_67::field_845{};
int32_t class_67::field_846{};
int32_t class_67::field_847{};
int32_t class_67::field_848{};
int32_t class_67::field_849{};
int32_t class_67::field_850{};
int32_t class_67::field_851{};
int32_t class_67::field_852{};
jrt::Ref<javax::microedition::lcdui::Image> class_67::field_853{};
jrt::Ref<javax::microedition::lcdui::Image> class_67::field_854{};
jrt::Ref<javax::microedition::lcdui::Image> class_67::field_855{};
jrt::Ref<javax::microedition::lcdui::Image> class_67::field_856{};
jrt::Ref<jrt::Array<int32_t>> class_67::field_857{};
int64_t class_67::field_858{};
int64_t class_67::field_859{};
int32_t class_67::field_860{};
bool class_67::field_861{};
bool class_67::field_862{};
double class_67::deep3dLockSteps{};

void class_67::__clinit() {
    class_67::field_844 = (-11955272);
    class_67::field_845 = (-14795958);
    class_67::field_846 = (-14461586);
    class_67::field_847 = (-15786202);
    class_67::field_848 = 0;
    class_67::field_849 = 0;
}

void class_67::__init() {
}

void class_67::method_574() {
    class_67::field_853 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_67::field_857 = jrt::Ref<jrt::Array<int32_t>>(nullptr);
}

bool class_67::method_575() {
    return class_67::field_844 == (-9783452);
}

void class_67::method_576() {
    class_67::field_851 = class_58::method_523(JRT_LIT(u"9999")) + 12;
    class_67::field_850 = ((class_84::field_1120 - class_67::field_851) - 6) / 2;
    class_67::field_852 = 10;
    class_67::field_848 = (class_84::field_1120 - 6) + 1;
    class_67::field_849 = ((class_84::field_1121 - 11) - 10) - 4;
    if (class_67::field_853 == nullptr) {
        class_67::field_853 = class_28::method_282(JRT_LIT(u"/data/interface/coin.png"));
        class_67::field_854 = class_28::method_282(JRT_LIT(u"/data/interface/coin_red.png"));
        class_67::field_855 = class_28::method_282(JRT_LIT(u"/data/interface/skip.png"));
    }
    if (class_67::field_857 == nullptr) {
        class_67::field_857 = jrt::newArray<int32_t>(1024);
        for (int32_t var0 = 0; var0 < class_67::field_857->length; var0++) {
            class_67::field_857->at(var0) = -2013265920;
        }
    }
}

int32_t class_67::method_577() {
    return 12;
}

void class_67::method_578(bool var0) {
    if (var0) {
        class_67::field_844 = -9783452;
        class_67::field_845 = -14071252;
        class_67::field_847 = -15391210;
        class_67::field_846 = -12489412;
    } else {
        class_67::field_844 = -11955272;
        class_67::field_845 = -14795958;
        class_67::field_847 = -15786202;
        class_67::field_846 = -14461586;
    }
    if (class_14::method_70()) {
        class_67::field_844 = -131148;
        class_67::field_845 = -8626622;
        class_67::field_847 = -14146007;
        class_67::field_846 = -3296910;
    }
}

void class_67::method_579(int32_t var0) {
    class_67::field_859 += int64_t(var0);
    class_67::field_858 += int64_t(var0);
}

bool class_67::method_580() {
    if (class_67::field_859 > int64_t(1000)) {
        if (class_67::field_859 > int64_t(2000)) {
            class_67::field_859 = int64_t(0);
        }
        return true;
    } else {
        return false;
    }
}

bool class_67::method_581() {
    if (class_67::field_858 > int64_t(300)) {
        if (class_67::field_858 > int64_t(600)) {
            class_67::field_858 = int64_t(0);
        }
        return true;
    } else {
        return false;
    }
}

void class_67::method_582(int32_t var0, int32_t var1, int32_t var2, int32_t var3) {
    class_84::field_1117->setClip(var0, var1, var2, var3);
    class_67::method_583();
    class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
}

void class_67::method_583() {
    for (int32_t var0 = 0; var0 < ((class_84::field_1120 / 32) + 1); var0++) {
        for (int32_t var1 = 0; var1 < ((class_84::field_1121 / 32) + 1); var1++) {
            class_84::field_1117->drawRGB(class_67::field_857, 0, 32, (var0 * 32), (var1 * 32), 32, 32, true);
        }
    }
}

void class_67::method_584(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4) {
    class_67::method_586(var0, var1, var2, var3, var4, false);
}

void class_67::method_585(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4, bool var5, bool var6) {
    org::deep3d::GameUi::registerItem(var0, var1, var2, var3, 12, var4);
    int32_t var7 = class_58::method_523(var0);
    if (var4) {
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->drawLine(var1, (var2 + 2), (var1 + var3), (var2 + 2));
        class_84::field_1117->drawLine(var1, (var2 + 4), (var1 + var3), (var2 + 4));
        class_84::field_1117->drawLine(var1, (var2 + 6), (var1 + var3), (var2 + 6));
        class_84::field_1117->drawLine(var1, (var2 + 8), (var1 + var3), (var2 + 8));
        class_84::field_1117->drawLine(var1, (var2 + 10), (var1 + var3), (var2 + 10));
        class_84::field_1117->fillRect((var5 ? (((var1 + (var3 >> 1)) - (var7 >> 1)) - 1) : (var1 + 9)), (var2 + 2), (var7 + 3), 8);
    }
    class_58::method_516(var0, (var5 ? (var1 + (var3 >> 1)) : (var1 + 10)), (var2 + 1), (var4 ? 0 : 1), (var5 ? 24 : 17));
    if (var6) {
        if (class_67::field_856 == nullptr) {
            class_67::field_856 = class_28::method_282(JRT_LIT(u"/data/interface/lock.png"));
        }
        if ((((class_21::method_143() < 9) && (var0 == class_84::field_1116->method_4(37))) || ((class_21::method_143() < 7) && (var0 == class_84::field_1116->method_4(73)))) || (class_21::method_180()->method_752() && (var0 == class_84::field_1116->method_4(235)))) {
            class_84::field_1117->drawImage(class_67::field_856, (var1 + 3), (var2 + 2), 0);
        }
    }
}

void class_67::method_586(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4, bool var5) {
    class_67::method_585(var0, var1, var2, var3, var4, var5, false);
}

void class_67::method_587() {
    class_84::field_1117->setColor(0);
    class_84::field_1117->fillRect(0, 0, class_84::field_1120, class_84::field_1121);
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(1, 1, (class_84::field_1120 - 3), ((class_84::field_1121 - 6) - class_67::field_852));
}

void class_67::method_588(jrt::Ref<java::lang::String> var0) {
    class_67::method_592(var0, 1, 1, (class_84::field_1120 - 3), ((class_84::field_1121 - 6) - class_67::field_852), false);
}

void class_67::method_589(jrt::Ref<java::lang::String> var0, int32_t var1, bool var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6) {
    jrt::Ref<java::lang::String> var7 = (var1 >= 1000000) ? jrt::concat((var1 / 1000000), JRT_LIT(u"M")) : ((var1 >= 10000) ? jrt::concat((var1 / 1000), JRT_LIT(u"k")) : jrt::concat(JRT_LIT(u""), var1));
    class_58::method_516(jrt::concat(var0, var7), (var3 + (((var6 & 8) != 0) ? (-4) : (((var6 & 2) != 0) ? (-10) : 0))), var4, var5, var6);
    if ((var6 & 32) != 0) {
        var4 -= 10;
    }
    if ((var6 & 8) != 0) {
        var3 += ((class_58::method_523(jrt::concat(var0, var7)) / 2) - 2);
    }
    if ((var6 & 2) != 0) {
        var3 -= 9;
    }
    if (((var6 & 1) != 0) || (var6 == 0)) {
        var3 += (class_58::method_523(jrt::concat(var0, var7)) + 2);
    }
    class_84::field_1117->drawImage((((class_21::method_182() < var1) && var2) ? class_67::field_854 : class_67::field_853), var3, (var4 + 2), 0);
}

void class_67::method_590(int32_t var0, bool var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    class_67::method_589(JRT_LIT(u""), var0, var1, var2, var3, var4, var5);
}

void class_67::method_591(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    class_67::method_592(var0, var1, var2, var3, var4, true);
}

void class_67::method_592(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, bool var5) {
    if (var5) {
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->fillRect(var1, var2, var3, var4);
    }
    class_84::field_1117->setColor(class_67::field_846);
    class_84::field_1117->fillRect(var1, var2, var3, 8);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->drawRect(var1, var2, var3, var4);
    class_84::field_1117->setClip(var1, var2, var3, 10);
    for (int32_t var6 = var1; var6 < (var1 + var3); var6 += 4) {
        class_84::field_1117->drawLine(var6, (var2 + 6), (var6 + 4), (var2 + 2));
    }
    class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
    class_84::field_1117->drawLine(var1, (var2 + 8), (var1 + var3), (var2 + 8));
    class_84::field_1117->fillRect(var1, var2, (class_58::method_523(var0) + 4), 8);
    class_58::method_518(var0, (var1 + 2), (var2 - 1), 0);
}

void class_67::method_593(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1) {
    class_67::method_601(var0, var1, true);
}

void class_67::method_594(bool var0) {
    class_67::field_861 = var0;
    class_67::field_860 = 5;
}

bool class_67::method_595() {
    return class_67::field_860 <= 0;
}

void class_67::method_596() {
    class_67::field_860 -= org::deep3d::Step::steps(class_67::deep3dLockSteps);
}

void class_67::method_597(bool var0) {
    class_67::field_862 = var0;
}

void class_67::method_598(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    class_67::method_599(var0, var1, var2, var3, var4, 17);
}

void class_67::method_599(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5) {
    jrt::Ref<java::lang::String> var6{};
    jrt::Ref<java::lang::String> var7{};
    class_58::method_516((((var7 = class_58::method_533(var6 = var0->trim(), (var3 - 2), true))->equals(jrt::Ref<java::lang::Object>(var6))) ? var6 : jrt::concat(var7, JRT_LIT(u"..."))), var1, var2, var4, var5);
}

jrt::Ref<java::lang::String> class_67::method_600(jrt::Ref<java::lang::String> var0, int32_t var1) {
    jrt::Ref<java::lang::String> var2{};
    jrt::Ref<java::lang::String> var3{};
    return ((var3 = class_58::method_533(var2 = var0->trim(), (var1 - 2), true))->equals(jrt::Ref<java::lang::Object>(var2))) ? var2 : jrt::concat(var3, JRT_LIT(u"..."));
}

void class_67::method_601(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1, bool var2) {
    class_67::method_602(var0, var1, var2, false);
}

void class_67::method_602(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1, bool var2, bool var3) {
    jrt::Ref<javax::microedition::lcdui::Graphics> g = class_84::field_1117;
    if (!org::deep3d::Config::pcAdditions()) {
        // the phone's soft-key bar (the game compared
        // with the "" literal, so by content here)
        auto empty = [](const jrt::Ref<java::lang::String>& s) { return s != nullptr && s->length() == 0; };
        int32_t by = (class_84::field_1121 - 3) - class_67::field_852;
        g->setColor(class_67::field_845);
        g->setColor(((!class_67::field_861 || class_67::field_860 <= 0 || empty(var0)) && !class_67::field_862) ? class_67::field_846 : class_67::field_844);
        g->fillRect(1, by, class_67::field_850, class_67::field_852);
        g->setColor((!class_67::field_861 && class_67::field_860 > 0 && !empty(var1)) ? class_67::field_844 : class_67::field_846);
        g->fillRect((class_84::field_1120 - class_67::field_850) - 1, by, class_67::field_850 - 1, class_67::field_852);
        g->setColor(class_67::field_846);
        g->fillRect(3 + class_67::field_850, by, class_67::field_851, class_67::field_852);
        g->setColor(class_67::field_844);
        g->drawRect(1, by, class_67::field_850, class_67::field_852);
        g->drawRect((class_84::field_1120 - class_67::field_850) - 1, by, class_67::field_850 - 1, class_67::field_852);
        g->drawRect(3 + class_67::field_850, by, class_67::field_851, class_67::field_852);
        class_67::method_599(var0, 1 + (class_67::field_850 >> 1), class_84::field_1121 - 2, class_67::field_850 + 2, 1, 40);
        class_67::method_599(var1, (class_84::field_1120 - 1) - (class_67::field_850 >> 1), class_84::field_1121 - 2, class_67::field_850 + 2, 1, 40);
        if (var2) {
            class_67::method_590(class_21::method_182(), false, class_84::field_1120 >> 1, class_84::field_1121 - 2, 0, 40);
        } else if (var3) {
            g->drawImage(class_67::field_855, class_84::field_1120 >> 1, class_84::field_1121 - 3, 33);
        }
        return;
    }
    int32_t h = class_67::field_852;
    int32_t y = (class_84::field_1121 - 3) - h;
    int32_t w = class_84::field_1120;
    g->setColor(class_67::field_847);
    g->fillRect(0, (y - 2), w, (h + 5));
    g->setColor(class_67::field_844);
    g->drawLine(0, (y - 2), w, (y - 2));
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> chips = org::deep3d::GameUi::barChips(var0, var1);
    int32_t lw = class_67::drawCommand(chips->at(1), chips->at(0), 2, y, h, false, (class_67::field_861 && (class_67::field_860 > 0)));
    int32_t rw = class_67::drawCommand(chips->at(3), chips->at(2), (w - 2), y, h, true, ((!class_67::field_861) && (class_67::field_860 > 0)));
    org::deep3d::GameUi::registerBarZones(2, y, lw, h, ((w - 2) - rw), y, rw, h);
    if (var2) {
        class_67::method_590(class_21::method_182(), false, (w >> 1), (class_84::field_1121 - 2), 0, 40);
    } else if (var3) {
        g->drawImage(class_67::field_855, (w >> 1), (class_84::field_1121 - 3), 33);
    }
}

jrt::Ref<jrt::Array<int32_t>> class_67::deep3dBar(jrt::Ref<java::lang::String> lk, jrt::Ref<java::lang::String> ll, jrt::Ref<java::lang::String> rk, jrt::Ref<java::lang::String> rl) {
    jrt::Ref<javax::microedition::lcdui::Graphics> g = class_84::field_1117;
    int32_t h = class_67::field_852;
    int32_t y = (class_84::field_1121 - 3) - h;
    int32_t w = class_84::field_1120;
    g->setColor(class_67::field_847);
    g->fillRect(0, (y - 2), w, (h + 5));
    g->setColor(class_67::field_844);
    g->drawLine(0, (y - 2), w, (y - 2));
    int32_t lw = class_67::drawCommand(ll, lk, 2, y, h, false, false);
    int32_t rw = class_67::drawCommand(rl, rk, (w - 2), y, h, true, false);
    return jrt::arrayOf<int32_t>({y, h, lw, rw});
}

int32_t class_67::drawCommand(jrt::Ref<java::lang::String> label, jrt::Ref<java::lang::String> key, int32_t x, int32_t y, int32_t h, bool alignRight, bool lit) {
    if ((label == nullptr) || label->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u"")))) {
        return 0;
    }
    jrt::Ref<javax::microedition::lcdui::Graphics> g = class_84::field_1117;
    int32_t kw = key->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u""))) ? 0 : (class_58::method_523(key) + 7);
    int32_t cw = (kw + class_58::method_523(label)) + 9;
    int32_t cx = alignRight ? (x - cw) : x;
    g->setColor((lit ? class_67::field_844 : class_67::field_846));
    g->fillRect(cx, y, cw, h);
    g->setColor(class_67::field_844);
    g->drawRect(cx, y, cw, h);
    if (kw > 0) {
        class_58::method_518(key, (cx + 4), y, 1);
    }
    class_58::method_518(label, ((cx + 4) + kw), y, 0);
    return cw;
}

void class_67::__dumpFields(jrt::Dumper& d) {
}

