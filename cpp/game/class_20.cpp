// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_20::__clinit() {
}

void class_20::__init(int32_t var1, int32_t var2, int32_t var3, int32_t var4) {
    this->field_178 = var1;
    this->field_179 = var2;
    this->field_180 = var3;
    this->field_181 = var4;
    this->field_182 = jrt::arrayOf<int32_t>({var4});
    this->field_184 = false;
    this->field_185 = false;
}

void class_20::__init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<jrt::Array<int32_t>> var4) {
    this->field_178 = var1;
    this->field_179 = var2;
    this->field_180 = var3;
    this->field_181 = var4->at(0);
    this->field_182 = var4;
    this->field_184 = false;
}

void class_20::method_125() {
    this->field_185 = true;
}

bool class_20::method_126(int64_t var1, jrt::Ref<class_70> var3) {
    if (this->field_184) {
        return false;
    } else {
        bool var4{};
        var4 = false;
        {
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var5{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var18{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var19{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var17{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var21{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var12{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var15{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var9{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var14{};
            jrt::Ref<jrt::Array<jrt::Ref<class_37>>> var6{};
            switch (this->field_180) {
            case 0:
                if (var3->field_982 != nullptr) {
                    var4 = (var3->field_982->field_164 > this->field_186) && (this->field_186 == this->field_181);
                    this->field_186 = var3->field_982->field_164;
                }
                break;
            case 1:
                var5 = var3->field_969->field_360;
                for (int32_t var13 = 0; var13 < this->field_182->length; var13++) {
                    if (var5->at(this->field_182->at(var13))->method_345()) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 2:
                var18 = var3->field_969->field_361;
                for (int32_t var20 = 0; var20 < this->field_182->length; var20++) {
                    if (var18->at(this->field_182->at(var20))->method_345()) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 3:
                var4 = var3->field_981->field_281 <= 0;
                break;
            case 4:
                var4 = var3->field_981->field_282 <= 0;
                break;
            case 5:
                var4 = var1 >= int64_t(this->field_181);
                break;
            case 6:
                var4 = this->field_177->method_299(this->field_181)->field_184;
            case 7:
                ;
            default:
                break;
            case 8:
                var19 = var3->field_969->field_360;
                for (int32_t var22 = 0; var22 < this->field_182->length; var22++) {
                    if ((!var19->at(var22)->method_321()) && var19->at(this->field_182->at(var22))->field_375) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 9:
                var4 = true;
                var17 = var3->field_969->field_360;
                for (int32_t var8 = 0; var8 < this->field_182->length; var8++) {
                    if (!var17->at(this->field_182->at(var8))->method_345()) {
                        var4 = false;
                        goto label201_break;
                    }
                }
                break;
            case 10:
                var21 = var3->field_969->field_361;
                for (int32_t var24 = 0; var24 < this->field_182->length; var24++) {
                    if (var21->at(this->field_182->at(var24))->field_375) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 11:
                var4 = this->field_183->method_222(int32_t(var1));
                break;
            case 12:
                var12 = var3->field_969->field_360;
                for (int32_t var16 = 0; var16 < this->field_182->length; var16++) {
                    if (var12->at(this->field_182->at(var16))->field_363 < (var12->at(this->field_182->at(var16))->field_364 / 2)) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 13:
                var4 = class_21::method_170() > 0;
                break;
            case 14:
                var4 = (jrt::cast<class_96>(var3->field_969->field_360->at(this->field_181)->field_379))->method_815();
                break;
            case 15:
                var4 = false;
                var15 = var3->field_969->field_360;
                for (int32_t var23 = 0; var23 < var15->length; var23++) {
                    if (var15->at(var23)->method_345() && (!var15->at(var23)->method_321())) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 16:
                var9 = var3->field_969->field_360;
                for (int32_t var10 = 0; var10 < var9->length; var10++) {
                    if ((!var9->at(var10)->method_321()) && var9->at(var10)->field_375) {
                        var4 = true;
                        goto label201_break;
                    }
                }
                break;
            case 17:
                var14 = var3->field_969->field_360;
                var4 = true;
                for (int32_t var11 = 0; var11 < var14->length; var11++) {
                    if (((var11 != this->field_181) && (!var14->at(var11)->method_321())) && (!var14->at(var11)->method_345())) {
                        var4 = false;
                        goto label201_break;
                    }
                }
                break;
            case 18:
                var4 = (jrt::cast<class_96>(var3->field_969->field_360->at(this->field_181)->field_379))->method_816() || (jrt::cast<class_96>(var3->field_969->field_360->at(this->field_181)->field_379))->field_1286;
                break;
            case 19:
                var6 = var3->field_969->field_360;
                for (int32_t var7 = 0; var7 < this->field_182->length; var7++) {
                    if (var6->at(this->field_182->at(var7))->field_363 < ((var6->at(this->field_182->at(var7))->field_364 / 4) * 3)) {
                        var4 = true;
                        break;
                    }
                }
            }
        }
        label201_break:;
        this->field_184 = var4;
        if (this->field_184) {
            this->field_177->field_343 = jrt::Ref<class_20>(this);
        }
        return var4;
    }
}

void class_20::__dumpFields(jrt::Dumper& d) {
    d.f("field_177", this->field_177);
    d.f("field_178", this->field_178);
    d.f("field_179", this->field_179);
    d.f("field_180", this->field_180);
    d.f("field_181", this->field_181);
    d.f("field_182", this->field_182);
    d.f("field_183", this->field_183);
    d.f("field_184", this->field_184);
    d.f("field_185", this->field_185);
    d.f("field_186", this->field_186);
}

