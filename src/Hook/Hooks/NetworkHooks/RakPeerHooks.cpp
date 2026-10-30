//
// Created by vastrakai on 7/10/2024.
//

#include "RakPeerHooks.hpp"

#include <Solstice.hpp>
#include <windows.h>
#include <Features/FeatureManager.hpp>
#include <SDK/SigManager.hpp>
#include <Features/Events/PingUpdateEvent.hpp>
#include <Features/Events/RunUpdateCycleEvent.hpp>
#include <Features/Events/SendImmediateEvent.hpp>

#include <SDK/Minecraft/ClientInstance.hpp>

std::unique_ptr<Detour> RakPeerHooks::RunUpdateCycleDetour;
std::unique_ptr<Detour> RakPeerHooks::GetLastPingDetour;
std::unique_ptr<Detour> RakPeerHooks::SendImmediateDetour;

float RakPeerHooks::LastPing;

void* peer = nullptr;

bool RakPeerHooks::runUpdateCycle(void* _this, void* a2)
{
    israknetalive = true;
    if (!peer)
    {
        peer = _this;
        uintptr_t getAveragePingAddr = MemUtils::getAddressByIndex(reinterpret_cast<uintptr_t>(peer), 39); // 1.21.131
        init(getAveragePingAddr);
    }
    auto original = RunUpdateCycleDetour->getOriginal<&runUpdateCycle>();
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return original(_this, a2);

    auto holder = nes::make_holder<RunUpdateCycleEvent>();
    gFeatureManager->mDispatcher->trigger(holder);
    if (holder->isCancelled())
    {
        return false; //idontknow false = correct?
    }

    return original(_this, a2);
}

__int64 RakPeerHooks::getLastPing(void* _this, void* a2)
{
    auto original = GetLastPingDetour->getOriginal<&getLastPing>();
    auto val = original(_this, a2);

    static __int64 lastPing = 0;
    if (lastPing == val) return val;

    auto holder = nes::make_holder<PingUpdateEvent>(val);
    spdlog::trace("RakNet::RakPeer::GetLastPing triggered PingUpdate event [ping={0}]", val);
    gFeatureManager->mDispatcher->trigger(holder);

    lastPing = val;

    return val;
}

uint64_t RakPeerHooks::sendImmediate(uint64_t a1, char* send, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5, uint64_t a6, uint64_t a7, uint64_t a8, uint64_t a9, uint64_t a10)
{
    auto original = SendImmediateDetour->getOriginal<&sendImmediate>();

    auto holder = nes::make_holder<SendImmediateEvent>(a1, send, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    gFeatureManager->mDispatcher->trigger(holder);
    if (holder->isCancelled()) {
        uint8_t id = holder->send[0];
        spdlog::debug("RakNet::RakPeer::SendImmediate cancelled event [id={0}]", id);
        return 0;
    }

    if (holder->mModified)
    {
        spdlog::debug("RakNet::RakPeer::SendImmediate modified event [send={0}]", MemUtils::bytesToHex(holder->send, a2 / 8));
        return original(holder->a1, holder->send, holder->a2, holder->a3, holder->a4, holder->a5, holder->a6, holder->a7, holder->a8, holder->a9, holder->a10);
    }

    return original(a1, send, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

void RakPeerHooks::init(uintptr_t addr)
{
    static bool once = false;
    if (once) return;
    once = true;

    GetLastPingDetour = std::make_unique<Detour>("RakNet::RakPeer::GetLastPing", reinterpret_cast<void*>(addr), &getLastPing);
    GetLastPingDetour->enable();
}

void RakPeerHooks::init()
{
    RunUpdateCycleDetour = std::make_unique<Detour>("RakNet::RakPeer::RunUpdateCycle", reinterpret_cast<void*>(SigManager::RakNet_RakPeer_runUpdateCycle), &runUpdateCycle);
    SendImmediateDetour = std::make_unique<Detour>("RakNet::RakPeer::SendImmediate", reinterpret_cast<void*>(SigManager::RakNet_RakPeer_sendImmediate), &sendImmediate);
}

void RakPeerHooks::shutdown()
{
    RunUpdateCycleDetour->restore();
    GetLastPingDetour->restore();
    SendImmediateDetour->restore();
}