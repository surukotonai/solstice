#pragma once
//
// Created by vastrakai on 7/3/2024.
//

#include <optional>
#include <vector>
#include <Utils/MemUtils.hpp>


#include <Utils/Structs.hpp>

class Material
{
public:
    /*
    CLASS_FIELD(int, mType, 0x0);
    CLASS_FIELD(bool, mIsFlammable, 0x4); 
    CLASS_FIELD(bool, mIsNeverBuildable, 0x5);
    CLASS_FIELD(bool, mIsLiquid, 0x6);
    CLASS_FIELD(bool, mIsBlockingMotion, 0xC);
    CLASS_FIELD(bool, mIsBlockingPrecipitation, 0xD);
    CLASS_FIELD(bool, mIsSolid, 0xE);
    CLASS_FIELD(bool, mIsSuperHot, 0xF);*/
    unsigned char mType;
    bool mIsNeverBuildable;
    bool mIsLiquid;
    bool mIsBlockingMotion;
    bool mIsBlockingPrecipitation;
    bool mIsSolid;
    bool mIsSuperHot;

    bool isTopSolid(bool includeWater, bool includeLeaves)
    {
        if (mType == 7) return includeLeaves;
        if (!includeWater) return mIsBlockingMotion;
        if (mType != 5) return mIsBlockingMotion;
        return true;
    }
};
//fuck clang? microsoft?
struct __BlockFlags {
    bool mCanBeOriginalSurface : 1;
    bool mSolid : 1;
    bool mPushesOutItems : 1;
    bool mIgnoreBlockForInsideCubeRenderer : 1;
    bool mIsOpaqueFullBlock : 1;
    bool mShouldRandomTickExtraLayer : 1;
    bool mIsMobPiece : 1;
    bool mCanBeExtraBlock : 1;
};

class BlockLegacy {
public:
    CLASS_FIELD(uintptr_t**, mVfTable, 0x0);
    CLASS_FIELD(std::string, mTileName, OffsetProvider::BlockLegacy_mTileName);
    CLASS_FIELD(std::string, mName, OffsetProvider::BlockLegacy_mName); 
    CLASS_FIELD(Material, mMaterial, OffsetProvider::BlockLegacy_mMaterial);
    CLASS_FIELD(__BlockFlags, _BlockFlags, OffsetProvider::BlockLegacy_BlockFlags);

    uint16_t getBlockId();
    bool mayPlaceOn(glm::ivec3 pos);
    bool isAir();
    AABB getCollisionShape(Block* block, BlockSource* source, BlockPos pos);
};