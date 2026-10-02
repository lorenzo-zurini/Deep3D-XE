// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<java::lang::String> class_90::field_1199{};
jrt::Ref<java::lang::String> class_90::field_1200{};
jrt::Ref<jrt::Array<int16_t>> class_90::field_1201{};
jrt::Ref<jrt::Array<int16_t>> class_90::field_1202{};
jrt::Ref<jrt::Array<int16_t>> class_90::field_1203{};
jrt::Ref<jrt::Array<int16_t>> class_90::field_1204{};
jrt::Ref<jrt::Array<int16_t>> class_90::field_1205{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1206{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1207{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1208{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1209{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1210{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1211{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1212{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1213{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1214{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1215{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1216{};
jrt::Ref<jrt::Array<int8_t>> class_90::field_1217{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int8_t>>>> class_90::field_1218{};
jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> class_90::field_1219{};
jrt::Ref<jrt::Array<jrt::Ref<class_19>>> class_90::field_1220{};
jrt::Ref<jrt::Array<jrt::Ref<class_68>>> class_90::field_1221{};
jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_90::field_1222{};
jrt::Ref<jrt::Array<jrt::Ref<class_40>>> class_90::field_1223{};

void class_90::__clinit() {
    class_90::field_1199 = JRT_LIT(u"/data/3d/");
    class_90::field_1200 = JRT_LIT(u"/data/textures/");
    class_90::field_1201 = jrt::arrayOf<int16_t>({int16_t(6754), int16_t(6755), int16_t(6756), int16_t(0), int16_t(0), int16_t(0), int16_t(6760), int16_t(6761), int16_t(6762), int16_t(6763), int16_t(6764), int16_t(6765)});
    class_90::field_1202 = jrt::arrayOf<int16_t>({int16_t(4429), int16_t(4442), int16_t(4426), int16_t(4422), int16_t(4423), int16_t(4430), int16_t(4432), int16_t(4434), int16_t(4440), int16_t(4436), int16_t(4424), int16_t(4438), int16_t(4427), int16_t(4443), int16_t(4444), int16_t(4445), int16_t(4446), int16_t(4447)});
    class_90::field_1203 = jrt::arrayOf<int16_t>({int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(1000), int16_t(1000), int16_t(15000), int16_t(1000), int16_t(1000), int16_t(1000), int16_t(2000)});
    class_90::field_1204 = jrt::arrayOf<int16_t>({int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(20), int16_t(100), int16_t(20), int16_t(4), int16_t(1), int16_t(32000), int16_t(32000), int16_t(5), int16_t(10), int16_t(15)});
    class_90::field_1205 = jrt::arrayOf<int16_t>({int16_t(0), int16_t(1), int16_t(2), int16_t(3), int16_t(4), int16_t(5), int16_t(6), int16_t(7), int16_t(8), int16_t(9), int16_t(10)});
    class_90::field_1206 = jrt::arrayOf<int8_t>({int8_t((-1)), int8_t(60), int8_t(76), int8_t(11), int8_t(31), int8_t(0)});
    class_90::field_1207 = jrt::arrayOf<int8_t>({int8_t(85), int8_t(58), int8_t(75), int8_t(12), int8_t(93), int8_t((-1))});
    class_90::field_1208 = jrt::arrayOf<int8_t>({int8_t(87), int8_t(80), int8_t(68), int8_t(16), int8_t(50), int8_t((-1))});
    class_90::field_1209 = jrt::arrayOf<int8_t>({int8_t(85), int8_t(81), int8_t(68), int8_t(21), int8_t(44), int8_t(3)});
    class_90::field_1210 = jrt::arrayOf<int8_t>({int8_t(85), int8_t(60), int8_t(76), int8_t(11), int8_t(36), int8_t((-1))});
    class_90::field_1211 = jrt::arrayOf<int8_t>({int8_t(84), int8_t(83), int8_t(71), int8_t(25), int8_t(46), int8_t(3)});
    class_90::field_1212 = jrt::arrayOf<int8_t>({int8_t(85), int8_t(82), int8_t(65), int8_t(25), int8_t(43), int8_t((-1))});
    class_90::field_1213 = jrt::arrayOf<int8_t>({int8_t(86), int8_t(78), int8_t(69), int8_t(20), int8_t(51), int8_t((-1))});
    class_90::field_1214 = jrt::arrayOf<int8_t>({int8_t(84), int8_t(28), int8_t(71), int8_t(23), int8_t(52), int8_t((-1))});
    class_90::field_1215 = jrt::arrayOf<int8_t>({int8_t(86), int8_t(83), int8_t(68), int8_t(16), int8_t(48), int8_t((-1))});
    class_90::field_1216 = jrt::arrayOf<int8_t>({int8_t(87), int8_t(83), int8_t(70), int8_t(20), int8_t(41), int8_t((-1))});
    class_90::field_1217 = jrt::arrayOf<int8_t>({int8_t(85), int8_t(82), int8_t(69), int8_t(26), int8_t(47), int8_t((-1))});
    class_90::field_1218 = jrt::arrayOf<jrt::Ref<jrt::Array<int8_t>>>({jrt::Ref<jrt::Array<int8_t>>(nullptr), class_90::field_1206, class_90::field_1207, class_90::field_1208, class_90::field_1209, class_90::field_1210, class_90::field_1211, class_90::field_1212, class_90::field_1213, class_90::field_1214, class_90::field_1215, class_90::field_1216, class_90::field_1217});
    class_90::field_1219 = jrt::arrayOf<jrt::Ref<java::lang::String>>({jrt::Ref<java::lang::String>(nullptr), JRT_LIT(u"M.A.I."), JRT_LIT(u"Ayumi"), JRT_LIT(u"Raymond"), JRT_LIT(u"Pierre"), JRT_LIT(u"Leah"), JRT_LIT(u"Colonist"), JRT_LIT(u"Rebel"), JRT_LIT(u"Fenko"), JRT_LIT(u"Jack"), JRT_LIT(u"Pirate"), JRT_LIT(u"Raoul"), JRT_LIT(u"Colin")});
    jrt::Ref<jrt::Array<int16_t>> var10000 = jrt::arrayOf<int16_t>({int16_t(0), int16_t(1), int16_t(2), int16_t(3), int16_t(4), int16_t(5), int16_t(6), int16_t(7), int16_t(8), int16_t(9), int16_t(10), int16_t(11), int16_t(12), int16_t(13), int16_t(14), int16_t(15), int16_t(16), int16_t(17), int16_t(18), int16_t(19)});
    var10000 = jrt::arrayOf<int16_t>({int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(10000), int16_t(2000), int16_t(2000), int16_t(2000), int16_t(5000), int16_t(1000), int16_t(2000), int16_t(2000), int16_t(2000)});
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> var1 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(11), int16_t(22), int16_t(28), int16_t(5), int16_t(7)}), jrt::arrayOf<int16_t>({int16_t(4), int16_t(30)}), jrt::arrayOf<int16_t>({int16_t(3), int16_t(14)}), jrt::arrayOf<int16_t>({int16_t(9), int16_t(16)})});
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> var2 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(11), int16_t(22), int16_t(28), int16_t(5), int16_t(7)}), jrt::arrayOf<int16_t>({int16_t(4), int16_t(30)}), jrt::arrayOf<int16_t>({int16_t(3), int16_t(14)}), jrt::arrayOf<int16_t>({int16_t(9), int16_t(16)})});
}

void class_90::__init() {
}

void class_90::method_780() {
    class_90::field_1220 = class_49::method_406();
}

jrt::Ref<jrt::Array<jrt::Ref<class_19>>> class_90::method_781() {
    return class_90::field_1220;
}

void class_90::method_782() {
    class_90::field_1221 = class_49::method_407();
}

jrt::Ref<jrt::Array<jrt::Ref<class_68>>> class_90::method_783() {
    return class_90::field_1221;
}

void class_90::method_784() {
    class_90::field_1222 = class_49::method_405();
}

jrt::Ref<jrt::Array<jrt::Ref<class_120>>> class_90::method_785() {
    return class_90::field_1222;
}

void class_90::method_786() {
    class_90::field_1223 = class_49::method_402();
}

jrt::Ref<jrt::Array<jrt::Ref<class_40>>> class_90::method_787() {
    return class_90::field_1223;
}

jrt::Ref<class_68> class_90::method_788(int32_t var0) {
    for (int32_t var1 = 0; var1 < class_90::field_1205->length; var1++) {
        if (var0 == int32_t(class_90::field_1205->at(var1))) {
            return class_90::field_1221->at(var1);
        }
    }
    return jrt::Ref<class_68>(nullptr);
}

jrt::Ref<jrt::Array<int32_t>> class_90::method_789(int32_t var0, int32_t var1) {
    if (((var1 != 0) && (var1 != 1)) && (var1 != 2)) {
        return jrt::Ref<jrt::Array<int32_t>>(nullptr);
    } else {
        {
            switch (var0) {
            case 0:
                ;
            case 1:
                ;
            case 3:
                ;
            case 9:
                ;
            case 10:
                ;
            case 11:
                if (var1 == 0) {
                    return jrt::arrayOf<int32_t>({0, 0});
                } else {
                    if (var1 == 1) {
                        return jrt::arrayOf<int32_t>({1, 1});
                    }
                    return jrt::arrayOf<int32_t>({2, 2});
                }
            case 2:
                ;
            case 4:
                ;
            case 5:
                ;
            case 6:
                ;
            case 7:
                ;
            case 8:
                if (var1 == 0) {
                    return jrt::arrayOf<int32_t>({0, 2});
                } else {
                    if (var1 == 1) {
                        return jrt::arrayOf<int32_t>({3, 5});
                    }
                    return jrt::arrayOf<int32_t>({6, 8});
                }
            default:
                return jrt::Ref<jrt::Array<int32_t>>(nullptr);
            }
        }
    }
}

jrt::Ref<java::lang::String> class_90::method_790(int32_t var0, bool var1) {
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var2{};
    return (var2 = class_49::method_408(var0, var1))->at(class_84::field_1123->nextInt(var2->length));
}

int32_t class_90::method_791() {
    return int32_t(class_90::field_1205->at(class_84::field_1123->nextInt((class_90::field_1205->length - 1))));
}

void class_90::method_792() {
    class_43::method_377(1, jrt::concat(class_90::field_1200, JRT_LIT(u"deep")));
    class_43::method_377(2, jrt::concat(class_90::field_1200, JRT_LIT(u"fx")));
    class_43::method_377(0, jrt::concat(class_90::field_1200, JRT_LIT(u"skybox")));
    class_43::method_378(19, jrt::concat(class_90::field_1199, JRT_LIT(u"aquar")), 2000, 2);
    class_43::method_378(0, jrt::concat(class_90::field_1199, JRT_LIT(u"u0")), 2000, 1);
    class_43::method_378(1, jrt::concat(class_90::field_1199, JRT_LIT(u"u1")), 2000, 1);
    class_43::method_378(2, jrt::concat(class_90::field_1199, JRT_LIT(u"u2")), 2000, 1);
    class_43::method_378(3, jrt::concat(class_90::field_1199, JRT_LIT(u"u3")), 2000, 1);
    class_43::method_378(4, jrt::concat(class_90::field_1199, JRT_LIT(u"u4")), 2000, 1);
    class_43::method_378(5, jrt::concat(class_90::field_1199, JRT_LIT(u"u5")), 2000, 1);
    class_43::method_378(6, jrt::concat(class_90::field_1199, JRT_LIT(u"u6")), 2000, 1);
    class_43::method_378(7, jrt::concat(class_90::field_1199, JRT_LIT(u"u7")), 2000, 1);
    class_43::method_378(8, jrt::concat(class_90::field_1199, JRT_LIT(u"u8")), 2000, 1);
    class_43::method_378(9, jrt::concat(class_90::field_1199, JRT_LIT(u"u9")), 2000, 1);
    class_43::method_378(10, jrt::concat(class_90::field_1199, JRT_LIT(u"u10")), 2000, 1);
    class_43::method_378(11, jrt::concat(class_90::field_1199, JRT_LIT(u"tanker1")), 10000, 1);
    class_43::method_378(14, jrt::concat(class_90::field_1199, JRT_LIT(u"biowaste")), 2000, 2);
    class_43::method_378(13, jrt::concat(class_90::field_1199, JRT_LIT(u"mine")), 2000, 1);
    class_43::method_379(9991, jrt::concat(class_90::field_1199, JRT_LIT(u"skybox")), 0);
    class_43::method_378(16, jrt::concat(class_90::field_1199, JRT_LIT(u"torpedo")), 1000, 1);
    class_43::method_378(17, jrt::concat(class_90::field_1199, JRT_LIT(u"box")), 2000, 1);
    class_43::method_378(15, jrt::concat(class_90::field_1199, JRT_LIT(u"stream")), 5000, 1);
    class_43::method_378(4422, jrt::concat(class_90::field_1199, JRT_LIT(u"manta")), 2000, 2);
    class_43::method_378(4424, jrt::concat(class_90::field_1199, JRT_LIT(u"squid_01")), 2000, 2);
    class_43::method_378(4425, jrt::concat(class_90::field_1199, JRT_LIT(u"squid_02")), 2000, 2);
    class_43::method_378(4423, jrt::concat(class_90::field_1199, JRT_LIT(u"fish_swarm")), 2000, 2);
    class_43::method_378(4426, jrt::concat(class_90::field_1199, JRT_LIT(u"jellyfish")), 1000, 2);
    class_43::method_378(4427, jrt::concat(class_90::field_1199, JRT_LIT(u"whale_01")), 10000, 2);
    class_43::method_378(4428, jrt::concat(class_90::field_1199, JRT_LIT(u"whale_02")), 10000, 2);
    class_43::method_378(4429, jrt::concat(class_90::field_1199, JRT_LIT(u"nautilus")), 2000, 2);
    class_43::method_378(4430, jrt::concat(class_90::field_1199, JRT_LIT(u"anglerfish_01")), 2000, 2);
    class_43::method_378(4431, jrt::concat(class_90::field_1199, JRT_LIT(u"anglerfish_02")), 2000, 2);
    class_43::method_378(4432, jrt::concat(class_90::field_1199, JRT_LIT(u"devilfish_01")), 2000, 2);
    class_43::method_378(4433, jrt::concat(class_90::field_1199, JRT_LIT(u"devilfish_02")), 2000, 2);
    class_43::method_378(4442, jrt::concat(class_90::field_1199, JRT_LIT(u"gulper_eel")), 2000, 2);
    class_43::method_378(4434, jrt::concat(class_90::field_1199, JRT_LIT(u"marlin_01")), 2000, 2);
    class_43::method_378(4435, jrt::concat(class_90::field_1199, JRT_LIT(u"marlin_02")), 2000, 2);
    class_43::method_378(4440, jrt::concat(class_90::field_1199, JRT_LIT(u"shark_01")), 2000, 2);
    class_43::method_378(4441, jrt::concat(class_90::field_1199, JRT_LIT(u"shark_02")), 2000, 2);
    class_43::method_378(4436, jrt::concat(class_90::field_1199, JRT_LIT(u"shrimp_01")), 2000, 2);
    class_43::method_378(4437, jrt::concat(class_90::field_1199, JRT_LIT(u"shrimp_02")), 2000, 2);
    class_43::method_378(4438, jrt::concat(class_90::field_1199, JRT_LIT(u"turtle_01")), 2000, 2);
    class_43::method_378(4439, jrt::concat(class_90::field_1199, JRT_LIT(u"turtle_02")), 2000, 2);
    class_43::method_378(4443, jrt::concat(class_90::field_1199, JRT_LIT(u"alga_gold")), 1000, 2);
    class_43::method_378(4444, jrt::concat(class_90::field_1199, JRT_LIT(u"alga_blue")), 1000, 2);
    class_43::method_378(4445, jrt::concat(class_90::field_1199, JRT_LIT(u"alga_brown")), 1000, 2);
    class_43::method_378(4446, jrt::concat(class_90::field_1199, JRT_LIT(u"alga_red")), 1000, 2);
    class_43::method_378(4447, jrt::concat(class_90::field_1199, JRT_LIT(u"alga_green")), 1000, 2);
    class_43::method_378(3300, jrt::concat(class_90::field_1199, JRT_LIT(u"station_bottom")), 15000, 1);
    class_43::method_378(3301, jrt::concat(class_90::field_1199, JRT_LIT(u"station_bridge_01")), 15000, 1);
    class_43::method_378(3310, jrt::concat(class_90::field_1199, JRT_LIT(u"station_starter")), 15000, 1);
    class_43::method_378(3302, jrt::concat(class_90::field_1199, JRT_LIT(u"station_bridge_02")), 15000, 1);
    class_43::method_378(3303, jrt::concat(class_90::field_1199, JRT_LIT(u"station_cannon")), 15000, 1);
    class_43::method_378(3304, jrt::concat(class_90::field_1199, JRT_LIT(u"station_engine")), 15000, 1);
    class_43::method_378(3305, jrt::concat(class_90::field_1199, JRT_LIT(u"station_habitat_de")), 15000, 1);
    class_43::method_378(3306, jrt::concat(class_90::field_1199, JRT_LIT(u"station_habitat_ve")), 15000, 1);
    class_43::method_378(3307, jrt::concat(class_90::field_1199, JRT_LIT(u"station_hangar_de")), 15000, 1);
    class_43::method_378(3308, jrt::concat(class_90::field_1199, JRT_LIT(u"station_hangar_ve")), 15000, 1);
    class_43::method_378(3309, jrt::concat(class_90::field_1199, JRT_LIT(u"station_sidehabitat")), 15000, 1);
    class_43::method_378(3311, jrt::concat(class_90::field_1199, JRT_LIT(u"station_top")), 15000, 1);
    class_43::method_378(9992, jrt::concat(class_90::field_1199, JRT_LIT(u"explosion")), 2000, 2);
    class_43::method_378(9995, jrt::concat(class_90::field_1199, JRT_LIT(u"fischtod")), 2000, 2);
    class_43::method_378(9993, jrt::concat(class_90::field_1199, JRT_LIT(u"limiter_up")), 5000, 2);
    class_43::method_378(9997, jrt::concat(class_90::field_1199, JRT_LIT(u"limiter_down")), 5000, 2);
    class_43::method_378(9994, jrt::concat(class_90::field_1199, JRT_LIT(u"kapsel")), 5000, 1);
    class_43::method_378(9996, jrt::concat(class_90::field_1199, JRT_LIT(u"trash")), 2000, 1);
    class_43::method_378(6768, jrt::concat(class_90::field_1199, JRT_LIT(u"pfeil")), 2000, 2);
    class_43::method_378(6754, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_0")), 2000, 2);
    class_43::method_378(6755, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_1")), 2000, 2);
    class_43::method_378(6756, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_2")), 2000, 2);
    class_43::method_378(6760, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_6")), 2000, 2);
    class_43::method_378(6761, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_7")), 2000, 2);
    class_43::method_378(6762, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_8")), 2000, 2);
    class_43::method_378(6763, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_9")), 2000, 2);
    class_43::method_378(6764, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_10")), 2000, 2);
    class_43::method_378(6765, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_11")), 2000, 2);
    class_43::method_378(6766, jrt::concat(class_90::field_1199, JRT_LIT(u"eclipse")), 2000, 2);
    class_43::method_378(6767, jrt::concat(class_90::field_1199, JRT_LIT(u"laser_aqua")), 2000, 2);
}

void class_90::method_793() {
    class_90::field_1221 = jrt::Ref<jrt::Array<jrt::Ref<class_68>>>(nullptr);
    class_90::field_1220 = jrt::Ref<jrt::Array<jrt::Ref<class_19>>>(nullptr);
    class_43::method_382();
}

void class_90::__dumpFields(jrt::Dumper& d) {
}

