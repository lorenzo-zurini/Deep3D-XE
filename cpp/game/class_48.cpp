// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"

jrt::Ref<java::lang::String> class_48::field_536{};
jrt::Ref<java::lang::String> class_48::field_537{};
jrt::Ref<java::lang::String> class_48::field_538{};

void class_48::__clinit() {
}

void class_48::__init() {
}

jrt::Ref<java::lang::String> class_48::method_397(int64_t var0) {
    int32_t var2 = int32_t(((var0 / int64_t(1000)) % int64_t(60)));
    int32_t var3 = int32_t(((var0 / int64_t(60000)) % int64_t(60)));
    int32_t var4 = int32_t(((var0 / int64_t(3600000)) % int64_t(24)));
    class_48::field_536 = jrt::concat(((var2 < 10) ? JRT_LIT(u"0") : JRT_LIT(u"")), var2);
    class_48::field_537 = jrt::concat(((var3 < 10) ? JRT_LIT(u"0") : JRT_LIT(u"")), var3);
    if (var4 == 0) {
        return jrt::New<java::lang::String>(jrt::concat(class_48::field_537, JRT_LIT(u":"), class_48::field_536));
    } else {
        int32_t var5 = int32_t(((var0 / int64_t(3600000)) / int64_t(24)));
        var4 += (var5 * 24);
        class_48::field_538 = jrt::concat(((var4 < 10) ? JRT_LIT(u"0") : JRT_LIT(u"")), var4);
        return jrt::New<java::lang::String>(jrt::concat(class_48::field_538, JRT_LIT(u":"), class_48::field_537, JRT_LIT(u":"), class_48::field_536));
    }
}

jrt::Ref<java::lang::String> class_48::method_398(int64_t var0) {
    int32_t var2 = int32_t(((var0 / int64_t(60000)) % int64_t(60)));
    int32_t var3 = int32_t(((var0 / int64_t(3600000)) % int64_t(24)));
    class_48::field_537 = jrt::concat(((var2 < 10) ? JRT_LIT(u"0") : JRT_LIT(u"")), var2);
    int32_t var4 = int32_t(((var0 / int64_t(3600000)) / int64_t(24)));
    var3 += (var4 * 24);
    class_48::field_538 = jrt::concat(((var3 < 10) ? JRT_LIT(u"0") : JRT_LIT(u"")), var3);
    return jrt::New<java::lang::String>(jrt::concat(class_48::field_538, JRT_LIT(u":"), class_48::field_537));
}

void class_48::__dumpFields(jrt::Dumper& d) {
}

