// Translated from the decompiled Java of the game (2026-10); now the source.
#include "game.h"


void class_22::__clinit() {
}

void class_22::__init(int32_t var1, int32_t var2, jrt::Ref<class_26> var3) {
    this->field_222 = var1;
    this->field_223 = var2;
    this->field_225 = var3;
}

void class_22::__init(int32_t var1, int32_t var2, int32_t var3, jrt::Ref<class_26> var4) {
    this->__init(var1, var2, var4);
    this->field_224 = var3;
    if (var1 == 13) {
        this->field_227 = var3;
    }
}

bool class_22::method_222(int32_t var1) {
    bool var2 = true;
    if (this->field_226 != nullptr) {
        for (int32_t var3 = 0; var3 < this->field_226->length; var3++) {
            var2 = var2 && this->field_226->at(var3)->method_222(var1);
        }
        if (var2) {
            return true;
        }
    }
    {
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var14{};
        int32_t var4{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var5{};
        int32_t var17{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var7{};
        int32_t var16{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var8{};
        bool var6{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var9{};
        int32_t var10{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var11{};
        jrt::Ref<jrt::Array<jrt::Ref<class_91>>> var12{};
        switch (this->field_222) {
        case 0:
            if (var2 && (this->field_225->field_281 == 0)) {
                return true;
            }
            return false;
        case 1:
            if (var2 && this->field_225->field_273->at(this->field_223)->method_800()) {
                return true;
            }
            return false;
        case 2:
            if (var2 && this->field_225->field_277->method_111()->field_1298) {
                return true;
            }
            return false;
        case 3:
            if (var2 && (var1 > this->field_223)) {
                return true;
            }
            return false;
        case 4:
            if (var2 && this->field_225->field_280->at(this->field_223)->field_184) {
                return true;
            }
            return false;
        case 5:
            if (var2 && (this->field_225->field_282 == 0)) {
                return true;
            }
            return false;
        case 6:
            if (var2 && this->field_225->field_274->at(this->field_223)->method_800()) {
                return true;
            }
            return false;
        case 7:
            var14 = this->field_225->field_273;
            var4 = 0;
            for (int32_t var15 = 0; var15 < this->field_223; var15++) {
                if (var14->at(var15)->method_800()) {
                    var4++;
                }
            }
            if (var4 == this->field_223) {
                return true;
            }
            return false;
        case 8:
            var5 = this->field_225->field_275;
            var17 = 0;
            for (int32_t var18 = 0; var18 < var5->length; var18++) {
                if (var5->at(var18)->method_800()) {
                    var17++;
                }
            }
            if (var17 > this->field_223) {
                return true;
            }
            return false;
        case 9:
            var7 = this->field_225->field_275;
            var16 = 0;
            for (int32_t var19 = 0; var19 < var7->length; var19++) {
                if ((jrt::cast<class_101>(var7->at(var19)))->field_1326) {
                    var16++;
                }
                if (var19 >= this->field_223) {
                    if (var16 >= this->field_223) {
                        return true;
                    }
                    return false;
                }
            }
            break;
        case 10:
            var8 = this->field_225->field_275;
            var6 = false;
            for (int32_t var20 = 0; var20 < var8->length; var20++) {
                if (var8->at(var20)->method_800() && (!(jrt::cast<class_101>(var8->at(var20)))->field_1326)) {
                    return true;
                }
                if (var20 >= this->field_223) {
                    return false;
                }
            }
            break;
        case 11:
            return (jrt::cast<class_96>(this->field_225->field_273->at(this->field_223)))->method_815();
        case 12:
            return (jrt::cast<class_96>(this->field_225->field_273->at(this->field_223)))->field_1285;
        case 13:
            var9 = this->field_225->field_275;
            var10 = 0;
            for (int32_t var21 = 0; var21 < var9->length; var21++) {
                jrt::Ref<class_101> var23{};
                if (((var23 = jrt::cast<class_101>(var9->at(var21)))->field_1312->field_391 == this->field_223) && (var9->at(var21)->method_800() || (jrt::cast<class_101>(var9->at(var21)))->field_1326)) {
                    var10++;
                }
            }
            this->field_227 = this->field_224 - var10;
            if (var10 >= this->field_224) {
                return true;
            }
            return false;
        case 14:
            if (this->field_225->field_287 >= this->field_223) {
                return true;
            }
            return false;
        case 15:
            return this->field_225->field_273->at(this->field_223)->field_1225->field_375;
        case 16:
            var11 = this->field_225->field_273;
            for (int32_t var22 = 0; var22 < var11->length; var22++) {
                if (!(jrt::cast<class_96>(var11->at(var22)))->method_815()) {
                    return false;
                }
            }
            return true;
        case 17:
            var12 = this->field_225->field_273;
            for (int32_t var13 = 0; var13 < var12->length; var13++) {
                if ((jrt::cast<class_96>(var12->at(var13)))->field_1285) {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

bool class_22::method_223() {
    return this->field_222 == 3;
}

void class_22::__dumpFields(jrt::Dumper& d) {
    d.f("field_222", this->field_222);
    d.f("field_223", this->field_223);
    d.f("field_224", this->field_224);
    d.f("field_225", this->field_225);
    d.f("field_226", this->field_226);
    d.f("field_227", this->field_227);
}

