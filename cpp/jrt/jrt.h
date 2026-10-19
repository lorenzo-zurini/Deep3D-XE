// jrt: the Java semantics the translated code (tools/j2cpp) relies on.
//
// Object model: classes form a single (non-virtual) inheritance chain from
// java::lang::Object, so a class pointer is the object's address and every
// array of class references has one layout, which gives Java's array
// covariance (a Foo[] used as an Object[]) by aliasing. Java interfaces are
// separate abstract C++ bases, reached from objects by dynamic cross-casts.
//
// Objects are reference counted through jrt::Ref<T>. An object whose count
// drops to zero is not freed at once but at the next safe point (the game
// loop's), as Java code may drop the last reference to an object while one
// of its methods still runs. Reference cycles are freed by a cycle collector
// (jrt_gc.cpp), also at the safe point, while every other thread running
// Java code waits (MutatorScope / SafeRegion).
//
// Java's runtime errors are C++ exceptions of type jrt::Thrown carrying the
// Java exception object: null dereferences, array bounds, integer division
// by zero and bad casts throw what Java throws.
#pragma once

#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <limits>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <utility>

namespace jrt {
class Dumper;
}

namespace java::lang {
class Object;
class String;
class Throwable;
class Class;
}

namespace jrt {

class Monitor;

[[noreturn]] void throwNPE();
[[noreturn]] void throwAIOOBE(int32_t index, int32_t length);
[[noreturn]] void throwArithmetic(const char* msg);
[[noreturn]] void throwClassCast(const char* from, const char* to);
[[noreturn]] void throwNegativeArraySize(int32_t n);
[[noreturn]] void throwArrayStore();

void destroyLater(java::lang::Object* o);
/** Takes a destroyed object off the cycle collector's list. */
void forgetObject(java::lang::Object* o);

template <class T>
inline void retain(T* p) noexcept;
template <class T>
inline void release(T* p) noexcept;

/**
 * Converts between reference types: implicit upcasts, and the cross-casts
 * between interfaces and classes (interfaces are separate C++ bases).
 */
template <class T, class U>
inline T* refConvert(U* p) {
    if constexpr (std::is_convertible_v<U*, T*>) {
        return p;
    } else {
        return p ? dynamic_cast<T*>(p) : nullptr;
    }
}

/** A counted reference: Java's object reference. */
template <class T>
class Ref {
    T* p_ = nullptr;

    template <class U>
    friend class Ref;

public:
    using element_type = T;

    Ref() noexcept = default;
    Ref(std::nullptr_t) noexcept {}
    Ref(T* p) noexcept : p_(p) {
        if (p_) retain(p_);
    }
    Ref(const Ref& o) noexcept : p_(o.p_) {
        if (p_) retain(p_);
    }
    Ref(Ref&& o) noexcept : p_(o.p_) { o.p_ = nullptr; }
    /** Upcasts, and interface <-> class conversions (checked by the translator). */
    template <class U, class = std::enable_if_t<!std::is_same_v<U, T>>>
    Ref(const Ref<U>& o) noexcept : p_(refConvert<T>(o.p_)) {
        if (p_) retain(p_);
    }
    ~Ref() {
        if (p_) release(p_);
    }

    Ref& operator=(const Ref& o) noexcept {
        T* old = p_;
        p_ = o.p_;
        if (p_) retain(p_);
        if (old) release(old);
        return *this;
    }
    Ref& operator=(Ref&& o) noexcept {
        if (this != &o) {
            T* old = p_;
            p_ = o.p_;
            o.p_ = nullptr;
            if (old) release(old);
        }
        return *this;
    }
    Ref& operator=(std::nullptr_t) noexcept {
        T* old = p_;
        p_ = nullptr;
        if (old) release(old);
        return *this;
    }
    template <class U, class = std::enable_if_t<!std::is_same_v<U, T>>>
    Ref& operator=(const Ref<U>& o) noexcept {
        return *this = Ref(o);
    }

    T* operator->() const {
        if (!p_) throwNPE();
        return p_;
    }
    T& operator*() const {
        if (!p_) throwNPE();
        return *p_;
    }
    T* get() const noexcept { return p_; }
    explicit operator bool() const noexcept { return p_ != nullptr; }
};

/** Identity of two references (through the most-derived object). */
template <class A, class B>
inline bool operator==(const Ref<A>& a, const Ref<B>& b) noexcept {
    if (!a.get() || !b.get()) return !a.get() && !b.get();
    return dynamic_cast<const void*>(a.get()) == dynamic_cast<const void*>(b.get());
}
template <class A, class B>
inline bool operator!=(const Ref<A>& a, const Ref<B>& b) noexcept {
    return !(a == b);
}
template <class A>
inline bool operator==(const Ref<A>& a, std::nullptr_t) noexcept {
    return a.get() == nullptr;
}
template <class A>
inline bool operator!=(const Ref<A>& a, std::nullptr_t) noexcept {
    return a.get() != nullptr;
}
template <class A>
inline bool operator==(std::nullptr_t, const Ref<A>& a) noexcept {
    return a.get() == nullptr;
}
template <class A>
inline bool operator!=(std::nullptr_t, const Ref<A>& a) noexcept {
    return a.get() != nullptr;
}

/** A new object, constructed the Java way: zeroed, then __init(args). */
template <class T, class... A>
inline Ref<T> New(A&&... args) {
    Ref<T> r(new T());
    r->__init(std::forward<A>(args)...);
    return r;
}

/** Java exceptions in flight. */
struct Thrown {
    Ref<java::lang::Throwable> t;
};

[[noreturn]] void throwJava(const Ref<java::lang::Throwable>& t);
template <class T>
[[noreturn]] inline void throwJava(const Ref<T>& t) {
    throwJava(Ref<java::lang::Throwable>(t));
}

/** Runs a Java finally block on scope exit. */
template <class F>
class Finally {
    F f_;

public:
    explicit Finally(F f) : f_(std::move(f)) {}
    ~Finally() noexcept(false) { f_(); }
};

/** Holds an object's monitor (synchronized). */
class Synchronized {
    Monitor* m_;

public:
    explicit Synchronized(java::lang::Object* o);
    explicit Synchronized(Monitor* m);
    template <class T>
    explicit Synchronized(T* o) : Synchronized(toObjectPtr(o)) {}
    ~Synchronized();

private:
    template <class T>
    static java::lang::Object* toObjectPtr(T* p);
};
Monitor* classMonitor(const char* name);

// ---- integer arithmetic with Java's rules ----

template <class T>
inline T div(T a, T b) {
    static_assert(std::is_same_v<T, int32_t> || std::is_same_v<T, int64_t>);
    if (b == 0) throwArithmetic("/ by zero");
    if (b == -1) return T(0) - a;   // MIN / -1 wraps (-fwrapv)
    return a / b;
}
template <class T>
inline T rem(T a, T b) {
    static_assert(std::is_same_v<T, int32_t> || std::is_same_v<T, int64_t>);
    if (b == 0) throwArithmetic("/ by zero");
    if (b == -1) return 0;
    return a % b;
}
inline int32_t shl(int32_t a, int32_t n) { return int32_t(uint32_t(a) << (n & 31)); }
inline int64_t shl(int64_t a, int32_t n) { return int64_t(uint64_t(a) << (n & 63)); }
inline int64_t shl(int64_t a, int64_t n) { return shl(a, int32_t(n)); }
inline int32_t shl(int32_t a, int64_t n) { return shl(a, int32_t(n)); }
inline int32_t shr(int32_t a, int32_t n) { return a >> (n & 31); }
inline int64_t shr(int64_t a, int32_t n) { return a >> (n & 63); }
inline int64_t shr(int64_t a, int64_t n) { return shr(a, int32_t(n)); }
inline int32_t shr(int32_t a, int64_t n) { return shr(a, int32_t(n)); }
inline int32_t ushr(int32_t a, int32_t n) { return int32_t(uint32_t(a) >> (n & 31)); }
inline int64_t ushr(int64_t a, int32_t n) { return int64_t(uint64_t(a) >> (n & 63)); }
inline int64_t ushr(int64_t a, int64_t n) { return ushr(a, int32_t(n)); }
inline int32_t ushr(int32_t a, int64_t n) { return ushr(a, int32_t(n)); }

/** Java's (int) of a float/double: saturates, NaN is 0. */
template <class F>
inline int32_t f2i(F f) {
    if (f != f) return 0;
    if (f >= F(2147483647.0)) return std::numeric_limits<int32_t>::max();
    if (f <= F(-2147483648.0)) return std::numeric_limits<int32_t>::min();
    return int32_t(f);
}
template <class F>
inline int64_t f2l(F f) {
    if (f != f) return 0;
    if (f >= F(9223372036854775807.0)) return std::numeric_limits<int64_t>::max();
    if (f <= F(-9223372036854775808.0)) return std::numeric_limits<int64_t>::min();
    return int64_t(f);
}
inline float fmod(float a, float b) { return std::fmod(a, b); }
inline double fmod(double a, double b) { return std::fmod(a, b); }
inline float fNaN() { return std::numeric_limits<float>::quiet_NaN(); }
inline float fInf() { return std::numeric_limits<float>::infinity(); }
inline double dNaN() { return std::numeric_limits<double>::quiet_NaN(); }
inline double dInf() { return std::numeric_limits<double>::infinity(); }

/** Frees objects whose count dropped to zero (call at safe points). */
void collect();
/** Frees unreachable reference cycles when enough was allocated since the
    last time (call at the safe point, after collect()). */
void maybeCollectCycles();
/** Runs the cycle collector now; false if the other threads did not stop. */
bool collectCycles();

/**
 * A thread running Java code: the cycle collector only runs while every
 * such thread is stopped (outside its scopes or in a SafeRegion). Nests.
 */
class MutatorScope {
public:
    MutatorScope();
    ~MutatorScope();
    MutatorScope(const MutatorScope&) = delete;
    MutatorScope& operator=(const MutatorScope&) = delete;
};
/** A blocking wait inside Java code (sleep, wait, join, monitor entry): the
    collector may run meanwhile. Leaving it waits for a running collection. */
class SafeRegion {
    int depth_;

public:
    SafeRegion();
    ~SafeRegion();
    SafeRegion(const SafeRegion&) = delete;
    SafeRegion& operator=(const SafeRegion&) = delete;
};

/**
 * Visits an object's references for the cycle collector. A tracer must
 * report only references the object holds (counted Refs), each once; one
 * it leaves out only keeps what it points to alive.
 */
class Tracer {
public:
    enum class Mode { Count, Mark, Clear };
    Mode mode = Mode::Count;
    Dumper* dumper = nullptr;   // reused for the translated classes' field lists

    template <class T>
    void operator()(Ref<T>& r) {
        if (!r.get()) return;
        if (mode == Mode::Clear) {
            r = nullptr;
        } else {
            edge(toObjectSlow(r.get()));
        }
    }
    template <class C>
    void all(C& refs) {
        for (auto& r : refs) (*this)(r);
    }

private:
    void edge(java::lang::Object* o);
    template <class T>
    static java::lang::Object* toObjectSlow(T* p);
};
/** The thread started for this runnable becomes the safe point thread. */
void setSafePointRunnable(void* runnable);
/** The thread whose loop is the safe point (the game loop). */
void setSafePointThread();
bool onSafePointThread();

}  // namespace jrt

namespace java::lang {

/** java.lang.Object: the root of every class (interfaces are separate). */
class Object {
public:
    std::atomic<int32_t> __rc{0};
    uint32_t __gcSlot = 0;    // index in the collector's list of objects
    int32_t __gcRefs = 0;     // collector scratch: count minus traced references
    std::atomic<bool> __dying{false};
    std::atomic<jrt::Monitor*> __monitor{nullptr};

    Object();
    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;
    virtual ~Object();

    void __init() {}
    static void __clinit() {}

    virtual jrt::Ref<String> toString();
    virtual bool equals(jrt::Ref<Object> o);
    virtual int32_t hashCode();
    jrt::Ref<Class> getClass();
    void wait();
    void wait(int64_t millis);
    void notify();
    void notifyAll();

    /** For diagnostics: the C++ class name. */
    const char* className() const;

    // deterministic runs (org::deep3d::Det): the game's objects list their
    // fields like the Java build's reflection does
    virtual bool __dumpable() { return false; }
    virtual const char* __javaName() { return ""; }
    virtual void __dumpFields(jrt::Dumper&) {}

    // the cycle collector: the references of hand-written classes (each
    // calls its base's); the translated classes' come from __dumpFields
    virtual void __gcTrace(jrt::Tracer&) {}
    /** Called once before an unreachable object's references are cleared. */
    virtual void __gcUnreachable() {}
};

}  // namespace java::lang

namespace jrt {

/** The Object behind a class or interface pointer. */
template <class T>
inline java::lang::Object* toObject(T* p) noexcept {
    if constexpr (std::is_base_of_v<java::lang::Object, T>) {
        return static_cast<java::lang::Object*>(p);
    } else {
        return dynamic_cast<java::lang::Object*>(p);
    }
}

template <class T>
inline java::lang::Object* Synchronized::toObjectPtr(T* p) {
    return toObject(p);
}
template <class T>
inline java::lang::Object* Tracer::toObjectSlow(T* p) {
    return toObject(p);
}

template <class T>
struct isRef : std::false_type {};
template <class E>
struct isRef<Ref<E>> : std::true_type {};

template <class T>
inline void retain(T* p) noexcept {
    toObject(p)->__rc.fetch_add(1, std::memory_order_relaxed);
}
template <class T>
inline void release(T* p) noexcept {
    java::lang::Object* o = toObject(p);
    if (o->__rc.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        destroyLater(o);
    }
}

/** Any array (System.arraycopy works on these). */
class ArrayBase : public java::lang::Object {
public:
    const int32_t length;
    explicit ArrayBase(int32_t n) : length(n) {}
    /** Copies [srcPos, srcPos+len) into dst at dstPos (overlap-safe). */
    virtual void copyRange(int32_t srcPos, ArrayBase* dst, int32_t dstPos, int32_t len) = 0;
    /** Arrays of class references share one layout (Java's covariance). */
    virtual bool isRefArray() const { return false; }
    virtual void __dumpElems(jrt::Dumper& d) = 0;
};

/** Whether T is a reference to a class (not an interface): those arrays alias. */
template <class T>
struct isClassRef : std::false_type {};
template <class E>
struct isClassRef<Ref<E>> : std::bool_constant<std::is_base_of_v<java::lang::Object, E>> {};

/** A Java array: fixed length, bounds checked, elements zeroed. */
template <class T>
class Array : public ArrayBase {
public:
    T* const data;

    explicit Array(int32_t n) : ArrayBase(n), data(n > 0 ? new T[size_t(n)]() : nullptr) {}
    ~Array() override { delete[] data; }

    static constexpr bool kRefArray = isClassRef<T>::value;

    bool isRefArray() const override { return kRefArray; }

    void copyRange(int32_t srcPos, ArrayBase* dst, int32_t dstPos, int32_t len) override {
        Array<T>* d = dynamic_cast<Array<T>*>(dst);
        if (!d && kRefArray && dst->isRefArray()) {
            d = reinterpret_cast<Array<T>*>(dst);   // same layout (covariance)
        }
        if (!d) throwArrayStore();
        if (len < 0 || srcPos < 0 || dstPos < 0 || int64_t(srcPos) + len > length ||
            int64_t(dstPos) + len > d->length) {
            throwAIOOBE(srcPos < 0 ? srcPos : dstPos, length);
        }
        if (d == this && srcPos < dstPos) {
            for (int32_t i = len - 1; i >= 0; i--) d->data[dstPos + i] = data[srcPos + i];
        } else {
            for (int32_t i = 0; i < len; i++) d->data[dstPos + i] = data[srcPos + i];
        }
    }

    void __dumpElems(jrt::Dumper& d) override;

    void __gcTrace(Tracer& t) override {
        if constexpr (isRef<T>::value) {
            for (int32_t i = 0; i < length; i++) t(data[i]);
        }
    }

    T& at(int32_t i) {
        if (uint32_t(i) >= uint32_t(length)) throwAIOOBE(i, length);
        return data[i];
    }
    T* begin() { return data; }
    T* end() { return data + length; }

    Ref<Array<T>> clone() {
        Ref<Array<T>> c(new Array<T>(length));
        for (int32_t i = 0; i < length; i++) c->data[i] = data[i];
        return c;
    }
};

template <class T>
inline Ref<Array<T>> newArray(int32_t n) {
    if (n < 0) throwNegativeArraySize(n);
    return Ref<Array<T>>(new Array<T>(n));
}

template <class T>
inline Ref<Array<T>> arrayOf(std::initializer_list<T> items) {
    Ref<Array<T>> a(new Array<T>(int32_t(items.size())));
    int32_t i = 0;
    for (const T& x : items) a->data[i++] = x;
    return a;
}

/** The array type with N dimensions of leaf type T. */
template <class T, int N>
struct MultiArray {
    using type = Array<Ref<typename MultiArray<T, N - 1>::type>>;
};
template <class T>
struct MultiArray<T, 1> {
    using type = Array<T>;
};

template <class T, int N>
inline Ref<typename MultiArray<T, N>::type> newMultiArray(const int32_t* dims) {
    using A = typename MultiArray<T, N>::type;
    Ref<A> a(new A(dims[0]));
    if constexpr (N > 1) {
        for (int32_t i = 0; i < dims[0]; i++) a->data[i] = newMultiArray<T, N - 1>(dims + 1);
    }
    return a;
}
template <class T, int N>
inline Ref<typename MultiArray<T, N>::type> newMultiArray(std::initializer_list<int32_t> dims) {
    // Java checks every dimension before allocating
    for (int32_t d : dims)
        if (d < 0) throwNegativeArraySize(d);
    return newMultiArray<T, N>(dims.begin());
}

// ---- casts ----

template <class A>
struct isArrayType : std::false_type {};
template <class E>
struct isArrayType<Array<E>> : std::true_type {};

template <class T, class U>
inline bool isInstance(const Ref<U>& r) {
    if (!r.get()) return false;
    if (dynamic_cast<T*>(r.get())) return true;
    if constexpr (isArrayType<T>::value) {
        if constexpr (T::kRefArray) {
            // any array of class references is an Object[] (covariance;
            // element types are not tracked)
            auto* a = dynamic_cast<ArrayBase*>(toObject(r.get()));
            return a && a->isRefArray();
        }
    }
    return false;
}

template <class T, class U>
inline Ref<T> cast(const Ref<U>& r) {
    if (!r.get()) return nullptr;
    if (T* t = dynamic_cast<T*>(r.get())) return Ref<T>(t);
    if constexpr (isArrayType<T>::value) {
        if constexpr (T::kRefArray) {
            auto* a = dynamic_cast<ArrayBase*>(toObject(r.get()));
            if (a && a->isRefArray()) return Ref<T>(reinterpret_cast<T*>(a));
        }
    }
    throwClassCast(toObject(r.get())->className(), typeid(T).name());
}
template <class T>
inline Ref<T> cast(std::nullptr_t) {
    return nullptr;
}

/** An array of class references seen as an array of a supertype (aliasing). */
template <class E, class F>
inline Ref<Array<E>> arrayView(const Ref<Array<F>>& a) {
    static_assert(Array<E>::kRefArray && Array<F>::kRefArray, "covariance needs class references");
    return Ref<Array<E>>(reinterpret_cast<Array<E>*>(a.get()));
}

}  // namespace jrt

#include "jrt_lang.h"
#include "jrt_dump.h"
