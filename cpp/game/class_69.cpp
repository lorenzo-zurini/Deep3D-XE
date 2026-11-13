// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

int32_t class_69::field_893{};
int32_t class_69::field_894{};
int32_t class_69::field_895{};
int32_t class_69::field_896{};
int32_t class_69::field_897{};
int32_t class_69::field_898{};
int32_t class_69::field_899{};
int32_t class_69::field_900{};
int32_t class_69::field_901{};
int32_t class_69::field_902{};
int32_t class_69::field_903{};
int32_t class_69::field_904{};
int32_t class_69::field_905{};
int32_t class_69::field_906{};
int32_t class_69::field_907{};
int32_t class_69::field_908{};
int32_t class_69::field_909{};
int32_t class_69::field_910{};
int32_t class_69::field_911{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_912{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_913{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_914{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_915{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_916{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_917{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_918{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_919{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_920{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_921{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_922{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_923{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_924{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_925{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_926{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_927{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_928{};
jrt::Ref<javax::microedition::lcdui::game::Sprite> class_69::field_929{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_930{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_931{};
jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> class_69::field_932{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_69::field_933{};
float class_69::field_934{};
int32_t class_69::field_935{};
int32_t class_69::field_936{};
int32_t class_69::field_937{};
int32_t class_69::field_938{};
int32_t class_69::field_939{};
int32_t class_69::field_940{};
bool class_69::field_941{};
bool class_69::field_942{};
bool class_69::field_943{};
bool class_69::field_944{};
jrt::Ref<java::lang::String> class_69::field_945{};
bool class_69::field_946{};
int32_t class_69::field_947{};
int32_t class_69::field_948{};
int32_t class_69::field_949{};
jrt::Ref<java::lang::String> class_69::field_950{};
jrt::Ref<java::lang::String> class_69::field_951{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_69::field_952{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_69::field_953{};
bool class_69::field_954{};
int32_t class_69::field_955{};
bool class_69::field_956{};
bool class_69::field_957{};
bool class_69::field_958{};
bool class_69::field_959{};
int32_t class_69::field_960{};
jrt::Ref<java::lang::String> class_69::field_961{};
jrt::Ref<javax::microedition::lcdui::Image> class_69::field_962{};
bool class_69::field_963{};
bool class_69::field_964{};
bool class_69::field_965{};

void class_69::__clinit() {
    class_69::field_950 = JRT_LIT(u"");
    class_69::field_951 = JRT_LIT(u"");
    class_69::field_961 = JRT_LIT(u"");
}

void class_69::__init() {
}

void class_69::method_631() {
    {
        try {
            class_69::field_912 = class_28::method_282(JRT_LIT(u"/data/interface/i_bar.png"));
            class_69::field_913 = class_28::method_282(JRT_LIT(u"/data/interface/i_barend.png"));
            class_69::field_914 = class_28::method_282(JRT_LIT(u"/data/interface/i_shield.png"));
            class_69::field_915 = class_28::method_282(JRT_LIT(u"/data/interface/i_hull.png"));
            class_69::field_926 = class_28::method_282(JRT_LIT(u"/data/interface/i_laser.png"));
            class_69::field_927 = class_28::method_282(JRT_LIT(u"/data/interface/i_harpoon.png"));
            class_69::field_916 = class_28::method_282(JRT_LIT(u"/data/interface/i_booster.png"));
            class_69::field_917 = class_28::method_282(JRT_LIT(u"/data/interface/i_autofire.png"));
            class_69::field_918 = class_28::method_282(JRT_LIT(u"/data/interface/i_autopilot.png"));
            class_69::field_919 = class_28::method_282(JRT_LIT(u"/data/interface/i_weight.png"));
            class_69::field_920 = class_28::method_282(JRT_LIT(u"/data/interface/i_weight_box.png"));
            class_69::field_921 = class_28::method_282(JRT_LIT(u"/data/interface/display_radiation.png"));
            class_69::field_923 = class_28::method_282(JRT_LIT(u"/data/interface/display_warning_radiation.png"));
            class_69::field_924 = class_28::method_282(JRT_LIT(u"/data/interface/display_pressure.png"));
            class_69::field_922 = class_28::method_282(JRT_LIT(u"/data/interface/display_warning_pressure.png"));
            class_69::field_925 = class_28::method_282(JRT_LIT(u"/data/interface/menu.png"));
            class_69::field_929 = jrt::New<javax::microedition::lcdui::game::Sprite>(class_28::method_282(JRT_LIT(u"/data/interface/numbers.png")), 14, 12);
            class_69::field_930 = class_28::method_282(JRT_LIT(u"/data/interface/hull.png"));
            class_69::field_905 = (class_84::field_1120 / 2) - 21;
            class_69::field_906 = (class_84::field_1120 / 2) - 7;
            class_69::field_907 = (class_84::field_1120 / 2) + 7;
            class_69::field_904 = class_69::field_920->getWidth();
            class_69::field_903 = 0;
            class_69::field_900 = 0;
            class_69::field_895 = class_84::field_1120 >> 1;
            class_69::field_896 = class_84::field_1121 - 17;
            class_69::field_897 = (((class_69::field_895 - 22) - 1) - 4) - 3;
            class_69::field_901 = (((class_84::field_1120 - 4) - 11) - class_69::field_904) - 3;
            if ((class_69::field_897 % 2) == 0) {
                class_69::field_897--;
                class_69::field_900 = 1;
            }
            if ((class_69::field_901 % 2) == 0) {
                class_69::field_901--;
                class_69::field_903 = 1;
            }
            class_69::field_898 = class_69::field_912->getWidth();
            class_69::field_899 = jrt::div(class_69::field_897, class_69::field_898) + 1;
            class_69::field_902 = jrt::div(class_69::field_901, class_69::field_898) + 1;
            class_69::field_908 = (((class_84::field_1121 - 33) - 17) - 13) - 4;
            class_69::field_911 = class_84::field_1120 - 6;
            class_69::field_934 = float(class_69::field_908) / 15000.0f;
            class_69::field_909 = 33 + jrt::f2i((float((class_21::method_178()->field_889 - 15000)) * class_69::field_934));
            class_69::field_910 = (33 + jrt::f2i((float((class_21::method_178()->field_890 - 15000)) * class_69::field_934))) - class_69::field_909;
            class_69::field_893 = class_84::field_1120 - 28;
            class_69::field_894 = class_69::field_908;
            class_69::field_943 = false;
            class_69::field_936 = 10000;
            class_69::field_955 = class_84::field_1120 - 5;
            class_69::field_957 = class_21::method_178()->field_878 > 0;
            class_69::field_958 = class_21::method_178()->field_871 > 0;
            class_69::field_959 = class_21::method_178()->field_872 > 0;
            jrt::Ref<java::lang::Object> var0 = jrt::Ref<java::lang::Object>(nullptr);
            class_69::field_932 = jrt::newArray<jrt::Ref<javax::microedition::lcdui::Image>>(2);
            class_69::field_933 = jrt::newArray<jrt::Ref<java::lang::String>>(2);
            for (int32_t var1 = 0; var1 < 2; var1++) {
                class_69::field_932->at(var1) = (var1 == 0) ? class_69::field_926 : class_69::field_927;
                class_69::field_933->at(var1) = class_84::field_1116->method_4(int32_t(class_1::field_3->at(var1)));
            }
            class_69::field_950 = JRT_LIT(u"");
            class_69::field_951 = JRT_LIT(u"");
            class_69::field_952 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
            class_69::field_964 = false;
            class_69::field_965 = false;
            class_69::field_962 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
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

void class_69::method_632() {
    class_69::field_917 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_918 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_912 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_913 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_916 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_928 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_927 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_915 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_925 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_924 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_926 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_921 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_922 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_923 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_914 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    class_69::field_962 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
}

void class_69::method_633(int32_t var0, jrt::Ref<class_70> var1) {
    {
        switch (var0) {
        case 0:
            if (var1->field_987 == (-1)) {
                return;
            }
            class_69::field_945 = class_69::field_933->at(((var1->method_663() == 2) ? 1 : 0));
            class_69::field_944 = true;
            class_84::field_1122->method_770(15);
            break;
        case 1:
            if (var1->field_987 == (-1)) {
                return;
            }
            class_69::field_945 = [&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(12); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(14); return jrt::concat(__c1, __c2, __c3); }();
            class_69::field_944 = true;
            class_84::field_1122->method_770(15);
            break;
        case 2:
            if (var1->field_987 == (-1)) {
                return;
            }
            class_69::field_945 = [&]() { jrt::Ref<java::lang::String> __c4 = class_84::field_1116->method_4(12); jrt::Ref<java::lang::String> __c5 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(15); return jrt::concat(__c4, __c5, __c6); }();
            class_69::field_944 = true;
            class_84::field_1122->method_770(15);
            break;
        case 3:
            if ((!class_69::field_957) || (!var1->method_651())) {
                return;
            }
            class_69::field_945 = class_84::field_1116->method_4(137);
            class_69::field_944 = false;
            break;
        case 4:
            if (!class_69::field_957) {
                return;
            }
            class_69::field_945 = class_84::field_1116->method_4(138);
            class_69::field_944 = false;
            break;
        case 5:
            class_69::field_945 = [&]() { jrt::Ref<java::lang::String> __c7 = class_84::field_1116->method_4(323); jrt::Ref<java::lang::String> __c8 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c9 = class_84::field_1116->method_4(14); return jrt::concat(__c7, __c8, __c9); }();
            class_69::field_944 = false;
            class_84::field_1122->method_770(15);
            break;
        case 6:
            class_69::field_945 = [&]() { jrt::Ref<java::lang::String> __c10 = class_84::field_1116->method_4(323); jrt::Ref<java::lang::String> __c11 = JRT_LIT(u" "); jrt::Ref<java::lang::String> __c12 = class_84::field_1116->method_4(15); return jrt::concat(__c10, __c11, __c12); }();
            class_69::field_944 = false;
            class_84::field_1122->method_770(15);
            break;
        case 7:
            class_69::field_945 = class_84::field_1116->method_4(294);
            class_69::field_944 = false;
        }
    }
    class_69::field_946 = class_58::method_523(class_69::field_945) > (((class_84::field_1120 / 2) - 11) - 4);
    class_69::field_939 = 0;
    class_69::field_943 = true;
}

void class_69::method_634(int32_t var0, int32_t var1, jrt::Ref<java::lang::String> var2) {
    class_69::field_947 = var0;
    class_69::field_948 = var1;
    class_69::field_950 = var2;
}

void class_69::method_635() {
    class_69::field_952 = class_58::method_532(([&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(26); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u"\n\n\n\n\n\n"); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(28); jrt::Ref<java::lang::String> __c4 = JRT_LIT(u"\n\n\n\n\n\n"); jrt::Ref<java::lang::String> __c5 = class_84::field_1116->method_4(27); return jrt::concat(__c1, __c2, __c3, __c4, __c5); }()), (class_84::field_1120 - 20));
}

void class_69::method_636(int32_t var0) {
    class_69::field_949 += var0;
}

bool class_69::method_637() {
    return class_69::field_949 > ((class_58::method_530(class_69::field_952) + class_84::field_1121) + 20);
}

void class_69::method_638(jrt::Ref<java::lang::String> var0) {
    // Deep3D-PC: DEEP3D_NO_HINTS=1 films flight without the HUD's hint line
    static const bool noHints = getenv("DEEP3D_NO_HINTS") != nullptr;
    if (noHints) {
        var0 = JRT_LIT(u"");
    }
    if (var0 == JRT_LIT(u"")) {
        var0 = jrt::Ref<java::lang::String>(nullptr);
    }
    class_69::field_953 = class_58::method_532(var0, class_69::field_955);
}

void class_69::method_639(int32_t var0) {
    if (var0 > 0) {
        class_69::field_936 = 0;
        class_69::field_961 = jrt::concat(JRT_LIT(u"+ "), var0, JRT_LIT(u" $"));
    } else {
        class_69::field_961 = JRT_LIT(u"");
        class_69::field_936 = 5001;
    }
}

void class_69::method_640(int32_t var0, int32_t var1, bool var2, bool var3) {
    class_69::field_965 = var2;
    class_69::field_936 = 0;
    class_69::field_954 = var2;
    if (var3) {
        class_69::field_950 = class_69::field_951 = class_84::field_1116->method_4(293);
        jrt::Ref<java::lang::String> var4 = (class_21::method_132()->field_1146 == 1) ? JRT_LIT(u"recovery") : JRT_LIT(u"salvage");
        class_69::field_928 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var4, JRT_LIT(u".png")));
    } else if (var2) {
        class_69::field_950 = class_84::field_1116->method_4(143);
    } else {
        bool var5 = var0 < 13;
        class_69::field_928 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), var0, JRT_LIT(u".png")));
        class_69::field_950 = (!var5) ? class_84::field_1116->method_4(293) : JRT_LIT(u"");
        class_69::field_951 = jrt::concat(class_84::field_1116->method_4(int32_t(class_1::field_7->at(var0)->at(0))), JRT_LIT(u"   "), var1, JRT_LIT(u"t"));
    }
    class_69::field_947 = -100;
    class_69::field_948 = -100;
}

bool class_69::method_641() {
    return class_69::field_965;
}

void class_69::method_642(int64_t var0, jrt::Ref<class_70> var2, bool var3) {
    int32_t var4{};
    if ((((var4 = var2->field_1004) >= class_21::method_178()->field_889) && (var4 <= class_21::method_178()->field_890)) || Deep3dDebug::godFor(var2->field_969)) {
        class_69::field_956 = false;
        class_69::field_937 = 0;
        class_69::field_941 = false;
        class_69::field_942 = false;
    } else {
        if (!class_69::field_956) {
            class_84::field_1122->method_770(4);
            class_69::field_956 = true;
        }
        class_69::field_937 = int32_t((int64_t(class_69::field_937) + var0));
        class_69::field_935 = int32_t((int64_t(class_69::field_935) + var0));
        bool var5 = var4 > class_21::method_178()->field_890;
        class_69::field_942 = true;
        float deep3dLevel = (class_69::field_941 ? 0.7f : (0.5f * java::lang::Math::min(1.0f, (float(class_69::field_937) / 5000.0f)))) + (0.3f * java::lang::Math::min(1.0f, (float((var5 ? (var4 - class_21::method_178()->field_890) : (class_21::method_178()->field_889 - var4))) / 4000.0f)));
        org::deep3d::Remaster::hazard((var5 ? 0.0f : deep3dLevel), (var5 ? deep3dLevel : 0.0f));
        if ((class_69::field_941 && (!var3)) && org::deep3d::Step::past(class_69::field_937, 250)) {
            class_69::field_937 = 0;
            if (var5) {
                var2->field_969->method_339((2 + class_16::method_97(0, ((var4 - 30000) / 2000))));
            } else {
                var2->field_969->method_340((2 + class_16::method_97(0, ((15000 - var4) / 2000))));
            }
        }
        if (class_69::field_935 > 1000) {
            if (class_69::field_935 > 2000) {
                class_69::field_935 = 0;
            }
            class_84::field_1117->drawImage((var5 ? class_69::field_924 : class_69::field_921), (class_84::field_1120 >> 1), 39, 17);
            if (class_69::field_937 > 5000) {
                class_69::field_941 = true;
            }
        } else {
            class_84::field_1117->drawImage(((var4 > class_21::method_178()->field_890) ? class_69::field_922 : class_69::field_923), (class_84::field_1120 >> 1), 39, 17);
        }
    }
}

void class_69::method_643(jrt::Ref<java::lang::String> var0, bool var1) {
    if (class_69::field_946) {
        class_58::method_516(var0, (var1 ? 3 : ((class_84::field_1120 - 2) - 1)), (class_69::field_896 - 1), 0, ((var1 ? 1 : 2) | 32));
    } else {
        class_58::method_516(var0, (class_69::field_895 + (var1 ? (-14) : 14)), (class_69::field_896 - 1), 0, ((var1 ? 2 : 1) | 32));
    }
}

void class_69::method_644(int64_t var0, int64_t var2, jrt::Ref<class_70> var4, bool var5) {
    class_69::field_940 = 33 + jrt::f2i((float((var4->field_1004 - 15000)) * class_69::field_934));
    if (class_69::field_940 > (33 + class_69::field_908)) {
        class_69::field_940 = 33 + class_69::field_908;
    } else if (class_69::field_940 <= 33) {
        class_69::field_940 = 33;
    }
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(13, 3, class_69::field_901, 11);
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->fillRect(13, 3, jrt::f2i(((float(class_21::method_178()->field_867) / float(class_21::method_178()->method_607())) * float(class_69::field_901))), 11);
    class_84::field_1117->setClip(13, 3, class_69::field_901, 11);
    for (int32_t var6 = 0; var6 < class_69::field_902; var6++) {
        class_84::field_1117->drawImage(class_69::field_912, (13 + (var6 * (class_69::field_898 - 1))), 3, 0);
    }
    class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
    class_84::field_1117->fillRect(2, 2, 11, 13);
    class_84::field_1117->drawImage(class_69::field_919, 2, 2, 0);
    class_84::field_1117->fillRect(((((class_84::field_1120 - 2) - class_69::field_904) - 3) - class_69::field_903), 2, 3, 13);
    class_84::field_1117->drawImage(class_69::field_913, ((((class_84::field_1120 - 2) - class_69::field_904) - 3) - class_69::field_903), 2, 0);
    class_84::field_1117->setColor(((class_21::method_178()->field_867 == class_21::method_178()->method_607()) ? class_67::field_844 : class_67::field_845));
    class_84::field_1117->fillRect(((class_84::field_1120 - 2) - class_69::field_904), 3, class_69::field_904, 11);
    class_84::field_1117->drawImage(class_69::field_920, (class_84::field_1120 - 2), 3, 24);
    class_58::method_516(jrt::concat(class_21::method_178()->field_867, JRT_LIT(u"/"), class_21::method_178()->method_607(), JRT_LIT(u"t")), ((class_84::field_1120 - 2) - 2), 3, 0, 18);
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect(class_69::field_911, 33, 3, class_69::field_908);
    class_84::field_1117->setColor(class_67::field_844);
    if ((class_69::field_942 && class_67::method_581()) || (!class_69::field_942)) {
        class_84::field_1117->fillRect(class_69::field_911, class_69::field_909, 3, class_69::field_910);
    }
    class_84::field_1117->setColor((-15790321));
    class_84::field_1117->drawRect(class_69::field_911, 33, 3, class_69::field_908);
    class_84::field_1117->fillTriangle((class_69::field_911 - 4), (class_69::field_940 + 6), (class_69::field_911 + 2), class_69::field_940, (class_69::field_911 - 4), (class_69::field_940 - 6));
    class_84::field_1117->setColor(class_67::field_844);
    class_84::field_1117->fillTriangle((class_69::field_911 - 3), (class_69::field_940 + 4), (class_69::field_911 + 1), class_69::field_940, (class_69::field_911 - 3), (class_69::field_940 - 4));
    if (org::deep3d::Config::pcAdditions() && ((!class_69::field_942) || class_67::method_581())) {   // Deep3D-PC: the depth, by its arrow
        class_58::method_516(jrt::concat(org::deep3d::Scale::depth(var4->field_1004), JRT_LIT(u" m")), (class_69::field_911 - 7), class_69::field_940, 0, 6);
    }
    class_69::method_642(var0, var4, false);
    if (class_69::field_943) {
        class_69::field_939 = int32_t((int64_t(class_69::field_939) + var0));
        class_69::method_643(class_69::field_945, class_69::field_944);
        if (class_69::field_939 > 1000) {
            class_69::field_943 = false;
            class_69::field_946 = false;
        }
    }
    if (var4->field_987 != (-1)) {
        if (!class_69::field_946) {
            class_84::field_1117->setColor(class_67::field_844);
            class_84::field_1117->fillRect(((class_69::field_895 - 11) - 1), ((class_69::field_896 - 13) - 1), 11, 13);
            class_84::field_1117->setColor(class_67::field_845);
            class_84::field_1117->fillRect(((class_69::field_895 - 11) - 1), ((class_69::field_896 - 13) - 1), 11, jrt::f2i(((1.0f - var4->field_969->method_338(var4->field_987)) * 13.0f)));
            class_84::field_1117->drawImage(class_69::field_932->at(((var4->method_663() == 2) ? 1 : 0)), ((class_69::field_895 - 11) - 1), ((class_69::field_896 - 13) - 1), 0);
        }
        class_84::field_1117->setColor(class_67::field_844);
        if (!var5) {
            class_84::field_1117->setColor(class_67::field_845);
        }
        class_84::field_1117->fillRect(((class_69::field_895 - 11) - 1), (class_69::field_896 + 1), 11, 13);
        class_84::field_1117->drawImage(class_69::field_917, ((class_69::field_895 - 11) - 1), (class_69::field_896 + 1), 0);
    }
    if ((!class_69::field_946) && class_69::field_957) {
        if (!var4->field_994) {
            class_84::field_1117->setColor(class_67::field_844);
        }
        class_84::field_1117->fillRect((class_69::field_895 + 1), ((class_69::field_896 - 13) - 1), 11, 13);
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->fillRect((class_69::field_895 + 1), ((class_69::field_896 - 13) - 1), 11, jrt::f2i(((1.0f - var4->method_653()) * 13.0f)));
        class_84::field_1117->drawImage(class_69::field_916, (class_69::field_895 + 1), ((class_69::field_896 - 13) - 1), 0);
    }
    class_84::field_1117->setColor(class_67::field_845);
    class_84::field_1117->fillRect((class_69::field_895 + 1), (class_69::field_896 + 1), 11, 13);
    if (var4->field_1007 && class_67::method_580()) {
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->fillRect((class_69::field_895 + 1), (class_69::field_896 + 1), 11, 13);
    }
    class_84::field_1117->drawImage(class_69::field_918, (class_69::field_895 + 1), (class_69::field_896 + 1), 0);
    if (class_69::field_958) {
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->fillRect(13, (class_69::field_896 + 2), class_69::field_897, 11);
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->fillRect(13, (class_69::field_896 + 2), jrt::f2i(((float(var4->field_969->field_371) / 100.0f) * float(class_69::field_897))), 11);
        class_84::field_1117->setClip(13, (class_69::field_896 + 2), class_69::field_897, 11);
        for (int32_t var8 = 0; var8 < class_69::field_899; var8++) {
            class_84::field_1117->drawImage(class_69::field_912, (13 + (var8 * (class_69::field_898 - 1))), (class_69::field_896 + 2), 0);
        }
        class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
        class_84::field_1117->fillRect(2, (class_69::field_896 + 1), 11, 13);
        class_84::field_1117->drawImage(class_69::field_914, 2, (class_69::field_896 + 1), 0);
        class_84::field_1117->fillRect((((((class_69::field_895 - 1) - 11) - 2) - 3) - class_69::field_900), (class_69::field_896 + 1), 3, 13);
        class_84::field_1117->drawImage(class_69::field_913, (((((class_69::field_895 - 1) - 11) - 2) - 3) - class_69::field_900), (class_69::field_896 + 1), 0);
    }
    if (class_69::field_959) {
        class_84::field_1117->setColor(class_67::field_845);
        class_84::field_1117->fillRect((((class_69::field_895 + 2) + 2) + 22), (class_69::field_896 + 2), class_69::field_897, 11);
        class_84::field_1117->setColor(class_67::field_844);
        class_84::field_1117->fillRect((((class_69::field_895 + 2) + 2) + 22), (class_69::field_896 + 2), jrt::f2i(((float(var4->field_969->field_372) / 100.0f) * float(class_69::field_897))), 11);
        class_84::field_1117->setClip((((class_69::field_895 + 2) + 2) + 22), (class_69::field_896 + 2), class_69::field_897, 11);
        for (int32_t var9 = 0; var9 < class_69::field_899; var9++) {
            class_84::field_1117->drawImage(class_69::field_912, ((((class_69::field_895 + 2) + 2) + 22) + (var9 * (class_69::field_898 - 1))), (class_69::field_896 + 2), 0);
        }
        class_84::field_1117->setClip(0, 0, class_84::field_1120, class_84::field_1121);
        class_84::field_1117->fillRect((((class_69::field_895 + 2) + 11) + 2), (class_69::field_896 + 1), 11, 13);
        class_84::field_1117->drawImage(class_69::field_915, (((class_69::field_895 + 2) + 11) + 2), (class_69::field_896 + 1), 0);
        class_84::field_1117->fillRect((((class_84::field_1120 - 2) - 2) - class_69::field_900), (class_69::field_896 + 1), 3, 13);
        class_84::field_1117->drawImage(class_69::field_913, (((class_84::field_1120 - 2) - 2) - class_69::field_900), (class_69::field_896 + 1), 0);
    }
    int32_t var10 = var4->method_660();
    if (class_69::field_960 > var10) {
        class_69::field_938 = 0;
    }
    if ((var10 < 100) && (class_69::field_938 < 3000)) {
        if (class_67::method_581()) {
            class_69::field_938 = int32_t((int64_t(class_69::field_938) + var0));
            int32_t var7 = 41 + class_69::field_922->getHeight();
            class_84::field_1117->drawImage(class_69::field_930, class_69::field_895, var7, 17);
            class_69::field_929->setFrame((var10 / 10));
            class_69::field_929->setPosition(class_69::field_905, (var7 + 14));
            class_69::field_929->paint(class_84::field_1117);
            class_69::field_929->setFrame((var10 % 10));
            class_69::field_929->setPosition(class_69::field_906, (var7 + 14));
            class_69::field_929->paint(class_84::field_1117);
            class_69::field_929->setFrame(10);
            class_69::field_929->setPosition(class_69::field_907, (var7 + 14));
            class_69::field_929->paint(class_84::field_1117);
        }
    } else if (var10 < 100) {
        if (class_69::field_931 == nullptr) {
            class_69::field_931 = class_28::method_282(JRT_LIT(u"/data/interface/hull_icon.png"));
        }
        class_84::field_1117->drawImage(class_69::field_931, (((14 + class_69::field_893) - 4) - class_58::method_523(jrt::concat(var10, JRT_LIT(u"%")))), ((33 + class_69::field_894) - 2), 40);
        class_58::method_516(jrt::concat(var10, JRT_LIT(u"%")), ((14 + class_69::field_893) - 2), ((33 + class_69::field_894) - 2), 0, 34);
    }
    class_69::field_960 = var10;
    class_84::field_1117->drawImage(class_69::field_925, 1, (class_84::field_1121 - 4), 20);
    if (class_69::field_950 != JRT_LIT(u"")) {
        class_58::method_518(class_69::field_950, class_69::field_947, class_69::field_948, 1);
    }
    if (class_69::field_936 < 5000) {
        class_69::field_936 = int32_t((int64_t(class_69::field_936) + var0));
        if (class_69::field_961 != JRT_LIT(u"")) {
            if (class_67::method_581()) {
                class_58::method_518(class_69::field_961, 14, 18, 0);
            }
        } else if (!class_69::field_954) {
            if (class_69::field_928 != nullptr) {
                class_84::field_1117->drawImage(class_69::field_928, 14, 17, 0);
            }
            class_58::method_518(class_69::field_951, 36, 18, 0);
        } else {
            class_58::method_518(class_69::field_950, 14, 18, 0);
        }
        if (class_69::field_936 > 5000) {
            class_69::field_950 = JRT_LIT(u"");
            class_69::field_951 = JRT_LIT(u"");
            class_69::field_961 = JRT_LIT(u"");
        }
    } else if (class_69::field_953 == nullptr) {
        if (var2 > int64_t(0)) {
            class_58::method_518(class_48::method_397(var2), 14, 18, 1);
        }
        jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var11 = jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>(nullptr);
        if (class_21::method_132()->field_1146 == 6) {
            class_58::method_518(jrt::concat(class_84::field_1116->method_4(295), JRT_LIT(u": "), var4->field_981->field_286), 14, 18, 1);
        } else if (class_21::method_132()->field_1146 == 11) {
            class_58::method_518(jrt::concat(class_84::field_1116->method_4(296), JRT_LIT(u": "), (class_21::method_132()->field_1167 - var4->field_981->field_287), JRT_LIT(u" / "), class_21::method_132()->field_1168), 14, 18, 1);
        } else if (class_21::method_132()->field_1146 == 7) {
            if (class_69::field_962 == nullptr) {
                class_69::field_962 = class_28::method_282(jrt::concat(JRT_LIT(u"/data/interface/cargo_"), class_21::method_132()->field_1166, JRT_LIT(u".png")));
            }
            class_58::method_518(jrt::concat(class_84::field_1116->method_4(297), JRT_LIT(u": ")), 14, 18, 1);
            class_84::field_1117->drawImage(class_69::field_962, ((14 + class_58::method_523(jrt::concat(class_84::field_1116->method_4(297), JRT_LIT(u": ")))) + 3), 15, 0);
            class_58::method_518(jrt::concat(JRT_LIT(u"x "), var4->field_981->field_289->field_227), ((14 + class_58::method_523(jrt::concat(class_84::field_1116->method_4(297), JRT_LIT(u": ")))) + 23), 18, 1);
        } else if (class_21::method_143() == 1) {
            var11 = class_58::method_532(class_84::field_1116->method_4(337), ((class_84::field_1120 - 5) - 14));
        } else if (class_21::method_143() == 2) {
            var11 = class_58::method_532(class_84::field_1116->method_4(338), ((class_84::field_1120 - 5) - 14));
        } else if (((class_21::method_143() == 5) && (class_21::method_180()->field_1134 != 0)) && var4->field_981->field_280->at(0)->field_185) {
            var11 = class_58::method_532(class_84::field_1116->method_4(340), ((class_84::field_1120 - 5) - 14));
        } else if ((class_21::method_143() == 5) && (class_21::method_180()->field_1134 == 0)) {
            var11 = class_58::method_532(class_84::field_1116->method_4(341), ((class_84::field_1120 - 5) - 14));
        } else if (class_21::method_143() == 6) {
            var11 = class_58::method_532(class_84::field_1116->method_4(339), ((class_84::field_1120 - 5) - 14));
        }
        if ((var11 != nullptr) && class_67::method_581()) {
            class_58::method_521(var11, 14, (18 - ((var11->length > 1) ? 6 : 0)), 1);
        }
    }
    class_69::method_647();
}

void class_69::method_645(bool var0) {
    class_69::field_964 = var0;
}

void class_69::method_646() {
    if (class_69::field_952 != nullptr) {
        class_58::method_519(class_69::field_952, (class_84::field_1120 >> 1), ((class_84::field_1121 + 10) - class_69::field_949), 0, 3);
    }
}

void class_69::method_647() {
    if (((class_69::field_953 != nullptr) && (class_69::field_950 == JRT_LIT(u""))) && (class_69::field_951 == JRT_LIT(u""))) {
        if (class_69::field_963) {
            class_58::method_521(class_69::field_953, 5, ((class_84::field_1121 - 10) - (10 * class_69::field_953->length)), 0);
        } else if (class_69::field_953->length > 1) {
            class_58::method_521(class_69::field_953, 14, 12, 0);
        } else {
            class_58::method_521(class_69::field_953, 14, 18, 0);
        }
    }
    if (class_69::field_964) {
        class_84::field_1117->drawImage(class_33::method_292(), (class_84::field_1120 / 2), 10, 17);
    }
}

void class_69::__dumpFields(jrt::Dumper& d) {
}

