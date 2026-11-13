// java.io and java.util.
#include "jrt_io.h"

#include <chrono>

namespace java::io {

using jrt::throwJava;

[[noreturn]] static void eof() {
    Ref<EOFException> e(new EOFException());
    throwJava(e);
}

static void checkRange(const Ref<Array<int8_t>>& b, int32_t off, int32_t len) {
    if (off < 0 || len < 0 || int64_t(off) + len > b->length) jrt::throwAIOOBE(off, b->length);
}

int32_t InputStream::read(Ref<Array<int8_t>> b) { return read(b, 0, b->length); }

int32_t InputStream::read(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    checkRange(b, off, len);
    if (len == 0) return 0;
    int32_t c = read();
    if (c < 0) return -1;
    b->data[off] = int8_t(c);
    int32_t i = 1;
    for (; i < len; i++) {
        c = read();
        if (c < 0) break;
        b->data[off + i] = int8_t(c);
    }
    return i;
}

int64_t InputStream::skip(int64_t n) {
    int64_t i = 0;
    for (; i < n; i++)
        if (read() < 0) break;
    return i;
}

void InputStream::reset() {
    Ref<IOException> e(new IOException());
    e->message = JRT_LIT(u"mark/reset not supported");
    throwJava(e);
}

void ByteArrayInputStream::__init(Ref<Array<int8_t>> b) { __init(b, 0, b->length); }
void ByteArrayInputStream::__init(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    buf = b;
    pos = off;
    count = std::min(off + len, b->length);
    markPos = off;
}
int32_t ByteArrayInputStream::read() { return pos < count ? uint8_t(buf->data[pos++]) : -1; }
int32_t ByteArrayInputStream::read(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    checkRange(b, off, len);
    if (pos >= count) return -1;
    int32_t n = std::min(len, count - pos);
    if (n <= 0) return 0;
    memcpy(b->data + off, buf->data + pos, size_t(n));
    pos += n;
    return n;
}
int64_t ByteArrayInputStream::skip(int64_t n) {
    int64_t k = std::min<int64_t>(n, count - pos);
    if (k < 0) k = 0;
    pos += int32_t(k);
    return k;
}

void DataInputStream::readFully(Ref<Array<int8_t>> b) { readFully(b, 0, b->length); }
void DataInputStream::readFully(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    checkRange(b, off, len);
    int32_t n = 0;
    while (n < len) {
        int32_t r = in->read(b, off + n, len - n);
        if (r < 0) eof();
        n += r;
    }
}
int32_t DataInputStream::skipBytes(int32_t n) {
    int32_t total = 0;
    while (total < n) {
        int64_t s = in->skip(n - total);
        if (s <= 0) break;
        total += int32_t(s);
    }
    return total;
}
static int32_t req(InputStream* in) {
    int32_t c = in->read();
    if (c < 0) eof();
    return c;
}
bool DataInputStream::readBoolean() { return req(in.get()) != 0; }
int8_t DataInputStream::readByte() { return int8_t(req(in.get())); }
int32_t DataInputStream::readUnsignedByte() { return req(in.get()); }
int16_t DataInputStream::readShort() {
    int32_t a = req(in.get());
    int32_t b = req(in.get());
    return int16_t((a << 8) | b);
}
int32_t DataInputStream::readUnsignedShort() {
    int32_t a = req(in.get());
    int32_t b = req(in.get());
    return (a << 8) | b;
}
char16_t DataInputStream::readChar() { return char16_t(readUnsignedShort()); }
int32_t DataInputStream::readInt() {
    uint32_t a = uint32_t(req(in.get()));
    uint32_t b = uint32_t(req(in.get()));
    uint32_t c = uint32_t(req(in.get()));
    uint32_t d = uint32_t(req(in.get()));
    return int32_t((a << 24) | (b << 16) | (c << 8) | d);
}
int64_t DataInputStream::readLong() {
    uint64_t hi = uint32_t(readInt());
    uint64_t lo = uint32_t(readInt());
    return int64_t((hi << 32) | lo);
}
float DataInputStream::readFloat() { return java::lang::Float::intBitsToFloat(readInt()); }
double DataInputStream::readDouble() { return java::lang::Double::longBitsToDouble(readLong()); }
Ref<String> DataInputStream::readUTF() {
    int32_t n = readUnsignedShort();
    auto bytes = jrt::newArray<int8_t>(n);
    readFully(bytes);
    // modified UTF-8, checked as java.io.DataInputStream does
    auto bad = [](const std::string& m) {
        Ref<UTFDataFormatException> e(new UTFDataFormatException());
        e->message = String::fromUtf8(m);
        throwJava(e);
    };
    std::u16string o;
    for (int32_t count = 0; count < n;) {
        uint32_t c = uint8_t(bytes->data[count]);
        switch (c >> 4) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                count++;
                o.push_back(char16_t(c));
                break;
            case 12: case 13: {
                count += 2;
                if (count > n) bad("malformed input: partial character at end");
                uint32_t c2 = uint8_t(bytes->data[count - 1]);
                if ((c2 & 0xC0) != 0x80) bad("malformed input around byte " + std::to_string(count));
                o.push_back(char16_t(((c & 0x1F) << 6) | (c2 & 0x3F)));
                break;
            }
            case 14: {
                count += 3;
                if (count > n) bad("malformed input: partial character at end");
                uint32_t c2 = uint8_t(bytes->data[count - 2]), c3 = uint8_t(bytes->data[count - 1]);
                if ((c2 & 0xC0) != 0x80 || (c3 & 0xC0) != 0x80) bad("malformed input around byte " + std::to_string(count - 1));
                o.push_back(char16_t(((c & 0x0F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F)));
                break;
            }
            default:
                bad("malformed input around byte " + std::to_string(count));
        }
    }
    return String::of(o);
}
Ref<String> DataInputStream::readUTF(Ref<DataInputStream> in) { return in->readUTF(); }

void OutputStream::write(Ref<Array<int8_t>> b) { write(b, 0, b->length); }
void OutputStream::write(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    checkRange(b, off, len);
    for (int32_t i = 0; i < len; i++) write(b->data[off + i]);
}

void ByteArrayOutputStream::write(Ref<Array<int8_t>> b, int32_t off, int32_t len) {
    checkRange(b, off, len);
    buf.insert(buf.end(), b->data + off, b->data + off + len);
}
Ref<Array<int8_t>> ByteArrayOutputStream::toByteArray() {
    auto a = jrt::newArray<int8_t>(int32_t(buf.size()));
    if (!buf.empty()) memcpy(a->data, buf.data(), buf.size());
    return a;
}

void DataOutputStream::writeShort(int32_t v) {
    write((v >> 8) & 0xFF);
    write(v & 0xFF);
}
void DataOutputStream::writeInt(int32_t v) {
    write(int32_t(uint32_t(v) >> 24) & 0xFF);
    write((v >> 16) & 0xFF);
    write((v >> 8) & 0xFF);
    write(v & 0xFF);
}
void DataOutputStream::writeLong(int64_t v) {
    writeInt(int32_t(uint64_t(v) >> 32));
    writeInt(int32_t(v));
}
void DataOutputStream::writeFloat(float v) { writeInt(java::lang::Float::floatToIntBits(v)); }
void DataOutputStream::writeDouble(double v) { writeLong(java::lang::Double::doubleToLongBits(v)); }
void DataOutputStream::writeUTF(Ref<String> s) {
    std::vector<uint8_t> o;
    for (char16_t c : s->s) {
        if (c >= 1 && c < 0x80) {
            o.push_back(uint8_t(c));
        } else if (c < 0x800) {
            o.push_back(uint8_t(0xC0 | (c >> 6)));
            o.push_back(uint8_t(0x80 | (c & 0x3F)));
        } else {
            o.push_back(uint8_t(0xE0 | (c >> 12)));
            o.push_back(uint8_t(0x80 | ((c >> 6) & 0x3F)));
            o.push_back(uint8_t(0x80 | (c & 0x3F)));
        }
    }
    if (o.size() > 65535) {
        Ref<UTFDataFormatException> e(new UTFDataFormatException());
        throwJava(e);
    }
    writeShort(int32_t(o.size()));
    for (uint8_t b : o) write(b);
}

static void out(FILE* f, const Ref<String>& s) {
    std::string u = s ? s->utf8() : "null";
    fwrite(u.data(), 1, u.size(), f);
}
void PrintStream::print(Ref<String> s) { out(f, s); }
void PrintStream::print(Ref<Object> o) { out(f, jrt::concat(o)); }
void PrintStream::print(int32_t v) { out(f, jrt::concat(v)); }
void PrintStream::print(int64_t v) { out(f, jrt::concat(v)); }
void PrintStream::print(char16_t v) { out(f, jrt::concat(v)); }
void PrintStream::print(bool v) { out(f, jrt::concat(v)); }
void PrintStream::print(float v) { out(f, jrt::concat(v)); }
void PrintStream::print(double v) { out(f, jrt::concat(v)); }
void PrintStream::println() {
    fputc('\n', f);
    fflush(f);
}
void PrintStream::println(Ref<String> s) { print(s), println(); }
void PrintStream::println(Ref<Object> o) { print(o), println(); }
void PrintStream::println(int32_t v) { print(v), println(); }
void PrintStream::println(int64_t v) { print(v), println(); }
void PrintStream::println(char16_t v) { print(v), println(); }
void PrintStream::println(bool v) { print(v), println(); }
void PrintStream::println(float v) { print(v), println(); }
void PrintStream::println(double v) { print(v), println(); }

}  // namespace java::io

namespace java::util {

using jrt::throwJava;

// ---------------------------------------------------------------------
// Random: java.util.Random's generator exactly
// ---------------------------------------------------------------------

static constexpr int64_t kMultiplier = 0x5DEECE66DLL;
static constexpr int64_t kMask = (int64_t(1) << 48) - 1;

int64_t (*gRandomSeedHook)() = nullptr;

void Random::__init() {
    // Java: a unique seed per Random; deterministic runs fix it
    static std::atomic<int64_t> uniquifier{8682522807148012LL};
    int64_t s;
    if (gRandomSeedHook) {
        s = gRandomSeedHook();
        setSeed(s);
        return;
    }
    int64_t u = uniquifier.load();
    int64_t next;
    do {
        next = u * 1181783497276652981LL;
    } while (!uniquifier.compare_exchange_weak(u, next));
    s = next ^ java::lang::System::nanoTime();
    setSeed(s);
}

void Random::setSeed(int64_t s) {
    seed = (s ^ kMultiplier) & kMask;
    haveNextNextGaussian = false;
}

int32_t Random::next(int32_t bits) {
    seed = (seed * kMultiplier + 0xBLL) & kMask;
    return int32_t(uint64_t(seed) >> (48 - bits));
}

int32_t Random::nextInt() { return next(32); }

int32_t Random::nextInt(int32_t bound) {
    if (bound <= 0) {
        Ref<java::lang::IllegalArgumentException> e(new java::lang::IllegalArgumentException());
        e->message = JRT_LIT(u"bound must be positive");
        throwJava(e);
    }
    int32_t r = next(31);
    int32_t m = bound - 1;
    if ((bound & m) == 0) {
        return int32_t((int64_t(bound) * int64_t(r)) >> 31);
    }
    for (int32_t u = r; int32_t(uint32_t(u) - uint32_t(r = u % bound) + uint32_t(m)) < 0; u = next(31)) {
    }
    return r;
}

int64_t Random::nextLong() { return int64_t(uint64_t(int64_t(next(32))) << 32) + next(32); }
bool Random::nextBoolean() { return next(1) != 0; }
float Random::nextFloat() { return float(next(24)) / float(1 << 24); }
double Random::nextDouble() {
    return double((int64_t(next(26)) << 27) + next(27)) * (1.0 / double(int64_t(1) << 53));
}
void Random::nextBytes(Ref<Array<int8_t>> b) {
    for (int32_t i = 0, len = b->length; i < len;)
        for (int32_t rnd = nextInt(), n = std::min(len - i, 4); n-- > 0; rnd >>= 8) b->data[i++] = int8_t(rnd);
}

// ---------------------------------------------------------------------
// Collections
// ---------------------------------------------------------------------

[[noreturn]] static void outOfRange(int32_t i, int32_t n) { jrt::throwAIOOBE(i, n); }

void Iterator::remove() {
    Ref<java::lang::UnsupportedOperationException> e(new java::lang::UnsupportedOperationException());
    throwJava(e);
}

namespace {
class VectorIterator : public Object, public Iterator, public Enumeration {
public:
    Ref<Vector> v;
    int32_t i = 0;
    bool hasNext() override { return i < v->size(); }
    Ref<Object> next() override {
        if (i >= v->size()) {
            Ref<NoSuchElementException> e(new NoSuchElementException());
            throwJava(e);
        }
        return v->items[size_t(i++)];
    }
    bool hasMoreElements() override { return hasNext(); }
    Ref<Object> nextElement() override { return next(); }
};

class ListEnumeration : public Object, public Enumeration {
public:
    std::vector<Ref<Object>> items;
    size_t i = 0;
    bool hasMoreElements() override { return i < items.size(); }
    Ref<Object> nextElement() override {
        if (i >= items.size()) {
            Ref<NoSuchElementException> e(new NoSuchElementException());
            throwJava(e);
        }
        return items[i++];
    }
};

bool sameKey(const Ref<Object>& a, const Ref<Object>& b) {
    if (!a || !b) return !a && !b;
    return a == b || a->equals(b);
}
}  // namespace

Ref<Iterator> Vector::iterator() {
    Ref<VectorIterator> it(new VectorIterator());
    it->v = Ref<Vector>(this);
    return it;
}
Ref<Enumeration> Vector::elements() {
    Ref<VectorIterator> it(new VectorIterator());
    it->v = Ref<Vector>(this);
    return it;
}
Ref<Object> Vector::elementAt(int32_t i) {
    if (uint32_t(i) >= items.size()) outOfRange(i, size());
    return items[size_t(i)];
}
Ref<Object> Vector::firstElement() {
    if (items.empty()) {
        Ref<NoSuchElementException> e(new NoSuchElementException());
        throwJava(e);
    }
    return items.front();
}
Ref<Object> Vector::lastElement() {
    if (items.empty()) {
        Ref<NoSuchElementException> e(new NoSuchElementException());
        throwJava(e);
    }
    return items.back();
}
void Vector::insertElementAt(Ref<Object> o, int32_t i) {
    if (i < 0 || size_t(i) > items.size()) outOfRange(i, size());
    items.insert(items.begin() + i, o);
}
void Vector::setElementAt(Ref<Object> o, int32_t i) {
    if (uint32_t(i) >= items.size()) outOfRange(i, size());
    items[size_t(i)] = o;
}
Ref<Object> Vector::set(int32_t i, Ref<Object> o) {
    if (uint32_t(i) >= items.size()) outOfRange(i, size());
    Ref<Object> old = items[size_t(i)];
    items[size_t(i)] = o;
    return old;
}
void Vector::removeElementAt(int32_t i) {
    if (uint32_t(i) >= items.size()) outOfRange(i, size());
    items.erase(items.begin() + i);
}
Ref<Object> Vector::remove(int32_t i) {
    if (uint32_t(i) >= items.size()) outOfRange(i, size());
    Ref<Object> old = items[size_t(i)];
    items.erase(items.begin() + i);
    return old;
}
bool Vector::removeElement(Ref<Object> o) {
    int32_t i = indexOf(o);
    if (i < 0) return false;
    items.erase(items.begin() + i);
    return true;
}
int32_t Vector::indexOf(Ref<Object> o) {
    for (size_t i = 0; i < items.size(); i++)
        if (sameKey(o, items[i])) return int32_t(i);
    return -1;
}
void Vector::copyInto(Ref<Array<Ref<Object>>> a) {
    for (size_t i = 0; i < items.size(); i++) a->at(int32_t(i)) = items[i];
}
Ref<Array<Ref<Object>>> Vector::toArray() {
    auto a = jrt::newArray<Ref<Object>>(size());
    copyInto(a);
    return a;
}

int32_t Hashtable::find(const Ref<Object>& key) {
    for (size_t i = 0; i < entries.size(); i++)
        if (sameKey(key, entries[i].first)) return int32_t(i);
    return -1;
}
Ref<Object> Hashtable::get(Ref<Object> key) {
    if (!key) jrt::throwNPE();
    int32_t i = find(key);
    return i < 0 ? nullptr : entries[size_t(i)].second;
}
Ref<Object> Hashtable::put(Ref<Object> key, Ref<Object> value) {
    if (!key || !value) jrt::throwNPE();
    int32_t i = find(key);
    if (i >= 0) {
        Ref<Object> old = entries[size_t(i)].second;
        entries[size_t(i)].second = value;
        return old;
    }
    entries.emplace_back(key, value);
    return nullptr;
}
Ref<Object> Hashtable::remove(Ref<Object> key) {
    if (!key) jrt::throwNPE();
    int32_t i = find(key);
    if (i < 0) return nullptr;
    Ref<Object> old = entries[size_t(i)].second;
    entries.erase(entries.begin() + i);
    return old;
}
bool Hashtable::containsKey(Ref<Object> key) {
    if (!key) jrt::throwNPE();
    return find(key) >= 0;
}

}  // namespace java::util

namespace jrt {

void Dumper::v(float x) {
    char b[16];
    snprintf(b, sizeof b, "f%x", uint32_t(java::lang::Float::floatToIntBits(x)));
    out += b;
}

void Dumper::v(double x) {
    char b[32];
    snprintf(b, sizeof b, "d%lx", (unsigned long)java::lang::Double::doubleToLongBits(x));
    out += b;
}

void Dumper::obj(java::lang::Object* o) {
    if (!o) {
        out += "null";
        return;
    }
    if (auto* s = dynamic_cast<java::lang::String*>(o)) {
        out += '"';
        out += s->utf8();
        out += '"';
        return;
    }
    if (auto* r = dynamic_cast<java::util::Random*>(o)) {
        char b[32];
        snprintf(b, sizeof b, "R%lx", (unsigned long)r->seed);
        out += b;
        return;
    }
    auto* a = dynamic_cast<ArrayBase*>(o);
    // class_33 is the loading screen: its own thread animates it
    if (!a && (!o->__dumpable() || !strcmp(o->__javaName(), "class_33") || (original && added(o->__javaName())))) {
        out += "<obj>";
        return;
    }
    auto it = ids.find(o);
    if (it != ids.end()) {
        out += '@';
        out += std::to_string(it->second);
        return;
    }
    int id = int(ids.size());
    ids[o] = id;
    out += '#';
    out += std::to_string(id);
    if (a) {
        out += '[';
        a->__dumpElems(*this);
        out += ']';
        return;
    }
    out += ' ';
    out += o->__javaName();
    out += '{';
    o->__dumpFields(*this);
    out += '}';
}

}  // namespace jrt
