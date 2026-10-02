// Translated from the decompiled Java of the game (2026-10); now the source.
#pragma once
#include "deep3d/runtime.h"

class class_0;
class class_91;
class class_98;
class class_99;
class class_100;
class class_101;
class class_102;
class class_103;
class class_104;
class class_105;
class class_106;
class class_107;
class class_108;
class class_109;
class class_10;
class class_110;
class class_111;
class class_112;
class class_113;
class class_114;
class class_115;
class class_116;
class class_117;
class class_118;
class class_119;
class class_11;
class class_120;
class class_121;
class class_122;
class class_123;
class class_124;
class class_12;
class class_13;
class class_14;
class class_15;
class class_16;
class class_17;
class class_18;
class class_19;
class class_1;
class class_20;
class class_21;
class class_22;
class class_23;
class class_24;
class class_25;
class class_26;
class class_27;
class class_28;
class class_29;
class class_2;
class class_30;
class class_31;
class class_32;
class class_33;
class class_34;
class class_35;
class class_36;
class class_37;
class class_38;
class class_39;
class class_3;
class class_40;
class class_41;
class class_42;
class class_43;
class class_44;
class class_45;
class class_46;
class class_47;
class class_48;
class class_49;
class class_4;
class class_50;
class class_51;
class class_51__anon1;
class class_51__anon2;
class class_52;
class class_53;
class class_54;
class class_55;
class class_56;
class class_57;
class class_58;
class class_59;
class class_5;
class class_60;
class class_61;
class class_62;
class class_63;
class class_64;
class class_65;
class class_66;
class class_67;
class class_68;
class class_69;
class class_6;
class class_70;
class class_71;
class class_72;
class class_73;
class class_74;
class class_75;
class class_76;
class class_77;
class class_78;
class class_79;
class class_7;
class class_80;
class class_81;
class class_82;
class class_83;
class class_84;
class class_85;
class class_86;
class class_87;
class class_88;
class class_89;
class class_8;
class class_90;
class class_92;
class class_93;
class class_94;
class class_95;
class class_96;
class class_97;
class class_9;
class Deep3dMenu;
class DeepMIDlet;

class class_0 {
public:
    virtual ~class_0() = default;
    virtual void method_0() = 0;
    virtual bool method_1() = 0;
    static void __clinit();
};

class class_91 : public java::lang::Object {
public:
    int16_t field_1224{};
    jrt::Ref<class_37> field_1225{};
    jrt::Ref<class_108> field_1226{};
    int32_t field_1227{};
    bool field_1228{};
    jrt::Ref<class_26> field_1229{};
    jrt::Ref<class_18> field_1230{};
    jrt::Ref<class_85> field_1231{};
    jrt::Ref<class_3> field_1232{};
    jrt::Ref<class_3> field_1233{};
    int32_t field_1234{};
    int32_t field_1235{};
    int32_t field_1236{};
    bool field_1237{};
    bool field_1238{};
    bool field_1239{};
    jrt::Ref<class_120> field_1240{};
    void __init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7);
    virtual void method_794();
    virtual void method_795(bool var1);
    virtual void method_796(int32_t var1);
    virtual void method_797(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1);
    virtual void method_798(jrt::Ref<class_9> var1, int32_t var2);
    virtual jrt::Ref<class_3> method_799(jrt::Ref<class_3> var1);
    virtual bool method_800();
    virtual bool method_801();
    virtual void method_802();
    virtual void method_803();
    virtual void method_804();
    virtual void method_805(int64_t var1) = 0;
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3) = 0;
    virtual bool method_807(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_808(jrt::Ref<class_3> var1);
    virtual void method_809();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_91"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_98 : public class_91 {
public:
    static jrt::Ref<class_3> field_1299;
    int32_t field_1300{};
    int32_t field_1301{};
    int32_t field_1302{};
    void __init(int32_t var1, jrt::Ref<class_108> var2, int32_t var3, int32_t var4, int32_t var5);
    virtual void method_805(int64_t var1);
    virtual jrt::Ref<class_3> method_799(jrt::Ref<class_3> var1);
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_98"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_99 : public class_98 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_29>>> field_1303{};
    bool field_1304{};
    bool field_1305{};
    bool field_1306{};
    void __init(int32_t var1, jrt::Ref<class_108> var2, int32_t var3, int32_t var4, int32_t var5);
    virtual void method_821();
    virtual void method_822(int32_t var1);
    virtual void method_809();
    virtual void method_805(int64_t var1);
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_823();
    virtual void method_824();
    virtual bool method_807(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_808(jrt::Ref<class_3> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_99"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_100 : public class_99 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_1307{};
    jrt::Ref<jrt::Array<int32_t>> field_1308{};
    int32_t field_1309{};
    int32_t field_1310{};
    void __init(jrt::Ref<class_86> var1);
    jrt::Ref<jrt::Array<int32_t>> method_825(int32_t var1, bool var2);
    virtual void method_805(int64_t var1);
    virtual void method_809();
    virtual jrt::Ref<class_3> method_799(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_108> method_826();
    virtual void method_827(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_828(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_807(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_808(jrt::Ref<class_3> var1);
    virtual void method_794();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_100"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_101 : public class_91 {
public:
    static jrt::Ref<class_3> field_1311;
    jrt::Ref<class_40> field_1312{};
    int32_t field_1313{};
    int32_t field_1314{};
    int32_t field_1315{};
    int32_t field_1316{};
    jrt::Ref<class_108> field_1317{};
    static jrt::Ref<jrt::Array<int32_t>> field_1318;
    static jrt::Ref<jrt::Array<int32_t>> field_1319;
    static jrt::Ref<class_3> field_1320;
    static jrt::Ref<class_3> field_1321;
    static jrt::Ref<class_57> field_1322;
    jrt::Ref<class_57> field_1323{};
    bool field_1324{};
    bool field_1325{};
    bool field_1326{};
    int32_t field_1327{};
    float field_1328{};
    int32_t field_1329{};
    bool field_1330{};
    bool field_1331{};
    int32_t field_1332{};
    bool field_1333{};
    int32_t field_1334{};
    void __init(int32_t var1, jrt::Ref<class_108> var2, jrt::Ref<class_40> var3, int32_t var4, int32_t var5, int32_t var6);
    virtual void method_829(bool var1);
    virtual void method_830(int32_t var1);
    virtual void method_831();
    virtual int32_t method_832();
    virtual bool method_833();
    virtual void method_834(int32_t var1);
    virtual void method_805(int64_t var1);
    bool method_835();
    void method_836();
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_101"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_102 : public java::lang::Object {
public:
    int32_t field_1335{};
    jrt::Ref<class_103> field_1336{};
    jrt::Ref<class_102> field_1337{};
    bool field_1338{};
    bool field_1339{};
    bool field_1340{};
    jrt::Ref<class_57> field_1341{};
    jrt::Ref<class_57> field_1342{};
    jrt::Ref<class_15> field_1343{};
    int32_t field_1344{};
    void __init();
    void __init(jrt::Ref<class_102> var1);
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) = 0;
    virtual void method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2) = 0;
    virtual void method_839(bool var1) = 0;
    virtual jrt::Ref<class_102> method_840() = 0;
    virtual void method_841();
    virtual jrt::Ref<java::lang::String> toString();
    virtual jrt::Ref<java::lang::String> method_842(jrt::Ref<java::lang::String> var1, int32_t var2) = 0;
    virtual void method_843(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_844(jrt::Ref<class_3> var1);
    virtual void method_845(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_846(jrt::Ref<class_3> var1);
    virtual void method_847(int32_t var1);
    virtual jrt::Ref<class_3> method_848(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_849(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_850();
    virtual jrt::Ref<class_3> method_851();
    virtual int32_t method_852();
    virtual int32_t method_853();
    virtual int32_t method_854();
    virtual jrt::Ref<class_3> method_855(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_856(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_857();
    virtual jrt::Ref<class_3> method_858(jrt::Ref<class_3> var1);
    virtual void method_859(int16_t var1);
    virtual void method_860(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_861(int32_t var1);
    virtual void method_862(int32_t var1);
    virtual void method_863(int32_t var1);
    virtual void method_864(int32_t var1, int32_t var2, int32_t var3);
    virtual jrt::Ref<class_123> method_865();
    virtual int32_t method_866();
    virtual void method_867(jrt::Ref<class_123> var1);
    virtual void method_868(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_869(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_870(jrt::Ref<class_57> var1);
    virtual jrt::Ref<class_57> method_871(jrt::Ref<class_57> var1);
    virtual void method_872(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2, jrt::Ref<class_3> var3);
    virtual void method_873(int32_t var1);
    virtual void method_874(int32_t var1);
    virtual int32_t method_875();
    virtual void method_876(int32_t var1, int32_t var2);
    virtual void method_877(int8_t var1);
    virtual void method_878();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_102"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_103 : public class_102 {
public:
    jrt::Ref<class_102> field_1345{};
    void __init();
    void __init(jrt::Ref<class_103> var1);
    virtual jrt::Ref<class_102> method_840();
    virtual void method_879(jrt::Ref<class_102> var1);
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_839(bool var1);
    virtual jrt::Ref<java::lang::String> method_842(jrt::Ref<java::lang::String> var1, int32_t var2);
    virtual void method_876(int32_t var1, int32_t var2);
    virtual void method_877(int8_t var1);
    virtual void method_878();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_103"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_104 : public class_103 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_0>>> field_1346{};
    void __init();
    virtual void method_880(jrt::Ref<class_0> var1);
    virtual void method_839(bool var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_104"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_105 : public class_102 {
public:
    static jrt::Ref<class_3> field_1347;
    int32_t field_1348{};
    void __init();
    void __init(jrt::Ref<class_105> var1);
    virtual void method_839(bool var1);
    virtual jrt::Ref<java::lang::String> method_842(jrt::Ref<java::lang::String> var1, int32_t var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_105"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_106 : public class_105 {
public:
    int32_t field_1349{};
    int32_t field_1350{};
    int32_t field_1351{};
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> field_1352{};
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> field_1353{};
    jrt::Ref<jrt::Array<int32_t>> field_1354{};
    static jrt::Ref<class_3> field_1355;
    static jrt::Ref<class_3> field_1356;
    static jrt::Ref<class_3> field_1357;
    int32_t field_1358{};
    int32_t field_1359{};
    int32_t field_1360{};
    int32_t field_1361{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    void __init(jrt::Ref<class_106> var1);
    virtual void method_839(bool var1);
    virtual void method_881(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_882(int32_t var1);
    virtual bool method_883(jrt::Ref<class_3> var1);
    virtual int8_t method_884(jrt::Ref<class_15> var1);
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_885() = 0;
    static jrt::Ref<class_106> method_886(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_106"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_107 : public class_106 {
public:
    jrt::Ref<javax::microedition::m3g::Camera> field_1362{};
    static jrt::Ref<javax::microedition::m3g::Transform> field_1363;
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    void __init(jrt::Ref<class_107> var1);
    virtual void method_881(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_885();
    virtual jrt::Ref<class_102> method_840();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_107"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_108 : public class_105 {
public:
    int32_t field_1364{};
    static jrt::Ref<class_57> field_1365;
    static jrt::Ref<class_57> field_1366;
    int32_t field_1367{};
    jrt::Ref<class_57> field_1368{};
    void __init();
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_838(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_887() = 0;
    virtual void method_888();
    virtual jrt::Ref<class_102> method_840() = 0;
    static jrt::Ref<class_108> method_889(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2);
    static jrt::Ref<class_108> method_890(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int8_t var8);
    static jrt::Ref<class_108> method_891(int32_t var0, jrt::Ref<java::lang::String> var1);
    static jrt::Ref<class_108> method_892(int32_t var0, int32_t var1, int8_t var2);
    virtual void method_893(jrt::Ref<class_44> var1) = 0;
    virtual void method_894() = 0;
    virtual void method_895(int64_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_108"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_109 : public class_108 {
public:
    static jrt::Ref<javax::microedition::m3g::Transform> field_1369;
    static jrt::Ref<jrt::Array<float>> field_1370;
    jrt::Ref<javax::microedition::m3g::Appearance> field_1371{};
    int32_t field_1372{};
    jrt::Ref<javax::microedition::m3g::Mesh> field_1373{};
    jrt::Ref<javax::microedition::m3g::VertexBuffer> field_1374{};
    jrt::Ref<javax::microedition::m3g::VertexArray> field_1375{};
    jrt::Ref<javax::microedition::m3g::VertexArray> field_1376{};
    jrt::Ref<javax::microedition::m3g::TriangleStripArray> field_1377{};
    jrt::Ref<jrt::Array<int16_t>> field_1378{};
    jrt::Ref<jrt::Array<int8_t>> field_1379{};
    static jrt::Ref<jrt::Array<float>> field_1380;
    static jrt::Ref<jrt::Array<float>> field_1381;
    int32_t field_1382{};
    int32_t field_1383{};
    void __init(int32_t var1, int32_t var2, int8_t var3);
    void __init(jrt::Ref<class_109> var1);
    virtual jrt::Ref<class_102> method_840();
    virtual void method_894();
    virtual void method_887();
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_896(jrt::Ref<jrt::Array<int32_t>> var1, jrt::Ref<jrt::Array<int32_t>> var2);
    virtual void method_893(jrt::Ref<class_44> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_109"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_10 : public java::lang::Object {
public:
    jrt::Ref<class_59> field_102{};
    jrt::Ref<javax::microedition::lcdui::Image> field_103{};
    jrt::Ref<java::lang::String> field_104{};
    jrt::Ref<java::lang::String> field_105{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_106{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_107{};
    jrt::Ref<class_23> field_108{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_109{};
    jrt::Ref<javax::microedition::lcdui::Image> field_110{};
    bool field_111{};
    jrt::Ref<jrt::Array<bool>> field_112{};
    int32_t field_113{};
    int32_t field_114{};
    void __init();
    virtual void method_51(jrt::Ref<class_59> var1, bool var2);
    virtual void method_52(int32_t var1);
    virtual void method_53(int32_t var1);
    virtual void method_54();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_10"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_110 : public class_108 {
public:
    static jrt::Ref<javax::microedition::m3g::Transform> field_1384;
    static jrt::Ref<class_3> field_1385;
    jrt::Ref<javax::microedition::m3g::Appearance> field_1386{};
    int32_t field_1387{};
    jrt::Ref<javax::microedition::m3g::Mesh> field_1388{};
    jrt::Ref<jrt::Array<int32_t>> field_1389{};
    jrt::Ref<jrt::Array<int32_t>> field_1390{};
    jrt::Ref<jrt::Array<int32_t>> field_1391{};
    float field_1392{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int8_t var9);
    void __init(jrt::Ref<class_110> var1);
    virtual jrt::Ref<class_102> method_840();
    virtual void method_894();
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual void method_887();
    virtual void method_893(jrt::Ref<class_44> var1);
    virtual jrt::Ref<jrt::Array<int32_t>> method_897();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_110"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_111 : public class_108 {
public:
    int32_t field_1393{};
    int32_t field_1394{};
    int32_t field_1395{};
    int32_t field_1396{};
    int64_t field_1397{};
    bool field_1398{};
    int8_t field_1399{};
    static jrt::Ref<javax::microedition::m3g::Transform> field_1400;
    static jrt::Ref<jrt::Array<float>> field_1401;
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>> field_1402{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Node>>> field_1403{};
    static jrt::Ref<javax::microedition::m3g::PolygonMode> field_1404;
    static jrt::Ref<javax::microedition::m3g::PolygonMode> field_1405;
    static jrt::Ref<javax::microedition::m3g::CompositingMode> field_1406;
    bool field_1407{};
    jrt::Ref<javax::microedition::m3g::Texture2D> field_1408{};
    void __init(int32_t var1, jrt::Ref<java::lang::String> var2, int32_t var3);
    void __init(jrt::Ref<class_111> var1);
    void method_898();
    void method_899(jrt::Ref<java::lang::String> var1);
    void method_900(jrt::Ref<javax::microedition::m3g::Node> var1);
    bool method_901(jrt::Ref<javax::microedition::m3g::Node> var1);
    int32_t method_902(jrt::Ref<javax::microedition::m3g::Node> var1, int32_t var2);
    virtual void method_887();
    virtual void method_888();
    virtual void method_895(int64_t var1);
    virtual int32_t method_875();
    virtual void method_874(int32_t var1);
    virtual void method_873(int32_t var1);
    virtual void method_876(int32_t var1, int32_t var2);
    virtual void method_877(int8_t var1);
    virtual void method_878();
    virtual jrt::Ref<class_102> method_840();
    virtual void method_893(jrt::Ref<class_44> var1);
    void method_903(jrt::Ref<javax::microedition::m3g::Node> var1, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> var2, bool var3);
    virtual void method_894();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_111"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_112 : public class_108 {
public:
    jrt::Ref<class_9> field_1409{};
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_1410{};
    jrt::Ref<class_108> field_1411{};
    static jrt::Ref<class_3> field_1412;
    void __init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, int32_t var3);
    virtual void method_894();
    virtual void method_887();
    virtual void method_895(int64_t var1);
    virtual jrt::Ref<class_102> method_840();
    virtual void method_893(jrt::Ref<class_44> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_112"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_113 : public class_112 {
public:
    jrt::Ref<class_25> field_1413{};
    jrt::Ref<class_83> field_1414{};
    static jrt::Ref<class_3> field_1415;
    static jrt::Ref<class_3> field_1416;
    static jrt::Ref<class_3> field_1417;
    static int32_t field_1418;
    static int32_t field_1419;
    static int32_t field_1420;
    bool field_1421{};
    void __init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, int32_t var3, bool var4);
    virtual void method_894();
    virtual void method_887();
    virtual void method_895(int64_t var1);
    void method_904(int64_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_113"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_114 : public class_112 {
public:
    jrt::Ref<class_3> field_1422{};
    jrt::Ref<class_108> field_1423{};
    jrt::Ref<class_108> field_1424{};
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_1425;
    int32_t field_1426{};
    jrt::Ref<class_108> field_1427{};
    jrt::Ref<jrt::Array<int32_t>> field_1428{};
    jrt::Ref<jrt::Array<int32_t>> field_1429{};
    jrt::Ref<jrt::Array<int32_t>> field_1430{};
    int32_t field_1431{};
    int32_t field_1432{};
    bool field_1433{};
    void __init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, jrt::Ref<class_108> var3, int32_t var4, int32_t var5, int32_t var6);
    virtual void method_894();
    virtual void method_887();
    void method_905();
    virtual void method_895(int64_t var1);
    virtual jrt::Ref<class_3> method_906(jrt::Ref<class_3> var1);
    virtual void method_907();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_114"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_115 : public class_114 {
public:
    jrt::Ref<class_3> field_1434{};
    void __init(jrt::Ref<class_9> var1, jrt::Ref<class_108> var2, jrt::Ref<class_108> var3, int32_t var4);
    virtual jrt::Ref<class_3> method_906(jrt::Ref<class_3> var1);
    virtual void method_895(int64_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_115"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_116 : public class_108 {
public:
    jrt::Ref<class_24> field_1435{};
    bool field_1436{};
    bool field_1437{};
    void __init(jrt::Ref<class_44> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9, int8_t var10);
    void __init(jrt::Ref<class_44> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9);
    virtual void method_845(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_908(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual void method_909(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_910();
    virtual void method_895(int64_t var1);
    virtual void method_887();
    virtual jrt::Ref<class_102> method_840();
    virtual void method_893(jrt::Ref<class_44> var1);
    virtual void method_894();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_116"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_117 : public class_108 {
public:
    static jrt::Ref<javax::microedition::m3g::Transform> field_1438;
    static jrt::Ref<jrt::Array<float>> field_1439;
    jrt::Ref<javax::microedition::m3g::Node> field_1440{};
    static jrt::Ref<javax::microedition::m3g::CompositingMode> field_1441;
    int32_t field_1442{};
    void __init(jrt::Ref<java::lang::String> var1);
    void __init(jrt::Ref<class_117> var1);
    void method_911(jrt::Ref<java::lang::String> var1);
    virtual void method_887();
    virtual void method_837(jrt::Ref<class_106> var1, jrt::Ref<class_4> var2);
    virtual jrt::Ref<class_102> method_840();
    virtual void method_893(jrt::Ref<class_44> var1);
    void method_912(jrt::Ref<javax::microedition::m3g::Group> var1, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> var2);
    virtual void method_894();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_117"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_118 : public java::lang::Object {
public:
    jrt::Ref<class_26> field_1443{};
    int32_t field_1444{};
    bool field_1445{};
    bool field_1446{};
    bool field_1447{};
    jrt::Ref<class_5> field_1448{};
    int32_t field_1449{};
    bool field_1450{};
    jrt::Ref<class_3> field_1451{};
    jrt::Ref<class_3> field_1452{};
    jrt::Ref<class_3> field_1453{};
    jrt::Ref<class_39> field_1454{};
    int32_t field_1455{};
    bool field_1456{};
    void __init(jrt::Ref<class_42> var1, jrt::Ref<class_5> var2, jrt::Ref<class_26> var3);
    virtual bool method_913(int32_t var1, jrt::Ref<class_42> var2, jrt::Ref<class_2> var3);
    virtual void method_914();
    virtual void method_915();
    static void method_916(jrt::Ref<class_42> var0, jrt::Ref<class_26> var1);
    static void method_917(jrt::Ref<class_42> var0);
    static void method_918(jrt::Ref<class_42> var0);
    static void method_919(jrt::Ref<class_42> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_118"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_119 : public java::lang::Object {
public:
    static int8_t field_1457;
    static int32_t field_1458;
    static int32_t field_1459;
    static int8_t field_1460;
    static int8_t field_1461;
    static int8_t field_1462;
    static jrt::Ref<jrt::Array<int8_t>> field_1463;
    static jrt::Ref<jrt::Array<int8_t>> field_1464;
    static jrt::Ref<jrt::Array<int8_t>> field_1465;
    static jrt::Ref<jrt::Array<int8_t>> field_1466;
    static jrt::Ref<jrt::Array<int8_t>> field_1467;
    static jrt::Ref<jrt::Array<int8_t>> field_1468;
    static jrt::Ref<jrt::Array<int8_t>> field_1469;
    static jrt::Ref<jrt::Array<int8_t>> field_1470;
    static jrt::Ref<jrt::Array<int8_t>> field_1471;
    static jrt::Ref<jrt::Array<int8_t>> field_1472;
    static jrt::Ref<jrt::Array<int8_t>> field_1473;
    static jrt::Ref<jrt::Array<int8_t>> field_1474;
    static jrt::Ref<jrt::Array<int8_t>> field_1475;
    static jrt::Ref<jrt::Array<int8_t>> field_1476;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int8_t>>>>>> field_1477;
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1478;
    static jrt::Ref<javax::microedition::lcdui::Image> field_1479;
    void __init();
    static jrt::Ref<jrt::Array<int8_t>> method_920(bool var0, int32_t var1);
    static void method_921(jrt::Ref<jrt::Array<int8_t>> var0);
    static void method_922(int32_t var0);
    static void method_923(jrt::Ref<jrt::Array<int8_t>> var0, int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_119"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_11 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<int32_t>> field_115{};
    jrt::Ref<javax::microedition::lcdui::Image> field_116{};
    jrt::Ref<class_3> field_117{};
    void __init();
    virtual void method_55(jrt::Ref<class_57> var1);
    virtual void method_56();
    virtual void method_57(jrt::Ref<class_106> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_11"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_120 : public java::lang::Object {
public:
    int32_t field_1480{};
    int32_t field_1481{};
    int32_t field_1482{};
    int32_t field_1483{};
    int32_t field_1484{};
    int32_t field_1485{};
    int32_t field_1486{};
    int32_t field_1487{};
    jrt::Ref<jrt::Array<int8_t>> field_1488{};
    jrt::Ref<jrt::Array<int8_t>> field_1489{};
    int32_t field_1490{};
    int32_t field_1491{};
    int32_t field_1492{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, jrt::Ref<jrt::Array<int8_t>> var8, jrt::Ref<jrt::Array<int8_t>> var9);
    virtual int32_t method_924();
    virtual float method_925();
    virtual void method_926(int32_t var1);
    virtual void method_927(int32_t var1);
    virtual int32_t method_928(bool var1, int32_t var2);
    virtual jrt::Ref<class_120> method_929(int32_t var1);
    virtual jrt::Ref<class_120> method_930(int32_t var1, int32_t var2);
    static bool method_931(int32_t var0, int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2);
    static bool method_932(int32_t var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_933(jrt::Ref<class_120> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1, int32_t var2);
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_934(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, bool var1);
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_935(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_936(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var0, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    virtual jrt::Ref<class_120> method_937();
    virtual bool method_938(jrt::Ref<class_120> var1);
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_120"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_121 : public java::lang::Object {
public:
    int32_t field_1493{};
    int32_t field_1494{};
    int32_t field_1495{};
    int32_t field_1496{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1497{};
    int32_t field_1498{};
    bool field_1499{};
    bool field_1500{};
    void __init(int32_t var1, int32_t var2, int32_t var3);
    void __init();
    virtual void method_939(jrt::Ref<java::lang::String> var1);
    virtual void method_940(jrt::Ref<java::lang::String> var1, bool var2);
    virtual bool method_941();
    virtual void method_942();
    virtual void method_943();
    virtual void method_944();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_121"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_122 : public java::lang::Object {
public:
    int32_t field_1501{};
    int32_t field_1502{};
    int32_t field_1503{};
    int32_t field_1504{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1505{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1506{};
    int32_t field_1507{};
    jrt::Ref<javax::microedition::lcdui::Image> field_1508{};
    void __init(int32_t var1, int32_t var2, int32_t var3);
    void __init();
    virtual void method_945(int32_t var1, int32_t var2);
    virtual void method_946();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_122"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_123 : public java::lang::Object {
public:
    int32_t field_1509{};
    int32_t field_1510{};
    int32_t field_1511{};
    int32_t field_1512{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    void __init();
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_123"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_124 : public javax::microedition::lcdui::game::GameCanvas {
public:
    jrt::Ref<DeepMIDlet> field_1513{};
    int32_t field_1514{};
    int32_t field_1515{};
    int32_t field_1516{};
    int32_t field_1517{};
    int32_t field_1518{};
    int32_t field_1519{};
    jrt::Ref<class_54> field_1520{};
    jrt::Ref<class_33> field_1521{};
    bool field_1522{};
    bool field_1523{};
    bool field_1524{};
    void __init(jrt::Ref<DeepMIDlet> var1);
    virtual void method_947();
    virtual void method_948();
    virtual void hideNotify();
    virtual void method_949();
    virtual void method_950();
    virtual void method_951();
    virtual void method_952();
    virtual void keyPressed(int32_t var1);
    virtual void keyRepeated(int32_t var1);
    virtual void keyReleased(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_124"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_12 : public java::lang::Object {
public:
    jrt::Ref<class_23> field_118{};
    int32_t field_119{};
    void __init();
    virtual void method_58(jrt::Ref<java::lang::String> var1);
    virtual bool method_59(int32_t var1);
    virtual bool method_60(int32_t var1, int32_t var2);
    virtual void method_61();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_12"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_13 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<float>> field_120{};
    jrt::Ref<jrt::Array<float>> field_121{};
    jrt::Ref<jrt::Array<float>> field_122{};
    int32_t field_123{};
    float field_124{};
    jrt::Ref<jrt::Array<float>> field_125{};
    jrt::Ref<jrt::Array<float>> field_126{};
    jrt::Ref<jrt::Array<float>> field_127{};
    jrt::Ref<jrt::Array<int32_t>> field_128{};
    jrt::Ref<jrt::Array<int32_t>> field_129{};
    jrt::Ref<class_3> field_130{};
    jrt::Ref<class_3> field_131{};
    int32_t field_132{};
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_133{};
    int64_t field_134{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> var1, int32_t var2, int64_t var3);
    void method_62();
    virtual void method_63(int64_t var1);
    void method_64(float var1, int32_t var2);
    virtual void method_65();
    virtual void method_66();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_13"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_14 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_135;
    static jrt::Ref<jrt::Array<int32_t>> field_136;
    static jrt::Ref<jrt::Array<int32_t>> field_137;
    static int32_t field_138;
    static int32_t field_139;
    static int32_t field_140;
    static int32_t field_141;
    static int32_t field_142;
    static int32_t field_143;
    static bool field_144;
    static bool field_145;
    static int32_t field_146;
    static int32_t field_147;
    void __init();
    static void method_67(jrt::Ref<class_70> var0);
    static void method_68();
    static bool method_69();
    static bool method_70();
    static jrt::Ref<jrt::Array<int32_t>> method_71();
    static jrt::Ref<jrt::Array<int32_t>> method_72();
    static void method_73();
    static int32_t method_74();
    static void method_75();
    static int32_t method_76();
    static void method_77();
    static void method_78();
    static int32_t method_79();
    static void method_80(int32_t var0);
    static void method_81();
    static void method_82(jrt::Ref<jrt::Array<int32_t>> var0);
    static void method_83();
    static void method_84();
    static void method_85();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_14"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_15 : public java::lang::Object {
public:
    jrt::Ref<class_3> field_148{};
    int32_t field_149{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    void __init();
    void __init(jrt::Ref<class_15> var1);
    virtual jrt::Ref<class_15> method_86(jrt::Ref<class_15> var1, jrt::Ref<class_15> var2);
    virtual void method_87(jrt::Ref<class_15> var1);
    virtual void method_88(jrt::Ref<class_15> var1);
    virtual void method_89(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    virtual void method_90(jrt::Ref<class_3> var1, int32_t var2);
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_15"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_16 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<int16_t>> field_150;
    void __init();
    static int32_t method_91(int32_t var0);
    static int32_t method_92(int32_t var0);
    static int32_t method_93(int32_t var0);
    static int32_t method_94(int32_t var0, int32_t var1);
    static int32_t method_95(int32_t var0);
    static int32_t method_96(int64_t var0);
    static int32_t method_97(int32_t var0, int32_t var1);
    static int32_t method_98(int32_t var0, int32_t var1);
    static float method_99(float var0, float var1);
    static int32_t method_100(int32_t var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_16"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_17 : public java::lang::Object {
public:
    int64_t field_151{};
    int32_t field_152{};
    bool field_153{};
    bool field_154{};
    jrt::Ref<class_78> field_155{};
    jrt::Ref<class_10> field_156{};
    jrt::Ref<class_121> field_157{};
    jrt::Ref<class_59> field_158{};
    int32_t field_159{};
    int32_t field_160{};
    int32_t field_161{};
    void __init();
    virtual void method_101();
    virtual void method_102();
    virtual bool method_103(int32_t var1);
    virtual bool method_104(int32_t var1, int32_t var2);
    virtual void method_105();
    virtual int32_t method_106();
    virtual bool method_107();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_17"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_18 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_97>>> field_162{};
    bool field_163{};
    int32_t field_164{};
    void __init(jrt::Ref<jrt::Array<int32_t>> var1);
    virtual void method_108();
    virtual jrt::Ref<class_97> method_109(int32_t var1);
    virtual jrt::Ref<class_97> method_110();
    virtual jrt::Ref<class_97> method_111();
    virtual void method_112(int32_t var1);
    virtual int32_t method_113();
    virtual void method_114(int32_t var1, int32_t var2, int32_t var3);
    virtual jrt::Ref<class_18> method_115();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_18"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_19 : public java::lang::Object {
public:
    int32_t field_165{};
    int32_t field_166{};
    int32_t field_167{};
    int32_t field_168{};
    int32_t field_169{};
    int32_t field_170{};
    int32_t field_171{};
    int32_t field_172{};
    int32_t field_173{};
    int32_t field_174{};
    int32_t field_175{};
    bool field_176{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9);
    virtual int32_t method_116();
    virtual int32_t method_117(int32_t var1);
    virtual bool method_118();
    virtual jrt::Ref<class_19> method_119(int32_t var1, int32_t var2);
    virtual jrt::Ref<class_19> method_120();
    virtual jrt::Ref<class_19> method_121();
    virtual bool method_122(jrt::Ref<class_19> var1);
    virtual jrt::Ref<java::lang::String> toString();
    virtual void method_123(jrt::Ref<class_86> var1);
    virtual void method_124();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_19"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_1 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_0;
    static jrt::Ref<jrt::Array<int16_t>> field_1;
    static jrt::Ref<jrt::Array<int16_t>> field_2;
    static jrt::Ref<jrt::Array<int16_t>> field_3;
    static jrt::Ref<jrt::Array<int16_t>> field_4;
    static jrt::Ref<jrt::Array<int16_t>> field_5;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_6;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_7;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_8;
    static jrt::Ref<jrt::Array<int16_t>> field_9;
    static jrt::Ref<jrt::Array<int16_t>> field_10;
    static jrt::Ref<jrt::Array<int16_t>> field_11;
    static jrt::Ref<jrt::Array<int16_t>> field_12;
    static jrt::Ref<jrt::Array<int16_t>> field_13;
    static jrt::Ref<jrt::Array<int16_t>> field_14;
    static jrt::Ref<jrt::Array<int16_t>> field_15;
    static jrt::Ref<jrt::Array<int16_t>> field_16;
    static jrt::Ref<jrt::Array<int16_t>> field_17;
    static jrt::Ref<jrt::Array<int16_t>> field_18;
    static jrt::Ref<jrt::Array<int32_t>> field_19;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_20;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_21;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_22;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_23;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_24;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>>>> field_25;
    static int32_t field_26;
    static jrt::Ref<java::lang::String> field_27;
    static int32_t field_28;
    static int32_t field_29;
    static int32_t field_30;
    void __init();
    virtual void method_2(int32_t var1);
    void method_3(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2);
    virtual jrt::Ref<java::lang::String> method_4(int32_t var1);
    virtual void method_5();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_1"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_20 : public java::lang::Object {
public:
    jrt::Ref<class_34> field_177{};
    int32_t field_178{};
    int32_t field_179{};
    int32_t field_180{};
    int32_t field_181{};
    jrt::Ref<jrt::Array<int32_t>> field_182{};
    jrt::Ref<class_22> field_183{};
    bool field_184{};
    bool field_185{};
    int32_t field_186{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    void __init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<jrt::Array<int32_t>> var4);
    virtual void method_125();
    virtual bool method_126(int64_t var1, jrt::Ref<class_70> var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_20"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_21 : public java::lang::Object {
public:
    static jrt::Ref<java::lang::String> field_187;
    static jrt::Ref<jrt::Array<int8_t>> field_188;
    static jrt::Ref<javax::microedition::lcdui::Image> field_189;
    static int32_t field_190;
    static int32_t field_191;
    static int64_t field_192;
    static int32_t field_193;
    static int32_t field_194;
    static int32_t field_195;
    static int32_t field_196;
    static int32_t field_197;
    static int32_t field_198;
    static int32_t field_199;
    static int32_t field_200;
    static int32_t field_201;
    static int32_t field_202;
    static int32_t field_203;
    static int32_t field_204;
    static int32_t field_205;
    static int32_t field_206;
    static int32_t field_207;
    static int32_t field_208;
    static int32_t field_209;
    static jrt::Ref<jrt::Array<bool>> field_210;
    static jrt::Ref<jrt::Array<bool>> field_211;
    static jrt::Ref<jrt::Array<bool>> field_212;
    static jrt::Ref<class_68> field_213;
    static jrt::Ref<class_87> field_214;
    static jrt::Ref<jrt::Array<jrt::Ref<class_87>>> field_215;
    static jrt::Ref<class_86> field_216;
    static jrt::Ref<jrt::Array<jrt::Ref<class_86>>> field_217;
    static int32_t field_218;
    static int32_t field_219;
    static int32_t field_220;
    static int64_t field_221;
    void __init();
    static jrt::Ref<jrt::Array<jrt::Ref<class_86>>> method_127();
    static void method_128(jrt::Ref<jrt::Array<jrt::Ref<class_86>>> var0);
    static bool method_129(jrt::Ref<class_86> var0);
    static jrt::Ref<class_86> method_130(jrt::Ref<class_86> var0);
    static void method_131(jrt::Ref<class_86> var0);
    static jrt::Ref<class_87> method_132();
    static void method_133(jrt::Ref<class_87> var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_87>>> method_134();
    static jrt::Ref<class_87> method_135();
    static void method_136(jrt::Ref<class_87> var0);
    static jrt::Ref<class_87> method_137();
    static void method_138(jrt::Ref<class_87> var0);
    static bool method_139();
    static void method_140();
    static void method_141();
    static void method_142(int32_t var0);
    static int32_t method_143();
    static void method_144(jrt::Ref<jrt::Array<int32_t>> var0);
    static void method_145();
    static bool method_146();
    static bool method_147();
    static jrt::Ref<class_87> method_148(bool var0, int64_t var1);
    static void method_149(int32_t var0);
    static void method_150();
    static int32_t method_151();
    static void method_152();
    static void method_153(int32_t var0);
    static int32_t method_154();
    static void method_155();
    static int32_t method_156();
    static void method_157(int32_t var0);
    static int32_t method_158();
    static int32_t method_159();
    static int32_t method_160();
    static void method_161(int32_t var0);
    static void method_162(int32_t var0);
    static void method_163(jrt::Ref<class_87> var0);
    static void method_164(int32_t var0);
    static void method_165(int32_t var0);
    static void method_166(int32_t var0);
    static void method_167(jrt::Ref<jrt::Array<bool>> var0);
    static jrt::Ref<jrt::Array<bool>> method_168();
    static void method_169(int32_t var0);
    static int32_t method_170();
    static void method_171(int32_t var0);
    static int32_t method_172();
    static void method_173();
    static void method_174(jrt::Ref<jrt::Array<bool>> var0);
    static jrt::Ref<jrt::Array<bool>> method_175();
    static void method_176();
    static int32_t method_177();
    static jrt::Ref<class_68> method_178();
    static void method_179(jrt::Ref<class_68> var0);
    static jrt::Ref<class_86> method_180();
    static void method_181(jrt::Ref<class_86> var0);
    static int32_t method_182();
    static void method_183(int32_t var0);
    static void method_184(int64_t var0);
    static void method_185(int32_t var0);
    static void method_186(int32_t var0);
    static void method_187(int32_t var0);
    static void method_188(int32_t var0);
    static void method_189(int32_t var0);
    static void method_190(int32_t var0);
    static int32_t method_191();
    static void method_192(int32_t var0);
    static void method_193(int32_t var0);
    static void method_194(jrt::Ref<jrt::Array<bool>> var0);
    static jrt::Ref<jrt::Array<bool>> method_195();
    static void method_196(int32_t var0);
    static void method_197(int32_t var0);
    static void method_198(int32_t var0);
    static void method_199();
    static int32_t method_200();
    static int32_t method_201();
    static int32_t method_202();
    static void method_203();
    static void method_204(int32_t var0);
    static int32_t method_205();
    static void method_206();
    static void method_207();
    static int32_t method_208();
    static int32_t method_209();
    static int32_t method_210();
    static void method_211(int64_t var0);
    static int64_t method_212();
    static jrt::Ref<java::lang::String> method_213();
    static void method_214(jrt::Ref<java::lang::String> var0);
    static jrt::Ref<jrt::Array<int8_t>> method_215();
    static void method_216(jrt::Ref<jrt::Array<int8_t>> var0);
    static jrt::Ref<javax::microedition::lcdui::Image> method_217();
    static void method_218(jrt::Ref<javax::microedition::lcdui::Image> var0);
    static jrt::Ref<java::lang::String> method_219(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1);
    static void method_220();
    static void method_221();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_21"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_22 : public java::lang::Object {
public:
    int32_t field_222{};
    int32_t field_223{};
    int32_t field_224{};
    jrt::Ref<class_26> field_225{};
    jrt::Ref<jrt::Array<jrt::Ref<class_22>>> field_226{};
    int32_t field_227{};
    void __init(int32_t var1, int32_t var2, jrt::Ref<class_26> var3);
    void __init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_26> var4);
    virtual bool method_222(int32_t var1);
    virtual bool method_223();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_22"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_23 : public java::lang::Object {
public:
    int32_t field_228{};
    int32_t field_229{};
    int32_t field_230{};
    int32_t field_231{};
    int32_t field_232{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_233{};
    int32_t field_234{};
    bool field_235{};
    int32_t field_236{};
    int32_t field_237{};
    jrt::Ref<java::lang::String> field_238{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_239{};
    jrt::Ref<jrt::Array<int8_t>> field_240{};
    jrt::Ref<javax::microedition::lcdui::Image> field_241{};
    bool field_242{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_243{};
    int32_t field_244{};
    jrt::Ref<javax::microedition::lcdui::Image> field_245{};
    int32_t field_246{};
    int32_t field_247{};
    bool field_248{};
    int32_t field_249{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<java::lang::String> var5);
    virtual void method_224();
    virtual void method_225(jrt::Ref<java::lang::String> var1);
    virtual void method_226(jrt::Ref<jrt::Array<int8_t>> var1, jrt::Ref<java::lang::String> var2, bool var3);
    virtual void method_227(jrt::Ref<jrt::Array<int8_t>> var1, jrt::Ref<javax::microedition::lcdui::Image> var2, jrt::Ref<java::lang::String> var3, bool var4);
    virtual void method_228(jrt::Ref<javax::microedition::lcdui::Image> var1, int32_t var2, int32_t var3);
    virtual void method_229(int32_t var1);
    virtual void method_230(int32_t var1);
    virtual void method_231();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_23"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_24 : public java::lang::Object {
public:
    jrt::Ref<class_108> field_250{};
    jrt::Ref<jrt::Array<int32_t>> field_251{};
    int32_t field_252{};
    int32_t field_253{};
    int32_t field_254{};
    void __init(int32_t var1, jrt::Ref<class_44> var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9, int32_t var10, int8_t var11);
    virtual void method_232();
    virtual void method_233();
    virtual void method_234(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_24"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_25 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<int32_t>> field_255{};
    jrt::Ref<jrt::Array<int32_t>> field_256{};
    jrt::Ref<jrt::Array<int32_t>> field_257{};
    jrt::Ref<jrt::Array<int32_t>> field_258{};
    int32_t field_259{};
    int32_t field_260{};
    jrt::Ref<class_108> field_261{};
    void __init();
    virtual void method_235();
    virtual void method_236(jrt::Ref<class_3> var1, int32_t var2);
    virtual void method_237(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    virtual void method_238();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_25"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_26 : public java::lang::Object {
public:
    int32_t field_262{};
    static jrt::Ref<class_29> field_263;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_264;
    jrt::Ref<class_108> field_265{};
    bool deep3dShown{};
    jrt::Ref<class_116> field_266{};
    jrt::Ref<class_116> field_267{};
    jrt::Ref<class_116> field_268{};
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_269{};
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_270{};
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_271{};
    jrt::Ref<class_70> field_272{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_273{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_274{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_275{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_276{};
    jrt::Ref<class_18> field_277{};
    jrt::Ref<class_18> field_278{};
    jrt::Ref<class_18> field_279{};
    jrt::Ref<jrt::Array<jrt::Ref<class_20>>> field_280{};
    int32_t field_281{};
    int32_t field_282{};
    int32_t field_283{};
    int32_t field_284{};
    int32_t field_285{};
    jrt::Ref<java::lang::String> field_286{};
    int32_t field_287{};
    int32_t field_288{};
    jrt::Ref<class_22> field_289{};
    jrt::Ref<class_22> field_290{};
    int32_t field_291{};
    int32_t field_292{};
    bool field_293{};
    int32_t field_294{};
    float field_295{};
    float field_296{};
    float field_297{};
    int32_t field_298{};
    int32_t field_299{};
    int32_t field_300{};
    static bool field_301;
    static jrt::Ref<class_86> field_302;
    jrt::Ref<jrt::Array<float>> deep3dCam{};
    jrt::Ref<class_3> deep3dPos{};
    void __init();
    void __init(int32_t var1);
    static void method_239();
    virtual bool method_240();
    virtual void method_241();
    void method_242();
    jrt::Ref<class_101> method_243(int32_t var1, jrt::Ref<class_97> var2);
    virtual void method_244();
    virtual jrt::Ref<class_9> method_245(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    virtual void method_246();
    virtual void method_247();
    virtual void method_248();
    virtual void method_249();
    virtual void method_250();
    virtual void method_251();
    virtual jrt::Ref<class_91> method_252(int32_t var1);
    virtual jrt::Ref<class_91> method_253(jrt::Ref<class_97> var1, int32_t var2);
    virtual jrt::Ref<class_91> method_254(int32_t var1, int32_t var2, int32_t var3, bool var4, jrt::Ref<class_97> var5);
    virtual jrt::Ref<class_18> method_255(int32_t var1);
    virtual jrt::Ref<jrt::Array<jrt::Ref<class_20>>> method_256(int32_t var1);
    virtual void method_257(int32_t var1, bool var2);
    virtual void method_258();
    virtual void method_259();
    virtual void method_260();
    virtual void method_261();
    virtual bool method_262(jrt::Ref<class_3> var1, bool var2);
    virtual bool method_263(jrt::Ref<class_3> var1);
    virtual bool method_264(jrt::Ref<class_3> var1);
    virtual void method_265(int64_t var1);
    virtual void method_266(int64_t var1);
    virtual void method_267(int64_t var1);
    virtual bool method_268(int32_t var1);
    virtual void method_269();
    virtual bool method_270(int32_t var1);
    virtual void method_271();
    void deep3dRemaster();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_26"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_27 : public java::lang::Object {
public:
    static jrt::Ref<javax::microedition::rms::RecordStore> field_303;
    void __init();
    static jrt::Ref<jrt::Array<jrt::Ref<class_41>>> method_272();
    static jrt::Ref<class_41> method_273(int32_t var0);
    static void method_274();
    static void method_275();
    static jrt::Ref<class_41> method_276(int32_t var0);
    static void method_277(int32_t var0);
    static void method_278(jrt::Ref<java::io::DataOutputStream> var0, jrt::Ref<class_87> var1);
    static jrt::Ref<class_87> method_279(jrt::Ref<java::io::DataInputStream> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_27"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_28 : public java::lang::Object {
public:
    static jrt::Ref<java::lang::Class> field_304;
    void __init();
    static jrt::Ref<javax::microedition::lcdui::Image> method_280(jrt::Ref<javax::microedition::lcdui::Image> var0, int32_t var1, int32_t var2);
    static jrt::Ref<jrt::Array<int32_t>> method_281(jrt::Ref<jrt::Array<int32_t>> var0, jrt::Ref<jrt::Array<int32_t>> var1, int32_t var2, int32_t var3);
    static jrt::Ref<javax::microedition::lcdui::Image> method_282(jrt::Ref<java::lang::String> var0);
    static jrt::Ref<jrt::Array<int8_t>> method_283(jrt::Ref<java::lang::String> var0);
    static jrt::Ref<java::lang::Class> method_284(jrt::Ref<java::lang::String> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_28"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_29 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_29>>> field_305{};
    static jrt::Ref<class_3> field_306;
    int32_t field_307{};
    int32_t field_308{};
    int32_t field_309{};
    int32_t field_310{};
    int32_t field_311{};
    int32_t field_312{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6);
    virtual jrt::Ref<class_3> method_285(jrt::Ref<class_3> var1);
    virtual void method_286(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_287(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_288(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_29"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_2 : public java::lang::Object {
public:
    int32_t field_31{};
    int32_t field_32{};
    int32_t field_33{};
    int32_t field_34{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_35{};
    int32_t field_36{};
    void __init(jrt::Ref<class_26> var1);
    virtual void method_6();
    virtual void method_7();
    virtual void method_8();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_2"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_30 : public class_29 {
public:
    int32_t field_313{};
    int32_t field_314{};
    int32_t field_315{};
    int32_t field_316{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7);
    virtual bool method_287(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_288(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_286(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_30"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_31 : public class_29 {
public:
    int32_t field_317{};
    int32_t field_318{};
    int32_t field_319{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8, int32_t var9);
    virtual bool method_287(int32_t var1, int32_t var2, int32_t var3);
    virtual bool method_288(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_286(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_31"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_32 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<char16_t>>>> field_320;
    int32_t field_321{};
    int32_t field_322{};
    int32_t field_323{};
    int32_t field_324{};
    int32_t field_325{};
    char16_t field_326{};
    jrt::Ref<java::lang::String> field_327{};
    int32_t field_328{};
    void __init(int32_t var1);
    int32_t method_289(int32_t var1);
    void typeFromKeyboard();
    virtual int32_t method_290(int32_t var1);
    virtual void method_291(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_32"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_33 : public java::lang::Object, public virtual java::lang::Runnable {
public:
    int32_t field_329{};
    static jrt::Ref<jrt::Array<int32_t>> field_330;
    bool field_331{};
    jrt::Ref<javax::microedition::lcdui::game::GameCanvas> field_332{};
    jrt::Ref<java::lang::Thread> field_333{};
    static jrt::Ref<javax::microedition::lcdui::Image> field_334;
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_335{};
    jrt::Ref<jrt::Array<int32_t>> field_336{};
    bool field_337{};
    int32_t field_338{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_339{};
    jrt::Ref<java::lang::String> field_340{};
    static jrt::Ref<java::lang::String> field_341;
    void __init();
    static jrt::Ref<javax::microedition::lcdui::Image> method_292();
    virtual void run();
    virtual void method_293();
    virtual void method_294();
    virtual void method_295();
    virtual void method_296(bool var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_33"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_34 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_20>>> field_342{};
    jrt::Ref<class_20> field_343{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_344{};
    jrt::Ref<jrt::Array<int8_t>> field_345{};
    int64_t field_346{};
    int32_t field_347{};
    jrt::Ref<java::lang::String> field_348{};
    void __init();
    virtual void method_297();
    virtual void method_298(jrt::Ref<jrt::Array<jrt::Ref<class_20>>> var1);
    virtual jrt::Ref<class_20> method_299(int32_t var1);
    virtual void method_300(int64_t var1, jrt::Ref<class_70> var3);
    virtual void method_301(int64_t var1, jrt::Ref<class_70> var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_34"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_35 : public java::lang::Object {
public:
    void __init();
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_302();
    static void method_303(jrt::Ref<class_86> var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_304(jrt::Ref<class_86> var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_19>>> method_305(jrt::Ref<class_86> var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_68>>> method_306(jrt::Ref<class_86> var0);
    static jrt::Ref<class_120> method_307();
    static int32_t method_308(jrt::Ref<jrt::Array<int8_t>> var0, jrt::Ref<class_86> var1);
    static jrt::Ref<jrt::Array<jrt::Ref<class_87>>> method_309(jrt::Ref<class_86> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_35"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_36 : public java::lang::Object {
public:
    jrt::Ref<class_81> field_349{};
    jrt::Ref<class_87> field_350{};
    jrt::Ref<class_10> field_351{};
    jrt::Ref<class_121> field_352{};
    jrt::Ref<class_55> field_353{};
    int64_t field_354{};
    int32_t field_355{};
    bool field_356{};
    jrt::Ref<class_47> field_357{};
    jrt::Ref<class_86> field_358{};
    void __init();
    virtual void method_310();
    virtual void method_311();
    virtual void method_312();
    virtual int32_t method_313();
    virtual bool method_314();
    virtual bool method_315(int32_t var1);
    void method_316(bool var1);
    virtual bool method_317(int32_t var1, int32_t var2);
    virtual bool method_318();
    virtual bool method_319();
    virtual void method_320();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_36"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_37 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<class_9>>>>> field_359{};
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> field_360{};
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> field_361{};
    float field_362{};
    int32_t field_363{};
    int32_t field_364{};
    int32_t field_365{};
    int32_t field_366{};
    int32_t field_367{};
    int32_t field_368{};
    int32_t field_369{};
    int32_t field_370{};
    int32_t field_371{};
    int32_t field_372{};
    jrt::Ref<jrt::Array<int32_t>> field_373{};
    int32_t field_374{};
    bool field_375{};
    bool field_376{};
    jrt::Ref<class_57> field_377{};
    jrt::Ref<class_3> field_378{};
    jrt::Ref<class_91> field_379{};
    bool field_380{};
    int32_t field_381{};
    int32_t field_382{};
    bool field_383{};
    void __init(float var1, int32_t var2, int32_t var3);
    virtual bool method_321();
    virtual void method_322(int32_t var1);
    virtual void method_323(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1);
    virtual void method_324(jrt::Ref<class_37> var1);
    virtual void method_325(jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var1);
    virtual jrt::Ref<class_37> method_326(int32_t var1);
    virtual void method_327(int32_t var1);
    virtual void method_328(int32_t var1);
    virtual void method_329(int32_t var1);
    virtual void method_330(int32_t var1);
    virtual void method_331(int32_t var1);
    virtual void method_332(int32_t var1);
    virtual int32_t method_333();
    virtual void method_334();
    virtual void method_335();
    void method_336();
    virtual void method_337(int32_t var1, int32_t var2, int32_t var3);
    virtual float method_338(int32_t var1);
    virtual void method_339(int32_t var1);
    virtual void method_340(int32_t var1);
    virtual void method_341(int32_t var1);
    virtual void method_342(int32_t var1, bool var2);
    virtual void method_343(int32_t var1);
    virtual jrt::Ref<class_3> method_344(jrt::Ref<class_3> var1);
    virtual bool method_345();
    virtual void method_346(jrt::Ref<class_9> var1, int32_t var2);
    virtual void method_347(jrt::Ref<jrt::Array<jrt::Ref<class_9>>> var1, int32_t var2);
    void method_348();
    virtual void method_349();
    virtual int32_t method_350(int32_t var1);
    virtual void method_351(int32_t var1);
    virtual void method_352(int32_t var1, int64_t var2, bool var4);
    virtual void method_353(int64_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_37"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_38 : public java::lang::Object {
public:
    static jrt::Ref<class_3> field_384;
    static jrt::Ref<class_3> field_385;
    static jrt::Ref<jrt::Array<bool>> field_386;
    void __init();
    static jrt::Ref<class_86> method_354(int32_t var0);
    static void method_355(jrt::Ref<jrt::Array<bool>> var0);
    static jrt::Ref<jrt::Array<bool>> method_356();
    static void method_357(int32_t var0);
    static int32_t method_358(int32_t var0);
    static int32_t method_359(int32_t var0);
    static int32_t method_360(int32_t var0, int32_t var1, int32_t var2, int32_t var3);
    static int32_t method_361(int32_t var0, int32_t var1, int32_t var2, int32_t var3);
    static float method_362(jrt::Ref<class_86> var0, jrt::Ref<class_86> var1);
    static jrt::Ref<jrt::Array<int8_t>> method_363(jrt::Ref<class_86> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_38"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_39 : public java::lang::Object {
public:
    int64_t field_387{};
    jrt::Ref<class_106> field_388{};
    jrt::Ref<class_13> field_389{};
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_390;
    void __init(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_364(int64_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_39"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_3 : public java::lang::Object {
public:
    int32_t field_37{};
    int32_t field_38{};
    int32_t field_39{};
    void __init(int32_t var1, int32_t var2, int32_t var3);
    void __init();
    void __init(jrt::Ref<class_3> var1);
    virtual void method_9(jrt::Ref<class_3> var1);
    virtual void method_10(int32_t var1, int32_t var2, int32_t var3);
    virtual int32_t method_11(jrt::Ref<class_3> var1);
    virtual int32_t method_12(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_13(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual jrt::Ref<class_3> method_14(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual void method_15(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_16(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual void method_17(jrt::Ref<class_3> var1);
    virtual void method_18(int32_t var1);
    virtual jrt::Ref<class_3> method_19(int32_t var1, jrt::Ref<class_3> var2);
    virtual void method_20(int32_t var1);
    virtual jrt::Ref<class_3> method_21(jrt::Ref<class_3> var1);
    virtual void method_22();
    virtual int32_t method_23();
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_3"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_40 : public java::lang::Object {
public:
    int32_t field_391{};
    int32_t field_392{};
    int32_t field_393{};
    void __init(int32_t var1, int32_t var2, int32_t var3);
    virtual int32_t method_365();
    virtual int32_t method_366();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_40"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_41 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<bool>> field_394{};
    int32_t field_395{};
    int32_t field_396{};
    int64_t field_397{};
    int32_t field_398{};
    int32_t field_399{};
    int32_t field_400{};
    int32_t field_401{};
    int32_t field_402{};
    int32_t field_403{};
    int32_t field_404{};
    int32_t field_405{};
    int32_t field_406{};
    int32_t field_407{};
    int32_t field_408{};
    int32_t field_409{};
    int32_t field_410{};
    int32_t field_411{};
    int32_t field_412{};
    int32_t field_413{};
    int32_t field_414{};
    jrt::Ref<class_87> field_415{};
    jrt::Ref<class_87> field_416{};
    jrt::Ref<java::lang::String> field_417{};
    jrt::Ref<jrt::Array<int8_t>> field_418{};
    jrt::Ref<javax::microedition::lcdui::Image> field_419{};
    jrt::Ref<jrt::Array<bool>> field_420{};
    jrt::Ref<jrt::Array<bool>> field_421{};
    jrt::Ref<jrt::Array<bool>> field_422{};
    jrt::Ref<jrt::Array<jrt::Ref<class_86>>> field_423{};
    jrt::Ref<jrt::Array<int32_t>> field_424{};
    int32_t field_425{};
    jrt::Ref<jrt::Array<int32_t>> field_426{};
    bool field_427{};
    bool field_428{};
    bool field_429{};
    bool field_430{};
    bool field_431{};
    bool field_432{};
    bool field_433{};
    bool field_434{};
    bool field_435{};
    bool field_436{};
    bool field_437{};
    bool field_438{};
    bool field_439{};
    bool field_440{};
    bool field_441{};
    bool field_442{};
    bool field_443{};
    bool field_444{};
    bool field_445{};
    bool field_446{};
    bool field_447{};
    bool field_448{};
    bool field_449{};
    jrt::Ref<class_68> field_450{};
    jrt::Ref<class_86> field_451{};
    void __init();
    virtual void method_367();
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_41"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_42 : public java::lang::Object, public virtual class_0 {
public:
    jrt::Ref<class_102> field_452{};
    jrt::Ref<class_102> field_453{};
    jrt::Ref<class_102> field_454{};
    jrt::Ref<class_3> field_455{};
    jrt::Ref<class_3> field_456{};
    jrt::Ref<class_3> field_457{};
    jrt::Ref<class_3> field_458{};
    jrt::Ref<class_3> field_459{};
    bool field_460{};
    jrt::Ref<class_3> field_461{};
    jrt::Ref<class_3> field_462{};
    jrt::Ref<class_5> field_463{};
    bool field_464{};
    bool field_465{};
    float deep3dDolly{};
    jrt::Ref<class_3> deep3dOff{};
    jrt::Ref<class_3> deep3dAim{};
    void __init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2);
    void __init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2, jrt::Ref<class_3> var3);
    virtual void method_368(jrt::Ref<class_102> var1);
    virtual void method_369(jrt::Ref<class_102> var1);
    virtual void method_370(jrt::Ref<class_3> var1);
    virtual void method_371();
    virtual void method_372();
    virtual void method_0();
    virtual bool method_1();
    virtual void method_373(bool var1);
    virtual void method_374(jrt::Ref<class_3> var1);
    virtual void method_375(jrt::Ref<class_3> var1);
    virtual void method_376(jrt::Ref<class_3> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_42"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_43 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<int32_t>> field_466;
    static jrt::Ref<jrt::Array<jrt::Ref<class_44>>> field_467;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_468;
    static jrt::Ref<jrt::Array<bool>> field_469;
    static jrt::Ref<jrt::Array<int32_t>> field_470;
    static jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_471;
    static jrt::Ref<jrt::Array<int32_t>> field_472;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_473;
    static jrt::Ref<jrt::Array<bool>> field_474;
    static jrt::Ref<jrt::Array<int32_t>> field_475;
    void __init();
    static void method_377(int32_t var0, jrt::Ref<java::lang::String> var1);
    static void method_378(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3);
    static void method_379(int32_t var0, jrt::Ref<java::lang::String> var1, int32_t var2);
    static jrt::Ref<class_44> method_380(int32_t var0);
    static jrt::Ref<class_108> method_381(int32_t var0);
    static void method_382();
    static void method_383();
    static void method_384();
    static void method_385();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_43"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_44 : public java::lang::Object {
public:
    void __init();
    static jrt::Ref<class_44> method_386(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0);
    virtual void method_387() = 0;
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_44"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_45 : public class_44 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> field_476{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1);
    virtual void method_387();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_45"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_46 : public java::lang::Object {
public:
    static int32_t field_477;
    static int32_t field_478;
    static int32_t field_479;
    static int32_t field_480;
    jrt::Ref<javax::microedition::lcdui::Image> field_481{};
    jrt::Ref<javax::microedition::lcdui::Image> field_482{};
    jrt::Ref<javax::microedition::lcdui::Image> field_483{};
    jrt::Ref<javax::microedition::lcdui::Image> field_484{};
    jrt::Ref<javax::microedition::lcdui::Image> field_485{};
    jrt::Ref<javax::microedition::lcdui::Image> field_486{};
    jrt::Ref<javax::microedition::lcdui::Image> field_487{};
    jrt::Ref<javax::microedition::lcdui::Image> field_488{};
    jrt::Ref<javax::microedition::lcdui::Image> field_489{};
    jrt::Ref<javax::microedition::lcdui::Image> field_490{};
    jrt::Ref<javax::microedition::lcdui::Image> field_491{};
    jrt::Ref<javax::microedition::lcdui::Image> field_492{};
    jrt::Ref<javax::microedition::lcdui::Image> field_493{};
    jrt::Ref<javax::microedition::lcdui::Image> field_494{};
    jrt::Ref<javax::microedition::lcdui::Image> field_495{};
    jrt::Ref<javax::microedition::lcdui::Image> field_496{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_497{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_498{};
    jrt::Ref<javax::microedition::lcdui::Image> field_499{};
    int32_t field_500{};
    int32_t field_501{};
    int32_t field_502{};
    int32_t field_503{};
    bool field_504{};
    bool field_505{};
    bool field_506{};
    bool field_507{};
    bool field_508{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_509{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_510{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_511{};
    jrt::Ref<jrt::Array<jrt::Ref<class_91>>> field_512{};
    jrt::Ref<class_18> field_513{};
    jrt::Ref<class_26> field_514{};
    jrt::Ref<class_57> field_515{};
    jrt::Ref<class_3> field_516{};
    jrt::Ref<class_3> field_517{};
    jrt::Ref<class_3> field_518{};
    jrt::Ref<class_3> field_519{};
    jrt::Ref<class_8> field_520{};
    int32_t field_521{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_522{};
    int32_t field_523{};
    jrt::Ref<java::lang::String> field_524{};
    jrt::Ref<javax::microedition::lcdui::Image> field_525{};
    jrt::Ref<javax::microedition::lcdui::Image> field_526{};
    void __init(jrt::Ref<class_26> var1);
    virtual void method_388();
    virtual void method_389(jrt::Ref<class_106> var1, jrt::Ref<class_91> var2);
    virtual void method_390(jrt::Ref<class_37> var1, jrt::Ref<class_106> var2);
    jrt::Ref<java::lang::String> method_391(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_37> var4);
    static float method_392(float var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_46"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_47 : public java::lang::Object {
public:
    int32_t field_527{};
    int32_t field_528{};
    int32_t field_529{};
    int32_t field_530{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_531{};
    int32_t field_532{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_533{};
    bool field_534{};
    bool field_535{};
    void __init();
    virtual void method_393(bool var1, bool var2);
    virtual void method_394();
    virtual void method_395();
    virtual void method_396();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_47"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_48 : public java::lang::Object {
public:
    static jrt::Ref<java::lang::String> field_536;
    static jrt::Ref<java::lang::String> field_537;
    static jrt::Ref<java::lang::String> field_538;
    void __init();
    static jrt::Ref<java::lang::String> method_397(int64_t var0);
    static jrt::Ref<java::lang::String> method_398(int64_t var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_48"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_49 : public java::lang::Object {
public:
    static jrt::Ref<java::io::InputStream> field_539;
    static jrt::Ref<jrt::Array<int8_t>> field_540;
    static jrt::Ref<java::lang::StringBuffer> field_541;
    static char16_t field_542;
    static jrt::Ref<jrt::Array<int8_t>> field_543;
    static jrt::Ref<java::lang::String> field_544;
    static jrt::Ref<java::lang::Class> field_545;
    void __init();
    static void method_399(jrt::Ref<java::lang::String> var0);
    static jrt::Ref<class_86> method_400(int32_t var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_86>>> method_401(jrt::Ref<jrt::Array<int16_t>> var0);
    static jrt::Ref<jrt::Array<jrt::Ref<class_40>>> method_402();
    static void method_403();
    static jrt::Ref<jrt::Array<int8_t>> method_404();
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_405();
    static jrt::Ref<jrt::Array<jrt::Ref<class_19>>> method_406();
    static jrt::Ref<jrt::Array<jrt::Ref<class_68>>> method_407();
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> method_408(int32_t var0, bool var1);
    static jrt::Ref<java::lang::Class> method_409(jrt::Ref<java::lang::String> var0);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_49"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_4 : public java::lang::Object {
public:
    jrt::Ref<class_106> field_40{};
    jrt::Ref<class_102> field_41{};
    jrt::Ref<jrt::Array<jrt::Ref<class_6>>> field_42{};
    jrt::Ref<jrt::Array<bool>> field_43{};
    jrt::Ref<class_71> field_44{};
    static int32_t deep3dKind;
    void __init(jrt::Ref<class_71> var1);
    virtual void method_24(jrt::Ref<class_106> var1);
    virtual void method_25(jrt::Ref<class_102> var1);
    virtual void method_26();
    virtual void method_27(int64_t var1);
    virtual void method_28(bool var1);
    virtual void method_29();
    virtual void method_30(int32_t var1, jrt::Ref<class_108> var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_4"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_50 : public java::lang::Object {
public:
    static int32_t field_546;
    bool field_547{};
    jrt::Ref<class_121> field_548{};
    jrt::Ref<class_77> field_549{};
    jrt::Ref<class_23> field_550{};
    jrt::Ref<class_23> field_551{};
    void __init();
    virtual void method_410();
    virtual bool method_411(int32_t var1);
    virtual bool method_412();
    virtual void method_413(int32_t var1, int32_t var2);
    virtual void method_414();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_50"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_51 : public java::lang::Object {
public:
    static int32_t field_552;
    static int32_t field_553;
    static int32_t field_554;
    static jrt::Ref<jrt::Array<int32_t>> field_555;
    jrt::Ref<javax::microedition::lcdui::Image> field_556{};
    int32_t field_557{};
    int32_t field_558{};
    int32_t field_559{};
    int32_t field_560{};
    jrt::Ref<java::lang::String> field_561{};
    jrt::Ref<class_121> field_562{};
    bool field_563{};
    bool field_564{};
    jrt::Ref<jrt::Array<jrt::Ref<class_41>>> field_565{};
    jrt::Ref<java::lang::String> field_566{};
    jrt::Ref<class_75> field_567{};
    jrt::Ref<class_23> field_568{};
    jrt::Ref<class_23> field_569{};
    jrt::Ref<class_23> field_570{};
    jrt::Ref<class_32> field_571{};
    int32_t field_572{};
    jrt::Ref<jrt::Array<int8_t>> field_573{};
    jrt::Ref<class_53> field_574{};
    jrt::Ref<class_80> field_575{};
    int32_t field_576{};
    static bool field_577;
    bool field_578{};
    jrt::Ref<java::lang::String> field_579{};
    jrt::Ref<java::lang::String> field_580{};
    jrt::Ref<java::lang::String> field_581{};
    int32_t field_582{};
    void __init();
    jrt::Ref<java::lang::String> method_415(jrt::Ref<java::lang::String> var1);
    void method_416();
    virtual void method_417();
    virtual void method_418(int32_t var1, int32_t var2);
    virtual bool method_419();
    virtual void method_420(int32_t var1);
    virtual void method_421(int32_t var1);
    virtual void method_422();
    void method_423();
    virtual void method_424();
    virtual bool method_425();
    virtual bool method_426();
    virtual void method_427(int32_t var1);
    virtual void method_428();
    virtual void method_429();
    virtual void method_430(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_51"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_51__anon1 : public java::lang::Object, public virtual org::deep3d::GameSettings_Toggle {
public:
    class_51* __outer = nullptr;
    void __init();
    virtual bool get();
    virtual void set(bool var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_51$1"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_51__anon2 : public java::lang::Object, public virtual org::deep3d::GameSettings_Toggle {
public:
    class_51* __outer = nullptr;
    void __init();
    virtual bool get();
    virtual void set(bool var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_51$2"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_52 : public java::lang::Object {
public:
    int32_t field_583{};
    int32_t field_584{};
    int32_t field_585{};
    int32_t field_586{};
    int32_t field_587{};
    jrt::Ref<class_120> field_588{};
    int32_t field_589{};
    void __init(int32_t var1, int32_t var2, int32_t var3);
    void __init();
    virtual void method_431(jrt::Ref<class_120> var1);
    virtual bool method_432();
    virtual void method_433();
    virtual void method_434();
    virtual void method_435();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_52"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_53 : public java::lang::Object, public virtual javax::microedition::lcdui::CommandListener, public virtual javax::microedition::media::PlayerListener {
public:
    jrt::Ref<javax::microedition::media::Player> field_590{};
    jrt::Ref<javax::microedition::media::control::VideoControl> field_591{};
    jrt::Ref<javax::microedition::lcdui::Image> field_592{};
    jrt::Ref<jrt::Array<int8_t>> field_593{};
    jrt::Ref<javax::microedition::lcdui::Form> field_594{};
    void __init();
    virtual void method_436();
    virtual jrt::Ref<javax::microedition::lcdui::Image> method_437();
    virtual void method_438();
    virtual void playerUpdate(jrt::Ref<javax::microedition::media::Player> var1, jrt::Ref<java::lang::String> var2, jrt::Ref<java::lang::Object> var3);
    virtual void commandAction(jrt::Ref<javax::microedition::lcdui::Command> var1, jrt::Ref<javax::microedition::lcdui::Displayable> var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_53"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_54 : public java::lang::Object {
public:
    jrt::Ref<class_61> field_595{};
    jrt::Ref<DeepMIDlet> field_596{};
    jrt::Ref<class_33> field_597{};
    void __init(jrt::Ref<DeepMIDlet> var1, jrt::Ref<class_33> var2);
    virtual void method_439(jrt::Ref<class_61> var1);
    virtual void method_440();
    virtual void method_441(int32_t var1);
    virtual void method_442(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_54"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_55 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<int32_t>> field_598;
    static jrt::Ref<jrt::Array<int32_t>> field_599;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_600;
    int32_t field_601{};
    int32_t field_602{};
    bool field_603{};
    int32_t field_604{};
    int32_t field_605{};
    int32_t field_606{};
    int32_t field_607{};
    float field_608{};
    float field_609{};
    int32_t field_610{};
    int32_t field_611{};
    int32_t field_612{};
    int32_t field_613{};
    float field_614{};
    float field_615{};
    float field_616{};
    float field_617{};
    jrt::Ref<jrt::Array<int32_t>> field_618{};
    float field_619{};
    float field_620{};
    jrt::Ref<class_121> field_621{};
    jrt::Ref<class_79> field_622{};
    int32_t field_623{};
    jrt::Ref<jrt::Array<jrt::Ref<class_86>>> field_624{};
    jrt::Ref<jrt::Array<int16_t>> field_625{};
    jrt::Ref<jrt::Array<int16_t>> field_626{};
    jrt::Ref<jrt::Array<int16_t>> field_627{};
    jrt::Ref<jrt::Array<float>> field_628{};
    int32_t field_629{};
    int32_t field_630{};
    int32_t field_631{};
    int32_t field_632{};
    int32_t field_633{};
    jrt::Ref<javax::microedition::lcdui::Image> field_634{};
    jrt::Ref<javax::microedition::lcdui::Image> field_635{};
    jrt::Ref<javax::microedition::lcdui::Image> field_636{};
    jrt::Ref<javax::microedition::lcdui::Image> field_637{};
    jrt::Ref<javax::microedition::lcdui::Image> field_638{};
    jrt::Ref<javax::microedition::lcdui::Image> field_639{};
    jrt::Ref<javax::microedition::lcdui::Image> field_640{};
    jrt::Ref<javax::microedition::lcdui::Image> field_641{};
    jrt::Ref<javax::microedition::lcdui::Image> field_642{};
    jrt::Ref<javax::microedition::lcdui::Image> field_643{};
    jrt::Ref<javax::microedition::lcdui::Image> field_644{};
    jrt::Ref<javax::microedition::lcdui::Image> field_645{};
    jrt::Ref<javax::microedition::lcdui::Image> field_646{};
    jrt::Ref<javax::microedition::lcdui::Image> field_647{};
    jrt::Ref<javax::microedition::lcdui::Image> field_648{};
    jrt::Ref<javax::microedition::lcdui::Image> field_649{};
    jrt::Ref<class_3> field_650{};
    int32_t field_651{};
    jrt::Ref<java::lang::String> field_652{};
    jrt::Ref<java::lang::String> field_653{};
    bool field_654{};
    int32_t field_655{};
    jrt::Ref<class_87> field_656{};
    jrt::Ref<class_87> field_657{};
    bool field_658{};
    bool field_659{};
    bool field_660{};
    bool field_661{};
    jrt::Ref<jrt::Array<bool>> field_662{};
    jrt::Ref<jrt::Array<bool>> field_663{};
    int32_t field_664{};
    jrt::Ref<jrt::Array<int32_t>> field_665{};
    bool field_666{};
    int32_t field_667{};
    int32_t field_668{};
    int32_t field_669{};
    bool field_670{};
    bool field_671{};
    int32_t field_672{};
    void __init();
    virtual void method_443();
    virtual bool method_444();
    virtual void method_445(jrt::Ref<class_87> var1);
    virtual void method_446();
    virtual bool method_447(int32_t var1);
    virtual void method_448();
    virtual bool method_449();
    virtual bool method_450(int32_t var1, int32_t var2);
    void method_451();
    void method_452(float var1, float var2);
    void method_453(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    void method_454();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_55"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_56 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_673;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_674;
    jrt::Ref<javax::microedition::lcdui::Image> field_675{};
    jrt::Ref<jrt::Array<int8_t>> field_676{};
    jrt::Ref<java::lang::String> field_677{};
    jrt::Ref<java::lang::String> field_678{};
    jrt::Ref<class_23> field_679{};
    int32_t field_680{};
    int32_t field_681{};
    jrt::Ref<class_87> field_682{};
    jrt::Ref<class_121> field_683{};
    bool field_684{};
    void __init(jrt::Ref<class_87> var1, int32_t var2);
    void __init();
    void __init(jrt::Ref<java::lang::String> var1, bool var2);
    void __init(jrt::Ref<java::lang::String> var1);
    static bool method_455(int32_t var0);
    static bool method_456(int32_t var0);
    virtual void method_457(jrt::Ref<class_87> var1, int32_t var2);
    virtual void method_458();
    virtual bool method_459(int32_t var1);
    virtual bool method_460(int32_t var1, int32_t var2);
    virtual int32_t method_461();
    virtual bool method_462();
    virtual bool method_463();
    virtual bool method_464();
    virtual bool method_465();
    void method_466();
    virtual void method_467();
    virtual void method_468();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_56"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_57 : public java::lang::Object {
public:
    int16_t field_685{};
    int32_t field_686{};
    int32_t field_687{};
    int32_t field_688{};
    int32_t field_689{};
    int32_t field_690{};
    int32_t field_691{};
    int32_t field_692{};
    int32_t field_693{};
    int32_t field_694{};
    int32_t field_695{};
    int32_t field_696{};
    int32_t field_697{};
    int32_t field_698{};
    int32_t field_699{};
    int32_t field_700{};
    int32_t field_701{};
    int32_t field_702{};
    int32_t field_703{};
    bool field_704{};
    static jrt::Ref<class_3> field_705;
    void __init();
    void __init(jrt::Ref<class_57> var1);
    virtual void method_469();
    virtual void method_470(jrt::Ref<class_57> var1);
    virtual void method_471(jrt::Ref<class_57> var1);
    virtual void method_472(jrt::Ref<class_57> var1);
    virtual jrt::Ref<class_57> method_473(jrt::Ref<class_57> var1, jrt::Ref<class_57> var2);
    virtual void method_474(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_475(jrt::Ref<class_3> var1);
    virtual void method_476(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_477(jrt::Ref<class_3> var1);
    virtual void method_478(int32_t var1);
    virtual jrt::Ref<class_3> method_479(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_480();
    virtual jrt::Ref<class_3> method_481(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_482(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_483();
    virtual jrt::Ref<class_3> method_484(jrt::Ref<class_3> var1);
    virtual void method_485(int16_t var1);
    virtual void method_486(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_487(int32_t var1);
    virtual void method_488(int32_t var1);
    virtual void method_489(int32_t var1);
    virtual void method_490(int32_t var1);
    virtual void method_491(int32_t var1, int32_t var2, int32_t var3);
    virtual int32_t method_492();
    void method_493();
    virtual void method_494(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    virtual void method_495(jrt::Ref<class_123> var1);
    int32_t method_496(int32_t var1);
    int32_t method_497(int32_t var1);
    virtual jrt::Ref<class_123> method_498(jrt::Ref<class_123> var1);
    virtual jrt::Ref<class_123> method_499();
    virtual void method_500(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_501(int32_t var1, int32_t var2, int32_t var3);
    virtual jrt::Ref<class_3> method_502(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_57> method_503(jrt::Ref<class_57> var1);
    virtual void method_504(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2, jrt::Ref<class_3> var3);
    virtual void method_505(jrt::Ref<jrt::Array<float>> var1);
    virtual jrt::Ref<java::lang::String> toString();
    virtual jrt::Ref<class_3> method_506(jrt::Ref<class_3> var1);
    virtual jrt::Ref<class_3> method_507(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual jrt::Ref<class_3> method_508(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual jrt::Ref<class_3> method_509(jrt::Ref<class_3> var1, jrt::Ref<class_3> var2);
    virtual jrt::Ref<jrt::Array<jrt::Ref<class_3>>> method_510(jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var1, jrt::Ref<jrt::Array<jrt::Ref<class_3>>> var2);
    virtual jrt::Ref<class_3> method_511(jrt::Ref<class_3> var1);
    virtual void method_512(jrt::Ref<class_3> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_57"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_58 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<class_73>>> field_706;
    static jrt::Ref<javax::microedition::lcdui::Graphics> field_707;
    static int32_t field_708;
    void __init();
    static void method_513();
    static void method_514(jrt::Ref<javax::microedition::lcdui::Graphics> var0);
    static void method_515(jrt::Ref<java::lang::String> var0);
    static void method_516(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    static void method_517(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2);
    static void method_518(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3);
    static void method_519(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    static void method_520(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6);
    static void method_521(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0, int32_t var1, int32_t var2, int32_t var3);
    static void method_522(int32_t var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    static int32_t method_523(jrt::Ref<java::lang::String> var0);
    static int32_t method_524(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2);
    static void method_525(int32_t var0);
    static void method_526(int32_t var0, int32_t var1);
    static int32_t method_527();
    static int32_t method_528();
    static void method_529(int32_t var0);
    static int32_t method_530(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var0);
    static void method_531(int32_t var0, int32_t var1);
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> method_532(jrt::Ref<java::lang::String> var0, int32_t var1);
    static jrt::Ref<java::lang::String> method_533(jrt::Ref<java::lang::String> var0, int32_t var1, bool var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_58"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_59 : public java::lang::Object {
public:
    jrt::Ref<class_68> field_709{};
    jrt::Ref<class_19> field_710{};
    jrt::Ref<class_120> field_711{};
    jrt::Ref<class_87> field_712{};
    bool field_713{};
    jrt::Ref<java::lang::String> field_714{};
    int32_t field_715{};
    int32_t field_716{};
    jrt::Ref<javax::microedition::lcdui::Image> field_717{};
    void __init(jrt::Ref<javax::microedition::lcdui::Image> var1, int32_t var2, jrt::Ref<java::lang::String> var3);
    void __init(jrt::Ref<class_68> var1);
    void __init(jrt::Ref<class_19> var1);
    void __init(jrt::Ref<class_120> var1);
    void __init(jrt::Ref<java::lang::String> var1);
    void __init(int32_t var1);
    void __init(int32_t var1, int32_t var2);
    void __init(jrt::Ref<class_87> var1);
    virtual bool method_534();
    virtual bool method_535();
    virtual bool method_536();
    virtual bool method_537();
    virtual bool method_538();
    virtual bool method_539();
    virtual bool method_540();
    virtual bool method_541();
    virtual bool method_542();
    virtual bool method_543();
    virtual int32_t method_544();
    virtual int32_t method_545();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_59"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_5 : public java::lang::Object, public virtual class_0 {
public:
    jrt::Ref<class_102> field_45{};
    jrt::Ref<class_102> field_46{};
    int32_t field_47{};
    jrt::Ref<class_102> field_48{};
    static jrt::Ref<class_3> field_49;
    static jrt::Ref<class_3> field_50;
    static jrt::Ref<class_3> field_51;
    jrt::Ref<class_3> field_52{};
    bool field_53{};
    void __init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2);
    void __init(jrt::Ref<class_102> var1, jrt::Ref<class_102> var2, jrt::Ref<class_3> var3, int32_t var4);
    virtual void method_31(jrt::Ref<class_3> var1, int32_t var2);
    virtual void method_0();
    virtual bool method_1();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_5"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_60 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<int32_t>> field_718{};
    jrt::Ref<jrt::Array<int32_t>> field_719{};
    jrt::Ref<jrt::Array<int32_t>> field_720{};
    jrt::Ref<class_3> field_721{};
    jrt::Ref<class_3> field_722{};
    jrt::Ref<class_108> field_723{};
    void __init();
    virtual void method_546();
    virtual void method_547(int64_t var1, jrt::Ref<class_57> var3, bool var4);
    virtual void method_548();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_60"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_61 : public java::lang::Object {
public:
    void __init();
    virtual void method_549(int32_t var1) = 0;
    virtual void method_550(int32_t var1) = 0;
    virtual void method_551() = 0;
    virtual void method_552() = 0;
    virtual bool method_553() = 0;
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_61"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_62 : public class_61 {
public:
    jrt::Ref<javax::microedition::lcdui::Image> field_724{};
    jrt::Ref<javax::microedition::lcdui::Image> field_725{};
    bool field_726{};
    int64_t field_727{};
    int32_t field_728{};
    int32_t field_729{};
    int32_t field_730{};
    jrt::Ref<jrt::Array<int8_t>> field_731{};
    void __init();
    virtual void method_551();
    virtual void method_552();
    virtual bool method_553();
    virtual void method_550(int32_t var1);
    virtual void method_549(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_62"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_63 : public class_61 {
public:
    int64_t field_732{};
    int64_t field_733{};
    int64_t field_734{};
    int64_t field_735{};
    int64_t field_736{};
    int32_t field_737{};
    jrt::Ref<jrt::Array<int32_t>> field_738{};
    jrt::Ref<javax::microedition::lcdui::Image> field_739{};
    jrt::Ref<class_65> field_740{};
    jrt::Ref<class_51> field_741{};
    bool field_742{};
    bool field_743{};
    bool field_744{};
    bool field_745{};
    bool field_746{};
    bool field_747{};
    bool field_748{};
    bool field_749{};
    bool field_750{};
    bool field_751{};
    bool field_752{};
    bool field_753{};
    jrt::Ref<class_121> field_754{};
    jrt::Ref<class_36> field_755{};
    jrt::Ref<class_89> field_756{};
    jrt::Ref<class_55> field_757{};
    jrt::Ref<class_17> field_758{};
    jrt::Ref<class_50> field_759{};
    jrt::Ref<class_56> field_760{};
    jrt::Ref<class_56> field_761{};
    jrt::Ref<class_12> field_762{};
    jrt::Ref<class_122> field_763{};
    jrt::Ref<class_87> field_764{};
    int32_t field_765{};
    int32_t field_766{};
    int32_t field_767{};
    bool field_768{};
    bool field_769{};
    bool field_770{};
    int32_t field_771{};
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int32_t>>>> field_772{};
    int32_t field_773{};
    bool field_774{};
    bool field_775{};
    int32_t field_776{};
    bool field_777{};
    void __init();
    virtual void method_552();
    virtual void method_554();
    virtual void method_551();
    void method_555(jrt::Ref<java::lang::String> var1);
    void method_556();
    virtual bool method_553();
    virtual void method_549(int32_t var1);
    virtual void method_557();
    void method_558();
    virtual void method_550(int32_t var1);
    void method_559();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_63"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_64 : public class_61 {
public:
    int32_t field_778{};
    int64_t field_779{};
    int64_t field_780{};
    int64_t field_781{};
    int64_t field_782{};
    int64_t field_783{};
    int64_t field_784{};
    int64_t field_785{};
    bool field_786{};
    jrt::Ref<class_70> field_787{};
    jrt::Ref<class_106> field_788{};
    jrt::Ref<class_104> field_789{};
    jrt::Ref<class_42> field_790{};
    jrt::Ref<class_5> field_791{};
    bool field_792{};
    bool field_793{};
    bool field_794{};
    bool field_795{};
    bool field_796{};
    int32_t field_797{};
    int32_t field_798{};
    int32_t deep3dFov{};
    jrt::Ref<class_26> field_799{};
    jrt::Ref<class_118> field_800{};
    jrt::Ref<class_46> field_801{};
    jrt::Ref<class_34> field_802{};
    jrt::Ref<class_51> field_803{};
    jrt::Ref<class_56> field_804{};
    jrt::Ref<class_56> field_805{};
    jrt::Ref<class_55> field_806{};
    jrt::Ref<class_2> field_807{};
    jrt::Ref<class_121> field_808{};
    bool field_809{};
    bool field_810{};
    bool field_811{};
    bool field_812{};
    bool field_813{};
    bool field_814{};
    bool field_815{};
    int32_t field_816{};
    bool field_817{};
    void __init();
    virtual void method_552();
    virtual void method_551();
    void method_560();
    virtual bool method_553();
    virtual void method_549(int32_t var1);
    void method_561();
    void method_562();
    void method_563();
    bool method_564();
    virtual void method_565();
    virtual bool method_566(int32_t var1, int32_t var2);
    virtual void method_567();
    virtual void method_550(int32_t var1);
    static float deep3dDolly();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_64"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_65 : public class_61 {
public:
    int64_t field_818{};
    int64_t field_819{};
    int64_t field_820{};
    int64_t field_821{};
    int32_t field_822{};
    bool field_823{};
    jrt::Ref<class_104> field_824{};
    jrt::Ref<class_106> field_825{};
    jrt::Ref<class_39> field_826{};
    jrt::Ref<class_42> field_827{};
    jrt::Ref<class_5> field_828{};
    jrt::Ref<class_70> field_829{};
    jrt::Ref<class_26> field_830{};
    int32_t field_831{};
    jrt::Ref<class_3> field_832{};
    int32_t field_833{};
    jrt::Ref<class_60> field_834{};
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_835{};
    jrt::Ref<class_103> field_836{};
    void __init(int32_t var1);
    virtual void method_552();
    virtual void method_551();
    virtual bool method_553();
    virtual void method_568(int32_t var1, int32_t var2);
    virtual void method_569(int32_t var1);
    virtual void method_570();
    virtual void method_571();
    virtual void method_549(int32_t var1);
    void method_572();
    virtual void method_550(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_65"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_66 : public class_61 {
public:
    int64_t field_837{};
    int64_t field_838{};
    int64_t field_839{};
    int64_t field_840{};
    bool field_841{};
    jrt::Ref<class_65> field_842{};
    jrt::Ref<class_51> field_843{};
    void __init();
    virtual void method_552();
    virtual void method_551();
    virtual bool method_553();
    virtual void method_549(int32_t var1);
    void method_573();
    virtual void method_550(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_66"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_67 : public java::lang::Object {
public:
    static int32_t field_844;
    static int32_t field_845;
    static int32_t field_846;
    static int32_t field_847;
    static int32_t field_848;
    static int32_t field_849;
    static int32_t field_850;
    static int32_t field_851;
    static int32_t field_852;
    static jrt::Ref<javax::microedition::lcdui::Image> field_853;
    static jrt::Ref<javax::microedition::lcdui::Image> field_854;
    static jrt::Ref<javax::microedition::lcdui::Image> field_855;
    static jrt::Ref<javax::microedition::lcdui::Image> field_856;
    static jrt::Ref<jrt::Array<int32_t>> field_857;
    static int64_t field_858;
    static int64_t field_859;
    static int32_t field_860;
    static bool field_861;
    static bool field_862;
    void __init();
    static void method_574();
    static bool method_575();
    static void method_576();
    static int32_t method_577();
    static void method_578(bool var0);
    static void method_579(int32_t var0);
    static bool method_580();
    static bool method_581();
    static void method_582(int32_t var0, int32_t var1, int32_t var2, int32_t var3);
    static void method_583();
    static void method_584(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4);
    static void method_585(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4, bool var5, bool var6);
    static void method_586(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, bool var4, bool var5);
    static void method_587();
    static void method_588(jrt::Ref<java::lang::String> var0);
    static void method_589(jrt::Ref<java::lang::String> var0, int32_t var1, bool var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6);
    static void method_590(int32_t var0, bool var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    static void method_591(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    static void method_592(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, bool var5);
    static void method_593(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1);
    static void method_594(bool var0);
    static bool method_595();
    static void method_596();
    static void method_597(bool var0);
    static void method_598(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    static void method_599(jrt::Ref<java::lang::String> var0, int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5);
    static jrt::Ref<java::lang::String> method_600(jrt::Ref<java::lang::String> var0, int32_t var1);
    static void method_601(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1, bool var2);
    static void method_602(jrt::Ref<java::lang::String> var0, jrt::Ref<java::lang::String> var1, bool var2, bool var3);
    static jrt::Ref<jrt::Array<int32_t>> deep3dBar(jrt::Ref<java::lang::String> lk, jrt::Ref<java::lang::String> ll, jrt::Ref<java::lang::String> rk, jrt::Ref<java::lang::String> rl);
    static int32_t drawCommand(jrt::Ref<java::lang::String> label, jrt::Ref<java::lang::String> key, int32_t x, int32_t y, int32_t h, bool alignRight, bool lit);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_67"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_68 : public java::lang::Object {
public:
    int32_t field_863{};
    int32_t field_864{};
    int32_t field_865{};
    int32_t field_866{};
    int32_t field_867{};
    int32_t field_868{};
    int32_t field_869{};
    float field_870{};
    int32_t field_871{};
    int32_t field_872{};
    int32_t field_873{};
    int32_t field_874{};
    int32_t field_875{};
    int32_t field_876{};
    int32_t field_877{};
    int32_t field_878{};
    int32_t field_879{};
    int32_t field_880{};
    int32_t field_881{};
    int32_t field_882{};
    bool field_883{};
    bool field_884{};
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> field_885{};
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> field_886{};
    int32_t field_887{};
    int32_t field_888{};
    int32_t field_889{};
    int32_t field_890{};
    int32_t field_891{};
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> field_892{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, float var6);
    virtual int32_t method_603();
    virtual int32_t method_604();
    virtual bool method_605();
    virtual int32_t method_606();
    virtual int32_t method_607();
    virtual void method_608(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    virtual bool method_609(int32_t var1);
    virtual bool method_610(int32_t var1, int32_t var2);
    virtual void method_611(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    virtual bool method_612(int32_t var1);
    virtual void method_613(jrt::Ref<class_120> var1);
    virtual void method_614(jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var1);
    virtual void method_615(jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var1);
    virtual void method_616(jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var1);
    virtual void method_617(jrt::Ref<class_19> var1);
    virtual void method_618();
    virtual void method_619();
    virtual int32_t method_620();
    virtual int32_t method_621();
    virtual void method_622(jrt::Ref<class_19> var1);
    virtual int32_t method_623();
    virtual int32_t method_624();
    virtual bool method_625(int32_t var1);
    virtual bool method_626();
    virtual jrt::Ref<class_68> method_627();
    virtual void method_628();
    virtual void method_629();
    virtual jrt::Ref<class_68> method_630();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_68"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_69 : public java::lang::Object {
public:
    static int32_t field_893;
    static int32_t field_894;
    static int32_t field_895;
    static int32_t field_896;
    static int32_t field_897;
    static int32_t field_898;
    static int32_t field_899;
    static int32_t field_900;
    static int32_t field_901;
    static int32_t field_902;
    static int32_t field_903;
    static int32_t field_904;
    static int32_t field_905;
    static int32_t field_906;
    static int32_t field_907;
    static int32_t field_908;
    static int32_t field_909;
    static int32_t field_910;
    static int32_t field_911;
    static jrt::Ref<javax::microedition::lcdui::Image> field_912;
    static jrt::Ref<javax::microedition::lcdui::Image> field_913;
    static jrt::Ref<javax::microedition::lcdui::Image> field_914;
    static jrt::Ref<javax::microedition::lcdui::Image> field_915;
    static jrt::Ref<javax::microedition::lcdui::Image> field_916;
    static jrt::Ref<javax::microedition::lcdui::Image> field_917;
    static jrt::Ref<javax::microedition::lcdui::Image> field_918;
    static jrt::Ref<javax::microedition::lcdui::Image> field_919;
    static jrt::Ref<javax::microedition::lcdui::Image> field_920;
    static jrt::Ref<javax::microedition::lcdui::Image> field_921;
    static jrt::Ref<javax::microedition::lcdui::Image> field_922;
    static jrt::Ref<javax::microedition::lcdui::Image> field_923;
    static jrt::Ref<javax::microedition::lcdui::Image> field_924;
    static jrt::Ref<javax::microedition::lcdui::Image> field_925;
    static jrt::Ref<javax::microedition::lcdui::Image> field_926;
    static jrt::Ref<javax::microedition::lcdui::Image> field_927;
    static jrt::Ref<javax::microedition::lcdui::Image> field_928;
    static jrt::Ref<javax::microedition::lcdui::game::Sprite> field_929;
    static jrt::Ref<javax::microedition::lcdui::Image> field_930;
    static jrt::Ref<javax::microedition::lcdui::Image> field_931;
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_932;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_933;
    static float field_934;
    static int32_t field_935;
    static int32_t field_936;
    static int32_t field_937;
    static int32_t field_938;
    static int32_t field_939;
    static int32_t field_940;
    static bool field_941;
    static bool field_942;
    static bool field_943;
    static bool field_944;
    static jrt::Ref<java::lang::String> field_945;
    static bool field_946;
    static int32_t field_947;
    static int32_t field_948;
    static int32_t field_949;
    static jrt::Ref<java::lang::String> field_950;
    static jrt::Ref<java::lang::String> field_951;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_952;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_953;
    static bool field_954;
    static int32_t field_955;
    static bool field_956;
    static bool field_957;
    static bool field_958;
    static bool field_959;
    static int32_t field_960;
    static jrt::Ref<java::lang::String> field_961;
    static jrt::Ref<javax::microedition::lcdui::Image> field_962;
    static bool field_963;
    static bool field_964;
    static bool field_965;
    void __init();
    static void method_631();
    static void method_632();
    static void method_633(int32_t var0, jrt::Ref<class_70> var1);
    static void method_634(int32_t var0, int32_t var1, jrt::Ref<java::lang::String> var2);
    static void method_635();
    static void method_636(int32_t var0);
    static bool method_637();
    static void method_638(jrt::Ref<java::lang::String> var0);
    static void method_639(int32_t var0);
    static void method_640(int32_t var0, int32_t var1, bool var2, bool var3);
    static bool method_641();
    static void method_642(int64_t var0, jrt::Ref<class_70> var2, bool var3);
    static void method_643(jrt::Ref<java::lang::String> var0, bool var1);
    static void method_644(int64_t var0, int64_t var2, jrt::Ref<class_70> var4, bool var5);
    static void method_645(bool var0);
    static void method_646();
    static void method_647();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_69"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_6 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_108>>> field_54{};
    int32_t field_55{};
    jrt::Ref<jrt::Array<int32_t>> deep3dKind{};
    void __init();
    virtual void deep3dTag(int32_t kind);
    virtual void method_32(jrt::Ref<class_108> var1);
    virtual void method_33();
    virtual void method_34(int64_t var1);
    virtual void method_35();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_6"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_70 : public java::lang::Object {
public:
    static int32_t field_966;
    static int32_t field_967;
    static int32_t field_968;
    jrt::Ref<class_37> field_969{};
    jrt::Ref<class_108> field_970{};
    jrt::Ref<class_108> field_971{};
    jrt::Ref<class_5> field_972{};
    jrt::Ref<class_104> field_973{};
    jrt::Ref<class_3> field_974{};
    jrt::Ref<class_3> field_975{};
    jrt::Ref<class_60> field_976{};
    jrt::Ref<class_82> field_977{};
    jrt::Ref<class_11> field_978{};
    jrt::Ref<class_85> field_979{};
    jrt::Ref<class_25> field_980{};
    jrt::Ref<class_26> field_981{};
    jrt::Ref<class_18> field_982{};
    int32_t field_983{};
    float field_984{};
    float field_985{};
    int32_t field_986{};
    int32_t field_987{};
    int64_t field_988{};
    int64_t field_989{};
    int32_t field_990{};
    bool field_991{};
    int64_t field_992{};
    int32_t field_993{};
    bool field_994{};
    int32_t field_995{};
    int32_t field_996{};
    bool field_997{};
    bool field_998{};
    bool field_999{};
    jrt::Ref<class_3> field_1000{};
    jrt::Ref<class_3> field_1001{};
    jrt::Ref<class_57> field_1002{};
    int32_t field_1003{};
    int32_t field_1004{};
    float field_1005{};
    int32_t field_1006{};
    bool field_1007{};
    jrt::Ref<class_91> field_1008{};
    bool field_1009{};
    jrt::Ref<class_3> field_1010{};
    jrt::Ref<class_108> field_1011{};
    jrt::Ref<class_108> field_1012{};
    int32_t field_1013{};
    int32_t field_1014{};
    bool field_1015{};
    void __init(jrt::Ref<class_37> var1);
    virtual void method_648(jrt::Ref<class_108> var1);
    virtual void method_649();
    virtual void method_650();
    virtual bool method_651();
    virtual float method_652();
    virtual float method_653();
    virtual void method_654();
    virtual bool method_655();
    virtual void method_656(int64_t var1);
    virtual void method_657(jrt::Ref<class_9> var1, int32_t var2);
    virtual void method_658(jrt::Ref<jrt::Array<jrt::Ref<class_9>>> var1, int32_t var2);
    virtual int32_t method_659();
    virtual int32_t method_660();
    virtual void method_661();
    virtual bool method_662();
    virtual int32_t method_663();
    virtual jrt::Ref<class_3> method_664();
    virtual float method_665();
    virtual void method_666(bool var1);
    virtual void method_667(jrt::Ref<class_91> var1);
    virtual bool method_668();
    virtual bool method_669();
    virtual void method_670(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_671(int64_t var1);
    void method_672(jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var1);
    virtual void method_673(int64_t var1);
    virtual void method_674(int64_t var1);
    virtual void steerAnalog(int64_t var1, float yaw, float pitch);
    virtual void method_675(int64_t var1);
    virtual void method_676(int64_t var1);
    virtual void method_677(int32_t var1);
    void method_678(int64_t var1);
    virtual void method_679();
    virtual void method_680();
    virtual void method_681(bool var1);
    virtual void method_682(bool var1, jrt::Ref<class_106> var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_70"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_71 : public java::lang::Object {
public:
    void __init();
    virtual void method_683(jrt::Ref<javax::microedition::lcdui::Graphics> var1) = 0;
    virtual void method_684(jrt::Ref<javax::microedition::lcdui::Graphics> var1) = 0;
    virtual void method_685() = 0;
    static jrt::Ref<class_71> method_686();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_71"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_72 : public class_71 {
public:
    static jrt::Ref<javax::microedition::m3g::Graphics3D> field_1016;
    static jrt::Ref<javax::microedition::m3g::Background> field_1017;
    void __init();
    virtual void method_683(jrt::Ref<javax::microedition::lcdui::Graphics> var1);
    virtual void method_685();
    virtual void method_684(jrt::Ref<javax::microedition::lcdui::Graphics> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_72"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_73 : public java::lang::Object {
public:
    jrt::Ref<javax::microedition::lcdui::Image> field_1018{};
    jrt::Ref<jrt::Array<int16_t>> field_1019{};
    jrt::Ref<jrt::Array<int16_t>> field_1020{};
    jrt::Ref<jrt::Array<int8_t>> field_1021{};
    int8_t field_1022{};
    int8_t field_1023{};
    int8_t field_1024{};
    static jrt::Ref<javax::microedition::lcdui::Graphics> field_1025;
    int8_t field_1026{};
    void __init(jrt::Ref<java::lang::String> var1, jrt::Ref<javax::microedition::lcdui::Graphics> var2);
    virtual void method_687(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    virtual void method_688(int32_t var1);
    int8_t method_689(int32_t var1, int32_t var2, jrt::Ref<jrt::Array<int32_t>> var3);
    virtual int32_t method_690(jrt::Ref<java::lang::String> var1);
    virtual int32_t method_691(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3);
    virtual int32_t method_692(char16_t var1);
    virtual void method_693(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3);
    virtual void method_694(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3);
    virtual void method_695(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3);
    virtual void method_696(int32_t var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_73"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_74 : public java::lang::Object {
public:
    int32_t field_1027{};
    int32_t field_1028{};
    int32_t field_1029{};
    int32_t field_1030{};
    jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1031{};
    jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<java::lang::Object>>>>> field_1032{};
    jrt::Ref<jrt::Array<int32_t>> field_1033{};
    int32_t field_1034{};
    int32_t field_1035{};
    int32_t field_1036{};
    bool field_1037{};
    int32_t field_1038{};
    int32_t field_1039{};
    int32_t field_1040{};
    int32_t field_1041{};
    int32_t field_1042{};
    int32_t field_1043{};
    int32_t field_1044{};
    int32_t field_1045{};
    int32_t field_1046{};
    bool field_1047{};
    bool field_1048{};
    int32_t field_1049{};
    jrt::Ref<java::lang::String> field_1050{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6);
    virtual void method_697(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6);
    virtual int32_t method_698();
    virtual int32_t method_699();
    virtual void method_700(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<java::lang::Object>>> var2);
    virtual jrt::Ref<java::lang::Object> method_701();
    virtual void method_702(int32_t var1);
    virtual void method_703();
    virtual void method_704();
    virtual void method_705();
    virtual void method_706();
    virtual void method_707();
    virtual void method_708();
    virtual void method_709();
    virtual void method_710();
    virtual void method_711();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_74"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_75 : public class_74 {
public:
    bool field_1051{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5);
    virtual void method_710();
    virtual void method_705();
    virtual void method_704();
    virtual void method_712();
    virtual void method_713(jrt::Ref<java::lang::Object> var1, int32_t var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_75"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_76 : public class_74 {
public:
    int32_t field_1052{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1053{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1054{};
    jrt::Ref<java::lang::String> field_1055{};
    jrt::Ref<javax::microedition::lcdui::Image> field_1056{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2);
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var5, jrt::Ref<java::lang::String> var6);
    virtual void method_714();
    virtual void method_715(int32_t var1, jrt::Ref<class_68> var2);
    virtual void method_716(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_19>>> var2, jrt::Ref<jrt::Array<jrt::Ref<class_68>>> var3);
    virtual void method_704();
    virtual void method_705();
    virtual void method_703();
    virtual bool method_717();
    virtual void registerRows();
    virtual void method_718();
    virtual void method_719();
    virtual void method_720();
    virtual void method_721(jrt::Ref<java::lang::Object> var1, int32_t var2);
    virtual int32_t method_698();
    virtual int32_t method_699();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_76"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_77 : public class_76 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1057{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2);
    virtual void method_718();
    virtual void method_719();
    virtual void method_721(jrt::Ref<java::lang::Object> var1, int32_t var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_77"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_78 : public class_76 {
public:
    bool field_1058{};
    bool field_1059{};
    bool field_1060{};
    int32_t field_1061{};
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> field_1062{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1063{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1064{};
    jrt::Ref<class_52> field_1065{};
    jrt::Ref<class_121> field_1066{};
    jrt::Ref<javax::microedition::lcdui::game::Sprite> field_1067{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2);
    virtual void method_714();
    virtual void method_722(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_120>>> var2);
    virtual bool method_723();
    virtual void method_724();
    virtual void method_725();
    virtual void method_706();
    virtual void method_707();
    virtual void method_726();
    virtual void method_704();
    virtual void method_705();
    virtual void method_719();
    virtual void method_718();
    virtual void method_720();
    virtual void method_721(jrt::Ref<java::lang::Object> var1, int32_t var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_78"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_79 : public class_76 {
public:
    void __init();
    virtual jrt::Ref<javax::microedition::lcdui::Image> method_727(int32_t var1);
    virtual int32_t method_728();
    virtual void method_720();
    virtual void method_729();
    virtual void method_721(jrt::Ref<java::lang::Object> var1, int32_t var2);
    virtual void method_718();
    virtual int32_t method_698();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_79"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_7 : public java::lang::Object {
public:
    static jrt::Ref<class_3> field_56;
    static jrt::Ref<class_3> field_57;
    static jrt::Ref<class_3> field_58;
    static jrt::Ref<java::util::Random> field_59;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_60;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>> field_61;
    int32_t field_62{};
    jrt::Ref<jrt::Array<int16_t>> field_63{};
    jrt::Ref<jrt::Array<int16_t>> field_64{};
    jrt::Ref<jrt::Array<jrt::Ref<class_7>>> field_65{};
    bool field_66{};
    jrt::Ref<class_108> field_67{};
    static int32_t field_68;
    static int32_t field_69;
    static int32_t field_70;
    static jrt::Ref<class_57> field_71;
    static void method_36();
    virtual int32_t method_37();
    void __init(jrt::Ref<class_86> var1);
    void __init(int32_t var1);
    void method_38();
    int32_t method_39(int32_t var1);
    virtual jrt::Ref<jrt::Array<jrt::Ref<class_108>>> method_40(jrt::Ref<jrt::Array<jrt::Ref<class_108>>> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_7"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_80 : public class_79 {
public:
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4);
    virtual void method_729();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_80"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_81 : public class_76 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::lcdui::Image>>> field_1068{};
    jrt::Ref<javax::microedition::lcdui::Image> field_1069{};
    jrt::Ref<javax::microedition::lcdui::game::Sprite> field_1070{};
    jrt::Ref<java::lang::String> field_1071{};
    void __init(jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> var1, jrt::Ref<java::lang::String> var2);
    virtual void method_730(int32_t var1, jrt::Ref<jrt::Array<jrt::Ref<class_87>>> var2);
    virtual void method_718();
    virtual void method_719();
    virtual void method_721(jrt::Ref<java::lang::Object> var1, int32_t var2);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_81"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_82 : public java::lang::Object {
public:
    void __init();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_82"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_83 : public java::lang::Object {
public:
    int32_t field_1072{};
    jrt::Ref<jrt::Array<int32_t>> field_1073{};
    jrt::Ref<jrt::Array<int32_t>> field_1074{};
    jrt::Ref<jrt::Array<int32_t>> field_1075{};
    jrt::Ref<class_108> field_1076{};
    jrt::Ref<class_3> field_1077{};
    bool field_1078{};
    void __init();
    virtual void method_731();
    virtual void method_732(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6);
    virtual void method_733(jrt::Ref<class_3> var1);
    virtual void method_734(jrt::Ref<class_3> var1);
    virtual void method_735();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_83"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_84 : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1079;
    static bool field_1080;
    static bool field_1081;
    static bool field_1082;
    static int32_t field_1083;
    static int32_t field_1084;
    static bool field_1085;
    static bool field_1086;
    static bool field_1087;
    static bool field_1088;
    static bool field_1089;
    static bool field_1090;
    static bool field_1091;
    static bool field_1092;
    static bool field_1093;
    static bool field_1094;
    static bool field_1095;
    static bool field_1096;
    static bool field_1097;
    static bool field_1098;
    static bool field_1099;
    static bool field_1100;
    static bool field_1101;
    static bool field_1102;
    static bool field_1103;
    static bool field_1104;
    static bool field_1105;
    static bool field_1106;
    static bool field_1107;
    static jrt::Ref<jrt::Array<int32_t>> field_1108;
    static int32_t field_1109;
    static jrt::Ref<class_4> field_1110;
    static jrt::Ref<class_71> field_1111;
    static jrt::Ref<javax::microedition::lcdui::Display> field_1112;
    static jrt::Ref<class_33> field_1113;
    static bool field_1114;
    static int32_t field_1115;
    static jrt::Ref<class_1> field_1116;
    static jrt::Ref<javax::microedition::lcdui::Graphics> field_1117;
    static jrt::Ref<javax::microedition::lcdui::Canvas> field_1118;
    static jrt::Ref<javax::microedition::midlet::MIDlet> field_1119;
    static int32_t field_1120;
    static int32_t field_1121;
    static jrt::Ref<class_88> field_1122;
    static jrt::Ref<java::util::Random> field_1123;
    static jrt::Ref<java::lang::String> field_1124;
    static bool field_1125;
    static jrt::Ref<class_54> field_1126;
    static jrt::Ref<jrt::Array<jrt::Ref<class_61>>> field_1127;
    void __init();
    static void method_736(int32_t var0);
    static void method_737();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_84"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_85 : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<int32_t>> field_1128{};
    jrt::Ref<jrt::Array<int32_t>> field_1129{};
    int32_t field_1130{};
    jrt::Ref<jrt::Array<jrt::Ref<class_116>>> field_1131{};
    jrt::Ref<class_108> field_1132{};
    void __init(int32_t var1, int32_t var2);
    virtual void method_738();
    virtual void method_739(jrt::Ref<jrt::Array<int32_t>> var1);
    virtual int32_t method_740();
    virtual void method_741(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_742(int64_t var1);
    virtual bool method_743();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_85"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_86 : public java::lang::Object {
public:
    jrt::Ref<java::lang::String> field_1133{};
    int32_t field_1134{};
    int32_t field_1135{};
    int32_t field_1136{};
    int32_t field_1137{};
    bool field_1138{};
    int32_t field_1139{};
    int32_t field_1140{};
    jrt::Ref<jrt::Array<jrt::Ref<class_19>>> field_1141{};
    jrt::Ref<jrt::Array<jrt::Ref<class_120>>> field_1142{};
    jrt::Ref<jrt::Array<jrt::Ref<class_68>>> field_1143{};
    jrt::Ref<jrt::Array<jrt::Ref<class_87>>> field_1144{};
    void __init(jrt::Ref<java::lang::String> var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, int32_t var6);
    void __init();
    virtual float method_744();
    virtual bool method_745();
    virtual void method_746();
    virtual bool method_747(int32_t var1);
    virtual void method_748(jrt::Ref<class_19> var1);
    virtual void method_749(jrt::Ref<class_120> var1);
    virtual void method_750(jrt::Ref<class_19> var1);
    virtual void method_751(jrt::Ref<class_87> var1);
    virtual bool method_752();
    virtual jrt::Ref<java::lang::String> toString();
    virtual bool method_753(jrt::Ref<class_86> var1);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_86"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_87 : public java::lang::Object {
public:
    static jrt::Ref<class_87> field_1145;
    int32_t field_1146{};
    jrt::Ref<java::lang::String> field_1147{};
    jrt::Ref<jrt::Array<int8_t>> field_1148{};
    int32_t field_1149{};
    int32_t field_1150{};
    int32_t field_1151{};
    int32_t field_1152{};
    jrt::Ref<java::lang::String> field_1153{};
    int32_t field_1154{};
    int32_t field_1155{};
    int32_t field_1156{};
    bool field_1157{};
    int32_t field_1158{};
    int32_t field_1159{};
    int32_t field_1160{};
    bool field_1161{};
    bool field_1162{};
    bool field_1163{};
    int32_t field_1164{};
    int32_t field_1165{};
    int32_t field_1166{};
    int32_t field_1167{};
    int32_t field_1168{};
    int32_t field_1169{};
    int32_t field_1170{};
    bool field_1171{};
    void __init(int32_t var1, jrt::Ref<java::lang::String> var2, jrt::Ref<jrt::Array<int8_t>> var3, int32_t var4, int32_t var5, int32_t var6, int32_t var7, int32_t var8);
    void __init(int32_t var1, int32_t var2, int32_t var3);
    void __init();
    virtual bool method_754();
    virtual void method_755(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_756(int32_t var1, int32_t var2);
    virtual jrt::Ref<java::lang::String> method_757();
    virtual jrt::Ref<java::lang::String> method_758();
    virtual void method_759(int32_t var1);
    virtual void method_760();
    virtual void method_761(int32_t var1);
    virtual bool method_762();
    virtual void method_763();
    virtual int32_t method_764();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_87"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_88 : public java::lang::Object, public virtual javax::microedition::media::PlayerListener {
public:
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1172;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1173;
    static jrt::Ref<jrt::Array<int32_t>> field_1174;
    static int32_t field_1175;
    static int64_t field_1176;
    static jrt::Ref<jrt::Array<int64_t>> field_1177;
    static jrt::Ref<jrt::Array<int16_t>> field_1178;
    static jrt::Ref<javax::microedition::media::Player> field_1179;
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::media::Player>>> field_1180{};
    jrt::Ref<javax::microedition::media::control::VolumeControl> field_1181{};
    int32_t field_1182{};
    bool field_1183{};
    int32_t field_1184{};
    void __init();
    virtual void method_765(int32_t var1);
    virtual void method_766();
    virtual bool method_767();
    virtual void method_768(int32_t var1);
    virtual void method_769(int32_t var1, int32_t var2);
    virtual void method_770(int32_t var1);
    virtual void method_771();
    virtual void method_772();
    virtual void method_773();
    virtual void playerUpdate(jrt::Ref<javax::microedition::media::Player> var1, jrt::Ref<java::lang::String> var2, jrt::Ref<java::lang::Object> var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_88"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_89 : public java::lang::Object {
public:
    static int32_t field_1185;
    int64_t field_1186{};
    jrt::Ref<class_65> field_1187{};
    bool field_1188{};
    jrt::Ref<class_76> field_1189{};
    jrt::Ref<class_59> field_1190{};
    jrt::Ref<class_10> field_1191{};
    jrt::Ref<class_121> field_1192{};
    jrt::Ref<class_121> field_1193{};
    bool field_1194{};
    int32_t field_1195{};
    int32_t field_1196{};
    jrt::Ref<jrt::Array<int32_t>> field_1197{};
    int32_t field_1198{};
    void __init();
    virtual void method_774();
    virtual void method_775();
    virtual bool method_776();
    virtual bool method_777(int32_t var1);
    virtual bool method_778(int32_t var1, int32_t var2);
    void method_779();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_89"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_8 : public java::lang::Object {
public:
    float field_72{};
    float field_73{};
    float field_74{};
    void __init();
    virtual jrt::Ref<java::lang::String> toString();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_8"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_90 : public java::lang::Object {
public:
    static jrt::Ref<java::lang::String> field_1199;
    static jrt::Ref<java::lang::String> field_1200;
    static jrt::Ref<jrt::Array<int16_t>> field_1201;
    static jrt::Ref<jrt::Array<int16_t>> field_1202;
    static jrt::Ref<jrt::Array<int16_t>> field_1203;
    static jrt::Ref<jrt::Array<int16_t>> field_1204;
    static jrt::Ref<jrt::Array<int16_t>> field_1205;
    static jrt::Ref<jrt::Array<int8_t>> field_1206;
    static jrt::Ref<jrt::Array<int8_t>> field_1207;
    static jrt::Ref<jrt::Array<int8_t>> field_1208;
    static jrt::Ref<jrt::Array<int8_t>> field_1209;
    static jrt::Ref<jrt::Array<int8_t>> field_1210;
    static jrt::Ref<jrt::Array<int8_t>> field_1211;
    static jrt::Ref<jrt::Array<int8_t>> field_1212;
    static jrt::Ref<jrt::Array<int8_t>> field_1213;
    static jrt::Ref<jrt::Array<int8_t>> field_1214;
    static jrt::Ref<jrt::Array<int8_t>> field_1215;
    static jrt::Ref<jrt::Array<int8_t>> field_1216;
    static jrt::Ref<jrt::Array<int8_t>> field_1217;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int8_t>>>> field_1218;
    static jrt::Ref<jrt::Array<jrt::Ref<java::lang::String>>> field_1219;
    static jrt::Ref<jrt::Array<jrt::Ref<class_19>>> field_1220;
    static jrt::Ref<jrt::Array<jrt::Ref<class_68>>> field_1221;
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> field_1222;
    static jrt::Ref<jrt::Array<jrt::Ref<class_40>>> field_1223;
    void __init();
    static void method_780();
    static jrt::Ref<jrt::Array<jrt::Ref<class_19>>> method_781();
    static void method_782();
    static jrt::Ref<jrt::Array<jrt::Ref<class_68>>> method_783();
    static void method_784();
    static jrt::Ref<jrt::Array<jrt::Ref<class_120>>> method_785();
    static void method_786();
    static jrt::Ref<jrt::Array<jrt::Ref<class_40>>> method_787();
    static jrt::Ref<class_68> method_788(int32_t var0);
    static jrt::Ref<jrt::Array<int32_t>> method_789(int32_t var0, int32_t var1);
    static jrt::Ref<java::lang::String> method_790(int32_t var0, bool var1);
    static int32_t method_791();
    static void method_792();
    static void method_793();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_90"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_92 : public class_91 {
public:
    int32_t field_1241{};
    int32_t field_1242{};
    int32_t field_1243{};
    int32_t field_1244{};
    int32_t field_1245{};
    void __init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7);
    virtual void method_810();
    virtual void method_805(int64_t var1);
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_92"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_93 : public class_91 {
public:
    jrt::Ref<class_3> field_1246{};
    jrt::Ref<class_8> field_1247{};
    int64_t field_1248{};
    int64_t field_1249{};
    jrt::Ref<class_37> field_1250{};
    jrt::Ref<class_116> field_1251{};
    void __init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7);
    virtual void method_794();
    virtual void method_811();
    virtual void method_805(int64_t var1);
    virtual void method_809();
    void deep3dRender();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_93"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_94 : public class_91 {
public:
    int64_t field_1252{};
    void __init(int32_t var1, bool var2, jrt::Ref<class_37> var3, jrt::Ref<class_108> var4, int32_t var5, int32_t var6, int32_t var7);
    virtual void method_805(int64_t var1);
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_94"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_95 : public class_91 {
public:
    jrt::Ref<jrt::Array<jrt::Ref<class_29>>> field_1253{};
    int64_t field_1254{};
    bool field_1255{};
    jrt::Ref<class_3> field_1256{};
    jrt::Ref<class_3> field_1257{};
    jrt::Ref<class_3> field_1258{};
    jrt::Ref<class_3> field_1259{};
    jrt::Ref<class_3> field_1260{};
    jrt::Ref<class_37> field_1261{};
    jrt::Ref<class_108> field_1262{};
    bool field_1263{};
    int32_t field_1264{};
    void __init(int32_t var1, int32_t var2, bool var3, jrt::Ref<class_37> var4, jrt::Ref<class_108> var5, int32_t var6, int32_t var7, int32_t var8);
    virtual void method_794();
    virtual void method_812(int32_t var1, int32_t var2, int32_t var3);
    virtual jrt::Ref<class_3> method_799(jrt::Ref<class_3> var1);
    virtual void method_805(int64_t var1);
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    virtual jrt::Ref<class_3> method_808(jrt::Ref<class_3> var1);
    virtual bool method_807(jrt::Ref<class_3> var1);
    virtual bool method_813(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_95"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_96 : public class_91 {
public:
    int32_t field_1265{};
    float field_1266{};
    float field_1267{};
    int32_t field_1268{};
    jrt::Ref<class_25> field_1269{};
    jrt::Ref<class_3> field_1270{};
    jrt::Ref<class_3> field_1271{};
    jrt::Ref<class_3> field_1272{};
    jrt::Ref<class_3> field_1273{};
    static jrt::Ref<class_57> field_1274;
    int32_t field_1275{};
    bool field_1276{};
    int32_t field_1277{};
    int32_t field_1278{};
    int32_t field_1279{};
    int32_t field_1280{};
    jrt::Ref<class_37> field_1281{};
    bool field_1282{};
    int64_t field_1283{};
    bool field_1284{};
    bool field_1285{};
    bool field_1286{};
    jrt::Ref<class_83> field_1287{};
    bool field_1288{};
    float field_1289{};
    float field_1290{};
    jrt::Ref<jrt::Array<jrt::Ref<class_29>>> field_1291{};
    bool field_1292{};
    bool field_1293{};
    int32_t field_1294{};
    void __init(int32_t var1, int32_t var2, bool var3, jrt::Ref<class_37> var4, jrt::Ref<class_108> var5, int32_t var6, int32_t var7, int32_t var8);
    virtual void method_794();
    virtual void method_814(bool var1);
    virtual bool method_815();
    virtual bool method_816();
    virtual void method_817();
    virtual void method_818(int32_t var1, int32_t var2, int32_t var3);
    virtual void method_796(int32_t var1);
    virtual void method_805(int64_t var1);
    virtual void method_809();
    void deep3dRender();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_96"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_97 : public class_91 {
public:
    int32_t field_1295{};
    int32_t field_1296{};
    int32_t field_1297{};
    bool field_1298{};
    void __init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_18> var4);
    virtual jrt::Ref<class_3> method_799(jrt::Ref<class_3> var1);
    virtual void method_795(bool var1);
    virtual void method_819();
    virtual void method_820();
    virtual void method_805(int64_t var1);
    virtual void method_809();
    virtual bool method_806(int32_t var1, int32_t var2, int32_t var3);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_97"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class class_9 : public java::lang::Object {
public:
    static bool DEEP3D_LOG;
    static jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<jrt::Ref<jrt::Array<int16_t>>>>>> field_75;
    jrt::Ref<class_26> field_76{};
    jrt::Ref<jrt::Array<jrt::Ref<class_37>>> field_77{};
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> field_78{};
    jrt::Ref<jrt::Array<jrt::Ref<class_3>>> field_79{};
    jrt::Ref<class_3> field_80{};
    jrt::Ref<class_3> field_81{};
    jrt::Ref<class_37> field_82{};
    jrt::Ref<jrt::Array<int32_t>> field_83{};
    int32_t field_84{};
    float field_85{};
    int32_t field_86{};
    jrt::Ref<class_3> field_87{};
    bool field_88{};
    jrt::Ref<class_3> field_89{};
    int32_t field_90{};
    int32_t field_91{};
    bool field_92{};
    bool field_93{};
    jrt::Ref<class_116> field_94{};
    bool field_95{};
    jrt::Ref<class_91> field_96{};
    bool field_97{};
    jrt::Ref<class_114> field_98{};
    int32_t field_99{};
    int32_t field_100{};
    bool field_101{};
    void __init(int32_t var1, int32_t var2, int32_t var3, int32_t var4, int32_t var5, float var6, jrt::Ref<class_3> var7, jrt::Ref<class_3> var8);
    virtual void method_41(int32_t var1, jrt::Ref<class_114> var2);
    virtual void method_42(int32_t var1, int32_t var2);
    virtual void method_43();
    virtual void method_44(jrt::Ref<class_116> var1);
    virtual bool method_45(jrt::Ref<class_57> var1, int64_t var2, jrt::Ref<class_37> var4, bool var5);
    virtual bool method_46(jrt::Ref<class_57> var1, int64_t var2, bool var4);
    void method_47();
    void method_48(int64_t var1);
    virtual void method_49(int64_t var1);
    virtual void method_50();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "class_9"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class Deep3dMenu : public java::lang::Object, public virtual org::deep3d::MenuToolkit {
public:
    jrt::Ref<javax::microedition::lcdui::Graphics> saved{};
    void __init();
    virtual void begin(jrt::Ref<javax::microedition::lcdui::Graphics> g);
    virtual void end();
    virtual jrt::Ref<java::lang::String> text(int32_t id);
    virtual int32_t textWidth(jrt::Ref<java::lang::String> s);
    virtual int32_t lineHeight();
    virtual jrt::Ref<java::lang::String> fit(jrt::Ref<java::lang::String> s, int32_t w);
    virtual void dim();
    virtual void panel(jrt::Ref<java::lang::String> title, int32_t x, int32_t y, int32_t w, int32_t h);
    virtual void row(jrt::Ref<java::lang::String> s, int32_t x, int32_t y, int32_t w, bool selected);
    virtual jrt::Ref<jrt::Array<int32_t>> bar(jrt::Ref<java::lang::String> lk, jrt::Ref<java::lang::String> ll, jrt::Ref<java::lang::String> rk, jrt::Ref<java::lang::String> rl);
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "Deep3dMenu"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

class DeepMIDlet : public javax::microedition::midlet::MIDlet, public virtual java::lang::Runnable {
public:
    int32_t field_1525{};
    jrt::Ref<class_124> field_1526{};
    jrt::Ref<javax::microedition::lcdui::Display> field_1527{};
    bool field_1528{};
    bool field_1529{};
    jrt::Ref<java::lang::Thread> field_1530{};
    void __init();
    virtual jrt::Ref<javax::microedition::lcdui::Display> getDisplay();
    virtual void startApp();
    virtual void pauseApp();
    virtual void resume();
    virtual void pause();
    virtual void destroyApp(bool var1);
    virtual void run();
    virtual void quit();
    bool __dumpable() override { return true; }
    const char* __javaName() override { return "DeepMIDlet"; }
    void __dumpFields(jrt::Dumper& d) override;
    static void __clinit();
};

void game_clinit();
bool game_setStatic(const std::string& cls, const std::string& field, int32_t value);
void game_dumpStatics(jrt::Dumper& d);
