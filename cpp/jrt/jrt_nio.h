// java.nio.ByteBuffer (direct buffers for the M3G engine) and the
// java.awt.image.BufferedImage the M3G layer mentions (never present in the
// C++ build: Graphics targets have no software image).
#pragma once
#include "jrt.h"

#include <vector>

namespace java::nio {

class ByteBuffer : public java::lang::Object {
public:
    std::vector<uint8_t> bytes;
    int32_t pos = 0;
    int32_t lim = 0;

    static jrt::Ref<ByteBuffer> allocateDirect(int32_t n) {
        jrt::Ref<ByteBuffer> b(new ByteBuffer());
        b->bytes.assign(size_t(n > 0 ? n : 0), 0);
        b->lim = n;
        return b;
    }
    void* address() { return bytes.data(); }
    int32_t capacity() { return int32_t(bytes.size()); }
    jrt::Ref<ByteBuffer> clear() {
        pos = 0;
        lim = capacity();
        return jrt::Ref<ByteBuffer>(this);
    }
    jrt::Ref<ByteBuffer> rewind() {
        pos = 0;
        return jrt::Ref<ByteBuffer>(this);
    }
};

}  // namespace java::nio

namespace java::awt::image {

class BufferedImage : public java::lang::Object {
public:
    int32_t getWidth() { return 0; }
    int32_t getHeight() { return 0; }
};

}  // namespace java::awt::image
