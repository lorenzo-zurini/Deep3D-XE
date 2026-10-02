// javax.microedition.midlet and rms: the MIDlet base and record stores
// (the save games: one file per store, the Java build's format).
#include "midp.h"
#include "deep3d/deep3d.h"

#include <cstdio>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

namespace javax::microedition::midlet {

void MIDlet::notifyDestroyed() { org::deep3d::Runtime::shutdown(); }

Ref<String> MIDlet::getAppProperty(Ref<String> key) {
    auto v = org::deep3d::Runtime::getAppProperty(key->utf8());
    return v ? String::fromUtf8(*v) : nullptr;
}

}  // namespace javax::microedition::midlet

namespace javax::microedition::rms {

namespace {

std::string saveDir() {
    const char* env = getenv("DEEP3D_SAVE_DIR");
    if (env && *env) {
        mkdir(env, 0755);
        return env;
    }
    return org::deep3d::AppDirs::dir("saves");
}

std::string sanitize(const std::string& name) {
    std::string out = name;
    for (char& c : out) {
        bool ok = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_' ||
                  c == '.' || c == '-';
        if (!ok) c = '_';
    }
    return out;
}

template <class E>
[[noreturn]] void fail(const std::string& msg) {
    Ref<E> e(new E());
    e->message = String::fromUtf8(msg);
    jrt::throwJava(e);
}

int32_t readInt(FILE* f, bool& ok) {
    uint8_t b[4];
    if (fread(b, 1, 4, f) != 4) {
        ok = false;
        return 0;
    }
    return int32_t(uint32_t(b[0]) << 24 | uint32_t(b[1]) << 16 | uint32_t(b[2]) << 8 | b[3]);
}

void writeInt(FILE* f, int32_t v) {
    uint8_t b[4] = {uint8_t(uint32_t(v) >> 24), uint8_t(v >> 16), uint8_t(v >> 8), uint8_t(v)};
    fwrite(b, 1, 4, f);
}

}  // namespace

Ref<RecordStore> RecordStore::openRecordStore(Ref<String> name, bool createIfNecessary) {
    Ref<RecordStore> rs(new RecordStore());
    rs->name = name->utf8();
    rs->path = saveDir() + "/" + sanitize(rs->name) + ".rms";
    if (access(rs->path.c_str(), F_OK) == 0) {
        rs->load();
    } else if (!createIfNecessary) {
        fail<RecordStoreNotFoundException>(rs->name);
    }
    rs->open = true;
    return rs;
}

void RecordStore::deleteRecordStore(Ref<String> name) {
    std::string p = saveDir() + "/" + sanitize(name->utf8()) + ".rms";
    if (access(p.c_str(), F_OK) != 0) fail<RecordStoreNotFoundException>(name->utf8());
    if (unlink(p.c_str()) != 0) fail<RecordStoreException>("cannot delete " + name->utf8());
}

Ref<Array<Ref<String>>> RecordStore::listRecordStores() {
    std::vector<std::string> names;
    if (DIR* d = opendir(saveDir().c_str())) {
        while (dirent* e = readdir(d)) {
            std::string n = e->d_name;
            if (n.size() > 4 && n.compare(n.size() - 4, 4, ".rms") == 0) names.push_back(n.substr(0, n.size() - 4));
        }
        closedir(d);
    }
    if (names.empty()) return nullptr;
    auto out = jrt::newArray<Ref<String>>(int32_t(names.size()));
    for (size_t i = 0; i < names.size(); i++) out->data[i] = String::fromUtf8(names[i]);
    return out;
}

void RecordStore::load() {
    records.clear();
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) fail<RecordStoreException>("cannot read " + name);
    bool ok = true;
    int32_t count = readInt(f, ok);
    for (int32_t i = 0; ok && i < count; i++) {
        int32_t len = readInt(f, ok);
        if (!ok) break;
        if (len < 0) {
            records.push_back(nullptr);
        } else {
            auto data = jrt::newArray<int8_t>(len);
            if (len > 0 && fread(data->data, 1, size_t(len), f) != size_t(len)) ok = false;
            records.push_back(data);
        }
    }
    fclose(f);
    if (!ok) fail<RecordStoreException>("cannot read " + name + ": truncated");
}

void RecordStore::save() {
    std::string tmp = path + ".tmp";
    FILE* f = fopen(tmp.c_str(), "wb");
    if (!f) fail<RecordStoreException>("cannot write " + name);
    writeInt(f, int32_t(records.size()));
    for (auto& r : records) {
        if (!r) {
            writeInt(f, -1);
        } else {
            writeInt(f, r->length);
            if (r->length > 0) fwrite(r->data, 1, size_t(r->length), f);
        }
    }
    bool ok = fflush(f) == 0;
    fclose(f);
    if (!ok || rename(tmp.c_str(), path.c_str()) != 0) fail<RecordStoreException>("cannot write " + name);
}

void RecordStore::checkOpen() {
    if (!open) fail<RecordStoreNotOpenException>(name);
}

void RecordStore::checkId(int32_t id) {
    if (id < 1 || id > int32_t(records.size()) || !records[size_t(id - 1)]) {
        fail<InvalidRecordIDException>("record " + std::to_string(id) + " in " + name);
    }
}

void RecordStore::closeRecordStore() {
    checkOpen();
    open = false;
}

Ref<String> RecordStore::getName() { return String::fromUtf8(name); }

int32_t RecordStore::addRecord(Ref<Array<int8_t>> data, int32_t offset, int32_t numBytes) {
    checkOpen();
    auto copy = jrt::newArray<int8_t>(numBytes);
    if (numBytes > 0) java::lang::System::arraycopy(data, offset, copy, 0, numBytes);
    records.push_back(copy);
    save();
    return int32_t(records.size());
}

void RecordStore::setRecord(int32_t id, Ref<Array<int8_t>> data, int32_t offset, int32_t numBytes) {
    checkOpen();
    checkId(id);
    auto copy = jrt::newArray<int8_t>(numBytes);
    if (numBytes > 0) java::lang::System::arraycopy(data, offset, copy, 0, numBytes);
    records[size_t(id - 1)] = copy;
    save();
}

void RecordStore::deleteRecord(int32_t id) {
    checkOpen();
    checkId(id);
    records[size_t(id - 1)] = nullptr;
    save();
}

Ref<Array<int8_t>> RecordStore::getRecord(int32_t id) {
    checkOpen();
    checkId(id);
    auto& r = records[size_t(id - 1)];
    return r ? r->clone() : nullptr;
}

int32_t RecordStore::getRecord(int32_t id, Ref<Array<int8_t>> buffer, int32_t offset) {
    auto r = getRecord(id);
    if (!r) return 0;
    java::lang::System::arraycopy(r, 0, buffer, offset, r->length);
    return r->length;
}

int32_t RecordStore::getRecordSize(int32_t id) {
    auto r = getRecord(id);
    return r ? r->length : 0;
}

int32_t RecordStore::getNumRecords() {
    checkOpen();
    int32_t n = 0;
    for (auto& r : records)
        if (r) n++;
    return n;
}

int32_t RecordStore::getNextRecordID() {
    checkOpen();
    return int32_t(records.size()) + 1;
}

int32_t RecordStore::getSize() {
    checkOpen();
    int32_t n = 0;
    for (auto& r : records)
        if (r) n += r->length;
    return n;
}

int32_t RecordStore::getSizeAvailable() {
    checkOpen();
    return 2147483647;
}

}  // namespace javax::microedition::rms
