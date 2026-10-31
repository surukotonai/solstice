//
// Created by vastrakai on 7/5/2024.
//

#include "GameMode.hpp"

float GameMode::getDestroyRate(const Block& block)
{
    static uintptr_t func = SigManager::GameMode_getDestroyRate;
    return MemUtils::callFastcall<float, GameMode*, const Block&>(func, this, block);
}

bool GameMode::baseUseItem(ItemStack* itemStack)
{
    if (!itemStack) return false;
    static uintptr_t func = SigManager::GameMode_baseUseItem;
    return MemUtils::callFastcall<bool, GameMode*, ItemStack*, int>(func, this, itemStack, 0);
}
