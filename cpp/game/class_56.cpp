// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> class_56::field_673{};
jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> class_56::field_674{};

void class_56::__clinit() {
    class_56::field_673 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(628), int16_t(0), int16_t(629), int16_t(1), int16_t(630), int16_t(1), int16_t(631)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(640)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(642), int16_t(1), int16_t(643)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(655), int16_t(0), int16_t(656)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(670), int16_t(1), int16_t(671), int16_t(9), int16_t(672)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(684), int16_t(7), int16_t(685), int16_t(1), int16_t(686), int16_t(7), int16_t(687), int16_t(0), int16_t(688), int16_t(7), int16_t(689), int16_t(1), int16_t(690), int16_t(7), int16_t(691)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(701), int16_t(0), int16_t(702), int16_t(1), int16_t(703), int16_t(0), int16_t(704)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(720)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(7), int16_t(742)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(763), int16_t(0), int16_t(764), int16_t(1), int16_t(765)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(3), int16_t(783), int16_t(0), int16_t(784), int16_t(3), int16_t(785), int16_t(1), int16_t(786), int16_t(0), int16_t(787)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(823), int16_t(9), int16_t(824), int16_t(2), int16_t(825)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(851)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(977), int16_t(2), int16_t(978), int16_t(9), int16_t(979), int16_t(0), int16_t(980), int16_t(9), int16_t(981)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(12), int16_t(1001), int16_t(1), int16_t(1002), int16_t(0), int16_t(1003)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(1017), int16_t(9), int16_t(1018), int16_t(0), int16_t(1019), int16_t(9), int16_t(1020), int16_t(0), int16_t(1021), int16_t(9), int16_t(1022), int16_t(0), int16_t(1023)})});
    class_56::field_674 = jrt::arrayOf<jrt::Ref<jrt::Array<int16_t>>>({jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(632), int16_t(1), int16_t(633)}), jrt::arrayOf<int16_t>({int16_t(9), int16_t(634), int16_t(0), int16_t(635), int16_t(9), int16_t(636), int16_t(1), int16_t(637), int16_t(0), int16_t(638)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(639)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(641)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(649)}), jrt::arrayOf<int16_t>({int16_t(9), int16_t(650), int16_t(0), int16_t(651), int16_t(9), int16_t(652), int16_t(0), int16_t(653), int16_t(9), int16_t(654)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(657), int16_t(0), int16_t(658), int16_t(1), int16_t(659)}), jrt::arrayOf<int16_t>({int16_t(6), int16_t(660), int16_t(0), int16_t(661), int16_t(6), int16_t(662), int16_t(1), int16_t(663), int16_t(1), int16_t(664)}), jrt::arrayOf<int16_t>({int16_t(6), int16_t(665), int16_t(0), int16_t(666), int16_t(6), int16_t(667), int16_t(0), int16_t(668), int16_t(6), int16_t(669)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(673), int16_t(1), int16_t(674), int16_t(0), int16_t(675)}), jrt::arrayOf<int16_t>({int16_t(9), int16_t(676), int16_t(1), int16_t(677), int16_t(0), int16_t(678), int16_t(1), int16_t(679), int16_t(0), int16_t(680), int16_t(1), int16_t(681), int16_t(0), int16_t(682), int16_t(1), int16_t(683)}), jrt::arrayOf<int16_t>({int16_t(4), int16_t(692), int16_t(0), int16_t(693), int16_t(1), int16_t(694), int16_t(4), int16_t(695), int16_t(0), int16_t(696), int16_t(4), int16_t(697), int16_t(0), int16_t(698), int16_t(4), int16_t(699), int16_t(0), int16_t(700)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(705), int16_t(0), int16_t(706), int16_t(5), int16_t(707), int16_t(0), int16_t(708), int16_t(1), int16_t(709), int16_t(5), int16_t(710), int16_t(0), int16_t(711), int16_t(5), int16_t(712), int16_t(0), int16_t(713), int16_t(5), int16_t(714), int16_t(0), int16_t(715), int16_t(5), int16_t(716), int16_t(1), int16_t(717), int16_t(0), int16_t(718), int16_t(1), int16_t(719)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(721), int16_t(0), int16_t(722), int16_t(5), int16_t(723), int16_t(0), int16_t(724), int16_t(5), int16_t(725), int16_t(0), int16_t(726), int16_t(5), int16_t(727), int16_t(0), int16_t(728)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(729), int16_t(0), int16_t(730), int16_t(5), int16_t(731), int16_t(0), int16_t(732), int16_t(5), int16_t(733), int16_t(0), int16_t(734), int16_t(5), int16_t(735), int16_t(0), int16_t(736), int16_t(5), int16_t(737)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(738), int16_t(0), int16_t(739), int16_t(1), int16_t(740), int16_t(0), int16_t(741)}), jrt::arrayOf<int16_t>({int16_t(4), int16_t(743), int16_t(1), int16_t(744), int16_t(4), int16_t(745), int16_t(0), int16_t(746), int16_t(4), int16_t(747), int16_t(0), int16_t(748), int16_t(4), int16_t(749), int16_t(1), int16_t(750)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(751), int16_t(0), int16_t(752), int16_t(2), int16_t(753), int16_t(0), int16_t(754), int16_t(2), int16_t(755), int16_t(0), int16_t(756), int16_t(2), int16_t(757), int16_t(0), int16_t(758), int16_t(2), int16_t(759), int16_t(1), int16_t(760), int16_t(0), int16_t(761), int16_t(1), int16_t(762)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(768), int16_t(1), int16_t(769), int16_t(0), int16_t(770)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(771), int16_t(0), int16_t(772), int16_t(2), int16_t(773), int16_t(0), int16_t(774), int16_t(2), int16_t(775), int16_t(0), int16_t(776), int16_t(2), int16_t(777), int16_t(0), int16_t(778), int16_t(2), int16_t(779), int16_t(0), int16_t(780), int16_t(2), int16_t(781), int16_t(1), int16_t(782)}), jrt::arrayOf<int16_t>({int16_t(3), int16_t(790), int16_t(2), int16_t(791), int16_t(3), int16_t(792), int16_t(0), int16_t(793), int16_t(3), int16_t(794), int16_t(1), int16_t(795), int16_t(0), int16_t(796)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(797), int16_t(0), int16_t(798), int16_t(2), int16_t(799), int16_t(0), int16_t(800), int16_t(2), int16_t(801), int16_t(0), int16_t(802), int16_t(2), int16_t(803), int16_t(0), int16_t(804), int16_t(2), int16_t(805)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(808)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(809), int16_t(0), int16_t(810), int16_t(5), int16_t(811), int16_t(0), int16_t(812), int16_t(5), int16_t(813), int16_t(0), int16_t(814), int16_t(1), int16_t(815), int16_t(0), int16_t(816), int16_t(5), int16_t(817), int16_t(2), int16_t(818), int16_t(0), int16_t(819), int16_t(2), int16_t(820), int16_t(0), int16_t(821), int16_t(2), int16_t(822)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(830), int16_t(0), int16_t(831), int16_t(2), int16_t(832), int16_t(5), int16_t(833), int16_t(2), int16_t(834), int16_t(5), int16_t(835), int16_t(0), int16_t(836), int16_t(2), int16_t(837), int16_t(5), int16_t(838), int16_t(2), int16_t(839), int16_t(0), int16_t(840), int16_t(2), int16_t(841)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(842), int16_t(0), int16_t(843), int16_t(3), int16_t(844), int16_t(0), int16_t(845), int16_t(3), int16_t(846), int16_t(1), int16_t(847), int16_t(0), int16_t(848), int16_t(1), int16_t(849), int16_t(0), int16_t(850)}), jrt::arrayOf<int16_t>({int16_t(3), int16_t(852), int16_t(2), int16_t(853), int16_t(3), int16_t(854), int16_t(0), int16_t(855), int16_t(1), int16_t(856), int16_t(0), int16_t(857), int16_t(1), int16_t(858), int16_t(0), int16_t(859), int16_t(3), int16_t(860), int16_t(0), int16_t(861), int16_t(3), int16_t(862), int16_t(0), int16_t(863), int16_t(1), int16_t(864), int16_t(0), int16_t(865), int16_t(3), int16_t(866), int16_t(0), int16_t(867), int16_t(3), int16_t(868), int16_t(0), int16_t(869), int16_t(1), int16_t(870), int16_t(0), int16_t(871), int16_t(3), int16_t(872)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(878), int16_t(0), int16_t(879), int16_t(2), int16_t(880), int16_t(0), int16_t(881), int16_t(2), int16_t(882)}), jrt::arrayOf<int16_t>({int16_t(7), int16_t(885), int16_t(2), int16_t(886)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(887), int16_t(0), int16_t(888), int16_t(4), int16_t(889), int16_t(2), int16_t(890), int16_t(0), int16_t(891), int16_t(2), int16_t(892), int16_t(0), int16_t(893), int16_t(2), int16_t(894), int16_t(0), int16_t(895), int16_t(2), int16_t(896), int16_t(5), int16_t(897), int16_t(4), int16_t(898), int16_t(0), int16_t(899)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(905)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(906), int16_t(5), int16_t(907), int16_t(2), int16_t(908), int16_t(1), int16_t(909), int16_t(0), int16_t(910), int16_t(2), int16_t(911), int16_t(0), int16_t(912), int16_t(2), int16_t(913), int16_t(0), int16_t(914), int16_t(2), int16_t(915), int16_t(0), int16_t(916), int16_t(2), int16_t(917), int16_t(0), int16_t(918), int16_t(2), int16_t(919), int16_t(0), int16_t(920), int16_t(2), int16_t(921), int16_t(0), int16_t(922)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(923), int16_t(0), int16_t(924)}), jrt::arrayOf<int16_t>({int16_t(8), int16_t(925), int16_t(0), int16_t(926), int16_t(8), int16_t(927), int16_t(0), int16_t(928), int16_t(8), int16_t(929), int16_t(0), int16_t(930), int16_t(8), int16_t(931), int16_t(0), int16_t(932), int16_t(8), int16_t(933)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(937)}), jrt::arrayOf<int16_t>({int16_t(8), int16_t(938), int16_t(0), int16_t(939), int16_t(8), int16_t(940), int16_t(0), int16_t(941), int16_t(8), int16_t(942), int16_t(1), int16_t(943), int16_t(0), int16_t(944)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(945), int16_t(0), int16_t(946)}), jrt::arrayOf<int16_t>({int16_t(2), int16_t(947), int16_t(0), int16_t(948), int16_t(2), int16_t(949), int16_t(0), int16_t(950), int16_t(2), int16_t(951), int16_t(0), int16_t(952), int16_t(1), int16_t(953), int16_t(0), int16_t(954), int16_t(1), int16_t(955), int16_t(0), int16_t(956)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(957), int16_t(0), int16_t(958)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(959), int16_t(0), int16_t(960), int16_t(1), int16_t(961), int16_t(0), int16_t(962)}), jrt::arrayOf<int16_t>({int16_t(5), int16_t(963), int16_t(1), int16_t(964), int16_t(0), int16_t(965), int16_t(5), int16_t(966), int16_t(0), int16_t(967), int16_t(1), int16_t(968), int16_t(0), int16_t(969), int16_t(1), int16_t(970)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(975), int16_t(0), int16_t(976)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(985), int16_t(2), int16_t(986), int16_t(0), int16_t(987), int16_t(2), int16_t(988)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(989), int16_t(2), int16_t(990), int16_t(0), int16_t(991), int16_t(2), int16_t(992), int16_t(0), int16_t(993), int16_t(2), int16_t(994), int16_t(0), int16_t(995), int16_t(2), int16_t(996), int16_t(0), int16_t(997), int16_t(2), int16_t(998), int16_t(0), int16_t(999), int16_t(2), int16_t(1000)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(1006), int16_t(12), int16_t(1007)}), jrt::arrayOf<int16_t>({int16_t(1), int16_t(1008), int16_t(0), int16_t(1009), int16_t(5), int16_t(1010), int16_t(0), int16_t(1011), int16_t(5), int16_t(1012), int16_t(0), int16_t(1013), int16_t(5), int16_t(1014), int16_t(0), int16_t(1015), int16_t(5), int16_t(1016)}), jrt::arrayOf<int16_t>({int16_t(0), int16_t(0)})});
}

void class_56::__init(jrt::Ref<class_87> var1, int32_t var2) {
    this->__init();
    this->method_457(var1, var2);
}

void class_56::__init() {
    this->field_683 = jrt::New<class_121>();
    this->field_683->method_940(class_84::field_1116->method_4(233), true);
    this->field_684 = false;
}

void class_56::__init(jrt::Ref<java::lang::String> var1, bool var2) {
    this->__init(var1);
    [&]() { auto __r = this->field_679; jrt::Ref<jrt::Array<int8_t>> __a1 = class_119::method_920(true, ((class_21::method_180()->method_752()) ? 0 : 1)); jrt::Ref<javax::microedition::lcdui::Image> __a2 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr); jrt::Ref<java::lang::String> __a3 = class_84::field_1116->method_4(246); bool __a4 = true; return __r->method_227(__a1, __a2, __a3, __a4); }();
}

void class_56::__init(jrt::Ref<java::lang::String> var1) {
    this->__init();
    if (this->field_679 == nullptr) {
        if (class_84::field_1120 < 176) {
            this->field_679 = jrt::New<class_23>(15, 25, ((class_84::field_1120 - 10) - 20), (((class_84::field_1121 - 22) - 8) - 20), jrt::Ref<java::lang::String>(nullptr));
        } else {
            this->field_679 = jrt::New<class_23>(25, 45, ((class_84::field_1120 - 20) - 30), (((class_84::field_1121 - 22) - 8) - 70), jrt::Ref<java::lang::String>(nullptr));
        }
    }
    this->field_679->method_227(class_90::field_1206, jrt::Ref<javax::microedition::lcdui::Image>(nullptr), JRT_LIT(u"M.A.I."), true);
    this->field_679->method_225(var1);
    this->field_679->method_224();
}

bool class_56::method_455(int32_t var0) {
    return (var0 < class_56::field_673->length) ? (int32_t(class_56::field_673->at(var0)->at(1)) != 0) : false;
}

bool class_56::method_456(int32_t var0) {
    return (var0 < class_56::field_673->length) ? (int32_t(class_56::field_674->at(var0)->at(1)) != 0) : false;
}

void class_56::method_457(jrt::Ref<class_87> var1, int32_t var2) {
    this->field_682 = var1;
    this->field_680 = var2;
    if (var2 == 2) {
        var1->field_1162 = true;
    } else if (var2 == 1) {
        var1->field_1163 = true;
    } else if (var2 == 3) {
        this->field_680 = 1;
    }
    this->field_681 = 0;
    if (this->field_679 == nullptr) {
        this->field_679 = jrt::New<class_23>(15, 25, ((class_84::field_1120 - 10) - 20), (((class_84::field_1121 - 22) - 8) - 40), jrt::Ref<java::lang::String>(nullptr));
    }
    {
        try {
            this->method_466();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> var4 = jrt::cast<java::lang::Exception>(__ex1.t);
                var4->printStackTrace();
            } else {
                throw;
            }
        }
    }
    class_84::field_1122->method_770(2);
}

void class_56::method_458() {
    this->field_675 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
    this->field_676 = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    this->field_679 = jrt::Ref<class_23>(nullptr);
}

bool class_56::method_459(int32_t var1) {
    if (!this->field_684) {
        if ((var1 == 16384) && (!this->method_464())) {
            return false;
        }
        if (var1 == 8192) {
            this->method_465();
        }
    }
    if ((var1 == 256) && ((!this->method_463()) || (!this->method_462()))) {
        this->field_684 = !this->field_684;
        if ((!this->field_684) && this->field_683->method_941()) {
            return false;
        }
    }
    if ((var1 == 4) && this->field_684) {
        this->field_683->method_942();
    }
    if ((var1 == 32) && this->field_684) {
        this->field_683->method_943();
    }
    return true;
}

bool class_56::method_460(int32_t var1, int32_t var2) {
    if ((var1 & 64) != 0) {
        this->field_679->deep3dHeldDown(var2);
    }
    if ((var1 & 2) != 0) {
        this->field_679->deep3dHeldUp(var2);
    }
    return true;
}

int32_t class_56::method_461() {
    if (this->field_682->field_1161) {
        if (this->field_680 == 0) {
            return class_56::field_673->at(class_21::method_143())->length / 2;
        } else {
            return (this->field_680 == 1) ? (class_56::field_674->at(class_21::method_143())->length / 2) : 1;
        }
    } else {
        return 1;
    }
}

bool class_56::method_462() {
    return this->field_681 == 0;
}

bool class_56::method_463() {
    return this->field_681 == (this->method_461() - 1);
}

bool class_56::method_464() {
    if (this->field_681 < (this->method_461() - 1)) {
        this->field_681++;
        this->method_466();
        return true;
    } else {
        return false;
    }
}

bool class_56::method_465() {
    if (this->field_681 > 0) {
        this->field_681--;
        this->method_466();
        return true;
    } else {
        return false;
    }
}

void class_56::method_466() {
    if (this->field_682->field_1161) {
        int16_t var1{};
        if (int32_t((var1 = (this->field_680 == 0) ? class_56::field_673->at(class_21::method_143())->at((2 * this->field_681)) : ((this->field_680 == 1) ? class_56::field_674->at(class_21::method_143())->at((2 * this->field_681)) : int16_t(1)))) == 0) {
            this->field_676 = class_21::method_215();
            this->field_675 = class_21::method_217();
            this->field_678 = class_21::method_213();
        } else {
            this->field_676 = class_90::field_1218->at(int32_t(var1));
            this->field_678 = class_90::field_1219->at(int32_t(var1));
            if (this->field_678 == JRT_LIT(u"Colonist")) {
                this->field_678 = class_84::field_1116->method_4(238);
            } else if (this->field_678 == JRT_LIT(u"Rebel")) {
                this->field_678 = class_84::field_1116->method_4(239);
            } else if (this->field_678 == JRT_LIT(u"Pirate")) {
                this->field_678 = class_84::field_1116->method_4(240);
            }
            this->field_675 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
        }
        if (this->field_680 == 0) {
            this->field_677 = class_84::field_1116->method_4(int32_t(class_56::field_673->at(class_21::method_143())->at(((2 * this->field_681) + 1))));
        } else if (this->field_680 == 1) {
            this->field_677 = class_84::field_1116->method_4(int32_t(class_56::field_674->at(class_21::method_143())->at(((2 * this->field_681) + 1))));
        } else {
            this->field_677 = [&]() { jrt::Ref<java::lang::String> __c1 = class_84::field_1116->method_4(int32_t(class_1::field_18->at(class_84::field_1123->nextInt(class_1::field_18->length)))); jrt::Ref<java::lang::String> __c2 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c3 = class_84::field_1116->method_4(139); return jrt::concat(__c1, __c2, __c3); }();
        }
    } else {
        if ((this->field_681 % 2) == 0) {
            this->field_676 = this->field_682->field_1148;
            this->field_678 = this->field_682->field_1147;
            this->field_675 = jrt::Ref<javax::microedition::lcdui::Image>(nullptr);
        } else {
            this->field_676 = class_21::method_215();
            this->field_675 = class_21::method_217();
            this->field_678 = class_21::method_213();
        }
        if (this->field_680 == 0) {
            this->field_677 = [&]() { jrt::Ref<java::lang::String> __c4 = class_84::field_1116->method_4(int32_t(class_1::field_14->at(this->field_682->field_1146))); jrt::Ref<java::lang::String> __c5 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c6 = class_84::field_1116->method_4(int32_t(class_1::field_15->at(class_84::field_1123->nextInt(class_1::field_15->length)))); return jrt::concat(__c4, __c5, __c6); }();
        } else if (this->field_680 == 1) {
            this->field_677 = [&]() { jrt::Ref<java::lang::String> __c7 = class_84::field_1116->method_4(int32_t(class_1::field_16->at(class_84::field_1123->nextInt(class_1::field_16->length)))); jrt::Ref<java::lang::String> __c8 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c9 = class_84::field_1116->method_4(92); return jrt::concat(__c7, __c8, __c9); }();
        } else {
            this->field_677 = [&]() { jrt::Ref<java::lang::String> __c10 = class_84::field_1116->method_4(int32_t(class_1::field_17->at(class_84::field_1123->nextInt(class_1::field_17->length)))); jrt::Ref<java::lang::String> __c11 = JRT_LIT(u"\n\n"); jrt::Ref<java::lang::String> __c12 = class_84::field_1116->method_4(228); return jrt::concat(__c10, __c11, __c12); }();
        }
    }
    this->field_679->method_227(this->field_676, this->field_675, this->field_678, ((this->field_681 % 2) == 1));
    this->field_679->method_225(class_21::method_219(this->field_677, class_21::method_213()));
    this->field_679->method_224();
}

void class_56::method_467() {
    org::deep3d::GameUi::layer(2);
    org::deep3d::GameUi::controls(2, (-6), (this->method_462() ? 0 : (-7)), (((!this->method_463()) || (!this->method_462())) ? (-5) : 0));
    org::deep3d::GameUi::zone(10, 10, (class_84::field_1120 - 20), (class_84::field_1121 - 40), 100);
    class_67::method_582(10, 10, (class_84::field_1120 - 20), (class_84::field_1121 - 40));
    class_67::method_592(JRT_LIT(u""), 10, 10, (class_84::field_1120 - 20), (class_84::field_1121 - 40), false);
    this->field_679->method_231();
    [&]() { jrt::Ref<java::lang::String> __a1 = (this->method_463() ? ((this->field_682->field_1161 && (this->field_680 == 2)) ? class_84::field_1116->method_4(67) : (((this->field_680 != 2) && (this->field_680 != 1)) ? class_84::field_1116->method_4(78) : class_84::field_1116->method_4(265))) : class_84::field_1116->method_4(77)); jrt::Ref<java::lang::String> __a2 = ((!this->method_462()) ? class_84::field_1116->method_4(76) : JRT_LIT(u"")); bool __a3 = false; bool __a4 = ((!this->method_463()) || (!this->method_462())); return class_67::method_602(__a1, __a2, __a3, __a4); }();
    if (this->field_684) {
        this->field_683->method_944();
    }
}

void class_56::method_468() {
    org::deep3d::GameUi::layer(2);
    org::deep3d::GameUi::controls(2, (-5), (-5), 0);
    class_67::method_583();
    if (class_84::field_1120 < 176) {
        class_67::method_592(JRT_LIT(u""), 10, 10, (class_84::field_1120 - 20), (class_84::field_1121 - 20), true);
    } else {
        class_67::method_592(JRT_LIT(u""), 20, 30, (class_84::field_1120 - 40), (class_84::field_1121 - 60), true);
    }
    this->field_679->method_231();
    if (class_84::field_1120 < 176) {
        class_67::method_586(class_84::field_1116->method_4(41), 10, ((class_84::field_1121 - 10) - 16), (class_84::field_1120 - 20), true, true);
    } else {
        class_67::method_586(class_84::field_1116->method_4(41), 20, ((class_84::field_1121 - 30) - 16), (class_84::field_1120 - 40), true, true);
    }
}

void class_56::__dumpFields(jrt::Dumper& d) {
    d.f("field_675", this->field_675);
    d.f("field_676", this->field_676);
    d.f("field_677", this->field_677);
    d.f("field_678", this->field_678);
    d.f("field_679", this->field_679);
    d.f("field_680", this->field_680);
    d.f("field_681", this->field_681);
    d.f("field_682", this->field_682);
    d.f("field_683", this->field_683);
    d.f("field_684", this->field_684);
}

