// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void Deep3dMenu::__clinit() {
}

void Deep3dMenu::__init() {
}

void Deep3dMenu::begin(jrt::Ref<javax::microedition::lcdui::Graphics> g) {
    this->saved = class_84::field_1117;
    class_84::field_1117 = g;
    g->setClip(0, 0, class_84::field_1120, class_84::field_1121);
    org::deep3d::GameUi::suspend(true);
}

void Deep3dMenu::end() {
    org::deep3d::GameUi::suspend(false);
    class_84::field_1117 = this->saved;
    this->saved = jrt::Ref<javax::microedition::lcdui::Graphics>(nullptr);
}

jrt::Ref<java::lang::String> Deep3dMenu::text(int32_t id) {
    return class_84::field_1116->method_4(id);
}

int32_t Deep3dMenu::textWidth(jrt::Ref<java::lang::String> s) {
    return class_58::method_523(s);
}

int32_t Deep3dMenu::lineHeight() {
    return class_58::method_527();
}

jrt::Ref<java::lang::String> Deep3dMenu::fit(jrt::Ref<java::lang::String> s, int32_t w) {
    return class_67::method_600(s, w);
}

void Deep3dMenu::dim() {
    if (class_67::field_857 != nullptr) {
        class_67::method_583();
    }
}

void Deep3dMenu::panel(jrt::Ref<java::lang::String> title, int32_t x, int32_t y, int32_t w, int32_t h) {
    class_67::method_591(title, x, y, w, h);
}

void Deep3dMenu::row(jrt::Ref<java::lang::String> s, int32_t x, int32_t y, int32_t w, bool selected) {
    class_67::method_584(s, x, y, w, selected);
}

jrt::Ref<jrt::Array<int32_t>> Deep3dMenu::bar(jrt::Ref<java::lang::String> lk, jrt::Ref<java::lang::String> ll, jrt::Ref<java::lang::String> rk, jrt::Ref<java::lang::String> rl) {
    return class_67::deep3dBar(lk, ll, rk, rl);
}

void Deep3dMenu::__dumpFields(jrt::Dumper& d) {
    d.f("saved", this->saved);
}

