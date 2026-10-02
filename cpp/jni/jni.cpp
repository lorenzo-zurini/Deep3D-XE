// The JNI stand-in: jrt arrays served in place, exceptions deferred.
#include "jrt_jni.h"
#include "jrt/jrt_io.h"
#include "jrt/jrt_nio.h"

#include <cstring>
#include <string>

namespace {

thread_local std::string tPending;   // class of the exception raised, if any
JNIEnv_ gEnv;

java::lang::Object* objectOf(jobject o) { return reinterpret_cast<java::lang::Object*>(o); }

template <class T>
jrt::Array<T>* arrayOf(jarray a) {
    return a ? dynamic_cast<jrt::Array<T>*>(objectOf(a)) : nullptr;
}

template <class E>
[[noreturn]] void raise(const char* msg) {
    jrt::Ref<E> e(new E());
    if (msg && *msg) e->message = java::lang::String::fromUtf8(msg);
    jrt::throwJava(e);
}

}  // namespace

jsize JNIEnv_::GetArrayLength(jarray a) {
    auto* arr = a ? dynamic_cast<jrt::ArrayBase*>(objectOf(a)) : nullptr;
    return arr ? arr->length : 0;
}

jbyte* JNIEnv_::GetByteArrayElements(jbyteArray a, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    auto* arr = arrayOf<int8_t>(a);
    return arr ? arr->data : nullptr;
}
jshort* JNIEnv_::GetShortArrayElements(jshortArray a, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    auto* arr = arrayOf<int16_t>(a);
    return arr ? arr->data : nullptr;
}
jint* JNIEnv_::GetIntArrayElements(jintArray a, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    auto* arr = arrayOf<int32_t>(a);
    return arr ? arr->data : nullptr;
}
jlong* JNIEnv_::GetLongArrayElements(jlongArray a, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    auto* arr = arrayOf<int64_t>(a);
    return arr ? reinterpret_cast<jlong*>(arr->data) : nullptr;
}
jfloat* JNIEnv_::GetFloatArrayElements(jfloatArray a, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    auto* arr = arrayOf<float>(a);
    return arr ? arr->data : nullptr;
}

void JNIEnv_::GetByteArrayRegion(jbyteArray a, jsize start, jsize len, jbyte* buf) {
    auto* arr = arrayOf<int8_t>(a);
    if (!arr || start < 0 || len < 0 || start + len > arr->length) {
        tPending = "java/lang/ArrayIndexOutOfBoundsException";
        return;
    }
    memcpy(buf, arr->data + start, size_t(len));
}

void JNIEnv_::GetFloatArrayRegion(jfloatArray a, jsize start, jsize len, jfloat* buf) {
    auto* arr = arrayOf<float>(a);
    if (!arr || start < 0 || len < 0 || start + len > arr->length) {
        tPending = "java/lang/ArrayIndexOutOfBoundsException";
        return;
    }
    memcpy(buf, arr->data + start, size_t(len) * sizeof(float));
}

void JNIEnv_::SetIntArrayRegion(jintArray a, jsize start, jsize len, const jint* buf) {
    auto* arr = arrayOf<int32_t>(a);
    if (!arr || start < 0 || len < 0 || start + len > arr->length) {
        tPending = "java/lang/ArrayIndexOutOfBoundsException";
        return;
    }
    memcpy(arr->data + start, buf, size_t(len) * sizeof(jint));
}

jclass JNIEnv_::FindClass(const char* name) {
    // the "class" is its name (only ThrowNew uses it)
    return reinterpret_cast<jclass>(const_cast<char*>(name));
}

jint JNIEnv_::ThrowNew(jclass cls, const char*) {
    if (tPending.empty()) tPending = reinterpret_cast<const char*>(cls);
    return 0;
}

void* JNIEnv_::GetDirectBufferAddress(jobject buf) {
    auto* b = buf ? dynamic_cast<java::nio::ByteBuffer*>(objectOf(buf)) : nullptr;
    return b ? b->address() : nullptr;
}

jboolean JNIEnv_::ExceptionCheck() { return tPending.empty() ? JNI_FALSE : JNI_TRUE; }

namespace jrt::jni {

JNIEnv* env() { return &gEnv; }

void check() {
    if (tPending.empty()) return;
    std::string name;
    name.swap(tPending);
    if (name == "java/lang/NullPointerException") raise<java::lang::NullPointerException>(nullptr);
    if (name == "java/lang/IllegalArgumentException") raise<java::lang::IllegalArgumentException>(nullptr);
    if (name == "java/lang/IllegalStateException") raise<java::lang::IllegalStateException>(nullptr);
    if (name == "java/lang/ArithmeticException") raise<java::lang::ArithmeticException>(nullptr);
    if (name == "java/lang/IndexOutOfBoundsException") raise<java::lang::IndexOutOfBoundsException>(nullptr);
    if (name == "java/lang/ArrayIndexOutOfBoundsException") raise<java::lang::ArrayIndexOutOfBoundsException>(nullptr);
    if (name == "java/lang/OutOfMemoryError") raise<java::lang::OutOfMemoryError>(nullptr);
    if (name == "java/lang/SecurityException") raise<java::lang::SecurityException>(nullptr);
    if (name == "java/io/IOException") raise<java::io::IOException>(nullptr);
    raise<java::lang::RuntimeException>(name.c_str());
}

}  // namespace jrt::jni
