// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<jrt::Array<int16_t>> class_16::field_150{};

void class_16::__clinit() {
    class_16::field_150 = jrt::arrayOf<int16_t>({int16_t(0), int16_t(6), int16_t(13), int16_t(19), int16_t(25), int16_t(31), int16_t(38), int16_t(44), int16_t(50), int16_t(57), int16_t(63), int16_t(69), int16_t(75), int16_t(82), int16_t(88), int16_t(94), int16_t(101), int16_t(107), int16_t(113), int16_t(119), int16_t(126), int16_t(132), int16_t(138), int16_t(144), int16_t(151), int16_t(157), int16_t(163), int16_t(170), int16_t(176), int16_t(182), int16_t(188), int16_t(195), int16_t(201), int16_t(207), int16_t(214), int16_t(220), int16_t(226), int16_t(232), int16_t(239), int16_t(245), int16_t(251), int16_t(257), int16_t(264), int16_t(270), int16_t(276), int16_t(283), int16_t(289), int16_t(295), int16_t(301), int16_t(308), int16_t(314), int16_t(320), int16_t(326), int16_t(333), int16_t(339), int16_t(345), int16_t(351), int16_t(358), int16_t(364), int16_t(370), int16_t(376), int16_t(383), int16_t(389), int16_t(395), int16_t(401), int16_t(408), int16_t(414), int16_t(420), int16_t(426), int16_t(433), int16_t(439), int16_t(445), int16_t(451), int16_t(458), int16_t(464), int16_t(470), int16_t(476), int16_t(483), int16_t(489), int16_t(495), int16_t(501), int16_t(508), int16_t(514), int16_t(520), int16_t(526), int16_t(533), int16_t(539), int16_t(545), int16_t(551), int16_t(557), int16_t(564), int16_t(570), int16_t(576), int16_t(582), int16_t(589), int16_t(595), int16_t(601), int16_t(607), int16_t(613), int16_t(620), int16_t(626), int16_t(632), int16_t(638), int16_t(644), int16_t(651), int16_t(657), int16_t(663), int16_t(669), int16_t(675), int16_t(682), int16_t(688), int16_t(694), int16_t(700), int16_t(706), int16_t(713), int16_t(719), int16_t(725), int16_t(731), int16_t(737), int16_t(744), int16_t(750), int16_t(756), int16_t(762), int16_t(768), int16_t(774), int16_t(781), int16_t(787), int16_t(793), int16_t(799), int16_t(805), int16_t(811), int16_t(818), int16_t(824), int16_t(830), int16_t(836), int16_t(842), int16_t(848), int16_t(854), int16_t(861), int16_t(867), int16_t(873), int16_t(879), int16_t(885), int16_t(891), int16_t(897), int16_t(904), int16_t(910), int16_t(916), int16_t(922), int16_t(928), int16_t(934), int16_t(940), int16_t(946), int16_t(953), int16_t(959), int16_t(965), int16_t(971), int16_t(977), int16_t(983), int16_t(989), int16_t(995), int16_t(1001), int16_t(1007), int16_t(1014), int16_t(1020), int16_t(1026), int16_t(1032), int16_t(1038), int16_t(1044), int16_t(1050), int16_t(1056), int16_t(1062), int16_t(1068), int16_t(1074), int16_t(1080), int16_t(1086), int16_t(1092), int16_t(1099), int16_t(1105), int16_t(1111), int16_t(1117), int16_t(1123), int16_t(1129), int16_t(1135), int16_t(1141), int16_t(1147), int16_t(1153), int16_t(1159), int16_t(1165), int16_t(1171), int16_t(1177), int16_t(1183), int16_t(1189), int16_t(1195), int16_t(1201), int16_t(1207), int16_t(1213), int16_t(1219), int16_t(1225), int16_t(1231), int16_t(1237), int16_t(1243), int16_t(1249), int16_t(1255), int16_t(1261), int16_t(1267), int16_t(1273), int16_t(1279), int16_t(1285), int16_t(1291), int16_t(1297), int16_t(1303), int16_t(1309), int16_t(1315), int16_t(1321), int16_t(1327), int16_t(1332), int16_t(1338), int16_t(1344), int16_t(1350), int16_t(1356), int16_t(1362), int16_t(1368), int16_t(1374), int16_t(1380), int16_t(1386), int16_t(1392), int16_t(1398), int16_t(1404), int16_t(1409), int16_t(1415), int16_t(1421), int16_t(1427), int16_t(1433), int16_t(1439), int16_t(1445), int16_t(1451), int16_t(1457), int16_t(1462), int16_t(1468), int16_t(1474), int16_t(1480), int16_t(1486), int16_t(1492), int16_t(1498), int16_t(1503), int16_t(1509), int16_t(1515), int16_t(1521), int16_t(1527), int16_t(1533), int16_t(1538), int16_t(1544), int16_t(1550), int16_t(1556), int16_t(1562), int16_t(1567), int16_t(1573), int16_t(1579), int16_t(1585), int16_t(1591), int16_t(1596), int16_t(1602), int16_t(1608), int16_t(1614), int16_t(1620), int16_t(1625), int16_t(1631), int16_t(1637), int16_t(1643), int16_t(1648), int16_t(1654), int16_t(1660), int16_t(1666), int16_t(1671), int16_t(1677), int16_t(1683), int16_t(1689), int16_t(1694), int16_t(1700), int16_t(1706), int16_t(1711), int16_t(1717), int16_t(1723), int16_t(1729), int16_t(1734), int16_t(1740), int16_t(1746), int16_t(1751), int16_t(1757), int16_t(1763), int16_t(1768), int16_t(1774), int16_t(1780), int16_t(1785), int16_t(1791), int16_t(1797), int16_t(1802), int16_t(1808), int16_t(1813), int16_t(1819), int16_t(1825), int16_t(1830), int16_t(1836), int16_t(1842), int16_t(1847), int16_t(1853), int16_t(1858), int16_t(1864), int16_t(1870), int16_t(1875), int16_t(1881), int16_t(1886), int16_t(1892), int16_t(1898), int16_t(1903), int16_t(1909), int16_t(1914), int16_t(1920), int16_t(1925), int16_t(1931), int16_t(1936), int16_t(1942), int16_t(1947), int16_t(1953), int16_t(1958), int16_t(1964), int16_t(1970), int16_t(1975), int16_t(1981), int16_t(1986), int16_t(1992), int16_t(1997), int16_t(2002), int16_t(2008), int16_t(2013), int16_t(2019), int16_t(2024), int16_t(2030), int16_t(2035), int16_t(2041), int16_t(2046), int16_t(2052), int16_t(2057), int16_t(2062), int16_t(2068), int16_t(2073), int16_t(2079), int16_t(2084), int16_t(2090), int16_t(2095), int16_t(2100), int16_t(2106), int16_t(2111), int16_t(2117), int16_t(2122), int16_t(2127), int16_t(2133), int16_t(2138), int16_t(2143), int16_t(2149), int16_t(2154), int16_t(2159), int16_t(2165), int16_t(2170), int16_t(2175), int16_t(2181), int16_t(2186), int16_t(2191), int16_t(2197), int16_t(2202), int16_t(2207), int16_t(2213), int16_t(2218), int16_t(2223), int16_t(2228), int16_t(2234), int16_t(2239), int16_t(2244), int16_t(2249), int16_t(2255), int16_t(2260), int16_t(2265), int16_t(2270), int16_t(2276), int16_t(2281), int16_t(2286), int16_t(2291), int16_t(2296), int16_t(2302), int16_t(2307), int16_t(2312), int16_t(2317), int16_t(2322), int16_t(2328), int16_t(2333), int16_t(2338), int16_t(2343), int16_t(2348), int16_t(2353), int16_t(2359), int16_t(2364), int16_t(2369), int16_t(2374), int16_t(2379), int16_t(2384), int16_t(2389), int16_t(2394), int16_t(2399), int16_t(2405), int16_t(2410), int16_t(2415), int16_t(2420), int16_t(2425), int16_t(2430), int16_t(2435), int16_t(2440), int16_t(2445), int16_t(2450), int16_t(2455), int16_t(2460), int16_t(2465), int16_t(2470), int16_t(2475), int16_t(2480), int16_t(2485), int16_t(2490), int16_t(2495), int16_t(2500), int16_t(2505), int16_t(2510), int16_t(2515), int16_t(2520), int16_t(2525), int16_t(2530), int16_t(2535), int16_t(2540), int16_t(2545), int16_t(2550), int16_t(2555), int16_t(2559), int16_t(2564), int16_t(2569), int16_t(2574), int16_t(2579), int16_t(2584), int16_t(2589), int16_t(2594), int16_t(2598), int16_t(2603), int16_t(2608), int16_t(2613), int16_t(2618), int16_t(2623), int16_t(2628), int16_t(2632), int16_t(2637), int16_t(2642), int16_t(2647), int16_t(2652), int16_t(2656), int16_t(2661), int16_t(2666), int16_t(2671), int16_t(2675), int16_t(2680), int16_t(2685), int16_t(2690), int16_t(2694), int16_t(2699), int16_t(2704), int16_t(2709), int16_t(2713), int16_t(2718), int16_t(2723), int16_t(2727), int16_t(2732), int16_t(2737), int16_t(2741), int16_t(2746), int16_t(2751), int16_t(2755), int16_t(2760), int16_t(2765), int16_t(2769), int16_t(2774), int16_t(2779), int16_t(2783), int16_t(2788), int16_t(2792), int16_t(2797), int16_t(2802), int16_t(2806), int16_t(2811), int16_t(2815), int16_t(2820), int16_t(2824), int16_t(2829), int16_t(2833), int16_t(2838), int16_t(2843), int16_t(2847), int16_t(2852), int16_t(2856), int16_t(2861), int16_t(2865), int16_t(2870), int16_t(2874), int16_t(2878), int16_t(2883), int16_t(2887), int16_t(2892), int16_t(2896), int16_t(2901), int16_t(2905), int16_t(2910), int16_t(2914), int16_t(2918), int16_t(2923), int16_t(2927), int16_t(2932), int16_t(2936), int16_t(2940), int16_t(2945), int16_t(2949), int16_t(2953), int16_t(2958), int16_t(2962), int16_t(2967), int16_t(2971), int16_t(2975), int16_t(2979), int16_t(2984), int16_t(2988), int16_t(2992), int16_t(2997), int16_t(3001), int16_t(3005), int16_t(3009), int16_t(3014), int16_t(3018), int16_t(3022), int16_t(3026), int16_t(3031), int16_t(3035), int16_t(3039), int16_t(3043), int16_t(3048), int16_t(3052), int16_t(3056), int16_t(3060), int16_t(3064), int16_t(3068), int16_t(3073), int16_t(3077), int16_t(3081), int16_t(3085), int16_t(3089), int16_t(3093), int16_t(3097), int16_t(3102), int16_t(3106), int16_t(3110), int16_t(3114), int16_t(3118), int16_t(3122), int16_t(3126), int16_t(3130), int16_t(3134), int16_t(3138), int16_t(3142), int16_t(3146), int16_t(3150), int16_t(3154), int16_t(3158), int16_t(3162), int16_t(3166), int16_t(3170), int16_t(3174), int16_t(3178), int16_t(3182), int16_t(3186), int16_t(3190), int16_t(3194), int16_t(3198), int16_t(3202), int16_t(3206), int16_t(3210), int16_t(3214), int16_t(3217), int16_t(3221), int16_t(3225), int16_t(3229), int16_t(3233), int16_t(3237), int16_t(3241), int16_t(3244), int16_t(3248), int16_t(3252), int16_t(3256), int16_t(3260), int16_t(3264), int16_t(3267), int16_t(3271), int16_t(3275), int16_t(3279), int16_t(3282), int16_t(3286), int16_t(3290), int16_t(3294), int16_t(3297), int16_t(3301), int16_t(3305), int16_t(3309), int16_t(3312), int16_t(3316), int16_t(3320), int16_t(3323), int16_t(3327), int16_t(3331), int16_t(3334), int16_t(3338), int16_t(3342), int16_t(3345), int16_t(3349), int16_t(3352), int16_t(3356), int16_t(3360), int16_t(3363), int16_t(3367), int16_t(3370), int16_t(3374), int16_t(3378), int16_t(3381), int16_t(3385), int16_t(3388), int16_t(3392), int16_t(3395), int16_t(3399), int16_t(3402), int16_t(3406), int16_t(3409), int16_t(3413), int16_t(3416), int16_t(3420), int16_t(3423), int16_t(3426), int16_t(3430), int16_t(3433), int16_t(3437), int16_t(3440), int16_t(3444), int16_t(3447), int16_t(3450), int16_t(3454), int16_t(3457), int16_t(3461), int16_t(3464), int16_t(3467), int16_t(3471), int16_t(3474), int16_t(3477), int16_t(3481), int16_t(3484), int16_t(3487), int16_t(3490), int16_t(3494), int16_t(3497), int16_t(3500), int16_t(3504), int16_t(3507), int16_t(3510), int16_t(3513), int16_t(3516), int16_t(3520), int16_t(3523), int16_t(3526), int16_t(3529), int16_t(3532), int16_t(3536), int16_t(3539), int16_t(3542), int16_t(3545), int16_t(3548), int16_t(3551), int16_t(3555), int16_t(3558), int16_t(3561), int16_t(3564), int16_t(3567), int16_t(3570), int16_t(3573), int16_t(3576), int16_t(3579), int16_t(3582), int16_t(3585), int16_t(3588), int16_t(3591), int16_t(3594), int16_t(3597), int16_t(3600), int16_t(3603), int16_t(3606), int16_t(3609), int16_t(3612), int16_t(3615), int16_t(3618), int16_t(3621), int16_t(3624), int16_t(3627), int16_t(3630), int16_t(3633), int16_t(3636), int16_t(3639), int16_t(3642), int16_t(3644), int16_t(3647), int16_t(3650), int16_t(3653), int16_t(3656), int16_t(3659), int16_t(3661), int16_t(3664), int16_t(3667), int16_t(3670), int16_t(3673), int16_t(3675), int16_t(3678), int16_t(3681), int16_t(3684), int16_t(3686), int16_t(3689), int16_t(3692), int16_t(3695), int16_t(3697), int16_t(3700), int16_t(3703), int16_t(3705), int16_t(3708), int16_t(3711), int16_t(3713), int16_t(3716), int16_t(3719), int16_t(3721), int16_t(3724), int16_t(3727), int16_t(3729), int16_t(3732), int16_t(3734), int16_t(3737), int16_t(3739), int16_t(3742), int16_t(3745), int16_t(3747), int16_t(3750), int16_t(3752), int16_t(3755), int16_t(3757), int16_t(3760), int16_t(3762), int16_t(3765), int16_t(3767), int16_t(3770), int16_t(3772), int16_t(3775), int16_t(3777), int16_t(3779), int16_t(3782), int16_t(3784), int16_t(3787), int16_t(3789), int16_t(3791), int16_t(3794), int16_t(3796), int16_t(3798), int16_t(3801), int16_t(3803), int16_t(3805), int16_t(3808), int16_t(3810), int16_t(3812), int16_t(3815), int16_t(3817), int16_t(3819), int16_t(3822), int16_t(3824), int16_t(3826), int16_t(3828), int16_t(3831), int16_t(3833), int16_t(3835), int16_t(3837), int16_t(3839), int16_t(3842), int16_t(3844), int16_t(3846), int16_t(3848), int16_t(3850), int16_t(3852), int16_t(3854), int16_t(3857), int16_t(3859), int16_t(3861), int16_t(3863), int16_t(3865), int16_t(3867), int16_t(3869), int16_t(3871), int16_t(3873), int16_t(3875), int16_t(3877), int16_t(3879), int16_t(3881), int16_t(3883), int16_t(3885), int16_t(3887), int16_t(3889), int16_t(3891), int16_t(3893), int16_t(3895), int16_t(3897), int16_t(3899), int16_t(3901), int16_t(3903), int16_t(3905), int16_t(3907), int16_t(3909), int16_t(3910), int16_t(3912), int16_t(3914), int16_t(3916), int16_t(3918), int16_t(3920), int16_t(3921), int16_t(3923), int16_t(3925), int16_t(3927), int16_t(3929), int16_t(3930), int16_t(3932), int16_t(3934), int16_t(3936), int16_t(3937), int16_t(3939), int16_t(3941), int16_t(3943), int16_t(3944), int16_t(3946), int16_t(3948), int16_t(3949), int16_t(3951), int16_t(3953), int16_t(3954), int16_t(3956), int16_t(3958), int16_t(3959), int16_t(3961), int16_t(3962), int16_t(3964), int16_t(3965), int16_t(3967), int16_t(3969), int16_t(3970), int16_t(3972), int16_t(3973), int16_t(3975), int16_t(3976), int16_t(3978), int16_t(3979), int16_t(3981), int16_t(3982), int16_t(3984), int16_t(3985), int16_t(3987), int16_t(3988), int16_t(3989), int16_t(3991), int16_t(3992), int16_t(3994), int16_t(3995), int16_t(3996), int16_t(3998), int16_t(3999), int16_t(4001), int16_t(4002), int16_t(4003), int16_t(4005), int16_t(4006), int16_t(4007), int16_t(4008), int16_t(4010), int16_t(4011), int16_t(4012), int16_t(4014), int16_t(4015), int16_t(4016), int16_t(4017), int16_t(4019), int16_t(4020), int16_t(4021), int16_t(4022), int16_t(4023), int16_t(4024), int16_t(4026), int16_t(4027), int16_t(4028), int16_t(4029), int16_t(4030), int16_t(4031), int16_t(4032), int16_t(4034), int16_t(4035), int16_t(4036), int16_t(4037), int16_t(4038), int16_t(4039), int16_t(4040), int16_t(4041), int16_t(4042), int16_t(4043), int16_t(4044), int16_t(4045), int16_t(4046), int16_t(4047), int16_t(4048), int16_t(4049), int16_t(4050), int16_t(4051), int16_t(4052), int16_t(4053), int16_t(4053), int16_t(4054), int16_t(4055), int16_t(4056), int16_t(4057), int16_t(4058), int16_t(4059), int16_t(4060), int16_t(4060), int16_t(4061), int16_t(4062), int16_t(4063), int16_t(4064), int16_t(4064), int16_t(4065), int16_t(4066), int16_t(4067), int16_t(4067), int16_t(4068), int16_t(4069), int16_t(4070), int16_t(4070), int16_t(4071), int16_t(4072), int16_t(4072), int16_t(4073), int16_t(4074), int16_t(4074), int16_t(4075), int16_t(4076), int16_t(4076), int16_t(4077), int16_t(4077), int16_t(4078), int16_t(4079), int16_t(4079), int16_t(4080), int16_t(4080), int16_t(4081), int16_t(4081), int16_t(4082), int16_t(4082), int16_t(4083), int16_t(4083), int16_t(4084), int16_t(4084), int16_t(4085), int16_t(4085), int16_t(4086), int16_t(4086), int16_t(4087), int16_t(4087), int16_t(4088), int16_t(4088), int16_t(4088), int16_t(4089), int16_t(4089), int16_t(4089), int16_t(4090), int16_t(4090), int16_t(4090), int16_t(4091), int16_t(4091), int16_t(4091), int16_t(4092), int16_t(4092), int16_t(4092), int16_t(4092), int16_t(4093), int16_t(4093), int16_t(4093), int16_t(4093), int16_t(4094), int16_t(4094), int16_t(4094), int16_t(4094), int16_t(4094), int16_t(4095), int16_t(4095), int16_t(4095), int16_t(4095), int16_t(4095), int16_t(4095), int16_t(4095), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096), int16_t(4096)});
}

void class_16::__init() {
}

int32_t class_16::method_91(int32_t var0) {
    if ((var0 = var0 & 4095) >= 3072) {
        return -int32_t(class_16::field_150->at((4096 - var0)));
    } else if (var0 >= 2048) {
        return -int32_t(class_16::field_150->at((var0 - 2048)));
    } else {
        return int32_t(((var0 >= 1024) ? class_16::field_150->at((2048 - var0)) : class_16::field_150->at(var0)));
    }
}

int32_t class_16::method_92(int32_t var0) {
    var0 -= 1024;
    if ((var0 = var0 & 4095) >= 3072) {
        return int32_t(class_16::field_150->at((4096 - var0)));
    } else if (var0 >= 2048) {
        return int32_t(class_16::field_150->at((var0 - 2048)));
    } else {
        return (var0 >= 1024) ? (-int32_t(class_16::field_150->at((2048 - var0)))) : (-int32_t(class_16::field_150->at(var0)));
    }
}

int32_t class_16::method_93(int32_t var0) {
    int32_t var1{};
    return ((var1 = 4096 - ((var0 * var0) >> 12)) <= 0) ? class_16::method_94(var0, 0) : class_16::method_94(var0, class_16::method_96(int64_t(var1)));
}

int32_t class_16::method_94(int32_t var0, int32_t var1) {
    bool var2 = false;
    int32_t var3 = class_16::method_100(var0) + 1;
    if (var1 >= 0) {
        int32_t var6 = jrt::div(((var1 - var3) << 12), (var1 + var3));
        return (var0 < 0) ? (-(512 - ((512 * var6) >> 12))) : (512 - ((512 * var6) >> 12));
    } else {
        int32_t var4 = jrt::div(((var1 + var3) << 12), (var3 - var1));
        bool var5 = false;
        return (var0 < 0) ? (-(1536 - ((512 * var4) >> 12))) : (1536 - ((512 * var4) >> 12));
    }
}

int32_t class_16::method_95(int32_t var0) {
    int32_t var1 = var0 >> 1;
    int32_t var2 = java::lang::Float::floatToIntBits((float(var0) * 2.4414062E-4f));
    int32_t var4{};
    return class_16::method_100((([&]() { int32_t __l1 = (var0 = jrt::f2i((java::lang::Float::intBitsToFloat(var4 = 1597463174 - (var2 >> 1)) * 4096.0f))); int32_t __r1 = (6144 - ((((var1 * var0) >> 12) * var0) >> 12)); return (__l1 * __r1); }()) >> 12));
}

int32_t class_16::method_96(int64_t var0) {
    if (var0 == int64_t(0)) {
        return 0;
    } else {
        bool var2 = false;
        int32_t var3 = 2147483647;
        int64_t var4 = int64_t(2147483647);
        for (int32_t var6 = 30; var6 >= 0; var6--) {
            var3 >>= 1;
            int64_t var7{};
            if ((var7 = var0 - ((var4 * var4) >> 12)) > int64_t(0)) {
                var4 += int64_t(var3);
            } else {
                if (var7 >= int64_t(0)) {
                    return int32_t(var4);
                }
                var4 -= int64_t(var3);
            }
        }
        return int32_t(var4);
    }
}

int32_t class_16::method_97(int32_t var0, int32_t var1) {
    return (var0 >= var1) ? var0 : var1;
}

int32_t class_16::method_98(int32_t var0, int32_t var1) {
    return (var0 <= var1) ? var0 : var1;
}

float class_16::method_99(float var0, float var1) {
    return (var0 <= var1) ? var0 : var1;
}

int32_t class_16::method_100(int32_t var0) {
    return (var0 < 0) ? (-var0) : var0;
}

void class_16::__dumpFields(jrt::Dumper& d) {
}

