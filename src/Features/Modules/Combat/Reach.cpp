//
// Created by alteik on 04/09/2024.
//

#include "Reach.hpp"
#include <SDK/SigManager.hpp>
#include <Utils/Buffer.hpp>
#include <Utils/MemUtils.hpp>

static uintptr_t func = 0x0;

void Reach::onInit() {
    func = SigManager::Reach;

    uintptr_t addr2 = SigManager::BlockReach;
    addr2 += 4;
    int offset2 = *(int*)addr2;
    mBlockReachPtr = (float*)(addr2 + offset2 + 4);
}

void Reach::onEnable() {
    auto* buf = AllocateBuffer((void*)func);
    if (!buf) {
        return;
    }
    uintptr_t adr = (uintptr_t)buf;
    if (adr % alignof(float) != 0) {
        return;
    }
    mCombatPtr = (float*)buf;
    if (!mCombatPtr) {
        return;
    }
    *mCombatPtr = 3.f;

    MemUtils::ReadBytes((void*)func, mOriginalData, sizeof(mOriginalData));
    static auto mov = func + 10;

    auto cr = (int32_t)((uintptr_t)mCombatPtr - (func + 8));
    auto mr = (int32_t)((uintptr_t)mCombatPtr - (mov + 8));
    MemUtils::writeBytes((uintptr_t)func + 4, &cr, sizeof(int32_t));
    MemUtils::writeBytes((uintptr_t)mov + 4, &mr, sizeof(int32_t)); // more better :joy:

    /*

    mDetour = AllocateBuffer((void*)func);
    MemUtils::writeBytes((uintptr_t)mDetour, mDetourBytes, sizeof(mDetourBytes));

    auto toOriginalAddrRip1 = MemUtils::GetRelativeAddress((uintptr_t)mDetour + sizeof(mDetourBytes) + 1, func + 10);

    MemUtils::writeBytes((uintptr_t)mDetour + sizeof(mDetourBytes), "\xE9", 1);
    MemUtils::writeBytes((uintptr_t)mDetour + sizeof(mDetourBytes) + 1, &toOriginalAddrRip1, sizeof(int32_t));

    auto newRelRip1 = MemUtils::GetRelativeAddress(func + 1, (uintptr_t)mDetour + 4);

    MemUtils::writeBytes(func, "\xE9", 1);
    MemUtils::writeBytes(func + 1, &newRelRip1, sizeof(int32_t));
    MemUtils::NopBytes(func + 5, 5);*/

    gFeatureManager->mDispatcher->listen<BaseTickEvent, &Reach::onBaseTickEvent>(this);
}

void Reach::onDisable() {
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &Reach::onBaseTickEvent>(this);
    
    MemUtils::writeBytes(func, mOriginalData, sizeof(mOriginalData));
    FreeBuffer(mCombatPtr);

    //MemUtils::Write((uintptr_t) mBlockReachPtr, 5.7f);
}

void Reach::onBaseTickEvent(class BaseTickEvent &event) {
    if (mCombatPtr) {
        *mCombatPtr = mCombatReach.mValue;
    }
    MemUtils::Write((uintptr_t) mBlockReachPtr, mBlockReach.mValue);
}