// jrt: object lifetime, exceptions, monitors, java.lang.
#include "jrt.h"
#include "jrt_io.h"

#include <algorithm>
#include <chrono>
#include <charconv>
#include <condition_variable>
#include <cxxabi.h>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace jrt {

// ---------------------------------------------------------------------
// Lifetime: objects at count zero are freed at the next safe point
// ---------------------------------------------------------------------

extern std::atomic<void*> gSafePointRunnable;

namespace {
std::mutex gDeadLock;
std::vector<java::lang::Object*> gDead;
std::thread::id gSafePointThread;
bool gHaveSafePoint = false;
}  // namespace

void destroyLater(java::lang::Object* o) {
    bool expected = false;
    if (!o->__dying.compare_exchange_strong(expected, true)) {
        return;     // already queued (it was revived and dropped again)
    }
    std::lock_guard<std::mutex> g(gDeadLock);
    gDead.push_back(o);
}

void collect() {
    // freeing can drop more counts to zero: repeat until quiet
    for (int round = 0; round < 64; round++) {
        std::vector<java::lang::Object*> batch;
        {
            std::lock_guard<std::mutex> g(gDeadLock);
            batch.swap(gDead);
        }
        if (batch.empty()) {
            return;
        }
        for (java::lang::Object* o : batch) {
            if (o->__rc.load(std::memory_order_acquire) == 0) {
                delete o;
            } else {
                o->__dying = false;     // revived: a reference was taken again
            }
        }
    }
}

std::atomic<void*> gSafePointRunnable{nullptr};

void setSafePointRunnable(void* runnable) { gSafePointRunnable = runnable; }

void setSafePointThread() {
    gSafePointThread = std::this_thread::get_id();
    gHaveSafePoint = true;
}

bool onSafePointThread() {
    return gHaveSafePoint && std::this_thread::get_id() == gSafePointThread;
}

java::lang::Object* asObject(java::lang::Object* o) { return o; }

// ---------------------------------------------------------------------
// Exceptions
// ---------------------------------------------------------------------

template <class E>
[[noreturn]] static void throwNew(const std::u16string& msg) {
    Ref<E> e(new E());
    if (!msg.empty()) {
        e->message = java::lang::String::of(msg);
    }
    throw Thrown{Ref<java::lang::Throwable>(e)};
}

static std::u16string u16(const std::string& s) {
    return std::u16string(s.begin(), s.end());
}

void throwNPE() { throwNew<java::lang::NullPointerException>(u""); }

void throwAIOOBE(int32_t index, int32_t length) {
    throwNew<java::lang::ArrayIndexOutOfBoundsException>(
        u16("Index " + std::to_string(index) + " out of bounds for length " + std::to_string(length)));
}

void throwArithmetic(const char* msg) { throwNew<java::lang::ArithmeticException>(u16(msg)); }

void throwClassCast(const char* from, const char* to) {
    int st = 0;
    char* dn = abi::__cxa_demangle(to, nullptr, nullptr, &st);
    std::string t = dn ? dn : to;
    free(dn);
    throwNew<java::lang::ClassCastException>(u16(std::string("class ") + from + " cannot be cast to " + t));
}

void throwNegativeArraySize(int32_t n) {
    throwNew<java::lang::NegativeArraySizeException>(u16(std::to_string(n)));
}

void throwArrayStore() { throwNew<java::lang::RuntimeException>(u"ArrayStoreException"); }

void throwJava(const Ref<java::lang::Throwable>& t) {
    if (!t) throwNPE();
    throw Thrown{t};
}

// ---------------------------------------------------------------------
// Monitors: recursive locks with wait/notify
// ---------------------------------------------------------------------

class Monitor {
public:
    std::mutex m;
    std::condition_variable cv;
    std::thread::id owner;
    int count = 0;

    void enter() {
        std::unique_lock<std::mutex> l(m);
        auto me = std::this_thread::get_id();
        if (count > 0 && owner == me) {
            count++;
            return;
        }
        cv.wait(l, [&] { return count == 0; });
        owner = me;
        count = 1;
    }
    void exit() {
        std::unique_lock<std::mutex> l(m);
        if (--count == 0) {
            owner = std::thread::id();
            cv.notify_all();
        }
    }
    void wait(int64_t millis) {
        std::unique_lock<std::mutex> l(m);
        int saved = count;
        count = 0;
        owner = std::thread::id();
        cv.notify_all();
        if (millis > 0) {
            cv.wait_for(l, std::chrono::milliseconds(millis));
        } else {
            cv.wait(l);
        }
        cv.wait(l, [&] { return count == 0; });
        owner = std::this_thread::get_id();
        count = saved;
    }
    void notifyAll() { cv.notify_all(); }
};

static Monitor* monitorOf(java::lang::Object* o) {
    Monitor* m = o->__monitor.load(std::memory_order_acquire);
    if (m) return m;
    Monitor* fresh = new Monitor();
    if (o->__monitor.compare_exchange_strong(m, fresh)) return fresh;
    delete fresh;
    return m;
}

Synchronized::Synchronized(java::lang::Object* o) : m_(monitorOf(o)) { m_->enter(); }
Synchronized::Synchronized(Monitor* m) : m_(m) { m_->enter(); }
Synchronized::~Synchronized() { m_->exit(); }

Monitor* classMonitor(const char* name) {
    static std::mutex lock;
    static std::unordered_map<std::string, Monitor*> monitors;
    std::lock_guard<std::mutex> g(lock);
    Monitor*& m = monitors[name];
    if (!m) m = new Monitor();
    return m;
}

// ---------------------------------------------------------------------
// Strings
// ---------------------------------------------------------------------

const Ref<java::lang::String>& intern(const char16_t* s, size_t n) {
    static std::mutex lock;
    static std::unordered_map<std::u16string, Ref<java::lang::String>> table;
    std::lock_guard<std::mutex> g(lock);
    std::u16string key(s, n);
    auto it = table.find(key);
    if (it == table.end()) {
        Ref<java::lang::String> str(new java::lang::String(key));
        it = table.emplace(key, str).first;
    }
    return it->second;
}

static void appendAscii(std::u16string& o, const char* s, size_t n) {
    for (size_t i = 0; i < n; i++) o.push_back(char16_t(s[i]));
}

void appendTo(std::u16string& o, int8_t v) { appendTo(o, int32_t(v)); }
void appendTo(std::u16string& o, int16_t v) { appendTo(o, int32_t(v)); }
void appendTo(std::u16string& o, int32_t v) {
    char b[16];
    auto r = std::to_chars(b, b + sizeof b, v);
    appendAscii(o, b, size_t(r.ptr - b));
}
void appendTo(std::u16string& o, int64_t v) {
    char b[24];
    auto r = std::to_chars(b, b + sizeof b, v);
    appendAscii(o, b, size_t(r.ptr - b));
}
void appendTo(std::u16string& o, char16_t v) { o.push_back(v); }
void appendTo(std::u16string& o, bool v) { o += v ? u"true" : u"false"; }
void appendTo(std::u16string& o, float v) { o += floatToString(v); }
void appendTo(std::u16string& o, double v) { o += doubleToString(v); }
void appendTo(std::u16string& o, const Ref<java::lang::String>& v) {
    if (v) {
        o += v->s;
    } else {
        o += u"null";
    }
}
void appendTo(std::u16string& o, java::lang::Object* v) {
    if (!v) {
        o += u"null";
        return;
    }
    Ref<java::lang::String> s = v->toString();
    appendTo(o, s);
}

/** Java's Float/Double.toString from the shortest round-trip digits. */
template <class F>
static std::u16string javaFloat(F v) {
    if (v != v) return u"NaN";
    if (v == std::numeric_limits<F>::infinity()) return u"Infinity";
    if (v == -std::numeric_limits<F>::infinity()) return u"-Infinity";
    if (v == 0) return std::signbit(v) ? u"-0.0" : u"0.0";
    char buf[64];
    auto r = std::to_chars(buf, buf + sizeof buf, v, std::chars_format::scientific);
    std::string sci(buf, r.ptr);
    bool neg = sci[0] == '-';
    if (neg) sci = sci.substr(1);
    size_t e = sci.find('e');
    std::string mant = sci.substr(0, e);
    int exp = std::stoi(sci.substr(e + 1));
    std::string digits;
    for (char c : mant)
        if (c != '.') digits.push_back(c);
    while (digits.size() > 1 && digits.back() == '0') digits.pop_back();
    std::string out;
    F a = v < 0 ? -v : v;
    if (a >= F(1e-3) && a < F(1e7)) {
        if (exp >= 0) {
            std::string ip = digits.substr(0, std::min(digits.size(), size_t(exp + 1)));
            while (ip.size() < size_t(exp + 1)) ip.push_back('0');
            std::string fp = digits.size() > size_t(exp + 1) ? digits.substr(size_t(exp + 1)) : "0";
            out = ip + "." + fp;
        } else {
            out = "0." + std::string(size_t(-exp - 1), '0') + digits;
        }
    } else {
        out = digits.substr(0, 1) + "." + (digits.size() > 1 ? digits.substr(1) : "0") + "E" + std::to_string(exp);
    }
    if (neg) out = "-" + out;
    return std::u16string(out.begin(), out.end());
}

std::u16string floatToString(float v) { return javaFloat(v); }
std::u16string doubleToString(double v) { return javaFloat(v); }

// set by the platform (org.deep3d.Assets)
Ref<java::io::InputStream> (*gResourceHook)(const Ref<java::lang::String>&) = nullptr;

Ref<java::io::InputStream> getResourceAsStream(const Ref<java::lang::String>& name) {
    return gResourceHook ? gResourceHook(name) : nullptr;
}

}  // namespace jrt

namespace java::lang {

using jrt::throwNPE;

// ---------------------------------------------------------------------
// Object
// ---------------------------------------------------------------------

Object::~Object() { delete __monitor.load(); }

const char* Object::className() const {
    static thread_local std::string name;
    int st = 0;
    char* dn = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &st);
    name = dn ? dn : typeid(*this).name();
    free(dn);
    return name.c_str();
}

Ref<String> Object::toString() {
    char buf[32];
    snprintf(buf, sizeof buf, "@%x", uint32_t(hashCode()));
    std::string s = std::string(className()) + buf;
    return String::fromUtf8(s);
}

bool Object::equals(Ref<Object> o) { return o.get() == this; }

int32_t Object::hashCode() {
    return int32_t(reinterpret_cast<uintptr_t>(dynamic_cast<void*>(this)) >> 4);
}

Ref<Class> Object::getClass() {
    Ref<Class> c(new Class());
    c->name = className();
    return c;
}

void Object::wait() { jrt::monitorOf(this)->wait(0); }
void Object::wait(int64_t millis) { jrt::monitorOf(this)->wait(millis); }
void Object::notify() { jrt::monitorOf(this)->notifyAll(); }
void Object::notifyAll() { jrt::monitorOf(this)->notifyAll(); }

// ---------------------------------------------------------------------
// String
// ---------------------------------------------------------------------

Ref<String> String::of(std::u16string v) { return Ref<String>(new String(std::move(v))); }

Ref<String> String::fromUtf8(const std::string& v) {
    std::u16string o;
    for (size_t i = 0; i < v.size();) {
        unsigned char c = (unsigned char)v[i];
        uint32_t cp;
        int n;
        if (c < 0x80) { cp = c; n = 1; }
        else if ((c >> 5) == 6 && i + 1 < v.size()) { cp = ((c & 0x1F) << 6) | (v[i + 1] & 0x3F); n = 2; }
        else if ((c >> 4) == 14 && i + 2 < v.size()) { cp = ((c & 0x0F) << 12) | ((v[i + 1] & 0x3F) << 6) | (v[i + 2] & 0x3F); n = 3; }
        else if ((c >> 3) == 30 && i + 3 < v.size()) {
            cp = ((c & 0x07) << 18) | ((v[i + 1] & 0x3F) << 12) | ((v[i + 2] & 0x3F) << 6) | (v[i + 3] & 0x3F);
            n = 4;
        } else { cp = 0xFFFD; n = 1; }
        if (cp >= 0x10000) {
            cp -= 0x10000;
            o.push_back(char16_t(0xD800 + (cp >> 10)));
            o.push_back(char16_t(0xDC00 + (cp & 0x3FF)));
        } else {
            o.push_back(char16_t(cp));
        }
        i += size_t(n);
    }
    return of(std::move(o));
}

std::string String::utf8() const {
    std::string o;
    for (size_t i = 0; i < s.size(); i++) {
        uint32_t c = s[i];
        if (c >= 0xD800 && c < 0xDC00 && i + 1 < s.size()) {
            c = 0x10000 + ((c - 0xD800) << 10) + (s[i + 1] - 0xDC00);
            i++;
        }
        if (c < 0x80) o.push_back(char(c));
        else if (c < 0x800) { o.push_back(char(0xC0 | (c >> 6))); o.push_back(char(0x80 | (c & 0x3F))); }
        else if (c < 0x10000) {
            o.push_back(char(0xE0 | (c >> 12)));
            o.push_back(char(0x80 | ((c >> 6) & 0x3F)));
            o.push_back(char(0x80 | (c & 0x3F)));
        } else {
            o.push_back(char(0xF0 | (c >> 18)));
            o.push_back(char(0x80 | ((c >> 12) & 0x3F)));
            o.push_back(char(0x80 | ((c >> 6) & 0x3F)));
            o.push_back(char(0x80 | (c & 0x3F)));
        }
    }
    return o;
}

static void sioobe(int32_t i) {
    Ref<StringIndexOutOfBoundsException> e(new StringIndexOutOfBoundsException());
    e->message = jrt::concat(JRT_LIT(u"index "), i);
    jrt::throwJava(e);
}

void String::__init(Ref<Array<char16_t>> chars) { s.assign(chars->data, size_t(chars->length)); }
void String::__init(Ref<Array<char16_t>> chars, int32_t off, int32_t len) {
    if (off < 0 || len < 0 || int64_t(off) + len > chars->length) sioobe(off);
    s.assign(chars->data + off, size_t(len));
}
void String::__init(Ref<Array<int8_t>> bytes) { __init(bytes, 0, bytes->length); }
void String::__init(Ref<Array<int8_t>> bytes, int32_t off, int32_t len) {
    // the platform's default charset: UTF-8
    if (off < 0 || len < 0 || int64_t(off) + len > bytes->length) sioobe(off);
    s = fromUtf8(std::string(reinterpret_cast<const char*>(bytes->data + off), size_t(len)))->s;
}
void String::__init(Ref<Array<int8_t>> bytes, Ref<String> charset) {
    std::string cs = charset->utf8();
    for (auto& c : cs) c = char(tolower(c));
    if (cs == "utf-8" || cs == "utf8") {
        __init(bytes);
        return;
    }
    if (cs == "utf-16be" || cs == "utf-16") {
        s.clear();
        for (int32_t i = 0; i + 1 < bytes->length; i += 2)
            s.push_back(char16_t((uint8_t(bytes->data[i]) << 8) | uint8_t(bytes->data[i + 1])));
        return;
    }
    if (cs == "utf-16le") {
        s.clear();
        for (int32_t i = 0; i + 1 < bytes->length; i += 2)
            s.push_back(char16_t((uint8_t(bytes->data[i + 1]) << 8) | uint8_t(bytes->data[i])));
        return;
    }
    // ISO-8859-1 and anything else: bytes as code points
    s.clear();
    for (int32_t i = 0; i < bytes->length; i++) s.push_back(char16_t(uint8_t(bytes->data[i])));
}
void String::__init(Ref<String> other) { s = other->s; }

char16_t String::charAt(int32_t i) {
    if (uint32_t(i) >= s.size()) sioobe(i);
    return s[size_t(i)];
}
Ref<String> String::substring(int32_t b) { return substring(b, int32_t(s.size())); }
Ref<String> String::substring(int32_t b, int32_t e) {
    if (b < 0 || e > int32_t(s.size()) || b > e) sioobe(b < 0 ? b : e);
    return of(s.substr(size_t(b), size_t(e - b)));
}
int32_t String::indexOf(int32_t ch) { return indexOf(ch, 0); }
int32_t String::indexOf(int32_t ch, int32_t from) {
    if (from < 0) from = 0;
    for (size_t i = size_t(from); i < s.size(); i++)
        if (s[i] == ch) return int32_t(i);
    return -1;
}
int32_t String::indexOf(Ref<String> str) { return indexOf(str, 0); }
int32_t String::indexOf(Ref<String> str, int32_t from) {
    if (from < 0) from = 0;
    if (size_t(from) > s.size()) return str->s.empty() ? int32_t(s.size()) : -1;
    size_t p = s.find(str->s, size_t(from));
    return p == std::u16string::npos ? -1 : int32_t(p);
}
int32_t String::lastIndexOf(int32_t ch) { return lastIndexOf(ch, int32_t(s.size()) - 1); }
int32_t String::lastIndexOf(int32_t ch, int32_t from) {
    if (from >= int32_t(s.size())) from = int32_t(s.size()) - 1;
    for (int32_t i = from; i >= 0; i--)
        if (s[size_t(i)] == ch) return i;
    return -1;
}
int32_t String::lastIndexOf(Ref<String> str) {
    size_t p = s.rfind(str->s);
    return p == std::u16string::npos ? -1 : int32_t(p);
}
bool String::startsWith(Ref<String> p) { return s.compare(0, p->s.size(), p->s) == 0 && s.size() >= p->s.size(); }
bool String::startsWith(Ref<String> p, int32_t off) {
    if (off < 0 || size_t(off) > s.size()) return false;
    return s.size() - size_t(off) >= p->s.size() && s.compare(size_t(off), p->s.size(), p->s) == 0;
}
bool String::endsWith(Ref<String> p) {
    return s.size() >= p->s.size() && s.compare(s.size() - p->s.size(), p->s.size(), p->s) == 0;
}
Ref<String> String::trim() {
    size_t b = 0, e = s.size();
    while (b < e && s[b] <= u' ') b++;
    while (e > b && s[e - 1] <= u' ') e--;
    if (b == 0 && e == s.size()) return Ref<String>(this);
    return of(s.substr(b, e - b));
}
Ref<String> String::toUpperCase() {
    std::u16string o = s;
    for (auto& c : o) c = Character::toUpperCase(c);
    return of(o);
}
Ref<String> String::toLowerCase() {
    std::u16string o = s;
    for (auto& c : o) c = Character::toLowerCase(c);
    return of(o);
}
Ref<String> String::replace(char16_t a, char16_t b) {
    std::u16string o = s;
    for (auto& c : o)
        if (c == a) c = b;
    return of(o);
}
Ref<String> String::concat(Ref<String> o) { return of(s + o->s); }
bool String::equalsIgnoreCase(Ref<String> o) {
    if (!o || o->s.size() != s.size()) return false;
    for (size_t i = 0; i < s.size(); i++)
        if (Character::toUpperCase(s[i]) != Character::toUpperCase(o->s[i])) return false;
    return true;
}
int32_t String::compareTo(Ref<String> o) {
    size_t n = std::min(s.size(), o->s.size());
    for (size_t i = 0; i < n; i++)
        if (s[i] != o->s[i]) return int32_t(s[i]) - int32_t(o->s[i]);
    return int32_t(s.size()) - int32_t(o->s.size());
}
Ref<Array<char16_t>> String::toCharArray() {
    auto a = jrt::newArray<char16_t>(int32_t(s.size()));
    for (size_t i = 0; i < s.size(); i++) a->data[i] = s[i];
    return a;
}
Ref<Array<int8_t>> String::getBytes() {
    std::string u = utf8();
    auto a = jrt::newArray<int8_t>(int32_t(u.size()));
    memcpy(a->data, u.data(), u.size());
    return a;
}
Ref<Array<int8_t>> String::getBytes(Ref<String> charset) {
    std::string cs = charset->utf8();
    for (auto& c : cs) c = char(tolower(c));
    if (cs == "utf-8" || cs == "utf8") return getBytes();
    auto a = jrt::newArray<int8_t>(int32_t(s.size()));
    for (size_t i = 0; i < s.size(); i++) a->data[i] = int8_t(s[i] < 256 ? s[i] : '?');
    return a;
}
void String::getChars(int32_t b, int32_t e, Ref<Array<char16_t>> dst, int32_t db) {
    if (b < 0 || e > int32_t(s.size()) || b > e) sioobe(b);
    for (int32_t i = b; i < e; i++) dst->at(db + i - b) = s[size_t(i)];
}
Ref<String> String::intern() { return jrt::intern(s.data(), s.size()); }
bool String::contains(Ref<String> o) { return s.find(o->s) != std::u16string::npos; }
bool String::equals(Ref<Object> o) {
    String* other = o ? dynamic_cast<String*>(o.get()) : nullptr;
    return other && other->s == s;
}
int32_t String::hashCode() {
    int32_t h = 0;
    for (char16_t c : s) h = 31 * h + int32_t(c);
    return h;
}
Ref<String> String::toString() { return Ref<String>(this); }

Ref<String> String::valueOf(int32_t v) { return jrt::concat(v); }
Ref<String> String::valueOf(int64_t v) { return jrt::concat(v); }
Ref<String> String::valueOf(float v) { return jrt::concat(v); }
Ref<String> String::valueOf(double v) { return jrt::concat(v); }
Ref<String> String::valueOf(bool v) { return jrt::concat(v); }
Ref<String> String::valueOf(char16_t v) { return of(std::u16string(1, v)); }
Ref<String> String::valueOf(Ref<Object> v) { return jrt::concat(v); }
Ref<String> String::valueOf(Ref<Array<char16_t>> v) { return of(std::u16string(v->data, size_t(v->length))); }

// ---------------------------------------------------------------------
// Class, Throwable
// ---------------------------------------------------------------------

Ref<Class> Class::forName(Ref<String> n) {
    Ref<Class> c(new Class());
    c->name = n->utf8();
    return c;
}
Ref<java::io::InputStream> Class::getResourceAsStream(Ref<String> n) { return jrt::getResourceAsStream(n); }
Ref<String> Class::getName() { return String::fromUtf8(name); }

Ref<String> Throwable::toString() {
    Ref<String> m = getMessage();
    std::string n = className();
    if (m) return jrt::concat(String::fromUtf8(n), JRT_LIT(u": "), m);
    return String::fromUtf8(n);
}

void Throwable::printStackTrace() {
    Ref<String> s = toString();
    fprintf(stderr, "%s\n", s->utf8().c_str());
}

// ---------------------------------------------------------------------
// StringBuffer
// ---------------------------------------------------------------------

void StringBuffer::__init(Ref<String> v) { s = v->s; }
Ref<StringBuffer> StringBuffer::append(Ref<Array<char16_t>> chars) {
    s.append(chars->data, size_t(chars->length));
    return Ref<StringBuffer>(this);
}
Ref<StringBuffer> StringBuffer::insert(int32_t off, Ref<String> v) {
    if (off < 0 || size_t(off) > s.size()) sioobe(off);
    s.insert(size_t(off), v ? v->s : u"null");
    return Ref<StringBuffer>(this);
}
Ref<StringBuffer> StringBuffer::insert(int32_t off, char16_t c) {
    if (off < 0 || size_t(off) > s.size()) sioobe(off);
    s.insert(s.begin() + off, c);
    return Ref<StringBuffer>(this);
}
Ref<StringBuffer> StringBuffer::deleteCharAt(int32_t i) {
    if (uint32_t(i) >= s.size()) sioobe(i);
    s.erase(size_t(i), 1);
    return Ref<StringBuffer>(this);
}
Ref<StringBuffer> StringBuffer::delete_(int32_t b, int32_t e) {
    if (e > int32_t(s.size())) e = int32_t(s.size());
    if (b < 0 || b > e) sioobe(b);
    s.erase(size_t(b), size_t(e - b));
    return Ref<StringBuffer>(this);
}
Ref<StringBuffer> StringBuffer::reverse() {
    std::reverse(s.begin(), s.end());
    return Ref<StringBuffer>(this);
}
char16_t StringBuffer::charAt(int32_t i) {
    if (uint32_t(i) >= s.size()) sioobe(i);
    return s[size_t(i)];
}
void StringBuffer::setCharAt(int32_t i, char16_t c) {
    if (uint32_t(i) >= s.size()) sioobe(i);
    s[size_t(i)] = c;
}
void StringBuffer::setLength(int32_t n) {
    if (n < 0) sioobe(n);
    s.resize(size_t(n), u'\0');
}

// ---------------------------------------------------------------------
// Numbers
// ---------------------------------------------------------------------

[[noreturn]] static void numberFormat(Ref<String> s) {
    Ref<NumberFormatException> e(new NumberFormatException());
    e->message = jrt::concat(JRT_LIT(u"For input string: \""), s, JRT_LIT(u"\""));
    jrt::throwJava(e);
}

static int64_t parseIntegral(Ref<String> str, int32_t radix, int64_t lo, int64_t hi) {
    if (!str) numberFormat(str);
    const std::u16string& s = str->s;
    if (s.empty()) numberFormat(str);
    size_t i = 0;
    bool neg = false;
    if (s[0] == u'-' || s[0] == u'+') {
        neg = s[0] == u'-';
        i = 1;
        if (s.size() == 1) numberFormat(str);
    }
    // accumulate negatively (like Java) so MIN_VALUE parses
    int64_t v = 0;
    for (; i < s.size(); i++) {
        int32_t d = Character::digit(s[i], radix);
        if (d < 0) numberFormat(str);
        if (v < (lo + d) / radix) numberFormat(str);
        v = v * radix - d;
        if (v < lo) numberFormat(str);
    }
    if (!neg) {
        if (v < -hi) numberFormat(str);
        v = -v;
    }
    return v;
}

Ref<Integer> Integer::valueOf(int32_t v) { return jrt::New<Integer>(v); }
Ref<Integer> Integer::valueOf(Ref<String> s) { return valueOf(parseInt(s)); }
int32_t Integer::parseInt(Ref<String> s) { return parseInt(s, 10); }
int32_t Integer::parseInt(Ref<String> s, int32_t radix) {
    return int32_t(parseIntegral(s, radix, MIN_VALUE, MAX_VALUE));
}
Ref<String> Integer::toString(int32_t v) { return jrt::concat(v); }
Ref<String> Integer::toString(int32_t v, int32_t radix) {
    if (radix < 2 || radix > 36) radix = 10;
    if (v == 0) return JRT_LIT(u"0");
    bool neg = v < 0;
    int64_t x = v;
    if (neg) x = -x;
    std::u16string o;
    while (x > 0) {
        int d = int(x % radix);
        o.insert(o.begin(), char16_t(d < 10 ? u'0' + d : u'a' + d - 10));
        x /= radix;
    }
    if (neg) o.insert(o.begin(), u'-');
    return String::of(o);
}
static Ref<String> unsignedString(uint32_t v, int shift) {
    if (v == 0) return JRT_LIT(u"0");
    std::u16string o;
    uint32_t mask = (1u << shift) - 1;
    while (v) {
        uint32_t d = v & mask;
        o.insert(o.begin(), char16_t(d < 10 ? u'0' + d : u'a' + d - 10));
        v >>= shift;
    }
    return String::of(o);
}
Ref<String> Integer::toHexString(int32_t v) { return unsignedString(uint32_t(v), 4); }
Ref<String> Integer::toBinaryString(int32_t v) { return unsignedString(uint32_t(v), 1); }
bool Integer::equals(Ref<Object> o) {
    Integer* i = o ? dynamic_cast<Integer*>(o.get()) : nullptr;
    return i && i->value == value;
}
Ref<String> Integer::toString() { return jrt::concat(value); }

Ref<Long> Long::valueOf(int64_t v) { return jrt::New<Long>(v); }
int64_t Long::parseLong(Ref<String> s) {
    return parseIntegral(s, 10, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
}
bool Long::equals(Ref<Object> o) {
    Long* i = o ? dynamic_cast<Long*>(o.get()) : nullptr;
    return i && i->value == value;
}
Ref<String> Long::toString() { return jrt::concat(value); }

Ref<Short> Short::valueOf(int16_t v) {
    Ref<Short> r(new Short());
    r->value = v;
    return r;
}
int16_t Short::parseShort(Ref<String> s) { return int16_t(parseIntegral(s, 10, -32768, 32767)); }

Ref<Byte> Byte::valueOf(int8_t v) {
    Ref<Byte> r(new Byte());
    r->value = v;
    return r;
}
int8_t Byte::parseByte(Ref<String> s) { return int8_t(parseIntegral(s, 10, -128, 127)); }

Ref<Float> Float::valueOf(float v) {
    Ref<Float> r(new Float());
    r->value = v;
    return r;
}
float Float::parseFloat(Ref<String> s) {
    std::string u = s->trim()->utf8();
    float v = 0;
    auto r = std::from_chars(u.data() + (!u.empty() && u[0] == '+' ? 1 : 0), u.data() + u.size(), v);
    if (r.ec != std::errc() || (r.ptr != u.data() + u.size() && !(r.ptr + 1 == u.data() + u.size() && (*r.ptr == 'f' || *r.ptr == 'F' || *r.ptr == 'd' || *r.ptr == 'D'))))
        numberFormat(s);
    return v;
}
int32_t Float::floatToIntBits(float v) {
    if (v != v) return 0x7fc00000;
    return floatToRawIntBits(v);
}
int32_t Float::floatToRawIntBits(float v) {
    int32_t i;
    memcpy(&i, &v, 4);
    return i;
}
float Float::intBitsToFloat(int32_t v) {
    float f;
    memcpy(&f, &v, 4);
    return f;
}
Ref<String> Float::toString() { return jrt::concat(value); }

Ref<Double> Double::valueOf(double v) {
    Ref<Double> r(new Double());
    r->value = v;
    return r;
}
double Double::parseDouble(Ref<String> s) {
    std::string u = s->trim()->utf8();
    double v = 0;
    auto r = std::from_chars(u.data() + (!u.empty() && u[0] == '+' ? 1 : 0), u.data() + u.size(), v);
    if (r.ec != std::errc()) numberFormat(s);
    return v;
}
int64_t Double::doubleToLongBits(double v) {
    if (v != v) return 0x7ff8000000000000LL;
    int64_t i;
    memcpy(&i, &v, 8);
    return i;
}
double Double::longBitsToDouble(int64_t v) {
    double d;
    memcpy(&d, &v, 8);
    return d;
}

Ref<Boolean> Boolean::valueOf(bool v) {
    Ref<Boolean> r(new Boolean());
    r->value = v;
    return r;
}

Ref<Character> Character::valueOf(char16_t v) {
    Ref<Character> r(new Character());
    r->value = v;
    return r;
}
bool Character::isDigit(char16_t c) { return c >= u'0' && c <= u'9'; }
bool Character::isLetter(char16_t c) {
    return (c >= u'a' && c <= u'z') || (c >= u'A' && c <= u'Z') || (c >= 0xC0 && c != 0xD7 && c != 0xF7 && c < 0x2000);
}
bool Character::isLetterOrDigit(char16_t c) { return isDigit(c) || isLetter(c); }
bool Character::isWhitespace(char16_t c) { return c == u' ' || (c >= 9 && c <= 13) || (c >= 0x1C && c <= 0x1F); }
bool Character::isUpperCase(char16_t c) { return toLowerCase(c) != c; }
bool Character::isLowerCase(char16_t c) { return toUpperCase(c) != c; }
char16_t Character::toUpperCase(char16_t c) {
    if (c >= u'a' && c <= u'z') return char16_t(c - 32);
    if (c >= 0xE0 && c <= 0xFE && c != 0xF7) return char16_t(c - 32);
    if (c >= 0x430 && c <= 0x44F) return char16_t(c - 32);    // Cyrillic
    if (c >= 0x450 && c <= 0x45F) return char16_t(c - 80);
    return c;
}
char16_t Character::toLowerCase(char16_t c) {
    if (c >= u'A' && c <= u'Z') return char16_t(c + 32);
    if (c >= 0xC0 && c <= 0xDE && c != 0xD7) return char16_t(c + 32);
    if (c >= 0x410 && c <= 0x42F) return char16_t(c + 32);
    if (c >= 0x400 && c <= 0x40F) return char16_t(c + 80);
    return c;
}
int32_t Character::digit(char16_t c, int32_t radix) {
    int32_t d = -1;
    if (c >= u'0' && c <= u'9') d = c - u'0';
    else if (c >= u'a' && c <= u'z') d = c - u'a' + 10;
    else if (c >= u'A' && c <= u'Z') d = c - u'A' + 10;
    return d < radix ? d : -1;
}

// ---------------------------------------------------------------------
// Math (Java's min/max NaN and signed-zero rules)
// ---------------------------------------------------------------------

float Math::min(float a, float b) {
    if (a != a) return a;
    if (a == 0 && b == 0) return std::signbit(a) ? a : b;
    return a <= b ? a : b;
}
double Math::min(double a, double b) {
    if (a != a) return a;
    if (a == 0 && b == 0) return std::signbit(a) ? a : b;
    return a <= b ? a : b;
}
float Math::max(float a, float b) {
    if (a != a) return a;
    if (a == 0 && b == 0) return std::signbit(a) ? b : a;
    return a >= b ? a : b;
}
double Math::max(double a, double b) {
    if (a != a) return a;
    if (a == 0 && b == 0) return std::signbit(a) ? b : a;
    return a >= b ? a : b;
}
double Math::sin(double v) { return std::sin(v); }
double Math::cos(double v) { return std::cos(v); }
double Math::tan(double v) { return std::tan(v); }
double Math::asin(double v) { return std::asin(v); }
double Math::acos(double v) { return std::acos(v); }
double Math::atan(double v) { return std::atan(v); }
double Math::atan2(double y, double x) { return std::atan2(y, x); }
double Math::pow(double a, double b) { return std::pow(a, b); }
double Math::exp(double v) { return std::exp(v); }
double Math::log(double v) { return std::log(v); }
int32_t Math::round(float v) {
    if (v != v) return 0;
    return jrt::f2i(std::floor(v + 0.5f));
}
int64_t Math::round(double v) {
    if (v != v) return 0;
    return jrt::f2l(std::floor(v + 0.5));
}
double Math::random() {
    static Ref<java::util::Random> r = jrt::New<java::util::Random>();
    return r->nextDouble();
}

// ---------------------------------------------------------------------
// Thread
// ---------------------------------------------------------------------

static thread_local Thread* tCurrent = nullptr;

Thread::~Thread() {
    if (native) {
        if (native->joinable()) native->detach();
        delete native;
    }
}

void Thread::run() {
    if (target) target->run();
}

void Thread::start() {
    bool expected = false;
    if (!started.compare_exchange_strong(expected, true)) {
        Ref<IllegalStateException> e(new IllegalStateException());
        jrt::throwJava(e);
    }
    alive = true;
    Ref<Thread> self(this);    // the thread keeps itself alive while it runs
    native = new std::thread([self]() {
        tCurrent = self.get();
        if (self->target && dynamic_cast<void*>(self->target.get()) == jrt::gSafePointRunnable.load()) {
            jrt::setSafePointThread();
        }
        try {
            self->run();
        } catch (const jrt::Thrown& t) {
            fprintf(stderr, "Exception in thread: ");
            t.t->printStackTrace();
        }
        self->alive = false;
    });
}

void Thread::join() {
    while (alive) std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
void Thread::join(int64_t millis) {
    auto end = std::chrono::steady_clock::now() + std::chrono::milliseconds(millis);
    while (alive && std::chrono::steady_clock::now() < end) std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

void (*gSleepHook)(int64_t) = nullptr;

void Thread::sleep(int64_t millis) {
    if (jrt::onSafePointThread()) jrt::collect();
    if (gSleepHook) {
        gSleepHook(millis);
        return;
    }
    if (millis > 0) std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}
void Thread::yield() { std::this_thread::yield(); }

Ref<Thread> Thread::currentThread() {
    if (!tCurrent) {
        // a thread not started from Java (the main or an event thread)
        tCurrent = new Thread();
        jrt::retain(tCurrent);
        tCurrent->alive = true;
    }
    return Ref<Thread>(tCurrent);
}

// ---------------------------------------------------------------------
// System, Runtime
// ---------------------------------------------------------------------

Ref<java::io::PrintStream> System::out;
Ref<java::io::PrintStream> System::err;

int64_t (*gClockHook)() = nullptr;

int64_t System::currentTimeMillis() {
    if (gClockHook) return gClockHook();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
        .count();
}
int64_t System::nanoTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch())
        .count();
}
void System::arraycopy(Ref<Object> src, int32_t sp, Ref<Object> dst, int32_t dp, int32_t len) {
    if (!src || !dst) throwNPE();
    auto* s = dynamic_cast<jrt::ArrayBase*>(src.get());
    auto* d = dynamic_cast<jrt::ArrayBase*>(dst.get());
    if (!s || !d) jrt::throwArrayStore();
    s->copyRange(sp, d, dp, len);
}
void System::exit(int32_t code) {
    fflush(stdout);
    fflush(stderr);
    _Exit(code);
}
Ref<String> System::getProperty(Ref<String> key) {
    std::string k = key->utf8();
    if (k == "microedition.platform") return JRT_LIT(u"Deep3D-PC");
    if (k == "microedition.profiles") return JRT_LIT(u"MIDP-2.0");
    if (k == "microedition.configuration") return JRT_LIT(u"CLDC-1.1");
    if (k == "microedition.m3g.version") return JRT_LIT(u"1.1");
    if (k == "microedition.locale") return JRT_LIT(u"en");
    return nullptr;
}
Ref<String> System::getenv(Ref<String> key) {
    const char* v = ::getenv(key->utf8().c_str());
    return v ? String::fromUtf8(v) : nullptr;
}
int32_t System::identityHashCode(Ref<Object> o) { return o ? o->Object::hashCode() : 0; }

Ref<Runtime> Runtime::getRuntime() {
    static Ref<Runtime> r(new Runtime());
    return r;
}

}  // namespace java::lang

// System.out / System.err exist before any static initialiser runs
namespace {
struct StdStreams {
    StdStreams() {
        using java::io::PrintStream;
        jrt::Ref<PrintStream> o(new PrintStream());
        o->f = stdout;
        jrt::Ref<PrintStream> e(new PrintStream());
        e->f = stderr;
        java::lang::System::out = o;
        java::lang::System::err = e;
    }
} gStdStreams;
}  // namespace
