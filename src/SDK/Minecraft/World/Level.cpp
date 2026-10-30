//
// Created by vastrakai on 7/10/2024.
//

#include "Level.hpp"

#include <SDK/heap_rd.hpp>

#include <libhat.hpp>
#include <SDK/OffsetProvider.hpp>
#include <SDK/Minecraft/Actor/SyncedPlayerMovementSettings.hpp>

std::unordered_map<mce::UUID, PlayerListEntry>* Level::getPlayerList()
{
    static auto vIndex = OffsetProvider::Level_getPlayerList;
    return MemUtils::callVirtualFunc<std::unordered_map<mce::UUID, PlayerListEntry>*>(vIndex, this);
}

HitResult* Level::getHitResult()
{
    /*
    auto unti = hat::member_at<std::shared_ptr<HitResult>>(this, OffsetProvider::Level_mHitResult);
    return &*unti;*/
    
    static auto vIndex = 335;
    return MemUtils::callVirtualFunc<HitResult*>(vIndex, this);
}

SyncedPlayerMovementSettings* Level::getPlayerMovementSettings()
{
    static auto vIndex = OffsetProvider::Level_getPlayerMovementSettings;
    return MemUtils::callVirtualFunc<SyncedPlayerMovementSettings*>(vIndex, this);
}

std::vector<Actor*> Level::getRuntimeActorList()
{
    static auto vIndex = OffsetProvider::Level_getRuntimeActorList;
    std::vector<Actor*> actors;
    MemUtils::callVirtualFunc<std::vector<Actor*>*>(vIndex, this, &actors);
    return actors;

    /*
    //static auto func = SigManager::Level_getRuntimeActorList;
    std::vector<Actor*> actors;
   // MemUtils::callFastcall<void>(func, this, &actors);
    return actors;*/
}

LevelData* Level::getLevelData()
{
    
    return hat::member_at<LevelData*>(this, OffsetProvider::Level_mLevelData);

    /*
    static auto vIndex = OffsetProvider::Level_mLevelData;
    return MemUtils::callVirtualFunc<LevelData*>(vIndex, this);*/
}