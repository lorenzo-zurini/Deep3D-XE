// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

jrt::Ref<jrt::Array<int8_t>> javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER{};
jrt::Ref<jrt::Array<int8_t>> javax::microedition::m3g::Loader::PNG_FILE_IDENTIFIER{};
int32_t javax::microedition::m3g::Loader::PNG_IHDR{};
int32_t javax::microedition::m3g::Loader::PNG_tRNS{};
int32_t javax::microedition::m3g::Loader::PNG_IDAT{};
jrt::Ref<jrt::Array<int8_t>> javax::microedition::m3g::Loader::JPEG_FILE_IDENTIFIER{};
int32_t javax::microedition::m3g::Loader::JPEG_JFIF{};
int32_t javax::microedition::m3g::Loader::JPEG_SOFn_DELTA{};
int32_t javax::microedition::m3g::Loader::JPEG_INVALID_COLOUR_FORMAT{};
int32_t javax::microedition::m3g::Loader::INVALID_HEADER_TYPE{};
int32_t javax::microedition::m3g::Loader::M3G_TYPE{};
int32_t javax::microedition::m3g::Loader::PNG_TYPE{};
int32_t javax::microedition::m3g::Loader::JPEG_TYPE{};
int32_t javax::microedition::m3g::Loader::MAX_IDENTIFIER_LENGTH{};
int32_t javax::microedition::m3g::Loader::AVG_HEADER_SEC_LENGTH{};
int32_t javax::microedition::m3g::Loader::AVG_XREF_SEC_LENGTH{};

void javax::microedition::m3g::Loader::__clinit() {
    javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER = jrt::arrayOf<int8_t>({int8_t((-85)), int8_t(74), int8_t(83), int8_t(82), int8_t(49), int8_t(56), int8_t(52), int8_t((-69)), int8_t(13), int8_t(10), int8_t(26), int8_t(10)});
    javax::microedition::m3g::Loader::PNG_FILE_IDENTIFIER = jrt::arrayOf<int8_t>({int8_t((-119)), int8_t(80), int8_t(78), int8_t(71), int8_t(13), int8_t(10), int8_t(26), int8_t(10)});
    javax::microedition::m3g::Loader::PNG_IHDR = 1229472850;
    javax::microedition::m3g::Loader::PNG_tRNS = 1951551059;
    javax::microedition::m3g::Loader::PNG_IDAT = 1229209940;
    javax::microedition::m3g::Loader::JPEG_FILE_IDENTIFIER = jrt::arrayOf<int8_t>({int8_t((-1)), int8_t((-40))});
    javax::microedition::m3g::Loader::JPEG_JFIF = 1246120262;
    javax::microedition::m3g::Loader::JPEG_SOFn_DELTA = 7;
    javax::microedition::m3g::Loader::JPEG_INVALID_COLOUR_FORMAT = (-1);
    javax::microedition::m3g::Loader::INVALID_HEADER_TYPE = (-1);
    javax::microedition::m3g::Loader::M3G_TYPE = 0;
    javax::microedition::m3g::Loader::PNG_TYPE = 1;
    javax::microedition::m3g::Loader::JPEG_TYPE = 2;
    javax::microedition::m3g::Loader::MAX_IDENTIFIER_LENGTH = javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER->length;
    javax::microedition::m3g::Loader::AVG_HEADER_SEC_LENGTH = 64;
    javax::microedition::m3g::Loader::AVG_XREF_SEC_LENGTH = 128;
}

void javax::microedition::m3g::Loader::finalize() {
    this->doFinalize();
}

void javax::microedition::m3g::Loader::__init() {
    this->iLoadedObjects = jrt::New<java::util::Vector>();
    this->iFileHistory = jrt::New<java::util::Vector>();
    this->iResourceName = jrt::Ref<java::lang::String>(nullptr);
    this->iParentResourceName = jrt::Ref<java::lang::String>(nullptr);
    this->iTotalFileSize = 0;
    this->iBytesRead = javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER->length;
    this->iStreamData = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    this->iStreamOffset = 0;
    this->iInterface = javax::microedition::m3g::Interface::getInstance();
}

void javax::microedition::m3g::Loader::__init(jrt::Ref<java::util::Vector> aFileHistory, jrt::Ref<java::lang::String> aParentResourceName) {
    this->iLoadedObjects = jrt::New<java::util::Vector>();
    this->iFileHistory = jrt::New<java::util::Vector>();
    this->iResourceName = jrt::Ref<java::lang::String>(nullptr);
    this->iParentResourceName = jrt::Ref<java::lang::String>(nullptr);
    this->iTotalFileSize = 0;
    this->iBytesRead = javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER->length;
    this->iStreamData = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    this->iStreamOffset = 0;
    this->iParentResourceName = aParentResourceName;
    this->iFileHistory = aFileHistory;
    this->iInterface = javax::microedition::m3g::Interface::getInstance();
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::load(jrt::Ref<java::lang::String> name) {
    if (name == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    {
        try {
            return (jrt::New<javax::microedition::m3g::Loader>())->loadFromStream(name);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::SecurityException>(__ex1.t)) {
                jrt::Ref<java::lang::SecurityException> e = jrt::cast<java::lang::SecurityException>(__ex1.t);
                jrt::throwJava(e);
            } else if (jrt::isInstance<java::io::IOException>(__ex1.t)) {
                jrt::Ref<java::io::IOException> e = jrt::cast<java::io::IOException>(__ex1.t);
                jrt::throwJava(e);
            } else if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Load error "), e)));
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::load(jrt::Ref<jrt::Array<int8_t>> data, int32_t offset) {
    if (data == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if ((offset < 0) || (offset >= data->length)) {
        jrt::throwJava(jrt::New<java::lang::IndexOutOfBoundsException>());
    }
    {
        try {
            return (jrt::New<javax::microedition::m3g::Loader>())->loadFromByteArray(data, offset);
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::SecurityException>(__ex1.t)) {
                jrt::Ref<java::lang::SecurityException> e = jrt::cast<java::lang::SecurityException>(__ex1.t);
                jrt::throwJava(e);
            } else if (jrt::isInstance<java::io::IOException>(__ex1.t)) {
                jrt::Ref<java::io::IOException> e = jrt::cast<java::io::IOException>(__ex1.t);
                jrt::throwJava(e);
            } else if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Load error "), e)));
            } else {
                throw;
            }
        }
    }
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::loadFromStream(jrt::Ref<java::lang::String> aName) {
    if (aName == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if (this->inFileHistory(aName)) {
        jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Reference loop detected.")));
    }
    this->iResourceName = aName;
    this->iFileHistory->addElement(jrt::Ref<java::lang::Object>(aName));
    jrt::Ref<javax::microedition::m3g::Loader_PeekInputStream> stream = [&]() { jrt::Ref<javax::microedition::m3g::Loader_PeekInputStream> __o(new javax::microedition::m3g::Loader_PeekInputStream()); __o->__outer = this; __o->__init(this->getInputStream(aName), javax::microedition::m3g::Loader::MAX_IDENTIFIER_LENGTH); return __o; }();
    int32_t type = this->getIdentifierType(jrt::Ref<java::io::InputStream>(stream));
    stream->rewind();
    this->iStreamData = jrt::Ref<jrt::Array<int8_t>>(nullptr);
    this->iStreamOffset = 0;
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> objects{};
    {
        jrt::Finally __finally([&]() {
            {
                try {
                    stream->close();
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                        e->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
        });
        {
            objects = this->doLoad(jrt::Ref<java::io::InputStream>(stream), type);
        }
    }
    this->iFileHistory->removeElement(jrt::Ref<java::lang::Object>(aName));
    return objects;
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::loadFromByteArray(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset) {
    if (aData == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>(JRT_LIT(u"Resource byte array is null.")));
    }
    int32_t type = javax::microedition::m3g::Loader::getIdentifierType(aData, aOffset);
    jrt::Ref<java::io::ByteArrayInputStream> stream = jrt::New<java::io::ByteArrayInputStream>(aData, aOffset, (aData->length - aOffset));
    this->iStreamData = aData;
    this->iStreamOffset = aOffset;
    this->iResourceName = JRT_LIT(u"ByteArray");
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> objects{};
    {
        jrt::Finally __finally([&]() {
            {
                try {
                    stream->close();
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                        e->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
        });
        {
            objects = this->doLoad(jrt::Ref<java::io::InputStream>(stream), type);
        }
    }
    return objects;
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::doLoad(jrt::Ref<java::io::InputStream> aStream, int32_t aType) {
    {
        switch (aType) {
        case 0:
            return this->loadM3G(aStream);
        case 1:
            return this->loadPNG(aStream);
        case 2:
            return this->loadJPEG(aStream);
        }
    }
    jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"File not recognized.")));
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::loadPNG(jrt::Ref<java::io::InputStream> aStream) {
    int32_t format = 99;
    jrt::Ref<java::io::DataInputStream> in = jrt::New<java::io::DataInputStream>(aStream);
    in->skip(int64_t(javax::microedition::m3g::Loader::PNG_FILE_IDENTIFIER->length));
    {
        try {
            while (true) {
                int32_t length = in->readInt();
                int32_t type = in->readInt();
                if (type == 1229472850) {
                    in->skip(int64_t(9));
                    int32_t colourType = in->readUnsignedByte();
                    length -= 10;
                    {
                        switch (colourType) {
                        case 0:
                            format = 97;
                            break;
                        case 2:
                            format = 99;
                            break;
                        case 3:
                            format = 99;
                            break;
                        case 4:
                            format = 98;
                            break;
                        case 6:
                            format = 100;
                            break;
                        }
                    }
                }
                if (type == 1951551059) {
                    {
                        switch (format) {
                        case 97:
                            format = 98;
                            break;
                        case 99:
                            format = 100;
                            break;
                        }
                    }
                }
                if (type == 1229209940) {
                    break;
                }
                in->skip(int64_t((length + 4)));
            }
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                e->printStackTrace();
            } else {
                throw;
            }
        }
    }
    {
        try {
            in->close();
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex2.t);
                e->printStackTrace();
            } else {
                throw;
            }
        }
    }
    return this->buildImage2D(format);
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::loadJPEG(jrt::Ref<java::io::InputStream> aStream) {
    int32_t format = -1;
    jrt::Ref<java::io::DataInputStream> in = jrt::New<java::io::DataInputStream>(aStream);
    in->skip(int64_t(javax::microedition::m3g::Loader::JPEG_FILE_IDENTIFIER->length));
    {
        try {
            int32_t marker{};
            do {
                while (in->readUnsignedByte() != 255) {
                    ;
                }
                do {
                    marker = in->readUnsignedByte();
                } while (marker == 255);
                {
                    int32_t length{};
                    switch (marker) {
                    case 192:
                        ;
                    case 193:
                        ;
                    case 194:
                        ;
                    case 195:
                        ;
                    case 197:
                        ;
                    case 198:
                        ;
                    case 199:
                        ;
                    case 201:
                        ;
                    case 202:
                        ;
                    case 203:
                        ;
                    case 205:
                        ;
                    case 206:
                        ;
                    case 207:
                        in->skip(int64_t(7));
                        {
                            switch (in->readUnsignedByte()) {
                            case 1:
                                format = 97;
                                break;
                            case 3:
                                format = 99;
                                break;
                            default:
                                jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Unknown JPG format.")));
                            }
                        }
                        break;
                    case 224:
                        length = in->readUnsignedShort();
                        if (1246120262 != in->readInt()) {
                            jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Not a valid JPG file.")));
                        }
                        in->skip(int64_t(((length - 4) - 2)));
                        break;
                    default:
                        in->skip(int64_t((in->readUnsignedShort() - 2)));
                        break;
                    }
                }
            } while (format == (-1));
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                e->printStackTrace();
            } else {
                throw;
            }
        }
    }
    {
        try {
            in->close();
        } catch (const jrt::Thrown& __ex2) {
            if (jrt::isInstance<java::lang::Exception>(__ex2.t)) {
                jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex2.t);
                e->printStackTrace();
            } else {
                throw;
            }
        }
    }
    return this->buildImage2D(format);
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::buildImage2D(int32_t aColourFormat) {
    jrt::Ref<java::io::InputStream> stream{};
    if (this->iStreamData == nullptr) {
        stream = this->getInputStream(this->iResourceName);
    } else {
        stream = jrt::Ref<java::io::InputStream>(jrt::New<java::io::ByteArrayInputStream>(this->iStreamData, this->iStreamOffset, (this->iStreamData->length - this->iStreamOffset)));
    }
    jrt::Ref<javax::microedition::m3g::Image2D> i2d{};
    {
        jrt::Finally __finally([&]() {
            {
                try {
                    stream->close();
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                        e->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
        });
        {
            i2d = jrt::New<javax::microedition::m3g::Image2D>(aColourFormat, jrt::Ref<java::lang::Object>(javax::microedition::lcdui::Image::createImage(stream)));
        }
    }
    return jrt::arrayOf<jrt::Ref<javax::microedition::m3g::Object3D>>({jrt::Ref<javax::microedition::m3g::Object3D>(i2d)});
}

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> javax::microedition::m3g::Loader::loadM3G(jrt::Ref<java::io::InputStream> aStream) {
    aStream->skip(int64_t(javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER->length));
    if (jrt::isInstance<javax::microedition::m3g::Loader_PeekInputStream>(aStream)) {
        (jrt::cast<javax::microedition::m3g::Loader_PeekInputStream>(aStream))->increasePeekBuffer(64);
    }
    int32_t compressionScheme = javax::microedition::m3g::Loader::readByte(aStream);
    int32_t totalSectionLength = javax::microedition::m3g::Loader::readUInt32(aStream);
    if (jrt::isInstance<javax::microedition::m3g::Loader_PeekInputStream>(aStream) && (totalSectionLength > 64)) {
        (jrt::cast<javax::microedition::m3g::Loader_PeekInputStream>(aStream))->increasePeekBuffer((totalSectionLength - 64));
    }
    int32_t uncompressedLength = javax::microedition::m3g::Loader::readUInt32(aStream);
    int32_t objectType = javax::microedition::m3g::Loader::readByte(aStream);
    int32_t length = javax::microedition::m3g::Loader::readUInt32(aStream);
    int8_t vMajor = int8_t(javax::microedition::m3g::Loader::readByte(aStream));
    int8_t vMinor = int8_t(javax::microedition::m3g::Loader::readByte(aStream));
    bool externalLinks = javax::microedition::m3g::Loader::readBoolean(aStream);
    this->iTotalFileSize = javax::microedition::m3g::Loader::readUInt32(aStream);
    int32_t approximateContentSize = javax::microedition::m3g::Loader::readUInt32(aStream);
    jrt::Ref<java::lang::String> authoringField = javax::microedition::m3g::Loader::readString(aStream);
    int32_t checksum = javax::microedition::m3g::Loader::readUInt32(aStream);
    this->handle = javax::microedition::m3g::Loader::_ctor(javax::microedition::m3g::Interface::getHandle());
    javax::microedition::m3g::Interface::register_(jrt::Ref<javax::microedition::m3g::Loader>(this));
    if (externalLinks) {
        if (jrt::isInstance<javax::microedition::m3g::Loader_PeekInputStream>(aStream)) {
            (jrt::cast<javax::microedition::m3g::Loader_PeekInputStream>(aStream))->increasePeekBuffer(128);
        }
        this->loadExternalRefs(aStream);
        if (this->iLoadedObjects->size() > 0) {
            jrt::Ref<jrt::Array<int64_t>> xRef = jrt::newArray<int64_t>(this->iLoadedObjects->size());
            for (int32_t i = 0; i < xRef->length; i++) {
                xRef->at(i) = (jrt::cast<javax::microedition::m3g::Object3D>(this->iLoadedObjects->elementAt(i)))->handle;
            }
            javax::microedition::m3g::Loader::_setExternalReferences(this->handle, xRef);
        } else {
            jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"No external sections ["), this->iResourceName, JRT_LIT(u"]."))));
        }
    }
    if (jrt::isInstance<javax::microedition::m3g::Loader_PeekInputStream>(aStream)) {
        (jrt::cast<javax::microedition::m3g::Loader_PeekInputStream>(aStream))->rewind();
    } else if (aStream->markSupported()) {
        aStream->reset();
    }
    int32_t read = 0;
    int32_t size = aStream->available();
    if (size == 0) {
        size = 2048;
    }
    while (read < this->iTotalFileSize) {
        if ((read + size) > this->iTotalFileSize) {
            size = this->iTotalFileSize - read;
        }
        jrt::Ref<jrt::Array<int8_t>> data = jrt::newArray<int8_t>(size);
        if (aStream->read(data) == (-1)) {
            break;
        }
        read += size;
        size = javax::microedition::m3g::Loader::_decodeData(this->handle, 0, data);
        if ((size > 0) && (aStream->available() > size)) {
            size = aStream->available();
        }
    }
    if ((size != 0) || (read != this->iTotalFileSize)) {
        jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Invalid file length ["), this->iResourceName, JRT_LIT(u"]."))));
    }
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> objects = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>>(nullptr);
    int32_t num = javax::microedition::m3g::Loader::_getLoadedObjects(this->handle, jrt::Ref<jrt::Array<int64_t>>(nullptr));
    if (num > 0) {
        jrt::Ref<jrt::Array<int64_t>> obj = jrt::newArray<int64_t>(num);
        javax::microedition::m3g::Loader::_getLoadedObjects(this->handle, obj);
        objects = jrt::newArray<jrt::Ref<javax::microedition::m3g::Object3D>>(num);
        for (int32_t i = 0; i < objects->length; i++) {
            objects->at(i) = javax::microedition::m3g::Interface::getObjectInstance(obj->at(i));
        }
        this->setUserObjects();
    }
    return objects;
}

void javax::microedition::m3g::Loader::setUserObjects() {
    int32_t numObjects = javax::microedition::m3g::Loader::_getObjectsWithUserParameters(this->handle, jrt::Ref<jrt::Array<int64_t>>(nullptr));
    jrt::Ref<jrt::Array<int64_t>> obj = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    if (numObjects > 0) {
        obj = jrt::newArray<int64_t>(numObjects);
        javax::microedition::m3g::Loader::_getObjectsWithUserParameters(this->handle, obj);
    }
    for (int32_t i = 0; i < numObjects; i++) {
        int32_t num = javax::microedition::m3g::Loader::_getNumUserParameters(this->handle, i);
        if (num > 0) {
            jrt::Ref<java::util::Hashtable> hash = jrt::New<java::util::Hashtable>();
            for (int32_t j = 0; j < num; j++) {
                int32_t len = javax::microedition::m3g::Loader::_getUserParameter(this->handle, i, j, jrt::Ref<jrt::Array<int8_t>>(nullptr));
                jrt::Ref<jrt::Array<int8_t>> data = jrt::newArray<int8_t>(len);
                int32_t id = javax::microedition::m3g::Loader::_getUserParameter(this->handle, i, j, data);
                if (hash->put(jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(id)), jrt::Ref<java::lang::Object>(data)) != nullptr) {
                    jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Duplicate id in user data ["), this->iResourceName, JRT_LIT(u"]."))));
                }
            }
            jrt::Ref<javax::microedition::m3g::Object3D> object = javax::microedition::m3g::Interface::getObjectInstance(obj->at(i));
            object->setUserObject(jrt::Ref<java::lang::Object>(hash));
        }
    }
}

void javax::microedition::m3g::Loader::loadExternalRefs(jrt::Ref<java::io::InputStream> aStream) {
    int32_t firstByte = javax::microedition::m3g::Loader::readByte(aStream);
    if ((firstByte == (-1)) || ((this->iTotalFileSize != 0) && (this->iBytesRead >= this->iTotalFileSize))) {
        return;
    }
    int32_t compressionScheme = firstByte;
    int32_t totalSectionLength = javax::microedition::m3g::Loader::readUInt32(aStream);
    this->iBytesRead += totalSectionLength;
    if (jrt::isInstance<javax::microedition::m3g::Loader_PeekInputStream>(aStream) && (totalSectionLength > 128)) {
        (jrt::cast<javax::microedition::m3g::Loader_PeekInputStream>(aStream))->increasePeekBuffer((totalSectionLength - 128));
    }
    int32_t uncompressedLength = javax::microedition::m3g::Loader::readUInt32(aStream);
    int32_t expectedCount = totalSectionLength;
    jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> uncompressedStream{};
    if (compressionScheme == 0) {
        uncompressedStream = [&]() { jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> __o(new javax::microedition::m3g::Loader_CountedInputStream()); __o->__outer = this; __o->__init(aStream); return __o; }();
        if (uncompressedLength != (totalSectionLength - 13)) {
            jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Section length mismatch ["), this->iResourceName, JRT_LIT(u"]."))));
        }
    } else if (compressionScheme == 1) {
        if ((uncompressedLength == 0) && ((totalSectionLength - 13) == 0)) {
            uncompressedStream = [&]() { jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> __o(new javax::microedition::m3g::Loader_CountedInputStream()); __o->__outer = this; __o->__init(jrt::Ref<java::io::InputStream>(nullptr)); return __o; }();
        } else {
            if ((uncompressedLength <= 0) || ((totalSectionLength - 13) <= 0)) {
                jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Section length mismatch ["), this->iResourceName, JRT_LIT(u"]."))));
            }
            jrt::Ref<jrt::Array<int8_t>> compressed = jrt::newArray<int8_t>((totalSectionLength - 13));
            aStream->read(compressed);
            jrt::Ref<jrt::Array<int8_t>> uncompressed = jrt::newArray<int8_t>(uncompressedLength);
            if (!javax::microedition::m3g::Loader::_inflate(compressed, uncompressed)) {
                jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Decompression error.")));
            }
            uncompressedStream = [&]() { jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> __o(new javax::microedition::m3g::Loader_CountedInputStream()); __o->__outer = this; __o->__init(jrt::Ref<java::io::InputStream>(jrt::New<java::io::ByteArrayInputStream>(uncompressed))); return __o; }();
        }
    } else {
        jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Unrecognized compression scheme ["), this->iResourceName, JRT_LIT(u"]."))));
    }
    uncompressedStream->resetCounter();
    while (uncompressedStream->getCounter() < uncompressedLength) {
        this->iLoadedObjects->addElement(jrt::Ref<java::lang::Object>(this->loadObject(uncompressedStream)));
    }
    if (uncompressedStream->getCounter() != uncompressedLength) {
        jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Section length mismatch ["), this->iResourceName, JRT_LIT(u"]."))));
    }
    int32_t checksum = javax::microedition::m3g::Loader::readUInt32(aStream);
}

jrt::Ref<javax::microedition::m3g::Object3D> javax::microedition::m3g::Loader::loadObject(jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> aStream) {
    int32_t objectType = javax::microedition::m3g::Loader::readByte(jrt::Ref<java::io::InputStream>(aStream));
    int32_t length = javax::microedition::m3g::Loader::readUInt32(jrt::Ref<java::io::InputStream>(aStream));
    int32_t expectedCount = aStream->getCounter() + length;
    jrt::Ref<javax::microedition::m3g::Object3D> newObject{};
    if (objectType == 255) {
        jrt::Ref<java::lang::String> xref = javax::microedition::m3g::Loader::readString(jrt::Ref<java::io::InputStream>(aStream));
        newObject = (jrt::New<javax::microedition::m3g::Loader>(this->iFileHistory, this->iResourceName))->loadFromStream(xref)->at(0);
    } else {
        jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Invalid external section ["), this->iResourceName, JRT_LIT(u"]."))));
    }
    if (expectedCount != aStream->getCounter()) {
        jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Object length mismatch ["), this->iResourceName, JRT_LIT(u"]."))));
    }
    return newObject;
}

int32_t javax::microedition::m3g::Loader::readByte(jrt::Ref<java::io::InputStream> aStream) {
    return aStream->read();
}

bool javax::microedition::m3g::Loader::readBoolean(jrt::Ref<java::io::InputStream> aStream) {
    int32_t b = aStream->read();
    if (b == 0) {
        return false;
    }
    if (b != 1) {
        jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Malformed boolean.")));
    }
    return true;
}

int32_t javax::microedition::m3g::Loader::readUInt32(jrt::Ref<java::io::InputStream> aStream) {
    return [&]() { int32_t __l3 = ([&]() { int32_t __l2 = ([&]() { int32_t __l1 = aStream->read(); int32_t __r1 = (aStream->read() << 8); return (__l1 + __r1); }()); int32_t __r2 = (aStream->read() << 16); return (__l2 + __r2); }()); int32_t __r3 = (aStream->read() << 24); return (__l3 + __r3); }();
}

jrt::Ref<java::lang::String> javax::microedition::m3g::Loader::readString(jrt::Ref<java::io::InputStream> aStream) {
    jrt::Ref<java::lang::StringBuilder> result = jrt::New<java::lang::StringBuilder>();
    for (int32_t c = aStream->read(); c != 0; c = aStream->read()) {
        if ((c & 128) == 0) {
            result->append(char16_t((c & 255)));
        } else if ((c & 224) == 192) {
            int32_t c2 = aStream->read();
            if ((c2 & 192) != 128) {
                jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Invalid UTF-8 string.")));
            } else {
                result->append(char16_t((((c & 31) << 6) | (c2 & 63))));
            }
        } else if ((c & 240) == 224) {
            int32_t c2 = aStream->read();
            int32_t c3 = aStream->read();
            if (((c2 & 192) != 128) || ((c3 & 192) != 128)) {
                jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Invalid UTF-8 string.")));
            } else {
                result->append(char16_t(((((c & 15) << 12) | ((c2 & 63) << 6)) | (c3 & 63))));
            }
        } else {
            jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Invalid UTF-8 string.")));
        }
    }
    return result->toString();
}

int32_t javax::microedition::m3g::Loader::getIdentifierType(jrt::Ref<java::io::InputStream> aStream) {
    jrt::Ref<jrt::Array<int8_t>> data = jrt::newArray<int8_t>(javax::microedition::m3g::Loader::MAX_IDENTIFIER_LENGTH);
    aStream->read(data);
    return javax::microedition::m3g::Loader::getIdentifierType(data, 0);
}

int32_t javax::microedition::m3g::Loader::getIdentifierType(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset) {
    if (javax::microedition::m3g::Loader::parseIdentifier(aData, aOffset, javax::microedition::m3g::Loader::JPEG_FILE_IDENTIFIER)) {
        return 2;
    } else if (javax::microedition::m3g::Loader::parseIdentifier(aData, aOffset, javax::microedition::m3g::Loader::PNG_FILE_IDENTIFIER)) {
        return 1;
    } else if (javax::microedition::m3g::Loader::parseIdentifier(aData, aOffset, javax::microedition::m3g::Loader::M3G_FILE_IDENTIFIER)) {
        return 0;
    }
    return -1;
}

bool javax::microedition::m3g::Loader::parseIdentifier(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset, jrt::Ref<jrt::Array<int8_t>> aIdentifier) {
    if ((aData->length - aOffset) < aIdentifier->length) {
        return false;
    }
    for (int32_t index = 0; index < aIdentifier->length; index++) {
        if (int32_t(aData->at((index + aOffset))) != int32_t(aIdentifier->at(index))) {
            return false;
        }
    }
    return true;
}

bool javax::microedition::m3g::Loader::inFileHistory(jrt::Ref<java::lang::String> name) {
    for (int32_t i = 0; i < this->iFileHistory->size(); i++) {
        if (this->iFileHistory->elementAt(i)->equals(jrt::Ref<java::lang::Object>(name))) {
            return true;
        }
    }
    return false;
}

jrt::Ref<java::io::InputStream> javax::microedition::m3g::Loader::getHttpInputStream(jrt::Ref<java::lang::String> name) {
    jrt::Ref<javax::microedition::io::InputConnection> ic = jrt::cast<javax::microedition::io::InputConnection>(javax::microedition::io::Connector::open(name));
    if (jrt::isInstance<javax::microedition::io::HttpConnection>(ic)) {
        jrt::Ref<javax::microedition::io::HttpConnection> hc = jrt::cast<javax::microedition::io::HttpConnection>(ic);
        jrt::Ref<java::lang::String> type = hc->getHeaderField(JRT_LIT(u"Content-Type"));
        if ((((type != nullptr) && (!type->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u"application/m3g"))))) && (!type->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u"image/png"))))) && (!type->equals(jrt::Ref<java::lang::Object>(JRT_LIT(u"image/jpeg"))))) {
            jrt::throwJava(jrt::New<java::io::IOException>(jrt::concat(JRT_LIT(u"Wrong MIME type: "), type, JRT_LIT(u"."))));
        }
    }
    jrt::Ref<java::io::InputStream> is{};
    {
        jrt::Finally __finally([&]() {
            {
                try {
                    ic->close();
                } catch (const jrt::Thrown& __ex1) {
                    if (jrt::isInstance<java::lang::Exception>(__ex1.t)) {
                        jrt::Ref<java::lang::Exception> e = jrt::cast<java::lang::Exception>(__ex1.t);
                        e->printStackTrace();
                    } else {
                        throw;
                    }
                }
            }
        });
        {
            is = ic->openInputStream();
        }
    }
    return is;
}

jrt::Ref<java::io::InputStream> javax::microedition::m3g::Loader::getInputStream(jrt::Ref<java::lang::String> name) {
    if (name->indexOf(int32_t(u':')) != (-1)) {
        return this->getHttpInputStream(name);
    }
    if ((int32_t(name->charAt(0)) == int32_t(u'/')) || (this->iParentResourceName == nullptr)) {
        return org::deep3d::Assets::open(name);
    }
    jrt::Ref<java::lang::String> uri = jrt::concat(this->iParentResourceName->substring(0, (this->iParentResourceName->lastIndexOf(int32_t(u'/')) + 1)), name);
    if (int32_t(uri->charAt(0)) == int32_t(u'/')) {
        return org::deep3d::Assets::open(uri);
    } else {
        return this->getHttpInputStream(uri);
    }
}

void javax::microedition::m3g::Loader::doFinalize() {
    this->registeredFinalize();
}

void javax::microedition::m3g::Loader::registeredFinalize() {
    if (this->handle != int64_t(0)) {
        javax::microedition::m3g::Platform::finalizeObject(this->handle, this->iInterface);
        javax::microedition::m3g::Interface::deregister(jrt::Ref<javax::microedition::m3g::Loader>(this), this->iInterface);
        this->iInterface = jrt::Ref<javax::microedition::m3g::Interface>(nullptr);
        this->handle = int64_t(0);
    }
}

bool javax::microedition::m3g::Loader::_inflate(jrt::Ref<jrt::Array<int8_t>> data, jrt::Ref<jrt::Array<int8_t>> buffer) {
    auto __r = Java_javax_microedition_m3g_Loader__1inflate(jrt::jni::env(), nullptr, jrt::jni::arg(data), jrt::jni::arg(buffer));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

int64_t javax::microedition::m3g::Loader::_ctor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Loader__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Loader::_decodeData(int64_t handle, int32_t offset, jrt::Ref<jrt::Array<int8_t>> data) {
    auto __r = Java_javax_microedition_m3g_Loader__1decodeData(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(offset), jrt::jni::arg(data));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Loader::_setExternalReferences(int64_t handle, jrt::Ref<jrt::Array<int64_t>> references) {
    Java_javax_microedition_m3g_Loader__1setExternalReferences(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(references));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Loader::_getLoadedObjects(int64_t handle, jrt::Ref<jrt::Array<int64_t>> objects) {
    auto __r = Java_javax_microedition_m3g_Loader__1getLoadedObjects(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(objects));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Loader::_getObjectsWithUserParameters(int64_t handle, jrt::Ref<jrt::Array<int64_t>> objects) {
    auto __r = Java_javax_microedition_m3g_Loader__1getObjectsWithUserParameters(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(objects));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Loader::_getNumUserParameters(int64_t handle, int32_t obj) {
    auto __r = Java_javax_microedition_m3g_Loader__1getNumUserParameters(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(obj));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Loader::_getUserParameter(int64_t handle, int32_t obj, int32_t index, jrt::Ref<jrt::Array<int8_t>> data) {
    auto __r = Java_javax_microedition_m3g_Loader__1getUserParameter(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(obj), jrt::jni::arg(index), jrt::jni::arg(data));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

javax::microedition::m3g::Loader::~Loader() {
    try {
        this->finalize();
    } catch (...) {
    }
}


void javax::microedition::m3g::Loader_PeekInputStream::__clinit() {
}

void javax::microedition::m3g::Loader_PeekInputStream::__init(jrt::Ref<java::io::InputStream> aStream, int32_t aLength) {
    java::io::InputStream::__init();
    this->iStream = aStream;
    this->iPeekBuffer = jrt::newArray<int32_t>(aLength);
}

int32_t javax::microedition::m3g::Loader_PeekInputStream::read() {
    if (this->iCounter < this->iBuffered) {
        return this->iPeekBuffer->at((this->iCounter++));
    }
    int32_t nv = this->iStream->read();
    if (this->iBuffered < this->iPeekBuffer->length) {
        this->iPeekBuffer->at(this->iBuffered) = nv;
        this->iBuffered++;
    }
    this->iCounter++;
    return nv;
}

void javax::microedition::m3g::Loader_PeekInputStream::increasePeekBuffer(int32_t aLength) {
    jrt::Ref<jrt::Array<int32_t>> temp = jrt::newArray<int32_t>((this->iPeekBuffer->length + aLength));
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(this->iPeekBuffer), 0, jrt::Ref<java::lang::Object>(temp), 0, this->iBuffered);
    this->iPeekBuffer = temp;
}

int32_t javax::microedition::m3g::Loader_PeekInputStream::available() {
    if (this->iCounter < this->iBuffered) {
        return (this->iBuffered - this->iCounter) + this->iStream->available();
    }
    return this->iStream->available();
}

void javax::microedition::m3g::Loader_PeekInputStream::close() {
    {
        try {
            this->iStream->close();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::io::IOException>(__ex1.t)) {
                jrt::Ref<java::io::IOException> ioe = jrt::cast<java::io::IOException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

void javax::microedition::m3g::Loader_PeekInputStream::rewind() {
    if (this->iCounter > this->iBuffered) {
        jrt::throwJava(jrt::New<java::io::IOException>(JRT_LIT(u"Peek buffer overrun.")));
    }
    this->iCounter = 0;
}


void javax::microedition::m3g::Loader_CountedInputStream::__clinit() {
}

void javax::microedition::m3g::Loader_CountedInputStream::__init(jrt::Ref<java::io::InputStream> aStream) {
    java::io::InputStream::__init();
    this->iStream = aStream;
    this->resetCounter();
}

int32_t javax::microedition::m3g::Loader_CountedInputStream::read() {
    this->iCounter++;
    return this->iStream->read();
}

void javax::microedition::m3g::Loader_CountedInputStream::resetCounter() {
    this->iCounter = 0;
}

int32_t javax::microedition::m3g::Loader_CountedInputStream::getCounter() {
    return this->iCounter;
}

void javax::microedition::m3g::Loader_CountedInputStream::close() {
    {
        try {
            this->iStream->close();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::io::IOException>(__ex1.t)) {
                jrt::Ref<java::io::IOException> ioe = jrt::cast<java::io::IOException>(__ex1.t);
            } else {
                throw;
            }
        }
    }
}

int32_t javax::microedition::m3g::Loader_CountedInputStream::available() {
    return this->iStream->available();
}

