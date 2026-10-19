// java.io and java.util for the translated code.
#pragma once
#include "jrt.h"

#include <cstdio>
#include <vector>

namespace java::io {

using jrt::Array;
using jrt::Ref;
using java::lang::Object;
using java::lang::String;

JRT_EXCEPTION(IOException, java::lang::Exception)
JRT_EXCEPTION(EOFException, IOException)
JRT_EXCEPTION(UTFDataFormatException, IOException)

class InputStream : public Object {
public:
    void __init() {}
    virtual int32_t read() = 0;
    virtual int32_t read(Ref<Array<int8_t>> b);
    virtual int32_t read(Ref<Array<int8_t>> b, int32_t off, int32_t len);
    virtual int64_t skip(int64_t n);
    virtual int32_t available() { return 0; }
    virtual void close() {}
    virtual void mark(int32_t) {}
    virtual void reset();
    virtual bool markSupported() { return false; }
};

class ByteArrayInputStream : public InputStream {
public:
    Ref<Array<int8_t>> buf;
    int32_t pos = 0;
    int32_t count = 0;
    int32_t markPos = 0;
    void __init(Ref<Array<int8_t>> b);
    void __init(Ref<Array<int8_t>> b, int32_t off, int32_t len);
    int32_t read() override;
    int32_t read(Ref<Array<int8_t>> b, int32_t off, int32_t len) override;
    using InputStream::read;
    int64_t skip(int64_t n) override;
    int32_t available() override { return count - pos; }
    void mark(int32_t) override { markPos = pos; }
    void reset() override { pos = markPos; }
    bool markSupported() override { return true; }
};

/** Reads big-endian primitives, as java.io.DataInputStream. */
class DataInputStream : public InputStream {
public:
    Ref<InputStream> in;
    void __init(Ref<InputStream> i) { in = i; }
    int32_t read() override { return in->read(); }
    int32_t read(Ref<Array<int8_t>> b, int32_t off, int32_t len) override { return in->read(b, off, len); }
    using InputStream::read;
    int64_t skip(int64_t n) override { return in->skip(n); }
    int32_t available() override { return in->available(); }
    void close() override { in->close(); }
    void mark(int32_t l) override { in->mark(l); }
    void reset() override { in->reset(); }
    bool markSupported() override { return in->markSupported(); }

    void readFully(Ref<Array<int8_t>> b);
    void readFully(Ref<Array<int8_t>> b, int32_t off, int32_t len);
    int32_t skipBytes(int32_t n);
    bool readBoolean();
    int8_t readByte();
    int32_t readUnsignedByte();
    int16_t readShort();
    int32_t readUnsignedShort();
    char16_t readChar();
    int32_t readInt();
    int64_t readLong();
    float readFloat();
    double readDouble();
    Ref<String> readUTF();
    static Ref<String> readUTF(Ref<DataInputStream> in);
};

class OutputStream : public Object {
public:
    void __init() {}
    virtual void write(int32_t b) = 0;
    virtual void write(Ref<Array<int8_t>> b);
    virtual void write(Ref<Array<int8_t>> b, int32_t off, int32_t len);
    virtual void flush() {}
    virtual void close() {}
};

class ByteArrayOutputStream : public OutputStream {
public:
    std::vector<int8_t> buf;
    void __init() {}
    void __init(int32_t size) { buf.reserve(size_t(size > 0 ? size : 0)); }
    void write(int32_t b) override { buf.push_back(int8_t(b)); }
    void write(Ref<Array<int8_t>> b, int32_t off, int32_t len) override;
    using OutputStream::write;
    Ref<Array<int8_t>> toByteArray();
    int32_t size() { return int32_t(buf.size()); }
    void reset() { buf.clear(); }
};

class DataOutputStream : public OutputStream {
public:
    Ref<OutputStream> out;
    int32_t written = 0;
    void __init(Ref<OutputStream> o) { out = o; }
    void write(int32_t b) override {
        out->write(b);
        written++;
    }
    void write(Ref<Array<int8_t>> b, int32_t off, int32_t len) override {
        out->write(b, off, len);
        written += len;
    }
    using OutputStream::write;
    void flush() override { out->flush(); }
    void close() override { out->close(); }
    void writeBoolean(bool v) { write(v ? 1 : 0); }
    void writeByte(int32_t v) { write(v); }
    void writeShort(int32_t v);
    void writeChar(int32_t v) { writeShort(v); }
    void writeInt(int32_t v);
    void writeLong(int64_t v);
    void writeFloat(float v);
    void writeDouble(double v);
    void writeUTF(Ref<String> s);
    int32_t size() { return written; }
};

/** System.out / System.err. */
class PrintStream : public OutputStream {
public:
    FILE* f = nullptr;
    void write(int32_t b) override { fputc(b, f); }
    void flush() override { fflush(f); }
    void print(Ref<String> s);
    void print(Ref<Object> o);
    void print(int32_t v);
    void print(int64_t v);
    void print(char16_t v);
    void print(bool v);
    void print(float v);
    void print(double v);
    void println();
    void println(Ref<String> s);
    void println(Ref<Object> o);
    void println(int32_t v);
    void println(int64_t v);
    void println(char16_t v);
    void println(bool v);
    void println(float v);
    void println(double v);
};

}  // namespace java::io

namespace java::util {

using jrt::Array;
using jrt::Ref;
using java::lang::Object;
using java::lang::String;

JRT_EXCEPTION(NoSuchElementException, java::lang::RuntimeException)

/** java.util.Random: the same 48-bit generator, bit for bit. */
class Random : public Object {
public:
    int64_t seed = 0;
    double nextNextGaussian = 0;
    bool haveNextNextGaussian = false;

    void __init();
    void __init(int64_t s) { setSeed(s); }
    void setSeed(int64_t s);
    int32_t next(int32_t bits);
    int32_t nextInt();
    int32_t nextInt(int32_t bound);
    int64_t nextLong();
    bool nextBoolean();
    float nextFloat();
    double nextDouble();
    void nextBytes(Ref<Array<int8_t>> b);
};

class Enumeration {
public:
    virtual ~Enumeration() = default;
    virtual bool hasMoreElements() = 0;
    virtual Ref<Object> nextElement() = 0;
};

class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual Ref<Object> next() = 0;
    virtual void remove();
};

class Collection {
public:
    virtual ~Collection() = default;
    virtual int32_t size() = 0;
    virtual Ref<Iterator> iterator() = 0;
    bool isEmpty() { return size() == 0; }
};

/** Vector / ArrayList / List: one growable array of references. */
class Vector : public Object, public Collection {
public:
    std::vector<Ref<Object>> items;
    void __init() {}
    void __init(int32_t capacity) { items.reserve(size_t(capacity > 0 ? capacity : 0)); }
    int32_t size() override { return int32_t(items.size()); }
    Ref<Iterator> iterator() override;
    Ref<Object> elementAt(int32_t i);
    Ref<Object> get(int32_t i) { return elementAt(i); }
    Ref<Object> firstElement();
    Ref<Object> lastElement();
    void addElement(Ref<Object> o) { items.push_back(o); }
    bool add(Ref<Object> o) {
        items.push_back(o);
        return true;
    }
    void add(int32_t i, Ref<Object> o) { insertElementAt(o, i); }
    void insertElementAt(Ref<Object> o, int32_t i);
    void setElementAt(Ref<Object> o, int32_t i);
    Ref<Object> set(int32_t i, Ref<Object> o);
    void removeElementAt(int32_t i);
    Ref<Object> remove(int32_t i);
    bool removeElement(Ref<Object> o);
    void removeAllElements() { items.clear(); }
    void setSize(int32_t n) { items.resize(size_t(n > 0 ? n : 0)); }
    void clear() { items.clear(); }
    bool contains(Ref<Object> o) { return indexOf(o) >= 0; }
    int32_t indexOf(Ref<Object> o);
    Ref<Enumeration> elements();
    void copyInto(Ref<Array<Ref<Object>>> a);
    Ref<Array<Ref<Object>>> toArray();
    void __gcTrace(jrt::Tracer& t) override { t.all(items); }
};
using List = Vector;
using ArrayList = Vector;
using AbstractList = Vector;

/** Hashtable with Java's equals keys and null rules. No iteration: Java's
    order (by hash buckets) is not reproduced, and nothing iterates one. */
class Hashtable : public Object {
public:
    std::vector<std::pair<Ref<Object>, Ref<Object>>> entries;
    void __init() {}
    void __init(int32_t) {}
    int32_t size() { return int32_t(entries.size()); }
    bool isEmpty() { return entries.empty(); }
    Ref<Object> get(Ref<Object> key);
    Ref<Object> put(Ref<Object> key, Ref<Object> value);
    Ref<Object> remove(Ref<Object> key);
    bool containsKey(Ref<Object> key);
    void clear() { entries.clear(); }
    void __gcTrace(jrt::Tracer& t) override {
        for (auto& [k, v] : entries) {
            t(k);
            t(v);
        }
    }

private:
    int32_t find(const Ref<Object>& key);
};

}  // namespace java::util
