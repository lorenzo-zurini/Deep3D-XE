// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#pragma once
#include "deep3d/m3g_deps.h"

namespace javax::microedition::m3g { class Object3D; }
namespace javax::microedition::m3g { class AnimationController; }
namespace javax::microedition::m3g { class AnimationTrack; }
namespace javax::microedition::m3g { class Appearance; }
namespace javax::microedition::m3g { class Background; }
namespace javax::microedition::m3g { class Transformable; }
namespace javax::microedition::m3g { class Node; }
namespace javax::microedition::m3g { class Camera; }
namespace javax::microedition::m3g { class CompositingMode; }
namespace javax::microedition::m3g { class Defs; }
namespace javax::microedition::m3g { class Fog; }
namespace javax::microedition::m3g { class Graphics3D; }
namespace javax::microedition::m3g { class Graphics3D_Destroyer; }
namespace javax::microedition::m3g { class M3gRunnable; }
namespace javax::microedition::m3g { class Graphics3D__anon1; }
namespace javax::microedition::m3g { class Graphics3D__anon2; }
namespace javax::microedition::m3g { class Graphics3D__anon3; }
namespace javax::microedition::m3g { class Graphics3D__anon4; }
namespace javax::microedition::m3g { class Graphics3D__anon5; }
namespace javax::microedition::m3g { class Graphics3D__anon6; }
namespace javax::microedition::m3g { class Graphics3D__anon7; }
namespace javax::microedition::m3g { class Graphics3D__anon8; }
namespace javax::microedition::m3g { class Graphics3D__anon9; }
namespace javax::microedition::m3g { class Group; }
namespace javax::microedition::m3g { class Image2D; }
namespace javax::microedition::m3g { class Image2D__anon1; }
namespace javax::microedition::m3g { class IndexBuffer; }
namespace javax::microedition::m3g { class KeyframeSequence; }
namespace javax::microedition::m3g { class Light; }
namespace javax::microedition::m3g { class Loader; }
namespace javax::microedition::m3g { class Loader_PeekInputStream; }
namespace javax::microedition::m3g { class Loader_CountedInputStream; }
namespace javax::microedition::m3g { class Material; }
namespace javax::microedition::m3g { class Mesh; }
namespace javax::microedition::m3g { class MorphingMesh; }
namespace javax::microedition::m3g { class PolygonMode; }
namespace javax::microedition::m3g { class RayIntersection; }
namespace javax::microedition::m3g { class SkinnedMesh; }
namespace javax::microedition::m3g { class Sprite3D; }
namespace javax::microedition::m3g { class Texture2D; }
namespace javax::microedition::m3g { class Transform; }
namespace javax::microedition::m3g { class TriangleStripArray; }
namespace javax::microedition::m3g { class VertexArray; }
namespace javax::microedition::m3g { class VertexBuffer; }
namespace javax::microedition::m3g { class World; }

namespace javax::microedition::m3g {
class Object3D : public java::lang::Object {
public:
    int64_t handle{};
    jrt::Ref<java::lang::Object> userObject{};
    jrt::Ref<java::util::Vector> animTracks{};
    jrt::Ref<javax::microedition::m3g::Interface> iInterface{};
    virtual void finalize();
    void __init(int64_t handle);
    virtual jrt::Ref<javax::microedition::m3g::Object3D> duplicate();
    virtual int32_t getReferences(jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> references);
    virtual void setUserID(int32_t userID);
    virtual int32_t getUserID();
    virtual jrt::Ref<javax::microedition::m3g::Object3D> find(int32_t userID);
    virtual void addAnimationTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> animationTrack);
    virtual jrt::Ref<javax::microedition::m3g::AnimationTrack> getAnimationTrack(int32_t index);
    virtual void removeAnimationTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> animationTrack);
    virtual int32_t getAnimationTrackCount();
    virtual int32_t animate(int32_t time);
    virtual void setUserObject(jrt::Ref<java::lang::Object> obj);
    virtual jrt::Ref<java::lang::Object> getUserObject();
    static jrt::Ref<javax::microedition::m3g::Object3D> getInstance(int64_t handle);
    void linkAnimTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> track);
    void doFinalize();
    static int32_t _addAnimationTrack(int64_t hObject, int64_t hAnimationTrack);
    static void _removeAnimationTrack(int64_t hObject, int64_t hAnimationTrack);
    static int32_t _getAnimationTrackCount(int64_t hObject);
    static int32_t _animate(int64_t hObject, int32_t time);
    static void _setUserID(int64_t hObject, int32_t userID);
    static int32_t _getUserID(int64_t hObject);
    static void _addRef(int64_t hObject);
    static int64_t _getAnimationTrack(int64_t hObject, int32_t index);
    static int64_t _duplicate(int64_t hObject, jrt::Ref<jrt::Array<int64_t>> handles);
    static int32_t _getReferences(int64_t hObject, jrt::Ref<jrt::Array<int64_t>> handles);
    static int64_t _find(int64_t hObject, int32_t userID);
    ~Object3D() override;
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class AnimationController : public javax::microedition::m3g::Object3D {
public:
    void __init();
    void __init(int64_t handle);
    virtual void setActiveInterval(int32_t worldTimeMin, int32_t worldTimeMax);
    virtual int32_t getActiveIntervalStart();
    virtual int32_t getActiveIntervalEnd();
    virtual void setSpeed(float factor, int32_t worldTime);
    virtual float getSpeed();
    virtual void setPosition(float time, int32_t worldTime);
    virtual float getPosition(int32_t worldTime);
    virtual void setWeight(float weight);
    virtual float getWeight();
    virtual int32_t getRefWorldTime();
    static int64_t _ctor(int64_t hInterface);
    static void _setActiveInterval(int64_t handle, int32_t worldTimeMin, int32_t worldTimeMax);
    static int32_t _getActiveIntervalStart(int64_t handle);
    static int32_t _getActiveIntervalEnd(int64_t handle);
    static void _setSpeed(int64_t handle, float factor, int32_t worldTime);
    static float _getSpeed(int64_t handle);
    static void _setPosition(int64_t handle, float time, int32_t worldTime);
    static float _getPosition(int64_t handle, int32_t worldTime);
    static void _setWeight(int64_t handle, float weight);
    static float _getWeight(int64_t handle);
    static int32_t _getRefWorldTime(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class AnimationTrack : public javax::microedition::m3g::Object3D {
public:
    static int32_t ALPHA;
    static int32_t AMBIENT_COLOR;
    static int32_t COLOR;
    static int32_t CROP;
    static int32_t DENSITY;
    static int32_t DIFFUSE_COLOR;
    static int32_t EMISSIVE_COLOR;
    static int32_t FAR_DISTANCE;
    static int32_t FIELD_OF_VIEW;
    static int32_t INTENSITY;
    static int32_t MORPH_WEIGHTS;
    static int32_t NEAR_DISTANCE;
    static int32_t ORIENTATION;
    static int32_t PICKABILITY;
    static int32_t SCALE;
    static int32_t SHININESS;
    static int32_t SPECULAR_COLOR;
    static int32_t SPOT_ANGLE;
    static int32_t SPOT_EXPONENT;
    static int32_t TRANSLATION;
    static int32_t VISIBILITY;
    jrt::Ref<javax::microedition::m3g::AnimationController> controller{};
    jrt::Ref<javax::microedition::m3g::KeyframeSequence> sequence{};
    void __init(int64_t handle);
    void __init(jrt::Ref<javax::microedition::m3g::KeyframeSequence> sequence, int32_t property);
    virtual void setController(jrt::Ref<javax::microedition::m3g::AnimationController> controller);
    virtual jrt::Ref<javax::microedition::m3g::AnimationController> getController();
    virtual jrt::Ref<javax::microedition::m3g::KeyframeSequence> getKeyframeSequence();
    virtual int32_t getTargetProperty();
    static int64_t _ctor(int64_t hInterface, int64_t hSequence, int32_t property);
    static int64_t _getController(int64_t handle);
    static int64_t _getSequence(int64_t handle);
    static int32_t _getTargetProperty(int64_t handle);
    static void _setController(int64_t handle, int64_t hController);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Appearance : public javax::microedition::m3g::Object3D {
public:
    jrt::Ref<javax::microedition::m3g::CompositingMode> compositingMode{};
    jrt::Ref<javax::microedition::m3g::Fog> fog{};
    jrt::Ref<javax::microedition::m3g::Material> material{};
    jrt::Ref<javax::microedition::m3g::PolygonMode> polygonMode{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Texture2D>>> textures{};
    void __init();
    void __init(int64_t handle);
    virtual void setCompositingMode(jrt::Ref<javax::microedition::m3g::CompositingMode> compositingMode);
    virtual jrt::Ref<javax::microedition::m3g::CompositingMode> getCompositingMode();
    virtual void setFog(jrt::Ref<javax::microedition::m3g::Fog> fog);
    virtual jrt::Ref<javax::microedition::m3g::Fog> getFog();
    virtual void setPolygonMode(jrt::Ref<javax::microedition::m3g::PolygonMode> polygonMode);
    virtual jrt::Ref<javax::microedition::m3g::PolygonMode> getPolygonMode();
    virtual void setLayer(int32_t index);
    virtual int32_t getLayer();
    virtual void setMaterial(jrt::Ref<javax::microedition::m3g::Material> material);
    virtual jrt::Ref<javax::microedition::m3g::Material> getMaterial();
    virtual void setTexture(int32_t unit, jrt::Ref<javax::microedition::m3g::Texture2D> texture);
    virtual jrt::Ref<javax::microedition::m3g::Texture2D> getTexture(int32_t unit);
    static int64_t _ctor(int64_t hInterface);
    static int64_t _getCompositingMode(int64_t hApp);
    static int64_t _getFog(int64_t hApp);
    static int32_t _getLayer(int64_t hApp);
    static int64_t _getMaterial(int64_t hApp);
    static int64_t _getPolygonMode(int64_t hApp);
    static int64_t _getTexture(int64_t hApp, int32_t unit);
    static void _setCompositingMode(int64_t hApp, int64_t hMode);
    static void _setFog(int64_t hApp, int64_t hFog);
    static void _setLayer(int64_t hApp, int32_t layer);
    static void _setMaterial(int64_t hApp, int64_t hMaterial);
    static void _setPolygonMode(int64_t hApp, int64_t hMode);
    static void _setTexture(int64_t hApp, int32_t unit, int64_t hTexture);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Background : public javax::microedition::m3g::Object3D {
public:
    static int32_t BORDER;
    static int32_t REPEAT;
    jrt::Ref<javax::microedition::m3g::Image2D> image{};
    void __init();
    void __init(int64_t handle);
    virtual void setColor(int32_t ARGB);
    virtual int32_t getColor();
    virtual void setImage(jrt::Ref<javax::microedition::m3g::Image2D> image);
    virtual jrt::Ref<javax::microedition::m3g::Image2D> getImage();
    virtual void setImageMode(int32_t modeX, int32_t modeY);
    virtual int32_t getImageModeX();
    virtual int32_t getImageModeY();
    virtual void setColorClearEnable(bool enable);
    virtual void setDepthClearEnable(bool enable);
    virtual bool isColorClearEnabled();
    virtual bool isDepthClearEnabled();
    virtual void setCrop(int32_t cropX, int32_t cropY, int32_t width, int32_t height);
    virtual int32_t getCropX();
    virtual int32_t getCropY();
    virtual int32_t getCropWidth();
    virtual int32_t getCropHeight();
    static int64_t _ctor(int64_t hInterface);
    static void _setColor(int64_t handle, int32_t ARGB);
    static int32_t _getColor(int64_t handle);
    static void _setImage(int64_t handle, int64_t hImage);
    static int64_t _getImage(int64_t handle);
    static void _setImageMode(int64_t handle, int32_t modeX, int32_t modeY);
    static int32_t _getImageMode(int64_t handle, int32_t which);
    static void _enable(int64_t handle, int32_t which, bool enable);
    static bool _isEnabled(int64_t handle, int32_t which);
    static void _setCrop(int64_t handle, int32_t cropX, int32_t cropY, int32_t width, int32_t height);
    static int32_t _getCrop(int64_t handle, int32_t which);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Transformable : public javax::microedition::m3g::Object3D {
public:
    void __init(int64_t handle);
    virtual void setOrientation(float angle, float ax, float ay, float az);
    virtual void postRotate(float angle, float ax, float ay, float az);
    virtual void preRotate(float angle, float ax, float ay, float az);
    virtual void getOrientation(jrt::Ref<jrt::Array<float>> angleAxis);
    virtual void setScale(float sx, float sy, float sz);
    virtual void scale(float sx, float sy, float sz);
    virtual void getScale(jrt::Ref<jrt::Array<float>> xyz);
    virtual void setTranslation(float tx, float ty, float tz);
    virtual void translate(float tx, float ty, float tz);
    virtual void getTranslation(jrt::Ref<jrt::Array<float>> xyz);
    virtual void setTransform(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void getTransform(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void getCompositeTransform(jrt::Ref<javax::microedition::m3g::Transform> transform);
    static void _setOrientation(int64_t handle, float angle, float ax, float ay, float az, bool absolute);
    static void _preRotate(int64_t handle, float angle, float ax, float ay, float az);
    static void _getOrientation(int64_t handle, jrt::Ref<jrt::Array<float>> angleAxis);
    static void _setScale(int64_t handle, float sx, float sy, float sz, bool absolute);
    static void _getScale(int64_t handle, jrt::Ref<jrt::Array<float>> scale);
    static void _setTranslation(int64_t handle, float tx, float ty, float tz, bool absolute);
    static void _getTranslation(int64_t handle, jrt::Ref<jrt::Array<float>> translation);
    static void _setTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _getTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _getComposite(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Node : public javax::microedition::m3g::Transformable {
public:
    static int32_t NONE;
    static int32_t ORIGIN;
    static int32_t X_AXIS;
    static int32_t Y_AXIS;
    static int32_t Z_AXIS;
    jrt::Ref<javax::microedition::m3g::Node> parent{};
    jrt::Ref<javax::microedition::m3g::Node> zRef{};
    jrt::Ref<javax::microedition::m3g::Node> yRef{};
    void __init(int64_t handle);
    virtual jrt::Ref<javax::microedition::m3g::Node> getParent();
    virtual bool getTransformTo(jrt::Ref<javax::microedition::m3g::Node> target, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void setAlignment(jrt::Ref<javax::microedition::m3g::Node> zReference, int32_t zTarget, jrt::Ref<javax::microedition::m3g::Node> yReference, int32_t yTarget);
    virtual void setAlphaFactor(float alphaFactor);
    virtual float getAlphaFactor();
    virtual void setRenderingEnable(bool enable);
    virtual bool isRenderingEnabled();
    virtual void setPickingEnable(bool enable);
    virtual bool isPickingEnabled();
    virtual void setScope(int32_t id);
    virtual int32_t getScope();
    virtual void align(jrt::Ref<javax::microedition::m3g::Node> reference);
    virtual jrt::Ref<javax::microedition::m3g::Node> getAlignmentReference(int32_t axis);
    virtual int32_t getAlignmentTarget(int32_t axis);
    virtual void setParent(jrt::Ref<javax::microedition::m3g::Node> parent);
    static bool _getTransformTo(int64_t handle, int64_t hTarget, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _align(int64_t handle, int64_t refHandle);
    static void _setAlignment(int64_t handle, int64_t hZReference, int32_t zTarget, int64_t hYReference, int32_t yTarget);
    static void _setAlphaFactor(int64_t handle, float alphaFactor);
    static float _getAlphaFactor(int64_t handle);
    static void _enable(int64_t handle, int32_t which, bool enable);
    static bool _isEnabled(int64_t handle, int32_t which);
    static void _setScope(int64_t handle, int32_t id);
    static int32_t _getScope(int64_t handle);
    static int64_t _getParent(int64_t handle);
    static int64_t _getZRef(int64_t handle);
    static int64_t _getYRef(int64_t handle);
    static int32_t _getSubtreeSize(int64_t handle);
    static int32_t _getAlignmentTarget(int64_t handle, int32_t axis);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Camera : public javax::microedition::m3g::Node {
public:
    static int32_t GENERIC;
    static int32_t PARALLEL;
    static int32_t PERSPECTIVE;
    void __init();
    void __init(int64_t handle);
    virtual void setParallel(float height, float aspectRatio, float near_, float far_);
    virtual void setPerspective(float fovy, float aspectRatio, float near_, float far_);
    virtual void setGeneric(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual int32_t getProjection(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual int32_t getProjection(jrt::Ref<jrt::Array<float>> params);
    static int64_t _ctor(int64_t hInterface);
    static void _setParallel(int64_t handle, float height, float aspectRatio, float near_, float far_);
    static void _setPerspective(int64_t handle, float fovy, float aspectRatio, float near_, float far_);
    static void _setGeneric(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static int32_t _getProjectionAsTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static int32_t _getProjectionAsParams(int64_t handle, jrt::Ref<jrt::Array<float>> params);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class CompositingMode : public javax::microedition::m3g::Object3D {
public:
    static int32_t ALPHA;
    static int32_t ALPHA_ADD;
    static int32_t MODULATE;
    static int32_t MODULATE_X2;
    static int32_t REPLACE;
    void __init();
    void __init(int64_t handle);
    virtual void setBlending(int32_t mode);
    virtual int32_t getBlending();
    virtual void setAlphaThreshold(float threshold);
    virtual float getAlphaThreshold();
    virtual void setAlphaWriteEnable(bool enable);
    virtual bool isAlphaWriteEnabled();
    virtual void setColorWriteEnable(bool enable);
    virtual bool isColorWriteEnabled();
    virtual void setDepthWriteEnable(bool enable);
    virtual bool isDepthWriteEnabled();
    virtual void setDepthTestEnable(bool enable);
    virtual bool isDepthTestEnabled();
    virtual void setDepthOffset(float factor, float units);
    virtual float getDepthOffsetFactor();
    virtual float getDepthOffsetUnits();
    static int64_t _ctor(int64_t hInterface);
    static void _setBlending(int64_t handle, int32_t mode);
    static int32_t _getBlending(int64_t handle);
    static void _setAlphaThreshold(int64_t handle, float threshold);
    static float _getAlphaThreshold(int64_t handle);
    static void _setAlphaWriteEnable(int64_t handle, bool enable);
    static bool _isAlphaWriteEnabled(int64_t handle);
    static void _enableDepthTest(int64_t handle, bool enable);
    static bool _isDepthTestEnabled(int64_t handle);
    static void _enableDepthWrite(int64_t handle, bool enable);
    static bool _isDepthWriteEnabled(int64_t handle);
    static void _enableColorWrite(int64_t handle, bool enable);
    static bool _isColorWriteEnabled(int64_t handle);
    static void _setDepthOffset(int64_t handle, float factor, float units);
    static float _getDepthOffsetFactor(int64_t handle);
    static float _getDepthOffsetUnits(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Defs : public java::lang::Object {
public:
    static bool supportDithering;
    static bool supportTrueColor;
    static bool supportAntialiasing;
    static bool supportMipmapping;
    static bool supportPerspectiveCorrection;
    static bool supportLocalCameraLighting;
    static int32_t MAX_LIGHTS;
    static int32_t MAX_TEXTURE_DIMENSION;
    static int32_t MAX_TRANSFORMS_PER_VERTEX;
    static int32_t MAX_VIEWPORT_WIDTH;
    static int32_t MAX_VIEWPORT_HEIGHT;
    static int32_t MAX_VIEWPORT_DIMENSION;
    static int32_t NUM_TEXTURE_UNITS;
    static int32_t GET_POSITIONS;
    static int32_t GET_NORMALS;
    static int32_t GET_COLORS;
    static int32_t GET_TEXCOORDS0;
    static int32_t GET_CROPX;
    static int32_t GET_CROPY;
    static int32_t GET_CROPWIDTH;
    static int32_t GET_CROPHEIGHT;
    static int32_t GET_MODEX;
    static int32_t GET_MODEY;
    static int32_t SETGET_COLORCLEAR;
    static int32_t SETGET_DEPTHCLEAR;
    static int32_t GET_NEAR;
    static int32_t GET_FAR;
    static int32_t SETGET_RENDERING;
    static int32_t SETGET_PICKING;
    static int32_t GET_CONSTANT;
    static int32_t GET_LINEAR;
    static int32_t GET_QUADRATIC;
    void __init();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Fog : public javax::microedition::m3g::Object3D {
public:
    static int32_t EXPONENTIAL;
    static int32_t LINEAR;
    void __init();
    void __init(int64_t handle);
    virtual void setMode(int32_t mode);
    virtual int32_t getMode();
    virtual void setLinear(float near_, float far_);
    virtual float getNearDistance();
    virtual float getFarDistance();
    virtual void setDensity(float density);
    virtual float getDensity();
    virtual void setColor(int32_t RGB);
    virtual int32_t getColor();
    static int64_t _ctor(int64_t hInterface);
    static void _setMode(int64_t handle, int32_t mode);
    static int32_t _getMode(int64_t handle);
    static void _setLinear(int64_t handle, float near_, float far_);
    static float _getDistance(int64_t handle, int32_t which);
    static void _setDensity(int64_t handle, float density);
    static float _getDensity(int64_t handle);
    static void _setColor(int64_t handle, int32_t RGB);
    static int32_t _getColor(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D : public java::lang::Object {
public:
    static int32_t ANTIALIAS;
    static int32_t DITHER;
    static int32_t TRUE_COLOR;
    static int32_t OVERWRITE;
    static jrt::Ref<javax::microedition::m3g::Graphics3D> s_instance;
    int64_t handle{};
    jrt::Ref<java::nio::ByteBuffer> buffer{};
    int32_t cur_width{};
    int32_t cur_height{};
    int32_t targetScale{};
    int32_t targetW{};
    int32_t targetH{};
    int32_t clipGX{};
    int32_t clipGY{};
    int32_t clipGW{};
    int32_t clipGH{};
    jrt::Ref<javax::microedition::m3g::Camera> camera{};
    jrt::Ref<java::util::Vector> lights{};
    jrt::Ref<java::lang::Object> currentTarget{};
    int32_t offsetX{};
    int32_t offsetY{};
    int32_t hints{};
    bool depthEnabled{};
    jrt::Ref<javax::microedition::m3g::Graphics3D_Destroyer> destroyer{};
    jrt::Ref<javax::microedition::m3g::Interface> iInterface{};
    bool iIsImageTarget{};
    bool iIsProperRenderer{};
    bool iNativeInitialized{};
    int64_t bindStartNanos{};
    jrt::Ref<org::deep3d::gl::M3GTargets_TexSlot> texSlot{};
    jrt::Ref<jrt::Array<int32_t>> texInfo{};
    static jrt::Ref<javax::microedition::m3g::Graphics3D> getInstance();
    static void initGraphics3D();
    void __init();
    virtual void bindTarget(jrt::Ref<java::lang::Object> target);
    virtual void bindTarget(jrt::Ref<java::lang::Object> target, bool depth, int32_t flags);
    virtual void releaseTarget();
    virtual void setViewport(int32_t x, int32_t y, int32_t width, int32_t height);
    virtual void clear(jrt::Ref<javax::microedition::m3g::Background> background);
    virtual void render(jrt::Ref<javax::microedition::m3g::World> world);
    virtual void render(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> primitives, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void render(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> primitives, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Transform> transform, int32_t scope);
    virtual void render(jrt::Ref<javax::microedition::m3g::Node> node, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void setCamera(jrt::Ref<javax::microedition::m3g::Camera> camera, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual int32_t addLight(jrt::Ref<javax::microedition::m3g::Light> light, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void setLight(int32_t index, jrt::Ref<javax::microedition::m3g::Light> light, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void resetLights();
    static jrt::Ref<java::util::Hashtable> getProperties();
    virtual void setDepthRange(float near_, float far_);
    virtual jrt::Ref<javax::microedition::m3g::Camera> getCamera(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual float getDepthRangeFar();
    virtual float getDepthRangeNear();
    virtual jrt::Ref<javax::microedition::m3g::Light> getLight(int32_t index, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual int32_t getLightCount();
    virtual jrt::Ref<java::lang::Object> getTarget();
    virtual int32_t getViewportHeight();
    virtual int32_t getViewportWidth();
    virtual int32_t getViewportX();
    virtual int32_t getViewportY();
    virtual int32_t getHints();
    virtual bool isDepthBufferEnabled();
    void integrityCheck();
    bool initNativePeer();
    static int64_t _ctor(int64_t hInterface);
    static void _addRef(int64_t hObject);
    static int32_t _addLight(int64_t handle, int64_t hLight, jrt::Ref<jrt::Array<int8_t>> transform);
    static bool _bindGraphics(int64_t handle, int64_t surfaceHandle, int32_t width, int32_t height, int32_t clipX, int32_t clipY, int32_t clipW, int32_t clipH, bool depth, int32_t hintBits, bool aIsProperRenderer, jrt::Ref<java::nio::ByteBuffer> pixels);
    static void _bindImage(int64_t handle, int64_t imgHandle, bool depth, int32_t hintBits);
    static void _releaseGraphics(int64_t handle, int64_t surfaceHandle, bool aIsImageTarget, bool aIsProperRenderer, jrt::Ref<java::nio::ByteBuffer> pixels);
    static void _releaseImage(int64_t handle);
    static void _resetLights(int64_t handle);
    static void _clear(int64_t handle, int64_t hBackground);
    static void _render(int64_t handle, int64_t hVtxBuffer, int64_t hIdxBuffer, int64_t hAppearance, jrt::Ref<jrt::Array<int8_t>> transform, int32_t scope);
    static void _renderNode(int64_t handle, int64_t hNode, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _renderWorld(int64_t handle, int64_t hWorld);
    static void _setCamera(int64_t handle, int64_t hCamera, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _setViewport(int64_t handle, int32_t x, int32_t y, int32_t width, int32_t height);
    static void _setLight(int64_t handle, int32_t index, int64_t hLight, jrt::Ref<jrt::Array<int8_t>> transform);
    static void _setDepthRange(int64_t handle, float near_, float far_);
    static void _getViewTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform);
    static int64_t _getCamera(int64_t handle);
    static int64_t _getLightTransform(int64_t handle, int32_t index, jrt::Ref<jrt::Array<int8_t>> transform);
    static int32_t _getLightCount(int64_t handle);
    static float _getDepthRangeNear(int64_t handle);
    static float _getDepthRangeFar(int64_t handle);
    static int32_t _getViewportX(int64_t handle);
    static int32_t _getViewportY(int64_t handle);
    static int32_t _getViewportWidth(int64_t handle);
    static int32_t _getViewportHeight(int64_t handle);
    static bool _isAASupported(int64_t handle);
    static bool _isProperRenderer();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D_Destroyer : public java::lang::Object {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    jrt::Ref<javax::microedition::m3g::Graphics3D> target{};
    void __init(jrt::Ref<javax::microedition::m3g::Graphics3D> g3d);
    virtual void shuttingDown();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class M3gRunnable : public java::lang::Object, public virtual java::lang::Runnable {
public:
    jrt::Ref<java::lang::Throwable> e{};
    void __init();
    virtual void run();
    virtual void checkAndThrow();
    virtual void doRun() = 0;
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon1 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    int32_t width{};
    int32_t height{};
    int32_t nClipX{};
    int32_t nClipY{};
    int32_t nClipW{};
    int32_t nClipH{};
    bool finalDepth{};
    int32_t finalFlags{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon2 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    int64_t imageHandle{};
    bool finalDepth{};
    int32_t finalFlags{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon3 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon4 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon5 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    jrt::Ref<javax::microedition::m3g::Background> finalBackground{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon6 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    jrt::Ref<javax::microedition::m3g::World> finalWorld{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon7 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    jrt::Ref<javax::microedition::m3g::VertexBuffer> finalVertices{};
    jrt::Ref<javax::microedition::m3g::IndexBuffer> finalPrimitives{};
    jrt::Ref<javax::microedition::m3g::Appearance> finalAppearance{};
    jrt::Ref<javax::microedition::m3g::Transform> finalTransform{};
    int32_t finalScope{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon8 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    jrt::Ref<javax::microedition::m3g::Node> finalNode{};
    jrt::Ref<javax::microedition::m3g::Transform> finalTransform{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Graphics3D__anon9 : public javax::microedition::m3g::M3gRunnable {
public:
    javax::microedition::m3g::Graphics3D* __outer = nullptr;
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Group : public javax::microedition::m3g::Node {
public:
    jrt::Ref<java::util::Vector> children{};
    void __init();
    void __init(int64_t handle);
    virtual void addChild(jrt::Ref<javax::microedition::m3g::Node> child);
    virtual void removeChild(jrt::Ref<javax::microedition::m3g::Node> child);
    virtual int32_t getChildCount();
    virtual jrt::Ref<javax::microedition::m3g::Node> getChild(int32_t index);
    virtual bool pick(int32_t mask, float ox, float oy, float oz, float dx, float dy, float dz, jrt::Ref<javax::microedition::m3g::RayIntersection> ri);
    virtual bool pick(int32_t mask, float x, float y, jrt::Ref<javax::microedition::m3g::Camera> camera, jrt::Ref<javax::microedition::m3g::RayIntersection> ri);
    void linkChild(jrt::Ref<javax::microedition::m3g::Node> child);
    void detachChild(jrt::Ref<javax::microedition::m3g::Node> child);
    static int64_t _ctor(int64_t hInterface);
    static void _addChild(int64_t handle, int64_t hNode);
    static void _removeChild(int64_t handle, int64_t hNode);
    static int32_t _getChildCount(int64_t handle);
    static int64_t _getChild(int64_t handle, int32_t index);
    static int64_t _pick3D(int64_t handle, int32_t mask, jrt::Ref<jrt::Array<float>> ray, jrt::Ref<jrt::Array<float>> result);
    static int64_t _pick2D(int64_t handle, int32_t mask, float x, float y, int64_t hCamera, jrt::Ref<jrt::Array<float>> result);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Image2D : public javax::microedition::m3g::Object3D {
public:
    static int32_t ALPHA;
    static int32_t LUMINANCE;
    static int32_t LUMINANCE_ALPHA;
    static int32_t RGB;
    static int32_t RGBA;
    static int64_t tempHandle;
    void __init(int32_t format, jrt::Ref<java::lang::Object> image);
    void __init(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image);
    void __init(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette);
    void __init(int32_t format, int32_t width, int32_t height);
    void __init(int64_t handle);
    virtual void set(int32_t x, int32_t y, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image);
    virtual bool isMutable();
    virtual int32_t getFormat();
    virtual int32_t getWidth();
    virtual int32_t getHeight();
    static int32_t getBytesPerPixel(int32_t format);
    static int64_t checkAndCreate(int32_t format, jrt::Ref<java::lang::Object> image);
    static int64_t createHandle(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image);
    static int64_t createHandle(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette);
    static int64_t createHandle(int32_t format, int32_t width, int32_t height);
    static int64_t _ctorSizePixels(int64_t hInterface, int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image);
    static int64_t _ctorSizePixelsPalette(int64_t hInterface, int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette);
    static int64_t _ctorSize(int64_t hInterface, int32_t format, int32_t width, int32_t height);
    static void _set(int64_t handle, int32_t x, int32_t y, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image);
    static bool _isMutable(int64_t handle);
    static int32_t _getFormat(int64_t handle);
    static int32_t _getWidth(int64_t handle);
    static int32_t _getHeight(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Image2D__anon1 : public javax::microedition::m3g::M3gRunnable {
public:
    int32_t finalFormat{};
    int32_t width{};
    int32_t height{};
    jrt::Ref<jrt::Array<int8_t>> byteArr{};
    void __init();
    virtual void doRun();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class IndexBuffer : public javax::microedition::m3g::Object3D {
public:
    void __init(int64_t handle);
    virtual int32_t getIndexCount() = 0;
    virtual void getIndices(jrt::Ref<jrt::Array<int32_t>> indices) = 0;
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class KeyframeSequence : public javax::microedition::m3g::Object3D {
public:
    static int32_t LINEAR;
    static int32_t SLERP;
    static int32_t SPLINE;
    static int32_t SQUAD;
    static int32_t STEP;
    static int32_t CONSTANT;
    static int32_t LOOP;
    void __init(int32_t numKeyframes, int32_t numComponents, int32_t interpolation);
    void __init(int64_t handle);
    virtual void setKeyframe(int32_t index, int32_t time, jrt::Ref<jrt::Array<float>> value);
    virtual void setValidRange(int32_t first, int32_t last);
    virtual void setDuration(int32_t duration);
    virtual int32_t getDuration();
    virtual void setRepeatMode(int32_t mode);
    virtual int32_t getRepeatMode();
    virtual int32_t getComponentCount();
    virtual int32_t getInterpolationType();
    virtual int32_t getKeyframe(int32_t index, jrt::Ref<jrt::Array<float>> value);
    virtual int32_t getKeyframeCount();
    virtual int32_t getValidRangeFirst();
    virtual int32_t getValidRangeLast();
    static int64_t _ctor(int64_t hInterface, int32_t numKeyframes, int32_t numComponents, int32_t interpolation);
    static void _setValidRange(int64_t handle, int32_t first, int32_t last);
    static void _setKeyframe(int64_t handle, int32_t index, int32_t time, jrt::Ref<jrt::Array<float>> value);
    static void _setDuration(int64_t handle, int32_t duration);
    static int32_t _getDuration(int64_t handle);
    static void _setRepeatMode(int64_t handle, int32_t mode);
    static int32_t _getRepeatMode(int64_t handle);
    static int32_t _getComponentCount(int64_t handle);
    static int32_t _getInterpolationType(int64_t handle);
    static int32_t _getKeyframe(int64_t handle, int32_t index, jrt::Ref<jrt::Array<float>> value);
    static int32_t _getKeyframeCount(int64_t handle);
    static int32_t _getValidRangeFirst(int64_t handle);
    static int32_t _getValidRangeLast(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Light : public javax::microedition::m3g::Node {
public:
    static int32_t AMBIENT;
    static int32_t DIRECTIONAL;
    static int32_t OMNI;
    static int32_t SPOT;
    void __init();
    void __init(int64_t handle);
    virtual void setIntensity(float intensity);
    virtual float getIntensity();
    virtual void setColor(int32_t RGB);
    virtual int32_t getColor();
    virtual void setMode(int32_t mode);
    virtual int32_t getMode();
    virtual void setSpotAngle(float angle);
    virtual float getSpotAngle();
    virtual void setSpotExponent(float exponent);
    virtual float getSpotExponent();
    virtual void setAttenuation(float constant, float linear, float quadratic);
    virtual float getConstantAttenuation();
    virtual float getLinearAttenuation();
    virtual float getQuadraticAttenuation();
    static int64_t _ctor(int64_t hInterface);
    static void _setIntensity(int64_t handle, float intensity);
    static float _getIntensity(int64_t handle);
    static void _setColor(int64_t handle, int32_t RGB);
    static int32_t _getColor(int64_t handle);
    static void _setMode(int64_t handle, int32_t mode);
    static int32_t _getMode(int64_t handle);
    static void _setSpotAngle(int64_t handle, float angle);
    static float _getSpotAngle(int64_t handle);
    static void _setSpotExponent(int64_t handle, float exponent);
    static float _getSpotExponent(int64_t handle);
    static void _setAttenuation(int64_t handle, float constant, float linear, float quadratic);
    static float _getAttenuation(int64_t handle, int32_t type);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Loader : public java::lang::Object {
public:
    static jrt::Ref<jrt::Array<int8_t>> M3G_FILE_IDENTIFIER;
    static jrt::Ref<jrt::Array<int8_t>> PNG_FILE_IDENTIFIER;
    static int32_t PNG_IHDR;
    static int32_t PNG_tRNS;
    static int32_t PNG_IDAT;
    static jrt::Ref<jrt::Array<int8_t>> JPEG_FILE_IDENTIFIER;
    static int32_t JPEG_JFIF;
    static int32_t JPEG_SOFn_DELTA;
    static int32_t JPEG_INVALID_COLOUR_FORMAT;
    static int32_t INVALID_HEADER_TYPE;
    static int32_t M3G_TYPE;
    static int32_t PNG_TYPE;
    static int32_t JPEG_TYPE;
    static int32_t MAX_IDENTIFIER_LENGTH;
    static int32_t AVG_HEADER_SEC_LENGTH;
    static int32_t AVG_XREF_SEC_LENGTH;
    int64_t handle{};
    jrt::Ref<java::util::Vector> iLoadedObjects{};
    jrt::Ref<java::util::Vector> iFileHistory{};
    jrt::Ref<java::lang::String> iResourceName{};
    jrt::Ref<java::lang::String> iParentResourceName{};
    int32_t iTotalFileSize{};
    int32_t iBytesRead{};
    jrt::Ref<jrt::Array<int8_t>> iStreamData{};
    int32_t iStreamOffset{};
    jrt::Ref<javax::microedition::m3g::Interface> iInterface{};
    virtual void finalize();
    void __init();
    void __init(jrt::Ref<java::util::Vector> aFileHistory, jrt::Ref<java::lang::String> aParentResourceName);
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> load(jrt::Ref<java::lang::String> name);
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> load(jrt::Ref<jrt::Array<int8_t>> data, int32_t offset);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> loadFromStream(jrt::Ref<java::lang::String> aName);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> loadFromByteArray(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> doLoad(jrt::Ref<java::io::InputStream> aStream, int32_t aType);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> loadPNG(jrt::Ref<java::io::InputStream> aStream);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> loadJPEG(jrt::Ref<java::io::InputStream> aStream);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> buildImage2D(int32_t aColourFormat);
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> loadM3G(jrt::Ref<java::io::InputStream> aStream);
    void setUserObjects();
    void loadExternalRefs(jrt::Ref<java::io::InputStream> aStream);
    jrt::Ref<javax::microedition::m3g::Object3D> loadObject(jrt::Ref<javax::microedition::m3g::Loader_CountedInputStream> aStream);
    static int32_t readByte(jrt::Ref<java::io::InputStream> aStream);
    static bool readBoolean(jrt::Ref<java::io::InputStream> aStream);
    static int32_t readUInt32(jrt::Ref<java::io::InputStream> aStream);
    static jrt::Ref<java::lang::String> readString(jrt::Ref<java::io::InputStream> aStream);
    int32_t getIdentifierType(jrt::Ref<java::io::InputStream> aStream);
    static int32_t getIdentifierType(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset);
    static bool parseIdentifier(jrt::Ref<jrt::Array<int8_t>> aData, int32_t aOffset, jrt::Ref<jrt::Array<int8_t>> aIdentifier);
    bool inFileHistory(jrt::Ref<java::lang::String> name);
    jrt::Ref<java::io::InputStream> getHttpInputStream(jrt::Ref<java::lang::String> name);
    jrt::Ref<java::io::InputStream> getInputStream(jrt::Ref<java::lang::String> name);
    void doFinalize();
    void registeredFinalize();
    static bool _inflate(jrt::Ref<jrt::Array<int8_t>> data, jrt::Ref<jrt::Array<int8_t>> buffer);
    static int64_t _ctor(int64_t handle);
    static int32_t _decodeData(int64_t handle, int32_t offset, jrt::Ref<jrt::Array<int8_t>> data);
    static void _setExternalReferences(int64_t handle, jrt::Ref<jrt::Array<int64_t>> references);
    static int32_t _getLoadedObjects(int64_t handle, jrt::Ref<jrt::Array<int64_t>> objects);
    static int32_t _getObjectsWithUserParameters(int64_t handle, jrt::Ref<jrt::Array<int64_t>> objects);
    static int32_t _getNumUserParameters(int64_t handle, int32_t obj);
    static int32_t _getUserParameter(int64_t handle, int32_t obj, int32_t index, jrt::Ref<jrt::Array<int8_t>> data);
    ~Loader() override;
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Loader_PeekInputStream : public java::io::InputStream {
public:
    javax::microedition::m3g::Loader* __outer = nullptr;
    using java::io::InputStream::read;
    jrt::Ref<jrt::Array<int32_t>> iPeekBuffer{};
    jrt::Ref<java::io::InputStream> iStream{};
    int32_t iBuffered{};
    int32_t iCounter{};
    void __init(jrt::Ref<java::io::InputStream> aStream, int32_t aLength);
    virtual int32_t read();
    virtual void increasePeekBuffer(int32_t aLength);
    virtual int32_t available();
    virtual void close();
    virtual void rewind();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Loader_CountedInputStream : public java::io::InputStream {
public:
    javax::microedition::m3g::Loader* __outer = nullptr;
    using java::io::InputStream::read;
    jrt::Ref<java::io::InputStream> iStream{};
    int32_t iCounter{};
    void __init(jrt::Ref<java::io::InputStream> aStream);
    virtual int32_t read();
    virtual void resetCounter();
    virtual int32_t getCounter();
    virtual void close();
    virtual int32_t available();
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Material : public javax::microedition::m3g::Object3D {
public:
    static int32_t AMBIENT;
    static int32_t DIFFUSE;
    static int32_t EMISSIVE;
    static int32_t SPECULAR;
    void __init();
    void __init(int64_t handle);
    virtual void setColor(int32_t target, int32_t ARGB);
    virtual int32_t getColor(int32_t target);
    virtual void setShininess(float shininess);
    virtual float getShininess();
    virtual void setVertexColorTrackingEnable(bool enable);
    virtual bool isVertexColorTrackingEnabled();
    static int64_t _ctor(int64_t hInstance);
    static void _setColor(int64_t handle, int32_t target, int32_t ARGB);
    static int32_t _getColor(int64_t handle, int32_t target);
    static void _setShininess(int64_t handle, float shininess);
    static float _getShininess(int64_t handle);
    static void _setVertexColorTrackingEnable(int64_t handle, bool enable);
    static bool _isVertexColorTrackingEnabled(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Mesh : public javax::microedition::m3g::Node {
public:
    jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles{};
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> tempTrianglesArray;
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> tempAppearanceArray;
    static jrt::Ref<javax::microedition::m3g::IndexBuffer> tempTriangles;
    static jrt::Ref<javax::microedition::m3g::Appearance> tempAppearance;
    void __init(int64_t handle);
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances);
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    virtual void setAppearance(int32_t index, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    virtual jrt::Ref<javax::microedition::m3g::Appearance> getAppearance(int32_t index);
    virtual jrt::Ref<javax::microedition::m3g::IndexBuffer> getIndexBuffer(int32_t index);
    virtual jrt::Ref<javax::microedition::m3g::VertexBuffer> getVertexBuffer();
    virtual int32_t getSubmeshCount();
    static void verifyParams(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances);
    static void verifyParams(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles);
    virtual void updateReferences();
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances);
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    static int64_t _ctor(int64_t hInstance, int64_t hVertices, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances);
    static void _setAppearance(int64_t handle, int32_t index, int64_t hAppearance);
    static int64_t _getAppearance(int64_t handle, int32_t index);
    static int64_t _getIndexBuffer(int64_t handle, int32_t index);
    static int64_t _getVertexBuffer(int64_t handle);
    static int32_t _getSubmeshCount(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class MorphingMesh : public javax::microedition::m3g::Mesh {
public:
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets{};
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> tempTrianglesArray;
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> tempAppearanceArray;
    static jrt::Ref<javax::microedition::m3g::IndexBuffer> tempTriangles;
    static jrt::Ref<javax::microedition::m3g::Appearance> tempAppearance;
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances);
    void __init(int64_t handle);
    virtual jrt::Ref<javax::microedition::m3g::VertexBuffer> getMorphTarget(int32_t index);
    virtual int32_t getMorphTargetCount();
    virtual void setWeights(jrt::Ref<jrt::Array<float>> weights);
    virtual void getWeights(jrt::Ref<jrt::Array<float>> weights);
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances);
    static int64_t _ctor(int64_t hInstance, int64_t handle, jrt::Ref<jrt::Array<int64_t>> hTargets, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances);
    static void _setWeights(int64_t handle, jrt::Ref<jrt::Array<float>> weights);
    static void _getWeights(int64_t handle, jrt::Ref<jrt::Array<float>> weights);
    static int64_t _getMorphTarget(int64_t handle, int32_t index);
    static int32_t _getMorphTargetCount(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class PolygonMode : public javax::microedition::m3g::Object3D {
public:
    static int32_t CULL_BACK;
    static int32_t CULL_FRONT;
    static int32_t CULL_NONE;
    static int32_t SHADE_FLAT;
    static int32_t SHADE_SMOOTH;
    static int32_t WINDING_CCW;
    static int32_t WINDING_CW;
    void __init();
    void __init(int64_t handle);
    virtual void setCulling(int32_t mode);
    virtual int32_t getCulling();
    virtual void setWinding(int32_t mode);
    virtual int32_t getWinding();
    virtual void setShading(int32_t mode);
    virtual int32_t getShading();
    virtual void setTwoSidedLightingEnable(bool enable);
    virtual bool isTwoSidedLightingEnabled();
    virtual void setLocalCameraLightingEnable(bool enable);
    virtual void setPerspectiveCorrectionEnable(bool enable);
    virtual bool isLocalCameraLightingEnabled();
    virtual bool isPerspectiveCorrectionEnabled();
    static int64_t _ctor(int64_t hInterface);
    static void _setLocalCameraLightingEnable(int64_t handle, bool enable);
    static void _setPerspectiveCorrectionEnable(int64_t handle, bool enable);
    static void _setCulling(int64_t handle, int32_t mode);
    static int32_t _getCulling(int64_t handle);
    static void _setWinding(int64_t handle, int32_t mode);
    static int32_t _getWinding(int64_t handle);
    static void _setShading(int64_t handle, int32_t mode);
    static int32_t _getShading(int64_t handle);
    static void _setTwoSidedLightingEnable(int64_t handle, bool enable);
    static bool _isTwoSidedLightingEnabled(int64_t handle);
    static bool _isLocalCameraLightingEnabled(int64_t handle);
    static bool _isPerspectiveCorrectionEnabled(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class RayIntersection : public java::lang::Object {
public:
    jrt::Ref<javax::microedition::m3g::Node> intersected{};
    float distance{};
    int32_t submeshIndex{};
    jrt::Ref<jrt::Array<float>> textureS{};
    jrt::Ref<jrt::Array<float>> textureT{};
    jrt::Ref<jrt::Array<float>> normal{};
    jrt::Ref<jrt::Array<float>> ray{};
    void __init();
    virtual jrt::Ref<javax::microedition::m3g::Node> getIntersected();
    virtual float getDistance();
    virtual int32_t getSubmeshIndex();
    virtual float getTextureS(int32_t index);
    virtual float getTextureT(int32_t index);
    virtual float getNormalX();
    virtual float getNormalY();
    virtual float getNormalZ();
    virtual void getRay(jrt::Ref<jrt::Array<float>> ray);
    static jrt::Ref<jrt::Array<float>> createResult();
    virtual void fill(int64_t hIntersected, jrt::Ref<jrt::Array<float>> result);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class SkinnedMesh : public javax::microedition::m3g::Mesh {
public:
    jrt::Ref<javax::microedition::m3g::Group> skeleton{};
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> tempTrianglesArray;
    static jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> tempAppearanceArray;
    static jrt::Ref<javax::microedition::m3g::IndexBuffer> tempTriangles;
    static jrt::Ref<javax::microedition::m3g::Appearance> tempAppearance;
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances, jrt::Ref<javax::microedition::m3g::Group> skeleton);
    void __init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Group> skeleton);
    void __init(int64_t handle);
    virtual void addTransform(jrt::Ref<javax::microedition::m3g::Node> bone, int32_t weight, int32_t firstVertex, int32_t numVertices);
    virtual jrt::Ref<javax::microedition::m3g::Group> getSkeleton();
    virtual void getBoneTransform(jrt::Ref<javax::microedition::m3g::Node> bone, jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual int32_t getBoneVertices(jrt::Ref<javax::microedition::m3g::Node> bone, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<float>> weights);
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances, jrt::Ref<javax::microedition::m3g::Group> skeleton);
    static int64_t createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Group> skeleton);
    static int64_t _ctor(int64_t hInstance, int64_t hVertices, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances, int64_t hSkeleton);
    static void _addTransform(int64_t handle, int64_t hBone, int32_t weight, int32_t firstVertex, int32_t numVertices);
    static int64_t _getSkeleton(int64_t handle);
    static void _getBoneTransform(int64_t handle, int64_t hBone, jrt::Ref<jrt::Array<int8_t>> transform);
    static int32_t _getBoneVertices(int64_t handle, int64_t hBone, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<float>> weights);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Sprite3D : public javax::microedition::m3g::Node {
public:
    jrt::Ref<javax::microedition::m3g::Image2D> image{};
    jrt::Ref<javax::microedition::m3g::Appearance> appearance{};
    void __init(bool scaled, jrt::Ref<javax::microedition::m3g::Image2D> image, jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    void __init(int64_t handle);
    virtual bool isScaled();
    virtual void setAppearance(jrt::Ref<javax::microedition::m3g::Appearance> appearance);
    virtual jrt::Ref<javax::microedition::m3g::Appearance> getAppearance();
    virtual void setImage(jrt::Ref<javax::microedition::m3g::Image2D> image);
    virtual jrt::Ref<javax::microedition::m3g::Image2D> getImage();
    virtual void setCrop(int32_t cropX, int32_t cropY, int32_t width, int32_t height);
    virtual int32_t getCropX();
    virtual int32_t getCropY();
    virtual int32_t getCropWidth();
    virtual int32_t getCropHeight();
    static int64_t _ctor(int64_t hInterface, bool scaled, int64_t hImage, int64_t hAppearance);
    static bool _isScaled(int64_t handle);
    static void _setAppearance(int64_t handle, int64_t hAppearance);
    static void _setImage(int64_t handle, int64_t hImage);
    static void _setCrop(int64_t handle, int32_t cropX, int32_t cropY, int32_t width, int32_t height);
    static int32_t _getCrop(int64_t handle, int32_t which);
    static int64_t _getAppearance(int64_t handle);
    static int64_t _getImage(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Texture2D : public javax::microedition::m3g::Transformable {
public:
    static int32_t FILTER_BASE_LEVEL;
    static int32_t FILTER_LINEAR;
    static int32_t FILTER_NEAREST;
    static int32_t FUNC_ADD;
    static int32_t FUNC_BLEND;
    static int32_t FUNC_DECAL;
    static int32_t FUNC_MODULATE;
    static int32_t FUNC_REPLACE;
    static int32_t WRAP_CLAMP;
    static int32_t WRAP_REPEAT;
    jrt::Ref<javax::microedition::m3g::Image2D> image{};
    void __init(jrt::Ref<javax::microedition::m3g::Image2D> image);
    void __init(int64_t handle);
    virtual void setImage(jrt::Ref<javax::microedition::m3g::Image2D> image);
    virtual jrt::Ref<javax::microedition::m3g::Image2D> getImage();
    virtual void setFiltering(int32_t levelFilter, int32_t imageFilter);
    virtual void setWrapping(int32_t wrapS, int32_t wrapT);
    virtual int32_t getWrappingS();
    virtual int32_t getWrappingT();
    virtual void setBlending(int32_t func);
    virtual int32_t getBlending();
    virtual void setBlendColor(int32_t RGB);
    virtual int32_t getBlendColor();
    virtual int32_t getImageFilter();
    virtual int32_t getLevelFilter();
    static int64_t _ctor(int64_t hInterface, int64_t imageHandle);
    static void _setImage(int64_t handle, int64_t imageHandle);
    static int64_t _getImage(int64_t handle);
    static void _setFiltering(int64_t handle, int32_t levelFilter, int32_t imageFilter);
    static void _setWrapping(int64_t handle, int32_t wrapS, int32_t wrapT);
    static int32_t _getWrappingS(int64_t handle);
    static int32_t _getWrappingT(int64_t handle);
    static void _setBlending(int64_t handle, int32_t func);
    static int32_t _getBlending(int64_t handle);
    static void _setBlendColor(int64_t handle, int32_t RGB);
    static int32_t _getBlendColor(int64_t handle);
    static int32_t _getImageFilter(int64_t handle);
    static int32_t _getLevelFilter(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class Transform : public java::lang::Object {
public:
    jrt::Ref<jrt::Array<int8_t>> matrix{};
    void __init();
    void __init(jrt::Ref<javax::microedition::m3g::Transform> other);
    virtual void setIdentity();
    virtual void set(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void set(jrt::Ref<jrt::Array<float>> matrix);
    virtual void get(jrt::Ref<jrt::Array<float>> matrix);
    virtual void invert();
    virtual void transpose();
    virtual void postMultiply(jrt::Ref<javax::microedition::m3g::Transform> transform);
    virtual void postScale(float sx, float sy, float sz);
    virtual void postRotate(float angle, float ax, float ay, float az);
    virtual void postRotateQuat(float qx, float qy, float qz, float qw);
    virtual void postTranslate(float tx, float ty, float tz);
    virtual void transform(jrt::Ref<jrt::Array<float>> v);
    virtual void transform(jrt::Ref<javax::microedition::m3g::VertexArray> in, jrt::Ref<jrt::Array<float>> out, bool W);
    static void _mul(jrt::Ref<jrt::Array<int8_t>> prod, jrt::Ref<jrt::Array<int8_t>> left, jrt::Ref<jrt::Array<int8_t>> right);
    static void _setIdentity(jrt::Ref<jrt::Array<int8_t>> matrix);
    static void _setMatrix(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> srcMatrix);
    static void _getMatrix(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> dstMatrix);
    static void _invert(jrt::Ref<jrt::Array<int8_t>> matrix);
    static void _transpose(jrt::Ref<jrt::Array<int8_t>> matrix);
    static void _rotate(jrt::Ref<jrt::Array<int8_t>> matrix, float angle, float ax, float ay, float az);
    static void _rotateQuat(jrt::Ref<jrt::Array<int8_t>> matrix, float qx, float qy, float qz, float qw);
    static void _scale(jrt::Ref<jrt::Array<int8_t>> matrix, float sx, float sy, float sz);
    static void _translate(jrt::Ref<jrt::Array<int8_t>> matrix, float tx, float ty, float tz);
    static void _transformTable(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> v);
    static void _transformArray(jrt::Ref<jrt::Array<int8_t>> matrix, int64_t handle, jrt::Ref<jrt::Array<float>> out, bool W);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class TriangleStripArray : public javax::microedition::m3g::IndexBuffer {
public:
    void __init(int32_t firstIndex, jrt::Ref<jrt::Array<int32_t>> stripLengths);
    void __init(jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<int32_t>> stripLengths);
    void __init(int64_t handle);
    virtual int32_t getIndexCount();
    virtual void getIndices(jrt::Ref<jrt::Array<int32_t>> indices);
    static int64_t _createImplicit(int64_t hInterface, int32_t first, jrt::Ref<jrt::Array<int32_t>> lengths);
    static int64_t _createExplicit(int64_t hInterface, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<int32_t>> lengths);
    static int32_t _getIndexCount(int64_t handle);
    static void _getIndices(int64_t handle, jrt::Ref<jrt::Array<int32_t>> indices);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class VertexArray : public javax::microedition::m3g::Object3D {
public:
    void __init(int32_t numVertices, int32_t numComponents, int32_t componentSize);
    void __init(int64_t handle);
    virtual void set(int32_t startIndex, int32_t length, jrt::Ref<jrt::Array<int16_t>> values);
    virtual void set(int32_t startIndex, int32_t length, jrt::Ref<jrt::Array<int8_t>> values);
    virtual void get(int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int8_t>> values);
    virtual void get(int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int16_t>> values);
    virtual int32_t getComponentCount();
    virtual int32_t getComponentType();
    virtual int32_t getVertexCount();
    static int64_t createHandle(int32_t numVertices, int32_t numComponents, int32_t componentSize);
    static int64_t _ctor(int64_t hInterface, int32_t numVertices, int32_t numComponents, int32_t componentSize);
    static void _setByte(int64_t handle, int32_t first, int32_t count, jrt::Ref<jrt::Array<int8_t>> src);
    static void _setShort(int64_t handle, int32_t first, int32_t count, jrt::Ref<jrt::Array<int16_t>> src);
    static void _getByte(int64_t handle, int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int8_t>> values);
    static void _getShort(int64_t handle, int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int16_t>> values);
    static int32_t _getComponentCount(int64_t handle);
    static int32_t _getComponentType(int64_t handle);
    static int32_t _getVertexCount(int64_t handle);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class VertexBuffer : public javax::microedition::m3g::Object3D {
public:
    jrt::Ref<javax::microedition::m3g::VertexArray> positions{};
    jrt::Ref<javax::microedition::m3g::VertexArray> normals{};
    jrt::Ref<javax::microedition::m3g::VertexArray> colors{};
    jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexArray>>> texCoords{};
    void __init();
    void __init(int64_t handle);
    virtual int32_t getVertexCount();
    virtual void setPositions(jrt::Ref<javax::microedition::m3g::VertexArray> positions, float scale, jrt::Ref<jrt::Array<float>> bias);
    virtual void setTexCoords(int32_t index, jrt::Ref<javax::microedition::m3g::VertexArray> texCoords, float scale, jrt::Ref<jrt::Array<float>> bias);
    virtual void setNormals(jrt::Ref<javax::microedition::m3g::VertexArray> normals);
    virtual void setColors(jrt::Ref<javax::microedition::m3g::VertexArray> colors);
    virtual jrt::Ref<javax::microedition::m3g::VertexArray> getPositions(jrt::Ref<jrt::Array<float>> scaleBias);
    virtual jrt::Ref<javax::microedition::m3g::VertexArray> getTexCoords(int32_t index, jrt::Ref<jrt::Array<float>> scaleBias);
    virtual jrt::Ref<javax::microedition::m3g::VertexArray> getNormals();
    virtual jrt::Ref<javax::microedition::m3g::VertexArray> getColors();
    virtual void setDefaultColor(int32_t ARGB);
    virtual int32_t getDefaultColor();
    static int64_t _ctor(int64_t hInterface);
    static void _setColors(int64_t hBuffer, int64_t hArray);
    static void _setNormals(int64_t hBuffer, int64_t hArray);
    static void _setTexCoords(int64_t hBuffer, int32_t unit, int64_t hArray, float scale, jrt::Ref<jrt::Array<float>> bias);
    static void _setVertices(int64_t hBuffer, int64_t hArray, float scale, jrt::Ref<jrt::Array<float>> bias);
    static void _setDefaultColor(int64_t hBuffer, int32_t ARGB);
    static int32_t _getDefaultColor(int64_t hBuffer);
    static int64_t _getArray(int64_t hBuffer, int32_t which, jrt::Ref<jrt::Array<float>> scaleBias);
    static int32_t _getVertexCount(int64_t hBuffer);
    static void __clinit();
};
}

namespace javax::microedition::m3g {
class World : public javax::microedition::m3g::Group {
public:
    jrt::Ref<javax::microedition::m3g::Camera> activeCamera{};
    jrt::Ref<javax::microedition::m3g::Background> background{};
    void __init();
    void __init(int64_t handle);
    virtual void setBackground(jrt::Ref<javax::microedition::m3g::Background> background);
    virtual jrt::Ref<javax::microedition::m3g::Background> getBackground();
    virtual void setActiveCamera(jrt::Ref<javax::microedition::m3g::Camera> camera);
    virtual jrt::Ref<javax::microedition::m3g::Camera> getActiveCamera();
    static int64_t _ctor(int64_t hInterface);
    static void _setActiveCamera(int64_t handle, int64_t hCamera);
    static void _setBackground(int64_t handle, int64_t hBackground);
    static int64_t _getActiveCamera(int64_t handle);
    static int64_t _getBackground(int64_t handle);
    static void __clinit();
};
}

void m3g_clinit();
bool m3g_setStatic(const std::string& cls, const std::string& field, int32_t value);
