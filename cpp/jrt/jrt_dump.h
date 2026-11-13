// The game's state as text, for deterministic runs: the same format as the
// Java build's reflection dump (runtime/src/org/deep3d/Det.java), so the
// two builds can be compared frame by frame.
#pragma once

#include <cstring>
#include "jrt.h"

#include <string>
#include <unordered_map>

namespace jrt {

class Dumper {
public:
    std::string out;
    std::unordered_map<const void*, int> ids;
    /** Set: the field list goes to the cycle collector instead (no text). */
    Tracer* gc = nullptr;
    /** The original game's state only, without what the PC added (fields
        deep3d*, classes Deep3d*): to compare with the phone build. */
    bool original = false;
    static bool added(const char* name) {
        const char* dot = strrchr(name, '.');
        const char* field = dot ? dot + 1 : name;
        return strncmp(field, "deep3d", 6) == 0 || strncmp(name, "Deep3d", 6) == 0;
    }

    void v(bool x) { out += x ? "true" : "false"; }
    void v(int8_t x) { out += std::to_string(int(x)); }
    void v(int16_t x) { out += std::to_string(int(x)); }
    void v(int32_t x) { out += std::to_string(x); }
    void v(int64_t x) { out += std::to_string(x); }
    void v(char16_t x) {
        out += 'c';
        out += std::to_string(int(x));
    }
    void v(float x);
    void v(double x);
    template <class T>
    void v(const Ref<T>& r) {
        obj(r.get() ? toObject(r.get()) : nullptr);
    }
    void obj(java::lang::Object* o);

    template <class T>
    void f(const char* name, const T& value) {
        if (gc) {
            // the fields are the object's own (non-const) members
            if constexpr (isRef<T>::value) (*gc)(const_cast<T&>(value));
            return;
        }
        if (original && added(name)) return;
        out += name;
        out += '=';
        v(value);
        out += ';';
    }
    template <class T>
    void staticField(const char* name, const T& value) {
        if (original && added(name)) return;
        out += name;
        out += '=';
        v(value);
        out += '\n';
    }
};

template <class T>
inline void Array<T>::__dumpElems(Dumper& d) {
    for (int32_t i = 0; i < length; i++) {
        if (i > 0) d.out += ',';
        d.v(data[i]);
    }
}

}  // namespace jrt
