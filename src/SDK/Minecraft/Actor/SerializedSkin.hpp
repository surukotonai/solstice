//
// Created by vastrakai on 8/22/2024.
//

#pragma once
#include <SDK/Minecraft/JSON.hpp>
#include <SDK/Minecraft/mce.hpp>

class SemVersion {
public:
    struct any_version_constructor;

    // SemVersion inner types define
    enum class MatchType : int {
        Full = 0x0,
        Partial = 0x1,
        None = 0x2,
    };

    enum class ParseOption : int {
        AllowWildcards = 0x0,
        NoWildcards = 0x1,
    };

    unsigned short      mMajor;
    unsigned short      mMinor;
    unsigned short      mPatch;
    std::string         mPreRelease;
    std::string         mBuildMeta;
    std::string         mFullVersionString;
    bool                mValidVersion;
    bool                mAnyVersion;
};

namespace persona {
    enum class AnimatedTextureType : int {
        None = 0x0,
        Face = 0x1,
        Body32x32 = 0x2,
        Body128x128 = 0x3,
    };

    enum class AnimationExpression : int {
        Linear = 0x0,
        Blinking = 0x1,
    };


    enum class PieceType : int {
        Unknown = 0x0,
        Skeleton = 0x1,
        Body = 0x2,
        Skin = 0x3,
        Bottom = 0x4,
        Feet = 0x5,
        Dress = 0x6,
        Top = 0x7,
        High_Pants = 0x8,
        Hands = 0x9,
        Outerwear = 0xA,
        FacialHair = 0xB,
        Mouth = 0xC,
        Eyes = 0xD,
        Hair = 0xE,
        Hood = 0xF,
        Back = 0x10,
        FaceAccessory = 0x11,
        Head = 0x12,
        Legs = 0x13,
        LeftLeg = 0x14,
        RightLeg = 0x15,
        Arms = 0x16,
        LeftArm = 0x17,
        RightArm = 0x18,
        Capes = 0x19,
        ClassicSkin = 0x1A,
        Emote = 0x1B,
        Unsupported = 0x1C,
        Count = 0x1D,
    };


    class ArmSize
    {
    public:
        // ArmSize inner types define
        enum class Type : int64_t {
            Slim = 0,
            Wide = 1,
            Count = 2,
            Unknown = 3,
        };
    };
};

class AnimatedImageData
{
public:
    persona::AnimatedTextureType mType;
    persona::AnimationExpression mAnimationExpression;
    mce::Image                   mImage;
    float                        mFrames;
};

class TintMapColor
{
public:
    std::array<mce::Color, 4> colors;
};

class SerializedPersonaPieceHandle
{
public:
    std::string        mPieceId;
    persona::PieceType mPieceType;
    int                mPackId;
    bool               mIsDefaultPiece;
    std::string        mProductId;
};

enum class TrustedSkinFlag : int8_t {
	UNSET = 0,
	NO = 1,
	YES = 2,
};
template <typename T0>
class ThreadOwner
{
public:
    T0 Object;
    bool ThreadIdInitialized{};
    std::thread::id ThreadId;
    unsigned int ThreadCheckIndex{};
};
// CYKA BLYAT IDA NAHUI
class SerializedSkinImpl {
public:
    CLASS_FIELD(int32_t, skinWidth, 0x84);
    CLASS_FIELD(int32_t, skinHeight, 0x88);
    CLASS_FIELD(const uint8_t*, skinData, 0xA0); // skinImage + Blob = 0xB8 + 0x8 pointer = 0xC0
public:
    std::string                                          mId;                             // this+0x0
    std::string                                          mFullId;                         // this+0x40
    std::string                                          mResourcePatch;                  // this+0x60
    std::string                                          mDefaultGeometryName;            // this+0x80
    mce::Image                                           mSkinImage;                      // this+0xA0
    mce::Image                                           mCapeImage;                      // this+0xC0
    std::vector<AnimatedImageData>                       mSkinAnimatedImages;             // this+0xE0
    std::optional<MinecraftJson::Value>                  mGeometryData;                   // this+0x100
    SemVersion                                           mGeometryDataEngineVersion;      // this+0x120
    std::optional<MinecraftJson::Value>                  mGeometryDataMutable;            // this+0x128
    std::string                                          mAnimationData;                  // this+0x148
    std::string                                          mCapeId;                         // this+0x168
    std::vector<SerializedPersonaPieceHandle>            mPersonaPieces;                  // this+0x188
    persona::ArmSize::Type                               mArmSizeType;                    // this+0x1A8
    std::unordered_map<persona::PieceType, TintMapColor> mPieceTintColors;                // this+0x1B0
    mce::Color                                           mSkinColor;                      // this+0x1D0
    TrustedSkinFlag                                      mIsTrustedSkin;                  // this+0x1D8
    bool                                                 mIsPremium;                      // this+0x1DC
    bool                                                 mIsPersona;                      // this+0x1DD
    bool                                                 mIsPersonaCapeOnClassicSkin;     // this+0x1DE
    bool                                                 mIsPrimaryUser;                  // this+0x1DF
    bool                                                 mOverridesPlayerAppearance;      // this+0x1E0
};
class SerializedSkin
{
public:
    std::shared_ptr<ThreadOwner<SerializedSkinImpl>> impl;

    void operator= (const SerializedSkin& other) {
        // use memcpy to copy the data
        memcpy(this, &other, sizeof(SerializedSkin));
    }

};


class SerializedSkinBase
{
private:
    template <typename To>
    class ThreadOwner
    {
    public:
        To Object;
        bool ThreadIdInitialized{};
        std::thread::id ThreadId;
        unsigned int ThreadCheckIndex{};
    };
public:
    std::shared_ptr<ThreadOwner<SerializedSkin>> Impl;
};