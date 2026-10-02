// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_84::field_1079{};
bool class_84::field_1080{};
bool class_84::field_1081{};
bool class_84::field_1082{};
int32_t class_84::field_1083{};
int32_t class_84::field_1084{};
bool class_84::field_1085{};
bool class_84::field_1086{};
bool class_84::field_1087{};
bool class_84::field_1088{};
bool class_84::field_1089{};
bool class_84::field_1090{};
bool class_84::field_1091{};
bool class_84::field_1092{};
bool class_84::field_1093{};
bool class_84::field_1094{};
bool class_84::field_1095{};
bool class_84::field_1096{};
bool class_84::field_1097{};
bool class_84::field_1098{};
bool class_84::field_1099{};
bool class_84::field_1100{};
bool class_84::field_1101{};
bool class_84::field_1102{};
bool class_84::field_1103{};
bool class_84::field_1104{};
bool class_84::field_1105{};
bool class_84::field_1106{};
bool class_84::field_1107{};
jrt::Ref<jrt::Array<int32_t>> class_84::field_1108{};
int32_t class_84::field_1109{};
jrt::Ref<class_4> class_84::field_1110{};
jrt::Ref<class_71> class_84::field_1111{};
jrt::Ref<javax::microedition::lcdui::Display> class_84::field_1112{};
jrt::Ref<class_33> class_84::field_1113{};
bool class_84::field_1114{};
int32_t class_84::field_1115{};
jrt::Ref<class_1> class_84::field_1116{};
jrt::Ref<javax::microedition::lcdui::Graphics> class_84::field_1117{};
jrt::Ref<javax::microedition::lcdui::Canvas> class_84::field_1118{};
jrt::Ref<javax::microedition::midlet::MIDlet> class_84::field_1119{};
int32_t class_84::field_1120{};
int32_t class_84::field_1121{};
jrt::Ref<class_88> class_84::field_1122{};
jrt::Ref<java::util::Random> class_84::field_1123{};
jrt::Ref<java::lang::String> class_84::field_1124{};
bool class_84::field_1125{};
jrt::Ref<class_54> class_84::field_1126{};
jrt::Ref<jrt::Array<jrt::Ref<class_61>>> class_84::field_1127{};

void class_84::__clinit() {
    class_84::field_1079 = jrt::arrayOf<jrt::Ref<java::lang::String>>({JRT_LIT(u"/data/txt/names_human")});
    class_84::field_1080 = true;
    class_84::field_1081 = true;
    class_84::field_1082 = true;
    class_84::field_1083 = 2;
    class_84::field_1084 = 1;
    class_84::field_1114 = false;
    class_84::field_1115 = (-1);
    class_84::field_1124 = JRT_LIT(u"");
    class_84::field_1125 = false;
}

void class_84::__init() {
}

void class_84::method_736(int32_t var0) {
    if (class_84::field_1081) {
        class_84::field_1112->vibrate(var0);
    }
}

void class_84::method_737() {
    class_84::field_1085 = false;
    class_84::field_1086 = false;
    class_84::field_1087 = false;
    class_84::field_1088 = false;
    class_84::field_1089 = false;
    class_84::field_1090 = false;
    class_84::field_1091 = false;
    class_84::field_1092 = false;
    class_84::field_1093 = false;
    class_84::field_1094 = false;
    class_84::field_1095 = false;
    class_84::field_1096 = false;
    class_84::field_1097 = false;
    class_84::field_1098 = false;
    class_84::field_1099 = false;
    class_84::field_1100 = false;
    class_84::field_1101 = false;
    class_84::field_1102 = false;
    class_84::field_1103 = false;
    class_84::field_1104 = false;
    class_84::field_1105 = false;
    class_84::field_1106 = false;
    class_84::field_1107 = false;
}

void class_84::__dumpFields(jrt::Dumper& d) {
}

