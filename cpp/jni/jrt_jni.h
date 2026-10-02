// Calls from translated code (native methods) into JNI implementations.
#pragma once
#include "jni.h"
#include "jrt/jrt.h"

namespace java::nio {
class ByteBuffer;
}

namespace jrt::jni {

JNIEnv* env();
/** Throws the Java exception the last JNI call raised, if any. */
void check();

inline jobject obj(java::lang::Object* o) { return reinterpret_cast<jobject>(o); }
template <class T>
inline jobject obj(T* o) {
    return reinterpret_cast<jobject>(toObject(o));
}

inline jint arg(int32_t v) { return v; }
inline jlong arg(int64_t v) { return jlong(v); }
inline jfloat arg(float v) { return v; }
inline jdouble arg(double v) { return v; }
inline jboolean arg(bool v) { return v ? JNI_TRUE : JNI_FALSE; }
inline jshort arg(int16_t v) { return v; }
inline jbyte arg(int8_t v) { return v; }
inline jchar arg(char16_t v) { return jchar(v); }
template <class T>
inline jobject arg(const Ref<T>& r) {
    return r.get() ? reinterpret_cast<jobject>(toObject(r.get())) : nullptr;
}

template <class R, class V>
inline R ret(V v) {
    if constexpr (std::is_same_v<R, bool>) {
        return v != 0;
    } else {
        return R(v);
    }
}

}  // namespace jrt::jni
