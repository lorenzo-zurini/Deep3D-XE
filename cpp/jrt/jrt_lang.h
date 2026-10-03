// java.lang for the translated code: String, StringBuffer, the boxed
// types, exceptions, Math, System, Thread.
#pragma once
#include "jrt.h"

#include <string>
#include <thread>
#include <typeinfo>

namespace java::io {
class PrintStream;
class InputStream;
}

namespace java::lang {

using jrt::Array;
using jrt::Ref;

/** java.lang.String: immutable UTF-16 text. */
class String : public Object {
public:
    std::u16string s;

    String() = default;
    explicit String(std::u16string v) : s(std::move(v)) {}

    void __init() {}
    void __init(Ref<Array<char16_t>> chars);
    void __init(Ref<Array<char16_t>> chars, int32_t off, int32_t len);
    void __init(Ref<Array<int8_t>> bytes);
    void __init(Ref<Array<int8_t>> bytes, int32_t off, int32_t len);
    void __init(Ref<Array<int8_t>> bytes, Ref<String> charset);
    void __init(Ref<String> other);

    static Ref<String> of(std::u16string v);
    static Ref<String> fromUtf8(const std::string& v);
    std::string utf8() const;

    int32_t length() { return int32_t(s.size()); }
    bool isEmpty() { return s.empty(); }
    char16_t charAt(int32_t i);
    Ref<String> substring(int32_t begin);
    Ref<String> substring(int32_t begin, int32_t end);
    int32_t indexOf(int32_t ch);
    int32_t indexOf(int32_t ch, int32_t from);
    int32_t indexOf(Ref<String> str);
    int32_t indexOf(Ref<String> str, int32_t from);
    int32_t lastIndexOf(int32_t ch);
    int32_t lastIndexOf(int32_t ch, int32_t from);
    int32_t lastIndexOf(Ref<String> str);
    bool startsWith(Ref<String> p);
    bool startsWith(Ref<String> p, int32_t off);
    bool endsWith(Ref<String> p);
    Ref<String> trim();
    Ref<String> toUpperCase();
    Ref<String> toLowerCase();
    Ref<String> replace(char16_t a, char16_t b);
    Ref<String> concat(Ref<String> o);
    bool equalsIgnoreCase(Ref<String> o);
    int32_t compareTo(Ref<String> o);
    Ref<Array<char16_t>> toCharArray();
    Ref<Array<int8_t>> getBytes();
    Ref<Array<int8_t>> getBytes(Ref<String> charset);
    void getChars(int32_t srcBegin, int32_t srcEnd, Ref<Array<char16_t>> dst, int32_t dstBegin);
    Ref<String> intern();
    bool contains(Ref<String> o);
    bool equals(Ref<Object> o) override;
    int32_t hashCode() override;
    Ref<String> toString() override;

    static Ref<String> valueOf(int32_t v);
    static Ref<String> valueOf(int64_t v);
    static Ref<String> valueOf(float v);
    static Ref<String> valueOf(double v);
    static Ref<String> valueOf(bool v);
    static Ref<String> valueOf(char16_t v);
    static Ref<String> valueOf(Ref<Object> v);
    static Ref<String> valueOf(Ref<Array<char16_t>> v);
};

}  // namespace java::lang

namespace jrt {

/** The interned String for a literal. */
const Ref<java::lang::String>& intern(const char16_t* s, size_t n);

// Java's text forms of values, for concatenation and StringBuffer
void appendTo(std::u16string& o, int8_t v);
void appendTo(std::u16string& o, int16_t v);
void appendTo(std::u16string& o, int32_t v);
void appendTo(std::u16string& o, int64_t v);
void appendTo(std::u16string& o, char16_t v);
void appendTo(std::u16string& o, bool v);
void appendTo(std::u16string& o, float v);
void appendTo(std::u16string& o, double v);
void appendTo(std::u16string& o, const Ref<java::lang::String>& v);
void appendTo(std::u16string& o, java::lang::Object* v);
template <class T>
inline void appendTo(std::u16string& o, const Ref<T>& v) {
    appendTo(o, static_cast<java::lang::Object*>(v.get()));
}
inline void appendTo(std::u16string& o, std::nullptr_t) { o += u"null"; }

std::u16string floatToString(float v);
std::u16string doubleToString(double v);

/** "a" + b + c ... */
template <class... A>
inline Ref<java::lang::String> concat(const A&... parts) {
    std::u16string o;
    (appendTo(o, parts), ...);
    return java::lang::String::of(std::move(o));
}

/** An InputStream of a game resource ("/data/..."), or null. */
Ref<java::io::InputStream> getResourceAsStream(const Ref<java::lang::String>& name);

}  // namespace jrt

/** A string literal: interned once per use site. */
#define JRT_LIT(s)                                                                         \
    ([]() -> const ::jrt::Ref<::java::lang::String>& {                                    \
        static const ::jrt::Ref<::java::lang::String>& lit =                               \
            ::jrt::intern(s, sizeof(s) / sizeof(char16_t) - 1);                            \
        return lit;                                                                        \
    }())

namespace java::lang {

/** Interfaces are abstract bases outside the Object chain. */
class Runnable {
public:
    virtual ~Runnable() = default;
    virtual void run() = 0;
};

/** java.lang.Class: only what the game uses (resources, forName). */
class Class : public Object {
public:
    std::string name;
    static Ref<Class> forName(Ref<String> name);
    Ref<java::io::InputStream> getResourceAsStream(Ref<String> name);
    Ref<String> getName();
};

class Throwable : public Object {
public:
    Ref<String> message;
    void __init() {}
    void __init(Ref<String> msg) { message = msg; }
    virtual Ref<String> getMessage() { return message; }
    Ref<String> toString() override;
    void printStackTrace();
};

#define JRT_EXCEPTION(Name, Base)                      \
    class Name : public Base {                         \
    public:                                            \
        void __init() { Base::__init(); }              \
        void __init(Ref<String> m) { Base::__init(m); } \
    };

JRT_EXCEPTION(Exception, Throwable)
JRT_EXCEPTION(Error, Throwable)
JRT_EXCEPTION(RuntimeException, Exception)
JRT_EXCEPTION(NullPointerException, RuntimeException)
JRT_EXCEPTION(ArithmeticException, RuntimeException)
JRT_EXCEPTION(ClassCastException, RuntimeException)
JRT_EXCEPTION(IndexOutOfBoundsException, RuntimeException)
JRT_EXCEPTION(ArrayIndexOutOfBoundsException, IndexOutOfBoundsException)
JRT_EXCEPTION(StringIndexOutOfBoundsException, IndexOutOfBoundsException)
JRT_EXCEPTION(NegativeArraySizeException, RuntimeException)
JRT_EXCEPTION(ArrayStoreException, RuntimeException)
JRT_EXCEPTION(IllegalArgumentException, RuntimeException)
JRT_EXCEPTION(IllegalStateException, RuntimeException)
JRT_EXCEPTION(NumberFormatException, IllegalArgumentException)
JRT_EXCEPTION(UnsupportedOperationException, RuntimeException)
JRT_EXCEPTION(SecurityException, RuntimeException)
JRT_EXCEPTION(InterruptedException, Exception)
JRT_EXCEPTION(ReflectiveOperationException, Exception)
JRT_EXCEPTION(ClassNotFoundException, ReflectiveOperationException)
JRT_EXCEPTION(NoSuchFieldException, ReflectiveOperationException)
JRT_EXCEPTION(NoSuchMethodException, ReflectiveOperationException)
JRT_EXCEPTION(IllegalAccessException, ReflectiveOperationException)
JRT_EXCEPTION(CloneNotSupportedException, Exception)
JRT_EXCEPTION(LinkageError, Error)
JRT_EXCEPTION(NoClassDefFoundError, LinkageError)
JRT_EXCEPTION(VirtualMachineError, Error)
JRT_EXCEPTION(OutOfMemoryError, VirtualMachineError)

/** Mutable text: StringBuffer and StringBuilder. */
class StringBuffer : public Object {
public:
    std::u16string s;
    void __init() {}
    void __init(int32_t capacity) { s.reserve(size_t(capacity > 0 ? capacity : 0)); }
    void __init(Ref<String> v);

    template <class T>
    Ref<StringBuffer> append(const T& v) {
        jrt::appendTo(s, v);
        return Ref<StringBuffer>(this);
    }
    Ref<StringBuffer> append(Ref<Array<char16_t>> chars);
    Ref<StringBuffer> insert(int32_t off, Ref<String> v);
    Ref<StringBuffer> insert(int32_t off, char16_t c);
    Ref<StringBuffer> deleteCharAt(int32_t i);
    Ref<StringBuffer> delete_(int32_t start, int32_t end);
    Ref<StringBuffer> reverse();
    int32_t length() { return int32_t(s.size()); }
    char16_t charAt(int32_t i);
    void setCharAt(int32_t i, char16_t c);
    void setLength(int32_t n);
    Ref<String> toString() override { return String::of(s); }
};
class StringBuilder : public StringBuffer {
public:
    template <class T>
    Ref<StringBuilder> append(const T& v) {
        jrt::appendTo(s, v);
        return Ref<StringBuilder>(this);
    }
};

/** Boxed numbers (Hashtable keys, collections). */
class Number : public Object {
public:
    virtual int32_t intValue() = 0;
    virtual int64_t longValue() = 0;
    virtual float floatValue() = 0;
    virtual double doubleValue() = 0;
};

class Integer : public Number {
public:
    int32_t value = 0;
    void __init(int32_t v) { value = v; }
    static constexpr int32_t MAX_VALUE = 2147483647;
    static constexpr int32_t MIN_VALUE = -2147483647 - 1;
    static Ref<Integer> valueOf(int32_t v);
    static Ref<Integer> valueOf(Ref<String> s);
    static int32_t parseInt(Ref<String> s);
    static int32_t parseInt(Ref<String> s, int32_t radix);
    static Ref<String> toString(int32_t v);
    static Ref<String> toString(int32_t v, int32_t radix);
    static Ref<String> toHexString(int32_t v);
    static Ref<String> toBinaryString(int32_t v);
    int32_t intValue() override { return value; }
    int64_t longValue() override { return value; }
    float floatValue() override { return float(value); }
    double doubleValue() override { return double(value); }
    bool equals(Ref<Object> o) override;
    int32_t hashCode() override { return value; }
    Ref<String> toString() override;
};

class Long : public Number {
public:
    int64_t value = 0;
    void __init(int64_t v) { value = v; }
    static Ref<Long> valueOf(int64_t v);
    static int64_t parseLong(Ref<String> s);
    int32_t intValue() override { return int32_t(value); }
    int64_t longValue() override { return value; }
    float floatValue() override { return float(value); }
    double doubleValue() override { return double(value); }
    bool equals(Ref<Object> o) override;
    int32_t hashCode() override { return int32_t(value ^ (uint64_t(value) >> 32)); }
    Ref<String> toString() override;
};

class Short : public Number {
public:
    int16_t value = 0;
    static Ref<Short> valueOf(int16_t v);
    static int16_t parseShort(Ref<String> s);
    int32_t intValue() override { return value; }
    int64_t longValue() override { return value; }
    float floatValue() override { return value; }
    double doubleValue() override { return value; }
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Short*>(o.get()) : nullptr;
        return b && b->value == value;
    }
    int32_t hashCode() override { return value; }
    Ref<String> toString() override;
};

class Byte : public Number {
public:
    int8_t value = 0;
    static Ref<Byte> valueOf(int8_t v);
    static int8_t parseByte(Ref<String> s);
    int32_t intValue() override { return value; }
    int64_t longValue() override { return value; }
    float floatValue() override { return value; }
    double doubleValue() override { return value; }
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Byte*>(o.get()) : nullptr;
        return b && b->value == value;
    }
    int32_t hashCode() override { return value; }
    Ref<String> toString() override;
};

class Float : public Number {
public:
    float value = 0;
    static Ref<Float> valueOf(float v);
    static int32_t floatToIntBits(float v);
    static int32_t floatToRawIntBits(float v);
    static float intBitsToFloat(int32_t v);
    static bool isNaN(float v) { return v != v; }
    int32_t intValue() override { return jrt::f2i(value); }
    int64_t longValue() override { return jrt::f2l(value); }
    float floatValue() override { return value; }
    double doubleValue() override { return value; }
    Ref<String> toString() override;
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Float*>(o.get()) : nullptr;
        return b && floatToIntBits(b->value) == floatToIntBits(value);
    }
    int32_t hashCode() override { return floatToIntBits(value); }
};

class Double : public Number {
public:
    double value = 0;
    static Ref<Double> valueOf(double v);
    static int64_t doubleToLongBits(double v);
    static double longBitsToDouble(int64_t v);
    int32_t intValue() override { return jrt::f2i(value); }
    int64_t longValue() override { return jrt::f2l(value); }
    float floatValue() override { return float(value); }
    double doubleValue() override { return value; }
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Double*>(o.get()) : nullptr;
        return b && doubleToLongBits(b->value) == doubleToLongBits(value);
    }
    int32_t hashCode() override { return int32_t(doubleToLongBits(value) ^ (uint64_t(doubleToLongBits(value)) >> 32)); }
    Ref<String> toString() override;
};

class Boolean : public Object {
public:
    bool value = false;
    void __init(bool v) { value = v; }
    static Ref<Boolean> valueOf(bool v);
    bool booleanValue() { return value; }
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Boolean*>(o.get()) : nullptr;
        return b && b->value == value;
    }
    int32_t hashCode() override { return value ? 1231 : 1237; }
    Ref<String> toString() override;
};

class Character : public Object {
public:
    char16_t value = 0;
    static Ref<Character> valueOf(char16_t v);
    char16_t charValue() { return value; }
    static bool isDigit(char16_t c);
    static bool isLetter(char16_t c);
    static bool isLetterOrDigit(char16_t c);
    static bool isWhitespace(char16_t c);
    static bool isUpperCase(char16_t c);
    static bool isLowerCase(char16_t c);
    static char16_t toUpperCase(char16_t c);
    static char16_t toLowerCase(char16_t c);
    static int32_t digit(char16_t c, int32_t radix);
    bool equals(Ref<Object> o) override {
        auto* b = o ? dynamic_cast<Character*>(o.get()) : nullptr;
        return b && b->value == value;
    }
    int32_t hashCode() override { return value; }
    Ref<String> toString() override;
};

class Math : public Object {
public:
    static constexpr double PI = 3.141592653589793;
    static constexpr double E = 2.718281828459045;
    static int32_t abs(int32_t v) { return v < 0 ? -v : v; }
    static int64_t abs(int64_t v) { return v < 0 ? -v : v; }
    static float abs(float v) { return std::fabs(v); }
    static double abs(double v) { return std::fabs(v); }
    static int32_t min(int32_t a, int32_t b) { return a < b ? a : b; }
    static int64_t min(int64_t a, int64_t b) { return a < b ? a : b; }
    static float min(float a, float b);
    static double min(double a, double b);
    static int32_t max(int32_t a, int32_t b) { return a > b ? a : b; }
    static int64_t max(int64_t a, int64_t b) { return a > b ? a : b; }
    static float max(float a, float b);
    static double max(double a, double b);
    static double sqrt(double v) { return std::sqrt(v); }
    static double tan(double v);
    static double atan(double v);
    static double floor(double v) { return std::floor(v); }
    static double ceil(double v) { return std::ceil(v); }
    static int32_t round(float v);
    static int64_t round(double v);
    static double toRadians(double v) { return v * 0.017453292519943295; }   // as the JDK
    static double toDegrees(double v) { return v * 57.29577951308232; }
    static double random();
};

class Thread : public Object, public Runnable {
public:
    Ref<Runnable> target;
    Ref<String> name;
    std::thread* native = nullptr;
    std::atomic<bool> started{false};
    std::atomic<bool> alive{false};

    void __init() { name = nextName(); }
    void __init(Ref<Runnable> r) {
        target = r;
        name = nextName();
    }
    void __init(Ref<Runnable> r, Ref<String> n) {
        target = r;
        name = n;
    }
    ~Thread() override;
    Ref<String> getName();

    void run() override;
    void start();
    void join();
    void join(int64_t millis);
    bool isAlive() { return alive; }
    void interrupt() {}
    void setPriority(int32_t) {}
    void setDaemon(bool) {}
    static void sleep(int64_t millis);
    static void yield();
    static Ref<Thread> currentThread();

private:
    static Ref<String> nextName();   // "Thread-<n>", numbered as Java numbers unnamed threads
};

class System : public Object {
public:
    static Ref<java::io::PrintStream> out;
    static Ref<java::io::PrintStream> err;
    static int64_t currentTimeMillis();
    static int64_t nanoTime();
    static void arraycopy(Ref<Object> src, int32_t srcPos, Ref<Object> dst, int32_t dstPos, int32_t len);
    static void gc() {}
    static void exit(int32_t code);
    static Ref<String> getProperty(Ref<String> key);
    static Ref<String> getenv(Ref<String> key);
    static int32_t identityHashCode(Ref<Object> o);
};

class Runtime : public Object {
public:
    static Ref<Runtime> getRuntime();
    int64_t freeMemory() { return 64 << 20; }
    int64_t totalMemory() { return 128 << 20; }
    void gc() {}
};

}  // namespace java::lang
