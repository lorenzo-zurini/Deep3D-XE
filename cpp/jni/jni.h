// A JNI stand-in for the M3G engine's Java glue (native/m3g/jni/*.inl),
// which the C++ build calls directly: "Java objects" are jrt objects, the
// environment serves their arrays in place, and an exception raised by the
// glue is thrown as a Java exception once the call returns
// (jrt::jni::check()). Only what the glue uses is provided.
#pragma once

#include <cstdint>
#include <cstddef>

typedef int32_t jint;
typedef long jlong;     // int64_t on LP64, as the JDK's jni_md.h
typedef int8_t jbyte;
typedef uint8_t jboolean;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;

struct _jobject {};
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
typedef jobject jthrowable;
typedef jobject jarray;
typedef jarray jbooleanArray;
typedef jarray jbyteArray;
typedef jarray jcharArray;
typedef jarray jshortArray;
typedef jarray jintArray;
typedef jarray jlongArray;
typedef jarray jfloatArray;
typedef jarray jdoubleArray;
typedef jarray jobjectArray;

#define JNI_FALSE 0
#define JNI_TRUE 1
#define JNI_OK 0
#define JNI_ERR (-1)
#define JNI_COMMIT 1
#define JNI_ABORT 2

#define JNIEXPORT __attribute__((visibility("default")))
#define JNICALL
#define JNIIMPORT

/** The environment: implemented in cpp/jni/jni.cpp over jrt objects. */
struct JNIEnv_ {
    jsize GetArrayLength(jarray a);
    jbyte* GetByteArrayElements(jbyteArray a, jboolean* isCopy);
    jshort* GetShortArrayElements(jshortArray a, jboolean* isCopy);
    jint* GetIntArrayElements(jintArray a, jboolean* isCopy);
    jlong* GetLongArrayElements(jlongArray a, jboolean* isCopy);
    jfloat* GetFloatArrayElements(jfloatArray a, jboolean* isCopy);
    void ReleaseByteArrayElements(jbyteArray, jbyte*, jint) {}
    void ReleaseShortArrayElements(jshortArray, jshort*, jint) {}
    void ReleaseIntArrayElements(jintArray, jint*, jint) {}
    void ReleaseLongArrayElements(jlongArray, jlong*, jint) {}
    void ReleaseFloatArrayElements(jfloatArray, jfloat*, jint) {}
    void GetByteArrayRegion(jbyteArray a, jsize start, jsize len, jbyte* buf);
    void GetFloatArrayRegion(jfloatArray a, jsize start, jsize len, jfloat* buf);
    void SetIntArrayRegion(jintArray a, jsize start, jsize len, const jint* buf);
    jclass FindClass(const char* name);
    jint ThrowNew(jclass cls, const char* msg);
    void* GetDirectBufferAddress(jobject buf);
    jboolean ExceptionCheck();
};
typedef JNIEnv_ JNIEnv;
typedef struct JavaVM_ JavaVM;
