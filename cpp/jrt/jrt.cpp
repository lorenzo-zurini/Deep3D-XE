// jrt: object lifetime, exceptions, monitors, java.lang.
#include "jrt.h"
#include "jrt_io.h"
#include "jrt_unicode.h"

#include <algorithm>
#include <chrono>
#include <charconv>
#include <condition_variable>
#include <cxxabi.h>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <unistd.h>

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

void throwArrayStore() { throwNew<java::lang::ArrayStoreException>(u""); }

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
        if (count > 0) {
            // blocked: the cycle collector may run meanwhile
            l.unlock();
            SafeRegion safe;
            l.lock();
            cv.wait(l, [&] { return count == 0; });
            owner = me;
            count = 1;
            l.unlock();   // before ~SafeRegion, which can wait for a collection
            return;
        }
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
        SafeRegion safe;
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
        l.unlock();   // before ~SafeRegion, which can wait for a collection
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

Object::~Object() {
    jrt::forgetObject(this);
    delete __monitor.load();
}

const char* Object::className() const {
    static thread_local std::string name;
    int st = 0;
    char* dn = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &st);
    name = dn ? dn : typeid(*this).name();
    free(dn);
    // Java's binary name: java::lang::Foo -> java.lang.Foo
    for (size_t i; (i = name.find("::")) != std::string::npos;) name.replace(i, 2, ".");
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

/* UTF-8 as Java decodes it: well-formed sequences per Unicode table 3-7,
   and each maximal ill-formed subpart becomes one U+FFFD. */
Ref<String> String::fromUtf8(const std::string& v) {
    std::u16string o;
    o.reserve(v.size());
    size_t n = v.size();
    auto at = [&](size_t i) { return uint32_t((unsigned char)v[i]); };
    for (size_t i = 0; i < n;) {
        uint32_t c = at(i);
        if (c < 0x80) {
            o.push_back(char16_t(c));
            i++;
            continue;
        }
        int need;
        uint32_t lo = 0x80, hi = 0xBF, cp;
        if (c >= 0xC2 && c <= 0xDF) { need = 1; cp = c & 0x1F; }
        else if (c >= 0xE0 && c <= 0xEF) {
            need = 2; cp = c & 0x0F;
            if (c == 0xE0) lo = 0xA0;
            if (c == 0xED) hi = 0x9F;
        } else if (c >= 0xF0 && c <= 0xF4) {
            need = 3; cp = c & 0x07;
            if (c == 0xF0) lo = 0x90;
            if (c == 0xF4) hi = 0x8F;
        } else {
            o.push_back(u'\xFFFD');
            i++;
            continue;
        }
        size_t k = i + 1;
        bool ok = true;
        for (int m = 0; m < need; m++, k++) {
            if (k >= n || at(k) < lo || at(k) > hi) {
                ok = false;
                break;
            }
            cp = (cp << 6) | (at(k) & 0x3F);
            lo = 0x80;
            hi = 0xBF;
        }
        if (!ok) {
            o.push_back(u'\xFFFD');
            i = k;
            continue;
        }
        if (cp >= 0x10000) {
            cp -= 0x10000;
            o.push_back(char16_t(0xD800 + (cp >> 10)));
            o.push_back(char16_t(0xDC00 + (cp & 0x3FF)));
        } else {
            o.push_back(char16_t(cp));
        }
        i = k;
    }
    return of(std::move(o));
}

std::string String::utf8() const {
    std::string o;
    for (size_t i = 0; i < s.size(); i++) {
        uint32_t c = s[i];
        if (c >= 0xD800 && c < 0xDC00 && i + 1 < s.size() && s[i + 1] >= 0xDC00 && s[i + 1] < 0xE000) {
            c = 0x10000 + ((c - 0xD800) << 10) + (s[i + 1] - 0xDC00);
            i++;
        } else if (c >= 0xD800 && c < 0xE000) {
            c = u'?';   // an unpaired surrogate, as Java's encoder writes it
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
    if (b == 0 && e == int32_t(s.size())) return Ref<String>(this);
    if (b == e) return JRT_LIT(u"");
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
    if (b == e) return JRT_LIT(u"");
    return of(s.substr(b, e - b));
}
Ref<String> String::toUpperCase() {
    std::u16string o = jrt::unicode::toUpperCase(s);
    return o == s ? Ref<String>(this) : of(o);
}
Ref<String> String::toLowerCase() {
    std::u16string o = jrt::unicode::toLowerCase(s);
    return o == s ? Ref<String>(this) : of(o);
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
    if (o.get() == this) return true;
    for (size_t i = 0; i < s.size(); i++) {
        char16_t a = s[i], b = o->s[i];
        if (a == b) continue;
        char16_t ua = Character::toUpperCase(a), ub = Character::toUpperCase(b);
        if (ua == ub) continue;
        if (Character::toLowerCase(ua) == Character::toLowerCase(ub)) continue;
        return false;
    }
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

/* NumberFormatException.forInputString (and parseInt's null message) */
[[noreturn]] static void numberFormat(Ref<String> s, int32_t radix = 10) {
    Ref<NumberFormatException> e(new NumberFormatException());
    if (!s) e->message = JRT_LIT(u"Cannot parse null string: null");
    else if (radix == 10) e->message = jrt::concat(JRT_LIT(u"For input string: \""), s, JRT_LIT(u"\""));
    else e->message = jrt::concat(JRT_LIT(u"For input string: \""), s, JRT_LIT(u"\" under radix "), radix);
    jrt::throwJava(e);
}

static int64_t parseIntegral(Ref<String> str, int32_t radix, int64_t lo, int64_t hi) {
    if (!str) numberFormat(str, radix);
    const std::u16string& s = str->s;
    if (s.empty()) numberFormat(str, radix);
    size_t i = 0;
    bool neg = false;
    if (s[0] == u'-' || s[0] == u'+') {
        neg = s[0] == u'-';
        i = 1;
        if (s.size() == 1) numberFormat(str, radix);
    }
    // accumulate negatively (like Java) so MIN_VALUE parses
    int64_t v = 0;
    for (; i < s.size(); i++) {
        int32_t d = Character::digit(s[i], radix);
        if (d < 0) numberFormat(str, radix);
        if (v < (lo + d) / radix) numberFormat(str, radix);
        v = v * radix - d;
        if (v < lo) numberFormat(str, radix);
    }
    if (!neg) {
        if (v < -hi) numberFormat(str, radix);
        v = -v;
    }
    return v;
}

// valueOf caches like Java's (-128..127; Character 0..127; Boolean TRUE/FALSE),
// so == on boxes compares as in Java. The caches live forever.
template <class T, class V>
Ref<T> cachedBox(V v, int lo, int hi) {
    static Ref<T>* cache = [lo, hi] {
        auto* c = new Ref<T>[size_t(hi - lo + 1)];
        for (int i = lo; i <= hi; i++) {
            c[i - lo] = Ref<T>(new T());
            c[i - lo]->value = V(i);
        }
        return c;
    }();
    if (int64_t(v) >= lo && int64_t(v) <= hi) return cache[int64_t(v) - lo];
    Ref<T> r(new T());
    r->value = v;
    return r;
}
Ref<Integer> Integer::valueOf(int32_t v) { return cachedBox<Integer>(v, -128, 127); }
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

Ref<Long> Long::valueOf(int64_t v) { return cachedBox<Long>(v, -128, 127); }
int64_t Long::parseLong(Ref<String> s) {
    return parseIntegral(s, 10, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
}
bool Long::equals(Ref<Object> o) {
    Long* i = o ? dynamic_cast<Long*>(o.get()) : nullptr;
    return i && i->value == value;
}
Ref<String> Long::toString() { return jrt::concat(value); }

Ref<Short> Short::valueOf(int16_t v) { return cachedBox<Short>(v, -128, 127); }
/* Short/Byte.parseX: Integer.parseInt, then the range check */
[[noreturn]] static void outOfRange(Ref<String> s) {
    Ref<NumberFormatException> e(new NumberFormatException());
    e->message = jrt::concat(JRT_LIT(u"Value out of range. Value:\""), s, JRT_LIT(u"\" Radix:10"));
    jrt::throwJava(e);
}
int16_t Short::parseShort(Ref<String> s) {
    int32_t v = Integer::parseInt(s, 10);
    if (v < -32768 || v > 32767) outOfRange(s);
    return int16_t(v);
}

Ref<Byte> Byte::valueOf(int8_t v) { return cachedBox<Byte>(v, -128, 127); }
int8_t Byte::parseByte(Ref<String> s) {
    int32_t v = Integer::parseInt(s, 10);
    if (v < -128 || v > 127) outOfRange(s);
    return int8_t(v);
}

Ref<Float> Float::valueOf(float v) {
    Ref<Float> r(new Float());
    r->value = v;
    return r;
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
Ref<String> Double::toString() { return jrt::concat(value); }
Ref<String> Short::toString() { return jrt::concat(int32_t(value)); }
Ref<String> Byte::toString() { return jrt::concat(int32_t(value)); }
Ref<String> Boolean::toString() { return value ? JRT_LIT(u"true") : JRT_LIT(u"false"); }
Ref<String> Character::toString() { return String::of(std::u16string(1, value)); }

Ref<Double> Double::valueOf(double v) {
    Ref<Double> r(new Double());
    r->value = v;
    return r;
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

Ref<Boolean> Boolean::valueOf(bool v) { return cachedBox<Boolean>(v, 0, 1); }

Ref<Character> Character::valueOf(char16_t v) { return cachedBox<Character>(v, 0, 127); }
bool Character::isDigit(char16_t c) { return jrt::unicode::isDigit(c); }
bool Character::isLetter(char16_t c) { return jrt::unicode::isLetter(c); }
bool Character::isLetterOrDigit(char16_t c) { return jrt::unicode::isLetterOrDigit(c); }
bool Character::isWhitespace(char16_t c) { return jrt::unicode::isWhitespace(c); }
bool Character::isUpperCase(char16_t c) { return jrt::unicode::isUpperCase(c); }
bool Character::isLowerCase(char16_t c) { return jrt::unicode::isLowerCase(c); }
char16_t Character::toUpperCase(char16_t c) { return jrt::unicode::toUpperCase(c); }
char16_t Character::toLowerCase(char16_t c) { return jrt::unicode::toLowerCase(c); }
int32_t Character::digit(char16_t c, int32_t radix) { return jrt::unicode::digit(c, radix); }

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
namespace {
int32_t hiWord(double x) { uint64_t b; memcpy(&b, &x, 8); return int32_t(b >> 32); }
uint32_t loWord(double x) { uint64_t b; memcpy(&b, &x, 8); return uint32_t(b); }

/* Math.tan is a HotSpot intrinsic whose last bit differs from glibc's for
   some inputs. The game only takes tan of k*PI/2048 and k*PI/4096 (field of
   view); for those the JDK's results (OpenJDK 27, x86-64) where glibc
   differs, |k| <= 8192: */
const uint64_t kTanFix[][2] = {
    {0x3FB2106CA4910069ULL, 0x3FB2181D6CE53175ULL},
    {0x3FCF839C24A97C8BULL, 0x3FD01555F41BC929ULL},
    {0x3FD69487CDB54084ULL, 0x3FD790F53CB492ADULL},
    {0x3FDC5F5CBA20F6E8ULL, 0x3FDE63D50272EF97ULL},
    {0x3FE1990B3AC0BC93ULL, 0x3FE39DCAF1F3EF5EULL},
    {0x3FE400CBC85142E4ULL, 0x3FE7179C6B64AFFBULL},
    {0x3FF3BBAE55298768ULL, 0x4006CC6E906C04BBULL},
    {0x3FF7C868147D83ACULL, 0x4027A62D8F0713F9ULL},
    {0x3FFA4C6EDCCCD6AFULL, 0xC02B665761659531ULL},
    {0x3FFE68DDD9357D90ULL, 0xC0075EEA99530047ULL},
    {0x40007CBACF977955ULL, 0xBFFDFD3C26CD692FULL},
    {0x4000CB4500FECE62ULL, 0xBFFB678E7733141FULL},
    {0x4001E6034C72CD5DULL, 0xBFF4573E0139EA1BULL},
    {0x40047376D301B9F2ULL, 0xBFE53464B32B57E5ULL},
    {0x40059F7C7B3FA7CCULL, 0xBFDE07A258AD0C95ULL},
    {0x40069F86ABAA1E57ULL, 0xBFD4C3265473AEDDULL},
    {0x40073C9B0E78C871ULL, 0xBFCEEAC359280E75ULL},
    {0x40081D3AC4B9E9C4ULL, 0xBFC062B9CB41C49DULL},
    {0x400860C6182C60FDULL, 0xBFB8390FCF0758CDULL},
    {0x4008625837E1A540ULL, 0xBFB8065993B3D341ULL},
    {0x4009EFC18E061B49ULL, 0x3FB9CF06D28556F1ULL},
    {0x400A042D2A3A92AEULL, 0x3FBC63CE377FC7FDULL},
    {0x400A1BBD05D99298ULL, 0x3FBF6011BF2C58ABULL},
    {0x400D26DA750DD40EULL, 0x3FE194A51D926815ULL},
    {0x400D7888E5DFB1A1ULL, 0x3FE347C0A91C254DULL},
    {0x400DA93ABCD2F5B8ULL, 0x3FE455263CC2146BULL},
    {0x400DB4399AC7D38CULL, 0x3FE49319B2C728A6ULL},
    {0x400E464F1FA19FD2ULL, 0x3FE7F63CB6322609ULL},
    {0x400EA620ADD2E3BEULL, 0x3FEA629AFA3EDEB5ULL},
    {0x400EBC1E69BC9F65ULL, 0x3FEAF7B30E714A78ULL},
    {0x400F04601C4EE367ULL, 0x3FECF55BFE9493B5ULL},
    {0x4011CCE1511E8930ULL, 0x400DCBA315B30F4DULL},
    {0x401287CE0E61443FULL, 0x4029051334B8220DULL},
    {0x40155D83478274D6ULL, 0xBFF5FE6459C4F827ULL},
    {0x40156626F5E76C45ULL, 0xBFF59BADCF33CB5EULL},
    {0x401567B9159CB088ULL, 0xBFF589F9035D333DULL},
    {0x40174D195B68152FULL, 0xBFDF8A7CE35C8721ULL},
    {0x401A0C07C8C4E7FCULL, 0x3FCDC6C31310B573ULL},
    {0x401AECA77F06094FULL, 0x3FDEC06F0D71F237ULL},
    {0x401B9196805F08B7ULL, 0x3FE6513DACA07251ULL},
    {0x401D7BAD254A3A26ULL, 0x3FFE7E83AFF0C9C9ULL},
    {0x40204C08F8A4353EULL, 0xC00A5F59E90600D1ULL},
    {0x4020A4C8F825C5FDULL, 0xBFFFAA5DF8E6A273ULL},
    {0x4022B6EDC59F4414ULL, 0xBFB14E177C05800FULL},
    {0x4022D97C7F3321D2ULL, 0xBCBA79394C9E8A0AULL},
    {0x4025D4E4B152B8ACULL, 0x4029051334B82247ULL},
    {0x4025FDBBE9BBA775ULL, 0x432093C3B4AEBEB1ULL},
    {0x40271231B65A9565ULL, 0xBFFAB1C35D8A74F3ULL},
    {0x4027ACEAE999591BULL, 0xBFEC8F234A479A10ULL},
    {0x4028486D2CB2BEF2ULL, 0xBFDCF56611D47235ULL},
    {0x4028EC931E311C38ULL, 0xBFBACD0207170511ULL},
    {0xBFB2106CA4910069ULL, 0xBFB2181D6CE53175ULL},
    {0xBFCF839C24A97C8BULL, 0xBFD01555F41BC929ULL},
    {0xBFD69487CDB54084ULL, 0xBFD790F53CB492ADULL},
    {0xBFDC5F5CBA20F6E8ULL, 0xBFDE63D50272EF97ULL},
    {0xBFE1990B3AC0BC93ULL, 0xBFE39DCAF1F3EF5EULL},
    {0xBFE400CBC85142E4ULL, 0xBFE7179C6B64AFFBULL},
    {0xBFF3BBAE55298768ULL, 0xC006CC6E906C04BBULL},
    {0xBFF7C868147D83ACULL, 0xC027A62D8F0713F9ULL},
    {0xBFFA4C6EDCCCD6AFULL, 0x402B665761659531ULL},
    {0xBFFE68DDD9357D90ULL, 0x40075EEA99530047ULL},
    {0xC0007CBACF977955ULL, 0x3FFDFD3C26CD692FULL},
    {0xC000CB4500FECE62ULL, 0x3FFB678E7733141FULL},
    {0xC001E6034C72CD5DULL, 0x3FF4573E0139EA1BULL},
    {0xC0047376D301B9F2ULL, 0x3FE53464B32B57E5ULL},
    {0xC0059F7C7B3FA7CCULL, 0x3FDE07A258AD0C95ULL},
    {0xC0069F86ABAA1E57ULL, 0x3FD4C3265473AEDDULL},
    {0xC0073C9B0E78C871ULL, 0x3FCEEAC359280E75ULL},
    {0xC0081D3AC4B9E9C4ULL, 0x3FC062B9CB41C49DULL},
    {0xC00860C6182C60FDULL, 0x3FB8390FCF0758CDULL},
    {0xC008625837E1A540ULL, 0x3FB8065993B3D341ULL},
    {0xC009EFC18E061B49ULL, 0xBFB9CF06D28556F1ULL},
    {0xC00A042D2A3A92AEULL, 0xBFBC63CE377FC7FDULL},
    {0xC00A1BBD05D99298ULL, 0xBFBF6011BF2C58ABULL},
    {0xC00D26DA750DD40EULL, 0xBFE194A51D926815ULL},
    {0xC00D7888E5DFB1A1ULL, 0xBFE347C0A91C254DULL},
    {0xC00DA93ABCD2F5B8ULL, 0xBFE455263CC2146BULL},
    {0xC00DB4399AC7D38CULL, 0xBFE49319B2C728A6ULL},
    {0xC00E464F1FA19FD2ULL, 0xBFE7F63CB6322609ULL},
    {0xC00EA620ADD2E3BEULL, 0xBFEA629AFA3EDEB5ULL},
    {0xC00EBC1E69BC9F65ULL, 0xBFEAF7B30E714A78ULL},
    {0xC00F04601C4EE367ULL, 0xBFECF55BFE9493B5ULL},
    {0xC011CCE1511E8930ULL, 0xC00DCBA315B30F4DULL},
    {0xC01287CE0E61443FULL, 0xC029051334B8220DULL},
    {0xC0155D83478274D6ULL, 0x3FF5FE6459C4F827ULL},
    {0xC0156626F5E76C45ULL, 0x3FF59BADCF33CB5EULL},
    {0xC01567B9159CB088ULL, 0x3FF589F9035D333DULL},
    {0xC0174D195B68152FULL, 0x3FDF8A7CE35C8721ULL},
    {0xC01A0C07C8C4E7FCULL, 0xBFCDC6C31310B573ULL},
    {0xC01AECA77F06094FULL, 0xBFDEC06F0D71F237ULL},
    {0xC01B9196805F08B7ULL, 0xBFE6513DACA07251ULL},
    {0xC01D7BAD254A3A26ULL, 0xBFFE7E83AFF0C9C9ULL},
    {0xC0204C08F8A4353EULL, 0x400A5F59E90600D1ULL},
    {0xC020A4C8F825C5FDULL, 0x3FFFAA5DF8E6A273ULL},
    {0xC022B6EDC59F4414ULL, 0x3FB14E177C05800FULL},
    {0xC022D97C7F3321D2ULL, 0x3CBA79394C9E8A0AULL},
    {0xC025D4E4B152B8ACULL, 0xC029051334B82247ULL},
    {0xC025FDBBE9BBA775ULL, 0xC32093C3B4AEBEB1ULL},
    {0xC0271231B65A9565ULL, 0x3FFAB1C35D8A74F3ULL},
    {0xC027ACEAE999591BULL, 0x3FEC8F234A479A10ULL},
    {0xC028486D2CB2BEF2ULL, 0x3FDCF56611D47235ULL},
    {0xC028EC931E311C38ULL, 0x3FBACD0207170511ULL},
};
}  // namespace

double Math::tan(double v) {
    uint64_t bits;
    memcpy(&bits, &v, 8);
    size_t lo = 0, hi = sizeof(kTanFix) / sizeof(kTanFix[0]);
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (bits < kTanFix[mid][0]) hi = mid;
        else if (bits > kTanFix[mid][0]) lo = mid + 1;
        else {
            double r;
            memcpy(&r, &kTanFix[mid][1], 8);
            return r;
        }
    }
    return std::tan(v);
}

// fdlibm's s_atan.c, which Java's Math.atan is (StrictMath.atan)
double Math::atan(double x) {
    static const double atanhi[] = {4.63647609000806093515e-01, 7.85398163397448278999e-01,
                                    9.82793723247329054082e-01, 1.57079632679489655800e+00};
    static const double atanlo[] = {2.26987774529616870924e-17, 3.06161699786838301793e-17,
                                    1.39033110312309984516e-17, 6.12323399573676603587e-17};
    static const double aT[] = {3.33333333333329318027e-01, -1.99999999998764832476e-01,
                                1.42857142725034663711e-01, -1.11111104054623557880e-01,
                                9.09088713343650656196e-02, -7.69187620504482999495e-02,
                                6.66107313738753120669e-02, -5.83357013379057348645e-02,
                                4.97687799461593236017e-02, -3.65315727442169155270e-02,
                                1.62858201153657823623e-02};
    const double one = 1.0, huge = 1.0e300;
    int32_t hx = hiWord(x), ix = hx & 0x7fffffff, id;
    if (ix >= 0x44100000) {
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && loWord(x) != 0)) return x + x;
        return hx > 0 ? atanhi[3] + atanlo[3] : -atanhi[3] - atanlo[3];
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000 && huge + x > one) return x;
        id = -1;
    } else {
        x = std::fabs(x);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) { id = 0; x = (2.0 * x - one) / (2.0 + x); }
            else { id = 1; x = (x - one) / (x + one); }
        } else {
            if (ix < 0x40038000) { id = 2; x = (x - 1.5) / (one + 1.5 * x); }
            else { id = 3; x = -1.0 / x; }
        }
    }
    double z = x * x, w = z * z;
    double s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    double s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0) return x - x * (s1 + s2);
    z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
    return hx < 0 ? -z : z;
}

// Java's exact Math.round (not floor(x + 0.5))
int32_t Math::round(float a) {
    int32_t bits;
    memcpy(&bits, &a, 4);
    int32_t shift = (24 - 2 + 127) - ((bits & 0x7F800000) >> 23);
    if ((shift & -32) == 0) {
        int32_t r = (bits & 0x007FFFFF) | 0x00800000;
        if (bits < 0) r = -r;
        return ((r >> shift) + 1) >> 1;
    }
    return jrt::f2i(a);
}
int64_t Math::round(double a) {
    int64_t bits;
    memcpy(&bits, &a, 8);
    int64_t shift = (53 - 2 + 1023) - ((bits & 0x7FF0000000000000LL) >> 52);
    if ((shift & -64) == 0) {
        int64_t r = (bits & 0x000FFFFFFFFFFFFFLL) | 0x0010000000000000LL;
        if (bits < 0) r = -r;
        return ((r >> shift) + 1) >> 1;
    }
    return jrt::f2l(a);
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
            jrt::MutatorScope running;
            self->run();
        } catch (const jrt::Thrown& t) {
            // the Java build's default handler (Diagnostics)
            fprintf(stderr, "[diag] uncaught exception in %s\n", self->getName()->utf8().c_str());
            t.t->printStackTrace();
        }
        self->alive = false;
    });
}

void Thread::join() {
    jrt::SafeRegion safe;
    while (alive) std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
void Thread::join(int64_t millis) {
    jrt::SafeRegion safe;
    auto end = std::chrono::steady_clock::now() + std::chrono::milliseconds(millis);
    while (alive && std::chrono::steady_clock::now() < end) std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

void (*gSleepHook)(int64_t) = nullptr;

void Thread::sleep(int64_t millis) {
    if (jrt::onSafePointThread()) {
        jrt::collect();
        jrt::maybeCollectCycles();
    }
    jrt::SafeRegion safe;
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
        tCurrent->name = gettid() == getpid() ? JRT_LIT(u"main")
                                               : String::fromUtf8("native-" + std::to_string(gettid()));
    }
    return Ref<Thread>(tCurrent);
}

Ref<String> Thread::nextName() {
    static std::atomic<int32_t> n{0};
    return jrt::concat(JRT_LIT(u"Thread-"), int32_t(n++));
}

Ref<String> Thread::getName() { return name ? name : JRT_LIT(u"Thread-?"); }

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
/* The Java build ran on a desktop JDK, which has none of the phone's
   properties (microedition.*, supports.*): the game gets null for all. */
Ref<String> System::getProperty(Ref<String> key) {
    if (!key) jrt::throwNPE();
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
